# @ohos.ability.featureAbility

The **FeatureAbility** module provides a UI for interacting with users. You can use APIs of this module to start a new ability, obtain the **dataAbilityHelper**, set a Page ability, obtain the window corresponding to this ability, and connect to a Service ability.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the FA model.

## Constraints

APIs of the **FeatureAbility** module can be called only by Page abilities.

## Modules to Import

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|
| callback  | AsyncCallback\<number>                   | Yes   | Callback used to return the result.     |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.startAbility(
    {
        want:
        {
            action: "",
            entities: [""],
            type: "",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* In the FA model, abilityName consists of package and ability names. */
            abilityName: "com.example.entry.secondAbility",
            uri: ""
        },
    },
    (err, data) => {
        console.info("startAbility err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
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
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.startAbility(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* In the FA model, abilityName consists of package and ability names. */
            abilityName: "com.example.entry.secondAbility",
            uri: ""
        },
    }
).then((data) => {
    console.info("startAbility data: " + JSON.stringify(data));
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

```ts
import featureAbility from '@ohos.ability.featureAbility';
var dataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

Starts an ability. This API uses an asynchronous callback to return the execution result when the ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|
| callback  | AsyncCallback\<[AbilityResult](js-apis-inner-ability-abilityResult.md)> | Yes   | Callback used to return the result.     |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.startAbilityForResult(
   {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* In the FA model, abilityName consists of package and ability names. */
            abilityName: "com.example.entry.secondAbility",
            uri:""
        },
    },
    (err, data) => {
        console.info("startAbilityForResult err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
    }
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

Starts an ability. This API uses a promise to return the execution result when the ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description           |
| --------- | ---------------------------------------- | ---- | ------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<[AbilityResult](js-apis-inner-ability-abilityResult.md)> | Promised returned with the execution result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.startAbilityForResult(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* In the FA model, abilityName consists of package and ability names. */
            abilityName: "com.example.entry.secondAbility",
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
    },
).then((data) => {
    console.info("startAbilityForResult data: " + JSON.stringify(data));
});
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

Destroys this Page ability, with the result code and data sent to the caller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                             | Mandatory  | Description            |
| --------- | ------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes   | Ability to start.|
| callback  | AsyncCallback\<void>            | Yes   | Callback used to return the result.     |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
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
            bundleName: "com.example.myapplication",
            /* In the FA model, abilityName consists of package and ability names. */
            abilityName: "com.example.entry.secondAbility",
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
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes   | Ability to start.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
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
            bundleName: "com.example.myapplication",
            /* In the FA model, abilityName consists of package and ability names. */
            abilityName: "com.example.entry.secondAbility",
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

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus((err, data) => {
    console.info("hasWindowFocus err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
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

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus().then((data) => {
    console.info("hasWindowFocus data: " + JSON.stringify(data));
});
```

## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

Obtains the **Want** object sent from this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                           | Mandatory  | Description       |
| -------- | ----------------------------- | ---- | --------- |
| callback | AsyncCallback\<[Want](js-apis-application-want.md)> | Yes   | Callback used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant((err, data) => {
    console.info("getWant err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## featureAbility.getWant

getWant(): Promise\<Want>

Obtains the **Want** object sent from this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type                     | Description              |
| ----------------------- | ---------------- |
| Promise\<[Want](js-apis-application-want.md)> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant().then((data) => {
    console.info("getWant data: " + JSON.stringify(data));
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

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext()
context.getBundleName((err, data) => {
    console.info("getBundleName err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
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

```ts
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

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf().then((data) => {
    console.info("==========================>terminateSelf=======================>");
});
```

## featureAbility.connectAbility<sup>7+</sup>

connectAbility(request: Want, options:ConnectOptions): number

Connects this ability to a specific Service ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name     | Type            | Mandatory  | Description                   |
| ------- | -------------- | ---- | --------------------- |
| request | [Want](js-apis-application-want.md)  | Yes   | Service ability to connect.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes   | Callback used to return the result.            |

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | ID of the Service ability connected.|

**Example**

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connectId = featureAbility.connectAbility(
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

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connectId = featureAbility.connectAbility(
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
var result = featureAbility.disconnectAbility(connectId,
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

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connectId = featureAbility.connectAbility(
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

featureAbility.disconnectAbility(connectId).then((data) => {
    console.log('data : '  + data);
}).catch((error)=>{
    console.log('featureAbilityTest result errCode : ' + error.code);
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

```ts
featureAbility.getWindow((err, data) => {
    console.info("getWindow err: " + JSON.stringify(err) + "data: " + typeof(data));
});
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

```ts
featureAbility.getWindow().then((data) => {
    console.info("getWindow data: " + typeof(data));
});
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
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Indicates the permission to make the URI persistent.<br>**System API**: This is a system API and cannot be called by third-party applications.                         |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Indicates the permission to verify URIs by prefix matching.<br>**System API**: This is a system API and cannot be called by third-party applications.                       |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Supports cross-device startup in a distributed scheduler.                       |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the Service ability is started regardless of whether the host application has been started.<br>**System API**: This is a system API and cannot be called by third-party applications.          |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that the migration is reversible.                              |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.                      |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.                      |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for the **Want** object in the **startAbility** API passed to [ohos.app.Context](js-apis-ability-context.md) and must be used together with **flag_ABILITY_NEW_MISSION**.|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Creates a mission on the historical mission stack.                      |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Starts the mission on the top of the existing mission stack; creates an ability instance if no mission exists.|
