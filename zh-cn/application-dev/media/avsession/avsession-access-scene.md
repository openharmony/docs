# 应用接入AVSession场景介绍

音视频应用在实现音视频功能的同时，需要接入媒体会话即AVSession Kit，下文将提供一些典型的接入AVSession的展示和控制场景，方便开发者根据场景进行适配。

对于不同的场景，将会在系统的播控中心看到不同的UI呈现。同时，在不同的场景下，应用的接入处理也需要遵循不同的规范约束。

## 哪些场景下需要接入AVSession

AVSession会对后台的音频播放、VOIP通话做约束，所以通常来说，长音频应用、听书类应用、长视频应用、VOIP类应用等都需要接入AVSession。当应用在没有创建接入AVSession的情况下进行了上述业务，那么系统会在检测到应用后台时，停止对应的音频播放，静音通话声音，以达到约束应用行为的目的。这种约束，应用上架前在本地就可以验证。

对于其他使用到音频播放的应用，比如游戏，直播等场景，接入AVSession不是必选项，只是可选，取决于应用是否有后台播放的使用诉求。若应用需要后台播放，那么接入AVSession仍然是必须的，否则业务的正常功能会受到限制。

当应用需要实现后台播放等功能时，需要使用[BackgroundTasks Kit](../../task-management/background-task-overview.md)（后台任务管理）的能力，申请对应的长时任务，避免进入挂起（Suspend）状态。

## 接入流程

应用接入AVSession流程分为如下几个步骤：

1. 确定应用需要创建的会话类型，[创建对应的会话](#创建不同类型的会话)，不同类型决定了播控中心展示的控制模板样式。
2. 按需[创建后台任务](#创建后台任务)。
3. [设置必要的元数据（Metadata）](#设置元数据)，以在播控中心展示响应的信息，包括不限于：当前媒体的ID（assetId），上一首媒体的ID（previousAssetId），下一首媒体的ID（nextAssetId），标题（title），专辑作者（author），专辑名称（album），词作者（writer），媒体时长（duration）等属性。
4. [设置播放相关的状态](#设置播放状态)，包括不限于：当前媒体的播放状态（state）、播放位置（position）、播放倍速（speed）、缓冲时间（bufferedTime）、循环模式（loopMode）、是否收藏（isFavorite）、正在播放的媒体Id（activeItemId）、自定义媒体数据（extras）等属性。
5. 按需[注册不同的控制命令](#注册控制命令)，包括不限于：播放/暂停、上下一首、快进快退、收藏、循环模式、进度条。
6. 应用退出或者无对应业务时，注销会话。

## 创建不同类型的会话

AVSession在构造方法中支持不同的类型参数，由 [AVSessionType](../../reference/apis-avsession-kit/js-apis-avsession.md#avsessiontype10) 定义，不同的类型代表了不同场景的控制能力，对于播控中心来说，会展示不同的控制模版。

- audio类型，播控中心的控制样式为：收藏，上一首，播放/暂停，下一首，循环模式。

- video类型，播控中心的控制样式为：快退，上一首，播放/暂停，下一首，快进。

- voice_call类型，通话类型。

使用代码示例：

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          // 开始创建并激活媒体会话。
          // 创建session。
          let context = this.getUIContext().getHostContext() as Context;
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
          // 激活接口要在元数据、控制命令注册完成之后再执行。
          await session.activate();
          console.info(`session create done : sessionId : ${session.sessionId}`);
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## 创建后台任务

当应用需要实现后台播放等功能时，需要使用[BackgroundTasks Kit](../../task-management/background-task-overview.md)（后台任务管理）的能力，申请对应的长时任务，避免进入挂起（Suspend）状态。

对媒体类播放来说，需要申请[AUDIO_PLAYBACK BackgroundMode](../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundmode)的长时任务。


## 设置元数据

### 通用元数据

应用可以通过setAVMetadata把会话的一些元数据信息设置给系统，从而在播控中心界面进行展示，包括不限制：当前媒体的ID（assetId），上一首媒体的ID（previousAssetId），下一首媒体的ID（nextAssetId），标题（title），专辑作者（author），专辑名称（album），词作者（writer），媒体时长（duration）等。

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');
          // 设置必要的媒体信息。
          let metadata: AVSessionManager.AVMetadata = {
            assetId: '0', // 由应用指定，用于标识应用媒体库里的媒体。
            title: 'TITLE',
            mediaImage: 'IMAGE',
            artist: 'ARTIST',
          };
          session.setAVMetadata(metadata).then(() => {
            console.info(`SetAVMetadata successfully`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### 歌词

对于长音频来说，播控中心提供了歌词的展示页面，对于应用来说，接入也比较简单，只需要把歌词内容设置给系统。播控中心会解析歌词内容，并根据播放进度进行同步的刷新。

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          // 把歌词信息设置给AVSession。
          let metadata: AVSessionManager.AVMetadata = {
            assetId: '0',
            title: 'TITLE',
            mediaImage: 'IMAGE',
            // LRC中有两类元素：一种是时间标签+歌词，一种是ID标签。
            // 例如：[00:25.44]xxx\r\n[00:26.44]xxx\r\n。
            lyric: "lrc格式歌词内容",
            // singleLyricText字段存储单条歌词文本，不包含时间戳。
            // 例如："单条歌词内容"。
            singleLyricText: "单条歌词内容",
          };
          session.setAVMetadata(metadata).then(() => {
            console.info(`SetAVMetadata successfully`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

<!--RP1-->
<!--RP1End-->

### 媒体资源金标

对于长音频，播控中心提供了媒体资源金标的展示，媒体资源金标又可称为应用媒体音频音源的标识，目前暂时只支持展示AudioVivid标识。
对于应用来说，接入只需要在AVMetadata中通知系统，当前播放音频的音源标识，播控就会同步展示。

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          // 把媒体音源信息设置给AVSession。
          let metadata: AVSessionManager.AVMetadata = {
            assetId: '0',
            title: 'TITLE',
            mediaImage: 'IMAGE',
            // 标识该媒体音源是AudioVivid。
            displayTags: AVSessionManager.DisplayTag.TAG_AUDIO_VIVID,
          };
          session.setAVMetadata(metadata).then(() => {
            console.info(`SetAVMetadata successfully`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## 设置播放状态

### 通用播放状态

应用可以通过[setAVPlaybackState](../../reference/apis-avsession-kit/js-apis-avsession.md#setavplaybackstate10)。把当前的播放状态设置给系统，以在播控中心界面进行展示。
播放状态一般是在资源播放后会进行变化的内容，包括：当前媒体的播放状态（state）、播放位置（position）、播放倍速（speed）、缓冲时间（bufferedTime）、循环模式（loopMode）、是否收藏（isFavorite）、正在播放的媒体Id（activeItemId）、自定义媒体数据（extras）等。

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');

          // 播放器逻辑··· 引发媒体信息与播放状态的变更。
          // 简单设置一个播放状态 - 暂停 未收藏。
          let playbackState: AVSessionManager.AVPlaybackState = {
            state: AVSessionManager.PlaybackState.PLAYBACK_STATE_PAUSE,
            isFavorite: false
          };
          session.setAVPlaybackState(playbackState, (err: BusinessError) => {
            if (err) {
              console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
            } else {
              console.info(`SetAVPlaybackState successfully`);
            }
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### 进度条

应用如果支持在播控中心展示进度，那么在媒体资源播放中，需要设置资源的时长、播放状态（暂停、播放）、播放位置、倍速，播控中心会使用这些信息进行进度的展示：

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          // 设置媒体资源时长。
          let metadata: AVSessionManager.AVMetadata = {
            assetId: '0',
            title: 'TITLE',
            mediaImage: 'IMAGE',
            duration: 23000, // 资源的时长，以ms为单位。
          };
          session.setAVMetadata(metadata).then(() => {
            console.info(`SetAVMetadata successfully`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
          });

          // 设置状态： 播放状态，进度位置，播放倍速，缓存的时间。
          let playbackState: AVSessionManager.AVPlaybackState = {
            state: AVSessionManager.PlaybackState.PLAYBACK_STATE_PLAY, // 播放状态。
            position: {
              elapsedTime: 1000, // 已经播放的位置，以ms为单位。
              updateTime: new Date().getTime(), // 应用更新当前位置时的时间戳，以ms为单位。
            },
            speed: 1.0, // 可选，默认是1.0，播放的倍速，按照应用内支持的speed进行设置，系统不做校验。
            bufferedTime: 14000, // 可选，资源缓存的时间，以ms为单位。
          };
          session.setAVPlaybackState(playbackState, (err) => {
            if (err) {
              console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
            } else {
              console.info(`SetAVPlaybackState successfully`);
            }
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

系统的播控中心会根据应用设置的信息自行进行播放进度的计算，而不需要应用实时更新播放进度；
但是应用需要如下状态发生变化的时候，再更新AVPlaybackState，否则系统会发生计算错误：

- state
- position
- speed

应用在真实播放开始时，再上报进度起始position；若播放存在buffer状态，可以先上报播放状态为AVSessionManager.PlaybackState.PLAYBACK_STATE_BUFFERING，来通知系统不刷新进度。

关于进度条有一些特殊情况需要处理：

1. 歌曲支持试听

    （1）应用不需要设置完整的歌曲时长，则只需要设置歌曲的试听时长。当应用仅设置歌曲的试听时长而不是完整时长，用户在播控中心触发进度控制时，应用收到的时长也是VIP试听时长内的相对时间戳位置，而不是完整歌曲的绝对时间戳位置，应用需要重新计算歌曲从零开始的绝对时间戳进行实际响应处理。
    
    （2）如果应用设置完整歌曲时长，但需要系统支持试听片段，也可以在播放时上报起始进度position，当收到的seek指令超过试听片段时，上报试听截止position，系统播控的进度会跟随回弹。

2. 歌曲不支持试听

    如果歌曲不支持试听，那么理论上应用内也不支持播放，这时可以把 duration 设置为 -1，以通知系统不显示实际的时长。

3. 广告等内容的时长设置

    对于有前贴广告、后贴广告的资源来说，建议这么处理：
    - 播放广告时，单独设置广告的时长 duration。
    - 当进入到正片播放的时候，则重新设置一次新的时长，以与广告进行区分。

## 注册控制命令

应用接入AVSession，可以通过注册不同的控制命令来实现播控中心界面上的控制操作，即通过on接口注册不同的控制命令参数，即可实现对应的功能。
具体的接口参考[接口注册](../../reference/apis-avsession-kit/js-apis-avsession.md#onplay10)。
> **说明：**
>
> 创建AVSession后，请先注册应用支持的控制命令，再激活 Session。 

媒体资源支持的控制命令列表：

| 控制命令 | 功能说明   |
| ------  | -------------------------|
| play    | 播放命令。 |
| pause    | 暂停命令。 |
| stop    | 停止命令。 |
| playNext    | 播放下一首命令。 |
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
import { avSession as AVSessionManager } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          // 取消指定session下的相关监听。
          session.off('play');
          session.off('pause');
          session.off('stop');
          session.off('playNext');
          session.off('playPrevious');
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### 快进快退

系统支持三种快进快退的时长，应用可以通过接口进行设置；同时注册快进快退的回调命令，以响应控制。

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          // 设置支持的快进快退的时长设置给AVSession。
          let metadata: AVSessionManager.AVMetadata = {
            assetId: '0', // 由应用指定，用于标识应用媒体库里的媒体。
            title: 'TITLE',
            mediaImage: 'IMAGE',
            skipIntervals: AVSessionManager.SkipIntervals.SECONDS_10,
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
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### 收藏

音乐类应用实现收藏功能，那么需要注册收藏的控制响应[on('toggleFavorite')](../../reference/apis-avsession-kit/js-apis-avsession.md#ontogglefavorite10)。

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
          session.on('toggleFavorite', (assetId) => {
            console.info(`on toggleFavorite `);
            // 应用收到收藏命令，进行收藏处理。

            // 应用内完成或者取消收藏，把新的收藏状态设置给AVSession。
            let playbackState: AVSessionManager.AVPlaybackState = {
              isFavorite: true,
            };
            session.setAVPlaybackState(playbackState).then(() => {
              console.info(`SetAVPlaybackState successfully`);
            }).catch((err: BusinessError) => {
              console.error(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
            });
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### 循环模式

针对音乐类应用，系统的播控中心界面会默认展示循环模式的控制操作，目前系统支持四种固定的循环模式控制，参考: [LoopMode](../../reference/apis-avsession-kit/js-apis-avsession.md#loopmode10)。

播控中心支持固定的四种循环模式的切换，即： 随机播放、顺序播放、单曲循环、列表循环。应用收到循环模式切换的指令并切换后，需要向系统上报切换后的LoopMode。
若应用内支持的LoopMode不在系统固定的四个循环模式内，需要选择四个固定循环模式其一向系统上报，由应用自定。

实现参考：

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          // 应用启动时/内部切换循环模式，需要把应用内的当前的循环模式设置给AVSession。
          let playBackState: AVSessionManager.AVPlaybackState = {
            loopMode: AVSessionManager.LoopMode.LOOP_MODE_SINGLE,
          };
          session.setAVPlaybackState(playBackState).then(() => {
            console.info(`set AVPlaybackState successfully`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
          });

          // 应用注册循环模式的控制监听。
          session.on('setLoopMode', (mode) => {
            console.info(`on setLoopMode ${mode}`);
            // 应用收到设置循环模式的指令后，应用自定下一个模式，切换完毕后通过AVPlaybackState上报切换后的LoopMode。
            let playBackState: AVSessionManager.AVPlaybackState = {
              loopMode: AVSessionManager.LoopMode.LOOP_MODE_SINGLE,
            };
            session.setAVPlaybackState(playBackState).then(() => {
              console.info(`set AVPlaybackState successfully`);
            }).catch((err: BusinessError) => {
              console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
            });
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### 进度控制

应用如果支持进度显示，进一步也可以支持进度控制。应用需要响应seek的控制命令，那么当用户在播控中心的界面上进行拖动操作时，应用就会收到对应的回调。参考实现：

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // 假设已经创建了一个session，如何创建session可以参考之前的案例。
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          session.on('seek', (position: number) => {
            console.info(`on seek , the time is ${JSON.stringify(position)}`);

            // 由于应用内seek可能会触发较长的缓冲等待，可以先把状态设置为 Buffering。
            let playbackState: AVSessionManager.AVPlaybackState = {
              state: AVSessionManager.PlaybackState.PLAYBACK_STATE_BUFFERING, // 缓冲状态。
            };
            session.setAVPlaybackState(playbackState, (err) => {
              if (err) {
                console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
              } else {
                console.info(`SetAVPlaybackState successfully`);
              }
            });

            // 应用响应seek命令，使用应用内播放器完成seek实现。

            // 应用内更新新的位置后，也需要同步更新状态给系统。
            playbackState.state = AVSessionManager.PlaybackState.PLAYBACK_STATE_PLAY; // 播放状态。
            playbackState.position = {
              elapsedTime: position, // 已经播放的位置，以ms为单位。
              updateTime: new Date().getTime(), // 应用更新当前位置的时间戳，以ms为单位。
            }
            session.setAVPlaybackState(playbackState, (err) => {
              if (err) {
                console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
              } else {
                console.info(`SetAVPlaybackState successfully`);
              }
            });
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## 适配媒体通知

当前系统不直接向应用提供主动发送媒体控制通知的接口，那么当应用正确接入媒体播控中心并进入播放状态时，系统会自动发送通知，同时在通知和锁屏界面进行展示。

> **说明：**
>
> 通知中心、锁屏下的播控卡片的展示，由系统进行发送，并控制相应的生命周期。

## 适配蓝牙按键与有线按键事件

当前系统不直接向应用提供监听多模按键事件的接口，应用如需要监听蓝牙与有线耳机的媒体按键事件，可以通过注册AVSession的控制指令来实现。AVSession提供了如下两种实现方式：
- 方式一（推荐使用）：
  按照应用业务需求，正确接入媒体播控中心，[注册需要的控制指令](#注册控制命令)并实现对应的功能。AVSession会监听多模按键事件，将其转换为AVSession的控制指令发送回应用。应用无须区分不同的按键事件，按照AVSession的回调处理即可。按照此方式接入播放暂停，也等同于适配了蓝牙耳机的佩戴检测，在双耳佩戴与摘下时也会收到如下播放暂停控制指令。目前支持转换的AVSession控制指令如下：
  | 控制命令 | 功能说明   |
  | ------  | -------------------------|
  | play    | 播放命令。 |
  | pause    | 暂停命令。 |
  | stop    | 停止命令。 |
  | playNext    | 播放下一首命令。 |
  | playPrevious    | 播放上一首命令。 |
  | fastForward    | 快进命令。 |
  | rewind    | 快退命令。 |

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
          // 设置必要的媒体信息，务必设置，否则接收不到控制事件。
          let metadata: AVSessionManager.AVMetadata = {
            assetId: '0', // 由应用指定，用于标识应用媒体库里的媒体。
            title: 'TITLE',
            mediaImage: 'IMAGE',
            artist: 'ARTIST'
          };
          session.setAVMetadata(metadata).then(() => {
            console.info(`SetAVMetadata successfully`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
          });
          // 一般在监听器中会对播放器做相应逻辑处理。
          // 不要忘记处理完后需要通过set接口同步播放相关信息，参考上面的用例。
          session.on('play', () => {
            console.info(`on play , do play task`);
            // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('play')取消监听。
            // 处理完毕后，请使用SetAVPlayState上报播放状态。
          });
          session.on('pause', () => {
            console.info(`on pause , do pause task`);
            // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('pause')取消监听。
            // 处理完毕后，请使用SetAVPlayState上报播放状态。
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

- 方式二：
  通过AVSession注册[HandleMediaKeyEvent](../../reference/apis-avsession-kit/js-apis-avsession.md#onhandlekeyevent10)指令。该回调接口会直接转发媒体按键事件[KeyEvent](../../reference/apis-input-kit/js-apis-keyevent.md)。应用需要自行识别按键事件的类型，并响应事件实现对应的功能。目前支持转发的按键事件类型如下：
  | 按键类型([KeyCode](../../reference/apis-input-kit/js-apis-keycode.md#keycode)) | 功能说明   |
  | ------  | -------------------------|
  | KEYCODE_MEDIA_PLAY_PAUSE    | 多媒体键：播放/暂停 |
  | KEYCODE_MEDIA_STOP    | 多媒体键：停止 |
  | KEYCODE_MEDIA_NEXT    | 多媒体键：下一首 |
  | KEYCODE_MEDIA_PREVIOUS    | 多媒体键：上一首 |
  | KEYCODE_MEDIA_REWIND    | 多媒体键：快退 |
  | KEYCODE_MEDIA_FAST_FORWARD    | 	多媒体键：快进 |
  | KEYCODE_MEDIA_PLAY    | 多媒体键：播放 |
  | KEYCODE_MEDIA_PAUSE   | 多媒体键：暂停|

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
          // 设置必要的媒体信息，务必设置，否则接收不到按键事件。
          let metadata: AVSessionManager.AVMetadata = {
            assetId: '0', // 由应用指定，用于标识应用媒体库里的媒体。
            title: 'TITLE',
            mediaImage: 'IMAGE',
            artist: 'ARTIST'
          };
          session.setAVMetadata(metadata).then(() => {
            console.info(`SetAVMetadata successfully`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
          });
          session.on('handleKeyEvent', (event) => {
            // 解析keycode，应用需要根据keycode对播放器做相应逻辑处理。
            console.info(`on handleKeyEvent, keyCode=${event.key.code}`);
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

> **说明：**
>
> 1. 方式一与方式二均需正确设置媒体信息AVMetadata并注册相应控制接口，否则会无法接收到控制指令与按键事件。
> 2. 方式一与方式二，选择其一接入即可，无须同时接入，系统推荐按照方式一接入。

<!--RP2-->
<!--RP2End-->