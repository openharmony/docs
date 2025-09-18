# @ohos.accessibility (Accessibility) (System API)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

The **Accessibility** module provides accessibility event types and operations executable on accessibility nodes.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about other public APIs, see [@ohos.accessibility](js-apis-accessibility.md).

## Modules to Import

```ts
import { accessibility } from '@kit.AccessibilityKit';
```


## AccessibilityEventType

Enumerates accessibility event types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core


| Name                    | Value                   |Description|
| ---------------------------------------- | ---- | ---------------------- |
| TYPE_ACCESSIBILITY_FOCUS                 | 0    | Event of gaining accessibility focus.            |
| TYPE_ACCESSIBILITY_FOCUS_CLEAR           | 1    | Event of clearing accessibility focus.            |
| TYPE_CLICK                               | 2    | Event of clicking a component.               |
| TYPE_LONG_CLICK                          | 3    | Event of long pressing a component.             |
| TYPE_SELECT                              | 4    | Event of selecting a component.               |
| TYPE_HOVER_ENTER                         | 5    | Event indicating the mouse pointer enters a component.             |
| TYPE_HOVER_EXIT                          | 6    | Event indicating the mouse pointer exits a component.             |
| TYPE_FOCUS                               | 7    | Event of the component gaining focus.             |
| TYPE_TEXT_UPDATE                         | 8    | Event indicating that the component text has been updated.            |
| TYPE_TEXT_SELECTION_UPDATE               | 9    | Event indicating that the selected text has been updated. |
| TYPE_SCROLL                              | 10   | Event of scrolling the view.               |
| TYPE_REQUEST_FOCUS_FOR_ACCESSIBILITY     | 11   | Event of auto-focusing.               |
| TYPE_ANNOUNCE_FOR_ACCESSIBILITY          | 12   | Event of auto-broadcasting.               |
| TYPE_REQUEST_FOCUS_FOR_ACCESSIBILITY_NOT_INTERRUPT | 13   | Event of auto-focusing without interruption.            |
| TYPE_ANNOUNCE_FOR_ACCESSIBILITY_NOT_INTERRUPT | 14   | Event of auto-broadcasting without interruption.            |
| TYPE_ELEMENT_INFO_CHANGE                 | 15   | Event indicating that the component information changes.             |
| TYPE_SCROLLING                           | 16   | Event indicating that an item is scrolled out of the screen.    |
| TYPE_WINDOW_ADD                          | 17   | Event of adding windows.               |
| TYPE_WINDOW_REMOVE                       | 18   | Event of deleting windows.               |
| TYPE_WINDOW_BOUNDS                       | 19   | Event indicating that the window boundary changes.             |
| TYPE_WINDOW_ACTIVE                       | 20   | Event indicating that the window activity state changes.            |
| TYPE_WINDOW_FOCUS                        | 21   | Event indicating that the window focus changes.           |
| TYPE_WINDOW_PROPERTY                     | 22   | Event indicating that the window properties change, such as transparency, size, and so on.|
| TYPE_WINDOW_LAYER                        | 23   | Event indicating that the window layer changes.             |
| TYPE_TOUCH_BEGIN                         | 24   | Event indicating that a touch begins.           |
| TYPE_TOUCH_END                           | 25   | Event indicating that a touch ends.           |
| TYPE_PAGE_CONTENT_UPDATE  |26| Event indicating that the page content is updated.|
| TYPE_PAGE_STATE_UPDATE  |27| Event indicating that the page state is updated.|
| TYPE_PAGE_OPEN  |28| Event of opening a page.|
| TYPE_PAGE_CLOSE  |29| Event of closing a page.|
| TYPE_SWIPE_LEFT           |30| Event indicating the swipe-left gesture.   |
| TYPE_SWIPE_LEFT_THEN_RIGHT  |31| 	Event indicating the swipe-left-then-right gesture.|
| TYPE_SWIPE_LEFT_THEN_UP     |32| Event indicating the swipe-left-then-up gesture.|
| TYPE_SWIPE_LEFT_THEN_DOWN   |33| Event indicating the swipe-left-then-down gesture.|
| TYPE_SWIPE_RIGHT          |34| Event indicating the swipe-right gesture.   |
| TYPE_SWIPE_RIGHT_THEN_LEFT  |35| Event indicating the swipe-right-then-left gesture.|
| TYPE_SWIPE_RIGHT_THEN_UP    |36| Event indicating the swipe-right-then-up gesture.|
| TYPE_SWIPE_RIGHT_THEN_DOWN  |37| Event indicating the swipe-right-then-down gesture.|
| TYPE_SWIPE_UP             |38| Event indicating the swipe-up gesture.  |
| TYPE_SWIPE_UP_THEN_LEFT     |39| Event indicating the swipe-up-then-left gesture.|
| TYPE_SWIPE_UP_THEN_RIGHT    |40| Event indicating the swipe-up-then-right gesture.|
| TYPE_SWIPE_UP_THEN_DOWN     |41| Event indicating the swipe-up-then-down gesture.|
| TYPE_SWIPE_DOWN           |42| Event indicating the swipe-down gesture.   |
| TYPE_SWIPE_DOWN_THEN_LEFT   |43| Event indicating the swipe-down-then-left gesture.|
| TYPE_SWIPE_DOWN_THEN_RIGHT  |44| Event indicating the swipe-down-then-right gesture.|
| TYPE_SWIPE_DOWN_THEN_UP     |45| Event indicating the swipe-down-then-up gesture.|
| TYPE_TWO_FINGER_SINGLE_TAP   |46| Event indicating the two-finger single-tap gesture.|
| TYPE_TWO_FINGER_DOUBLE_TAP   |47| 	Event indicating the two-finger double-tap gesture.|
| TYPE_TWO_FINGER_DOUBLE_TAP_AND_HOLD      | 48   | Event indicating the two-finger double-tap-and-hold gesture.         |
| TYPE_TWO_FINGER_TRIPLE_TAP   |49| Event indicating the two-finger triple-tap gesture.|
| TYPE_TWO_FINGER_TRIPLE_TAP_AND_HOLD      | 50   | Event indicating the two-finger triple-tap-and-hold gesture.         |
| TYPE_THREE_FINGER_SINGLE_TAP  |51| Event indicating the three-finger single-tap gesture.|
| TYPE_THREE_FINGER_DOUBLE_TAP  |52| Event indicating the three-finger double-tap gesture.|
| TYPE_THREE_FINGER_DOUBLE_TAP_AND_HOLD    | 53   | Event indicating the three-finger double-tap-and-hold gesture.         |
| TYPE_THREE_FINGER_TRIPLE_TAP  |54| Event indicating the three-finger triple-tap gesture.|
| TYPE_THREE_FINGER_TRIPLE_TAP_AND_HOLD    | 55   | Event indicating the three-finger triple-tap-and-hold gesture.         |
| TYPE_FOUR_FINGER_SINGLE_TAP  |56| Event indicating the four-finger single-tap gesture.|
| TYPE_FOUR_FINGER_DOUBLE_TAP  |57| Event indicating the four-finger double-tap gesture.|
| TYPE_FOUR_FINGER_DOUBLE_TAP_AND_HOLD     | 58   | Event indicating the four-finger double-tap-and-hold gesture.         |
| TYPE_FOUR_FINGER_TRIPLE_TAP  |59| Event indicating the four-finger triple-tap gesture.|
| TYPE_FOUR_FINGER_TRIPLE_TAP_AND_HOLD     | 60   | Event indicating the four-finger triple-tap-and-hold gesture.         |
| TYPE_THREE_FINGER_SWIPE_UP   |61| Event indicating the three-finger swipe-up gesture.|
| TYPE_THREE_FINGER_SWIPE_DOWN  |62| Event indicating the three-finger swipe-down gesture.|
| TYPE_THREE_FINGER_SWIPE_LEFT  |63| 	Event indicating the three-finger swipe-left gesture.|
| TYPE_THREE_FINGER_SWIPE_RIGHT  |64| Event indicating the three-finger swipe-right gesture.|
| TYPE_FOUR_FINGER_SWIPE_UP    |65| Event indicating the four-finger swipe-up gesture.|
| TYPE_FOUR_FINGER_SWIPE_DOWN  |66| Event indicating the four-finger swipe-down gesture.|
| TYPE_FOUR_FINGER_SWIPE_LEFT  |67| Event indicating the four-finger swipe-left gesture.|
| TYPE_FOUR_FINGER_SWIPE_RIGHT  |68| Event indicating the four-finger swipe-right gesture.|

## AccessibilityAction

Actions that can be executed on accessibility nodes, which are UI components, such as buttons, text boxes, and so on.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                        | Value   | Description                      |
| -------------------------- | ---- | ------------------------ |
| ACCESSIBILITY_FOCUS        | 0    | Gaining the accessibility focus.              |
| CLEAR_ACCESSIBILLITY_FOCUS | 1    | Clearing the accessibility focus.              |
| FOCUS                      | 2    | Gaining the focus for a component.               |
| CLEAR_FOCUS                | 3    | Clearing the focus for a component.               |
| CLICK                      | 4    | Clicking a component.                 |
| LONG_CLICK                 | 5    | Long pressing a component.               |
| CUT                        | 6    | Cutting the content of a component.               |
| COPY                       | 7    | Copying the content of a component.                |
| PASTE                      | 8    | Pasting content to a component.               |
| SELECT                     | 9    | Selecting a component.                  |
| SET_TEXT                   | 10   | Setting the text of a component.              |
| SCROLL_FORWARD             | 11   | Scrolling a component forward.                |
| SCROLL_BACKWARD            | 12   | Scrolling a component backward.               |
| SET_SELECTION              | 13   | Selecting a text range in a component.            |
| SET_CURSOR_POSITION        | 14   | Setting the cursor position in a component.            |
| HOME                       | 15   | Returning to the home screen.             |
| BACK                       | 16   | Returning to the previous screen.              |
| RECENT_TASK                | 17   | Opening a recent task.                 |
| NOTIFICATION_CENTER        | 18   | Opening the notification center.                 |
| CONTROL_CENTER             | 19   | Opening the control center.                 |
| SPAN_CLICK                 | 20   | Clicking a part of a text.            |
