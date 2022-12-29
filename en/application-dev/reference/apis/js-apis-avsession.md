# AVSession Management

The **avSession** module provides APIs for media playback control so that applications can access the system's Media Controller.

This module provides the following common features related to media sessions:
- [AVSession](#section652893): used to set session metadata, playback state information, and more.
- [AVSessionController](#section974602): used to obtain session IDs, send commands and events to sessions, and obtain the session metadata and playback state information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import avSession from '@ohos.multimedia.avsession';
```

## avSession.createAVSession

createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>

Creates a media session. This API uses a promise to return the result. An ability can have only one session, and repeated calling of this API fails.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                           | Mandatory| Description                          |
| ------ | ------------------------------- | ---- | ------------------------------ |
| context| [Context](../../ability/context-userguide.md) | Yes| Application context, which provides application environment information.|
| tag    | string                          | Yes  | Custom session name.            |
| type   | [AVSessionType](#avsessiontype) | Yes  | Session type, which can be audio or video.|


**Return value**

| Type                             | Description                                                        |
| --------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSession](#avsession)\> | Promise used to return the media session obtained, which can be used to obtain the session ID, set the metadata and playback state information, and send key events.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

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

## avSession.createAVSession

createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void

Creates a media session. This API uses an asynchronous callback to return the result. An ability can have only one session, and repeated calling of this API fails.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context| [Context](../../ability/context-userguide.md) | Yes| Application context, which provides application environment information.    |
| tag      | string                                  | Yes  | Custom session name.                                          |
| type     | [AVSessionType](#avsessiontype)         | Yes  | Session type, which can be audio or video.                              |
| callback | AsyncCallback<[AVSession](#avsession)\> | Yes  | Callback used to return the media session obtained, which can be used to obtain the session ID, set the metadata and playback state information, and send key events.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

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
| 6600101  | Session service exception |

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

**Required permissions**: ohos.permission.MANAGE_MEDIA_RESOURCES (available only to system applications)

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
| 6600101  |Session service exception |

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
| Promise<[AVSessionController](#avsessioncontroller)\> | Promise used to return the session controller created, which can be used to obtain the session ID,<br>send commands and events to sessions, and obtain metadata and playback state information.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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
| callback  | AsyncCallback<[AVSessionController](#avsessioncontroller)\> | Yes  | Callback used to return the session controller created, which can be used to obtain the session ID,<br>send commands and events to sessions, and obtain metadata and playback state information.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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
| Promise<void\> | Promise used to return the result. If the cast is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600104  | The remote session  connection failed |

**Example**

```js
import audio from '@ohos.multimedia.audio';

let audioManager = audio.getAudioManager();
let audioDevices;
await audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
    audioDevices = data;
    console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err) => {
    console.info(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

avSession.castAudio('all', audioDevices).then(() => {
    console.info('CreateController : SUCCESS');
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
| callback     | AsyncCallback<void\>                       | Yes  | Callback used to return the result. If the casting is successful, **err** is **undefined**; otherwise, **err** is an error object.                       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600104  | The remote session  connection failed |

**Example**

```js
import audio from '@ohos.multimedia.audio';

let audioManager = audio.getAudioManager();
let audioDevices;
await audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
    audioDevices = data;
    console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err) => {
    console.info(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

avSession.castAudio('all', audioDevices, function (err) {
    if (err) {
        console.info(`CastAudio BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('CastAudio : SUCCESS ');
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
| 6600101  | Session service exception |

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
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **session** parameter in the callback describes a media session. The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

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

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Event type. The event **'sessionServiceDie'** is reported when the session service dies.|
| callback | callback: () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                               |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**Example**

```js
avSession.on('sessionServiceDie', () => {
    console.info('on sessionServiceDie  : session is  Died ');
});
```

## avSession.off('sessionServiceDie')

off(type: 'sessionServiceDie', callback?: () => void): void

Unsubscribes from session service death events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                   | Mandatory |      Description                                              |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | Yes   | Event type. The event **'sessionServiceDie'** is reported when the session service dies.|
| callback | callback: () => void   | No   | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

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
| Promise<void\> | Promise used to return the result. If the event is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600105  | Invalid session command |

**Example**

```js

let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false}; 

avSession.sendSystemAVKeyEvent(event).then(() => {
    console.info('SendSystemAVKeyEvent Successfully');
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
| callback | AsyncCallback<void\>                                         | Yes  | Callback used to return the result. If the event is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600105  | Invalid session command |

**Example**

```js
let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false}; 

avSession.sendSystemAVKeyEvent(event, function (err) {
    if (err) {
        console.info(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('SendSystemAVKeyEvent : SUCCESS ');
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
| command | [AVControlCommand](#avcontrolcommand) | Yes  | Command to send.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600105  | Invalid session command |
| 6600107  | Command or event overload |

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
    console.info('SendSystemControlCommand successfully');
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
| command  | [AVControlCommand](#avcontrolcommand) | Yes  | Command to send.  |
| callback | AsyncCallback<void\>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600105  | Invalid session command |
| 6600107  | Command or event overload |

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
        console.info('sendSystemControlCommand successfully');
    }
});
```

## AVSession<a name="section652893"></a>

An **AVSession** object is created by calling [avSession.createAVSession](#avsessioncreateavsession). The object enables you to obtain the session ID and set the metadata and playback state. 

### Attributes

**System capability**: SystemCapability.Multimedia.AVSession.Core


| Name     | Type  | Readable| Writable| Description                         |
| :-------- | :----- | :--- | :--- | :---------------------------- |
| sessionId | string | Yes  | No  | Unique session ID of the **AVSession** object.|


**Example**
```js
let sessionId = session.sessionId;
```

### setAVMetadata

setAVMetadata(data: AVMetadata): Promise\<void>

Sets session metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                     | Mandatory| Description        |
| ------ | ------------------------- | ---- | ------------ |
| data   | [AVMetadata](#avmetadata) | Yes  | Session metadata.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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
    console.info('SetAVMetadata successfully');
}).catch((err) => {
    console.info(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVMetadata

setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void

Sets session metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                 |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [AVMetadata](#avmetadata) | Yes  | Session metadata.                         |
| callback | AsyncCallback<void\>      | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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
        console.info('SetAVMetadata successfully');
    }
});
```

### setAVPlaybackState

setAVPlaybackState(state: AVPlaybackState): Promise\<void>

Sets information related to the session playback state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                               | Mandatory| Description                                          |
| ------ | ----------------------------------- | ---- | ---------------------------------------------- |
| data   | [AVPlaybackState](#avplaybackstate) | Yes  | Information related to the session playback state.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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
    console.info('SetAVPlaybackState successfully');
}).catch((err) => {
    console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVPlaybackState

setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void

Sets information related to the session playback state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                          |
| -------- | ----------------------------------- | ---- | ---------------------------------------------- |
| data     | [AVPlaybackState](#avplaybackstate) | Yes  | Information related to the session playback state.|
| callback | AsyncCallback<void\>                | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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
        console.info('SetAVPlaybackState successfully');
    }
});
```

### setLaunchAbility

setLaunchAbility(ability: WantAgent): Promise\<void>

Sets a launcher ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                             | Mandatory| Description                                                       |
| ------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| ability | [WantAgent](js-apis-wantAgent.md) | Yes  | Application attributes, such as the bundle name, ability name, and deviceID.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
import wantAgent from '@ohos.wantAgent';

// WantAgentInfo object
let wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
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
        console.info('SetLaunchAbility successfully');
    }).catch((err) => {
        console.info(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
    });
});
```

### setLaunchAbility

setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void

Sets a launcher ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                             | Mandatory| Description                                                       |
| -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| ability  | [WantAgent](js-apis-wantAgent.md) | Yes  | Application attributes, such as the bundle name, ability name, and deviceID.|
| callback | AsyncCallback<void\>              | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
import wantAgent from '@ohos.wantAgent';

// WantAgentInfo object
let wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
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
            console.info('SetLaunchAbility successfully');
        }
    });
});
```

### getController

getController(): Promise\<AVSessionController>

Obtains the controller corresponding to this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                | Description                         |
| ---------------------------------------------------- | ----------------------------- |
| Promise<[AVSessionController](#avsessioncontroller)> | Promise used to return the session controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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

### getController

getController(callback: AsyncCallback\<AVSessionController>): void

Obtains the controller corresponding to this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                       | Mandatory| Description                      |
| -------- | ----------------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVSessionController](#avsessioncontroller)\> | Yes  | Callback used to return the session controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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

### getOutputDevice

getOutputDevice(): Promise\<OutputDeviceInfo>

Obtains information about the output device for this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                          | Description                             |
| ---------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo)> | Promise used to return the output device information.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.getOutputDevice().then((outputDeviceInfo) => {
    console.info(`GetOutputDevice : SUCCESS : isRemote : ${outputDeviceInfo.isRemote}`);
}).catch((err) => {
    console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getOutputDevice

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

Obtains information about the output device for this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                 | Mandatory| Description                          |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo)\> | Yes  | Callback used to return the information obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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

### activate

activate(): Promise\<void>

Activates this session. A session can be used only after being activated. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the session is activated, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.activate().then(() => {
    console.info('Activate : SUCCESS ');
}).catch((err) => {
    console.info(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### activate

activate(callback: AsyncCallback\<void>): void

Activates this session. A session can be used only after being activated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the session is activated, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.activate(function (err) {
    if (err) {
        console.info(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('Activate : SUCCESS ');
    }
});
```

### deactivate

deactivate(): Promise\<void>

Deactivates this session. You can use [activate](#activate) to activate the session again. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the session is deactivated, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.deactivate().then(() => {
    console.info('Deactivate : SUCCESS ');
}).catch((err) => {
    console.info(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### deactivate

deactivate(callback: AsyncCallback\<void>): void

Deactivates this session. This API uses an asynchronous callback to return the result.

Deactivates this session. You can use [activate](#activate) to activate the session again.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the session is deactivated, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.deactivate(function (err) {
    if (err) {
        console.info(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('Deactivate : SUCCESS ');
    }
});
```

### destroy

destroy(): Promise\<void>

Destroys this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the session is destroyed, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.destroy().then(() => {
    console.info('Destroy : SUCCESS ');
}).catch((err) => {
    console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### destroy

destroy(callback: AsyncCallback\<void>): void

Destroys this session. This API uses an asynchronous callback to return the result.


**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the session is destroyed, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.destroy(function (err) {
    if (err) {
        console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('Destroy : SUCCESS ');
    }
});
```

### on('play'|'pause'|'stop'|'playNext'|'playPrevious'|'fastForward'|'rewind')

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
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.on('play', () => {
    console.info('on play entry');
});
session.on('pause', () => {
    console.info('on pause entry');
});
session.on('stop', () => {
    console.info('on stop entry');
});
session.on('playNext', () => {
    console.info('on playNext entry');
});
session.on('playPrevious', () => {
    console.info('on playPrevious entry');
});
session.on('fastForward', () => {
    console.info('on fastForward entry');
});
session.on('rewind', () => {
    console.info('on rewind entry');
});
```

### on('seek')

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
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**
The session does not exist
```js
session.on('seek', (time) => {
    console.info(`on seek entry time : ${time}`);
});
```

### on('setSpeed')

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
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.on('setSpeed', (speed) => {
    console.info(`on setSpeed speed : ${speed}`);
});
```

### on('setLoopMode')

on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void

Subscribes to the event for setting the loop mode.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                  | Mandatory| Description |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | Yes  | Event type. The event **'setLoopMode'** is reported when the command for setting the loop mode is sent to the session.|
| callback | (mode: [LoopMode](#loopmode)) => void | Yes  | Callback used for subscription. The **mode** parameter in the callback indicates the loop mode.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.on('setLoopMode', (mode) => {
    console.info(`on setLoopMode mode : ${mode}`);
});
```

### on('toggleFavorite')

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
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.on('toggleFavorite', (assetId) => {
    console.info(`on toggleFavorite mode : ${assetId}`);
});
```

### on('handleKeyEvent')

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
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.on('handleKeyEvent', (event) => {
    console.info(`on handleKeyEvent event : ${event}`);
});
```

### on('outputDeviceChange')

on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void

Subscribes to output device changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The event **'outputDeviceChange'** is reported when the output device changes.|
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo)) => void | Yes  | Callback used for subscription. The **device** parameter in the callback indicates the output device information.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.on('outputDeviceChange', (device) => {
    console.info(`on outputDeviceChange device isRemote : ${device.isRemote}`);
});
```

### off('play'|'pause'|'stop'|'playNext'|'playPrevious'|'fastForward'|'rewind')

off(type: 'play' | 'pause' | 'stop' | 'playNext' | 'playPrevious' | 'fastForward' | 'rewind', callback?: () => void): void

Unsubscribes from playback command events.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                                                                                        |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | Yes  | Event type. The following events are supported: **'play'**, **'pause'**, **'stop'**, **'playNext'**, **'playPrevious'**, **'fastForward'**, and **'rewind'**.|
| callback | callback: () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

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

### off('seek')

off(type: 'seek', callback?: (time: number) => void): void

Unsubscribes from the seek event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                         |
| -------- | ---------------------- | ---- | ----------------------------------------- |
| type     | string                 | Yes  | Event type. The value is fixed at **'seek'**.      |
| callback | (time: number) => void | No  | Callback used for unsubscription. The **time** parameter in the callback indicates the time to seek to, in milliseconds.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.off('seek');
```

### off('setSpeed')

off(type: 'setSpeed', callback?: (speed: number) => void): void

Unsubscribes from the event for setting the playback speed.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                          |
| -------- | ----------------------- | ---- | -------------------------------------------|
| type     | string                  | Yes  | Event type. The value is fixed at **'setSpeed'**.   |
| callback | (speed: number) => void | No  | Callback used for unsubscription. The **speed** parameter in the callback indicates the playback speed.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.off('setSpeed');
```

### off('setLoopMode')

off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void

Unsubscribes from the event for setting loop mode.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description    |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | Yes  | Event type. The value is fixed at **'setLoopMode'**.|
| callback | (mode: [LoopMode](#loopmode)) => void | No  | Callback used for unsubscription. The **mode** parameter in the callback indicates the loop mode.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.off('setLoopMode');
```

### off('toggleFavorite')

off(type: 'toggleFavorite', callback?: (assetId: string) => void): void

Unsubscribes from the event for favoriting a media asset.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | -------------------------------------------------------- |
| type     | string                    | Yes  | Event type. The value is fixed at **'toggleFavorite'**.           |
| callback | (assetId: string) => void | No  | Callback used for unsubscription. The **assetId** parameter in the callback indicates the media asset ID.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.off('toggleFavorite');
```

### off('handleKeyEvent')

off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void

Unsubscribes from the key event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'handleKeyEvent'**.            |
| callback | (event: [KeyEvent](js-apis-keyevent.md)) => void | No  | Callback used for unsubscription. The **event** parameter in the callback indicates the key event.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.off('handleKeyEvent');
```

### off('outputDeviceChange')

off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void

Unsubscribes from playback device changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                     |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'outputDeviceChange'**.    |
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo)) => void | No  | Callback used for unsubscription. The **device** parameter in the callback indicates the output device information.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**Example**

```js
session.off('outputDeviceChange');
```



## AVSessionController<a name="section974602"></a>

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

### getAVPlaybackState

getAVPlaybackState(): Promise\<AVPlaybackState>

Obtains the information related to the playback state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                         | Description                       |
| --------------------------------------------- | --------------------------- |
| Promise<[AVPlaybackState](#avplaybackstate)\> | Promise used to return the **AVPlaybackState** object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**Example**
```js
controller.getAVPlaybackState().then((playbackState) => {
    console.info(`GetAVPlaybackState : SUCCESS : state : ${playbackState.state}`);
}).catch((err) => {
    console.info(`GetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVPlaybackState

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

Obtains the information related to the playback state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                        |
| -------- | --------------------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback<[AVPlaybackState](#avplaybackstate)\> | Yes  | Callback used to return the **AVPlaybackState** object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

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

### getAVMetadata

getAVMetadata(): Promise\<AVMetadata>

Obtains the session metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<[AVMetadata](#avmetadata)\> | Promise used to return the metadata obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**Example**
```js
controller.getAVMetadata().then((metadata) => {
    console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
}).catch((err) => {
    console.info(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVMetadata

getAVMetadata(callback: AsyncCallback\<AVMetadata>): void

Obtains the session metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVMetadata](#avmetadata)\> | Yes  | Callback used to return the metadata obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

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

### getOutputDevice

getOutputDevice(): Promise\<OutputDeviceInfo>

Obtains the output device information. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                           | Description                             |
| ----------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo)\> | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**Example**
```js
controller.getOutputDevice().then((deviceInfo) => {
    console.info(`GetOutputDevice : SUCCESS : isRemote : ${deviceInfo.isRemote}`);
}).catch((err) => {
    console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getOutputDevice

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

Obtains the output device information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                 | Mandatory| Description                          |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo)\> | Yes  | Callback used to return the information obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

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

### sendAVKeyEvent

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
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |
| 6600105  | Invalid session command |
| 6600106  | The session not active |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the event is sent, no value is returned; otherwise, an error object is returned.|

**Example**

```js
let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {action:2, key:keyItem, keys:[keyItem]};

controller.sendAVKeyEvent(event).then(() => {
    console.info('SendAVKeyEvent Successfully');
}).catch((err) => {
    console.info(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendAVKeyEvent

sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

Sends a key event to the session corresponding to this controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description      |
| -------- | ------------------------------------------------------------ | ---- | ---------- |
| event    | [KeyEvent](js-apis-keyevent.md) | Yes  | Key event.|
| callback | AsyncCallback<void\>                                         | Yes  | Callback used to return the result. If the event is sent, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |
| 6600105  | Invalid session command |
| 6600106  | The session not active |

**Example**

```js
let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {action:2, key:keyItem, keys:[keyItem]};

controller.sendAVKeyEvent(event, function (err) {
    if (err) {
        console.info(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('SendAVKeyEvent Successfully');
    }
});
```

### getLaunchAbility

getLaunchAbility(): Promise\<WantAgent>

Obtains the **WantAgent** object saved by the application in the session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                       | Description                                                        |
| ------------------------------------------- | ------------------------------------------------------------ |
| Promise<[WantAgent](js-apis-wantAgent.md)\> | Promise used to return the object saved by calling [setLaunchAbility](#setlaunchability). The object includes the application attribute, such as the bundle name, ability name, and device ID.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**Example**

```js
import wantAgent from '@ohos.wantAgent';

controller.getLaunchAbility().then((agent) => {
    console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
}).catch((err) => {
    console.info(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getLaunchAbility

getLaunchAbility(callback: AsyncCallback\<WantAgent>): void

Obtains the **WantAgent** object saved by the application in the session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description                                                        |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[WantAgent](js-apis-wantAgent.md)\> | Yes  | Callback used to return the object saved by calling [setLaunchAbility](#setlaunchability). The object includes the application attribute, such as the bundle name, ability name, and device ID.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**Example**

```js
import wantAgent from '@ohos.wantAgent';

controller.getLaunchAbility(function (err, agent) {
    if (err) {
        console.info(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
    }
});
```

### getRealPlaybackPositionSync

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
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**Example**

```js
let time = controller.getRealPlaybackPositionSync();
```

### isActive

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
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**Example**

```js
controller.isActive().then((isActive) => {
    console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
}).catch((err) => {
    console.info(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### isActive

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
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

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

### destroy

destroy(): Promise\<void>

Destroys this controller. A controller can no longer be used after being destroyed. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the controller is destroyed, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**Example**

```js
controller.destroy().then(() => {
    console.info('Destroy : SUCCESS ');
}).catch((err) => {
    console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### destroy

destroy(callback: AsyncCallback\<void>): void

Destroys this controller. A controller can no longer be used after being destroyed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the controller is destroyed, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**Example**

```js
controller.destroy(function (err) {
    if (err) {
        console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('Destroy : SUCCESS ');
    }
});
```

### getValidCommands

getValidCommands(): Promise\<Array\<AVControlCommandType>>

Obtains valid commands supported by the session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<Array<[AVControlCommandType](#avcontrolcommandtype)\>\> | Promise used to return a set of valid commands.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**Example**

```js
controller.getValidCommands.then((validCommands) => {
    console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
}).catch((err) => {
    console.info(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getValidCommands

getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void

Obtains valid commands supported by the session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<[AVControlCommandType](#avcontrolcommandtype)\>\> | Yes  | Callback used to return a set of valid commands.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

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

### sendControlCommand

sendControlCommand(command: AVControlCommand): Promise\<void>

Sends a control command to the session through the controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                 | Mandatory| Description                          |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | [AVControlCommand](#avcontrolcommand) | Yes  | Command to send.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |
| 6600105  | Invalid session command |
| 6600106  | The session not active |
| 6600107  | Command or event overload |

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
    console.info('SendControlCommand successfully');
}).catch((err) => {
    console.info(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand

sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

Sends a control command to the session through the controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                          |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| command  | [AVControlCommand](#avcontrolcommand) | Yes  | Command to send.|
| callback | AsyncCallback<void\>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.                    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------- |
| 6600101  | Session service exception                |
| 6600102  | The session does not exist      |
| 6600103  | The session controller does not exist   |
| 6600105  | Invalid session command           |
| 6600106  | The session not active                |
| 6600107  | Command or event overload       |

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
        console.info('SendControlCommand successfully');
    }
});
```

### on('metadataChange')

on(type: 'metadataChange', filter: Array\<keyof AVMetadata> | 'all', callback: (data: AVMetadata) => void)

Subscribes to the metadata change event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'metadataChange'** is reported when the session metadata changes.|
| filter   | Array\<keyof&nbsp;[AVMetadata](#avmetadata)\>&nbsp;&#124;&nbsp;'all' | Yes  | The value **'all'** indicates that any metadata field change will trigger the event, and **Array<keyof [AVMetadata](#avmetadata)\>** indicates that only changes to the listed metadata field will trigger the event.|
| callback | (data: [AVMetadata](#avmetadata)) => void                    | Yes  | Callback used for subscription. The **data** parameter in the callback indicates the changed metadata.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

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

### on('playbackStateChange')

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void)

Subscribes to the playback state change event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'playbackStateChange'** is reported when the playback state changes.|
| filter   | Array\<keyof&nbsp;[AVPlaybackState](#avplaybackstate)\>&nbsp;&#124;&nbsp;'all' | Yes  | The value **'all'** indicates that any playback state field change will trigger the event, and **Array<keyof [AVPlaybackState](#avplaybackstate)\>** indicates that only changes to the listed playback state field will trigger the event.|
| callback | (state: [AVPlaybackState](#avplaybackstate)) => void         | Yes  | Callback used for subscription. The **state** parameter in the callback indicates the changed playback state.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

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

### on('sessionDestroy')

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
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**Example**

```js
controller.on('sessionDestroy', () => {
    console.info('on sessionDestroy : SUCCESS ');
});
```

### on('activeStateChange')

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
| 6600101  | Session service exception |
| 6600103  |The session controller does not exist |

**Example**

```js
controller.on('activeStateChange', (isActive) => {
    console.info(`on activeStateChange : SUCCESS : isActive ${isActive}`);
});
```

### on('validCommandChange')

on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void)

Subscribes to valid command changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'validCommandChange'** is reported when the valid commands supported by the session changes.|
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype)\>) => void | Yes  | Callback used for subscription. The **commands** parameter in the callback is a set of valid commands.                    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**Example**

```js
controller.on('validCommandChange', (validCommands) => {
    console.info(`validCommandChange : SUCCESS : size : ${validCommands.size}`);
    console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});
```

### on('outputDeviceChange')

on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void

Subscribes to output device changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The event **'outputDeviceChange'** is reported when the output device changes.|
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo)) => void | Yes  | Callback used for subscription. The **device** parameter in the callback indicates the output device information.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ----------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**Example**

```js
controller.on('outputDeviceChange', (device) => {
    console.info(`on outputDeviceChange device isRemote : ${device.isRemote}`);
});
```

### off('metadataChange')

off(type: 'metadataChange', callback?: (data: AVMetadata) => void)

Unsubscribes from metadata changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                              | Mandatory| Description                                                   |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------ |
| type     | string                                           | Yes  | Event type. The event **'metadataChange'** is reported when the session metadata changes.        |
| callback | (data: [AVMetadata](#avmetadata)) => void        | No  | Callback used for subscription. The **data** parameter in the callback indicates the changed metadata.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception |

**Example**

```js
controller.off('metadataChange');
```

### off('playbackStateChange')

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void)

Unsubscribes from playback state changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | Yes  | Event type. The event **'playbackStateChange'** is reported when the playback state changes.   |
| callback | (state: [AVPlaybackState](#avplaybackstate)) => void         | No  | Callback used for subscription. The **state** parameter in the callback indicates the changed playback state.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception |

**Example**

```js
controller.off('playbackStateChange');
```

### off('sessionDestroy')

off(type: 'sessionDestroy', callback?: () => void)

Unsubscribes from the session destruction event.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type      | Mandatory| Description                                                     |
| -------- | ---------- | ---- | ----------------------------------------------------- |
| type     | string     | Yes  | Event type. The event **'sessionDestroy'** is reported when the session is destroyed.        |
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception |

**Example**

```js
controller.off('sessionDestroy');
```

### off('activeStateChange')

off(type: 'activeStateChange', callback?: (isActive: boolean) => void)

Unsubscribes from session activation state changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                     |
| -------- | --------------------------- | ---- | ----------------------------------------------------- |
| type     | string                      | Yes  | Event type. The event **'activeStateChange'** is reported when the session activation state changes.     |
| callback | (isActive: boolean) => void | No  | Callback used for unsubscription. The **isActive** parameter in the callback specifies whether the session is activated. The value **true** means that the session is activated, and **false** means the opposite.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                  |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 6600101  | Session service exception |

**Example**

```js
controller.off('activeStateChange');
```

### off('validCommandChange')

off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void)

Unsubscribes from valid command changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | Yes  | Event type. The event **'validCommandChange'** is reported when the supported commands change.        |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype)\>) => void | No  | Callback used for unsubscription. The **commands** parameter in the command is a set of valid commands.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID| Error Message          |
| -------- | ---------------- |
| 6600101  | Session service exception |

**Example**

```js
controller.off('validCommandChange');
```

### off('outputDeviceChange')

off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void

Unsubscribes from output device changes.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                     |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The event **'outputDeviceChange'** is reported when the output device changes.     |
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo)) => void | No  | Callback used for unsubscription. The **device** parameter in the callback indicates the output device information.<br>The callback parameter is optional. If it is not specified, the specified event is no longer listened for all sessions.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](../errorcodes/errorcode-avsession.md).

| ID | Error Message         |
| -------- | ---------------- |
| 6600101  | Session service exception |

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

## AVSessionType
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
| type         | [AVSessionType](#avsessiontype)                              | Yes  | No | Session type.                                           |
| sessionTag   | string                                                       | Yes  | No | Custom session name.                                   |
| elementName  | [ElementName](js-apis-bundle-ElementName.md)                 | Yes  | No | Information about the application to which the session belongs, including the bundle name and ability name.|
| isActive     | boolean                                                      | Yes  | No | Whether the session is activated.                                     |
| isTopSession | boolean                                                      | Yes  | No | Whether the session is the top session.                               |
| outputDevice | [OutputDeviceInfo](#outputdeviceinfo)                        | Yes  | No | Information about the output device.                                 |

## AVControlCommandType

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

## AVControlCommand

Describes the command that can be sent to the session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name     | Type                                             | Mandatory| Description          |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVControlCommandType](#avcontrolcommandtype)     | Yes  | Command.          |
| parameter | [LoopMode](#loopmode) &#124; string &#124; number | No  | Parameters carried in the command.|

## AVMetadata

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
| duration        | string                  | No  | Media duration, in ms.                                                 |
| mediaImage      | image.PixelMap &#124; string | No  | Pixel map or image path (local path or network path) of the image.                            |
| publishDate     | Date                    | No  | Release date.                                                              |
| subtitle        | string                  | No  | Subtitle.                                                               |
| description     | string                  | No  | Media description.                                                              |
| lyric           | string                  | No  | Lyric file path (local path or network path).|
| previousAssetId | string                  | No  | ID of the previous media asset.                                                           |
| nextAssetId     | string                  | No  | ID of the next media asset.                                                           |

## AVPlaybackState

Describes the information related to the media playback state.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name        | Type                                 | Mandatory| Description    |
| ------------ | ------------------------------------- | ---- | ------- |
| state        | [PlaybackState](#playbackstate)       | No  | Playback state.|
| speed        | number                                | No  | Playback speed.|
| position     | [PlaybackPosition](#playbackposition) | No  | Playback position.|
| bufferedTime | number                                | No  | Buffered time.|
| loopMode     | [LoopMode](#loopmode)                 | No  | Loop mode.|
| isFavorite   | boolean                               | No  | Whether the media asset is favorited.|

## PlaybackPosition

Describes the information related to the playback position.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name       | Type  | Mandatory| Description              |
| ----------- | ------ | ---- | ------------------ |
| elapsedTime | number | Yes  | Elapsed time, in ms.|
| updateTime  | number | Yes  | Updated time, in ms.|

## OutputDeviceInfo

Describes the information related to the output device.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name      | Type          | Mandatory| Description                  |
| ---------- | -------------- | ---- | ---------------------- |
| isRemote   | boolean        | Yes  | Whether the device is connected.        |
| audioDeviceId   | Array<number\> | Yes  | IDs of output devices. |
| deviceName | Array<string\> | Yes  | Names of output devices.   |

## PlaybackState

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


## LoopMode

Enumerates the loop modes of media playback.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name              | Value  | Description    |
| ------------------ | ---- | -------- |
| LOOP_MODE_SEQUENCE | 0    | Sequential playback.|
| LOOP_MODE_SINGLE   | 1    | Single loop.|
| LOOP_MODE_LIST     | 2    | Playlist loop.|
| LOOP_MODE_SHUFFLE  | 3    | Shuffle.|

## AVSessionErrorCode

Enumerates the error codes used in the media session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                          | Value     | Description                            |
| ------------------------------ | ------- | ------------------------------- |
| ERR_CODE_SERVICE_EXCEPTION     | 6600101 | Session service exception                |
| ERR_CODE_SESSION_NOT_EXIST     | 6600102 | The session does not exist      |
| ERR_CODE_CONTROLLER_NOT_EXIST  | 6600103 | The session controller does not exist   |
| ERR_CODE_REMOTE_CONNECTION_ERR | 6600104 | The remote session  connection failed         |
| ERR_CODE_COMMAND_INVALID       | 6600105 | Invalid session command           |
| ERR_CODE_SESSION_INACTIVE      | 6600106 | The session not active                |
| ERR_CODE_MESSAGE_OVERLOAD      | 6600107 | Command or event overload       |
