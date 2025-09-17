# @ohos.application.AccessibilityExtensionAbility (AccessibilityExtensionAbility)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

The **AccessibilityExtensionAbility** module provides accessibility extension capabilities based on the ExtensionAbility framework.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
```

## AccessibilityExtensionAbility

### Properties

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name     | Type                                                                                         | Read-Only  | Optional  | Description          |
| ------- |---------------------------------------------------------------------------------------------| ---- | ---- | ------------ |
| context | [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md) | No   | No   | Context of the accessibility extension ability.|

## AccessibilityEvent

Defines an accessibility event.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Properties

| Name     | Type             | Read-Only            | Optional                     | Description                      |
| --------- |----------------------------------------------------------------|------------------------------------------------------------------------------|------------------------------------| ------------------------------------------------------------ |
| eventType | [accessibility.EventType](js-apis-accessibility.md#eventtype) \| [accessibility.WindowUpdateType](js-apis-accessibility.md#windowupdatetype) \| [TouchGuideType](#touchguidetype) \| [GestureType](#gesturetype) \| [PageUpdateType](#pageupdatetype) | No  | No  | Event type.<br>**EventType**: accessibility event type.<br>**WindowUpdateType**: window update type.<br>**TouchGuideType**: touch guide type.<br>**GestureType**: gesture type.<br>**PageUpdateType**: page update type.|
| target    | [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9) | No | Yes   | Target component where the event occurs. |
| timeStamp | number              | No       | Yes        | Timestamp of the event, in milliseconds. The default value is **0**.                         |
| elementId<sup>12+</sup> | number            | No            | Yes            | Component ID for auto-focusing. The default value is **0**.                |
| textAnnouncedForAccessibility<sup>12+</sup> | string    | No          | Yes    | Content for auto-broadcasting. Set the broadcast content based on the actual scenario. No special restrictions.                 |
| extraInfo<sup>20+</sup> | string    | No          | Yes    | Added or deleted text content carried by the **TextArea**, **TextInput**, **SearchField**, or **RichEdit** component. Set this parameter based on site requirements. No special restrictions.                |


## AccessibilityElement<sup>10+</sup>

type AccessibilityElement = _AccessibilityElement

Accessibility element. For details, see [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                    |
| ----------------------- |------------------------|
| _AccessibilityElement  | Indicates an accessibility element. For details, see [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9).|

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';

let accessibilityElement: AccessibilityElement;
```

## ElementAttributeValues<sup>10+</sup>

type ElementAttributeValues = _ElementAttributeValues

Provides attribute names and value types of a node element. For details, see [ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                    |
| ----------------------- |------------------------|
| _ElementAttributeValues | Provides attribute names and value types of a node element. For details, see [ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues).|

**Example**

```ts
import { ElementAttributeValues } from '@kit.AccessibilityKit';

let elementAttributeValues: ElementAttributeValues;
```

## FocusDirection<sup>10+</sup>

type FocusDirection = _FocusDirection

Enumerates the focus directions. For details, see [FocusDirection](js-apis-inner-application-accessibilityExtensionContext.md#focusdirection).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                    |
| ----------------------- |------------------------|
| _FocusDirection | Enumerates the focus directions. For details, see [FocusDirection](js-apis-inner-application-accessibilityExtensionContext.md#focusdirection).|

**Example**

```ts
import { FocusDirection } from '@kit.AccessibilityKit';

let focusDirection: FocusDirection;
```

## ElementAttributeKeys<sup>10+</sup>

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name     | Type                                                                                                                  | Read-Only  | Optional  | Description                                                |
| ------- |----------------------------------------------------------------------------------------------------------------------| ---- | ---- |----------------------------------------------------|
| ElementAttributeKeys | keyof [ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues) | No   | No   | Key of **ElementAttributeValues**.|


**Example**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';

let elementAttributeKeys: ElementAttributeKeys;
```

## FocusType<sup>10+</sup>

type FocusType = _FocusType

Enumerates the focus types. For details, see [FocusType](js-apis-inner-application-accessibilityExtensionContext.md#focustype).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                    |
| ----------------------- |------------------------|
| _FocusType | Enumerates the focus types. For details, see [FocusType](js-apis-inner-application-accessibilityExtensionContext.md#focustype).|

**Example**

```ts
import { FocusType } from '@kit.AccessibilityKit';

let focusType: FocusType;
```

## WindowType <sup>10+</sup>

type WindowType = _WindowType

Enumerates the window types. For details, see [WindowType](js-apis-inner-application-accessibilityExtensionContext.md#windowtype).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                    |
| ----------------------- |------------------------|
| _WindowType | Enumerates the window types. For details, see [WindowType](js-apis-inner-application-accessibilityExtensionContext.md#windowtype).|

**Example**

```ts
import { WindowType } from '@kit.AccessibilityKit';

let windowType: WindowType;
```

## Rect<sup>10+</sup>

type Rect = _Rect

Defines a rectangle. For details, see [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                    |
| ----------------------- |------------------------|
| _Rect | Defines a rectangle. For details, see [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect).|

**Example**

```ts
import { Rect } from '@kit.AccessibilityKit';

let rect: Rect;
```

## AccessibilityExtensionContext<sup>10+</sup>

type AccessibilityExtensionContext = _AccessibilityExtensionContext.default

Defines the context of the accessibility extension. For details, see [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                    |
| ----------------------- |------------------------|
| _AccessibilityExtensionContext.default | Context of the accessibility extension. For details, see [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md).|

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let axContext = this.context; 
  } 
}
```

## GestureType

type GestureType = 'left' | 'leftThenRight' | 'leftThenUp' | 'leftThenDown' | 'right' | 'rightThenLeft' | 'rightThenUp' | 'rightThenDown' | 'up' | 'upThenLeft' | 'upThenRight' | 'upThenDown' | 'down' | 'downThenLeft' | 'downThenRight' | 'downThenUp' | 'twoFingerSingleTap' | 'twoFingerDoubleTap' | 'twoFingerDoubleTapAndHold' | 'twoFingerTripleTap' | 'twoFingerTripleTapAndHold' | 'threeFingerSingleTap' | 'threeFingerDoubleTap' | 'threeFingerDoubleTapAndHold' | 'threeFingerTripleTap' | 'threeFingerTripleTapAndHold' | 'fourFingerSingleTap' | 'fourFingerDoubleTap' | 'fourFingerDoubleTapAndHold' | 'fourFingerTripleTap' | 'fourFingerTripleTapAndHold' | 'threeFingerSwipeUp' | 'threeFingerSwipeDown' | 'threeFingerSwipeLeft' | 'threeFingerSwipeRight' | 'fourFingerSwipeUp' | 'fourFingerSwipeDown' | 'fourFingerSwipeLeft' | 'fourFingerSwipeRight'

Enumerates gesture types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name           | Type           | Description                 |
| ------------- | ------------- | ------------------- |
| left          | string          | Left gesture.    |
| leftThenRight | string          | Left-then-right gesture.|
| leftThenUp    | string          | Left-then-up gesture.|
| leftThenDown  | string          | Left-then-down gesture.|
| right         | string          | Right gesture.    |
| rightThenLeft | string          | Right-then-left gesture.|
| rightThenUp   | string          | Right-then-up gesture.|
| rightThenDown | string          | Right-then-down gesture.|
| up            | string          | Up gesture.    |
| upThenLeft    | string          | Up-then-left gesture.|
| upThenRight   | string          | Up-then-right gesture.|
| upThenDown    | string          | Up-then-down gesture.|
| down          | string          | Down gesture.    |
| downThenLeft  | string          | Down-then-left gesture.|
| downThenRight | string          | Down-then-right gesture.|
| downThenUp    | string          | Down-then-up gesture.|
| twoFingerSingleTap<sup>11+</sup>  | string          | Two-finger single-tap gesture.|
| twoFingerDoubleTap<sup>11+</sup>  | string          | Two-finger double-tap gesture.|
| twoFingerDoubleTapAndHold<sup>11+</sup> | string          | Two-finger double-tap-and-hold gesture.|
| twoFingerTripleTap<sup>11+</sup>  | string          | Two-finger triple-tap gesture.|
| twoFingerTripleTapAndHold<sup>11+</sup> | string          | Two-finger triple-tap-and-hold gesture.|
| threeFingerSingleTap<sup>11+</sup> | string          | Three-finger single-tap gesture.|
| threeFingerDoubleTap<sup>11+</sup> | string          | Three-finger double-tap gesture.|
| threeFingerDoubleTapAndHold<sup>11+</sup> | string          | Three-finger double-tap-and-hold gesture.|
| threeFingerTripleTap<sup>11+</sup> | string          | Three-finger triple-tap gesture.|
| threeFingerTripleTapAndHold<sup>11+</sup> | string          | Three-finger triple-tap-and-hold gesture.|
| fourFingerSingleTap<sup>11+</sup> | string          | Four-finger single-tap gesture.|
| fourFingerDoubleTap<sup>11+</sup> | string          | Four-finger double-tap gesture.|
| fourFingerDoubleTapAndHold<sup>11+</sup> | string          | Four-finger double-tap-and-hold gesture.|
| fourFingerTripleTap<sup>11+</sup> | string          | Four-finger triple-tap gesture.|
| fourFingerTripleTapAndHold<sup>11+</sup> | string          | Four-finger triple-tap-and-hold gesture.|
| threeFingerSwipeUp<sup>11+</sup>  | string          | Three-finger swipe-up gesture.|
| threeFingerSwipeDown<sup>11+</sup> | string          | Three-finger swipe-down gesture.|
| threeFingerSwipeLeft<sup>11+</sup> | string          | Three-finger swipe-left gesture.|
| threeFingerSwipeRight<sup>11+</sup> | string          | Three-finger swipe-right gesture.|
| fourFingerSwipeUp<sup>11+</sup>   | string          | Four-finger swipe-up gesture.|
| fourFingerSwipeDown<sup>11+</sup> | string          | Four-finger swipe-down gesture.|
| fourFingerSwipeLeft<sup>11+</sup> | string          | Four-finger swipe-left gesture.|
| fourFingerSwipeRight<sup>11+</sup> | string          | Four-finger swipe-right gesture.|

## PageUpdateType

type PageUpdateType = 'pageContentUpdate' | 'pageStateUpdate'

Enumerates the page update types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type               | Description           |
| ----------------- | ---------------- |
| 'pageContentUpdate' | Update of the page content.|
| 'pageStateUpdate' | Update of the page status.|

## TouchGuideType

type TouchGuideType = 'touchBegin' | 'touchEnd'

Enumerates the touch guide event types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type               | Description                 |
| ---------- | ------------------- |
| 'touchBegin' | Start of touch in touch guide mode.|
| 'touchEnd' | End of touch in touch guide mode.|

## AccessibilityExtensionAbility.onConnect<sup>(deprecated)</sup>

onConnect(): void;

Called when the **AccessibilityExtensionAbility** is enabled and connected to the system service. In this API, you can have the service logic initialized. This API can be overridden as required.

> **NOTE**
>
> This API is deprecated since API version 12. The substitute API is available only for system applications.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    console.log('AxExtensionAbility onConnect');
  }
}
```

## AccessibilityExtensionAbility.onDisconnect<sup>(deprecated)</sup>

onDisconnect(): void;

Called when the **AccessibilityExtensionAbility** is disabled and disconnected from the system service. In this API, you can implement the service logic of resource release and exit. This API can be overridden as required.

> **NOTE**
>
> This API is deprecated since API version 12. The substitute API is available only for system applications.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onDisconnect(): void {
    console.log('AxExtensionAbility onDisconnect');
  }
}
```

## AccessibilityExtensionAbility.onAccessibilityEvent<sup>(deprecated)</sup>

onAccessibilityEvent(event: AccessibilityEvent): void;

Called when an event that matches the specified bundle and event type occurs. In this API, you can implement event-specific service logic. Generally, this API needs to be overridden.

> **NOTE**
>
> This API is deprecated since API version 12. The substitute API is available only for system applications.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                                      | Mandatory  | Description             |
| ----- | ---------------------------------------- | ---- | --------------- |
| event | [AccessibilityEvent](#accessibilityevent) | Yes   | Accessibility event. No return value.|

**Example**

```ts
import { AccessibilityExtensionAbility, AccessibilityEvent } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityEvent(event: AccessibilityEvent): void {
    console.log('AxExtensionAbility onAccessibilityEvent');
    if (event.eventType === 'click') {
      console.log('AxExtensionAbility onAccessibilityEvent: click');
    }
  }
}
```

## AccessibilityExtensionAbility.onKeyEvent<sup>(deprecated)</sup>

onKeyEvent(keyEvent: KeyEvent): boolean;

Called when a physical key is pressed. In this API, you can determine whether to consume the event based on the service.

> **NOTE**
>
> This API is deprecated since API version 12. The substitute API is available only for system applications.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                              | Mandatory  | Description                     |
| -------- |--------------------------------------------------| ---- | ----------------------- |
| keyEvent | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | Yes   | Key event. If **true** is returned, the key is consumed.|

**Return value**
| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the event is consumed and will not be transferred;<br>returns **false** otherwise.|

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { KeyEvent } from '@kit.InputKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onKeyEvent(keyEvent: KeyEvent): boolean {
    console.log('AxExtensionAbility onKeyEvent');
    if (keyEvent.key.code === 16) {
      console.log('AxExtensionAbility onKeyEvent: intercept 16');
      return true;
    }
    return false;
  }
}
```
