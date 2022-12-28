# AVSession开发指导

## 会话接入端开发指导

### 基本概念
- 会话元数据`'AVMetadata'`: 媒体数据相关属性，包含标识当前媒体的ID(assetId)，上一首媒体的ID(previousAssetId)，下一首媒体的ID(nextAssetId)，标题(title)，专辑作者(author)，专辑名称(album)，词作者(writer)，媒体时长(duration)等属性。
- 会话描述符`'AVSessionDescriptor'`: 描述媒体会话的相关信息。包含标识会话的ID(sessionId)，会话的类型type(音频Audio/视频Video)，会话自定义名称(sessionTag)，会话所属应用的信息(elementName)等。
- 媒体播放状态`'AVPlaybackState'`：用于描述媒体播放状态的相关属性。包含当前媒体的播放状态(state)、位置(position)、速度(speed)、缓冲时间(bufferedTime)、循环模式(loopMode)、是否收藏(isFavorite)等属性。

### 接口说明
会话接入端常用接口如下表所示。接口返回值有两种返回形式：callback和promise，下表中为callback形式接口，promise和callback只是返回值方式不一样，功能相同。更多API说明请参见[API文档](../reference/apis/js-apis-avsession.md)。

表1：会话接入端常用接口

| 接口名                                                                              | 描述          |
|----------------------------------------------------------------------------------|-------------|
| createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void | 创建会话 |
| setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void            | 设置会话元数据     |
| setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void | 设置会话播放状态信息  |
| setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void       | 设置启动ability |
| getController(callback: AsyncCallback\<AVSessionController>): void                | 获取当前会话自身控制器 |
| getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void                 | 获取音频输出设备信息  |
| activate(callback: AsyncCallback\<void>): void                                    | 激活会话        |
| destroy(callback: AsyncCallback\<void>): void                                     | 销毁会话        |

### 开发步骤
1.导入模块接口

```js
import avSession from '@ohos.multimedia.avsession';
import wantAgent from '@ohos.wantAgent';
import featureAbility from '@ohos.ability.featureAbility';
```

2.创建会话并激活会话
```js
// 全局变量定义
let mediaFavorite = false;
let currentSession = null;
let context = featureAbility.getContext();
   
// 创建音频类型会话
avSession.createAVSession(context, "AudioAppSample", 'audio').then((session) => {
   currentSession = session;
   currentSession.activate();  // 激活会话
}).catch((err) => {
   console.info(`createAVSession : ERROR : ${err.message}`);
});
```

3.设置AVSession会话信息，包括：
- 设置会话元数据，除了媒体ID必选外，可选设置媒体标题、专辑信息、媒体作者、媒体时长、上一首/下一首媒体ID等。详细的会话元数据信息可参考API文档中的`AVMetadata`。
- 设置启动Ability，通过[WantAgent](../reference/apis/js-apis-app-ability-wantAgent.md)的接口实现。WantAgent一般用于封装行为意图信息。
- 设置播放状态。
```js
// 设置会话元数据
let metadata  = {
   assetId: "121278",
   title: "lose yourself",
   artist: "Eminem",
   author: "ST",
   album: "Slim shady",
   writer: "ST",
   composer: "ST",
   duration: 2222,
   mediaImage: "https://www.example.com/example.jpg",       // 请开发者根据实际情况使用
   subtitle: "8 Mile",
   description: "Rap",
   lyric: "https://www.example.com/example.lrc",            // 请开发者根据实际情况使用
   previousAssetId: "121277",
   nextAssetId: "121279",
};
currentSession.setAVMetadata(metadata).then(() => {
   console.info('setAVMetadata successfully');
}).catch((err) => {
   console.info(`setAVMetadata : ERROR : ${err.message}`);
});
```

```js
// 设置启动ability
let wantAgentInfo = {
  wants: [
    {
      bundleName: "com.neu.setResultOnAbilityResultTest1",
      abilityName: "com.example.test.MainAbility",
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
  currentSession.setLaunchAbility(agent).then(() => {
    console.info('setLaunchAbility successfully');
  }).catch((err) => {
    console.info(`setLaunchAbility : ERROR : ${err.message}`);
  });
});
```

```js
// 设置播放状态
let PlaybackState = {
  state: avSession.PlaybackState.PLAYBACK_STATE_STOP,
  speed: 1.0,
  position:{elapsedTime: 0, updateTime: (new Date()).getTime()},
  bufferedTime: 1000,
  loopMode: avSession.LoopMode.LOOP_MODE_SEQUENCE,
  isFavorite: false,
};
currentSession.setAVPlaybackState(PlaybackState).then(() => {
  console.info('setAVPlaybackState successfully');
}).catch((err) => {
  console.info(`setAVPlaybackState : ERROR : ${err.message}`);
});
```

```js
// 获取当前session会话对象自身的控制器
currentSession.getController().then((selfController) => {
   console.info('getController successfully');
}).catch((err) => {
   console.info(`getController : ERROR : ${err.message}`);
});
```

```js
// 获取音频输出设备信息
currentSession.getOutputDevice().then((outputInfo) => {
   console.info(`getOutputDevice successfully, deviceName : ${outputInfo.deviceName}`);
}).catch((err) => {
   console.info(`getOutputDevice : ERROR : ${err.message}`);
});
```

4.注册控制命令监听
```js
// 注册播放命令监听
currentSession.on('play', () => {
   console.log("调用AudioPlayer.play方法");
   // 设置播放状态
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_PLAY}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});


// 注册暂停命令监听
currentSession.on('pause', () => {
   console.log("调用AudioPlayer.pause方法");
   // 设置播放状态
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_PAUSE}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// 注册停止命令监听
currentSession.on('stop', () => {
   console.log("调用AudioPlayer.stop方法");
   // 设置播放状态
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_STOP}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// 注册下一首命令监听
currentSession.on('playNext', () => {
   // 如果媒体文件未准备好，则下载并缓存媒体文件，设置准备状态
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_PREPARE}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
   // 成功获取媒体文件
   currentSession.setAVMetadata({assetId: '58970105', title: '不如我们明天见'}).then(() => {
       console.info('setAVMetadata successfully');
   }).catch((err) => {
       console.info(`setAVMetadata : ERROR : ${err.message}`);
   });
   console.log("调用AudioPlayer.play方法");
   // 设置播放状态
   let time = (new Data()).getTime();
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_PLAY, position: {elapsedTime: 0, updateTime: time}, bufferedTime:2000}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// 注册播放快进命令监听
currentSession.on('fastForward', () => {
   console.log("调用AudioPlayer的倍速播放");
   // 设置播放状态
   currentSession.setAVPlaybackState({speed: 2.0}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// 注册跳播命令监听
currentSession.on('seek', (time) => {
   console.log("调用AudioPlayer的seek方法");
   // 设置播放状态
   currentSession.setAVPlaybackState({position: {elapsedTime: time, updateTime: (new Data()).getTime()}}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// 注册设置播放速度命令监听
currentSession.on('setSpeed', (speed) => {
   console.log(`调用AudioPlayer的倍速播放 ${speed}`);
   // 设置播放状态
   currentSession.setAVPlaybackState({speed: speed}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// 注册设置播放循环模式命令监听
currentSession.on('setLoopMode', (mode) => {
   console.log(`应用自身切换循环模式 ${mode}`);
   // 设置播放状态
   currentSession.setAVPlaybackState({loopMode: mode}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// 注册设置歌曲收藏命令监听
currentSession.on('toggleFavorite', (assetId) => {
   console.log(`应用保存当前assetId为喜爱 ${assetId}`);
   // 根据上一次的状态进行切换
   let favorite = mediaFavorite == false ? true : false;
   currentSession.setAVPlaybackState({isFavorite: favorite}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
   mediaFavorite = favorite;
});

// 注册媒体按键命令监听
currentSession.on('handleKeyEvent', (event) => {
   console.log(`用户按键 ${event.keyCode}`);
});

// 注册播放设备变化命令监听
currentSession.on('outputDeviceChange', (device) => {
   console.log(`输出设备变更,更新显示 ${device.deviceName}`);
});
```

5.释放资源
```js
// 取消注册回调
currentSession.off('play');
currentSession.off('pause');
currentSession.off('stop');
currentSession.off('playNext');
currentSession.off('playPrevious');
currentSession.off('fastForward');
currentSession.off('rewind');
currentSession.off('seek');
currentSession.off('setSpeed');
currentSession.off('setLoopMode');
currentSession.off('toggleFavorite');
currentSession.off('handleKeyEvent');
currentSession.off('outputDeviceChange');

// 去激活session并销毁对象
currentSession.deactivate().then(() => {
   currentSession.destory();
});
```

### 调测验证
在媒体应用上点击播放、暂停、下一首等按键，媒体播放状态出现相应变化。

### 常见问题

1.会话服务端异常
- 现象描述:

  会话服务端异常，应用端无法获取服务端的消息响应。如会话服务未运行或者会话服务通信失败。返回错误信息: Session service exception。
  
- 可能原因:
  
  会话重启过程中服务被杀。
  
- 解决办法

  (1)定时重试，超过3s仍失败时，停止对该会话或者控制器进行操作。
  
  (2)销毁当前会话或者会话控制器，并重新创建，如果重新创建失败，则停止会话相关操作。

2.会话不存在
- 现象描述:

  会话对象不存在时，向该会话设置参数或者发送命令。返回错误信息: The session does not exist。

- 可能原因:

  会话已被销毁，服务端无会话记录。

- 解决办法

  (1)如果在会话被控端产生该错误，请重新创建会话；如果是会话控制端，请停止向该会话发送查询或者控制命令。
  
  (2)如果在会话管理端产生该错误，请重新查询系统当前会话记录，在创建控制器时传入正确的会话ID。

3.会话未激活
- 现象描述:

  会话没有激活时，向会话发送控制命令或者事件。。返回错误信息: The session not active。

- 可能原因:

  会话处于未激活状态。

- 解决办法

  停止发送该命令或事件，监听会话的激活状态，会话激活后恢复发送该命令或事件。

### 相关实例
提供[音乐Demo](https://gitee.com/openharmony/multimedia_av_session/blob/master/test/resource/player_index_js.md)的代码实例

## 会话控制端开发指导（播控中心）

### 基本概念
- 远端投播：将本地媒体投播到远端设备，通过本地控制器发送命令，可控制远端播放行为。
- 发送按键命令：控制器通过发送按键事件的方式控制媒体。
- 发送控制命令：控制器通过发送控制命令的方式控制媒体。
- 发送系统按键命令：应用拥有调用该接口的系统权限，通过发送按键事件的方式控制媒体，仅系统应用可用。
- 发送系统控制命令：应用拥有调用该接口的系统权限，通过发送控制命令的方式控制媒体，仅系统应用可用。

### 接口说明

会话控制端涉及的常用接口如下表所示。接口返回值有两种返回形式：callback和promise，下表中为callback形式接口，promise和callback只是返回值方式不一样，功能相同。更多API说明请参见[API文档](../reference/apis/js-apis-avsession.md)。

表2：会话控制端常用接口

| 接口名                                                                                            | 描述               |
| ------------------------------------------------------------------------------------------------ | ----------------- |
| getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void    | 获取所有会话的描述符  |
| createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void          | 创建控制器          |
| sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void                            | 发送按键命令        |
| getLaunchAbility(callback: AsyncCallback\<WantAgent>): void                                      | 拉起应用           |
| sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void              | 发送控制命令        |
| sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void                       | 发送系统按键命令     |
| sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void         | 发送系统控制命令     |
| castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void | 远端投播 |

### 开发步骤
1.导入模块接口
```js
import avSession from '@ohos.multimedia.avsession';
import {Action, KeyEvent} from '@ohos.multimodalInput.KeyEvent';
import wantAgent from '@ohos.wantAgent';
import audio from '@ohos.multimedia.audio';
```

2.获取会话描述符，创建控制器
```js
// 全局变量定义
let g_controller = new Array<avSession.AVSessionController>();
let g_centerSupportCmd:Set<avSession.AVControlCommandType> = new Set(['play', 'pause', 'playNext', 'playPrevious', 'fastForward', 'rewind', 'seek','setSpeed', 'setLoopMode', 'toggleFavorite']);
let g_validCmd:Set<avSession.AVControlCommandType>;

// 获取会话描述符，创建控制器
avSession.getAllSessionDescriptors().then((descriptors) => {
   descriptors.forEach((descriptor) => {
       avSession.createController(descriptor.sessionId).then((controller) => {
           g_controller.push(controller);
       }).catch((err) => {
           console.error('createController error');
       });
   });
}).catch((err) => {
   console.error('getAllSessionDescriptors error');
});

// 注册会话创建监听，创建控制器
avSession.on('sessionCreate', (session) => {
  // 新增会话，需要创建控制器
  avSession.createController(session.sessionId).then((controller) => {
    g_controller.push(controller);
  }).catch((err) => {
    console.info(`createController : ERROR : ${err.message}`);
  });
});
```

3.监听AVSession会话状态以及AVSession服务变化
```js
// 注册会话激活状态变更监听
controller.on('activeStateChange', (isActive) => {
  if (isActive) {
    console.log("控制器卡片按键高亮");
  } else {
    console.log("控制器卡片按键变更为无效");
  }
});

// 注册会话销毁监听
controller.on('sessionDestroy', () => {
   console.info('on sessionDestroy : SUCCESS ');
   controller.destroy().then(() => {
       console.info('destroy : SUCCESS ');
   }).catch((err) => {
       console.info(`destroy : ERROR :${err.message}`);
   });
});

// 注册系统会话销毁监听
avSession.on('sessionDestroy', (session) => {
   let index = g_controller.findIndex((controller) => {
       return controller.sessionId == session.sessionId;
   });
   if (index != 0) {
       g_controller[index].destroy();
       g_controller.splice(index, 1);
   }
});

// 注册系统最高优先级会话变更监听
avSession.on('topSessionChange', (session) => {
   let index = g_controller.findIndex((controller) => {
       return controller.sessionId == session.sessionId;
   });
   // 将该会话显示排到第一个
   if (index != 0) {
       g_controller.sort((a, b) => {
           return a.sessionId == session.sessionId ? -1 : 0;
       });
   }
});

// 注册服务异常监听
avSession.on('sessionServiceDie', () => {
   // 服务端异常，应用清理资源
   console.log("服务端异常");
})
```

4.监听AVSession会话信息变化
```js
// 注册元数据更新监听
let metaFilter = ['assetId', 'title', 'description'];
controller.on('metadataChange', metaFilter, (metadata) => {
   console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

// 注册播放状态更新监听
let playbackFilter = ['state', 'speed', 'loopMode'];
controller.on('playbackStateChange', playbackFilter, (playbackState) => {
   console.info(`on playbackStateChange state : ${playbackState.state}`);
});

// 注册会话支持的命令变更监听
controller.on('validCommandChange', (cmds) => {
   console.info(`validCommandChange : SUCCESS : size : ${cmds.size}`);
   console.info(`validCommandChange : SUCCESS : cmds : ${cmds.values()}`);
   g_validCmd.clear();
   for (let c of g_centerSupportCmd) {
       if (cmds.has(c)) {
           g_validCmd.add(c);
       }
   }
});

// 注册输出设备变更监听
controller.on('outputDeviceChange', (device) => {
   console.info(`on outputDeviceChange device isRemote : ${device.isRemote}`);
});
```

5.控制AVSession会话行为
```js
// 用户点击播放按键:发送控制命令--播放
if (g_validCmd.has('play')) {
   controller.sendControlCommand({command:'play'}).then(() => {
       console.info('sendControlCommand successfully');
   }).catch((err) => {
       console.info(`sendControlCommand : ERROR : ${err.message}`);
   });
}

// 用户点击循环模式:发送控制命令--单曲循环
if (g_validCmd.has('setLoopMode')) {
   controller.sendControlCommand({command: 'setLoopMode', parameter: avSession.LoopMode.LOOP_MODE_SINGLE}).then(() => {
       console.info('sendControlCommand successfully');
   }).catch((err) => {
       console.info(`sendControlCommand : ERROR : ${err.message}`);
   });
}

// 发送按键事件
let keyItem = {code: 0x49, pressedTime: 123456789, deviceId: 0};
let event = {action: 2, key: keyItem, keys: [keyItem]};
controller.sendAVKeyEvent(event).then(() => {
   console.info('sendAVKeyEvent Successfully');
}).catch((err) => {
   console.info(`sendAVKeyEvent : ERROR : ${err.message}`);
});

// 用户点击卡片空白位置拉起应用
controller.getLaunchAbility().then((want) => {
   console.log("前台拉起应用");
}).catch((err) => {
   console.info(`getLaunchAbility : ERROR : ${err.message}`);
});

// 发送系统媒体按键事件
let keyItem = {code: 0x49, pressedTime: 123456789, deviceId: 0};
let event = {action: 2, key: keyItem, keys: [keyItem]};
avSession.sendSystemAVKeyEvent(event).then(() => {
   console.info('sendSystemAVKeyEvent Successfully');
}).catch((err) => {
   console.info(`sendSystemAVKeyEvent : ERROR : ${err.message}`);
});

// 发送系统控制命令，系统会把控制命令发送到Top会话中
let avcommand = {command: 'toggleFavorite', parameter: "false"};
avSession.sendSystemControlCommand(avcommand).then(() => {
   console.info('sendSystemControlCommand successfully');
}).catch((err) => {
   console.info(`sendSystemControlCommand : ERROR : ${err.message}`);
});

// 投播到其他设备
let audioManager = audio.getAudioManager();
let audioDevices;
await audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
   audioDevices = data;
   console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err) => {
   console.info(`getDevices : ERROR : ${err.message}`);
});

avSession.castAudio('all', audioDevices).then(() => {
   console.info('createController : SUCCESS');
}).catch((err) => {
   console.info(`createController : ERROR : ${err.message}`);
});
```

6.释放资源
```js
// 取消注册回调
 controller.off('metadataChange');
 controller.off('playbackStateChange');
 controller.off('sessionDestroy');
 controller.off('activeStateChange');
 controller.off('validCommandChange');
 controller.off('outputDeviceChange');
 
 // 销毁controller对象
 controller.destroy().then(() => {
     console.info('destroy : SUCCESS ');
 }).catch((err) => {
     console.info(`destroy : ERROR : ${err.message}`);
 });
```

### 调测验证
在播控中心点击播放、暂停、下一首等按键，应用播放状态随即发生相应变化。

### 常见问题
1.控制器不存在
- 现象描述:

  会话控制器不存在时，向该控制器发送控制命令或者事件。返回错误信息: The session controller does not exist。

- 可能原因:

  控制器已被销毁。

- 解决办法

  请重新查询系统当前会话记录，并创建对应的会话控制器。

2.远端会话连接失败
- 现象描述:

  本端会话与远端会话通信失败。返回错误信息: The remote session connection failed。

- 可能原因:

  设备间通信断开。

- 解决办法

  停止对该会话发送控制命令，并监听输出设备变化，当输出设备发送变化后恢复发送。

3.无效会话命令
- 现象描述:

  会话被控端不支持该被控命令或事件。返回错误信息: Invalid session command。

- 可能原因:

  被控端不支持该命令。

- 解决办法

  停止发送该命令或事件，并查询被控会话支持的命令集，发送被控端支持的命令。

4.消息过载
- 现象描述:

  会话客户端在一段时间内向服务端发送了过多的消息或者命令，引起服务端消息过载。返回错误信息: Command or event overload。

- 可能原因:

  服务端消息过载。

- 解决办法

  检查自身命令发送是否过于频繁，控制自身查询和控制命令的发送频度。

### 相关实例
提供[播控中心Demo](https://gitee.com/openharmony/multimedia_av_session/blob/master/test/resource/controller_index_js.md)的代码实例