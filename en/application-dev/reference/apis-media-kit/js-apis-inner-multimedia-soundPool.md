# SoundPool (Sound Pool)

The SoundPool module provides APIs for loading, unloading, playing, and stopping playing sounds, setting the volume, and setting the number of loops.

Before using these APIs, you must call [media.createSoundPool](js-apis-media.md#mediacreatesoundpool10) to create a **SoundPool** instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { media } from '@kit.MediaKit';
import { audio } from '@kit.AudioKit';
```

## PlayParameters

Describes the playback parameters of the sound pool.

These parameters are used to control the playback volume, number of loops, and priority.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

| Name           | Type                                    | Mandatory| Description                                                        |
| --------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| loop | number   | No | Number of loops. The value **0** means that the sound does not loop (the sound is played once), and **-1** means that the sound loops forever. Default value: **0**                  |
| rate | number    | No | Playback rate. For details, see [AudioRendererRate](../apis-audio-kit/js-apis-audio.md#audiorendererrate8). Default value: **0**|
| leftVolume  | number | No | Volume of the left channel. The value ranges from 0.0 to 1.0. Default value: **1.0**                                   |
| rightVolume | number  | No | Volume of the right channel. (Currently, the volume cannot be set separately for the left and right channels. The volume set for the left channel is used.) Default value: **1.0**|
| priority  | number  | No | Playback priority. The value **0** means the lowest priority. A larger value indicates a higher priority. Default value: **0**     |

## SoundPool

Implements a sound pool that provides APIs for loading, unloading, playing, and stopping playing system sounds, setting the volume, and setting the number of loops. Before using these APIs, you must call [createSoundPool](js-apis-media.md#mediacreatesoundpool10) to create a **SoundPool** instance.

> **NOTE**
>
> When using the **SoundPool** instance, you are advised to register the following callbacks to proactively obtain status changes:
> - [on('loadComplete')](#onloadcomplete): listens for the event indicating that the resource loading is finished.
> - [on('playFinished')](#onplayfinished): listens for the event indicating that the playback is finished.
> - [on('error')](#onerror): listens for error events.

### load

load(uri: string, callback: AsyncCallback\<number>): void

Loads a sound. This API uses an asynchronous callback to obtain the sound ID. The input parameter **uri** is a string starting with fd://, which is generated based on the file descriptor (FD) obtained.
This API cannot be used to load resources in the **rawfile** directory. Instead, use [load(fd: number, offset: number, length: number, callback: AsyncCallback\<number>): void](#load-2) or [load(fd: number, offset: number, length: number): Promise\<number>](#load-3).

>**NOTE**
>
>After the resource handle (in the form of an FD) or path description (in the form of a URI) is transferred to the AVPlayer, do not use the resource handle or path description in read or write operations, including but not limited to transferring it to multiple AVPlayers.
>Competition occurs when multiple AVPlayers use the same resource handle or path description to read and write files at the same time, resulting in playback errors.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                                  | Mandatory| Description                                 |
| -------- | -------------------------------------- | ---- | ------------------------------------- |
| uri   | string | Yes  | URI of the audio file to load. Generally, the URI starts with fd://.|
| callback | AsyncCallback\<number>                   | Yes  | Callback used to return the sound ID. A valid value must be greater than 0.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback.|
| 5400103  | I/O error. Return by callback. |
| 5400105  | Service died. Return by callback. |

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let uri:string = "";
    let file: fileIo.File;
    // Obtain the URI starting with fd://.
    fileIo.open('/test_01.mp3', fileIo.OpenMode.READ_ONLY).then((file_: fileIo.File) => {
      file = file_;
      console.info("file fd: " + file.fd);
      uri = 'fd://' + (file.fd).toString()
      soundPool.load(uri, (error: BusinessError, soundId_: number) => {
        if (error) {
          console.error(`Failed to load soundPool: errCode is ${error.code}, errMessage is ${error.message}`)
        } else {
          console.info(`Succeeded in loading soundPool` + JSON.stringify(soundId_))
        }
      });
    }); // '/test_01.mp3' here is only an example. You need to pass in the actual URI.
  }
});
```

### load

load(uri: string): Promise\<number>

Loads a sound. This API uses a promise to obtain the sound ID. The input parameter **uri** is a starting with fd://, which is generated based on the FD obtained.
This API cannot be used to load resources in the **rawfile** directory. Instead, use [load(fd: number, offset: number, length: number, callback: AsyncCallback\<number>): void](#load-2) or [load(fd: number, offset: number, length: number): Promise\<number>](#load-3).

>**NOTE**
>
>After the resource handle (in the form of an FD) or path description (in the form of a URI) is transferred to the AVPlayer, do not use the resource handle or path description in read or write operations, including but not limited to transferring it to multiple AVPlayers.
>Competition occurs when multiple AVPlayers use the same resource handle or path description to read and write files at the same time, resulting in playback errors.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name| Type                                  | Mandatory| Description                      |
| ------ | -------------------------------------- | ---- | -------------------------- |
| uri | string | Yes  | URI of the audio file to load. Generally, the URI starts with fd://.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<number> | Promise used to return the sound ID. A valid value must be greater than 0.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise.|
| 5400103  | I/O error. Return by promise. |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let uri:string = "";
    let soundID: number = 0;
    let file: fileIo.File;
    // Obtain the URI starting with fd://.
    fileIo.open('/test_01.mp3', fileIo.OpenMode.READ_ONLY).then((file_: fileIo.File) => {
      file = file_;
      console.info("file fd: " + file.fd);
      uri = 'fd://' + (file.fd).toString()
      soundPool.load(uri).then((soundId: number) => {
        console.info('Succeeded in loading uri');
        soundID = soundId;
      }, (err: BusinessError) => {
        console.error('Failed to load soundPool and catch error is ' + err.message);
      });
    }); // '/test_01.mp3' here is only an example. You need to pass in the actual URI.
  }
});

```

### load

load(fd: number, offset: number, length: number, callback: AsyncCallback\<number>): void

Loads a sound. This API uses an asynchronous callback to obtain the sound ID. The input parameter **fd** can be manually input or automatically obtained by reading the embedded resource of the application.

>**NOTE**
>
>After the resource handle (in the form of an FD) or path description (in the form of a URI) is transferred to the AVPlayer, do not use the resource handle or path description in read or write operations, including but not limited to transferring it to multiple AVPlayers.
>Competition occurs when multiple AVPlayers use the same resource handle or path description to read and write files at the same time, resulting in playback errors.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| fd     | number | Yes  | Resource handle, which is obtained by calling [resourceManager.getRawFd](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9).    |
| offset | number | Yes  | Resource offset, which needs to be entered based on the preset resource information. An invalid value causes a failure to parse audio and video resources.|
| length | number | Yes  | Resource length, which needs to be entered based on the preset resource information. An invalid value causes a failure to parse audio and video resources.|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the sound ID. A valid value must be greater than 0.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example 1:**

```ts
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let file: fileIo.File;
    let soundID: number = 0;
    let fileSize: number = 1; // Obtain the size through fileIo.stat().
    let uri: string = "";
    // Obtain the FD. The test_01.mp3 file is not an audio file in the rawfile directory.
    fileIo.open('/test_01.mp3', fileIo.OpenMode.READ_ONLY).then((file_: fileIo.File) => {
      file = file_;
      console.info("file fd: " + file.fd);
      uri = 'fd://' + (file.fd).toString()
      soundPool.load(file.fd, 0, fileSize, (error: BusinessError, soundId_: number) => {
        if (error) {
          console.error(`Failed to load soundPool: errCode is ${error.code}, errMessage is ${error.message}`)
        } else {
          soundID = soundId_;
          console.info('Succeeded in loading soundId:' + soundId_);
        }
      });
    }); // '/test_01.mp3' here is only an example. You need to pass in the actual URI.
  }
});

```

**Example 2**

```ts
import { media } from '@kit.MediaKit';
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
let soundID: number = 0;
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    // The test_01.mp3 file is an audio file in the rawfile directory.
    let fileDescriptor = getContext().resourceManager.getRawFd('test_01.mp3');
    soundPool.load(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length, (error: BusinessError, soundId_: number) => {
      if (error) {
        console.error(`Failed to load soundPool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        soundID = soundId_;
        console.info('Succeeded in loading soundId:' + soundId_);
      }
    });
  }
});

```

### load

load(fd: number, offset: number, length: number): Promise\<number>

Loads a sound. This API uses a promise to obtain the sound ID. The input parameter **fd** can be manually input or automatically obtained by reading the embedded resource of the application.

>**NOTE**
>
>After the resource handle (in the form of an FD) or path description (in the form of a URI) is transferred to the AVPlayer, do not use the resource handle or path description in read or write operations, including but not limited to transferring it to multiple AVPlayers.
>Competition occurs when multiple AVPlayers use the same resource handle or path description to read and write files at the same time, resulting in playback errors.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| fd     | number | Yes  | Resource handle, which is obtained by calling [resourceManager.getRawFd](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9).    |
| offset | number | Yes  | Resource offset, which needs to be entered based on the preset resource information. An invalid value causes a failure to parse audio and video resources.|
| length | number | Yes  | Resource length, which needs to be entered based on the preset resource information. An invalid value causes a failure to parse audio and video resources.|

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<number> | Promise used to return the sound ID. A valid value must be greater than 0.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise.|
| 5400103  | I/O error. Return by promise. |
| 5400105  | Service died. Return by promise. |

**Example 1:**

```ts
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let file: fileIo.File;
    let soundID: number = 0;
    let fileSize: number = 1; // Obtain the size through fileIo.stat().
    let uri: string = "";
    // Obtain the FD. The test_01.mp3 file is not an audio file in the rawfile directory.
    fileIo.open('/test_01.mp3', fileIo.OpenMode.READ_ONLY).then((file_: fileIo.File) => {
      file = file_;
      console.info("file fd: " + file.fd);
      uri = 'fd://' + (file.fd).toString()
      soundPool.load(file.fd, 0, fileSize).then((soundId: number) => {
        console.info('Succeeded in loading soundpool');
        soundID = soundId;
      }, (err: BusinessError) => {
        console.error('Failed to load soundpool and catch error is ' + err.message);
      });
    });
  }
});

```

**Example 2**

```ts
import { media } from '@kit.MediaKit';
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
let soundID: number = 0;
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    // The test_01.mp3 file is an audio file in the rawfile directory.
    let fileDescriptor = getContext().resourceManager.getRawFd('test_01.mp3');
    soundPool.load(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length).then((soundId: number) => {
      console.info('Succeeded in loading soundpool');
      soundID = soundId;
    }, (err: BusinessError) => {
      console.error('Failed to load soundpool and catch error is ' + err.message);
    });
  }
});

```

### play

play(soundID: number, params: PlayParameters, callback: AsyncCallback\<number>): void

Plays a sound. This API uses an asynchronous callback to obtain the audio stream ID.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | Yes  | Sound ID, which is obtained by calling **load()**.|
| params | [PlayParameters](#playparameters) | Yes | Playback parameters.|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the audio stream ID. A valid value must be greater than 0.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by callback. |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let soundID: number = 0;
    let streamID: number = 0;
    let playParameters: media.PlayParameters = {
      loop: 3, // The sound loops three times.
      rate: audio.AudioRendererRate.RENDER_RATE_NORMAL, // The sound is played at the original frequency.
      leftVolume: 0.5, // range = 0.0-1.0
      rightVolume: 0.5, // range = 0.0-1.0
      priority: 0, // The sound playback has the lowest priority.
    }
    soundPool.play(soundID, playParameters, (error: BusinessError, streamId: number) => {
      if (error) {
        console.error(`Failed to play soundpool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        streamID = streamId;
        console.info('Succeeded in playing soundpool, streamId:' + streamId);
      }
    });
  }
});

```

### play

play(soundID: number, callback: AsyncCallback\<number>): void

Plays a sound. This API uses an asynchronous callback to obtain the audio stream ID.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | Yes  | Sound ID, which is obtained by calling **load()**.|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the audio stream ID. A valid value must be greater than 0.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by callback. |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let soundID: number = 0;
    let streamID: number = 0;
    soundPool.play(soundID,  (error: BusinessError, streamId: number) => {
      if (error) {
        console.error(`Failed to play soundpool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        streamID = streamId;
        console.info('Succeeded in playing soundpool, streamId:' + streamId);
      }
    });
  }
});

```

### play

play(soundID: number, params?: PlayParameters): Promise\<number>

Plays a sound. This API uses a promise to obtain the audio stream ID.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | Yes  | Sound ID, which is obtained by calling **load()**.|
| params | [PlayParameters](#playparameters) | No | Playback parameters.|

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<number> | Promise used to return the audio stream ID. A valid value must be greater than 0.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let soundID: number = 0;
    let streamID: number = 0;
    let playParameters: media.PlayParameters = {
      loop: 3, // The sound is played four times (three loops).
      rate: audio.AudioRendererRate.RENDER_RATE_NORMAL, // The sound is played at the original frequency.
      leftVolume: 0.5, // range = 0.0-1.0
      rightVolume: 0.5, // range = 0.0-1.0
      priority: 0, // The sound playback has the lowest priority.
    }

    soundPool.play(soundID, playParameters).then((streamId: number) => {
      console.info('Succeeded in playing soundpool');
      streamID = streamId;
    },(err: BusinessError) => {
      console.error('Failed to play soundpool and catch error is ' + err.message);
    });
  }
});

```

### stop

stop(streamID: number, callback: AsyncCallback\<void>): void

Stops playing a sound. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by callback. |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    // Call play() to obtain the stream ID.
    soundPool.stop(streamID, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to stop soundpool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        console.info('Succeeded in stopping soundpool');
      }
    })
  }
});

```

### stop

stop(streamID: number): Promise\<void>

Stops playing a sound. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    // Call play() to obtain the stream ID.
    soundPool.stop(streamID).then(() => {
      console.info('Succeeded in stopping soundpool');
    }, (err: BusinessError) => {
      console.error('Failed to stop soundpool and catch error is ' + err.message);
    });
  }
});
```

### setLoop

setLoop(streamID: number, loop: number, callback: AsyncCallback\<void>): void;

Sets the loop mode for an audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|
| loop | number | Yes  | Number of loops. The value **0** means that the sound does not loop (the sound is played once), and **-1** means that the sound loops forever.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by callback. |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    // Call play() to obtain the stream ID.
    // Set the number of loops to 2.
    soundPool.setLoop(streamID, 2, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to setLoop soundPool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        console.info('Succeeded in setLoopping soundpool, streamID:' + streamID);
      }
    });
  }
});

```

### setLoop

setLoop(streamID: number, loop: number): Promise\<void>

Sets the loop mode for an audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|
| loop | number | Yes  | Number of loops. The value **0** means that the sound does not loop (the sound is played once), and **-1** means that the sound loops forever.|

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    // Call play() to obtain the stream ID.
    // Set the number of loops to 1.
    soundPool.setLoop(streamID, 1).then(() => {
      console.info('Succeeded in setLoopping soundpool, streamID:' + streamID);
    }).catch((err: BusinessError) => {
      console.error('Failed to setLoop soundPool and catch error is ' + err.message);
    });
  }
});

```

### setPriority

setPriority(streamID: number, priority: number, callback: AsyncCallback\<void>): void

Sets the priority for an audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|
| priority | number | Yes  | Priority. The value **0** means the lowest priority.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by callback. |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    // Call play() to obtain the stream ID.
    // Set the priority to 1.
    soundPool.setPriority(streamID, 1, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to setPriority soundPool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        console.info('Succeeded in setPriority soundpool, streamID:' + streamID);
      }
    });
  }
});

```

### setPriority

setPriority(streamID: number, priority: number): Promise\<void>

Sets the priority for an audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|
| priority | number | Yes  | Priority. The value **0** means the lowest priority.|

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    // Call play() to obtain the stream ID.
    // Set the priority to 1.

    soundPool.setPriority(streamID, 1).then(() => {
      console.info('Succeeded in setPriority soundpool');
    }, (err: BusinessError) => {
      console.error('Failed to setPriority soundPool and catch error is ' + err.message);
    });
  }
});

```

### setRate

setRate(streamID: number, rate: audio.AudioRendererRate, callback: AsyncCallback\<void>): void

Sets the playback rate for an audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|
| rate | [audio.AudioRendererRate](../apis-audio-kit/js-apis-audio.md#audiorendererrate8) | Yes  | Playback rate.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by callback. |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    let selectedAudioRendererRate: audio.AudioRendererRate = audio.AudioRendererRate.RENDER_RATE_NORMAL; // The sound is played at the original frequency.
    // Call play() to obtain the stream ID.
    soundPool.setRate(streamID, selectedAudioRendererRate, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to setRate soundPool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        console.info('Succeeded in setRate success, streamID:' + streamID);
      }
    })
  }
});

```

### setRate

setRate(streamID: number, rate: audio.AudioRendererRate): Promise\<void>

Sets the playback rate for an audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|
| rate | [audio.AudioRendererRate](../apis-audio-kit/js-apis-audio.md#audiorendererrate8) | Yes  | Playback rate.|

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    let selectedAudioRendererRate: audio.AudioRendererRate = audio.AudioRendererRate.RENDER_RATE_NORMAL; // The sound is played at the original frequency.
    // Call play() to obtain the stream ID.
    soundPool.setRate(streamID, selectedAudioRendererRate).then(() => {
      console.info('Succeeded in setRate soundpool');
    }, (err: BusinessError) => {
      console.error('Failed to setRate soundpool and catch error is ' + err.message);
    });
  }
});

```

### setVolume

setVolume(streamID: number, leftVolume: number, rightVolume: number, callback: AsyncCallback\<void>): void

Sets the volume for an audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|
| leftVolume | number | Yes  | Volume of the left channel. The value ranges from 0.0 to 1.0.|
| rightVolume | number | Yes  | Volume of the right channel. Currently, setting the volume for the right channel does not take effect. The volume set for the left channel is used.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by callback. |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    // Call play() to obtain the stream ID.
    // Set the volume to 0.5.
    soundPool.setVolume(streamID, 0.5, 0.5, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to setVolume soundPool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        console.info('Succeeded in setVolume soundpool, streamID:' + streamID);
      }
    })
  }
});

```

### setVolume

setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise\<void>

Sets the volume for an audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | Yes  | Audio stream ID, which is obtained by calling **play()**.|
| leftVolume | number | Yes  | Volume of the left channel. The value ranges from 0.0 to 1.0.|
| rightVolume | number | Yes  | Volume of the right channel. Currently, setting the volume for the right channel does not take effect. The volume set for the left channel is used.|

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.  Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let streamID: number = 0;
    // Call play() to obtain the stream ID.

    soundPool.setVolume(streamID, 0.5, 0.5).then(() => {
      console.info('Succeeded in setVolume soundpool');
    }, (err: BusinessError) => {
      console.error('Failed to setVolume soundPool and catch error is ' + err.message);
    });
  }
});

```

### unload

unload(soundID: number, callback: AsyncCallback\<void>): void

Unloads a sound. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | Yes  | Sound ID, which is obtained by calling **load()**.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let soundID: number = 0;
    // Call load() to obtain the sound ID.
    soundPool.unload(soundID, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to unload soundPool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        console.info('Succceeded in unload soundPool');
      }
    })
  }
});

```

### unload

unload(soundID: number): Promise\<void>

Unloads a sound. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | Yes  | Sound ID, which is obtained by calling **load()**.|

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    let soundID: number = 0;
    // Call load() to obtain the sound ID.

    soundPool.unload(soundID).then(() => {
      console.info('Succceeded in unload soundPool');
    }, (err: BusinessError) => {
      console.error('Failed to unload soundPool and catch error is ' + err.message);
    });
  }
});

```

### release

release(callback: AsyncCallback\<void>): void

Releases this **SoundPool** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    soundPool.release((error: BusinessError) => {
      if (error) {
        console.error(`Failed to release soundPool: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        console.info('Succeeded in releasing soundPool');
      }
    })
  }
});


```

### release

release(): Promise\<void>

Releases this **SoundPool** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    soundPool.release().then(() => {
      console.info('Succeeded in releasing soundPool');
    }, (err: BusinessError) => {
      console.error('Failed to release soundPool and catch error is ' + err.message);
    });
  }
});

```

### on('loadComplete')

on(type: 'loadComplete', callback: Callback\<number>): void

Subscribes to events indicating that a sound finishes loading.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'loadComplete'** in this case. This event is triggered when a sound is loaded.|
| callback | Callback\<number> | Yes  | ID of the sound that has been loaded.                              |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    soundPool.on('loadComplete', (soundId: number) => {
      console.info('Succeeded in loadComplete, soundId: ' + soundId)
    })
  }
});

```

### off('loadComplete')

off(type: 'loadComplete'): void

Unsubscribes from events indicating that a sound finishes loading.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type. The value is fixed at **'loadComplete'**.|

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    soundPool.off('loadComplete')
  }
});

```

### on('playFinished')

on(type: 'playFinished', callback: Callback\<void>): void

Subscribes to events indicating that a sound finishes playing.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'playFinished'** in this case. This event is triggered when a sound finishes playing.|
| callback | Callback\<void> | Yes  |  Callback used to return the result.       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    soundPool.on('playFinished', () => {
      console.info('Succeeded in playFinished')
    });
  }
});

```

### off('playFinished')

off(type: 'playFinished'): void

Unsubscribes from events indicating that a sound finishes playing.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type. The value is fixed at **'playFinished'**.|

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    soundPool.off('playFinished')
  }
});

```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to error events of this **SoundPool** instance. This event is used only for error prompt.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'error'** in this case. This event can be triggered by both user operations and the system.|
| callback | ErrorCallback | Yes  | Callback used to return the error code ID and error message.|

The **SoundPool** class provides the following error types<a name = error_info></a>:

| ID| Error Message             | Description                                                        |
| -------- | --------------------- | ------------------------------------------------------------ |
| 401      | Invalid Parameter.    | Incorrect input parameter, causing an invalid call.                                    |
| 801      | Unsupport Capability. | Unsupported API, causing an invalid call.                             |
| 5400101  | No Memory.            | Insufficient memory.|
| 5400102  | Operation Not Allowed.   | Unsupported operation in the current state, causing an invalid call.                      |
| 5400103  | IO Error.             | I/O exception.|
| 5400105  | Service Died.         | The playback process is dead, and the service on which the sound pool depends is abnormal.|

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    soundPool.on('error', (error: BusinessError) => {
      console.error('error happened,and error message is :' + error.message)
      console.error('error happened,and error code is :' + error.code)
    })
  }
});

```

### off('error')

off(type: 'error'): void

Unsubscribes from error events of this **SoundPool** instance.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | Yes  | Event type, which is **'error'** in this case.|

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// Create a SoundPool instance.
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`)
    soundPool.off('error')
  }
});
```
