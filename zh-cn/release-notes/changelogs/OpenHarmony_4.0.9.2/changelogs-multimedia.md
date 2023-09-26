# multimedia子系统ChangeLog

## cl.multimedia.1 音频C接口流类型枚举声明变更

对于在API10中已经新增的音频C接口，音频输出流类型错写为AUDIOSTREAM_TYPE_RERNDERER，需要修正为AUDIOSTREAM_TYPE_RENDERER。

**变更影响**

对于已发布的C接口，可能影响三方应用的兼容性。

**关键的接口/组件变更**

修改前的接口原型：

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

修改后的接口原型：

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

**适配指导**

开发人员需要在使用音频输出流类型AUDIOSTREAM_TYPE_RERNDERER时，修改为AUDIOSTREAM_TYPE_RENDERER。例如：

修改前

```C
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RERNDERER);
```

修改后

```C
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
```

## cl.multimedia.2 移除OH_AudioStream_Content

对于在API10中已经新增的音频C接口，音频输出流属性中将删除掉OH_AudioStream_Content。

**变更影响**

对于已发布的C接口，可能影响三方应用的兼容性。

**关键的接口/组件变更**

- native_audiostream_base.h 文件

修改前的接口原型：

```C
typedef enum {
    AUDIOSTREAM_CONTENT_TYPE_UNKNOWN = 0,
    AUDIOSTREAM_CONTENT_TYPE_SPEECH = 1,
    AUDIOSTREAM_CONTENT_TYPE_MUSIC = 2,
    AUDIOSTREAM_CONTENT_TYPE_MOVIE = 3,
} OH_AudioStream_Content;
```
修改后
删除OH_AudioStream_Content枚举定义

- native_audiostreambuilder.h 文件

修改前

```C
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder* builder,
    OH_AudioStream_Usage usage, OH_AudioStream_Content content);
```

修改后
```C
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder* builder,
    OH_AudioStream_Usage usage);
```

- native_audiorenderer.h 文件

修改前

```C
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer* renderer,
    OH_AudioStream_Usage* usage, OH_AudioStream_Content* content);
```

修改后
```C
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer* renderer,
    OH_AudioStream_Usage* usage);
```

**适配指导**

对于OH_AudioStreamBuilder_SetRendererInfo接口，开发者按照所属场景，原本设置的OH_AudioStream_Content类型可对比下表，使用对应的OH_AudioStream_Usage类型。

| OH_AudioStream_Content          | OH_AudioStream_Usage                  |
| ------------------------------- | ------------------------------------- |
| AUDIOSTREAM_CONTENT_TYPE_SPEECH | AUDIOSTREAM_USAGE_VOICE_COMMUNICATION |
| AUDIOSTREAM_CONTENT_TYPE_MUSIC  | AUDIOSTREAM_USAGE_MUSIC               |
| AUDIOSTREAM_CONTENT_TYPE_MOVIE  | AUDIOSTREAM_USAGE_MOVIE               |

对于OH_AudioRenderer_GetRendererInfo接口，开发者使用新的接口只能获取到OH_AudioStream_Usage属性，不能获取OH_AudioStream_Content属性。

## cl.multimedia.3 OH_AudioStream_Usage变更

API10的音频C接口native_audiostream_base.h 文件中，在OH_AudioStream_Usage枚举中删除了AUDIOSTREAM_USAGE_MEDIA枚举值，将AUDIOSTREAM_USAGE_COMMUNICATION枚举值变更为AUDIOSTREAM_USAGE_VOICE_COMMUNICATION和AUDIOSTREAM_USAGE_VOICE_ASSISTANT。

**变更影响**

对于已发布的C接口，可能影响三方应用的兼容性。如果开发者使用AUDIOSTREAM_USAGE_MEDIA和AUDIOSTREAM_USAGE_COMMUNICATION枚举值，会有兼容性问题。

**关键的接口/组件变更**

修改前

```C
typedef enum {
    AUDIOSTREAM_USAGE_UNKNOWN = 0,
    AUDIOSTREAM_USAGE_MEDIA = 1,
    AUDIOSTREAM_USAGE_COMMUNICATION = 2,
} OH_AudioStream_Usage;
```

修改后
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

**适配指导**

用户通过OH_AudioStreamBuilder_SetRendererInfo接口不能再设置OH_AudioStream_Usage值为AUDIOSTREAM_USAGE_MEDIA，改为使用AUDIOSTREAM_USAGE_MUSIC或者AUDIOSTREAM_USAGE_MOVIE。

修改前

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MEDIA);
```

修改后

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC); // 音乐场景
```

或者

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MOVIE); // 视频场景
```

用户通过OH_AudioStreamBuilder_SetRendererInfo接口不能再设置OH_AudioStream_Usage值为AUDIOSTREAM_USAGE_COMMUNICATION，改为使用AUDIOSTREAM_USAGE_VOICE_COMMUNICATION或者AUDIOSTREAM_USAGE_VOICE_ASSISTANT。

修改前

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_COMMUNICATION);
```

修改后

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_VOICE_COMMUNICATION); // 通话场景
```

或者

```C
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_VOICE_ASSISTANT); // 语音场景
```

## cl.multimedia.4 OH_AudioStream_SampleFormat变更，删除AUDIOSTREAM_SAMPLE_F32LE

API10的音频C接口native_audiostream_base.h 文件中，在OH_AudioStream_SampleFormat枚举中删除了AUDIOSTREAM_SAMPLE_F32LE枚举值。

**变更影响**

对于已发布的C接口，可能影响三方应用的兼容性。如果开发者使用AUDIOSTREAM_SAMPLE_F32LE会有兼容性问题。

**关键的接口/组件变更**

修改前

```C
typedef enum {
    AUDIOSTREAM_SAMPLE_U8 = 0,
    AUDIOSTREAM_SAMPLE_S16LE = 1,
    AUDIOSTREAM_SAMPLE_S24LE = 2,
    AUDIOSTREAM_SAMPLE_S32LE = 3,
    AUDIOSTREAM_SAMPLE_F32LE = 4,
} OH_AudioStream_SampleFormat;
```

修改后
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

**适配指导**

修改后用户不能再设置采样格式为AUDIOSTREAM_SAMPLE_F32LE枚举值。

## cl.multimedia.5 OH_AudioStream_Result添加枚举值

API10的音频C接口native_audiostream_base.h 文件中，在OH_AudioStream_Result枚举中给枚举值定义数值。

**变更影响**

无影响

**关键的接口/组件变更**

修改前

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

修改后
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

**适配指导**

无兼容性影响，不涉及。
