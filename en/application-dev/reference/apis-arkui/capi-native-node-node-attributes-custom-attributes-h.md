# custom_attributes.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=c8d89821f92b220ca7659a1de29fb1e3b0412c5b translatedAt=2026-08-11T09:09:02.189Z pushedAt=2026-08-12T04:19:47.723Z -->

## Overview

Provides event type definitions for measurement, layout, and drawing of custom components for **NativeNode** API, used to register and handle measurement, layout, and drawing events of the content layer, foreground layer, and overlay layer.

**File to include:** <arkui/node_attributes/custom_attributes.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[native_node_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/native_node_sample)<!--RP1End-->

## Summary

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_NodeCustomEventType](#arkui_nodecustomeventtype) | ArkUI_NodeCustomEventType | Enumerates custom component event types. |

## Enum Description

### ArkUI_NodeCustomEventType

```c
enum ArkUI_NodeCustomEventType
```

**Description**

Enumerates custom component event types.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE = 1 << 0 | Custom measurement. <br>**Since:** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT = 1 << 1 | Custom layout. <br>**Since:** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_DRAW = 1 << 2 | Custom content layer drawing. <br>**Since:** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW = 1 << 3 | Custom foreground drawing. <br>**Since:** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW = 1 << 4 | Custom overlay drawing. <br>**Since:** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_DRAW_FRONT = 1 << 5 | Custom content layer foreground drawing. <br>**Since:** 20 |
| ARKUI_NODE_CUSTOM_EVENT_ON_DRAW_BEHIND = 1 << 6 | Custom content layer background drawing. <br>**Since:** 20 |