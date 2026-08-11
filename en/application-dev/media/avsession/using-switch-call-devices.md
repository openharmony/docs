# Switching Call Devices Using Components

<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=c9dcc12ca328989783da9ca7a900edb5d9480648 translatedAt=2026-08-10T03:50:53.667Z pushedAt=2026-08-10T08:55:26.815Z -->

## Switching Call Output Devices

This topic describes how to integrate the **AVCastPicker** component to implement call device switching. For details about related parameters, see [@ohos.multimedia.avCastPicker (AVCastPicker)](../../reference/apis-avsession-kit/ohos-multimedia-avcastpicker.md) and [@ohos.multimedia.avCastPickerParam (AVCastPicker Parameters)](../../reference/apis-avsession-kit/js-apis-avCastPickerParam.md). If you want to implement audio output device routing switching, see [Switching Audio Output Devices](../audio/audio-output-device-switcher.md).

Currently, the system provides the default style and custom style for the **AVCastPicker** component.

- If the application chooses to display the default style, when the device switches, the system displays the default component style based on the currently selected device.

- If the application opts for a custom style, it needs to refresh its defined style in response to device changes.

### Implementing the Default Style

1. Create an AVSession of the **voice_call** type. The AVSession constructor provides **AVSessionType** to specify the session type, and **voice_call** indicates the call type. If no AVSession is created, an empty list is displayed.

   <!-- @[create_voiceCall](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/pages/Index.ets) -->    

   ``` TypeScript
   import { AVCastPicker, AVCastPickerState, AVInputCastPicker, avSession } from '@kit.AVSessionKit';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Simulated call';
     @State session: avSession.AVSession | undefined = undefined;
     @State context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
     // ...
    
     async init() {
       try {
         let context = this.getUIContext().getHostContext() as Context;
         // Create a voice_call type AVSession when the call starts.
         this.session = await avSession.createAVSession(context, 'SESSION_NAME', 'voice_call');
       } catch (err) {
         console.error(`AVSession create :  Error: Code: ${err.code}, message: ${err.message}`);
       }
       // ...
     }
     // ...
   }
   ```

2. Create the **AVCastPicker** component on the call page that provides device switching.

   <!-- @[create_castPicker](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/pages/SwitchOutputDevice.ets) -->     

   ``` TypeScript
   import { AVCastPicker } from '@kit.AVSessionKit';

   @Entry
   @Component
   struct OutputCastPicker {
     @State normalColor:Color = Color.White;
     @State activeColor:Color = Color.Blue;
     @State pickerImage: ResourceStr = $r('app.media.sound'); // Custom resource.
     // ...
     // Create the component and set its size.
     build() {
       Row() {
         Column() {
           AVCastPicker({
             normalColor: this.normalColor,
             activeColor: this.activeColor,
           })
             .size({ width: '50%', height: '20%' })
             .id('AVCastPicker')
           // ...
         }
         .width('100%')
         .alignItems(HorizontalAlign.Center)
       }
       .alignItems(VerticalAlign.Center)
       .width('100%')
       .height('100%')
     }
   }
   ```

   Alternatively, create the **AVCastPickerHelper** component.

   <!-- @[create_castPickerHelper](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/utils/AVCastPickerHelper.ets) -->   

   ``` TypeScript
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { avSession } from '@kit.AVSessionKit';
   
   class MyPage {
     private avCastPicker: avSession.AVCastPickerHelper;
   
     constructor(context: common.UIAbilityContext) {
       this.avCastPicker = new avSession.AVCastPickerHelper(context);
     }
   
     async selectCastDevice() {
       const avCastPickerOptions: avSession.AVCastPickerOptions = {
         sessionType: 'video',
       };
   
       this.avCastPicker.select(avCastPickerOptions).then(() => {
         console.info('select successfully');
       }).catch((err: BusinessError) => {
         console.error('AVCastPicker.select failed with err: ${err.code}, ${err.message}');
       });
     }
   }
   ```

3. Create an AudioRenderer of the **VOICE_COMMUNICATION** type and start playing. For details about call audio playback, see [Developing Audio Call](../audio/audio-call-development.md).

   <!-- @[start_render](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/utils/AudioRenderer.ets) -->         

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { resourceManager } from '@kit.LocalizationKit';
   import { fileIo } from '@kit.CoreFileKit';

   class Options {
     public offset: number = 0;
     public length: number = 0;
   }
   export default class AudioRenderer {
     private audioRenderer: audio.AudioRenderer | undefined = undefined;
     private audioStreamInfo: audio.AudioStreamInfo = {
       // Configure based on the actual scenario. The current parameters are for reference only.
       samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
       channels: audio.AudioChannel.CHANNEL_2, // Channels.
       sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sample format.
       encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
     }
     public appContext?: common.UIAbilityContext | undefined = undefined;
     private audioSource = 'test1.wav';
     private fileDescriptor?: resourceManager.RawFileDescriptor | undefined = undefined;
     // ...
     async getStageFileDescriptor(fileName: string): Promise<resourceManager.RawFileDescriptor | undefined> {
       let fileDescriptor: resourceManager.RawFileDescriptor | undefined = undefined;
       if (this.appContext) {
         let mgr = this.appContext.resourceManager;
         this.fileDescriptor = mgr.getRawFdSync(fileName);
         await mgr.getRawFd(fileName).then(value => {
           fileDescriptor = value;
           console.info('case getRawFileDescriptor success fileName: ' + fileName);
         }).catch((error: BusinessError) => {
           console.error('case getRawFileDescriptor err: ' + error);
         });
       }
       return fileDescriptor;
     }
   
     async startRenderer(): Promise<void> {
       if (this.audioRenderer !== undefined) {
         return;
       }
       await this.getStageFileDescriptor(this.audioSource).then((res) => {
         this.fileDescriptor = res;
       });
       if (!this.fileDescriptor) {
         return;
       }
       let file: resourceManager.RawFileDescriptor = this.fileDescriptor;
       try {
         this.audioRenderer = await audio.createAudioRenderer(this.audioRendererOption);
       } catch (error) {
         console.error(`audioRenderer create : Error: ${JSON.stringify(error)}`);
         return;
       }
       let bufferSize: number = this.fileDescriptor.offset;
       let writeDataCallback = (buffer: ArrayBuffer) => {
         let options: Options = {
           offset: bufferSize,
           length: buffer.byteLength
         }
         fileIo.readSync(file.fd, buffer, options);
         bufferSize += buffer.byteLength;
       };
       this.audioRenderer.on('writeData', writeDataCallback);
       await this.audioRenderer.start();
     }

     async stopRenderer(): Promise<void> {
       if (this.audioRenderer) {
         await this.audioRenderer.release();
         this.audioRenderer = undefined;
       }
       if (this.fileDescriptor) {
         this.closeResource(this.audioSource);
         this.fileDescriptor = undefined;
       }
     }

     async closeResource(fileName: string): Promise<void> {
       if (this.appContext) {
         let mgr = this.appContext.resourceManager;
         await mgr.closeRawFd(fileName).then(() => {
           console.info('case closeRawFd success fileName: ' + fileName);
         }).catch((error: BusinessError) => {
           console.error('case closeRawFd err: ' + error);
         });
       }
     }
   }
   ```

4. (Optional) Subscribe to audio output device change events if you want to know the device change status.

   <!-- @[device_monitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/utils/AudioRenderer.ets) -->       

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   // ...
   export default class AudioRenderer {
     // ...
     private audioManager: audio.AudioManager | undefined = undefined;
     private audioRoutingManager: audio.AudioRoutingManager | undefined = undefined;
     private audioRendererInfo: audio.AudioRendererInfo = {
       // Use parameters appropriate for the call scenario.
       usage: audio.StreamUsage.STREAM_USAGE_VIDEO_COMMUNICATION, // Audio stream usage type: VOIP video call. The default is speaker.
       rendererFlags: 0 // Audio renderer flag. The default value 0 is sufficient.
     }
     private  audioRendererOption: audio.AudioRendererOptions = {
       streamInfo: this.audioStreamInfo,
       rendererInfo: this.audioRendererInfo
     };

     async observerDevices() {
       this.audioManager = audio.getAudioManager(); // Obtain the audioManager first.
       if (!this.audioManager) {
         console.error('get audioManager failed');
         return;
       }
       // Then call the AudioManager method to create an AudioRoutingManager instance.
       this.audioRoutingManager = this.audioManager.getRoutingManager();
       if(!this.audioRoutingManager) {
         return;
       }
       // Optionally listen for the current output device switching callback.
       this.audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', this.audioRendererInfo, (desc: audio.AudioDeviceDescriptors) => {
         console.info(`device change to: ${desc[0].deviceType}`); // Device type.
       });
     }
     // ...
   }
   ```

5. Destroy the AVSession when the call ends.

   <!-- @[destroy_session](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/pages/Index.ets) -->     

   ``` TypeScript
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

You can customize a style by setting the [customPicker](../../reference/apis-avsession-kit/ohos-multimedia-avcastpicker.md#avcastpicker) parameter of the [CustomBuilder](../../reference/apis-arkui/arkui-ts/ts-types.md#custombuilder8) type.

The procedure for implementing a custom style is similar to that for implementing the default style. You can create an AVSession and implement audio playback by referring to [Implementing the Default Style Implementation](#implementing-the-default-style).

The differences are as follows:

1. Create a custom **AVCastPicker**. You need to add custom parameters (corresponding to step 2 of the default style implementation).

   <!-- @[self_castPicker](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/pages/SelfAVCastPicker.ets) -->    

   ``` TypeScript
   import { AVCastPicker } from '@kit.AVSessionKit';
   // ...

   @Entry
   @Component
   struct SelfCastPicker {
     @State pickerImage: ResourceStr = $r('app.media.earpiece'); // Custom resource.
     // ...
     build() {
       Row() {
         Column() {
           AVCastPicker(
             {
               customPicker: (): void => this.ImageBuilder() // Add a custom parameter.
             }
           ).size({ height: 45, width: 45 })
         }
       }
     }

     // Custom content.
     @Builder
     ImageBuilder() {
       Image(this.pickerImage)
         .size({ width: '100%', height: '100%' })
         .backgroundColor('#00000000')
         .fillColor(Color.Black)
     }
   }
   ```

2. If the app needs to change the custom style based on output device changes, you must listen for device switching and refresh the custom style in real time (corresponding to step 4 of the default style implementation).

   <!-- @[device_monitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/pages/SelfAVCastPicker.ets) -->    

   ``` TypeScript
   import { audio } from '@kit.AudioKit';

   @Entry
   @Component
   struct SelfCastPicker {
     // ...
     async selfObserverDevices() {
       let audioManager = audio.getAudioManager();
       let audioRoutingManager = audioManager.getRoutingManager();

       // Obtain the current device and refresh the display when AVCastPicker is first launched.
       this.changePickerShow(audioRoutingManager.getPreferredOutputDeviceForRendererInfoSync(this.audioRendererInfo));

       // Listen for current audio output device switching to display different styles based on device type.
       audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', this.audioRendererInfo, (desc: audio.AudioDeviceDescriptors) => {
         this.changePickerShow(audioRoutingManager.getPreferredOutputDeviceForRendererInfoSync(this.audioRendererInfo));
       });
     }
   
     // Refresh the custom resource pickerImage after the device is updated.
     private changePickerShow(desc: audio.AudioDeviceDescriptors) {
       if(!desc || !desc.length || !desc[0]) {
         return;
       }
       if (desc[0].deviceType === 2) {
         this.pickerImage = $r('app.media.sound');
       } else if (desc[0].deviceType === 7) {
         this.pickerImage = $r('app.media.bluetooth');
       } else {
         this.pickerImage = $r('app.media.earpiece');
       }
     }
     // ...
   }
   ```

## Switching Call Input Devices

The system no longer provides APIs for audio input device switching. To switch audio input devices within an app, you can integrate the **AVInputCastPicker** component. For details about related parameters, see [@ohos.multimedia.avInputCastPicker](../../reference/apis-avsession-kit/ohos-multimedia-avinputcastpicker.md) and [@ohos.multimedia.avCastPickerParam](../../reference/apis-avsession-kit/js-apis-avCastPickerParam.md).

This topic describes how to integrate the **AVInputCastPicker** component to implement the switching of call input devices.

Currently, the system provides the default style and custom style for the **AVCastPicker** component.

- If the application chooses to display the default style, when the device switches, the system displays the default component style based on the currently selected device.

- If the application opts for a custom style, it needs to refresh its defined style in response to device changes.

### Default Style Implementation

1. Create the **AVInputCastPicker** component on the call page that provides device switching.

   <!-- @[default_InputCastPicker](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/pages/DefaultAVInputCastPicker.ets) -->   

   ``` TypeScript
   import { AVCastPickerState, AVInputCastPicker } from '@kit.AVSessionKit';

   // ...
     // Callback for device list display state changes (optional).
     private onStateChange(state: AVCastPickerState) {
       if (state === AVCastPickerState.STATE_APPEARING) {
         console.info('The picker starts showing.');
       } else if (state === AVCastPickerState.STATE_DISAPPEARING) {
         console.info('The picker finishes presenting.');
       }
     }

     // Create the component and set its size.
     build() {
       Row() {
         Column() {
           AVInputCastPicker(
             {
               onStateChange: this.onStateChange
             }
           ).size({ height: 45, width: 45 })
         }
       }
     }
   ```

2. Implement the call feature. For details, see [Developing Audio Call](../audio/audio-call-development.md).

### Custom Style Implementation

You can customize a style by setting the **customPicker** parameter of the [AVInputCastPicker](../../reference/apis-avsession-kit/ohos-multimedia-avinputcastpicker.md#avinputcastpicker).

1. When creating a custom **AVInputCastPicker** component, you must add a custom parameter.

   <!-- @[self_inputCastPicker](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/SwitchCallDevices/entry/src/main/ets/pages/SwitchInputDevice.ets) -->   

   ``` TypeScript
   import { AVCastPickerState, AVInputCastPicker } from '@kit.AVSessionKit';

   @Entry
   @Component
   struct InputCastPicker {
     @State pickerImage: ResourceStr = $r('app.media.sound'); // Custom resource.
     // ...

     // (Optional) Callback for the device list state change.
     private onStateChange(state: AVCastPickerState) {
       if (state === AVCastPickerState.STATE_APPEARING) {
         console.info('The picker starts showing.');
       } else if (state === AVCastPickerState.STATE_DISAPPEARING) {
         console.info('The picker finishes presenting.');
       }
     }
 
     build() {
       Row() {
         Column() {
           AVInputCastPicker(
             {
               customPicker: (): void => this.ImageBuilder(), // New custom parameter.
               onStateChange: this.onStateChange
             }
           )
             .size({ width: '50%', height: '20%' })
             .id('AVInputCastPicker')
           // ...
         }
         .width('100%')
         .alignItems(HorizontalAlign.Center)
       }
       .alignItems(VerticalAlign.Center)
       .width('100%')
       .height('100%')
     }

     // Custom content.
     @Builder
     ImageBuilder() {
       Text($r('app.string.switch_InputDevice'))
       Image(this.pickerImage)
         .size({ width: '100%', height: '100%' })
         .backgroundColor('#00000000')
         .fillColor(Color.Black)
     }
   }
   ```

2. Implement the call feature. For details, see [Developing Audio Call](../audio/audio-call-development.md).