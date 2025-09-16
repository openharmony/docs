# @ohos.ability.particleAbility (ParticleAbility)

The particleAbility module provides APIs for operating a DataAbility and ServiceAbility. You can use the APIs to start and terminate a ParticleAbility, obtain a dataAbilityHelper object, and connect to or disconnect from a ServiceAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in the FA model.

## Constraints

The ParticleAbility module is used to perform operations on abilities of the Data and Service types.

## Modules to Import

```ts
import { particleAbility } from '@kit.AbilityKit';
```

## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>): void

Starts a ParticleAbility. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name     | Type                                           | Mandatory| Description             |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes  | Ability to start.|
| callback  | AsyncCallback\<void>                            | Yes  | Callback used to return the result. If the ParticleAbility is started, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility, wantConstant } from '@kit.AbilityKit';

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

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name     | Type                                           | Mandatory| Description             |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes  | Ability to start.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility, wantConstant } from '@kit.AbilityKit';

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

**Parameters**

| Name    | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the ParticleAbility is terminated, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility } from '@kit.AbilityKit';

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

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility } from '@kit.AbilityKit';

particleAbility.terminateSelf().then(() => {
  console.info('particleAbility terminateSelf');
});
```



## particleAbility.acquireDataAbilityHelper

acquireDataAbilityHelper(uri: string): DataAbilityHelper

Obtains a dataAbilityHelper object.

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).
> To access a DataAbility of another application, the target application must be configured with associated startup (**AssociateWakeUp** set to **true**).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name| Type  | Mandatory| Description                    |
| :--- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the file to open.|

**Return value**

| Type             | Description                                        |
| ----------------- | -------------------------------------------- |
| [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md) | A utility class used to help other abilities access a DataAbility.|

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility } from '@kit.AbilityKit';

let uri = '';
particleAbility.acquireDataAbilityHelper(uri);
```


## particleAbility.startBackgroundRunning<sup>(deprecated)</sup>

startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback&lt;void&gt;): void

Requests a continuous task from the system. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [backgroundTaskManager.startBackgroundRunning](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning) instead.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | id | number | Yes| Notification ID of the continuous task.|
  | request | [NotificationRequest](../apis-notification-kit/js-apis-notification.md#notificationrequest) | Yes| Notification parameter, which is used to display information in the notification bar.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the continuous task is requested, **err** is **undefined**. Otherwise, **err** is an error object.|

 **Example**

<!--code_no_check_fa-->
```ts
import { particleAbility, wantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import notification from '@ohos.notification';

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

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [backgroundTaskManager.startBackgroundRunning](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning-1) instead.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id | number | Yes| Notification ID of the continuous task.|
| request | [NotificationRequest](../apis-notification-kit/js-apis-notification.md#notificationrequest) | Yes| Notification parameter, which is used to display information in the notification bar.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility, wantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import notification from '@ohos.notification';

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

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [backgroundTaskManager.stopBackgroundRunning](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning) instead.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the continuous task is canceled, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [backgroundTaskManager.stopBackgroundRunning](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning-1) instead.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

 **Example**

<!--code_no_check_fa-->
```ts
import { particleAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

particleAbility.cancelBackgroundRunning().then(() => {
  console.info('Operation succeeded');
}).catch((err: BusinessError) => {
  console.error(`Operation failed cause: ${JSON.stringify(err)}`);
});
```

## particleAbility.connectAbility

connectAbility(request: Want, options:ConnectOptions): number

Connects this ability to a ServiceAbility.

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).
> To connect to a ServiceAbility of another application, the target application must be configured with associated startup (**AssociateWakeUp** set to **true**).


**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name   | Type          | Mandatory| Description                        |
| ------- | -------------- | ---- | ---------------------------- |
| request | [Want](js-apis-application-want.md)           | Yes  | ServiceAbility to connect.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes  | Connection options.          |

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | ID of the connected ServiceAbility. The ID starts from 0 and is incremented by 1 each time a connection is set up.|

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | connection | number               | Yes   | ID of the ServiceAbility to disconnect.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the disconnection is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

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

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number               | Yes   | ID of the ServiceAbility to disconnect.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import { particleAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
## ErrorCode

Enumerates the error codes that may be returned when an ability is started.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| INVALID_PARAMETER | -1   | Invalid parameter.|
