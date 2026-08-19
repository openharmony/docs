# OH_AbilityRuntime_ModularObjectDispatcher*

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=43d5e77d1f5350f21a34e2eda9d75b2c11601c5c translatedAt=2026-08-13T13:15:46.891Z pushedAt=2026-08-14T03:06:58.873Z -->

```c
typedef struct OH_AbilityRuntime_ModularObjectDispatcher* OH_AbilityRuntime_ModObjDispatcherHandle
```

## Overview

Handle to a ModularObject dispatcher.

This handle points to a ModularObject dispatcher instance. It can be created by [OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createmainserviceinstance) or [OH_AbilityRuntime_ModObjDispatcher_CreateSubInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createsubinstance), and must be released by [OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release) after use.

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

**File to include:** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)