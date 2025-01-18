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
   构造函数支持通过DateTimeOptions设置不同的时间日期格式，具体请参考表1-表6。

   ```ts
   let dateFormat: intl.DateTimeFormat = new intl.DateTimeFormat(locale: string | Array<string>, options?: DateTimeOptions);
   let dateFormat: intl.DateTimeFormat = new intl.DateTimeFormat(); //不传入locale参数
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

以时间：2021年9月17日 13:04:00，locale: zh-CN为例，说明[DateTimeOptions](../reference/apis-localization-kit/js-apis-intl.md#datetimeoptions)不同的取值和显示结果。

**表1** 日期显示格式(dateStyle)

| 取值 | 显示结果 | 
| -------- | -------- |
| full | 2021年9月17日星期五 | 
| long | 2021年9月17日 | 
| short | 2021/9/17 | 
| medium | 2021年9月17日 | 

**表2** 时间显示格式(timeStyle)

| 取值 | 显示效果 | 
| -------- | -------- |
| full | 中国标准时间 13:04:00 | 
| long | GMT+8 13:4:00 | 
| short | 13:04 | 
| medium | 13:04:00 | 

**表3** 年份显示格式(year)

| 取值 | 显示效果 | 
| -------- | -------- |
| numeric | 2021 | 
| 2-digit | 21 | 

**表4** 工作日显示格式(weekday)

| 取值 | 显示效果 | 
| -------- | -------- |
| long | 星期五 | 
| short | 周五 | 
| narrow | 五 | 


**表5** 时制格式(hourCycle)

| 取值 | 显示效果 | 
| -------- | -------- |
| h11 | 下午13:04 | 
| h12 | 下午1:04 | 
| h23 | 1:04 | 
| h24 | 13:04 | 

**开发实例**
```ts
// 导入模块
import { intl } from '@kit.LocalizationKit';

let date = new Date(2021, 8, 17, 13, 4, 0); // 时间日期为2021.09.17 13:04:00
let startDate = new Date(2021, 8, 17, 13, 4, 0);
let endDate = new Date(2021, 8, 18, 13, 4, 0);

// 在软件上展示完整的时间信息
let dateFormat1 = new intl.DateTimeFormat('zh-CN', {dateStyle: 'full', timeStyle: 'full'});
let formattedDate1 = dateFormat1.format(date); // formattedDate1: 2021年9月17日星期五 中国标准时间 13:04:00

// 在有限的空间展示简短的时间信息
let dateFormat2 = new intl.DateTimeFormat('zh-CN', {dateStyle: 'short', timeStyle: 'short'});
let formattedDate2 = dateFormat2.format(date); // formattedDate2: 2021/9/17 13:04 

// 自定义年月日时分秒的显示效果
let dateFormat3 = new intl.DateTimeFormat('zh-CN', {year: 'numeric', month: '2-digit', day: '2-digit', hour: '2-digit', minute: '2-digit', second: '2-digit'});
let formattedDate3 = dateFormat3.format(date); // formattedDate3: 2021/09/17 13:04:00

// 仅显示一部分时间
let dateFormat4 = new intl.DateTimeFormat('zh-CN', {month: 'long', day: 'numeric', weekday: 'long' });
let formattedDate4 = dateFormat4.format(date); // formattedDate4: 9月17日星期五

// 自定义时制格式
let dateFormat5 = new intl.DateTimeFormat('zh-CN', {dateStyle: 'short', timeStyle: 'short', hourCycle: 'h11'});
let formattedDate5 = dateFormat5.format(date); // formattedDate5: 2021/9/17 下午13:04

// 面向习惯于其他数字系统的用户
let dateFormat6 = new intl.DateTimeFormat('zh-CN', {dateStyle: 'short', timeStyle: 'short', numberingSystem: 'arab'});
let formattedDate6 = dateFormat6.format(date); // formattedDate6: ٢٠٢١/٩/١٧ ١٣:٠٤

// 格式化时间段
let dataFormat7 = new intl.DateTimeFormat('en-GB');
let formattedDateRange = dataFormat7.formatRange(startDate, endDate); // formattedDateRange: 17/09/2021 - 18/09/2021

// 获取格式化选项
let dataFormat8 = new intl.DateTimeFormat('en-GB', {dateStyle: 'full'});
let options = dataFormat8.resolvedOptions();
let dateStyle = options.dateStyle; // dateStyle: full
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

**表6** 输出消息格式(numeric)

| 取值 | 显示效果(fr-FR) | 显示效果(en-GB) | 
| -------- | -------- | -------- |
| always | il y a 1 jour | 1 day ago | 
| auto | hier | yesterday | 

**表7** 国际化消息长度(style)

| 取值 | 显示效果(fr-FR) | 显示效果(en-GB) | 
| -------- | -------- | -------- |
| long | il y a 1 jour | 1 day ago | 
| short | il y a 1 j | 1 day ago | 
| narrow | -1 j | 1 day ago | 


**开发实例**
```ts
// 导入模块
import { intl } from '@kit.LocalizationKit';

// 显示相对时间
let relativeTimeFormat1 = new intl.RelativeTimeFormat('en-GB');
let formattedRelativeTime1 = relativeTimeFormat1.format(-1, 'day'); // formattedRelativeTime1: 1 day ago

// 口语化
let relativeTimeFormat2 = new intl.RelativeTimeFormat('en-GB', {numeric: "auto"});
let formattedRelativeTime2 = relativeTimeFormat2.format(-1, 'day'); // formattedRelativeTime2: yesterday

// 部分语言支持更为简短的显示风格
let relativeTimeFormat3 = new intl.RelativeTimeFormat('fr-FR'); // 默认style为long
let formattedRelativeTime3 = relativeTimeFormat3.format(-1, 'day'); // formattedRelativeTime3: il y a 1 jour
let relativeTimeFormat4 = new intl.RelativeTimeFormat('fr-FR', {style: 'narrow'});
let formattedRelativeTime4 = relativeTimeFormat4.format(-1, 'day'); // formattedRelativeTime4: -1 j

// 自定义区域设置格式的相对时间格式
let relativeTimeFormat5 = new intl.RelativeTimeFormat('en-GB', {style: 'long'});
// parts: [{type: 'literal', value: 'in'}, {type: 'integer', value: 1, unit: 'day'}, {type: 'literal', value: 'day'}]
let parts = relativeTimeFormat5.formatToParts(1, 'day');

// 获取RelativeTimeFormat对象的格式化选项
let relativeTimeFormat6 = new intl.RelativeTimeFormat('en-GB', {numeric: 'auto'});
let options = relativeTimeFormat6.resolvedOptions();
let numeric = options.numeric; // numeric: auto
```
