# WantAgent开发指导
### 简介
wantAgent封装了一个指定行为的意图，可以通过wantAgent.trigger接口主动触发，也可以通过与通知绑定被动触发。

具体的行为包括：启动ability和发布公共事件。

### 场景介绍
通过wantAgent，拉起另外一个ability

### 接口说明
| 接口名                                                                                          | 接口描述 |
| ---------------------------------------------------------------------------------------------- | ----------- |
| wantAgent.getWantAgentInfo(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>) | 创建wantAgent对象(callback) |
| wantAgent.getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>; | 创建wantAgent对象(promise) |
| commonEvent.trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData\>) | 触发wantAgent |

### 开发步骤
1. 导入WantAgent模块。

```javascript
import wantAgent from '@ohos.wantAgent';
```

2. 创建WantAgentInfo信息，详细的WantAgentInfo信息数据类型及包含的参数请见[WantAgentInfo文档](../reference/apis/js-apis-wantAgent.md#WantAgentInfo)介绍。

```javascript
private wantAgentObj = null	//用于保存创建成功的wantAgent对象，后续使用其完成触发的动作

//wantAgentInfo
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
    operationType: OperationType.START_ABILITIE,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.CONSTANT_FLAG]
}
```

3. 创建wantAgent，保存返回的wantAgent对象wantAgentObj，用于执行后续触发操作。

```javascript
//创建wantAgent
wantAgent.getWantAgent(wantAgentInfo, (err, wantAgentObj) => {
    if (err.code) {
        console.error("[WantAgent]getWantAgent err=" + JSON.stringify(err))
    } else {
        console.log("[WantAgent]getWantAgent success")
        this.wantAgentObj = wantAgentObj
    }
})
```

4. 触发wantAgent

```
//触发wantAgent
var triggerInfo = {
    code:0
}
wantAgent.trigger(wantAgentObj, triggerInfo, (err, completeData) => {
    if (err.code) {
        console.error("[WantAgent]trigger err=" + JSON.stringify(err))
    } else {
        console.log("[WantAgent]getWantAgent success, completeData: ",  + JSON.stringify(completeData))
    }
})
```