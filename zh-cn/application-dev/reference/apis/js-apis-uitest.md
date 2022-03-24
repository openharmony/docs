# UiTest

>**说明：**
>
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块 

```
import {UiDriver,BY,MatchPattern} from '@ohos.uitest'
```

## By

UiTest框架通过By类提供了丰富的控件特征描述API，用以进行控件筛选来匹配/查找出目标控件。
By提供的API能力具有以下几个特点:
	1、支持单属性匹配和多属性组合匹配，例如同时指定目标控件text和id
	2、控件属性支持多种匹配模式
	3、支持控件绝对定位，相对定位，可通过isBefore和isAfter等API限定邻近控件特征进行辅助定位
By类提供的所有API均为同步接口，建议使用者通过静态构造器BY来链式创建By对象，例如：BY.text('123').type('button')

### enum MatchPattern

控件属性支持的匹配模式

**系统能力**：以下各项对应的系统能力均为SystemCapability.Test.UiTest

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| EQUALS      | 0    | 等于给定值   |
| CONTAINS    | 1    | 包含给定值   |
| STARTS_WITH | 2    | 以给定值开始 |
| ENDS_WITH   | 3    | 以给定值结束 |

### By.text

text(txt:string,pattern?:MatchPattern):By

指定目标控件文本属性，支持多种匹配模式，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型         | 必填 | 说明                               |
| ------- | ------------ | ---- | ---------------------------------- |
| txt     | string       | 是   | 指定控件文本，用于匹配目标控件文本 |
| pattern | MatchPattern | 否   | 指定的文本匹配模式，默认为EQUALS   |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.text('123') //使用静态构造器BY创建by对象，指定目标控件的text属性
```


### By.key

key(key:string):By;

指定目标控件key值属性，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| key    | string | 是   | 指定控件的Key值 |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.key('123') //使用静态构造器BY创建by对象，指定目标控件的key值属性
```


### By.id

id(id:number):By;

指定目标控件id属性，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| id     | number | 是   | 指定控件id值 |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.id(123) //使用静态构造器BY创建by对象，指定目标控件的id属性
```


### By.type

type(tp:string):By;

指定目标控件的控件类型属性，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| tp     | string | 是   | 指定控件类型 |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.type('button') //使用静态构造器BY创建by对象，指定目标控件的控件类型属性
```


### By.clickable

clickable(b?:bool):By;

指定目标控件的可点击状态属性，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                           |
| ------ | ---- | ---- | ------------------------------ |
| b      | bool | 否   | 指定控件可点击状态，默认为true |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.clickable(true) //使用静态构造器BY创建by对象，指定目标控件的可点击状态属性
```


### By.scrollable

scrollable(b?:bool):By;

指定目标控件的可滑动状态属性，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                       |
| ------ | ---- | ---- | -------------------------- |
| b      | bool | 否   | 控件可滑动状态，默认为true |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.scrollable(true) //使用静态构造器BY创建by对象，指定目标控件的可滑动状态属性
```

### By.enabled

enabled(b?:bool):By;

指定目标控件的使能状态属性，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                         |
| ------ | ---- | ---- | ---------------------------- |
| b      | bool | 否   | 指定控件使能状态，默认为true |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.enabled(true) //使用静态构造器BY创建by对象，指定目标控件的使能状态属性
```

### By.focused

focused(b?:bool):By;

指定目标控件的获焦状态属性，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                     |
| ------ | ---- | ---- | ------------------------ |
| b      | bool | 否   | 控件获焦状态，默认为true |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.focused(true) //使用静态构造器BY创建by对象，指定目标控件的获焦状态属性
```

### By.selected

selected(b?:bool):By;

指定目标控件的被选中状态属性，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                           |
| ------ | ---- | ---- | ------------------------------ |
| b      | bool | 否   | 指定控件被选中状态，默认为true |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.selected(true) //使用静态构造器BY创建by对象，指定目标控件的被选中状态属性
```

### By.isBefore

isBefore(by:By):By;

指定目标控件位于给出的特征属性控件之前，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| ------ | ---- | ---- | -------------- |
| by     | By   | 是   | 特征控件的属性 |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.isBefore(BY.text('123')) //使用静态构造器BY创建by对象，指定目标控件位于给出的特征属性控件之前
```

### By.isAfter

isAfter(by:By):By;

指定目标控件位于给出的特征属性控件之后，返回By对象自身。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| ------ | ---- | ---- | -------------- |
| by     | By   | 是   | 特征控件的属性 |

**返回值：**

| 类型 | 说明           |
| ---- | -------------- |
| By   | 返回By对象自身 |

**示例：**

```
let by = BY.isAfter(BY.text('123')) //使用静态构造器BY创建by对象，指定目标控件位于给出的特征属性控件之后
```

## UiComponent

UiTest中，UiComponent类代表了UI界面上的一个控件，提供控件属性获取，控件点击，滑动查找，文本注入等API。
该类提供的所有方法都使用Promise方式作为异步方法，需使用await调用。

### UiComponent.click

click():Promise<void>;

控件对象进行点击操作。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.click()
}
```

### UiComponent.doubleClick

doubleClick():Promise<void>;

控件对象进行双击操作。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await buttont.doubleClick()
}
```

### UiComponent.longClick

longClick():Promise<void>;

控件对象进行长按操作。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.longClick()
}
```

### UiComponent.getId

getId():Promise<number>;

获取控件对象的id值。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                      |
| ---------------- | ------------------------- |
| Promise<number>; | 以Promise形式返回控件id值 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let num = await button.getId()
}
```

### UiComponent.getKey

getKey():Promise<string>;

获取控件对象的key值。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                       |
| ---------------- | -------------------------- |
| Promise<string>; | 以Promise形式返回控件key值 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let str_key = await button.getKey()
}
```

### UiComponent.getText

getText():Promise<string>;

获取控件对象的文本信息。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                            |
| ---------------- | ------------------------------- |
| Promise<string>; | 以Promise形式返回控件的文本信息 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let text = await button.getText()
}
```

### UiComponent.getType

getType():Promise<string>;

获取控件对象的控件类型。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                            |
| ---------------- | ------------------------------- |
| Promise<string>; | 以Promise形式返回控件对象的类型 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    let type = await button.getType()
}
```

### UiComponent.isClickable

isClickable():Promise<bool>;

获取控件对象可点击状态。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise<bool>; | 以Promise形式返回控件对象可点击状态 |

**示例：**

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

isScrollable():Promise<bool>;

获取控件对象可滑动状态。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise<bool>; | 以Promise形式返回控件对象可滑动状态 |

**示例：**

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

isEnabled():Promise<bool>;

获取控件使能状态。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<bool>; | 以Promise形式返回控件使能状态 |

**示例：**

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

isFocused():Promise<bool>;

判断控件对象是否获焦。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise<bool>; | 以Promise形式返回控件对象是否获焦 |

**示例：**

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

isSelected():Promise<bool>;

获取控件对象被选中状态。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise<bool>; | 以Promise形式返回控件对象被选中状态 |

**示例：**

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

inputText(text: string):Promise<void>;

向控件中输入文本(适用于文本框控件)。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | ------------------------- |
| text   | string | 是   | 用于向控件输入的文本信息, |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.type('button'))
    await button.inputText('next page')
}
```

### UiComponent.scrollSearch

scrollSearch(by:By):Promise<UiComponent>;

在控件上滑动查找目标控件(适用于List等控件)。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | ---- | ---- | -------------------- |
| by     | By   | 是   | 目标控件的体属性要求 |

**返回值：**

| 类型                  | 说明                                |
| --------------------- | ----------------------------------- |
| Promise<UiComponent>; | 以Promise形式返回找到的目标控件对象 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let scrollBar = await driver.findComponent(BY.scrollable(true))
    let button = await scrollBar.scrollSearch(BY.text('next page'))
}
```

## UiDriver

UiDriver类为uitest测试框架的总入口，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等API。
该类提供的方法除UiDriver.create()以外的所有方法都使用Promise方式作为异步方法，需使用await调用。

### UiDriver.create

static create():UiDriver;

静态方法，构造一个UiDriver对象，并返回该对象。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型    | 说明                   |
| ------- | ---------------------- |
| UiDrive | 返回构造的UiDriver对象 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
}
```

### UiDriver.delayMs

delayMs(duration:number):Promise<void>;

UiDriver对象在给定的时间内延时。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| duration | number | 是   | 给定的时间 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.delayMs(1000)
}
```

### UiDriver.findComponent

findComponent(by:By):Promise<UiComponent>;

在UiDriver对象中，根据给出的目标控件属性要求查找目标控件。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | ---- | ---- | ------------------ |
| by     | By   | 是   | 目标控件的属性要求 |

**返回值：**

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise<UiComponent>; | 以Promise形式返回找到的控件对象 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let button = await driver.findComponent(BY.text('next page'))
}
```

### UiDriver.findComponents

findComponents(by:By):Promise<Array<UiComponent>>;

在UiDriver对象中，根据给出的目标控件属性要求查找出所有匹配控件，以列表保存。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | ---- | ---- | ------------------ |
| by     | By   | 是   | 目标控件的属性要求 |

**返回值：**

| 类型                         | 说明                                  |
| ---------------------------- | ------------------------------------- |
| Promise<Array<UiComponent>>; | 以Promise形式返回找到的控件对象的列表 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    let buttonList = await driver.findComponents(BY.text('next page'))
}
```

### UiDriver.assertComponentExist   

assertComponentExist(by:By):Promise<void>;

断言API，用于断言当前界面存在满足给出的目标控件属性的控件; 如果控件不存在，该API将抛出JS异常，使当前测试用例失败。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | ---- | ---- | ------------------ |
| by     | By   | 是   | 目标控件的属性要求 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.assertComponentExist(BY.text('next page'))
}
```

### UiDriver.pressBack

pressBack():Promise<void>;

UiDriver对象进行点击BACK键的操作。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.pressBack()
}
```

### UiDriver.triggerKey

triggerKey(keyCode:number):Promise<void>;

UiDriver对象采取如下操作：通过key值找到对应键并点击。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型   | 必填 | 说明      |
| ------- | ------ | ---- | --------- |
| keyCode | number | 是   | 指定key值 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.triggerKey(123)
}
```

### UiDriver.click

click(x:number,y:number):Promise<void>;

UiDriver对象采取如下操作：在目标坐标点单击。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型          | 必填 | 说明                                        |
| ------ | ------------- | ---- | ------------------------------------------- |
| x,y    | number,number | 是   | 以(number,number)的形式传入特定点的坐标信息 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.click(100,100)
}
```

### UiDriver.doubleClick

doubleClick(x:number,y:number):Promise<void>;

UiDriver对象采取如下操作：在目标坐标点双击。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型          | 必填 | 说明                                        |
| ------ | ------------- | ---- | ------------------------------------------- |
| x,y    | number,number | 是   | 以(number,number)的形式传入特定点的坐标信息 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.doubleClick(100,100)
}
```

### UiDriver.longClick

longClick(x:number,y:number):Promise<void>;

UiDriver对象采取如下操作：在目标坐标点长按下鼠标左键。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型          | 必填 | 说明                                        |
| ------ | ------------- | ---- | ------------------------------------------- |
| x,y    | number,number | 是   | 以(number,number)的形式传入特定点的坐标信息 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.longClick(100,100)
}
```

### UiDriver.swipe

swipe(startx:number,starty:number,endx:number,endy:number):Promise<void>;

UiDriver对象采取如下操作：从给出的起始坐标点滑向给出的目的坐标点。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名        | 类型          | 必填 | 说明                                        |
| ------------- | ------------- | ---- | ------------------------------------------- |
| startx,starty | number,number | 是   | 以(number,number)的形式传入起始点的坐标信息 |
| endx,endy     | number,number | 是   | 以(number,number)的形式传入目的点的坐标信息 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.swipe(100,100,200,200)
}
```

### UiDriver.screenCap

screenCap(savePath:string):Promise<bool>;

UiDriver对象采取如下操作：捕获当前屏幕，并保存为PNG格式的图片至给出的保存路径中。

**需要权限**：NA

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型   | 必填 | 说明         |
| -------- | ------ | ---- | ------------ |
| savePath | string | 是   | 文件保存路径 |

**示例：**

```
async function demo() {
    let driver = UiDriver.create()
    await driver.screenCap('/local/tmp/')
}
```

