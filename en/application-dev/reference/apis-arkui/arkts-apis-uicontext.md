# Module Description

In the stage model, a window stage or window can use the [loadContent](arkts-apis-window-Window.md#loadcontent9) API to load pages, create a UI instance, and render page content to the associated window. Naturally, UI instances and windows are associated on a one-by-one basis. Some global UI APIs are executed in the context of certain UI instances. When calling these APIs, you must identify the UI context, and consequently UI instance, by tracing the call chain. If these APIs are called on a non-UI page or in some asynchronous callback, the current UI context may fail to be identified, resulting in API execution errors.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Modules to Import

```ts
import {
  AtomicServiceBar, ComponentUtils, ContextMenuController, CursorController, DragController, Font, KeyboardAvoidMode, MediaQuery, OverlayManager,
  PromptAction, Router, UIContext, UIInspector, UIObserver, PageInfo, SwiperDynamicSyncScene, SwiperDynamicSyncSceneType, MeasureUtils, FrameCallback,
  OverlayManagerOptions, TargetInfo, MarqueeDynamicSyncScene, MarqueeDynamicSyncSceneType
} from "@kit.ArkUI";
```
