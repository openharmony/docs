# Number and Unit of Measurement Formatting

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=1a7fdda7cb0bdacc6b1c367c8fd0def17530cd88 translatedAt=2026-08-15T01:53:17.845Z pushedAt=2026-08-15T08:42:09.661Z -->

## Function Description

In different countries and cultures, numbers, currencies, and units of measurement are expressed in different ways, including what symbols are used as decimal separators, how many digits are displayed after separators, and what currencies and units of measurement are used. Suppose you want to display the number 1000 on the application UI to indicate the price of a product. If the fixed format **1,000** is used, it may be considered as 1 in some European countries where a comma is used as a decimal point. Formatting is therefore needed to format numbers, currencies, and units of measurement so that they are displayed on the application UI in line with local user habits.

## How to Develop

### Number Formatting

For details about number formatting, see [Intl.NumberFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat).

### Number Range Formatting

For details about number range formatting, see [formatRange](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat/formatRange).

### Currency and Unit Formatting

Currency and unit formatting is based on number formatting. When creating a **NumberFormat** object for currency and unit formatting, set the number formatting style to **currency** and **unit**, respectively. Similarly, you can also use [Intl.NumberFormatOptions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat/NumberFormat#options) to set different formatting options for currencies and units of measurement.

### Units of Measurement Conversion

Units of measurement include length, area, volume, and capacity. You can achieve the conversion and formatting of units of measurement via the [unitConvert](../reference/apis-localization-kit/js-apis-i18n.md#unitconvert9) API of the [I18NUtil](../reference/apis-localization-kit/js-apis-i18n.md#i18nutil9) class.

**Formatting Style**

You can use **unitConvert** to convert one measurement unit into another and formats the unit based on the specified locale. You can use the **style** parameter to specify the formatting style.

The following example assumes that the source unit is cup (US), the target unit is liter (metric), and the number is 1000.

**Table 1** Formatting style (style)

| Value| Display Effect| 
| -------- | -------- |
| long | 236.588 liters | 
| short | 236.588 L | 
| narrow | 236.588L | 

**Development Example**

1. Import the required module.

   <!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/NumberMeasurementFormatting.ets) -->

   ``` TypeScript
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Convert the unit.

   <!-- @[measurement_conversion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/NumberMeasurementFormatting.ets) -->

   ``` TypeScript
   // Set the source unit and target unit for conversion.
   let fromUnit: i18n.UnitInfo = {unit: 'cup', measureSystem: 'US'};
   let toUnit: i18n.UnitInfo = {unit: 'liter', measureSystem: 'SI'};

   // Convert the measurement using the en-US locale ID.
   let simplifyConvertedUnit = i18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, 'en-US'); // simplifyConvertedUnit = '236.588 L'

   // Display the complete measurement.
   let convertedUnit = i18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, 'en-US', 'long'); // convertedUnit = '236.588 liters'
   ```