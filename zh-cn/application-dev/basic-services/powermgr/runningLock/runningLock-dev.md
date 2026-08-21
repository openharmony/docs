# 阻止系统闲时进入睡眠开发指南

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @fang-jinxu-->

## 场景介绍

当计算机在一段时间内没有检测到用户活动（如键盘或鼠标输入）时，系统会自动尝试进入睡眠，使用RunningLockType.BACKGROUND_USER_IDLE运行锁，保证在持锁过程中系统不会进入自动睡眠，保证业务正常运行。

## 环境准备

### 环境要求

- 开发工具及配置：

  [DevEco Studio](https://developer.huawei.com/consumer/cn/download/)是OpenHarmony应用开发的推荐IDE工具。开发者可以使用该工具进行开发、调试、打包等操作。请下载安装该工具，并参考[DevEco Studio使用指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-tools-overview)中的[创建工程及运行](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-create-new-project)进行基本的操作验证，保证在DevEco Studio可正常运行。


- SDK版本配置：

  RunningLockType.BACKGROUND_USER_IDLE类型的运行锁，所需SDK版本为API version 23及以上才可使用。


- HDC配置：

  HDC（HarmonyOS Device Connector）是为开发人员提供的用于调试的命令行工具，通过该工具可以在Windows/Linux/Mac系统上与真实设备或者模拟器进行交互，详细参考[HDC配置](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/hdc)。

### 搭建环境

- 在PC上安装[DevEco Studio](https://developer.huawei.com/consumer/cn/download/deveco-studio)，要求版本在4.1及以上。
- 将public-SDK更新到API version 23或以上，更新SDK的具体操作可参见[更新指南](../../../faqs/full-sdk-switch-guide.md)。
- PC安装HDC工具，通过该工具可以在Windows/Linux/Mac系统上与真实设备或者模拟器进行交互。
- 用USB线缆将搭载OpenHarmony的设备连接到PC。

## 开发指导

### 接口说明

1. 介绍自动睡眠与强制睡眠:

   系统睡眠（sleep）指的是计算机系统进入一种低功耗状态，其中大部分硬件组件停止工作，只有最小必要的组件保持运行，以维持系统状态。系统睡眠分为两种主要类型：自动睡眠和强制睡眠。

   （1）自动睡眠：由系统预设的条件或用户配置自动触发的睡眠状态。通常，当计算机在一段时间内没有检测到用户活动（如键盘或鼠标输入）时，系统会自动进入睡眠状态。
   > **注意**：
   > 
   > 触发自动睡眠且无睡眠锁一段时间后，系统会进行网络上下行限制。

   （2）强制睡眠：指用户或应用程序直接命令系统立即进入睡眠状态（如用户合上PC盖子，或主动点击菜单里的睡眠等），而不考虑当前系统状态或用户活动。
   > **注意**：
   >
   > 触发强制睡眠后，系统会立刻进行网络上下行限制；同时系统会抢占音频焦点，音视频应用会暂停播放。

2. RunningLockType.BACKGROUND_USER_IDLE接口的使用约束和设备差异：

   （1）PC设备创建该类型的运行锁无系统应用权限管控，系统应用和非系统应用均可创建以及使用；非PC设备创建和使用该类型的运行锁要求是系统应用，非PC设备且非系统应用使用该类型锁**功能不生效**，开发时应考虑此约束。

   （2）BACKGROUND_USER_IDLE用户闲时任务锁可以阻止系统自动睡眠，但不能阻止系统强制睡眠。因此使用该接口的应用必须监听进入强制睡眠的公共事件[common_event_enter_force_sleep](../../../reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_enter_force_sleep12)，在接收到该公共事件后1s内主动释放掉该锁；是否监听退出强制睡眠的公共事件[common_event_exit_force_sleep](../../../reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_exit_force_sleep12)并重新持有锁，由应用根据具体场景自行决策。
   > **注意**：
   > 
   > 触发强制睡眠后，系统会做兜底来强制释放该锁，确保系统能正常进入睡眠。应用需要监听强制睡眠公共事件来处理相应业务，如有必要，在监听到退出强制睡眠后重新申请相应运行锁。


### 开发步骤

使用RunningLockType.BACKGROUND_USER_IDLE运行锁，开发示例如下：

1. 申请使用运行锁所需的权限：`ohos.permission.RUNNING_LOCK`。申请流程请参考：[申请应用权限](../../../security/AccessToken/determine-application-mode.md)。

2. 导入模块。

   ``` TypeScript
   // 导入runningLock、commonEventManager模块
   import { runningLock } from '@kit.BasicServicesKit';
   import { commonEventManager } from '@kit.BasicServicesKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

3. 开发公共事件工具类以及运行锁工具类。

   ``` TypeScript
   // CommonEventHelper.ets
   import { commonEventManager } from '@kit.BasicServicesKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   type SubscriberInfo = commonEventManager.CommonEventSubscribeInfo;
   type Subscriber = commonEventManager.CommonEventSubscriber;
   type EventData = commonEventManager.CommonEventData;
   
   // 公共事件工具类，用来创建公共事件监听者以及订阅、取消订阅公共事件
   export class CommonEventHelper {
     // 创建监听者以及订阅公共事件
     public static async subscribeSystemCommonEvent(info: SubscriberInfo,
       callback: (data: EventData) => void): Promise<Subscriber | undefined> {
       try {
         // 创建监听对象
         const subscriber: Subscriber = await commonEventManager.createSubscriber(info);
         // 订阅指定的公共事件
         commonEventManager.subscribe(subscriber, (err: BusinessError, data: EventData): void => {
           if (err) {
             console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
             return;
           }
           // 监听到公共事件后执行回调
           callback(data);
         });
         // 返回监听者对象
         return subscriber;
       } catch (error) {
         console.error('Failed to subscribe system common event, err: ' + error);
         return undefined;
       }
     }
     
     // 根据传入的监听者取消订阅公共事件
     public static async unsubscribeSystemCommonEvent(subscriber: Subscriber | undefined): Promise<boolean> {
       try {
         // 取消订阅公共事件
         commonEventManager.unsubscribe(subscriber, (error: BusinessError): void => {
           if (error) {
             console.error(`Failed to unsubscribe. Code is ${error.code}, message is ${error.message}`);
           } else {
             console.info('unsubscribe success');
           }
         });
         return true;
       } catch (error) {
         console.error('Failed to unsubscribe event, err: ' + error);
         return false;
       }
     }
   }
   ```
   
   ``` TypeScript
   // RunningLockUtil.ets
   import { runningLock } from '@kit.BasicServicesKit';

   // 运行锁工具类，用来创建运行锁、持锁以及释放锁
   export class RunningLockUtil {
     // 保存运行锁对象
     public static recordLock: runningLock.RunningLock | undefined;

     public static holdRunningLock(): void {
       // 通过isSupport接口查询当前设备是否支持该类型锁
       if (!runningLock.isSupported(runningLock.RunningLockType.BACKGROUND_USER_IDLE)) {
           console.error('type BACKGROUND_USER_IDLE is not support in the device.');
           return;
       }
       if (RunningLockUtil.recordLock) {
         try {
           // 持锁时长取决于具体业务场景，锁超时自动释放；这里示例持锁5000ms
           RunningLockUtil.recordLock.hold(5000);
           console.info('hold running lock success');
         } catch (err) {
           console.error('hold running lock failed, err: ' + err);
         }
       } else {
         // 创建运行锁，并保存运行锁
         RunningLockUtil.createRunningLockAndHold();
       }
     }

     private static async createRunningLockAndHold(): Promise<void> {
       try {
         const lock = await runningLock.create(
           'running_lock_user_idle',
           runningLock.RunningLockType.BACKGROUND_USER_IDLE
         );
         console.info('create running lock: ' + lock);
         RunningLockUtil.recordLock = lock;
         // 持锁时长取决于具体业务场景，锁超时自动释放；示例持锁5000ms
         lock.hold(5000);
         console.info('hold running lock success');
       } catch (err) {
         console.error('create or hold failed, err: ' + err);
       }
     }
   
     public static unholdRunningLock(): void {
       if (!RunningLockUtil.recordLock) {
         console.error('lock is null');
         return;
       }
       try {
         // 判断是否持锁，并进行释放操作
         if (RunningLockUtil.recordLock.isHolding()) {
           RunningLockUtil.recordLock.unhold();
           console.info('unhold running lock success');
         }
       } catch (error) {
         console.error('unhold running lock failed, err: ' + error);
       }
     }
   }
   ```

4. 实现业务需要完成的后台系统闲时任务。
   ``` TypeScript
   // UserIdleTask.ets
   import { CommonEventHelper } from './CommonEventHelper';
   import { RunningLockUtil } from './RunningLockUtil';
   import { commonEventManager } from '@kit.BasicServicesKit';
   
   // 闲时任务类，可参考下方步骤开发
   class UserIdleTask {
     private static subscriber: Nullable<commonEventManager.CommonEventSubscriber> = undefined;
     
     // 1、初始化监听公共事件以及其他业务流程，示例只完成监听
     public async init(): Promise<void> {
       if (UserIdleTask.subscriber === undefined) {
         // 监听进入强制睡眠和退出强制睡眠公共事件，并保存监听者对象
         UserIdleTask.subscriber = await CommonEventHelper.subscribeSystemCommonEvent(
           {
             events: [
               commonEventManager.Support.COMMON_EVENT_ENTER_FORCE_SLEEP,
               commonEventManager.Support.COMMON_EVENT_EXIT_FORCE_SLEEP,
             ],
           },
           this.onReceiveEvent
         );
       }
     }
     
     // 2、持锁后执行任务，任务执行完成后释放锁
     public runUserIdleTask(): void {
       RunningLockUtil.holdRunningLock();
       // 开发者需要自行实现执行系统闲时任务的具体业务逻辑，这里是空实现
       console.info('background user idle task run');
       RunningLockUtil.unholdRunningLock();
     }
     
     // 3、实现收到进入强制睡眠或退出强制睡眠事件的回调函数
     private onReceiveEvent(data: commonEventManager.CommonEventData): void {
       if (data?.event === commonEventManager.Support.COMMON_EVENT_ENTER_FORCE_SLEEP) {
         // 收到进入强制睡眠公共事件后需要在1s内暂停或结束任务（如有），然后释放锁
         RunningLockUtil.unholdRunningLock();
       }
       if (data?.event === commonEventManager.Support.COMMON_EVENT_EXIT_FORCE_SLEEP) {
         // 收到退出强制睡眠公共事件后由业务自行决策是否需要继续执行未完成的任务（如有），示例不做处理
       }
     }
   }
   
   // 创建并执行任务
   function main() {
     let task: UserIdleTask = new UserIdleTask();
     task.init();
     task.runUserIdleTask();
   }
   ```
