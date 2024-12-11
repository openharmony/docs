# Media Kit开发速览

当前 Media Kit 提供了 ArkTS 和 C/C++ 两种开发接口，实现了音视频播放、录制、元数据、转码等能力。Media Kit 的 API 文档和开发指导如下表所示。

|      | ArkTS 开发文档                        |      ArkTS API 文档          | C/C++ 开发文档                            | C/C++ API 文档                             |
| ------------ | ------------------------------------------------- | ------------------------------------------------- | ------------------------------------------------- | ------------------------------------------------- |
| 音频播放     | [使用AVPlayer接口播放音频(ArkTS)](using-avplayer-for-playback.md) | [AVPlayer(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avplayer9)    | [使用AVPlayer接口播放音频(C/C++)](using-ndk-avplayer-for-playback.md) |  [AVPlayer(C/C++)](../../reference/apis-media-kit/_a_v_player.md) |
| 视频播放     | [使用AVPlayer接口播放视频(ArkTS)](video-playback.md)              |  [AVPlayer(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avplayer9)    | [使用AVPlayer接口播放视频(C/C++)](using-ndk-avplayer-for-video-playback.md) | [AVPlayer(C/C++)](../../reference/apis-media-kit/_a_v_player.md) |
| 流媒体     |  [使用AVPlayer播放流媒体(ArkTS)](streaming-media-playback-development-guide.md)    |    [AVPlayer(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avplayer9)      | - | - |
| 添加字幕     | [使用AVPlayer接口添加视频外挂字幕(ArkTS)](video-subtitle.md) | [AVPlayer(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avplayer9) | - |- |
| 音频池       | [使用SoundPool接口播放短音频(ArkTS)](using-soundpool-for-playback.md)    |   [SoundPool(ArkTS)](../../reference/apis-media-kit/js-apis-inner-multimedia-soundPool.md)    | -                                     |   - |
| 音频录制     | [使用AVRecorder接口录制音频(ArkTS)](using-avrecorder-for-recording.md)  | [AVRecorder(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avrecorder9) | -                                     | - |
| 视频录制     | [使用AVRecorder接口录制视频(ArkTS)](video-recording.md) | [AVRecorder(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avrecorder9)  | -                                     |- |
| 录屏写文件   | [使用AVScreenCaptureRecorder接口录屏写文件(ArkTS)](using-avscreencapture-ArkTs.md)| [AVScreenCaptureRecoder(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avscreencapturerecorder12) | [使用AVScreenCapture接口录屏写文件(C/C++)](using-avscreencapture-for-file.md) | [AVScreenCapture(C/C++)](../../reference/apis-media-kit/_a_v_screen_capture.md) |
| 元数据       | [使用AVMetadataExtractor提取音视频元数据信息(ArkTS)](avmetadataextractor.md) | [AVMetadataExtractor(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avmetadataextractor11)  | -                                     | - |
| 图像提取     | [使用AVImageGenerator提取视频指定时间图像(ArkTS)](avimagegenerator.md) |[AVImageGenerator(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avimagegenerator12)| -| -                                     |
| 视频转码     | [使用AVTranscoder接口转码(ArkTS)](using-avtranscoder-for-transcodering.md) |[AVTranscoder(ArkTS)](../../reference/apis-media-kit/js-apis-media.md#avtranscoder12)| | -                                     |
| 录屏取码流   | -                                      | -         | [使用AVScreenCapture接口录屏取码流(C/C++)](using-avscreencapture-for-buffer.md) | [AVScreenCapture(C/C++)](../../reference/apis-media-kit/_a_v_screen_capture.md) |


