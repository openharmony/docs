# Using SoundPool for Audio Playback

The **SoundPool** class provides APIs to implement low-latency playback of short sounds.

Short sound effects (such as the camera shutter sound effect and system notification sound effect) are often required during application development. You can call the APIs provided by **SoundPool** to implement one-time loading of short sounds and multiple times of low-latency playback.

Currently, the **SoundPool** APIs can be used to play an audio file that is less than 1 MB. If the size of an audio file exceeds 1 MB, 1 MB data is captured and played.

This topic walks you through on how to use the **SoundPool** APIs to implement low-latency playback. For details about the API, see [SoundPool](../../reference/apis-media-kit/js-apis-inner-multimedia-soundPool.md).

The full process includes creating a **SoundPool** instance, loading a sound (including decapsulation and decoding), setting playback parameters (loop mode, and playback priority), playing the sound, stopping the playback, and releasing the instance. (For details about the decoding formats, see [Audio Decoding](../avcodec/audio-decoding.md).)

During application development, you must subscribe to playback state changes and call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur.  

## How to Develop

1. Call **createSoundPool()** to create a **SoundPool** instance.

    ```ts
    import { media } from '@kit.MediaKit';
    import { audio } from '@kit.AudioKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let soundPool: media.SoundPool;
    let audioRendererInfo: audio.AudioRendererInfo = {
      usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
      rendererFlags : 0
    }

    media.createSoundPool(5, audioRendererInfo).then((soundpool_: media.SoundPool) => {
      if (soundpool_ != null) {
        soundPool = soundpool_;
        console.info('create SoundPool success');
      } else {
        console.error('create SoundPool fail');
      }
    }).catch((error: BusinessError) => {
      console.error(`soundpool catchCallback, error message:${error.message}`);
    });
    ```

2. Call **on('loadComplete')** to listen for the completion of sound loading.

    ```ts
    soundPool.on('loadComplete', (soundId: number) => {
      console.info('loadComplete, soundId: ' + soundId);
    });
    ```

3. Call **on('playFinished')** to listen for the completion of sound playing.
     
    ```ts
    soundPool.on('playFinished', () => {
      console.info("receive play finished message");
    });
    ```

4. Call **on('error')** to listen for errors that may occur.
     
    ```ts
    soundPool.on('error', (error: BusinessError) => {
      console.info('error happened,message is :' + error.message);
    });
    ```

5. Call **load()** to load a sound.
    You can pass in a URI or an FD to load the sound. The following uses the URI as an example. For more methods, see [SoundPool](../../reference/apis-media-kit/js-apis-inner-multimedia-soundPool.md#load).

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { fileIo as fs } from '@kit.CoreFileKit';
   
    let soundID: number;
    let uri: string;
    async function load() {
      await fs.open('/test_01.mp3', fs.OpenMode.READ_ONLY).then((file: fs.File) => {
        console.info("file fd: " + file.fd);
        uri = 'fd://' + (file.fd).toString()
      }); // '/test_01.mp3' here is only an example. You need to pass in the actual URI.
      soundPool.load(uri).then((soundId: number) => {
        console.info('soundPool load uri success');
        soundID = soundId;
      }).catch((err: BusinessError) => {
        console.error('soundPool load failed and catch error is ' + err.message);
      })
    }
    ```

6. Set the playback parameters and call **play()** to play the sound. If **play()** with the same sound ID passed in is called for multiple times, the sound is played only once.
  
    ```ts
    let soundID: number;
    let streamID: number;
    let playParameters: media.PlayParameters = {
        loop: 0, // The sound does not loop. It is played once.
        rate: 2, // The sound is played at twice its original frequency.
        leftVolume: 0.5, // range = 0.0-1.0
        rightVolume: 0.5, // range = 0.0-1.0
        priority: 0, // The sound playback has the lowest priority.
      }
    soundPool.play(soundID, playParameters, (error: BusinessError, streamId: number) => {
      if (error) {
        console.info(`play sound Error: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        streamID = streamId;
        console.info('play success soundid:' + streamId);
      }
    });
    ```

7. Call **setLoop()** to set the number of loops.
     
    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
   
    let streamID: number;
    soundPool.setLoop(streamID, 1).then(() => {
      console.info('setLoop success streamID:' + streamID);
    }).catch((err: BusinessError) => {
      console.error('soundpool setLoop failed and catch error is ' + err.message);
    });
    ```

8. Call **setPriority()** to set the playback priority.
     
    ```ts
    let streamID: number;
    soundPool.setPriority(streamID, 1);
    ```

9. Call **setVolume()** to set the playback volume.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
   
    let streamID: number;
    // Call play() to obtain the stream ID.

    soundPool.setVolume(streamID, 0.5, 0.5).then(() => {
      console.info('setVolume success');
    }).catch((err: BusinessError) => {
      console.error('soundpool setVolume failed and catch error is ' + err.message);
    });
    ```

10. Call **stop()** to stop the playback.
     
    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    
    let streamID: number;
    // Call play() to obtain the stream ID.

    soundPool.stop(streamID).then(() => {
      console.info('stop success');
    }).catch((err: BusinessError) => {
      console.error('soundpool load stop and catch error is ' + err.message);
    });
    ```

11. Call **unload()** to unload a sound.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    
    let soundID: number;
    // Call load() to obtain the sound ID.

    soundPool.unload(soundID).then(() => {
      console.info('unload success');
    }).catch((err: BusinessError) => {
      console.error('soundpool unload failed and catch error is ' + err.message);
    });
    ```

12. Call **off('loadComplete')** to stop listening for the completion of sound loading.

    ```ts
    soundPool.off('loadComplete');
    ```

13. Call **off('playFinished')** to stop listening for the completion of sound playing.

    ```ts
    soundPool.off('playFinished');
    ```

14. Call **off('error')** to stop listening for errors.

    ```ts
    soundPool.off('error');
    ```

15. Call **release()** to release the **SoundPool** instance.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    
    soundPool.release().then(() => {
      console.info('release success');
    }).catch((err: BusinessError) => {
      console.error('soundpool release failed and catch error is ' + err.message);
    });
    ```

## Sample Code

The following sample code implements low-latency playback using **SoundPool**.

```ts
import { audio } from '@kit.AudioKit';
import { media } from '@kit.MediaKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let soundPool: media.SoundPool;
let streamId: number = 0;
let soundId: number = 0;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags: 1
}
let playParameters: media.PlayParameters = {
  loop: 3, // The sound is played four times (three loops).
  rate: audio.AudioRendererRate.RENDER_RATE_NORMAL, // The sound is played at the original frequency.
  leftVolume: 0.5, // range = 0.0-1.0
  rightVolume: 0.5, // range = 0.0-1.0
  priority: 0, // The sound playback has the lowest priority.
}
let uri: string = "";
async function create() {
  // Create a SoundPool instance.
  soundPool = await media.createSoundPool(5, audioRendererInfo);
  // Register listeners.
  loadCallback();
  finishPlayCallback();
  setErrorCallback();
  // Load a sound.
  await fs.open('/test_01.mp3', fs.OpenMode.READ_ONLY).then((file: fs.File) => {
    console.info("file fd: " + file.fd);
    uri = 'fd://' + (file.fd).toString()
  }); // '/test_01.mp3' here is only an example. You need to pass in the actual URI.
  soundId = await soundPool.load(uri);
}
function loadCallback() {
  // Callback invoked when the sound finishes loading.
  soundPool.on('loadComplete', (soundId_: number) => {
    console.info('loadComplete, soundId: ' + soundId_);
  })
}
// Set the listener when the sound finishes playing.
function finishPlayCallback() {
  // Callback invoked when the sound finishes playing.
  soundPool.on('playFinished', () => {
    console.info("recive play finished message");
    // The sound can be played again.
  })
}
// Set the listener for errors.
function setErrorCallback() {
  soundPool.on('error', (error: BusinessError) => {
    console.info('error happened,message is :' + error.message);
  })
}
async function PlaySoundPool() {
  // Start playback. PlayParameters can be carried in the play() API.
  soundPool.play(soundId, playParameters, (error, streamID: number) => {
    if (error) {
      console.info(`play sound Error: errCode is ${error.code}, errMessage is ${error.message}`)
    } else {
      streamId = streamID;
      console.info('play success soundid:' + streamId);
    }
  });
  // Set the number of loops.
  await soundPool.setLoop(streamId, 2); // The sound is played three times (two loops).
  // Set the priority.
  await soundPool.setPriority(streamId, 1);
  // Set the volume.
  await soundPool.setVolume(streamId, 0.5, 0.5);
}
async function release() {
  // Stop the playback of the stream.
  await soundPool.stop(streamId);
  // Unload the sound.
  await soundPool.unload(soundId);
  // Unregister the listeners.
  setOffCallback();
  // Release the SoundPool instance.
  await soundPool.release();
}
// Unregister the listeners.
function setOffCallback() {
  soundPool.off('loadComplete');
  soundPool.off('playFinished');
  soundPool.off('error');
}
```
