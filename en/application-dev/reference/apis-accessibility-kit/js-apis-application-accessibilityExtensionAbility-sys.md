# @ohos.application.AccessibilityExtensionAbility (AccessibilityExtensionAbility) (System API)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

AccessibilityExtensionAbility provides accessibility service capabilities based on the ExtensionAbility framework, including connecting to and disconnecting from accessibility services, and processing accessibility service events and accessibility key events.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about other public APIs, see [@ohos.application.AccessibilityExtensionAbility](js-apis-application-accessibilityExtensionAbility.md).

## Modules to Import

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
```
## AccessibilityEventInfo

Describes the accessibility event information.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Properties

| Name                           | Type                                      | Read-Only  | Optional  | Description                                      |
| ----------------------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| eventType                     | [AccessibilityEventType](./js-apis-accessibility-sys.md#accessibilityeventtype) | No   | No   | Event type.                                |
| target                        | [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext-sys.md#accessibilityelement12) | No   | Yes   | Target component where the event occurs.                              |
| timeStamp                     | number                                   | No   | Yes   | Timestamp of the event, in milliseconds. The default value is **0**.                      |
| extraInfo                     | string                                   | No   | Yes   | Added or deleted text content carried by the **TextArea**, **TextInput**, **SearchField**, or **RichEdit** component.|


## AccessibilityExtensionAbility.onAccessibilityConnect

onAccessibilityConnect(): void;

Called when the AccessibilityExtensionAbility is enabled and connected to the system service.
In this API, you can have the service logic initialized. This API can be overridden as required. It returns the result to notify that the ability is successfully connected.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityConnect(): void {
    console.log('AxExtensionAbility onAccessibilityConnect');
  }
}
```

## AccessibilityExtensionAbility.onAccessibilityDisconnect

onAccessibilityDisconnect(): void;

Called when the AccessibilityExtensionAbility is successfully disconnected from the system service.
In this API, you can implement the service logic of resource release and exit. This API can be overridden as required.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityDisconnect(): void {
    console.log('AxExtensionAbility onAccessibilityDisconnect');
  }
}
```

## AccessibilityExtensionAbility.onAccessibilityEventInfo

onAccessibilityEventInfo(event: AccessibilityEventInfo): void;

Called when a specified event occurs in an application. In this API, you can implement event-specific service logic. Generally, this API needs to be overridden.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                                      | Mandatory  | Description   |
| ----- | ---------------------------------------- | ---- | ----- |
| event | [AccessibilityEventInfo](#accessibilityeventinfo) | Yes   | Accessibility event information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityExtensionAbility, AccessibilityEventInfo, AccessibilityEventType } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityEventInfo(event: AccessibilityEventInfo): void {
    console.log('AxExtensionAbility onAccessibilityEventInfo');
    if (event.eventType === AccessibilityEventType.TYPE_CLICK) {
      console.log('AxExtensionAbility onAccessibilityEventInfo: click');
    }
  }
}
```

## AccessibilityExtensionAbility.onAccessibilityKeyEvent

onAccessibilityKeyEvent(keyEvent: KeyEvent): boolean;

Called when a physical key is pressed. In this API, you can determine whether to consume the event based on the service.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description  |
| -------- | ---------------------------------------- | ---- | ---- |
| keyEvent | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | Yes   | Key event.|

**Return value**
| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the event is consumed and will not be transferred; returns **false** otherwise. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { KeyEvent, KeyCode } from '@kit.InputKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityKeyEvent(keyEvent: KeyEvent): boolean {
    console.log('AxExtensionAbility onAccessibilityKeyEvent');
    if (keyEvent.key.code === KeyCode.KEYCODE_VOLUME_UP) {
      console.log('AxExtensionAbility onAccessibilityKeyEvent: intercept 16');
      return true;
    }
    return false;
  }
}
```
