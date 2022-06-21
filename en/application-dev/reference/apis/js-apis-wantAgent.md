# WantAgent

>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import WantAgent from '@ohos.wantAgent';
```

## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>): void

Obtains a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name    | Readable| Writable | Type                      | Mandatory| Description                   |
| -------- | --- | ---- | -------------------------- | ---- | ----------------------- |
| info     | Yes  | No  | WantAgentInfo              | Yes  | Information about the **WantAgent** object to obtain.          |
| callback | Yes  | No  | AsyncCallback\<WantAgent\> | Yes  | Callback used to return the **WantAgent** object.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)
```



## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>

Obtains a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Readable| Writable | Type         | Mandatory| Description         |
| ---- | --- | ---- | ------------- | ---- | ------------- |
| info | Yes  | No  | WantAgentInfo | Yes  | Information about the **WantAgent** object to obtain.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<WantAgent\> | Promise used to return the **WantAgent** object.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

| Name    | Readable| Writable | Type                   | Mandatory| Description                             |
| -------- | --- | ---- | ----------------------- | ---- | --------------------------------- |
| agent    | Yes  | No  | WantAgent               | Yes  | Target **WantAgent** object.                    |
| callback | Yes  | No  | AsyncCallback\<string\> | Yes  | Callback used to return the bundle name.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

| Name | Readable| Writable| Type     | Mandatory| Description         |
| ----- | --- | ---- | --------- | ---- | ------------- |
| agent | Yes  | No | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used to return the bundle name.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

| Name    | Readable| Writable| Type                   | Mandatory| Description                               |
| -------- | --- | ---- | ----------------------- | ---- | ----------------------------------- |
| agent    | Yes  | No | WantAgent               | Yes  | Target **WantAgent** object.                      |
| callback | Yes  | No | AsyncCallback\<number\> | Yes  | Callback used to return the user ID.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

| Name | Readable| Writable| Type     | Mandatory| Description         |
| ----- | --- | ---- | --------- | ---- | ------------- |
| agent | Yes  | No | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the user ID.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                           |
| -------- | --- | ---- | --------------------- | ---- | ------------------------------- |
| agent    | Yes  | No | WantAgent             | Yes  | Target **WantAgent** object.                  |
| callback | Yes  | No | AsyncCallback\<Want\> | Yes  | Callback used to return the want.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

**Parameters**

| Name | Readable| Writable| Type     | Mandatory| Description         |
| ----- | --- | ---- | --------- | ---- | ------------- |
| agent | Yes  | No | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Want\> | Promise used to return the want.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

| Name    | Readable| Writable| Type                 | Mandatory| Description                       |
| -------- | --- | ---- | --------------------- | ---- | --------------------------- |
| agent    | Yes  | No | WantAgent             | Yes  | Target **WantAgent** object.              |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

| Name | Readable| Writable| Type     | Mandatory| Description         |
| ----- | --- | ---- | --------- | ---- | ------------- |
| agent | Yes  | No | WantAgent | Yes  | Target **WantAgent** object.|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

| Name       | Readable| Writable| Type                         | Mandatory| Description                           |
| ----------- | --- | ---- | ----------------------------- | ---- | ------------------------------- |
| agent       | Yes  | No | WantAgent                     | Yes  | **WantAgent** object to trigger.                  |
| triggerInfo | Yes  | No | TriggerInfo                   | Yes  | **TriggerInfo** object.                |
| callback    | Yes  | No | AsyncCallback\<CompleteData\> | Yes  | Callback used to return the result.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// trigger callback
function triggerCallback(err, data) {
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

| Name      | Readable| Writable| Type                    | Mandatory| Description                                   |
| ---------- | --- | ---- | ------------------------ | ---- | --------------------------------------- |
| agent      | Yes  | No | WantAgent                | Yes  | The first **WantAgent** object.                          |
| otherAgent | Yes  | No | WantAgent                | Yes  | The second **WantAgent** object.                          |
| callback   | Yes  | No | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

| Name      | Readable| Writable| Type     | Mandatory| Description         |
| ---------- | --- | ---- | --------- | ---- | ------------- |
| agent      | Yes  | No | WantAgent | Yes  | The first **WantAgent** object.|
| otherAgent | Yes  | No | WantAgent | Yes  | The second **WantAgent** object.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

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
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

getOperationType(agent: WantAgent, callback: AsyncCallback\<number>): void

Obtains the operation type of a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name     | Readable | Writable | Type                   | Mandatory | Description                                 |
| ---------- | --- | ---- | --------- | ---- | ------------- |
| agent      | Yes | No  | WantAgent | Yes | Target **WantAgent** object. |
| callback   | Yes | No | AsyncCallback\<number> | Yes | Callback used to return the operation type. |

**Example**

```js
import WantAgent from '@ohos.wantAgent';

//wantAgent����
var wantAgent;

//WantAgentInfo����
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
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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

getOperationType(agent: WantAgent): Promise\<number>

Obtains the operation type of a **WantAgent** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Readable | Writable | Type      | Mandatory | Description   |
| ---------- | --- | ---- | --------- | ---- | ------------- |
| agent      | Yes | No | WantAgent | Yes | WantAgent���� |

**Return value**

| Type              | Description                                |
| ----------------- | ------------------------------------------ |
| Promise\<number\> | Promise used to return the operation type. |


**Example**

```js
import WantAgent from '@ohos.wantAgent';

//wantAgent����
var wantAgent;

//WantAgentInfo����
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
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
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


## WantAgentInfo

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Readable| Writable| Type                           | Mandatory| Description                  |
| -------------- | --- | ---- | ------------------------------- | ---- | ---------------------- |
| wants          | Yes | Yes | Array\<Want\>                   | Yes  | Array of all **Want** objects.    |
| operationType  | Yes | Yes | wantAgent.OperationType         | Yes  | Action type.              |
| requestCode    | Yes | Yes | number                          | Yes  | Request code defined by the user.|
| wantAgentFlags | Yes | Yes | Array<wantAgent.WantAgentFlags> | No  | Array of flags for using the **WantAgent** object.          |
| extraInfo      | Yes | Yes | {[key: string]: any}            | No  | Extra information.              |



## WantAgentFlags

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name               | Value            | Description                                                        |
| ------------------- | -------------- | ------------------------------------------------------------ |
| ONE_TIME_FLAG       | WantAgentFlags | The **WantAgent** object can be used only once.                                     |
| NO_BUILD_FLAG       | WantAgentFlags | The **WantAgent** object does not exist and hence it is not created. In this case, **null** is returned.     |
| CANCEL_PRESENT_FLAG | WantAgentFlags | The existing **WantAgent** object should be canceled before a new object is generated.|
| UPDATE_PRESENT_FLAG | WantAgentFlags | Extra information of the existing **WantAgent** object is replaced with that of the new object.|
| CONSTANT_FLAG       | WantAgentFlags | The **WantAgent** object is immutable.                                       |
| REPLACE_ELEMENT     | WantAgentFlags | The **element** attribute of the current **Want** can be replaced by the **element** attribute of the **Want** in **WantAgent.trigger()**.|
| REPLACE_ACTION      | WantAgentFlags | The **action** attribute of the current **Want** can be replaced by the **action** attribute of the **Want** in **WantAgent.trigger()**.|
| REPLACE_URI         | WantAgentFlags | The **uri** attribute of the current **Want** can be replaced by the **uri** attribute of the **Want** in **WantAgent.trigger()**.|
| REPLACE_ENTITIES    | WantAgentFlags | The **entities** attribute of the current **Want** can be replaced by the **entities** attribute of the **Want** in **WantAgent.trigger()**.|
| REPLACE_BUNDLE      | WantAgentFlags | The **bundleName** attribute of the current **Want** can be replaced by the **bundleName** attribute of **Want** in **WantAgent.trigger()**.|



## OperationType

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name             | Value           | Description                     |
| ----------------- | ------------- | ------------------------- |
| UNKNOWN_TYPE      | OperationType | Unknown operation type.           |
| START_ABILITY     | OperationType | Starts an ability with a UI.|
| START_ABILITIES   | OperationType | Starts multiple abilities with a UI.|
| START_SERVICE     | OperationType | Starts an ability without a UI.|
| SEND_COMMON_EVENT | OperationType | Sends a common event.       |



## CompleteData 

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Readable| Writable| Type                          | Mandatory| Description                   |
| -------------- | --- | ---- | ------------------------------ | ---- | ---------------------- |
| info           | Yes | Yes | WantAgent                       | Yes  | A triggered **WantAgent** object.      |
| want           | Yes | Yes | Want                            | Yes  | An existing triggered **want**.    |
| finalCode      | Yes | Yes | number                          | Yes  | Request code that triggers the **WantAgent** object.|
| finalData      | Yes | Yes | string                          | No  | Final data collected by the common event. |
| extraInfo      | Yes | Yes | {[key: string]: any}            | No  | Extra information.              |



## TriggerInfo

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Readable| Writable| Type                | Mandatory| Description       |
| ---------- | --- | ---- | -------------------- | ---- | ----------- |
| code       | Yes | Yes | number               | Yes  | Result code.|
| want       | Yes | Yes | Want                 | No  | Want.       |
| permission | Yes | Yes | string               | No  | Permission.   |
| extraInfo  | Yes | Yes | {[key: string]: any} | No  | Extra information.   |
