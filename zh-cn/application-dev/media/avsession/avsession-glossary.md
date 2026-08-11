# AVSession Kit术语
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

## A

### Audio & Video Session (AVSession)；媒体会话

音视频应用和音视频应用控制端之间进行信息交换的通道，一端连接被控的音视频应用，另一端连接音视频应用的控制端（如播控中心、语音助手等）。AVSession Kit的核心概念，用于实现音视频统一展示和控制能力。

### AVMetadata；媒体会话元数据

描述媒体数据相关属性的信息集合，包含媒体ID（assetId）、标题（title）、专辑作者（author）、专辑名称（album）、词作者（writer）、媒体时长（duration）、歌词（lyric）、媒体封面（mediaImage）、媒体音源标识（displayTags）等属性。媒体应用通过设置元数据在播控中心展示媒体相关信息。

### AVMusicTemplate；音频模板

用于描述音频模板相关能力的类，包含标识当前媒体会话的ID（sessionId）、会话标签（sessionTag）等属性，以及与播控中心进行数据交互的操作方法。媒体应用可通过音频模板向播控中心上报媒体相关信息及响应播控中心的操作指令，减少应用侧开发工作量。

### AVPlaybackState；媒体播放状态

描述媒体播放状态相关属性的信息集合，包含播放状态（state）、播放位置（position）、播放倍速（speed）、缓冲时间（bufferedTime）、循环模式（loopMode）、是否收藏（isFavorite）、正在播放的媒体ID（activeItemId）、自定义媒体数据（extras）等属性。用于在播控中心展示播放进度和控制状态。

### AVSessionController；媒体会话控制器

媒体会话控制方持有的对象，用于控制媒体会话提供方的应用播放行为，获取应用的播放信息，监听音视频应用播放状态的变化，确保媒体会话信息在音视频应用和播控中心之间的同步。

### AVSessionDescriptor；媒体会话描述符

描述媒体会话相关信息的对象，包含标识媒体会话的ID（sessionId）、媒体会话的类型（type）、媒体会话自定义名称（sessionTag）、媒体会话所属应用的信息（elementName）、是否为置顶会话（isTopSession）等属性。

### AVSessionManager；媒体会话管理器

提供媒体会话管理相关功能的模块，可以创建媒体会话（AVSession）、创建媒体会话控制器（AVSessionController）、发送系统控制事件，支持对媒体会话的状态进行监听。

### AVSessionType；媒体会话类型

定义媒体会话类型的参数，包括audio（音频会话）、video（视频会话）、voice_call（语音通话会话）、video_call（视频通话会话）、photo（图片会话）五种类型。不同类型决定了播控中心展示的控制模板样式。

## B

### BackgroundPlayMode；后台播放模式

用于标识应用退至后台时是否继续播放的模式，包含ENABLE_BACKGROUND_PLAY（支持后台播放）和DISABLE_BACKGROUND_PLAY（不支持后台播放）两种模式。系统根据该模式决定应用退后台时是否展示系统实况窗。

## D

### DisplayTag；媒体音源标识

标识媒体音源的标签，用于在播控中心展示媒体音频信息。目前支持TAG_AUDIO_VIVID，表示该音源是Audio Vivid。

## P

### ProtocolType；协议类型

远端设备支持的协议类型枚举，包括TYPE_LOCAL（本地设备）、TYPE_CAST_PLUS_STREAM（Cast+ Stream模式）、TYPE_DLNA（DLNA协议）、TYPE_CAST_PLUS_AUDIO（PCM模式）等协议类型。用于标识投播设备支持的通信协议。

## T

### TopSession；置顶会话

系统中优先级最高的媒体会话，例如当前处于正在播放状态的会话。媒体会话控制方可以在不用获取对应控制器的情况下，直接与置顶会话通信，例如直接向置顶会话发送播控命令和按键事件。