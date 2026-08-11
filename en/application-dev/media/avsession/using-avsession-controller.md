# AVSession Controller

<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=8e770cbadeb30048762cabf5d8eefee15902d89d translatedAt=2026-08-10T03:49:01.404Z pushedAt=2026-08-10T08:28:01.685Z -->

Starting from API version 23, apps can use AVSession Kit to obtain playback information of AVSessions and control playback actions such as play and pause, enabling unified playback control over audio and video apps in the system. This document describes the API capabilities and basic development process of the AVSession controller, including obtaining metadata and playback state information from AVSession providers, as well as sending commands and events to AVSession providers to control their playback, pause, and other actions.

## Fundamental Concepts

- [AVSession provider](using-avsession-developer.md): When implementing audio and video features, an audio/video app must connect to the AVSession as an AVSession provider and respond to playback control commands sent by the AVSession controller.

- AVSession descriptor (`AVSessionDescriptor`): session information, including the session ID, session type (audio/video), custom session name (`sessionTag`), information about the corresponding application (`elementName`), and whether the session is pinned on top (`isTopSession`).

- AVSession controller (AVSessionController): A session controller that can be used to view session IDs, send commands and events to sessions, and obtain session metadata and playback state information.

- Top session (TopSession): The AVSession with the highest priority in the system, for example, the session that is currently playing.

## Available APIs

The key APIs used by the controller are classified into the following types:

1. Obtain AVSession descriptors and AVSession controllers, and listen for AVSession creation and destruction: called through AVSessionManager, for example, the API `AVSessionManager.createController(sessionId)`.

2. Obtain AVSession metadata and playback state information, and listen for changes to AVSession metadata and playback state: called through the AVSessionController object, for example, the API `controller.getAVPlaybackState()`.

Asynchronous JavaScript APIs use either a callback or promise to return the result. The two forms differ only in the return method and provide the same functionality.

For more API details, see the [module description](../../reference/apis-avsession-kit/arkts-apis-avsession.md) of `@ohos.multimedia.avsession`.

## How to Develop

The basic steps for an app to connect as an AVSession controller are as follows:

1. The app applies for the restricted permission [ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC](../../security/AccessToken/restricted-permissions.md#ohospermissionmanage_media_resources_for_public). Currently, only a small number of apps that meet specific scenarios can use restricted permissions after approval. For details about the application method, see [Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md).

2. Listen for AVSession creation, destruction, and changes to the currently active AVSession, and create the AVSessionController corresponding to the AVSession, so as to perform unified playback control over audio and video apps in the system.

   <!-- @[getAVSessionDescriptorsInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AVSessionController/entry/src/main/ets/feature/MediaController.ets) -->

   ``` TypeScript
   import { avSession } from '@kit.AVSessionKit';
   // ...
   
     // Obtain the AVSession descriptor and AVSession controller.
     async getAVSessionDescriptorsInfo(): Promise<void> {
       try {
         // Obtain descriptor information for all sessions that have set media information and registered control callbacks.
         avSession.getAllSessionDescriptors().then(async (descriptors: avSession.AVSessionDescriptor[]) => {
           Log.info(TAG, 'Succeeded in getting all session descriptors, length: ' + descriptors.length);
           if (descriptors.length > 0) {
             avSession.createController(descriptors[0].sessionId).then(
               async (controller: avSession.AVSessionController) => {
               this.currentController = controller;
               this.currentControllerLink?.set(controller);
               await this.getControllerInfo();
               await this.listenControllerInfo();
               await this.getAVSessionValidCommands();
             });
           }
         });
   
         // Listen for the event of the latest playback session change.
         avSession.onTopSessionChange(async (descriptor: avSession.AVSessionDescriptor) => {
           Log.info(TAG, 'on topSessionChange : sessionTag: ' + descriptor.sessionTag);
           avSession.createController(descriptor.sessionId).then(async (controller: avSession.AVSessionController) => {
             this.currentController = controller;
             this.currentControllerLink?.set(controller);
             await this.getControllerInfo();
             await this.listenControllerInfo();
             await this.getAVSessionValidCommands();
           });
         });
   
         // Listen for session creation events.
         avSession.onSessionCreate((descriptor: avSession.AVSessionDescriptor) => {
           Log.info(TAG, 'on sessionCreate: sessionTag: ' + descriptor.sessionTag);
         });
   
         // Listen for session destruction events.
         avSession.onSessionDestroy((descriptor: avSession.AVSessionDescriptor) => {
           Log.info(TAG, 'on sessionDestroy: ' + descriptor.sessionTag);
         });
       } catch (error) {
         if (error) {
           console.error(`avSession Error: Code: ${error.code}, message: ${error.message}`);
         }
       }
     }
   ```

3. Obtain the current track and playback state delivered by the AVSession provider.

   <!-- @[getControllerInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AVSessionController/entry/src/main/ets/feature/MediaController.ets) -->

   ``` TypeScript
   async getControllerInfo(): Promise<void> {
     // Obtain the session metadata.
     this.currentController?.getAVMetadata((error: BusinessError, metadata: avSession.AVMetadata) => {
       if (error) {
         Log.info(TAG, 'Failed to get AV metadata, code: ' + error.code + ', message: ' + error.message);
         return;
       }
       Log.info(TAG, 'Succeeded in getting AV metadata, assetId: ' + metadata.assetId);
       if (metadata?.mediaImage && metadata?.title && metadata?.artist) {
         this.metaDataLink?.set(metadata);
       }
     });
   
     // Obtain the playback state.
     this.currentController?.getAVPlaybackState((error: BusinessError, state: avSession.AVPlaybackState) => {
       if (error) {
         Log.info(TAG, 'Failed to get AV playback state, code: ' + error.code + ', message: ' + error.message);
         return;
       }
       Log.info(TAG, 'Succeeded in getting AV playback state.');
       this.playbackStateLink?.set(state?.state);
     });
   
     // ...
   }
   ```

4. Listen for media information changes and other session events from the AVSession provider, so that the app can refresh the current track and playback state in a timely manner based on the callbacks.

   <!-- @[listenControllerInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AVSessionController/entry/src/main/ets/feature/MediaController.ets) -->

   ``` TypeScript
   async listenControllerInfo(): Promise<void> {
     try {
       // Set the listener for metadata changes.
       this.currentController?.on('metadataChange', 'all', (metadata: avSession.AVMetadata) => {
         Log.info(TAG, 'on metadataChange assetId: ' + metadata.assetId);
         if (metadata?.mediaImage && metadata?.title && metadata?.artist) {
           this.metaDataLink?.set(metadata);
         }
       });
   
       // Set the listener for playback state changes.
       this.currentController?.on('playbackStateChange', ['state'], (playbackState: avSession.AVPlaybackState) => {
         Log.info(TAG, 'on playbackStateChange state: ' + playbackState.state);
         this.playbackStateLink?.set(playbackState.state);
       });
   
       // ...
     } catch (error) {
       if (error) {
         console.error(`listenControllerInfo Error: Code: ${error.code}, message: ${error.message}`);
       }
     }
   }
   ```

5. Obtain the valid commands supported by the session, so that the app can perceive the commands supported by the AVSession provider.

   <!-- @[getAVSessionValidCommands](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AVSessionController/entry/src/main/ets/feature/MediaController.ets) -->

   ``` TypeScript
   async getAVSessionValidCommands(): Promise<void> {
     try {
       // Obtain the valid commands supported by the session.
       this.currentController?.getValidCommands((error: BusinessError,
         validCommands: avSession.AVControlCommandType[]) => {
         if (error) {
           Log.info(TAG, 'Failed to get valid commands, code: ' + error.code + ', message: ' + error.message);
           return;
         }
         Log.info(TAG, 'Succeeded in getting valid commands, size: ' + validCommands.length);
         this.validCommandsLink?.set(validCommands);
       });
   
       // Listener event for changes to valid commands supported by the session.
       this.currentController?.on('validCommandChange', (validCommands: avSession.AVControlCommandType[]) => {
         Log.info(TAG, 'Succeeded in valid command change, size: ' + validCommands.length);
         this.validCommandsLink?.set(validCommands);
       });
     } catch (error) {
       if (error) {
         console.error(`validCommand Error: Code: ${error.code}, message: ${error.message}`);
       }
     }
   }
   ```

6. Control the playback behavior, for example, sending a command to operate (play/pause/previous/next) the item being played.

   <!-- @[commands](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AVSessionController/entry/src/main/ets/pages/PresentPage.ets) -->

   ``` TypeScript
   changeCallback() {
     this.canPlay = !!this.validCommands?.includes('play');
     this.canPause = !!this.validCommands?.includes('pause');
     this.canNext = !!this.validCommands?.includes('playNext');
     this.canPrevious = !!this.validCommands?.includes('playPrevious');
   }
   
   @Builder
   commandBuild() {
     Image($r('app.media.previous'))
       .width('24vp').height('24vp')
       .id('Previous')
       .onClick(async () => {
         if (this.canPrevious) {
           let command: avSession.AVControlCommand = {
             command: 'playPrevious', // Switch to the previous track.
           }
           await this.currentController?.sendControlCommand(command);
           Log.info(TAG, 'on previous click');
         }
       })
     Image(this.playbackState == avSession.PlaybackState.PLAYBACK_STATE_PLAY ? $r('app.media.stopmusic') : $r('app.media.playmusic'))
       .width('24vp')
       .height('24vp')
       .id('PlayOrPause:')
       .onClick(async () => {
         if (this.playbackState == avSession.PlaybackState.PLAYBACK_STATE_PLAY) {
           if (this.canPause) {
             let command: avSession.AVControlCommand = {
               command: 'pause', // Pause playback.
             }
             await this.currentController?.sendControlCommand(command);
           }
         } else {
           if (this.canPlay) {
             let command: avSession.AVControlCommand = {
               command: 'play', // Start playback.
             }
             await this.currentController?.sendControlCommand(command);
           }
         }
         Log.info(TAG, 'on play/pause click');
       })
     Image($r('app.media.next'))
       .width('24vp').height('24vp')
       .id('Next')
       .onClick(async () => {
         if (this.canNext) {
           let command: avSession.AVControlCommand = {
             command: 'playNext', // Switch to the next track.
           }
           await this.currentController?.sendControlCommand(command);
           Log.info(TAG, 'on next click ');
         }
       })
   }
   ```

7. When the AVSession exits, the AVSession controller must promptly cancel listening and release resources.

   <!-- @[listenAVSessionDestroy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AVSessionController/entry/src/main/ets/feature/MediaController.ets) -->

   ``` TypeScript
   async listenAVSessionDestroy(): Promise<void> {
     try {
       // Register a listener for session destruction.
       this.currentController?.on('sessionDestroy', () => {
         Log.info(TAG, 'on sessionDestroy: SUCCESS');
         this.currentController?.destroy(() => { // Destroy the current controller. After destruction, the controller can no longer be used.
           Log.info(TAG, 'Succeeded in destroying.');
         });
       });
     } catch (error) {
       if (error) {
         console.error(`destroy Error: Code: ${error.code}, message: ${error.message}`);
       }
     }
   }
   
   stopControl() {
     Log.info(TAG, 'stopControl');
     avSession.offSessionCreate();
     avSession.offTopSessionChange();
     Log.info(TAG, 'stopControl done');
   }
   ```