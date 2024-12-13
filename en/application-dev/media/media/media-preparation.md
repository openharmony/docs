# Media Development Preparations

The main process of media application development includes development preparations, audio and video playback, audio and video recording, metadata extraction, and screen capture.

Before developing a media application, you must request related permissions to ensure that the application has the permission to access media files and other services. For example, if you want to access online media resources, request the ohos.permission.INTERNET permission. Before requesting permissions, ensure that the [basic principles for using permissions](../../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met.

Most media-related permissions are of the user_grant level and must be authorized by the user. After adding the permissions in the **module.json5** file, use [abilityAccessCtrl.requestPermissionsFromUser](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to check whether the required permissions are granted by the user. If yes, the application can access the data. Otherwise, display a dialog box to request user authorization.


For details about how to request and verify the permissions, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

## How to Develop

You can use either ArkTS or C++ APIs for media development.

| Procedure    | ArkTS Development                                    | C++ Development                            |
| ------------ | ------------------------------------------------- | --------------------------------------- |
| Audio playback    | [Using AVPlayer to Play Audio (ArkTS)](using-avplayer-for-playback.md)| [Using AVPlayer to Play Audio (C/C++)](using-ndk-avplayer-for-playerback.md)|
| Video playback    | [Using AVPlayer to Play Videos (ArkTS)](video-playback.md)             | - |
| Streaming media    |  [Using AVPlayer to Play Streaming Media (ArkTS)](streaming-media-playback-development-guide.md)             | - |
| Adding subtitles    | [Using AVPlayer to Add External Subtitles to Videos (ArkTS)](video-subtitle.md)| -                                    |
| Sound pool      | [Using SoundPool to Play Short Sounds (ArkTS)](using-soundpool-for-playback.md)          | -                                     |
| Audio recording    | [Using AVRecorder to Record Audio (ArkTS)](using-avrecorder-for-recording.md)| -                                     |
| Video recording    | [Using AVRecorder to Record Videos (ArkTS)](video-recording.md)| -                                     |
| Writing screen capture files  | [Using AVScreenCaptureRecorder to Capture Screens and Write Them to Files (ArkTS)](using-avscreencapture-ArkTs.md)| [Using AVScreenCapture to Capture Screens and Write Them to Files (C/C++)](using-avscreencapture-for-file.md)|
| Metadata extraction      | [Using AVMetadataExtractor to Extract Audio and Video Metadata (ArkTS)](avmetadataextractor.md)| -                                     |
| Image extraction    | [Using AVImageGenerator to Extract Video Images at a Specified Time (ArkTS)](avimagegenerator.md)| -                                     |
| Video transcoding    | [Using AVTranscoder to Transcode Videos (ArkTS)](using-avtranscoder-for-transcodering.md)| -                                     |
| Screen capture and stream retrieval  | -                                               | [Using AVScreenCapture to Capture Screens and Obtain Streams (C/C++)](using-avscreencapture-for-buffer.md)|
