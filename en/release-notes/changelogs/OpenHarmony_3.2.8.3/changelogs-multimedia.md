# Multimedia Subsystem ChangeLog

## cl.multimedia.audio.001 Call Mode Change of getRoutingManager()

**getRoutingManager()** is changed from asynchronous to synchronous.

**Change Impacts**

If the new mode is not used, an error will be reported during compilation.

**Key API/Component Changes**

Before change:
```js
getRoutingManager(callback: AsyncCallback<AudioRoutingManager>): void;
getRoutingManager(): Promise<AudioRoutingManager>;
```
After change:
```js
getRoutingManager(): AudioRoutingManager;
```


## cl.multimedia.audio.002 Call Mode Change of getStreamManager()

**getStreamManager()** is changed from asynchronous to synchronous.

**Change Impacts**

If the new mode is not used, an error will be reported during compilation.

**Key API/Component Changes**

Before change:
```js
getStreamManager(callback: AsyncCallback<AudioStreamManager>): void;
getStreamManager(): Promise<AudioStreamManager>;
```
After change:
```js
getStreamManager(): AudioStreamManager;
```


## cl.multimedia.audio.003 Registration Mode Change of micStateChange

In the original **AudioRoutingManager**, the registration mode of the **micStateChange** listener of the **on()** function is changed.

**Change Impacts**

If the new mode is not used, an error will be reported during compilation.

**Key API/Component Changes**

Before change:

```js
interface AudioRoutingManager {
   on(type: 'micStateChange', callback: Callback<MicStateChangeEvent>): void;
}
```
After change:
```js
interface AudioVolumeGroupManager {
  on(type: 'micStateChange', callback: Callback<MicStateChangeEvent>): void;
}
```


## cl.multimedia.audio.004 Call Mode Change of getVolumeGroups()

The call mode of **getVolumeGroups()** is changed.

**Change Impacts**

If the new mode is not used, an error will be reported during compilation.

**Key API/Component Changes**

Before change:
```js
getVolumeGroups(networkId: string, callback:AsyncCallback<VolumeGroupInfos>): void;
getVolumeGroups(networkId: string): Promise<VolumeGroupInfos>;
```
After change:
```js
getVolumeManager(): AudioVolumeManager;
interface AudioVolumeManager{
  getVolumeGroupInfos(networkId: string, callback: AsyncCallback<VolumeGroupInfos>): void;
  getVolumeGroupInfos(networkId: string): Promise<VolumeGroupInfos>;
}
```


## cl.multimedia.audio.005 Call Mode Change of getGroupManager()

The call mode of **getGroupManager()** is changed.

**Change Impacts**

If the new mode is not used, an error will be reported during compilation.

**Key API/Component Changes**

Before change:
```js
getGroupManager(groupId: number, callback: AsyncCallback<AudioGroupManager>): void;
getGroupManager(groupId: number): Promise<AudioGroupManager>;
```
After change:
```js
getVolumeManager(): AudioVolumeManager;
interface AudioVolumeManager{
  getVolumeGroupManager(groupId: number, callback: AsyncCallback<AudioVolumeGroupManager>): void;
  getVolumeGroupManager(groupId: number): Promise<AudioVolumeGroupManager>;
}
```


## cl.multimedia.audio.006 FocusType Member Name Change

**FOCUS_TYPE_RECORDING** of **FocusType** is renamed as **FOCUS_TYPE_DEFAULT**.

**Change Impacts**

If the new name is not used, an error will be reported during compilation.

**Key API/Component Changes**

Before change:
```js
enum FocusType {
  FOCUS_TYPE_RECORDING = 0,
}
```
After change:
```js
enum InterruptRequestType {
  INTERRUPT_REQUEST_TYPE_DEFAULT = 0,
}
```


## cl.multimedia.audio.007 Listener Registration Name Change of interrupt

The listener registration name of **interrupt** of the **on()** function in **AudioRenderer** is changed.

**Change Impacts**

If the new name is not used, an error will be reported during compilation.

**Key API/Component Changes**

Before change:
```js
interface AudioRenderer {
    on(type: 'interrupt', callback: Callback<InterruptEvent>): void;
}
```
After change:
```js
interface AudioRenderer {
    on(type: 'audioInterrupt', callback: Callback<InterruptEvent>): void;
}
```


## cl.multimedia.media.001 Change of VideoRecorder APIs to System APIs

In the MR version, the formal **AVRecorder** APIs (integrating audio and video) will be provided for external use.
**VideoRecorder** APIs in API version 9 are changed to system APIs, which are available only to system users. In the future, **VideoRecorder** APIs will be deprecated after system users switch to **AVRecorder**.

**Change Impacts**

If the **VideoRecorder** caller is not a system user, the call will fail.

Involved APIs and enumerations:

function createVideoRecorder(callback: AsyncCallback<VideoRecorder>): void;

function createVideoRecorder(): Promise<VideoRecorder>;

type VideoRecordState = 'idle' | 'prepared' | 'playing' | 'paused' | 'stopped' | 'error';

interface VideoRecorder{

​    prepare(config: VideoRecorderConfig, callback: AsyncCallback<void>): void;

​    prepare(config: VideoRecorderConfig): Promise<void>;

​    getInputSurface(callback: AsyncCallback<string>): void;

​    getInputSurface(): Promise<string>;

​    start(callback: AsyncCallback<void>): void;

​    start(): Promise<void>;

​    pause(callback: AsyncCallback<void>): void;

​    pause(): Promise<void>;

​    resume(callback: AsyncCallback<void>): void;

​    resume(): Promise<void>;

​    stop(callback: AsyncCallback<void>): void;

​    stop(): Promise<void>;

​    release(callback: AsyncCallback<void>): void;

​    release(): Promise<void>;

​    reset(callback: AsyncCallback<void>): void;

​    reset(): Promise<void>;

​    on(type: 'error', callback: ErrorCallback): void;

​    readonly state: VideoRecordState;

}

interface VideoRecorderProfile {

​    readonly audioBitrate: number;

​    readonly audioChannels: number;

​    readonly audioCodec: CodecMimeType;

​    readonly audioSampleRate: number;

​    readonly fileFormat: ContainerFormatType;

​    readonly videoBitrate: number;

​    readonly videoCodec: CodecMimeType;

​    readonly videoFrameWidth: number;

​    readonly videoFrameHeight: number;

​    readonly videoFrameRate: number; 

}

enum AudioSourceType {

​    AUDIO_SOURCE_TYPE_DEFAULT = 0,

​    AUDIO_SOURCE_TYPE_MIC = 1,

}

enum VideoSourceType {

​    VIDEO_SOURCE_TYPE_SURFACE_YUV = 0,

​    VIDEO_SOURCE_TYPE_SURFACE_ES = 1,

}

enum VideoRecorderConfig {

​    audioSourceType?: AudioSourceType;

​    videoSourceType: VideoSourceType;

​    profile: VideoRecorderProfile;

​    url: string;

​    rotation?: number;

​    location?: Location;

}

## cl.multimedia.media.002 No Externally Provided Bit Rate Selection API in VideoPlayer

In API version 9, **VideoPlayer** does not externally provide the bit rate selection API. Such an API will be provided by **AVPlayer** in the MR version.

**Change Impacts**

Bit rate selection cannot be performed in the multi-bit rate scenario of **VideoPlayer**. Relevant functions will be provided by **AVPlayer**.

**Key API/Component Changes**

Deleted APIs:

interface VideoPlayer {

​    selectBitrate(bitrate: number): Promise<number>;

​    selectBitrate(bitrate: number, callback: AsyncCallback<number>): void;

​    on(type: 'availableBitratesCollect', callback: (bitrates: Array<number>) => void): void;

}

## cl.multimedia.media.003 Error Information Change of VideoRecorder

Original error codes of **VideoRecorder** are changed because they do not comply with the error code specifications.

**Change Impacts**

Error codes returned from **VideoRecorder** are changed.

**Key API/Component Changes**

**VideoRecorder** APIs remain unchanged, but the returned error codes are changed.

**Adaptation Guide**

For details about exception handling, see the following documents:
[Media](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-media.md)
[Media Error Codes](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/errorcodes/errorcode-media.md)
