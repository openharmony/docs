# 多媒体子系统ChangeLog

## cl.multimedia.audio.001 getRoutingManager()调用方式变更

getRoutingManager()接口的调用方法由异步变为同步。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
getRoutingManager(callback: AsyncCallback<AudioRoutingManager>): void;
getRoutingManager(): Promise<AudioRoutingManager>;
```
变更后
```js
getRoutingManager(): AudioRoutingManager;
```


## cl.multimedia.audio.002 getStreamManager()调用方式变更

getStreamManager()接口的调用方法由异步变为同步。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
getStreamManager(callback: AsyncCallback<AudioStreamManager>): void;
getStreamManager(): Promise<AudioStreamManager>;
```
变更后
```js
getStreamManager(): AudioStreamManager;
```


## cl.multimedia.audio.003 原AudioRoutingManager中micStateChange监听注册方式变更

原AudioRoutingManager中，on()函数的micStateChange监听注册方式变更。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前

```js
interface AudioRoutingManager {
   on(type: 'micStateChange', callback: Callback<MicStateChangeEvent>): void;
}
```
变更后
```js
interface AudioVolumeGroupManager {
  on(type: 'micStateChange', callback: Callback<MicStateChangeEvent>): void;
}
```


## cl.multimedia.audio.004 getVolumeGroups()调用方式变更

getVolumeGroups()接口的调用方式变更。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
getVolumeGroups(networkId: string, callback:AsyncCallback<VolumeGroupInfos>): void;
getVolumeGroups(networkId: string): Promise<VolumeGroupInfos>;
```
变更后
```js
getVolumeManager(): AudioVolumeManager;
interface AudioVolumeManager{
  getVolumeGroupInfos(networkId: string, callback: AsyncCallback<VolumeGroupInfos>): void;
  getVolumeGroupInfos(networkId: string): Promise<VolumeGroupInfos>;
}
```


## cl.multimedia.audio.005 getGroupManager()调用方式变更

getGroupManager()接口的调用方式变更。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
getGroupManager(groupId: number, callback: AsyncCallback<AudioGroupManager>): void;
getGroupManager(groupId: number): Promise<AudioGroupManager>;
```
变更后
```js
getVolumeManager(): AudioVolumeManager;
interface AudioVolumeManager{
  getVolumeGroupManager(groupId: number, callback: AsyncCallback<AudioVolumeGroupManager>): void;
  getVolumeGroupManager(groupId: number): Promise<AudioVolumeGroupManager>;
}
```


## cl.multimedia.audio.006 枚举FocusType成员名变更

枚举FocusType中，成员FOCUS_TYPE_RECORDING重命名为FOCUS_TYPE_DEFAULT。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
enum FocusType {
  FOCUS_TYPE_RECORDING = 0,
}
```
变更后
```js
enum InterruptRequestType {
  INTERRUPT_REQUEST_TYPE_DEFAULT = 0,
}
```


## cl.multimedia.audio.007 AudioRenderer中interrupt监听注册名称变更

AudioRenderer中on()函数的interrupt监听注册名称变更。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
interface AudioRenderer {
    on(type: 'interrupt', callback: Callback<InterruptEvent>): void;
}
```
变更后
```js
interface AudioRenderer {
    on(type: 'audioInterrupt', callback: Callback<InterruptEvent>): void;
}
```


## cl.multimedia.media.001 VideoRecorder相关接口变更为systemapi

录制在MR版本会提供正式的AVRecorder（音视频合一）的接口给外部用户使用。
VideoRecorder相关的api9接口变更为systemapi，当前只提供给系统用户使用，未来等内部用户都切换为AVRecorder之后，废弃VideoRecorder相关接口。

**变更影响**

如果VideoRecorder的调用者非系统用户，会调用失败。
涉及接口以及枚举如下：
function createVideoRecorder(callback: AsyncCallback<VideoRecorder>): void;
function createVideoRecorder(): Promise<VideoRecorder>;
type VideoRecordState = 'idle' | 'prepared' | 'playing' | 'paused' | 'stopped' | 'error';
interface VideoRecorder{
    prepare(config: VideoRecorderConfig, callback: AsyncCallback<void>): void;
    prepare(config: VideoRecorderConfig): Promise<void>;
    getInputSurface(callback: AsyncCallback<string>): void;
    getInputSurface(): Promise<string>;
    start(callback: AsyncCallback<void>): void;
    start(): Promise<void>;
    pause(callback: AsyncCallback<void>): void;
    pause(): Promise<void>;
    resume(callback: AsyncCallback<void>): void;
    resume(): Promise<void>;
    stop(callback: AsyncCallback<void>): void;
    stop(): Promise<void>;
    release(callback: AsyncCallback<void>): void;
    release(): Promise<void>;
    reset(callback: AsyncCallback<void>): void;
    reset(): Promise<void>;
    on(type: 'error', callback: ErrorCallback): void;
    readonly state: VideoRecordState;
}
interface VideoRecorderProfile {
    readonly audioBitrate: number;
    readonly audioChannels: number;
    readonly audioCodec: CodecMimeType;
    readonly audioSampleRate: number;
    readonly fileFormat: ContainerFormatType;
    readonly videoBitrate: number;
    readonly videoCodec: CodecMimeType;
    readonly videoFrameWidth: number;
    readonly videoFrameHeight: number;
    readonly videoFrameRate: number;  
}
enum AudioSourceType {
    AUDIO_SOURCE_TYPE_DEFAULT = 0,
    AUDIO_SOURCE_TYPE_MIC = 1,
}
enum VideoSourceType {
    VIDEO_SOURCE_TYPE_SURFACE_YUV = 0,
    VIDEO_SOURCE_TYPE_SURFACE_ES = 1,
}
enum VideoRecorderConfig {
    audioSourceType?: AudioSourceType;
    videoSourceType: VideoSourceType;
    profile: VideoRecorderProfile;
    url: string;
    rotation?: number;
    location?: Location;
}

## cl.multimedia.media.002 VideoPlayer中不对外提供多码率选择接口

VideoPlayer在API9中不对外提供多码率选择相关接口，相关接口会在MR版本中由AvPlayer提供。

**变更影响**

VideoPlayer多码率场景无法进行码率选择，相关功能由AVPlayer提供

**关键的接口/组件变更**

删除如下接口
interface VideoPlayer {
    selectBitrate(bitrate: number): Promise<number>;
    selectBitrate(bitrate: number, callback: AsyncCallback<number>): void;
    on(type: 'availableBitratesCollect', callback: (bitrates: Array<number>) => void): void;
}

## cl.multimedia.media.003 VideoRecorder错误信息变更

VideoRecorder原有错误码与整体错误码规则不一致，变更错误码适配规则。

**变更影响**

VideoRecorder返回的错误码发生变更。

**关键的接口/组件变更**

VideoRecorder接口未发生变更，返回的错误码发生变更。

**适配指导**

异常处理具体参考接口文档。
https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-media.md
https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/errorcodes/errorcode-media.md
