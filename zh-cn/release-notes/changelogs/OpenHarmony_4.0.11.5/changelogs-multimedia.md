# multimedia子系统ChangeLog

## cl.multimedia.1 AudioRenderer.getCurrentOutputDevices接口实现错误修正

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

## cl.multimedia.2 401同步错误码接口实现修正

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
