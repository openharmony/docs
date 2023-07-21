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

## cl.multimedia.2 OH_AudioStream_Content Removed

For the audio APIs of API version 10 in C, **OH_AudioStream_Content** is removed for the audio output stream attributes.

**Change Impact**

Applications that use the involved APIs may have compatibility issues.

**Key API/Component Changes**

- In the **native_audiostream_base.h** file

  Before change:

  ```C
  typedef enum {
      AUDIOSTREAM_CONTENT_TYPE_UNKNOWN = 0,
      AUDIOSTREAM_CONTENT_TYPE_SPEECH = 1,
      AUDIOSTREAM_CONTENT_TYPE_MUSIC = 2,
      AUDIOSTREAM_CONTENT_TYPE_MOVIE = 3,
  } OH_AudioStream_Content;
  ```

  After change: **OH_AudioStream_Content** is removed.

- In the **native_audiostreambuilder.h** file

  Before change:

  ```C
  OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder* builder,
      OH_AudioStream_Usage usage, OH_AudioStream_Content content);
  ```

  After change:

  ```C
  OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder* builder,
      OH_AudioStream_Usage usage);
  ```

- In the **native_audiorenderer.h** file

  Before change:

  ```C
  OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer* renderer,
      OH_AudioStream_Usage* usage, OH_AudioStream_Content* content);
  ```

  After change:

  ```C
  OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer* renderer,
      OH_AudioStream_Usage* usage);
  ```

**Adaptation Guide**

When using **OH_AudioStreamBuilder_SetRendererInfo**, check the original **OH_AudioStream_Content** type against the following table and use the corresponding **OH_AudioStream_Usage** type based on the scenario.

| OH_AudioStream_Content          | OH_AudioStream_Usage                  |
| ------------------------------- | ------------------------------------- |
| AUDIOSTREAM_CONTENT_TYPE_SPEECH | AUDIOSTREAM_USAGE_VOICE_COMMUNICATION |
| AUDIOSTREAM_CONTENT_TYPE_MUSIC  | AUDIOSTREAM_USAGE_MUSIC               |
| AUDIOSTREAM_CONTENT_TYPE_MOVIE  | AUDIOSTREAM_USAGE_MOVIE               |

**OH_AudioRenderer_GetRendererInfo** can be used to obtain the **OH_AudioStream_Usage** attribute but not the **OH_AudioStream_Content** attribute.

## cl.multimedia.3 OH_AudioStream_Usage Changed

In the **native_audiostream_base.h** file of the audio interfaces of API version 10 in C, for the **OH_AudioStream_Usage** enum, the enumerated value **AUDIOSTREAM_USAGE_MEDIA** is deleted, and **AUDIOSTREAM_USAGE_COMMUNICATION** is changed to **AUDIOSTREAM_USAGE_VOICE_COMMUNICATION** and **AUDIOSTREAM_USAGE_VOICE_ASSISTANT**.

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

## cl.multimedia.4 AUDIOSTREAM_SAMPLE_F32LE Deleted for **OH_AudioStream_SampleFormat**

In the **native_audiostream_base.h** file of the audio interfaces of API version 10 in C, the enumerated value **AUDIOSTREAM_SAMPLE_F32LE** is deleted for the **OH_AudioStream_SampleFormat** enum.

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

## cl.multimedia.5 Enumerated Values Added for OH_AudioStream_Result

In the **native_audiostream_base.h** file of the audio interfaces of API version 10 in C, new enumerated values are added for the **OH_AudioStream_Result** enum.

**Change Impact**

None.

**Key API/Component Changes**

Before change:

```C
typedef enum {
    /**
     * The call was successful.
     */
    AUDIOSTREAM_SUCCESS,

    /**
     * This means that the function was executed with an invalid input parameter.
     */
    AUDIOSTREAM_ERROR_INVALID_PARAM,

    /**
     * Execution status exception.
     */
    AUDIOSTREAM_ERROR_ILLEGAL_STATE,

    /**
     * An system error has occurred.
     */
    AUDIOSTREAM_ERROR_SYSTEM
} OH_AudioStream_Result;
```

After change:
```C
typedef enum {
    /**
     * The call was successful.
     */
    AUDIOSTREAM_SUCCESS = 0,

    /**
     * This means that the function was executed with an invalid input parameter.
     */
    AUDIOSTREAM_ERROR_INVALID_PARAM = 1,

    /**
     * Execution status exception.
     */
    AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2,

    /**
     * An system error has occurred.
     */
    AUDIOSTREAM_ERROR_SYSTEM = 3
} OH_AudioStream_Result;
```

**Adaptation Guide**

No adaptation is required.
