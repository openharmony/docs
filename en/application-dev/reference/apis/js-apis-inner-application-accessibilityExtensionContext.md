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
import AccessibilityExtensionAbility, {
  AccessibilityExtensionContext,
} from '@ohos.application.AccessibilityExtensionAbility';

let axContext: AccessibilityExtensionContext;

class EntryAbility extends AccessibilityExtensionAbility {
  axContext = this.context;
}
```

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
let targetNames = ['com.ohos.xyz'];

try {
  axContext.setTargetBundleName(targetNames).then(() => {
    console.info('set target bundle names success');
  }).catch((err: object) => {
    console.error(`failed to set target bundle names, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to set target bundle names, because ${JSON.stringify(exception)}`);
}
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
try {
  axContext.setTargetBundleName(targetNames, (err: BusinessError<void>) => {
    if (err) {
      console.error(`failed to set target bundle names, because ${JSON.stringify(err)}`);
      return;
    }
    console.info('set target bundle names success');
  });
} catch (exception) {
  console.error(`failed to set target bundle names, because ${JSON.stringify(exception)}`);
}
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;

Obtains the focus element. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name                 | Type     | Mandatory  | Description                 |
| -------------------- | ------- | ---- | ------------------- |
| isAccessibilityFocus | boolean | No   | Whether the obtained focus element is an accessibility focus. The default value is **false**.|

**Return value**

| Type                                 | Description                    |
| ----------------------------------- | ---------------------- |
| Promise&lt;AccessibilityElement&gt; | Promise used to return the current focus element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';

let focusElement: AccessibilityElement;
try {
  axContext.getFocusElement().then((data: AccessibilityElement) => {
    focusElement = data;
    console.log('get focus element success');
  }).catch((err: object) => {
    console.error(`failed to get focus element, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to get focus element, because ${JSON.stringify(exception)}`);
}
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the focus element. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;AccessibilityElement&gt; | Yes   | Callback used to return the current focus element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let focusElement: AccessibilityElement;
try {
  axContext.getFocusElement((err: BusinessError<void>, data: AccessibilityElement) => {
    if (err) {
      console.error(`failed to get focus element, because ${JSON.stringify(err)}`);
      return;
    }
    focusElement = data;
    console.info('get focus element success');
  });
} catch (exception) {
  console.error(`failed to get focus element, because ${JSON.stringify(exception)}`);
}
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(isAccessibilityFocus: boolean, callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the focus element. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name                 | Type                                      | Mandatory  | Description               |
| -------------------- | ---------------------------------------- | ---- | ----------------- |
| isAccessibilityFocus | boolean                                  | Yes   | Whether the obtained focus element is an accessibility focus.   |
| callback             | AsyncCallback&lt;AccessibilityElement&gt; | Yes   | Callback used to return the current focus element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let focusElement: AccessibilityElement;
let isAccessibilityFocus = true;

try {
  axContext.getFocusElement(isAccessibilityFocus, (err: BusinessError<void>, data: AccessibilityElement) => {
    if (err) {
      console.error(`failed to get focus element, because ${JSON.stringify(err)}`);
      return;
    }
    focusElement = data;
    console.info('get focus element success');
  });
} catch (exception) {
  console.error(`failed to get focus element, because ${JSON.stringify(exception)}`);
}
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
| Promise&lt;AccessibilityElement&gt; | Promise used to return the root element of the specified window.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';

let rootElement: AccessibilityElement;
try {
  axContext.getWindowRootElement().then((data: AccessibilityElement) => {
    rootElement = data;
    console.log('get root element of the window success');
  }).catch((err: object) => {
    console.error(`failed to get root element of the window, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to get root element of the window, ${JSON.stringify(exception)}`);
}
```

## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the root element of a window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                |
| -------- | ---------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback&lt;AccessibilityElement&gt; | Yes   | Callback used to return the root element.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let rootElement: AccessibilityElement;
try {
  axContext.getWindowRootElement((err: BusinessError<void>
                                  , data: AccessibilityElement) => {
    if (err) {
      console.error(`failed to get root element of the window, because ${JSON.stringify(err)}`);
      return;
    }
    rootElement = data;
    console.info('get root element of the window success');
  });
} catch (exception) {
  console.error(`failed to get root element of the window, because ${JSON.stringify(exception)}`);
}
```

## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(windowId: number, callback: AsyncCallback\<AccessibilityElement>): void;

Obtains the root element of a window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                    |
| -------- | ---------------------------------------- | ---- | ---------------------- |
| windowId | number                                   | Yes   | Window for which you want to obtain the root element. If this parameter is not specified, it indicates the current active window.|
| callback | AsyncCallback&lt;AccessibilityElement&gt; | Yes   | Callback used to return the root element.    |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let rootElement: AccessibilityElement;
let windowId = 10;

try {
  axContext.getWindowRootElement(windowId, (err: BusinessError<void>, data: AccessibilityElement) => {
    if (err) {
      console.error(`failed to get root element of the window, because ${JSON.stringify(err)}`);
      return;
    }
    rootElement = data;
    console.info('get root element of the window success');
  });
} catch (exception) {
  console.error(`failed to get root element of the window, because ${JSON.stringify(exception)}`);
}
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
| Promise&lt;Array&lt;AccessibilityElement&gt;&gt; | Promise used to return the window list.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';

let windows: AccessibilityElement[];
try {
  axContext.getWindows().then((data: AccessibilityElement[]) => {
    windows = data;
    console.log('get windows success');
  }).catch((err: object) => {
    console.error(`failed to get windows, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to get windows, because ${JSON.stringify(exception)}`);
}
```

## AccessibilityExtensionContext.getWindows

getWindows(callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

Obtains the list of windows on this display. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;Array&lt;AccessibilityElement&gt;&gt; | Yes   | Callback used to return the window list.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let windows: AccessibilityElement[];
try {
  axContext.getWindows((err: BusinessError<void>, data: AccessibilityElement[]) => {
    if (err) {
      console.error(`failed to get windows, because ${JSON.stringify(err)}`);
      return;
    }
    windows = data;
    console.info('get windows success');
  });
} catch (exception) {
  console.error(`failed to get windows, because ${JSON.stringify(exception)}`);
}
```

## AccessibilityExtensionContext.getWindows

getWindows(displayId: number, callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

Obtains the list of windows on a display. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                   |
| --------- | ---------------------------------------- | ---- | --------------------- |
| displayId | number                                   | Yes   | ID of the display from which the window information is obtained. If this parameter is not specified, it indicates the default main display.|
| callback  | AsyncCallback&lt;Array&lt;AccessibilityElement&gt;&gt; | Yes   | Callback used to return the window list.    |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let windows: AccessibilityElement[];
let displayId = 10;
try {
  axContext.getWindows(displayId, (err: BusinessError<void>, data: AccessibilityElement[]) => {
    if (err) {
      console.error(`failed to get windows, because ${JSON.stringify(err)}`);
      return;
    }
    windows = data;
    console.info('get windows success');
  });
} catch (exception) {
  console.error(`failed to get windows, because ${JSON.stringify(exception)}`);
}
```

## AccessibilityExtensionContext.injectGesture<sup>(deprecated)</sup>

injectGesture(gesturePath: GesturePath): Promise\<void>;

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

let gesturePath: GesturePath.GesturePath = new GesturePath.GesturePath(100);
try {
  for (let i = 0; i < 10; i++) {
    let gesturePoint = new GesturePoint.GesturePoint(100, i * 200);
    gesturePath.points.push(gesturePoint);
  }
  axContext.injectGesture(gesturePath).then(() => {
    console.info('inject gesture success');
  }).catch((err: object) => {
    console.error(`failed to inject gesture, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to inject gesture, because ${JSON.stringify(exception)}`);
}
```
## AccessibilityExtensionContext.injectGesture<sup>(deprecated)</sup>

injectGesture(gesturePath: GesturePath, callback: AsyncCallback\<void>): void

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

let gesturePath: GesturePath.GesturePath = new GesturePath.GesturePath(100);
try {
  for (let i = 0; i < 10; i++) {
    let gesturePoint = new GesturePoint.GesturePoint(100, i * 200);
    gesturePath.points.push(gesturePoint);
  }
  axContext.injectGesture(gesturePath, (err) => {
    if (err) {
      console.error(`failed to inject gesture, because ${JSON.stringify(err)}`);
      return;
    }
    console.info('inject gesture success');
  });
} catch (exception) {
  console.error(`failed to inject gesture, because ${JSON.stringify(exception)}`);
}
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
try {
  for (let i = 0; i < 10; i++) {
    let gesturePoint = new GesturePoint.GesturePoint(100, i * 200);
    gesturePath.points.push(gesturePoint);
  }
  axContext.injectGestureSync(gesturePath);
} catch (exception) {
  console.error(`failed to inject gesture, because ${JSON.stringify(exception)}`);
}
```

## AccessibilityElement<sup>9+</sup>

Defines the **AccessibilityElement**. Before calling APIs of **AccessibilityElement**, you must call [AccessibilityExtensionContext.getFocusElement()](#accessibilityextensioncontextgetfocuselement) or [AccessibilityExtensionContext.getWindowRootElement()](#accessibilityextensioncontextgetwindowrootelement) to obtain an **AccessibilityElement** instance.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### attributeNames

attributeNames\<T extends keyof ElementAttributeValues>(): Promise\<Array\<T>>;

Obtains all attribute names of this element. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                           | Description                      |
| ----------------------------- | ------------------------ |
| Promise&lt;Array&lt;T&gt;&gt; | Promise used to return all attribute names of the element.|

**Example**

```ts
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';

let attributeNames: ElementAttributeKeys;
rootElement.attributeNames().then((data: ElementAttributeKeys) => {
  console.log('get attribute names success');
  attributeNames = data;
}).catch((err: object) => {
  console.log(`failed to get attribute names, because ${JSON.stringify(err)}`);
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

let attributeNames: ElementAttributeKeys[];
rootElement.attributeNames((err: BusinessError<void>, data: ElementAttributeKeys[]) => {
  if (err) {
    console.error(`failed to get attribute names, because ${JSON.stringify(err)}`);
    return;
  }
  attributeNames = data;
  console.info('get attribute names success');
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

let attributeName: ElementAttributeKeys = 'bundleName';
let attributeValue: string;
try {
  rootElement.attributeValue(attributeName).then((data: string) => {
    console.log('get attribute value by name success');
    attributeValue = data;
  }).catch((err: object) => {
    console.error(`failed to get attribute value, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to get attribute value, because ${JSON.stringify(exception)}`);
}
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
let attributeValue: string;
try {
  rootElement.attributeValue(attributeName, (err: BusinessError<void>, data: string) => {
    if (err) {
      console.error(`failed to get attribute value, because ${JSON.stringify(err)}`);
      return;
    }
    attributeValue = data;
    console.info('get attribute value success');
  });
} catch (exception) {
  console.error(`failed to get attribute value, because ${JSON.stringify(exception)}`);
}
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
let actionNames: string[];
rootElement.actionNames().then((data: string[]) => {
  console.log('get action names success');
  actionNames = data;
}).catch((err: object) => {
  console.error(`failed to get action names because ${JSON.stringify(err)}`);
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
let actionNames: string[];
rootElement.actionNames((err: BusinessError<void>, data: string[]) => {
  if (err) {
    console.error(`failed to get action names, because ${JSON.stringify(err)}`);
    return;
  }
  actionNames = data;
  console.info('get action names success');
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
let actionName = 'action';
try {
  rootElement.performAction(actionName).then(() => {
    console.info('perform action success');
  }).catch((err: object) => {
    console.error(`failed to perform action, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to perform action, because ${JSON.stringify(exception)}`);
}
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
try {
  rootElement.performAction(actionName, (err:BusinessError) => {
    if (err) {
      console.error(`failed to perform action, because ${JSON.stringify(err)}`);
      return;
    }
    console.info('perform action success');
  });
} catch (exception) {
  console.error(`failed to perform action, because ${JSON.stringify(exception)}`);
}
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
try {
  rootElement.performAction(actionName, parameters, (err: BusinessError<void>) => {
    if (err) {
      console.error(`failed to perform action, because ${JSON.stringify(err)}`);
      return;
    }
    console.info('perform action success');
  });
} catch (exception) {
  console.error(`failed to perform action, because ${JSON.stringify(exception)}`);
}
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
| Promise&lt;Array&lt;AccessibilityElement&gt;&gt; | Promise used to return the result.|

**Example**

```ts
let condition = 'keyword';
let elements: AccessibilityElement[];
try {
  rootElement.findElement('content', condition).then((data: AccessibilityElement[]) => {
    elements = data;
    console.log('find element success');
  }).catch((err: object) => {
    console.error(`failed to find element, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to find element, because ${JSON.stringify(exception)}`);
}
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
| callback  | AsyncCallback&lt;Array&lt;AccessibilityElement&gt;&gt; | Yes   | Callback used to return the result.    |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let condition = 'keyword';
let elements: AccessibilityElement[];
try {
  rootElement.findElement('content', condition, (err: BusinessError<void>, data: AccessibilityElement[]) => {
    if (err) {
      console.error(`failed to find element, because ${JSON.stringify(err)}`);
      return;
    }
    elements = data;
    console.info('find element success');
  });
} catch (exception) {
  console.error(`failed to find element, because ${JSON.stringify(exception)}`);
}
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
| Promise&lt;AccessibilityElement&gt; | Promise used to return the result.|

**Example**

```ts
import { FocusType } from '@ohos.application.AccessibilityExtensionAbility';

let condition: FocusType = 'normal';
let element: AccessibilityElement;
try {
  rootElement.findElement('focusType', condition).then((data: AccessibilityElement) => {
    element = data;
    console.log('find element success');
  }).catch((err: object) => {
    console.error(`failed to find element, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to find element, because ${JSON.stringify(exception)}`);
}
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
| callback  | AsyncCallback&lt;AccessibilityElement&gt; | Yes   | Callback used to return the result.         |

**Example**

```ts
import { FocusType } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let condition: FocusType = 'normal';
let element: AccessibilityElement;
try {
  rootElement.findElement('focusType', condition, (err: BusinessError<void>, data: AccessibilityElement) => {
    if (err) {
      console.error(`failed to find element, because ${JSON.stringify(err)}`);
      return;
    }
    element = data;
    console.info('find element success');
  });
} catch (exception) {
  console.error(`failed to find element, because ${JSON.stringify(exception)}`);
}
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
| Promise&lt;AccessibilityElement&gt; | Promise used to return the result.|

**Example**

```ts
import { FocusDirection } from '@ohos.application.AccessibilityExtensionAbility';

let condition: FocusDirection = 'up';
let element: AccessibilityElement;
try {
  rootElement.findElement('focusDirection', condition).then((data: AccessibilityElement) => {
    element = data;
    console.log('find element success');
  }).catch((err: object) => {
    console.error(`failed to find element, because ${JSON.stringify(err)}`);
  });
} catch (exception) {
  console.error(`failed to find element, because ${JSON.stringify(exception)}`);
}
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
| callback  | AsyncCallback&lt;AccessibilityElement&gt; | Yes   | Callback used to return the result.             |

**Example**

```ts
import { FocusDirection } from '@ohos.application.AccessibilityExtensionAbility';
import { BusinessError } from '@ohos.base';

let condition: FocusDirection = 'up';
let elements: AccessibilityElement;
try {
  rootElement.findElement('focusDirection', condition, (err: BusinessError<void>, data: AccessibilityElement) => {
    if (err) {
      console.error(`failed to find element, because ${JSON.stringify(err)}`);
      return;
    }
    elements = data;
    console.info('find element success');
  });
} catch (exception) {
  console.error(`failed to find element, because ${JSON.stringify(exception)}`);
}
```
