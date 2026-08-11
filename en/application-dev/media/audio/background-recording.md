# Implementing Background Recording

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ZhengYong21-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=bbcf4d0737e3916a6a65e6c508a141a7e736f3d3 translatedAt=2026-08-06T01:50:02.615Z pushedAt=2026-08-06T08:38:40.806Z -->

Starting from API version 9, the background continuous task development feature is supported. An app can configure a background continuous task to enable background recording.

Background recording refers to the scenario where an app continues to capture audio after starting a recording task in the foreground and then moving to the background. Typical scenarios include meeting minutes, voice memos, interview recordings, and other services that require long-duration recording.

Background recording involves microphone capture and background running. An app must simultaneously meet the requirements for microphone permission, recording capability implementation, background continuous task declaration, and system control. Recording must not be started without the user's awareness or authorization.

## Constraints

- User authorization: Microphone permission must be obtained before recording. After the user revokes the permission, the app must immediately stop recording and release resources.

- User awareness: A clear user-perceptible indication must be maintained during background recording, such as a notification or status prompt showing that recording is in progress.

- Scenario matching: The background mode declaration must align with the actual service. After requesting a recording-type continuous task, the app must actually perform recording operations. When only playback, media control, or media session control is required, declaring the background recording mode is unnecessary.

- Minimal acquisition: The app must capture audio only when the user triggers a recording task, and stop promptly after the task ends to avoid prolonged microphone occupancy.

- Resource release: When the app enters the background, exits, crashes, or completes recording, the audio capturer, file handles, and background task state must be kept consistent to prevent a situation where recording has stopped but the background task remains active.

- Privacy compliance: Recording content that the user has not confirmed must not be automatically uploaded in the background. The saving, uploading, sharing, and deletion of recording files must follow user authorization.

## How to Develop

For details about how to implement the recording feature, see [Using AudioCapturer for Audio Recording (ArkTS)](using-audiocapturer-for-recording.md), [(Recommended) Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md), or [Using AVRecorder to Record Audio (ArkTS)](../media/using-avrecorder-for-recording.md). When the app needs to switch to the background for continuous recording, it must also request a recording-type [continuous task (ArkTS)](../../task-management/continuous-task.md).

1. Declare the background recording mode.

   In the [module.json5 configuration file](../../quick-start/module-configuration-file.md), declare the `audioRecording` background mode for the UIAbility that needs to perform background recording.

   ```json
   {
     "abilities": [
       {
         "name": "EntryAbility",
         "backgroundModes": [
           "audioRecording"
         ]
       }
     ]
   }
   ```

2. Start the recording task.

   The app must start the recording task in the foreground. After the recording starts, the app can switch to the background to continue recording. Starting recording directly in the background will fail.

Before recording starts, the app must confirm that the user has explicitly triggered the recording operation, and handle exception scenarios such as microphone permission not granted, device being occupied, and storage path being unavailable. For details about recording development, see [Audio Recording Development](audio-recording-overview.md).

For scenarios where app background recording is interrupted by other audio streams and cannot be recovered, the following solution is recommended:

- When app recording is interrupted in the background and start fails upon receiving a focus restoration notification, a dialog can be displayed to remind the user to open the app again and manually restart recording.

- Use the audio recording API [setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setindependentaudiosessionstrategy24) with `AudioSessionBehaviorFlags` set to `MUTE_WHEN_INTERRUPTED`. This configures the recording stream focus policy to the mute-when-interrupted mode. When recording is stopped or paused due to interruption by another app, it enters a muted recording state where the recorded audio is silent. After the other app completes its recording action, audible data recording resumes.

3. Apply for a recording-type continuous task.

When recording needs to continue running in the background, the app must apply for a continuous task of the `AUDIO_RECORDING` type so that the system can identify that the background task matches the recording service.

   <!-- @[background_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioVoIPCallSampleC/entry/src/main/ets/pages/AudioPlayer.ets) -->

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   import { backgroundTaskManager } from '@kit.BackgroundTasksKit'
   import { wantAgent, WantAgent } from '@kit.AbilityKit'
   // ...
   
     // Start the continuous task.
     startContinuousTask(context: Context) {
       let wantAgentInfo: wantAgent.WantAgentInfo = {
         // List of actions to be executed after the notification is tapped.
         // Add the bundleName and abilityName of the app to be started.
         wants: [
           {
             bundleName: 'com.example.backgroundmusic',
             abilityName: 'MainAbility'
           }
         ],
         // Specify that the action after tapping the notification bar message is to start an ability.
         actionType: wantAgent.OperationType.START_ABILITY,
         // A private value defined by the user.
         requestCode: 0,
         // Action execution attributes after the notification is tapped.
         actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
       };
   
       try {
         // Obtain the WantAgent object through the getWantAgent method in the wantAgent module.
         wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
           try {
             let list: string[] = ['audioPlayback'];
             backgroundTaskManager.startBackgroundRunning(context, list, wantAgentObj)
               .then(() => {
                 console.info('Operate startBackgroundRunning succeeded');
               })
               .catch((error: BusinessError) => {
                 console.error(`Failed to operate startBackgroundRunning. code is ${error.code} message is ${error.message}`);
               });
           } catch (error) {
             console.error(`Failed to operate startBackgroundRunning. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
           };
         });
       } catch (error) {
         console.error(`Failed to operate getWantAgent. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
       }
     }
   ```

When a continuous task fails to start, the app must avoid continuing to run in background recording mode. It should stop recording or guide the user back to the foreground. For the complete process of requesting and canceling a continuous task, see [Continuous Task (ArkTS)](../../task-management/continuous-task.md).

4. Stop recording and release resources.

When the user stops recording, recording is abnormally interrupted, or the service ends, the app must call the [release](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#release8) API of AudioCapturer to stop recording, release audio capture resources, and simultaneously cancel the continuous task of the recording type.

   <!-- @[background_task_cancel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioVoIPCallSampleC/entry/src/main/ets/pages/AudioPlayer.ets) -->

   ``` TypeScript
   // Cancel the continuous task.
   stopContinuousTask(context: Context) {
     backgroundTaskManager.stopBackgroundRunning(context).then(() => {
       console.info(`Succeeded in operating stopBackgroundRunning.`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to operate stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
     });
   }
   ```