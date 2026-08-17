# Audio Effects (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=19889a99389d4cf8eb3285184cf910e9c13f48e4 translatedAt=2026-08-15T01:57:18.674Z pushedAt=2026-08-15T09:28:43.420Z -->

Since API version 22, [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) provides various audio effect nodes. You can select appropriate effect nodes to process audio based on your service requirements.

## Effect Node Types

| Effect Type | Node Type | Since | Purpose | Description |
|---------|---------|--------|------|------|
| [Equalizer](#equalizer) | EFFECT_NODE_TYPE_EQUALIZER | API version 22 | Adjusts frequency bands to change the frequency characteristics of audio. | - |
| [Noise reduction](#noise-reduction) | EFFECT_NODE_TYPE_NOISE_REDUCTION | API version 22 | Reduces background noise and improves voice clarity. | - |
| [Sound field](#sound-field) | EFFECT_NODE_TYPE_SOUND_FIELD | API version 22 | Adjusts the spatial sense and range of sound. | - |
| [Source separation](#source-separation) | EFFECT_MULTII_OUTPUT_NODE_TYPE_AUDIO_SEPARATION | API version 22 | Separates vocals from accompaniment (multi-output). | This feature depends on the NPU. Before creating a node, call [OH_AudioSuiteEngine_IsNodeTypeSupported()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_isnodetypesupported) to check whether this node type is supported. |
| [Sound beautification](#sound-beautification) | EFFECT_NODE_TYPE_VOICE_BEAUTIFIER | API version 22 | Improves sound quality and listening experience. | - |
| [Environmental effect](#environmental-effect) | EFFECT_NODE_TYPE_ENVIRONMENT_EFFECT | API version 22 | Simulates the acoustic effects of different environments. | - |
| [Mixing](#mixing) | EFFECT_NODE_TYPE_AUDIO_MIXER | API version 22 | Mixes multiple audio streams into one. | - |
| [Spatial rendering](#spatial-rendering) | EFFECT_NODE_TYPE_SPACE_RENDER | API version 23 | Positions and renders 3D spatial audio. | - |
| [Traditional voice changer](#traditional-voice-changer) | EFFECT_NODE_TYPE_PURE_VOICE_CHANGE | API version 23 | Traditional voice changing based on gender and pitch. | - |
| [General voice changer](#general-voice-changer) | EFFECT_NODE_TYPE_GENERAL_VOICE_CHANGE | API version 23 | Various stylized voice changing effects. | - |
| [Speed and pitch shifting](#speed-and-pitch-shifting) | EFFECT_NODE_TYPE_TEMPO_PITCH | API version 23 | Changes the speed and pitch of audio. | - |
| [HOA spatial audio](#hoa-spatial-audio) | EFFECT_NODE_TYPE_HOA_SPACE_RENDER | API version 26.0.0 | Renders high-order Ambisonics (HOA) to binaural audio. | - |

## Equalizer

The equalizer effect node [EFFECT_NODE_TYPE_EQUALIZER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) changes the frequency characteristics of audio by adjusting the gain of different bands, delivering a variety of music style effects.

### Equalizer Bands

The equalizer effect node supports gain adjustment for 10 bands, and the gain of each band can be set independently. The gain value ranges from [-10, 10], in decibels (dB). You can use preset effects or customize the gain for each band.

The frequencies corresponding to the 10 bands are as follows:

| Band Index | Frequency<br>in hertz (Hz) | Gain Range<br>in decibels (dB) | Audio Characteristics |
|---------|------|---------|---------|
| 0 | 31 | [-10, 10] | Ultra-low frequency, affecting the deep bass effect. |
| 1 | 62 | [-10, 10] | Low frequency, affecting bass drums, bass, and so on. |
| 2 | 125 | [-10, 10] | Low-mid frequency, affecting male vocals, guitars, and so on. |
| 3 | 250 | [-10, 10] | Mid frequency, affecting vocals and the main body of instruments. |
| 4 | 500 | [-10, 10] | Upper-mid frequency, affecting vocal clarity. |
| 5 | 1000 | [-10, 10] | Upper-mid frequency, affecting vocal brightness. |
| 6 | 2000 | [-10, 10] | High frequency, affecting vocal details and instrument overtones. |
| 7 | 4000 | [-10, 10] | High frequency, affecting instrument brightness. |
| 8 | 8000 | [-10, 10] | High frequency, affecting instrument treble and percussion. |
| 9 | 16000 | [-10, 10] | Ultra-high frequency, affecting airiness and details. |

### Preset Effect Types

The equalizer node provides the following preset effects:

- [OH_EQUALIZER_PARAM_DEFAULT](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#variables): default effect, with the gain for each band being {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}.

- [OH_EQUALIZER_PARAM_BALLADS](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#variables): ballad effect, with the gain for each band being {3, 5, 2, -4, 1, 2, -3, 1, 4, 5}.

- [OH_EQUALIZER_PARAM_CHINESE_STYLE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#variables): Chinese style effect, with the gain for each band being {0, 0, 2, 0, 0, 4, 4, 2, 2, 5}.

- [OH_EQUALIZER_PARAM_CLASSICAL](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#variables): Classical effect, with the gain for each band being {2, 3, 2, 1, 0, 0, -5, -5, -5, -6}.

- [OH_EQUALIZER_PARAM_DANCE_MUSIC](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#variables): Dance music effect, with the gain for each band being {4, 3, 2, -3, 0, 0, 5, 4, 2, 0}.

- [OH_EQUALIZER_PARAM_JAZZ](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#variables): Jazz effect, with the gain for each band being {2, 0, 2, 3, 6, 5, -1, 3, 4, 4}.

- [OH_EQUALIZER_PARAM_POP](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#variables): Pop effect, with the gain for each band being {5, 2, 1, -1, -5, -5, -2, 1, 2, 4}.

- [OH_EQUALIZER_PARAM_RB](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#variables): R&B effect, with the gain for each band being {1, 4, 5, 3, -2, -2, 2, 3, 5, 5}.

- [OH_EQUALIZER_PARAM_ROCK](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#variables): Rock effect, with the gain for each band being {6, 4, 4, 2, 0, 1, 3, 3, 5, 4}.

### Setting Method for the Equalizer Effect Node

<!-- @[audioSuite_SetEqualizerType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// Set the node type to equalizer.
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_EQUALIZER);
// Create the equalizer node.
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// ...
// Set the equalizer node effect.
OH_AudioSuiteEngine_SetEqualizerFrequencyBandGains(*node, gains);
```

## Noise Reduction

The noise reduction effect node [EFFECT_NODE_TYPE_NOISE_REDUCTION](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) is used to reduce background noise in audio and improve the clarity and intelligibility of speech.

### Configuration Description

The noise reduction effect node requires no additional configuration parameters and takes effect once the node is created and connected to the pipeline. You can use [OH_AudioSuiteEngine_BypassEffectNode](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_bypasseffectnode) to control whether to bypass (pass through) the effect.

### Noise Reduction Effect Node Settings

<!-- @[audioSuite_SetNoiseReductionType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// Set the node type to noise reduction.
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_NOISE_REDUCTION);
// Create a noise reduction node.
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
```

## Sound Field

The sound field effect node [EFFECT_NODE_TYPE_SOUND_FIELD](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) creates different listening atmospheres by adjusting the spatial sense and sound field range of the audio.

### Sound Field Types

The sound field effect node supports the following four sound field effects, which are set through [OH_SoundFieldType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_soundfieldtype):

| Enumerated Value | Name | Description |
|--------|------|------|
| SOUND_FIELD_FRONT_FACING = 1 | Front-facing sound field | Concentrates the sound toward the front to create a forward-focused listening experience. |
| SOUND_FIELD_GRAND = 2 | Grand sound field | Widens the sound field range to create a grand and open sense of space. |
| SOUND_FIELD_NEAR = 3 | Near sound field | Shortens the listening distance to create an immersive, close-up listening experience. |
| SOUND_FIELD_WIDE = 4 | Wide sound field | Expands the left-right sound field width to enhance the horizontal envelopment. |

### Sound Field Effect Node Settings

<!-- @[audioSuite_SetSoundFieldType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// Set the node type to sound field.
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_SOUND_FIELD);
// Create the sound field node.
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// Set the sound field node effect.
OH_AudioSuiteEngine_SetSoundFieldType(*node, static_cast<OH_SoundFieldType>(params.soundFieldType));
```

## Source Separation

The source separation effect node [EFFECT_MULTII_OUTPUT_NODE_TYPE_AUDIO_SEPARATION](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) can separate mixed audio into two channels: vocals and accompaniment. It is a multi-output effect node, and no more than one such node is allowed in each pipeline.

### Configuration Description

- A source separation effect node can connect only to output nodes, not to other effect nodes.

- Because it is a multi-output node, obtain the processed data through [OH_AudioSuiteEngine_MultiRenderFrame](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_multirenderframe). The size of `audioDataArray` must correspond one-to-one with the number of outputs: one channel for vocals and one channel for accompaniment.

### Setting Method for the Source Separation Effect Node

Refer to [Source Separation](audio-suite-manual-rendering.md#source-separation) for configuration.

## Sound Beautification

The sound beautification effect node [EFFECT_NODE_TYPE_VOICE_BEAUTIFIER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) improves the audio quality and listening experience, delivering a better auditory experience to users.

### Beautification Types

The sound beautification effect node supports the following four beautification effect types, which are set through [OH_VoiceBeautifierType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_voicebeautifiertype):

| Enumerated Value | Name | Description |
|--------|------|------|
| VOICE_BEAUTIFIER_TYPE_CLEAR = 1 | Clear effect | Makes the voice clearer and brighter, suitable for scenarios that require highlighting details. |
| VOICE_BEAUTIFIER_TYPE_THEATRE = 2 | Theatre effect | Creates a theatre-like sense of space and reverberation, suitable for scenarios such as drama and performance. |
| VOICE_BEAUTIFIER_TYPE_CD = 3 | CD effect | Provides a professional CD-quality listening experience, suitable for high-quality music playback scenarios. |
| VOICE_BEAUTIFIER_TYPE_RECORDING_STUDIO = 4 | Recording studio effect | Creates the sound texture of a professional recording studio, suitable for recording and production scenarios. |

### Setting Method for the Beautification Effect Node

<!-- @[audioSuite_SetVoiceBeautifierType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// Set the node type to voice beautifier.
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_VOICE_BEAUTIFIER);
// Create the voice beautifier node.
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// Set the effect for the voice beautifier node.
OH_AudioSuiteEngine_SetVoiceBeautifierType(*node,
                                           static_cast<OH_VoiceBeautifierType>(params.voiceBeautifierType));
```

## Environmental Effect

The environmental effect node [EFFECT_NODE_TYPE_ENVIRONMENT_EFFECT](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) simulates the characteristics of different acoustic environments so that the audio presents the listening experience of the corresponding scene.

### Environment Type

The environmental effect node supports the following four environmental effects, which are set through [OH_EnvironmentType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_environmenttype):

| Enumerated Value | Name | Description |
|--------|------|------|
| ENVIRONMENT_TYPE_BROADCAST = 1 | Broadcast | Simulates the acoustic characteristics of a radio station. |
| ENVIRONMENT_TYPE_EARPIECE = 2 | Earpiece | Simulates the narrowband listening experience of a phone earpiece. |
| ENVIRONMENT_TYPE_UNDERWATER = 3 | Underwater | Simulates the muffled effect of sound propagating underwater. |
| ENVIRONMENT_TYPE_GRAMOPHONE = 4 | Gramophone | Simulates the vintage timbre of an old gramophone. |

### Setting the Environmental Effect Node

<!-- @[audioSuite_SetEnvironmentType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// Set the node type to environmental effect.
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_ENVIRONMENT_EFFECT);
// Create the environmental effect node.
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// Set the environmental effect node effect.
OH_AudioSuiteEngine_SetEnvironmentType(*node, static_cast<OH_EnvironmentType>(params.environmentType));
```

## Mixing

The audio mixer effect node [EFFECT_NODE_TYPE_AUDIO_MIXER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) is used to mix multiple input audio streams into a single output. The number of audio mixer nodes in each pipeline does not exceed 3.

### Mixing Effect Node Settings

Refer to [Mixing and Cascading](audio-suite-manual-rendering.md#mixing-and-cascading) for settings.

## Spatial Rendering

The spatial rendering effect node [EFFECT_NODE_TYPE_SPACE_RENDER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) is used to implement the positioning and rendering of 3D spatial audio. It adopts a left-handed coordinate system (the thumb points to the positive X-axis direction, the index finger points to the positive Y-axis direction, and the remaining fingers point to the positive Z-axis direction). For details, see [Spatial Rendering (C/C++)](audio-suite-space-render.md).

### Rendering Mode

The spatial rendering effect node supports three rendering modes, each corresponding to a group of configuration parameters:

**Fixed Positioning Mode**

Set this mode through [OH_AudioSuiteEngine_SetSpaceRenderPositionParams](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_setspacerenderpositionparams). The members of the parameter structure [OH_AudioSuite_SpaceRenderPositionParams](../../reference/apis-audio-kit/capi-ohaudiosuite-oh-audiosuite-spacerenderpositionparams.md) are defined as follows:

| Member | Type | Value Range | Unit | Description |
|------|------|---------|------|------|
| x | float | [-5.0, 5.0] | m | X coordinate in space. |
| y | float | [-5.0, 5.0] | m | Y coordinate in space. |
| z | float | [-5.0, 5.0] | m | Z coordinate in space. |

**Rotation Mode**

Set it through [OH_AudioSuiteEngine_SetSpaceRenderRotationParams](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_setspacerenderrotationparams). The members of the parameter structure [OH_AudioSuite_SpaceRenderRotationParams](../../reference/apis-audio-kit/capi-ohaudiosuite-oh-audiosuite-spacerenderrotationparams.md) are defined as follows:

| Member | Type | Value Range | Unit | Description |
|------|------|---------|------|------|
| x | float | [-5.0, 5.0] | meter (m) | X coordinate in space. |
| y | float | [-5.0, 5.0] | meter (m) | Y coordinate in space. |
| z | float | [-5.0, 5.0] | meter (m) | Z coordinate in space. |
| surroundTime | int32_t | [2, 40] | second (s) | Time for one full rotation. |
| surroundDirection | [OH_AudioSuite_SurroundDirection](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_surrounddirection) | [0, 1] | - | Rotation direction: 0 = counterclockwise (SPACE_RENDER_CCW), 1 = clockwise (SPACE_RENDER_CW). |

**Extension Mode**

Set it through [OH_AudioSuiteEngine_SetSpaceRenderExtensionParams](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_setspacerenderextensionparams). The members of the parameter structure [OH_AudioSuite_SpaceRenderExtensionParams](../../reference/apis-audio-kit/capi-ohaudiosuite-oh-audiosuite-spacerenderextensionparams.md) are defined as follows:

| Member | Type | Value Range | Unit | Description |
|------|------|---------|------|------|
| extRadius | float | [1.0, 5.0] | meter (m) | Extension radius. |
| extAngle | int32_t | (0, 360) | degree (°) | Extension angle. |

### Setting Method for the Spatial Rendering Effect Node

<!-- @[audioSuite_SetSpaceRenderParams](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// Set the node type to spatial rendering.
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_SPACE_RENDER);
// Create the spatial rendering node.
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// Set the spatial rendering parameters based on the scenario.
switch (params.spaceRenderMode) {
    // Fixed positioning mode.
    case SPACE_RENDER_MODE_POSITION: {
        OH_AudioSuite_SpaceRenderPositionParams position;
        position.x = params.spacePositionX;
        position.y = params.spacePositionY;
        position.z = params.spacePositionZ;
        OH_AudioSuiteEngine_SetSpaceRenderPositionParams(*node, position);
        break;
    }
    // Rotation mode.
    case SPACE_RENDER_MODE_ROTATION: {
        OH_AudioSuite_SpaceRenderRotationParams rotation;
        rotation.x = params.spaceRotationX;
        rotation.y = params.spaceRotationY;
        rotation.z = params.spaceRotationZ;
        rotation.surroundTime = params.spaceRotationSurroundTime;
        rotation.surroundDirection =
            static_cast<OH_AudioSuite_SurroundDirection>(params.spaceRotationSurroundDirection);
        OH_AudioSuiteEngine_SetSpaceRenderRotationParams(*node, rotation);
        break;
    }
    // Extension mode.
    case SPACE_RENDER_MODE_EXTENSION: {
        OH_AudioSuite_SpaceRenderExtensionParams extension;
        extension.extRadius = params.spaceExtensionRadius;
        extension.extAngle = params.spaceExtensionAngle;
        OH_AudioSuiteEngine_SetSpaceRenderExtensionParams(*node, extension);
        break;
    }
    default:
        break;
}
```

## Traditional Voice Changer

The traditional voice changer effect node [EFFECT_NODE_TYPE_PURE_VOICE_CHANGE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) implements the traditional voice changer effect by specifying the gender, voice changer type, and pitch.

### Configuration Description

The traditional voice changer effect node is configured through the [OH_AudioSuite_PureVoiceChangeOption](../../reference/apis-audio-kit/capi-ohaudiosuite-oh-audiosuite-purevoicechangeoption.md) structure, which contains the following members:

| Name | Type | Description |
|------|------|------|
| optionGender | [OH_AudioSuite_PureVoiceChangeGenderOption](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_purevoicechangegenderoption) | Voice changer gender: 1 = female (PURE_VOICE_CHANGE_FEMALE), 2 = male (PURE_VOICE_CHANGE_MALE). |
| optionType | [OH_AudioSuite_PureVoiceChangeType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_purevoicechangetype) | See the voice changer types below. |
| pitch | float | Pitch. To use the system-recommended pitch, set it to OH_PURE_VOICE_DEFAULT_PITCH (0.0f) in [macros](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#macros) for the best effect. The custom value range is [0.3f, 3.0f]. |

**Voice Changer Type**

| Enumerated Value | Name | Description |
|--------|------|------|
| PURE_VOICE_CHANGE_TYPE_CARTOON = 1 | Cartoon | Cartoon-style voice changer. |
| PURE_VOICE_CHANGE_TYPE_CUTE = 2 | Loli | Loli-style voice changer. |
| PURE_VOICE_CHANGE_TYPE_FEMALE = 3 | Female | Female voice changer. |
| PURE_VOICE_CHANGE_TYPE_MALE = 4 | Male | Male voice changer. |
| PURE_VOICE_CHANGE_TYPE_MONSTER = 5 | Monster | Monster-style voice changer. |
| PURE_VOICE_CHANGE_TYPE_ROBOTS = 6 | Robot | Robot-style voice changer. |
| PURE_VOICE_CHANGE_TYPE_SEASONED = 7 | Uncle | Uncle-style voice changer. |

### Setting the Traditional Voice Changer Effect Node

<!-- @[audioSuite_SetPureVoiceChangeOption](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// Set the node type to traditional voice changer.
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_PURE_VOICE_CHANGE);
// Create a traditional voice changer node.
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// Set the traditional voice changer node effect.
OH_AudioSuite_PureVoiceChangeOption option;
option.optionGender = static_cast<OH_AudioSuite_PureVoiceChangeGenderOption>(params.pureVoiceChangeGender);
option.optionType = static_cast<OH_AudioSuite_PureVoiceChangeType>(params.pureVoiceChangeType);
option.pitch = params.pureVoiceChangePitch;
OH_AudioSuiteEngine_SetPureVoiceChangeOption(*node, option);
```

## General Voice Changer

The general voice changer effect node [EFFECT_NODE_TYPE_GENERAL_VOICE_CHANGE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) provides a variety of stylized voice changer effects and is applicable to more scenarios.

### Voice Changer Type

The general voice changer effect node supports the following ten voice changer types, which are set through [OH_AudioSuite_GeneralVoiceChangeType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_generalvoicechangetype):

| Enumerated Value | Name | Description |
|--------|------|------|
| GENERAL_VOICE_CHANGE_TYPE_CUTE = 1 | Loli | Loli-style voice changer. |
| GENERAL_VOICE_CHANGE_TYPE_CYBERPUNK = 2 | Cyberpunk | Cyberpunk-style voice changer. |
| GENERAL_VOICE_CHANGE_TYPE_FEMALE = 3 | Female | Female voice changer. |
| GENERAL_VOICE_CHANGE_TYPE_MALE = 4 | Male | Male voice changer. |
| GENERAL_VOICE_CHANGE_TYPE_MIX = 5 | Reverb | Reverb-style voice changer. |
| GENERAL_VOICE_CHANGE_TYPE_MONSTER = 6 | Monster | Monster-style voice changer. |
| GENERAL_VOICE_CHANGE_TYPE_SEASONED = 7 | Uncle | Uncle-style voice changer. |
| GENERAL_VOICE_CHANGE_TYPE_SYNTH = 8 | Synth | Synth-style voice changer. |
| GENERAL_VOICE_CHANGE_TYPE_TRILL = 9 | Trill | Trill-style voice changer. |
| GENERAL_VOICE_CHANGE_TYPE_WAR = 10 | War | War-style voice changer. |

### Setting Method for the General Voice Changer Effect Node

<!-- @[audioSuite_SetGeneralVoiceChangeType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// Set the node type to general voice changer.
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_GENERAL_VOICE_CHANGE);
// Create a general voice changer node.
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// Set the general voice changer node effect.
OH_AudioSuiteEngine_SetGeneralVoiceChangeType(
    *node, static_cast<OH_AudioSuite_GeneralVoiceChangeType>(params.generalVoiceChangeType));
```

## Speed and Pitch Shifting

The speed and pitch shifting effect node [EFFECT_NODE_TYPE_TEMPO_PITCH](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) is used to change the playback speed and pitch of audio independently or simultaneously.

### Configuration Description

Set the parameters through [OH_AudioSuiteEngine_SetTempoAndPitch](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_settempoandpitch). The parameters are described as follows:

| Name | Type | Value Range | Description |
|------|------|---------|------|
| speed | float | [0.5, 10.0] | Speed parameter. 1.0 indicates the original speed. A value less than 1.0 slows down the audio, and a value greater than 1.0 speeds it up. |
| pitch | float | [0.1, 5.0] | Pitch parameter. 1.0 indicates the original pitch. A value less than 1.0 lowers the pitch, and a value greater than 1.0 raises it. |

### Setting Method for the Speed and Pitch Shifting Effect Node

<!-- @[audioSuite_SetTempoAndPitch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// Set the node type to speed and pitch shifting.
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_TEMPO_PITCH);
// Create the speed and pitch shifting node.
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// Set the speed and pitch shifting node effect.
OH_AudioSuiteEngine_SetTempoAndPitch(*node, params.tempoSpeed, params.tempoPitch);
```

## HOA Spatial Audio

The HOA (High-Order Ambisonics)-to-binaural spatial audio node [EFFECT_NODE_TYPE_HOA_SPACE_RENDER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) converts HOA-format spatial audio into binaural stereo output.

### Input Audio Format

The preceding node of this node must be an HOA-format input node. The input audio format requirements are as follows:

- Sample rate: [OH_Audio_SampleRate](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate).SAMPLE_RATE_16000 or SAMPLE_RATE_48000.

- Sample format: [OH_Audio_SampleFormat](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat).

- Channel layout: Supports first-order to third-order HOA. The values are as follows:

  - [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER1_ACN_N3D.

  - [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER1_ACN_SN3D.

  - [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER1_FUMA.

  - [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER2_ACN_N3D.

  - [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER2_ACN_SN3D.

  - [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER2_FUMA.

  - [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER3_ACN_N3D.

  - [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER3_ACN_SN3D.

  - [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER3_FUMA.

### Configuration Description

- The preceding node of this node must be connected to an input node whose audio format is HOA.

- If the node is not connected correctly, an error is reported when [OH_AudioSuiteEngine_StartPipeline](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_startpipeline) is called.

- This node requires no additional configuration parameters. It takes effect once it is created and connected correctly.