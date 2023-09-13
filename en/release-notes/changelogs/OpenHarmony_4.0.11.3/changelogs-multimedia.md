# Multimedia Subsystem Changelog

## cl.multimedia.1 Added Error Code Declaration for APIs of API Version 10 with Input Parameters in @ohos.multimedia.audio.d.ts

**Change Impact**

For an API that carries input parameters, if the parameter type or quantity is incorrect, error code 401 is thrown synchronously. If the parameter value is out of the value range, the corresponding error code is thrown directly for a synchronous API and returned through the **error** object for an asynchronous API.
If the API usage meets the definition requirements, there is no compatibility impact.

**Key API/Component Changes**

The following APIs are involved:

 ```ts
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback<AudioDeviceDescriptors>): void;
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise<AudioDeviceDescriptors>;
on(type: 'preferredOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback<AudioDeviceDescriptors>): void;
off(type: 'preferredOutputDeviceChangeForRendererInfo', callback?: Callback<AudioDeviceDescriptors>): void;
setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback<void>): void;
setAudioEffectMode(mode: AudioEffectMode): Promise<void>;
 ```

The following error code types are added:

 ```ts
// The input parameter type or quantity is incorrect.
@throws { BusinessError } 401 - If input parameter type or number mismatch.
// The input parameter value is out of the value range.
@throws { BusinessError } 6800101 - Invalid parameter error.
// Common internal system error.
@throws { BusinessError } 6800301 - System error.
 ```

**Adaptation Guide**

If error code 401 is thrown, check whether the type and quantity of input parameters comply with the API definition.
If other codes are thrown, check the possible causes and handle the exceptions properly.
