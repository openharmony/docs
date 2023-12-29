# AccessibilityExtensionContext (Accessibility Extension Context)

The **AccessibilityExtensionContext** module, inherited from **ExtensionContext**, provides context for **AccessibilityExtensionAbility**.

You can use the APIs of this module to configure the concerned information, obtain root information, and inject gestures.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## Usage

Before using the **AccessibilityExtensionContext** module, you must define a child class that inherits from **AccessibilityExtensionAbility**.

```ts
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let axContext = this.context; 
  } 
}
```

## ElementAttributeValues

| key            | value            | Description                 |
| ------------- | ------------- | ------------------- |
| accessibilityFocused | boolean          |   Accessibility focus status.  |
| bundleName | string          | Bundle name.|
| checkable    | boolean          | Whether the element is checkable.|
| checked  | boolean          | Whether the element is checked.|
| children  | Array<AccessibilityElement>          | All child elements.|
| clickable  | boolean          | Whether the element is clickable.|
| componentId  | number          | ID of the component to which the element belongs.|
| componentType  | string          | Type of the component to which the element belongs.|
| contents  | Array<string>          | Content.|
| currentIndex  | number          | Index of the current item.|
| description  | string          | Description of the element.|
| editable  | boolean          | Whether the element is editable.|
| endIndex  | number          | Index of the last list item displayed on the screen.|
| error  | string          | Error status.|
| focusable  | boolean          | Whether the element is focusable.|
| hintText  | string          | Hint text.|
| inputType  | number          | Type of the input text.|
| inspectorKey  | string          | Inspector key.|
| isActive  | boolean          | Whether the element is active.|
| isEnable  | boolean          | Whether the element is enabled.|
| isHint  | boolean          | Whether the element is in the hint state.|
| isFocused  | boolean          | Whether the element is focused.|
| isPassword  | boolean          | Whether the element is a password.|
| isVisible  | boolean          | Whether elements are visible.|
| itemCount  | number          | Total number of items.|
| lastContent  | string          | Last content.|
| layer  | number          | Display layer of the element.|
| longClickable  | boolean          | Whether the element can be long pressed.|
| pageId  | number          | Page ID.|
| parent  | AccessibilityElement          | Parent element of the element.|
| pluralLineSupported  | boolean          | Whether the element supports multiple lines of text.|
| rect  | Rect          | Area of the element.|
| resourceName  | string          | Resource name of the element.|
| rootElement  | AccessibilityElement          | Root element of the window element.|
| screenRect  | Rect          | Display area of the element.|
| scrollable  | boolean          | Whether the element is scrollable.|
| selected  | boolean          | Whether the element is selected.|
| startIndex  | number          | Index of the first list item on the screen.|
| text  | string          | Text of the element.|
| textLengthLimit  | string          | Maximum text length of the element.|
| textMoveUnit  | accessibility.TextMoveUnit          | Unit of movement when the text is read.|
| triggerAction  | accessibility.Action          | Action that triggers the element event.|
| type  | WindowType          | Window type of the element.|
| valueMax  | number          | Maximum value.|
| valueMin  | number          | Minimum value.|
| valueNow  | number          | Current value.|
| windowId  | number          | Window ID.|



## FocusDirection

Enumerates the focus directions.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name      | Description     |
| -------- | ------- |
| up       | Search for the next focusable item above the current item in focus.|
| down     | Search for the next focusable item below the current item in focus.|
| left     | Search for the next focusable item on the left of the current item in focus.|
| right    | Search for the next focusable item on the right of the current item in focus.|
| forward  | Search for the next focusable item before the current item in focus.|
| backward | Search for the next focusable item after the current item in focus.|

## FocusType

Enumerates the focus types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name           | Description         |
| ------------- | ----------- |
| accessibility | Accessibility focus.|
| normal        | Normal focus. |

## Rect

Defines a rectangle.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name    | Type    | Readable  | Writable  | Description       |
| ------ | ------ | ---- | ---- | --------- |
| left   | number | Yes   | No   | Left boundary of the rectangle.|
| top    | number | Yes   | No   | Top boundary of the rectangle.|
| width  | number | Yes   | No   | Width of the rectangle. |
| height | number | Yes   | No   | Height of the rectangle. |

## WindowType

Enumerates the window types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name         | Description       |
| ----------- | --------- |
| application | Application window.|
| system      | System window.|

## AccessibilityExtensionContext.setTargetBundleName

setTargetBundleName(targetNames: Array\<string>): Promise\<void>;

Sets the concerned target bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                 | Mandatory  | Description      |
| ----------- | ------------------- | ---- | -------- |
| targetNames | Array&lt;string&gt; | Yes   | Name of the target bundle.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let targetNames = ['com.ohos.xyz'];
axContext.setTargetBundleName(targetNames).then(() => {
  console.info(`Succeeded in set target bundle names, targetNames is ${targetNames}`);
}).catch((err: BusinessError) => {
  console.error(`failed to set target bundle names, Code is ${err.code}, message is ${err.message}`);
})
```

## AccessibilityExtensionContext.setTargetBundleName

setTargetBundleName(targetNames: Array\<string>, callback: AsyncCallback\<void>): void;

Sets the concerned target bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                       | Mandatory  | Description                                      |
| ----------- | ------------------------- | ---- | ---------------------------------------- |
| targetNames | Array&lt;string&gt;       | Yes   | Name of the target bundle.                                |
| callback    | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation fails, **err** that contains data is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let targetNames = ['com.ohos.xyz'];
axContext.setTargetBundleName(targetNames, (err: BusinessError) => {
  if (err) {
    console.error(`failed to set target bundle names, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in set target bundle names, targetNames is ${targetNames}`);
});
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;

Obtains the focus element. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name                 | Type     | Mandatory  | Description                 |
| -------------------- | ------- | ---- | ------------------- |
| isAccessibilityFocus | boolean | No   | Whether the obtained focus element is an accessibility focus. The value **True** means that the obtained focus element is an accessibility focus, and **False** means the opposite. The default value is **False**.|

**Return value**
| Type                                 | Description                    |
| ----------------------------------- | ---------------------- |
| Promise&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Promise used to return the current focus element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

axContext.getFocusElement().then((data: AccessibilityElement) => {
  console.log(`Succeeded in get focus element,${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get focus element, Code is ${err.code}, message is ${err.message}`);
})
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the focus element. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the current focus element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

axContext.getFocusElement((err: BusinessError, data: AccessibilityElement) => {
  if (err) {
    console.error(`failed to get focus element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get focus element, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(isAccessibilityFocus: boolean, callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the focus element. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name                 | Type                                      | Mandatory  | Description               |
| -------------------- | ---------------------------------------- | ---- | ----------------- |
| isAccessibilityFocus | boolean                                  | Yes   | Whether the obtained focus element is an accessibility focus.   |
| callback             | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the current focus element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let isAccessibilityFocus = true;

axContext.getFocusElement(isAccessibilityFocus, (err: BusinessError, data: AccessibilityElement)=> {
  if (err) {
    console.error(`failed to get focus element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get focus element, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>;

Obtains the root element of a window. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                    |
| -------- | ------ | ---- | ---------------------- |
| windowId | number | No   | Window for which you want to obtain the root element. If this parameter is not specified, it indicates the current active window.|

**Return value**

| Type                                 | Description                    |
| ----------------------------------- | ---------------------- |
| Promise&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Promise used to return the root element of the specified window.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

axContext.getWindowRootElement().then((data: AccessibilityElement) => {
  console.log(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get root element of the window, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the root element of a window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                |
| -------- | ---------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the root element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

axContext.getWindowRootElement((err: BusinessError, data: AccessibilityElement) => {
  if (err) {
    console.error(`failed to get root element of the window, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(windowId: number, callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the root element of a window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                    |
| -------- | ---------------------------------------- | ---- | ---------------------- |
| windowId | number                                   | Yes   | Window for which you want to obtain the root element. If this parameter is not specified, it indicates the current active window.|
| callback | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the root element.    |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let windowId = 10;

axContext.getWindowRootElement(windowId, (err: BusinessError, data: AccessibilityElement) => {
  if (err) {
    console.error(`failed to get root element of the window, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindows

getWindows(displayId?: number): Promise\<Array\<AccessibilityElement>>;

Obtains the list of windows on a display. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type    | Mandatory  | Description                   |
| --------- | ------ | ---- | --------------------- |
| displayId | number | No   | ID of the display from which the window information is obtained. If this parameter is not specified, it indicates the default main display.|

**Return value**

| Type                                      | Description                    |
| ---------------------------------------- | ---------------------- |
| Promise&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Promise used to return the window list.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

axContext.getWindows().then((data: AccessibilityElement[]) => {
  console.log(`Succeeded in get windows, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get windows, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getWindows

getWindows(callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

Obtains the list of windows on this display. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Yes   | Callback used to return the window list.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

axContext.getWindows((err: BusinessError, data: AccessibilityElement[]) => {
  if (err) {
    console.error(`failed to get windows, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get windows, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindows

getWindows(displayId: number, callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

Obtains the list of windows on a display. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                   |
| --------- | ---------------------------------------- | ---- | --------------------- |
| displayId | number                                   | Yes   | ID of the display from which the window information is obtained. If this parameter is not specified, it indicates the default main display.|
| callback  | AsyncCallback&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Yes   | Callback used to return the window list.    |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let displayId = 10;
axContext.getWindows(displayId, (err: BusinessError, data: AccessibilityElement[]) => {
  if (err) {
    console.error(`failed to get windows, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get windows, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.injectGesture<sup>(deprecated)</sup>

injectGesture(gesturePath: GesturePath): Promise\<void>;

> **NOTE**
>
> This API is deprecated since API version 10.
>
> You are advised to use [injectGestureSync<sup>10+</sup>](#accessibilityextensioncontextinjectgesturesync10) instead.

Injects a gesture. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                      | Mandatory  | Description        |
| ----------- | ---------------------------------------- | ---- | ---------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | Yes   | Path of the gesture to inject.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import GesturePath from '@ohos.accessibility.GesturePath';
import GesturePoint from '@ohos.accessibility.GesturePoint';
import { BusinessError } from '@ohos.base';

let gesturePath: GesturePath.GesturePath = new GesturePath.GesturePath(100);

for (let i = 0; i < 10; i++) {
  let gesturePoint = new GesturePoint.GesturePoint(100, i * 200);
  gesturePath.points.push(gesturePoint);
}
axContext.injectGesture(gesturePath).then(() => {
  console.info(`Succeeded in inject gesture,gesturePath is ${gesturePath}`);
}).catch((err: BusinessError) => {
  console.error(`failed to inject gesture, Code is ${err.code}, message is ${err.message}`);
});
```
## AccessibilityExtensionContext.injectGesture<sup>(deprecated)</sup>

injectGesture(gesturePath: GesturePath, callback: AsyncCallback\<void>): void

> **NOTE**
>
> This API is deprecated since API version 10.
>
> You are advised to use [injectGestureSync<sup>10+</sup>](#accessibilityextensioncontextinjectgesturesync10) instead.

Injects a gesture. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                      | Mandatory  | Description                 |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | Yes   | Path of the gesture to inject.         |
| callback    | AsyncCallback&lt;void&gt;                | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import GesturePath from '@ohos.accessibility.GesturePath';
import GesturePoint from '@ohos.accessibility.GesturePoint';
import { BusinessError } from '@ohos.base';

let gesturePath: GesturePath.GesturePath = new GesturePath.GesturePath(100);
for (let i = 0; i < 10; i++) {
  let gesturePoint = new GesturePoint.GesturePoint(100, i * 200);
  gesturePath.points.push(gesturePoint);
}
axContext.injectGesture(gesturePath, (err: BusinessError) => {
  if (err) {
    console.error(`failed to inject gesture, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in inject gesture,gesturePath is ${gesturePath}`);
});
```
## AccessibilityExtensionContext.injectGestureSync<sup>10+</sup>

injectGestureSync(gesturePath: GesturePath): void

Injects a gesture.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                                        | Mandatory| Description                |
| ----------- | ------------------------------------------------------------ | ---- | -------------------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | Yes  | Path of the gesture to inject.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID| Error Message                                           |
| -------- | --------------------------------------------------- |
| 9300003  | Do not have accessibility right for this operation. |

**Example**

```ts
import GesturePath from '@ohos.accessibility.GesturePath';
import GesturePoint from '@ohos.accessibility.GesturePoint';

let gesturePath: GesturePath.GesturePath = new GesturePath.GesturePath(100);
for (let i = 0; i < 10; i++) {
  let gesturePoint = new GesturePoint.GesturePoint(100, i * 200);
  gesturePath.points.push(gesturePoint);
}
axContext.injectGestureSync(gesturePath);
```

## AccessibilityElement<sup>9+</sup>

Defines the **AccessibilityElement**. Before calling APIs of **AccessibilityElement**, you must call [AccessibilityExtensionContext.getFocusElement()](#accessibilityextensioncontextgetfocuselement) or [AccessibilityExtensionContext.getWindowRootElement()](#accessibilityextensioncontextgetwindowrootelement) to obtain an **AccessibilityElement** instance.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### attributeNames

attributeNames\<T extends keyof ElementAttributeValues>() : Promise\<Array\<T>>;

Obtains all attribute names of this element. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                           | Description                      |
| ----------------------------- | ------------------------ |
| Promise&lt;Array&lt;T&gt;&gt; | Promise used to return all attribute names of the element.|

**Example**

```ts
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.attributeNames().then((data: ElementAttributeKeys[]) => {
  console.log(`Succeeded in get attribute names, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.log(`failed to get attribute names, Code is ${err.code}, message is ${err.message}`);
});
```

### attributeNames

attributeNames\<T extends keyof ElementAttributeValues>(callback: AsyncCallback\<Array\<T>>): void;

Obtains all attribute names of this element. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description                 |
| -------- | ----------------------------------- | ---- | ------------------- |
| callback | AsyncCallback&lt;Array&lt;T&gt;&gt; | Yes   | Callback used to return all attribute names of the element.|

**Example**

```ts
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.attributeNames((err: BusinessError, data: ElementAttributeKeys[]) => {
  if (err) {
    console.error(`failed to get attribute names, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get attribute names, ${JSON.stringify(data)}`);
});
```

### attributeValue

attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T): Promise\<ElementAttributeValues[T]>;

Obtains the attribute value based on an attribute name. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core


**Parameters**

| Name          | Type  | Mandatory  | Description      |
| ------------- | ---- | ---- | -------- |
| attributeName | ElementAttributeKeys  | Yes   | Attribute name.|

**Return value**

| Type                                      | Description                         |
| ---------------------------------------- | --------------------------- |
| Promise&lt;ElementAttributeValues[T]&gt; | Promise used to return the attribute value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 9300004 | This property does not exist. |


**Example**

```ts
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let attributeName: ElementAttributeKeys = 'bundleName';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.attributeValue(attributeName).then((data: string) => {
  console.log(`Succeeded in get attribute value by name, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get attribute value, Code is ${err.code}, message is ${err.message}`);
});
```

### attributeValue

attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T, 
    callback: AsyncCallback\<ElementAttributeValues[T]>): void;

Obtains the attribute value based on an attribute name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name          | Type                                      | Mandatory  | Description                    |
| ------------- | ---------------------------------------- | ---- | ---------------------- |
| attributeName | ElementAttributeKeys                         | Yes   | Attribute name.              |
| callback      | AsyncCallback&lt;ElementAttributeValues[T]&gt; | Yes   | Callback used to return the attribute value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 9300004 | This property does not exist. |

**Example**

```ts
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let attributeName: ElementAttributeKeys = 'bundleName';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.attributeValue(attributeName, (err: BusinessError, data: string) => {
  if (err) {
    console.error(`failed to get attribute value, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get attribute value, ${JSON.stringify(data)}`);
});
```

### actionNames

actionNames(): Promise\<Array\<string>>;

Obtains the names of all actions supported by this element. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                                | Description                        |
| ---------------------------------- | -------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the names of all actions supported by the element.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.actionNames().then((data: string[]) => {
  console.log(`Succeeded in get action names, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get action names, Code is ${err.code}, message is ${err.message}`);
})
```

### actionNames

actionNames(callback: AsyncCallback\<Array\<string>>): void;

Obtains the names of all actions supported by this element. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                   |
| -------- | ---------------------------------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the names of all actions supported by the element.|

**Example**

```ts
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.actionNames((err: BusinessError, data: string[]) => {
  if (err) {
    console.error(`failed to get action names, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get action names, ${JSON.stringify(data)}`);
})
```

### performAction

performAction(actionName: string, parameters?: object): Promise\<void>;

Performs an action based on the specified action name. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description            |
| ----------- | ---------------------------------------- | ---- | -------------- |
| actionName | string | Yes   | Action name. For details, see [Action](./js-apis-accessibility.md#action).
| parameters | object | No   | Parameters required for performing the target action. Empty by default. Not supported currently.    |

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 9300005 | This action is not supported. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let actionName = 'action';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.performAction(actionName).then(() => {
  console.info(`Succeeded in perform action,actionName is ${actionName}`);
}).catch((err: BusinessError) => {
  console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
});
```

### performAction

performAction(actionName: string, callback: AsyncCallback\<void>): void;

Performs an action based on the specified action name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description            |
| ----------- | ---------------------------------------- | ---- | -------------- |
| actionName | string | Yes   | Action name. For details, see [Action](./js-apis-accessibility.md#action).
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 9300005 | This action is not supported. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let actionName = 'action';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.performAction(actionName, (err: BusinessError) => {
  if (err) {
    console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in perform action, actionName is ${actionName}`);
});
```

### performAction

performAction(actionName: string, parameters: object, callback: AsyncCallback\<void>): void;

Performs an action based on the specified action name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                      |
| ---------- | ------------------------- | ---- | ---------------------------------------- |
| actionName | string                    | Yes   | Action name. For details, see [Action](./js-apis-accessibility.md#action).|
| parameters | object                    | Yes   | Parameters required for performing the target action. Empty by default. Not supported currently.                 |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.                       |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 9300005 | This action is not supported. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let actionName = 'action';
let parameters: object = [];
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.performAction(actionName, parameters, (err: BusinessError) => {
  if (err) {
    console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in perform action,actionName is ${actionName}, parameters is ${parameters}`);
});
```

### findElement('content')

findElement(type: 'content', condition: string): Promise\<Array\<AccessibilityElement>>;

Finds an element based on the content type. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type    | Mandatory  | Description                           |
| --------- | ------ | ---- | ----------------------------- |
| type      | string | Yes   | Type of element finding. The value is fixed at **'content'**.|
| condition | string | Yes   | Search criteria.                     |

**Return value**

| Type                                      | Description                           |
| ---------------------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let condition = 'keyword';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.findElement('content', condition).then((data: AccessibilityElement[]) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('content')

findElement(type: 'content', condition: string, callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

Finds an element based on the content type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                          |
| --------- | ---------------------------------------- | ---- | ---------------------------- |
| type      | string                                   | Yes   | Type of element finding. The value is fixed at **'content'**.|
| condition | string                                   | Yes   | Search criteria.                    |
| callback  | AsyncCallback&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Yes   | Callback used to return the result.    |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let condition = 'keyword';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.findElement('content', condition, (err: BusinessError, data: AccessibilityElement[])=>{
  if (err) {
    console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in find element, ${JSON.stringify(data)}`);
});
```

### findElement('focusType')

findElement(type: 'focusType', condition: FocusType): Promise\<AccessibilityElement>;

Finds an element based on the focus type. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                     | Mandatory  | Description                                |
| --------- | ----------------------- | ---- | ---------------------------------- |
| type      | string                  | Yes   | Type of element finding. The value is fixed at **'focusType'**.|
| condition | [FocusType](#focustype) | Yes   | Focus type.                      |

**Return value**

| Type                                 | Description                            |
| ----------------------------------- | ------------------------------ |
| Promise&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Promise used to return the result.|

**Example**

```ts
import { FocusType } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let condition: FocusType = 'normal';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.findElement('focusType', condition).then((data: AccessibilityElement) => {
  console.log(`Succeeded in find element,${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('focusType')

findElement(type: 'focusType', condition: FocusType, callback: AsyncCallback\<AccessibilityElement>): void;

Finds an element based on the focus type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                                |
| --------- | ---------------------------------------- | ---- | ---------------------------------- |
| type      | string                                   | Yes   | Type of element finding. The value is fixed at **'focusType'**.|
| condition | [FocusType](#focustype)                  | Yes   | Focus type.                      |
| callback  | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the result.         |

**Example**

```ts
import { FocusType } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let condition: FocusType = 'normal';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.findElement('focusType', condition, (err: BusinessError, data: AccessibilityElement)=>{
  if (err) {
    console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in find element, ${JSON.stringify(data)}`);
});
```

### findElement('focusDirection')

findElement(type: 'focusDirection', condition: FocusDirection): Promise\<AccessibilityElement>;

Finds an element based on the focus direction. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                               | Mandatory  | Description                                      |
| --------- | --------------------------------- | ---- | ---------------------------------------- |
| type      | string                            | Yes   | Type of element finding. The value is fixed at **'focusDirection'**.|
| condition | [FocusDirection](#focusdirection) | Yes   | Focus direction.                          |

**Return value**

| Type                                 | Description                              |
| ----------------------------------- | -------------------------------- |
| Promise&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Promise used to return the result.|

**Example**

```ts
import { FocusDirection } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let condition: FocusDirection = 'up';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.findElement('focusDirection', condition).then((data: AccessibilityElement) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('focusDirection')

findElement(type: 'focusDirection', condition: FocusDirection, callback: AsyncCallback\<AccessibilityElement>): void;

Finds an element based on the focus direction. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                                      |
| --------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type      | string                                   | Yes   | Type of element finding. The value is fixed at **'focusDirection'**.|
| condition | [FocusDirection](#focusdirection)        | Yes   | Direction of the next focus element.                          |
| callback  | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the result.             |

**Example**

```ts
import { FocusDirection } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let condition: FocusDirection = 'up';
let rootElement:AccessibilityElement;// rootElement is an AccessibilityElement instance.

rootElement.findElement('focusDirection', condition, (err: BusinessError, data: AccessibilityElement) =>{
  if (err) {
    console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in find element, ${JSON.stringify(data)}`);
});
```
