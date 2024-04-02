# 媒体Changelog


## cl.multimedia.1 音频C接口流类型枚举声明变更

对于在API10中已经新增的音频C接口，音频输出流类型名称为AUDIOSTREAM_TYPE_RERNDERER，在最新版本修正为AUDIOSTREAM_TYPE_RENDERER。

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


## cl.multimedia.2 OH_AudioStream_Usage变更

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


## cl.multimedia.3 OH_AudioStream_SampleFormat变更，删除AUDIOSTREAM_SAMPLE_F32LE

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


## cl.multimedia.4 getAudioEffectInfoArray接口入参变更，删除Content type入参

对于getAudioEffectInfoArray，适配4.0.9.2修改，删除Content type入参。

**变更影响**

对于已发布的js接口，可能影响三方应用的兼容性。

**关键的接口/组件变更**

修改前的接口原型：

```js
getAudioEffectInfoArray(content: ContentType, usage: StreamUsage, callback: AsyncCallback<AudioEffectInfoArray>): void;
getAudioEffectInfoArray(content: ContentType, usage: StreamUsage): Promise<AudioEffectInfoArray>;
```

修改后的接口原型：

```js
getAudioEffectInfoArray(usage: StreamUsage, callback: AsyncCallback<AudioEffectInfoArray>): void;
getAudioEffectInfoArray(usage: StreamUsage): Promise<AudioEffectInfoArray>;
```

**适配指导**

修改后用户调用该接口时，只需要传入StreamUsage入参，对于已经适配的用户，直接删去ContentType type入参即可。


## cl.multimedia.5 播放功能接口变更

删除音轨切换相关接口。

**变更影响**

删除音轨切换相关接口，相关接口不可使用。

**关键的接口/组件变更**

删除接口如下：

| 类名 | 删除接口声明 | 
| -------- | -------- |
| Media.Core | MD_KEY_LANGUAGE | 
| Media.AVPlayer | selectTrack(index:&nbsp;number):&nbsp;void | 
| Media.AVPlayer | deselectTrack(index:&nbsp;number):&nbsp;void | 
| Media.AVPlayer | getCurrentTrack(trackType:&nbsp;MediaType,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 
| Media.AVPlayer | getCurrentTrack(trackType:&nbsp;MediaType):&nbsp;Promise&lt;number&gt; | 
| Media.AVPlayer | on(type:&nbsp;'trackChange',&nbsp;callback:&nbsp;(index:&nbsp;number,&nbsp;isSelect:&nbsp;boolean)&nbsp;=&gt;&nbsp;void):&nbsp;void; | 
| Media.AVPlayer | off(type:&nbsp;'trackChange'):&nbsp;void | 
