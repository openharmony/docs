# multimedia子系统ChangeLog

## cl.multimedia.1 5400102错误码实现修正

部分含入参的API10接口，当开发者传递的参数错误，或状态机异常（如load未完成就直接play），接口应当按照API声明抛出操作异常，提醒开发者在应用调试过程中出现此类接口使用问题。
当前版本修正了部分接口没有按此预期抛出错误的问题

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number): Promise<number>
play(soundID: number, params: PlayParameters, callback: AsyncCallback<number>): void
play(soundID: number, callback: AsyncCallback<number>): void
play(soundID: number, params?: PlayParameters): Promise<number>
stop(streamID: number, callback: AsyncCallback<void>): void
stop(streamID: number): Promise<void>
setLoop(streamID: number, loop: number): Promise<void>
setPriority(streamID: number, priority: number): Promise<void>
setRate(streamID: number, rate: audio.AudioRendererRate): Promise<void>
setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise<void>
unload(soundID: number): Promise<void>
```

修改后，上述接口新增5400102错误码声明:

```ts
@throws { BusinessError } 5400102 - Operation not allowed.
```

**适配指导**

正确使用API，无需适配。如发现抛出异常，则说明传入参数有误，或状态机异常，需要按照API定义调用接口。

## cl.multimedia.2 5400103错误码实现修正

部分含入参的API10接口，当开发者调用接口发生媒体与其他模块的数据交互问题（I/O ERROR）的时候，接口应当按照接口声明抛出异常，提醒开发者在应用调试过程中出现此类接口使用问题。
当前版本修正了部分接口没有按此预期抛出错误的问题

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number, callback: AsyncCallback<number>): void
load(fd: number, offset: number, length: number): Promise<number>
unload(soundID: number): Promise<void>
```

修改后，上述接口新增5400103错误码声明:

```ts
@throws { BusinessError } 5400103 - I/O error.
```

**适配指导**

正确使用API，无需适配。如发现抛出异常，则说明发生媒体与其他模块的数据交互问题，需要按照API定义调用接口。

## cl.multimedia.3 5400105错误码实现修正

部分含入参的API10接口，当调用接口发生播放服务死亡时，接口应当按照接口声明抛出异常，提醒开发者在应用调试过程中出现此类接口使用问题。
当前版本修正了部分接口没有按此预期抛出错误的问题

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number): Promise<number>
play(soundID: number, params?: PlayParameters): Promise<number>
stop(streamID: number): Promise<void>
setLoop(streamID: number, loop: number): Promise<void>
setPriority(streamID: number, priority: number): Promise<void>
setRate(streamID: number, rate: audio.AudioRendererRate): Promise<void>
setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise<void>
unload(soundID: number): Promise<void>
release(): Promise<void>
```

修改后，上述接口新增5400105错误码声明:

```ts
@throws { BusinessError } 5400105 - Service died.
```

**适配指导**

正确使用API，无需适配。如发现抛出异常，则说明当前播放服务死亡，需要按照API定义调用接口。

## cl.multimedia.4 SoundPool.on('loadComplete')接口实现错误修正

SoundPool的on('loadComplete')接口，按照API定义，开发者调用接口进行加载完成监听，发生错误时通过on('error')回调接口抛出。历史版本中接口抛出错误码的设计多余，在新版本中修复此问题。

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
on(type: 'loadComplete', callback: Callback<number>): void
```

修改后，上述接口不进行错误码声明:

```ts
@param {'loadComplete'} type Type of the play finish event to listen for.
@param {Callback<number>} callback Callback used to listen for load result event
@syscap SystemCapability.Multimedia.Media.SoundPool
@since 10
```

**适配指导**

正确使用API，无需适配。按照API定义调用接口，发生错误时通过on('error')回调接口抛出，不需要针对接口进行抛出错误码的设计。

## cl.multimedia.5 SoundPool.on('playFinished')接口实现错误修正

SoundPool的on('playFinished')接口，按照API定义，开发者调用接口进行播放完成监听，发生错误时通过on('error')回调接口抛出。历史版本中接口抛出错误码的设计多余，在新版本中修复此问题。

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
on(type: 'playFinished', callback: Callback<void>): void
```

修改后，上述接口不进行错误码声明:

```ts
@param {'loadComplete'} type Type of the play finish event to listen for.
@param {Callback<number>} callback Callback used to listen for load result event
@syscap SystemCapability.Multimedia.Media.SoundPool
@since 10
```

**适配指导**

正确使用API，无需适配。按照API定义调用接口，发生错误时通过on('error')回调接口抛出，不需要针对接口进行抛出错误码的设计。

## cl.multimedia.6 401错误码实现修正

部分含入参的API10接口，当开发者调用接口时缺少入参，接口应当按照API声明抛出401操作异常，提醒开发者在应用调试过程中出现了此类接口使用问题。
当前版本修正了部分接口没有按此预期抛出错误的问题

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
play(soundID: number, params: PlayParameters, callback: AsyncCallback<number>): void;
play(soundID: number, callback: AsyncCallback<number>): void;
play(soundID: number, params?: PlayParameters): Promise<number>;
stop(streamID: number, callback: AsyncCallback<void>): void;
stop(streamID: number): Promise<void>;
setLoop(streamID: number, loop: number, callback: AsyncCallback<void>): void;
setLoop(streamID: number, loop: number): Promise<void>;
setPriority(streamID: number, priority: number, callback: AsyncCallback<void>): void;
setPriority(streamID: number, priority: number): Promise<void>;
setRate(streamID: number, rate: audio.AudioRendererRate, callback: AsyncCallback<void>): void;
setRate(streamID: number, rate: audio.AudioRendererRate): Promise<void>;
setVolume(streamID: number, leftVolume: number, rightVolume: number, callback: AsyncCallback<void>): void;
setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise<void>;
```

修改后，上述接口新增401错误码声明:

```ts
@throws { BusinessError } 401 - The parameter check failed. Return by callback.
```

**适配指导**

正确使用API，无需适配。如发现抛出异常，则说明当前接口调用缺少必要参数，需要按照API定义调用接口。

## cl.multimedia.1 audioRenderer和audioCapturer回调接口变更

**访问级别**

公开接口

**变更原因**

audioRenderer和audioCapturer回调接口,为了更准确反馈当前流的发声/录音设备，回调信息存在变化。

**变更影响**

非播放/录音状态时，AudioRendererChangeInfo.deviceDescriptors和AudioCapturerChangeInfo.deviceDescriptors为空设备。

**变更发生版本**

从OpenHarmony SDK 4.1.3.3开始。

**变更的接口/组件**

变更前：

on(type: 'audioRendererChange', callback: Callback<AudioRendererChangeInfoArray>): void;

on(type: 'audioCapturerChange', callback: Callback<AudioCapturerChangeInfoArray>): void;

非播放/录音状态时，AudioRendererChangeInfo.deviceDescriptors和AudioCapturerChangeInfo.deviceDescriptors为上一次播放/录音的设备。

变更后：

on(type: 'audioRendererChange', callback: Callback<AudioRendererChangeInfoArray>): void;

on(type: 'audioCapturerChange', callback: Callback<AudioCapturerChangeInfoArray>): void;

非播放/录音状态时，AudioRendererChangeInfo.deviceDescriptors和AudioCapturerChangeInfo.deviceDescriptors为空设备。

**适配指导**

修改后用户调用该接口时，如果需要通过回调获取当前发声/录音设备，需要先启动播放/录音。

## cl.multimedia.2 cameraInput的open和on回调接口行为变更

**访问级别**

公开接口

**变更原因**

cameraInput的open接口，新增抢占机制，保证高优先级应用可以优先使用相机，open和on回调接口行为出现变化。

**变更影响**

该变更为非兼容性变更，可能影响三方应用的兼容性。

**变更发生版本**

从OpenHarmony SDK 4.1.3.3开始。

**变更的接口/组件**

变更前：

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void;

open(callback: AsyncCallback<void>): void;

当存在其他应用正在使用相机设备时，当前应用使用open接口打开失败，回调CONFLICT_CAMERA错误码；

变更后：

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void;

open(callback: AsyncCallback<void>): void;

当存在其他应用正在使用相机设备时，当前应用若优先级高于其他应用，比如处于前台，其他应用已退后台，此时使用open接口打开成功，

之前使用相机的应用会收到回调DEVICE_PREEMPTED错误码；

**适配指导**

在使用cameraInput的on回调接口时，需要对错误码增加DEVICE_PREEMPTED错误的处理逻辑。

## cl.multimedia.1 getValidCommandsSync接口变更

**访问级别**

公开接口

**变更原因**

接口原实现返回成错误的int类型，现按照接口定义，修改返回为正确的AVControlCommandType类型。

**变更影响**

该变更为非兼容性变更，需要开发者进行适配。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

getValidCommandsSync(): Array<AVControlCommandType>

**适配指导**

变更前：

使用已创建的AVSession，获取controller支持的指令，返回值为int数组

let validCommands = avsession.getController().getValidCommandsSync();

例如若应用只注册了play指令回调，validCommands[0]就等于0

变更后：

使用已创建的AVSession，获取controller支持的指令，返回值为AVControlCommandType类型的string数组

let validCommands = avsession.getController().getValidCommandsSync();

例如若应用只注册了play指令回调，validCommands[0]就等于'play'

## cl.multimedia.1 getDevices接口变更

**访问级别**

公开接口

**变更原因**

对于有听筒的设备，即使非通话状态听筒也可以通过接口查询到。

**变更影响**

对于有听筒的设备，当DeviceFlag为OUTPUT_DEVICES_FLAG、ALL_DEVICES_FLAG时，非通话场景返回值也会包含EARPIECE设备。

**变更发生版本**

从OpenHarmony SDK 4.1.5.1开始。

**变更的接口/组件**

变更前：

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;

getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;

对于有听筒的设备，当DeviceFlag为OUTPUT_DEVICES_FLAG、ALL_DEVICES_FLAG时，只有通话场景返回值才会包含EARPIECE设备。

变更后：

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;

getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;

对于有听筒的设备，当DeviceFlag为OUTPUT_DEVICES_FLAG、ALL_DEVICES_FLAG时，非通话场景返回值也会包含EARPIECE设备。

**适配指导**

修改后用户调用该接口时，如果需要判断其返回值，需要增加EARPIECE设备的判断。