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
> - The APIs of this module are applicable to phones, tablets, PCs/2-in-1devices, wearables, smart visions, and head units.


## Modules to Import

```ts
import { UiComponent, UiDriver, Component, Driver, UiWindow, ON, BY, MatchPattern, DisplayRotation, ResizeDirection, WindowMode, PointerMatrix, UiDirection, MouseButton, UIElementInfo, UIEventObserver } from '@kit.TestKit';
```

## MatchPattern

Enumerates the match patterns supported for component attributes.

**System capability**: SystemCapability.Test.UiTest

| Name                   | Value| Description                                                                 |
|-----------------------|---|---------------------------------------------------------------------|
| EQUALS                | 0 | Equals the given value.<br>**Atomic service API**: This API can be used in atomic services since API version 11.        |
| CONTAINS              | 1 | Contains the given value.<br>**Atomic service API**: This API can be used in atomic services since API version 11.        |
| STARTS_WITH           | 2 | Starts with the given value.<br>**Atomic service API**: This API can be used in atomic services since API version 11.       |
| ENDS_WITH             | 3 | Ends with the given value.<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
| REG_EXP<sup>18+</sup> | 4 | Uses regular expression matching.<br>**Atomic service API**: This API can be used in atomic services since API version 18.      |
| REG_EXP_ICASE<sup>18+</sup>          | 5 | Uses case-insensitive regular expression matching.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
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

**System capability**: SystemCapability.Test.UiTest

| Name| Type  | Read-Only|  Optional| Description       |
| ---- | ------ | ---- | ---- |-----------|
| x    | number |  No  | No  | Horizontal coordinate of a coordinate point. The value is an integer greater than 0.<br> **Note**: Since API version 20, this attribute is no longer read-only.<br> **Atomic service API**: This API can be used in atomic services since API version 11.|
| y    | number |  No  | No  | Vertical coordinate of a coordinate point. The value is an integer greater than 0.<br> **Note**: Since API version 20, this attribute is no longer read-only.<br> **Atomic service API**: This API can be used in atomic services since API version 11.|
| displayId<sup>20+</sup>    | number | No   | Yes  | ID of the display to which the coordinate point belongs. The value is an integer greater than or equal to 0. The default value is the default screen ID of the device.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|

## Rect<sup>9+</sup>

Provides bounds information of a component.

**System capability**: SystemCapability.Test.UiTest

| Name  | Type  | Read-Only| Optional| Description                     |
| ------ | ------ | ---- | ---- | ------------------------- |
| left   | number |  No  | No|X coordinate of the upper left corner of the component border. The value is an integer greater than 0.<br> **Note**: Since API version 20, this attribute is no longer read-only.<br> **Atomic service API**: This API can be used in atomic services since API version 11.|
| top    | number |  No  | No|Y coordinate of the upper left corner of the component border. The value is an integer greater than 0.<br> **Note**: Since API version 20, this attribute is no longer read-only.<br> **Atomic service API**: This API can be used in atomic services since API version 11. |
| right  | number |  No  | No|X coordinate of the lower right corner of the component border. The value is an integer greater than 0.<br> **Note**: Since API version 20, this attribute is no longer read-only.<br> **Atomic service API**: This API can be used in atomic services since API version 11. |
| bottom | number |  No  | No|Y coordinate of the lower right corner of the component border. The value is an integer greater than 0.<br> **Note**: Since API version 20, this attribute is no longer read-only.<br> **Atomic service API**: This API can be used in atomic services since API version 11. |
| displayId<sup>20+</sup> | number |  No  | Yes|ID of the display to which the component border belongs. The value is an integer greater than or equal to 0. The default value is the default screen ID of the device.<br> **Atomic service API**: This API can be used in atomic services since API version 20. |

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

| Name                | Type   | Read-Only| Optional| Description                                                                                    |
| -------------------- | ------- | ---- | ---- |----------------------------------------------------------------------------------------|
| bundleName           | string  | No | Yes | Bundle name of the application to which the window belongs. The default value is empty.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                       |
| title                | string  | No | Yes | Title of the window. The default value is empty.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                         |
| focused              | boolean | No | Yes  | Whether the window is focused. The value **true** indicates that the window is focused, and **false** indicates the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| actived(deprecated)  | boolean | No  | Yes | Whether the window is interacting with the user. The value **true** indicates that the window is interacting with the user, and **false** indicates the opposite.<br>This API is deprecated since API version 11. You are advised to use the **active** API instead.                                               |
| active<sup>11+</sup> | boolean | No | Yes | Whether the window is interacting with the user. The value **true** indicates that the window is interacting with the user, and **false** indicates the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                    |
| displayId<sup>20+</sup> | number | No  | Yes | ID of the display to which the window belongs. The value is an integer greater than or equal to 0. The default value is the default screen ID of the device.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|

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

| Name      | Type  | Read-Only| Optional| Description                 |
| ---------- | ------ | ---- | ---- | --------------------- |
| bundleName | string | Yes  | No  | Bundle name of the home application.     |
| type       | string | Yes  | No  | Component or window type.      |
| text       | string | Yes  | No  | Text information of the component or window.|


## TouchPadSwipeOptions<sup>18+</sup>

Describes information about the touchpad swipe gesture option.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

| Name      | Type  | Read-Only| Optional| Description                                                    |
| ---------- | ------ |----|----|--------------------------------------------------------|
| stay | boolean | No | Yes | Whether the swipe gesture stays on the touchpad for 1s before it is lifted. The value **true** indicates that the swipe gesture stays on the touchpad for 1s, and **false** indicates the opposite. The default value is **false**.|
| speed       | number | No | Yes | Swipe speed, in px/s. The value is an integer ranges from 200 to 40000. If the set value is not in the range, the default value **2000** is used. |


## InputTextMode<sup>20+</sup>

Describes the text input mode.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

| Name      | Type  | Read-Only| Optional| Description                                                      |
| ---------- | ------ |----|----|----------------------------------------------------------|
| paste | boolean | No | Yes | Whether to copy and paste text. The value **true** means to copy and paste text, and **false** means to type text. Default value: **false**<br> **NOTE**<br>1. If the input text contains Chinese characters or special characters or contains more than 200 characters, the text is copied and pasted regardless of the value of this parameter.<br>2. For smart wearable devices, this API does not support input in copy and paste mode.|
| addition       | boolean | No | Yes | Whether to input text in addition mode. The value **true** means to input text in addition mode, and **false** means the opposite. Default value: **false**|


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

> **NOTE**
>
> If the [accessibilityLevel](../apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilitylevel) of a component is set to **no** or **no-hide-descendants**, this API cannot be used to specify the text attribute of the target component for searching for the component. In this case, you can use the [On.originalText ()](#originaltext20) API.

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

### id<sup>18+</sup>

id(id: string, pattern: MatchPattern): On

Specifies the ID attribute of the target component.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name                  | Type  | Mandatory| Description                                   |
|-----------------------| ------ |----|---------------------------------------|
| id                    | string | Yes | Component ID.                            |
| pattern | [MatchPattern](#matchpattern) | Yes | Text matching pattern.|

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
import { MatchPattern, On, ON } from '@kit.TestKit';

let on:On = ON.id('id', MatchPattern.REG_EXP_ICASE) // Use case-insensitive regular expression to match the ID attribute value of the component.
```

### type<sup>9+</sup>

type(tp: string): On

Specifies the type attribute of the target component.

>**NOTE**
>
>You can define the type of the component. In addition, you can use [DevEco Testing](https://developer.huawei.com/consumer/en/download) to query the type information of the component.

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

### type<sup>18+</sup>

type(tp: string, pattern: MatchPattern): On

Specifies the type attribute of the target component.

>**NOTE**
>
>You can define the type of the component. In addition, you can use [DevEco Testing](https://developer.huawei.com/consumer/en/download) to query the type information of the component.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name                  | Type  | Mandatory| Description                                   |
|-----------------------| ------ |----|---------------------------------------|
| tp                    | string | Yes | Component type.                              |
| pattern | [MatchPattern](#matchpattern) | Yes | Text matching pattern.|

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
| b      | boolean | No  | Clickable status of the component. The value **true** indicates that the component is clickable, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Long-clickable status of the component. The value **true** indicates that the component is long-clickable, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Scrollable status of the component. The value **true** indicates that the component is scrollable, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Enabled status of the component. The value **true** indicates that the component is enabled, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Focused status of the component. The value **true** indicates that the component is focused, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Selected status of the component. The value **true** indicates that the component is selected, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Checked status of the component. The value **true** indicates that the component is checked, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Checkable status of the component. The value **true** indicates that the component is checkable, and **false** indicates the opposite. Default value: **true**|

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
let on:On = ON.type('Text').isAfter(ON.text('123'));  // Search for the first <Text> component located after the component whose text is 123.
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

inWindow(bundleName: string): On

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

### hint<sup>18+</sup>

hint(val: string, pattern?: MatchPattern): On

Obtains the component object of the specified hint text and returns the **On** object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                   |
| ------ | ------ |----|---------------------------------------|
| val     | string | Yes | The specified hint text of the component.                             |
| pattern | [MatchPattern](#matchpattern) | No | Match pattern. The default value is [EQUALS](#matchpattern).|

**Return value**

| Type      | Description                                    |
| ---------- | ---------------------------------------- |
| [On](#on9) | The **On** object of the specified hint text component.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
 import { MatchPattern, On, ON } from '@kit.TestKit';
 
 let on:On = ON.hint('welcome', MatchPattern.EQUALS); // Use the static constructor ON to create an On object with the hint text attribute of the target component specified.
```

### belongingDisplay<sup>20+</sup>

belongingDisplay(displayId: number): On

Obtains the component object on the specified display.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                   |
| ------ | ------ |----|---------------------------------------|
| displayId | number | Yes | ID of the display to which the component belongs. The value is an integer greater than or equal to 0.<br> **Note**: If the input **displayId** does not exist, the exception **17000007** is reported. You can use [getAllDisplays](../apis-arkui/js-apis-display.md#displaygetalldisplays9) to obtain all current **display** objects and use them to obtain the corresponding display IDs.|

**Return value**

| Type      | Description                                    |
| ---------- | ---------------------------------------- |
| [On](#on9) | The **On** object of the display to which the specified component belongs.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
|  17000007  | Parameter verification failed.|

**Example**

```ts
 import { On, ON } from '@kit.TestKit';
 
 let on:On = ON.belongingDisplay (0); // Use the static constructor ON to create an On object and specify the ID of the display to which the target component belongs.
```

### originalText<sup>20+</sup>

originalText(text: string, pattern?: MatchPattern): On

Specifies the text attribute of the target component. Multiple match patterns are supported.

> **NOTE**
>
> If the [accessibilityLevel](../apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilitylevel) of a component is set to **no** or **no-hide-descendants**, this API can be used to specify the text attribute of the target component for searching for the component. In this case, the [On.text()](#text9) API does not take effect.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type                         | Mandatory| Description                                               |
| ------- | ----------------------------- | ---- | --------------------------------------------------- |
| text     | string                        | Yes  | Component text, used to match the target component.               |
| pattern | [MatchPattern](#matchpattern) | No  | Match pattern. The default value is [EQUALS](#matchpattern).|

**Return value**

| Type      | Description                              |
| ---------- | ---------------------------------- |
| [On](#on9) | **On** object that matches the text attribute of the target component.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000007      | Parameter verification failed.|

**Example**

```ts
import { On, ON } from '@kit.TestKit';

let on:On = ON.originalText('123'); // Use the static constructor ON to create an On object and specify the originalText attribute of the target component.
```

## Component<sup>9+</sup>

Represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

### click<sup>9+</sup>

click(): Promise\<void>

Clicks a component object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Double-clicks a component object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Long-clicks a component object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Obtains the ID of a component object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                           |
| ---------------- | ------------------------------- |
| Promise\<string> | Promise used to return the component ID.|

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

Obtains the text information of this component. This API uses a promise to return the result.

> **NOTE**
>
> If the [accessibilityLevel](../apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilitylevel) attribute of the component is set to **no** or **no-hide-descendants**, this API cannot be used to obtain the text information of the component. In this case, you can use [Component.getOriginalText ()](#getoriginaltext20) to obtain the text information of the component.

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

Obtains the type of a component object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                         |
| ---------------- | ----------------------------- |
| Promise\<string> | Promise used to return the component type.|

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

Obtains the bound information of this component. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                    | Description                                 |
| ------------------------ | ------------------------------------- |
| Promise\<[Rect](#rect9)> | Promise used to return the bound information of the component object.|

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

Obtains the center point of the area occupied by a component object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                      | Description                                           |
| -------------------------- | ----------------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the center point of the area occupied by the component object.|

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

Obtains the clickable attribute of a component object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return whether the component object is clickable. The value **true** indicates that the component is clickable, and **false** indicates the opposite.|

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

Obtains the long-clickable attribute of a component object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                              |
| ----------------- |--------------------------------------------------|
| Promise\<boolean> | Promise used to return whether the component object is long-clickable. The value **true** indicates that the component is long-clickable, and **false** indicates the opposite.|

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

Obtains the checked status of a component object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the checked status of the component object. The value **true** indicates that the component is checked, and **false** indicates the opposite.|

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

Obtains whether a component object is checkable. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return whether the component object is checkable. The value **true** indicates that the component is checkable, and **false** indicates the opposite.|

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

Obtains whether a component object is scrollable. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return whether the component object is scrollable. The value **true** indicates that the component is scrollable, and **false** indicates the opposite.|

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

Obtains whether the component is enabled. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                      |
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | Promise used to return whether the component is enabled. The value **true** indicates that the component is enabled, and **false** indicates the opposite.|

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

Checks whether the component is focused. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return whether the component is focused. The value **true** indicates that the component is focused, and **false** indicates the opposite.|

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

Obtains whether a component is selected. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                               |
| ----------------- | --------------------------------------------------- |
| Promise\<boolean> | Promise used to return whether the component is selected. The value **true** indicates that the component is selected, and **false** indicates the opposite.|

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

Inputs text in a text box component after clearing its original text. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| text   | string | Yes  | Input text. Currently, English, Chinese, and special characters are supported.<br> **Note**: For wearables, this API does not support Chinese characters.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### inputText<sup>20+</sup>

inputText(text: string, mode: InputTextMode): Promise\<void>

Inputs text to a text box component with a specified text input mode supported. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| text   | string | Yes  | Input text. Currently, English, Chinese, and special characters are supported.<br> **Note**: For wearables, this API does not support Chinese characters.|
| mode | [InputTextMode](#inputtextmode20)  | Yes  | Text input mode. For details, see [InputTextMode](#inputtextmode20).<br> **Note**: If **InputTextMode.addition** is set to **true**, the specified text is added to the end of the existing text in the component. Otherwise, the specified text overwrites the existing text of the component.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not support, function can not work correctly due to limited device capabilities.|

**Example**
```ts
import { Component, Driver, ON } from '@kit.TestKit';

async function mode_demo() {
  let driver: Driver = Driver.create();
  let text: Component = await driver.findComponent(ON.text('hello world'));
  await text.inputText('123', { paste: true, addition: false });
}
```


### clearText<sup>9+</sup>

clearText(): Promise\<void>

Clears the text in a text box component. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Scrolls on this component to search for the target component. This API is applicable to components that support scrolling and uses a promise to return the result.

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

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### scrollSearch<sup>18+</sup>

scrollSearch(on: On, vertical?: boolean, offset?: number): Promise\<Component>

Scrolls on this component to search for the target component. This API is applicable to components that support scrolling and uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name                   | Type      | Mandatory| Description                               |
|------------------------| ---------- | ---- |-----------------------------------|
| on                     | [On](#on9) | Yes  | Attributes of the target component.                       |
| vertical |    boolean | No| Whether the search direction is vertical. The default value **true** indicates that the search direction is vertical. **false** indicates that the search direction is horizontal.|
| offset   | number| No| Offset from the scrolling start/end point to the component border, in pixels. The default value is **80**. The value is an integer greater than or equal to 0.   |

**Return value**

| Type                              | Description                                 |
| ---------------------------------- | ------------------------------------- |
| Promise\<[Component](#component9)> | Promise used to return the target component.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Scrolls to the top of a scrollable component. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                    |
| ------ | ------ | ---- |--------------------------------------------------------|
| speed  | number | No  | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Scrolls to the bottom of a scrollable component. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                    |
| ------ | ------ | ---- |--------------------------------------------------------|
| speed  | number | No  | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Drags a component to the target component. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on phones, tablets, and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                    | Mandatory| Description      |
| ------ | ------------------------ | ---- | ---------- |
| target | [Component](#component9) | Yes  | Target component.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Pinches a component to zoom in based on the specified scale. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| scale  | number | Yes  | Scale factor, which is a value greater than 1.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Pinches a component to zoom out based on the specified scale. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| scale  | number | Yes  | Scale factor, which is a value ranging from 0 to 1.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

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
### getHint<sup>18+</sup>

getHint(): Promise\<string>

Obtains the hint text of a component. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                  |
| ---------------- |----------------------|
| Promise\<string> | Promise used to return the hint text of a component.|

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
  let button: Component = await driver.findComponent(ON.type('TextInput'));
  let hints = await button.getHint();
}
```
### getDisplayId<sup>20+</sup>

getDisplayId(): Promise\<number>

Obtains the ID of the display to which the component belongs. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                  |
| ---------------- |----------------------|
| Promise\<number> | Promise used to return the ID of the display to which the component belongs.|

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
  let button: Component = await driver.findComponent(ON.type('TextInput'));
  let displayId = await button.getDisplayId();
}
```

### getOriginalText<sup>20+</sup>

getOriginalText(): Promise\<string>

Obtains the original text information of this component. This API uses a promise to return the result.

> **NOTE**
>
> If the [accessibilityLevel](../apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilitylevel) attribute of the component is set to **no** or **no-hide-descendants**, this API can be used to obtain the text information of the component, but [Component.getText()](#gettext9) cannot.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the original text information of the component.|

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
  let text = await button.getOriginalText();
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

Delays within a specified period. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                           |
| -------- | ------ | ---- | ------------------------------- |
| duration | number | Yes  | Specified time, in ms. The value is an integer greater than or equal to 0.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Searches for the target component based on the specified attributes. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the target component.|

**Return value**

| Type                              | Description                             |
| ---------------------------------- | --------------------------------- |
| Promise\<[Component](#component9)> | Promise used to return the component.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Searches for all matched components based on the given attributes and saves them in a list. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the target component.|

**Return value**

| Type                                      | Description                                   |
| ------------------------------------------ | --------------------------------------- |
| Promise\<Array\<[Component](#component9)>> | Promise used to return the list of components.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Searches for a window based on the attributes. This API uses a promise to return the result.

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

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Searches for the target component based on the attributes within a specified time. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                                     |
| ------ | ---------- | ---- | ----------------------------------------- |
| on    | [On](#on9) | Yes  | Attributes of the target component.                     |
| time   | number     | Yes  | Duration for searching for the target component, in ms. The value is an integer greater than or equal to 0.|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise\<[Component](#component9)> | Promise used to return the component.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Asserts whether a component matches the specified attributes exists on the current page. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type      | Mandatory| Description                |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | Yes  | Attributes of the target component.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Presses the BACK button. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

### pressBack<sup>20+</sup>

pressBack(displayId: number): Promise\<void>

Presses the **BACK** button on a specified display. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ------------- |
| displayId | number | Yes  | Display ID. The value is an integer greater than or equal to 0.<br> **Note**: If the input **displayId** does not exist, the exception **17000007** is reported. |

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 | Parameter verification failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.pressBack(0);
}
```

### triggerKey<sup>9+</sup>

triggerKey(keyCode: number): Promise\<void>

Triggers a key event based on the key value. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ------------- |
| keyCode | number | Yes  | Key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode).|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### triggerKey<sup>20+</sup>

triggerKey(keyCode: number, displayId: number): Promise\<void>

Triggers a key event on the specified display based on the key value. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ------------- |
| keyCode | number | Yes  | Key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode).|
| displayId | number | Yes  | Display ID. The value is an integer greater than or equal to 0.<br> **Note**: If the input **displayId** does not exist, the exception **17000007** is reported. |

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.triggerKey(123, 0);
}
```

### triggerCombineKeys<sup>9+</sup>

triggerCombineKeys(key0: number, key1: number, key2?: number): Promise\<void>

Triggers a combination key event based on the specified key values. This API uses a promise to return the result. For example, if the value of **Key** is (2072, 2019), the combination key that matches the value is found and clicked, for example, **Ctrl+C**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| key0   | number | Yes  | First key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode).           |
| key1   | number | Yes  | Second key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode).           |
| key2   | number | No  | Third key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### triggerCombineKeys<sup>20+</sup>

triggerCombineKeys(key0: number, key1: number, key2?: number, displayId?: number): Promise\<void>

Triggers a combination key event on the specified display based on the specified key values. This API uses a promise to return the result. For example, if the value of **Key** is (2072, 2019), the combination key that matches the value is found and clicked, for example, **Ctrl+C**.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| key0   | number | Yes  | First key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode).           |
| key1   | number | Yes  | Second key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode).           |
| key2   | number | No  | Third key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|
| displayId | number | No | Display ID. The value is an integer greater than or equal to 0. The default value is the default display ID of the device.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.triggerCombineKeys(2072, 2047, 2035, 0);
}
```

### click<sup>9+</sup>

click(x: number, y: number): Promise\<void>

Clicks the target coordinate. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| x      | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.|
| y      | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### clickAt<sup>20+</sup>

clickAt(point: Point): Promise\<void>

Clicks the target coordinate point. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| point      | [Point](#point9) | Yes  | Point object, which is used to transfer the target point information.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 | Parameter verification failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.clickAt({ x: 100, y: 100, displayId: 0 });
}
```

### doubleClick<sup>9+</sup>

doubleClick(x: number, y: number): Promise\<void>

Double-clicks the target point. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| x      | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.|
| y      | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### doubleClickAt<sup>20+</sup>

doubleClickAt(point: Point): Promise\<void>

Double-clicks the target coordinate point. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| point      | [Point](#point9) | Yes  | Point object, which is used to transfer the target point information.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 | Parameter verification failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.doubleClickAt({ x: 100, y: 100, displayId: 0 });
}
```

### longClick<sup>9+</sup>

longClick(x: number, y: number): Promise\<void>

Long-clicks the target point. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| x      | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.|
| y      | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### longClickAt<sup>20+</sup>

longClickAt(point: Point, duration?: number): Promise\<void>

Long-clicks the target coordinate point for a specified duration. This promise uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| point      | [Point](#point9) | Yes  | Point object, which is used to transfer the target point information.|
| duration | number | No  | Long-click duration, in ms. The value is an integer greater than or equal to 1500. The default value is 1500.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 | Parameter verification failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.longClickAt({ x: 100, y: 100, displayId: 0 }, 1500);
}
```

### swipe<sup>9+</sup>

swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Swipes from the start coordinate point to the target coordinate point. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- |------------------------------------------------------|
| startx | number | Yes  | Number, which indicates the horizontal coordinate of the start point. The value is an integer greater than or equal to 0.                      |
| starty | number | Yes  | Number, which indicates the vertical coordinate of the start point. The value is an integer greater than or equal to 0.                      |
| endx   | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.                      |
| endy   | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.                      |
| speed  | number | No  | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### swipeBetween<sup>20+</sup>

swipeBetween(from: Point, to: Point, speed?: number): Promise\<void>

Swipes from the start coordinate point to the target coordinate point. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- |------------------------------------------------------|
| from | [Point](#point9) | Yes  | Point object, which transfers the coordinates of the start point and the ID of the display to which the start point belongs.                      |
| to  | [Point](#point9) | Yes  | Point object, which transfers the coordinates of the target point and the ID of the display to which it belongs.<br> **Note**: The target point and the start point must be on the same screen. Otherwise, the **17000007** exception is thrown.                      |
| speed  | number | No  | Swipe speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 | Parameter verification failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.swipeBetween({x: 100, y: 100, displayId: 0}, {x: 1000, y: 1000, displayId: 0}, 800);
}
```

### drag<sup>9+</sup>

drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Drags from the start coordinate point to the target coordinate point. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on phones, tablets, and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| startx | number | Yes  | Number, which indicates the horizontal coordinate of the start point. The value is an integer greater than or equal to 0.             |
| starty | number | Yes  | Number, which indicates the vertical coordinate of the start point. The value is an integer greater than or equal to 0.             |
| endx   | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.             |
| endy   | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.             |
| speed  | number | No  | Drag speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.drag(100, 100, 200, 200, 600);
}
```

### dragBetween<sup>20+</sup>

dragBetween(from: Point, to: Point, speed?: number, duration?: number): Promise\<void>

Drags from the start point to the target point. You can specify the drag speed and the click duration before dragging. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on phones, tablets, and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                                    |
| ------ | ------ | ---- |--------------------------------------------------------|
| from | [Point](#point9) | Yes  | Point object, which transfers the coordinates of the start point and the ID of the display to which the start point belongs.                      |
| to  | [Point](#point9) | Yes  | Point object, which transfers the coordinates of the target point and the ID of the display to which it belongs.<br> **Note**: The target point and the start point must be on the same screen. Otherwise, the **17000007** exception is thrown.                      |
| speed  | number | No  | Drag speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|
| duration  | number | No  | Click duration, in ms. The value is an integer greater than or equal to 1500. The default value is 1500.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 | Parameter verification failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.dragBetween( {x: 100, y: 100, displayId: 0}, {x: 1000, y: 1000, displayId: 0}, 800, 1500);
}
```

### screenCap<sup>9+</sup>

screenCap(savePath: string): Promise\<boolean>

Captures the current screen and saves it as a PNG image to the specified path. This API uses a promise to return the result. This API can be used in scenarios where screenshots are supported.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                      |
| -------- | ------ | ---- | ------------------------------------------ |
| savePath | string | Yes  | File save path. The path must be the [sandbox path](../../file-management/app-sandbox-directory.md) of the current application.|

**Return value**

| Type             | Description                                       |
| ----------------- |-------------------------------------------|
| Promise\<boolean> | Promise used to return whether the screenshot operation is successful. The value **true** indicates that the screen capture operation is successful, and **false** indicates the opposite.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### screenCap<sup>20+</sup>

screenCap(savePath: string, displayId: number): Promise\<boolean>

Captures the specified screen and saves it as a PNG image to the specified path. This API uses a promise to return the result. This API can be used in scenarios where screenshots are supported.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                      |
| -------- | ------ | ---- | ------------------------------------------ |
| savePath | string | Yes  | File save path. The path must be the [sandbox path](../../file-management/app-sandbox-directory.md) of the current application.|
| displayId     | number | Yes | Display ID. The value is an integer greater than or equal to 0.<br> **Note**: If the input **displayId** does not exist, the exception **17000007** is reported.                 |

**Return value**

| Type             | Description                                       |
| ----------------- |-------------------------------------------|
| Promise\<boolean> | Promise used to return whether the screenshot operation is successful. The value **true** indicates that the screen capture operation is successful, and **false** indicates the opposite.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.screenCap('/data/storage/el2/base/cache/1.png', 0);
}
```

### setDisplayRotation<sup>9+</sup>

setDisplayRotation(rotation: DisplayRotation): Promise\<void>

Sets the display rotation of the current scene to the specified direction. This API uses a promise to return the result. It applies to rotatable scenarios.

> **NOTE**
>
> This API takes effect only on phones, tablets, and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type                                | Mandatory| Description            |
| -------- | ------------------------------------ | ---- | ---------------- |
| rotation | [DisplayRotation](#displayrotation9) | Yes  | Display rotation of the device.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Obtains the display rotation of the current device. This API uses a promise to return the result.

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

### getDisplayRotation<sup>20+</sup>

getDisplayRotation(displayId: number): Promise\<DisplayRotation>

Obtains the display rotation of the specified device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                      |
| -------- | ------ | ---- | ------------------------------------------ |
| displayId     | number | Yes | Display ID. The value is an integer greater than or equal to 0.<br> **Note**: If the input **displayId** does not exist, the exception **17000007** is reported.                 |

**Return value**

| Type                                          | Description                                   |
| ---------------------------------------------- | --------------------------------------- |
| Promise\<[DisplayRotation](#displayrotation9)> | Promise used to return the display rotation of the specified device.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 |  Parameter verification failed. |

**Example**

```ts
import { DisplayRotation, Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  let rotation: DisplayRotation = await driver.getDisplayRotation(0);
}
```

### setDisplayRotationEnabled<sup>9+</sup>

setDisplayRotationEnabled(enabled: boolean): Promise\<void>

Sets whether to enable the screen rotation feature. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on phones, tablets, and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type   | Mandatory| Description                                                   |
| ------- | ------- | ---- | ------------------------------------------------------- |
| enabled | boolean | Yes  | Whether the screen can be rotated. The value **true** indicates that the screen can be rotated, and **false** indicates the opposite.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Obtains the display size of the current device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                      | Description                                   |
| -------------------------- | --------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the **Point** object. The size of the current device screen is **Point.x * Point.y**.|

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
  let size = await driver.getDisplaySize();
}
```

### getDisplaySize<sup>20+</sup>

getDisplaySize(displayId: number): Promise\<Point>

Obtains the size of the specified display of the current device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                      |
| -------- | ------ | ---- | ------------------------------------------ |
| displayId     | number | Yes | Display ID. The value is an integer greater than or equal to 0.<br> **Note**: If the input **displayId** does not exist, the exception **17000007** is reported.              |

**Return value**

| Type                      | Description                                   |
| -------------------------- | --------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the **Point** object. The size of the specified display is **Point.x * Point.y**.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 |  Parameter verification failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  let size = await driver.getDisplaySize(0);
}
```

### getDisplayDensity<sup>9+</sup>

getDisplayDensity(): Promise\<Point>

Obtains the display density of the current device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                      | Description                                     |
| -------------------------- | ----------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the **Point** object. The density of the current device display is **Point.x*Point.y**.|

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

### getDisplayDensity<sup>20+</sup>

getDisplayDensity(displayId: number): Promise\<Point>

Obtains the density of the specified display of the current device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                      |
| -------- | ------ | ---- | ------------------------------------------ |
| displayId | number | Yes | Display ID. The value is an integer greater than or equal to 0.<br> **Note**: If the input **displayId** does not exist, the exception **17000007** is reported.                 |

**Return value**

| Type                      | Description                                     |
| -------------------------- | ----------------------------------------- |
| Promise\<[Point](#point9)> | Promise used to return the **Point** object. The density of the specified display is **Point.x*Point.y**.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 |  Parameter verification failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  let density = await driver.getDisplayDensity(0);
}
```

### wakeUpDisplay<sup>9+</sup>

wakeUpDisplay(): Promise\<void>

Wakes up the current display. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Injects an operation of returning to the home screen on the device. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on phones, tablets, and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

### pressHome<sup>20+</sup>

pressHome(displayId: number): Promise\<void>

Injects the operation of returning to the home screen on the specified display. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on phones, tablets, and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                      |
| -------- | ------ | ---- | ------------------------------------------ |
| displayId     | number | Yes | Display ID. The value is an integer greater than or equal to 0.<br> **Note**: If the input **displayId** does not exist, the exception **17000007** is reported.                 |

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000007 |  Parameter verification failed. |

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.pressHome(0);
}
```

### waitForIdle<sup>9+</sup>

waitForIdle(idleTime: number, timeout: number): Promise\<boolean>

Checks whether all components on the current page are idle. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| idleTime | number | Yes  | Idle time threshold, in ms. If the duration for which a component remains inactive reaches this threshold, it is considered as idle. The value must be an integer greater than or equal to 0.|
| timeout  | number | Yes  | Maximum waiting time, in milliseconds. The value is an integer greater than or equal to 0.                   |

**Return value**

| Type             | Description                                               |
| ----------------- |---------------------------------------------------|
| Promise\<boolean> | Promise used to return whether all components on the current UI are idle. The value true indicates that all components on the current UI are idle, and false indicates the opposite.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Simulates a fling operation. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type            | Mandatory| Description                                                  |
| ------- | ---------------- | ---- |------------------------------------------------------|
| from    | [Point](#point9) | Yes  | Coordinates of the point where the finger touches the screen.                                       |
| to      | [Point](#point9) | Yes  | Coordinates of the point where the finger leaves the screen.                                        |
| stepLen | number           | Yes  | Step length, in pixels. The value is an integer greater than or equal to 0.                                        |
| speed   | number           | Yes  | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.fling({x: 500, y: 480},{x: 450, y: 480}, 5, 600);
}
```

### injectMultiPointerAction<sup>9+</sup>

injectMultiPointerAction(pointers: PointerMatrix, speed?: number): Promise\<boolean>

Injects a multi-finger operation into a device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type                            | Mandatory| Description                                                    |
| -------- | -------------------------------- | ---- |--------------------------------------------------------|
| pointers | [PointerMatrix](#pointermatrix9) | Yes  | Scroll trajectory, including the number of fingers and an array of coordinates along the trajectory.                                 |
| speed    | number                           | No  | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type             | Description                                 |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | Promise used to return whether the operation is successful. The value **true** indicates that the operation is successful, and **false** indicates the opposite.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                              |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, PointerMatrix } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  let pointers: PointerMatrix = PointerMatrix.create(2, 5);
  pointers.setPoint(0, 0, {x:250, y:480});
  pointers.setPoint(0, 1, {x:250, y:440});
  pointers.setPoint(0, 2, {x:250, y:400});
  pointers.setPoint(0, 3, {x:250, y:360});
  pointers.setPoint(0, 4, {x:250, y:320});
  pointers.setPoint(1, 0, {x:250, y:480});
  pointers.setPoint(1, 1, {x:250, y:440});
  pointers.setPoint(1, 2, {x:250, y:400});
  pointers.setPoint(1, 3, {x:250, y:360});
  pointers.setPoint(1, 4, {x:250, y:320});
  await driver.injectMultiPointerAction(pointers);
}
```

### fling<sup>10+</sup>

fling(direction: UiDirection, speed: number): Promise\<void>;

Simulates a fling operation with the specified direction and speed. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name   | Type                         | Mandatory| Description                                                    |
| --------- | ----------------------------- | ---- |--------------------------------------------------------|
| direction | [UiDirection](#uidirection10) | Yes  | Direction of the fling operation.                                              |
| speed     | number                        | Yes  | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### fling<sup>20+</sup>

fling(direction: UiDirection, speed: number, displayId: number): Promise\<void>

Simulates a fling operation on a specified display with the specified direction and speed. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name   | Type                         | Mandatory| Description                                                    |
| --------- | ----------------------------- | ---- |--------------------------------------------------------|
| direction | [UiDirection](#uidirection10) | Yes  | Direction of the fling operation.                                              |
| speed     | number                        | Yes  | Fling speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|
| displayId     | number | Yes | Display ID. The value is an integer greater than or equal to 0.<br> **Note**: If the input **displayId** does not exist, the exception **17000007** is reported.                 |

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, UiDirection } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.fling(UiDirection.DOWN, 10000, 0);
}
```

### screenCapture<sup>10+</sup>

screenCapture(savePath: string, rect?: Rect): Promise\<boolean>;

Captures the specified area of the current screen and saves it as a PNG image to the specified path. This API uses a promise to return the result. This API can be used in scenarios where screenshots are supported.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type          | Mandatory| Description                                      |
| -------- | -------------- | ---- | ------------------------------------------ |
| savePath | string         | Yes  | File save path. The path must be the [sandbox path](../../file-management/app-sandbox-directory.md) of the current application.|
| rect     | [Rect](#rect9) | No  | Area of the screen to capture. The default value is the entire screen.                    |

**Return value**

| Type             | Description                                         |
| ----------------- |---------------------------------------------|
| Promise\<boolean> | Promise used to return whether the screenshot operation is successful. The value **true** indicates the screenshot operation is successful, and **false** indicates the opposite.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Injects a mouse click action at a specified coordinate point and presses the corresponding combination key at the same time. This API uses a promise to return the result. For example, if the value of **key1** is **2072**, the **Ctrl** button is pressed with the mouse click.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                         | Mandatory| Description                          |
| ------ | ----------------------------- | ---- | ------------------------------ |
| p      | [Point](#point9)              | Yes  | Coordinates of the mouse click.              |
| btnId  | [MouseButton](#mousebutton10) | Yes  | Mouse button pressed.              |
| key1   | number                        | No  | First key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|
| key2   | number                        | No  | Second key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Injects a mouse scrolling action at a specified coordinate point and presses the corresponding combination key at the same time. This API uses a promise to return the result. For example, if the value of **key1** is **2072**, the **Ctrl** button is pressed with mouse scrolling.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description                                                       |
| ------ | ---------------- | ---- | ----------------------------------------------------------- |
| p      | [Point](#point9) | Yes  | Coordinates of the mouse click.                                           |
| down   | boolean          | Yes  | Whether the scroll wheel scrolls downward. The value **true** indicates the scroll wheel scrolls downward, and **false** indicates the scroll wheel scrolls upward.|
| d      | number           | Yes  | Number of ticks scrolled by the mouse wheel. A tick indicates a 120 px shift to the target point. The value is an integer greater than or equal to 0.        |
| key1   | number           | No  | First key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.                             |
| key2   | number           | No  | Second key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.                             |

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseScroll({x:360, y:640}, true, 30, 2072);
}
```

### mouseMoveTo<sup>10+</sup>

mouseMoveTo(p: Point): Promise\<void>;

Moves the cursor to the target point. This API uses a promise to return the result.

**System capability**: SystemCapability.Test.UiTest

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type            | Mandatory| Description          |
| ------ | ---------------- | ---- | -------------- |
| p      | [Point](#point9) | Yes  | Coordinates of the end point.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseMoveTo({x:100, y:100});
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
  let observer: UIEventObserver = await driver.createUIEventObserver();
}
```

### mouseScroll<sup>11+</sup>

mouseScroll(p: Point, down: boolean, d: number, key1?: number, key2?: number, speed?: number): Promise\<void>

Injects a mouse wheel scrolling action at the specified coordinate point. The corresponding combination key can be pressed at the same time and the scrolling speed can be specified. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description                                                        |
| ------ | ---------------- | ---- | ------------------------------------------------------------ |
| p      | [Point](#point9) | Yes  | Coordinates of the mouse click.                                            |
| down   | boolean          | Yes  | Whether the scroll wheel scrolls downward. The value **true** indicates the scroll wheel scrolls downward, and **false** indicates the scroll wheel scrolls upward. |
| d      | number           | Yes  | Number of ticks scrolled by the mouse wheel. A tick indicates a 120 px shift to the target point. The value is an integer greater than or equal to 0.         |
| key1   | number           | No  | First key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.                              |
| key2   | number           | No  | Second key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.                              |
| speed  | number           | No  | Scroll speed of the mouse wheel, in ticks/second. The value is an integer ranging from 1 to 500. If the value is not within the range, the default value **20** will be used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseScroll({x:360, y:640}, true, 30, 2072,20);
}
```

### mouseDoubleClick<sup>11+</sup>

mouseDoubleClick(p: Point, btnId: MouseButton, key1?: number, key2?: number): Promise\<void>

Injects a mouse double-click action at a specified coordinate point. The corresponding combination key can be pressed at the same time. This API uses a promise to return the result. For example, if the value of **key** is **2072**, the **Ctrl** button is pressed with the double-click.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                         | Mandatory| Description                          |
| ------ | ----------------------------- | ---- | ------------------------------ |
| p      | [Point](#point9)              | Yes  | Coordinates of the double-click.              |
| btnId  | [MouseButton](#mousebutton10) | Yes  | Mouse button pressed.              |
| key1   | number                        | No  | First key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|
| key2   | number                        | No  | Second key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Injects a mouse long-click action at a specified coordinate point. The corresponding combination key can be pressed at the same time. This API uses a promise to return the result. For example, if the value of **Key** is **2072**, the **Ctrl** button is long-clicked with the mouse device.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                         | Mandatory| Description                          |
| ------ | ----------------------------- | ---- | ------------------------------ |
| p      | [Point](#point9)              | Yes  | Coordinates of the long-click of the mouse device.              |
| btnId  | [MouseButton](#mousebutton10) | Yes  | Mouse button pressed.              |
| key1   | number                        | No  | First key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|
| key2   | number                        | No  | Second key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### mouseLongClick<sup>20+</sup>

mouseLongClick(p: Point, btnId: MouseButton, key1?: number, key2?: number, duration?: number): Promise\<void>

Injects a mouse long-click action at a specified coordinate point. The corresponding combination key can be pressed at the same time and the click duration can be specified. This API uses a promise to return the result. For example, if the value of **Key** is **2072**, the **Ctrl** button is long-clicked with the mouse device.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                         | Mandatory| Description                          |
| -------- | ----------------------------- | ---- | ------------------------------ |
| p        | [Point](#point9)              | Yes  | Coordinates of the long-click of the mouse device.              |
| btnId    | [MouseButton](#mousebutton10) | Yes  | Mouse button pressed.              |
| key1     | number                        | No  | First key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|
| key2     | number                        | No  | Second key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode). The default value is 0.|
| duration | number | No  | Long-click duration, in ms. The value is an integer greater than or equal to 1500. The default value is 1500.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver,MouseButton } from '@kit.TestKit';

async function demo() {
  let driver:Driver = Driver.create();
  await driver.mouseLongClick({x:248, y:194}, MouseButton.MOUSE_BUTTON_LEFT, 2072, 0, 2000);
}
```

### mouseMoveWithTrack<sup>11+</sup>

mouseMoveWithTrack(from: Point, to: Point, speed?: number): Promise\<void>

Moves the mouse from the start point to the end point. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description                                                    |
| ------ | ---------------- | ---- |--------------------------------------------------------|
| from   | [Point](#point9) | Yes  | Coordinates of the start point.                                                |
| to     | [Point](#point9) | Yes  | Coordinates of the end point.                                                 |
| speed  | number           | No  | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseMoveWithTrack({x:100, y:100}, {x:200, y:200}, 600);
}
```

### mouseDrag<sup>11+</sup>

mouseDrag(from: Point, to: Point, speed?: number): Promise\<void>

Drags the mouse from the start point to the end point with the left mouse button clicked. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on phones, tablets, and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description                                                    |
| ------ | ---------------- | ---- |--------------------------------------------------------|
| from   | [Point](#point9) | Yes  | Coordinates of the start point.                                                |
| to     | [Point](#point9) | Yes  | Coordinates of the end point.                                                 |
| speed  | number           | No  | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseDrag({x:100, y:100},{x:200, y:200}, 600);
}
```

### mouseDrag<sup>20+</sup>

mouseDrag(from: Point, to: Point, speed?: number, duration?: number): Promise\<void>

Drags the mouse from the start point to the end point with the left mouse button clicked. You can specify the drag speed and click duration before dragging. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on phones, tablets, and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type            | Mandatory| Description                                                    |
| --------- | ---------------- | ---- |--------------------------------------------------------|
| from      | [Point](#point9) | Yes  | Coordinates of the start point.                                                |
| to        | [Point](#point9) | Yes  | Coordinates of the end point.                                                 |
| speed     | number           | No  | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|
| duration  | number | No  | Click duration, in ms. The value is an integer greater than or equal to 1500. The default value is 1500.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  await driver.mouseDrag({x:100, y:100},{x:200, y:200}, 600, 2000);
}
```

### inputText<sup>11+</sup>

inputText(p: Point, text: string): Promise\<void>

Inputs text at a specified coordinate without clearing the original text in the component. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description              |
| ------ | ---------------- | ---- | ------------------ |
| p      | [Point](#point9) | Yes  | Coordinates of the end point.|
| text   | string           | Yes  |Input text. Currently, English, Chinese, and special characters are supported.<br> **Note**: For wearables, this API does not support Chinese characters.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

### inputText<sup>20+</sup>

inputText(p: Point, text: string, mode: InputTextMode): Promise\<void>

Inputs text at a specified coordinate point in a specified input mode. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type            | Mandatory| Description              |
| ------ | ---------------- | ---- | ------------------ |
| p      | [Point](#point9) | Yes  | Coordinates of the end point.|
| text   | string           | Yes  |Input text. Currently, English, Chinese, and special characters are supported.<br> **Note**: For wearables, this API does not support Chinese characters.|
| mode | [InputTextMode](#inputtextmode20) | Yes  | Text input mode. For details, see [InputTextMode](#inputtextmode20).<br> **Note**: If **InputTextMode.addition** is set to true, the cursor moves to the end of the text and the specified text is input. If the value is **false**, the specified text is input at the coordinate point.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not support, function can not work correctly due to limited device capabilities.|

**Example**

```ts
import { Component, Driver, ON } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  let text: Component = await driver.findComponent(ON.type('TextInput'));
  let point = await text.getBoundsCenter();
  await driver.inputText(point, '123', {paste: true, addition: false});
}

async function demo_Chinese() {
  let driver: Driver = Driver.create();
  let text: Component = await driver.findComponent(ON.type('TextInput'));
  let point = await text.getBoundsCenter();
  await driver.inputText(point, 'Chinese&', { paste: false, addition: true });
  // Copy and paste Chinese and a special character to the end of the specified text.
}
```

### touchPadMultiFingerSwipe<sup>18+</sup>

touchPadMultiFingerSwipe(fingers: number, direction: UiDirection, options?: TouchPadSwipeOptions): Promise\<void>

Simulates a multi-finger swipe gesture on the touchpad. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                                           | Mandatory| Description                   |
| ------ |-----------------------------------------------|----|-----------------------|
| fingers      | number                                        | Yes | Number of fingers. The value can be 3 or 4.|
| direction | [UiDirection](#uidirection10)                 | Yes | Swipe direction.          |
| options      | [TouchPadSwipeOptions](#touchpadswipeoptions18) | No | Additional options.       |

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 17000005 | This operation is not supported.        |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, UiDirection } from '@kit.TestKit';
async function demo() {
  let driver:Driver = Driver.create();
  await driver.touchPadMultiFingerSwipe(3, UiDirection.UP);
}
```

### penClick<sup>18+</sup>

penClick(point: Point): Promise\<void>

Simulates a pen click. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                                           | Mandatory| Description     |
| ------ |-----------------------------------------------|----|---------|
| point      | [Point](#point9) | Yes  | Coordinates of the clicked point.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.penClick({x: 100, y: 100});
}
```

### penLongClick<sup>18+</sup>

penLongClick(point: Point, pressure?: number): Promise\<void>

Simulates a pen long-click. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                                           | Mandatory| Description                           |
| ------ |-----------------------------------------------|----|-------------------------------|
| point      | [Point](#point9) | Yes | Coordinates of the long-clicked point.                      |
| pressure      | number | No | Swipe pressure of the pen. The value ranges from 0.0 to 1.0. The default value is **1.0**.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.penLongClick({x: 100, y: 100}, 0.5);
}
```

### penDoubleClick<sup>18+</sup>

penDoubleClick(point: Point): Promise\<void>

Simulates a pen double-click. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                                           | Mandatory| Description     |
| ------ |-----------------------------------------------|----|---------|
| point      | [Point](#point9) | Yes | Coordinates of the double-clicked point.|


**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.penDoubleClick({x: 100, y: 100});
}
```

### penSwipe<sup>18+</sup>

penSwipe(startPoint: Point, endPoint: Point, speed?: number, pressure?: number): Promise\<void>

Simulates a pen swipe. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                                           | Mandatory| Description                                                    |
| ------ |-----------------------------------------------|----|--------------------------------------------------------|
| startPoint      | [Point](#point9) | Yes | Coordinates of the start point.                                             |
| endPoint      | [Point](#point9) | Yes | Coordinates of the end point.                                             |
| speed      | number | No | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.|
| pressure      | number | No | Swipe pressure of the pen. The value ranges from 0.0 to 1.0. The default value is **1.0**.                       |

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
 import { Driver } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  await driver.penSwipe({x: 100, y: 100}, {x: 100, y: 500}, 600, 0.5);
}
```

### injectPenPointerAction<sup>18+</sup>

injectPenPointerAction(pointers: PointerMatrix, speed?: number, pressure?: number): Promise\<void>

Simulates a continuous multi-point pen injection. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                                           | Mandatory| Description                                                               |
| ------ |-----------------------------------------------|----|-------------------------------------------------------------------|
| pointers | [PointerMatrix](#pointermatrix9) | Yes |Scroll trajectory, including the number of fingers and an array of coordinates along the trajectory. Currently, only the single-finger operation is supported. The value of **fingers** in **PointerMatrix** must be set to 1.|
| speed      | number| No | Scroll speed, in px/s. The value ranges from 200 to 40000. If the set value is not in the range, the default value **600** is used.           |
| pressure      | number | No | Injection pressure. The value ranges from 0.0 to 1.0. The default value is **1.0**.                                |


**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { Driver, PointerMatrix } from '@kit.TestKit';
async function demo() {
  let driver: Driver = Driver.create();
  let pointer = PointerMatrix.create(1, 8);
  for (let step = 0; step < 8; step++) {
    pointer.setPoint(0, step, {x: 500, y: 1100 - 100 *step});
  }
  await driver.injectPenPointerAction(pointer, 600, 0.5);
}
```

### crownRotate<sup>20+</sup>

crownRotate(d: number, speed?: number): Promise\<void>

Injects a crown rotation event. You can specify the rotation speed. This API uses a promise to return the result.

This API takes effect only on wearables.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type                                        | Mandatory| Description                                                            |
| ------ |-----------------------------------------------|----|-------------------------------------------------------------------|
| d      | number   | Yes  | Number of rotation ticks. A positive value indicates rotation, and a negative value indicates counterclockwise rotation. The value must be an integer.        |
| speed  | number   | No  | Rotation speed, in ticks/s. The value is an integer ranging from 1 to 500. The default value is 20.<br> **Note**: If the set value is not in the range, the default value 20 is used.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17000002 | The async function is not called with await.             |
| 17000007 |  Parameter verification failed. |
| 801 | Capability not support, function can not work correctly due to limited device capabilities. |

**Example**

```ts
import { Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  // Rotate 50 ticks clockwise at a speed of 30 ticks per second.
  await driver.crownRotate(50, 30);
  // Rotate 20 ticks counterclockwise at a speed of 30 ticks per second.
  await driver.crownRotate(-20, 30);
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
| fingers | number | Yes  | Number of fingers injected during the multi-finger operation. The value is an integer ranging from 1 to 10.|
| steps   | number | Yes  | Number of steps performed by a finger. The value is an integer ranging from 1 to 1000.|

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
  let pointerMatrix: PointerMatrix = PointerMatrix.create(2, 3);
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
| finger | number           | Yes  | Number of fingers. The value is an integer greater than or equal to 0 and cannot exceed the number of fingers set when the **PointerMatrix** object is constructed.                                             |
| step   | number           | Yes  | Number of steps. The value is an integer greater than or equal to 0 and cannot exceed the number of steps set when the **PointerMatrix** object is constructed.                                              |
| point  | [Point](#point9) | Yes  | Coordinates of the action. It is recommended that the distance between adjacent coordinates be within the range of 10 px to 80 px.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { PointerMatrix } from '@kit.TestKit';

async function demo() {
  let pointers: PointerMatrix = PointerMatrix.create(2, 5);
  pointers.setPoint(0, 0, {x:250, y:480});
  pointers.setPoint(0, 1, {x:250, y:440});
  pointers.setPoint(0, 2, {x:250, y:400});
  pointers.setPoint(0, 3, {x:250, y:360});
  pointers.setPoint(0, 4, {x:250, y:320});
  pointers.setPoint(1, 0, {x:250, y:480});
  pointers.setPoint(1, 1, {x:250, y:440});
  pointers.setPoint(1, 2, {x:250, y:400});
  pointers.setPoint(1, 3, {x:250, y:360});
  pointers.setPoint(1, 4, {x:250, y:320});
}
```

## UiWindow<sup>9+</sup>

The **UiWindow** class represents a window on the UI and provides APIs for obtaining window attributes, dragging a window, and adjusting the window size.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

### getBundleName<sup>9+</sup>

getBundleName(): Promise\<string>

Obtains the bundle name of the application to which the window belongs. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise\<string> | Promise used to return the bundle name of the application to which the window belongs.|

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

Obtains the border information of a window. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                    | Description                             |
| ------------------------ | --------------------------------- |
| Promise\<[Rect](#rect9)> | Promise used to return the window border information.|

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

Obtains the window title. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the window title.|

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
  let title = await window.getTitle();
}
```

### getWindowMode<sup>9+</sup>

getWindowMode(): Promise\<WindowMode>

Obtains the window mode information. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                                | Description                                 |
| ------------------------------------ | ------------------------------------- |
| Promise\<[WindowMode](#windowmode9)> | Promise used to return the window mode information.|

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

Checks whether the window is focused. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return whether the window is focused. The value **true** indicates that the window is focused, and **false** indicates the opposite.|

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
| Promise\<boolean> | Promise used to return whether the window is active. The value **true** indicates that the window is active, and **false** indicates the opposite.|

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

Focuses the window. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Moves a window to the target point. This API uses a promise to return the result. This API is applicable to moveable windows.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| ------ | ------ | ---- | ----------------------------------------------- |
| x      | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.|
| y      | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Resizes the window based on the specified width, height, and direction. This API uses a promise to return the result. This API is applicable to resizable windows.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name   | Type                                | Mandatory| Description                                                        |
| --------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| wide      | number                               | Yes  | Width of the adjusted window, in number format. The value is an integer greater than or equal to 0.                        |
| height    | number                               | Yes  | Height of the adjusted window, in number format. The value is an integer greater than or equal to 0.                        |
| direction | [ResizeDirection](#resizedirection9) | Yes  | Resize direction.|

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [Uitest Error Codes](errorcode-uitest.md).

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

Switches to the split-screen mode. This API uses a promise to return the result. This API is applicable to windows that support screen splitting.

> **NOTE**
>
> This API takes effect only on tablets and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Maximizes a window. This API uses a promise to return the result. This API is applicable to windows that can be maximized.

> **NOTE**
>
> This API takes effect only on tablets and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Minimizes a window. This API uses a promise to return the result. This API is applicable to windows that can be minimized.

> **NOTE**
>
> This API takes effect only on tablets and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Restores a window to its previous mode. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on tablets and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Closes a window. This API uses a promise to return the result.

> **NOTE**
>
> This API takes effect only on tablets and PCs/2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description             |
|----------------|-----------------|
| Promise\<void> | Promise that returns no value.|

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

Checks whether this window is active. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return whether the window is active. The value **true** indicates that the window is active, and **false** indicates the opposite.|

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

### getDisplayId<sup>20+</sup>

getDisplayId(): Promise\<number>

Obtains the ID of the display to which the window belongs. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                  |
| ---------------- |----------------------|
| Promise\<number> | Promise used to return the ID of the display to which the window belongs.|

**Error codes**

For details about the error codes, see [UiTest Error Codes](errorcode-uitest.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17000002 | The async function is not called with await. |
| 17000004 | The window or component is invisible or destroyed.           |

**Example**

```ts
import { UiWindow, Driver } from '@kit.TestKit';

async function demo() {
  let driver: Driver = Driver.create();
  let window: UiWindow = await driver.findWindow({active: true});
  let id = await window.getDisplayId();
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
  let observer:  UIEventObserver = await driver.createUIEventObserver();
  let  callback = (UIElementInfo: UIElementInfo)=>{
    console.info(UIElementInfo.bundleName);
    console.info(UIElementInfo.text);
    console.info(UIElementInfo.type);
  }
  observer.once('toastShow', callback);
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
  let observer: UIEventObserver = await driver.createUIEventObserver();
  let  callback = (UIElementInfo: UIElementInfo)=>{
    console.info(UIElementInfo.bundleName);
    console.info(UIElementInfo.text);
    console.info(UIElementInfo.type);
  }
  observer.once('dialogShow', callback);
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
| b      | boolean | No  | Clickable status of the component. The value **true** indicates that the component is clickable, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Scrollable status of the component. The value **true** indicates that the component is scrollable, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Enabled status of the component. The value **true** indicates that the component is enabled, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Focused status of the component. The value **true** indicates that the component is focused, and **false** indicates the opposite. Default value: **true**|

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
| b      | boolean | No  | Selected status of the component. The value **true** indicates that the component is selected, and **false** indicates the opposite. Default value: **true**|

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
| Promise\<number> | Promise used to return the component ID.|

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
| Promise\<string> | Promise used to return the key value.|

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
| Promise\<string> | Promise used to return the original text information of the component.|

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
| Promise\<string> | Promise used to return the component type.|

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
| Promise\<boolean> | Promise used to return whether the component is clickable. The value **true** indicates that the component is clickable, and **false** indicates the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  if (await button.isClickable()) {
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
| Promise\<boolean> | Promise used to return whether the component is scrollable. The value **true** indicates that the component is scrollable, and **false** indicates the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let scrollBar: UiComponent = await driver.findComponent(BY.scrollable(true));
  if (await scrollBar.isScrollable()) {
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
| Promise\<boolean> | Promise used to return whether the component is enabled. The value **true** indicates that the component is enabled, and **false** indicates the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  if (await button.isEnabled()) {
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
| Promise\<boolean> | Promise used to return whether the component is focused. The value **true** indicates that the window is focused, and **false** indicates the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  if (await button.isFocused()) {
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
| Promise\<boolean> | Promise used to return whether the component is selected. The value **true** indicates that the component is selected, and **false** indicates the opposite.|

**Example**

```ts
import { UiDriver, BY, UiComponent } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  let button: UiComponent = await driver.findComponent(BY.type('Button'));
  if (await button.isSelected()) {
    console.info('This button is selected');
  } else {
    console.info('This button is not selected');
  }
}
```

### inputText<sup>(deprecated)</sup>

inputText(text: string): Promise\<void>

Inputs text into a component (applicable to text box components).

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

Scrolls on this component to search for the target component (applicable to components that support scrolling, such as **List**).

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
| Promise\<[UiComponent](#uicomponentdeprecated)> | Promise used to return the component.|

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
| Promise\<Array\<[UiComponent](#uicomponentdeprecated)>> | Promise used to return the list of components.|

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
| keyCode | number | Yes  | Key value. The value is an integer greater than or equal to 0. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode).|

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
| x      | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.|
| y      | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';

async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.click(100, 100);
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
| x      | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.|
| y      | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';

async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.doubleClick(100, 100);
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
| x      | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.|
| y      | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.longClick(100, 100);
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
| startx | number | Yes  | Number, which indicates the horizontal coordinate of the start point. The value is an integer greater than or equal to 0.|
| starty | number | Yes  | Number, which indicates the vertical coordinate of the start point. The value is an integer greater than or equal to 0.|
| endx   | number | Yes  | Number, which indicates the horizontal coordinate of the target point. The value is an integer greater than or equal to 0.|
| endy   | number | Yes  | Number, which indicates the vertical coordinate of the target point. The value is an integer greater than or equal to 0.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';

async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.swipe(100, 100, 200, 200);
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


| Type             | Description                                           |
| ----------------- |-----------------------------------------------|
| Promise\<boolean> | Promise used to return whether the screenshot operation is successful. The value **true** indicates the screenshot operation is successful, and **false** indicates the opposite.|

**Example**

```ts
import { UiDriver } from '@kit.TestKit';
async function demo() {
  let driver: UiDriver = UiDriver.create();
  await driver.screenCap('/data/storage/el2/base/cache/1.png');
}
```
