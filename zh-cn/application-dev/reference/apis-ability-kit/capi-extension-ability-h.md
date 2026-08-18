# extension_ability.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yangzhongkai-->
<!--Designer: @yangzhongkai-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

## 概述

提供ExtensionAbility回调函数类型声明和入口函数名称声明。

**引用文件：** <AbilityKit/ability_runtime/extension_ability.h>

**库：** libability_runtime.so

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 24

**相关模块：** [AbilityRuntime](capi-abilityruntime.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [AbilityRuntime_ExtensionInstance](capi-abilityruntime-extensioninstance.md) | - | 定义AbilityRuntime_ExtensionInstance结构体类型。 |
| [AbilityRuntime_ExtensionInstance*](capi-abilityruntime-extensioninstance8h.md) | AbilityRuntime_ExtensionInstanceHandle | 定义AbilityRuntime_ExtensionInstance对象指针。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void AbilityRuntime_Extension_CreateFunc(AbilityRuntime_ExtensionInstanceHandle handle, const char *abilityName);](#abilityruntime_extension_createfunc) | AbilityRuntime_Extension_CreateFunc | ExtensionAbility中必须实现的回调函数类型，用于实例化ExtensionAbility。|

### 变量

| 名称 | 类型 | 描述 |
|------| --- |------|
| [OH_AbilityRuntime_OnNativeExtensionCreate](#oh_abilityruntime_onnativeextensioncreate) | [AbilityRuntime_Extension_CreateFunc](#abilityruntime_extension_createfunc) | ExtensionAbility入口函数名称声明。开发者需要实现一个类型为[AbilityRuntime_Extension_CreateFunc](#abilityruntime_extension_createfunc)的函数，并将其命名为OH_AbilityRuntime_OnNativeExtensionCreate。系统会自动查找并调用此函数来完成ExtensionAbility实例的初始化。<br>**起始版本：** 24 |

## 函数说明

### AbilityRuntime_Extension_CreateFunc()

```c
typedef void AbilityRuntime_Extension_CreateFunc(AbilityRuntime_ExtensionInstanceHandle handle, const char *abilityName)
```

**描述**

ExtensionAbility创建回调函数类型。ExtensionAbility中必须实现的回调函数类型，用于实例化ExtensionAbility。

**起始版本：** 24

**参数：**

| 参数名 | 描述 |
|--------|------|
| [AbilityRuntime_ExtensionInstanceHandle](capi-abilityruntime-extensioninstance8h.md) handle | 回调函数传入AbilityRuntime_ExtensionInstanceHandle实例。 |
| const char *abilityName | 回调函数传入的ExtensionAbility的名称。 |

## 变量说明

### OH_AbilityRuntime_OnNativeExtensionCreate

```c
AbilityRuntime_Extension_CreateFunc OH_AbilityRuntime_OnNativeExtensionCreate
```

**描述**

ExtensionAbility入口函数名称声明。开发者需要实现一个类型为[AbilityRuntime_Extension_CreateFunc](#abilityruntime_extension_createfunc)的函数，并将其命名为OH_AbilityRuntime_OnNativeExtensionCreate。系统会自动查找并调用此函数来完成ExtensionAbility实例的初始化。

**起始版本：** 24

**示例代码：**

```c
#include <AbilityKit/ability_runtime/extension_ability.h>

extern "C" void OH_AbilityRuntime_OnNativeExtensionCreate(AbilityRuntime_ExtensionInstance *instance,
                                                          const char *abilityName) {
    if (!instance) {
        // 记录错误日志以及其他业务处理
        return;
    }
    // ExtensionAbility 初始化工作
}
```