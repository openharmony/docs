# @ohos.systemTime (系统时间、时区)(系统接口)

本模块主要由系统时间和系统时区功能组成。开发者可以设置、获取系统时间及系统时区。

> **说明：**
>
> - 从API Version 9 开始，该模块接口不再维护，推荐使用新模块接口[@ohos.systemDateTime (系统时间、时区)](js-apis-system-date-time-sys.md)
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本文档均为系统接口。

## 导入模块

```ts
import systemTime from '@ohos.systemTime';
```

## systemTime.setTime

setTime(time : number, callback : AsyncCallback&lt;void&gt;) : void

设置系统时间，使用callback异步回调。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型            | 必填 | 说明                                       |
| -------- | ----------- | ---- | ---------------- |
| time     | number                    | 是   | 目标时间戳（ms）。                         |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| -1       | Parameter check failed, permission denied, or system error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

// time对应的时间为2021-01-20 02:36:25
let time = 1611081385000;
try {
  systemTime.setTime(time, (error: BusinessError) => {
    if (error) {
      console.info(`Failed to setting time. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in setting time`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);
}
```

## systemTime.setTime

setTime(time : number) : Promise&lt;void&gt;

设置系统时间，使用Promise异步回调。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

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

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| -1       | Parameter check failed, permission denied, or system error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

// time对应的时间为2021-01-20 02:36:25
let time = 1611081385000;
try {
  systemTime.setTime(time).then(() => {
    console.info(`Succeeded in setting time.`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to setting time. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);
}
```

## systemTime.setDate

setDate(date: Date, callback: AsyncCallback&lt;void&gt;): void

设置系统日期，使用callback异步回调。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                      | 必填 | 说明             |
| -------- | ------------- | ---- | --------------------- |
| date     | Date                      | 是   | 目标日期。                                 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| -1       | Parameter check failed, permission denied, or system error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let date = new Date();
try {
  systemTime.setDate(date, (error: BusinessError) => {
    if (error) {
      console.info(`Failed to setting date. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in setting date.`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);
}
```

## systemTime.setDate

setDate(date: Date): Promise&lt;void&gt;

设置系统日期，使用Promise异步回调。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型 | 必填 | 说明       |
| ------ | ---- | ---- | ---------- |
| date   | Date | 是   | 目标日期。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| -1       | Parameter check failed, permission denied, or system error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let date = new Date(); 
try {
  systemTime.setDate(date).then(() => {
    console.info(`Succeeded in setting date.`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to setting date. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);
}
```

## systemTime.setTimezone

setTimezone(timezone: string, callback: AsyncCallback&lt;void&gt;): void

设置系统时区，使用callback异步回调。

**需要权限：** ohos.permission.SET_TIME_ZONE

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型              | 必填 | 说明                  |
| -------- | ------------- | ---- | -------------------------- |
| timezone | string                    | 是   | 系统时区。 具体可见[支持的系统时区](#支持的系统时区) 。        |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| -1       | Parameter check failed, permission denied, or system error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemTime.setTimezone('Asia/Shanghai', (error: BusinessError) => {
    if (error) {
      console.info(`Failed to setting timezone. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in setting timezone.`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);
}
```

## systemTime.setTimezon

setTimezone(timezone: string): Promise&lt;void&gt;

设置系统时区，使用Promise异步回调。

**需要权限：** ohos.permission.SET_TIME_ZONE

**系统能力：** SystemCapability.MiscServices.Time

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

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| -1       | Parameter check failed, permission denied, or system error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  systemTime.setTimezone('Asia/Shanghai').then(() => {
    console.info(`Succeeded in setting timezone.`);
  }).catch((error: BusinessError) => {
    console.info(`Failed to setting timezone. message: ${error.message}, code: ${error.code}`);
  });
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);
}
```

## 支持的系统时区

支持的系统时区参考接口[I18n.SystemLocaleManager.getTimeZoneCityItemArray()](../apis-localization-kit/js-apis-i18n-sys.md#gettimezonecityitemarray10)。
