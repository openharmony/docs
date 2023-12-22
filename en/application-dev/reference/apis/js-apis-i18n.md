# @ohos.i18n (Internationalization)

 This module provides system-related or enhanced i18n capabilities, such as locale management, phone number formatting, and calendar, through supplementary i18n APIs that are not defined in ECMA 402.
The [intl](js-apis-intl.md) module provides basic i18n capabilities through the standard i18n APIs defined in ECMA 402. It works with the **i18n** module to provide a complete suite of i18n capabilities.

>  **NOTE**
>  - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - This module provides system-related or enhanced i18n capabilities, such as locale management, phone number formatting, and calendar, through supplementary i18n APIs that are not defined in ECMA 402. For details about the basic I18N capabilities, see [intl](js-apis-intl.md).


## Modules to Import

```ts
import I18n from '@ohos.i18n';
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
| sentenceCase | boolean | No   | Whether to use sentence case for the localized script. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified country.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
      let displayCountry: string = I18n.System.getDisplayCountry("zh-CN", "en-GB"); // displayCountry = "China"
  } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call System.getDisplayCountry failed, error code: ${err.code}, message: ${err.message}.`);
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
| sentenceCase | boolean | No   | Whether to use sentence case for the localized script. The default value is **true**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Localized script for the specified language.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let displayLanguage: string = I18n.System.getDisplayLanguage("zh", "en-GB"); // displayLanguage = Chinese
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getDisplayLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLanguages<sup>9+</sup>

static getSystemLanguages(): Array&lt;string&gt;

Obtains the list of system languages. For details about languages, see [Instantiating the Locale Object](../../internationalization/intl-guidelines.md#how-to-develop).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Array&lt;string&gt; | List of the IDs of system languages.|

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemLanguages: Array<string> = I18n.System.getSystemLanguages(); // [ "en-Latn-US", "zh-Hans" ]
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemLanguages failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemCountries<sup>9+</sup>

static getSystemCountries(language: string): Array&lt;string&gt;

Obtains the list of countries and regions supported for the specified language. For details about countries or regions, see [Instantiating the Locale Object](../../internationalization/intl-guidelines.md#how-to-develop).

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description   |
| -------- | ------ | ---- | ----- |
| language | string | Yes   | Language ID.|

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Array&lt;string&gt; | List of the IDs of the countries and regions supported for the specified language.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemCountries: Array<string> = I18n.System.getSystemCountries('zh'); // systemCountries = [ "ZW", "YT", "YE", ..., "ER", "CN", "DE" ], 240 countries or regions in total
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemCountries failed, error code: ${err.code}, message: ${err.message}.`);
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
| region   | string | No   | Valid region ID, for example, **CN**. The default value is the country or region where the SIM card is used. |

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the system language matches the specified region, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let res: boolean = I18n.System.isSuggested('zh', 'CN');  // res = true
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.isSuggested failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLanguage<sup>9+</sup>

static getSystemLanguage(): string

Obtains the system language. For details about languages, see [Instantiating the Locale Object](../../internationalization/intl-guidelines.md#how-to-develop).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System language ID.|

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemLanguage: string = I18n.System.getSystemLanguage();  // systemLanguage indicates the current system language.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setSystemLanguage<sup>9+</sup>

static setSystemLanguage(language: string): void

Sets the system language. Currently, this API does not support real-time updating of the system language.

To listen for [common_event_locale_changed](./commonEventManager-definitions.md#common_event_locale_changed) events after the system language is set, you need to add an [event subscriber](./js-apis-commonEventManager.md#commoneventmanagercreatesubscriber-1).

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description   |
| -------- | ------ | ---- | ----- |
| language | string | Yes   | Language ID.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';
  import CommonEventManager from '@ohos.commonEventManager';

  // Set the system language
  try {
    I18n.System.setSystemLanguage('zh'); // Set the current system language to zh.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
 
  // Subscribe to a common event.
  let subscriber: CommonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.
  let subscribeInfo: CommonEventManager.CommonEventSubscribeInfo = { // Define the subscriber information.
    events: [CommonEventManager.Support.COMMON_EVENT_LOCALE_CHANGED]
  };
  CommonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber:CommonEventManager.CommonEventSubscriber) => { // Create a subscriber.
      console.info("createSubscriber");
      subscriber = commonEventSubscriber;
      CommonEventManager.subscribe(subscriber, (err, data) => {
        if (err) {
          console.error(`Failed to subscribe common event. error code: ${err.code}, message: ${err.message}.`);
          return;
        }
        console.info("the subscribed event has occurred."); // Triggered when the subscribed event occurs.
      })
  }).catch((err: BusinessError) => {
      console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  });  
  ```

### getSystemRegion<sup>9+</sup>

static getSystemRegion(): string

Obtains the system region. For details about system regions, see [Instantiating the Locale Object](../../internationalization/intl-guidelines.md#how-to-develop).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System region ID.|

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemRegion: string = I18n.System.getSystemRegion(); // Obtain the current system region.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setSystemRegion<sup>9+</sup>

static setSystemRegion(region: string): void

Sets the system region.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| region | string | Yes   | System region ID.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    I18n.System.setSystemRegion('CN'); // Set the current system region to CN.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getSystemLocale<sup>9+</sup>

static getSystemLocale(): string

Obtains the system locale. For details about system locales, see [Instantiating the Locale Object](../../internationalization/intl-guidelines.md#how-to-develop).

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | System locale ID.|

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let systemLocale: string = I18n.System.getSystemLocale();  // Obtain the current system locale.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setSystemLocale<sup>9+</sup>

static setSystemLocale(locale: string): void

Sets the system locale.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| locale | string | Yes   | System locale ID, for example, **zh-CN**.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    I18n.System.setSystemLocale('zh-CN'); // Set the current system locale to zh-CN.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### is24HourClock<sup>9+</sup>

static is24HourClock(): boolean

Checks whether the 24-hour clock is used.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the 24-hour clock is used, and the value **false** indicates the opposite.|

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let is24HourClock: boolean = I18n.System.is24HourClock();  // Check whether the 24-hour clock is enabled.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.is24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### set24HourClock<sup>9+</sup>

static set24HourClock(option: boolean): void

Sets the system time to the 24-hour clock.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type     | Mandatory  | Description                                      |
| ------ | ------- | ---- | ---------------------------------------- |
| option | boolean | Yes   | Whether to enable the 24-hour clock. The value **true** means to enable the 24-hour clock, and the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  // Set the system time to the 24-hour clock.
  try {
    I18n.System.set24HourClock(true);
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### addPreferredLanguage<sup>9+</sup>

static addPreferredLanguage(language: string, index?: number): void

Adds a preferred language to the specified position on the preferred language list.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description        |
| -------- | ------ | ---- | ---------- |
| language | string | Yes   | Preferred language to add. |
| index    | number | No   | Position to which the preferred language is added. The default value is the length of the preferred language list.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  // Add zh-CN to the preferred language list.
  let language = 'zh-CN';
  let index = 0;
  try {
    I18n.System.addPreferredLanguage(language, index); // Add zh-CN to the first place in the preferred language list.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.addPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### removePreferredLanguage<sup>9+</sup>

static removePreferredLanguage(index: number): void

Deletes a preferred language from the specified position on the preferred language list.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                   |
| ----- | ------ | ---- | --------------------- |
| index | number | Yes   | Position of the preferred language to delete.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  // Delete the first preferred language from the preferred language list.
  let index: number = 0;
  try {
    I18n.System.removePreferredLanguage(index);
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.removePreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
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

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let preferredLanguageList: Array<string> = I18n.System.getPreferredLanguageList(); // Obtain the current preferred language list.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getPreferredLanguageList failed, error code: ${err.code}, message: ${err.message}.`);
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

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let firstPreferredLanguage: string = I18n.System.getFirstPreferredLanguage();  // Obtain the first language in the preferred language list.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getFirstPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setAppPreferredLanguage<sup>11+</sup>

static setAppPreferredLanguage(language: string): void

Sets the preferred language of the application.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description   |
| -------- | ------ | ---- | ----- |
| language | string | Yes   | Language ID.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    I18n.System.setAppPreferredLanguage('zh'); // Set the current language of the application to zh.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
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

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let appPreferredLanguage: string = I18n.System.getAppPreferredLanguage(); // Obtain the preferred language of an application.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setUsingLocalDigit<sup>9+</sup>

static setUsingLocalDigit(flag: boolean): void

Specifies whether to enable use of local digits.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type     | Mandatory  | Description                             |
| ---- | ------- | ---- | ------------------------------- |
| flag | boolean | Yes   | Whether to turn on the local digit switch. The value **true** means to turn on the local digit switch, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    I18n.System.setUsingLocalDigit(true); // Enable the local digit switch.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getUsingLocalDigit<sup>9+</sup>

static getUsingLocalDigit(): boolean

Checks whether use of local digits is enabled.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the local digit switch is turned on, and the value **false** indicates the opposite.|

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let status: boolean = I18n.System.getUsingLocalDigit();  // Check whether the local digit switch is enabled.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.getUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


## I18n.isRTL<sup>7+</sup>

isRTL(locale: string): boolean

Checks whether a locale uses an RTL language.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| locale | string | Yes   | Locale ID.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | The value **true** indicates that the localized script is displayed from right to left, and the value **false** indicates the opposite.|

**Example**
  ```ts
  i18n.isRTL("zh-CN");// Since Chinese is not written from right to left, false is returned.
  i18n.isRTL("ar-EG");// Since Arabic is written from right to left, true is returned.
  ```


## I18n.getCalendar<sup>8+</sup>

getCalendar(locale: string, type? : string): Calendar

Obtains a **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | Valid locale value, for example, **zh-Hans-CN**.                |
| type   | string | No   | Valid calendar type. Currently, the valid types are as follows: **buddhist**, **chinese**, **coptic**, **ethiopic**, **hebrew**, **gregory**, **indian**, **islamic\_civil**, **islamic\_tbla**, **islamic\_umalqura**, **japanese**, and **persian**. The default value is the default calendar type of the locale.|

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| [Calendar](#calendar8) | **Calendar** object.|

**Example**
  ```ts
  I18n.getCalendar("zh-Hans", "chinese"); // Obtain the Calendar object for the Chinese lunar calendar.
  ```

## EntityRecognizer<sup>11+</sup>

### constructor<sup>11+</sup>

constructor(locale?: string)

Creates an **entityRecognizer** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| locale | string | No   | Locale ID.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  let entityRecognizer: I18n.EntityRecognizer = new I18n.EntityRecognizer("zh-CN");
  ```

### findEntityInfo<sup>11+</sup>

findEntityInfo(text: string): Array&lt;EntityInfoItem&gt;

Recognizes entities in text.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description               |
| ---- | ---- | ---- | ----------------- |
| text | string | Yes   | Text for entity recognition.|

**Return value**

| Type  | Description               |
| ---- | ----------------- |
| Array&lt;[EntityInfoItem](#entityinfoitem11)&gt; | List of recognized entities.|

**Example**
  ```ts
  let entityRecognizer: I18n.EntityRecognizer = new I18n.EntityRecognizer("zh-CN");
  let text1: string = " If you have any questions, call us by phone 12345678";
  let result1: Array<I18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text1); // result[0].type = "phone_number", result[0].begin = 8, result[0].end = 19
  let text2: string = "Let's have dinner on December 1, 2023."
  let result2: Array<I18n.EntityInfoItem> = entityRecognizer.findEntityInfo(text2); // result[0].type = "date", result[0].begin = 2, result[0].end = 12
  ```

## EntityInfoItem<sup>11+</sup>

Defines an entity information object.

**System capability**: SystemCapability.Global.I18n

| Name | Type  | Readable  | Writable  | Description               |
| ---- | ---- | ---- | ---- | ----------------- |
| type | string | Yes   | Yes   | Entity type, which can be **phone_number** or **date**.|
| begin | number | Yes   | Yes   | Start position of an entity.|
| end | number | Yes   | Yes   | End position of an entity.|

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
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("en-US", "gregory");
  let date: Date = new Date(2021, 10, 7, 8, 0, 0, 0);
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
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("en-US", "gregory");
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
| hour   | number | No   | Hour to set. The default value is the system hour.|
| minute | number | No   | Minute to set. The default value is the system minute.|
| second | number | No   | Second to set. The default value is the system second.|

**Example**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
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
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
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
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.setTimeZone("Asia/Shanghai");
  let timezone: string = calendar.getTimeZone(); // timezone = "Asia/Shanghai"
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
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("en-US", "gregory");
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1
  ```


### setFirstDayOfWeek<sup>8+</sup>

setFirstDayOfWeek(value: number): void

Sets the start day of a week for this **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                   |
| ----- | ------ | ---- | --------------------- |
| value | number | Yes   | Start day of a week. The value **1** indicates Sunday, and the value **7** indicates Saturday.|

**Example**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.setFirstDayOfWeek(3);
  let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 3
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
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 1
  ```


### setMinimalDaysInFirstWeek<sup>8+</sup>

setMinimalDaysInFirstWeek(value: number): void

Sets the minimum number of days in the first week of a year.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description          |
| ----- | ------ | ---- | ------------ |
| value | number | Yes   | Minimum number of days in the first week of a year.|

**Example**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.setMinimalDaysInFirstWeek(3);
  let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 3
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
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.set(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00
  let hourOfDay: number = calendar.get("hour_of_day"); // hourOfDay = 8
  ```


### getDisplayName<sup>8+</sup>

getDisplayName(locale: string): string

Obtains the displayed name of the **Calendar** object for the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| locale | string | Yes   | Locale for the displayed name of the **Calendar** object. For example, displayed name of **buddhist** is **Buddhist Calendar** when the locale is set to **en-US**.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Displayed name of the **Calendar** object for the specified locale.|

**Example**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("en-US", "buddhist");
  let calendarName: string = calendar.getDisplayName("zh"); // calendarName = "Buddhist Calendar"
  ```


### isWeekend<sup>8+</sup>

isWeekend(date?: Date): boolean

Checks whether a given date is a weekend in the calendar.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | No   | Specified date. If this parameter is left empty, the system checks whether the current date is a weekend. The default value is the system date.|

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| boolean | The value **true** indicates that the specified date is a weekend, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.11.11 08:00:00
  calendar.isWeekend(); // false
  let date: Date = new Date(2011, 11, 6, 9, 0, 0);
  calendar.isWeekend(date); // true
  ```


### add<sup>11+</sup>

add(field: string, amount: number): void

Performs addition and subtraction operations on the specified field of the **Calendar** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| field | string | Yes   | Specified field of the **Calendar** object. The supported value year, month, week_of_year, week_of_month, date, day_of_year, day_of_week, day_of_week_in_month, hour, hour_of_day, minute, second, millisecond.|
| amount | number | Yes   | Addition or subtraction amount.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
    calendar.set(2021, 11, 11, 8, 0, 0); // set time to 2021.11.11 08:00:00
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

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| number | Number of milliseconds that have elapsed since the Unix epoch.|

**Example**
  ```ts
  let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
  calendar.setTime(5000);
  let millisecond: number = calendar.getTimeInMillis(); // millisecond = 5000
  ```


### compareDays<sup>11+</sup>

compareDays(date: Date): number

Compares the number of days between the calendar date and the specified date. The value is accurate to milliseconds. If the value is less than one day, it is treated as one day.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type  | Mandatory  | Description                                      |
| ---- | ---- | ---- | ---------------------------------------- |
| date | Date | Yes   | Specified date.|

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| number | Number of days between the calendar date and the specified date. A positive number indicates that the calendar date is earlier, and a negative number indicates the opposite.|

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let calendar: I18n.Calendar = I18n.getCalendar("zh-Hans");
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

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type                                      | Mandatory  | Description              |
| ------- | ---------------------------------------- | ---- | ---------------- |
| country | string                                   | Yes   | Country or region to which the phone number to be formatted belongs.|
| options | [PhoneNumberFormatOptions](#phonenumberformatoptions8) | No   | Options of the **PhoneNumberFormat** object. The default value is **NATIONAL**. |

**Example**
  ```ts
  let option: I18n.PhoneNumberFormatOptions = {type: "E164"};
  let phoneNumberFormat: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN", option);
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
| boolean | The value **true** indicates that the phone number format is valid, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let phonenumberfmt: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN");
  let isValidNumber: boolean = phonenumberfmt.isValidNumber("158****2312"); // isValidNumber = true
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
  ```ts
  let phonenumberfmt: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN");
  let formattedPhoneNumber: string = phonenumberfmt.format("158****2312"); // formattedPhoneNumber = "158 **** 2312"
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
  ```ts
  let phonenumberfmt: I18n.PhoneNumberFormat = new I18n.PhoneNumberFormat("CN");
  let locationName: string = phonenumberfmt.getLocationName("158****2345", "zh-CN"); // locationName = "Zhanjiang, Guangdong Province"
  ```


## PhoneNumberFormatOptions<sup>8+</sup>

Defines the options for this PhoneNumberFormat object.

**System capability**: SystemCapability.Global.I18n

| Name  | Type    | Readable  | Writable  | Description                                      |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | Yes   | Yes   | Format type of a phone number. The value can be **E164**, **INTERNATIONAL**, **NATIONAL**, or **RFC3966**.<br>- In API version 8, **type** is mandatory.<br>- In API version 9 or later, **type** is optional.|


## UnitInfo<sup>8+</sup>

Defines the measurement unit information.

**System capability**: SystemCapability.Global.I18n

| Name           | Type    | Readable  | Writable  | Description                                      |
| ------------- | ------ | ---- | ---- | ---------------------------------------- |
| unit          | string | Yes   | Yes   | Name of the measurement unit, for example, **meter**, **inch**, or **cup**.|
| measureSystem | string | Yes   | Yes   | Measurement system. The value can be **SI**, **US**, or **UK**.|


## getInstance<sup>8+</sup>

getInstance(locale?:string): IndexUtil

Creates an **IndexUtil** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                          |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | No   | A string containing locale information, including the language, optional script, and region. The default value is the system locale.|

**Return value**

| Type                      | Description                   |
| ------------------------ | --------------------- |
| [IndexUtil](#indexutil8) | **IndexUtil** object mapping to the **locale** object.|

**Example**
  ```ts
  let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");
  ```


## IndexUtil<sup>8+</sup>


### getIndexList<sup>8+</sup>

getIndexList(): Array&lt;string&gt;

Obtains the index list for this **locale** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                 | Description                |
| ------------------- | ------------------ |
| Array&lt;string&gt; | Index list for the **locale** object.|

**Example**
  ```ts
  let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");
  // indexList = [ "...", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
  //              "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "..." ]
  let indexList: Array<string> = indexUtil.getIndexList();
  ```


### addLocale<sup>8+</sup>

addLocale(locale: string): void

Adds a **locale** object to the current index list.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                          |
| ------ | ------ | ---- | ---------------------------- |
| locale | string | Yes   | A string containing locale information, including the language, optional script, and region.|

**Example**
  ```ts
  let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");
  indexUtil.addLocale("en-US");
  ```


### getIndex<sup>8+</sup>

getIndex(text: string): string

Obtains the index of a **text** object.

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
  let indexUtil: I18n.IndexUtil = I18n.getInstance("zh-CN");
  let index: string = indexUtil.getIndex("hi");  // index = "H"
  ```


## I18n.getLineInstance<sup>8+</sup>

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
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  ```


## BreakIterator<sup>8+</sup>


### setLineBreakText<sup>8+</sup>

setLineBreakText(text: string): void

Sets the text to be processed by the **BreakIterator** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description                     |
| ---- | ------ | ---- | ----------------------- |
| text | string | Yes   | Text to be processed by the **BreakIterator** object.|

**Example**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit ."); // Set a short sentence as the text to be processed by the BreakIterator object.
  ```


### getLineBreakText<sup>8+</sup>

getLineBreakText(): string

Obtains the text being processed by the **BreakIterator** object.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                    |
| ------ | ---------------------- |
| string | Text being processed by the **BreakIterator** object.|

**Example**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let breakText: string = iterator.getLineBreakText(); // breakText = "Apple is my favorite fruit."
  ```


### current<sup>8+</sup>

current(): number

Obtains the position of the **BreakIterator** object in the text being processed.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                         |
| ------ | --------------------------- |
| number | Position of the **BreakIterator** object in the text being processed.|

**Example**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let currentPos: number = iterator.current(); // currentPos = 0
  ```


### first<sup>8+</sup>

first(): number

Puts the **BreakIterator** object to the first break point, which is always at the beginning of the processed text.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description               |
| ------ | ----------------- |
| number | Offset to the first break point of the processed text.|

**Example**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let firstPos: number = iterator.first(); // firstPos = 0
  ```


### last<sup>8+</sup>

last(): number

Puts the **BreakIterator** object to the last break point, which is always the next position after the end of the processed text.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | Offset to the last break point of the processed text.|

**Example**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let lastPos: number = iterator.last(); // lastPos = 27
  ```


### next<sup>8+</sup>

next(index?: number): number

Moves the **BreakIterator** object backward by the corresponding number of break points.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| index | number | No   | Number of break points to be moved by the **BreakIterator** object. A positive value indicates that the break point is moved backward by the specified number of break points, and a negative value indicates the opposite. The default value is **1**.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the **BreakIterator** object in the text after it is moved by the specified number of break points. The value **-1** is returned if the position of the [BreakIterator](#breakiterator8) object is outside of the processed text after it is moved by the specified number of break points.|

**Example**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(); // pos = 6
  pos = iterator.next(10); // pos = -1
  ```


### previous<sup>8+</sup>

previous(): number

Moves the **BreakIterator** object forward by one break point.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Position of the **BreakIterator** object in the text after it is moved to the previous break point. The value **-1** is returned if the position of the [BreakIterator](#breakiterator8) object is outside of the processed text after it is moved by the specified number of break points.|

**Example**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.first(); // pos = 0
  pos = iterator.next(3); // pos = 12
  pos = iterator.previous(); // pos = 9
  ```


### following<sup>8+</sup>

following(offset: number): number

Moves the **BreakIterator** to the break point following the specified position.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| offset | number | Yes   | Moves the **BreakIterator** to the break point following the specified position.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | The value **-1** is returned if the break point to which the **BreakIterator** object is moved is outside of the processed text.|

**Example**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let pos: number = iterator.following(0); // pos = 6
  pos = iterator.following(100); // pos = -1
  pos = iterator.current(); // pos = 27
  ```


### isBoundary<sup>8+</sup>

isBoundary(offset: number): boolean

Checks whether the specified position of the text is a break point.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description         |
| ------ | ------ | ---- | ----------- |
| offset | number | Yes   | Offset to the specified position of the text. The value **true** is returned if the position specified by **offset** is a break point, and the value **false** is returned otherwise. If **true** is returned, the **BreakIterator** object is moved to the position specified by **offset**. Otherwise, **following** is called.|

**Return value**

| Type     | Description                             |
| ------- | ------------------------------- |
| boolean | The value **true** indicates that the position specified by the offset is a break point, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let iterator: I18n.BreakIterator = I18n.getLineInstance("en");
  iterator.setLineBreakText("Apple is my favorite fruit.");
  let isBoundary: boolean = iterator.isBoundary(0); // isBoundary = true;
  isBoundary = iterator.isBoundary(5); // isBoundary = false;
  ```


## I18n.getTimeZone<sup>7+</sup>

getTimeZone(zoneID?: string): TimeZone

Obtains the **TimeZone** object corresponding to the specified time zone ID.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| zondID | string | No   | Time zone ID. The default value is the system time zone.|

**Return value**

| Type      | Description          |
| -------- | ------------ |
| [TimeZone](#timezone) | **TimeZone** object corresponding to the time zone ID.|

**Example**
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
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
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
  let timezoneID: string = timezone.getID(); // timezoneID = "Asia/Shanghai"
  ```


### getDisplayName

getDisplayName(locale?: string, isDST?: boolean): string

Obtains the localized representation of a **TimeZone** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type     | Mandatory  | Description                  |
| ------ | ------- | ---- | -------------------- |
| locale | string  | No   | Locale ID. The default value is the system locale.               |
| isDST  | boolean | No   | Whether DST is considered in the localized representation of the **TimeZone** object. The default value is **false**.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Representation of the **TimeZone** object in the specified locale.|

**Example**
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
  let timezoneName: string = timezone.getDisplayName("zh-CN", false); // timezoneName = "China Standard Time"
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
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
  let offset: number = timezone.getRawOffset(); // offset = 28800000
  ```


### getOffset

getOffset(date?: number): number

Obtains the offset between the time zone represented by a **TimeZone** object and the UTC time zone at a certain time.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| date | number | No   | Date and time.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| number | Offset between the time zone represented by the **TimeZone** object and the UTC time zone at a certain time. The default value is the system time.|

**Example**
  ```ts
  let timezone: I18n.TimeZone = I18n.getTimeZone();
  let offset: number = timezone.getOffset(1234567890); // offset = 28800000
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
  // ids = ["America/Adak", "America/Anchorage", "America/Bogota", "America/Denver", "America/Los_Angeles", "America/Montevideo", "America/Santiago", "America/Sao_Paulo", "Asia/Ashgabat", "Asia/Hovd", "Asia/Jerusalem", "Asia/Magadan", "Asia/Omsk", "Asia/Shanghai", "Asia/Tokyo", "Asia/Yerevan", "Atlantic/Cape_Verde", "Australia/Lord_Howe", "Europe/Dublin", "Europe/London", "Europe/Moscow", "Pacific/Auckland", "Pacific/Easter", "Pacific/Pago-Pago"], 24 time zones supported in total
  let ids: Array<string> = I18n.TimeZone.getAvailableIDs();
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
  // cityIDs = ["Auckland", "Magadan", "Lord Howe Island", "Tokyo", "Shanghai", "Hovd", "Omsk", "Ashgabat", "Yerevan", "Moscow", "Tel Aviv", "Dublin", "London", "Praia", "Montevideo", "Brasília", "Santiago", "Bogotá", "Easter Island", "Salt Lake City", "Los Angeles", "Anchorage", "Adak", "Pago Pago"], 24 time zone cities supported in total
  let cityIDs: Array<string> = I18n.TimeZone.getAvailableZoneCityIDs();
  ```


### getCityDisplayName<sup>9+</sup>

static getCityDisplayName(cityID: string, locale: string): string

Obtains the localized representation of a time zone city in the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description    |
| ------ | ------ | ---- | ------ |
| cityID | string | Yes   | Time zone city ID.|
| locale | string | Yes   | Locale ID.  |

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | Localized representation of the time zone city in the specified locale.|

**Example**
  ```ts
  let displayName: string = I18n.TimeZone.getCityDisplayName("Shanghai", "zh-CN"); // displayName = "Shanghai (China)"
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
  let timezone: I18n.TimeZone = I18n.TimeZone.getTimezoneFromCity("Shanghai");
  ```

### getTimezonesByLocation<sup>10+</sup>

static getTimezonesByLocation(longitude: number, latitude: number): Array&lt;TimeZone&gt;

Creates an array of **TimeZone** objects corresponding to the specified longitude and latitude.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name    | Type    | Mandatory  | Description    |
| --------- | ------ | ---- | ------ |
| longitude | number | Yes   | Longitude. The value ranges from **-180** to **179.9**. A positive value is used for east longitude and a negative value is used for west longitude.|
| latitude  | number | Yes   | Latitude. The value ranges from **-90** to **89.9**. A positive value is used for north latitude and a negative value is used for south latitude.|

**Return value**

| Type      | Description         |
| -------- | ----------- |
| Array&lt;[TimeZone](#timezone)&gt; | Array of **TimeZone** objects.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  let timezoneArray: Array<I18n.TimeZone> = I18n.TimeZone.getTimezonesByLocation(-118.1, 34.0);
  for (let i = 0; i < timezoneArray.length; i++) {
      let tzId: string = timezoneArray[i].getID();
  }
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
  // A total of 671 IDs are supported. One ID is comprised of two parts separated by a hyphen (-) in the format of source-destination. For example, in **ids = ["Han-Latin","Latin-ASCII", "Amharic-Latin/BGN","Accents-Any", ...]**, **Han-Latin** indicates conversion from Chinese to Latin, and **Amharic-Latin** indicates conversion from Amharic to Latin.
  // For more information, see ISO-15924.
  let ids: string[] = I18n.Transliterator.getAvailableIDs();
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
  let transliterator: I18n.Transliterator = I18n.Transliterator.getInstance("Any-Latn");
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
  let transliterator: I18n.Transliterator = I18n.Transliterator.getInstance("Any-Latn");
  let res: string = transliterator.transform("China"); // res = "zhōng guó"
  ```


## Unicode<sup>9+</sup>


### isDigit<sup>9+</sup>

static isDigit(char: string): boolean

Checks whether the input string is composed of digits.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| char | string | Yes   | Input character.|

**Return value**

| Type     | Description                                  |
| ------- | ------------------------------------ |
| boolean | The value **true** indicates that the input character is a digit, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isdigit: boolean = I18n.Unicode.isDigit("1");  // isdigit = true
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
| boolean | The value **true** indicates that the input character is a space, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isspacechar: boolean = I18n.Unicode.isSpaceChar("a");  // isspacechar = false
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
| boolean | The value **true** indicates that the input character is a white space, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let iswhitespace: boolean = I18n.Unicode.isWhitespace("a");  // iswhitespace = false
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
| boolean | The value **true** indicates that the input character is of the RTL language, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isrtl: boolean = I18n.Unicode.isRTL("a");  // isrtl = false
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
| boolean | The value **true** indicates that the input character is an ideographic character, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isideograph: boolean = I18n.Unicode.isIdeograph("a");  // isideograph = false
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
| boolean | The value **true** indicates that the input character is a letter, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isletter: boolean = I18n.Unicode.isLetter("a");  // isletter = true
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
| boolean | The value **true** indicates that the input character is a lowercase letter, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let islowercase: boolean = I18n.Unicode.isLowerCase("a");  // islowercase = true
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
| boolean | The value **true** indicates that the input character is an uppercase letter, and the value **false** indicates the opposite.|

**Example**
  ```ts
  let isuppercase: boolean = I18n.Unicode.isUpperCase("a");  // isuppercase = false
  ```


### getType<sup>9+</sup>

static getType(char: string): string

Obtains the type of the input string.

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
  let type: string = I18n.Unicode.getType("a"); // type = "U_LOWERCASE_LETTER"
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
| style    | string                 | No   | Style used for formatting. The value can be **long**, **short**, or **narrow**. The default value is **short**.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| string | String obtained after formatting based on the measurement unit specified by **toUnit**.|

**Example**
  ```ts
  let fromUnit: I18n.UnitInfo = {unit: "cup", measureSystem: "US"};
  let toUnit: I18n.UnitInfo = {unit: "liter", measureSystem: "SI"};
  let res: string = I18n.I18NUtil.unitConvert(fromUnit, toUnit, 1000, "en-US", "long"); // res = 236.588 liters
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
| string | Sequence of the year, month, and day in the locale.|

**Example**
  ```ts
  let order: string = I18n.I18NUtil.getDateOrder("zh-CN");  // order = "y-L-d"
  ```


### getTimePeriodName<sup>11+</sup>

static getTimePeriodName(hour:number, locale?: string): string

Obtains the localized expression for the specified time of the specified locale.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| hour | number | Yes   | Specified time, for example, **16**.|
| locale | string | No   | Specified locale. By default, the locale of the application is used, for example, **zh-Hans-CN**.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Localized expression for the specified time of the specified locale.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let name: string = I18n.I18NUtil.getTimePeriodName(2, "zh-CN");  // name = "a.m."
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call I18NUtil.getTimePeriodName failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


## Normalizer<sup>10+</sup>

### getInstance<sup>10+</sup>

static getInstance(mode: NormalizerMode): Normalizer

Obtains a **Normalizer** object for text normalization.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| mode | [NormalizerMode](#normalizermode10) | Yes   | Text normalization mode.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| [Normalizer](#normalizer10) | **Normalizer** object for text normalization.|

**Example**
  ```ts
  let normalizer: I18n.Normalizer = I18n.Normalizer.getInstance(I18n.NormalizerMode.NFC);
  ```


### normalize<sup>10+</sup>

normalize(text: string): string

Normalizes text strings.

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description                       |
| ------ | ------ | ---- | ------------------------- |
| text | string | Yes   | Text strings to be normalized.|

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| string | Normalized text strings.|

**Example**
  ```ts
  let normalizer: I18n.Normalizer = I18n.Normalizer.getInstance(I18n.NormalizerMode.NFC);
  let normalizedText: string = normalizer.normalize('\u1E9B\u0323'); // normalizedText = \u1E9B\u0323
  ```


## NormalizerMode<sup>10+</sup>

Enumerates text normalization modes.

**System capability**: SystemCapability.Global.I18n

| Name| Value| Description|
| -------- | -------- | -------- |
| NFC | 1 | NFC.|
| NFD | 2 | NFD.|
| NFKC | 3 | NFKC.|
| NFKD | 4 | NFKD.|


## SystemLocaleManager<sup>10+</sup>


### constructor<sup>10+</sup>

constructor()

Creates a **SystemLocaleManager** object.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  let systemLocaleManager: I18n.SystemLocaleManager = new I18n.SystemLocaleManager();
  ```


### getLanguageInfoArray<sup>10+</sup>

getLanguageInfoArray(languages: Array&lt;string&gt;, options?: SortOptions): Array&lt;LocaleItem&gt;

Obtains the language sorting array.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| languages | Array&lt;string&gt; | Yes  | List of languages to be sorted.|
| options   | [SortOptions](#sortoptions10)   | No  | Language sorting option.|

**Return value**

|       Type       |         Description         |
| ----------------- | -------------------- |
| Array&lt;[LocaleItem](#localeitem10)&gt; | Language list after sorting.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid  |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  // Assume that the system language is zh-Hans, the system region is CN, and the system locale is zh-Hans-CN.
  let systemLocaleManager: I18n.SystemLocaleManager = new I18n.SystemLocaleManager();
  let languages: string[] = ["zh-Hans", "en-US", "pt", "ar"];
  let sortOptions: I18n.SortOptions = {locale: "zh-Hans-CN", isUseLocalName: true, isSuggestedFirst: true};
  try {
      // The language list after sorting is [zh-Hans, en-US, pt, ar].
      let sortedLanguages: Array<I18n.LocaleItem> = systemLocaleManager.getLanguageInfoArray(languages, sortOptions);
  } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call systemLocaleManager.getLanguageInfoArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getRegionInfoArray<sup>10+</sup>

getRegionInfoArray(regions: Array&lt;string&gt;, options?: SortOptions): Array&lt;LocaleItem&gt;

Obtains the country/region sorting array.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| regions   | Array&lt;string&gt; | Yes  | List of countries/regions to be sorted.|
| options   | [SortOptions](#sortoptions10)   | No  | Country/region sorting option. The default value of **locale** is the system locale, the default value of **isUseLocalName** is **false**, and the default value of **isSuggestedFirst** is **true**.|

**Return value**

|       Type       |         Description         |
| ----------------- | -------------------- |
| Array&lt;[LocaleItem](#localeitem10)&gt; | Country/region list after sorting.|

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid  |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  // Assume that the system language is zh-Hans, the system region is CN, and the system locale is zh-Hans-CN.
  let systemLocaleManager: I18n.SystemLocaleManager = new I18n.SystemLocaleManager();
  let regions: string[] = ["CN", "US", "PT", "EG"];
  let sortOptions: I18n.SortOptions = {locale: "zh-Hans-CN", isUseLocalName: false, isSuggestedFirst: true};
  try {
      // The country/region list after sorting is [CN, EG, US, PT].
      let sortedRegions: Array<I18n.LocaleItem> = systemLocaleManager.getRegionInfoArray(regions, sortOptions);
  } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call systemLocaleManager.getRegionInfoArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getTimeZoneCityItemArray<sup>10+</sup>

static getTimeZoneCityItemArray(): Array&lt;TimeZoneCityItem&gt;

Obtains the array of time zone city items after sorting.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

|       Type       |         Description         |
| ----------------- | -------------------- |
| Array&lt;[TimeZoneCityItem](#timezonecityitem10)&gt; | Array of time zone city items.|

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let timeZoneCityItemArray: Array<I18n.TimeZoneCityItem> = I18n.SystemLocaleManager.getTimeZoneCityItemArray();
    for (let i = 0; i < timeZoneCityItemArray.length; i++) {
        console.log(timeZoneCityItemArray[i].zoneId + ", " + timeZoneCityItemArray[i].cityId + ", " + timeZoneCityItemArray[i].cityDisplayName +
            ", " + timeZoneCityItemArray[i].offset + "\r\n");
    }
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call SystemLocaleManager.getTimeZoneCityItemArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## LocaleItem<sup>10+</sup>

Represents the list of languages or countries/regions sorted by **SystemLocaleManager**.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

| Name           | Type           |  Mandatory  |  Description                                  |
| --------------- | --------------- | ------ | --------------------------------------- |
| id              | string          |   Yes  | Language code or country/region code, for example, **zh** or **CN**.   |
| suggestionType  | [SuggestionType](#suggestiontype10)  |   Yes | Language or country/region suggestion type.                 |
| displayName     | string          |  Yes  | Displayed name of ID in the locale of **SystemLocaleManager**.|
| localName       | string          |  No  | Local name of the ID.                          |

## TimeZoneCityItem<sup>10+</sup>

Represents the time zone and city combination information.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Mandatory  |  Description                                  |
| --------------- | --------------- | ------  | --------------------------------------- |
| zoneId          | string          |   Yes   | Time zone ID, for example, **Asia/Shanghai**.             |
| cityId          | string          |   Yes   | City ID, for example, **Shanghai**.                  |
| cityDisplayName | string          |   Yes   | Displayed name of the city ID in the system locale.         |
| offset          | int             |   Yes   | Offset of the time zone ID.                        |
| zoneDisplayName | string          |   Yes   | Displayed name of the time zone ID in the system locale.         |
| rawOffset       | int             |   No   | Fixed offset of the time zone ID.                      |


## SuggestionType<sup>10+</sup>

Represents the language or country/region suggestion type.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

| Name                  | Value | Description  |
| ---------------------- | ---- | ---- |
| SUGGESTION_TYPE_NONE   | 0x00 | Not a recommended language or country/region.|
| SUGGESTION_TYPE_RELATED| 0x01 | Country/region recommended by the system language or language recommended by the system country/region.|
| SUGGESTION_TYPE_SIM    | 0x02 | Language recommended by the country/region of the SIM card.|


## SortOptions<sup>10+<sup>

Represents the language or country/region sorting option.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

| Name           | Type           |  Mandatory|   Description                                |
| --------------- | --------------- | ---- | --------------------------------------- |
| locale          | string          |  No | System locale, for example, **zh-Hans-CN**. The default value of **locale** is the system locale.   |
| isUseLocalName  | boolean         |  No | Whether to use the local name for sorting. If **getLanguageInfoArray** is called, the default value of **isUseLocalName** is **true**. If **getRegionInfoArray** is called, the default value of **isUseLocalName** is **false**.               |
| isSuggestedFirst | boolean        |  No | Whether to move the recommended language or country/region to the top in the sorting result. The default value of **isSuggestedFirst** is **true**. |


## HolidayManager<sup>11+</sup>

### constructor<sup>11+</sup>

constructor(icsPath: String)

Creates a **HolidayManager** object.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| icsPath   | String | Yes  | Path of the **.ics** file with the read permission granted for applications. |

**Error codes**

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid  |

**Example**
  ```ts
  let holidayManager= new I18n.HolidayManager("/system/lib/US.ics");
  ```

### isHoliday<sup>11+</sup>

isHoliday(date?: Date): boolean;

Determines whether the specified date is a holiday.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ---------------| ---- | ------------- |
| date      | Date           | No  | **Date** object.<br>If no date is specified, the current date is used by default.|

**Return value**

|       Type       |         Description         |
| ----------------- | ----------------------|
| boolean           | The value **true** indicates that the specified date is a holiday, and the value **false** indicates the opposite.|

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let holidayManager= new I18n.HolidayManager("/system/lib/US.ics");
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

For details about the error codes, see [I18N Error Codes](../errorcodes/errorcode-i18n.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 890001 | param value not valid  |

**Example**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let holidayManager= new I18n.HolidayManager("/system/lib/US.ics");
    let holidayInfoItemArray = holidayManager.getHolidayInfoItemArray(2023);
    for (let i =0 ;i < holidayInfoItemArray.length; i++) {
        console.log(JSON.stringify(holidayInfoItemArray[i]));
    }
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call holidayManager.getHolidayInfoItemArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

## HolidayInfoItem<sup>11+</sup>

Represents the holiday information.

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

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Mandatory  |  Description                                  |
| --------------- | -----------------| ------  | --------------------------------------- |
| language        | string           |   Yes   | Local language of a holiday, for example, **ar**, **en**, or **tr**.         |
| name            | string           |   Yes   | Local name of a holiday. For example, the Turkish name of Sacrifice Feast is Kurban Bayrami.     |


## I18n.getDisplayCountry<sup>(deprecated)</sup>

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
  let countryName: string = I18n.getDisplayCountry("zh-CN", "en-GB", true); // countryName = true
  countryName = I18n.getDisplayCountry("zh-CN", "en-GB"); // countryName = true
  ```


## I18n.getDisplayLanguage<sup>(deprecated)</sup>

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
  let languageName: string = I18n.getDisplayLanguage("zh", "en-GB", true); // languageName = "Chinese"
  languageName = I18n.getDisplayLanguage("zh", "en-GB"); // languageName = "Chinese"
  ```


## I18n.getSystemLanguage<sup>(deprecated)</sup>

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
  let systemLanguage: string = I18n.getSystemLanguage(); // Obtain the current system language.
  ```


## I18n.getSystemRegion<sup>(deprecated)</sup>

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
  let region: string = I18n.getSystemRegion(); // Obtain the current system region.
  ```


## I18n.getSystemLocale<sup>(deprecated)</sup>

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
  let locale: string = I18n.getSystemLocale (); // Obtain the system locale.
  ```


## I18n.is24HourClock<sup>(deprecated)</sup>

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
  let is24HourClock: boolean = I18n.is24HourClock();
  ```


## I18n.set24HourClock<sup>(deprecated)</sup>

set24HourClock(option: boolean): boolean

Sets the 24-hour clock.

This API is deprecated since API version 9. You are advised to use [System.set24HourClock](#set24hourclock9).

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
  let success: boolean = I18n.set24HourClock(true);
  ```


## I18n.addPreferredLanguage<sup>(deprecated)</sup>

addPreferredLanguage(language: string, index?: number): boolean

Adds a preferred language to the specified position on the preferred language list.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.addPreferredLanguage](#addpreferredlanguage9).

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
  let success: boolean = I18n.addPreferredLanguage(language, index);
  ```


## I18n.removePreferredLanguage<sup>(deprecated)</sup>

removePreferredLanguage(index: number): boolean

Deletes a preferred language from the specified position on the preferred language list.

This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [System.removePreferredLanguage](#removepreferredlanguage9).

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
  let success: boolean = I18n.removePreferredLanguage(index);
  ```


## I18n.getPreferredLanguageList<sup>(deprecated)</sup>

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
  let preferredLanguageList: Array<string> = I18n.getPreferredLanguageList(); // Obtain the preferred language list.
  ```


## I18n.getFirstPreferredLanguage<sup>(deprecated)</sup>

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
  let firstPreferredLanguage: string = I18n.getFirstPreferredLanguage();
  ```


## Util<sup>(deprecated)</sup>


### unitConvert<sup>(deprecated)</sup>

static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string

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

static isDigit(char: string): boolean

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

static isSpaceChar(char: string): boolean

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

static isWhitespace(char: string): boolean

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

static isRTL(char: string): boolean

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

static isIdeograph(char: string): boolean

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

static isLetter(char: string): boolean

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

static isLowerCase(char: string): boolean

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

static isUpperCase(char: string): boolean

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

static getType(char: string): string

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
