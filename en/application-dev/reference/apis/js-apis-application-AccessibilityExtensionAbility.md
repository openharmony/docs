# Accessibility Extension Ability

The **AccessibilityExtensionAbility** module is based on the ExtensionAbility framework and provides the **AccessibilityExtensionAbility**.

>**NOTE**
>
>The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility'
```

## Attributes

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name  | Type | Readable | Writable | Description           |
| --------- | -------- | ---- | ---- | ------------------------- |
| context | [AccessibilityExtensionContext](js-apis-accessibility-extension-context.md) | Yes | No | Context of the accessibility extension ability. |

## AccessibilityEvent

Defines an accessibility event.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name       | Type                                    | Readable  | Writable  | Description        |
| --------- | ---------------------------------------- | ---- | ---- | ---------- |
| eventType | [EventType](js-apis-accessibility.md#eventtype) \| [WindowUpdateType](js-apis-accessibility.md#windowupdatetype) \| [TouchGuideType](#touchguidetype) \| [GestureType](#gesturetype) \| [PageUpdateType](#pageupdatetype) | Yes   | No   | Event type.   |
| target    | AccessibilityElement                     | Yes   | No   | Target component where the event occurs.|
| timeStamp | number                                   | Yes   | No   | Timestamp of the event.    |

## GesturePath

Defines a gesture path.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name          | Type                                    | Readable  | Writable  | Description    |
| ------------ | ---------------------------------------- | ---- | ---- | ------ |
| points       | Array&lt;[GesturePoint](gesturepoint)&gt; | Yes   | Yes   | An array of gesture touch points. |
| durationTime | number                                   | Yes   | Yes   | Total time consumed by the gesture.|

## GesturePoint

Defines a gesture touch point.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| positionX | number | Yes   | Yes   | X-coordinate of the touch point.|
| positionY | number | Yes   | Yes   | Y-coordinate of the touch point.|

## GestureType

Enumerates gesture types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name           | Description          |
| ------------- | ------------ |
| left          | Left gesture.    |
| leftThenRight | Left-then-right gesture.|
| leftThenUp    | Left-then-up gesture.|
| leftThenDown  | Left-then-down gesture.|
| right         | Right gesture.    |
| rightThenLeft | Right-then-left gesture.|
| rightThenUp   | Right-then-up gesture.|
| rightThenDown | Right-then-down gesture.|
| up            | Up gesture.    |
| upThenLeft    | Up-then-left gesture.|
| upThenRight   | Up-then-right gesture.|
| upThenDown    | Up-then-down gesture.|
| down          | Down gesture.    |
| downThenLeft  | Down-then-left gesture.|
| downThenRight | Down-then-right gesture.|
| downThenUp    | Down-then-up gesture.|

## PageUpdateType

Enumerates the page refresh types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name               | Description       |
| ----------------- | --------- |
| pageContentUpdate | Update of the page content.|
| pageStateUpdate   | Update of the page status.|

## TouchGuideType

Enumerates the touch guide event types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name        | Description          |
| ---------- | ------------ |
| touchBegin | A touch starts in touch guide mode.|
| touchEnd   | A touch ends in touch guide mode.|

## AccessibilityExtensionAbility.onConnect

onConnect(): void;

Called when the **AccessibilityExtensionAbility** is enabled and connected to the system service. In this API, you can initialize service logic. This API can be overridden as required.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

None

**Example**

```ts
onConnect(): void {
    console.log("AxExtensionAbility onConnect");
}
```

## AccessibilityExtensionAbility.onDisconnect

onDisconnect(): void;

Called when the **AccessibilityExtensionAbility** is disabled and disconnected from the system service. In this API, you can implement the service logic of resource release and exit. This API can be overridden as required.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

None

**Example**

```ts
onDisconnect(): void {
    console.log("AxExtensionAbility onDisconnect");
}
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
onAccessibilityEvent(event: AccessibilityEvent): void {
    console.log("AxExtensionAbility onAccessibilityEvent");
    if (event.eventType == 'click') {
        console.log("AxExtensionAbility onAccessibilityEvent: click");
    }
}
```

## AccessibilityExtensionAbility.onKeyEvent

onKeyEvent(keyEvent: inputEventClient.KeyEvent): boolean;

Called when a physical key is pressed. In this API, you can determine whether to intercept the key event based on the service.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                    | Mandatory  | Description                     |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| keyEvent | [KeyEvent](js-apis-keyevent.md#KeyEvent) | Yes   | Key event. If **true** is returned, the key is intercepted.|

**Example**

```ts
onKeyEvent(keyEvent: inputEventClient.KeyEvent): boolean {
    console.log("AxExtensionAbility onKeyEvent");
    if (keyEvent.keyCode == 22) {
        console.log("AxExtensionAbility onKeyEvent: intercept 22");
        return true;
    }
    return false;
}
```
