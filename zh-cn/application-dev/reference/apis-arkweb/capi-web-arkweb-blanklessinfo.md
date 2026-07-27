# ArkWeb_BlanklessInfo
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @Shenxiaoliang1-->
<!--Designer: @kurli1-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct {...} ArkWeb_BlanklessInfo
```

## 概述

页面首屏加载预测信息，主要包括首屏相似度预测值、首屏加载耗时预测值、错误码，应用需根据此信息来决策是否启用无白屏加载插帧方案（该方案通过在页面加载过程中插入预渲染帧来减少白屏时间）。

**起始版本：** 20

**相关模块：** [Web](capi-web.md)

**所在头文件：** [native_interface_arkweb.h](capi-native-interface-arkweb-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| ArkWeb_BlanklessErrorCode errCode | 无白屏加载的错误码，取值为0表示无错误，非0值表示错误类型，见[ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode)定义。 |
| double similarity | 首屏相似度，根据历史加载首屏内容计算相似度，范围为[0, 1.0]，1.0表示完全一致，数值越接近1，相似度越高。该值存在滞后性，本地加载的相似度将在下次加载时才可反映。建议当相似度低于具体阈值（如0.33）时，应用不启用无白屏加载插帧方案。 |
| int32_t loadingTime | 根据历史加载首屏耗时预测本次加载耗时，单位：ms，取值范围需大于0。 |

