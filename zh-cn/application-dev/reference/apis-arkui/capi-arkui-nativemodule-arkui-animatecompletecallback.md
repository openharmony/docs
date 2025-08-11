# ArkUI_AnimateCompleteCallback
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--SE: @yangfan229-->
<!--TSE: @lxl007-->

## 概述

动画播放完成回调类型。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_animate.h](capi-native-animate-h.md)

## 汇总

### 成员变量

| 名称                                                                              | 描述 |
|---------------------------------------------------------------------------------| -- |
| [ArkUI_FinishCallbackType](capi-native-type-h.md#arkui_finishcallbacktype) type | 在动画中定义onFinish回调的类型。 |
| void* userData                                                                  | 自定义类型。 |


### 成员函数

| 名称 | 描述 |
| -- | -- |
| [void (\*callback)(void* userData)](#callback) | 动画播放完成回调。 |

## 成员函数说明

### callback()

```
void (*callback)(void* userData)
```

**描述：**


动画播放完成回调。


