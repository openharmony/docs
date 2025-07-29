# Using the UI Context API for UI Operations (UIContext)

## Overview

With the support of the stage model in OpenHarmony, there is a scenario where multiple ArkUI instances run within a single ArkTS engine. In this case, an ArkTS engine may have multiple abilities, each of which may have multiple windows. Each window loads a page through **loadContent**, generating an ArkUI instance.

**Figure 1** Multi-instance relationship 
![multi-instance](figures/multi-instance.png)

## Ambiguous UI Context

Ambiguous UI context refers to the issue where the calling point cannot clearly identify the target UI instance when invoking ArkUI global APIs. ArkUI global APIs were designed for the FA model, which inherently supports only a single ArkUI instance and does not account for multiple instances. When the framework switches to the stage model, these global APIs, originally exposed in the FA model, cannot determine the specific instance being used. The APIs can only identify a valid UI instance based on the call chain. If the UI instance cannot be traced, this results in ambiguous UI context. Since the implementation of these APIs relies on information from the ArkUI instance, ambiguous UI context can lead to unexpected runtime behavior.

To address this issue, ArkUI has introduced alternative APIs for the stage model to meet needs in multi-ArkUI instance scenarios. You can obtain a [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md) object to call the corresponding multi-instance alternative APIs, thereby resolving the UI context ambiguity in multi-instance scenarios. The UIContext is the context of an ArkUI instance, an object created by a window to manage all UIs, which is held and managed by the creating window.

## Substitute APIs

The table below lists some of the alternative APIs to replace in multi-instance scenarios. The full range of APIs supported is described in [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md).

|               Global API               |               Substitute API               |            Description           |
| :-----------------------------------: | :-----------------------------------: | :------------------------: |
|            @ohos.animator             |            createAnimator             |      Custom animation controller.     |
|     @ohos.arkui.componentSnapshot     |         getComponentSnapshot          |          Component snapshot.         |
|      @ohos.arkui.componentUtils       |           getComponentUtils           |         Component utility class.        |
|      @ohos.arkui.dragController       |           getDragController           |         Drag controller.        |
|         @ohos.arkui.inspector         |            getUIInspector             |        Component layout callback.       |
|         @ohos.arkui.observer          |             getUIObserver             |          Observer.         |
|              @ohos.font               |                getFont                |         Custom font registration.        |
|             @ohos.measure             |            getMeasureUtil             |          Text measurement.         |
|           @ohos.mediaquery            |             getMediaQuery             |          Media query.         |
|          @ohos.promptAction           |            getPromptAction            |            Popup.           |
|             @ohos.router              |               getRouter               |          Page routing.         |
|              AlertDialog              |            showAlertDialog            |          Alert dialog box.         |
|              ActionSheet              |            showActionSheet            |        Action sheet.       |
|         CalendarPickerDialog          |                Not supported                |       Calendar picker dialog box.      |
|           DatePickerDialog            |         showDatePickerDialog          |      Date picker dialog box.     |
|           TimePickerDialog            |         showTimePickerDialog          |     Time picker dialog box.    |
|           TextPickerDialog            |         showTextPickerDialog          |     Text picker dialog box.    |
|              ContextMenu              |       getContextMenuController        |          Menu control.         |
| vp2px/px2vp/fp2px/px2fp/lpx2px/px2lpx | vp2px/px2vp/fp2px/px2fp/lpx2px/px2lpx |        Pixel unit conversion.       |
|             focusControl              |            getFocusControl            |          Focus control.         |
|             cursorControl             |           getCursorControl            |          Cursor control.         |
|              getContext               |            getHostContext             | Obtains the context of the current ability.|
|        LocalStorage.getShared         |         getSharedLocalStorage         |  Obtains the storage passed by the current ability. |
|               animateTo               |               animateTo               |          Explicit animation.         |
|         animateToImmediately          |                Not supported                |        Explicit instant animation.       |

## How to Switch to Substitute APIs

In the following example, a toast is displayed in a specific window. ArkUI can detect that the API is called on the current page and find the corresponding UI instance. In some complex scenarios, however, the API is not initially called on the current page and has been asynchronously called. In this case, the behavior of the instance may become ambiguous.

<!--deprecated_code_no_check-->
```ts
import { promptAction } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  build() {
    Row() {
      Button()
        .onClick(() => {
          promptAction.showToast({            
            message: 'Message Info',
            duration: 2000 
          });
        })
    }
  }
}
```
In the following example, **callNative** is a Node-API method. If it is asynchronously triggered by the C side, the current page information cannot be detected at execution, and the UI instance that responds cannot be determined.

<!--deprecated_code_no_check-->
```ts
import { promptAction } from '@kit.ArkUI'
// xxx.so is not system provided. You must provide it.
import bridge from xxx.so

@Entry
@Component
struct Index {
  build() {
    Row() {
      Button()
        .onClick(() => {
          bridge.callNative("xxxx", ()=> {
            promptAction.showToast({            
              message: 'Message Info',
              duration: 2000 
            });
          })
        })
    }
  }
}
```

To address the above issue, you can use the component built-in API [getUIContext](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#getuicontext) to directly obtain the **UIContext** instance where the current component is located, and then use the **getPromptAction** API in [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md) to obtain objects bound to the instance. This way, the toast is bound to a specific instance.
```ts
// xxx.so is not system provided. You must provide it.
import bridge from xxx.so

@Entry
@Component
struct Index {
  build() {
    Row() {
      Button()
        .onClick(() => {
          let uiContext = this.getUIContext();
          let prompt = uiContext.getPromptAction();
          bridge.callNative("xxxx", ()=> {
            prompt.showToast({            
              message: 'Message Info',
              duration: 2000 
            });
          })
        })
    }
  }
}
```

If you are using APIs in [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md) that do not have substitutes (such as **CalendarPickerDialog** and **animateToImmediately**), or if you are implementing custom service logic that's tied to specific instances, you can use the **runScopedTask** API in **UIContext** to encapsulate these APIs or code snippets.

| API in UIContext| Description                |
| ------------- | -------------------- |
| runScopedTask | Executes the closure of the bound instance.|

The above example can also be implemented using the following method.

<!--deprecated_code_no_check-->
```ts
// Execute the closure of the bound instance.
import { promptAction } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  build() {
    Row() {
      Button()
        .onClick(() => {
          let uiContext = this.getUIContext();
          uiContext.runScopedTask(() => {
            promptAction.showToast({            
              message: 'Message Info',
              duration: 2000 
            });
          })
        })
    }
  }
}
```
