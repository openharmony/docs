# AVSession Controller

Media Controller preset in OpenHarmony functions as the controller to interact with audio and video applications, for example, obtaining and displaying media information and delivering control commands.

You can develop a system application (for example, a new playback control center or voice assistant) as the controller to interact with audio and video applications in the system.

## Basic Concepts

- AVSessionDescriptor: session information, including the session ID, session type (audio/video), custom session name (**sessionTag**), information about the corresponding application (**elementName**), and whether the session is pined on top (isTopSession).

- Top session: session with the highest priority in the system, for example, a session that is being played. Generally, the controller must hold an **AVSessionController** object to communicate with a session. However, the controller can directly communicate with the top session, for example, directly sending a control command or key event, without holding an **AVSessionController** object.

## Available APIs

The table below lists the key APIs used by the controller. The APIs use either a callback or promise to return the result. The APIs listed below use a callback. They provide the same functions as their counterparts that use a promise.

For details, see [AVSession Management](../reference/apis/js-apis-avsession.md).

| API| Description| 
| -------- | -------- |
| getAllSessionDescriptors(callback: AsyncCallback&lt;Array&lt;Readonly&lt;AVSessionDescriptor&gt;&gt;&gt;): void | Obtains the descriptors of all AVSessions in the system.| 
| createController(sessionId: string, callback: AsyncCallback&lt;AVSessionController&gt;): void | Creates an AVSessionController.| 
| getValidCommands(callback: AsyncCallback&lt;Array&lt;AVControlCommandType&gt;&gt;): void | Obtains valid commands supported by the AVSession.<br>Control commands listened by an audio and video application when it accesses the AVSession are considered as valid commands supported by the AVSession. For details, see [Provider of AVSession](using-avsession-developer.md).| 
| getLaunchAbility(callback: AsyncCallback&lt;WantAgent&gt;): void | Obtains the UIAbility that is configured in the AVSession and can be started.<br>The UIAbility configured here is started when a user operates the UI of the controller, for example, clicking a widget in Media Controller.| 
| sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback&lt;void&gt;): void | Sends a key event to an AVSession through the AVSessionController object.| 
| sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback&lt;void&gt;): void | Sends a key event to the top session.| 
| sendControlCommand(command: AVControlCommand, callback: AsyncCallback&lt;void&gt;): void | Sends a control command to an AVSession through the AVSessionController object.| 
| sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback&lt;void&gt;): void | Sends a control command to the top session.| 

## How to Develop

To enable a system application to access the AVSession service as a controller, proceed as follows:

1. Obtain **AVSessionDescriptor** through AVSessionManager and create an **AVSessionController** object.
   The controller may obtain all **AVSessionDescriptor**s in the current system, and create an **AVSessionController** object for each session, so as to perform unified playback control on all the audio and video applications.

   ```ts
   // Import the AVSessionManager module.
   import AVSessionManager from '@ohos.multimedia.avsession'; 
   
   // Define global variables.
   let g_controller = new Array<AVSessionManager.AVSessionController>();
   let g_centerSupportCmd:Set<AVSessionManager.AVControlCommandType> = new Set(['play', 'pause', 'playNext', 'playPrevious', 'fastForward', 'rewind', 'seek','setSpeed', 'setLoopMode', 'toggleFavorite']);
   let g_validCmd:Set<AVSessionManager.AVControlCommandType>;
   // Obtain the session descriptors and create an AVSessionController object.
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

2. Listen for the session state and service state events.
   
   The following session state events are available:

   - **sessionCreate**: triggered when a session is created.
   - **sessionDestroy**: triggered when a session is destroyed.
   - **topSessionChange**: triggered when the top session is changed.

   The service state event **sessionServiceDie** is reported when the AVSession service is abnormal.

   ```ts
   // Subscribe to the 'sessionCreate' event and create an AVSessionController object.
   AVSessionManager.on('sessionCreate', (session) => {
     // After an AVSession is added, you must create an AVSessionController object.
     AVSessionManager.createController(session.sessionId).then((controller) => {
       g_controller.push(controller);
     }).catch((err) => {
       console.info(`createController : ERROR : ${err.message}`);
     });
   });
   
   // Subscribe to the 'sessionDestroy' event to enable the application to get notified when the session dies.
   AVSessionManager.on('sessionDestroy', (session) => {
      let index = g_controller.findIndex((controller) => {
          return controller.sessionId === session.sessionId;
      });
      if (index !== 0) {
          g_controller[index].destroy();
          g_controller.splice(index, 1);
      }
   });
   // Subscribe to the 'topSessionChange' event.
   AVSessionManager.on('topSessionChange', (session) => {
      let index = g_controller.findIndex((controller) => {
          return controller.sessionId === session.sessionId;
      });
      // Place the session on the top.
      if (index !== 0) {
          g_controller.sort((a, b) => {
              return a.sessionId === session.sessionId ? -1 : 0;
          });
      }
   });
   // Subscribe to the 'sessionServiceDie' event.
   AVSessionManager.on('sessionServiceDie', () => {
      // The server is abnormal, and the application clears resources.
      console.info("Server exception.");
   })
   ```

3. Subscribe to media information changes and other session events.
   
   The following media information change events are available:

   - **metadataChange**: triggered when the session metadata changes.
   - **playbackStateChange**: triggered when the playback state changes.
   - **activeStateChange**: triggered when the activation state of the session changes.
   - **validCommandChange**: triggered when the valid commands supported by the session changes.
   - **outputDeviceChange**: triggered when the output device changes.
   - **sessionDestroy**: triggered when a session is destroyed.

   The controller can listen for events as required.

   ```ts
   // Subscribe to the 'activeStateChange' event.
   controller.on('activeStateChange', (isActive) => {
     if (isActive) {
       console.info("The widget corresponding to the controller is highlighted.");
     } else {
       console.info("The widget corresponding to the controller is invalid.");
     }
   });
   // Subscribe to the 'sessionDestroy' event to enable the controller to get notified when the session dies.
   controller.on('sessionDestroy', () => {
      console.info('on sessionDestroy : SUCCESS ');
      controller.destroy().then(() => {
          console.info('destroy : SUCCESS ');
      }).catch((err) => {
          console.info(`destroy : ERROR :${err.message}`);
      });
   });
   
   // Subscribe to metadata changes.
   let metaFilter = ['assetId', 'title', 'description'];
   controller.on('metadataChange', metaFilter, (metadata) => {
      console.info(`on metadataChange assetId : ${metadata.assetId}`);
   });
   // Subscribe to playback state changes.
   let playbackFilter = ['state', 'speed', 'loopMode'];
   controller.on('playbackStateChange', playbackFilter, (playbackState) => {
      console.info(`on playbackStateChange state : ${playbackState.state}`);
   });
   // Subscribe to supported command changes.
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
   // Subscribe to output device changes.
   controller.on('outputDeviceChange', (device) => {
      console.info(`on outputDeviceChange device isRemote : ${device.isRemote}`);
   });
   ```

4. Obtain the media information transferred by the provider for display on the UI, for example, displaying the track being played and the playback state in Media Controller.
     
   ```ts
   async getInfoFromSessionByController() {
     // It is assumed that an AVSessionController object corresponding to the session already exists. For details about how to create an AVSessionController object, see the code snippet above.
     let controller: AVSessionManager.AVSessionController = ALLREADY_HAVE_A_CONTROLLER;
     // Obtain the session ID.
     let sessionId: string = controller.sessionId;
     console.info(`get sessionId by controller : isActive : ${sessionId}`);
     // Obtain the activation state of the session.
     let isActive: boolean = await controller.isActive();
     console.info(`get activeState by controller : ${isActive}`);
     // Obtain the media information of the session.
     let metadata: AVSessionManager.AVMetadata = await controller.getAVMetadata();
     console.info(`get media title by controller : ${metadata.title}`);
     console.info(`get media artist by controller : ${metadata.artist}`);
     // Obtain the playback information of the session.
     let avPlaybackState: AVSessionManager.AVPlaybackState = await controller.getAVPlaybackState();
     console.info(`get playbackState by controller : ${avPlaybackState.state}`);
     console.info(`get favoriteState by controller : ${avPlaybackState.isFavorite}`);
   }
   ```

5. Control the playback behavior, for example, sending a command to operate (play/pause/previous/next) the item being played in Media Controller.
   
   After listening for the control command event, the audio and video application serving as the provider needs to implement the corresponding operation.

     
   ```ts
   async sendCommandToSessionByController() {
     // It is assumed that an AVSessionController object corresponding to the session already exists. For details about how to create an AVSessionController object, see the code snippet above.
     let controller: AVSessionManager.AVSessionController = ALLREADY_HAVE_A_CONTROLLER;
     // Obtain the commands supported by the session.
     let validCommandTypeArray: Array<AVSessionManager.AVControlCommandType> = await controller.getValidCommands();
     console.info(`get validCommandArray by controller : length : ${validCommandTypeArray.length}`);
     // Deliver the 'play' command.
     // If the 'play' command is valid, deliver it. Normal sessions should provide and implement the playback.
     if (validCommandTypeArray.indexOf('play') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'play'};
       controller.sendControlCommand(avCommand);
     }
     // Deliver the 'pause' command.
     if (validCommandTypeArray.indexOf('pause') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'pause'};
       controller.sendControlCommand(avCommand);
     }
     // Deliver the 'playPrevious' command.
     if (validCommandTypeArray.indexOf('playPrevious') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'playPrevious'};
       controller.sendControlCommand(avCommand);
     }
     // Deliver the 'playNext' command.
     if (validCommandTypeArray.indexOf('playNext') >= 0) {
       let avCommand: AVSessionManager.AVControlCommand = {command:'playNext'};
       controller.sendControlCommand(avCommand);
     }
   }
   ```

6. When the audio and video application exits, cancel the listener and release the resources.
     
   ```ts
   async destroyController() {
     // It is assumed that an AVSessionController object corresponding to the session already exists. For details about how to create an AVSessionController object, see the code snippet above.
     let controller: AVSessionManager.AVSessionController = ALLREADY_HAVE_A_CONTROLLER;
   
     // Destroy the AVSessionController object. After being destroyed, it is no longer available.
     controller.destroy(function (err) {
       if (err) {
         console.info(`Destroy controller ERROR : code: ${err.code}, message: ${err.message}`);
       } else {
         console.info('Destroy controller SUCCESS');
       }
     });
   }
   ```
