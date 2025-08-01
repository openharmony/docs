# 数字与度量衡国际化

## 使用场景

在不同的国家和文化中，数字、货币和度量衡的表示方法各异，包括小数分隔符、小数位数、货币和度量衡单位等。例如，应用界面需要显示数字“1,000”（一千）表示商品价格。若采用固定格式“1,000”，在欧洲某些国家（如德国）用户会将其理解为“1”，因为这些国家使用逗号作为小数分隔符。为了确保界面符合当地习惯，需要对数字、货币和度量衡进行格式化，使其根据用户的语言和地区设置显示。

## 开发步骤

### 数字格式化

数字格式化请参考[Intl.NumberFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat)。

### 数字范围格式化

数字范围格式化请参考[formatRange](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat/formatRange)。

### 货币和单位格式化

货币和单位的格式化基于数字格式化，在创建货币和单位格式化对象时，将数字的显示风格分别设置为“currency(货币)”和“unit(单位)”。同样，对货币和度量衡进行格式化时也支持通过[Intl.NumberFormatOptions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat/NumberFormat#options)设置不同的格式。

### 度量衡转换

通过[I18NUtil](../reference/apis-localization-kit/js-apis-i18n.md#i18nutil9)类的[unitConvert](../reference/apis-localization-kit/js-apis-i18n.md#unitconvert9)接口实现单位转换和格式化。具体开发步骤如下：

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 将度量衡从一个单位（fromUnit）转换到另一个单位（toUnit）。

   将度量衡从fromUnit转换到toUnit，数值为value，并根据区域和风格格式化。style取不同值时，显示不同效果，详情见表1。
   ```ts
   let convertedUnit: string = i18n.I18NUtil.unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string);
   ```

**格式化风格**

以fromUnit为美制单位cup，toUnit为公制单位liter，数字大小1000为例。

**表1** 格式化使用的风格(style)

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
