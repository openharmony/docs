# 开发指导

***【写作要求】***


*必选*。 *描述各个场景下，开发者如何完成开发任务*。 *可根据多场景任务增加章节。写作要求见下，完成写作后，请逐项自检*。


| 内容要求 | 是否满足 |
| -------- | -------- |
| 如果有多个场景，请写起多个“开发指导”章节，如音频播放开发指导、音量管理开发指导、短音播放开发指导。 |  |
| 标题尽量使用“动词+名词”的句式表述任务操作。 |  |


## 场景介绍

***【写作要求】***

*必选*。 *描述在什么情景下解决什么问题，最终达到什么样的效果*。应用SCQA描述方法：

- S：situation（情景），由大家都熟悉的的情景，事实引入。

- C：complication（冲突），但是实际情况往往和我们的要求有冲突。

- Q：question（疑问），怎么办？

- A：answer（回答），我们的解决方案是 …

*写作要求见下，完成写作后，请逐项自检*。

| 内容要求 | 是否满足 |
| -------- | -------- |
| 背景原因、什么时候在哪、做了什么操作、最终解决什么问题或操作效果都明确。 |  |

【**写作样例**】

音频播放的主要工作是将音频数据转码为可听见的音频模拟信号并通过输出设备进行播放，同时对播放任务进行管理。


## 接口说明

*【**写作要求**】*

*必选*。 *描述本开发指导相关的接口有哪些，旨在要开发者在开发前有大体了解，提升开发效率*。 *写作要求见下，完成写作后，请逐项自检*。

| 内容要求 | 是否满足 |
| -------- | -------- |
| 不在本开发任务的接口无需提供。 |  |
| 如果接口太多，超过10个，可以提供主要的接口 |  |

【**写作样例**】

音频播放开放能力如下：AudioRenderer类，具体的API详见接口文档。

**表1**  音频播放API接口功能介绍

| 接口名 | 描述 |
| -------- | -------- |
| AudioRenderer(AudioRendererInfo audioRendererInfo, PlayMode pm) throws IllegalArgumentException | 构造函数，设置播放相关音频参数和播放模式，使用默认播放设备 |
| AudioRenderer(AudioRendererInfo audioRendererInfo, PlayMode pm, AudioDeviceDescriptor outputDevice) throws IllegalArgumentException | 构造函数，设置播放相关音频参数、播放模式和播放设备 |
| boolean play() | 播放音频流 |
| boolean write(byte[] data, int offset, int size) | 将音频数据以byte流写入音频接收器以进行播放 |


## 开发步骤

*【**写作要求**】*

 *必选。描述*  *开发的整体过程，便于开发者快速完成开发*。*具体写作要求见下，完成写作后，请逐项自检下*。

| 内容要求 | 是否满足 |
| -------- | -------- |
| **如何写好步骤** |  |
| 步骤完整：提供必需的步骤，顺利指导完成操作，无缺失。 |  |
| 脉络清楚：文档逻辑清晰、合理。文档前面的概述、准备、操作围绕一条线描述，不能章节断裂或前后矛盾的现象。 |  |
| 任务句式：标题或句子尽量使用“动词+名词”的句式表述动作。 |  |
| 预防提前：操作过程中的限制、易错的、有潜在风险的，要提前描述，使用DOCS平台的“插入&gt;&nbsp;说明&nbsp;&gt;&nbsp;须知”描述。 |  |
| 步骤清晰-1：无论步骤简单或复杂，都需要写步骤目的，即为什么做。 |  |
| 步骤清晰-2：明确在什么环境下，使用什么工具，做什么操作，怎么做该操作。 |  |
| 步骤具体：如果操作可选，要明确可选条件。 |  |
| 在开发步骤执行完成后，及时明确操作正确的标准。 |  |
| **如何写好代码段** |  |
| 代码涉及开发者拷贝的命令，必须用可编辑的报文呈现，避免截图，使用代码片段包裹。 |  |
| 代码中关键段用蓝色（RGB：0.0.255）突出显示，关键步骤要有注释说明。 |  |
| 代码显示符合代码缩进要求。 |  |
| 步骤涉及接口调用，清晰给出接口及其使用说明或示例代码，代码来源于具体实例。 |  |

【**写作样例**】

1. 构造音频流参数的数据结构AudioStreamInfo，推荐使用AudioStreamInfo.Builder类来构造，模板如下，模板中设置的均为AudioStreamInfo.Builder类的默认值，根据音频流的具体规格来设置具体参数。
   ```
   AudioStreamInfo audioStreamInfo = new AudioStreamInfo.Builder()
    .sampleRate(    AudioStreamInfo.SAMPLE_RATE_UNSPECIFIED)    
    .audioStreamFlag(AudioStreamInfo.AudioStreamFlag.AUDIO_STREAM_FLAG_NONE)
    .encodingFormat(AudioStreamInfo.EncodingFormat.ENCODING_INVALID)
    .channelMask(AudioStreamInfo.ChannelMask.CHANNEL_INVALID)
    .streamUsage(AudioStreamInfo.StreamUsage.STREAM_USAGE_UNKNOWN)    
    .build();
   ```

    以真实的播放pcm流为例：
      ```
   AudioStreamInfo audioStreamInfo = new AudioStreamInfo.Builder().sampleRate(44100)//44.1kHz            
    .audioStreamFlag(AudioStreamInfo.AudioStreamFlag.AUDIO_STREAM_FLAG_MAY_DUCK)//混音            
    .encodingFormat(AudioStreamInfo.EncodingFormat.ENCODING_PCM_16BIT)//16-bit PCM    
    .channelMask(AudioStreamInfo.ChannelMask.CHANNEL_OUT_STEREO)//双声道    
    .streamUsage(AudioStreamInfo.StreamUsage.STREAM_USAGE_MEDIA)//媒体类音频
    .build();
      ```

2. 使用步骤1创建的音频流构建音频播放的参数结构AudioRendererInfo，推荐使用AudioRendererInfo.Builder类来构造，模板如下，模板中设置的均为AudioRendererInfo.Builder类的默认值，根据音频播放的具体规格来设置具体参数。
   ```
   AudioRendererInfo audioRendererInfo = new AudioRendererInfo.Builder()
    .audioStreamInfo(audioStreamInfo)
    .audioStreamOutputFlag(AudioRendererInfo.AudioStreamOutputFlag.AUDIO_STREAM_OUTPUT_FLAG_NONE)
    .bufferSizeInBytes(0)
    .distributedDeviceId("")
    .isOffload(false)
    .sessionID(AudioRendererInfo.SESSION_ID_UNSPECIFIED)
    .build();
   ```

    以真实的播放pcm流为例：
      ```
   AudioRendererInfo audioRendererInfo = new AudioRendererInfo.Builder()
    .audioStreamInfo(audioStreamInfo)
    .audioStreamOutputFlag(AudioRendererInfo.AudioStreamOutputFlag.AUDIO_STREAM_OUTPUT_FLAG_DIRECT_PCM)//pcm格式的输出流
    .bufferSizeInBytes(100)
    .distributedDeviceId("E54***5E8")//使用分布式设备E54***5E8播放
    .isOffload(false)//false表示分段传输buffer并播放，true表示整个音频流一次性传输到HAL层播放
    .build();
      ```

3. 根据要播放音频流指定PlayMode，不同的PlayMode在写数据时存在差异，详情见步骤7，其余播放流程是无区别的。并通过构造函数获取AudioRenderer类的实例化对象。
   
4. 播放任务结束后，调用AudioRenderer实例化对象的release()释放资源。


## 调测验证（可选）

*【**写作要求**】*

*可选*。 *描述开发完成后，进行调测验证，确保最终操作成功*。*操作步骤要求同“开发指导”，其他具体写作要求见下，完成写作后，请逐项自检下*。

| 内容要求 | 是否满足 |
| -------- | -------- |
| 仅进行最后的业务调测，每个小任务的操作结果，在开发步骤执行完成后，及时验证操作结果。 |  |
| 明确开发成功标准。 |  |

## 开发实例
*【**写作要求**】*

*提供完整的sample示例，同时简要描述示例原理和实现，并链接到源码仓*。

针对xxx开发，有以下示例工程可供参考：

- xxx（此处请提供源码超链接）

 本示例xxxx。
