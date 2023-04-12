# 音视频录制开发指导


## 使用场景

音视频录制的主要功能是录制音视频，并根据设置的编码格式、采样率、码率等参数封装输出文件。


## 接口说明

音视频录制API接口如下，具体的API详见接口文档。

  **表1** 音视频录制API接口

| 类名 | 接口名 | 功能 | 
| -------- | -------- | -------- |
| Recorder | int32_t&nbsp;SetVideoSource(VideoSourceType&nbsp;source,&nbsp;int32_t&nbsp;&amp;sourceId) | 设置录制视频源 | 
| Recorder | int32_t&nbsp;SetVideoEncoder(int32_t&nbsp;sourceId,&nbsp;VideoCodecFormat&nbsp;encoder) | 设置录制的视频编码器类型 | 
| Recorder | int32_t&nbsp;SetVideoSize(int32_t&nbsp;sourceId,&nbsp;int32_t&nbsp;width,&nbsp;int32_t&nbsp;height) | 设置录制的视频宽和高 | 
| Recorder | int32_t&nbsp;SetVideoFrameRate(int32_t&nbsp;sourceId,&nbsp;int32_t&nbsp;frameRate) | 设置要录制的视频帧率 | 
| Recorder | int32_t&nbsp;SetVideoEncodingBitRate(int32_t&nbsp;sourceId,&nbsp;int32_t&nbsp;rate) | 设置录制视频编码的码率 | 
| Recorder | int32_t&nbsp;SetCaptureRate(int32_t&nbsp;sourceId,&nbsp;double&nbsp;fps) | 设置视频帧的捕获帧率 | 
| Recorder | std::shared_ptr&lt;OHOS::Surface&gt;&nbsp;GetSurface(int32_t&nbsp;sourceId); | 获取对应输入源的surface | 
| Recorder | int32_t&nbsp;SetAudioSource(AudioSourceType&nbsp;source,&nbsp;int32_t&nbsp;&amp;sourceId) | 设置录制音频源 | 
| Recorder | int32_t&nbsp;SetAudioEncoder(int32_t&nbsp;sourceId,&nbsp;AudioCodecFormat&nbsp;encoder) | 设置录制的音频编码器类型 | 
| Recorder | int32_t&nbsp;SetAudioSampleRate(int32_t&nbsp;sourceId,&nbsp;int32_t&nbsp;rate) | 设置录制的音频采样率 | 
| Recorder | int32_t&nbsp;SetAudioChannels(int32_t&nbsp;sourceId,&nbsp;int32_t&nbsp;num) | 设置要录制的音频通道数 | 
| Recorder | int32_t&nbsp;SetAudioEncodingBitRate(int32_t&nbsp;sourceId,&nbsp;int32_t&nbsp;bitRate) | 设置录制音频编码的码率 | 
| Recorder | int32_t&nbsp;SetMaxDuration(int32_t&nbsp;duration) | 设置录制文件的最大时长 | 
| Recorder | int32_t&nbsp;SetOutputFormat(OutputFormatType&nbsp;format) | 设置输出文件格式 | 
| Recorder | int32_t&nbsp;SetOutputPath(const&nbsp;string&nbsp;&amp;path); | 设置输出文件保存路径 | 
| Recorder | int32_t&nbsp;SetOutputFile(int32_t&nbsp;fd) | 设置输出文件的fd | 
| Recorder | int32_t&nbsp;SetNextOutputFile(int32_t&nbsp;fd); | 设置下一个输出文件的fd | 
| Recorder | int32_t&nbsp;SetMaxFileSize(int64_t&nbsp;size) | 设置录制会话的最大文件大小 | 
| Recorder | int32_t&nbsp;SetRecorderCallback(const&nbsp;std::shared_ptr&lt;RecorderCallback&gt;&nbsp;&amp;callback) | 注册录制侦听器回调 | 
| Recorder | int32_t&nbsp;Prepare() | 准备录制 | 
| Recorder | int32_t&nbsp;Start() | 开始录制 | 
| Recorder | int32_t&nbsp;Pause() | 暂停录制 | 
| Recorder | int32_t&nbsp;Resume() | 恢复录制 | 
| Recorder | int32_t&nbsp;Stop(bool&nbsp;block) | 停止录制 | 
| Recorder | int32_t&nbsp;Reset(); | 重置录制 | 
| Recorder | int32_t&nbsp;Release() | 释放录制资源 | 
| Recorder | int32_t&nbsp;SetFileSplitDuration(FileSplitType&nbsp;type,&nbsp;int64_t&nbsp;timestamp,&nbsp;uint32_t&nbsp;duration) | 设置切分录像 | 
| Recorder | int32_t&nbsp;SetParameter(int32_t&nbsp;sourceId,&nbsp;const&nbsp;Format&nbsp;&amp;format) | 设置录制的扩展参数 | 


## 约束与限制

无。


## 开发步骤

1. 创建Recorder实例。
     
   ```
   Recorder *recorder = new Recorder();
   ```

2. 设置Recorder参数，包括设置音视频源信息，音视频编码格式，采样率，码率，视频宽高等信息。
     
   ```
   int32_t sampleRate = 48000; 
   int32_t channelCount = 1;
   AudioCodecFormat audioFormat = AAC_LC;
   AudioSourceType inputSource = AUDIO_MIC;
   int32_t audioEncodingBitRate = sampleRate;
   VideoSourceType source = VIDEO_SOURCE_SURFACE_ES;
   int32_t frameRate = 30;
   double fps = 30;
   int32_t rate = 4096;
   int32_t sourceId = 0;
   int32_t audioSourceId = 0;
   int32_t width = 1920;
   int32_t height = 1080;
   VideoCodecFormat encoder = H264;
   recorder->SetVideoSource(source, sourceId ); // 设置视频源，获得sourceId
   recorder->SetVideoEncoder(sourceId, encoder); // 设置视频编码格式
   recorder->SetVideoSize(sourceId, width, height); // 设置视频宽高
   recorder->SetVideoFrameRate(sourceId, frameRate); // 设置视频帧率
   recorder->SetVideoEncodingBitRate(sourceId, rate); // 设置视频编码码率
   recorder->SetCaptureRate(sourceId, fps); // 设置视频帧的捕获帧率
   recorder->SetAudioSource(inputSource, audioSourceId); // 设置音频源，获得audioSourceId
   recorder->SetAudioEncoder(audioSourceId, audioFormat); // 设置音频编码格式
   recorder->SetAudioSampleRate(audioSourceId, sampleRate); // 设置音频采样率
   recorder->SetAudioChannels(audioSourceId, channelCount); // 设置音频通道数
   recorder->SetAudioEncodingBitRate(audioSourceId, audioEncodingBitRate); // 设置音频编码码率
   ```

3. 准备录制，Recorder进行录制前的准备工作。
     
   ```
   recorder->Prepare(); // 准备录制
   ```

4. 开始录制，Recorder会根据设置的音频源和视频源进行录制。
     
   ```
   recorder->Start(); // 开始录制
   ```

5. 结束录制，释放资源。
     
   ```
   recorder->Stop(); // 停止录制
   recorder->Release(); // 释放录制资源
   ```
