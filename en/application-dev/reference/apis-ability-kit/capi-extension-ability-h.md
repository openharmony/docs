# extension_ability.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yangzhongkai-->
<!--Designer: @yangzhongkai-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=78b37dc80cedb621e1e10520010742ca19e07207 translatedAt=2026-08-13T13:24:03.797Z pushedAt=2026-08-14T03:25:47.418Z -->

## Overview

Declares the callback function type and entry function name of ExtensionAbility.

**File to include:** <AbilityKit/ability_runtime/extension_ability.h>

**Library:** libability_runtime.so

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Since**: 24

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [AbilityRuntime_ExtensionInstance](capi-abilityruntime-extensioninstance.md) | - | Defines the AbilityRuntime_ExtensionInstance struct type. |
| [AbilityRuntime_ExtensionInstance*](capi-abilityruntime-extensioninstance8h.md) | AbilityRuntime_ExtensionInstanceHandle | Defines a pointer to the AbilityRuntime_ExtensionInstance object. |

### Functions

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [typedef void AbilityRuntime_Extension_CreateFunc(AbilityRuntime_ExtensionInstanceHandle handle, const char *abilityName);](#abilityruntime_extension_createfunc) | AbilityRuntime_Extension_CreateFunc | Defines the callback function type that must be implemented in ExtensionAbility, used to instantiate the ExtensionAbility. |

### Variables

| Name | Type | Description |
|------| --- |------|
| [OH_AbilityRuntime_OnNativeExtensionCreate](#oh_abilityruntime_onnativeextensioncreate) | [AbilityRuntime_Extension_CreateFunc](#abilityruntime_extension_createfunc) | Declares the entry function name of the ExtensionAbility. Developers need to implement a function of the [AbilityRuntime_Extension_CreateFunc](#abilityruntime_extension_createfunc) type and name it OH_AbilityRuntime_OnNativeExtensionCreate. The system automatically finds and invokes this function to instantiate the ExtensionAbility.<br>**Since:** 24 |

## Function Description

### AbilityRuntime_Extension_CreateFunc()

```c
typedef void AbilityRuntime_Extension_CreateFunc(AbilityRuntime_ExtensionInstanceHandle handle, const char *abilityName)
```

**Description**

Defines the callback function type for creating an ExtensionAbility. This callback function type must be implemented in the ExtensionAbility to instantiate the ExtensionAbility.

**Since**: 24

**Parameters**

| Name | Description |
|--------|------|
| [AbilityRuntime_ExtensionInstanceHandle](capi-abilityruntime-extensioninstance8h.md) handle | AbilityRuntime_ExtensionInstanceHandle instance passed in by the callback function. |
| const char *abilityName | Name of the ExtensionAbility passed in by the callback function. |

## Variable Description

### OH_AbilityRuntime_OnNativeExtensionCreate

```c
AbilityRuntime_Extension_CreateFunc OH_AbilityRuntime_OnNativeExtensionCreate
```

**Description**

Declares the name of the ExtensionAbility entry function. Developers need to implement a function of the [AbilityRuntime_Extension_CreateFunc](#abilityruntime_extension_createfunc) type and name it OH_AbilityRuntime_OnNativeExtensionCreate. The system automatically finds and calls this function to initialize the ExtensionAbility instance.

**Since**: 24

**Example:**

```c
#include <AbilityKit/ability_runtime/extension_ability.h>

extern "C" void OH_AbilityRuntime_OnNativeExtensionCreate(AbilityRuntime_ExtensionInstance *instance,
                                                          const char *abilityName) {
    if (!instance) {
        // Record the error log and perform other service processing.
        return;
    }
    // Initialize the ExtensionAbility.
}
```