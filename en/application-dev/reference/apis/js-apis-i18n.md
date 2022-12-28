# Internationalization – I18N

 This module provides system-related or enhanced I18N capabilities, such as locale management, phone number formatting, and calendar, through supplementary I18N APIs that are not defined in ECMA 402.
The [Intl](js-apis-intl.md) module provides basic I18N capabilities through the standard I18N APIs defined in ECMA 402. It works with the I18N module to provide a complete suite of I18N capabilities.

>  **NOTE**
>  - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - This module provides system-related or enhanced I18N capabilities, such as locale management, phone number formatting, and calendar, through supplementary I18N APIs that are not defined in ECMA 402. For details about the basic I18N capabilities, see [Intl](js-apis-intl.md).


## Modules to Import

```js
import i18n from '@ohos.i18n';
```


## System<sup>9+</sup>

### getDisplayCountry<sup>9+</sup>

static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

Obtains the localized script for the specified country.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | Yes   | Specified country.           |
| locale       | string  | Yes   | Locale ID.    |
| sentenceCase | boolean | No   | Whether to use sentence case for the localized script.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified country.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var displayCountry = i18n.System.getDisplayCountry("zh-CN", "en-GB");
  } catch(error) {
    console.error(`call System.getDisplayCountry failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getDisplayLanguage<sup>9+</sup>

static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

Obtains the localized script for the specified language.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| language     | string  | Yes   | Specified language.           |
| locale       | string  | Yes   | Locale ID.    |
| sentenceCase | boolean | No   | Whether to use sentence case for the localized script.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified language.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var displayLanguage = i18n.System.getDisplayLanguage("zh", "en-GB");
  } catch(error) {
    console.error(`call System.getDisplayLanguage failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getSystemLanguages<sup>9+</sup>

static getSystemLanguages(): Array&lt;string&gt;

Obtains the list of system languages.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Array&lt;string&gt; | List of the IDs of system languages.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var systemLanguages = i18n.System.getSystemLanguages();
  } catch(error) {
    console.error(`call System.getSystemLanguages failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getSystemCountries<sup>9+</sup>

static getSystemCountries(language: string): Array&lt;string&gt;

Obtains the list of countries and regions supported for the specified language.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Description   |
| -------- | ------ | ----- |
| language | string | Language ID.|

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Array&lt;string&gt; | List of the IDs of the countries and regions supported for the specified language.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var systemCountries = i18n.System.getSystemCountries('zh');
  } catch(error) {
    console.error(`call System.getSystemCountries failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### isSuggested<sup>9+</sup>

static isSuggested(language: string, region?: string): boolean

Checks whether the system language matches the specified region.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description           |
| -------- | ------ | ---- | ------------- |
| language | string | Yes   | Valid language ID, for example, **zh**.|
| region   | string | No   | Valid region ID, for example, **CN**. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the system language matches the specified region; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var res = i18n.System.isSuggested('zh', 'CN');
  } catch(error) {
    console.error(`call System.isSuggested failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getSystemLanguage<sup>9+</sup>

static getSystemLanguage(): string

Obtains the system language.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System language ID.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var systemLanguage = i18n.System.getSystemLanguage();
  } catch(error) {
    console.error(`call System.getSystemLanguage failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### setSystemLanguage<sup>9+</sup>

static setSystemLanguage(language: string): void

Sets the system language. Currently, this API does not support real-time updating of the system language.

This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Description   |
| -------- | ------ | ----- |
| language | string | Language ID.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    i18n.System.setSystemLanguage('zh');
  } catch(error) {
    console.error(`call System.setSystemLanguage failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getSystemRegion<sup>9+</sup>

static getSystemRegion(): string

Obtains the system region.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System region ID.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var systemRegion = i18n.System.getSystemRegion();
  } catch(error) {
    console.error(`call System.getSystemRegion failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### setSystemRegion<sup>9+</sup>

static setSystemRegion(region: string): void

Sets the system region.

This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Description   |
| ------ | ------ | ----- |
| region | string | Region ID.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    i18n.System.setSystemRegion('CN');
  } catch(error) {
    console.error(`call System.setSystemRegion failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getSystemLocale<sup>9+</sup>

static getSystemLocale(): string

Obtains the system locale.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System locale ID.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var systemLocale = i18n.System.getSystemLocale();
  } catch(error) {
    console.error(`call System.getSystemLocale failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### setSystemLocale<sup>9+</sup>

static setSystemLocale(locale: string): void

Sets the system locale.

This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Description             |
| ------ | ------ | --------------- |
| locale | string | System locale ID, for example, **zh-CN**.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    i18n.System.setSystemLocale('zh-CN');
  } catch(error) {
    console.error(`call System.setSystemLocale failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### is24HourClock<sup>9+</sup>

static is24HourClock(): boolean

Checks whether the 24-hour clock is used.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the 24-hour clock is used; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var is24HourClock = i18n.System.is24HourClock();
  } catch(error) {
    console.error(`call System.is24HourClock failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### set24HourClock<sup>9+</sup>

static set24HourClock(option: boolean): void

Sets the 24-hour clock.

This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type     | Mandatory  | Description                                      |
| ------ | ------- | ---- | ---------------------------------------- |
| option | boolean | Yes   | Whether to enable the 24-hour clock. The value **true** means to enable the 24-hour clock, and the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  // Set the system time to the 24-hour clock.
  try {
    i18n.System.set24HourClock(true);
  } catch(error) {
    console.error(`call System.set24HourClock failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### addPreferredLanguage<sup>9+</sup>

static addPreferredLanguage(language: string, index?: number): void

Adds a preferred language to the specified position on the preferred language list.

This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description        |
| -------- | ------ | ---- | ---------- |
| language | string | Yes   | Preferred language to add. |
| index    | number | No   | Position to which the preferred language is added.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  // Add zh-CN to the preferred language list.
  var language = 'zh-CN';
  var index = 0;
  try {
    i18n.System.addPreferredLanguage(language, index);
  } catch(error) {
    console.error(`call System.addPreferredLanguage failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### removePreferredLanguage<sup>9+</sup>

static removePreferredLanguage(index: number): void

Deletes a preferred language from the specified position on the preferred language list.

This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                   |
| ----- | ------ | ---- | --------------------- |
| index | number | Yes   | Position of the preferred language to delete.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  // Delete the first preferred language from the preferred language list.
  var index = 0;
  try {
    i18n.System.removePreferredLanguage(index);
  } catch(error) {
    console.error(`call System.removePreferredLanguage failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getPreferredLanguageList<sup>9+</sup>

static getPreferredLanguageList(): Array&lt;string&gt;

Obtains the list of preferred languages.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description       |
| ------------------- | --------- |
| Array&lt;string&gt; | List of preferred languages.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var preferredLanguageList = i18n.System.getPreferredLanguageList();
  } catch(error) {
    console.error(`call System.getPreferredLanguageList failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getFirstPreferredLanguage<sup>9+</sup>

static getFirstPreferredLanguage(): string

Obtains the first language in the preferred language list.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description            |
| ------ | -------------- |
| string | First language in the preferred language list.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var firstPreferredLanguage = i18n.System.getFirstPreferredLanguage();
  } catch(error) {
    console.error(`call System.getFirstPreferredLanguage failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getAppPreferredLanguage<sup>9+</sup>

static getAppPreferredLanguage(): string

Obtains the preferred language of an application.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Preferred language of the application.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```js
  try {
    var appPreferredLanguage = i18n.System.getAppPreferredLanguage();
  } catch(error) {
    console.error(`call System.getAppPreferredLanguage failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### setUsingLocalDigit<sup>9+</sup>

static setUsingLocalDigit(flag: boolean): void

Sets whether to turn on the local digit switch.

This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type     | Mandatory  | Description                             |
| ---- | ------- | ---- | ------------------------------- |
| flag | boolean | Yes   | Whether to turn on the local digit switch. The value **true** means to turn on the local digit switch, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```ts
  try {
    i18n.System.setUsingLocalDigit(true);
  } catch(error) {
    console.error(`call System.setUsingLocalDigit failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getUsingLocalDigit<sup>9+</sup>

static getUsingLocalDigit(): boolean

Checks whether the local digit switch is turned on.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Result indicating whether the local digit switch is turned on. The value **true** indicates that the local digit switch is turned on, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 890001  | Unspported para value.                |

**Example**
  ```ts
  try {
    var status = i18n.System.getUsingLocalDigit();
  } catch(error) {
    console.error(`call System.getUsingLocalDigit failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


## i18n.isRTL<sup>7+</sup>

isRTL(locale: string): boolean

Checks whether the localized script for the specified language is displayed from right to left.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Description     |
| ------ | ------ | ------- |
| locale | string | Locale ID.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the localized script is displayed from right to left; returns **false** otherwise.|

**Example**
  ```js
  i18n.isRTL("zh-CN");// Since Chinese is not written from right to left, false is returned.
  i18n.isRTL("ar-EG");// Since Arabic is written from right to left, true is returned.
  ```


## i18n.getCalendar<sup>8+</sup>

getCalendar(locale: string, type? : string): Calendar

Obtains a **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | Valid locale value, for example, **zh-Hans-CN**.                |
| type   | string | No   | Valid calendar type. Currently, the valid types are as follows: **buddhist**, **chinese**, **coptic**, **ethiopic**, **hebrew**, **gregory**, **indian**, **islamic\_civil**, **islamic\_tbla**, **islamic\_umalqura**, **japanese**, and **persian**. If this parameter is left unspecified, the default calendar type of the specified locale is used.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [Calendar](#calendar8) | **Calendar** object.|

**Example**
  ```js
  i18n.getCalendar("zh-Hans", "gregory");
  ```


## Calendar<sup>8+</sup>


### setTime<sup>8+</sup>

setTime(date: Date): void

Sets the date for this **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| date | Date | Yes   | Date to be set for the **Calendar** object.|

**Example**
  ```js
  var calendar = i18n.getCalendar("en-US", "gregory");
  var date = new Date(2021, 10, 7, 8, 0, 0, 0);
  calendar.setTime(date);
  ```


### setTime<sup>8+</sup>

setTime(time: number): void

Sets the date and time for this **Calendar** object. The value is represented by the number of milliseconds that have elapsed since the Unix epoch (00:00:00 UTC on January 1, 1970).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| time | number | Yes   | Number of milliseconds that have elapsed since the Unix epoch.|

**Example**
  ```js
  var calendar = i18n.getCalendar("en-US", "gregory");
  calendar.setTime(10540800000);
  ```


### set<sup>8+</sup>

set(year: number, month: number, date:number, hour?: number, minute?: number, second?: number): void

Sets the year, month, day, hour, minute, and second for this **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| year   | number | Yes   | Year to set. |
| month  | number | Yes   | Month to set. |
| date   | number | Yes   | Day to set. |
| hour   | number | No   | Hour to set.|
| minute | number | No   | Minute to set.|
| second | number | No   | Second to set. |

**Example**
  ```js
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00
  ```


### setTimeZone<sup>8+</sup>

setTimeZone(timezone: string): void

Sets the time zone of this **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description                       |
| -------- | ------ | ---- | ------------------------- |
| timezone | string | Yes   | Time zone, for example, **Asia/Shanghai**.|

**Example**
  ```js
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  ```


### getTimeZone<sup>8+</sup>

getTimeZone(): string

Obtains the time zone of this **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Time zone of the **Calendar** object.|

**Example**
  ```js
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  calendar.getTimeZone(); // Asia/Shanghai"
  ```


### getFirstDayOfWeek<sup>8+</sup>

getFirstDayOfWeek(): number

Obtains the start day of a week for this **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                   |
| ------ | --------------------- |
| number | Start day of a week. The value **1** indicates Sunday, and the value **7** indicates Saturday.|

**Example**
  ```js
  var calendar = i18n.getCalendar("en-US", "gregory");
  calendar.getFirstDayOfWeek();
  ```


### setFirstDayOfWeek<sup>8+</sup>

setFirstDayOfWeek(value: number): void

Sets the start day of a week for this **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                   |
| ----- | ------ | ---- | --------------------- |
| value | number | No   | Start day of a week. The value **1** indicates Sunday, and the value **7** indicates Saturday.|

**Example**
  ```js
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.setFirstDayOfWeek(0);
  ```


### getMinimalDaysInFirstWeek<sup>8+</sup>

getMinimalDaysInFirstWeek(): number

Obtains the minimum number of days in the first week of a year.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description          |
| ------ | ------------ |
| number | Minimum number of days in the first week of a year.|

**Example**
  ```js
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.getMinimalDaysInFirstWeek();
  ```


### setMinimalDaysInFirstWeek<sup>8+</sup>

setMinimalDaysInFirstWeek(value: number): void

Sets the minimum number of days in the first week of a year.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description          |
| ----- | ------ | ---- | ------------ |
| value | number | No   | Minimum number of days in the first week of a year.|

**Example**
  ```js
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.setMinimalDaysInFirstWeek(3);
  ```


### get<sup>8+</sup>

get(field: string): number

Obtains the value of the specified field in the **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| field | string | Yes   | Value of the specified field in the **Calendar** object. Currently, a valid field can be any of the following: **era**, **year**, **month**, **week\_of\_year**, **week\_of\_month**, **date**, **day\_of\_year**, **day\_of\_week**, **day\_of\_week\_in\_month**, **hour**, **hour\_of\_day**, **minute**, **second**, **millisecond**, **zone\_offset**, **dst\_offset**, **year\_woy**, **dow\_local**, **extended\_year**, **julian\_day**, **milliseconds\_in\_day**, **is\_leap\_month**.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Value of the specified field. For example, if the year in the internal date of this **Calendar** object is **1990**, the **get("year")** function will return **1990**.|

**Example**
  ```js
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00
  calendar.get("hour_of_day"); // 8
  ```


### getDisplayName<sup>8+</sup>

getDisplayName(locale: string): string

Obtains the **Calendar** object name displayed for the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | Locale for which the name of the **Calendar** object is displayed. For example, if **locale** is **en-US**, the name of the Buddhist calendar will be **Buddhist Calendar**.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | **Calendar** object name displayed for the specified locale.|

**Example**
  ```js
  var calendar = i18n.getCalendar("en-US", "buddhist");
  calendar.getDisplayName("zh"); // Obtain the name of the Buddhist calendar in zh.
  ```


### isWeekend<sup>8+</sup>

isWeekend(date?: Date): boolean

Checks whether the specified date in this **Calendar** object is a weekend.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | No   | Specified date in this **Calendar** object. If this parameter is left unspecified, the system checks whether the current date in the **Calendar** object is a weekend.|

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| boolean | Returns **true** if the date is a weekend; returns **false** if the date is a weekday.|

**Example**
  ```js
  var calendar = i18n.getCalendar("zh-Hans");
  calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.11.11 08:00:00
  calendar.isWeekend(); // false
  var date = new Date(2011, 11, 6, 9, 0, 0);
  calendar.isWeekend(date); // true
  ```


## PhoneNumberFormat<sup>8+</sup>


### constructor<sup>8+</sup>

constructor(country: string, options?: PhoneNumberFormatOptions)

Creates a **PhoneNumberFormat** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type                                      | Mandatory  | Description              |
| ------- | ---------------------------------------- | ---- | ---------------- |
| country | string                                   | Yes   | Country or region to which the phone number to be formatted belongs.|
| options | [PhoneNumberFormatOptions](#phonenumberformatoptions9) | No   | Options of the **PhoneNumberFormat** object. |

**Example**
  ```js
  var phoneNumberFormat= new i18n.PhoneNumberFormat("CN", {"type": "E164"});
  ```


### isValidNumber<sup>8+</sup>

isValidNumber(number: string): boolean

Checks whether the format of the specified phone number is valid.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description       |
| ------ | ------ | ---- | --------- |
| number | string | Yes   | Phone number to be checked.|

**Return value**

| Type     | Description                                   |
| ------- | ------------------------------------- |
| boolean | Returns **true** if the phone number format is valid; returns **false** otherwise.|

**Example**
  ```js
  var phonenumberfmt = new i18n.PhoneNumberFormat("CN");
  phonenumberfmt.isValidNumber("15812312312");
  ```


### format<sup>8+</sup>

format(number: string): string

Formats a phone number.

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
  ```js
  var phonenumberfmt = new i18n.PhoneNumberFormat("CN");
  phonenumberfmt.format("15812312312");
  ```


### getLocationName<sup>9+</sup>

getLocationName(number: string, locale: string): string

Obtains the home location of a phone number.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description  |
| ------ | ------ | ---- | ---- |
| number | string | Yes   | Phone number.|
| locale | string | Yes   | Locale ID.|

**Return value**

| Type    | Description      |
| ------ | -------- |
| string | Home location of the phone number.|

**Example**
  ```js
  var phonenumberfmt = new i18n.PhoneNumberFormat("CN");
  phonenumberfmt.getLocationName("15812312345", "zh-CN");
  ```


## PhoneNumberFormatOptions<sup>9+</sup>

Defines the options for this PhoneNumberFormat object.

**System capability**: SystemCapability.Global.I18n

| Name  | Type  | Readable  | Writable  | Description                                      |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | Yes   | Yes   | Format type of a phone number. The available options are as follows: E164,&nbsp;INTERNATIONAL,&nbsp;NATIONAL, and&nbsp;RFC3966.|


## UnitInfo<sup>8+</sup>

Defines the measurement unit information.

**System capability**: SystemCapability.Global.I18n

| Name           | Type  | Readable  | Writable  | Description                                      |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| unit          | string | Yes   | Yes   | Name of the measurement unit, for example, **meter**, **inch**, or **cup**.|
| measureSystem | string | Yes   | Yes   | Measurement system. The value can be **SI**,&nbsp;**US**, or&nbsp;**UK**.|


## getInstance<sup>8+</sup>

getInstance(locale?:string): IndexUtil

Creates an **IndexUtil** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                          |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | No   | A string containing locale information, including the language, optional script, and region.|

**Return value**

| Type                      | Description                   |
| ------------------------ | --------------------- |
| [IndexUtil](#indexutil8) | **IndexUtil** object mapping to the specified locale.|

**Example**
  ```js
  var indexUtil= i18n.getInstance("zh-CN");
  ```


## IndexUtil<sup>8+</sup>


### getIndexList<sup>8+</sup>

getIndexList(): Array&lt;string&gt;

Obtains the index list for this **locale** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description                |
| ------------------- | ------------------ |
| Array&lt;string&gt; | Index list for this **locale** object.|

**Example**
  ```js
  var indexUtil = i18n.getInstance("zh-CN");
  var indexList = indexUtil.getIndexList();
  ```


### addLocale<sup>8+</sup>

addLocale(locale: string): void

Adds the index of the new **locale** object to the index list.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                          |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | Yes   | A string containing locale information, including the language, optional script, and region.|

**Example**
  ```js
  var indexUtil = i18n.getInstance("zh-CN");
  indexUtil.addLocale("en-US");
  ```


### getIndex<sup>8+</sup>

getIndex(text: string): string

Obtains the index of a text object.

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
  ```js
  var indexUtil= i18n.getInstance("zh-CN");
  indexUtil.getIndex("hi"); // Return hi.
  ```


## i18n.getLineInstance<sup>8+</sup>

getLineInstance(locale: string): BreakIterator

Obtains a [BreakIterator](#breakiterator8) object for text segmentation.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | Valid locale value, for example, **zh-Hans-CN**. The [BreakIterator](#breakiterator8) object segments text according to the rules of the specified locale.|

**Return value**

| Type                              | Description         |
| -------------------------------- | ----------- |
| [BreakIterator](#breakiterator8) | [BreakIterator](#breakiterator8) object used for text segmentation.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  ```


## BreakIterator<sup>8+</sup>


### setLineBreakText<sup>8+</sup>

setLineBreakText(text: string): void

Sets the text to be processed by the [BreakIterator](#breakiterator8) object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description                     |
| ---- | ------ | ---- | ----------------------- |
| text | string | Yes   | Text to be processed by the **BreakIterator** object.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  ```


### getLineBreakText<sup>8+</sup>

getLineBreakText(): string

Obtains the text being processed by the [BreakIterator](#breakiterator8) object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                    |
| ------ | ---------------------- |
| string | Text being processed by the **BreakIterator** object.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.getLineBreakText(); // Apple is my favorite fruit.
  ```


### current<sup>8+</sup>

current(): number

Obtains the position of the [BreakIterator](#breakiterator8) object in the text being processed.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                         |
| ------ | --------------------------- |
| number | Position of the **BreakIterator** object in the text being processed.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.current(); // 0
  ```


### first<sup>8+</sup>

first(): number

Puts the [BreakIterator](#breakiterator8) object to the first text boundary, which is always at the beginning of the processed text.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description               |
| ------ | ----------------- |
| number | Offset to the first text boundary of the processed text.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.first(); // 0
  ```


### last<sup>8+</sup>

last(): number

Puts the [BreakIterator](#breakiterator8) object to the last text boundary, which is always the next position after the end of the processed text.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | Offset to the last text boundary of the processed text.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.last(); // 27
  ```


### next<sup>8+</sup>

next(index?: number): number

Moves the [BreakIterator](#breakiterator8) object backward by the specified number of text boundaries if the specified index is a positive number. If the index is a negative number, the [BreakIterator](#breakiterator8) object will be moved forward by the corresponding number of text boundaries. If no index is specified, the index will be treated as **1**.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| index | number | No   | Number of text boundaries by which the [BreakIterator](#breakiterator8) object is moved. A positive value indicates that the text boundary is moved backward, and a negative value indicates the opposite. If no index is specified, the index will be treated as **1**.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the [BreakIterator](#breakiterator8) object in the text after it is moved by the specified number of text boundaries. The value **-1** is returned if the position of the [BreakIterator](#breakiterator8) object is outside of the processed text after it is moved by the specified number of text boundaries.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.first(); // 0
  iterator.next(); // 6
  iterator.next(10); // -1
  ```


### previous<sup>8+</sup>

previous(): number

Moves the [BreakIterator](#breakiterator8) object to the previous text boundary.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the [BreakIterator](#breakiterator8) object in the text after it is moved to the previous text boundary. The value **-1** is returned if the position of the [BreakIterator](#breakiterator8) object is outside of the processed text after it is moved by the specified number of text boundaries.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.first(); // 0
  iterator.next(3); // 12
  iterator.previous(); // 9
  ```


### following<sup>8+</sup>

following(offset: number): number

Moves the [BreakIterator](#breakiterator8) object to the text boundary after the position specified by the offset. Position of the [BreakIterator](#breakiterator8) object after it is moved to the text boundary after the position specified by the offset.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| offset | number | Yes   | Offset to the position before the text boundary to which the [BreakIterator](#breakiterator8) object is moved.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | The value **-1** is returned if the text boundary to which the [BreakIterator](#breakiterator8) object is moved is outside of the processed text.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.following(0); // 6
  iterator.following(100); // -1
  iterator.current(); // 27
  ```


### isBoundary<sup>8+</sup>

isBoundary(offset: number): boolean

Checks whether the position specified by the offset is a text boundary. If **true** is returned, the [BreakIterator](#breakiterator8) object is moved to the position specified by the offset. If **false** is returned, the [BreakIterator](#breakiterator8) object is moved to the text boundary after the position specified by the offset, which is equivalent to calling [following](#following8)(offset).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description         |
| ------ | ------ | ---- | ----------- |
| offset | number | Yes   | Position to check.|

**Return value**

| Type     | Description                             |
| ------- | ------------------------------- |
| boolean | Returns **true** if the position specified by the offset is a text boundary; returns **false** otherwise.|

**Example**
  ```js
  var iterator = i18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  iterator.isBoundary(0); // true;
  iterator.isBoundary(5); // false;
  ```


## i18n.getTimeZone<sup>7+</sup>

getTimeZone(zoneID?: string): TimeZone

Obtains the **TimeZone** object corresponding to the specified time zone ID.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| zondID | string | No   | Time zone ID.|

**Return value**

| Type      | Description          |
| -------- | ------------ |
| TimeZone | **TimeZone** object corresponding to the time zone ID.|

**Example**
  ```js
  var timezone = i18n.getTimeZone();
  ```


## TimeZone


### getID

getID(): string

Obtains the ID of the specified **TimeZone** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Time zone ID corresponding to the **TimeZone** object.|

**Example**
  ```js
  var timezone = i18n.getTimeZone();
  timezone.getID();
  ```


### getDisplayName

getDisplayName(locale?: string, isDST?: boolean): string

Obtains the representation of a **TimeZone** object in the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type     | Mandatory  | Description                  |
| ------ | ------- | ---- | -------------------- |
| locale | string  | No   | Locale ID.               |
| isDST  | boolean | No   | Whether to consider DST when obtaining the representation of the **TimeZone** object.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Representation of the **TimeZone** object in the specified locale.|

**Example**
  ```js
  var timezone = i18n.getTimeZone();
  timezone.getDisplayName("zh-CN", false);
  ```


### getRawOffset

getRawOffset(): number

Obtains the offset between the time zone represented by a **TimeZone** object and the UTC time zone.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| number | Offset between the time zone represented by the **TimeZone** object and the UTC time zone.|

**Example**
  ```js
  var timezone = i18n.getTimeZone();
  timezone.getRawOffset();
  ```


### getOffset

getOffset(date?: number): number

Obtains the offset between the time zone represented by a **TimeZone** object and the UTC time zone at a certain time point.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| number | Offset between the time zone represented by the **TimeZone** object and the UTC time zone at a certain time point.|

**Example**
  ```js
  var timezone = i18n.getTimeZone();
  timezone.getOffset(1234567890);
  ```


### getAvailableIDs<sup>9+</sup>

static getAvailableIDs(): Array&lt;string&gt;

Obtains the list of time zone IDs supported by the system.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description         |
| ------------------- | ----------- |
| Array&lt;string&gt; | List of time zone IDs supported by the system.|

**Example**
  ```ts
  var ids = i18n.TimeZone.getAvailableIDs();
  ```


### getAvailableZoneCityIDs<sup>9+</sup>

static getAvailableZoneCityIDs(): Array&lt;string&gt;

Obtains the list of time zone city IDs supported by the system.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Array&lt;string&gt; | List of time zone city IDs supported by the system.|

**Example**
  ```ts
  var cityIDs = i18n.TimeZone.getAvailableZoneCityIDs();
  ```


### getCityDisplayName<sup>9+</sup>

static getCityDisplayName(cityID: string, locale: string): string

Obtains the localized display of a time zone city in the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| cityID | string | Yes   | Time zone city ID.|
| locale | string | Yes   | Locale ID.  |

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | Localized display of the time zone city in the specified locale.|

**Example**
  ```ts
  var displayName = i18n.TimeZone.getCityDisplayName("Shanghai", "zh-CN");
  ```


### getTimezoneFromCity<sup>9+</sup>

static getTimezoneFromCity(cityID: string): TimeZone

Obtains the **TimeZone** object corresponding to the specified time zone city ID.

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
  var timezone = i18n.TimeZone.getTimezoneFromCity("Shanghai");
  ```


## Transliterator<sup>9+</sup>


### getAvailableIDs<sup>9+</sup>

static getAvailableIDs(): string[]

Obtains a list of IDs supported by the **Transliterator** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type      | Description        |
| -------- | ---------- |
| string[] | List of IDs supported by the **Transliterator** object.|

**Example**
  ```ts
  i18n.Transliterator.getAvailableIDs();
  ```


### getInstance<sup>9+</sup>

static getInstance(id: string): Transliterator

Creates a **Transliterator** object.

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
  var transliterator = i18n.Transliterator.getInstance("Any-Latn");
  ```


### transform<sup>9+</sup>

transform(text: string): string

Converts the input string from the source format to the target format.

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
  var transliterator = i18n.Transliterator.getInstance("Any-Latn");
  transliterator.transform ("China");
  ```


## Unicode<sup>9+</sup>


### isDigit<sup>9+</sup>

static isDigit(char: string): boolean

Checks whether the input character string is composed of digits.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | Returns **true** if the input character is a digit; returns **false** otherwise.|

**Example**
  ```js
  var isdigit = i18n.Unicode.isDigit("1"); // Return true.
  ```


### isSpaceChar<sup>9+</sup>

static isSpaceChar(char: string): boolean

Checks whether the input character is a space.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | Returns **true** if the input character is a space; returns **false** otherwise.|

**Example**
  ```js
  var isspacechar = i18n.Unicode.isSpaceChar("a"); // Return false.
  ```


### isWhitespace<sup>9+</sup>

static isWhitespace(char: string): boolean

Checks whether the input character is a white space.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | Returns **true** if the input character is a white space; returns **false** otherwise.|

**Example**
  ```js
  var iswhitespace = i18n.Unicode.isWhitespace("a"); // Return false.
  ```


### isRTL<sup>9+</sup>

static isRTL(char: string): boolean

Checks whether the input character is of the right to left (RTL) language.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the input character is of the RTL language; returns **false** otherwise.|

**Example**
  ```js
  var isrtl = i18n.Unicode.isRTL("a"); // Return false.
  ```


### isIdeograph<sup>9+</sup>

static isIdeograph(char: string): boolean

Checks whether the input character is an ideographic character.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the input character is an ideographic character; returns **false** otherwise.|

**Example**
  ```js
  var isideograph = i18n.Unicode.isIdeograph("a"); // Return false.
  ```


### isLetter<sup>9+</sup>

static isLetter(char: string): boolean

Checks whether the input character is a letter.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | Returns **true** if the input character is a letter; returns **false** otherwise.|

**Example**
  ```js
  var isletter = i18n.Unicode.isLetter("a"); // Return true.
  ```


### isLowerCase<sup>9+</sup>

static isLowerCase(char: string): boolean

Checks whether the input character is a lowercase letter.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the input character is a lowercase letter; returns **false** otherwise.|

**Example**
  ```js
  var islowercase = i18n.Unicode.isLowerCase("a"); // Return true.
  ```


### isUpperCase<sup>9+</sup>

static isUpperCase(char: string): boolean

Checks whether the input character is an uppercase letter.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the input character is an uppercase letter; returns **false** otherwise.|

**Example**
  ```js
  var isuppercase = i18n.Unicode.isUpperCase("a"); // Return false.
  ```


### getType<sup>9+</sup>

static getType(char: string): string

Obtains the type of the input character string.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Type of the input character.|

**Example**
  ```js
  var type = i18n.Unicode.getType("a");
  ```


## I18NUtil<sup>9+</sup>


### unitConvert<sup>9+</sup>

static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

Converts one measurement unit into another and formats the unit based on the specified locale and style.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type                    | Mandatory  | Description                                      |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| fromUnit | [UnitInfo](#unitinfo8) | Yes   | Measurement unit to be converted.                                |
| toUnit   | [UnitInfo](#unitinfo8) | Yes   | Measurement unit to be converted to.                                |
| value    | number                 | Yes   | Value of the measurement unit to be converted.                            |
| locale   | string                 | Yes   | Locale used for formatting, for example, **zh-Hans-CN**.               |
| style    | string                 | No   | Style used for formatting. The value can be **long**, **short**, or **narrow**.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| string | Character string obtained after formatting based on the measurement unit specified by **toUnit**.|

**Example**
  ```js
  i18n.I18NUtil.unitConvert({unit: "cup", measureSystem: "US"}, {unit: "liter", measureSystem: "SI"}, 1000, "en-US", "long");
  ```


### getDateOrder<sup>9+</sup>

static getDateOrder(locale: string): string

Obtains the sequence of the year, month, and day in the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| locale | string | Yes   | Locale used for formatting, for example, **zh-Hans-CN**.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Sequence of the year, month, and day.|

**Example**
  ```js
  i18n.I18NUtil.getDateOrder("zh-CN");
  ```


## i18n.getDisplayCountry<sup>(deprecated)</sup>

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

Obtains the localized script for the specified country.

This API is deprecated since API version 9. You are advised to use [System.getDisplayCountry](#getdisplaycountry9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| country      | string  | Yes   | Specified country.           |
| locale       | string  | Yes   | Locale ID.    |
| sentenceCase | boolean | No   | Whether to use sentence case for the localized script.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified country.|

**Example**
  ```js
  i18n.getDisplayCountry("zh-CN", "en-GB", true);
  i18n.getDisplayCountry("zh-CN", "en-GB");
  ```


## i18n.getDisplayLanguage<sup>(deprecated)</sup>

getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

Obtains the localized script for the specified language.

This API is deprecated since API version 9. You are advised to use [System.getDisplayLanguage](#getdisplaylanguage9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name         | Type     | Mandatory  | Description              |
| ------------ | ------- | ---- | ---------------- |
| language     | string  | Yes   | Specified language.           |
| locale       | string  | Yes   | Locale ID.    |
| sentenceCase | boolean | No   | Whether to use sentence case for the localized script.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified language.|

**Example**
  ```js
  i18n.getDisplayLanguage("zh", "en-GB", true);
  i18n.getDisplayLanguage("zh", "en-GB");
  ```


## i18n.getSystemLanguage<sup>(deprecated)</sup>

getSystemLanguage(): string

Obtains the system language.

This API is deprecated since API version 9. You are advised to use [System.getSystemLanguage](#getsystemlanguage9) instead.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System language ID.|

**Example**
  ```js
  i18n.getSystemLanguage();
  ```


## i18n.getSystemRegion<sup>(deprecated)</sup>

getSystemRegion(): string

Obtains the system region.

This API is deprecated since API version 9. You are advised to use [System.getSystemRegion](#getsystemregion9) instead.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System region ID.|

**Example**
  ```js
  i18n.getSystemRegion();
  ```


## i18n.getSystemLocale<sup>(deprecated)</sup>

getSystemLocale(): string

Obtains the system locale.

This API is deprecated since API version 9. You are advised to use [System.getSystemLocale](#getsystemlocale9) instead.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System locale ID.|

**Example**
  ```js
  i18n.getSystemLocale();
  ```


## i18n.is24HourClock<sup>(deprecated)</sup>

is24HourClock(): boolean

Checks whether the 24-hour clock is used.

This API is deprecated since API version 9. You are advised to use [System.is24HourClock](#is24hourclock9) instead.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the 24-hour clock is used; returns **false** otherwise.|

**Example**
  ```js
  var is24HourClock = i18n.is24HourClock();
  ```


## i18n.set24HourClock<sup>(deprecated)</sup>

set24HourClock(option: boolean): boolean

Sets the 24-hour clock.

This API is deprecated since API version 9. You are advised to use [System.set24HourClock](#set24hourclock9) instead.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type     | Mandatory  | Description                                      |
| ------ | ------- | ---- | ---------------------------------------- |
| option | boolean | Yes   | Whether to enable the 24-hour clock. The value **true** means to enable the 24-hour clock, and the value **false** means the opposite.|

**Return value**

| Type     | Description                           |
| ------- | ----------------------------- |
| boolean | Returns **true** if the 24-hour clock is enabled; returns **false** otherwise.|

**Example**
  ```js
  // Set the system time to the 24-hour clock.
  var success = i18n.set24HourClock(true);
  ```


## i18n.addPreferredLanguage<sup>(deprecated)</sup>

addPreferredLanguage(language: string, index?: number): boolean

Adds a preferred language to the specified position on the preferred language list.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.addPreferredLanguage](#addpreferredlanguage9) instead.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description        |
| -------- | ------ | ---- | ---------- |
| language | string | Yes   | Preferred language to add. |
| index    | number | No   | Position to which the preferred language is added.|

**Return value**

| Type     | Description                           |
| ------- | ----------------------------- |
| boolean | Returns **true** if the preferred language is successfully added; returns **false** otherwise.|

**Example**
  ```js
  // Add zh-CN to the preferred language list.
  var language = 'zh-CN';
  var index = 0;
  var success = i18n.addPreferredLanguage(language, index);
  ```


## i18n.removePreferredLanguage<sup>(deprecated)</sup>

removePreferredLanguage(index: number): boolean

Deletes a preferred language from the specified position on the preferred language list.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.removePreferredLanguage](#removepreferredlanguage9) instead.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                   |
| ----- | ------ | ---- | --------------------- |
| index | number | Yes   | Position of the preferred language to delete.|

**Return value**

| Type     | Description                           |
| ------- | ----------------------------- |
| boolean | Returns **true** if the preferred language is deleted; returns **false** otherwise.|

**Example**
  ```js
  // Delete the first preferred language from the preferred language list.
  var index = 0;
  var success = i18n.removePreferredLanguage(index);
  ```


## i18n.getPreferredLanguageList<sup>(deprecated)</sup>

getPreferredLanguageList(): Array&lt;string&gt;

Obtains the list of preferred languages.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.getPreferredLanguageList](#getpreferredlanguagelist9) instead.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description       |
| ------------------- | --------- |
| Array&lt;string&gt; | List of preferred languages.|

**Example**
  ```js
  var preferredLanguageList = i18n.getPreferredLanguageList();
  ```


## i18n.getFirstPreferredLanguage<sup>(deprecated)</sup>

getFirstPreferredLanguage(): string

Obtains the first language in the preferred language list.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.getFirstPreferredLanguage](#getfirstpreferredlanguage9) instead.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description            |
| ------ | -------------- |
| string | First language in the preferred language list.|

**Example**
  ```js
  var firstPreferredLanguage = i18n.getFirstPreferredLanguage();
  ```


## Util<sup>(deprecated)</sup>


### unitConvert<sup>(deprecated)</sup>

static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

Converts one measurement unit into another and formats the unit based on the specified locale and style.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [unitConvert](#unitconvert9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type                    | Mandatory  | Description                                      |
| -------- | ---------------------- | ---- | ---------------------------------------- |
| fromUnit | [UnitInfo](#unitinfo8) | Yes   | Measurement unit to be converted.                                |
| toUnit   | [UnitInfo](#unitinfo8) | Yes   | Measurement unit to be converted to.                                |
| value    | number                 | Yes   | Value of the measurement unit to be converted.                            |
| locale   | string                 | Yes   | Locale used for formatting, for example, **zh-Hans-CN**.               |
| style    | string                 | No   | Style used for formatting. The value can be **long**, **short**, or **narrow**.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| string | Character string obtained after formatting based on the measurement unit specified by **toUnit**.|


## Character<sup>(deprecated)</sup>


### isDigit<sup>(deprecated)</sup>

static isDigit(char: string): boolean

Checks whether the input character string is composed of digits.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isDigit](#isdigit9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | Returns **true** if the input character is a digit; returns **false** otherwise.|


### isSpaceChar<sup>(deprecated)</sup>

static isSpaceChar(char: string): boolean

Checks whether the input character is a space.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isSpaceChar](#isspacechar9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | Returns **true** if the input character is a space; returns **false** otherwise.|


### isWhitespace<sup>(deprecated)</sup>

static isWhitespace(char: string): boolean

Checks whether the input character is a white space.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isWhitespace](#iswhitespace9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| boolean | Returns **true** if the input character is a white space; returns **false** otherwise.|


### isRTL<sup>(deprecated)</sup>

static isRTL(char: string): boolean

Checks whether the input character is of the right to left (RTL) language.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isRTL](#isrtl9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the input character is of the RTL language; returns **false** otherwise.|


### isIdeograph<sup>(deprecated)</sup>

static isIdeograph(char: string): boolean

Checks whether the input character is an ideographic character.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isIdeograph](#isideograph9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the input character is an ideographic character; returns **false** otherwise.|


### isLetter<sup>(deprecated)</sup>

static isLetter(char: string): boolean

Checks whether the input character is a letter.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isLetter](#isletter9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | Returns **true** if the input character is a letter; returns **false** otherwise.|


### isLowerCase<sup>(deprecated)</sup>

static isLowerCase(char: string): boolean

Checks whether the input character is a lowercase letter.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isLowerCase](#islowercase9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the input character is a lowercase letter; returns **false** otherwise.|


### isUpperCase<sup>(deprecated)</sup>

static isUpperCase(char: string): boolean

Checks whether the input character is an uppercase letter.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [isUpperCase](#isuppercase9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the input character is an uppercase letter; returns **false** otherwise.|


### getType<sup>(deprecated)</sup>

static getType(char: string): string

Obtains the type of the input character string.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [getType](#gettype9) instead.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | Type of the input character.|
