# @ohos.wantAgent

The **WantAgent** module provides APIs for triggering, canceling, and comparing **WantAgent** objects. You can use the APIs to create a **WantAgent** object, and obtain the user ID, bundle name, and want information of the object.

> **NOTE**
> 
> The APIs of this module are supported since API version 7 and deprecated since API version 9. You are advised to use [@ohos.app.ability.wantAgent](js-apis-app-ability-wantAgent.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import WantAgent from '@ohos.wantAgent';
```

## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>): void

Obtains a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Type                      | Mandatory| Description                   |
| -------- | -------------------------- | ---- | ----------------------- |
| info     | WantAgentInfo              | Yes  | Information about the **WantAgent** object to obtain.          |
| callback | AsyncCallback\<WantAgent\> | Yes  | Callback used to return the **WantAgent** object.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
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

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)
```



## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>

Obtains a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description         |
| ---- | ------------- | ---- | ------------- |
| info | WantAgentInfo | Yes  | Information about the **WantAgent** object to obtain.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<WantAgent\> | Promise used to return the **WantAgent** object.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';


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

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
});
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

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
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

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// getBundleName callback
function getBundleNameCallback(err, data) {
	console.info("==========================>getBundleNameCallback=======================>");
}
WantAgent.getBundleName(wantAgent, getBundleNameCallback)
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

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent;

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

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getBundleName(wantAgent).then((data) => {
	console.info("==========================>getBundleNameCallback=======================>");
});
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

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
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

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// getUid callback
function getUidCallback(err, data) {
	console.info("==========================>getUidCallback=======================>");
}
WantAgent.getUid(wantAgent, getUidCallback)
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

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent;

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

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getUid(wantAgent).then((data) => {
	console.info("==========================>getUidCallback=======================>");
});
```



## WantAgent.getWant

getWant(agent: WantAgent, callback: AsyncCallback\<Want\>): void

Obtains the want in a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                           |
| -------- | --------------------- | ---- | ------------------------------- |
| agent    | WantAgent             | Yes  | Target **WantAgent** object.                  |
| callback | AsyncCallback\<Want\> | Yes  | Callback used to return the want.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
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

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// getWant callback
function getWantCallback(err, data) {
	console.info("==========================>getWantCallback=======================>");
}
WantAgent.getWant(wantAgent, getWantCallback)
```



## WantAgent.getWant

getWant(agent: WantAgent): Promise\<Want\>

Obtains the want in a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name | Type     | Mandatory| Description         |
| ----- | --------- | ---- | ------------- |
| agent | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Want\> | Promise used to return the want.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent;

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

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getWant(wantAgent).then((data) => {
	console.info("==========================>getWantCallback=======================>");
});
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

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
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

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// cancel callback
function cancelCallback(err, data) {
	console.info("==========================>cancelCallback=======================>");
}
WantAgent.cancel(wantAgent, cancelCallback)
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

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent;

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

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.cancel(wantAgent).then((data) => {
	console.info("==========================>cancelCallback=======================>");
});
```



## WantAgent.trigger

trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData\>): void

Triggers a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                           |
| ----------- | ----------------------------- | ---- | ------------------------------- |
| agent       | WantAgent                     | Yes  | Target **WantAgent** object.                  |
| triggerInfo | TriggerInfo                   | Yes  | **TriggerInfo** object.                |
| callback    | AsyncCallback\<CompleteData\> | No  | Callback used to return the result.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
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

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// trigger callback
function triggerCallback(data) {
	console.info("==========================>triggerCallback=======================>");
}

var triggerInfo = {
    code:0
}
WantAgent.trigger(wantAgent, triggerInfo, triggerCallback)
```



## WantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean\>): void

Checks whether two **WantAgent** objects are equal. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                                   |
| ---------- | ------------------------ | ---- | --------------------------------------- |
| agent      | WantAgent                | Yes  | The first **WantAgent** object.                          |
| otherAgent | WantAgent                | Yes  | The second **WantAgent** object.                          |
| callback   | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent1;
var wantAgent2;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent1 = data;
        wantAgent2 = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
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

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// equal callback
function equalCallback(err, data) {
	console.info("==========================>equalCallback=======================>");
}
WantAgent.equal(wantAgent1, wantAgent2, equalCallback)
```



## WantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean\>

Checks whether two **WantAgent** objects are equal. This API uses a promise to return the result.

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

```js
import WantAgent from '@ohos.wantAgent';


// WantAgent object
var wantAgent1;
var wantAgent2;

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

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent1 = data;
    wantAgent2 = data;
});

WantAgent.equal(wantAgent1, wantAgent2).then((data) => {
	console.info("==========================>equalCallback=======================>");
});
```

## WantAgent.getOperationType<sup>9+</sup>

getOperationType(agent: WantAgent, callback: AsyncCallback\<number>): void;

Obtains the operation type of a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                                   |
| ---------- | ------------------------ | ---- | --------------------------------------- |
| agent      | WantAgent                | Yes  | Target **WantAgent** object.                          |
| callback   | AsyncCallback\<number> | Yes  | Callback used to return the operation type.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';

// WantAgent object
var wantAgent;

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

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getOperationType(wantAgent, (OperationType) => {
    console.log('----------- getOperationType ----------, OperationType: ' + OperationType);
})
```

## WantAgent.getOperationType<sup>9+</sup>

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

**Example**

```js
import WantAgent from '@ohos.wantAgent';

// WantAgent object
var wantAgent;

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

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getOperationType(wantAgent).then((OperationType) => {
    console.log('getOperationType success, OperationType: ' + OperationType);
}).catch((err) => {
    console.log('getOperationType fail, err: ' + err);
})
```


## WantAgentFlags

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name               | Value            | Description                                                        |
| ------------------- | -------------- | ------------------------------------------------------------ |
| ONE_TIME_FLAG       | 0 | The **WantAgent** object can be used only once.                                     |
| NO_BUILD_FLAG       | 1 | The **WantAgent** object does not exist and hence it is not created. In this case, **null** is returned.     |
| CANCEL_PRESENT_FLAG | 2 | The existing **WantAgent** object should be canceled before a new object is generated.|
| UPDATE_PRESENT_FLAG | 3 | Extra information of the existing **WantAgent** object is replaced with that of the new object.|
| CONSTANT_FLAG       | 4 | The **WantAgent** object is immutable.                                       |
| REPLACE_ELEMENT     | 5 | The **element** attribute of the current **Want** can be replaced by the **element** attribute of the **Want** in **WantAgent.trigger()**.|
| REPLACE_ACTION      | 6 | The **action** attribute of the current **Want** can be replaced by the **action** attribute of the **Want** in **WantAgent.trigger()**.|
| REPLACE_URI         | 7 | The **uri** attribute of the current **Want** can be replaced by the **uri** attribute of the **Want** in **WantAgent.trigger()**.|
| REPLACE_ENTITIES    | 8 | The **entities** attribute of the current **Want** can be replaced by the **entities** attribute of the **Want** in **WantAgent.trigger()**.|
| REPLACE_BUNDLE      | 9 | The **bundleName** attribute of the current **Want** can be replaced by the **bundleName** attribute of **Want** in **WantAgent.trigger()**.|

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
| want           | Want                            | Yes  | An existing triggered **want**.    |
| finalCode      | number                          | Yes  | Request code that triggers the **WantAgent** object.|
| finalData      | string                          | No  | Final data collected by the common event. |
| extraInfo      | {[key: string]: any}            | No  | Extra information.              |
