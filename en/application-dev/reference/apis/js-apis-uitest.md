# UiTest

The **UiTest** module provides APIs that you can use to simulate UI actions during testing, such as clicks, double-clicks, long-clicks, and swipes.

This module provides the following functions:

- [By](#by): provides UI component feature description APIs for component filtering and matching.
- [UiComponent](#uicomponent): represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
- [UiDriver](#uidriver): works as the entry class and provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot.
- [UiWindow<sup>9+</sup>](#uiwindow9): works as the entry class and provides APIs for obtaining window attributes, dragging windows, and adjusting window sizes.

>**NOTE**<br>
>
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import {UiDriver, BY, MatchPattern, ResizeDirection, WindowMode} from '@ohos.uitest'
```

## By

The UiTest framework provides a wide range of UI component feature description APIs in the **By** class to filter and match components.
The API capabilities provided by the **By** class exhibit the following features: <br>1. Allow one or more attributes as the match conditions. For example, you can specify both the **text** and **id** attributes to find the target component. <br>2. Provide multiple match patterns for component attributes. <br>3. Support absolute positioning and relative positioning for components. APIs such as [By.isBefore](#isbefore) and [By.isAfter](#isafter) can be used to specify the features of adjacent components to assist positioning. <br>All APIs provided in the **By** class are synchronous. You are advised to use the static constructor **BY** to create a **By** object in chain mode.

```js
BY.text('123').type('button')
```

### text

text(txt: string, pattern?: MatchPattern): By

Specifies the text attribute of the target component. Multiple match patterns are supported.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type        | Mandatory| Description                                             |
| ------- | ------------ | ---- | ------------------------------------------------- |
| txt     | string       | Yes  | Component text, used to match the target component.             |
| pattern | MatchPattern | No  | Match pattern. The default value is [EQUALS](#matchpattern).|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.text('123') // Use the static constructor BY to create a By object and specify the text attribute of the target component.
```


### key

key(key: string): By

Specifies the key attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description             |
| ------ | ------ | ---- | ----------------- |
| key    | string | Yes  | Component key.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.key('123') // Use the static constructor BY to create a By object and specify the key attribute of the target component.
```


### id

id(id: number): By

Specifies the ID attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| id     | number | Yes  | Component ID.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.id(123) // Use the static constructor BY to create a By object and specify the id attribute of the target component.
```


### type

type(tp: string): By

Specifies the type attribute of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| tp     | string | Yes  | Component type.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.type('button') // Use the static constructor BY to create a By object and specify the type attribute of the target component.
```


### clickable

clickable(b?: bool): By

Specifies the clickable status of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                            |
| ------ | ---- | ---- | -------------------------------- |
| b      | bool | No  | Clickable status of the target component. The default value is **true**.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.clickable(true) // Use the static constructor BY to create a By object and specify the clickable status of the target component.
```

### longClickable<sup>9+</sup>

longClickable(b?: bool): By

Specifies the long-clickable status of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                                |
| ------ | ---- | ---- | ------------------------------------ |
| b      | bool | No  | Long-clickable status of the target component. The default value is **true**.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.longClickable(true) // Use the static constructor BY to create a By object and specify the long-clickable status of the target component.
```


### scrollable

scrollable(b?: bool): By

Specifies the scrollable status of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                        |
| ------ | ---- | ---- | ---------------------------- |
| b      | bool | No  | Scrollable status of the target component. The default value is **true**.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.scrollable(true) // Use the static constructor BY to create a By object and specify the scrollable status of the target component.
```

### enabled

enabled(b?: bool): By

Specifies the enabled status of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                          |
| ------ | ---- | ---- | ------------------------------ |
| b      | bool | No  | Enabled status of the target component. The default value is **true**.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.enabled(true) // Use the static constructor BY to create a By object and specify the enabled status of the target component.
```

### focused

focused(b?: bool): By

Specifies the focused status of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                      |
| ------ | ---- | ---- | -------------------------- |
| b      | bool | No  | Focused status of the target component. The default value is **true**.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.focused(true) // Use the static constructor BY to create a By object and specify the focused status of the target component.
```

### selected

selected(b?: bool): By

Specifies the selected status of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                            |
| ------ | ---- | ---- | -------------------------------- |
| b      | bool | No  | Selected status of the target component. The default value is **true**.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.selected(true) // Use the static constructor BY to create a By object and specify the selected status of the target component.
```

### checked<sup>9+</sup>

checked(b?: bool): By

Specifies the checked status of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                             |
| ------ | ---- | ---- | --------------------------------- |
| b      | bool | No  | Checked status of the target component. The default value is **false**.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.checked(true) // Use the static constructor BY to create a By object and specify the checked status of the target component.
```

### checkable<sup>9+</sup>

checkable(b?: bool): By

Specifies the checkable status of the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                                 |
| ------ | ---- | ---- | ------------------------------------- |
| b      | bool | No  | Checkable status of the target component. The default value is **false**.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.checkable(true) // Use the static constructor BY to create a By object and specify the checkable status of the target component.
```

### isBefore

isBefore(by: By): By

Specifies the attributes of the component before which the target component is located.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| by     | By   | Yes  | Attributes of the component before which the target component is located.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.isBefore(BY.text('123')) // Use the static constructor BY to create a By object and specify the attributes of the component before which the target component is located.
```

### isAfter

isAfter(by: By): By

Specifies the attributes of the component after which the target component is located.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| by     | By   | Yes  | Attributes of the component before which the target component is located.|

**Return value**

| Type| Description            |
| ---- | ---------------- |
| By   | Returns the **By** object itself.|

**Example**

```js
let by = BY.isAfter(BY.text('123')) // Use the static constructor BY to create a By object and specify the attributes of the component after which the target component is located.
```

## UiComponent

In **UiTest**, the **UiComponent** class represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

### Point<sup>9+</sup>

Provides the coordinates of a point.

| Name| Type| Readable| Writable| Description            |
| ---- | -------- | ---- | ---- | ---------------- |
| X    | number   | Yes  | No  | X-coordinate of a point.|
| Y    | number   | Yes  | No  | Y-coordinate of a point.|

### Rect<sup>9+</sup>

Provides bounds information of a component.

| Name   | Type| Readable| Writable| Description                     |
| ------- | -------- | ---- | ---- | ------------------------- |
| leftX   | number   | Yes  | No  | X-coordinate of the upper left corner of the component bounds.|
| topY    | number   | Yes  | No  | Y-coordinate of the upper left corner of the component bounds.|
| rightX  | number   | Yes  | No  | X-coordinate of the lower right corner of the component bounds.|
| bottomY | number   | Yes  | No  | Y-coordinate of the lower right corner of the component bounds.|

### UiComponent.click

click(): Promise\<void>

Clicks this component.

**System capability**: SystemCapability.Test.UiTest

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.click()
}
```

### doubleClick

doubleClick(): Promise\<void>

Double-clicks this component.

**System capability**: SystemCapability.Test.UiTest

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.doubleClick()
}
```

### longClick

longClick(): Promise\<void>

Long-clicks this component.

**System capability**: SystemCapability.Test.UiTest

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.longClick()
}
```

### getId

getId(): Promise\<number>

Obtains the ID of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                           |
| ---------------- | ------------------------------- |
| Promise\<number> | Promise used to return the ID of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let num = await button.getId()
}
```

### getKey

getKey(): Promise\<string>

Obtains the key of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                          |
| ---------------- | ------------------------------ |
| Promise\<string> | Promise used to return the key of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let str_key = await button.getKey()
}
```

### getText

getText(): Promise\<string>

Obtains the text information of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the text information of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let text = await button.getText()
}
```

### getType

getType(): Promise\<string>

Obtains the type of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                         |
| ---------------- | ----------------------------- |
| Promise\<string> | Promise used to return the type of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let type = await button.getType()
}
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

Obtains the bounds of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<Rect> | Promise used to return the bounds of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let rect = await button.getBounds()
}
```

### getBoundsCenter<sup>9+</sup>

getBoundsCenter(): Promise\<Point>

Obtains the bound center information of a component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type           | Description                                   |
| --------------- | --------------------------------------- |
| Promise\<Point> | Promise used to return the bound center information.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let point = await button.getBoundsCenter()
}
```

### isClickable

isClickable(): Promise\<bool>

Obtains the clickable status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<bool> | Promise used to return the clickable status of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    if(await button.isClickable()) {
        console.info('This button can be Clicked')
    }
    else{
        console.info('This button can not be Clicked')
    }
}
```

### isLongClickable<sup>9+</sup>

isLongClickable(): Promise\<bool> 

Obtains the long clickable status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                                       |
| -------------- | ------------------------------------------- |
| Promise\<bool> | Promise used to return the long clickable status of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    if(await button.isLongClickable()) {
        console.info('This button can longClick')
    }
    else{
        console.info('This button can not longClick')
    }
}
```

### isChecked<sup>9+</sup>

isChecked(): Promise\<bool>

Obtains the checked status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<bool> | Promise used to return the checked status of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let checkBox = await driver.findComponent(BY.type('Checkbox'))
    if(await checkBox.isChecked) {
        console.info('This checkBox is checked')
    }
    else{
        console.info('This checkBox is not checked')
    }
}
```

### isCheckable<sup>9+</sup>

isCheckable(): Promise\<bool>

Obtains the checked status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                                       |
| -------------- | ------------------------------------------- |
| Promise\<bool> | Promise used to return the checked status of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let checkBox = await driver.findComponent(BY.type('Checkbox'))
    if(await checkBox.isCheckable) {
        console.info('This checkBox is checkable')
    }
    else{
        console.info('This checkBox is not checkable')
    }
}
```

### isScrollable

isScrollable(): Promise\<bool>

Obtains the scrollable status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<bool> | Promise used to return the scrollable status of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.scrollable(true))
    if(await scrollBar.isScrollable()) {
        console.info('This scrollBar can be operated')
    }
    else{
        console.info('This scrollBar can not be operated')
    }
}
```


### isEnabled

isEnabled(): Promise\<bool>

Obtains the enabled status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise\<bool> | Promise used to return the enabled status of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    if(await button.isEnabled()) {
        console.info('This button can be operated')
    }
    else{
        console.info('This button can not be operated')
    }
}

```

### isFocused

isFocused(): Promise\<bool>

Obtains the focused status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return the focused status of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    if(await button.isFocused()) {
        console.info('This button is focused')
	}
    else{
        console.info('This button is not focused')
	}
}
```

### isSelected

isSelected(): Promise\<bool>

Obtains the selected status of this component.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                |
| -------------- | -------------------- |
| Promise\<bool> | Promise used to return the selected status of the component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    if(await button.isSelected()) {
        console.info('This button is selected')
	}
    else{
        console.info('This button is not selected')
    }
}
```

### inputText

inputText(text: string): Promise\<void>

Enters text into this component (available for text boxes).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| text   | string | Yes  | Text to enter.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let text = await driver.findComponent(BY.text('hello world'))
    await text.inputText('123')
}
```

### clearText<sup>9+</sup>

clearText(): Promise\<void>

Clears text in this component. This API is applicable to text boxes.

**System capability**: SystemCapability.Test.UiTest

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let text = await driver.findComponent(BY.text('hello world'))
    await text.clearText()
}
```

### scrollSearch

scrollSearch(by: By): Promise\<UiComponent>

Scrolls on this component to search for the target component (applicable to component that support scrolling, such as **\<List>**).

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | ---- | ---- | -------------------- |
| by     | By   | Yes  | Attributes of the target component.|

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise\<UiComponent> | Promise used to return the target component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.type('Scroll'))
    let button = await scrollBar.scrollSearch(BY.text('next page'))
}
```

### scrollToTop<sup>9+</sup>

scrollToTop(speed?: number): Promise\<void>

Scrolls to the top of this a component. This API is applicable to components that support scrolling, such as **\<List>**.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| speed  | number | No  | Scroll speed, in pixels/s. The default value is **600**.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.type('Scroll'))
    await scrollBar.scrollToTop()
}
```

### scrollToBottom<sup>9+</sup>

scrollToBottom(speed?: number): Promise\<void>

Scrolls to the bottom of this a component. This API is applicable to components that support scrolling, such as **\<List>**.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| speed  | number | No  | Scroll speed, in pixels/s. The default value is **600**.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.type('Scroll'))
    await scrollBar.scrollToBottom()
}
```

### dragTo<sup>9+</sup>

dragTo(target: UiComponent): Promise\<void>

Drags this component to the target component.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type       | Mandatory| Description      |
| ------ | ----------- | ---- | ---------- |
| target | UiComponent | Yes  | Target component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let text = await driver.findComponent(BY.text('hello world'))
    await button.dragTo(text)
    }
```

### pinchOut<sup>9+</sup>

pinchOut(scale: number): Promise\<void>

Pinches a component to scale it up to the specified ratio.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type       | Mandatory| Description      |
| ------ | ----------- | ---- | ---------- |
| scale  | number      | Yes  | Scale ratio.  |

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let image = await driver.findComponent(BY.type('image'))
    await image.pinchOut(1.5)
    }
```

### pinchIn<sup>9+</sup>

pinchIn(scale: number): Promise\<void>

Pinches a component to scale it down to the specified ratio.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type       | Mandatory| Description      |
| ------ | ----------- | ---- | ---------- |
| scale  | number      | Yes  | Scale ratio.  |

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let image = await driver.findComponent(BY.type('image'))
    await image.pinchIn(0.5)
    }
```

## UiDriver

The **UiDriver** class is the main entry to the UiTest framework. It provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot.
All APIs provided by this class, except for **UiDriver.create()**, use a promise to return the result and must be invoked using **await**.

### create

static create(): UiDriver

Creates a **UiDriver** object and returns the object created. This API is a static API.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type   | Description                    |
| ------- | ------------------------ |
| UiDrive | Returns the **UiDriver** object created.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
}
```

### delayMs

delayMs(duration: number): Promise\<void>

Delays this **UiDriver** object within the specified duration.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description        |
| -------- | ------ | ---- | ------------ |
| duration | number | Yes  | Duration of time.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.delayMs(1000)
}
```

### findComponent

findComponent(by: By): Promise\<UiComponent>

Searches this **UiDriver** object for the target component that matches the given attributes.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | ---- | ---- | -------------------- |
| by     | By   | Yes  | Attributes of the target component.|

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise\<UiComponent> | Promise used to return the found component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.text('next page'))
}
```

### findComponents

findComponents(by: By): Promise\<Array\<UiComponent>>

Searches this **UiDriver** object for all components that match the given attributes.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | ---- | ---- | -------------------- |
| by     | By   | Yes  | Attributes of the target component.|

**Return value**

| Type                         | Description                                   |
| ----------------------------- | --------------------------------------- |
| Promise\<Array\<UiComponent>> | Promise used to return a list of found components.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let buttonList = await driver.findComponents(BY.text('next page'))
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

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
}
```

### waitForComponent<sup>9+</sup>

waitForComponent(by: By, time: number): Promise\<UiComponent>

Searches this **UiDriver** object for the target component that matches the given attributes within the specified duration.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                            |
| ------ | ------ | ---- | -------------------------------- |
| by     | By     | Yes  | Attributes of the target component.            |
| time   | number | Yes  | Duration for searching for the target component, in ms.|

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise\<UiComponent> | Promise used to return the found component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.waitForComponent(BY.text('next page'),500)
}
```

### assertComponentExist   

assertComponentExist(by: By): Promise\<void>

Asserts that a component that matches the given attributes exists on the current page. If the component does not exist, the API throws a JS exception, causing the current test case to fail.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | ---- | ---- | -------------------- |
| by     | By   | Yes  | Attributes of the target component.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.assertComponentExist(BY.text('next page'))
}
```

### pressBack

pressBack(): Promise\<void>

Presses the Back button on this **UiDriver** object.

**System capability**: SystemCapability.Test.UiTest

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.pressBack()
}
```

### triggerKey

triggerKey(keyCode: number): Promise\<void>

Triggers the key of this **UiDriver** object that matches the given key code.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ------------- |
| keyCode | number | Yes  | Key code.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.triggerKey(123)
}
```

### triggerCombineKeys<sup>9+</sup>

triggerCombineKeys(key0: number, key1: number, key2: number): Promise\<void>

Triggers a key combination based on the specified key values. For example, if the key values are (2072, 2019), the **UiDriver** triggers the key combination **Ctrl+C**.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description               |
| ------- | ------ | ---- | ------------------- |
| key0    | number | Yes  | The first key value.|
| key1    | number | Yes  | The second key value.|
| key2    | number | No  | The third key value.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.triggerCombineKeys(2072, 2047, 2035)
}
```


### click

click(x: number, y: number): Promise\<void>

Clicks a specific point of this **UiDriver** object based on the given coordinates.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.click(100,100)
}
```

### doubleClick

doubleClick(x: number, y: number): Promise\<void>

Double-clicks a specific point of this **UiDriver** object based on the given coordinates.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.doubleClick(100,100)
}
```

### longClick

longClick(x: number, y: number): Promise\<void>

Long-clicks a specific point of this **UiDriver** object based on the given coordinates.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X-coordinate of the target point.|
| y      | number | Yes  | Y-coordinate of the target point.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.longClick(100,100)
}
```

### swipe<sup>9+</sup>

swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Swipes on this **UiDriver** object from the start point to the end point based on the given coordinates.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| startx | number | Yes  | X-coordinate of the start point.  |
| starty | number | Yes  | Y-coordinate of the start point.  |
| endx   | number | Yes  | X-coordinate of the end point.  |
| endy   | number | Yes  | Y-coordinate of the end point.  |
| speed  | number | No  | Scroll speed, in pixels/s. The default value is **600**.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.swipe(100,100,200,200,600)
}
```

### drag<sup>9+</sup>

drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Drags this **UiDriver** object from the given start point to the given end point.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| startx | number | Yes  | X-coordinate of the start point.  |
| starty | number | Yes  | Y-coordinate of the start point.  |
| endx   | number | Yes  | X-coordinate of the end point.  |
| endy   | number | Yes  | Y-coordinate of the end point.  |
| speed  | number | No  | Scroll speed, in pixels/s. The default value is **600**.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.drag(100,100,200,200,600)
}
```

### screenCap

screenCap(savePath: string): Promise\<bool>

Captures the current screen of this **UiDriver** object and saves it as a PNG image to the given save path.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description          |
| -------- | ------ | ---- | -------------- |
| savePath | string | Yes  | File save path.|

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<bool> | Promise used to return the operation result. The value **true** means that the operation is successful.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.screenCap('/local/tmp/')
}
```

## UiWindow<sup>9+</sup>

The **UiWindow** class represents a window on the UI and provides APIs for obtaining window attributes, dragging a window, and adjusting the window size.
All APIs provided in this class use a promise to return the result and must be invoked using **await**.

### WindowFilter<sup>9+</sup>

Provides the flag attributes of this window.

**System capability**: SystemCapability.Test.UiTest

| Name      | Type| Mandatory| Readable| Writable| Description                      |
| ---------- | -------- | ---- | ---- | ---- | -------------------------- |
| bundleName | string   | No  | Yes  | No  | Bundle name of the window.          |
| title      | string   | No  | Yes  | No  | Title of the window.              |
| focused    | bool     | No  | Yes  | No  | Whether the window has focus.            |
| actived    | bool     | No  | Yes  | No  | Whether the window is interacting with the user.|

### getBundleName<sup>9+</sup>

getBundleName(): Promise\<string>

Obtains the bundle name of this window.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the bundle name of the window.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let name = await window.getBundleName()
}
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

Obtains the bounds information of this window.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<Rect> | Promise used to return the bounds information of the window.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let rect = await window.getBounds()
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

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let rect = await window.getTitle()
}
```

### getWindowMode<sup>9+</sup>

getWindowMode(): Promise\<WindowMode>

Obtains the window mode of this window.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type                                            | Description                                 |
| ------------------------------------------------ | ------------------------------------- |
| Promise\<[WindowMode](#windowmode9)> | Promise used to return the window mode of the window.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let mode = await window.getWindowMode()
}
```

### isFocused<sup>9+</sup>

isFocused(): Promise\<bool>

Checks whether this window has focus.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return whether the window has focus.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let focused = await window.isFocused()
}
```

### isActived<sup>9+</sup>

isActived(): Promise\<bool>

Checks whether this window is interacting with the user.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                                         |
| -------------- | --------------------------------------------- |
| Promise\<bool> | Promise used to return whether the window is interacting with the user.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let focused = await window.isActived()
}
```

### focus<sup>9+</sup>

focus(): Promise\<bool>

Moves the focus to this window.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return the result.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.focus()
}
```

### moveTo<sup>9+</sup>

moveTo(x: number, y: number): Promise\<bool>;

Moves this window to the target point. This API is applicable to moveable windows.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | Yes  | X coordinate of the target point.|
| y      | number | Yes  | Y coordinate of the target point.|

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return the result.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.moveTo(100, 100)
}
```

### resize<sup>9+</sup>

resize(wide: number, height: number, direction: ResizeDirection): Promise\<bool>

Resizes this window based on the specified width, height, and resize direction. This API is applicable to windows that support resizing.

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name   | Type                                            | Mandatory| Description                                                        |
| --------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| wide      | number                                           | Yes  | Target width.                        |
| height    | number                                           | Yes  | Target height.                        |
| direction | [ResizeDirection](#resizedirection9)| Yes  | Target direction in which the window is adjusted.|

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return the result.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.resize(100, 100, ResizeDirection.LEFT)
}
```

### split<sup>9+</sup>

split(): Promise\<bool>

Switches the window to split-screen mode. This API is applicable to windows that support split-screen mode.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return the result.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.split()
}
```

### maximize<sup>9+</sup>

maximize(): Promise\<bool>

Maximizes this window. This API is applicable to windows that can be maximized.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return the result.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.maximize()
}
```

### minimize<sup>9+</sup>

minimize(): Promise\<bool>

Minimizes this window. This API is applicable to windows that can be minimized.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return the result.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.minimize()
}
```

### resume<sup>9+</sup>

resume(): Promise\<bool>

Restores this window to the previous window mode.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return the result.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.resume()
}
```

### close<sup>9+</sup>

close(): Promise\<bool>

Closes this window.

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool> | Promise used to return the result.|

**Example**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.close()
}
```

## MatchPattern

Enumerates the match patterns supported for component attributes.

**System capability**: SystemCapability.Test.UiTest

| Name       | Value  | Description          |
| ----------- | ---- | -------------- |
| EQUALS      | 0    | Equal to the given value.  |
| CONTAINS    | 1    | Containing the given value.  |
| STARTS_WITH | 2    | Starting from the given value.|
| ENDS_WITH   | 3    | Ending with the given value.|

## ResizeDirection<sup>9+</sup>

Enumerates the directions in which a window can be resized.

**System capability**: SystemCapability.Test.UiTest

| Name      | Description    |
| ---------- | -------- |
| LEFT       | Left.  |
| RIGHT      | Right.  |
| UP         | Up.  |
| DOWN       | Down.  |
| LEFT_UP    | Upper left.|
| LEFT_DOWN  | Lower left.|
| RIGHT_UP   | Upper right.|
| RIGHT_DOWN | Lower right.|

## WindowMode<sup>9+</sup>

Enumerates the window modes.

**System capability**: SystemCapability.Test.UiTest

| Name      | Description      |
| ---------- | ---------- |
| FULLSCREEN | Full-screen mode.|
| PRIMARY    | Primary window mode.  |
| SECONDARY  | Secondary window mode.|
| FLOATING   | Floating window mode.|
