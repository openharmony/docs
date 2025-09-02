# Using SoundPool to Play Short Sounds (ArkTS)

The [SoundPool](media-kit-intro.md#soundpool) class provides APIs to implement low-latency playback of short sounds.

Short sound effects (such as the camera shutter sound effect and system notification sound effect) are often required during application development. You can call the APIs provided by SoundPool to implement one-time loading of short sounds and multiple times of low-latency playback.

SoundPool currently supports playing of audio files that are under 1 MB in size after decoding. For audio files that exceed this limit after decoding, only the first 1 MB of data is played. This is equivalent to approximately 5.6 seconds of audio duration at a 44.1 kHz sampling rate with 16-bit depth for stereo sound. (At lower sampling rates or in mono mode, the duration may be slightly longer.)

This topic walks you through on how to use the SoundPool APIs to implement low-latency playback. For details about the API, see [SoundPool](../../reference/apis-media-kit/js-apis-inner-multimedia-soundPool.md).

The full process includes creating a SoundPool instance, loading a sound (including decapsulation and decoding), setting playback parameters (loop mode, and playback priority), playing the sound, stopping the playback, and releasing the instance. (For details about the decoding formats, see [Audio Decoding](../avcodec/audio-decoding.md).)

During application development, you must subscribe to playback state changes and call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur.  

> **NOTE**
>
> For details about the audio focus strategy when SoundPool is used to play short sounds, see [Introduction to Audio Focus and Audio Session](../audio/audio-playback-concurrency.md).

## How to Develop

1. Call **createSoundPool()** to create a SoundPool instance.

   ```ts
   import { media } from '@kit.MediaKit';
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   private soundPool: media.SoundPool | undefined = undefined;
   // If the value of usage in audioRenderInfo is STREAM_USAGE_UNKNOWN, STREAM_USAGE_MUSIC, STREAM_USAGE_MOVIE,
   // or STREAM_USAGE_AUDIOBOOK, SoundPool plays a short sound in audio mixing mode, without interrupting the playback of other audio streams.
   let audioRendererInfo: audio.AudioRendererInfo = {
     usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
     rendererFlags: 1 // AudioRenderer flag.
   };

   // Create a SoundPool instance.
   this.soundPool = await media.createSoundPool(14, audioRendererInfo); // A maximum of 14 streams can be played simultaneously.
   ```

2. Call **on('loadComplete')** to listen for the completion of sound loading.

   ```ts
   private soundId: number = 0;
   // Callback invoked when the sound finishes loading.
   this.soundPool!.on('loadComplete', (soundId_: number) => {
     this.soundId = soundId_;
     console.info('loadComplete soundId: ' + soundId_);
   })
   ```

3. Call **on('playFinished')** or **on('playFinishedWithStreamId')** to listen for the completion of audio playback.

    When only **'playFinished'** or **'playFinishedWithStreamId'** is subscribed to, the registered callback is triggered when the audio playback is complete.

    When both **'playFinished'** and **'playFinishedWithStreamId'** are subscribed to, the **'playFinishedWithStreamId'** callback is triggered, but the **'playFinished'** callback is not triggered, when the audio playback is complete.

    ```ts
    this.soundPool!.on('playFinished', () => {
      console.info("receive play finished message");
      // The sound can be played again.
    });
    this.soundPool!.on('playFinishedWithStreamId', (streamId) => {
      console.info("receive play finished message, streamId: " + streamId);
    });
    ```

4. Call **on('error')** to listen for errors that may occur.

    ```ts
    this.soundPool!.on('error', (error: BusinessError) => {
      console.error('error happened,message is :' + error.code);
      console.error('error happened,message is :' + error.message);
    });
    ```

5. Call **load()** to load a sound.

    You can pass in a URI or an FD to load the sound. The following uses the FD as an example. For more methods, see [SoundPool](../../reference/apis-media-kit/js-apis-inner-multimedia-soundPool.md#load).

    When the system finishes loading the sound, the **loadComplete** callback is invoked to notify the user that the loading is complete. Perform the subsequent play operation after the callback is received.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { fileIo as fs } from '@kit.CoreFileKit';

    private soundId: number = 0;
    // Obtain the context of the ability to which the current component belongs and obtain the application file path through the context.
    let context = this.getUIContext().getHostContext();
    // Obtain the file descriptor of the input file. test.ogg is a preset resource in the rawfile directory. Replace it with the actual one.
    let fileDescriptor = await context!.resourceManager.getRawFd('test.ogg');
    this.soundId = await this.soundPool!.load(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length);
    console.info(`load soundPool soundId: ${this.soundId}`)
    ```

6. Set **PlayParameters**, and call **play** after the **loadComplete** callback is received. If **play()** with the same sound ID passed in is called for multiple times, the sound is played only once.

    ```ts
    private soundId: number = 0;
    private streamId: number = 0;
    let playParameters: media.PlayParameters = {
      loop: 1, // Loop once, meaning the sound will play twice in total.
      rate: 1, // Play at normal speed.
      leftVolume: 0.5, // The value ranges from 0.0 to 1.0.
      rightVolume: 0.5, // The value ranges from 0.0 to 1.0.
      priority: 0, // The sound playback has the lowest priority.
    };
    // Start playback. The play operation can also contain PlayParameters. Perform the play operation after the audio resources are loaded, that is, after the loadComplete callback is received.
    this.soundPool!.play(this.soundId, playParameters, (error, streamID: number) => {
      if (error) {
        console.error(`play sound Error: errCode is ${error.code}, errMessage is ${error.message}`)
      } else {
        this.streamId = streamID;
        console.info('play success soundid:' + this.streamId);
      }
    });
    ```

7. Call **setLoop()** to set the number of loops.

    ```ts
    // Set the number of loops.
    await this.soundPool!.setLoop(this.streamId, 2); // Play the sound three times.
    ```

8. Call **setPriority()** to set the playback priority.

    ```ts
    // Set the priority.
    await this.soundPool!.setPriority(this.streamId, 1);
    ```

9. Call **setVolume()** to set the playback volume.

    ```ts
    // Set the volume.
    await this.soundPool!.setVolume(this.streamId, 0.5, 0.5);
    ```

10. Call **stop()** to stop the playback.

    ```ts
    // Stop the playback of the stream.
    await this.soundPool!.stop(this.streamId);
    ```

11. Call **unload()** to unload a sound.

    ```ts
    // Unload the sound.
    await this.soundPool!.unload(this.soundId);
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

15. Call **release()** to release the SoundPool instance.

    ```ts
    // Release the SoundPool instance.
    await this.soundPool!.release();
    ```

## Running the Sample Project

Refer to the sample project to use SoundPool to play audio at a low latency.

1. Create a project, download the [sample project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/SoundPool/SoundPoolArkTS), and copy its resources to the corresponding directories.

    ```
    SoundPoolArkTS
    entry/src/main/ets/
    └── pages
        └── Index.ets (Playback UI)
    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │
    └── rawfile
        └── test.ogg (Audio resource)
    ```
2. Compile and run the project.
