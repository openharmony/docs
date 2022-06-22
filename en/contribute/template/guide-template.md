# Development Guidelines

***[Writing Requirements]***


*Mandatory. Describe how a developer completes tasks in a specific scenario. Include one scenario in each section. The table below describes the writing requirements. After finishing the writing, check your content against these requirements one by one.*  


| Requirement| Satisfied or Not|
| -------- | -------- |
| Each section covers only one scenario. If there are multiple scenarios, provide development guidelines for each scenario in separate sections. For example, you can use the following sections in **Audio**: **Development Guidelines on Audio Playback**, **Development Guidelines on Volume Management**, and **Development Guidelines on Sound Playback**.|  |
| Use verbs + nouns to describe task operations in titles.|  |


## When to Use

***[Writing Requirements]***

*Mandatory. Describe in which scenario, what problem is solved, and what the final effect is. Use the SCQA method.*

- *S: situation. Introduce a familiar scenario.*

- *C: complication. Describe the conflict between the situation and requirement.*

- *Q: question. Ask a question. What can I do in such a case?*

- *A: answer. Describe the solution.*

*The table below describes the writing requirements. After finishing the writing, check your content against these requirements one by one.*  

| Requirement| Satisfied or Not|
| -------- | -------- |
| Clearly describe the background, what operations are done when and where, what problems are solved, and what benefits are delivered.|  |

***[Example]***

You can use APIs described in this section to convert audio data into audible analog signals, play the audio signals using output devices, and manage playback tasks.


## Available APIs

***[Writing Requirements]***

*Mandatory. Describe APIs involved in the development guideline to help developers have a general understanding of the APIs, thereby improving development efficiency. The table below describes the writing requirements. After finishing the writing, check your content against these requirements one by one.*  

| Requirement| Satisfied or Not|
| -------- | -------- |
| Include only APIs relevant to the development task.|  |
| If there are more than 10 APIs, you can provide only main APIs.|  |

***[Example]***

The **AudioRenderer** class provides open audio playback capabilities. For details about the APIs, see the API reference.

**Table 1** Audio playback APIs

| API| Description|
| -------- | -------- |
| AudioRenderer(AudioRendererInfo audioRendererInfo, PlayMode pm) throws IllegalArgumentException | A constructor used to create an **AudioRenderer** instance based on the specified playback parameters, the specified playback mode, and the default playback device.|
| AudioRenderer(AudioRendererInfo audioRendererInfo, PlayMode pm, AudioDeviceDescriptor outputDevice) throws IllegalArgumentException | A constructor used to create an **AudioRenderer** instance based on the specified playback parameters, playback mode, and playback device.|
| boolean play() | Plays audio streams.|
| boolean write(byte[] data, int offset, int size) | Writes audio data in the specified byte array into an audio receiver for playback.|


## How to Develop

***[Writing Requirements]***

 *Mandatory. Describe the overall process to help developers quickly complete the task. The table below describes the writing requirements. After finishing the writing, check your content against these requirements one by one.*  

| Requirement| Satisfied or Not|
| -------- | -------- |
| **Writing a Development Procedure**|  |
| Complete: All mandatory steps are provided.|  |
| Clear: The logic of the writing is clear and reasonable. The overview, preparations, and operations in the document are described by following certain logic, and the chapters are not broken or contradictory.|  |
| Sentence pattern for tasks: Use verbs + nouns to describe actions in titles or sentences.|  |
| Prevention in advance: Describe the restrictions, error-prone operations, and potential risks in advance. Use general icons and styles.|  |
| Clear steps-1: Describe the purpose of each step, no matter whether it is simple or not.|  |
| Clear steps-2: Specify the environment, tools, operations, and how-to.|  |
| If an operation is optional, specify the optional conditions.|  |
| After the development procedure is complete, specify the expected results.|  |
| **Writing a Code Segment**|  |
| If a code segment involves commands to be copied by developers, display the commands in editable mode, instead of using screenshots. Use code snippets to wrap the commands.|  |
| Highlight key code segments in blue (RGB: 0.0.255), and comment out key steps.|  |
| The code display meets the code indentation requirements.|  |
| If an API call is involved in a step, provide the API and its usage description or sample code. The code comes from specific instances.|  |

***[Example]***

1. Use **AudioStreamInfo.Builder** to create an **AudioStreamInfo** instance for audio stream parameters. The following example uses the default values of the input parameters for **AudioStreamInfo.Builder**. You need to set the parameters based on the audio stream specification.
   ```
   AudioStreamInfo audioStreamInfo = new AudioStreamInfo.Builder()
    .sampleRate(AudioStreamInfo.SAMPLE_RATE_UNSPECIFIED)
    .audioStreamFlag(AudioStreamInfo.AudioStreamFlag.AUDIO_STREAM_FLAG_NONE)
    .encodingFormat(AudioStreamInfo.EncodingFormat.ENCODING_INVALID)
    .channelMask(AudioStreamInfo.ChannelMask.CHANNEL_INVALID)
    .streamUsage(AudioStreamInfo.StreamUsage.STREAM_USAGE_UNKNOWN)
    .build();
   ```

   Example code for playing a PCM stream:
   ```
   AudioStreamInfo audioStreamInfo = new AudioStreamInfo.Builder().sampleRate(44100)// 44.1 kHz
    .audioStreamFlag(AudioStreamInfo.AudioStreamFlag.AUDIO_STREAM_FLAG_MAY_DUCK)// Set audio ducking.
    .encodingFormat(AudioStreamInfo.EncodingFormat.ENCODING_PCM_16BIT)//16-bit PCM
    .channelMask(AudioStreamInfo.ChannelMask.CHANNEL_OUT_STEREO)// Set the dual output channel.
    .streamUsage(AudioStreamInfo.StreamUsage.STREAM_USAGE_MEDIA)// Set the stream to be used for media.    
    .build();
   ```
2. Build the playback parameter structure via **AudioRendererInfo** for the audio stream created in Step 1, and use **AudioRendererInfo.Builder** to create an instance. The following example uses the default parameter values of the **AudioRendererInfo.Builder** instance. You need to set the playback parameters based on the audio playback specification.
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

    Example code for playing a PCM stream:
      ```
   AudioRendererInfo audioRendererInfo = new AudioRendererInfo.Builder()
    .audioStreamInfo(audioStreamInfo)
    .audioStreamOutputFlag(AudioRendererInfo.AudioStreamOutputFlag.AUDIO_STREAM_OUTPUT_FLAG_DIRECT_PCM)// Set direct PCM output.
    .bufferSizeInBytes(100)    
    .distributedDeviceId("E54***5E8")// Use distributed device E54***5E8 for playback.   
    .isOffload(false)// Value false indicates that the audio stream is transmitted to the buffer on a segment-by-segment basis for several times and then played. Value true indicates that the audio stream is transmitted to the HAL layer at a time.
    .build();
      ```
   
3. Specify the playback mode based on the audio stream to be played. The playback modes differ only in the data writing process. Create an **AudioRenderer** instance using a constructor that fits your need.

4. After the playback task is complete, call the **release()** method on the **AudioRenderer** instance to release resources.


## (Optional) Commissioning and Verification

***[Writing Requirements]***

*Optional. After the development is complete, perform commissioning and verification to ensure that the operation is successful. The operation procedure requirements are the same as those in **Development Guidelines**. Other specific writing requirements are as follows. After finishing the writing, check your content against these requirements one by one.*  

| Requirement| Satisfied or Not|
| -------- | -------- |
| Describe the final service commissioning process. The operation result of each step should be verified after the corresponding development task is complete.|  |
| Specify the criteria for development success.|  |

## Development Example
***[Writing Requirements]***

*Provide a complete sample, briefly describe the principle and implementation of the sample, and provide a link to the source code repository.*  

The following sample is provided to help you better understand how to xx:

- xxx (A link to the source code repository)

 This sample xxx.
