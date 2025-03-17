# AVSession Provider

An audio and video application needs to access the AVSession service as a provider in order to display media information in the controller (for example, Media Controller) and respond to playback control commands delivered by the controller.

## Basic Concepts

- AVMetadata: media data related attributes, including the IDs of the current media asset (assetId), previous media asset (previousAssetId), and next media asset (nextAssetId), title, author, album, writer, and duration.

- AVPlaybackState: playback state attributes, including the playback state, position, speed, buffered time, loop mode, media item being played (activeItemId), custom media data (extras), and whether the media asset is favorited (isFavorite).

## Available APIs

The table below lists the key APIs used by the provider. The APIs use either a callback or promise to return the result. The APIs listed below use a callback. They provide the same functions as their counterparts that use a promise.

For details, see [AVSession Management](../../reference/apis-avsession-kit/js-apis-avsession.md).

| API| Description| 
| -------- | -------- |
| createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback&lt;AVSession&gt;): void<sup>10+<sup> | Creates an AVSession.<br>Only one AVSession can be created for a UIAbility.| 
| setAVMetadata(data: AVMetadata, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sets AVSession metadata.| 
| setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sets the AVSession playback state.| 
| setLaunchAbility(ability: WantAgent, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Starts a UIAbility.| 
| getController(callback: AsyncCallback&lt;AVSessionController&gt;): void<sup>10+<sup> | Obtains the controller of the AVSession.| 
| getOutputDevice(callback: AsyncCallback&lt;OutputDeviceInfo&gt;): void<sup>10+<sup> | Obtains the output device information.|
| activate(callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Activates the AVSession.| 
| deactivate(callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Deactivates this session.|
| destroy(callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Destroys the AVSession.| 
| setAVQueueItems(items: Array&lt;AVQueueItem&gt;, callback: AsyncCallback&lt;void&gt;): void <sup>10+<sup> | Sets a playlist.|
| setAVQueueTitle(title: string, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sets a name for the playlist.|
| dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Dispatches a custom session event.|
| setExtras(extras: {[key: string]: Object}, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sets a custom media packet in the form of a key-value pair.|
| getOutputDeviceSync(): OutputDeviceInfo<sup>10+<sup> | Obtains the output device information. This API is a synchronous API.|

## How to Develop

To enable an audio and video application to access the AVSession service as a provider, proceed as follows:

1. Call an API in the **AVSessionManager** class to create and activate an **AVSession** object.
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';

   // Start to create and activate an AVSession object.
   // Create an AVSession object.
   let context: Context = getContext(this);
   async function createSession() {
     let type: AVSessionManager.AVSessionType = 'audio';
     let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
     await session.activate();
     console.info(`session create done : sessionId : ${session.sessionId}`);
   }
   ```

2. Set AVSession information, which includes:
   - AVMetadata
   - AVPlaybackState

   The controller will call an API in the **AVSessionController** class to obtain the information and display or process the information.
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let context: Context = getContext(this);
   async function setSessionInfo() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');
     // The player logic that triggers changes in the session metadata and playback state is omitted here.
     // Set necessary session metadata.
     let metadata: AVSessionManager.AVMetadata = {
       assetId: '0', // Specified by the application, used to identify the media asset in the application media library.
       title: 'TITLE',
       mediaImage: 'IMAGE',
       artist: 'ARTIST'
     };
     session.setAVMetadata(metadata).then(() => {
       console.info(`SetAVMetadata successfully`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
     });
     // Set the playback state to paused and set isFavorite to false.
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
     // Set a playlist.
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
     // Set a name for the playlist.
     let queueTitle = 'QUEUE_TITLE';
     session.setAVQueueTitle(queueTitle).then(() => {
       console.info(`SetAVQueueTitle successfully`);
     }).catch((err: BusinessError) => {
       console.info(`Failed to set AVQueueTitle, error code: ${err.code}, error message: ${err.message}`);
     });
   }
   ```

3. Set the UIAbility to be started by the controller. The UIAbility configured here is started when a user operates the UI of the controller, for example, clicking a widget in Media Controller.
   The UIAbility is set through the **WantAgent** API. For details, see [WantAgent](../../reference/apis-ability-kit/js-apis-app-ability-wantAgent.md).

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { wantAgent } from '@kit.AbilityKit';

   let context: Context = getContext(this);
   async function getWantAgent() {
     let type: AVSessionManager.AVSessionType = 'audio';
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
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
   ```

4. Set a custom session event. The controller performs an operation after receiving the event.

   > **NOTE**
   > 
   > The data set through **dispatchSessionEvent** is not saved in the **AVSession** object or AVSession service.

   ```ts

   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let context: Context = getContext(this);
   async function dispatchSessionEvent() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let type: AVSessionManager.AVSessionType = 'audio';
     let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
     let eventName = 'dynamic_lyric';
     await session.dispatchSessionEvent(eventName, {lyric : 'This is my lyric'}).then(() => {
       console.info(`Dispatch session event successfully`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to dispatch session event. Code: ${err.code}, message: ${err.message}`);
     })
   }

   ```

5. Set a custom media packet. The controller performs an operation after receiving the event.

   > **NOTE**
   > 
   > The data set by using **setExtras** is stored in the AVSession service. The data lifecycle is the same as that of the **AVSession** object, and the controller corresponding to the object can use **getExtras** to obtain the data.

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let context: Context = getContext(this);
   async function setExtras() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let type: AVSessionManager.AVSessionType = 'audio';
     let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
     await session.setExtras({extra : 'This is my custom meida packet'}).then(() => {
       console.info(`Set extras successfully`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to set extras. Code: ${err.code}, message: ${err.message}`);
     })
   }
   ```

6. Listen for playback control commands or events delivered by the controller, for example, Media Controller.

   Both fixed playback control commands and advanced playback control events can be listened for.

   6.1 Listening for Fixed Playback Control Commands

   > **NOTE**
   >
   > After the provider registers a listener for fixed playback control commands, the commands will be reflected in **getValidCommands()** of the controller. In other words, the controller determines that the command is valid and triggers the corresponding event (not used temporarily) as required. To ensure that the playback control commands delivered by the controller can be executed normally, the provider should not use a null implementation for listening.

   Fixed playback control commands on the session side include basic operation commands such as play, pause, previous, and next. For details, see [AVControlCommand](../../reference/apis-avsession-kit/js-apis-avsession.md#avcontrolcommand10).
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';

   let context: Context = getContext(this);
   async function setListenerForMesFromController() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let type: AVSessionManager.AVSessionType = 'audio';
     let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
     // Generally, logic processing on the player is implemented in the listener.
     // After the processing is complete, use the setter to synchronize the playback information. For details, see the code snippet above.
     session.on('play', () => {
       console.info(`on play , do play task`);
       // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('play') to cancel listening.
       // After the processing is complete, call SetAVPlayState to report the playback state.
     });
     session.on('pause', () => {
       console.info(`on pause , do pause task`);
        // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('pause') to cancel listening.
        // After the processing is complete, call SetAVPlayState to report the playback state.
     });
     session.on('stop', () => {
       console.info(`on stop , do stop task`);
        // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('stop') to cancel listening.
        // After the processing is complete, call SetAVPlayState to report the playback state.
     });
     session.on('playNext', () => {
       console.info(`on playNext , do playNext task`);
        // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('playNext') to cancel listening.
        // After the processing is complete, call SetAVPlayState to report the playback state and call SetAVMetadata to report the media information.
     });
     session.on('playPrevious', () => {
       console.info(`on playPrevious , do playPrevious task`);
        // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('playPrevious') to cancel listening.
        // After the processing is complete, call SetAVPlayState to report the playback state and call SetAVMetadata to report the media information.
     });
     session.on('fastForward', () => {
       console.info(`on fastForward , do fastForward task`);
        // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('fastForward') to cancel listening.
        // After the processing is complete, call SetAVPlayState to report the playback state and position.
     });
     session.on('rewind', () => {
       console.info(`on rewind , do rewind task`);
        // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('rewind') to cancel listening.
        // After the processing is complete, call SetAVPlayState to report the playback state and position.
     });
     session.on('seek', (time) => {
       console.info(`on seek , the seek time is ${time}`);
        // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('seek') to cancel listening.
        // After the processing is complete, call SetAVPlayState to report the playback state and position.
     });
     session.on('setSpeed', (speed) => {
       console.info(`on setSpeed , the speed is ${speed}`);
       // do some tasks ···
     });
     session.on('setLoopMode', (mode) => {
       console.info(`on setLoopMode , the loop mode is ${mode}`);
        // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('setLoopMode') to cancel listening.
        // The application determines the next loop mode. After the processing is complete, call SetAVPlayState to report the new loop mode.
     });
     session.on('toggleFavorite', (assetId) => {
       console.info(`on toggleFavorite , the target asset Id is ${assetId}`);
        // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('toggleFavorite') to cancel listening.
        // After the processing is complete, call SetAVPlayState to report the value of isFavorite.
     });
   }
   ```

   6.2 Listening for Advanced Playback Control Events

   The following advanced playback control events can be listened for:

   - **skipToQueueItem**: triggered when an item in the playlist is selected.
   - **handleKeyEvent**: triggered when a key is pressed.
   - **outputDeviceChange**: triggered when the output device changes.
   - **commonCommand**: triggered when a custom playback control command changes.

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';

   let context: Context = getContext(this);
   async function setListenerForMesFromController() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let type: AVSessionManager.AVSessionType = 'audio';
     let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
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
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';

   let context: Context = getContext(this);
   async function createControllerFromSession() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let type: AVSessionManager.AVSessionType = 'audio';
     let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

     // Obtain an AVSessionController object for this AVSession object.
     let controller = await session.getController();

     // The AVSessionController object can interact with the AVSession object, for example, by delivering a playback control command.
     let avCommand: AVSessionManager.AVControlCommand = {command:'play'};
     controller.sendControlCommand(avCommand);

     // Alternatively, listen for state changes.
     controller.on('playbackStateChange', 'all', (state) => {

       // Do some things.
     });

     // The AVSessionController object can perform many operations. For details, see the description of the controller.
   }
   ```

8. When the audio and video application exits and does not need to continue playback, cancel the listener and destroy the **AVSession** object.

   The code snippet below is used for canceling the listener for playback control commands:

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';

   let context: Context = getContext(this);
   async function unregisterSessionListener() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let type: AVSessionManager.AVSessionType = 'audio';
     let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

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
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';

   let context: Context = getContext(this);
   async function destroySession() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let type: AVSessionManager.AVSessionType = 'audio';
     let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
     // Destroy the AVSession object.
     session.destroy((err) => {
       if (err) {
         console.error(`Failed to destroy session. Code: ${err.code}, message: ${err.message}`);
       } else {
         console.info(`Destroy : SUCCESS `);
       }
     });
   }
   ```
