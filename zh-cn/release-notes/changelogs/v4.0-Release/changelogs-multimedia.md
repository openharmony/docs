# 媒体变更说明

## cl.multimedia.1 音频C接口播放焦点事件回调接口声明变更

对于在API10中新增的音频C接口，播放焦点事件回调接口错写为OH_AudioRenderer_OnInterrptEvent，需要修正为OH_AudioRenderer_OnInterruptEvent。

**变更影响**

对于已发布的C接口，可能影响三方应用的兼容性。

**关键的接口/组件变更**

修改前的接口原型：

 ```C
int32_t (*OH_AudioRenderer_OnInterrptEvent)(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

修改后的接口原型：

 ```C
int32_t (*OH_AudioRenderer_OnInterruptEvent)(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

**适配指导**

开发人员需要定义播放焦点事件时，使用的函数指针名称为OH_AudioRenderer_OnInterruptEvent。例如：

修改前

```C
OH_AudioRenderer_Callbacks callbacks;
callbacks.OH_AudioRenderer_OnInterrptEvent = AudioRendererOnInterrptEvent;
```

修改后

```C
OH_AudioRenderer_Callbacks callbacks;
callbacks.OH_AudioRenderer_OnInterruptEvent = AudioRendererOnInterrptEvent;
```

## cl.multimedia.2 音频C接口录音焦点事件回调接口声明变更

对于在API10中新增的音频C接口，录制焦点事件回调接口错写为OH_AudioCapturer_OnInterrptEvent，需要修正为OH_AudioCapturer_OnInterruptEvent。

**变更影响**

对于已发布的C接口，可能影响三方应用的兼容性。

**关键的接口/组件变更**

修改前的接口原型：

 ```C
int32_t (*OH_AudioCapturer_OnInterrptEvent)(
        OH_AudioCapturer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

修改后的接口原型：

 ```C
int32_t (*OH_AudioCapturer_OnInterruptEvent)(
        OH_AudioCapturer* capturer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

**适配指导**

开发人员需要定义录音焦点事件时，使用的函数指针名称为OH_AudioCapturer_OnInterruptEvent。例如：

修改前

```C
OH_AudioCapturer_Callbacks callbacks;
callbacks.OH_AudioCapturer_OnInterrptEvent = AudioCaptureOnInterruptEvent;
```

修改后

```C
OH_AudioCapturer_Callbacks callbacks;
callbacks.OH_AudioCapturer_OnInterruptEvent = AudioCaptureOnInterruptEvent;
```


## cl.multimedia.3 @ohos.multimedia.audio.d.ts内带入参的API10接口新增错误码声明

**变更影响**

携带入参的接口，当开发者参数类型或数量传错情况下，接口会同步抛出401错误码的异常，当参数值不符合取值范围，当接口为同步接口，会抛出相应错误码的异常，当接口为异步接口，会通过异步error返回错误码。
如果接口使用符合定义要求，则无兼容性影响。

**关键的接口/组件变更**

涉及新增错误声明的接口：

 ```ts
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback<AudioDeviceDescriptors>): void;
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise<AudioDeviceDescriptors>;
on(type: 'preferredOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback<AudioDeviceDescriptors>): void;
off(type: 'preferredOutputDeviceChangeForRendererInfo', callback?: Callback<AudioDeviceDescriptors>): void;
setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback<void>): void;
setAudioEffectMode(mode: AudioEffectMode): Promise<void>;
 ```

涉及新增的错误码类型：

 ```ts
// 入参类型或数量缺少
@throws { BusinessError } 401 - If input parameter type or number mismatch.
// 入参值不符合取值范围
@throws { BusinessError } 6800101 - Invalid parameter error.
// 系统通用内部错误
@throws { BusinessError } 6800301 - System error.
 ```

**适配指导**

接口使用时，当发现抛出错误码为401的异常，开发者需要检查传入的参数类型和数量是否符合接口定义。
当发现接口异步返回了错误，可以根据错误码，检查接口错误的原因，进行合理的异常处置。


## cl.multimedia.4 AudioRenderer.getCurrentOutputDevices接口实现错误修正

AudioRenderer的getCurrentOutputDevices接口，按照API定义，应返回AudioDeviceDescriptors类型，即AudioDeviceDescriptor类型的数组，但在历史版本内，实现和xts用例都错误的使用AudioDeviceDescriptor类型进行实现和测试，在新版本修复此问题，正确返回AudioDeviceDescriptors数组类型

**变更影响**

已在Beta版本发布的ts接口，影响按照错误的示范使用接口的三方应用的兼容性。

**关键的接口/组件变更**

修改前的接口原型：

```ts
// interface AudioRenderer
getCurrentOutputDevices(callback: AsyncCallback<AudioDeviceDescriptors>): void
getCurrentOutputDevices(): Promise<AudioDeviceDescriptors>;
```

修改后的接口原型：

接口定义不变，但实现正确返回AudioDeviceDescriptors数组类型

**适配指导**

如开发者需要按照接口声明的类型去使用API，无需适配。
如果参考了历史xts写法，并屏蔽了调用时与接口定义不匹配的告警，则需要修改为按照API定义使用。

## cl.multimedia.5 401同步错误码接口实现修正

部分含入参的API10接口，当开发者没有传递足够的必选参数，或是传递的参数类型错误，接口应当按照接口声明，以同步方式抛出异常，提醒开发者在应用调试过程中出现此类接口使用错误问题。
当前版本修正了部分接口没有按此预期抛出错误的问题

**变更影响**

仅影响错误使用接口的场景

**关键的接口/组件变更**

修改前的接口原型：

```ts
// interface AudioRenderer
adjustVolumeByStep(adjustType: VolumeAdjustType, callback: AsyncCallback<void>): void;
adjustVolumeByStep(adjustType: VolumeAdjustType): Promise<void>;
adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType, callback: AsyncCallback<void>): void;
adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType): Promise<void>;
getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType, callback: AsyncCallback<number>): void;
getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): Promise<number>;
setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback<void>): void;
setAudioEffectMode(mode: AudioEffectMode): Promise<void>;
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback<AudioDeviceDescriptors>): void;
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise<AudioDeviceDescriptors>;
```

修改后的接口原型：

```ts
// 401错误码声明描述调整
@throws { BusinessError } 401 - Input parameter type or number mismatch.
```

**适配指导**

正确使用API，无需适配。如发现抛出异常，则说明没有传递足够的必选参数，或是传递的参数类型错误，需要按照API定义传入参数。
