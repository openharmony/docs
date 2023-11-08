# Using SoundPool for Audio Playback

The **SoundPool** class provides APIs to implement low-latency playback of short sounds.

Short sound effects (such as the camera shutter sound effect and system notification sound effect) are often required during application development. You can call the APIs provided by **SoundPool** to implement one-time loading of short sounds and multiple times of low-latency playback.

Currently, the **SoundPool** APIs can be used to play an audio file that is less than 1 MB. If the size of an audio file exceeds 1 MB, 1 MB data is captured and played.

This topic walks you through on how to use the **SoundPool** APIs to implement low-latency playback. For details about the API, see [SoundPool](../reference/apis/js-apis-inner-multimedia-soundPool.md).

The full process includes creating a **SoundPool** instance, loading a sound (including decapsulation and decoding), setting playback parameters (playback rate, loop mode, and priority), playing the sound, stopping the playback, and releasing the instance. (For details about the decoding formats, see [Audio Decoding](audio-decoding.md).)

During application development, you must subscribe to playback state changes and call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur.  

## How to Develop

1. Call **createSoundPool()** to create a **SoundPool** instance.

    ```ts
    let soundPool: media.SoundPool;
    let audioRendererInfo: audio.AudioRendererInfo = {
        content : audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION
        usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
        rendererFlags : 1
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

2. Call **load()** to load a sound.

    You can pass in a URI or an FD to load the sound. The following uses the URI as an example. For more methods, see [SoundPool](../reference/apis/js-apis-inner-multimedia-soundPool.md#load).

    ```ts
    let soundID: number;
    await fs.open('/test_01.mp3', fs.OpenMode.READ_ONLY).then((file: fs.File) => {
      console.info("file fd: " + file.fd);
      uri = 'fd://' + (file.fd).toString()
    }); // '/test_01.mp3' here is only an example. You need to pass in the actual URI.
    soundPool.load(uri).then((soundId: number) => {
      console.info('soundPool load uri success');
      soundID = soundId;
    }).catch((err) => {
      console.error('soundPool load failed and catch error is ' + err.message);
    });
    ```

3. Call **on('loadComplete')** to listen for the completion of sound loading.

    ```ts
    soundPool.on('loadComplete', (soundId_: number) => {
      console.info('loadComplete, soundId: ' + soundId_);
    });
    ```

4. Call **on('playFinished')** to listen for the completion of sound playing.
     
    ```ts
    soundPool.on('playFinished', () => {
      console.info("recive play finished message");
    });
    ```

5. Call **on('error')** to listen for errors that may occur.
     
    ```ts
    soundPool.on('error', (error) => {
      console.info('error happened,message is :' + error.message);
    });
    ```

6. Set the playback parameters and call **play()** to play the sound. If **play()** with the same sound ID passed in is called for multiple times, the sound is played only once.
  
    ```ts
    let soundID: number;
    let streamID: number;
    let playParameters: media.PlayParameters = {
        loop = 0, // The sound does not loop. It is played once.
        rate = 2, // The sound is played at twice its original frequency.
        leftVolume = 0.5, // range = 0.0-1.0
        rightVolume = 0.5, // range = 0.0-1.0
        priority = 0, // The sound playback has the lowest priority.
        parallelPlayFlag: boolean = false // The sound is not played in parallel with other active audio streams.
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

9. Call **setRate()** to set the playback rate.

    ```ts
    let streamID: number;
    let selectedAudioRendererRate: audio.AudioRendererRate = audio.AudioRendererRate.RENDER_RATE_NORMAL; // The sound is played at the original frequency.
    // Call play() to obtain the stream ID.

    soundPool.setRate(streamID, selectedAudioRendererRate).then(() => {
      console.info('setRate success');
    }).catch((err: BusinessError) => {
      console.error('soundpool setRate failed and catch error is ' + err.message);
    });
    ```

10. Call **setVolume()** to set the playback volume.

    ```ts
    let streamID: number;
    // Call play() to obtain the stream ID.

    soundPool.setVolume(streamID, 0.5, 0.5).then(() => {
      console.info('setVolume success');
    }).catch((err: BusinessError) => {
      console.error('soundpool setVolume failed and catch error is ' + err.message);
    });
    ```

11. Call **stop()** to stop the playback.
     
    ```ts
    let streamID: number;
    // Call play() to obtain the stream ID.

    soundPool.stop(streamID).then(() => {
      console.info('stop success');
    }).catch((err: BusinessError) => {
      console.error('soundpool load stop and catch error is ' + err.message);
    });
    ```

12. Call **unload()** to unload a sound.

    ```ts
    let soundID: number;
    // Call load() to obtain the sound ID.

    soundPool.unload(soundID).then(() => {
      console.info('unload success');
    }).catch((err: BusinessError) => {
      console.error('soundpool unload failed and catch error is ' + err.message);
    });
    ```

13. Call **off('loadComplete')** to stop listening for the completion of sound loading.

    ```ts
    soundPool.off('loadComplete');
    ```

14. Call **off('playFinished')** to stop listening for the completion of sound playing.

    ```ts
    soundPool.off('playFinished');
    ```

15. Call **off('error')** to stop listening for errors.

    ```ts
    soundPool.off('error');
    ```

16. Call **release()** to release the **SoundPool** instance.

    ```ts
    soundPool.release().then(() => {
      console.info('release success');
    }).catch((err: BusinessError) => {
      console.error('soundpool release failed and catch error is ' + err.message);
    });
    ```

### Sample Code

The following sample code implements low-latency playback using **SoundPool**.
  
```ts

import audio from '@ohos.multimedia.audio';
import media from '@ohos.multimedia.media';
import fs from '@ohos.file.fs'
struct Soundpool {
  private soundPool: media.SoundPool;
  private streamId: number = 0;
  private soundId: number = 0;
  private audioRendererInfo: audio.AudioRendererInfo = {
    content: audio.ContentType.CONTENT_TYPE_SPEECH,
    usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
    rendererFlags: 1
  }
  private PlayParameters: media.PlayParameters = {
    loop: number = 3, // The sound is played four times (three loops).
    rate: audio.AudioRendererRate = audio.AudioRendererRate.RENDER_RATE_NORMAL, // The sound is played at the original frequency.
    leftVolume: number = 0.5, // range = 0.0-1.0
    rightVolume: number = 0.5, // range = 0.0-1.0
    priority: number = 0, // The sound playback has the lowest priority.
    parallelPlayFlag: boolean = false // The sound is not played in parallel with other active audio streams.
  }
  private uri: string = "";
  async create(): Promise<void> {
    // Create a SoundPool instance.
    this.soundPool = await media.createSoundPool(5, this.audioRendererInfo);
    // Register listeners.
    this.loadCallback();
    this.finishPlayCallback();
    this.setErrorCallback();
    // Load a sound.
    await fs.open('/test_01.mp3', fs.OpenMode.READ_ONLY).then((file: fs.File) => {
      console.info("file fd: " + file.fd);
      this.uri = 'fd://' + (file.fd).toString()
    }); // '/test_01.mp3' here is only an example. You need to pass in the actual URI.
    this.soundId = await this.soundPool.load(this.uri);
  }
  async loadCallback(): Promise<void> {
    // Callback invoked when the sound finishes loading.
    this.soundPool.on('loadComplete', (soundId_: number) => {
      console.info('loadComplete, soundId: ' + soundId_);
    })
  }
  // Set the listener when the sound finishes playing.
  async finishPlayCallback(): Promise<void> {
    // Callback invoked when the sound finishes playing.
    this.soundPool.on('playFinished', () => {
      console.info("recive play finished message");
      // The sound can be played again.
    })
  }
  // Set the listener for errors.
  setErrorCallback(): void {
    this.soundPool.on('error', (error) => {
      console.info('error happened,message is :' + error.message);
    })
  }
  async PlaySoundPool(): Promise<void> {
    // Start playback. PlayParameters can be carried in the play() API.
    this.streamId = await this.soundPool.play(this.soundId);
    // Set the number of loops.
    this.soundPool.setLoop (this.streamId, 2); // The sound is played three times (two loops).
    // Set the priority.
    this.soundPool.setPriority(this.streamId, 1);
    // Set the playback rate.
    this.soundPool.setRate(this.streamId, audio.AudioRendererRate.RENDER_RATE_HALF); // The sound is played at half its original frequency.
    // Set the volume.
    this.soundPool.setVolume(this.streamId, 0.5, 0.5);
  }
  async release(): Promise<void> {
    // Stop the playback of the stream.
    this.soundPool.stop(this.streamId);
    // Unload the sound.
    await this.soundPool.unload(this.soundId);
    // Unregister the listeners.
    this.setOffCallback();
    // Release the SoundPool instance.
    await this.soundPool.release();
  }
  // Unregister the listeners.
  setOffCallback() {
    this.soundPool.off('loadComplete');
    this.soundPool.off('playFinished');
    this.soundPool.off('error');
  }
}
```
