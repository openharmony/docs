# 媒体会话控制方

OpenHarmony系统预置的播控中心，作为媒体会话控制方与音视频应用进行交互，包括获取媒体信息进行展示以及下发播控命令等。

系统应用开发者也可以根据需要，按照本章节的内容自行开发一款新的系统应用（例如新开发一款播控中心或语音助手），作为媒体会话控制方的角色，与系统中的音视频应用进行交互。

## 基本概念

- 媒体会话描述符（AVSessionDescriptor）：描述媒体会话的相关信息，包含标识媒体会话的ID（sessionId），媒体会话的类型type（音频Audio/视频Video），媒体会话自定义名称（sessionTag），媒体会话所属应用的信息（elementName）、是否为置顶会话（isTopSession）等。

- 置顶会话（TopSession）：系统中优先级最高的媒体会话，例如当前处于正在播放状态的会话。一般来说，如果想与媒体会话通信，需要获取会话对应的控制器，而媒体会话控制方可以在不用获取对应控制器的情况下，直接与置顶会话通信，例如直接向置顶会话发送播控命令和按键事件。

## 接口说明

媒体会话控制方使用的关键接口如下表所示。接口返回值有两种返回形式：callback和promise，下表中为callback形式接口，promise和callback只是返回值方式不一样，功能相同。

更多API说明请参见[API文档](../reference/apis/js-apis-avsession.md)。

| 接口名 | 说明 | 
| -------- | -------- |
| getAllSessionDescriptors(callback: AsyncCallback&lt;Array&lt;Readonly&lt;AVSessionDescriptor&gt;&gt;&gt;): void | 获取系统中所有媒体会话的描述符。 | 
| createController(sessionId: string, callback: AsyncCallback&lt;AVSessionController&gt;): void | 创建媒体会话控制器。 | 
| getValidCommands(callback: AsyncCallback&lt;Array&lt;AVControlCommandType&gt;&gt;): void | 获取媒体会话支持的有效命令。<br/>音视频应用在接入媒体会话时监听的播控命令，即为媒体会话支持的有效命令，相关信息请参见[媒体会话提供方监听播控命令事件](using-avsession-developer.md)。 | 
| getLaunchAbility(callback: AsyncCallback&lt;WantAgent&gt;): void | 获取媒体会话中配置的可被拉起的UIAbility。<br/>当用户在媒体会话控制方应用进行界面操作，例如点击了播控中心卡片后，可以拉起对应的应用。 | 
| sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback&lt;void&gt;): void | 通过会话对应的AVSessionController向会话发送按键命令。 | 
| sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback&lt;void&gt;): void | 向置顶会话发送按键命令。 | 
| sendControlCommand(command: AVControlCommand, callback: AsyncCallback&lt;void&gt;): void | 通过会话对应的AVSessionController向会话发送播控命令。 | 
| sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback&lt;void&gt;): void | 向置顶会话发送播控命令。 | 

## 开发步骤

系统应用作为媒体会话控制方接入媒体会话的基本步骤如下所示：

1. 通过AVSessionManager获取媒体会话描述符AVSessionDescriptor，创建媒体会话控制器AVSessionController。
   媒体会话控制方可以获取当前系统中所有的AVSessionDescriptor，并创建每个会话对应的AVSessionController，从而对系统中的音视频应用进行统一的播放控制。

   ```ts
   //导入AVSessionManager模块
   import AVSessionManager from '@ohos.multimedia.avsession'; 
   
   // 全局变量定义
   let g_controller = new Array<AVSessionManager.AVSessionController>();
   let g_centerSupportCmd:Set<AVSessionManager.AVControlCommandType> = new Set(['play', 'pause', 'playNext', 'playPrevious', 'fastForward', 'rewind', 'seek','setSpeed', 'setLoopMode', 'toggleFavorite']);
   let g_validCmd:Set<AVSessionManager.AVControlCommandType>;
   // 获取会话描述符，创建控制器
   AVSessionManager.getAllSessionDescriptors().then((descriptors) => {
      descriptors.forEach((descriptor) => {
          AVSessionManager.createController(descriptor.sessionId).then((controller) => {
              g_controller.push(controller);
          }).catch((err) => {
              console.error(`createController : ERROR : ${err.message}`);
          });
      });
   }).catch((err) => {
      console.error(`getAllSessionDescriptors : ERROR : ${err.message}`);
   });
   
   ```

2. 监听AVSession会话状态及AVSession服务状态事件。
   
   AVSession会话状态事件包括：

   - sessionCreate：媒体会话创建事件。
   - sessionDestroy：媒体会话销毁事件。
   - topSessionChange：置顶会话发生变化事件。

   AVSession服务状态事件指sessionServiceDie，在AVSession服务异常时产生该事件。

   ```ts
   // 注册会话创建监听，创建控制器
   AVSessionManager.on('sessionCreate', (session) => {
     // 新增会话，需要创建控制器
     AVSessionManager.createController(session.sessionId).then((controller) => {
       g_controller.push(controller);
     }).catch((err) => {
       console.info(`createController : ERROR : ${err.message}`);
     });
   });
   
   // 注册系统会话销毁监听
   AVSessionManager.on('sessionDestroy', (session) => {
      let index = g_controller.findIndex((controller) => {
          return controller.sessionId === session.sessionId;
      });
      if (index !== 0) {
          g_controller[index].destroy();
          g_controller.splice(index, 1);
      }
   });
   // 注册系统最高优先级会话变更监听
   AVSessionManager.on('topSessionChange', (session) => {
      let index = g_controller.findIndex((controller) => {
          return controller.sessionId === session.sessionId;
      });
      // 将该会话显示排到第一个
      if (index !== 0) {
          g_controller.sort((a, b) => {
              return a.sessionId === session.sessionId ? -1 : 0;
          });
      }
   });
   // 注册服务异常监听
   AVSessionManager.on('sessionServiceDie', () => {
      // 服务端异常，应用清理资源
      console.info("服务端异常");
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

   媒体会话控制方可以根据实际需要监听对应的事件。

   ```ts
   // 注册会话激活状态变更监听
   controller.on('activeStateChange', (isActive) => {
     if (isActive) {
       console.info("控制器卡片按键高亮");
     } else {
       console.info("控制器卡片按键变更为无效");
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

4. 获取媒体会话提供方传递的媒体信息，可以用于界面展示，例如在播控中心展示当前播放的曲目及对应的播放状态。
     
   ```ts
   async getInfoFromSessionByController() {
     // 假设我们已经有了一个对应session的controller，如何创建controller可以参考之前的案例
     let controller: AVSessionManager.AVSessionController = ALLREADY_HAVE_A_CONTROLLER;
     // 获取sessionId
     let sessionId: string = controller.sessionId;
     console.info(`get sessionId by controller : isActive : ${sessionId}`);
     // 获取session激活状态
     let isActive: boolean = await controller.isActive();
     console.info(`get activeState by controller : ${isActive}`);
     // 获取session的媒体信息
     let metadata: AVSessionManager.AVMetadata = await controller.getAVMetadata();
     console.info(`get media title by controller : ${metadata.title}`);
     console.info(`get media artist by controller : ${metadata.artist}`);
     // 获取session的播放信息
     let avPlaybackState: AVSessionManager.AVPlaybackState = await controller.getAVPlaybackState();
     console.info(`get playbackState by controller : ${avPlaybackState.state}`);
     console.info(`get favoriteState by controller : ${avPlaybackState.isFavorite}`);
   }
   ```

5. 控制媒体会话行为，例如发送用户在播控中心对当前曲目的操作（播放/暂停/上一首/下一首等）命令。
   
   作为媒体会话提供方的音视频应用在监听到相关的播控命令事件后，在相应的逻辑中可以完成对应的操作动作。

     
   ```ts
   async sendCommandToSessionByController() {
     // 假设我们已经有了一个对应session的controller，如何创建controller可以参考之前的案例
     let controller: AVSessionManager.AVSessionController = ALLREADY_HAVE_A_CONTROLLER;
     // 获取这个session支持的命令种类
     let validCommandTypeArray: Array<AVSessionManager.AVControlCommandType> = await controller.getValidCommands();
     console.info(`get validCommandArray by controller : length : ${validCommandTypeArray.length}`);
     // 下发播放命令
     // 如果可用命令包含播放，则下发播放命令，正常session都应该提供并实现播放功能
     if (validCommandTypeArray.indexOf('play') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'play'};
       controller.sendControlCommand(avCommand);
     }
     // 下发暂停命令
     if (validCommandTypeArray.indexOf('pause') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'pause'};
       controller.sendControlCommand(avCommand);
     }
     // 下发上一首命令
     if (validCommandTypeArray.indexOf('playPrevious') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'playPrevious'};
       controller.sendControlCommand(avCommand);
     }
     // 下发下一首命令
     if (validCommandTypeArray.indexOf('playNext') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'playNext'};
       controller.sendControlCommand(avCommand);
     }
   }
   ```

6. 在媒体会话控制方应用退出时及时取消事件监听，并释放资源。
     
   ```ts
   async destroyController() {
     // 假设我们已经有了一个对应session的controller，如何创建controller可以参考之前的案例
     let controller: AVSessionManager.AVSessionController = ALLREADY_HAVE_A_CONTROLLER;
   
     // 销毁当前的controller，销毁后这个controller将不在可用
     controller.destroy(function (err) {
       if (err) {
         console.info(`Destroy controller ERROR : code: ${err.code}, message: ${err.message}`);
       } else {
         console.info('Destroy controller SUCCESS');
       }
     });
   }
   ```
