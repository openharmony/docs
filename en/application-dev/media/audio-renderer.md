# Audio Rendering Development

## Introduction

**AudioRenderer** provides APIs for rendering audio files and controlling playback. It also supports audio interruption. You can use the APIs provided by **AudioRenderer** to play audio files in output devices and manage playback tasks.
Before calling the APIs, be familiar with the following terms:

- **Audio interruption**: When an audio stream with a higher priority needs to be played, the audio renderer interrupts the stream with a lower priority. For example, if a call comes in when the user is listening to music, the music playback, which is the lower priority stream, is paused.
- **Status check**: During application development, you are advised to use **on('stateChange')** to subscribe to state changes of the **AudioRenderer** instance. This is because some operations can be performed only when the audio renderer is in a given state. If the application performs an operation when the audio renderer is not in the given state, the system may throw an exception or generate other undefined behavior.
- **Asynchronous operation**: To prevent the UI thread from being blocked, most **AudioRenderer** calls are asynchronous. Each API provides the callback and promise functions. The following examples use the promise functions. For more information, see [AudioRenderer in Audio Management](../reference/apis/js-apis-audio.md#audiorenderer8).
- **Audio interruption mode**: OpenHarmony provides two audio interruption modes: **shared mode** and **independent mode**. In shared mode, all **AudioRenderer** instances created by the same application share one focus object, and there is no focus transfer inside the application. Therefore, no callback will be triggered. In independent mode, each **AudioRenderer** instance has an independent focus object, and focus transfer is triggered by focus preemption. When focus transfer occurs, the **AudioRenderer** instance that is having the focus receives a notification through the callback. By default, the shared mode is used. You can call **setInterruptMode()** to switch to the independent mode.

## Working Principles

The following figure shows the audio renderer state transitions.

**Figure 1** Audio renderer state transitions

![audio-renderer-state](figures/audio-renderer-state.png)

- **PREPARED**: The audio renderer enters this state by calling **create()**.
- **RUNNING**: The audio renderer enters this state by calling **start()** when it is in the **PREPARED** state or by calling **start()** when it is in the **STOPPED** state.
- **PAUSED**: The audio renderer enters this state by calling **pause()** when it is in the **RUNNING** state. When the audio playback is paused, it can call **start()** to resume the playback.
- **STOPPED**: The audio renderer enters this state by calling **stop()** when it is in the **PAUSED** or **RUNNING** state.
- **RELEASED**: The audio renderer enters this state by calling **release()** when it is in the **PREPARED**, **PAUSED**, or **STOPPED** state. In this state, the audio renderer releases all occupied hardware and software resources and will not transit to any other state.

## How to Develop

For details about the APIs, see [AudioRenderer in Audio Management](../reference/apis/js-apis-audio.md#audiorenderer8).

1. Use **createAudioRenderer()** to create a global **AudioRenderer** instance.
   Set parameters of the **AudioRenderer** instance in **audioRendererOptions**. This instance is used to render audio, control and obtain the rendering status, and register a callback for notification.

   ```js
   import audio from '@ohos.multimedia.audio';
   import fs from '@ohos.file.fs';
   
   // Perform a self-test on APIs related to audio rendering.
   @Entry
   @Component
   struct AudioRenderer1129 {
     private audioRenderer: audio.AudioRenderer;
     private bufferSize; // It will be used for the call of the write function in step 3.
     private audioRenderer1: audio.AudioRenderer; // It will be used for the call in the complete example in step 14.
     private audioRenderer2: audio.AudioRenderer; // It will be used for the call in the complete example in step 14.

     async initAudioRender(){
       let audioStreamInfo = {
         samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
         channels: audio.AudioChannel.CHANNEL_1,
         sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
         encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
       }
       let audioRendererInfo = {
         content: audio.ContentType.CONTENT_TYPE_SPEECH,
         usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
         rendererFlags: 0 // 0 is the extended flag bit of the audio renderer. The default value is 0.
       }
       let audioRendererOptions = {
         streamInfo: audioStreamInfo,
         rendererInfo: audioRendererInfo
       }
       this.audioRenderer = await audio.createAudioRenderer(audioRendererOptions);
       console.log("Create audio renderer success.");
     }
   }
   ```

2. Use **start()** to start audio rendering.
   
   ```js
   async startRenderer() {
     let state = this.audioRenderer.state;
     // The audio renderer should be in the STATE_PREPARED, STATE_PAUSED, or STATE_STOPPED state when start() is called.
     if (state != audio.AudioState.STATE_PREPARED && state != audio.AudioState.STATE_PAUSED &&
     state != audio.AudioState.STATE_STOPPED) {
       console.info('Renderer is not in a correct state to start');
       return;
     }
   
     await this.audioRenderer.start();
   
     state = this.audioRenderer.state;
     if (state == audio.AudioState.STATE_RUNNING) {
       console.info('Renderer started');
     } else {
       console.error('Renderer start failed');
     }
   }
   ```
   
   The renderer state will be **STATE_RUNNING** once the audio renderer is started. The application can then begin reading buffers.
   
3. Call **write()** to write data to the buffer.

   Read the audio data to be played to the buffer. Call **write()** repeatedly to write the data to the buffer. Import fs from '@ohos.file.fs'; as step 1.

   ```js
   async writeData(){
     // Set a proper buffer size for the audio renderer. You can also select a buffer of another size.
     this.bufferSize = await this.audioRenderer.getBufferSize();
     let dir = globalThis.fileDir; // You must use the sandbox path.
     const filePath = dir + '/file_example_WAV_2MG.wav'; // The file to render is in the following path: /data/storage/el2/base/haps/entry/files/file_example_WAV_2MG.wav
     console.info(`file filePath: ${ filePath}`);
    
     let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
     let stat = await fs.stat(filePath); // Music file information.
     let buf = new ArrayBuffer(this.bufferSize);
     let len = stat.size % this.bufferSize == 0 ? Math.floor(stat.size / this.bufferSize) : Math.floor(stat.size / this.bufferSize + 1);
     for (let i = 0;i < len; i++) {
       let options = {
         offset: i * this.bufferSize,
         length: this.bufferSize
       }
       let readsize = await fs.read(file.fd, buf, options)
       let writeSize = await new Promise((resolve,reject)=>{
         this.audioRenderer.write(buf,(err,writeSize)=>{
           if(err){
             reject(err)
           }else{
             resolve(writeSize)
           }
         })
       })
     }
    
     fs.close(file)
     await this.audioRenderer.stop(); // Stop rendering.
     await this.audioRenderer.release(); // Release the resources.
   }
   ```

4. (Optional) Call **pause()** or **stop()** to pause or stop rendering.

   ```js
   async  pauseRenderer() {
     let state = this.audioRenderer.state;
     // The audio renderer can be paused only when it is in the STATE_RUNNING state.
     if (state != audio.AudioState.STATE_RUNNING) {
       console.info('Renderer is not running');
       return;
     }
   
     await this.audioRenderer.pause();
   
     state = this.audioRenderer.state;
     if (state == audio.AudioState.STATE_PAUSED) {
       console.info('Renderer paused');
     } else {
       console.error('Renderer pause failed');
     }
   }
   
   async  stopRenderer() {
     let state = this.audioRenderer.state;
     // The audio renderer can be stopped only when it is in STATE_RUNNING or STATE_PAUSED state.
     if (state != audio.AudioState.STATE_RUNNING && state != audio.AudioState.STATE_PAUSED) {
       console.info('Renderer is not running or paused');
       return;
     }
   
     await this.audioRenderer.stop();
   
     state = this.audioRenderer.state;
     if (state == audio.AudioState.STATE_STOPPED) {
       console.info('Renderer stopped');
     } else {
       console.error('Renderer stop failed');
     }
   }
   ```

5. (Optional) Call **drain()** to clear the buffer.

   ```js
    async  drainRenderer() {
    let state = this.audioRenderer.state;
    // drain() can be used only when the audio renderer is in the STATE_RUNNING state.
    if (state != audio.AudioState.STATE_RUNNING) {
      console.info('Renderer is not running');
      return;
    }
    
    await this.audioRenderer.drain();
    state = this.audioRenderer.state;
    } 
   ```

6. After the task is complete, call **release()** to release related resources.

   **AudioRenderer** uses a large number of system resources. Therefore, ensure that the resources are released after the task is complete.

   ```js
    async releaseRenderer() {
    let state = this.audioRenderer.state;
    // The audio renderer can be released only when it is not in the STATE_RELEASED or STATE_NEW state.
    if (state == audio.AudioState.STATE_RELEASED || state == audio.AudioState.STATE_NEW) {
      console.info('Renderer already released');
      return;
    }
    await this.audioRenderer.release();
   
    state = this.audioRenderer.state;
    if (state == audio.AudioState.STATE_RELEASED) {
      console.info('Renderer released');
    } else {
      console.info('Renderer release failed');
    }
    }
   ```

7. (Optional) Obtain the audio renderer information.

   You can use the following code to obtain the audio renderer information:

   ```js
   async getRenderInfo(){
     // Obtain the audio renderer state.
     let state = this.audioRenderer.state;
     // Obtain the audio renderer information.
     let audioRendererInfo : audio.AudioRendererInfo = await this.audioRenderer.getRendererInfo();
     // Obtain the audio stream information.
     let audioStreamInfo : audio.AudioStreamInfo = await this.audioRenderer.getStreamInfo();
     // Obtain the audio stream ID.
     let audioStreamId : number = await this.audioRenderer.getAudioStreamId();
     // Obtain the Unix timestamp, in nanoseconds.
     let audioTime : number = await this.audioRenderer.getAudioTime();
     // Obtain a proper minimum buffer size.
     let bufferSize : number = await this.audioRenderer.getBufferSize();
     // Obtain the audio renderer rate.
     let renderRate : audio.AudioRendererRate = await this.audioRenderer.getRenderRate();
   }
   ```

8. (Optional) Set the audio renderer information.

   You can use the following code to set the audio renderer information:

   ```js
   async setAudioRenderInfo(){
     // Set the audio renderer rate to RENDER_RATE_NORMAL.
     let renderRate : audio.AudioRendererRate = audio.AudioRendererRate.RENDER_RATE_NORMAL;
     await this.audioRenderer.setRenderRate(renderRate);
     // Set the interruption mode of the audio renderer to SHARE_MODE.
     let interruptMode : audio.InterruptMode = audio.InterruptMode.SHARE_MODE;
     await this.audioRenderer.setInterruptMode(interruptMode);
     // Set the volume of the stream to 0.5.
     let volume : number = 0.5;
     await this.audioRenderer.setVolume(volume);
   }
   ```

9. (Optional) Use **on('audioInterrupt')** to subscribe to the audio interruption event, and use **off('audioInterrupt')** to unsubscribe from the event.

   Audio interruption means that Stream A will be interrupted when Stream B with a higher or equal priority requests to become active and use the output device.

   In some cases, the audio renderer performs forcible operations such as pausing and ducking, and notifies the application through **InterruptEvent**. In other cases, the application can choose to act on the **InterruptEvent** or ignore it.

   In the case of audio interruption, the application may encounter write failures. To avoid such failures, interruption-unaware applications can use **audioRenderer.state** to check the audio renderer state before writing audio data. The applications can obtain more details by subscribing to the audio interruption events. For details, see [InterruptEvent](../reference/apis/js-apis-audio.md#interruptevent9).

   It should be noted that the audio interruption event subscription of the **AudioRenderer** module is slightly different from **on('interrupt')** in [AudioManager](../reference/apis/js-apis-audio.md#audiomanager). The **on('interrupt')** and **off('interrupt')** APIs are deprecated since API version 9. In the **AudioRenderer** module, you only need to call **on('audioInterrupt')** to listen for focus change events. When the **AudioRenderer** instance created by the application performs actions such as start, stop, and pause, it requests the focus, which triggers focus transfer and in return enables the related **AudioRenderer** instance to receive a notification through the callback. For instances other than **AudioRenderer**, such as frequency modulation (FM) and voice wakeup, the application does not create an instance. In this case, the application can call **on('interrupt')** in **AudioManager** to receive a focus change notification.

   ```js
   async subscribeAudioRender(){
     this.audioRenderer.on('audioInterrupt', (interruptEvent) => {
       console.info('InterruptEvent Received');
       console.info(`InterruptType: ${interruptEvent.eventType}`);
       console.info(`InterruptForceType: ${interruptEvent.forceType}`);
       console.info(`AInterruptHint: ${interruptEvent.hintType}`);
    
       if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
         switch (interruptEvent.hintType) {
         // Forcible pausing initiated by the audio framework. To prevent data loss, stop the write operation.
           case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
             console.info('isPlay is false');
             break;
         // Forcible stopping initiated by the audio framework. To prevent data loss, stop the write operation.
           case audio.InterruptHint.INTERRUPT_HINT_STOP:
             console.info('isPlay is false');
             break;
         // Forcible ducking initiated by the audio framework.
           case audio.InterruptHint.INTERRUPT_HINT_DUCK:
             break;
         // Undocking initiated by the audio framework.
           case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
             break;
         }
       } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
         switch (interruptEvent.hintType) {
         // Notify the application that the rendering starts.
           case audio.InterruptHint.INTERRUPT_HINT_RESUME:
             this.startRenderer();
             break;
         // Notify the application that the audio stream is interrupted. The application then determines whether to continue. (In this example, the application pauses the rendering.)
           case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
             console.info('isPlay is false');
             this.pauseRenderer();
             break;
         }
       }
     });
   }
   ```

10. (Optional) Use **on('markReach')** to subscribe to the mark reached event, and use **off('markReach')** to unsubscribe from the event.

    After the mark reached event is subscribed to, when the number of frames rendered by the audio renderer reaches the specified value, a callback is triggered and the specified value is returned.

    ```js
    async markReach(){
      this.audioRenderer.on('markReach', 50, (position) => {
        if (position == 50) {
          console.info('ON Triggered successfully');
        }
      });
      this.audioRenderer.off('markReach'); // Unsubscribe from the mark reached event. This event will no longer be listened for.
    }
    ```

11. (Optional) Use **on('periodReach')** to subscribe to the period reached event, and use **off('periodReach')** to unsubscribe from the event.

    After the period reached event is subscribed to, each time the number of frames rendered by the audio renderer reaches the specified value, a callback is triggered and the specified value is returned.

    ```js
    async periodReach(){
      this.audioRenderer.on('periodReach',10, (reachNumber) => {
        console.info(`In this period, the renderer reached frame: ${reachNumber} `);
      });
    
      this.audioRenderer.off('periodReach'); // Unsubscribe from the period reached event. This event will no longer be listened for.
    }
    ```

12. (Optional) Use **on('stateChange')** to subscribe to audio renderer state changes.

    After the **stateChange** event is subscribed to, when the audio renderer state changes, a callback is triggered and the audio renderer state is returned.

    ```js
    async stateChange(){
      this.audioRenderer.on('stateChange', (audioState) => {
        console.info('State change event Received');
        console.info(`Current renderer state is: ${audioState}`);
      });
    }
    ```

13. (Optional) Handle exceptions of **on()**.

    If the string or the parameter type passed in **on()** is incorrect , the application throws an exception. In this case, you can use **try catch** to capture the exception.

    ```js
    async errorCall(){
      try {
        this.audioRenderer.on('invalidInput', () => { // The string is invalid.
        })
      } catch (err) {
        console.info(`Call on function error, ${err}`); // The application throws exception 401.
      }
      try {
        this.audioRenderer.on(1, () => { // The type of the input parameter is incorrect.
        })
      } catch (err) {
        console.info(`Call on function error,  ${err}`); // The application throws exception 6800101.
      }
    }
    ```

14. (Optional) Refer to the complete example of **on('audioInterrupt')**.
     Declare audioRenderer1 and audioRenderer2 first. For details, see step 1.
     Create **AudioRender1** and **AudioRender2** in an application, configure the independent interruption mode, and call **on('audioInterrupt')** to subscribe to audio interruption events. At the beginning, **AudioRender1** has the focus. When **AudioRender2** attempts to obtain the focus, **AudioRender1** receives a focus transfer notification and the related log information is printed. If the shared mode is used, the log information will not be printed during application running.
     ```js
     async runningAudioRender1(){
       let audioStreamInfo = {
         samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
         channels: audio.AudioChannel.CHANNEL_1,
         sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S32LE,
         encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
       }
       let audioRendererInfo = {
         content: audio.ContentType.CONTENT_TYPE_MUSIC,
         usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
         rendererFlags: 0 // 0 is the extended flag bit of the audio renderer. The default value is 0.
       }
       let audioRendererOptions = {
         streamInfo: audioStreamInfo,
         rendererInfo: audioRendererInfo
       }
      
       // 1.1 Create an instance.
       this.audioRenderer1 = await audio.createAudioRenderer(audioRendererOptions);
       console.info("Create audio renderer 1 success.");
      
       // 1.2 Set the independent mode.
       this.audioRenderer1.setInterruptMode(1).then( data => {
         console.info('audioRenderer1 setInterruptMode Success!');
       }).catch((err) => {
         console.error(`audioRenderer1 setInterruptMode Fail: ${err}`);
       });
      
       // 1.3 Set the listener.
       this.audioRenderer1.on('audioInterrupt', async(interruptEvent) => {
         console.info(`audioRenderer1 on audioInterrupt : ${JSON.stringify(interruptEvent)}`)
       });
      
       // 1.4 Start rendering.
       await this.audioRenderer1.start();
       console.info('startAudioRender1 success');
      
       // 1.5 Obtain the buffer size, which is the proper minimum buffer size of the audio renderer. You can also select a buffer of another size.
       const bufferSize = await this.audioRenderer1.getBufferSize();
       console.info(`audio bufferSize: ${bufferSize}`);
      
       // 1.6 Obtain the original audio data file.
       let dir = globalThis.fileDir; // You must use the sandbox path.
       const path1 = dir + '/music001_48000_32_1.wav'; // The file to render is in the following path: /data/storage/el2/base/haps/entry/files/music001_48000_32_1.wav
       console.info(`audioRender1 file path: ${ path1}`);
       let file1 = fs.openSync(path1, fs.OpenMode.READ_ONLY);
       let stat = await fs.stat(path1); // Music file information.
       let buf = new ArrayBuffer(bufferSize);
       let len = stat.size % this.bufferSize == 0 ? Math.floor(stat.size / this.bufferSize) : Math.floor(stat.size / this.bufferSize + 1);
      
       // 1.7 Render the original audio data in the buffer by using audioRender.
       for (let i = 0;i < len; i++) {
         let options = {
           offset: i * this.bufferSize,
           length: this.bufferSize
         }
         let readsize = await fs.read(file1.fd, buf, options)
         let writeSize = await new Promise((resolve,reject)=>{
           this.audioRenderer1.write(buf,(err,writeSize)=>{
             if(err){
               reject(err)
             }else{
               resolve(writeSize)
             }
           })
         })
       }
       fs.close(file1)
       await this.audioRenderer1.stop(); // Stop rendering.
       await this.audioRenderer1.release(); // Release the resources.
     }
      
     async runningAudioRender2(){
       let audioStreamInfo = {
         samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
         channels: audio.AudioChannel.CHANNEL_1,
         sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S32LE,
         encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
       }
       let audioRendererInfo = {
         content: audio.ContentType.CONTENT_TYPE_MUSIC,
         usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
         rendererFlags: 0 // 0 is the extended flag bit of the audio renderer. The default value is 0.
       }
       let audioRendererOptions = {
         streamInfo: audioStreamInfo,
         rendererInfo: audioRendererInfo
       }
      
       // 2.1 Create another instance.
       this.audioRenderer2 = await audio.createAudioRenderer(audioRendererOptions);
       console.info("Create audio renderer 2 success.");
      
       // 2.2 Set the independent mode.
       this.audioRenderer2.setInterruptMode(1).then( data => {
         console.info('audioRenderer2 setInterruptMode Success!');
       }).catch((err) => {
         console.error(`audioRenderer2 setInterruptMode Fail: ${err}`);
       });
      
       // 2.3 Set the listener.
       this.audioRenderer2.on('audioInterrupt', async(interruptEvent) => {
         console.info(`audioRenderer2 on audioInterrupt : ${JSON.stringify(interruptEvent)}`)
       });
      
       // 2.4 Start rendering.
       await this.audioRenderer2.start();
       console.info('startAudioRender2 success');
      
       // 2.5 Obtain the buffer size.
       const bufferSize = await this.audioRenderer2.getBufferSize();
       console.info(`audio bufferSize: ${bufferSize}`);
      
       // 2.6 Read the original audio data file.
       let dir = globalThis.fileDir; // You must use the sandbox path.
       const path2 = dir + '/music002_48000_32_1.wav'; // The file to render is in the following path: /data/storage/el2/base/haps/entry/files/music002_48000_32_1.wav
       console.info(`audioRender2 file path: ${ path2}`);
       let file2 = fs.openSync(path2, fs.OpenMode.READ_ONLY);
       let stat = await fs.stat(path2); // Music file information.
       let buf = new ArrayBuffer(bufferSize);
       let len = stat.size % this.bufferSize == 0 ? Math.floor(stat.size / this.bufferSize) : Math.floor(stat.size / this.bufferSize + 1);
      
       // 2.7 Render the original audio data in the buffer by using audioRender.
       for (let i = 0;i < len; i++) {
         let options = {
           offset: i * this.bufferSize,
           length: this.bufferSize
         }
         let readsize = await fs.read(file2.fd, buf, options)
         let writeSize = await new Promise((resolve,reject)=>{
           this.audioRenderer2.write(buf,(err,writeSize)=>{
             if(err){
               reject(err)
             }else{
               resolve(writeSize)
             }
           })
         })
       }
       fs.close(file2)
       await this.audioRenderer2.stop(); // Stop rendering.
       await this.audioRenderer2.release(); // Release the resources.
     }
      
     // Integrated invoking entry.
     async test(){
       await this.runningAudioRender1();
       await this.runningAudioRender2();
     }
      
     ```