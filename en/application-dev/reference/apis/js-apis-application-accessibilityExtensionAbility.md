# @ohos.application.AccessibilityExtensionAbility (AccessibilityExtensionAbility)

The **AccessibilityExtensionAbility** module provides accessibility extension capabilities based on the ExtensionAbility framework.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';
```

### Attributes

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name     | Type                                      | Readable  | Writable  | Description          |
| ------- | ---------------------------------------- | ---- | ---- | ------------ |
| context | [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md) | Yes   | No   | Context of the accessibility extension ability.|

## AccessibilityEvent

Defines an accessibility event.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name     | Type                                                        | Readable| Writable| Description                                                        |
| --------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| eventType | [accessibility.EventType](js-apis-accessibility.md#EventType) \| [accessibility.WindowUpdateType](js-apis-accessibility.md#WindowUpdateType)\| [TouchGuideType](#touchguidetype) \| [GestureType](#gesturetype) \| [PageUpdateType](#pageupdatetype) | Yes  | No  | Event type.<br>**EventType**: accessibility event type.<br>**WindowUpdateType**: Window update type.<br>**TouchGuideType**: touch guide event type.<br>**GestureType**: gesture type.<br>**PageUpdateType**: page update type, which is not supported currently.|
| target    | [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9) | Yes  | No  | Target component where the event occurs.                                        |
| timeStamp | number                                                       | Yes  | No  | Timestamp of the event.                                                |


## AccessibilityElement<sup>10+</sup>

Level-2 module of [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9).

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';

let AccessibilityElement: AccessibilityElement;
```

## ElementAttributeValues<sup>10+</sup>

Level-2 module of [ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues).

**Example**

```ts
import { ElementAttributeValues } from '@ohos.application.AccessibilityExtensionAbility';

let ElementAttributeValues: ElementAttributeValues;
```

## FocusDirection<sup>10+</sup>

Enumerates the focus directions. It is a level-2 module of [FocusDirection](js-apis-inner-application-accessibilityExtensionContext.md#focusdirection).

**Example**

```ts
import { FocusDirection } from '@ohos.application.AccessibilityExtensionAbility';

let FocusDirection: FocusDirection;
```

## ElementAttributeKeys<sup>10+</sup>

ElementAttributeKeys keyof [ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues)

**Example**

```ts
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';

let ElementAttributeKeys: ElementAttributeKeys;
```

## FocusType<sup>10+</sup>

Enumerates the focus types. It is a level-2 module of [FocusType](js-apis-inner-application-accessibilityExtensionContext.md#focustype).

**Example**

```ts
import { FocusType } from '@ohos.application.AccessibilityExtensionAbility';

let FocusType: FocusType;
```

## WindowType <sup>10+</sup>

Enumerates the window types. It is a level-2 module of [WindowType](js-apis-inner-application-accessibilityExtensionContext.md#windowtype).

**Example**

```ts
import { WindowType } from '@ohos.application.AccessibilityExtensionAbility';

let WindowType: WindowType;
```

## Rect<sup>10+</sup>

Defines a rectangle. It is a level-2 module of [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect).

**Example**

```ts
import { Rect } from '@ohos.application.AccessibilityExtensionAbility';

let Rect: Rect;
```

## GestureType

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
| twoFingerSingleTap<sup>11+</sup>    | string          | Two-finger tap gesture.|
| twoFingerDoubleTap<sup>11+</sup>    | string          | Two-finger double-tap gesture.|
| twoFingerDoubleTapAndHold<sup>11+</sup>    | string          | Two-finger double-tap and press-and-hold gesture.|
| twoFingerTripleTap<sup>11+</sup>    | string          | Two-finger triple-tap gesture.|
| twoFingerTripleTapAndHold<sup>11+</sup>    | string          | Two-finger triple-tap and press-and-hold gesture.|
| threeFingerSingleTap<sup>11+</sup>    | string          | Three-finger tap gesture.|
| threeFingerDoubleTap<sup>11+</sup>    | string          | Three-finger double-tap gesture.|
| threeFingerDoubleTapAndHold<sup>11+</sup>    | string          | Three-finger double-tap and press-and-hold gesture.|
| threeFingerTripleTap<sup>11+</sup>    | string          | Three-finger triple-tap gesture.|
| threeFingerTripleTapAndHold<sup>11+</sup>    | string          | Three-finger triple-tap and press-and-hold gesture.|
| fourFingerSingleTap<sup>11+</sup>    | string          | Four-finger tap gesture.|
| fourFingerDoubleTap<sup>11+</sup>    | string          | Four-finger double-tap gesture.|
| fourFingerDoubleTapAndHold<sup>11+</sup>    | string          | Four-finger double-tap and press-and-hold gesture.|
| fourFingerTripleTap<sup>11+</sup>    | string          | Four-finger triple-tap gesture.|
| fourFingerTripleTapAndHold<sup>11+</sup>    | string          | Four-finger triple-tap and press-and-hold gesture.|
| threeFingerSwiperUp<sup>11+</sup>    | string          | Three-finger swipe-up gesture.|
| threeFingerSwiperDown<sup>11+</sup>    | string          | Three-finger swipe-down gesture.|
| threeFingerSwiperLeft<sup>11+</sup>    | string          | Three-finger swipe-left gesture.|
| threeFingerSwiperRight<sup>11+</sup>    | string          | Three-finger swipe-right gesture.|
| fourFingerSwiperUp<sup>11+</sup>    | string          | Four-finger swipe-up gesture.|
| fourFingerSwiperDown<sup>11+</sup>    | string          | Four-finger swipe-down gesture.|
| fourFingerSwiperLeft<sup>11+</sup>    | string          | Four-finger swipe-left gesture.|
| fourFingerSwiperRight<sup>11+</sup>    | string          | Four-finger swipe-right gesture.|

## PageUpdateType

Enumerates the page update types. This API is not supported currently.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name               | Type               | Description              |
| ----------------- | ----------------- | ---------------- |
| pageContentUpdate | string | Update of the page content.|
| pageStateUpdate   | string | Update of the page status.|

## TouchGuideType

Enumerates the touch guide event types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name        | Type               | Description                 |
| ---------- | ---------- | ------------------- |
| touchBegin | string | Start of touch in touch guide mode.|
| touchEnd   | string | End of touch in touch guide mode.|

## AccessibilityExtensionAbility.onConnect

onConnect(): void;

Called when the **AccessibilityExtensionAbility** is enabled and connected to the system service. In this API, you can have the service logic initialized. This API can be overridden as required.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Example**

```ts
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    console.log('AxExtensionAbility onConnect');
  }
}
```

## AccessibilityExtensionAbility.onDisconnect

onDisconnect(): void;

Called when the **AccessibilityExtensionAbility** is disabled and disconnected from the system service. In this API, you can implement the service logic of resource release and exit. This API can be overridden as required.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Example**

```ts
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onDisconnect(): void {
    console.log('AxExtensionAbility onDisconnect');
  }
}
```

## AccessibilityExtensionAbility.onAccessibilityEvent

onAccessibilityEvent(event: AccessibilityEvent): void;

Called when an event that matches the specified bundle and event type occurs. In this API, you can implement event-specific service logic. Generally, this API needs to be overridden.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                                      | Mandatory  | Description             |
| ----- | ---------------------------------------- | ---- | --------------- |
| event | [AccessibilityEvent](#accessibilityevent) | Yes   | Accessibility event. No value is returned.|

**Example**

```ts
import AccessibilityExtensionAbility , { AccessibilityEvent } from '@ohos.application.AccessibilityExtensionAbility';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityEvent(event: AccessibilityEvent): void {
    console.log('AxExtensionAbility onAccessibilityEvent');
    if (event.eventType === 'click') {
      console.log('AxExtensionAbility onAccessibilityEvent: click');
    }
  }
}
```

## AccessibilityExtensionAbility.onKeyEvent

onKeyEvent(keyEvent: KeyEvent): boolean;

Called when a physical key is pressed. In this API, you can determine whether to intercept an event based on the service.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                     |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| keyEvent | [KeyEvent](js-apis-keyevent.md#keyevent) | Yes   | Key event. If **true** is returned, the key is intercepted.|

**Example**

```ts
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';
import { KeyEvent } from '@ohos.multimodalInput.keyEvent';

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
