# 媒体会话提供方(C/C++)

OHAVSession系统提供的通过使用C API实现媒体会话提供方，从而在媒体会话控制方（例如播控中心）中展示媒体相关信息，及响应媒体会话控制方下发的播控命令。

## 使用入门

开发者要使用OHAVSession实现媒体会话，需要添加对应的头文件。

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(entry PUBLIC libohavsession.so)
```

### 添加头文件

```cpp
#include <multimedia/av_session/native_avmetadata.h>
#include <multimedia/av_session/native_avsession.h>
#include <multimedia/av_session/native_avsession_errors.h>
```

## 开发步骤及注意事项

开发者可以通过以下几个步骤在NDK接入本地会话。
1. 创建会话并激活媒体，需要传入会话类型`AVSession_Type`，自定义的TAG，以及应用的包名、ability名字。

   ```c++
   OH_AVSession* avsession;
   OH_AVSession_Create(SESSION_TYPE_AUDIO, "testsession", "com.example. application",   "MainAbility", &avsession);
   ```
 
   `AVSession_Type`包含如下四种类型：
 
   - SESSION_TYPE_AUDIO
   - SESSION_TYPE_VIDEO
   - SESSION_TYPE_VOICE_CALL 
   - SESSION_TYPE_VIDEO_CALL


2. 应用内播放对应的媒体资源时，同步设置媒体元数据信息。

   要设置元数据，要使用OH_AVMetadataBuilder构造具体的数据，最后生成一个 OH_AVMetadata。生成OH_AVMetadata后，使用OH_AVMetadata的各个功能接口进行资源的设置。
 
   使用OH_AVMetadataBuilder构造元数据示例：
 
   ```c++
   //创建OH_AVMetadataBuilder构造器
   OH_AVMetadataBuilder* builder;
   OH_AVMetadataBuilder_Create(&builder);
   
   OH_AVMetadata* ohMetadata;
   OH_AVMetadataBuilder_SetTitle(builder, "Anonymous title");
   OH_AVMetadataBuilder_SetArtist(builder, "Anonymous artist");
   OH_AVMetadataBuilder_SetAuthor(builder, "Anonymous author");
   OH_AVMetadataBuilder_SetAlbum(builder, "Anonymous album");
   OH_AVMetadataBuilder_SetWriter(builder, "Anonymous writer");
   OH_AVMetadataBuilder_SetComposer(builder, "Anonymous composer");
   OH_AVMetadataBuilder_SetDuration(builder, 3600);
   // MediaImageUri只支持网络地址。
   OH_AVMetadataBuilder_SetMediaImageUri(builder, "https://xxx.xxx.xx");
   OH_AVMetadataBuilder_SetSubtitle(builder, "Anonymous subtitle");
   OH_AVMetadataBuilder_SetDescription(builder, "For somebody");
   // Lyric只支持媒体歌词内容（应用需将歌词内容拼接为一个字符串传入）
   OH_AVMetadataBuilder_SetLyric(builder, "balabala");
   OH_AVMetadataBuilder_SetAssetId(builder, "000");
   OH_AVMetadataBuilder_SetSkipIntervals(builder, SECONDS_30);
   OH_AVMetadataBuilder_SetDisplayTags(builder,  AVSESSION_DISPLAYTAG_AUDIO_VIVID);
   
   /**
    * generate an AVMetadata 构造AVMetadata对象
    */
   OH_AVMetadataBuilder_GenerateAVMetadata(builder, &ohMetadata);
   ```
   
   在不使用AVMetadta之后，开发者应该执行OH_AVMetadataBuilder_Destroy接口来销毁元数 据，且不要继续使用。
   
   ```c++
   OH_AVMetadata_Destroy(ohMetadata);
   OH_AVMetadataBuilder_Destroy(builder);
   ```

3. 跟随媒体播放状态的变化，及时更新媒体播放状态。

   媒体播放状态，包含状态值、播放位置、播放速度、收藏状态等，可以按需使用对应的接口进行 设置。
   
   ```c++
   AVSession_ErrCode ret = AV_SESSION_ERR_SUCCESS;
   
   // 设置播放状态，其中state范围应为[0,11]
   AVSession_PlaybackState state = PLAYBACK_STATE_PREPARING;
   ret = OH_AVSession_SetPlaybackState(avsession, state);
   
   // 设置播放位置
   AVSession_PlaybackPosition* playbackPosition = new  AVSession_PlaybackPosition;
   playbackPosition->elapsedTime = 1000;
   playbackPosition->updateTime = 16111150;
   ret = OH_AVSession_SetPlaybackPosition(avsession, playbackPosition);
   ```

4. 注册播控命令事件监听，便于响应用户通过媒体会话控制方，例如播控中心下发的播控命令。

   > **说明：**
   >
   > 媒体会话提供方在注册相关固定播控命令事件监听时，监听的事件会在媒体会话控制方的getValidCommands()方法中体现，即  体会话控制方会认为对应的方法有效，进而根据需要触发相应暂不使用时的事件。为了 保证媒体会话控制方下发的播控命令可以被正常执行，媒体会话提供方请勿进行无逻辑的空实现监听。
 
   Session侧目前支持的播控命令包括：
   - 播放
   - 暂停
   - 停止
   - 上一首
   - 下一首
   - 快退
   - 快进
   - 设置进度
   - 设置收藏
   
   ```c++
   // 设置播放/暂停/停止/上一首/下一首回调.
   // CONTROL_CMD_PLAY = 0; 播放
   // CONTROL_CMD_PAUSE = 1; 暂停
   // CONTROL_CMD_STOP = 2;  停止
   // CONTROL_CMD_PLAY_NEXT = 3; 上一首
   // CONTROL_CMD_PLAY_PREVIOUS = 4; 下一首
   AVSession_ControlCommand command = CONTROL_CMD_PLAY;
   OH_AVSessionCallback_OnCommand commandCallback = [](OH_AVSession* session, AVSession_ControlCommand command,
       void* userData) -> AVSessionCallback_Result
   {
       return AVSESSION_CALLBACK_RESULT_SUCCESS;
   };
   OH_AVSession_RegisterCommandCallback(avsession, command, commandCallback, (void *)(&userData));
   
   //设置快进回调
   OH_AVSessionCallback_OnFastForward fastForwardCallback = [](OH_AVSession* session, uint32_t seekTime,
       void* userData) -> AVSessionCallback_Result
   {
       return AVSESSION_CALLBACK_RESULT_SUCCESS;
   };
   OH_AVSession_RegisterForwardCallback(avsession, fastForwardCallback, (void *)(&userData));
   ```
   相关回调接口如下：
  
   | 接口                                                         | 说明         |
   | ------------------------------------------------------------ | ------------ |
   |OH_AVSession_RegisterCommandCallback(OH_AVSession* avsession, AVSession_ControlCommand   command, OH_AVSessionCallback_OnCommand callback, void* userData);| 注册通用播控的回调，支持：播  放、暂停、停止、上一首、下一首回调。     |
   |OH_AVSession_RegisterForwardCallback(OH_AVSession* avsession,   OH_AVSessionCallback_OnFastForward callback, void* userData); | 注册快进的回调。   |
   |OH_AVSession_RegisterRewindCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnRewind   callback, void* userData); | 注册快退的回调。     |
   |OH_AVSession_RegisterSeekCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSeek   callback, void* userData); | 注册跳转的回调。  |
   |OH_AVSession_RegisterToggleFavoriteCallback(OH_AVSession* avsession,   OH_AVSessionCallback_OnToggleFavorite callback, void* userData)| 注册收藏的回调。  |
5. 音视频应用在退出，并且不需要继续播放时，及时取消监听以及销毁媒体会话释放资源。示例代码如下所示 ：
 
   ```c++
   OH_AVSession_Destroy(avsession);
   ```

## 相关实例

针对媒体会话提供方的NDK开发，有以下相关实例可供参考：

- [媒体会话——提供方（C/C++）（API13）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.1-Release/code/BasicFeature/Media/AVSession/MediaProvider)
