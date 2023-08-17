# multimedia子系统ChangeLog

## cl.multimedia.1 preferOutputDeviceForRendererInfo系列接口命名变更

对于getPreferOutputDeviceForRendererInfo和对应的on/off订阅接口，命名内preferOutput变更为preferredOutput，与新增的preferredInput相匹配，满足英文翻译要求

**变更影响**

已在Beta版本发布的ts接口，影响使用此三方应用的兼容性。

**关键的接口/组件变更**

修改前的接口原型：

 ```ts
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback<AudioDeviceDescriptors>): void;
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise<AudioDeviceDescriptors>;
on(type: 'preferOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback<AudioDeviceDescriptors>): void;
off(type: 'preferOutputDeviceChangeForRendererInfo', callback?: Callback<AudioDeviceDescriptors>): void;
 ```

修改后的接口原型：

 ```ts
getPreferredOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback<AudioDeviceDescriptors>): void;
getPreferredOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise<AudioDeviceDescriptors>;
on(type: 'preferredOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback<AudioDeviceDescriptors>): void;
off(type: 'preferredOutputDeviceChangeForRendererInfo', callback?: Callback<AudioDeviceDescriptors>): void;
 ```

**适配指导**

修改后开发者调用该接口时，需要使用修改后的接口命名定义。
系统会暂时兼容两种命名方式的接口调用，但建议在使用新版本SDK后立即修改适配。

## cl.multimedia.2 @ohos.multimedia.audio.d.ts内带入参的API10接口新增错误码声明

**变更影响**

携带入参的接口，当开发者参数类型或数量传错情况下，接口会同步抛出401错误码的异常，当参数值不符合取值范围，当接口为同步接口，会抛出相应错误码的异常，当接口为异步接口，会通过异步error返回错误码。
如果接口使用符合定义要求，则无兼容性影响。

**关键的接口/组件变更**

涉及新增错误声明的接口：

 ```ts
getPreferredOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback<AudioDeviceDescriptors>): void;
getPreferredOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise<AudioDeviceDescriptors>;
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
