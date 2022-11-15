# UiTest

UiTest提供模拟UI操作的能力，供开发者在测试场景使用，主要支持如点击、双击、长按、滑动等UI操作能力。

该模块提供以下功能：

- [On<sup>9+</sup>](#on9)：提供控件特征描述能力，用于控件筛选匹配查找。
- [Component<sup>9+</sup>](#component9)：代表UI界面上的指定控件，提供控件属性获取，控件点击，滑动查找，文本注入等能力。
- [Driver<sup>9+</sup>](#driver9)：入口类，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等能力。
- [UiWindow<sup>9+</sup>](#uiwindow9)：入口类，提供窗口属性获取，窗口拖动、调整窗口大小等能力。
- [By<sup>(deprecated)</sup>](#bydeprecated)：提供控件特征描述能力，用于控件筛选匹配查找。从API version 9开始不再维护，建议使用[On<sup>9+</sup>](#on9)。
- [UiComponent<sup>(deprecated)</sup>](#uicomponentdeprecated)：代表UI界面上的指定控件，提供控件属性获取，控件点击，滑动查找，文本注入等能力。从API version 9开始不再维护，建议使用[Component<sup>9+</sup>](#component9)。
- [UiDriver<sup>(deprecated)</sup>](#uidriverdeprecated)：入口类，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等能力。从API version 9开始不再维护，建议使用[Driver<sup>9+</sup>](#driver9)。

>**说明：**
>
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块 

```js
import {UiComponent, UiDriver, Component, Driver, UiWindow, ON, BY, MatchPattern, DisplayRotation, ResizeDirection, WindowMode, PointerMatrix} from '@ohos.uitest';
```

## MatchPattern

控件属性支持的匹配模式。

**系统能力**：SystemCapability.Test.UiTest

| 名称        | 值   | 说明           |
| ----------- | ---- | -------------- |
| EQUALS      | 0    | 等于给定值。   |
| CONTAINS    | 1    | 包含给定值。   |
| STARTS_WITH | 2    | 以给定值开始。 |
| ENDS_WITH   | 3    | 以给定值结束。 |

## ResizeDirection<sup>9+</sup>

窗口调整大小的方向。

**系统能力**：SystemCapability.Test.UiTest

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

## Point<sup>9+</sup>

坐标点信息。

**系统能力**：SystemCapability.Test.UiTest

| 名称 | 参数类型 | 可读 | 可写 | 描述             |
| ---- | -------- | ---- | ---- | ---------------- |
| X    | number   | 是   | 否   | 坐标点的横坐标。 |
| Y    | number   | 是   | 否   | 坐标点的纵坐标。 |

## Rect<sup>9+</sup>

控件的边框信息。

**系统能力**：SystemCapability.Test.UiTest

| 名称    | 参数类型 | 可读 | 可写 | 描述                      |
| ------- | -------- | ---- | ---- | ------------------------- |
| leftX   | number   | 是   | 否   | 控件边框的左上角的X坐标。 |
| topY    | number   | 是   | 否   | 控件边框的左上角的Y坐标。 |
| rightX  | number   | 是   | 否   | 控件边框的右下角的X坐标。 |
| bottomY | number   | 是   | 否   | 控件边框的右下角的Y坐标。 |

## WindowMode<sup>9+</sup>

**系统能力**：SystemCapability.Test.UiTest

窗口的窗口模式。

| 名称       | 说明       |
| ---------- | ---------- |
| FULLSCREEN | 全屏模式。 |
| PRIMARY    | 主窗口。   |
| SECONDARY  | 第二窗口。 |
| FLOATING   | 浮动窗口。 |

## DisplayRotation<sup>9+</sup>

**系统能力**：SystemCapability.Test.UiTest

设备显示器的显示方向。

| 名称         | 说明                                     |
| ------------ | ---------------------------------------- |
| ROTATION_0   | 设备显示器不旋转，初始形态垂直显示。     |
| ROTATION_90  | 设备显示器顺时针旋转90°，水平显示。      |
| ROTATION_180 | 设备显示器顺时针旋转180°，逆向垂直显示。 |
| ROTATION_270 | 设备显示器顺时针旋转270°，逆向水平显示。 |

## WindowFilter<sup>9+</sup>

窗口的标志属性信息。

**系统能力**：SystemCapability.Test.UiTest

| 名称       | 参数类型 | 必填 | 可读 | 可写 | 描述                       |
| ---------- | -------- | ---- | ---- | ---- | -------------------------- |
| bundleName | string   | 否   | 是   | 否   | 窗口归属应用的包名。       |
| title      | string   | 否   | 是   | 否   | 窗口的标题信息。           |
| focused    | boolean  | 否   | 是   | 否   | 窗口是否处于获焦状态。     |
| actived    | boolean  | 否   | 是   | 否   | 窗口是否正与用户进行交互。 |

## On<sup>9+</sup>

UiTest框架在API 9中，通过On类提供了丰富的控件特征描述API，用于进行控件筛选来匹配/查找出目标控件。<br>
On提供的API能力具有以下几个特点:<br>1、支持单属性匹配和多属性组合匹配，例如同时指定目标控件text和id。<br>2、控件属性支持多种匹配模式。<br>3、支持控件绝对定位，相对定位，可通过[ON.isBefore](#isbefore)和[ON.isAfter](#isafter)等API限定邻近控件特征进行辅助定位。<br>On类提供的所有API均为同步接口，建议使用者通过静态构造器ON来链式创建On对象。

```js
ON.text('123').type('button');
```

### text<sup>9+</sup>

text(txt: string, pattern?: MatchPattern): On

指定目标控件文本属性，支持多种匹配模式，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型                          | 必填 | 说明                                                |
| ------- | ----------------------------- | ---- | --------------------------------------------------- |
| txt     | string                        | 是   | 指定控件文本，用于匹配目标控件文本。                |
| pattern | [MatchPattern](#matchpattern) | 否   | 指定的文本匹配模式，默认为[EQUALS](#matchpattern)。 |

**返回值：**

| 类型       | 说明                               |
| ---------- | ---------------------------------- |
| [On](#on9) | 返回指定目标控件文本属性的On对象。 |

**示例：**

```js
let on = ON.text('123'); // 使用静态构造器ON创建On对象，指定目标控件的text属性。
```


### id<sup>9+</sup>

id(id: string): On

指定目标控件id属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| id     | string | 是   | 指定控件的id值。 |

**返回值：**

| 类型       | 说明                             |
| ---------- | -------------------------------- |
| [On](#on9) | 返回指定目标控件id属性的On对象。 |

**示例：**

```js
let on = ON.id('123'); // 使用静态构造器ON创建On对象，指定目标控件的id属性。
```


### type<sup>9+</sup>

type(tp: string): On

指定目标控件的控件类型属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| tp     | string | 是   | 指定控件类型。 |

**返回值：**

| 类型       | 说明                                     |
| ---------- | ---------------------------------------- |
| [On](#on9) | 返回指定目标控件的控件类型属性的On对象。 |

**示例：**

```js
let on = ON.type('button'); // 使用静态构造器ON创建On对象，指定目标控件的控件类型属性。
```


### clickable<sup>9+</sup>

clickable(b?: boolean): On

指定目标控件的可点击状态属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | 否   | 指定控件可点击状态，true：可点击，false：不可点击。默认为true。 |

**返回值：**

| 类型       | 说明                                       |
| ---------- | ------------------------------------------ |
| [On](#on9) | 返回指定目标控件的可点击状态属性的On对象。 |

**示例：**

```js
let on = ON.clickable(true); // 使用静态构造器ON创建On对象，指定目标控件的可点击状态属性。
```

### longClickable<sup>9+</sup>

longClickable(b?: boolean): On

指定目标控件的可长按点击状态属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | 否   | 指定控件可长按点击状态，true：可长按点击，false：不可长按点击。默认为true。 |

**返回值：**

| 类型       | 说明                                           |
| ---------- | ---------------------------------------------- |
| [On](#on9) | 返回指定目标控件的可长按点击状态属性的On对象。 |

**示例：**

```js
let on = ON.longClickable(true); // 使用静态构造器ON创建On对象，指定目标控件的可长按点击状态属性。
```


### scrollable<sup>9+</sup>

scrollable(b?: boolean): On

指定目标控件的可滑动状态属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                        |
| ------ | ------- | ---- | ----------------------------------------------------------- |
| b      | boolean | 否   | 控件可滑动状态，true：可滑动，false：不可滑动。默认为true。 |

**返回值：**

| 类型       | 说明                                       |
| ---------- | ------------------------------------------ |
| [On](#on9) | 返回指定目标控件的可滑动状态属性的On对象。 |

**示例：**

```js
let on = ON.scrollable(true); // 使用静态构造器ON创建On对象，指定目标控件的可滑动状态属性。
```

### enabled<sup>9+</sup>

enabled(b?: boolean): On

指定目标控件的使能状态属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| b      | boolean | 否   | 指定控件使能状态，true：使能，false：未使能。默认为true。 |

**返回值：**

| 类型       | 说明                                     |
| ---------- | ---------------------------------------- |
| [On](#on9) | 返回指定目标控件的使能状态属性的On对象。 |

**示例：**

```js
let on = ON.enabled(true); // 使用静态构造器ON创建On对象，指定目标控件的使能状态属性。
```

### focused<sup>9+</sup>

focused(b?: boolean): On

指定目标控件的获焦状态属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                  |
| ------ | ------- | ---- | ----------------------------------------------------- |
| b      | boolean | 否   | 控件获焦状态，true：获焦，false：未获焦。默认为true。 |

**返回值：**

| 类型       | 说明                                     |
| ---------- | ---------------------------------------- |
| [On](#on9) | 返回指定目标控件的获焦状态属性的On对象。 |

**示例：**

```js
let on = ON.focused(true); // 使用静态构造器ON创建On对象，指定目标控件的获焦状态属性。
```

### selected<sup>9+</sup>

selected(b?: boolean): On

指定目标控件的被选中状态属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | 否   | 指定控件被选中状态，true：被选中，false：未被选中。默认为true。 |

**返回值：**

| 类型       | 说明                                       |
| ---------- | ------------------------------------------ |
| [On](#on9) | 返回指定目标控件的被选中状态属性的On对象。 |

**示例：**

```js
let on = ON.selected(true); // 使用静态构造器ON创建On对象，指定目标控件的被选中状态属性。
```

### checked<sup>9+</sup>

checked(b?: boolean): On

指定目标控件的被勾选状态属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | 否   | 指定控件被勾选状态，true：被勾选，false：未被勾选。默认为false。 |

**返回值：**

| 类型       | 说明                                       |
| ---------- | ------------------------------------------ |
| [On](#on9) | 返回指定目标控件的被勾选状态属性的On对象。 |

**示例：**

```js
let on = ON.checked(true); // 使用静态构造器ON创建On对象，指定目标控件的被勾选状态属性
```

### checkable<sup>9+</sup>

checkable(b?: boolean): On

指定目标控件能否被勾选状态属性，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | 否   | 指定控件能否被勾选状态，true：能被勾选，false：不能被勾选。默认为false。 |

**返回值：**

| 类型       | 说明                                         |
| ---------- | -------------------------------------------- |
| [On](#on9) | 返回指定目标控件能否被勾选状态属性的On对象。 |

**示例：**

```js
let on = ON.checkable(true); // 使用静态构造器ON创建On对象，指定目标控件的能否被勾选状态属性。
```

### isBefore<sup>9+</sup>

isBefore(on: On): On

指定目标控件位于给出的特征属性控件之前，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型       | 必填 | 说明                 |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | 是   | 特征控件的属性要求。 |

**返回值：**

| 类型       | 说明                                                 |
| ---------- | ---------------------------------------------------- |
| [On](#on9) | 返回指定目标控件位于给出的特征属性控件之前的On对象。 |

**示例：**

```js
let on = ON.isBefore(ON.text('123')); // 使用静态构造器ON创建On对象，指定目标控件位于给出的特征属性控件之前。
```

### isAfter<sup>9+</sup>

isAfter(on: On): On

指定目标控件位于给出的特征属性控件之后，返回On对象自身。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型       | 必填 | 说明                 |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | 是   | 特征控件的属性要求。 |

**返回值：**

| 类型       | 说明                                                 |
| ---------- | ---------------------------------------------------- |
| [On](#on9) | 返回指定目标控件位于给出的特征属性控件之后的On对象。 |

**示例：**

```js
let on = ON.isAfter(ON.text('123')); // 使用静态构造器ON创建On对象，指定目标控件位于给出的特征属性控件之后。
```

## Component<sup>9+</sup>

UiTest框架在API9中，Component类代表了UI界面上的一个控件，提供控件属性获取，控件点击，滑动查找，文本注入等API。
该类提供的所有方法都使用Promise方式作为异步方法，需使用await调用。

### click<sup>9+</sup>

click(): Promise\<void>

控件对象进行点击操作。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    await button.click();
}
```

### doubleClick<sup>9+</sup>

doubleClick(): Promise\<void>

控件对象进行双击操作。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    await button.doubleClick();
}
```

### longClick<sup>9+</sup>

longClick(): Promise\<void>

控件对象进行长按操作。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    await button.longClick();
}
```

### getId<sup>9+</sup>

getId(): Promise\<string>

获取控件对象的id值。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                            |
| ---------------- | ------------------------------- |
| Promise\<string> | 以Promise形式返回的控件的id值。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let num = await button.getId();
}
```

### getText<sup>9+</sup>

getText(): Promise\<string>

获取控件对象的文本信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                              |
| ---------------- | --------------------------------- |
| Promise\<string> | 以Promise形式返回控件的文本信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let text = await button.getText();
}
```

### getType<sup>9+</sup>

getType(): Promise\<string>

获取控件对象的控件类型。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                          |
| ---------------- | ----------------------------- |
| Promise\<string> | 以Promise形式返回控件的类型。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let type = await button.getType();
}
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

获取控件对象的边框信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型                     | 说明                                  |
| ------------------------ | ------------------------------------- |
| Promise\<[Rect](#rect9)> | 以Promise形式返回控件对象的边框信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let rect = await button.getBounds();
}
```

### getBoundsCenter<sup>9+</sup>

getBoundsCenter(): Promise\<Point>

获取控件对象所占区域的中心点信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型                       | 说明                                            |
| -------------------------- | ----------------------------------------------- |
| Promise\<[Point](#point9)> | 以Promise形式返回控件对象所占区域的中心点信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('button'));
    let point = await button.getBoundsCenter();
}
```

### isClickable<sup>9+</sup>

isClickable(): Promise\<boolean>

获取控件对象可点击属性。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回控件对象是否可点击，true：可点击，false：不可点击。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

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

获取控件对象可长按点击属性。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回控件对象是否可安装点击，true：可长按点击，false：不可长按点击。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

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

获取控件对象被勾选状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回控件对象被勾选状态，true：被勾选，false：未被勾选。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('Checkbox'));
    if(await checkBox.isChecked) {
        console.info('This checkBox is checked');
    } else {
        console.info('This checkBox is not checked');
    }
}
```

### isCheckable<sup>9+</sup>

isCheckable(): Promise\<boolean>

获取控件对象能否被勾选属性。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 错误码ID          | 错误码信息                                                   |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回控件对象能否可被勾选属性，true：可被勾选，false：不可被勾选。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 类型     | 说明                                     |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('Checkbox'));
    if(await checkBox.isCheckable) {
        console.info('This checkBox is checkable');
    } else {
        console.info('This checkBox is not checkable');
    }
}
```

### isScrollable<sup>9+</sup>

isScrollable(): Promise\<boolean>

获取控件对象可滑动属性。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回控件对象是否可滑动，true：可滑动，false：不可滑动。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.scrollable(true));
    if(await scrollBar.isScrollable()) {
        console.info('This scrollBar can be operated');
    } else {
        console.info('This scrollBar can not be operated');
    }
}
```


### isEnabled<sup>9+</sup>

isEnabled(): Promise\<boolean>

获取控件使能状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                       |
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | 以Promise形式返回控件使能状态，true：使能，false：未使能。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

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

判断控件对象获焦状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回控件对象获焦状态，true：获焦，false：未获焦。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

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

获取控件对象被选中状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                |
| ----------------- | --------------------------------------------------- |
| Promise\<boolean> | 控件对象被选中状态，true：被选中，false：未被选中。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

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

向控件中输入文本(适用于文本框控件)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| text   | string | 是   | 输入的文本信息，当前支持英文和特殊字符。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.text('hello world'));
    await text.inputText('123');
}
```

### clearText<sup>9+</sup>

clearText(): Promise\<void>

清除控件的文本信息(适用于文本框控件)。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.text('hello world'));
    await text.clearText();
}
```

### scrollSearch<sup>9+</sup>

scrollSearch(on: ON): Promise\<Component>

在控件上滑动查找目标控件(适用支持滑动的控件)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型       | 必填 | 说明                 |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | 是   | 目标控件的属性要求。 |

**返回值：**

| 类型                               | 说明                                  |
| ---------------------------------- | ------------------------------------- |
| Promise\<[Component](#component9)> | 以Promise形式返回找到的目标控件对象。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('Scroll'));
    let button = await scrollBar.scrollSearch(ON.text('next page'));
}
```

### scrollToTop<sup>9+</sup>

scrollToTop(speed?: number): Promise\<void>

在控件上滑动到顶部(适用支持滑动的控件)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| speed  | number | 否   | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('Scroll'));
    await scrollBar.scrollToTop();
}
```

### scrollToBottom<sup>9+</sup>

scrollToBottom(speed?: number): Promise\<void>

在控件上滑动到底部(适用支持滑动的控件)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| speed  | number | 否   | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('Scroll'));
    await scrollBar.scrollToBottom();
}
```

### dragTo<sup>9+</sup>

dragTo(target: Component): Promise\<void>

将控件拖拽至目标控件处。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型                     | 必填 | 说明       |
| ------ | ------------------------ | ---- | ---------- |
| target | [Component](#component9) | 是   | 目标控件。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

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

将控件按指定的比例进行捏合放大。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| scale  | number | 是   | 指定放大的比例。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('image'));
    await image.pinchOut(1.5);
    }
```

### pinchIn<sup>9+</sup>

pinchIn(scale: number): Promise\<void>

将控件按指定的比例进行捏合缩小。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| scale  | number | 是   | 指定缩小的比例。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.type('image'));
    await image.pinchIn(0.5);
    }
```

## Driver<sup>9+</sup>

Driver类为uitest测试框架的总入口，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等能力。
该类提供的方法除Driver.create()以外的所有方法都使用Promise方式作为异步方法，需使用await方式调用。

### create<sup>9+</sup>

static create(): Driver

静态方法，构造一个Driver对象，并返回该对象。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 错误码ID | 错误码信息             |
| -------- | ---------------------- |
| Driver   | 返回构造的Driver对象。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 类型     | 说明               |
| -------- | ------------------ |
| 17000001 | Initialize failed. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
}
```

### delayMs<sup>9+</sup>

delayMs(duration: number): Promise\<void>

Driver对象在给定的时间内延时。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| duration | number | 是   | 给定的时间，单位：ms。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.delayMs(1000);
}
```

### findComponent<sup>9+</sup>

findComponent(on: On): Promise\<Component>

在Driver对象中，根据给出的目标控件属性要求查找目标控件。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型       | 必填 | 说明                 |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | 是   | 目标控件的属性要求。 |

**返回值：**

| 类型                               | 说明                              |
| ---------------------------------- | --------------------------------- |
| Promise\<[Component](#component9)> | 以Promise形式返回找到的控件对象。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.findComponent(ON.text('next page'));
}
```

### findComponents<sup>9+</sup>

findComponents(on: On): Promise\<Array\<Component>>

在Driver对象中，根据给出的目标控件属性要求查找出所有匹配控件，以列表保存。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型       | 必填 | 说明                 |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | 是   | 目标控件的属性要求。 |

**返回值：**

| 类型                                       | 说明                                    |
| ------------------------------------------ | --------------------------------------- |
| Promise\<Array\<[Component](#component9)>> | 以Promise形式返回找到的控件对象的列表。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let buttonList = await driver.findComponents(ON.text('next page'));
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

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
}
```

### waitForComponent<sup>9+</sup>

waitForComponent(on: On, time: number): Promise\<Component>

在Driver对象中，在用户给定的时间内，持续查找满足控件属性要求的目标控件。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型       | 必填 | 说明                             |
| ------ | ---------- | ---- | -------------------------------- |
| On     | [On](#on9) | 是   | 目标控件的属性要求。             |
| time   | number     | 是   | 查找目标控件的持续时间。单位ms。 |

**返回值：**

| 类型                              | 说明                              |
| --------------------------------- | --------------------------------- |
| Promise\<[Component](#component)> | 以Promise形式返回找到的控件对象。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let button = await driver.waitForComponent(ON.text('next page'),500);
}
```

### assertComponentExist<sup>9+</sup>

assertComponentExist(on: On): Promise\<void>

断言API，用于断言当前界面是否存在满足给出的目标属性的控件。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型       | 必填 | 说明                 |
| ------ | ---------- | ---- | -------------------- |
| on     | [On](#on9) | 是   | 目标控件的属性要求。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000003 | Component existence assertion failed.    |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.assertComponentExist(ON.text('next page'));
}
```

### pressBack<sup>9+</sup>

pressBack(): Promise\<void>

Driver对象进行点击BACK键的操作。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.pressBack();
}
```

### triggerKey<sup>9+</sup>

triggerKey(keyCode: number): Promise\<void>

Driver对象采取如下操作：传入key值实现模拟点击对应按键的效果。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型   | 必填 | 说明          |
| ------- | ------ | ---- | ------------- |
| keyCode | number | 是   | 指定的key值。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.triggerKey(123);
}
```

### triggerCombineKeys<sup>9+</sup>

triggerCombineKeys(key0: number, key1: number, key2?: number): Promise\<void>

Driver对象通过给定的key值，找到对应组合键并点击。例如，Key值为(2072, 2019)时，Driver对象找到key值对应的组合键并点击，如ctrl+c。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ------ | ------ | ---- | ------------------- |
| key0   | number | 是   | 指定的第一个key值。 |
| key1   | number | 是   | 指定的第二个key值。 |
| key2   | number | 否   | 指定的第三个key值。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.triggerCombineKeys(2072, 2047, 2035);
}
```


### click<sup>9+</sup>

click(x: number, y: number): Promise\<void>

Driver对象采取如下操作：在目标坐标点单击。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.click(100,100);
}
```

### doubleClick<sup>9+</sup>

doubleClick(x: number, y: number): Promise\<void>

Driver对象采取如下操作：在目标坐标点双击。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.doubleClick(100,100);
}
```

### longClick<sup>9+</sup>

longClick(x: number, y: number): Promise\<void>

Driver对象采取如下操作：在目标坐标点长按。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.longClick(100,100);
}
```

### swipe<sup>9+</sup>

swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Driver对象采取如下操作：从起始坐标点滑向目的坐标点。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| startx | number | 是   | 以number的形式传入起始点的横坐标信息。                       |
| starty | number | 是   | 以number的形式传入起始点的纵坐标信息。                       |
| endx   | number | 是   | 以number的形式传入目的点的横坐标信息。                       |
| endy   | number | 是   | 以number的形式传入目的点的纵坐标信息。                       |
| speed  | number | 否   | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.swipe(100,100,200,200,600);
}
```

### drag<sup>9+</sup>

drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>

Driver对象采取如下操作：从起始坐标点拖拽至目的坐标点。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| startx | number | 是   | 以number的形式传入起始点的横坐标信息。                       |
| starty | number | 是   | 以number的形式传入起始点的纵坐标信息。                       |
| endx   | number | 是   | 以number的形式传入目的点的横坐标信息。                       |
| endy   | number | 是   | 以number的形式传入目的点的纵坐标信息。                       |
| speed  | number | 否   | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.drag(100,100,200,200,600);
}
```

### screenCap<sup>9+</sup>

screenCap(savePath: string): Promise\<boolean>

Driver对象采取如下操作：捕获当前屏幕，并保存为PNG格式的图片至给出的保存路径中。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型   | 必填 | 说明           |
| -------- | ------ | ---- | -------------- |
| savePath | string | 是   | 文件保存路径。 |

**返回值：**

| 类型              | 说明                                   |
| ----------------- | -------------------------------------- |
| Promise\<boolean> | 截图操作是否成功完成。成功完成为true。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.screenCap('/local/tmp/');
}
```

### setDisplayRotation<sup>9+</sup>

setDisplayRotation(rotation: DisplayRotation): Promise\<void>

将设备的屏幕显示方向设置为指定的显示方向。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型                                 | 必填 | 说明             |
| -------- | ------------------------------------ | ---- | ---------------- |
| rotation | [DisplayRotation](#displayrotation9) | 是   | 设备的显示方向。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.setDisplayRotation(DisplayRotation.ROTATION_180);
}
```

### getDisplayRotation<sup>9+</sup>

getDisplayRotation(): Promise\<DisplayRotation>

获取当前设备的屏幕显示方向。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型                                           | 说明                                    |
| ---------------------------------------------- | --------------------------------------- |
| Promise\<[DisplayRotation](#displayrotation9)> | 以Promise的形式返回当前设备的显示方向。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let rotation = await driver.getDisplayRotation();
}
```

### setDisplayRotationEnabled<sup>9+</sup>

setDisplayRotationEnabled(enabled: boolean): Promise\<void>

启用/禁用设备旋转屏幕的功能。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型    | 必填 | 说明                                                    |
| ------- | ------- | ---- | ------------------------------------------------------- |
| enabled | boolean | 是   | 能否旋转屏幕的标识，true：可以旋转，false：不可以旋转。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.setDisplayRotationEnabled(false);
}
```

### getDisplaySize<sup>9+</sup>

getDisplaySize(): Promise\<Point>

获取当前设备的屏幕大小。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型                       | 说明                                    |
| -------------------------- | --------------------------------------- |
| Promise\<[Point](#point9)> | 以Promise的形式返回当前设备的屏幕大小。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let size = await driver.getDisplaySize();
}
```

### getDisplayDensity<sup>9+</sup>

getDisplayDensity(): Promise\<Point>

获取当前设备屏幕的分辨率。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型                       | 说明                                      |
| -------------------------- | ----------------------------------------- |
| Promise\<[Point](#point9)> | 以Promise的形式返回当前设备屏幕的分辨率。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let density = await driver.getDisplayDensity();
}
```

### wakeUpDisplay<sup>9+</sup>

wakeUpDisplay(): Promise\<void>

唤醒当前设备即设备亮屏。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.wakeUpDisplay();
}
```

### pressHome<sup>9+</sup>

pressHome(): Promise\<void>

设备返回到桌面。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.pressHome();
}
```

### waitForIdle<sup>9+</sup>

waitForIdle(idleTime: number, timeout: number): Promise\<boolean>

判断当前界面的所有控件是否已经空闲。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| idleTime | number | 是   | 空闲时间的阈值。在这个时间段控件不发生变化，视为该控件空闲，单位：毫秒。 |
| timeout  | number | 是   | 等待空闲的最大时间，单位：毫秒。                             |

**返回值：**

| 类型              | 说明                                                |
| ----------------- | --------------------------------------------------- |
| Promise\<boolean> | 以Promise的形式返回当前界面的所有控件是否已经空闲。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let idled = await driver.waitForIdle(4000,5000);
}
```

### fling<sup>9+</sup>

fling(from: Point, to: Point, stepLen: number, speed: number): Promise\<void>

模拟手指滑动后脱离屏幕的快速滑动操作。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型             | 必填 | 说明                                                         |
| ------- | ---------------- | ---- | ------------------------------------------------------------ |
| from    | [Point](#point9) | 是   | 手指接触屏幕的起始点坐标。                                   |
| to      | [Point](#point9) | 是   | 手指离开屏幕时的坐标点。                                     |
| stepLen | number           | 是   | 间隔距离，单位：像素点。                                     |
| speed   | number           | 是   | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    await driver.fling({X: 500, Y: 480},{X: 450, Y: 480},5,600);
}
```

### injectMultiPointerAction<sup>9+</sup>

injectMultiPointerAction(pointers: PointerMatrix, speed?: number): Promise\<boolean>

向设备注入多指操作。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| pointers | [PointerMatrix](#pointermatrix9) | 是   | 滑动轨迹，包括操作手指个数和滑动坐标序列。                   |
| speed    | number                           | 否   | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |

**返回值：**

| 类型              | 说明                                  |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | 以Promise的形式返回操作是否成功完成。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |

**示例：**

```js
async function demo() {
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

存储多指操作中每根手指每一步动作的坐标点及其行为的二维数组。

### create<sup>9+</sup>

static create(fingers: number, steps: number): PointerMatrix

静态方法，构造一个PointerMatrix对象，并返回该对象。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型   | 必填 | 说明                                       |
| ------- | ------ | ---- | ------------------------------------------ |
| fingers | number | 是   | 多指操作中注入的手指数，取值范围：[1,10]。 |
| steps   | number | 是   | 每根手指操作的步骤数，取值范围：[1,1000]。 |

**返回值：**

| 类型                             | 说明                          |
| -------------------------------- | ----------------------------- |
| [PointerMatrix](#pointermatrix9) | 返回构造的PointerMatrix对象。 |

**示例：**

```js
async function demo() {
    let pointerMatrix = PointerMatrix.create(2,3);
}
```

### setPoint<sup>9+</sup>

setPoint(finger: number, step: number, point: Point): void

设置PointerMatrix对象中指定手指和步骤对应动作的坐标点。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型             | 必填 | 说明             |
| ------ | ---------------- | ---- | ---------------- |
| finger | number           | 是   | 手指的序号。     |
| step   | number           | 是   | 步骤的序号。     |
| point  | [Point](#point9) | 是   | 该行为的坐标点。 |

**示例：**

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

UiWindow代表了UI界面上的一个窗口，提供窗口属性获取，窗口拖动、调整窗口大小等能力。
该类提供的所有方法都使用Promise方式作为异步方法，需使用await方式调用。

### getBundleName<sup>9+</sup>

getBundleName(): Promise\<string>

获取窗口归属应用的包名信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<string> | 以Promise形式返回窗口归属应用的包名信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let name = await window.getBundleName();
}
```

### getBounds<sup>9+</sup>

getBounds(): Promise\<Rect>

获取窗口的边框信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型                     | 说明                              |
| ------------------------ | --------------------------------- |
| Promise\<[Rect](#rect9)> | 以Promise形式返回窗口的边框信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let rect = await window.getBounds();
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

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let rect = await window.getTitle();
}
```

### getWindowMode<sup>9+</sup>

getWindowMode(): Promise\<WindowMode>

获取窗口的窗口模式信息。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型                                 | 说明                                  |
| ------------------------------------ | ------------------------------------- |
| Promise\<[WindowMode](#windowmode9)> | 以Promise形式返回窗口的窗口模式信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let mode = await window.getWindowMode();
}
```

### isFocused<sup>9+</sup>

isFocused(): Promise\<boolean>

判断窗口是否处于获焦状态。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回窗口对象是否获取获焦状态，true：获焦，false：未获焦。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let focused = await window.isFocused();
}
```

### isActived<sup>9+</sup>

isActived(): Promise\<boolean>

判断窗口是否为用户正在交互窗口。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回窗口对象是否为用户正在交互窗口，true：交互窗口，false：非交互窗口。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    let focused = await window.isActived();
}
```

### focus<sup>9+</sup>

focus(): Promise\<void>

让窗口获焦。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.focus();
}
```

### moveTo<sup>9+</sup>

moveTo(x: number, y: number): Promise\<void>

将窗口移动到目标点。适用于支持移动的窗口。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.moveTo(100, 100);
}
```

### resize<sup>9+</sup>

resize(wide: number, height: number, direction: ResizeDirection): Promise\<void>

根据传入的宽、高和调整方向来调整窗口的大小。适用于支持调整大小的窗口。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名    | 类型                                 | 必填 | 说明                                                         |
| --------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| wide      | number                               | 是   | 以number的形式传入调整后窗口的宽度。                         |
| height    | number                               | 是   | 以number的形式传入调整后窗口的高度。                         |
| direction | [ResizeDirection](#resizedirection9) | 是   | 以[ResizeDirection](#resizedirection9)的形式传入窗口调整的方向。 |

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.resize(100, 100, ResizeDirection.LEFT);
}
```

### split<sup>9+</sup>

split(): Promise\<void>

将窗口模式切换成分屏模式。适用于支持切换分屏模式的窗口。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 类型     | 说明                                     |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.split();
}
```

### maximize<sup>9+</sup>

maximize(): Promise\<void>

将窗口最大化。适用于支持窗口最大化操作的窗口。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.maximize();
}
```

### minimize<sup>9+</sup>

minimize(): Promise\<void>

将窗口最小化。适用于支持窗口最小化操作的窗口。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.minimize();
}
```

### resume<sup>9+</sup>

resume(): Promise\<void>

将窗口恢复到之前的窗口模式。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.resume();
}
```

### close<sup>9+</sup>

close(): Promise\<void>

将窗口关闭。

**系统能力**：SystemCapability.Test.UiTest

**错误码：**

以下错误码的详细介绍请参见[uitest测试框架错误码](../errorcodes/errorcode-uitest.md)。

| 错误码ID | 错误码信息                               |
| -------- | ---------------------------------------- |
| 17000002 | API does not allow calling concurrently. |
| 17000004 | Component lost/UiWindow lost.            |
| 17000005 | This operation is not supported.         |

**示例：**

```js
async function demo() {
    let driver = Driver.create();
    let window = await driver.findWindow({actived: true});
    await window.close();
}
```

## By<sup>(deprecated)</sup>

UiTest框架通过By类提供了丰富的控件特征描述API，用于进行控件筛选来匹配/查找出目标控件。<br>
By提供的API能力具有以下几个特点:<br>1、支持单属性匹配和多属性组合匹配，例如同时指定目标控件text和id。<br>2、控件属性支持多种匹配模式。<br>3、支持控件绝对定位，相对定位，可通过[By.isBefore<sup>(deprecated)</sup>](#isbeforedeprecated)和[By.isAfter<sup>(deprecated)</sup>](#isafterdeprecated)等API限定邻近控件特征进行辅助定位。<br>By类提供的所有API均为同步接口，建议使用者通过静态构造器BY来链式创建By对象。

从API version 9开始不再维护，建议使用[On<sup>9+</sup>](#on9)。

```js
BY.text('123').type('button');
```

### text<sup>(deprecated)</sup>

text(txt: string, pattern?: MatchPattern): By

指定目标控件文本属性，支持多种匹配模式，返回By对象自身。

从API version 9开始不再维护，建议使用[text<sup>9+</sup>](#text9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型                          | 必填 | 说明                                                |
| ------- | ----------------------------- | ---- | --------------------------------------------------- |
| txt     | string                        | 是   | 指定控件文本，用于匹配目标控件文本。                |
| pattern | [MatchPattern](#matchpattern) | 否   | 指定的文本匹配模式，默认为[EQUALS](#matchpattern)。 |

**返回值：**

| 类型                | 说明                               |
| ------------------- | ---------------------------------- |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件文本属性的By对象。 |

**示例：**

```js
let by = BY.text('123'); // 使用静态构造器BY创建by对象，指定目标控件的text属性。
```


### key<sup>(deprecated)</sup>

key(key: string): By

指定目标控件key值属性，返回By对象自身。

从API version 9开始不再维护，建议使用[id<sup>9+</sup>](#id9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明              |
| ------ | ------ | ---- | ----------------- |
| key    | string | 是   | 指定控件的Key值。 |

**返回值：**

| 类型                | 说明                                |
| ------------------- | ----------------------------------- |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件key值属性的By对象。 |

**示例：**

```js
let by = BY.key('123'); // 使用静态构造器BY创建by对象，指定目标控件的key值属性。
```


### id<sup>(deprecated)</sup>

id(id: number): By

指定目标控件id属性，返回By对象自身。

从API version 9开始废弃。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| id     | number | 是   | 指定控件的id值。 |

**返回值：**

| 类型                | 说明                             |
| ------------------- | -------------------------------- |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件id属性的By对象。 |

**示例：**

```js
let by = BY.id(123); // 使用静态构造器BY创建by对象，指定目标控件的id属性。
```


### type<sup>(deprecated)</sup>

type(tp: string): By

指定目标控件的控件类型属性，返回By对象自身。

从API version 9开始不再维护，建议使用[type<sup>9+</sup>](#type9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| tp     | string | 是   | 指定控件类型。 |

**返回值：**

| 类型                | 说明                                     |
| ------------------- | ---------------------------------------- |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件的控件类型属性的By对象。 |

**示例：**

```js
let by = BY.type('button'); // 使用静态构造器BY创建by对象，指定目标控件的控件类型属性。
```


### clickable<sup>(deprecated)</sup>

clickable(b?: boolean): By

指定目标控件的可点击状态属性，返回By对象自身。

从API version 9开始不再维护，建议使用[clickable<sup>9+</sup>](#clickable9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | 否   | 指定控件可点击状态，true：可点击，false：不可点击。默认为true。 |

**返回值：**

| 类型                | 说明                                       |
| ------------------- | ------------------------------------------ |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件的可点击状态属性的By对象。 |

**示例：**

```js
let by = BY.clickable(true); // 使用静态构造器BY创建by对象，指定目标控件的可点击状态属性。
```


### scrollable<sup>(deprecated)</sup>

scrollable(b?: boolean): By

指定目标控件的可滑动状态属性，返回By对象自身。

从API version 9开始不再维护，建议使用[scrollable<sup>9+</sup>](#scrollable9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                        |
| ------ | ------- | ---- | ----------------------------------------------------------- |
| b      | boolean | 否   | 控件可滑动状态，true：可滑动，false：不可滑动。默认为true。 |

**返回值：**

| 类型                | 说明                                       |
| ------------------- | ------------------------------------------ |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件的可滑动状态属性的By对象。 |

**示例：**

```js
let by = BY.scrollable(true); // 使用静态构造器BY创建by对象，指定目标控件的可滑动状态属性。
```

### enabled<sup>(deprecated)</sup>

enabled(b?: boolean): By

指定目标控件的使能状态属性，返回By对象自身。

从API version 9开始不再维护，建议使用[enabled<sup>9+</sup>](#enabled9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| b      | boolean | 否   | 指定控件使能状态，true：使能，false：未使能。默认为true。 |

**返回值：**

| 类型                | 说明                                     |
| ------------------- | ---------------------------------------- |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件的使能状态属性的By对象。 |

**示例：**

```js
let by = BY.enabled(true); // 使用静态构造器BY创建by对象，指定目标控件的使能状态属性。
```

### focused<sup>(deprecated)</sup>

focused(b?: boolean): By

指定目标控件的获焦状态属性，返回By对象自身。

从API version 9开始不再维护，建议使用[focused<sup>9+</sup>](#focused9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                  |
| ------ | ------- | ---- | ----------------------------------------------------- |
| b      | boolean | 否   | 控件获焦状态，true：获焦，false：未获焦。默认为true。 |

**返回值：**

| 类型                | 说明                                     |
| ------------------- | ---------------------------------------- |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件的获焦状态属性的By对象。 |

**示例：**

```js
let by = BY.focused(true); // 使用静态构造器BY创建by对象，指定目标控件的获焦状态属性。
```

### selected<sup>(deprecated)</sup>

selected(b?: boolean): By

指定目标控件的被选中状态属性，返回By对象自身。

从API version 9开始不再维护，建议使用[selected<sup>9+</sup>](#selected9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| b      | boolean | 否   | 指定控件被选中状态，true：被选中，false：未被选中。默认为true。 |

**返回值：**

| 类型                | 说明                                       |
| ------------------- | ------------------------------------------ |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件的被选中状态属性的By对象。 |

**示例：**

```js
let by = BY.selected(true); // 使用静态构造器BY创建by对象，指定目标控件的被选中状态属性。
```

### isBefore<sup>(deprecated)</sup>

isBefore(by: By): By

指定目标控件位于给出的特征属性控件之前，返回By对象自身。

从API version 9开始不再维护，建议使用[isBefore<sup>9+</sup>](#isbefore9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型                | 必填 | 说明             |
| ------ | ------------------- | ---- | ---------------- |
| by     | [By<sup>(deprecated)</sup>](#bydeprecated) | 是   | 特征控件的属性。 |

**返回值：**

| 类型                | 说明                                                 |
| ------------------- | ---------------------------------------------------- |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件位于给出的特征属性控件之前的By对象。 |

**示例：**

```js
let by = BY.isBefore(BY.text('123')); // 使用静态构造器BY创建by对象，指定目标控件位于给出的特征属性控件之前。
```

### isAfter<sup>(deprecated)</sup>

isAfter(by: By): By

指定目标控件位于给出的特征属性控件之后，返回By对象自身。

从API version 9开始不再维护，建议使用[isAfter<sup>9+</sup>](#isafter9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型                | 必填 | 说明             |
| ------ | ------------------- | ---- | ---------------- |
| by     | [By<sup>(deprecated)</sup>](#bydeprecated) | 是   | 特征控件的属性。 |

**返回值：**

| 类型                | 说明                                                 |
| ------------------- | ---------------------------------------------------- |
| [By<sup>(deprecated)</sup>](#bydeprecated) | 返回指定目标控件位于给出的特征属性控件之后的By对象。 |

**示例：**

```js
let by = BY.isAfter(BY.text('123')); // 使用静态构造器BY创建by对象，指定目标控件位于给出的特征属性控件之后。
```

## UiComponent<sup>(deprecated)</sup>

UiTest中，UiComponent类代表了UI界面上的一个控件，提供控件属性获取，控件点击，滑动查找，文本注入等API。
该类提供的所有方法都使用Promise方式作为异步方法，需使用await调用。

从API version 9开始不再维护，建议使用[Component<sup>9+</sup>](#component9)。

### click<sup>(deprecated)</sup>

click(): Promise\<void>

控件对象进行点击操作。

从API version 9开始不再维护，建议使用[click<sup>9+</sup>](#click9)。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    await button.click();
}
```

### doubleClick<sup>(deprecated)</sup>

doubleClick(): Promise\<void>

控件对象进行双击操作。

从API version 9开始不再维护，建议使用[doubleClick<sup>9+</sup>](#doubleclick9)。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    await button.doubleClick();
}
```

### longClick<sup>(deprecated)</sup>

longClick(): Promise\<void>

控件对象进行长按操作。

从API version 9开始不再维护，建议使用[longClick<sup>9+</sup>](#longclick9)。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    await button.longClick();
}
```

### getId<sup>(deprecated)</sup>

getId(): Promise\<number>

获取控件对象的id值。

从API version 9开始不再维护，被废弃。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                            |
| ---------------- | ------------------------------- |
| Promise\<number> | 以Promise形式返回的控件的id值。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    let num = await button.getId();
}
```

### getKey<sup>(deprecated)</sup>

getKey(): Promise\<string>

获取控件对象的key值。

从API version 9开始不再维护，建议使用[getId<sup>9+</sup>](#getid9)

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                           |
| ---------------- | ------------------------------ |
| Promise\<string> | 以Promise形式返回控件的key值。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    let str_key = await button.getKey();
}
```

### getText<sup>(deprecated)</sup>

getText(): Promise\<string>

获取控件对象的文本信息。

从API version 9开始不再维护，建议使用[getText<sup>9+</sup>](#gettext9)。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                              |
| ---------------- | --------------------------------- |
| Promise\<string> | 以Promise形式返回控件的文本信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    let text = await button.getText();
}
```

### getType<sup>(deprecated)</sup>

getType(): Promise\<string>

获取控件对象的控件类型。

从API version 9开始不再维护，建议使用[getType<sup>9+</sup>](#gettype9)。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型             | 说明                          |
| ---------------- | ----------------------------- |
| Promise\<string> | 以Promise形式返回控件的类型。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.type('button'));
    let type = await button.getType();
}
```

### isClickable<sup>(deprecated)</sup>

isClickable(): Promise\<boolean>

获取控件对象可点击状态。

从API version 9开始不再维护，建议使用[isClickable<sup>9+</sup>](#isclickable9)。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回控件对象可点击状态，true：可点击，false：不可点击。 |

**示例：**

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

获取控件对象可滑动状态。

从API version 9开始不再维护，建议使用[isScrollable<sup>9+</sup>](#isscrollable9)。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回控件对象可滑动状态，true：可滑动，false：不可滑动。 |

**示例：**

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

获取控件使能状态。

从API version 9开始不再维护，建议使用[isEnabled<sup>9+</sup>](#isenabled9)。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                       |
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | 以Promise形式返回控件使能状态，true：使能，false：未使能。 |

**示例：**

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

判断控件对象是否获焦。

从API version 9开始不再维护，建议使用[isFocused<sup>9+</sup>](#isfocused9)。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回控件对象是否获焦，true：获焦，false：未获焦。 |

**示例：**

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

获取控件对象被选中状态。

从API version 9开始不再维护，建议使用[isSelected<sup>9+</sup>](#isselected9)。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型              | 说明                                                  |
| ----------------- | ----------------------------------------------------- |
| Promise\<boolean> | 控件对象被选中的状态，true：被选中，false：未被选中。 |

**示例：**

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

向控件中输入文本(适用于文本框控件)。

从API version 9开始不再维护，建议使用[inputText<sup>9+</sup>](#inputtext9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| text   | string | 是   | 输入的文本信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let text = await driver.findComponent(BY.text('hello world'));
    await text.inputText('123');
}
```

### scrollSearch<sup>(deprecated)</sup>

scrollSearch(by: By): Promise\<UiComponent>

在控件上滑动查找目标控件(适用于List等支持滑动的控件)。

从API version 9开始不再维护，建议使用[scrollSearch<sup>9+</sup>](#scrollsearch9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型                | 必填 | 说明                 |
| ------ | ------------------- | ---- | -------------------- |
| by     | [By<sup>(deprecated)</sup>](#bydeprecated) | 是   | 目标控件的属性要求。 |

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise\<[UiComponent<sup>(deprecated)</sup>](#uicomponentdeprecated)> | 以Promise形式返回找到的目标控件对象。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let scrollBar = await driver.findComponent(BY.type('Scroll'));
    let button = await scrollBar.scrollSearch(BY.text('next page'));
}
```

## UiDriver<sup>(deprecated)</sup>

UiDriver类为uitest测试框架的总入口，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等API。
该类提供的方法除UiDriver.create()以外的所有方法都使用Promise方式作为异步方法，需使用await调用。

从API version 9开始不再维护，建议使用[Driver<sup>9+</sup>](#driver9)。

### create<sup>(deprecated)</sup>

static create(): UiDriver

静态方法，构造一个UiDriver对象，并返回该对象。

从API version 9开始不再维护，建议使用[create<sup>9+</sup>](#create9)。

**系统能力**：SystemCapability.Test.UiTest

**返回值：**

| 类型     | 说明                     |
| -------- | ------------------------ |
| UiDriver | 返回构造的UiDriver对象。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
}
```

### delayMs<sup>(deprecated)</sup>

delayMs(duration: number): Promise\<void>

UiDriver对象在给定的时间内延时。

从API version 9开始不再维护，建议使用[delayMs<sup>9+</sup>](#delayms9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型   | 必填 | 说明         |
| -------- | ------ | ---- | ------------ |
| duration | number | 是   | 给定的时间。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.delayMs(1000);
}
```

### findComponent<sup>(deprecated)</sup>

findComponent(by: By): Promise\<UiComponent>

在UiDriver对象中，根据给出的目标控件属性要求查找目标控件。

从API version 9开始不再维护，建议使用[findComponent<sup>9+</sup>](#findcomponent9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型                | 必填 | 说明                 |
| ------ | ------------------- | ---- | -------------------- |
| by     | [By<sup>(deprecated)</sup>](#bydeprecated) | 是   | 目标控件的属性要求。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[UiComponent<sup>(deprecated)</sup>](#uicomponentdeprecated)> | 以Promise形式返回找到的控件对象。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let button = await driver.findComponent(BY.text('next page'));
}
```

### findComponents<sup>(deprecated)</sup>

findComponents(by: By): Promise\<Array\<UiComponent>>

在UiDriver对象中，根据给出的目标控件属性要求查找出所有匹配控件，以列表保存。

从API version 9开始不再维护，建议使用[findComponents<sup>9+</sup>](#findcomponents9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型                | 必填 | 说明                 |
| ------ | ------------------- | ---- | -------------------- |
| by     | [By<sup>(deprecated)</sup>](#bydeprecated) | 是   | 目标控件的属性要求。 |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise\<Array\<[UiComponent<sup>(deprecated)</sup>](#uicomponentdeprecated)>> | 以Promise形式返回找到的控件对象的列表。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    let buttonList = await driver.findComponents(BY.text('next page'));
}
```

### assertComponentExist<sup>(deprecated)</sup>

assertComponentExist(by: By): Promise\<void>

断言API，用于断言当前界面存在满足给出的目标控件属性的控件; 如果控件不存在，该API将抛出JS异常，使当前测试用例失败。

从API version 9开始不再维护，建议使用[assertComponentExist<sup>9+</sup>](#assertcomponentexist9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型                | 必填 | 说明                 |
| ------ | ------------------- | ---- | -------------------- |
| by     | [By<sup>(deprecated)</sup>](#bydeprecated) | 是   | 目标控件的属性要求。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.assertComponentExist(BY.text('next page'));
}
```

### pressBack<sup>(deprecated)</sup>

pressBack(): Promise\<void>

UiDriver对象进行点击BACK键的操作。

从API version 9开始不再维护，建议使用[pressBack<sup>9+</sup>](#pressback9)。

**系统能力**：SystemCapability.Test.UiTest

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.pressBack();
}
```

### triggerKey<sup>(deprecated)</sup>

triggerKey(keyCode: number): Promise\<void>

UiDriver对象采取如下操作：通过key值找到对应键并点击。

从API version 9开始不再维护，建议使用[triggerKey<sup>9+</sup>](#triggerkey9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名  | 类型   | 必填 | 说明          |
| ------- | ------ | ---- | ------------- |
| keyCode | number | 是   | 指定的key值。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.triggerKey(123);
}
```


### click<sup>(deprecated)</sup>

click(x: number, y: number): Promise\<void>

UiDriver对象采取如下操作：在目标坐标点单击。

从API version 9开始不再维护，建议使用[click<sup>9+</sup>](#click9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.click(100,100);
}
```

### doubleClick<sup>(deprecated)</sup>

doubleClick(x: number, y: number): Promise\<void>

UiDriver对象采取如下操作：在目标坐标点双击。

从API version 9开始不再维护，建议使用[doubleClick<sup>9+</sup>](#doubleclick9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.doubleClick(100,100);
}
```

### longClick<sup>(deprecated)</sup>

longClick(x: number, y: number): Promise\<void>

UiDriver对象采取如下操作：在目标坐标点长按下鼠标左键。

从API version 9开始不再维护，建议使用[longClick<sup>9+</sup>](#longclick9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| x      | number | 是   | 以number的形式传入目标点的横坐标信息。 |
| y      | number | 是   | 以number的形式传入目标点的纵坐标信息。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.longClick(100,100);
}
```

### swipe<sup>(deprecated)</sup>

swipe(startx: number, starty: number, endx: number, endy: number): Promise\<void>

UiDriver对象采取如下操作：从给出的起始坐标点滑向给出的目的坐标点。

从API version 9开始不再维护，建议使用[swipe<sup>9+</sup>](#swipe9)。

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
    let driver = UiDriver.create();
    await driver.swipe(100,100,200,200);
}
```

### screenCap<sup>(deprecated)</sup>

screenCap(savePath: string): Promise\<boolean>

UiDriver对象采取如下操作：捕获当前屏幕，并保存为PNG格式的图片至给出的保存路径中。

从API version 9开始不再维护，建议使用[screenCap<sup>9+</sup>](#screencap9)。

**系统能力**：SystemCapability.Test.UiTest

**参数：**

| 参数名   | 类型   | 必填 | 说明           |
| -------- | ------ | ---- | -------------- |
| savePath | string | 是   | 文件保存路径。 |

**返回值：**

| 类型              | 说明                                   |
| ----------------- | -------------------------------------- |
| Promise\<boolean> | 截图操作是否成功完成。成功完成为true。 |

**示例：**

```js
async function demo() {
    let driver = UiDriver.create();
    await driver.screenCap('/local/tmp/1.png');
}
```
