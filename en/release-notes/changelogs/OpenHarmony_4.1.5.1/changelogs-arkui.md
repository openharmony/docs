# ArkUI Subsystem Changelog

## cl.arkui.1 Change in Event Response Capability

**Access Level**

Open API

**Reason for Change**

The response of the mouse wheel and the touchpad to the swipe and pan gestures is improved, and the conflict between swipe events in different directions is resolved.

**Change Impact**

This change is a compatible change and does not involve API changes. However, due to changes in the response logic, response to the swipe and scroll events may be affected.

**Change Since**

OpenHarmony SDK 4.1.5.1

**Key API/Component Changes**

APIs: **PanGesture** and **SwipeGesture**

Components: **\<List>**, **\<Grid>**, **\<Scroll>**, and any other components that can be scrolled by using the mouse wheel

**Adaptation Guide**

Before change:

No matter how many swipe events occur in the area where the mouse pointer is located, the mouse wheel and the touchpad's two-finger functionality can respond only to the first swipe event bound to the first child node. If this swipe event is in the horizontal direction, it can be triggered with the mouse wheel or by swiping with two fingers horizontally or vertically on the touchpad. If this swipe event is in the vertical direction, it can be triggered with the mouse wheel or by swiping with two fingers vertically on the touchpad.

Example 1: A horizontal swipe event is bound to or built in a component. When the mouse pointer is located in the component area, scrolling the mouse wheel or swiping with two fingers horizontally or vertically on the touchpad can both trigger the event.

Example 2: A vertical swipe event is bound to or built in a component. When the mouse pointer is located in the component area, scrolling the mouse wheel or swiping with two fingers vertically on the touchpad can both trigger the event.

Example 3: A vertical swipe event is bound to or built in the parent component, and a horizontal swipe event is bound to or built in the child component. When the mouse pointer is in the area of the child component (also in the area of the parent component), operations with the mouse wheel and the touchpad trigger the event on the child component, but not on the parent component.

After change:

When there is only a horizontal swipe event in the area in which the mouse pointer is located, the first swipe event on the first child node may be triggered by with the mouse wheel, Shift+mouse wheel, or two fingers swiping horizontally on the touchpad.

When there is only a vertical swipe event in the area in which the mouse pointer is located, the first swipe event on the first child node may be triggered by with the mouse wheel or two fingers swiping vertically on the touchpad.

When there is a horizontal swipe event and a vertical swipe event in the area in which the mouse pointer is located, the first vertical swipe event on the first child node may be triggered with the mouse wheel or two fingers swiping vertically on the touchpad, while first horizontal swipe event may be triggered with Shift+mouse wheel or two fingers swiping horizontally on the touchpad.

In all the preceding scenarios, the two-finger operation on the touchpad does not the Shift button. This means that, pressing the Shift button does not affect event response.

Example 1: Scrolling the mouse wheel, scrolling the mouse wheel while pressing Shift, or swiping horizontally with two fingers on the touchpad can trigger the event.

Example 2: Scrolling the mouse wheel or swiping vertically with two fingers on the touchpad can trigger the event.

Example 3: Scrolling the mouse wheel or swiping vertically with two fingers on the touchpad can trigger the event on the parent component. Scrolling the mouse wheel while pressing Shift or swiping horizontally with two fingers on the touchpad can trigger the event on the child component.
## cl.arkui.2 Change in showActionMenu of UIContext

**Access Level**

Open API

**Reason for Change**

The **callback** parameter type of the **showActionMenu** API of UIContext was incorrectly defined. As a result, the callback function was unavailable.

**Change Impact**

This change is a non-compatible change and involves API changes. The original API with the incorrectly defined **callback** parameter is no longer available.

**Change Since**

OpenHarmony SDK 4.1.5.1

**Key API/Component Changes**

**showActionMenu** API of **UIContext**

**Adaptation Guide**

Before change:

The data type of the **callback** parameter is **promptAction.ActionMenuSuccessResponse**, which is a data object. If **promptAction.ActionMenuSuccessResponse** is passed in according to the API definition, the API does not work.

```ts
import { PromptAction, UIInspector } from '@ohos.arkui.UIContext';
import promptAction from '@ohos.promptAction';
import { BusinessError } from '@ohos.base';

let promptActionF: PromptAction = uiContext.getPromptAction();
try {
    promptActionF.showActionMenu({
      title: 'Title Info',
      buttons: [
        {
          text: 'item1',
          color: '#666666'
        },
        {
          text: 'item2',
          color: '#000000'
        }
      ]
    },  (data:promptAction.ActionMenuSuccessResponse))
} catch (error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);
};
```

After change:

The data type of the **callback** parameter is AsyncCallback&lt;[promptAction.ActionMenuSuccessResponse](../../../application-dev/reference/apis/js-apis-promptAction.md#actionmenusuccessresponse)&gt, which indicates a callback method. If AsyncCallback&lt;[promptAction.ActionMenuSuccessResponse](../../../application-dev/reference/apis/js-apis-promptAction.md#actionmenusuccessresponse)&gt; is passed in, the API works properly.

```ts
import { PromptAction, UIInspector } from '@ohos.arkui.UIContext';
import promptAction from '@ohos.promptAction';
import { BusinessError } from '@ohos.base';

let promptActionF: PromptAction = uiContext.getPromptAction();
try {
    promptActionF.showActionMenu({
      title: 'Title Info',
      buttons: [
        {
          text: 'item1',
          color: '#666666'
        },
        {
          text: 'item2',
          color: '#000000'
        }
      ]
    }, (err:BusinessError, data:promptAction.ActionMenuSuccessResponse) => {
        if (err) {
        console.info('showDialog err: ' + err);
        return;
        }
        console.info('showDialog success callback, click button: ' + data.index);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    let code = (error as BusinessError).code;
    console.error(`showActionMenu args error code is ${code}, message is ${message}`);
};
```
## cl.arkui.3 Change in Calculating the Size of the \<RelativeContainer> Component

**Access Level**

Open API

**Reason for Change**

If both the component size and size constraints are set, the component size set is preferentially used. Since API version 11, the **bias** attribute is added to set the offset of the component under constraints.

**Change Impact**

Before change, if both the component size and size constraints are set, the size constraints are preferentially used to determine the component size.<br>After change, the component size set is preferentially used.

**Change Since**

OpenHarmony SDK 4.1.5.1 (API version 11 and later)

**Key API/Component Changes**

\<RelativeContainer>
