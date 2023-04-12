# 音视频播放开发指导


## 使用场景

音视频播放是将音视频文件或音视频流数据进行解码并通过输出设备进行播放的过程，同时对播放任务进行管理。


## 接口说明

音视频播放API接口功能如下，具体的API详见接口文档。

  **表1** 音视频播放API接口

| 类名 | 接口名 | 描述 | 
| -------- | -------- | -------- |
| Player | int32_t&nbsp;SetSource(const&nbsp;Source&nbsp;&amp;source); | 设置播放源 | 
| Player | int32_t&nbsp;Prepare(); | 准备播放 | 
| Player | int32_t&nbsp;Play(); | 开始播放 | 
| Player | bool&nbsp;IsPlaying() | 判断是否播放中 | 
| Player | int32_t&nbsp;Pause(); | 暂停播放 | 
| Player | int32_t&nbsp;Stop(); | 停止播放 | 
| Player | int32_t&nbsp;Rewind(int_64&nbsp;mSeconds,&nbsp;int32_t&nbsp;mode); | 改变播放位置 | 
| Player | int32_t&nbsp;SetVolume(float&nbsp;leftVolume,&nbsp;float&nbsp;rightVolume); | 设置音量，包括左声道和右声道。 | 
| Player | int32_t&nbsp;SetVideoSurface(Surface&nbsp;\*surface) | 设置播放窗口 | 
| Player | int32_t&nbsp;EnableSingleLooping(bool&nbsp;loop) | 设置循环播放 | 
| Player | bool&nbsp;IsSingleLooping(); | 判断是否循环播放 | 
| Player | int32_t&nbsp;GetCurrentTime(int64_t&nbsp;&amp;time)&nbsp;const; | 获取当前播放时长 | 
| Player | int32_t&nbsp;GetDuration(int64_t&nbsp;&amp;duration)&nbsp;const; | 获取总播放时长 | 
| Player | int32_t&nbsp;GetVideoWidth(int32_t&nbsp;&amp;videoWidth); | 获取视频源宽度 | 
| Player | int32_t&nbsp;GetVideoHeight(int32_t&nbsp;&amp;videoHeight); | 获取视频源高度 | 
| Player | int32_t&nbsp;Reset(); | 重置播放器 | 
| Player | int32_t&nbsp;Release(); | 释放播放器资源 | 
| Player | void&nbsp;SetPlayerCallback(const&nbsp;std::shared_ptr&lt;PlayerCallback&gt;&nbsp;&amp;cb); | 设置播放回调函数 | 
| Source | Source(const&nbsp;std::string&amp;&nbsp;uri); | 基于uri创建Source实例 | 
| Source | Source(const&nbsp;std::shared_ptr&lt;StreamSource&gt;&nbsp;&amp;stream,&nbsp;const&nbsp;Format&nbsp;&amp;formats); | 基于流创建Source实例 | 
| Source | SourceType&nbsp;GetSourceType()&nbsp;const; | 获取源类型 | 
| Source | const&nbsp;std::string&nbsp;&amp;GetSourceUri()&nbsp;const; | 获取音视频uri | 
| Source | const&nbsp;std::shared_ptr&lt;StreamSource&gt;&nbsp;&amp;GetSourceStream()&nbsp;const; | 获取音视频流 | 
| Source | const&nbsp;Format&nbsp;&amp;GetSourceStreamFormat()&nbsp;const; | 获取音视频流格式 | 
| Format | bool&nbsp;PutIntValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;int32_t&nbsp;value); | 设置整数类型的元数据 | 
| Format | bool&nbsp;PutLongValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;int64_t&nbsp;value); | 设置长整数类型的元数据 | 
| Format | bool&nbsp;PutFloatValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;float&nbsp;value); | 设置单精度浮点类型的元数据 | 
| Format | bool&nbsp;PutDoubleValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;double&nbsp;value); | 设置双精度浮点类型的元数据 | 
| Format | bool&nbsp;PutStringValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;const&nbsp;std::string&nbsp;&amp;value); | 设置字符串类型的元数据 | 
| Format | bool&nbsp;GetIntValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;int32_t&nbsp;&amp;value)&nbsp;const; | 获取整数类型的元数据值 | 
| Format | bool&nbsp;GetLongValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;int64_t&nbsp;&amp;value)&nbsp;const; | 获取长整数类型的元数据值 | 
| Format | bool&nbsp;GetFloatValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;float&nbsp;&amp;value)&nbsp;const; | 获取单精度浮点类型的元数据值 | 
| Format | bool&nbsp;GetDoubleValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;double&nbsp;&amp;value)&nbsp;const; | 获取双精度浮点类型的元数据值 | 
| Format | bool&nbsp;GetStringValue(const&nbsp;std::string&nbsp;&amp;key,&nbsp;std::string&nbsp;&amp;value)&nbsp;const; | 获取字符串类型的元数据值 | 
| Format | const&nbsp;std::map&lt;std::string,&nbsp;FormatData&nbsp;\*&gt;&nbsp;&amp;GetFormatMap()&nbsp;const; | 获取元数据映射表 | 
| Format | bool&nbsp;CopyFrom(const&nbsp;Format&nbsp;&amp;format); | 用输入Format设置所有元数据 | 


## 约束与限制

输入源为音视频流时，不支持播放进度控制和获取文件时长。


## 开发步骤

1. 实现PlayerCallback回调，通过SetPlayerCallback函数进行绑定，用于事件处理。
     
   ```
   class TestPlayerCallback : public PlayerCallback{ 
       void OnPlaybackComplete() override 
       { 
           //此处实现代码用于处理文件播放完成的事件 
       } 
       void OnError(int32_t errorType, int32_t errorCode) override 
       { 
           //此处实现代码处理错误事件 
       } 
       void OnInfo(int type, int extra) override 
       { 
           //此处实现代码处理普通事件 
       } 
       void OnRewindToComplete() override 
       { 
           //此处实现代码处理进度控制完成的事件 
       } 
   };
   
   ```

2. 创建Player实例，设置播放源并开始播放。
     
   ```
   Player *player = new Player(); 
   std::shared_ptr<PlayerCallback> callback = std::make_shared<TestPlayerCallback>(); 
   player->SetPlayerCallback(callback);//设置player回调 
   std::string uri(filePath);//此处filePath为本地文件路径 
   Source source(uri);//保存uri到source实例 
   player->SetSource(source);//将source设置到player 
   player->Prepare();//准备播放 
   player->SetVideoSurface(surface);//设置播放窗口
   player->Play();//开始播放
   ```

3. 根据场景需要进行播放控制。
     
   ```
   player->SetVolume(lvolume, rvolume);//设置左右声道声音 
   player->EnableSingleLooping(true);//设置循环播放 
   player->Pause();//暂停 
   player->Play();//继续播放
   ```

4. 播放任务结束后，进行资源释放。
     
   ```
   player->Stop(); //停止播放
   player->Release();//释放资源
   ```
