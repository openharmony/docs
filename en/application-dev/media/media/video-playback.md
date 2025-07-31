# Using AVPlayer to Play Videos (ArkTS)

The system provides two solutions for video playback development:

- [AVPlayer](media-kit-intro.md#avplayer): provides ArkTS and JS APIs to implement audio and video playback. It also supports parsing streaming media and local assets, decapsulating media assets, decoding video, and rendering video. It is applicable to end-to-end playback of media assets and can be used to play video files in MP4 and MKV formats.

- **Video** component: encapsulates basic video playback capabilities. It can be used to play video files after the data source and basic information are set. However, its scalability is poor. This component is provided by ArkUI. For details about how to use this component for video playback development, see [Video Component](../../ui/arkts-common-components-video-player.md).

In this topic, you will learn how to use the AVPlayer to develop a video playback service that plays a complete video file.

The full playback process includes creating an AVPlayer instance, setting the media asset to play and the window to display the video, setting playback parameters (volume, speed, and scale type), controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the instance. During application development, you can use the **state** property of the AVPlayer to obtain the AVPlayer state or call **on('stateChange')** to listen for state changes. If the application performs an operation when the AVPlayer is not in the given state, the system may throw an exception or generate other undefined behavior.

**Figure 1** Playback state transition 

![Playback state change](figures/video-playback-status-change.png)

For details about the states, see [AVPlayerState](../../reference/apis-media-kit/arkts-apis-media-t.md#avplayerstate9). When the AVPlayer is in the **prepared**, **playing**, **paused**, or **completed** state, the playback engine is working and a large amount of RAM is occupied. If your application does not need to use the AVPlayer, call **reset()** or **release()** to release the instance.

## Developer's Tips

This topic describes only how to implement the playback of a media asset. In practice, background playback and playback conflicts may be involved. You can refer to the following description to handle the situation based on your service requirements.

- If you want the application to continue playing the media asset in the background or when the screen is off, use the [AVSession](../avsession/avsession-access-scene.md) and [continuous task](../../task-management/continuous-task.md) to prevent the playback from being forcibly interrupted by the system.
- If the media asset being played involves audio, the playback may be interrupted by other applications based on the system audio management policy. (For details, see [Processing Audio Interruption Events](../audio/audio-playback-concurrency.md).) It is recommended that the player application proactively listen for audio interruption events and handle the events accordingly to avoid the inconsistency between the application status and the expected effect.
- When a device is connected to multiple audio output devices, the application can listen for audio output device changes through [on('audioOutputDeviceChangeWithInfo')](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#onaudiooutputdevicechangewithinfo11) and perform the processing accordingly.
- To access online media resources, you must request the ohos.permission.INTERNET permission.

## How to Develop

Read [AVPlayer](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md) for the API reference.

1. Call **createAVPlayer()** to create an AVPlayer instance. The AVPlayer is the idle state.

2. Set the events to listen for, which will be used in the full-process scenario. The table below lists the supported events.
   | Event Type| Description|
   | -------- | -------- |
   | stateChange | Mandatory; used to listen for changes of the **state** property of the AVPlayer.|
   | error | Mandatory; used to listen for AVPlayer errors.|
   | durationUpdate | Used to listen for progress bar updates to refresh the media asset duration.|
   | timeUpdate | Used to listen for the current position of the progress bar to refresh the current time.|
   | seekDone | Used to listen for the completion status of the **seek()** request.<br>This event is reported when the AVPlayer seeks to the playback position specified in **seek()**.|
   | speedDone | Used to listen for the completion status of the **setSpeed()** request.<br>This event is reported when the AVPlayer plays videos at the speed specified in **setSpeed()**.|
   | volumeChange | Used to listen for the completion status of the **setVolume()** request.<br>This event is reported when the AVPlayer plays videos at the volume specified in **setVolume()**.|
   | bitrateDone | Used to listen for the completion status of the **setBitrate()** request, which is used for HTTP Live Streaming (HLS) streams.<br>This event is reported when the AVPlayer plays videos at the bit rate specified in **setBitrate()**.|
   | availableBitrates | Used to listen for available bit rates of HLS resources. The available bit rates are provided for **setBitrate()**.|
   | bufferingUpdate | Used to listen for network playback buffer information.|
   | startRenderFrame | Used to listen for the rendering time of the first frame during video playback.<br>This event is reported when the AVPlayer enters the playing state and the first frame of the video image is rendered to the display. Generally, the application can use this event to remove the video cover, achieving smooth connection between the cover and the video image.|
   | videoSizeChange | Used to listen for the width and height of video playback and adjust the window size and ratio.|
   | audioInterrupt | Used to listen for audio interruption. This event is used together with the **audioInterruptMode** property.<br>This event is reported when the current audio playback is interrupted by another (for example, when a call is coming), so the application can process the event in time.|

3. Set the media asset URL. The AVPlayer enters the **initialized** state.
   > **NOTE**
   >
   > The URL in the code snippet below is for reference only. You need to check the media asset validity and set the URL based on service requirements.
   > 
   > - If local files are used for playback, ensure that the files are available and the application sandbox path is used for access. For details about how to obtain the application sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).
   > 
   > - If a network playback path is used, you must [declare the ohos.permission.INTERNET permission](../../security/AccessToken/declare-permissions.md).
   > 
   > - You can also use **ResourceManager.getRawFd** to obtain the FD of a file packed in the HAP file. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9).
   > 
   > - The [playback formats and protocols](media-kit-intro.md#supported-formats-and-protocols) in use must be those supported by the system.

4. Obtain and set the surface ID of the window to display the video.
   The application obtains the surface ID from the **XComponent**. For details about the process, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

5. Call **prepare()** to switch the AVPlayer to the **prepared** state. In this state, you can obtain the duration of the media asset to play and set the scale type and volume.

6. Call **play()**, **pause()**, **seek()**, and **stop()** to perform video playback control as required.

7. (Optional) Call **reset()** to reset the AVPlayer. The AVPlayer enters the **idle** state again and you can change the media asset URL.

8. Call **release()** to switch the AVPlayer to the **released** state. Now your application exits the playback.

## Running the Sample Project

1. Create a project, download the [sample project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSVideo), and copy its resources to the corresponding directories.
    ```
    AVPlayerArkTSVideo
    entry/src/main/ets/
    └── pages
        └── Index.ets (playback UI)
    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │       ├── ic_video_play.svg (play button image resource)
    │       └── ic_video_pause.svg (pause button image resource)
    └── rawfile
        └── test1.mp4 (video resource)
    ```
2. Compile and run the project.
