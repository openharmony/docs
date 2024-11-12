# @ohos.i18n (Internationalization)

This module provides system-related or enhanced i18n capabilities, such as locale management, phone number formatting, and calendar, through supplementary i18n APIs that are not defined in ECMA 402. The [intl](js-apis-intl.md) module provides basic i18n capabilities through the standard i18n APIs defined in ECMA 402. It works with the **i18n** module to provide a complete suite of i18n capabilities.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs of this module conform to the [Common Locale Data Repository (CLDR)](https://cldr.unicode.org) internationalization database. The processing result may change with CLDR evolution. API version 12 corresponds to [CLDR 42](https://cldr.unicode.org/index/downloads/cldr-42). For details about data changes, visit the official website.
>
>  - Since API version 11, some APIs of this module are supported in ArkTS widgets.


## Modules to Import

```ts
import { i18n } from '@kit.LocalizationKit';
```

## System<sup>9+</sup>

### getDisplayCountry<sup>9+</sup>

static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

Obtains the localized display of the text for the specified country.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | Yes   | Valid country code.           |
| locale       | string  | Yes   | Valid locale ID for the specified country.    |
| sentenceCase | boolean | No   | Whether the first letter of the text is capitalized. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized display of the text.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

> **Description**
>
> The error message of 890001 is subject to the actual error.

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
      let displayCountry: string = i18n.System.getDisplayCountry("zh-CN", "en-GB"); // displayCountry = "China"
  } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call System.getDisplayCountry failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getDisplayLanguage<sup>9+</sup>

static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

Obtains the localized display of the text for the specified language. For example, if **getDisplayLanguage ("de," "zh-Hans-CN")** is called to display German in Chinese, the output is in German.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| language     | string  | Yes   | Valid language ID.           |
| locale       | string  | Yes   | Valid locale ID for the specified language.    |
| sentenceCase | boolean | No   | Whether the first letter of the text is capitalized. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized display of the text for the specified language.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let displayLanguage: string = i18n.System.getDisplayLanguage("zh", "en-GB"); // Display Chinese in English.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getDisplayLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLanguages<sup>9+</sup>

static getSystemLanguages(): Array&lt;string&gt;

Obtains the list of system languages.

Since API version 11, this API is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Array&lt;string&gt; | List of the IDs of system languages.|

**Example**
  ```ts
  let systemLanguages: Array<string> = i18n.System.getSystemLanguages(); // [ "ug", "bo", "zh-Hant", "en-Latn-US", "zh-Hans" ]
  ```

### getSystemCountries<sup>9+</sup>

static getSystemCountries(language: string): Array&lt;string&gt;

Obtains the list of countries and regions supported for the specified language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description   |
| -------- | ------ | ---- | ----- |
| language | string | Yes   | Valid language ID.|

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Array&lt;string&gt; | List of countries or regions supported for the specified language.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

> **Description**
>
> The error message of 890001 is subject to the actual error.

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let systemCountries: Array<string> = i18n.System.getSystemCountries('zh'); // systemCountries = [ "ZW", "YT", "YE", ..., "ER", "CN", "DE" ]
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemCountries failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### isSuggested<sup>9+</sup>

static isSuggested(language: string, region?: string): boolean

Checks whether the system language matches the specified region.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description           |
| -------- | ------ | ---- | ------------- |
| language | string | Yes   | Valid language ID, for example, **zh**.|
| region   | string | No   | Valid region ID, for example, **CN**.<br>The default value is the country or region where the SIM card is used. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the language matches the specified country or region,<br>and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |


> **Description**
>
> The error message of 890001 is subject to the actual error.

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let res: boolean = i18n.System.isSuggested('zh', 'CN');  // res = true
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.isSuggested failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLanguage<sup>9+</sup>

static getSystemLanguage(): string

Obtains the system language.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System language ID.|

**Example**
  ```ts
  let systemLanguage: string = i18n.System.getSystemLanguage();  // systemLanguage indicates the current system language.
  ```

### getSystemRegion<sup>9+</sup>

static getSystemRegion(): string

Obtains the system region.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System region ID.|

**Example**
  ```ts
  let systemRegion: string = i18n.System.getSystemRegion(); // Obtain the current system region.
  ```

### getSystemLocale<sup>9+</sup>

static getSystemLocale(): string

Obtains the system locale.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System locale ID.|

**Example**
  ```ts
  let systemLocale: string = i18n.System.getSystemLocale();  // Obtain the current system locale.
  ```

### is24HourClock<sup>9+</sup>

static is24HourClock(): boolean

Checks whether the 24-hour clock is used.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the 24-hour clock is used, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let is24HourClock: boolean = i18n.System.is24HourClock();  // Check whether the 24-hour clock is enabled.
  ```


### getPreferredLanguageList<sup>9+</sup>

static getPreferredLanguageList(): Array&lt;string&gt;

Obtains the list of preferred languages.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description       |
| ------------------- | --------- |
| Array&lt;string&gt; | List of preferred languages.|

**Example**
  ```ts
  let preferredLanguageList: Array<string> = i18n.System.getPreferredLanguageList(); // Obtain the current preferred language list.
  ```

### getFirstPreferredLanguage<sup>9+</sup>

static getFirstPreferredLanguage(): string

Obtains the first language in the preferred language list.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description            |
| ------ | -------------- |
| string | First language in the preferred language list.|

**Example**
  ```ts
  let firstPreferredLanguage: string = i18n.System.getFirstPreferredLanguage();  // Obtain the first language in the preferred language list.
  ```

### setAppPreferredLanguage<sup>11+</sup>

static setAppPreferredLanguage(language: string): void

Sets the preferred language of the application.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description   |
| -------- | ------ | ---- | ----- |
| language | string | Yes   | Valid language ID.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setAppPreferredLanguage('zh'); // Set the preferred language of the application to zh.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getAppPreferredLanguage<sup>9+</sup>

static getAppPreferredLanguage(): string

Obtains the preferred language of an application.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Preferred language of the application.|

**Example**
  ```ts
  let appPreferredLanguage: string = i18n.System.getAppPreferredLanguage(); // Obtain the preferred language of the application.
  ```


### getUsingLocalDigit<sup>9+</sup>

static getUsingLocalDigit(): boolean

Checks whether use of local digits is enabled.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the local digit switch is enabled, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let status: boolean = i18n.System.getUsingLocalDigit();  // Check whether the local digit switch is enabled.
  ```


## i18n.isRTL

isRTL(locale: string): boolean

Checks whether a locale uses a right-to-left (RTL) language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| locale | string | Yes   | Locale ID.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the locale uses an RTL language, and the value **false** indicates the opposite.|

**Example**
  ```ts
  i18n.isRTL("zh-CN");// Since Chinese is not written from right to left, false is returned.
  i18n.isRTL("ar-EG");// Since Arabic is written from right to left, true is returned.
  ```

## i18n.getCalendar<sup>8+</sup>

getCalendar(locale: string, type? : string): Calendar

Obtains a **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | Valid locale ID, for example, **zh-Hans-CN**.                |
| type   | string | No   | Valid calendar type. The value can be **buddhist**, **chinese**, **coptic**, **ethiopic**, **hebrew**, **gregory**, **indian**, **islamic_civil**, **islamic_tbla**, **islamic_umalqura**, **japanese**, or **persian**.<br>The default value is the default calendar type of the locale. For details, see [Calendar Setting](../../internationalization/i18n-calendar.md).|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [Calendar](#calendar8) | **Calendar** object.|

**Example**
  ```ts
  i18n.getCalendar("zh-Hans", "chinese"); // Obtain the Calendar object for the Chinese lunar calendar.
  ```

## EntityRecognizer<sup>11+</sup>

### constructor<sup>11+</sup>

constructor(locale?: string)

Creates an **entityRecognizer** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| locale | string | No   | Valid locale ID, for example, **zh-Hans-CN**.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  let entityRecognizer: i18n.EntityRecognizer = new i18n.EntityRecognizer("zh-CN");
  ```

### findEntityInfo<sup>11+</sup>

findEntityInfo(text: string): Array&lt;EntityInfoItem&gt;

Recognizes entities in text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| text | string | Yes   | Text to be recognized.|

**Return value**

| Type  | Description               |
| ---- | ----------------- |
| Array&lt;[EntityInfoItem](#entityinfoitem11)&gt; | List of entities in the text.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**
  ```ts
  let entityRecognizer: i18n.EntityRecognizer = new i18n.EntityRecognizer("zh-CN");
  let text1: string = " If you have any questions, call us by phone 12345678";
  let result1: Array<i18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text1); // result1[0].type = "phone_number", result1[0].begin = 8, result1[0].end = 19
  let text2: string = "Let's have dinner on December 1, 2023."
  let result2: Array<i18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text2); // result2[0].type = "date", result2[0].begin = 2, result2[0].end = 12
  ```

## EntityInfoItem<sup>11+</sup>

Defines a list of entities.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name | Type  | Readable  | Writable  | Description               |
| ---- | ---- | ---- | ---- | ----------------- |
| type | string | Yes   | Yes   | Entity type. Only phone number and date are supported.|
| begin | number | Yes   | Yes   | Start position of an entity.|
| end | number | Yes   | Yes   | End position of an entity.|

## Calendar<sup>8+</sup>

### setTime<sup>8+</sup>

setTime(date: Date): void

Sets the date and time for a **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| date | Date | Yes   | Date and time.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("en-US", "gregory");
  let date: Date = new Date(2021, 10, 7, 8, 0, 0, 0);
  calendar.setTime(date);
  ```


### setTime<sup>8+</sup>

setTime(time: number): void

Sets the date and time for a **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| time | number | Yes   | Number of milliseconds that have elapsed since the Unix epoch.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("en-US", "gregory");
  calendar.setTime(10540800000);
  ```

### set<sup>8+</sup>

set(year: number, month: number, date:number, hour?: number, minute?: number, second?: number): void

Sets the year, month, day, hour, minute, and second for this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| year   | number | Yes   | Year to set. |
| month  | number | Yes   | Month to set. |
| date   | number | Yes   | Day to set. |
| hour   | number | No   | Hour to set. The default value is the system hour.|
| minute | number | No   | Minute to set. The default value is the system minute.|
| second | number | No   | Second to set. The default value is the system second.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.11.1 08:00:00
  ```

### setTimeZone<sup>8+</sup>

setTimeZone(timezone: string): void

Sets the time zone of this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description                       |
| -------- | ------ | ---- | ------------------------- |
| timezone | string | Yes   | Valid time zone ID, for example, Asia/Shanghai.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  ```


### getTimeZone<sup>8+</sup>

getTimeZone(): string

Obtains the time zone of this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Time zone ID.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  let timezone: string = calendar.getTimeZone(); // timezone = "Asia/Shanghai"
  ```


### getFirstDayOfWeek<sup>8+</sup>

getFirstDayOfWeek(): number

Obtains the start day of a week for a **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                   |
| ------ | --------------------- |
| number | Start day of a week. The value **1** indicates Sunday, and the value **7** indicates Saturday.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("en-US", "gregory");
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1
  ```


### setFirstDayOfWeek<sup>8+</sup>

setFirstDayOfWeek(value: number): void

Sets the start day of a week for a **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                   |
| ----- | ------ | ---- | --------------------- |
| value | number | Yes   | Start day of a week. The value **1** indicates Sunday, and the value **7** indicates Saturday.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setFirstDayOfWeek(3);
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 3
  ```

### getMinimalDaysInFirstWeek<sup>8+</sup>

getMinimalDaysInFirstWeek(): number

Obtains the minimum number of days in the first week of a year.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description          |
| ------ | ------------ |
| number | Minimum number of days in the first week of a year.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 1
  ```


### setMinimalDaysInFirstWeek<sup>8+</sup>

setMinimalDaysInFirstWeek(value: number): void

Sets the minimum number of days in the first week of a year.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description          |
| ----- | ------ | ---- | ------------ |
| value | number | Yes   | Minimum number of days in the first week of a year.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setMinimalDaysInFirstWeek(3);
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 3
  ```


### get<sup>8+</sup>

get(field: string): number

Obtains the value of the associated field in a **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| field | string | Yes   | Associated field in a **Calendar** object. The following table lists the supported field values.|


| Field  | Description                                      |
| ----- | ---------------------------------------- |
| era | Era, for example, AD or BC.|
| year | Year.|
| month | Month.|
| date | Date.|
| hour | Wall-clock hour.|
| hour_of_day | Hour of day.|
| minute | Minute.|
| second | Second.|
| millisecond | Millisecond.|
| week_of_year | Week of year. Note that the algorithm for calculating the first week of a year varies according to regions. For example, the first seven days in a year are the first week.|
| year_woy | Year used with the week of year field. |
| week_of_month | Week of month.|
| day_of_week_in_month | Day of week in month.|
| day_of_year | Day of year.|
| day_of_week | Day of week.|
| milliseconds_in_day | Milliseconds in day.|
| zone_offset | Fixed time zone offset in milliseconds (excluding DST).|
| dst_offset | DST offset in milliseconds.|
| dow_local | Localized day of week.|
| extended_year | Extended year, which can be a negative number.|
| julian_day | Julian day.|
| is_leap_month | Whether a month is a leap month.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Value of the specified field. For example, if the year in the internal date of this **Calendar** object is **1990**, the **get("year")** function will return **1990**.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.11.1 08:00:00
  let hourOfDay: number = calendar.get("hour_of_day"); // hourOfDay = 8
  ```


### getDisplayName<sup>8+</sup>

getDisplayName(locale: string): string

Obtains the displayed name of the **Calendar** object for the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | Locale ID.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Displayed name of the **Calendar** object for the specified locale. For example, **buddhist** is displayed as **Buddhist Calendar** if the locale is **en-US**.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("en-US", "buddhist");
  let calendarName: string = calendar.getDisplayName("zh"); // calendarName = "Buddhist Calendar"
  ```


### isWeekend<sup>8+</sup>

isWeekend(date?: Date): boolean

Checks whether a given date is a weekend in the calendar.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | No   | Specified date.<br>The default value is the system date. If this parameter is left empty, the system checks whether the current date is a weekend.|

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| boolean | The value **true** indicates that the specified date is a weekend, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.12.11 08:00:00
  calendar.isWeekend(); // true
  let date: Date = new Date(2011, 11, 6, 9, 0, 0);
  calendar.isWeekend(date); // false
  ```


### add<sup>11+</sup>

add(field: string, amount: number): void

Adds or subtracts some fields in a **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| field | string | Yes   | Specified field in the **Calendar** object. The value can be any of the following: **year**, **month**, **week_of_year**, **week_of_month**, **date**, **day_of_year**, **day_of_week**, **day_of_week_in_month**, **hour**, **hour_of_day**, **minute**, **second**, **millisecond**.<br>For details about the values, see [get](#get8).|
| amount | number | Yes   | Addition or subtraction amount.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
    calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.12.11 08:00:00
    calendar.add("year", 8); // 2021 + 8
    let year: number = calendar.get("year"); // year = 2029
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call Calendar.add failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getTimeInMillis<sup>11+</sup>

getTimeInMillis(): number

Obtains number of milliseconds that have elapsed since the Unix epoch in the current **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| number | Number of milliseconds that have elapsed since the Unix epoch.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
  calendar.setTime(5000);
  let millisecond: number = calendar.getTimeInMillis(); // millisecond = 5000
  ```


### compareDays<sup>11+</sup>

compareDays(date: Date): number

Compares the **Calendar** object and the specified date for the difference in the number of days.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | Yes   | Specified date.|

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| number | Difference in the number of days between the calendar date and the specified date. A positive number indicates that the calendar date is earlier, and a negative number indicates the opposite.<br>The value is accurate to milliseconds. If the value is less than one day, it is considered as one day.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let calendar: i18n.Calendar = i18n.getCalendar("zh-Hans");
    calendar.setTime(5000);
    let date: Date = new Date(6000);
    let diff: number = calendar.compareDays(date); // diff = 1
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call Calendar.compareDays failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## PhoneNumberFormat<sup>8+</sup>


### constructor<sup>8+</sup>

constructor(country: string, options?: PhoneNumberFormatOptions)

Creates a **PhoneNumberFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type                                      | Mandatory  | Description              |
| ------- | ---------------------------------------- | ---- | ---------------- |
| country | string                                   | Yes   | Country or region to which the phone number to be formatted belongs.|
| options | [PhoneNumberFormatOptions](#phonenumberformatoptions8) | No   | Options for initializing the **PhoneNumberFormat** object. The default value is **NATIONAL**. |

**Example**
  ```ts
  let option: i18n.PhoneNumberFormatOptions = {type: "E164"};
  let phoneNumberFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN", option);
  ```

### isValidNumber<sup>8+</sup>

isValidNumber(number: string): boolean

Checks whether the format of the specified phone number is valid.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description       |
| ------ | ------ | ---- | --------- |
| number | string | Yes   | Phone number to be checked.|

**Return value**

| Type     | Description                                   |
| ------- | ------------------------------------- |
| boolean | The value **true** indicates that the phone number format is valid, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let phonenumberfmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN");
  let isValidNumber: boolean = phonenumberfmt.isValidNumber("158****2312"); // isValidNumber = true
  ```


### format<sup>8+</sup>

format(number: string): string

Formats a phone number.

> **Description**
> Formatting dialed phone numbers is supported since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description        |
| ------ | ------ | ---- | ---------- |
| number | string | Yes   | Phone number to be formatted.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Formatted phone number.|

**Example**
  ```ts
  let phonenumberfmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN");
  let formattedPhoneNumber: string = phonenumberfmt.format("158****2312"); // formattedPhoneNumber = "158 **** 2312"

  // Format the dialed phone number.
  let option: i18n.PhoneNumberFormatOptions = {type: "TYPING"};
  let phoneNumberFmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN", option);
  let phoneNumber : string = "130493";
  let formatResult : string = "";
  for (let i = 0; i < phoneNumber.length; i++) {
    formatResult += phoneNumber.charAt(i);
    formatResult = phoneNumberFmt.format(formatResult);
  }
  console.log(formatResult); // formatResult: 130 493
  ```


### getLocationName<sup>9+</sup>

getLocationName(number: string, locale: string): string

Obtains the home location of a phone number.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description  |
| ------ | ------ | ---- | ---- |
| number | string | Yes   | Phone number. To obtain the home location of a number in other countries/regions, you need to prefix the number with **00** and the country code.|
| locale | string | Yes   | Valid locale ID.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Home location of the phone number.|

**Example**
  ```ts
  let phonenumberfmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat("CN");
  let locationName: string = phonenumberfmt.getLocationName("158****2345", "zh-CN"); // locationName = "Zhanjiang, Guangdong Province"
  let locName: string = phonenumberfmt.getLocationName("0039312****789", "zh-CN"); // locName = "Italy"
  ```


## PhoneNumberFormatOptions<sup>8+</sup>

Options for initializing the **PhoneNumberFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name  | Type    | Readable  | Writable  | Description                                      |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | Yes   | Yes   | Type of the phone number. The value can be **E164**, **INTERNATIONAL**, **NATIONAL**, **RFC3966**, or **TYPING**.<br>- In API version 8, **type** is mandatory.<br>- In API version 9 or later, **type** is optional.<br>- **TYPING** is supported since API version 12.|


## UnitInfo<sup>8+</sup>

Defines the measurement unit information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name           | Type    | Readable  | Writable  | Description                                      |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| unit          | string | Yes   | Yes   | Name of the measurement unit, for example, **meter**, **inch**, or **cup**.|
| measureSystem | string | Yes   | Yes   | Measurement system. The value can be **SI**, **US**, or **UK**.|


## getInstance<sup>8+</sup>

getInstance(locale?:string): IndexUtil

Creates an **IndexUtil** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                          |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | No   | A string containing locale information, including the language, optional script, and region.<br>The default value is the system locale.|

**Return value**

| Type                      | Description                   |
| ------------------------ | --------------------- |
| [IndexUtil](#indexutil8) | **IndexUtil** object mapping to the **locale** object.|

**Example**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance("zh-CN");
  ```


## IndexUtil<sup>8+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

### getIndexList<sup>8+</sup>

getIndexList(): Array&lt;string&gt;

Obtains the index list of the current locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description                |
| ------------------- | ------------------ |
| Array&lt;string&gt; | Index list of the current locale.|

**Example**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance("zh-CN");
  // indexList = [ "...", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
  //              "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "..." ]
  let indexList: Array<string> = indexUtil.getIndexList();
  ```


### addLocale<sup>8+</sup>

addLocale(locale: string): void

Adds the index list of a new locale to the index list of the current locale to form a composite list.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                          |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | Yes   | A string containing locale information, including the language, optional script, and region.|

**Example**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance("zh-CN");
  indexUtil.addLocale("en-US");
  ```

### getIndex<sup>8+</sup>

getIndex(text: string): string

Obtains the index of a **text** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| text | string | Yes   | **text** object whose index is to be obtained.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Index of the **text** object.|

**Example**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance("zh-CN");
  let index: string = indexUtil.getIndex("hi");  // index = "H"
  ```


## i18n.getLineInstance<sup>8+</sup>

getLineInstance(locale: string): BreakIterator

Obtains a [BreakIterator](#breakiterator8) object for text segmentation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | A string containing locale information, including the language, optional script, and region.<br>The [BreakIterator](#breakiterator8) object segments text according to the rules of the specified locale.|

**Return value**

| Type                              | Description         |
| -------------------------------- | ----------- |
| [BreakIterator](#breakiterator8) | Break iterator used for text segmentation.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  ```


## BreakIterator<sup>8+</sup>


### setLineBreakText<sup>8+</sup>

setLineBreakText(text: string): void

Sets the text to be processed by the **BreakIterator** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description                     |
| ---- | ------ | ---- | ----------------------- |
| text | string | Yes   | Text to be processed by the **BreakIterator** object.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit ."); // Set a short sentence as the text to be processed by the BreakIterator object.
  ```


### getLineBreakText<sup>8+</sup>

getLineBreakText(): string

Obtains the text being processed by the **BreakIterator** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                    |
| ------ | ---------------------- |
| string | Text being processed by the **BreakIterator** object.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let breakText: string = iterator.getLineBreakText(); // breakText = "Apple is my favorite fruit."
  ```


### current<sup>8+</sup>

current(): number

Obtains the position of a **BreakIterator** object in the processed text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                         |
| ------ | --------------------------- |
| number | Position of the **BreakIterator** object in the text being processed.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let currentPos: number = iterator.current(); // currentPos = 0
  ```


### first<sup>8+</sup>

first(): number

Moves a **BreakIterator** object to the first break point, which is always at the beginning of the processed text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description               |
| ------ | ----------------- |
| number | Offset to the first break point of the processed text.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let firstPos: number = iterator.first(); // firstPos = 0
  ```


### last<sup>8+</sup>

last(): number

Moves a **BreakIterator** object to the last break point, which is always the next position after the end of the processed text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | Offset to the last break point of the processed text.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let lastPos: number = iterator.last(); // lastPos = 27
  ```


### next<sup>8+</sup>

next(index?: number): number

Moves the **BreakIterator** object backward by the corresponding number of break points.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| index | number | No   | Number of break points to be moved by the **BreakIterator** object.<br>A positive value indicates that the break point is moved backward by the specified number of break points, and a negative value indicates the opposite.<br>The default value is **1**.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the **BreakIterator** object in the text after it is moved by the specified number of break points.<br>The value **-1** is returned if the position of the **BreakIterator** object is outside of the processed text after movement.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(); // pos = 6
  pos = iterator.next(10); // pos = -1
  ```


### previous<sup>8+</sup>

previous(): number

Moves the **BreakIterator** object forward by one break point.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the **BreakIterator** object in the text after it is moved to the previous break point.<br>The value **-1** is returned if the position of the **BreakIterator** object is outside of the processed text after movement.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(3); // pos = 12
  pos = iterator.previous(); // pos = 9
  ```


### following<sup>8+</sup>

following(offset: number): number

Moves a **BreakIterator** object to the break point following the specified position.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| offset | number | Yes   | Offset to the break point following the specified position.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the **BreakIterator** object after movement. The value **-1** is returned if the position of the **BreakIterator** object is outside of the processed text after movement.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.following(0); // pos = 6
  pos = iterator.following(100); // pos = -1
  pos = iterator.current(); // pos = 27
  ```


### isBoundary<sup>8+</sup>

isBoundary(offset: number): boolean

Checks whether the specified position is a break point.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description         |
| ------ | ------ | ---- | ----------- |
| offset | number | Yes   | Specified position.|

**Return value**

| Type     | Description                             |
| ------- | ------------------------------- |
| boolean | Offset to the specified position of the text. The value **true** is returned if the position specified by **offset** is a break point, and the value **false** is returned otherwise.<br>If **true** is returned, the **BreakIterator** object is moved to the position specified by **offset**. Otherwise, **following** is called.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let isBoundary: boolean = iterator.isBoundary(0); // isBoundary = true;
  isBoundary = iterator.isBoundary(5); // isBoundary = false;
  ```


## i18n.getTimeZone

getTimeZone(zoneID?: string): TimeZone

Obtains the **TimeZone** object corresponding to the specified time zone ID.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| zoneID | string | No   | Time zone ID. The default value is the system time zone.|

**Return value**

| Type      | Description          |
| -------- | ------------ |
| [TimeZone](#timezone) | **TimeZone** object corresponding to the time zone ID.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  ```

## TimeZone

### getID

getID(): string

Obtains the ID of the specified **TimeZone** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Time zone ID corresponding to the **TimeZone** object.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  let timezoneID: string = timezone.getID(); // timezoneID = "Asia/Shanghai"
  ```


### getDisplayName

getDisplayName(locale?: string, isDST?: boolean): string

Obtains the localized representation of a **TimeZone** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type     | Mandatory  | Description                  |
| ------ | ------- | ---- | -------------------- |
| locale | string  | No   | A string containing locale information, including the language, optional script, and region. The default value is the system locale.               |
| isDST  | boolean | No   | Whether DST is considered in the localized representation of the **TimeZone** object. The default value is **false**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized display of the **TimeZone** object in the specified locale.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  let timezoneName: string = timezone.getDisplayName("zh-CN", false); // timezoneName = "China Standard Time"
  ```


### getRawOffset

getRawOffset(): number

Obtains the offset between the time zone represented by a **TimeZone** object and the UTC time zone.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| number | Offset between the time zone represented by a **TimeZone** object and the UTC time zone, in milliseconds.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  let offset: number = timezone.getRawOffset(); // offset = 28800000
  ```


### getOffset

getOffset(date?: number): number

Obtains the offset between the time zone represented by a **TimeZone** object and the UTC time zone at a certain time.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| date | number | No   | Time for calculating the offset, in milliseconds. The default value is the system time.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| number | Offset between the time zone represented by the **TimeZone** object and the UTC time zone at a certain time.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone();
  let offset: number = timezone.getOffset(1234567890); // offset = 28800000
  ```


### getAvailableIDs<sup>9+</sup>

static getAvailableIDs(): Array&lt;string&gt;

Obtains the list of time zone IDs supported by the system.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description         |
| ------------------- | ----------- |
| Array&lt;string&gt; | List of time zone IDs supported by the system.|

**Example**
  ```ts
  // ids = ["America/Adak", "America/Anchorage", "America/Bogota", "America/Denver", "America/Los_Angeles", "America/Montevideo", "America/Santiago", "America/Sao_Paulo", "Asia/Ashgabat", "Asia/Hovd", "Asia/Jerusalem", "Asia/Magadan", "Asia/Omsk", "Asia/Shanghai", "Asia/Tokyo", "Asia/Yerevan", "Atlantic/Cape_Verde", "Australia/Lord_Howe", "Europe/Dublin", "Europe/London", "Europe/Moscow", "Pacific/Auckland", "Pacific/Easter", "Pacific/Pago-Pago"]
  let ids: Array<string> = i18n.TimeZone.getAvailableIDs();
  ```


### getAvailableZoneCityIDs<sup>9+</sup>

static getAvailableZoneCityIDs(): Array&lt;string&gt;

Obtains the list of time zone city IDs supported by the system.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Array&lt;string&gt; | List of time zone city IDs supported by the system.|

**Example**
  ```ts
  // cityIDs = ["Auckland", "Magadan", "Lord Howe Island", "Tokyo", "Shanghai", "Hovd", "Omsk", "Ashgabat", "Yerevan", "Moscow", "Tel Aviv", "Dublin", "London", "Praia", "Montevideo", "Brasília", "Santiago", "Bogotá", "Easter Island", "Salt Lake City", "Los Angeles", "Anchorage", "Adak", "Pago Pago"]
  let cityIDs: Array<string> = i18n.TimeZone.getAvailableZoneCityIDs();
  ```

### getCityDisplayName<sup>9+</sup>

static getCityDisplayName(cityID: string, locale: string): string

Obtains the localized representation of a time zone city in the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| cityID | string | Yes   | Time zone city ID.|
| locale | string | Yes   | A string containing locale information, including the language, optional script, and region. |

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | Localized display of the time zone city in the specified locale.|

**Example**
  ```ts
  let displayName: string = i18n.TimeZone.getCityDisplayName("Shanghai", "zh-CN"); // displayName = "Shanghai (China)"
  ```


### getTimezoneFromCity<sup>9+</sup>

static getTimezoneFromCity(cityID: string): TimeZone

Obtains the **TimeZone** object corresponding to the specified time zone city ID.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| cityID | string | Yes   | Time zone city ID.|

**Return value**

| Type      | Description         |
| -------- | ----------- |
| TimeZone | **TimeZone** object corresponding to the specified time zone city ID.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.TimeZone.getTimezoneFromCity("Shanghai");
  ```

### getTimezonesByLocation<sup>10+</sup>

static getTimezonesByLocation(longitude: number, latitude: number): Array&lt;TimeZone&gt;

Creates an array of **TimeZone** objects corresponding to the specified longitude and latitude.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type    | Mandatory  | Description    |
| --------- | ------ | ---- | ------ |
| longitude | number | Yes   | Longitude. The value range is [-180, 179.9). A positive value is used for east longitude and a negative value is used for west longitude.|
| latitude  | number | Yes   | Latitude. The value range is [-90, 89.9). A positive value is used for north latitude and a negative value is used for south latitude.|

**Return value**

| Type      | Description         |
| -------- | ----------- |
| Array&lt;[TimeZone](#timezone)&gt; | **TimeZone** object array.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |


> **Description**
>
> The error message of 890001 is subject to the actual error.

**Example**
  ```ts
  let timezoneArray: Array<i18n.TimeZone> = i18n.TimeZone.getTimezonesByLocation(-118.1, 34.0);
  for (let i = 0; i < timezoneArray.length; i++) {
      let tzId: string = timezoneArray[i].getID();
  }
  ```


## Transliterator<sup>9+</sup>


### getAvailableIDs<sup>9+</sup>

static getAvailableIDs(): string[]

Obtains a list of IDs supported by the **Transliterator** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type      | Description        |
| -------- | ---------- |
| string[] | List of IDs supported by the **Transliterator** object.|

**Example**
  ```ts
  // A total of 742 IDs are supported. One ID is comprised of two parts separated by a hyphen (-) in the format of source-destination. For example, in **ids = ["Han-Latin","Latin-ASCII", "Amharic-Latin/BGN","Accents-Any", ...]**, **Han-Latin** indicates conversion from Chinese to Latin, and **Amharic-Latin** indicates conversion from Amharic to Latin.
  // For more information, see ISO-15924.
  let ids: string[] = i18n.Transliterator.getAvailableIDs();
  ```


### getInstance<sup>9+</sup>

static getInstance(id: string): Transliterator

Creates a **Transliterator** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description      |
| ---- | ------ | ---- | -------- |
| id   | string | Yes   | ID supported by the **Transliterator** object.|

**Return value**

| Type                                | Description   |
| ---------------------------------- | ----- |
| [Transliterator](#transliterator9) | **Transliterator** object.|

**Example**
  ```ts
  let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance("Any-Latn");
  ```


### transform<sup>9+</sup>

transform(text: string): string

Converts the input string from the source format to the target format.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description    |
| ---- | ------ | ---- | ------ |
| text | string | Yes   | Input string.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Target string.|

**Example**
  ```ts
  let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance("Any-Latn");
  let res: string = transliterator.transform("China"); // res = "zhōng guó"
  ```


## Unicode<sup>9+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

### isDigit<sup>9+</sup>

static isDigit(char: string): boolean

Checks whether the input string is composed of digits.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input string.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | The value **true** indicates that the input character is a digit, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isdigit: boolean = i18n.Unicode.isDigit("1");  // isdigit = true
  ```


### isSpaceChar<sup>9+</sup>

static isSpaceChar(char: string): boolean

Checks whether the input character is a space.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input string.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | The value **true** indicates that the input character is a space, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isspacechar: boolean = i18n.Unicode.isSpaceChar("a");  // isspacechar = false
  ```


### isWhitespace<sup>9+</sup>

static isWhitespace(char: string): boolean

Checks whether the input character is a white space.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | String obtained.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | The value **true** indicates that the input character is a white space, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let iswhitespace: boolean = i18n.Unicode.isWhitespace("a");  // iswhitespace = false
  ```


### isRTL<sup>9+</sup>

static isRTL(char: string): boolean

Checks whether the input character is of the right to left (RTL) language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the input character is of the RTL language, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isrtl: boolean = i18n.Unicode.isRTL("a");  // isrtl = false
  ```


### isIdeograph<sup>9+</sup>

static isIdeograph(char: string): boolean

Checks whether the input character is an ideographic character.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the input character is an ideographic character, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isideograph: boolean = i18n.Unicode.isIdeograph("a");  // isideograph = false
  ```


### isLetter<sup>9+</sup>

static isLetter(char: string): boolean

Checks whether the input character is a letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | The value **true** indicates that the input character is a letter, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isletter: boolean = i18n.Unicode.isLetter("a");  // isletter = true
  ```


### isLowerCase<sup>9+</sup>

static isLowerCase(char: string): boolean

Checks whether the input character is a lowercase letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the input character is a lowercase letter, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let islowercase: boolean = i18n.Unicode.isLowerCase("a");  // islowercase = true
  ```


### isUpperCase<sup>9+</sup>

static isUpperCase(char: string): boolean

Checks whether the input character is an uppercase letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the input character is an uppercase letter, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isuppercase: boolean = i18n.Unicode.isUpperCase("a");  // isuppercase = false
  ```


### getType<sup>9+</sup>

static getType(char: string): string

Obtains the type of the input string.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Type of the input character.|

The following table lists only the common types. For more details, see the Unicode Standard.

| Name| Value| Description|
| ---- | -------- | ---------- |
| U_UNASSIGNED | U_UNASSIGNED | Non-category for unassigned and non-character code points.|
| U_GENERAL_OTHER_TYPES | U_GENERAL_OTHER_TYPES | Same as **U_UNASSIGNED**.|
| U_UPPERCASE_LETTER | U_UPPERCASE_LETTER | Uppercase letter.|
| U_LOWERCASE_LETTER | U_LOWERCASE_LETTER | Lowercase letter. |
| U_TITLECASE_LETTER | U_TITLECASE_LETTER | Title case letter.|
| U_MODIFIER_LETTER | U_MODIFIER_LETTER | Modifier letter.|
| U_OTHER_LETTER | U_OTHER_LETTER | Letters other than the uppercase letter, lowercase letter, title case letter, and modifier letter.|
| U_NON_SPACING_MARK | U_NON_SPACING_MARK | Non-spacing mark, such as the accent symbol **'** and the variable symbol **#**.|
| U_ENCLOSING_MARK | U_ENCLOSING_MARK | Enclosing mark, for example, a circle or a box.|
| U_COMBINING_SPACING_MARK | U_COMBINING_SPACING_MARK | Spacing mark, for example, the vowel symbol **[]**.|
| U_DECIMAL_DIGIT_NUMBER | U_DECIMAL_DIGIT_NUMBER | Decimal number.|
| U_LETTER_NUMBER | U_LETTER_NUMBER | Letter and number (including Roman numeral).|
| U_OTHER_NUMBER | U_OTHER_NUMBER | Other numbers, which are used as encryption symbols, marker symbols, or non-Arabic numerals, such as **@**, **#**, **(1)**, and **①**.|
| U_SPACE_SEPARATOR | U_SPACE_SEPARATOR | Space separator, for example, a space character, uninterrupted space character, or space character with a fixed width.|
| U_LINE_SEPARATOR | U_LINE_SEPARATOR | Line separator.|
| U_PARAGRAPH_SEPARATOR | U_PARAGRAPH_SEPARATOR | Paragraph separator.|
| U_CONTROL_CHAR | U_CONTROL_CHAR | Control character.|
| U_FORMAT_CHAR | U_FORMAT_CHAR | Format character.|
| U_PRIVATE_USE_CHAR | U_PRIVATE_USE_CHAR | Privately used character, for example, a company logo.|
| U_SURROGATE | U_SURROGATE | Surrogate, which is used to represent supplementary characters in UTF-16.|
| U_DASH_PUNCTUATION | U_DASH_PUNCTUATION | Dash punctuation.|
| U_START_PUNCTUATION | U_START_PUNCTUATION | Start punctuation, for example, the left parenthesis.|
| U_END_PUNCTUATION | U_END_PUNCTUATION | End punctuation, for example, the right parenthesis.|
| U_INITIAL_PUNCTUATION | U_INITIAL_PUNCTUATION | Initial punctuation, for example, the left double quotation mark or left single quotation mark.|
| U_FINAL_PUNCTUATION | U_FINAL_PUNCTUATION | Final punctuation, for example, the right double quotation mark or right single quotation mark.|
| U_CONNECTOR_PUNCTUATION | U_CONNECTOR_PUNCTUATION | Connector punctuation.|
| U_OTHER_PUNCTUATION | U_OTHER_PUNCTUATION | Other punctuations.|
| U_MATH_SYMBOL | U_MATH_SYMBOL | Mathematical symbol.|
| U_CURRENCY_SYMBOL | U_CURRENCY_SYMBOL | Currency symbol.|
| U_MODIFIER_SYMBOL | U_MODIFIER_SYMBOL | Modifier symbol.|
| U_OTHER_SYMBOL | U_OTHER_SYMBOL | Other symbols.|

**Example**
  ```ts
  let type: string = i18n.Unicode.getType("a"); // type = "U_LOWERCASE_LETTER"
  ```

## I18NUtil<sup>9+</sup>


### unitConvert<sup>9+</sup>

static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

Converts one measurement unit into another and formats the unit based on the specified locale and style.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type                    | Mandatory  | Description                                      |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| fromUnit | [UnitInfo](#unitinfo8) | Yes   | Measurement unit to be converted.                                |
| toUnit   | [UnitInfo](#unitinfo8) | Yes   | Measurement unit to be converted to.                                |
| value    | number                 | Yes   | Value of the measurement unit to be converted.                            |
| locale   | string                 | Yes   | A string containing locale information, including the language, optional script, and region, for example, **zh-Hans-CN**.               |
| style    | string                 | No   | Style used for formatting. The value can be **long**, **short**, or **narrow**. The default value is **short**.<br>For details about the meaning or display effect of different values, see [Number and Unit of Measurement Formatting](../../internationalization/i18n-numbers-weights-measures.md).|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| string | String obtained after formatting based on the measurement unit specified by **toUnit**.|

**Example**
  ```ts
  let fromUnit: i18n.UnitInfo = {unit: "cup", measureSystem: "US"};
  let toUnit: i18n.UnitInfo = {unit: "liter", measureSystem: "SI"};
  let res: string = i18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, "en-US", "long"); // res = 236.588 liters
  ```

### getDateOrder<sup>9+</sup>

static getDateOrder(locale: string): string

Obtains the sequence of the year, month, and day in the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| locale | string | Yes   | A string containing locale information, including the language, optional script, and region, for example, **zh-Hans-CN**.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Sequence of the year, month, and day in the locale.|

**Example**
  ```ts
  let order: string = i18n.I18NUtil.getDateOrder("zh-CN");  // order = "y-L-d"
  ```


### getTimePeriodName<sup>11+</sup>

static getTimePeriodName(hour:number, locale?: string): string

Obtains the localized expression for the specified time of the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| hour | number | Yes   | Specified time, for example, **16**.|
| locale | string | No   | A string containing locale information, including the language, optional script, and region, for example, **zh-Hans-CN**.<br>The default value is the current locale.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Localized expression for the specified time of the specified locale.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let name: string = i18n.I18NUtil.getTimePeriodName(2, "zh-CN");  // name = "a.m."
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call I18NUtil.getTimePeriodName failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getBestMatchLocale<sup>12+</sup>

static getBestMatchLocale(locale: string, localeList: string[]): string

Obtains the locale that best matches a region from the specified locale list.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| locale | string | Yes   | Locale ID, for example, **zh-Hans-CN**.|
| localeList | string[] | Yes  | Locale ID list.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | ID of the locale that best matches a region. If no matching locale is found, an empty string is returned.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let matchedLocaleId: string = i18n.I18NUtil.getBestMatchLocale("zh-Hans-CN", ["en-Latn-US", "en-GB", "zh-Hant-CN", "zh-Hans-MO"]);  // matchedLocaleId = "zh-Hans-MO"
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call I18NUtil.getBestMatchLocale failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getThreeLetterLanguage<sup>12+</sup>

static getThreeLetterLanguage(locale: string): string

Converts a language code from two letters to three letters.<br>For example, the two-letter language code of Chinese is **zh**, and the corresponding three-letter language code is **zho**. For details, see [ISO 639](https://www.iso.org/iso-639-language-code).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| locale | string | Yes  | Two-letter code of the language to be converted, for example, **zh**.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001   | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let language : string = i18n.I18NUtil.getThreeLetterLanguage('zh')  // zho
  } catch(error) {
    console.error(`call I18NUtil.getThreeLetterLanguage failed, error code: ${error.code}, message: ${error.message}.`);
  }
  ```

### getThreeLetterRegion<sup>12+</sup>

static getThreeLetterRegion(locale: string): string

Converts a country/region code from two letters to three letters.<br>For example, the two-letter country/region code of China is **CN**, and the three-letter country/region code is **CHN**. For details, see [ISO 3166](https://www.iso.org/iso-3166-country-codes.html).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| locale | string | Yes  | Two-letter country/region code to be converted, for example, **CN**.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001   | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let region : string = i18n.I18NUtil.getThreeLetterRegion('CN')  // CHN
  } catch(error) {
    console.error(`call I18NUtil.getThreeLetterRegion failed, error code: ${error.code}, message: ${error.message}.`);
  }
  ```

## Normalizer<sup>10+</sup>


### getInstance<sup>10+</sup>

static getInstance(mode: NormalizerMode): Normalizer

Obtains a **Normalizer** object for text normalization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| mode | [NormalizerMode](#normalizermode10) | Yes   | Text normalization mode.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| [Normalizer](#normalizer10) | **Normalizer** object for text normalization.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**
  ```ts
  let normalizer: i18n.Normalizer = i18n.Normalizer.getInstance(i18n.NormalizerMode.NFC);
  ```


### normalize<sup>10+</sup>

normalize(text: string): string

Normalizes text strings.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| text | string | Yes   | Text strings to be normalized.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Normalized text strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**
  ```ts
  let normalizer: i18n.Normalizer = i18n.Normalizer.getInstance(i18n.NormalizerMode.NFC);
  let normalizedText: string = normalizer.normalize('\u1E9B\u0323'); // normalizedText = ẛ̣
  ```

## NormalizerMode<sup>10+</sup>

Enumerates text normalization modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name| Value| Description|
| -------- | -------- | -------- |
| NFC | 1 | NFC.|
| NFD | 2 | NFD.|
| NFKC | 3 | NFKC.|
| NFKD | 4 | NFKD.|


## HolidayManager<sup>11+</sup>


### constructor<sup>11+</sup>

constructor(icsPath: String)

Creates a **HolidayManager** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| icsPath   | String | Yes  | Path of the **.ics** file with the read permission granted for applications. |

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  let holidayManager= new i18n.HolidayManager("/system/lib/US.ics");
  ```

### isHoliday<sup>11+</sup>

isHoliday(date?: Date): boolean

Determines whether the specified date is a holiday.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ---------------| ---- | ------------- |
| date      | Date           | No  | **Date** object.<br>If no date is specified, the current date is used by default.|

**Return value**

|       Type       |         Description         |
| ----------------- | ----------------------|
| boolean           | The value **true** indicates that the specified date is a holiday, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let holidayManager= new i18n.HolidayManager("/system/lib/US.ics");
    let isHoliday = holidayManager.isHoliday();
    console.log(isHoliday.toString());
    let isHoliday2 = holidayManager.isHoliday(new Date(2023,5,25));
    console.log(isHoliday2.toString());
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call holidayManager.isHoliday failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getHolidayInfoItemArray<sup>11+</sup>

getHolidayInfoItemArray(year?: number): Array&lt;[HolidayInfoItem](#holidayinfoitem11)&gt;

Obtains the holiday information list of the specified year.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | -------------  | ---- | ------------- |
| year      | number         | No  | Specified year, for example, 2023.<br>If no year is specified, the current year is used by default.|

**Return value**

|       Type       |         Description         |
| ----------------- | -------------------- |
| Array&lt;[HolidayInfoItem](#holidayinfoitem11)&gt; | Holiday information list.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let holidayManager= new i18n.HolidayManager("/system/lib/US.ics");
    let holidayInfoItemArray = holidayManager.getHolidayInfoItemArray(2023);
    for (let i =0; i < holidayInfoItemArray.length; i++) {
        console.log(JSON.stringify(holidayInfoItemArray[i]));
    }
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call holidayManager.getHolidayInfoItemArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## HolidayInfoItem<sup>11+</sup>

Represents the holiday information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Mandatory  |  Description                                  |
| --------------- | --------------- | ------  | --------------------------------------- |
| baseName        | string          |   Yes   | Holiday name.             |
| year            | number          |   Yes   | Year of the holiday.                  |
| month           | number          |   Yes   | Month of the holiday.         |
| day             | number          |   Yes   | Day of the holiday.                        |
| localNames      | Array&lt;[HolidayLocalName](#holidaylocalname11)&gt;          |   No   | Local names of the holiday.         |

## HolidayLocalName<sup>11+</sup>

Defines the local names of a holiday.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Mandatory  |  Description                                  |
| --------------- | -----------------| ------  | --------------------------------------- |
| language        | string           |   Yes   | Local language of a holiday, for example, **ar**, **en**, or **tr**.         |
| name            | string           |   Yes   | Local name of a holiday. For example, the Turkish name of Sacrifice Feast is Kurban Bayrami.     |


## i18n.getDisplayCountry<sup>(deprecated)</sup>

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

Obtains the localized script for the specified country.

This API is deprecated since API version 9. You are advised to use [System.getDisplayCountry](#getdisplaycountry9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | Yes   | Specified country.           |
| locale       | string  | Yes   | Locale ID.    |
| sentenceCase | boolean | No   | Whether to use sentence case for the localized script. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified country.|

**Example**
  ```ts
  let countryName: string = i18n.getDisplayCountry("zh-CN", "en-GB", true); // countryName = China
  countryName = i18n.getDisplayCountry("zh-CN", "en-GB"); // countryName = China
  ```

## i18n.getDisplayCountry<sup>(deprecated)</sup>

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

Obtains the localized script for the specified country.

This API is deprecated since API version 9. You are advised to use [System.getDisplayCountry](#getdisplaycountry9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | Yes   | Specified country.           |
| locale       | string  | Yes   | Locale ID.    |
| sentenceCase | boolean | No   | Whether to use sentence case for the localized script. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified country.|

**Example**
  ```ts
  let countryName: string = i18n.getDisplayCountry("zh-CN", "en-GB", true); // countryName = China
  countryName = i18n.getDisplayCountry("zh-CN", "en-GB"); // countryName = China
  ```


## i18n.getDisplayLanguage<sup>(deprecated)</sup>

getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

Obtains the localized script for the specified language.

This API is deprecated since API version 9. You are advised to use [System.getDisplayLanguage](#getdisplaylanguage9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| language     | string  | Yes   | Specified language.           |
| locale       | string  | Yes   | Locale ID.    |
| sentenceCase | boolean | No   | Whether to use sentence case for the localized script. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified language.|

**Example**
  ```ts
  let languageName: string = i18n.getDisplayLanguage("zh", "en-GB", true); // languageName = "Chinese"
  languageName = i18n.getDisplayLanguage("zh", "en-GB"); // languageName = "Chinese"
  ```


## i18n.getSystemLanguage<sup>(deprecated)</sup>

getSystemLanguage(): string

Obtains the system language.

This API is deprecated since API version 9. You are advised to use [System.getSystemLanguage](#getsystemlanguage9).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System language ID.|

**Example**
  ```ts
  let systemLanguage: string = i18n.getSystemLanguage(); // Obtain the current system language.
  ```


## i18n.getSystemRegion<sup>(deprecated)</sup>

getSystemRegion(): string

Obtains the system region.

This API is deprecated since API version 9. You are advised to use [System.getSystemRegion](#getsystemregion9).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System region ID.|

**Example**
  ```ts
  let region: string = i18n.getSystemRegion(); // Obtain the current system region.
  ```


## i18n.getSystemLocale<sup>(deprecated)</sup>

getSystemLocale(): string

Obtains the system locale.

This API is deprecated since API version 9. You are advised to use [System.getSystemLocale](#getsystemlocale9).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System locale ID.|

**Example**
  ```ts
  let locale: string = i18n.getSystemLocale (); // Obtain the system locale.
  ```


## i18n.is24HourClock<sup>(deprecated)</sup>

is24HourClock(): boolean

Checks whether the 24-hour clock is used.

This API is deprecated since API version 9. You are advised to use [System.is24HourClock](#is24hourclock9).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the 24-hour clock is used, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let is24HourClock: boolean = i18n.is24HourClock();
  ```


## i18n.set24HourClock<sup>(deprecated)</sup>

set24HourClock(option: boolean): boolean

Sets the 24-hour clock.

This API is deprecated since API version 9. The substitute API is available only for system applications.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type     | Mandatory  | Description                                      |
| ------ | ------- | ---- | ---------------------------------------- |
| option | boolean | Yes   | Whether to enable the 24-hour clock. The value **true** means to enable the 24-hour clock, and the value **false** means the opposite.|

**Return value**

| Type     | Description                           |
| ------- | ----------------------------- |
| boolean | The value **true** indicates that the 24-hour clock is enabled, and the value **false** indicates the opposite.|

**Example**
  ```ts
  // Set the system time to the 24-hour clock.
  let success: boolean = i18n.set24HourClock(true);
  ```


## i18n.addPreferredLanguage<sup>(deprecated)</sup>

addPreferredLanguage(language: string, index?: number): boolean

Adds a preferred language to the specified position on the preferred language list.

This API is supported since API version 8 and is deprecated since API version 9. The substitute API is available only for system applications.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description        |
| -------- | ------ | ---- | ---------- |
| language | string | Yes   | Preferred language to add. |
| index    | number | No   | Position to which the preferred language is added. The default value is the length of the preferred language list.|

**Return value**

| Type     | Description                           |
| ------- | ----------------------------- |
| boolean | The value **true** indicates that the preferred language is successfully added, and the value **false** indicates the opposite.|

**Example**
  ```ts
  // Add zh-CN to the preferred language list.
  let language: string = 'zh-CN';
  let index: number = 0;
  let success: boolean = i18n.addPreferredLanguage(language, index);
  ```


## i18n.removePreferredLanguage<sup>(deprecated)</sup>

removePreferredLanguage(index: number): boolean

Deletes a preferred language from the specified position on the preferred language list.

This API is supported since API version 8 and is deprecated since API version 9. The substitute API is available only for system applications.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                   |
| ----- | ------ | ---- | --------------------- |
| index | number | Yes   | Position of the preferred language to delete.|

**Return value**

| Type     | Description                           |
| ------- | ----------------------------- |
| boolean | The value **true** indicates that the preferred language is deleted, and the value **false** indicates the opposite.|

**Example**
  ```ts
  // Delete the first preferred language from the preferred language list.
  let index: number = 0;
  let success: boolean = i18n.removePreferredLanguage(index);
  ```


## i18n.getPreferredLanguageList<sup>(deprecated)</sup>

getPreferredLanguageList(): Array&lt;string&gt;

Obtains the list of preferred languages.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.getPreferredLanguageList](#getpreferredlanguagelist9).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description       |
| ------------------- | --------- |
| Array&lt;string&gt; | List of preferred languages.|

**Example**
  ```ts
  let preferredLanguageList: Array<string> = i18n.getPreferredLanguageList(); // Obtain the preferred language list.
  ```


## i18n.getFirstPreferredLanguage<sup>(deprecated)</sup>

getFirstPreferredLanguage(): string

Obtains the first language in the preferred language list.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.getFirstPreferredLanguage](#getfirstpreferredlanguage9).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description            |
| ------ | -------------- |
| string | First language in the preferred language list.|

**Example**
  ```ts
  let firstPreferredLanguage: string = i18n.getFirstPreferredLanguage();
  ```


## Util<sup>(deprecated)</sup>


### unitConvert<sup>(deprecated)</sup>

unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

Converts one measurement unit into another and formats the unit based on the specified locale and style.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [unitConvert](#unitconvert9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type                    | Mandatory  | Description                                      |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| fromUnit | [UnitInfo](#unitinfo8) | Yes   | Measurement unit to be converted.                                |
| toUnit   | [UnitInfo](#unitinfo8) | Yes   | Measurement unit to be converted to.                                |
| value    | number                 | Yes   | Value of the measurement unit to be converted.                            |
| locale   | string                 | Yes   | Locale used for formatting, for example, **zh-Hans-CN**.               |
| style    | string                 | No   | Style used for formatting. The value can be **long**, **short**, or **narrow**. The default value is **short**.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| string | String obtained after formatting based on the measurement unit specified by **toUnit**.|


## Character<sup>(deprecated)</sup>


### isDigit<sup>(deprecated)</sup>

isDigit(char: string): boolean

Checks whether the input string is composed of digits.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isDigit](#isdigit9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | The value **true** indicates that the input character is a digit, and the value **false** indicates the opposite.|


### isSpaceChar<sup>(deprecated)</sup>

isSpaceChar(char: string): boolean

Checks whether the input character is a space.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isSpaceChar](#isspacechar9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | The value **true** indicates that the input character is a space, and the value **false** indicates the opposite.|


### isWhitespace<sup>(deprecated)</sup>

isWhitespace(char: string): boolean

Checks whether the input character is a white space.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isWhitespace](#iswhitespace9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | The value **true** indicates that the input character is a white space, and the value **false** indicates the opposite.|


### isRTL<sup>(deprecated)</sup>

isRTL(char: string): boolean

Checks whether the input character is of the right to left (RTL) language.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isRTL](#isrtl9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the input character is of the RTL language, and the value **false** indicates the opposite.|


### isIdeograph<sup>(deprecated)</sup>

isIdeograph(char: string): boolean

Checks whether the input character is an ideographic character.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isIdeograph](#isideograph9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the input character is an ideographic character, and the value **false** indicates the opposite.|


### isLetter<sup>(deprecated)</sup>

isLetter(char: string): boolean

Checks whether the input character is a letter.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isLetter](#isletter9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | The value **true** indicates that the input character is a letter, and the value **false** indicates the opposite.|


### isLowerCase<sup>(deprecated)</sup>

isLowerCase(char: string): boolean

Checks whether the input character is a lowercase letter.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isLowerCase](#islowercase9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the input character is a lowercase letter, and the value **false** indicates the opposite.|


### isUpperCase<sup>(deprecated)</sup>

isUpperCase(char: string): boolean

Checks whether the input character is an uppercase letter.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isUpperCase](#isuppercase9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the input character is an uppercase letter, and the value **false** indicates the opposite.|


### getType<sup>(deprecated)</sup>

getType(char: string): string

Obtains the type of the input string.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [getType](#gettype9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Type of the input character.|
