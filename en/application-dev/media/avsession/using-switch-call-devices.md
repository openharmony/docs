# Using the Call Device Switching Component

## Basic Concepts

The system no longer provides APIs for switching audio output devices. To switch an audio output device, you must implement the **AVCastPicker** component. For details about the component, see [@ohos.multimedia.avCastPicker](../../reference/apis-avsession-kit/ohos-multimedia-avcastpicker.md) and [@ohos.multimedia.avCastPickerParam](../../reference/apis-avsession-kit/js-apis-avCastPickerParam.md).

This topic describes how to integrate the **AVCastPicker** component to implement the switching of call devices.

Currently, the system provides the default style and custom style for the **AVCastPicker** component. In the default style, the system displays the default component style based on the selected device during device switching. In the custom style, the application must refresh the style based on the device changes.

## How to Develop

### Implementing the Default Style

1. Create an AVSession of the voice_call type. The AVSession constructor provides **AVSessionType** to specify the session type, and **voice_call** indicates the call type. If no AVSession is created, an empty list is displayed.

   ```ts
   import { avSession } from '@kit.AVSessionKit';

   private session: avSession.AVSession | undefined = undefined;

   // Create an AVSession of the voice_call type.
   this.session = await avSession.createAVSession(getContext(this), 'voiptest', 'voice_call');
   ```

2. Create the **AVCastPicker** component on the call page that provides device switching.

   ```ts
   import { AVCastPicker } from '@kit.AVSessionKit';

   // Create the component and set its size.
   build() {
     Row() {
       Column() {
         AVCastPicker()
           .size({ height:45, width:45 })
       }
     }
   }
   ```

3. Create an AudioRenderer of the VOICE_COMMUNICATION type and start playing. For details about the implementation, see [Developing Audio Call](../audio/audio-call-development.md).

   ```ts
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   private audioRenderer: audio.AudioRenderer | undefined = undefined;
   private audioStreamInfo: audio.AudioStreamInfo = {
     // Set the parameters based on project requirements. The following parameters are for reference only.
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
     channels: audio.AudioChannel.CHANNEL_2, // Channel.
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
   }
   private audioRendererInfo: audio.AudioRendererInfo = {
     // Set the parameters related to the call scenario.
     usage: audio.StreamUsage.STREAM_USAGE_VIDEO_COMMUNICATION, // Audio stream usage type: VoIP video call, speaker by default.
     rendererFlags: 0 // AudioRenderer flag. The default value is 0.
   }
   private audioRendererOptions: audio.AudioRendererOptions = {
     streamInfo: this.audioStreamInfo,
     rendererInfo: this.audioRendererInfo
   }

   // Create an AudioRenderer instance, and set the events to listen for.
   try {
    this.audioRenderer = await audio.createAudioRenderer(this.audioRendererOptions);
   } catch (err) {
    console.error(`audioRender create :  Error: ${JSON.stringify(err)}`);
   }

   this.audioRenderer?.start((err: BusinessError) => {
    if (err) {
      console.error(`audioRender start faild :  Error: ${JSON.stringify(err)}`);
    } else {
      console.error('audioRender start success');
    }
   });
   ```

4. (Optional) Subscribe to audio output device change events if you want to know the device change status.

   ```ts
   import { audio } from '@kit.AudioKit';

   let audioManager = audio.getAudioManager(); // Create an AudioManager instance.
   let audioRoutingManager = audioManager.getRoutingManager(); // Call an API of AudioManager to create an AudioRoutingManager instance.

   // (Optional) Listen for audio output device changes.
   audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', this.audioRendererInfo, (desc: audio.AudioDeviceDescriptors) => {
     console.info(`device change To : ${desc[0].deviceType}`); // Device type.
   });
   ```

5. Destroy the AVSession when the call ends.

   ```ts
   // Destroy the AVSession created in step 1 when the call ends.
   this.session?.destroy((err) => {
     if (err) {
       console.error(`Failed to destroy session. Code: ${err.code}, message: ${err.message}`);
     } else {
       console.info(`Destroy : SUCCESS `);
     }
   });
   ```

### Implementing a Custom Style

You can customize a style by setting the **customPicker** parameter of the [CustomBuilder](../../reference/apis-avsession-kit/ohos-multimedia-avcastpicker.md) type.

The procedure for implementing a custom style is similar to that for implementing the default style. You can create an AVSession and implement audio playback by referring to [Implementing the Default Style Implementation](#implementing-the-default-style).

The differences are as follows:

1. When creating a custom **AVCastPicker** component, you must add a custom parameter. (This step corresponds to step 2 in the default style implementation.)

   ```ts
   import { AVCastPicker } from '@kit.AVSessionKit';

   @State pickerImage:ResourceStr = $r('app.media.earpiece'); // Custom resources.

   build() {
     Row() {
       Column() {
         AVCastPicker(
           {
             customPicker: (): void => this.ImageBuilder() // Add a custom parameter.
           }
         ).size({ height: 45, width:45 })
       }
     }
   }

   // Custom content
   @Builder
   ImageBuilder(): void {
     Image(this.pickerImage)
       .size({ width: '100%', height: '100%' })
       .backgroundColor('#00000000')
       .fillColor(Color.Black)
   }
   ```

2. If the application needs to change the custom style based on audio output device changes, the application must listen for device change events and refresh the custom style in real time. (This step corresponds to step 4 in the default style implementation.)

   ```ts
   import { audio } from '@kit.AudioKit';

   async observerDevices() {
     let audioManager = audio.getAudioManager();
     let audioRoutingManager = audioManager.getRoutingManager();

     // When the AVCastPicker component is started for the first time, obtain the current device and refresh the content displayed.
     this.changePickerShow(audioRoutingManager.getPreferredOutputDeviceForRendererInfoSync(this.audioRendererInfo));

     // Listen for the switching of the audio output device and display different styles based on the device type.
     audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', this.audioRendererInfo, (desc: audio.AudioDeviceDescriptors) => {
       this.changePickerShow(audioRoutingManager.getPreferredOutputDeviceForRendererInfoSync(this.audioRendererInfo));
     });
   }

   // Refresh the custom resource pickerImage after the device is changed.
   private changePickerShow(desc: audio.AudioDeviceDescriptors) {
     if (desc[0].deviceType === 2) {
       this.pickerImage = $r('app.media.sound');
     } else if (desc[0].deviceType === 7) {
       this.pickerImage = $r('app.media.bluetooth');
     } else {
       this.pickerImage = $r('app.media.earpiece');
     }
   }
   ```

<!--RP1-->
<!--RP1End-->
