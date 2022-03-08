# Internationalization – intl

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - This module contains standard i18n APIs, which are defined in ECMA 402.


## Modules to Import

```
import Intl from '@ohos.intl';
```


## Locale


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| language | string | Yes| No| Language associated with the locale, for example, **zh**.<br>**System capability**: SystemCapability.Global.I18n|
| script | string | Yes| No| Script type of the language, for example, **Hans**.<br>**System capability**: SystemCapability.Global.I18n|
| region | string | Yes| No| Region associated with the locale, for example, **CN**.<br>**System capability**: SystemCapability.Global.I18n|
| baseName | string | Yes| No| Basic key information about the locale, which consists of the language, script, and region, for example, **zh-Hans-CN**.<br>**System capability**: SystemCapability.Global.I18n|
| caseFirst | string | Yes| No| Whether case is taken into account for the locale's collation rules. The value can be **upper**, **lower**, or **false**.<br>**System capability**: SystemCapability.Global.I18n|
| calendar | string | Yes| No| Calendar for the locale. The value can be any of the following: buddhist, chinese, coptic, dangi, ethioaa, ethiopic, gregory, hebrew, indian, islamic, islamic-umalqura, islamic-tbla, islamic-civil, islamic-rgsa, iso8601, japanese, persian, roc, islamicc.<br>**System capability**: SystemCapability.Global.I18n|
| collation | string | Yes| No| Rule for sorting regions. The value can be any of the following: big5han, compat, dict, direct, ducet, eor, gb2312, phonebk, phonetic, pinyin, reformed, searchjl, stroke, trad, unihan, zhuyin.<br>**System capability**: SystemCapability.Global.I18n|
| hourCycle | string | Yes| No| Time system for the locale. The value can be any of the following: h12, h23, h11, and h24.<br>**System capability**: SystemCapability.Global.I18n|
| numberingSystem | string | Yes| No| Numbering system for the locale. The value can be any of the following: adlm, ahom, arab, arabext, bali, beng, bhks, brah, cakm, cham, deva, diak, fullwide, gong, gonm, gujr, guru, hanidec, hmng, hmnp, java, kali, khmr, knda, lana, lanatham, laoo, latn, lepc, limb, mathbold, mathdbl, mathmono, mathsanb, mathsans, mlym, modi, mong, mroo, mtei, mymr, mymrshan, mymrtlng, newa, nkoo, olck, orya, osma, rohg, saur, segment, shrd, sind, sinh, sora, sund, takr, talu, tamldec, telu, thai, tibt, tirh, vaii, wara, wcho.<br>**System capability**: SystemCapability.Global.I18n|
| numeric | boolean | Yes| No| Whether to apply special collation rules for numeric characters.<br>**System capability**: SystemCapability.Global.I18n|


### constructor

constructor(locale: string, options?: options)

Creates a Locale object.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | locale | string | Yes| A string containing locale information, including the language, optional script, and region.|
  | options | options | No| Options for creating the **Locale** object.|

- Example
  ```
  var locale = new Intl.Locale("zh-CN");
  ```


### toString

toString(): string

Converts locale information to a string.

**System capability**: SystemCapability.Global.I18n

- Return value
  | Type| Description|
  | -------- | -------- |
  | string | String containing locale information.|

- Example
  ```
  var locale = new Intl.Locale("zh-CN");
  locale.toString();
  ```


### maximize

maximize(): Locale

Maximizes information of the **Locale** object. If the script and locale information is missing, add the information.

**System capability**: SystemCapability.Global.I18n

- Return value
  | Type| Description|
  | -------- | -------- |
  | [Locale](#locale) | **Locale** object with the maximized information.|

- Example
  ```
  var locale = new Intl.Locale("zh-CN");
  locale.maximize();
  ```


### minimize

minimize(): Locale

Minimizes information of the **Locale** object. If the script and locale information is present, delete the information.

**System capability**: SystemCapability.Global.I18n

- Return value
  | Type| Description|
  | -------- | -------- |
  | [Locale](#locale) | **Locale** object with the minimized information.|

- Example
  ```
  var locale = new Intl.Locale("zh-CN");
  locale.minimize();
  ```


## DateTimeFormat


### constructor

constructor(locale: string, options?: DateTimeOptions)

Creates a **DateTimeOptions** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | locale | string | Yes| A string containing locale information, including the language, optional script, and region.|
  | options | [DateTimeOptions](#datetimeoptions) | No| Options for creating a **DateTimeFormat** object.|

- Example
  ```
  var datefmt= new Intl.DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });
  ```


### constructor

constructor(locales: Array&lt;string&gt;, options?: DateTimeOptions)

Creates a **DateTimeOptions** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | locales | Array&lt;string&gt; | Yes| An array of strings containing locale information.|
  | options | [DateTimeOptions](#datetimeoptions) | No| Options for creating a **DateTimeFormat** object.|

- Example
  ```
  var datefmt= new Intl.DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
  ```


### format

format(date: Date): string

Formats the specified date and time.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | date | Date | Yes| Date and time to be formatted.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | string | A string containing the formatted date and time.|

- Example
  ```
  var date = new Date(2021, 11, 17, 3, 24, 0);
  var datefmt = new Intl.DateTimeFormat("en-GB");
  datefmt.format(date);
  ```


### formatRange

formatRange(fromDate: Date, toDate: Date): string

Formats the specified date range.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | startDate | Date | Yes| Start date and time to be formatted.|
  | endDate | Date | Yes| End date and time to be formatted.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | string | A string containing the formatted date and time range.|

- Example
  ```
  var startDate = new Date(2021, 11, 17, 3, 24, 0);
  var endDate = new Date(2021, 11, 18, 3, 24, 0);
  var datefmt = new Intl.DateTimeFormat("en-GB");
  datefmt.formatRange(startDate, endDate);
  ```


### resolvedOptions

resolvedOptions(): DateTimeOptions

Obtains the formatting options for **DateTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

- Return value
  | Type| Description|
  | -------- | -------- |
  | [DateTimeOptions](#datetimeoptions) | Formatting options for **DateTimeFormat** objects.|

- Example
  ```
  var datefmt = new Intl.DateTimeFormat("en-GB");
  datefmt.resolvedOptions();
  ```


## DateTimeOptions

Provides the options for the **DateTimeFormat** object.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | Yes| No| Locale, for example, **zh-Hans-CN**.<br>**System capability**: SystemCapability.Global.I18n|
| dateStyle | string | Yes| Yes| Date display format. The value can be **long**, **short**, **medium**, or **full**.<br>**System capability**: SystemCapability.Global.I18n|
| timeStyle | string | Yes| Yes| Time display format. The value can be **long**, **short**, **medium**, or **full**.<br>**System capability**: SystemCapability.Global.I18n|
| hourCycle | string | Yes| Yes| Time system for the locale. The value can be any of the following: h11, h12, h23, h24.<br>**System capability**: SystemCapability.Global.I18n|
| timeZone | string | Yes| Yes| Time zone represented by a valid IANA time zone ID.<br>**System capability**: SystemCapability.Global.I18n|
| numberingSystem | string | Yes| Yes| Numbering system for the locale. The value can be any of the following: adlm, ahom, arab, arabext, bali, beng, bhks, brah, cakm, cham, deva, diak, fullwide, gong, gonm, gujr, guru, hanidec, hmng, hmnp, java, kali, khmr, knda, lana, lanatham, laoo, latn, lepc, limb, mathbold, mathdbl, mathmono, mathsanb, mathsans, mlym, modi, mong, mroo, mtei, mymr, mymrshan, mymrtlng, newa, nkoo, olck, orya, osma, rohg, saur, segment, shrd, sind, sinh, sora, sund, takr, talu, tamldec, telu, thai, tibt, tirh, vaii, wara, wcho.<br>**System capability**: SystemCapability.Global.I18n|
| hour12 | boolean | Yes| Yes| Whether to use the 12-hour clock.<br>**System capability**: SystemCapability.Global.I18n|
| weekday | string | Yes| Yes| Workday display format. The value can be **long**, **short**, or **narrow**.<br>**System capability**: SystemCapability.Global.I18n|
| era | string | Yes| Yes| Era display format. The value can be **long**, **short**, or **narrow**.<br>**System capability**: SystemCapability.Global.I18n|
| year | string | Yes| Yes| Year display format. The value can be **numeric** or **2-digit**. <br>**System capability**: SystemCapability.Global.I18n|
| month | string | Yes| Yes| Month display format. The value can be any of the following: numeric, 2-digit, long, short, narrow.<br>**System capability**: SystemCapability.Global.I18n|
| day | string | Yes| Yes| Day display format. The value can be **numeric** or **2-digit**.<br>**System capability**: SystemCapability.Global.I18n|
| hour | string | Yes| Yes| Hour display format. The value can be **numeric** or **2-digit**.<br>**System capability**: SystemCapability.Global.I18n|
| minute | string | Yes| Yes| Minute display format. The value can be **numeric** or **2-digit**.<br>**System capability**: SystemCapability.Global.I18n|
| second | string | Yes| Yes| Seconds display format. The value can be **numeric** or **2-digit**.<br>**System capability**: SystemCapability.Global.I18n|
| timeZoneName | string | Yes| Yes| Localized representation of a time zone name.<br>**System capability**: SystemCapability.Global.I18n|
| dayPeriod | string | Yes| Yes| Time period display format. The value can be **long**, **short**, or **narrow**.<br>**System capability**: SystemCapability.Global.I18n|
| localeMatcher | string | Yes| Yes| Locale matching algorithm. The value can be **lookup** or **best fit**.<br>**System capability**: SystemCapability.Global.I18n|
| formatMatcher | string | Yes| Yes| Format matching algorithm. The value can be **basic** or **best fit**.<br>**System capability**: SystemCapability.Global.I18n|


## NumberFormat


### constructor

constructor(locale: string, options?: NumberOptions)

Creates a **NumberFormat** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

Parameters
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| locale | string | Yes| A string containing locale information, including the language, optional script, and region.|
| options | [NumberOptions](#numberoptions) | No| Options for creating a **NumberFormat** object.|

- Example
  ```
  var numfmt = new Intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
  ```


### constructor

constructor(locales: Array&lt;string&gt;, options?: NumberOptions)

Creates a **NumberFormat** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | locales | Array&lt;string&gt; | Yes| An array of strings containing locale information.|
  | options | [NumberOptions](#numberoptions) | No| Options for creating a **NumberFormat** object.|

- Example
  ```
  var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  ```


### format

format(number: number): string;

Formats a number.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | number | number | Yes| Number to be formatted.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | string | Formatted number.|


- Example
  ```
  var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  numfmt.format(1223);
  ```


### resolvedOptions

resolvedOptions(): NumberOptions

Obtains the options of the **NumberFormat** object.

**System capability**: SystemCapability.Global.I18n

- Return value
  | Type| Description|
  | -------- | -------- |
  | [NumberOptions](#numberoptions) | Formatting options for **NumberFormat** objects.|


- Example
  ```
  var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  numfmt.resolvedOptions();
  ```


## NumberOptions

Provides the device capability.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | Yes| No| Locale, for example, **zh-Hans-CN**.<br>**System capability**: SystemCapability.Global.I18n|
| currency | string | Yes| Yes| Currency unit, for example, **EUR**, **CNY**, or **USD**.<br>**System capability**: SystemCapability.Global.I18n|
| currencySign | string | Yes| Yes| Currency unit symbol. The value can be **symbol**, **narrowSymbol**, **code**, or **name**.<br>**System capability**: SystemCapability.Global.I18n|
| currencyDisplay | string | Yes| Yes| Currency display mode. The value can be **symbol**, **narrowSymbol**, **code**, or **name**.<br>**System capability**: SystemCapability.Global.I18n|
| unit | string | Yes| Yes| Unit name, for example, **meter**, **inch**, or **hectare**.<br>**System capability**: SystemCapability.Global.I18n|
| unitDisplay | string | Yes| Yes| Unit display format. The value can be **long**, **short**, or **medium**.<br>**System capability**: SystemCapability.Global.I18n|
| unitUsage | string | Yes| Yes| Unit usage scenario. The value can be any of the following: default, area-land-agricult, area-land-commercl, area-land-residntl, length-person, length-person-small, length-rainfall, length-road, length-road-small, length-snowfall, length-vehicle, length-visiblty, length-visiblty-small, length-person-informal, length-person-small-informal, length-road-informal, speed-road-travel, speed-wind, temperature-person, temperature-weather, volume-vehicle-fuel.<br>**System capability**: SystemCapability.Global.I18n|
| signDisplay | string | Yes| Yes| Number sign display format. The value can be **auto**, **never**, always**, or **expectZero**.<br>**System capability**: SystemCapability.Global.I18n|
| compactDisplay | string | Yes| Yes| Compact display format. The value can be **long** or **short**.<br>**System capability**: SystemCapability.Global.I18n|
| notation | string | Yes| Yes| Number formatting specification. The value can be **standard**, **scientific**, engineering**, or **compact**.<br>**System capability**: SystemCapability.Global.I18n|
| localeMatcher | string | Yes| Yes| Locale matching algorithm. The value can be **lookup** or **best fit**.<br>**System capability**: SystemCapability.Global.I18n|
| style | string | Yes| Yes| Number display format. The value can be **decimal**, **currency**, **percent**, or **unit**.<br>**System capability**: SystemCapability.Global.I18n|
| numberingSystem | string | Yes| Yes| Numbering system for the locale. The value can be any of the following: adlm, ahom, arab, arabext, bali, beng, bhks, brah, cakm, cham, deva, diak, fullwide, gong, gonm, gujr, guru, hanidec, hmng, hmnp, java, kali, khmr, knda, lana, lanatham, laoo, latn, lepc, limb, mathbold, mathdbl, mathmono, mathsanb, mathsans, mlym, modi, mong, mroo, mtei, mymr, mymrshan, mymrtlng, newa, nkoo, olck, orya, osma, rohg, saur, segment, shrd, sind, sinh, sora, sund, takr, talu, tamldec, telu, thai, tibt, tirh, vaii, wara, wcho.<br>**System capability**: SystemCapability.Global.I18n|
| useGrouping | boolean | Yes| Yes| Whether to use grouping for display.<br>**System capability**: SystemCapability.Global.I18n|
| miniumumIntegerDigits | number | Yes| Yes| Minimum number of digits allowed in the integer part of a number. The value ranges from **1** to **21**.<br>**System capability**: SystemCapability.Global.I18n|
| miniumumFractionDigits | number | Yes| Yes| Minimum number of digits in the fraction part of a number. The value ranges from **1** to **20**.<br>**System capability**: SystemCapability.Global.I18n|
| maxiumumFractionDigits | number | Yes| Yes| Maximum number of digits in the fraction part of a number. The value ranges from **1** to **21**.<br>**System capability**: SystemCapability.Global.I18n|
| miniumumSignificantDigits | number | Yes| Yes| Minimum number of the least significant digits. The value ranges from **1** to **21**.<br>**System capability**: SystemCapability.Global.I18n|
| maxiumumSignificantDigits | number | Yes| Yes| Maximum number of the least significant digits. The value ranges from **1** to **21**.<br>**System capability**: SystemCapability.Global.I18n|


## Collator<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

Creates a Collator object.

**System capability**: SystemCapability.Global.I18n

- Example
  ```
  var collator = new Intl.Collator();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: CollatorOptions)

Creates a Collator object.

**System capability**: SystemCapability.Global.I18n

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | locale | string\|Array&lt;string&gt; | Yes| A string containing locale information, including the language, optional script, and region.|
  | options | [CollatorOptions](#collatoroptions) | No| Options for creating a **Collator** object.|

- Example
  ```
  var collator = new Intl.Collator("zh-CN", {"localeMatcher": "lookup", "usage": "sort"});
  ```


### compare<sup>8+</sup>

compare(first: string, second: string): number

Compares two strings based on the sorting policy of the **Collator** object.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | first | string | Yes| First string to compare.|
  | second | string | Yes| Second string to compare.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | number | Comparison result. If the value is a negative number, the first string is before the second string. If the value of number is **0**, the first string is equal to the second string. If the value of number is a positive number, the first string is after the second string.|

- Example
  ```
  var collator = new Intl.Collator("zh-Hans");
  collator.compare("first", "second");
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): CollatorOptions

Returns properties reflecting the locale and collation options of a **Collator** object.

**System capability**: SystemCapability.Global.I18n

- Return value
  | Type| Description|
  | -------- | -------- |
  | [CollatorOptions](#collatoroptions) | Properties of the **Collator** object.|

- Example
  ```
  var collator = new Intl.Collator("zh-Hans");
  var options = collator.resolvedOptions();
  ```


## CollatorOptions<sup>8+</sup><a name=collatoroptions></a>

Represents the properties of a **Collator** object.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| localeMatcher | string | Yes| Yes| Locale matching algorithm. The value can be **lookup** or **best fit**.<br>**System capability**: SystemCapability.Global.I18n|
| usage | string | Yes| Yes| Whether the comparison is for sorting or for searching. The value can be **sort** or **search**.<br>**System capability**: SystemCapability.Global.I18n|
| sensitivity | string | Yes| Yes| Differences in the strings that lead to non-zero return values. The value can be **base**, **accent**, **case**, or **variant**.<br>**System capability**: SystemCapability.Global.I18n|
| ignorePunctuation | boolean | Yes| Yes| Whether punctuation is ignored. The value can be **true** or **false**.<br>**System capability**: SystemCapability.Global.I18n|
| collation | string | Yes| Yes| Rule for sorting regions. The value can be any of the following: big5han, compat, dict, direct, ducet, eor, gb2312, phonebk, phonetic, pinyin, reformed, searchjl, stroke, trad, unihan, zhuyin.<br>**System capability**: SystemCapability.Global.I18n|
| numeric | boolean | Yes| Yes| Whether numeric collation is used. The value can be **true** or **false**.<br>**System capability**: SystemCapability.Global.I18n|
| caseFirst | string | Yes| Yes| Whether upper case or lower case is sorted first. The value can be **upper**, **lower**, or **false**.<br>**System capability**: SystemCapability.Global.I18n|


## PluralRules<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

Create a **PluralRules** object.

**System capability**: SystemCapability.Global.I18n

- Example
  ```
  var pluralRules = new Intl.PluralRules();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: PluralRulesOptions)

Create a **PluralRules** object.

**System capability**: SystemCapability.Global.I18n

Parameters
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| locale | string\|Array&lt;string&gt; | Yes| A string containing locale information, including the language, optional script, and region.|
| options | [PluralRulesOptions](#pluralrulesoptions) | No| Options for creating a **PluralRules** object.|

- Example
  ```
  var pluralRules= new Intl.PluraRules("zh-CN", {"localeMatcher": "lookup", "type": "cardinal"});
  ```


### select<sup>8+</sup>

select(n: number): string

Obtains a string that represents the singular-plural type of the specified number.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | n | number | Yes| Number for which the singular-plural type is to be obtained.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | string | Singular-plural type. The value can be any of the following: one, two, few, many, others.|

- Example
  ```
  var pluralRules = new Intl.PluralRules("zh-Hans");
  pluralRules.select(1);
  ```


## PluralRulesOptions<sup>8+</sup><a name=pluralrulesoptions></a>

Represents the properties of a **PluralRules** object.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| localeMatcher | string | Yes| Yes| Locale matching algorithm. The value can be **lookup** or **best fit**.<br>**System capability**: SystemCapability.Global.I18n|
| type | string | Yes| Yes| Sorting type. The value can be **cardinal** or **ordinal**.<br>**System capability**: SystemCapability.Global.I18n|
| minimumIntegerDigits | number | Yes| Yes| Minimum number of digits allowed in the integer part of a number. The value ranges from **1** to **21**.<br>**System capability**: SystemCapability.Global.I18n|
| minimumFractionDigits | number | Yes| Yes| Minimum number of digits in the fraction part of a number. The value ranges from **0** to **20**.<br>**System capability**: SystemCapability.Global.I18n|
| maximumFractionDigits | number | Yes| Yes| Maximum number of digits in the fraction part of a number. The value ranges from **1** to **21**.<br>**System capability**: SystemCapability.Global.I18n|
| minimumSignificantDigits | number | Yes| Yes| Minimum number of the least significant digits. The value ranges from **1** to **21**.<br>**System capability**: SystemCapability.Global.I18n|
| maximumSignificantDigits | number | Yes| Yes| Maximum number of the least significant digits. The value ranges from **1** to **21**.<br>**System capability**: SystemCapability.Global.I18n|


## RelativeTimeFormat<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

Creates a **RelativeTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

- Example
  ```
  var relativetimefmt = new Intl.RelativeTimeFormat();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: RelativeTimeFormatInputOptions)

Creates a **RelativeTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

Parameters
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| locale | string\|Array&lt;string&gt; | Yes| A string containing locale information, including the language, optional script, and region.|
| options | [RelativeTimeFormatInputOptions](#relativetimeformatinputoptions) | No| Options for creating a **RelativeTimeFormat** object.|

- Example
  ```
  var relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {"localeMatcher": "lookup", "numeric": "always", "style": "long"});
  ```


### format<sup>8+</sup>

format(value: numeric, unit: string): string

Formats the value and unit based on the specified locale and formatting options.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | value | numeric | Yes| Value to format.|
  | unit | string | Yes| Unit to format. The value can be any of the following: year, quarter, month, week, day, hour, minute, second.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | string | Relative time after formatting.|

- Example
  ```
  var relativetimefmt = new Intl.RelativeTimeFormat("zh-CN");
  relativetimefmt.format(3, "quarter")
  ```


### formatToParts<sup>8+</sup>

formatToParts(value: numeric, unit: string): Array&lt;Object&gt;

Returns an array of RelativeTimeFormat objects in parts for locale-aware formatting.

**System capability**: SystemCapability.Global.I18n

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | value | numeric | Yes| Value to format.|
  | unit | string | Yes| Unit to format. The value can be any of the following: year, quarter, month, week, day, hour, minute, second.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Array&lt;Object&gt; | An array of **RelativeTimeFormat** objects in parts.|

- Example
  ```
  var relativetimefmt = new Intl.RelativeTimeFormat("en", {"numeric": "auto"});
  var parts = relativetimefmt.format(10, "seconds");
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): RelativeTimeFormatResolvedOptions

Obtains the formatting options for **RelativeTimeFormat** objects.

**System capability**: SystemCapability.Global.I18n

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RelativeTimeFormatResolvedOptions](#relativetimeformatresolvedoptions) | Formatting options for **RelativeTimeFormat** objects.|

- Example
  ```
  var relativetimefmt= new Intl.RelativeTimeFormat("en-GB");
  relativetimefmt.resolvedOptions();
  ```


## RelativeTimeFormatInputOptions<sup>8+</sup><a name=relativetimeformatinputoptions></a>

Represents the properties of a **RelativeTimeFormat** object.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| localeMatcher | string | Yes| Yes| Locale matching algorithm. The value can be **lookup** or **best fit**.<br>**System capability**: SystemCapability.Global.I18n|
| numeric | string | Yes| Yes| Format of the output message. The value can be **always** or **auto**.<br>**System capability**: SystemCapability.Global.I18n|
| style | string | Yes| Yes| Length of an internationalized message. The value can be **long**, **short**, or **narrow**.<br>**System capability**: SystemCapability.Global.I18n|


## RelativeTimeFormatResolvedOptions<sup>8+</sup><a name=relativetimeformatresolvedoptions></a>

Represents the properties of a **RelativeTimeFormat** object.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | Yes| Yes| A string containing locale information, including the language, optional script, and region.<br>**System capability**: SystemCapability.Global.I18n|
| numeric | string | Yes| Yes| Format of the output message. The value can be **always** or **auto**.<br>**System capability**: SystemCapability.Global.I18n|
| style | string | Yes| Yes| Length of an internationalized message. The value can be **long**, **short**, or **narrow**.<br>**System capability**: SystemCapability.Global.I18n|
| numberingSystem | string | Yes| Yes| Numbering system.<br>**System capability**: SystemCapability.Global.I18n|
