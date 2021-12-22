# 国际化-Intl

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> - Intl模块包含国际化能力基础接口（在ECMA 402中定义）。


## 导入模块

```
import Intl from '@ohos.intl';
```


## 权限

无


## Locale


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| language | string | 是 | 否 | 与区域设置关联的语言 |
| script | string | 是 | 否 | 语言的书写方式 |
| region | string | 是 | 否 | 与区域设置相关的地区 |
| baseName | string | 是 | 否 | Locale的基本核心信息 |
| caseFirst | string | 是 | 否 | 区域的整理规则是否考虑大小写 |
| calendar | string | 是 | 否 | 区域的日历信息 |
| collation | string | 是 | 否 | 区域的排序规则 |
| hourCycle | string | 是 | 否 | 区域的时制信息 |
| numberingSystem | string | 是 | 否 | 区域使用的数字系统 |
| numeric | boolean | 是 | 否 | 是否对数字字符具有特殊的排序规则处理 |


### constructor

constructor(locale: string, options?:options)

创建区域对象

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | locale | string | 是 | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |
  | options | options | 否 | 用于创建区域对象的选项。 |

- 示例：
  ```
  var locale = new Intl.Locale("zh-CN");
  ```


### toString

toString(): string

将区域信息转换为字符串

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 字符串形式的区域信息 |


- 示例：
  ```
  var locale = new Intl.Locale("zh-CN");
  locale.toString();
  ```


### maximize

maximize(): Locale

最大化区域信息，若缺少脚本与地区信息，则补齐。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Locale | 最大化后的区域对象 |


- 示例：
  ```
  var locale = new Intl.Locale("zh-CN");
  locale.maximize();
  ```


### minimize

minimize(): Locale

最小化区域信息，若包含脚本与地区信息，则去除。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Locale | 最小化后的区域对象 |


- 示例：
  ```
  var locale = new Intl.Locale("zh-CN");
  locale.minimize();
  ```


## DateTimeFormat


### constructor

constructor(locale: string, options?:DateTimeOptions)

创建时间日期格式化对象。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | locale | string | 是 | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |
  | options | [DateTimeOptions](#datetimeoptions) | 否 | 用于创建时间日期格式化的选项。 |

- 示例：
  ```
  var datefmt= new Intl.DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });
  ```


### constructor

constructor(locales: Array&lt;string&gt;, options?:DateTimeOptions)

创建时间日期格式化对象。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | locales | Array&lt;string&gt; | 是 | 包含区域设置信息的字符串的数组。 |
  | options | [DateTimeOptions](#datetimeoptions) | 否 | 用于创建时间日期格式化的选项。 |

- 示例：
  ```
  var datefmt= new Intl.DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
  ```


### format

format(date: Date): string;

格式化时间日期字符串。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | date | Date | 是 | 时间日期对象。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 格式化后的时间日期字符串 |


- 示例：
  ```
  var date = new Date(2021, 11, 17, 3, 24, 0);
  var datefmt = new Intl.DateTimeFormat("en-GB");
  datefmt.format(date);
  ```


### formatRange

formatRange(fromDate: Date, toDate: Date): string;

格式化时间日期段字符串。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | startDate | Date | 是 | 起始的时间日期 |
  | endDate | Date | 是 | 结束的时间日期 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 格式化后的时间日期段字符串 |


- 示例：
  ```
  var startDate = new Date(2021, 11, 17, 3, 24, 0);
  var endDate = new Date(2021, 11, 18, 3, 24, 0);
  var datefmt = new Intl.DateTimeFormat("en-GB");
  datefmt.formatRange(startDate, endDate);
  ```


### resolvedOptions

resolvedOptions(): DateTimeOptions

获取DateTimeFormat 对象的格式化选项。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [DateTimeOptions](#datetimeoptions) | DateTimeFormat&nbsp;对象的格式化选项。 |


- 示例：
  ```
  var datefmt = new Intl.DateTimeFormat("en-GB");
  datefmt.resolvedOptions();
  ```


## NumberFormat


### constructor

constructor(locale: string, options?:NumberOptions)

创建数字格式化对象。

参数：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| locale | string | 是 | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |
| options | [NumberOptions](#numberoptions) | 否 | 用于创建数字格式化的选项。 |

- 示例：
  ```
  var numfmt = new Intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
  ```


### constructor

constructor(locales: Array&lt;string&gt;, options?:NumberOptions)

创建数字格式化对象。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | locales | Array&lt;string&gt; | 是 | 包含区域设置信息的字符串的数组。 |
  | options | [NumberOptions](#numberoptions) | 否 | 用于创建数字格式化的选项。 |

- 示例：
  ```
  var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  ```


### format

format(number: number): string;

格式化数字字符串。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | number | number | 是 | 数字对象 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 格式化后的数字字符串 |


- 示例：
  ```
  var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  numfmt.format(1223);
  ```


### resolvedOptions

resolvedOptions(): NumberOptions

获取NumberFormat 对象的格式化选项。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [NumberOptions](#numberoptions) | NumberFormat&nbsp;对象的格式化选项。 |


- 示例：
  ```
  var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  numfmt.resolvedOptions();
  ```


## DateTimeOptions

表示时间日期格式化选项。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| locale | string | 是 | 否 | 区域参数 |
| dateStyle | string | 是 | 是 | 日期显示格式，取值范围："long",&nbsp;"short",&nbsp;"medium",&nbsp;"full" |
| timeStyle | string | 是 | 是 | 时间显示格式，取值范围："long",&nbsp;"short",&nbsp;"medium",&nbsp;"full" |
| hourCycle | string | 是 | 是 | 时制格式，取值范围："h11",&nbsp;"h12",&nbsp;"h23",&nbsp;"h24". |
| timeZone | string | 是 | 是 | 使用的时区（合法的IANA时区ID） |
| numberingSystem | string | 是 | 是 | 数字系统 |
| hour12 | boolean | 是 | 是 | 是否使用12小时制 |
| weekday | string | 是 | 是 | 工作日的显示格式，取值范围："long",&nbsp;"short",&nbsp;"narrow" |
| era | string | 是 | 是 | 时代的显示格式，取值范围："long",&nbsp;"short",&nbsp;"narrow" |
| year | string | 是 | 是 | 年份的显示格式，取值范围："numeric",&nbsp;"2-digit" |
| month | string | 是 | 是 | 月份的显示格式，取值范围："numeric",&nbsp;"2-digit",&nbsp;"long",&nbsp;"short",&nbsp;"narrow" |
| day | string | 是 | 是 | 日期的显示格式，取值范围："numeric",&nbsp;"2-digit" |
| hour | string | 是 | 是 | 小时的显示格式，取值范围："numeric",&nbsp;"2-digit" |
| minute | string | 是 | 是 | 分钟的显示格式，取值范围："numeric",&nbsp;"2-digit" |
| second | string | 是 | 是 | 秒钟的显示格式，取值范围："numeric",&nbsp;"2-digit" |
| timeZoneName | string | 是 | 是 | 时区名称的本地化表示 |
| dayPeriod | string | 是 | 是 | 时段的显示格式，取值范围："long",&nbsp;"short",&nbsp;"narrow" |
| localeMatcher | string | 是 | 是 | 要使用的区域匹配算法，取值范围："lookup",&nbsp;"best&nbsp;fit" |
| formatMatcher | string | 是 | 是 | 要使用的格式匹配算法，取值范围："basic",&nbsp;"best&nbsp;fit" |


## NumberOptions

表示设备支持的能力。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| locale | string | 是 | 否 | 区域参数 |
| currency | string | 是 | 是 | 货币单位 |
| currencySign | string | 是 | 是 | 货币单位的符号显示 |
| currencyDisplay | string | 是 | 是 | 货币的显示方式，取值范围："symbol",&nbsp;"narrowSymbol",&nbsp;"code",&nbsp;"name" |
| unit | string | 是 | 是 | 单位 |
| unitDisplay | string | 是 | 是 | 单位的显示格式，取值范围："long",&nbsp;"short",&nbsp;"medium" |
| signDisplay | string | 是 | 是 | 数字符号的显示格式，取值范围："auto",&nbsp;"never",&nbsp;"always",&nbsp;"expectZero" |
| compactDisplay | string | 是 | 是 | 紧凑型的显示格式，取值范围："long",&nbsp;"short" |
| notation | string | 是 | 是 | 数字的格式化规格，取值范围："standard",&nbsp;"scientific",&nbsp;"engineering",&nbsp;"compact" |
| localeMatcher | string | 是 | 是 | 要使用的区域匹配算法，取值范围："lookup",&nbsp;"best&nbsp;fit" |
| style | string | 是 | 是 | 数字的显示格式，取值范围："decimal",&nbsp;"currency",&nbsp;"percent",&nbsp;"unit" |
| numberingSystem | string | 是 | 是 | 数字系统 |
| useGrouping | boolean | 是 | 是 | 是否分组显示 |
| miniumumIntegerDigits | number | 是 | 是 | 最少整数个数 |
| miniumumFractionDigits | number | 是 | 是 | 最少小数个数 |
| maxiumumFractionDigits | number | 是 | 是 | 最多小数个数 |
| miniumumSignificantDigits | number | 是 | 是 | 最少有效位个数 |
| maxiumumSignificantDigits | number | 是 | 是 | 最多有效位个数 |
