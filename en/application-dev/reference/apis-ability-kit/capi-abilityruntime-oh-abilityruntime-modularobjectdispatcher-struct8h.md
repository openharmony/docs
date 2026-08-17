# OH_AbilityRuntime_ModularObjectDispatcher_Struct*

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=43d5e77d1f5350f21a34e2eda9d75b2c11601c5c translatedAt=2026-08-13T13:15:35.853Z pushedAt=2026-08-14T02:56:23.143Z -->

```c
typedef struct OH_AbilityRuntime_ModularObjectDispatcher_Struct* OH_AbilityRuntime_ModObjDispatcher_StructHandle
```

## Overview

Struct handle.

The handle points to a struct instance with named fields, and the field types are defined by the type library metadata.

It can be created by [OH_AbilityRuntime_ModObjDispatcher_StructCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_structcreate) and must be released by [OH_AbilityRuntime_ModObjDispatcher_StructRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_structrelease) after use.

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

**File to include:** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)