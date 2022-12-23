# WantAgent开发指导
## 场景简介
WantAgent封装了一个行为意图信息，可以通过WantAgent.trigger接口主动触发，也可以通过与通知绑定被动触发。

具体的行为包括：启动Ability和发布公共事件。

## 接口说明
| 接口名                                                                                          | 接口描述 |
| ---------------------------------------------------------------------------------------------- | ----------- |
| getWantAgentInfo(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>) | 以异步回调形式创建WantAgent对象。 |
| getWantAgent(info: WantAgentInfo): Promise\<WantAgent\> | 以Promise形式创建WantAgent对象。 |
| trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData\>) | 触发WantAgent。 |

## 开发步骤
1. 导入WantAgent模块。

   ```ts
   import wantAgent from '@ohos.wantAgent';
   ```
   
2. 创建拉起Ability的WantAgentInfo信息。详细的WantAgentInfo信息数据类型及包含的参数请见[WantAgentInfo文档](../reference/apis/js-apis-wantAgent.md#wantagentinfo)介绍。

   ```ts
   private wantAgentObj = null	// 用于保存创建成功的wantAgent对象，后续使用其完成触发的动作。
   
   // wantAgentInfo
   var wantAgentInfo = {
       wants: [
           {
               deviceId: "",
               bundleName: "com.example.test",
               abilityName: "com.example.test.MainAbility",
               action: "",
               entities: [],
               uri: "",
               parameters: {}
           }
       ],
       operationType: wantAgent.OperationType.START_ABILITY,
       requestCode: 0,
       wantAgentFlags:[wantAgent.WantAgentFlags.CONSTANT_FLAG]
   }
   ```

3. 创建发布公共事件的WantAgentInfo信息。

   ```ts
   private wantAgentObj = null	// 用于保存创建成功的WantAgent对象，后续使用其完成触发的动作。
   
   // wantAgentInfo
   var wantAgentInfo = {
       wants: [
           {
               action: "event_name", // 设置事件名。
               parameters: {}
           }
       ],
       operationType: wantAgent.OperationType.SEND_COMMON_EVENT,
       requestCode: 0,
       wantAgentFlags:[wantAgent.WantAgentFlags.CONSTANT_FLAG]
   }
   ```

4. 创建WantAgent，保存返回的WantAgent对象wantAgentObj，用于执行后续触发操作。

   ```ts
   // 创建WantAgent
   wantAgent.getWantAgent(wantAgentInfo, (err, wantAgentObj) => {
       if (err.code) {
           console.error("[WantAgent]getWantAgent err=" + JSON.stringify(err))
       } else {
           console.log("[WantAgent]getWantAgent success")
           this.wantAgentObj = wantAgentObj
       }
   })
   ```

5. 触发WantAgent。

   ```ts
   // 触发WantAgent。
   var triggerInfo = {
       code:0
   }
   wantAgent.trigger(wantAgentObj, triggerInfo, (completeData) => {
       console.log("[WantAgent]getWantAgent success, completeData: ",  + JSON.stringify(completeData))
   })
   ```
