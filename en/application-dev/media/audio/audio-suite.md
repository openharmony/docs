# Audio Creation Overview (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=f74c65425449044869180c2c7706f4329d5a4b6a translatedAt=2026-08-06T01:49:08.834Z pushedAt=2026-08-06T08:35:23.440Z -->

Starting from API version 22, [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) is provided for audio creation. OHAudioSuite is a professional audio effects processing interface designed to help you efficiently build audio creation applications. It offers high-quality, low-latency, intelligent audio processing capabilities, and integrates a variety of audio effects such as noise reduction, equalization, and vocal separation. You can easily integrate these features into your application based on specific use cases.

OHAudioSuite is built around three core concepts: engine, pipeline, and node.

**Figure 1** Implementation principle of audio creation

![audiosuite-pipeline](figures/audiosuite-pipeline.png)

## Engine

The engine in [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) is an object that centrally manages audio pipelines and controls [offline editing (C/C++)](audio-suite-manual-rendering.md) and [real-time preview (C/C++)](audio-suite-real-time-rendering.md). You can build audio processing chains based on your requirements. The calling process is shown in the figure above: initiated by the app, the interfaces of [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) are called to sequentially create an engine, pipelines, and nodes. The created nodes are then connected within a pipeline to transmit PCM (Pulse Code Modulation) audio data, enabling the corresponding effect nodes to perform audio effect processing. When a pipeline is stopped, you can connect, disconnect, and remove nodes with certain restrictions (for specific rules, see [Pipeline Usage Rules](#pipeline-usage-rules)), achieving complex audio effect processing by adjusting node orchestration.

An engine supports the creation of up to 10 pipelines. Before API version 26.0.0, at most one pipeline could be dedicated to real-time preview. Starting from API version 26.0.0, the number of real-time preview pipelines is no longer separately restricted, but the total number of pipelines must still not exceed 10.

## Node

### Introduction to Nodes

A node is the minimum unit of audio rendering. It provides the corresponding audio effect processing capability based on its functionality. Nodes themselves cannot be called independently; they must be attached to pipelines and engines for use.

[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) supports three types of nodes: input node, output node, and effect node.

|Node Type  | Description   |
|----------|----------|
| INPUT_NODE  | Input node, which allows you to input PCM audio data in various formats. |
| EFFECT_NODE | Effect node, which allows you to add audio effects. Both single-input single-output and multi-input single-output are supported.|
| OUTPUT_NODE | Output node, which allows you to set the output format of PCM audio data. |

  For details about the complete node types, see [OH_AudioNode_Type](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type).

### Functionalities of Nodes

- Input nodes are responsible for processing the input of PCM audio data and obtaining data from the application side.

- Output nodes are responsible for processing the output of PCM audio data. You can set the output format of audio data.

- In [offline editing (C/C++)](audio-suite-manual-rendering.md) scenarios, audio effect nodes such as equalizers, source separation, sound field effects, noise reduction, voice beautification, environment effects, and audio mixer are supported.

- [Real-time preview (C/C++)](audio-suite-real-time-rendering.md) scenarios support equalizer effect nodes.

- Audio effect nodes such as equalizers, source separation, sound field effects, and noise reduction support corresponding audio effect processing functionalities and multi-audio mixing operations. The output format of PCM audio data can be set (such as [OH_Audio_SampleFormat (bit depth)](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat), [OH_Audio_SampleRate (sampling rate)](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), and [OH_AudioChannelLayout (number of channels)](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)).

## Pipeline

A pipeline is an object that centrally manages the connection and configuration of audio nodes. It supports two working modes: [offline editing (C/C++)](audio-suite-manual-rendering.md) and [real-time preview (C/C++)](audio-suite-real-time-rendering.md).

The pipeline data processing uses a reverse drive mechanism. Initiated by [OH_AudioSuiteEngine_RenderFrame()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_renderframe) or [OH_AudioSuiteEngine_MultiRenderFrame()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_multirenderframe), the output node requests data from the upstream connected nodes level by level, ultimately prompting the input node's [OH_InputNode_RequestDataCallback()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_inputnode_requestdatacallback) callback function to request the audio data to be processed from the developer.

**Figure 2** Pipeline running state

![audiosuite-pipeline-state](figures/audiosuite-pipeline-state.png)

The table below describes these states.

|State | Description   |
|----------|----------|
| stopped  | Initial state, or entered from the working state via the [OH_AudioSuiteEngine_StopPipeline()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_stoppipeline) command.<br>After switching to the stopped state, each node releases its buffers.  |
| running  | Working state, or entered from the initial state via the [OH_AudioSuiteEngine_StartPipeline()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_startpipeline) command.<br>This function performs a pipeline integrity check, including whether there are valid connections and whether any node has connection errors. |

### Functionalities of Pipelines

- The pipeline is the audio effect chain in [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) that supports applications in rendering PCM audio data. The pipeline supports flexible networking between nodes, providing a richer and more flexible audio creation experience.

- The pipeline is used in the following scenarios:

  Create an input node, an effect node (for example, an equalizer node [EFFECT_NODE_TYPE_EQUALIZER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)), and an output node, and connect them in the order of input node -> effect node -> output node to form a pipeline that implements the equalizer function (for a specific code example, see [Basic Offline Editing](audio-suite-manual-rendering.md#basic-offline-editing)). Pipelines also support multi-input scenarios (for a specific code example, see [Mixing and Cascading](audio-suite-manual-rendering.md#mixing-and-cascading)), where PCM data from each input passes through its respective effect node and is then mixed before output.

### Pipeline Usage Rules

A pipeline is composed of nodes. The rules for creating nodes in a pipeline are as follows.

- When a pipeline creates a node through the [OH_AudioSuiteEngine_CreateNode](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode) API, if the number of created nodes exceeds the system limit, the API returns the error code [AUDIOSUITE_ERROR_CREATED_EXCEED_SYSTEM_LIMITS](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_result).

  - Before API version 24, the number of input nodes [INPUT_NODE_TYPE_DEFAULT](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) must not exceed 5. Starting from API version 24, the number of input nodes [INPUT_NODE_TYPE_DEFAULT](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) must not exceed 15.

  - The number of output nodes [OUTPUT_NODE_TYPE_DEFAULT](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) must not exceed 1.

  - The number of mixer nodes [EFFECT_NODE_TYPE_AUDIO_MIXER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) must not exceed 3.

  - The number of source separation nodes [EFFECT_MULTII_OUTPUT_NODE_TYPE_AUDIO_SEPARATION](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) must not exceed 1.

  - Before API version 24, the number of other effect nodes of each type must not exceed 5. Starting from API version 24, the number of other effect nodes of each type must not exceed 15.

- Each pipeline must have at least one input node and exactly one output node.

- Before creating a node, call [OH_AudioSuiteEngine_IsNodeTypeSupported()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_isnodetypesupported) to check whether the node type is supported to avoid node creation failure.

- Input and output nodes support node format setting, whereas other nodes do not. The input format is the audio format of the audio source, and the output format is the audio format that you expect to output.

The rules for orchestrating nodes in a pipeline are as follows:

- The connection order of nodes in a pipeline is as follows: input node -> effect node -> output node.

- The source separation effect node [EFFECT_MULTII_OUTPUT_NODE_TYPE_AUDIO_SEPARATION](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) can only be connected to an output node. There is no such restriction for other effect nodes.

- The audio mixer effect node [EFFECT_NODE_TYPE_AUDIO_MIXER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) supports multiple input connections, whereas other nodes do not.

- Node connections are unidirectional, and reverse connections from subsequent nodes to preceding nodes are not supported. The input node is the first node in each pipeline, and the output node is the last node in each pipeline.

<!--RP1-->

## Samples

- [AudioSuiteSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioSuiteSample)

<!--RP1End-->