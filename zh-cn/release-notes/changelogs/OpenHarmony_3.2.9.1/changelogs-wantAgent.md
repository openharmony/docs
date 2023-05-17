# wantAgent的JS API变更Changelog

OpenHarmony 3.2.9.1 sp8版本相较于OpenHarmony 3.2.8.1版本，wantAgent的API变更如下

## cl.url.1.trigger类接口变更
trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>): void ;

因部分功能未实现，已对其进行删除，应用可调用下面接口进行替代：

 trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback<CompleteData>): void 

 **变更影响**

影响已发布的JS接口，应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**

| OpenHarmony 3.2.8.1版本接口                                  | OpenHarmony 3.2.9.1 sp8版本接口                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>): void ; | trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback<CompleteData>): void |

**适配指导**

应用中调用替代的trigger接口可参考下列代码

示例：

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
//wantAgent对象
var wantAgent;
// triggerInfo
var triggerInfo = {
        code: 0
    }
//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}

//getWantAgent回调
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed' + JSON.stringify(wantAgent));
    }
    //getUid回调
    function triggerCallback(err, data) {
        if(err) {
            console.info('getUid failed!' + err.code + err.message);
        } else {
            console.info('getUid ok!' + JSON.stringify(data));
        }
    }
    try {
        WantAgent.trigger(wantAgent, triggerInfo, triggerCallback);
    } catch(err) {
        console.info('getUid failed!' + err.code + err.message);
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + err.code + err.message);
}
```
