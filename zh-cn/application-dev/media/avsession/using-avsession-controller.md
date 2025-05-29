# 媒体会话控制方(仅对系统应用开放)

OpenHarmony系统预置的播控中心，作为媒体会话控制方与音视频应用进行交互，包括获取媒体信息进行展示以及下发播控命令等。

系统应用开发者也可以根据需要，按照本章节的内容自行开发一款新的系统应用（例如新开发一款播控中心或语音助手），作为媒体会话控制方的角色，与系统中的音视频应用进行交互。

## 基本概念

- 媒体会话描述符（AVSessionDescriptor）：描述媒体会话的相关信息，包含标识媒体会话的ID（sessionId），媒体会话的类型type（音频Audio/视频Video），媒体会话自定义名称（sessionTag），媒体会话所属应用的信息（elementName）、是否为置顶会话（isTopSession）等。

- 置顶会话（TopSession）：系统中优先级最高的媒体会话，例如当前处于正在播放状态的会话。一般来说，如果想与媒体会话通信，需要获取会话对应的控制器，而媒体会话控制方可以在不用获取对应控制器的情况下，直接与置顶会话通信，例如直接向置顶会话发送播控命令和按键事件。

## 接口说明

媒体会话控制方使用的关键接口包括两类：

1. 直接通过import得到的AVSessionManager来调用，例如接口`AVSessionManager.createController(sessionId)`。
2. 通过AVSessionController对象来调用，例如接口`controller.getAVPlaybackState()`。

异步的JavaScript接口返回值有两种返回形式：callback和promise，本说明仅提供callback形式接口，promise和callback只是返回值方式不一样，功能相同。

更多API说明请参见[API文档](../../reference/apis-avsession-kit/js-apis-avsession.md)。

### 直接通过AVSessionManager调用的接口

| 接口名 | 说明 | 
| -------- | -------- |
| getAllSessionDescriptors(callback: AsyncCallback&lt;Array&lt;Readonly&lt;AVSessionDescriptor&gt;&gt;&gt;): void | 获取系统中所有媒体会话的描述符。 | 
| createController(sessionId: string, callback: AsyncCallback&lt;AVSessionController&gt;): void | 创建媒体会话控制器。 | 
| sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback&lt;void&gt;): void | 向置顶会话发送按键命令。 |  
| sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback&lt;void&gt;): void | 向置顶会话发送播控命令。 | 
| getHistoricalSessionDescriptors(maxSize: number, callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void<sup>10+<sup> | 获取历史会话的描述符。 |

### 通过AVSessionController对象调用的接口

| 接口名 | 说明 |
| -------- | -------- |
| getAVPlaybackState(callback: AsyncCallback&lt;AVPlaybackState&gt;): void<sup>10+<sup> | 获取当前会话播放状态相关信息。 |
| getAVMetadata(callback: AsyncCallback&lt;AVMetadata&gt;): void<sup>10+<sup> | 获取会话元数据。 |
| getOutputDevice(callback: AsyncCallback&lt;OutputDeviceInfo&gt;): void<sup>10+<sup> | 获取播放设备信息。 |
| sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 发送按键事件到会话。|
| getLaunchAbility(callback: AsyncCallback&lt;WantAgent&gt;): void<sup>10+<sup> | 获取应用在会话中保存的WantAgent对象。 |
| isActive(callback: AsyncCallback&lt;boolean&gt;): void<sup>10+<sup> | 判断会话是否被激活。 |
| destroy(callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 销毁当前控制器，销毁后当前控制器不再可用。 |
| getValidCommands(callback: AsyncCallback&lt;Array&lt;AVControlCommandType&gt;&gt;): void<sup>10+<sup> | 获取会话支持的有效命令。 |
| sendControlCommand(command: AVControlCommand, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 通过会话控制器发送命令到其对应的会话。 |
| sendCommonCommand(command: string, args: {[key: string]: Object}, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 通过会话控制器发送自定义命令到其对应的会话。 |
| getAVQueueItems(callback: AsyncCallback&lt;Array&lt;AVQueueItem&gt;&gt;): void<sup>10+<sup> | 获取当前播放列表相关信息。 |
| getAVQueueTitle(callback: AsyncCallback&lt;string&gt;): void<sup>10+<sup> | 获取当前播放列表的名称。 |
| skipToQueueItem(itemId: number, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 设置指定播放列表单项的ID，发送给session端处理，session端可以选择对这个单项歌曲进行播放。 |
| getExtras(callback: AsyncCallback&lt;{[key: string]: Object}&gt;): void<sup>10+<sup> | 获取媒体提供方设置的自定义媒体数据包。 |
| getOutputDeviceSync(): OutputDeviceInfo<sup>10+<sup> | 使用同步方法获取当前输出设备信息。 |
| getAVPlaybackStateSync(): AVPlaybackState<sup>10+<sup> | 使用同步方法获取当前会话播放状态相关信息。 |
| getAVMetadataSync(): AVMetadata<sup>10+<sup> | 使用同步方法获取当前会话元数据信息。 |
| getAVQueueTitleSync(): string<sup>10+<sup> | 使用同步方法当前播放列表的名称。 |
| getAVQueueItemsSync(): Array&lt;AVQueueItem&gt;<sup>10+<sup> | 使用同步方法获取当前播放列表相关信息。 |
| isActiveSync(): boolean<sup>10+<sup> | 使用同步方法判断会话是否被激活。 |
| getValidCommandsSync(): Array&lt;AVControlCommandType&gt;<sup>10+<sup> | 使用同步方法获取会话支持的有效命令。 |

## 开发步骤

系统应用作为媒体会话控制方接入媒体会话的基本步骤如下所示：

1. 通过AVSessionManager获取媒体会话描述符AVSessionDescriptor，创建媒体会话控制器AVSessionController。
   媒体会话控制方可以获取当前系统中所有的AVSessionDescriptor，并创建每个会话对应的AVSessionController，从而对系统中的音视频应用进行统一的播放控制。

   ```ts
   //导入AVSessionManager模块。
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   // 全局变量定义。
   let g_controller = new Array<AVSessionManager.AVSessionController>();
   let g_centerSupportCmd:Set<AVSessionManager.AVControlCommandType> = new Set(['play', 'pause', 'playNext', 'playPrevious', 'fastForward', 'rewind', 'seek','setSpeed', 'setLoopMode', 'toggleFavorite']);
   let g_validCmd:Set<AVSessionManager.AVControlCommandType>;
   // 获取会话描述符，创建控制器。
   AVSessionManager.getAllSessionDescriptors().then((descriptors) => {
     descriptors.forEach((descriptor) => {
       AVSessionManager.createController(descriptor.sessionId).then((controller) => {
         g_controller.push(controller);
       }).catch((err: BusinessError) => {
         console.error(`Failed to create controller. Code: ${err.code}, message: ${err.message}`);
       });
     });
   }).catch((err: BusinessError) => {
     console.error(`Failed to get all session descriptors. Code: ${err.code}, message: ${err.message}`);
   });

   // 获取历史会话的描述符。
   AVSessionManager.getHistoricalSessionDescriptors().then((descriptors) => {
     console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
     if (descriptors.length > 0){
       console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
       console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
       console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
       console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionId : ${descriptors[0].sessionId}`);
       console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].elementName.bundleName : ${descriptors[0].elementName.bundleName}`);
     }
   }).catch((err: BusinessError) => {
     console.error(`Failed to get historical session descriptors, error code: ${err.code}, error message: ${err.message}`);
   });
   ```

2. 监听AVSession会话状态及AVSession服务状态事件。
   
   AVSession会话状态事件包括：

   - sessionCreate：媒体会话创建事件。
   - sessionDestroy：媒体会话销毁事件。
   - topSessionChange：置顶会话发生变化事件。

   AVSession服务状态事件指sessionServiceDie，在AVSession服务异常时产生该事件。

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let g_controller = new Array<AVSessionManager.AVSessionController>();
   // 注册会话创建监听，创建控制器。
   AVSessionManager.on('sessionCreate', (session) => {
     // 新增会话，需要创建控制器。
     AVSessionManager.createController(session.sessionId).then((controller) => {
       g_controller.push(controller);
     }).catch((err: BusinessError) => {
       console.error(`Failed to create controller. Code: ${err.code}, message: ${err.message}`);
     });
   });

   // 注册系统会话销毁监听。
   AVSessionManager.on('sessionDestroy', (session) => {
     let index = g_controller.findIndex((controller) => {
       return controller.sessionId === session.sessionId;
     });
     if (index !== 0) {
       g_controller[index].destroy();
       g_controller.splice(index, 1);
     }
   });
   // 注册系统最高优先级会话变更监听。
   AVSessionManager.on('topSessionChange', (session) => {
     let index = g_controller.findIndex((controller) => {
       return controller.sessionId === session.sessionId;
     });
     // 将该会话显示排到第一个。
     if (index !== 0) {
       g_controller.sort((a, b) => {
         return a.sessionId === session.sessionId ? -1 : 0;
       });
     }
   });
   // 注册服务异常监听。
   AVSessionManager.on('sessionServiceDie', () => {
     // 服务端异常，应用清理资源。
     console.info(`服务端异常`);
   })
   ```

3. 监听媒体信息变化及会话其他事件。
   
   AVSession媒体信息变化事件主要包括：

   - metadataChange：媒体会话元数据变化事件。
   - playbackStateChange：媒体播放状态变化事件。
   - activeStateChange：媒体会话激活状态变化事件。
   - validCommandChange：媒体会话支持的有效命令变化事件。
   - outputDeviceChange：播放设备变化事件。
   - sessionDestroy：媒体会话销毁事件。
   - sessionEvent：媒体会话自定义事件变化事件。
   - extrasChange：媒体会话自定义数据包变化事件。
   - queueItemsChange：媒体会话自定义播放列表变化事件。
   - queueTitleChange：媒体会话自定义播放列表的名称变化事件。

   媒体会话控制方可以根据实际需要监听对应的事件。

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let g_controller = new Array<AVSessionManager.AVSessionController>();
   let controller = g_controller[0];
   let g_validCmd:Set<AVSessionManager.AVControlCommandType>;
   let g_centerSupportCmd:Set<AVSessionManager.AVControlCommandType> = new Set(['play', 'pause', 'playNext', 'playPrevious', 'fastForward', 'rewind', 'seek','setSpeed', 'setLoopMode', 'toggleFavorite']);
   // 注册会话激活状态变更监听。
   controller.on('activeStateChange', (isActive) => {
     if (isActive) {
       console.info(`控制器卡片按键高亮`);
     } else {
       console.info(`控制器卡片按键变更为无效`);
     }
   });
   // 注册会话销毁监听。
   controller.on('sessionDestroy', () => {
     console.info(`on sessionDestroy : SUCCESS `);
     controller.destroy().then(() => {
       console.info(`destroy : SUCCESS`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to destroy session. Code: ${err.code}, message: ${err.message}`);
     });
   });

   // 注册元数据更新监听。
   controller.on('metadataChange', ['assetId', 'title', 'description'], (metadata: AVSessionManager.AVMetadata) => {
     console.info(`on metadataChange assetId : ${metadata.assetId}`);
   });
   // 注册播放状态更新监听。
   controller.on('playbackStateChange', ['state', 'speed', 'loopMode'], (playbackState: AVSessionManager.AVPlaybackState) => {
     console.info(`on playbackStateChange state : ${playbackState.state}`);
   });
   // 注册会话支持的命令变更监听。
   controller.on('validCommandChange', (cmds) => {
     console.info(`validCommandChange : SUCCESS : size : ${cmds.length}`);
     console.info(`validCommandChange : SUCCESS : cmds : ${cmds.values()}`);
     g_validCmd.clear();
     let centerSupportCmd = Array.from(g_centerSupportCmd.values())
     for (let c of centerSupportCmd) {
       if (cmds.concat(c)) {
         g_validCmd.add(c);
       }
     }
   });
   // 注册输出设备变更监听。
   controller.on('outputDeviceChange', (state, device) => {
     console.info(`outputDeviceChange device are : ${JSON.stringify(device)}`);
   });
   // 注册会话自定义事件变更监听。
   controller.on('sessionEvent', (eventName, eventArgs) => {
     console.info(`Received new session event, event name is ${eventName}, args are ${JSON.stringify(eventArgs)}`);
   });
   // 注册会话自定义媒体数据包变更监听。
   controller.on('extrasChange', (extras) => {
     console.info(`Received custom media packet, packet data is ${JSON.stringify(extras)}`);
   });
   // 注册会话自定义播放列表变更监听。
   controller.on('queueItemsChange', (items) => {
     console.info(`Caught queue items change, items length is ${items.length}`);
   });
   // 注册会话自定义播放标题变更监听。
   controller.on('queueTitleChange', (title) => {
     console.info(`Caught queue title change, title is ${title}`);
   });
   ```

4. 获取媒体会话提供方传递的媒体信息，可以用于界面展示，例如在播控中心展示当前播放的曲目及对应的播放状态。
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   async function getInfoFromSessionByController() {
     // 假设我们已经有了一个对应session的controller，如何创建controller可以参考之前的案例。
     let controller = await AVSessionManager.createController("");
     // 获取sessionId。
     let sessionId = controller.sessionId;
     console.info(`get sessionId by controller : isActive : ${sessionId}`);
     // 获取session激活状态。
     let isActive = await controller.isActive();
     console.info(`get activeState by controller : ${isActive}`);
     // 获取session的媒体信息。
     let metadata = await controller.getAVMetadata();
     console.info(`get media title by controller : ${metadata.title}`);
     console.info(`get media artist by controller : ${metadata.artist}`);
     // 获取session的播放信息。
     let avPlaybackState = await controller.getAVPlaybackState();
     console.info(`get playbackState by controller : ${avPlaybackState.state}`);
     console.info(`get favoriteState by controller : ${avPlaybackState.isFavorite}`);
     // 获取session的播放列表信息。
     let queueItems = await controller.getAVQueueItems();
     console.info(`get queueItems length by controller : ${queueItems.length}`);
     // 获取session的播放标题信息。
     let queueTitle = await controller.getAVQueueTitle();
     console.info(`get queueTitle by controller : ${queueTitle}`);
     // 获取session的自定义媒体数据包。
     let extras = await controller.getExtras();
     console.info(`get custom media packets by controller : ${JSON.stringify(extras)}`);
     // 获取session对应应用提供的ability信息。
     let agent = await controller.getLaunchAbility();
     console.info(`get want agent info by controller : ${JSON.stringify(agent)}`);
     // 获取session的当前播放位置信息。
     let currentTime = controller.getRealPlaybackPositionSync();
     console.info(`get current playback time by controller : ${currentTime}`);
     // 获取session支持的有效命令。
     let validCommands = await controller.getValidCommands();
     console.info(`get valid commands by controller : ${JSON.stringify(validCommands)}`);
   }
   ```

5. 控制媒体会话行为，例如发送用户在播控中心对当前曲目的操作（播放/暂停/上一首/下一首等）命令。
   
   作为媒体会话提供方的音视频应用在监听到相关的播控命令事件后，在相应的逻辑中可以完成对应的操作动作。

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   async function  sendCommandToSessionByController() {
     // 假设我们已经有了一个对应session的controller，如何创建controller可以参考之前的案例。
     let controller = await AVSessionManager.createController("");
     // 获取这个session支持的命令种类。
     let validCommandTypeArray = await controller.getValidCommands();
     console.info(`get validCommandArray by controller : length : ${validCommandTypeArray.length}`);
     // 下发播放命令。
     // 如果可用命令包含播放，则下发播放命令，正常session都应该提供并实现播放功能。
     if (validCommandTypeArray.indexOf('play') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'play'};
       controller.sendControlCommand(avCommand);
     }
     // 下发暂停命令。
     if (validCommandTypeArray.indexOf('pause') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'pause'};
       controller.sendControlCommand(avCommand);
     }
     // 下发上一首命令。
     if (validCommandTypeArray.indexOf('playPrevious') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'playPrevious'};
       controller.sendControlCommand(avCommand);
     }
     // 下发下一首命令。
     if (validCommandTypeArray.indexOf('playNext') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'playNext'};
       controller.sendControlCommand(avCommand);
     }
     // 下发自定义控制命令。
     let commandName = 'custom command';
     await controller.sendCommonCommand(commandName, {command : 'This is my custom command'}).then(() => {
       console.info(`SendCommonCommand successfully`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to send common command. Code: ${err.code}, message: ${err.message}`);
     })
     // 设置指定播放列表单项的ID，供session选择播放。
     let queueItemId = 0;
     await controller.skipToQueueItem(queueItemId).then(() => {
       console.info(`SkipToQueueItem successfully`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to skip to queue item. Code: ${err.code}, message: ${err.message}`);
     });
   }
   ```

6. 在媒体会话控制方应用退出时及时取消事件监听，并释放资源。
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   async function destroyController() {
     // 假设我们已经有了一个对应session的controller，如何创建controller可以参考之前的案例。
     let controller = await AVSessionManager.createController("");
     
     // 销毁当前的controller，销毁后这个controller将不在可用。
     controller.destroy((err: BusinessError) => {
       if (err) {
         console.error(`Failed to destroy controller. Code: ${err.code}, message: ${err.message}`);
       } else {
         console.info(`Destroy controller SUCCESS`);
       }
     });
   }
   ```

## 相关实例

针对媒体会话控制方开发，有以下相关实例可供参考：

- [媒体会话——控制方（仅对系统应用开放）（ArkTS）（Full SDK）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/AVSession/MediaController)