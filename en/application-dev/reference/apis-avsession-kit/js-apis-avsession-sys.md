# @ohos.multimedia.avsession (AVSession Management) (System API)
<!--Kit: AVSession Kit-->
<!--Subsystem:Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester:@chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

The AVSession module provides APIs for media playback control so that applications can access the system's Media Controller.

This module provides the following typical features related to media sessions:

- [AVCastController](#avcastcontroller10): used to control playback, listen for remote playback state changes, and obtain the remote playback state in casting scenarios.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.multimedia.avsession (AVSession Management)](arkts-apis-avsession.md).

## Modules to Import

```ts
import { avSession } from '@kit.AVSessionKit';
```

## Usage Guidelines

This topic describes only system APIs. Before using these APIs, you must create an instance. For details about how to create an instance, see the description and example of the public API [avSession.createAVSession](arkts-apis-avsession-f.md#avsessioncreateavsession10).

## avSession.getAllSessionDescriptors

getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

Obtains the descriptors of all sessions that have set media information and registered control callbacks. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise\<Array\<Readonly\<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Promise used to return an array of AVSessionDescriptor objects, each of which is read only.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 6600101  | Session service exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getAllSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`getAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
  if (descriptors.length > 0 ) {
    console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
  }
}).catch((err: BusinessError) => {
  console.error(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.getAllSessionDescriptors

getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void

Obtains the descriptors of all sessions that have set media information and registered control callbacks. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Yes  | Callback used to return an array of AVSessionDescriptor objects, each of which is read only.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 6600101  |Session service exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getAllSessionDescriptors((err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {
  if (err) {
    console.error(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if (descriptors.length > 0 ) {
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
    }
  }
});
```

## avSession.getHistoricalSessionDescriptors<sup>10+</sup>

getHistoricalSessionDescriptors(maxSize?: number): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

Obtains the descriptors of all historical sessions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type   | Mandatory| Description                                                            |
| -------- | ------ | ---- | -----------------------------------------------------------------|
| maxSize  | number | No  | Maximum number of descriptors to obtain. The value ranges from 0 to 10. If this parameter is left blank, the default value **3** is used.|

**Return value**

| Type                                                                       | Description                                  |
| --------------------------------------------------------------------------- | -------------------------------------- |
| Promise\<Array\<Readonly\<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Promise used to return an array of AVSessionDescriptor objects, each of which is read only.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getHistoricalSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
  if (descriptors.length > 0 && descriptors[0]) {
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionId : ${descriptors[0].sessionId}`);
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].elementName.bundleName : ${descriptors[0].elementName.bundleName}`);
  }
}).catch((err: BusinessError) => {
  console.error(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.getHistoricalSessionDescriptors<sup>10+</sup>

getHistoricalSessionDescriptors(maxSize: number, callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void

Obtains the descriptors of all historical sessions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                                           | Mandatory| Description                                                            |
| -------- | ------------------------------------------------------------------------------ | ---- | -----------------------------------------------------------------|
| maxSize  | number                                                                         | Yes | Maximum number of descriptors to obtain. The value ranges from 0 to 10.|
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Yes  | Callback used to return an array of AVSessionDescriptor objects, each of which is read only.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message
| -------- | ---------------------------------------- |
| 201 |  permission denied. |
| 202 |  Not System App.  |
| 401 |  parameter check failed. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  |Session service exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getHistoricalSessionDescriptors(1, (err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {
  if (err) {
    console.error(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if (descriptors.length > 0 ) {
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionId : ${descriptors[0].sessionId}`);
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].elementName.bundleName : ${descriptors[0].elementName.bundleName}`);
    }
  }
});
```

## avSession.getHistoricalAVQueueInfos<sup>11+</sup>

getHistoricalAVQueueInfos(maxSize: number, maxAppSize: number) : Promise\<Array\<Readonly\<AVQueueInfo>>>

Obtains all the historical playlists. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type   | Mandatory| Description                                                            |
| -------- | ------ | ---- | ---------------------------------------------------------------|
| maxSize  | number | Yes  | Maximum number of playlists that can be obtained. Currently, the maximum number is restricted by the system.                    |
| maxAppSize | number | Yes  | Maximum number of applications to which the playlists to be obtained belong. Currently, the maximum number is restricted by the system.            |

**Return value**

| Type                                                                       | Description                                  |
| --------------------------------------------------------------------------- | ------------------------------------- |
| Promise\<Array\<Readonly\<[AVQueueInfo](#avqueueinfo11)\>\>\> | Promise used to return all the read-only historical playlists.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getHistoricalAVQueueInfos(3, 5).then((avQueueInfos: avSession.AVQueueInfo[]) => {
  console.info(`getHistoricalAVQueueInfos : SUCCESS : avQueueInfos.length : ${avQueueInfos.length}`);
}).catch((err: BusinessError) => {
  console.error(`getHistoricalAVQueueInfos BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.getHistoricalAVQueueInfos<sup>11+</sup>

getHistoricalAVQueueInfos(maxSize: number, maxAppSize: number, callback: AsyncCallback\<Array\<Readonly\<AVQueueInfo>>>): void;

Obtains all the historical playlists. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                                           | Mandatory| Description                                                            |
| -------- | ----------------------------------------------------------------------------- | ---- | ---------------------------------------------------------------|
| maxSize  | number                                                                        | Yes  | Maximum number of playlists that can be obtained. Currently, the maximum number is restricted by the system.                     |
| maxAppSize | number                                                                      | Yes  | Maximum number of applications to which the playlists to be obtained belong. Currently, the maximum number is restricted by the system.              |
| callback | AsyncCallback<Array<Readonly<[AVQueueInfo](#avqueueinfo11)\>\>\> | Yes  | Callback used to return all the read-only historical playlists.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  |Session service exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getHistoricalAVQueueInfos(3, 5, (err: BusinessError, avQueueInfos: avSession.AVQueueInfo[]) => {
  if (err) {
    console.error(`getHistoricalAVQueueInfos BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getHistoricalAVQueueInfos : SUCCESS : avQueueInfos.length : ${avQueueInfos.length}`);
  }
});
```

## avSession.createController

createController(sessionId: string): Promise\<AVSessionController>

Creates a session controller based on the session ID. Multiple session controllers can be created. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name   | Type  | Mandatory| Description    |
| --------- | ------ | ---- | -------- |
| sessionId | string | Yes  | Session ID. If the value is set to **'default'**, the system creates a default controller to control the system default session.|

**Return value**

| Type                                                 | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\> | Promise used to return the session controller created, which can be used to obtain the session ID,<br>send commands and events to sessions, and obtain metadata and playback state information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVcontroller: avSession.AVSessionController | undefined = undefined;
currentAvSession.createController(sessionId).then((avcontroller: avSession.AVSessionController) => {
  currentAVcontroller = avcontroller;
  console.info('CreateController : SUCCESS ');
}).catch((err: BusinessError) => {
  console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.createController

createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void

Creates a session controller based on the session ID. Multiple session controllers can be created. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name   | Type                                                       | Mandatory| Description                                                        |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| sessionId | string                                                      | Yes  | Session ID. If the value is set to **'default'**, the system creates a default controller to control the system default session.                                                    |
| callback  | AsyncCallback<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\> | Yes  | Callback used to return the session controller created, which can be used to obtain the session ID,<br>send commands and events to sessions, and obtain metadata and playback state information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVcontroller: avSession.AVSessionController | undefined = undefined;
currentAvSession.createController(sessionId, (err: BusinessError, avcontroller: avSession.AVSessionController) => {
  if (err) {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVcontroller = avcontroller;
    console.info('CreateController : SUCCESS ');
  }
});
```

## avSession.castAudio

castAudio(session: SessionToken | 'all', audioDevices: Array<audio.AudioDeviceDescriptor>): Promise\<void>

Casts a session to a list of devices. This API uses a promise to return the result.

Before calling this API, import the **ohos.multimedia.audio** module to obtain the descriptors of these audio devices.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name       | Type          | Mandatory| Description|
| ------------ | -------------- |------|------|
| session      | [SessionToken](#sessiontoken) &#124; 'all' | Yes  | Session token. **SessionToken** indicates a specific token, and **'all'** indicates all tokens.|
| audioDevices | Array\<[audio.AudioDeviceDescriptor](../apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor)\> | Yes  | Audio devices. |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If casting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err: BusinessError) => {
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

if (audioDevices !== undefined) {
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors).then(() => {
    console.info('CreateController : SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}
```

## avSession.castAudio

castAudio(session: SessionToken | 'all', audioDevices: Array<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void

Casts a session to a list of devices. This API uses an asynchronous callback to return the result.

Before calling this API, import the **ohos.multimedia.audio** module to obtain the descriptors of these audio devices.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name      | Type                                        | Mandatory| Description                                                        |
| ------------ |--------------------------------------------| ---- | ------------------------------------------------------------ |
| session      | [SessionToken](#sessiontoken) &#124; 'all' | Yes  | Session token. **SessionToken** indicates a specific token, and **'all'** indicates all tokens.|
| audioDevices | Array\<[audio.AudioDeviceDescriptor](../apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor)\>   | Yes  | Audio devices.|
| callback     | AsyncCallback\<void>     | Yes  | Callback used to return the result. If casting is successful, **err** is **undefined**; otherwise, **err** is an error object.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err: BusinessError) => {
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

if (audioDevices !== undefined) {
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors, (err: BusinessError) => {
    if (err) {
      console.error(`CastAudio BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('CastAudio : SUCCESS ');
    }
  });
}
```

## avSession.startAVPlayback<sup>11+</sup>

startAVPlayback(bundleName: string, assetId: string): Promise\<void>

Starts an application to play a media asset. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name       | Type          | Mandatory| Description|
| ------------ | -------------- |------|------|
| bundleName   | string         | Yes  | Bundle name of the application.|
| assetId      |string           | Yes  | ID of the media asset. |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the playback is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

avSession.startAVPlayback("com.example.myapplication", "121278").then(() => {
  console.info('startAVPlayback : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`startAVPlayback BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.getDistributedSessionController<sup>18+</sup>

getDistributedSessionController(distributedSessionType: DistributedSessionType): Promise<Array\<AVSessionController>>

Obtains remote distributed session controllers based on the remote session type. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name   | Type                                                                     | Mandatory| Description     |
| --------- |-------------------------------------------------------------------------| ---- |---------|
| distributedSessionType | [DistributedSessionType](#distributedsessiontype18) | Yes  | Remote session type.|

**Return value**

| Type                                                                                | Description                                                                   |
|------------------------------------------------------------------------------------|-----------------------------------------------------------------------|
| Promise<Array<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\>> | Promise used to return an array of session controller instances of the corresponding type. You can view the session ID, send commands and events to the session, and obtain metadata and playback status information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID  | Error Message                                                                                                 |
|---------|-------------------------------------------------------------------------------------------------------|
| 201     | permission denied.                                                                                    |
| 202     | Not System App. |
| 6600101 | Session service exception.                                                                            |
| 6600109 | The remote connection is not established.                                                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';

avSession.getDistributedSessionController(avSession.DistributedSessionType.TYPE_SESSION_REMOTE).then((sessionControllers: Array<avSession.AVSessionController>) => {
  console.info(`getDistributedSessionController : SUCCESS : sessionControllers.length : ${sessionControllers.length}`);
}).catch((err: BusinessError) => {
  console.error(`getDistributedSessionController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```


## SessionToken

Describes the information about a session token.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

| Name     | Type  | Mandatory| Description        |
| :-------- | :----- | :--- | :----------- |
| sessionId | string | Yes  | Session ID.      |
| pid       | number | No  | Process ID of the session.|
| uid       | number | No  | User ID.      |

## avSession.on('sessionCreate')

on(type: 'sessionCreate', callback: (session: AVSessionDescriptor) => void): void

Subscribes to session creation events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name   | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The event **'sessionCreate'** is triggered when a session is created.|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | Yes  | Callback used to report the session descriptor.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.on('sessionCreate', (descriptor: avSession.AVSessionDescriptor) => {
  console.info(`on sessionCreate : isActive : ${descriptor.isActive}`);
  console.info(`on sessionCreate : type : ${descriptor.type}`);
  console.info(`on sessionCreate : sessionTag : ${descriptor.sessionTag}`);
});

```

## avSession.on('sessionDestroy')

on(type: 'sessionDestroy', callback: (session: AVSessionDescriptor) => void): void

Subscribes to session destruction events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type           | Mandatory| Description                                                        |
| -------- | ---------------| ---- | ------------------------------------------------------------ |
| type     | string         | Yes  | Event type. The event **'sessionDestroy'** is triggered when a session is destroyed.|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | Yes  | Callback used to report the session descriptor.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.on('sessionDestroy', (descriptor: avSession.AVSessionDescriptor) => {
  console.info(`on sessionDestroy : isActive : ${descriptor.isActive}`);
  console.info(`on sessionDestroy : type : ${descriptor.type}`);
  console.info(`on sessionDestroy : sessionTag : ${descriptor.sessionTag}`);
});
```

## avSession.on('topSessionChange')

on(type: 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void

Subscribes to top session change events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | --------------------| ---- | ------------------------------------------------------------ |
| type     | string      | Yes  | Event type. The event **'topSessionChange'** is triggered when the top session is changed.|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | Yes  | Callback used to report the session descriptor.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.on('topSessionChange', (descriptor: avSession.AVSessionDescriptor) => {
  console.info(`on topSessionChange : isActive : ${descriptor.isActive}`);
  console.info(`on topSessionChange : type : ${descriptor.type}`);
  console.info(`on topSessionChange : sessionTag : ${descriptor.sessionTag}`);
});
```

## avSession.off('sessionCreate')

off(type: 'sessionCreate', callback?: (session: AVSessionDescriptor) => void): void

Unsubscribes from session creation events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type      | Mandatory| Description      |
| -------- | ----------| ---- | ----------|
| type     | string    | Yes  | Event type, which is **'sessionCreate'** in this case.|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **session** parameter in the callback describes a media session. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.off('sessionCreate');
```

## avSession.off('sessionDestroy')

off(type: 'sessionDestroy', callback?: (session: AVSessionDescriptor) => void): void

Unsubscribes from session destruction events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type       | Mandatory| Description                     |
| -------- | -----------| ---- | -------------------------|
| type     | string     | Yes  | Event type, which is **'sessionDestroy'** in this case.|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **session** parameter in the callback describes a media session. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.off('sessionDestroy');
```

## avSession.off('topSessionChange')

off(type: 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void

Unsubscribes from top session change events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type             | Mandatory| Description                       |
| -------- | -----------------| ---- | ---------------------------- |
| type     | string           | Yes  | Event type, which is **'topSessionChange'** in this case.|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **session** parameter in the callback describes a media session. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.off('topSessionChange');
```

## avSession.on('sessionServiceDie')

on(type: 'sessionServiceDie', callback: () => void): void

Subscribes to session service death events. Upon receiving this event, the application can clear resources.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'sessionServiceDie'** is triggered when the session service dies.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.on('sessionServiceDie', () => {
  console.info('on sessionServiceDie  : session is  Died ');
});
```

## avSession.off('sessionServiceDie')

off(type: 'sessionServiceDie', callback?: () => void): void

Unsubscribes from session service death events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**System API**: This is a system API.

**Parameters**

| Name   | Type                   | Mandatory |      Description                                              |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | Yes   | Event type. The event **'sessionServiceDie'** is triggered when the session service dies.|
| callback | callback: () => void   | No   | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.off('sessionServiceDie');
```


## avSession.on('distributedSessionChange')<sup>18+</sup>

on(type: 'distributedSessionChange', distributedSessionType: DistributedSessionType, callback: Callback<Array\<AVSessionController>>): void

Subscribes to the latest distributed remote session change events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                                                 | Mandatory| Description                                                                      |
| -------- |-------------------------------------------------------------------------------------| ---- |--------------------------------------------------------------------------|
| type     | string                                                                              | Yes  | Event type. The event **'distributedSessionChange'** is triggered when the latest distributed session is changed.|
| distributedSessionType     | [DistributedSessionType](#distributedsessiontype18)             | Yes  | Remote session type.                                                                 |
| callback | Callback<Array<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\>> | Yes  | Callback used to return an array of session controller instances of the corresponding type. You can view the session ID, send commands and events to the session, and obtain metadata and playback status information.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID  | Error Message                                                                                             |
|---------|---------------------------------------------------------------------------------------------------|
| 202     | Not System App. |
| 6600101 | Session service exception.                                                                        |

**Example**

```ts
avSession.on('distributedSessionChange', avSession.DistributedSessionType.TYPE_SESSION_REMOTE, (sessionControllers: Array<avSession.AVSessionController>) => {
  console.info(`on distributedSessionChange size: ${sessionControllers.length}`);
});
```


## avSession.off('distributedSessionChange')<sup>18+</sup>

off(type: 'distributedSessionChange', distributedSessionType: DistributedSessionType, callback?: Callback<Array\<AVSessionController>>): void

Unsubscribes from the latest distributed remote session change events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                                                 | Mandatory| Description                                                           |
| -------- |-------------------------------------------------------------------------------------|----|---------------------------------------------------------------|
| type     | string                                                                              | Yes | Event type. The event **'distributedSessionChange'** is triggered when the latest distributed session is changed.                   |
| distributedSessionType     | [DistributedSessionType](#distributedsessiontype18)             | Yes | Remote session type.                                                      |
| callback | Callback<Array<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\>> | No | Callback used to return an array of session controller instances of the corresponding type. You can view the session ID, send commands and events to the session, and obtain metadata and playback status information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID  | Error Message                                                                                             |
|---------|---------------------------------------------------------------------------------------------------|
| 202     | Not System App. |
| 6600101 | Session service exception.                                                                        |

**Example**

```ts
avSession.off('distributedSessionChange', avSession.DistributedSessionType.TYPE_SESSION_REMOTE);
```

## avSession.sendSystemAVKeyEvent

sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

Sends a system key event to the top session. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------- |
| event    | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | Yes  | Key event.                           |
| callback | AsyncCallback\<void>                                         | Yes  | Callback used to return the result. If the event is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**Example**

```ts
import { KeyEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event, (err: BusinessError) => {
  if (err) {
    console.error(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('SendSystemAVKeyEvent : SUCCESS ');
  }
});
```

## avSession.sendSystemAVKeyEvent

sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>

Sends a system key event to the top session. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name| Type                           | Mandatory| Description      |
| ------ | ------------------------------- | ---- | ---------- |
| event  | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | Yes  | Key event.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the event is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**Example**

```ts
import { KeyEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event).then(() => {
  console.info('SendSystemAVKeyEvent Successfully');
}).catch((err: BusinessError) => {
  console.error(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.sendSystemControlCommand

sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

Sends a system control command to the top session. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| command  | [AVControlCommand](arkts-apis-avsession-i.md#avcontrolcommand10) | Yes  | Command to send.  |
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**Example**

```ts
let cmd : avSession.AVControlCommandType = 'play';
// let cmd : avSession.AVControlCommandType = 'pause';
// let cmd : avSession.AVControlCommandType = 'stop';
// let cmd : avSession.AVControlCommandType = 'playNext';
// let cmd : avSession.AVControlCommandType = 'playPrevious';
// let cmd : avSession.AVControlCommandType = 'fastForward';
// let cmd : avSession.AVControlCommandType = 'rewind';
let avcommand: avSession.AVControlCommand = {command:cmd};
// let cmd : avSession.AVControlCommandType = 'seek';
// let avcommand = {command:cmd, parameter:10};
// let cmd : avSession.AVControlCommandType = 'setSpeed';
// let avcommand = {command:cmd, parameter:2.6};
// let cmd : avSession.AVControlCommandType = 'setLoopMode';
// let avcommand = {command:cmd, parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let cmd : avSession.AVControlCommandType = 'toggleFavorite';
// let avcommand = {command:cmd, parameter:"false"};
avSession.sendSystemControlCommand(avcommand, (err) => {
  if (err) {
    console.error(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('sendSystemControlCommand successfully');
  }
});
```

## avSession.sendSystemControlCommand

sendSystemControlCommand(command: AVControlCommand): Promise\<void>

Sends a system control command to the top session. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name | Type                                 | Mandatory| Description                               |
| ------- | ------------------------------------- | ---- | ----------------------------------- |
| command | [AVControlCommand](arkts-apis-avsession-i.md#avcontrolcommand10) | Yes  | Command to send.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let cmd : avSession.AVControlCommandType = 'play';
// let cmd : avSession.AVControlCommandType = 'pause';
// let cmd : avSession.AVControlCommandType = 'stop';
// let cmd : avSession.AVControlCommandType = 'playNext';
// let cmd : avSession.AVControlCommandType = 'playPrevious';
// let cmd : avSession.AVControlCommandType = 'fastForward';
// let cmd : avSession.AVControlCommandType = 'rewind';
let avcommand: avSession.AVControlCommand = {command:cmd};
// let cmd : avSession.AVControlCommandType = 'seek';
// let avcommand = {command:cmd, parameter:10};
// let cmd : avSession.AVControlCommandType = 'setSpeed';
// let avcommand = {command:cmd, parameter:2.6};
// let cmd : avSession.AVControlCommandType = 'setLoopMode';
// let avcommand = {command:cmd, parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let cmd : avSession.AVControlCommandType = 'toggleFavorite';
// let avcommand = {command:cmd, parameter:"false"};
avSession.sendSystemControlCommand(avcommand).then(() => {
  console.info('SendSystemControlCommand successfully');
}).catch((err: BusinessError) => {
  console.error(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## ProtocolType<sup>10+</sup>

Enumerates the protocol types supported by the remote device.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| TYPE_CAST_PLUS_MIRROR      | 1    | Cast+ mirror mode.<br> **System API**: This is a system API.|

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(callback: AsyncCallback\<void>): void

Starts cast-enabled device discovery. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent and device discovery starts, **err** is **undefined**; otherwise, **err** is an error object.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.startCastDeviceDiscovery((err: BusinessError) => {
  if (err) {
    console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('startCastDeviceDiscovery successfully');
  }
});
```

## DistributedSessionType<sup>18+</sup>

Enumerates the session types supported by the remote distributed device.

**System capability**: SystemCapability.Multimedia.AVSession.Message

**System API**: This is a system API.

| Name                                    | Value| Description                       |
|----------------------------------------|---|---------------------------|
| TYPE_SESSION_REMOTE      | 0 | Session on the remote device.|
| TYPE_SESSION_MIGRATE_IN  | 1 | Session migrated to the local device.|
| TYPE_SESSION_MIGRATE_OUT | 2 | Session migrated to the remote device.|

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(filter: number, callback: AsyncCallback\<void>): void

Starts cast-enabled device discovery with filter criteria specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| filter | number | Yes| Filter criteria for device discovery. The value consists of **ProtocolType**s.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent and device discovery starts, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filter = 2;
avSession.startCastDeviceDiscovery(filter, (err: BusinessError) => {
  if (err) {
    console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('startCastDeviceDiscovery successfully');
  }
});
```

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(filter?: number, drmSchemes?: Array\<string>): Promise\<void>

Starts cast-enabled device discovery. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| filter | number | No| Filter criteria for device discovery. The value consists of **ProtocolType**s.|
| drmSchemes | Array\<string> | No| Filter criteria for discovering devices that support DRM resource playback. The value consists of DRM UUIDs.<br>This parameter is supported since API version 12.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent and device discovery starts, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filter = 2;
let drmSchemes = ['3d5e6d35-9b9a-41e8-b843-dd3c6e72c42c'];
avSession.startCastDeviceDiscovery(filter, drmSchemes).then(() => {
  console.info('startCastDeviceDiscovery successfully');
}).catch((err: BusinessError) => {
  console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.stopCastDeviceDiscovery<sup>10+</sup>

stopCastDeviceDiscovery(callback: AsyncCallback\<void>): void

Stops cast-enabled device discovery. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If device discovery stops, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.stopCastDeviceDiscovery((err: BusinessError) => {
  if (err) {
    console.error(`stopCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('stopCastDeviceDiscovery successfully');
  }
});
```

## avSession.stopCastDeviceDiscovery<sup>10+</sup>

stopCastDeviceDiscovery(): Promise\<void>

Stops cast-enabled device discovery. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If device discovery stops, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.stopCastDeviceDiscovery().then(() => {
  console.info('stopCastDeviceDiscovery successfully');
}).catch((err: BusinessError) => {
  console.error(`stopCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.setDiscoverable<sup>10+</sup>

setDiscoverable(enable: boolean, callback: AsyncCallback\<void>): void

Sets whether to allow the device discoverable. A discoverable device can be used as the cast receiver. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| enable | boolean | Yes| Whether to allow the device discoverable. **true** if discoverable, **false** otherwise.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.setDiscoverable(true, (err: BusinessError) => {
  if (err) {
    console.error(`setDiscoverable BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('setDiscoverable successfully');
  }
});
```

## avSession.setDiscoverable<sup>10+</sup>

setDiscoverable(enable: boolean): Promise\<void>

Sets whether to allow the device discoverable. A discoverable device can be used as the cast receiver. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| enable | boolean | Yes| Whether to allow the device discoverable. **true** if discoverable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.setDiscoverable(true).then(() => {
  console.info('setDiscoverable successfully');
}).catch((err: BusinessError) => {
  console.error(`setDiscoverable BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.on('deviceAvailable')<sup>10+</sup>

on(type: 'deviceAvailable', callback: (device: OutputDeviceInfo) => void): void

Subscribes to device discovery events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'deviceAvailable'** is triggered when a device is discovered.|
| callback | (device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
let castDevice: avSession.OutputDeviceInfo;
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {
  castDevice = device;
  console.info(`on deviceAvailable  : ${device} `);
});
```

## avSession.off('deviceAvailable')<sup>10+</sup>

off(type: 'deviceAvailable', callback?: (device: OutputDeviceInfo) => void): void

Unsubscribes from device discovery events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name   | Type                   | Mandatory |      Description                                              |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | Yes   | Event type. The event **'deviceAvailable'** is triggered when a device is discovered.|
| callback     | (device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void                 | No   | Callback used to return the device information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
avSession.off('deviceAvailable');
```

## avSession.on('deviceOffline')<sup>11+</sup>

on(type: 'deviceOffline', callback: (deviceId: string) => void): void

Subscribes to device offline events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'deviceOffline'** is triggered when a device gets offline.|
| callback | (deviceId: string) => void | Yes  | Callback used to return the result. The **deviceId** parameter in the callback indicates the device ID. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
let castDeviceId: string;
avSession.on('deviceOffline', (deviceId: string) => {
  castDeviceId = deviceId;
  console.info(`on deviceOffline  : ${deviceId} `);
});
```

## avSession.off('deviceOffline')<sup>11+</sup>

off(type: 'deviceOffline', callback?: (deviceId: string) => void): void

Unsubscribes from device offline events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name   | Type                   | Mandatory |      Description                                              |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | Yes   | Event type, which is **'deviceOffline'** in this case.|
| callback | (deviceId: string) => void | No  | Callback used to return the result. The **deviceId** parameter in the callback indicates the device ID. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
avSession.off('deviceOffline');
```

## avSession.getAVCastController<sup>10+</sup>

getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void

Obtains the cast controller when a casting connection is set up. This API uses an asynchronous callback to return the result.

This API can be called on both the local and remote devices. You can use the API to obtain the same controller to control audio playback after cast.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System API**: This is a system API.

**Parameters**

| Name   | Type                                                       | Mandatory| Description                                                        |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| sessionId | string                    | Yes  |Session ID.|
| callback  | AsyncCallback<[AVCastController](#avcastcontroller10)\> | Yes  | Callback used to return the cast controller.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception |
| 6600102  | session does not exist |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() { 
    Column() {
        Text(this.message)
          .onClick(()=>{
            let currentAVSession: avSession.AVSession | undefined = undefined;
            let tag = "createNewSession";
            let context = this.getUIContext().getHostContext() as Context;
            let sessionId: string = "";  // Used as an input parameter of subsequent functions.

            let aVCastController: avSession.AVCastController;
            avSession.getAVCastController(sessionId , (err: BusinessError, avcontroller: avSession.AVCastController) => {
            if (err) {
                console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
            } else {
                aVCastController = avcontroller;
                console.info('getAVCastController : SUCCESS ');
            }
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.getAVCastController<sup>10+</sup>

getAVCastController(sessionId: string): Promise\<AVCastController>

Obtains the cast controller when a casting connection is set up. This API uses a promise to return the result.

This API can be called on both the local and remote devices. You can use the API to obtain the same controller to control audio playback after cast.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System API**: This is a system API.

**Parameters**

| Name   | Type                      | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| sessionId | string                    | Yes  |Session ID.|

**Return value**

| Type                                                       | Description            |
| --------- | ------------------------------------------------------------ |
| Promise<[AVCastController](#avcastcontroller10)\>  | Promise used to return the cast controller.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | server exception |
| 6600102  | The session does not exist |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() { 
    Column() {
        Text(this.message)
          .onClick(()=>{
            let currentAVSession: avSession.AVSession | undefined = undefined;
            let tag = "createNewSession";
            let context = this.getUIContext().getHostContext() as Context;
            let sessionId: string = "";  // Used as an input parameter of subsequent functions.

            let aVCastController: avSession.AVCastController;
            avSession.getAVCastController(sessionId).then((avcontroller: avSession.AVCastController) => {
            aVCastController = avcontroller;
            console.info('getAVCastController : SUCCESS');
            }).catch((err: BusinessError) => {
            console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.startCasting<sup>10+</sup>

startCasting(session: SessionToken, device: OutputDeviceInfo, callback: AsyncCallback\<void>): void

Starts casting. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | Yes  | Session token.  |
| device | [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)                        | Yes  | Device-related information.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent and casting starts, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600108 | Device connection failed.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
let castDevice: avSession.OutputDeviceInfo | undefined = undefined;
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {
  castDevice = device;
  console.info(`on deviceAvailable  : ${device} `);
});
if (castDevice !== undefined) {
  avSession.startCasting(myToken, castDevice, (err: BusinessError) => {
    if (err) {
      console.error(`startCasting BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('startCasting successfully');
    }
  });
}
```


## avSession.startCasting<sup>10+</sup>

startCasting(session: SessionToken, device: OutputDeviceInfo): Promise\<void>

Starts casting. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | Yes  | Session token.  |
| device | [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)                        | Yes  | Device-related information.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent and casting starts, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600108 | Device connection failed.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
let castDevice: avSession.OutputDeviceInfo | undefined = undefined;
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {
  castDevice = device;
  console.info(`on deviceAvailable  : ${device} `);
});
if (castDevice !== undefined) {
  avSession.startCasting(myToken, castDevice).then(() => {
    console.info('startCasting successfully');
  }).catch((err: BusinessError) => {
    console.error(`startCasting BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}
```

## avSession.stopCasting<sup>10+</sup>

stopCasting(session: SessionToken, callback: AsyncCallback\<void>): void

Stops castings. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | Yes  | Session token.  | 
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If casting stops, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken, (err: BusinessError) => {
  if (err) {
    console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('stopCasting successfully');
  }
});
```

## avSession.stopCasting<sup>10+</sup>

stopCasting(session: SessionToken): Promise\<void>

Stops castings. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | Yes  | Session token.  |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If casting stops, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken).then(() => {
  console.info('stopCasting successfully');
}).catch((err: BusinessError) => {
  console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.startDeviceLogging<sup>13+</sup>

startDeviceLogging(url: string, maxSize?: number): Promise\<void>

Starts to write device logs to a file. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| url | string                   | Yes  | Target file descriptor (unique identifier used to open a file).|
| maxSize | number                   | No  | Maximum size of the log file, in KB.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the device logs are written to the file successfully, no result is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 401        | Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

let file = await fileIo.open("filePath");
let url = file.fd.toString();
avSession.startDeviceLogging(url, 2048).then(() => {
  console.info('startDeviceLogging successfully');
}).catch((err: BusinessError) => {
  console.error(`startDeviceLogging BusinessError: code: ${err.code}, message: ${err.message}`);
})
```

## avSession.stopDeviceLogging<sup>13+</sup>

stopDeviceLogging(): Promise\<void>

Stops device logging. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If device logging is stopped, no result is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.stopDeviceLogging().then(() => {
  console.info('stopCasting successfully');
}).catch((err: BusinessError) => {
  console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.on('deviceLogEvent')<sup>13+</sup>

on(type: 'deviceLogEvent', callback: Callback\<DeviceLogEventCode>): void

Subscribes to device log events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type, which is **'deviceLogEvent'** in this case.|
| callback | (callback: [DeviceLogEventCode](#devicelogeventcode13)) => void        | Yes  | Callback function, in which **DeviceLogEventCode** is the return value of the current device log event.                     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 401        | Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**Example**

```ts
avSession.on('deviceLogEvent', (eventCode: avSession.DeviceLogEventCode) => {
  console.info(`on deviceLogEvent code : ${eventCode}`);
});
```

## avSession.off('deviceLogEvent')<sup>13+</sup>

off(type: 'deviceLogEvent', callback?: Callback\<DeviceLogEventCode>): void

Unsubscribes from device log events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type, which is **'deviceLogEvent'** in this case.|
| callback | (callback: [DeviceLogEventCode](#devicelogeventcode13)) => void        | No | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 401        | Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**Example**

```ts
avSession.off('deviceLogEvent');
```

## DeviceState<sup>20+</sup>

Describes the connection state of the casting device.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name           | Type  | Read-Only|  Optional| Description        |
| :------------- | :----- | :--- | :--- | :----------- |
| deviceId       | string | Yes  | No   | ID of the casting device.      |
| deviceState    | number | Yes  | No   | Connection status code of the casting device.|
| reasonCode     | number | Yes  | No   | Connection error code of the casting device.|
| radarErrorCode | number | Yes  | No   | System radar error code.|

## avSession.on('deviceStateChanged')<sup>20+</sup>

on(type: 'deviceStateChanged', callback: Callback\<DeviceState\>): void

Subscribes to casting device connection state events.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type                                                         | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type, which is **'deviceStateChanged'** in this case. This event is triggered when the connection state of the casting device changes.|
| callback | (callback: [DeviceState](#devicestate20)) => void            | Yes  | Callback function, in which **DeviceState** contains the casting device ID, connection status code, connection error code, and system radar error code.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201        | Permission denied. |
| 202        | Not System App. |

**Example**

```ts
avSession.on('deviceStateChanged', (state: avSession.DeviceState) => {
  console.info(`on deviceStateChanged state, deviceId=${state.deviceId}, connect status=${state.deviceState},
    reasonCode=${state.reasonCode}, radarErrorCode=${state.radarErrorCode}`)
})
```

## avSession.off('deviceStateChanged')<sup>20+</sup>

off(type: 'deviceStateChanged', callback?: Callback\<DeviceState>): void

Unsubscribes from casting device connection state events.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type                                                         | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type, which is **'deviceStateChanged'** in this case. This event is triggered when the connection state of the casting device changes.|
| callback | (callback: [DeviceState](#devicestate20)) => void            | No  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201        | Permission denied. |
| 202        | Not System App. |

**Example**

```ts
avSession.off('deviceStateChanged');
```

## AVCastController<sup>10+</sup>

After a casting connection is set up, you can call [avSession.getAVCastController](arkts-apis-avsession-AVSession.md#getavcastcontroller10) to obtain the cast controller. Through the controller, you can query the session ID, send commands and events to a session, and obtain session metadata and playback state information.

### setDisplaySurface<sup>10+</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

Sets the surface ID for playback, which is used at the cast receiver (sink). This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                               | Mandatory| Description                        |
| -------- | --------------------------------------------------- | ---- | ---------------------------- |
| surfaceId | string | Yes  | Surface ID.|

**Return value**

| Type                                         | Description                       |
| --------------------------------------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**Example**

```ts
import { media } from '@kit.MediaKit';
let surfaceID: string = '';
media.createAVRecorder().then((avRecorder) => {
  avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {
    if (err == null) {
      console.info('getInputSurface success');
      surfaceID = surfaceId;
    } else {
      console.error('getInputSurface failed and error is ' + err.message);
    }
  });
})
aVCastController.setDisplaySurface(surfaceID).then(() => {
  console.info('setDisplaySurface : SUCCESS');
});
```

### setDisplaySurface<sup>10+</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

Sets the surface ID for playback, which is used at the cast receiver (sink). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                               | Mandatory| Description                        |
| -------- | --------------------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|
| surfaceId | string | Yes  | Surface ID.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';
let surfaceID: string = '';
media.createAVRecorder().then((avRecorder) => {
  avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {
    if (err == null) {
      console.info('getInputSurface success');
      surfaceID = surfaceId;
    } else {
      console.error('getInputSurface failed and error is ' + err.message);
    }
  });
})
aVCastController.setDisplaySurface(surfaceID, (err: BusinessError) => {
  if (err) {
    console.error(`setDisplaySurface BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('setDisplaySurface : SUCCESS');
  }
});
```

### on('videoSizeChange')<sup>12+</sup>

on(type: 'videoSizeChange', callback: (width:number, height:number) => void): void

Subscribes to video size change events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string      | Yes  | Event type. The event **'videoSizeChange'** is triggered when the video size changes.|
| callback | (width:number, height:number) => void    | Yes  | Callback used to return the video width and height.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
aVCastController.on('videoSizeChange', (width: number, height: number) => {
  console.info(`width : ${width} `);
  console.info(`height: ${height} `);
});
```

### off('videoSizeChange')<sup>12+</sup>

off(type: 'videoSizeChange'): void

Unsubscribes from video size changes.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type    | Mandatory| Description     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string  | Yes  | Event type, which is **'videoSizeChange'** in this case.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
aVCastController.off('videoSizeChange');
```

## AVMetadata<sup>10+</sup>

Describes the media metadata.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name           | Type                     | Mandatory| Description                                                                 |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| avQueueName<sup>12+</sup>     | string                  | No  | Playlist name.<br>This is a system API.|

## AVQueueInfo<sup>11+</sup>

Defines the attributes of a playlist.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**System API**: This is a system API.

| Name           | Type                     | Mandatory| Description                                                                 |
| --------------- |-------------------------| ---- |--------------------------------------------------------------------- |
| bundleName      | string                  | Yes  | Bundle name of the application to which the playlist belongs.                                                       |
| avQueueName     | string                  | Yes  | Playlist name.                                                   |
| avQueueId       | string                  | Yes  | Unique ID of the playlist.                                              |
| avQueueImage    | image.PixelMap &#124; string |Yes  | Cover image of the playlist, which can be pixel data of an image or an image path (local path or Internet path).    |
| lastPlayedTime  | number                  | No  | Last time when the playlist is played.                                                       |

## DeviceInfo<sup>10+</sup>

Describes the information related to the output device.

| Name      | Type          | Mandatory| Description                  |
| ---------- | -------------- | ---- | ---------------------- |
| ipAddress | string | No  | IP address of the output device.<br>This is a system API.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast    |
| providerId | number | No  | Vendor of the output device.<br>This is a system API.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast   |
| authenticationStatus<sup>11+</sup> | number | No  | Whether the output device is trusted. The default value is **0**, indicating that the device is untrusted. The value **1** means that the device is trusted.<br>This is a system API.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast   |
| networkId<sup>13+</sup> | string | No  | Network ID of the output device.<br>This is a system API.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast|

## AVSessionDescriptor

Declares the session descriptor.

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

| Name         | Type             | Read-Only| Optional| Description |
| --------------| ---------------- | ---------------- | ---------------- |------|
| sessionId    | string    | No| No | Session ID.     |
| type         | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10)   | No| No| Session type.   |
| sessionTag   | string             | No| No| Custom session name.   |
| elementName  | [ElementName](../apis-ability-kit/js-apis-bundle-ElementName.md)  | No| No| Information about the application to which the session belongs, including the bundle name and ability name.|
| isActive     | boolean             | No| No| Whether the session is activated.<br>**true**: The session is activated.<br>**false**: The session is not activated.                                     |
| isTopSession | boolean             | No| No| Whether the session is the top session.<br>**true**: The session is the top session.<br>**false**: The session is not the top session.               |
| outputDevice | [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)    | No| No| Information about the output device.  |

## DeviceLogEventCode<sup>13+</sup>

Enumerates the return values of device log events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| DEVICE_LOG_FULL       | 1    | The log file is full.   |
| DEVICE_LOG_EXCEPTION       | 2    | An exception occurs during device logging.|
