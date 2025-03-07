# 使用通话设备切换组件

## 基本概念

系统不再提供音频输出设备切换的API，如果需要应用内切换音频输出设备，请实现AVCastPicker组件，相关参数可参考[@ohos.multimedia.avCastPicker](../../reference/apis-avsession-kit/ohos-multimedia-avcastpicker.md) 和 [@ohos.multimedia.avCastPickerParam](../../reference/apis-avsession-kit/js-apis-avCastPickerParam.md)。

本文将主要介绍AVCastPicker组件接入，实现通话设备切换。

当前系统支持两种组件样式的显示方式：默认样式显示和自定义样式显示。如果应用选择显示默认样式，当设备切换时，系统将根据当前选择的设备显示系统默认的组件样式；如果应用选择显示自定义样式，那么需要应用根据设备的变化刷新自己定义的样式。

## 开发步骤

### 默认样式实现

1. 创建voice_call类型的AVSession，AVSession在构造方法中支持不同的类型参数，由AVSessionType定义，voice_call表示通话类型，如果不创建，将显示空列表。

   ```ts
   import { avSession } from '@kit.AVSessionKit';

   private session: avSession.AVSession | undefined = undefined;

   // 通话开始时创建voice_call类型的avsession。
   this.session = await avSession.createAVSession(getContext(this), 'voiptest', 'voice_call');
   ```

2. 在需要切换设备的通话界面创建AVCastPicker组件。

   ```ts
   import { AVCastPicker } from '@kit.AVSessionKit';

   // 创建组件，并设置大小。
   build() {
     Row() {
       Column() {
         AVCastPicker()
           .size({ height:45, width:45 })
       }
     }
   }
   ```

3. 创建VOICE_COMMUNICATION类型的AudioRenderer，并开始播放。具体通话音频播放等实现，请参考[AudioKit开发音频通话功能](../audio/audio-call-development.md)。

   ```ts
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   private audioRenderer: audio.AudioRenderer | undefined = undefined;
   private audioStreamInfo: audio.AudioStreamInfo = {
     // 请按照实际场景设置，当前参数仅参考。
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
     channels: audio.AudioChannel.CHANNEL_2, // 通道。
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
   }
   private audioRendererInfo: audio.AudioRendererInfo = {
     // 需使用通话场景相应的参数。
     usage: audio.StreamUsage.STREAM_USAGE_VIDEO_COMMUNICATION, // 音频流使用类型：VOIP视频通话，默认为扬声器。
     rendererFlags: 0 // 音频渲染器标志：默认为0即可。
   }
   private audioRendererOptions: audio.AudioRendererOptions = {
     streamInfo: this.audioStreamInfo,
     rendererInfo: this.audioRendererInfo
   }

   // 初始化，创建通话audiorenderer实例，设置监听事件。
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

4. （可选）如果应用想知道设备切换情况，可以监听当前发声设备切换回调。

   ```ts
   import { audio } from '@kit.AudioKit';

   let audioManager = audio.getAudioManager(); // 先创建audiomanager。
   let audioRoutingManager = audioManager.getRoutingManager(); // 再调用AudioManager的方法创建AudioRoutingManager实例。

   // 可选监听当前发声设备切换回调。
   audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', this.audioRendererInfo, (desc: audio.AudioDeviceDescriptors) => {
     console.info(`device change To : ${desc[0].deviceType}`); // 设备类型。
   });
   ```

5. 通话结束后，销毁会话。

   ```ts
   // 通话结束销毁第一步创建的session。
   this.session?.destroy((err) => {
     if (err) {
       console.error(`Failed to destroy session. Code: ${err.code}, message: ${err.message}`);
     } else {
       console.info(`Destroy : SUCCESS `);
     }
   });
   ```

### 自定义样式实现

自定义样式通过设置[CustomBuilder](../../reference/apis-avsession-kit/ohos-multimedia-avcastpicker.md)类型的参数customPicker实现。

实现自定义样式的步骤与实现默认样式基本相同，开发者可参考[默认样式实现](#默认样式实现)，完成创建AVSession、实现音频播放等步骤。

存在差异的步骤如下所示。

1. 创建自定义AVCastPicker，需要新增自定义参数。（对应默认样式实现步骤2）

   ```ts
   import { AVCastPicker } from '@kit.AVSessionKit';

   @State pickerImage:ResourceStr = $r('app.media.earpiece'); // 自定义资源。

   build() {
     Row() {
       Column() {
         AVCastPicker(
           {
             customPicker: (): void => this.ImageBuilder() // 新增自定义参数。
           }
         ).size({ height: 45, width:45 })
       }
     }
   }

   // 自定义内容。
   @Builder
   ImageBuilder(): void {
     Image(this.pickerImage)
       .size({ width: '100%', height: '100%' })
       .backgroundColor('#00000000')
       .fillColor(Color.Black)
   }
   ```

2. 如果应用要根据出声设备变化而改变自定义样式，必须监听设备切换，然后实时刷新自定义样式。（对应默认样式实现步骤4）

   ```ts
   import { audio } from '@kit.AudioKit';

   async observerDevices() {
     let audioManager = audio.getAudioManager();
     let audioRoutingManager = audioManager.getRoutingManager();

     // 初次拉起AVCastPicker时需获取当前设备,刷新显示。
     this.changePickerShow(audioRoutingManager.getPreferredOutputDeviceForRendererInfoSync(this.audioRendererInfo));

     // 监听当前发声设备切换，及时根据不同设备类型显示不同的样式。
     audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', this.audioRendererInfo, (desc: audio.AudioDeviceDescriptors) => {
       this.changePickerShow(audioRoutingManager.getPreferredOutputDeviceForRendererInfoSync(this.audioRendererInfo));
     });
   }

   // 设备更新后刷新自定义资源pickerImage。
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