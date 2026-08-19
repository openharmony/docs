# OH_AbilityRuntime_ModularObjectDispatcher_Map*

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=43d5e77d1f5350f21a34e2eda9d75b2c11601c5c translatedAt=2026-08-13T13:15:24.403Z pushedAt=2026-08-14T02:54:44.231Z -->

```c
typedef struct OH_AbilityRuntime_ModularObjectDispatcher_Map* OH_AbilityRuntime_ModObjDispatcher_MapHandle
```

## Overview

Map handle.

The handle points to an ordered collection of key-value pairs. The key and value types are specified at creation. It supports adding or updating key-value pairs, obtaining values by key, deleting key-value pairs, querying whether a specified key exists, obtaining keys or values by index, querying the map size, and clearing operations.

Keys support only basic types (BOOL, signed integer, unsigned integer, floating-point number, STRING, ENUM).

It can be created through [OH_AbilityRuntime_ModObjDispatcher_MapCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapcreate), and must be released through [OH_AbilityRuntime_ModObjDispatcher_MapRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_maprelease) after use.

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

**File to include:** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)