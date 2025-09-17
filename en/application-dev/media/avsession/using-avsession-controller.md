# AVSession Controller (for System Applications Only)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

Media Controller preset in OpenHarmony functions as the controller to interact with audio and video applications, for example, obtaining and displaying media information and delivering playback control commands.

You can develop a system application (for example, a new playback control center or voice assistant) as the controller to interact with audio and video applications in the system.

## Basic Concepts

- AVSessionDescriptor: session information, including the session ID, session type (audio/video), custom session name (**sessionTag**), information about the corresponding application (**elementName**), and whether the session is pined on top (isTopSession).

- Top session: session with the highest priority in the system, for example, a session that is being played. Generally, the controller must hold an AVSessionController object to communicate with a session. However, the controller can directly communicate with the top session, for example, directly sending a playback control command or key event, without holding an AVSessionController object.

## Available APIs

The key APIs used by the controller are classified into the following types:

1. APIs called by the AVSessionManager object, which is obtained by means of import. An example API is **AVSessionManager.createController(sessionId)**.
2. APIs called by the AVSessionController object. An example API is **controller.getAVPlaybackState()**.

Asynchronous JavaScript APIs use either a callback or promise to return the result. The APIs listed below use a callback. They provide the same functions as their counterparts that use a promise.

For details, see [AVSession Management](../../reference/apis-avsession-kit/arkts-apis-avsession.md).

### APIs Called by the AVSessionManager Object

| API| Description| 
| -------- | -------- |
| getAllSessionDescriptors(callback: AsyncCallback&lt;Array&lt;Readonly&lt;AVSessionDescriptor&gt;&gt;&gt;): void | Obtains the descriptors of all AVSessions in the system.| 
| createController(sessionId: string, callback: AsyncCallback&lt;AVSessionController&gt;): void | Creates an AVSessionController.| 
| sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback&lt;void&gt;): void | Sends a key event to the top session.|  
| sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback&lt;void&gt;): void | Sends a playback control command to the top session.| 
| getHistoricalSessionDescriptors(maxSize: number, callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void<sup>10+<sup> | Obtains the descriptors of historical sessions.|

### APIs Called by the AVSessionController Object

| API| Description|
| -------- | -------- |
| getAVPlaybackState(callback: AsyncCallback&lt;AVPlaybackState&gt;): void<sup>10+<sup> | Obtains the information related to the playback state.|
| getAVMetadata(callback: AsyncCallback&lt;AVMetadata&gt;): void<sup>10+<sup> | Obtains the session metadata.|
| getOutputDevice(callback: AsyncCallback&lt;OutputDeviceInfo&gt;): void<sup>10+<sup> | Obtains the output device information.|
| sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sends a key event to the session corresponding to this controller.|
| getLaunchAbility(callback: AsyncCallback&lt;WantAgent&gt;): void<sup>10+<sup> | Obtains the WantAgent object saved by the application in the session.|
| isActive(callback: AsyncCallback&lt;boolean&gt;): void<sup>10+<sup> | Checks whether the session is activated.|
| destroy(callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Destroys this controller. A controller can no longer be used after being destroyed.|
| getValidCommands(callback: AsyncCallback&lt;Array&lt;AVControlCommandType&gt;&gt;): void<sup>10+<sup> | Obtains valid commands supported by the session.|
| sendControlCommand(command: AVControlCommand, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sends a playback control command to the session through the controller.|
| sendCommonCommand(command: string, args: {[key: string]: Object}, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sends a custom playback control command to the session through the controller.|
| getAVQueueItems(callback: AsyncCallback&lt;Array&lt;AVQueueItem&gt;&gt;): void<sup>10+<sup> | Obtains the information related to the items in the playlist.|
| getAVQueueTitle(callback: AsyncCallback&lt;string&gt;): void<sup>10+<sup> | Obtains the name of the playlist.|
| skipToQueueItem(itemId: number, callback: AsyncCallback&lt;void&gt;): void<sup>10+<sup> | Sends the ID of an item in the playlist to the session for processing. The session can play the song.|
| getExtras(callback: AsyncCallback&lt;{[key: string]: Object}&gt;): void<sup>10+<sup> | Obtains the custom media packet set by the provider.|
| getOutputDeviceSync(): OutputDeviceInfo<sup>10+<sup> | Obtains the output device information. This API returns the result synchronously.|
| getAVPlaybackStateSync(): AVPlaybackState<sup>10+<sup> | Obtains the information related to the playback state. This API returns the result synchronously.|
| getAVMetadataSync(): AVMetadata<sup>10+<sup> | Obtains the session metadata. This API returns the result synchronously.|
| getAVQueueTitleSync(): string<sup>10+<sup> | Obtains the name of the playlist. This API returns the result synchronously.|
| getAVQueueItemsSync(): Array&lt;AVQueueItem&gt;<sup>10+<sup> | Obtains the information related to the items in the playlist. This API returns the result synchronously.|
| isActiveSync(): boolean<sup>10+<sup> | Checks whether the session is activated. This API returns the result synchronously.|
| getValidCommandsSync(): Array&lt;AVControlCommandType&gt;<sup>10+<sup> | Obtains valid commands supported by the session. This API returns the result synchronously.|

## How to Develop

To enable a system application to access the AVSession service as a controller, proceed as follows:

1. Obtain AVSessionDescriptor through AVSessionManager and create an AVSessionController object.

   The controller may obtain all AVSessionDescriptors in the current system, and create an AVSessionController object for each session, so as to perform unified playback control on all the audio and video applications.

   ```ts
   // Import the AVSessionManager module.
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   // Define global variables.
   let g_controller = new Array<AVSessionManager.AVSessionController>();
   let g_centerSupportCmd:Set<AVSessionManager.AVControlCommandType> = new Set(['play', 'pause', 'playNext', 'playPrevious', 'fastForward', 'rewind', 'seek','setSpeed', 'setLoopMode', 'toggleFavorite']);
   let g_validCmd:Set<AVSessionManager.AVControlCommandType>;
   // Obtain the session descriptors and create an AVSessionController object.
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

   // Obtain the descriptors of historical sessions.
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

2. Listen for the session state and service state events.

   The following session state events are available:

   - **sessionCreate**: triggered when a session is created.
   - **sessionDestroy**: triggered when a session is destroyed.
   - **topSessionChange**: triggered when the top session is changed.

   The service state event **sessionServiceDie** is reported when the AVSession service is abnormal.

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let g_controller = new Array<AVSessionManager.AVSessionController>();
   // Subscribe to the 'sessionCreate' event and create an AVSessionController object.
   AVSessionManager.on('sessionCreate', (session) => {
     // After an AVSession is added, you must create an AVSessionController object.
     AVSessionManager.createController(session.sessionId).then((controller) => {
       g_controller.push(controller);
     }).catch((err: BusinessError) => {
       console.error(`Failed to create controller. Code: ${err.code}, message: ${err.message}`);
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
     console.info(`Server exception.`);
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
   - **sessionEvent**: triggered when the custom session event changes.
   - **extrasChange**: triggered when the custom media packet of the session changes.
   - **queueItemsChange**: triggered when one or more items in the custom playlist of the session changes.
   - **queueTitleChange**: triggered when the custom playlist name of the session changes.

   The controller can listen for events as required.

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let g_controller = new Array<AVSessionManager.AVSessionController>();
   if (g_controller && g_controller.length > 0 && g_controller[0]) {
    let controller = g_controller[0];
    let g_validCmd:Set<AVSessionManager.AVControlCommandType>;
    let g_centerSupportCmd:Set<AVSessionManager.AVControlCommandType> = new Set(['play', 'pause', 'playNext', 'playPrevious', 'fastForward', 'rewind', 'seek','setSpeed', 'setLoopMode', 'toggleFavorite']);
    // Subscribe to the 'activeStateChange' event.
    controller.on('activeStateChange', (isActive) => {
      if (isActive) {
        console.info(`The widget corresponding to the controller is highlighted.`);
      } else {
        console.info(`The widget corresponding to the controller is invalid.`);
      }
    });
    // Subscribe to the 'sessionDestroy' event to enable the controller to get notified when the session dies.
    controller.on('sessionDestroy', () => {
      console.info(`on sessionDestroy : SUCCESS `);
      controller.destroy().then(() => {
        console.info(`destroy : SUCCESS`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to destroy session. Code: ${err.code}, message: ${err.message}`);
      });
    });

    // Subscribe to metadata changes.
    controller.on('metadataChange', ['assetId', 'title', 'description'], (metadata: AVSessionManager.AVMetadata) => {
      console.info(`on metadataChange assetId : ${metadata.assetId}`);
    });
    // Subscribe to playback state changes.
    controller.on('playbackStateChange', ['state', 'speed', 'loopMode'], (playbackState: AVSessionManager.AVPlaybackState) => {
      console.info(`on playbackStateChange state : ${playbackState.state}`);
    });
    // Subscribe to supported command changes.
    controller.on('validCommandChange', (cmds) => {
      console.info(`validCommandChange : SUCCESS : size : ${cmds.length}`);
      console.info(`validCommandChange : SUCCESS : cmds : ${Array.from(cmds)}`);
      g_validCmd.clear();
      let centerSupportCmd = Array.from(g_centerSupportCmd.values())
      for (let c of centerSupportCmd) {
        if (cmds.indexOf(c) != -1) {
          g_validCmd.add(c);
        }
      }
    });
    // Subscribe to output device changes.
    controller.on('outputDeviceChange', (state, device) => {
      console.info(`outputDeviceChange device are : ${JSON.stringify(device)}`);
    });
    // Subscribe to custom session event changes.
    controller.on('sessionEvent', (eventName, eventArgs) => {
      console.info(`Received new session event, event name is ${eventName}, args are ${JSON.stringify(eventArgs)}`);
    });
    // Subscribe to custom media packet changes.
    controller.on('extrasChange', (extras) => {
      console.info(`Received custom media packet, packet data is ${JSON.stringify(extras)}`);
    });
    // Subscribe to custom playlist item changes.
    controller.on('queueItemsChange', (items) => {
      console.info(`Caught queue items change, items length is ${items.length}`);
    });
    // Subscribe to custom playback name changes.
    controller.on('queueTitleChange', (title) => {
      console.info(`Caught queue title change, title is ${title}`);
    });
   }
   ```

4. Obtain the media information transferred by the provider for display on the UI, for example, displaying the track being played and the playback state in Media Controller.
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   async function getInfoFromSessionByController() {
     // It is assumed that an AVSessionController object corresponding to the session already exists. For details about how to create an AVSessionController object, see the code snippet above.
     let controller = await AVSessionManager.createController("");
     // Obtain the session ID.
     let sessionId = controller.sessionId;
     console.info(`get sessionId by controller : isActive : ${sessionId}`);
     // Obtain the activation state of the session.
     let isActive = await controller.isActive();
     console.info(`get activeState by controller : ${isActive}`);
     // Obtain the media information of the session.
     let metadata = await controller.getAVMetadata();
     console.info(`get media title by controller : ${metadata.title}`);
     console.info(`get media artist by controller : ${metadata.artist}`);
     // Obtain the playback information of the session.
     let avPlaybackState = await controller.getAVPlaybackState();
     console.info(`get playbackState by controller : ${avPlaybackState.state}`);
     console.info(`get favoriteState by controller : ${avPlaybackState.isFavorite}`);
     // Obtain the playlist items of the session.
     let queueItems = await controller.getAVQueueItems();
     console.info(`get queueItems length by controller : ${queueItems.length}`);
     // Obtain the playlist name of the session.
     let queueTitle = await controller.getAVQueueTitle();
     console.info(`get queueTitle by controller : ${queueTitle}`);
     // Obtain the custom media packet of the session.
     let extras = await controller.getExtras();
     console.info(`get custom media packets by controller : ${extras ? JSON.stringify(extras) : ''}`);
     // Obtain the ability information provided by the application corresponding to the session.
     let agent = await controller.getLaunchAbility();
     console.info(`get want agent info by controller : ${agent ? JSON.stringify(agent) : ''}`);
     // Obtain the current playback position of the session.
     let currentTime = controller.getRealPlaybackPositionSync();
     console.info(`get current playback time by controller : ${currentTime}`);
     // Obtain valid commands supported by the session.
     let validCommands = await controller.getValidCommands();
     console.info(`get valid commands by controller : ${validCommands ? JSON.stringify(validCommands) : '[]'}`);
   }
   ```

5. Control the playback behavior, for example, sending a command to operate (play/pause/previous/next) the item being played in Media Controller.
   
   After listening for the playback control command event, the audio and video application serving as the provider needs to implement the corresponding operation.

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   async function  sendCommandToSessionByController() {
     // It is assumed that an AVSessionController object corresponding to the session already exists. For details about how to create an AVSessionController object, see the code snippet above.
     let controller = await AVSessionManager.createController("");
     // Obtain valid commands supported by the session.
     let validCommandTypeArray = await controller.getValidCommands();
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
     // Deliver a custom playback control command.
     let commandName = 'custom command';
     await controller.sendCommonCommand(commandName, {command : 'This is my custom command'}).then(() => {
       console.info(`SendCommonCommand successfully`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to send common command. Code: ${err.code}, message: ${err.message}`);
     })
     // Set the ID of an item in the specified playlist for the session to play.
     let queueItemId = 0;
     await controller.skipToQueueItem(queueItemId).then(() => {
       console.info(`SkipToQueueItem successfully`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to skip to queue item. Code: ${err.code}, message: ${err.message}`);
     });
   }
   ```

6. When the audio and video application exits, cancel the listener and release the resources.
     
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   async function destroyController() {
     // It is assumed that an AVSessionController object corresponding to the session already exists. For details about how to create an AVSessionController object, see the code snippet above.
     let controller = await AVSessionManager.createController("");
     
     // Destroy the AVSessionController object. After being destroyed, it is no longer available.
     controller.destroy((err: BusinessError) => {
       if (err) {
         console.error(`Failed to destroy controller. Code: ${err.code}, message: ${err.message}`);
       } else {
         console.info(`Destroy controller SUCCESS`);
       }
     });
   }
   ```
