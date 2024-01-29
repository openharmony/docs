# Multimedia Subsystem Changelog


## cl.multimedia.1 Stream Type Enum Declaration in Audio C APIs Changed

For the audio APIs of API version 10 in C, the audio output stream type is changed from **AUDIOSTREAM_TYPE_RERNDERER** to **AUDIOSTREAM_TYPE_RENDERER**.

**Change Impact**

Applications that use the involved APIs may have compatibility issues.

**Key API/Component Changes**

Before change:

```C
enum OH_AudioStream_Type {
   /**
    * The type for audio stream is renderer.
    */
   AUDIOSTREAM_TYPE_RERNDERER = 1,

   /**
    * The type for audio stream is capturer.
    */
   AUDIOSTREAM_TYPE_CAPTURER = 2
};
```

After change:

```C
enum OH_AudioStream_Type {
   /**
    * The type for audio stream is renderer.
    */
   AUDIOSTREAM_TYPE_RENDERER = 1,

   /**
    * The type for audio stream is capturer.
    */
   AUDIOSTREAM_TYPE_CAPTURER = 2
};
```

**Adaptation Guide**

Change **AUDIOSTREAM_TYPE_RERNDERER** to **AUDIOSTREAM_TYPE_RENDERER** in your code. Example:

Before change:

```C
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RERNDERER);
```

After change:

```C
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
```


## cl.multimedia.2 OH_AudioStream_Usage Changed

In the **native_audiostream_base.h** file of the audio APIs of API version 10 in C, for the **OH_AudioStream_Usage** enum, the enumerated value **AUDIOSTREAM_USAGE_MEDIA** is deleted, and **AUDIOSTREAM_USAGE_COMMUNICATION** is changed to **AUDIOSTREAM_USAGE_VOICE_COMMUNICATION** and **AUDIOSTREAM_USAGE_VOICE_ASSISTANT**.

**Change Impact**

Applications that use the involved APIs may have compatibility issues.  

**Key API/Component Changes**

Before change:

```C
typedef enum {
    AUDIOSTREAM_USAGE_UNKNOWN = 0,
    AUDIOSTREAM_USAGE_MEDIA = 1,
    AUDIOSTREAM_USAGE_COMMUNICATION = 2,
} OH_AudioStream_Usage;
```

After change:

```C
typedef enum {
    /**
     * Unknown usage.
     */
    AUDIOSTREAM_USAGE_UNKNOWN = 0,
    /**
     * Music usage.
     */
    AUDIOSTREAM_USAGE_MUSIC = 1,
    /**
     * Voice communication usage.
     */
    AUDIOSTREAM_USAGE_VOICE_COMMUNICATION = 2,
    /**
     * Voice assistant usage.
     */
    AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3,
    /**
     * Movie or video usage.
     */
    AUDIOSTREAM_USAGE_MOVIE = 10,

} OH_AudioStream_Usage;
```

**Adaptation Guide**

When using **OH_AudioStreamBuilder_SetRendererInfo**, set **OH_AudioStream_Usage** to **AUDIOSTREAM_USAGE_MUSIC** or **AUDIOSTREAM_USAGE_MOVIE**, rather than **AUDIOSTREAM_USAGE_MEDIA**.

Before change:

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MEDIA);
```

After change:

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC); // Music scene
```

Or:

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MOVIE); // Video scene
```

When using **OH_AudioStreamBuilder_SetRendererInfo**, set **OH_AudioStream_Usage** to **AUDIOSTREAM_USAGE_VOICE_COMMUNICATION** or **AUDIOSTREAM_USAGE_VOICE_ASSISTANT**, rather than **AUDIOSTREAM_USAGE_COMMUNICATION**.

Before change:

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_COMMUNICATION);
```

After change:

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_VOICE_COMMUNICATION); // Communication scene
```

Or:

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_VOICE_ASSISTANT); // Voice assistant scene
```


## cl.multimedia.3 AUDIOSTREAM_SAMPLE_F32LE Deleted for OH_AudioStream_SampleFormat

In the **native_audiostream_base.h** file of the audio APIs of API version 10 in C, the enumerated value **AUDIOSTREAM_SAMPLE_F32LE** is deleted for the **OH_AudioStream_SampleFormat** enum.

**Change Impact**

Applications that use the involved APIs may have compatibility issues.  

**Key API/Component Changes**

Before change:

```C
typedef enum {
    AUDIOSTREAM_SAMPLE_U8 = 0,
    AUDIOSTREAM_SAMPLE_S16LE = 1,
    AUDIOSTREAM_SAMPLE_S24LE = 2,
    AUDIOSTREAM_SAMPLE_S32LE = 3,
    AUDIOSTREAM_SAMPLE_F32LE = 4,
} OH_AudioStream_SampleFormat;
```

After change:

```C
typedef enum {
    /**
     * Unsigned 8 format.
     */
    AUDIOSTREAM_SAMPLE_U8 = 0,
    /**
     * Signed 16 bit integer, little endian.
     */
    AUDIOSTREAM_SAMPLE_S16LE = 1,
    /**
     * Signed 24 bit integer, little endian.
     */
    AUDIOSTREAM_SAMPLE_S24LE = 2,
    /**
     * Signed 32 bit integer, little endian.
     */
    AUDIOSTREAM_SAMPLE_S32LE = 3,
} OH_AudioStream_SampleFormat;
```

**Adaptation Guide**

Do not use **AUDIOSTREAM_SAMPLE_F32LE** for **OH_AudioStream_SampleFormat**.


## cl.multimedia.4 Deleted content from getAudioEffectInfoArray

The input parameter **content** is deleted from **getAudioEffectInfoArray**.

**Change Impact**

Applications that use the involved APIs may have compatibility issues.

**Key API/Component Changes**

Before change:

```js
getAudioEffectInfoArray(content: ContentType, usage: StreamUsage, callback: AsyncCallback<AudioEffectInfoArray>): void;
getAudioEffectInfoArray(content: ContentType, usage: StreamUsage): Promise<AudioEffectInfoArray>;
```

After change:

```js
getAudioEffectInfoArray(usage: StreamUsage, callback: AsyncCallback<AudioEffectInfoArray>): void;
getAudioEffectInfoArray(usage: StreamUsage): Promise<AudioEffectInfoArray>;
```

**Adaptation Guide**

When calling this API, pass in only the input parameter **usage**. If **getAudioEffectInfoArray** is used in your application code, delete the **content** parameter.


## cl.multimedia.5 Playback APIs Changed

The APIs related to audio track switching are deleted.

**Change Impact**

These APIs are unavailable.

**Key API/Component Changes**

The deleted APIs are as follows:

| Class| API|
| -------- | -------- |
| Media.Core | MD_KEY_LANGUAGE |
| Media.AVPlayer | selectTrack(index:&nbsp;number):&nbsp;void |
| Media.AVPlayer | deselectTrack(index:&nbsp;number):&nbsp;void |
| Media.AVPlayer | getCurrentTrack(trackType:&nbsp;MediaType,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void |
| Media.AVPlayer | getCurrentTrack(trackType:&nbsp;MediaType):&nbsp;Promise&lt;number&gt; |
| Media.AVPlayer | on(type:&nbsp;'trackChange',&nbsp;callback:&nbsp;(index:&nbsp;number,&nbsp;isSelect:&nbsp;boolean)&nbsp;=&gt;&nbsp;void):&nbsp;void; |
| Media.AVPlayer | off(type:&nbsp;'trackChange'):&nbsp;void |
