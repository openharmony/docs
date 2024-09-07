# Accessing AVSession

In addition to the implementation of audio and video playback, media applications may need to access AVSession provided by AVSession Kit for display and control purposes. This topic describes typical display and control scenarios of accessing AVSession.

In different access scenarios, different UIs are displayed in the controller of the system, and different specifications are posed for application access processing.

## Scenarios That Require AVSession Access

AVSession restricts background audio playback and VoIP calls. As such, applications that provide long-duration audio or video playback, audiobook applications, and VoIP applications need to access AVSession. If such an application does not access AVSession, the system stops its audio playback or mutes the ongoing call when detecting that the application is running in the background. In this way, the application behavior is restricted. You can verify the restriction locally before the application is released.

For applications that may use audio playback, such as gaming and live broadcast applications, accessing AVSession is optional. However, if they want to continue audio playback after switching to the background, they must access AVSession.

To implement background playback, the application must also use [Background Tasks Kit](../../task-management/background-task-overview.md) to request a continuous task to avoid being suspended.

## Access Process

The process for implementing AVSession access is as follows:

1. Determine the type of AVSession to be created for the application, and then [create one](#creating-avsession). The AVSession type determines the style of the control template displayed in the controller.
2. [Create a background task](#creating-a-background-task).
3. [Set necessary metadata](#setting-metadata), which is the response information displayed in the controller. The metadata includes the IDs of the current media asset (assetId), previous media asset (previousAssetId), and next media asset (nextAssetId), title, author, album, writer, and duration.
4. [Set playback state information](#setting-playback-state-information). The information includes the playback state, position, speed, buffered time, loop mode, media item being played (activeItemId), custom media data (extras), and whether the media asset is favorited (isFavorite).
5. [Register control commands](#registering-control-commands). The control commands include **play**, **pause**, **previous**, **next**, **fastForward**, **rewind**, **toggleFavorite**, **setLoopMode**, and **seek**.
6. Destroy AVSession when the application exits or stops providing service.

## Creating AVSession

[AVSessionType](../../reference/apis-avsession-kit/js-apis-avsession.md#avsessiontype10) in the constructor determines the type of AVSession to create. Different AVSession types represent the control capabilities in various scenarios and display different control templates in the controller.

- For audio AVSession, the controller provides the following control buttons: favorite, previous, play/pause, next, and loop mode.

- For video AVSession, the controller provides the following control buttons: rewind, previous, play/pause, next, and fast-forward.

- For voice_call AVSession, the application is not displayed in the controller.

Refer to the code snippet below:

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';

// Start to create and activate an AVSession object.
// Create an AVSession object.
let context: Context = getContext(this);
async function createSession() {
  let type: AVSessionManager.AVSessionType = 'audio';
  let session = await AVSessionManager.createAVSession(context,'SESSION_NAME', type);

  // Call activate() after the metadata and control commands are registered.
  await session.activate();
  console.info(`session create done : sessionId : ${session.sessionId}`);
}
```

## Creating a Background Task

To implement background playback, the application must also use [Background Tasks Kit](../../task-management/background-task-overview.md) to request a continuous task to avoid being suspended.

Media playback applications must request a continuous task of the [AUDIO_PLAYBACK](../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundmode) background mode.


## Setting Metadata

### Setting Common Metadata

The application can call **setAVMetadata()** to set AVSession metadata to the system so that the metadata can be displayed in the controller. The metadata includes the IDs of the current media asset (assetId), previous media asset (previousAssetId), and next media asset (nextAssetId), title, author, album, writer, and duration.

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: Context = getContext(this);
async function setSessionInfo() {
  // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
  let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');
  // Set necessary AVSession metadata.
  let metadata: AVSessionManager.AVMetadata = {
    assetId: '0', // Specified by the application, used to identify the media asset in the application media library.
    title: 'TITLE',
    mediaImage: 'IMAGE',
    artist: 'ARTIST',
  };
  session.setAVMetadata(metadata).then(() => {
    console.info(`SetAVMetadata successfully`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
  });
 }
```

### Setting Lyrics

The controller provides the UI to show lyrics. The application only needs to set the lyrics content. The controller parses the lyrics content and displays it based on the playback progress.

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: Context = getContext(this);
async function setListener() {
  // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
  let type: AVSessionManager.AVSessionType = 'audio';
  let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

  // Set the lyric to AVSession.
  let metadata: AVSessionManager.AVMetadata = {
    assetId: '0',
    title: 'TITLE',
    mediaImage: 'IMAGE',
    // The LRC contains two types of elements: time tag + lyrics, and ID tag.
    // Example: [00:25.44]xxx\r\n[00:26.44]xxx\r\n
    lyric: "Lyrics in LRC format",
  };
  session.setAVMetadata(metadata).then(() => {
    console.info(`SetAVMetadata successfully`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
  });

}
```

<!--RP1-->
<!--RP1End-->

### Display Tags of Media Assets

The controller displays a special type identifier for long-duration media assets. Currently, only the AudioVivid identifier is displayed.

The application notifies the system of the display tag of the media asset through the AVMetadata during the access, and the controller displays the tag when the media asset is being played.

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: Context = getContext(this);
async function setListener() {
  // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
  let type: AVSessionManager.AVSessionType = 'audio';
  let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

  // Set the media audio source information to AVSession.
  let metadata: AVSessionManager.AVMetadata = {
    assetId: '0',
    title: 'TITLE',
    mediaImage: 'IMAGE',
    // The display tag of the audio source is AudioVivid.
    displayTags: AVSessionManager.DisplayTag.TAG_AUDIO_VIVID,
  };
  session.setAVMetadata(metadata).then(() => {
    console.info(`SetAVMetadata successfully`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## Setting Playback State Information

### Setting General State Information

The application can call [setAVPlaybackState()](../../reference/apis-avsession-kit/js-apis-avsession.md#setavplaybackstate10) to set the playback state information to the system so that the information can be displayed in the controller.

Generally, the playback state information includes the playback state, position, speed, buffered time, loop mode, media item being played (activeItemId), custom media data (extras), and whether the media asset is favorited (isFavorite). It changes during the playback.

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: Context = getContext(this);
async function setSessionInfo() {
  // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
  let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');

  // The player logic that triggers changes in the AVSession metadata and playback state information is omitted here.
  // Set the playback state to paused and set isFavorite to false.
  let playbackState: AVSessionManager.AVPlaybackState = {
    state:AVSessionManager.PlaybackState.PLAYBACK_STATE_PAUSE,
    isFavorite:false
  };
  session.setAVPlaybackState(playbackState, (err: BusinessError) => {
   if (err) {
      console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`SetAVPlaybackState successfully`);
    }
  });
}
```

### Setting the Progress Bar

To display a progress bar in the controller, the application must set the duration, playback state (pause or play), playback position, and playback speed. The controller displays the progress bar based on the information.

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: Context = getContext(this);
async function setListener() {
  // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
  let type: AVSessionManager.AVSessionType = 'audio';
  let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

  // Set the media resource duration.
  let metadata: AVSessionManager.AVMetadata = {
    assetId: '0',
    title: 'TITLE',
    mediaImage: 'IMAGE',
    duration: 23000, // Duration of the media asset, in milliseconds.
  };
  session.setAVMetadata(metadata).then(() => {
    console.info(`SetAVMetadata successfully`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
  });

  // Set the playback state information, including the playback state, position, speed, and buffered time.
  let playbackState: AVSessionManager.AVPlaybackState = {
    state: AVSessionManager.PlaybackState.PLAYBACK_STATE_PLAY, // Playing state.
    position: {
      elapsedTime: 1000, // Playback position, in milliseconds.
      updateTime: new Date().getTime(), // Timestamp when the application updates the current position, in milliseconds.
    },
    speed: 1.0, // Optional. The default value is 1.0. The playback speed is set based on the speed supported by the application. The system does not verify the speed.
    bufferedTime: 14000, // Optional. Buffered time, in milliseconds.
  };
  session.setAVPlaybackState(playbackState, (err) => {
    if (err) {
      console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`SetAVPlaybackState successfully`);
    }
  });
}
```

The controller calculates the playback progress based on the information set by the application. The application does not need to update the playback progress in real time.
However, it needs to update the playback state when the following information changes to avid calculation errors:

- state
- position
- speed

The application reports the start position of the progress once the actual playback starts. If the playback is in the buffer state, the application can report **AVSessionManager.PlaybackState.PLAYBACK_STATE_BUFFERING** to instruct the system not to update the progress.

Certain special processing is required when setting the progress bar.

1. Songs that can be previewed

    (1) The application sets the preview duration, rather than the total duration, for a song. In this case, when the user performs progress control in the controller, the application receives the relative timestamp within the preview duration, rather than that within the total duration. The application needs to calculate the absolute timestamp from the very beginning of the song.
    
    (2) The application sets the total duration for a song but requires the system to provide preview, the application can report the start position of the progress when the playback starts, and report the end position when the received seek instruction is not within the preview duration. In the latter case, the playback control progress of the system rebounds.

2. Songs that do not support preview

    If a song cannot be previewed, it cannot be displayed by the application. In this case, the application should set the duration to **-1**, so the system does not display the actual duration.

3. Special contents such as ads

    For media assets with pre-roll or post-roll ads, you are advised to:
    - Set the ad duration separately.
    - Set a new duration for the actual content, to distinguish it from the ad.

## Registering Control Commands

The application can register different control commands through **on()** to implement control operations in the controller. For details, see the [API reference](../../reference/apis-avsession-kit/js-apis-avsession.md#onplay10).
> **NOTE**
>
> After an AVSession object is created, register control commands supported by the application before activating the object.

The table below lists the control commands supported by media assets.

| Control Command| Description  |
| ------  | -------------------------|
| play    | Plays the media.|
| pause    | Pauses the playback.|
| stop    | Stops the playback.|
| playNext    | Plays the next media asset.|
| playPrevious    | Plays the previous media asset.|
| fastForward    | Fast-forwards.|
| rewind    | Rewinds.|
| playFromAssetId    | Plays a media asset with a given asset ID.|
| seek    | Seeks to a playback position. |
| setSpeed    | Sets the playback speed.|
| setLoopMode    | Sets the loop mode.|
| toggleFavorite    | Favorites or unfavorites a media asset.|
| skipToQueueItem    | Selects an item in the playlist.|
| handleKeyEvent    | Sets a key event.|
| commonCommand    | Customizes a control command.|

The table below lists the control commands for calling applications.

| Control Command| Description  |
| ------  | -------------------------|
| answer    | Answers a call.|
| hangUp    | Ends a call.|
| toggleCallMute    | Mutes or unmutes a call.|

### Handling Unsupported Commands

If the application does not support a control command supported by the system, for example, the **playPrevious** command, it can use **off()** to deregister the control command. Then the controller grays out the control page accordingly, so that users know that the control command is not supported.

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';

let context: Context = getContext(this);
async function unregisterSessionListener() {
  // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
  let type: AVSessionManager.AVSessionType = 'audio';
  let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

  // Cancel the listener of the AVSession object.
  session.off('play');
  session.off('pause');
  session.off('stop');
  session.off('playNext');
  session.off('playPrevious');
}
```

### Setting Fast-Forward or Rewind

The application can call APIs to set the fast-forward or rewind intervals in three different ways. It also registers the fast-forward or rewind control command to respond to user operations.

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: Context = getContext(this);
async function unregisterSessionListener() {
  // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
  let type: AVSessionManager.AVSessionType = 'audio';
  let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

  // Set the supported fast-forward or rewind duration for AVSession.
  let metadata: AVSessionManager.AVMetadata = {
    assetId: '0', // Specified by the application, used to identify the media asset in the application media library.
    title: 'TITLE',
    mediaImage: 'IMAGE',
    skipIntervals: AVSessionManager.SkipIntervals.SECONDS_10,
  };
  session.setAVMetadata(metadata).then(() => {
    console.info(`SetAVMetadata successfully`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
  });

  session.on('fastForward', (time ?: number) => {
    console.info(`on fastForward , do fastForward task`);
    // do some tasks ···
  });
  session.on('rewind', (time ?: number) => {
    console.info(`on rewind , do rewind task`);
    // do some tasks ···
  });
}
```

### Favoriting Media Assets

To implement favoriting, a music application must call [on('toggleFavorite')](../../reference/apis-avsession-kit/js-apis-avsession.md#ontogglefavorite10) to register the **toggleFavorite** control command.

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: Context = getContext(this);
async function setListener() {
 // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
 let type: AVSessionManager.AVSessionType = 'audio';
 let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
 session.on('toggleFavorite', (assetId) => {
   console.info(`on toggleFavorite `);
   // The application receives the toggleFavorite command and favorites or unfavorites the media asset.

   // Set the new state to AVSession after the application finishes favoriting or unfavoriting.
   let playbackState: AVSessionManager.AVPlaybackState = {
     isFavorite:true,
   };
   session.setAVPlaybackState(playbackState).then(() => {
     console.info(`SetAVPlaybackState successfully`);
   }).catch((err: BusinessError) => {
     console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
   });

 });
}
```

### Setting the Loop Mode

For music applications, the controller displays control operations in loop mode by default. Currently, the system supports four fixed [loop modes](../../reference/apis-avsession-kit/js-apis-avsession.md#loopmode10), namely, shuffle, sequential playback, single loop, and playlist loop. After switching the loop mode as instructed, the application needs to report the new loop mode.

Even if the application does not support the four fixed loop modes, it must report one of them to the system.

Refer to the code snippet below:

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: Context = getContext(this);
async function setListener() {
 // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
 let type: AVSessionManager.AVSessionType = 'audio';
 let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

 // When the application starts or switches the loop mode, it sets the loop mode in use to the AVSession.
 let playBackState: AVSessionManager.AVPlaybackState = {
   loopMode: AVSessionManager.LoopMode.LOOP_MODE_SINGLE,
 };
 session.setAVPlaybackState(playBackState).then(() => {
   console.info(`set AVPlaybackState successfully`);
 }).catch((err: BusinessError) => {
   console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
 });

 // The application listens for loop mode changes.
 session.on('setLoopMode', (mode) => {
   console.info(`on setLoopMode ${mode}`);
   // After receiving the instruction for setting the loop mode, the application determines the next mode. After the switching is complete, the application reports the new loop mode through AVPlaybackState.
   let playBackState: AVSessionManager.AVPlaybackState = {
    loopMode: AVSessionManager.LoopMode.LOOP_MODE_SINGLE,
   };
   session.setAVPlaybackState(playBackState).then(() => {
     console.info(`set AVPlaybackState successfully`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
   });
 });

}
```

### Performing Progress Control

An application that supports progress display can further supports progress control. To support progress control, the application must respond to the **seek** control command. When users drag the progress bar in the controller, the application receives a callback. Refer to the code snippet below:

```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';

let context: Context = getContext(this);
async function setListener() {
 // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the node snippet above.
 let type: AVSessionManager.AVSessionType = 'audio';
 let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

 session.on('seek', (position: number) => {
   console.info(`on seek , the time is ${JSON.stringify(position)}`);

   // The seek operation may trigger a long buffering time. You can set the playback state to PLAYBACK_STATE_BUFFERING.
   let playbackState: AVSessionManager.AVPlaybackState = {
     state: AVSessionManager.PlaybackState.PLAYBACK_STATE_BUFFERING, // Buffering state.
   };
   session.setAVPlaybackState(playbackState, (err) => {
     if (err) {
       console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
     } else {
       console.info(`SetAVPlaybackState successfully`);
     }
   });

   // The application responds to the seek command and seeks to the specified position.

   // After seeking to the specified position, the application synchronizes the new position to the system.
   playbackState.state = AVSessionManager.PlaybackState.PLAYBACK_STATE_PLAY; // Playing state.
   playbackState.position = {
     elapsedTime: position, // Playback position, in milliseconds.
     updateTime: new Date().getTime(), // Timestamp when the application updates the current position, in milliseconds.
   }
   session.setAVPlaybackState(playbackState, (err) => {
     if (err) {
       console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
     } else {
       console.info(`SetAVPlaybackState successfully`);
     }
   });

 });
}
```

## Adapting to Media Notification

Currently, the system does not provide APIs for proactively sending control notifications to applications. When an application enters the playing state, the system automatically sends a notification and displays the notification in the notification center and on the lock screen.

> **NOTE**
>
> Currently, notifications are displayed for audio AVSession, but not video AVSession.
>
> The system sends playback control widgets in the notification center and on the lock screen and controls their lifecycle.
