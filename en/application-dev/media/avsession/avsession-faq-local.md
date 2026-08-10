# Local Media Session FAQs

<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=cd52fabbe6a7dffbf6bd4bde88d3fc0bbc62f827 translatedAt=2026-08-10T03:47:36.096Z pushedAt=2026-08-10T14:18:12.803Z -->

This document summarizes typical issues encountered by audio and video apps during local media session integration with [AVSession Kit](avsession-overview.md), along with their diagnosis and resolution methods. You can use [AVSession management error codes](../../reference/apis-avsession-kit/errorcode-avsession.md) and HiLog logs to further diagnose issues.

## AVSession Creation Failure

**Symptom**

An exception is thrown when [createAVSession](../../reference/apis-avsession-kit/arkts-apis-avsession-f.md#avsessioncreateavsession10) is called, and the session is not created successfully.

**Possible Causes**

- Duplicate creation of an AVSession session object. Only one AVSession session object can exist in a process.

- In scenarios where AVSession objects are frequently created and destroyed, the old session may not have been fully destroyed. The destroy call is an asynchronous process. If the app creates a new AVSession immediately after calling destroy, the new session creation may fail because the previous session has not been completely destroyed.

- The context input parameter is invalid. The context parameter of createAVSession must use a valid context of the app.

- The `type` parameter value is invalid. `type` must be a value defined in [AVSessionType](../../reference/apis-avsession-kit/arkts-apis-avsession-t.md#avsessiontype10) (`audio`/`video`/`voice_call`/`video_call`/`photo`). Passing any other string causes validation failure.

- Other required parameters are passed with invalid values. The `context`, `tag`, and `type` parameters of createAVSession are all required. Any missing or invalid parameter throws an exception.

**Solution**

1. Check whether a live AVSession already exists. If necessary, call [destroy](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#destroy10) to release the old session before creating a new one. Before creation, you can also call [getAVSession](../../reference/apis-avsession-kit/arkts-apis-avsession-f.md#avsessiongetavsession22) to check whether the current app has already created a session object, and then decide whether to destroy the old session or reuse the existing one.

2. In scenarios involving frequent creation and destruction, listen for the [on('sessionDestroy')](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSessionController.md#onsessiondestroy10) event through the media session controller, and create a new AVSession object only after receiving the old session destruction callback.

    ```TypeScript
    import { avSession } from '@kit.AVSessionKit';

    async destroyAndRecreateAVSession(context: Context) {
        let videoSession: avSession.AVSession;
        let avSessionController: avSession.AVSessionController;
        try {
            // Create an AVSession for the first time and obtain its controller.
            videoSession = await avSession.createAVSession(context, 'VIDEO_SESSION', 'video');
            avSessionController = await videoSession.getController();

            // Register a session destruction listener. The callback is triggered after the session is destroyed.
            avSessionController.on('sessionDestroy', async () => {
                // Create an AVSession for the second time. Re-create a session of the same type after destruction.
                videoSession = await avSession.createAVSession(context, 'VIDEO_SESSION', 'video');
                // Destroy the AVSession for the second time.
                await videoSession.destroy();
            });

            // Destroy the AVSession for the first time, which triggers the sessionDestroy callback above.
            await videoSession.destroy();
        } catch (err) {
            console.error(`AVSession create Error: Code: ${err.code}, message: ${err.message}`);
        }
    }
    ```

3. It is recommended to obtain the context through `this.getUIContext().getHostContext() as Context` to avoid passing undefined or a context that does not belong to the current UIAbility.

4. Ensure that type is a valid value defined in [AVSessionType](../../reference/apis-avsession-kit/arkts-apis-avsession-t.md#avsessiontype10).

5. Ensure that all required parameters are valid non-null values. For example, avoid passing invalid values such as an empty string for `tag`.

## Audio and Video Forcibly Paused After App Is Relegated to Background

**Symptom**

After the app is switched to the background, audio and video playback is forcibly paused by the system, and the user cannot continue listening.

**Possible Causes**

- AVSession not integrated. The system enforces strict control over audio and video apps that have not integrated AVSession when they are in the background. When the stream type is `STREAM_USAGE_MUSIC`, `STREAM_USAGE_MOVIE`, `STREAM_USAGE_AUDIOBOOK`, or `STREAM_USAGE_GAME`, AVSession must be integrated.

- Continuous task not requested. Integrating AVSession alone is insufficient to ensure background playback. A continuous task must also be requested; otherwise, the app will be suspended or frozen after entering the background.

- AVSession instance reclaimed. The AVSession object must persist throughout the background playback activity. If the session is stored in a local variable, the object is released after the method returns. The system then determines that the app has no valid AVSession instance and forcibly pauses the audio.

- AVSession creation failure causes the app to not hold a valid session.

- The background playback mode is set incorrectly.

**Solution**

1. Refer to [Accessing AVSession](avsession-background-scene.md#accessing-avsession) in Background Playback to complete AVSession integration.

2. Apply for an `AUDIO_PLAYBACK` type [continuous task (ArkTS)](../../task-management/continuous-task.md).

3. Use a class member variable to hold the session instance, and release it only when the app process ends or the playback service exits.

4. Check the related causes in [AVSession Creation Failure](#avsession-creation-failure) one by one to ensure that the app holds a valid session.

5. Before the app is relegated to the background, call [setBackgroundPlayMode](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setbackgroundplaymode24) to set the background playback mode ([BackgroundPlayMode](../../reference/apis-avsession-kit/arkts-apis-avsession-e.md#backgroundplaymode24)), which informs the system whether to continue playback when the app is relegated to the background:

     - `ENABLE_BACKGROUND_PLAY` (supports background playback): The app continues playback when relegated to the background.

     - `DISABLE_BACKGROUND_PLAY` (does not support background playback): The app stops playback when relegated to the background.

     For apps with [AVSessionType](../../reference/apis-avsession-kit/arkts-apis-avsession-t.md#avsessiontype10) set to `audio`, the default value is `ENABLE_BACKGROUND_PLAY`; for apps with the type set to `video`, the default value is `DISABLE_BACKGROUND_PLAY`. If a video app needs to support background audio playback, you must explicitly set it to `ENABLE_BACKGROUND_PLAY`. If the app provides a "whether background playback is supported" switch, the background playback mode set must be consistent with the switch state; otherwise, the app may be forcibly paused after being relegated to the background, or the system Live View may display incorrectly. The following is a setup example:

     ```TypeScript
     import { avSession } from '@kit.AVSessionKit';
     import { BusinessError } from '@kit.BasicServicesKit';

     // Assume that currentAVSession has been created and held.
     async setBackgroundPlayMode(currentAVSession: avSession.AVSession) {
       try {
         await currentAVSession.setBackgroundPlayMode(avSession.BackgroundPlayMode.ENABLE_BACKGROUND_PLAY);
         console.info(' Succeeded in setBackgroundPlayMode');
       } catch (err) {
         let error = err as BusinessError;
         console.error(`setBackgroundPlayMode BusinessError: code: ${error.code}, message: ${error.message}`);
       }
     }
     ```

For more details, see [Setting the Background Playback Mode](avsession-background-scene.md#setting-the-background-playback-mode).

## Media Control Center Not Displaying the App Session

**Symptom**

The app has created an AVSession, but the Media Control Center does not display the corresponding media information or control bar.

**Possible Causes**

- Metadata is not set, or metadata setting fails.

- No control command callback is registered. For a session to be displayed in the Media Control Center, at least one control command (such as play/pause) must be registered.

- Fields such as album art contain illegal characters, causing the image not to be displayed. If the file path passed to the mediaImage field in [AVMetadata](../../reference/apis-avsession-kit/arkts-apis-avsession-i.md#avmetadata10) contains Chinese characters or special characters (such as `/`, `·`, etc.), the image cannot be displayed properly. Similarly, illegal characters in `avQueueName` and `avQueueId` may also cause the image not to be displayed.

- The lyric content exceeds the length limit. The `lyric` field (lyric content) string in [AVMetadata](../../reference/apis-avsession-kit/arkts-apis-avsession-i.md#avmetadata10) must be less than 40960 bytes. If the limit is exceeded, the Media Control Center will not display the lyric content.

- A call-type app does not use the call session type, or the system version/app classification does not meet the requirements.<!--RP1--><!--RP1End-->

**Solution**

1. Set media information such as the title, subtitle/artist, and album art. For details, see [Setting Metadata Information](avsession-access-scene.md#setting-metadata-information). Ensure that key metadata fields such as `assetId` use valid values, and avoid passing empty strings, which may cause the setting to fail.

2. Register at least one control command. For details, see [Control Command Processing](avsession-access-scene.md#control-command-processing).

3. Ensure that fields such as `mediaImage`, `avQueueName`, and `avQueueId` use valid characters.

4. Ensure that the lyric content does not exceed the length limit of 40960 bytes.

5. When a call app integrates AVSession, the session type ([AVSessionType](../../reference/apis-avsession-kit/arkts-apis-avsession-t.md#avsessiontype10)) must be set to `voice_call` or `video_call`.<!--RP2--><!--RP2End-->

## Control Command Unresponsive or Media Control Display Mismatch

**Symptom**

When control buttons (play, pause, previous, next, etc.) are tapped in the media control center, there is no response, and neither the app nor the media control interface is updated. Alternatively, the actual playback state of the app is out of sync with the state displayed in the media control center — for example, the app is playing but the media control still shows paused.

**Possible Causes**

- The session is not activated. Control commands can be delivered through the media control center only after the session is activated.

- No control command listener is registered. If no listener is registered, control commands cannot be delivered to the app.

- The app's playback state is not synchronized with the system media control center. The state displayed in the media control center (such as play/pause, progress, etc.) is based on the state reported by the app through control commands. If the app does not synchronize its playback state in a timely manner when the actual state changes, the media control center display will not match the actual state.

**Solution**

1. Activate the session through [activate](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#activate10) and confirm that the session has been activated.

2. Register listeners for the corresponding control commands through the AVSession object's `on('play')`, `on('pause')`, `on('playNext')`, `on('playPrevious')`, and other APIs, and drive the player to perform the corresponding operations in the callbacks. Refer to [Control Command Processing](avsession-access-scene.md#control-command-processing) to complete the registration logic.

3. Call [setAVPlaybackState](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setavplaybackstate10) to update the playback state when the playback state changes. When the state is set to [PLAYBACK_STATE_PAUSE](../../reference/apis-avsession-kit/arkts-apis-avsession-e.md#playbackstate10), the system reclaims the media control card in the capsule area 5 seconds after the app is relegated to the background, and reclaims the media control cards in the Notification Bar and Lock Screen positions 10 minutes later.

## Playback Progress Bar Rewind Flicker

**Symptom**

After tapping the play button in the media control center, the playback progress bar rewinds and flickers.

**Possible Causes**

The player startup delay causes progress inconsistency. After the play button is tapped, the playback progress bar in the media control center starts timing immediately, while the player in the app has not actually started playback yet, causing its progress to lag behind the media control center. When the app subsequently synchronizes the progress, the progress value is smaller than the elapsed time tracked by the media control center, resulting in the progress bar rewinding and flickering.

**Solution**

Before the player starts playback, call [setAVPlaybackState](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setavplaybackstate10) to set the state to [PLAYBACK_STATE_BUFFERING](../../reference/apis-avsession-kit/arkts-apis-avsession-e.md#playbackstate10) (buffering). After the player actually starts playback, synchronize the state and progress.

```TypeScript
import { avSession } from '@kit.AVSessionKit';
import { media } from '@kit.MediaKit';

// avPlayer is the player instance created through media.createAVPlayer(), and currentAVSession is the created AVSession object.

async listenAVPlayer(avPlayer: media.AVPlayer, currentAVSession: avSession.AVSession) {
    // Listen for AVPlayer state machine transitions in advance. After actual playback starts (entering the playing state), synchronize the actual state and progress.
    avPlayer.on('stateChange', async (state: string) => {
        if (state === 'playing') {
        let playingState: avSession.AVPlaybackState = {
            state: avSession.PlaybackState.PLAYBACK_STATE_PLAY,
            speed: 1.0,
            // currentTime is the current actual playback progress of AVPlayer, in milliseconds (ms).
            position: { elapsedTime: avPlayer.currentTime, updateTime: (new Date()).getTime() }
        };
        await currentAVSession.setAVPlaybackState(playingState);
        }
    });

    // After receiving a playback command and before AVPlayer actually starts playback, set the media control state to buffering to prevent the media control progress bar from starting to count ahead of time.
    let bufferingState: avSession.AVPlaybackState = {
        state: avSession.PlaybackState.PLAYBACK_STATE_BUFFERING,
        speed: 0,
        position: { elapsedTime: 0, updateTime: (new Date()).getTime() }
    };
    await currentAVSession.setAVPlaybackState(bufferingState);
    await avPlayer.play();
}
```