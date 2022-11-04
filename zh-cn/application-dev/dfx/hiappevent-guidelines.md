# 应用事件打点开发指导

## 场景介绍

应用事件打点的主要工作是在应用运行过程中，帮助应用记录在运行过程中发生的各种信息。

## 接口说明

应用事件JS打点接口由hiAppEvent模块提供。

以下仅提供简单的接口介绍，API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[应用事件打点API文档](../reference/apis/js-apis-hiviewdfx-hiappevent.md)。

**打点接口功能介绍：**

| 接口名                                                       | 描述                                                 |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| write(AppEventInfo info, AsyncCallback\<void> callback): void | 应用事件异步打点方法，使用callback方式作为异步回调。 |
| write(AppEventInfo info): Promise\<void>                     | 应用事件异步打点方法，使用Promise方式作为异步回调。  |

**打点配置接口功能介绍：**

| 接口名                               | 描述                                                 |
| ------------------------------------ | ---------------------------------------------------- |
| configure(ConfigOption config): void | 应用事件打点配置方法，可以对打点功能进行自定义配置。 |

**订阅接口功能介绍：**

| 接口名                                             | 描述                 |
| -------------------------------------------------- | -------------------- |
| addWatcher(Watcher watcher): AppEventPackageHolder | 添加应用事件订阅者。 |
| removeWatcher(Watcher watcher): void               | 移除应用事件订阅者。 |

**清理接口功能介绍：**

| 接口名            | 描述                 |
| ----------------- | -------------------- |
| clearData(): void | 清除本地的打点数据。 |

## 开发步骤

以一次应用事件打点订阅流程为例，说明开发步骤。

1. 新建一个ets应用工程，编辑工程中的“entry > src > main > ets  > pages > index.ets” 文件，依次添加三个按钮，以对应用事件打点订阅流程进行模拟。其中，按钮1模拟了应用事件打点的调用，按钮2模拟了添加自动触发回调的事件订阅者的调用，按钮3模拟了移除事件订阅者的调用，完整示例代码如下：

   ```ts
   import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent';
   
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
   
           Button("1 writeTest").onClick(()=>{
             // 根据传入的事件参数执行一次应用事件打点
             hiAppEvent.write({
               domain: "test_domain",
               name: "test_event",
               eventType: hiAppEvent.EventType.FAULT,
               params: {
                 int_data: 100,
                 str_data: "strValue"
               }
             }).then(() => {
               console.log(`HiAppEvent success to write event`);
             }).catch((err) => {
               console.error(`code: ${err.code}, message: ${err.message}`);
             });
           })
   
           Button("2 addWatcherTest").onClick(()=>{
             // 根据传入的订阅参数添加一个应用事件订阅者
             hiAppEvent.addWatcher({
               name: "watcher1",
               appEventFilters: [{ domain: "test_domain" }],
               triggerCondition: {
                 row: 2,
                 size: 1000,
                 timeOut: 2
               },
               onTrigger: function (curRow, curSize, holder) {
                 // 返回的holder对象为null表示订阅过程发生异常，因此在记录错误日志后直接返回
                 if (holder == null) {
                   console.error("HiAppEvent holder is null");
                   return;
                 }
                 // 设置每次获取的订阅事件包大小阈值为1000字节
                 holder.setSize(1000);
                 let eventPkg = null;
                 // 根据设置阈值大小去获取订阅事件包（返回的事件包对象为null，表示当前订阅数据被全部取出）
                 while ((eventPkg = holder.takeNext()) != null) {
                   // 对获取的订阅事件包进行解析，并将解析结果打印在Log界面
                   console.info(`HiAppEvent eventPkg.packageId=${eventPkg.packageId}`);
                   console.info(`HiAppEvent eventPkg.row=${eventPkg.row}`);
                   console.info(`HiAppEvent eventPkg.size=${eventPkg.size}`);
                   // 对订阅事件包中的事件字符串数组进行遍历解析
                   for (const eventInfo of eventPkg.data) {
                     console.info(`HiAppEvent eventPkg.data=${eventInfo}`);
                   }
                 }
               }
             });
           })
   
           Button("3 removeWatcherTest").onClick(()=>{
             // 移除指定名称的应用事件订阅者
             hiAppEvent.removeWatcher({
               name: "watcher1"
             })
           })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

2. 点击IDE界面中的运行按钮，运行应用工程。

3. 在应用界面点击按钮1进行一次事件打点，可以在Log窗口看到打点成功的日志：

   ```
   success to write event: 0
   ```

4. 在应用界面点击按钮2进行添加事件订阅者，再多次点击按钮1进行多次打点。在满足回调任一触发条件（事件数量、事件数据大小、定时时长）后，可以在Log窗口看到回调函数触发后获取到的订阅事件包的日志：

   ```
   HiAppEvent eventPkg.packageId=0
   HiAppEvent eventPkg.row=2
   HiAppEvent eventPkg.size=308
   HiAppEvent eventPkg.data={"domain_":"test_domain","name_":"test_event","type_":1,"time_":1502096107556,"tz_":"+0000","pid_":4204,"tid_":4223,"int_data":100,"str_data":"strValue"}
   ```

5. 在应用界面点击按钮3进行移除事件订阅者，再多次点击按钮1进行多次打点，此时在Log窗口不再能看到订阅触发的日志。

## 相关实例

针对应用事件开发，有以下相关实例可供参考：

- [`JsDotTest`：测试打点（JS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/DFX/JsDotTest)