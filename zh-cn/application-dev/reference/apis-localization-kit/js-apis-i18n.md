# @ohos.i18n (国际化-I18n)

本模块提供系统相关的或者增强的国际化能力，包括区域管理、电话号码处理、日历等，相关接口为ECMA 402标准中未定义的补充接口。[Intl模块](js-apis-intl.md)提供了ECMA 402标准定义的基础国际化接口，与本模块共同使用可提供完整地国际化支持能力。

>  **说明：**
>
>  - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 本模块接口依据[CLDR](https://cldr.unicode.org) 国际化数据库进行处理，随着CLDR演进，本模块接口处理结果可能发生变化。其中，API version 12对应[CLDR 42](https://cldr.unicode.org/index/downloads/cldr-42)，具体数据变化请参考官方链接。
>
>  - 从API version 11开始，本模块部分接口支持在ArkTS卡片中使用。


## 导入模块

```ts
import { i18n } from '@kit.LocalizationKit';
```

## System<sup>9+</sup>

### getDisplayCountry<sup>9+</sup>

static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

文本按指定国家进行本地化显示。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | 是    | 用于指定国家，要求是合法的国家码。            |
| locale       | string  | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。     |
| sentenceCase | boolean | 否    | 本地化显示文本时，首字母是否大写。默认值：true。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 按指定国家，本地化显示的文本。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

> **说明**
>
> 890001的报错信息请以接口的实际报错为准。

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
      let displayCountry: string = i18n.System.getDisplayCountry("zh-CN", "en-GB"); // displayCountry = "China"
  } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call System.getDisplayCountry failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getDisplayLanguage<sup>9+</sup>

static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

文本按指定语言进行本地化显示。例如，getDisplayLanguage("de", "zh-Hans-CN")用中文显示德文，接口输出结果为：德文。

**原子化服务API**： 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| language     | string  | 是    | 指定语言，要求是合法的语言ID。            |
| locale       | string  | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。     |
| sentenceCase | boolean | 否    | 本地化显示文本时，首字母是否大写。默认值：true。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 按指定语言，本地化显示的语言。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let displayLanguage: string = i18n.System.getDisplayLanguage("zh", "en-GB"); // 用英文形式显示中文，displayLanguage = Chinese
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getDisplayLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLanguages<sup>9+</sup>

static getSystemLanguages(): Array&lt;string&gt;

获取系统支持的语言列表。

从API version 11开始，该类型支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明           |
| ------------------- | ------------ |
| Array&lt;string&gt; | 系统支持的语言ID列表。 |

**示例：**
  ```ts
  let systemLanguages: Array<string> = i18n.System.getSystemLanguages(); // [ "ug", "bo", "zh-Hant", "en-Latn-US", "zh-Hans" ]
  ```

### getSystemCountries<sup>9+</sup>

static getSystemCountries(language: string): Array&lt;string&gt;

针对输入语言，系统支持的国家或地区列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明    |
| -------- | ------ | ---- | ----- |
| language | string | 是    | 合法的语言ID。 |

**返回值：**

| 类型                  | 说明           |
| ------------------- | ------------ |
| Array&lt;string&gt; | 系统支持某种特定语言的国家或地区列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

> **说明**
>
> 890001的报错信息请以接口的实际报错为准。

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let systemCountries: Array<string> = i18n.System.getSystemCountries('zh'); // systemCountries = [ "ZW", "YT", "YE", ..., "ER", "CN", "DE" ]
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemCountries failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### isSuggested<sup>9+</sup>

static isSuggested(language: string, region?: string): boolean

判断当前语言和地区是否匹配。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明            |
| -------- | ------ | ---- | ------------- |
| language | string | 是    | 合法的语言ID，例如zh。 |
| region   | string | 否    | 合法的地区ID，例如CN。<br>默认值：使用SIM卡国家或地区。  |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true，表示当前语言和地区匹配；<br>返回false，表示当前语言和地区不匹配。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |


> **说明**
>
> 890001的报错信息请以接口的实际报错为准。

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let res: boolean = i18n.System.isSuggested('zh', 'CN');  // res = true
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.isSuggested failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLanguage<sup>9+</sup>

static getSystemLanguage(): string

获取系统语言。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统语言ID。 |

**示例：**
  ```ts
  let systemLanguage: string = i18n.System.getSystemLanguage();  // systemLanguage为当前系统语言
  ```

### getSystemRegion<sup>9+</sup>

static getSystemRegion(): string

获取系统地区。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统地区ID。 |

**示例：**
  ```ts
  let systemRegion: string = i18n.System.getSystemRegion(); // 获取系统当前地区设置
  ```

### getSystemLocale<sup>9+</sup>

static getSystemLocale(): string

获取系统区域。

**原子化服务API**： 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 区域信息的字符串。 |

**示例：**
  ```ts
  let systemLocale: string = i18n.System.getSystemLocale();  // 获取系统当前Locale
  ```

### is24HourClock<sup>9+</sup>

static is24HourClock(): boolean

判断系统时间是否为24小时制。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true，表示系统24小时开关开启；返回false，表示系统24小时开关关闭。 |

**示例：**
  ```ts
  let is24HourClock: boolean = i18n.System.is24HourClock();  // 系统24小时开关是否开启
  ```


### getPreferredLanguageList<sup>9+</sup>

static getPreferredLanguageList(): Array&lt;string&gt;

获取系统偏好语言列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明        |
| ------------------- | --------- |
| Array&lt;string&gt; | 系统偏好语言列表。 |

**示例：**
  ```ts
  let preferredLanguageList: Array<string> = i18n.System.getPreferredLanguageList(); // 获取系统当前偏好语言列表
  ```

### getFirstPreferredLanguage<sup>9+</sup>

static getFirstPreferredLanguage(): string

获取系统偏好语言列表中的第一个偏好语言。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明             |
| ------ | -------------- |
| string | 偏好语言列表中的第一个语言。 |

**示例：**
  ```ts
  let firstPreferredLanguage: string = i18n.System.getFirstPreferredLanguage();  // 获取系统当前偏好语言列表中的第一个偏好语言
  ```

### setAppPreferredLanguage<sup>11+</sup>

static setAppPreferredLanguage(language: string): void

设置应用的偏好语言。设置偏好语言为"default"后，应用语言将跟随系统语言，应用冷启动生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明    |
| -------- | ------ | ---- | ----- |
| language | string | 是    | 合法的语言ID或"default"。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setAppPreferredLanguage('zh'); // 设置应用当前的偏好语言为 "zh"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getAppPreferredLanguage<sup>9+</sup>

static getAppPreferredLanguage(): string

获取应用的偏好语言。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明       |
| ------ | -------- |
| string | 应用的偏好语言。 |

**示例：**
  ```ts
  let appPreferredLanguage: string = i18n.System.getAppPreferredLanguage(); // 获取应用偏好语言
  ```


### getUsingLocalDigit<sup>9+</sup>

static getUsingLocalDigit(): boolean

判断系统是否使用本地数字。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | true表示本地数字开关已打开，false表示本地数字开关未打开。 |

**示例：**
  ```ts
  let status: boolean = i18n.System.getUsingLocalDigit();  // 判断本地化数字开关是否打开
  ```

### getSimplifiedLanguage<sup>15+</sup>

static getSimplifiedLanguage(language?: string): string

获取语言的最简化表示。如："zh-Hans-CN"的最简化表示是"zh"，"zh-Hant-TW"的最简表示为"zh-TW"。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明            |
| -------- | ------ | ---- | ------------- |
| language | string | 否    | 合法的语言ID。默认值：系统语言。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| string | 不传入language时，会根据系统语言和地区判断是否存在系统支持的方言，若存在则返回方言的最简表示；若不存在，则返回系统语言的最简表示。<br>传入language时，返回language的最简表示。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let simplifiedLanguage: string = i18n.System.getSimplifiedLanguage("zh-Hans-CN");  // simplifiedLanguage = zh
    let simplifiedSystemLanguage: string = i18n.System.getSimplifiedLanguage();  // simplifiedSystemLanguage = zh, 如果当前系统语言为简体中文
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSimplifiedLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getTemperatureType<sup>16+</sup>

static getTemperatureType(): TemperatureType

获取当前用户偏好的温度单位。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| [TemperatureType](#temperaturetype16) | 温度单位。 |

**示例：**
  ```ts
  let type: i18n.TemperatureType = i18n.System.getTemperatureType();
  ```

### getTemperatureName<sup>16+</sup>

static getTemperatureName(type: TemperatureType): string

获取温度单位的名称。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明            |
| -------- | ------ | ---- | ------------- |
| type| [TemperatureType](#temperaturetype16) | 是    | 温度单位。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| string | 返回温度单位的名称，包括celsius，fahrenheit，kelvin。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |


> **说明**
>
> 890001的报错信息请以接口的实际报错为准。

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let res: string = i18n.System.getTemperatureName(i18n.TemperatureType.CELSIUS);  // res = celsius
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getTemperatureName failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getFirstDayOfWeek<sup>16+</sup>

static getFirstDayOfWeek(): WeekDay

获取当前用户偏好的周起始日。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| [WeekDay](#weekday16) | 周起始日。 |

**示例：**
  ```ts
  let type: i18n.WeekDay = i18n.System.getFirstDayOfWeek();
  ```

## TemperatureType<sup>16+</sup>

温度单位的枚举。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| CELSIUS | 1 | 摄氏度。 |
| FAHRENHEIT | 2 | 华氏度。 |
| KELVIN | 3 | 开尔文。 |

## WeekDay<sup>16+</sup>

周起始日的枚举，取值是周一至周日的某天。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| MON | 1 | 周一。 |
| TUE | 2 | 周二。 |
| WED | 3 | 周三。 |
| THU | 4 | 周四。 |
| FRI | 5 | 周五。 |
| SAT | 6 | 周六。 |
| SUN | 7 | 周日。 |


## i18n.isRTL

isRTL(locale: string): boolean

判断某区域语言是否从右到左显示。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| locale | string | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。  |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | true表示该区域语言从右至左显示，false表示该区域语言从左至右显示。 |

**示例：**
  ```ts
  i18n.isRTL("zh-CN");// 中文不是RTL语言，返回false
  i18n.isRTL("ar-EG");// 阿语是RTL语言，返回true
  ```

## i18n.getCalendar<sup>8+</sup>

getCalendar(locale: string, type? : string): Calendar

获取日历对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成，例如zh-Hans-CN。                 |
| type   | string | 否    | 合法的日历类型，取值包括：buddhist,&nbsp;chinese,&nbsp;coptic,&nbsp;ethiopic,&nbsp;hebrew,&nbsp;gregory,&nbsp;indian,&nbsp;islamic_civil,&nbsp;islamic_tbla,&nbsp;islamic_umalqura,&nbsp;japanese,&nbsp;persian。<br>默认值：区域默认的日历类型。不同取值代表的含义和不同场景下取值请参考[设置日历和历法](../../internationalization/i18n-calendar.md)。 |

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| [Calendar](#calendar8) | 日历对象。 |

**示例：**
  ```ts
  i18n.getCalendar("zh-Hans", "chinese"); // 获取中国农历日历对象
  ```

## EntityRecognizer<sup>11+</sup>

### constructor<sup>11+</sup>

constructor(locale?: string)

创建实体识别对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                |
| ---- | ---- | ---- | ----------------- |
| locale | string | 否    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成，例如zh-Hans-CN。<br>默认值：系统当前locale。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  let entityRecognizer: i18n.EntityRecognizer = new i18n.EntityRecognizer("zh-CN");
  ```

### findEntityInfo<sup>11+</sup>

findEntityInfo(text: string): Array&lt;EntityInfoItem&gt;

识别文本中的实体信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                |
| ---- | ---- | ---- | ----------------- |
| text | string | 是    | 需要被识别的文本。 |

**返回值：**

| 类型   | 说明                |
| ---- | ----------------- |
| Array&lt;[EntityInfoItem](#entityinfoitem11)&gt; | 文本中的实体信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**
  ```ts
  let entityRecognizer: i18n.EntityRecognizer = new i18n.EntityRecognizer("zh-CN");
  let text1: string = "如有疑问，请联系158****2312";
  let result1: Array<i18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text1); // result1[0].type = "phone_number", result1[0].begin = 8, result1[0].end = 19
  let text2: string = "我们2023年12月1日一起吃饭吧。";
  let result2: Array<i18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text2); // result2[0].type = "date", result2[0].begin = 2, result2[0].end = 12
  ```

## EntityInfoItem<sup>11+</sup>

实体信息属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称  | 类型   | 可读   | 可写   | 说明                |
| ---- | ---- | ---- | ---- | ----------------- |
| type | string | 是    | 是    | 实体类型，当前支持phone_number和date类型。 |
| begin | number | 是    | 是    | 实体的起始位置。 |
| end | number | 是    | 是    | 实体的终止位置。 |

## Calendar<sup>8+</sup>

### setTime<sup>8+</sup>

setTime(date: Date): void

设置日历对象内部的时间、日期。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                |
| ---- | ---- | ---- | ----------------- |
| date | Date | 是    | 时间、日期。说明：月份从0开始计数，如0表示一月。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("en-US", "gregory");
  // 时间日期为2021.11.07 08:00:00
  let date: Date = new Date(2021, 10, 7, 8, 0, 0);
  calendar.setTime(date);
  ```


### setTime<sup>8+</sup>

setTime(time: number): void

设置日历对象内部的时间、日期。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| time | number | 是    | time为从1970.1.1&nbsp;00:00:00&nbsp;GMT逝去的毫秒数。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("en-US", "gregory");
  calendar.setTime(10540800000);
  ```

### set<sup>8+</sup>

set(year: number, month: number, date:number, hour?: number, minute?: number, second?: number): void

设置日历对象的年、月、日、时、分、秒。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明     |
| ------ | ------ | ---- | ------ |
| year   | number | 是    | 设置的年。  |
| month  | number | 是    | 设置的月。说明：月份从0开始计数，如0表示一月。  |
| date   | number | 是    | 设置的日。  |
| hour   | number | 否    | 设置的小时。默认值：系统小时。 |
| minute | number | 否    | 设置的分钟。默认值：系统分钟。 |
| second | number | 否    | 设置的秒。默认值：系统秒。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // 设置时间日期为2021.11.1 08:00:00
  ```

### setTimeZone<sup>8+</sup>

setTimeZone(timezone: string): void

设置日历对象的时区。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明                        |
| -------- | ------ | ---- | ------------------------- |
| timezone | string | 是    | 合法的时区ID，如“Asia/Shanghai”。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  ```


### getTimeZone<sup>8+</sup>

getTimeZone(): string

获取日历对象的时区。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 日历对象的时区ID。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  let timezone: string = calendar.getTimeZone(); // timezone = "Asia/Shanghai"
  ```


### getFirstDayOfWeek<sup>8+</sup>

getFirstDayOfWeek(): number

获取日历对象一周的起始日。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                    |
| ------ | --------------------- |
| number | 一周的起始日，1代表周日，7代表周六。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("en-US", "gregory");
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1
  ```


### setFirstDayOfWeek<sup>8+</sup>

setFirstDayOfWeek(value: number): void

设置一周的起始日。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                    |
| ----- | ------ | ---- | --------------------- |
| value | number | 是    | 一周起始日，1代表周日，7代表周六。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setFirstDayOfWeek(3);
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 3
  ```

### getMinimalDaysInFirstWeek<sup>8+</sup>

getMinimalDaysInFirstWeek(): number

获取一年中第一周的最小天数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| number | 一年中第一周的最小天数。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 1
  ```


### setMinimalDaysInFirstWeek<sup>8+</sup>

setMinimalDaysInFirstWeek(value: number): void

设置一年中第一周的最小天数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明           |
| ----- | ------ | ---- | ------------ |
| value | number | 是    | 一年中第一周的最小天数。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setMinimalDaysInFirstWeek(3);
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 3
  ```


### get<sup>8+</sup>

get(field: string): number

获取日历对象与field相关联的值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| field | string | 是    | 通过field来获取日历对象相应的值，目前支持的field值请参考下表。 |


| field名称   | 说明                                       |
| ----- | ---------------------------------------- |
| era | 纪元，例如公历中的公元前或者公元后。 |
| year | 年。 |
| month | 月。说明：月份从0开始计数，如0表示一月。 |
| date | 日。 |
| hour | 挂钟小时数。 |
| hour_of_day | 一天中的第几小时。 |
| minute | 分。 |
| second | 秒。 |
| millisecond | 毫秒。 |
| week_of_year | 一年中的第几周，按照星期计算周，注意：第一周的归属算法各地有区别。 |
| year_woy | 一年中的第几周，按照数值计算周，例如一年中前1~7日属于第一周。 |
| week_of_month | 一个月中的第几周，按照星期计算周。 |
| day_of_week_in_month | 一月中的第几周，按照数值计算周，例如1-7日属于第一周。 |
| day_of_year | 一年中的第几天。 |
| day_of_week | 一周中的第几天(星期)。 |
| milliseconds_in_day | 一天中的第几毫秒。 |
| zone_offset | 以毫秒计时的时区固定偏移量(不含夏令时)。 |
| dst_offset | 以毫秒计时的夏令时偏移量。 |
| dow_local | 本地星期。 |
| extended_year | 扩展的年份数值，支持负数。 |
| julian_day | 儒略日,与当前时区相关。 |
| is_leap_month | 是否为闰月。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 与field相关联的值，如当前Calendar对象的内部日期的年份为1990，get("year")返回1990。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // 设置时间日期为2021.11.1 08:00:00
  let hourOfDay: number = calendar.get("hour_of_day"); // hourOfDay = 8
  ```


### getDisplayName<sup>8+</sup>

getDisplayName(locale: string): string

获取日历对象在某区域的名字。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| string | 日历在locale所指示区域的名字。如buddhist在en-US上显示的名称为“Buddhist&nbsp;Calendar”。|

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("en-US", "buddhist");
  let calendarName: string = calendar.getDisplayName("zh"); // calendarName = "佛历"
  ```


### isWeekend<sup>8+</sup>

isWeekend(date?: Date): boolean

判断指定的日期在日历中是否为周末。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                                       |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | 否    | 时间、日期。说明：月份从0开始计数，如0表示一月。<br>默认值：系统日期。若不填，则判断当前日期是否为周末。 |

**返回值：**

| 类型      | 说明                                  |
| ------- | ----------------------------------- |
| boolean | true表示指定的日期是周末，false表示指定的日期不是周末。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 11, 11, 8, 0, 0); // 设置时间为2021.12.11 08:00:00
  calendar.isWeekend(); // true
  let date: Date = new Date(2011, 11, 6, 9, 0, 0); // 时间日期为2011.12.06 09:00:00
  calendar.isWeekend(date); // false
  ```


### add<sup>11+</sup>

add(field: string, amount: number): void

将日历中的某些字段进行加减操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                                       |
| ---- | ---- | ---- | ---------------------------------------- |
| field | string | 是    | 指定日历字段，目前支持的field值有&nbsp;year,&nbsp;month,&nbsp;week_of_year,&nbsp;week_of_month,&nbsp;date,&nbsp;day_of_year,&nbsp;day_of_week,&nbsp;day_of_week_in_month,&nbsp;hour,&nbsp;hour_of_day,&nbsp;minute,&nbsp;second,&nbsp;millisecond。<br>各取值代表的含义请参考[get](#get8)。 |
| amount | number | 是    | 进行加减操作的具体数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
    calendar.set(2021, 11, 11, 8, 0, 0); // 设置时间日期为2021.12.11 08:00:00
    calendar.add("year", 8); // 2021 + 8
    let year: number = calendar.get("year"); // year = 2029
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call Calendar.add failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getTimeInMillis<sup>11+</sup>

getTimeInMillis(): number

获取当前日历的UTC毫秒数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型      | 说明                                  |
| ------- | ----------------------------------- |
| number | 当前日历的UTC毫秒数。 |

**示例：**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setTime(5000);
  let millisecond: number = calendar.getTimeInMillis(); // millisecond = 5000
  ```


### compareDays<sup>11+</sup>

compareDays(date: Date): number

比较日历和指定日期相差的天数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                                       |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | 是    | 时间、日期。说明：月份从0开始计数，如0表示一月。 |

**返回值：**

| 类型      | 说明                                  |
| ------- | ----------------------------------- |
| number | 相差的天数，正数代表日历时间更早，负数代表指定时间更早。<br>按毫秒级的精度，不足一天将按一天进行计算。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
    calendar.setTime(5000);
    let date: Date = new Date(6000);
    let diff: number = calendar.compareDays(date); // diff = 1
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call Calendar.compareDays failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## PhoneNumberFormat<sup>8+</sup>


### constructor<sup>8+</sup>

constructor(country: string, options?: PhoneNumberFormatOptions)

创建电话号码格式化对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名     | 类型                                       | 必填   | 说明               |
| ------- | ---------------------------------------- | ---- | ---------------- |
| country | string                                   | 是    | 表示电话号码所属国家或地区代码。 |
| options | [PhoneNumberFormatOptions](#phonenumberformatoptions8) | 否    | 电话号码格式化时设置的配置项。默认值：NATIONAL。  |

**示例：**
  ```ts
  let option: i18n.PhoneNumberFormatOptions = {type: "E164"};
  let phoneNumberFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN", option);
  ```

### isValidNumber<sup>8+</sup>

isValidNumber(number: string): boolean

判断传入的电话号码格式是否正确。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明        |
| ------ | ------ | ---- | --------- |
| number | string | 是    | 待判断的电话号码。 |

**返回值：**

| 类型      | 说明                                    |
| ------- | ------------------------------------- |
| boolean | 返回true表示电话号码的格式正确，返回false表示电话号码的格式错误。 |

**示例：**
  ```ts
  let phonenumberfmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN");
  let isValidNumber: boolean = phonenumberfmt.isValidNumber("158****2312"); // isValidNumber = true
  ```


### format<sup>8+</sup>

format(number: string): string

对电话号码进行格式化。

> **说明**
> 从API version 12开始，支持对拨号中的号码进行格式化。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明         |
| ------ | ------ | ---- | ---------- |
| number | string | 是    | 待格式化的电话号码。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 格式化后的电话号码。 |

**示例：**
  ```ts
  let phonenumberfmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN");
  let formattedPhoneNumber: string = phonenumberfmt.format("158****2312"); // formattedPhoneNumber = "158 **** 2312"

  // 拨号中的号码格式化
  let option: i18n.PhoneNumberFormatOptions = {type: "TYPING"};
  let phoneNumberFmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN", option);
  let phoneNumber : string = "130493";
  let formatResult : string = "";
  for (let i = 0; i < phoneNumber.length; i++) {
    formatResult += phoneNumber.charAt(i);
    formatResult = phoneNumberFmt.format(formatResult);
  }
  console.log(formatResult); // formatResult: 130 493
  ```

### getLocationName<sup>9+</sup>

getLocationName(number: string, locale: string): string

判断电话号码归属地。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明   |
| ------ | ------ | ---- | ---- |
| number | string | 是    | 电话号码。获取其他地区号码的归属地时，需要在号码前加00+国际区号。 |
| locale | string | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。 |

**返回值：**

| 类型     | 说明       |
| ------ | -------- |
| string | 电话号码归属地。 |

**示例：**
  ```ts
  let phonenumberfmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN");
  let locationName: string = phonenumberfmt.getLocationName("158****2345", "zh-CN"); // locationName = "广东省湛江市"
  let locName: string = phonenumberfmt.getLocationName("0039312****789", "zh-CN"); // locName = "意大利"
  ```


## PhoneNumberFormatOptions<sup>8+</sup>

电话号码格式化时可设置的配置项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称   | 类型     | 可读   | 可写   | 说明                                       |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | 是    | 是    | 表示对电话号码格式化的类型，取值包括："E164",&nbsp;"INTERNATIONAL",&nbsp;"NATIONAL",&nbsp;"RFC3966",&nbsp;"TYPING"。<br>-在API version 8版本，type为必填项。 <br>-API version 9版本开始，type为选填项。<br>-API version 12版本开始支持TYPING，表示对拨号中的号码格式化。|


## UnitInfo<sup>8+</sup>

度量衡单位信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型     | 可读   | 可写   | 说明                                       |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| unit          | string | 是    | 是    | 单位的名称，如："meter",&nbsp;"inch",&nbsp;"cup"等。 |
| measureSystem | string | 是    | 是    | 单位的度量体系，取值包括："SI",&nbsp;"US",&nbsp;"UK"。 |


## getInstance<sup>8+</sup>

getInstance(locale?:string): IndexUtil

创建并返回IndexUtil对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                           |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | 否    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。<br>默认值：系统Locale。 |

**返回值：**

| 类型                       | 说明                    |
| ------------------------ | --------------------- |
| [IndexUtil](#indexutil8) | locale对应的IndexUtil对象。 |

**示例：**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance("zh-CN");
  ```


## IndexUtil<sup>8+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

### getIndexList<sup>8+</sup>

getIndexList(): Array&lt;string&gt;

获取当前区域的索引列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明                 |
| ------------------- | ------------------ |
| Array&lt;string&gt; | 返回当前区域的索引列表。 |

**示例：**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance("zh-CN");
  // indexList = [ "...", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
  //              "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "..." ]
  let indexList: Array<string> = indexUtil.getIndexList();
  ```


### addLocale<sup>8+</sup>

addLocale(locale: string): void

在当前区域的索引列表中，添加新区域的索引列表，形成复合列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                           |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。 |

**示例：**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance("zh-CN");
  indexUtil.addLocale("en-US");
  ```

### getIndex<sup>8+</sup>

getIndex(text: string): string

获取text对应的索引。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明           |
| ---- | ------ | ---- | ------------ |
| text | string | 是    | 待计算索引值的输入文本。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| string | 输入文本对应的索引值。 |

**示例：**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance("zh-CN");
  let index: string = indexUtil.getIndex("hi");  // index = "H"
  ```


## i18n.getLineInstance<sup>8+</sup>

getLineInstance(locale: string): BreakIterator

获取一个用于断句的[BreakIterator](#breakiterator8)对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。<br>生成的[BreakIterator](#breakiterator8)将按照locale所指定的区域规则进行断句。 |

**返回值：**

| 类型                               | 说明          |
| -------------------------------- | ----------- |
| [BreakIterator](#breakiterator8) | 断句处理器。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  ```


## BreakIterator<sup>8+</sup>


### setLineBreakText<sup>8+</sup>

setLineBreakText(text: string): void

设置BreakIterator要处理的文本。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明                      |
| ---- | ------ | ---- | ----------------------- |
| text | string | 是    | 指定BreakIterator进行断句的文本。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit."); // 设置短句文本
  ```


### getLineBreakText<sup>8+</sup>

getLineBreakText(): string

获取BreakIterator当前处理的文本。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                     |
| ------ | ---------------------- |
| string | BreakIterator对象正在处理的文本。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let breakText: string = iterator.getLineBreakText(); // breakText = "Apple is my favorite fruit."
  ```


### current<sup>8+</sup>

current(): number

获取BreakIterator对象在处理文本中的位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                          |
| ------ | --------------------------- |
| number | BreakIterator在当前所处理的文本中的位置。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let currentPos: number = iterator.current(); // currentPos = 0
  ```


### first<sup>8+</sup>

first(): number

将BreakIterator移动到第一个可断句的分割点。第一个分割点总是在被处理文本的起始位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                |
| ------ | ----------------- |
| number | 被处理文本的第一个分割点的偏移量。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let firstPos: number = iterator.first(); // firstPos = 0
  ```


### last<sup>8+</sup>

last(): number

将BreakIterator移动到最后一个可断句的分割点。最后一个分割点总是在被处理文本末尾的下一个位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| number | 被处理文本的最后一个分割点的偏移量。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let lastPos: number = iterator.last(); // lastPos = 27
  ```


### next<sup>8+</sup>

next(index?: number): number

将BreakIterator向后移动相应个分割点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| index | number | 否    | BreakIterator将要移动的分割点数。<br>正数代表向后移动，即将BreakIterator向后移动number个可断句的分割点；负数代表向前移动，即向前移动相应个分割点。<br>默认值：1。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 移动了index个分割点后，当前BreakIterator在文本中的位置。<br>若移动index个分割点后超出了所处理的文本的长度范围，返回-1。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(); // pos = 6
  pos = iterator.next(10); // pos = -1
  ```


### previous<sup>8+</sup>

previous(): number

将BreakIterator向前移动一个分割点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 移动到前一个分割点后，当前BreakIterator在文本中的位置。<br>若移动index个分割点后超出了所处理的文本的长度范围，返回-1。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(3); // pos = 12
  pos = iterator.previous(); // pos = 9
  ```


### following<sup>8+</sup>

following(offset: number): number

将BreakIterator移动到指定位置后面一个分割点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| offset | number | 是    | 将BreakIterator移动到指定位置的后面一个分割点。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | BreakIterator移动后的位置。若offset所指定位置的下一个分割点超出了文本的范围，则返回-1。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.following(0); // pos = 6
  pos = iterator.following(100); // pos = -1
  pos = iterator.current(); // pos = 27
  ```


### isBoundary<sup>8+</sup>

isBoundary(offset: number): boolean

判断指定位置是否为分割点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明          |
| ------ | ------ | ---- | ----------- |
| offset | number | 是    | 指定位置。 |

**返回值：**

| 类型      | 说明                              |
| ------- | ------------------------------- |
| boolean | 若offset指定的文本位置是一个分割点，则返回true，否则返回false。<br>返回true时，会将BreakIterator对象移动到offset指定的位置，否则相当于调用following。 |

**示例：**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let isBoundary: boolean = iterator.isBoundary(0); // isBoundary = true;
  isBoundary = iterator.isBoundary(5); // isBoundary = false;
  ```


## i18n.getTimeZone

getTimeZone(zoneID?: string): TimeZone

获取时区ID对应的时区对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| zoneID | string | 否    | 时区ID。默认值：系统时区。 |

**返回值：**

| 类型       | 说明           |
| -------- | ------------ |
| [TimeZone](#timezone) | 时区ID对应的时区对象。 |

**示例：**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  ```

## TimeZone

### getID

getID(): string

获取时区对象的ID。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 时区对象对应的时区ID。 |

**示例：**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  let timezoneID: string = timezone.getID(); // timezoneID = "Asia/Shanghai"
  ```


### getDisplayName

getDisplayName(locale?: string, isDST?: boolean): string

获取时区对象的本地化表示。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型      | 必填   | 说明                   |
| ------ | ------- | ---- | -------------------- |
| locale | string  | 否    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。默认值：系统Locale。                |
| isDST  | boolean | 否    | 时区对象本地化时是否考虑夏令时。默认值：false。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 时区对象在指定区域的本地化表示。 |

**示例：**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  let timezoneName: string = timezone.getDisplayName("zh-CN", false); // timezoneName = "中国标准时间"
  ```


### getRawOffset

getRawOffset(): number

获取时区对象表示的时区与UTC时区的偏差。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| number | 时区对象表示的时区与UTC时区的偏差，单位是毫秒。 |

**示例：**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  let offset: number = timezone.getRawOffset(); // offset = 28800000
  ```


### getOffset

getOffset(date?: number): number

获取某一时刻时区对象表示的时区与UTC时区的偏差。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明     |
| ------ | ------ | ---- | ------ |
| date | number | 否    | 待计算偏差的时刻，单位是毫秒。默认值：系统时间。 |

**返回值：**

| 类型     | 说明                      |
| ------ | ----------------------- |
| number | 某一时刻时区对象表示的时区与UTC时区的偏差。 |

**示例：**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  let offset: number = timezone.getOffset(1234567890); // offset = 28800000
  ```


### getAvailableIDs<sup>9+</sup>

static getAvailableIDs(): Array&lt;string&gt;

获取系统支持的时区ID。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明          |
| ------------------- | ----------- |
| Array&lt;string&gt; | 系统支持的时区ID列表。 |

**示例：**
  ```ts
  // ids = ["America/Adak", "America/Anchorage", "America/Bogota", "America/Denver", "America/Los_Angeles", "America/Montevideo", "America/Santiago", "America/Sao_Paulo", "Asia/Ashgabat", "Asia/Hovd", "Asia/Jerusalem", "Asia/Magadan", "Asia/Omsk", "Asia/Shanghai", "Asia/Tokyo", "Asia/Yerevan", "Atlantic/Cape_Verde", "Australia/Lord_Howe", "Europe/Dublin", "Europe/London", "Europe/Moscow", "Pacific/Auckland", "Pacific/Easter", "Pacific/Pago-Pago"]
  let ids: Array<string> = i18n.TimeZone.getAvailableIDs();
  ```


### getAvailableZoneCityIDs<sup>9+</sup>

static getAvailableZoneCityIDs(): Array&lt;string&gt;

获取系统支持的时区城市ID。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Array&lt;string&gt; | 系统支持的时区城市ID列表。 |

**示例：**
  ```ts
  // cityIDs = ["Auckland", "Magadan", "Lord Howe Island", "Tokyo", "Shanghai", "Hovd", "Omsk", "Ashgabat", "Yerevan", "Moscow", "Tel Aviv", "Dublin", "London", "Praia", "Montevideo", "Brasília", "Santiago", "Bogotá", "Easter Island", "Salt Lake City", "Los Angeles", "Anchorage", "Adak", "Pago Pago"]
  let cityIDs: Array<string> = i18n.TimeZone.getAvailableZoneCityIDs();
  ```

### getCityDisplayName<sup>9+</sup>

static getCityDisplayName(cityID: string, locale: string): string

获取某时区城市在该区域的本地化显示。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明     |
| ------ | ------ | ---- | ------ |
| cityID | string | 是    | 时区城市ID。 |
| locale | string | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。  |

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| string | 时区城市在某区域的本地化显示。 |

**示例：**
  ```ts
  let displayName: string = i18n.TimeZone.getCityDisplayName("Shanghai", "zh-CN"); // displayName = "上海 (中国)"
  ```


### getTimezoneFromCity<sup>9+</sup>

static getTimezoneFromCity(cityID: string): TimeZone

创建某时区城市对应的时区对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明     |
| ------ | ------ | ---- | ------ |
| cityID | string | 是    | 时区城市ID。 |

**返回值：**

| 类型       | 说明          |
| -------- | ----------- |
| TimeZone | 时区城市对应的时区对象。 |

**示例：**
  ```ts
  let timezone: i18n.TimeZone = i18n.TimeZone.getTimezoneFromCity("Shanghai");
  ```

### getTimezonesByLocation<sup>10+</sup>

static getTimezonesByLocation(longitude: number, latitude: number): Array&lt;TimeZone&gt;

创建某经纬度对应的时区对象数组。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名     | 类型     | 必填   | 说明     |
| --------- | ------ | ---- | ------ |
| longitude | number | 是    | 经度, 范围[-180, 179.9), 东经取正值, 西经取负值。 |
| latitude  | number | 是    | 纬度, 范围[-90, 89.9), 北纬取正值, 南纬取负值。 |

**返回值：**

| 类型       | 说明          |
| -------- | ----------- |
| Array&lt;[TimeZone](#timezone)&gt; | 时区对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |


> **说明**
>
> 890001的报错信息请以接口的实际报错为准。

**示例：**
  ```ts
  let timezoneArray: Array<i18n.TimeZone> = i18n.TimeZone.getTimezonesByLocation(-118.1, 34.0);
  for (let i = 0; i < timezoneArray.length; i++) {
      let tzId: string = timezoneArray[i].getID();
  }
  ```


## Transliterator<sup>9+</sup>


### getAvailableIDs<sup>9+</sup>

static getAvailableIDs(): string[]

获取音译支持的ID列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型       | 说明         |
| -------- | ---------- |
| string[] | 音译支持的ID列表。 |

**示例：**
  ```ts
  // ids共支持742个。每一个id由使用中划线分割的两部分组成，格式为 source-destination。例如ids = ["Han-Latin","Latin-ASCII", "Amharic-Latin/BGN","Accents-Any", ...]，Han-Latin表示汉语转为译拉丁文，Amharic-Latin表示阿姆哈拉语转为拉丁文。
  // 更多使用信息可以参考ISO-15924。
  let ids: string[] = i18n.Transliterator.getAvailableIDs();
  ```


### getInstance<sup>9+</sup>

static getInstance(id: string): Transliterator

创建音译对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明       |
| ---- | ------ | ---- | -------- |
| id   | string | 是    | 音译支持的ID。 |

**返回值：**

| 类型                                 | 说明    |
| ---------------------------------- | ----- |
| [Transliterator](#transliterator9) | 音译对象。 |

**示例：**
  ```ts
  let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance("Any-Latn");
  ```


### transform<sup>9+</sup>

transform(text: string): string

将输入字符串从源格式转换为目标格式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明     |
| ---- | ------ | ---- | ------ |
| text | string | 是    | 输入字符串。 |

**返回值：**

| 类型     | 说明       |
| ------ | -------- |
| string | 转换后的字符串。 |

**示例：**
  ```ts
  let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance("Any-Latn");
  let wordArray = ["中国", "德国", "美国", "法国"]
  for (let i = 0; i < wordArray.length; i++) {
      let res = transliterator.transform(wordArray[i]); // res: zhōng guó, dé guó, měi guó, fǎ guó
  }

  // 汉语音译去声调
  let transliter = i18n.Transliterator.getInstance('Any-Latn;Latin-Ascii');
  let result = transliter.transform('中国'); // result: zhong guo

  // 汉语姓氏读音
  let nameTransliter = i18n.Transliterator.getInstance('Han-Latin/Names');
  let result1 = nameTransliter.transform('单老师'); // result1: shàn lǎo shī
  let result2 = nameTransliter.transform('长孙无忌'); // result2: zhǎng sūn wú jì
  ```


## Unicode<sup>9+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

### isDigit<sup>9+</sup>

static isDigit(char: string): boolean

判断字符串char是否是数字。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符串。 |

**返回值：**

| 类型      | 说明                                   |
| ------- | ------------------------------------ |
| boolean | 返回true表示输入的字符是数字，返回false表示输入的字符不是数字。 |

**示例：**
  ```ts
  let isdigit: boolean = i18n.Unicode.isDigit("1");  // isdigit = true
  ```


### isSpaceChar<sup>9+</sup>

static isSpaceChar(char: string): boolean

判断字符串char是否是空格符。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符串。 |

**返回值：**

| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空格符，返回false表示输入的字符不是空格符。 |

**示例：**
  ```ts
  let isspacechar: boolean = i18n.Unicode.isSpaceChar("a");  // isspacechar = false
  ```


### isWhitespace<sup>9+</sup>

static isWhitespace(char: string): boolean

判断字符串char是否是空白符。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 字符串。 |

**返回值：**

| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空白符，返回false表示输入的字符不是空白符。 |

**示例：**
  ```ts
  let iswhitespace: boolean = i18n.Unicode.isWhitespace("a");  // iswhitespace = false
  ```


### isRTL<sup>9+</sup>

static isRTL(char: string): boolean

判断字符串char是否是从右到左语言的字符。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是从右到左语言的字符，返回false表示输入的字符不是从右到左语言的字符。 |

**示例：**
  ```ts
  let isrtl: boolean = i18n.Unicode.isRTL("a");  // isrtl = false
  ```


### isIdeograph<sup>9+</sup>

static isIdeograph(char: string): boolean

判断字符串char是否是表意文字。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是表意文字，返回false表示输入的字符不是表意文字。 |

**示例：**
  ```ts
  let isideograph: boolean = i18n.Unicode.isIdeograph("a");  // isideograph = false
  ```


### isLetter<sup>9+</sup>

static isLetter(char: string): boolean

判断字符串char是否是字母。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                   |
| ------- | ------------------------------------ |
| boolean | 返回true表示输入的字符是字母，返回false表示输入的字符不是字母。 |

**示例：**
  ```ts
  let isletter: boolean = i18n.Unicode.isLetter("a");  // isletter = true
  ```


### isLowerCase<sup>9+</sup>

static isLowerCase(char: string): boolean

判断字符串char是否是小写字母。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是小写字母，返回false表示输入的字符不是小写字母。 |

**示例：**
  ```ts
  let islowercase: boolean = i18n.Unicode.isLowerCase("a");  // islowercase = true
  ```


### isUpperCase<sup>9+</sup>

static isUpperCase(char: string): boolean

判断字符串char是否是大写字母。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是大写字母，返回false表示输入的字符不是大写字母。 |

**示例：**
  ```ts
  let isuppercase: boolean = i18n.Unicode.isUpperCase("a");  // isuppercase = false
  ```


### getType<sup>9+</sup>

static getType(char: string): string

获取输入字符串的一般类别值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| string | 输入字符的一般类别值。|

一般类别值如下，更详细的介绍可以参考Unicode标准。

| 名称 | 值 | 说明 |
| ---- | -------- | ---------- |
| U_UNASSIGNED | U_UNASSIGNED | 表示未分配和非字符代码点对应类别。 |
| U_GENERAL_OTHER_TYPES | U_GENERAL_OTHER_TYPES | 与 U_UNASSIGNED 相同。 |
| U_UPPERCASE_LETTER | U_UPPERCASE_LETTER | 表示大写字母。 |
| U_LOWERCASE_LETTER | U_LOWERCASE_LETTER | 表示小写字母。  |
| U_TITLECASE_LETTER | U_TITLECASE_LETTER | 表示首字母大写。 |
| U_MODIFIER_LETTER | U_MODIFIER_LETTER | 表示字母修饰符。 |
| U_OTHER_LETTER | U_OTHER_LETTER | 表示其它字母，不属于大写字母、小写字母、首字母大写或修饰符字母的字母。 |
| U_NON_SPACING_MARK | U_NON_SPACING_MARK | 表示非间距标记，如重音符号'，变音符号#。 |
| U_ENCLOSING_MARK | U_ENCLOSING_MARK | 表示封闭标记和能围住其它字符的标记，如圆圈、方框等。 |
| U_COMBINING_SPACING_MARK | U_COMBINING_SPACING_MARK | 表示间距标记，如元音符号[ ]。 |
| U_DECIMAL_DIGIT_NUMBER | U_DECIMAL_DIGIT_NUMBER | 表示十进制数字。 |
| U_LETTER_NUMBER | U_LETTER_NUMBER | 表示字母数字，罗马数字。 |
| U_OTHER_NUMBER | U_OTHER_NUMBER | 表示其它作为加密符号和记号的数字，非阿拉伯数字的数字表示符，如@、#、（1）、①等。 |
| U_SPACE_SEPARATOR | U_SPACE_SEPARATOR | 表示空白分隔符，如空格符、不间断空格、固定宽度的空白符。 |
| U_LINE_SEPARATOR | U_LINE_SEPARATOR | 表示行分隔符。|
| U_PARAGRAPH_SEPARATOR | U_PARAGRAPH_SEPARATOR | 表示段落分割符。 |
| U_CONTROL_CHAR | U_CONTROL_CHAR | 表示控制字符。 |
| U_FORMAT_CHAR | U_FORMAT_CHAR | 表示格式字符。 |
| U_PRIVATE_USE_CHAR | U_PRIVATE_USE_CHAR | 表示私人使用区代码点类别，例如公司 logo。 |
| U_SURROGATE | U_SURROGATE | 表示代理项，在UTF-16中用来表示补充字符的方法。 |
| U_DASH_PUNCTUATION | U_DASH_PUNCTUATION | 表示短划线标点。 |
| U_START_PUNCTUATION | U_START_PUNCTUATION | 表示开始标点，如左括号。 |
| U_END_PUNCTUATION | U_END_PUNCTUATION | 表示结束标点，如右括号。 |
| U_INITIAL_PUNCTUATION | U_INITIAL_PUNCTUATION | 表示前引号，如左双引号、左单引号。 |
| U_FINAL_PUNCTUATION | U_FINAL_PUNCTUATION | 表示后引号，如右双引号、右单引号。 |
| U_CONNECTOR_PUNCTUATION | U_CONNECTOR_PUNCTUATION | 表示连接符标点。 |
| U_OTHER_PUNCTUATION | U_OTHER_PUNCTUATION | 表示其他标点。 |
| U_MATH_SYMBOL | U_MATH_SYMBOL | 表示数学符号。 |
| U_CURRENCY_SYMBOL | U_CURRENCY_SYMBOL | 表示货币符号。 |
| U_MODIFIER_SYMBOL | U_MODIFIER_SYMBOL | 表示修饰符号。 |
| U_OTHER_SYMBOL | U_OTHER_SYMBOL | 表示其它符号。 |

**示例：**
  ```ts
  let type: string = i18n.Unicode.getType("a"); // type = "U_LOWERCASE_LETTER"
  ```

## I18NUtil<sup>9+</sup>


### unitConvert<sup>9+</sup>

static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

将fromUnit的单位转换为toUnit的单位，并根据区域与风格进行格式化。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型                     | 必填   | 说明                                       |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| fromUnit | [UnitInfo](#unitinfo8) | 是    | 需要转换的单位。                                 |
| toUnit   | [UnitInfo](#unitinfo8) | 是    | 转换成的目标单位。                                 |
| value    | number                 | 是    | 需要转换的单位的数量值。                             |
| locale   | string                 | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成，如：zh-Hans-CN。                |
| style    | string                 | 否    | 格式化使用的风格，取值包括："long",&nbsp;"short",&nbsp;"narrow"。默认值：short。<br>不同取值显示效果请参考[数字与度量衡国际化](../../internationalization/i18n-numbers-weights-measures.md)。 |

**返回值：**

| 类型     | 说明                      |
| ------ | ----------------------- |
| string | 按照toUnit的单位格式化后，得到的字符串。 |

**示例：**
  ```ts
  let fromUnit: i18n.UnitInfo = {unit: "cup", measureSystem: "US"};
  let toUnit: i18n.UnitInfo = {unit: "liter", measureSystem: "SI"};
  let res: string = i18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, "en-US", "long"); // res = 236.588 liters
  ```

### getDateOrder<sup>9+</sup>

static getDateOrder(locale: string): string

获取某区域日期中年、月、日的排列顺序。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                        |
| ------ | ------ | ---- | ------------------------- |
| locale | string | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成，如：zh-Hans-CN。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| string | 返回该区域年、月、日的排列顺序。 |

**示例：**
  ```ts
  let order: string = i18n.I18NUtil.getDateOrder("zh-CN");  // order = "y-L-d"
  ```


### getTimePeriodName<sup>11+</sup>

static getTimePeriodName(hour:number, locale?: string): string

获取某区域指定时间的本地化表达。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                        |
| ------ | ------ | ---- | ------------------------- |
| hour | number | 是    | 指定的时间，如：16。 |
| locale | string | 否    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。如：zh-Hans-CN。<br>默认是当前区域。|

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| string | 返回某区域指定时间的本地化表达。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let name: string = i18n.I18NUtil.getTimePeriodName(2, "zh-CN");  // name = "凌晨"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call I18NUtil.getTimePeriodName failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getBestMatchLocale<sup>12+</sup>

static getBestMatchLocale(locale: string, localeList: string[]): string

在指定区域列表中获取与某个区域最佳匹配的区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                        |
| ------ | ------ | ---- | ------------------------- |
| locale | string | 是    | 待匹配的[区域信息字符串](../../internationalization/i18n-locale-culture.md#实现原理)，如：zh-Hans-CN。 |
| localeList | string[] | 是   | 被指定的区域字符串列表。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| string | 与某个区域最佳匹配的区域ID。当指定区域列表中没有匹配的区域时，返回空字串。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let matchedLocaleId: string = i18n.I18NUtil.getBestMatchLocale("zh-Hans-CN", ["en-Latn-US", "en-GB", "zh-Hant-CN", "zh-Hans-MO"]);  // matchedLocaleId = "zh-Hans-MO"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call I18NUtil.getBestMatchLocale failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getThreeLetterLanguage<sup>12+</sup>

static getThreeLetterLanguage(locale: string): string

将语言代码由二字母转换为三字母。<br>例如，中文的二字母语言代码是zh，对应的三字母语言代码是zho，更多详细信息可参考[ISO 639](https://www.iso.org/iso-639-language-code)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| locale | string | 是   | 待转换的语言二字母代码，如：zh。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001   | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let language : string = i18n.I18NUtil.getThreeLetterLanguage('zh')  // zho
  } catch(error) {
    console.error(`call I18NUtil.getThreeLetterLanguage failed, error code: ${error.code}, message: ${error.message}.`);
  }
  ```

### getThreeLetterRegion<sup>12+</sup>

static getThreeLetterRegion(locale: string): string

将地区的二字母代码转换为三字母。<br>例如，中国的二字母地区代码是CN, 三字母是CHN，更多详细信息可参考[ISO 3166](https://www.iso.org/iso-3166-country-codes.html)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| locale | string | 是   | 待转换的地区二字母代码，如：CN。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001   | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let region : string = i18n.I18NUtil.getThreeLetterRegion('CN')  // CHN
  } catch(error) {
    console.error(`call I18NUtil.getThreeLetterRegion failed, error code: ${error.code}, message: ${error.message}.`);
  }
  ```

### getUnicodeWrappedFilePath<sup>16+</sup>

static getUnicodeWrappedFilePath(path: string, delimiter?: string, locale?: intl.Locale): string

文件路径镜像处理。<br>例如，将/data/out/tmp镜像处理后生成tmp/out/data/。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| path | string | 是   | 待处理的路径，如：/data/out/tmp。 |
| delimiter | string | 否   | 路径分隔符，默认值：/。 |
| locale | [intl.Locale](./js-apis-intl.md#locale) | 否   | intl.Locale对象，默认值：new intl.Locale([i18n.System.getSystemLocale()](#getsystemlocale9))。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001   | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import intl from '@ohos.intl';
  import i18n from '@ohos.i18n';

  try {
    let path : string = "/data/out/tmp";
    let delimiter : string = "/";
    let locale : intl.Locale = new intl.Locale("ar");
    let mirrorPath : string = i18n.I18NUtil.getUnicodeWrappedFilePath(path, delimiter, locale);  // mirrorPath:tmp/out/data/
  } catch(error) {
    console.error(`call I18NUtil.getUnicodeWrappedFilePath failed, error code: ${error.code}, message: ${error.message}.`);
  }
  ```

## Normalizer<sup>10+</sup>


### getInstance<sup>10+</sup>

static getInstance(mode: NormalizerMode): Normalizer

获取文本正则化对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                        |
| ------ | ------ | ---- | ------------------------- |
| mode | [NormalizerMode](#normalizermode10) | 是    | 文本正则化范式。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| [Normalizer](#normalizer10) | 返回指定范式的文本正则化对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**
  ```ts
  let normalizer: i18n.Normalizer = i18n.Normalizer.getInstance(i18n.NormalizerMode.NFC);
  ```


### normalize<sup>10+</sup>

normalize(text: string): string

对字符串进行正则化。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                        |
| ------ | ------ | ---- | ------------------------- |
| text | string | 是    | 待正则化的字符串。 |

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| string | 正则化后的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**
  ```ts
  let normalizer: i18n.Normalizer = i18n.Normalizer.getInstance(i18n.NormalizerMode.NFC);
  let normalizedText: string = normalizer.normalize('\u1E9B\u0323'); // normalizedText = ẛ̣
  ```

## NormalizerMode<sup>10+</sup>

文本正则化范式的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** ：SystemCapability.Global.I18n

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NFC | 1 | NFC范式。 |
| NFD | 2 | NFD范式。 |
| NFKC | 3 | NFKC范式。 |
| NFKD | 4 | NFKD范式。 |


## HolidayManager<sup>11+</sup>


### constructor<sup>11+</sup>

constructor(icsPath: String)

创建HolidayManager对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ------------- | ---- | ------------- |
| icsPath   | String | 是   | 在设备上有应用读取权限的iCalendar格式的ics文件路径。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  let holidayManager= new i18n.HolidayManager("/system/lib/US.ics");
  ```

### isHoliday<sup>11+</sup>

isHoliday(date?: Date): boolean

判断指定的日期是否是节假日。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ---------------| ---- | ------------- |
| date      | Date           | 否   | 时间、日期。说明：月份从0开始计数，如0表示一月。<br>如果没有指定日期，默认为当天。|

**返回值：**

|       类型        |         说明          |
| ----------------- | ----------------------|
| boolean           | 返回true是节假日，返回false不是节假日。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let holidayManager= new i18n.HolidayManager("/system/lib/US.ics"); // 需要将"/system/lib/US.ics"替换为实际ics文件路径
    let isHoliday = holidayManager.isHoliday();
    console.log(isHoliday.toString());
    let isHoliday2 = holidayManager.isHoliday(new Date(2023,5,25)); // 时间日期为2023.06.25
    console.log(isHoliday2.toString());
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call holidayManager.isHoliday failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getHolidayInfoItemArray<sup>11+</sup>

getHolidayInfoItemArray(year?: number): Array&lt;[HolidayInfoItem](#holidayinfoitem11)&gt;

获取指定年的节假日信息列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | -------------  | ---- | ------------- |
| year      | number         | 否   | 年，例如2023。<br>如果没有指定年，默认为当年。|

**返回值：**

|       类型        |         说明          |
| ----------------- | -------------------- |
| Array&lt;[HolidayInfoItem](#holidayinfoitem11)&gt; | 返回节假日信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let holidayManager= new i18n.HolidayManager("/system/lib/US.ics"); // 需要将"/system/lib/US.ics"替换为实际ics文件路径
    let holidayInfoItemArray = holidayManager.getHolidayInfoItemArray(2023);
    for (let i =0; i < holidayInfoItemArray.length; i++) {
        console.log(JSON.stringify(holidayInfoItemArray[i]));
    }
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call holidayManager.getHolidayInfoItemArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## HolidayInfoItem<sup>11+</sup>

节假日信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型             |  必填   |  说明                                   |
| --------------- | --------------- | ------  | --------------------------------------- |
| baseName        | string          |   是    | 节假日的英文名称。              |
| year            | number          |   是    | 节假日所在年。                   |
| month           | number          |   是    | 节假日所在月。          |
| day             | number          |   是    | 节假日所在日。                         |
| localNames      | Array&lt;[HolidayLocalName](#holidaylocalname11)&gt;          |   否    | 节假日的本地名称列表。          |

## HolidayLocalName<sup>11+</sup>

节假日本地名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型             |  必填   |  说明                                   |
| --------------- | -----------------| ------  | --------------------------------------- |
| language        | string           |   是    | 节假日的本地语言，例如ar，en，tr。          |
| name            | string           |   是    | 节假日的本地名称，例如Sacrifice Feast(宰牲节)的土耳其语名称为Kurban Bayrami。      |


## i18n.getSimpleDateTimeFormatByPattern<sup>16+</sup>

getSimpleDateTimeFormatByPattern(pattern: string, locale?: intl.Locale): SimpleDateTimeFormat

通过模式字符串获取SimpleDateTimeFormat对象。与getSimpleDateTimeFormatBySkeleton接口获取的对象在格式化后显示差异请参考[SimpleDateTimeFormat](#simpledatetimeformat16)。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------- | ----------- | ----- | ---------------------------------------- |
| pattern | string      | 是    | 合法的模式字符串，支持的字符及含义请参考[日期字段符号表](https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table)。同时，pattern支持传入自定义文本，文本内容以''标识。 |
| locale  | [intl.Locale](./js-apis-intl.md#locale) | 否    | 合法的区域对象。默认值：系统区域。 |

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| [SimpleDateTimeFormat](#simpledatetimeformat16) | SimpleDateTimeFormat对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { intl } from '@kit.LocalizationKit';

  let locale : intl.Locale = new intl.Locale("zh-Hans-CN");
  let formatter : i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatByPattern("'month('M')'", locale);
  ```

## i18n.getSimpleDateTimeFormatBySkeleton<sup>16+</sup>

getSimpleDateTimeFormatBySkeleton(skeleton: string, locale?: intl.Locale): SimpleDateTimeFormat

通过框架字符串获取SimpleDateTimeFormat对象。与getSimpleDateTimeFormatByPattern接口获取的对象在格式化后显示差异请参考[SimpleDateTimeFormat](#simpledatetimeformat16)。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------- | ----------- | ----- | ---------------------------------------- |
| skeleton | string      | 是    | 合法的框架字符串，支持的字符及含义请参考[日期字段符号表](https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table)。skeleton不支持传入自定义文本。 |
| locale  | [intl.Locale](./js-apis-intl.md#locale) | 否    | 合法的区域对象。默认值：系统区域。 |

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| [SimpleDateTimeFormat](#simpledatetimeformat16) | SimpleDateTimeFormat对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { intl } from '@kit.LocalizationKit';

  let locale : intl.Locale = new intl.Locale("zh-Hans-CN");
  let formatter : i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatBySkeleton("yMd", locale);
  ```

## SimpleDateTimeFormat<sup>16+</sup>

### format<sup>16+</sup>

format(date: Date): string

对时间、日期进行格式化。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                |
| ---- | ---- | ---- | ----------------- |
| date | Date | 是    | 时间、日期。说明：月份从0开始计数，如0表示一月。 |

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| string | 格式化后的时间、日期字符串。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**
  ```ts
  import { intl } from '@kit.LocalizationKit';

  let locale : intl.Locale = new intl.Locale("zh-Hans-CN");
  let date : Date = new Date(2024, 11, 13); // 时间日期为2024.12.13

  let formatterWithText : i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatByPattern("'month('M')'", locale);
  let result : string = formatterWithText.format(date); // result = month(12)

  let patternFormatter : i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatByPattern("yMd", locale);
  result = patternFormatter.format(date); // result = 20241213

  let skeletonFormatter : i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatBySkeleton("yMd", locale);
  result = skeletonFormatter.format(date); // result = 2024/12/13
  ```


## i18n.getSimpleNumberFormatBySkeleton<sup>16+</sup>

getSimpleNumberFormatBySkeleton(skeleton: string, locale?: intl.Locale): SimpleNumberFormat

通过框架字符串获取SimpleNumberFormat对象。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明                                       |
| ------- | ----------- | ----- | ---------------------------------------- |
| skeleton | string      | 是    | 合法的框架字符串，支持的字符及含义请参考[Number Skeletons](https://unicode-org.github.io/icu/userguide/format_parse/numbers/skeletons.html#number-skeletons)。 |
| locale  | [intl.Locale](./js-apis-intl.md#locale) | 否    | 合法的区域对象。默认值：系统区域。 |

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| [SimpleNumberFormat](#simplenumberformat16) | SimpleNumberFormat对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.i18n错误码](errorcode-i18n.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**示例：**
  ```ts
  import { intl } from '@kit.LocalizationKit';

  let locale : intl.Locale = new intl.Locale("zh-Hans-CN");
  let formatter : i18n.SimpleNumberFormat = i18n.getSimpleNumberFormatBySkeleton("%", locale);
  ```

## SimpleNumberFormat<sup>16+</sup>

### format<sup>16+</sup>

format(value: number): string

格式化数字字符串。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明                |
| ---- | ---- | ---- | ----------------- |
| value | number | 是    | 数字对象。 |

**返回值：**

| 类型                     | 说明    |
| ---------------------- | ----- |
| string | 格式化后的数字字符串。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**
  ```ts
  import { intl } from '@kit.LocalizationKit';

  let locale : intl.Locale = new intl.Locale("zh-Hans-CN");
  let formatter : i18n.SimpleNumberFormat = i18n.getSimpleNumberFormatBySkeleton("%", locale);
  let result : string = formatter.format(10); // result = 10%
  ```

## StyledNumberFormat<sup>16+</sup>

### constructor<sup>16+</sup>

constructor(numberFormat: intl.NumberFormat | SimpleNumberFormat, options?: StyledNumberFormatOptions)

创建需要富文本显示的数字格式化的对象。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ------------- | ---- | ------------- |
| numberFormat | [intl.NumberFormat](js-apis-intl.md#numberformat) \| [SimpleNumberFormat](#simplenumberformat16) | 是   | 用于格式化数字的对象。  |
| options | [StyledNumberFormatOptions](#stylednumberformatoptions16) | 否 | 指定数字格式化对象的配置项。默认值：默认的文本样式。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**
  ```ts
  import { intl } from '@kit.LocalizationKit';

  let integer_textStyle = new TextStyle({fontColor: Color.Red});
  let decimal_textStyle = new TextStyle({fontColor: Color.Brown});
  let fraction_textStyle = new TextStyle({fontColor: Color.Blue});
  let unit_textStyle = new TextStyle({fontColor: Color.Green});

  // 通过intl.NumberFormat创建StyledNumberFormat对象
  let numFmt = new intl.NumberFormat("zh", {style: "unit", unit: "percent"});
  let styledNumFmt_1 = new i18n.StyledNumberFormat(numFmt, {
    integer: integer_textStyle,
    decimal: decimal_textStyle,
    fraction: fraction_textStyle,
    unit: unit_textStyle });
  
  // 通过SimpleNumberFormat创建StyledNumberFormat对象
  let locale = new intl.Locale("zh");
  let simpleNumFmt = i18n.getSimpleNumberFormatBySkeleton("percent", locale);
  let styledNumFmt_2 = new i18n.StyledNumberFormat(simpleNumFmt, {
    integer: integer_textStyle,
    decimal: decimal_textStyle,
    fraction: fraction_textStyle,
    unit: unit_textStyle });
  ```

### format<sup>16+</sup>

format(value: number): StyledString

对创建的数字格式化对象处理，返回富文本对象。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

|   参数名  |      类型      | 必填 |     说明      |
| --------- | ------------- | ---- | ------------- |
| value | Number | 是 | 需要格式化的数字。  |

**返回值：**

|       类型        |         说明          |
| ----------------- | ----------------------|
| [StyledString](../apis-arkui/arkui-ts/ts-universal-styled-string.md#styledstring) | 返回格式化后的富文本对象。 |


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**
  ```ts
  import { intl } from '@kit.LocalizationKit';

  let integer_textStyle = new TextStyle({fontColor: Color.Red});
  let decimal_textStyle = new TextStyle({fontColor: Color.Brown});
  let fraction_textStyle = new TextStyle({fontColor: Color.Blue});
  let unit_textStyle = new TextStyle({fontColor: Color.Green});

  // 通过intl.NumberFormat创建StyledNumberFormat对象
  let numFmt = new intl.NumberFormat("zh", {style: "unit", unit: "percent"});
  let styledNumFmt_1 = new i18n.StyledNumberFormat(numFmt, {
    integer: integer_textStyle,
    decimal: decimal_textStyle,
    fraction: fraction_textStyle,
    unit: unit_textStyle });
  let result_1 = styledNumFmt_1.format(1234.5678);  // result_1.getString() 为 "1,234.568%"。显示result_1时"1,234"是红色，"."是棕色，"568"是蓝色，"%"是绿色。
  
  // 通过SimpleNumberFormat创建StyledNumberFormat对象
  let locale = new intl.Locale("zh");
  let simpleNumFmt = i18n.getSimpleNumberFormatBySkeleton("percent", locale);
  let styledNumFmt_2 = new i18n.StyledNumberFormat(simpleNumFmt, {
    integer: integer_textStyle,
    decimal: decimal_textStyle,
    fraction: fraction_textStyle,
    unit: unit_textStyle });
  let result_2 = styledNumFmt_2.format(1234.5678);  // result_2.getString() 为 "1,234.5678%"。显示result_2时"1,234"是红色，"."是棕色，"5678"是蓝色，"%"是绿色。
  ```

## StyledNumberFormatOptions<sup>16+</sup>

创建需要富文本显示的数字格式化的对象时，可选的配置项。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型             |  必填   |  说明                                   |
| --------------- | --------------- | ------  | --------------------------------------- |
| integer        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   否    |  指定整数部分的文本样式。默认值：默认的文本样式。     |
| decimal        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   否    |  指定小数点的文本样式。默认值：默认的文本样式。    |
| fraction       | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   否    |  指定小数部分的文本样式。默认值：默认的文本样式。     |
| unit           | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   否    |  指定单位部分的文本样式。默认值：默认的文本样式。     |

## i18n.getDisplayCountry<sup>(deprecated)</sup>

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

获取指定国家的本地化显示文本。

从API version 9开始不再维护，建议使用[System.getDisplayCountry](#getdisplaycountry9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | 是    | 指定国家。            |
| locale       | string  | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。      |
| sentenceCase | boolean | 否    | 本地化显示文本是否要首字母大写。默认值：true。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 指定国家的本地化显示文本。 |

**示例：**
  ```ts
  let countryName: string = i18n.getDisplayCountry("zh-CN", "en-GB", true); // countryName = China
  countryName = i18n.getDisplayCountry("zh-CN", "en-GB"); // countryName = China
  ```

## i18n.getDisplayCountry<sup>(deprecated)</sup>

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

获取指定国家的本地化显示文本。

从API version 9开始不再维护，建议使用[System.getDisplayCountry](#getdisplaycountry9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | 是    | 指定国家。            |
| locale       | string  | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。      |
| sentenceCase | boolean | 否    | 本地化显示文本是否要首字母大写。默认值：true。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 指定国家的本地化显示文本。 |

**示例：**
  ```ts
  let countryName: string = i18n.getDisplayCountry("zh-CN", "en-GB", true); // countryName = China
  countryName = i18n.getDisplayCountry("zh-CN", "en-GB"); // countryName = China
  ```


## i18n.getDisplayLanguage<sup>(deprecated)</sup>

getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

获取指定语言的本地化显示文本。

从API version 9开始不再维护，建议使用[System.getDisplayLanguage](#getdisplaylanguage9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| language     | string  | 是    | 指定语言。            |
| locale       | string  | 是    | [表示区域信息的字符串](../../internationalization/i18n-locale-culture.md#实现原理)，由语言、脚本、国家或地区组成。      |
| sentenceCase | boolean | 否    | 本地化显示文本是否要首字母大写。默认值：true。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 指定语言的本地化显示文本。 |

**示例：**
  ```ts
  let languageName: string = i18n.getDisplayLanguage("zh", "en-GB", true); // languageName = "Chinese"
  languageName = i18n.getDisplayLanguage("zh", "en-GB"); // languageName = "Chinese"
  ```


## i18n.getSystemLanguage<sup>(deprecated)</sup>

getSystemLanguage(): string

获取系统语言。

从API version 9开始不再维护，建议使用[System.getSystemLanguage](#getsystemlanguage9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统语言ID。 |

**示例：**
  ```ts
  let systemLanguage: string = i18n.getSystemLanguage(); // 返回当前系统语言
  ```


## i18n.getSystemRegion<sup>(deprecated)</sup>

getSystemRegion(): string

获取系统地区。

从API version 9开始不再维护，建议使用[System.getSystemRegion](#getsystemregion9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统地区ID。 |

**示例：**
  ```ts
  let region: string = i18n.getSystemRegion(); // 返回当前系统地区
  ```


## i18n.getSystemLocale<sup>(deprecated)</sup>

getSystemLocale(): string

获取系统区域。

从API version 9开始不再维护，建议使用[System.getSystemLocale](#getsystemlocale9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 系统区域ID。 |

**示例：**
  ```ts
  let locale: string = i18n.getSystemLocale(); // 返回系统Locale
  ```


## i18n.is24HourClock<sup>(deprecated)</sup>

is24HourClock(): boolean

判断系统时间是否为24小时制。

从API version 9开始不再维护，建议使用[System.is24HourClock](#is24hourclock9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true，表示系统24小时开关开启；返回false，表示系统24小时开关关闭。 |

**示例：**
  ```ts
  let is24HourClock: boolean = i18n.is24HourClock();
  ```


## i18n.set24HourClock<sup>(deprecated)</sup>

set24HourClock(option: boolean): boolean

修改系统时间的24小时制设置。

从API version 9开始不再维护，替代接口仅支持系统应用使用。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型      | 必填   | 说明                                       |
| ------ | ------- | ---- | ---------------------------------------- |
| option | boolean | 是    | option为true，表示开启系统24小时制开关；返回false，表示关闭系统24小时开关。 |

**返回值：**

| 类型      | 说明                            |
| ------- | ----------------------------- |
| boolean | 返回true，表示修改成功；返回false，表示修改失败。 |

**示例：**
  ```ts
  // 将系统时间设置为24小时制
  let success: boolean = i18n.set24HourClock(true);
  ```


## i18n.addPreferredLanguage<sup>(deprecated)</sup>

addPreferredLanguage(language: string, index?: number): boolean

在系统偏好语言列表中的指定位置添加偏好语言。

从API version 8开始支持，从API version 9开始不再维护，替代接口仅支持系统应用使用。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型     | 必填   | 说明         |
| -------- | ------ | ---- | ---------- |
| language | string | 是    | 待添加的偏好语言。  |
| index    | number | 否    | 偏好语言的添加位置。默认值：系统偏好语言列表长度。 |

**返回值：**

| 类型      | 说明                            |
| ------- | ----------------------------- |
| boolean | 返回true，表示添加成功；返回false，表示添加失败。 |

**示例：**
  ```ts
  // 将语言zh-CN添加到系统偏好语言列表中
  let language: string = 'zh-CN';
  let index: number = 0;
  let success: boolean = i18n.addPreferredLanguage(language, index);
  ```


## i18n.removePreferredLanguage<sup>(deprecated)</sup>

removePreferredLanguage(index: number): boolean

删除系统偏好语言列表中指定位置的偏好语言。

从API version 8开始支持，从API version 9开始不再维护，替代接口仅支持系统应用使用。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                    |
| ----- | ------ | ---- | --------------------- |
| index | number | 是    | 待删除偏好语言在系统偏好语言列表中的位置。 |

**返回值：**

| 类型      | 说明                            |
| ------- | ----------------------------- |
| boolean | 返回true，表示删除成功；返回false，表示删除失败。 |

**示例：**
  ```ts
  // 删除系统偏好语言列表中的第一个偏好语言
  let index: number = 0;
  let success: boolean = i18n.removePreferredLanguage(index);
  ```


## i18n.getPreferredLanguageList<sup>(deprecated)</sup>

getPreferredLanguageList(): Array&lt;string&gt;

获取系统偏好语言列表。

从API version 8开始支持，从API version 9开始不再维护，建议使用[System.getPreferredLanguageList](#getpreferredlanguagelist9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                  | 说明        |
| ------------------- | --------- |
| Array&lt;string&gt; | 系统偏好语言列表。 |

**示例：**
  ```ts
  let preferredLanguageList: Array<string> = i18n.getPreferredLanguageList(); // 获取系统偏好语言列表
  ```


## i18n.getFirstPreferredLanguage<sup>(deprecated)</sup>

getFirstPreferredLanguage(): string

获取偏好语言列表中的第一个偏好语言。

从API version 8开始支持，从API version 9开始不再维护，建议使用[System.getFirstPreferredLanguage](#getfirstpreferredlanguage9)代替。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明             |
| ------ | -------------- |
| string | 偏好语言列表中的第一个语言。 |

**示例：**
  ```ts
  let firstPreferredLanguage: string = i18n.getFirstPreferredLanguage();
  ```


## Util<sup>(deprecated)</sup>


### unitConvert<sup>(deprecated)</sup>

unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

将fromUnit的单位转换为toUnit的单位，并根据区域与风格进行格式化。

从API version 8开始支持，从API version 9开始不再维护，建议使用[unitConvert](#unitconvert9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名      | 类型                     | 必填   | 说明                                       |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| fromUnit | [UnitInfo](#unitinfo8) | 是    | 要被转换的单位。                                 |
| toUnit   | [UnitInfo](#unitinfo8) | 是    | 要转换为的单位。                                 |
| value    | number                 | 是    | 要被转换的单位的数量值。                             |
| locale   | string                 | 是    | 格式化时使用的区域参数，如：zh-Hans-CN。                |
| style    | string                 | 否    | 格式化使用的风格，取值包括："long",&nbsp;"short",&nbsp;"narrow"。默认值：short。 |

**返回值：**

| 类型     | 说明                      |
| ------ | ----------------------- |
| string | 按照toUnit的单位格式化后，得到的字符串。 |


## Character<sup>(deprecated)</sup>


### isDigit<sup>(deprecated)</sup>

isDigit(char: string): boolean

判断字符串char是否是数字。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isDigit](#isdigit9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                   |
| ------- | ------------------------------------ |
| boolean | 返回true表示输入的字符是数字，返回false表示输入的字符不是数字。 |


### isSpaceChar<sup>(deprecated)</sup>

isSpaceChar(char: string): boolean

判断字符串char是否是空格符。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isSpaceChar](#isspacechar9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空格符，返回false表示输入的字符不是空格符。 |


### isWhitespace<sup>(deprecated)</sup>

isWhitespace(char: string): boolean

判断字符串char是否是空白符。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isWhitespace](#iswhitespace9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空白符，返回false表示输入的字符不是空白符。 |


### isRTL<sup>(deprecated)</sup>

isRTL(char: string): boolean

判断字符串char是否是从右到左语言的字符。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isRTL](#isrtl9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是从右到左语言的字符，返回false表示输入的字符不是从右到左语言的字符。 |


### isIdeograph<sup>(deprecated)</sup>

isIdeograph(char: string): boolean

判断字符串char是否是表意文字。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isIdeograph](#isideograph9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是表意文字，返回false表示输入的字符不是表意文字。 |


### isLetter<sup>(deprecated)</sup>

isLetter(char: string): boolean

判断字符串char是否是字母。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isLetter](#isletter9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                   |
| ------- | ------------------------------------ |
| boolean | 返回true表示输入的字符是字母，返回false表示输入的字符不是字母。 |


### isLowerCase<sup>(deprecated)</sup>

isLowerCase(char: string): boolean

判断字符串char是否是小写字母。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isLowerCase](#islowercase9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是小写字母，返回false表示输入的字符不是小写字母。 |


### isUpperCase<sup>(deprecated)</sup>

isUpperCase(char: string): boolean

判断字符串char是否是大写字母。

从API version 8开始支持，从API version 9开始不再维护，建议使用[isUpperCase](#isuppercase9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true表示输入的字符是大写字母，返回false表示输入的字符不是大写字母。 |


### getType<sup>(deprecated)</sup>

getType(char: string): string

获取输入字符串的一般类别值。

从API version 8开始支持，从API version 9开始不再维护，建议使用[getType](#gettype9)代替。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| string | 输入字符的一般类别值。 |
