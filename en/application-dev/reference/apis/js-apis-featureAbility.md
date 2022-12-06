# FeatureAbility

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> API version 9 is a canary version for trial use. The APIs of this version may be unstable.

## Constraints

APIs of the **FeatureAbility** module can be called only by Page abilities.

## Modules to Import

```
import featureAbility from '@ohos.ability.featureAbility'
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes   | Ability to start.|
| callback  | AsyncCallback\<number>                   | Yes   | Callback used to return the result.     |

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
    (err, data) => {
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
);
```



## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes   | Ability to start.|

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

## featureAbility.acquireDataAbilityHelper<sup>7+</sup>

acquireDataAbilityHelper(uri: string): DataAbilityHelper

Obtains a **dataAbilityHelper** object.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name  | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| uri  | string | Yes   | URI of the file to open.|

**Return value**

| Type               | Description                             |
| ----------------- | ------------------------------- |
| DataAbilityHelper | A utility class used to help other abilities access the Data ability.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
)
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

Starts an ability. This API uses an asynchronous callback to return the execution result when the ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes   | Ability to start.|
| callback  | AsyncCallback\<[AbilityResult](#abilityresult)> | Yes   | Callback used to return the result.     |

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
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
    (err, data) => {
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
)
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

Starts an ability. This API uses a promise to return the execution result when the ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description           |
| --------- | ---------------------------------------- | ---- | ------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes   | Ability to start.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<[AbilityResult](#abilityresult)> | Promised returned with the execution result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
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

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

Destroys this Page ability, with the result code and data sent to the caller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                             | Mandatory  | Description            |
| --------- | ------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](#abilityresult) | Yes   | Ability to destroy.|
| callback  | AsyncCallback\<void>            | Yes   | Callback used to return the result.     |

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
    (err) => {
        console.info("err: " + JSON.stringify(err))
    }
);
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult): Promise\<void>

Destroys this Page ability, with the result code and data sent to the caller. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                             | Mandatory  | Description           |
| --------- | ------------------------------- | ---- | ------------- |
| parameter | [AbilityResult](#abilityresult) | Yes   | Ability to destroy.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
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



## featureAbility.hasWindowFocus<sup>7+<sup>

hasWindowFocus(callback: AsyncCallback\<boolean>): void

Checks whether the main window of this ability has the focus. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the result.<br>Returns **true** if the main window of this ability has the focus; returns **false** otherwise.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus(
    (err, data) => {
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
)
```



## featureAbility.hasWindowFocus<sup>7+<sup>

hasWindowFocus(): Promise\<boolean>

Checks whether the main window of this ability has the focus. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type               | Description                                   |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | Returns **true** if the main window of this ability has the focus; returns **false** otherwise.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus().then((data) => {
    console.info("==========================>hasWindowFocus=======================>");
});
```



## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

Obtains the **Want** object sent from this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                           | Mandatory  | Description       |
| -------- | ----------------------------- | ---- | --------- |
| callback | AsyncCallback\<[Want](#want)> | Yes   | Callback used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant(
    (err, data) => {
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
)
```



## featureAbility.getWant

getWant(): Promise\<Want>

Obtains the **Want** object sent from this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type                     | Description              |
| ----------------------- | ---------------- |
| Promise\<[Want](#want)> | Promise used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant().then((data) => {
		console.info("==========================>getWantCallBack=======================>");
});
```

## featureAbility.getContext

getContext(): Context

Obtains the application context.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type     | Description        |
| ------- | ---------- |
| Context | Application context.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext()
context.getBundleName()
```



## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(callback: AsyncCallback\<void>): void

Destroys this Page ability, with the result code and data sent to the caller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                  | Mandatory  | Description      |
| -------- | -------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf(
    (err) => {
        console.info("err: " + JSON.stringify(err))
    }
)
```



## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(): Promise\<void>

Destroys this Page ability, with the result code and data sent to the caller. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf().then((data) => {		    console.info("==========================>terminateSelfCallBack=======================>");
});
```

## featureAbility.connectAbility<sup>7+</sup>

connectAbility(request: Want, options:ConnectOptions): number

Connects this ability to a specific Service ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name     | Type            | Mandatory  | Description                   |
| ------- | -------------- | ---- | --------------------- |
| request | [Want](#want)  | Yes   | Service ability to connect.|
| options | ConnectOptions | Yes   | Callback used to return the result.            |

Want

**System capability**: SystemCapability.Ability.AbilityBase

| Name        | Readable/Writable | Type   | Mandatory | Description                                                  |
| ----------- | ----------------- | ------ | --------- | ------------------------------------------------------------ |
| deviceId    | Read-only         | string | No        | Device ID of the Service ability to connect. The default value is the local device ID. |
| bundleName  | Read-only         | string | Yes       | Bundle name of the Service ability to connect.               |
| abilityName | Read-only         | string | Yes       | Class name of the Service ability to connect.                |

ConnectOptions

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Readable/Writable | Type      | Mandatory  | Description                       |
| ------------ | -- | -------- | ---- | ------------------------- |
| onConnect    | Read-only | function | Yes   | Callback invoked when the connection is successful.              |
| onDisconnect | Read-only | function | Yes   | Callback invoked when the connection fails.              |
| onFailed     | Read-only | function | Yes   | Callback invoked when **connectAbility** fails to be called.|

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | ID of the Service ability connected.|

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

## featureAbility.disconnectAbility<sup>7+</sup>

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

Disconnects this ability from a specific Service ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                  | Mandatory  | Description                     |
| ---------- | -------------------- | ---- | ----------------------- |
| connection | number               | Yes   | ID of the Service ability to disconnect.|
| callback   | AsyncCallback\<void> | Yes   | Callback used to return the result.               |

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
    (error) => {
        console.log('featureAbilityTest DisConnectJsSameBundleName result errCode : ' + error.code)
    },
);
```

## featureAbility.disconnectAbility<sup>7+</sup>

disconnectAbility(connection: number): Promise\<void>

Disconnects this ability from a specific Service ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type    | Mandatory  | Description                     |
| ---------- | ------ | ---- | ----------------------- |
| connection | number | Yes   | ID of the Service ability to disconnect.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
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

featureAbility.disconnectAbility(connId).then((error,data)=>{
    console.log('featureAbilityTest result errCode : ' + error.code + " data: " + data);
});
```


## featureAbility.getWindow<sup>7+</sup>

getWindow(callback: AsyncCallback\<window.Window>): void

Obtains the window corresponding to this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                         | Mandatory| Description                         |
| -------- | ----------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<window.Window> | Yes  | Callback used to return the window.|

**Example**

```javascript
featureAbility.getWindow(
    (err, data) => {
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
)
```

## featureAbility.getWindow<sup>7+</sup>

getWindow(): Promise\<window.Window>;

Obtains the window corresponding to this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type                   | Description                         |
| ----------------------- | ----------------------------- |
| Promise\<window.Window> | Promise used to return the window.|

**Example**

```javascript
featureAbility.getWindow().then((data) => {
  console.info("=============getWindowPromise========== " +  JSON.stringify(data)); 
});
```

## ConnectOptions.onConnect<sup>7+</sup>

onConnect(elementName: ElementName, remote: rpc.IRemoteObject): void;

Callback invoked when the connection is successful.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name         | Type               | Mandatory  | Description      |
| ----------- | ----------------- | ---- | -------- |
| elementName | ElementName       | Yes   | Element name.    |
| remote      | rpc.IRemoteObject | Yes   | RPC remote object.|

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

## ConnectOptions.onDisconnect<sup>7+</sup>

onDisconnect(elementName: ElementName): void;

Callback invoked when the connection fails.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name         | Type         | Mandatory  | Description  |
| ----------- | ----------- | ---- | ---- |
| elementName | ElementName | Yes   | Element name.|

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

## ConnectOptions.onFailed<sup>7+</sup>

onFailed(code: number): void;

Callback invoked when **connectAbility** fails to be called.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type    | Mandatory  | Description       |
| ---- | ------ | ---- | --------- |
| code | number | Yes   | Number type.|

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





## AbilityWindowConfiguration

The value is obtained through the **featureAbility.AbilityWindowConfiguration** API.

**Example**

```
featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED
```

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                                    | Value  | Description                                      |
| ---------------------------------------- | ---- | ---------------------------------------- |
| WINDOW_MODE_UNDEFINED<sup>7+</sup>       | 0    | The Page ability is in an undefined window display mode.|
| WINDOW_MODE_FULLSCREEN<sup>7+</sup>      | 1    | The Page ability is in full screen mode.   |
| WINDOW_MODE_SPLIT_PRIMARY<sup>7+</sup>   | 100  | The Page ability is displayed in the primary window when it is in split-screen mode.|
| WINDOW_MODE_SPLIT_SECONDARY<sup>7+</sup> | 101  | The Page ability is displayed in the secondary window when it is in split-screen mode.|
| WINDOW_MODE_FLOATING<sup>7+</sup>        | 102  | The Page ability is displayed in floating window mode.|


## AbilityStartSetting

The **AbilityStartSetting** attribute is an object defined as [key: string]: any. The key is a type of **AbilityStartSetting**, and the value is a type of **AbilityWindowConfiguration**.

The value is obtained through the **featureAbility.AbilityStartSetting** API.

**Example**

```
featureAbility.AbilityStartSetting.BOUNDS_KEY
```

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                          | Value             | Description                                      |
| ---------------------------- | --------------- | ---------------------------------------- |
| BOUNDS_KEY<sup>7+</sup>      | "abilityBounds" | Ability window size.|
| WINDOW_MODE_KEY<sup>7+</sup> | "windowMode"    | Ability window display mode.|
| DISPLAY_ID_KEY<sup>7+</sup>  | "displayId"     | Display device ID.|

## ErrorCode

Enumerates error codes.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| NO_ERROR<sup>7+</sup>          | 0    | No error occurs.|
| INVALID_PARAMETER<sup>7+</sup> | -1   | Invalid parameter.|
| ABILITY_NOT_FOUND<sup>7+</sup> | -2   | The ability is not found.|
| PERMISSION_DENY<sup>7+</sup>   | -3   | The request is denied.|


## DataAbilityOperationType

Enumerates operation types of the Data ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                      | Value   | Description                                      |
| ------------------------ | ---- | ---------------------------------------- |
| TYPE_INSERT<sup>7+</sup> | 1    | Insert operation.|
| TYPE_UPDATE<sup>7+</sup> | 2    | Update operation.|
| TYPE_DELETE<sup>7+</sup> | 3    | Deletion operation.|
| TYPE_ASSERT<sup>7+</sup> | 4    | Assert operation.|



## AbilityResult

**System capability**: SystemCapability.Ability.AbilityBase

| Name                  | Readable/Writable |   Type  | Mandatory  | Description                                   |
| ---------------        |-------- | ------ | ------------------------------------- | ------------------------------------- |
| resultCode<sup>7+</sup>| Read-only | number| Yes   | Result code returned after the ability is destroyed. The feature for defining error-specific result codes is coming soon.|
| want<sup>7+</sup>      | Read-only | [Want](#want)| No   | Data returned after the ability is destroyed. You can define the data to be returned. This parameter can be **null**. |

## StartAbilityParameter

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name              | Readable/Writable |   Type  | Mandatory  | Description                                   |
| ------------------- | -------- | -------------------- | -------------------- | -------------------- |
| want                | Read-only       | [Want](#want)| Yes   | Information about the ability to start.                    |
| abilityStartSetting | Read-only | {[key: string]: any} | No   | Special attribute of the ability to start. This attribute can be passed in the method call.|


## Want

**System capability**: SystemCapability.Ability.AbilityBase

| Name                              | Readable/Writable | Type                        | Mandatory | Description                                                  |
| --------------------------------- | ----------------- | --------------------------- | --------- | ------------------------------------------------------------ |
| deviceId                          | Read-only         | string                      | No        | ID of the device that runs the ability.                      |
| bundleName                        | Read-only         | string                      | No        | Bundle name of the ability to start.                         |
| abilityName                       | Read-only         | string                      | No        | Name of the ability to start. If both **package** and **AbilityName** are specified in this field in a **Want** object, the **Want** object can directly match the specified ability. |
| uri                               | Read-only         | string                      | No        | URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**. |
| type                              | Read-only         | string                      | No        | MIME type, for example, text/plain or image/*.               |
| flags                             | Read-only         | number                      | No        | How the **Want** object will be handled. By default, a number is passed. For details, see [flags](#flags). |
| action                            | Read-only         | string                      | No        | Action option.                                               |
| parameters                        | Read-only         | {[key: string]: any}        | No        | List of parameters in the **Want** object.                   |
| entities                          | Read-only         | Array\<string>              | No        | List of entities.                                            |
| extensionAbilityType<sup>9+</sup> | Read-only         | bundle.ExtensionAbilityType | No        | Type of the Extension ability.                               |
| extensionAbilityName<sup>9+<sup>  | Read-only         | string                      | No        | Description of the Extension ability name in the **Want** object. |

## flags

**System capability**: SystemCapability.Ability.AbilityBase

| Name                                  | Value        | Description                                      |
| ------------------------------------ | ---------- | ---------------------------------------- |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Indicates the permission to read the URI.                        |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Indicates the permission to write the URI.                        |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Returns the result to the ability.                              |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Indicates whether the ability on the local device can be migrated to a remote device.                 |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Indicates that a component does not belong to OHOS.                           |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Indicates whether to enable an ability.                             |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Indicates the permission to make the URI persistent.                         |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Indicates the permission to verify URIs by prefix matching.                       |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Supports cross-device startup in a distributed scheduler.                       |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the Service ability is started regardless of whether the host application has been started.          |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that the migration is reversible.                              |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.                      |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.                      |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for the **Want** object in the **startAbility** API passed to [ohos.app.Context](js-apis-ability-context.md) and must be used together with **flag_ABILITY_NEW_MISSION**.|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Creates a mission on the historical mission stack.                      |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Starts the mission on the top of the existing mission stack; creates an ability instance if no mission exists.|
