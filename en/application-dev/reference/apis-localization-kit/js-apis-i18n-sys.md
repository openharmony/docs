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

### getSystemCollations<sup>20+</sup>

static getSystemCollations(): Map&lt;string, string&gt;

Obtains the collation modes supported by the system and their names. If the system language is English, the system supports the collation mode where uppercase letters come before lowercase letters or vice versa.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | Collation modes supported by the system and their names. The **Map** object employs the key-value format, where the key is a string that indicates the collation mode, and the value is a string that indicates its name. The range of supported collation modes is subject to the system language.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let systemCollations: Map<string, string> = i18n.System.getSystemCollations();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemCollations failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getUsingCollation<sup>20+</sup>

static getUsingCollation(): string

Obtains the current collation mode of the system.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | Current collation mode of the system.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let usingCollation: string = i18n.System.getUsingCollation();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getUsingCollation failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemCollation<sup>20+</sup>

static setSystemCollation(identifier: string): void

Sets the collation mode used by the system.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type     | Mandatory  | Description                             |
| ---- | ------- | ---- | ------------------------------- |
| identifier | string | Yes| Collation mode used by the system. You can obtain the range supported collation modes by calling [getSystemCollations](#getsystemcollations20).|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemCollation("zhuyin"); // If the specified collation mode is not supported, an error is reported.
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemCollation failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getSystemNumberingSystems<sup>20+</sup>

static getSystemNumberingSystems(): Map&lt;string, string&gt;

Obtains the numbering systems supported by the system and examples. The examples illustrate the display of digits 0 to 9 in the corresponding numbering system.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | Numbering systems supported by the system and examples. The **Map** object employs the key-value format, where the key is a string that indicates the numbering system, and the value indicates an example. The range of supported numbering systems is subject to the system language.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let systemNumberingSystems: Map<string, string> = i18n.System.getSystemNumberingSystems();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemNumberingSystems failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemNumberingSystem<sup>20+</sup>

static setSystemNumberingSystem(identifier: string):void

Sets the numbering system used by the system.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type     | Mandatory  | Description                             |
| ---- | ------- | ---- | ------------------------------- |
| identifier | string | Yes| Numbering system used by the system. You can obtain the range of supported numbering systems by calling [getSystemNumberingSystems](#getsystemnumberingsystems20).|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemNumberingSystem("arab"); // If the specified numbering system is not supported, an error is reported.
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemNumberingSystem failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getSystemNumberPatterns<sup>20+</sup>

static getSystemNumberPatterns(): Map&lt;string, string&gt;

Obtains the number patterns supported by the system and examples. A number pattern determines the format of the thousands separator and decimal separator in numbers.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | Number patterns supported by the system and examples. The **Map** object employs the key-value format, where the key is the number pattern (represented by Unicode code of the thousand separator and decimal separator), and the value indicates an example. The range of supported number patterns is subject to the system language.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let systemNumberPatterns: Map<string, string> = i18n.System.getSystemNumberPatterns();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemNumberPatterns failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getUsingNumberPattern<sup>20+</sup>

static getUsingNumberPattern(): string

Obtains the current number pattern of the system.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | Current number pattern of the system.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let usingNumberPattern: string = i18n.System.getUsingNumberPattern();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getUsingNumberPattern failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemNumberPattern<sup>20+</sup>

static setSystemNumberPattern(pattern: string): void

Sets the number pattern used by the system.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type     | Mandatory  | Description                             |
| ---- | ------- | ---- | ------------------------------- |
| pattern | string | Yes| Number pattern used by the system. You can obtain the range of supported number patterns by calling [getSystemNumberPatterns](#getsystemnumberpatterns20).|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemNumberPattern("002e002c"); // If the specified number pattern is not supported, an error is reported.
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemNumberPattern failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getSystemMeasurements<sup>20+</sup>

static getSystemMeasurements(): Map&lt;string, string&gt;

Obtains the measurement systems supported by the system and their names.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | Measurement systems supported by the system and their names. The **Map** object employs the key-value format, where the key indicates the ID of the measurement system, and the value indicates its name. The supported measurement systems are as follows:<br>- **metric**: metric system<br>- **uksystem**: imperial system<br>- **ussystem**: US system|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let systemMeasurements: Map<string, string> = i18n.System.getSystemMeasurements();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemMeasurements failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getUsingMeasurement<sup>20+</sup>

static getUsingMeasurement(): string

Obtains the current measurement system of the system.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | Current measurement system of the system. The supported measurement systems are as follows:<br>- **metric**: metric system<br>- **uksystem**: imperial system<br>- **ussystem**: US system|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let usingMeasurement: string = i18n.System.getUsingMeasurement();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getUsingMeasurement failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemMeasurement<sup>20+</sup>

static setSystemMeasurement(identifier: string): void

Sets the measurement system used by the system.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type     | Mandatory  | Description                             |
| ---- | ------- | ---- | ------------------------------- |
| identifier | string | Yes| Measurement system used by the system. You can obtain the range of supported measurement systems by calling [getSystemMeasurements](#getsystemmeasurements20).|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemMeasurement("uksystem"); // If the specified measurement system is not supported, error code 8900001 is reported.
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemMeasurement failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getSystemNumericalDatePatterns<sup>20+</sup>

static getSystemNumericalDatePatterns(): Map&lt;string, string&gt;

Obtains the numerical date patterns supported by the system and examples.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| Map&lt;string, string&gt; | Numerical date patterns supported by the system and examples. The **Map** object employs the key-value format, where the key indicates the numerical date pattern, for example, `dd/MM/y`, and the value indicates an example, for example, `18/07/2025`.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let datePatterns: Map<string, string> = i18n.System.getSystemNumericalDatePatterns();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getSystemNumericalDatePatterns failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### getUsingNumericalDatePattern<sup>20+</sup>

static getUsingNumericalDatePattern(): string

Obtains the current numerical date pattern of the system.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

**Return value**

| Type                    | Description   |
| ---------------------- | ----- |
| string | Current numerical date pattern of the system.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  let datePattern: string = i18n.System.getUsingNumericalDatePattern();
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.getUsingNumericalDatePattern failed, error code: ${err.code}, message: ${err.message}.`);
}
```

### setSystemNumericalDatePattern<sup>20+</sup>

static setSystemNumericalDatePattern(identifier: string): void

Sets the numerical date pattern used by the system.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Global.I18n

**Parameters**

| Name | Type     | Mandatory  | Description                             |
| ---- | ------- | ---- | ------------------------------- |
| identifier | string | Yes| Numerical date pattern used by the system. You can obtain the range of supported numerical date patterns by calling [getSystemNumericalDatePatterns](#getsystemnumericaldatepatterns20).|

**Error codes**

For details about the error codes, see [ohos.i18n Error Codes](errorcode-i18n.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| ------ | ---------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 8900001 | Invalid parameter. Possible causes: Parameter verification failed. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n } from '@kit.LocalizationKit';

try {
  i18n.System.setSystemNumericalDatePattern("dd/MM/y"); // If the specified numerical date pattern is not supported, error code 8900001 is reported.
} catch(error) {
  let err: BusinessError = error as BusinessError;
  console.error(`call System.setSystemNumericalDatePattern failed, error code: ${err.code}, message: ${err.message}.`);
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

| Name           | Type           | Read-Only| Optional  |  Description                                  |
| --------------- | --------------- | ------ | ------ | --------------------------------------- |
| id              | string          |   No  |   No  | Language code or country/region code, for example, **zh** or **CN**.   |
| suggestionType  | [SuggestionType](#suggestiontype10)  |   No  |   No | Language or country/region suggestion type.                 |
| displayName     | string          |   No  |  No  | Representation of ID in the specified locale in **SystemLocaleManager**.|
| localName       | string          |   No  |  Yes  | Local name of the ID. This option is available only when the language information is presented.     |

## TimeZoneCityItem<sup>10+</sup>

Represents a time zone and city combination item.

**System API**: This is a system API.

**System capability**: SystemCapability.Global.I18n

| Name           | Type            |  Read-Only  |  Optional  |  Description                                  |
| --------------- | --------------- | ------  | ------  | --------------------------------------- |
| zoneId          | string          |   No   |   No   | Time zone ID, for example, **Asia/Shanghai**.             |
| cityId          | string          |   No   |   No   | City ID, for example, Shanghai.                  |
| cityDisplayName | string          |   No   |   No   | City display name in the system locale.         |
| offset          | number             |   No   |   No   | Offset of the time zone ID.                        |
| zoneDisplayName | string          |   No   |   No   | Time zone display name in the system locale.         |
| rawOffset       | number             |   No   |   Yes   | Fixed offset of the time zone ID.                      |


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

| Name           | Type           |  Read-Only|  Optional|   Description                                |
| --------------- | --------------- | ---- | ---- | --------------------------------------- |
| locale          | string          |  No |  Yes | [Locale information](../../internationalization/i18n-locale-culture.md#how-it-works), which consists of the language, script, and country/region, for example, **zh-Hans-CN**.<br>The default value is the current system locale.   |
| isUseLocalName  | boolean         |  No |  Yes | Whether to use the local name for sorting. The value **true** means to use the local name for sorting, and the value **false** means the opposite.<br>If **getLanguageInfoArray** is called, the default value of **isUseLocalName** is **true**.<br>If **getRegionInfoArray** is called, the default value of **isUseLocalName** is **false**.               |
| isSuggestedFirst | boolean        |  No |  Yes | Whether to move the recommended language or country/region to the top in the sorting result. The value **true** means to move the recommended language or country/region to the top, and the value **false** means the opposite.<br>The default value is **true**. |
