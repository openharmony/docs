# Media Subsystem ChangeLog

## cl.media.1 API Change of the Playback Function

Added the [AVPlayer](../../../application-dev/reference/apis/js-apis-media.md#avplayer9)<sup>9+</sup> API for audio and video playback, with the updated state machine and error codes, which is recommended. The following APIs for audio playback and video playback are no longer maintained: [AudioPlayer](../../../application-dev/reference/apis/js-apis-media.md#audioplayer)<sup>6+</sup> and [VideoPlayer](../../../application-dev/reference/apis/js-apis-media.md#videoplayer)<sup>8+</sup>.

**Change Impacts**

The original APIs can still be used but are no longer maintained. You are advised to use the new API instead.

**Key API/Component Changes**

Added APIs

| Class          | Declaration                                                |
| -------------- | ------------------------------------------------------------ |
| media          | createAVPlayer(callback: AsyncCallback\<AVPlayer>): void     |
| media          | createAVPlayer() : Promise\<AVPlayer>                        |
| media.AVPlayer | interface AVPlayer                                           |
| media.AVPlayer | videoScaleType ?: VideoScaleType                             |
| media.AVPlayer | url ?: string                                                |
| media.AVPlayer | surfaceId ?: string                                          |
| media.AVPlayer | stop(callback: AsyncCallback\<void>): void                   |
| media.AVPlayer | stop(): Promise\<void>                                       |
| media.AVPlayer | setVolume(volume: number): void                              |
| media.AVPlayer | setSpeed(speed: PlaybackSpeed): void                         |
| media.AVPlayer | setBitrate(bitrate: number): void                            |
| media.AVPlayer | seek(timeMs: number, mode?:SeekMode): void                   |
| media.AVPlayer | reset(callback: AsyncCallback\<void>): void                  |
| media.AVPlayer | reset(): Promise\<void>                                      |
| media.AVPlayer | release(callback: AsyncCallback\<void>): void                |
| media.AVPlayer | release(): Promise\<void>                                    |
| media.AVPlayer | readonly width: number                                       |
| media.AVPlayer | readonly state: AVPlayerState                                |
| media.AVPlayer | readonly height: number                                      |
| media.AVPlayer | readonly duration: number                                    |
| media.AVPlayer | readonly currentTime: number                                 |
| media.AVPlayer | prepare(callback: AsyncCallback\<void>): void                |
| media.AVPlayer | prepare(): Promise\<void>                                    |
| media.AVPlayer | play(callback: AsyncCallback\<void>): void                   |
| media.AVPlayer | play(): Promise\<void>                                       |
| media.AVPlayer | pause(callback: AsyncCallback\<void>): void                  |
| media.AVPlayer | pause(): Promise\<void>                                      |
| media.AVPlayer | on(type: 'volumeChange', callback: Callback\<number>): void  |
| media.AVPlayer | on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void |
| media.AVPlayer | on(type: 'timeUpdate', callback: Callback\<number>): void    |
| media.AVPlayer | on(type: 'stateChange', callback: (state: AVPlayerState, reason: StateChangeReason) => void): void |
| media.AVPlayer | on(type: 'startRenderFrame', callback: Callback\<void>): void |
| media.AVPlayer | on(type: 'speedDone', callback: Callback\<number>): void     |
| media.AVPlayer | on(type: 'seekDone', callback: Callback\<number>): void      |
| media.AVPlayer | on(type: 'error', callback: ErrorCallback): void             |
| media.AVPlayer | on(type: 'endOfStream', callback: Callback\<void>): void     |
| media.AVPlayer | on(type: 'durationUpdate', callback: Callback\<number>): void |
| media.AVPlayer | on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void |
| media.AVPlayer | on(type: 'bitrateDone', callback: Callback\<number>): void   |
| media.AVPlayer | on(type: 'availableBitrates', callback: (bitrates: Array\<number>) => void): void |
| media.AVPlayer | on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void |
| media.AVPlayer | off(type: 'volumeChange'): void                              |
| media.AVPlayer | off(type: 'videoSizeChange'): void                           |
| media.AVPlayer | off(type: 'timeUpdate'): void                                |
| media.AVPlayer | off(type: 'stateChange'): void                               |
| media.AVPlayer | off(type: 'startRenderFrame'): void                          |
| media.AVPlayer | off(type: 'speedDone'): void                                 |
| media.AVPlayer | off(type: 'seekDone'): void                                  |
| media.AVPlayer | off(type: 'error'): void                                     |
| media.AVPlayer | off(type: 'endOfStream'): void                               |
| media.AVPlayer | off(type: 'durationUpdate'): void                            |
| media.AVPlayer | off(type: 'bufferingUpdate'): void                           |
| media.AVPlayer | off(type: 'bitrateDone'): void                               |
| media.AVPlayer | off(type: 'availableBitrates'): void                         |
| media.AVPlayer | off(type: 'audioInterrupt'): void                            |
| media.AVPlayer | loop: boolean                                                |
| media.AVPlayer | getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void |
| media.AVPlayer | getTrackDescription() : Promise\<Array\<MediaDescription>>   |
| media.AVPlayer | fdSrc ?: AVFileDescriptor                                    |
| media.AVPlayer | audioInterruptMode ?: audio.InterruptMode                    |
| unnamed        | type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error' |

APIs no longer maintained

| Class             | Declaration                                            |
| ----------------- | ------------------------------------------------------------ |
| media             | createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void |
| media             | createVideoPlayer() : Promise\<VideoPlayer>                  |
| media             | createAudioPlayer(): AudioPlayer                             |
| media.AudioPlayer | interface AudioPlayer                                        |
| media.AudioPlayer | play(): void                                                 |
| media.AudioPlayer | release(): void                                              |
| media.AudioPlayer | audioInterruptMode ?: audio.InterruptMode                    |
| media.AudioPlayer | fdSrc: AVFileDescriptor                                      |
| media.AudioPlayer | seek(timeMs: number): void                                   |
| media.AudioPlayer | readonly duration: number                                    |
| media.AudioPlayer | loop: boolean                                                |
| media.AudioPlayer | readonly state: AudioState                                   |
| media.AudioPlayer | getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void |
| media.AudioPlayer | getTrackDescription() : Promise\<Array\<MediaDescription>>   |
| media.AudioPlayer | on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void |
| media.AudioPlayer | on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void |
| media.AudioPlayer | on(type: 'timeUpdate', callback: Callback\<number>): void    |
| media.AudioPlayer | on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void |
| media.AudioPlayer | on(type: 'error', callback: ErrorCallback): void             |
| media.AudioPlayer | setVolume(vol: number): void                                 |
| media.AudioPlayer | pause(): void                                                |
| media.AudioPlayer | readonly currentTime: number                                 |
| media.AudioPlayer | stop(): void                                                 |
| media.AudioPlayer | reset(): void                                                |
| media.AudioPlayer | src: string                                                  |
| media.VideoPlayer | interface VideoPlayer                                        |
| media.VideoPlayer | play(callback: AsyncCallback\<void>): void                   |
| media.VideoPlayer | play(): Promise\<void>                                       |
| media.VideoPlayer | prepare(callback: AsyncCallback\<void>): void                |
| media.VideoPlayer | prepare(): Promise\<void>                                    |
| media.VideoPlayer | release(callback: AsyncCallback\<void>): void                |
| media.VideoPlayer | release(): Promise\<void>                                    |
| media.VideoPlayer | audioInterruptMode ?: audio.InterruptMode                    |
| media.VideoPlayer | fdSrc: AVFileDescriptor                                      |
| media.VideoPlayer | seek(timeMs: number, callback: AsyncCallback\<number>): void |
| media.VideoPlayer | seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void |
| media.VideoPlayer | seek(timeMs: number, mode?:SeekMode): Promise\<number>       |
| media.VideoPlayer | readonly duration: number                                    |
| media.VideoPlayer | loop: boolean                                                |
| media.VideoPlayer | videoScaleType ?: VideoScaleType                             |
| media.VideoPlayer | readonly state: VideoPlayState                               |
| media.VideoPlayer | getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void |
| media.VideoPlayer | getTrackDescription() : Promise\<Array\<MediaDescription>>   |
| media.VideoPlayer | readonly height: number                                      |
| media.VideoPlayer | on(type: 'playbackCompleted', callback: Callback\<void>): void |
| media.VideoPlayer | on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void |
| media.VideoPlayer | on(type: 'startRenderFrame', callback: Callback\<void>): void |
| media.VideoPlayer | on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void |
| media.VideoPlayer | on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void |
| media.VideoPlayer | on(type: 'error', callback: ErrorCallback): void             |
| media.VideoPlayer | setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void |
| media.VideoPlayer | setDisplaySurface(surfaceId: string): Promise\<void>         |
| media.VideoPlayer | setVolume(vol: number, callback: AsyncCallback\<void>): void |
| media.VideoPlayer | setVolume(vol: number): Promise\<void>                       |
| media.VideoPlayer | url: string                                                  |
| media.VideoPlayer | pause(callback: AsyncCallback\<void>): void                  |
| media.VideoPlayer | pause(): Promise\<void>                                      |
| media.VideoPlayer | readonly currentTime: number                                 |
| media.VideoPlayer | setSpeed(speed:number, callback: AsyncCallback\<number>): void |
| media.VideoPlayer | setSpeed(speed:number): Promise\<number>                     |
| media.VideoPlayer | stop(callback: AsyncCallback\<void>): void                   |
| media.VideoPlayer | stop(): Promise\<void>                                       |
| media.VideoPlayer | readonly width: number                                       |
| media.VideoPlayer | reset(callback: AsyncCallback\<void>): void                  |
| media.VideoPlayer | reset(): Promise\<void>                                      |
| unnamed           | type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error' |
| unnamed           | type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error' |

**Adaptation Guide**

For details, see the [reference](../../../application-dev/reference/apis/js-apis-media.md) for each API.

## cl.media.2 API Change of the Recording Function

Added the [AVRecorder](../../../application-dev/reference/apis/js-apis-media.md#avrecorder9)<sup>9+</sup> API for audio and video recording, with the updated state machine and error codes, which is recommended. The following APIs for audio recording and video recording are no longer maintained: [AudioRecorder](../../../application-dev/reference/apis/js-apis-media.md#audiorecorder)<sup>6+</sup> and [VideoRecorder](../../../application-dev/reference/apis/js-apis-media.md#videorecorder9)<sup>9+</sup>.

The [AudioSourceType](../../../application-dev/reference/apis/js-apis-media.md#audiosourcetype9) and [VideoSourceType](../../../application-dev/reference/apis/js-apis-media.md#videosourcetype9) APIs shared by the old and new recording APIs are changed to non-system APIs.

**Change Impacts**

The [AudioRecorder](../../../application-dev/reference/apis/js-apis-media.md#audiorecorder)<sup>6+</sup> and [VideoRecorder](../../../application-dev/reference/apis/js-apis-media.md#videorecorder9)<sup>9+</sup> APIs can still be used but are no longer maintained. You are advised to use the [AVRecorder](../../../application-dev/reference/apis/js-apis-media.md#avrecorder9)<sup>9+</sup> API instead.

**Key API/Component Changes**

Added APIs

| Class                   | Declaration                                                |
| ----------------------- | ------------------------------------------------------------ |
| media                   | createAVRecorder(callback: AsyncCallback\<AVRecorder>): void |
| media                   | createAVRecorder() : Promise\<AVRecorder>                    |
| media.AVRecorder        | interface AVRecorder                                         |
| media.AVRecorder        | prepare(config: AVRecorderConfig, callback: AsyncCallback\<void>): void |
| media.AVRecorder        | prepare(config: AVRecorderConfig): Promise\<void>            |
| media.AVRecorder        | release(callback: AsyncCallback\<void>): void                |
| media.AVRecorder        | release(): Promise\<void>                                    |
| media.AVRecorder        | readonly state: AVRecorderState                              |
| media.AVRecorder        | on(type: 'stateChange', callback: (state: AVRecorderState, reason: StateChangeReason) => void): void |
| media.AVRecorder        | on(type: 'error', callback: ErrorCallback): void             |
| media.AVRecorder        | resume(callback: AsyncCallback\<void>): void                 |
| media.AVRecorder        | resume(): Promise\<void>                                     |
| media.AVRecorder        | start(callback: AsyncCallback\<void>): void                  |
| media.AVRecorder        | start(): Promise\<void>                                      |
| media.AVRecorder        | off(type: 'stateChange'): void                               |
| media.AVRecorder        | off(type: 'error'): void                                     |
| media.AVRecorder        | pause(callback: AsyncCallback\<void>): void                  |
| media.AVRecorder        | pause(): Promise\<void>                                      |
| media.AVRecorder        | stop(callback: AsyncCallback\<void>): void                   |
| media.AVRecorder        | stop(): Promise\<void>                                       |
| media.AVRecorder        | reset(callback: AsyncCallback\<void>): void                  |
| media.AVRecorder        | reset(): Promise\<void>                                      |
| media.AVRecorder        | getInputSurface(callback: AsyncCallback\<string>): void      |
| media.AVRecorder        | getInputSurface(): Promise\<string>                          |
| media.AVRecorderConfig  | videoSourceType?: VideoSourceType                            |
| media.AVRecorderConfig  | audioSourceType?: AudioSourceType                            |
| media.AVRecorderConfig  | profile: AVRecorderProfile                                   |
| media.AVRecorderConfig  | rotation?: number                                            |
| media.AVRecorderConfig  | url: string                                                  |
| media.AVRecorderConfig  | location?: Location                                          |
| media.AVRecorderConfig  | interface AVRecorderConfig                                   |
| media.AVRecorderProfile | videoBitrate?: number                                        |
| media.AVRecorderProfile | videoCodec?: CodecMimeType                                   |
| media.AVRecorderProfile | audioCodec?: CodecMimeType                                   |
| media.AVRecorderProfile | videoFrameRate?: number                                      |
| media.AVRecorderProfile | videoFrameHeight?: number                                    |
| media.AVRecorderProfile | audioSampleRate?: number                                     |
| media.AVRecorderProfile | audioBitrate?: number                                        |
| media.AVRecorderProfile | videoFrameWidth?: number                                     |
| media.AVRecorderProfile | audioChannels?: number                                       |
| media.AVRecorderProfile | fileFormat: ContainerFormatType                              |
| media.AVRecorderProfile | interface AVRecorderProfile                                  |
| unnamed                 | type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error' |

APIs no longer maintained

| Class                      | Declaration                                            |
| -------------------------- | ------------------------------------------------------------ |
| media                      | createVideoRecorder(callback: AsyncCallback\<VideoRecorder>): void |
| media                      | createVideoRecorder(): Promise\<VideoRecorder>               |
| media                      | createAudioRecorder(): AudioRecorder                         |
| media.AudioRecorder        | interface AudioRecorder                                      |
| media.AudioRecorder        | prepare(config: AudioRecorderConfig): void                   |
| media.AudioRecorder        | release(): void                                              |
| media.AudioRecorder        | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void |
| media.AudioRecorder        | on(type: 'error', callback: ErrorCallback): void             |
| media.AudioRecorder        | resume(): void                                               |
| media.AudioRecorder        | start(): void                                                |
| media.AudioRecorder        | pause(): void                                                |
| media.AudioRecorder        | stop(): void                                                 |
| media.AudioRecorder        | reset(): void                                                |
| media.AudioRecorderConfig  | audioSampleRate?: number                                     |
| media.AudioRecorderConfig  | location?: Location                                          |
| media.AudioRecorderConfig  | fileFormat?: ContainerFormatType                             |
| media.AudioRecorderConfig  | interface AudioRecorderConfig                                |
| media.AudioRecorderConfig  | audioEncoder?: AudioEncoder                                  |
| media.AudioRecorderConfig  | audioEncodeBitRate?: number                                  |
| media.AudioRecorderConfig  | numberOfChannels?: number                                    |
| media.AudioRecorderConfig  | format?: AudioOutputFormat                                   |
| media.AudioRecorderConfig  | uri: string                                                  |
| media.AudioRecorderConfig  | audioEncoderMime?: CodecMimeType                             |
| media.VideoRecorder        | interface VideoRecorder                                      |
| media.VideoRecorder        | prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void |
| media.VideoRecorder        | prepare(config: VideoRecorderConfig): Promise\<void>         |
| media.VideoRecorder        | release(callback: AsyncCallback\<void>): void                |
| media.VideoRecorder        | release(): Promise\<void>                                    |
| media.VideoRecorder        | readonly state: VideoRecordState                             |
| media.VideoRecorder        | on(type: 'error', callback: ErrorCallback): void             |
| media.VideoRecorder        | resume(callback: AsyncCallback\<void>): void                 |
| media.VideoRecorder        | resume(): Promise\<void>                                     |
| media.VideoRecorder        | start(callback: AsyncCallback\<void>): void                  |
| media.VideoRecorder        | start(): Promise\<void>                                      |
| media.VideoRecorder        | pause(callback: AsyncCallback\<void>): void                  |
| media.VideoRecorder        | pause(): Promise\<void>                                      |
| media.VideoRecorder        | stop(callback: AsyncCallback\<void>): void                   |
| media.VideoRecorder        | stop(): Promise\<void>                                       |
| media.VideoRecorder        | reset(callback: AsyncCallback\<void>): void                  |
| media.VideoRecorder        | reset(): Promise\<void>                                      |
| media.VideoRecorder        | getInputSurface(callback: AsyncCallback\<string>): void      |
| media.VideoRecorder        | getInputSurface(): Promise\<string>                          |
| media.VideoRecorderConfig  | videoSourceType: VideoSourceType                             |
| media.VideoRecorderConfig  | audioSourceType?: AudioSourceType                            |
| media.VideoRecorderConfig  | profile: VideoRecorderProfile                                |
| media.VideoRecorderConfig  | rotation?: number                                            |
| media.VideoRecorderConfig  | url: string                                                  |
| media.VideoRecorderConfig  | location?: Location                                          |
| media.VideoRecorderConfig  | interface VideoRecorderConfig                                |
| media.VideoRecorderProfile | readonly videoBitrate: number                                |
| media.VideoRecorderProfile | readonly videoCodec: CodecMimeType                           |
| media.VideoRecorderProfile | readonly audioCodec: CodecMimeType                           |
| media.VideoRecorderProfile | readonly videoFrameRate: number                              |
| media.VideoRecorderProfile | readonly videoFrameHeight: number                            |
| media.VideoRecorderProfile | readonly audioSampleRate: number                             |
| media.VideoRecorderProfile | readonly audioBitrate: number                                |
| media.VideoRecorderProfile | readonly videoFrameWidth: number                             |
| media.VideoRecorderProfile | readonly audioChannels: number                               |
| media.VideoRecorderProfile | readonly fileFormat: ContainerFormatType                     |
| media.VideoRecorderProfile | interface VideoRecorderProfile                               |
| unnamed                    | type VideoRecordState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error' |

Changed APIs

| Class                 | Declaration                                                    | Capability Before Change                                     | Capability After Change                                  | Whether a System API Before Change| Whether a System API After Change|
| --------------------- | ------------------------------------------------------------ | ----------------------------------------------- | -------------------------------------------- | -------------------- | -------------------- |
| media.AudioSourceType | enum AudioSourceType { /** * default audio source type. * @since 9 * @syscap SystemCapability.Multimedia.Media.AVRecorder */ AUDIO_SOURCE_TYPE_DEFAULT = 0, /** * source type mic. * @since 9 * @syscap SystemCapability.Multimedia.Media.AVRecorder */ AUDIO_SOURCE_TYPE_MIC = 1, } | SystemCapability.Multimedia.Media.VideoRecorder | SystemCapability.Multimedia.Media.AVRecorder | Yes                  | No                  |
| media.VideoSourceType | enum VideoSourceType { /** * surface raw data. * @since 9 * @syscap SystemCapability.Multimedia.Media.AVRecorder */ VIDEO_SOURCE_TYPE_SURFACE_YUV = 0, /** * surface ES data. * @since 9 * @syscap SystemCapability.Multimedia.Media.AVRecorder */ VIDEO_SOURCE_TYPE_SURFACE_ES = 1, } | SystemCapability.Multimedia.Media.VideoRecorder | SystemCapability.Multimedia.Media.AVRecorder | Yes                  | No                  |

**Adaptation Guide**

For details, see the [reference](../../../application-dev/reference/apis/js-apis-media.md) for each API.

## cl.media.3 Error Code Change

Added the standard error code enumeration type [AVErrorCode9](../../../application-dev/reference/apis/js-apis-media.md#averrorcode)<sup>9+</sup> that replaces the original error code enumeration type [MediaErrorCode](../../../application-dev/reference/apis/js-apis-media.md#mediaerrorcode)<sup>8+</sup>.

**Change Impacts**

The error code enumeration type [MediaErrorCode](../../../application-dev/reference/apis/js-apis-media.md#mediaerrorcode)<sup>8+</sup> is still used for original APIs. [AVErrorCode9](../../../application-dev/reference/apis/js-apis-media.md#averrorcode)<sup>9+</sup> is used for newly added APIs.

**Key API/Component Changes**

Added API

| Class             | Declaration                                              |
| ----------------- | ------------------------------------------------------------ |
| media.AVErrorCode | enum AVErrorCode { /** * operation success. * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_OK = 0, /** * permission denied. * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_NO_PERMISSION = 201, /** * invalid parameter. * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_INVALID_PARAMETER = 401, /** * the api is not supported in the current version * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_UNSUPPORT_CAPABILITY = 801, /** * the system memory is insufficient or the number of services reaches the upper limit * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_NO_MEMORY = 5400101, /** * current status does not allow or do not have permission to perform this operation * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_OPERATE_NOT_PERMIT = 5400102, /** * data flow exception information * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_IO = 5400103, /** * system or network response timeout. * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_TIMEOUT = 5400104, /** * service process died. * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_SERVICE_DIED = 5400105, /** * unsupported media format * @since 9 * @syscap SystemCapability.Multimedia.Media.Core */ AVERR_UNSUPPORT_FORMAT = 5400106, } |

API no longer maintained

| Class                | Declaration                                          |
| -------------------- | ------------------------------------------------------------ |
| media.MediaErrorCode | enum MediaErrorCode { /** * operation success. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_OK = 0, /** * malloc or new memory failed. maybe system have no memory. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_NO_MEMORY = 1, /** * no permission for the operation. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_OPERATION_NOT_PERMIT = 2, /** * invalid argument. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_INVALID_VAL = 3, /** * an I/O error occurred. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_IO = 4, /** * operation time out. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_TIMEOUT = 5, /** * unknown error. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_UNKNOWN = 6, /** * media service died. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_SERVICE_DIED = 7, /** * operation is not permit in current state. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_INVALID_STATE = 8, /** * operation is not supported in current version. * @since 8 * @syscap SystemCapability.Multimedia.Media.Core */ MSERR_UNSUPPORTED = 9, } |

 <!--no_check--> 