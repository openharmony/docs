# @ohos.i18n (Internationalization)

This module provides system-related or enhanced [i18n](../../internationalization/i18n-l10n.md) capabilities, such as locale management, phone number formatting, and calendar, through supplementary I18N APIs that are not defined in [ECMA 402](https://dev.ecma-international.org/publications-and-standards/standards/ecma-402/). The [intl](js-apis-intl.md) module provides basic i18n capabilities through the standard i18n APIs defined in ECMA 402. It works with the **i18n** module to provide a complete suite of i18n capabilities.

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

Obtains the country/region display name in the specified language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | Yes   | Valid country/region code.           |
| locale       | string  | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.    |
| sentenceCase | boolean | No   | Whether to use sentence case to display the text. The value **true** means to display the text in title case format, and the value **false** means to display the text in the default case format of the locale. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Country/region display name in the specified language.|

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
    let displayCountry: string = i18n.System.getDisplayCountry('CN', 'en-GB'); // displayCountry = 'China'
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getDisplayCountry failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getDisplayLanguage<sup>9+</sup>

static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

Obtains the language display name in the specified language.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| language     | string  | Yes   | Valid language ID.           |
| locale       | string  | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.    |
| sentenceCase | boolean | No   | Whether to use sentence case to display the text. The value **true** means to display the text in title case format, and the value **false** means to display the text in the default case format of the locale. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Language display name in the specified language.|

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
    // Obtain the display name of Chinese in English.
    let displayLanguage: string = i18n.System.getDisplayLanguage('zh', 'en-GB'); // displayLanguage = 'Chinese'
  } catch (error) {
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
| Array&lt;string&gt; | List of system languages.|

**Example**
  ```ts
  // systemLanguages = [ 'ug', 'bo', 'zh-Hant', 'en-Latn-US', 'zh-Hans' ]
  let systemLanguages: Array<string> = i18n.System.getSystemLanguages();
  ```

### getSystemCountries<sup>9+</sup>

static getSystemCountries(language: string): Array&lt;string&gt;

Obtains the list of countries/regions supported for the specified language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description   |
| -------- | ------ | ---- | ----- |
| language | string | Yes   | Valid language ID.|

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Array&lt;string&gt; | List of countries/regions supported for the specified language.|

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
    // systemCountries = [ 'ZW', 'YT', 'YE', ..., 'ER', 'CN', 'DE' ]
    let systemCountries: Array<string> = i18n.System.getSystemCountries('zh');
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemCountries failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### isSuggested<sup>9+</sup>

static isSuggested(language: string, region?: string): boolean

Checks whether a language is a suggested language in the specified region. It can be used for region-based language recommendation or language-based region recommendation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description           |
| -------- | ------ | ---- | ------------- |
| language | string | Yes   | Valid language ID, for example, **zh**.|
| region   | string | No   | Valid region ID, for example, **CN**.<br>The default value is the country/region of the SIM card. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Whether a language is a suggested language. The value **true** indicates that the language is a suggested language of the region, the the value false indicates the opposite.|

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
    let isSuggestedCountry: boolean = i18n.System.isSuggested('zh', 'CN'); // isSuggestedCountry = true
    isSuggestedCountry = i18n.System.isSuggested('en'); // Check whether a language is a suggested language for the current system region.
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.isSuggested failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLanguage<sup>9+</sup>

static getSystemLanguage(): string

Obtains the current system language.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Language ID.|

**Example**
  ```ts
  let systemLanguage: string = i18n.System.getSystemLanguage();
  ```

### getSystemRegion<sup>9+</sup>

static getSystemRegion(): string

Obtains the current system country/region.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Country/region ID.|

**Example**
  ```ts
  let systemRegion: string = i18n.System.getSystemRegion();
  ```

### getSystemLocale<sup>9+</sup>

static getSystemLocale(): string

Obtains the current system locale.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Locale ID.|

**Example**
  ```ts
  let systemLocale: string = i18n.System.getSystemLocale();
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
| boolean | Whether the 24-hour clock is used. The value **true** indicates that the 24-hour clock is used, the the value **false** means the opposite.|

**Example**
  ```ts
  let is24HourClock: boolean = i18n.System.is24HourClock();
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
  let preferredLanguageList: Array<string> = i18n.System.getPreferredLanguageList();
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
  let firstPreferredLanguage: string = i18n.System.getFirstPreferredLanguage();
  ```

### setAppPreferredLanguage<sup>11+</sup>

static setAppPreferredLanguage(language: string): void

Sets the preferred language of the application. Resources are loaded in the preferred language when the application is launched. If the preferred language is set to **default**, the application's language will be the same as the system language, and the setting will take effect upon cold starting of the application.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description   |
| -------- | ------ | ---- | ----- |
| language | string | Yes   | Valid language ID or **default**.|

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
    i18n.System.setAppPreferredLanguage('zh');
  } catch (error) {
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
  let appPreferredLanguage: string = i18n.System.getAppPreferredLanguage();
  ```


### getUsingLocalDigit<sup>9+</sup>

static getUsingLocalDigit(): boolean

Checks whether use of local digits is enabled.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Whether use of local digits is enabled. The value **true** indicates that use of local digits is enabled, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let usingLocalDigit: boolean = i18n.System.getUsingLocalDigit();
  ```

### getSimplifiedLanguage<sup>15+</sup>

static getSimplifiedLanguage(language?: string): string

Obtains the simplified representation of a language. For example, the simplified representation of **en-Latn-US** is **en**, and that of **en-Latn-GB** is **en-GB**.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description           |
| -------- | ------ | ---- | ------------- |
| language | string | No   | Valid language ID. The default value is the system language.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| string | If **language** is not passed, the application checks for dialects supported by the system based on the system language and locale. If such a dialect is found, the simplified representation of the dialect is returned. Otherwise, the simplified representation of the system language is returned.<br>If **language** is passed, the simplified representation of the specified language is returned.|

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
    // simplifiedLanguage = 'zh'
    let simplifiedLanguage: string = i18n.System.getSimplifiedLanguage('zh-Hans-CN');
    // Obtain the simplified representation of the current system language.
    let simplifiedSystemLanguage: string = i18n.System.getSimplifiedLanguage();
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSimplifiedLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getTemperatureType<sup>18+</sup>

static getTemperatureType(): TemperatureType

Obtains the temperature unit of the system.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description           |
| ------ | ------------- |
| [TemperatureType](#temperaturetype18) | Temperature unit.|

**Example**
  ```ts
  let temperatureType: i18n.TemperatureType = i18n.System.getTemperatureType();
  ```

### getTemperatureName<sup>18+</sup>

static getTemperatureName(type: TemperatureType): string

Obtains the name of a temperature unit.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description           |
| -------- | ------ | ---- | ------------- |
| type| [TemperatureType](#temperaturetype18) | Yes   | Temperature unit.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| string | Name of the temperature unit, which can be **celsius**, **fahrenheit**, and **kelvin**.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |


> **Description**
>
> The error message of 890001 is subject to the actual error.

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // temperatureName = 'celsius'
    let temperatureName: string = i18n.System.getTemperatureName(i18n.TemperatureType.CELSIUS);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getTemperatureName failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getFirstDayOfWeek<sup>18+</sup>

static getFirstDayOfWeek(): WeekDay

Obtains the first day of a week in the system settings.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description           |
| ------ | ------------- |
| [WeekDay](#weekday18) | Start day of a week.|

**Example**
  ```ts
  let firstDayOfWeek: i18n.WeekDay = i18n.System.getFirstDayOfWeek();
  ```

## TemperatureType<sup>18+</sup>

Enumerates temperature units.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

| Name| Value| Description|
| -------- | -------- | -------- |
| CELSIUS | 1 | Celsius.|
| FAHRENHEIT | 2 | Fahrenheit.|
| KELVIN | 3 | Kelvin.|

## WeekDay<sup>18+</sup>

Enumerates the first day of a week. The value ranges from Monday to Sunday.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

| Name| Value| Description|
| -------- | -------- | -------- |
| MON | 1 | Monday.|
| TUE | 2 | Tuesday.|
| WED | 3 | Wednesday.|
| THU | 4 | Thursday.|
| FRI | 5 | Friday.|
| SAT | 6 | Saturday.|
| SUN | 7 | Sunday.|


## i18n.isRTL

isRTL(locale: string): boolean

Checks whether a language is an RTL language. For an RTL language, [UI mirroring](../../internationalization/i18n-ui-design.md#ui-mirroring) is required.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| locale | string | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Whether a language is an RTL language. The value **true** indicates that the language is an RTL language, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isZhRTL: boolean = i18n.isRTL('zh-CN'); // Since Chinese is not written from right to left, false is returned.
  let isArRTL: boolean = i18n.isRTL('ar-EG'); // Since Arabic is written from right to left, true is returned.
  ```

## i18n.getCalendar<sup>8+</sup>

getCalendar(locale: string, type? : string): Calendar

Obtains the **Calendar** object for the specified locale and calendar type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | [Locale ID](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region, for example, **zh-Hans-CN**.                |
| type   | string | No   | Calendar. The value can be buddhist,&nbsp;chinese,&nbsp;coptic,&nbsp;ethiopic,&nbsp;hebrew,&nbsp;gregory,&nbsp;indian,&nbsp;islamic_civil,&nbsp;islamic_tbla,&nbsp;islamic_umalqura,&nbsp;japanese,&nbsp; or persian.<br>The default value is the default calendar of the locale. For details about the meanings and application scenarios of different values, see [Calendar Setting ](../../internationalization/i18n-calendar.md).|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [Calendar](#calendar8) | **Calendar** object.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans', 'chinese'); // Obtain the Calendar object for the Chinese lunar calendar.
  ```

## EntityRecognizer<sup>11+</sup>

### constructor<sup>11+</sup>

constructor(locale?: string)

Creates an **entityRecognizer** object. This object is used to recognize entities in the text for the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| locale | string | No   | [Locale ID](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region, for example, **zh-Hans-CN**.<br>The default value is the current system locale.|

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
    let entityRecognizer: i18n.EntityRecognizer = new i18n.EntityRecognizer('zh-CN');
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call new i18n.EntityRecognizer failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### findEntityInfo<sup>11+</sup>

findEntityInfo(text: string): Array&lt;EntityInfoItem&gt;

Obtains entity information in the **text** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| text | string | Yes   | **text** object.|

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
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let entityRecognizer: i18n.EntityRecognizer = new i18n.EntityRecognizer('zh-CN');
    let phoneNumberText: string = 'If you have any questions, call us by phone 12345678.';
    // phoneNumberEntity[0].type = 'phone_number', phoneNumberEntity[0].begin = 8, phoneNumberEntity[0].end = 19
    let phoneNumberEntity: Array<i18n.EntityInfoItem> = entityRecognizer.findEntityInfo(phoneNumberText);
    let dateText: string = 'Let's have dinner on December 1, 2023.';
    // dateEntity[0].type = 'date', dateEntity[0].begin = 2, dateEntity[0].end = 12
    let dateEntity: Array<i18n.EntityInfoItem> = entityRecognizer.findEntityInfo(dateText);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call EntityRecognizer.findEntityInfo failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## EntityInfoItem<sup>11+</sup>

Defines a list of entities.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name | Type  | Readable  | Writable  | Description               |
| ---- | ---- | ---- | ---- | ----------------- |
| type | string | Yes   | Yes   | Entity type. The value can be **phone_number** or **date**. **phone_number** indicates that the entity is a phone number, and **date** indicates that the entity is a date.|
| begin | number | Yes   | Yes   | Start position of the entity in the input string.|
| end | number | Yes   | Yes   | End position of the entity the input string.|

## Calendar<sup>8+</sup>

### setTime<sup>8+</sup>

setTime(date: Date): void

Sets the date and time for a **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| date | Date | Yes   | Date and time. Note: The month starts from **0**. For example, **0** indicates January.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('en-US', 'gregory');
  let date: Date = new Date(2021, 10, 7, 8, 0, 0); // The date and time is 2021.11.07 08:00:00.
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
| time | number | Yes   | Unix timestamp, which indicates the number of milliseconds that have elapsed since the Unix epoch.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('en-US', 'gregory');
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
| month  | number | Yes   | Month to set. Note: The month starts from **0**. For example, **0** indicates January. |
| date   | number | Yes   | Day to set. |
| hour   | number | No   | Hour to set. The default value is the current system time.|
| minute | number | No   | Minute to set. The default value is the current system time.|
| second | number | No   | Second to set. The default value is the current system time.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
  calendar.set(2021, 10, 1, 8, 0, 0); // Set the date and time to 2021.11.1 08:00:00.
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
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
  calendar.setTimeZone('Asia/Shanghai');
  ```


### getTimeZone<sup>8+</sup>

getTimeZone(): string

Obtains the time zone ID of this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Time zone ID.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
  calendar.setTimeZone('Asia/Shanghai');
  let timezone: string = calendar.getTimeZone(); // timezone = 'Asia/Shanghai'
  ```


### getFirstDayOfWeek<sup>8+</sup>

getFirstDayOfWeek(): number

Obtains the first day of a week for this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                   |
| ------ | --------------------- |
| number | First day of a week. The value **1** indicates Sunday, and the value **7** indicates Saturday.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('en-US', 'gregory');
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1
  ```


### setFirstDayOfWeek<sup>8+</sup>

setFirstDayOfWeek(value: number): void

Sets the first day of a week for this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                   |
| ----- | ------ | ---- | --------------------- |
| value | number | Yes   | Start day of a week. The value **1** indicates Sunday, and the value **7** indicates Saturday.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
  calendar.setFirstDayOfWeek(3);
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 3
  ```

### getMinimalDaysInFirstWeek<sup>8+</sup>

getMinimalDaysInFirstWeek(): number

Obtains the minimum number of days in the first week for this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description          |
| ------ | ------------ |
| number | Minimum number of days in the first week of a year.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 1
  ```


### setMinimalDaysInFirstWeek<sup>8+</sup>

setMinimalDaysInFirstWeek(value: number): void

Sets the minimum number of days in the first week for this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description          |
| ----- | ------ | ---- | ------------ |
| value | number | Yes   | Minimum number of days in the first week of a year.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
  calendar.setMinimalDaysInFirstWeek(3);
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 3
  ```


### get<sup>8+</sup>

get(field: string): number

Obtains the values of the calendar attributes in this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| field | string | Yes   | Calendar attributes. The following table lists the supported attribute values.|


| Name  | Description                                      |
| ----- | ---------------------------------------- |
| era | Era, for example, AD or BC.|
| year | Year.|
| month | Month. Note: The month starts from **0**. For example, **0** indicates January.|
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
| number | Value of the calendar attribute. For example, if the year of the internal date of the current **Calendar** object is 1990, **get('year')** returns **1990**.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
  calendar.set(2021, 10, 1, 8, 0, 0); // Set the date and time to 2021.11.1 08:00:00.
  let hourOfDay: number = calendar.get('hour_of_day'); // hourOfDay = 8
  ```


### getDisplayName<sup>8+</sup>

getDisplayName(locale: string): string

Obtains calendar display name in the specified language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Calendar display name in the specified language. For example, **buddhist** is displayed as **Buddhist Calendar** if the locale is **en-US**.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('en-US', 'buddhist');
  let calendarName: string = calendar.getDisplayName('zh'); // calendarName = 'Buddhist'
  ```


### isWeekend<sup>8+</sup>

isWeekend(date?: Date): boolean

Checks whether a given date is a weekend in this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | No   | Date and time. Note: The month starts from **0**. For example, **0** indicates January.<br>The default value is current date of the **Calendar** object.|

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| boolean | The value **true** indicates that the specified date is a weekend, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
  calendar.set(2021, 11, 11, 8, 0, 0); // Set the time to 2021.12.11 08:00:00.
  let isWeekend: boolean = calendar.isWeekend(); // isWeekend = true
  let date: Date = new Date(2011, 11, 6, 9, 0, 0); // The date and time is 2011-12-06 09:00:00.
  isWeekend = calendar.isWeekend(date); // isWeekend = false
  ```


### add<sup>11+</sup>

add(field: string, amount: number): void

Performs addition or subtraction on the calendar attributes of this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| field | string | Yes   | Calendar attribute. The value can be any of the following: **year**, **month**, **week_of_year**, **week_of_month**, **date**, **day_of_year**, **day_of_week**, **day_of_week_in_month**, **hour**, **hour_of_day**, **minute**, **second**, **millisecond**.<br>For details about the values, see [get](#get8).|
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
    let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
    calendar.set(2021, 11, 11, 8, 0, 0); // Set the date and time to 2021.12.11 08:00:00.
    calendar.add('year', 8); // 2021 + 8
    let year: number = calendar.get('year'); // year = 2029
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call Calendar.add failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getTimeInMillis<sup>11+</sup>

getTimeInMillis(): number

Obtains the timestamp of this **Calendar** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| number | Unix timestamp, which indicates the number of milliseconds that have elapsed since the Unix epoch.|

**Example**
  ```ts
  let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
  calendar.setTime(5000);
  let millisecond: number = calendar.getTimeInMillis(); // millisecond = 5000
  ```


### compareDays<sup>11+</sup>

compareDays(date: Date): number

Compares the current date of this **Calendar** object with the specified date for the difference in the number of days.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | Yes   | Date and time. Note: The month starts from **0**. For example, **0** indicates January.|

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| number | Difference in the number of days. A positive number indicates that the calendar date is earlier, and a negative number indicates the opposite.<br>The value is accurate to milliseconds. If the value is less than one day, it is considered as one day.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
    calendar.setTime(5000);
    let date: Date = new Date(6000);
    let diff: number = calendar.compareDays(date); // diff = 1
  } catch (error) {
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
| country | string                                   | Yes   | Country/region to which the phone number to be formatted belongs.|
| options | [PhoneNumberFormatOptions](#phonenumberformatoptions8) | No   | Options for **PhoneNumberFormat** object initialization. The default value is **NATIONAL**. |

**Example**
  ```ts
  let option: i18n.PhoneNumberFormatOptions = { type: 'E164' };
  let phoneNumberFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN', option);
  ```

### isValidNumber<sup>8+</sup>

isValidNumber(number: string): boolean

Checks whether the phone number is valid for the country/region in the **PhoneNumberFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description       |
| ------ | ------ | ---- | --------- |
| number | string | Yes   | Phone number to be checked.|

**Return value**

| Type     | Description                                   |
| ------- | ------------------------------------- |
| boolean | Whether the phone number is valid. The value **true** indicates that the phone number is valid, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let phonenumberfmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN');
  let isValidNumber: boolean = phonenumberfmt.isValidNumber('158****2312'); // isValidNumber = true
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
  let phonenumberfmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN');
  // formattedPhoneNumber = '158 **** 2312'
  let formattedPhoneNumber: string = phonenumberfmt.format('158****2312');

  // Format the phone number being dialed.
  let option: i18n.PhoneNumberFormatOptions = { type: 'TYPING' };
  let phoneNumberFmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN', option);
  let phoneNumber: string = '130493';
  let formatResult: string = '';
  for (let i = 0; i < phoneNumber.length; i++) {
    formatResult += phoneNumber.charAt(i);
    formatResult = phoneNumberFmt.format(formatResult); // formatResult = '130 493'
  }
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
| locale | string | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Home location of the phone number. If the number is invalid, an empty string is returned.|

**Example**
  ```ts
  let phonenumberfmt: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN');
  let locationName: string = phonenumberfmt.getLocationName('158****2345', 'zh-CN'); // locationName = 'Zhanjiang, Guangdong Province'
  let locName: string = phonenumberfmt.getLocationName('0039312****789', 'zh-CN'); // locName = 'Italy'
  ```


## PhoneNumberFormatOptions<sup>8+</sup>

Options for **PhoneNumberFormat** object initialization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name  | Type    | Readable  | Writable  | Description                                      |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | Yes   | Yes   | Type of the phone number. The value can be **E164**, **INTERNATIONAL**, **NATIONAL**, **RFC3966**, or **TYPING**.<br>- In API version 8, **type** is mandatory.<br>- In API version 9 or later, **type** is optional.<br>- In API version 12 or later, TYPING is supported, which indicates that the dialed number is formatted in real time.|


## UnitInfo<sup>8+</sup>

Defines the measurement unit information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name           | Type    | Readable  | Writable  | Description                                      |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| unit          | string | Yes   | Yes   | Name of the measurement unit, for example, **meter**, **inch**, or **cup**.|
| measureSystem | string | Yes   | Yes   | Measurement system. The value can be **SI**, **US**, or **UK**.|


## i18n.getInstance<sup>8+</sup>

getInstance(locale?: string): IndexUtil

Creates an **IndexUtil** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                          |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | No   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.<br>The default value is the current system locale.|

**Return value**

| Type                      | Description                   |
| ------------------------ | --------------------- |
| [IndexUtil](#indexutil8) | **IndexUtil** object created based on the specified locale ID.|

**Example**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance('zh-CN');
  ```


## IndexUtil<sup>8+</sup>


### getIndexList<sup>8+</sup>

getIndexList(): Array&lt;string&gt;

Obtains the index list of the current locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description                |
| ------------------- | ------------------ |
| Array&lt;string&gt; | Index list of the current locale. The first and last elements are **...**.|

**Example**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance('zh-CN');
  // indexList = [ '...', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
  //              'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '...' ]
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
| locale | string | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.|

**Example**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance('zh-CN');
  indexUtil.addLocale('en-US');
  ```

### getIndex<sup>8+</sup>

getIndex(text: string): string

Obtains the index of the **text** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| text | string | Yes   | **text** object.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Index of the **text** object. If no proper index is found, an empty string is returned.|

**Example**
  ```ts
  let indexUtil: i18n.IndexUtil = i18n.getInstance('zh-CN');
  let index: string = indexUtil.getIndex('hi'); // index = 'H'
  ```


## i18n.getLineInstance<sup>8+</sup>

getLineInstance(locale: string): BreakIterator

Obtains a **BreakIterator** object. The **BreakIterator** object maintains an internal break iterator that can be used to access various line break points.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.<br>The generated [BreakIterator](#breakiterator8) object calculates the positions of line breaks based on the rules of the specified locale.|

**Return value**

| Type                              | Description         |
| -------------------------------- | ----------- |
| [BreakIterator](#breakiterator8) | **BreakIterator** object.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
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
| text | string | Yes   | Input text.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  iterator.setLineBreakText('Apple is my favorite fruit.'); // Set the text to be processed.
  ```


### getLineBreakText<sup>8+</sup>

getLineBreakText(): string

Obtains the text processed by the **BreakIterator** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                    |
| ------ | ---------------------- |
| string | Text being processed by the **BreakIterator** object.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  iterator.setLineBreakText('Apple is my favorite fruit.');
  let breakText: string = iterator.getLineBreakText(); // breakText = 'Apple is my favorite fruit.'
  ```


### current<sup>8+</sup>

current(): number

Obtains the position of the break iterator in the text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                         |
| ------ | --------------------------- |
| number | Position of the break iterator in the text.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  iterator.setLineBreakText('Apple is my favorite fruit.');
  let currentPos: number = iterator.current(); // currentPos = 0
  ```


### first<sup>8+</sup>

first(): number

Moves the break iterator to the first line break point, which is always at the beginning of the processed text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description               |
| ------ | ----------------- |
| number | Offset of the first line break point in the processed text.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  iterator.setLineBreakText('Apple is my favorite fruit.');
  let firstPos: number = iterator.first(); // firstPos = 0
  ```


### last<sup>8+</sup>

last(): number

Moves the break iterator to the last line break point, which is always the next position after the end of the processed text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | Offset of the last line break point in the processed text.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  iterator.setLineBreakText('Apple is my favorite fruit.');
  let lastPos: number = iterator.last(); // lastPos = 27
  ```


### next<sup>8+</sup>

next(index?: number): number

Moves the break iterator backward by the specified number of line break points.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| index | number | No   | Number of line break points for moving the break iterator. The value is an integer.<br>A positive number means to move the break iterator backward, and a negative number means to move the break iterator forward.<br>The default value is **1**.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the break iterator in the text after movement.<br>The value **-1** is returned if the position of the break iterator is outside of the processed text after movement.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  iterator.setLineBreakText('Apple is my favorite fruit.');
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(); // pos = 6
  pos = iterator.next(10); // pos = -1
  ```


### previous<sup>8+</sup>

previous(): number

Moves the break iterator foreward by one line break point.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the break iterator in the text after movement.<br>The value **-1** is returned if the position of the break iterator is outside of the processed text after movement.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  iterator.setLineBreakText('Apple is my favorite fruit.');
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(3); // pos = 12
  pos = iterator.previous(); // pos = 9
  ```


### following<sup>8+</sup>

following(offset: number): number

Moves the line break iterator to the line break point after the specified position.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| offset | number | Yes   | Offset of the line break point.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the break iterator in the text after movement. The value **-1** is returned if the position of the break iterator is outside of the processed text after movement.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  iterator.setLineBreakText('Apple is my favorite fruit.');
  let pos: number = iterator.following(0); // pos = 6
  pos = iterator.following(100); // pos = -1
  pos = iterator.current(); // pos = 27
  ```


### isBoundary<sup>8+</sup>

isBoundary(offset: number): boolean

Checks whether the specified position is a line break point.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description         |
| ------ | ------ | ---- | ----------- |
| offset | number | Yes   | Specified position in the text.|

**Return value**

| Type     | Description                             |
| ------- | ------------------------------- |
| boolean | Whether the specified position is a line break point. The value **true** indicates that the specified position is a line break point, and the value **false** indicates the opposite.<br>If **true** is returned, the break iterator is moved to the position specified by **offset**. Otherwise, the break iterator is moved to the text line break point after the position specified by **offset**, which is equivalent to calling **following**.|

**Example**
  ```ts
  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  iterator.setLineBreakText('Apple is my favorite fruit.');
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
  let timezone: i18n.TimeZone = i18n.getTimeZone('Asia/Shanghai');
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
  let timezone: i18n.TimeZone = i18n.getTimeZone('Asia/Shanghai');
  let timezoneID: string = timezone.getID(); // timezoneID = 'Asia/Shanghai'
  ```


### getDisplayName

getDisplayName(locale?: string, isDST?: boolean): string

Obtains time zone display name in the specified language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type     | Mandatory  | Description                  |
| ------ | ------- | ---- | -------------------- |
| locale | string  | No   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region. The default value is the current system locale.               |
| isDST  | boolean | No   | Whether DST information is displayed. The value **true** indicates that DST information is displayed, and the value **false** indicates the opposite. The default value is **false**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Time zone display name in the specified language.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone('Asia/Shanghai');
  let timezoneName: string = timezone.getDisplayName('zh-CN', false); // timezoneName = 'China Standard Time'
  ```


### getRawOffset

getRawOffset(): number

Obtains the raw offset of the specified time zone.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| number | Raw offset of the time zone, in milliseconds.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone('Asia/Shanghai');
  let offset: number = timezone.getRawOffset(); // offset = 28800000
  ```


### getOffset

getOffset(date?: number): number

Obtains the offset of the specified time zone at the specified time.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| date | number | No   | Specified time, in milliseconds. The default value is the system time.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| number | Time zone offset, in milliseconds. When the DST is used, the time zone offset is the raw time zone offset plus the DST offset.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.getTimeZone('Asia/Shanghai');
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
  // ids = ['America/Adak', 'America/Anchorage', 'America/Bogota', 'America/Denver', 'America/Los_Angeles', 'America/Montevideo', 'America/Santiago', 'America/Sao_Paulo', 'Asia/Ashgabat', 'Asia/Hovd', 'Asia/Jerusalem', 'Asia/Magadan', 'Asia/Omsk', 'Asia/Shanghai', 'Asia/Tokyo', 'Asia/Yerevan', 'Atlantic/Cape_Verde', 'Australia/Lord_Howe', 'Europe/Dublin', 'Europe/London', 'Europe/Moscow', 'Pacific/Auckland', 'Pacific/Easter', 'Pacific/Pago-Pago']
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
  // cityIDs = ['Auckland', 'Magadan', 'Lord Howe Island', 'Tokyo', 'Shanghai', 'Hovd', 'Omsk', 'Ashgabat', 'Yerevan', 'Moscow', 'Tel Aviv', 'Dublin', 'London', 'Praia', 'Montevideo', 'Brasília', 'Santiago', 'Bogotá', 'Easter Island', 'Salt Lake City', 'Los Angeles', 'Anchorage', 'Adak', 'Pago Pago']
  let cityIDs: Array<string> = i18n.TimeZone.getAvailableZoneCityIDs();
  ```

### getCityDisplayName<sup>9+</sup>

static getCityDisplayName(cityID: string, locale: string): string

Obtains time zone city display name in the specified language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| cityID | string | Yes   | Time zone city ID.|
| locale | string | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region. |

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | Time zone city display name in the specified language.|

**Example**
  ```ts
  let displayName: string = i18n.TimeZone.getCityDisplayName('Shanghai', 'zh-CN'); // displayName = 'Shanghai (China)'
  ```


### getTimezoneFromCity<sup>9+</sup>

static getTimezoneFromCity(cityID: string): TimeZone

Creates a **TimeZone** object corresponding to the specified time zone city.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| cityID | string | Yes   | Time zone city ID. The value must be a time zone city ID supported by the system.|

**Return value**

| Type      | Description         |
| -------- | ----------- |
| TimeZone | **TimeZone** object corresponding to the specified time zone city ID.|

**Example**
  ```ts
  let timezone: i18n.TimeZone = i18n.TimeZone.getTimezoneFromCity('Shanghai');
  ```

### getTimezonesByLocation<sup>10+</sup>

static getTimezonesByLocation(longitude: number, latitude: number): Array&lt;TimeZone&gt;

Creates an array of **TimeZone** objects corresponding to the specified location.

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
| Array&lt;[TimeZone](#timezone)&gt; | **TimeZone** objects corresponding to the specified location.|

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
    let timezoneArray: Array<i18n.TimeZone> = i18n.TimeZone.getTimezonesByLocation(-118.1, 34.0);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call TimeZone.getTimezonesByLocation failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getZoneRules<sup>20+</sup>

getZoneRules(): ZoneRules

Obtains the time zone transition rules. For details about the time zone transition logic, see [DST Transition](../../internationalization/i18n-dst-transition.md).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| [ZoneRules](#zonerules20) | Time zone transition rule, including the transition time and the offset before and after the transition.|

**Example**
```ts
import { i18n } from '@kit.LocalizationKit';

let tzId: string = 'America/Tijuana';
let timeZone: i18n.TimeZone = i18n.getTimeZone(tzId);
let zoneRules: i18n.ZoneRules = timeZone.getZoneRules();
let date = new Date(2025, 4, 13);
let zoneOffsetTransition: i18n.ZoneOffsetTransition =
    zoneRules.nextTransition(date.getTime()); // Obtain the ZoneOffsetTransition object for time zone transition after May 13, 2025.
zoneOffsetTransition.getMilliseconds(); // Timestamp of the transition point: 1762074000000
zoneOffsetTransition.getOffsetAfter(); // Post-transition offset: -28800000
zoneOffsetTransition.getOffsetBefore(); // Pre-transition offset: -25200000
// Format the timestamp of the transition point.
let dateTimeFormat: Intl.DateTimeFormat = new Intl.DateTimeFormat('en-US', {
  timeZone: tzId,
  dateStyle: 'long',
  timeStyle: 'long',
  hour12: false
});
let dateFormat: string =
  dateTimeFormat.format(new Date(zoneOffsetTransition.getMilliseconds())); // November 2, 2025, 1:00:00 PST
```

## ZoneRules<sup>20+</sup>


### nextTransition<sup>20+</sup>

nextTransition(date?: number): ZoneOffsetTransition

Obtains the **nextTransition** object for the specified time.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| date | number | No   | Timestamp of next transition. It is measured as the number of milliseconds from 00:00:00 on January 1, 1970 (UTC) to the specified time, which defaults to the current system time.|

**Return value**

| Type      | Description        |
| -------- | ---------- |
| [ZoneOffsetTransition](#zoneoffsettransition20) | **nextTransition** object.|

**Example**
```ts
import { i18n } from '@kit.LocalizationKit';

// Obtain the time zone of Tijuana.
let timeZone: i18n.TimeZone = i18n.getTimeZone('America/Tijuana');
// Obtain the time zone transition rule of Tijuana.
let zoneRules: i18n.ZoneRules = timeZone.getZoneRules();
let date = new Date(2025, 4, 13);
// Obtain the next time zone transition for Tijuana after May 13, 2025.
let zoneOffsetTransition: i18n.ZoneOffsetTransition = zoneRules.nextTransition(date.getTime());
```

## ZoneOffsetTransition<sup>20+</sup>


### getMilliseconds<sup>20+</sup>

getMilliseconds(): number

Obtains the timestamp of the time zone transition point.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type      | Description        |
| -------- | ---------- |
| number | Timestamp of the time zone transition point. It is measured as the number of milliseconds from 00:00:00 on January 1, 1970 (UTC) to the time zone transition point, for example, 1762074000000.|

**Example**
```ts
import { i18n } from '@kit.LocalizationKit';

let timeZone: i18n.TimeZone = i18n.getTimeZone('America/Tijuana');
let zoneRules: i18n.ZoneRules = timeZone.getZoneRules();
let date = new Date(2025, 4, 13);
let zoneOffsetTransition: i18n.ZoneOffsetTransition =
    zoneRules.nextTransition(date.getTime()); // Obtain the ZoneOffsetTransition object for time zone transition after May 13, 2025.
zoneOffsetTransition.getMilliseconds(); // Timestamp of the transition point: 1762074000000
```

### getOffsetAfter<sup>20+</sup>

getOffsetAfter(): number

Obtains the offset after the time zone transition.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type      | Description        |
| -------- | ---------- |
| number | Post-transition offset, that is, the time difference between the post-transition time and UTC, measured in ms. For example, **-28800000** indicates that the time after the transition is 28800000 ms (8 hours) later than UTC.|

**Example**
```ts
import { i18n } from '@kit.LocalizationKit';

let timeZone: i18n.TimeZone = i18n.getTimeZone('America/Tijuana');
let zoneRules: i18n.ZoneRules = timeZone.getZoneRules();
let date = new Date(2025, 4, 13);
let zoneOffsetTransition: i18n.ZoneOffsetTransition =
    zoneRules.nextTransition(date.getTime()); // Obtain the ZoneOffsetTransition object for time zone transition after May 13, 2025.
zoneOffsetTransition.getOffsetAfter(); // Post-transition offset: -28800000
```

### getOffsetBefore<sup>20+</sup>

getOffsetBefore(): number

Obtains the offset before the time zone transition.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type      | Description        |
| -------- | ---------- |
| number | Pre-transition offset, that is, the time difference between the pre-transition time and UTC, measured in ms. For example, **-25200000** indicates that the pre-transition time is 25200000 ms (7 hours) slower than UTC.|

**Example**
```ts
import { i18n } from '@kit.LocalizationKit';

let timeZone: i18n.TimeZone = i18n.getTimeZone('America/Tijuana');
let zoneRules: i18n.ZoneRules = timeZone.getZoneRules();
let date = new Date(2025, 4, 13);
let zoneOffsetTransition: i18n.ZoneOffsetTransition =
    zoneRules.nextTransition(date.getTime()); // Obtain the ZoneOffsetTransition object for time zone transition after May 13, 2025.
zoneOffsetTransition.getOffsetBefore(); // Pre-transition offset: -25200000
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

Creates a **Transliterator** object based on the specified ID.

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
  let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance('Any-Latn');
  ```


### transform<sup>9+</sup>

transform(text: string): string

Converts the input text from the source format to the target format.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description    |
| ---- | ------ | ---- | ------ |
| text | string | Yes   | **text** object.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Text after conversion.|

**Example**
  ```ts
  let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance('Any-Latn');
  let wordArray = ['China', 'Germany', 'US', 'France"]
  for (let i = 0; i < wordArray.length; i++) {
    let transliterLatn =
      transliterator.transform(wordArray[i]); // transliterLatn: 'zhōng guó', 'dé guó', 'měi guó', 'fǎ guó'
  }

  // Chinese transliteration and tone removal
  let transliter = i18n.Transliterator.getInstance('Any-Latn;Latin-Ascii');
  let transliterAscii = transliter.transform('中国'); // transliterAscii ='zhong guo'

  // Chinese surname pronunciation
  let nameTransliter = i18n.Transliterator.getInstance('Han-Latin/Names');
  let transliterNames = nameTransliter.transform('单老师'); // transliterNames = 'shàn lǎo shī'
  transliterNames = nameTransliter.transform('长孙无忌'); // transliterNames = 'zhǎng sūn wú jì'
  ```


## Unicode<sup>9+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

### isDigit<sup>9+</sup>

static isDigit(char: string): boolean

Checks whether the input character is a digit.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | **true** if the input character is a digit, and **false** otherwise.|

**Example**
  ```ts
  let isDigit: boolean = i18n.Unicode.isDigit('1'); // isDigit = true
  ```


### isSpaceChar<sup>9+</sup>

static isSpaceChar(char: string): boolean

Checks whether the input character is a space.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | **true** if the input character is a space, and **false** otherwise.|

**Example**
  ```ts
  let isSpacechar: boolean = i18n.Unicode.isSpaceChar('a'); // isSpacechar = false
  ```


### isWhitespace<sup>9+</sup>

static isWhitespace(char: string): boolean

Checks whether the input character is a whitespace.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | **true** if the input character is a white space, and **false** otherwise.|

**Example**
  ```ts
  let isWhitespace: boolean = i18n.Unicode.isWhitespace('a'); // isWhitespace = false
  ```


### isRTL<sup>9+</sup>

static isRTL(char: string): boolean

Checks whether the input character is of the right to left (RTL) language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character is of the RTL language, and **false** otherwise.|

**Example**
  ```ts
  let isRtl: boolean = i18n.Unicode.isRTL('a'); // isRtl = false
  ```


### isIdeograph<sup>9+</sup>

static isIdeograph(char: string): boolean

Checks whether the input character is an ideographic character.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character an ideographic character, and **false** otherwise.|

**Example**
  ```ts
  let isIdeograph: boolean = i18n.Unicode.isIdeograph('a'); // isIdeograph = false
  ```


### isLetter<sup>9+</sup>

static isLetter(char: string): boolean

Checks whether the input character is a letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | **true** if the input character a letter, and **false** otherwise.|

**Example**
  ```ts
  let isLetter: boolean = i18n.Unicode.isLetter('a'); // isLetter = true
  ```


### isLowerCase<sup>9+</sup>

static isLowerCase(char: string): boolean

Checks whether the input character is a lowercase letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character a lowercase letter, and **false** otherwise.|

**Example**
  ```ts
  let isLowercase: boolean = i18n.Unicode.isLowerCase('a'); // isLowercase = true
  ```


### isUpperCase<sup>9+</sup>

static isUpperCase(char: string): boolean

Checks whether the input character is an uppercase letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character an uppercase letter, and **false** otherwise.|

**Example**
  ```ts
  let isUppercase: boolean = i18n.Unicode.isUpperCase('a'); // isUppercase = false
  ```


### getType<sup>9+</sup>

static getType(char: string): string

Obtains the type of the input character.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

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
  let unicodeType: string = i18n.Unicode.getType('a'); // unicodeType = 'U_LOWERCASE_LETTER'
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
| locale   | string                 | Yes   | [Locale ID](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region, for example, **zh-Hans-CN**.               |
| style    | string                 | No   | Style used for formatting. The value can be **long**, **short**, or **narrow**. The default value is **short**.<br>For details about the meaning or display effect of different values, see [Number and Unit of Measurement Formatting](../../internationalization/i18n-numbers-weights-measures.md).|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| string | String converted to the measurement unit after formatting.|

**Example**
  ```ts
  let fromUnit: i18n.UnitInfo = { unit: 'cup', measureSystem: 'US' };
  let toUnit: i18n.UnitInfo = { unit: 'liter', measureSystem: 'SI' };
  let convertResult: string =
    i18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, 'en-US', 'long'); // convertResult = '236.588 liters'
  ```

### getDateOrder<sup>9+</sup>

static getDateOrder(locale: string): string

Obtains the sequence of the year, month, and day in the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| locale | string | Yes   | [Locale ID](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region, for example, **zh-Hans-CN**.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Sequence of the year, month, and day in the locale. **y** indicates the year, **L** indicates the month, and **d** indicates the day.|

**Example**
  ```ts
  let order: string = i18n.I18NUtil.getDateOrder('zh-CN'); // order = 'y-L-d'
  ```


### getTimePeriodName<sup>11+</sup>

static getTimePeriodName(hour:number, locale?: string): string

Obtains the localized expression of the specified time in the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| hour | number | Yes   | Specified time, for example, **16**.|
| locale | string | No   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region. for example, **zh-Hans-CN**.<br>The default value is the current system locale.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Localized expression of the specified time in the specified locale.|

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
    let name: string = i18n.I18NUtil.getTimePeriodName(2, 'zh-CN'); // name = 'a.m.'
  } catch (error) {
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
| locale | string | Yes   | [Locale ID](../../internationalization/i18n-locale-culture.md#how-it-works), for example, **zh-Hans-CN**.|
| localeList | string[] | Yes  | List of locale IDs.|

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
    let matchedLocaleId: string = i18n.I18NUtil.getBestMatchLocale('zh-Hans-CN',
      ['en-Latn-US', 'en-GB', 'zh-Hant-CN', 'zh-Hans-MO']); // matchedLocaleId = 'zh-Hans-MO'
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call I18NUtil.getBestMatchLocale failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getThreeLetterLanguage<sup>12+</sup>

static getThreeLetterLanguage(locale: string): string

Converts a language code from two letters to three letters.  <br>For example, the two-letter language code of Chinese is **zh**, and the corresponding three-letter language code is **zho**. For details, see [ISO 639](https://www.iso.org/iso-639-language-code).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| locale | string | Yes  | Two-letter code of the language to be converted, for example, **zh**.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Language code after conversion.|

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
    let language: string = i18n.I18NUtil.getThreeLetterLanguage('zh') // language = 'zho'
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call I18NUtil.getThreeLetterLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getThreeLetterRegion<sup>12+</sup>

static getThreeLetterRegion(locale: string): string

Converts a region code from two letters to three letters.  <br>For example, the two-letter region code of China is **CN**, and the corresponding three-letter region code is **CHN**. For details, see [ISO 3166](https://www.iso.org/iso-3166-country-codes.html).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| locale | string | Yes  | Two-letter country/region code to be converted, for example, **CN**.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Region code after conversion .|

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
    let region: string = i18n.I18NUtil.getThreeLetterRegion('CN') // region = 'CHN'
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call I18NUtil.getThreeLetterRegion failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getUnicodeWrappedFilePath<sup>20+</sup>

static getUnicodeWrappedFilePath(path: string, delimiter?: string, locale?: Intl.Locale): string

Localizes a file path for the specified locale.<br>For example, **/data/out/tmp** is changed to **tmp/out/data/** after localization.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| path | string | Yes  | Path to mirror, for example, **/data/out/tmp**.|
| delimiter | string | No  | Path delimiter. The default value is **/**.|
| locale | [Intl.Locale](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | No  | **Locale** object. The default value is the current system locale.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | File path after localization. If the specified locale object corresponds to an RTL language, the processed file path contains a direction control character to ensure that the file path is displayed in mirror mode.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 890001   | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let path: string = '/data/out/tmp';
  let delimiter: string = '/';
  let locale: Intl.Locale = new Intl.Locale('ar');
  let mirrorPath: string =
    i18n.I18NUtil.getUnicodeWrappedFilePath(path, delimiter, locale); // mirrorPath is displayed as tmp/out/data/.
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call I18NUtil.getUnicodeWrappedFilePath failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getUnicodeWrappedFilePath<sup>(deprecated)</sup>

static getUnicodeWrappedFilePath(path: string, delimiter?: string, locale?: intl.Locale): string

This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getUnicodeWrappedFilePath](#getunicodewrappedfilepath20).

Localizes a file path for the specified locale.<br>For example, **/data/out/tmp** is changed to **tmp/out/data/** after localization.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| path | string | Yes  | Path to mirror, for example, **/data/out/tmp**.|
| delimiter | string | No  | Path delimiter. The default value is **/**.|
| locale | [intl.Locale](./js-apis-intl.md#localedeprecated) | No  | **Locale** object. The default value is the current system locale.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | File path after localization. If the specified locale object corresponds to an RTL language, the processed file path contains a direction control character to ensure that the file path is displayed in mirror mode.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 890001   | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { intl } from '@kit.LocalizationKit';

try {
  let path: string = '/data/out/tmp';
  let delimiter: string = '/';
  let locale: intl.Locale = new intl.Locale('ar');
  let mirrorPath: string =
    i18n.I18NUtil.getUnicodeWrappedFilePath(path, delimiter, locale); // mirrorPath is displayed as tmp/out/data/.
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call I18NUtil.getUnicodeWrappedFilePath failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## Normalizer<sup>10+</sup>


### getInstance<sup>10+</sup>

static getInstance(mode: NormalizerMode): Normalizer

Obtains a **Normalizer** object.

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
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let normalizer: i18n.Normalizer = i18n.Normalizer.getInstance(i18n.NormalizerMode.NFC);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call Normalizer.getInstance failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### normalize<sup>10+</sup>

normalize(text: string): string

Normalizes input strings.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| text | string | Yes   | **text** object.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Normalized strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let normalizer: i18n.Normalizer = i18n.Normalizer.getInstance(i18n.NormalizerMode.NFC);
    let normalizedText: string = normalizer.normalize('\u1E9B\u0323'); // normalizedText = 'ẛ̣'
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call Normalizer.getInstance failed, error code: ${err.code}, message: ${err.message}.`);
  }
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

Creates a **HolidayManager** object for parsing holiday data.

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
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let holidayManager = new i18n.HolidayManager('/system/lib/US.ics');
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call i18n.HolidayManager failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### isHoliday<sup>11+</sup>

isHoliday(date?: Date): boolean

Determines whether the specified date is a holiday.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ---------------| ---- | ------------- |
| date      | Date           | No  | Date and time. Note: The month starts from **0**. For example, **0** indicates January.<br>The default value is the current date.|

**Return value**

|       Type       |         Description         |
| ----------------- | ----------------------|
| boolean           | **true** if the specified date is a holiday, and **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace /system/lib/US.ics with the actual ICS file path.
    let holidayManager: i18n.HolidayManager = new i18n.HolidayManager('/system/lib/US.ics');
    let isHoliday: boolean = holidayManager.isHoliday();
    isHoliday = holidayManager.isHoliday(new Date(2023, 5, 25)); // The date is 2023.06.25.
  } catch (error) {
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
| year      | number         | No  | Specified year, for example, 2023.<br>The default value is the current year.|

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
    // Replace /system/lib/US.ics with the actual ICS file path.
    let holidayManager: i18n.HolidayManager = new i18n.HolidayManager('/system/lib/US.ics');
    let holidayInfoItemArray: Array<i18n.HolidayInfoItem> = holidayManager.getHolidayInfoItemArray(2023);
  } catch (error) {
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

Represents the name of a holiday in different languages.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Mandatory  |  Description                                  |
| --------------- | -----------------| ------  | --------------------------------------- |
| language        | string           |   Yes   | Language, for example, **ar**, **en**, or **tr**.         |
| name            | string           |   Yes   | Local name of a holiday. For example, the Turkish name of Sacrifice Feast is Kurban Bayrami.     |


## i18n.getSimpleDateTimeFormatByPattern<sup>20+</sup>

getSimpleDateTimeFormatByPattern(pattern: string, locale?: Intl.Locale): SimpleDateTimeFormat

Obtains a **SimpleDateTimeFormat** object based on the specified pattern string. For details about the difference between the objects obtained by this API and [getSimpleDateTimeFormatBySkeleton](#i18ngetsimpledatetimeformatbyskeleton20), see the examples in [SimpleDateTimeFormat.format](#format18).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------- | ----------- | ----- | ---------------------------------------- |
| pattern | string      | Yes   | Valid pattern, which supports free combinations of field patterns in [Date Field Symbol Table](https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table). This parameter also supports custom text enclosed in single quotation marks (`''`).|
| locale  | [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | No   | **Locale** object. The default value is the current system locale.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [SimpleDateTimeFormat](#simpledatetimeformat18) | **SimpleDateTimeFormat** object.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let locale: Intl.Locale = new Intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatByPattern("'month('M')'", locale);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call i18n.getSimpleDateTimeFormatByPattern failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## i18n.getSimpleDateTimeFormatByPattern<sup>(deprecated)</sup>

getSimpleDateTimeFormatByPattern(pattern: string, locale?: intl.Locale): SimpleDateTimeFormat

This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getSimpleDateTimeFormatByPattern](#i18ngetsimpledatetimeformatbypattern20).

Obtains a **SimpleDateTimeFormat** object based on the specified pattern string. For details about the difference between the objects obtained by this API and [getSimpleDateTimeFormatBySkeleton](#i18ngetsimpledatetimeformatbyskeletondeprecated), see the examples in [SimpleDateTimeFormat.format](#format18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------- | ----------- | ----- | ---------------------------------------- |
| pattern | string      | Yes   | Valid pattern, which supports free combinations of field patterns in [Date Field Symbol Table](https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table). This parameter also supports custom text enclosed in single quotation marks (`''`).|
| locale  | [intl.Locale](./js-apis-intl.md#localedeprecated) | No   | **Locale** object. The default value is the current system locale.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [SimpleDateTimeFormat](#simpledatetimeformat18) | **SimpleDateTimeFormat** object.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { intl } from '@kit.LocalizationKit';

try {
  let locale: intl.Locale = new intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatByPattern("'month('M')'", locale);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call i18n.getSimpleDateTimeFormatByPattern failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## i18n.getSimpleDateTimeFormatBySkeleton<sup>20+</sup>

getSimpleDateTimeFormatBySkeleton(skeleton: string, locale?: Intl.Locale): SimpleDateTimeFormat

Obtains a **SimpleDateTimeFormat** object based on the specified skeleton. For details about the difference between the objects obtained by this API and [getSimpleDateTimeFormatByPattern](#i18ngetsimpledatetimeformatbypattern20), see the examples in [SimpleDateTimeFormat.format](#format18).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------- | ----------- | ----- | ---------------------------------------- |
| skeleton | string      | Yes   | Valid skeleton, which supports free combinations of field patterns in [Date Field Symbol Table](https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table). This parameter does not support custom text.|
| locale  | [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | No   | **Locale** object. The default value is the current system locale.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [SimpleDateTimeFormat](#simpledatetimeformat18) | **SimpleDateTimeFormat** object.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let locale: Intl.Locale = new Intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatBySkeleton('yMd', locale);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call i18n.getSimpleDateTimeFormatBySkeleton failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## i18n.getSimpleDateTimeFormatBySkeleton<sup>(deprecated)</sup>

getSimpleDateTimeFormatBySkeleton(skeleton: string, locale?: intl.Locale): SimpleDateTimeFormat

This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getSimpleDateTimeFormatBySkeleton](#i18ngetsimpledatetimeformatbyskeleton20).

Obtains a **SimpleDateTimeFormat** object based on the specified skeleton. For details about the difference between the objects obtained by this API and [getSimpleDateTimeFormatByPattern](#i18ngetsimpledatetimeformatbypatterndeprecated), see the examples in [SimpleDateTimeFormat.format](#format18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------- | ----------- | ----- | ---------------------------------------- |
| skeleton | string      | Yes   | Valid skeleton, which supports free combinations of field patterns in [Date Field Symbol Table](https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table). This parameter does not support custom text.|
| locale  | [intl.Locale](./js-apis-intl.md#localedeprecated) | No   | **Locale** object. The default value is the current system locale.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [SimpleDateTimeFormat](#simpledatetimeformat18) | **SimpleDateTimeFormat** object.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { intl } from '@kit.LocalizationKit';

try {
  let locale: intl.Locale = new intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatBySkeleton('yMd', locale);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call i18n.getSimpleDateTimeFormatBySkeleton failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## SimpleDateTimeFormat<sup>18+</sup>

### format<sup>18+</sup>

format(date: Date): string

Formats the date and time.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| date | Date | Yes   | Date and time. Note: The month starts from **0**. For example, **0** indicates January.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | A string containing the formatted date and time.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let locale : Intl.Locale = new Intl.Locale("zh-Hans-CN");
    let date: Date = new Date(2024, 11, 13); // Set the date to 2024.12.13.

    let formatterWithText: i18n.SimpleDateTimeFormat =
      i18n.getSimpleDateTimeFormatByPattern("'month('M')'", locale);
    let formattedDate: string = formatterWithText.format(date); // formattedDate = 'month(12)'

    let patternFormatter: i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatByPattern('yMd', locale);
    formattedDate = patternFormatter.format(date); // formattedDate = '20241213'

    let skeletonFormatter: i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatBySkeleton('yMd', locale);
    formattedDate = skeletonFormatter.format(date); // formattedDate = '2024/12/13'
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call SimpleDateTimeFormat.format failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


## i18n.getSimpleNumberFormatBySkeleton<sup>20+</sup>

getSimpleNumberFormatBySkeleton(skeleton: string, locale?: Intl.Locale): SimpleNumberFormat

Obtains a **SimpleNumberFormat** object based on the specified skeleton.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------- | ----------- | ----- | ---------------------------------------- |
| skeleton | string      | Yes   | Valid skeleton. For details about the supported characters and their meanings, see [Number Skeletons](https://unicode-org.github.io/icu/userguide/format_parse/numbers/skeletons.html#number-skeletons).|
| locale  | [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | No   | **Locale** object. The default value is the current system locale.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [SimpleNumberFormat](#simplenumberformat18) | **SimpleNumberFormat** object.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let locale: Intl.Locale = new Intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleNumberFormat = i18n.getSimpleNumberFormatBySkeleton('%', locale);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call SimpleDateTimeFormat.getSimpleNumberFormatBySkeleton failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## i18n.getSimpleNumberFormatBySkeleton<sup>(deprecated)</sup>

getSimpleNumberFormatBySkeleton(skeleton: string, locale?: intl.Locale): SimpleNumberFormat

This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getSimpleNumberFormatBySkeleton](#i18ngetsimplenumberformatbyskeleton20).

Obtains a **SimpleNumberFormat** object based on the specified skeleton.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------- | ----------- | ----- | ---------------------------------------- |
| skeleton | string      | Yes   | Valid skeleton. For details about the supported characters and their meanings, see [Number Skeletons](https://unicode-org.github.io/icu/userguide/format_parse/numbers/skeletons.html#number-skeletons).|
| locale  | [intl.Locale](./js-apis-intl.md#localedeprecated) | No   | **Locale** object. The default value is the current system locale.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [SimpleNumberFormat](#simplenumberformat18) | **SimpleNumberFormat** object.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { intl } from '@kit.LocalizationKit';

try {
  let locale: intl.Locale = new intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleNumberFormat = i18n.getSimpleNumberFormatBySkeleton('%', locale);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call SimpleDateTimeFormat.getSimpleNumberFormatBySkeleton failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## SimpleNumberFormat<sup>18+</sup>

### format<sup>18+</sup>

format(value: number): string

Formats a number.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| value | number | Yes   | Number to be formatted.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | Formatted number.|

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let locale: Intl.Locale = new Intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleNumberFormat = i18n.getSimpleNumberFormatBySkeleton('%', locale);
  let formattedNumber: string = formatter.format(10); // formattedNumber = '10%'
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call SimpleNumberFormat.format failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## StyledNumberFormat<sup>18+</sup>

### constructor<sup>18+</sup>

constructor(numberFormat: intl.NumberFormat | SimpleNumberFormat, options?: StyledNumberFormatOptions)

Creates a **NumberFormat** object for rich text display.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| numberFormat | [intl.NumberFormat](js-apis-intl.md#numberformat) \| [SimpleNumberFormat](#simplenumberformat18) | Yes  | **NumberFormat** object. |
| options | [StyledNumberFormatOptions](#stylednumberformatoptions18) | No| Configuration options of the **NumberFormat** object. The default value is the default text style. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { intl } from '@kit.LocalizationKit';

  try {
    let integerTextStyle: TextStyle = new TextStyle({ fontColor: Color.Red });
    let decimalTextStyle: TextStyle = new TextStyle({ fontColor: Color.Brown });
    let fractionTextStyle: TextStyle = new TextStyle({ fontColor: Color.Blue });
    let unitTextStyle: TextStyle = new TextStyle({ fontColor: Color.Green });

    // Create a StyledNumberFormat object through intl.NumberFormat.
    let numFmt: intl.NumberFormat = new intl.NumberFormat('zh', { style: 'unit', unit: 'percent' });
    let styledNumFmt: i18n.StyledNumberFormat = new i18n.StyledNumberFormat(numFmt, {
      integer: integerTextStyle,
      decimal: decimalTextStyle,
      fraction: fractionTextStyle,
      unit: unitTextStyle
    });

    // Create a StyledNumberFormat object through SimpleNumberFormat.
    let locale: intl.Locale = new intl.Locale('zh');
    let simpleNumFmt: i18n.SimpleNumberFormat = i18n.getSimpleNumberFormatBySkeleton('percent', locale);
    let styledSimpleNumFmt: i18n.StyledNumberFormat = new i18n.StyledNumberFormat(simpleNumFmt, {
      integer: integerTextStyle,
      decimal: decimalTextStyle,
      fraction: fractionTextStyle,
      unit: unitTextStyle
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call i18n.StyledNumberFormat failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### format<sup>18+</sup>

format(value: number): StyledString

Formats a number as a rich text object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| value | number | Yes| Number to be formatted. |

**Return value**

|       Type       |         Description         |
| ----------------- | ----------------------|
| [StyledString](../apis-arkui/arkui-ts/ts-universal-styled-string.md#styledstring) | Rich text object after formatting.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { intl } from '@kit.LocalizationKit';

  try {
    let integerTextStyle: TextStyle = new TextStyle({ fontColor: Color.Red });
    let decimalTextStyle: TextStyle = new TextStyle({ fontColor: Color.Brown });
    let fractionTextStyle: TextStyle = new TextStyle({ fontColor: Color.Blue });
    let unitTextStyle: TextStyle = new TextStyle({ fontColor: Color.Green });

    // Create a StyledNumberFormat object through intl.NumberFormat.
    let numFmt: intl.NumberFormat = new intl.NumberFormat('zh', { style: 'unit', unit: 'percent' });
    let styledNumFmt: i18n.StyledNumberFormat = new i18n.StyledNumberFormat(numFmt, {
      integer: integerTextStyle,
      decimal: decimalTextStyle,
      fraction: fractionTextStyle,
      unit: unitTextStyle
    });
    // formattedNumber.getString () is 1,234.568%. In the formatted number, 1,234 is in red, . in brown, 568 in blue, and % in green.
    let formattedNumber: StyledString = styledNumFmt.format(1234.5678);

    // Create a StyledNumberFormat object through SimpleNumberFormat.
    let locale: intl.Locale = new intl.Locale('zh');
    let simpleNumFmt: i18n.SimpleNumberFormat = i18n.getSimpleNumberFormatBySkeleton('percent', locale);
    let styledSimpleNumFmt: i18n.StyledNumberFormat = new i18n.StyledNumberFormat(simpleNumFmt, {
      integer: integerTextStyle,
      decimal: decimalTextStyle,
      fraction: fractionTextStyle,
      unit: unitTextStyle
    });
    // formattedSimpleNumber.getString () is 1,234.5678%. In the formatted number, '1,234' is in red, . in brown, 5678 in blue, and % in green.
    let formattedSimpleNumber: StyledString = styledSimpleNumFmt.format(1234.5678);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call StyledNumberFormat.format failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## StyledNumberFormatOptions<sup>18+</sup>

Represents optional configuration items for the **NumberFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Mandatory  |  Description                                  |
| --------------- | --------------- | ------  | --------------------------------------- |
| integer        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |  Text style for the integer part. The default value is the default text style.    |
| decimal        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |  Text style for the decimal point. The default value is the default text style.   |
| fraction       | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |  Text style for the fraction part. The default value is the default text style.    |
| unit           | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |  Text style for the unit. The default value is the default text style.    |

## i18n.getDisplayCountry<sup>(deprecated)</sup>

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

Obtains the localized name of the specified country/region.

This API is deprecated since API version 9. You are advised to use [System.getDisplayCountry](#getdisplaycountry9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | Yes   | Specified country.           |
| locale       | string  | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.     |
| sentenceCase | boolean | No   | Whether to use sentence case to display the text. The value **true** means to display the text in title case format, and the value **false** means to display the text in the default case format of the locale. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified country.|

**Example**
  ```ts
  let countryName: string = i18n.getDisplayCountry('zh-CN', 'en-GB', true); // countryName = 'China'
  countryName = i18n.getDisplayCountry('zh-CN', 'en-GB'); // countryName = 'China'
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
| locale       | string  | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.     |
| sentenceCase | boolean | No   | Whether to use sentence case to display the text. The value **true** means to display the text in title case format, and the value **false** means to display the text in the default case format of the locale. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified language.|

**Example**
  ```ts
  let languageName: string = i18n.getDisplayLanguage('zh', 'en-GB', true); // languageName = 'Chinese'
  languageName = i18n.getDisplayLanguage('zh', 'en-GB'); // languageName = 'Chinese'
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
  let systemLanguage: string = i18n.getSystemLanguage();
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
  let region: string = i18n.getSystemRegion();
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
  let locale: string = i18n.getSystemLocale();
  ```


## i18n.is24HourClock<sup>(deprecated)</sup>

is24HourClock(): boolean

Checks whether the 24-hour clock is used.

This API is deprecated since API version 9. You are advised to use [System.is24HourClock](#is24hourclock9).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the 24-hour clock is used, and **false** otherwise.|

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
| boolean | **true** if the setting is successful, and **false** otherwise.|

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
| boolean | **true** if the operation is successful, and **false** otherwise.|

**Example**
  ```ts
  // Add zh-CN to the preferred language list.
  let language: string = 'zh-CN';
  let index: number = 0;
  let success: boolean = i18n.addPreferredLanguage(language, index);
  ```


## i18n.removePreferredLanguage<sup>(deprecated)</sup>

removePreferredLanguage(index: number): boolean

Removes a preferred language from the specified position on the preferred language list.

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
| boolean | Whether the operation is successful. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

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
  let preferredLanguageList: Array<string> = i18n.getPreferredLanguageList();
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
| locale   | string                 | Yes   | Locale ID used for formatting, for example, **zh-Hans-CN**.               |
| style    | string                 | No   | Style used for formatting. The value can be **long**, **short**, or **narrow**. The default value is **short**.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| string | String obtained after formatting based on the measurement unit specified by **toUnit**.|


## Character<sup>(deprecated)</sup>


### isDigit<sup>(deprecated)</sup>

isDigit(char: string): boolean

Checks whether the input character is a digit.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isDigit](#isdigit9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | **true** if the input character is a digit, and **false** otherwise.|


### isSpaceChar<sup>(deprecated)</sup>

isSpaceChar(char: string): boolean

Checks whether the input character is a space.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isSpaceChar](#isspacechar9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | **true** if the input character is a space, and **false** otherwise.|


### isWhitespace<sup>(deprecated)</sup>

isWhitespace(char: string): boolean

Checks whether the input character is a whitespace.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isWhitespace](#iswhitespace9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | **true** if the input character is a white space, and **false** otherwise.|


### isRTL<sup>(deprecated)</sup>

isRTL(char: string): boolean

Checks whether the input character is of the right to left (RTL) language.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isRTL](#isrtl9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character is of the RTL language, and **false** otherwise.|


### isIdeograph<sup>(deprecated)</sup>

isIdeograph(char: string): boolean

Checks whether the input character is an ideographic character.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isIdeograph](#isideograph9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character an ideographic character, and **false** otherwise.|


### isLetter<sup>(deprecated)</sup>

isLetter(char: string): boolean

Checks whether the input character is a letter.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isLetter](#isletter9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | **true** if the input character a letter, and **false** otherwise.|


### isLowerCase<sup>(deprecated)</sup>

isLowerCase(char: string): boolean

Checks whether the input character is a lowercase letter.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isLowerCase](#islowercase9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character a lowercase letter, and **false** otherwise.|


### isUpperCase<sup>(deprecated)</sup>

isUpperCase(char: string): boolean

Checks whether the input character is an uppercase letter.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isUpperCase](#isuppercase9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character an uppercase letter, and **false** otherwise.|


### getType<sup>(deprecated)</sup>

getType(char: string): string

Obtains the type of the input character.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [getType](#gettype9).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Type of the input character.|


<!--no_check-->