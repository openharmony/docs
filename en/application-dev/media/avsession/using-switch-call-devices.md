# Using the Call Device Switching Component

## Basic Concepts

The system no longer provides APIs for switching the audio output device. If your application wants to provide the feature of switching the audio output device, it needs to integrate the **\<AVCastPicker>** component. This topic describes how to integrate the **\<AVCastPicker>** component to implement the switching of call devices.

## How to Develop

1. Create the **\<AVCastPicker>** component on the call page that provides device switching.

   ```ts
   import AVCastPicker from '@ohos.multimedia.avCastPicker';

   // Create the component and set its size.
   build() {
     Row() {
       Column() {
         AVCastPicker()
           .size({height:'100%',width:'100%'})
       }
     }
   }
   ```

2. Create an AVSession of the voice_call type. The AVSession constructor provides **AVSessionType** to specify the session type, and **voice_call** indicates the call type.

   ```ts
   import avSession from "@ohos.multimedia.avsession"

   // Create an AVSession of the voice_call type.
   let session = await avSession.createAVSession(getContext(this), 'voiptest', 'voice_call');
   // (Optional) Set the call information.
   let callMeta: avSession.CallMetadata = {
     name: "SessionTest", // Name of the contact.
     phoneNumber: "123XXX890" // Phone number of the contact.
   }
   ```

3. Create an AudioRenderer of the VOICE_COMMUNICATION type and start playing. For details about the implementation, see [Developing Audio Call](../audio/audio-call-development.md).

   ```ts
   import audio from '@ohos.multimedia.audio';

   let audioRenderer: audio.AudioRenderer | undefined = undefined;
   let audioStreamInfo: audio.AudioStreamInfo = {
     // Set the parameters based on project requirements. The following parameters are for reference only.
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
     channels: audio.AudioChannel.CHANNEL_2, // Channel.
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
   }
   let audioRendererInfo: audio.AudioRendererInfo = {
     // Set the parameters related to the call scenario.
     usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // Audio stream usage type: voice communication.
     rendererFlags: 0 // AudioRenderer flag. The default value is 0.
   }
   let audioRendererOptions: audio.AudioRendererOptions = {
     streamInfo: audioStreamInfo,
     rendererInfo: audioRendererInfo
   }

   // Create an AudioRenderer instance, and set the events to listen for.
   audio.createAudioRenderer(audioRendererOptions, (err: BusinessError, renderer: audio.AudioRenderer) => { // Create an AudioRenderer instance.
     if (err) {
       console.info(TAG, `Invoke createAudioRenderer failed, code is ${err.code}, message is ${err.message}`);
       return;
     } else {
       console.info(TAG,'Invoke createAudioRenderer succeeded.');
       audioRenderer = renderer;
       // Start the AudioRenderer.
       audioRenderer.start((err: BusinessError) => {
         if (err) {
           console.error(TAG, `Renderer start failed, code is ${err.code}, message is ${err.message}`);
         } else {
           console.info(TAG,'Renderer start success.');
         }
       });
     }
   });
   ```

4. Listen for audio output device changes.

   ```ts
   let audioManager = audio.getAudioManager(); // Create an AudioManager instance.
   let audioRoutingManager = audioManager.getRoutingManager(); // Call an API of AudioManager to create an AudioRoutingManager instance.
   // (Optional) Listen for audio output device changes.
   audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', audioRendererInfo, (desc: audio.AudioDeviceDescriptors) => {
     console.info(TAG, `device change To : ${desc[0].deviceType}`);  // Device type.
   });
   ```

5. Destroy the AVSession when the call ends.

   ```ts
   // Destroy the AVSession created in step 1 when the call ends.
   session.destroy((err) => {
     if (err) {
       console.error(`Failed to destroy session. Code: ${err.code}, message: ${err.message}`);
     } else {
       console.info(`Destroy : SUCCESS `);
     }
   });
   ```
