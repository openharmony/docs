# 后台播放

实际应用中，大多数音视频都有后台播放的需求，本指南将详细讲解如何实现后台长时间播放的方法。

## 基本概念

开始之前，开发者应了解以下基本概念，以便根据自身播放器的类型，更有效地实现后台播放。

- 长时任务：请参考[长时任务(ArkTS)](../../task-management/continuous-task.md)说明。

  设备返回主界面、锁屏、应用切换等操作会使应用退至后台。当应用退至后台时，再继续活动，可能会出现设备耗电快、用户界面卡顿等问题。为了降低设备耗电速度、保障用户使用流畅度，系统会对退至后台的应用进行管控，包括进程挂起和进程终止。<br>
  当应用退至后台并需要长时间运行用户可感知的任务（如播放音乐、播放视频等）时。为防止应用进程被挂起，导致对应功能异常，可以申请长时任务，使应用在后台长时间运行。

- AVSession：请参考[AVSession Kit简介](../avsession/avsession-overview.md)。

  AVSession Kit（音视频播控服务）是系统提供的音视频管控服务，用于统一管理系统中音视频行为，帮助开发者快速构建音视频统一展示和控制能力。音视频类应用接入AVSession后，可以设置应用的数据（如正在播放的歌曲、歌曲的播放状态等）。用户可以通过系统播控中心来展示和控制不同应用的播放。AVSession会对后台的媒体播放有约束行为，所以通常来说，音频应用、听书类应用、视频应用等都需要接入AVSession。如果应用在没有创建AVSession的情况进行上述业务，系统会在检测到应用退至后台时，停止对应的音视频播放，以达到约束应用行为的目的。

- AVPlayer：参考[AVPlayer](../media/media-kit-intro.md#avplayer)说明。

  AVPlayer是一款功能强大的媒体播放器。使用AVPlayer可以实现端到端地播放多种音视频格式（如mp4、mp3、mkv、mpeg-ts等），开发者提供媒体源即可启动播放，无需关注复杂的解封装、解码处理。

- AudioRenderer：请参考[使用AudioRenderer开发音频播放功能](../audio/using-audiorenderer-for-playback.md)说明。

  AudioRenderer是音频渲染器，用于播放PCM（Pulse Code Modulation）音频数据。相比AVPlayer而言，AudioRenderer可以在输入前添加数据预处理，更适合有音频开发经验的开发者，以实现更灵活的播放功能。

## 应用接入规范

- 当应用需要在后台播放媒体类型（流类型为STREAM_USAGE_MUSIC、STREAM_USAGE_MOVIE和STREAM_USAGE_AUDIOBOOK）和游戏类型（流类型为STREAM_USAGE_GAME）时，必须接入AVSession和申请长时任务。流类型请参考[使用合适的音频流类型](../audio/using-right-streamusage-and-sourcetype.md)，长时任务支持的类型请参考[BackgroundMode](../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundmode)。

- 除了上述播放类型，当应用需要在后台长时间运行用户可感知的其他任务时，必须申请长时任务。

如果应用不满足上述接入规范，退至后台播放时会被系统静音并冻结，无法在后台正常播放。直到应用重新切回前台时，才会被解除静音并恢复播放。

## 开发步骤

音视频应用进行后台播放的基本步骤如下所示。

### 启动播放器

应用播放可以通过AudioRenderer、AVPlayer、其他第三方或自研的播放器来播放音视频。

- AudioRenderer：使用AudioRenderer创建播放音频流时应该注意使用合适的音频流类型。流类型的不同对音量控制、音频焦点管理以及输入/输出设备都具有决定性影响。详细内容请参考[使用合适的音频流类型](../audio/using-right-streamusage-and-sourcetype.md)。<br>
  同时需要注意正确处理音频焦点，系统预设了默认的音频焦点策略，根据音频流的类型及启动的先后顺序，对所有播放和录制音频流进行统一管理。在应用播放或录制音频的过程中，若有其他音频流申请焦点，系统会根据焦点策略进行焦点处理。若判定本音频流的焦点有变化，系统会自动执行一些必要操作（如暂停、继续、降低音量、恢复音量等），并通过音频焦点事件（InterruptEvent）通知应用。详细内容请参考[处理音频焦点变化](../audio/audio-playback-concurrency.md#处理音频焦点变化)。<br>
  开发指导请参考[使用AudioRenderer开发音频播放功能](../audio/using-audiorenderer-for-playback.md)。

- AVPlayer：使用AVPlayer可以实现端到端播放原始媒体资源。如果要实现后台播放或熄屏播放，需要接入AVSession和申请长时任务，避免播放被系统强制中断。[AVPlayer](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md)可通过audioInterruptMode属性设置焦点管理策略，该策略默认使用SHARE_MODE共享焦点模式。<br>
  开发指导请参考[使用AVPlayer播放音频(ArkTS)](../media/using-avplayer-for-playback.md)。

### 接入AVSession

当创建的音频流类型为STREAM_USAGE_MUSIC、STREAM_USAGE_MOVIE、STREAM_USAGE_AUDIOBOOK或STREAM_USAGE_GAME时，无论是将应用退至后台继续播放，还是在后台启动播放，都必须接入AVSession。<br>
关于AVSession的创建和释放时机，建议在应用启动或开始播放业务之前进行创建，并在应用进程结束或完全退出播放业务且不再播放时予以释放，以避免频繁创建和释放AVSession，从而保证应用播放业务的连续性和稳定性。应用后台播放时，需要确保AVSession对象实例在应用后台活动期间一直存在，避免被系统回收、释放，比如不要使用局部变量保存AVSession对象等。<br>
创建AVSession后，为了保证接入体验，要求设置以下元数据并注册以下控制命令。

- 元数据：标题、副标题/歌手、封面图。具体操作请参考[设置元数据](avsession-access-scene.md#设置元数据)。

- 注册控制命令：播放/暂停。具体操作请参考[注册控制命令](avsession-access-scene.md#注册控制命令)。

AVSession的接入开发请参考指南[应用接入AVSession场景介绍](avsession-access-scene.md)。

### 申请长时任务

在长时任务中可以申请多种类型的任务。例如：当后台播音的任务类型为AUDIO_PLAYBACK时，应用在后台播放音频、视频或通过AVSession投播组件投播，都可申请类型为AUDIO_PLAYBACK的长时任务。
- 播放时申请长时任务，如果应用明确有后台播放业务（例如：视频应用开启后台放音选项），可以在前台播放时申请长时任务。
- 暂停或停止时主动取消长时任务。（例如：用户主动点击音乐暂停播放时，应用需及时取消对应的长时任务；用户再次点击音乐播放时，需重新申请长时任务。）
- 若音频在后台播放时被打断（例如：焦点打断），系统会自行检测，冻结或者取消长时任务。当应用重启音频播放时，需要再次申请长时任务。
- 应用收到AVSession播控指令，收到音频设备变更等需要做出对应播放和暂停操作时，都需要在暂停时取消长时任务，播放时重新申请长时任务。
- 通过AVSession投播组件后台投播，开始投播时申请长时任务，断开投播时取消长时任务。投播过程中音频暂停，无须对长时任务做处理。

具体操作请参考长时任务(ArkTS)中的[开发步骤](../../task-management/continuous-task.md#开发步骤)。

### 监听前后台状态

如果应用本身没有后台播放业务，可以通过监听生命周期函数[onBackground](../../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onbackground)来判断应用是否已进入后台并主动停止播放。否则会受到AVSession与长时任务模块管控，对应用正常的播放业务造成影响。如需在应用回到前台时重启播放，可以通过监听生命周期函数[onForeground](../../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground)来判断应用是否回到前台。

## 完整示例

[使用AVPlayer后台播放](https://gitcode.com/harmonyos_samples/video-player)
- 本示例主要展示通过系统播放器AVPlayer实现视频类应用的开发，功能包括后台播放和系统播控中心的交互。

[使用AudioRenderer后台播放](https://gitcode.com/harmonyos_samples/audio-interaction)
- 本场景解决方案主要面向前台音频开发人员。指导开发者基于AudioRenderer开发音频播控功能。功能包括后台播放、系统播控中心的交互、适配不同类型的焦点打断策略、切换路由发声设备、切换输出设备等。