# Number and Unit of Measurement Formatting

## Use Cases

In different countries and cultures, numbers, currencies, and units of measurement are expressed in different ways, including what symbols are used as decimal separators, how many digits are displayed after separators, and what currencies and units of measurement are used. Suppose you want to display the number 1000 on the application UI to indicate the price of a product. If the fixed format **1,000** is used, it may be considered as 1 in some European countries where a comma is used as a decimal point. Formatting is therefore needed to format numbers, currencies, and units of measurement so that they are displayed on the application UI in line with local user habits.

## How to Develop

### Number Formatting

Number formatting is implemented through the [format](../reference/apis-localization-kit/js-apis-intl.md#format-1) API of the [NumberFormat](../reference/apis-localization-kit/js-apis-intl.md#numberformat) class. The development procedure is as follows:

1. Import the **intl** module.
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. Create a **NumberFormat** object.
   If you pass in a list of locales, the first valid locale will be used. If you do not pass in any locale, the current system locale will be used.
   The **NumberFormat** constructor allows you to set different number formatting formats by using **NumberOptions**. For details, see Table 1 to Table 8.

   ```ts
   let numberFormat: intl.NumberFormat = new intl.NumberFormat(locale: string | Array<string>, options?: NumberOptions);
   ```

3. Format numbers based on the configuration of **numberFormat**.
   ```ts
   let formattedNumber: string = numberFormat.format(number: number);
   ```

4. Obtain **NumberOptions** and view the configuration of formatting options.
   ```ts
   let options: intl.NumberOptions = numberFormat.resolvedOptions();
   ```

**Number Formatting Options**

You can use [NumberOptions](../reference/apis-localization-kit/js-apis-intl.md#numberoptions) to configure number formatting options, including minimum number of integer digits, minimum and maximum numbers of fraction digits, minimum and maximum numbers of significant digits, use of grouping for display, number notation, compact display, rounding mode, rounding priority, rounding increment, number display format, and numeral system. Supported number display formats include decimal, percent, currency, and unit.

The following uses **123000.123** as an example to show the parameter values and corresponding display effects.

**Table 1** Minimum number of integer digits (minimumIntegerDigits)

| Value| Display Effect| 
| -------- | -------- |
| 6 | 123,000.123 | 
| 7 | 0,123,000.123 | 

**Table 2** Minimum number of decimal places (minimumFractionDigits)

| Value| Display Effect| 
| -------- | -------- |
| 3 | 123,000.123 | 
| 4 | 123,000.1230 | 

**Table 3** Maximum number of fraction digits (maximumFractionDigits)

| Value| Display Effect| 
| -------- | -------- |
| 3 | 123,000.123 | 
| 2 | 123,000.12 | 

**Table 4** Minimum number of significant digits (minimumSignificantDigits)

| Value| Display Effect| 
| -------- | -------- |
| 9 | 123,000.123 | 
| 10 | 123,000.1230 | 

**Table 5** Maximum number of significant digits (maximumSignificantDigits)

| Value| Display Effect| 
| -------- | -------- |
| 9 | 123,000.123 | 
| 8 | 123,000.12 | 

**Table 6** Use of grouping for display (useGrouping)

| Value| Display Effect| 
| -------- | -------- |
| true | 123,000.123 | 
| false | 123000.123 | 

**Table 7** Number notation (notation)

| Value| Display Effect| 
| -------- | -------- |
| standard | 123,000.123 | 
| scientific | 1.230001E5 | 
| engineering | 123.000123E3 | 
| compact | 123K | 

**Table 8** Compact display (compactDisplay)

| Value| Display Effect| 
| -------- | -------- |
| short | 123K | 
| long | 123 thousand | 


**Development Example**

```ts
// Import the intl module.
import { intl } from '@kit.LocalizationKit';

// Display numbers in scientific notation.
let scientificFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN',
  {
    notation: 'scientific',
    maximumSignificantDigits: 3
  });
let formattedNumber: string = scientificFormat.format(123400); // formattedNumber = '1.23E5'

// Display numbers in the compact format.
let compactFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN',
  {
    notation: 'compact',
    compactDisplay: 'short'
  });
formattedNumber = compactFormat.format(123400); // formattedNumber = '12万)'

// Display the signs in numbers.
let signFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN', { signDisplay: 'always' });
formattedNumber = signFormat.format(123400); // formattedNumber = '+123,400'

// Display numbers in the percentage format.
let percentFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN', { style: 'percent' });
formattedNumber = percentFormat.format(0.25); // formattedNumber = '25%'

// Rounding mode
let truncFormat: intl.NumberFormat = new intl.NumberFormat('en',
  {
    roundingMode: 'trunc',
    maximumSignificantDigits: 2
  });
formattedNumber = truncFormat.format(2.28); // formattedNumber = '2.2'
formattedNumber = truncFormat.format(-2.25); // formattedNumber = '-2.2'

// Rounding priority
let lessPrecisionOptions: intl.NumberOptions = {
  roundingPriority: 'lessPrecision',
  maximumFractionDigits: 3,
  maximumSignificantDigits: 2
};
let lessPrecisionFormat: intl.NumberFormat = new intl.NumberFormat('en', lessPrecisionOptions);
formattedNumber = lessPrecisionFormat.format(1.23456); // formattedNumber = '1.2'

// Rounding increment
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

### Number Range Formatting

Number range formatting is implemented through the [formatRange](../reference/apis-localization-kit/js-apis-intl.md#formatrange-1) API of the [NumberFormat](../reference/apis-localization-kit/js-apis-intl.md#numberformat) class. The development procedure is as follows:

1. Import the **intl** module.
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. Create a **NumberFormat** object.
   If you pass in a list of locales, the first valid locale will be used. If you do not pass in any locale, the current system locale will be used.
   The **NumberFormat** constructor allows you to set different number formatting formats by using **NumberOptions**. For details, see Table 1 to Table 8.

   ```ts
   let numberFormat: intl.NumberFormat = new intl.NumberFormat(locale: string | Array<string>, options?: NumberOptions);
   ```

3. Format the start and end numbers based on the configuration of **numberFormat**.
   ```ts
   let formattedNumber: string = numberFormat.formatRange(startRange: number, endRange: number);
   ```

**Development Example**

```ts
// Import the intl module.
import { intl } from '@kit.LocalizationKit';

// Number range formatting
let options: intl.NumberOptions = {
  style: 'currency',
  currency: 'EUR',
  maximumFractionDigits: 0
};
let numberRangeFormat: intl.NumberFormat = new intl.NumberFormat('es-ES', options);
let formattedRange: string = numberRangeFormat.formatRange(2, 8); // formattedRange = '2-8 €'
formattedRange = numberRangeFormat.formatRange(2.9, 3.1); // formattedRange = '~3 €'
```


### Currency and Unit Formatting

Currency and unit formatting is based on number formatting. When creating a **NumberFormat** object for currency and unit formatting, set the number formatting style to **currency** and **unit**, respectively. Similarly, this can be done through [NumberOptions](../reference/apis-localization-kit/js-apis-intl.md#numberoptions). The following tables show the parameter values and corresponding display effects.

**Currency Formatting Options**

Assume that the currency unit is USD and the value is **-12300**.

**Table 9** Currency sign (currencySign)

| Value| Display Effect| 
| -------- | -------- |
| standard | -US$12,300.00 | 
| accounting | (US$12,300.00) | 

**Table 10** Currency display (currencyDisplay)

| Value| Display Effect| 
| -------- | -------- |
| symbol | -US$12,300.00 | 
| narrowSymbol | -$12,300.00 | 
| code | -USD 12,300.00 | 
| name | -12,300.00 US dollars | 

**Unit Formatting Options**

Assume that the unit name is **hectare** and the value is **-12300**.

**Table 11** Unit display (unitDisplay)

| Value| Display Effect| 
| -------- | -------- |
| long | -12,3000 hectares | 
| short | -12,300 ha | 
| narrow | -12,300ha | 

**Table 12** Unit usage (unitUsage)

| Value| Display Effect| 
| -------- | -------- |
| Unspecified| -12,300 ha | 
| default | -47.491 sq mi | 
| area-land-agricult | -30,393.962 ac | 


**Development Example**
```ts
// Import the intl module.
import { intl } from '@kit.LocalizationKit';

// Format the currency.
let currencyFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN', { style: 'currency', currency: 'USD' });
let formattedNumber: string = currencyFormat.format(123400); // formattedNumber = 'US$123,400.00'

// Display the currency using its name.
let currencyNameFormat: intl.NumberFormat = new intl.NumberFormat('zh-CN',
  {
    style: 'currency',
    currency: 'USD',
    currencyDisplay: 'name'
  });
formattedNumber = currencyNameFormat.format(123400); // formattedNumber = '123,400.00美元'

// Format units of measurement.
let unitFormat: intl.NumberFormat = new intl.NumberFormat('en-GB', { style: 'unit', unit: 'hectare' });
formattedNumber = unitFormat.format(123400); // formattedNumber = '123,400 ha'

// Format the units of measurement in the specified scenario, for example, area-land-agricult.
let unitUsageFormat: intl.NumberFormat = new intl.NumberFormat('en-GB',
  {
    style: 'unit',
    unit: 'hectare',
    unitUsage: 'area-land-agricult'
  });
formattedNumber = unitUsageFormat.format(123400); // formattedNumber = '304,928.041 ac'
```


### Units of Measurement Conversion

Units of measurement conversion and formatting are implemented by the [unitConvert](../reference/apis-localization-kit/js-apis-i18n.md#unitconvert9) API of the [I18NUtil](../reference/apis-localization-kit/js-apis-i18n.md#i18nutil9) class. The development procedure is as follows:

1. Import the **intl** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Change the unit of measurement.

   Convert the unit of measurement from **fromUnit** to **toUnit**, and format the unit based on the specified locale and formatting style. The display effect varies according to the style. For details, see Table 13.
   ```ts
   let convertedUnit: string = i18n.I18NUtil.unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string);
   ```

**Formatting Style**

Assume that **fromUnit** is **cup** (US unit), **toUnit** is **liter** (SI unit), and the value is **1000**.

**Table 13** Formatting style (style)

| Value| Display Effect| 
| -------- | -------- |
| long | 236.588 liters | 
| short | 236.588 L | 
| narrow | 236.588L | 

**Development Example**

```ts
// Import the i18n module.
import { i18n } from '@kit.LocalizationKit';

// Set the fromUnit and toUnit.
let fromUnit: i18n.UnitInfo = {unit: 'cup', measureSystem: 'US'};
let toUnit: i18n.UnitInfo = {unit: 'liter', measureSystem: 'SI'};

// Convert the unit based on the locale en-US.
let convertedUnit: string = i18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, 'en-US'); // convertedUnit = '236.588 L'

// Display the complete unit.
convertedUnit = i18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, 'en-US', 'long'); // convertedUnit = '236.588 liters'
```
<!--no_check-->