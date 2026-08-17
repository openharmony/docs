# OH_AbilityRuntime_ModObjDispatcher_InputParams

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=43d5e77d1f5350f21a34e2eda9d75b2c11601c5c translatedAt=2026-08-13T13:14:40.033Z pushedAt=2026-08-14T01:32:59.912Z -->

```c
typedef struct {...} OH_AbilityRuntime_ModObjDispatcher_InputParams
```

## Overview

Defines the parameter structure for method invocation. rgvarg points to the parameter variant array, and the array length is specified by cArgs. The parameter order must be consistent with that in the method definition.

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

**Header File:** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_Variant*](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md) rgvarg | Parameter variant array.<br>**Since:** 26.0.0 |
| uint32_t cArgs | Number of parameters.<br>**Since:** 26.0.0 |