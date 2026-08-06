# embedded_component.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

声明EmbeddedComponent组件选项（ArkUI_EmbeddedComponentOption）相关的结构体和方法。开发者可通过这些方法创建、销毁组件选项对象，并为EmbeddedComponent组件设置运行异常回调（onError）和正常退出回调（onTerminated）。适用于需要在应用中嵌入EmbeddedUIExtensionAbility组件并管理其生命周期、监听运行异常与正常退出事件的应用场景，帮助开发者灵活处理组件运行过程中的状态变化。

**引用文件：** <arkui/node_attributes/embedded_component.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[embedded_component_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/UIExtensionAndAccessibility)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [AbilityBase_Want](capi-arkui-nativemodule-abilitybase-want.md) | AbilityBase_Want | 声明元能力Want结构。 |
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md) | ArkUI_EmbeddedComponentOption | 为EmbeddedComponent定义参数EmbeddedComponentOption。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_EmbeddedComponentOption* OH_ArkUI_EmbeddedComponentOption_Create()](#oh_arkui_embeddedcomponentoption_create) | - | 创建EmbeddedComponent组件选项的对象。 |
| [void OH_ArkUI_EmbeddedComponentOption_Dispose(ArkUI_EmbeddedComponentOption* option)](#oh_arkui_embeddedcomponentoption_dispose) | - | 销毁EmbeddedComponent组件选项的对象。 |
| [void OH_ArkUI_EmbeddedComponentOption_SetOnError(ArkUI_EmbeddedComponentOption* option, void (\*callback)(int32_t code, const char* name, const char* message))](#oh_arkui_embeddedcomponentoption_setonerror) | - | 设置EmbeddedComponent组件的onError回调。EmbeddedComponent组件在运行过程中发生异常时触发本回调。 |
| [void OH_ArkUI_EmbeddedComponentOption_SetOnTerminated(ArkUI_EmbeddedComponentOption* option, void (\*callback)(int32_t code, AbilityBase_Want* want))](#oh_arkui_embeddedcomponentoption_setonterminated) | - | 设置EmbeddedComponent组件的onTerminated回调。EmbeddedComponent组件正常退出时触发本回调。 |

## 函数说明

### OH_ArkUI_EmbeddedComponentOption_Create()

```c
ArkUI_EmbeddedComponentOption* OH_ArkUI_EmbeddedComponentOption_Create()
```

**描述：**


创建EmbeddedComponent组件选项的对象。返回的对象需要在不再使用时通过OH_ArkUI_EmbeddedComponentOption_Dispose销毁。

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* | 返回指向EmbeddedComponent组件选项的对象的指针。 |

### OH_ArkUI_EmbeddedComponentOption_Dispose()

```c
void OH_ArkUI_EmbeddedComponentOption_Dispose(ArkUI_EmbeddedComponentOption* option)
```

**描述：**


销毁EmbeddedComponent组件选项的对象。该对象必须由OH_ArkUI_EmbeddedComponentOption_Create创建，销毁后不应再使用该对象。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* option | 要销毁的EmbeddedComponent组件选项的对象的指针，不能为空，必须为OH_ArkUI_EmbeddedComponentOption_Create()创建的有效对象。 |

### OH_ArkUI_EmbeddedComponentOption_SetOnError()

```c
void OH_ArkUI_EmbeddedComponentOption_SetOnError(ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, const char* name, const char* message))
```

**描述：**


设置EmbeddedComponent组件的[onError](../apis-arkui/arkui-ts/ts-container-embedded-component.md#onerror)回调。EmbeddedComponent组件在运行过程中发生异常时触发本回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述                           |
| -- |------------------------------|
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* option | EmbeddedComponent组件选项的对象的指针。 |
| void (\*callback)(int32_t code, const char* name, const char* message) | 开发者自定义回调函数。不设置该回调时，EmbeddedComponent组件在运行过程中发生异常时不触发回调。<br>- code：组件运行发生异常时返回的错误码信息。错误码的详细介绍请参考[UIExtension错误码](errorcode-uiextension.md)。<br>- name：组件运行发生异常时返回的名称信息。<br>- message：组件运行发生异常时返回的详细信息。 |


### OH_ArkUI_EmbeddedComponentOption_SetOnTerminated()

```c
void OH_ArkUI_EmbeddedComponentOption_SetOnTerminated(ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, AbilityBase_Want* want))
```

**描述：**


设置EmbeddedComponent组件的[onTerminated](../apis-arkui/arkui-ts/ts-container-embedded-component.md#onterminated)回调。EmbeddedComponent组件正常退出时触发本回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述                           |
| -- |------------------------------|
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* option | EmbeddedComponent组件选项的对象的指针。 |
| void (\*callback)(int32_t code, [AbilityBase_Want](capi-arkui-nativemodule-abilitybase-want.md)* want) | 开发者自定义回调函数。不设置该回调时，EmbeddedComponent组件正常退出时不触发回调。<br>- code：被拉起的[EmbeddedUIExtensionAbility](../apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)退出时返回的结果码。若EmbeddedUIExtensionAbility通过调用[terminateSelfWithResult](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#terminateselfwithresult)退出，结果码为EmbeddedUIExtensionAbility设置的值。若EmbeddedUIExtensionAbility通过调用[terminateSelf](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#terminateself)退出，结果码为默认值"0"。<br>- want：被拉起的EmbeddedUIExtensionAbility退出时返回的数据。若EmbeddedUIExtensionAbility通过调用[terminateSelfWithResult](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#terminateselfwithresult)退出，返回的数据为EmbeddedUIExtensionAbility设置的数据。若EmbeddedUIExtensionAbility通过调用[terminateSelf](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#terminateself)退出，返回的数据为默认值。 |