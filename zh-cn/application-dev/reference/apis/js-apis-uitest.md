# UiTest

UiTest提供模拟UI操作的能力，供开发者在测试场景使用，主要支持如点击、双击、长按、滑动等UI操作能力。

该模块提供以下功能：

- [By](#by)：提供控件特征描述能力，用于控件筛选匹配查找。
- [UiComponent](#uicomponent)：代表UI界面上的指定控件，提供控件属性获取，控件点击，滑动查找，文本注入等能力。
- [UiDriver](#uidriver)：入口类，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等能能力。
- [UiWINDOW<sup>9+</sup>](#uiwindow9)：入口类，提供窗口属性获取，窗口拖动、调整窗口大小等能能力。

>**说明：**
>
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块 

```
import {UiDriver, BY, MatchPattern, ResizeDirection, WindowMode} from '@ohos.uitest'
```

## By

UiTest框架通过By类提供了丰富的控件特征描述API，用于进行控件筛选来匹配/查找出目标控件。<br>
By提供的API能力具有以下几个特点:<br>1、支持单属性匹配和多属性组合匹配，例如同时指定目标控件text和id。<br>2、控件属性支持多种匹配模式。<br>3、支持控件绝对定位，相对定位，可通过[By.isBefore](#byisbefore)和[By.isAfter](#byisafter)等API限定邻近控件特征进行辅助定位。<br>By类提供的所有API均为同步接口，建议使用者通过静态构造器BY来链式创建By对象。

```js
BY.text('123').type('button')
```

### text

text(txt: string, pattern?: MatchPattern): By

指定目标控件文本属性，支持多种匹配模式，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型         | 必填 | 说明                                              |
| ------- | ------------ | ---- | ------------------------------------------------- |
| txt     | string       | 是   | 指定控件文本，用于匹配目标控件文本。              |
| pattern | MatchPattern | 否   | 指定的文本匹配模式，默认为[EQUALS](#matchpattern) |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```js
let by = BY.text('123') //使用静态构造器BY创建by对象，指定目标控件的text属性。
```


### key

key(key: string): By

指定目标控件key值属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明              |
| ------ | ------ | ---- | ----------------- |
| key    | string | 是   | 指定控件的Key值。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.key('123') //使用静态构造器BY创建by对象，指定目标控件的key值属性。
```


### id

id(id: number): By

指定目标控件id属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| id     | number | 是   | 指定控件的id值。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.id(123) //使用静态构造器BY创建by对象，指定目标控件的id属性。
```


### type

type(tp: string): By

指定目标控件的控件类型属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| tp     | string | 是   | 指定控件类型。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.type('button') //使用静态构造器BY创建by对象，指定目标控件的控件类型属性。
```


### clickable

clickable(b?: bool): By

指定目标控件的可点击状态属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                             |
| ------ | ---- | ---- | -------------------------------- |
| b      | bool | 否   | 指定控件可点击状态，默认为true。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.clickable(true) //使用静态构造器BY创建by对象，指定目标控件的可点击状态属性。
```

### longClickable<sup>9+</sup>

longClickable(b?: bool): By

指定目标控件的可长按点击状态属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                                 |
| ------ | ---- | ---- | ------------------------------------ |
| b      | bool | 否   | 指定控件可长按点击状态，默认为true。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.longClickable(true) //使用静态构造器BY创建by对象，指定目标控件的可长按点击状态属性。
```


### scrollable

scrollable(b?: bool): By

指定目标控件的可滑动状态属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                         |
| ------ | ---- | ---- | ---------------------------- |
| b      | bool | 否   | 控件可滑动状态，默认为true。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.scrollable(true) //使用静态构造器BY创建by对象，指定目标控件的可滑动状态属性。
```

### enabled

enabled(b?: bool): By

指定目标控件的使能状态属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                           |
| ------ | ---- | ---- | ------------------------------ |
| b      | bool | 否   | 指定控件使能状态，默认为true。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.enabled(true) //使用静态构造器BY创建by对象，指定目标控件的使能状态属性。
```

### focused

focused(b?: bool): By

指定目标控件的获焦状态属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                       |
| ------ | ---- | ---- | -------------------------- |
| b      | bool | 否   | 控件获焦状态，默认为true。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.focused(true) //使用静态构造器BY创建by对象，指定目标控件的获焦状态属性。
```

### selected

selected(b?: bool): By

指定目标控件的被选中状态属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                             |
| ------ | ---- | ---- | -------------------------------- |
| b      | bool | 否   | 指定控件被选中状态，默认为true。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.selected(true) //使用静态构造器BY创建by对象，指定目标控件的被选中状态属性。
```

### checked<sup>9+</sup>

checked(b?: bool): By

指定目标控件的被勾选状态属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                              |
| ------ | ---- | ---- | --------------------------------- |
| b      | bool | 否   | 指定控件被勾选状态，默认为false。 |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```js
let by = BY.checked(true) //使用静态构造器BY创建by对象，指定目标控件的被勾选状态属性
```

### checkable<sup>9+</sup>

checkable(b?: bool): By

指定目标控件能否被勾选状态属性，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                                  |
| ------ | ---- | ---- | ------------------------------------- |
| b      | bool | 否   | 指定控件能否被勾选状态，默认为false。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.checkable(true) //使用静态构造器BY创建by对象，指定目标控件的能否被勾选状态属性。
```

### isBefore

isBefore(by: By): By

指定目标控件位于给出的特征属性控件之前，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| ------ | ---- | ---- | ---------------- |
| by     | By   | 是   | 特征控件的属性。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.isBefore(BY.text('123')) //使用静态构造器BY创建by对象，指定目标控件位于给出的特征属性控件之前。
```

### isAfter

isAfter(by: By): By

指定目标控件位于给出的特征属性控件之后，返回By对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| ------ | ---- | ---- | ---------------- |
| by     | By   | 是   | 特征控件的属性。 |

**返回值：**

| 类型 | 说明             |
| ---- | ---------------- |
| By   | 返回By对象自身。 |

**示例：**

```js
let by = BY.isAfter(BY.text('123')) //使用静态构造器BY创建by对象，指定目标控件位于给出的特征属性控件之后。
```

## UiComponent

UiTest中，UiComponent类代表了UI界面上的一个控件，提供控件属性获取，控件点击，滑动查找，文本注入等API。
该类提供的所有方法都使用Promise方式作为异步方法，需使用await调用。

### Point<sup>9+</sup>

坐标点信息。

| 名称 | 参数类型 | 可读 | 可写 | 描述             |
| ---- | -------- | ---- | ---- | ---------------- |
| X    | number   | 是   | 否   | 坐标点的横坐标。 |
| Y    | number   | 是   | 否   | 坐标点的纵坐标。 |

### Rect<sup>9+</sup>

控件的边框信息。

| 名称    | 参数类型 | 可读 | 可写 | 描述                      |
| ------- | -------- | ---- | ---- | ------------------------- |
| leftX   | number   | 是   | 否   | 控件边框的左上角的X坐标。 |
| topY    | number   | 是   | 否   | 控件边框的左上角的Y坐标。 |
| rightX  | number   | 是   | 否   | 控件边框的右下角的X坐标。 |
| bottomY | number   | 是   | 否   | 控件边框的右下角的Y坐标。 |

### UiComponent.click

click(): Promise\<void>

控件对象进行点击操作。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.click()
}
```

### doubleClick

doubleClick(): Promise\<void>

控件对象进行双击操作。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.doubleClick()
}
```

### longClick

longClick(): Promise\<void>

控件对象进行长按操作。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.longClick()
}
```

### getId

getId(): Promise\<number>

获取控件对象的id值。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                            |
| ---------------- | ------------------------------- |
| Promise\<number> | 以Promise形式返回的控件的id值。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let num = await button.getId()
}
```

### getKey

getKey(): Promise\<string>

获取控件对象的key值。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                           |
| ---------------- | ------------------------------ |
| Promise\<string> | 以Promise形式返回控件的key值。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let str_key = await button.getKey()
}
```

### getText

getText(): Promise\<string>

获取控件对象的文本信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                              |
| ---------------- | --------------------------------- |
| Promise\<string> | 以Promise形式返回控件的文本信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let text = await button.getText()
}
```

### getType

getType(): Promise\<string>

获取控件对象的控件类型。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                          |
| ---------------- | ----------------------------- |
| Promise\<string> | 以Promise形式返回控件的类型。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let type = await button.getType()
}
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

获取控件对象的边框信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<Rect> | 以Promise形式返回控件对象的边框信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let rect = await button.getBounds()
}
```

### getBoundsCenter<sup>9+</sup>

getBoundsCenter(): Promise\<Point>

获取控件对象的中心点信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型            | 说明                                    |
| --------------- | --------------------------------------- |
| Promise\<Point> | 以Promise形式返回控件对象的中心点信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let point = await button.getBoundsCenter()
}
```

### isClickable

isClickable(): Promise\<bool>

获取控件对象可点击状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<bool> | 以Promise形式返回控件对象可点击状态。 |

**示例：**

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

获取控件对象可长按点击状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                        |
| -------------- | ------------------------------------------- |
| Promise\<bool> | 以Promise形式返回控件对象能否长按点击状态。 |

**示例：**

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

获取控件对象被勾选状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<bool> | 以Promise形式返回控件对象被勾选状态。 |

**示例：**

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

获取控件对象能否被勾选的属性。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                        |
| -------------- | ------------------------------------------- |
| Promise\<bool> | 以Promise形式返回控件对象能否被勾选的属性。 |

**示例：**

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

获取控件对象可滑动状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<bool> | 以Promise形式返回控件对象可滑动状态。 |

**示例：**

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

获取控件使能状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<bool> | 以Promise形式返回控件使能状态。 |

**示例：**

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

判断控件对象是否获焦。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回控件对象是否获焦。 |

**示例：**

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

获取控件对象被选中状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                 |
| -------------- | -------------------- |
| Promise\<bool> | 控件对象被选中的状态 |

**示例：**

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

向控件中输入文本(适用于文本框控件)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| text   | string | 是   | 输入的文本信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let text = await driver.findComponent(BY.text('hello world'))
    await text.inputText('123')
}
```

### clearText<sup>9+</sup>

clearText(): Promise\<void>

清除控件的文本信息(适用于文本框控件)。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let text = await driver.findComponent(BY.text('hello world'))
    await text.clearText()
}
```

### scrollSearch

scrollSearch(by: By): Promise\<UiComponent>

在控件上滑动查找目标控件(适用于List等支持滑动的控件)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | ---- | ---- | -------------------- |
| by     | By   | 是   | 目标控件的属性要求。 |

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise\<UiComponent> | 以Promise形式返回找到的目标控件对象。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.type('Scroll'))
    let button = await scrollBar.scrollSearch(BY.text('next page'))
}
```

### scrollToTop<sup>9+</sup>

scrollToTop(speed?: number): Promise\<void>

在控件上滑动到顶部(适用于List等支持滑动的控件)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| speed  | number | 否   | 滑动速率，默认值为600，单位：像素点/秒。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.type('Scroll'))
    await scrollBar.scrollToTop()
}
```

### scrollToBottom<sup>9+</sup>

scrollToBottom(speed?: number): Promise\<void>

在控件上滑动到底部(适用于List等支持滑动的控件)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| speed  | number | 否   | 滑动速率，默认值为600，单位：像素点/秒。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.type('Scroll'))
    await scrollBar.scrollToBottom()
}
```

### dragTo<sup>9+</sup>

dragTo(target: UiComponent): Promise\<void>

将控件拖拽至目标控件处。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型        | 必填 | 说明       |
| ------ | ----------- | ---- | ---------- |
| target | UiComponent | 是   | 目标控件。 |

**示例：**

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

将控件按指定的比例进行捏合放大。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型        | 必填 | 说明       |
| ------ | ----------- | ---- | ---------- |
| scale  | number      | 是   | 指定比例   |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let image = await driver.findComponent(BY.type('image'))
    await image.pinchOut(1.5)
    }
```

### pinchIn<sup>9+</sup>

pinchIn(scale: number): Promise\<void>

将控件按指定的比例进行捏合缩小。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型        | 必填 | 说明       |
| ------ | ----------- | ---- | ---------- |
| scale  | number      | 是   | 指定比例   |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let image = await driver.findComponent(BY.type('image'))
    await image.pinchIn(0.5)
    }
```

## UiDriver

UiDriver类为uitest测试框架的总入口，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等API。
该类提供的方法除UiDriver.create()以外的所有方法都使用Promise方式作为异步方法，需使用await调用。

### create

static create(): UiDriver

静态方法，构造一个UiDriver对象，并返回该对象。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型    | 说明                     |
| ------- | ------------------------ |
| UiDrive | 返回构造的UiDriver对象。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
}
```

### delayMs

delayMs(duration: number): Promise\<void>

UiDriver对象在给定的时间内延时。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型   | 必填 | 说明         |
| -------- | ------ | ---- | ------------ |
| duration | number | 是   | 给定的时间。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.delayMs(1000)
}
```

### findComponent

findComponent(by: By): Promise\<UiComponent>

在UiDriver对象中，根据给出的目标控件属性要求查找目标控件。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | ---- | ---- | -------------------- |
| by     | By   | 是   | 目标控件的属性要求。 |

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise\<UiComponent> | 以Promise形式返回找到的控件对象。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.text('next page'))
}
```

### findComponents

findComponents(by: By): Promise\<Array\<UiComponent>>

在UiDriver对象中，根据给出的目标控件属性要求查找出所有匹配控件，以列表保存。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | ---- | ---- | -------------------- |
| by     | By   | 是   | 目标控件的属性要求。 |

**返回值：**

| 类型                          | 说明                                    |
| ----------------------------- | --------------------------------------- |
| Promise\<Array\<UiComponent>> | 以Promise形式返回找到的控件对象的列表。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let buttonList = await driver.findComponents(BY.text('next page'))
}
```

### findWindow<sup>9+</sup>

findWindow(filter: WindowFilter): Promise\<UiWindow>

通过指定窗口的属性来查找目标窗口。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型                           | 必填 | 说明             |
| ------ | ------------------------------ | ---- | ---------------- |
| filter | [WindowFilter](#windowfilter9) | 是   | 目标窗口的属性。 |

**返回值：**

| 类型                             | 说明                                  |
| -------------------------------- | ------------------------------------- |
| Promise\<[UiWindow](#uiwindow9)> | 以Promise形式返回找到的目标窗口对象。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
}
```

### waitForComponent<sup>9+</sup>

waitForComponent(by: By, time: number): Promise\<UiComponent>

在UiDriver对象中，在用户给定的时间内，持续查找满足控件属性要求的目标控件。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                             |
| ------ | ------ | ---- | -------------------------------- |
| by     | By     | 是   | 目标控件的属性要求。             |
| time   | number | 是   | 查找目标控件的持续时间。单位ms。 |

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise\<UiComponent> | 以Promise形式返回找到的控件对象。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.waitForComponent(BY.text('next page'),500)
}
```

### assertComponentExist   

assertComponentExist(by: By): Promise\<void>

断言API，用于断言当前界面存在满足给出的目标控件属性的控件; 如果控件不存在，该API将抛出JS异常，使当前测试用例失败。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | ---- | ---- | -------------------- |
| by     | By   | 是   | 目标控件的属性要求。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.assertComponentExist(BY.text('next page'))
}
```

### pressBack

pressBack(): Promise\<void>

UiDriver对象进行点击BACK键的操作。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.pressBack()
}
```

### triggerKey

triggerKey(keyCode: number): Promise\<void>

UiDriver对象采取如下操作：通过key值找到对应键并点击。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型   | 必填 | 说明          |
| ------- | ------ | ---- | ------------- |
| keyCode | number | 是   | 指定的key值。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.triggerKey(123)
}
```

### triggerCombineKeys<sup>9+</sup>

triggerCombineKeys(key0: number, key1: number, key2: number): Promise\<void>

UiDriver对象采取如下操作：通过给定的所有key值找到对应组合键并点击。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型   | 必填 | 说明                |
| ------- | ------ | ---- | ------------------- |
| key0    | number | 是   | 指定的第一个key值。 |
| key1    | number | 是   | 指定的第二个key值。 |
| key2    | number | 否   | 指定的第三个key值。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.triggerKey(2072, 2017)
}
```

### click

click(x: number, y: number): Promise\<void>

UiDriver对象采取如下操作：在目标坐标点单击。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.click(100,100)
}
```

### doubleClick

doubleClick(x: number, y: number): Promise\<void>

UiDriver对象采取如下操作：在目标坐标点双击。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.doubleClick(100,100)
}
```

### longClick

longClick(x: number, y: number): Promise\<void>

UiDriver对象采取如下操作：在目标坐标点长按下鼠标左键。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.longClick(100,100)
}
```

### swipe<sup>9+</sup>

swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

UiDriver对象采取如下操作：从给出的起始坐标点滑向给出的目的坐标点。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| startx | number | 是   | 以number的形式传入起始点的横坐标信息。   |
| starty | number | 是   | 以number的形式传入起始点的纵坐标信息。   |
| endx   | number | 是   | 以number的形式传入目的点的横坐标信息。   |
| endy   | number | 是   | 以number的形式传入目的点的纵坐标信息。   |
| speed  | number | 否   | 滑动速率，默认值为600，单位：像素点/秒。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.swipe(100,100,200,200,600)
}
```

### drag<sup>9+</sup>

drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

UiDriver对象采取如下操作：从给出的起始坐标点拖拽至给出的目的坐标点。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| startx | number | 是   | 以number的形式传入起始点的横坐标信息。   |
| starty | number | 是   | 以number的形式传入起始点的纵坐标信息。   |
| endx   | number | 是   | 以number的形式传入目的点的横坐标信息。   |
| endy   | number | 是   | 以number的形式传入目的点的纵坐标信息。   |
| speed  | number | 否   | 滑动速率，默认值为600，单位：像素点/秒。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.drag(100,100,200,200,600)
}
```

### screenCap

screenCap(savePath: string): Promise\<bool>

UiDriver对象采取如下操作：捕获当前屏幕，并保存为PNG格式的图片至给出的保存路径中。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型   | 必填 | 说明           |
| -------- | ------ | ---- | -------------- |
| savePath | string | 是   | 文件保存路径。 |

**返回值：**

| 类型           | 说明                                   |
| -------------- | -------------------------------------- |
| Promise\<bool> | 截图操作是否成功完成。成功完成为true。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.screenCap('/local/tmp/')
}
```

## UiWindow<sup>9+</sup>

UiTest中，UiWindow类代表了UI界面上的一个窗口，提供窗口属性获取，窗口拖动、调整窗口大小等API。
该类提供的所有方法都使用Promise方式作为异步方法，需使用await调用。

### WindowFilter<sup>9+</sup>

窗口的标志属性信息。

**系统能力**：SystemCapability.Test.UiTest 

| 名称       | 参数类型 | 必填 | 可读 | 可写 | 描述                       |
| ---------- | -------- | ---- | ---- | ---- | -------------------------- |
| bundleName | string   | 否   | 是   | 否   | 窗口对应的包名。           |
| title      | string   | 否   | 是   | 否   | 窗口的标题。               |
| focused    | bool     | 否   | 是   | 否   | 窗口是否获焦。             |
| actived    | bool     | 否   | 是   | 否   | 窗口是否正与用户进行交互。 |

### getBundleName<sup>9+</sup>

getBundleName(): Promise\<string>

获取窗口的包名信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                              |
| ---------------- | --------------------------------- |
| Promise\<string> | 以Promise形式返回窗口的包名信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let name = await window.getBundleName()
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

获取窗口的边框信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<Rect> | 以Promise形式返回窗口的边框信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let rect = await window.getBounds()
}
```

### getTitle<sup>9+</sup>

getTitle(): Promise\<string>

获取窗口的标题信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                              |
| ---------------- | --------------------------------- |
| Promise\<string> | 以Promise形式返回窗口的标题信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let rect = await window.getTitle()
}
```

### getWindowMode<sup>9+</sup>

getWindowMode(): Promise\<WindowMode>

获取窗口的窗口模式信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型                                             | 说明                                  |
| ------------------------------------------------ | ------------------------------------- |
| Promise\<[WindowMode](#WindowMode<sup>9+</sup>)> | 以Promise形式返回窗口的窗口模式信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let mode = await window.getWindowMode()
}
```

### isFocused<sup>9+</sup>

isFocused(): Promise\<bool>

判断窗口是否获焦。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回窗口对象是否获焦。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let focused = await window.isFocused()
}
```

### isActived<sup>9+</sup>

isActived(): Promise\<bool>

判断窗口是否为用户交互窗口。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                          |
| -------------- | --------------------------------------------- |
| Promise\<bool> | 以Promise形式返回窗口对象是否为用户交互窗口。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    let focused = await window.isActived()
}
```

### focus<sup>9+</sup>

focus(): Promise\<bool>

让窗口获焦。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回操作是否成功完成。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.focus()
}
```

### moveTo<sup>9+</sup>

moveTo(x: number, y: number): Promise\<bool>;

将窗口移动到目标点。适用于支持移动的窗口。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回操作是否成功完成。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.moveTo(100, 100)
}
```

### resize<sup>9+</sup>

resize(wide: number, height: number, direction: ResizeDirection): Promise\<bool>

根据传入的宽、高和调整方向来调整窗口的大小。适用于支持大小调整的窗口。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名    | 类型                                             | 必填 | 说明                                                         |
| --------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| wide      | number                                           | 是   | 以number的形式传入调整后窗口的宽度。                         |
| height    | number                                           | 是   | 以number的形式传入调整后窗口的高度。                         |
| direction | [ResizeDirection](#resizedirection<sup>9+</sup>) | 是   | 以[ResizeDirection](#ResizeDirection<sup>9+</sup>)的形式传入窗口调整的方向。 |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回操作是否成功完成。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.resize(100, 100, ResizeDirection.LEFT)
}
```

### split<sup>9+</sup>

split(): Promise\<bool>

将窗口模式切换成分屏模式。适用于支持切屏操作的窗口。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回操作是否成功完成。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.split()
}
```

### maximize<sup>9+</sup>

maximize(): Promise\<bool>

将窗口最大化。适用于支持窗口最大化操作的窗口。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回操作是否成功完成。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.maximize()
}
```

### minimize<sup>9+</sup>

minimize(): Promise\<bool>

将窗口最小化。适用于支持窗口最小化操作的窗口。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回操作是否成功完成。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.minimize()
}
```

### resume<sup>9+</sup>

resume(): Promise\<bool>

将窗口恢复到之前的窗口模式。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回操作是否成功完成。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.resume()
}
```

### close<sup>9+</sup>

close(): Promise\<bool>

将窗口关闭。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<bool> | 以Promise形式返回操作是否成功完成。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let window = await driver.findWindow({actived: true})
    await window.close()
}
```

## MatchPattern

控件属性支持的匹配模式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Test.UiTest

| 名称        | 值   | 说明           |
| ----------- | ---- | -------------- |
| EQUALS      | 0    | 等于给定值。   |
| CONTAINS    | 1    | 包含给定值。   |
| STARTS_WITH | 2    | 从给定值开始。 |
| ENDS_WITH   | 3    | 以给定值结束。 |

## ResizeDirection<sup>9+</sup>

窗口调整大小的方向。

| 名称       | 说明     |
| ---------- | -------- |
| LEFT       | 左方。   |
| RIGHT      | 右方。   |
| UP         | 上方。   |
| DOWN       | 下方。   |
| LEFT_UP    | 左上方。 |
| LEFT_DOWN  | 左下方。 |
| RIGHT_UP   | 右上方。 |
| RIGHT_DOWN | 右下方。 |

## WindowMode<sup>9+</sup>

窗口的窗口模式。

| 名称       | 说明       |
| ---------- | ---------- |
| FULLSCREEN | 全屏模式。 |
| PRIMARY    | 主窗口。   |
| SECONDARY  | 第二窗口。 |
| FLOAT      | 浮动窗口。 |
