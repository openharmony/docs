# @ohos.multimedia.avsession (AVSession Management)

The **avSession** module provides APIs for media playback control so that applications can access the system's Media Controller.

This module provides the following typical features related to media sessions:

- [AVSession](#avsession10): used to set session metadata, playback state information, and more.
- [AVSessionController](#avsessioncontroller10): used to obtain session IDs, send commands and events to sessions, and obtain the session metadata and playback state information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
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

```js
import featureAbility from '@ohos.ability.featureAbility';

let session;
let tag = "createNewSession";
let context = featureAbility.getContext();

await avSession.createAVSession(context, tag, "audio").then((data) => {
    session = data;
    console.info(`CreateAVSession : SUCCESS : sessionId = ${session.sessionId}`);
}).catch((err) => {
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

```js
import featureAbility from '@ohos.ability.featureAbility';

let session;
let tag = "createNewSession";
let context = featureAbility.getContext();

avSession.createAVSession(context, tag, "audio", function (err, data) {
    if (err) {
        console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        session = data;
        console.info(`CreateAVSession : SUCCESS : sessionId = ${session.sessionId}`);
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

```js
avSession.getAllSessionDescriptors().then((descriptors) => {
    console.info(`getAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if(descriptors.length > 0 ){
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
        console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
        console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
    }
}).catch((err) => {
    console.info(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
avSession.getAllSessionDescriptors(function (err, descriptors) {
    if (err) {
        console.info(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
avSession.getHistoricalSessionDescriptors().then((descriptors) => {
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if(descriptors.length > 0 ){
        console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
        console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
        console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
        console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionId : ${descriptors[0].sessionId}`);
        console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].elementName.bundleName : ${descriptors[0].elementName.bundleName}`);
    }
}).catch((err) => {
    console.info(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
avSession.getHistoricalSessionDescriptors(1, function (err, descriptors) {
    if (err) {
        console.info(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
import featureAbility from '@ohos.ability.featureAbility';

let session;
let tag = "createNewSession";
let context = featureAbility.getContext();

await avSession.createAVSession(context, tag, "audio").then((data) => {
    session = data;
    console.info(`CreateAVSession : SUCCESS : sessionId = ${session.sessionId}`);
}).catch((err) => {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
});

let controller;
await avSession.createController(session.sessionId).then((avcontroller) => {
    controller = avcontroller;
    console.info(`CreateController : SUCCESS : ${controller.sessionId}`);
}).catch((err) => {
    console.info(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
import featureAbility from '@ohos.ability.featureAbility';

let session;
let tag = "createNewSession";
let context = featureAbility.getContext();

await avSession.createAVSession(context, tag, "audio").then((data) => {
    session = data;
    console.info(`CreateAVSession : SUCCESS : sessionId = ${session.sessionId}`);
}).catch((err) => {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
});

let controller;
avSession.createController(session.sessionId, function (err, avcontroller) {
    if (err) {
        console.info(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        controller = avcontroller;
        console.info(`CreateController : SUCCESS : ${controller.sessionId}`);
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

| Name      | Type                                                                                                                                                                | Mandatory| Description                                                        |
| ------------ |--------------------------------------------------------------------------------------------------------------------------------------------------------------------| ---- | ------------------------------------------------------------ |
| session      | [SessionToken](#sessiontoken) &#124; 'all'                                                                                                                         | Yes  | Session token. **SessionToken** indicates a specific token, and **'all'** indicates all tokens.|
| audioDevices | Array\<[audio.AudioDeviceDescriptor](js-apis-audio.md#audiodevicedescriptor)\> | Yes  | Audio devices.                         |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the casting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session  connection failed. |

**Example**

```js
import audio from '@ohos.multimedia.audio';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices;
await audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
    audioDevices = data;
    console.info(`Promise returned to indicate that the device list is obtained.`);
}).catch((err) => {
    console.info(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

avSession.castAudio('all', audioDevices).then(() => {
    console.info(`CreateController : SUCCESS`);
}).catch((err) => {
    console.info(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});
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
| audioDevices | Array\<[audio.AudioDeviceDescriptor](js-apis-audio.md#audiodevicedescriptor)\>   | Yes  | Audio devices.                      |
| callback     | AsyncCallback\<void>                      | Yes  | Callback used to return the result. If the casting is successful, **err** is **undefined**; otherwise, **err** is an error object.                       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session  connection failed. |

**Example**

```js
import audio from '@ohos.multimedia.audio';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices;
await audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
    audioDevices = data;
    console.info(`Promise returned to indicate that the device list is obtained.`);
}).catch((err) => {
    console.info(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

avSession.castAudio('all', audioDevices, function (err) {
    if (err) {
        console.info(`CastAudio BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`CastAudio : SUCCESS `);
    }
});
```

## avSession.on('sessionCreate' | 'sessionDestroy' | 'topSessionChange')

on(type: 'sessionCreate' | 'sessionDestroy' | 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void

Subscribes to session creation, session destruction, and top session change events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type.<br>- **'sessionCreate'**: session creation event, which is reported when a session is created.<br>- **'sessionDestroy'**: session destruction event, which is reported when a session is destroyed.<br>- **'topSessionChange'**: top session change event, which is reported when the top session is changed.|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | Yes  | Callback used to report the session descriptor.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```js
avSession.on('sessionCreate', (descriptor) => {
    console.info(`on sessionCreate : isActive : ${descriptor.isActive}`);
    console.info(`on sessionCreate : type : ${descriptor.type}`);
    console.info(`on sessionCreate : sessionTag : ${descriptor.sessionTag}`);
});

avSession.on('sessionDestroy', (descriptor) => {
    console.info(`on sessionDestroy : isActive : ${descriptor.isActive}`);
    console.info(`on sessionDestroy : type : ${descriptor.type}`);
    console.info(`on sessionDestroy : sessionTag : ${descriptor.sessionTag}`);
});

avSession.on('topSessionChange', (descriptor) => {
    console.info(`on topSessionChange : isActive : ${descriptor.isActive}`);
    console.info(`on topSessionChange : type : ${descriptor.type}`);
    console.info(`on topSessionChange : sessionTag : ${descriptor.sessionTag}`);
});
```

## avSession.off('sessionCreate' | 'sessionDestroy' | 'topSessionChange')

off(type: 'sessionCreate' | 'sessionDestroy' | 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void

Unsubscribes from session creation, session destruction, and top session change events.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type.<br>- **'sessionCreate'**: session creation event, which is reported when a session is created.<br>- **'sessionDestroy'**: session destruction event, which is reported when a session is destroyed.<br>- **'topSessionChange'**: top session change event, which is reported when the top session is changed.|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **session** parameter in the callback describes a media session. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```js
avSession.off('sessionCreate');
avSession.off('sessionDestroy');
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
| type     | string               | Yes  | Event type. The event **'sessionServiceDie'** is reported when the session service dies.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                               |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```js
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
| type     | string                 | Yes   | Event type. The event **'sessionServiceDie'** is reported when the session service dies.|
| callback | callback: () => void   | No   | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**Example**

```js
avSession.off('sessionServiceDie');
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

```js

let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false}; 

avSession.sendSystemAVKeyEvent(event).then(() => {
    console.info(`SendSystemAVKeyEvent Successfully`);
}).catch((err) => {
    console.info(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});

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

```js
let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false}; 

avSession.sendSystemAVKeyEvent(event, function (err) {
    if (err) {
        console.info(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`SendSystemAVKeyEvent : SUCCESS `);
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

```js
let cmd : avSession.AVControlCommandType = 'play';
// let cmd : avSession.AVControlCommandType = 'pause';
// let cmd : avSession.AVControlCommandType = 'stop';
// let cmd : avSession.AVControlCommandType = 'playNext';
// let cmd : avSession.AVControlCommandType = 'playPrevious';
// let cmd : avSession.AVControlCommandType = 'fastForward';
// let cmd : avSession.AVControlCommandType = 'rewind';
let avcommand = {command:cmd};
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
}).catch((err) => {
    console.info(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
let cmd : avSession.AVControlCommandType = 'play';
// let cmd : avSession.AVControlCommandType = 'pause';
// let cmd : avSession.AVControlCommandType = 'stop';
// let cmd : avSession.AVControlCommandType = 'playNext';
// let cmd : avSession.AVControlCommandType = 'playPrevious';
// let cmd : avSession.AVControlCommandType = 'fastForward';
// let cmd : avSession.AVControlCommandType = 'rewind';
let avcommand = {command:cmd};
// let cmd : avSession.AVControlCommandType = 'seek';
// let avcommand = {command:cmd, parameter:10};
// let cmd : avSession.AVControlCommandType = 'setSpeed';
// let avcommand = {command:cmd, parameter:2.6};
// let cmd : avSession.AVControlCommandType = 'setLoopMode';
// let avcommand = {command:cmd, parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let cmd : avSession.AVControlCommandType = 'toggleFavorite';
// let avcommand = {command:cmd, parameter:"false"};
avSession.sendSystemControlCommand(avcommand, function (err) {
    if (err) {
        console.info(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`sendSystemControlCommand successfully`);
    }
});
```

## AVSession<sup>10+</sup>

An **AVSession** object is created by calling [avSession.createAVSession](#avsessioncreateavsession10). The object enables you to obtain the session ID and set the metadata and playback state. 

### Attributes

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name     | Type  | Readable| Writable| Description                         |
| :-------- | :----- | :--- | :--- | :---------------------------- |
| sessionId | string | Yes  | No  | Unique session ID of the **AVSession** object.|


**Example**
```js
let sessionId = session.sessionId;
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

```js
let metadata  = {
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
session.setAVMetadata(metadata).then(() => {
    console.info(`SetAVMetadata successfully`);
}).catch((err) => {
    console.info(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
let metadata  = {
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
session.setAVMetadata(metadata, function (err) {
    if (err) {
        console.info(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`SetAVMetadata successfully`);
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

```js
let playbackState = {
    state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
    speed: 1.0,
    position:{elapsedTime:10, updateTime:(new Date()).getTime()},
    bufferedTime:1000,
    loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
    isFavorite:true,
};
session.setAVPlaybackState(playbackState).then(() => {
    console.info(`SetAVPlaybackState successfully`);
}).catch((err) => {
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

```js
let PlaybackState = {
    state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
    speed: 1.0,
    position:{elapsedTime:10, updateTime:(new Date()).getTime()},
    bufferedTime:1000,
    loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
    isFavorite:true,
};
session.setAVPlaybackState(PlaybackState, function (err) {
    if (err) {
        console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`SetAVPlaybackState successfully`);
    }
});
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

```js
let imageSource : imageImageSource = image.createImageSource(value.buffer);
let imagePixel : image.PixelMap = await imageSource.createPixelMap({desiredSize:{width: 150, height: 150}});
let queueItemDescription_1 = {
    mediaId: '001',
    title: 'music_name',
    subtitle: 'music_sub_name',
    description: 'music_description',
    icon : imagePixel,
    iconUri: 'http://www.icon.uri.com',
    extras: {'extras':'any'}
};
let queueItem_1 = {
    itemId: 1,
    description: queueItemDescription_1
};
let queueItemDescription_2 = {
    mediaId: '002',
    title: 'music_name',
    subtitle: 'music_sub_name',
    description: 'music_description',
    icon: PIXELMAP_OBJECT,
    iconUri: 'http://www.xxx.com',
    extras: {'extras':'any'}
};
let queueItem_2 = {
    itemId: 2,
    description: queueItemDescription_2
};
let queueItemsArray = [queueItem_1, queueItem_2];
session.setAVQueueItems(queueItemsArray).then(() => {
    console.info(`SetAVQueueItems successfully`);
}).catch((err) => {
    console.info(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
let imageSource : imageImageSource = image.createImageSource(value.buffer);
let imagePixel : image.PixelMap = await imageSource.createPixelMap({desiredSize:{width: 150, height: 150}});
let queueItemDescription_1 = {
    mediaId: '001',
    title: 'music_name',
    subtitle: 'music_sub_name',
    description: 'music_description',
    icon: imagePixel,
    iconUri: 'http://www.icon.uri.com',
    extras: {'extras':'any'}
};
let queueItem_1 = {
    itemId: 1,
    description: queueItemDescription_1
};
let queueItemDescription_2 = {
    mediaId: '002',
    title: 'music_name',
    subtitle: 'music_sub_name',
    description: 'music_description',
    icon: PIXELMAP_OBJECT,
    iconUri: 'http://www.icon.uri.com',
    extras: {'extras':'any'}
};
let queueItem_2 = {
    itemId: 2,
    description: queueItemDescription_2
};
let queueItemsArray = [queueItem_1, queueItem_2];
session.setAVQueueItems(queueItemsArray, function (err) {
    if (err) {
        console.info(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
let queueTitle = 'QUEUE_TITLE';
session.setAVQueueTitle(queueTitle).then(() => {
    console.info(`SetAVQueueTitle successfully`);
}).catch((err) => {
    console.info(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
let queueTitle = 'QUEUE_TITLE';
session.setAVQueueTitle(queueTitle, function (err) {
    if (err) {
        console.info(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`SetAVQueueTitle successfully`);
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

```js
import wantAgent from '@ohos.app.ability.wantAgent';

// WantAgentInfo object
let wantAgentInfo = {
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
    session.setLaunchAbility(agent).then(() => {
        console.info(`SetLaunchAbility successfully`);
    }).catch((err) => {
        console.info(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
import wantAgent from '@ohos.app.ability.wantAgent';

// WantAgentInfo object
let wantAgentInfo = {
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
    session.setLaunchAbility(agent, function (err) {
        if (err) {
            console.info(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
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
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md).

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

```js
let eventName = "dynamic_lyric";
let args = {
    lyric : "This is lyric"
}
await session.dispatchSessionEvent(eventName, args).catch((err) => {
    console.info(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);
})
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
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md).

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
let eventName = "dynamic_lyric";
let args = {
    lyric : "This is lyric"
}
await session.dispatchSessionEvent(eventName, args, (err) => {
    if(err) {
        console.info(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);
    }
})
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
>
> The **extras** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md).

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

```js
let extras = {
    extras : "This is custom media packet"
}
await session.setExtras(extras).catch((err) => {
    console.info(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);
})
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
> The **extras** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md).

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
let extras = {
    extras : "This is custom media packet"
}
await session.setExtras(extras, (err) => {
    if(err) {
        console.info(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);
    }
})
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

```js
let controller;
session.getController().then((avcontroller) => {
    controller = avcontroller;
    console.info(`GetController : SUCCESS : sessionid : ${controller.sessionId}`);
}).catch((err) => {
    console.info(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
let controller;
session.getController(function (err, avcontroller) {
    if (err) {
        console.info(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        controller = avcontroller;
        console.info(`GetController : SUCCESS : sessionid : ${controller.sessionId}`);
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

```js
session.getOutputDevice().then((outputDeviceInfo) => {
    console.info(`GetOutputDevice : SUCCESS : isRemote : ${outputDeviceInfo.isRemote}`);
}).catch((err) => {
    console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});
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

```js
session.getOutputDevice(function (err, outputDeviceInfo) {
    if (err) {
        console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetOutputDevice : SUCCESS : isRemote : ${outputDeviceInfo.isRemote}`);
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

```js
session.activate().then(() => {
    console.info(`Activate : SUCCESS `);
}).catch((err) => {
    console.info(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
session.activate(function (err) {
    if (err) {
        console.info(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
session.deactivate().then(() => {
    console.info(`Deactivate : SUCCESS `);
}).catch((err) => {
    console.info(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
session.deactivate(function (err) {
    if (err) {
        console.info(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
session.destroy().then(() => {
    console.info(`Destroy : SUCCESS `);
}).catch((err) => {
    console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
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

```js
session.destroy(function (err) {
    if (err) {
        console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`Destroy : SUCCESS `);
    }
});
```

### on('play'|'pause'|'stop'|'playNext'|'playPrevious'|'fastForward'|'rewind')<sup>10+</sup>

on(type: 'play'|'pause'|'stop'|'playNext'|'playPrevious'|'fastForward'|'rewind', callback: () => void): void

Subscribes to playback command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The following events are supported: **'play'**, **'pause'**, **'stop'**, **'playNext'**, **'playPrevious'**, **'fastForward'**, and **'rewind'**.<br>The event is reported when the corresponding playback command is sent to the session.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                                       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.on('play', () => {
    console.info(`on play entry`);
});
session.on('pause', () => {
    console.info(`on pause entry`);
});
session.on('stop', () => {
    console.info(`on stop entry`);
});
session.on('playNext', () => {
    console.info(`on playNext entry`);
});
session.on('playPrevious', () => {
    console.info(`on playPrevious entry`);
});
session.on('fastForward', () => {
    console.info(`on fastForward entry`);
});
session.on('rewind', () => {
    console.info(`on rewind entry`);
});
```

### on('seek')<sup>10+</sup>

on(type: 'seek', callback: (time: number) => void): void

Subscribes to the seek event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The event **'seek'** is reported when the seek command is sent to the session.|
| callback | (time: number) => void | Yes  | Callback used for subscription. The **time** parameter in the callback indicates the time to seek to, in milliseconds.                  |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**
The session does not exist
```js
session.on('seek', (time) => {
    console.info(`on seek entry time : ${time}`);
});
```

### on('setSpeed')<sup>10+</sup>

on(type: 'setSpeed', callback: (speed: number) => void): void

Subscribes to the event for setting the playback speed.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type. The event **'setSpeed'** is reported when the command for setting the playback speed is sent to the session.|
| callback | (speed: number) => void | Yes  | Callback used for subscription. The **speed** parameter in the callback indicates the playback speed.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.on('setSpeed', (speed) => {
    console.info(`on setSpeed speed : ${speed}`);
});
```

### on('setLoopMode')<sup>10+</sup>

on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void

Subscribes to the event for setting the loop mode.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                  | Mandatory| Description |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | Yes  | Event type. The event **'setLoopMode'** is reported when the command for setting the loop mode is sent to the session.|
| callback | (mode: [LoopMode](#loopmode10)) => void | Yes  | Callback used for subscription. The **mode** parameter in the callback indicates the loop mode.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.on('setLoopMode', (mode) => {
    console.info(`on setLoopMode mode : ${mode}`);
});
```

### on('toggleFavorite')<sup>10+</sup>

on(type: 'toggleFavorite', callback: (assetId: string) => void): void

Subscribes to the event for favoriting a media asset.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                    | Yes  | Event type. The event **'toggleFavorite'** is reported when the command for favoriting the media asset is sent to the session.|
| callback | (assetId: string) => void | Yes  | Callback used for subscription. The **assetId** parameter in the callback indicates the media asset ID.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.on('toggleFavorite', (assetId) => {
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
| type     | string                   | Yes  | Event type. The event **'skipToQueueItem'** is reported when the command for selecting an item in the playlist is sent to the session.|
| callback | (itemId: number) => void | Yes  | Callback used for subscription. The **itemId** parameter in the callback indicates the ID of the selected item.                                               |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.on('skipToQueueItem', (itemId) => {
    console.info(`on skipToQueueItem id : ${itemId}`);
});
```

### on('handleKeyEvent')<sup>10+</sup>

on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void

Subscribes to the key event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'handleKeyEvent'** is reported when a key event is sent to the session.|
| callback | (event: [KeyEvent](js-apis-keyevent.md)) => void | Yes  | Callback used for subscription. The **event** parameter in the callback indicates the key event.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.on('handleKeyEvent', (event) => {
    console.info(`on handleKeyEvent event : ${event}`);
});
```

### on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void

Subscribes to output device changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The event **'outputDeviceChange'** is reported when the output device changes.|
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | Yes  | Callback used for subscription. The **device** parameter in the callback indicates the output device information.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.on('outputDeviceChange', (device) => {
    console.info(`on outputDeviceChange device isRemote : ${device.isRemote}`);
});
```

### on('commonCommand')<sup>10+</sup>

on(type: 'commonCommand', callback: (command: string, args: {[key: string]: Object}) => void): void

Subscribes to custom control command changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'commonCommand'** is reported when a custom control command changes.|
| callback | (commonCommand: string, args: {[key:string]: Object}) => void         | Yes  | Callback used for subscription. The **commonCommand** parameter in the callback indicates the name of the changed custom control command, and **args** indicates the parameters carried in the command. The parameters must be the same as those set in **sendCommand**.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
session.on('commonCommand', (commonCommand, args) => {
    console.info(`OnCommonCommand, the command is ${commonCommand}, args: ${JSON.stringify(args)}`);
});
```

### off('play'|'pause'|'stop'|'playNext'|'playPrevious'|'fastForward'|'rewind')<sup>10+</sup>

off(type: 'play' | 'pause' | 'stop' | 'playNext' | 'playPrevious' | 'fastForward' | 'rewind', callback?: () => void): void

Unsubscribes from playback command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type. The following events are supported: **'play'**, **'pause'**, **'stop'**, **'playNext'**, **'playPrevious'**, **'fastForward'**, and **'rewind'**.|
| callback | callback: () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.off('play');
session.off('pause');
session.off('stop');
session.off('playNext');
session.off('playPrevious');
session.off('fastForward');
session.off('rewind');
```

### off('seek')<sup>10+</sup>

off(type: 'seek', callback?: (time: number) => void): void

Unsubscribes from the seek event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                         |
| -------- | ---------------------- | ---- | ----------------------------------------- |
| type     | string                 | Yes  | Event type. The value is fixed at **'seek'**.      |
| callback | (time: number) => void | No  | Callback used for unsubscription. The **time** parameter in the callback indicates the time to seek to, in milliseconds.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.off('seek');
```

### off('setSpeed')<sup>10+</sup>

off(type: 'setSpeed', callback?: (speed: number) => void): void

Unsubscribes from the event for setting the playback speed.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                          |
| -------- | ----------------------- | ---- | -------------------------------------------|
| type     | string                  | Yes  | Event type. The value is fixed at **'setSpeed'**.   |
| callback | (speed: number) => void | No  | Callback used for unsubscription. The **speed** parameter in the callback indicates the playback speed.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.off('setSpeed');
```

### off('setLoopMode')<sup>10+</sup>

off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void

Unsubscribes from the event for setting loop mode.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description    |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | Yes  | Event type. The value is fixed at **'setLoopMode'**.|
| callback | (mode: [LoopMode](#loopmode10)) => void | No  | Callback used for unsubscription. The **mode** parameter in the callback indicates the loop mode.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.off('setLoopMode');
```

### off('toggleFavorite')<sup>10+</sup>

off(type: 'toggleFavorite', callback?: (assetId: string) => void): void

Unsubscribes from the event for favoriting a media asset.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | -------------------------------------------------------- |
| type     | string                    | Yes  | Event type. The value is fixed at **'toggleFavorite'**.           |
| callback | (assetId: string) => void | No  | Callback used for unsubscription. The **assetId** parameter in the callback indicates the media asset ID.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.off('toggleFavorite');
```

### off('skipToQueueItem')<sup>10+</sup>

off(type: 'skipToQueueItem', callback?: (itemId: number) => void): void

Unsubscribes from the event that indicates an item in the playlist is selected.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                                                                                                                       |
| -------- | ------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- |
| type     | string                   | Yes  | Event type. The value is fixed at **'skipToQueueItem'**.                                                                                                         |
| callback | (itemId: number) => void | No  | Callback used for unsubscription. The **itemId** parameter in the callback indicates the ID of the item.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.off('skipToQueueItem');
```

### off('handleKeyEvent')<sup>10+</sup>

off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void

Unsubscribes from the key event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'handleKeyEvent'**.            |
| callback | (event: [KeyEvent](js-apis-keyevent.md)) => void | No  | Callback used for unsubscription. The **event** parameter in the callback indicates the key event.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.off('handleKeyEvent');
```

### off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void

Unsubscribes from playback device changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                     |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'outputDeviceChange'**.    |
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | No  | Callback used for unsubscription. The **device** parameter in the callback indicates the output device information.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
session.off('outputDeviceChange');
```


### off('commonCommand')<sup>10+</sup>

off(type: 'commonCommand', callback?: (command: string, args: {[key:string]: Object}) => void): void

Unsubscribes from custom control command changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'commonCommand'**.   |
| callback | (command: string, args: {[key:string]: Object}) => void         | No  | Callback used for unsubscription. The **command** parameter in the callback indicates the name of the changed custom control command, and **args** indicates the parameters carried in the command.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
session.off('commonCommand');
```



## AVSessionController<sup>10+</sup>

An AV session controller is created by calling [avSession.createController](#avsessioncreatecontroller). Through the AV session controller, you can query the session ID, send commands and events to a session, and obtain session metadata and playback state information.

### Attributes

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name     | Type  | Readable| Writable| Description                                   |
| :-------- | :----- | :--- | :--- | :-------------------------------------- |
| sessionId | string | Yes  | No  | Unique session ID of the **AVSessionController** object.|


**Example**
```js
let sessionId;
await avSession.createController(session.sessionId).then((controller) => {
    sessionId = controller.sessionId;
}).catch((err) => {
    console.info(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(): Promise\<AVPlaybackState>

Obtains the information related to the playback state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                         | Description                       |
| --------------------------------------------- | --------------------------- |
| Promise<[AVPlaybackState](#avplaybackstate10)\> | Promise used to return the **AVPlaybackState** object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
controller.getAVPlaybackState().then((playbackState) => {
    console.info(`GetAVPlaybackState : SUCCESS : state : ${playbackState.state}`);
}).catch((err) => {
    console.info(`GetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

Obtains the information related to the playback state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                        |
| -------- | --------------------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback<[AVPlaybackState](#avplaybackstate10)\> | Yes  | Callback used to return the **AVPlaybackState** object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
controller.getAVPlaybackState(function (err, playbackState) {
    if (err) {
        console.info(`GetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetAVPlaybackState : SUCCESS : state : ${playbackState.state}`);
    }
});
```

### getAVQueueItems<sup>10+</sup>

getAVQueueItems(): Promise\<Array\<AVQueueItem>>

Obtains the information related to the items in the queue. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                         | Description                          |
| --------------------------------------------- | ----------------------------- |
| Promise<Array<[AVQueueItem](#avqueueitem10)\>\> | Promise used to return the items in the queue.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
controller.getAVQueueItems().then((items) => {
    console.info(`GetAVQueueItems : SUCCESS : length : ${items.length}`);
}).catch((err) => {
    console.info(`GetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVQueueItems<sup>10+</sup>

getAVQueueItems(callback: AsyncCallback\<Array\<AVQueueItem>>): void

Obtains the information related to the items in the playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                | Mandatory| Description                     |
| -------- | --------------------------------------------------- | ---- | ------------------------- |
| callback | AsyncCallback<Array<[AVQueueItem](#avqueueitem10)\>\> | Yes  | Callback used to return the items in the playlist.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
controller.getAVQueueItems(function (err, items) {
    if (err) {
        console.info(`GetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetAVQueueItems : SUCCESS : length : ${items.length}`);
    }
});
```

### getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(): Promise\<string>

Obtains the name of the playlist. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type            | Description                          |
| ---------------- | ----------------------------- |
| Promise<string\> | Promise used to return the playlist name.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
controller.getAVQueueTitle().then((title) => {
    console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);
}).catch((err) => {
    console.info(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(callback: AsyncCallback\<string>): void

Obtains the name of the playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                     |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback<string\> | Yes  | Callback used to return the playlist name.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
controller.getAVQueueTitle(function (err, title) {
    if (err) {
        console.info(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);
    }
});
```

### skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number): Promise\<void>

Sends the ID of an item in the playlist to the session for processing. The session can play the song. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type   | Mandatory| Description                                       |
| ------ | ------- | ---- | ------------------------------------------- |
| itemId | number  | Yes  | ID of an item in the playlist.|

**Return value**

| Type          | Description                                                            |
| -------------- | --------------------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the item ID is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
let queueItemId = 0;
controller.skipToQueueItem(queueItemId).then(() => {
    console.info(`SkipToQueueItem successfully`);
}).catch((err) => {
    console.info(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void

Sends the ID of an item in the playlist to the session for processing. The session can play the song. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                       |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| itemId   | number                | Yes  | ID of an item in the playlist.               |
| callback | AsyncCallback\<void>  | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```js
let queueItemId = 0;
controller.skipToQueueItem(queueItemId, function (err) {
    if (err) {
        console.info(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`SkipToQueueItem successfully`);
    }
});
```

### getAVMetadata<sup>10+</sup>

getAVMetadata(): Promise\<AVMetadata>

Obtains the session metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<[AVMetadata](#avmetadata10)\> | Promise used to return the metadata obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
controller.getAVMetadata().then((metadata) => {
    console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
}).catch((err) => {
    console.info(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVMetadata<sup>10+</sup>

getAVMetadata(callback: AsyncCallback\<AVMetadata>): void

Obtains the session metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVMetadata](#avmetadata10)\> | Yes  | Callback used to return the metadata obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
controller.getAVMetadata(function (err, metadata) {
    if (err) {
        console.info(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
    }
});
```

### getOutputDevice<sup>10+</sup>

getOutputDevice(): Promise\<OutputDeviceInfo>

Obtains the output device information. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                           | Description                             |
| ----------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo10)\> | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**
```js
controller.getOutputDevice().then((deviceInfo) => {
    console.info(`GetOutputDevice : SUCCESS : isRemote : ${deviceInfo.isRemote}`);
}).catch((err) => {
    console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getOutputDevice<sup>10+</sup>

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

Obtains the output device information. This API uses an asynchronous callback to return the result.

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
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.getOutputDevice(function (err, deviceInfo) {
    if (err) {
        console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetOutputDevice : SUCCESS : isRemote : ${deviceInfo.isRemote}`);
    }
});
```

### getExtras<sup>10+</sup>

getExtras(): Promise\<{[key: string]: Object}>

Obtains the custom media packet set by the provider. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<{[key: string]: Object}\>   | Promise used to return the custom media packet. The content of the packet is the same as that set in **setExtras**.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
let extras = await controller.getExtras().catch((err) => {
    console.info(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getExtras<sup>10+</sup>

getExtras(callback: AsyncCallback\<{[key: string]: Object}>): void

Obtains the custom media packet set by the provider. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<{[key: string]: Object}\> | Yes  | Callback used to return the custom media packet. The content of the packet is the same as that set in **setExtras**.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```js
let metadata  = {
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
controller.getExtras(function (err, extras) {
    if (err) {
        console.info(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`getExtras : SUCCESS : assetId : ${metadata.assetId}`);
    }
});
```

### sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent): Promise\<void>

Sends a key event to the session corresponding to this controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                                                        | Mandatory| Description      |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| event  | [KeyEvent](js-apis-keyevent.md) | Yes  | Key event.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the event is sent, no value is returned; otherwise, an error object is returned.|

**Example**

```js
let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {action:2, key:keyItem, keys:[keyItem]};

controller.sendAVKeyEvent(event).then(() => {
    console.info(`SendAVKeyEvent Successfully`);
}).catch((err) => {
    console.info(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

Sends a key event to the session corresponding to this controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description      |
| -------- | ------------------------------------------------------------ | ---- | ---------- |
| event    | [KeyEvent](js-apis-keyevent.md) | Yes  | Key event.|
| callback | AsyncCallback\<void>                                         | Yes  | Callback used to return the result. If the event is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |

**Example**

```js
let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {action:2, key:keyItem, keys:[keyItem]};

controller.sendAVKeyEvent(event, function (err) {
    if (err) {
        console.info(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
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

| Type                                                   | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[WantAgent](js-apis-app-ability-wantAgent.md)\> | Promise used to return the object saved by calling [setLaunchAbility](#setlaunchability10). The object includes the application attribute, such as the bundle name, ability name, and device ID.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```js
import wantAgent from '@ohos.app.ability.wantAgent';

controller.getLaunchAbility().then((agent) => {
    console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
}).catch((err) => {
    console.info(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getLaunchAbility<sup>10+</sup>

getLaunchAbility(callback: AsyncCallback\<WantAgent>): void

Obtains the **WantAgent** object saved by the application in the session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[WantAgent](js-apis-app-ability-wantAgent.md)\> | Yes  | Callback used to return the object saved by calling [setLaunchAbility](#setlaunchability10). The object includes the application attribute, such as the bundle name, ability name, and device ID.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```js
import wantAgent from '@ohos.app.ability.wantAgent';

controller.getLaunchAbility(function (err, agent) {
    if (err) {
        console.info(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
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

| Type  | Description              |
| ------ | ------------------ |
| number | Playback position, in milliseconds.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
let time = controller.getRealPlaybackPositionSync();
```

### isActive<sup>10+</sup>

isActive(): Promise\<boolean>

Checks whether the session is activated. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise<boolean\> | Promise used to return the activation state. If the session is activated, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.isActive().then((isActive) => {
    console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
}).catch((err) => {
    console.info(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### isActive<sup>10+</sup>

isActive(callback: AsyncCallback\<boolean>): void

Checks whether the session is activated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<boolean\> | Yes  | Callback used to return the activation state. If the session is activated, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.isActive(function (err, isActive) {
    if (err) {
        console.info(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
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

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the controller is destroyed, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.destroy().then(() => {
    console.info(`Destroy : SUCCESS `);
}).catch((err) => {
    console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### destroy<sup>10+</sup>

destroy(callback: AsyncCallback\<void>): void

Destroys this controller. A controller can no longer be used after being destroyed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the controller is destroyed, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.destroy(function (err) {
    if (err) {
        console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
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

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<Array<[AVControlCommandType](#avcontrolcommandtype10)\>\> | Promise used to return a set of valid commands.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.getValidCommands.then((validCommands) => {
    console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
}).catch((err) => {
    console.info(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getValidCommands<sup>10+</sup>

getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void

Obtains valid commands supported by the session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<[AVControlCommandType](#avcontrolcommandtype10)\>\> | Yes  | Callback used to return a set of valid commands.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.getValidCommands(function (err, validCommands) {
    if (err) {
        console.info(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
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
> Before using **sendControlCommand**, the controller must ensure that the AVSession has registered with the corresponding listener. For details about how to register the listener, see [Registering AVSession Listeners](#onplaypausestopplaynextplaypreviousfastforwardrewind10).

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                 | Mandatory| Description                          |
| ------- | ------------------------------------- | ---- | ------------------------------ |
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
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |
| 6600107  | Too many commands or events. |

**Example**

```js
let avCommand = {command:'play'};
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
controller.sendControlCommand(avCommand).then(() => {
    console.info(`SendControlCommand successfully`);
}).catch((err) => {
    console.info(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

Sends a control command to the session through the controller. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Before using **sendControlCommand**, the controller must ensure that the AVSession has registered with the corresponding listener. For details about how to register the listener, see [Registering AVSession Listeners](#onplaypausestopplaynextplaypreviousfastforwardrewind10).

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                          |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| command  | [AVControlCommand](#avcontrolcommand10) | Yes  | Command to send.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.                    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------- |
| 6600101  | Session service exception.                |
| 6600102  | The session does not exist.     |
| 6600103  | The session controller does not exist.   |
| 6600105  | Invalid session command.           |
| 6600106  | The session is not activated.                |
| 6600107  | Too many commands or events.      |

**Example**

```js
let avCommand = {command:'play'};
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
controller.sendControlCommand(avCommand, function (err) {
    if (err) {
        console.info(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`SendControlCommand successfully`);
    }
});
```

### sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}): Promise\<void>

Sends a custom control command to the session through the controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                 | Mandatory| Description                          |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | string | Yes  | Name of the custom control command.|
| args | {[key: string]: any} | Yes  | Parameters in key-value pair format carried in the custom control command.|

> **NOTE**
>
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md).

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |
| 6600107  | Too many commands or events. |

**Example**

```js
let commandName = "my_command";
let args = {
    command : "This is my command"
}
await controller.sendCommonCommand(commandName, args).catch((err) => {
    console.info(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
})
```

### sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void

Sends a custom control command to the session through the controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                 | Mandatory| Description                          |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | string | Yes  | Name of the custom control command.|
| args | {[key: string]: any} | Yes  | Parameters in key-value pair format carried in the custom control command.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.                    |

> **NOTE**
>
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md).

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------- |
| 6600101  | Session service exception.                |
| 6600102  | The session does not exist.     |
| 6600103  | The session controller does not exist.   |
| 6600105  | Invalid session command.           |
| 6600106  | The session is not activated.                |
| 6600107  | Too many commands or events.      |

**Example**

```js
let commandName = "my_command";
let args = {
    command : "This is my command"
}
controller.sendCommonCommand(commandName, args, (err) => {
    if(err) {
        console.info(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
    }
})
```

### on('metadataChange')<sup>10+</sup>

on(type: 'metadataChange', filter: Array\<keyof AVMetadata> | 'all', callback: (data: AVMetadata) => void)

Subscribes to the metadata change event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'metadataChange'** is reported when the session metadata changes.|
| filter   | Array\<keyof&nbsp;[AVMetadata](#avmetadata10)\>&nbsp;&#124;&nbsp;'all' | Yes  | The value **'all'** indicates that any metadata field change will trigger the event, and **Array<keyof&nbsp;[AVMetadata](#avmetadata10)\>** indicates that only changes to the listed metadata field will trigger the event.|
| callback | (data: [AVMetadata](#avmetadata10)) => void                    | Yes  | Callback used for subscription. The **data** parameter in the callback indicates the changed metadata.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.on('metadataChange', 'all', (metadata) => {
    console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

let metaFilter = ['assetId', 'title', 'description'];
controller.on('metadataChange', metaFilter, (metadata) => {
    console.info(`on metadataChange assetId : ${metadata.assetId}`);
});
```

### on('playbackStateChange')<sup>10+</sup>

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void)

Subscribes to the playback state change event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'playbackStateChange'** is reported when the playback state changes.|
| filter   | Array\<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>&nbsp;&#124;&nbsp;'all' | Yes  | The value **'all'** indicates that any playback state field change will trigger the event, and **Array<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>** indicates that only changes to the listed playback state field will trigger the event.|
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void         | Yes  | Callback used for subscription. The **state** parameter in the callback indicates the changed playback state.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.on('playbackStateChange', 'all', (playbackState) => {
    console.info(`on playbackStateChange state : ${playbackState.state}`);
});

let playbackFilter = ['state', 'speed', 'loopMode'];
controller.on('playbackStateChange', playbackFilter, (playbackState) => {
    console.info(`on playbackStateChange state : ${playbackState.state}`);
});
```

### on('sessionEvent')<sup>10+</sup>

on(type: 'sessionEvent', callback: (sessionEvent: string, args: {[key:string]: Object}) => void): void

Subscribes to session event changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'sessionEvent'** is reported when the session event changes.|
| callback | (sessionEvent: string, args: {[key:string]: object}) => void         | Yes  | Callback used for subscription. **sessionEvent** in the callback indicates the name of the session event that changes, and **args** indicates the parameters carried in the event.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.on('sessionEvent', (sessionEvent, args) => {
    console.info(`OnSessionEvent, sessionEvent is ${sessionEvent}, args: ${JSON.stringify(args)}`);
});
```

### on('queueItemsChange')<sup>10+</sup>

on(type: 'queueItemsChange', callback: (items: Array<[AVQueueItem](#avqueueitem10)\>) => void): void

Subscribes to playlist item changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                  | Mandatory| Description                                                                        |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| type     | string                                                | Yes  | Event type. The event **'queueItemsChange'** is reported when one or more items in the playlist changes.|
| callback | (items: Array<[AVQueueItem](#avqueueitem10)\>) => void  | Yes  | Callback used for subscription. The **items** parameter in the callback indicates the changed items in the playlist.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.on('queueItemsChange', (items) => {
    console.info(`OnQueueItemsChange, items length is ${items.length}`);
});
```

### on('queueTitleChange')<sup>10+</sup>

on(type: 'queueTitleChange', callback: (title: string) => void): void

Subscribes to playlist name changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                                                                            |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The event **'queueTitleChange'** is reported when the playlist name changes.|
| callback | (title: string) => void | Yes  | Callback used for subscription. The **title** parameter in the callback indicates the changed playlist name.                               |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.on('queueTitleChange', (title) => {
    console.info(`queueTitleChange, title is ${title}`);
});
```

### on('extrasChange')<sup>10+</sup>

on(type: 'extrasChange', callback: (extras: {[key:string]: Object}) => void): void

Subscribes to custom media packet changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'extrasChange'** is reported when the provider sets a custom media packet.|
| callback | (extras: {[key:string]: object}) => void         | Yes  | Callback used for subscription. The **extras** parameter in the callback indicates the custom media packet set by the provider. This packet is the same as that set in **dispatchSessionEvent**.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |
| 401      | Parameter check failed                 |

**Example**

```js
controller.on('extrasChange', (extras) => {
    console.info(`Caught extrasChange event,the new extra is: ${JSON.stringify(extras)}`);
});
```

### on('sessionDestroy')<sup>10+</sup>

on(type: 'sessionDestroy', callback: () => void)

Subscribes to the session destruction event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type      | Mandatory| Description                                                        |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | Yes  | Event type. The event **'sessionDestroy'** is reported when the session is destroyed.|
| callback | () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                 |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.on('sessionDestroy', () => {
    console.info(`on sessionDestroy : SUCCESS `);
});
```

### on('activeStateChange')<sup>10+</sup>

on(type: 'activeStateChange', callback: (isActive: boolean) => void)

Subscribes to the session activation state change event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                      | Yes  | Event type. The event **'activeStateChange'** is reported when the activation state of the session changes.|
| callback | (isActive: boolean) => void | Yes  | Callback used for subscription. The **isActive** parameter in the callback specifies whether the session is activated. The value **true** means that the service is activated, and **false** means the opposite.                  |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ----------------------------- |
| 6600101  | Session service exception. |
| 6600103  |The session controller does not exist. |

**Example**

```js
controller.on('activeStateChange', (isActive) => {
    console.info(`on activeStateChange : SUCCESS : isActive ${isActive}`);
});
```

### on('validCommandChange')<sup>10+</sup>

on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void)

Subscribes to valid command changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'validCommandChange'** is reported when the valid commands supported by the session changes.|
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype10)\>) => void | Yes  | Callback used for subscription. The **commands** parameter in the callback is a set of valid commands.                    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.on('validCommandChange', (validCommands) => {
    console.info(`validCommandChange : SUCCESS : size : ${validCommands.size}`);
    console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});
```

### on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void

Subscribes to output device changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The event **'outputDeviceChange'** is reported when the output device changes.|
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | Yes  | Callback used for subscription. The **device** parameter in the callback indicates the output device information.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ----------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```js
controller.on('outputDeviceChange', (device) => {
    console.info(`on outputDeviceChange device isRemote : ${device.isRemote}`);
});
```

### off('metadataChange')<sup>10+</sup>

off(type: 'metadataChange', callback?: (data: AVMetadata) => void)

Unsubscribes from metadata changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                              | Mandatory| Description                                                   |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------ |
| type     | string                                           | Yes  | Event type. The event **'metadataChange'** is reported when the session metadata changes.        |
| callback | (data: [AVMetadata](#avmetadata10)) => void        | No  | Callback used for subscription. The **data** parameter in the callback indicates the changed metadata.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
controller.off('metadataChange');
```

### off('playbackStateChange')<sup>10+</sup>

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void)

Unsubscribes from playback state changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | Yes  | Event type. The event **'playbackStateChange'** is reported when the playback state changes.   |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void         | No  | Callback used for subscription. The **state** parameter in the callback indicates the changed playback state.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
controller.off('playbackStateChange');
```

### off('sessionEvent')<sup>10+</sup>

off(type: 'sessionEvent', callback?: (sessionEvent: string, args: {[key:string]: Obejct}) => void): void

Unsubscribes from session event changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'sessionEvent'**.   |
| callback | (sessionEvent: string, args: {[key:string]: object}) => void         | No  | Callback used for unsubscription. **sessionEvent** in the callback indicates the name of the session event that changes, and **args** indicates the parameters carried in the event.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
controller.off('sessionEvent');
```

### off('queueItemsChange')<sup>10+</sup>

off(type: 'queueItemsChange', callback?: (items: Array<[AVQueueItem](#avqueueitem10)\>) => void): void

Unsubscribes from playback item changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                                | Mandatory| Description                                                                                               |
| -------- | ---------------------------------------------------- | ---- | --------------------------------------------------------------------------------------------------- |
| type     | string                                               | Yes  | Event type. The value is fixed at **'queueItemsChange'**.                                                    |
| callback | (items: Array<[AVQueueItem](#avqueueitem10)\>) => void | No  | Callback used for unsubscription. The **items** parameter in the callback indicates the changed items in the playback.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
controller.off('queueItemsChange');
```

### off('queueTitleChange')<sup>10+</sup>

off(type: 'queueTitleChange', callback?: (title: string) => void): void

Unsubscribes from playlist name changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                   | Mandatory| Description                                                                                                   |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The value is fixed at **'queueTitleChange'**.                                                        |
| callback | (title: string) => void | No  | Callback used for unsubscription. The **items** parameter in the callback indicates the changed playlist name.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
controller.off('queueTitleChange');
```

### off('extrasChange')<sup>10+</sup>

off(type: 'extrasChange', callback?: (extras: {[key:string]: Object}) => void): void

Unsubscribes from custom media packet changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                   | Mandatory| Description                                                                                                   |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The value is fixed at **'extrasChange'**.                                                        |
| callback | ({[key:string]: Object}) => void | No  | Callback used for unsubscription.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ----------------                       |
| 6600101  | Session service exception.             |
| 6600103  | The session controller does not exist. |
| 401      | Parameter check failed                 |

**Example**

```js
controller.off('extrasChange');
```

### off('sessionDestroy')<sup>10+</sup>

off(type: 'sessionDestroy', callback?: () => void)

Unsubscribes from the session destruction event. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type      | Mandatory| Description                                                     |
| -------- | ---------- | ---- | ----------------------------------------------------- |
| type     | string     | Yes  | Event type. The event **'sessionDestroy'** is reported when the session is destroyed.        |
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
controller.off('sessionDestroy');
```

### off('activeStateChange')<sup>10+</sup>

off(type: 'activeStateChange', callback?: (isActive: boolean) => void)

Unsubscribes from session activation state changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                     |
| -------- | --------------------------- | ---- | ----------------------------------------------------- |
| type     | string                      | Yes  | Event type. The event **'activeStateChange'** is reported when the session activation state changes.     |
| callback | (isActive: boolean) => void | No  | Callback used for unsubscription. The **isActive** parameter in the callback specifies whether the session is activated. The value **true** means that the session is activated, and **false** means the opposite.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                  |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
controller.off('activeStateChange');
```

### off('validCommandChange')<sup>10+</sup>

off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void)

Unsubscribes from valid command changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | Yes  | Event type. The event **'validCommandChange'** is reported when the supported commands change.        |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype10)\>) => void | No  | Callback used for unsubscription. The **commands** parameter in the callback is a set of valid commands.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message          |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
controller.off('validCommandChange');
```

### off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void

Unsubscribes from output device changes. This API is called by the controller.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                     |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The event **'outputDeviceChange'** is reported when the output device changes.     |
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | No  | Callback used for unsubscription. The **device** parameter in the callback indicates the output device information.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID | Error Message         |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**Example**

```js
controller.off('outputDeviceChange');
```

## SessionToken

Describes the information about a session token.

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

| Name     | Type  | Mandatory| Description        |
| :-------- | :----- | :--- | :----------- |
| sessionId | string | Yes  | Session ID.      |
| pid       | number | Yes  | Process ID of the session.|
| uid       | number | Yes  | User ID.      |

## AVSessionType<sup>10+<sup>
Enumerates the session types supported by the session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name | Type  | Description|
| ----- | ------ | ---- |
| audio | string | Audio session.|
| video | string | Video session.|

## AVSessionDescriptor

Declares the session descriptor.

**System capability**: SystemCapability.Multimedia.AVSession.Manager

**System API**: This is a system API.

| Name        | Type                                                        | Readable| Writable| Description                                               |
| ------------ | ------------------------------------------------------------ | ---- | --------------------------------------------------- | --------------------------------------------------- |
| sessionId    | string                                                       | Yes | No| Session ID.                                             |
| type         | [AVSessionType](#avsessiontype10)                              | Yes  | No | Session type.                                           |
| sessionTag   | string                                                       | Yes  | No | Custom session name.                                   |
| elementName  | [ElementName](js-apis-bundle-ElementName.md)                 | Yes  | No | Information about the application to which the session belongs, including the bundle name and ability name.|
| isActive     | boolean                                                      | Yes  | No | Whether the session is activated.                                     |
| isTopSession | boolean                                                      | Yes  | No | Whether the session is the top session.                               |
| outputDevice | [OutputDeviceInfo](#outputdeviceinfo10)                        | Yes  | No | Information about the output device.                                 |

## AVControlCommandType<sup>10+</sup>

Enumerates the commands that can be sent to a session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name          | Type  | Description        |
| -------------- | ------ | ------------ |
| play           | string | Play the media.        |
| pause          | string | Pause the playback.        |
| stop           | string | Stop the playback.        |
| playNext       | string | Play the next media asset.      |
| playPrevious   | string | Play the previous media asset.      |
| fastForward    | string | Fast-forward.        |
| rewind         | string | Rewind.        |
| seek           | string | Seek to a playback position.|
| setSpeed       | string | Set the playback speed.|
| setLoopMode    | string | Set the loop mode.|
| toggleFavorite | string | Favorite the media asset.    |

## AVControlCommand<sup>10+</sup>

Describes the command that can be sent to the session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name     | Type                                             | Mandatory| Description          |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVControlCommandType](#avcontrolcommandtype10)     | Yes  | Command.          |
| parameter | [LoopMode](#loopmode10) &#124; string &#124; number | No  | Parameters carried in the command.|

## AVMetadata<sup>10+</sup>

Describes the media metadata.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name           | Type                     | Mandatory| Description                                                                 |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| assetId         | string                  | Yes  | Media ID.                                                              |
| title           | string                  | No  | Title.                                                                |
| artist          | string                  | No  | Artist.                                                               |
| author          | string                  | No  | Author.                                                              |
| album           | string                  | No  | Album name.                                                              |
| writer          | string                  | No  | Writer.                                                               |
| composer        | string                  | No  | composer.                                                               |
| duration        | number                  | No  | Media duration, in ms.                                                 |
| mediaImage      | image.PixelMap &#124; string | No  | Pixel map or image path (local path or network path) of the image.                            |
| publishDate     | Date                    | No  | Release date.                                                              |
| subtitle        | string                  | No  | Subtitle.                                                               |
| description     | string                  | No  | Media description.                                                              |
| lyric           | string                  | No  | Lyric file path (local path or network path).|
| previousAssetId | string                  | No  | ID of the previous media asset.                                                           |
| nextAssetId     | string                  | No  | ID of the next media asset.                                                           |

## AVMediaDescription<sup>10+</sup>

Describes the attributes related to the media metadata of the playlist.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name        | Type                   | Mandatory | Description                    |
| ------------ | ----------------------- | ---- | ----------------------- |
| mediaId      | string                  | Yes  | Media ID of the playlist.         |
| title        | string                  | No  | Name of the playlist.       |
| subtitle     | string                  | No  | Subname of the playlist.     |
| description  | string                  | No  | Description of the playlist.  |
| icon         | image.PixelMap          | No  | Pixel map of the image of the playlist.|
| iconUri      | string                  | No  | Path of the image of the playlist.|
| extras       | {[key: string]: any}    | No  | Additional fields of the playlist.    |
| mediaUri     | string                  | No  | Media URI.        |

## AVQueueItem<sup>10+</sup>

Describes the attributes of an item in the playlist.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name        | Type                                       | Mandatory| Description                       |
| ------------ | ------------------------------------------ | ---- | --------------------------- |
| itemId       | number                                     | Yes  | ID of an item in the playlist.         |
| description  | [AVMediaDescription](#avmediadescription10)  | Yes  | Media metadata of the item in the playlist.  |

## AVPlaybackState<sup>10+</sup>

Describes the information related to the media playback state.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name        | Type                                 | Mandatory| Description    |
| ------------ | ------------------------------------- | ---- | ------- |
| state        | [PlaybackState](#playbackstate)       | No  | Playback state.|
| speed        | number                                | No  | Playback speed.|
| position     | [PlaybackPosition](#playbackposition) | No  | Playback position.|
| bufferedTime | number                                | No  | Buffered time.|
| loopMode     | [LoopMode](#loopmode10)                 | No  | Loop mode.|
| isFavorite   | boolean                               | No  | Whether the media asset is favorited.|
| activeItemId<sup>10+</sup> | number                  | No  | ID of the item that is being played.|
| extras<sup>10+</sup> | {[key: string]: Object}       | No  | Custom media data.|

## PlaybackPosition<sup>10+</sup>

Describes the information related to the playback position.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name       | Type  | Mandatory| Description              |
| ----------- | ------ | ---- | ------------------ |
| elapsedTime | number | Yes  | Elapsed time, in ms.|
| updateTime  | number | Yes  | Updated time, in ms.|

## OutputDeviceInfo<sup>10+</sup>

Describes the information related to the output device.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name      | Type          | Mandatory| Description                  |
| ---------- | -------------- | ---- | ---------------------- |
| isRemote   | boolean        | Yes  | Whether the device is connected.        |
| audioDeviceId   | Array<number\> | Yes  | IDs of output devices. |
| deviceName | Array<string\> | Yes  | Names of output devices.   |

## PlaybackState<sup>10+</sup>

Enumerates the media playback states.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| PLAYBACK_STATE_INITIAL      | 0    | Initial.    |
| PLAYBACK_STATE_PREPARE      | 1    | Preparing. |
| PLAYBACK_STATE_PLAY         | 2    | Playing.    |
| PLAYBACK_STATE_PAUSE        | 3    | Paused.        |
| PLAYBACK_STATE_FAST_FORWARD | 4    | Fast-forwarding.        |
| PLAYBACK_STATE_REWIND       | 5    | Rewinding.        |
| PLAYBACK_STATE_STOP         | 6    | Stopped.        |


## LoopMode<sup>10+</sup>

Enumerates the loop modes of media playback.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name              | Value  | Description    |
| ------------------ | ---- | -------- |
| LOOP_MODE_SEQUENCE | 0    | Sequential playback.|
| LOOP_MODE_SINGLE   | 1    | Single loop.|
| LOOP_MODE_LIST     | 2    | Playlist loop.|
| LOOP_MODE_SHUFFLE  | 3    | Shuffle.|

## AVSessionErrorCode<sup>10+</sup>

Enumerates the error codes used in the media session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                          | Value     | Description                            |
| ------------------------------ | ------- | ------------------------------- |
| ERR_CODE_SERVICE_EXCEPTION     | 6600101 | Session service exception.               |
| ERR_CODE_SESSION_NOT_EXIST     | 6600102 | The session does not exist.      |
| ERR_CODE_CONTROLLER_NOT_EXIST  | 6600103 | The session controller does not exist.   |
| ERR_CODE_REMOTE_CONNECTION_ERR | 6600104 | The remote session  connection failed.         |
| ERR_CODE_COMMAND_INVALID       | 6600105 | Invalid session command.           |
| ERR_CODE_SESSION_INACTIVE      | 6600106 | The session is not activated.                |
| ERR_CODE_MESSAGE_OVERLOAD      | 6600107 | Too many commands or events.       |

<!--no_check-->
