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
| write(AppEventInfo info, AsyncCallback\<void> callback): void | 应用事件异步打点方法，使用callback方式作为异步回调。 |
| write(AppEventInfo info): Promise\<void>                     | 应用事件异步打点方法，使用Promise方式作为异步回调。  |

**订阅接口功能介绍：**

| 接口名                                             | 描述                                         |
| -------------------------------------------------- | -------------------------------------------- |
| addWatcher(Watcher watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(Watcher watcher): void               | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

以实现对用户点击按钮行为的事件打点及订阅为例，说明开发步骤。

1. 新建一个ets应用工程，编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ts” 文件，在onCreate函数中添加对用户点击按钮事件的订阅，完整示例代码如下：

   ```js
   import hilog from '@ohos.hilog';
   import Ability from '@ohos.application.Ability'
   import Window from '@ohos.window'
   import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent'
   
   export default class EntryAbility extends Ability {
       onCreate(want, launchParam) {
           hilog.isLoggable(0x0000, 'testTag', hilog.LogLevel.INFO);
           hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
           hilog.info(0x0000, 'testTag', '%{public}s', 'want param:' + JSON.stringify(want) ?? '');
           hilog.info(0x0000, 'testTag', '%{public}s', 'launchParam:' + JSON.stringify(launchParam) ?? '');
   
           hiAppEvent.addWatcher({
               // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
               name: "watcher1",
               // 开发者可以订阅感兴趣的应用事件，此处是订阅了按钮事件
               appEventFilters: [{ domain: "button" }],
               // 开发者可以设置订阅回调触发的条件，此处是设置为事件打点数量满足1个
               triggerCondition: { row: 1 },
               // 开发者可以自行实现订阅回调函数，以便对订阅获取到的事件打点数据进行自定义处理
               onTrigger: function (curRow, curSize, holder) {
                   // 返回的holder对象为null，表示订阅过程发生异常，因此在记录错误日志后直接返回
                   if (holder == null) {
                       hilog.error(0x0000, 'testTag', "HiAppEvent holder is null")
                       return
                   }
                   let eventPkg = null
                   // 根据设置阈值大小（默认为512KB）去获取订阅事件包，直到将订阅数据全部取出
                   // 返回的事件包对象为null，表示当前订阅数据已被全部取出，此次订阅回调触发结束
                   while ((eventPkg = holder.takeNext()) != null) {
                       // 开发者可以对事件包中的事件打点数据进行自定义处理，此处是将事件打点数据打印在日志中
                       hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.packageId=%{public}d`, eventPkg.packageId)
                       hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.row=%{public}d`, eventPkg.row)
                       hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.size=%{public}d`, eventPkg.size)
                       for (const eventInfo of eventPkg.data) {
                           hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.info=%{public}s`, eventInfo)
                       }
                   }
               }
           })
       }
   }

2. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，添加一个按钮并在其onClick函数中进行事件打点，以记录按钮点击事件，完整示例代码如下：

   ```js
   import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent'
   import hilog from '@ohos.hilog'
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
   
           Button("writeTest").onClick(()=>{
             // 在按钮点击函数中进行事件打点，以记录按钮点击事件
             hiAppEvent.write({
               // 事件领域定义
               domain: "button",
               // 事件名称定义
               name: "click",
               // 事件类型定义
               eventType: hiAppEvent.EventType.BEHAVIOR,
               // 事件参数定义
               params: { click_time: 100 }
             }).then(() => {
               hilog.info(0x0000, 'testTag', `HiAppEvent success to write event`)
             }).catch((err) => {
               hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`)
             })
           })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
   
3. 点击IDE界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“writeTest”，触发一次按钮点击事件打点。

4. 最终，可以在Log窗口看到按钮点击事件打点成功的日志，以及触发订阅回调后对打点事件数据的处理日志：

   ```js
   HiAppEvent success to write event
   
   HiAppEvent eventPkg.packageId=0
   HiAppEvent eventPkg.row=1
   HiAppEvent eventPkg.size=124
   HiAppEvent eventPkg.info={"domain_":"button","name_":"click","type_":4,"time_":1670268234523,"tz_":"+0800","pid_":3295,"tid_":3309,"click_time":100}
   ```

## 相关实例

针对应用事件开发，有以下相关实例可供参考：

- [`JsDotTest`：测试打点（JS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/DFX/JsDotTest)