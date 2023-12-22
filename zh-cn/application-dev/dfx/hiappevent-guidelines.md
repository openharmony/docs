# 应用事件打点开发指导

## 简介

传统的日志系统里汇聚了整个设备上所有程序运行的过程流水日志，难以识别其中的关键信息。因此，应用开发者需要一种数据打点机制，用来评估如访问数、日活、用户操作习惯以及影响用户使用的关键因素等关键信息。

HiAppEvent是在系统层面为应用开发者提供的一种事件打点机制，用于帮助应用记录在运行过程中发生的故障信息、统计信息、安全信息、用户行为信息，以支撑开发者分析应用的运行情况。

## 基本概念

- **打点**

  记录由用户操作引起的变化，提供业务数据信息，以供开发、产品、运维分析。

## 事件设计规范

- 事件领域：用于标识事件的领域，建议设置为业务模块名称，以便于区分不同的业务模块。
- 事件名称：用于指定事件的名称，建议设置为具体的业务名称，以便于描述实际的业务意义。
- 事件类型：用于指定事件的类型，支持以下四种类型事件：
  - 行为事件：用于记录用户日常操作行为的事件，例如按钮点击、界面跳转等行为。
  - 故障事件：用于定位和分析应用故障的事件，例如界面卡顿、掉网掉话等异常。
  - 统计事件：用于统计和度量应用关键行为的事件，例如对使用时长、访问数等的统计。
  - 安全事件：用于记录涉及应用安全行为的事件，例如密码修改、用户授权等行为。
- 事件参数：用于指定事件的参数，每个事件可以包含一组参数，建议设置为事件属性或事件发生上下文信息，以便于描述事件的详细信息。

## 接口说明

应用事件打点接口由hiAppEvent模块提供，API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[应用事件打点API文档](../reference/apis/js-apis-hiviewdfx-hiappevent.md)。

**打点接口功能介绍：**

| 接口名                                                       | 描述                                                 |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| write(info: AppEventInfo, callback: AsyncCallback\<void>): void | 应用事件异步打点方法，使用callback方式作为异步回调。 |
| write(info: AppEventInfo): Promise\<void>                    | 应用事件异步打点方法，使用Promise方式作为异步回调。  |

**订阅接口功能介绍：**

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void               | 移除应用事件观察者，以移除对应用事件的订阅。 |

**数据处理者接口功能介绍：**

| 接口名                                    | 描述                                             |
| ----------------------------------------- | ------------------------------------------------ |
| addProcessor(processor: Processor): number | 添加数据处理者，以通过预置的处理者进行事件上报。 |
| removeProcessor(id: number): void          | 移除数据处理者，以移除预置的处理者。             |

**用户ID接口功能介绍：**

| 接口名                                     | 描述                                         |
| ------------------------------------------ | -------------------------------------------- |
| setUserId(name: string, value: string): void | 设置用户ID，数据处理者上报事件时可携带用户ID。 |
| getUserId(name: string): void               | 获取已设置的用户ID。                           |

**用户属性接口功能介绍：**

| 接口名                                           | 描述                                             |
| ------------------------------------------------ | ------------------------------------------------ |
| setUserProperty(name: string, value: string): void | 设置用户属性，数据处理者上报事件时可携带用户属性。 |
| getUserProperty(name: string): void               | 获取已设置的用户属性。                            |

## 事件订阅开发步骤

### 订阅应用事件

以实现对用户点击按钮行为的事件打点及订阅为例，说明开发步骤。

1. 新建一个ArkTS应用工程，编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ts” 文件，在onCreate函数中添加对用户点击按钮事件的订阅，完整示例代码如下：

   ```ts
   import AbilityConstant from '@ohos.app.ability.AbilityConstant';
   import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent';
   import hilog from '@ohos.hilog';
   import UIAbility from '@ohos.app.ability.UIAbility';
   import Want from '@ohos.app.ability.Want';
   import window from '@ohos.window';
   
   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
   
       hiAppEvent.addWatcher({
         // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
         name: "watcher1",
         // 开发者可以订阅感兴趣的应用事件，此处是订阅了按钮事件
         appEventFilters: [{ domain: "button" }],
         // 开发者可以设置订阅回调触发的条件，此处是设置为事件打点数量满足1个
         triggerCondition: { row: 1 },
         // 开发者可以自行实现订阅回调函数，以便对订阅获取到的事件打点数据进行自定义处理
         onTrigger: (curRow: number, curSize: number, holder: hiAppEvent.AppEventPackageHolder) => {
           // 返回的holder对象为null，表示订阅过程发生异常，因此在记录错误日志后直接返回
           if (holder == null) {
             hilog.error(0x0000, 'testTag', "HiAppEvent holder is null");
             return;
           }
           hilog.info(0x0000, 'testTag', `HiAppEvent onTrigger: curRow=%{public}d, curSize=%{public}d`, curRow, curSize);
           let eventPkg: hiAppEvent.AppEventPackage | null = null;
           // 根据设置阈值大小（默认为512KB）去获取订阅事件包，直到将订阅数据全部取出
           // 返回的事件包对象为null，表示当前订阅数据已被全部取出，此次订阅回调触发结束
           while ((eventPkg = holder.takeNext()) != null) {
             // 开发者可以对事件包中的事件打点数据进行自定义处理，此处是将事件打点数据打印在日志中
             hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.packageId=%{public}d`, eventPkg.packageId);
             hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.row=%{public}d`, eventPkg.row);
             hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.size=%{public}d`, eventPkg.size);
             for (const eventInfo of eventPkg.data) {
               hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.info=%{public}s`, eventInfo);
             }
           }
         }
       });
     }
   }

2. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，添加一个按钮并在其onClick函数中进行事件打点，以记录按钮点击事件，完整示例代码如下：

   ```ts
     Button("writeTest").onClick(()=>{
       // 在按钮点击函数中进行事件打点，以记录按钮点击事件
       let eventParams: Record<string, number> = { 'click_time': 100 };
       let eventInfo: hiAppEvent.AppEventInfo = {
         // 事件领域定义
         domain: "button",
         // 事件名称定义
         name: "click",
         // 事件类型定义
         eventType: hiAppEvent.EventType.BEHAVIOR,
         // 事件参数定义
         params: eventParams,
       };
       hiAppEvent.write(eventInfo).then(() => {
         hilog.info(0x0000, 'testTag', `HiAppEvent success to write event`)
       }).catch((err: BusinessError) => {
         hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`)
       });
     })
   ```

3. 点击IDE界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“writeTest”，触发一次按钮点击事件打点。

4. 可以在Log窗口看到按钮点击事件打点成功的日志，以及触发订阅回调后对打点事件数据的处理日志：

   ```text
   HiAppEvent success to write event
   HiAppEvent eventPkg.packageId=0
   HiAppEvent eventPkg.row=1
   HiAppEvent eventPkg.size=124
   HiAppEvent eventPkg.info={"domain\_":"button","name\_":"click","type\_":4,"time\_":1670268234523,"tz\_":"+0800","pid\_":3295,"tid\_":3309,"click_time":100}
   ```

### 订阅系统事件（崩溃事件）

崩溃事件信息中params属性的详细描述如下：

**params属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| time     | number | 事件触发时间，单位为毫秒。 |
| crash_type | string | 崩溃类型。支持JsError和NativeCrash两种崩溃类型。 |
| foreground | boolean | 应用是否处于前台状态。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| pid | number | 应用的进程id。|
| uid | number | 应用的用户id。 |
| uuid | string | 用户标识id。 |
| exception | object | 异常信息，详见exception属性。NativeCrash类型的崩溃事件详见exception属性（NativeCrash类型）。 |
| hilog | string[] | 日志信息。|
| threads | object[] | 全量线程调用栈，详见thread属性。仅NativeCrash类型的崩溃事件提供。 |

**exception属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| name | string | 异常类型。 |
| message | string | 异常原因。 |
| stack | string | 异常调用栈。 |

**exception属性（NativeCrash类型）：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| message | string | 异常原因。 |
| signal | object | 信号信息，详见signal属性。 |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见frame属性。 |

**signal属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| signo | number | 信号值。 |
| code | number | 信号错误码。 |

**thread属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见frame属性。 |

**frame属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| symbol | string | 函数名称。 |
| file | string | 文件名。 |
| buildId | string | 文件唯一标识。 |
| pc | string | pc寄存器地址。 |
| offset | number | 函数偏移量。 |

以实现对用户点击按钮触发崩溃场景生成的崩溃事件订阅为例，说明开发步骤。

1. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ts”文件，在onCreate函数中添加系统事件的订阅，完整示例代码如下：

   ```ts
    hiAppEvent.addWatcher({
      // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
      name: "watcher2",
      // 开发者可以订阅感兴趣的系统事件，此处是订阅了崩溃事件
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_CRASH]
        }
      ],
      // 开发者可以自行实现订阅实时回调函数，以便对订阅获取到的事件数据进行自定义处理
      onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
        hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
        for (const eventGroup of appEventGroups) {
          // 开发者可以根据事件集合中的事件名称区分不同的系统事件
          hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
          for (const eventInfo of eventGroup.appEventInfos) {
            // 开发者可以对事件集合中的事件数据进行自定义处理，此处是将事件数据打印在日志中
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
            // 开发者可以获取到崩溃事件发生的时间戳
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params.time}`);
            // 开发者可以获取到崩溃事件发生的崩溃类型
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.crash_type=${eventInfo.params.crash_type}`);
            // 开发者可以获取到崩溃应用的前后台状态
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params.foreground}`);
            // 开发者可以获取到崩溃应用的版本信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params.bundle_version}`);
            // 开发者可以获取到崩溃应用的包名
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params.bundle_name}`);
            // 开发者可以获取到崩溃应用的进程id
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params.pid}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params.uid}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uuid=${eventInfo.params.uuid}`);
            // 开发者可以获取到崩溃事件发生的异常类型、异常原因和异常调用栈
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${JSON.stringify(eventInfo.params.exception)}`);
            // 开发者可以获取到崩溃事件发生时日志信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params.hilog.length}`);
          }
        }
      }
    });
   ```

2. 编辑工程中的“entry > src > main > ets  > pages > Index.ets”文件，添加按钮并在其onClick函数构造崩溃场景，以触发崩溃事件，完整示例代码如下：

   ```ts
    Button("appCrash").onClick(()=>{
      // 在按钮点击函数中构造一个crash场景，触发应用崩溃事件
      let obj = {
        'name': 'crash',
      }
      obj = null
      hilog.info(0x0000, 'testTag', `HiAppEvent obj.name: ${obj.name}`)
    })
   ```

3. 点击IDE界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“appCrash”，触发一次崩溃事件。

4. 应用工程崩溃退出后再次运行可以在Log窗口看到对系统事件数据的处理日志：

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=APP_CRASH
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_CRASH
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1701836127566
   HiAppEvent eventInfo.params.crash_type=JsError
   HiAppEvent eventInfo.params.foreground=true
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=2027
   HiAppEvent eventInfo.params.uid=20010043
   HiAppEvent eventInfo.params.uuid=...
   HiAppEvent eventInfo.params.exception={"message":"Cannot read property name of null","name":"TypeError","stack":"at anonymous (entry/src/main/ets/pages/Index.ets:47:44)"}
   HiAppEvent eventInfo.params.hilog.size=100
   ```

### 订阅系统事件（卡死事件）

卡死事件信息中params属性的详细描述如下：

**params属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| time     | number | 事件触发时间，单位为毫秒。 |
| freeze_type | string | 卡死类型。当前支持AppFreeze一种卡死类型。 |
| foreground | boolean | 应用是否处于前台状态。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| process_name | string | 应用的进程名称。 |
| pid | number | 应用的进程id。|
| uid | number | 应用的用户id。 |
| uuid | string | 用户标识id。 |
| exception | object | 异常信息，详见exception属性。 |
| hilog | string[] | 日志信息。|
| event_handler | string[] | 主线程未处理消息。 |
| event_handler_size_3s | string | THREAD_BLOCK事件3s时任务栈中任务数。 |
| event_handler_size_6s | string | THREAD_BLOCK事件6s时任务栈中任务数。 |
| peer_binder | string[] | binder调用信息。 |
| threads | object[] | 全量线程调用栈，详见thread属性。 |
| memory | object | 内存信息，详见memory属性。 |

**exception属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| name | string | 异常类型。 |
| message | string | 异常原因。 |

**thread属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见frame属性。 |

**frame属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| symbol | string | 函数名称。 |
| file | string | 文件名。 |
| buildId | string | 文件唯一标识。 |
| pc | string | pc寄存器地址。 |
| offset | number | 函数偏移量。 |

**memory属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| rss | number | 进程实际占用内存大小，单位KB。 |
| vss | number | 进程向系统申请的虚拟内存大小，单位KB。 |
| pss | number | 进程实际使用的物理内存大小，单位KB。 |
| sys_free_mem | number | 空闲内存大小，单位KB。 |
| sys_avail_mem | number | 可用内存大小，单位KB。 |
| sys_total_mem | number | 总内存大小，单位KB。 |

以实现对用户点击按钮触发卡死场景生成的卡死事件订阅为例，说明开发步骤。

1. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ts”文件，在onCreate函数中添加系统事件的订阅，完整示例代码如下：

   ```ts
    hiAppEvent.addWatcher({
      // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
      name: "watcher3",
      // 开发者可以订阅感兴趣的系统事件，此处是订阅了卡死事件
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_FREEZE]
        }
      ],
      // 开发者可以自行实现订阅实时回调函数，以便对订阅获取到的事件数据进行自定义处理
      onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
        hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
        for (const eventGroup of appEventGroups) {
          // 开发者可以根据事件集合中的事件名称区分不同的系统事件
          hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
          for (const eventInfo of eventGroup.appEventInfos) {
            // 开发者可以对事件集合中的事件数据进行自定义处理，此处是将事件数据打印在日志中
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
            // 开发者可以获取到卡死事件发生的时间戳
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params.time}`);
            // 开发者可以获取到卡死事件发生的卡死类型
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.freeze_type=${eventInfo.params.freeze_type}`);
            // 开发者可以获取到卡死应用的前后台状态
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params.foreground}`);
            // 开发者可以获取到卡死应用的版本信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params.bundle_version}`);
            // 开发者可以获取到卡死应用的包名
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params.bundle_name}`);
            // 开发者可以获取到卡死应用的进程名称
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_name=${eventInfo.params.process_name}`);
            // 开发者可以获取到卡死应用的进程id
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params.pid}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params.uid}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uuid=${eventInfo.params.uuid}`);
            // 开发者可以获取到卡死事件发生的异常类型、异常原因
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${JSON.stringify(eventInfo.params.exception)}`);
            // 开发者可以获取到卡死事件发生时日志信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params.hilog.length}`);
            // 开发者可以获取到卡死事件发生时主线程未处理消息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler.size=${eventInfo.params.event_handler.length}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_3s=${eventInfo.params.event_handler_size_3s}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_6s=${eventInfo.params.event_handler_size_6s}`);
            // 开发者可以获取到卡死事件发生时同步binder调用信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.peer_binder.size=${eventInfo.params.peer_binder.length}`);
            // 开发者可以获取到卡死事件发生时全量线程调用栈
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.threads.size=${eventInfo.params.threads.length}`);
            // 开发者可以获取到卡死事件发生时内存信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo.params.memory)}`);
          }
        }
      }
    });
   ```

2. 编辑工程中的“entry > src > main > ets  > pages > Index.ets”文件，添加按钮并在其onClick函数构造卡死场景，以触发卡死事件，完整示例代码如下：

   ```ts
    Button("appFreeze").onClick(()=>{
      // 在按钮点击函数中构造一个freeze场景，触发应用卡死事件
      setTimeout(() => {
        while (true) {}
      }, 1000)
    })
   ```

3. 点击IDE界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“appFreeze”，触发一次卡死事件。

4. 应用工程卡死恢复运行后可以在Log窗口看到对系统事件数据的处理日志：

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=APP_FREEZE
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_FREEZE
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1702553728887
   HiAppEvent eventInfo.params.freeze_type=AppFreeze
   HiAppEvent eventInfo.params.foreground=true
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.params.process_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=2978
   HiAppEvent eventInfo.params.uid=20010043
   HiAppEvent eventInfo.params.uuid=...
   HiAppEvent eventInfo.params.exception={"message":"App main thread is not response!","name":"THREAD_BLOCK_6S"}
   HiAppEvent eventInfo.params.hilog.size=7
   HiAppEvent eventInfo.params.event_handler.size=3
   HiAppEvent eventInfo.params.event_handler_size_3s=2
   HiAppEvent eventInfo.params.event_handler_size_6s=3
   HiAppEvent eventInfo.params.peer_binder.size=0
   HiAppEvent eventInfo.params.threads.size=22
   HiAppEvent eventInfo.params.memory={"pss":0,"rss":0,"sys_avail_mem":947700,"sys_free_mem":441064,"sys_total_mem":1992724,"vss":0}
   ```

## 事件上报开发步骤

以实现对用户点击按钮行为的事件打点并由处理者进行事件上报为例，说明开发步骤。

1. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，添加一个按钮并在其onClick函数中添加数据处理者。analytics_demo为预置在设备里面的数据处理者lib库，具体实现可以参考[《HiAppEvent数据处理者lib库概述》](../../device-dev/subsystems/subsys-dfx-hiappevent-extend-so.md)。完整示例代码如下：

   ```ts
   import { BusinessError } from '@ohos.base'
   import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent'
   import hilog from '@ohos.hilog'
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'

     processorId: number = -1
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
   
           Button("addProcessorTest").onClick(()=>{
             // 在按钮点击函数中进行数据处理者添加
             let eventConfig: hiAppEvent.AppEventReportConfig = {
               domain: 'button',
               name: 'click',
               isRealTime: true
             };
             let processor: hiAppEvent.Processor = {
               name: 'analytics_demo',
               debugMode: true,
               routeInfo: 'CN',
               onStartReport: true,
               onBackgroundReport: true,
               periodReport: 10,
               batchReport: 5,
               userIds: ['testUserIdName'],
               userProperties: ['testUserPropertyName'],
               eventConfigs: [eventConfig]
             };
             this.processorId = hiAppEvent.addProcessor(processor);
           })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

2. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，添加一个按钮并在其onClick函数中添加并查看用户ID，完整示例代码如下：

   ```ts
     Button("userIdTest").onClick(()=>{
       // 在按钮点击函数中设置用户ID
       hiAppEvent.setUserId('testUserIdName', '123456');

       // 在按钮点击函数中获取刚设置的用户ID
       let userId = hiAppEvent.getUserId('testUserIdName');
       hilog.info(0x0000, 'testTag', `userId: ${userId}`)
     })
   ```

3. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，添加一个按钮并在其onClick函数中添加并查看用户属性，完整示例代码如下：

   ```ts
     Button("userPropertyTest").onClick(()=>{
       // 在按钮点击函数中设置用户ID
       hiAppEvent.setUserProperty('testUserPropertyName', '123456');

       // 在按钮点击函数中获取刚设置的用户ID
       let userProperty = hiAppEvent.getUserProperty('testUserPropertyName');
       hilog.info(0x0000, 'testTag', `userProperty: ${userProperty}`)
     })
   ```

4. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，添加一个按钮并在其onClick函数中进行事件打点，以记录按钮点击事件，完整示例代码如下：

   ```ts
     Button("writeTest").onClick(()=>{
       // 在按钮点击函数中进行事件打点，以记录按钮点击事件
       let eventParams: Record<string, number> = { 'click_time': 100 };
       let eventInfo: hiAppEvent.AppEventInfo = {
         // 事件领域定义
         domain: "button",
         // 事件名称定义
         name: "click",
         // 事件类型定义
         eventType: hiAppEvent.EventType.BEHAVIOR,
         // 事件参数定义
         params: eventParams,
       };
       hiAppEvent.write(eventInfo).then(() => {
         hilog.info(0x0000, 'testTag', `HiAppEvent success to write event`)
       }).catch((err: BusinessError) => {
         hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`)
       });
     })
   ```

5. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，添加一个按钮并在其onClick函数中进行数据处理者移除(第二步已完成数据处理者添加)，完整示例代码如下：

   ```ts
     Button("removeProcessorTest").onClick(()=>{
       // 在按钮点击函数中进行数据处理者移除
       hiAppEvent.removeProcessor(this.processorId);
     })
   ```

6. 点击IDE界面中的运行按钮，运行应用工程，然后在应用界面中依次点击按钮“addProcessorTest”、“userIdTest”、“userPropertyTest”、“writeTest”、“removeProcessorTest”，则成功通过数据处理者进行一次事件上报。

   最终，事件处理者成功接收到事件数据，并在Log窗口看到按钮点击事件打点成功的日志：

   ```text
   HiAppEvent success to write event
   ```

## 相关实例

针对应用事件开发，有以下相关实例可供参考：

- [测试打点（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/DotTest)

- [日志打印（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/Logger)