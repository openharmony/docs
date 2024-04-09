# @ohos.app.ability.wantAgent (WantAgent) (System API)

The **app.ability.WantAgent** module provides APIs for creating and comparing **WantAgent** objects, and obtaining the user ID, Want, and bundle name of a **WantAgent** object. You are advised to use this module, since it will replace the [@ohos.wantAgent](js-apis-wantAgent.md) module in the near future.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.ability.wantAgent (WantAgent)](js-apis-app-ability-wantAgent.md).

## Modules to Import

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
```

## WantAgent.getWant

getWant(agent: WantAgent, callback: AsyncCallback\<Want\>): void

Obtains the Want in a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                           |
| -------- | --------------------- | ---- | ------------------------------- |
| agent    | WantAgent             | Yes  | Target **WantAgent** object.                  |
| callback | AsyncCallback\<[Want](js-apis-app-ability-want.md)\> | Yes  | Callback used to return the Want.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

// WantAgent object
let wantAgent: _WantAgent;
// WantAgentInfo object
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

// getWantAgent callback
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err) {
        console.info(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
    } else {
        wantAgent = data;
    }
    // getWant callback
    let getWantCallback = (err: BusinessError, data: Want) => {
        if(err) {
            console.error(`getWant failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getWant ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.getWant(wantAgent, getWantCallback);
    } catch(err) {
        console.error(`getWant failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.getWant

getWant(agent: WantAgent): Promise\<Want\>

Obtains the Want in a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name | Type     | Mandatory| Description         |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[Want](js-apis-app-ability-want.md)\> | Promise used to return the Want.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

// WantAgent object
let wantAgent: _WantAgent;
// WantAgentInfo object
let wantAgentInfo: WantAgent.WantAgentInfo = {
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: 'action1',
            entities: ['entity1'],
            type: 'MIMETYPE',
            uri: 'key={true,true,false}',
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [false, true, false],
                mykey5: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey6: true,
            }
        } as Want
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

// getWantAgent callback
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
    if (err) {
        console.info(`getWantAgent failed, code: ${JSON.stringify(err.code)}, message: ${JSON.stringify(err.message)}`);
    } else {
        wantAgent = data;
    }
    try {
        WantAgent.getUid(wantAgent).then((data)=>{
            console.info(`getUid ok! ${JSON.stringify(data)}`);
        }).catch((err: BusinessError)=>{
            console.error(`getUid failed! ${err.code} ${err.message}`);
        });
    } catch(err){
        console.error(`getUid failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}}`);
}
```
