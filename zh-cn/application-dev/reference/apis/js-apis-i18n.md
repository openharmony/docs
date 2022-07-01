# 国际化-I18n

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - I18N模块包含国际化能力增强接口（未在ECMA 402中定义），包括区域管理、电话号码处理、日历等，国际化基础能力请参考[Intl模块](js-apis-intl.md)。


## 导入模块

```
import i18n from '@ohos.i18n';
```


## i18n.getDisplayLanguage

getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

获取指定语言的本地化显示文本。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| language     | string  | 是    | 指定语言。            |
| locale       | string  | 是    | 显示指定语言的区域ID。     |
| sentenceCase | boolean | 否    | 本地化显示文本是否要首字母大写。 |

**返回值：** 
| 类型     | 说明            |
| ------ | ------------- |
| string | 指定语言的本地化显示文本。 |

**示例：** 
  ```
  i18n.getDisplayLanguage("zh", "en-GB", true);
  i18n.getDisplayLanguage("zh", "en-GB");
  ```


## i18n.getDisplayCountry

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

获取指定国家的本地化显示文本。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名          | 类型      | 必填   | 说明               |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | 是    | 指定国家。            |
| locale       | string  | 是    | 显示指定国家的区域ID。     |
| sentenceCase | boolean | 否    | 本地化显示文本是否要首字母大写。 |

**返回值：** 
| 类型     | 说明            |
| ------ | ------------- |
| string | 指定国家的本地化显示文本。 |

**示例：** 
  ```
  i18n.getDisplayCountry("zh-CN", "en-GB", true);
  i18n.getDisplayCountry("zh-CN", "en-GB");
  ```


## i18n.isRTL<sup>7+</sup>

isRTL(locale: string): boolean

获取是否为从右至左显示语言。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 说明      |
| ------ | ------ | ------- |
| locale | string | 指定区域ID。 |

**返回值：** 
| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | true表示该locale从右至左显示语言；false表示该locale从左至右显示语言。 |

**示例：** 
  ```
  i18n.isRTL("zh-CN");// 中文不是RTL语言，返回false
  i18n.isRTL("ar-EG");// 阿语是RTL语言，返回true
  ```


## i18n.getSystemLanguage

getSystemLanguage(): string

获取系统语言。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明      |
| ------ | ------- |
| string | 系统语言ID。 |

**示例：** 
  ```
  i18n.getSystemLanguage();
  ```


## i18n.setSystemLanguage

setSystemLanguage(language: string): boolean

设置系统语言。<br>
该接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名      | 类型     | 说明    |
| -------- | ------ | ----- |
| language | string | 语言ID。 |

**返回值：** 
| 类型      | 说明                                    |
| ------- | ------------------------------------- |
| boolean | 返回true，表示系统语言设置成功；返回false，表示系统语言设置失败。 |

**示例：** 
  ```
  i18n.setSystemLanguage('zh');
  ```


## i18n.getSystemLanguages

getSystemLanguages(): Array&lt;string&gt;

获取系统支持的语言列表。

**系统能力**：SystemCapability.Global.I18n

**系统API**: 该接口为系统接口，三方应用不支持调用。

**返回值：** 
| 类型                  | 说明           |
| ------------------- | ------------ |
| Array&lt;string&gt; | 系统支持的语言ID列表。 |

**示例：** 
  ```
  i18n.getSystemLanguages();
  ```


## i18n.getSystemCountries

getSystemCountries(language: string): Array&lt;string&gt;

获取针对输入语言系统支持的区域列表。

**系统能力**：SystemCapability.Global.I18n

**系统API**: 该接口为系统接口，三方应用不支持调用。

**参数：** 
| 参数名      | 类型     | 说明    |
| -------- | ------ | ----- |
| language | string | 语言ID。 |

**返回值：** 
| 类型                  | 说明           |
| ------------------- | ------------ |
| Array&lt;string&gt; | 系统支持的区域ID列表。 |

**示例：** 
  ```
  i18n.getSystemCountries('zh');
  ```


## i18n.getSystemRegion

getSystemRegion(): string

获取系统地区。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明      |
| ------ | ------- |
| string | 系统地区ID。 |

**示例：** 
  ```
  i18n.getSystemRegion();
  ```


## i18n.setSystemRegion

setSystemRegion(region: string): boolean

设置系统区域。<br>
该接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 说明    |
| ------ | ------ | ----- |
| region | string | 地区ID。 |

**返回值：** 
| 类型      | 说明                                    |
| ------- | ------------------------------------- |
| boolean | 返回true，表示系统区域设置成功；返回false，表示系统区域设置失败。 |

**示例：** 
  ```
  i18n.setSystemRegion('CN');
  ```


## i18n.getSystemLocale

getSystemLocale(): string

获取系统区域。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明      |
| ------ | ------- |
| string | 系统区域ID。 |

**示例：** 
  ```
  i18n.getSystemLocale();
  ```


## i18n.setSystemLocale

setSystemLocale(locale: string): boolean

设置系统Locale。<br>
该接口为系统接口。 

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 说明              |
| ------ | ------ | --------------- |
| locale | string | 指定区域ID，例如zh-CN。 |

**返回值：** 
| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true，表示系统Locale设置成功；返回false，表示系统Locale设置失败。 |

**示例：** 
  ```
  i18n.setSystemLocale('zh-CN');
  ```


## i18n.isSuggested

isSuggested(language: string, region?: string): boolean

判断当前语言和区域是否匹配。

**系统能力**：SystemCapability.Global.I18n

**系统API**: 该接口为系统接口，三方应用不支持调用。

**参数：** 
| 参数名      | 类型     | 必填   | 说明            |
| -------- | ------ | ---- | ------------- |
| language | string | 是    | 合法的语言ID，例如zh。 |
| region   | string | 否    | 合法的地区ID，例如CN  |

**返回值：** 
| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true，表示当前语言和地区匹配；返回false，表示当前语言和地区不匹配。 |

**示例：** 
  ```
  i18n.isSuggested('zh', 'CN');
  ```


## i18n.getCalendar<sup>8+</sup>

getCalendar(locale: string, type? : string): Calendar

获取日历对象。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | 是    | 合法的locale值，例如zh-Hans-CN。                 |
| type   | string | 否    | 合法的日历类型，目前合法的类型有buddhist,&nbsp;chinese,&nbsp;coptic,&nbsp;ethiopic,&nbsp;hebrew,&nbsp;gregory,&nbsp;indian,&nbsp;islamic_civil,&nbsp;islamic_tbla,&nbsp;islamic_umalqura,&nbsp;japanese,&nbsp;persian。当type没有给出时，采用区域默认的日历类型。 |

**返回值：** 
| 类型                     | 说明    |
| ---------------------- | ----- |
| [Calendar](#calendar8) | 日历对象。 |

**示例：** 
  ```
  i18n.getCalendar("zh-Hans", "gregory");
  ```


## Calendar<sup>8+</sup>


### setTime<sup>8+</sup>

setTime(date: Date): void

设置日历对象内部的时间日期。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名  | 类型   | 必填   | 说明                |
| ---- | ---- | ---- | ----------------- |
| date | Date | 是    | 将要设置的日历对象的内部时间日期。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("en-US", "gregory");
  var date = new Date(2021, 10, 7, 8, 0, 0, 0);
  calendar.setTime(date);
  ```


### setTime<sup>8+</sup>

setTime(time: number): void

设置日历对象内部的时间日期, time为从1970.1.1 00:00:00 GMT逝去的毫秒数。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名  | 类型     | 必填   | 说明                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| time | number | 是    | time为从1970.1.1&nbsp;00:00:00&nbsp;GMT逝去的毫秒数。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("en-US", "gregory");
  calendar.setTime(10540800000);
  ```


### set<sup>8+</sup>

set(year: number, month: number, date:number, hour?: number, minute?: number, second?: number): void

设置日历对象的年、月、日、时、分、秒。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明     |
| ------ | ------ | ---- | ------ |
| year   | number | 是    | 设置的年。  |
| month  | number | 是    | 设置的月。  |
| date   | number | 是    | 设置的日。  |
| hour   | number | 否    | 设置的小时。 |
| minute | number | 否    | 设置的分钟。 |
| second | number | 否    | 设置的秒。  |

**示例：** 
  ```
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00
  ```


### setTimeZone<sup>8+</sup>

setTimeZone(timezone: string): void

设置日历对象的时区。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名      | 类型     | 必填   | 说明                        |
| -------- | ------ | ---- | ------------------------- |
| timezone | string | 是    | 设置的时区id，如“Asia/Shanghai”。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  ```


### getTimeZone<sup>8+</sup>

getTimeZone(): string

获取日历对象的时区。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明         |
| ------ | ---------- |
| string | 日历对象的时区id。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  calendar.getTimeZone(); // Asia/Shanghai"
  ```


### getFirstDayOfWeek<sup>8+</sup>

getFirstDayOfWeek(): number

获取日历对象的一周起始日。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                    |
| ------ | --------------------- |
| number | 获取一周的起始日，1代表周日，7代表周六。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("en-US", "gregory");
  calendar.getFirstDayOfWeek();
  ```


### setFirstDayOfWeek<sup>8+</sup>

setFirstDayOfWeek(value: number): void

设置每一周的起始日。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名   | 类型     | 必填   | 说明                    |
| ----- | ------ | ---- | --------------------- |
| value | number | 否    | 设置一周的起始日，1代表周日，7代表周六。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.setFirstDayOfWeek(0);
  ```


### getMinimalDaysInFirstWeek<sup>8+</sup>

getMinimalDaysInFirstWeek(): number

获取一年中第一周的最小天数。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明           |
| ------ | ------------ |
| number | 一年中第一周的最小天数。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.getMinimalDaysInFirstWeek();
  ```


### setMinimalDaysInFirstWeek<sup>8+</sup>

setMinimalDaysInFirstWeek(value: number): void

设置一年中第一周的最小天数。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名   | 类型     | 必填   | 说明           |
| ----- | ------ | ---- | ------------ |
| value | number | 否    | 一年中第一周的最小天数。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.setMinimalDaysInFirstWeek(3);
  ```


### get<sup>8+</sup>

get(field: string): number

获取日历对象中与field相关联的值。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| field | string | 是    | 通过field来获取日历对象相应的值。目前支持的field值有&nbsp;era,&nbsp;year,&nbsp;month,&nbsp;week_of_year,&nbsp;week_of_month,&nbsp;date,&nbsp;day_of_year,&nbsp;day_of_week,&nbsp;day_of_week_in_month,&nbsp;hour,&nbsp;hour_of_day,&nbsp;minute,&nbsp;second,&nbsp;millisecond,&nbsp;zone_offset,&nbsp;dst_offset,&nbsp;year_woy,&nbsp;dow_local,&nbsp;extended_year,&nbsp;julian_day,&nbsp;milliseconds_in_day,&nbsp;is_leap_month。 |

**返回值：** 
| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 与field相关联的值，如当前Calendar对象的内部日期的年份为1990，get("year")返回1990。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00
  calendar.get("hour_of_day"); // 8
  ```


### getDisplayName<sup>8+</sup>

getDisplayName(locale: string): string

获取日历对象在locale所指定的区域的名字。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | 是    | locale指定获取哪个区域下该calendar的名字，如buddhist在en-US上显示的名称为“Buddhist&nbsp;Calendar”。 |

**返回值：** 
| 类型     | 说明                  |
| ------ | ------------------- |
| string | 日历在locale所指示的区域的名字。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("en-US", "buddhist");
  calendar.getDisplayName("zh"); // 佛历
  ```


### isWeekend<sup>8+</sup>

isWeekend(date?: Date): boolean

判断给定的日期是否在日历中是周末。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名  | 类型   | 必填   | 说明                                       |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | 否    | 判断日期在日历中是否是周末。如果date没有给出，判断calendar当前日期是否为周末。 |

**返回值：** 
| 类型      | 说明                                  |
| ------- | ----------------------------------- |
| boolean | 当所判断的日期为周末时，返回&nbsp;true，否则返回false。 |

**示例：** 
  ```
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.11.11 08:00:00
  calendar.isWeekend(); // false
  var date = new Date(2011, 11, 6, 9, 0, 0);
  calendar.isWeekend(date); // true
  ```


## PhoneNumberFormat<sup>8+</sup>


### constructor<sup>8+</sup>

constructor(country: string, options?: PhoneNumberFormatOptions)

创建电话号码格式化对象。

**系统能力**：SystemCapability.Global.I18n

参数：
| 参数名     | 类型                                       | 必填   | 说明               |
| ------- | ---------------------------------------- | ---- | ---------------- |
| country | string                                   | 是    | 表示电话号码所属国家或地区代码。 |
| options | [PhoneNumberFormatOptions](#phonenumberformatoptions8) | 否    | 电话号码格式化对象的相关选项。  |

**示例：** 
  ```
  var phoneNumberFormat= new i18n.PhoneNumberFormat("CN", {"type": "E164"});
  ```


### isValidNumber<sup>8+</sup>

isValidNumber(number: string): boolean

判断传入的电话号码格式是否正确。

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
  ```
  var phonenumberfmt = new i18n.PhoneNumberFormat("CN");
  phonenumberfmt.isValidNumber("15812312312");
  ```


### format<sup>8+</sup>

format(number: string): string

对电话号码进行格式化。

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
  ```
  var phonenumberfmt = new i18n.PhoneNumberFormat("CN");
  phonenumberfmt.format("15812312312");
  ```


## PhoneNumberFormatOptions<sup>8+</sup>

表示电话号码格式化对象可设置的属性。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Global.I18n

| 名称   | 参数类型   | 可读   | 可写   | 说明                                       |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | 是    | 是    | 表示对电话号码格式化的类型，取值范围："E164",&nbsp;"INTERNATIONAL",&nbsp;"NATIONAL",&nbsp;"RFC3966"。 |


## UnitInfo<sup>8+</sup>

度量衡单位信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Global.I18n

| 名称            | 参数类型   | 可读   | 可写   | 说明                                       |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| unit          | string | 是    | 是    | 单位的名称，如："meter",&nbsp;"inch",&nbsp;"cup"等。 |
| measureSystem | string | 是    | 是    | 单位的度量体系，取值包括："SI",&nbsp;"US",&nbsp;"UK"。 |


## Util<sup>8+</sup>


### unitConvert<sup>8+</sup>

static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

将fromUnit的单位转换为toUnit的单位，并根据区域与风格进行格式化。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名      | 类型                     | 必填   | 说明                                       |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| fromUnit | [UnitInfo](#unitinfo8) | 是    | 要被转换的单位。                                 |
| toUnit   | [UnitInfo](#unitinfo8) | 是    | 要转换为的单位。                                 |
| value    | number                 | 是    | 要被转换的单位的数量值。                             |
| locale   | string                 | 是    | 格式化时使用的区域参数，如：zh-Hans-CN。                |
| style    | string                 | 否    | 格式化使用的风格，取值包括："long",&nbsp;"short",&nbsp;"narrow"。 |

**返回值：** 
| 类型     | 说明                      |
| ------ | ----------------------- |
| string | 按照toUnit的单位格式化后，得到的字符串。 |

**示例：** 
  ```
  i18n.Util.unitConvert({unit: "cup", measureSystem: "US"}, {unit: "liter", measureSystem: "SI"}, 1000, "en-US", "long");
  ```


## getInstance<sup>8+</sup>

getInstance(locale?:string): IndexUtil

创建并返回IndexUtil对象。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明                           |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | 否    | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |

**返回值：** 
| 类型                       | 说明                    |
| ------------------------ | --------------------- |
| [IndexUtil](#indexutil8) | locale对应的IndexUtil对象。 |

**示例：** 
  ```
  var indexUtil= i18n.getInstance("zh-CN");
  ```


## IndexUtil<sup>8+</sup>


### getIndexList<sup>8+</sup>

getIndexList(): Array&lt;string&gt;

获取当前locale对应的索引列表。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型                  | 说明                 |
| ------------------- | ------------------ |
| Array&lt;string&gt; | 返回当前locale对应的索引列表。 |

**示例：** 
  ```
  var indexUtil = i18n.getInstance("zh-CN");
  var indexList = indexUtil.getIndexList();
  ```


### addLocale<sup>8+</sup>

addLocale(locale: string): void

将新的locale对应的索引加入当前索引列表。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明                           |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | 是    | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |

**示例：** 
  ```
  var indexUtil = i18n.getInstance("zh-CN");
  indexUtil.addLocale("en-US");
  ```


### getIndex<sup>8+</sup>

getIndex(text: string): string

获取text对应的索引。

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
  ```
  var indexUtil= i18n.getInstance("zh-CN");
  indexUtil.getIndex("hi");  // 返回h
  ```


## Character<sup>8+</sup>


### isDigit<sup>8+</sup>

static isDigit(char: string): boolean

判断字符串char是否是数字。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：** 
| 类型      | 说明                                   |
| ------- | ------------------------------------ |
| boolean | 返回true表示输入的字符是数字，返回false表示输入的字符不是数字。 |

**示例：** 
  ```
  var isdigit = i18n.Character.isDigit("1");  // 返回true
  ```


### isSpaceChar<sup>8+</sup>

static isSpaceChar(char: string): boolean

判断字符串char是否是空格符。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：** 
| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空格符，返回false表示输入的字符不是空格符。 |

**示例：** 
  ```
  var isspacechar = i18n.Character.isSpaceChar("a");  // 返回false
  ```


### isWhitespace<sup>8+</sup>

static isWhitespace(char: string): boolean

判断字符串char是否是空白符。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：** 
| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| boolean | 返回true表示输入的字符是空白符，返回false表示输入的字符不是空白符。 |

**示例：** 
  ```
  var iswhitespace = i18n.Character.isWhitespace("a");  // 返回false
  ```


### isRTL<sup>8+</sup>

static isRTL(char: string): boolean

判断字符串char是否是从右到左语言的字符。

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
  ```
  var isrtl = i18n.Character.isRTL("a");  // 返回false
  ```


### isIdeograph<sup>8+</sup>

static isIdeograph(char: string): boolean

判断字符串char是否是表意文字。

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
  ```
  var isideograph = i18n.Character.isIdeograph("a");  // 返回false
  ```


### isLetter<sup>8+</sup>

static isLetter(char: string): boolean

判断字符串char是否是字母。

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
  ```
  var isletter = i18n.Character.isLetter("a");  // 返回true
  ```


### isLowerCase<sup>8+</sup>

static isLowerCase(char: string): boolean

判断字符串char是否是小写字母。

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
  ```
  var islowercase = i18n.Character.isLowerCase("a");  // 返回true
  ```


### isUpperCase<sup>8+</sup>

static isUpperCase(char: string): boolean

判断字符串char是否是大写字母。

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
  ```
  var isuppercase = i18n.Character.isUpperCase("a");  // 返回false
  ```


### getType<sup>8+</sup>

static getType(char: string): string

获取输入字符串的一般类别值。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| char | string | 是    | 输入字符。 |

**返回值：** 
| 类型     | 说明          |
| ------ | ----------- |
| string | 输入字符的一般类别值。 |

**示例：** 
  ```
  var type = i18n.Character.getType("a");
  ```


## i18n.getLineInstance<sup>8+</sup>

getLineInstance(locale: string): BreakIterator

获取一个用于断句的[BreakIterator](#breakiterator8)对象。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | 是    | 合法的locale值，例如zh-Hans-CN。生成的[BreakIterator](#breakiterator8)将按照locale所指定的区域的规则来进行断句。 |

**返回值：** 
| 类型                               | 说明          |
| -------------------------------- | ----------- |
| [BreakIterator](#breakiterator8) | 用于进行断句的处理器。 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  ```


## BreakIterator<sup>8+</sup>


### setLineBreakText<sup>8+</sup>

setLineBreakText(text: string): void

设置[BreakIterator](#breakiterator8)要处理的文本。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名  | 类型     | 必填   | 说明                      |
| ---- | ------ | ---- | ----------------------- |
| text | string | 是    | 指定BreakIterator进行断句的文本。 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  ```


### getLineBreakText<sup>8+</sup>

getLineBreakText(): string

获取[BreakIterator](#breakiterator8)当前处理的文本。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                     |
| ------ | ---------------------- |
| string | BreakIterator对象正在处理的文本 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.getLineBreakText(); // Apple is my favorite fruit.
  ```


### current<sup>8+</sup>

current(): number

获取[BreakIterator](#breakiterator8)对象在当前处理的文本中的位置。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                          |
| ------ | --------------------------- |
| number | BreakIterator在当前所处理的文本中的位置。 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.current(); // 0
  ```


### first<sup>8+</sup>

first(): number

将[BreakIterator](#breakiterator8)对象设置到第一个可断句的分割点。第一个分割点总是被处理的文本的起始位置。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                |
| ------ | ----------------- |
| number | 被处理文本的第一个分割点的偏移量。 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.first(); // 0
  ```


### last<sup>8+</sup>

last(): number

将[BreakIterator](#breakiterator8)对象的位置设置到最后一个可断句的分割点。最后一个分割点总是被处理文本末尾的下一个位置。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                 |
| ------ | ------------------ |
| number | 被处理的文本的最后一个分割点的偏移量 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.last(); // 27
  ```


### next<sup>8+</sup>

next(index?: number): number

如果index给出，并且index是一个正数将[BreakIterator](#breakiterator8)向后移动number个可断句的分割点，如果n是一个负数，向前移动相应个分割点。若index没有给出，则相当于index = 1。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名   | 类型     | 必填   | 说明                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| index | number | 否    | [BreakIterator](#breakiterator8)将要移动的分割点数，正数代表向后移动，负数代表向前移动。若index没有给出，则按照index=1处理。 |

**返回值：** 
| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 返回移动了index个分割点后，当前[BreakIterator](#breakiterator8)在文本中的位置。若移动index个分割点后超出了所处理的文本的长度范围，返回-1。 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.first(); // 0
  iterator.next(); // 6
  iterator.next(10); // -1
  ```


### previous<sup>8+</sup>

previous(): number

将[BreakIterator](#breakiterator8)移动到前一个分割点处。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 返回移动到前一个分割点后，当前[BreakIterator](#breakiterator8)在文本中的位置。若移动index个分割点后超出了所处理的文本的长度范围，返回-1。 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.first(); // 0
  iterator.next(3); // 12
  iterator.previous(); // 9
  ```


### following<sup>8+</sup>

following(offset: number): number

将[BreakIterator](#breakiterator8)设置到由offset指定的位置的后面一个分割点。返回移动后[BreakIterator](#breakiterator8)的位置。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明                                       |
| ------ | ------ | ---- | ---------------------------------------- |
| offset | number | 是    | 将[BreakIterator](#breakiterator8)对象的位置设置到由offset所指定的位置的下一个分割点。 |

**返回值：** 
| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 返回[BreakIterator](#breakiterator8)移动后的位置，如果由offset所指定的位置的下一个分割点超出了文本的范围则返回-1。 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.following(0); // 6
  iterator.following(100); // -1
  iterator.current(); // 27
  ```


### isBoundary<sup>8+</sup>

isBoundary(offset: number): boolean

如果offset所指定的文本位置是一个分割点，那么返回true，否则返回false。如果返回true, 将[BreakIterator](#breakiterator8)对象设置到offset所指定的位置, 否则相当于调用[following](#following8)(offset)。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明          |
| ------ | ------ | ---- | ----------- |
| offset | number | 是    | 指定需要进行判断的位置 |

**返回值：** 
| 类型      | 说明                              |
| ------- | ------------------------------- |
| boolean | 如果是一个分割点返回true,&nbsp;否则返回false。 |

**示例：** 
  ```
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.isBoundary(0); // true;
  iterator.isBoundary(5); // false;
  ```


## i18n.is24HourClock<sup>7+</sup>

is24HourClock(): boolean

判断系统时间是否为24小时制。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 返回true，表示系统24小时开关开启；返回false，表示系统24小时开关关闭。 |

**示例：** 
  ```
  var is24HourClock = i18n.is24HourClock();
  ```


## i18n.set24HourClock<sup>7+</sup>

set24HourClock(option: boolean): boolean

修改系统时间的24小时制设置。

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
  ```
  // 将系统时间设置为24小时制
  var success = i18n.set24HourClock(true);
  ```


## i18n.addPreferredLanguage<sup>8+</sup>

addPreferredLanguage(language: string, index?: number): boolean

在系统偏好语言列表中的指定位置添加偏好语言。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名      | 类型     | 必填   | 说明         |
| -------- | ------ | ---- | ---------- |
| language | string | 是    | 待添加的偏好语言。  |
| index    | number | 否    | 偏好语言的添加位置。 |

**返回值：** 
| 类型      | 说明                            |
| ------- | ----------------------------- |
| boolean | 返回true，表示添加成功；返回false，表示添加失败。 |

**示例：** 
  ```
  // 将语言zh-CN添加到系统偏好语言列表中
  var language = 'zh-CN';
  var index = 0;
  var success = i18n.addPreferredLanguage(language, index);
  ```


## i18n.removePreferredLanguage<sup>8+</sup>

removePreferredLanguage(index: number): boolean

删除系统偏好语言列表中指定位置的偏好语言。

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
  ```
  // 删除系统偏好语言列表中的第一个偏好语言
  var index = 0;
  var success = i18n.removePreferredLanguage(index);
  ```


## i18n.getPreferredLanguageList<sup>8+</sup>

getPreferredLanguageList(): Array&lt;string&gt;

获取系统偏好语言列表。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型                  | 说明        |
| ------------------- | --------- |
| Array&lt;string&gt; | 系统偏好语言列表。 |

**示例：** 
  ```
  var preferredLanguageList = i18n.getPreferredLanguageList();
  ```


## i18n.getFirstPreferredLanguage<sup>8+</sup>

getFirstPreferredLanguage(): string

获取偏好语言列表中的第一个偏好语言。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明             |
| ------ | -------------- |
| string | 偏好语言列表中的第一个语言。 |

**示例：** 
  ```
  var firstPreferredLanguage = i18n.getFirstPreferredLanguage();
  ```


## i18n.getAppPreferredLanguage<sup>9+</sup>

getAppPreferredLanguage(): string

获取应用的偏好语言。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明             |
| ------ | -------------- |
| string | 应用的偏好语言。 |

**示例：** 
  ```
  var appPreferredLanguage = i18n.getAppPreferredLanguage();
  ```


## i18n.getTimeZone<sup>7+</sup>

getTimeZone(zoneID?: string): TimeZone

获取时区ID对应的时区对象。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| zondID | string | 否    | 时区ID。 |

**返回值：** 
| 类型       | 说明           |
| -------- | ------------ |
| TimeZone | 时区ID对应的时区对象。 |

**示例：** 
  ```
  var timezone = i18n.getTimeZone();
  ```


## TimeZone<sup>8+</sup>


### getID<sup>8+</sup>

getID(): string

获取时区对象的ID。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明           |
| ------ | ------------ |
| string | 时区对象对应的时区ID。 |

**示例：** 
  ```
  var timezone = i18n.getTimeZone();
  timezone.getID();
  ```


### getDisplayName<sup>8+</sup>

getDisplayName(locale?: string, isDST?: boolean): string

获取时区对象在指定区域的表示。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型      | 必填   | 说明                   |
| ------ | ------- | ---- | -------------------- |
| locale | string  | 否    | 区域ID。                |
| isDST  | boolean | 否    | 表示获取时区对象的表示时是否考虑夏令时。 |

**返回值：** 
| 类型     | 说明            |
| ------ | ------------- |
| string | 时区对象在指定区域的表示。 |

**示例：** 
  ```
  var timezone = i18n.getTimeZone();
  timezone.getDisplayName("zh-CN", false);
  ```


### getRawOffset<sup>8+</sup>

getRawOffset(): number

获取时区对象表示的时区与UTC时区的偏差。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                  |
| ------ | ------------------- |
| number | 时区对象表示的时区与UTC时区的偏差。 |

**示例：** 
  ```
  var timezone = i18n.getTimeZone();
  timezone.getRawOffset();
  ```


### getOffset<sup>8+</sup>

getOffset(date?: number): number

获取某一时刻时区对象表示的时区与UTC时区的偏差。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                      |
| ------ | ----------------------- |
| number | 某一时刻时区对象表示的时区与UTC时区的偏差。 |

**示例：** 
  ```
  var timezone = i18n.getTimeZone();
  timezone.getOffset(1234567890);
  ```


### getAvailableIDs<sup>9+</sup>

static getAvailableIDs(): Array&lt;string&gt;

获取系统支持的时区ID。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                      |
| ------ | ----------------------- |
| Array&lt;string&gt; | 系统支持的时区ID列表 |

**示例：** 
  ```
  var ids = i18n.TimeZone.getAvailableIDs();
  ```


### getAvailableZoneCityIDs<sup>9+</sup>

static getAvailableZoneCityIDs(): Array&lt;string&gt;

获取系统支持的时区城市ID。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型     | 说明                      |
| ------ | ----------------------- |
| Array&lt;string&gt; | 系统支持的时区城市ID列表 |

**示例：** 
  ```
  var cityIDs = i18n.TimeZone.getAvailableZoneCityIDs();
  ```


### getCityDisplayName<sup>9+</sup>

static getCityDisplayName(cityID: string, locale: string): string

获取某时区城市在locale下的本地化显示。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| cityID | string | 是    | 时区城市ID |
| locale | string | 是    | 区域ID |

**返回值：** 
| 类型     | 说明                      |
| ------ | ----------------------- |
| string | 时区城市在locale下的本地化显示 |

**示例：** 
  ```
  var displayName = i18n.TimeZone.getCityDisplayName("Shanghai", "zh-CN");
  ```


### getTimezoneFromCity<sup>9+</sup>

static getTimezoneFromCity(cityID: string): TimeZone

创建某时区城市对应的时区对象。

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| cityID | string | 是    | 时区城市ID |

**返回值：** 
| 类型     | 说明                      |
| ------ | ----------------------- |
| TimeZone | 时区城市对应的时区对象 |

**示例：** 
  ```
  var timezone = i18n.TimeZone.getTimezoneFromCity("Shanghai");
  ```


## i18n.setUsingLocalDigit<sup>9+</sup>

setUsingLocalDigit(flag: boolean): boolean

设置是否打开本地数字开关。<br>
该接口为系统接口。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Global.I18n

**参数：** 
| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| flag | boolean | 是    | true表示打开本地数字开关，false表示关闭本地数字开关。 |

**返回值：** 
| 类型       | 说明           |
| -------- | ------------ |
| boolean | true表示本地数字开关设置成功，false表示本地数字开关设置失败。 |

**示例：** 
  ```
  var status = i18n.setUsingLocalDigit(true);
  ```


## i18n.getUsingLocalDigit<sup>9+</sup>

getUsingLocalDigit(): boolean

获取系统当前是否打开本地数字开关。

**系统能力**：SystemCapability.Global.I18n

**返回值：** 
| 类型       | 说明           |
| -------- | ------------ |
| boolean | true表示系统当前已打开本地数字开关，false表示系统当前未打开本地数字开关。 |

**示例：** 
  ```
  var status = i18n.getUsingLocalDigit();
  ```