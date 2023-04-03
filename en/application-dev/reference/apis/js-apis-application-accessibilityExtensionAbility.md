# @ohos.application.AccessibilityExtensionAbility (AccessibilityExtensionAbility)

The **AccessibilityExtensionAbility** module provides accessibility extension capabilities based on the ExtensionAbility framework.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';
```

## Attributes

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name     | Type| Readable| Writable| Description                     |
| --------- | -------- | ---- | ---- | ------------------------- |
| context | [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md) | Yes| No| Context of the accessibility extension ability.|

## AccessibilityEvent

Defines an accessibility event.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name       | Type                                    | Readable  | Writable  | Description        |
| --------- | ---------------------------------------- | ---- | ---- | ---------- |
| eventType | [accessibility.EventType](js-apis-accessibility.md#EventType) \| [accessibility.WindowUpdateType](js-apis-accessibility.md#WindowUpdateType) \| [TouchGuideType](#touchguidetype) \| [GestureType](#gesturetype) \| [PageUpdateType](#pageupdatetype) | Yes   | No   | Event type.   |
| target    | [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9)                     | Yes   | No   | Target component where the event occurs.|
| timeStamp | number                                   | Yes   | No   | Timestamp of the event.    |

## GestureType

Enumerates gesture types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name           | Description          |
| ------------- | ------------ |
| left          | Left gesture. String type. |
| leftThenRight | Left-then-right gesture. String type. |
| leftThenUp    | Left-then-up gesture. String type. |
| leftThenDown  | Left-then-down gesture. String type. |
| right         | Right gesture. String type. |
| rightThenLeft | Right-then-left gesture. String type. |
| rightThenUp   | Right-then-up gesture. String type. |
| rightThenDown | Right-then-down gesture. String type. |
| up            | Up gesture. String type. |
| upThenLeft    | Up-then-left gesture. String type. |
| upThenRight   | Up-then-right gesture. String type. |
| upThenDown    | Up-then-down gesture. String type. |
| down          | Down gesture. String type. |
| downThenLeft  | Down-then-left gesture. String type. |
| downThenRight | Down-then-right gesture. String type. |
| downThenUp    | Down-then-up gesture. String type. |

## PageUpdateType

Enumerates the page update types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name               | Description       |
| ----------------- | --------- |
| pageContentUpdate | Update of the page content. String type. |
| pageStateUpdate   | Update of the page status. String type. |

## TouchGuideType

Enumerates the touch guide event types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name        | Description          |
| ---------- | ------------ |
| touchBegin | Start of touch in touch guide mode. String type. |
| touchEnd   | End of touch in touch guide mode. String type. |

## AccessibilityExtensionAbility.onConnect

onConnect(): void;

Called when the **AccessibilityExtensionAbility** is enabled and connected to the system service. In this API, you can have the service logic initialized. This API can be overridden as required.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Example**

```ts
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
    onConnect() {
        console.log('AxExtensionAbility onConnect');
    }
};
```

## AccessibilityExtensionAbility.onDisconnect

onDisconnect(): void;

Called when the **AccessibilityExtensionAbility** is disabled and disconnected from the system service. In this API, you can implement the service logic of resource release and exit. This API can be overridden as required.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Example**

```ts
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
    onDisconnect() {
        console.log('AxExtensionAbility onDisconnect');
    }
};
```

## AccessibilityExtensionAbility.onAccessibilityEvent

onAccessibilityEvent(event: AccessibilityEvent): void;

Called when an event that matches the specified bundle and event type occurs. In this API, you can implement event-specific service logic. Generally, this API needs to be overridden.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                                    | Mandatory  | Description             |
| ----- | ---------------------------------------- | ---- | --------------- |
| event | [AccessibilityEvent](#accessibilityevent) | Yes   | Accessibility event. No value is returned.|

**Example**

```ts
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
    onAccessibilityEvent(event) {
        console.log('AxExtensionAbility onAccessibilityEvent');
        if (event.eventType === 'click') {
            console.log('AxExtensionAbility onAccessibilityEvent: click');
        }
    }
};
```

## AccessibilityExtensionAbility.onKeyEvent

onKeyEvent(keyEvent: KeyEvent): boolean;

Called when a physical key is pressed. In this API, you can determine whether to intercept an event based on the service.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                    | Mandatory  | Description                     |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| keyEvent | [KeyEvent](js-apis-keyevent.md#KeyEvent) | Yes   | Key event. If **true** is returned, the key is intercepted.|

**Example**

```ts
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
    onKeyEvent(keyEvent) {
        console.log('AxExtensionAbility onKeyEvent');
        if (keyEvent.keyCode === 22) {
            console.log('AxExtensionAbility onKeyEvent: intercept 22');
            return true;
        }
        return false;
    }
};
```
