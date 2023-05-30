# AVSession Provider

An audio and video application needs to access the AVSession service as a provider in order to display media information in the controller (for example, Media Controller) and respond to playback control commands delivered by the controller.

## Basic Concepts

- AVMetadata: media data related attributes, including the IDs of the current media asset (assetId), previous media asset (previousAssetId), and next media asset (nextAssetId), title, author, album, writer, and duration.

- AVPlaybackState: playback state attributes, including the playback state, position, speed, buffered time, loop mode, media item being played (activeItemId), custom media data (extras), and whether the media asset is favorited (isFavorite).

## Available APIs

The table below lists the key APIs used by the provider. The APIs use either a callback or promise to return the result. The APIs listed below use a callback. They provide the same functions as their counterparts that use a promise.

For details, see [AVSession Management](../reference/apis/js-apis-avsession.md).

| API| Description|
| -------- | -------- |
| createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback&lt;AVSession&gt;): void | Creates an AVSession.<br>Only one AVSession can be created for a UIAbility.|
| setAVMetadata(data: AVMetadata, callback: AsyncCallback&lt;void&gt;): void | Sets AVSession metadata.|
| setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback&lt;void&gt;): void | Sets the AVSession playback state.|
| setLaunchAbility(ability: WantAgent, callback: AsyncCallback&lt;void&gt;): void | Starts a UIAbility.|
| getController(callback: AsyncCallback&lt;AVSessionController&gt;): void | Obtains the controller of the AVSession.|
| getOutputDevice(callback: AsyncCallback&lt;OutputDeviceInfo&gt;): void | Obtains the output device information.|
| activate(callback: AsyncCallback&lt;void&gt;): void | Activates the AVSession.|
| deactivate(callback: AsyncCallback&lt;void&gt;): void | Deactivates this session.|
| destroy(callback: AsyncCallback&lt;void&gt;): void | Destroys the AVSession.|
| setAVQueueItems(items: Array&lt;AVQueueItem&gt;, callback: AsyncCallback&lt;void&gt;): void <sup>10+<sup> | Sets a playlist.|
| setAVQueueTitle(title: string, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sets a name for the playlist.|
| dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Dispatches a custom session event.|
| setExtras(extras: {[key: string]: Object}, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sets a custom media packet in the form of a key-value pair.|

## How to Develop

To enable an audio and video application to access the AVSession service as a provider, proceed as follows:

1. Call an API in the **AVSessionManager** class to create and activate an **AVSession** object.
   
   ```ts
   // To create an AVSession object, you must first obtain the application context. You can set a global variable in the EntryAbility file of the application to store the application context.
   export default class EntryAbility extends UIAbility {
       onCreate(want, launchParam) {
           globalThis.context = this.context; // Set the global variable globalThis.context to store the application context.
       }
       // Other APIs of the EntryAbility class.
    }

   // Start to create and activate an AVSession object.
   import AVSessionManager from '@ohos.multimedia.avsession'; // Import the AVSessionManager module.
   
   // Create an AVSession object.
   async createSession() {
       let session: AVSessionManager.AVSession = await AVSessionManager.createAVSession(globalThis.context, 'SESSION_NAME', 'audio');
       session.activate();
       console.info(`session create done : sessionId : ${session.sessionId}`);
   }
   ```

2. Set AVSession information, which includes:
   - AVMetadata
   - AVPlaybackState

   The controller will call an API in the **AVSessionController** class to obtain the information and display or process the information.
   
   ```ts
   async setSessionInfo() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let session: AVSessionManager.AVSession = ALREADY_CREATE_A_SESSION;
     // The player logic that triggers changes in the session metadata and playback state is omitted here.
     // Set necessary session metadata.
     let metadata: AVSessionManager.AVMetadata = {
       assetId: '0',
       title: 'TITLE',
       artist: 'ARTIST'
     };
     session.setAVMetadata(metadata).then(() => {
       console.info(`SetAVMetadata successfully`);
     }).catch((err) => {
       console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
     });
     // Set the playback state to paused and set isFavorite to false.
     let playbackState: AVSessionManager.AVPlaybackState = {
       state:AVSessionManager.PlaybackState.PLAYBACK_STATE_PAUSE,
       isFavorite:false
     };
     session.setAVPlaybackState(playbackState, function (err) {
       if (err) {
         console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
       } else {
         console.info(`SetAVPlaybackState successfully`);
       }
     });
     // Set a playlist.
     let queueItemDescription_1 = {
       mediaId: '001',
       title: 'music_name',
       subtitle: 'music_sub_name',
       description: 'music_description',
       icon: PIXELMAP_OBJECT,
       iconUri: 'http://www.xxx.com',
       extras: {'extras':'any'}
     };
     let queueItem_1 = {
       itemId: 1,
       description: queueItemDescription_1
     };
     let queueItemDescription_2 = {
       mediaId: '002',
       title: 'music_name',
       subtitle: 'music_sub_name',
       description: 'music_description',
       icon: PIXELMAP_OBJECT,
       iconUri: 'http://www.xxx.com',
       extras: {'extras':'any'}
     };
     let queueItem_2 = {
       itemId: 2,
       description: queueItemDescription_2
     };
     let queueItemsArray = [queueItem_1, queueItem_2];
     session.setAVQueueItems(queueItemsArray).then(() => {
       console.info(`SetAVQueueItems successfully`);
     }).catch((err) => {
       console.error(`Failed to set AVQueueItem, error code: ${err.code}, error message: ${err.message}`);
     });
     // Set a name for the playlist.
     let queueTitle = 'QUEUE_TITLE';
       session.setAVQueueTitle(queueTitle).then(() => {
         console.info(`SetAVQueueTitle successfully`);
       }).catch((err) => {
       console.info(`Failed to set AVQueueTitle, error code: ${err.code}, error message: ${err.message}`);
     });
   }
   ```

3. Set the UIAbility to be started by the controller. The UIAbility configured here is started when a user operates the UI of the controller, for example, clicking a widget in Media Controller.
   The UIAbility is set through the **WantAgent** API. For details, see [WantAgent](../reference/apis/js-apis-app-ability-wantAgent.md).

   ```ts
   import wantAgent from "@ohos.app.ability.wantAgent";
   ```

   ```ts
   // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
   let session: AVSessionManager.AVSession = ALREADY_CREATE_A_SESSION;
   let wantAgentInfo = {
       wants: [
           {
               bundleName: 'com.example.musicdemo',
               abilityName: 'com.example.musicdemo.MainAbility'
           }
       ],
       operationType: wantAgent.OperationType.START_ABILITIES,
       requestCode: 0,
       wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
   }
   wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
       session.setLaunchAbility(agent);
   })
   ```

4. Set a custom session event. The controller performs an operation after receiving the event.

   > **NOTE**
   >
   > The data set through **dispatchSessionEvent** is not saved in the **AVSession** object or AVSession service.

   ```ts
   // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
   let session: AVSessionManager.AVSession = ALREADY_CREATE_A_SESSION;
   let eventName = 'dynamic_lyric';
   let args = {
     lyric : 'This is my lyric'
   }
   await session.dispatchSessionEvent(eventName, args).then(() => {
      console.info(`Dispatch session event successfully`);
   }).catch((err) => {
      console.error(`Failed to dispatch session event. Code: ${err.code}, message: ${err.message}`);
   })
   ```

5. Set a custom media packet. The controller performs an operation after receiving the event.

   > **NOTE**
   >
   > The data set by using **setExtras** is stored in the AVSession service. The data lifecycle is the same as that of the **AVSession** object, and the controller corresponding to the object can use **getExtras** to obtain the data.

   ```ts
   // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
   let session: AVSessionManager.AVSession = ALREADY_CREATE_A_SESSION;
   let extras = {
     extra : 'This is my custom meida packet'
   }
   await session.setExtras(extras).then(() => {
      console.info(`Set extras successfully`);
   }).catch((err) => {
      console.error(`Failed to set extras. Code: ${err.code}, message: ${err.message}`);
   })
   ```

6. Listen for playback control commands or events delivered by the controller, for example, Media Controller.

   Both fixed playback control commands and advanced playback control events can be listened for.

   - Listening for Fixed Playback Control Commands

     > **NOTE**
     >
     > After the provider registers a listener for fixed playback control commands, the commands will be reflected in **getValidCommands()** of the controller. In other words, the controller determines that the command is valid and triggers the corresponding event as required. To ensure that the playback control commands delivered by the controller can be executed normally, the provider should not use a null implementation for listening.

     Fixed playback control commands on the session side include basic operation commands such as play, pause, previous, and next. For details, see [AVControlCommand](../reference/apis/js-apis-avsession.md).
   
     ```ts
     async setListenerForMesFromController() {
       // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
       let session: AVSessionManager.AVSession = ALREADY_CREATE_A_SESSION;
       // Generally, logic processing on the player is implemented in the listener.
       // After the processing is complete, use the setter to synchronize the playback information. For details, see the code snippet above.
       session.on('play', () => {
         console.info(`on play , do play task`);
         // do some tasks ···
       });
       session.on('pause', () => {
         console.info(`on pause , do pause task`);
         // do some tasks ···
       });
       session.on('stop', () => {
         console.info(`on stop , do stop task`);
         // do some tasks ···
       });
       session.on('playNext', () => {
         console.info(`on playNext , do playNext task`);
         // do some tasks ···
       });
       session.on('playPrevious', () => {
         console.info(`on playPrevious , do playPrevious task`);
         // do some tasks ···
       });
       session.on('fastForward', () => {
         console.info(`on fastForward , do fastForward task`);
         // do some tasks ···
       });
       session.on('rewind', () => {
         console.info(`on rewind , do rewind task`);
         // do some tasks ···
       });
    
       session.on('seek', (time) => {
         console.info(`on seek , the seek time is ${time}`);
         // do some tasks ···
       });
       session.on('setSpeed', (speed) => {
         console.info(`on setSpeed , the speed is ${speed}`);
         // do some tasks ···
       });
       session.on('setLoopMode', (mode) => {
         console.info(`on setLoopMode , the loop mode is ${mode}`);
         // do some tasks ···
       });
       session.on('toggleFavorite', (assetId) => {
         console.info(`on toggleFavorite , the target asset Id is ${assetId}`);
         // do some tasks ···
       });
     }
     ```

   - Listening for Advanced Playback Control Events

     The following advanced playback control events can be listened for:

     - **skipToQueueItem**: triggered when an item in the playlist is selected.
     - **handleKeyEvent**: triggered when a key is pressed.
     - **outputDeviceChange**: triggered when the output device changes.
     - **commonCommand**: triggered when a custom playback control command changes.

     ```ts
     async setListenerForMesFromController() {
       // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
       let session: AVSessionManager.AVSession = ALREADY_CREATE_A_SESSION;
       // Generally, logic processing on the player is implemented in the listener.
       // After the processing is complete, use the setter to synchronize the playback information. For details, see the code snippet above.
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
     ```

7. Obtain an **AVSessionController** object for this **AVSession** object for interaction.
   
   ```ts
   async createControllerFromSession() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let session: AVSessionManager.AVSession = ALREADY_CREATE_A_SESSION;
   
     // Obtain an AVSessionController object for this AVSession object.
     let controller: AVSessionManager.AVSessionController = await session.getController();
   
     // The AVSessionController object can interact with the AVSession object, for example, by delivering a playback control command.
     let avCommand: AVSessionManager.AVControlCommand = {command:'play'};
     controller.sendControlCommand(avCommand);
   
     // Alternatively, listen for state changes.
     controller.on('playbackStateChange', 'all', (state: AVSessionManager.AVPlaybackState) => {
   
       // do some things
     });
   
     // The AVSessionController object can perform many operations. For details, see the description of the controller.
   }
   ```

8. When the audio and video application exits and does not need to continue playback, cancel the listener and destroy the **AVSession** object.

   The code snippet below is used for canceling the listener for playback control commands:

   ```ts
   async unregisterSessionListener() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let session: AVSessionManager.AVSession = ALREADY_CREATE_A_SESSION;
   
     // Cancel the listener of the AVSession object.
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
   ```
   
   
   The code snippet below is used for destroying the AVSession object:
   
      ```ts
   async destroySession() {
    // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
    let session: AVSessionManager.AVSession = ALREADY_CREATE_A_SESSION;
    // Destroy the AVSession object.
    session.destroy(function (err) {
      if (err) {
        console.error(`Failed to destroy session. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.info(`Destroy : SUCCESS `);
      }
    });
   }
      ```