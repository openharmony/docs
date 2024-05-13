# 使用通话设备切换组件

## 基本概念

系统不再提供音频输出设备切换的API，如果需要应用内切换音频输出设备，请集成AVCastPicker组件。本文将主要介绍AVCastPicker组件接入，实现通话设备切换。

## 开发步骤

1. 在需要切换设备的通话界面创建AVCastPicker组件。

   ```ts
   import AVCastPicker from '@ohos.multimedia.avCastPicker';

   // 创建组件，并设置大小
   build() {
     Row() {
       Column() {
         AVCastPicker()
           .size({height:'100%',width:'100%'})
       }
     }
   }
   ```

2. 创建voice_call类型的AVSession，AVSession在构造方法中支持不同的类型参数，由AVSessionType定义，voice_call表示通话类型。

   ```ts
   import avSession from "@ohos.multimedia.avsession"

   // 通话开始时创建voice_call类型的avsession
   let session = await avSession.createAVSession(getContext(this), 'voiptest', 'voice_call');
   // 可选设置当前通话信息
   let callMeta: avSession.CallMetadata = {
     name: "SessionTest", // 联系人
     phoneNumber: "123XXX890"  // 联系人电话
   }
   ```

3. 创建VOICE_COMMUNICATION类型的AudioRenderer，并开始播放。具体通话音频播放等实现，请参考[AudioKit开发音频通话功能](../audio/audio-call-development.md)。

   ```ts
   import audio from '@ohos.multimedia.audio';

   let audioRenderer: audio.AudioRenderer | undefined = undefined;
   let audioStreamInfo: audio.AudioStreamInfo = {
     // 请按照实际场景设置，当前参数仅参考
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率
     channels: audio.AudioChannel.CHANNEL_2, // 通道
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
   }
   let audioRendererInfo: audio.AudioRendererInfo = {
     // 需使用通话场景相应的参数
     usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // 音频流使用类型：语音通信
     rendererFlags: 0 // 音频渲染器标志：默认为0即可
   }
   let audioRendererOptions: audio.AudioRendererOptions = {
     streamInfo: audioStreamInfo,
     rendererInfo: audioRendererInfo
   }

   // 初始化，创建通话audiorenderer实例，设置监听事件
   audio.createAudioRenderer(audioRendererOptions, (err: BusinessError, renderer: audio.AudioRenderer) => { // 创建AudioRenderer实例
     if (err) {
       console.info(TAG, `Invoke createAudioRenderer failed, code is ${err.code}, message is ${err.message}`);
       return;
     } else {
       console.info(TAG,'Invoke createAudioRenderer succeeded.');
       audioRenderer = renderer;
       // 播放通话audiorenderer
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

4. 监听当前发声设备切换回调。

   ```ts
   let audioManager = audio.getAudioManager(); // 先创建audiomanager
   let audioRoutingManager = audioManager.getRoutingManager();  // 再调用AudioManager的方法创建AudioRoutingManager实例
   // 可选监听当前发声设备切换回调
   audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', audioRendererInfo, (desc: audio.AudioDeviceDescriptors) => {
     console.info(TAG, `device change To : ${desc[0].deviceType}`);  // 设备类型
   });
   ```

5. 通话结束后，销毁会话。

   ```ts
   // 通话结束销毁第一步创建的session
   session.destroy((err) => {
     if (err) {
       console.error(`Failed to destroy session. Code: ${err.code}, message: ${err.message}`);
     } else {
       console.info(`Destroy : SUCCESS `);
     }
   });
   ```
