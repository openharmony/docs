# OH_AbilityRuntime_ModularObjectDispatcher_Array*

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=43d5e77d1f5350f21a34e2eda9d75b2c11601c5c translatedAt=2026-08-13T13:15:08.718Z pushedAt=2026-08-14T02:53:18.547Z -->

```c
typedef struct OH_AbilityRuntime_ModularObjectDispatcher_Array* OH_AbilityRuntime_ModObjDispatcher_ArrayHandle
```

## Overview

Array handle.

This handle points to a fixed-size ordered collection of elements of the same type. It supports setting and obtaining elements by index and querying the array size.

It can be created by [OH_AbilityRuntime_ModObjDispatcher_ArrayCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arraycreate) and must be released by [OH_AbilityRuntime_ModObjDispatcher_ArrayRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arrayrelease) after use.

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

**Header file:** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)