# @ohos.i18n (Internationalization) (System API)

 This module provides system-related or enhanced i18n capabilities, such as locale management, phone number formatting, and calendar, through supplementary i18n APIs that are not defined in ECMA 402. The [intl](js-apis-intl.md) module provides basic i18n capabilities through the standard i18n APIs defined in ECMA 402. It works with the **i18n** module to provide a complete suite of i18n capabilities.

>  **NOTE**
>  - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - Since API version 11, some APIs of this module are supported in ArkTS widgets.
>
>  - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.i18n (Internationalization)](js-apis-intl.md).


## Modules to Import

```ts
import { i18n } from '@kit.LocalizationKit';
```

## System<sup>9+</sup>

### setSystemLanguage<sup>9+</sup>

static setSystemLanguage(language: string): void

Sets the system language.

To listen for system language changes, enable listening for [COMMON_EVENT_LOCALE_CHANGED](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_locale_changed).

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name     | Type    | Mandatory  | Description   |
| -------- | ------ | ---- | ----- |
| language | string | Yes   | Valid language ID.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError, commonEventManager } from '@kit.BasicServicesKit';

  // Set the system language
  try {
    i18n.System.setSystemLanguage('zh'); // Set the current system language to zh.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
 
  // Subscribe to a common event.
  let subscriber: commonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.
  let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = { // Define subscriber information.
    events: [commonEventManager.Support.COMMON_EVENT_LOCALE_CHANGED]
  };
  commonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber:commonEventManager.CommonEventSubscriber) => { // Create a subscriber.
      console.info("createSubscriber");
      subscriber = commonEventSubscriber;
      commonEventManager.subscribe(subscriber, (err, data) => {
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

### setSystemRegion<sup>9+</sup>

static setSystemRegion(region: string): void

Sets the system region.

To listen for system region changes, enable listening for [COMMON_EVENT_LOCALE_CHANGED](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_locale_changed).

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| region | string | Yes   | Valid region ID.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setSystemRegion('CN'); // Set the current system region to CN.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```



### setSystemLocale<sup>9+</sup>

static setSystemLocale(locale: string): void

Sets the system locale.

To listen for system locale changes, enable listening for [COMMON_EVENT_LOCALE_CHANGED](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_locale_changed).

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| locale | string | Yes   | [System locale](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setSystemLocale('zh-CN'); // Set the system locale to zh-CN.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### set24HourClock<sup>9+</sup>

static set24HourClock(option: boolean): void

Sets whether to use the 24-hour clock.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name   | Type     | Mandatory  | Description                                      |
| ------ | ------- | ---- | ---------------------------------------- |
| option | boolean | Yes   | Whether to use the 24-hour clock. The value **true** means to use the 24-hour clock, the the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Set the system time to the 24-hour clock.
  try {
    i18n.System.set24HourClock(true);
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
| language | string | Yes   | Valid ID of the language to be added as a preferred language. |
| index    | number | No   | Position to which the preferred language is added. The default value is the length of the preferred language list.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Add zh-CN to the preferred language list.
  let language = 'zh-CN';
  let index = 0;
  try {
    i18n.System.addPreferredLanguage(language, index); // Add zh-CN to the first place in the preferred language list.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.addPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### removePreferredLanguage<sup>9+</sup>

static removePreferredLanguage(index: number): void

Removes a preferred language from the specified position on the preferred language list.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name  | Type    | Mandatory  | Description                   |
| ----- | ------ | ---- | --------------------- |
| index | number | Yes   | Position of the preferred language to delete.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Delete the first preferred language from the preferred language list.
  let index: number = 0;
  try {
    i18n.System.removePreferredLanguage(index);
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.removePreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
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

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setUsingLocalDigit(true); // Enable the local digit switch.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### setTemperatureType<sup>18+</sup>

static setTemperatureType(type: TemperatureType): void

Sets the temperature unit of the system.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type     | Mandatory  | Description                             |
| ---- | ------- | ---- | ------------------------------- |
| type | [TemperatureType](./js-apis-i18n.md#temperaturetype18) | Yes| Temperature unit.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

> **NOTE**
>
> The error message of 890001 is subject to the actual error.

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setTemperatureType(i18n.TemperatureType.CELSIUS); //: Set the temperature unit to °C.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setTemperatureType failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### setFirstDayOfWeek<sup>18+</sup>

static setFirstDayOfWeek(type: WeekDay): void

Sets the first day of a week.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type     | Mandatory  | Description                             |
| ---- | ------- | ---- | ------------------------------- |
| type | [WeekDay](./js-apis-i18n.md#weekday18) | Yes| Start day of a week.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

> **NOTE**
>
> The error message of 890001 is subject to the actual error.

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    i18n.System.setFirstDayOfWeek (i18n.WeekDay.MON); // Set the preferred start day of a week to Monday.
  } catch(error) {
    let err: BusinessError = error as BusinessError;
    console.error(`call System.setFirstDayOfWeek failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


## SystemLocaleManager<sup>10+</sup>

### constructor<sup>10+</sup>

constructor()

Creates a **SystemLocaleManager** object.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Example**
  ```ts
  let systemLocaleManager: i18n.SystemLocaleManager = new i18n.SystemLocaleManager();
  ```


### getLanguageInfoArray<sup>10+</sup>

getLanguageInfoArray(languages: Array&lt;string&gt;, options?: SortOptions): Array&lt;LocaleItem&gt;

Obtains the list of languages after sorting.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| languages | Array&lt;string&gt; | Yes  | Valid IDs of the languages to be sorted.|
| options   | [SortOptions](#sortoptions10)   | No  | Language sorting option.|

**Return value**

|       Type       |         Description         |
| ----------------- | -------------------- |
| Array&lt;[LocaleItem](#localeitem10)&gt; | Language list after sorting.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Assume that the system language is zh-Hans, the system region is CN, and the system locale is zh-Hans-CN.
  let systemLocaleManager: i18n.SystemLocaleManager = new i18n.SystemLocaleManager();
  let languages: string[] = ["zh-Hans", "en-US", "pt", "ar"];
  let sortOptions: i18n.SortOptions = {locale: "zh-Hans-CN", isUseLocalName: true, isSuggestedFirst: true};
  try {
      // The language list after sorting is [zh-Hans, en-US, pt, ar].
      let sortedLanguages: Array<i18n.LocaleItem> = systemLocaleManager.getLanguageInfoArray(languages, sortOptions);
  } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call systemLocaleManager.getLanguageInfoArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```


### getRegionInfoArray<sup>10+</sup>

getRegionInfoArray(regions: Array&lt;string&gt;, options?: SortOptions): Array&lt;LocaleItem&gt;

Obtains the IDs of the countries or regions after sorting.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Parameters**

|   Name |      Type     | Mandatory|     Description     |
| --------- | ------------- | ---- | ------------- |
| regions   | Array&lt;string&gt; | Yes  | Valid IDs of the countries or regions to be sorted.|
| options   | [SortOptions](#sortoptions10)   | No  | Country/region sorting option.<br>By default, **locale** is the current system locale, **isUseLocalName** is **false**, and **isSuggestedFirst** is **true**.|

**Return value**

|       Type       |         Description         |
| ----------------- | -------------------- |
| Array&lt;[LocaleItem](#localeitem10)&gt; | IDs of the countries or regions after sorting.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 890001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Assume that the system language is zh-Hans, the system region is CN, and the system locale is zh-Hans-CN.
  let systemLocaleManager: i18n.SystemLocaleManager = new i18n.SystemLocaleManager();
  let regions: string[] = ["CN", "US", "PT", "EG"];
  let sortOptions: i18n.SortOptions = {locale: "zh-Hans-CN", isUseLocalName: false, isSuggestedFirst: true};
  try {
      // The country/region list after sorting is [CN, EG, US, PT].
      let sortedRegions: Array<i18n.LocaleItem> = systemLocaleManager.getRegionInfoArray(regions, sortOptions);
  } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call systemLocaleManager.getRegionInfoArray failed, error code: ${err.code}, message: ${err.message}.`);
  }
  ```

### getTimeZoneCityItemArray<sup>10+</sup>

static getTimeZoneCityItemArray(): Array&lt;TimeZoneCityItem&gt;

Obtains list of time zone city items after sorting.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

|       Type       |         Description         |
| ----------------- | -------------------- |
| Array&lt;[TimeZoneCityItem](#timezonecityitem10)&gt; | List of time zone city items after sorting.|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let timeZoneCityItemArray: Array<i18n.TimeZoneCityItem> = i18n.SystemLocaleManager.getTimeZoneCityItemArray();
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

Represents the locale information, which consists of the language, script, and country/region.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

| Name           | Type           |  Mandatory  |  Description                                  |
| --------------- | --------------- | ------ | --------------------------------------- |
| id              | string          |   Yes  | Language code or country/region code, for example, **zh** or **CN**.   |
| suggestionType  | [SuggestionType](#suggestiontype10)  |   Yes | Language or country/region suggestion type.                 |
| displayName     | string          |  Yes  | Representation of ID in the specified locale in **SystemLocaleManager**.|
| localName       | string          |  No  | Local name of the ID.                          |

## TimeZoneCityItem<sup>10+</sup>

Represents a time zone and city combination item.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Mandatory  |  Description                                  |
| --------------- | --------------- | ------  | --------------------------------------- |
| zoneId          | string          |   Yes   | Time zone ID, for example, **Asia/Shanghai**.             |
| cityId          | string          |   Yes   | City ID, for example, Shanghai.                  |
| cityDisplayName | string          |   Yes   | City display name in the system locale.         |
| offset          | int             |   Yes   | Offset of the time zone ID.                        |
| zoneDisplayName | string          |   Yes   | Time zone display name in the system locale.         |
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
| locale          | string          |  No | [Locale information](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region, for example, **zh-Hans-CN**.<br>The default value is the current system locale.   |
| isUseLocalName  | boolean         |  No | Whether to use the local name for sorting. The value **true** means to use the local name for sorting, and the value **false** means the opposite.<br>If **getLanguageInfoArray** is called, the default value of **isUseLocalName** is **true**.<br>If **getRegionInfoArray** is called, the default value of **isUseLocalName** is **false**.               |
| isSuggestedFirst | boolean        |  No | Whether to move the recommended language or country/region to the top in the sorting result. The value **true** means to move the recommended language or country/region to the top, and the value **false** means the opposite.<br>The default value is **true**. |
