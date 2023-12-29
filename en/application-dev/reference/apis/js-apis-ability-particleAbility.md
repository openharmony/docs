# @ohos.ability.particleAbility (ParticleAbility)

The **particleAbility** module provides APIs for operating a DataAbility and ServiceAbility. You can use the APIs to start and terminate a ParticleAbility, obtain a **dataAbilityHelper** object, and connect to or disconnect from a ServiceAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs provided by this module can be used only in the FA model. In the stage model, use the APIs provided by [ServiceExtensionAbility](js-apis-app-ability-serviceExtensionAbility.md) and [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext.md) modules instead.

## Constraints

The ParticleAbility module is used to perform operations on abilities of the Data and Service types.

## Modules to Import

```ts
import particleAbility from '@ohos.ability.particleAbility';
```

## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>): void

Starts a ParticleAbility. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [ServiceExtensionContext.startAbility](js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextstartability) instead.

**Parameters**

| Name     | Type                                           | Mandatory| Description             |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes  | Ability to start.|
| callback  | AsyncCallback\<void>                            | Yes  | Callback used to return the result. |

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 1 | Get ability error. |
| 202 | Parameter is invalid. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';
import wantConstant from '@ohos.app.ability.wantConstant';

particleAbility.startAbility(
    {
        want:
        {
            action: 'ohos.want.action.home',
            entities: ['entity.system.home'],
            type: 'MIMETYPE',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.Data',
            abilityName: 'com.example.Data.EntryAbility',
            uri: ''
        },
    },
    (error, data) => {
        if (error && error.code !== 0) {
            console.error(`startAbility fail, error: ${JSON.stringify(error)}`);
        } else {
            console.log(`startAbility success, data: ${JSON.stringify(data)}`);
        }
    },
);
```

## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<void>

Starts a ParticleAbility. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [ServiceExtensionContext.startAbility](js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextstartability-1) instead.

**Parameters**

| Name     | Type                                           | Mandatory| Description             |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes  | Ability to start.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 1 | Get ability error. |
| 202 | Parameter is invalid. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';
import wantConstant from '@ohos.app.ability.wantConstant';

particleAbility.startAbility(
    {
        want:
        {
            action: 'ohos.want.action.home',
            entities: ['entity.system.home'],
            type: 'MIMETYPE',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.Data',
            abilityName: 'com.example.Data.EntryAbility',
            uri: ''
        },
    },
).then(() => {
    console.info('particleAbility startAbility');
});
```

## particleAbility.terminateSelf

terminateSelf(callback: AsyncCallback\<void>): void

Terminates this ParticleAbility. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [ServiceExtensionContext.terminateSelf](js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextterminateself) instead.

**Parameters**

| Name    | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).


**Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';

particleAbility.terminateSelf(
    (error) => {
        if (error && error.code !== 0) {
            console.error(`terminateSelf fail, error: ${JSON.stringify(error)}`);
        }
    }
);
```

## particleAbility.terminateSelf

terminateSelf(): Promise\<void>

Terminates this ParticleAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [ServiceExtensionContext.terminateSelf](js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextterminateself-1) instead.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).


**Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';

particleAbility.terminateSelf().then(() => {
	console.info('particleAbility terminateSelf');
});
```



## particleAbility.acquireDataAbilityHelper

acquireDataAbilityHelper(uri: string): DataAbilityHelper

Obtains a **dataAbilityHelper** object.

Observe the following when using this API:
 - To access a DataAbility of another application, the target application must be configured with associated startup (**AssociateWakeUp** set to **true**).
 - If an application running in the background needs to call this API to access a DataAbility, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission. (Applications developed using the SDK of API version 8 or earlier are not restricted by this restriction when accessing the DataAbility.)
 - If **visible** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [dataShare.createDataShareHelper](js-apis-data-dataShare.md#datasharecreatedatasharehelper) instead.

**Parameters**

| Name| Type  | Mandatory| Description                    |
| :--- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the file to open.|

**Return value**

| Type             | Description                                        |
| ----------------- | -------------------------------------------- |
| [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md) | A utility class used to help other abilities access a DataAbility.|

**Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';

let uri = '';
particleAbility.acquireDataAbilityHelper(uri);
```


## particleAbility.startBackgroundRunning<sup>(deprecated)</sup>

startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback&lt;void&gt;): void

Requests a continuous task from the system. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Note**: This API can be used only in the FA model. In the stage model, use [backgroundTaskManager.startBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning8) instead.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | id | number | Yes| Notification ID of a continuous task.|
  | request | [NotificationRequest](js-apis-notification.md#notificationrequest) | Yes| Notification parameter, which is used to display information in the notification bar.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |
| -104 | Parameter is invalid. |
| 201 | Permission denied. |
| 202 | System API verification failed. Only system application can apply. |
| 9800407 | The bgMode cannot be null and its type must be BackgroundMode object. |
| 980000401 | Manager is not ready. |
| 980000501 | Continuous task is already exist. |
| 980000503 | Continuous Task verification failed. TASK_KEEPING background mode only supported in particular device. |
| 980000504 | Continuous Task verification failed. The bgMode is invalid. |
| 980000601 | Notification verification failed. The title or text of the notification cannot be empty. |
| 980000603 | Continuous task param is null. |

 **Example**

```ts
import notification from '@ohos.notificationManager';
import particleAbility from '@ohos.ability.particleAbility';
import wantAgent from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

function callback(error: BusinessError, data: void) {
    if (error && error.code !== 0) {
        console.error(`Operation failed error: ${JSON.stringify(error)}`);
    } else {
        console.info(`Operation succeeded, data: ${data}`);
    }
}

let wantAgentInfo: wantAgent.WantAgentInfo = {
    wants: [
        {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility'
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let id = 1;
    particleAbility.startBackgroundRunning(id, {
        content:
        {
            contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
            normal:
            {
                title: 'title',
                text: 'text'
            }
        },
        wantAgent: wantAgentObj
    }, callback);
});

```

## particleAbility.startBackgroundRunning<sup>(deprecated)</sup>

startBackgroundRunning(id: number, request: NotificationRequest): Promise&lt;void&gt;

Requests a continuous task from the system. This API uses a promise to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Note**: This API can be used only in the FA model. In the stage model, use [backgroundTaskManager.startBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning8-1) instead.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id | number | Yes| Notification ID of a continuous task.|
| request | [NotificationRequest](js-apis-notification.md#notificationrequest) | Yes| Notification parameter, which is used to display information in the notification bar.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |
| -104 | Parameter is invalid. |
| 201 | Permission denied. |
| 202 | System API verification failed. Only system application can apply. |
| 9800407 | The bgMode cannot be null and its type must be BackgroundMode object. |
| 980000401 | Manager is not ready. |
| 980000501 | Continuous task is already exist. |
| 980000503 | Continuous Task verification failed. TASK_KEEPING background mode only supported in particular device. |
| 980000504 | Continuous Task verification failed. The bgMode is invalid. |
| 980000601 | Notification verification failed. The title or text of the notification cannot be empty. |
| 980000603 | Continuous task param is null. |

**Example**

```ts
import notification from '@ohos.notificationManager';
import particleAbility from '@ohos.ability.particleAbility';
import wantAgent from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

let wantAgentInfo: wantAgent.WantAgentInfo = {
    wants: [
        {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility'
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let id = 1;
    particleAbility.startBackgroundRunning(id, {
        content:
        {
            contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
            normal:
            {
                title: 'title',
                text: 'text'
            }
        },
        wantAgent: wantAgentObj
    }).then(() => {
        console.info('Operation succeeded');
    }).catch((err: BusinessError) => {
        console.error(`Operation failed cause: ${JSON.stringify(err)}`);
    });
});

```

## particleAbility.cancelBackgroundRunning<sup>(deprecated)</sup>

cancelBackgroundRunning(callback: AsyncCallback&lt;void&gt;): void

Requests to cancel a continuous task from the system. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Note**: This API can be used only in the FA model. In the stage model, use [backgroundTaskManager.stopBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning8) instead.

 **Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | The input param is invalid. |
| 980000401 | Manager is not ready. |
| 980000502 | Continuous Task verification failed. The application has applied for a continuous task. |
| 980000602 | Notification verification failed. Failed to send or cancel the notification. |
| 980000603 | Continuous task param is null. |


 **Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';
import { BusinessError } from '@ohos.base';

function callback(error: BusinessError, data: void) {
    if (error && error.code !== 0) {
        console.error(`Operation failed error: ${JSON.stringify(error)}`);
    } else {
        console.info(`Operation succeeded, data: ${data}`);
    }
}

particleAbility.cancelBackgroundRunning(callback);

```

## particleAbility.cancelBackgroundRunning<sup>(deprecated)</sup>

cancelBackgroundRunning(): Promise&lt;void&gt;

Requests to cancel a continuous task from the system. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Note**: This API can be used only in the FA model. In the stage model, use [backgroundTaskManager.stopBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning8-1) instead.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | The input param is invalid. |
| 980000401 | Manager is not ready. |
| 980000502 | Continuous Task verification failed. The application has applied for a continuous task. |
| 980000602 | Notification verification failed. Failed to send or cancel the notification. |
| 980000603 | Continuous task param is null. |

 **Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';
import { BusinessError } from '@ohos.base';

particleAbility.cancelBackgroundRunning().then(() => {
    console.info('Operation succeeded');
}).catch((err: BusinessError) => {
    console.error(`Operation failed cause: ${JSON.stringify(err)}`);
});

```

## particleAbility.connectAbility

connectAbility(request: Want, options:ConnectOptions): number

Connects this ability to a specific ServiceAbility.

Observe the following when using this API:
 - To connect to a ServiceAbility of another application, the target application must be configured with associated startup (**AssociateWakeUp** set to **true**)..
 - If an application running in the background needs to call this API to connect to a ServiceAbility, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission. (Applications developed using the SDK of API version 8 or earlier are not restricted by this restriction when connecting to the ServiceAbility.)
 - If **visible** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [ServiceExtensionContext.connectServiceExtensionAbility](js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextconnectserviceextensionability) instead.

**Parameters**

| Name   | Type          | Mandatory| Description                        |
| ------- | -------------- | ---- | ---------------------------- |
| request | [Want](js-apis-application-want.md)           | Yes  | ServiceAbility to connect.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes  | Connection options.          |

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | ID of the connected ServiceAbility. The ID starts from 0 and is incremented by 1 each time a connection is set up.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| -1   | Invalid parameter. |
| -2   | Ability not found.|
| -3   | Permission denied.|
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';
import rpc from '@ohos.rpc';
import { BusinessError } from '@ohos.base';

let connId = particleAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'ServiceAbilityA',
    },
    {
        onConnect: (element, remote) => {
            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
        },
        onDisconnect: (element) => {
            console.log(`ConnectAbility onDisconnect element.deviceId: ${element.deviceId}`);
        },
        onFailed: (code) => {
            console.error(`particleAbilityTest ConnectAbility onFailed errCode: ${code}`);
        },
    },
);

particleAbility.disconnectAbility(connId).then((data) => {
    console.log(`data: ${data}`);
}).catch((error: BusinessError) => {
    console.error(`particleAbilityTest result errCode: ${error.code}`);
});
```

## particleAbility.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

Disconnects this ability from a specific ServiceAbility. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [ServiceExtensionContext.disconnectServiceExtensionAbility](js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextdisconnectserviceextensionability) instead.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | connection | number               | Yes   | ID of the ServiceAbility to disconnect.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |
| -105 | Type of ability is invalid. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';
import rpc from '@ohos.rpc';

let connId = particleAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'ServiceAbilityA',
    },
    {
        onConnect: (element, remote) => {
            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
        },
        onDisconnect: (element) => {
            console.log(`ConnectAbility onDisconnect element.deviceId: ${element.deviceId}`);
        },
        onFailed: (code) => {
            console.error(`particleAbilityTest ConnectAbility onFailed errCode: ${code}`);
        },
    },
);

particleAbility.disconnectAbility(connId, (err) => {
    console.error(`particleAbilityTest disconnectAbility err: ${JSON.stringify(err)}`);
});
```


## particleAbility.disconnectAbility

disconnectAbility(connection: number): Promise\<void>

Disconnects this ability from a specific ServiceAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [ServiceExtensionContext.disconnectServiceExtensionAbility](js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextdisconnectserviceextensionability-1) instead.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| connection | number               | Yes   | ID of the ServiceAbility to disconnect.|
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |
| -105 | Type of ability is invalid. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import particleAbility from '@ohos.ability.particleAbility';
import rpc from '@ohos.rpc';
import { BusinessError } from '@ohos.base';

let connId = particleAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'ServiceAbilityA',
    },
    {
        onConnect: (element, remote) => {
            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
        },
        onDisconnect: (element) => {
            console.log(`ConnectAbility onDisconnect element.deviceId: ${element.deviceId}`);
        },
        onFailed: (code) => {
            console.error(`particleAbilityTest ConnectAbility onFailed errCode: ${code}`);
        },
    },
);

particleAbility.disconnectAbility(connId).then(() => {
    console.log('disconnectAbility success');
}).catch((error: BusinessError) => {
    console.error(`particleAbilityTest result errCode : ${error.code}`);
});
```
