# 录音无声定位指导
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

开发者在实现音频录制功能时，可能会遇到录音启动失败、没有录音数据回调、录音文件无声等问题。本文将介绍录音无声场景的常见现象、相关背景知识以及定位方法，并给出可直接对照的示例代码和定位流程。

## 问题现象

应用录音时，常见的无声问题表现如下：

- 录音实例创建失败或启动失败。
- 录音实例创建和启动成功，但没有收到录音数据回调。
- 可以收到录音数据回调，但数据长度始终为0，或录音文件播放时全为静音。
- 录音正常启动后，在通话、蓝牙切换、耳机插拔或其他特定场景下变为无声。

## 问题原因

**1. 启动前提不满足**

   录音启动前需要先完成权限申请、参数配置和录音实例创建。如果权限未授权、参数不符合业务场景，或实例创建失败，后续启动录音或接收数据回调都会受到影响。基础录音流程可参考[使用AudioCapturer开发音频录制功能(ArkTS)](using-audiocapturer-for-recording.md)。

**2. 录音已经启动，但内容被静音或路由影响**

   录音无声不一定表示录音没有启动，也可能是录音已进入静音录制、输入设备路由发生变化、并发策略生效或应用写文件逻辑异常。常见表现是“能收到`readData`回调，但播放出来全是静音”“通话、蓝牙切换、耳机插拔后开始无声”“某个外设接入后录音内容不对”。

**3. 录音参数与业务场景不匹配**

   `SourceType`会影响录音通路、算法处理、并发打断策略以及输入设备选择。错误的`SourceType`可能导致“有数据但近似无声”的现象，或者录到的数据和业务预期完全不一致。比如普通麦克风录音误用了`SOURCE_TYPE_VOICE_COMMUNICATION`，或者原始采集场景没有按业务选对音源类型。相关说明可参考[选择合适的录制流类型](using-right-sourcetype-for-recording.md)。

**4. 运行状态和回调未按预期变化**

   录音场景下，应用除了要关注`start`接口是否成功，还需要同时关注状态变化、读数据回调、输入设备信息以及录音流变化信息。常见表现是“`start`返回成功但根本没有数据”“实例已经创建但状态没进`STATE_RUNNING`”“对象被页面生命周期提前释放后，后续调用都不再生效”。如果开发者不清楚该先看什么，可以按“权限 → 创建 → `STATE_RUNNING` → `readData` → 写文件 → `SourceType` → 输入设备/并发”的顺序排查。

## 问题定位流程

建议按照以下顺序逐步排查。每一步先确认一个可观察结果，再根据结果进入下一步或跳转到对应文档。

1. 确认录音启动前提。

   这一步先看基础前提是否成立，建议按“权限 → 参数配置 → 创建结果”的顺序检查。

   检查项如下：

   - 权限：确认应用已声明并申请`ohos.permission.MICROPHONE`权限。权限声明可参考[声明权限](../../security/AccessToken/declare-permissions.md)，动态授权可参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。
   - 参数配置：确认采样率、声道数、采样格式、编码格式和`SourceType`符合业务场景。
   - 创建结果：确认`createAudioCapturer`已成功返回录音实例。如果创建失败，先根据错误码和日志排查权限、参数配置和并发场景。

   创建录音实例前，普通麦克风录音可参考下方参数配置；VoIP场景需要根据语音通话场景选择对应的音源类型和数据流向。

   ``` TypeScript
   let audioStreamInfo: audio.AudioStreamInfo = {
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
     channels: audio.AudioChannel.CHANNEL_2,
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
   };
   let audioCapturerInfo: audio.AudioCapturerInfo = {
     source: audio.SourceType.SOURCE_TYPE_MIC,
     capturerFlags: 0
   };
   let audioCapturerOptions: audio.AudioCapturerOptions = {
     streamInfo: audioStreamInfo,
     capturerInfo: audioCapturerInfo
   };
   ```

   创建流程可参考AudioCaptureSampleJS页面代码中的`create_AudioCapturer`。

   <!-- @[create_AudioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) --> 
   
   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   // ...
   let audioStreamInfo: audio.AudioStreamInfo = {
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
     channels: audio.AudioChannel.CHANNEL_2, // 通道。
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
   };
   let audioCapturerInfo: audio.AudioCapturerInfo = {
     source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型:Mic音频源。根据业务场景配置,参考SourceType。
     capturerFlags: 0 // 音频采集器标志。
   };
   let audioCapturerOptions: audio.AudioCapturerOptions = {
     streamInfo: audioStreamInfo,
     capturerInfo: audioCapturerInfo
   };
   // ...
     audio.createAudioCapturer(audioCapturerOptions, (err, capturer) => { // 创建AudioCapturer实例。
       if (err) {
         console.error(`${TAG}: Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
         // ...
         return;
       }
       console.info(`${TAG}: create AudioCapturer success`);
       // ...
       audioCapturer = capturer;
       if (audioCapturer !== undefined) {
         audioCapturer.on('readData', onReadData);
         // ...
       }
     });
   ```

2. 确认录音实例是否进入运行状态。

   建议按“`start`结果 → 当前状态 → 状态变化 → 提前释放”的顺序检查。

   检查项如下：

   - `start`结果：确认`start`接口调用成功。
   - 当前状态：读取`audioCapturer.state`，或注册`stateChange`事件确认状态变化。
   - 状态变化：如果状态没有进入`STATE_RUNNING`，打印当前状态，并检查`start`前实例状态是否为`STATE_PREPARED`、`STATE_PAUSED`或`STATE_STOPPED`。
   - 提前释放：确认没有其他业务提前调用`stop`、`pause`或`release`。
   - OHAudio回调：使用OHAudio开发录音功能时，确认已按C/C++接口要求注册状态回调，并确认启动后状态进入运行态。相关接口可参考[使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)。

   状态查询和状态监听可参考AudioCaptureSampleJS页面代码中的`view_AudioCapturerState`和`listen_AudioCapturerState`。

   <!-- @[view_AudioCapturerState](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) --> 
   
   ``` TypeScript
   let audioCapturerState: audio.AudioState = audioCapturer.state;
   console.info(`Current state is: ${audioCapturerState }`)
   ```

3. 如果没有收到录音数据回调，检查回调注册和对象生命周期。

   建议按“注册时机 → 运行状态 → 对象生命周期 → 回调耗时”的顺序检查。

   检查项如下：

   - 注册时机：确认在录音实例创建成功后调用`audioCapturer.on('readData', readDataCallback)`注册回调。
   - 运行状态：确认录音实例已进入`STATE_RUNNING`。
   - 对象生命周期：如果回调已经注册但仍无数据，确认录音对象没有被页面生命周期、路由切换或业务清理逻辑提前释放。
   - 回调耗时：确认没有在`readData`回调中执行上传、转码、大文件写入合并等耗时任务，避免阻塞读数据线程。
   - OHAudio回调：使用OHAudio开发录音功能时，确认已按C/C++接口要求设置音频数据读取回调。具体流程可参考[使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)。

   回调注册可参考AudioCaptureSampleJS页面代码中的`listen_AudioCapturer`。

   <!-- @[listen_AudioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) --> 
   
   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common, abilityAccessCtrl, PermissionRequestResult } from '@kit.AbilityKit';
   
   // ...
   class Options {
     public offset?: number;
     public length?: number;
   }
   
   // ...
      let writtenBytes: number = 0;
      pendingRecordingWrite = Promise.resolve();
      let path = context.cacheDir;
      let filePath = path + '/S16LE_2_48000.pcm';
      recordingFile = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
      onReadData = (buffer: ArrayBuffer) => {
        let recordingBuffer = buffer.slice(0);
        let writeOffset = writtenBytes;
        writtenBytes += recordingBuffer.byteLength;
        let options: Options = {
          offset: writeOffset,
          length: recordingBuffer.byteLength
        }
        pendingRecordingWrite = pendingRecordingWrite.then(async () => {
          await fs.write(recordingFile.fd, recordingBuffer, options);
        }).catch((error: BusinessError) => {
          console.error(`${TAG}: Write recording data failed, code: ${error.code}, message: ${error.message}`);
        });
      };
     // ...
         audioCapturer.on('readData', onReadData);
   ```

4. 如果收到`readData`回调但录音结果无声，检查数据写入和解析逻辑。

   建议按“文件句柄 → 写入偏移 → 写入长度 → PCM解析参数 → 数据生命周期”的顺序检查。

   检查项如下：

   - 文件句柄：确认文件句柄创建成功。
   - 写入偏移：确认写入时使用的偏移量会随累计写入字节数递增，避免重复覆盖同一段数据。
   - 写入长度：确认写入长度与`readData`回调中的`buffer.byteLength`一致，避免只写入部分数据。
   - PCM解析参数：确认后续播放或解析PCM时使用的采样率、声道数、采样格式与录音参数一致。
   - 数据生命周期：如果需要停止录音后再拼接、上传、转码或解析PCM数据，不要长期保存`readData`回调参数`ArrayBuffer`的引用；应在回调内立即拷贝出独立数据副本，再交给后续业务处理。

   写文件流程可参考AudioCaptureSampleJS页面代码中的`readDataCallback`。

   ``` TypeScript
   readDataCallback = (buffer: ArrayBuffer) => {
     let options: Options = {
       offset: bufferSize,
       length: buffer.byteLength
     }
     fs.writeSync(file.fd, buffer, options);
     bufferSize += buffer.byteLength;
   };
   ```

5. 如果录音内容持续无声，检查音源类型和静音策略。

   建议按“`SourceType` → 静音打断策略 → 音频会话策略 → 并发时间点”的顺序检查。

   检查项如下：

   - `SourceType`：确认`SourceType`与业务场景匹配。普通录音通常使用`SOURCE_TYPE_MIC`，VoIP通话场景使用`SOURCE_TYPE_VOICE_COMMUNICATION`，直播场景使用`SOURCE_TYPE_LIVE`，原始数据采集场景使用`SOURCE_TYPE_UNPROCESSED`。更多说明可参考[选择合适的录制流类型](using-right-sourcetype-for-recording.md)。
   - 静音打断策略：确认应用是否调用了`setWillMuteWhenInterrupted`。
   - 音频会话策略：确认是否配置了音频会话策略并将行为设置为`MUTE_WHEN_INTERRUPTED`。
   - 并发时间点：确认无声开始时间点是否与来电、VoIP、语音播报或其他录音任务启动重合；如果怀疑录音流被静音或被并发策略影响，可通过录音流变化信息确认当前录音流和输入设备。

6. 如果问题与外设或并发场景相关，检查输入设备、路由和录音策略。

   建议按“当前输入设备 → 设备切换 → 其他录音流 → 并发策略”的顺序检查。

   检查项如下：

   - 当前输入设备：确认当前活跃输入设备是否为预期设备。
   - 设备切换：确认录音开始前后是否发生蓝牙耳机、有线耳机或USB声卡等输入设备切换。输入设备查询和监听可参考[查询和监听音频输入设备](audio-input-device-management.md)。
   - 路由切换：如果应用需要指定输入设备或处理设备切换，可参考[实现音频输入设备路由切换](audio-input-device-switcher.md)。
   - 其他录音流：确认当前设备上是否存在其他录音任务。可参考[查询和监听其他应用录制状态](audio-recording-stream-management.md)确认是否存在其他录音流。
   - 并发策略：如果业务与VoIP通话、系统来电、语音识别、转写、耳返、直播等场景并发，可参考[录音并发策略说明](audio-recording-concurrency.md)确认系统策略。

   如果无声与通话、其他录音任务、蓝牙耳机、有线耳机或USB声卡有关，可通过录音流变化和输入设备信息确认当前录音流、`SourceType`和输入设备是否符合预期。

   <!-- @[audioStreamManager_on](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioStreamManager.ets) --> 
   
   ``` TypeScript
   audioStreamManager.on('audioCapturerChange', (audioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) =>  {
     // ...
     for (let i = 0; i < audioCapturerChangeInfoArray.length; i++) {
       console.info(`## CapChange on is called for element ${i} ##`);
       console.info(`StreamId for ${i} is: ${audioCapturerChangeInfoArray[i].streamId}`);
       console.info(`Source for ${i} is: ${audioCapturerChangeInfoArray[i].capturerInfo.source}`);
       console.info(`Flag  ${i} is: ${audioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
   
       // ...
   
       let devDescriptor: audio.AudioDeviceDescriptors = audioCapturerChangeInfoArray[i].deviceDescriptors;
       for (let j = 0; j < audioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
         console.info(`Id: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
         console.info(`Type: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
         console.info(`Role: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
         console.info(`Name: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
         console.info(`Address: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
         console.info(`SampleRates: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
         console.info(`ChannelCounts ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
         console.info(`ChannelMask: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks}`);
       }
     }
     // ...
   });
   ```

   通过录音流信息查询接口获取蓝牙设备名称或地址时，如果应用未声明`ohos.permission.USE_BLUETOOTH`权限，蓝牙设备相关名称和地址字段可能为空。

## 相关文档参考

- 如果问题与普通录音、VoIP、直播或原始数据采集场景有关，优先参考[选择合适的录制流类型](using-right-sourcetype-for-recording.md)。
- 如果问题与其他录音任务、通话或音频会话策略并发有关，优先参考[录音并发策略说明](audio-recording-concurrency.md)和[查询和监听其他应用录制状态](audio-recording-stream-management.md)。
- 如果问题与蓝牙耳机、有线耳机、USB声卡等输入设备切换有关，优先参考[查询和监听音频输入设备](audio-input-device-management.md)和[实现音频输入设备路由切换](audio-input-device-switcher.md)。
