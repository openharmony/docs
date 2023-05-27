# @ohos.intl (国际化-Intl)

 本模块提供基础的应用国际化能力，包括时间日期格式化、数字格式化、排序等，相关接口在ECMA 402标准中定义。
[I18N模块](js-apis-i18n.md)提供其他非ECMA 402定义的国际化接口，与本模块共同使用可提供完整地国际化支持能力。 

>  **说明：**
>  - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - Intl模块包含国际化能力基础接口（在ECMA 402中定义），包括时间日期格式化、数字格式化、排序等，国际化增强能力请参考[I18N模块](js-apis-i18n.md)。


## 导入模块

```js
import Intl from '@ohos.intl';
```
未正确导入包可能产生不明确的接口行为。

## Locale


### 属性

**系统能力**：SystemCapability.Global.I18n

| 名称              | 类型      | 可读   | 可写   | 说明                                       |
| --------------- | ------- | ---- | ---- | ---------------------------------------- |
| language        | string  | 是    | 否    | 与区域设置关联的语，&nbsp;如：zh。                    |
| script          | string  | 是    | 否    | 语言的书写方式，如：Hans。                          |
| region          | string  | 是    | 否    | 与区域设置相关的地区，如：CN。                         |
| baseName        | string  | 是    | 否    | Locale的基本核心信息（由语言脚本与地区组成），如：zh-Hans-CN。  |
| caseFirst       | string  | 是    | 否    | 区域的整理规则是否考虑大小写，取值包括："upper",&nbsp;"lower",&nbsp;"false"。 |
| calendar        | string  | 是    | 否    | 区域的日历信息，取值包括："buddhist",&nbsp;"chinese",&nbsp;"coptic","dangi",&nbsp;"ethioaa",&nbsp;"ethiopic",&nbsp;"gregory",&nbsp;"hebrew",&nbsp;"indian",&nbsp;"islamic",&nbsp;"islamic-umalqura",&nbsp;"islamic-tbla",&nbsp;"islamic-civil",&nbsp;"islamic-rgsa",&nbsp;"iso8601",&nbsp;"japanese",&nbsp;"persian",&nbsp;"roc",&nbsp;"islamicc"。 |
| collation       | string  | 是    | 否    | 区域的排序规则，取值包括："big5han",&nbsp;"compat",&nbsp;"dict",&nbsp;"direct",&nbsp;"ducet",&nbsp;"eor",&nbsp;"gb2312",&nbsp;"phonebk",&nbsp;"phonetic",&nbsp;"pinyin",&nbsp;"reformed",&nbsp;"searchjl",&nbsp;"stroke",&nbsp;"trad",&nbsp;"unihan",&nbsp;"zhuyin"。 |
| hourCycle       | string  | 是    | 否    | 区域的时制信息，取值包括："h12",&nbsp;"h23",&nbsp;"h11",&nbsp;"h24"。 |
| numberingSystem | string  | 是    | 否    | 区域使用的数字系统，取值包括："adlm",&nbsp;"ahom",&nbsp;"arab",&nbsp;"arabext",&nbsp;"bali",&nbsp;"beng",&nbsp;"bhks",&nbsp;"brah",&nbsp;"cakm",&nbsp;"cham",&nbsp;"deva",&nbsp;"diak",&nbsp;"fullwide",&nbsp;"gong",&nbsp;"gonm",&nbsp;"gujr",&nbsp;"guru",&nbsp;"hanidec",&nbsp;"hmng",&nbsp;"hmnp",&nbsp;"java",&nbsp;"kali",&nbsp;"khmr",&nbsp;"knda",&nbsp;"lana",&nbsp;"lanatham",&nbsp;"laoo",&nbsp;"latn",&nbsp;"lepc",&nbsp;"limb",&nbsp;"mathbold",&nbsp;"mathdbl",&nbsp;"mathmono",&nbsp;"mathsanb",&nbsp;"mathsans",&nbsp;"mlym",&nbsp;"modi",&nbsp;"mong",&nbsp;"mroo",&nbsp;"mtei",&nbsp;"mymr",&nbsp;"mymrshan",&nbsp;"mymrtlng",&nbsp;"newa",&nbsp;"nkoo",&nbsp;"olck",&nbsp;"orya",&nbsp;"osma",&nbsp;"rohg",&nbsp;"saur",&nbsp;"segment",&nbsp;"shrd",&nbsp;"sind",&nbsp;"sinh",&nbsp;"sora",&nbsp;"sund",&nbsp;"takr",&nbsp;"talu",&nbsp;"tamldec",&nbsp;"telu",&nbsp;"thai",&nbsp;"tibt",&nbsp;"tirh",&nbsp;"vaii",&nbsp;"wara",&nbsp;"wcho"。 |
| numeric         | boolean | 是    | 否    | 是否对数字字符具有特殊的排序规则处理。                      |


### constructor<sup>8+</sup>

constructor()

创建区域对象

**系统能力**：SystemCapability.Global.I18n

**示例：** 
  ```js
  // 默认构造函数使用系统当前locale创建Locale对象
  let locale = new Intl.Locale();
  // 返回系统当前localel
  let localeID = locale.toString();
  ```


### constructor

constructor(locale: string, options?: LocaleOptions)

创建区域对象

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名                  | 类型                               | 必填   | 说明                           |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string                           | 是    | 包含区域信息的字符串，包括语言以、脚本、国家或地区。语言、脚本、国家或地区的国际标准及组合方式请见[Intl开发指导](../../internationalization/intl-guidelines.md#设置区域信息) |
| options             | [LocaleOptions](#localeoptions6) | 否    | 用于创建区域对象的选项。                 |

**示例：** 
  ```js
  // 创建 "zh-CN" Locale对象
  let locale = new Intl.Locale("zh-CN");
  let localeID = locale.toString(); // localeID = "zh-CN"
  ```


### toString

toString(): string

获取区域对象的字符串表示

**系统能力**：SystemCapability.Global.I18n

**返回值：** 

| 类型     | 说明          |
| ------ | ----------- |
| string | 区域对象的字符串表示。 |

**示例：** 
  ```js
  // 创建 "en-GB" Locale对象
  let locale = new Intl.Locale("en-GB");
  let localeID = locale.toString(); // localeID = "en-GB"
  ```


### maximize

maximize(): Locale

最大化区域信息，若缺少脚本与地区信息，则补齐。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 

| 类型                | 说明         |
| ----------------- | ---------- |
| [Locale](#locale) | 最大化后的区域对象。 |

**示例：** 
  ```js
  // 创建 "zh" Locale对象
  let locale = new Intl.Locale("zh");
  // 补齐Locale对象的脚本和地区
  let maximizedLocale = locale.maximize();
  let localeID = maximizedLocale.toString(); // localeID = "zh-Hans-CN"

  // 创建 "en-US" Locale对象
  locale = new Intl.Locale("en-US");
  // 补齐Locale对象的脚本
  maximizedLocale = locale.maximize();
  localeID = maximizedLocale.toString(); // localeID = "en-Latn-US"
  ```


### minimize

minimize(): Locale

最小化区域信息，若包含脚本与地区信息，则去除。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 

| 类型                | 说明         |
| ----------------- | ---------- |
| [Locale](#locale) | 最小化后的区域对象。 |

**示例：** 
  ```js
  // 创建 "zh-Hans-CN" Locale对象
  let locale = new Intl.Locale("zh-Hans-CN");
  // 去除Locale对象的脚本和地区
  let minimizedLocale = locale.minimize();
  let localeID = minimizedLocale.toString(); // localeID = "zh"

  // 创建 "en-US" Locale对象
  locale = new Intl.Locale("en-US");
  // 去除Locale对象的地区
  minimizedLocale = locale.minimize();
  localeID = minimizedLocale.toString(); // localeID = "en"
  ```


## LocaleOptions<sup>6+</sup>

表示区域初始化选项。
在API9中，LocaleOptions中的属性修改为可选属性。

**系统能力**：SystemCapability.Global.I18n

| 名称              | 类型      | 可读   | 可写   | 说明                                       |
| --------------- | ------- | ---- | ---- | ---------------------------------------- |
| calendar        | string  | 是    | 是    | 日历参数，如："buddhist", "chinese", "coptic", "dangi", "ethioaa", "ethiopic", "gregory", "hebrew", "indian", "islamic", "islamic-umalqura", "islamic-tbla", "islamic-civil", "islamic-rgsa", "iso8601", "japanese", "persian", "roc", "islamicc"。 |
| collation       | string  | 是    | 是    | 排序参数，取值包括："big5han", "compat", "dict", "direct", "ducet", "emoji", "eor", "gb2312", "phonebk", "phonetic", "pinyin", "reformed	", "search", "searchjl", "standard", "stroke", "trad", "unihan", "zhuyin"。 |
| hourCycle       | string  | 是    | 是    | 时制格式，取值包括："h11",&nbsp;"h12",&nbsp;"h23",&nbsp;"h24"。 |
| numberingSystem | string  | 是    | 是    | 数字系统，取值包括："adlm",&nbsp;"ahom",&nbsp;"arab",&nbsp;"arabext",&nbsp;"bali",&nbsp;"beng",&nbsp;"bhks",&nbsp;"brah",&nbsp;"cakm",&nbsp;"cham",&nbsp;"deva",&nbsp;"diak",&nbsp;"fullwide",&nbsp;"gong",&nbsp;"gonm",&nbsp;"gujr",&nbsp;"guru",&nbsp;"hanidec",&nbsp;"hmng",&nbsp;"hmnp",&nbsp;"java",&nbsp;"kali",&nbsp;"khmr",&nbsp;"knda",&nbsp;"lana",&nbsp;"lanatham",&nbsp;"laoo",&nbsp;"latn",&nbsp;"lepc",&nbsp;"limb",&nbsp;"mathbold",&nbsp;"mathdbl",&nbsp;"mathmono",&nbsp;"mathsanb",&nbsp;"mathsans",&nbsp;"mlym",&nbsp;"modi",&nbsp;"mong",&nbsp;"mroo",&nbsp;"mtei",&nbsp;"mymr",&nbsp;"mymrshan",&nbsp;"mymrtlng",&nbsp;"newa",&nbsp;"nkoo",&nbsp;"olck",&nbsp;"orya",&nbsp;"osma",&nbsp;"rohg",&nbsp;"saur",&nbsp;"segment",&nbsp;"shrd",&nbsp;"sind",&nbsp;"sinh",&nbsp;"sora",&nbsp;"sund",&nbsp;"takr",&nbsp;"talu",&nbsp;"tamldec",&nbsp;"telu",&nbsp;"thai",&nbsp;"tibt",&nbsp;"tirh",&nbsp;"vaii",&nbsp;"wara",&nbsp;"wcho"。 |
| numeric         | boolean | 是    | 是    | 是否使用12小时制。                               |
| caseFirst       | string  | 是    | 是    | 表示大写、小写的排序顺序，取值范围："upper",&nbsp;"lower",&nbsp;"false"。 |


## DateTimeFormat


### constructor<sup>8+</sup>

constructor()

创建时间日期格式化对象。

**系统能力**：SystemCapability.Global.I18n

**示例：** 
  ```js
  // 使用系统当前locale创建DateTimeFormat对象
  let datefmt= new Intl.DateTimeFormat();
  ```


### constructor

constructor(locale: string | Array&lt;string&gt;, options?: DateTimeOptions)

创建时间日期格式化对象。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名                  | 类型                                   | 必填   | 说明                           |
| -------------------- | ------------------------------------ | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;        | 是    | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |
| options              | [DateTimeOptions](#datetimeoptions6) | 否    | 用于创建时间日期格式化的选项。              |

**示例：** 
  ```js
  // 使用 "zh-CN" locale创建DateTimeFormat对象，日期风格为full，时间风格为medium
  let datefmt= new Intl.DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });
  ```


**示例：** 
  ```js
  // 使用 ["ban", "zh"] locale列表创建DateTimeFormat对象，因为ban为非法LocaleID，因此使用zh Locale创建DateTimeFormat对象
  let datefmt= new Intl.DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
  ```


### format

format(date: Date): string

格式化时间日期字符串。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名  | 类型   | 必填   | 说明      |
| ---- | ---- | ---- | ------- |
| date | Date | 是    | 时间日期对象。 |

**返回值：** 

| 类型     | 说明           |
| ------ | ------------ |
| string | 格式化后的时间日期字符串 |

**示例：** 
  ```js
  let date = new Date(2021, 11, 17, 3, 24, 0);
  // 使用 en-GB locale创建DateTimeFormat对象
  let datefmt = new Intl.DateTimeFormat("en-GB");
  let formattedDate = datefmt.format(date); // formattedDate "17/12/2021"

  // 使用 en-GB locale创建DateTimeFormat对象，dateStyle设置为full，timeStyle设置为medium
  datefmt = new Intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });
  formattedDate = datefmt.format(date); // formattedDate "Friday, 17 December 2021 at 03:24:00"
  ```


### formatRange

formatRange(startDate: Date, endDate: Date): string

格式化时间日期段字符串。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名       | 类型   | 必填   | 说明       |
| --------- | ---- | ---- | -------- |
| startDate | Date | 是    | 起始的时间日期。 |
| endDate   | Date | 是    | 结束的时间日期。 |

**返回值：** 

| 类型     | 说明             |
| ------ | -------------- |
| string | 格式化后的时间日期段字符串。 |

**示例：** 
  ```js
  let startDate = new Date(2021, 11, 17, 3, 24, 0);
  let endDate = new Date(2021, 11, 18, 3, 24, 0);
  // 使用 en-GB locale创建DateTimeFormat对象
  let datefmt = new Intl.DateTimeFormat("en-GB");
  let formattedDateRange = datefmt.formatRange(startDate, endDate); // formattedDateRange = "17/12/2021-18/12/2021"
  ```


### resolvedOptions

resolvedOptions(): DateTimeOptions

获取DateTimeFormat对象的格式化选项。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 

| 类型                                   | 说明                            |
| ------------------------------------ | ----------------------------- |
| [DateTimeOptions](#datetimeoptions6) | DateTimeFormat&nbsp;对象的格式化选项。 |

**示例：** 
  ```js
  let datefmt = new Intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });
  // 返回DateTimeFormat对象的配置项
  let options = datefmt.resolvedOptions();
  let dateStyle = options.dateStyle; // dateStyle = "full"
  let timeStyle = options.timeStyle; // timeStyle = "medium"
  ```


## DateTimeOptions<sup>6+</sup>

表示时间日期格式化选项。
在API9中，DateTimeOptions中的属性修改为可选属性。

**系统能力**：SystemCapability.Global.I18n

| 名称              | 类型      | 可读   | 可写   | 说明                                       |
| --------------- | ------- | ---- | ---- | ---------------------------------------- |
| locale          | string  | 是    | 否    | 区域参数，&nbsp;如：zh-Hans-CN。                 |
| dateStyle       | string  | 是    | 是    | 日期显示格式，取值包括："long",&nbsp;"short",&nbsp;"medium",&nbsp;"full"。 |
| timeStyle       | string  | 是    | 是    | 时间显示格式，取值包括："long",&nbsp;"short",&nbsp;"medium",&nbsp;"full"。 |
| hourCycle       | string  | 是    | 是    | 时制格式，取值包括："h11",&nbsp;"h12",&nbsp;"h23",&nbsp;"h24"。 |
| timeZone        | string  | 是    | 是    | 使用的时区（合法的IANA时区ID）。                      |
| numberingSystem | string  | 是    | 是    | 数字系统，取值包括："adlm",&nbsp;"ahom",&nbsp;"arab",&nbsp;"arabext",&nbsp;"bali",&nbsp;"beng",&nbsp;"bhks",&nbsp;"brah",&nbsp;"cakm",&nbsp;"cham",&nbsp;"deva",&nbsp;"diak",&nbsp;"fullwide",&nbsp;"gong",&nbsp;"gonm",&nbsp;"gujr",&nbsp;"guru",&nbsp;"hanidec",&nbsp;"hmng",&nbsp;"hmnp",&nbsp;"java",&nbsp;"kali",&nbsp;"khmr",&nbsp;"knda",&nbsp;"lana",&nbsp;"lanatham",&nbsp;"laoo",&nbsp;"latn",&nbsp;"lepc",&nbsp;"limb",&nbsp;"mathbold",&nbsp;"mathdbl",&nbsp;"mathmono",&nbsp;"mathsanb",&nbsp;"mathsans",&nbsp;"mlym",&nbsp;"modi",&nbsp;"mong",&nbsp;"mroo",&nbsp;"mtei",&nbsp;"mymr",&nbsp;"mymrshan",&nbsp;"mymrtlng",&nbsp;"newa",&nbsp;"nkoo",&nbsp;"olck",&nbsp;"orya",&nbsp;"osma",&nbsp;"rohg",&nbsp;"saur",&nbsp;"segment",&nbsp;"shrd",&nbsp;"sind",&nbsp;"sinh",&nbsp;"sora",&nbsp;"sund",&nbsp;"takr",&nbsp;"talu",&nbsp;"tamldec",&nbsp;"telu",&nbsp;"thai",&nbsp;"tibt",&nbsp;"tirh",&nbsp;"vaii",&nbsp;"wara",&nbsp;"wcho"。 |
| hour12          | boolean | 是    | 是    | 是否使用12小时制。                               |
| weekday         | string  | 是    | 是    | 工作日的显示格式，取值包括："long",&nbsp;"short",&nbsp;"narrow"。 |
| era             | string  | 是    | 是    | 时代的显示格式，取值包括："long",&nbsp;"short",&nbsp;"narrow"。 |
| year            | string  | 是    | 是    | 年份的显示格式，取值包括："numeric",&nbsp;"2-digit"。  |
| month           | string  | 是    | 是    | 月份的显示格式，取值包括："numeric",&nbsp;"2-digit",&nbsp;"long",&nbsp;"short",&nbsp;"narrow"。 |
| day             | string  | 是    | 是    | 日期的显示格式，取值包括："numeric",&nbsp;"2-digit"。  |
| hour            | string  | 是    | 是    | 小时的显示格式，取值包括："numeric",&nbsp;"2-digit"。  |
| minute          | string  | 是    | 是    | 分钟的显示格式，取值包括："numeric",&nbsp;"2-digit"。  |
| second          | string  | 是    | 是    | 秒钟的显示格式，取值包括："numeric",&nbsp;"2-digit"。  |
| timeZoneName    | string  | 是    | 是    | 时区名称的本地化表示。                              |
| dayPeriod       | string  | 是    | 是    | 时段的显示格式，取值包括："long",&nbsp;"short",&nbsp;"narrow"。 |
| localeMatcher   | string  | 是    | 是    | 要使用的区域匹配算法，取值包括："lookup",&nbsp;"best&nbsp;fit"。 |
| formatMatcher   | string  | 是    | 是    | 要使用的格式匹配算法，取值包括："basic",&nbsp;"best&nbsp;fit"。 |


## NumberFormat


### constructor<sup>8+</sup>

constructor()

创建数字格式化对象。

**系统能力**：SystemCapability.Global.I18n

**示例：** 
  ```js
  // 使用系统当前locale创建NumberFormat对象
  let numfmt = new Intl.NumberFormat();
  ```


### constructor

constructor(locale: string | Array&lt;string&gt;, options?: NumberOptions)

创建数字格式化对象。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名                  | 类型                               | 必填   | 说明                           |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;    | 是    | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |
| options              | [NumberOptions](#numberoptions6) | 否    | 用于创建数字格式化的选项。                |

**示例：** 
  ```js
  // 使用 en-GB locale创建NumberFormat对象，style设置为decimal，notation设置为scientific
  let numfmt = new Intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
  ```


### format

format(number: number): string;

格式化数字字符串。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名    | 类型     | 必填   | 说明   |
| ------ | ------ | ---- | ---- |
| number | number | 是    | 数字对象 |

**返回值：** 

| 类型     | 说明         |
| ------ | ---------- |
| string | 格式化后的数字字符串 |


**示例：** 
  ```js
  // 使用 ["en-GB", "zh"] locale列表创建NumberFormat对象，因为en-GB为合法LocaleID，因此使用en-GB创建NumberFormat对象
  let numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  let formattedNumber = numfmt.format(1223); // formattedNumber = 1.223E3
  ```


### resolvedOptions

resolvedOptions(): NumberOptions

获取NumberFormat 对象的格式化选项。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 

| 类型                               | 说明                          |
| -------------------------------- | --------------------------- |
| [NumberOptions](#numberoptions6) | NumberFormat&nbsp;对象的格式化选项。 |


**示例：** 
  ```js
  let numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  // 获取NumberFormat对象配置项
  let options = numfmt.resolvedOptions();
  let style = options.style; // style = decimal
  let notation = options.notation; // notation = scientific
  ```


## NumberOptions<sup>6+</sup>

表示设备支持的能力。
在API9中，NumberOptions中的属性修改为可选属性。

**系统能力**：SystemCapability.Global.I18n

| 名称                       | 类型      | 可读   | 可写   | 说明                                       |
| ------------------------ | ------- | ---- | ---- | ---------------------------------------- |
| locale                   | string  | 是    | 否    | 区域参数，&nbsp;如："zh-Hans-CN"。               |
| currency                 | string  | 是    | 是    | 货币单位，&nbsp;如："EUR"，"CNY"，"USD"等。         |
| currencySign             | string  | 是    | 是    | 货币单位的符号显示，取值包括：&nbsp;"symbol"，"narrowSymbol"，"code"，"name"&nbsp;。 |
| currencyDisplay          | string  | 是    | 是    | 货币的显示方式，取值包括："symbol",&nbsp;"narrowSymbol",&nbsp;"code",&nbsp;"name"。 |
| unit                     | string  | 是    | 是    | 单位名称，如："meter"，"inch"，“hectare”等。        |
| unitDisplay              | string  | 是    | 是    | 单位的显示格式，取值包括："long",&nbsp;"short",&nbsp;"narrow"。 |
| unitUsage<sup>8+</sup>   | string  | 是    | 是    | 单位的使用场景，取值包括："default",&nbsp;"area-land-agricult",&nbsp;"area-land-commercl",&nbsp;"area-land-residntl",&nbsp;"length-person",&nbsp;"length-person-small",&nbsp;"length-rainfall",&nbsp;"length-road",&nbsp;"length-road-small",&nbsp;"length-snowfall",&nbsp;"length-vehicle",&nbsp;"length-visiblty",&nbsp;"length-visiblty-small",&nbsp;"length-person-informal",&nbsp;"length-person-small-informal",&nbsp;"length-road-informal",&nbsp;"speed-road-travel",&nbsp;"speed-wind",&nbsp;"temperature-person",&nbsp;"temperature-weather",&nbsp;"volume-vehicle-fuel"。 |
| signDisplay              | string  | 是    | 是    | 数字符号的显示格式，取值包括："auto",&nbsp;"never",&nbsp;"always",&nbsp;"expectZero"。 |
| compactDisplay           | string  | 是    | 是    | 紧凑型的显示格式，取值包括："long",&nbsp;"short"。      |
| notation                 | string  | 是    | 是    | 数字的格式化规格，取值包括："standard",&nbsp;"scientific",&nbsp;"engineering",&nbsp;"compact"。 |
| localeMatcher            | string  | 是    | 是    | 要使用的区域匹配算法，取值包括："lookup",&nbsp;"best&nbsp;fit"。 |
| style                    | string  | 是    | 是    | 数字的显示格式，取值包括："decimal",&nbsp;"currency",&nbsp;"percent",&nbsp;"unit"。 |
| numberingSystem          | string  | 是    | 是    | 数字系统，取值包括："adlm",&nbsp;"ahom",&nbsp;"arab",&nbsp;"arabext",&nbsp;"bali",&nbsp;"beng",&nbsp;"bhks",&nbsp;"brah",&nbsp;"cakm",&nbsp;"cham",&nbsp;"deva",&nbsp;"diak",&nbsp;"fullwide",&nbsp;"gong",&nbsp;"gonm",&nbsp;"gujr",&nbsp;"guru",&nbsp;"hanidec",&nbsp;"hmng",&nbsp;"hmnp",&nbsp;"java",&nbsp;"kali",&nbsp;"khmr",&nbsp;"knda",&nbsp;"lana",&nbsp;"lanatham",&nbsp;"laoo",&nbsp;"latn",&nbsp;"lepc",&nbsp;"limb",&nbsp;"mathbold",&nbsp;"mathdbl",&nbsp;"mathmono",&nbsp;"mathsanb",&nbsp;"mathsans",&nbsp;"mlym",&nbsp;"modi",&nbsp;"mong",&nbsp;"mroo",&nbsp;"mtei",&nbsp;"mymr",&nbsp;"mymrshan",&nbsp;"mymrtlng",&nbsp;"newa",&nbsp;"nkoo",&nbsp;"olck",&nbsp;"orya",&nbsp;"osma",&nbsp;"rohg",&nbsp;"saur",&nbsp;"segment",&nbsp;"shrd",&nbsp;"sind",&nbsp;"sinh",&nbsp;"sora",&nbsp;"sund",&nbsp;"takr",&nbsp;"talu",&nbsp;"tamldec",&nbsp;"telu",&nbsp;"thai",&nbsp;"tibt",&nbsp;"tirh",&nbsp;"vaii",&nbsp;"wara",&nbsp;"wcho"。 |
| useGrouping              | boolean | 是    | 是    | 是否分组显示。                                  |
| minimumIntegerDigits     | number  | 是    | 是    | 表示要使用的最小整数位数，取值范围：1~21。                  |
| minimumFractionDigits    | number  | 是    | 是    | 表示要使用的最小分数位数，取值范围：0~20。                  |
| maximumFractionDigits    | number  | 是    | 是    | 表示要使用的最大分数位数，取值范围：1~21。                  |
| minimumSignificantDigits | number  | 是    | 是    | 表示要使用的最低有效位数，取值范围：1~21。                  |
| maximumSignificantDigits | number  | 是    | 是    | 表示要使用的最大有效位数，取值范围：1~21。                  |


## Collator<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

创建排序对象。

**系统能力**：SystemCapability.Global.I18n

**示例：** 
  ```js
  // 使用系统locale创建Collator对象
  let collator = new Intl.Collator();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: CollatorOptions)

创建排序对象。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名                  | 类型                                   | 必填   | 说明                           |
| -------------------- | ------------------------------------ | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;        | 是    | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |
| options              | [CollatorOptions](#collatoroptions8) | 否    | 用于创建排序对象的选项。                 |

**示例：** 
  ```js
  // 使用 zh-CN locale创建Collator对象，localeMatcher设置为lookup，usage设置为sort
  let collator = new Intl.Collator("zh-CN", {localeMatcher: "lookup", usage: "sort"});
  ```


### compare<sup>8+</sup>

compare(first: string, second: string): number

依据Collator的排序策略对两个字符串进行比较。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名    | 类型     | 必填   | 说明           |
| ------ | ------ | ---- | ------------ |
| first  | string | 是    | 进行比较第一个字符串。  |
| second | string | 是    | 进行比较的第二个字符串。 |

**返回值：** 

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 比较结果。当number为负数，表示first排序在second之前；当number为0，表示first与second排序相同；当number为正数，表示first排序在second之后。 |

**示例：** 
  ```js
  // 使用en-GB locale创建Collator对象
  let collator = new Intl.Collator("en-GB");
  // 比较 "first" 和 "second" 的先后顺序
  let compareResult = collator.compare("first", "second"); // compareResult = -1
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): CollatorOptions

返回Collator对象的属性。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 

| 类型                                   | 说明                |
| ------------------------------------ | ----------------- |
| [CollatorOptions](#collatoroptions8) | 返回的Collator对象的属性。 |

**示例：** 
  ```js
  let collator = new Intl.Collator("zh-Hans", { usage: 'sort', ignorePunctuation: true });
  // 获取Collator对象的配置项
  let options = collator.resolvedOptions();
  let usage = options.usage; // usage = "sort"
  let ignorePunctuation = options.ignorePunctuation; // ignorePunctuation = true
  ```


## CollatorOptions<sup>8+</sup>

表示Collator可设置的属性。
在API9中，CollatorOptions中的属性修改为可选属性。

**系统能力**：SystemCapability.Global.I18n

| 名称                | 类型      | 可读   | 可写   | 说明                                       |
| ----------------- | ------- | ---- | ---- | ---------------------------------------- |
| localeMatcher     | string  | 是    | 是    | locale匹配算法，取值范围："best&nbsp;fit",&nbsp;"lookup"。 |
| usage             | string  | 是    | 是    | 比较的用途，取值范围："sort",&nbsp;"search"。        |
| sensitivity       | string  | 是    | 是    | 表示字符串中的哪些差异会导致非零结果值，取值范围："base",&nbsp;"accent",&nbsp;"case",&nbsp;"letiant"。 |
| ignorePunctuation | boolean | 是    | 是    | 表示是否忽略标点符号，取值范围：true,&nbsp;false。        |
| collation         | string  | 是    | 是    | 排序规则，取值范围："big5han",&nbsp;"compat",&nbsp;"dict",&nbsp;"direct",&nbsp;"ducet",&nbsp;"eor",&nbsp;"gb2312",&nbsp;"phonebk",&nbsp;"phonetic",&nbsp;"pinyin",&nbsp;"reformed",&nbsp;"searchjl",&nbsp;"stroke",&nbsp;"trad",&nbsp;"unihan",&nbsp;"zhuyin"。 |
| numeric           | boolean | 是    | 是    | 是否使用数字排序，取值范围：true,&nbsp;false。          |
| caseFirst         | string  | 是    | 是    | 表示大写、小写的排序顺序，取值范围："upper",&nbsp;"lower",&nbsp;"false"。 |


## PluralRules<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

创建单复数对象来计算数字的单复数类别。

**系统能力**：SystemCapability.Global.I18n

**示例：** 
  ```js
  // 使用系统locale创建PluralRules对象
  let pluralRules = new Intl.PluralRules();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: PluralRulesOptions)

创建单复数对象来计算数字的单复数类别。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名                  | 类型                                       | 必填   | 说明                           |
| -------------------- | ---------------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;            | 是    | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |
| options              | [PluralRulesOptions](#pluralrulesoptions8) | 否    | 用于创建单复数对象的选项。                |

**示例：** 
  ```js
  // 使用 zh-CN locale创建PluralRules对象，localeMatcher设置为lookup，type设置为cardinal
  let pluralRules= new Intl.PluralRules("zh-CN", {"localeMatcher": "lookup", "type": "cardinal"});
  ```


### select<sup>8+</sup>

select(n: number): string

返回一个字符串表示该数字的单复数类别。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名  | 类型     | 必填   | 说明           |
| ---- | ------ | ---- | ------------ |
| n    | number | 是    | 待获取单复数类别的数字。 |

**返回值：** 

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| string | 单复数类别，取值包括："zero"，"one"，"two",&nbsp;"few",&nbsp;"many",&nbsp;"others"。 |

**示例：** 
  ```js
  // 使用 zh-Hans locale创建PluralRules对象
  let zhPluralRules = new Intl.PluralRules("zh-Hans");
  // 计算 zh-Hans locale中数字1对应的单复数类别
  let plural = zhPluralRules.select(1); // plural = other

  // 使用 en-US locale创建PluralRules对象
  let enPluralRules = new Intl.PluralRules("en-US");
  // 计算 en-US locale中数字1对应的单复数类别
  plural = enPluralRules.select(1); // plural = one
  ```


## PluralRulesOptions<sup>8+</sup>

表示PluralRules对象可设置的属性。
在API9中，PluralRulesOptions中的属性修改为可选属性。

**系统能力**：SystemCapability.Global.I18n

| 名称                       | 类型     | 可读   | 可写   | 说明                                       |
| ------------------------ | ------ | ---- | ---- | ---------------------------------------- |
| localeMatcher            | string | 是    | 是    | locale匹配算法，取值包括："best&nbsp;fit",&nbsp;"lookup"。 |
| type                     | string | 是    | 是    | 排序的类型，取值包括："cardinal",&nbsp;"ordinal"。   |
| minimumIntegerDigits     | number | 是    | 是    | 表示要使用的最小整数位数，取值范围：1~21。                  |
| minimumFractionDigits    | number | 是    | 是    | 表示要使用的最小分数位数，取值范围：0~20。                  |
| maximumFractionDigits    | number | 是    | 是    | 表示要使用的最大分数位数，取值范围：1~21。                  |
| minimumSignificantDigits | number | 是    | 是    | 表示要使用的最低有效位数，取值范围：1~21。                  |
| maximumSignificantDigits | number | 是    | 是    | 表示要使用的最大有效位数，取值范围：1~21。                  |


## RelativeTimeFormat<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

创建相对时间格式化对象。

**系统能力**：SystemCapability.Global.I18n

**示例：** 
  ```js
  // 使用系统locale创建RelativeTimeFormat对象
  let relativetimefmt = new Intl.RelativeTimeFormat();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: RelativeTimeFormatInputOptions)

创建相对时间格式化对象。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名                  | 类型                                       | 必填   | 说明                           |
| -------------------- | ---------------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;            | 是    | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |
| options              | [RelativeTimeFormatInputOptions](#relativetimeformatinputoptions8) | 否    | 用于创建相对时间格式化对象的选项。            |

**示例：** 
  ```js
  // 使用 zh-CN locale创建RelativeTimeFormat对象，localeMatcher设置为lookup，numeric设置为always，style设置为long
  let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {"localeMatcher": "lookup", "numeric": "always", "style": "long"});
  ```


### format<sup>8+</sup>

format(value: number, unit: string): string

依据locale和格式化选项，对value和unit进行格式化。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | 是    | 相对时间格式化的数值。                              |
| unit  | string | 是    | 相对时间格式化的单位，取值包括："year",&nbsp;"quarter",&nbsp;"month",&nbsp;"week",&nbsp;"day",&nbsp;"hour",&nbsp;"minute",&nbsp;"second"。 |

**返回值：** 

| 类型     | 说明         |
| ------ | ---------- |
| string | 格式化后的相对时间。 |

**示例：** 
  ```js
  // 使用 zh-CN locale创建RelativeTimeFormat对象
  let relativetimefmt = new Intl.RelativeTimeFormat("zh-CN");
  // 计算 zh-CN locale中数字3，单位quarter的本地化表示
  let formatResult = relativetimefmt.format(3, "quarter"); // formatResult = "3个季度后"
  ```


### formatToParts<sup>8+</sup>

formatToParts(value: number, unit: string): Array&lt;object&gt;

返回一个对象数组，表示可用于自定义区域设置格式的相对时间格式。

**系统能力**：SystemCapability.Global.I18n

**参数：** 

| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | 是    | 相对时间格式化的数值。                              |
| unit  | string | 是    | 相对时间格式化的单位，取值包括："year",&nbsp;"quarter",&nbsp;"month",&nbsp;"week",&nbsp;"day",&nbsp;"hour",&nbsp;"minute",&nbsp;"second"。 |

**返回值：** 

| 类型                  | 说明                          |
| ------------------- | --------------------------- |
| Array&lt;object&gt; | 返回可用于自定义区域设置格式的相对时间格式的对象数组。 |

**示例：** 
  ```js
  // 使用 en locale创建RelativeTimeFormat对象，numeric设置为auto
  let relativetimefmt = new Intl.RelativeTimeFormat("en", {"numeric": "auto"});
  let parts = relativetimefmt.formatToParts(10, "seconds"); // parts = [ {type: "literal", value: "in"}, {type: "integer", value: 10, unit: "second"}, {type: "literal", value: "seconds"} ]
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): RelativeTimeFormatResolvedOptions

获取RelativeTimeFormat对象的格式化选项。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 

| 类型                                       | 说明                                |
| ---------------------------------------- | --------------------------------- |
| [RelativeTimeFormatResolvedOptions](#relativetimeformatresolvedoptions8) | RelativeTimeFormat&nbsp;对象的格式化选项。 |

**示例：** 
  ```js
  // 使用 en-GB locale创建RelativeTimeFormat对象
  let relativetimefmt= new Intl.RelativeTimeFormat("en-GB", { style: "short" });
  // 获取RelativeTimeFormat对象配置项
  let options = relativetimefmt.resolvedOptions();
  let style = options.style; // style = "short"
  ```


## RelativeTimeFormatInputOptions<sup>8+</sup>

表示RelativeTimeFormat对象可设置的属性。
在API9中，RelativeTimeFormatInputOptions中的属性修改为可选属性。

**系统能力**：SystemCapability.Global.I18n

| 名称            | 类型     | 可读   | 可写   | 说明                                       |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| localeMatcher | string | 是    | 是    | locale匹配算法，取值包括："best&nbsp;fit",&nbsp;"lookup"。 |
| numeric       | string | 是    | 是    | 输出消息的格式，取值包括："always",&nbsp;"auto"。      |
| style         | string | 是    | 是    | 国际化消息的长度，取值包括："long",&nbsp;"short",&nbsp;"narrow"。 |


## RelativeTimeFormatResolvedOptions<sup>8+</sup>

表示RelativeTimeFormat对象可设置的属性。

**系统能力**：SystemCapability.Global.I18n

| 名称              | 类型     | 可读   | 可写   | 说明                                       |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| locale          | string | 是    | 是    | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。             |
| numeric         | string | 是    | 是    | 输出消息的格式，取值包括："always",&nbsp;"auto"。      |
| style           | string | 是    | 是    | 国际化消息的长度，取值包括："long",&nbsp;"short",&nbsp;"narrow"。 |
| numberingSystem | string | 是    | 是    | 使用的数字系统。                                 |
