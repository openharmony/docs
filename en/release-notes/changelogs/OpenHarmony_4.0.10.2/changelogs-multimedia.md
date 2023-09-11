# Multimedia Subsystem Changelog

## cl.multimedia.1 Changed the Declaration of the Focus Event Callback of Audio Renderer C APIs

For the audio renderer C APIs of API version 10, the focus event callback is changed from **OH_AudioRenderer_OnInterrptEvent** to **OH_AudioRenderer_OnInterruptEvent**.

**Change Impact**

Applications that use the involved APIs may have compatibility issues.

**Key API/Component Changes**

Before change:

 ```C
int32_t (*OH_AudioRenderer_OnInterrptEvent)(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

After change:

 ```C
int32_t (*OH_AudioRenderer_OnInterruptEvent)(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

**Adaptation Guide**

To define the focus event for an audio renderer, use the function pointer **OH_AudioRenderer_OnInterruptEvent**. Example:

Before change:

```C
OH_AudioRenderer_Callbacks callbacks;
callbacks.OH_AudioRenderer_OnInterrptEvent = AudioRendererOnInterrptEvent;
```

After change:

```C
OH_AudioRenderer_Callbacks callbacks;
callbacks.OH_AudioRenderer_OnInterruptEvent = AudioRendererOnInterrptEvent;
```

## cl.multimedia.2 Changed the Declaration of the Focus Event Callback of Audio Capturer C APIs

For the audio capturer C APIs of API version 10, the focus event callback is changed from **OH_AudioCapturer_OnInterrptEvent** to **OH_AudioCapturer_OnInterruptEvent**.

**Change Impact**

Applications that use the involved APIs may have compatibility issues.

**Key API/Component Changes**

Before change:

 ```C
int32_t (*OH_AudioCapturer_OnInterrptEvent)(
        OH_AudioCapturer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

After change:

 ```C
int32_t (*OH_AudioCapturer_OnInterruptEvent)(
        OH_AudioCapturer* capturer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint);
 ```

**Adaptation Guide**

To define the focus event for an audio capturer, use the function pointer **OH_AudioCapturer_OnInterruptEvent**. Example:

Before change:

```C
OH_AudioCapturer_Callbacks callbacks;
callbacks.OH_AudioCapturer_OnInterrptEvent = AudioCaptureOnInterruptEvent;
```

After change:

```C
OH_AudioCapturer_Callbacks callbacks;
callbacks.OH_AudioCapturer_OnInterruptEvent = AudioCaptureOnInterruptEvent;
```
