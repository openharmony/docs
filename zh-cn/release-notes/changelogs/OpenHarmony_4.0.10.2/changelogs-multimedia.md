# multimedia子系统ChangeLog

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
