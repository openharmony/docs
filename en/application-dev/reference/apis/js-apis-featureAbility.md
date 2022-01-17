# FeatureAbility Module (JavaScript)

#### Applicable Devices

| API                                                          | Phone| Tablet| Smart TV| Wearable| Lite Wearable| SmartVision Device|
| ------------------------------------------------------------ | ---- | ---- | ------ | -------- | -------------- | ------------ |
| FeatureAbility.startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.startAbility(parameter: StartAbilityParameter): Promise\<number> | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.acquireDataAbilityHelper(uri: string): DataAbilityHelper | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult> | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.terminateSelfWithResult(parameter: AbilityResult): Promise\<void> | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.hasWindowFocus(callback: AsyncCallback\<boolean>): void | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.hasWindowFocus(): Promise\<boolean>           | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.getWant(callback: AsyncCallback\<Want>)       | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.getWant(): void                               | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.getContext(): Context                         | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.terminateSelf(callback: AsyncCallback\<void>): void | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.terminateSelf(): Promise\<void>               | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.connectAbility(request: Want, options:ConnectOptions): number | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.disconnectAbility(connection: number, callback:AsyncCallback\<void>): void | Yes| Yes| Yes| Yes| No| No|
| FeatureAbility.disconnectAbility(connection: number): Promise\<void> | Yes| Yes| Yes| Yes| No| No|

#### Constraints

APIs of the **FeatureAbility** module can be called only by Page abilities.

#### Modules to Import

```
import featureAbility from '@ohos.ability.featureAbility'
```

#### FeatureAbility.startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

* Functionality

  Starts an ability. This method uses a callback to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | --------------------- | ---- | ------------------- |
| parameter | Read-only| [StartAbilityParameter](#StartAbilityParameter)| Yes| Ability to start.|
| callback  | Read-only| AsyncCallback\<number>         | Yes| Callback used to return the result.|


- Example

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.startAbility(
        {
        want:
        {
            action: "",
            entities: [""],
            type: "",
            flags: FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    },
  );
)
```



#### FeatureAbility.startAbility(parameter: StartAbilityParameter): Promise\<number>

* Functionality

  Starts an ability. This method uses a promise to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | ------------------------------------------------------- | ---- | ------------------- |
| parameter | Read-only| [StartAbilityParameter](#StartAbilityParameter)| Yes| Ability to start.|


- Example

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.startAbility(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
			flags: FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: deviceId,
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    }
   ).then((void) => {
	console.info("==========================>startAbility=======================>");
});
```



#### FeatureAbility.acquireDataAbilityHelper(uri: string): DataAbilityHelper

* Functionality

  Obtains a **dataAbilityHelper**.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---- | -------- | ------ | ---- | ---------------------- |
| uri  | Read-only| string | Yes| URI of the file to open.|

* Return values

| Type| Description|
| ----------------- | ------------------------------------------ |
| DataAbilityHelper | A utility class used to help other abilities access the Data ability.|

* Example

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.acquireDataAbilityHelper(
    "dataability:///com.exmaple.DataAbility"
)
```



#### FeatureAbility.startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

* Functionality

  Starts an ability. This method uses a callback to return the execution result when the ability is destroyed.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | ---------------------- | ---- | ------------------- |
| parameter | Read-only| [StartAbilityParameter](#StartAbilityParameter)| Yes| Ability to start.|
| callback  | Read-only| AsyncCallback\<[AbilityResult](#AbilityResult)>| Yes| Callback used to return the result.|

* Return values

  Returns [AbilityResult](#AbilityResult).

* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.startAbilityForResult(
   {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:""
        },
    },
)
```



#### FeatureAbility.startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

* Functionality

  Starts an ability. This method uses a promise to return the execution result when the ability is destroyed.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | ------------------------------------------------------- | ---- | ------------------- |
| parameter | Read-only| [StartAbilityParameter](#StartAbilityParameter)| Yes| Ability to start.|

* Return values

  Returns [AbilityResult](#AbilityResult).

* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.startAbilityForResult(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION,
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
).then((void) => {
    console.info("==========================>startAbilityForResult=======================>");
});
```



#### FeatureAbility.terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

* Functionality

  Destroys this Page ability, with the result code and data sent to the caller. This method uses a callback to return the result.


* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | ------------- | ---- | ------------------- |
| parameter | Read-only| [AbilityResult](#AbilityResult)| Yes| Ability to start.|
| callback  | Read-only| AsyncCallback\<void> | Yes| Callback used to return the result.|


* Example

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION,
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



#### FeatureAbility.terminateSelfWithResult(parameter: AbilityResult): Promise\<void>

* Functionality

  Destroys this Page ability, with the result code and data sent to the caller. This method uses a promise to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | --------------------------------------- | ---- | ------------------- |
| parameter | Read-only| [AbilityResult](#AbilityResult)| Yes| Ability to start.|


* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION,
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
).then((void) => {
    console.info("==========================>terminateSelfWithResult=======================>");
});
```



#### FeatureAbility.hasWindowFocus(callback: AsyncCallback\<boolean>): void

* Functionality

  Checks whether the main window of this ability has the focus. This method uses a callback to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ----------------------- | ---- | ---------------- |
| callback | Read-only| AsyncCallback\<boolean> | Yes| Callback used to return the result.|

* Return values

  Returns **true** if the main window of this ability has the focus; returns **false** otherwise.

* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus()
```



#### FeatureAbility.hasWindowFocus(): Promise\<boolean>

* Functionality

  Checks whether the main window of this ability has the focus. This method uses a promise to return the result.

* Parameters

  None

* Return values

  Returns **true** if the main window of this ability has the focus; returns **false** otherwise.

* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus().then((void) => {
    console.info("==========================>hasWindowFocus=======================>");
});
```



#### FeatureAbility.getWant(callback: AsyncCallback\<Want>)

* Functionality

  Obtains the **Want** object sent from this ability. This method uses a callback to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | -------------------- | ---- | ---------------- |
| callback | Read-only| AsyncCallback\<Want> | Yes| Callback used to return the result.|


* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant()
```



#### FeatureAbility.getWant(): void

* Functionality

  Obtains the **Want** object sent from this ability. This method uses a promise to return the result.

* Parameters

  None

* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant().then((void) => {
		console.info("==========================>getWantCallBack=======================>");
});
```



#### FeatureAbility.getContext(): Context

* Functionality

  Obtains the application context.

* Return values

  Returns the application context.

* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
var context = featureAbility.getContext()
context.getBundleName()
```



#### FeatureAbility.terminateSelf(callback: AsyncCallback\<void>): void

* Functionality

  Destroys this Page ability, with the result code and data sent to the caller. This method uses a callback to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | -------------------- | ---- | ---------------- |
| callback | Read-only| AsyncCallback\<void> | Yes| Callback used to return the result.|

* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf()
```



#### FeatureAbility.terminateSelf(): Promise\<void>

* Functionality

  Destroys this Page ability, with the result code and data sent to the caller. This method uses a promise to return the result.

* Parameters

  None

* Example

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf().then((void) => {		    console.info("==========================>terminateSelfCallBack=======================>");
});
```

#### FeatureAbility.connectAbility(request: Want, options:ConnectOptions): number

* Functionality

  Connects this ability to a specific Service ability. This method uses a callback to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------- | -------- | -------------- | ---- | -------------------------- |
| request | Read-only| Want           | Yes| Service ability to connect.|
| options | Read-only| ConnectOptions | Yes| Callback used to return the result.|

* Want parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------ | -------- | -------- | ---- | ----------------------------------                               |
| deviceId     | Read-only| string   | No| Device ID of the Service ability to connect. The default value is the local device ID.|
| bundleName   | Read-only| string   | Yes| Bundle name of the Service ability to connect.|
| abilityName  | Read-only| string   | Yes| Class name of the Service ability to connect.|

- ConnectOptions

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------ | -------- | -------- | ---- | ---------------------------------- |
| onConnect    | Read-only| function | Yes| Callback invoked when the connection is successful.|
| onDisconnect | Read-only| function | Yes| Callback invoked when the connection fails.|
| onFailed     | Read-only| function | Yes| Callback invoked when **connectAbility** fails to be called.|

* Return values

  Returns the ID of the Service ability connected.

* Example

```javascript
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
        deviceId: deviceId,
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

#### FeatureAbility.disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

* Functionality

  Disconnects this ability from a specific Service ability. This method uses a callback to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------------- | ---- | ------------------------------ |
| connection | Read-only| number        | Yes| ID of the Service ability to disconnect.|
| callback   | Read-only| AsyncCallback\<void> | Yes| Callback used to return the result.|

* Example

```javascript
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

#### FeatureAbility.disconnectAbility(connection: number): Promise\<void>

* Functionality

  Disconnects this ability from a specific Service ability. This method uses a promise to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------ | ---- | ------------------------------ |
| connection | Read-only| number | Yes| ID of the Service ability to disconnect.|

* Example

```javascript
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


#### FeatureAbility.continueAbility(options: ContinueAbilityOptions, callback: AsyncCallback\<void>): void;

* Functionality

  Migrates an ability to another device. This method uses a callback to return the execution result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ---------------------- | ---- | ------------------- |
| options  | Read-only| ContinueAbilityOptions | Yes| Ability to migrate.|
| callback | Read-only| AsyncCallback\<void>   | Yes| Callback used to return the result.|

- ContinueAbilityOptions

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------- | ---- | ----------------------------------------------------------- |
| deviceId   | Read-only| string  | Yes| Information about the ability to migrate.|
| reversible | Read-only| boolean | Yes| Whether migration back is supported. Currently, this feature is not supported. This parameter is reserved and can be set to **false**.|

* Example

```javascript
import featureAbility from '@ohos.ability.featureAbility'

async StartContinueAbility(deviceId) {
    let continueAbilityOptions = {
        reversible: false,
        deviceId: deviceId,
    }
    function ContinueAbilityCallback(err, data) {
        console.info("[Demo] ContinueAbilityCallback, result err = " + JSON.stringify(err));
        console.info("[Demo] ContinueAbilityCallback, result data= " + JSON.stringify(data));
    }
    await featureAbility.continueAbility(continueAbilityOptions, ContinueAbilityCallback);
    console.info('[Demo] featureAbility.StartContinueAbility end');
}
this.StartContinueAbility(remoteDeviceId); //remoteDeviceId is acquired from DeviceManager
```

#### AbilityResult

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | --------------------- | ---- | ------------------------------------------------------------ |
| resultCode | Read-only| number                | Yes| Result code returned after the ability is destroyed. The feature for defining error-specific result codes is coming soon.|
| want       | Read-only| [Want](#Want)| No| Data returned after the ability is destroyed. You can define the data to be returned. This parameter can be **null**.|

#### StartAbilityParameter

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------------- | -------- | --------------------- | ---- | ------------------------------------------------------------ |
| want                | Read-only| [Want](#Want)| Yes| Information about the ability to start.|
| abilityStartSetting | Read-only| {[key: string]: any}  | No| Special attribute of the ability to start. This attribute can be passed in the method call.|

#### Want

| Name| Readable/Writable| Type| Mandatory| Description|
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | Read-only| string               | No| ID of the device that runs the ability.|
| bundleName  | Read-only| string               | No| Bundle name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.|
| abilityName | Read-only| string               | No| Name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.|
| uri         | Read-only| string               | No| URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type        | Read-only| string               | No| MIME type, for example, text/plain or image/*.|
| flags       | Read-only| number               | No| How the **Want** object will be handled. By default, a number is passed. For details, see [flags](#flags).|
| action      | Read-only| string               | No| Action option.|
| parameters  | Read-only| {[key: string]: any} | No| List of parameters in a **Want** object.|
| entities    | Read-only| Array\<string>       | No| List of entities.|

## flags

| Name| Name| Description|
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Permission to read the URI.|
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Permission to write the URI.|
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Whether to return the result to the ability.|
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Whether abilities on the local device can be migrated to a remote device.|
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Whether a component belongs to OHOS.|
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Whether to enable an ability.|
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Permission to make the URI persist.|
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Permission to authenticate prefix URI.|
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Support for the startup across multiple devices in a distributed scheduler.|
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Functionality of using the Service template is enabled regardless of whether the host application is started.|
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Whether the migration is reversible.|
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | A demand for the installation of a specific function.|
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | A demand for the installation of a specific function in background mode.|
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | An instruction for clearing other tasks. This flag can be set for the **Want** object passed to **ohos.app.Context#startAbility** and must be used together with **flag_ABILITY_NEW_MISSION**.|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | An instruction for creating a task on the history task stack.|
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | An existing instance of the ability to start will be reused if it is already at the top of the task stack. Otherwise, a new ability instance is created.|
