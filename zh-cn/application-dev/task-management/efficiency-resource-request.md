# 能效资源申请(ArkTS)（仅对系统特权应用开放）

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @cheng-shichang-->
<!--Designer: @zhouben25-->
<!--Tester: @fenglili18-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

### 功能介绍

部分系统基础应用对外提供或者维持系统基本功能，需要长时间运行，如系统为了维持和服务器的连接，需要有一个默认长连接推送服务的应用每隔一小段时间给服务器发送心跳包，为了避免该应用进程被挂起，可以申请能效资源来保障业务的执行。

### 基本概念

- **能效资源申请接口** ：单独为进程申请CPU等资源的接口，保障系统应用在后台执行的诉求。申请CPU资源后，则应用或进程不被挂起。

- **系统特权应用**：配置[runningResourcesApply特权](../../device-dev/subsystems/subsys-app-privilege-config-guide.md#可由设备厂商配置的特权)应用的系统应用。

### 约束与限制

- 能效资源仅支持系统特权应用使用。

- CPU支持按照进程维度或应用维度申请，其他资源仅支持按照应用维度申请。

## 接口说明

**表1** 申请能效资源主要接口

以下是能效资源开发使用的相关接口，更多接口及使用方式请见[后台任务管理](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager-sys.md)。

| 接口名 | 描述 |
| -------- | -------- |
| applyEfficiencyResources(request: EfficiencyResourcesRequest): void | 申请能效资源 |
| resetAllEfficiencyResources(): void | 释放全部能效资源 |

**表2** 能效资源申请参数
| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| resourceTypes | number | 是 | 申请的资源类型 |
| isApply | boolean | 是 | 申请或释放资源<br/>- true表示申请资源<br/>- false表示释放部分资源 |
| timeOut | number | 是 | 资源使用时间（ms） |
| isPersist | boolean | 否 | 是否为永久持有资源，默认为false<br/>- true表示永久持有<br/>- false表示有限时间内持有 |
| isProcess | boolean | 否 | 进程或应用申请，默认为false<br/>- true表示进程申请<br/>- false表示应用申请 |
| reason | string | 是 | 申请资源原因 |

**表3** 能效资源类型
| 参数名 | 值 | 描述 |
| -------- | -------- | -------- |
| CPU | 1 | CPU资源，申请后应用进程不被挂起 |
| COMMON_EVENT | 2 | 公共事件资源，申请后应用进程被挂起后，可以收到公共事件 |
| TIMER | 4 | 公共事件资源，申请后应用进程被挂起后，Timer仍然可以唤醒应用 |
| WORK_SCHEDULER | 8 | 延迟任务资源，申请后延迟任务管控变宽松 |
| BLUETOOTH | 16 | 蓝牙资源，申请后应用进程被挂起后，蓝牙相关事件仍然可以唤醒应用 |
| GPS | 32 | GPS资源，申请后应用进程被挂起后，GPS相关事件可以唤醒应用 |
| AUDIO | 64 | 音频资源，有音频播放时对应的应用进程不被挂起 |
| RUNNING_LOCK<sup>10+</sup> | 128 | RUNNING_LOCK资源，申请后挂起状态不会临时释放RUNNING_BACKGROUND锁 |
| SENSOR<sup>10+</sup> | 256 | SENSOR资源，申请后挂起状态不拦截Sensor回调 |

## 开发步骤

1. 导入模块。

   ```ts
   import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 申请能效资源。

   ```ts
   // 应用需要在后台保持活动状态，不被挂起。
   let request: backgroundTaskManager.EfficiencyResourcesRequest = {
     resourceTypes: backgroundTaskManager.ResourceType.CPU, // 资源类型是CPU资源，保证应用进程不被挂起
     isApply: true, // 申请资源
     timeOut: 0, // 超时时间，超过超时时间后资源自动释放
     reason: "apply", // 申请原因
     isPersist: true, // 永久持有资源
     isProcess: false, // 在应用级别申请
   };
   try {
     backgroundTaskManager.applyEfficiencyResources(request);
     console.info("Succeeded in invoking applyEfficiencyResources.");
   } catch (error) {
     console.error(`Operation applyEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
   }
   ```

3. 释放能效资源。应用在后台完成工作后，及时释放资源，支持释放部分资源或全部资源。

   ```ts
   // 应用在后台完成了工作后，全部释放能效资源
   try {
     backgroundTaskManager.resetAllEfficiencyResources();
     console.info("Succeeded in invoking resetAllEfficiencyResources.");
   } catch (error) {
     console.error(`Operation resetAllEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
   }
   //应用在后台完成了工作后，部分释放能效资源
   let request: backgroundTaskManager.EfficiencyResourcesRequest = {
     resourceTypes: backgroundTaskManager.ResourceType.CPU,
     isApply: false, // 释放资源
     timeOut: 0,
     reason: "apply",
     isPersist: true,
     isProcess: false, // 在应用级别释放资源
   };
   try {
     backgroundTaskManager.applyEfficiencyResources(request);
     console.info("Succeeded in invoking applyEfficiencyResources.");
   } catch (error) {
     console.error(`Operation applyEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
   }
   ```

   > **说明：**
   > 能效资源申请接口支持动态申请，在任务完成后，建议主动取消能效资源申请，以降低设备耗电速度、保障用户使用流畅度。