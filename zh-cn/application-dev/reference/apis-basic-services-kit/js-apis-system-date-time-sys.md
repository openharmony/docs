# @ohos.systemDateTime (系统时间、时区)(系统接口)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Time-->
<!--Owner: @huaxin05-->
<!--Designer: @hu-kai45-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @fang-jinxu-->

本模块主要由系统时间和系统时区功能组成。开发者可以设置、获取系统时间及系统时区，支持通过NTP服务器更新网络时间、设置自动时间开关状态等，适用于需要精确管理系统时间和时区的系统应用场景。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { systemDateTime } from '@kit.BasicServicesKit';
```

## TimeType<sup>10+</sup>

定义获取时间的枚举类型。

**系统能力：** SystemCapability.MiscServices.Time

| 名称    | 值   | 说明                                             |
| ------- | ---- | ------------------------------------------------ |
| STARTUP | 0    | 自系统启动以来经过的时间，包括深度睡眠时间。   |
| ACTIVE  | 1    | 自系统启动以来经过的时间，不包括深度睡眠时间。 |

## systemDateTime.setTime

setTime(time : number, callback : AsyncCallback&lt;void&gt;) : void

设置系统时间，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME

**参数：**

| 参数名   | 类型            | 必填 | 说明                                       |
| -------- | ----------- | ---- | ---------------- |
| time     | number                    | 是   | 目标时间戳（ms），且必须>0。                         |
| callback | AsyncCallback&lt;void&gt; | 是   | 设置系统时间的结果回调，设置成功时err为undefined，设置失败时err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                        |
| -------- |-------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                          |
| 202       | Permission verification failed. A non-system application calls a system API.                                |
| 204       | Access denied due to user access control policy. Possible causes: 1.The operation is restricted by the OS-account constraint; 2.The required privilege for the operation has not been granted. |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// time对应的时间为2021-01-20 02:36:25。
let time: number = 1611081385000;
try {
  systemDateTime.setTime(time, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to set time. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`Succeeded in setting time`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to set time. Code: ${error.code}, message: ${error.message}`);
}
```

## systemDateTime.setTime

setTime(time : number) : Promise&lt;void&gt;

设置系统时间，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| time   | number | 是   | 目标时间戳（ms），且必须>0。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。resolve表示设置系统时间成功，reject表示设置系统时间失败并返回错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                        |
| -------- |-------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                          |
| 202       | Permission verification failed. A non-system application calls a system API.                                |
| 204       | Access denied due to user access control policy. Possible causes: 1.The operation is restricted by the OS-account constraint; 2.The required privilege for the operation has not been granted. |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// time对应的时间为2021-01-20 02:36:25。
let time: number = 1611081385000;
try {
  systemDateTime.setTime(time).then(() => {
    console.info(`Succeeded in setting time.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to set time. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to set time. Code: ${error.code}, message: ${error.message}`);
}
```

## systemDateTime.setDate<sup>(deprecated)</sup>

setDate(date: Date, callback: AsyncCallback&lt;void&gt;): void

设置系统日期，使用callback异步回调。

> **说明：**
> 
> 从API version 9开始支持，从API version 10开始废弃。建议使用[systemDateTime.setTime](#systemdatetimesettime)替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME

**参数：**

| 参数名   | 类型                      | 必填 | 说明          |
| -------- | ------------- | ---- |-------------|
| date     | Date                      | 是   | 目标日期，且必须>0。传入小于等于0的值时返回错误码401。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 设置系统日期的结果回调，设置成功时err为undefined，设置失败时err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                                                         |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                                                           |
| 202       | Permission verification failed. A non-system application calls a system API.                                                                 |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let date = new Date();
try {
  systemDateTime.setDate(date, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to set date. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`Succeeded in setting date.`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to set date. Code: ${error.code}, message: ${error.message}`);
}
```

## systemDateTime.setDate<sup>(deprecated)</sup>

setDate(date: Date): Promise&lt;void&gt;

设置系统日期，使用Promise异步回调。

> **说明：**
> 从API version 9开始支持，从API version 10开始废弃。建议使用[systemDateTime.setTime](#systemdatetimesettime)替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME

**参数：**

| 参数名 | 类型 | 必填 | 说明       |
| ------ | ---- | ---- | ---------- |
| date   | Date | 是   | 目标日期，且必须>0。传入小于等于0的值时返回错误码401。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。resolve表示设置系统日期成功，reject表示设置系统日期失败并返回错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                                                         |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                                                           |
| 202       | Permission verification failed. A non-system application calls a system API.                                                                 |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let date = new Date(); 
try {
  systemDateTime.setDate(date).then(() => {
    console.info(`Succeeded in setting date.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to set date. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to set date. Code: ${error.code}, message: ${error.message}`);
}
```

## systemDateTime.setTimezone

setTimezone(timezone: string, callback: AsyncCallback&lt;void&gt;): void

设置系统时区，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME_ZONE

**参数：**

| 参数名   | 类型              | 必填 | 说明                  |
| -------- | ------------- | ---- | -------------------------- |
| timezone | string                    | 是   | 系统时区。具体可见[支持的系统时区](#支持的系统时区)。        |
| callback | AsyncCallback&lt;void&gt; | 是   | 设置系统时区的结果回调，设置成功时err为undefined，设置失败时err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                        |
| -------- |-------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                          |
| 202       | Permission verification failed. A non-system application calls a system API.                                |
| 204       | Access denied due to user access control policy. Possible causes: 1.The operation is restricted by the OS-account constraint; 2.The required privilege for the operation has not been granted. |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  systemDateTime.setTimezone('Asia/Shanghai', (error: BusinessError) => {
    if (error) {
      console.error(`Failed to set timezone. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`Succeeded in setting timezone.`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to set timezone. Code: ${error.code}, message: ${error.message}`);
}
```

## systemDateTime.setTimezone

setTimezone(timezone: string): Promise&lt;void&gt;

设置系统时区，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME_ZONE

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| timezone | string | 是   | 系统时区。具体可见[支持的系统时区](#支持的系统时区) 。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。resolve表示设置系统时区成功，reject表示设置系统时区失败并返回错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                        |
| -------- |-------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                          |
| 202       | Permission verification failed. A non-system application calls a system API.                                |
| 204       | Access denied due to user access control policy. Possible causes: 1.The operation is restricted by the OS-account constraint; 2.The required privilege for the operation has not been granted. |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  systemDateTime.setTimezone('Asia/Shanghai').then(() => {
    console.info(`Succeeded in setting timezone.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to set timezone. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to set timezone. Code: ${error.code}, message: ${error.message}`);
}
```

## systemDateTime.updateNtpTime<sup>14+</sup>

updateNtpTime(): Promise&lt;void&gt;

使用异步方式从NTP服务器更新NTP时间。该方法一小时内只会从NTP服务器更新一次NTP时间。

**使用场景：** 用于系统应用需要主动从网络时间服务器校准系统时间的场景，例如设备时间不准确或需要手动触发网络时间同步时。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Time

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。resolve表示从NTP服务器更新NTP时间成功，reject表示更新NTP时间失败并返回错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)和[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                    |
|-------|-------------------------------------------------------------------------------------------------------------|
| 13000001    | Network connection error or OS error.                                                                 |
| 202   | Permission verification failed. A non-system application calls a system API.                                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  systemDateTime.updateNtpTime().then(() => {
    console.info(`Succeeded in updating ntp time.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to update ntp time. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to update ntp time. Code: ${error.code}, message: ${error.message}`);
}
```

## systemDateTime.getNtpTime<sup>14+</sup>

getNtpTime(): number

使用同步方式获取基于上次更新的NTP时间所计算出的真实时间。使用本方法前需先成功调用[updateNtpTime](#systemdatetimeupdatentptime14)更新NTP时间，否则会抛出13000002错误。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Time

**返回值：**

| 类型   | 说明                             |
| ------ |--------------------------------|
| number | 基于上次更新的NTP时间所计算出的Unix纪元时间（ms）。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)和[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                    |
|-------|-------------------------------------------------------------------------------------------------------------|
| 13000002    | updateNtpTime() is not called successfully.                                                           |
| 202   | Permission verification failed. A non-system application calls a system API.                                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let time: number = systemDateTime.getNtpTime();
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get ntp time. Code: ${error.code}, message: ${error.message}`);
}
```

## 支持的系统时区

支持的系统时区可参考接口[I18n.SystemLocaleManager.getTimeZoneCityItemArray()](../apis-localization-kit/js-apis-i18n-sys.md#gettimezonecityitemarray10)。


## systemDateTime.setAutoTimeStatus<sup>21+</sup>

setAutoTimeStatus(status: boolean): Promise&lt;void&gt;

设置自动设置时间开关状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| status | boolean | 是   | 设置自动设置时间开关状态。<br>- true：表示打开自动设置时间开关。 <br>- false：表示关闭自动设置时间开关。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。resolve表示设置自动设置时间开关状态成功，reject表示设置自动设置时间开关状态失败并返回错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)和[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                        |
| -------- |-------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                          |
| 202       | Permission verification failed. A non-system application calls a system API.                                |
| 204       | Access denied due to user access control policy. Possible causes: 1. The operation is restricted by the OS-account constraint; 2. The required privilege for the operation has not been granted. |
| 13000001  | Network connection error or OS error. Possible causes: 1. System memory is insufficient; 2. Calls the underlying system interface failed.|


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  systemDateTime.setAutoTimeStatus(true).then(() => {
    console.info(`Succeeded in setting autotime.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to set autotime. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to set autotime. Code: ${error.code}, message: ${error.message}`);
}
```