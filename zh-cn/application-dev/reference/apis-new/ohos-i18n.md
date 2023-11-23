# @ohos.i18n    
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import i18n from '@ohos.i18n'    
```  
    
## getDisplayCountry<sup>(deprecated)</sup>    
获取指定国家的本地化显示文本。  
 **调用形式：**     
- getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.System.getDisplayCountry。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| country<sup>(deprecated)</sup> | string | true | 指定国家。 |  
| locale<sup>(deprecated)</sup> | string | true | 显示指定国家的区域ID。 |  
| sentenceCase<sup>(deprecated)</sup> | boolean | false | 本地化显示文本是否要首字母大写。默认值：true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 指定国家的本地化显示文本 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let displayCountry: string = I18n.System.getDisplayCountry("zh-CN", "en-GB"); // displayCountry = "China"  
} catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error(`call System.getDisplayCountry failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
## getDisplayLanguage<sup>(deprecated)</sup>    
获取指定语言的本地化显示文本。  
 **调用形式：**     
- getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.System.getDisplayLanguage。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| language<sup>(deprecated)</sup> | string | true | 指定语言。 |  
| locale<sup>(deprecated)</sup> | string | true | 显示指定语言的区域ID。 |  
| sentenceCase<sup>(deprecated)</sup> | boolean | false | 本地化显示文本是否要首字母大写。默认值：true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 指定语言的本地化显示文本 |  
    
 **示例代码：**   
```ts    
let languageName: string = I18n.getDisplayLanguage("zh", "en-GB", true); // languageName = "Chinese"  
languageName = I18n.getDisplayLanguage("zh", "en-GB"); // languageName = "Chinese"    
```    
  
    
## getSystemLanguage<sup>(deprecated)</sup>    
获取系统支持的语言列表。语言的详细说明参见[实例化Locale对象]。  
 **调用形式：**     
- getSystemLanguage(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.System.getSystemLanguage。  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 系统支持的语言ID列表。 |  
    
 **示例代码：**   
```ts    
let systemLanguage: string = I18n.getSystemLanguage(); // 返回当前系统语言    
```    
  
    
## getSystemRegion<sup>(deprecated)</sup>    
获取系统地区。地区的详细说明参见[实例化Locale对象]。  
 **调用形式：**     
- getSystemRegion(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.System.getSystemRegion。  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 系统地区ID。 |  
    
## getSystemLocale<sup>(deprecated)</sup>    
获取系统区域。区域的详细说明参见[实例化Locale对象]。  
 **调用形式：**     
- getSystemLocale(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.System.getSystemLocale。  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 系统区域ID。 |  
    
 **示例代码：**   
```null    
let locale: string = I18n.getSystemLocale(); // 返回系统Locale    
```    
  
    
## System<sup>(9+)</sup>    
获取指定国家的本地化显示文本  
  
 **系统能力:**  SystemCapability.Global.I18n    
### getDisplayCountry<sup>(9+)</sup>    
获取指定国家的本地化显示文本。  
 **调用形式：**     
- static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| country | string | true | 指定国家。 |  
| locale | string | true | 显示指定国家的区域ID。 |  
| sentenceCase | boolean | false | 本地化显示文本是否要首字母大写。默认值：true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 指定国家的本地化显示文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
### getDisplayLanguage<sup>(9+)</sup>    
获取指定语言的本地化显示文本。  
 **调用形式：**     
- static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| language | string | true | 指定语言。 |  
| locale | string | true | 显示指定语言的区域ID。 |  
| sentenceCase | boolean | false | 本地化显示文本是否要首字母大写。默认值：true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 指定语言的本地化显示文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
### getSystemLanguages<sup>(9+)</sup>    
获取系统支持的语言列表。语言的详细说明参见[实例化Locale对象]  
 **调用形式：**     
- static getSystemLanguages(): Array\<string>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 系统支持的语言ID列表。 |  
    
### getSystemCountries<sup>(9+)</sup>    
获取针对输入语言系统支持的国家或地区列表。国家或地区的详细说明参见[实例化Locale对象]  
 **调用形式：**     
- static getSystemCountries(language: string): Array\<string>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| language | string | true | 语言ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 系统支持的区域ID列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
### isSuggested<sup>(9+)</sup>    
判断当前语言和地区是否匹配。  
 **调用形式：**     
- static isSuggested(language: string, region?: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| language | string | true | 合法的语言ID，例如zh |  
| region | string | false | 合法的地区ID，例如CN。默认值：使用SIM卡国家或地区。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true，表示当前语言和地区匹配；返回false，表示当前语言和地区不匹配。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
### getSystemLanguage<sup>(9+)</sup>    
获取系统支持的语言列表。语言的详细说明参见[实例化Locale对象]。  
 **调用形式：**     
- static getSystemLanguage(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 系统支持的语言ID列表。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let systemLanguage: string = I18n.System.getSystemLanguage();  // systemLanguage为当前系统语言  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.getSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### getSystemRegion<sup>(9+)</sup>    
获取系统地区。地区的详细说明参见[实例化Locale对象](../../internationalization/intl-guidelines.md#开发步骤)。  
 **调用形式：**     
- static getSystemRegion(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 系统地区ID。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let systemRegion: string = I18n.System.getSystemRegion(); // 获取系统当前地区设置  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.getSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### getSystemLocale<sup>(9+)</sup>    
获取系统区域。区域的详细说明参见[实例化Locale对象](../../internationalization/intl-guidelines.md#开发步骤)。  
 **调用形式：**     
- static getSystemLocale(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 系统区域ID。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let systemLocale: string = I18n.System.getSystemLocale();  // 获取系统当前Locale  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.getSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### is24HourClock<sup>(9+)</sup>    
判断系统时间是否为24小时制。  
 **调用形式：**     
- static is24HourClock(): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true，表示系统24小时开关开启；返回false，表示系统24小时开关关闭。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let is24HourClock: boolean = I18n.System.is24HourClock();  // 系统24小时开关是否开启  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.is24HourClock failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### getPreferredLanguageList<sup>(9+)</sup>    
获取系统偏好语言列表。  
 **调用形式：**     
- static getPreferredLanguageList(): Array\<string>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 系统偏好语言列表。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let preferredLanguageList: Array<string> = I18n.System.getPreferredLanguageList(); // 获取系统当前偏好语言列表  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.getPreferredLanguageList failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### getFirstPreferredLanguage<sup>(9+)</sup>    
获取系统偏好语言列表中的第一个偏好语言。  
 **调用形式：**     
- static getFirstPreferredLanguage(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 偏好语言列表中的第一个语言。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let firstPreferredLanguage: string = I18n.System.getFirstPreferredLanguage();  // 获取系统当前偏好语言列表中的第一个偏好语言  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.getFirstPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### setAppPreferredLanguage<sup>(11+)</sup>    
设置应用的偏好语言。  
 **调用形式：**     
- static setAppPreferredLanguage(language: string): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| language | string | true | 语言ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
  
try {  
  I18n.System.setAppPreferredLanguage('zh'); // 设置应用当前语言为 "zh"  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### getAppPreferredLanguage<sup>(9+)</sup>    
获取应用的偏好语言。  
 **调用形式：**     
- static getAppPreferredLanguage(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 应用的偏好语言。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let appPreferredLanguage: string = I18n.System.getAppPreferredLanguage(); // 获取应用偏好语言  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.getAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### getUsingLocalDigit<sup>(9+)</sup>    
判断系统是否使用本地数字。  
 **调用形式：**     
- static getUsingLocalDigit(): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true表示系统当前已打开本地数字开关，false表示系统当前未打开本地数字开关。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let status: boolean = I18n.System.getUsingLocalDigit();  // 判断本地化数字开关是否打开  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call System.getUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
## Util<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.i18n/i18n.I18NUtil替代。  
 **系统能力:**  SystemCapability.Global.I18n    
### unitConvert<sup>(deprecated)</sup>    
将fromUnit的单位转换为toUnit的单位，并根据区域与风格进行格式化。  
  
从API version 8开始支持，从API version 9开始不再维护，建议使用[unitConvert](#unitconvert9)代替。  
 **调用形式：**     
- unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.i18n/i18n.I18NUtil#unitConvert。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fromUnit<sup>(deprecated)</sup> | UnitInfo | true | 要被转换的单位。 |  
| toUnit<sup>(deprecated)</sup> | UnitInfo | true | 要转换为的单位。 |  
| value<sup>(deprecated)</sup> | number | true | 要被转换的单位的数量值。 |  
| locale<sup>(deprecated)</sup> | string | true | 格式化时使用的区域参数，如：zh-Hans-CN。 |  
| style<sup>(deprecated)</sup> | string | false | 格式化使用的风格，取值包括："long","short","narrow"。默认值：short。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 按照toUnit的单位格式化后，得到的字符串。 |  
    
## I18NUtil<sup>(9+)</sup>  
 **系统能力:**  SystemCapability.Global.I18n    
### unitConvert<sup>(9+)</sup>    
将fromUnit的单位转换为toUnit的单位，并根据区域与风格进行格式化。  
  
从API version 8开始支持，从API version 9开始不再维护，建议使用[unitConvert](#unitconvert9)代替。  
 **调用形式：**     
- static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fromUnit | UnitInfo | true | 要被转换的单位。 |  
| toUnit | UnitInfo | true | 要转换为的单位。 |  
| value | number | true | 要被转换的单位的数量值。 |  
| locale | string | true | 格式化时使用的区域参数，如：zh-Hans-CN。   |  
| style | string | false | 格式化使用的风格，取值包括："long","short","narrow"。默认值：short。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 按照toUnit的单位格式化后，得到的字符串。 |  
    
 **示例代码：**   
```ts    
let fromUnit: I18n.UnitInfo = {unit: "cup", measureSystem: "US"};  
let toUnit: I18n.UnitInfo = {unit: "liter", measureSystem: "SI"};  
let res: string = I18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, "en-US", "long"); // res = 236.588 liters    
```    
  
    
### getDateOrder<sup>(9+)</sup>    
获取该区域日期中年、月、日的排列顺序。  
 **调用形式：**     
- static getDateOrder(locale: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locale | string | true | 格式化时使用的区域参数，如：zh-Hans-CN。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回该区域年、月、日的排列顺序。 |  
    
 **示例代码：**   
```ts    
let order: string = I18n.I18NUtil.getDateOrder("zh-CN");  // order = "y-L-d"    
```    
  
    
### getTimePeriodName<sup>(11+)</sup>    
获取该区域指定时间的本地化表达。  
 **调用形式：**     
- static getTimePeriodName(hour:number, locale?: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hour | number | true | 指定的时间，如：16。 |  
| locale | string | false | 指定区域的参数，默认采用当前APP的区域，如：zh-Hans-CN。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回该区域指定时间的本地化表达。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let name: string = I18n.I18NUtil.getTimePeriodName(2, "zh-CN");  // name = "凌晨"  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call I18NUtil.getTimePeriodName failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
## UnitInfo<sup>(8+)</sup>    
度量衡单位信息。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| unit<sup>(8+)</sup> | string | false | true | 单位的名称，如："meter","inch","cup"等。 |  
| measureSystem<sup>(8+)</sup> | string | false | true | 单位的度量体系，取值包括："SI","US","UK"。 |  
    
## PhoneNumberFormatOptions<sup>(8+)</sup>    
表示电话号码格式化对象可设置的属性。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(8+)</sup> | string | false | true | 表示对电话号码格式化的类型，取值范围："E164","INTERNATIONAL","NATIONAL","RFC3966"。<br>-在API version 8版本，type为必填项。 <br>-API version 9版本开始，type为选填项。 |  
| type<sup>(9+)</sup> | string | false | false | 表示对电话号码格式化的类型，取值范围："E164","INTERNATIONAL","NATIONAL","RFC3966"。<br>-在API version 8版本，type为必填项。 <br>-API version 9版本开始，type为选填项。 |  
    
## PhoneNumberFormat<sup>(8+)</sup>  
 **系统能力:**  SystemCapability.Global.I18n    
### isValidNumber<sup>(8+)</sup>    
判断传入的电话号码格式是否正确。  
 **调用形式：**     
- isValidNumber(number: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| number | string | true | 待判断的电话号码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示电话号码的格式正确，返回false表示电话号码的格式错误。 |  
    
 **示例代码：**   
```ts    
let phonenumberfmt: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN");  
let isValidNumber: boolean = phonenumberfmt.isValidNumber("158****2312"); // isValidNumber = true    
```    
  
    
### format<sup>(8+)</sup>    
对电话号码进行格式化。  
 **调用形式：**     
- format(number: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| number | string | true | 待格式化的电话号码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 格式化后的电话号码。 |  
    
 **示例代码：**   
```ts    
let phonenumberfmt: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN");  
let formattedPhoneNumber: string = phonenumberfmt.format("158****2312"); // formattedPhoneNumber = "158 **** 2312"    
```    
  
    
### getLocationName<sup>(9+)</sup>    
获取电话号码归属地。  
 **调用形式：**     
- getLocationName(number: string, locale: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| number | string | true |  电话号码 |  
| locale | string | true | 区域ID |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 电话号码归属地。 |  
    
 **示例代码：**   
```ts    
let phonenumberfmt: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN");  
let locationName: string = phonenumberfmt.getLocationName("158****2345", "zh-CN"); // locationName = "广东省湛江市"    
```    
  
    
## getCalendar<sup>(8+)</sup>    
获取日历对象。  
 **调用形式：**     
- getCalendar(locale: string, type?: string): Calendar  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locale | string | true | 合法的locale值，例如zh-Hans-CN。 |  
| type | string | false | 合法的日历类型，目前合法的类型有buddhist,chinese,coptic,ethiopic,hebrew,gregory,indian,islamic_civil,islamic_tbla,islamic_umalqura,japanese,persian。默认值：区域默认的日历类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Calendar | 日历对象。 |  
    
 **示例代码：**   
```ts    
I18n.getCalendar("zh-Hans", "chinese"); // 获取中国农历日历对象    
```    
  
    
## Calendar    
### setTime<sup>(8+)</sup>    
设置日历对象内部的时间日期。  
 **调用形式：**     
- setTime(date: Date): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date | Date | true | 将要设置的日历对象的内部时间日期。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("en-US", "gregory");  
let date: Date = new Date(2021, 10, 7, 8, 0, 0, 0);  
calendar.setTime(date);    
```    
  
    
### setTime<sup>(10+)</sup>    
设置日历对象内部的时间日期。  
 **调用形式：**     
- setTime(date: Date): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date | Date | true | 将要设置的日历对象的内部时间日期。  |  
    
### setTime<sup>(8+)</sup>    
将要设置的日历对象的内部时间日期。  
 **调用形式：**     
- setTime(time: number): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| time | number | true | time为从1970.1.100:00:00GMT逝去的毫秒数。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("en-US", "gregory");  
calendar.setTime(10540800000);    
```    
  
    
### setTime<sup>(10+)</sup>    
将要设置的日历对象的内部时间日期。  
 **调用形式：**     
- setTime(time: number): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| time | number | true | time为从1970.1.100:00:00GMT逝去的毫秒数。 |  
    
### set<sup>(8+)</sup>    
将要设置的日历对象的内部时间日期。  
 **调用形式：**     
- set(year: number, month: number, date: number, hour?: number, minute?: number, second?: number): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| year | number | true | 设置的年。 |  
| month | number | true | 设置的月。 |  
| date | number | true | 设置的日。 |  
| hour | number | false | 设置的小时。默认值：系统小时。 |  
| minute | number | false | 设置的分钟。默认值：系统分钟。 |  
| second | number | false | 设置的秒。默认值：系统秒。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00    
```    
  
    
### set<sup>(10+)</sup>  
 **调用形式：**     
- set(year: number, month: number, date: number, hour?: number, minute?: number, second?: number): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| year | number | true | 设置的年。 |  
| month | number | true | 设置的月。 |  
| date | number | true | 设置的日。 |  
| hour | number | false | 设置的小时。默认值：系统小时。 |  
| minute | number | false | 设置的分钟。默认值：系统分钟。 |  
| second | number | false | 设置的秒。默认值：系统秒。 |  
    
### setTimeZone<sup>(8+)</sup>    
设置日历对象的时区。  
 **调用形式：**     
- setTimeZone(timezone: string): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timezone | string | true | 设置的时区id，如“Asia/Shanghai”。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
calendar.setTimeZone("Asia/Shanghai");    
```    
  
    
### setTimeZone<sup>(10+)</sup>    
设置日历对象的时区。  
 **调用形式：**     
- setTimeZone(timezone: string): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timezone | string | true | 设置的时区id，如“Asia/Shanghai”。 |  
    
### getTimeZone<sup>(8+)</sup>    
获取日历对象的时区。  
 **调用形式：**     
- getTimeZone(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 日历对象的时区id。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
calendar.setTimeZone("Asia/Shanghai");  
let timezone: string = calendar.getTimeZone(); // timezone = "Asia/Shanghai"    
```    
  
    
### getTimeZone<sup>(10+)</sup>    
获取日历对象的时区。  
 **调用形式：**     
- getTimeZone(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 日历对象的时区id。 |  
    
### getFirstDayOfWeek<sup>(8+)</sup>    
获取日历对象的一周起始日。  
 **调用形式：**     
- getFirstDayOfWeek(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取一周的起始日，1代表周日，7代表周六。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("en-US", "gregory");  
let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1    
```    
  
    
### getFirstDayOfWeek<sup>(10+)</sup>    
获取日历对象的一周起始日。  
 **调用形式：**     
- getFirstDayOfWeek(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取一周的起始日，1代表周日，7代表周六。 |  
    
### setFirstDayOfWeek<sup>(8+)</sup>    
获取日历对象的一周起始日。  
 **调用形式：**     
- setFirstDayOfWeek(value: number): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 获取一周的起始日，1代表周日，7代表周六。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
calendar.setFirstDayOfWeek(3);  
let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 3    
```    
  
    
### setFirstDayOfWeek<sup>(10+)</sup>    
获取日历对象的一周起始日。  
 **调用形式：**     
- setFirstDayOfWeek(value: number): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 获取一周的起始日，1代表周日，7代表周六。 |  
    
### getMinimalDaysInFirstWeek<sup>(8+)</sup>    
获取一年中第一周的最小天数。  
 **调用形式：**     
- getMinimalDaysInFirstWeek(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 一年中第一周的最小天数。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 1    
```    
  
    
### getMinimalDaysInFirstWeek<sup>(10+)</sup>    
获取一年中第一周的最小天数。  
 **调用形式：**     
- getMinimalDaysInFirstWeek(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 一年中第一周的最小天数。 |  
    
### setMinimalDaysInFirstWeek<sup>(8+)</sup>    
设置一年中第一周的最小天数。  
 **调用形式：**     
- setMinimalDaysInFirstWeek(value: number): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 一年中第一周的最小天数。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
calendar.setMinimalDaysInFirstWeek(3);  
let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 3    
```    
  
    
### setMinimalDaysInFirstWeek<sup>(10+)</sup>    
设置一年中第一周的最小天数。  
 **调用形式：**     
- setMinimalDaysInFirstWeek(value: number): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 一年中第一周的最小天数。 |  
    
### get<sup>(8+)</sup>    
获取日历对象中与field相关联的值。  
 **调用形式：**     
- get(field: string): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 通过field来获取日历对象相应的值。目前支持的field值有era,year,month,week_of_year,week_of_month,date,day_of_year,day_of_week,day_of_week_in_month,hour,hour_of_day,minute,second,millisecond,zone_offset,dst_offset,year_woy,dow_local,extended_year,julian_day,milliseconds_in_day,is_leap_month。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 与field相关联的值，如当前Calendar对象的内部日期的年份为1990，get("year")返回1990。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00  
let hourOfDay: number = calendar.get("hour_of_day"); // hourOfDay = 8    
```    
  
    
### get<sup>(10+)</sup>    
获取日历对象中与field相关联的值。  
 **调用形式：**     
- get(field: string): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 通过field来获取日历对象相应的值。目前支持的field值有era,year,month,week_of_year,week_of_month,date,day_of_year,day_of_week,day_of_week_in_month,hour,hour_of_day,minute,second,millisecond,zone_offset,dst_offset,year_woy,dow_local,extended_year,julian_day,milliseconds_in_day,is_leap_month。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 与field相关联的值，如当前Calendar对象的内部日期的年份为1990，get("year")返回1990。 |  
    
### getDisplayName<sup>(8+)</sup>    
获取日历对象在该区域的名字。  
 **调用形式：**     
- getDisplayName(locale: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locale | string | true | locale用于指定区域，如buddhist在en-US上显示的名称为“BuddhistCalendar”。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 日历在locale所指示的区域的名字。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("en-US", "buddhist");  
let calendarName: string = calendar.getDisplayName("zh"); // calendarName = "佛历"    
```    
  
    
### isWeekend<sup>(8+)</sup>    
判断指定的日期在日历中是否为周末。  
 **调用形式：**     
- isWeekend(date?: Date): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date | Date | false | 指定的日期。若不填，则判断当前日期是否为周末。默认值：系统日期。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 若判断指定日期为周末时，返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.11.11 08:00:00  
calendar.isWeekend(); // false  
let date: Date = new Date(2011, 11, 6, 9, 0, 0);  
calendar.isWeekend(date); // true    
```    
  
    
### isWeekend<sup>(10+)</sup>    
判断指定的日期在日历中是否为周末。  
 **调用形式：**     
- isWeekend(date?: Date): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date | Date | false | 指定的日期。若不填，则判断当前日期是否为周末。默认值：系统日期。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 若判断指定日期为周末时，返回true，否则返回false。 |  
    
### add<sup>(11+)</sup>    
在日历的给定字段进行加减操作。  
 **调用形式：**     
- add(field: string, amount: number): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 指定进行操作的日历字段，目前支持的field值有year,month,week_of_year,week_of_month,date,day_of_year,day_of_week,day_of_week_in_month,hour,hour_of_day,minute,second,millisecond。 |  
| amount | number | 是    | 进行加减操作的具体数值。 |  
| amount | number | true | 进行加减操作的具体数值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
  calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.11.11 08:00:00  
  calendar.add("year", 8); // 2021 + 8  
  let year: number = calendar.get("year"); // year = 2029  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call Calendar.add failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
### getTimeInMillis<sup>(11+)</sup>    
获取当前日历的UTC毫秒数。  
 **调用形式：**     
- getTimeInMillis(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 当前日历的UTC毫秒数。 |  
    
 **示例代码：**   
```ts    
let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
calendar.setTime(5000);  
let millisecond: number = calendar.getTimeInMillis(); // millisecond = 5000    
```    
  
    
### compareDays<sup>(11+)</sup>    
比较日历和指定日期相差的天数（按毫秒级的精度，不足一天将按一天进行计算）。  
 **调用形式：**     
- compareDays(date: Date): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date | Date | true | 指定的日期。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 相差的天数，正数代表日历时间更早，负数代表日历时间更晚。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");  
  calendar.setTime(5000);  
  let date: Date = new Date(6000);  
  let diff: number = calendar.compareDays(date); // diff = 1  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call Calendar.compareDays failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
## isRTL    
获取该区域是否为从右至左显示语言。  
 **调用形式：**     
- isRTL(locale: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locale | string | true | 指定区域ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true表示该locale从右至左显示语言；false表示该locale从左至右显示语言。 |  
    
 **示例代码：**   
```ts    
I18n.isRTL("zh-CN");// 中文不是RTL语言，返回false  
I18n.isRTL("ar-EG");// 阿语是RTL语言，返回true    
```    
  
    
## getLineInstance<sup>(8+)</sup>    
获取一个用于断句的[BreakIterator](#breakiterator8)对象。  
 **调用形式：**     
- getLineInstance(locale: string): BreakIterator  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locale | string | true | 合法的locale值，例如zh-Hans-CN。生成的[BreakIterator](#breakiterator8)将按照locale所指定的区域的规则来进行断句。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BreakIterator | 用于进行断句的处理器。 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");    
```    
  
    
## BreakIterator<sup>(8+)</sup>  
 **系统能力:**  SystemCapability.Global.I18n    
### current<sup>(8+)</sup>    
获取BreakIterator对象在当前处理的文本中的位置。  
 **调用形式：**     
- current(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | BreakIterator在当前所处理的文本中的位置。 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");  
iterator.setLineBreakText("Apple is my favorite fruit.");  
let currentPos: number = iterator.current(); // currentPos = 0    
```    
  
    
### first<sup>(8+)</sup>    
将BreakIterator对象设置到第一个可断句的分割点。第一个分割点总是被处理的文本的起始位置。  
 **调用形式：**     
- first(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 被处理文本的第一个分割点的偏移量。 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");  
iterator.setLineBreakText("Apple is my favorite fruit.");  
let firstPos: number = iterator.first(); // firstPos = 0    
```    
  
    
### last<sup>(8+)</sup>    
将BreakIterator对象的位置设置到最后一个可断句的分割点。最后一个分割点总是被处理文本末尾的下一个位置。  
 **调用形式：**     
- last(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 被处理的文本的最后一个分割点的偏移量 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");  
iterator.setLineBreakText("Apple is my favorite fruit.");  
let lastPos: number = iterator.last(); // lastPos = 27    
```    
  
    
### next<sup>(8+)</sup>    
将BreakIterator向后移动相应个分割点。  
 **调用形式：**     
- next(index?: number): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | false |  BreakIterator将要移动的分割点数。正数代表向后移动，即将BreakIterator向后移动number个可断句的分割点；负数代表向前移动，即向前移动相应个分割点。默认值：1。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回移动了index个分割点后，当前BreakIterator在文本中的位置。若移动index个分割点后超出了所处理的文本的长度范围，返回-1。 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");  
iterator.setLineBreakText("Apple is my favorite fruit.");  
let pos: number = iterator.first(); // pos = 0  
pos = iterator.next(); // pos = 6  
pos = iterator.next(10); // pos = -1    
```    
  
    
### previous<sup>(8+)</sup>    
将BreakIterator向前移动一个分割点。  
 **调用形式：**     
- previous(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回移动到前一个分割点后，当前BreakIterator在文本中的位置。若移动index个分割点后超出了所处理的文本的长度范围，返回-1。 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");  
iterator.setLineBreakText("Apple is my favorite fruit.");  
let pos: number = iterator.first(); // pos = 0  
pos = iterator.next(3); // pos = 12  
pos = iterator.previous(); // pos = 9    
```    
  
    
### setLineBreakText<sup>(8+)</sup>    
设置BreakIterator要处理的文本。  
 **调用形式：**     
- setLineBreakText(text: string): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 指定BreakIterator进行断句的文本。 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");  
iterator.setLineBreakText("Apple is my favorite fruit."); // 设置短句文本    
```    
  
    
### following<sup>(8+)</sup>    
将BreakIterator设置到指定位置的后面一个分割点。  
 **调用形式：**     
- following(offset: number): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 将BreakIterator设置到指定位置的后面一个分割点。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回BreakIterator移动后的位置，如果由offset所指定的位置的下一个分割点超出了文本的范围则返回-1。 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");  
iterator.setLineBreakText("Apple is my favorite fruit.");  
let pos: number = iterator.following(0); // pos = 6  
pos = iterator.following(100); // pos = -1  
pos = iterator.current(); // pos = 27    
```    
  
    
### getLineBreakText<sup>(8+)</sup>    
获取BreakIterator当前处理的文本。  
 **调用形式：**     
- getLineBreakText(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | BreakIterator对象正在处理的文本 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");  
iterator.setLineBreakText("Apple is my favorite fruit.");  
let breakText: string = iterator.getLineBreakText(); // breakText = "Apple is my favorite fruit."    
```    
  
    
### isBoundary<sup>(8+)</sup>    
判断文本指定位置是否为分割点。  
 **调用形式：**     
- isBoundary(offset: number): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 若offset指定的文本位置是一个分割点，则返回true，否则返回false。返回true时，将BreakIterator对象移动到offset指定的位置，否则相当于调用following。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果是一个分割点返回true,否则返回false。 |  
    
 **示例代码：**   
```ts    
let iterator: I18n.BreakIterator = I18n.getLineInstance("en");  
iterator.setLineBreakText("Apple is my favorite fruit.");  
let isBoundary: boolean = iterator.isBoundary(0); // isBoundary = true;  
isBoundary = iterator.isBoundary(5); // isBoundary = false;    
```    
  
    
## getInstance<sup>(8+)</sup>    
创建并返回IndexUtil对象。  
 **调用形式：**     
- getInstance(locale?: string): IndexUtil  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locale | string | false | 区域设置信息字符串，包括语言以及可选的脚本和区域。默认值：系统Locale。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IndexUtil | locale对应的IndexUtil对象。 |  
    
 **示例代码：**   
```ts    
let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");    
```    
  
    
## IndexUtil<sup>(8+)</sup>  
 **系统能力:**  SystemCapability.Global.I18n    
### getIndexList<sup>(8+)</sup>    
获取当前区域对应的索引列表。  
 **调用形式：**     
- getIndexList(): Array\<string>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 返回当前locale对应的索引列表。 |  
    
 **示例代码：**   
```ts    
let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");  
// indexList = [ "...", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",  
//              "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "..." ]  
let indexList: Array<string> = indexUtil.getIndexList();    
```    
  
    
### addLocale<sup>(8+)</sup>    
在当前索引列表中添加新的区域。  
 **调用形式：**     
- addLocale(locale: string): void  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locale | string | true | 区域设置信息的字符串，包括语言以及可选的脚本和区域。 |  
    
 **示例代码：**   
```ts    
let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");  
indexUtil.addLocale("en-US");    
```    
  
    
### getIndex<sup>(8+)</sup>    
获取text对应的索引。  
 **调用形式：**     
- getIndex(text: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 待计算索引值的输入文本。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 输入文本对应的索引值。 |  
    
 **示例代码：**   
```ts    
let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");  
let index: string = indexUtil.getIndex("hi");  // index = "H"<i></i>    
```    
  
    
## Character<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用Unicode替代。  
 **系统能力:**  SystemCapability.Global.I18n    
### isDigit<sup>(deprecated)</sup>    
判断字符串char是否是数字。  
 **调用形式：**     
- isDigit(char: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: Unicode.isDigit。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char<sup>(deprecated)</sup> | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是数字，返回false表示输入的字符不是数字。 |  
    
### isSpaceChar<sup>(deprecated)</sup>    
判断字符串char是否是空格符。  
 **调用形式：**     
- isSpaceChar(char: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: Unicode.isSpaceChar。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char<sup>(deprecated)</sup> | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是空格符，返回false表示输入的字符不是空格符。 |  
    
### isWhitespace<sup>(deprecated)</sup>    
判断字符串char是否是空白符。  
 **调用形式：**     
- isWhitespace(char: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: Unicode.isWhitespace。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char<sup>(deprecated)</sup> | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是空白符，返回false表示输入的字符不是空白符。 |  
    
### isRTL<sup>(deprecated)</sup>    
判断字符串char是否是从右到左语言的字符。  
 **调用形式：**     
- isRTL(char: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: Unicode.isRTL。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char<sup>(deprecated)</sup> | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是从右到左语言的字符，返回false表示输入的字符不是从右到左语言的字符。 |  
    
### isIdeograph<sup>(deprecated)</sup>    
判断字符串char是否是表意文字。  
 **调用形式：**     
- isIdeograph(char: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: Unicode.isIdeograph。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char<sup>(deprecated)</sup> | string | true |  输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是表意文字，返回false表示输入的字符不是表意文字。 |  
    
### isLetter<sup>(deprecated)</sup>    
判断字符串char是否是字母。  
 **调用形式：**     
- isLetter(char: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: Unicode.isLetter。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char<sup>(deprecated)</sup> | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是字母，返回false表示输入的字符不是字母。 |  
    
### isLowerCase<sup>(deprecated)</sup>    
判断字符串char是否是小写字母。  
 **调用形式：**     
- isLowerCase(char: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: Unicode.isLowerCase。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char<sup>(deprecated)</sup> | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是小写字母，返回false表示输入的字符不是小写字母。 |  
    
### isUpperCase<sup>(deprecated)</sup>    
判断字符串char是否是大写字母。  
 **调用形式：**     
- isUpperCase(char: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: Unicode.isUpperCase。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char<sup>(deprecated)</sup> | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是大写字母，返回false表示输入的字符不是大写字母。 |  
    
### getType<sup>(deprecated)</sup>    
获取输入字符串的一般类别值。  
 **调用形式：**     
- getType(char: string): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: Unicode.getType。  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char<sup>(deprecated)</sup> | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 输入字符的一般类别值。 |  
    
## Unicode<sup>(9+)</sup>  
 **系统能力:**  SystemCapability.Global.I18n    
### isDigit<sup>(9+)</sup>    
判断字符串char是否是数字。  
 **调用形式：**     
- static isDigit(char: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是数字，返回false表示输入的字符不是数字。 |  
    
 **示例代码：**   
```ts    
let isdigit: boolean = I18n.Unicode.isDigit("1");  // isdigit = true    
```    
  
    
### isSpaceChar<sup>(9+)</sup>    
判断字符串char是否是空格符。  
 **调用形式：**     
- static isSpaceChar(char: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是空格符，返回false表示输入的字符不是空格符。 |  
    
 **示例代码：**   
```ts    
let isspacechar: boolean = I18n.Unicode.isSpaceChar("a");  // isspacechar = false    
```    
  
    
### isWhitespace<sup>(9+)</sup>    
判断字符串char是否是空白符。  
 **调用形式：**     
- static isWhitespace(char: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是空白符，返回false表示输入的字符不是空白符。 |  
    
 **示例代码：**   
```ts    
let iswhitespace: boolean = I18n.Unicode.isWhitespace("a");  // iswhitespace = false    
```    
  
    
### isRTL<sup>(9+)</sup>    
判断字符串char是否是从右到左语言的字符。  
 **调用形式：**     
- static isRTL(char: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是从右到左语言的字符，返回false表示输入的字符不是从右到左语言的字符。 |  
    
 **示例代码：**   
```ts    
let isrtl: boolean = I18n.Unicode.isRTL("a");  // isrtl = false    
```    
  
    
### isIdeograph<sup>(9+)</sup>    
判断字符串char是否是表意文字。  
 **调用形式：**     
- static isIdeograph(char: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是表意文字，返回false表示输入的字符不是表意文字。 |  
    
 **示例代码：**   
```ts    
let isideograph: boolean = I18n.Unicode.isIdeograph("a");  // isideograph = false    
```    
  
    
### isLetter<sup>(9+)</sup>    
判断字符串char是否是字母。  
 **调用形式：**     
- static isLetter(char: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是字母，返回false表示输入的字符不是字母。 |  
    
 **示例代码：**   
```ts    
let isletter: boolean = I18n.Unicode.isLetter("a");  // isletter = true    
```    
  
    
### isLowerCase<sup>(9+)</sup>    
判断字符串char是否是小写字母。  
 **调用形式：**     
- static isLowerCase(char: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是小写字母，返回false表示输入的字符不是小写字母。 |  
    
 **示例代码：**   
```ts    
let islowercase: boolean = I18n.Unicode.isLowerCase("a");  // islowercase = true    
```    
  
    
### isUpperCase<sup>(9+)</sup>    
判断字符串char是否是大写字母。  
 **调用形式：**     
- static isUpperCase(char: string): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示输入的字符是大写字母，返回false表示输入的字符不是大写字母。 |  
    
 **示例代码：**   
```ts    
let isuppercase: boolean = I18n.Unicode.isUpperCase("a");  // isuppercase = false    
```    
  
    
### getType<sup>(9+)</sup>    
获取输入字符串的一般类别值。  
 **调用形式：**     
- static getType(char: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| char | string | true | 输入字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 输入字符的一般类别值。 |  
    
 **示例代码：**   
```ts    
let type: string = I18n.Unicode.getType("a"); // type = "U_LOWERCASE_LETTER"    
```    
  
    
## is24HourClock<sup>(deprecated)</sup>    
判断系统时间是否为24小时制。  
 **调用形式：**     
- is24HourClock(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.i18n/i18n.System#is24HourClock。  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true，表示系统24小时开关开启；返回false，表示系统24小时开关关闭。 |  
    
 **示例代码：**   
```ts    
let is24HourClock: boolean = I18n.is24HourClock();    
```    
  
    
## set24HourClock<sup>(deprecated)</sup>    
设置系统时间为24小时。  
 **调用形式：**     
- set24HourClock(option: boolean): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.i18n/i18n.System#set24HourClock。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option<sup>(deprecated)</sup> | boolean | true | option为true，表示开启系统24小时制开关；返回false，表示关闭系统24小时开关。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | option为true，表示开启系统24小时制开关；返回false，表示关闭系统24小时开关。 |  
    
 **示例代码：**   
```ts    
// 将系统时间设置为24小时制  
let success: boolean = I18n.set24HourClock(true);    
```    
  
    
## addPreferredLanguage<sup>(deprecated)</sup>    
在系统偏好语言列表中的指定位置添加偏好语言。  
 **调用形式：**     
- addPreferredLanguage(language: string, index?: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.i18n/i18n.System#addPreferredLanguage。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| language<sup>(deprecated)</sup> | string | true | 待添加的偏好语言。 |  
| index<sup>(deprecated)</sup> | number | false | 偏好语言的添加位置。默认值：系统偏好语言列表长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
 **示例代码：**   
```null    
// 将语言zh-CN添加到系统偏好语言列表中  
let language: string = 'zh-CN';  
let index: number = 0;  
let success: boolean = I18n.addPreferredLanguage(language, index);    
```    
  
    
## removePreferredLanguage<sup>(deprecated)</sup>    
删除系统偏好语言列表中指定位置的偏好语言。  
 **调用形式：**     
- removePreferredLanguage(index: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.i18n/i18n.System#removePreferredLanguage。  
 **系统能力:**  SystemCapability.Global.I18n  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | true | 待删除偏好语言在系统偏好语言列表中的位置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
 **示例代码：**   
```ts    
// 删除系统偏好语言列表中的第一个偏好语言  
let index: number = 0;  
let success: boolean = I18n.removePreferredLanguage(index);    
```    
  
    
## getPreferredLanguageList<sup>(deprecated)</sup>    
获取系统偏好语言列表。  
 **调用形式：**     
- getPreferredLanguageList(): Array\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.i18n/i18n.System#getPreferredLanguageList。  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 系统偏好语言列表。 |  
    
 **示例代码：**   
```ts    
let preferredLanguageList: Array<string> = I18n.getPreferredLanguageList(); // 获取系统偏好语言列表    
```    
  
    
## getFirstPreferredLanguage<sup>(deprecated)</sup>    
获取系统偏好语言列表中的第一个偏好语言。  
 **调用形式：**     
- getFirstPreferredLanguage(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.i18n/i18n.System#getFirstPreferredLanguage。  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 偏好语言列表中的第一个语言。 |  
    
 **示例代码：**   
```ts    
let firstPreferredLanguage: string = I18n.getFirstPreferredLanguage();    
```    
  
    
## getTimeZone    
获取时区ID对应的时区对象。  
 **调用形式：**     
- getTimeZone(zoneID?: string): TimeZone  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| zoneID | string | false | 时区ID。默认值：系统时区。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| TimeZone | 时区ID对应的时区对象。 |  
    
 **示例代码：**   
```ts    
let timezone: I18n.TimeZone = I18n.getTimeZone();    
```    
  
    
## TimeZone  
 **系统能力:**  SystemCapability.Global.I18n    
### getID    
获取时区对象的ID。  
 **调用形式：**     
- getID(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 时区对象对应的时区ID。 |  
    
 **示例代码：**   
```ts    
let timezone: I18n.TimeZone = I18n.getTimeZone();  
let timezoneID: string = timezone.getID(); // timezoneID = "Asia/Shanghai"    
```    
  
    
### getDisplayName    
获取时区对象的本地化表示。  
 **调用形式：**     
- getDisplayName(locale?: string, isDST?: boolean): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locale | string | false | 区域ID。默认值：系统Locale。   |  
| isDST | boolean | false | 时区对象本地化表示时是否考虑夏令时。默认值：false。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 时区对象在指定区域的表示。 |  
    
 **示例代码：**   
```ts    
let timezone: I18n.TimeZone = I18n.getTimeZone();  
let timezoneName: string = timezone.getDisplayName("zh-CN", false); // timezoneName = "中国标准时间"    
```    
  
    
### getRawOffset    
获取时区对象表示的时区与UTC时区的偏差。  
 **调用形式：**     
- getRawOffset(): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 时区对象表示的时区与UTC时区的偏差。 |  
    
 **示例代码：**   
```ts    
let timezone: I18n.TimeZone = I18n.getTimeZone();  
let offset: number = timezone.getRawOffset(); // offset = 28800000    
```    
  
    
### getOffset    
获取某一时刻时区对象表示的时区与UTC时区的偏差。  
 **调用形式：**     
- getOffset(date?: number): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date | number | false | 待计算偏差的时刻 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 某一时刻时区对象表示的时区与UTC时区的偏差。默认值：系统时间。 |  
    
 **示例代码：**   
```ts    
let timezone: I18n.TimeZone = I18n.getTimeZone();  
let offset: number = timezone.getOffset(1234567890); // offset = 28800000    
```    
  
    
### getAvailableIDs<sup>(9+)</sup>    
获取系统支持的时区ID。  
 **调用形式：**     
- static getAvailableIDs(): Array\<string>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 系统支持的时区ID列表 |  
    
 **示例代码：**   
```ts    
// ids = ["America/Adak", "America/Anchorage", "America/Bogota", "America/Denver", "America/Los_Angeles", "America/Montevideo", "America/Santiago", "America/Sao_Paulo", "Asia/Ashgabat", "Asia/Hovd", "Asia/Jerusalem", "Asia/Magadan", "Asia/Omsk", "Asia/Shanghai", "Asia/Tokyo", "Asia/Yerevan", "Atlantic/Cape_Verde", "Australia/Lord_Howe", "Europe/Dublin", "Europe/London", "Europe/Moscow", "Pacific/Auckland", "Pacific/Easter", "Pacific/Pago-Pago"], 当前共支持24个时区  
let ids: Array<string> = I18n.TimeZone.getAvailableIDs();    
```    
  
    
### getAvailableZoneCityIDs<sup>(9+)</sup>    
获取系统支持的时区城市ID。  
 **调用形式：**     
- static getAvailableZoneCityIDs(): Array\<string>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 系统支持的时区城市ID列表 |  
    
 **示例代码：**   
```ts    
// cityIDs = ["Auckland", "Magadan", "Lord Howe Island", "Tokyo", "Shanghai", "Hovd", "Omsk", "Ashgabat", "Yerevan", "Moscow", "Tel Aviv", "Dublin", "London", "Praia", "Montevideo", "Brasília", "Santiago", "Bogotá", "Easter Island", "Salt Lake City", "Los Angeles", "Anchorage", "Adak", "Pago Pago"]，当前共支持24个时区城市  
let cityIDs: Array<string> = I18n.TimeZone.getAvailableZoneCityIDs();    
```    
  
    
### getCityDisplayName<sup>(9+)</sup>    
获取某时区城市在该区域的本地化显示。  
 **调用形式：**     
- static getCityDisplayName(cityID: string, locale: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| cityID | string | true |  时区城市ID |  
| locale | string | true | 区域ID  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 时区城市在locale下的本地化显示 |  
    
 **示例代码：**   
```ts    
let displayName: string = I18n.TimeZone.getCityDisplayName("Shanghai", "zh-CN"); // displayName = "上海(中国)"    
```    
  
    
### getTimezoneFromCity<sup>(9+)</sup>    
创建某时区城市对应的时区对象。  
 **调用形式：**     
- static getTimezoneFromCity(cityID: string): TimeZone  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| cityID | string | true | 时区城市ID  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| TimeZone | 时区城市对应的时区对象 |  
    
 **示例代码：**   
```ts    
let timezone: I18n.TimeZone = I18n.TimeZone.getTimezoneFromCity("Shanghai");    
```    
  
    
### getTimezonesByLocation<sup>(10+)</sup>    
创建某经纬度对应的时区对象数组。  
 **调用形式：**     
- static getTimezonesByLocation(longitude: number, latitude: number): Array\<TimeZone>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| longitude | number | true | 经度, 范围[-180, 179.9), 东经取正值, 西经取负值 |  
| latitude | number | true | 纬度, 范围[-90, 89.9), 北纬取正值, 南纬取负值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<TimeZone> | 时区对象的数组 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
```ts    
let timezoneArray: Array<I18n.TimeZone> = I18n.TimeZone.getTimezonesByLocation(-118.1, 34.0);  
for (let i = 0; i < timezoneArray.length; i++) {  
    let tzId: string = timezoneArray[i].getID();  
}    
```    
  
    
## Transliterator<sup>(9+)</sup>    
获取音译支持的ID列表。  
 **系统能力:**  SystemCapability.Global.I18n    
### getAvailableIDs<sup>(9+)</sup>    
获取系统支持的时区ID。  
 **调用形式：**     
- static getAvailableIDs(): string[]  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string[] | 系统支持的时区ID列表 |  
    
 **示例代码：**   
```ts    
// ids共支持671个。每一个id由使用中划线分割的两部分组成，格式为 source-destination。例如ids = ["Han-Latin","Latin-ASCII", "Amharic-Latin/BGN","Accents-Any", ...]，Han-Latin表示汉语转为译拉丁文，Amharic-Latin表示阿姆哈拉语转为拉丁文。  
// 更多使用信息可以参考ISO-15924。  
let ids: string[] = I18n.Transliterator.getAvailableIDs();    
```    
  
    
### getInstance<sup>(9+)</sup>    
创建音译对象。  
 **调用形式：**     
- static getInstance(id: string): Transliterator  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | string | true | 音译支持的ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Transliterator | 音译对象。 |  
    
 **示例代码：**   
```ts    
let transliterator: I18n.Transliterator = I18n.Transliterator.getInstance("Any-Latn");    
```    
  
    
### transform<sup>(9+)</sup>    
将输入字符串从源格式转换为目标格式。  
 **调用形式：**     
- transform(text: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 输入字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 转换后的字符串。 |  
    
 **示例代码：**   
```ts    
let transliterator: I18n.Transliterator = I18n.Transliterator.getInstance("Any-Latn");  
let res: string = transliterator.transform("中国"); // res = "zhōng guó"    
```    
  
    
## NormalizerMode<sup>(10+)</sup>    
表示文本正则化范式的枚举。    
    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NFC | 1 | NFC范式。 |  
| NFD | 2 | NFD范式。 |  
| NFKC | 3 | NFKC范式。 |  
| NFKD | 4 | NFKD范式。 |  
    
## Normalizer<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.Global.I18n    
### getInstance<sup>(10+)</sup>    
获取文本正则化对象。  
 **调用形式：**     
- static getInstance(mode: NormalizerMode): Normalizer  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | NormalizerMode | true | 文本正则化范式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Normalizer | 返回指定范式的文本正则化对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let normalizer: I18n.Normalizer = I18n.Normalizer.getInstance(I18n.NormalizerMode.NFC);    
```    
  
    
### normalize<sup>(10+)</sup>    
对字符串进行正则化。  
 **调用形式：**     
- normalize(text: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 待正则化的字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 正则化后的字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let normalizer: I18n.Normalizer = I18n.Normalizer.getInstance(I18n.NormalizerMode.NFC);  
let normalizedText: string = normalizer.normalize('\u1E9B\u0323'); // normalizedText = \u1E9B\u0323    
```    
  
    
## HolidayInfoItem<sup>(11+)</sup>    
节假日信息。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| baseName<sup>(11+)</sup> | string | false | true | 节假日的英文名称。 |  
| year<sup>(11+)</sup> | number | false | true | 节假日所在年。 |  
| month<sup>(11+)</sup> | number | false | true | 节假日所在月。 |  
| day<sup>(11+)</sup> | number | false | true | 节假日所在日。 |  
| localNames<sup>(11+)</sup> | Array<HolidayLocalName> | false | false | 节假日的本地名称列表。 |  
    
## HolidayLocalName<sup>(11+)</sup>    
节假日本地名称。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| language<sup>(11+)</sup> | string | false | true | 节假日的本地语言，例如ar,en,tr。 |  
| name<sup>(11+)</sup> | string | false | true | 节假日的本地名称，例如Sacrifice Feast(宰牲节)的土耳其语名称为Kurban Bayrami。 |  
    
## HolidayManager<sup>(11+)</sup>  
 **系统能力:**  SystemCapability.Global.I18n    
### isHoliday<sup>(11+)</sup>    
判断指定的日期是否是节假日。  
 **调用形式：**     
- isHoliday(date?: Date): boolean  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date | Date | false | JavaScript的Date对象。<br>如果没有指定日期，默认为当天 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true是节假日，返回false不是节假日。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let holidayManager= new I18n.HolidayManager("/system/lib/US.ics");  
  let isHoliday = holidayManager.isHoliday();  
  console.log(isHoliday.toString());  
  let isHoliday2 = holidayManager.isHoliday(new Date(2023,5,25));  
  console.log(isHoliday2.toString());  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call holidayManager.isHoliday failed, error code: ${err.code}, message: ${err.message}.`);  
}    
```    
  
    
### getHolidayInfoItemArray<sup>(11+)</sup>    
获取指定某年的节假日信息列表。  
 **调用形式：**     
- getHolidayInfoItemArray(year?: number): Array\<HolidayInfoItem>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| year | number | false | 年，例如2023。<br>如果没有指定年，默认为当年。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<HolidayInfoItem> | 返回节假日信息列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 890001 | param value not valid |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let holidayManager= new I18n.HolidayManager("/system/lib/US.ics");  
  let holidayInfoItemArray = holidayManager.getHolidayInfoItemArray(2023);  
  for (let i =0 ;i < holidayInfoItemArray.length; i++) {  
      console.log(JSON.stringify(holidayInfoItemArray[i]));  
  }  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.error(`call holidayManager.getHolidayInfoItemArray failed, error code: ${err.code}, message: ${err.message}.`);  
}  
    
```    
  
    
## EntityInfoItem<sup>(11+)</sup>    
实体信息对象。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| begin<sup>(11+)</sup> | number | false | true | 实体的起始位置。 |  
| end<sup>(11+)</sup> | number | false | true | 实体的终止位置。 |  
| type<sup>(11+)</sup> | string | false | true | 实体的类型，当前仅支持"phone_number"。 |  
    
## EntityRecognizer<sup>(11+)</sup>  
 **系统能力:**  SystemCapability.Global.I18n    
### findEntityInfo<sup>(11+)</sup>    
识别文本中的实体信息。  
 **调用形式：**     
- findEntityInfo(text: string): Array\<EntityInfoItem>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 用于识别实体的文本。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<EntityInfoItem> | 识别的实体对象列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let entityRecognizer: I18n.EntityRecognizer = new I18n.EntityRecognizer("zh-CN");  
let text1: string = "如有疑问，请联系158****2312";  
let result1: Array<I18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text1); // result[0].type = "phone_number", result[0].begin = 8, result[0].end = 19  
let text2: string = "我们2023年12月1日一起吃饭吧。";  
let result2: Array<I18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text2); // result[0].type = "date", result[0].begin = 2, result[0].end = 12    
```    
  
