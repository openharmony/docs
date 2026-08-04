# ArkUI_AnimateCompleteCallback
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_AnimateCompleteCallback
```

## 概述

动画播放结束回调类型，用于在动画播放完成时通知开发者动画已结束。开发者可通过type字段指定回调触发方式，通过callback字段设置自定义回调函数，并通过userData字段传递自定义数据至回调函数中。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_animate.h](capi-native-animate-h.md)

## 汇总

### 成员变量

| 名称                                                                              | 描述 |
|---------------------------------------------------------------------------------| -- |
| [ArkUI_FinishCallbackType](capi-native-type-visual-h.md#arkui_finishcallbacktype) type | 在动画中定义结束回调的回调类型，用于指定回调的触发方式。取值原则：ARKUI_FINISH_CALLBACK_REMOVED(0)表示动画结束并立即删除时触发回调，ARKUI_FINISH_CALLBACK_LOGICALLY(1)表示动画逻辑上完成（可能仍处于长尾状态）时触发回调。不同回调类型的触发时机不同，请根据业务场景选择合适的类型。未显式设置type时，按ARKUI_FINISH_CALLBACK_REMOVED处理。 |
| void\* userData                                                                  | 用于动画播放结束回调，传递用户自定义数据。需确保userData在动画播放结束回调触发时仍有效，避免悬空指针导致未定义行为。设置该成员为NULL时，回调函数将不会接收到userData参数。 |


### 成员函数

| 名称 | 描述 |
| -- | -- |
| [void (\*callback)(void\* userData)](#callback) | 动画播放结束回调，可在动画播放完毕后执行自定义操作，例如启动衔接动画、更新UI元素状态或执行资源清理。 |

## 成员函数说明

### callback()

```c
void (*callback)(void* userData)
```

**描述：**

动画播放结束回调，与type和userData配合使用。type参数决定回调触发的时机类型，回调函数接收userData作为入参。设置该回调后，当动画播放结束时将自动调用该函数，开发者可在回调中通过userData参数执行自定义逻辑，如更新UI状态或处理动画完成后的后续操作。


