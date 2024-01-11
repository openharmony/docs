# 应用接入AVSession场景介绍

音视频应用在实现音视频功能的同时，需要接入媒体会话即[AVSession Kit](../kit-readme/Readme-Avsession-Kit.md)，下文将提供一些典型的接入AVSession的展示和控制场景，方便开发者根据场景进行适配。

对于不同的场景，将会在系统的播控中心看到不同的UI呈现。同时，在不同的场景下，应用的接入处理也需要遵循不同的规范约束。

## 哪些场景下需要接入AVSession

AVSession会对后台的音频播放、VOIP通话做约束，所以通常来说，长音频应用、听书类应用、长视频应用、VOIP类应用等都需要接入AVSession。当应用在没有创建接入AVSession的情况下进行了上述业务，那么系统会在检测到应用后台时，停止对应的音频播放，静音通话声音，以达到约束应用行为的目的。这种约束，应用上架前在本地就可以验证。

对于其他使用到音频播放的应用，比如浏览器，游戏，直播等场景，接入AVSession不是必选项，只是可选，取决于应用是否有后台播放的使用诉求。若应用需要后台播放，那么接入AVSession仍然是必须的，否则业务的正常功能会受到限制。

当应用需要实现后台播放等功能时，需要使用[BackgroundTasks Kit](../task-management/background-task-overview.md)（后台任务管理）的能力，申请对应的长时任务，避免进入挂起（Suspend）状态。

## 接入流程

应用接入AVSession流程分为如下几个步骤，根据是否需要在播控中心展示，分为两种：

如果不需要在播控中心展示：

1. 确定应用需要创建的会话类型，[创建对应的会话](#创建不同类型的会话)，不同类型决定了播控中心展示的控制模板样式。
2. 按需[创建后台任务](#创建后台任务)。
3. 将[播放状态设置为PLAYBACK_STATE_STOP](#设置是否在播控中心展示)，不在系统播控中心显示。
4. 应用退出或者无对应业务时，注销会话。

如果需要在播控中心展示：

1. 确定应用需要创建的会话类型，[创建对应的会话](#创建不同类型的会话)，不同类型决定了播控中心展示的控制模板样式。
2. 按需[创建后台任务](#创建后台任务)。
3. [设置必要的元数据（Metadata）](#设置元数据)，以在播控中心展示响应的信息，包括不限于：当前媒体的ID（assetId），上一首媒体的ID（previousAssetId），下一首媒体的ID（nextAssetId），标题（title），专辑作者（author），专辑名称（album），词作者（writer），媒体时长（duration）等属性。
4. [设置播放相关的状态](#设置播放状态)，包括不限于：当前媒体的播放状态（state）、播放位置（position）、播放倍速（speed）、缓冲时间（bufferedTime）、循环模式（loopMode）、是否收藏（isFavorite）、正在播放的媒体Id（activeItemId）、自定义媒体数据（extras）等属性。
5. 按需[注册不同的控制命令](#注册控制命令)，包括不限于：播放/暂停、上下一首、快进快退、收藏、循环模式、进度条。
6. 应用退出或者无对应业务时，注销会话。

## 创建不同类型的会话

AVSession在构造方法中支持不同的类型参数，由 [AVSessionType](../reference/apis/js-apis-avsession.md#avsessiontype10) 定义，不同的类型代表了不同场景的控制能力，对于播控中心来说，会展示不同的控制模版。

- audio类型，播控中心的控制样式为：收藏，上一首，播放/暂停，下一首，循环模式。

- video类型，播控中心的控制样式为：快退，上一首，播放/暂停，下一首，快进。

- voice_all类型，播控中心的页面不做展示。

使用代码示例：

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';

  // 开始创建并激活媒体会话
  // 创建session
  let context: Context = getContext(this);
  async function createSession() {
  let type: AVSessionManager.AVSessionType = 'audio';
  let session = await AVSessionManager.createAVSession(context,'SESSION_NAME', type);
  await session.activate();
    console.info(`session create done : sessionId : ${session.sessionId}`);
  }
```

## 创建后台任务

当应用需要实现后台播放等功能时，需要使用[BackgroundTasks Kit](../task-management/background-task-overview.md)（后台任务管理）的能力，申请对应的长时任务，避免进入挂起（Suspend）状态。

对媒体类播放来说，需要申请[AUDIO_PLAYBACK BackgroundMode](../reference/apis/js-apis-resourceschedule-backgroundTaskManager.md#backgroundmode)的长时任务。

## 设置是否在播控中心展示

如果应用仅希望支持后台播放，但是又不希望在系统的播控中心展示，系统会提供如下的方式来支持，可以设置PLAYBACK_STATE_STOP状态，系统读到此状态，不会把应用的信息在播控中心的卡片进行展示。

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';

  let context: Context = getContext(this);
  async function setListener() {
    // 假设已经创建了一个session，如何创建session可以参考之前的案例
    let type: AVSessionManager.AVSessionType = 'audio';
    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

    // 设置 STOP 状态，那么即使avsession存在，播控中心也不再展示
    let playbackState: AVSessionManager.AVPlaybackState = {
      state: AVSessionManager.PlaybackState.PLAYBACK_STATE_STOP, // 播放状态为stop
    };
    session.setAVPlaybackState(playbackState, (err) => {
      if (err) {
        console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.info(`SetAVPlaybackState successfully`);
      }
    });
  }
```

## 设置元数据

### 通用元数据

应用可以通过setAVMetadata把会话的一些元数据信息设置给系统，从而在播控中心界面进行展示，包括不限制：当前媒体的ID（assetId），上一首媒体的ID（previousAssetId），下一首媒体的ID（nextAssetId），标题（title），专辑作者（author），专辑名称（album），词作者（writer），媒体时长（duration）等。

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';
  import { BusinessError } from '@ohos.base';

  let context: Context = getContext(this);
  async function setSessionInfo() {
    // 假设已经创建了一个session，如何创建session可以参考之前的案例
    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');
    // 设置必要的媒体信息
    let metadata: AVSessionManager.AVMetadata = {
      assetId: '0', // 由应用指定，用于标识应用媒体库里的媒体
      title: 'TITLE',
      artist: 'ARTIST'
    };
    session.setAVMetadata(metadata).then(() => {
      console.info(`SetAVMetadata successfully`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
    });
   }
```

### 歌词

对于长音频来说，播控中心提供了歌词的展示页面，对于应用来说，接入也比较简单，只需要把歌词内容设置给系统。播控中心会解析歌词内容，并根据播放进度进行同步的刷新。

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';

  let context: Context = getContext(this);
  async function setListener() {
    // 假设已经创建了一个session，如何创建session可以参考之前的案例
    let type: AVSessionManager.AVSessionType = 'audio';
    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

    // 把歌词信息设置给AVSession
    let metadata: AVSessionManager.AVMetadata = {
      assetId: '0',
      lyric: 'http://www.test.lyric',
    };
    session.setAVMetadata(metadata).then(() => {
      console.info(`SetAVMetadata successfully`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
    });

  }
```

### 历史歌单

历史歌单（播放列表）的接入，需要应用先接入意图框架支持MUSIC_PLAYBACK的能力（注册后台模式的PlayMusicList意图），并实现相应的意图调用接口，具体参考意图框架。
注册后台模式的PlayMusicList意图后，当系统启动历史歌单播放时，应用同样会在意图调用接口中获取到歌单的启动参数。

音乐类应用在播放内容时，可以通过setAVMetadata接口进行歌单的设置，歌单由这几个信息组成：

- avQueueName: 歌单的名称
- avQueueId: 歌单的唯一标识
- avQueueImage: 歌单的图片资源

当应用向系统设置歌单后，用户在播控中心界面操作后，可以针对歌单进行播放控制，系统会将歌单的唯一标识传回应用。

歌单启动播放后，应用内仍然通过AVSession的控制命令

需要注意的是：
1. 应用接入历史歌单，就相当于接入了系统后台冷启动播放。
2. 若应用只注册后台模式的PlayMusicList意图，但没有通过setAVMetadata设置歌单内容，请务必支持没有歌单唯一标识的PlayMusicList意图后台播放，系统后台冷启动会启动空歌单Id的歌单意图播放，由应用来决定播放内容。
3. 若应用注册后台模式的PlayMusicList意图，且通过setAVMetadata设置歌单内容，系统后台冷启动会启动对应歌单播放。

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';

  let context: Context = getContext(this);
  async function setListener() {
    // 假设已经创建了一个session，如何创建session可以参考之前的案例
    let type: AVSessionManager.AVSessionType = 'audio';
    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

    // 把歌单信息设置给AVSession
    let metadata: AVSessionManager.AVMetadata = {
      // 下面内容均由应用指定
      assetId: '0', 
      avQueueName: 'myQueue',
      avQueueId: 'myQueue123',
      avQueueImage: "PIXELMAP_OBJECT",
    };
    session.setAVMetadata(metadata).then(() => {
      console.info(`SetAVMetadata successfully`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
    });
    // 上报播放状态，参考播放状态
  }
```

## 设置播放状态

### 通用播放状态

应用可以通过[setAVPlaybackState](../reference/apis/js-apis-avsession.md#setavplaybackstate10)。把当前的播放状态设置给系统，以在播控中心界面进行展示。
播放状态一般是在资源播放后会进行变化的内容，包括：当前媒体的播放状态（state）、播放位置（position）、播放倍速（speed）、缓冲时间（bufferedTime）、循环模式（loopMode）、是否收藏（isFavorite）、正在播放的媒体Id（activeItemId）、自定义媒体数据（extras）等。

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';
  import { BusinessError } from '@ohos.base';

  let context: Context = getContext(this);
  async function setSessionInfo() {
    // 假设已经创建了一个session，如何创建session可以参考之前的案例
    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');
    // 播放器逻辑··· 引发媒体信息与播放状态的变更
     // 简单设置一个播放状态 - 暂停 未收藏
     let playbackState: AVSessionManager.AVPlaybackState = {
       state:AVSessionManager.PlaybackState.PLAYBACK_STATE_PAUSE,
       isFavorite:false
     };
     session.setAVPlaybackState(playbackState, (err) => {
       if (err) {
         console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
       } else {
         console.info(`SetAVPlaybackState successfully`);
       }
     });
   }
```

### 进度条

应用如果支持在播控中心展示进度，那么在媒体资源播放中，需要设置资源的时长、播放状态（暂停、播放）、播放位置、倍速，播控中心会使用这些信息进行进度的展示：

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';

  let context: Context = getContext(this);
  async function setListener() {
    // 假设已经创建了一个session，如何创建session可以参考之前的案例
    let type: AVSessionManager.AVSessionType = 'audio';
    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

    // 设置状态： 播放状态，进度位置，播放倍速，缓存的时间，资源的时长
    let playbackState: AVSessionManager.AVPlaybackState = {
      state: AVSessionManager.PlaybackState.PLAYBACK_STATE_PLAY, // 播放状态
      position: {
        elapsedTime: 1000, // 已经播放的位置，以ms为单位
        updateTime: 30000, // 应用更新当前位置的时间戳，以ms为单位
      }
      speed: 1.0, // 可选，默认是1.0，播放的倍速，按照应用内支持的speed进行设置，系统不做校验
      bufferedTime: 14000, // 可选，资源缓存的时间，以ms为单位
      duration: 23000, // 资源的时长，以ms为单位
    };
    session.setAVPlaybackState(playbackState, (err) => {
      if (err) {
        console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.info(`SetAVPlaybackState successfully`);
      }
    });
  }
```

系统的播控中心会根据应用设置的信息自行进行播放进度的计算，而不需要应用实时更新播放进度；
但是应用需要如下状态发生变化的时候，更新AVPlaybackState，否则系统会发生计算错误：

- playbackState
- speed

关于进度条有一些特殊情况需要处理：

1. 歌曲支持试听

    如果VIP歌曲支持试听，这样应用就不需要设置完整的歌曲时长，则只需要设置歌曲的试听时长。

2. 歌曲不支持试听

    如果歌曲不支持试听，那么理论上应用内也不支持播放，这时可以把 duration 设置为 -1，以通知系统不显示实际的时长。

3. 广告等内容的时长设置

    对于有前贴广告、后贴广告的资源来说，建议这么处理：
    - 播放广告时，单独设置广告的时长 duration
    - 当进入到正片播放的时候，则重新设置一次新的时长，以与广告进行区分。

## 注册控制命令

应用接入AVSession，可以通过注册不同的控制命令来实现播控中心界面上的控制操作，即通过on接口注册不同的控制命令参数，即可实现对应的功能。
具体的接口参考[接口注册](../reference/apis/js-apis-avsession.md#onplay10)。
> **说明：**
>
> 创建AVSession后，请先注册应用支持的控制命令，再激活 Session 

媒体资源支持的控制命令列表：

| 控制命令 | 功能说明   |
| ------  | -------------------------|
| play    | 播放命令。 |
| pause    | 暂停命令。 |
| stop    | 停止命令。 |
| playNex    | 播放下一首命令。 |
| playPrevious    | 播放上一首命令。 |
| fastForward    | 快进命令。 |
| rewind    | 快退命令。 |
| playFromAssetId    | 根据某个资源id进行播放命令。 |
| seek    | 跳转命令。 |
| setSpeed    | 设置播放速率命令。 |
| setLoopMode    | 设置循环模式命令。 |
| toggleFavorite    | 设置是否收藏命令。 |
| skipToQueueItem    | 设置播放列表其中某项被选中播放的命令。 |
| handleKeyEvent    | 设置按键事件的命令。 |
| commonCommand    | 设置自定义控制命令。 |

通话类应用支持的控制：

| 控制命令 | 功能说明   |
| ------  | -------------------------|
| answer    | 接听电话的命令。 |
| hangUp    | 通话挂断的命令。 |
| toggleCallMute    | 通话静音或解除静音的命令。 |

### 不支持命令的处理

系统支持的控制命令对于不支持的控制，比如应用不支持“上一首”的命令处理，只需要使用off 接口注销对应的控制命令，系统的播控中心会相应的对该控制界面进行置灰处理，以明确告知用户此控制命令不支持。

```ts
import AVSessionManager from '@ohos.multimedia.avsession';

let context: Context = getContext(this);
async function unregisterSessionListener() {
  // 假设已经创建了一个session，如何创建session可以参考之前的案例
  let type: AVSessionManager.AVSessionType = 'audio';
  let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

  // 取消指定session下的相关监听
  session.off('play');
  session.off('pause');
  session.off('stop');
  session.off('playNext');
  session.off('playPrevious');
}
```

### 快进快退

系统支持三种快进快退的时长，应用可以通过接口进行设置；同时注册快进快退的回调命令，以响应控制。

```ts
import AVSessionManager from '@ohos.multimedia.avsession';

let context: Context = getContext(this);
async function unregisterSessionListener() {
  // 假设已经创建了一个session，如何创建session可以参考之前的案例
  let type: AVSessionManager.AVSessionType = 'audio';
  let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

  // 设置支持的快进快退的时长设置给AVSession
  let metadata: AVSessionManager.AVMetadata = {
    assetId: '0', // 由应用指定，用于标识应用媒体库里的媒体
    skipIntervals: SkipIntervals.SECONDS_10,
  };
  session.setAVMetadata(metadata).then(() => {
    console.info(`SetAVMetadata successfully`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
  });

  session.on('fastForward', (time ?: number) => {
    console.info(`on fastForward , do fastForward task`);
    // do some tasks ···
  });
  session.on('rewind', (time ?: number) => {
    console.info(`on rewind , do rewind task`);
    // do some tasks ···
  });
}
```

### 收藏

音乐类应用实现收藏功能，那么需要注册收藏的控制响应[on('toggleFavorite')](../reference/apis/js-apis-avsession.md#ontogglefavorite10)。

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';

  let context: Context = getContext(this);
  async function setListener() {
    // 假设已经创建了一个session，如何创建session可以参考之前的案例
    let type: AVSessionManager.AVSessionType = 'audio';
    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
    session.on('toggleFavorite', (assetId) => {
      console.info(`on toggleFavorite `);
      // 应用收到收藏命令，进行收藏处理

      // 应用内完成或者取消收藏，把新的收藏状态设置给AVSession
      let playbackState: avSession.AVPlaybackState = {
        isFavorite:true,
      };
      session.setAVPlaybackState(playbackState).then(() => {
        console.info(`SetAVPlaybackState successfully`);
      }).catch((err: BusinessError) => {
        console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
      });

    });
  }
```

### 循环模式

针对音乐类应用，系统的播控中心界面会默认展示循环模式的控制操作，目前系统支持四种固定的循环模式控制，参考: [LoopMode](../reference/apis/js-apis-avsession.md#loopmode10)。

播控中心支持固定的四种循环模式的切换，即： 随机播放、顺序播放、单曲循环、列表循环。播控中心会按照固定的切换顺序通知应用，应用收到对应的循环模式命令后进行响应。

实现参考：

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';

  let context: Context = getContext(this);
  async function setListener() {
    // 假设已经创建了一个session，如何创建session可以参考之前的案例
    let type: AVSessionManager.AVSessionType = 'audio';
    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

    // 应用启动时，需要把应用内的循环模式设置给AVSession
    let metadata: AVSessionManager.AVMetadata = {
      assetId: '0', // 由应用指定，用于标识应用媒体库里的媒体
      loopMode: AVSessionManager.LoopMode.LOOP_MODE_SINGLE,
    };
    session.setAVMetadata(metadata).then(() => {
      console.info(`SetAVMetadata successfully`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
    });

    // 应用注册循环模式的控制监听
    session.on('setLoopMode', (mode) => {
      console.info(`on setLoopMode ${mode}`);
      // 应用收到收藏命令后，切换对应的循环模式
    });

  }
```

### 进度控制

应用如果支持进度显示，进一步也可以支持进度控制。应用需要响应seek的控制命令，那么当用户在播控中心的界面上进行拖动操作时，应用就会收到对应的回调。参考实现：

```ts
  import AVSessionManager from '@ohos.multimedia.avsession';

  let context: Context = getContext(this);
  async function setListener() {
    // 假设已经创建了一个session，如何创建session可以参考之前的案例
    let type: AVSessionManager.AVSessionType = 'audio';
    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

    session.on('seek', (time: number) => {
      console.info(`on seek , the time is ${JSON.stringify(time)}`);

      // 由于应用内seek可能会触发较长的缓冲等待，一般先把状态设置为 Buffering
      let playbackState: AVSessionManager.AVPlaybackState = {
        state: AVSessionManager.PlaybackState.PLAYBACK_STATE_BUFFERING, // 缓冲状态
      };
      session.setAVPlaybackState(playbackState, (err) => {
        if (err) {
          console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
        } else {
          console.info(`SetAVPlaybackState successfully`);
        }
      });

      // 应用响应seek命令，使用应用内播放器完成seek实现

      // 应用内更新新的位置后，也需要同步更新状态给系统
      playbackState.state = AVSessionManager.PlaybackState.PLAYBACK_STATE_PLAY; // 缓冲状态
      playbackState.position = {
        elapsedTime: 4000, // 已经播放的位置，以ms为单位
        updateTime: 34000, // 应用更新当前位置的时间戳，以ms为单位
      }
      session.setAVPlaybackState(playbackState, (err) => {
        if (err) {
          console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
        } else {
          console.info(`SetAVPlaybackState successfully`);
        }
      });

    });
  }
```

## 媒体通知的适配

当前系统不直接向应用提供主动发送媒体控制通知的接口，那么当应用进入播放状态时，系统会自动发送通知，同时在通知和锁屏界面进行展示。

> **说明：**
>
> 1. 目前仅audio类型的媒体会话会在通知入口展示，video类型暂时不支持展示。
> 2. 通知中心、锁屏下的播控卡片的展示，由系统进行发送，并控制相应的生命周期。
