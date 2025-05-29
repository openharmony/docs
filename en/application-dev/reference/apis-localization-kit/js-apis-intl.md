# @ohos.intl (Internationalization)

The **intl** module provides basic i18n capabilities, such as time and date formatting, number formatting, and string sorting, through the standard i18n APIs defined in ECMA 402.
The [i18n](js-apis-i18n.md) module provides enhanced i18n capabilities through supplementary interfaces that are not defined in ECMA 402. It works with the intl module to provide a complete suite of i18n capabilities.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs of this module conform to the [Common Locale Data Repository (CLDR)](https://cldr.unicode.org) internationalization database. The processing result may change with CLDR evolution. API version 12 corresponds to [CLDR 42](https://cldr.unicode.org/index/downloads/cldr-42). For details about data changes, visit the official website.
>
>  - Since API version 11, some APIs of this module are supported in ArkTS widgets.
>
>  - Since API version 12, the APIs of this module are supported in atomic services.


## Modules to Import

```ts
import { intl } from '@kit.LocalizationKit';
```

## Locale

### Attributes

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name             | Type     | Mandatory  | Description                                      |
| --------------- | ------- | -------- | ---------------------------------------- |
| language        | string  | Yes   | Language associated with the locale, for example, **zh**. The value complies with the ISO 639 standard.|
| script          | string  | Yes   | Script type of the language, for example, **Hans**. The value complies with the Unicode ISO 15924 standard.|
| region          | string  | Yes   | Country/region associated with the locale, for example, **CN**. The value complies with the ISO 3166 standard.|
| baseName        | string  | Yes   | Locale information, which consists of the language, script, and country/region, for example, **zh-Hans-CN**. |
| caseFirst       | string  | Yes   | Whether case is taken into account for the locale's collation rules. The value can be:<br>"upper",&nbsp;"lower", or &nbsp;"false".<br>For details about their meanings, see Table 1 in [Sorting by Local Habits ](../../internationalization/i18n-sorting-local.md).|
| calendar        | string  | Yes   | Calendar for the locale. The value can be:<br>The value can be any of the following: **buddhist**, **chinese**, **coptic**, **dangi**, **ethioaa**, **ethiopic**, **gregory**, **hebrew**, **indian**, **islamic**, **islamic-umalqura**, **islamic-tbla**, **islamic-civil**, **islamic-rgsa**, **iso8601**, **japanese**, **persian**, **roc**, or **islamicc**.<br>For details about their meanings, see Table 1 in [Calendar Setting](../../internationalization/i18n-calendar.md).|
| collation       | string  | Yes   | Collation rules for the locale. The value can be:<br>The value can be any of the following: **big5han**, **compat**, **dict**, **direct**, **ducet**, **eor**, **gb2312**, **phonebk**, **phonetic**, **pinyin**, **reformed**, **searchjl**, **stroke**, **trad**, **unihan**, or **zhuyin**.<br>For details about their meanings, see Table 1 in [Sorting by Local Habits ](../../internationalization/i18n-sorting-local.md).|
| hourCycle       | string  | Yes   | Time system for the locale. The value can be:<br>"h11", "h12", "h23", or "h24".<br>For details about their display effects, see Table 5 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).|
| numberingSystem | string  | Yes   | Numbering system for the locale. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.|
| numeric         | boolean | Yes   | Wether to use special sorting rules for digits. The value **true** means to use special sorting rules for digits, and the value **false** means the opposite.<br>The default value is **false**.                     |

### constructor<sup>8+</sup>

constructor()

Creates a **Locale** object.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  // The current system locale is used by the default constructor.
  let locale = new intl.Locale();
  // Return the current system locale ID.
  let localeID = locale.toString();
  ```

### constructor

constructor(locale: string, options?: LocaleOptions)

Creates a **Locale** object.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                              | Mandatory  | Description                          |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string                           | Yes   | Locale information, which consists of the language, script, and country/region.|
| options             | [LocaleOptions](#localeoptions) | No   | Options for creating the **Locale** object.|

**Example**
  ```ts
  // Create a zh-CN locale object.
  let locale = new intl.Locale("zh-CN");
  let localeID = locale.toString(); // localeID = "zh-CN"
  ```


### toString

toString(): string

Obtains the string that represents a **Locale** object.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | String that represents the **Locale** object.|

**Example**
  ```ts
  // Create an en-GB locale object.
  let locale = new intl.Locale("en-GB");
  let localeID = locale.toString(); // localeID = "en-GB"
  ```

### maximize

maximize(): Locale

Maximizes locale information by supplementing the missing script and country/region information.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type               | Description        |
| ----------------- | ---------- |
| [Locale](#locale) | **Locale** object with the script and country/region information.|

**Example**
  ```ts
  // Create a zh locale object.
  let locale = new intl.Locale("zh");
  // Supplement the locale object's script and region.
  let maximizedLocale = locale.maximize();
  let localeID = maximizedLocale.toString(); // localeID = "zh-Hans-CN"

  // Create an en-US locale object.
  locale = new intl.Locale("en-US");
  // Supplement the locale object's script.
  maximizedLocale = locale.maximize();
  localeID = maximizedLocale.toString(); // localeID = "en-Latn-US"
  ```


### minimize

minimize(): Locale

Minimizes locale information by removing the script and country/region information.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type               | Description        |
| ----------------- | ---------- |
| [Locale](#locale) | **Locale** object without the script and country/region information.|

**Example**
  ```ts
  // Create a zh-Hans-CN locale object.
  let locale = new intl.Locale("zh-Hans-CN");
  // Remove the locale object's script and region.
  let minimizedLocale = locale.minimize();
  let localeID = minimizedLocale.toString(); // localeID = "zh"

  // Create an en-US locale object.
  locale = new intl.Locale("en-US");
  // Remove locale object's region.
  minimizedLocale = locale.minimize();
  localeID = minimizedLocale.toString(); // localeID = "en"
  ```

## LocaleOptions

Options for initializing the **Locale** object. Since API version 9, the **LocaleOptions** attribute is changed from mandatory to optional.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name             | Type     | Mandatory  |  Description                                      |
| --------------- | ------- | ---- |---------------------------------------- |
| calendar        | string  | No  |Calendar parameter. The value can be:<br>"buddhist", "chinese", "coptic", "dangi", "ethioaa", "ethiopic", "gregory", "hebrew", "indian", "islamic", "islamic-umalqura", "islamic-tbla", "islamic-civil", "islamic-rgsa", "iso8601", "japanese", "persian", "roc", or "islamicc".|
| collation       | string  | No    |Collation parameter. The value can be:<br>"big5han", "compat", "dict", "direct", "ducet", "emoji", "eor", "gb2312", "phonebk", "phonetic", "pinyin", "reformed	**search**, **searchjl**, **standard**, **stroke**, **trad**, **unihan**, **zhuyin**.|
| hourCycle       | string  | No    |Hour cycle. The value can be:<br>"h11",&nbsp;"h12",&nbsp;"h23", or &nbsp;"h24".|
| numberingSystem | string  | No    |Numbering system. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.|
| numeric         | boolean | No    | Wether to use special sorting rules for digits. The value **true** means to use special sorting rules for digits, and the value **false** means the opposite. The default value is **false**.                              |
| caseFirst       | string  | No    | Whether upper case or lower case is sorted first. The value can be **upper**, **lower**, or **false**.|

>  **NOTE**
>
>  - For details about **calendar**, see Table 1 in [Calendar Setting](../../internationalization/i18n-calendar.md).
>
>  - For details about **hourCycle**, see Table 5 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).
>
>  - For details about **caseFirst** and **collation**, see Table 1 in [Sorting by Local Habits ](../../internationalization/i18n-sorting-local.md).

## DateTimeFormat

### constructor<sup>8+</sup>

constructor()

Creates a **DateTimeOptions** object for the specified locale.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  // Create a DateTimeFormat object using the current system locale ID.
  let datefmt= new intl.DateTimeFormat();
  ```

### constructor

constructor(locale: string | Array&lt;string&gt;, options?: DateTimeOptions)

Creates a **DateTimeOptions** object for the specified locale.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                  | Mandatory  | Description                          |
| -------------------- | ------------------------------------ | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;        | Yes   | Locale ID or locale ID array. If the input is a locale ID array, the first valid locale ID is used.|
| options              | [DateTimeOptions](#datetimeoptions) | No   | Options for creating the **DateTimeOptions** object.<br>If no options are set, the default values of **year**, **month**, and **day** are **numeric**.|

**Example**
  ```ts
  // Create a DateTimeFormat object with locale ID being zh-CN, dateStyle being full, and timeStyle being medium.
  let datefmt= new intl.DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });

  // Create a DateTimeFormat object with a locale ID array. The locale ID ban is invalid and therefore locale ID zh is used.
  let datefmt= new intl.DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
  ```

### format

format(date: Date): string

Formats the date and time.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description     |
| ---- | ---- | ---- | ------- |
| date | Date | Yes   | Date and time. Note: The month starts from **0**. For example, **0** indicates January.|

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | A string containing the formatted date and time.|

**Example**
  ```ts
  let date = new Date (2021, 11, 17, 3, 24, 0); // The date and time is 2021.12.17 03:24:00.
  // Create a DateTimeFormat object with the locale ID being en-GB.
  let datefmt = new intl.DateTimeFormat("en-GB");
  let formattedDate = datefmt.format(date); // formattedDate "17/12/2021"

  // Create a DateTimeFormat object with locale ID being en-GB, dateStyle being full, and timeStyle being medium.
  datefmt = new intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });
  formattedDate = datefmt.format(date); // formattedDate "Friday, 17 December 2021 at 03:24:00"
  ```

### formatRange

formatRange(startDate: Date, endDate: Date): string

Formats date and time ranges.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name      | Type  | Mandatory  | Description      |
| --------- | ---- | ---- | -------- |
| startDate | Date | Yes   | Start date and time. Note: The month starts from **0**. For example, **0** indicates January.|
| endDate   | Date | Yes   | End date and time. Note: The month starts from **0**. For example, **0** indicates January.|

**Return value**

| Type    | Description            |
| ------ | -------------- |
| string | A string containing the formatted date and time ranges.|

**Example**
  ```ts
  let startDate = new Date(2021, 11, 17, 3, 24, 0); // The date and time is 2021.12.17 03:24:00.
  let endDate = new Date(2021, 11, 18, 3, 24, 0);
  // Create a DateTimeFormat object with the locale ID being en-GB.
  let datefmt = new intl.DateTimeFormat("en-GB");
  let formattedDateRange = datefmt.formatRange(startDate, endDate); // formattedDateRange = "17/12/2021 - 18/12/2021"
  ```

### resolvedOptions

resolvedOptions(): DateTimeOptions

Obtains the options for creating a **DateTimeOptions** object.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                                  | Description                           |
| ------------------------------------ | ----------------------------- |
| [DateTimeOptions](#datetimeoptions) | Options for the **DateTimeOptions** object.|

**Example**
  ```ts
  let datefmt = new intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });
  // Obtain the options of the DateTimeFormat object.
  let options = datefmt.resolvedOptions();
  let dateStyle = options.dateStyle; // dateStyle = "full"
  let timeStyle = options.timeStyle; // timeStyle = "medium"
  ```


## DateTimeOptions

Defines the options for a **DateTimeOptions** object. Since API version 9, the **DateTimeOptions** attribute is changed from mandatory to optional.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name             | Type     | Mandatory  | Description                                      |
| --------------- | ------- | ---- |  ---------------------------------------- |
| locale          | string  | No   |Valid locale ID, for example, **zh-Hans-CN**.<br>The default value is the current system locale.          |
| dateStyle       | string  | No    |Date display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"medium",&nbsp;"full", or &nbsp;"auto".<br>For details about their display effects, see Table 1 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).|
| timeStyle       | string  | No    |Time display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"medium",&nbsp;"full", or &nbsp;"auto".<br>For details about their display effects, see Table 2 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).|
| hourCycle       | string  | No    |Hour cycle. The value can be:<br>"h11",&nbsp;"h12",&nbsp;"h23", or &nbsp;"h24".<br>For details about the display effect when **dateStyle** or **timeStyle** is not set, see Table 5 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).<br>For details about the display effect when **dateStyle** or **timeStyle** is set, see Table 6 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).|
| timeZone        | string  | No    |Time zone in use. The value is a valid IANA time zone ID.                     |
| numberingSystem | string  | No    |Numbering system. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.|
| hour12          | boolean | No    | Whether to use the 12-hour clock. The value **true** means to use the 12-hour clock, and the value **false** means the opposite.<br>If both **hour12** and **hourCycle** are set, **hourCycle** does not take effect.<br>If **hour12** and **hourCycle** are not set and the 24-hour clock is turned on, the default value of **hour12** is **false**.|
| weekday         | string  | No    | Week display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"narrow", or &nbsp;"auto".<br>For details about their display effects, see Table 4 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).|
| era             | string  | No    | Epoch display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"narrow", or &nbsp;"auto".<br>For details about their display effects, see Table 9 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).|
| year            | string  | No    | Year display format. The value can be:<br>"numeric" or &nbsp;"2-digit".<br>For details about their display effects, see Table 3 in [Date and Time Formatting](../../internationalization/i18n-time-date.md). |
| month           | string  | No   | Month display format. The value can be:<br>"numeric",&nbsp;"2-digit",&nbsp;"long",&nbsp;"short",&nbsp;"narrow", or &nbsp;"auto".<br>For details about their display effects, see Table 6 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).|
| day             | string  | No    | Day display format. The value can be:<br>"numeric" or &nbsp;"2-digit". |
| hour            | string  | No    | Hour display format. The value can be:<br>"numeric" or &nbsp;"2-digit". |
| minute          | string  | No    | Minute display format. The value can be:<br>"numeric" or &nbsp;"2-digit". |
| second          | string  | No    | Second display format. The value can be:<br>"numeric" or &nbsp;"2-digit". |
| timeZoneName    | string  | No    | Localized representation of a time zone name. The value can be:<br>"long",&nbsp;"short", or &nbsp;"auto".<br>For details about their display effects, see Table 8 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).  |
| dayPeriod       | string  | No    | Time period display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"narrow", or &nbsp;"auto".<br>For details about their display effects, see Table 10 in [Date and Time Formatting](../../internationalization/i18n-time-date.md).|
| localeMatcher   | string  | No    | Locale matching algorithm. The value can be:<br>- "lookup": exact match.<br>- "best fit": best match.|
| formatMatcher   | string  | No    | Format matching algorithm. The value can be:<br>- "basic": exact match.<br>- "best fit": best match.|

## NumberFormat

### constructor<sup>8+</sup>

constructor()

Creates a **NumberFormat** object for the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  // Create a NumberFormat object using the current system locale ID.
  let numfmt = new intl.NumberFormat();
  ```


### constructor

constructor(locale: string | Array&lt;string&gt;, options?: NumberOptions)

Creates a **NumberFormat** object for the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                              | Mandatory  | Description                          |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;    | Yes   | Locale ID or locale ID array. If the input is a locale ID array, the first valid locale ID is used.|
| options              | [NumberOptions](#numberoptions) | No   | Options for creating the **NumberFormat** object.              |

**Example**
  ```ts
  // Create a NumberFormat object with locale ID being en-GB, style being decimal, and notation being scientific.
  let numfmt = new intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
  ```

### format

format(number: number): string

Formats a number.

**Atomic service API**: This API can be used in atomic services since API version 12.

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
  ```ts
  // Create a NumberFormat object with a locale ID array. The locale ID en-GB is valid and therefore is used.
  let numfmt : intl.NumberFormat = new intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  let formattedNumber : string = numfmt.format(1223); // formattedNumber = 1.223E3
  let options : intl.NumberOptions = {
    roundingPriority: "lessPrecision",
    maximumFractionDigits: 3,
    maximumSignificantDigits: 3
  }
  let numberFmt : intl.NumberFormat = new intl.NumberFormat("en", options);
  let result : string = numberFmt.format(1.23456); // result = 1.23
  ```

### formatRange<sup>18+</sup>

formatRange(startRange: number, endRange: number): string

Formats a number range.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description  |
| ------ | ------ | ---- | ---- |
| startRange | number | Yes   | Start number.|
| endRange | number | Yes   | End number.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Formatted number range.|


**Example**
  ```ts
  let numfmt : intl.NumberFormat = new intl.NumberFormat("en-US", {style:'unit', unit:"meter"});
  let formattedRange : string = numfmt.formatRange(0, 3); // formattedRange: 0–3 m
  ```


### resolvedOptions

resolvedOptions(): NumberOptions

Obtains the options for creating a **NumberFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                              | Description                         |
| -------------------------------- | --------------------------- |
| [NumberOptions](#numberoptions) | Options for creating the **NumberFormat** object.|


**Example**
  ```ts
  let numfmt = new intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
  // Obtain the options of the NumberFormat object.
  let options = numfmt.resolvedOptions();
  let style = options.style; // style = decimal
  let notation = options.notation; // notation = scientific
  ```

## NumberOptions

Options for creating the **NumberFormat** object. Since API version 9, the **NumberOptions** attribute is changed from mandatory to optional.

**System capability**: SystemCapability.Global.I18n

| Name                      | Type     | Mandatory  |  Description                                      |
| ------------------------ | ------- | ---- |  ---------------------------------------- |
| locale                   | string  | No   | Valid locale ID, for example, **zh-Hans-CN**.<br>The default value is the current system locale.<br>**Atomic service API**: This API can be used in atomic services since API version 12.              |
| currency                 | string  | No   | Currency unit. The value must comply with the [ISO-4217 standard](https://www.iso.org/iso-4217-currency-codes.html), for example, EUR, CNY, and USD.<br>From API version 12, a three-digit number is supported, for example, **978**, **156**, or **840**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.   |
| currencySign             | string  | No   | Currency unit symbol. The value can be **standard** or **accounting**.<br>The default value is **standard**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| currencyDisplay          | string  | No   | Currency display mode. The value can be **symbol**, **narrowSymbol**, **code**, or **name**.<br>The default value is **symbol**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| unit                     | string  | No   | Unit name, for example, **meter**, **inch**, or **hectare**.<br>The combination units supported since API version 18 are as follows: beat-per-minute, body-weight-per-second, breath-per-minute, foot-per-hour, jump-rope-per-minute, meter-per-hour, milliliter-per-minute-per-kilogram, rotation-per-minute, step-per-minute, and stroke-per-minute.<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| unitDisplay              | string  | No   | Display format of units. The value can be **long**, **short**, or **narrow**.<br>The default value is **short**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| unitUsage<sup>8+</sup>   | string  | No   | Application scenario of units. The value can be any of the following: "default**, **area-land-agricult**, **area-land-commercl**, **area-land-residntl**, **length-person**, **length-person-small**, **length-rainfall**, **length-road**, **length-road-small**, **length-snowfall**, **length-vehicle**, **length-visiblty**, **length-visiblty-small**, **length-person-informal**, **length-person-small-informal**, **length-road-informal**, **speed-road-travel**, **speed-wind**, **temperature-person**, **temperature-weather**, **volume-vehicle-fuel**, **elapsed-time-second**, **size-file-byte**, or **size-shortfile-byte**.<br>The default value is **default**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| signDisplay              | string  | No   | Number sign display format. The value can be:<br>- "auto": automatically determines whether to display the plus or minus sign.<br>- "never": do not display the plus or minus sign.<br>- "always": always displays the plus or minus sign.<br>- "exceptZero": displays the plus or minus sign for all values except 0.<br>Default value: **"auto"**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| compactDisplay           | string  | No   | Compact display format. The value can be **long** or **short**.<br>The default value is **short**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
| notation                 | string  | No   | Number notation. The value can be **standard**, **scientific**, **engineering**, or **compact**.<br>The default value is **standard**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| localeMatcher            | string  | No   | Locale matching algorithm. The value can be **lookup** or **best fit**.<br>The default value is **best fit**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| style                    | string  | No   | Number display format. The value can be **decimal**, **currency**, **percent**, or **unit**.<br>The default value is **decimal**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| numberingSystem          | string  | No   | Numbering system. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.<br>The default value is the default numbering system of the locale.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| useGrouping              | boolean | No   | Whether to enable grouping for display. The value **true** means to enable grouping for display, and the value **false** means the opposite.<br>The default value is **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                 |
| minimumIntegerDigits     | number  | No   | Minimum number of digits allowed in the integer part of a number. The value ranges from **1** to **21**.<br>The default value is **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| minimumFractionDigits    | number  | No   | Minimum number of digits in the fraction part of a number. The value ranges from **0** to **20**.<br>The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| maximumFractionDigits    | number  | No   | Maximum number of digits in the fraction part of a number. The value ranges from **1** to **21**.<br>The default value is **3**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| minimumSignificantDigits | number  | No   | Minimum number of the least significant digits. The value ranges from **1** to **21**.<br>The default value is **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| maximumSignificantDigits | number  | No   | Maximum number of the least significant digits. The value ranges from **1** to **21**.<br>The default value is **21**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| roundingPriority<sup>18+</sup>   | string  | No   | Rounding priority used when both the maximum number of fraction digits and the maximum number of valid digits are set. The value can be **auto**, **morePrecision**, or **lessPrecision**. The value **morePrecision** indicates that the maximum number of fraction digits is used. The value **lessPrecision** indicates that the maximum number of valid digits is used.<br>The default value is **auto**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.                 |
| roundingIncrement<sup>18+</sup>  | number  | No   | Rounding increment. The value can be **1**, **2**, **5**, **10**, **20**, **25**, **50**, **100**, **200**, **250**, **500**, **1000**, **2000**, **2500**, or **5000**.<br>The default value is **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.                 |
| roundingMode<sup>18+</sup>       | string  | No   | Rounding mode. The value can be:<br>- "ceil": rounding up.<br>- "floor": rounding down.<br>- "expand": rounding away from 0.<br>- "trunc": rounding toward 0.<br>- "halfCeil": half-rounding up; that is, rounding up when the decimal number is greater than or equal to half of the increment, and rounding down otherwise.<br>- "halfFloor": half-rounding down; that is, rounding up when the decimal number is greater than half of the increment, and rounding down otherwise.<br>- "halfExpand": half-rounding away from 0; that is, rounding away from 0 when the decimal number is greater than or equal to half of the increment, and rounding toward 0 otherwise.<br>- "halfTrunc": half-rounding toward 0; that is, rounding away from 0 when the decimal number is greater than half of the increment, and rounding toward 0 otherwise.<br>- "halfEven": half-rounding to the nearest even number; that is, rounding away from 0 when the decimal number is greater than half of the increment, rounding toward 0 when the decimal number is less than half of the increment, and rounding to the nearest even number when the decimal number is exactly half of the increment.<br>The default value is **halfExpand**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

>  **NOTE**
>
>  - For details about the meaning or display effect of different values, see [Number and Unit of Measurement Formatting](../../internationalization/i18n-numbers-weights-measures.md).

## Collator<sup>8+</sup>

### constructor<sup>8+</sup>

constructor()

Creates a **Collator** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  // Create a Collator object using the current system locale ID.
  let collator = new intl.Collator();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: CollatorOptions)

Creates a **Collator** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                  | Mandatory  | Description                          |
| -------------------- | ------------------------------------ | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;        | Yes   | Locale ID or locale ID array. If the input is a locale ID array, the first valid locale ID is used. |
| options              | [CollatorOptions](#collatoroptions8) | No   | Options for creating a **Collator** object.      |

**Example**
  ```ts
  // Create a Collator object with the locale ID being zh-CN, localeMatcher being lookup, and usage being sort.
  let collator = new intl.Collator("zh-CN", {localeMatcher: "lookup", usage: "sort"});
  ```


### compare<sup>8+</sup>

compare(first: string, second: string): number

Compares two strings based on the specified collation rules.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description          |
| ------ | ------ | ---- | ------------ |
| first  | string | Yes   | First string to compare. |
| second | string | Yes   | Second string to compare.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Comparison result.<br>- If the value is a negative number, the first string comes before the second string.<br>- If the value is **0**, the first and second strings are in the same sequence.<br>- If the value is a positive number, the first string is comes after the second string.|

**Example**
  ```ts
  // Create a Collator object with the locale ID being en-GB.
  let collator = new intl.Collator("en-GB");
  // Compare the sequence of the first and second strings.
  let compareResult = collator.compare("first", "second"); // compareResult = -1
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): CollatorOptions

Obtains the options for creating a **Collator** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                                  | Description               |
| ------------------------------------ | ----------------- |
| [CollatorOptions](#collatoroptions8) | Options for creating a **Collator** object.|

**Example**
  ```ts
  let collator = new intl.Collator("zh-Hans", { usage: 'sort', ignorePunctuation: true });
  // Obtain the options of the Collator object.
  let options = collator.resolvedOptions();
  let usage = options.usage; // usage = "sort"
  let ignorePunctuation = options.ignorePunctuation; // ignorePunctuation = true
  ```


## CollatorOptions<sup>8+</sup>

Defines the options for creating a **Collator** object.

Since API version 9, the attributes in **CollatorOptions** are optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name               | Type     | Mandatory  | Description                                      |
| ----------------- | ------- | ---- | ---------------------------------------- |
| localeMatcher     | string  | No   | Locale matching algorithm. The value can be **lookup** or **best fit**.<br>The default value is **best fit**.|
| usage             | string  | No   | Whether the comparison is for sorting or for searching. The value can be **sort** or **search**.<br>The default value is **sort**.       |
| sensitivity       | string  | No   | Differences in the strings that lead to non-zero return values. The value can be **base**, **accent**, **case**, or **letiant**.<br>The default value is **variant**.|
| ignorePunctuation | boolean | No   | Whether to ignore punctuation. The value **true** means to ignore punctuation, and the value **false** means the opposite.<br>The default value is **false**.       |
| collation         | string  | No   | Collation rule.<br>The value can be any of the following: **big5han**, **compat**, **dict**, **direct**, **ducet**, **eor**, **gb2312**, **phonebk**, **phonetic**, **pinyin**, **reformed**, **searchjl**, **stroke**, **trad**, **unihan**, or **zhuyin**.<br>The default value is **default**.|
| numeric           | boolean | No   | Whether to use numeric collation. The value **true** means to use numeric collation, and the value **false** means the opposite.<br>The default value is **false**.         |
| caseFirst         | string  | No   | Whether upper case or lower case is sorted first. The value can be **upper**, **lower**, or **false**.<br>The default value is **false**.|


>  **NOTE**
>
>  - For details about the meanings of different field values, see [Sorting by Local Habits](../../internationalization/i18n-sorting-local.md).


## PluralRules<sup>8+</sup>

### constructor<sup>8+</sup>

constructor()

Creates a **PluralRules** object to obtain the singular-plural type of numbers.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  // Create a PluralRules object using the current system locale ID.
  let pluralRules = new intl.PluralRules();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: PluralRulesOptions)

Creates a **PluralRules** object to obtain the singular-plural type of numbers.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                          |
| -------------------- | ---------------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;            | Yes   | Locale ID or locale ID array. If the input is a locale ID array, the first valid locale ID is used.|
| options              | [PluralRulesOptions](#pluralrulesoptions8) | No   | Options for creating a **PluralRules** object.      |

**Example**
  ```ts
  // Create a PluralRules object with the locale ID being zh-CN, localeMatcher being lookup, and type being cardinal.
  let pluralRules= new intl.PluralRules("zh-CN", {"localeMatcher": "lookup", "type": "cardinal"});
  ```

### select<sup>8+</sup>

select(n: number): string

Obtains the singular-plural type of the specified number.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| n    | number | Yes   | Number for which the singular-plural type is to be obtained.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| string | Singular-plural type. The value can be any of the following: **zero**, **one**, **two**, **few**, **many**, **others**.<br>For details about the meanings of different values, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|

**Example**
  ```ts
  // Create a PluralRules object with the locale ID being zh-Hans.
  let zhPluralRules = new intl.PluralRules("zh-Hans");
  // Determine the singular-plural type corresponding to number 1 in locale zh-Hans.
  let plural = zhPluralRules.select(1); // plural = other

  // Create a PluralRules object with the locale ID being en-US.
  let enPluralRules = new intl.PluralRules("en-US");
  // Determine the singular-plural type corresponding to number 1 in locale en-US.
  plural = enPluralRules.select(1); // plural = one
  ```


## PluralRulesOptions<sup>8+</sup>

Defines the options for creating a **PluralRules** object. Since API version 9, the **PluralRulesOptions** attribute is changed from mandatory to optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name                      | Type    | Readable  | Writable  | Description                                      |
| ------------------------ | ------ | ---- | ---- | ---------------------------------------- |
| localeMatcher            | string | Yes   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.<br>The default value is **best fit**.|
| type                     | string | Yes   | Yes   | Collation type. The value can be **cardinal** or **ordinal**.<br>The default value is **cardinal**.<br>The value **cardinal** indicates a cardinal number and the value **ordinal** indicates an ordinal number. |
| minimumIntegerDigits     | number | Yes   | Yes   | Minimum number of digits allowed in the integer part of a number. The value ranges from **1** to **21**.<br>The default value is **1**.                 |
| minimumFractionDigits    | number | Yes   | Yes   | Minimum number of digits in the fraction part of a number. The value ranges from **0** to **20**.<br>The default value is **0**.                 |
| maximumFractionDigits    | number | Yes   | Yes   | Maximum number of digits in the fraction part of a number. The value ranges from **1** to **21**.<br>The default value is **3**.                 |
| minimumSignificantDigits | number | Yes   | Yes   | Minimum number of the least significant digits. The value ranges from **1** to **21**.<br>The default value is **1**.                 |
| maximumSignificantDigits | number | Yes   | Yes   | Maximum number of the least significant digits. The value ranges from **1** to **21**.<br>The default value is **21**.               |


## RelativeTimeFormat<sup>8+</sup>

### constructor<sup>8+</sup>

constructor()

Creates a **RelativeTimeFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  // Create a RelativeTimeFormat object using the current system locale ID.
  let relativetimefmt = new intl.RelativeTimeFormat();
  ```


### constructor<sup>8+</sup>

constructor(locale: string | Array&lt;string&gt;, options?: RelativeTimeFormatInputOptions)

Creates a **RelativeTimeFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                          |
| -------------------- | ---------------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;            | Yes   | Locale ID or locale ID array. If the input is a locale ID array, the first valid locale ID is used.|
| options              | [RelativeTimeFormatInputOptions](#relativetimeformatinputoptions8) | No   | Options for creating a **RelativeTimeFormat** object.    |

**Example**
  ```ts
  // Create a RelativeTimeFormat object with the locale ID being zh-CN, localeMatcher being lookup, and style being long.
  let relativeTimeFormat = new intl.RelativeTimeFormat("zh-CN", {"localeMatcher": "lookup", "numeric": "always", "style": "long"});
  ```


### format<sup>8+</sup>

format(value: number, unit: string): string

Formats a relative time.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | Yes   | Value to format.                             |
| unit  | string | Yes   | Unit of the relative time.<br>The value can be any of the following: **year**, **quarter**, month**, **week**, **day**, **hour**, **minute**, or **second**.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Relative time after formatting.|

**Example**
  ```ts
  // Create a RelativeTimeFormat object with the locale ID being zh-CN.
  let relativetimefmt = new intl.RelativeTimeFormat("zh-CN");
  // Obtain the localized representation (in unit of quarter) of number 3 in locale zh-CN.
  let formatResult = relativetimefmt.format(3, "quarter"); // formatResult = "3 quarters later"
  ```


### formatToParts<sup>8+</sup>

formatToParts(value: number, unit: string): Array&lt;object&gt;

Formats the relative time

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | Yes   | Value to format.                             |
| unit  | string | Yes   | Unit of the relative time.<br>The value can be any of the following: **year**, **quarter**, month**, **week**, **day**, **hour**, **minute**, or **second**.|

**Return value**

| Type                 | Description                         |
| ------------------- | --------------------------- |
| Array&lt;object&gt; | to parts.|

**Example**
  ```ts
  // Create a RelativeTimeFormat object with the locale ID being en and numeric being auto.
  let relativetimefmt = new intl.RelativeTimeFormat("en", {"numeric": "auto"});
  let parts = relativetimefmt.formatToParts(10, "seconds"); // parts = [ {type: "literal", value: "in"}, {type: "integer", value: 10, unit: "second"}, {type: "literal", value: "seconds"} ]
  ```


### resolvedOptions<sup>8+</sup>

resolvedOptions(): RelativeTimeFormatResolvedOptions

Defines the formatting options for a **RelativeTimeFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                                      | Description                               |
| ---------------------------------------- | --------------------------------- |
| [RelativeTimeFormatResolvedOptions](#relativetimeformatresolvedoptions8) | Options for the **RelativeTimeFormat** object.|

**Example**
  ```ts
  // Create a RelativeTimeFormat object with the locale ID being en-GB.
  let relativetimefmt= new intl.RelativeTimeFormat("en-GB", { style: "short" });
  // Obtain the options of the RelativeTimeFormat object.
  let options = relativetimefmt.resolvedOptions();
  let style = options.style; // style = "short"
  ```


## RelativeTimeFormatInputOptions<sup>8+</sup>

Defines the configuration options for a **RelativeTimeFormat** object.

Since API version 9, the attributes in **RelativeTimeFormatInputOptions** are optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name           | Type    | Mandatory  |Description                                      |
| ------------- | ------ | ---- | ---------------------------------------- |
| localeMatcher | string | No   | Locale matching algorithm. The value can be **lookup** or **best fit**.<br>The default value is **best fit**.|
| numeric       | string | No   | Format of the output message. The value can be **always** or **auto**.<br>The default value is **always**.     |
| style         | string | No   | Length of an internationalized message. The value can be **long**, **short**, or **narrow**.<br>The default value is **long**.|

> **NOTE**
>
> For details about the display effects of **numeric** and **style**, see [Date and Time Formatting](../../internationalization/i18n-time-date.md#relative-time-formatting).

## RelativeTimeFormatResolvedOptions<sup>8+</sup>

Represents the formatting options for the **RelativeTimeFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name             | Type    | Mandatory  |Description                                      |
| --------------- | ------ | ---- | ---------------------------------------- |
| locale          | string | Yes   | Locale ID, including the language, script, and region.            |
| numeric         | string | Yes   | Format of the output message. The value can be **always** or **auto**.     |
| style           | string | Yes   | Length of an internationalized message. The value can be **long**, **short**, or **narrow**.|
| numberingSystem | string | Yes   | Numbering system. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.|

> **NOTE**
>
> For details about the display effects of **numeric** and **style**, see [Date and Time Formatting](../../internationalization/i18n-time-date.md#relative-time-formatting).
