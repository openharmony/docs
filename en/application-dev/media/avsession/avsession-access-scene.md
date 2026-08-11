# Accessing AVSession
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

In addition to implementing audio and video features, audio and video applications need to access AVSession provided by AVSession Kit. This topic uses typical cases to describe display and control scenarios for accessing AVSession, providing adaptation references for developers.

Different UIs are displayed in the system controller for different scenarios. In different scenarios, application access processing must also follow different specifications and constraints.

## Scenarios That Require AVSession Access

AVSession restricts background audio playback and VoIP calls. Therefore, applications that provide long-duration audio playback, audiobooks, long-duration video playback, and VoIP calls need to access AVSession. If such an application does not create an AVSession during these services, the system stops the corresponding audio playback or mutes the call when detecting that the application is running in the background. In this way, the application behavior is restricted. You can verify the restriction locally before the application is released.

For other applications that use audio playback, such as games and live streams, accessing AVSession is optional, depending on whether the application requires background playback. If background playback is required, AVSession access is still mandatory. Otherwise, normal service functions will be restricted.

To implement background playback, the application must also use [Background Tasks Kit](../../task-management/background-task-overview.md) to request a continuous task to avoid being suspended.

## Access Process

The process for implementing AVSession access is as follows:

1. Determine the type of AVSession to be created for the application, and then [create one](#creating-avsession). The AVSession type determines the style of the control template displayed in the controller.
2. [Create a background task](#creating-a-background-task).
3. [Set necessary metadata](#setting-metadata-information) to display corresponding information in the controller. The metadata includes but is not limited to the IDs of the current media asset (**assetId**), previous media asset (**previousAssetId**), and next media asset (**nextAssetId**), title, author, album, writer, and duration.
4. [Set playback state information](#setting-playback-state). The information includes but is not limited to the playback state (**state**), position (**position**), speed (**speed**), buffered time (**bufferedTime**), loop mode (**loopMode**), whether the media asset is favorited (**isFavorite**), media ID being played (**activeItemId**), and custom media data (**extras**).
5. [Register control commands](#control-command-processing) as required, including but not limited to play/pause, previous/next, fast-forward/rewind, favorite, loop mode, and progress bar.
6. Destroy AVSession when the application exits or stops providing service.

## Creating AVSession

[AVSessionType](../../reference/apis-avsession-kit/arkts-apis-avsession-t.md#avsessiontype10) in the constructor determines the type of AVSession to create. Different AVSession types represent the control capabilities in various scenarios and display different control templates in the controller.

- For audio AVSession, the controller provides the following control buttons: favorite, previous, play/pause, next, and loop mode.

- For video AVSession, the controller provides the following control buttons: rewind, previous, play/pause, next, and fast-forward.

- For voice_call AVSession, the application is not displayed in the controller.

Refer to the code snippet below:

> **NOTE**
>
> The sample code below demonstrates only the API call for creating an AVSession object. When actually using it, the application must ensure that the AVSession object remains throughout the application's background playback activities. This prevents the system from reclaiming or releasing it, which could lead to playback being controlled by the system.

<!-- @[createAVSession](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/CreateAVSession.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
// ...

@Entry
@Component
struct Index {
  @State message: string = 'hello world';
  // ...

  build() {
    Column() {
      // ...
      Text(this.message)
        .onClick(async () => {
          // Start to create and activate an AVSession object.
          // Create an AVSession object.
          let context = this.getUIContext().getHostContext() as Context;
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
          // Call activate() after the metadata and control commands are registered.
          await session.activate();
          console.info(`session create done : sessionId : ${session.sessionId}`);
          // ...
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## Creating a Background Task

To implement background playback, the application must also use [Background Tasks Kit](../../task-management/background-task-overview.md) to request a continuous task to avoid being suspended.

Media playback applications must request a continuous task of the [AUDIO_PLAYBACK](../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundmode) background mode.


## Setting Metadata Information

The application uses [setAVMetadata](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setavmetadata10) to set the metadata information of the current media session to the system. The system controller displays information based on the metadata set by the application.

### Metadata Information

Metadata [AVMetadata](../../reference/apis-avsession-kit/arkts-apis-avsession-i.md#avmetadata10) includes the IDs of the current media asset (**assetId**), previous media asset (**previousAssetId**), and next media asset (**nextAssetId**), title, author, album, writer, and duration.

<!-- @[setAVMetadata](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/SetAVMetadata.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

@Entry
@Component
struct Index {
  @State message: string = 'hello world';
  // ...

  build() {
    Column() {
      // ...
      Text(this.message)
        .onClick(async () => {
          try {
            let context = this.getUIContext().getHostContext() as Context;
            // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
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
              // ...
            }).catch((err: BusinessError) => {
              console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
              // ...
            });
          } catch (err) {
            if (err) {
              console.error(`AVSession create Error: Code: ${err.code}, message: ${err.message}`);
              // ...
            }
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### Setting Lyrics Field Information

Metadata [AVMetadata](../../reference/apis-avsession-kit/arkts-apis-avsession-i.md#avmetadata10) contains lyric fields. The application can set lyric fields to display lyrics in certain scenarios. Currently, two lyric fields can be set:

- **lyric**: complete lyrics of the media asset. The system controller displays lyric content based on this field. The application needs to concatenate the lyric content into a string and pass it in.

- **singleLyricText**: a single line of lyric text. The system Bluetooth module displays lyric content in certain scenarios, such as Bluetooth speakers, based on this field.

> **NOTE**
>
> - The **lyric** field supports only lyrics in LRC format, that is, timestamp plus lyric text, for example, `[00:25.44]lyric text`. If lyrics in other formats are passed in, the system controller may fail to parse them and display lyrics abnormally.
>
> - The size of each lyric string cannot exceed 40960 bytes. Otherwise, lyric information fails to be set due to system transfer limits.

<!-- @[settingLyrics](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/SettingLyrics.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

@Entry
@Component
struct Index {
  @State message: string = 'hello world';
  // ...

  build() {
    Column() {
      // ...
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          // Set the lyric to AVSession.
          let metadata: AVSessionManager.AVMetadata = {
            assetId: '0',
            title: 'TITLE',
            mediaImage: 'IMAGE',
            // The LRC contains two types of elements: time tag + lyrics, and ID tag.
            // Example: [00:25.44]xxx\r\n[00:26.44]xxx\r\n
            lyric: 'Lyrics in LRC format',
            // The singleLyricText field stores a single line of lyric text without timestamps.
            // Example: "Content of a single lyric line"
            singleLyricText: 'Content of a single lyric line',
          };
          session.setAVMetadata(metadata).then(() => {
            console.info(`SetAVMetadata successfully`);
            // ...
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
            // ...
          });
          // ...
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### Setting Progress Bar Information

The metadata [AVMetadata](../../reference/apis-avsession-kit/arkts-apis-avsession-i.md#avmetadata10) contains the **duration** field, in ms. To display the progress bar of a media asset in the controller, set the correct playback duration in **duration**.

<!-- @[settingTheProgressBar](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/SettingTheProgressBar.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

@Entry
@Component
struct Index {
  @State message: string = 'hello world';
  // ...

  build() {
    Column() {
      // ...
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
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
            // ...
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
            // ...
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
              // ...
            } else {
              console.info(`SetAVPlaybackState successfully`);
              // ...
            }
          });
          // ...
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

The system controller automatically calculates the playback progress based on the information set by the application. The application does not need to update the playback progress in real time. However, when the **state**, **position**, or **speed** changes, the application must update AVPlaybackState. Otherwise, the application state information and progress bar information displayed in the controller may be abnormal.

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

<!--RP1--><!--RP1End-->

### Display Tags of Media Assets

The metadata [AVMetadata](../../reference/apis-avsession-kit/arkts-apis-avsession-i.md#avmetadata10) provides the **displayTags** field for displaying the media asset tag, which identifies the audio source of the application. After the application sets **displayTags**, the system controller displays the tag synchronously. Currently, only the Audio Vivid tag is supported.

<!-- @[displayTagsOfMediaAssets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/DisplayTagsOfMediaAssets.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

@Entry
@Component
struct Index {
  @State message: string = 'hello world';
  // ...

  build() {
    Column() {
      // ...
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          // Set the media audio source information to AVSession.
          let metadata: AVSessionManager.AVMetadata = {
            assetId: '0',
            title: 'TITLE',
            mediaImage: 'IMAGE',
            // The media audio source is Audio Vivid.
            displayTags: AVSessionManager.DisplayTag.TAG_AUDIO_VIVID,
          };
          session.setAVMetadata(metadata).then(() => {
            console.info(`SetAVMetadata successfully`);
            // ...
          }).catch((err: BusinessError) => {
            console.error(`Failed to set AVMetadata. Code: ${err.code}, message: ${err.message}`);
            // ...
          });
          // ...
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## Setting Playback State

The application uses [setAVPlaybackState](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setavplaybackstate10) to set the playback state information of the current media session to the system. The system controller strictly displays information based on the playback state information passed by the application.

### Playback State Information

Playback state information [AVPlaybackState](../../reference/apis-avsession-kit/arkts-apis-avsession-i.md#avplaybackstate10) includes the playback state (**state**), playback position (**position**), playback speed (**speed**), buffered time (**bufferedTime**), loop mode (**loopMode**), whether the media asset is favorited (**isFavorite**), ID of the media asset being played (**activeItemId**), and custom media data (**extras**).

<!-- @[settingGeneralStateInformation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/SettingGeneralStateInformation.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

@Entry
@Component
struct Index {
  @State message: string = 'hello world';
  // ...

  build() {
    Column() {
      // ...
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');

          // Player logic that triggers changes in media information and playback state is omitted here.
          // Set the playback state to paused and set isFavorite to false.
          let playbackState: AVSessionManager.AVPlaybackState = {
            state: AVSessionManager.PlaybackState.PLAYBACK_STATE_PAUSE,
            isFavorite: false
          };
          session.setAVPlaybackState(playbackState, (err: BusinessError) => {
            if (err) {
              console.error(`Failed to set AVPlaybackState. Code: ${err.code}, message: ${err.message}`);
              // ...
            } else {
              console.info(`SetAVPlaybackState successfully`);
              // ...
            }
          });
          // ...
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## Control Command Processing

### Supported Control Commands

After an application accesses AVSession, it can register control commands through **on()** to implement the corresponding control button operations in the controller.

> **NOTE**
>
> After an AVSession object is created, register control commands supported by the application before activating the object.

The following table lists the control commands supported by audio and video applications.

| Control Command| Description  |
| ------  | -------------------------|
| [play](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onplay10)    | Play command.|
| [pause](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onpause10)    | Pause command.|
| [stop](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onstop10)    | Stop command.|
| [playNext](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onplaynext10)    | Play next command.|
| [playPrevious](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onplayprevious10)    | Play previous command.|
| [fastForward](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onfastforward10)    | Fast-forward command.|
| [rewind](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onrewind10)    | Rewind command.|
| [playWithAssetId](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onplaywithassetid20)    | Plays a media asset based on a specified asset ID.|
| [seek](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onseek10)    | Seek command.|
| [setSpeed](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onsetspeed10)    | Set playback speed command.|
| [setLoopMode](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onsetloopmode10)    | Set loop mode command.|
| [toggleFavorite](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#ontogglefavorite10)    | Sets whether a media asset is favorited.|
| [skipToQueueItem](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onskiptoqueueitem10)    | Selects an item in the playlist for playback.|
| [handleKeyEvent](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onhandlekeyevent10)    | Sets a key event command.|
| [commonCommand](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#oncommoncommand10)    | Sets a custom control command.|

The following table lists the control commands supported by call applications.

| Control Command| Description  |
| ------  | -------------------------|
| [answer](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onanswer11)    | Answer call command.|
| [hangUp](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onhangup11)    | Hang up call command.|
| [toggleCallMute](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#ontogglecallmute11)    | Mutes or unmutes a call.|

### Handling Unsupported Control Commands

If the application does not support certain control command operations, for example, the **playPrevious** command, it can use **off()** to deregister the corresponding control command. The system controller then grays out or hides the corresponding control button to clearly inform users that the application does not support this control operation.

<!-- @[handing_unSupported](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/HandlingUnsupportedCommands.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          // Cancel the listener of the AVSession object.
          session.off('play');
          session.off('pause');
          session.off('stop');
          session.off('playNext');
          session.off('playPrevious');
          // ...
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### Fast-Forward/Rewind

The application can call APIs to set the fast-forward/rewind intervals in three different ways. It also registers the fast-forward/rewind control command to respond to user operations.

> **NOTE**
>
> When applications register commands for fast-forward/rewind and next/previous track switching, there are differences in the display on the controller.

- When **AVSessionType** is **audio**:

  | Registered Event Combination| Controller Buttons| Button Availability|
  | ------------ | ------------ | ------------ |
  | No events registered| **Previous**, **Next**| All buttons are unavailable.|
  | Previous/Next events registered| **Previous**, **Next**| If previous events registered, the **Previous** button is available.<br>If next events registered, the **Next** button is available.<br>Buttons corresponding to unregistered events are unavailable. |
  | Fast-forward/rewind events registered| **Previous**, **Next**|  All buttons are unavailable.|
  | Previous/Next and fast-forward/rewind events registered| **Previous**, **Next**| If previous events registered, the **Previous** button is available.<br>If next events registered, the **Next** button is available.<br>Buttons corresponding to unregistered events are unavailable. |

- When **AVSessionType** is **video**:

  | Registered Event Combination| Controller Buttons| Button Availability|
  | ------------ | ------------ | ------------ |
  | No events registered| **Fast-Forward**, **Rewind**| All buttons are unavailable.|
  | Previous/Next events registered| **Previous**, **Next**| If previous events registered, the **Previous** button is available.<br>If next events registered, the **Next** button is available.<br>Buttons corresponding to unregistered events are unavailable. |
  | Fast-forward/rewind events registered| **Fast-Forward**, **Rewind**|  If fast-forward events are registered, the **Fast-Forward** button is available.<br>If rewind events are registered, the **Rewind** button is available.<br>Buttons corresponding to unregistered events are unavailable.|
  | Previous/Next and fast-forward/rewind events registered| **Fast-Forward**, **Rewind**|  If fast-forward events are registered, the **Fast-Forward** button is available.<br>If rewind events are registered, the **Rewind** button is available.<br>Buttons corresponding to unregistered events are unavailable.|

  <!-- @[settingFastForward](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/SettingFastForward.ets) -->

  ``` TypeScript
  import { avSession as AVSessionManager } from '@kit.AVSessionKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  // ...

  @Entry
  @Component
  struct Index {
    @State message: string = 'hello world';

    build() {
      Column() {
        Text(this.message)
          .onClick(async () => {
            let context = this.getUIContext().getHostContext() as Context;
            // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
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

            session.on('fastForward', (time?: number) => {
              console.info(`on fastForward , do fastForward task`);
              // Do some tasks.
            });
            session.on('rewind', (time?: number) => {
              console.info(`on rewind , do rewind task`);
              // Do some tasks.
            });
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

### Favoriting Media Assets

To implement favoriting, a music application must call [on('toggleFavorite')](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#ontogglefavorite10) to register the **toggleFavorite** control command.

<!-- @[toggleFavorite_mediaAssets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/FavoritingMediaAssets.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
          session.on('toggleFavorite', (assetId) => {
            console.info(`on toggleFavorite `);
            // The application receives the toggleFavorite command and favorites or unfavorites the media asset.

            // Set the new state to AVSession after the application finishes favoriting or unfavoriting.
            let playbackState: AVSessionManager.AVPlaybackState = {
              isFavorite: true,
            };
            session.setAVPlaybackState(playbackState).then(() => {
              console.info(`SetAVPlaybackState successfully`);
            }).catch((err: BusinessError) => {
              console.error(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
            });
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### Implementing Loop Mode

For music applications, the system controller displays loop mode control operations by default. Currently, the system supports four fixed loop mode controls. For details, see [LoopMode](../../reference/apis-avsession-kit/arkts-apis-avsession-e.md#loopmode10).

The controller supports switching between four fixed loop modes: shuffle, sequential playback, single loop, and playlist loop. After the application receives the loop mode switching command and completes the switching, it needs to report the switched LoopMode to the system.

If the LoopMode supported by the application is not one of the four fixed loop modes of the system, select one of the four fixed loop modes to report to the system. The mapping is customized by the application.

Refer to the code snippet below:

<!-- @[settingTheLoopMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/SettingTheLoopMode.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
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
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### Performing Progress Control

An application that supports progress display can further support progress control. To support progress control, the application must respond to the **seek** control command. When users drag the progress bar in the controller, the application receives a callback. Refer to the code snippet below:

<!-- @[performingProgressControl](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/PerformingProgressControl.ets) -->

``` TypeScript
import { avSession as AVSessionManager } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context = this.getUIContext().getHostContext() as Context;
          // It is assumed that an AVSession object has been created. For details about how to create an AVSession object, see the preceding example.
          let type: AVSessionManager.AVSessionType = 'audio';
          let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);

          session.on('seek', (time: number) => {
            console.info(`on seek , the time is ${time}`);

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
              elapsedTime: time, // Playback position, in milliseconds.
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
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## Adapting to Media Notification

When an application correctly accesses AVSession according to the preceding process, sets metadata information and correct playback state information, and registers control commands, the system notification and lock screen display information about the playing application when the application enters the playing state.

## Adapting to Bluetooth and Wired Key Events

After an application correctly accesses AVSession, it can listen for Bluetooth and wired headset key events by registering control commands. AVSession provides the following two implementation methods:
- Method 1 (recommended)

  Register the required control commands as needed. For details, see [Control Command Processing](#control-command-processing). Currently, the following AVSession control commands can be converted:
  | Control Command| Description  |
  | ------  | -------------------------|
  | play    | Plays the media.|
  | pause    | Pauses the playback.|
  | stop    | Stops the playback.|
  | playNext    | Plays the next media asset.|
  | playPrevious    | Plays the previous media asset.|
  | fastForward    | Fast-forwards.|
  | rewind    | Rewinds.|

  <!-- @[adaptingToBluetoothMethodOne](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/AdaptingToBluetoothMethodOne.ets) -->

  ``` TypeScript
  import { avSession as AVSessionManager } from '@kit.AVSessionKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct Index {
    @State message: string = 'hello world';

    build() {
      Column() {
        Text(this.message)
          .onClick(async () => {
            try {
              let context = this.getUIContext().getHostContext() as Context;
              let type: AVSessionManager.AVSessionType = 'audio';
              let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
              // Set the necessary media information. This step is mandatory. Otherwise, the application cannot receive control events.
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
              // Generally, logic processing on the player is implemented in the listener.
              // After the processing is complete, use the setter to synchronize the playback information. For details, see the code snippet above.
              session.on('play', () => {
                console.info(`on play , do play task`);
                // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('play') to cancel listening.
                // After the processing is complete, call setAVPlayState to report the playback state.
              });
              session.on('pause', () => {
                console.info(`on pause , do pause task`);
                // If this command is not supported, do not register it. If the command has been registered but is not used temporarily, use session.off('pause') to cancel listening.
                // After the processing is complete, call setAVPlayState to report the playback state.
              });
            } catch (err) {
              if (err) {
                console.error(`AVSession create Error: Code: ${err.code}, message: ${err.message}`);
              }
            }
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

- Method 2
  Register the [on('handleKeyEvent')](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onhandlekeyevent10) command through AVSession. This callback directly forwards media key events [KeyEvent](../../reference/apis-input-kit/js-apis-keyevent.md). The application needs to identify the key event type and respond to the event to implement the corresponding function. Currently, the following key event types can be forwarded:

  | Key Type ([KeyCode](../../reference/apis-input-kit/js-apis-keycode.md#keycode))| Description  |
  | ------  | -------------------------|
  | KEYCODE_MEDIA_PLAY_PAUSE    | Play/Pause key.|
  | KEYCODE_MEDIA_STOP    | Stop key.|
  | KEYCODE_MEDIA_NEXT    | Next key.|
  | KEYCODE_MEDIA_PREVIOUS    | Previous key.|
  | KEYCODE_MEDIA_REWIND    | Rewind key.|
  | KEYCODE_MEDIA_FAST_FORWARD    | 	Fast-forward key.|
  | KEYCODE_MEDIA_PLAY    | Play key.|
  | KEYCODE_MEDIA_PAUSE   | Pause key.|

  <!-- @[adaptingToBluetoothMethodTwo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AccessingAVSession/entry/src/main/ets/pages/AdaptingToBluetoothMethodTwo.ets) -->

  ``` TypeScript
  import { avSession as AVSessionManager } from '@kit.AVSessionKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct Index {
    @State message: string = 'hello world';

    build() {
      Column() {
        Text(this.message)
          .onClick(async () => {
            let context = this.getUIContext().getHostContext() as Context;
            let type: AVSessionManager.AVSessionType = 'audio';
            let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', type);
            // Set the necessary media information. This step is mandatory. Otherwise, the application cannot receive key events.
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
            session.on('handleKeyEvent', (event) => {
              // Parse the key code. The application must perform logic processing on the player based on the key code.
              console.info(`on handleKeyEvent, keyCode=${event.key.code}`);
            });
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

> **NOTE**
>
> 1. Both methods require the accurate configuration of media information AVMetadata and the registration of corresponding control interfaces to receive control commands and key events.
> 2. Choose either method for integration. Method 1 is recommended.

<!--RP2-->
<!--RP2End-->
