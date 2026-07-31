# @ohos.i18n (Internationalization)

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=f86c324189946cdd73af5fa71703997419ec43ae translatedAt=2026-07-31T01:30:00.306Z pushedAt=2026-07-31T01:58:40.602Z -->

This module provides system-related and enhanced [i18n](../../internationalization/i18n-l10n.md) capabilities, such as locale management, phone number formatting, and calendar, through supplementary i18n APIs that are not defined in [ECMA 402](https://dev.ecma-international.org/publications-and-standards/standards/ecma-402/). The [Internationalization](js-apis-intl.md) module provides basic i18n APIs defined in ECMA 402. It works with this module to provide a complete suite of i18n capabilities. The terms used in the APIs are defined as follows:

- Pattern string: a string that consists of [Unicode date field symbols](https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table) and custom text enclosed by single quotation marks.

- Skeleton string: a string that consists of [Unicode date field symbols](https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table) and does not support custom text.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs of this module are based on the [CLDR](https://cldr.unicode.org) internationalization database. The processing results of the APIs may be adjusted as the CLDR standard evolves. For example, the return value of the date and time formatting API is used only for UI display. Do not hardcode the return value or make assumptions about the return value. Otherwise, version compatibility problems may occur. API version 12 corresponds to [CLDR 42](https://cldr.unicode.org/downloads/cldr-42). For details about data changes, see the [official CLDR documentation](https://cldr.unicode.org/).
>
>  - Since API version 11, some APIs of this module are supported in ArkTS widgets.

## Modules to Import

```ts
import { i18n } from '@kit.LocalizationKit';
```

## System<sup>9+</sup>

Provides system attribute configuration functions, including translating language and country/region names, obtaining the list of supported languages and countries/regions, and obtaining the system language and region.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.I18n

### getDisplayCountry<sup>9+</sup>

static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

Obtains the country/region display name in the specified language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | Yes   | Valid country/region code. For details, see [System Locale](../../internationalization/i18n-locale-culture.md#how-it-works).           |
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
  import { i18n } from '@kit.LocalizationKit';

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
| language     | string  | Yes   | Valid language ID. For details, see [System Locale](../../internationalization/i18n-locale-culture.md#how-it-works).           |
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
  import { i18n } from '@kit.LocalizationKit';

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

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Array&lt;string&gt; | List of system languages.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

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
| language | string | Yes   | [Valid language ID](../../internationalization/i18n-locale-culture.md#how-it-works).|

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Array&lt;string&gt; | List of countries/regions supported for the language specified by **language**.|

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
  import { i18n } from '@kit.LocalizationKit';

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
| language | string | Yes   | [Valid language ID](../../internationalization/i18n-locale-culture.md#how-it-works), for example, **zh**.|
| region   | string | No   | [Valid country/region code](../../internationalization/i18n-locale-culture.md#how-it-works), for example, **CN**.<br>The default value is the country/region of the SIM card. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Whether a language is a suggested language. The value **true** indicates yes, and the value **false** indicates no.|

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
  import { i18n } from '@kit.LocalizationKit';

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

Obtains the current system language. To listen for system language changes, enable listening for [COMMON_EVENT_LOCALE_CHANGED](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_locale_changed). For details, see [System Language and Region](../../internationalization/i18n-system-language-region.md#how-to-develop).

**Atomic service API**: This API can be used in atomic services since API version 11.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Language ID.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let systemLanguage: string = i18n.System.getSystemLanguage(); // If the system language is simplified Chinese, then systemLanguage is 'zh-Hans'.
  ```

### getSystemRegion<sup>9+</sup>

static getSystemRegion(): string

Obtains the current system country/region. To listen for system locale changes, enable listening for [COMMON_EVENT_LOCALE_CHANGED](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_locale_changed). For details, see [System Language and Region](../../internationalization/i18n-system-language-region.md#how-to-develop).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Country/region ID.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let systemRegion: string = i18n.System.getSystemRegion(); // If the system region is China, then systemRegion is CN.
  ```

### getSystemLocale<sup>(deprecated)</sup>

static getSystemLocale(): string

> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [System.getSystemLocaleInstance](#getsystemlocaleinstance20) instead.

Obtains the current system locale.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Locale ID.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let systemLocale: string = i18n.System.getSystemLocale(); // If the system language is simplified Chinese and the system region is China, then systemLocale is zh-Hans-CN.
  ```

### getSystemLocaleInstance<sup>20+</sup>

static getSystemLocaleInstance(): Intl.Locale

Obtains the current system locale. To listen for system locale changes, enable listening for [COMMON_EVENT_LOCALE_CHANGED](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_locale_changed). For details, see [System Language and Region](../../internationalization/i18n-system-language-region.md#how-to-develop).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | System locale.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let systemLocale: Intl.Locale = i18n.System.getSystemLocaleInstance();
  ```

### is24HourClock<sup>9+</sup>

static is24HourClock(): boolean

Checks whether the 24-hour clock is used. To listen for system time format changes, enable listening for [COMMON_EVENT_TIME_CHANGED](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_time_changed). For details, see [User Preference](../../internationalization/i18n-user-preferences.md#how-to-develop).

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Whether the 24-hour clock is used. The value **true** indicates that the 24-hour clock is used, and the value **false** indicates that the 12-hour clock is used.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let is24HourClock: boolean = i18n.System.is24HourClock(); // If the 24-hour clock is used, then is24HourClock is true.
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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
| language | string | Yes   | [Valid language ID](../../internationalization/i18n-locale-culture.md#how-it-works) or **default**.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
| language | string | No   | [Valid language ID](../../internationalization/i18n-locale-culture.md#how-it-works). The default value is the system language.|

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

  let isZhRTL: boolean = i18n.isRTL('zh-CN'); // Since Chinese is not written from right to left, false is returned.
  let isArRTL: boolean = i18n.isRTL('ar-EG'); // Since Arabic is written from right to left, true is returned.
  ```

## EntityRecognizer<sup>11+</sup>

Provides entity recognition capabilities, which can be used to obtain the type and start and end positions of an entity in the text. Currently, supported entities include phone numbers, and date and time.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

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
  import { i18n } from '@kit.LocalizationKit';

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
| text | string | Yes   | Input text.|

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
  import { i18n } from '@kit.LocalizationKit';

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

| Name | Type  | Read-Only  | Optional  | Description               |
| ---- | ---- | ---- | ---- | ----------------- |
| type | string | No   | No   | Entity type. The value can be **phone_number** or **date**. **phone_number** indicates that the entity is a phone number, and **date** indicates that the entity is a date.|
| begin | number | No   | No   | Start position of the entity in the input string.|
| end | number | No   | No   | End position of the entity the input string.|

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
| [Calendar](#calendar) | **Calendar** object.|

**Example**

```ts
let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans', 'chinese'); // Obtain the Calendar object for the Chinese lunar calendar.
```

## Calendar

Provides calendar management capabilities, such as calendar name retrieval and date calculation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

### setTime<sup>8+</sup>

setTime(date: Date): void

Sets the date and time for a **Calendar** object based on the input **Date** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| date | Date | Yes | Date and time.<br>**NOTE**<br>The month starts from **0**, indicating January. |

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let calendar: i18n.Calendar = i18n.getCalendar('en-US', 'gregory');
  let date: Date = new Date(2021, 10, 7, 8, 0, 0); // The date and time is 2021.11.07 08:00:00.
  calendar.setTime(date);
  ```

### setTime<sup>8+</sup>

setTime(time: number): void

Sets the date and time for a **Calendar** object based on the input timestamp.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| time | number | Yes   | Unix timestamp, which indicates the number of milliseconds that have elapsed since the Unix epoch.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

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
| month  | number | Yes    | Month to set.<br>**NOTE**<br>The month starts from **0**, indicating January.  |
| date   | number | Yes   | Day to set. |
| hour   | number | No    | Hour to set. The default value is the system time. |
| minute | number | No    | Minute to set. The default value is the system time. |
| second | number | No    | Second to set. The default value is the system time. |

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
| field | string | Yes   | Calendar attributes, including:<br>**era**: Era, for example, BC or AD in the Gregorian calendar.<br>**year**: Year.<br>**month**: Month, counting from 0 (indicating January).<br>**date**: Day.<br>**hour**: Wall-clock hour.<br>**hour_of_day**: Hour of the day.<br>**minute**: Minute.<br>**second**: Second.<br>**millisecond**: Millisecond.<br>**week_of_year**: Week of the year, calculated based on weeks. The determination of the first week varies by region.<br>**year_woy**: Week of the year, calculated numerically. For example, days 1–7 of the year belong to the first week.<br>**week_of_month**: Week of the month, calculated based on weeks.<br>**day_of_week_in_month**: Week of the month, calculated numerically. For example, days 1–7 belong to the first week.<br>**day_of_year**: Day of the year.<br>**day_of_week**: Day of the week.<br>**milliseconds_in_day**: Millisecond of the day.<br>**zone_offset**: Fixed time zone offset in milliseconds (excluding daylight saving time).<br>**dst_offset**: Daylight saving time offset in milliseconds. <br>**dow_local**: Localized day of the week.<br>**extended_year**: Extended year value. Negative numbers are supported.<br>**julian_day**: Julian day, relative to the current time zone.<br>**is_leap_month**: Whether a month is a leap month. The value **1** indicates yes and the value **0** indicates no.<br>|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Value of the calendar attribute. For example, if the year of the internal date of the current **Calendar** object is 1990, **get('year')** returns **1990**.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
| date | Date | No | Date and time.<br>**NOTE**<br>The month starts from **0**, indicating January.<br>The default value is current date of the **Calendar** object. |

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| boolean | The value **true** indicates that the specified date is a weekend, and the value **false** indicates the opposite.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
| date | Date | Yes | Date and time.<br>**NOTE**<br>The month starts from **0**, indicating January. |

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
  import { i18n } from '@kit.LocalizationKit';

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

## i18n.getChineseCalendar

getChineseCalendar(locale?: Intl.Locale): ChineseCalendar

Obtains the lunar calendar object of a specified region.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | No  | **Locale** object. The default value is the current system locale.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [ChineseCalendar](#chinesecalendar) | Lunar calendar object.|

**Example**

```ts
let locale: Intl.Locale = i18n.System.getSystemLocaleInstance();
let calendar: i18n.ChineseCalendar = i18n.getChineseCalendar(locale);
```

## ChineseCalendar

Provides lunar calendar capabilities, including setting the lunar calendar time and checking whether a month in a specified year is a leap month. This API inherits from [Calendar](#calendar) and supports methods of [Calendar](#calendar).

### setChineseCalendarTime

setChineseCalendarTime(chineseCalendarTime: ChineseCalendarTime): void

Sets the date and time for a lunar calendar object.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| chineseCalendarTime | [ChineseCalendarTime](#chinesecalendar) | Yes   | Lunar calendar time object.|

**Example**

```ts
let locale: Intl.Locale = i18n.System.getSystemLocaleInstance();
let calendar: i18n.ChineseCalendar = i18n.getChineseCalendar(locale);
calendar.setChineseCalendarTime({
  gregorianYear: 2026,
  cyclicalYear: 43,
  month: 1,
  date: 15
});
```

### checkLeapMonth

static checkLeapMonth(gregorianYear: number, cyclicalYear: number, month: number): boolean

Checks whether a month in a specified year is a leap month.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| gregorianYear   | number |   Yes   |  Year in the Gregorian calendar.<br>Value range: [1900, 2100].   |
| cyclicalYear    | number |   Yes   |  Stem-branch year in the lunar calendar.<br>Value range: [1, 60].   |
| month           | number |   Yes   |  Month in the lunar calendar.<br>**NOTE**<br>The month starts from **0**, indicating January.   |

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| boolean | Whether a month is a leap month. The value **true** indicates yes and the value **false** indicates no.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 8900001   | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

```ts
let isExist = i18n.ChineseCalendar.checkLeapMonth(2026, 43, 2);
```

## ChineseCalendarTime

Describes the lunar calendar time object.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | ------- | ------- | ------- | --------------------------------------- |
| gregorianYear   | number |   No   |   No   |  Year in the Gregorian calendar.<br>Value range: [1900, 2100]   |
| cyclicalYear    | number |   No   |   No   |  Stem-branch year in the lunar calendar.<br>Value range: [1, 60]   |
| month           | number |   No   |   No   |  Month in the lunar calendar.<br>**NOTE**<br>The month starts from **0**, indicating January.   |
| date            | number |   No  |   No  |  Date in the lunar calendar.  |
| isLeapMonth     | boolean |   No |   Yes  |  Whether a month is a leap month. The default value is **false**. |
| hour            | number |   No  |   Yes  |  Hour in the lunar calendar. The default value is **0**.  |
| minute          | number |   No  |   Yes  |  Minute in the lunar calendar. The default value is **0**.  |
| second          | number |   No  |   Yes  |  Second in the lunar calendar. The default value is **0**.  |

## PhoneNumberFormat<sup>8+</sup>

Provides phone number management capabilities, such as phone number validity verification, formatting, and home location retrieval.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

### constructor<sup>8+</sup>

constructor(country: string, options?: PhoneNumberFormatOptions)

Creates a **PhoneNumberFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type                                      | Mandatory  | Description              |
| ------- | ---------------------------------------- | ---- | ---------------- |
| country | string                                   | Yes   | Country/Region code of the phone number. For details, see [Locale ID](../../internationalization/i18n-locale-culture.md#how-it-works).|
| options | [PhoneNumberFormatOptions](#phonenumberformatoptions8) | No   | Options for **PhoneNumberFormat** object initialization. The default value is **NATIONAL**. |

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let option: i18n.PhoneNumberFormatOptions = { type: 'E164' };
  let phoneNumberFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN', option);
  ```

### isValidNumber<sup>8+</sup>

isValidNumber(phoneNumber: string): boolean

Checks whether the phone number is valid for the country/region in the **PhoneNumberFormat** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description       |
| ------ | ------ | ---- | --------- |
| phoneNumber | string | Yes   | Phone number to be checked.|

**Return value**

| Type     | Description                                   |
| ------- | ------------------------------------- |
| boolean | Whether the phone number is valid. The value **true** indicates that the phone number is valid, and the value **false** indicates the opposite.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let formatter: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN');
  let isValidNumber: boolean = formatter.isValidNumber('158****2312'); // isValidNumber = true
  ```

### format<sup>8+</sup>

format(phoneNumber: string): string

Formats a phone number.

> **Description**
> Formatting dialed phone numbers is supported since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description        |
| ------ | ------ | ---- | ---------- |
| phoneNumber | string | Yes   | Phone number to be formatted.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Formatted phone number.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let formatter: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN');
  // formattedPhoneNumber = '158 **** 2312'
  let formattedPhoneNumber: string = formatter.format('158****2312');

  // Format the phone number being dialed.
  let option: i18n.PhoneNumberFormatOptions = { type: 'TYPING' };
  let typingFormatter: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN', option);
  let phoneNumber: string = '130493';
  let formatResult: string = '';
  for (let i = 0; i < phoneNumber.length; i++) {
    formatResult += phoneNumber.charAt(i);
    formatResult = typingFormatter.format(formatResult); // formatResult = '130 493'
  }
  ```

### getLocationName<sup>9+</sup>

getLocationName(phoneNumber: string, locale: string): string

Obtains the home location of a phone number.

> **Description**
> This API can be used to obtain the home location of a dialed number in real time since API version 23.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description  |
| ------ | ------ | ---- | ---- |
| phoneNumber | string | Yes   | Phone number. To obtain the home location of a number in other countries/regions, you need to prefix the number with **00** and the country code.|
| locale | string | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Home location of the phone number. If the number is invalid, an empty string is returned.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  // Obtain the home location of the complete phone number.
  let phonenumberFormat: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN');
  let locationName: string = phonenumberFormat.getLocationName('158****2345', 'zh-CN'); // locationName = 'Zhanjiang, Guangdong Province'
  let locName: string = phonenumberFormat.getLocationName('0039312****789', 'zh-CN'); // locName = 'Italy'

  // Obtain the home area of the phone number being dialed.
  let option: i18n.PhoneNumberFormatOptions = { type: 'TYPING' };
  let typingFormatter: i18n.PhoneNumberFormat = new i18n.PhoneNumberFormat('CN', option);
  let formatResult = typingFormatter.getLocationName('1', 'en'); // formatResult = ''
  formatResult = typingFormatter.getLocationName('13', 'en'); // formatResult = 'China'
  formatResult = typingFormatter.getLocationName('133', 'en'); // formatResult = 'China'
  formatResult = typingFormatter.getLocationName('1334', 'en'); // formatResult = 'China'
  formatResult = typingFormatter.getLocationName('13342', 'en'); // formatResult = 'China'
  formatResult = typingFormatter.getLocationName('133426', 'en'); // formatResult = 'Dongguan, Guangdong'
  ```

## PhoneNumberFormatOptions<sup>8+</sup>

Options for **PhoneNumberFormat** object initialization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name  | Type    | Read-Only  | Optional  | Description                                      |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | No   | Yes   | Type of the phone number. The value can be **E164**, **INTERNATIONAL**, **NATIONAL**, **RFC3966**, or **TYPING**.<br>- In API version 8, **type** is mandatory.<br>- In API version 9 or later, **type** is optional.<br>- In API version 12 or later, TYPING is supported, which indicates that the dialed number is formatted in real time.<br>- In API version 23 or later, TYPING supports real-time obtaining of the home location of a dialed number.|

## UnitInfo<sup>8+</sup>

Defines the measurement unit information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name           | Type    | Read-Only  | Optional  | Description                                      |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| unit          | string | No   | No   | Name of the measurement unit, for example, **meter**, **inch**, or **cup**.|
| measureSystem | string | No   | No   | Measurement system. The value can be **SI**, **US**, or **UK**.|

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
  import { i18n } from '@kit.LocalizationKit';

  let indexUtil: i18n.IndexUtil = i18n.getInstance('zh-CN');
  ```

## IndexUtil<sup>8+</sup>

Provides index management capabilities, such as obtaining the locale index list and text index values.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

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
  import { i18n } from '@kit.LocalizationKit';

  let indexUtil: i18n.IndexUtil = i18n.getInstance('zh-CN');
  // indexList = [ '...', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
  // 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '...' ]
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
  import { i18n } from '@kit.LocalizationKit';

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
| text | string | Yes   | Input text.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Index of the **text** object. If no proper index is found, an empty string is returned.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let indexUtil: i18n.IndexUtil = i18n.getInstance('zh-CN');
  let index: string = indexUtil.getIndex('hi'); // index = 'H'
  ```

## i18n.getLineInstance<sup>8+</sup>

getLineInstance(locale: string): BreakIterator

Obtains a **BreakIterator** object for locating line break points in text. This object maintains an internal break iterator that can be used to access each line break points.

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
  import { i18n } from '@kit.LocalizationKit';

  let iterator: i18n.BreakIterator = i18n.getLineInstance('en');
  ```

## BreakIterator<sup>8+</sup>

Provides text line breaking capabilities, such as obtaining, moving, and identifying break points.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

  let timezone: i18n.TimeZone = i18n.getTimeZone('Asia/Shanghai');
  ```

## TimeZone

Provides time zone management capabilities, such as time zone name translation, offset retrieval, and transition rule retrieval.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
| number | Raw offset of the time zone, in milliseconds. |

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

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
| date | number | No | Time for calculating the time zone offset, in milliseconds. The default value is the system time. |

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| number | Offset of the time zone, in milliseconds. When the DST is used, the time zone offset is the raw time zone offset plus the DST offset. |

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
    zoneRules.nextTransition(date.getTime()); // Obtain the nextTransition object for time zone transition after May 13, 2025.
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

### isDaylightSavingTime

isDaylightSavingTime(date: Date): boolean

Checks whether the specified date and time is in the daylight saving time.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| date   | Date   | Yes   | Date and time.<br>**NOTE**<br>The month starts from **0**, indicating January.|

**Return value**

| Type      | Description        |
| -------- | ---------- |
| boolean | Whether the daylight saving time is enabled. The value **true** indicates yes, and the value **false** indicates no.|

**Example**

```ts
let timezone: i18n.TimeZone = i18n.getTimeZone('Asia/Shanghai');
let isDST = timezone.isDaylightSavingTime(new Date(2026, 3, 15));
```

### setAppDefaultTimeZoneById

static setAppDefaultTimeZoneById(zoneID: string): void

Sets the default time zone for the current application, which is valid throughout the application's runtime.

> **NOTE**
>
> During date and time formatting, the default time zone set by the application will be used if no time zone is specified.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| zoneID | string | Yes  | Default time zone ID set by the application, for example, **Asia/Shanghai**.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 8900001   | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let zoneID: string = 'Asia/Shanghai';
  i18n.TimeZone.setAppDefaultTimeZoneById(zoneID);
  console.info('setAppDefaultTimeZoneById success.');
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call TimeZone.setAppDefaultTimeZoneById failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getAppDefaultTimeZone

static getAppDefaultTimeZone(): TimeZone

Obtains the default time zone object used by an application. If the default time zone has been set by calling [setAppDefaultTimeZoneById](#setappdefaulttimezonebyid), the default time zone object is returned. Otherwise, the system time zone object is returned.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| TimeZone | Default time zone object used by the application.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let zoneID: string = 'Asia/Shanghai';
  i18n.TimeZone.setAppDefaultTimeZoneById(zoneID);
  console.info('setAppDefaultTimeZoneById success.');
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call TimeZone.setAppDefaultTimeZoneById failed, error code: ${err.code}, message: ${err.message}.`);
}
let timeZone: i18n.TimeZone = i18n.TimeZone.getAppDefaultTimeZone();
let id: string = timeZone.getID();
console.info(`getAppDefaultTimeZone success, time zone id: ${id}`);
```

## ZoneRules<sup>20+</sup>

Queries the time zone transition rule.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

### nextTransition<sup>20+</sup>

nextTransition(date?: number): ZoneOffsetTransition

Obtains the **nextTransition** object for the specified time.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| date | number | No | Number of milliseconds from January 1, 1970, 00:00:00 UTC to the specified time.<br>The default value is the system time. |

**Return value**

| Type      | Description        |
| -------- | ---------- |
| [ZoneOffsetTransition](#zoneoffsettransition20) | **ZoneOffsetTransition** object for next transition.|

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

Parses the time zone transition rule.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

### getMilliseconds<sup>20+</sup>

getMilliseconds(): number

Obtains the timestamp of the time zone transition point.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type      | Description        |
| -------- | ---------- |
| number | Number of milliseconds from January 1, 1970, 00:00:00 UTC to the time zone transition point, in milliseconds, for example, **1762074000000**. If the [raw offset](#getrawoffset) remains unchanged and DST is not used, **0** is returned. |

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let timeZone: i18n.TimeZone = i18n.getTimeZone('America/Tijuana');
let zoneRules: i18n.ZoneRules = timeZone.getZoneRules();
let date = new Date(2025, 4, 13);
let zoneOffsetTransition: i18n.ZoneOffsetTransition =
    zoneRules.nextTransition(date.getTime()); // Obtain the nextTransition object for time zone transition after May 13, 2025.
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
| number | Offset after the time zone transition, representing the time difference between the post-transition time and UTC, in milliseconds. For example, **-28800000** indicates that the post‑transition time is 28,800,000 milliseconds (8 hours) behind UTC. |

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let timeZone: i18n.TimeZone = i18n.getTimeZone('America/Tijuana');
let zoneRules: i18n.ZoneRules = timeZone.getZoneRules();
let date = new Date(2025, 4, 13);
let zoneOffsetTransition: i18n.ZoneOffsetTransition =
    zoneRules.nextTransition(date.getTime()); // Obtain the nextTransition object for time zone transition after May 13, 2025.
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
| number | Offset before the time zone transition, representing the time difference between the pre-transition time and UTC, in milliseconds. For example, **-25200000** indicates that the pre-transition time is 25200000 ms (7 hours) behind UTC. |

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let timeZone: i18n.TimeZone = i18n.getTimeZone('America/Tijuana');
let zoneRules: i18n.ZoneRules = timeZone.getZoneRules();
let date = new Date(2025, 4, 13);
let zoneOffsetTransition: i18n.ZoneOffsetTransition =
    zoneRules.nextTransition(date.getTime()); // Obtain the nextTransition object for time zone transition after May 13, 2025.
zoneOffsetTransition.getOffsetBefore(); // Pre-transition offset: -25200000
```

## Transliterator<sup>9+</sup>

Provides text transliteration capabilities, such as obtaining the supported language IDs and transliterating text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

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
  import { i18n } from '@kit.LocalizationKit';

  // A total number of 742 IDs are supported. Each ID is in *source*-*destination* format. For example, in **ids = ['Han-Latin','Latin-ASCII', 'Amharic-Latin/BGN','Accents-Any', ...]**, **Han-Latin** indicates conversion from Chinese to Latin, and **Amharic-Latin** indicates conversion from Amharic to Latin.
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
  import { i18n } from '@kit.LocalizationKit';

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
| text | string | Yes   | Input text.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Text after conversion.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance('Any-Latn');
  let wordArray: string[] = ['China', 'Germany', 'US', 'France"]
  for (let i = 0; i < wordArray.length; i++) {
    let transliterateLatn: string =
      transliterator.transform(wordArray[i]); // transliterateLatn: 'zhōng guó', 'dé guó', 'měi guó', 'fǎ guó'
  }

  // Chinese transliteration and tone removal
  transliterator = i18n.Transliterator.getInstance('Any-Latn;Latin-Ascii');
  let transliterateAscii: string = transliterator.transform ('China'); // transliterateAscii = 'zhong guo'

  // Chinese surname pronunciation
  transliterator = i18n.Transliterator.getInstance('Han-Latin/Names');
  let transliterateNames: string = transliterator.transform('Teacher Shan'); // transliterateNames = 'shàn lǎo shī'
  transliterateNames = transliterator.transform('Long Sun No Taboo'); // transliterateNames = 'zhǎng sūn wú jì'
  ```

## Unicode<sup>9+</sup>

Provides character attribute management capabilities, such as checking whether a character is a space, digit, or letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

### isDigit<sup>9+</sup>

static isDigit(ch: string): boolean

Checks whether the input character is a digit.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | **true** if the input character is a digit, and **false** otherwise.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let isDigit: boolean = i18n.Unicode.isDigit('1'); // isDigit = true
  ```

### isSpaceChar<sup>9+</sup>

static isSpaceChar(ch: string): boolean

Checks whether the input character is a space.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | **true** if the input character is a space, and **false** otherwise.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let isSpacechar: boolean = i18n.Unicode.isSpaceChar('a'); // isSpacechar = false
  ```

### isWhitespace<sup>9+</sup>

static isWhitespace(ch: string): boolean

Checks whether the input character is a whitespace character.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | **true** if the input character is a white space, and **false** otherwise.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let isWhitespace: boolean = i18n.Unicode.isWhitespace('a'); // isWhitespace = false
  ```

### isRTL<sup>9+</sup>

static isRTL(ch: string): boolean

Checks whether the input character is of the right to left (RTL) language.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character is of the RTL language, and **false** otherwise.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let isRtl: boolean = i18n.Unicode.isRTL('a'); // isRtl = false
  ```

### isIdeograph<sup>9+</sup>

static isIdeograph(ch: string): boolean

Checks whether the input character is an ideographic character.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character an ideographic character, and **false** otherwise.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let isIdeograph: boolean = i18n.Unicode.isIdeograph('a'); // isIdeograph = false
  ```

### isLetter<sup>9+</sup>

static isLetter(ch: string): boolean

Checks whether the input character is a letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | **true** if the input character a letter, and **false** otherwise.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let isLetter: boolean = i18n.Unicode.isLetter('a'); // isLetter = true
  ```

### isLowerCase<sup>9+</sup>

static isLowerCase(ch: string): boolean

Checks whether the input character is a lowercase letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character a lowercase letter, and **false** otherwise.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let isLowercase: boolean = i18n.Unicode.isLowerCase('a'); // isLowercase = true
  ```

### isUpperCase<sup>9+</sup>

static isUpperCase(ch: string): boolean

Checks whether the input character is an uppercase letter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character an uppercase letter, and **false** otherwise.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let isUppercase: boolean = i18n.Unicode.isUpperCase('a'); // isUppercase = false
  ```

### getType<sup>9+</sup>

static getType(ch: string): string

Obtains the type of the input character.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Type of the input character. The options are as follows:<br>**U_UNASSIGNED**: Category for unassigned and non-character code points.<br>**U_GENERAL_OTHER_TYPES**: Same as **U_UNASSIGNED**.<br>**U_UPPERCASE_LETTER**: Uppercase letter.<br>**U_LOWERCASE_LETTER**: Lowercase letter.<br>**U_TITLECASE_LETTER**: Title case letter.<br>**U_MODIFIER_LETTER**: Modifier letter.<br>**U_OTHER_LETTER**: Letter other than the uppercase letter, lowercase letter, title case letter, and modifier letter.<br>**U_NON_SPACING_MARK**: Non-spacing mark, such as the accent symbol **'** and the variable symbol **#**.<br>**U_ENCLOSING_MARK**: Enclosing mark, for example, a circle or a box.<br>**U_COMBINING_SPACING_MARK**: Spacing mark, for example, the vowel symbol **[]**.<br>**U_DECIMAL_DIGIT_NUMBER**: Decimal number.<br>**U_LETTER_NUMBER**: Alphanumeric and Roman numeral.<br>**U_OTHER_NUMBER**: Other numbers used as encryption symbols or marker symbols, or non-Arabic numerals, such as **@**, **#**, **(1)**, and **①**.<br>**U_SPACE_SEPARATOR**: Whitespace separator, for example, space character, non-breaking space character, or fixed-width space character.<br>**U_LINE_SEPARATOR**: Line separator.<br>**U_PARAGRAPH_SEPARATOR**: Paragraph separator.<br>**U_CONTROL_CHAR**: Control character.<br>**U_FORMAT_CHAR**: Format character.<br>**U_PRIVATE_USE_CHAR**: Privately used character, for example, a company logo.<br>**U_SURROGATE**: Surrogate, which is used to represent supplementary characters in UTF-16.<br>**U_DASH_PUNCTUATION**: Dash punctuation.<br>**U_START_PUNCTUATION**: Start punctuation, for example, the left parenthesis.<br>**U_END_PUNCTUATION**: End punctuation, for example, the right parenthesis.<br>**U_INITIAL_PUNCTUATION**: Opening quotation mark, for example, the left double quotation mark or left single quotation mark.<br>**U_FINAL_PUNCTUATION**: Closing quotation mark, for example, the right double quotation mark or right single quotation mark.<br>**U_CONNECTOR_PUNCTUATION**: Connector punctuation.<br>**U_OTHER_PUNCTUATION**: Other punctuations.<br>**U_MATH_SYMBOL**: Mathematical symbol.<br>**U_CURRENCY_SYMBOL**: Currency symbol.<br>**U_MODIFIER_SYMBOL**: Modifier symbol.<br>**U_OTHER_SYMBOL**: Other symbols.<br> For details, see Unicode standard.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let unicodeType: string = i18n.Unicode.getType('a'); // unicodeType = 'U_LOWERCASE_LETTER'
  ```

### detectEncoding

static detectEncoding(bytes: Uint8Array): EncodingInfo

Detects the encoding information of the input byte stream.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| bytes | Uint8Array | Yes   | Input byte stream.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| [EncodingInfo](#encodinginfo) | Encoding information, including the encoding name and confidence.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let uint8Array = new Uint8Array([0xEF, 0xBB, 0xBF, 0xE4, 0xB8, 0xAD]);
  let info = i18n.Unicode.detectEncoding(uint8Array); // info.encodingName = 'UTF-8', info.confidence = 100
  ```

## EncodingInfo

Describes the encoding information.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

| Name | Type  | Read-Only  | Optional  | Description               |
| ---- | ---- | ---- | ---- | ----------------- |
| encodingName | string | No | No | Encoding name. The value can be any of the following: **UTF-8**, **UTF-16BE**, **UTF-16LE**, **UTF-32BE**, **UTF-32LE**, **Shift_JIS**, **ISO-2022-JP**, **ISO-2022-CN**, **ISO-2022-KR**, **GB18030**, **Big5**, **EUC-JP**, **EUC-KR**, **ISO-8859-1**, **ISO-8859-2**, **ISO-8859-5**, **ISO-8859-6**, **ISO-8859-7**, **ISO-8859-8**, **ISO-8859-9**, **windows-1250**, **windows-1251**, **windows-1252**, **windows-1253**, **windows-1254**, **windows-1255**, **windows-1256**, **KOI8-R**, **IBM420**, or **IBM424**. |
| confidence | number | No   | No   | Confidence level of the detection result. The value ranges from 0 to 100. A larger value indicates a more reliable detection result.|

## I18NUtil<sup>9+</sup>

Internationalization utility class, which provides the capabilities of unit conversion, date sequence retrieval, time segment name retrieval, region matching, and path localization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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
| path | string | Yes  | Path to process, for example, **/data/out/tmp**.|
| delimiter | string | No  | Path delimiter. The default value is **/**.|
| locale | [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | No  | **Locale** object. The default value is the current system locale.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | File path after localization. If the specified locale object corresponds to an RTL language, the processed file path contains a direction control character to ensure that the file path is displayed in mirror mode.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 8900001   | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

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

### setUnicodeWrappedBidiDirection

static setUnicodeWrappedBidiDirection(text: string, direction: 'RTL' | 'LTR'): string

Sets the text direction for certain text within a paragraph, including RTL (right-to-left) and LTR (left-to-right).

> **NOTE**
>
> The setting does not take effect within strong characters (characters with an intrinsic, unambiguous writing direction).

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| text | string | Yes  | Text for which the direction needs to be set.|
| direction | 'RTL' \| 'LTR' | Yes  | **RTL** indicates right-to-left, and **LTR** indicates left-to-right.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Text with direction set.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let text: string = '(012) 345-6789';
  let result: string = i18n.I18NUtil.setUnicodeWrappedBidiDirection(text, 'LTR');
  console.info(`setUnicodeWrappedBidiDirection, result: ${result}`);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call I18NUtil.setUnicodeWrappedBidiDirection failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### convertCanonicalLocaleIdentifier

static convertCanonicalLocaleIdentifier(locale: string): string

Adjusts a locale ID to a format that complies with the [BCP47](https://www.rfc-editor.org/info/bcp47/) standard.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| locale | string | Yes   | Locale ID.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | If the input locale ID is valid, a locale ID that complies with the [BCP47](https://www.rfc-editor.org/info/bcp47/) standard will be returned. If the input locale ID is invalid, an empty string is returned. |

**Example**

```ts
let result: string = i18n.I18NUtil.convertCanonicalLocaleIdentifier('zh-cn'); // result = 'zh-CN'
```

### getUnicodeWrappedFilePath<sup>(deprecated)</sup>

static getUnicodeWrappedFilePath(path: string, delimiter?: string, locale?: intl.Locale): string

> This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getUnicodeWrappedFilePath](#getunicodewrappedfilepath20).

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
import { i18n, intl } from '@kit.LocalizationKit';

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

Provides the text normalization capabilities.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

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
  import { i18n } from '@kit.LocalizationKit';

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
| text | string | Yes   | Input text.|

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
  import { i18n } from '@kit.LocalizationKit';

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

Provides holiday data parsing capabilities, such as determining holidays and obtaining the holiday list of a specified year.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

### constructor<sup>11+</sup>

constructor(icsPath: String)

Creates a **HolidayManager** object for parsing holiday data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| icsPath   | String | Yes  | Path of the **.ics** file with the read permission granted for applications. iCalendar is a standard Internet calendar format for storing calendar data.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { i18n } from '@kit.LocalizationKit';

  try {
    // Replace /system/lib/US.ics with the actual ICS file path.
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
| date      | Date           | No   | Date and time.<br>**NOTE**<br>The month starts from **0**, indicating January.<br>The default value is the current date.|

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
  import { i18n } from '@kit.LocalizationKit';

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
  import { i18n } from '@kit.LocalizationKit';

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

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| baseName        | string          |   No   |   No   | Holiday name.             |
| year            | number          |   No   |   No   | Year of the holiday.                  |
| month           | number          |   No   |   No   | Month of the holiday.         |
| day             | number          |   No   |   No   | Day of the holiday.                        |
| localNames      | Array&lt;[HolidayLocalName](#holidaylocalname11)&gt;          |   No   |   Yes   | Local names of the holiday.         |

## HolidayLocalName<sup>11+</sup>

Represents the name of a holiday in different languages.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | -----------------| ------  | ------  | --------------------------------------- |
| language        | string           |   No   |   No   | Language, for example, **ar**, **en**, or **tr**.         |
| name            | string           |   No   |   No   | Local name of a holiday. For example, the Turkish name of Sacrifice Feast is Kurban Bayrami.     |

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
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

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

> This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getSimpleDateTimeFormatByPattern](#i18ngetsimpledatetimeformatbypattern20).

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
import { i18n, intl } from '@kit.LocalizationKit';

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
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

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

> This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getSimpleDateTimeFormatBySkeleton](#i18ngetsimpledatetimeformatbyskeleton20).

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
import { i18n, intl } from '@kit.LocalizationKit';

try {
  let locale: intl.Locale = new intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatBySkeleton('yMd', locale);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call i18n.getSimpleDateTimeFormatBySkeleton failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## SimpleDateTimeFormat<sup>18+</sup>

Performs date and time formatting.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

### format<sup>18+</sup>

format(date: Date): string

Formats the date and time.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| date | Date | Yes | Date and time.<br>**NOTE**<br>The month starts from **0**, indicating January. |

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | String of the formatted date and time.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { i18n } from '@kit.LocalizationKit';

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

## SymbolDateTimeFormat

Provides the capability of customizing date and time symbols. This API inherits from [Intl.DateTimeFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat) and supports methods of [Intl.DateTimeFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat).

### constructor

constructor(locale?: Intl.Locale, options?: SymbolDateTimeFormatOptions)

Creates a date and time formatting object that uses custom symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| locale  | [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | No   | **Locale** object. The default value is the current system locale.|
| options | [SymbolDateTimeFormatOptions](#symboldatetimeformatoptions) | No   | Configuration items for date and time formatting using custom symbols. The default value is the locale object's default symbol set.|

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolDateTimeFormat(locale, {
  timeStyle: 'short',
  amPMSymbol: ['AM', 'PM']
});
```

### format

format(date?: Date | number): string

Formats the date and time into a date and time string that uses custom symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| date | Date \| number | No | Date and time object or the millisecond value corresponding to the date and time. In the date and time object, the month starts from **0**, indicating January.<br>The default value is the system time. |

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | Date and time string that uses custom symbols.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolDateTimeFormat(locale, {
  timeStyle: 'short',
  amPMSymbol: ['AM', 'PM']
});
let result = formatter.format(new Date(2026, 3, 26, 14, 20, 0)); // result = '2:20 AM'
```

### formatToParts

formatToParts(date?: Date | number): Intl.DateTimeFormatPart[]

Formats the date and time and returns an array of date and time elements using custom symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| date | Date \| number | No | Date and time object or the millisecond value corresponding to the date and time. In the date and time object, the month starts from **0**, indicating January.<br>The default value is the system time. |

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| Intl.DateTimeFormatPart[] | Array of date and time elements using custom symbols.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolDateTimeFormat(locale, {
  timeStyle: 'short',
  amPMSymbol: ['AM', 'PM']
});
let parts = formatter.formatToParts(new Date(2026, 3, 26, 14, 20, 0)); // parts[0].type = 'dayPeriod'
```

### formatRange

formatRange(startDate: Date | number | bigint, endDate: Date | number | bigint): string

Formats the date and time range. This API does not support custom symbols currently.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| startDate | Date \| number \| bigint | Yes    | Date and time object or the millisecond value corresponding to the date and time. In the date and time object, the month starts from **0**, indicating January. |
| endDate | Date \| number \| bigint | Yes    | Date and time object or the millisecond value corresponding to the date and time. In the date and time object, the month starts from **0**, indicating January. |

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | String of the formatted date and time range.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolDateTimeFormat(locale, {
  timeStyle: 'short',
  amPMSymbol: ['AM', 'PM']
});
let startDate = new Date(2026, 3, 27, 14, 20, 0);
let endDate = new Date(2026, 3, 27, 18, 20, 0);
let result = formatter.formatRange(startDate, endDate); // result = '2:20 PM–6:20 PM'
```

### formatRangeToParts

formatRangeToParts(startDate: Date | number | bigint, endDate: Date | number | bigint): Intl.DateTimeRangeFormatPart[]

Formats a date and time range into an array of date and time elements. This API does not support custom symbols currently.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| startDate | Date \| number \| bigint | Yes | Date and time object or the millisecond value corresponding to the date and time. In the date and time object, the month starts from **0**, indicating January. |
| endDate | Date \| number \| bigint | Yes | Date and time object or the millisecond value corresponding to the date and time. In the date and time object, the month starts from **0**, indicating January. |

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| Intl.DateTimeRangeFormatPart[] | Array of date and time range elements.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolDateTimeFormat(locale, {
  timeStyle: 'short',
  amPMSymbol: ['AM', 'PM']
});
let startDate = new Date(2026, 3, 27, 14, 20, 0);
let endDate = new Date(2026, 3, 27, 18, 20, 0);
let parts = formatter.formatRangeToParts(startDate, endDate); // parts[0].type = 'dayPeriod'
```

### parse

parse(text: string, lenientMode: boolean): number

Parses a localized date and time string and returns the corresponding timestamp.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type   | Mandatory   | Description                |
| ---- | ---- | ---- | ----------------- |
| text | string | Yes    | Localized date and time string to parse. |
| lenientMode | boolean | Yes    | Whether to use the lenient mode. The value **true** means to use the lenient mode, and **false** means the opposite.<br>In lenient mode, date and time values that do not follow conventional logic can be processed. For example, "May 32" is automatically converted to "June 1" for parsing. |

**Return value**

| Type                     | Description    |
| ---------------------- | ----- |
| number | Timestamp corresponding to the parsed date and time string, in milliseconds (ms). |

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID  | Error Message                   |
| ------ | ---------------------- |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example:**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolDateTimeFormat(locale, {
  dateStyle: 'full'
});
let result = formatter.parse('Sunday, May 10, 2026', false); // result = 1778342400000
```

### resolvedOptions

resolvedOptions(): ResolvedSymbolDateTimeFormatOptions

Parses the configuration items for customizing the date and time symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Return value**

|       Type       |         Description         |
| ----------------- | ----------------------|
| [ResolvedSymbolDateTimeFormatOptions](#resolvedsymboldatetimeformatoptions)  | Parsing result of the configuration items of the time and date formatting object using custom symbols.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolDateTimeFormat(locale, {
  timeStyle: 'short',
  amPMSymbol: ['AM', 'PM']
});
let options = formatter.resolvedOptions(); // options.timeStyle = 'short', options.amPMSymbol = ['AM', 'PM']
```

### SymbolDateTimeFormatOptions

Describes optional configuration items for creating the time and date formatting object using custom symbols. This API inherits from **Intl.DateTimeFormatOptions**, supports all its configuration items, and provides the same functionality.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| amPMSymbol     | string[] |   No|   Yes  |  Specifies the symbols for AM and PM. The array length must be no less than 2, where the first element represents the AM symbol and the second element represents the PM symbol. The default value is the locale's default symbol set.  |

### ResolvedSymbolDateTimeFormatOptions

Describes the parsing result of the configuration items of the time and date formatting object using custom symbols. This API inherits from **Intl.ResolvedDateTimeFormatOptions**, supports all its configuration items, and provides the same functionality.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| amPMSymbol     | string[] |   No  |  Yes  |  Specifies the symbols for AM and PM. The first element represents the AM symbol and the second element represents the PM symbol. The default value is the locale's default symbol set.  |

## StyledDateTimeFormat<sup>23+</sup>

Formats the rich text time and date.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Global.I18n

### constructor<sup>23+</sup>

constructor(dateTimeFormat: Intl.DateTimeFormat | SimpleDateTimeFormat, options?: StyledDateTimeFormatOptions)

Creates an object for formatting the time and date that needs to be displayed in rich text.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| dateTimeFormat | [Intl.DateTimeFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat) \| [SimpleDateTimeFormat](#simpledatetimeformat18) | Yes  | Object used to format the date and time. |
| options | [StyledDateTimeFormatOptions](#styleddatetimeformatoptions23) | No| Specifies the configuration items of the time and date formatting object. The default value is the default text style. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let yearTextStyle: TextStyle = new TextStyle({ fontColor: Color.Red });
  let monthTextStyle: TextStyle = new TextStyle({ fontColor: Color.Green });
  let dayTextStyle: TextStyle = new TextStyle({ fontColor: Color.Blue });

  // Create a StyledDateTimeFormat object through Intl.DateTimeFormat.
  let dateFormat: Intl.DateTimeFormat = new Intl.DateTimeFormat('zh-Hans-CN', { dateStyle: 'full' });
  let styledDateFormat: i18n.StyledDateTimeFormat = new i18n.StyledDateTimeFormat(dateFormat, {
    year: yearTextStyle,
    month: monthTextStyle,
    day: dayTextStyle
  });

  let hourTextStyle: TextStyle = new TextStyle({ fontColor: Color.Yellow });
  let minuteTextStyle: TextStyle = new TextStyle({ fontColor: Color.Orange });
  let secondTextStyle: TextStyle = new TextStyle({ fontColor: Color.Pink });

  // Create a StyledDateTimeFormat object through SimpleDateTimeFormat.
  let locale: Intl.Locale = new Intl.Locale('zh-Hans-CN');
  let simpleTimeFormat: i18n.SimpleDateTimeFormat = i18n.getSimpleDateTimeFormatBySkeleton('hhmmss', locale);
  let styledTimeFormat: i18n.StyledDateTimeFormat = new i18n.StyledDateTimeFormat(simpleTimeFormat, {
    hour: hourTextStyle,
    minute: minuteTextStyle,
    second: secondTextStyle
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call i18n.StyledDateTimeFormat failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### format<sup>23+</sup>

format(date: Date): StyledString

Formats the date and time and returns a rich text object.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| date | Date | Yes | Date and time.<br>**NOTE**<br>The month starts from **0**, indicating January. |

**Return value**

|       Type       |         Description         |
| ----------------- | ----------------------|
| [StyledString](../apis-arkui/arkui-ts/ts-universal-styled-string.md#styledstring) | Rich text object after formatting.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let yearTextStyle: TextStyle = new TextStyle({ fontColor: Color.Red });
  let monthTextStyle: TextStyle = new TextStyle({ fontColor: Color.Green });
  let dayTextStyle: TextStyle = new TextStyle({ fontColor: Color.Blue });

  // Create a StyledDateTimeFormat object through Intl.DateTimeFormat.
  let dateFormat: Intl.DateTimeFormat = new Intl.DateTimeFormat('zh-Hans-CN', { dateStyle: 'full' });
  let styledDateFormat: i18n.StyledDateTimeFormat = new i18n.StyledDateTimeFormat(dateFormat, {
    year: yearTextStyle,
    month: monthTextStyle,
    day: dayTextStyle
  });
  let date: Date = new Date(2025, 11, 1);
  // formattedDate.getString() is 'Monday, December 1, 2025'. When formattedDate is displayed, 2025 is in red, 12 is in green, and 1 is in blue.
  let formattedDate: StyledString = styledDateFormat.format(date);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call StyledNumberFormat.format failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## StyledDateTimeFormatOptions<sup>23+</sup>

Optional configuration items for creating the time and date formatting object for rich text display.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| year        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the year. The default value is the default text style of StyledString.    |
| month        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the month. The default value is the default text style of StyledString.   |
| day       | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the day. The default value is the default text style of StyledString.    |
| hour       | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the hour. The default value is the default text style of StyledString.    |
| minute      | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the minute. The default value is the default text style of StyledString.    |
| second        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the second. The default value is the default text style of StyledString.   |
| dayPeriod       | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the period. The default value is the default text style of StyledString.    |
| weekday        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the week. The default value is the default text style of StyledString.    |
| era        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the era. The default value is the default text style of StyledString.    |
| timeZoneName   | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Specifies the text style of the time zone name. The default value is the default text style of StyledString. |

## ISO8601DateTimeFormat

Date formatting object that complies with ISO 8601.

### constructor

constructor(options?: ISO8601DateTimeFormatOptions)

Creates a date formatting object that complies with ISO 8601.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| options | [ISO8601DateTimeFormatOptions](#iso8601datetimeformatoptions) | No | Configuration options for creating a date formatting object that complies with ISO 8601. Default value: configuration options with all properties set to their default values. |

**Example**

```ts
let formatter = new i18n.ISO8601DateTimeFormat({
  dateFormat: 'calendar',
  timePrecision: 'minutes',
  separatorStyle: 'extended'
});
```

### format

format(date: Date): string

Formats the date and time into a date and time string that complies with ISO 8601.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| date | Date | Yes | Date and time.<br>**NOTE**<br>The month starts from **0**, indicating January. |

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | Date and time string that complies with ISO 8601. |

**Example**

```ts
let formatter = new i18n.ISO8601DateTimeFormat({
  dateFormat: 'calendar',
  timePrecision: 'minutes',
  separatorStyle: 'extended'
});
let result = formatter.format(new Date(2026, 2, 15, 12, 0, 0));
```

## ISO8601DateTimeFormatOptions

Describes the configuration options for creating a date formatting object that complies with ISO 8601.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | ------- | ------- | ------- | --------------------------------------- |
| dateFormat   | string |   No  |   Yes  |  Date format. The options are as follows:<br>**calendar**: The date format is **YYYY-MM-DD**.<br>**ordinal**: The date format is **YYYY-DDD**.<br>**week**: The date format is **YYYY-Www-D**.<br>The default value is **calendar**. For details about the meaning of characters in a format, see [Date Field Symbol Table](https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table).  |
| timePrecision   | string |   No  |   Yes  |  Time precision. The options are as follows:<br>**dateOnly**: Displays the date only.<br>**hours**: Displays the hour.<br>**minutes**: Displays the hour and minute.<br>**seconds**: Displays the hour, minute, and second.<br>**milliSeconds**: Displays the hour, minute, second, and millisecond.<br>The default value is **seconds**. |
| separatorStyle  | string |   No  |   Yes  |  Separator style. The options are as follows:<br>**extended**: The date and time separator is displayed.<br>**basic**: The date and time separator is not displayed.<br>The default value is **extended**.  |
| timeZone        | [TimeZone](#timezone) |   No  |   Yes  |  Time zone. The default value is **UTC**.  |
| displayTimeZone     | boolean |   No |   Yes  |  Whether to display the time zone. The value **true** yes, and the value **false** indicates no. The default value is **true**. |

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
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

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

> This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getSimpleNumberFormatBySkeleton](#i18ngetsimplenumberformatbyskeleton20).

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
import { i18n, intl } from '@kit.LocalizationKit';

try {
  let locale: intl.Locale = new intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleNumberFormat = i18n.getSimpleNumberFormatBySkeleton('%', locale);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call SimpleDateTimeFormat.getSimpleNumberFormatBySkeleton failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## SimpleNumberFormat<sup>18+</sup>

Formats a number based on the specified skeleton string.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

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
import { i18n } from '@kit.LocalizationKit';

try {
  let locale: Intl.Locale = new Intl.Locale('zh-Hans-CN');
  let formatter: i18n.SimpleNumberFormat = i18n.getSimpleNumberFormatBySkeleton('%', locale);
  let formattedNumber: string = formatter.format(10); // formattedNumber = '10%'
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call SimpleNumberFormat.format failed, error code: ${err.code}, message: ${err.message}.`);
}
```

## SymbolNumberFormat

Provides the capability of customizing numeric symbols. This API inherits from [Intl.NumberFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat) and supports methods of [Intl.NumberFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat).

### constructor

constructor(locale?: Intl.Locale, options?: SymbolNumberFormatOptions)

Creates a number formatting object that uses custom symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| locale  | [Intl.Locale](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale) | No   | **Locale** object. The default value is the current system locale.|
| options | [SymbolNumberFormatOptions](#symbolnumberformatoptions) | No   | Configuration items for number formatting using custom symbols. The default value is the locale's default symbol set.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolNumberFormat(locale, {
  style: 'unit',
  unit: 'day',
  zero: '(0)'
});
```

### format

format(value: number | bigint): string

Formats a number and returns a numeric string using a custom symbol.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| value | number \| bigint | Yes   | Number to be formatted.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | Numeric string that uses a custom symbol.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolNumberFormat(locale, {
  style: 'unit',
  unit: 'day',
  zero: '(0)'
});
let result = formatter.format(10); // result = '1(0) days'
```

### formatToParts

formatToParts(value?: number \| bigint): Intl.NumberFormatPart[]

Formats a number and returns an array of numeric elements using custom symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| value | number \| bigint | No   | Number to be formatted. The default value is **NaN**.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| Intl.NumberFormatPart[] | Array of numeric elements using custom symbols.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolNumberFormat(locale, {
  style: 'unit',
  unit: 'day',
  zero: '(0)'
});
let result = formatter.formatToParts(10); // result[0].type = 'integer'
```

### formatRange

formatRange(startRange: number, endRange: number): string

Formats a number range and returns a number range string using custom symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| startRange | number | Yes   | Start number.|
| endRange | number | Yes   | End number.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | Number range string using custom symbols.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolNumberFormat(locale, {
  style: 'unit',
  unit: 'day',
  zero: '(0)'
});
let result = formatter.formatRange(10, 20); // result = '1(0)-2(0) days'
```

### formatRangeToParts

formatRangeToParts(startRange: number, endRange: number): Intl.NumberFormatPart[]

Formats a number range and returns an array of numeric elements using custom symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| startRange | number | Yes   | Start number.|
| endRange | number | Yes   | End number.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| Intl.NumberFormatPart[] | Array of numeric elements using custom symbols.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolNumberFormat(locale, {
  style: 'unit',
  unit: 'day',
  zero: '(0)'
});
let result = formatter.formatRangeToParts(10, 20); // result[0].type = 'integer'
```

### parse

parse(text: string, lenientMode: boolean): number

Parses a localized numeric string and returns the corresponding number. It cannot correctly parse localized numeric strings that use custom symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type   | Mandatory   | Description                |
| ---- | ---- | ---- | ----------------- |
| text | string | Yes    | Localized number string to parse. |
| lenientMode | boolean | Yes    | Whether to use the lenient mode. The value **true** means to use the lenient mode, and **false** means the opposite.<br>In lenient mode, incorrect thousand separators can be recognized. For example, "1,23,456" can be correctly parsed as "123456". |

**Return value**

| Type                     | Description    |
| ---------------------- | ----- |
| number | Number parsed from the localized number string. |

**Error codes**

For details about the error codes, see [i18n Error Codes](errorcode-i18n.md).

| ID  | Error Message                   |
| ------ | ---------------------- |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example:**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolNumberFormat(locale);
let result = formatter.parse('125 m', false); // result = 125
```

### resolvedOptions

resolvedOptions(): ResolvedSymbolNumberFormatOptions

Parses the configuration items for customizing number symbols.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Return value**

|       Type       |         Description         |
| ----------------- | ----------------------|
| [ResolvedSymbolNumberFormatOptions](#resolvedsymbolnumberformatoptions)  | Parsing result of the configuration items of the number formatting object using custom symbols.|

**Example**

```ts
import { i18n } from '@kit.LocalizationKit';

let locale = new Intl.Locale('zh-Hans-CN');
let formatter = new i18n.SymbolNumberFormat(locale, {
  style: 'unit',
  unit: 'day',
  zero: '(0)'
});
let result = formatter.resolvedOptions(); // result.style = 'unit', result.unit = 'day', result.zero = '(0)'
```

### SymbolNumberFormatOptions

Describes optional configuration items for creating the number object using custom symbols. This API inherits from **Intl.NumberFormatOptions**, supports all its configuration items, and provides the same functionality.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| zero     | string  |   No   |   Yes  |  Zero. The default value is the locale's default symbol.  |
| nan     | string  |   No   |   Yes  |  NaN. The default value is the locale's default symbol.  |
| minusSign     | string  |   No   |   Yes  |  Minus sign. The default value is the locale's default symbol.  |
| plusSign     | string  |   No   |   Yes  |  Plus sign. The default value is the locale's default symbol.  |
| infinity     | string  |   No   |   Yes  |  Infinity symbol. The default value is the locale's default symbol.  |
| groupingSeparator     | string |   No   |   Yes  |  Grouping symbol. The default value is the locale's default symbol.  |

### ResolvedSymbolNumberFormatOptions

Describes the parsing result of the configuration items of the number formatting object using custom symbols. This API inherits from **Intl.ResolvedNumberFormatOptions**, supports all its configuration items, and provides the same functionality.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| zero     | string  |   No   |   Yes  |  Zero. The default value is the locale's default symbol.  |
| nan     | string  |   No   |   Yes  |  NaN. The default value is the locale's default symbol.  |
| minusSign     | string  |   No   |   Yes  |  Minus sign. The default value is the locale's default symbol.  |
| plusSign     | string  |   No   |   Yes  |  Plus sign. The default value is the locale's default symbol.  |
| infinity     | string  |   No   |   Yes  |  Infinity symbol. The default value is the locale's default symbol.  |
| groupingSeparator     | string |   No   |   Yes  |  Grouping symbol. The default value is the locale's default symbol.  |

## StyledNumberFormat<sup>18+</sup>

Performs rich text number formatting.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.I18n

### constructor<sup>(deprecated)</sup>

constructor(numberFormat: intl.NumberFormat | SimpleNumberFormat, options?: StyledNumberFormatOptions)

> This API is supported since API version 18 and deprecated since API version 20. You are advised to use [constructor](#constructor20) instead.

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
  import { i18n, intl } from '@kit.LocalizationKit';

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

### constructor<sup>20+</sup>

constructor(numberFormat: Intl.NumberFormat | SimpleNumberFormat, options?: StyledNumberFormatOptions)

Creates a **NumberFormat** object for rich text display.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| numberFormat | [Intl.NumberFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat) \| [SimpleNumberFormat](#simplenumberformat18) | Yes  | **NumberFormat** object. |
| options | [StyledNumberFormatOptions](#stylednumberformatoptions18) | No| Configuration options of the **NumberFormat** object. The default value is the default text style. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { i18n } from '@kit.LocalizationKit';

  try {
    let integerTextStyle: TextStyle = new TextStyle({ fontColor: Color.Red });
    let decimalTextStyle: TextStyle = new TextStyle({ fontColor: Color.Brown });
    let fractionTextStyle: TextStyle = new TextStyle({ fontColor: Color.Blue });
    let unitTextStyle: TextStyle = new TextStyle({ fontColor: Color.Green });

    // Create a StyledNumberFormat object through Intl.NumberFormat.
    let numFmt: Intl.NumberFormat = new Intl.NumberFormat('zh', { style: 'unit', unit: 'percent' });
    let styledNumFmt: i18n.StyledNumberFormat = new i18n.StyledNumberFormat(numFmt, {
      integer: integerTextStyle,
      decimal: decimalTextStyle,
      fraction: fractionTextStyle,
      unit: unitTextStyle
    });

    // Create a StyledNumberFormat object through SimpleNumberFormat.
    let locale: Intl.Locale = new Intl.Locale('zh');
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
  import { i18n } from '@kit.LocalizationKit';

  try {
    let integerTextStyle: TextStyle = new TextStyle({ fontColor: Color.Red });
    let decimalTextStyle: TextStyle = new TextStyle({ fontColor: Color.Brown });
    let fractionTextStyle: TextStyle = new TextStyle({ fontColor: Color.Blue });
    let unitTextStyle: TextStyle = new TextStyle({ fontColor: Color.Green });

    // Create a StyledNumberFormat object through Intl.NumberFormat.
    let numFmt: Intl.NumberFormat = new Intl.NumberFormat('zh', { style: 'unit', unit: 'percent' });
    let styledNumFmt: i18n.StyledNumberFormat = new i18n.StyledNumberFormat(numFmt, {
      integer: integerTextStyle,
      decimal: decimalTextStyle,
      fraction: fractionTextStyle,
      unit: unitTextStyle
    });
    // formattedNumber.getString () is 1,234.568%. In the formatted number, 1,234 is in red, . in brown, 568 in blue, and % in green.
    let formattedNumber: StyledString = styledNumFmt.format(1234.5678);

    // Create a StyledNumberFormat object through SimpleNumberFormat.
    let locale: Intl.Locale = new Intl.Locale('zh');
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

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| integer        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Text style for the integer part. The default value is the default text style of StyledString.    |
| decimal        | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Text style for the decimal point. The default value is the default text style of StyledString.   |
| fraction       | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Text style for the fraction part. The default value is the default text style of StyledString.    |
| unit           | [TextStyle](../apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle) |   No   |   Yes   |  Text style for the unit. The default value is the default text style of StyledString.    |

## AdvancedMeasureFormat<sup>23+</sup>

Provides the number formatting capability, supporting automatic conversion to the appropriate unit based on the usage scenario.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

### constructor<sup>23+</sup>

constructor(numberFormat: Intl.NumberFormat, options?: AdvancedMeasureFormatOptions)

Creates a **NumberForma**t object for the specified locale.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| numberFormat | [Intl.NumberFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat) | Yes  | **NumberFormat** object. |
| options | [AdvancedMeasureFormatOptions](#advancedmeasureformatoptions23) | No| Configuration options of the **NumberFormat** object. Default value: Same as [numberFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat) |

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let numFmt: Intl.NumberFormat = new Intl.NumberFormat('zh-Hans-CN', { style: 'unit', unit: 'fahrenheit' });
  let advancedMeasureFormat: i18n.AdvancedMeasureFormat = new i18n.AdvancedMeasureFormat(numFmt, {
    unitUsage: i18n.UnitUsage.TEMPERATURE_PERSON
  });
  ```

### format<sup>23+</sup>

format(num: number): string

Formats a number.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| num | number | Yes| Number to be formatted. |

**Return value**

|       Type       |         Description         |
| ----------------- | ----------------------|
| string | Formatted text.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let numFmt: Intl.NumberFormat = new Intl.NumberFormat('zh-Hans-CN', { style: 'unit', unit: 'fahrenheit' });
  let advancedMeasureFormat: i18n.AdvancedMeasureFormat = new i18n.AdvancedMeasureFormat(numFmt, {
    unitUsage: i18n.UnitUsage.TEMPERATURE_PERSON
  });
  let result = advancedMeasureFormat.format(100); // result = '37.778°C'
  ```

## AdvancedMeasureFormatOptions<sup>23+</sup>

Optional configuration items for creating a number format object.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| unitUsage        | [UnitUsage](#unitusage23) |   No   |   Yes   |  Enumerates unit formatting scenarios.    |

## UnitUsage<sup>23+</sup>

Enumerates unit formatting scenarios.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Global.I18n

**Model restriction**: This API can be used only in the stage model.

| Name| Value| Description|
| -------- | -------- | -------- |
| AREA_LAND_AGRICULT | 1 | Agricultural land area.|
| AREA_LAND_COMMERCL | 2 | Commercial land area.|
| AREA_LAND_RESIDNTL | 3 | Residential land area.|
| LENGTH_PERSON | 4 | Height.|
| LENGTH_PERSON_SMALL | 5 | High-precision height.|
| LENGTH_RAINFALL | 6 | Rainfall amount.|
| LENGTH_ROAD | 7 | Road length.|
| LENGTH_ROAD_SMALL | 8 | High-precision road length.|
| LENGTH_SNOWFALL | 9 | Snowfall amount.|
| LENGTH_VEHICLE | 10 | Vehicle length.|
| LENGTH_VISIBLTY | 11 | Visibility.|
| LENGTH_VISIBLTY_SMALL | 12 | High-precision visibility.|
| LENGTH_PERSON_INFORMAL | 13 | Oral height.|
| LENGTH_PERSON_SMALL_INFORMAL | 14 | High-precision oral height.|
| LENGTH_ROAD_INFORMAL | 15 | Oral road length.|
| SPEED_ROAD_TRAVEL | 16 | Vehicle speed.|
| SPEED_WIND | 17 | Wind speed.|
| TEMPERATURE_PERSON | 18 | Body temperature.|
| TEMPERATURE_WEATHER | 19 | Air temperature.|
| VOLUME_VEHICLE_FUEL | 20 | Vehicle fuel volume.|
| ELAPSED_TIME_SECOND | 21 | Past time.|
| SIZE_FILE_BYTE | 22 | File size.|
| SIZE_SHORTFILE_BYTE | 23 | Short file size.|

## i18n.getDisplayCountry<sup>(deprecated)</sup>

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [System.getDisplayCountry](#getdisplaycountry9) instead.

Obtains the localized name of the specified country/region.

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
  import { i18n } from '@kit.LocalizationKit';

  let countryName: string = i18n.getDisplayCountry('zh-CN', 'en-GB', true); // countryName = 'China'
  countryName = i18n.getDisplayCountry('zh-CN', 'en-GB'); // countryName = 'China'
  ```

## i18n.getDisplayLanguage<sup>(deprecated)</sup>

getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [System.getDisplayLanguage](#getdisplaylanguage9) instead.

Obtains the localized script for the specified language.

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
  import { i18n } from '@kit.LocalizationKit';

  let languageName: string = i18n.getDisplayLanguage('zh', 'en-GB', true); // languageName = 'Chinese'
  languageName = i18n.getDisplayLanguage('zh', 'en-GB'); // languageName = 'Chinese'
  ```

## i18n.getSystemLanguage<sup>(deprecated)</sup>

getSystemLanguage(): string

> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [System.getSystemLanguage](#getsystemlanguage9) instead.

Obtains the system language.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System language ID.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let systemLanguage: string = i18n.getSystemLanguage();
  ```

## i18n.getSystemRegion<sup>(deprecated)</sup>

getSystemRegion(): string

> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [System.getSystemRegion](#getsystemregion9) instead.

Obtains the system region.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System region ID.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let region: string = i18n.getSystemRegion();
  ```

## i18n.getSystemLocale<sup>(deprecated)</sup>

getSystemLocale(): string

> This API is supported since API version 7 and is deprecated since API version 9. You are advised to use [System.getSystemLocale](#getsystemlocaleinstance20) instead.

Obtains the system locale.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System locale ID.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let locale: string = i18n.getSystemLocale();
  ```

## i18n.is24HourClock<sup>(deprecated)</sup>

is24HourClock(): boolean

> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [System.is24HourClock](#is24hourclock9) instead.

Checks whether the 24-hour clock is used.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the 24-hour clock is used, and **false** otherwise.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let is24HourClock: boolean = i18n.is24HourClock();
  ```

## i18n.set24HourClock<sup>(deprecated)</sup>

set24HourClock(option: boolean): boolean

> This API is supported since API version 7 and is deprecated since API version 9. The substitute API is available only for system applications.

Sets the 24-hour clock.

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
  import { i18n } from '@kit.LocalizationKit';

  // Set the system time to the 24-hour clock.
  let success: boolean = i18n.set24HourClock(true);
  ```

## i18n.addPreferredLanguage<sup>(deprecated)</sup>

addPreferredLanguage(language: string, index?: number): boolean

> This API is supported since API version 8 and is deprecated since API version 9. The substitute API is available only for system applications.

Adds a preferred language to the specified position on the preferred language list.

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
  import { i18n } from '@kit.LocalizationKit';

  // Add zh-CN to the preferred language list.
  let language: string = 'zh-CN';
  let index: number = 0;
  let success: boolean = i18n.addPreferredLanguage(language, index);
  ```

## i18n.removePreferredLanguage<sup>(deprecated)</sup>

removePreferredLanguage(index: number): boolean

> This API is supported since API version 8 and is deprecated since API version 9. The substitute API is available only for system applications.

Removes a preferred language from the specified position on the preferred language list.

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
  import { i18n } from '@kit.LocalizationKit';

  // Delete the first preferred language from the preferred language list.
  let index: number = 0;
  let success: boolean = i18n.removePreferredLanguage(index);
  ```

## i18n.getPreferredLanguageList<sup>(deprecated)</sup>

getPreferredLanguageList(): Array&lt;string&gt;

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.getPreferredLanguageList](#getpreferredlanguagelist9) instead.

Obtains the list of preferred languages.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description       |
| ------------------- | --------- |
| Array&lt;string&gt; | List of preferred languages.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let preferredLanguageList: Array<string> = i18n.getPreferredLanguageList();
  ```

## i18n.getFirstPreferredLanguage<sup>(deprecated)</sup>

getFirstPreferredLanguage(): string

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.getFirstPreferredLanguage](#getfirstpreferredlanguage9) instead.

Obtains the first language in the preferred language list.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description            |
| ------ | -------------- |
| string | First language in the preferred language list.|

**Example**

  ```ts
  import { i18n } from '@kit.LocalizationKit';

  let firstPreferredLanguage: string = i18n.getFirstPreferredLanguage();
  ```

## Util<sup>(deprecated)</sup>

### unitConvert<sup>(deprecated)</sup>

unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [unitConvert](#unitconvert9) instead.

Converts one measurement unit into another and formats the unit based on the specified locale and style.

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

isDigit(ch: string): boolean

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isDigit](#isdigit9) instead.

Checks whether the input character is a digit.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | **true** if the input character is a digit, and **false** otherwise.|

### isSpaceChar<sup>(deprecated)</sup>

isSpaceChar(ch: string): boolean

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isSpaceChar](#isspacechar9) instead.

Checks whether the input character is a space.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | **true** if the input character is a space, and **false** otherwise.|

### isWhitespace<sup>(deprecated)</sup>

isWhitespace(ch: string): boolean

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isWhitespace](#iswhitespace9) instead.

Checks whether the input character is a whitespace character.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | **true** if the input character is a white space, and **false** otherwise.|

### isRTL<sup>(deprecated)</sup>

isRTL(ch: string): boolean

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isRTL](#isrtl9) instead.

Checks whether the input character is of the right to left (RTL) language.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character is of the RTL language, and **false** otherwise.|

### isIdeograph<sup>(deprecated)</sup>

isIdeograph(ch: string): boolean

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isIdeograph](#isideograph9) instead.

Checks whether the input character is an ideographic character.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character an ideographic character, and **false** otherwise.|

### isLetter<sup>(deprecated)</sup>

isLetter(ch: string): boolean

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isLetter](#isletter9) instead.

Checks whether the input character is a letter.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | **true** if the input character a letter, and **false** otherwise.|

### isLowerCase<sup>(deprecated)</sup>

isLowerCase(ch: string): boolean

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isLowerCase](#islowercase9) instead.

Checks whether the input character is a lowercase letter.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character a lowercase letter, and **false** otherwise.|

### isUpperCase<sup>(deprecated)</sup>

isUpperCase(ch: string): boolean

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isUpperCase](#isuppercase9) instead.

Checks whether the input character is an uppercase letter.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | **true** if the input character an uppercase letter, and **false** otherwise.|

### getType<sup>(deprecated)</sup>

getType(ch: string): string

> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [getType](#gettype9) instead.

Obtains the type of the input character.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| ch | string | Yes   | Input character. If the input is a string, only the type of the first character is checked.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Type of the input character.|