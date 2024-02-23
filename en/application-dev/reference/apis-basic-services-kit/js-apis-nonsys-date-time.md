# @ohos.systemDateTime (System Time and Time Zone)

The **systemDateTime** module provides system time and time zone features. You can use the APIs of this module to set and obtain the system time and time zone.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import systemDateTime from '@ohos.systemDateTime';
```

## TimeType<sup>10+</sup>

Enumerates the types of time to obtain.

**System capability**: SystemCapability.MiscServices.Time

| Name   | Value  | Description                                            |
| ------- | ---- | ------------------------------------------------ |
| STARTUP | 0    | Number of milliseconds elapsed since system startup, including the deep sleep time.  |
| ACTIVE  | 1    | Number of milliseconds elapsed since system startup, excluding the deep sleep time.|

## systemDateTime.getCurrentTime

getCurrentTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since the Unix epoch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type      | Mandatory| Description                            |
| -------- | -------------- | ---- | ------------------ |
| isNano   | boolean                     | Yes  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time elapsed since the Unix epoch.        |

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getCurrentTime(true, (error: BusinessError, time: number) => {
    if (error) {
      console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in getting currentTime : ${time}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getCurrentTime

getCurrentTime(callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since the Unix epoch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type              | Mandatory| Description                           |
| -------- | ----------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time elapsed since the Unix epoch, in milliseconds.        |

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getCurrentTime((error: BusinessError, time: number) => {
    if (error) {
      console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in getting currentTime : ${time}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getCurrentTime

getCurrentTime(isNano?: boolean): Promise&lt;number&gt;

Obtains the time elapsed since the Unix epoch. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                    |
| ------ | ------- | ---- | ------------------------- |
| isNano | boolean | No  | Whether the time to return is in nanoseconds. The default value is **false**.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.|

**Return value**

| Type       | Description                              |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the time elapsed since the Unix epoch.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getCurrentTime().then((time: number) => {
    console.info(`Succeeded in getting currentTime : ${time}`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getRealActiveTime

getRealActiveTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description  |
| -------- | ---------- | ---- | -------------------------- |
| isNano   | boolean                     | Yes  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getRealActiveTime(true, (error: BusinessError, time: number) => {
    if (error) {
      console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in getting real active time : ${time}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getRealActiveTime

getRealActiveTime(callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description   |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getRealActiveTime((error: BusinessError, time: number) => {
    if (error) {
      console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in getting real active time : ${time}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getRealActiveTime

getRealActiveTime(isNano?: boolean): Promise&lt;number&gt;

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                             |
| ------ | ------- | ---- | ----------------------------------- |
| isNano | boolean | No  | Whether the time to return is in nanoseconds. The default value is **false**.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.|

**Return value**

| Type                 | Description        |
| -------------- | -------------------------------- |
| Promise&lt;number&gt; | Promise used to return the time elapsed since system startup, excluding the deep sleep time.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getRealActiveTime().then((time: number) => {
    console.info(`Succeeded in getting real active time : ${time}`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getRealTime

getRealTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, including the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description  |
| -------- | --------------- | ---- | ------------------------------- |
| isNano   | boolean                     | Yes  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getRealTime(true, (error: BusinessError, time: number) => {
    if (error) {
      console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in getting real time : ${time}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getRealTime

getRealTime(callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, including the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description     |
| -------- | --------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getRealTime((error: BusinessError, time: number) => {
    if (error) {
      console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in getting real time : ${time}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getRealTime

getRealTime(isNano?: boolean): Promise&lt;number&gt;

Obtains the time elapsed since system startup, including the deep sleep time. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                              |
| ------ | ------- | ---- | ------------------------------- |
| isNano | boolean | No  | Whether the time to return is in nanoseconds. The default value is **false**.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.|

**Return value**

| Type                 | Description      |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the time elapsed since system startup, including the deep sleep time.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getRealTime().then((time: number) => {
    console.info(`Succeeded in getting real time : ${time}`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getTime<sup>10+</sup>

getTime(isNanoseconds?: boolean): number

 Obtains the time elapsed since the Unix epoch. This API returns the result synchronously.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name       | Type   | Mandatory| Description                                                        |
| ------------- | ------- | ---- | ------------------------------------------------------------ |
| isNanoseconds | boolean | No  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.<br>Default value: **false**|

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | Time elapsed since the Unix epoch.|

**Example**

```ts
try {
  let time = systemDateTime.getTime(true)
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getUptime<sup>10+</sup>

getUptime(timeType: TimeType, isNanoseconds?: boolean): number

Obtains the time elapsed since system startup. This API returns the result synchronously.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name       | Type                   | Mandatory| Description                                                        |
| ------------- | ----------------------- | ---- | ------------------------------------------------------------ |
| timeType      | [TimeType](#timetype10) | Yes  | Type of the time to obtain.                                            |
| isNanoseconds | boolean                 | No  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.<br>Default value: **false**|

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | Time elapsed since system startup.|

**Example**

```ts
try {
  let time = systemDateTime.getUptime(systemDateTime.TimeType.ACTIVE, false);
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get uptime. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getDate<sup>(deprecated)</sup>

getDate(callback: AsyncCallback&lt;Date&gt;): void

Obtains the current system date. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use **new Date()** instead, which returns a **Date** object.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type          | Mandatory| Description                  |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;Date&gt; | Yes  | Callback used to return the current system date.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getDate((error: BusinessError, date: Date) => {
    if (error) {
      console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in getting date : ${date}`);;
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getDate<sup>(deprecated)</sup>

getDate(): Promise&lt;Date&gt;

Obtains the current system date. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use **new Date()** instead, which returns a **Date** object.

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| Promise&lt;Date&gt; | Promise used to return the current system date.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getDate().then((date: Date) => {
    console.info(`Succeeded in getting date : ${date}`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getTimezone

getTimezone(callback: AsyncCallback&lt;string&gt;): void

Obtains the system time zone. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type             | Mandatory| Description                |
| -------- | --------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the system time zone. For details, see [Supported System Time Zones](#supported-system-time-zones).|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getTimezone((error: BusinessError, data: string) => {
    if (error) {
      console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in get timezone : ${data}`);;
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getTimezone

getTimezone(): Promise&lt;string&gt;

Obtains the system time zone. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the system time zone. For details, see [Supported System Time Zones](#supported-system-time-zones).|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.getTimezone().then((data: string) => {
    console.info(`Succeeded in getting timezone: ${data}`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getTimezoneSync<sup>10+</sup>

getTimezoneSync(): string

Obtain the system time zone. This API returns the result synchronously.

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type  | Description                                                      |
| ------ | ---------------------------------------------------------- |
| string | System time zone. For details, see [Supported System Time Zones](#supported-system-time-zones).|

**Example**

```ts
try {
  let timezone = systemDateTime.getTimezoneSync();
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);
}
```

## Supported System Time Zones

The following table lists the supported system time zones and the respective offset (unit: h) between each time zone and time zone 0.

| Time Zone                          | Offset        |
| ------------------------------ | --------------------- |
| Antarctica/McMurdo             | 12                    |
| America/Argentina/Buenos_Aires | -3                    |
| Australia/Sydney               | 10                    |
| America/Noronha                | -2                    |
| America/St_Johns               | -3                    |
| Africa/Kinshasa                | 1                     |
| America/Santiago               | -3                    |
| Asia/Shanghai                  | 8                     |
| Asia/Nicosia                   | 3                     |
| Europe/Berlin                  | 2                     |
| America/Guayaquil              | -5                    |
| Europe/Madrid                  | 2                     |
| Pacific/Pohnpei                | 11                    |
| America/Godthab                | -2                    |
| Asia/Jakarta                   | 7                     |
| Pacific/Tarawa                 | 12                    |
| Asia/Almaty                    | 6                     |
| Pacific/Majuro                 | 12                    |
| Asia/Ulaanbaatar               | 8                     |
| America/Mexico_City            | -5                    |
| Asia/Kuala_Lumpur              | 8                     |
| Pacific/Auckland               | 12                    |
| Pacific/Tahiti                 | -10                   |
| Pacific/Port_Moresby           | 10                    |
| Asia/Gaza                      | 3                     |
| Europe/Lisbon                  | 1                     |
| Europe/Moscow                  | 3                     |
| Europe/Kiev                    | 3                     |
| Pacific/Wake                   | 12                    |
| America/New_York               | -4                    |
| Asia/Tashkent                  | 5                     |
