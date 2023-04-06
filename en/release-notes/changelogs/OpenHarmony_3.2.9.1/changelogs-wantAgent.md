# ChangeLog of JS API Changes in the WantAgent

This document describes the WantAgent API changes in OpenHarmony 3.2.9.1 SP8 when compared with OpenHarmony 3.2.8.1.

## cl.url.1 Trigger API Changes
trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>): void ;

This API has been deleted, because some functions have not been implemented. Your application can call the following API:

 trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback<CompleteData>): void 

**Change Impacts**

Released JS APIs are affected. The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

| OpenHarmony 3.2.8.1 API                                 | OpenHarmony 3.2.9.1 SP8 API                             |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>): void ; | trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback<CompleteData>): void |

**Adaptation Guide**

The following illustrates how to call the alternative **trigger** API in your application.

Example:

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
// WantAgent object
var wantAgent;
// triggerInfo
var triggerInfo = {
        code: 0
    }
// WantAgentInfo object
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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed' + JSON.stringify(wantAgent));
    }
    // getUid callback
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
