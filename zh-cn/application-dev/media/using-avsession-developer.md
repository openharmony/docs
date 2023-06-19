# 媒体会话提供方

音视频应用在实现音视频功能的同时，需要作为媒体会话提供方接入媒体会话，在媒体会话控制方（例如播控中心）中展示媒体相关信息，及响应媒体会话控制方下发的播控命令。

## 基本概念

- 媒体会话元数据（AVMetadata）： 用于描述媒体数据相关属性，包含标识当前媒体的ID（assetId），上一首媒体的ID（previousAssetId），下一首媒体的ID（nextAssetId），标题（title），专辑作者（author），专辑名称（album），词作者（writer），媒体时长（duration）等属性。

- 媒体播放状态（AVPlaybackState）：用于描述媒体播放状态的相关属性，包含当前媒体的播放状态（state）、播放位置（position）、播放倍速（speed）、缓冲时间（bufferedTime）、循环模式（loopMode）、是否收藏（isFavorite）等属性。

## 接口说明

媒体会话提供方使用的关键接口如下表所示。接口返回值有两种返回形式：callback和promise，下表中为callback形式接口，promise和callback只是返回值方式不一样，功能相同。

更多API说明请参见[API文档](../reference/apis/js-apis-avsession.md)。

| 接口名 | 说明 | 
| -------- | -------- |
| createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback&lt;AVSession&gt;): void | 创建媒体会话。<br/>一个UIAbility只能存在一个媒体会话，重复创建会失败。 | 
| setAVMetadata(data: AVMetadata, callback: AsyncCallback&lt;void&gt;): void | 设置媒体会话元数据。 | 
| setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback&lt;void&gt;): void | 设置媒体会话播放状态。 | 
| setLaunchAbility(ability: WantAgent, callback: AsyncCallback&lt;void&gt;): void | 设置启动UIAbility。 | 
| getController(callback: AsyncCallback&lt;AVSessionController&gt;): void | 获取当前会话自身控制器。 | 
| activate(callback: AsyncCallback&lt;void&gt;): void | 激活媒体会话。 | 
| destroy(callback: AsyncCallback&lt;void&gt;): void | 销毁媒体会话。 | 

## 开发步骤

音视频应用作为媒体会话提供方接入媒体会话的基本步骤如下所示：

1. 通过AVSessionManager的方法创建并激活媒体会话。
     
   ```ts
   import AVSessionManager from '@ohos.multimedia.avsession'; //导入AVSessionManager模块
   
   // 创建session
   async createSession() {
       let session: AVSessionManager.AVSession = await AVSessionManager.createAVSession(this.context, 'SESSION_NAME', 'audio');
       session.activate();
       console.info(`session create done : sessionId : ${session.sessionId}`);
   }
   ```

2. 跟随媒体信息的变化，及时设置媒体会话信息。需要设置的媒体会话信息主要包括：
   - 媒体会话元数据AVMetadata。
   - 媒体播放状态AVPlaybackState。

   音视频应用设置的媒体会话信息，会被媒体会话控制方通过AVSessionController相关方法获取后进行显示或处理。
     
   ```ts
   async setSessionInfo() {
     // 假设已经创建了一个session，如何创建session可以参考之前的案例
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
     // 播放器逻辑··· 引发媒体信息与播放状态的变更
     // 设置必要的媒体信息
     let metadata: AVSessionManager.AVMetadata = {
       assetId: "0",
       title: "TITLE",
       artist: "ARTIST"
     };
     session.setAVMetadata(metadata).then(() => {
       console.info('SetAVMetadata successfully');
     }).catch((err) => {
       console.info(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
     });
     // 简单设置一个播放状态 - 暂停 未收藏
     let playbackState: AVSessionManager.AVPlaybackState = {
       state:AVSessionManager.PlaybackState.PLAYBACK_STATE_PAUSE,
       isFavorite:false
     };
     session.setAVPlaybackState(playbackState, function (err) {
       if (err) {
         console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
       } else {
         console.info('SetAVPlaybackState successfully');
       }
     });
   }
   ```

3. 设置用于被媒体会话控制方拉起的UIAbility。当用户操作媒体会话控制方的界面时，例如点击播控中心的卡片，可以拉起此处配置的UIAbility。
   设置UIAbility时通过WantAgent接口实现，更多关于WantAgent的信息请参考[WantAgent](../reference/apis/js-apis-app-ability-wantAgent.md)。
 
   ```ts
   import WantAgent from "@ohos.app.ability.wantAgent";
   ```

   ```ts
   // 假设已经创建了一个session，如何创建session可以参考之前的案例
   let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
   let wantAgentInfo = {
       wants: [
           {
               bundleName: "com.example.musicdemo",
               abilityName: "com.example.musicdemo.MainAbility"
           }
       ],
       operationType: WantAgent.OperationType.START_ABILITIES,
       requestCode: 0,
       wantAgentFlags: [WantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
   }
   WantAgent.getWantAgent(wantAgentInfo).then((agent) => {
       session.setLaunchAbility(agent)
   })
   ```

4. 注册播控命令事件监听，便于响应用户通过媒体会话控制方，例如播控中心，下发的播控命令。
   > **说明：**
   >
   > 媒体会话提供方在注册相关播控命令事件监听时，监听的事件会在媒体会话控制方的getValidCommands()方法中体现，即媒体会话控制方会认为对应的方法有效，进而根据需要触发相应的事件。为了保证媒体会话控制方下发的播控命令可以被正常执行，媒体会话提供方请勿进行无逻辑的空实现监听。
     
   ```ts
   async setListenerForMesFromController() {
     // 假设已经创建了一个session，如何创建session可以参考之前的案例
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
     // 一般在监听器中会对播放器做相应逻辑处理
     // 不要忘记处理完后需要通过set接口同步播放相关信息，参考上面的用例
     session.on('play', () => {
       console.info('on play , do play task');
       
       // do some tasks ···
     });
     session.on('pause', () => {
       console.info('on pause , do pause task');
       // do some tasks ···
     });
     session.on('stop', () => {
       console.info('on stop , do stop task');
       // do some tasks ···
     });
     session.on('playNext', () => {
       console.info('on playNext , do playNext task');
       // do some tasks ···
     });
     session.on('playPrevious', () => {
       console.info('on playPrevious , do playPrevious task');
       // do some tasks ···
     });
   }
   ```

5. 获取当前媒体会话自身的控制器，与媒体会话对应进行通信交互。
     
   ```ts
   async createControllerFromSession() {
     // 假设已经创建了一个session，如何创建session可以参考之前的案例
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
   
     // 通过已有session获取一个controller对象
     let controller: AVSessionManager.AVSessionController = await session.getController();
   
     // controller可以与原session对象进行基本的通信交互，比如下发播放命令
     let avCommand: AVSessionManager.AVControlCommand = {command:'play'};
     controller.sendControlCommand(avCommand);
   
     // 或者做状态变更监听
     controller.on('playbackStateChange', 'all', (state: AVSessionManager.AVPlaybackState) => {
   
       // do some things
     });
   
     // controller可以做的操作还有很多，具体可以参考媒体会话控制方相关的说明
   }
   ```

6. 音视频应用在退出，并且不需要继续播放时，及时取消监听以及销毁媒体会话释放资源。
   取消播控命令监听的示例代码如下所示 ：

   ```ts
   async unregisterSessionListener() {
     // 假设已经创建了一个session，如何创建session可以参考之前的案例
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
   
     // 取消指定session下的相关监听
     session.off('play');
     session.off('pause');
     session.off('stop');
     session.off('playNext');
     session.off('playPrevious');
   }
   ```

     销毁媒体会话示例代码如下所示：
     
   ```ts
   async destroySession() {
     // 假设已经创建了一个session，如何创建session可以参考之前的案例
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
     // 主动销毁已创建的session
     session.destroy(function (err) {
       if (err) {
         console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
       } else {
         console.info('Destroy : SUCCESS ');
       }
     });
   }
   ```
