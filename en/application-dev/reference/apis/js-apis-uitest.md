# @ohos.uitest

The **UiTest** module provides APIs that you can use to simulate UI actions during testing, such as clicks, double-clicks, long-clicks, and swipes.

This module provides the following functions:

- [On<sup>9+</sup>](#on9): provides UI component feature description APIs for component filtering and matching.
- [Component<sup>9+</sup>](#component9): represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
- [Driver<sup>9+</sup>](#driver9): works as the entry class and provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot.
- [UiWindow<sup>9+</sup>](#uiwindow9): works as the entry class and provides APIs for obtaining window attributes, dragging windows, and adjusting window sizes.
- [By<sup>(deprecated)</sup>](#bydeprecated): provides UI component feature description APIs for component filtering and matching. This API is deprecated since API version 9. You are advised to use [On<sup>9+</sup>](#on9) instead.
- [UiComponent<sup>(deprecated)</sup>](#uicomponentdeprecated): represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection. This API is deprecated since API version 9. You are advised to use [Component<sup>9+</sup>](#component9) instead.
- [UiDriver<sup>(deprecated)</sup>](#uidriverdeprecated): works as the entry class and provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot. This API is deprecated since API version 9. You are advised to use [Driver<sup>9+</sup>](#driver9) instead.

>**NOTE**
>
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import {UiComponent, UiDriver, Component, Driver, UiWindow, ON, BY, MatchPattern, DisplayRotation, ResizeDirection, WindowMode, PointerMatrix} from '@ohos.uitest';
```

## MatchPattern

Enumerates the match patterns supported for component attributes.

**System capability**: SystemCapability.Test.UiTest

| Name       | Value  | Description          |
| ----------- | ---- | -------------- |
| EQUALS      | 0    | Equal to the given value.  |
| CONTAINS    | 1    | Contains the given value.  |
| STARTS_WITH | 2    | Starts with the given value.|
| ENDS_WITH   | 3    | Ends with the given value.|

## ResizeDirection<sup>9+</sup>

Enumerates the directions in which a window can be resized.

**System capability**: SystemCapability.Test.UiTest

| Name      | Value  | Description    |
| ---------- | ---- | -------- |
| LEFT       | 0    | Left.  |
| RIGHT      | 1    | Right.  |
| UP         | 2    | Up.  |
| DOWN       | 3    | Down.  |
| LEFT_UP    | 4    | Upper left.|
| LEFT_DOWN  | 5    | Lower left.|
| RIGHT_UP   | 6    | Upper right.|
| RIGHT_DOWN | 7    | Lower right.|

## Point<sup>9+</sup>

Provides the coordinates of a point.

**System capability**: SystemCapability.Test.UiTest

| Name| Type  | Readable| Writable| Description            |
| ---- | ------ | ---- | ---- | ---------------- |
| X    | number | Yes  | No  | X-coordinate of a point.|
| Y    | number | Yes  | No  | Y-coordinate of a point.|

## Rect<sup>9+</sup>

Provides bounds information of a component.

**System capability**: SystemCapability.Test.UiTest

| Name   | Type  | Readable| Writable| Description                     |
| ------- | ------ | ---- | ---- | ------------------------- |
| leftX   | number | Yes  | No  | X-coordinate of the upper left corner of the component bounds.|
| topY    | number | Yes  | No  | Y-coordinate of the upper left corner of the component bounds.|
| rightX  | number | Yes  | No  | X-coordinate of the lower right corner of the component bounds.|
| bottomY | number | Yes  | No  | Y-coordinate of the lower right corner of the component bounds.|

## WindowMode<sup>9+</sup>

**System capability**: SystemCapability.Test.UiTest

Enumerates the window modes.

| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| FULLSCREEN | 0    | Full-screen mode.|
| PRIMARY    | 1    | Primary window mode.  |
| SECONDARY  | 2    | Secondary window mode.|
| FLOATING   | 3    | Floating window mode.|

## DisplayRotation<sup>9+</sup>

**System capability**: SystemCapability.Test.UiTest

Describes the display rotation of the device.

| Name        | Value  | Description                                    |
| ------------ | ---- | ---------------------------------------- |
| ROTATION_0   | 0    | The device display is not rotated and is in its original vertical orientation.    |
| ROTATION_90  | 1    | The device display rotates 90° clockwise and is in landscape orientation.     |
| ROTATION_180 | 2    | The device display rotates 180° clockwise and is in reverse vertical orientation.|
| ROTATION_270 | 3    | The device display rotates 270° clockwise and is in reverse landscape orientation.|

## WindowFilter<sup>9+</sup>

Provides the flag attributes of this window.

**System capability**: SystemCapability.Test.UiTest

| Name      | Type   | Readable| Writable| Description                      |
| ---------- | ------- | ---- | ---- | -------------------------- |
| bundleName | string  | Yes  | No  | Bundle name of the application to which the window belongs.      |
| title      | string  | Yes  | No  | Title of the window.          |
| focused    | boolean | Yes  | No  | Whether the window is in focused state.    |
| actived    | boolean | Yes  | No  | Whether the window is interacting with the user.|

## On<sup>9+</sup>

Since API version 9, the UiTest framework provides a wide range of UI component feature description APIs in the **On** class to filter and match components.
The API capabilities provided by the **On** class exhibit the following features: 1. Allow one or more attributes as the match conditions. For example, you can specify both the **text** and **id** attributes to find the target component. <br>2. Provide multiple match patterns for component attributes. <br>3. Support absolute positioning and relative positioning for components. APIs such as [ON.isBefore](#isbefore) and [ON.isAfter](#isafter) can be used to specify the features of adjacent components to assist positioning. <br>All APIs provided in the **On** class are synchronous. You are advised to use the static constructor **ON** to create an **On** object in chain mode.

```js
ON.text('123').type('button');
```

### text<sup>9+</sup>

text(txt: string, pattern?: MatchPattern): On

Specifies the text attribute of the target component. Multiple match patterns are supported.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type                         | Mandatory| Description                                               |
| ------- | ----------------------------- | ---- | --------------------------------------------------- |
| txt     | string                        | Yes  | Component text, used to match the target component.               |
| pattern | [MatchPattern](#matchpattern) | No  | Match pattern. The default value is [EQUALS](#matchpattern).|

**Return value**

| Type      | Description                              |
| ---------- | ---------------------------------- |
| [On](#on9) | **On** object that matches the text attribute of the target component.|

**Example**

```js
let on = ON.text('123'); // Use the static constructor ON to create an On object and specify the text attribute of the target component.
```


### id<sup>9+</sup>

id(id: string): On

Specifies the ID attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| id     | string | Yes  | Component ID.|

**Return value**

| Type      | Description                            |
| ---------- | -------------------------------- |
| [On](#on9) | **On** object that matches the ID attribute of the target component.|

**Example**

```js
let on = ON.id('123'); // Use the static constructor ON to create an On object and specify the ID attribute of the target component.
```


### type<sup>9+</sup>

type(tp: string): On

Specifies the type attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| tp     | string | Yes  | Component type.|

**Return value**

| Type      | Description                                    |
| ---------- | ---------------------------------------- |
| [On](#on9) | **On** object that matches the type attribute of the target component.|

**Example**

```js
let on = ON.type('button'); // Use the static constructor ON to create an On object and specify the type attribute of the target component.
```


### clickable<sup>9+</sup>

clickable(b?: boolean): On

Specifies the clickable status attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Clickable status of the target component.<br>**true**: clickable.<br>**false**: not clickable.<br> Default value: **true**|

**Return value**

| Type      | Description                                      |
| ---------- | ------------------------------------------ |
| [On](#on9) | **On** object that matches the clickable status attribute of the target component.|

**Example**

```js
let on = ON.clickable(true); // Use the static constructor ON to create an On object and specify the clickable status attribute of the target component.
```

### longClickable<sup>9+</sup>

longClickable(b?: boolean): On

Specifies the long-clickable status attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Long-clickable status of the target component.<br>**true**: long-clickable.<br>**false**: not long-clickable.<br> Default value: **true**|

**Return value**

| Type      | Description                                          |
| ---------- | ---------------------------------------------- |
| [On](#on9) | **On** object that matches the long-clickable status attribute of the target component.|

**Example**

```js
let on = ON.longClickable(true); // Use the static constructor ON to create an On object and specify the long-clickable status attribute of the target component.
```


### scrollable<sup>9+</sup>

scrollable(b?: boolean): On

Specifies the scrollable status attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                       |
| ------ | ------- | ---- | ----------------------------------------------------------- |
| b      | boolean | No  | Scrollable status of the target component.<br>**true**: scrollable.<br>**false**: not scrollable.<br> Default value: **true**|

**Return value**

| Type      | Description                                      |
| ---------- | ------------------------------------------ |
| [On](#on9) | **On** object that matches the scrollable status attribute of the target component.|

**Example**

```js
let on = ON.scrollable(true); // Use the static constructor ON to create an On object and specify the scrollable status attribute of the target component.
```

### enabled<sup>9+</sup>

enabled(b?: boolean): On

Specifies the enabled status attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                     |
| ------ | ------- | ---- | --------------------------------------------------------- |
| b      | boolean | No  | Enabled status of the target component.<br>**true**: enabled.<br>**false**: disabled.<br> Default value: **true**|

**Return value**

| Type      | Description                                    |
| ---------- | ---------------------------------------- |
| [On](#on9) | **On** object that matches the enabled status attribute of the target component.|

**Example**

```js
let on = ON.enabled(true); // Use the static constructor ON to create an On object and specify the enabled status attribute of the target component.
```

### focused<sup>9+</sup>

focused(b?: boolean): On

Specifies the focused status attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                 |
| ------ | ------- | ---- | ----------------------------------------------------- |
| b      | boolean | No  | Focused status of the target component.<br>**true**: focused.<br>**false**: not focused.<br> Default value: **true**|

**Return value**

| Type      | Description                                    |
| ---------- | ---------------------------------------- |
| [On](#on9) | **On** object that matches the focused status attribute of the target component.|

**Example**

```js
let on = ON.focused(true); // Use the static constructor ON to create an On object and specify the focused status attribute of the target component.
```

### selected<sup>9+</sup>

selected(b?: boolean): On

Specifies the selected status attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Selected status of the target component.<br>**true**: selected.<br>**false**: not selected.<br> Default value: **true**|

**Return value**

| Type      | Description                                      |
| ---------- | ------------------------------------------ |
| [On](#on9) | **On** object that matches the selected status attribute of the target component.|

**Example**

```js
let on = ON.selected(true); // Use the static constructor ON to create an On object and specify the selected status attribute of the target component.
```

### checked<sup>9+</sup>

checked(b?: boolean): On

Specifies the checked status attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Checked status of the target component.<br>**true**: checked.<br>**false**: not checked.<br> Default value: **false**|

**Return value**

| Type      | Description                                      |
| ---------- | ------------------------------------------ |
| [On](#on9) | **On** object that matches the checked status attribute of the target component.|

**Example**

```js
let on = ON.checked(true); // Use the static constructor ON to create an On object and specify the checked status attribute of the target component.
```

### checkable<sup>9+</sup>

checkable(b?: boolean): On

Specifies the checkable status attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Checkable status of the target component.<br>**true**: checkable.<br>**false**: not checkable.<br> Default value: **false**|

**Return value**

| Type      | Description                                        |
| ---------- | -------------------------------------------- |
| [On](#on9) | **On** object that matches the checkable status attribute of the target component.|

**Example**

```js
let on = ON.checkable(true); // Use the static constructor ON to create an On object and specify the checkable status attribute of the target component.
```

### isBefore<sup>9+</sup>

isBefore(on: On): On

Specifies the attributes of the component before which the target component is located.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the component before which the target component is located.|

**Return value**

| Type      | Description                                                |
| ---------- | ---------------------------------------------------- |
| [On](#on9) | **On** object.|

**Example**

```js
let on = ON.isBefore(ON.text('123')); // Use the static constructor ON to create an On object and specify the attributes of the component before which the target component is located.
```

### isAfter<sup>9+</sup>

isAfter(on: On): On

Specifies the attributes of the component after which the target component is located.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the component after which the target component is located.|

**Return value**

| Type      | Description                                                |
| ---------- | ---------------------------------------------------- |
| [On](#on9) | **On** object.|

**Example**

```js
let on = ON.isAfter(ON.text('123')); // Use the static constructor ON to create an On object and specify the attributes of the component after which the target component is located.
```

## Component<sup>9+</sup>

In **UiTest** of API version 9, the **Component** class represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

### click<sup>9+</sup>

click(): Promise\<void>

Clicks this component.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    await button.click();
}
```

### doubleClick<sup>9+</sup>

doubleClick(): Promise\<void>

Double-clicks this component.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    await button.doubleClick();
}
```

### longClick<sup>9+</sup>

longClick(): Promise\<void>

Long-clicks this component.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    await button.longClick();
}
```

### getId<sup>9+</sup>

getId(): Promise\<string>

Obtains the ID of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                           |
| ---------------- | ------------------------------- |
| Promise\<string> | Promise used to return the ID of the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let num = await button.getId();
}
```

### getText<sup>9+</sup>

getText(): Promise\<string>

Obtains the text information of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the text information of the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let text = await button.getText();
}
```

### getType<sup>9+</sup>

getType(): Promise\<string>

Obtains the type of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                         |
| ---------------- | ----------------------------- |
| Promise\<string> | Promise used to return the type of the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let type = await button.getType();
}
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

Obtains the bounds of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                    | Description                                 |
| ------------------------ | ------------------------------------- |
| Promise\<[Rect](#rect9)> | Promise used to return the bounds of the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let rect = await button.getBounds();
}
```

### getBoundsCenter<sup>9+</sup>

getBoundsCenter(): Promise\<Point>

Obtains the information about the center of the bounding box around this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                      | Description                                           |
| -------------------------- | ----------------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the information about the center of the bounding box around the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let point = await button.getBoundsCenter();
}
```

### isClickable<sup>9+</sup>

isClickable(): Promise\<boolean>

Obtains the clickable status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is clickable, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    if(await button.isClickable()) {
        console.info('This button can be Clicked');
    } else {
        console.info('This button can not be Clicked');
    }
}
```

### isLongClickable<sup>9+</sup>

isLongClickable(): Promise\<boolean> 

Obtains the long-clickable status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the long-clickable status of the component. The value **true** means that the component is long-clickable, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    if(await button.isLongClickable()) {
        console.info('This button can longClick');
    } else {
        console.info('This button can not longClick');
    }
}
```

### isChecked<sup>9+</sup>

isChecked(): Promise\<boolean>

Obtains the checked status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the checked status of the component. The value **true** means that the component is checked, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let checkBox = await driver.findComponent(ON.type('Checkbox'));
    if(await checkBox.isChecked) {
        console.info('This checkBox is checked');
    } else {
        console.info('This checkBox is not checked');
    }
}
```

### isCheckable<sup>9+</sup>

isCheckable(): Promise\<boolean>

Obtains the checkable status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the checkable status of the component. The value **true** means that the component is checkable, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let checkBox = await driver.findComponent(ON.type('Checkbox'));
    if(await checkBox.isCheckable) {
        console.info('This checkBox is checkable');
    } else {
        console.info('This checkBox is not checkable');
    }
}
```

### isScrollable<sup>9+</sup>

isScrollable(): Promise\<boolean>

Obtains the scrollable status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is scrollable, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let scrollBar = await driver.findComponent(ON.scrollable(true));
    if(await scrollBar.isScrollable()) {
        console.info('This scrollBar can be operated');
    } else {
        console.info('This scrollBar can not be operated');
    }
}
```


### isEnabled<sup>9+</sup>

isEnabled(): Promise\<boolean>

Obtains the enabled status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                      |
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    if(await button.isEnabled()) {
        console.info('This button can be operated');
    } else {
        console.info('This button can not be operated');
    }
}

```

### isFocused<sup>9+</sup>

isFocused(): Promise\<boolean>

Obtains the focused status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the focused status of the component. The value **true** means that the component is focused, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    if(await button.isFocused()) {
        console.info('This button is focused');
    } else {
        console.info('This button is not focused');
	}
}
```

### isSelected<sup>9+</sup>

isSelected(): Promise\<boolean>

Obtains the selected status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                               |
| ----------------- | --------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is selected, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    if(await button.isSelected()) {
        console.info('This button is selected');
	} else {
        console.info('This button is not selected');
    }
}
```

### inputText<sup>9+</sup>

inputText(text: string): Promise\<void>

Enters text into this component (available for text boxes).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| text   | string | Yes  | Text to enter, which can contain English and special characters.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let text = await driver.findComponent(ON.text('hello world'));
    await text.inputText('123');
}
```

### clearText<sup>9+</sup>

clearText(): Promise\<void>

Clears text in this component. This API is applicable to text boxes.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let text = await driver.findComponent(ON.text('hello world'));
    await text.clearText();
}
```

### scrollSearch<sup>9+</sup>

scrollSearch(on: On): Promise\<Component>

Scrolls on this component to search for the target component. This API is applicable to components that support scrolling.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the target component.|

**Return value**

| Type                              | Description                                 |
| ---------------------------------- | ------------------------------------- |
| Promise\<[Component](#component9)> | Promise used to return the target component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('Scroll'));
    let button = await scrollBar.scrollSearch(ON.text('next page'));
}
```

### scrollToTop<sup>9+</sup>

scrollToTop(speed?: number): Promise\<void>

Scrolls to the top of this component. This API is applicable to components that support scrolling.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| speed  | number | No  | Scroll speed, in pixel/s. The value ranges from 200 to 15000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let scrollBar = await driver.findComponent(ON.type('Scroll'));
    await scrollBar.scrollToTop();
}
```

### scrollToBottom<sup>9+</sup>

scrollToBottom(speed?: number): Promise\<void>

Scrolls to the bottom of this component. This API is applicable to components that support scrolling.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| speed  | number | No  | Scroll speed, in pixel/s. The value ranges from 200 to 15000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let scrollBar = await driver.findComponent(ON.type('Scroll'));
    await scrollBar.scrollToBottom();
}
```

### dragTo<sup>9+</sup>

dragTo(target: Component): Promise\<void>

Drags this component to the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                    | Mandatory| Description      |
| ------ | ------------------------ | ---- | ---------- |
| target | [Component](#component9) | Yes  | Target component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let text = await driver.findComponent(ON.text('hello world'));
    await button.dragTo(text);
    }
```

### pinchOut<sup>9+</sup>

pinchOut(scale: number): Promise\<void>

Pinches a component to scale it up to the specified ratio.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| scale  | number | Yes  | Scale factor.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let image = await driver.findComponent(ON.type('image'));
    await image.pinchOut(1.5);
    }
```

### pinchIn<sup>9+</sup>

pinchIn(scale: number): Promise\<void>

Pinches a component to scale it down to the specified ratio.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| scale  | number | Yes  | Scale factor.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let image = await driver.findComponent(ON.type('image'));
    await image.pinchIn(0.5);
    }
```

## Driver<sup>9+</sup>

The **Driver** class is the main entry to the UiTest framework. It provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot.
All APIs provided by this class, except for **Driver.create()**, use a promise to return the result and must be invoked using **await**.

### create<sup>9+</sup>

static create(): Driver

Creates a **Driver** object and returns the object created. This API is a static API.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type| Description          |
| -------- | ---------------------- |
| Driver   | **Driver** object created.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message          |
| -------- | ------------------ |
| 17000001 | Initialize failed. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
}
```

### delayMs<sup>9+</sup>

delayMs(duration: number): Promise\<void>

Delays this **Driver** object within the specified duration.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| duration | number | Yes  | Duration of time, in ms.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.delayMs(1000);
}
```

### findComponent<sup>9+</sup>

findComponent(on: On): Promise\<Component>

Searches this **Driver** object for the target component that matches the given attributes.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the target component.|

**Return value**

| Type                              | Description                             |
| ---------------------------------- | --------------------------------- |
| Promise\<[Component](#component9)> | Promise used to return the found component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.text('next page'));
}
```

### findComponents<sup>9+</sup>

findComponents(on: On): Promise\<Array\<Component>>

Searches this **Driver** object for all components that match the given attributes.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the target component.|

**Return value**

| Type                                      | Description                                   |
| ------------------------------------------ | --------------------------------------- |
| Promise\<Array\<[Component](#component9)>> | Promise used to return a list of found components.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let buttonList = await driver.findComponents(ON.text('next page'));
}
```

### findWindow<sup>9+</sup>

findWindow(filter: WindowFilter): Promise\<UiWindow>

Searches for the window that matches the specified attributes.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                          | Mandatory| Description            |
| ------ | ------------------------------ | ---- | ---------------- |
| filter | [WindowFilter](#windowfilter9) | Yes  | Attributes of the target window.|

**Return value**

| Type                            | Description                                 |
| -------------------------------- | ------------------------------------- |
| Promise\<[UiWindow](#uiwindow9)> | Promise used to return the target window.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
}
```

### waitForComponent<sup>9+</sup>

waitForComponent(on: On, time: number): Promise\<Component>

Searches this **Driver** object for the target component that matches the given attributes within the specified duration.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                            |
| ------ | ---------- | ---- | -------------------------------- |
| On     | [On](#on9) | Yes  | Attributes of the target component.            |
| time   | number     | Yes  | Duration for searching for the target component, in ms.|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise\<[Component](#component)> | Promise used to return the found component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.waitForComponent(ON.text('next page'),500);
}
```

### assertComponentExist<sup>9+</sup>

assertComponentExist(on: On): Promise\<void>

Asserts that a component that matches the given attributes exists on the current page.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the target component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000003 | Component existence assertion failed.    |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.assertComponentExist(ON.text('next page'));
}
```

### pressBack<sup>9+</sup>

pressBack(): Promise\<void>

Presses the Back button on this **Driver** object.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.pressBack();
}
```

### triggerKey<sup>9+</sup>

triggerKey(keyCode: number): Promise\<void>

Triggers the key of this **Driver** object that matches the given key code.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ------------- |
| keyCode | number | Yes  | Key code.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.triggerKey(123);
}
```

### triggerCombineKeys<sup>9+</sup>

triggerCombineKeys(key0: number, key1: number, key2?: number): Promise\<void>

Triggers a key combination based on the specified key values. For example, if the value of **Key** is (2072, 2019), the **Driver** object finds and clicks the key combination that matches the value, for example, **Ctrl+C**.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description               |
| ------ | ------ | ---- | ------------------- |
| key0   | number | Yes  | The first key value.|
| key1   | number | Yes  | The second key value.|
| key2   | number | No  | The third key value.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.triggerCombineKeys(2072, 2047, 2035);
}
```


### click<sup>9+</sup>

click(x: number, y: number): Promise\<void>

Clicks a specific point of this **Driver** object based on the given coordinates.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.click(100,100);
}
```

### doubleClick<sup>9+</sup>

doubleClick(x: number, y: number): Promise\<void>

Double-clicks a specific point of this **Driver** object based on the given coordinates.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.doubleClick(100,100);
}
```

### longClick<sup>9+</sup>

longClick(x: number, y: number): Promise\<void>

Long-clicks a specific point of this **Driver** object based on the given coordinates.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.longClick(100,100);
}
```

### swipe<sup>9+</sup>

swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Swipes on this **Driver** object from the given start point to the given end point.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| startx | number | Yes  | X-coordinate of the start point.                      |
| starty | number | Yes  | Y-coordinate of the start point.                      |
| endx   | number | Yes  | X-coordinate of the end point.                      |
| endy   | number | Yes  | Y-coordinate of the end point.                      |
| speed  | number | No  | Scroll speed, in pixel/s. The value ranges from 200 to 15000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.swipe(100,100,200,200,600);
}
```

### drag<sup>9+</sup>

drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Drags this **Driver** object from the given start point to the given end point.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| startx | number | Yes  | X-coordinate of the start point.                      |
| starty | number | Yes  | Y-coordinate of the start point.                      |
| endx   | number | Yes  | X-coordinate of the end point.                      |
| endy   | number | Yes  | Y-coordinate of the end point.                      |
| speed  | number | No  | Scroll speed, in pixel/s. The value ranges from 200 to 15000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.drag(100,100,200,200,600);
}
```

### screenCap<sup>9+</sup>

screenCap(savePath: string): Promise\<boolean>

Captures the current screen of this **Driver** object and saves it as a PNG image to the given save path.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description          |
| -------- | ------ | ---- | -------------- |
| savePath | string | Yes  | File save path.|

**Return value**

| Type             | Description                                  |
| ----------------- | -------------------------------------- |
| Promise\<boolean> | Promise used to return the operation result. The value **true** means that the operation is successful.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.screenCap('/local/tmp/1.png');
}
```

### setDisplayRotation<sup>9+</sup>

setDisplayRotation(rotation: DisplayRotation): Promise\<void>

Sets the display rotation of the device.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type                                | Mandatory| Description            |
| -------- | ------------------------------------ | ---- | ---------------- |
| rotation | [DisplayRotation](#displayrotation9) | Yes  | Display rotation of the device.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.setDisplayRotation(DisplayRotation.ROTATION_180);
}
```

### getDisplayRotation<sup>9+</sup>

getDisplayRotation(): Promise\<DisplayRotation>

Obtains the display rotation of the current device.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                                          | Description                                   |
| ---------------------------------------------- | --------------------------------------- |
| Promise\<[DisplayRotation](#displayrotation9)> | Promise used to return the display rotation of the current device.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let rotation = await driver.getDisplayRotation();
}
```

### setDisplayRotationEnabled<sup>9+</sup>

setDisplayRotationEnabled(enabled: boolean): Promise\<void>

Enables or disables display rotation.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type   | Mandatory| Description                                                   |
| ------- | ------- | ---- | ------------------------------------------------------- |
| enabled | boolean | Yes  | Whether to enable display rotation. The value **true** means to enable display rotation, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.setDisplayRotationEnabled(false);
}
```

### getDisplaySize<sup>9+</sup>

getDisplaySize(): Promise\<Point>

Obtains the display size of the current device.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                      | Description                                   |
| -------------------------- | --------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the display size of the current device.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let size = await driver.getDisplaySize();
}
```

### getDisplayDensity<sup>9+</sup>

getDisplayDensity(): Promise\<Point>

Obtains the display density of the current device.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                      | Description                                     |
| -------------------------- | ----------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the display density of the current device.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let density = await driver.getDisplayDensity();
}
```

### wakeUpDisplay<sup>9+</sup>

wakeUpDisplay(): Promise\<void>

Wakes up the device display.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.wakeUpDisplay();
}
```

### pressHome<sup>9+</sup>

pressHome(): Promise\<void>

Returns to the home screen.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.pressHome();
}
```

### waitForIdle<sup>9+</sup>

waitForIdle(idleTime: number, timeout: number): Promise\<boolean>

Checks whether all components on the current page are idle.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| idleTime | number | Yes  | Idle time threshold, in milliseconds. If the duration for which a component remains inactive reaches this threshold, it is considered as idle.|
| timeout  | number | Yes  | Maximum idle waiting time, in milliseconds.                            |

**Return value**

| Type             | Description                                               |
| ----------------- | --------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let idled = await driver.waitForIdle(4000,5000);
}
```

### fling<sup>9+</sup>

fling(from: Point, to: Point, stepLen: number, speed: number): Promise\<void>

Simulates a fling operation on the screen.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type            | Mandatory| Description                                                        |
| ------- | ---------------- | ---- | ------------------------------------------------------------ |
| from    | [Point](#point9) | Yes  | Coordinates of the point where the finger touches the screen.                                  |
| to      | [Point](#point9) | Yes  | Coordinates of the point where the finger leaves the screen.                                    |
| stepLen | number           | Yes  | Fling step length, in pixels.                                    |
| speed   | number           | Yes  | Scroll speed, in pixel/s. The value ranges from 200 to 15000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    await driver.fling({X: 500, Y: 480},{X: 450, Y: 480},5,600);
}
```

### injectMultiPointerAction<sup>9+</sup>

injectMultiPointerAction(pointers: PointerMatrix, speed?: number): Promise\<boolean>

Injects a multi-touch operation to the device.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| pointers | [PointerMatrix](#pointermatrix9) | Yes  | Scroll trajectory, including the number of fingers and an array of coordinates along the trajectory.                  |
| speed    | number                           | No  | Scroll speed, in pixel/s. The value ranges from 200 to 15000. If the set value is not in the range, the default value 600 is used.|

**Return value**

| Type             | Description                                 |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let pointers = PointerMatrix.create(2,3);
    pointers.setPoint(0,0,{X:230,Y:480});
    pointers.setPoint(0,1,{X:250,Y:380});
    pointers.setPoint(0,2,{X:270,Y:280});
    pointers.setPoint(1,0,{X:230,Y:680});
    pointers.setPoint(1,1,{X:240,Y:580});
    pointers.setPoint(1,2,{X:250,Y:480});
    await driver.injectMultiPointerAction(pointers);
}
```

## PointerMatrix<sup>9+</sup>

Implements a **PointerMatrix** object that stores coordinates and behaviors of each action of each finger in a multi-touch operation.

### create<sup>9+</sup>

static create(fingers: number, steps: number): PointerMatrix

Creates a **PointerMatrix** object and returns the object created. This API is a static API.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description                                      |
| ------- | ------ | ---- | ------------------------------------------ |
| fingers | number | Yes  | Number of fingers in the multi-touch operation. Value range: [1,10].|
| steps   | number | Yes  | Number of steps operated by each finger. Value range: [1,1000].|

**Return value**

| Type                            | Description                         |
| -------------------------------- | ----------------------------- |
| [PointerMatrix](#pointermatrix9) | **PointerMatrix** object created.|

**Example**

```js
async function demo() {
    let pointerMatrix = PointerMatrix.create(2,3);
}
```

### setPoint<sup>9+</sup>

setPoint(finger: number, step: number, point: Point): void

Sets the coordinates for the action corresponding to the specified finger and step in the **PointerMatrix** object.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description            |
| ------ | ---------------- | ---- | ---------------- |
| finger | number           | Yes  | Sequence number of the finger.    |
| step   | number           | Yes  | Sequence number of the step.    |
| point  | [Point](#point9) | Yes  | Coordinates of the action.|

**Example**

```js
async function demo() {
    let pointers = PointerMatrix.create(2,3);
    pointers.setPoint(0,0,{X:230,Y:480});
    pointers.setPoint(0,1,{X:250,Y:380});
    pointers.setPoint(0,2,{X:270,Y:280});
    pointers.setPoint(1,0,{X:230,Y:680});
    pointers.setPoint(1,1,{X:240,Y:580});
    pointers.setPoint(1,2,{X:250,Y:480});
}
```

## UiWindow<sup>9+</sup>

The **UiWindow** class represents a window on the UI and provides APIs for obtaining window attributes, dragging a window, and adjusting the window size.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

### getBundleName<sup>9+</sup>

getBundleName(): Promise\<string>

Obtains the bundle name of the application to which this window belongs.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise\<string> | Promise used to return the bundle name.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let name = await window.getBundleName();
}
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

Obtains the bounds information of this window.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                    | Description                             |
| ------------------------ | --------------------------------- |
| Promise\<[Rect](#rect9)> | Promise used to return the bounds information of the window.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let rect = await window.getBounds();
}
```

### getTitle<sup>9+</sup>

getTitle(): Promise\<string>

Obtains the title of this window.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the title of the window.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let rect = await window.getTitle();
}
```

### getWindowMode<sup>9+</sup>

getWindowMode(): Promise\<WindowMode>

Obtains the window mode of this window.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                                | Description                                 |
| ------------------------------------ | ------------------------------------- |
| Promise\<[WindowMode](#windowmode9)> | Promise used to return the window mode of the window.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let mode = await window.getWindowMode();
}
```

### isFocused<sup>9+</sup>

isFocused(): Promise\<boolean>

Checks whether this window is in focused state.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the window is in focused state, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let focused = await window.isFocused();
}
```

### isActived<sup>9+</sup>

isActived(): Promise\<boolean>

Checks whether this window is active.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the window is active, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let focused = await window.isActived();
}
```

### focus<sup>9+</sup>

focus(): Promise\<void>

Moves the focus to this window.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.focus();
}
```

### moveTo<sup>9+</sup>

moveTo(x: number, y: number): Promise\<void>

Moves this window to the target point. This API is applicable to moveable windows.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.moveTo(100, 100);
}
```

### resize<sup>9+</sup>

resize(wide: number, height: number, direction: ResizeDirection): Promise\<void>

Resizes this window based on the specified width, height, and resize direction. This API is applicable to resizable windows.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name   | Type                                | Mandatory| Description                                                        |
| --------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| wide      | number                               | Yes  | Target width.                        |
| height    | number                               | Yes  | Target height.                        |
| direction | [ResizeDirection](#resizedirection9) | Yes  | Resize direction.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.resize(100, 100, ResizeDirection.LEFT);
}
```

### split<sup>9+</sup>

split(): Promise\<void>

Switches the window to split-screen mode. This API is applicable to windows that support screen splitting.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.split();
}
```

### maximize<sup>9+</sup>

maximize(): Promise\<void>

Maximizes this window. This API is applicable to windows that can be maximized.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.maximize();
}
```

### minimize<sup>9+</sup>

minimize(): Promise\<void>

Minimizes this window. This API is applicable to windows that can be minimized.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.minimize();
}
```

### resume<sup>9+</sup>

resume(): Promise\<void>

Restores this window to the previous window mode.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.resume();
}
```

### close<sup>9+</sup>

close(): Promise\<void>

Closes this window.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](../errorcodes/errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**Example**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.close();
}
```

## By<sup>(deprecated)</sup>

The UiTest framework provides a wide range of UI component feature description APIs in the **By** class to filter and match components.
The API capabilities provided by the **By** class exhibit the following features: <br>1. Allow one or more attributes as the match conditions. For example, you can specify both the **text** and **id** attributes to find the target component. <br>2. Provide multiple match patterns for component attributes. <br>3. Support absolute positioning and relative positioning for components. APIs such as [By.isBefore<sup>(deprecated)</sup>](#isbeforedeprecated) and [By.isAfter<sup>(deprecated)</sup>](#isafterdeprecated) can be used to specify the features of adjacent components to assist positioning. <br>All APIs provided in the **By** class are synchronous. You are advised to use the static constructor **BY** to create a **By** object in chain mode.

This API is deprecated since API version 9. You are advised to use [On<sup>9+</sup>](#on9) instead.

```js
BY.text('123').type('button');
```

### text<sup>(deprecated)</sup>

text(txt: string, pattern?: MatchPattern): By

Specifies the text attribute of the target component. Multiple match patterns are supported.

This API is deprecated since API version 9. You are advised to use [text<sup>9+</sup>](#text9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type                         | Mandatory| Description                                               |
| ------- | ----------------------------- | ---- | --------------------------------------------------- |
| txt     | string                        | Yes  | Component text, used to match the target component.               |
| pattern | [MatchPattern](#matchpattern) | No  | Match pattern. The default value is [EQUALS](#matchpattern).|

**Return value**

| Type               | Description                              |
| ------------------- | ---------------------------------- |
| [By](#bydeprecated) | **By** object that matches the text attribute of the target component.|

**Example**

```js
let by = BY.text('123'); // Use the static constructor BY to create a By object and specify the text attribute of the target component.
```


### key<sup>(deprecated)</sup>

key(key: string): By

Specifies the key attribute of the target component.

This API is deprecated since API version 9. You are advised to use [id<sup>9+</sup>](#id9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description             |
| ------ | ------ | ---- | ----------------- |
| key    | string | Yes  | Component key.|

**Return value**

| Type               | Description                               |
| ------------------- | ----------------------------------- |
| [By](#bydeprecated) | **By** object that matches the key attribute of the target component.|

**Example**

```js
let by = BY.key('123'); // Use the static constructor BY to create a By object and specify the key attribute of the target component.
```


### id<sup>(deprecated)</sup>

id(id: number): By

Specifies the ID attribute of the target component.

This API is deprecated since API version 9.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| id     | number | Yes  | Component ID.|

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| [By](#bydeprecated) | **By** object that matches the ID attribute of the target component.|

**Example**

```js
let by = BY.id(123); // Use the static constructor BY to create a By object and specify the ID attribute of the target component.
```


### type<sup>(deprecated)</sup>

type(tp: string): By

Specifies the type attribute of the target component.

This API is deprecated since API version 9. You are advised to use [type<sup>9+</sup>](#type9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| tp     | string | Yes  | Component type.|

**Return value**

| Type               | Description                                    |
| ------------------- | ---------------------------------------- |
| [By](#bydeprecated) | **By** object that matches the type attribute of the target component.|

**Example**

```js
let by = BY.type('button'); // Use the static constructor BY to create a By object and specify the type attribute of the target component.
```


### clickable<sup>(deprecated)</sup>

clickable(b?: boolean): By

Specifies the clickable status attribute of the target component.

This API is deprecated since API version 9. You are advised to use [clickable<sup>9+</sup>](#clickable9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Clickable status of the target component.<br>**true**: clickable.<br>**false**: not clickable.<br> Default value: **true**|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [By](#bydeprecated) | **By** object that matches the clickable status attribute of the target component.|

**Example**

```js
let by = BY.clickable(true); // Use the static constructor BY to create a By object and specify the clickable status attribute of the target component.
```


### scrollable<sup>(deprecated)</sup>

scrollable(b?: boolean): By

Specifies the scrollable status attribute of the target component.

This API is deprecated since API version 9. You are advised to use [scrollable<sup>9+</sup>](#scrollable9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                       |
| ------ | ------- | ---- | ----------------------------------------------------------- |
| b      | boolean | No  | Scrollable status of the target component.<br>**true**: scrollable.<br>**false**: not scrollable.<br> Default value: **true**|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [By](#bydeprecated) | **By** object that matches the scrollable status attribute of the target component.|

**Example**

```js
let by = BY.scrollable(true); // Use the static constructor BY to create a By object and specify the scrollable status attribute of the target component.
```

### enabled<sup>(deprecated)</sup>

enabled(b?: boolean): By

Specifies the enabled status attribute of the target component.

This API is deprecated since API version 9. You are advised to use [enabled<sup>9+</sup>](#enabled9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                     |
| ------ | ------- | ---- | --------------------------------------------------------- |
| b      | boolean | No  | Enabled status of the target component.<br>**true**: enabled.<br>**false**: not disabled.<br> Default value: **true**|

**Return value**

| Type               | Description                                    |
| ------------------- | ---------------------------------------- |
| [By](#bydeprecated) | **By** object that matches the enabled status attribute of the target component.|

**Example**

```js
let by = BY.enabled(true); // Use the static constructor BY to create a By object and specify the enabled status attribute of the target component.
```

### focused<sup>(deprecated)</sup>

focused(b?: boolean): By

Specifies the focused status attribute of the target component.

This API is deprecated since API version 9. You are advised to use [focused<sup>9+</sup>](#focused9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                 |
| ------ | ------- | ---- | ----------------------------------------------------- |
| b      | boolean | No  | Focused status of the target component.<br>**true**: focused.<br>**false**: not focused.<br> Default value: **true**|

**Return value**

| Type               | Description                                    |
| ------------------- | ---------------------------------------- |
| [By](#bydeprecated) | **By** object that matches the focused status attribute of the target component.|

**Example**

```js
let by = BY.focused(true); // Use the static constructor BY to create a By object and specify the focused status attribute of the target component.
```

### selected<sup>(deprecated)</sup>

selected(b?: boolean): By

Specifies the selected status of the target component.

This API is deprecated since API version 9. You are advised to use [selected<sup>9+</sup>](#selected9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Selected status of the target component.<br>**true**: selected.<br>**false**: not selected.<br> Default value: **true**|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [By](#bydeprecated) | **By** object that matches the selected status attribute of the target component.|

**Example**

```js
let by = BY.selected(true); // Use the static constructor BY to create a By object and specify the selected status attribute of the target component.
```

### isBefore<sup>(deprecated)</sup>

isBefore(by: By): By

Specifies the attributes of the component before which the target component is located.

This API is deprecated since API version 9. You are advised to use [isBefore<sup>9+</sup>](#isbefore9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type               | Mandatory| Description            |
| ------ | ------------------- | ---- | ---------------- |
| by     | [By](#bydeprecated) | Yes  | Attributes of the component before which the target component is located.|

**Return value**

| Type               | Description                                                |
| ------------------- | ---------------------------------------------------- |
| [By](#bydeprecated) | **By** object.|

**Example**

```js
let by = BY.isBefore(BY.text('123')); // Use the static constructor BY to create a By object and specify the attributes of the component before which the target component is located.
```

### isAfter<sup>(deprecated)</sup>

isAfter(by: By): By

Specifies the attributes of the component after which the target component is located.

This API is deprecated since API version 9. You are advised to use [isAfter<sup>9+</sup>](#isafter9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type               | Mandatory| Description            |
| ------ | ------------------- | ---- | ---------------- |
| by     | [By](#bydeprecated) | Yes  | Attributes of the component before which the target component is located.|

**Return value**

| Type               | Description                                                |
| ------------------- | ---------------------------------------------------- |
| [By](#bydeprecated) | **By** object.|

**Example**

```js
let by = BY.isAfter(BY.text('123')); // Use the static constructor BY to create a By object and specify the attributes of the component after which the target component is located.
```

## UiComponent<sup>(deprecated)</sup>

In **UiTest**, the **UiComponent** class represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

This API is deprecated since API version 9. You are advised to use [Component<sup>9+</sup>](#component9) instead.

### click<sup>(deprecated)</sup>

click(): Promise\<void>

Clicks this component.

This API is deprecated since API version 9. You are advised to use [click<sup>9+</sup>](#click9).

**System capability**: SystemCapability.Test.UiTest

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    await button.click();
}
```

### doubleClick<sup>(deprecated)</sup>

doubleClick(): Promise\<void>

Double-clicks this component.

This API is deprecated since API version 9. You are advised to use [doubleClick<sup>9+</sup>](#doubleclick9).

**System capability**: SystemCapability.Test.UiTest

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    await button.doubleClick();
}
```

### longClick<sup>(deprecated)</sup>

longClick(): Promise\<void>

Long-clicks this component.

This API is deprecated since API version 9. You are advised to use [longClick<sup>9+</sup>](#longclick9).

**System capability**: SystemCapability.Test.UiTest

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    await button.longClick();
}
```

### getId<sup>(deprecated)</sup>

getId(): Promise\<number>

Obtains the ID of this component.

This API is deprecated since API version 9.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                           |
| ---------------- | ------------------------------- |
| Promise\<number> | Promise used to return the ID of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    let num = await button.getId();
}
```

### getKey<sup>(deprecated)</sup>

getKey(): Promise\<string>

Obtains the key of this component.

This API is deprecated since API version 9. You are advised to use [getId<sup>9+</sup>](#getid9).

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                          |
| ---------------- | ------------------------------ |
| Promise\<string> | Promise used to return the key of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    let str_key = await button.getKey();
}
```

### getText<sup>(deprecated)</sup>

getText(): Promise\<string>

Obtains the text information of this component.

This API is deprecated since API version 9. You are advised to use [getText<sup>9+</sup>](#gettext9).

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the text information of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    let text = await button.getText();
}
```

### getType<sup>(deprecated)</sup>

getType(): Promise\<string>

Obtains the type of this component.

This API is deprecated since API version 9. You are advised to use [getType<sup>9+</sup>](#gettype9).

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                         |
| ---------------- | ----------------------------- |
| Promise\<string> | Promise used to return the type of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    let type = await button.getType();
}
```

### isClickable<sup>(deprecated)</sup>

isClickable(): Promise\<boolean>

Obtains the clickable status of this component.

This API is deprecated since API version 9. You are advised to use [isClickable<sup>9+</sup>](#isclickable9).

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is clickable, and **false** means the opposite.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    if(await button.isClickable()) {
        console.info('This button can be Clicked');
    } else {
        console.info('This button can not be Clicked');
    }
}
```

### isScrollable<sup>(deprecated)</sup>

isScrollable(): Promise\<boolean>

Obtains the scrollable status of this component.

This API is deprecated since API version 9. You are advised to use [isScrollable<sup>9+</sup>](#isscrollable9).

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is scrollable, and **false** means the opposite.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let scrollBar = await driver.findComponent(BY.scrollable(true));
    if(await scrollBar.isScrollable()) {
        console.info('This scrollBar can be operated');
    } else {
        console.info('This scrollBar can not be operated');
    }
}
```


### isEnabled<sup>(deprecated)</sup>

isEnabled(): Promise\<boolean>

Obtains the enabled status of this component.

This API is deprecated since API version 9. You are advised to use [isEnabled<sup>9+</sup>](#isenabled9).

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                      |
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is enabled, and **false** means the opposite.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    if(await button.isEnabled()) {
        console.info('This button can be operated');
    } else {
        console.info('This button can not be operated');
    }
}

```

### isFocused<sup>(deprecated)</sup>

isFocused(): Promise\<boolean>

Obtains the focused status of this component.

This API is deprecated since API version 9. You are advised to use [isFocused<sup>9+</sup>](#isfocused9).

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the target component is focused, and **false** means the opposite.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    if(await button.isFocused()) {
        console.info('This button is focused');
    } else {
        console.info('This button is not focused');
	}
}
```

### isSelected<sup>(deprecated)</sup>

isSelected(): Promise\<boolean>

Obtains the selected status of this component.

This API is deprecated since API version 9. You are advised to use [isSelected<sup>9+</sup>](#isselected9).

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                 |
| ----------------- | ----------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is selected, and **false** means the opposite.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    if(await button.isSelected()) {
        console.info('This button is selected');
    } else {
        console.info('This button is not selected');
    }
}
```

### inputText<sup>(deprecated)</sup>

inputText(text: string): Promise\<void>

Enters text into this component (available for text boxes).

This API is deprecated since API version 9. You are advised to use [inputText<sup>9+</sup>](#inputtext9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| text   | string | Yes  | Text to enter.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let text = await driver.findComponent(BY.text('hello world'));
    await text.inputText('123');
}
```

### scrollSearch<sup>(deprecated)</sup>

scrollSearch(by: By): Promise\<UiComponent>

Scrolls on this component to search for the target component (applicable to components that support scrolling, such as **\<List>**).

This API is deprecated since API version 9. You are advised to use [scrollSearch<sup>9+</sup>](#scrollsearch9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type               | Mandatory| Description                |
| ------ | ------------------- | ---- | -------------------- |
| by     | [By](#bydeprecated) | Yes  | Attributes of the target component.|

**Return value**

| Type                                           | Description                                 |
| ----------------------------------------------- | ------------------------------------- |
| Promise\<[UiComponent](#uicomponentdeprecated)> | Promise used to return the target component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let scrollBar = await driver.findComponent(BY.type('Scroll'));
    let button = await scrollBar.scrollSearch(BY.text('next page'));
}
```

## UiDriver<sup>(deprecated)</sup>

The **UiDriver** class is the main entry to the UiTest framework. It provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot.
All APIs provided by this class, except for **UiDriver.create()**, use a promise to return the result and must be invoked using **await**.

This API is deprecated since API version 9. You are advised to use [Driver<sup>9+</sup>](#driver9) instead.

### create<sup>(deprecated)</sup>

static create(): UiDriver

Creates a **UiDriver** object and returns the object created. This API is a static API.

This API is deprecated since API version 9. You are advised to use [create<sup>9+</sup>](#create9).

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type    | Description                    |
| -------- | ------------------------ |
| UiDriver | Returns the **UiDriver** object created.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
}
```

### delayMs<sup>(deprecated)</sup>

delayMs(duration: number): Promise\<void>

Delays this **UiDriver** object within the specified duration.

This API is deprecated since API version 9. You are advised to use [delayMs<sup>9+</sup>](#delayms9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description        |
| -------- | ------ | ---- | ------------ |
| duration | number | Yes  | Duration of time.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.delayMs(1000);
}
```

### findComponent<sup>(deprecated)</sup>

findComponent(by: By): Promise\<UiComponent>

Searches this **UiDriver** object for the target component that matches the given attributes.

This API is deprecated since API version 9. You are advised to use [findComponent<sup>9+</sup>](#findcomponent9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type               | Mandatory| Description                |
| ------ | ------------------- | ---- | -------------------- |
| by     | [By](#bydeprecated) | Yes  | Attributes of the target component.|

**Return value**

| Type                                           | Description                             |
| ----------------------------------------------- | --------------------------------- |
| Promise\<[UiComponent](#uicomponentdeprecated)> | Promise used to return the found component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.text('next page'));
}
```

### findComponents<sup>(deprecated)</sup>

findComponents(by: By): Promise\<Array\<UiComponent>>

Searches this **UiDriver** object for all components that match the given attributes.

This API is deprecated since API version 9. You are advised to use [findComponents<sup>9+</sup>](#findcomponents9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type               | Mandatory| Description                |
| ------ | ------------------- | ---- | -------------------- |
| by     | [By](#bydeprecated) | Yes  | Attributes of the target component.|

**Return value**

| Type                                                   | Description                                   |
| ------------------------------------------------------- | --------------------------------------- |
| Promise\<Array\<[UiComponent](#uicomponentdeprecated)>> | Promise used to return a list of found components.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    let buttonList = await driver.findComponents(BY.text('next page'));
}
```

### assertComponentExist<sup>(deprecated)</sup>

assertComponentExist(by: By): Promise\<void>

Asserts that a component that matches the given attributes exists on the current page. If the component does not exist, the API throws a JS exception, causing the current test case to fail.

This API is deprecated since API version 9. You are advised to use [assertComponentExist<sup>9+</sup>](#assertcomponentexist9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type               | Mandatory| Description                |
| ------ | ------------------- | ---- | -------------------- |
| by     | [By](#bydeprecated) | Yes  | Attributes of the target component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.assertComponentExist(BY.text('next page'));
}
```

### pressBack<sup>(deprecated)</sup>

pressBack(): Promise\<void>

Presses the Back button on this **UiDriver** object.

This API is deprecated since API version 9. You are advised to use [pressBack<sup>9+</sup>](#pressback9).

**System capability**: SystemCapability.Test.UiTest

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.pressBack();
}
```

### triggerKey<sup>(deprecated)</sup>

triggerKey(keyCode: number): Promise\<void>

Triggers the key of this **UiDriver** object that matches the given key code.

This API is deprecated since API version 9. You are advised to use [triggerKey<sup>9+</sup>](#triggerkey9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ------------- |
| keyCode | number | Yes  | Key code.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.triggerKey(123);
}
```


### click<sup>(deprecated)</sup>

click(x: number, y: number): Promise\<void>

Clicks a specific point of this **UiDriver** object based on the given coordinates.

This API is deprecated since API version 9. You are advised to use [click<sup>9+</sup>](#click9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.click(100,100);
}
```

### doubleClick<sup>(deprecated)</sup>

doubleClick(x: number, y: number): Promise\<void>

Double-clicks a specific point of this **UiDriver** object based on the given coordinates.

This API is deprecated since API version 9. You are advised to use [doubleClick<sup>9+</sup>](#doubleclick9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.doubleClick(100,100);
}
```

### longClick<sup>(deprecated)</sup>

longClick(x: number, y: number): Promise\<void>

Long-clicks a specific point of this **UiDriver** object based on the given coordinates.

This API is deprecated since API version 9. You are advised to use [longClick<sup>9+</sup>](#longclick9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.longClick(100,100);
}
```

### swipe<sup>(deprecated)</sup>

swipe(startx: number, starty: number, endx: number, endy: number): Promise\<void>

Swipes on this **UiDriver** object from the start point to the end point based on the given coordinates.

This API is deprecated since API version 9. You are advised to use [swipe<sup>9+</sup>](#swipe9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| startx | number | Yes  | X-coordinate of the start point.|
| starty | number | Yes  | Y-coordinate of the start point.|
| endx   | number | Yes  | X-coordinate of the end point.|
| endy   | number | Yes  | Y-coordinate of the end point.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.swipe(100,100,200,200);
}
```

### screenCap<sup>(deprecated)</sup>

screenCap(savePath: string): Promise\<boolean>

Captures the current screen of this **UiDriver** object and saves it as a PNG image to the given save path.

This API is deprecated since API version 9. You are advised to use [screenCap<sup>9+</sup>](#screencap9).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description          |
| -------- | ------ | ---- | -------------- |
| savePath | string | Yes  | File save path.|

**Return value**

| Type             | Description                                  |
| ----------------- | -------------------------------------- |
| Promise\<boolean> | Promise used to return the operation result. The value **true** means that the operation is successful.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.screenCap('/local/tmp/1.png');
}
```
