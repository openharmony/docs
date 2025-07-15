# 时间日期国际化

## 使用场景

在不同的国家和文化中，时间和日期格式的表示方法存在差异，具体表现在日期中年月日的顺序以及时间中时分秒的分隔符。若应用中需展示时间日期，要确保界面以合适的方式显示，以便用户能够理解。

时间日期国际化包括时间日期格式化、相对时间格式化、时间段格式化。时间日期格式化是指将时间和日期转换为指定格式的字符串。相对时间格式化是指将一个时间点与另一个时间点之间的时间差转换为指定格式，例如“30秒前”、“1天后”。时间段格式化是指将一段时间转换为指定格式，例如“星期三”、“8:00 - 11:30”。

## 约束与限制

1. dateStyle和timeStyle需同时设置。设置timeStyle但不设置dateStyle时，只显示时间；设置dateStyle但不设置timeStyle时，只显示日期。

2. 设置dateStyle或timeStyle时，不支持设置年、月、日、时、分、秒、工作日格式；不设置dateStyle和timeStyle时，支持独立设置年、月、日、时、分、秒、工作日格式。

## 开发步骤

### 时间日期格式化

具体可参考[Intl.DateTimeFormat](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat)。

### 相对时间格式化

格式化相对时间将表示时间日期的Date对象，通过[RelativeTimeFormat](../reference/apis-localization-kit/js-apis-intl.md#relativetimeformatdeprecated)类的[format](../reference/apis-localization-kit/js-apis-intl.md#formatdeprecated-2)接口实现格式化，具体开发步骤如下：

1. 导入模块。
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. 创建RelativeTimeFormat对象。
   构造函数支持通过RelativeTimeFormatInputOptions设置不同的输出消息格式和国际化消息长度，具体请参考表1和表2。
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

以相对时间：一天前，区域ID: fr-FR和en-GB为例，说明[RelativeTimeFormatInputOptions](../reference/apis-localization-kit/js-apis-intl.md#relativetimeformatinputoptionsdeprecated)不同的取值和显示结果。

**表1** 数值表示(numeric)

| 取值   | 描述                                          | 显示效果(fr-FR) | 显示效果(en-GB) |
| ------ | -------------------------------------------- | -------------- | --------------- |
| always | 使用数值表示相对时间。                         | il y a 1 jour  | 1 day ago       |
| auto   | 根据区域ID自适应选择短语或数值表示相对时间。 | hier           | yesterday       |

**表2** 相对时间样式(style)

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
