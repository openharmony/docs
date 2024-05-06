# @ohos.systemDateTime (系统时间、时区)(系统接口)

本模块主要由系统时间和系统时区功能组成。开发者可以设置、获取系统时间及系统时区。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import systemDateTime from '@ohos.systemDateTime';
```

## TimeType<sup>10+</sup>

定义获取时间的枚举类型。

**系统能力**: SystemCapability.MiscServices.Time

| 名称    | 值   | 说明                                             |
| ------- | ---- | ------------------------------------------------ |
| STARTUP | 0    | 自系统启动以来经过的毫秒数，包括深度睡眠时间。   |
| ACTIVE  | 1    | 自系统启动以来经过的毫秒数，不包括深度睡眠时间。 |

## systemDateTime.setTime

setTime(time : number, callback : AsyncCallback&lt;void&gt;) : void

设置系统时间，使用callback异步回调。

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME

**参数：**

| 参数名   | 类型            | 必填 | 说明                                       |
| -------- | ----------- | ---- | ---------------- |
| time     | number                    | 是   | 目标时间戳（ms）。                         |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                           |
| -------- |----------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                             |
| 202       | Permission denied, Non system application use system APIs.                                                     |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

// time对应的时间为2021-01-20 02:36:25
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

设置系统时间，使用Promise异步回调。

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| time   | number | 是   | 目标时间戳（ms）。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                           |
| -------- |----------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                             |
| 202       | Permission denied, Non system application use system APIs.                                                     |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

// time对应的时间为2021-01-20 02:36:25
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

设置系统日期，使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API 10开始废弃。建议使用[systemDateTime.setTime](#systemdatetimesettime)替代。

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME

**参数：**

| 参数名   | 类型                      | 必填 | 说明          |
| -------- | ------------- | ---- |-------------|
| date     | Date                      | 是   | 目标日期，且必须>0。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。       |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                                                            |
| -------- |-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                                                              |
| 202       | Permission denied, Non system application use system APIs.                                                                                      |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**示例：**

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

设置系统日期，使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API 10开始废弃。建议使用[systemDateTime.setTime](#systemdatetimesettime)替代。

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME

**参数：**

| 参数名 | 类型 | 必填 | 说明       |
| ------ | ---- | ---- | ---------- |
| date   | Date | 是   | 目标日期，且必须。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                                                            |
| -------- |-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                                                              |
| 202       | Permission denied, Non system application use system APIs.                                                                                      |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**示例：**

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

设置系统时区，使用callback异步回调。

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME_ZONE

**参数：**

| 参数名   | 类型              | 必填 | 说明                  |
| -------- | ------------- | ---- | -------------------------- |
| timezone | string                    | 是   | 系统时区。 具体可见[支持的系统时区](#支持的系统时区) 。        |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                           |
| -------- |----------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                             |
| 202       | Permission denied, Non system application use system APIs.                                                     |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

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

设置系统时区，使用Promise异步回调。

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.MiscServices.Time

**需要权限：** ohos.permission.SET_TIME_ZONE

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| timezone | string | 是   | 系统时区。具体可见[支持的系统时区](#支持的系统时区) 。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                           |
| -------- |----------------------------------------------------------------------------------------------------------------|
| 201       | Permission denied.                                                                                             |
| 202       | Permission denied, Non system application use system APIs.                                                     |
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

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

## 支持的系统时区

支持的系统时区及各时区与0时区相比的偏移量（单位：h）可见下表。

| 时区                           | 偏移量         |
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