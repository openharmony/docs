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

## systemDateTime.setTime

setTime(time : number, callback : AsyncCallback&lt;void&gt;) : void

Sets the system time. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Required permissions**: ohos.permission.SET_TIME

**Parameters**

| Name  | Type           | Mandatory| Description                                      |
| -------- | ----------- | ---- | ---------------- |
| time     | number                    | Yes  | Timestamp to set, in milliseconds.                        |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

// Set the system time to 2021-01-20 02:36:25.
let time = 1611081385000;
try {
  systemDateTime.setTime(time, (error: BusinessError) => {
    if (error) {
      console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in setting time`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.setTime

setTime(time : number) : Promise&lt;void&gt;

Sets the system time. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Required permissions**: ohos.permission.SET_TIME

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| time   | number | Yes  | Timestamp to set, in milliseconds.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

// Set the system time to 2021-01-20 02:36:25.
let time = 1611081385000;
try {
  systemDateTime.setTime(time).then(() => {
    console.info(`Succeeded in setting time.`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.setDate<sup>(deprecated)</sup>

setDate(date: Date, callback: AsyncCallback&lt;void&gt;): void

Sets the system date. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use [systemDateTime.setTime](#systemdatetimesettime) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Required permissions**: ohos.permission.SET_TIME

**Parameters**

| Name  | Type                     | Mandatory| Description            |
| -------- | ------------- | ---- | --------------------- |
| date     | Date                      | Yes  | Target date to set.                                |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let date = new Date();
try {
  systemDateTime.setDate(date, (error: BusinessError) => {
    if (error) {
      console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in setting date.`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.setDate<sup>(deprecated)</sup>

setDate(date: Date): Promise&lt;void&gt;

Sets the system date. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use [systemDateTime.setTime](#systemdatetimesettime) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Required permissions**: ohos.permission.SET_TIME

**Parameters**

| Name| Type| Mandatory| Description      |
| ------ | ---- | ---- | ---------- |
| date   | Date | Yes  | Target date to set.|

**Return value**

| Type               | Description                |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let date = new Date(); 
try {
  systemDateTime.setDate(date).then(() => {
    console.info(`Succeeded in setting date.`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.setTimezone

setTimezone(timezone: string, callback: AsyncCallback&lt;void&gt;): void

Sets the system time zone. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Required permissions**: ohos.permission.SET_TIME_ZONE

**Parameters**

| Name  | Type             | Mandatory| Description                 |
| -------- | ------------- | ---- | -------------------------- |
| timezone | string                    | Yes  | System time zone to set. For details, see [Supported System Time Zones](#supported-system-time-zones).       |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.setTimezone('Asia/Shanghai', (error: BusinessError) => {
    if (error) {
      console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in setting timezone.`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.setTimezone

setTimezone(timezone: string): Promise&lt;void&gt;

Sets the system time zone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Required permissions**: ohos.permission.SET_TIME_ZONE

**Parameters**

| Name  | Type  | Mandatory| Description      |
| -------- | ------ | ---- | ---------- |
| timezone | string | Yes  | System time zone to set. For details, see [Supported System Time Zones](#supported-system-time-zones).|

**Return value**

| Type               | Description                |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemDateTime.setTimezone('Asia/Shanghai').then(() => {
    console.info(`Succeeded in setting timezone.`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);
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
