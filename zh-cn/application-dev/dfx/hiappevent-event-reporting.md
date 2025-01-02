# 事件上报

HiAppEvent提供接口用于处理中上报事件。

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[应用事件打点API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

**数据处理者接口功能介绍：**

| 接口名                                    | 描述                                             |
| ----------------------------------------- | ------------------------------------------------ |
| addProcessor(processor: Processor): number | 添加数据处理者，以通过预置的处理者进行事件上报。 |
| removeProcessor(id: number): void          | 移除数据处理者，以移除预置的处理者。             |

**用户ID接口功能介绍：**

| 接口名                                     | 描述                                         |
| ------------------------------------------ | -------------------------------------------- |
| setUserId(name: string, value: string): void | 设置用户ID，数据处理者上报事件时可携带用户ID。 |
| getUserId(name: string): string               | 获取已设置的用户ID。                           |

**用户属性接口功能介绍：**

| 接口名                                           | 描述                                             |
| ------------------------------------------------ | ------------------------------------------------ |
| setUserProperty(name: string, value: string): void | 设置用户属性，数据处理者上报事件时可携带用户属性。 |
| getUserProperty(name: string): string               | 获取已设置的用户属性。                            |

## 开发步骤

以实现对用户点击按钮行为的事件打点并由处理者进行事件上报为例，说明开发步骤。

1. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，添加一个按钮并在其onClick函数中添加数据处理者。analytics_demo为预置在设备里面的数据处理者lib库<!--Del-->，具体实现可以参考[《HiAppEvent数据处理者lib库概述》](../../device-dev/subsystems/subsys-dfx-hiappevent-extend-so.md)<!--DelEnd-->。完整示例代码如下：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   
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
       // 在按钮点击函数中设置用户属性值
       hiAppEvent.setUserProperty('testUserPropertyName', '123456');

       // 在按钮点击函数中获取刚设置的用户属性值
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