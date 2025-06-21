# @ohos.intl (国际化-Intl)

本模块提供基础的应用国际化能力，包括时间日期格式化、数字格式化、排序等，相关接口在ECMA 402标准中定义。
[I18N模块](js-apis-i18n.md)提供其他非ECMA 402定义的国际化接口，与本模块共同使用可提供完整地国际化支持能力。

>  **说明：**
>
>  - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 本模块接口依据[CLDR](https://cldr.unicode.org) 国际化数据库进行处理。随着CLDR演进，本模块接口处理结果可能发生变化。其中，API version 12对应[CLDR 42](https://cldr.unicode.org/index/downloads/cldr-42)，详细数据变化请参考官方链接。
>
>  - 从API version 11开始，本模块部分接口支持在ArkTS卡片中使用。
>
>  - 从API version 12开始，本模块全接口支持在原子化服务中使用。


## 导入模块

```ts
import { intl } from '@kit.LocalizationKit';
```

## Locale<sup>(deprecated)</sup>

### 属性

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称              | 类型      | 必填   | 说明                                       |
| --------------- | ------- | -------- | ---------------------------------------- |
| language        | string  | 是    | 与区域设置相关的语言，如：zh。取值遵循ISO&nbsp;639标准。 |
| script          | string  | 是    | 区域语言的书写方式（脚本），如：Hans。取值遵循Unicode&nbsp;ISO&nbsp;15924标准。 |
| region          | string  | 是    | 与区域设置相关的国家地区，如：CN。取值遵循ISO&nbsp;3166标准。 |
| baseName        | string  | 是    | 区域对象的基本信息，由语言、脚本、国家地区组成，如：zh-Hans-CN。  |
| caseFirst       | string  | 是    | 区域的排序规则是否考虑大小写，取值包括：<br>"upper"：大写排前面。<br>"lower"：小写排前面。<br>"false"：使用区域默认的大小写排序规则。 |
| calendar        | string  | 是    | 区域的日历信息，取值包括：<br>"buddhist",&nbsp;"chinese",&nbsp;"coptic","dangi",&nbsp;"ethioaa",&nbsp;"ethiopic",&nbsp;"gregory",&nbsp;"hebrew",&nbsp;"indian",&nbsp;"islamic",&nbsp;"islamic-umalqura",&nbsp;"islamic-tbla",&nbsp;"islamic-civil",&nbsp;"islamic-rgsa",&nbsp;"iso8601",&nbsp;"japanese",&nbsp;"persian",&nbsp;"roc",&nbsp;"islamicc"。<br>不同取值表示的含义请参考[设置日历和历法表1](../../internationalization/i18n-calendar.md)。 |
| collation       | string  | 是    | 区域的排序规则，取值包括：<br>"big5han"：拉丁字母使用的拼音排序。<br>"compat"：兼容性排序，仅用于阿拉伯语。<br>"dict"：词典风格排序，仅用于僧伽罗语。<br>"direct"：二进制码点排序。<br>"ducet"：按Unicode排序元素表排序。<br>"eor"：按欧洲排序规则排序。<br>"gb2312"：拼音排序，仅用于中文排序。<br>"phonebk"：电话本风格排序。<br>"phonetic"：发音排序。<br>"pinyin"：拼音排序。<br>"reformed"：瑞典语排序。<br>"searchjl"：韩语初始辅音搜索的特殊排序。<br>"stroke"：汉语的笔画排序。<br>"trad"：传统风格排序，如西班牙语。<br>"unihan"：统一汉字排序，用于日语、韩语、中文等汉字排序。<br>"zhuyin"：注音排序，仅用于中文排序。 |
| hourCycle       | string  | 是    | 区域的时制信息，取值包括：<br>"h11"、"h12"、"h23"、"h24"。<br>不同取值的显示效果可参考[时间日期国际化表5](../../internationalization/i18n-time-date.md)。 |
| numberingSystem | string  | 是    | 区域使用的数字系统，取值包括：<br>"adlm",&nbsp;"ahom",&nbsp;"arab",&nbsp;"arabext",&nbsp;"bali",&nbsp;"beng",&nbsp;"bhks",&nbsp;"brah",&nbsp;"cakm",&nbsp;"cham",&nbsp;"deva",&nbsp;"diak",&nbsp;"fullwide",&nbsp;"gong",&nbsp;"gonm",&nbsp;"gujr",&nbsp;"guru",&nbsp;"hanidec",&nbsp;"hmng",&nbsp;"hmnp",&nbsp;"java",&nbsp;"kali",&nbsp;"khmr",&nbsp;"knda",&nbsp;"lana",&nbsp;"lanatham",&nbsp;"laoo",&nbsp;"latn",&nbsp;"lepc",&nbsp;"limb",&nbsp;"mathbold",&nbsp;"mathdbl",&nbsp;"mathmono",&nbsp;"mathsanb",&nbsp;"mathsans",&nbsp;"mlym",&nbsp;"modi",&nbsp;"mong",&nbsp;"mroo",&nbsp;"mtei",&nbsp;"mymr",&nbsp;"mymrshan",&nbsp;"mymrtlng",&nbsp;"newa",&nbsp;"nkoo",&nbsp;"olck",&nbsp;"orya",&nbsp;"osma",&nbsp;"rohg",&nbsp;"saur",&nbsp;"segment",&nbsp;"shrd",&nbsp;"sind",&nbsp;"sinh",&nbsp;"sora",&nbsp;"sund",&nbsp;"takr",&nbsp;"talu",&nbsp;"tamldec",&nbsp;"telu",&nbsp;"thai",&nbsp;"tibt",&nbsp;"tirh",&nbsp;"vaii",&nbsp;"wara",&nbsp;"wcho"。 |
| numeric         | boolean | 是    | true表示对数字字符进行特殊的排序规则处理，false表示不对数字字符进行特殊的排序规则处理。<br>默认值：false。                      |

### constructor<sup>(deprecated)</sup>

constructor()

从API version 8开始支持，从API version 20开始废弃，建议使用[Intl.Locale() constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/Locale)替代。

创建区域对象。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**示例：**
  ```ts
  // 默认构造函数使用系统当前区域ID创建
  let locale = new intl.Locale();
  // 返回系统当前区域ID
  let localeID = locale.toString();
  ```

### constructor<sup>(deprecated)</sup>

constructor(locale: string, options?: LocaleOptions)

从API version 8开始支持，从API version 20开始废弃，建议使用[Intl.Locale() constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/Locale)替代。

创建区域对象。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名                  | 类型                               | 必填   | 说明                           |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string                           | 是    | 表示区域ID的字符串，由语言、脚本、国家地区组成。|
| options             | [LocaleOptions](#localeoptionsdeprecated) | 否    | 创建区域对象的选项。 |

**示例：**
  ```ts
  // 创建zh-CN区域对象
  let locale = new intl.Locale("zh-CN");
  let localeID = locale.toString(); // localeID = "zh-CN"
  ```


### toString<sup>(deprecated)</sup>

toString(): string

从API version 8开始支持，从API version 20开始废弃，建议使用[Intl.Locale.prototype.toString()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/toString)替代。

获取区域对象的字符串。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| string | 区域对象的字符串。 |

**示例：**
  ```ts
  // 创建en-GB区域对象
  let locale = new intl.Locale("en-GB");
  let localeID = locale.toString(); // localeID = "en-GB"
  ```

### maximize<sup>(deprecated)</sup>

maximize(): Locale

从API version 8开始支持，从API version 20开始废弃，建议使用[Intl.Locale.prototype.maximize()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/maximize)替代。

最大化区域信息，补齐区域对象中缺少的脚本、国家地区信息。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                | 说明         |
| ----------------- | ---------- |
| [Locale](#localedeprecated) | 补齐完脚本、国家地区信息后的区域对象。 |

**示例：**
  ```ts
  // 创建zh区域对象
  let locale = new intl.Locale("zh");
  // 补齐区域对象的脚本和地区
  let maximizedLocale = locale.maximize();
  let localeID = maximizedLocale.toString(); // localeID = "zh-Hans-CN"

  // 创建en-US区域对象
  locale = new intl.Locale("en-US");
  // 补齐区域对象的脚本
  maximizedLocale = locale.maximize();
  localeID = maximizedLocale.toString(); // localeID = "en-Latn-US"
  ```


### minimize<sup>(deprecated)</sup>

minimize(): Locale

从API version 8开始支持，从API version 20开始废弃，建议使用[Intl.Locale.prototype.minimize()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/minimize)替代。

最小化区域信息，移除区域对象中的脚本、国家地区信息。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                | 说明         |
| ----------------- | ---------- |
| [Locale](#localedeprecated) | 移除完脚本、国家地区信息后的区域对象。 |

**示例：**
  ```ts
  // 创建zh-Hans-CN区域对象
  let locale = new intl.Locale("zh-Hans-CN");
  // 移除区域对象的脚本和地区
  let minimizedLocale = locale.minimize();
  let localeID = minimizedLocale.toString(); // localeID = "zh"

  // 创建en-US区域对象
  locale = new intl.Locale("en-US");
  // 移除区域对象的地区
  minimizedLocale = locale.minimize();
  localeID = minimizedLocale.toString(); // localeID = "en"
  ```

## LocaleOptions<sup>(deprecated)</sup>

区域初始化选项。从API version 9开始，LocaleOptions属性由必填改为可选。从API version 8开始支持，从API version 20开始废弃，以calendar为例，建议使用[Intl.Locale.prototype.calendar()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/calendar)替代。

**卡片能力**：从API version 11开始，该类型支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称              | 类型      | 必填   |  说明                                       |
| --------------- | ------- | ---- |---------------------------------------- |
| calendar        | string  | 否   |日历参数，取值包括：<br>"buddhist", "chinese", "coptic", "dangi", "ethioaa", "ethiopic", "gregory", "hebrew", "indian", "islamic", "islamic-umalqura", "islamic-tbla", "islamic-civil", "islamic-rgsa", "iso8601", "japanese", "persian", "roc", "islamicc"。 |
| collation       | string  | 否     |区域的排序规则，取值包括：<br>"big5han"：拉丁字母使用的拼音排序。<br>"compat"：兼容性排序，仅用于阿拉伯语。<br>"dict"：词典风格排序，仅用于僧伽罗语。<br>"direct"：二进制码点排序。<br>"ducet"：按Unicode排序元素表排序。<br>"eor"：按欧洲排序规则排序。<br>"gb2312"：拼音排序，仅用于中文排序。<br>"phonebk"：电话本风格排序。<br>"phonetic"：发音排序。<br>"pinyin"：拼音排序。<br>"reformed"：瑞典语排序。<br>"searchjl"：韩语初始辅音搜索的特殊排序。<br>"stroke"：汉语的笔画排序。<br>"trad"：传统风格排序，如西班牙语。<br>"unihan"：统一汉字排序，用于日语、韩语、中文等汉字排序。<br>"zhuyin"：注音排序，仅用于中文排序。 |
| hourCycle       | string  | 否     |时制格式，取值包括：<br>"h11",&nbsp;"h12",&nbsp;"h23",&nbsp;"h24"。 |
| numberingSystem | string  | 否     |数字系统，取值包括：<br>"adlm",&nbsp;"ahom",&nbsp;"arab",&nbsp;"arabext",&nbsp;"bali",&nbsp;"beng",&nbsp;"bhks",&nbsp;"brah",&nbsp;"cakm",&nbsp;"cham",&nbsp;"deva",&nbsp;"diak",&nbsp;"fullwide",&nbsp;"gong",&nbsp;"gonm",&nbsp;"gujr",&nbsp;"guru",&nbsp;"hanidec",&nbsp;"hmng",&nbsp;"hmnp",&nbsp;"java",&nbsp;"kali",&nbsp;"khmr",&nbsp;"knda",&nbsp;"lana",&nbsp;"lanatham",&nbsp;"laoo",&nbsp;"latn",&nbsp;"lepc",&nbsp;"limb",&nbsp;"mathbold",&nbsp;"mathdbl",&nbsp;"mathmono",&nbsp;"mathsanb",&nbsp;"mathsans",&nbsp;"mlym",&nbsp;"modi",&nbsp;"mong",&nbsp;"mroo",&nbsp;"mtei",&nbsp;"mymr",&nbsp;"mymrshan",&nbsp;"mymrtlng",&nbsp;"newa",&nbsp;"nkoo",&nbsp;"olck",&nbsp;"orya",&nbsp;"osma",&nbsp;"rohg",&nbsp;"saur",&nbsp;"segment",&nbsp;"shrd",&nbsp;"sind",&nbsp;"sinh",&nbsp;"sora",&nbsp;"sund",&nbsp;"takr",&nbsp;"talu",&nbsp;"tamldec",&nbsp;"telu",&nbsp;"thai",&nbsp;"tibt",&nbsp;"tirh",&nbsp;"vaii",&nbsp;"wara",&nbsp;"wcho"。 |
| numeric         | boolean | 否     | true表示对数字字符进行特殊的排序规则处理，false表示不对数字字符进行特殊的排序规则处理。默认值：false。                               |
| caseFirst       | string  | 否     | 区域的排序规则是否考虑大小写，取值包括：<br>"upper"：大写排前面。<br>"lower"：小写排前面。<br>"false"：使用区域默认的大小写排序规则。 |

>  **说明：**
>
>  - calendar：不同取值的含义请参考[设置日历和历法表1](../../internationalization/i18n-calendar.md)。
>
>  - hourCycle：不同取值的显示效果请参考[时间日期国际化表5](../../internationalization/i18n-time-date.md)。

## DateTimeFormat

### constructor<sup>8+</sup>

constructor()

创建时间、日期格式化对象。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**示例：**
  ```ts
  // 使用系统当前区域ID创建DateTimeFormat对象
  let datefmt= new intl.DateTimeFormat();
  ```

### constructor

constructor(locale: string | Array&lt;string&gt;, options?: DateTimeOptions)

创建时间、日期格式化对象。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名                  | 类型                                   | 必填   | 说明                           |
| -------------------- | ------------------------------------ | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;        | 是    | 区域ID或区域ID数组。输入是区域ID数组时，使用第一个有效的区域ID。 |
| options              | [DateTimeOptions](#datetimeoptions) | 否    | 创建时间、日期格式化对象时可设置的配置项。<br>若所有选项均未设置时，year、month、day三个属性的默认值为numeric。 |

**示例：**
  ```ts
  // 使用zh-CN区域ID创建DateTimeFormat对象，日期风格为full，时间风格为medium
  let datefmt= new intl.DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });

  // 使用区域ID列表创建DateTimeFormat对象，因为ban为非法区域ID，因此使用zh区域ID创建DateTimeFormat对象
  let datefmt= new intl.DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
  ```

### format

format(date: Date): string

对时间、日期进行格式化。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型   | 必填   | 说明      |
| ---- | ---- | ---- | ------- |
| date | Date | 是    | 时间、日期。说明：月份从0开始计数，例如0表示一月。 |

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 格式化后的时间、日期字符串。 |

**示例：**
  ```ts
  let date = new Date(2021, 11, 17, 3, 24, 0); // 时间日期为2021.12.17 03:24:00
  // 使用en-GB区域ID创建DateTimeFormat对象
  let datefmt = new intl.DateTimeFormat("en-GB");
  let formattedDate = datefmt.format(date); // formattedDate "17/12/2021"

  // 使用en-GB区域ID创建DateTimeFormat对象，dateStyle设置为full，timeStyle设置为medium
  datefmt = new intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });
  formattedDate = datefmt.format(date); // formattedDate "Friday, 17 December 2021 at 03:24:00"
  ```

### formatRange

formatRange(startDate: Date, endDate: Date): string

对时间段、日期段进行格式化。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名       | 类型   | 必填   | 说明       |
| --------- | ---- | ---- | -------- |
| startDate | Date | 是    | 时间、日期的开始。说明：月份从0开始计数，例如0表示一月。|
| endDate   | Date | 是    | 时间、日期的结束。说明：月份从0开始计数，例如0表示一月。|

**返回值：**

| 类型     | 说明             |
| ------ | -------------- |
| string | 格式化后的时间段、日期段字符串。 |

**示例：**
  ```ts
  let startDate = new Date(2021, 11, 17, 3, 24, 0); // 时间日期为2021.12.17 03:24:00
  let endDate = new Date(2021, 11, 18, 3, 24, 0);
  // 使用en-GB区域ID创建DateTimeFormat对象
  let datefmt = new intl.DateTimeFormat("en-GB");
  let formattedDateRange = datefmt.formatRange(startDate, endDate); // formattedDateRange = "17/12/2021 - 18/12/2021"
  ```

### resolvedOptions

resolvedOptions(): DateTimeOptions

获取创建时间、日期格式化对象时设置的配置项。

**卡片能力**：从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                                   | 说明                            |
| ------------------------------------ | ----------------------------- |
| [DateTimeOptions](#datetimeoptions) | 时间、日期格式化对象设置的配置项。 |

**示例：**
  ```ts
  let datefmt = new intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });
  // 返回DateTimeFormat对象的配置项
  let options = datefmt.resolvedOptions();
  let dateStyle = options.dateStyle; // dateStyle = "full"
  let timeStyle = options.timeStyle; // timeStyle = "medium"
  ```


## DateTimeOptions

时间、日期格式化时可设置的配置项。从API version 9开始，DateTimeOptions的属性由必填改为可选。

**卡片能力**：从API version 11开始，该类型支持在ArkTS卡片中使用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称              | 类型      | 必填   | 说明                                       |
| --------------- | ------- | ---- |  ---------------------------------------- |
| locale          | string  | 否    |合法的区域ID，如：zh-Hans-CN。<br>默认值：系统当前区域ID。           |
| dateStyle       | string  | 否     |日期显示格式，取值包括：<br>"long",&nbsp;"short",&nbsp;"medium",&nbsp;"full",&nbsp;"auto"。<br>不同取值的显示效果请参考[时间日期国际化表1](../../internationalization/i18n-time-date.md)。 |
| timeStyle       | string  | 否     |时间显示格式，取值包括：<br>"long",&nbsp;"short",&nbsp;"medium",&nbsp;"full",&nbsp;"auto"。<br>不同取值的显示效果请参考[时间日期国际化表2](../../internationalization/i18n-time-date.md)。 |
| hourCycle       | string  | 否     |时制格式，取值包括：<br>"h11",&nbsp;"h12",&nbsp;"h23",&nbsp;"h24"。<br>不设置dateStyle或timeStyle参数时的显示效果请参考[时间日期国际化表5](../../internationalization/i18n-time-date.md)。<br>设置dateStyle或timeStyle参数时的显示效果请参考[时间日期国际化表6](../../internationalization/i18n-time-date.md)。 |
| timeZone        | string  | 否     |使用的时区，取值为合法的IANA时区ID。                      |
| numberingSystem | string  | 否     |数字系统，取值包括：<br>"adlm",&nbsp;"ahom",&nbsp;"arab",&nbsp;"arabext",&nbsp;"bali",&nbsp;"beng",&nbsp;"bhks",&nbsp;"brah",&nbsp;"cakm",&nbsp;"cham",&nbsp;"deva",&nbsp;"diak",&nbsp;"fullwide",&nbsp;"gong",&nbsp;"gonm",&nbsp;"gujr",&nbsp;"guru",&nbsp;"hanidec",&nbsp;"hmng",&nbsp;"hmnp",&nbsp;"java",&nbsp;"kali",&nbsp;"khmr",&nbsp;"knda",&nbsp;"lana",&nbsp;"lanatham",&nbsp;"laoo",&nbsp;"latn",&nbsp;"lepc",&nbsp;"limb",&nbsp;"mathbold",&nbsp;"mathdbl",&nbsp;"mathmono",&nbsp;"mathsanb",&nbsp;"mathsans",&nbsp;"mlym",&nbsp;"modi",&nbsp;"mong",&nbsp;"mroo",&nbsp;"mtei",&nbsp;"mymr",&nbsp;"mymrshan",&nbsp;"mymrtlng",&nbsp;"newa",&nbsp;"nkoo",&nbsp;"olck",&nbsp;"orya",&nbsp;"osma",&nbsp;"rohg",&nbsp;"saur",&nbsp;"segment",&nbsp;"shrd",&nbsp;"sind",&nbsp;"sinh",&nbsp;"sora",&nbsp;"sund",&nbsp;"takr",&nbsp;"talu",&nbsp;"tamldec",&nbsp;"telu",&nbsp;"thai",&nbsp;"tibt",&nbsp;"tirh",&nbsp;"vaii",&nbsp;"wara",&nbsp;"wcho"。 |
| hour12          | boolean | 否     | true表示使用12小时制，false表示使用24小时制。<br>同时设置hour12和hourCycle时，hourCycle不生效。<br>若hour12和hourCycle未设置且系统24小时开关打开时，hour12属性的默认值为false。|
| weekday         | string  | 否     | 星期的显示格式，取值包括：<br>"long",&nbsp;"short",&nbsp;"narrow",&nbsp;"auto"。<br>不同取值的显示效果请参考[时间日期国际化表4](../../internationalization/i18n-time-date.md)。 |
| era             | string  | 否     | 纪元的显示格式，取值包括：<br>"long",&nbsp;"short",&nbsp;"narrow",&nbsp;"auto"。<br>不同取值的显示效果请参考[时间日期国际化表9](../../internationalization/i18n-time-date.md)。 |
| year            | string  | 否     | 年份的显示格式，取值包括：<br>"numeric",&nbsp;"2-digit"。<br>不同取值的显示效果请参考[时间日期国际化表3](../../internationalization/i18n-time-date.md)。  |
| month           | string  | 否    | 月份的显示格式，取值包括：<br>"numeric",&nbsp;"2-digit",&nbsp;"long",&nbsp;"short",&nbsp;"narrow",&nbsp;"auto"。<br>不同取值的显示效果请参考[时间日期国际化表6](../../internationalization/i18n-time-date.md)。 |
| day             | string  | 否     | 日期的显示格式，取值包括：<br>"numeric",&nbsp;"2-digit"。  |
| hour            | string  | 否     | 小时的显示格式，取值包括：<br>"numeric",&nbsp;"2-digit"。  |
| minute          | string  | 否     | 分钟的显示格式，取值包括：<br>"numeric",&nbsp;"2-digit"。  |
| second          | string  | 否     | 秒钟的显示格式，取值包括：<br>"numeric",&nbsp;"2-digit"。  |
| timeZoneName    | string  | 否     | 时区名称的本地化表示，取值包括：<br>"long",&nbsp;"short",&nbsp;"auto"。<br>不同取值的显示效果请参考[时间日期国际化表8](../../internationalization/i18n-time-date.md)。   |
| dayPeriod       | string  | 否     | 时段的显示格式，取值包括：<br>"long",&nbsp;"short",&nbsp;"narrow",&nbsp;"auto"。<br>不同取值的显示效果请参考[时间日期国际化表10](../../internationalization/i18n-time-date.md)。 |
| localeMatcher   | string  | 否     | 要使用的区域匹配算法，取值包括：<br>"lookup"：精确匹配。<br>"best&nbsp;fit"：最佳匹配。 |
| formatMatcher   | string  | 否     | 要使用的格式匹配算法，取值包括：<br>"basic"：精确匹配。<br>"best&nbsp;fit"：最佳匹配。 |

## NumberFormat

### constructor<sup>8+</sup>

constructor()

创建数字格式化对象。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**示例：**
  ```ts
  // 使用系统当前区域ID创建NumberFormat对象
  let numfmt = new intl.NumberFormat();
  ```


### constructor

constructor(locale: string | Array&lt;string&gt;, options?: NumberOptions)

创建数字格式化对象。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名                  | 类型                               | 必填   | 说明                           |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;    | 是    | 区域ID或区域ID数组。输入是区域ID数组时，使用第一个有效的区域ID。 |
| options              | [NumberOptions](#numberoptions) | 否    | 创建数字格式化对象时可设置的配置项。               |

**示例：**
  ```ts
  // 使用en-GB区域ID创建NumberFormat对象，style设置为decimal，notation设置为scientific
  let numfmt = new intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
  ```

### format

format(number: number): string

对数字进行格式化。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明   |
| ------ | ------ | ---- | ---- |
| number | number | 是    | 数字对象。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 格式化后的数字字符串。 |


**示例：**
  ```ts
  // 使用区域ID列表创建NumberFormat对象，因为en-GB为合法的区域ID，因此使用en-GB创建NumberFormat对象
  let numfmt : intl.NumberFormat = new intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  let formattedNumber : string = numfmt.format(1223); // formattedNumber = 1.223E3
  let options : intl.NumberOptions = {
    roundingPriority: "lessPrecision",
    maximumFractionDigits: 3,
    maximumSignificantDigits: 3
  }
  let numberFmt : intl.NumberFormat = new intl.NumberFormat("en", options);
  let result : string = numberFmt.format(1.23456); // result = 1.23
  ```

### formatRange<sup>18+</sup>

formatRange(startRange: number, endRange: number): string

对数字范围进行格式化。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明   |
| ------ | ------ | ---- | ---- |
| startRange | number | 是    | 开始数字。 |
| endRange | number | 是    | 结束数字。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 格式化后的数字范围字符串。 |


**示例：**
  ```ts
  let numfmt : intl.NumberFormat = new intl.NumberFormat("en-US", {style:'unit', unit:"meter"});
  let formattedRange : string = numfmt.formatRange(0, 3); // formattedRange: 0–3 m
  ```


### resolvedOptions

resolvedOptions(): NumberOptions

获取创建数字格式化对象时设置的配置项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                               | 说明                          |
| -------------------------------- | --------------------------- |
| [NumberOptions](#numberoptions) | 创建数字格式化对象时设置的配置项。 |


**示例：**
  ```ts
  let numfmt = new intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  // 获取NumberFormat对象配置项
  let options = numfmt.resolvedOptions();
  let style = options.style; // style = decimal
  let notation = options.notation; // notation = scientific
  ```

## NumberOptions

创建数字格式化对象时可设置的配置项。从API version 9开始，NumberOptions的属性由必填改为可选。

**系统能力**：SystemCapability.Global.I18n

| 名称                       | 类型      | 必填   |  说明                                       |
| ------------------------ | ------- | ---- |  ---------------------------------------- |
| locale                   | string  | 否    | 合法的区域ID，&nbsp;如："zh-Hans-CN"。<br>默认值：系统当前区域ID。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。               |
| currency                 | string  | 否    | 货币单位，&nbsp;取值符合[ISO-4217标准](https://www.iso.org/iso-4217-currency-codes.html)，如："EUR"，"CNY"，"USD"等。<br>从API version 12开始支持三位数字代码，如："978"，"156"，"840"等。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。    |
| currencySign             | string  | 否    | 货币单位的符号显示，取值包括：&nbsp;"standard"，"accounting"。<br>默认值：standard。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| currencyDisplay          | string  | 否    | 货币的显示方式，取值包括："symbol",&nbsp;"narrowSymbol",&nbsp;"code",&nbsp;"name"。<br>默认值：symbol。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| unit                     | string  | 否    | 单位名称，如："meter"，"inch"，“hectare”等。<br>从API version 18开始新增支持的组合单位有： "beat-per-minute", "body-weight-per-second", "breath-per-minute", "foot-per-hour", "jump-rope-per-minute", "meter-per-hour", "milliliter-per-minute-per-kilogram", "rotation-per-minute", "step-per-minute", "stroke-per-minute"。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。       |
| unitDisplay              | string  | 否    | 单位的显示格式，取值包括："long",&nbsp;"short",&nbsp;"narrow"。<br>默认值：short。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| unitUsage<sup>8+</sup>   | string  | 否    | 单位的使用场景，取值包括："default",&nbsp;"area-land-agricult",&nbsp;"area-land-commercl",&nbsp;"area-land-residntl",&nbsp;"length-person",&nbsp;"length-person-small",&nbsp;"length-rainfall",&nbsp;"length-road",&nbsp;"length-road-small",&nbsp;"length-snowfall",&nbsp;"length-vehicle",&nbsp;"length-visiblty",&nbsp;"length-visiblty-small",&nbsp;"length-person-informal",&nbsp;"length-person-small-informal",&nbsp;"length-road-informal",&nbsp;"speed-road-travel",&nbsp;"speed-wind",&nbsp;"temperature-person",&nbsp;"temperature-weather",&nbsp;"volume-vehicle-fuel",&nbsp;"elapsed-time-second",&nbsp;"size-file-byte",&nbsp;"size-shortfile-byte"。<br>默认值：default。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| signDisplay              | string  | 否    | 数字符号的显示格式，取值包括：<br>"auto"：自动判断是否显示正负符号。<br>"never"：不显示正负号。<br>"always"：总是显示正负号。<br>"exceptZero"：除了0都显示正负号。<br>默认值："auto"。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| compactDisplay           | string  | 否    | 紧凑显示格式，取值包括："long",&nbsp;"short"。<br>默认值：short。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。      |
| notation                 | string  | 否    | 数字的表示方法，取值包括："standard",&nbsp;"scientific",&nbsp;"engineering",&nbsp;"compact"。<br>默认值：standard。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| localeMatcher            | string  | 否    | 要使用的区域匹配算法，取值包括："lookup",&nbsp;"best&nbsp;fit"。<br>默认值：best fit。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| style                    | string  | 否    | 数字的显示格式，取值包括："decimal",&nbsp;"currency",&nbsp;"percent",&nbsp;"unit"。<br>默认值：decimal。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| numberingSystem          | string  | 否    | 数字系统，取值包括：<br>"adlm",&nbsp;"ahom",&nbsp;"arab",&nbsp;"arabext",&nbsp;"bali",&nbsp;"beng",&nbsp;"bhks",&nbsp;"brah",&nbsp;"cakm",&nbsp;"cham",&nbsp;"deva",&nbsp;"diak",&nbsp;"fullwide",&nbsp;"gong",&nbsp;"gonm",&nbsp;"gujr",&nbsp;"guru",&nbsp;"hanidec",&nbsp;"hmng",&nbsp;"hmnp",&nbsp;"java",&nbsp;"kali",&nbsp;"khmr",&nbsp;"knda",&nbsp;"lana",&nbsp;"lanatham",&nbsp;"laoo",&nbsp;"latn",&nbsp;"lepc",&nbsp;"limb",&nbsp;"mathbold",&nbsp;"mathdbl",&nbsp;"mathmono",&nbsp;"mathsanb",&nbsp;"mathsans",&nbsp;"mlym",&nbsp;"modi",&nbsp;"mong",&nbsp;"mroo",&nbsp;"mtei",&nbsp;"mymr",&nbsp;"mymrshan",&nbsp;"mymrtlng",&nbsp;"newa",&nbsp;"nkoo",&nbsp;"olck",&nbsp;"orya",&nbsp;"osma",&nbsp;"rohg",&nbsp;"saur",&nbsp;"segment",&nbsp;"shrd",&nbsp;"sind",&nbsp;"sinh",&nbsp;"sora",&nbsp;"sund",&nbsp;"takr",&nbsp;"talu",&nbsp;"tamldec",&nbsp;"telu",&nbsp;"thai",&nbsp;"tibt",&nbsp;"tirh",&nbsp;"vaii",&nbsp;"wara",&nbsp;"wcho"。<br>默认值：区域的默认数字系统。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| useGrouping              | boolean | 否    | true表示分组显示，false表示不分组显示。<br>默认值：true。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                                  |
| minimumIntegerDigits     | number  | 否    | 表示要使用的最小整数位数，取值范围：1~21。<br>默认值：1。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                  |
| minimumFractionDigits    | number  | 否    | 表示要使用的最小分数位数，取值范围：0~20。<br>默认值：0。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                  |
| maximumFractionDigits    | number  | 否    | 表示要使用的最大分数位数，取值范围：1~21。<br>默认值：3。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                  |
| minimumSignificantDigits | number  | 否    | 表示要使用的最小有效位数，取值范围：1~21。<br>默认值：1。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                  |
| maximumSignificantDigits | number  | 否    | 表示要使用的最大有效位数，取值范围：1~21。<br>默认值：21。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                  |
| roundingPriority<sup>18+</sup>   | string  | 否    | 最大分数位数和最大有效位数同时设置时的舍入优先级，取值包括："auto"，"morePrecision"&nbsp;取最大分数位数，"lessPrecision"&nbsp;取最大有效位数。<br>默认值：auto。<br>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。                  |
| roundingIncrement<sup>18+</sup>  | number  | 否    | 表示舍入增量，取值范围：1，2，5，10，20，25，50，100，200，250，500，1000，2000，2500，5000。<br>默认值：1。<br>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。                  |
| roundingMode<sup>18+</sup>       | string  | 否    | 表示舍入模式，取值包括：<br>"ceil"：向上取整。<br>"floor"：向下取整。<br>"expand"：远离零取整。<br>"trunc"：向零取整。<br>"halfCeil"：半向上取整，大于等于增量的一半时向上取整，小于增量的一半时向下取整。<br>"halfFloor"：半向下取整，大于增量的一半时向上取整，小于等于增量的一半时向下取整。<br>"halfExpand"：半远离零取整，大于等于增量的一半时远离零取整，小于增量的一半时向零取整。<br>"halfTrunc"：半向零取整，大于增量的一半时远离零取整，小于等于增量的一半时向零取整。<br>"halfEven"：半向偶数取整，大于增量的一半时 远离零取整，小于增量的一半时向零取整，等于增量的一半时向最近的偶数位舍入。<br>默认值：halfExpand。<br>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。 |

>  **说明：**
>
>  - 各属性不同取值代表的含义或呈现效果，请参考[数字与度量衡国际化](../../internationalization/i18n-numbers-weights-measures.md)。

## Collator<sup>(deprecated)</sup>

### constructor<sup>(deprecated)</sup>

constructor()

从API version 8开始支持，从API version 20开始不再维护，建议使用[Intl.Collator() constructor](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator)代替。

创建排序对象。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**示例：**
  ```ts
  // 使用系统区域创建Collator对象
  let collator = new intl.Collator();
  ```


### constructor<sup>(deprecated)</sup>

constructor(locale: string | Array&lt;string&gt;, options?: CollatorOptions)

从API version 8开始支持，从API version 20开始不再维护，建议使用[Intl.Collator](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator)代替。

创建排序对象。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名                  | 类型                                   | 必填   | 说明                           |
| -------------------- | ------------------------------------ | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;        | 是    | 区域ID或区域ID数组。输入是区域ID数组时，使用第一个有效的区域ID。  |
| options              | [CollatorOptions](#collatoroptionsdeprecated) | 否    | 创建排序对象时可设置的配置项。       |

**示例：**
  ```ts
  // 使用zh-CN区域ID创建Collator对象，localeMatcher设置为lookup，usage设置为sort
  let collator = new intl.Collator("zh-CN", {localeMatcher: "lookup", usage: "sort"});
  ```


### compare<sup>(deprecated)</sup>

compare(first: string, second: string): number

从API version 8开始支持，从API version 20开始不再维护，建议使用[Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/compare)代替。

根据配置项的排序规则，比较两个字符串。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名    | 类型     | 必填   | 说明           |
| ------ | ------ | ---- | ------------ |
| first  | string | 是    | 进行比较的第一个字符串。  |
| second | string | 是    | 进行比较的第二个字符串。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 比较结果。<br>- number为负数时，表示first排序在second之前。<br>- number为0时，表示first与second排序相同。<br>- number为正数，表示first排序在second之后。 |

**示例：**
  ```ts
  // 使用en-GB区域ID创建Collator对象
  let collator = new intl.Collator("en-GB");
  // 比较first和second的先后顺序
  let compareResult = collator.compare("first", "second"); // compareResult = -1
  ```


### resolvedOptions<sup>(deprecated)</sup>

resolvedOptions(): CollatorOptions

从API version 8开始支持，从API version 20开始不再维护，建议使用[Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/resolvedOptions)代替。

获取创建排序对象时设置的配置项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                                   | 说明                |
| ------------------------------------ | ----------------- |
| [CollatorOptions](#collatoroptionsdeprecated) | 返回排序对象的属性。 |

**示例：**
  ```ts
  let collator = new intl.Collator("zh-Hans", { usage: 'sort', ignorePunctuation: true });
  // 获取Collator对象的配置项
  let options = collator.resolvedOptions();
  let usage = options.usage; // usage = "sort"
  let ignorePunctuation = options.ignorePunctuation; // ignorePunctuation = true
  ```


## CollatorOptions<sup>(deprecated)</sup>

从API version 8开始支持，从API version 20开始不再维护。

创建排序对象时可设置的配置项。

从API version 9中，CollatorOptions中的属性改为可选。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称                | 类型      | 必填   | 说明                                       |
| ----------------- | ------- | ---- | ---------------------------------------- |
| localeMatcher     | string  | 否    | 区域匹配算法，取值范围：<br>"lookup"：模糊匹配。<br>"best fit"：准确匹配。<br>默认值："best fit"。 |
| usage             | string  | 否    | 比较的用途，取值范围：<br>"sort"：用作排序。<br>"search"：用作查找匹配的字符串。<br>默认值："sort"。        |
| sensitivity       | string  | 否    | 表示字符串中的哪些差异会导致非零结果值，取值范围：<br>"base"：不同的字母比较不相等，比如：'a' ≠ 'b', 'a' = 'á', 'a' = 'A'。<br>"accent"：不同的字母或不同读音的相同字母比较不相等，比如'a' ≠ 'b', 'a' ≠ 'á', 'a' = 'A'。<br>"case"：不同的字母或相同字母大小写比较不相等，比如：'a' ≠ 'b', 'a' = 'á', 'a' ≠ 'A'。<br>"variant"：不同的字母或读音及其它有区别的标志或大小写都是不相等的，比如：'a' ≠ 'b', 'a' ≠ 'á', 'a' ≠ 'A'。<br>默认值："variant"。        |
| collation         | string  | 否    | 区域的排序规则，取值包括：<br>"big5han"：拉丁字母使用的拼音排序。<br>"compat"：兼容性排序，仅用于阿拉伯语。<br>"dict"：词典风格排序，仅用于僧伽罗语。<br>"direct"：二进制码点排序。<br>"ducet"：按Unicode排序元素表排序。<br>"eor"：按欧洲排序规则排序。<br>"gb2312"：拼音排序，仅用于中文排序。<br>"phonebk"：电话本风格排序。<br>"phonetic"：发音排序。<br>"pinyin"：拼音排序。<br>"reformed"：瑞典语排序。<br>"searchjl"：韩语初始辅音搜索的特殊排序。<br>"stroke"：汉语的笔画排序。<br>"trad"：传统风格排序，如西班牙语。<br>"unihan"：统一汉字排序，用于日语、韩语、中文等汉字排序。<br>"zhuyin"：注音排序，仅用于中文排序。<br>默认值："default"。 |
| numeric           | boolean | 否    | 数字排序，取值包括：<br>true：使用数字排序，比如：'1' &lt; '2' &lt; '10' &lt; '11'。<br>false：不使用数字排序，比如：'1' &lt; '10' &lt; '11' &lt; '2'。<br>默认值：false。          |
| caseFirst         | string  | 否    | 区域的排序规则是否考虑大小写，取值包括：<br>"upper"：大写排前面。<br>"lower"：小写排前面。<br>"false"：使用区域默认的大小写排序规则。<br>默认值："false"。 |


## PluralRules<sup>8+</sup>

### constructor<sup>8+</sup>

constructor()

创建单复数对象来计算数字的单复数类别。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**示例：**
  ```ts
  // 使用系统区域创建PluralRules对象
  let pluralRules = new intl.PluralRules();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: PluralRulesOptions)

创建单复数对象来计算数字的单复数类别。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名                  | 类型                                       | 必填   | 说明                           |
| -------------------- | ---------------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;            | 是    | 区域ID或区域ID数组。输入是区域ID数组时，使用第一个有效的区域ID。 |
| options              | [PluralRulesOptions](#pluralrulesoptions8) | 否    | 创建单复数对象时设置的配置项。       |

**示例：**
  ```ts
  // 使用zh-CN区域ID创建PluralRules对象，localeMatcher设置为lookup，type设置为cardinal
  let pluralRules= new intl.PluralRules("zh-CN", {"localeMatcher": "lookup", "type": "cardinal"});
  ```

### select<sup>8+</sup>

select(n: number): string

获取数字的单复数类别。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名  | 类型     | 必填   | 说明           |
| ---- | ------ | ---- | ------------ |
| n    | number | 是    | 待获取单复数类别的数字。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| string | 单复数类别，取值包括："zero"，"one"，"two",&nbsp;"few",&nbsp;"many",&nbsp;"others"。 <br>不同取值的含义请参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。|

**示例：**
  ```ts
  // 使用zh-Hans区域ID创建PluralRules对象
  let zhPluralRules = new intl.PluralRules("zh-Hans");
  // 计算zh-Hans区域中数字1对应的单复数类别
  let plural = zhPluralRules.select(1); // plural = other

  // 使用en-US区域ID创建PluralRules对象
  let enPluralRules = new intl.PluralRules("en-US");
  // 计算en-US区域中数字1对应的单复数类别
  plural = enPluralRules.select(1); // plural = one
  ```


## PluralRulesOptions<sup>8+</sup>

创建单复数对象时可设置的配置项。从API version 9开始，PluralRulesOptions的属性由必填改为可选。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称                       | 类型     | 可读   | 可写   | 说明                                       |
| ------------------------ | ------ | ---- | ---- | ---------------------------------------- |
| localeMatcher            | string | 是    | 是    | 区域匹配算法，取值包括："best&nbsp;fit",&nbsp;"lookup"。<br>默认值：best fit。 |
| type                     | string | 是    | 是    | 排序的类型，取值包括："cardinal",&nbsp;"ordinal",<br>默认值：cardinal。<br>- cardinal：基数词，ordinal：序数词。  |
| minimumIntegerDigits     | number | 是    | 是    | 表示要使用的最小整数位数，取值范围：1~21。<br>默认值：1。                  |
| minimumFractionDigits    | number | 是    | 是    | 表示要使用的最小分数位数，取值范围：0~20。<br>默认值：0。                  |
| maximumFractionDigits    | number | 是    | 是    | 表示要使用的最大分数位数，取值范围：1~21。<br>默认值：3。                  |
| minimumSignificantDigits | number | 是    | 是    | 表示要使用的最小有效位数，取值范围：1~21。<br>默认值：1。                  |
| maximumSignificantDigits | number | 是    | 是    | 表示要使用的最大有效位数，取值范围：1~21。<br>默认值：21。                |


## RelativeTimeFormat<sup>8+</sup>

### constructor<sup>8+</sup>

constructor()

创建相对时间格式化对象。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**示例：**
  ```ts
  // 使用系统区域创建RelativeTimeFormat对象
  let relativetimefmt = new intl.RelativeTimeFormat();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: RelativeTimeFormatInputOptions)

创建相对时间格式化对象。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名                  | 类型                                       | 必填   | 说明                           |
| -------------------- | ---------------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;            | 是    | 区域ID或区域ID数组。输入是区域ID数组时，使用第一个有效的区域ID。 |
| options              | [RelativeTimeFormatInputOptions](#relativetimeformatinputoptions8) | 否    | 创建相对时间格式化对象时可配置的选项。     |

**示例：**
  ```ts
  // 使用zh-CN区域ID创建RelativeTimeFormat对象，localeMatcher设置为lookup，numeric设置为always，style设置为long
  let relativeTimeFormat = new intl.RelativeTimeFormat("zh-CN", {"localeMatcher": "lookup", "numeric": "always", "style": "long"});
  ```


### format<sup>8+</sup>

format(value: number, unit: string): string

对相对时间进行格式化。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | 是    | 相对时间格式化的数值。                              |
| unit  | string | 是    | 相对时间格式化的单位，<br>取值包括："year",&nbsp;"quarter",&nbsp;"month",&nbsp;"week",&nbsp;"day",&nbsp;"hour",&nbsp;"minute",&nbsp;"second"。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 格式化后的相对时间。 |

**示例：**
  ```ts
  // 使用zh-CN区域ID创建RelativeTimeFormat对象
  let relativetimefmt = new intl.RelativeTimeFormat("zh-CN");
  // 计算zh-CN区域中数字3，单位quarter的本地化表示
  let formatResult = relativetimefmt.format(3, "quarter"); // formatResult = "3个季度后"
  ```


### formatToParts<sup>8+</sup>

formatToParts(value: number, unit: string): Array&lt;object&gt;

对相对时间进行格式化，获取格式化结果中各个部分的对象数组。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**参数：**

| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | 是    | 相对时间格式化的数值。                              |
| unit  | string | 是    | 相对时间格式化的单位，<br>取值包括："year",&nbsp;"quarter",&nbsp;"month",&nbsp;"week",&nbsp;"day",&nbsp;"hour",&nbsp;"minute",&nbsp;"second"。 |

**返回值：**

| 类型                  | 说明                          |
| ------------------- | --------------------------- |
| Array&lt;object&gt; | 格式化结果中各个部分的对象数组。 |

**示例：**
  ```ts
  // 使用en区域ID创建RelativeTimeFormat对象，numeric设置为auto
  let relativetimefmt = new intl.RelativeTimeFormat("en", {"numeric": "auto"});
  let parts = relativetimefmt.formatToParts(10, "seconds"); // parts = [ {type: "literal", value: "in"}, {type: "integer", value: 10, unit: "second"}, {type: "literal", value: "seconds"} ]
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): RelativeTimeFormatResolvedOptions

获取相对时间格式化对象的格式化配置项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

**返回值：**

| 类型                                       | 说明                                |
| ---------------------------------------- | --------------------------------- |
| [RelativeTimeFormatResolvedOptions](#relativetimeformatresolvedoptions8) | 相对时间格式化对象的格式化配置项。 |

**示例：**
  ```ts
  // 使用en-GB区域ID创建RelativeTimeFormat对象
  let relativetimefmt= new intl.RelativeTimeFormat("en-GB", { style: "short" });
  // 获取RelativeTimeFormat对象配置项
  let options = relativetimefmt.resolvedOptions();
  let style = options.style; // style = "short"
  ```


## RelativeTimeFormatInputOptions<sup>8+</sup>

创建相对时间格式化对象时可设置的配置项。

从API version 9开始，RelativeTimeFormatInputOptions中的属性改为可选。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型     | 必填   |说明                                       |
| ------------- | ------ | ---- | ---------------------------------------- |
| localeMatcher | string | 否    | 区域匹配算法，取值包括："best&nbsp;fit",&nbsp;"lookup"。<br>默认值：best fit。 |
| numeric       | string | 否    | 输出消息的格式，取值包括："always",&nbsp;"auto"。<br>默认值：always。      |
| style         | string | 否    | 国际化消息的长度，取值包括："long",&nbsp;"short",&nbsp;"narrow"。<br>默认值：long。 |

> **说明**
>
> numeric、style不同取值的显示效果，请参考[相对时间格式化选项](../../internationalization/i18n-time-date.md#相对时间格式化)。

## RelativeTimeFormatResolvedOptions<sup>8+</sup>

相对时间格式化对象的格式化配置项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.I18n

| 名称              | 类型     | 必填   |说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| locale          | string | 是    | 表示区域ID的字符串，包括语言以及可选的脚本和区域。             |
| numeric         | string | 是    | 输出消息的格式，取值包括："always",&nbsp;"auto"。      |
| style           | string | 是    | 国际化消息的长度，取值包括："long",&nbsp;"short",&nbsp;"narrow"。 |
| numberingSystem | string | 是    | 使用的数字系统，取值包括：<br>"adlm",&nbsp;"ahom",&nbsp;"arab",&nbsp;"arabext",&nbsp;"bali",&nbsp;"beng",&nbsp;"bhks",&nbsp;"brah",&nbsp;"cakm",&nbsp;"cham",&nbsp;"deva",&nbsp;"diak",&nbsp;"fullwide",&nbsp;"gong",&nbsp;"gonm",&nbsp;"gujr",&nbsp;"guru",&nbsp;"hanidec",&nbsp;"hmng",&nbsp;"hmnp",&nbsp;"java",&nbsp;"kali",&nbsp;"khmr",&nbsp;"knda",&nbsp;"lana",&nbsp;"lanatham",&nbsp;"laoo",&nbsp;"latn",&nbsp;"lepc",&nbsp;"limb",&nbsp;"mathbold",&nbsp;"mathdbl",&nbsp;"mathmono",&nbsp;"mathsanb",&nbsp;"mathsans",&nbsp;"mlym",&nbsp;"modi",&nbsp;"mong",&nbsp;"mroo",&nbsp;"mtei",&nbsp;"mymr",&nbsp;"mymrshan",&nbsp;"mymrtlng",&nbsp;"newa",&nbsp;"nkoo",&nbsp;"olck",&nbsp;"orya",&nbsp;"osma",&nbsp;"rohg",&nbsp;"saur",&nbsp;"segment",&nbsp;"shrd",&nbsp;"sind",&nbsp;"sinh",&nbsp;"sora",&nbsp;"sund",&nbsp;"takr",&nbsp;"talu",&nbsp;"tamldec",&nbsp;"telu",&nbsp;"thai",&nbsp;"tibt",&nbsp;"tirh",&nbsp;"vaii",&nbsp;"wara",&nbsp;"wcho"。 |

> **说明**
>
> numeric、style不同参数取值显示的效果，请参考[相对时间格式化选项](../../internationalization/i18n-time-date.md#相对时间格式化)。