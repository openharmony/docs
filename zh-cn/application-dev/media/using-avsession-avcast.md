# 音视频投播开发

鸿蒙提供了统一的应用内音视频投播功能设计，通过提供投播组件和标准的接口，使得应用进行跨端投播音视频资源变得简单便捷。同时，系统默认支持Cast+协议，有效提升了投播体验。使用系统提供的投播组件和接口后，应用仅需要负责进行资源信息的设置，投播中部分状态的监听，以及应用主动控制的行为，如播放、暂停、切换资源等，其他动作包括图标切换，设备的发现、连接、认证等，都由系统统一负责完成。


## 基本概念

- 媒体会话(AVSession)：本地播放时用于进行媒体播放中的信息的更新和对系统播控中心的控制响应，[媒体会话提供方接入参考](using-avsession-developer.md)。 在投播时，AVSession用于在本地播放和投播之间切换的“枢纽”接口，把二者联系起来，即在本地播放时，如果接收到远端设备的连接状态，则应用感知到远端投播场景，进入到远端投播状态。通过AVSession可以进行应用投播能力的设置和查询，并进行投播控制器的创建。
- 投播组件[AVCastPicker](../reference/apis/js-apis-avcastpicker.md)：应用用于创建系统级的投播组件，嵌入在应用内界面，当用户点击后，由系统负责进行设备发现、连接、认证，应用只需要通过接口获取到投播中的状态回调。
- 投播控制器[AVCastController](../reference/apis/js-apis-avsession.md)：在投播后，由应用发起的对远端播放控制的接口，包括播放、暂停、调节音量、设置播放模式、设置播放速度等能力。
- 后台长时任务：进行投播时应用后台任务的申请，避免应用在投播后被系统后台清理或冻结。后台长时任务[开发参考](../task-management/continuous-task-dev-guide.md)。

## 接入说明

- 基本原则 

应用需要接入AVSession才可以使用系统提供的统一投播能力。系统不额外提供音视频设备发现的接口由应用选择和切换，需要通过系统提供的接口进行音视频的投播接入。

- 详细说明 

鸿蒙系统把本地播控和远端投播融合归一到AVSession中，体现了系统的统一设计。使用系统提供的统一投播组件，应用可以减少对设备发现连接的关注，而只需要关注连接设备是否在远端进行。当用户通过投播组件，选择了某个远端设备并连接成功，应用会通过回调接口获取到该设备连接成功的事件，然后可以创建一个“远端遥控器” AVCastController，从而实现对远端设备播放的控制操作。当进入到远端设备投播状态时，应用也可以对应用界面进行重新绘制，比如呈现遥控器状态。一个比较好的体验是，在进入远端投播时，本地的播放器最好停止，以防止本端和投播端设备同时播放的情形。

对于本端和远端设备的场景的区分，参考 AVCastCategory 的定义：

```ts
/**
 * The default cast type "local", media can be routed on the same device, 
 * including internal speakers or audio jacks on the device itself, A2DP devices.
 */
CATEGORY_LOCAL = 0,

/**
 * The remote category indicating the media is presenting on a different device
 * the application need get an AVCastController to control remote playback.
 */
CATEGORY_REMOTE = 1,
```

本次的投播能力和已有的分布式会话有什么关联和区别？

1. 分布式会话是基于分布式软总线的能力在双端设备之间进行会话信息的同步，投播能力基于Cast+的能力进行数据传输和信息同步，支持的设备类型更丰富；
2. 分布式会话投播音频投播成功后，远端无对应信息展示，仅有声音会传输到对端设备；而投播能力支持在远端设备进行播放的展示，体验上会更有优势；
2. 投播能力当前支持音频，长期会支持视频，这个是分布式会话不支持的；
3. 分布式会话能力长期会融入到投播能力中，由系统提供统一的接口包装，更容易接入和使用。

## 接口说明

接口返回值有两种返回形式：callback和promise，下表中为callback形式接口，promise和callback只是返回值方式不一样，功能相同。

### 投播组件接口

更多API说明请参见[API文档](../reference/apis/js-apis-avcastpicker.md)。

| 接口 | 说明 |
| --------  | -------- |
| AVCastPicker |投播组件的定义 |

### 投播相关的主要接口

更多API说明请参见[API文档](../reference/apis/js-apis-avsession.md)。

| 接口定义 |  说明 |
| -------- | -------- |
| getAVCastController(callback: AsyncCallback\<AVCastController\>): void; | 获取远端投播时的控制接口。|
| on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void;  | 注册设备变化的回调，同时包含了设备的连接状态。|
| sendControlCommand(command: AVCastControlCommand, callback: AsyncCallback\<void\>): void;  | 投播会话的控制接口，用于进行投播中的各种播控指令 |
| prepare(item: AVQueueItem, callback: AsyncCallback<void>): void | 准备播放，进行资源加载和缓冲，不会触发真正的播放 |
| start(item: AVQueueItem, callback: AsyncCallback<void>): void  | 开始播放媒体资源 |
| on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState\> \| 'all', callback: (state: AVPlaybackState) => void)  | 注册播放状态变化的回调 |
| on(type: 'mediaItemChange', callback: AsyncCallback\<AVQueueItem\>): void;  | 注册当前播放内容更新的回调，返回当前播放的内容的信息。|

Note:

*AVCastController由系统获取并返回，在设备连接成功后获取，在设备断开后不能继续使用，否则会抛出异常*


## 应用开发步骤

应用接入投播功能，分为如下几步：

1. 创建AVSession，既可以用于本地，也用于投播的实现
2. 在需要投播的播放界面绘制投播组件
3. 向AVSession注册设备投播过程状态的回调，感知投播连接
4. 通过AVSession获取投播控制器，进行投播中的播放控制
5. 投播启动后，应用需要进行长时任务的申请
6. 投播结束后，销毁过程对象

### 接入效果展示

![Cast Demo](figures/cast-demo.png)

### 应用接入示意

![Cast Interaction Diagram](figures/cast-interaction-diagram.png)

### 进入投播和远端控制响应

1. 创建播放器，并创建AVSession，通过AVSessionManager的方法创建并激活媒体会话。

```ts
import AVSessionManager from '@ohos.multimedia.avsession'; //导入AVSession模块

// 创建session
async createSession() {
    let session: AVSessionManager.AVSession = await AVSessionManager.createAVSession(this.context, 'SESSION_NAME', 'audio');
    session.activate();
    console.info(`session create done : sessionId : ${session.sessionId}`);
}
```

2. 在播放页面创建投播组件。

```ts
// 创建组件，并设置大小
build() {
  Row() {
    Column() {
      AVCastPicker()
        .width('40vp')
        .height('40vp')
        .border({ width: 1, color: Color.Red })
    }
  }
}
```

3. 设置AVSession的信息，注册AVSession的回调：

```ts
async setListenerFromController() {
  let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;

  // 对于应用来说，可以在每次更新资源的时候，设置设备过滤器，以通知系统进行设备选择界面的呈现
  // 如果应用不需要，或者不设置，系统会按照默认的设备策略进行展示
  // 设备过滤，一般是由应用根据播放的资源指定能够支持的投播设备
  // 通过extras 的 deviceFilter 设置设备过滤条件
  let extras = {
    deviceFilter: AVCastDeviceCategory.DEVICE_CAPABILITY_CAST_STREAM;
  }
  await session.setExtras(extras).then(() => {
    console.info(`Set extras successfully`);
  }).catch((err) => {
    console.error(`Failed to set extras. Code: ${err.code}, message: ${err.message}`);
  })

  // 监听设备连接状态的变化
  session.on("outputDeviceChange", (state, device) => {
    if (state == AVCastState.STATE_CONNECTED) { // 设备连接成功
      global.avcastcontroller = avsession.getAVCastController();
      console.info('get a cast controller successfully');
      console.info(`device connected ` + ${JSON.stringify(device)});

      // 设置播放参数，开始播放
      var playItem = {
        itemId: 0,
        description: {
          mediaId: '12345',
          mediaName: 'song1',
          mediaType: 'AUDIO',
          mediaUri: 'http://resource1_address',
          mediaSize: 12345,
          startPosition: 0,
          duration: 0,
          artist: 'mysong',
          albumTitle: 'song1_title',
          albumCoverUri: "http://resource1_album_address",
          lyricUri: "http://resource1_lyric_address",
          iconUri: "http://resource1_icon_address",
          appName: 'MyMusic'
        }
      };
      // 准备播放，这个不会触发真正的播放，会进行加载和缓冲
      global.avcastcontroller.prepare(playItem, () => {
        console.info('prepare done');
      });
      // 启动播放
      global.avcastcontroller.start(playItem, () => {
        console.info('play done');
      });

      // 列表里的第一首歌曲投播的时候，本端的Player要停止
      this.localplayer.stop();

      // 本端投播后的应用界面由应用进行专辑图、歌手等信息的刷新

      // 远端状态的回调，这个回调需要应用进行界面刷新，而不需要执行控制操作
      // 回调包括播放状态，播放位置，播放速度，播放模式等
      global.avcontroller.on('playbackStateChange', filter: 'all',  (state) => {
        console.info('playbackStateChange ' + state);
      });
      // 用于响应远端进行上一首、下一首
      global.avcontroller.on('playNext', () => {
        // 应用根据列表顺序，更新新的资源进行播放
        var nextPlayItem = {
          itemId: 2,
          description: {
            mediaId: '12345',
            mediaName: 'song2',
            mediaType: 'AUDIO',
            mediaUri: 'http://resource2_address',
            mediaSize: 12345,
            startPosition: 0,
            duration: 0,
            artist: 'mysong',
            albumTitle: 'song2_title',
            albumCoverUri: "http://resource2_album_address",
            lyricUri: "http://resource2_lyric_address",
            iconUri: "http://resource2_icon_address",
            appName: 'MyMusic'
          }
        };
        // 准备播放
        global.avcastcontroller.prepare(nextPlayItem, () => {
          console.info('prepare done');
        });
        // 启动播放
        global.avcastcontroller.start(nextPlayItem, () => {
          console.info('play done');
        });
      });
    }
  }

  // 可以通过getOutputDevice接口主动查询连接的设备
  session.getOutputDevice((device) => {
    console.info(`current routing device` + ${JSON.stringify(device)});
  });
}
```

4. 使用AVCastController进行应用内的播放控制：

```ts
async sendCommandToSessionByController() {
  // 记录从avsession获取的远端控制器
  // 下发播放命令
  let avCommand: AVSessionManager.AVCastControlCommand = {command:'play'};
  global.avcontroller.sendControlCommand(avCommand);

  // 下发暂停命令
  let avCommand: AVSessionManager.AVCastControlCommand = {command:'pause'};
  global.avcontroller.sendControlCommand(avCommand);

  // 播放、暂停等的操作，可以通过状态的回调接口获取到，然后进行本端界面的刷新
}
```

5. 申请投播长时任务，避免应用在投播进入后台时被系统冻结，导致无法持续投播

```ts
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';
import wantAgent from '@ohos.app.ability.wantAgent';

function startContinuousTask() {
    let wantAgentInfo = {
        // 点击通知后，将要执行的动作列表
        wants: [
          {
            bundleName: "com.example.myapplication",
            abilityName: "EntryAbility",
          }
        ],
        // 点击通知后，动作类型
        operationType: wantAgent.OperationType.START_ABILITY,
        // 使用者自定义的一个私有值
        requestCode: 0,
        // 点击通知后，动作执行属性
        wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    // 通过wantAgent模块的getWantAgent方法获取WantAgent对象
    try {
        wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
            try {
                backgroundTaskManager.startBackgroundRunning(mContext,
                    backgroundTaskManager.BackgroundMode.MULTI_DEVICE_CONNECTION, wantAgentObj).then(() => {
                    console.info("Operation succeeded");
                }).catch((error) => {
                    console.error(`Operation failed. code is ${error.code} message is ${error.message}`);
                });
            } catch (error) {
                console.error(`Operation failed. code is ${error.code} message is ${error.message}`);
            }
        });
    } catch (error) {
        console.error(`Operation getWantAgent failed. code is ${error.code} message is ${error.message}`);
    }
}
```

6. 音频焦点的处理

在应用进入投播后，当前应用需要去注册焦点处理，以免被其他应用的焦点申请而影响。
**当前投播支持全局切换，后续如果规格变更，再同步调整方案说明**

7. 结束投播

当远端设备断开的时候，应用会收到事件，系统会自动断开连接。

应用也可以使用断开投播的接口，主动进行投播连接的断开。

```ts
async release() {
  // 一般来说，应用退出时，而不希望继续投播，可以主动结束
  await global.avsession.stopCast();
}
```