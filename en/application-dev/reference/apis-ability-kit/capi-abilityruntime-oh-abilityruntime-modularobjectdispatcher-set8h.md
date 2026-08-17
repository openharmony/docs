# OH_AbilityRuntime_ModularObjectDispatcher_Set*

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=43d5e77d1f5350f21a34e2eda9d75b2c11601c5c translatedAt=2026-08-13T13:15:36.021Z pushedAt=2026-08-14T02:56:04.068Z -->

```c
typedef struct OH_AbilityRuntime_ModularObjectDispatcher_Set* OH_AbilityRuntime_ModObjDispatcher_SetHandle
```

## Overview

Set handle.

This handle points to an unordered set of unique elements of the same type. It supports adding elements, removing elements, querying whether a specified element exists, obtaining an element by index, querying the set size, and clearing the set.

You can create it through [OH_AbilityRuntime_ModObjDispatcher_SetCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setcreate), and release it through [OH_AbilityRuntime_ModObjDispatcher_SetRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setrelease) when it is no longer needed.

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

**File to include:** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)