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

