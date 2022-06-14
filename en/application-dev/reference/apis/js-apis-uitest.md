# UiTest

>**NOTE**
>
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import {UiDriver,BY,MatchPattern} from '@ohos.uitest'
```

## By

The UiTest framework provides a wide range of UI component feature description APIs in the **By** class to filter and match components.
The API capabilities provided by the **By** class exhibit the following features:

- Allows one or more attributes as the match conditions. For example, you can specify both the **text** and **id** attributes to find the target component.

- Provides multiple match patterns for component attributes.

- Supports absolute positioning and relative positioning for components. APIs such as **isBefore** and **isAfter** can be used to specify the features of adjacent components to assist positioning.

All APIs provided in the **By** class are synchronous. You are advised to use the static constructor **BY** to create a **By** object in chain mode, for example, **BY.text('123').type('button')**.

### enum MatchPattern

Enumerates the match patterns supported for component attributes.

**System capability**: SystemCapability.Test.UiTest

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| EQUALS      | 0    | Equal to the given value.  |
| CONTAINS    | 1    | Contain the given value.  |
| STARTS_WITH | 2    | Start with the given value.|
| ENDS_WITH   | 3    | End with the given value.|

### By.text

text(txt:string,pattern?:MatchPattern):By

Specifies the text attribute of the target component. Multiple match patterns are supported.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type        | Mandatory| Description                              |
| ------- | ------------ | ---- | ---------------------------------- |
| txt     | string       | Yes  | Component text, used to match the target component.|
| pattern | MatchPattern | No  | Match pattern. The default value is **EQUALS**.  |

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.text('123') // Use the static constructor BY to create a By object and specify the text attribute 
                           of the target component.
```


### By.key

key(key:string):By;

Specifies the key attribute of the target component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| key    | string | Yes  | Component key.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.key('123') // Use the static constructor BY to create a By object and specify the key attribute
                          of the target component.
```


### By.id

id(id:number):By;

Specifies the ID property of the target component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| id     | number | Yes  | Component ID.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.id(123) // Use the static constructor BY to create a By object and specify the ID attribute
                       of the target component.
```


### By.type

type(tp:string):By;

Specifies the type property of the target component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| tp     | string | Yes  | Component type.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.type('button') // Use the static constructor BY to create a By object and specify the type attribute 
                              of the target component.
```


### By.clickable

clickable(b?:bool):By;

Specifies the clickable attribute of the target component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                          |
| ------ | ---- | ---- | ------------------------------ |
| b      | bool | No  | Clickable status of the target component. The default value is **true**.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.clickable(true) // Use the static constructor BY to create a By object and specify the clickable attribute 
                               of the target component.
```


### By.scrollable

scrollable(b?:bool):By;

Specifies the scrollable attribute of the target component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                      |
| ------ | ---- | ---- | -------------------------- |
| b      | bool | No  | Scrollable status of the target component. The default value is **true**.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.scrollable(true) // Use the static constructor BY to create a By object and specify the scrollable attribute 
                                of the target component.
```

### By.enabled

enabled(b?:bool):By;

Specifies the enable attribute of the target component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                        |
| ------ | ---- | ---- | ---------------------------- |
| b      | bool | No  | Enable status of the target component. The default value is **true**.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.enabled(true) // Use the static constructor BY to create a By object and specify the enable attribute 
                             of the target component.
```

### By.focused

focused(b?:bool):By;

Specifies the focused attribute of the target component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                    |
| ------ | ---- | ---- | ------------------------ |
| b      | bool | No  | Focused status of the target component. The default value is **true**.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.enabled(true) // Use the static constructor BY to create a By object and specify the focused attribute 
                             of the target component.
```

### By.selected

selected(b?:bool):By;

Specifies the selected attribute of the target component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                          |
| ------ | ---- | ---- | ------------------------------ |
| b      | bool | No  | Selected status of the target component. The default value is **true**.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.selected(true) // Use the static constructor BY to create a By object and specify the selected attribute 
                              of the target component.
```

### By.isBefore

isBefore(by:By):By;

Specifies the attributes of the component before which the target component is located.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description          |
| ------ | ---- | ---- | -------------- |
| by     | By   | Yes  | Attributes of the component before which the target component is located.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.isBefore(BY.text('123')) // Use the static constructor BY to create a By object and specify the attributes 
                                        of the component before which the target component is located.
```

### By.isAfter

isAfter(by:By):By;

Specifies the attributes of the component after which the target component is located.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description          |
| ------ | ---- | ---- | -------------- |
| by     | By   | Yes  | Attributes of the component before which the target component is located.|

**Return value**

| Type| Description          |
| ---- | -------------- |
| By   | Returns the **By** object itself.|

**Example**

```
let by = BY.isAfter(BY.text('123')) // Use the static constructor BY to create a By object and specify the attributes 
                                       of the component after which the target component is located.
```

## UiComponent

In **UiTest**, the **UiComponent** class represents a component on the UI and provides APIs for obtaining component attributes, clicking a component, scrolling to search for a component, and text injection.
All APIs provided by this class use a promise to return the result and must be invoked using **await**.

### UiComponent.click

click():Promise\<void>;

Clicks this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.click()
}
```

### UiComponent.doubleClick

doubleClick():Promise\<void>;

Double-clicks this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await buttont.doubleClick()
}
```

### UiComponent.longClick

longClick():Promise\<void>;

Long-clicks this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.longClick()
}
```

### UiComponent.getId

getId():Promise\<number>;

Obtains the ID of this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                     |
| ---------------- | ------------------------- |
| Promise\<number>; | Promise used to return the component ID.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let num = await button.getId()
}
```

### UiComponent.getKey

getKey():Promise\<string>;

Obtains the key of this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                      |
| ---------------- | -------------------------- |
| Promise\<string>; | Promise used to return the component key.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let str_key = await button.getKey()
}
```

### UiComponent.getText

getText():Promise\<string>;

Obtains the text information of this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                           |
| ---------------- | ------------------------------- |
| Promise\<string>; | Promise used to return the text information of the component.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let text = await button.getText()
}
```

### UiComponent.getType

getType():Promise\<string>;

Obtains the type of this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type            | Description                           |
| ---------------- | ------------------------------- |
| Promise\<string>; | Promise used to return the component type.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let type = await button.getType()
}
```

### UiComponent.isClickable

isClickable():Promise\<bool>;

Obtains the clickable status of this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool>; | Promise used to return the clickable status of the component.|

**Example**

```
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

### UiComponent.isScrollable

isScrollable():Promise\<bool>;

Obtains the scrollable status of this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool>; | Promise used to return the scrollable status of the component.|

**Example**

```
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


### UiComponent.isEnabled

isEnabled():Promise\<bool>;

Obtains the enable status of this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<bool>; | Promise used to return the enable status of the component.|

**Example**

```
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

### UiComponent.isFocused

isFocused():Promise\<bool>;

Obtains the focused status of this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<bool>; | Promise used to return the focused status of the component.|

**Example**

```
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

### UiComponent.isSelected

isSelected():Promise\<bool>;

Obtains the selected status of this component.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<bool>; | Promise used to return the selected status of the component.|

**Example**

```
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

### UiComponent.inputText

inputText(text: string):Promise\<void>;

Enters text into this component (available for text boxes).

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | ------------------------- |
| text   | string | Yes  | Text to be entered to the component.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.inputText('next page')
}
```

### UiComponent.scrollSearch

scrollSearch(by:By):Promise\<UiComponent>;

Scrolls on this component to search for the target component (available for lists).

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | ---- | ---- | -------------------- |
| by     | By   | Yes  | Attributes of the target component.|

**Return value**

| Type                 | Description                               |
| --------------------- | ----------------------------------- |
| Promise\<UiComponent>; | Promise used to return the target component.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.scrollable(true))
    let button = await scrollBar.scrollSearch(BY.text('next page'))
}
```

## UiDriver

The **UiDriver** class is the main entry to the **uitest** test framework. It provides APIs for features such as component matching/search, key injection, coordinate clicking/sliding, and screenshot.
All APIs provided by this class, except for **UiDriver.create()**, use a promise to return the result and must be invoked using **await**.

### UiDriver.create

static create():UiDriver;

Creates a **UiDriver** object and returns the object created. This API is a static API.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Return value**

| Type   | Description                  |
| ------- | ---------------------- |
| UiDrive | Returns the **UiDriver** object created.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
}
```

### UiDriver.delayMs

delayMs(duration:number):Promise\<void>;

Delays this **UiDriver** object within the specified duration.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description      |
| -------- | ------ | ---- | ---------- |
| duration | number | Yes  | Duration of time.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.delayMs(1000)
}
```

### UiDriver.findComponent

findComponent(by:By):Promise\<UiComponent>;

Searches this **UiDriver** object for the target component that has the given attributes.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | ---- | ---- | ------------------ |
| by     | By   | Yes  | Attributes of the target component.|

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise\<UiComponent>; | Promise used to return the found component.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.text('next page'))
}
```

### UiDriver.findComponents

findComponents(by:By):Promise\<Array\<UiComponent>>;

Searches this **UiDriver** object for all components that match the given attributes.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | ---- | ---- | ------------------ |
| by     | By   | Yes  | Attributes of the target component.|

**Return value**

| Type                        | Description                                 |
| ---------------------------- | ------------------------------------- |
| Promise\<Array\<UiComponent>>; | Promise used to return a list of found components.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    let buttonList = await driver.findComponents(BY.text('next page'))
}
```

### UiDriver.assertComponentExist   

assertComponentExist(by:By):Promise\<void>;

Asserts that a component that matches the given attributes exists on the current page. If the component does not exist, the API throws a JS exception, causing the current test case to fail.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | ---- | ---- | ------------------ |
| by     | By   | Yes  | Attributes of the target component.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.assertComponentExist(BY.text('next page'))
}
```

### UiDriver.pressBack

pressBack():Promise\<void>;

Presses the Back button on this **UiDriver** object.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.pressBack()
}
```

### UiDriver.triggerKey

triggerKey(keyCode:number):Promise\<void>;

Triggers the key of this **UiDriver** object that matches the given key code.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name | Type  | Mandatory| Description     |
| ------- | ------ | ---- | --------- |
| keyCode | number | Yes  | Key code.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.triggerKey(123)
}
```

### UiDriver.click

click(x:number,y:number):Promise\<void>;

Clicks a specific point of this **UiDriver** object based on the given coordinates.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type         | Mandatory| Description                                       |
| ------ | ------------- | ---- | ------------------------------------------- |
| x,y    | number,number | Yes  | Coordinate information of a specific point in the (number,number) format.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.click(100,100)
}
```

### UiDriver.doubleClick

doubleClick(x:number,y:number):Promise\<void>;

Double-clicks a specific point of this **UiDriver** object based on the given coordinates.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type         | Mandatory| Description                                       |
| ------ | ------------- | ---- | ------------------------------------------- |
| x,y    | number,number | Yes  | Coordinate information of a specific point in the (number,number) format.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.doubleClick(100,100)
}
```

### UiDriver.longClick

longClick(x:number,y:number):Promise\<void>;

Long-clicks a specific point of this **UiDriver** object based on the given coordinates.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name| Type         | Mandatory| Description                                       |
| ------ | ------------- | ---- | ------------------------------------------- |
| x,y    | number,number | Yes  | Coordinate information of a specific point in the (number,number) format.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.longClick(100,100)
}
```

### UiDriver.swipe

swipe(startx:number,starty:number,endx:number,endy:number):Promise\<void>;

Swipes from the start point to the end point of this **UiDriver** object based on the given coordinates.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name       | Type         | Mandatory| Description                                       |
| ------------- | ------------- | ---- | ------------------------------------------- |
| startx,starty | number,number | Yes  | Coordinate information of the start point in the (number,number) format.|
| endx,endy     | number,number | Yes  | Coordinate information of the end point in the (number,number) format.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.swipe(100,100,200,200)
}
```

### UiDriver.screenCap

screenCap(savePath:string):Promise\<bool>;

Captures the current screen of this **UiDriver** object and saves it as a PNG image to the given save path.

**Required permissions**: none

**System capability**: SystemCapability.Test.UiTest

**Parameters**

| Name  | Type  | Mandatory| Description        |
| -------- | ------ | ---- | ------------ |
| savePath | string | Yes  | File save path.|

**Example**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.screenCap('/local/tmp/')
}
```
