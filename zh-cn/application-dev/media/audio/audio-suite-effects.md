# 音频效果(C/C++)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

从API version 22开始，[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)提供多种音频效果节点，开发者可根据业务需求选择合适的效果节点对音频进行处理。

## 效果节点类型

| 效果类型 | 节点类型 | 起始API版本 | 用途 |
|---------|---------|--------|------|
| [均衡器](#均衡器) | EFFECT_NODE_TYPE_EQUALIZER | API版本22 | 频段调节，改变音频频率特性 |
| [降噪](#降噪) | EFFECT_NODE_TYPE_NOISE_REDUCTION | API版本22 | 降低背景噪声，提升语音清晰度 |
| [声场](#声场) | EFFECT_NODE_TYPE_SOUND_FIELD | API版本22 | 调整声音空间感和声场范围 |
| [音源分离](#音源分离) | EFFECT_MULTII_OUTPUT_NODE_TYPE_AUDIO_SEPARATION | API版本22 | 分离人声与伴奏（多路输出） |
| [声音美化](#声音美化) | EFFECT_NODE_TYPE_VOICE_BEAUTIFIER | API版本22 | 提升音质和听感 |
| [环境效果](#环境效果) | EFFECT_NODE_TYPE_ENVIRONMENT_EFFECT | API版本22 | 模拟不同环境的声学效果 |
| [混音](#混音) | EFFECT_NODE_TYPE_AUDIO_MIXER | API版本22 | 多路音频混合为一路 |
| [空间渲染](#空间渲染) | EFFECT_NODE_TYPE_SPACE_RENDER | API版本23 | 3D空间音频定位与渲染 |
| [传统变声](#传统变声) | EFFECT_NODE_TYPE_PURE_VOICE_CHANGE | API版本23 | 基于性别与音调的传统变声 |
| [通用变声](#通用变声) | EFFECT_NODE_TYPE_GENERAL_VOICE_CHANGE | API版本23 | 多种风格化变声效果 |
| [变速变调](#变速变调) | EFFECT_NODE_TYPE_TEMPO_PITCH | API版本23 | 改变音频速度与音调 |
| [HOA转双耳空间音频](#hoa转双耳空间音频) | EFFECT_NODE_TYPE_HOA_SPACE_RENDER | API版本26.0.0 | HOA高阶 Ambisonics 转双耳渲染 |

---

## 均衡器

均衡器效果节点[EFFECT_NODE_TYPE_EQUALIZER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)通过调整不同频段的增益来改变音频的频率特性，实现丰富的音乐风格效果。

### 均衡器频段

均衡器效果节点支持10个频段的增益调节，每个频段可以独立设置增益值。增益值范围为[-10, 10] dB（分贝）。开发者可以使用预设效果或自定义各频段增益。

10个频段对应的频率如下表所示：

| 频段序号 | 频率 | 增益范围 | 音频特性 |
|---------|------|---------|---------|
| 0 | 31Hz | [-10, 10] dB | 超低频，影响重低音效果 |
| 1 | 62Hz | [-10, 10] dB | 低频，影响低音鼓、贝斯等 |
| 2 | 125Hz | [-10, 10] dB | 低中频，影响男声、吉他等 |
| 3 | 250Hz | [-10, 10] dB | 中频，影响人声、乐器主体 |
| 4 | 500Hz | [-10, 10] dB | 中高频，影响人声清晰度 |
| 5 | 1kHz | [-10, 10] dB | 中高频，影响人声明亮度 |
| 6 | 2kHz | [-10, 10] dB | 高频，影响人声细节、乐器泛音 |
| 7 | 4kHz | [-10, 10] dB | 高频，影响乐器明亮度 |
| 8 | 8kHz | [-10, 10] dB | 高频，影响乐器高音、打击乐 |
| 9 | 16kHz | [-10, 10] dB | 超高频，影响空气感、细节 |

### 预置效果类型

均衡器节点内置以下预置效果：

- **[OH_EQUALIZER_PARAM_DEFAULT](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#变量)**：默认效果，各频段增益为{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
- **[OH_EQUALIZER_PARAM_BALLADS](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#变量)**：民谣效果，各频段增益为{3, 5, 2, -4, 1, 2, -3, 1, 4, 5}
- **[OH_EQUALIZER_PARAM_CHINESE_STYLE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#变量)**：中国风效果，各频段增益为{0, 0, 2, 0, 0, 4, 4, 2, 2, 5}
- **[OH_EQUALIZER_PARAM_CLASSICAL](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#变量)**：古典效果，各频段增益为{2, 3, 2, 1, 0, 0, -5, -5, -5, -6}
- **[OH_EQUALIZER_PARAM_DANCE_MUSIC](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#变量)**：舞曲效果，各频段增益为{4, 3, 2, -3, 0, 0, 5, 4, 2, 0}
- **[OH_EQUALIZER_PARAM_JAZZ](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#变量)**：爵士效果，各频段增益为{2, 0, 2, 3, 6, 5, -1, 3, 4, 4}
- **[OH_EQUALIZER_PARAM_POP](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#变量)**：流行效果，各频段增益为{5, 2, 1, -1, -5, -5, -2, 1, 2, 4}
- **[OH_EQUALIZER_PARAM_RB](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#变量)**：R&B效果，各频段增益为{1, 4, 5, 3, -2, -2, 2, 3, 5, 5}
- **[OH_EQUALIZER_PARAM_ROCK](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#变量)**：摇滚效果，各频段增益为{6, 4, 4, 2, 0, 1, 3, 3, 5, 4}

### 设置方法

可通过以下方式创建均衡器节点：

<!-- @[audioSuite_SetEqualizerType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// 设置为均衡器节点类型。
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_EQUALIZER);
// 创建均衡器节点。
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// ...
// 设置均衡器节点效果。
OH_AudioSuiteEngine_SetEqualizerFrequencyBandGains(*node, gains);
```
---

## 降噪

降噪效果节点[EFFECT_NODE_TYPE_NOISE_REDUCTION](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)用于降低音频中的背景噪声，提升语音的清晰度与可懂度，适合通话、录音、直播等场景。

### 配置说明

降噪效果节点无需额外配置参数，创建节点并接入管线后即生效。开发者可通过[OH_AudioSuiteEngine_BypassEffectNode](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_bypasseffectnode)控制是否旁路（透传）该效果。

### 设置方法

可通过以下方式创建降噪节点：

<!-- @[audioSuite_SetNoiseReductionType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

---

## 声场

声场效果节点[EFFECT_NODE_TYPE_SOUND_FIELD](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)通过调整声音的空间感与声场范围，营造不同的听感氛围。

### 声场类型

声场效果节点支持以下四种声场效果，通过[OH_SoundFieldType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_soundfieldtype)进行设置：

| 枚举值 | 名称 | 描述 |
|--------|------|------|
| SOUND_FIELD_FRONT_FACING = 1 | 前置声场 | 声音集中于前方，营造前向聚焦听感 |
| SOUND_FIELD_GRAND = 2 | 宏大声场 | 拓宽声场范围，营造宏大开阔的空间感 |
| SOUND_FIELD_NEAR = 3 | 聆听声场 | 缩短听感距离，营造贴近聆听的现场感 |
| SOUND_FIELD_WIDE = 4 | 宽广声场 | 扩展左右声场宽度，增强横向包围感 |

### 设置方法

可通过以下方式创建声场节点：

<!-- @[audioSuite_SetSoundFieldType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

---

## 音源分离

音源分离效果节点[EFFECT_MULTII_OUTPUT_NODE_TYPE_AUDIO_SEPARATION](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)可将混合音频分离为人声与伴奏两路，属于多输出效果节点，每个管线中数量不超过1个。

### 连接与取数说明

- 音源分离效果节点**只能连接输出节点**，不能连接其他效果节点。
- 由于是多输出节点，需通过[OH_AudioSuiteEngine_MultiRenderFrame](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_multirenderframe)获取处理后的数据；`audioDataArray`大小需与输出数量一一对应（人声1路、伴奏1路）。

### 设置方法

可通过以下方式创建音源分离节点：

<!-- @[audioSuite_SetAudioSeparationType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

---

## 声音美化

声音美化效果节点[EFFECT_NODE_TYPE_VOICE_BEAUTIFIER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)可以提升音频的音质和听感，为用户带来更加优质的听觉体验。

### 美化类型

声音美化效果节点支持以下四种美化效果类型，通过[OH_VoiceBeautifierType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_voicebeautifiertype)进行设置：

- **VOICE_BEAUTIFIER_TYPE_CLEAR**：清澈效果，使声音更加清晰明亮，适合需要突出细节的场景
- **VOICE_BEAUTIFIER_TYPE_THEATRE**：剧场效果，营造剧场般的空间感和回响效果，适合戏剧、演出等场景
- **VOICE_BEAUTIFIER_TYPE_CD**：CD效果，提供专业CD音质的听感，适合高品质音乐播放场景
- **VOICE_BEAUTIFIER_TYPE_RECORDING_STUDIO**：录音棚效果，营造专业录音棚的声音质感，适合录音制作场景

### 设置方法

可通过以下方式创建美化节点：

<!-- @[audioSuite_SetVoiceBeautifierType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

``` C
// 设置为声音美化节点类型。
OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_VOICE_BEAUTIFIER);
// 创建声音美化节点。
OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
// 设置声音美化节点效果。
OH_AudioSuiteEngine_SetVoiceBeautifierType(*node,
                                             static_cast<OH_VoiceBeautifierType>(params.voiceBeautifierType));
```

---

## 环境效果

环境效果节点[EFFECT_NODE_TYPE_ENVIRONMENT_EFFECT](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)通过模拟不同声学环境的特性，使音频呈现对应场景的听感。

### 环境类型

环境效果节点支持以下四种环境效果，通过[OH_EnvironmentType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_environmenttype)进行设置：

| 枚举值 | 名称 | 描述 |
|--------|------|------|
| ENVIRONMENT_TYPE_BROADCAST = 1 | 广播 | 模拟广播电台的声学特性 |
| ENVIRONMENT_TYPE_EARPIECE = 2 | 电话听筒 | 模拟电话听筒的窄带听感 |
| ENVIRONMENT_TYPE_UNDERWATER = 3 | 水下 | 模拟水下传播的闷响效果 |
| ENVIRONMENT_TYPE_GRAMOPHONE = 4 | 留声机 | 模拟老式留声机的复古音色 |

### 设置方法

可通过以下方式创建环境效果节点：

<!-- @[audioSuite_SetEnvironmentType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

---

## 混音

混音效果节点[EFFECT_NODE_TYPE_AUDIO_MIXER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)用于将多路输入音频混合为一路输出，每个管线中混音节点的数量不超过3个。

### 连接说明

混音节点支持在管线运行状态下动态接入。当管线处于运行状态时：

- 目标节点（destAudioNode）必须为混音（mix）类型节点；
- 且源节点（sourceAudioNode）必须已连接输入类型节点，否则连接将失败。

### 设置方法

可通过以下方式创建混音节点：

<!-- @[audioSuite_SetAudioMixerType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

---

## 空间渲染

空间渲染效果节点[EFFECT_NODE_TYPE_SPACE_RENDER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)用于实现3D空间音频的定位与渲染，采用左手坐标系（拇指指向x轴正方向、食指指向y轴正方向、其余手指指向z轴正方向）。

### 渲染模式

空间渲染效果节点支持三种渲染模式，分别对应三组配置参数：

#### 固定摆位模式

通过[OH_AudioSuiteEngine_SetSpaceRenderPositionParams](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_setspacerenderpositionparams)设置，参数结构体[OH_AudioSuite_SpaceRenderPositionParams](../../reference/apis-audio-kit/capi-ohaudiosuite-oh-audiosuite-spacerenderpositionparams.md)：

| 成员 | 类型 | 取值范围 | 单位 | 说明 |
|------|------|---------|------|------|
| x | float | [-5.0, 5.0] | 米 | 空间中的X坐标 |
| y | float | [-5.0, 5.0] | 米 | 空间中的Y坐标 |
| z | float | [-5.0, 5.0] | 米 | 空间中的Z坐标 |

#### 旋转模式

通过[OH_AudioSuiteEngine_SetSpaceRenderRotationParams](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_setspacerenderrotationparams)设置，参数结构体[OH_AudioSuite_SpaceRenderRotationParams](../../reference/apis-audio-kit/capi-ohaudiosuite-oh-audiosuite-spacerenderrotationparams.md)：

| 成员 | 类型 | 取值范围 | 单位 | 说明 |
|------|------|---------|------|------|
| x | float | [-5.0, 5.0] | 米 | 空间中的X坐标 |
| y | float | [-5.0, 5.0] | 米 | 空间中的Y坐标 |
| z | float | [-5.0, 5.0] | 米 | 空间中的Z坐标 |
| surroundTime | int32_t | [2, 40] | 秒 | 单周环绕时间 |
| surroundDirection | [OH_AudioSuite_SurroundDirection](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_surrounddirection) | [0, 1] | - | 环绕方向：0=逆时针(SPACE_RENDER_CCW)，1=顺时针(SPACE_RENDER_CW) |

#### 扩展模式

通过[OH_AudioSuiteEngine_SetSpaceRenderExtensionParams](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_setspacerenderextensionparams)设置，参数结构体[OH_AudioSuite_SpaceRenderExtensionParams](../../reference/apis-audio-kit/capi-ohaudiosuite-oh-audiosuite-spacerenderextensionparams.md)：

| 成员 | 类型 | 取值范围 | 单位 | 说明 |
|------|------|---------|------|------|
| extRadius | float | [1.0, 5.0] | 米 | 扩展半径 |
| extAngle | int32_t | (0, 360) | 度 | 扩展角度 |

### 设置方法

可通过以下方式创建空间渲染节点（以固定摆位模式为例）：

<!-- @[audioSuite_SetSpaceRenderParams](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

---

## 传统变声

传统变声效果节点[EFFECT_NODE_TYPE_PURE_VOICE_CHANGE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)通过指定性别、变声类型与音调实现传统变声效果。

### 配置参数

传统变声效果节点通过结构体[OH_AudioSuite_PureVoiceChangeOption](../../reference/apis-audio-kit/capi-ohaudiosuite-oh-audiosuite-purevoicechangeoption.md)配置，包含以下成员：

| 成员 | 类型 | 说明 |
|------|------|------|
| optionGender | [OH_AudioSuite_PureVoiceChangeGenderOption](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_purevoicechangegenderoption) | 变声性别：1=女声(PURE_VOICE_CHANGE_FEMALE)，2=男声(PURE_VOICE_CHANGE_MALE) |
| optionType | [OH_AudioSuite_PureVoiceChangeType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_purevoicechangetype) | 变声类型，见下表 |
| pitch | float | 音调。使用系统推荐音调设为宏[OH_PURE_VOICE_DEFAULT_PITCH](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#宏定义)（0.0f）以获得最佳效果；自定义取值范围为[0.3f, 3.0f] |

#### 变声类型

| 枚举值 | 名称 | 描述 |
|--------|------|------|
| PURE_VOICE_CHANGE_TYPE_CARTOON = 1 | 卡通 | 卡通风格变声 |
| PURE_VOICE_CHANGE_TYPE_CUTE = 2 | 萝莉 | 萝莉风格变声 |
| PURE_VOICE_CHANGE_TYPE_FEMALE = 3 | 女声 | 女声变声 |
| PURE_VOICE_CHANGE_TYPE_MALE = 4 | 男声 | 男声变声 |
| PURE_VOICE_CHANGE_TYPE_MONSTER = 5 | 怪兽 | 怪兽风格变声 |
| PURE_VOICE_CHANGE_TYPE_ROBOTS = 6 | 机器人 | 机器人风格变声 |
| PURE_VOICE_CHANGE_TYPE_SEASONED = 7 | 大叔 | 大叔风格变声 |

### 设置方法

可通过以下方式创建传统变声节点：

<!-- @[audioSuite_SetPureVoiceChangeOption](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

---

## 通用变声

通用变声效果节点[EFFECT_NODE_TYPE_GENERAL_VOICE_CHANGE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)提供多种风格化的变声效果，适用场景更丰富。

### 变声类型

通用变声效果节点支持以下十种变声类型，通过[OH_AudioSuite_GeneralVoiceChangeType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_generalvoicechangetype)进行设置：

| 枚举值 | 名称 | 描述 |
|--------|------|------|
| GENERAL_VOICE_CHANGE_TYPE_CUTE = 1 | 萝莉 | 萝莉风格变声 |
| GENERAL_VOICE_CHANGE_TYPE_CYBERPUNK = 2 | 赛博朋克 | 赛博朋克风格变声 |
| GENERAL_VOICE_CHANGE_TYPE_FEMALE = 3 | 女声 | 女声变声 |
| GENERAL_VOICE_CHANGE_TYPE_MALE = 4 | 男声 | 男声变声 |
| GENERAL_VOICE_CHANGE_TYPE_MIX = 5 | 混响 | 混响风格变声 |
| GENERAL_VOICE_CHANGE_TYPE_MONSTER = 6 | 怪兽 | 怪兽风格变声 |
| GENERAL_VOICE_CHANGE_TYPE_SEASONED = 7 | 大叔 | 大叔风格变声 |
| GENERAL_VOICE_CHANGE_TYPE_SYNTH = 8 | 合成器 | 合成器风格变声 |
| GENERAL_VOICE_CHANGE_TYPE_TRILL = 9 | 颤音 | 颤音风格变声 |
| GENERAL_VOICE_CHANGE_TYPE_WAR = 10 | 战争 | 战争风格变声 |

### 设置方法

可通过以下方式创建通用变声节点：

<!-- @[audioSuite_SetGeneralVoiceChangeType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

---

## 变速变调

变速变调效果节点[EFFECT_NODE_TYPE_TEMPO_PITCH](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)用于独立或同时改变音频的播放速度与音调。

### 配置参数

通过[OH_AudioSuiteEngine_SetTempoAndPitch](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_settempoandpitch)设置，参数说明如下：

| 参数 | 类型 | 取值范围 | 说明 |
|------|------|---------|------|
| speed | float | [0.5, 10.0] | 变速参数，1.0为原始速度；小于1.0减速，大于1.0加速 |
| pitch | float | [0.1, 5.0] | 变调参数，1.0为原始音调；小于1.0降调，大于1.0升调 |

### 设置方法

可通过以下方式创建变速变调节点：

<!-- @[audioSuite_SetTempoAndPitch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

---

## HOA转双耳空间音频

HOA（High-Order Ambisonics）转双耳空间音频节点[EFFECT_NODE_TYPE_HOA_SPACE_RENDER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)用于将HOA格式的空间音频转换为双耳（Binaural）立体声输出，实现耳机场景下的沉浸式3D听感。

### 输入音频格式

该节点的前置节点必须为HOA格式的输入节点，输入音频格式要求如下：

- 采样率：[OH_Audio_SampleRate](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate).SAMPLE_RATE_16000 或 SAMPLE_RATE_48000
- 采样格式：[OH_Audio_SampleFormat](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat)
- 声道布局：支持1阶至3阶HOA，取值如下：
  - [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER1_ACN_N3D
  - [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER1_ACN_SN3D
  - [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER1_FUMA
  - [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER2_ACN_N3D
  - [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER2_ACN_SN3D
  - [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER2_FUMA
  - [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER3_ACN_N3D
  - [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER3_ACN_SN3D
  - [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_AMB_ORDER3_FUMA

### 连接说明

- 该节点的前置节点**必须连接音频格式为HOA的输入节点**。
- 若未正确连接，在调用[OH_AudioSuiteEngine_StartPipeline](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_startpipeline)接口时将会报错。
- 该节点无需额外配置参数，创建并正确连接后即生效。