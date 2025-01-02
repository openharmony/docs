# @ohos.systemDateTime (System Time and Time Zone) (System API)

The **systemDateTime** module provides system time and time zone features. You can use the APIs of this module to set and obtain the system time and time zone.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { systemDateTime } from '@kit.BasicServicesKit';
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

**Error codes**

For details about the error codes, see [Time and Time Zone Service Error Codes](./errorcode-time.md).

| ID| Error Message                                                                                                       |
| -------- |-------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                          |
| 202       | Permission verification failed. A non-system application calls a system API.                                |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Time and Time Zone Service Error Codes](./errorcode-time.md).

| ID| Error Message                                                                                                       |
| -------- |-------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                          |
| 202       | Permission verification failed. A non-system application calls a system API.                                |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

| Name  | Type                     | Mandatory| Description         |
| -------- | ------------- | ---- |-------------|
| date     | Date                      | Yes  | Target date. The value must be greater than 0.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.      |

**Error codes**

For details about the error codes, see [Time and Time Zone Service Error Codes](./errorcode-time.md).

| ID| Error Message                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                                                           |
| 202       | Permission verification failed. A non-system application calls a system API.                                                                 |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
| date   | Date | Yes  | Target date, which is mandatory.|

**Return value**

| Type               | Description                |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Time and Time Zone Service Error Codes](./errorcode-time.md).

| ID| Error Message                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                                                           |
| 202       | Permission verification failed. A non-system application calls a system API.                                                                 |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Time and Time Zone Service Error Codes](./errorcode-time.md).

| ID| Error Message                                                                                                       |
| -------- |-------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                          |
| 202       | Permission verification failed. A non-system application calls a system API.                                |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Time and Time Zone Service Error Codes](./errorcode-time.md).

| ID| Error Message                                                                                                       |
| -------- |-------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                          |
| 202       | Permission verification failed. A non-system application calls a system API.                                |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## systemDateTime.updateNtpTime<sup>14+</sup>

updateNtpTime(): Promise&lt;void&gt;

Updates the NTP time from the NTP server This API returns the result asynchronously. In this way, the NTP time is updated from the NTP server only once within one hour.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type               | Description                |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Time and Time Zone Service Error Codes](./errorcode-time.md).

| ID| Error Message                                                                                                   |
|-------|-------------------------------------------------------------------------------------------------------------|
| 13000001    | Network connection error or OS error.                                                                 |
| 202   | Permission verification failed. A non-system application calls a system API.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  systemDateTime.updateNtpTime().then(() => {
    console.info(`Succeeded in update ntp time.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to update ntp time. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.error(`Failed to update ntp time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getNtpTime<sup>14+</sup>

getNtpTime(): number

Obtains the actual time calculated based on the last updated NTP time. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type  | Description                            |
| ------ |--------------------------------|
| number | Unix epoch time (ms) calculated based on the last updated NTP time.|

**Error codes**

For details about the error codes, see [Time and Time Zone Service Error Codes](./errorcode-time.md).

| ID| Error Message                                                                                                   |
|-------|-------------------------------------------------------------------------------------------------------------|
| 13000002    | updateNtpTime() is not called successfully.                                                           |
| 202   | Permission verification failed. A non-system application calls a system API.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let time = systemDateTime.getNtpTime();
} catch(e) {
  let error = e as BusinessError;
  console.error(`Failed to get ntp time. message: ${error.message}, code: ${error.code}`);
}
```

## Supported System Time Zones

For details about the supported system time zones, see API [I18n.SystemLocaleManager.getTimeZoneCityItemArray()](../apis-localization-kit/js-apis-i18n-sys.md#gettimezonecityitemarray10).
