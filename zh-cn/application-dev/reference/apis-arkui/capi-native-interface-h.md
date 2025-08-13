# native_interface.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--SE: @xiang-shouxing-->
<!--TSE: @sally__-->

## 概述

提供NativeModule接口的统一入口函数。

**引用文件：** <arkui/native_interface.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) | ArkUI_NativeAPIVariantKind | 定义Native接口集合类型。 |

### 函数

| 名称  | 描述   |
|--------------|-----------|
| [void* OH_ArkUI_QueryModuleInterfaceByName(ArkUI_NativeAPIVariantKind type, const char* structName)](#oh_arkui_querymoduleinterfacebyname)        | 需调用该函数初始化C-API环境，并获取指定类型的Native模块接口集合。 |

### 宏定义

| 名称  | 描述   |
|--------------|-----------|
| [OH_ArkUI_GetModuleInterface(nativeAPIVariantKind, structType, structPtr)](#oh_arkui_getmoduleinterface)      | 基于结构体类型获取对应结构体指针的宏函数。 |

## 枚举类型说明

### ArkUI_NativeAPIVariantKind

```
enum ArkUI_NativeAPIVariantKind
```

**描述：**


定义Native接口集合类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_NATIVE_NODE | UI组件相关接口类型，详见<arkui/native_node.h>中的结构体类型定义。 |
| ARKUI_NATIVE_DIALOG | 弹窗相关接口类型，详见<arkui/native_dialog.h>中的结构体类型定义。 |
| ARKUI_NATIVE_GESTURE | 手势相关接口类型，详见<arkui/native_gesture.h>中的结构体类型定义。 |
| ARKUI_NATIVE_ANIMATE | 动画相关接口类型。详见<arkui/native_animate.h>中的结构体类型定义。 |
| ARKUI_MULTI_THREAD_NATIVE_NODE | 多线程UI组件相关接口类型，详见<arkui/native_node.h>中的结构体类型定义。 |


## 函数说明

### OH_ArkUI_QueryModuleInterfaceByName()

```
void* OH_ArkUI_QueryModuleInterfaceByName(ArkUI_NativeAPIVariantKind type, const char* structName)
```

**描述：**


需调用该函数初始化C-API环境，并获取指定类型的Native模块接口集合。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NativeAPIVariantKind](capi-native-interface-h.md#arkui_nativeapivariantkind) type | ArkUI提供的Native接口集合大类，例如UI组件接口类：ARKUI_NATIVE_NODE, 手势类：ARKUI_NATIVE_GESTURE。 |
| const char* structName | native接口结构体的名称，通过查询对应头文件内结构体定义，例如位于<arkui/native_node.h>中的"ArkUI_NativeNodeAPI_1"。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | void 返回Native接口抽象指针，在转化为具体类型后进行使用。 |

### OH_ArkUI_GetModuleInterface()

```
OH_ArkUI_GetModuleInterface(nativeAPIVariantKind, structType, structPtr)                             \
do {                                                                                                 \
        void* anyNativeAPI = OH_ArkUI_QueryModuleInterfaceByName(nativeAPIVariantKind, #structType); \
        if (anyNativeAPI) {                                                                          \
            structPtr = (structType*)(anyNativeAPI);                                                 \
        }                                                                                            \
    } while (0)                                                                      
```

**描述：**


基于结构体类型获取对应结构体指针的宏函数。

**起始版本：** 12


