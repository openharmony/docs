# Internationalization – Intl

The Intl module provides basic I18N capabilities, such as time and date formatting, number formatting, and string sorting, through the standard I18N APIs defined in ECMA 402.

The [I18N](js-apis-i18n.md) module provides enhanced I18N capabilities through supplementary APIs that are not defined in ECMA 402. It works with the Intl module to provide a complete suite of I18N capabilities.

>  **NOTE**
>  
>  The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import Intl from '@ohos.intl';
```


## Locale


### Attributes

**System capability**: SystemCapability.Global.I18n

| Name             | Type   | Readable  | Writable  | Description                                      |
| --------------- | ------- | ---- | ---- | ---------------------------------------- |
| language        | string  | Yes   | No   | Language associated with the locale, for example, **zh**.                   |
| script          | string  | Yes   | No   | Script type of the language, for example, **Hans**.                         |
| region          | string  | Yes   | No   | Region associated with the locale, for example, **CN**.                        |
| baseName        | string  | Yes   | No   | Basic key information about the locale, which consists of the language, script, and region, for example, **zh-Hans-CN**. |
| caseFirst       | string  | Yes   | No   | Whether case is taken into account for the locale's collation rules. The value can be **upper**, **lower**, or **false**.|
| calendar        | string  | Yes   | No   | Calendar for the locale. The value can be any of the following: **buddhist**, **chinese**, **coptic**, **dangi**, **ethioaa**, **ethiopic**, **gregory**, **hebrew**, **indian**, **islamic**, **islamic-umalqura**, **islamic-tbla**, **islamic-civil**, **islamic-rgsa**, **iso8601**, **japanese**, **persian**, **roc**, **islamicc**.|
| collation       | string  | Yes   | No   | Rule for sorting regions. The value can be any of the following: **big5han**, **compat**, **dict**, **direct**, **ducet**, **eor**, **gb2312**, **phonebk**, **phonetic**, **pinyin**, **reformed**, **searchjl**, **stroke**, **trad**, **unihan**, **zhuyin**.|
| hourCycle       | string  | Yes   | No   | Time system for the locale. The value can be any of the following: **h12**, **h23**, **h11**, **h24**.|
| numberingSystem | string  | Yes   | No   | Numbering system for the locale. The value can be any of the following: **adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, **wcho**.|
| numeric         | boolean | Yes   | No   | Whether to apply special collation rules for numeric characters.                     |


### constructor<sup>8+</sup>

constructor()

Creates a Locale object.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```
  var locale = new Intl.Locale();
  ```


### constructor

constructor(locale: string, options?: LocaleOptions)

Creates a Locale object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type           | Mandatory  | Description                          |
| ------- | ------------- | ---- | ---------------------------- |
| locale  | string        | Yes   | A string containing locale information, including the language, optional script, and region.|
| options<sup>9+</sup> | [LocaleOptions](#localeoptions9) | No   | Options for creating the **Locale** object.                |

**Example**
  ```
  var locale = new Intl.Locale("zh-CN");
  ```


### toString

toString(): string

Converts locale information to a string.

**System capability**: SystemCapability.Global.I18n

**Return Value**

| Type    | Description         |
| ------ | ----------- |
| string | String containing locale information.|

**Example**
  ```
  var locale = new Intl.Locale("zh-CN");
  locale.toString();
  ```


### maximize

maximize(): Locale

Maximizes information of the **Locale** object. If the script and locale information is missing, add the information.

**System capability**: SystemCapability.Global.I18n

**Return Value**

| Type               | Description        |
| ----------------- | ---------- |
| [Locale](#locale) | **Locale** object with the maximized information.|

**Example**
  ```
  var locale = new Intl.Locale("zh-CN");
  locale.maximize();
  ```


### minimize

minimize(): Locale

Minimizes information of the **Locale** object. If the script and locale information is present, delete the information.

**System capability**: SystemCapability.Global.I18n

**Return Value**

| Type               | Description        |
| ----------------- | ---------- |
| [Locale](#locale) | **Locale** object with the minimized information.|

**Example**
  ```
  var locale = new Intl.Locale("zh-CN");
  locale.minimize();
  ```


## LocaleOptions<sup>9+</sup>

Represents the locale options.

**System capability**: SystemCapability.Global.I18n

| Name             | Type   | Readable  | Writable  | Description                                      |
| --------------- | ------- | ---- | ---- | ---------------------------------------- |
| calendar        | string  | Yes   | Yes   | Calendar for the locale. The value can be any of the following: **buddhist**, **chinese**, **coptic**, **dangi**, **ethioaa**, **ethiopic**, **gregory**, **hebrew**, **indian**, **islamic**, **islamic-umalqura**, **islamic-tbla**, **islamic-civil**, **islamic-rgsa**, **iso8601**, **japanese**, **persian**, **roc**, **islamicc**.|
| collation       | string  | Yes   | Yes   | Collation rule. The value can be any of the following: **big5han**, **compat**, **dict**, **direct**, **ducet**, **emoji**, **eor**, **gb2312**, **phonebk**, **phonetic**, **pinyin**, **reformed**,**search**, **searchjl**, **standard**, **stroke**, **trad**, **unihan**, **zhuyin**.|
| hourCycle       | string  | Yes   | Yes   | Time system for the locale. The value can be any of the following: **h11**, **h12**, **h23**, **h24**.|
| numberingSystem | string  | Yes   | Yes   | Numbering system for the locale. The value can be any of the following: **adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, **wcho**.|
| numeric         | boolean | Yes   | Yes   | Whether to use the 12-hour clock.                              |
| caseFirst       | string  | Yes   | Yes   | Whether upper case or lower case is sorted first. The value can be **upper**, **lower**, or **false**.|


## DateTimeFormat


### constructor<sup>8+</sup>

constructor()

Creates a **DateTimeOptions** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```
  var datefmt= new Intl.DateTimeFormat();
  ```


### constructor

constructor(locale: string | Array&lt;string&gt;, options?: DateTimeOptions)

Creates a **DateTimeOptions** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type                                 | Mandatory  | Description                          |
| ------- | ----------------------------------- | ---- | ---------------------------- |
| locale  | string \| Array&lt;string&gt;       | Yes   | A string containing locale information, including the language, optional script, and region.|
| options<sup>9+</sup> | [DateTimeOptions](#datetimeoptions9) | No   | Options for creating a **DateTimeFormat** object.             |

**Example**
  ```
  var datefmt= new Intl.DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });
  ```


**Example**
  ```
  var datefmt= new Intl.DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
  ```


### format

format(date: Date): string

Formats the specified date and time.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description     |
| ---- | ---- | ---- | ------- |
| date | Date | Yes   | Date and time to be formatted.|

**Return Value**

| Type    | Description          |
| ------ | ------------ |
| string | A string containing the formatted date and time.|

**Example**
  ```
  var date = new Date(2021, 11, 17, 3, 24, 0);
  var datefmt = new Intl.DateTimeFormat("en-GB");
  datefmt.format(date);
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

**Return Value**

| Type    | Description            |
| ------ | -------------- |
| string | A string containing the formatted date and time range.|

**Example**
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

**Return Value**

| Type                                 | Description                           |
| ----------------------------------- | ----------------------------- |
| [DateTimeOptions](#datetimeoptions9) | Formatting options for **DateTimeFormat** objects.|

**Example**
  ```
  var datefmt = new Intl.DateTimeFormat("en-GB");
  datefmt.resolvedOptions();
  ```


## DateTimeOptions<sup>9+</sup>

Provides the options for the **DateTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

| Name             | Type   | Readable  | Writable  | Description                                      |
| --------------- | ------- | ---- | ---- | ---------------------------------------- |
| locale          | string  | Yes   | No   | Locale, for example, **zh-Hans-CN**.                |
| dateStyle       | string  | Yes   | Yes   | Date display format. The value can be **long**, **short**, **medium**, or **full**.|
| timeStyle       | string  | Yes   | Yes   | Time display format. The value can be **long**, **short**, **medium**, or **full**.|
| hourCycle       | string  | Yes   | Yes   | Time system for the locale. The value can be any of the following: **h11**, **h12**, **h23**, **h24**.|
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
  ```
  var numfmt = new Intl.NumberFormat();
  ```


### constructor

constructor(locale: string | Array&lt;string&gt;, options?: NumberOptions)

Creates a **NumberFormat** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

Parameters
| Name    | Type                             | Mandatory  | Description                          |
| ------- | ------------------------------- | ---- | ---------------------------- |
| locale  | string \| Array&lt;string&gt;   | Yes   | A string containing locale information, including the language, optional script, and region.|
| options<sup>9+</sup> | [NumberOptions](#numberoptions9) | No   | Options for creating a **NumberFormat** object.               |

**Example**
  ```
  var numfmt = new Intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
  ```


### format

format(number: number): string;

Formats a number.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description  |
| ------ | ------ | ---- | ---- |
| number | number | Yes   | Number to be formatted.|

**Return Value**

| Type    | Description        |
| ------ | ---------- |
| string | Formatted number.|


**Example**
  ```
  var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  numfmt.format(1223);
  ```


### resolvedOptions

resolvedOptions(): NumberOptions

Obtains the options of the **NumberFormat** object.

**System capability**: SystemCapability.Global.I18n

**Return Value**

| Type                             | Description                         |
| ------------------------------- | --------------------------- |
| [NumberOptions](#numberoptions9) | Formatting options for **NumberFormat** objects.|


**Example**
  ```
  var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  numfmt.resolvedOptions();
  ```


## NumberOptions<sup>9+</sup>

Provides the device capability.

**System capability**: SystemCapability.Global.I18n

| Name                      | Type   | Readable  | Writable  | Description                                      |
| ------------------------ | ------- | ---- | ---- | ---------------------------------------- |
| locale                   | string  | Yes   | No   | Locale, for example, **zh-Hans-CN**.              |
| currency                 | string  | Yes   | Yes   | Currency unit, for example, **EUR**, **CNY**, or **USD**.        |
| currencySign             | string  | Yes   | Yes   | Currency unit symbol. The value can be **symbol**, **narrowSymbol**, **code**, or **name**.|
| currencyDisplay          | string  | Yes   | Yes   | Currency display mode. The value can be **symbol**, **narrowSymbol**, **code**, or **name**.|
| unit                     | string  | Yes   | Yes   | Unit name, for example, **meter**, **inch**, or **hectare**.       |
| unitDisplay              | string  | Yes   | Yes   | Unit display format. The value can be **long**, **short**, or **narrow**.|
| unitUsage                | string  | Yes   | Yes   | Unit usage scenario. The value can be any of the following: **default**, **area-land-agricult**, **area-land-commercl**, **area-land-residntl**, **length-person**, **length-person-small**, **length-rainfall**, **length-road**, **length-road-small**, **length-snowfall**, **length-vehicle**, **length-visiblty**, **length-visiblty-small**, **length-person-informal**, **length-person-small-informal**, **length-road-informal**, **speed-road-travel**, **speed-wind**, **temperature-person**, **temperature-weather**, **volume-vehicle-fuel**.|
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

Creates a Collator object.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```
  var collator = new Intl.Collator();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: CollatorOptions)

Creates a Collator object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type                                 | Mandatory  | Description                          |
| ------- | ----------------------------------- | ---- | ---------------------------- |
| locale  | string \| Array&lt;string&gt;       | Yes   | A string containing locale information, including the language, optional script, and region.|
| options<sup>9+</sup> | [CollatorOptions](#collatoroptions9) | No   | Options for creating a **Collator** object.                |

**Example**
  ```
  var collator = new Intl.Collator("zh-CN", {localeMatcher: "lookup", usage: "sort"});
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

**Return Value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Comparison result. If the value is a negative number, the first string is before the second string. If the value of number is **0**, the first string is equal to the second string. If the value of number is a positive number, the first string is after the second string.|

**Example**
  ```
  var collator = new Intl.Collator("zh-Hans");
  collator.compare("first", "second");
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): CollatorOptions

Returns properties reflecting the locale and collation options of a **Collator** object.

**System capability**: SystemCapability.Global.I18n

**Return Value**

| Type                                 | Description               |
| ----------------------------------- | ----------------- |
| [CollatorOptions](#collatoroptions9) | Properties of the **Collator** object.|

**Example**

  ```
  var collator = new Intl.Collator("zh-Hans");
  var options = collator.resolvedOptions();
  ```


## CollatorOptions<sup>9+</sup>

Represents the properties of a **Collator** object.

**System capability**: SystemCapability.Global.I18n

| Name               | Type   | Readable  | Writable  | Description                                      |
| ----------------- | ------- | ---- | ---- | ---------------------------------------- |
| localeMatcher     | string  | Yes   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.|
| usage             | string  | Yes   | Yes   | Whether the comparison is for sorting or for searching. The value can be **sort** or **search**.       |
| sensitivity       | string  | Yes   | Yes   | Differences in the strings that lead to non-zero return values. The value can be **base**, **accent**, **case**, or **variant**.|
| ignorePunctuation | boolean | Yes   | Yes   | Whether punctuation is ignored. The value can be **true** or **false**.       |
| collation         | string  | Yes   | Yes   | Rule for sorting regions. The value can be any of the following: **big5han**, **compat**, **dict**, **direct**, **ducet**, **eor**, **gb2312**, **phonebk**, **phonetic**, **pinyin**, **reformed**, **searchjl**, **stroke**, **trad**, **unihan**, **zhuyin**.|
| numeric           | boolean | Yes   | Yes   | Whether numeric collation is used. The value can be **true** or **false**.         |
| caseFirst         | string  | Yes   | Yes   | Whether upper case or lower case is sorted first. The value can be **upper**, **lower**, or **false**.|


## PluralRules<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

Create a **PluralRules** object.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```
  var pluralRules = new Intl.PluralRules();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: PluralRulesOptions)

Create a **PluralRules** object.

**System capability**: SystemCapability.Global.I18n

Parameters
| Name    | Type                                      | Mandatory  | Description                          |
| ------- | ---------------------------------------- | ---- | ---------------------------- |
| locale  | string \| Array&lt;string&gt;            | Yes   | A string containing locale information, including the language, optional script, and region.|
| options<sup>9+</sup> | [PluralRulesOptions](#pluralrulesoptions9) | No   | Options for creating a **PluralRules** object.               |

**Example**
  ```
  var pluralRules= new Intl.PluralRules("zh-CN", {"localeMatcher": "lookup", "type": "cardinal"});
  ```


### select<sup>8+</sup>

select(n: number): string

Obtains a string that represents the singular-plural type of the specified number.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| n    | number | Yes   | Number for which the singular-plural type is to be obtained.|

**Return Value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| string | Singular-plural type. The value can be any of the following: **one**, **two**, **few**, **many**, **others**.|

**Example**
  ```
  var pluralRules = new Intl.PluralRules("zh-Hans");
  pluralRules.select(1);
  ```


## PluralRulesOptions<sup>9+</sup>

Represents the properties of a **PluralRules** object.

**System capability**: SystemCapability.Global.I18n

| Name                      | Type  | Readable  | Writable  | Description                                      |
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
  ```
  var relativetimefmt = new Intl.RelativeTimeFormat();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: RelativeTimeFormatInputOptions)

Creates a **RelativeTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type                                      | Mandatory  | Description                          |
| ------- | ---------------------------------------- | ---- | ---------------------------- |
| locale  | string \| Array&lt;string&gt;            | Yes   | A string containing locale information, including the language, optional script, and region.|
| options<sup>9+</sup> | [RelativeTimeFormatInputOptions](#relativetimeformatinputoptions9) | No   | Options for creating a **RelativeTimeFormat** object.           |

**Example**
  ```
  var relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {"localeMatcher": "lookup", "numeric": "always", "style": "long"});
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

**Return Value**

| Type    | Description        |
| ------ | ---------- |
| string | Relative time after formatting.|

**Example**
  ```
  var relativetimefmt = new Intl.RelativeTimeFormat("zh-CN");
  relativetimefmt.format(3, "quarter")
  ```


### formatToParts<sup>8+</sup>

formatToParts(value: number, unit: string): Array&lt;object&gt;

Returns an array of RelativeTimeFormat objects in parts for locale-aware formatting.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | Yes   | Value to format.                             |
| unit  | string | Yes   | Unit to format. The value can be any of the following: **year**, **quarter**, **month**, **week**, **day**, **hour**, **minute**, **second**.|

**Return Value**

| Type                 | Description                         |
| ------------------- | --------------------------- |
| Array&lt;object&gt; | An array of **RelativeTimeFormat** objects in parts.|

**Example**
  ```
  var relativetimefmt = new Intl.RelativeTimeFormat("en", {"numeric": "auto"});
  var parts = relativetimefmt.format(10, "seconds");
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): RelativeTimeFormatResolvedOptions

Obtains the formatting options for **RelativeTimeFormat** objects.

**System capability**: SystemCapability.Global.I18n

**Return Value**

| Type                                      | Description                               |
| ---------------------------------------- | --------------------------------- |
| [RelativeTimeFormatResolvedOptions](#relativetimeformatresolvedoptions8) | Formatting options for **RelativeTimeFormat** objects.|

**Example**
  ```
  var relativetimefmt= new Intl.RelativeTimeFormat("en-GB");
  relativetimefmt.resolvedOptions();
  ```


## RelativeTimeFormatInputOptions<sup>9+</sup>

Represents the properties of a **RelativeTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

| Name           | Type  | Readable  | Writable  | Description                                      |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| localeMatcher | string | Yes   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.|
| numeric       | string | Yes   | Yes   | Format of the output message. The value can be **always** or **auto**.     |
| style         | string | Yes   | Yes   | Length of an internationalized message. The value can be **long**, **short**, or **narrow**.|


## RelativeTimeFormatResolvedOptions<sup>8+</sup><a name=relativetimeformatresolvedoptions></a>

Represents the properties of a **RelativeTimeFormat** object.

**System capability**: SystemCapability.Global.I18n

| Name             | Type  | Readable  | Writable  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| locale          | string | Yes   | Yes   | A string containing locale information, including the language, optional script, and region.            |
| numeric         | string | Yes   | Yes   | Format of the output message. The value can be **always** or **auto**.     |
| style           | string | Yes   | Yes   | Length of an internationalized message. The value can be **long**, **short**, or **narrow**.|
| numberingSystem | string | Yes   | Yes   | Numbering system.                                |
