# 使用音视频投播

通过本开发指导，完成一次音频跨设备投播。

## 接口说明

对于每个异步调用的API均提供了callback函数和Promise函数，以下示例均采用callback函数。详细的API接口说明，请参考[AVCastPicker组件参考](../reference/arkui-ts/ohos-avcastpicker.md)和[AVCastController API参考文档](../reference/apis/js-apis-avsession.md#avcastcontroller10)。

| 接口 |  说明 |
| -------- | -------- |
| getAVCastController(callback: AsyncCallback\<AVCastController\>): void | 获取远端投播时的控制接口。|
| on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void  | 注册设备变化的回调，同时包含了设备的连接状态。|
| sendControlCommand(command: AVCastControlCommand, callback: AsyncCallback\<void\>): void  | 投播会话的控制接口，用于进行投播中的各种播控指令 |
| prepare(item: AVQueueItem, callback: AsyncCallback\<void>): void | 准备播放，进行资源加载和缓冲，不会触发真正的播放 |
| start(item: AVQueueItem, callback: AsyncCallback\<void>): void  | 开始播放媒体资源 |
| on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState\> \| 'all', callback: (state: AVPlaybackState) => void)  | 注册播放状态变化的回调 |
| on(type: 'mediaItemChange', callback: AsyncCallback\<AVQueueItem\>): void | 注册当前播放内容更新的回调，返回当前播放的内容的信息。|

>**说明：**
>
> AVCastController由系统获取并返回，在设备连接成功后获取，在设备断开后不能继续使用，否则会抛出异常。

## 开发步骤

1. 创建播放器，并创建AVSession。

   通过AVSessionManager创建并激活媒体会话。

   ```ts
   import AVSessionManager from '@ohos.multimedia.avsession'; //导入AVSession模块

   // 创建session
   async createSession() {
       let session: AVSessionManager.AVSession = await AVSessionManager.createAVSession(this.context, 'SESSION_NAME', 'audio');
       session.activate();
       console.info(`session create done : sessionId : ${session.sessionId}`);
   }
   ```

2. 在需要投播的播放界面创建投播组件AVCastPicker。

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

3. 设置AVSession的信息，注册AVSession的回调。用于感知投播连接。

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

4. 通过AVSession获取投播控制器AVCastController，用于控制应用内的播放。

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

5. 申请投播长时任务，避免应用在投播进入后台时被系统冻结，导致无法持续投播。

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

6. 音频焦点的处理。请参考[多音频并发处理](audio-playback-concurrency.md)。

   在应用进入投播后，当前应用需要去注册焦点处理，以免被其他应用的焦点申请而影响。

   **当前投播支持全局切换，后续如果规格变更，再同步调整方案说明。**

7. 结束投播。

   当远端设备断开的时候，应用会收到事件，系统会自动断开连接。

   应用也可以使用断开投播的接口，主动进行投播连接的断开。

   ```ts
   async release() {
     // 一般来说，应用退出时，而不希望继续投播，可以主动结束
     await global.avsession.stopCast();
   }
   ```
