# AccessibilityExtensionContext (Accessibility Extension Context)

The **AccessibilityExtensionContext** module, inherited from **ExtensionContext**, provides context for **AccessibilityExtensionAbility**.

You can use the APIs of this module to configure the concerned information, obtain root information, and inject gestures.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Usage

Before using the **AccessibilityExtensionContext** module, you must define a child class that inherits from **AccessibilityExtensionAbility**.

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let axContext = this.context; 
  } 
}
```

## ElementAttributeValues

Provides attribute names and value types of a node element.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Name

| Name                  | Type                                                                | Readable | Writable | Description                 |
|----------------------|--------------------------------------------------------------------|-----|-----| ------------------- |
| accessibilityFocused | boolean                                                            | Yes  | No  |   Accessibility focus status.  |
| accessibilityText<sup>12+</sup> | string                                                  | Yes  | No  | Accessibility text information of an element.|
| bundleName           | string                                                             | Yes  | No  | Bundle name.|
| checkable            | boolean                                                            | Yes  | No  | Whether the element is checkable.|
| checked              | boolean                                                            | Yes  | No  | Whether the element is checked.|
| children             | Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;        | Yes  | No  | All child elements.|
| clickable            | boolean                                                            | Yes  | No  | Whether the element is clickable.|
| componentId          | number                                                             | Yes  | No  | ID of the component to which the element belongs.|
| componentType        | string                                                             | Yes  | No  | Type of the component to which the element belongs.|
| contents             | Array&lt;string&gt;                                                | Yes  | No  | Content.|
| currentIndex         | number                                                             | Yes  | No  | Index of the current item.|
| description          | string                                                             | Yes  | No  | Description of the element.|
| editable             | boolean                                                            | Yes  | No  | Whether the element is editable.|
| endIndex             | number                                                             | Yes  | No  | Index of the last list item displayed on the screen.|
| error                | string                                                             | Yes  | No  | Error status.|
| focusable            | boolean                                                            | Yes  | No  | Whether the element is focusable.|
| hintText             | string                                                             | Yes  | No  | Hint text.|
| inputType            | number                                                             | Yes  | No  | Type of the input text.|
| inspectorKey         | string                                                             | Yes  | No  | Inspector key.|
| isActive             | boolean                                                            | Yes  | No  | Whether the element is active.|
| isEnable             | boolean                                                            | Yes  | No  | Whether the element is enabled.|
| isHint               | boolean                                                            | Yes  | No  | Whether the element is in the hint state.|
| isFocused            | boolean                                                            | Yes  | No  | Whether the element is focused.|
| isPassword           | boolean                                                            | Yes  | No  | Whether the element is a password.|
| isVisible            | boolean                                                            | Yes  | No  | Whether the element is visible.|
| itemCount            | number                                                             | Yes  | No  | Total number of items.|
| lastContent          | string                                                             | Yes  | No  | Last content.|
| layer                | number                                                             | Yes  | No  | Display layer of the element.|
| longClickable        | boolean                                                            | Yes  | No  | Whether the element is long-clickable.|
| pageId               | number                                                             | Yes  | No  | Page ID.|
| parent               | [AccessibilityElement](#accessibilityelement9)                     | Yes  | No  | Parent element of the element.|
| pluralLineSupported  | boolean                                                            | Yes  | No  | Whether the element supports multiple lines of text.|
| rect                 | [Rect](#rect)                                                      | Yes  | No  | Area of the element.|
| resourceName         | string                                                             | Yes  | No  | Resource name of the element.|
| rootElement          | [AccessibilityElement](#accessibilityelement9)                     | Yes  | No  | Root element of the window element.|
| screenRect           | [Rect](#rect)                                                      | Yes  | No  | Display area of the element.|
| scrollable           | boolean                                                            | Yes  | No  | Whether the element is scrollable.|
| selected             | boolean                                                            | Yes  | No  | Whether the element is selected.|
| startIndex           | number                                                             | Yes  | No  | Index of the first list item on the screen.|
| text                 | string                                                             | Yes  | No  | Text of the element.|
| textLengthLimit      | number                                                             | Yes  | No  | Maximum text length of the element.|
| textMoveUnit         | [accessibility.TextMoveUnit](js-apis-accessibility.md#textmoveunit) | Yes  | No  | Unit of movement when the text is read.|
| triggerAction        | [accessibility.Action](js-apis-accessibility.md#action)         | Yes  | No  | Action that triggers the element event.|
| type                 | [WindowType](#windowtype)                                          | Yes  | No  | Window type of the element.|
| valueMax             | number                                                             | Yes  | No  | Maximum value.|
| valueMin             | number                                                             | Yes  | No  | Minimum value.|
| valueNow             | number                                                             | Yes  | No  | Current value.|
| windowId             | number                                                             | Yes  | No  | Window ID.|
| textType<sup>12+</sup>             | string                                                             | Yes  | No  | Accessibility text type of an element, which is configured by the **accessibilityTextHint** attribute of the component.|
| offset<sup>12+</sup>             | number                                                             | Yes  | No  | Pixel offset of the content area relative to the top coordinate of a scrollable component, such as **List** and **Grid**.|
| hotArea<sup>12+</sup>             | [Rect](#rect)                                                              | Yes  | No  | Touchable area of an element.|
| customComponentType<sup>16+</sup>             | string                                                             | Yes  | No  | Custom component type.|
| accessibilityNextFocusId<sup>16+</sup>             | number                                                             | Yes  | No  | ID of the next component to be focused on.|
| extraInfo<sup>16+</sup>             | string                                                             | Yes  | No  | Extended attribute, which is used to define the attributes that are available only to specific components.|

## FocusDirection

type FocusDirection = 'up' | 'down' | 'left' | 'right' | 'forward' | 'backward'

Enumerates the focus directions.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type      | Description     |
| -------- | ------- |
| 'up'       | Search for the next focusable item above the current item in focus.|
| 'down'     | Search for the next focusable item below the current item in focus.|
| 'left'     | Search for the next focusable item on the left of the current item in focus.|
| 'right'    | Search for the next focusable item on the right of the current item in focus.|
| 'forward'  | Search for the next focusable item before the current item in focus.|
| 'backward' | Search for the next focusable item after the current item in focus.|

## FocusType

type FocusType = 'accessibility' | 'normal'

Enumerates the focus types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type           | Description         |
| ------------- | ----------- |
| 'accessibility' | Accessibility focus.|
| 'normal'        | Normal focus. |

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

type WindowType = 'application' | 'system'

Enumerates the window types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type         | Description       |
| ----------- | --------- |
| 'application' | Application window.|
| 'system'      | System window.|

## AccessibilityExtensionContext.setTargetBundleName<sup>(deprecated)</sup>

setTargetBundleName(targetNames: Array\<string>): Promise\<void>;

Sets the concerned target bundle. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                 | Mandatory  | Description      |
| ----------- | ------------------- | ---- | -------- |
| targetNames | Array&lt;string&gt; | Yes   | Bundle name of the concerned target application. The service receives accessibility events of the concerned application. By default, accessibility events of all applications are received. Pass in an empty array if there is no concerned application.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let targetNames = ['com.ohos.xyz'];
axContext.setTargetBundleName(targetNames).then(() => {
  console.info(`Succeeded in set target bundle names, targetNames is ${targetNames}`);
}).catch((err: BusinessError) => {
  console.error(`failed to set target bundle names, Code is ${err.code}, message is ${err.message}`);
})
```

## AccessibilityExtensionContext.setTargetBundleName<sup>(deprecated)</sup>

setTargetBundleName(targetNames: Array\<string>, callback: AsyncCallback\<void>): void;

Sets the concerned target bundle. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                       | Mandatory  | Description                                      |
| ----------- | ------------------------- | ---- | ---------------------------------------- |
| targetNames | Array&lt;string&gt;       | Yes   | Bundle name of the concerned target application. The service receives accessibility events of the concerned application. By default, accessibility events of all applications are received. Pass in an empty array if there is no concerned application.                                |
| callback    | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation fails, **err** that contains data is returned.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let targetNames = ['com.ohos.xyz'];
try {
  axContext.setTargetBundleName(targetNames, (err: BusinessError) => {
    if (err && err.code) {
      console.error(`failed to set target bundle names, Code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`Succeeded in set target bundle names, targetNames is ${targetNames}`);
  });
} catch (error) {
  console.error(`failed to set target bundle names, Because ${JSON.stringify(error)}`);
}
```

## AccessibilityExtensionContext.getFocusElement<sup>(deprecated)</sup>

getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;

Obtains the focus element. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

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

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getFocusElement().then((data: AccessibilityElement) => {
  rootElement = data;
  console.log(`Succeeded in get focus element,${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get focus element, Code is ${err.code}, message is ${err.message}`);
})
```

## AccessibilityExtensionContext.getFocusElement<sup>(deprecated)</sup>

getFocusElement(callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the focus element. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the current focus element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getFocusElement((err: BusinessError, data: AccessibilityElement) => {
  if (err && err.code) {
    console.error(`failed to get focus element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  rootElement = data;
  console.info(`Succeeded in get focus element, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getFocusElement<sup>(deprecated)</sup>

getFocusElement(isAccessibilityFocus: boolean, callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the focus element. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name                 | Type                                      | Mandatory  | Description               |
| -------------------- | ---------------------------------------- | ---- | ----------------- |
| isAccessibilityFocus | boolean                                  | Yes   | Whether the obtained focus element is an accessibility focus. The value **True** means that the obtained focus element is an accessibility focus, and **False** means the opposite.   |
| callback             | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the current focus element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let isAccessibilityFocus = true;
let rootElement: AccessibilityElement;

axContext.getFocusElement(isAccessibilityFocus, (err: BusinessError, data: AccessibilityElement)=> {
  if (err && err.code) {
    console.error(`failed to get focus element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  rootElement = data;
  console.info(`Succeeded in get focus element, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindowRootElement<sup>(deprecated)</sup>

getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>;

Obtains the root element of a window. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

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

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getWindowRootElement().then((data: AccessibilityElement) => {
  rootElement = data;
  console.log(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get root element of the window, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getWindowRootElement<sup>(deprecated)</sup>

getWindowRootElement(callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the root element of a window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                |
| -------- | ---------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the root element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getWindowRootElement((err: BusinessError, data: AccessibilityElement) => {
  if (err && err.code) {
    console.error(`failed to get root element of the window, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  rootElement = data;
  console.info(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindowRootElement<sup>(deprecated)</sup>

getWindowRootElement(windowId: number, callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the root element of a window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                    |
| -------- | ---------------------------------------- | ---- | ---------------------- |
| windowId | number                                   | Yes   | Window for which you want to obtain the root element. If this parameter is not specified, it indicates the current active window.|
| callback | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the root element.    |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId = 10;
let rootElement: AccessibilityElement;

axContext.getWindowRootElement(windowId, (err: BusinessError, data: AccessibilityElement) => {
  if (err && err.code) {
    console.error(`failed to get root element of the window, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  rootElement = data;
  console.info(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindows<sup>(deprecated)</sup>

getWindows(displayId?: number): Promise\<Array\<AccessibilityElement>>;

Obtains the list of windows on a display. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

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

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getWindows().then((data: AccessibilityElement[]) => {
  console.log(`Succeeded in get windows, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get windows, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getWindows<sup>(deprecated)</sup>

getWindows(callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

Obtains the list of windows on a display. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Yes   | Callback used to return the window list.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getWindows((err: BusinessError, data: AccessibilityElement[]) => {
  if (err && err.code) {
    console.error(`failed to get windows, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get windows, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindows<sup>(deprecated)</sup>

getWindows(displayId: number, callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

Obtains the list of windows on a display. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                   |
| --------- | ---------------------------------------- | ---- | --------------------- |
| displayId | number                                   | Yes   | ID of the display from which the window information is obtained. If this parameter is not specified, it indicates the default main display.|
| callback  | AsyncCallback&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Yes   | Callback used to return the window list.    |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let displayId = 10;
axContext.getWindows(displayId, (err: BusinessError, data: AccessibilityElement[]) => {
  if (err && err.code) {
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

Injects a gesture. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                                                | Mandatory  | Description        |
| ----------- |--------------------------------------------------------------------| ---- | ---------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | Yes   | Path of the gesture to inject.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { GesturePath, GesturePoint } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let gesturePath: GesturePath = new GesturePath(100);

for (let i = 0; i < 10; i++) {
  let gesturePoint = new GesturePoint(100, i * 200);
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

Injects a gesture. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                                                | Mandatory  | Description                 |
| ----------- |--------------------------------------------------------------------| ---- | ------------------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | Yes   | Path of the gesture to inject.         |
| callback    | AsyncCallback&lt;void&gt;                                          | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**Example**

```ts
import { GesturePath, GesturePoint } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let gesturePath: GesturePath = new GesturePath(100);
for (let i = 0; i < 10; i++) {
  let gesturePoint = new GesturePoint(100, i * 200);
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
## AccessibilityExtensionContext.injectGestureSync<sup>(deprecated)</sup>

injectGestureSync(gesturePath: GesturePath): void

Injects a gesture.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                                                | Mandatory| Description                |
| ----------- |--------------------------------------------------------------------| ---- | -------------------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | Yes  | Path of the gesture to inject.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message                                           |
| -------- | --------------------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003  | No accessibility permission to perform the operation. |

**Example**

```ts
import { GesturePath, GesturePoint } from '@kit.AccessibilityKit';

let gesturePath: GesturePath = new GesturePath(100);
for (let i = 0; i < 10; i++) {
  let gesturePoint = new GesturePoint(100, i * 200);
  gesturePath.points.push(gesturePoint);
}
axContext.injectGestureSync(gesturePath);
```

## AccessibilityElement<sup>9+</sup>

Defines the **AccessibilityElement**. Before calling APIs of **AccessibilityElement**, you must call [AccessibilityExtensionContext.getFocusElement()](#accessibilityextensioncontextgetfocuselementdeprecated) or [AccessibilityExtensionContext.getWindowRootElement()](#accessibilityextensioncontextgetwindowrootelementdeprecated) to obtain an **AccessibilityElement** instance.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### attributeNames<sup>(deprecated)</sup>

attributeNames\<T extends keyof ElementAttributeValues>() : Promise\<Array\<T>>;

Obtains all attribute names of this element. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                           | Description                      |
| ----------------------------- | ------------------------ |
| Promise&lt;Array&lt;T&gt;&gt; | Promise used to return all attribute names of the element.|

**Example**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
rootElement.attributeNames().then((data: ElementAttributeKeys[]) => {
  console.log(`Succeeded in get attribute names, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.log(`failed to get attribute names, Code is ${err.code}, message is ${err.message}`);
});
```

### attributeNames<sup>(deprecated)</sup>

attributeNames\<T extends keyof ElementAttributeValues>(callback: AsyncCallback\<Array\<T>>): void;

Obtains all attribute names of this element. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description                 |
| -------- | ----------------------------------- | ---- | ------------------- |
| callback | AsyncCallback&lt;Array&lt;T&gt;&gt; | Yes   | Callback used to return all attribute names of the element.|

**Example**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
rootElement.attributeNames((err: BusinessError, data: ElementAttributeKeys[]) => {
  if (err && err.code) {
    console.error(`failed to get attribute names, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get attribute names, ${JSON.stringify(data)}`);
});
```

### attributeValue<sup>(deprecated)</sup>

attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T): Promise\<ElementAttributeValues[T]>;

Obtains the attribute value based on an attribute name. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

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

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300004 | This property does not exist. |


**Example**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let attributeName: ElementAttributeKeys = 'bundleName';

// rootElement is an instance of AccessibilityElement.
rootElement.attributeValue(attributeName).then((data: string) => {
  console.log(`Succeeded in get attribute value by name, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get attribute value, Code is ${err.code}, message is ${err.message}`);
});
```

### attributeValue<sup>(deprecated)</sup>

attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T, 
    callback: AsyncCallback\<ElementAttributeValues[T]>): void;

Obtains the attribute value based on an attribute name. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name          | Type                                      | Mandatory  | Description                    |
| ------------- | ---------------------------------------- | ---- | ---------------------- |
| attributeName | ElementAttributeKeys                         | Yes   | Attribute name.              |
| callback      | AsyncCallback&lt;ElementAttributeValues[T]&gt; | Yes   | Callback used to return the attribute value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300004 | This property does not exist. |

**Example**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let attributeName: ElementAttributeKeys = 'bundleName';

// rootElement is an instance of AccessibilityElement.
rootElement.attributeValue(attributeName, (err: BusinessError, data: string) => {
  if (err && err.code) {
    console.error(`failed to get attribute value, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get attribute value, ${JSON.stringify(data)}`);
});
```

### actionNames<sup>(deprecated)</sup>

actionNames(): Promise\<Array\<string>>;

Obtains the names of all actions supported by this element. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                                | Description                        |
| ---------------------------------- | -------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the names of all actions supported by the element.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
rootElement.actionNames().then((data: string[]) => {
  console.log(`Succeeded in get action names, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get action names, Code is ${err.code}, message is ${err.message}`);
})
```

### actionNames<sup>(deprecated)</sup>

actionNames(callback: AsyncCallback\<Array\<string>>): void;

Obtains the names of all actions supported by this element. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                   |
| -------- | ---------------------------------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the names of all actions supported by the element.|

**Example**

```ts
// rootElement is an instance of AccessibilityElement.
rootElement.actionNames((err: BusinessError, data: string[]) => {
  if (err && err.code) {
    console.error(`failed to get action names, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get action names, ${JSON.stringify(data)}`);
})
```

### performAction<sup>(deprecated)</sup>

performAction(actionName: string, parameters?: object): Promise\<void>;

Performs an action based on the specified action name. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description                                                      |
| ----------- | ---------------------------------------- | ---- |----------------------------------------------------------|
| actionName | string | Yes   | Action name. For details, see [Action](./js-apis-accessibility.md#action). |
| parameters | object | No   | Parameters required for performing the target action. Empty by default.                            |

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300005 | This action is not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let actionName = 'action';

// rootElement is an instance of AccessibilityElement.
rootElement.performAction(actionName).then(() => {
  console.info(`Succeeded in perform action,actionName is ${actionName}`);
}).catch((err: BusinessError) => {
  console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
});
```

**Example of an action without parameters:**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
// An action that does not require any parameter setting is an action without parameters, as specified in the action description.
rootElement.performAction('click').then(() => {
  console.info(`Succeeded in perform action.`);
}).catch((err: BusinessError) => {
  console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
});
```

**Example of an action with parameters:**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
// Sample code of setSelection
rootElement.performAction('setSelection', {
  selectTextBegin: '0', // Indicates the start position of selection.
  selectTextEnd: '8',   // Indicates the end position of selection.
  selectTextInForWard: true   // true indicates the insertion point, and false indicates the selection range.
}).then(() => {
  console.info(`Succeeded in perform action`);
}).catch((err: BusinessError) => {
  console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
});
```

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
// Sample code of setCursorPosition
rootElement.performAction('setCursorPosition', {
  offset: '1'   // Position of the cursor.
}).then(() => {
  console.info(`Succeeded in perform action`);
}).catch((err: BusinessError) => {
  console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
});
```

### performAction<sup>(deprecated)</sup>

performAction(actionName: string, callback: AsyncCallback\<void>): void;

Performs an action based on the specified action name. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description            |
| ----------- | ---------------------------------------- | ---- | -------------- |
| actionName | string | Yes   | Action name. For details, see [Action](./js-apis-accessibility.md#action). |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300005 | This action is not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let actionName = 'action';

// rootElement is an instance of AccessibilityElement.
rootElement.performAction(actionName, (err: BusinessError) => {
  if (err && err.code) {
    console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in perform action, actionName is ${actionName}`);
});
```

### performAction<sup>(deprecated)</sup>

performAction(actionName: string, parameters: object, callback: AsyncCallback\<void>): void;

Performs an action based on the specified action name. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                                         |
| ---------- | ------------------------- | ---- |-------------------------------------------------------------|
| actionName | string                    | Yes   | Action name. For details, see [Action](./js-apis-accessibility.md#action).|
| parameters | object                    | Yes   | Parameters required for performing the target action. Empty by default.                               |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.                                          |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300005 | This action is not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let actionName = 'action';
let parameters: object = [];

// rootElement is an instance of AccessibilityElement.
rootElement.performAction(actionName, parameters, (err: BusinessError) => {
  if (err && err.code) {
    console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in perform action,actionName is ${actionName}, parameters is ${parameters}`);
});
```

### findElement('content')<sup>(deprecated)</sup>

findElement(type: 'content', condition: string): Promise\<Array\<AccessibilityElement>>;

Finds an element based on the content type. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let condition = 'keyword';

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('content', condition).then((data: AccessibilityElement[]) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('content')<sup>(deprecated)</sup>

findElement(type: 'content', condition: string, callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

Finds an element based on the content type. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                          |
| --------- | ---------------------------------------- | ---- | ---------------------------- |
| type      | string                                   | Yes   | Type of element finding. The value is fixed at **'content'**.|
| condition | string                                   | Yes   | Search criteria.                    |
| callback  | AsyncCallback&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Yes   | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let condition = 'keyword';

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('content', condition, (err: BusinessError, data: AccessibilityElement[])=>{
  if (err && err.code) {
    console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in find element, ${JSON.stringify(data)}`);
});
```

### findElement('focusType')<sup>(deprecated)</sup>

findElement(type: 'focusType', condition: FocusType): Promise\<AccessibilityElement>;

Finds an element based on the focus type. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { FocusType } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let condition: FocusType = 'normal';

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('focusType', condition).then((data: AccessibilityElement) => {
  console.log(`Succeeded in find element,${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('focusType')<sup>(deprecated)</sup>

findElement(type: 'focusType', condition: FocusType, callback: AsyncCallback\<AccessibilityElement>): void;

Finds an element based on the focus type. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                                |
| --------- | ---------------------------------------- | ---- | ---------------------------------- |
| type      | string                                   | Yes   | Type of element finding. The value is fixed at **'focusType'**.|
| condition | [FocusType](#focustype)                  | Yes   | Focus type.                      |
| callback  | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the result.         |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { FocusType } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let condition: FocusType = 'normal';

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('focusType', condition, (err: BusinessError, data: AccessibilityElement)=>{
  if (err && err.code) {
    console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in find element, ${JSON.stringify(data)}`);
});
```

### findElement('focusDirection')<sup>(deprecated)</sup>

findElement(type: 'focusDirection', condition: FocusDirection): Promise\<AccessibilityElement>;

Finds an element based on the focus direction. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { FocusDirection } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let condition: FocusDirection = 'up';

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('focusDirection', condition).then((data: AccessibilityElement) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('focusDirection')<sup>(deprecated)</sup>

findElement(type: 'focusDirection', condition: FocusDirection, callback: AsyncCallback\<AccessibilityElement>): void;

Finds an element based on the focus direction. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                                      |
| --------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type      | string                                   | Yes   | Type of element finding. The value is fixed at **'focusDirection'**.|
| condition | [FocusDirection](#focusdirection)        | Yes   | Direction of the next focus element.                          |
| callback  | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Yes   | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { FocusDirection } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let condition: FocusDirection = 'up';

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('focusDirection', condition, (err: BusinessError, data: AccessibilityElement) =>{
  if (err && err.code) {
    console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in find element, ${JSON.stringify(data)}`);
});
```
