# FeatureAbility Module (JavaScript)

## Constraints

APIs of the **FeatureAbility** module can be called only by Page abilities.

## Modules to Import

```
import featureAbility from '@ohos.ability.featureAbility'
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

Starts an ability. This method uses a callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory| Description               |
| --------- | --------------------- | ---- | ------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes  | Ability to start.|
| callback  | AsyncCallback\<number>         | Yes  | Callback used to return the result.  |

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.startAbility(
        {
        want:
        {
            action: "",
            entities: [""],
            type: "",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    },
);
```



## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>

Starts an ability. This method uses a promise to return the result.

**Parameters**

| Name     | Type                                           | Mandatory| Description                 |
| --------- | ----------------------------------------------- | ---- | --------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes  | Ability to start.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.startAbility(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
			flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    }
   ).then((data) => {
	console.info("==========================>startAbility=======================>");
});
```

## featureAbility.acquireDataAbilityHelper

acquireDataAbilityHelper(uri: string): DataAbilityHelper

Obtains a **dataAbilityHelper** object.

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the file to open.|

**Return value**

| Type             | Description                                        |
| ----------------- | -------------------------------------------- |
| DataAbilityHelper | A utility class used to help other abilities access the Data ability.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.acquireDataAbilityHelper(
    "dataability:///com.exmaple.DataAbility"
)
```

## featureAbility.startAbilityForResult

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

Starts an ability. This method uses a callback to return the execution result when the ability is destroyed.

**Parameters**

| Name     | Type                                           | Mandatory| Description                 |
| --------- | ----------------------------------------------- | ---- | --------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes  | Ability to start.|
| callback  | AsyncCallback\<[AbilityResult](#abilityresult)> | Yes  | Callback used to return the result.   |

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.startAbilityForResult(
   {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:""
        },
    },
)
```

## featureAbility.startAbilityForResult

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

Starts an ability. This method uses a promise to return the execution result when the ability is destroyed.

**Parameters**

| Name     | Type                                           | Mandatory| Description               |
| --------- | ----------------------------------------------- | ---- | ------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes  | Ability to start.|

**Return value**
| Type                                     | Description          |
| ----------------------------------------- | -------------- |
| Promise\<[AbilityResult](#abilityresult)> | Promised returned with the execution result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.startAbilityForResult(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:"",
            parameters:
            {
                mykey0: 1111,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "xxxxxxxxxxxxxxxxxxxxxx",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["aaaaaa", "bbbbb", "ccccccccccc"],
                mykey7: true,
            },
        },
        requestCode: 2,
    },
).then((data) => {
    console.info("==========================>startAbilityForResult=======================>");
});
```

## featureAbility.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

Destroys this Page ability, with the result code and data sent to the caller. This method uses a callback to return the result.

**Parameters**

| Name     | Type         | Mandatory| Description               |
| --------- | ------------- | ---- | ------------------- |
| parameter | [AbilityResult](#abilityresult) | Yes  | Ability to start.|
| callback  | AsyncCallback\<void> | Yes  | Callback used to return the result. |

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:"",
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey7: true,
            }
        },
    },
);
```

## featureAbility.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise\<void>

Destroys this Page ability, with the result code and data sent to the caller. This method uses a promise to return the result.

**Parameters**

| Name     | Type                           | Mandatory| Description               |
| --------- | ------------------------------- | ---- | ------------------- |
| parameter | [AbilityResult](#abilityresult) | Yes  | Ability to start.|

**Return value**
| Type          | Description                   |
| -------------- | ----------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
import wantConstant from '@ohos.ability.wantConstant'
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:"",
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey7: true,
            }
        },
    }
).then((data) => {
    console.info("==========================>terminateSelfWithResult=======================>");
});
```



## featureAbility.hasWindowFocus

hasWindowFocus(callback: AsyncCallback\<boolean>): void

Checks whether the main window of this ability has the focus. This method uses a callback to return the result.

**Parameters**

| Name    | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result.<br>Returns **true** if the main window of this ability has the focus; returns **false** otherwise.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus()
```



## featureAbility.hasWindowFocus

hasWindowFocus(): Promise\<boolean>

Checks whether the main window of this ability has the focus. This method uses a promise to return the result.

**Return value**

| Type             | Description                                                      |
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | Returns **true** if the main window of this ability has the focus; returns **false** otherwise.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus().then((data) => {
    console.info("==========================>hasWindowFocus=======================>");
});
```



## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

Obtains the **Want** object sent from this ability. This method uses a callback to return the result.

**Parameters**

| Name    | Type                         | Mandatory| Description              |
| -------- | ----------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<[Want](#want)> | Yes  | Callback used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant()
```



## featureAbility.getWant

getWant(): Promise\<Want>

Obtains the **Want** object sent from this ability. This method uses a promise to return the result.

**Return value**
| Type                   | Description                     |
| ----------------------- | ------------------------- |
| Promise\<[Want](#want)> | Promise used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant().then((data) => {
		console.info("==========================>getWantCallBack=======================>");
});
```

## featureAbility.getContext

getContext(): Context

Obtains the application context.

**Return value**
| Type   | Description                |
| ------- | -------------------- |
| Context | Application context returned.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
var context = featureAbility.getContext()
context.getBundleName()
```



## featureAbility.terminateSelf

terminateSelf(callback: AsyncCallback\<void>): void

Destroys this Page ability, with the result code and data sent to the caller. This method uses a callback to return the result.

**Parameters**

| Name    | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf()
```



## featureAbility.terminateSelf

terminateSelf(): Promise\<void>

Destroys this Page ability, with the result code and data sent to the caller. This method uses a promise to return the result.

**Return value**
| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf().then((data) => {		    console.info("==========================>terminateSelfCallBack=======================>");
});
```

## featureAbility.connectAbility

connectAbility(request: Want, options:ConnectOptions): number

Connects this ability to a specific Service ability. This method uses a callback to return the result.

**Parameters**

| Name   | Type          | Mandatory| Description                        |
| ------- | -------------- | ---- | ---------------------------- |
| request | [Want](#want)           | Yes  | Service ability to connect.|
| options | ConnectOptions | Yes  | Callback used to return the result.          |

Want

| Name        | Readable/Writable | Type    | Mandatory| Description                                                             |
| ------------ | -------- | -------- | ---- | ----------------------------------                               |
| deviceId     | Read-only    | string   | No  | Device ID of the Service ability to connect. The default value is the local device ID.<br>|
| bundleName   | Read-only    | string   | Yes  | Bundle name of the Service ability to connect.<br>                                  |
| abilityName  | Read-only    | string   | Yes  | Class name of the Service ability to connect.<br>                                  |

ConnectOptions

| Name        | Readable/Writable| Type    | Mandatory| Description                              |
| ------------ | -------- | -------- | ---- | ---------------------------------- |
| onConnect    | Read-only    | function | Yes  | Callback invoked when the connection is successful.<br>              |
| onDisconnect | Read-only    | function | Yes  | Callback invoked when the connection fails.<br>              |
| onFailed     | Read-only    | function | Yes  | Callback invoked when **connectAbility** fails to be called.<br>|

**Return value**
| Type  | Description                    |
| ------ | ------------------------ |
| number | Returns the ID of the Service ability connected.|

**Example**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
    {
        deviceId: "",
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

## featureAbility.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

Disconnects this ability from a specific Service ability. This method uses a callback to return the result.

**Parameters**

| Name      | Type         | Mandatory| Description                          |
| ---------- | ------------- | ---- | ------------------------------ |
| connection | number        | Yes  | ID of the Service ability to disconnect.|
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result.              |

**Example**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = featureAbility.disconnectAbility(connId,
    (error,data) => {
    console.log('featureAbilityTest DisConnectJsSameBundleName result errCode : ' + error.code + " data: " + data)
    },
);
```

## featureAbility.disconnectAbility

disconnectAbility(connection: number): Promise\<void>

Disconnects this ability from a specific Service ability. This method uses a promise to return the result.

**Parameters**

| Name      | Type  | Mandatory| Description                          |
| ---------- | ------ | ---- | ------------------------------ |
| connection | number | Yes  | ID of the Service ability to disconnect.|

**Return value**
| Type          | Description                   |
| -------------- | ----------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = await featureAbility.disconnectAbility(connId);
```

## AbilityResult

| Name      | Readable/Writable| Type                 | Mandatory| Description                                                        |
| ---------- | -------- | --------------------- | ---- | ------------------------------------------------------------ |
| resultCode | Read-only    | number                | Yes  | Result code returned after the ability is destroyed. The feature for defining error-specific result codes is coming soon.<br>|
| want       | Read-only    | [Want](#want) | No  | Data returned after the ability is destroyed. You can define the data to be returned. This parameter can be **null**.<br> |

## StartAbilityParameter

| Name               | Readable/Writable| Type                | Mandatory| Description                                                        |
| ------------------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| want                | Read-only    | [Want](#want)        | Yes  | Information about the ability to start.<br>                      |
| abilityStartSetting | Read-only    | {[key: string]: any} | No  | Special attribute of the ability to start. This attribute can be passed in the method call.<br>|

## Want

| Name       | Readable/Writable| Type                | Mandatory| Description                                                        |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | Read-only    | string               | No  | ID of the device that runs the ability.<br>                               |
| bundleName  | Read-only    | string               | No  | Bundle name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.<br>|
| abilityName | Read-only    | string               | No  | Name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.<br>|
| uri         | Read-only    | string               | No  | URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.<br>|
| type        | Read-only    | string               | No  | MIME type, for example, text/plain or image/*.<br>  |
| flags       | Read-only    | number               | No  | How the **Want** object will be handled. By default, a number is passed. For details, see [flags](#flags).<br>|
| action      | Read-only    | string               | No  | Action option.<br>                          |
| parameters  | Read-only    | {[key: string]: any} | No  | List of parameters in a **Want** object.<br>                                      |
| entities    | Read-only    | Array\<string>       | No  | List of entities.<br>                                   |

## flags

| Name                                | Name      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Indicates the permission to read the URI.<br>                                 |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Indicates the permission to write the URI.<br>                                 |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Returns the result to the ability.<br>                                          |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Indicates whether the ability on the local device can be migrated to a remote device.<br>                |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Indicates that a component does not belong to OHOS.<br>                                        |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Indicates whether to enable an ability.<br>                                        |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Indicates the permission to make the URI persistent.<br>                                   |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Indicates the permission to verify URIs by prefix matching.<br>                                          |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Supports cross-device startup in a distributed scheduler.<br>                            |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the Service ability is started regardless of whether the host application has been started.<br>  |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that the migration is reversible.<br>                                        |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.<br>                         |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.<br>                        |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for the **Want** object passed to **ohos.app.Context#startAbility** and must be used together with **flag_ABILITY_NEW_MISSION**.<br>|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Creates a mission on the historical mission stack.<br>                        |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Starts the mission on the top of the existing mission stack; creates an ability instance if no mission exists.<br>|
