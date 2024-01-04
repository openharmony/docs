# @ohos.multimedia.avsession (AVSession Management)

The **avSession** module provides APIs for media playback control so that applications can access the system's Media Controller.

This module provides the following typical features related to media sessions:

- [AVSession](#avsession10): used to set session metadata, playback state information, and more.
- [AVSessionController](#avsessioncontroller10): used to obtain session IDs, send commands and events to sessions, and obtain the session metadata and playback state information.
- [AVCastController](#avcastcontroller10): used to control playback, listen for remote playback state changes, and obtain the remote playback state in casting scenarios.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import avSession from '@ohos.multimedia.avsession';
```

## avSession.createAVSession<sup>10+</sup>

createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>

Creates a media session. This API uses a promise to return the result. An ability can have only one session, and repeated calling of this API fails.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                           | Mandatory| Description                          |
| ------ | ------------------------------- | ---- | ------------------------------ |
| context| [Context](js-apis-inner-app-context.md) | Yes| Application context, which provides application environment information.|
| tag    | string                          | Yes  | Custom session name.            |
| type   | [AVSessionType](#avsessiontype10) | Yes  | Session type, which can be audio or video.|

**Return value**

| Type                             | Description                                                        |
| --------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSession](#avsession10)\> | Promise used to return the media session obtained, which can be used to obtain the session ID, set the metadata and playback state information, and send key events.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string;  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio").then((data: avSession.AVSession) => {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
}).catch((err: BusinessError) => {
  console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.createAVSession<sup>10+</sup>

createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void

Creates a media session. This API uses an asynchronous callback to return the result. An ability can have only one session, and repeated calling of this API fails.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context| [Context](js-apis-inner-app-context.md) | Yes| Application context, which provides application environment information.    |
| tag      | string                                  | Yes  | Custom session name.                                          |
| type     | [AVSessionType](#avsessiontype10)         | Yes  | Session type, which can be audio or video.                              |
| callback | AsyncCallback<[AVSession](#avsession10)\> | Yes  | Callback used to return the media session obtained, which can be used to obtain the session ID, set the metadata and playback state information, and send key events.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string;  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    sessionId = currentAVSession.sessionId;
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});
```

## avSession.getAllSessionDescriptors

getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

Obtains the descriptors of all sessions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise\<Array\<Readonly\<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Promise used to return an array of **AVSessionDescriptor** objects, each of which is read only.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avSession.getAllSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`getAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
  if(descriptors.length > 0 ){
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

Obtains the descriptors of all sessions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Yes  | Callback used to return an array of **AVSessionDescriptor** objects, each of which is read only.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  |Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avSession.getAllSessionDescriptors((err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {
  if (err) {
    console.error(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if(descriptors.length > 0 ){
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
    }
  }
});
```

## avSession.getHistoricalSessionDescriptors<sup>10+</sup>

getHistoricalSessionDescriptors(maxSize?: number): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

Obtains the descriptors of all sessions. This API uses a promise to return the result.

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
| Promise\<Array\<Readonly\<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Promise used to return an array of **AVSessionDescriptor** objects, each of which is read only.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avSession.getHistoricalSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
  if(descriptors.length > 0 ){
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

Obtains the descriptors of all sessions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                                           | Mandatory| Description                                                            |
| -------- | ------------------------------------------------------------------------------ | ---- | -----------------------------------------------------------------|
| maxSize  | number                                                                         | Yes  | Maximum number of descriptors to obtain. The value ranges from 0 to 10. If this parameter is left blank, the default value **3** is used.|
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Yes  | Callback used to return an array of **AVSessionDescriptor** objects, each of which is read only.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  |Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avSession.getHistoricalSessionDescriptors(1, (err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {
  if (err) {
    console.error(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if(descriptors.length > 0 ){
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  |Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| sessionId | string | Yes  | Session ID.|

**Return value**

| Type                                                 | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSessionController](#avsessioncontroller10)\> | Promise used to return the session controller created, which can be used to obtain the session ID,<br>send commands and events to sessions, and obtain metadata and playback state information.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let currentAVcontroller: avSession.AVSessionController | undefined = undefined;
avSession.createController(sessionId).then((avcontroller: avSession.AVSessionController) => {
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
| sessionId | string                                                      | Yes  | Session ID.                                                    |
| callback  | AsyncCallback<[AVSessionController](#avsessioncontroller10)\> | Yes  | Callback used to return the session controller created, which can be used to obtain the session ID,<br>send commands and events to sessions, and obtain metadata and playback state information.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let currentAVcontroller: avSession.AVSessionController | undefined = undefined;
avSession.createController(sessionId, (err: BusinessError, avcontroller: avSession.AVSessionController) => {
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
| audioDevices | Array\<[audio.AudioDeviceDescriptor](js-apis-audio.md#audiodevicedescriptor)\> | Yes  | Audio devices. |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If casting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**Example**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info(`Promise returned to indicate that the device list is obtained.`);
}).catch((err: BusinessError) => {
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

if (audioDevices !== undefined) {
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors).then(() => {
    console.info(`CreateController : SUCCESS`);
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
| audioDevices | Array\<[audio.AudioDeviceDescriptor](js-apis-audio.md#audiodevicedescriptor)\>   | Yes  | Audio devices.|
| callback     | AsyncCallback\<void>     | Yes  | Callback used to return the result. If casting is successful, **err** is **undefined**; otherwise, **err** is an error object.     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**Example**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info(`Promise returned to indicate that the device list is obtained.`);
}).catch((err: BusinessError) => {
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

if (audioDevices !== undefined) {
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors, (err: BusinessError) => {
    if (err) {
      console.error(`CastAudio BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`CastAudio : SUCCESS `);
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

avSession.startAVPlayback("com.example.myapplication", "121278").then(() => {
  console.info(`startAVPlayback : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`startAVPlayback BusinessError: code: ${err.code}, message: ${err.message}`);
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.off('topSessionChange');
```

## avSession.on('sessionServiceDie')

on(type: 'sessionServiceDie', callback: () => void): void

Subscribes to session service death events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'sessionServiceDie'** is triggered when the session service dies.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                               |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.on('sessionServiceDie', () => {
  console.info(`on sessionServiceDie  : session is  Died `);
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```ts
avSession.off('sessionServiceDie');
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
| event    | [KeyEvent](js-apis-keyevent.md) | Yes  | Key event.                           |
| callback | AsyncCallback\<void>                                         | Yes  | Callback used to return the result. If the event is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**Example**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';
import { BusinessError } from '@ohos.base';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event, (err: BusinessError) => {
  if (err) {
    console.error(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SendSystemAVKeyEvent : SUCCESS `);
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
| event  | [KeyEvent](js-apis-keyevent.md) | Yes  | Key event.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the event is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**Example**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';
import { BusinessError } from '@ohos.base';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event).then(() => {
  console.info(`SendSystemAVKeyEvent Successfully`);
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
| command  | [AVControlCommand](#avcontrolcommand10) | Yes  | Command to send.  |
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';

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
    console.info(`sendSystemControlCommand successfully`);
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
| command | [AVControlCommand](#avcontrolcommand10) | Yes  | Command to send.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

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
  console.info(`SendSystemControlCommand successfully`);
}).catch((err: BusinessError) => {
  console.error(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## ProtocolType<sup>10+</sup>

Enumerates the protocol types supported by the remote device.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| TYPE_LOCAL      | 0    | Local device.<br> **System API**: This is a system API.|
| TYPE_CAST_PLUS_MIRROR      | 1    | Cast+ mirror mode.<br> **System API**: This is a system API.|
| TYPE_CAST_PLUS_STREAM<sup>11+</sup>      | 2    | Cast+ stream mode.|

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
import { BusinessError } from '@ohos.base';

avSession.startCastDeviceDiscovery((err: BusinessError) => {
  if (err) {
    console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`startCastDeviceDiscovery successfully`);
  }
});
```

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


**Example**

```ts
import { BusinessError } from '@ohos.base';

let filter = 2;
avSession.startCastDeviceDiscovery(filter, (err: BusinessError) => {
  if (err) {
    console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`startCastDeviceDiscovery successfully`);
  }
});
```

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(filter?: number): Promise\<void>

Starts cast-enabled device discovery. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| filter | number | No| Filter criteria for device discovery. The value consists of **ProtocolType**s.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent and device discovery starts, no value is returned; otherwise, an error object is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let filter = 2;
avSession.startCastDeviceDiscovery(filter).then(() => {
  console.info(`startCastDeviceDiscovery successfully`);
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


**Example**

```ts
import { BusinessError } from '@ohos.base';

avSession.stopCastDeviceDiscovery((err: BusinessError) => {
  if (err) {
    console.error(`stopCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`stopCastDeviceDiscovery successfully`);
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

**Example**

```ts
import { BusinessError } from '@ohos.base';

avSession.stopCastDeviceDiscovery().then(() => {
  console.info(`startCastDeviceDiscovery successfully`);
}).catch((err: BusinessError) => {
  console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
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
| enable | boolean | Yes| Whether to allow the device discoverable. The value **true** means to allow the device discoverable, and **false** means the opposite.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|


**Example**

```ts
import { BusinessError } from '@ohos.base';

avSession.setDiscoverable(true, (err: BusinessError) => {
  if (err) {
    console.error(`setDiscoverable BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`setDiscoverable successfully`);
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
| enable | boolean | Yes| Whether to allow the device discoverable. The value **true** means to allow the device discoverable, and **false** means the opposite.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

avSession.setDiscoverable(true).then(() => {
  console.info(`setDiscoverable successfully`);
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
| callback | (device: OutputDeviceInfo) => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                               |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';

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

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';

let castDeviceId: string;
avSession.on('deviceOffline', (deviceId: string) => {
  castDeviceId = deviceId;
  console.info(`on deviceOffline  : ${deviceId} `);
});
```

## avSession.off('deviceOffline')<sup>11+</sup>

off(type: 'deviceOffline', callback?: (deviceId: string) => void): void

Unsubscribes from device offline events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name   | Type                   | Mandatory |      Description                                              |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | Yes   | Event type, which is **'deviceOffline'** in this case.|
| callback | (deviceId: string) => void | No  | Callback used to return the result. The **deviceId** parameter in the callback indicates the device ID. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Example**

```ts
avSession.off('deviceOffline');
```

## avSession.getAVCastController<sup>10+</sup>

getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void

Obtains the cast controller when a casting connection is set up. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES

**System API**: This is a system API.

**Parameters**

| Name   | Type                                                       | Mandatory| Description                                                        |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| sessionId | string                    | Yes  |Session ID.|
| callback  | AsyncCallback<[AVCastController](#avcastcontroller10)\> | Yes  | Callback used to return the cast controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | session does not exist |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let aVCastController: avSession.AVCastController;
avSession.getAVCastController(sessionId , (err: BusinessError, avcontroller: avSession.AVCastController) => {
  if (err) {
    console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    aVCastController = avcontroller;
    console.info('getAVCastController : SUCCESS ');
  }
});
```

## avSession.getAVCastController<sup>10+</sup>

getAVCastController(sessionId: string): Promise\<AVCastController>;

Obtains the cast controller when a casting connection is set up. This API uses a promise to return the result.

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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | server exception |
| 6600102  | The session does not exist |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let aVCastController: avSession.AVCastController;
avSession.getAVCastController(sessionId).then((avcontroller: avSession.AVCastController) => {
  aVCastController = avcontroller;
  console.info('getAVCastController : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
});
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
| device | [OutputDeviceInfo](#outputdeviceinfo10)                        | Yes  | Device-related information.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent and casting starts, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600108 | Device connecting failed.       |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

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
      console.info(`startCasting successfully`);
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
| device | [OutputDeviceInfo](#outputdeviceinfo10)                        | Yes  | Device-related information.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent and casting starts, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600108 | Device connecting failed.       |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

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
    console.info(`startCasting successfully`);
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken, (err: BusinessError) => {
  if (err) {
    console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`stopCasting successfully`);
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

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // Used as an input parameter of subsequent functions.

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken).then(() => {
  console.info(`stopCasting successfully`);
}).catch((err: BusinessError) => {
  console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
});


```

## AVSessionType<sup>10+<sup>
Enumerates the session types supported by the session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name | Type  | Description|
| ----- | ------ | ---- |
| audio | string | Audio session.|
| video | string | Video session.|

## AVSession<sup>10+</sup>

An **AVSession** object is created by calling [avSession.createAVSession](#avsessioncreateavsession10). The object enables you to obtain the session ID and set the metadata and playback state. 

### Attributes

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name     | Type  | Readable| Writable| Description                         |
| :-------- | :----- | :--- | :--- | :---------------------------- |
| sessionId | string | Yes  | No  | Unique session ID of the **AVSession** object.|
| sessionType<sup>10+</sup> | AVSessionType | Yes  | No  | AVSession type.|


**Example**

```ts
import avSession from '@ohos.multimedia.avsession';

let sessionId: string = currentAVSession.sessionId;
let sessionType: avSession.AVSessionType = currentAVSession.sessionType;
```

### setAVMetadata<sup>10+</sup>

setAVMetadata(data: AVMetadata): Promise\<void>

Sets session metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                     | Mandatory| Description        |
| ------ | ------------------------- | ---- | ------------ |
| data   | [AVMetadata](#avmetadata10) | Yes  | Session metadata.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let metadata: avSession.AVMetadata = {
  assetId: "121278",
  title: "lose yourself",
  artist: "Eminem",
  author: "ST",
  album: "Slim shady",
  writer: "ST",
  composer: "ST",
  duration: 2222,
  mediaImage: "https://www.example.com/example.jpg",
  subtitle: "8 Mile",
  description: "Rap",
  lyric: "https://www.example.com/example.lrc",
  previousAssetId: "121277",
  nextAssetId: "121279",
};
currentAVSession.setAVMetadata(metadata).then(() => {
  console.info(`SetAVMetadata successfully`);
}).catch((err: BusinessError) => {
  console.error(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVMetadata<sup>10+</sup>

setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void

Sets session metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                 |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [AVMetadata](#avmetadata10) | Yes  | Session metadata.                         |
| callback | AsyncCallback\<void>      | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let metadata: avSession.AVMetadata = {
  assetId: "121278",
  title: "lose yourself",
  artist: "Eminem",
  author: "ST",
  album: "Slim shady",
  writer: "ST",
  composer: "ST",
  duration: 2222,
  mediaImage: "https://www.example.com/example.jpg",
  subtitle: "8 Mile",
  description: "Rap",
  lyric: "https://www.example.com/example.lrc",
  previousAssetId: "121277",
  nextAssetId: "121279",
};
currentAVSession.setAVMetadata(metadata, (err: BusinessError) => {
  if (err) {
    console.error(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SetAVMetadata successfully`);
  }
});
```

### setCallMetadata<sup>11+</sup>

setCallMetadata(data: CallMetadata): Promise\<void>

Sets call metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                     | Mandatory| Description        |
| ------ | ------------------------- | ---- | ------------ |
| data   | [CallMetadata](#callmetadata11) | Yes  | Call metadata.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let calldata: avSession.CallMetadata = {
  name: "xiaoming",
  phoneNumber: "111xxxxxxxx",
  avatar: "xxx.jpg",
};
currentAVSession.setCallMetadata(calldata).then(() => {
  console.info(`setCallMetadata successfully`);
}).catch((err: BusinessError) => {
  console.error(`setCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setCallMetadata<sup>11+</sup>

setCallMetadata(data: CallMetadata, callback: AsyncCallback\<void>): void

Sets call metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                 |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [CallMetadata](#callmetadata11) | Yes  | Call metadata.                         |
| callback | AsyncCallback\<void>      | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let calldata: avSession.CallMetadata = {
  name: "xiaoming",
  phoneNumber: "111xxxxxxxx",
  avatar: "xxx.jpg",
};
currentAVSession.setCallMetadata(calldata, (err: BusinessError) => {
  if (err) {
    console.error(`setCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`setCallMetadata successfully`);
  }
});
```

### setAVCallState<sup>11+</sup>

setAVCallState(state: AVCallState): Promise\<void>

Sets the call state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                     | Mandatory| Description        |
| ------ | ------------------------- | ---- | ------------ |
| state   | [AVCallState](#avcallstate11) | Yes  | Call state.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let calldata: avSession.AVCallState = {
  state: avSession.AVCallState.CALL_STATE_ACTIVE ,
  muted: false
};
currentAVSession.setAVCallState(calldata).then(() => {
  console.info(`setAVCallState successfully`);
}).catch((err: BusinessError) => {
  console.error(`setAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVCallState<sup>11+</sup>

setAVCallState(state: AVCallState, callback: AsyncCallback\<void>): void

Sets the call state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                 |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state     | [AVCallState](#avcallstate11) | Yes  | Call state.                         |
| callback | AsyncCallback\<void>      | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avcalldata: avSession.AVCallState = {
  state: avsession.CallState.CALL_STATE_ACTIVE,
  muted: false
};
currentAVSession.setAVCallState(avcalldata, (err: BusinessError) => {
  if (err) {
    console.error(`setAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`setAVCallState successfully`);
  }
});
```

### setAVPlaybackState<sup>10+</sup>

setAVPlaybackState(state: AVPlaybackState): Promise\<void>

Sets information related to the session playback state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                               | Mandatory| Description                                          |
| ------ | ----------------------------------- | ---- | ---------------------------------------------- |
| data   | [AVPlaybackState](#avplaybackstate10) | Yes  | Information related to the session playback state.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let playbackState: avSession.AVPlaybackState = {
  state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
  speed: 1.0,
  position:{elapsedTime:10, updateTime:(new Date()).getTime()},
  bufferedTime:1000,
  loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
  isFavorite:true,
};
currentAVSession.setAVPlaybackState(playbackState).then(() => {
  console.info(`SetAVPlaybackState successfully`);
}).catch((err: BusinessError) => {
  console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVPlaybackState<sup>10+</sup>

setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void

Sets information related to the session playback state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                          |
| -------- | ----------------------------------- | ---- | ---------------------------------------------- |
| data     | [AVPlaybackState](#avplaybackstate10) | Yes  | Information related to the session playback state.|
| callback | AsyncCallback\<void>                | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let PlaybackState: avSession.AVPlaybackState = {
  state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
  speed: 1.0,
  position:{elapsedTime:10, updateTime:(new Date()).getTime()},
  bufferedTime:1000,
  loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
  isFavorite:true,
};
currentAVSession.setAVPlaybackState(PlaybackState, (err: BusinessError) => {
  if (err) {
    console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SetAVPlaybackState successfully`);
  }
});
```

### setLaunchAbility<sup>10+</sup>

setLaunchAbility(ability: WantAgent): Promise\<void>

Sets a launcher ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description                                                       |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| ability | [WantAgent](js-apis-app-ability-wantAgent.md) | Yes  | Application attributes, such as the bundle name, ability name, and deviceID.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import wantAgent from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

// WantAgentInfo object
let wantAgentInfo: wantAgent.WantAgentInfo = {
  wants: [
    {
      deviceId: "deviceId",
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility",
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
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
  currentAVSession.setLaunchAbility(agent).then(() => {
    console.info(`SetLaunchAbility successfully`);
  }).catch((err: BusinessError) => {
    console.error(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
  });
});
```

### setLaunchAbility<sup>10+</sup>

setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void

Sets a launcher ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| ability  | [WantAgent](js-apis-app-ability-wantAgent.md) | Yes  | Application attributes, such as the bundle name, ability name, and deviceID. |
| callback | AsyncCallback\<void>                          | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import wantAgent from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

// WantAgentInfo object
let wantAgentInfo: wantAgent.WantAgentInfo = {
  wants: [
    {
      deviceId: "deviceId",
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility",
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
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
  currentAVSession.setLaunchAbility(agent, (err: BusinessError) => {
    if (err) {
      console.error(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`SetLaunchAbility successfully`);
    }
  });
});
```

### dispatchSessionEvent<sup>10+</sup>

dispatchSessionEvent(event: string, args: {[key: string]: Object}): Promise\<void>

Dispatches a custom event in the session, including the event name and event content in key-value pair format. This API uses a promise to return the result. It is called by the provider.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description                                                       |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| event | string | Yes  | Name of the session event.|
| args | {[key: string]: any} | Yes  | Event content in key-value pair format.|

> **NOTE**
>
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want (Want)](./js-apis-app-ability-want.md).

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
let eventName = "dynamic_lyric";
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).dispatchSessionEvent(eventName, {lyric : "This is lyric"}).then(() => {
    console.info(`dispatchSessionEvent successfully`);
  }).catch((err: BusinessError) => {
    console.info(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
```

### dispatchSessionEvent<sup>10+</sup>

dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void

Dispatches a custom event in the session, including the event name and event content in key-value pair format. This API uses an asynchronous callback to return the result. It is called by the provider.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description                                                       |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| event | string | Yes  | Name of the session event.|
| args | {[key: string]: any} | Yes  | Event content in key-value pair format.|
| callback | AsyncCallback\<void>                          | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

> **NOTE**
>
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want (Want)](./js-apis-app-ability-want.md).

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
let eventName: string = "dynamic_lyric";
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).dispatchSessionEvent(eventName, {lyric : "This is lyric"}, (err: BusinessError) => {
    if(err) {
      console.error(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);
    }
  })
}
```

### setAVQueueItems<sup>10+</sup>

setAVQueueItems(items: Array\<AVQueueItem>): Promise\<void>

Sets a playlist. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                | Mandatory| Description                              |
| ------ | ------------------------------------ | ---- | ---------------------------------- |
| items  | Array<[AVQueueItem](#avqueueitem10)\> | Yes  | Playlist to set.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import image from '@ohos.multimedia.image';
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@ohos.base';
import avSession from '@ohos.multimedia.avsession';

let value: Uint8Array | undefined = undefined;
let imageSource: image.ImageSource | undefined = undefined;
resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI').then((data) => {
  value = data;
});
if (value !== undefined) {
  imageSource = image.createImageSource((value as Uint8Array).buffer);
}
let imagePixel: image.PixelMap | undefined = undefined;
if (imageSource !== undefined) {
  (imageSource as image.ImageSource).createPixelMap({desiredSize:{width: 150, height: 150}}).then((data) => {
    imagePixel = data;
  }).catch((err: BusinessError) => {
    console.error(`createPixelMap BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}

let queueItemDescription_1: avSession.AVMediaDescription = {
  assetId: '001',
  title: 'music_name',
  subtitle: 'music_sub_name',
  description: 'music_description',
  mediaImage : imagePixel,
  extras: {extras:'any'}
};
let queueItem_1: avSession.AVQueueItem = {
  itemId: 1,
  description: queueItemDescription_1
};
let queueItemDescription_2: avSession.AVMediaDescription = {
  assetId: '002',
  title: 'music_name',
  subtitle: 'music_sub_name',
  description: 'music_description',
  mediaImage: imagePixel,
  extras: {extras:'any'}
};
let queueItem_2: avSession.AVQueueItem = {
  itemId: 2,
  description: queueItemDescription_2
};
let queueItemsArray: avSession.AVQueueItem[] = [queueItem_1, queueItem_2];
currentAVSession.setAVQueueItems(queueItemsArray).then(() => {
  console.info(`SetAVQueueItems successfully`);
}).catch((err: BusinessError) => {
  console.error(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVQueueItems<sup>10+</sup>

setAVQueueItems(items: Array\<AVQueueItem>, callback: AsyncCallback\<void>): void

Sets a playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ----------------------------------------------------------- |
| items    | Array<[AVQueueItem](#avqueueitem10)\> | Yes  | Playlist to set.                         |
| callback | AsyncCallback\<void>                 | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import image from '@ohos.multimedia.image';
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@ohos.base';
import avSession from '@ohos.multimedia.avsession';

let value: Uint8Array | undefined = undefined;
let imageSource: image.ImageSource | undefined = undefined;
resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI').then((data) => {
  value = data;
});
if (value !== undefined) {
  imageSource = image.createImageSource((value as Uint8Array).buffer);
}
let imagePixel: image.PixelMap | undefined = undefined;
if (imageSource !== undefined) {
  (imageSource as image.ImageSource).createPixelMap({desiredSize:{width: 150, height: 150}}).then((data) => {
    imagePixel = data;
  }).catch((err: BusinessError) => {
    console.error(`createPixelMap BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
let queueItemDescription_1: avSession.AVMediaDescription = {
  assetId: '001',
  title: 'music_name',
  subtitle: 'music_sub_name',
  description: 'music_description',
  mediaImage : imagePixel,
  extras: {extras:'any'}
};
let queueItem_1: avSession.AVQueueItem = {
  itemId: 1,
  description: queueItemDescription_1
};
let queueItemDescription_2: avSession.AVMediaDescription = {
  assetId: '002',
  title: 'music_name',
  subtitle: 'music_sub_name',
  description: 'music_description',
  mediaImage: imagePixel,
  extras: {extras:'any'}
};
let queueItem_2: avSession.AVQueueItem = {
  itemId: 2,
  description: queueItemDescription_2
};
let queueItemsArray: avSession.AVQueueItem[] = [queueItem_1, queueItem_2];
currentAVSession.setAVQueueItems(queueItemsArray, (err: BusinessError) => {
  if (err) {
    console.error(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SetAVQueueItems successfully`);
  }
});
```

### setAVQueueTitle<sup>10+</sup>

setAVQueueTitle(title: string): Promise\<void>

Sets a name for the playlist. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| title  | string | Yes  | Name of the playlist.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let queueTitle = 'QUEUE_TITLE';
currentAVSession.setAVQueueTitle(queueTitle).then(() => {
  console.info(`SetAVQueueTitle successfully`);
}).catch((err: BusinessError) => {
  console.error(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVQueueTitle<sup>10+</sup>

setAVQueueTitle(title: string, callback: AsyncCallback\<void>): void

Sets a name for the playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| title    | string                | Yes  | Name of the playlist.                         |
| callback | AsyncCallback\<void>  | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let queueTitle = 'QUEUE_TITLE';
currentAVSession.setAVQueueTitle(queueTitle, (err: BusinessError) => {
  if (err) {
    console.info(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.error(`SetAVQueueTitle successfully`);
  }
});
```

### setExtras<sup>10+</sup>

setExtras(extras: {[key: string]: Object}): Promise\<void>

Sets a custom media packet in the form of key-value pairs. This API uses a promise to return the result. It is called by the provider.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description                                                       |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| extras | {[key: string]: Object} | Yes  | Key-value pairs of the custom media packet.|

> **NOTE**

> The **extras** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want (Want)](./js-apis-app-ability-want.md).

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).setExtras({extras : "This is custom media packet"}).then(() => {
    console.info(`setExtras successfully`);
  }).catch((err: BusinessError) => {
    console.info(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
```

### setExtras<sup>10+</sup>

setExtras(extras: {[key: string]: Object}, callback: AsyncCallback\<void>): void

Sets a custom media packet in the form of key-value pairs. This API uses an asynchronous callback to return the result. It is called by the provider.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description                                                       |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| extras | {[key: string]: any} | Yes  | Key-value pairs of the custom media packet.|
| callback | AsyncCallback\<void>                          | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

> **NOTE**
>
> The **extras** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want (Want)](./js-apis-app-ability-want.md).

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).setExtras({extras : "This is custom media packet"}, (err: BusinessError) => {
    if(err) {
      console.error(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);
    }
  })
}
```

### getController<sup>10+</sup>

getController(): Promise\<AVSessionController>

Obtains the controller corresponding to this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                | Description                         |
| ---------------------------------------------------- | ----------------------------- |
| Promise<[AVSessionController](#avsessioncontroller10)> | Promise used to return the session controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let avsessionController: avSession.AVSessionController;
currentAVSession.getController().then((avcontroller: avSession.AVSessionController) => {
  avsessionController = avcontroller;
  console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);
}).catch((err: BusinessError) => {
  console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getController<sup>10+</sup>

getController(callback: AsyncCallback\<AVSessionController>): void

Obtains the controller corresponding to this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                       | Mandatory| Description                      |
| -------- | ----------------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVSessionController](#avsessioncontroller10)\> | Yes  | Callback used to return the session controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let avsessionController: avSession.AVSessionController;
currentAVSession.getController((err: BusinessError, avcontroller: avSession.AVSessionController) => {
  if (err) {
    console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    avsessionController = avcontroller;
    console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);
  }
});
```

### getAVCastController<sup>10+</sup>

getAVCastController(callback: AsyncCallback\<AVCastController>): void

Obtains the cast controller when a casting connection is set up. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name   | Type                                                       | Mandatory| Description                                                        |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback<[AVCastController](#avcastcontroller10)\> | Yes  | Callback used to return the cast controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message                                 |
| -------- |---------------------------------------|
| 6600102  | The session does not exist.           |
| 6600110  | The remote connection does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let aVCastController: avSession.AVCastController;
currentAVSession.getAVCastController().then((avcontroller: avSession.AVCastController) => {
  aVCastController = avcontroller;
  console.info(`getAVCastController : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVCastController<sup>10+</sup>

getAVCastController(): Promise\<AVCastController>;

Obtains the cast controller when a casting connection is set up. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Return value**

| Type                                                       | Description                                                        |
| --------- | ------------------------------------------------------------ |
| Promise<[AVCastController](#avcastcontroller10)\>  | Promise used to return the cast controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | --------------------------------------- |
| 6600102  | The session does not exist. |
| 6600110  | The remote connection does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let aVCastController: avSession.AVCastController;
currentAVSession.getAVCastController((err: BusinessError, avcontroller: avSession.AVCastController) => {
  if (err) {
    console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    aVCastController = avcontroller;
    console.info(`getAVCastController : SUCCESS`);
  }
});
```

### getOutputDevice<sup>10+</sup>

getOutputDevice(): Promise\<OutputDeviceInfo>

Obtains information about the output device for this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                          | Description                             |
| ---------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo10)> | Promise used to return the output device information.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.getOutputDevice().then((outputDeviceInfo: avSession.OutputDeviceInfo) => {
  console.info(`GetOutputDevice : SUCCESS : devices length : ${outputDeviceInfo.devices.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
})
```

### getOutputDevice<sup>10+</sup>

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

Obtains information about the output device for this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                 | Mandatory| Description                          |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo10)\> | Yes  | Callback used to return the information obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.getOutputDevice((err: BusinessError, outputDeviceInfo: avSession.OutputDeviceInfo) => {
  if (err) {
    console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetOutputDevice : SUCCESS : devices length : ${outputDeviceInfo.devices.length}`);
  }
});
```

### activate<sup>10+</sup>

activate(): Promise\<void>

Activates this session. A session can be used only after being activated. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the session is activated, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.activate().then(() => {
  console.info(`Activate : SUCCESS `);
}).catch((err: BusinessError) => {
  console.error(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### activate<sup>10+</sup>

activate(callback: AsyncCallback\<void>): void

Activates this session. A session can be used only after being activated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the session is activated, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.activate((err: BusinessError) => {
  if (err) {
    console.error(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Activate : SUCCESS `);
  }
});
```

### deactivate<sup>10+</sup>

deactivate(): Promise\<void>

Deactivates this session. You can use [activate](#activate10) to activate the session again. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the session is deactivated, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.deactivate().then(() => {
  console.info(`Deactivate : SUCCESS `);
}).catch((err: BusinessError) => {
  console.error(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### deactivate<sup>10+</sup>

deactivate(callback: AsyncCallback\<void>): void

Deactivates this session. This API uses an asynchronous callback to return the result.

Deactivates this session. You can use [activate](#activate10) to activate the session again.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the session is deactivated, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.deactivate((err: BusinessError) => {
  if (err) {
    console.error(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Deactivate : SUCCESS `);
  }
});
```

### destroy<sup>10+</sup>

destroy(): Promise\<void>

Destroys this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the session is destroyed, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.destroy().then(() => {
  console.info(`Destroy : SUCCESS `);
}).catch((err: BusinessError) => {
  console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### destroy<sup>10+</sup>

destroy(callback: AsyncCallback\<void>): void

Destroys this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the session is destroyed, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.destroy((err: BusinessError) => {
  if (err) {
    console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Destroy : SUCCESS `);
  }
});
```

### on('play')<sup>10+</sup>

on(type: 'play', callback: () => void): void

Subscribes to playback started events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'play'** is triggered when the command for starting playback is sent to the session.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                                       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('play', () => {
  console.info(`on play entry`);
});
```

### on('pause')<sup>10+</sup>

on(type: 'pause', callback: () => void): void

Subscribes to playback paused events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'pause'** is triggered when the command for pausing the playback is sent to the session.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('pause', () => {
  console.info(`on pause entry`);
});
```

### on('stop')<sup>10+</sup>

on(type:'stop', callback: () => void): void

Subscribes to playback stopped events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'stop'** is triggered when the command for stopping the playback is sent to the session.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('stop', () => {
  console.info(`on stop entry`);
});
```

### on('playNext')<sup>10+</sup>

on(type:'playNext', callback: () => void): void

Subscribes to playNext command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'playNext'** is triggered when the command for playing the next item is sent to the session.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('playNext', () => {
  console.info(`on playNext entry`);
});
```

### on('playPrevious')<sup>10+</sup>

on(type:'playPrevious', callback: () => void): void

Subscribes to playPrevious command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'playPrevious'** is triggered when the command for playing the previous item sent to the session.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('playPrevious', () => {
  console.info(`on playPrevious entry`);
});
```

### on('fastForward')<sup>10+</sup>

on(type: 'fastForward', callback: (time?: number) => void): void

Subscribes to fastForward command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'fastForward'** is triggered when the command for fast forwarding is sent to the session.|
| callback | callback: (time?: number) => void | Yes  | Callback used for subscription. The **time** parameter in the callback indicates the time to seek to, in seconds.   |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('fastForward', (time?: number) => {
  console.info(`on fastForward entry`);
});
```

### on('rewind')<sup>10+</sup>

on(type:'rewind', callback: (time?: number) => void): void

Subscribes to rewind command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'rewind'** is triggered when the command for rewinding is sent to the session.|
| callback | callback: (time?: number) => void | Yes  | Callback used for subscription. The **time** parameter in the callback indicates the time to seek to, in seconds.     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('rewind', (time?: number) => {
  console.info(`on rewind entry`);
});
```

### on('playFromAssetId')<sup>11+</sup>

on(type:'playFromAssetId', callback: (assetId: number) => void): void

Subscribes to playback events of a given media ID.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'playFromAssetId'** is triggered when the media ID is played.|
| callback | callback: (assetId: number) => void | Yes  | Callback The **assetId** parameter in the callback indicates the media asset ID.     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('playFromAssetId', (assetId: number) => {
  console.info(`on playFromAssetId entry`);
});
```

### off('playFromAssetId')<sup>11+</sup>

off(type: 'playFromAssetId', callback?: (assetId: number) => void): void

Unsubscribes from playback events of a given media ID.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'playFromAssetId'** in this case.|
| callback | callback: (assetId: number) => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('playFromAssetId');
```

### on('seek')<sup>10+</sup>

on(type: 'seek', callback: (time: number) => void): void

Subscribes to seek command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The event **'seek'** is triggered when the seek command is sent to the session.|
| callback | (time: number) => void | Yes  | Callback used for subscription. The **time** parameter in the callback indicates the time to seek to, in milliseconds.                  |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('seek', (time: number) => {
  console.info(`on seek entry time : ${time}`);
});
```

### on('setSpeed')<sup>10+</sup>

on(type: 'setSpeed', callback: (speed: number) => void): void

Subscribes to setSpeed command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type. The event **'setSpeed'** is triggered when the command for setting the playback speed is sent to the session.|
| callback | (speed: number) => void | Yes  | Callback used for subscription. The **speed** parameter in the callback indicates the playback speed.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('setSpeed', (speed: number) => {
  console.info(`on setSpeed speed : ${speed}`);
});
```

### on('setLoopMode')<sup>10+</sup>

on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void

Subscribes to setLoopMode command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                  | Mandatory| Description |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | Yes  | Event type. The event **'setLoopMode'** is triggered when the command for setting the loop mode is sent to the session.|
| callback | (mode: [LoopMode](#loopmode10)) => void | Yes  | Callback used for subscription. The **mode** parameter in the callback indicates the loop mode.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('setLoopMode', (mode: avSession.LoopMode) => {
  console.info(`on setLoopMode mode : ${mode}`);
});
```

### on('toggleFavorite')<sup>10+</sup>

on(type: 'toggleFavorite', callback: (assetId: string) => void): void

Subscribes to toggleFavorite command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                    | Yes  | Event type. The event **'toggleFavorite'** is triggered when the command for favoriting the media asset is sent to the session.|
| callback | (assetId: string) => void | Yes  | Callback used for subscription. The **assetId** parameter in the callback indicates the media asset ID.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('toggleFavorite', (assetId: string) => {
  console.info(`on toggleFavorite mode : ${assetId}`);
});
```

### on('skipToQueueItem')<sup>10+</sup>

on(type: 'skipToQueueItem', callback: (itemId: number) => void): void

Subscribes to the event that indicates an item in the playlist is selected. The session can play the selected item.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                                                     |
| -------- | ------------------------ | ---- | ---------------------------------------------------------------------------------------- |
| type     | string                   | Yes  | Event type. The event **'skipToQueueItem'** is triggered when an item in the playlist is selected.|
| callback | (itemId: number) => void | Yes  | Callback used for subscription. The **itemId** parameter in the callback indicates the ID of the selected item.                                               |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('skipToQueueItem', (itemId: number) => {
  console.info(`on skipToQueueItem id : ${itemId}`);
});
```

### on('handleKeyEvent')<sup>10+</sup>

on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void

Subscribes to key events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'handleKeyEvent'** is triggered when a key event is sent to the session.|
| callback | (event: [KeyEvent](js-apis-keyevent.md)) => void | Yes  | Callback used for subscription. The **event** parameter in the callback indicates the key event.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';

currentAVSession.on('handleKeyEvent', (event: keyEvent.KeyEvent) => {
  console.info(`on handleKeyEvent event : ${event}`);
});

```

### on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void

Subscribes to output device change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The event **'outputDeviceChange'** is triggered when the output device changes.|
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | Yes  | Callback used for subscription. The **device** parameter in the callback indicates the output device information.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {
  console.info(`on outputDeviceChange device : ${device}`);
});
```

### on('commonCommand')<sup>10+</sup>

on(type: 'commonCommand', callback: (command: string, args: {[key: string]: Object}) => void): void

Subscribes to custom control command change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'commonCommand'** is triggered when a custom control command changes.|
| callback | (commonCommand: string, args: {[key:string]: Object}) => void         | Yes  | Callback used for subscription. The **commonCommand** parameter in the callback indicates the name of the changed custom control command, and **args** indicates the parameters carried in the command. The parameters must be the same as those set in **sendCommand**.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import avSession from '@ohos.multimedia.avsession';
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).on('commonCommand', (commonCommand, args) => {
    console.info(`OnCommonCommand, the command is ${commonCommand}, args: ${JSON.stringify(args)}`);
  });
}
```

### off('play')<sup>10+</sup>

off(type: 'play', callback?: () => void): void

Unsubscribes from playback started events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'play'** in this case.|
| callback | callback: () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('play');
```

### off('pause')<sup>10+</sup>

off(type: 'pause', callback?: () => void): void

Unsubscribes from playback paused events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'pause'** in this case.|
| callback | callback: () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('pause');
```

### off('stop')<sup>10+</sup>

off(type: 'stop', callback?: () => void): void

Unsubscribes from playback stopped events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'stop'** in this case.|
| callback | callback: () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('stop');
```

### off('playNext')<sup>10+</sup>

off(type: 'playNext', callback?: () => void): void

Unsubscribes from playNext command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'playNext'** in this case.|
| callback | callback: () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('playNext');
```

### off('playPrevious')<sup>10+</sup>

off(type: 'playPrevious', callback?: () => void): void

Unsubscribes from playPrevious command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'playPrevious'** in this case.|
| callback | callback: () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('playPrevious');
```

### off('fastForward')<sup>10+</sup>

off(type: 'fastForward', callback?: () => void): void

Unsubscribes from fastForward command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'fastForward'** in this case.|
| callback | callback: () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('fastForward');
```

### off('rewind')<sup>10+</sup>

off(type: 'rewind', callback?: () => void): void

Unsubscribes from rewind command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'rewind'** in this case.|
| callback | callback: () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('rewind');
```

### off('seek')<sup>10+</sup>

off(type: 'seek', callback?: (time: number) => void): void

Unsubscribes from seek command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                         |
| -------- | ---------------------- | ---- | ----------------------------------------- |
| type     | string                 | Yes  | Event type, which is **'seek'** in this case.      |
| callback | (time: number) => void | No  | Callback used for unsubscription. The **time** parameter in the callback indicates the time to seek to, in milliseconds.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('seek');
```

### off('setSpeed')<sup>10+</sup>

off(type: 'setSpeed', callback?: (speed: number) => void): void

Unsubscribes from setSpeed command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                          |
| -------- | ----------------------- | ---- | -------------------------------------------|
| type     | string                  | Yes  | Event type, which is **'setSpeed'** in this case.   |
| callback | (speed: number) => void | No  | Callback used for unsubscription. The **speed** parameter in the callback indicates the playback speed.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('setSpeed');
```

### off('setLoopMode')<sup>10+</sup>

off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void

Unsubscribes from setSpeed command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description    |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | Yes  | Event type, which is **'setLoopMode'** in this case.|
| callback | (mode: [LoopMode](#loopmode10)) => void | No  | Callback used for unsubscription. The **mode** parameter in the callback indicates the loop mode.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('setLoopMode');
```

### off('toggleFavorite')<sup>10+</sup>

off(type: 'toggleFavorite', callback?: (assetId: string) => void): void

Unsubscribes from toggleFavorite command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | -------------------------------------------------------- |
| type     | string                    | Yes  | Event type, which is **'toggleFavorite'** in this case.           |
| callback | (assetId: string) => void | No  | Callback used for unsubscription. The **assetId** parameter in the callback indicates the media asset ID.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('toggleFavorite');
```

### off('skipToQueueItem')<sup>10+</sup>

off(type: 'skipToQueueItem', callback?: (itemId: number) => void): void

Unsubscribes from the event that indicates an item in the playlist is selected.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                                                                                                                       |
| -------- | ------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- |
| type     | string                   | Yes  | Event type, which is **'skipToQueueItem'** in this case.                                                                                                         |
| callback | (itemId: number) => void | No  | Callback used for unsubscription. The **itemId** parameter in the callback indicates the ID of the item.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('skipToQueueItem');
```

### off('handleKeyEvent')<sup>10+</sup>

off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void

Unsubscribes from key events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type, which is **'handleKeyEvent'** in this case.            |
| callback | (event: [KeyEvent](js-apis-keyevent.md)) => void | No  | Callback used for unsubscription. The **event** parameter in the callback indicates the key event.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('handleKeyEvent');
```

### off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void

Unsubscribes from playback device change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                     |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type, which is **'outputDeviceChange'** in this case.    |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | No  | Callback used for unsubscription. The **device** parameter in the callback indicates the output device information.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('outputDeviceChange');
```


### off('commonCommand')<sup>10+</sup>

off(type: 'commonCommand', callback?: (command: string, args: {[key:string]: Object}) => void): void

Unsubscribes from custom control command change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'commonCommand'** in this case.   |
| callback | (command: string, args: {[key:string]: Object}) => void         | No  | Callback used for unsubscription. The **command** parameter in the callback indicates the name of the changed custom control command, and **args** indicates the parameters carried in the command.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('commonCommand');
```

### on('answer')<sup>11+</sup>

on(type: 'answer', callback: Callback\<void>): void;

Subscribes to call answer events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'answer'** is triggered when a call is answered.|
| callback | Callback\<void>                                               | Yes  | Callback used to return the result.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('answer', () => {
  console.info(`on call answer`);
});
```

### off('answer')<sup>11+</sup>

off(type: 'answer', callback?: Callback\<void>): void;

Unsubscribes from call answer events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'answer'** in this case.|
| callback | Callback\<void>     | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.   |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('answer');
```

### on('hangUp')<sup>11+</sup>

on(type: 'hangUp', callback: Callback\<void>): void;

Subscribes to call hangup events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'hangUp'** is triggered when a call is hung up.|
| callback | Callback\<void>                                               | Yes  | Callback used to return the result.                                            |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('hangUp', () => {
  console.info(`on call hangUp`);
});
```

### off('hangUp')<sup>11+</sup>

off(type: 'hangUp', callback?: Callback\<void>): void;

Unsubscribes from call answer events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'hangUp'** in this case.|
| callback | Callback\<void>      | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('hangUp');
```

### on('toggleCallMute')<sup>11+</sup>

on(type: 'toggleCallMute', callback: Callback\<void>): void;

Subscribes to call mute events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'toggleCallMute'** is triggered when a call is muted or unmuted.|
| callback | Callback\<void>                                               | Yes  | Callback used to return the result.                                            |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('toggleCallMute', () => {
  console.info(`on call toggleCallMute`);
});
```

### off('toggleCallMute')<sup>11+</sup>

off(type: 'toggleCallMute', callback?: Callback\<void>): void;

Unsubscribes from call mute events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type, which is **'toggleCallMute'** in this case.|
| callback | Callback\<void>    | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('toggleCallMute');
```
### stopCasting<sup>10+</sup>

stopCasting(callback: AsyncCallback\<void>): void

Stops castings. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.stopCasting((err: BusinessError) => {
  if (err) {
    console.info(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`stopCasting successfully`);
  }
});
```

### stopCasting<sup>10+</sup>

stopCasting(): Promise\<void>

Stops castings. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If casting stops, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.stopCasting().then(() => {
  console.info(`stopCasting successfully`);
}).catch((err: BusinessError) => {
  console.info(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getOutputDeviceSync<sup>10+</sup>

getOutputDeviceSync(): OutputDeviceInfo

Obtains the output device information. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                           | Description                             |
| ----------------------------------------------- | --------------------------------- |
| [OutputDeviceInfo](#outputdeviceinfo10) | Information about the output device.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID  | Error Message|
|---------| --------------------------------------- |
| 6600101 | Session service exception. |
| 6600102 | The session does not exist. |

**Example**

```ts

try {
  let currentOutputDevice: avSession.OutputDeviceInfo = currentAVSession.getOutputDeviceSync();
} catch (err) {
  console.info(`getOutputDeviceSync error, error code: ${err.code}, error message: ${err.message}`);
}
```

## AVCastControlCommandType<sup>10+</sup>

Enumerates the commands that can be sent by a cast controller.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name           | Type    | Description                    |
| -------------- | ------- | ------------------------------ |
| play           | string  | Play the media.                |
| pause          | string  | Pause the playback.            |
| stop           | string  | Stop the playback.             |
| playNext       | string  | Play the next media asset.     |
| playPrevious   | string  | Play the previous media asset. |
| fastForward    | string  | Fast-forward.                  |
| rewind         | string  | Rewind.                        |
| seek           | numbder | Seek to a playback position.   |
| setSpeed       | number  | Set the playback speed.        |
| setLoopMode    | string  | Set the loop mode.             |
| toggleFavorite | string  | Favorite the media asset.      |
| setVolume      | number  | Set the volume.                |

## AVCastControlCommand<sup>10+</sup>

Defines the command that can be sent by a cast controller.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name      | Type                                                    | Mandatory | Description                        |
| --------- | ------------------------------------------------------- | --------- | ---------------------------------- |
| command   | [AVCastControlCommandType](#avcastcontrolcommandtype10) | Yes       | Command.                           |
| parameter | [LoopMode](#loopmode10) &#124; string &#124; number     | No        | Parameters carried in the command. |

## AVCastController<sup>10+</sup>

After a casting connection is set up, you can call [avSession.getAVCastController](#getavcastcontroller10) to obtain the cast controller. Through the controller, you can query the session ID, send commands and events to a session, and obtain session metadata and playback state information.

### setDisplaySurface<sup>10+</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

Sets the surface ID for playback, which is used at the cast receiver (sink). This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Return value**

| Type           | Description                        |
| -------------- | ---------------------------------- |
| Promise\<void> | Promise used to return the result. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                             |
| ------- | ----------------------------------------- |
| 6600109 | The remote connection is not established. |

**Example**

```ts
import media from '@ohos.multimedia.media';
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
  console.info(`setDisplaySurface : SUCCESS`);
});
```

### setDisplaySurface<sup>10+</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

Sets the surface ID for playback, which is used at the cast receiver (sink). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name     | Type                 | Mandatory | Description                         |
| -------- | -------------------- | --------- | ----------------------------------- |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                             |
| ------- | ----------------------------------------- |
| 6600109 | The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import media from '@ohos.multimedia.media';
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
    console.info(`setDisplaySurface BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`setDisplaySurface : SUCCESS`);
  }
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

Obtains the remote playback state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                                   | Mandatory | Description                                        |
| -------- | ------------------------------------------------------ | --------- | -------------------------------------------------- |
| callback | AsyncCallback<[[AVPlaybackState](#avplaybackstate10)\> | Yes       | Callback used to return the remote playback state. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message             |
| ------- | ------------------------- |
| 6600101 | Session service exception |

**Example**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.getAVPlaybackState((err: BusinessError, state: avSession.AVPlaybackState) => {
  if (err) {
    console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getAVPlaybackState : SUCCESS`);
  }
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(): Promise\<AVPlaybackState>;

Obtains the remote playback state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Return value**

| Type                                            | Description                                       |
| ----------------------------------------------- | ------------------------------------------------- |
| Promise<[AVPlaybackState](#avplaybackstate10)\> | Promise used to return the remote playback state. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message             |
| ------- | ------------------------- |
| 6600101 | Session service exception |

**Example**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {
  console.info(`getAVPlaybackState : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVCastControlCommand): Promise\<void>

Sends a control command to the session through the controller. This API uses a promise to return the result.


**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name    | Type                                            | Mandatory | Description      |
| ------- | ----------------------------------------------- | --------- | ---------------- |
| command | [AVCastControlCommand](#avcastcontrolcommand10) | Yes       | Command to send. |

**Return value**

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                             |
| ------- | ----------------------------------------- |
| 6600101 | Session service exception.                |
| 6600105 | Invalid session command.                  |
| 6600109 | The remote connection is not established. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avCommand: avSession.AVCastControlCommand = {command:'play'};
// let avCommand = {command:'pause'};
// let avCommand = {command:'stop'};
// let avCommand = {command:'playNext'};
// let avCommand = {command:'playPrevious'};
// let avCommand = {command:'fastForward'};
// let avCommand = {command:'rewind'};
// let avCommand = {command:'seek', parameter:10};
aVCastController.sendControlCommand(avCommand).then(() => {
  console.info(`SendControlCommand successfully`);
}).catch((err: BusinessError) => {
  console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVCastControlCommand, callback: AsyncCallback\<void>): void

Sends a control command to the session through the controller. This API uses an asynchronous callback to return the result.


**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                            | Mandatory | Description                                                  |
| -------- | ----------------------------------------------- | --------- | ------------------------------------------------------------ |
| command  | [AVCastControlCommand](#avcastcontrolcommand10) | Yes       | Command to send.                                             |
| callback | AsyncCallback\<void>                            | Yes       | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                             |
| ------- | ----------------------------------------- |
| 6600101 | Session service exception.                |
| 6600105 | Invalid session command.                  |
| 6600109 | The remote connection is not established. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avCommand: avSession.AVCastControlCommand = {command:'play'};
// let avCommand = {command:'pause'};
// let avCommand = {command:'stop'};
// let avCommand = {command:'playNext'};
// let avCommand = {command:'playPrevious'};
// let avCommand = {command:'fastForward'};
// let avCommand = {command:'rewind'};
// let avCommand = {command:'seek', parameter:10};
aVCastController.sendControlCommand(avCommand, (err: BusinessError) => {
  if (err) {
    console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SendControlCommand successfully`);
  }
});
```

### prepare<sup>10+</sup>

prepare(item: AVQueueItem, callback: AsyncCallback\<void>): void

Prepares for the playback of a media asset, that is, loads and buffers a media asset. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                          | Mandatory | Description                                                  |
| -------- | ----------------------------- | --------- | ------------------------------------------------------------ |
| item     | [AVQueueItem](#avqueueitem10) | Yes       | Attributes of an item in the playlist.                       |
| callback | AsyncCallback\<void>          | Yes       | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                             |
| ------- | ----------------------------------------- |
| 6600101 | Session service exception.                |
| 6600109 | The remote connection is not established. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

// Set playback parameters.
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};
// Prepare for playback. This operation triggers loading and buffering, but not the actual playback.
aVCastController.prepare(playItem, (err: BusinessError) => {
  if (err) {
    console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`prepare successfully`);
  }
});
```


### prepare<sup>10+</sup>

prepare(item: AVQueueItem): Promise\<void>

Prepares for the playback of a media asset, that is, loads and buffers a media asset. This API uses a promise to return the result.


**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name | Type                          | Mandatory | Description                            |
| ---- | ----------------------------- | --------- | -------------------------------------- |
| item | [AVQueueItem](#avqueueitem10) | Yes       | Attributes of an item in the playlist. |

**Return value**

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                             |
| ------- | ----------------------------------------- |
| 6600101 | Session service exception.                |
| 6600109 | The remote connection is not established. |


**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

// Set playback parameters.
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};
// Prepare for playback. This operation triggers loading and buffering, but not the actual playback.
aVCastController.prepare(playItem).then(() => {
  console.info(`prepare successfully`);
}).catch((err: BusinessError) => {
  console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### start<sup>10+</sup>

start(item: AVQueueItem, callback: AsyncCallback\<void>): void

Prepares for the playback of a media asset. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                          | Mandatory | Description                                                  |
| -------- | ----------------------------- | --------- | ------------------------------------------------------------ |
| item     | [AVQueueItem](#avqueueitem10) | Yes       | Attributes of an item in the playlist.                       |
| callback | AsyncCallback\<void>          | Yes       | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                             |
| ------- | ----------------------------------------- |
| 6600101 | Session service exception.                |
| 6600109 | The remote connection is not established. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

// Set playback parameters.
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};

// Start playback.
aVCastController.start(playItem, (err: BusinessError) => {
  if (err) {
    console.error(`start BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`start successfully`);
  }
});

```

### start<sup>10+</sup>

start(item: AVQueueItem): Promise\<void>

Prepares for the playback of a media asset. This API uses a promise to return the result.


**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name | Type                          | Mandatory | Description                            |
| ---- | ----------------------------- | --------- | -------------------------------------- |
| item | [AVQueueItem](#avqueueitem10) | Yes       | Attributes of an item in the playlist. |

**Return value**

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                             |
| ------- | ----------------------------------------- |
| 6600101 | Session service exception.                |
| 6600109 | The remote connection is not established. |


**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

// Set playback parameters.
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};
// Start playback.
aVCastController.start(playItem).then(() => {
  console.info(`start successfully`);
}).catch((err: BusinessError) => {
  console.info(`start BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getCurrentItem<sup>10+</sup>

getCurrentItem(callback: AsyncCallback\<AVQueueItem>): void

Obtains the information about the media asset that is being played. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                          | Mandatory | Description                                                  |
| -------- | --------------------------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVQueueItem](#avqueueitem10)> | Yes       | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.getCurrentItem((err: BusinessError, value: avSession.AVQueueItem) => {
  if (err) {
    console.error(`getCurrentItem BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getCurrentItem successfully`);
  }
});

```

### getCurrentItem<sup>10+</sup>

getCurrentItem(): Promise\<AVQueueItem>

Obtains the information about the media asset that is being played. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Return value**

| Type                                    | Description                                                  |
| --------------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVQueueItem](#avqueueitem10)> | Promise used to return the media asset obtained. If the operation fails, an error object is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.getCurrentItem().then((value: avSession.AVQueueItem) => {
  console.info(`getCurrentItem successfully`);
}).catch((err: BusinessError) => {
  console.error(`getCurrentItem BusinessError: code: ${err.code}, message: ${err.message}`);
});


```

### release<sup>11+</sup>

release(callback: AsyncCallback\<void>): void

Releases this cast controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the controller is released, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.release((err: BusinessError) => {
  if (err) {
    console.error(`release BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`release successfully`);
  }
});

```

### release<sup>11+</sup>

release(): Promise\<void>

Releases this cast controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Return value**

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the controller is released, no value is returned; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.release().then(() => {
  console.info(`release successfully`);
}).catch((err: BusinessError) => {
  console.error(`release BusinessError: code: ${err.code}, message: ${err.message}`);
});


```

### on('playbackStateChange')<sup>10+</sup>

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void): void

Subscribes to playback state change events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The event **'playbackStateChange'** is triggered when the playback state changes. |
| filter   | Array\<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>&nbsp;&#124;&nbsp;'all' | Yes       | The value **'all'** indicates that any playback state field change will trigger the event, and **Array<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>** indicates that only changes to the listed playback state field will trigger the event. |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void       | Yes       | Callback used for subscription. The **state** parameter in the callback indicates the changed playback state. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.on('playbackStateChange', 'all', (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});

let playbackFilter = ['state', 'speed', 'loopMode'];
aVCastController.on('playbackStateChange', playbackFilter, (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});

```

### off('playbackStateChange')<sup>10+</sup>

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void): void

Unsubscribes from playback state change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                                   | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                 | Yes       | Event type, which is **'playbackStateChange'** in this case. |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void | No        | Callback used for unsubscription. The **state** parameter in the callback indicates the changed playback state.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.off('playbackStateChange');

```

### on('mediaItemChange')<sup>10+</sup>

on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void

Subscribes to media asset change events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                           | Mandatory | Description                                                  |
| -------- | ---------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                         | Yes       | Event type. The event **'mediaItemChange'** is triggered when the media content being played changes. |
| callback | (state: [AVQueueItem](#avqueueitem10)) => void | Yes       | Callback used for subscription. **AVQueueItem** is the media asset that is being played. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.on('mediaItemChange', (item: avSession.AVQueueItem) => {
  console.info(`on mediaItemChange state : ${item.itemId}`);
});

```

### off('mediaItemChange')<sup>10+</sup>

off(type: 'mediaItemChange'): void

Unsubscribes from media asset change events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name | Type   | Mandatory | Description                                              |
| ---- | ------ | --------- | -------------------------------------------------------- |
| type | string | Yes       | Event type, which is **'mediaItemChange'** in this case. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.off('mediaItemChange');

```

### on('playNext')<sup>10+</sup>

on(type: 'playNext', callback: Callback\<void>): void

Subscribes to playNext command events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type             | Mandatory | Description                                                  |
| -------- | ---------------- | --------- | ------------------------------------------------------------ |
| type     | string           | Yes       | Event type. The event **'playNext'** is triggered when the command for playing the next item is received. |
| callback | Callback\<void\> | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.on('playNext', () => {
  console.info(`on playNext`);
});

```

### off('playNext')<sup>10+</sup>

off(type: 'playNext'): void

Unsubscribes from playNext command events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name | Type   | Mandatory | Description                                       |
| ---- | ------ | --------- | ------------------------------------------------- |
| type | string | Yes       | Event type, which is **'playNext'** in this case. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.off('playNext');

```

### on('playPrevious')<sup>10+</sup>

on(type: 'playPrevious', callback: Callback\<void>): void

Subscribes to playPrevious command events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type             | Mandatory | Description                                                  |
| -------- | ---------------- | --------- | ------------------------------------------------------------ |
| type     | string           | Yes       | Event type. The event **'playPrevious'** is triggered when the command for playing the previous event is received. |
| callback | Callback\<void\> | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.on('playPrevious', () => {
  console.info(`on playPrevious`);
});

```

### off('playPrevious')<sup>10+</sup>

off(type: 'playPrevious'): void

Unsubscribes from playPrevious command events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name | Type   | Mandatory | Description                                           |
| ---- | ------ | --------- | ----------------------------------------------------- |
| type | string | Yes       | Event type, which is **'playPrevious'** in this case. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.off('playPrevious');

```

### on('requestPlay')<sup>11+</sup>

on(type: 'requestPlay', callback: Callback\<AVQueueItem>): void

Subscribes to playback request events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                           | Mandatory | Description                                                  |
| -------- | ---------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                         | Yes       | Event type. The event **'requestPlay'** is triggered when a playback request is received. |
| callback | (state: [AVQueueItem](#avqueueitem10)) => void | Yes       | Callback used for subscription. **AVQueueItem** is the media asset that is being played. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.on('requestPlay', (item: avSession.AVQueueItem) => {
  console.info(`on requestPlay state : ${item.itemId}`);
});

```

### off('requestPlay')<sup>11+</sup>

off(type: 'requestPlay', callback?: Callback\<AVQueueItem>): void

Unsubscribes from playback request events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                           | Mandatory | Description                                                  |
| -------- | ---------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                         | Yes       | Event type, which is **'requestPlay'** in this case.         |
| callback | (state: [AVQueueItem](#avqueueitem10)) => void | No        | Callback used for unsubscription. **AVQueueItem** is the media asset that is being played. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.off('requestPlay');

```

### on('endOfStream')<sup>11+</sup>

on(type: 'endOfStream', callback: Callback\<void>): void

Subscribes to playback end events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type             | Mandatory | Description                                                  |
| -------- | ---------------- | --------- | ------------------------------------------------------------ |
| type     | string           | Yes       | Event type. The event **'endOfStream'** is triggered when the playback operation is complete. |
| callback | Callback\<void\> | Yes       | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.on('endOfStream', () => {
  console.info(`on endOfStream`);
});

```

### off('endOfStream')<sup>11+</sup>

off(type: 'endOfStream', callback?: Callback\<void>): void

Unsubscribes from the playback end events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type             | Mandatory | Description                                                  |
| -------- | ---------------- | --------- | ------------------------------------------------------------ |
| type     | string           | Yes       | Event type, which is **'endOfStream'** in this case.         |
| callback | Callback\<void\> | No        | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.off('endOfStream');

```

### on('seekDone')<sup>10+</sup>

on(type: 'seekDone', callback: Callback\<number>): void

Subscribes to seek done events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type               | Mandatory | Description                                                  |
| -------- | ------------------ | --------- | ------------------------------------------------------------ |
| type     | string             | Yes       | Event type. The event **'seekDone'** is triggered when the seek operation is complete. |
| callback | Callback\<number\> | Yes       | Callback used to return the position after the seek operation. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.on('seekDone', (pos: number) => {
  console.info(`on seekDone pos: ${pos} `);
});

```

### off('seekDone')<sup>10+</sup>

off(type: 'seekDone'): void

Unsubscribes from the seek done events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name | Type   | Mandatory | Description                                       |
| ---- | ------ | --------- | ------------------------------------------------- |
| type | string | Yes       | Event type, which is **'seekDone'** in this case. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.off('seekDone');

```

### on('validCommandChange')<sup>11+</sup>

on(type: 'validCommandChange', callback: Callback\<Array\<AVCastControlCommandType>>)

Subscribes to valid command change events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The event **'validCommandChange'** is triggered when the valid commands supported by the session changes. |
| callback | Callback<Array<[AVCastControlCommandType](#avcastcontrolcommandtype10)\>\> | Yes       | Callback used for subscription. The **commands** parameter in the callback is a set of valid commands. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
aVCastController.on('validCommandChange', (validCommands: avSession.AVCastControlCommandType[]) => {
  console.info(`validCommandChange : SUCCESS : size : ${validCommands.length}`);
  console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});

```

### off('validCommandChange')<sup>11+</sup>

off(type: 'validCommandChange', callback?: Callback\<Array\<AVCastControlCommandType>>)

Unsubscribes from valid command change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type, which is **'validCommandChange'** in this case.  |
| callback | Callback<Array<[AVCastControlCommandType](#avcastcontrolcommandtype10)\>\> | No        | Callback used for unsubscription. The **commands** parameter in the callback is a set of valid commands.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
aVCastController.off('validCommandChange');

```

### on('videoSizeChange')<sup>10+</sup>

on(type: 'videoSizeChange', callback: (width:number, height:number) => void): void

Subscribes to video size change events.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name     | Type                                  | Mandatory | Description                                                  |
| -------- | ------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                | Yes       | Event type. The event **'videoSizeChange'** is triggered when the video size changes. |
| callback | (width:number, height:number) => void | Yes       | Callback used to return the video width and height.          |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.on('videoSizeChange', (width: number, height: number) => {
  console.info(`width : ${width} `);
  console.info(`height: ${height} `);
});

```

### off('videoSizeChange')<sup>10+</sup>

off(type: 'videoSizeChange'): void

Unsubscribes from video size changes.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**System API**: This is a system API.

**Parameters**

| Name | Type   | Mandatory | Description                                              |
| ---- | ------ | --------- | -------------------------------------------------------- |
| type | string | Yes       | Event type, which is **'videoSizeChange'** in this case. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.off('videoSizeChange');

```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to remote AVPlayer errors. This event is used only for error prompt and does not require the user to stop playback control.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name     | Type     | Mandatory | Description                                                  |
| -------- | -------- | --------- | ------------------------------------------------------------ |
| type     | string   | Yes       | Event type, which is **'error'** in this case. This event can be triggered by both user operations and the system. |
| callback | function | Yes       | Callback used to return the error code ID and error message. |

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 5400101 | No memory.                 |
| 5400102 | Operation not allowed.     |
| 5400103 | I/O error.                 |
| 5400104 | Time out.                  |
| 5400105 | Service died.              |
| 5400106 | Unsupport format.          |
| 6600101 | Session service exception. |

**Example**

```ts
import { BusinessError } from '@ohos.base'

aVCastController.on('error', (error: BusinessError) => {
  console.error('error happened,and error message is :' + error.message)
  console.error('error happened,and error code is :' + error.code)
})

```

### off('error')<sup>10+</sup>

off(type: 'error'): void

Unsubscribes from remote AVPlayer errors.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name | Type   | Mandatory | Description                                    |
| ---- | ------ | --------- | ---------------------------------------------- |
| type | string | Yes       | Event type, which is **'error'** in this case. |

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID      | Error Message              |
| ------- | -------------------------- |
| 5400101 | No memory.                 |
| 5400102 | Operation not allowed.     |
| 5400103 | I/O error.                 |
| 5400104 | Time out.                  |
| 5400105 | Service died.              |
| 5400106 | Unsupport format.          |
| 6600101 | Session service exception. |

**Example**

```ts
aVCastController.off('error')

```

## ConnectionState<sup>10+</sup>

Enumerates the connection states.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name               | Value | Description                 |
| ------------------ | ----- | --------------------------- |
| STATE_CONNECTING   | 0     | The device is connecting.   |
| STATE_CONNECTED    | 1     | The device is connected.    |
| STATE_DISCONNECTED | 6     | The device is disconnected. |

## AVMetadata<sup>10+</sup>

Describes the media metadata.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                        | Type                                                         | Mandatory | Description                                                  |
| --------------------------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| assetId                     | string                                                       | Yes       | Media asset ID.                                              |
| title                       | string                                                       | No        | Title.                                                       |
| artist                      | string                                                       | No        | Artist.                                                      |
| author                      | string                                                       | No        | Author.                                                      |
| avQueueName<sup>11+</sup>   | string                                                       | No        | Playlist name.<br>This is a system API.<br>                  |
| avQueueId<sup>11+</sup>     | string                                                       | No        | Unique ID of the playlist.                                   |
| avQueueImage<sup>11+</sup>  | image.PixelMap[image.PixelMap](js-apis-image.md#pixelmap7) &#124; string | No        | Cover image of the playlist, which can be pixel data of an image or an image path (local path or Internet path). |
| album                       | string                                                       | No        | Album name.                                                  |
| writer                      | string                                                       | No        | Writer.                                                      |
| composer                    | string                                                       | No        | composer.                                                    |
| duration                    | number                                                       | No        | Media duration, in ms.                                       |
| mediaImage                  | image.PixelMap &#124; string                                 | No        | Pixel map or image path (local path or network path) of the image. |
| publishDate                 | Date                                                         | No        | Release date.                                                |
| subtitle                    | string                                                       | No        | Subtitle.                                                    |
| description                 | string                                                       | No        | Media description.                                           |
| lyric                       | string                                                       | No        | Lyric file path (local path or network path).                |
| previousAssetId             | string                                                       | No        | ID of the previous media asset.                              |
| nextAssetId                 | string                                                       | No        | ID of the next media asset.                                  |
| filter<sup>11+</sup>        | number                                                       | No        | Protocol supported by the media session. The default value is **TYPE_CAST_PLUS_STREAM**. For details, see [ProtocolType](#protocoltype10). |
| skipIntervals<sup>11+</sup> | [SkipIntervals](#skipintervals11)                            | No        | Fast-forward or rewind interval supported by the media session. The default value is **SECONDS_15**, that is, 15 seconds. |
| displayTags<sup>11+</sup>   | [DisplayTag](#displaytag11)                                  | No        | Display tags of the media asset.                             |

## AVQueueInfo<sup>11+</sup>

Defines the attributes of a playlist.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**System API**: This is a system API.

| Name           | Type                         | Mandatory | Description                                                  |
| -------------- | ---------------------------- | --------- | ------------------------------------------------------------ |
| bundleName     | string                       | Yes       | Bundle name of the application to which the playlist belongs. |
| avQueueName    | string                       | Yes       | Playlist name.                                               |
| avQueueId      | string                       | Yes       | Unique ID of the playlist.                                   |
| avQueueImage   | image.PixelMap &#124; string | Yes       | Cover image of the playlist, which can be pixel data of an image or an image path (local path or Internet path). |
| lastPlayedTime | number                       | No        | Last time when the playlist is played.                       |

## AVMediaDescription<sup>10+</sup>

Describes the attributes related to the media metadata in the playlist.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name            | Type                   | Mandatory | Description                                                  |
| --------------- | ---------------------- | --------- | ------------------------------------------------------------ |
| assetId         | string                 | Yes       | Media ID in the playlist.                                    |
| title           | string                 | No        | Name of the media asset in the playlist.                     |
| subtitle        | string                 | No        | Subname of the media asset in the playlist.                  |
| description     | string                 | No        | Description of the media asset in the playlist.              |
| mediaImage      | image.PixelMap         | No        | Pixel map of the image of the media asset in the playlist.   |
| extras          | {[key: string]: any}   | No        | Additional fields of the media asset in the playlist.        |
| mediaUri        | string                 | No        | URI of the media asset in the playlist.                      |
| mediaType       | string                 | No        | Type of the media asset in the playlist.                     |
| mediaSize       | number                 | No        | Size of the media asset in the playlist.                     |
| albumTitle      | string                 | No        | Album name of the media asset in the playlist.               |
| albumCoverUri   | string                 | No        | URI of the album title of the media asset in the playlist.   |
| lyricContent    | string                 | No        | Lyric content of the media asset in the playlist.            |
| lyricUri        | string                 | No        | Lyric URI of the media asset in the playlist.                |
| artist          | string                 | No        | Author of the lyric of the media asset in the playlist.      |
| fdSrc           | media.AVFileDescriptor | No        | Handle to the local media file in the playlist.              |
| duration        | number                 | No        | Playback duration of the media asset in the playlist.        |
| startPosition   | number                 | No        | Start position for playing the media asset in the playlist.  |
| creditsPosition | number                 | No        | Position for playing the closing credits of the media asset in the playlist. |
| appName         | string                 | No        | Name of the application provided by the playlist.            |

## AVQueueItem<sup>10+</sup>

Describes the attributes of an item in the playlist.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name        | Type                                        | Mandatory | Description                                 |
| ----------- | ------------------------------------------- | --------- | ------------------------------------------- |
| itemId      | number                                      | Yes       | ID of an item in the playlist.              |
| description | [AVMediaDescription](#avmediadescription10) | Yes       | Media metadata of the item in the playlist. |

## AVPlaybackState<sup>10+</sup>

Describes the information related to the media playback state.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                       | Type                                  | Mandatory | Description                                            |
| -------------------------- | ------------------------------------- | --------- | ------------------------------------------------------ |
| state                      | [PlaybackState](#playbackstate)       | No        | Playback state.                                        |
| speed                      | number                                | No        | Playback speed.                                        |
| position                   | [PlaybackPosition](#playbackposition) | No        | Playback position.                                     |
| bufferedTime               | number                                | No        | Buffered time.                                         |
| loopMode                   | [LoopMode](#loopmode10)               | No        | Loop mode.                                             |
| isFavorite                 | boolean                               | No        | Whether the media asset is favorited.                  |
| activeItemId<sup>10+</sup> | number                                | No        | ID of the item that is being played.                   |
| volume<sup>10+</sup>       | number                                | No        | Media volume.                                          |
| extras<sup>10+</sup>       | {[key: string]: Object}               | No        | Custom media data.                                     |
| maxVolume<sup>11+</sup>    | number                                | No        | Maximum volume.                                        |
| muted<sup>11+</sup>        | boolean                               | No        | Mute status. The value **true** means the muted state. |
| videoWidth<sup>11+</sup>   | number                                | No        | Video width of the media asset, in pixels.             |
| videoHeight<sup>11+</sup>  | number                                | No        | Video height of the media asset, in pixels.            |

## PlaybackPosition<sup>10+</sup>

Describes the information related to the playback position.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name        | Type   | Mandatory | Description          |
| ----------- | ------ | --------- | -------------------- |
| elapsedTime | number | Yes       | Elapsed time, in ms. |
| updateTime  | number | Yes       | Updated time, in ms. |

## CallMetadata<sup>11+</sup>

Defines the attributes related to call metadata.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name        | Type                                                       | Mandatory | Description                    |
| ----------- | ---------------------------------------------------------- | --------- | ------------------------------ |
| name        | string                                                     | No        | Name (alias) of the caller.    |
| phoneNumber | string                                                     | No        | Phone number of the caller.    |
| avatar      | image.PixelMap[image.PixelMap](js-apis-image.md#pixelmap7) | No        | Profile picture of the caller. |

## AVCallState<sup>11+</sup>

Defines the attributes related to the call state.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name  | Type                                   | Mandatory | Description                      |
| ----- | -------------------------------------- | --------- | -------------------------------- |
| state | CallState[AVCallState](#avcallstate11) | Yes       | Call state.                      |
| muted | boolean                                | Yes       | Whether the microphone is muted. |

## CallState<sup>11+</sup>

Enumerates the call states.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                     | Value | Description                         |
| ------------------------ | ----- | ----------------------------------- |
| CALL_STATE_IDLE          | 0     | The phone is idle.                  |
| CALL_STATE_INCOMING      | 1     | The phone is ringing.               |
| CALL_STATE_ACTIVE        | 2     | The call is connected.              |
| CALL_STATE_DIALING       | 3     | The caller is dialing.              |
| CALL_STATE_WAITING       | 4     | The call is waiting for connection. |
| CALL_STATE_HOLDING       | 5     | The call is placed on hold.         |
| CALL_STATE_DISCONNECTING | 6     | The call is disconnecting.          |

## DisplayTag<sup>11+</sup>

Enumerates the display tags of the media asset, which is a special type identifier of the media audio source.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name            | Value | Description |
| --------------- | ----- | ----------- |
| TAG_AUDIO_VIVID | 1     | AUDIO VIVID |

## AVCastCategory<sup>10+</sup>

Enumerates the cast categories.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name            | Value | Description                                                  |
| --------------- | ----- | ------------------------------------------------------------ |
| CATEGORY_LOCAL  | 0     | Local playback. The sound is played from the local device or a connected Bluetooth headset by default. |
| CATEGORY_REMOTE | 1     | Remote playback. The sound or images are played from a remote device. |

## DeviceType<sup>10+</sup>

Enumerates the output device types.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                      | Value | Description                                                  |
| ------------------------- | ----- | ------------------------------------------------------------ |
| DEVICE_TYPE_LOCAL         | 0     | Local device.                                                |
| DEVICE_TYPE_BLUETOOTH     | 10    | Bluetooth device.                                            |
| DEVICE_TYPE_TV            | 2     | TV.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast |
| DEVICE_TYPE_SMART_SPEAKER | 3     | Speaker.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast |

## DeviceInfo<sup>10+</sup>

Describes the information related to the output device.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                               | Type           | Mandatory | Description                                                  |
| ---------------------------------- | -------------- | --------- | ------------------------------------------------------------ |
| castCategory                       | AVCastCategory | Yes       | Cast category.                                               |
| deviceId                           | string         | Yes       | ID of the output device.                                     |
| deviceName                         | string         | Yes       | Name of the output device.                                   |
| deviceType                         | DeviceType     | Yes       | Type of the output device.                                   |
| ipAddress                          | string         | No        | IP address of the output device.<br>This is a system API.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast |
| providerId                         | number         | No        | Vendor of the output device.<br>This is a system API.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast |
| supportedProtocols<sup>11+</sup>   | number         | No        | Protocol supported by the output device. The default value is **TYPE_LOCAL**. For details, see [ProtocolType](#protocoltype10). **System capability**: SystemCapability.Multimedia.AVSession.AVCast |
| authenticationStatus<sup>11+</sup> | number         | No        | Whether the output device is trusted. The default value is **0**, indicating that the device is untrusted. The value **1** means that the device is trusted.<br>This is a system API.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast |

## OutputDeviceInfo<sup>10+</sup>

Describes the information related to the output device.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name    | Type                | Mandatory | Description     |
| ------- | ------------------- | --------- | --------------- |
| devices | Array\<DeviceInfo\> | Yes       | Output devices. |

## LoopMode<sup>10+</sup>

Enumerates the loop modes of media playback.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                           | Value | Description          |
| ------------------------------ | ----- | -------------------- |
| LOOP_MODE_SEQUENCE             | 0     | Sequential playback. |
| LOOP_MODE_SINGLE               | 1     | Single loop.         |
| LOOP_MODE_LIST                 | 2     | Playlist loop.       |
| LOOP_MODE_SHUFFLE              | 3     | Shuffle.             |
| LOOP_MODE_CUSTOM<sup>11+</sup> | 4     | Custom playback.     |

## PlaybackState<sup>10+</sup>

Enumerates the media playback states.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                                   | Value | Description        |
| -------------------------------------- | ----- | ------------------ |
| PLAYBACK_STATE_INITIAL                 | 0     | Initial.           |
| PLAYBACK_STATE_PREPARE                 | 1     | Preparing.         |
| PLAYBACK_STATE_PLAY                    | 2     | Playing.           |
| PLAYBACK_STATE_PAUSE                   | 3     | Paused.            |
| PLAYBACK_STATE_FAST_FORWARD            | 4     | Fast-forwarding.   |
| PLAYBACK_STATE_REWIND                  | 5     | Rewinding.         |
| PLAYBACK_STATE_STOP                    | 6     | Stop the playback. |
| PLAYBACK_STATE_COMPLETED               | 7     | Playback complete. |
| PLAYBACK_STATE_RELEASED                | 8     | Released.          |
| PLAYBACK_STATE_ERROR                   | 9     | Error.             |
| PLAYBACK_STATE_IDLE<sup>11+</sup>      | 10    | Idle.              |
| PLAYBACK_STATE_BUFFERING<sup>11+</sup> | 11    | Buffering.         |

## AVSessionDescriptor

Declares the session descriptor.

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

| Name         | Type                                         | Readable | Writable | Description                                                  |
| ------------ | -------------------------------------------- | -------- | -------- | ------------------------------------------------------------ |
| sessionId    | string                                       | Yes      | No       | Session ID.                                                  |
| type         | [AVSessionType](#avsessiontype10)            | Yes      | No       | Session type.                                                |
| sessionTag   | string                                       | Yes      | No       | Custom session name.                                         |
| elementName  | [ElementName](js-apis-bundle-ElementName.md) | Yes      | No       | Information about the application to which the session belongs, including the bundle name and ability name. |
| isActive     | boolean                                      | Yes      | No       | Whether the session is activated.                            |
| isTopSession | boolean                                      | Yes      | No       | Whether the session is the top session.                      |
| outputDevice | [OutputDeviceInfo](#outputdeviceinfo10)      | Yes      | No       | Information about the output device.                         |

## AVSessionController<sup>10+</sup>

An AV session controller is created by calling [avSession.createController](#avsessioncreatecontroller). Through the controller, you can query the session ID, send commands and events to a session, and obtain session metadata and playback state information.

### Attributes

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name      | Type   | Readable | Writable | Description                                              |
| :-------- | :----- | :------- | :------- | :------------------------------------------------------- |
| sessionId | string | Yes      | No       | Unique session ID of the **AVSessionController** object. |


**Example**

```ts
import { BusinessError } from '@ohos.base';

let AVSessionController: avSession.AVSessionController;
avSession.createController(currentAVSession.sessionId).then((controller: avSession.AVSessionController) => {
  AVSessionController = controller;
}).catch((err: BusinessError) => {
  console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

Obtains the remote playback state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                   | Mandatory | Description                                        |
| -------- | ------------------------------------------------------ | --------- | -------------------------------------------------- |
| callback | AsyncCallback<[[AVPlaybackState](#avplaybackstate10)\> | Yes       | Callback used to return the remote playback state. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVPlaybackState((err: BusinessError, state: avSession.AVPlaybackState) => {
  if (err) {
    console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getAVPlaybackState : SUCCESS`);
  }
});

```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(): Promise\<AVPlaybackState>;

Obtains the remote playback state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                            | Description                                       |
| ----------------------------------------------- | ------------------------------------------------- |
| Promise<[AVPlaybackState](#avplaybackstate10)\> | Promise used to return the remote playback state. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {
  console.info(`getAVPlaybackState : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getAVMetadata<sup>10+</sup>

getAVMetadata(): Promise\<AVMetadata>

Obtains the session metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                  | Description                                   |
| ------------------------------------- | --------------------------------------------- |
| Promise<[AVMetadata](#avmetadata10)\> | Promise used to return the metadata obtained. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVMetadata().then((metadata: avSession.AVMetadata) => {
  console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getAVMetadata<sup>10+</sup>

getAVMetadata(callback: AsyncCallback\<AVMetadata>): void

Obtains the session metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                        | Mandatory | Description                                    |
| -------- | ------------------------------------------- | --------- | ---------------------------------------------- |
| callback | AsyncCallback<[AVMetadata](#avmetadata10)\> | Yes       | Callback used to return the metadata obtained. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVMetadata((err: BusinessError, metadata: avSession.AVMetadata) => {
  if (err) {
    console.error(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
  }
});

```

### getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(): Promise\<string>

Obtains the name of the playlist. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type             | Description                               |
| ---------------- | ----------------------------------------- |
| Promise<string\> | Promise used to return the playlist name. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVQueueTitle().then((title: string) => {
  console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(callback: AsyncCallback\<string>): void

Obtains the name of the playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                   | Mandatory | Description                                |
| -------- | ---------------------- | --------- | ------------------------------------------ |
| callback | AsyncCallback<string\> | Yes       | Callback used to return the playlist name. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVQueueTitle((err: BusinessError, title: string) => {
  if (err) {
    console.error(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);
  }
});

```

### getAVQueueItems<sup>10+</sup>

getAVQueueItems(): Promise\<Array\<AVQueueItem>>

Obtains the information related to the items in the queue. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                            | Description                                    |
| ----------------------------------------------- | ---------------------------------------------- |
| Promise<Array<[AVQueueItem](#avqueueitem10)\>\> | Promise used to return the items in the queue. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVQueueItems().then((items: avSession.AVQueueItem[]) => {
  console.info(`GetAVQueueItems : SUCCESS : length : ${items.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getAVQueueItems<sup>10+</sup>

getAVQueueItems(callback: AsyncCallback\<Array\<AVQueueItem>>): void

Obtains the information related to the items in the playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                  | Mandatory | Description                                        |
| -------- | ----------------------------------------------------- | --------- | -------------------------------------------------- |
| callback | AsyncCallback<Array<[AVQueueItem](#avqueueitem10)\>\> | Yes       | Callback used to return the items in the playlist. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVQueueItems((err: BusinessError, items: avSession.AVQueueItem[]) => {
  if (err) {
    console.error(`GetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAVQueueItems : SUCCESS : length : ${items.length}`);
  }
});

```

### skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number): Promise\<void>

Sends the ID of an item in the playlist to the session for processing. The session can play the song. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type   | Mandatory | Description                    |
| ------ | ------ | --------- | ------------------------------ |
| itemId | number | Yes       | ID of an item in the playlist. |

**Return value**

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the item ID is sent, no value is returned; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let queueItemId = 0;
avsessionController.skipToQueueItem(queueItemId).then(() => {
  console.info(`SkipToQueueItem successfully`);
}).catch((err: BusinessError) => {
  console.error(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void

Sends the ID of an item in the playlist to the session for processing. The session can play the song. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| itemId   | number               | Yes       | ID of an item in the playlist.                               |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let queueItemId = 0;
avsessionController.skipToQueueItem(queueItemId, (err: BusinessError) => {
  if (err) {
    console.error(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SkipToQueueItem successfully`);
  }
});

```

### getOutputDevice<sup>10+</sup>

getOutputDevice(): Promise\<OutputDeviceInfo>

Obtains the output device information. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                              | Description                                      |
| ------------------------------------------------- | ------------------------------------------------ |
| Promise<[OutputDeviceInfo](#outputdeviceinfo10)\> | Promise used to return the information obtained. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID     | Error Message                          |
| ------ | -------------------------------------- |
| 600101 | Session service exception.             |
| 600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getOutputDevice().then((deviceInfo: avSession.OutputDeviceInfo) => {
  console.info(`GetOutputDevice : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getOutputDevice<sup>10+</sup>

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

Obtains the output device information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                       |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------- |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo10)\> | Yes       | Callback used to return the information obtained. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID     | Error Message                          |
| ------ | -------------------------------------- |
| 600101 | Session service exception.             |
| 600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getOutputDevice((err: BusinessError, deviceInfo: avSession.OutputDeviceInfo) => {
  if (err) {
    console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetOutputDevice : SUCCESS`);
  }
});

```

### sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent): Promise\<void>

Sends a key event to the session corresponding to this controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                            | Mandatory | Description |
| ----- | ------------------------------- | --------- | ----------- |
| event | [KeyEvent](js-apis-keyevent.md) | Yes       | Key event.  |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID     | Error Message                          |
| ------ | -------------------------------------- |
| 600101 | Session service exception.             |
| 600102 | The session does not exist.            |
| 600103 | The session controller does not exist. |
| 600105 | Invalid session command.               |
| 600106 | The session is not activated.          |

**Return value**

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the event is sent, no value is returned; otherwise, an error object is returned. |

**Example**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';
import { BusinessError } from '@ohos.base';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avsessionController.sendAVKeyEvent(event).then(() => {
  console.info(`SendAVKeyEvent Successfully`);
}).catch((err: BusinessError) => {
  console.error(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

Sends a key event to the session corresponding to this controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                            | Mandatory | Description                                                  |
| -------- | ------------------------------- | --------- | ------------------------------------------------------------ |
| event    | [KeyEvent](js-apis-keyevent.md) | Yes       | Key event.                                                   |
| callback | AsyncCallback\<void>            | Yes       | Callback used to return the result. If the event is sent, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID     | Error Message                          |
| ------ | -------------------------------------- |
| 600101 | Session service exception.             |
| 600102 | The session does not exist.            |
| 600103 | The session controller does not exist. |
| 600105 | Invalid session command.               |
| 600106 | The session is not activated.          |

**Example**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';
import { BusinessError } from '@ohos.base';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avsessionController.sendAVKeyEvent(event, (err: BusinessError) => {
  if (err) {
    console.error(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SendAVKeyEvent Successfully`);
  }
});

```

### getLaunchAbility<sup>10+</sup>

getLaunchAbility(): Promise\<WantAgent>

Obtains the **WantAgent** object saved by the application in the session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                    | Description                                                  |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[WantAgent](js-apis-app-ability-wantAgent.md)\> | Promise used to return the object saved by calling [setLaunchAbility](#setlaunchability10). The object includes the application attribute, such as the bundle name, ability name, and device ID. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getLaunchAbility().then((agent: object) => {
  console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
}).catch((err: BusinessError) => {
  console.error(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getLaunchAbility<sup>10+</sup>

getLaunchAbility(callback: AsyncCallback\<WantAgent>): void

Obtains the **WantAgent** object saved by the application in the session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback<[WantAgent](js-apis-app-ability-wantAgent.md)\> | Yes       | Callback used to return the object saved by calling [setLaunchAbility](#setlaunchability10). The object includes the application attribute, such as the bundle name, ability name, and device ID. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getLaunchAbility((err: BusinessError, agent: object) => {
  if (err) {
    console.error(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
  }
});

```

### getRealPlaybackPositionSync<sup>10+</sup>

getRealPlaybackPositionSync(): number

Obtains the playback position.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type   | Description                         |
| ------ | ----------------------------------- |
| number | Playback position, in milliseconds. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
let time: number = avsessionController.getRealPlaybackPositionSync();

```

### isActive<sup>10+</sup>

isActive(): Promise\<boolean>

Checks whether the session is activated. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| Promise<boolean\> | Promise used to return the activation state. If the session is activated, **true** is returned; otherwise, **false** is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.isActive().then((isActive: boolean) => {
  console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
}).catch((err: BusinessError) => {
  console.error(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### isActive<sup>10+</sup>

isActive(callback: AsyncCallback\<boolean>): void

Checks whether the session is activated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                    | Mandatory | Description                                                  |
| -------- | ----------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback<boolean\> | Yes       | Callback used to return the activation state. If the session is activated, **true** is returned; otherwise, **false** is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.isActive((err: BusinessError, isActive: boolean) => {
  if (err) {
    console.error(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
  }
});

```

### destroy<sup>10+</sup>

destroy(): Promise\<void>

Destroys this controller. A controller can no longer be used after being destroyed. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the controller is destroyed, no value is returned; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.destroy().then(() => {
  console.info(`Destroy : SUCCESS `);
}).catch((err: BusinessError) => {
  console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### destroy<sup>10+</sup>

destroy(callback: AsyncCallback\<void>): void

Destroys this controller. A controller can no longer be used after being destroyed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the controller is destroyed, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.destroy((err: BusinessError) => {
  if (err) {
    console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Destroy : SUCCESS `);
  }
});

```

### getValidCommands<sup>10+</sup>

getValidCommands(): Promise\<Array\<AVControlCommandType>>

Obtains valid commands supported by the session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                         | Description                                     |
| ------------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[AVControlCommandType](#avcontrolcommandtype10)\>\> | Promise used to return a set of valid commands. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getValidCommands().then((validCommands: avSession.AVControlCommandType[]) => {
  console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getValidCommands<sup>10+</sup>

getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void

Obtains valid commands supported by the session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                      |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------ |
| callback | AsyncCallback\<Array\<[AVControlCommandType](#avcontrolcommandtype10)\>\> | Yes       | Callback used to return a set of valid commands. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getValidCommands((err: BusinessError, validCommands: avSession.AVControlCommandType[]) => {
  if (err) {
    console.error(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
  }
});

```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVControlCommand): Promise\<void>

Sends a control command to the session through the controller. This API uses a promise to return the result.

> **NOTE**
>
> Before using **sendControlCommand**, the controller must ensure that the corresponding listeners are registered for the media session. For details about how to register the listeners, see [on'play'](#onplay10), [on'pause'](#onpause10), and the like.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name    | Type                                    | Mandatory | Description      |
| ------- | --------------------------------------- | --------- | ---------------- |
| command | [AVControlCommand](#avcontrolcommand10) | Yes       | Command to send. |

**Return value**

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |
| 6600105 | Invalid session command.               |
| 6600106 | The session is not activated.          |
| 6600107 | Too many commands or events.           |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avCommand: avSession.AVControlCommand = {command:'play'};
// let avCommand = {command:'pause'};
// let avCommand = {command:'stop'};
// let avCommand = {command:'playNext'};
// let avCommand = {command:'playPrevious'};
// let avCommand = {command:'fastForward'};
// let avCommand = {command:'rewind'};
// let avCommand = {command:'seek', parameter:10};
// let avCommand = {command:'setSpeed', parameter:2.6};
// let avCommand = {command:'setLoopMode', parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let avCommand = {command:'toggleFavorite', parameter:"false"};
avsessionController.sendControlCommand(avCommand).then(() => {
  console.info(`SendControlCommand successfully`);
}).catch((err: BusinessError) => {
  console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

Sends a control command to the session through the controller. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Before using **sendControlCommand**, the controller must ensure that the corresponding listeners are registered for the media session. For details about how to register the listeners, see [on'play'](#onplay10), [on'pause'](#onpause10), and the like.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                    | Mandatory | Description                                                  |
| -------- | --------------------------------------- | --------- | ------------------------------------------------------------ |
| command  | [AVControlCommand](#avcontrolcommand10) | Yes       | Command to send.                                             |
| callback | AsyncCallback\<void>                    | Yes       | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |
| 6600105 | Invalid session command.               |
| 6600106 | The session is not activated.          |
| 6600107 | Too many commands or events.           |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avCommand: avSession.AVControlCommand = {command:'play'};
// let avCommand = {command:'pause'};
// let avCommand = {command:'stop'};
// let avCommand = {command:'playNext'};
// let avCommand = {command:'playPrevious'};
// let avCommand = {command:'fastForward'};
// let avCommand = {command:'rewind'};
// let avCommand = {command:'seek', parameter:10};
// let avCommand = {command:'setSpeed', parameter:2.6};
// let avCommand = {command:'setLoopMode', parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let avCommand = {command:'toggleFavorite', parameter:"false"};
avsessionController.sendControlCommand(avCommand, (err: BusinessError) => {
  if (err) {
    console.info(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.error(`SendControlCommand successfully`);
  }
});

```

### sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}): Promise\<void>

Sends a custom control command to the session through the controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name    | Type                 | Mandatory | Description                                                  |
| ------- | -------------------- | --------- | ------------------------------------------------------------ |
| command | string               | Yes       | Name of the custom control command.                          |
| args    | {[key: string]: any} | Yes       | Parameters in key-value pair format carried in the custom control command. |

> **NOTE**
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want (Want)](./js-apis-app-ability-want.md).

**Return value**

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |
| 6600105 | Invalid session command.               |
| 6600106 | The session is not activated.          |
| 6600107 | Too many commands or events.           |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  sessionId = (currentAVSession as avSession.AVSession).sessionId;
  avSession.createController(sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

let commandName = "my_command";
if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}).then(() => {
    console.info(`SendCommonCommand successfully`);
  }).catch((err: BusinessError) => {
    console.info(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}

```

### sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void

Sends a custom control command to the session through the controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| command  | string               | Yes       | Name of the custom control command.                          |
| args     | {[key: string]: any} | Yes       | Parameters in key-value pair format carried in the custom control command. |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object. |

> **NOTE**
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want (Want)](./js-apis-app-ability-want.md).

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |
| 6600105 | Invalid session command.               |
| 6600106 | The session is not activated.          |
| 6600107 | Too many commands or events.           |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';
let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

let commandName = "my_command";
if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}, (err: BusinessError) => {
    if(err) {
        console.info(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
    }
  })
}

```

### getExtras<sup>10+</sup>

getExtras(): Promise\<{[key: string]: Object}>

Obtains the custom media packet set by the provider. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                              | Description                                                  |
| --------------------------------- | ------------------------------------------------------------ |
| Promise<{[key: string]: Object}\> | Promise used to return the custom media packet. The content of the packet is the same as that set in **setExtras**. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |
| 6600105 | Invalid session command.               |
| 6600107 | Too many commands or events.           |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).getExtras().then((extras) => {
    console.info(`getExtras : SUCCESS : ${extras}`);
  }).catch((err: BusinessError) => {
    console.info(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

```

### getExtras<sup>10+</sup>

getExtras(callback: AsyncCallback\<{[key: string]: Object}>): void

Obtains the custom media packet set by the provider. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                    | Mandatory | Description                                                  |
| -------- | --------------------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback<{[key: string]: Object}\> | Yes       | Callback used to return the custom media packet. The content of the packet is the same as that set in **setExtras**. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |
| 6600105 | Invalid session command.               |
| 6600107 | Too many commands or events.           |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).getExtras((err, extras) => {
    if (err) {
      console.error(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`getExtras : SUCCESS : ${extras}`);
    }
  });
}

```

### on('metadataChange')<sup>10+</sup>

on(type: 'metadataChange', filter: Array\<keyof AVMetadata> | 'all', callback: (data: AVMetadata) => void)

Subscribes to metadata change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The event **'metadataChange'** is triggered when the session metadata changes. |
| filter   | Array\<keyof&nbsp;[AVMetadata](#avmetadata10)\>&nbsp;&#124;&nbsp;'all' | Yes       | The value **'all'** indicates that any metadata field change will trigger the event, and **Array<keyof&nbsp;[AVMetadata](#avmetadata10)\>** indicates that only changes to the listed metadata field will trigger the event. |
| callback | (data: [AVMetadata](#avmetadata10)) => void                  | Yes       | Callback used for subscription. The **data** parameter in the callback indicates the changed metadata. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('metadataChange', 'all', (metadata: avSession.AVMetadata) => {
  console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

avsessionController.on('metadataChange', ['assetId', 'title', 'description'], (metadata: avSession.AVMetadata) => {
  console.info(`on metadataChange assetId : ${metadata.assetId}`);
});


```

### off('metadataChange')<sup>10+</sup>

off(type: 'metadataChange', callback?: (data: AVMetadata) => void)

Unsubscribes from metadata change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                        | Mandatory | Description                                                  |
| -------- | ------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                      | Yes       | Event type, which is **'metadataChange'** in this case.      |
| callback | (data: [AVMetadata](#avmetadata10)) => void | No        | Callback used for subscription. The **data** parameter in the callback indicates the changed metadata.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('metadataChange');

```

### on('playbackStateChange')<sup>10+</sup>

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void)

Subscribes to playback state change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The event **'playbackStateChange'** is triggered when the playback state changes. |
| filter   | Array\<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>&nbsp;&#124;&nbsp;'all' | Yes       | The value **'all'** indicates that any playback state field change will trigger the event, and **Array<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>** indicates that only changes to the listed playback state field will trigger the event. |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void       | Yes       | Callback used for subscription. The **state** parameter in the callback indicates the changed playback state. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('playbackStateChange', 'all', (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});

avsessionController.on('playbackStateChange', ['state', 'speed', 'loopMode'], (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});

```

### off('playbackStateChange')<sup>10+</sup>

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void)

Unsubscribes from playback state change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                   | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                 | Yes       | Event type, which is **'playbackStateChange'** in this case. |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void | No        | Callback used for unsubscription. The **state** parameter in the callback indicates the changed playback state.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('playbackStateChange');

```

### on('callMetadataChange')<sup>11+</sup>

on(type: 'callMetadataChange', filter: Array\<keyof CallMetadata> | 'all', callback: Callback\<CallMetadata>): void;

Subscribes to call metadata change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The event **'callMetadataChange'** is triggered when the call metadata changes. |
| filter   | Array\<keyof&nbsp;[CallMetadata](#callmetadata11)\>&nbsp;&#124;&nbsp;'all' | Yes       | The value **'all'** indicates that any call metadata field change will trigger the event, and **Array<keyof&nbsp;[CallMetadata](#callmetadata11)\>** indicates that only changes to the listed metadata field will trigger the event. |
| callback | Callback<[CallMetadata](#callmetadata11)\>\>                 | Yes       | Callback used for subscription. The **calldata** parameter in the callback indicates the changed call metadata. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('callMetadataChange', 'all', (callmetadata: avSession.CallMetadata) => {
  console.info(`on callMetadataChange state : ${callmetadata.name}`);
});

avsessionController.on('callMetadataChange', ['name'], (callmetadata: avSession.CallMetadata) => {
  console.info(`on callMetadataChange state : ${callmetadata.state}`);
});

```

### off('callMetadataChange')<sup>11+</sup>

off(type: 'callMetadataChange', callback?: Callback\<CallMetadata>): void;

Unsubscribes from call metadata change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                       | Mandatory | Description                                                  |
| -------- | ------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                     | Yes       | Event type, which is **'callMetadataChange'** in this case.  |
| callback | Callback<[CallMetadata](#callmetadata11)\> | No        | Callback used for unsubscription. The **calldata** parameter in the callback indicates the changed call metadata.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('callMetadataChange');

```

### on('callStateChange')<sup>11+</sup>

on(type: 'callStateChange', filter: Array\<keyof AVCallState> | 'all', callback: Callback\<AVCallState>): void;

Subscribes to call state change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The event **'callStateChange'** is triggered when the call state changes. |
| filter   | Array<keyof&nbsp;[AVCallState](#avcallstate11)\>&nbsp;&#124;&nbsp;'all' | Yes       | The value **'all'** indicates that any call state field change will trigger the event, and **Array<keyof&nbsp;[AVCallState](#avcallstate11)\>** indicates that only changes to the listed call state field will trigger the event. |
| callback | Callback<[AVCallState](#avcallstate11)\>                     | Yes       | Callback used for subscription. The **callstate** parameter in the callback indicates the changed call state. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('callStateChange', 'all', (callstate: avSession.AVCallState) => {
  console.info(`on callStateChange state : ${callstate.state}`);
});

avsessionController.on('callStateChange', ['state'], (callstate: avSession.AVCallState) => {
  console.info(`on callStateChange state : ${callstate.state}`);
});

```

### off('callStateChange')<sup>11+</sup>

off(type: 'callStateChange', callback?: Callback\<AVCallState>): void;

Unsubscribes from call state change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                     | Mandatory | Description                                                  |
| -------- | ---------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                   | Yes       | Event type, which is **'callStateChange'** in this case.  |
| callback | Callback<[AVCallState](#avcallstate11)\> | No        | Callback used for unsubscription. The **callstate** parameter in the callback indicates the changed call state.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('callMetadataChange');

```

### on('sessionDestroy')<sup>10+</sup>

on(type: 'sessionDestroy', callback: () => void)

Subscribes to session destruction events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type       | Mandatory | Description                                                  |
| -------- | ---------- | --------- | ------------------------------------------------------------ |
| type     | string     | Yes       | Event type. The event **'sessionDestroy'** is triggered when a session is destroyed. |
| callback | () => void | Yes       | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('sessionDestroy', () => {
  console.info(`on sessionDestroy : SUCCESS `);
});

```

### off('sessionDestroy')<sup>10+</sup>

off(type: 'sessionDestroy', callback?: () => void)

Unsubscribes from session destruction events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type       | Mandatory | Description                                                  |
| -------- | ---------- | --------- | ------------------------------------------------------------ |
| type     | string     | Yes       | Event type, which is **'sessionDestroy'** in this case.      |
| callback | () => void | No        | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('sessionDestroy');

```

### on('activeStateChange')<sup>10+</sup>

on(type: 'activeStateChange', callback: (isActive: boolean) => void)

Subscribes to session activation state change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                        | Mandatory | Description                                                  |
| -------- | --------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                      | Yes       | Event type. The event **'activeStateChange'** is triggered when the activation state of the session changes. |
| callback | (isActive: boolean) => void | Yes       | Callback used for subscription. The **isActive** parameter in the callback specifies whether the session is activated. The value **true** means that the service is activated, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('activeStateChange', (isActive: boolean) => {
  console.info(`on activeStateChange : SUCCESS : isActive ${isActive}`);
});

```

### off('activeStateChange')<sup>10+</sup>

off(type: 'activeStateChange', callback?: (isActive: boolean) => void)

Unsubscribes from session activation state change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                        | Mandatory | Description                                                  |
| -------- | --------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                      | Yes       | Event type, which is **'activeStateChange'** in this case.   |
| callback | (isActive: boolean) => void | No        | Callback used for unsubscription. The **isActive** parameter in the callback specifies whether the session is activated. The value **true** means that the session is activated, and **false** means the opposite.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('activeStateChange');

```

### on('validCommandChange')<sup>10+</sup>

on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void)

Subscribes to valid command change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The event **'validCommandChange'** is triggered when the valid commands supported by the session changes. |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype10)\>) => void | Yes       | Callback used for subscription. The **commands** parameter in the callback is a set of valid commands. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('validCommandChange', (validCommands: avSession.AVControlCommandType[]) => {
  console.info(`validCommandChange : SUCCESS : size : ${validCommands.length}`);
  console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});

```

### off('validCommandChange')<sup>10+</sup>

off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void)

Unsubscribes from valid command change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type, which is **'validCommandChange'** in this case.  |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype10)\>) => void | No        | Callback used for unsubscription. The **commands** parameter in the callback is a set of valid commands.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('validCommandChange');

```

### on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void

Subscribes to output device change events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The event **'outputDeviceChange'** is triggered when the output device changes. |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | Yes       | Callback used for subscription. The **device** parameter in the callback indicates the output device information. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {
  console.info(`on outputDeviceChange state: ${state}, device : ${device}`);
});

```

### off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void

Unsubscribes from output device change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type, which is **'outputDeviceChange'** in this case.  |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | No        | Callback used for unsubscription. The **device** parameter in the callback indicates the output device information.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('outputDeviceChange');

```

### on('sessionEvent')<sup>10+</sup>

on(type: 'sessionEvent', callback: (sessionEvent: string, args: {[key:string]: Object}) => void): void

Subscribes to session event change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The event **'sessionEvent'** is triggered when the session event changes. |
| callback | (sessionEvent: string, args: {[key:string]: object}) => void | Yes       | Callback used for subscription. **sessionEvent** in the callback indicates the name of the session event that changes, and **args** indicates the parameters carried in the event. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).on('sessionEvent', (sessionEvent, args) => {
    console.info(`OnSessionEvent, sessionEvent is ${sessionEvent}, args: ${JSON.stringify(args)}`);
  });
}

```

### off('sessionEvent')<sup>10+</sup>

off(type: 'sessionEvent', callback?: (sessionEvent: string, args: {[key:string]: Object}) => void): void

Unsubscribes from session event change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type, which is **'sessionEvent'** in this case.        |
| callback | (sessionEvent: string, args: {[key:string]: Object}) => void | No        | Callback used for unsubscription. **sessionEvent** in the callback indicates the name of the session event that changes, and **args** indicates the parameters carried in the event.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('sessionEvent');

```

### on('queueItemsChange')<sup>10+</sup>

on(type: 'queueItemsChange', callback: (items: Array<[AVQueueItem](#avqueueitem10)\>) => void): void

Subscribes to playlist item change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                   | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                 | Yes       | Event type. The event **'queueItemsChange'** is triggered when one or more items in the playlist changes. |
| callback | (items: Array<[AVQueueItem](#avqueueitem10)\>) => void | Yes       | Callback used for subscription. The **items** parameter in the callback indicates the changed items in the playlist. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('queueItemsChange', (items: avSession.AVQueueItem[]) => {
  console.info(`OnQueueItemsChange, items length is ${items.length}`);
});

```

### off('queueItemsChange')<sup>10+</sup>

off(type: 'queueItemsChange', callback?: (items: Array<[AVQueueItem](#avqueueitem10)\>) => void): void

Unsubscribes from playback item change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                                   | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                 | Yes       | Event type, which is **'queueItemsChange'** in this case.    |
| callback | (items: Array<[AVQueueItem](#avqueueitem10)\>) => void | No        | Callback used for unsubscription. The **items** parameter in the callback indicates the changed items in the playlist.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('queueItemsChange');

```

### on('queueTitleChange')<sup>10+</sup>

on(type: 'queueTitleChange', callback: (title: string) => void): void

Subscribes to playlist name change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                    | Mandatory | Description                                                  |
| -------- | ----------------------- | --------- | ------------------------------------------------------------ |
| type     | string                  | Yes       | Event type. The event **'queueTitleChange'** is triggered when the playlist name changes. |
| callback | (title: string) => void | Yes       | Callback used for subscription. The **title** parameter in the callback indicates the changed playlist name. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.on('queueTitleChange', (title: string) => {
  console.info(`queueTitleChange, title is ${title}`);
});

```

### off('queueTitleChange')<sup>10+</sup>

off(type: 'queueTitleChange', callback?: (title: string) => void): void

Unsubscribes from playlist name change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                    | Mandatory | Description                                                  |
| -------- | ----------------------- | --------- | ------------------------------------------------------------ |
| type     | string                  | Yes       | Event type, which is **'queueTitleChange'** in this case.    |
| callback | (title: string) => void | No        | Callback used for unsubscription. The **items** parameter in the callback indicates the changed playlist name.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('queueTitleChange');

```

### on('extrasChange')<sup>10+</sup>

on(type: 'extrasChange', callback: (extras: {[key:string]: Object}) => void): void

Subscribes to custom media packet change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                     | Mandatory | Description                                                  |
| -------- | ---------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                   | Yes       | Event type. The event **'extrasChange'** is triggered when the provider sets a custom media packet. |
| callback | (extras: {[key:string]: object}) => void | Yes       | Callback used for subscription. The **extras** parameter in the callback indicates the custom media packet set by the provider. This packet is the same as that set in **dispatchSessionEvent**. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).on('extrasChange', (extras) => {
    console.info(`Caught extrasChange event,the new extra is: ${JSON.stringify(extras)}`);
  });
}

```

### off('extrasChange')<sup>10+</sup>

off(type: 'extrasChange', callback?: (extras: {[key:string]: Object}) => void): void

Unsubscribes from custom media packet change events. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                             | Mandatory | Description                                                  |
| -------- | -------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                           | Yes       | Event type, which is **'extrasChange'** in this case.        |
| callback | ({[key:string]: Object}) => void | No        | Callback used for unsubscription.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
avsessionController.off('extrasChange');

```

### getAVPlaybackStateSync<sup>10+</sup>

getAVPlaybackStateSync(): AVPlaybackState;

Obtains the playback state of this session. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                  | Description                    |
| ------------------------------------- | ------------------------------ |
| [AVPlaybackState](#avplaybackstate10) | Playback state of the session. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
try {
  let playbackState: avsession.AVPlaybackState = avsessionController.getAVPlaybackStateSync();
} catch (err) {
  console.info(`getAVPlaybackStateSync error, error code: ${err.code}, error message: ${err.message}`);
}

```

### getAVMetadataSync<sup>10+</sup>

getAVMetadataSync(): AVMetadata

Obtains the session metadata. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                        | Description       |
| --------------------------- | ----------------- |
| [AVMetadata](#avmetadata10) | Session metadata. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
try {
  let metaData: avsession.AVMetadata = avsessionController.getAVMetadataSync();
} catch (err) {
  console.info(`getAVMetadataSync error, error code: ${err.code}, error message: ${err.message}`);
}

```

### getAVCallState<sup>11+</sup>

getAVCallState(): Promise\<AVCallState>

Obtains the call state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                    | Description                                   |
| --------------------------------------- | --------------------------------------------- |
| Promise<[AVCallState](#avcallstate11)\> | Promise used to return the call state obtained. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVCallState().then((callstate: avSession.AVCallState) => {
  console.info(`getAVCallState : SUCCESS : state : ${callstate.state}`);
}).catch((err: BusinessError) => {
  console.error(`getAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getAVCallState<sup>11+</sup>

getAVCallState(callback: AsyncCallback\<AVCallState>): void

Obtains the call state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                          | Mandatory | Description                                    |
| -------- | --------------------------------------------- | --------- | ---------------------------------------------- |
| callback | AsyncCallback<[AVCallState](#avcallstate11)\> | Yes       | Callback used to return the call state obtained. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVCallState((err: BusinessError, callstate: avSession.AVCallState) => {
  if (err) {
    console.error(`getAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getAVCallState : SUCCESS : state : ${callstate.state}`);
  }
});

```

### getCallMetadata<sup>11+</sup>

getCallMetadata(): Promise\<CallMetadata>

Obtains the call metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                      | Description                                   |
| ----------------------------------------- | --------------------------------------------- |
| Promise<[CallMetadata](#callmetadata11)\> | Promise used to return the metadata obtained. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getCallMetadata().then((calldata: avSession.CallMetadata) => {
  console.info(`getCallMetadata : SUCCESS : name : ${calldata.name}`);
}).catch((err: BusinessError) => {
  console.error(`getCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### getCallMetadata<sup>11+</sup>

getCallMetadata(callback: AsyncCallback\<CallMetadata>): void

Obtains the call metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name     | Type                                            | Mandatory | Description                                    |
| -------- | ----------------------------------------------- | --------- | ---------------------------------------------- |
| callback | AsyncCallback<[CallMetadata](#callmetadata11)\> | Yes       | Callback used to return the metadata obtained. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getCallMetadata((err: BusinessError, calldata: avSession.CallMetadata) => {
  if (err) {
    console.error(`getCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getCallMetadata : SUCCESS : name : ${calldata.name}`);
  }
});

```

### getAVQueueTitleSync<sup>10+</sup>

getAVQueueTitleSync(): string

Obtains the name of the playlist of this session. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type   | Description    |
| ------ | -------------- |
| string | Playlist name. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
try {
  let currentQueueTitle: string = avsessionController.getAVQueueTitleSync();
} catch (err) {
  console.info(`getAVQueueTitleSync error, error code: ${err.code}, error message: ${err.message}`);
}

```

### getAVQueueItemsSync<sup>10+</sup>

getAVQueueItemsSync(): Array\<AVQueueItem\>

Obtains the information related to the items in the playlist of this session. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                  | Description         |
| ------------------------------------- | ------------------- |
| Array<[AVQueueItem](#avqueueitem10)\> | Items in the queue. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
try {
  let currentQueueItems: Array<avsession.AVQueueItem> = avsessionController.getAVQueueItemsSync();
} catch (err) {
  console.info(`getAVQueueItemsSync error, error code: ${err.code}, error message: ${err.message}`);
}

```

### getOutputDeviceSync<sup>10+</sup>

getOutputDeviceSync(): OutputDeviceInfo

Obtains the output device information. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                    | Description                          |
| --------------------------------------- | ------------------------------------ |
| [OutputDeviceInfo](#outputdeviceinfo10) | Information about the output device. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600103 | The session controller does not exist. |

**Example**

```ts
try {
  let currentOutputDevice: avSession.OutputDeviceInfo = avsessionController.getOutputDeviceSync();
} catch (err) {
  console.info(`getOutputDeviceSync error, error code: ${err.code}, error message: ${err.message}`);
}

```

### isActiveSync<sup>10+</sup>

isActiveSync(): boolean

Checks whether the session is activated. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type    | Description                                                  |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** is returned if the session is activated; returns **false** otherwise. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
try {
  let isActive: boolean = avsessionController.isActiveSync();
} catch (err) {
  console.info(`isActiveSync error, error code: ${err.code}, error message: ${err.message}`);
}

```

### getValidCommandsSync<sup>10+</sup>

getValidCommandsSync(): Array\<AVControlCommandType\>

Obtains valid commands supported by the session. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                    | Description              |
| ------------------------------------------------------- | ------------------------ |
| Array<[AVControlCommandType](#avcontrolcommandtype10)\> | A set of valid commands. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID      | Error Message                          |
| ------- | -------------------------------------- |
| 6600101 | Session service exception.             |
| 6600102 | The session does not exist.            |
| 6600103 | The session controller does not exist. |

**Example**

```ts
try {
  let validCommands: Array<avSession.AVControlCommandType> = avsessionController.getValidCommandsSync();
} catch (err) {
  console.info(`getValidCommandsSync error, error code: ${err.code}, error message: ${err.message}`);
}

```

## AVControlCommandType<sup>10+</sup>

Enumerates the commands that can be sent to a session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name           | Type   | Description                    |
| -------------- | ------ | ------------------------------ |
| play           | string | Play the media.                |
| pause          | string | Pause the playback.            |
| stop           | string | Stop the playback.             |
| playNext       | string | Play the next media asset.     |
| playPrevious   | string | Play the previous media asset. |
| fastForward    | string | Fast-forward.                  |
| rewind         | string | Rewind.                        |
| seek           | string | Seek to a playback position.   |
| setSpeed       | string | Set the playback speed.        |
| setLoopMode    | string | Set the loop mode.             |
| toggleFavorite | string | Favorite the media asset.      |

## AVControlCommand<sup>10+</sup>

Describes the command that can be sent to the session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name      | Type                                                | Mandatory | Description                        |
| --------- | --------------------------------------------------- | --------- | ---------------------------------- |
| command   | [AVControlCommandType](#avcontrolcommandtype10)     | Yes       | Command.                           |
| parameter | [LoopMode](#loopmode10) &#124; string &#124; number | No        | Parameters carried in the command. |

## AVSessionErrorCode<sup>10+</sup>

Enumerates the error codes used in the media session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                                 | Value   | Description                               |
| ------------------------------------ | ------- | ----------------------------------------- |
| ERR_CODE_SERVICE_EXCEPTION           | 6600101 | Session service exception.                |
| ERR_CODE_SESSION_NOT_EXIST           | 6600102 | The session does not exist.               |
| ERR_CODE_CONTROLLER_NOT_EXIST        | 6600103 | The session controller does not exist.    |
| ERR_CODE_REMOTE_CONNECTION_ERR       | 6600104 | The remote session  connection failed.    |
| ERR_CODE_COMMAND_INVALID             | 6600105 | Invalid session command.                  |
| ERR_CODE_SESSION_INACTIVE            | 6600106 | The session is not activated.             |
| ERR_CODE_MESSAGE_OVERLOAD            | 6600107 | Too many commands or events.              |
| ERR_CODE_DEVICE_CONNECTION_FAILED    | 6600108 | Device connecting failed.                 |
| ERR_CODE_REMOTE_CONNECTION_NOT_EXIST | 6600109 | The remote connection is not established. |

## SkipIntervals<sup>11+</sup>

Enumerates the fast-forward or rewind intervals supported by the media session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name       | Value | Description             |
| ---------- | ----- | ----------------------- |
| SECONDS_10 | 10    | The time is 10 seconds. |
| SECONDS_15 | 15    | The time is 15 seconds. |
| SECONDS_30 | 30    | The time is 30 seconds. |