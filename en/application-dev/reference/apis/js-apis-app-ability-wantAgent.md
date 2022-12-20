# @ohos.app.ability.wantAgent

The **app.ability.WantAgent** module provides APIs for triggering, canceling, and comparing **WantAgent** objects. You can use the APIs to create a **WantAgent** object, and obtain the user ID, bundle name, and want information of the object. You are advised to use this module, since it will replace the [@ohos.wantAgent](js-apis-wantAgent.md) module in the near future.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
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

**Error codes**
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|


**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';

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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed' + JSON.stringify(err));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
}
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

**Error codes**
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';


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

try {
    WantAgent.getWantAgent(wantAgentInfo).then((data) => {
    wantAgent = data;
}).catch((err) => {
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
});
} catch (err) {
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
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
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed' + JSON.stringify(wantAgent));
    }
    // getBundleName callback
    function getBundleNameCallback(err, data) {
        if(err) {
            console.info('getBundleName failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        } else {
            console.info('getBundleName ok!' + JSON.stringify(data));
        }
    }
    try {
        WantAgent.getBundleName(wantAgent, getBundleNameCallback);
    } catch(err) {
        console.info('getBundleName failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
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
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';

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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed!' + JSON.stringify(wantAgent));
    }
    try {
        WantAgent.getBundleName(wantAgent).then((data)=>{
            console.info('getBundleName ok!' + JSON.stringify(data));
        }).catch((err)=>{
            console.info('getBundleName failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        })
    } catch(err){
        console.info('getBundleName failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
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
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed' + JSON.stringify(err));
    }
    // getUid callback
    function getUidCallback(err, data) {
        if(err) {
            console.info('getUid failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        } else {
            console.info('getUid ok!' + JSON.stringify(data));
        }
    }
    try {
        WantAgent.getUid(wantAgent, getUidCallback);
    } catch(err) {
        console.info('getUid failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
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
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';

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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed!' + JSON.stringify(wantAgent));
    }
    try {
        WantAgent.getUid(wantAgent).then((data)=>{
            console.info('getUid ok!' + JSON.stringify(data));
        }).catch((err)=>{
            console.info('getUid failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        })
    } catch(err){
        console.info('getUid failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
}
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

**Error codes**
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed' + JSON.stringify(wantAgent));
    }
    // getUid callback
    function getWantCallback(err, data) {
        if(err) {
            console.info('getWant failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        } else {
            console.info('getWant ok!' + JSON.stringify(data));
        }
    }
    try {
        WantAgent.getWant(wantAgent, getBundleNameCallback);
    } catch(err) {
        console.info('getWant failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
}
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

**Error codes**
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';

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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed!' + JSON.stringify(wantAgent));
    }
    try {
        WantAgent.getUid(wantAgent).then((data)=>{
            console.info('getUid ok!' + JSON.stringify(data));
        }).catch((err)=>{
            console.info('getUid failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        })
    } catch(err){
        console.info('getUid failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
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
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed' + JSON.stringify(wantAgent));
    }
    // getUid callback
    function cancelCallback(err, data) {
        if(err) {
            console.info('cancel failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        } else {
            console.info('cancel ok!');
        }
    }
    try {
        WantAgent.cancel(wantAgent, getBundleNameCallback);
    } catch(err) {
        console.info('cancel failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
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
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';

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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed!' + JSON.stringify(wantAgent));
    }
    try {
        WantAgent.cancel(wantAgent).then((data)=>{
            console.info('cancel ok!');
        }).catch((err)=>{
            console.info('cancel failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        })
    } catch(err){
        console.info('cancel failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
}
```


//TODO WantAgent.trigger Callback


## WantAgent.trigger

trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback\<CompleteData\>): void

Triggers a **WantAgent** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                           |
| ----------- | ----------------------------- | ---- | ------------------------------- |
| agent       | WantAgent                     | Yes  | Target **WantAgent** object.                  |
| triggerInfo | TriggerInfo                   | Yes  | **TriggerInfo** object.                |
| callback    | AsyncCallback\<CompleteData\> | No  | Callback used to return the result.|

**Error codes**
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

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
            console.info('getUid failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        } else {
            console.info('getUid ok!' + JSON.stringify(data));
        }
    }
    try {
        WantAgent.trigger(wantAgent, triggerInfo, triggerCallback);
    } catch(err) {
        console.info('getUid failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
}
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

**Error codes**
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent1 = data;
        wantAgent2 = data;
    } else {
        console.info('getWantAgent failed' + JSON.stringify(wantAgent));
    }
    // getUid callback
    function equalCallback(err, data) {
        if(err) {
            console.info('equal failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        } else {
            console.info('equal ok!' + JSON.stringify(data));
        }
    }
    try {
        WantAgent.equal(wantAgent1,wantAgent2,equalCallback);
    } catch(err) {
        console.info('equal failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
}
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

**Error codes**
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';

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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent1 = data;
        wantAgent2 = data;
    } else {
        console.info('getWantAgent failed!' + JSON.stringify(wantAgent));
    }
    try {
        WantAgent.equal(wantAgent1,wantAgent2).then((data)=>{
            console.info('equal ok!' + JSON.stringify(data));
        }).catch((err)=>{
            console.info('equal failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        })
    } catch(err){
        console.info('equal failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
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
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';
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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed' + JSON.stringify(wantAgent));
    }
    // getUid callback
    function getOperationTypeCallback(err, data) {
        if(err) {
            console.info('getOperationType failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        } else {
            console.info('getOperationType ok!' + JSON.stringify(data));
        }
    }
    try {
        WantAgent.getOperationTypeCallback(wantAgent, getBundleNameCallback);
    } catch(err) {
        console.info('getOperationTypeCallback failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
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
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).
| ID   | Error Message           |
|-----------|--------------------|
| 16000001   | Input error. The specified ability name does not exist. |
| 16000002   | Ability type error. The specified ability type is wrong.|
| 16000003   | Input error. The specified id does not exist.|
| 16000004   | Visibility verification failed.|
| 16000006   | Can not cross user operations.|
| 16000007   | Service busyness. There are concurrent tasks, waiting for retry.|
| 16000008   | Crowdtest App Expiration.|
| 16000009   | Can not start ability in wukong mode.|
| 16000010   | Can not operation with continue flag.|
| 16000011   | Context does not exist.|
| 16000050   | Internal Error.|
| 16000051   | Network error. The network is abnormal.|
| 16000052   | Free install not support. The application does not support free install. |
| 16000053   | Not top ability. The application is not top ability.|
| 16000054   | Free install busyness. There are concurrent tasks, waiting for retry.|
| 16000055   | Free install timeout.|
| 16000056   | Can not free install other ability.|
| 16000057   | Not support cross device free install.|
| 16000101   | execute shell command failed.|
| 16000151   | Invalid wantagent object.|
| 16000152   | wantAgent object not found.|
| 16000153   | wangAgent object canceled.|

**Example**

```ts
import WantAgent from '@ohos.app.ability.wantAgent';

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

// getWantAgent callback
function getWantAgentCallback(err, data) {
    if (err == undefined) {
        wantAgent = data;
    } else {
        console.info('getWantAgent failed!' + JSON.stringify(wantAgent));
    }
    try {
        WantAgent.getOperationType(wantAgent).then((data)=>{
            console.info('getOperationType ok!' + JSON.stringify(data));
        }).catch((err)=>{
            console.info('getOperationType failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
        })
    } catch(err){
        console.info('getOperationType failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
    }
}
try{
    WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback);
} catch(err){
    console.info('getWantAgent failed!' + JSON.stringify(err.code) + JSON.stringify(err.message));
}
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
