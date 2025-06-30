# @ohos.app.ability.wantAgent (WantAgent) (System API)

The app.ability.WantAgent module provides APIs for creating and comparing **WantAgent** objects, and obtaining the user ID, Want, and bundle name of a **WantAgent** object. You are advised to use this module, since it will replace the [@ohos.wantAgent](js-apis-wantAgent.md) module in the near future.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.ability.wantAgent (WantAgent)](js-apis-app-ability-wantAgent.md).

## Modules to Import

```ts
import { WantAgent } from '@kit.AbilityKit';
```

## WantAgent.getWant

getWant(agent: WantAgent, callback: AsyncCallback\<Want\>): void

Obtains the Want in a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                           |
| -------- | --------------------- | ---- | ------------------------------- |
| agent    | WantAgent             | Yes  | Target **WantAgent** object.                  |
| callback | AsyncCallback\<[Want](js-apis-app-ability-want.md)\> | Yes  | Callback used to return the Want.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID   | Error Message           |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

**Example**

```ts
import { wantAgent, WantAgent as _WantAgent, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// WantAgent object
let wantAgentData: _WantAgent;
// WantAgentInfo object
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

// getWantAgent callback
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${err.code}, message: ${err.message}`);
  } else {
    wantAgentData = data;
  }
  // getWant callback
  let getWantCallback = (err: BusinessError, data: Want) => {
    if(err) {
      console.error(`getWant failed, code: ${err.code}, messgae: ${err.message}.`);
    } else {
      console.info(`getWant success, data: ${JSON.stringify(data)}.`);
    }
  }
  try {
    wantAgent.getWant(wantAgentData, getWantCallback);
  } catch(err) {
    let code = (err as BusinessError).code;
    let msg = (err as BusinessError).message;
    console.error(`getWant failed, code: ${code}, message: ${msg}.`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`getWantAgent failed, code: ${code}, message: ${msg}.`);
}
```



## WantAgent.getWant

getWant(agent: WantAgent): Promise\<Want\>

Obtains the Want in a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name | Type     | Mandatory| Description         |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[Want](js-apis-app-ability-want.md)\> | Promise used to return the Want.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID   | Error Message           |
|-----------|--------------------|
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000007   | Service busy. There are concurrent tasks. Try again later. |
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import { wantAgent, WantAgent as _WantAgent, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// WantAgent object
let wantAgentData: _WantAgent;
// WantAgentInfo object
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

// getWantAgent callback
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
  if (err) {
    console.error(`getWantAgent failed, code: ${err.code}, message: ${err.message}`);
  } else {
    wantAgentData = data;
  }
  try {
    wantAgent.getWant(wantAgentData).then((data)=>{
      console.info(`getWant success, data: ${JSON.stringify(data)}`);
    }).catch((err: BusinessError)=>{
      console.error(`getWant failed, code: ${err.code}, messgae: ${err.message}.`);
    });
  } catch(err){
    let code = (err as BusinessError).code;
    let msg = (err as BusinessError).message;
    console.error(`getWant failed, code: ${code}, messgae: ${msg}.`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`getWantAgent failed, code: ${code}, messgae: ${msg}.`);
}
```

## WantAgent.setWantAgentMultithreading<sup>18+</sup>

setWantAgentMultithreading(isMultithreadingSupported: boolean) : void

Enables or disables the WantAgent multithreading feature.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                           |
| ---------- | --------------------- | ---- | ------------------------------- |
| isMultithreadingSupported    | boolean    | Yes  |Whether to enable the multithreading feature. The value **true** means to enable multithreading, and **false** means the opposite.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message           |
|-----------|--------------------|
| 202       | Not system app. Interface caller is not a system app. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { wantAgent, WantAgent as _WantAgent, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Define a wantAgent object.
let wantAgentData: _WantAgent;
// Define a WantAgentInfo object.
let wantAgentInfo: wantAgent.WantAgentInfo = {
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
  actionType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

// Define a getWantAgent callback.
function getWantAgentCallback(err: BusinessError, data: _WantAgent) {
  if (err) {
    console.error(`Failed to call getWantAgentCallback. Code is ${err.code}. Message is ${err.message}.`);
  } else {
    wantAgentData = data;
  }

  try {
    wantAgent.setWantAgentMultithreading(true);
  } catch (err) {
    console.error(`Failed to set wantAgentMultithreading. Code is ${err.code}. Message is ${err.message}.`);
  }
}

try {
  wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch (err) {
  console.error(`Failed to get wantAgent. Code is ${err.code}. Message is ${err.message}.`);
}
```

## OperationType

Enumerates the operation types of the **WantAgent** objects.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                     | Value| Description                                           |
|-------------------------|---|-----------------------------------------------|
| START_SERVICE_EXTENSION<sup>12+</sup> | 6 | Starts a ServiceExtensionAbility.<br>**System API**: This is a system API.|
