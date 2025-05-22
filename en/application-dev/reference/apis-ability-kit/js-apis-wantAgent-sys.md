# @ohos.wantAgent (WantAgent) (System API)
<!--deprecated_code_no_check-->

The **WantAgent** module provides APIs for creating and comparing **WantAgent** objects, and obtaining the user ID and bundle name of a **WantAgent** object.

> **NOTE**
> 
> The APIs of this module are supported since API version 7 and deprecated since API version 9. You are advised to use [@ohos.app.ability.wantAgent](js-apis-app-ability-wantAgent.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.wantAgent (WantAgent)](js-apis-wantAgent.md).

## Modules to Import

```ts
import WantAgent from '@ohos.wantAgent';
```

## WantAgent.getWant

getWant(agent: WantAgent, callback: AsyncCallback\<Want\>): void

Obtains the Want in a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                      | Mandatory| Description                   |
| -------- | -------------------------- | ---- | ----------------------- |
| agent     | [WantAgent](js-apis-wantAgent-sys.md)              | Yes  | **WantAgent** object.          |
| callback | AsyncCallback\<Want\> | Yes  | Callback used to return the Want.|

**Example**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

// WantAgent object
let wantAgent: _WantAgent;

// getWantAgent callback
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
	console.info('==========================>getWantAgentCallback=======================>');
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.error('getWantAgent failed, error: ' + JSON.stringify(err));
        return;
    }

    // getWant callback
    let getWantCallback = (err: BusinessError, data: Want) => {
        console.info('==========================>getWantCallback=======================>');
    }
    WantAgent.getWant(wantAgent, getWantCallback);
}

WantAgent.getWantAgent({
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.neu.setResultOnAbilityResultTest1',
            abilityName: 'com.example.test.EntryAbility',
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
        }
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}, getWantAgentCallback);
```

## WantAgent.getWant

getWant(agent: WantAgent): Promise\<Want\>

Obtains the Want in a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type         | Mandatory| Description         |
| ---- | ------------- | ---- | ------------- |
| agent | [WantAgent](js-apis-wantAgent-sys.md) | Yes  | **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Want\> | Promise used to return the Want.|

**Example**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.wantAgent';
import { BusinessError } from '@ohos.base';

// WantAgent object
let wantAgent: _WantAgent;

WantAgent.getWantAgent({
    wants: [
        {
            deviceId: 'deviceId',
            bundleName: 'com.neu.setResultOnAbilityResultTest1',
            abilityName: 'com.example.test.EntryAbility',
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
        }
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}).then((data) => {
	console.info('==========================>getWantAgentCallback=======================>');
    wantAgent = data;
    if (wantAgent) {        
        WantAgent.getWant(wantAgent).then((data) => {
            console.info('==========================>getWantCallback=======================>');
        });
    }
});
```
