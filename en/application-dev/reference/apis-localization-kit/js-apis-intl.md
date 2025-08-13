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

## Locale<sup>(deprecated)</sup>

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
| caseFirst       | string  | Yes   | Whether case is taken into account for the locale's collation rules. The value can be:<br>**upper**: Uppercase letters come first.<br>**lower**: Lowercase letters come first.<br>**false**: The default collation rules of the locale are used.|
| calendar        | string  | Yes   | Calendar for the locale. The value can be:<br>The value can be any of the following: **buddhist**, **chinese**, **coptic**, **dangi**, **ethioaa**, **ethiopic**, **gregory**, **hebrew**, **indian**, **islamic**, **islamic-umalqura**, **islamic-tbla**, **islamic-civil**, **islamic-rgsa**, **iso8601**, **japanese**, **persian**, **roc**, or **islamicc**.<br>For details about their meanings, see Table 1 in [Calendar Setting](../../internationalization/i18n-calendar.md).|
| collation       | string  | Yes   | Collation rules for the locale. The value can be:<br>**big5han**: Pinyin sorting for Latin letters.<br>**compat**: compatibility sorting, only for Arabic.<br>**dict**: dictionary-style sorting, only for Singhalese.<br>**direct**: binary code point sorting.<br>**ducet**: sorting according to the Unicode collation element table.<br>**eor**: sorting according to the European collation rules.<br>**gb2312**: Pinyin sorting, only for Chinese.<br>**phonebk**: phone book-style sorting.<br>**phonetic**: phonetic sorting.<br>**pinyin**: Pinyin sorting.<br>**reformed**: reformed sorting, only for Swedish.<br>**searchjl**: special sorting for Korean initial consonant search.<br>**stroke**: stroke sorting for Chinese.<br>**trad**: traditional-style sorting, for example, Spanish.<br>unihan: radical-stroke sorting for Han characters, only for Chinese, Japanese, and Korean.<br>zhuyin: Zhuyin sorting, only for Chinese.|
| hourCycle       | string  | Yes   | Time system for the locale. The value can be:<br>"h11", "h12", "h23", or "h24".<br>For details about their display effects, see [Table 5](#appendix).|
| numberingSystem | string  | Yes   | Numbering system for the locale. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.|
| numeric         | boolean | Yes   | Whether to use special sorting rules for digits. The value **true** means to use special sorting rules for digits, and the value **false** means the opposite.<br>The default value is **false**.                     |

### constructor<sup>(deprecated)</sup>

constructor()

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.Locale() constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/Locale) instead.

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

### constructor<sup>(deprecated)</sup>

constructor(locale: string, options?: LocaleOptions)

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.Locale() constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/Locale) instead.

Creates a **Locale** object.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                              | Mandatory  | Description                          |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string                           | Yes   | Locale information, which consists of the language, script, and country/region.|
| options             | [LocaleOptions](#localeoptionsdeprecated) | No   | Options for creating the **Locale** object.|

**Example**
  ```ts
  // Create a zh-CN locale object.
  let locale = new intl.Locale("zh-CN");
  let localeID = locale.toString(); // localeID = "zh-CN"
  ```


### toString<sup>(deprecated)</sup>

toString(): string

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.Locale.prototype.toString()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/toString) instead.

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

### maximize<sup>(deprecated)</sup>

maximize(): Locale

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.Locale.prototype.maximize()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/maximize) instead.

Maximizes locale information by supplementing the missing script and country/region information.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type               | Description        |
| ----------------- | ---------- |
| [Locale](#localedeprecated) | **Locale** object with the script and country/region information.|

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


### minimize<sup>(deprecated)</sup>

minimize(): Locale

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.Locale.prototype.minimize()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/minimize) instead.

Minimizes locale information by removing the script and country/region information.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type               | Description        |
| ----------------- | ---------- |
| [Locale](#localedeprecated) | **Locale** object without the script and country/region information.|

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

## LocaleOptions<sup>(deprecated)</sup>

> This API is supported since API version 8 and is deprecated since API version 20. Taking calendar as an example, you are advised to use [Intl.Locale.prototype.calendar()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/calendar).

Options for initializing the **Locale** object. Since API version 9, the **LocaleOptions** attribute is changed from mandatory to optional.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name             | Type     | Read-Only  | Optional  |  Description                                      |
| --------------- | ------- | ---- | ---- |---------------------------------------- |
| calendar        | string  | No  | Yes  |Calendar parameter. The value can be:<br>"buddhist", "chinese", "coptic", "dangi", "ethioaa", "ethiopic", "gregory", "hebrew", "indian", "islamic", "islamic-umalqura", "islamic-tbla", "islamic-civil", "islamic-rgsa", "iso8601", "japanese", "persian", "roc", or "islamicc".|
| collation       | string  | No  | Yes    |Collation rules for the locale. The value can be:<br>**big5han**: Pinyin sorting for Latin letters.<br>**compat**: compatibility sorting, only for Arabic.<br>**dict**: dictionary-style sorting, only for Singhalese.<br>**direct**: binary code point sorting.<br>**ducet**: sorting according to the Unicode collation element table.<br>**eor**: sorting according to the European collation rules.<br>**gb2312**: Pinyin sorting, only for Chinese.<br>**phonebk**: phone book-style sorting.<br>**phonetic**: phonetic sorting.<br>**pinyin**: Pinyin sorting.<br>**reformed**: reformed sorting, only for Swedish.<br>**searchjl**: special sorting for Korean initial consonant search.<br>**stroke**: stroke sorting for Chinese.<br>**trad**: traditional-style sorting, for example, Spanish.<br>unihan: radical-stroke sorting for Han characters, only for Chinese, Japanese, and Korean.<br>zhuyin: Zhuyin sorting, only for Chinese.|
| hourCycle       | string  | No  | Yes    |Hour cycle. The value can be:<br>"h11",&nbsp;"h12",&nbsp;"h23", or &nbsp;"h24".|
| numberingSystem | string  | No  | Yes    |Numbering system. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.|
| numeric         | boolean | No  | Yes    | Whether to treat numeric characters as numbers for sorting. The value true means to treat numeric characters as numbers for sorting, and the value **false** means to treat numeric characters as ordinary characters for sorting. For example, when this parameter is set to **true**, comparing the string **21** with the string **123** is equivalent to comparing the number 21 with the number 123. The default value is **false**.                              |
| caseFirst       | string  | No  | Yes    | Whether case is taken into account for the locale's collation rules. The value can be:<br>**upper**: Uppercase letters come first.<br>**lower**: Lowercase letters come first.<br>**false**: The default collation rules of the locale are used.|

>  **NOTE**
>
>  - For details about **calendar**, see Table 1 in [Calendar Setting](../../internationalization/i18n-calendar.md).

## DateTimeFormat

### constructor<sup>(deprecated)</sup>

constructor()

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.DateTimeFormat() constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat/DateTimeFormat) instead.

Creates a **DateTimeOptions** object for the specified locale.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
```ts
// Create a DateTimeFormat object using the current system locale ID.
let formatter: intl.DateTimeFormat = new intl.DateTimeFormat();
```

### constructor<sup>(deprecated)</sup>

constructor(locale: string | Array&lt;string&gt;, options?: DateTimeOptions)

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.DateTimeFormat() constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat/DateTimeFormat) instead.

Creates a **DateTimeOptions** object for the specified locale.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                  | Mandatory  | Description                          |
| -------------------- | ------------------------------------ | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;        | Yes   | Locale ID or locale ID array. If the input is a locale ID array, the first valid locale ID is used.|
| options              | [DateTimeOptions](#datetimeoptionsdeprecated) | No   | Options for creating the **DateTimeOptions** object.<br>If no options are set, the default values of **year**, **month**, and **day** are **numeric**.|

**Example**
```ts
// Create a DateTimeFormat object with locale ID being zh-CN, dateStyle being full, and timeStyle being medium.
let formatter: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN', { dateStyle: 'full', timeStyle: 'medium' });

// Create a DateTimeFormat object with a locale ID array. The locale ID ban is invalid and therefore locale ID zh is used.
formatter = new intl.DateTimeFormat(['ban', 'zh'], { dateStyle: 'full', timeStyle: 'medium' });
```

### format<sup>(deprecated)</sup>

format(date: Date): string

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.DateTimeFormat.prototype.format()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat/format) instead.

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
let date: Date = new Date(2021, 11, 17, 3, 24, 0); // The date and time is 2021.12.17 03:24:00.
// Create a DateTimeFormat object with the locale ID being en-GB.
let formatter: intl.DateTimeFormat = new intl.DateTimeFormat('en-GB');
let formattedDate: string = formatter.format(date); // formattedDate "17/12/2021"

// Create a DateTimeFormat object with locale ID being en-GB, dateStyle being full, and timeStyle being medium.
formatter = new intl.DateTimeFormat('en-GB', { dateStyle: 'full', timeStyle: 'medium' });
formattedDate = formatter.format(date); // formattedDate "Friday, 17 December 2021, 03:24:00"
```

### formatRange<sup>(deprecated)</sup>

formatRange(startDate: Date, endDate: Date): string

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.DateTimeFormat.prototype.formatRange()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat/formatRange) instead.

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
let startDate: Date = new Date(2021, 11, 17, 3, 24, 0); // The date and time is 2021.12.17 03:24:00.
let endDate: Date = new Date(2021, 11, 18, 3, 24, 0);
// Create a DateTimeFormat object with the locale ID being en-GB.
let formatter: intl.DateTimeFormat = new intl.DateTimeFormat('en-GB');
let formattedDateRange: string = formatter.formatRange(startDate, endDate); // formattedDateRange = "17/12/2021 - 18/12/2021"
```

### resolvedOptions<sup>(deprecated)</sup>

resolvedOptions(): DateTimeOptions

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.DateTimeFormat.prototype.resolvedOptions()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat/resolvedOptions) instead.

Obtains the options for creating a **DateTimeOptions** object.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                                  | Description                           |
| ------------------------------------ | ----------------------------- |
| [DateTimeOptions](#datetimeoptionsdeprecated) | Options for the **DateTimeOptions** object.|

**Example**
```ts
let formatter: intl.DateTimeFormat = new intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });
// Obtain the options of the DateTimeFormat object.
let options: intl.DateTimeOptions = formatter.resolvedOptions();
let dateStyle: string | undefined = options.dateStyle; // dateStyle = 'full'
let timeStyle: string | undefined = options.timeStyle; // timeStyle = 'medium'
```


## DateTimeOptions<sup>(deprecated)</sup>

> This API is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.DateTimeFormatOptions** or **Intl.ResolvedDateTimeFormatOptions** instead. For details, see [Intl.DateTimeFormat() constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat/DateTimeFormat) and [Intl.DateTimeFormat.prototype.resolvedOptions()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat/resolvedOptions).

Defines the options for a **DateTimeOptions** object. Since API version 9, the **DateTimeOptions** attribute is changed from mandatory to optional.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name             | Type     | Read-Only  | Optional  | Description                                      |
| --------------- | ------- | ---- | ---- |  ---------------------------------------- |
| locale          | string  | No   | Yes   |Valid locale ID, for example, **zh-Hans-CN**.<br>The default value is the current system locale.          |
| dateStyle       | string  | No   | Yes    |Date display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"medium",&nbsp;"full", or &nbsp;"auto".<br>For details about their display effects, see [Table 1](#appendix).|
| timeStyle       | string  | No   | Yes    |Time display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"medium",&nbsp;"full", or &nbsp;"auto".<br>For details about their display effects, see [Table 2](#appendix).|
| hourCycle       | string  | No   | Yes    |Hour cycle. The value can be:<br>"h11",&nbsp;"h12",&nbsp;"h23", or &nbsp;"h24".<br>For the display effects when **dateStyle** or **timeStyle** is not set, see [Table 5](#appendix).<br>For the display effects when **dateStyle** or **timeStyle** is not set, see [Table 6](#appendix).|
| timeZone        | string  | No   | Yes    |Time zone in use. The value is a valid IANA time zone ID.                     |
| numberingSystem | string  | No   | Yes    |Numbering system. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.|
| hour12          | boolean | No   | Yes    | Whether to use the 12-hour clock. The value **true** means to use the 12-hour clock, and the value **false** means the opposite.<br>If both **hour12** and **hourCycle** are set, **hourCycle** does not take effect.<br>If **hour12** and **hourCycle** are not set and the 24-hour clock is turned on, the default value of **hour12** is **false**.|
| weekday         | string  | No   | Yes    | Week display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"narrow", or &nbsp;"auto".<br>For details about their display effects, see [Table 4](#appendix).|
| era             | string  | No   | Yes    | Epoch display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"narrow", or &nbsp;"auto".<br>For details about their display effects, see [Table 9](#appendix).|
| year            | string  | No   | Yes    | Year display format. The value can be:<br>"numeric" or &nbsp;"2-digit".<br>For details about their display effects, see [Table 3](#appendix). |
| month           | string  | No   | Yes   | Month display format. The value can be:<br>"numeric",&nbsp;"2-digit",&nbsp;"long",&nbsp;"short",&nbsp;"narrow", or &nbsp;"auto".<br>For details about their display effects, see [Table 7](#appendix).|
| day             | string  | No   | Yes    | Day display format. The value can be:<br>"numeric" or &nbsp;"2-digit". |
| hour            | string  | No   | Yes    | Hour display format. The value can be:<br>"numeric" or &nbsp;"2-digit". |
| minute          | string  | No   | Yes    | Minute display format. The value can be:<br>"numeric" or &nbsp;"2-digit". |
| second          | string  | No   | Yes    | Second display format. The value can be:<br>"numeric" or &nbsp;"2-digit". |
| timeZoneName    | string  | No   | Yes    | Localized representation of a time zone name. The value can be:<br>"long",&nbsp;"short", or &nbsp;"auto".<br>For details about their display effects, see [Table 8](#appendix). |
| dayPeriod       | string  | No   | Yes    | Time period display format. The value can be:<br>"long",&nbsp;"short",&nbsp;"narrow", or &nbsp;"auto".<br>For details about their display effects, see [Table 10](#appendix).|
| localeMatcher   | string  | No   | Yes    | Locale matching algorithm. The value can be:<br>- **lookup**: exact match.<br>- "best fit": best match.|
| formatMatcher   | string  | No   | Yes    | Format matching algorithm. The value can be:<br>- **basic**: exact match.<br>- "best fit": best match.|

## NumberFormat

### constructor<sup>(deprecated)</sup>

constructor()

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.NumberFormat()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat/NumberFormat) instead.

Creates a **NumberFormat** object for the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
```ts
// Create a NumberFormat object using the current system locale ID.
let formatter: intl.NumberFormat = new intl.NumberFormat();
```


### constructor<sup>(deprecated)</sup>

constructor(locale: string | Array&lt;string&gt;, options?: NumberOptions)

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.NumberFormat()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat/NumberFormat) instead.

Creates a **NumberFormat** object for the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                              | Mandatory  | Description                          |
| -------------------- | -------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;    | Yes   | Locale ID or locale ID array. If the input is a locale ID array, the first valid locale ID is used.|
| options              | [NumberOptions](#numberoptionsdeprecated) | No   | Options for creating the **NumberFormat** object.              |

**Example**
```ts
// Create a NumberFormat object with locale ID being en-GB, style being decimal, and notation being scientific.
let formatter: intl.NumberFormat = new intl.NumberFormat('en-GB', { style: 'decimal', notation: 'scientific' });
```

### format<sup>(deprecated)</sup>

format(number: number): string

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.NumberFormat.format()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat/format) instead.

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
let formatter: intl.NumberFormat = new intl.NumberFormat(['en-GB', 'zh'], { style: 'decimal', notation: 'scientific' });
let formattedNumber: string = formatter.format(1223); // formattedNumber = 1.223E3
let options : intl.NumberOptions = {
  roundingPriority: "lessPrecision",
  maximumFractionDigits: 3,
  maximumSignificantDigits: 3
}
formatter = new intl.NumberFormat('en', options);
let result: string = formatter.format(1.23456); // result = 1.23
```

### formatRange<sup>(deprecated)</sup>

formatRange(startRange: number, endRange: number): string

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.NumberFormat.formatRange()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat/formatRange) instead.

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
let formatter: intl.NumberFormat = new intl.NumberFormat('en-US', { style: 'unit', unit: 'meter' });
let formattedRange: string = formatter.formatRange(0, 3); // formattedRange: 0–3 m
```


### resolvedOptions

resolvedOptions(): NumberOptions

Obtains the options for creating a **NumberFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                              | Description                         |
| -------------------------------- | --------------------------- |
| [NumberOptions](#numberoptionsdeprecated) | Options for creating the **NumberFormat** object.|


**Example**
```ts
let formatter: intl.NumberFormat = new intl.NumberFormat(['en-GB', 'zh'], { style: 'decimal', notation: 'scientific' });
// Obtain the options of the NumberFormat object.
let options: intl.NumberOptions = formatter.resolvedOptions();
let style: string | undefined = options.style; // style = 'decimal'
let notation: string | undefined = options.notation; // notation = 'scientific'
```

## NumberOptions<sup>(deprecated)</sup>

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.NumberFormat#options](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat/NumberFormat#options) instead.

Options for creating the **NumberFormat** object. Since API version 9, the **NumberOptions** attribute is changed from mandatory to optional.

**System capability**: SystemCapability.Global.I18n

| Name                      | Type     | Read-Only  | Optional  |  Description                                      |
| ------------------------ | ------- | ---- | ---- |  ---------------------------------------- |
| locale                   | string  | No   | Yes   | Valid locale ID, for example, **zh-Hans-CN**.<br>The default value is the current system locale.<br>**Atomic service API**: This API can be used in atomic services since API version 12.              |
| currency                 | string  | No   | Yes   | Currency unit. The value must comply with the [ISO-4217 standard](https://www.iso.org/iso-4217-currency-codes.html), for example, EUR, CNY, and USD.<br>From API version 12, a three-digit number is supported, for example, **978**, **156**, or **840**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.   |
| currencySign             | string  | No   | Yes   | Currency unit symbol. The value can be **standard** or **accounting**.<br>The default value is **standard**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| currencyDisplay          | string  | No   | Yes   | Currency display mode. The value can be **symbol**, **narrowSymbol**, **code**, or **name**.<br>The default value is **symbol**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| unit                     | string  | No   | Yes   | Unit name, for example, **meter**, **inch**, or **hectare**.<br>The combination units supported since API version 18 are as follows: beat-per-minute, body-weight-per-second, breath-per-minute, foot-per-hour, jump-rope-per-minute, meter-per-hour, milliliter-per-minute-per-kilogram, rotation-per-minute, step-per-minute, and stroke-per-minute.<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| unitDisplay              | string  | No   | Yes   | Display format of units. The value can be **long**, **short**, or **narrow**.<br>The default value is **short**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| unitUsage<sup>8+</sup>   | string  | No   | Yes   | Application scenario of units. The value can be any of the following: "default**, **area-land-agricult**, **area-land-commercl**, **area-land-residntl**, **length-person**, **length-person-small**, **length-rainfall**, **length-road**, **length-road-small**, **length-snowfall**, **length-vehicle**, **length-visiblty**, **length-visiblty-small**, **length-person-informal**, **length-person-small-informal**, **length-road-informal**, **speed-road-travel**, **speed-wind**, **temperature-person**, **temperature-weather**, **volume-vehicle-fuel**, **elapsed-time-second**, **size-file-byte**, or **size-shortfile-byte**.<br>The default value is **default**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| signDisplay              | string  | No   | Yes   | Number sign display format. The value can be:<br>- "auto": automatically determines whether to display the plus or minus sign.<br>- "never": do not display the plus or minus sign.<br>- "always": always displays the plus or minus sign.<br>- "exceptZero": displays the plus or minus sign for all values except 0.<br>Default value: **"auto"**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| compactDisplay           | string  | No   | Yes   | Compact display format. The value can be **long** or **short**.<br>The default value is **short**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
| notation                 | string  | No   | Yes   | Number notation. The value can be **standard**, **scientific**, **engineering**, or **compact**.<br>The default value is **standard**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| localeMatcher            | string  | No   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.<br>The default value is **best fit**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| style                    | string  | No   | Yes   | Number display format. The value can be **decimal**, **currency**, **percent**, or **unit**.<br>The default value is **decimal**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| numberingSystem          | string  | No   | Yes   | Numbering system. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.<br>The default value is the default numbering system of the locale.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| useGrouping              | boolean | No   | Yes   | Whether to enable grouping for display. The value **true** means to enable grouping for display, and the value **false** means the opposite.<br>The default value is **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                 |
| minimumIntegerDigits     | number  | No   | Yes   | Minimum number of digits allowed in the integer part of a number. The value ranges from **1** to **21**.<br>The default value is **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| minimumFractionDigits    | number  | No   | Yes   | Minimum number of digits in the fraction part of a number. The value ranges from **0** to **20**.<br>The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| maximumFractionDigits    | number  | No   | Yes   | Maximum number of digits in the fraction part of a number. The value ranges from **1** to **21**.<br>The default value is **3**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| minimumSignificantDigits | number  | No   | Yes   | Minimum number of the least significant digits. The value ranges from **1** to **21**.<br>The default value is **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| maximumSignificantDigits | number  | No   | Yes   | Maximum number of the least significant digits. The value ranges from **1** to **21**.<br>The default value is **21**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| roundingPriority<sup>18+</sup>   | string  | No   | Yes   | Rounding priority used when both the maximum number of fraction digits and the maximum number of valid digits are set. The value can be **auto**, **morePrecision**, or **lessPrecision**. The value **morePrecision** indicates that the maximum number of fraction digits is used. The value **lessPrecision** indicates that the maximum number of valid digits is used.<br>The default value is **auto**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.                 |
| roundingIncrement<sup>18+</sup>  | number  | No   | Yes   | Rounding increment. The value can be **1**, **2**, **5**, **10**, **20**, **25**, **50**, **100**, **200**, **250**, **500**, **1000**, **2000**, **2500**, or **5000**.<br>The default value is **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.                 |
| roundingMode<sup>18+</sup>       | string  | No   | Yes   | Rounding mode. The value can be:<br>- **ceil**: rounding up.<br>- **floor**: rounding down.<br>- **expand**: rounding away from 0.<br>- **trunc**: rounding toward 0.<br>- **halfCeil**: half-rounding up; that is, rounding up when the decimal number is greater than or equal to half of the increment, and rounding down otherwise.<br>- **halfFloor**: half-rounding down; that is, rounding up when the decimal number is greater than half of the increment, and rounding down otherwise.<br>- **halfExpand**: half-rounding away from 0; that is, rounding away from 0 when the decimal number is greater than or equal to half of the increment, and rounding toward 0 otherwise.<br>- **halfTrunc**: half-rounding toward 0; that is, rounding away from 0 when the decimal number is greater than half of the increment, and rounding toward 0 otherwise.<br>- "halfEven": half-rounding to the nearest even number; that is, rounding away from 0 when the decimal number is greater than half of the increment, rounding toward 0 when the decimal number is less than half of the increment, and rounding to the nearest even number when the decimal number is exactly half of the increment.<br>The default value is **halfExpand**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

>  **NOTE**
>
>  - For details about the meaning or display effect of different values, see [Number and Unit of Measurement Formatting](../../internationalization/i18n-numbers-weights-measures.md).

## Collator<sup>8+</sup>

### constructor<sup>(deprecated)</sup>

constructor()

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.Collator() constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator) instead.

Creates a **Collator** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  // Create a Collator object using the current system locale ID.
  let collator = new intl.Collator();
  ```


### constructor<sup>(deprecated)</sup>

constructor(locale: string | Array&lt;string&gt;, options?: CollatorOptions)

> This method is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator) instead.

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


### compare<sup>(deprecated)</sup>

compare(first: string, second: string): number

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use (https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/compare) instead.

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


### resolvedOptions<sup>(deprecated)</sup>

resolvedOptions(): CollatorOptions

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/resolvedOptions) instead.

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

| Name               | Type     | Read-Only  | Optional  | Description                                      |
| ----------------- | ------- | ---- | ---- | ---------------------------------------- |
| localeMatcher<sup>(deprecated)</sup>     | string  | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.CollatorOptions.localeMatcher** instead. For details, see [Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator#options).<br>Locale matching algorithm. The options are as follows:<br>**lookup**: fuzzy match.<br>**best fit**: exact match.<br>The default value is **best fit**.|
| usage<sup>(deprecated)</sup>             | string  | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.CollatorOptions.usage** instead. For details, see [Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator#options).<br>Purpose of comparison. The options are as follows:<br>- **sort**: sorting.<br>- **search**: search for matched strings.<br>The default value is **sort**.       |
| sensitivity<sup>(deprecated)</sup>       | string  | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.CollatorOptions.sensitivity** instead. For details, see [Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator#options).<br>Differences in the strings that lead to non-zero return values. The options are as follows:<br>- **base**: Different letters are considered unequal, for example, 'a' ≠ 'b', 'a' = 'á', 'a' = 'A'.<br>- **accent**: Different letters or same letters with different pronunciations are considered unequal, for example, 'a' ≠ 'b', 'a' ≠ 'á', 'a' = 'A'.<br>- **case**: Different letters or same letters with different cases are considered unequal, for example, 'a' ≠ 'b', 'a' = 'á', 'a' ≠ 'A'.<br>- **variant**: Different letters, pronunciations, other distinguishing marks, or cases are all considered unequal, for example, 'a' ≠ 'b', 'a' ≠ 'á', 'a' ≠ 'A'.<br>The default value is **variant**.       |
| ignorePunctuation<sup>(deprecated)</sup> | boolean | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.CollatorOptions.ignorePunctuation** instead. For details, see [Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator#options).<br>Whether to ignore punctuation. The value **true** means to ignore punctuation, and the value **false** means the opposite.<br>The default value is **false**.       |
| collation<sup>(deprecated)</sup>         | string  | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.CollatorOptions.collation** instead. For details, see [Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator#options).<br>Collation rules for the locale. The value can be:<br>**big5han**: Pinyin sorting for Latin letters.<br>**compat**: compatibility sorting, only for Arabic.<br>**dict**: dictionary-style sorting, only for Singhalese.<br>**direct**: binary code point sorting.<br>**ducet**: sorting according to the Unicode collation element table.<br>**eor**: sorting according to the European collation rules.<br>**gb2312**: Pinyin sorting, only for Chinese.<br>**phonebk**: phone book-style sorting.<br>**phonetic**: phonetic sorting.<br>**pinyin**: Pinyin sorting.<br>**reformed**: reformed sorting, only for Swedish.<br>**searchjl**: special sorting for Korean initial consonant search.<br>**stroke**: stroke sorting for Chinese.<br>**trad**: traditional-style sorting, for example, Spanish.<br>unihan: radical-stroke sorting for Han characters, only for Chinese, Japanese, and Korean.<br>**zhuyin**: Zhuyin sorting, only for Chinese.<br>The default value is **default**.|
| numeric<sup>(deprecated)</sup>           | boolean | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.CollatorOptions.numeric** instead. For details, see [Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator#options).<br>Whether numeric sorting is used. The options are as follows:<br>- **true**: Numeric sorting is used. For example, '1' &lt; '2' &lt; '10' &lt; '11'.<br>- **false**: Numeric sorting is not used. For example, '1' &lt; '10' &lt; '11' &lt; '2'.<br>The default value is **false**.         |
| caseFirst<sup>(deprecated)</sup>         | string  | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.CollatorOptions.caseFirst** instead. For details, see [Intl.Collator](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Collator/Collator#options).<br>Whether case is taken into account for the locale's collation rules. The value can be:<br>**upper**: Uppercase letters come first.<br>**lower**: Lowercase letters come first.<br>- **false**: The default collation rules of the locale are used.<br>The default value is **false**.|


## PluralRules<sup>8+</sup>

### constructor<sup>(deprecated)</sup>

constructor()

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/PluralRules) instead.

Creates a **PluralRules** object to obtain the singular-plural type of numbers.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  // Create a PluralRules object using the current system locale ID.
  let pluralRules = new intl.PluralRules();
  ```


### constructor<sup>(deprecated)</sup>

constructor(locale: string | Array&lt;string&gt;, options?: PluralRulesOptions)

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/PluralRules) instead.

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
let pluralRules: intl.PluralRules = new intl.PluralRules('zh-CN', { localeMatcher: 'lookup', type: 'cardinal' });
```

### select<sup>(deprecated)</sup>

select(n: number): string

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/select) instead.

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

| Name                      | Type    | Read-Only  | Optional  | Description                                      |
| ------------------------ | ------ | ---- | ---- | ---------------------------------------- |
| localeMatcher<sup>(deprecated)</sup>            | string | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.PluralRulesOptions.localeMatcher** instead. For details, see [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/PluralRules#options).<br>Locale matching algorithm. The value can be **lookup** or **best fit**.<br>The default value is **best fit**.|
| type<sup>(deprecated)</sup>                     | string | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.PluralRulesOptions.type** instead. For details, see [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/PluralRules#options).<br>Collation type. The value can be **cardinal** or **ordinal**.<br>The default value is **cardinal**.<br>The value **cardinal** indicates a cardinal number and the value **ordinal** indicates an ordinal number. |
| minimumIntegerDigits<sup>(deprecated)</sup>     | number | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.PluralRulesOptions.minimumIntegerDigits** instead. For details, see [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/PluralRules#options).<br>Minimum number of digits allowed in the integer part of a number. The value ranges from **1** to **21**.<br>The default value is **1**.                 |
| minimumFractionDigits<sup>(deprecated)</sup>    | number | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.PluralRulesOptions.minimumFractionDigits** instead. For details, see [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/PluralRules#options).<br>Minimum number of digits in the fraction part of a number. The value ranges from **0** to **20**.<br>The default value is **0**.                 |
| maximumFractionDigits<sup>(deprecated)</sup>    | number | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.PluralRulesOptions.maximumFractionDigits** instead. For details, see [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/PluralRules#options).<br>Maximum number of digits in the fraction part of a number. The value ranges from **1** to **21**.<br>The default value is **3**.                 |
| minimumSignificantDigits<sup>(deprecated)</sup> | number | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.PluralRulesOptions.maximumFractionDigits** instead. For details, see [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/PluralRules#options).<br>Minimum number of the least significant digits. The value ranges from **1** to **21**.<br>The default value is **1**.                 |
| maximumSignificantDigits<sup>(deprecated)</sup> | number | No   | Yes   | This parameter is supported since API version 8 and is deprecated since API version 20. You are advised to use **Intl.PluralRulesOptions.maximumSignificantDigits** instead. For details, see [Intl.PluralRules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/PluralRules/PluralRules#options).<br>Maximum number of the least significant digits. The value ranges from **1** to **21**.<br>The default value is **21**.               |


## RelativeTimeFormat<sup>(deprecated)</sup>

### constructor<sup>(deprecated)</sup>

constructor()

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.RelativeTimeFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/RelativeTimeFormat) instead.

Creates a **RelativeTimeFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Example**
```ts
// Create a RelativeTimeFormat object using the current system locale ID.
let formatter: intl.RelativeTimeFormat = new intl.RelativeTimeFormat();
```


### constructor<sup>(deprecated)</sup>

constructor(locale: string | Array&lt;string&gt;, options?: RelativeTimeFormatInputOptions)

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.RelativeTimeFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/RelativeTimeFormat) instead.

Creates a **RelativeTimeFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                          |
| -------------------- | ---------------------------------------- | ---- | ---------------------------- |
| locale               | string \| Array&lt;string&gt;            | Yes   | Locale ID or locale ID array. If the input is a locale ID array, the first valid locale ID is used.|
| options              | [RelativeTimeFormatInputOptions](#relativetimeformatinputoptionsdeprecated) | No   | Options for creating a **RelativeTimeFormat** object.    |

**Example**
```ts
// Create a RelativeTimeFormat object with the locale ID being zh-CN, localeMatcher being lookup, and style being long.
let formatter: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('zh-CN', {
  localeMatcher: 'lookup',
  numeric: 'always',
  style: 'long'
});
```


### format<sup>(deprecated)</sup>

format(value: number, unit: string): string

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.RelativeTimeFormat.format()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/RelativeTimeFormat/format) instead.

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
let formatter: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('zh-CN');
// Obtain the localized representation (in unit of quarter) of number 3 in locale zh-CN.
let formatResult: string = formatter.format(3, 'quarter'); // formatResult = '3 quarters later'
```


### formatToParts<sup>(deprecated)</sup>

formatToParts(value: number, unit: string): Array&lt;object&gt;

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.RelativeTimeFormat.formatToParts()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/RelativeTimeFormat/formatToParts) instead.

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
let formatter: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en', { numeric: 'auto' });
let parts: Array<object> = formatter.formatToParts(10, 'seconds'); // parts = [ {type: 'literal', value: 'in'}, {type: 'integer', value: 10, unit: 'second'}, {type: 'literal', value: 'seconds'} ]
```


### resolvedOptions<sup>(deprecated)</sup>

resolvedOptions(): RelativeTimeFormatResolvedOptions

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.RelativeTimeFormat.resolvedOptions()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/RelativeTimeFormat/resolvedOptions) instead.

Defines the formatting options for a **RelativeTimeFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                                      | Description                               |
| ---------------------------------------- | --------------------------------- |
| [RelativeTimeFormatResolvedOptions](#relativetimeformatresolvedoptionsdeprecated) | Options for the **RelativeTimeFormat** object.|

**Example**
```ts
// Create a RelativeTimeFormat object with the locale ID being en-GB.
let formatter: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en-GB', { style: 'short' });
// Obtain the options of the RelativeTimeFormat object.
let options: intl.RelativeTimeFormatResolvedOptions = formatter.resolvedOptions();
let style: string = options.style; // style = 'short'
```


## RelativeTimeFormatInputOptions<sup>(deprecated)</sup>

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.RelativeTimeFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/RelativeTimeFormat/RelativeTimeFormat#options) instead.

Defines the configuration options for a **RelativeTimeFormat** object.

Since API version 9, the attributes in **RelativeTimeFormatInputOptions** are optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name           | Type    | Read-Only  | Optional  |Description                                      |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| localeMatcher | string | No   | Yes   | Locale matching algorithm. The value can be **lookup** or **best fit**.<br>The default value is **best fit**.|
| numeric       | string | No   | Yes   | Format of the output result. It determines whether numeric values are used to represent relative dates or times in the formatting result. The value can be **always** or **auto**.<br>The default value is **always**.     |
| style         | string | No   | Yes   | Length of an internationalized message. The value can be **long**, **short**, or **narrow**.<br>The default value is **long**.|

> **NOTE**
>
> For details about the display effects of **numeric** and **style**, see [Date and Time Formatting](../../internationalization/i18n-time-date.md#relative-time-formatting).

## RelativeTimeFormatResolvedOptions<sup>(deprecated)</sup>

> This API is supported since API version 8 and deprecated since API version 20. You are advised to use [Intl.RelativeTimeFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/RelativeTimeFormat/resolvedOptions#return_value) instead.

Represents the formatting options for the **RelativeTimeFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name             | Type    | Read-Only | Optional  |Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| locale          | string | No   | No   | Locale ID, including the language, script, and region.            |
| numeric         | string | No   | No   | Format of the output result. It determines whether numeric values are used to represent relative dates or times in the formatting result. The value can be **always** or **auto**.     |
| style           | string | No   | No   | Length of an internationalized message. The value can be **long**, **short**, or **narrow**.|
| numberingSystem | string | No   | No   | Numbering system. The value can be:<br>**adlm**, **ahom**, **arab**, **arabext**, **bali**, **beng**, **bhks**, **brah**, **cakm**, **cham**, **deva**, **diak**, **fullwide**, **gong**, **gonm**, **gujr**, **guru**, **hanidec**, **hmng**, **hmnp**, **java**, **kali**, **khmr**, **knda**, **lana**, **lanatham**, **laoo**, **latn**, **lepc**, **limb**, **mathbold**, **mathdbl**, **mathmono**, **mathsanb**, **mathsans**, **mlym**, **modi**, **mong**, **mroo**, **mtei**, **mymr**, **mymrshan**, **mymrtlng**, **newa**, **nkoo**, **olck**, **orya**, **osma**, **rohg**, **saur**, **segment**, **shrd**, **sind**, **sinh**, **sora**, **sund**, **takr**, **talu**, **tamldec**, **telu**, **thai**, **tibt**, **tirh**, **vaii**, **wara**, or **wcho**.|

> **NOTE**
>
> For details about the display effects of **numeric** and **style**, see [Date and Time Formatting](../../internationalization/i18n-time-date.md#relative-time-formatting).

## Appendix

**Date and Time Formatting Options**

The following tables use 13:04:00 and 00:25:00 on September 17, 2021 and locales **zh-CN** and **en** as examples to illustrate the values and display results of [DateTimeOptions](#datetimeoptionsdeprecated).

**Table 1** Date display format (dateStyle)

| Value  | Description                                   | 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| ------ | --------------------------------------- | ------------------------------------------  | ---------------------------------------- |
| full   | Complete date display, including the year, month, day, and week.| 2021年9月17日星期五                          | Friday, September 17, 2021               |
| long   | Long date display, including the year, month, and day.    | 2021年9月17日                                | September 17, 2021                       |
| short  | Short date display, including the year, month, and day.    | 2021/9/17                                   | 9/17/21                                  |
| medium | Medium date display, including the year, month, and day.  | 2021年9月17日                                | Sep 17, 2021                             |

**Table 2** Time display format (timeStyle)

| Value  | Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| ------ | ------------- | -------- | -------- |
| full   | Complete time display, including the time zone and time accurate to seconds.| 中国标准时间 13:04:00 | 13:04:00 China Standard Time |
| long   | Long time display, including the time zone expressed in the format of GMT + time zone offset and time accurate to seconds.| GMT+8 13:04:00 | 13:04:00 GMT+8 |
| short  | Short time display, including hour and minute.| 13:04 | 13:04 |
| medium | Medium time display, including hour, minute, and second.| 13:04:00 | 13:04:00 |

**Table 3** Year display format (year)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | --------- | -------- | -------- |
| numeric | Complete year| 2021年 | 2021 |
| 2-digit | 2-digit year display| 21年 | 21 |

**Table 4** Weekday display format (weekday)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | ------- | -------- | -------- |
| long | Long weekday display| 星期五 | Friday |
| short | Short weekday display.| 周五 | Fri |
| narrow | Narrow weekday display.| 五 | F |

**Table 5** Hour cycle format (hourCycle)

| Value| Description           | 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 00:25:00 for Locale zh-CN|
| --- | --------------- | -------------------------------------------- | ------------------------------------------- |
| h11 | Use of 0 to 11 to indicate the hour| 下午1:04                                     |  上午0:25                                    |
| h12 | Use of 1 to 12 to indicate the hour| 下午1:04                                     |  上午12:25                                   |
| h23 | Use of 0 to 23 to indicate the hour| 13:04                                        | 00:25                                       |
| h24 | Use of 1 to 24 to indicate the hour| 13:04                                        | 24:25                                       |

> **NOTE**
>
> The preceding table shows the display effect for different values of **hourCycle** when **dateStyle** or **timeStyle** is not set.


**Table 6** Hour cycle format (hourCycle)

| Value| Description           | 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 00:25:00 for Locale zh-CN|
| --- | --------------- | -------------------------------------------- | ------------------------------------------- |
| h11 | Use of 1 to 24 to indicate the hour| 下午13:04                                    |  上午24:25                                   |
| h12 | Use of 1 to 12 to indicate the hour| 下午1:04                                     |  上午12:25                                   |
| h23 | Use of 0 to 11 to indicate the hour| 1:04                                         |  0:25                                       |
| h24 | Use of 0 to 23 to indicate the hour| 13:04                                        |  0:25                                       |

> **NOTE**
>
> The preceding table shows the display effect for different values of **hourCycle** when **dateStyle** or **timeStyle** is set.

**Table 7** Month format (month)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | --------- | -------- | -------- |
| numeric | Display of the month as a number| 9月 | 9 |
| 2-digit | Display of the month in two digits| 09月 | 09 |
| long | Long month display| 九月 | September |
| short | Short month display| 9月 | Sep |
| narrow | Narrow month display| 9 | S |

**Table 8** Localized representation of time zone names (timeZoneName)

| Value | Description               | 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| ----- | ------------------ | -------------------------------------------- | ---------------------------------------- |
| long  | Long time zone name| 中国标准时间                                  | China Standard Time                      |
| short | Short time zone name| GMT+8                                        | GMT+8                                    |

**Table 9** Era display format (era)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | ------ | -------- | -------- |
| long | Long epoch display| 公元 | Anno Domini |
| short | Short epoch display| 公元 | AD |
| narrow | Narrow epoch display| 公元 | A |

**Table 10** Time period format (dayPeriod)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | ------ | -------- | -------- |
| long | Long time period display| 下午 | in the afternoon |
| short | Short time period display| 下午 | in the afternoon |
| narrow | Narrow time period display| 下午 | in the afternoon |

<!--no_check-->