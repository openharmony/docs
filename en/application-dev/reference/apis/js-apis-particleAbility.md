# ParticleAbility Module

## Constraints

The ParticleAbility module is used to perform operations on abilities of the Data and Service types.

## Modules to Import

```js
import particleAbility from '@ohos.ability.particleAbility'
```

## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>: void

Starts a particle ability. This method uses a callback to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**


| Name     | Type                                           | Mandatory| Description             |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes  | Ability to start.|
| callback  | AsyncCallback\<void>                            | Yes  | Callback used to return the result. |

**Example**

```js
import particleAbility from '@ohos.ability.particleAbility'
import wantConstant from '@ohos.ability.wantConstant'
particleAbility.startAbility(
	{
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
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



## particleAbility.startAbility

**System capabilities**

SystemCapability.Ability.AbilityRuntime.FAModel

startAbility(parameter: StartAbilityParameter): Promise\<number>
Starts a particle ability. This method uses a promise to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**


| Name     | Type                                           | Mandatory| Description             |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | Yes  | Ability to start.|
**Return value**
| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
import particleAbility from '@ohos.ability.particleAbility'
import wantConstant from '@ohos.ability.wantConstant'
particleAbility.startAbility(
	{
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.Data",
            abilityName: "com.example. Data.MainAbility",
            uri:""
        },
    },
).then((data) => {
    console.info("particleAbility startAbility");
});
```



## particleAbility.terminateSelf

terminateSelf(callback: AsyncCallback\<void>): void

Terminates this particle ability. This method uses a callback to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.terminateSelf(
    (error, result) => {
		console.log('particleAbility terminateSelf errCode:' + error + 'result:' + result)
    }
)
```



## particleAbility.terminateSelf

terminateSelf(): Promise\<void>

Terminates this particle ability. This method uses a promise to return the result.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**
| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.terminateSelf().then((data) => {
	console.info("particleAbility terminateSelf");
});
```



## particleAbility.acquireDataAbilityHelper

acquireDataAbilityHelper(uri: string): DataAbilityHelper

Obtains a **dataAbilityHelper** object.

**System capabilities**

SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name| Type  | Mandatory| Description                    |
| :--- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the file to open.|

**Return value**

| Type             | Description                                        |
| ----------------- | -------------------------------------------- |
| DataAbilityHelper | A utility class used to help other abilities access a Data ability.|

**Example**

```js
import particleAbility from '@ohos.ability.particleAbility'     
var uri = "";
particleAbility.acquireDataAbilityHelper(uri)
```

## StartAbilityParameter

| Name               | Readable/Writable| Type                 | Mandatory| Description                                                        |
| ------------------- | -------- | --------------------- | ---- | ------------------------------------------------------------ |
| want                | Read-only    | [Want](#want) | Yes  | Information about the ability to start.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel                         |
| abilityStartSetting | Read-only    | {[key: string]: any}  | No  | Special attribute of the ability to start. This attribute can be passed in the method call.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel|

## Want

| Name       | Readable/Writable| Type                | Mandatory| Description                                                        |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | Read-only    | string               | No  | ID of the device running the ability to start.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                               |
| bundleName  | Read-only    | string               | No  | Bundle name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase|
| abilityName | Read-only    | string               | No  | Name of the ability to start. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can directly match the specified ability.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase|
| uri         | Read-only    | string               | No  | URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase|
| type        | Read-only    | string               | No  | MIME type, for example, **text/plain** or **image/***.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase  |
| flags       | Read-only    | number               | No  | How the **Want** object will be handled. By default, numbers are passed in. For details, see [flags](#flags).<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase|
| action      | Read-only    | string               | No  | Action option.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                        |
| parameters  | Read-only    | {[key: string]: any} | No  | List of parameters in the **Want** object.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                        |
| entities    | Read-only    | Array\<string>       | No  | List of entities.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                      |

## flags

| Name                                | Value      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Indicates the permission to read the URI.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                 |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Indicates the permission to write the URI.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                 |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Returns the result to the ability.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                          |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Indicates whether the ability on the local device can be migrated to a remote device.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Indicates that a component does not belong to OHOS.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                        |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Indicates whether to enable an ability.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                        |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Indicates the permission to make the URI persistent.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                   |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Indicates the permission to verify URIs by prefix matching.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                        |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Supports cross-device startup in a distributed scheduler.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                            |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the Service ability is started regardless of whether the host application has been started.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase  |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that the migration is reversible.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                                        |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                         |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for the **Want** object passed to **ohos.app.Context#startAbility** and must be used together with **flag_ABILITY_NEW_MISSION**.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Creates a mission on the historical mission stack.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase                        |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Starts the mission on the top of the existing mission stack; creates an ability instance if no mission exists.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityBase|

## AbilityStartSetting

The **AbilityStartSetting** attribute is an object defined as [key: string]: any. The key is a type of **AbilityStartSetting**, and the value is a type of **AbilityWindowConfiguration**.

Defines special attributes of an ability, for example, **featureAbility.AbilityStartSetting.BOUNDS_KEY**.

| Name           | Value           | Description                      |
| --------------- | --------------- | -------------------------- |
| BOUNDS_KEY      | "abilityBounds" | Ability window size.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel  |
| WINDOW_MODE_KEY | "windowMode"    | Ability window display mode.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel  |
| DISPLAY_ID_KEY  | "displayId"     | Display device ID.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel|

## AbilityWindowConfiguration

Defines the window display modes of a Page ability, for example, **featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED**.

| Name                       | Value| Description      |
| --------------------------- | ---- | ---------- |
| WINDOW_MODE_UNDEFINED       | 0    | The Page ability is in an undefined window display mode.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel  |
| WINDOW_MODE_FULLSCREEN      | 1    | The Page ability is in full screen mode.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel    |
| WINDOW_MODE_SPLIT_PRIMARY   | 100  | The Page ability is displayed in the primary window when it is in split-screen mode.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel|
| WINDOW_MODE_SPLIT_SECONDARY | 101  | The Page ability is displayed in the secondary window when it is in split-screen mode.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel|
| WINDOW_MODE_FLOATING        | 102  | The Page ability is displayed in floating window mode.<br><b>System capabilities:</b> SystemCapability.Ability.AbilityRuntime.FAModel  |


## particleAbility.startBackgroundRunning

startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback&lt;void&gt;): void;

Requests a continuous task from the system. This method uses an asynchronous callback to return the result. (This method is of API 7 and will be deprecated. Use the counterpart in API 8.)

**System capabilities**

SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | id | number | Yes| Notification ID of a continuous task.|
  | request | NotificationRequest | Yes| Notification parameter, which is used to display information in the notification bar.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

- **Example**
```js
import notification from '@ohos.notification';
import particleAbility from '@ohos.ability.particleAbility';
import wantAgent from '@ohos.wantAgent';

function callback(err, data) {
    if (err) {
        console.error("Operation failed Cause: " + err);
    } else {
        console.info("Operation succeeded");
    }
}

let wantAgentInfo = {
    wants: [
        {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESET_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let basicContent = {
        title: "title",
        text: "text"
    };
    let notificationContent = {
        contentType: notification.ContentType.NOTIFICATION_CONTENT_TEXT,
        normal: basicContent
    };
    let request = {
        content: notificatonContent,
        wantAgent: wantAgentObj
    };
    let id = 1;
    particleAbility.startBackgroundRunning(id, request, callback);
});

```

## particleAbility.startBackgroundRunning

startBackgroundRunning(id: number, request: NotificationRequest): Promise&lt;void&gt;

**System capabilities**

SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

Requests a continuous task from the system. This method uses a promise to return the result. (This method is of API 7 and will be deprecated. Use the counterpart in API 8.)

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id | number | Yes| Notification ID of a continuous task.|
| request | NotificationRequest | Yes| Notification parameter, which is used to display information in the notification bar.|

**Return value**
| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

- **Example**
```js
import notification from '@ohos.notification';
import particleAbility from '@ohos.ability.particleAbility';
import wantAgent from '@ohos.wantAgent';

let wantAgentInfo = {
    wants: [
        {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESET_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let basicContent = {
        title: "title",
        text: "text"
    };
    let notificationContent = {
        contentType: notification.ContentType.NOTIFICATION_CONTENT_TEXT,
        normal: basicContent
    };
    let request = {
        content: notificatonContent,
        wantAgent: wantAgentObj
    };
    let id = 1;
    particleAbility.startBackgroundRunning(id, request).then(() => {
        console.info("Operation succeeded");
    }).catch((err) => {
        console.error("Operation failed Cause: " + err);
    });
});

```

## particleAbility.cancelBackgroundRunning

cancelBackgroundRunning(callback: AsyncCallback&lt;void&gt;): void;

Requests to cancel a continuous task from the system. This method uses an asynchronous callback to return the result. (This method is of API 7 and will be deprecated. Use the counterpart in API 8.)

**System capabilities**

SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

- **Example**
```js
import particleAbility from '@ohos.ability.particleAbility';

function callback(err, data) {
    if (err) {
        console.error("Operation failed Cause: " + err);
    } else {
        console.info("Operation succeeded");
    }
}

particleAbility.cancelBackgroundRunning(callback);

```

## particleAbility.cancelBackgroundRunning

cancelBackgroundRunning(): Promise&lt;void&gt;;

Requests to cancel a continuous task from the system. This method uses a promise to return the result. (This method is of API 7 and will be deprecated. Use the counterpart in API 8.)

**System capabilities**

SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Return value**
| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

- **Example**
```js
import particleAbility from '@ohos.ability.particleAbility';

particleAbility.cancelBackgroundRunning().then(() => {
    console.info("Operation succeeded");
}).catch((err) => {
    console.error("Operation failed Cause: " + err);
});

```
