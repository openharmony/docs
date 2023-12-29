# @ohos.app.ability.wantAgent (WantAgent)

The **app.ability.WantAgent** module provides APIs for creating and comparing **WantAgent** objects, and obtaining the user ID, Want, and bundle name of a **WantAgent** object. You are advised to use this module, since it will replace the [@ohos.wantAgent](js-apis-wantAgent.md) module in the near future.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
```

## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>): void

Obtains a **WantAgent** object. This API uses an asynchronous callback to return the result. If the creation fails, a null **WantAgent** object is returned.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                      | Mandatory| Description                   |
| -------- | -------------------------- | ---- | ----------------------- |
| info     | [WantAgentInfo](js-apis-inner-wantAgent-wantAgentInfo.md)              | Yes  | Information about the **WantAgent** object to obtain.          |
| callback | AsyncCallback\<WantAgent\> | Yes  | Callback used to return the **WantAgent** object.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed, error: ${JSON.stringify(err)}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed, error: ${JSON.stringify(err)}`);
}
```



## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>

Obtains a **WantAgent** object. This API uses a promise to return the result. If the creation fails, a null **WantAgent** object is returned.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description         |
| ---- | ------------- | ---- | ------------- |
| info | [WantAgentInfo](js-apis-inner-wantAgent-wantAgentInfo.md) | Yes  | Information about the **WantAgent** object to obtain.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<WantAgent\> | Promise used to return the **WantAgent** object.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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

try {
    WantAgent.getWantAgent(wantAgentInfo).then((data) => {
    wantAgent = data;
}).catch((err: BusinessError) => {
    console.error('getWantAgent failed! ${err.code} ${err.message}');
});
} catch (err) {
    console.error('getWantAgent failed! ${err.code} ${err.message}');
}
```



## WantAgent.getBundleName

getBundleName(agent: WantAgent, callback: AsyncCallback\<string\>): void

Obtains the bundle name of a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                             |
| -------- | ----------------------- | ---- | --------------------------------- |
| agent    | WantAgent               | Yes  | Target **WantAgent** object.                    |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the bundle name.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    // getBundleName callback
    let getBundleNameCallback = (err: BusinessError, data: string) => {
        if(err) {
            console.error(`getBundleName failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getBundleName ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.getBundleName(wantAgent, getBundleNameCallback);
    } catch(err) {
        console.error(`getBundleName failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.getBundleName

getBundleName(agent: WantAgent): Promise\<string\>

Obtains the bundle name of a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type     | Mandatory| Description         |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used to return the bundle name.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
    }
    try {
        WantAgent.getBundleName(wantAgent).then((data)=>{
            console.info(`getBundleName ok! ${JSON.stringify(data)}`);
        }).catch((err: BusinessError)=>{
            console.error(`getBundleName failed! ${err.code} ${err.message}`);
        });
    } catch(err){
        console.error(`getBundleName failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.getUid

getUid(agent: WantAgent, callback: AsyncCallback\<number\>): void

Obtains the user ID of a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                               |
| -------- | ----------------------- | ---- | ----------------------------------- |
| agent    | WantAgent               | Yes  | Target **WantAgent** object.                      |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the user ID.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.info(`getWantAgent failed ${JSON.stringify(err)}`);
    }
    // getUid callback
    let getUidCallback = (err: BusinessError, data: number) => {
        if(err) {
            console.error(`getUid failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getUid ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.getUid(wantAgent, getUidCallback);
    } catch(err) {
        console.error(`getUid failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.getUid

getUid(agent: WantAgent): Promise\<number\>

Obtains the user ID of a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type     | Mandatory| Description         |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the user ID.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
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
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
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



## WantAgent.cancel

cancel(agent: WantAgent, callback: AsyncCallback\<void\>): void

Cancels a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                       |
| -------- | --------------------- | ---- | --------------------------- |
| agent    | WantAgent             | Yes  | Target **WantAgent** object.              |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    // cancel callback
    let cancelCallback = (err: BusinessError, data: void) => {
        if(err) {
            console.error(`cancel failed! ${err.code} ${err.message}`);
        } else {
            console.info(`cancel ok!`);
        }
    }
    try {
        WantAgent.cancel(wantAgent, cancelCallback);
    } catch(err) {
        console.error(`cancel failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.cancel

cancel(agent: WantAgent): Promise\<void\>

Cancels a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type     | Mandatory| Description         |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
    }
    try {
        WantAgent.cancel(wantAgent).then((data)=>{
            console.info('cancel ok!');
        }).catch((err: BusinessError)=>{
            console.error(`cancel failed! ${err.code} ${err.message}`);
        });
    } catch(err){
        console.error(`cancel failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## WantAgent.trigger

trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback\<CompleteData\>): void

Triggers a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                           |
| ----------- | ----------------------------- | ---- | ------------------------------- |
| agent       | WantAgent                     | Yes  | Target **WantAgent** object.                  |
| triggerInfo | [TriggerInfo](js-apis-inner-wantAgent-triggerInfo.md)                   | Yes  | **TriggerInfo** object.                |
| callback    | AsyncCallback\<[CompleteData](#completedata)\> | No  | Callback used to return the result.|

**Example**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

// WantAgent object
let wantAgent: _WantAgent;
// triggerInfo
let triggerInfo: WantAgent.TriggerInfo = {
    code: 0 // Custom result code.
};
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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    // trigger callback
    let triggerCallback = (err: BusinessError, data: WantAgent.CompleteData) => {
        if(err) {
            console.error(`getUid failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getUid ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.trigger(wantAgent, triggerInfo, triggerCallback);
    } catch(err) {
        console.error(`getUid failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean\>): void

Checks whether two **WantAgent** objects are equal to determine whether the same operation is from the same application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                                   |
| ---------- | ------------------------ | ---- | --------------------------------------- |
| agent      | WantAgent                | Yes  | The first **WantAgent** object.                          |
| otherAgent | WantAgent                | Yes  | The second **WantAgent** object.                          |
| callback   | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

// WantAgent object
let wantAgent1: _WantAgent;
let wantAgent2: _WantAgent;
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
    if (err === undefined) {
        wantAgent1 = data;
        wantAgent2 = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    // equal callback
    let equalCallback = (err: BusinessError, data: boolean) => {
        if(err) {
            console.error(`equal failed! ${err.code} ${err.message}`);
        } else {
            console.info(`equal ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.equal(wantAgent1,wantAgent2,equalCallback);
    } catch(err) {
        console.error(`equal failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```



## WantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean\>

Checks whether two **WantAgent** objects are equal to determine whether the same operation is from the same application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type     | Mandatory| Description         |
| ---------- | --------- | ---- | ------------- |
| agent      | WantAgent | Yes  | The first **WantAgent** object.|
| otherAgent | WantAgent | Yes  | The second **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```ts
import WantAgent, { WantAgent as _WantAgent} from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

// WantAgent object
let wantAgent1: _WantAgent;
let wantAgent2: _WantAgent;
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
    if (err === undefined) {
        wantAgent1 = data;
        wantAgent2 = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
    }
    try {
        WantAgent.equal(wantAgent1,wantAgent2).then((data)=>{
            console.info(`equal ok! ${JSON.stringify(data)}`);
        }).catch((err: BusinessError)=>{
            console.error(`equal failed! ${err.code} ${err.message}`);
        })
    } catch(err){
        console.error(`equal failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## WantAgent.getOperationType

getOperationType(agent: WantAgent, callback: AsyncCallback\<number>): void;

Obtains the operation type of a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                                   |
| ---------- | ------------------------ | ---- | --------------------------------------- |
| agent      | WantAgent                | Yes  | Target **WantAgent** object.                          |
| callback   | AsyncCallback\<number> | Yes  | Callback used to return the operation type.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed ${JSON.stringify(wantAgent)}`);
    }
    // getOperationTypeCallback callback
    let getOperationTypeCallback = (err: BusinessError, data: number) => {
        if(err) {
            console.error(`getOperationType failed! ${err.code} ${err.message}`);
        } else {
            console.info(`getOperationType ok! ${JSON.stringify(data)}`);
        }
    }
    try {
        WantAgent.getOperationType(wantAgent, getOperationTypeCallback);
    } catch(err) {
        console.error(`getOperationTypeCallback failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## WantAgent.getOperationType

getOperationType(agent: WantAgent): Promise\<number>;

Obtains the operation type of a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type     | Mandatory| Description         |
| ---------- | --------- | ---- | ------------- |
| agent      | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise used to return the operation type.|

**Error codes**

| ID   | Error Message           |
|-----------|--------------------|
| 16000007   | Service busy, there are concurrent tasks, waiting for retry.|
| 16000015   | Service timeout.|
| 16000151   | Invalid wantagent object.|

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

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
    if (err === undefined) {
        wantAgent = data;
    } else {
        console.error(`getWantAgent failed! ${JSON.stringify(wantAgent)}`);
    }
    try {
        WantAgent.getOperationType(wantAgent).then((data)=>{
            console.info(`getOperationType ok! ${JSON.stringify(data)}`);
        }).catch((err: BusinessError) => {
            console.error(`getOperationType failed! ${err.code} ${err.message}`);
        });
    } catch(err){
        console.error(`getOperationType failed! ${err.code} ${err.message}`);
    }
}
try {
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err) {
    console.error(`getWantAgent failed! ${err.code} ${err.message}`);
}
```

## WantAgentFlags

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name               | Value            | Description                                                                    |
| ------------------- | -------------- |------------------------------------------------------------------------|
| ONE_TIME_FLAG       | 0 | The **WantAgent** object can be used only once.                                                      |
| NO_BUILD_FLAG       | 1 | The **WantAgent** object does not exist and hence it is not created. In this case, **null** is returned.                                    |
| CANCEL_PRESENT_FLAG | 2 | The existing **WantAgent** object should be canceled before a new object is generated.                               |
| UPDATE_PRESENT_FLAG | 3 | Extra information of the existing **WantAgent** object is replaced with that of the new object.                              |
| CONSTANT_FLAG       | 4 | The **WantAgent** object is immutable.                                                       |
| REPLACE_ELEMENT     | 5 | The **element** attribute in the current Want can be replaced by the **element** attribute in the Want passed in **WantAgent.trigger()**. This processing is not supported yet.     |
| REPLACE_ACTION      | 6 | The **action** attribute in the current Want can be replaced by the **action** attribute in the Want passed in **WantAgent.trigger()**. This processing is not supported yet.       |
| REPLACE_URI         | 7 | The **uri** attribute in the current Want can be replaced by the **uri** attribute in the Want passed in **WantAgent.trigger()**. This processing is not supported yet.             |
| REPLACE_ENTITIES    | 8 | The **entities** attribute in the current Want can be replaced by the **entities** attribute in the Want passed in **WantAgent.trigger()**. This processing is not supported yet.   |
| REPLACE_BUNDLE      | 9 | The **bundleName** attribute in the current Want can be replaced by the **bundleName** attribute in the Want passed in **WantAgent.trigger()**. This processing is not supported yet.|



## OperationType

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name             | Value           | Description                     |
| ----------------- | ------------- | ------------------------- |
| UNKNOWN_TYPE      | 0 | Unknown operation type.           |
| START_ABILITY     | 1 | Starts an ability with a UI.|
| START_ABILITIES   | 2 | Starts multiple abilities with a UI.|
| START_SERVICE     | 3 | Starts an ability without a UI.|
| SEND_COMMON_EVENT | 4 | Sends a common event.       |



## CompleteData 

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Type                          | Mandatory| Description                   |
| -------------- | ------------------------------ | ---- | ---------------------- |
| info           | WantAgent                       | Yes  | A triggered **WantAgent** object.      |
| want           | Want                            | Yes  | An existing triggered Want.    |
| finalCode      | number                          | Yes  | Request code that triggers the **WantAgent** object.|
| finalData      | string                          | Yes  | Final data collected by the common event. |
| extraInfo      | {[key: string]: any}            | No  | Extra information.              |
