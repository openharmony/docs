# 时间日期国际化

## 使用场景

在不同的国家和文化中，时间和日期格式的表示方法有所不同，使用惯例的不同点包括：日期中年月日的顺序、时间中时分秒的分隔符等。若应用中需展示时间日期，要确保界面以合适的方式显示，以便用户能够理解。

时间日期国际化包括时间日期格式化、相对时间格式化、时间段格式化。时间日期格式化是指将时间和日期转换为指定格式的字符串。相对时间格式化是指将一个时间点与另一个时间点之间的时间差转换为指定格式，时间差如“30秒前”、“1天后”。时间段格式化是指将一段时间转换为指定格式，时间段如“星期三”、“8:00--11:30”。

## 约束与限制

1. 日期格式和时间格式需同时设置。若设置了时间格式，未设置日期格式，只显示时间格式；若设置了日期格式，未设置时间格式，只显示日期格式。

2. 若设置了时间或日期格式，则不支持设置年、月、日、时、分、秒、工作日格式；不设置时间或日期格式时，支持独立设置年、月、日、时、分、秒、工作日格式。

## 开发步骤

### 时间日期和相对时间格式化

时间日期格式化将表示时间日期的Date对象，通过[DateTimeFormat](../reference/apis-localization-kit/js-apis-intl.md#datetimeformat)类的[format](../reference/apis-localization-kit/js-apis-intl.md#format)接口实现格式化，具体开发步骤如下。

1. 导入模块。
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. 创建DateTimeFormat对象。
   传入单独的locale参数或locale列表，若传入列表使用第一个有效的locale创建对象。不传入locale参数时，使用系统当前的locale创建对象。
   构造函数支持通过DateTimeOptions设置不同的时间日期格式，具体请参考表1-表10。

   ```ts
   let dateFormat: intl.DateTimeFormat = new intl.DateTimeFormat(locale: string | Array<string>, options?: DateTimeOptions);
   let dateFormat: intl.DateTimeFormat = new intl.DateTimeFormat(); // 不传入locale参数
   ```

3. 时间日期和相对时间格式化。
   ```ts
   // 时间日期格式化
   let formattedDate: string = dateFormat.format(date: Date);

   // 相对时间格式化
   let formattedDateRange: string = dateFormat.formatRange(startDate: Date, endDate: Date);
   ```

4. 获取格式化选项，查看对象的设置信息。
   ```ts
   let options: intl.DateTimeOptions = dateFormat.resolvedOptions();
   ```

**时间日期格式化选项**

以时间：2021年9月17日 13:04:00、2021年9月17日 00:25:00，locale: zh-CN和en为例，说明[DateTimeOptions](../reference/apis-localization-kit/js-apis-intl.md#datetimeoptions)不同的取值和显示结果。

**表1** 日期显示格式(dateStyle)

| 取值   | 描述                                    | 2021年9月17日 13:04:00，locale为zh-CN显示结果 | 2021年9月17日 13:04:00，locale为en显示结果 |
| ------ | --------------------------------------- | ------------------------------------------  | ---------------------------------------- |
| full   | 完整的日期显示，包含年份、月份、天数和星期。| 2021年9月17日星期五                          | Friday, September 17, 2021               |
| long   | 详细的日期显示，包含年份、月份和天数。     | 2021年9月17日                                | September 17, 2021                       |
| short  | 简短的日期显示，包含年份、月份和天数。     | 2021/9/17                                   | 9/17/21                                  |
| medium | 中等长度日期显示，包含年份、月份和天数。   | 2021年9月17日                                | Sep 17, 2021                             |

**表2** 时间显示格式(timeStyle)

| 取值   | 描述 | 2021年9月17日 13:04:00，locale为zh-CN显示结果 |　2021年9月17日 13:04:00，locale为en显示结果 |
| ------ | ------------- | -------- | -------- |
| full   | 完整的时间显示，包含时区和时间，时间精确到秒。 | 中国标准时间 13:04:00 | 13:04:00 China Standard Time |
| long   | 详细的时间显示，包含时区和时间，时区以GMT+时区偏移表示，时间精确到秒。 | GMT+8 13:04:00 | 13:04:00 GMT+8 |
| short  | 简短时间显示，包含小时和分钟。 | 13:04 | 13:04 |
| medium | 中等长度时间显示，包含小时、分钟和秒。 | 13:04:00 | 13:04:00 |

**表3** 年份显示格式(year)

| 取值 | 描述 | 2021年9月17日 13:04:00，locale为zh-CN显示结果 | 2021年9月17日 13:04:00，locale为en显示结果 |
| -------- | --------- | -------- | -------- |
| numeric | 完整的年份显示。 | 2021年 | 2021 |
| 2-digit | 用完整年份的后2位数字表示年份。 | 21年 | 21 |

**表4** 星期显示格式(weekday)

| 取值 | 描述 | 2021年9月17日 13:04:00，locale为zh-CN显示结果 | 2021年9月17日 13:04:00，locale为en显示结果 |
| -------- | ------- | -------- | -------- |
| long | 详细的星期显示。 | 星期五 | Friday |
| short | 简短的星期显示。 | 周五 | Fri |
| narrow | 最简短的星期显示。 | 五 | F |

**表5** 时制格式(hourCycle)

| 取值 | 描述            | 2021年9月17日 13:04:00，locale为zh-CN显示结果 | 2021年9月17日 00:25:00，locale为zh-CN显示结果 |
| --- | --------------- | -------------------------------------------- | ------------------------------------------- |
| h11 | 用0-11表示小时。 | 下午1:04                                     |  上午0:25                                    |
| h12 | 用1-12表示小时。 | 下午1:04                                     |  上午12:25                                   |
| h23 | 用0-23表示小时。 | 13:04                                        | 00:25                                       |
| h24 | 用1-24表示小时。 | 13:04                                        | 24:25                                       |

> **说明**
>
> 在不设置dateStyle或timeStyle参数时，hourCycle不同取值的显示效果如上表格。


**表6** 时制格式(hourCycle)

| 取值 | 描述            | 2021年9月17日 13:04:00，locale为zh-CN显示结果 | 2021年9月17日 00:25:00，locale为zh-CN显示结果 |
| --- | --------------- | -------------------------------------------- | ------------------------------------------- |
| h11 | 用1-24表示小时。 | 下午13:04                                    |  上午24:25                                   |
| h12 | 用1-12表示小时。 | 下午1:04                                     |  上午12:25                                   |
| h23 | 用0-11表示小时。 | 1:04                                         |  0:25                                       |
| h24 | 用0-23表示小时。 | 13:04                                        |  0:25                                       |

> **说明**
>
> 在设置dateStyle或timeStyle参数时，hourCycle不同取值的显示效果如上表格。

**表7** 月份格式(month)

| 取值 | 描述 | 2021年9月17日 13:04:00，locale为zh-CN显示结果 | 2021年9月17日 13:04:00，locale为en显示结果 |
| -------- | --------- | -------- | -------- |
| numeric | 以数字形式显示月份。 | 9月 | 9 |
| 2-digit | 以两位数字形式显示月份。 | 09月 | 09 |
| long | 详细的月份显示。 | 九月 | September |
| short | 简短的月份显示。 | 9月 | Sep |
| narrow | 最简短的月份显示。 | 9 | S |

**表8** 时区名称的本地化表示(timeZoneName)

| 取值  | 描述                | 2021年9月17日 13:04:00，locale为zh-CN显示结果 | 2021年9月17日 13:04:00，locale为en显示结果 |
| ----- | ------------------ | -------------------------------------------- | ---------------------------------------- |
| long  | 详细的时区名称显示。 | 中国标准时间                                  | China Standard Time                      |
| short | 简短的时区名称显示。 | GMT+8                                        | GMT+8                                    |

**表9** 纪元的显示格式(era)

| 取值 | 描述 | 2021年9月17日 13:04:00，locale为zh-CN显示效果 | 2021年9月17日 13:04:00，locale为en显示效果 |
| -------- | ------ | -------- | -------- |
| long | 详细的纪元显示。 | 公元 | Anno Domini |
| short | 简短的纪元显示。 | 公元 | AD |
| narrow | 最简短的纪元显示。 | 公元 | A |

**表10** 时段的显示格式(dayPeriod)

| 取值 | 描述 | 2021年9月17日 13:04:00，locale为zh-CN显示效果 | 2021年9月17日 13:04:00，locale为en显示效果 |
| -------- | ------ | -------- | -------- |
| long | 详细的时段表述。 | 下午 | in the afternoon |
| short | 简短的时段表示。 | 下午 | in the afternoon |
| narrow | 最简短的时段表示。 | 下午 | in the afternoon |

**开发实例**
```ts
// 导入模块
import { intl } from '@kit.LocalizationKit';

let date: Date = new Date(2021, 8, 17, 13, 4, 0); // 时间日期为2021.09.17 13:04:00
let startDate: Date = new Date(2021, 8, 17, 13, 4, 0);
let endDate: Date = new Date(2021, 8, 18, 13, 4, 0);

// 在软件上展示完整的时间信息
let fullFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN', { dateStyle: 'full', timeStyle: 'full' });
let formattedDate: string = fullFormat.format(date); // formattedDate = '2021年9月17日星期五 中国标准时间 13:04:00'

// 在有限的空间展示简短的时间信息
let shortFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN', { dateStyle: 'short', timeStyle: 'short' });
formattedDate = shortFormat.format(date); // formattedDate = '2021/9/17 13:04'

// 自定义年月日时分秒的显示效果
let customFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN',
  {
    year: 'numeric',
    month: '2-digit',
    day: '2-digit',
    hour: '2-digit',
    minute: '2-digit',
    second: '2-digit'
  });
formattedDate = customFormat.format(date); // formattedDate = '2021/09/17 13:04:00'

// 仅显示一部分时间
let partialFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN',
  {
    month: 'long',
    day: 'numeric',
    weekday: 'long'
  });
formattedDate = partialFormat.format(date); // formattedDate = '9月17日星期五'

// 自定义时制格式
let hourCycleFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN',
  {
    dateStyle: 'short',
    timeStyle: 'short',
    hourCycle: 'h11'
  });
formattedDate = hourCycleFormat.format(date); // formattedDate = '2021/9/17 下午13:04'

// 面向习惯于其他数字系统的用户
let numberingSystemFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN',
  {
    dateStyle: 'short',
    timeStyle: 'short',
    numberingSystem: 'arab'
  });
formattedDate = numberingSystemFormat.format(date); // formattedDate = '٢٠٢١/٩/١٧ ١٣:٠٤'

// 格式化时间段
let dateRangeFormat: intl.DateTimeFormat = new intl.DateTimeFormat('en-GB');
let formattedDateRange: string =
  dateRangeFormat.formatRange(startDate, endDate); // formattedDateRange = '17/09/2021 - 18/09/2021'

// 获取格式化选项
let dateFormat: intl.DateTimeFormat = new intl.DateTimeFormat('en-GB', { dateStyle: 'full' });
let options: intl.DateTimeOptions = dateFormat.resolvedOptions();
let dateStyle: string | undefined = options.dateStyle; // dateStyle = 'full'
```

### 相对时间格式化

格式化相对时间将表示时间日期的Date对象，通过[RelativeTimeFormat](../reference/apis-localization-kit/js-apis-intl.md#relativetimeformat8)类的[format](../reference/apis-localization-kit/js-apis-intl.md#format8)接口实现格式化，具体开发步骤如下。

1. 导入模块。
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. 创建RelativeTimeFormat对象。
   构造函数支持通过RelativeTimeFormatInputOptions设置不同的输出消息格式和国际化消息长度，具体请参考表7-表8。
   ```ts
   let relativeTimeFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat(locale: string | Array<string>, options?: RelativeTimeFormatInputOptions);
   ```

3. 格式化相对时间。value为格式化的数值，unit为格式化的单位。
   ```ts
   let formattedRelativeTime: string = relativeTimeFormat.format(value: number, unit: string);
   ```

4. 自定义相对时间的格式化。
   ```ts
   let parts: Array<object> = relativeTimeFormat.formatToParts(value: number, unit: string);
   ```

5. 获取相对时间格式化选项，查看对象的设置信息。
   ```ts
   let options: intl.RelativeTimeFormatInputOptions = relativeTimeFormat.resolvedOptions();
   ```

**相对时间格式化选项**

以相对时间：一天前，locale: fr-FR和en-GB为例，说明[RelativeTimeFormatInputOptions](../reference/apis-localization-kit/js-apis-intl.md#relativetimeformatinputoptions8)不同的取值和显示结果。

**表11** 数值表示(numeric)

| 取值   | 描述                                          | 显示效果(fr-FR) | 显示效果(en-GB) |
| ------ | -------------------------------------------- | -------------- | --------------- |
| always | 使用数值表示相对时间。                         | il y a 1 jour  | 1 day ago       |
| auto   | 根据locale自适应的选择短语或者数值表示相对时间。 | hier           | yesterday       |

**表12** 相对时间样式(style)

| 取值   | 描述                  | 显示效果(fr-FR) | 显示效果(en-GB) |
| ------ | -------------------- | -------------- | --------------  |
| long   | 详细的相对时间显示。   | il y a 1 jour  | 1 day ago       |
| short  | 简短的相对时间显示。   | il y a 1 j     | 1 day ago       |
| narrow | 最简短的相对时间显示。 | -1 j           | 1 day ago       |


**开发实例**
```ts
// 导入模块
import { intl } from '@kit.LocalizationKit';

// 显示相对时间
let relativeTimeFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en-GB');
let formattedRelativeTime: string = relativeTimeFormat.format(-1, 'day'); // formattedRelativeTime = '1 day ago'

// 口语化
let numericAutoFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en-GB', { numeric: 'auto' });
formattedRelativeTime = numericAutoFormat.format(-1, 'day'); // formattedRelativeTime = 'yesterday'

// 部分语言支持更为简短的显示风格
let longFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('fr-FR'); // 默认style为long
formattedRelativeTime = longFormat.format(-1, 'day'); // formattedRelativeTime = 'il y a 1 jour'
let narrowFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('fr-FR', { style: 'narrow' });
formattedRelativeTime = narrowFormat.format(-1, 'day'); // formattedRelativeTime = '-1 j'

// 自定义区域设置格式的相对时间格式
let partFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en-GB', { style: 'long' });
// parts = [{type: 'literal', value: 'in'}, {type: 'integer', value: 1, unit: 'day'}, {type: 'literal', value: 'day'}]
let parts: object[] = partFormat.formatToParts(1, 'day');

// 获取RelativeTimeFormat对象的格式化选项
let resolvedFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en-GB', { numeric: 'auto' });
let options: intl.RelativeTimeFormatResolvedOptions = resolvedFormat.resolvedOptions();
let numeric: string = options.numeric; // numeric = 'auto'
```
