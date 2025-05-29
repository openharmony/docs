# 媒体会话提供方

音视频应用在实现音视频功能的同时，需要作为媒体会话提供方接入媒体会话，在媒体会话控制方（例如播控中心）中展示媒体相关信息，及响应媒体会话控制方下发的播控命令。

## 基本概念

- 媒体会话元数据（AVMetadata）： 用于描述媒体数据相关属性，包含标识当前媒体的ID（assetId），上一首媒体的ID（previousAssetId），下一首媒体的ID（nextAssetId），标题（title），专辑作者（author），专辑名称（album），词作者（writer），媒体时长（duration）等属性。

- 媒体播放状态（AVPlaybackState）：用于描述媒体播放状态的相关属性，包含当前媒体的播放状态（state）、播放位置（position）、播放倍速（speed）、缓冲时间（bufferedTime）、循环模式（loopMode）、是否收藏（isFavorite）、正在播放的媒体Id（activeItemId）、自定义媒体数据（extras）等属性。

## 接口说明

媒体会话提供方使用的关键接口如下表所示。接口返回值有两种返回形式：callback和promise，下表中为callback形式接口，promise和callback只是返回值方式不一样，功能相同。

更多API说明请参见[API文档](../../reference/apis-avsession-kit/js-apis-avsession.md)。

| 接口名 | 说明 | 
| -------- | -------- |
| createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback&lt;AVSession&gt;): void<sup>10+<sup> | 创建媒体会话。<br/>一个UIAbility只能存在一个媒体会话，重复创建会失败。 | 
| setAVMetadata(data: AVMetadata, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 设置媒体会话元数据。 | 
| setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 设置媒体会话播放状态。 | 
| setLaunchAbility(ability: WantAgent, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 设置启动UIAbility。 | 
| getController(callback: AsyncCallback&lt;AVSessionController&gt;): void<sup>10+<sup> | 获取当前会话自身控制器。 | 
| getOutputDevice(callback: AsyncCallback&lt;OutputDeviceInfo&gt;): void<sup>10+<sup> | 获取播放设备相关信息。 |
| activate(callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 激活媒体会话。 | 
| deactivate(callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 禁用当前会话。 |
| destroy(callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 销毁媒体会话。 | 
| setAVQueueItems(items: Array&lt;AVQueueItem&gt;, callback: AsyncCallback&lt;void&gt;): void <sup>10+<sup> | 设置媒体播放列表。 |
| setAVQueueTitle(title: string, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 设置媒体播放列表名称。 |
| dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 设置会话内自定义事件。 |
| setExtras(extras: {[key: string]: Object}, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | 设置键值对形式的自定义媒体数据包。|
| getOutputDeviceSync(): OutputDeviceInfo<sup>10+<sup> | 使用同步方法获取当前输出设备信息。 |

## 开发步骤

音视频应用作为媒体会话提供方接入媒体会话的基本步骤如下所示：

1. 通过AVSessionManager的方法创建并激活媒体会话。
     
      ```ts
      import { avSession as AVSessionManager } from '@kit.AVSessionKit';
      @Entry
      @Component
      struct Index {
        @State message: string = 'hello world';
    
        build() { 
          Column() {
              Text(this.message)
                .onClick(()=>{
                  // 开始创建并激活媒体会话。
                  // 创建session。
                  let context = this.getUIContext().getHostContext() as Context;
                  async function createSession() {
                      let type: AVSessionManager.AVSessionType = 'audio';
                      let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
                      await session.activate();
                      console.info(`session create done : sessionId : ${session.sessionId}`);
                  }
                })
            }
          .width('100%')
          .height('100%')
        }
      }
      ```

2. 跟随媒体信息的变化，及时设置媒体会话信息。需要设置的媒体会话信息主要包括：
   - 媒体会话元数据AVMetadata。
   - 媒体播放状态AVPlaybackState。

   音视频应用设置的媒体会话信息，会被媒体会话控制方通过AVSessionController相关方法获取后进行显示或处理。
     
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
                .onClick(()=>{
                  let context = this.getUIContext().getHostContext() as Context;
                  async function setSessionInfo() {
                      // 假设已经创建了一个session，如何创建session可以参考之前的案例。
                      let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');
                      // 播放器逻辑··· 引发媒体信息与播放状态的变更。
                      // 设置必要的媒体信息
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
                      // 简单设置一个播放状态 - 暂停 未收藏。
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
                      // 设置一个播放列表。
                      let queueItemDescription_1: AVSessionManager.AVMediaDescription = {
                      assetId: '001',
                      title: 'music_name',
                      subtitle: 'music_sub_name',
                      description: 'music_description',
                      mediaImage: "PIXELMAP_OBJECT",
                      extras: {'extras':'any'}
                      };
                      let queueItem_1: AVSessionManager.AVQueueItem = {
                      itemId: 1,
                      description: queueItemDescription_1
                      };
                      let queueItemDescription_2: AVSessionManager.AVMediaDescription = {
                      assetId: '002',
                      title: 'music_name',
                      subtitle: 'music_sub_name',
                      description: 'music_description',
                      mediaImage: "PIXELMAP_OBJECT",
                      extras: {'extras':'any'}
                      };
                      let queueItem_2: AVSessionManager.AVQueueItem = {
                      itemId: 2,
                      description: queueItemDescription_2
                      };
                      let queueItemsArray = [queueItem_1, queueItem_2];
                      session.setAVQueueItems(queueItemsArray).then(() => {
                      console.info(`SetAVQueueItems successfully`);
                      }).catch((err: BusinessError) => {
                      console.error(`Failed to set AVQueueItem, error code: ${err.code}, error message: ${err.message}`);
                      });
                      // 设置媒体播放列表名称。
                      let queueTitle = 'QUEUE_TITLE';
                      session.setAVQueueTitle(queueTitle).then(() => {
                      console.info(`SetAVQueueTitle successfully`);
                      }).catch((err: BusinessError) => {
                      console.info(`Failed to set AVQueueTitle, error code: ${err.code}, error message: ${err.message}`);
                      });
                  }
                })
            }
          .width('100%')
          .height('100%')
        }
      }
      ```

3. 设置用于被媒体会话控制方拉起的UIAbility。当用户操作媒体会话控制方的界面时，例如点击播控中心的卡片，可以拉起此处配置的UIAbility。
   设置UIAbility时通过WantAgent接口实现，更多关于WantAgent的信息请参考[WantAgent](../../reference/apis-ability-kit/js-apis-app-ability-wantAgent.md)。

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { wantAgent } from '@kit.AbilityKit';
   @Entry
   @Component
   struct Index {
      @State message: string = 'hello world';
    
      build() { 
        Column() {
            Text(this.message)
              .onClick(()=>{
                let context = this.getUIContext().getHostContext() as Context;
                async function getWantAgent() {
                    let type: AVSessionManager.AVSessionType = 'audio';
                    // 假设已经创建了一个session，如何创建session可以参考之前的案例。
                    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
                    let wantAgentInfo: wantAgent.WantAgentInfo = {
                    wants: [
                        {
                        bundleName: 'com.example.musicdemo',
                        abilityName: 'MainAbility'
                        }
                    ],
                    // OperationType.START_ABILITIES
                    operationType: 2,
                    requestCode: 0,
                    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
                    }
                    wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
                    session.setLaunchAbility(agent);
                    })
                }
              })
          }
        .width('100%')
        .height('100%')
      }
    }
    ```
    
4. 设置一个即时的自定义会话事件，以供媒体控制方接收到事件后进行相应的操作。

   > **说明：**<br>
   > 通过dispatchSessionEvent方法设置的数据不会保存在会话对象或AVSession服务中。
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
                .onClick(()=>{
                  let context = this.getUIContext().getHostContext() as Context;
                  async function dispatchSessionEvent() {
                      // 假设已经创建了一个session，如何创建session可以参考之前的案例。
                      let type: AVSessionManager.AVSessionType = 'audio';
                      let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
                      let eventName = 'dynamic_lyric';
                      await session.dispatchSessionEvent(eventName, {lyric : 'This is my lyric'}).then(() => {
                      console.info(`Dispatch session event successfully`);
                      }).catch((err: BusinessError) => {
                      console.error(`Failed to dispatch session event. Code: ${err.code}, message: ${err.message}`);
                      })
                  }
                })
            }
          .width('100%')
          .height('100%')
        }
      }
      ```

5. 设置与当前会话相关的自定义媒体数据包，以供媒体控制方接收到事件后进行相应的操作。

   > **说明：**<br>
   > 通过setExtras方法设置的数据包会被存储在AVSession服务中，数据的生命周期与会话一致；会话对应的Controller可以使用getExtras来获取该数据。

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
              .onClick(()=>{
                let context = this.getUIContext().getHostContext() as Context;
                async function setExtras() {
                    // 假设已经创建了一个session，如何创建session可以参考之前的案例。
                    let type: AVSessionManager.AVSessionType = 'audio';
                    let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
                    await session.setExtras({extra : 'This is my custom meida packet'}).then(() => {
                    console.info(`Set extras successfully`);
                    }).catch((err: BusinessError) => {
                    console.error(`Failed to set extras. Code: ${err.code}, message: ${err.message}`);
                    })
                }
              })
          }
        .width('100%')
        .height('100%')
      }
   }
   ```

6. 注册播控命令事件监听，便于响应用户通过媒体会话控制方，例如播控中心，下发的播控命令。

   在Session侧注册的监听分为`固定播控命令`和`高级播控事件`两种。

   6.1 固定控制命令的监听

   > **说明：**
   >
   > 媒体会话提供方在注册相关固定播控命令事件监听时，监听的事件会在媒体会话控制方的getValidCommands()方法中体现，即媒体会话控制方会认为对应的方法有效，进而根据需要触发相应暂不使用时的事件。为了保证媒体会话控制方下发的播控命令可以被正常执行，媒体会话提供方请勿进行无逻辑的空实现监听。

   Session侧的固定播控命令主要包括播放、暂停、上一首、下一首等基础操作命令，详细介绍请参见[AVControlCommand](../../reference/apis-avsession-kit/js-apis-avsession.md#avcontrolcommand10)。
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';

   @Entry
   @Component
   struct Index {
     @State message: string = 'hello world';
    
     build() { 
       Column() {
           Text(this.message)
             .onClick(()=>{
               let context = this.getUIContext().getHostContext() as Context;
               async function setListenerForMesFromController() {
                   // 假设已经创建了一个session，如何创建session可以参考之前的案例。
                   let type: AVSessionManager.AVSessionType = 'audio';
                   let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
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
                   session.on('stop', () => {
                   console.info(`on stop , do stop task`);
                       // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('stop')取消监听。
                       // 处理完毕后，请使用SetAVPlayState上报播放状态。
                   });
                   session.on('playNext', () => {
                   console.info(`on playNext , do playNext task`);
                       // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('playNext')取消监听。
                       // 处理完毕后，请使用SetAVPlayState上报播放状态，使用SetAVMetadata上报媒体信息。
                   });
                   session.on('playPrevious', () => {
                   console.info(`on playPrevious , do playPrevious task`);
                       // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('playPrevious')取消监听。
                       // 处理完毕后，请使用SetAVPlayState上报播放状态，使用SetAVMetadata上报媒体信息。
                   });
                   session.on('fastForward', () => {
                   console.info(`on fastForward , do fastForward task`);
                       // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('fastForward')取消监听。
                       // 处理完毕后，请使用SetAVPlayState上报播放状态和播放position。
                   });
                   session.on('rewind', () => {
                   console.info(`on rewind , do rewind task`);
                       // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('rewind')取消监听。
                       // 处理完毕后，请使用SetAVPlayState上报播放状态和播放position。
                   });
                   session.on('seek', (time) => {
                   console.info(`on seek , the seek time is ${time}`);
                       // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('seek')取消监听。
                       // 处理完毕后，请使用SetAVPlayState上报播放状态和播放position。
                   });
                   session.on('setSpeed', (speed) => {
                   console.info(`on setSpeed , the speed is ${speed}`);
                   // do some tasks ···
                   });
                   session.on('setLoopMode', (mode) => {
                   console.info(`on setLoopMode , the loop mode is ${mode}`);
                       // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('setLoopMode')取消监听。
                       // 应用自定下一个模式，处理完毕后，请使用SetAVPlayState上报切换后的LoopMode。
                   });
                   session.on('toggleFavorite', (assetId) => {
                   console.info(`on toggleFavorite , the target asset Id is ${assetId}`);
                       // 如暂不支持该指令，请勿注册；或在注册后但暂不使用时，通过session.off('toggleFavorite')取消监听。
                       // 处理完毕后，请使用SetAVPlayState上报收藏结果isFavorite。
                   });
               }
             })
         }
       .width('100%')
       .height('100%')
     }
   }
   ```

   6.2 高级播控事件的监听

   Session侧的可以注册的高级播控事件主要包括：

   - skipToQueueItem: 播放列表其中某项被选中的事件。
   - handleKeyEvent: 按键事件。
   - outputDeviceChange: 播放设备变化的事件。
   - commonCommand: 自定义控制命令变化的事件。

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   @Entry
   @Component
   struct Index {
     @State message: string = 'hello world';
 
     build() { 
       Column() {
           Text(this.message)
             .onClick(()=>{
               let context = this.getUIContext().getHostContext() as Context;
               async function setListenerForMesFromController() {
                   // 假设已经创建了一个session，如何创建session可以参考之前的案例。
                   let type: AVSessionManager.AVSessionType = 'audio';
                   let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
                   // 一般在监听器中会对播放器做相应逻辑处理。
                   // 不要忘记处理完后需要通过set接口同步播放相关信息，参考上面的用例。
                   session.on('skipToQueueItem', (itemId) => {
                   console.info(`on skipToQueueItem , do skip task`);
                   // do some tasks ···
                   });
                   session.on('handleKeyEvent', (event) => {
                   console.info(`on handleKeyEvent , the event is ${JSON.stringify(event)}`);
                   // do some tasks ···
                   });
                   session.on('outputDeviceChange', (device) => {
                   console.info(`on outputDeviceChange , the device info is ${JSON.stringify(device)}`);
                   // do some tasks ···
                   });
                   session.on('commonCommand', (commandString, args) => {
                   console.info(`on commonCommand , command is ${commandString}, args are ${JSON.stringify(args)}`);
                   // do some tasks ···
                   });
               }
             })
         }
       .width('100%')
       .height('100%')
     }
   }
   ```

7. 获取当前媒体会话自身的控制器，与媒体会话对应进行通信交互。
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';

   @Entry
   @Component
   struct Index {
     @State message: string = 'hello world';
 
     build() { 
       Column() {
           Text(this.message)
             .onClick(()=>{
               let context = this.getUIContext().getHostContext() as Context;
               async function createControllerFromSession() {
                   // 假设已经创建了一个session，如何创建session可以参考之前的案例。
                   let type: AVSessionManager.AVSessionType = 'audio';
                   let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
 
                   // 通过已有session获取一个controller对象。
                   let controller = await session.getController();
 
                   // controller可以与原session对象进行基本的通信交互，比如下发播放命令。
                   let avCommand: AVSessionManager.AVControlCommand = {command:'play'};
                   controller.sendControlCommand(avCommand);
 
                   // 或者做状态变更监听。
                   controller.on('playbackStateChange', 'all', (state) => {
 
                   // do some things.
                   });
 
               }
             })
         }
       .width('100%')
       .height('100%')
     }
   }
   ```

8. 音视频应用在退出，并且不需要继续播放时，及时取消监听以及销毁媒体会话释放资源。
   取消播控命令监听的示例代码如下所示 ：

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   @Entry
   @Component
   struct Index {
     @State message: string = 'hello world';
 
     build() { 
       Column() {
           Text(this.message)
             .onClick(()=>{
               let context = this.getUIContext().getHostContext() as Context;
               async function unregisterSessionListener() {
                   // 假设已经创建了一个session，如何创建session可以参考之前的案例。
                   let type: AVSessionManager.AVSessionType = 'audio';
                   let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
 
                   // 取消指定session下的相关监听。
                   session.off('play');
                   session.off('pause');
                   session.off('stop');
                   session.off('playNext');
                   session.off('playPrevious');
                   session.off('skipToQueueItem');
                   session.off('handleKeyEvent');
                   session.off('outputDeviceChange');
                   session.off('commonCommand');
               }
             })
         }
       .width('100%')
       .height('100%')
     }
   }
   ```

     销毁媒体会话示例代码如下所示：
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   @Entry
   @Component
   struct Index {
     @State message: string = 'hello world';
 
     build() { 
       Column() {
           Text(this.message)
             .onClick(()=>{
               let context = this.getUIContext().getHostContext() as Context;
               async function destroySession() {
                   // 假设已经创建了一个session，如何创建session可以参考之前的案例。
                   let type: AVSessionManager.AVSessionType = 'audio';
                   let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
                   // 主动销毁已创建的session。
                   session.destroy((err) => {
                   if (err) {
                       console.error(`Failed to destroy session. Code: ${err.code}, message: ${err.message}`);
                   } else {
                       console.info(`Destroy : SUCCESS `);
                   }
                   });
               }
             })
         }
       .width('100%')
       .height('100%')
     }
   }
   ```

## 相关实例

针对媒体会话提供方开发，有以下相关实例可供参考：

- [媒体会话——提供方（ArkTS）（Full SDK）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVSession/MediaProvider)