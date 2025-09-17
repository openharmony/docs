# AccessibilityExtensionContext (System API)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

The **AccessibilityExtensionContext** module, inherited from **ExtensionContext**, provides context for **AccessibilityExtensionAbility**.

You can use the APIs of this module to configure the concerned information, obtain root information, and inject gestures.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The current page contains only the system APIs of the current module. For details about other public APIs, see [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md).

## How to Use

Before using the **AccessibilityExtensionContext** module, you must define a child class that inherits from **AccessibilityExtensionAbility**.

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let axContext = this.context; 
  } 
}
```

## Parameter<sup>20+</sup>

Sets the parameter for a specific operation when the accessibility node element executes this operation.
For details, see [AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                 | Type    | Read-Only |Optional| Description                               |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| setText             | string | No  |Yes|Text content of the component.                |
| selectTextBegin     | string | No | Yes|Start coordinate of the selected text in the component, for example, **'2'**.       |
| selectTextEnd       | string | No  | Yes|End coordinate of the selected text in the component, for example, **'8'**.     |
| selectTextInForWard | bool   | No   | Yes|Whether to select the text within the component forward, for example, **true**.     |
| offset              | string | No  | Yes|Cursor offset, for example, **'1'**.   |
| spanId              | string | No  |Yes|ID of the hyperlink wrapped by the span tag.               |
| scrollType          | string | No  | Yes|Scroll type of the component. The options are **'fullScreen'** and **'halfScreen'**.|

For example, if the characters whose indexes range from 0 to 7 in the text input box are selected, the parameters set by the **executeAction(AccessibilityAction.SET_SELECTION, parameter)** method are as follows:
```ts
let p : Parameter = { selectTextBegin: '0', selectTextEnd: '8', selectTextInForWard: true }
```

## AccessibilityGrid<sup>20+</sup>

Defines accessibility grid information.
For details, see [AccessibilityElement.currentItem](#accessibilityelement12).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                 | Type    | Read-Only |Optional| Description                               |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| rowIndex             | number | No  |No|Row index.                |
| columnIndex          | number | No | No|Column index.       |


## AccessibilitySpan<sup>20+</sup>

Defines the information about the hyperlink wrapped by the span tag.
For details, see [AccessibilityElement.spans](#accessibilityelement12).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                 | Type    | Read-Only |Optional| Description                               |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| spanId             | number | No  |No|Hyperlink ID.                |
| spanText          | string | No| No|Text content of the hyperlink.       |
| accessibilityText          | string | No | No|Accessibility text of the hyperlink.       |
| accessibilityDescription          | string | No | No|Accessibility description of the hyperlink.       |
| accessibilityLevel          | string | No | No|Accessibility level of the hyperlink.       |


## startAbility<sup>12+</sup>

startAbility(want: Want): Promise\<void>;

Starts the foreground page.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../../reference/apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want information about the target ability, such as the ability name and bundle name.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.huawei.hmos.photos',
  abilityName: 'com.huawei.hmos.photos.MainAbility'
}

axContext.startAbility(want).then(() => {
  console.info(`startAbility Succeeded enable ability`);
}).catch((err: BusinessError) => {
  console.error(`startAbility failed to enable ability, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getElements<sup>18+</sup>

getElements(windowId: number, elementId?: number): Promise<Array&lt;AccessibilityElement&gt;>;

Obtains node elements in batches.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowId | number | Yes| Window ID to be obtained.|
| elementId | number | No| Element ID to be obtained. If this parameter is passed in, the list of all child nodes under the current node is obtained. Otherwise, all nodes in the window are obtained. The default value is **-1**.|

**Return value**
| Type                                 | Description                    |
| ----------------------------------- | ---------------------- |
| Promise<Array&lt;AccessibilityElement&gt;> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;
let elementId: number = 10;

axContext.getElements(windowId, elementId).then((data:AccessibilityElement[]) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getDefaultFocusedElementIds<sup>18+</sup>

getDefaultFocusedElementIds(windowId: number): Promise<Array&lt;number&gt;>;

Obtains the custom default focuses of an application.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowId | number | Yes| Window ID to be obtained.|

**Return value**
| Type                                 | Description                    |
| ----------------------------------- | ---------------------- |
| Promise<Array&lt;number&gt;> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;

axContext.getDefaultFocusedElementIds(windowId).then((data: number[]) => {
  console.log(`Succeeded in get default focus, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get default focus, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.holdRunningLockSync<sup>20+</sup>

holdRunningLockSync(): void

Holds the running lock. After the lock is held, the screen will not turn off automatically.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.holdRunningLockSync();
} catch (err) {
  console.error(`Failed to hold RunningLock, Code is ${err.code}, message is ${err.message}`);
}
```

## AccessibilityExtensionContext.unholdRunningLockSync<sup>20+</sup>

unholdRunningLockSync(): void

Releases the running lock. After the lock is released, the screen will automatically turn off.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.unholdRunningLockSync();
} catch (err) {
  console.error(`Failed to unhold RunningLock, code is ${err.code}, message is ${err.message}`);
}
```

## AccessibilityExtensionContext.on('preDisconnect')<sup>20+</sup>

on(type: 'preDisconnect', callback: Callback&lt;void&gt;): void

Subscribes to the pre-disconnection event of the accessibility extension service. This API is called when the accessibility extension service is about to be disconnected.

Used together with [notifyDisconnect](#accessibilityextensioncontextnotifydisconnect20); otherwise, the accessibility extension service is automatically disconnected 30 seconds later by default.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Name of the event to listen for. The value is fixed at **'preDisconnect'**, indicating that the accessibility extension service is about to be disconnected.|
| callback | Callback&lt;void&gt; | Yes|Callback to be invoked when the accessibility extension service is about to be disconnected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.on('preDisconnect', () => {
    console.info(`To do something before accessibilityExtension disconnect.`);
  });
} catch (err) {
  console.error(`Failed to register, code is ${err.code}, message is ${err.message}`);
}
```

## AccessibilityExtensionContext.off('preDisconnect')<sup>20+</sup>

off(type: 'preDisconnect', callback?: Callback&lt;void&gt;): void

Unsubscribes from the pre-disconnection event of the accessibility extension service. This API is not called until the accessibility extension service is disconnected.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Name of the event to listen for. The value is fixed at **'preDisconnect'**, indicating that the accessibility extension service is about to be disconnected.|
| callback | Callback&lt;void&gt; | No|Callback to unregister, which must be the same as that of [on('preDisconnect')](#accessibilityextensioncontextonpredisconnect20). If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.off('preDisconnect', () => {
    console.info(`To do something before accessibilityExtension disconnect.`);
  });
} catch (err) {
  console.error(`Failed to unRegister, code is ${err.code}, message is ${err.message}`);
}
```

## AccessibilityExtensionContext.notifyDisconnect<sup>20+</sup>

notifyDisconnect(): void

Notifies the accessibility service that the accessibility extension service can be disconnected.

This API must be used together with the [on('preDisconnect')](#accessibilityextensioncontextonpredisconnect20) API. If the **on('preDisconnect')** API is not called, this API does not take effect.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.notifyDisconnect();
} catch (err) {
  console.error(`Failed to notify accessibility, code is ${err.code}, message is ${err.message}`);
}
```

## getAccessibilityFocusedElement<sup>20+</sup>

getAccessibilityFocusedElement(): Promise\<AccessibilityElement>;

Obtains the element that is currently focused. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**
| Type                                | Description                   |
| ----------------------------------- | ---------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)>| Promise used to return the result.|

**Error codes**
For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300003 | No accessibility permission to perform the operation. |
| 9300006 |  The target application failed to connect to accessibility service. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((element: AccessibilityElement) => {
  console.log(`Succeeded in get accessibility focused element, ${element.bundleName}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get accessibility focused element, Code is ${err.code}, message is ${err.message}`);
});
```

## getRootInActiveWindow<sup>20+</sup>

getRootInActiveWindow(windowId ?: number): Promise\<[AccessibilityElement](#accessibilityelement12)>;

Obtains the root element of an active window.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowId | number | No | Window ID to be obtained.|

**Return value**
| Type                                | Description                   |
| ----------------------------------- | ---------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)>| Promise used to return the result.|

**Error codes**
For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).
| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300003 | No accessibility permission to perform the operation. |
| 9300006 | The target application failed to connect to accessibility service. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 0;

axContext.getRootInActiveWindow(windowId).then((element: AccessibilityElement) => {
  console.log(`Succeeded in get root inactive window element, ${element.bundleName}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get root inactive window element, Code is ${err.code}, message is ${err.message}`);
});
```

## getAccessibilityWindowsSync<sup>20+</sup>

getAccessibilityWindowsSync(displayId?: number): Array\<[AccessibilityElement](#accessibilityelement12)>

Obtains the accessibility windows.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| displayId | number | No | Display ID. If this parameter is not specified, the default display ID is used.|

**Return value**

| Type                                | Description                   |
| ----------------------------------- | ---------------------- |
| Array\<[AccessibilityElement](#accessibilityelement12)> | List of windows.|

**Error codes**
For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).
| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let displayId: number = 0;
  let windowList = context?.getAccessibilityWindowsSync(displayId);
  if (windowList) {
    for (let window of windowList) {
      console.log(`getAccessibilityWindowsSync: windowId: ${window.windowId}`);
    }
  }
} catch (err) {
  console.log(`[FAILED] getAccessibilityWindowsSync: ${err.code} ${err.message}`)
}
```

## AccessibilityElement<sup>12+</sup>

Defines the accessibility node element. Before calling the APIs of **AccessibilityElement**, you should call [AccessibilityExtensionContext.getAccessibilityFocusedElement()](#getaccessibilityfocusedelement20) or [AccessibilityExtensionContext.getRootInActiveWindow()](#getrootinactivewindow20) to obtain an **AccessibilityElement** instance.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Properties

| Name                 | Type                                                            | Read-Only| Optional| Description            |
|----------------------|--------------------------------------------------------------------|------|------|-------------------|
| accessibilityFocused<sup>20+</sup> | boolean | No| Yes| Whether the element is focused for accessibility purposes. The value **true** indicates that the element is focused, and **false** indicates the opposite.<br>Default value: **false**.|
| bundleName<sup>20+</sup> | string                                                             | No | Yes | Bundle name.|
| checkable<sup>20+</sup> | boolean | No| Yes| Whether the element can be checked. The value **true** indicates that the element can be checked, and **false** indicates the opposite.<br>Default value: **false**.|
| checked<sup>20+</sup> | boolean | No| Yes| Whether the element is checked. The value **true** indicates that the element is checked, and **false** indicates the opposite.<br>Default value: **false**.|
| clickable<sup>20+</sup> | boolean | No| Yes| Whether the element is clickable. The value **true** indicates that the element is clickable, and **false** indicates the opposite.<br>Default value: **false**.|
| componentId<sup>20+</sup> | number | No| Yes| ID of the component to which the element belongs.<br>Default value: **1**.|
| componentType<sup>20+</sup> | string                                                             | No | Yes | Type of the component to which the element belongs.|
| contents<sup>20+</sup> | Array&lt;string&gt;                                                | No | Yes | Content displayed in the element.|
| currentIndex<sup>20+</sup> | number                                                             | No | Yes | Index of the current item.<br>Default value: **0**.|
| description<sup>20+</sup> | string                                                             | No | Yes | Description of the element.|
| editable<sup>20+</sup> | boolean | No| Yes| Whether the element is editable. The value **true** indicates that the element is editable, and **false** indicates the opposite.<br>Default value: **false**.|
| endIndex<sup>20+</sup> | number                                                             | No | Yes | Index of the last list item displayed on the screen.<br>Default value: **0**.|
| error<sup>20+</sup> | string                                                             | No | Yes | Error status of the element.|
| focusable<sup>20+</sup> | boolean | No| Yes| Whether the element can be focused. The value **true** indicates that the element can be focused, and **false** indicates the opposite.<br>Default value: **false**.|
| hintText<sup>20+</sup> | string                                                             | No | Yes | Hint text.|
| inputType<sup>20+</sup> | number                                                             | No | Yes | Type of the input text.<br>Default value: **0**.|
| inspectorKey<sup>20+</sup> | string                                                             | No | Yes | Inspector key.|
| isActive<sup>20+</sup> | boolean | No| Yes| Whether the element is active. The value **true** indicates that the element is active, and **false** indicates the opposite.<br>Default value: **true**.|
| isEnable<sup>20+</sup> | boolean | No| Yes| Whether the element is enabled. The value **true** indicates that the element is enabled, and **false** indicates the opposite.<br>Default value: **false**.|
| isHint<sup>20+</sup> | boolean | No| Yes| Whether the element is a hint. The value **true** indicates that the element is a hint, and **false** indicates the opposite.<br>Default value: **false**.|
| isFocused<sup>20+</sup> | boolean | No| Yes| Whether the element is focused. The value **true** indicates that the element is focused, and **false** indicates the opposite.<br>Default value: **false**.|
| isPassword<sup>20+</sup> | boolean                                                            | No | Yes | Whether the element is a password. The value **true** indicates that the element is a password, and **false** indicates the opposite.<br>Default value: **false**.|
| isVisible<sup>20+</sup> | boolean | No| Yes| Whether the element is visible. The value **true** indicates that the element is visible, and **false** indicates the opposite.<br>Default value: **false**.|
| itemCount<sup>20+</sup> | number                                                             | No | Yes | Total number of items.<br>Default value: **0**.|
| lastContent<sup>20+</sup> | string                                                             | No | Yes | Last item.|
| layer<sup>20+</sup> | number                                                             | No | Yes | Display layer of the element.|
| longClickable<sup>20+</sup> | boolean | No| Yes| Whether the element can be long-pressed. The value **true** indicates that the element can be long-pressed, and **false** indicates the opposite.<br>Default value: **false**.|
| pageId<sup>20+</sup> | number | No| Yes| Page ID.<br>Default value: **1**.|
| pluralLineSupported<sup>20+</sup> | boolean | No| Yes| Whether the element supports multiple lines of text. The value **true** indicates that the element supports multiple lines of text, and **false** indicates the opposite.<br>Default value: **false**.|
| rect<sup>20+</sup>                 | [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect)                                                      | No | Yes | Rectangular area for the element.|
| resourceName<sup>20+</sup>         | string                                                             | No | Yes | Resource name of the element.|
| screenRect<sup>20+</sup>           | [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect)                                                      | No | Yes | Rectangular area for the element to display.|
| scrollable<sup>20+</sup>           | boolean                                                            | No | Yes | Whether the element is scrollable. The value **true** indicates that the element is scrollable, and **false** indicates the opposite.<br>Default value: **false**.|
| selected<sup>20+</sup>             | boolean                                                            | No | Yes | Whether the element is selected. The value **true** indicates that the element is selected, and **false** indicates the opposite.<br>Default value: **false**.|
| startIndex<sup>20+</sup>           | number                                                             | No | Yes | Index of the first item on the screen.<br>Default value: **0**.|
| text<sup>20+</sup>                 | string                                                             | No | Yes | Text content of an element.|
| textLengthLimit<sup>20+</sup>      | number                                                             | No | Yes | Maximum text length of an element.|
| textMoveUnit<sup>20+</sup>         | [accessibility.TextMoveUnit](js-apis-accessibility.md#textmoveunit)| No | Yes | Movement unit for traversing and reading text.<br>Default value: **0**.|
| triggerAction<sup>20+</sup>        | [accessibility.Action](js-apis-accessibility.md#action)            | No | Yes | Action that triggers the element event.|
| type<sup>20+</sup>                 | [WindowType](js-apis-inner-application-accessibilityExtensionContext.md#windowtype)                                          | No | Yes | Window type of an element.|
| valueMax<sup>20+</sup>             | number                                                             | No | Yes | Maximum value.<br>Default value: **0**.|
| valueMin<sup>20+</sup>             | number                                                             | No | Yes | Minimum value.<br>Default value: **0**.|
| valueNow<sup>20+</sup>             | number                                                             | No | Yes | Current value.<br>Default value: **0**.|
| windowId<sup>20+</sup>             | number                                                             | No | Yes | Window ID.<br>Default value: **1**.|
| offset<sup>20+</sup>             | number              | No | Yes | Pixel offset of the content area from the top of a scrollable component (such as **List** and **Grid**).<br>Default value: **0**.|
| textType<sup>20+</sup>             | string                                                             | No | Yes | Accessibility text type of an element, which is configured by the **accessibilityTextHint** attribute of the component.|
| accessibilityText<sup>20+</sup> | string                                                  | No | Yes | Accessibility text information of an element.|
| hotArea<sup>20+</sup>             | [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect)                                                              | No | Yes | Hot area of an element.|
| customComponentType<sup>20+</sup>             | string                                                             | No | Yes | Custom component type.|
| accessibilityNextFocusId<sup>20+</sup>             | number                | No | Yes | ID of the next component to obtain the focus.<br>Default value: **1**.|
| accessibilityPreviousFocusId<sup>20+</sup>             | number                | No | Yes | ID of the previous component to obtain the focus.<br>Default value: **1**.|
| extraInfo<sup>20+</sup>             | string     | No | Yes | Additional information about an element. The value is a JSON string.|
| accessibilityScrollable<sup>20+</sup>             | boolean                 | No | Yes | Whether the element can be scrolled for accessibility purposes. This attribute has a higher priority than **scrollable**.<br>The value **true** indicates that the element is scrollable, and **false** indicates the opposite.<br>Default value: **true**.|
| supportedActionNames<sup>20+</sup> | Array&lt;string&gt;                                                | No | Yes | Supported action names.|
| accessibilityGroup<sup>20+</sup>  | boolean                                                            | No | Yes | Whether the element is an accessibility group. The value **true** indicates that the element is an accessibility group, and **false** indicates the opposite.<br>Default value: **false**.|
| accessibilityLevel<sup>20+</sup>             | string                                                             | No | Yes | Accessibility level of a component.<br>**auto**: The accessibility grouping service and ArkUI jointly determine whether the current component can be identified by accessibility services.<br>**yes**: The component can be identified by accessibility services.<br>**no**: The component cannot be identified by accessibility services.<br>**no-hide-descendants**: The current component and all its child components cannot be identified by accessibility services.|
| navDestinationId<sup>20+</sup>             | number                                                             | No | Yes | Destination ID of a component for navigation.|
| currentItem<sup>20+</sup>             | [AccessibilityGrid](#accessibilitygrid20)                                                             | No | Yes | Current item in the component grid.|
| spans<sup>20+</sup>             | [AccessibilitySpan](#accessibilityspan20)[]                                                             | No | Yes | Span array of a component.|
| accessibilityVisible<sup>20+</sup>  | boolean                                                            | No | Yes | Whether the component is visible for accessibility purposes. The value **true** indicates that the component is visible, and **false** indicates the opposite.|
| mainWindowId<sup>20+</sup>             | number                                                             | No | Yes| Main window ID of a component.|
| clip<sup>20+</sup>  | boolean                                                            | No | Yes | Whether the component needs to be clipped. The value **true** indicates that the component needs to be clipped, and **false** indicates the opposite.|
| parentId<sup>20+</sup>             | number                                                             | No | Yes | Parent element ID of a component.|
| childrenIds<sup>20+</sup>             | Array\<number>                                                             | No | Yes | List of child element IDs of a component.|

**Example**
```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;

axContext.getRootInActiveWindow(windowId).then((element: AccessibilityElement) => {
  console.info("AccessibilityElement.checkable: " + element.checkable)
  console.info("AccessibilityElement.checked: " + element.checked)
  console.info("AccessibilityElement.clickable: " + element.clickable)
  console.info("AccessibilityElement.componentId: " + element.componentId)
  console.info("AccessibilityElement.componentType: " + element.componentType)
  console.info("AccessibilityElement.contents: " + element.contents)
  console.info("AccessibilityElement.currentIndex: " + element.currentIndex)
  console.info("AccessibilityElement.description: " + element.description)
  // ....
}).catch((err) => {
  console.log(`getRootInActiveWindow failed, code: ${err.code}, message: ${err.message}`);
})
```

### enableScreenCurtain<sup>12+</sup>

enableScreenCurtain(isEnable: boolean): void;

Enables or disables the screen curtain.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description            |
| ----------- | ---------------------------------------- | ---- | -------------- |
| isEnable | boolean | Yes   | The value **true** indicates enabled; **false** indicates disabled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import {
  AccessibilityElement,
  AccessibilityEvent, 
  AccessibilityExtensionContext
} from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class AccessibilityManager {
  private static instance: AccessibilityManager;
  context?: AccessibilityExtensionContext;

  static getInstance(): AccessibilityManager {
    if (!AccessibilityManager.instance) {
      AccessibilityManager.instance = new AccessibilityManager();
    }
    return AccessibilityManager.instance;
  }

  onStart(context: AccessibilityExtensionContext) {
    this.context = context;
  }

  onStop() {
    this.context = undefined;
  }

  onEvent(accessibilityEvent: AccessibilityEvent): void {
    if (!this.context) {
      console.error('context is not available!');
      return;
    }
    this.context.getWindowRootElement().then((rootElement: AccessibilityElement) => {
      console.log(`Succeeded in get root element of the window, ${JSON.stringify(rootElement)}`);
      rootElement.enableScreenCurtain(true);
      console.log(`Succeeded in enableScreenCurtain`);
    }).catch((err: BusinessError) => {
      console.error(`failed to enableScreenCurtain, Code is ${err.code}, message is ${err.message}`);
    });
  }
}
```

### findElement('elementId')<sup>12+</sup>

findElement(type: 'elementId', condition: number): Promise\<AccessibilityElement>;

Queries the node elements in the current active window based on the **elementId**. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                               | Mandatory  | Description                                      |
| --------- | --------------------------------- | ---- | ---------------------------------------- |
| type      | string                            | Yes   | Type of element finding. The value is fixed at **'elementId'**.|
| condition | number | Yes   | **elementId** of the node element.                          |

**Return value**

| Type                                 | Description                              |
| ----------------------------------- | -------------------------------- |
| Promise&lt;[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// elementId is 10.
let condition = 10;

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('elementId', condition).then((data: AccessibilityElement) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('textType')<sup>12+</sup>

findElement(type: 'textType', condition: string): Promise\<Array\<AccessibilityElement>>;

Queries all node elements based on the **accessibilityTextHint** text type configured for a node. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type    | Mandatory  | Description                           |
| --------- | ------ | ---- | ----------------------------- |
| type      | string | Yes   | Type of element finding. The value is fixed at **'textType'**.|
| condition | string | Yes   | Search criteria.                     |

**Return value**

| Type                                      | Description                           |
| ---------------------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// The content of condition must be the same as the type value in the accessibilityTextHint attribute of the target component.
let condition = 'location'; 

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('textType', condition).then((data: AccessibilityElement[]) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### getCursorPosition<sup>12+</sup>

getCursorPosition(): Promise\<number>;

Obtains the cursor position in the **Text** component. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
rootElement.getCursorPosition().then((data: number) => {
  console.info(`Succeeded in getCursorPosition, ${data}`);
}).catch((err: BusinessError) => {
  console.error(`failed to getCursorPosition, Code is ${err.code}, message is ${err.message}`);
});
```

### getCursorPosition<sup>12+</sup>

getCursorPosition(callback: AsyncCallback\<number>): void;

Obtains the cursor position in the **Text** component. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description            |
| ----------- | ---------------------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback function used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
rootElement.getCursorPosition((err: BusinessError, data: number) => {
  if (err && err.code) {
    console.error(`failed to getCursorPosition, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getCursorPosition, ${data}`);
});
```


### executeAction<sup>20+</sup>

executeAction(action: AccessibilityAction, parameters?: Parameter): Promise\<void>;

Executes a specific action based on the specified action type and input parameters. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description                                                      |
| ----------- | ---------------------------------------- | ---- |----------------------------------------------------------|
| action    | [AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction)| Yes   | Executable action for the accessibility node. |
| parameters | [Parameter](#parameter20) | No   | Parameters set for the action. This parameter is left empty by default.                           |

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201     | Permission verification failed.The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.     |
| 9300005 | This action is not supported.            |

**Example**
```ts
// Example of an action without parameters:
import { BusinessError } from '@kit.BasicServicesKit';
import { AccessibilityAction, Parameter } from '@kit.AccessibilityKit';

// rootElement is an instance of AccessibilityElement.
// An action that does not require any parameter setting is an action without parameters, as specified in the action description.
try {
  rootElement.executeAction(AccessibilityAction.CLICK);
  console.info(`Succeeded in perform action CLICK`);
}catch (error){
  console.error(`failed to perform action CLICK, Code is ${error?.code}, message is ${error?.message}`);
}
```



```ts
// Example of an action with parameters:
import { BusinessError } from '@kit.BasicServicesKit'; 
import { AccessibilityAction, Parameter } from '@kit.AccessibilityKit';

try {
  // selectTextBegin: start position of the selected text
  // selectTextEnd: end position of the selected text
  // selectTextInForWard: true indicates to select text forward, and false indicates to select text backward.
  let p : Parameter = { selectTextBegin: '0', selectTextEnd: '8', selectTextInForWard: true }
  // rootElement is an instance of AccessibilityElement.
  // Sample code of setSelection
  rootElement.executeAction(AccessibilityAction.SET_SELECTION, p);
  console.info(`Succeeded in perform action SET_SELECTION`);
}catch (error){
  console.error(`failed to perform action SET_SELECTION, Code is ${error?.code}, message is ${error?.message}`);
}
```

```ts
// Example of an action with parameters:
import { BusinessError } from '@kit.BasicServicesKit';
import { AccessibilityAction, Parameter } from '@kit.AccessibilityKit';

try {
  // offset: cursor position
  let p : Parameter = { offset: '1' }
  // rootElement is an instance of AccessibilityElement.
  // Sample code of setCursorPosition
  rootElement.executeAction(AccessibilityAction.SET_CURSOR_POSITION, p);
  console.info(`Succeeded in perform action SET_CURSOR_POSITION`);
}catch (error){
  console.error(`failed to perform action SET_CURSOR_POSITION, Code is ${error?.code}, message is ${error?.message}`);
}
```

### getParent<sup>20+</sup>

getParent(): Promise\<AccessibilityElement>;

Obtains the parent element of an accessibility node.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                                     | Description                  |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)> | Parent element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                   |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((element: AccessibilityElement) => {
  console.log(`element parent id: ${element.parentId}`);
  element.getParent().then((parent: AccessibilityElement) => {
    console.log(`parent element's parent id: ${parent.parentId}`);
  }).catch((err) => {
    console.log(`getParent failed, code: ${err.code}, message: ${err.message}`);
  })
}).catch((err) => {
  console.log(`getAccessibilityFocusedElement failed, code: ${err.code}, message: ${err.message}`);
})
```

### getChildren<sup>20+</sup>

getChildren(): Promise\<Array\<AccessibilityElement>>;

Obtains the child elements of an element.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                                     | Description                  |
| ---------------------------------------- | --------------------- |
| Promise\<Array\<[AccessibilityElement](#accessibilityelement12)>> | Array of child elements.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                   |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((element: AccessibilityElement) => {
  console.log(`element childrenIds: ${element.childrenIds}`);
  element.getChildren().then((children: AccessibilityElement[]) => {
    console.log(`children element's size: ${children.length}`);
  }).catch((err) => {
    console.log(`getChildren failed, code: ${err.code}, message: ${err.message}`);
  })
}).catch((err) => {
  console.log(`getAccessibilityFocusedElement failed, code: ${err.code}, message: ${err.message}`);
})
```

### getRoot<sup>20+</sup>

getRoot(): Promise\<AccessibilityElement>;

Obtains the root element of an active window.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                                     | Description                  |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)> | Root element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                   |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windows: AccessibilityWindow[] = axContext.getAccessibilityWindowsSync()
for (let window of windows) {
  console.log(`window id: ${window.windowId}`);
  window.getRoot().then((root: AccessibilityElement) => {
    console.log(`root element's componentId: ${root.componentId}`);
  }).catch((err) => {
    console.log(`getRoot failed, code: ${err.code}, message: ${err.message}`);
  })
}
```

### findElementByContent<sup>20+</sup>

findElementByContent(condition: string): Promise\<Array\<AccessibilityElement>>;

Finds elements based on the content.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | string | Yes| Content.|

**Return value**

| Type                                     | Description                  |
| ---------------------------------------- | --------------------- |
| Promise\<Array\<[AccessibilityElement](#accessibilityelement12)>> | Elements obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| ID | Error Message                                   |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**Example**

```ts
// Page.ets
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
// ...

// AccessibilityExtAbility.ets
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;

axContext.getRootInActiveWindow(windowId).then((root: AccessibilityElement) => {
    root.findElementByContent('connect').then((elements: AccessibilityElement[]) => {
        console.log("findElementByContent size=" + elements.length)
    }).catch((err) => {
        console.log(`findElementByContent failed, code: ${err.code}, message: ${err.message}`);
    })
}).catch((err) => {
  console.log(`getRootInActiveWindow failed, code: ${err.code}, message: ${err.message}`);
})
```

### findElementByFocusDirection<sup>20+</sup>

findElementByFocusDirection(condition: FocusDirection): Promise\<AccessibilityElement>;

Finds elements based on the focus direction.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | FocusDirection | Yes| Focus direction.|

**Return value**

| Type                                     | Description                  |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)> | AccessibilityElement.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| ID | Error Message                                   |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**Example**

```ts
// Page.ets
// Click TextInput and then it is the accessibility focus element, up direction element is Text#connect
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)

    TextInput({ placeholder: 'please input...' })
        .id('text_input')
        .fontSize($r('app.float.page_text_font_size'))
// ...

// AccessibilityExtAbility.ets
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((focus: AccessibilityElement) => {
    focus.findElementByFocusDirection('up').then((element: AccessibilityElement) => {
        console.log("findElementByFocusDirection UP componentId: " + element.componentId);
    }).catch((err) => {
        console.log(`findElementByFocusDirection UP failed, code: ${err.code}, message: ${err.message}`);
    })
}).catch((err) => {
  console.log(`getAccessibilityFocusedElement failed, code: ${err.code}, message: ${err.message}`);
})
```

### findElementsByAccessibilityHintText<sup>20+</sup>

findElementsByAccessibilityHintText(condition: string): Promise\<Array\<AccessibilityElement>>;

Finds elements based on the hint text.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | string | Yes| Hint text.|

**Return value**

| Type                                     | Description                  |
| ---------------------------------------- | --------------------- |
| Promise\<Array\<[AccessibilityElement](#accessibilityelement12)>> | Elements obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| ID | Error Message                                   |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**Example**

```ts
// Page.ets
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)

    TextInput({ placeholder: 'please input...' })
        .id('text_input')
        .fontSize($r('app.float.page_text_font_size'))
        .accessibilityTextHint('location')
// ...

// AccessibilityExtAbility.ets
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;

axContext.getRootInActiveWindow(windowId).then((root: AccessibilityElement) => {
    root.findElementsByAccessibilityHintText('location').then((elements: AccessibilityElement[]) => {
        console.log("findElementsByAccessibilityHintText size=" + elements.length)
    }).catch((err) => {
        console.log(`findElementsByAccessibilityHintText failed, code: ${err.code}, message: ${err.message}`);
    })
}).catch((err) => {
  console.log(`getRootInActiveWindow failed, code: ${err.code}, message: ${err.message}`);
})
```

### findElementById<sup>20+</sup>

findElementById(condition: number): Promise\<AccessibilityElement>;

Finds elements based on element ID.

**Required permissions**: ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | number | Yes| Element ID.|

**Return value**

| Type                                     | Description                  |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)> | AccessibilityElement.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| ID | Error Message                                   |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API.|
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**Example**

```ts
// Page.ets
// Click TextInput and then it is the accessibility focus element
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)

    TextInput({ placeholder: 'please input...' })
        .id('text_input')
        .fontSize($r('app.float.page_text_font_size'))
// ...

// AccessibilityExtAbility.ets
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((focus: AccessibilityElement) => {
    focus.findElementById(0).then((element: AccessibilityElement) => {
        console.log("findElementById componentId: " + element.componentId);
    }).catch((err) => {
        console.log(`findElementById failed, code: ${err.code}, message: ${err.message}`);
    })
}).catch((err) => {
  console.log(`getAccessibilityFocusedElement failed, code: ${err.code}, message: ${err.message}`);
})
```
