# 数字与度量衡国际化

## 使用场景

在不同的国家和文化中，数字、货币和度量衡的表示方法不同，包括小数分隔符、小数位数、货币和度量衡单位等。例如，应用界面需要显示数字“1,000”（一千）表示商品价格。若采用固定格式“1,000”，在欧洲某些国家（如德国）用户会将其理解为“1”，因为这些国家使用逗号作为小数分隔符。为了确保界面符合当地习惯，需要对数字、货币和度量衡进行格式化。格式化后，界面会根据用户的语言和地区设置显示数字。

## 开发步骤

### 数字格式化

数字格式化通过[NumberFormat](../reference/apis-localization-kit/js-apis-intl.md#numberformat)的[format](../reference/apis-localization-kit/js-apis-intl.md#format-1)接口实现，具体开发步骤如下：

1. 导入模块。
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. 创建NumberFormat对象。
   传入区域ID列表时，使用第一个有效的区域ID创建对象。不传入区域参数时，使用系统当前的区域ID创建对象。
   构造函数支持通过NumberOptions设置不同的数字格式化格式，具体请参考表1-表8。

   ```ts
   let numberFormat: intl.NumberFormat = new intl.NumberFormat(locale: string | Array<string>, options?: NumberOptions);
   ```

3. 数字格式化，根据numberFormat的设置格式化number。
   ```ts
   let formattedNumber: string = numberFormat.format(number: number);
   ```

4. 获取数字格式化选项，查看对象的设置信息。
   ```ts
   let options: intl.NumberOptions = numberFormat.resolvedOptions();
   ```

**数字格式化选项**

通过[NumberOptions](../reference/apis-localization-kit/js-apis-intl.md#numberoptions)参数，可以设置数字的格式化选项，包括最小整数位数、最小小数位数、最大小数位数、最小有效位数、最大有效位数、是否分组显示、数字的表示方法、紧凑显示格式、舍入模式、舍入优先级、舍入增量以及数字的显示格式和数字系统。其中，数字的显示格式包括decimal(十进制)、percent(百分数)、currency(货币)和unit(单位)。

以123000.123为例，各选项取值和显示效果如下表所示：

**表1** 最小整数位数(minimumIntegerDigits)

| 取值 | 显示效果 | 
| -------- | -------- |
| 6 | 123,000.123 | 
| 7 | 0,123,000.123 | 

**表2** 最小小数位数(minimumFractionDigits)

| 取值 | 显示效果 | 
| -------- | -------- |
| 3 | 123,000.123 | 
| 4 | 123,000.1230 | 

**表3** 最大小数位数(maximumFractionDigits)

| 取值 | 显示效果 | 
| -------- | -------- |
| 3 | 123,000.123 | 
| 2 | 123,000.12 | 

**表4** 最小有效位数(minimumSignificantDigits)

| 取值 | 显示效果 | 
| -------- | -------- |
| 9 | 123,000.123 | 
| 10 | 123,000.1230 | 

**表5** 最大有效位数(maximumSignificantDigits)

| 取值 | 显示效果 | 
| -------- | -------- |
| 9 | 123,000.123 | 
| 8 | 123,000.12 | 

**表6** 是否分组显示(useGrouping)

| 取值 | 显示效果 | 
| -------- | -------- |
| true | 123,000.123 | 
| false | 123000.123 | 

**表7** 数字的表示方法(notation)

| 取值 | 显示效果 | 
| -------- | -------- |
| standard | 123,000.123 | 
| scientific | 1.230001E5 | 
| engineering | 123.000123E3 | 
| compact | 123K | 

**表8** 紧凑显示格式(compactDisplay)

| 取值 | 显示效果 | 
| -------- | -------- |
| short | 123K | 
| long | 123 thousand | 


**开发实例**

```ts
// 导入模块
import { intl } from '@kit.LocalizationKit';

// 用科学计数法显示数字
let scientificFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN',
  {
    notation: 'scientific',
    maximumSignificantDigits: 3
  });
let formattedNumber: string = scientificFormat.format(123400); // formattedNumber = '1.23E5'

// 用紧凑的格式显示数字
let compactFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN',
  {
    notation: 'compact',
    compactDisplay: 'short'
  });
formattedNumber = compactFormat.format(123400); // formattedNumber = '12万'

// 显示数字的符号
let signFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN', { signDisplay: 'always' });
formattedNumber = signFormat.format(123400); // formattedNumber = '+123,400'

// 显示百分数
let percentFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN', { style: 'percent' });
formattedNumber = percentFormat.format(0.25); // formattedNumber = '25%'

// 舍入模式
let truncFormat: intl.NumberFormat = new intl.NumberFormat('en',
  {
    roundingMode: 'trunc',
    maximumSignificantDigits: 2
  });
formattedNumber = truncFormat.format(2.28); // formattedNumber = '2.2'
formattedNumber = truncFormat.format(-2.25); // formattedNumber = '-2.2'

// 舍入优先级
let lessPrecisionOptions: intl.NumberOptions = {
  roundingPriority: 'lessPrecision',
  maximumFractionDigits: 3,
  maximumSignificantDigits: 2
};
let lessPrecisionFormat: intl.NumberFormat = new intl.NumberFormat('en', lessPrecisionOptions);
formattedNumber = lessPrecisionFormat.format(1.23456); // formattedNumber = '1.2'

// 舍入增量
let halfCeilNumOptions: intl.NumberOptions = {
  style: 'currency',
  currency: 'USD',
  roundingIncrement: 5,
  maximumFractionDigits: 2,
  roundingMode: 'halfCeil'
};
let halfCeilFormat: intl.NumberFormat = new intl.NumberFormat('en-US', halfCeilNumOptions);
formattedNumber = halfCeilFormat.format(11.21); // formattedNumber = '$11.20'
```

### 数字范围格式化

数字范围格式化通过[NumberFormat](../reference/apis-localization-kit/js-apis-intl.md#numberformat)的[formatRange](../reference/apis-localization-kit/js-apis-intl.md#formatrange-1)接口实现，具体开发步骤如下：

1. 导入模块。
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. 创建NumberFormat对象。
   传入区域ID列表时，使用第一个有效的区域ID创建对象。不传入区域参数时，使用系统当前的区域ID创建对象。
   构造函数支持通过NumberOptions设置不同的数字格式化格式，具体请参考表1-表8。

   ```ts
   let numberFormat: intl.NumberFormat = new intl.NumberFormat(locale: string | Array<string>, options?: NumberOptions);
   ```

3. 数字范围格式化，根据numberFormat的设置格式化开始和结束数字。
   ```ts
   let formattedNumber: string = numberFormat.formatRange(startRange: number, endRange: number);
   ```

**开发实例**

```ts
// 导入模块
import { intl } from '@kit.LocalizationKit';

// 数字范围格式化
let options: intl.NumberOptions = {
  style: 'currency',
  currency: 'EUR',
  maximumFractionDigits: 0
};
let numberRangeFormat: intl.NumberFormat = new intl.NumberFormat('es-ES', options);
let formattedRange: string = numberRangeFormat.formatRange(2, 8); // formattedRange = '2-8 €'
formattedRange = numberRangeFormat.formatRange(2.9, 3.1); // formattedRange = '~3 €'
```


### 货币和单位格式化

货币和单位的格式化基于数字格式化，在创建货币和单位格式化对象时，将数字的显示风格分别设置为“currency(货币)”和“unit(单位)”。同样，对货币和度量衡进行格式化时也支持通过[NumberOptions](../reference/apis-localization-kit/js-apis-intl.md#numberoptions)设置不同的格式，各属性参数取值和显示效果如下表所示：

**货币格式化选项**

以货币单位USD，数字大小-12300为例。

**表9** 货币单位的符号(currencySign)

| 取值 | 显示效果 | 
| -------- | -------- |
| standard | -US$12,300.00 | 
| accounting | (US$12,300.00) | 

**表10** 货币的显示方式(currencyDisplay)

| 取值 | 显示效果 | 
| -------- | -------- |
| symbol | -US$12,300.00 | 
| narrowSymbol | -$12,300.00 | 
| code | -USD 12,300.00 | 
| name | -12,300.00 US dollars | 

**单位格式化选项**

以单位hectare，数字大小-12300为例。

**表11** 单位的显示格式(unitDisplay)

| 取值 | 显示效果 | 
| -------- | -------- |
| long | -12,3000 hectares | 
| short | -12,300 ha | 
| narrow | -12,300ha | 

**表12** 单位的使用场景(unitUsage)

| 取值 | 显示效果 | 
| -------- | -------- |
| 未设置 | -12,300 ha | 
| default | -47.491 sq mi | 
| area-land-agricult | -30,393.962 ac | 


**开发实例**
```ts
// 导入模块
import { intl } from '@kit.LocalizationKit';

// 格式化货币
let currencyFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN', { style: 'currency', currency: 'USD' });
let formattedNumber: string = currencyFormat.format(123400); // formattedNumber = 'US$123,400.00'

// 用名称表示货币
let currencyNameFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN',
  {
    style: 'currency',
    currency: 'USD',
    currencyDisplay: 'name'
  });
formattedNumber = currencyNameFormat.format(123400); // formattedNumber = '123,400.00美元'

// 格式化度量衡
let unitFormat: intl.NumberFormat = new intl.NumberFormat('en-GB', { style: 'unit', unit: 'hectare' });
formattedNumber = unitFormat.format(123400); // formattedNumber = '123,400 ha'

// 格式化特定场景下度量衡，如面积-土地-农业
let unitUsageFormat: intl.NumberFormat = new intl.NumberFormat('en-GB',
  {
    style: 'unit',
    unit: 'hectare',
    unitUsage: 'area-land-agricult'
  });
formattedNumber = unitUsageFormat.format(123400); // formattedNumber = '304,928.041 ac'
```


### 度量衡转换

单位转换并根据区域和风格进行格式化，通过[I18NUtil](../reference/apis-localization-kit/js-apis-i18n.md#i18nutil9)类的[unitConvert](../reference/apis-localization-kit/js-apis-i18n.md#unitconvert9)接口实现，具体开发步骤如下：

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 将度量衡从一个单位转换到另一个单位。

   将度量衡从fromUnit转换到toUnit，数值为value，并根据区域和风格进行格式化。style可取不同的值，显示不同效果，具体请参考表13。
   ```ts
   let convertedUnit: string = i18n.I18NUtil.unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string);
   ```

**格式化风格**

以fromUnit为美制单位cup，toUnit为公制单位liter，数字大小1000为例。

**表13** 格式化使用的风格(style)

| 取值 | 显示效果 | 
| -------- | -------- |
| long | 236.588 liters | 
| short | 236.588 L | 
| narrow | 236.588L | 

**开发实例**

```ts
// 导入模块
import { i18n } from '@kit.LocalizationKit';

// 设置要转换的单位和目标单位
let fromUnit: i18n.UnitInfo = {unit: 'cup', measureSystem: 'US'};
let toUnit: i18n.UnitInfo = {unit: 'liter', measureSystem: 'SI'};

// 以en-US区域ID转换度量衡
let convertedUnit: string = i18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, 'en-US'); // convertedUnit = '236.588 L'

// 显示完整的度量衡
convertedUnit = i18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, 'en-US', 'long'); // convertedUnit = '236.588 liters'
```
