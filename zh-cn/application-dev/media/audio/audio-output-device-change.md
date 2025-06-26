# 响应音频流输出设备变更

开发者可以了解音频流输出设备变更信息，并完成相应适配，确保应用在设备发生变更时的用户体验。

开发者可使用AudioRenderer的[outputDeviceChangeWithInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#onoutputdevicechangewithinfo11)，用于监听音频流输出设备变化及原因。当系统出现音频输出设备的上下线、用户强选、设备抢占或设备选择策略变更等情况，导致音频流输出设备变更时，系统将通过该接口通知应用当前音频流设备变更信息，包含当前音频流输出设备信息和设备变更原因。

## 音频流输出设备信息

在[outputDeviceChangeWithInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#onoutputdevicechangewithinfo11)返回的音频流设备变更信息中，包含当前音频流输出设备信息，以数组形式发送，一般该列表仅包含一个设备信息，具体可参考[AudioDeviceDescriptors](../../reference/apis-audio-kit/arkts-apis-audio-t.md#audiodevicedescriptors)（设备信息列表）。

## 音频流输出设备变更原因

> **说明：**
当发生下述四种情况（[AudioStreamDeviceChangeReason](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiostreamdevicechangereason11)）时，系统将向应用发送设备变更回调。

- **REASON_NEW_DEVICE_AVAILABLE**：新设备可用。

  **触发场景：**

  普通蓝牙设备（耳机、眼镜、音箱、车机等）连接、支持佩戴检测的蓝牙设备（耳机、眼镜等）佩戴、有线设备（3.5mm耳机、Type-C耳机、USB耳机、USB音箱等）插入、分布式设备上线等。

- **REASON_OLD_DEVICE_UNAVAILABLE**：旧设备不可用。

  当报告此原因时，应用程序应考虑暂停音频播放。

  **触发场景：**

  普通蓝牙设备（耳机、眼镜、音箱、车机等）断开、支持佩戴检测的蓝牙耳机双耳摘下、支持佩戴检测的蓝牙眼镜摘下、有线设备（3.5mm耳机、Type-C耳机、USB耳机、音箱等）拔出、分布式设备下线等。

  针对此场景，常用业务场景的**处理建议**如下：

  - 游戏场景：不暂停
  - 听书场景：暂停
  - 音乐场景：暂停
  - 视频场景：暂停

- **REASON_OVERRODE**：用户强制选择设备。

  **触发场景：**

  用户从界面选择切换音频流输出设备、从外设选择接听蜂窝或VoIP来电。

- **REASON_UNKNOWN**：未知原因。

## 参考示例

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let audioRenderer: audio.AudioRenderer | undefined = undefined;
  let audioStreamInfo: audio.AudioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
    channels: audio.AudioChannel.CHANNEL_2, // 通道。
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
  };
  let audioRendererInfo: audio.AudioRendererInfo = {
    usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
    rendererFlags: 0 // 音频渲染器标志。
  };
  let audioRendererOptions: audio.AudioRendererOptions = {
    streamInfo: audioStreamInfo,
    rendererInfo: audioRendererInfo
  };
  
  // 创建AudioRenderer实例。
  audio.createAudioRenderer(audioRendererOptions).then((data) => {
    audioRenderer = data;
    console.info('AudioFrameworkRenderLog: AudioRenderer Created : Success : Stream Type: SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`AudioFrameworkRenderLog: AudioRenderer Created : ERROR : ${err}`);
  });
  
  if (audioRenderer) {
    // 订阅监听音频流输出设备变化及原因。
    (audioRenderer as audio.AudioRenderer).on('outputDeviceChangeWithInfo', async (deviceChangeInfo: audio.AudioStreamDeviceChangeInfo) => {
      switch (deviceChangeInfo.changeReason) {
        case audio.AudioStreamDeviceChangeReason.REASON_OLD_DEVICE_UNAVAILABLE:
          // 响应设备不可用事件，如果应用处于播放状态，应暂停播放，更新UX界面。
          // await audioRenderer.pause();
          break;
        case audio.AudioStreamDeviceChangeReason.REASON_NEW_DEVICE_AVAILABLE:
          // 应用根据业务情况响应设备可用事件。
          break;
        case audio.AudioStreamDeviceChangeReason.REASON_OVERRODE:
          // 应用根据业务情况响应设备强选事件。
          break;
        case audio.AudioStreamDeviceChangeReason.REASON_UNKNOWN:
          // 应用根据业务情况响应未知原因事件。
          break;
      }
    });
  }
  ```