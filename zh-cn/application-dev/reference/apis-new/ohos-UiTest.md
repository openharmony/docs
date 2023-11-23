# @ohos.UiTest    
UiTest提供模拟UI操作的能力，供开发者在测试场景使用，主要支持如点击、双击、长按、滑动等UI操作能力。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## 属性    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| BY<sup>(deprecated)</sup> | By | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.uitest.ON替代。 |  
| ON<sup>(9+)</sup> | On | true | true |  |  
    
## MatchPattern    
控件属性支持的匹配模式。    
    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| EQUALS | 0 | 等于给定值。  |  
| CONTAINS | 1 | 包含给定值。 |  
| STARTS_WITH | 2 | 以给定值开始。 |  
| ENDS_WITH | 3 | 以给定值结束。 |  
    
## By<sup>(deprecated)</sup>    
UiTest框架通过By类提供了丰富的控件特征描述API，用于进行控件筛选来匹配/查找出目标控件。  
  
By提供的API能力具有以下几个特点:  
1、支持单属性匹配和多属性组合匹配，例如同时指定目标控件text和id。  
2、控件属性支持多种匹配模式。  
3、支持控件绝对定位，相对定位，可通过[By.isBefore<sup>(deprecated)</sup>](#isbeforedeprecated)和[By.isAfter<sup>(deprecated)</sup>](#isafterdeprecated)等API限定邻近控件特征进行辅助定位。  
By类提供的所有API均为同步接口，建议使用者通过静态构造器BY来链式创建By对象。  
  
从API version 9开始不再维护，建议使用[On<sup>9+</sup>](#on9)。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.UiTest.On替代。  
 **系统能力:**  SystemCapability.Test.UiTest    
### text<sup>(deprecated)</sup>    
指定目标控件文本属性，支持多种匹配模式，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[text<sup>9+</sup>](#text9)。  
 **调用形式：**     
- text(txt: string, pattern?: MatchPattern): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#text。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| txt<sup>(deprecated)</sup> | string | true | 指定控件文本，用于匹配目标控件文本。 |  
| pattern<sup>(deprecated)</sup> | MatchPattern | false | 指定的文本匹配模式，默认为[EQUALS](#matchpattern)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件文本属性的By对象。 |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.text('123'); // 使用静态构造器ON创建On对象，指定目标控件的text属性。  
    
```    
  
    
### key<sup>(deprecated)</sup>    
指定目标控件key值属性，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[id<sup>9+</sup>](#id9)。  
 **调用形式：**     
- key(key: string): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#id。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 指定控件的Key值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件key值属性的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.key('123'); // 使用静态构造器BY创建by对象，指定目标控件的key值属性。  
    
```    
  
    
### id<sup>(deprecated)</sup>    
指定目标控件id属性，返回By对象自身。  
 **调用形式：**     
- id(id: number): By  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 指定控件的id值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件id属性的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.id(123); // 使用静态构造器BY创建by对象，指定目标控件的id属性。  
    
```    
  
    
### type<sup>(deprecated)</sup>    
指定目标控件的控件类型属性，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[type<sup>9+</sup>](#type9)。  
 **调用形式：**     
- type(tp: string): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#type。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tp<sup>(deprecated)</sup> | string | true | 指定控件类型。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件的控件类型属性的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.type('button'); // 使用静态构造器BY创建by对象，指定目标控件的控件类型属性。  
    
```    
  
    
### clickable<sup>(deprecated)</sup>    
指定目标控件的可点击状态属性，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[clickable<sup>9+</sup>](#clickable9)。  
 **调用形式：**     
- clickable(b?: boolean): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#clickable。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b<sup>(deprecated)</sup> | boolean | false | 指定控件可点击状态，true：可点击，false：不可点击。默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件的可点击状态属性的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.clickable(true); // 使用静态构造器BY创建by对象，指定目标控件的可点击状态属性。  
    
```    
  
    
### scrollable<sup>(deprecated)</sup>    
指定目标控件的可滑动状态属性，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[scrollable<sup>9+</sup>](#scrollable9)。  
 **调用形式：**     
- scrollable(b?: boolean): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#scrollable。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b<sup>(deprecated)</sup> | boolean | false | 控件可滑动状态，true：可滑动，false：不可滑动。默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件的可滑动状态属性的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.scrollable(true); // 使用静态构造器BY创建by对象，指定目标控件的可滑动状态属性。  
    
```    
  
    
### enabled<sup>(deprecated)</sup>    
指定目标控件的使能状态属性，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[enabled<sup>9+</sup>](#enabled9)。  
 **调用形式：**     
- enabled(b?: boolean): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#enabled。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b<sup>(deprecated)</sup> | boolean | false | 指定控件使能状态，true：使能，false：未使能。默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件的使能状态属性的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.enabled(true); // 使用静态构造器BY创建by对象，指定目标控件的使能状态属性。  
    
```    
  
    
### focused<sup>(deprecated)</sup>    
指定目标控件的获焦状态属性，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[focused<sup>9+</sup>](#focused9)。  
 **调用形式：**     
- focused(b?: boolean): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#focused。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b<sup>(deprecated)</sup> | boolean | false | 控件获焦状态，true：获焦，false：未获焦。默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件的获焦状态属性的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.focused(true); // 使用静态构造器BY创建by对象，指定目标控件的获焦状态属性。  
    
```    
  
    
### selected<sup>(deprecated)</sup>    
指定目标控件的被选中状态属性，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[selected<sup>9+</sup>](#selected9)。  
 **调用形式：**     
- selected(b?: boolean): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#selected。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b<sup>(deprecated)</sup> | boolean | false | 指定控件被选中状态，true：被选中，false：未被选中。默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件的被选中状态属性的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.selected(true); // 使用静态构造器BY创建by对象，指定目标控件的被选中状态属性。  
    
```    
  
    
### isBefore<sup>(deprecated)</sup>    
指定目标控件位于给出的特征属性控件之前，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[isBefore<sup>9+</sup>](#isbefore9)。  
 **调用形式：**     
- isBefore(by: By): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#isBefore。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| by<sup>(deprecated)</sup> | By | true | 特征控件的属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件位于给出的特征属性控件之前的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.isBefore(BY.text('123')); // 使用静态构造器BY创建by对象，指定目标控件位于给出的特征属性控件之前。  
    
```    
  
    
### isAfter<sup>(deprecated)</sup>    
指定目标控件位于给出的特征属性控件之后，返回By对象自身。  
  
从API version 9开始不再维护，建议使用[isAfter<sup>9+</sup>](#isafter9)。  
 **调用形式：**     
- isAfter(by: By): By  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.On#isAfter。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| by<sup>(deprecated)</sup> | By | true | 特征控件的属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| By | 返回指定目标控件位于给出的特征属性控件之后的By对象。 |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.isAfter(BY.text('123')); // 使用静态构造器BY创建by对象，指定目标控件位于给出的特征属性控件之后。  
    
```    
  
    
## UiComponent<sup>(deprecated)</sup>    
UiTest中，UiComponent类代表了UI界面上的一个控件，提供控件属性获取，控件点击，滑动查找，文本注入等API。  
该类提供的所有方法都使用Promise方式作为异步方法，需使用await调用。  
  
从API version 9开始不再维护，建议使用[Component<sup>9+</sup>](#component9)。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.uitest.Component替代。  
 **系统能力:**  SystemCapability.Test.UiTest    
### click<sup>(deprecated)</sup>    
控件对象进行点击操作。  
  
从API version 9开始不再维护，建议使用[click<sup>9+</sup>](#click9)。  
 **调用形式：**     
- click(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#click。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let button = await driver.findComponent(BY.type('button'));  
    await button.click();  
}  
    
```    
  
    
### doubleClick<sup>(deprecated)</sup>    
控件对象进行双击操作。  
  
从API version 9开始不再维护，建议使用[doubleClick<sup>9+</sup>](#doubleclick9)。  
 **调用形式：**     
- doubleClick(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#doubleClick。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let button = await driver.findComponent(BY.type('button'));  
    await button.doubleClick();  
}  
    
```    
  
    
### longClick<sup>(deprecated)</sup>    
控件对象进行长按操作。  
  
从API version 9开始不再维护，建议使用[longClick<sup>9+</sup>](#longclick9)。  
 **调用形式：**     
- longClick(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#longClick。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let button = await driver.findComponent(BY.type('button'));  
    await button.longClick();  
}  
    
```    
  
    
### getId<sup>(deprecated)</sup>    
获取控件对象的id值。  
  
从API version 9开始不再维护，被废弃。  
 **调用形式：**     
- getId(): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 以Promise形式返回的控件的id值。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let button = await driver.findComponent(BY.type('button'));  
    let num = await button.getId();  
}  
    
```    
  
    
### getKey<sup>(deprecated)</sup>    
获取控件对象的key值。  
  
从API version 9开始不再维护，建议使用[getId<sup>9+</sup>](#getid9)。import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let button = await driver.findComponent(BY.type('button'));  
    let str_key = await button.getKey();  
}。  
 **调用形式：**     
- getKey(): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#getId。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 以Promise形式返回控件的key值。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let button = await driver.findComponent(BY.type('button'));  
    let str_key = await button.getKey();  
}  
    
```    
  
    
### getText<sup>(deprecated)</sup>    
获取控件对象的文本信息。  
  
从API version 9开始不再维护，建议使用[getText<sup>9+</sup>](#gettext9)。  
  
**系统能力**：SystemCapability.Test.UiTest。  
 **调用形式：**     
- getText(): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#getText。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 以Promise形式返回控件的文本信息。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let button = await driver.findComponent(BY.type('button'));  
    let text = await button.getText();  
}  
    
```    
  
    
### getType<sup>(deprecated)</sup>    
获取控件对象的控件类型。  
  
从API version 9开始不再维护，建议使用[getType<sup>9+</sup>](#gettype9)。  
 **调用形式：**     
- getType(): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#getType。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 以Promise形式返回控件的类型。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let button = await driver.findComponent(BY.type('button'));  
    let type = await button.getType();  
}  
    
```    
  
    
### isClickable<sup>(deprecated)</sup>    
获取控件对象可点击状态。  
  
从API version 9开始不再维护，建议使用[isClickable<sup>9+</sup>](#isclickable9)。  
 **调用形式：**     
- isClickable(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#isClickable。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回控件对象可点击状态，true：可点击，false：不可点击。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
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
  
  
获取控件对象可滑动状态。  
  
从API version 9开始不再维护，建议使用[isScrollable<sup>9+</sup>](#isscrollable9)。  
 **调用形式：**     
- isScrollable(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#isScrollable。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回控件对象可滑动状态，true：可滑动，false：不可滑动。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
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
获取控件使能状态。  
  
从API version 9开始不再维护，建议使用[isEnabled<sup>9+</sup>](#isenabled9)。  
 **调用形式：**     
- isEnabled(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#isEnabled。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回控件使能状态，true：使能，false：未使能。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
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
判断控件对象是否获焦。  
  
从API version 9开始不再维护，建议使用[isFocused<sup>9+</sup>](#isfocused9)。  
 **调用形式：**     
- isFocused(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#isFocused。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回控件对象是否获焦，true：获焦，false：未获焦。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
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
获取控件对象被选中状态。  
  
从API version 9开始不再维护，建议使用[isSelected<sup>9+</sup>](#isselected9)。  
 **调用形式：**     
- isSelected(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#isSelected。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 控件对象被选中的状态，true：被选中，false：未被选中。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
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
向控件中输入文本(适用于文本框控件)。  
  
从API version 9开始不再维护，建议使用[inputText<sup>9+</sup>](#inputtext9)。  
 **调用形式：**     
- inputText(text: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#inputText。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text<sup>(deprecated)</sup> | string | true | 输入的文本信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let text = await driver.findComponent(BY.text('hello world'));  
    await text.inputText('123');  
}  
    
```    
  
    
### scrollSearch<sup>(deprecated)</sup>    
在控件上滑动查找目标控件(适用于List等支持滑动的控件)。  
  
从API version 9开始不再维护，建议使用[scrollSearch<sup>9+</sup>](#scrollsearch9)。  
 **调用形式：**     
- scrollSearch(by: By): Promise\<UiComponent>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Component#scrollSearch。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| by<sup>(deprecated)</sup> | By | true | 目标控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<UiComponent> | 以Promise形式返回找到的目标控件对象。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
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
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.uitest.Driver替代。  
 **系统能力:**  SystemCapability.Test.UiTest    
### create<sup>(deprecated)</sup>    
静态方法，构造一个UiDriver对象，并返回该对象。  
  
从API version 9开始不再维护，建议使用[create<sup>9+</sup>](#create9)。  
 **调用形式：**     
- static create(): UiDriver  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#create。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| UiDriver | 返回构造的UiDriver对象。 |  
    
 **示例代码：**   
```ts    
import { UiDriver } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
}  
    
```    
  
    
### delayMs<sup>(deprecated)</sup>    
UiDriver对象在给定的时间内延时。  
  
从API version 9开始不再维护，建议使用[delayMs<sup>9+</sup>](#delayms9)。  
 **调用形式：**     
- delayMs(duration: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#delayMs。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| duration<sup>(deprecated)</sup> | number | true | 给定的时间。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    await driver.delayMs(1000);  
}  
    
```    
  
    
### findComponent<sup>(deprecated)</sup>    
在UiDriver对象中，根据给出的目标控件属性要求查找目标控件。  
  
从API version 9开始不再维护，建议使用[findComponent<sup>9+</sup>](#findcomponent9)。  
 **调用形式：**     
- findComponent(by: By): Promise\<UiComponent>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#findComponent。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| by<sup>(deprecated)</sup> | By | true | 目标控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<UiComponent> | 以Promise形式返回找到的控件对象。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let button = await driver.findComponent(BY.text('next page'));  
}  
    
```    
  
    
### findComponents<sup>(deprecated)</sup>    
在UiDriver对象中，根据给出的目标控件属性要求查找出所有匹配控件，以列表保存。  
  
从API version 9开始不再维护，建议使用[findComponents<sup>9+</sup>](#findcomponents9)。  
 **调用形式：**     
- findComponents(by: By): Promise\<Array\<UiComponent>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#findComponents。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| by<sup>(deprecated)</sup> | By | true | 目标控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<UiComponent>> | 以Promise形式返回找到的控件对象。 |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let buttonList = await driver.findComponents(BY.text('next page'));  
}  
    
```    
  
    
### assertComponentExist<sup>(deprecated)</sup>    
断言API，用于断言当前界面存在满足给出的目标控件属性的控件; 如果控件不存在，该API将抛出JS异常，使当前测试用例失败。  
  
从API version 9开始不再维护，建议使用[assertComponentExist<sup>9+</sup>](#assertcomponentexist9)。  
 **调用形式：**     
- assertComponentExist(by: By): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#assertComponentExist。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| by<sup>(deprecated)</sup> | By | true | 目标控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000003 | if the assertion failed. |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    await driver.assertComponentExist(BY.text('next page'));  
}  
    
```    
  
    
### pressBack<sup>(deprecated)</sup>    
UiDriver对象进行点击BACK键的操作。  
  
从API version 9开始不再维护，建议使用[pressBack<sup>9+</sup>](#pressback9)。  
 **调用形式：**     
- pressBack(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#pressBack。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    await driver.pressBack();  
}  
    
```    
  
    
### triggerKey<sup>(deprecated)</sup>    
UiDriver对象采取如下操作：通过key值找到对应键并点击。  
  
从API version 9开始不再维护，建议使用[triggerKey<sup>9+</sup>](#triggerkey9)。  
 **调用形式：**     
- triggerKey(keyCode: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#triggerKey。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyCode<sup>(deprecated)</sup> | number | true | 指定的key值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    await driver.triggerKey(123);  
}  
    
```    
  
    
### click<sup>(deprecated)</sup>    
UiDriver对象采取如下操作：在目标坐标点单击。  
  
从API version 9开始不再维护，建议使用[click<sup>9+</sup>](#click9)。  
 **调用形式：**     
- click(x: number, y: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#click。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x<sup>(deprecated)</sup> | number | true | 以number的形式传入目标点的横坐标信息。 |  
| y<sup>(deprecated)</sup> | number | true | 以number的形式传入目标点的纵坐标信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    await driver.click(100,100);  
}  
    
```    
  
    
### doubleClick<sup>(deprecated)</sup>    
UiDriver对象采取如下操作：在目标坐标点双击。  
  
从API version 9开始不再维护，建议使用[doubleClick<sup>9+</sup>](#doubleclick9)。  
 **调用形式：**     
- doubleClick(x: number, y: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#doubleClick。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x<sup>(deprecated)</sup> | number | true | 以number的形式传入目标点的横坐标信息。 |  
| y<sup>(deprecated)</sup> | number | true | 以number的形式传入目标点的纵坐标信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    await driver.doubleClick(100,100);  
}  
    
```    
  
    
### longClick<sup>(deprecated)</sup>    
UiDriver对象采取如下操作：在目标坐标点长按下鼠标左键。  
  
从API version 9开始不再维护，建议使用[longClick<sup>9+</sup>](#longclick9)。  
 **调用形式：**     
- longClick(x: number, y: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#longClick。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x<sup>(deprecated)</sup> | number | true | 以number的形式传入目标点的横坐标信息。 |  
| y<sup>(deprecated)</sup> | number | true | 以number的形式传入目标点的纵坐标信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    await driver.longClick(100,100);  
}  
    
```    
  
    
### swipe<sup>(deprecated)</sup>    
UiDriver对象采取如下操作：从给出的起始坐标点滑向给出的目的坐标点。  
  
从API version 9开始不再维护，建议使用[swipe<sup>9+</sup>](#swipe9)。  
 **调用形式：**     
- swipe(startx: number, starty: number, endx: number, endy: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.UiTest.Driver#swipe。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| startx<sup>(deprecated)</sup> | number | true | 以number的形式传入起始点的横坐标信息。 |  
| starty<sup>(deprecated)</sup> | number | true | 以number的形式传入起始点的纵坐标信息。 |  
| endx<sup>(deprecated)</sup> | number | true | 以number的形式传入目的点的横坐标信息。 |  
| endy<sup>(deprecated)</sup> | number | true | 以number的形式传入目的点的纵坐标信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    await driver.swipe(100,100,200,200);  
}  
    
```    
  
    
### screenCap<sup>(deprecated)</sup>    
UiDriver对象采取如下操作：捕获当前屏幕，并保存为PNG格式的图片至给出的保存路径中。  
  
从API version 9开始不再维护，建议使用[screenCap<sup>9+</sup>](#screencap9)。  
 **调用形式：**     
- screenCap(savePath: string): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.uitest.Driver#screenCap。  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| savePath<sup>(deprecated)</sup> | string | true | 文件保存路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> |  |  
    
 **示例代码：**   
```ts    
import { UiDriver } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    await driver.screenCap('/data/storage/el2/base/cache/1.png');  
}  
    
```    
  
    
## WindowMode<sup>(9+)</sup>    
窗口的窗口模式。    
    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FULLSCREEN | 0 | 全屏模式。 |  
| PRIMARY | 1 | 主窗口。 |  
| SECONDARY | 2 | 第二窗口。 |  
| FLOATING | 3 | 浮动窗口。 |  
    
## ResizeDirection<sup>(9+)</sup>    
窗口调整大小的方向。    
    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LEFT | 0 | 左方。 |  
| RIGHT | 1 | 右方。 |  
| UP | 2 | 上方。 |  
| DOWN | 3 | 下方。 |  
| LEFT_UP | 4 | 左上方。 |  
| LEFT_DOWN | 5 | 左下方。 |  
| RIGHT_UP | 6 | 右上方。 |  
| RIGHT_DOWN | 7 | 右下方。 |  
    
## DisplayRotation<sup>(9+)</sup>    
设备显示器的显示方向。    
    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ROTATION_0 | 0 | 设备显示器不旋转，初始形态垂直显示。 |  
| ROTATION_90 | 1 | 设备显示器顺时针旋转90°，水平显示。 |  
| ROTATION_180 | 2 | 设备显示器顺时针旋转180°，逆向垂直显示。 |  
| ROTATION_270 | 3 | 设备显示器顺时针旋转270°，逆向水平显示。 |  
    
## Point<sup>(9+)</sup>    
坐标点信息。  
 **系统能力:**  SystemCapability.Test.UiTest    
### 属性    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x<sup>(9+)</sup> | number | true | true | 坐标点的横坐标。 |  
| y<sup>(9+)</sup> | number | true | true | 坐标点的纵坐标。 |  
    
## Rect<sup>(9+)</sup>    
控件的边框信息。  
 **系统能力:**  SystemCapability.Test.UiTest    
### 属性    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left<sup>(9+)</sup> | number | true | true | 控件边框的左上角的X坐标。 |  
| top<sup>(9+)</sup> | number | true | true | 控件边框的左上角的Y坐标。 |  
| right<sup>(9+)</sup> | number | true | true | 控件边框的右下角的X坐标。 |  
| bottom<sup>(9+)</sup> | number | true | true | 控件边框的右下角的Y坐标。 |  
    
## WindowFilter<sup>(9+)</sup>    
窗口的标志属性信息。  
 **系统能力:**  SystemCapability.Test.UiTest    
### 属性    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName<sup>(9+)</sup> | string | false | false | 窗口归属应用的包名。 |  
| title<sup>(9+)</sup> | string | false | false | 窗口的标题信息。 |  
| focused<sup>(9+)</sup> | boolean | false | false | 窗口是否处于获焦状态。 |  
| actived<sup>(9+)</sup> | boolean | false | false | 窗口是否正与用户进行交互。 |  
    
## UIElementInfo<sup>(10+)</sup>    
UI事件的相关信息。  
 **系统能力:**  SystemCapability.Test.UiTest    
### 属性    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName<sup>(10+)</sup> | string | true | true | 归属应用的包名。 |  
| type<sup>(10+)</sup> | string | true | true | 控件/窗口类型。 |  
| text<sup>(10+)</sup> | string | true | true | 控件/窗口的文本信息。 |  
    
## UIEventObserver<sup>(10+)</sup>    
UI事件监听器。  
 **系统能力:**  SystemCapability.Test.UiTest    
### once('toastShow')<sup>(10+)</sup>    
开始监听toast控件出现的事件，使用callback的形式返回结果。  
 **调用形式：**     
    
- once(type: 'toastShow', callback: Callback\<UIElementInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅的事件类型，取值为'toastShow' |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 事件发生时执行的回调函数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { Driver, UIElementInfo } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let observer = await driver.createUIEventObserver()  
    let  callback = (UIElementInfo: UIElementInfo)=>{  
        console.info(UIElementInfo.bundleName)  
        console.info(UIElementInfo.text)  
        console.info(UIElementInfo.type)  
     }  
    observer.once('toastShow', callback)  
}  
    
```    
  
    
### once('dialogShow')<sup>(10+)</sup>    
开始监听dialog控件出现的事件，使用callback的形式返回结果。  
 **调用形式：**     
    
- once(type: 'dialogShow', callback: Callback\<UIElementInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅的事件类型，取值为'dialogShow' |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 事件发生时执行的回调函数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { Driver, UIElementInfo } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let observer = await driver.createUIEventObserver()  
    let  callback = (UIElementInfo: UIElementInfo)=>{  
        console.info(UIElementInfo.bundleName)  
        console.info(UIElementInfo.text)  
        console.info(UIElementInfo.type)  
     }  
    observer.once('dialogShow', callback)  
}  
    
```    
  
    
## UiDirection<sup>(10+)</sup>    
进行抛滑等UI操作时的方向。    
    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LEFT | 0 | 向左。 |  
| RIGHT | 1 | 向右。 |  
| UP | 2 | 向上。 |  
| DOWN | 3 | 向下。 |  
    
## MouseButton<sup>(10+)</sup>    
模拟注入的鼠标按钮。    
    
 **系统能力:**  SystemCapability.Test.UiTest    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MOUSE_BUTTON_LEFT | 0 | 鼠标左键。 |  
| MOUSE_BUTTON_RIGHT | 1 | 鼠标右键。 |  
| MOUSE_BUTTON_MIDDLE | 2 | 鼠标中间键。 |  
    
## On<sup>(9+)</sup>  
 **系统能力:**  SystemCapability.Test.UiTest    
### text<sup>(9+)</sup>    
指定目标控件文本属性，支持多种匹配模式，返回On对象自身。  
 **调用形式：**     
- text(txt: string, pattern?: MatchPattern): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| txt | string | true | 指定控件文本，用于匹配目标控件文本。 |  
| pattern | MatchPattern | false | 指定的文本匹配模式，默认为[EQUALS](#matchpattern)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.text('123'); // 使用静态构造器BY创建by对象，指定目标控件的text属性。  
    
```    
  
    
### id<sup>(9+)</sup>    
指定目标控件id属性，返回On对象自身。  
 **调用形式：**     
- id(id: string): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件id属性的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.id(123); // 使用静态构造器BY创建by对象，指定目标控件的id属性。  
    
```    
  
    
### type<sup>(9+)</sup>    
指定目标控件的控件类型属性，返回On对象自身。  
 **调用形式：**     
- type(tp: string): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tp | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件的控件类型属性的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.type('button'); // 使用静态构造器BY创建by对象，指定目标控件的控件类型属性。  
    
```    
  
    
### clickable<sup>(9+)</sup>    
指定目标控件的可点击状态属性，返回On对象自身。  
 **调用形式：**     
- clickable(b?: boolean): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b | boolean | false | 指定控件可点击状态，true：可点击，false：不可点击。默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件的可点击状态属性的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BY } from '@ohos.UiTest';  
let by = BY.clickable(true); // 使用静态构造器BY创建by对象，指定目标控件的可点击状态属性。  
    
```    
  
    
### longClickable<sup>(9+)</sup>    
指定目标控件的可长按点击状态属性，返回On对象自身。  
 **调用形式：**     
- longClickable(b?: boolean): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b | boolean | false | 指定控件可长按点击状态，true：可长按点击，false：不可长按点击。默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件的可长按点击状态属性的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.longClickable(true); // 使用静态构造器ON创建On对象，指定目标控件的可长按点击状态属性。  
    
```    
  
    
### scrollable<sup>(9+)</sup>    
指定目标控件的可滑动状态属性，返回On对象自身。  
 **调用形式：**     
- scrollable(b?: boolean): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b | boolean | false | 控件可滑动状态，true：可滑动，false：不可滑动。默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件的可滑动状态属性的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.scrollable(true); // 使用静态构造器ON创建On对象，指定目标控件的可滑动状态属性。  
    
```    
  
    
### enabled<sup>(9+)</sup>    
指定目标控件的使能状态属性，返回On对象自身。  
 **调用形式：**     
- enabled(b?: boolean): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b | boolean | false | 指定控件使能状态，true：使能，false：未使能。默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.enabled(true); // 使用静态构造器ON创建On对象，指定目标控件的使能状态属性。  
    
```    
  
    
### focused<sup>(9+)</sup>  
 **调用形式：**     
- focused(b?: boolean): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b | boolean | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.focused(true); // 使用静态构造器ON创建On对象，指定目标控件的获焦状态属性。  
    
```    
  
    
### selected<sup>(9+)</sup>  
 **调用形式：**     
- selected(b?: boolean): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b | boolean | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.selected(true); // 使用静态构造器ON创建On对象，指定目标控件的被选中状态属性。  
    
```    
  
    
### checked<sup>(9+)</sup>  
 **调用形式：**     
- checked(b?: boolean): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b | boolean | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.checked(true); // 使用静态构造器ON创建On对象，指定目标控件的被勾选状态属性  
    
```    
  
    
### checkable<sup>(9+)</sup>  
 **调用形式：**     
- checkable(b?: boolean): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| b | boolean | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件的使能状态属性的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.checkable(true); // 使用静态构造器ON创建On对象，指定目标控件的能否被勾选状态属性。  
    
```    
  
    
### isBefore<sup>(9+)</sup>    
指定目标控件位于给出的特征属性控件之前，返回On对象自身。  
 **调用形式：**     
- isBefore(on: On): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| on | On | true | 特征控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件位于给出的特征属性控件之前的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.isBefore(ON.text('123')); // 使用静态构造器ON创建On对象，指定目标控件位于给出的特征属性控件之前。  
    
```    
  
    
### isAfter<sup>(9+)</sup>    
指定目标控件位于给出的特征属性控件之后，返回On对象自身。  
 **调用形式：**     
- isAfter(on: On): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| on | On | true | 特征控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件位于给出的特征属性控件之后的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.isAfter(ON.text('123')); // 使用静态构造器ON创建On对象，指定目标控件位于给出的特征属性控件之后。  
    
```    
  
    
### within<sup>(10+)</sup>    
指定目标控件位于给出的特征属性控件之内，返回On对象自身。  
 **调用形式：**     
- within(on: On): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| on | On | true | 特征控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件位于给出的特征属性控件内的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.within(ON.type('List')); // 使用静态构造器ON创建On对象，指定目标控件位于给出的特征属性控件之内。  
    
```    
  
    
### inWindow<sup>(10+)</sup>    
指定目标控件位于给出的应用窗口内，返回On对象自身。  
 **调用形式：**     
- inWindow(bundleName: string): On  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | | bundleName | string | 是   | 应用窗口的包名。 | |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| On | 返回指定目标控件位于给出的应用窗口内的On对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ON } from '@ohos.UiTest';  
let on = ON.inWindow('com.uitestScene.acts'); // 使用静态构造器ON创建On对象，指定目标控件位于给出的应用窗口内。  
    
```    
  
    
## Component<sup>(9+)</sup>    
UiTest框架在API9中，Component类代表了UI界面上的一个控件，提供控件属性获取，控件点击，滑动查找，文本注入等API。该类提供的所有方法都使用Promise方式作为异步方法，需使用await调用。  
 **系统能力:**  SystemCapability.Test.UiTest    
### click<sup>(9+)</sup>    
控件对象进行点击操作。  
 **调用形式：**     
    
- click(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.type('button'));  
    await button.click();  
}  
    
```    
  
    
### doubleClick<sup>(9+)</sup>    
控件对象进行双击操作。  
 **调用形式：**     
    
- doubleClick(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.type('button'));  
    await button.doubleClick();  
}  
    
```    
  
    
### longClick<sup>(9+)</sup>    
控件对象进行长按操作。  
 **调用形式：**     
    
- longClick(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.type('button'));  
    await button.longClick();  
}  
    
```    
  
    
### getId<sup>(9+)</sup>    
获取控件对象的id值。  
 **调用形式：**     
    
- getId(): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<string> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.type('button'));  
    let num = await button.getId();  
}  
    
```    
  
    
### getText<sup>(9+)</sup>    
获取控件对象的文本信息。  
 **调用形式：**     
    
- getText(): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<string> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 |  |  
| 17000004 |  |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.type('button'));  
    let text = await button.getText();  
}  
    
```    
  
    
### getType<sup>(9+)</sup>  
 **调用形式：**     
    
- getType(): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<string> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.type('button'));  
    let type = await button.getType();  
}  
    
```    
  
    
### isClickable<sup>(9+)</sup>    
获取控件对象可点击属性。  
 **调用形式：**     
    
- isClickable(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
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
  
    
### isLongClickable<sup>(9+)</sup>    
获取控件对象可长按点击属性。  
 **调用形式：**     
    
- isLongClickable(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
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
  
    
### isScrollable<sup>(9+)</sup>    
获取控件对象可滑动属性。  
 **调用形式：**     
    
- isScrollable(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 以Promise形式返回控件对象是否可滑动，true：可滑动，false：不可滑动。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
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
  
    
### isEnabled<sup>(9+)</sup>    
获取控件使能状态。  
 **调用形式：**     
    
- isEnabled(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 以Promise形式返回控件使能状态，true：使能，false：未使能。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
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
  
    
### isFocused<sup>(9+)</sup>    
判断控件对象获焦状态。  
 **调用形式：**     
    
- isFocused(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 以Promise形式返回控件对象获焦状态，true：获焦，false：未获焦。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
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
  
    
### isSelected<sup>(9+)</sup>    
获取控件对象被选中状态。  
 **调用形式：**     
    
- isSelected(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 控件对象被选中状态，true：被选中，false：未被选中。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
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
  
    
### isChecked<sup>(9+)</sup>    
获取控件对象被勾选状态。  
 **调用形式：**     
    
- isChecked(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let checkBox = await driver.findComponent(ON.type('Checkbox'));  
    if(await checkBox.isChecked()) {  
        console.info('This checkBox is checked');  
    } else {  
        console.info('This checkBox is not checked');  
    }  
}  
    
```    
  
    
### isCheckable<sup>(9+)</sup>    
获取控件对象能否被勾选属性。  
 **调用形式：**     
    
- isCheckable(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 以Promise形式返回控件对象能否可被勾选属性，true：可被勾选，false：不可被勾选。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let checkBox = await driver.findComponent(ON.type('Checkbox'));  
    if(await checkBox.isCheckable()) {  
        console.info('This checkBox is checkable');  
    } else {  
        console.info('This checkBox is not checkable');  
    }  
}  
    
```    
  
    
### inputText<sup>(9+)</sup>    
向控件中输入文本(适用于文本框控件)。  
 **调用形式：**     
    
- inputText(text: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 输入的文本信息，当前支持英文和特殊字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let text = await driver.findComponent(ON.text('hello world'));  
    await text.inputText('123');  
}  
    
```    
  
    
### clearText<sup>(9+)</sup>    
清除控件的文本信息(适用于文本框控件)。  
 **调用形式：**     
    
- clearText(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let text = await driver.findComponent(ON.text('hello world'));  
    await text.clearText();  
}  
    
```    
  
    
### scrollToTop<sup>(9+)</sup>    
在控件上滑动到顶部(适用支持滑动的控件)。  
 **调用形式：**     
    
- scrollToTop(speed?: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| speed | number | false | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let scrollBar = await driver.findComponent(ON.type('Scroll'));  
    await scrollBar.scrollToTop();  
}  
    
```    
  
    
### scrollToBottom<sup>(9+)</sup>    
在控件上滑动到底部(适用支持滑动的控件)。  
 **调用形式：**     
    
- scrollToBottom(speed?: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| speed | number | false | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let scrollBar = await driver.findComponent(ON.type('Scroll'));  
    await scrollBar.scrollToBottom();  
}  
    
```    
  
    
### scrollSearch<sup>(9+)</sup>    
在控件上滑动查找目标控件(适用支持滑动的控件)。  
 **调用形式：**     
    
- scrollSearch(on: On): Promise\<Component>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| on | On | true | 目标控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Component> | 以Promise形式返回找到的目标控件对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { UiDriver, BY } from '@ohos.UiTest';  
async function demo() {  
    let driver = UiDriver.create();  
    let scrollBar = await driver.findComponent(BY.type('Scroll'));  
    let button = await scrollBar.scrollSearch(BY.text('next page'));  
}  
    
```    
  
    
### getBounds<sup>(9+)</sup>    
获取窗口的边框信息。  
 **调用形式：**     
    
- getBounds(): Promise\<Rect>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Rect> | 以Promise形式返回窗口的边框信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.type('button'));  
    let rect = await button.getBounds();  
}  
    
```    
  
    
### getBoundsCenter<sup>(9+)</sup>    
获取控件对象所占区域的中心点信息。  
 **调用形式：**     
    
- getBoundsCenter(): Promise\<Point>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Point> | 以Promise形式返回控件对象所占区域的中心点信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.type('button'));  
    let point = await button.getBoundsCenter();  
}  
    
```    
  
    
### dragTo<sup>(9+)</sup>    
将控件拖拽至目标控件处。  
 **调用形式：**     
    
- dragTo(target: Component): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target | Component | true | 目标控件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.type('button'));  
    let text = await driver.findComponent(ON.text('hello world'));  
    await button.dragTo(text);  
    }  
    
```    
  
    
### pinchOut<sup>(9+)</sup>    
将控件按指定的比例进行捏合放大。  
 **调用形式：**     
    
- pinchOut(scale: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| scale | number | true | 指定放大的比例。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let image = await driver.findComponent(ON.type('image'));  
    await image.pinchOut(1.5);  
    }  
    
```    
  
    
### pinchIn<sup>(9+)</sup>    
将控件按指定的比例进行捏合缩小。  
 **调用形式：**     
    
- pinchIn(scale: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| scale | number | true | 指定缩小的比例。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let image = await driver.findComponent(ON.type('image'));  
    await image.pinchIn(0.5);  
    }  
    
```    
  
    
## Driver<sup>(9+)</sup>    
Driver类为uitest测试框架的总入口，提供控件匹配/查找，按键注入，坐标点击/滑动，截图等能力。该类提供的方法除Driver.create()以外的所有方法都使用Promise方式作为异步方法，需使用await方式调用。  
 **系统能力:**  SystemCapability.Test.UiTest    
### create<sup>(9+)</sup>    
静态方法，构造一个Driver对象，并返回该对象。  
 **调用形式：**     
- static create(): Driver  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Driver | 返回构造的Driver对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000001 | if the test framework failed to initialize. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
}  
    
```    
  
    
### delayMs<sup>(9+)</sup>    
Driver对象在给定的时间内延时。  
 **调用形式：**     
    
- delayMs(duration: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| duration | number | true | 给定的时间，单位：ms。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.delayMs(1000);  
}  
    
```    
  
    
### findComponent<sup>(9+)</sup>    
在Driver对象中，根据给出的目标控件属性要求查找目标控件。  
 **调用形式：**     
    
- findComponent(on: On): Promise\<Component>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| on | On | true | 目标控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Component> | 以Promise形式返回找到的控件对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.findComponent(ON.text('next page'));  
}  
    
```    
  
    
### findWindow<sup>(9+)</sup>    
通过指定窗口的属性来查找目标窗口。  
 **调用形式：**     
    
- findWindow(filter: WindowFilter): Promise\<UiWindow>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filter | WindowFilter | true | 目标窗口的属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<UiWindow> | 以Promise形式返回找到的目标窗口对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
}  
    
```    
  
    
### waitForComponent<sup>(9+)</sup>    
在Driver对象中，在用户给定的时间内，持续查找满足控件属性要求的目标控件。  
 **调用形式：**     
    
- waitForComponent(on: On, time: number): Promise\<Component>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| on | On | true | 目标控件的属性要求。 |  
| time | number | true | 查找目标控件的持续时间。单位ms。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Component> | 以Promise形式返回找到的控件对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let button = await driver.waitForComponent(ON.text('next page'),500);  
}  
    
```    
  
    
### findComponents<sup>(9+)</sup>    
findComponents(on: On): Promise\<Array\<Component>>  在Driver对象中，根据给出的目标控件属性要求查找出所有匹配控件，以列表保存。  
 **调用形式：**     
    
- findComponents(on: On): Promise\<Array\<Component>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| on | On | true | 目标控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Array<Component>> | 以Promise形式返回找到的控件对象的列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let buttonList = await driver.findComponents(ON.text('next page'));  
}  
    
```    
  
    
### assertComponentExist<sup>(9+)</sup>    
断言API，用于断言当前界面是否存在满足给出的目标属性的控件。  
 **调用形式：**     
    
- assertComponentExist(on: On): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| on | On | true | 目标控件的属性要求。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000003 | if the assertion failed. |  
    
 **示例代码：**   
```ts    
import { Driver, ON } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.assertComponentExist(ON.text('next page'));  
}  
    
```    
  
    
### pressBack<sup>(9+)</sup>    
Driver对象进行点击BACK键的操作。  
 **调用形式：**     
    
- pressBack(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.pressBack();  
}  
    
```    
  
    
### triggerKey<sup>(9+)</sup>    
Driver对象采取如下操作：传入key值实现模拟点击对应按键的效果。  
 **调用形式：**     
    
- triggerKey(keyCode: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyCode | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.triggerKey(123);  
}  
    
```    
  
    
### triggerCombineKeys<sup>(9+)</sup>    
Driver对象通过给定的key值，找到对应组合键并点击。例如，Key值为(2072, 2019)时，Driver对象找到key值对应的组合键并点击，如ctrl+c。  
 **调用形式：**     
    
- triggerCombineKeys(key0: number, key1: number, key2?: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key0 | number | true | 指定的第一个key值。 |  
| key1 | number | true | 指定的第二个key值。 |  
| key2 | number | false | 指定的第三个key值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.triggerCombineKeys(2072, 2047, 2035);  
}  
    
```    
  
    
### click<sup>(9+)</sup>    
Driver对象采取如下操作：在目标坐标点单击。  
 **调用形式：**     
    
- click(x: number, y: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x | number | true | 以number的形式传入目标点的横坐标信息。 |  
| y | number | true | 以number的形式传入目标点的纵坐标信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.click(100,100);  
}  
    
```    
  
    
### doubleClick<sup>(9+)</sup>    
Driver对象采取如下操作：在目标坐标点双击。  
 **调用形式：**     
    
- doubleClick(x: number, y: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x | number | true | 以number的形式传入目标点的横坐标信息。 |  
| y | number | true | 以number的形式传入目标点的纵坐标信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.doubleClick(100,100);  
}  
    
```    
  
    
### longClick<sup>(9+)</sup>    
Driver对象采取如下操作：在目标坐标点长按。  
 **调用形式：**     
    
- longClick(x: number, y: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x | number | true | 以number的形式传入目标点的横坐标信息。 |  
| y | number | true | 以number的形式传入目标点的纵坐标信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.longClick(100,100);  
}  
    
```    
  
    
### swipe<sup>(9+)</sup>    
Driver对象采取如下操作：从起始坐标点滑向目的坐标点。  
 **调用形式：**     
    
- swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| startx | number | true | 以number的形式传入起始点的横坐标信息。 |  
| starty | number | true | 以number的形式传入起始点的纵坐标信息。 |  
| endx | number | true | 以number的形式传入目的点的横坐标信息。 |  
| endy | number | true | 以number的形式传入目的点的纵坐标信息。 |  
| speed | number | false | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.swipe(100,100,200,200,600);  
}  
    
```    
  
    
### drag<sup>(9+)</sup>    
Driver对象采取如下操作：从起始坐标点拖拽至目的坐标点。  
 **调用形式：**     
    
- drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| startx | number | true | 以number的形式传入起始点的横坐标信息。 |  
| starty | number | true | 以number的形式传入起始点的纵坐标信息。 |  
| endx | number | true | 以number的形式传入目的点的横坐标信息。 |  
| endy | number | true | 以number的形式传入目的点的纵坐标信息。 |  
| speed | number | false | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.drag(100,100,200,200,600);  
}  
    
```    
  
    
### screenCap<sup>(9+)</sup>    
Driver对象采取如下操作：捕获当前屏幕，并保存为PNG格式的图片至给出的保存路径中。  
 **调用形式：**     
    
- screenCap(savePath: string): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| savePath | string | true | 文件保存路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 截图操作是否成功完成。成功完成为true。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.screenCap('/data/storage/el2/base/cache/1.png');  
}  
    
```    
  
    
### setDisplayRotation<sup>(9+)</sup>    
将设备的屏幕显示方向设置为指定的显示方向。  
 **调用形式：**     
    
- setDisplayRotation(rotation: DisplayRotation): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotation | DisplayRotation | true | 设备的显示方向。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver, DisplayRotation } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.setDisplayRotation(DisplayRotation.ROTATION_180);  
}  
    
```    
  
    
### getDisplayRotation<sup>(9+)</sup>    
获取当前设备的屏幕显示方向。  
 **调用形式：**     
    
- getDisplayRotation(): Promise\<DisplayRotation>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<DisplayRotation> | 以Promise的形式返回当前设备的显示方向。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let rotation = await driver.getDisplayRotation();  
}  
    
```    
  
    
### setDisplayRotationEnabled<sup>(9+)</sup>    
禁用设备旋转屏幕的功能。  
 **调用形式：**     
    
- setDisplayRotationEnabled(enabled: boolean): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enabled | boolean | true | 能否旋转屏幕的标识，true：可以旋转，false：不可以旋转。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.setDisplayRotationEnabled(false);  
}  
    
```    
  
    
### getDisplaySize<sup>(9+)</sup>    
获取当前设备的屏幕大小。  
 **调用形式：**     
    
- getDisplaySize(): Promise\<Point>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Point> | 以Promise的形式返回当前设备的屏幕大小。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let size = await driver.getDisplaySize();  
}  
    
```    
  
    
### getDisplayDensity<sup>(9+)</sup>    
获取当前设备屏幕的分辨率。  
 **调用形式：**     
    
- getDisplayDensity(): Promise\<Point>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Point> | 以Promise的形式返回当前设备屏幕的分辨率。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let density = await driver.getDisplayDensity();  
}  
    
```    
  
    
### wakeUpDisplay<sup>(9+)</sup>    
唤醒当前设备即设备亮屏。  
 **调用形式：**     
    
- wakeUpDisplay(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.wakeUpDisplay();  
}  
    
```    
  
    
### pressHome<sup>(9+)</sup>    
设备返回到桌面。  
 **调用形式：**     
    
- pressHome(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.pressHome();  
}  
    
```    
  
    
### waitForIdle<sup>(9+)</sup>    
判断当前界面的所有控件是否已经空闲。  
 **调用形式：**     
    
- waitForIdle(idleTime: number, timeout: number): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| idleTime | number | true | 空闲时间的阈值。在这个时间段控件不发生变化，视为该控件空闲，单位：毫秒。 |  
| timeout | number | true | 等待空闲的最大时间，单位：毫秒。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 以Promise的形式返回当前界面的所有控件是否已经空闲。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let idled = await driver.waitForIdle(4000,5000);  
}  
    
```    
  
    
### fling<sup>(9+)</sup>    
模拟手指滑动后脱离屏幕的快速滑动操作。  
 **调用形式：**     
    
- fling(from: Point, to: Point, stepLen: number, speed: number): Promise\<void>    
起始版本： 9    
- fling(direction: UiDirection, speed: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| from | Point | true | 手指接触屏幕的起始点坐标。 |  
| to | Point | true | 手指离开屏幕时的坐标点。 |  
| stepLen | number | true | 间隔距离，单位：像素点。 |  
| speed | number | true | 滑动速率，范围：200-40000，不在范围内设为默认值为600，单位：像素点/秒。 |  
| direction<sup>(10+)</sup> | UiDirection | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.fling({x: 500, y: 480},{x: 450, y: 480},5,600);  
}  
    
```    
  
    
### injectMultiPointerAction<sup>(9+)</sup>    
向设备注入多指操作。  
 **调用形式：**     
    
- injectMultiPointerAction(pointers: PointerMatrix, speed?: number): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pointers | PointerMatrix | true | 滑动轨迹，包括操作手指个数和滑动坐标序列。 |  
| speed | number | false | 滑动速率，范围：200-15000，不在范围内设为默认值为600，单位：像素点/秒。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver, PointerMatrix } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let pointers = PointerMatrix.create(2,3);  
    pointers.setPoint(0,0,{x:230,y:480});  
    pointers.setPoint(0,1,{x:250,y:380});  
    pointers.setPoint(0,2,{x:270,y:280});  
    pointers.setPoint(1,0,{x:230,y:680});  
    pointers.setPoint(1,1,{x:240,y:580});  
    pointers.setPoint(1,2,{x:250,y:480});  
    await driver.injectMultiPointerAction(pointers);  
}  
    
```    
  
    
### mouseClick<sup>(10+)</sup>    
在指定坐标点注入鼠标点击动作，支持同时按下对应键盘组合键。例如，Key值为2072时，按下ctrl并进行鼠标点击动作。  
 **调用形式：**     
    
- mouseClick(p: Point, btnId: MouseButton, key1?: number, key2?: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| p | Point | true | 鼠标点击的坐标。 |  
| btnId | MouseButton | true | 按下的鼠标按钮。 |  
| key1 | number | false | 指定的第一个key值。 |  
| key2 | number | false | 指定的第二个key值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver,MouseButton } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.mouseClick({x:248, y:194}, MouseButton.MOUSE_BUTTON_LEFT, 2072);  
}  
    
```    
  
    
### mouseMoveTo<sup>(10+)</sup>    
将鼠标光标移到目标点。  
 **调用形式：**     
    
- mouseMoveTo(p: Point): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| p | Point | true | 目标点的坐标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.mouseMoveTo({x:100, y:100})  
}  
    
```    
  
    
### mouseScroll<sup>(10+)</sup>    
在指定坐标点注入鼠标滚轮滑动动作，支持同时按下对应键盘组合键并且指定滑动速度。  
 **调用形式：**     
    
- mouseScroll(p: Point, down: boolean, d: number, key1?: number, key2?: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| p | Point | true | 鼠标点击的坐标。 |  
| down | boolean | true | 滚轮滑动方向是否向下，true表示向下滑动，false表示向上滚动。 |  
| d | number | true | 鼠标滚轮滚动的格数，每格对应目标点位移120个像素点。 |  
| key1 | number | false | 指定的第一个key值。 |  
| key2 | number | false | 指定的第二个key值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.mouseScroll({x:360, y:640}, true, 30, 2072,20)  
}  
    
```    
  
    
### screenCapture<sup>(10+)</sup>    
捕获当前屏幕的指定区域，并保存为PNG格式的图片至给出的保存路径中。  
 **调用形式：**     
    
- screenCapture(savePath: string, rect?: Rect): Promise\<boolean>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| savePath | string | true | 文件保存路径。 |  
| rect | Rect | false | 截图区域，默认为全屏。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 截图操作是否成功完成。成功完成为true。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    await driver.screenCapture('/data/storage/el2/base/cache/1.png', {left: 0, top: 0, right: 100, bottom: 100});  
}  
    
```    
  
    
### createUIEventObserver<sup>(10+)</sup>    
创建一个UI事件监听器。  
 **调用形式：**     
- createUIEventObserver(): UIEventObserver  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| UIEventObserver |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
    
 **示例代码：**   
```ts    
<span style="font-size: 14px; letter-spacing: 0px;">import { Driver } from '@ohos.UiTest';</span>  
async function demo() {  
    let driver = Driver.create();  
    let observer = await driver.createUIEventObserver()  
}    
```    
  
    
## UiWindow<sup>(9+)</sup>    
UiWindow代表了UI界面上的一个窗口，提供窗口属性获取，窗口拖动、调整窗口大小等能力。该类提供的所有方法都使用Promise方式作为异步方法，需使用await方式调用。  
 **系统能力:**  SystemCapability.Test.UiTest    
### getBundleName<sup>(9+)</sup>    
获取窗口归属应用的包名信息。  
 **调用形式：**     
    
- getBundleName(): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<string> | 以Promise形式返回窗口归属应用的包名信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 |  |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    let name = await window.getBundleName();  
}  
    
```    
  
    
### getBounds<sup>(9+)</sup>    
获取窗口的边框信息。  
 **调用形式：**     
    
- getBounds(): Promise\<Rect>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Rect> | 以Promise形式返回窗口的边框信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    let rect = await window.getBounds();  
}  
    
```    
  
    
### getTitle<sup>(9+)</sup>    
获取窗口的标题信息。  
 **调用形式：**     
    
- getTitle(): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<string> | 以Promise形式返回窗口的标题信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    let rect = await window.getTitle();  
}  
    
```    
  
    
### getWindowMode<sup>(9+)</sup>    
获取窗口的窗口模式信息。  
 **调用形式：**     
    
- getWindowMode(): Promise\<WindowMode>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<WindowMode> | 以Promise形式返回窗口的窗口模式信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 |  |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    let mode = await window.getWindowMode();  
}  
    
```    
  
    
### isFocused<sup>(9+)</sup>    
判断窗口是否处于获焦状态。  
 **调用形式：**     
    
- isFocused(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 以Promise形式返回窗口对象是否获取获焦状态，true：获焦，false：未获焦。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    let focused = await window.isFocused();  
}  
    
```    
  
    
### isActived<sup>(9+)</sup>    
判断窗口是否为用户正在交互窗口。  
 **调用形式：**     
    
- isActived(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> | 以Promise形式返回窗口对象是否为用户正在交互窗口，true：交互窗口，false：非交互窗口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 |  |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    let focused = await window.isActived();  
}  
    
```    
  
    
### focus<sup>(9+)</sup>    
让窗口获焦。  
 **调用形式：**     
    
- focus(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    await window.focus();  
}  
    
```    
  
    
### moveTo<sup>(9+)</sup>    
将窗口移动到目标点。适用于支持移动的窗口。  
 **调用形式：**     
    
- moveTo(x: number, y: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x | number | true | 以number的形式传入目标点的横坐标信息。 |  
| y | number | true | 以number的形式传入目标点的纵坐标信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
| 17000005 | if the action is not supported on this window. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    await window.moveTo(100, 100);  
}  
    
```    
  
    
### resize<sup>(9+)</sup>    
根据传入的宽、高和调整方向来调整窗口的大小。适用于支持调整大小的窗口。  
 **调用形式：**     
    
- resize(wide: number, height: number, direction: ResizeDirection): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wide | number | true | 以number的形式传入调整后窗口的宽度。 |  
| height | number | true | 以number的形式传入调整后窗口的高度。 |  
| direction | ResizeDirection | true | 以[ResizeDirection](#resizedirection9)的形式传入窗口调整的方向。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
| 17000005 | if the action is not supported on this window. |  
    
 **示例代码：**   
```ts    
import { Driver, ResizeDirection } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    await window.resize(100, 100, ResizeDirection.LEFT);  
}  
    
```    
  
    
### split<sup>(9+)</sup>    
将窗口模式切换成分屏模式。适用于支持切换分屏模式的窗口。  
 **调用形式：**     
    
- split(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
| 17000005 | if the action is not supported on this window. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    await window.split();  
}  
    
```    
  
    
### maximize<sup>(9+)</sup>    
将窗口最大化。适用于支持窗口最大化操作的窗口。  
 **调用形式：**     
    
- maximize(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
| 17000005 | if the action is not supported on this window. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    await window.maximize();  
}  
    
```    
  
    
### minimize<sup>(9+)</sup>    
将窗口最小化。适用于支持窗口最小化操作的窗口。  
 **调用形式：**     
    
- minimize(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
| 17000005 | if the action is not supported on this window. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    await window.minimize();  
}  
    
```    
  
    
### resume<sup>(9+)</sup>    
将窗口恢复到之前的窗口模式。  
 **调用形式：**     
    
- resume(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
| 17000005 | if the action is not supported on this window. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    await window.resume();  
}  
    
```    
  
    
### close<sup>(9+)</sup>    
将窗口关闭。  
 **调用形式：**     
    
- close(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17000002 | if the async function was not called with await. |  
| 17000004 | if the component is invisible or destroyed. |  
| 17000005 | if the action is not supported on this window. |  
    
 **示例代码：**   
```ts    
import { Driver } from '@ohos.UiTest';  
async function demo() {  
    let driver = Driver.create();  
    let window = await driver.findWindow({actived: true});  
    await window.close();  
}  
    
```    
  
    
## PointerMatrix<sup>(9+)</sup>    
存储多指操作中每根手指每一步动作的坐标点及其行为的二维数组。  
 **系统能力:**  SystemCapability.Test.UiTest    
### create<sup>(9+)</sup>    
静态方法，构造一个PointerMatrix对象，并返回该对象。  
 **调用形式：**     
- static create(fingers: number, steps: number): PointerMatrix  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fingers | number | true | 多指操作中注入的手指数，取值范围：[1,10]。 |  
| steps | number | true | 每根手指操作的步骤数，取值范围：[1,1000]。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PointerMatrix | 返回构造的PointerMatrix对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { PointerMatrix } from '@ohos.UiTest';  
async function demo() {  
    let pointerMatrix = PointerMatrix.create(2,3);  
}  
    
```    
  
    
### setPoint<sup>(9+)</sup>    
设置PointerMatrix对象中指定手指和步骤对应动作的坐标点。  
 **调用形式：**     
- setPoint(finger: number, step: number, point: Point): void  
  
 **系统能力:**  SystemCapability.Test.UiTest    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| finger | number | true | 手指的序号。 |  
| step | number | true | 步骤的序号。 |  
| point | Point | true | 该行为的坐标点。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { PointerMatrix } from '@ohos.UiTest';  
async function demo() {  
    let pointers = PointerMatrix.create(2,3);  
    pointers.setPoint(0,0,{x:230,y:480});  
    pointers.setPoint(0,1,{x:250,y:380});  
    pointers.setPoint(0,2,{x:270,y:280});  
    pointers.setPoint(1,0,{x:230,y:680});  
    pointers.setPoint(1,1,{x:240,y:580});  
    pointers.setPoint(1,2,{x:250,y:480});  
}  
    
```    
  
