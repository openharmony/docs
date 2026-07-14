# 音频效果(C/C++)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

从API version 22开始，[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)提供多种音频效果节点，开发者可根据业务需求选择合适的效果节点对音频进行处理。

## 使用场景

音频效果节点可应用于以下场景：

- **离线编辑**：适用于非实时预览场景，对音频数据进行离线处理。详见[音频离线编辑](audio-suite-manual-rendering.md)。
- **实时预览**：适用于播放时实时处理场景，边播放边应用效果。详见[音频实时预览](audio-suite-real-time-rendering.md)。

## 效果节点类型

| 效果类型 | 节点类型 | API版本 | 用途 |
|---------|---------|--------|------|
| 均衡器 | EFFECT_NODE_TYPE_EQUALIZER | API版本22 | 频段调节，改变音频频率特性 |
| 声音美化 | EFFECT_NODE_TYPE_VOICE_BEAUTIFIER | API版本22 | 提升音质和听感 |

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

创建均衡器节点后，可通过以下方式设置效果：

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

## 声音美化

声音美化效果节点[EFFECT_NODE_TYPE_VOICE_BEAUTIFIER](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type)可以提升音频的音质和听感，为用户带来更加优质的听觉体验。

### 美化类型

声音美化效果节点支持以下四种美化效果类型，通过[OH_VoiceBeautifierType](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_voicebeautifiertype)进行设置：

- **VOICE_BEAUTIFIER_TYPE_CLEAR**：清澈效果，使声音更加清晰明亮，适合需要突出细节的场景
- **VOICE_BEAUTIFIER_TYPE_THEATRE**：剧场效果，营造剧场般的空间感和回响效果，适合戏剧、演出等场景
- **VOICE_BEAUTIFIER_TYPE_CD**：CD效果，提供专业CD音质的听感，适合高品质音乐播放场景
- **VOICE_BEAUTIFIER_TYPE_RECORDING_STUDIO**：录音棚效果，营造专业录音棚的声音质感，适合录音制作场景

### 设置方法

创建声音美化节点后，可通过以下方式设置效果：

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