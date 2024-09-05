# @ohos.UiTest

The **UiTest** module provides APIs that you can use to simulate UI actions during testing, such as clicks, double-clicks, long-clicks, and swipes.

This module provides the following functions:

- [On<sup>9+</sup>](#on9): provides UI component feature description APIs for component filtering and matching.
- [Component<sup>9+</sup>](#component9): represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
- [Driver<sup>9+</sup>](#driver9): works as the entry class and provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot.
- [UiWindow<sup>9+</sup>](#uiwindow9): works as the entry class and provides APIs for obtaining window attributes, dragging windows, and adjusting window sizes.
- [By<sup>(deprecated)</sup>](#bydeprecated): provides UI component feature description APIs for component filtering and matching. This class is deprecated since API version 9. You are advised to use [On<sup>9+</sup>](#on9) instead.
- [UiComponent<sup>(deprecated)</sup>](#uicomponentdeprecated): represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection. This class is deprecated since API version 9. You are advised to use [Component<sup>9+</sup>](#component9) instead.
- [UiDriver<sup>(deprecated)</sup>](#uidriverdeprecated): works as the entry class and provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot. This class is deprecated since API version 9. You are advised to use [Driver<sup>9+</sup>](#driver9) instead.

> **NOTE**
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module can be used only in <!--RP1-->[arkxtest](../../application-test/arkxtest-guidelines.md)<!--RP1End-->.
> - The APIs of this module do not support concurrent calls.


## Modules to Import

```ts
import { UiComponent, UiDriver, Component, Driver, UiWindow, ON, BY, MatchPattern, DisplayRotation, ResizeDirection, WindowMode, PointerMatrix, UiDirection, MouseButton, UIElementInfo, UIEventObserver } from '@kit.TestKit';
```

## MatchPattern

Enumerates the match patterns supported for component attributes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

| Name       | Value  | Description          |
| ----------- | ---- | -------------- |
| EQUALS      | 0    | Equals the given value.  |
| CONTAINS    | 1    | Contains the given value.  |
| STARTS_WITH | 2    | Starts with the given value.|
| ENDS_WITH   | 3    | Ends with the given value.|

## ResizeDirection<sup>9+</sup>

Enumerates the directions in which a window can be resized.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

| Name| Type  | Readable| Writable| Description            |
| ---- | ------ | ---- | ---- | ---------------- |
| x    | number | Yes  | No  | X coordinate of a point.|
| y    | number | Yes  | No  | Y coordinate of a point.|

## Rect<sup>9+</sup>

Provides bounds information of a component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

| Name  | Type  | Readable| Writable| Description                     |
| ------ | ------ | ---- | ---- | ------------------------- |
| left   | number | Yes  | No  | X coordinate of the upper left corner of the component bounds.|
| top    | number | Yes  | No  | Y coordinate of the upper left corner of the component bounds.|
| right  | number | Yes  | No  | X coordinate of the lower right corner of the component bounds.|
| bottom | number | Yes  | No  | Y coordinate of the lower right corner of the component bounds.|

## WindowMode<sup>9+</sup>

Enumerates the window modes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| FULLSCREEN | 0    | Full-screen mode.|
| PRIMARY    | 1    | Primary window mode.  |
| SECONDARY  | 2    | Secondary window mode.|
| FLOATING   | 3    | Floating window mode.|

## DisplayRotation<sup>9+</sup>

Describes the display rotation of the device.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

| Name        | Value  | Description                                    |
| ------------ | ---- | ---------------------------------------- |
| ROTATION_0   | 0    | The device display is not rotated and is in its original vertical orientation.    |
| ROTATION_90  | 1    | The device display rotates 90° clockwise and is in landscape orientation.     |
| ROTATION_180 | 2    | The device display rotates 180° clockwise and is in reverse vertical orientation.|
| ROTATION_270 | 3    | The device display rotates 270° clockwise and is in reverse landscape orientation.|

## WindowFilter<sup>9+</sup>

Provides the flag attributes of this window.

**System capability**: SystemCapability.Test.UiTest

| Name                | Type   | Readable| Writable| Description                                                        |
| -------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName           | string  | Yes  | No  | Bundle name of the application to which the window belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| title                | string  | Yes  | No  | Title of the window.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| focused              | boolean | Yes  | No  | Whether the window is in focused state.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| actived(deprecated)  | boolean | Yes  | No  | Whether the window is interacting with the user.<br>Since API version 11, this parameter is renamed **active**.|
| active<sup>11+</sup> | boolean | Yes  | No  | Whether the window is interacting with the user.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

## UiDirection<sup>10+</sup>

Describes the direction of a UI operation such as fling.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

| Name | Value  | Description  |
| ----- | ---- | ------ |
| LEFT  | 0    | Leftward.|
| RIGHT | 1    | Rightward.|
| UP    | 2    | Upward.|
| DOWN  | 3    | Downward.|

## MouseButton<sup>10+</sup>

Describes the injected simulated mouse button.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

| Name               | Value  | Description        |
| ------------------- | ---- | ------------ |
| MOUSE_BUTTON_LEFT   | 0    | Left button on the mouse.  |
| MOUSE_BUTTON_RIGHT  | 1    | Right button on the mouse.  |
| MOUSE_BUTTON_MIDDLE | 2    | Middle button on the mouse.|

## UIElementInfo<sup>10+</sup>

Provides information about the UI event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

| Name      | Type  | Readable| Writable| Description                 |
| ---------- | ------ | ---- | ---- | --------------------- |
| bundleName | string | Yes  | No  | Bundle name of the home application.     |
| type       | string | Yes  | No  | Component or window type.      |
| text       | string | Yes  | No  | Text information of the component or window.|

## On<sup>9+</sup>

Since API version 9, the UiTest framework provides a wide range of UI component feature description APIs in the **On** class to filter and match components.<br>
The APIs provided by the **On** class exhibit the following features:<br>1. Allow one or more attributes as the match conditions. For example, you can specify both the **text** and **id** attributes to find the target component.<br>2. Provide multiple match patterns for component attributes.<br>3. Support absolute positioning and relative positioning for components. APIs such as [ON.isBefore](#isbefore9) and [ON.isAfter](#isafter9) can be used to specify the features of adjacent components to assist positioning.<br>All APIs provided in the **On** class are synchronous. You are advised to use the static constructor **ON** to create an **On** object in chain mode.

```ts
import { ON } from '@kit.TestKit';
ON.text('123').type('Button');
```

### text<sup>9+</sup>

text(txt: string, pattern?: MatchPattern): On

Specifies the text attribute of the target component. Multiple match patterns are supported.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.text('123'); // Use the static constructor ON to create an On object and specify the text attribute of the target component.
```

### id<sup>9+</sup>

id(id: string): On

Specifies the ID attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| id     | string | Yes  | Component ID.|

**Return value**

| Type      | Description                            |
| ---------- | -------------------------------- |
| [On](#on9) | **On** object that matches the ID attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.id('123'); // Use the static constructor ON to create an On object and specify the id attribute of the target component.
```


### type<sup>9+</sup>

type(tp: string): On

Specifies the type attribute of the target component.

>**NOTE**
>
>You can define the type of the component, and you can use [DevEco Testing](https://developer.huawei.com/consumer/cn/download) to query the type information of the component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| tp     | string | Yes  | Component type.|

**Return value**

| Type      | Description                                    |
| ---------- | ---------------------------------------- |
| [On](#on9) | **On** object that matches the type attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.type('Button'); // Use the static constructor ON to create an On object and specify the type attribute of the target component.
```


### clickable<sup>9+</sup>

clickable(b?: boolean): On

Specifies the clickable attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Clickable status of the target component.<br>**true**: clickable.<br>**false**: not clickable.<br> Default value: **true**|

**Return value**

| Type      | Description                                      |
| ---------- | ------------------------------------------ |
| [On](#on9) | **On** object that matches the clickable attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.clickable(true); // Use the static constructor ON to create an On object and specify the clickable attribute of the target component.
```

### longClickable<sup>9+</sup>

longClickable(b?: boolean): On

Specifies the long-clickable attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Long-clickable status of the target component.<br>**true**: long-clickable.<br>**false**: not long-clickable.<br> Default value: **true**|

**Return value**

| Type      | Description                                          |
| ---------- | ---------------------------------------------- |
| [On](#on9) | **On** object that matches the long-clickable attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.longClickable(true); // Use the static constructor ON to create an On object and specify the longClickable attribute of the target component.
```


### scrollable<sup>9+</sup>

scrollable(b?: boolean): On

Specifies the scrollable attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                       |
| ------ | ------- | ---- | ----------------------------------------------------------- |
| b      | boolean | No  | Scrollable status of the target component.<br>**true**: scrollable.<br>**false**: not scrollable.<br> Default value: **true**|

**Return value**

| Type      | Description                                      |
| ---------- | ------------------------------------------ |
| [On](#on9) | **On** object that matches the scrollable attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.scrollable(true); // Use the static constructor ON to create an On object and specify the scrollable attribute of the target component.
```

### enabled<sup>9+</sup>

enabled(b?: boolean): On

Specifies the enabled attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                     |
| ------ | ------- | ---- | --------------------------------------------------------- |
| b      | boolean | No  | Enabled status of the target component.<br>**true**: enabled.<br>**false**: not enabled.<br> Default value: **true**|

**Return value**

| Type      | Description                                    |
| ---------- | ---------------------------------------- |
| [On](#on9) | **On** object that matches the enabled attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.enabled(true); // Use the static constructor ON to create an On object and specify the enabled attribute of the target component.
```

### focused<sup>9+</sup>

focused(b?: boolean): On

Specifies the focused attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                 |
| ------ | ------- | ---- | ----------------------------------------------------- |
| b      | boolean | No  | Focused status of the target component.<br>**true**: focused.<br>**false**: not focused.<br> Default value: **true**|

**Return value**

| Type      | Description                                    |
| ---------- | ---------------------------------------- |
| [On](#on9) | **On** object that matches the focused attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.focused(true); // Use the static constructor ON to create an On object and specify the focused attribute of the target component.
```

### selected<sup>9+</sup>

selected(b?: boolean): On

Specifies the selected attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Selected status of the target component.<br>**true**: selected.<br>**false**: not selected.<br> Default value: **true**|

**Return value**

| Type      | Description                                      |
| ---------- | ------------------------------------------ |
| [On](#on9) | **On** object that matches the selected attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.selected(true); // Use the static constructor ON to create an On object and specify the selected attribute of the target component.
```

### checked<sup>9+</sup>

checked(b?: boolean): On

Specifies the checked attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Checked status of the target component.<br>**true**: checked.<br>**false**: not checked.<br> Default value: **false**|

**Return value**

| Type      | Description                                      |
| ---------- | ------------------------------------------ |
| [On](#on9) | **On** object that matches the checked attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.checked(true); // Use the static constructor ON to create an On object and specify the checked attribute of the target component.
```

### checkable<sup>9+</sup>

checkable(b?: boolean): On

Specifies the checkable attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Checkable status of the target component.<br>**true**: checkable.<br>**false**: not checkable.<br> Default value: **false**|

**Return value**

| Type      | Description                                        |
| ---------- | -------------------------------------------- |
| [On](#on9) | **On** object that matches the checkable attribute of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. 1. Incorrect parameter types; 2. Parameter verification failed. |

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.checkable(true); // Use the static constructor ON to create an On object and specify the checkable attribute of the target component.
```

### isBefore<sup>9+</sup>

isBefore(on: On): On

Specifies that the target component is located before the given attribute component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Information about the attribute component.|

**Return value**

| Type      | Description                                                |
| ---------- | ---------------------------------------------------- |
| [On](#on9) | **On** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';

// Use the static constructor ON to create an On object and specify that the target component is located before the given attribute component.
let on:On = ON.type('Button').isBefore(ON.text('123')); // Search for the first <Button> component located before the component whose text is 123.
```

### isAfter<sup>9+</sup>

isAfter(on: On): On

Specifies that the target component is located after the given attribute component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Information about the attribute component.|

**Return value**

| Type      | Description                                                |
| ---------- | ---------------------------------------------------- |
| [On](#on9) | **On** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';

// Use the static constructor ON to create an On object and specify that the target component is located after the given attribute component.
let on:On = ON.type('Text').isAfter(ON.text('123'))  // Search for the first <Text> component located after the component whose text is 123.
```

### within<sup>10+</sup>

within(on: On): On

Specifies that the target component is located within the given attribute component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Information about the attribute component.|

**Return value**

| Type      | Description                                              |
| ---------- | -------------------------------------------------- |
| [On](#on9) | **On** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
// Use the static constructor ON to create an On object and specify that the target component is located within the given attribute component.
let on:On = ON.text('java').within(ON.type('Scroll'));  // Search for the child component whose text is java within the <Scroller> component.
```

### inWindow<sup>10+</sup>

inWindow(bundleName: string): On;

Specifies that the target component is located within the given application window.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name    | Type  | Mandatory| Description            |
| ---------- | ------ | ---- | ---------------- |
| bundleName | string | Yes  | Bundle name of the application window.|

**Return value**

| Type      | Description                                          |
| ---------- | ---------------------------------------------- |
| [On](#on9) | **On** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.inWindow('com.uitestScene.acts'); // Use the static constructor ON to create an On object and specify that the target component is located within the given application window.
```

### description<sup>11+</sup>

description(val: string, pattern?: MatchPattern): On

Specifies the description of the target component. Multiple match patterns are supported.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type                         | Mandatory| Description                                               |
| ------- | ----------------------------- | ---- | --------------------------------------------------- |
| val     | string                        | Yes  | Description of the component.                                   |
| pattern | [MatchPattern](#matchpattern) | No  | Match pattern. The default value is [EQUALS](#matchpattern).|

**Return value**

| Type      | Description                                     |
| ---------- | ----------------------------------------- |
| [On](#on9) | **On** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';
let on:On = ON.description('123'); // Use the static constructor ON to create an On object and specify the description attribute of the target component.
```

## Component<sup>9+</sup>

Represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

### click<sup>9+</sup>

click(): Promise\<void>

Clicks this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Driver, ON, Component } from '@kit.TestKit';
async function demo() {
  let driver:Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  await button.click();
}
```

### doubleClick<sup>9+</sup>

doubleClick(): Promise\<void>

Double-clicks this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import {Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  await button.doubleClick();
}
```

### longClick<sup>9+</sup>

longClick(): Promise\<void>

Long-clicks this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  await button.longClick();
}
```

### getId<sup>9+</sup>

getId(): Promise\<string>

Obtains the ID of this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                           |
| ---------------- | ------------------------------- |
| Promise\<string> | Promise used to return the ID of the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  let id = await button.getId();
}
```

### getText<sup>9+</sup>

getText(): Promise\<string>

Obtains the text information of this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the text information of the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  let text = await button.getText();
}
```

### getType<sup>9+</sup>

getType(): Promise\<string>

Obtains the type of this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                         |
| ---------------- | ----------------------------- |
| Promise\<string> | Promise used to return the type of the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  let type = await button.getType();
}
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

Obtains the bounds of this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                    | Description                                 |
| ------------------------ | ------------------------------------- |
| Promise\<[Rect](#rect9)> | Promise used to return the bounds of the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  let rect = await button.getBounds();
}
```

### getBoundsCenter<sup>9+</sup>

getBoundsCenter(): Promise\<Point>

Obtains the information about the center of the bounding box around this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                      | Description                                           |
| -------------------------- | ----------------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the information about the center of the bounding box around the component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  let point = await button.getBoundsCenter();
}
```

### isClickable<sup>9+</sup>

isClickable(): Promise\<boolean>

Obtains the clickable status of this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is clickable, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                              |
| ----------------- |--------------------------------------------------|
| Promise\<boolean> | Promise used to return the long-clickable status of the component. The value **true** means that the component is long-clickable, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the checked status of the component. The value **true** means that the component is checked, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let checkBox: Component = await driver.findComponent(ON.type('Checkbox'));
  if(await checkBox.isChecked()) {
    console.info('This checkBox is checked');
  } else {
    console.info('This checkBox is not checked');
  }
}
```

### isCheckable<sup>9+</sup>

isCheckable(): Promise\<boolean>

Obtains the checkable status of this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the checkable status of the component. The value **true** means that the component is checkable, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let checkBox: Component = await driver.findComponent(ON.type('Checkbox'));
  if(await checkBox.isCheckable()) {
    console.info('This checkBox is checkable');
  } else {
    console.info('This checkBox is not checkable');
  }
}
```

### isScrollable<sup>9+</sup>

isScrollable(): Promise\<boolean>

Obtains the scrollable status of this component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is scrollable, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let scrollBar: Component = await driver.findComponent(ON.scrollable(true));
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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                      |
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the focused status of the component. The value **true** means that the component is focused, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                               |
| ----------------- | --------------------------------------------------- |
| Promise\<boolean> | Promise used to return the selected status of the component. The value **true** means that the component is selected, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| text   | string | Yes  | Text to enter, which can contain English and special characters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let text: Component = await driver.findComponent(ON.text('hello world'));
  await text.inputText('123');
}
```

### clearText<sup>9+</sup>

clearText(): Promise\<void>

Clears text in this component. This API is applicable to text boxes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**
For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let text: Component = await driver.findComponent(ON.text('hello world'));
  await text.clearText();
}
```

### scrollSearch<sup>9+</sup>

scrollSearch(on: On): Promise\<Component>

Scrolls on this component to search for the target component. This API is applicable to components that support scrolling.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let scrollBar: Component = await driver.findComponent(ON.type('Scroll'));
  let button = await scrollBar.scrollSearch(ON.text('next page'));
}
```

### scrollToTop<sup>9+</sup>

scrollToTop(speed?: number): Promise\<void>

Scrolls to the top of this component. This API is applicable to components that support scrolling.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| speed  | number | No  | Scroll speed, in pixel/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let scrollBar: Component = await driver.findComponent(ON.type('Scroll'));
  await scrollBar.scrollToTop();
}
```

### scrollToBottom<sup>9+</sup>

scrollToBottom(speed?: number): Promise\<void>

Scrolls to the bottom of this component. This API is applicable to components that support scrolling.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| speed  | number | No  | Scroll speed, in pixel/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let scrollBar: Component = await driver.findComponent(ON.type('Scroll'));
  await scrollBar.scrollToBottom();
}
```

### dragTo<sup>9+</sup>

dragTo(target: Component): Promise\<void>

Drags this component to the target component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                    | Mandatory| Description      |
| ------ | ------------------------ | ---- | ---------- |
| target | [Component](#component9) | Yes  | Target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  let text: Component = await driver.findComponent(ON.text('hello world'));
  await button.dragTo(text);
}
```

### pinchOut<sup>9+</sup>

pinchOut(scale: number): Promise\<void>

Pinches a component to scale it up to the specified ratio.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| scale  | number | Yes  | Scale factor, which is a value greater than 1.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let image: Component = await driver.findComponent(ON.type('Image'));
  await image.pinchOut(1.5);
}
```

### pinchIn<sup>9+</sup>

pinchIn(scale: number): Promise\<void>

Pinches a component to scale it down to the specified ratio.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| scale  | number | Yes  | Scale factor, which is a value ranging from 0 to 1.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let image: Component = await driver.findComponent(ON.type('Image'));
  await image.pinchIn(0.5);
}
```

### getDescription<sup>11+</sup>

getDescription(): Promise\<string>

Obtains the description of this component. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the description of the component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 17000004 | The window or component is invisible or destroyed.                  |

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.type('Button'));
  let description = await button.getDescription();
}
```

## Driver<sup>9+</sup>

The **Driver** class is the main entry to the UiTest framework. It provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot.
All APIs provided by this class, except **Driver.create()**, use a promise to return the result and must be invoked using **await**.

### create<sup>9+</sup>

static create(): Driver

Creates a **Driver** object and returns the object created. This API is a static API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type| Description          |
| -------- | ---------------------- |
| Driver   | **Driver** object created.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17000001 | Initialization failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
}
```

### delayMs<sup>9+</sup>

delayMs(duration: number): Promise\<void>

Delays this **Driver** object within the specified duration.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                           |
| -------- | ------ | ---- | ------------------------------- |
| duration | number | Yes  | Duration of time, in ms. The value must be greater than or equal to 0.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.delayMs(1000);
}
```

### findComponent<sup>9+</sup>

findComponent(on: On): Promise\<Component>

Searches this **Driver** object for the target component that matches the given attributes.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.findComponent(ON.text('next page'));
}
```

### findComponents<sup>9+</sup>

findComponents(on: On): Promise\<Array\<Component>>

Searches this **Driver** object for all components that match the given attributes.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let buttonList: Array<Component> = await driver.findComponents(ON.text('next page'));
}
```

### findWindow<sup>9+</sup>

findWindow(filter: WindowFilter): Promise\<UiWindow>

Searches for the window that matches the specified attributes.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
}
```

### waitForComponent<sup>9+</sup>

waitForComponent(on: On, time: number): Promise\<Component>

Searches this **Driver** object for the target component that matches the given attributes within the specified duration.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                                     |
| ------ | ---------- | ---- | ----------------------------------------- |
| On     | [On](#on9) | Yes  | Attributes of the target component.                     |
| time   | number     | Yes  | Duration for searching for the target component, in ms. The value must be greater than or equal to 0.|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise\<[Component](#component9)> | Promise used to return the found component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let button: Component = await driver.waitForComponent(ON.text('next page'),500);
}
```

### assertComponentExist<sup>9+</sup>

assertComponentExist(on: On): Promise\<void>

Asserts that a component that matches the given attributes exists on the current page.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the target component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000003 | Assertion failed.   |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.assertComponentExist(ON.text('next page'));
}
```

### pressBack<sup>9+</sup>

pressBack(): Promise\<void>

Presses the Back button on this **Driver** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.pressBack();
}
```

### triggerKey<sup>9+</sup>

triggerKey(keyCode: number): Promise\<void>

Triggers the key of this **Driver** object that matches the given key code.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ------------- |
| keyCode | number | Yes  | Key code.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.triggerKey(123);
}
```

### triggerCombineKeys<sup>9+</sup>

triggerCombineKeys(key0: number, key1: number, key2?: number): Promise\<void>

Triggers a key combination based on the specified key values. For example, if the value of **Key** is (2072, 2019), the **Driver** object finds and clicks the key combination that matches the value, for example, **Ctrl+C**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| key0   | number | Yes  | The first key value.           |
| key1   | number | Yes  | The second key value.           |
| key2   | number | No  | The third key value. The default value is **0**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.triggerCombineKeys(2072, 2047, 2035);
}
```


### click<sup>9+</sup>

click(x: number, y: number): Promise\<void>

Clicks a specific point of this **Driver** object based on the given coordinates.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| x      | number | Yes  | X coordinate of the end point. The value must be greater than or equal to 0.|
| y      | number | Yes  | Y coordinate of the end point. The value must be greater than or equal to 0.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.click(100,100);
}
```

### doubleClick<sup>9+</sup>

doubleClick(x: number, y: number): Promise\<void>

Double-clicks a specific point of this **Driver** object based on the given coordinates.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| x      | number | Yes  | X coordinate of the end point. The value must be greater than or equal to 0.|
| y      | number | Yes  | Y coordinate of the end point. The value must be greater than or equal to 0.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.doubleClick(100,100);
}
```

### longClick<sup>9+</sup>

longClick(x: number, y: number): Promise\<void>

Long-clicks a specific point of this **Driver** object based on the given coordinates.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| x      | number | Yes  | X coordinate of the end point. The value must be greater than or equal to 0.|
| y      | number | Yes  | Y coordinate of the end point. The value must be greater than or equal to 0.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.longClick(100,100);
}
```

### swipe<sup>9+</sup>

swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Swipes on this **Driver** object from the given start point to the given end point.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| startx | number | Yes  | X coordinate of the start point. The value must be greater than or equal to 0.             |
| starty | number | Yes  | Y coordinate of the start point. The value must be greater than or equal to 0.             |
| endx   | number | Yes  | X coordinate of the end point. The value must be greater than or equal to 0.             |
| endy   | number | Yes  | Y coordinate of the end point. The value must be greater than or equal to 0.             |
| speed  | number | No  | Scroll speed, in pixel/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.swipe(100,100,200,200,600);
}
```

### drag<sup>9+</sup>

drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Drags this **Driver** object from the given start point to the given end point.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| startx | number | Yes  | X coordinate of the start point. The value must be greater than or equal to 0.             |
| starty | number | Yes  | Y coordinate of the start point. The value must be greater than or equal to 0.             |
| endx   | number | Yes  | X coordinate of the end point. The value must be greater than or equal to 0.             |
| endy   | number | Yes  | Y coordinate of the end point. The value must be greater than or equal to 0.             |
| speed  | number | No  | Scroll speed, in pixel/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.drag(100,100,200,200,600);
}
```

### screenCap<sup>9+</sup>

screenCap(savePath: string): Promise\<boolean>

Captures the current screen of this **Driver** object and saves it as a PNG image to the given save path.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                      |
| -------- | ------ | ---- | ------------------------------------------ |
| savePath | string | Yes  | File save path. The path must be the sandbox path of the current application.|

**Return value**

| Type             | Description                                  |
| ----------------- | -------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the operation is successful.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.screenCap('/data/storage/el2/base/cache/1.png');
}
```

### setDisplayRotation<sup>9+</sup>

setDisplayRotation(rotation: DisplayRotation): Promise\<void>

Sets the display rotation of the current scene. It applies to rotatable scenarios.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type                                | Mandatory| Description            |
| -------- | ------------------------------------ | ---- | ---------------- |
| rotation | [DisplayRotation](#displayrotation9) | Yes  | Display rotation of the device.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, DisplayRotation } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.setDisplayRotation(DisplayRotation.ROTATION_180);
}
```

### getDisplayRotation<sup>9+</sup>

getDisplayRotation(): Promise\<DisplayRotation>

Obtains the display rotation of the current device.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                                          | Description                                   |
| ---------------------------------------------- | --------------------------------------- |
| Promise\<[DisplayRotation](#displayrotation9)> | Promise used to return the display rotation of the current device.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |

**Example**

```ts
import { DisplayRotation, Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let rotation: DisplayRotation = await driver.getDisplayRotation();
}
```

### setDisplayRotationEnabled<sup>9+</sup>

setDisplayRotationEnabled(enabled: boolean): Promise\<void>

Enables or disables display rotation.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type   | Mandatory| Description                                                   |
| ------- | ------- | ---- | ------------------------------------------------------- |
| enabled | boolean | Yes  | Whether to enable display rotation. The value **true** means to enable display rotation, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.setDisplayRotationEnabled(false);
}
```

### getDisplaySize<sup>9+</sup>

getDisplaySize(): Promise\<Point>

Obtains the display size of the current device.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                      | Description                                   |
| -------------------------- | --------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the display size of the current device.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |

**Example**

```ts
import { Driver, } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  let size = await driver.getDisplaySize();
}
```

### getDisplayDensity<sup>9+</sup>

getDisplayDensity(): Promise\<Point>

Obtains the display density of the current device.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                      | Description                                     |
| -------------------------- | ----------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the display density of the current device.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let density = await driver.getDisplayDensity();
}
```

### wakeUpDisplay<sup>9+</sup>

wakeUpDisplay(): Promise\<void>

Wakes up the device display.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.wakeUpDisplay();
}
```

### pressHome<sup>9+</sup>

pressHome(): Promise\<void>

Returns to the home screen.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.pressHome();
}
```

### waitForIdle<sup>9+</sup>

waitForIdle(idleTime: number, timeout: number): Promise\<boolean>

Checks whether all components on the current page are idle.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| idleTime | number | Yes  | Idle time threshold, in ms. If the duration for which a component remains inactive reaches this threshold, it is considered as idle. The value must be greater than or equal to 0.|
| timeout  | number | Yes  | Maximum idle waiting time, in ms. The value must be greater than or equal to 0.                   |

**Return value**

| Type             | Description                                               |
| ----------------- | --------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let idled:boolean = await driver.waitForIdle(4000,5000);
}
```

### fling<sup>9+</sup>

fling(from: Point, to: Point, stepLen: number, speed: number): Promise\<void>

Simulates a fling operation on the screen.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type            | Mandatory| Description                                                        |
| ------- | ---------------- | ---- | ------------------------------------------------------------ |
| from    | [Point](#point9) | Yes  | Coordinates of the point where the finger touches the screen.                                  |
| to      | [Point](#point9) | Yes  | Coordinates of the point where the finger leaves the screen.                                    |
| stepLen | number           | Yes  | Fling step length, in pixels.                                    |
| speed   | number           | Yes  | Fling speed, in pixel/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.fling({x: 500, y: 480},{x: 450, y: 480},5,600);
}
```

### injectMultiPointerAction<sup>9+</sup>

injectMultiPointerAction(pointers: PointerMatrix, speed?: number): Promise\<boolean>

Injects a multi-touch operation to the device.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| pointers | [PointerMatrix](#pointermatrix9) | Yes  | Scroll trajectory, including the number of fingers and an array of coordinates along the trajectory.                  |
| speed    | number                           | No  | Scroll speed, in pixel/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value 600 is used.|

**Return value**

| Type             | Description                                 |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, PointerMatrix } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let pointers: PointerMatrix = PointerMatrix.create(2,5);
  pointers.setPoint(0,0,{x:250,y:480});
  pointers.setPoint(0,1,{x:250,y:440});
  pointers.setPoint(0,2,{x:250,y:400});
  pointers.setPoint(0,3,{x:250,y:360});
  pointers.setPoint(0,4,{x:250,y:320});
  pointers.setPoint(1,0,{x:250,y:480});
  pointers.setPoint(1,1,{x:250,y:440});
  pointers.setPoint(1,2,{x:250,y:400});
  pointers.setPoint(1,3,{x:250,y:360});
  pointers.setPoint(1,4,{x:250,y:320});
  await driver.injectMultiPointerAction(pointers);
}
```

### fling<sup>10+</sup>

fling(direction: UiDirection, speed: number): Promise\<void>;

Simulates a fling operation on the screen, in the specified direction and speed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name   | Type                         | Mandatory| Description                                                        |
| --------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| direction | [UiDirection](#uidirection10) | Yes  | Direction of the fling operation.                                            |
| speed     | number                        | Yes  | Fling speed, in pixel/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, UiDirection } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.fling(UiDirection.DOWN, 10000);
}
```

### screenCapture<sup>10+</sup>

screenCapture(savePath: string, rect?: Rect): Promise\<boolean>;

Captures the specified area of the current screen and saves the captured screenshot as a PNG image to the specified path.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type          | Mandatory| Description                                      |
| -------- | -------------- | ---- | ------------------------------------------ |
| savePath | string         | Yes  | File save path. The path must be the sandbox path of the current application.|
| rect     | [Rect](#rect9) | No  | Area of the screen to capture. The default value is the entire screen.                    |

**Return value**

| Type             | Description                                  |
| ----------------- | -------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the operation is successful.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.screenCapture('/data/storage/el2/base/cache/1.png', {left: 0, top: 0, right: 100, bottom: 100});
}
```

### mouseClick<sup>10+</sup>

mouseClick(p: Point, btnId: MouseButton, key1?: number, key2?: number): Promise\<void>;

Injects a mouse click at the specified coordinates, with the optional key or key combination. For example, if the value of **key1** is **2072**, the **Ctrl** button is pressed with the mouse click.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                         | Mandatory| Description                          |
| ------ | ----------------------------- | ---- | ------------------------------ |
| p      | [Point](#point9)              | Yes  | Coordinates of the mouse click.              |
| btnId  | [MouseButton](#mousebutton10) | Yes  | Mouse button pressed.              |
| key1   | number                        | No  | The first key value. The default value is **0**.|
| key2   | number                        | No  | The second key value. The default value is **0**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver,MouseButton } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseClick({x:248, y:194}, MouseButton.MOUSE_BUTTON_LEFT, 2072);
}
```

### mouseScroll<sup>10+</sup>

mouseScroll(p: Point, down: boolean, d: number, key1?: number, key2?: number): Promise\<void>;

Injects a mouse scroll action at the specified coordinates, with the optional key or key combination. For example, if the value of **key1** is **2072**, the **Ctrl** button is pressed with mouse scrolling.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description                                                       |
| ------ | ---------------- | ---- | ----------------------------------------------------------- |
| p      | [Point](#point9) | Yes  | Coordinates of the mouse click.                                           |
| down   | boolean          | Yes  | Whether the mouse wheel scrolls downward.<br>**true**: The mouse wheel scrolls downward.<br>**false**: The mouse wheel scrolls upward.|
| d      | number           | Yes  | Number of cells by which the mouse wheel scrolls. Scrolling by one cell means a 120-pixel offset of the end point.        |
| key1   | number           | No  | The first key value. The default value is **0**.                             |
| key2   | number           | No  | The second key value. The default value is **0**.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseScroll({x:360, y:640}, true, 30, 2072)
}
```

### mouseMoveTo<sup>10+</sup>

mouseMoveTo(p: Point): Promise\<void>;

Moves the cursor to the end point.

**System capability**: SystemCapability.Test.UiTest

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type            | Mandatory| Description          |
| ------ | ---------------- | ---- | -------------- |
| p      | [Point](#point9) | Yes  | Coordinates of the end point.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseMoveTo({x:100, y:100})
}
```

### createUIEventObserver<sup>10+</sup>

createUIEventObserver(): UIEventObserver;

Creates a UI event listener.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                                  | Description                                 |
| ------------------------------------ | ------------------------------------- |
|[UIEventObserver](#uieventobserver10) | UI event listener.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |

**Example**

```ts
import { Driver, UIEventObserver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let observer: UIEventObserver = await driver.createUIEventObserver()
}
```

### mouseScroll<sup>11+</sup>

mouseScroll(p: Point, down: boolean, d: number, key1?: number, key2?: number, speed?: number): Promise\<void>

Injects a mouse scroll action at the specified coordinates. You can specify the key or key combination to work with the action, as well as the scroll speed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description                                                        |
| ------ | ---------------- | ---- | ------------------------------------------------------------ |
| p      | [Point](#point9) | Yes  | Coordinates of the mouse click.                                            |
| down   | boolean          | Yes  | Whether the mouse wheel scrolls downward.<br>**true**: The mouse wheel scrolls downward.<br>**false**: The mouse wheel scrolls upward. |
| d      | number           | Yes  | Number of cells by which the mouse wheel scrolls. Scrolling by one cell means a 120-pixel offset of the end point.         |
| key1   | number           | No  | The first key value. The default value is **0**.                              |
| key2   | number           | No  | The second key value. The default value is **0**.                              |
| speed  | number           | No  | Scroll speed of the mouse wheel, in cells/second.<br>Value range: 1 to 500<br>If the value is not within the range, the default value **20** will be used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseScroll({x:360, y:640}, true, 30, 2072,20)
}
```

### mouseDoubleClick<sup>11+</sup>

mouseDoubleClick(p: Point, btnId: MouseButton, key1?: number, key2?: number): Promise\<void>

Injects a double-click action at the specified coordinates, with the optional key or key combination. For example, if the value of **key** is **2072**, the **Ctrl** button is pressed with the double-click.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                         | Mandatory| Description                          |
| ------ | ----------------------------- | ---- | ------------------------------ |
| p      | [Point](#point9)              | Yes  | Coordinates of the double-click.              |
| btnId  | [MouseButton](#mousebutton10) | Yes  | Mouse button pressed.              |
| key1   | number                        | No  | The first key value. The default value is **0**.|
| key2   | number                        | No  | The second key value. The default value is **0**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver,MouseButton } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseDoubleClick({x:248, y:194}, MouseButton.MOUSE_BUTTON_LEFT, 2072);
}
```

### mouseLongClick<sup>11+</sup>

mouseLongClick(p: Point, btnId: MouseButton, key1?: number, key2?: number): Promise\<void>

Injects a long-click action of the mouse device at the specified coordinates, with the optional key or key combination. For example, if the value of **Key** is **2072**, the **Ctrl** button is long-clicked with the mouse device.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                         | Mandatory| Description                          |
| ------ | ----------------------------- | ---- | ------------------------------ |
| p      | [Point](#point9)              | Yes  | Coordinates of the long-click of the mouse device.              |
| btnId  | [MouseButton](#mousebutton10) | Yes  | Mouse button pressed.              |
| key1   | number                        | No  | The first key value. The default value is **0**.|
| key2   | number                        | No  | The second key value. The default value is **0**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver,MouseButton } from '@kit.TestKit';
async function demo() {
  let driver:Driver = Driver.create();
  await driver.mouseLongClick({x:248, y:194}, MouseButton.MOUSE_BUTTON_LEFT, 2072);
}
```

### mouseMoveWithTrack<sup>11+</sup>

mouseMoveWithTrack(from: Point, to: Point, speed?: number): Promise\<void>

Moves the mouse pointer from the start point to the end point.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description                                                        |
| ------ | ---------------- | ---- | ------------------------------------------------------------ |
| from   | [Point](#point9) | Yes  | Coordinates of the start point.                                                |
| to     | [Point](#point9) | Yes  | Coordinates of the end point.                                                  |
| speed  | number           | No  | Scroll speed, in pixel/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseMoveWithTrack({x:100, y:100},{x:200, y:200},600);
}
```

### mouseDrag<sup>11+</sup>

mouseDrag(from: Point, to: Point, speed?: number): Promise\<void>

Drags the mouse pointer from the start point to the end point.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description                                                        |
| ------ | ---------------- | ---- | ------------------------------------------------------------ |
| from   | [Point](#point9) | Yes  | Coordinates of the start point.                                                |
| to     | [Point](#point9) | Yes  | Coordinates of the end point.                                                  |
| speed  | number           | No  | Scroll speed, in pixel/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value 600 is used.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseDrag({x:100, y:100},{x:200, y:200},600);
}
```

### inputText<sup>11+</sup>

inputText(p: Point, text: string): Promise\<void>

Enters text at the specified point.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description              |
| ------ | ---------------- | ---- | ------------------ |
| p      | [Point](#point9) | Yes  | Coordinates of the end point.|
| text   | string           | Yes  | Text to enter.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';
async function demo() {
  let driver:Driver = Driver.create();
  let text: Component = await driver.findComponent(ON.type('TextInput'));
  let point = await text.getBoundsCenter();
  await driver.inputText(point, '123');
}
```

## PointerMatrix<sup>9+</sup>

Implements a **PointerMatrix** object that stores coordinates and behaviors of each action of each finger in a multi-touch operation.

### create<sup>9+</sup>

static create(fingers: number, steps: number): PointerMatrix

Creates a **PointerMatrix** object and returns the object created. This API is a static API.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { PointerMatrix } from '@kit.TestKit';
async function demo() {
  let pointerMatrix: PointerMatrix = PointerMatrix.create(2,3);
}
```

### setPoint<sup>9+</sup>

setPoint(finger: number, step: number, point: Point): void

Sets the coordinates for the action corresponding to the specified finger and step in the **PointerMatrix** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description                                                      |
| ------ | ---------------- | ---- | ---------------------------------------------------------- |
| finger | number           | Yes  | Sequence number of the finger.                                              |
| step   | number           | Yes  | Sequence number of the step.                                              |
| point  | [Point](#point9) | Yes  | Coordinates of the action. It is recommended that the distance between adjacent coordinate points is within the range of 10 to 80 pixels.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { PointerMatrix } from '@kit.TestKit';
async function demo() {
  let pointers: PointerMatrix = PointerMatrix.create(2,5);
  pointers.setPoint(0,0,{x:250,y:480});
  pointers.setPoint(0,1,{x:250,y:440});
  pointers.setPoint(0,2,{x:250,y:400});
  pointers.setPoint(0,3,{x:250,y:360});
  pointers.setPoint(0,4,{x:250,y:320});
  pointers.setPoint(1,0,{x:250,y:480});
  pointers.setPoint(1,1,{x:250,y:440});
  pointers.setPoint(1,2,{x:250,y:400});
  pointers.setPoint(1,3,{x:250,y:360});
  pointers.setPoint(1,4,{x:250,y:320});
}
```

## UiWindow<sup>9+</sup>

The **UiWindow** class represents a window on the UI and provides APIs for obtaining window attributes, dragging a window, and adjusting the window size.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

### getBundleName<sup>9+</sup>

getBundleName(): Promise\<string>

Obtains the bundle name of the application to which this window belongs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise\<string> | Promise used to return the bundle name.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  let name: string = await window.getBundleName();
}
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

Obtains the bounds information of this window.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                    | Description                             |
| ------------------------ | --------------------------------- |
| Promise\<[Rect](#rect9)> | Promise used to return the bounds information of the window.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  let rect = await window.getBounds();
}
```

### getTitle<sup>9+</sup>

getTitle(): Promise\<string>

Obtains the title of this window.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the title of the window.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  let rect = await window.getTitle();
}
```

### getWindowMode<sup>9+</sup>

getWindowMode(): Promise\<WindowMode>

Obtains the window mode of this window.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                                | Description                                 |
| ------------------------------------ | ------------------------------------- |
| Promise\<[WindowMode](#windowmode9)> | Promise used to return the window mode of the window.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.          |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  let mode = await window.getWindowMode();
}
```

### isFocused<sup>9+</sup>

isFocused(): Promise\<boolean>

Checks whether this window is in focused state.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the window is in focused state, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  let focused = await window.isFocused();
}
```

### isActived<sup>(deprecated)</sup>

isActived(): Promise\<boolean>

Checks whether this window is active. This API uses a promise to return the result.

This API is supported since API version 9 and deprecated since API version 11. You are advised to use [isActive<sup>11+</sup>](#isactive11) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the window is active, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  let focused = await window.isActived();
}
```

### focus<sup>9+</sup>

focus(): Promise\<void>

Moves the focus to this window.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  await window.focus();
}
```

### moveTo<sup>9+</sup>

moveTo(x: number, y: number): Promise\<void>

Moves this window to the end point. This API is applicable to moveable windows.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| x      | number | Yes  | X coordinate of the end point. The value must be greater than or equal to 0.|
| y      | number | Yes  | Y coordinate of the end point. The value must be greater than or equal to 0.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 17000005 | This operation is not supported.         |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  await window.moveTo(100, 100);
}
```

### resize<sup>9+</sup>

resize(wide: number, height: number, direction: ResizeDirection): Promise\<void>

Resizes this window based on the specified width, height, and resize direction. This API is applicable to resizable windows.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name   | Type                                | Mandatory| Description                                                        |
| --------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| wide      | number                               | Yes  | Target width.                        |
| height    | number                               | Yes  | Target height.                        |
| direction | [ResizeDirection](#resizedirection9) | Yes  | Resize direction.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 17000005 | This operation is not supported.         |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, ResizeDirection, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  await window.resize(100, 100, ResizeDirection.LEFT);
}
```

### split<sup>9+</sup>

split(): Promise\<void>

Switches the window to split-screen mode. This API is applicable to windows that support screen splitting.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.         |
| 17000005 | This operation is not supported.         |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  await window.split();
}
```

### maximize<sup>9+</sup>

maximize(): Promise\<void>

Maximizes this window. This API is applicable to windows that can be maximized.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 17000005 | This operation is not supported.         |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  await window.maximize();
}
```

### minimize<sup>9+</sup>

minimize(): Promise\<void>

Minimizes this window. This API is applicable to windows that can be minimized.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.          |
| 17000005 | This operation is not supported.         |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  await window.minimize();
}
```

### resume<sup>9+</sup>

resume(): Promise\<void>

Restores this window to the previous window mode.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.          |
| 17000005 | This operation is not supported.         |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  await window.resume();
}
```

### close<sup>9+</sup>

close(): Promise\<void>

Closes this window.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 17000005 | This operation is not supported.         |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver:Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({actived: true});
  await window.close();
}
```

### isActive<sup>11+</sup>

isActive(): Promise\<boolean>

Checks whether this window is active.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the window is active, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                        |
| -------- | ------------------------------------------------ |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.         |

**Example**

```ts
import { Driver, UiWindow } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({active: true});
  let focused = await window.isActive();
}
```

## UIEventObserver<sup>10+</sup>

UI event listener.

### once('toastShow')

once(type: 'toastShow', callback: Callback\<UIElementInfo>): void;

Subscribes to events of the toast component. This API uses a callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type                                        | Mandatory| Description                             |
| -------- | -------------------------------------------- | ---- | --------------------------------- |
| type     | string                                       | Yes  | Event type. The value is fixed at **'toastShow'**.|
| callback | Callback\<[UIElementInfo](#uielementinfo10)> | Yes  | Callback used to return the result.         |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, UIElementInfo, UIEventObserver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let observer:  UIEventObserver = await driver.createUIEventObserver()
  let  callback = (UIElementInfo: UIElementInfo)=>{
    console.info(UIElementInfo.bundleName)
    console.info(UIElementInfo.text)
    console.info(UIElementInfo.type)
  }
  observer.once('toastShow', callback)
}
```

### once('dialogShow')

once(type: 'dialogShow', callback: Callback\<UIElementInfo>): void;

Subscribes to events of the dialog component. This API uses a callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type                                        | Mandatory| Description                              |
| -------- | -------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                       | Yes  | Event type. The value is fixed at **'dialogShow'**.|
| callback | Callback\<[UIElementInfo](#uielementinfo10)> | Yes  | Callback used to return the result.          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, UIElementInfo, UIEventObserver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let observer: UIEventObserver = await driver.createUIEventObserver()
  let  callback = (UIElementInfo: UIElementInfo)=>{
    console.info(UIElementInfo.bundleName)
    console.info(UIElementInfo.text)
    console.info(UIElementInfo.type)
  }
  observer.once('dialogShow', callback)
}
```

## By<sup>(deprecated)</sup>

The UiTest framework provides a wide range of UI component feature description APIs in the **By** class to filter and match components.<br>
The APIs provided by the **By** class exhibit the following features:<br>1. Allow one or more attributes as the match conditions. For example, you can specify both the **text** and **id** attributes to find the target component.<br>2. Provide multiple match patterns for component attributes.<br>3. Support absolute positioning and relative positioning for components. APIs such as [By.isBefore<sup>(deprecated)</sup>](#isbeforedeprecated) and [By.isAfter<sup>(deprecated)</sup>](#isafterdeprecated) can be used to specify the features of adjacent components to assist positioning.<br>All APIs provided in the **By** class are synchronous. You are advised to use the static constructor **BY** to create a **By** object in chain mode.

This class is deprecated since API version 9. You are advised to use [On<sup>9+</sup>](#on9) instead.

```ts
import { BY } from '@kit.TestKit';
BY.text('123').type('Button');
```

### text<sup>(deprecated)</sup>

text(txt: string, pattern?: MatchPattern): By

Specifies the text attribute of the target component. Multiple match patterns are supported.

This API is deprecated since API version 9. You are advised to use [text<sup>9+</sup>](#text9) instead.

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

```ts
import { BY, By } from '@kit.TestKit';
let by: By = BY.text('123'); // Use the static constructor BY to create a By object and specify the text attribute of the target component.
```


### key<sup>(deprecated)</sup>

key(key: string): By

Specifies the key attribute of the target component.

This API is deprecated since API version 9. You are advised to use [id<sup>9+</sup>](#id9) instead.

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

```ts
import { By, BY } from '@kit.TestKit';
let by: By = BY.key('123'); // Use the static constructor BY to create a By object and specify the key attribute of the target component.
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

```ts
import { By, BY } from '@kit.TestKit';
let by: By = BY.id(123); // Use the static constructor BY to create a By object and specify the id attribute of the target component.
```


### type<sup>(deprecated)</sup>

type(tp: string): By

Specifies the type attribute of the target component.

This API is deprecated since API version 9. You are advised to use [type<sup>9+</sup>](#type9) instead.

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

```ts
import { By, BY } from '@kit.TestKit';
let by: By = BY.type('Button'); // Use the static constructor BY to create a By object and specify the type attribute of the target component.
```


### clickable<sup>(deprecated)</sup>

clickable(b?: boolean): By

Specifies the clickable attribute of the target component.

This API is deprecated since API version 9. You are advised to use [clickable<sup>9+</sup>](#clickable9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Clickable status of the target component.<br>**true**: clickable.<br>**false**: not clickable.<br> Default value: **true**|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [By](#bydeprecated) | **By** object that matches the clickable attribute of the target component.|

**Example**

```ts
import { By, BY } from '@kit.TestKit';
let by: By = BY.clickable(true); // Use the static constructor BY to create a By object and specify the clickable attribute of the target component.
```


### scrollable<sup>(deprecated)</sup>

scrollable(b?: boolean): By

Specifies the scrollable attribute of the target component.

This API is deprecated since API version 9. You are advised to use [scrollable<sup>9+</sup>](#scrollable9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                       |
| ------ | ------- | ---- | ----------------------------------------------------------- |
| b      | boolean | No  | Scrollable status of the target component.<br>**true**: scrollable.<br>**false**: not scrollable.<br> Default value: **true**|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [By](#bydeprecated) | **By** object that matches the scrollable attribute of the target component.|

**Example**

```ts
import { By, BY } from '@kit.TestKit';
let by: By = BY.scrollable(true); // Use the static constructor BY to create a By object and specify the scrollable attribute of the target component.
```

### enabled<sup>(deprecated)</sup>

enabled(b?: boolean): By

Specifies the enabled attribute of the target component.

This API is deprecated since API version 9. You are advised to use [enabled<sup>9+</sup>](#enabled9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                     |
| ------ | ------- | ---- | --------------------------------------------------------- |
| b      | boolean | No  | Enabled status of the target component.<br>**true**: enabled.<br>**false**: not enabled.<br> Default value: **true**|

**Return value**

| Type               | Description                                    |
| ------------------- | ---------------------------------------- |
| [By](#bydeprecated) | **By** object that matches the enabled attribute of the target component.|

**Example**

```ts
import { By, BY } from '@kit.TestKit';
let by: By = BY.enabled(true); // Use the static constructor BY to create a By object and specify the enabled attribute of the target component.
```

### focused<sup>(deprecated)</sup>

focused(b?: boolean): By

Specifies the focused attribute of the target component.

This API is deprecated since API version 9. You are advised to use [focused<sup>9+</sup>](#focused9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                 |
| ------ | ------- | ---- | ----------------------------------------------------- |
| b      | boolean | No  | Focused status of the target component.<br>**true**: focused.<br>**false**: not focused.<br> Default value: **true**|

**Return value**

| Type               | Description                                    |
| ------------------- | ---------------------------------------- |
| [By](#bydeprecated) | **By** object that matches the focused attribute of the target component.|

**Example**

```ts
import { By, BY } from '@kit.TestKit';
let by: By = BY.focused(true); // Use the static constructor BY to create a By object and specify the focused attribute of the target component.
```

### selected<sup>(deprecated)</sup>

selected(b?: boolean): By

Specifies the selected status of the target component.

This API is deprecated since API version 9. You are advised to use [selected<sup>9+</sup>](#selected9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | No  | Selected status of the target component.<br>**true**: selected.<br>**false**: not selected.<br> Default value: **true**|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [By](#bydeprecated) | **By** object that matches the selected attribute of the target component.|

**Example**

```ts
import { By, BY } from '@kit.TestKit';
let by: By = BY.selected(true); // Use the static constructor BY to create a By object and specify the selected attribute of the target component.
```

### isBefore<sup>(deprecated)</sup>

isBefore(by: By): By

Specifies that the target component is located before the given attribute component.

This API is deprecated since API version 9. You are advised to use [isBefore<sup>9+</sup>](#isbefore9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type               | Mandatory| Description            |
| ------ | ------------------- | ---- | ---------------- |
| by     | [By](#bydeprecated) | Yes  | Information about the attribute component.|

**Return value**

| Type               | Description                                                |
| ------------------- | ---------------------------------------------------- |
| [By](#bydeprecated) | **By** object.|

**Example**

```ts
import { By, BY } from '@kit.TestKit';

// Use the static constructor BY to create a by object and specify that the target component is located before the given attribute component.
let by: By = BY.type('Button').isBefore(BY.text('123')); // Search for the first <Button> component located before the component whose text is 123.
```

### isAfter<sup>(deprecated)</sup>

isAfter(by: By): By

Specifies that the target component is located after the given attribute component.

This API is deprecated since API version 9. You are advised to use [isAfter<sup>9+</sup>](#isafter9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type               | Mandatory| Description            |
| ------ | ------------------- | ---- | ---------------- |
| by     | [By](#bydeprecated) | Yes  | Information about the attribute component.|

**Return value**

| Type               | Description                                                |
| ------------------- | ---------------------------------------------------- |
| [By](#bydeprecated) | **By** object.|

**Example**

```ts
import { By, BY } from '@kit.TestKit';

// Use the static constructor BY to create a by object and specify that the target component is located after the given attribute component.
let by: By = BY.type('Text').isAfter(BY.text('123')); // Search for the first <Text> component located after the component whose text is 123.
```

## UiComponent<sup>(deprecated)</sup>

In **UiTest**, the **UiComponent** class represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

This class is deprecated since API version 9. You are advised to use [Component<sup>9+</sup>](#component9) instead.

### click<sup>(deprecated)</sup>

click(): Promise\<void>

Clicks this component.

This API is deprecated since API version 9. You are advised to use [click<sup>9+</sup>](#click9) instead.

**System capability**: SystemCapability.Test.UiTest

**Example**

```ts
import { UiDriver, BY, Driver, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  await button.click();
}
```

### doubleClick<sup>(deprecated)</sup>

doubleClick(): Promise\<void>

Double-clicks this component.

This API is deprecated since API version 9. You are advised to use [doubleClick<sup>9+</sup>](#doubleclick9) instead.

**System capability**: SystemCapability.Test.UiTest

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  await button.doubleClick();
}
```

### longClick<sup>(deprecated)</sup>

longClick(): Promise\<void>

Long-clicks this component.

This API is deprecated since API version 9. You are advised to use [longClick<sup>9+</sup>](#longclick9) instead.

**System capability**: SystemCapability.Test.UiTest

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
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

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  let id = await button.getId();
}
```

### getKey<sup>(deprecated)</sup>

getKey(): Promise\<string>

Obtains the key of this component.

This API is deprecated since API version 9. You are advised to use [getId<sup>9+</sup>](#getid9) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                          |
| ---------------- | ------------------------------ |
| Promise\<string> | Promise used to return the key of the component.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  let str_key = await button.getKey();
}
```

### getText<sup>(deprecated)</sup>

getText(): Promise\<string>

Obtains the text information of this component.

This API is deprecated since API version 9. You are advised to use [getText<sup>9+</sup>](#gettext9) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the text information of the component.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  let text = await button.getText();
}
```

### getType<sup>(deprecated)</sup>

getType(): Promise\<string>

Obtains the type of this component.

This API is deprecated since API version 9. You are advised to use [getType<sup>9+</sup>](#gettype9) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                         |
| ---------------- | ----------------------------- |
| Promise\<string> | Promise used to return the type of the component.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  let type = await button.getType();
}
```

### isClickable<sup>(deprecated)</sup>

isClickable(): Promise\<boolean>

Obtains the clickable status of this component.

This API is deprecated since API version 9. You are advised to use [isClickable<sup>9+</sup>](#isclickable9) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is clickable, and **false** means the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
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

This API is deprecated since API version 9. You are advised to use [isScrollable<sup>9+</sup>](#isscrollable9) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is scrollable, and **false** means the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let scrollBar: UiComponent = await driver.findComponent(BY.scrollable(true));
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

This API is deprecated since API version 9. You are advised to use [isEnabled<sup>9+</sup>](#isenabled9) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                      |
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the component is enabled, and **false** means the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
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

This API is deprecated since API version 9. You are advised to use [isFocused<sup>9+</sup>](#isfocused9) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the target component is focused, and **false** means the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
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

This API is deprecated since API version 9. You are advised to use [isSelected<sup>9+</sup>](#isselected9) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                 |
| ----------------- | ----------------------------------------------------- |
| Promise\<boolean> | Promise used to return the selected status of the component. The value **true** means that the component is selected, and **false** means the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
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

This API is deprecated since API version 9. You are advised to use [inputText<sup>9+</sup>](#inputtext9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| text   | string | Yes  | Text to enter.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let text: UiComponent = await driver.findComponent(BY.text('hello world'));
  await text.inputText('123');
}
```

### scrollSearch<sup>(deprecated)</sup>

scrollSearch(by: By): Promise\<UiComponent>

Scrolls on this component to search for the target component (applicable to components that support scrolling, such as **\<List>**).

This API is deprecated since API version 9. You are advised to use [scrollSearch<sup>9+</sup>](#scrollsearch9) instead.

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

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let scrollBar: UiComponent = await driver.findComponent(BY.type('Scroll'));
  let button = await scrollBar.scrollSearch(BY.text('next page'));
}
```

## UiDriver<sup>(deprecated)</sup>

The **UiDriver** class is the main entry to the UiTest framework. It provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot.
All APIs provided by this class, except **UiDriver.create()**, use a promise to return the result and must be invoked using **await**.

This class is deprecated since API version 9. You are advised to use [Driver<sup>9+</sup>](#driver9) instead.

### create<sup>(deprecated)</sup>

static create(): UiDriver

Creates a **UiDriver** object and returns the object created. This API is a static API.

This API is deprecated since API version 9. You are advised to use [create<sup>9+</sup>](#create9) instead.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type    | Description                    |
| -------- | ------------------------ |
| UiDriver | **UiDriver** object created.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
}
```

### delayMs<sup>(deprecated)</sup>

delayMs(duration: number): Promise\<void>

Delays this **UiDriver** object within the specified duration.

This API is deprecated since API version 9. You are advised to use [delayMs<sup>9+</sup>](#delayms9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description        |
| -------- | ------ | ---- | ------------ |
| duration | number | Yes  | Duration of time.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.delayMs(1000);
}
```

### findComponent<sup>(deprecated)</sup>

findComponent(by: By): Promise\<UiComponent>

Searches this **UiDriver** object for the target component that matches the given attributes.

This API is deprecated since API version 9. You are advised to use [findComponent<sup>9+</sup>](#findcomponent9) instead.

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

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.text('next page'));
}
```

### findComponents<sup>(deprecated)</sup>

findComponents(by: By): Promise\<Array\<UiComponent>>

Searches this **UiDriver** object for all components that match the given attributes.

This API is deprecated since API version 9. You are advised to use [findComponents<sup>9+</sup>](#findcomponents9) instead.

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

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let buttonList: Array<UiComponent> = await driver.findComponents(BY.text('next page'));
}
```

### assertComponentExist<sup>(deprecated)</sup>

assertComponentExist(by: By): Promise\<void>

Asserts that a component that matches the given attributes exists on the current page. If the component does not exist, the API throws a JS exception, causing the current test case to fail.

This API is deprecated since API version 9. You are advised to use [assertComponentExist<sup>9+</sup>](#assertcomponentexist9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type               | Mandatory| Description                |
| ------ | ------------------- | ---- | -------------------- |
| by     | [By](#bydeprecated) | Yes  | Attributes of the target component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                        |
| -------- | ------------------------------------------------ |
| 401      | if the input parameters are invalid.             |
| 17000002 | if the async function was not called with await. |
| 17000003 | if the assertion failed.                         |

**Example**

```ts
import { UiDriver, BY } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.assertComponentExist(BY.text('next page'));
}
```

### pressBack<sup>(deprecated)</sup>

pressBack(): Promise\<void>

Presses the Back button on this **UiDriver** object.

This API is deprecated since API version 9. You are advised to use [pressBack<sup>9+</sup>](#pressback9) instead.

**System capability**: SystemCapability.Test.UiTest

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.pressBack();
}
```

### triggerKey<sup>(deprecated)</sup>

triggerKey(keyCode: number): Promise\<void>

Triggers the key of this **UiDriver** object that matches the given key code.

This API is deprecated since API version 9. You are advised to use [triggerKey<sup>9+</sup>](#triggerkey9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ------------- |
| keyCode | number | Yes  | Key code.|

**Example**

```ts
import { Driver, UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.triggerKey(123);
}
```


### click<sup>(deprecated)</sup>

click(x: number, y: number): Promise\<void>

Clicks a specific point of this **UiDriver** object based on the given coordinates.

This API is deprecated since API version 9. You are advised to use [click<sup>9+</sup>](#click9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X coordinate of the end point.|
| y      | number | Yes  | Y coordinate of the end point.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.click(100,100);
}
```

### doubleClick<sup>(deprecated)</sup>

doubleClick(x: number, y: number): Promise\<void>

Double-clicks a specific point of this **UiDriver** object based on the given coordinates.

This API is deprecated since API version 9. You are advised to use [doubleClick<sup>9+</sup>](#doubleclick9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X coordinate of the end point.|
| y      | number | Yes  | Y coordinate of the end point.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.doubleClick(100,100);
}
```

### longClick<sup>(deprecated)</sup>

longClick(x: number, y: number): Promise\<void>

Long-clicks a specific point of this **UiDriver** object based on the given coordinates.

This API is deprecated since API version 9. You are advised to use [longClick<sup>9+</sup>](#longclick9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X coordinate of the end point.|
| y      | number | Yes  | Y coordinate of the end point.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.longClick(100,100);
}
```

### swipe<sup>(deprecated)</sup>

swipe(startx: number, starty: number, endx: number, endy: number): Promise\<void>

Swipes on this **UiDriver** object from the start point to the end point based on the given coordinates.

This API is deprecated since API version 9. You are advised to use [swipe<sup>9+</sup>](#swipe9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| startx | number | Yes  | X coordinate of the start point.|
| starty | number | Yes  | Y coordinate of the start point.|
| endx   | number | Yes  | X coordinate of the end point.|
| endy   | number | Yes  | Y coordinate of the end point.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.swipe(100,100,200,200);
}
```

### screenCap<sup>(deprecated)</sup>

screenCap(savePath: string): Promise\<boolean>

Captures the current screen of this **UiDriver** object and saves it as a PNG image to the given save path.

This API is deprecated since API version 9. You are advised to use [screenCap<sup>9+</sup>](#screencap9) instead.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description          |
| -------- | ------ | ---- | -------------- |
| savePath | string | Yes  | File save path.|

**Return value**

| Type             | Description                                  |
| ----------------- | -------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the operation is successful.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.screenCap('/data/storage/el2/base/cache/1.png');
}
```
