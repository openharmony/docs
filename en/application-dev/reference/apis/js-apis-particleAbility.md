# ParticleAbility Module

## Applicable Devices

| API                                                          | Phone| Tablet| Smart TV| Wearable| Lite Wearable| SmartVision Device|
| ------------------------------------------------------------ | ---- | ---- | ------ | -------- | -------------- | ------------ |
| particleAbility.startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>: void | Yes| Yes| Yes| Yes| No| No|
| particleAbility.startAbility(parameter: StartAbilityParameter): Promise\<number> | Yes| Yes| Yes| Yes| No| No|
| particleAbility.terminateSelf(callback: AsyncCallback\<void>): void | Yes| Yes| Yes| Yes| No| No|
| particleAbility.terminateSelf(): Promise\<void>              | Yes| Yes| Yes| Yes| No| No|
| particleAbility.acquireDataAbilityHelper(uri: string): DataAbilityHelper | Yes| Yes| Yes| Yes| No| No|
| particleAbility.connectAbility(request: Want, options:ConnectOptions): number | Yes| Yes| Yes| Yes| No| No|
| particleAbility.disconnectAbility(connection: number, callback:AsyncCallback\<void>): void | Yes| Yes| Yes| Yes| No| No|
| particleAbility.disconnectAbility(connection: number): Promise\<void> | Yes| Yes| Yes| Yes| No| No|

## Constraints

The ParticleAbility module is used to perform operations on abilities of the Data and Service types.

## Modules to Import

```js
import particleAbility from '@ohos.ability.particleAbility'
```

## particleAbility.startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>: void

- Functionality

  Starts a Service ability. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | ------------------------------------------------------- | ---- | ----------------- |
| parameter | Read-only| [StartAbilityParameter](#StartAbilityParameter)| Yes| Ability to start.|
| callback  | Read-only| AsyncCallback\<void>                                    | Yes| Callback used to return the result.|

- Return values

  void

- Example

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.startAbility(
	{
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION;
            deviceId: "",
            bundleName: "com.example.Data",
            abilityName: "com.example.Data.MainAbility",
            uri:""
        },
    },
    (error, result) => {
		console.log('particleAbility startAbility errCode:' + error + 'result:' + result)
    },
)
```



## particleAbility.startAbility(parameter: StartAbilityParameter): Promise\<number>

- Functionality
Starts a Service ability. This method uses a promise to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | ------------------------------------------------------- | ---- | ----------------- |
| parameter | Read-only| [StartAbilityParameter](#StartAbilityParameter)| Yes| Ability to start.|
- Return values

  Promise\<void>

- Example

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.startAbility(
	{
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION;
            deviceId: "",
            bundleName: "com.example.Data",
            abilityName: "com.example.Data.MainAbility",
            uri:""
        },
    },
).then((void) => {
    console.info("particleAbility startAbility");
});
```



## particleAbility.terminateSelf(callback: AsyncCallback\<void>): void

- Functionality

  Terminates this Service ability. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | -------------------- | ---- | -------------------- |
| callback | Read-only| AsyncCallback\<void> | Yes| Callback used to return the result.|

- Return values

  void

- Example

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.terminateSelf(
    (error, result) => {
		console.log('particleAbility terminateSelf errCode:' + error + 'result:' + result)
    }
)
```



## particleAbility.terminateSelf(): Promise\<void>

- Functionality

  Terminates this Service ability. This method uses a promise to return the result.

- Return values

  Promise\<void>

- Example

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.terminateSelf().then((void) => {
	console.info("particleAbility terminateSelf");
});
```



## particleAbility.acquireDataAbilityHelper(uri: string): DataAbilityHelper

- Functionality

  Obtains a **dataAbilityHelper** object.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| :--- | -------- | ------ | ---- | ---------------------- |
| uri  | Read-only| string | Yes| URI of the file to open.|

- Return values

| Type| Description|
| ----------------- | ------------------------------------------ |
| DataAbilityHelper | A utility class used to help other abilities access a Data ability.|

- Example

```js
import particleAbility from '@ohos.ability.particleAbility'     
var uri = "";
particleAbility.acquireDataAbilityHelper(uri)
```

## particleAbility.connectAbility(request: Want, options:ConnectOptions): number

* Functionality

  Connects this ability to a specific Service ability. This method uses a callback to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------- | -------- | -------------- | ---- | -------------------------- |
| request | Read-only| Want           | Yes| Service ability to connect.|
| options | Read-only| ConnectOptions | Yes| Callback used to return the result.|

- ConnectOptions

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------ | -------- | -------- | ---- | ---------------------------------- |
| onConnect    | Read-only| function | Yes| Callback invoked when the connection is set up.|
| onDisconnect | Read-only| function | Yes| Callback invoked when the connection is interrupted.|
| onFailed     | Read-only| function | Yes| Callback invoked when the connection fails.|

* Return values

  Returns the unique identifier of the connection.

* Example

```javascript
import particleAbility from '@ohos.ability.particleAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('particleAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = particleAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "com.ix.ServiceAbility.ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

## particleAbility.disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

* Functionality

  Disconnects this ability from a specific Service ability. This method uses a callback to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------------- | ---- | ------------------------------ |
| connection | Read-only| number        | Yes| ID of the Service ability to disconnect.|
| callback   | Read-only| AsyncCallback\<void> | Yes| Callback used to return the result.|

* Return values

  void

* Example

```javascript
import particleAbility from '@ohos.ability.particleAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('particleAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = particleAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "com.ix.ServiceAbility.ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = particleAbility.disconnectAbility(connId,
    (error,data) => {
        console.log('particleAbilityTest DisConnectAbility result errCode : ' + error.code + " data: " + data)
    },
);
```

## particleAbility.disconnectAbility(connection: number): Promise\<void>

* Functionality

  Disconnects this ability from a specific Service ability. This method uses a promise to return the result.

* Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------ | ---- | ------------------------------ |
| connection | Read-only| number | Yes| ID of the Service ability to disconnect.|

* Return values

  Promise\<void>

* Example

```javascript
import particleAbility from '@ohos.ability.particleAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('particleAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = particleAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "com.ix.ServiceAbility.ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = particleAbility.disconnectAbility(connId).then((void) => {
	console.info("particleAbilityTest disconnectAbility");
});
```

## StartAbilityParameter

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------------- | -------- | --------------------- | ---- | ------------------------------------------------------------ |
| want                | Read-only| [Want](#Want)| Yes| Information about the ability to start.|
| abilityStartSetting | Read-only| {[key: string]: any}  | No| Special attribute of the ability to start. This attribute can be passed in the method call.|

## Want

| Name| Readable/Writable| Type| Mandatory| Description|
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | Read-only| string               | No| ID of the device running the ability to start.|
| bundleName  | Read-only| string               | No| Bundle name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.|
| abilityName | Read-only| string               | No| Name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.|
| uri         | Read-only| string               | No| URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type        | Read-only| string               | No| MIME type, for example, **text/plain** or **image/***.|
| flags       | Read-only| number               | No| How the **Want** object will be handled. By default, numbers are passed in. For details, see [flags](#flags).|
| action      | Read-only| string               | No| Action option.|
| parameters  | Read-only| {[key: string]: any} | No| List of parameters in the **Want** object.|
| entities    | Read-only| Array\<string>       | No| List of entities.|

## flags

| Name| Value| Description|
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Indicates the permission to read the URI.|
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Indicates the permission to write the URI.|
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Returns the result to the ability.|
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Indicates whether the ability on the local device can be migrated to a remote device.|
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Indicates that a component does not belong to OHOS.|
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Indicates whether to enable an ability.|
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Indicates the permission to make the URI persistent.|
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Indicates the permission to verify URIs by prefix matching.|
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Supports cross-device startup in a distributed scheduler.|
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the Service ability is started regardless of whether the host application has been started.|
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that the migration is reversible.|
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.|
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.|
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for the **Want** object passed to **ohos.app.Context#startAbility** and must be used together with **flag_ABILITY_NEW_MISSION**.|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Creates a mission on the historical mission stack.|
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Starts the mission on the top of the existing mission stack; creates an ability instance if no mission exists.|

## AbilityStartSetting

Defines special attributes of an ability, for example, **featureAbility.AbilityStartSetting.BOUNDS_KEY**.

The **AbilityStartSetting** attribute is an object defined as [key: string]: any. The key is a type of **AbilityStartSetting**, and the value is a type of **AbilityWindowConfiguration**.

| Name| Value| Description|
| --------------- | --------------- | -------------------------- |
| BOUNDS_KEY      | "abilityBounds" | Ability window size.|
| WINDOW_MODE_KEY | "windowMode"    | Ability window display mode.|
| DISPLAY_ID_KEY  | "displayId"     | Display device ID.|

## AbilityWindowConfiguration

Defines the window display modes of a Page ability, for example, **featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED**.

| Name| Value| Description|
| --------------------------- | ---- | ---------- |
| WINDOW_MODE_UNDEFINED       | 0    | The Page ability is in an undefined window display mode.|
| WINDOW_MODE_FULLSCREEN      | 1    | The Page ability is in full screen mode.|
| WINDOW_MODE_SPLIT_PRIMARY   | 100  | The Page ability is displayed in the primary window when it is in split-screen mode.|
| WINDOW_MODE_SPLIT_SECONDARY | 101  | The Page ability is displayed in the secondary window when it is in split-screen mode.|
| WINDOW_MODE_FLOATING        | 102  | The Page ability is displayed in floating window mode.|
