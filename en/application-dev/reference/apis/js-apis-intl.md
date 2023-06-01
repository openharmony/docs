# @ohos.intl (Internationalization)

 The **intl** module provides basic i18n capabilities, such as time and date formatting, number formatting, and string sorting, through the standard i18n APIs defined in ECMA 402.
The [i18n](js-apis-i18n.md) module provides enhanced i18n capabilities through supplementary interfaces that are not defined in ECMA 402. It works with the intl module to provide a complete suite of i18n capabilities.

>  **NOTE**
>  - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - This module provides basic i18n capabilities, such as time and date formatting, number formatting, and string sorting, through the standard i18n interfaces defined in ECMA 402. For details about the enhanced i18n capabilities, see [i18n](js-apis-i18n.md).


## Modules to Import

```js
import Intl from '@ohos.intl';
```
Importing an incorrect bundle can lead to unexpected API behavior.

## Locale


### Attributes

**System capability**: SystemCapability.Global.I18n

| Name             | Type     | Readable  | Writable  | Description                                      |
| --------------- | ------- | ---- | ---- | ---------------------------------------- |
| language        | string  | Yes   | No   | Language associated with the locale, for example, **zh**.                   |
| script          | string  | Yes   | No   | Script type of the language, for example, **Hans**.                         |
| region          | string  | Yes   | No   | Region associated with the locale, for example, **CN**.                        |
| baseName        | string  | Yes   | No   | Basic key information about the locale, which consists of the language, script, and region, for example, **zh-Hans-CN**. |
| caseFirst       | string  | Yes   | No   | Whether case is taken into account for the locale's collation rules. The value can be **upper**, **lower**, or **false**.|
| calendar        | string  | Yes   | No   | Calendar for the locale. The value can be any of the following: **buddhist**, **chinese**, **coptic**, **dangi**, **ethioaa**, **ethiopic**, **gregory**, **hebrew**, **indian**, **islamic**, **islamic-umalqura**, **islamic-tbla**, **islamic-civil**, **islamic-rgsa**, **iso8601**, **japanese**, **persian**, **roc**, or **islamicc**.|
| collation       | string  | Yes   | No   | Rule for sorting regions. The value can be any of the following: **big5han**, **compat**, **dict**, **direct**, **ducet**, **eor**, **gb2312**, **phonebk**, **phonetic**, **pinyin**, **reformed**, **searchjl**, **stroke**, **trad**, **unihan**, **zhuyin**.|
| hourCycle       | string  | Yes   | No   | Time system for the locale. The value can be any of the following: **h12**, **h23**, **h11**, or **h24**.|
| numberingSystem | string  | Yes   | No   | Numbering system for the locale. The value can be any of the following: **adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, **wcho**.|
| numeric         | boolean | Yes   | No   | Whether to apply special collation rules for numeric characters.                     |


### constructor<sup>8+</sup>

constructor()

Creates a **Locale** object.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```js
  // The default constructor uses the current system locale to create a Locale object.
  let locale = new Intl.Locale();
  // Return the current system locale.
  let localeID = locale.toString();
  ```


### constructor

constructor(locale: string, options?: LocaleOptions)

Creates a **Locale** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                              | Mandatory  | Description                          |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string                           | Yes   | A string containing locale information, including the language, optional script, and region. For details about the international standards and combination modes for the language, script, and country or region, see [intl Development](../../internationalization/intl-guidelines.md#setting-locale-information).|
| options             | [LocaleOptions](#localeoptions6) | No   | Options for creating the **Locale** object.                |

**Example**
  ```js
  // Create a Locale object named zh-CN.
  let locale = new Intl.Locale("zh-CN");
  let localeID = locale.toString(); // localeID = "zh-CN"
  ```


### toString

toString(): string

Obtains the string representation of a **Locale** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | String representation of the **Locale** object.|

**Example**
  ```js
  // Create a Locale object named en-GB.
  let locale = new Intl.Locale("en-GB");
  let localeID = locale.toString(); // localeID = "en-GB"
  ```


### maximize

maximize(): Locale

Maximizes information of the **Locale** object. If the script and locale information is missing, add the information.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type               | Description        |
| ----------------- | ---------- |
| [Locale](#locale) | **Locale** object with the maximized information.|

**Example**
  ```js
  // Create a Locale object named zh.
  let locale = new Intl.Locale("zh");
  // Complete the script and region of the Locale object.
  let maximizedLocale = locale.maximize();
  let localeID = maximizedLocale.toString(); // localeID = "zh-Hans-CN"

  // Create a Locale object named en-US.
  locale = new Intl.Locale("en-US");
  // Complete the script of the Locale object.
  maximizedLocale = locale.maximize();
  localeID = maximizedLocale.toString(); // localeID = "en-Latn-US"
  ```


### minimize

minimize(): Locale

Minimizes information of the **Locale** object. If the script and locale information is present, delete the information.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type               | Description        |
| ----------------- | ---------- |
| [Locale](#locale) | **Locale** object with the minimized information.|

**Example**
  ```js
  // Create a Locale object named zh-Hans-CN.
  let locale = new Intl.Locale("zh-Hans-CN");
  // Remove the script and region of the Locale object.
  let minimizedLocale = locale.minimize();
  let localeID = minimizedLocale.toString(); // localeID = "zh"

  // Create a Locale object named en-US.
  locale = new Intl.Locale("en-US");
  // Remove the region of the Locale object.
  minimizedLocale = locale.minimize();
  localeID = minimizedLocale.toString(); // localeID = "en"
  ```


## LocaleOptions<sup>6+</sup>

Represents the locale options.
In API version 9, the attributes in **LocaleOptions** are optional.

**System capability**: SystemCapability.Global.I18n

| Name             | Type     | Readable  | Writable  | Description                                      |
| --------------- | ------- | ---- | ---- | ---------------------------------------- |
| calendar        | string  | Yes   | Yes   | Calendar for the locale. The value can be any of the following: **buddhist**, **chinese**, **coptic**, **dangi**, **ethioaa**, **ethiopic**, **gregory**, **hebrew**, **indian**, **islamic**, **islamic-umalqura**, **islamic-tbla**, **islamic-civil**, **islamic-rgsa**, **iso8601**, **japanese**, **persian**, **roc**, or **islamicc**.|
| collation       | string  | Yes   | Yes   | Collation rule. The value can be any of the following: **big5han**, **compat**, **dict**, **direct**, **ducet**, **emoji**, **eor**, **gb2312**, **phonebk**, **phonetic**, **pinyin**, **reformed**, **search**, **searchjl**, **standard**, **stroke**, **trad**, **unihan**, **zhuyin**.|
| hourCycle       | string  | Yes   | Yes   | Time system for the locale. The value can be any of the following: **h11**, **h12**, **h23**, or **h24**.|
| numberingSystem | string  | Yes   | Yes   | Numbering system for the locale. The value can be any of the following: **adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, **wcho**.|
| numeric         | boolean | Yes   | Yes   | Whether to use the 12-hour clock.                              |
| caseFirst       | string  | Yes   | Yes   | Whether upper case or lower case is sorted first. The value can be **upper**, **lower**, or **false**.|


## DateTimeFormat


### constructor<sup>8+</sup>

constructor()

Creates a **DateTimeOptions** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```js
  // Use the current system locale to create a DateTimeFormat object.
  let datefmt= new Intl.DateTimeFormat();
  ```


### constructor

constructor(locale: string | Array&lt;string&gt;, options?: DateTimeOptions)

Creates a **DateTimeOptions** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                  | Mandatory  | Description                          |
| -------------------- | ------------------------------------ | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;        | Yes   | A string containing locale information, including the language, optional script, and region.|
| options              | [DateTimeOptions](#datetimeoptions6) | No   | Options for creating a **DateTimeFormat** object.             |

**Example**
  ```js
  // Use locale zh-CN to create a DateTimeFormat object. Set dateStyle to full and timeStyle to medium.
  let datefmt= new Intl.DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });
  ```


**Example**
  ```js
  // Use the locale list ["ban", "zh"] to create a DateTimeFormat object. Because ban is an invalid locale ID, locale zh is used to create the DateTimeFormat object.
  let datefmt= new Intl.DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
  ```


### format

format(date: Date): string

Formats the specified date and time.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description     |
| ---- | ---- | ---- | ------- |
| date | Date | Yes   | Date and time to be formatted.|

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | A string containing the formatted date and time.|

**Example**
  ```js
  let date = new Date(2021, 11, 17, 3, 24, 0);
  // Use locale en-GB to create a DateTimeFormat object.
  let datefmt = new Intl.DateTimeFormat("en-GB");
  let formattedDate = datefmt.format(date); // formattedDate "17/12/2021"

  // Use locale en-GB to create a DateTimeFormat object. Set dateStyle to full and timeStyle to medium.
  datefmt = new Intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });
  formattedDate = datefmt.format(date); // formattedDate "Friday, 17 December 2021 at 03:24:00"
  ```


### formatRange

formatRange(startDate: Date, endDate: Date): string

Formats the specified date range.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name      | Type  | Mandatory  | Description      |
| --------- | ---- | ---- | -------- |
| startDate | Date | Yes   | Start date and time to be formatted.|
| endDate   | Date | Yes   | End date and time to be formatted.|

**Return value**

| Type    | Description            |
| ------ | -------------- |
| string | A string containing the formatted date and time range.|

**Example**
  ```js
  let startDate = new Date(2021, 11, 17, 3, 24, 0);
  let endDate = new Date(2021, 11, 18, 3, 24, 0);
  // Use locale en-GB to create a DateTimeFormat object.
  let datefmt = new Intl.DateTimeFormat("en-GB");
  let formattedDateRange = datefmt.formatRange(startDate, endDate); // formattedDateRange = "17/12/2021-18/12/2021"
  ```


### resolvedOptions

resolvedOptions(): DateTimeOptions

Obtains the formatting options for **DateTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                                  | Description                           |
| ------------------------------------ | ----------------------------- |
| [DateTimeOptions](#datetimeoptions6) | Formatting options for **DateTimeFormat** objects.|

**Example**
  ```js
  let datefmt = new Intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });
  // Obtain the options of the DateTimeFormat object.
  let options = datefmt.resolvedOptions();
  let dateStyle = options.dateStyle; // dateStyle = "full"
  let timeStyle = options.timeStyle; // timeStyle = "medium"
  ```


## DateTimeOptions<sup>6+</sup>

Provides the options for the **DateTimeFormat** object.
In API version 9, the attributes in **DateTimeOptions** are optional.

**System capability**: SystemCapability.Global.I18n

| Name             | Type     | Readable  | Writable  | Description                                      |
| --------------- | ------- | ---- | ---- | ---------------------------------------- |
| locale          | string  | Yes   | No   | Locale, for example, **zh-Hans-CN**.                |
| dateStyle       | string  | Yes   | Yes   | Date display format. The value can be **long**, **short**, **medium**, or **full**.|
| timeStyle       | string  | Yes   | Yes   | Time display format. The value can be **long**, **short**, **medium**, or **full**.|
| hourCycle       | string  | Yes   | Yes   | Time system for the locale. The value can be any of the following: **h11**, **h12**, **h23**, or **h24**.|
| timeZone        | string  | Yes   | Yes   | Time zone represented by a valid IANA time zone ID.                     |
| numberingSystem | string  | Yes   | Yes   | Numbering system for the locale. The value can be any of the following: **adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, **wcho**.|
| hour12          | boolean | Yes   | Yes   | Whether to use the 12-hour clock.                              |
| weekday         | string  | Yes   | Yes   | Workday display format. The value can be **long**, **short**, or **narrow**.|
| era             | string  | Yes   | Yes   | Era display format. The value can be **long**, **short**, or **narrow**.|
| year            | string  | Yes   | Yes   | Year display format. The value can be **numeric** or **2-digit**.  |
| month           | string  | Yes   | Yes   | Month display format. The value can be any of the following: **numeric**, **2-digit**, **long**, **short**, **narrow**.|
| day             | string  | Yes   | Yes   | Day display format. The value can be **numeric** or **2-digit**. |
| hour            | string  | Yes   | Yes   | Hour display format. The value can be **numeric** or **2-digit**. |
| minute          | string  | Yes   | Yes   | Minute display format. The value can be **numeric** or **2-digit**. |
| second          | string  | Yes   | Yes   | Seconds display format. The value can be **numeric** or **2-digit**. |
| timeZoneName    | string  | Yes   | Yes   | Localized representation of a time zone name.                             |
| dayPeriod       | string  | Yes   | Yes   | Time period display format. The value can be **long**, **short**, or **narrow**.|
| localeMatcher   | string  | Yes   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.|
| formatMatcher   | string  | Yes   | Yes   | Format matching algorithm. The value can be **basic** or **best fit**.|


## NumberFormat


### constructor<sup>8+</sup>

constructor()

Creates a **NumberFormat** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```js
  // Use the current system locale to create a NumberFormat object.
  let numfmt = new Intl.NumberFormat();
  ```


### constructor

constructor(locale: string | Array&lt;string&gt;, options?: NumberOptions)

Creates a **NumberFormat** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                              | Mandatory  | Description                          |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;    | Yes   | A string containing locale information, including the language, optional script, and region.|
| options              | [NumberOptions](#numberoptions6) | No   | Options for creating a **NumberFormat** object.               |

**Example**
  ```js
  // Use locale en-GB to create a NumberFormat object. Set style to decimal and notation to scientific.
  let numfmt = new Intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
  ```


### format

format(number: number): string;

Formats a number.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description  |
| ------ | ------ | ---- | ---- |
| number | number | Yes   | Number to be formatted.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Formatted number.|


**Example**
  ```js
  // Use locale list ["en-GB", "zh"] to create a NumberFormat object. Because en-GB is a valid locale ID, it is used to create the NumberFormat object.
  let numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  let formattedNumber = numfmt.format(1223); // formattedNumber = 1.223E3
  ```


### resolvedOptions

resolvedOptions(): NumberOptions

Obtains the options of the **NumberFormat** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                              | Description                         |
| -------------------------------- | --------------------------- |
| [NumberOptions](#numberoptions6) | Formatting options for **NumberFormat** objects.|


**Example**
  ```js
  let numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  // Obtain the options of the NumberFormat object.
  let options = numfmt.resolvedOptions();
  let style = options.style; // style = decimal
  let notation = options.notation; // notation = scientific
  ```


## NumberOptions<sup>6+</sup>

Defines the device capability.
In API version 9, the attributes in **NumberOptions** are optional.

**System capability**: SystemCapability.Global.I18n

| Name                      | Type     | Readable  | Writable  | Description                                      |
| ------------------------ | ------- | ---- | ---- | ---------------------------------------- |
| locale                   | string  | Yes   | No   | Locale, for example, **zh-Hans-CN**.              |
| currency                 | string  | Yes   | Yes   | Currency unit, for example, **EUR**, **CNY**, or **USD**.        |
| currencySign             | string  | Yes   | Yes   | Currency unit symbol. The value can be **symbol**, **narrowSymbol**, **code**, or **name**.|
| currencyDisplay          | string  | Yes   | Yes   | Currency display mode. The value can be **symbol**, **narrowSymbol**, **code**, or **name**.|
| unit                     | string  | Yes   | Yes   | Unit name, for example, **meter**, **inch**, or **hectare**.       |
| unitDisplay              | string  | Yes   | Yes   | Unit display format. The value can be **long**, **short**, or **narrow**.|
| unitUsage<sup>8+</sup>   | string  | Yes   | Yes   | Unit usage scenario. The value can be any of the following: **default**, **area-land-agricult**, **area-land-commercl**, **area-land-residntl**, **length-person**, **length-person-small**, **length-rainfall**, **length-road**, **length-road-small**, **length-snowfall**, **length-vehicle**, **length-visiblty**, **length-visiblty-small**, **length-person-informal**, **length-person-small-informal**, **length-road-informal**, **speed-road-travel**, **speed-wind**, **temperature-person**, **temperature-weather**, **volume-vehicle-fuel**.|
| signDisplay              | string  | Yes   | Yes   | Number sign display format. The value can be **auto**, **never**, **always**, or **expectZero**.|
| compactDisplay           | string  | Yes   | Yes   | Compact display format. The value can be **long** or **short**.     |
| notation                 | string  | Yes   | Yes   | Number formatting specification. The value can be **standard**, **scientific**, **engineering**, or **compact**.|
| localeMatcher            | string  | Yes   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.|
| style                    | string  | Yes   | Yes   | Number display format. The value can be **decimal**, **currency**, **percent**, or **unit**.|
| numberingSystem          | string  | Yes   | Yes   | Numbering system for the locale. The value can be any of the following: **adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, **wcho**.|
| useGrouping              | boolean | Yes   | Yes   | Whether to use grouping for display.                                 |
| minimumIntegerDigits     | number  | Yes   | Yes   | Minimum number of digits allowed in the integer part of a number. The value ranges from **1** to **21**.                 |
| minimumFractionDigits    | number  | Yes   | Yes   | Minimum number of digits in the fraction part of a number. The value ranges from **0** to **20**.                 |
| maximumFractionDigits    | number  | Yes   | Yes   | Maximum number of digits in the fraction part of a number. The value ranges from **1** to **21**.                 |
| minimumSignificantDigits | number  | Yes   | Yes   | Minimum number of the least significant digits. The value ranges from **1** to **21**.                 |
| maximumSignificantDigits | number  | Yes   | Yes   | Maximum number of the least significant digits. The value ranges from **1** to **21**.                 |


## Collator<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

Creates a **Collator** object.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```js
  // Use the system locale to create a Collator object.
  let collator = new Intl.Collator();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: CollatorOptions)

Creates a **Collator** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                  | Mandatory  | Description                          |
| -------------------- | ------------------------------------ | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;        | Yes   | A string containing locale information, including the language, optional script, and region.|
| options              | [CollatorOptions](#collatoroptions8) | No   | Options for creating a **Collator** object.                |

**Example**
  ```js
  // Use locale zh-CN to create a Collator object. Set localeMatcher to lookup and usage to sort.
  let collator = new Intl.Collator("zh-CN", {localeMatcher: "lookup", usage: "sort"});
  ```


### compare<sup>8+</sup>

compare(first: string, second: string): number

Compares two strings based on the sorting policy of the **Collator** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description          |
| ------ | ------ | ---- | ------------ |
| first  | string | Yes   | First string to compare. |
| second | string | Yes   | Second string to compare.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Comparison result. If the value is a negative number, the first string is before the second string. If the value of number is **0**, the first string is equal to the second string. If the value of number is a positive number, the first string is after the second string.|

**Example**
  ```js
  // Use locale en-GB to create a Collator object.
  let collator = new Intl.Collator("en-GB");
  // Compare the sequence of the first and second strings.
  let compareResult = collator.compare("first", "second"); // compareResult = -1
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): CollatorOptions

Returns properties reflecting the locale and collation options of a **Collator** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                                  | Description               |
| ------------------------------------ | ----------------- |
| [CollatorOptions](#collatoroptions8) | Properties of the **Collator** object.|

**Example**
  ```js
  let collator = new Intl.Collator("zh-Hans", { usage: 'sort', ignorePunctuation: true });
  // Obtain the options of the Collator object.
  let options = collator.resolvedOptions();
  let usage = options.usage; // usage = "sort"
  let ignorePunctuation = options.ignorePunctuation; // ignorePunctuation = true
  ```


## CollatorOptions<sup>8+</sup>

Represents the properties of a **Collator** object.
In API version 9, the attributes in **CollatorOptions** are optional.

**System capability**: SystemCapability.Global.I18n

| Name               | Type     | Readable  | Writable  | Description                                      |
| ----------------- | ------- | ---- | ---- | ---------------------------------------- |
| localeMatcher     | string  | Yes   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.|
| usage             | string  | Yes   | Yes   | Whether the comparison is for sorting or for searching. The value can be **sort** or **search**.       |
| sensitivity       | string  | Yes   | Yes   | Differences in the strings that lead to non-zero return values. The value can be **base**, **accent**, **case**, or **letiant**.|
| ignorePunctuation | boolean | Yes   | Yes   | Whether punctuation is ignored. The value can be **true** or **false**.       |
| collation         | string  | Yes   | Yes   | Rule for sorting regions. The value can be any of the following: **big5han**, **compat**, **dict**, **direct**, **ducet**, **eor**, **gb2312**, **phonebk**, **phonetic**, **pinyin**, **reformed**, **searchjl**, **stroke**, **trad**, **unihan**, **zhuyin**.|
| numeric           | boolean | Yes   | Yes   | Whether numeric collation is used. The value can be **true** or **false**.         |
| caseFirst         | string  | Yes   | Yes   | Whether upper case or lower case is sorted first. The value can be **upper**, **lower**, or **false**.|


## PluralRules<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

Creates a **PluralRules** object to obtain the singular-plural type of numbers.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```js
  // Use the system locale to create a PluralRules object.
  let pluralRules = new Intl.PluralRules();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: PluralRulesOptions)

Creates a **PluralRules** object to obtain the singular-plural type of numbers.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                          |
| -------------------- | ---------------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;            | Yes   | A string containing locale information, including the language, optional script, and region.|
| options              | [PluralRulesOptions](#pluralrulesoptions8) | No   | Options for creating a **PluralRules** object.               |

**Example**
  ```js
  // Use locale zh-CN to create a PluralRules object. Set localeMatcher to lookup and type to cardinal.
  let pluralRules= new Intl.PluralRules("zh-CN", {"localeMatcher": "lookup", "type": "cardinal"});
  ```


### select<sup>8+</sup>

select(n: number): string

Obtains a string that represents the singular-plural type of the specified number.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| n    | number | Yes   | Number for which the singular-plural type is to be obtained.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| string | Singular-plural type. The value can be any of the following: **zero**, **one**, **two**, **few**, **many**, **others**.|

**Example**
  ```js
  // Use locale zh-Hans to create a PluralRules object.
  let zhPluralRules = new Intl.PluralRules("zh-Hans");
  // Determine the singular-plural type corresponding to number 1 in locale zh-Hans.
  let plural = zhPluralRules.select(1); // plural = other

  // Use locale en-US to create a PluralRules object.
  let enPluralRules = new Intl.PluralRules("en-US");
  // Determine the singular-plural type corresponding to number 1 in locale en-US.
  plural = enPluralRules.select(1); // plural = one
  ```


## PluralRulesOptions<sup>8+</sup>

Represents the properties of a **PluralRules** object.
In API version 9, the attributes in **PluralRulesOptions** are optional.

**System capability**: SystemCapability.Global.I18n

| Name                      | Type    | Readable  | Writable  | Description                                      |
| ------------------------ | ------ | ---- | ---- | ---------------------------------------- |
| localeMatcher            | string | Yes   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.|
| type                     | string | Yes   | Yes   | Sorting type. The value can be **cardinal** or **ordinal**.  |
| minimumIntegerDigits     | number | Yes   | Yes   | Minimum number of digits allowed in the integer part of a number. The value ranges from **1** to **21**.                 |
| minimumFractionDigits    | number | Yes   | Yes   | Minimum number of digits in the fraction part of a number. The value ranges from **0** to **20**.                 |
| maximumFractionDigits    | number | Yes   | Yes   | Maximum number of digits in the fraction part of a number. The value ranges from **1** to **21**.                 |
| minimumSignificantDigits | number | Yes   | Yes   | Minimum number of the least significant digits. The value ranges from **1** to **21**.                 |
| maximumSignificantDigits | number | Yes   | Yes   | Maximum number of the least significant digits. The value ranges from **1** to **21**.                 |


## RelativeTimeFormat<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

Creates a **RelativeTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```js
  // Use the system locale to create a RelativeTimeFormat object.
  let relativetimefmt = new Intl.RelativeTimeFormat();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: RelativeTimeFormatInputOptions)

Creates a **RelativeTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                          |
| -------------------- | ---------------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;            | Yes   | A string containing locale information, including the language, optional script, and region.|
| options              | [RelativeTimeFormatInputOptions](#relativetimeformatinputoptions8) | No   | Options for creating a **RelativeTimeFormat** object.           |

**Example**
  ```js
  // Use locale zh-CN to create a RelativeTimeFormat object. Set localeMatcher to lookup, numeric to always, and style to long.
  let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {"localeMatcher": "lookup", "numeric": "always", "style": "long"});
  ```


### format<sup>8+</sup>

format(value: number, unit: string): string

Formats the value and unit based on the specified locale and formatting options.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | Yes   | Value to format.                             |
| unit  | string | Yes   | Unit to format. The value can be any of the following: **year**, **quarter**, **month**, **week**, **day**, **hour**, **minute**, **second**.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Relative time after formatting.|

**Example**
  ```js
  // Use locale zh-CN to create a RelativeTimeFormat object.
  let relativetimefmt = new Intl.RelativeTimeFormat("zh-CN");
  // Obtain the localized representation (in unit of quarter) of number 3 in locale zh-CN.
  let formatResult = relativetimefmt.format(3, "quarter"); // formatResult = "3 quarters later"
  ```


### formatToParts<sup>8+</sup>

formatToParts(value: number, unit: string): Array&lt;object&gt;

Obtains an array of RelativeTimeFormat objects in parts for locale-aware formatting.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | Yes   | Value to format.                             |
| unit  | string | Yes   | Unit to format. The value can be any of the following: **year**, **quarter**, **month**, **week**, **day**, **hour**, **minute**, **second**.|

**Return value**

| Type                 | Description                         |
| ------------------- | --------------------------- |
| Array&lt;object&gt; | An array of **RelativeTimeFormat** objects in parts.|

**Example**
  ```js
  // Use locale en to create a RelativeTimeFormat object. Set numeric to auto.
  let relativetimefmt = new Intl.RelativeTimeFormat("en", {"numeric": "auto"});
  let parts = relativetimefmt.formatToParts(10, "seconds"); // parts = [ {type: "literal", value: "in"}, {type: "integer", value: 10, unit: "second"}, {type: "literal", value: "seconds"} ]
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): RelativeTimeFormatResolvedOptions

Obtains the formatting options for **RelativeTimeFormat** objects.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                                      | Description                               |
| ---------------------------------------- | --------------------------------- |
| [RelativeTimeFormatResolvedOptions](#relativetimeformatresolvedoptions8) | Formatting options for **RelativeTimeFormat** objects.|

**Example**
  ```js
  // Use locale en-GB to create a RelativeTimeFormat object.
  let relativetimefmt= new Intl.RelativeTimeFormat("en-GB", { style: "short" });
  // Obtain the options of the RelativeTimeFormat object.
  let options = relativetimefmt.resolvedOptions();
  let style = options.style; // style = "short"
  ```


## RelativeTimeFormatInputOptions<sup>8+</sup>

Represents the properties of a **RelativeTimeFormat** object.
In API version 9, the attributes in **RelativeTimeFormatInputOptions** are optional.

**System capability**: SystemCapability.Global.I18n

| Name           | Type    | Readable  | Writable  | Description                                      |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| localeMatcher | string | Yes   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.|
| numeric       | string | Yes   | Yes   | Format of the output message. The value can be **always** or **auto**.     |
| style         | string | Yes   | Yes   | Length of an internationalized message. The value can be **long**, **short**, or **narrow**.|


## RelativeTimeFormatResolvedOptions<sup>8+</sup>

Represents the properties of a **RelativeTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

| Name             | Type    | Readable  | Writable  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| locale          | string | Yes   | Yes   | A string containing locale information, including the language, optional script, and region.            |
| numeric         | string | Yes   | Yes   | Format of the output message. The value can be **always** or **auto**.     |
| style           | string | Yes   | Yes   | Length of an internationalized message. The value can be **long**, **short**, or **narrow**.|
| numberingSystem | string | Yes   | Yes   | Numbering system.                                |
