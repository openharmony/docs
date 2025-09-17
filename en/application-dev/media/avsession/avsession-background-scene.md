# Background Playback
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

In practical applications, most audio and video content requires background playback. This guide details how to implement long-duration background playback.

## Basic Concepts

Before diving in, you should understand the following basic concepts to effectively implement background playback based on your player type.

- Continuous task: Refer to [Continuous Tasks (ArkTS)](../../task-management/continuous-task.md).

  Actions such as returning to the home screen, locking the screen, or switching applications can push an application to the background. When an application is pushed to the background and resumes activity, it may cause rapid battery drain and UI lag. To reduce battery consumption and ensure a smooth user experience, the system manages applications pushed to the background, including process suspension and termination.

  If an application has a perceivable task that needs to run in an extended period of time in the background, it can request a continuous task to prevent itself from being suspended. Examples of continuous tasks include music playback and video playback in the background.

- AVSession: Refer to [Introduction to AVSession Kit](../avsession/avsession-overview.md).

  AVSession Kit is a system-provided service for managing audio and video playback, helping you quickly build unified display and control capabilities for audio and video. After accessing AVSession, audio and video applications can set application data (such as the currently playing song and its playback status). Users can control playback of different applications through the media controller. AVSession imposes constraints on media playback in the background. Therefore, audio applications, audiobook applications, and video applications typically need to access AVSession. If an application performs the aforementioned tasks without creating an AVSession, the system will stop the corresponding audio and video playback when it detects the application moving to the background to enforce application behavior constraints.

- AVPlayer: Refer to [AVPlayer](../media/media-kit-intro.md#avplayer).

  AVPlayer is a powerful media player that can play various audio and video formats (such as mp4, mp3, mkv, mpeg-ts) end to end. You only need to provide the media source to start playback without worrying about complex demultiplexing and decoding processes.

- AudioRenderer: Refer to [Using AudioRenderer for Audio Playback](../audio/using-audiorenderer-for-playback.md).

  AudioRenderer is an audio renderer used to play Pulse Code Modulation (PCM) audio data. Compared with AVPlayer, AudioRenderer allows data preprocessing before input, making it more suitable for developers with audio development experience to achieve more flexible playback features.

## Application Access Standards

- When an application needs to play media types (stream types **STREAM_USAGE_MUSIC**, **STREAM_USAGE_MOVIE**, and **STREAM_USAGE_AUDIOBOOK**) and game types (stream type **STREAM_USAGE_GAME**) in the background, it must access AVSession and request continuous tasks. For details about the stream types, see [Selecting the Appropriate Audio Stream Types](../audio/using-right-streamusage-and-sourcetype.md). For details about the supported continuous task types, see [BackgroundMode](../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundmode).

- In addition to the aforementioned playback types, when an application needs to run other user-perceptible tasks in the background for a long time, it must request continuous tasks of the AUDIO_PLAYBACK type.

If an application does not meet the above access standards, playback in the background will be muted and frozen by the system, preventing normal background playback. Playback will only resume and unmute when the application is brought back to the foreground.

## How to Develop

The basic steps for audio and video applications to achieve background playback are as follows:

### Starting the Player

Application playback can be achieved using AudioRenderer, AVPlayer, or other third-party or custom players.

- AudioRenderer: When using AudioRenderer to create an audio stream, pay attention to using the appropriate audio stream type. Different stream types have a decisive impact on volume control, audio focus management, and input/output devices. For details, see [Selecting the Appropriate Audio Stream Types](../audio/using-right-streamusage-and-sourcetype.md).

  Additionally, you must correctly handle audio focus. The system has preset default audio focus strategies that manage all playback and recording audio streams based on the type of audio stream and the order in which they start. During application playback or recording, if another audio stream requests focus, the system will handle the focus according to the focus strategy. If the focus of this audio stream changes, the system automatically performs necessary operations (such as pausing, resuming, lowering volume, and restoring volume) and notifies the application of the change through the audio focus event (InterruptEvent). For details, see [Handling Audio Focus Changes](../audio/audio-playback-concurrency.md#handling-audio-focus-changes).
  
  For details about the development, see [Using AudioRenderer to Develop Audio Playback Functions](../audio/using-audiorenderer-for-playback.md).
  
- AVPlayer: Using AVPlayer can achieve end-to-end playback of raw media resources. To achieve background playback or playback with the screen off, you need to access AVSession and request continuous tasks to prevent playback from being forcibly interrupted by the system. [AVPlayer](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md) can set the focus management strategy through the **audioInterruptMode** property, which defaults to **SHARE_MODE**.
  
  For details about the development, see [Using AVPlayer to Play Audio (ArkTS)](../media/using-avplayer-for-playback.md).

### Accessing AVSession

When creating an audio stream of type **STREAM_USAGE_MUSIC**, **STREAM_USAGE_MOVIE**, **STREAM_USAGE_AUDIOBOOK**, or **STREAM_USAGE_GAME**, whether to continue playback in the background or start playback in the background, you must access AVSession.

You are advised to create an AVSession object before the application starts or begins playback, and release it when the application process ends or completely exits playback and no longer plays. This avoids frequent creation and release of AVSession, thereby ensuring the continuity and stability of the application's playback service. When playing in the background, ensure that the AVSession object exists throughout the application's background activity to prevent it from being reclaimed or released by the system, such as not using local variables to save the AVSession object.

After creating AVSession, to ensure a smooth integration experience, you are required to set the following metadata and register the following control commands.

- Metadata: title, subtitle/artist, and cover image. For details, see [Setting Metadata](avsession-access-scene.md#setting-metadata).

- Register control commands: play and pause. For details, see [Registering Control Commands](avsession-access-scene.md#registering-control-commands).

For details about how to access AVSession, see [Accessing AVSession](avsession-access-scene.md).

### Requesting Continuous Tasks

You can request various types of continuous tasks. For example, when the background playback task type is **AUDIO_PLAYBACK**, whether the application is playing audio, video, or casting (through the **AVCastPicker** component) in the background, you can request a continuous task of type **AUDIO_PLAYBACK**.
- Request a continuous task during playback. If the application explicitly has background playback service (for example, a video application enables background playback options), you can request a continuous task during foreground playback.
- Actively cancel the continuous task when pausing or stopping. For example, when the user actively taps to pause music playback, the application needs to promptly cancel the corresponding continuous task; when the user taps to play music again, the application needs to request a continuous task again.
- If audio playback in the background is interrupted (for example, by focus interruption), the system automatically detects and freezes or cancels the continuous task. When the application restarts audio playback, it needs to request a continuous task again.
- When the application receives AVSession playback control commands or audio device changes that require corresponding playback and pause operations, it needs to cancel the continuous task when pausing and request it again when playing.
- When casting through the **AVCastPicker** component in the background, request a continuous task when starting the cast and cancel it when disconnecting. During the casting process, if audio playback is paused, no action is required for the continuous task.

For details, see [Continuous Task (ArkTS)](../../task-management/continuous-task.md#how-to-develop).

### Listening for Foreground and Background States

If the application does not have background playback service, you can use the lifecycle function [onBackground](../../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onbackground) to determine whether the application has entered the background and proactively stop playback. Otherwise, it will be affected by AVSession and continuous task module management, impacting the application's normal playback. If you need to restart playback when the application returns to the foreground, use the lifecycle function [onForeground](../../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground) to determine whether the application is back in the foreground.

<!--RP1--><!--RP1End-->
