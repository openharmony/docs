# UiTest

UiTest提供模拟UI操作的能力，供开发者在测试场景使用，主要支持如点击、双击、长按、滑动等UI操作能力。

该模块提供以下功能：

- [By](#by)：提供控件特征描述能力，用于控件筛选匹配查找。
- [UiComponent](##uicomponent)：代表UI界面上的指定控件，提供控件属性获取，控件点击，滑动查找，文本注入等能力。
- [UiDriver](#uidriver)：入口类，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等能能力。

>**说明：**
>
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块 

```
import {UiDriver,BY,MatchPattern} from '@ohos.uitest'
```

## By

UiTest框架通过By类提供了丰富的控件特征描述API，用于进行控件筛选来匹配/查找出目标控件。<br>
By提供的API能力具有以下几个特点:<br>1、支持单属性匹配和多属性组合匹配，例如同时指定目标控件text和id。<br>2、控件属性支持多种匹配模式。<br>3、支持控件绝对定位，相对定位，可通过[By.isBefore](#byisbefore)和[By.isAfter](#byisafter)等API限定邻近控件特征进行辅助定位。<br>By类提供的所有API均为同步接口，建议使用者通过静态构造器BY来链式创建By对象。

```js
BY.text('123').type('button')
```

### By.text

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


### By.key

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


### By.id

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


### By.type

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


### By.clickable

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

### By.longClickable<sup>9+</sup>

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


### By.scrollable

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

### By.enabled

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

### By.focused

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

### By.selected

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

### By.checked<sup>9+</sup>

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

### By.checkable<sup>9+</sup>

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

### By.isBefore

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

### By.isAfter

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

### Rect<sup>9+</sup>

控件的边框信息。

**系统能力**：SystemCapability.Test.UiTest 

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

### UiComponent.doubleClick

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

### UiComponent.longClick

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

### UiComponent.getId

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

### UiComponent.getKey

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

### UiComponent.getText

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

### UiComponent.getType

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

### UiComponent.getBounds<sup>9+</sup>

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

### UiComponent.isClickable

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

### UiComponent.isLongClickable<sup>9+</sup>

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

### UiComponent.isChecked<sup>9+</sup>

isLongClickable(): Promise\<bool>

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

### UiComponent.isCheckable<sup>9+</sup>

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

### UiComponent.isScrollable

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


### UiComponent.isEnabled

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

### UiComponent.isFocused

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

### UiComponent.isSelected

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

### UiComponent.inputText

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

### UiComponent.clearText<sup>9+</sup>

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

### UiComponent.scrollSearch

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

### UiComponent.scrollToTop<sup>9+</sup>

scrollToTop(): Promise\<void>

在控件上滑动到顶部(适用于List等支持滑动的控件)。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.type('Scroll'))
    await scrollBar.scrollToTop()
}
```

### UiComponent.scrollToBottom<sup>9+</sup>

scrollToBottom(): Promise\<void>

在控件上滑动到底部(适用于List等支持滑动的控件)。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.type('Scroll'))
    await scrollBar.scrollToBottom()
}
```

### UiComponent.dragTo<sup>9+</sup>

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

## UiDriver

UiDriver类为uitest测试框架的总入口，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等API。
该类提供的方法除UiDriver.create()以外的所有方法都使用Promise方式作为异步方法，需使用await调用。

### UiDriver.create

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

### UiDriver.delayMs

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

### UiDriver.findComponent

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

### UiDriver.findComponents

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

### UiDriver.waitForComponent<sup>9+</sup>

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

### UiDriver.assertComponentExist   

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

### UiDriver.pressBack

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

### UiDriver.triggerKey

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

### UiDriver.click

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

### UiDriver.doubleClick

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

### UiDriver.longClick

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

### UiDriver.swipe

swipe(startx: number, starty: number, endx: number, endy: number): Promise\<void>

UiDriver对象采取如下操作：从给出的起始坐标点滑向给出的目的坐标点。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| startx | number | 是   | 以number的形式传入起始点的横坐标信息。 |
| starty | number | 是   | 以number的形式传入起始点的纵坐标信息。 |
| endx   | number | 是   | 以number的形式传入目的点的横坐标信息。 |
| endy   | number | 是   | 以number的形式传入目的点的纵坐标信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.swipe(100,100,200,200)
}
```

### UiDriver.drag<sup>9+</sup>

drag(startx: number, starty: number, endx: number, endy: number): Promise\<void>

UiDriver对象采取如下操作：从给出的起始坐标点拖拽至给出的目的坐标点。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| startx | number | 是   | 以number的形式传入起始点的横坐标信息。 |
| starty | number | 是   | 以number的形式传入起始点的纵坐标信息。 |
| endx   | number | 是   | 以number的形式传入目的点的横坐标信息。 |
| endy   | number | 是   | 以number的形式传入目的点的纵坐标信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create()
    await driver.drag(100,100,200,200)
}
```

### UiDriver.screenCap

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

## MatchPattern

控件属性支持的匹配模式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Test.UiTest

| 名称        | 值   | 说明           |
| ----------- | ---- | -------------- |
| EQUALS      | 0    | 等于给定值。   |
| CONTAINS    | 1    | 包含给定值。   |
| STARTS_WITH | 2    | 从给定值开始。 |
| ENDS_WITH   | 3    | 以给定值结束。 |

### 
