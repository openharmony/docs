# AVSession Provider

An audio and video application needs to access the AVSession service as a provider in order to display media information in the controller (for example, Media Controller) and respond to playback control commands delivered by the controller.

## Basic Concepts

- AVMetadata: media data related attributes, including the IDs of the current media asset (assetId), previous media asset (previousAssetId), and next media asset (nextAssetId), title, author, album, writer, and duration.

- AVPlaybackState: playback state attributes, including the playback state, position, speed, buffered time, loop mode, and whether the media asset is favorited (**isFavorite**).

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
| activate(callback: AsyncCallback&lt;void&gt;): void | Activates the AVSession.|
| destroy(callback: AsyncCallback&lt;void&gt;): void | Destroys the AVSession.|

## How to Develop

To enable an audio and video application to access the AVSession service as a provider, proceed as follows:

1. Call an API in the **AVSessionManager** class to create and activate an **AVSession** object.
   
   ```ts
   import AVSessionManager from '@ohos.multimedia.avsession'; // Import the AVSessionManager module.
   
   // Create an AVSession object.
   async createSession() {
       let session: AVSessionManager.AVSession = await AVSessionManager.createAVSession(this.context, 'SESSION_NAME', 'audio');
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
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
     // The player logic that triggers changes in the session metadata and playback state is omitted here.
     // Set necessary session metadata.
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
     // Set the playback state to paused and set isFavorite to false.
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

3. Set the UIAbility to be started by the controller. The UIAbility configured here is started when a user operates the UI of the controller, for example, clicking a widget in Media Controller.
   The UIAbility is set through the **WantAgent** API. For details, see [WantAgent](../reference/apis/js-apis-app-ability-wantAgent.md).

   ```ts
   import WantAgent from "@ohos.app.ability.wantAgent";
   ```

   ```ts
   // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
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

4. Listen for playback control commands delivered by the controller, for example, Media Controller.
   > **NOTE**
   >
   > After the provider registers a listener for playback control commands, the commands will be reflected in **getValidCommands()** of the controller. In other words, the controller determines that the command is valid and triggers the corresponding event as required. To ensure that the playback control commands delivered by the controller can be executed normally, the provider should not use a null implementation for listening.
   
   ```ts
   async setListenerForMesFromController() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
     // Generally, logic processing on the player is implemented in the listener.
     // After the processing is complete, use the setter to synchronize the playback information. For details, see the code snippet above.
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

5. Obtain an **AVSessionController** object for this **AVSession** object for interaction.
   
   ```ts
   async createControllerFromSession() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
   
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

6. When the audio and video application exits and does not need to continue playback, cancel the listener and destroy the **AVSession** object.

   The code snippet below is used for canceling the listener for playback control commands:

   ```ts
   async unregisterSessionListener() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
   
     // Cancel the listener of the AVSession object.
     session.off('play');
     session.off('pause');
     session.off('stop');
     session.off('playNext');
     session.off('playPrevious');
   }
   ```

   The code snippet below is used for destroying the AVSession object:

   ```ts
   async destroySession() {
     // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet in step 1.
     let session: AVSessionManager.AVSession = ALLREADY_CREATE_A_SESSION;
     // Destroy the AVSession object.
     session.destroy(function (err) {
       if (err) {
         console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
       } else {
         console.info('Destroy : SUCCESS ');
       }
     });
   }
   ```
