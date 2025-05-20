# @ohos.systemDateTime (系统时间、时区)

本模块主要由系统时间和系统时区功能组成。开发者可以设置、获取系统时间及系统时区。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { systemDateTime } from '@kit.BasicServicesKit';
```

## TimeType<sup>10+</sup>

定义获取时间的枚举类型。

**系统能力**: SystemCapability.MiscServices.Time

| 名称    | 值   | 说明                                             |
| ------- | ---- | ------------------------------------------------ |
| STARTUP | 0    | 自系统启动以来经过的毫秒数，包括深度睡眠时间。   |
| ACTIVE  | 1    | 自系统启动以来经过的毫秒数，不包括深度睡眠时间。 |

## systemDateTime.getCurrentTime<sup>(deprecated)</sup>

getCurrentTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

获取自Unix纪元以来经过的时间，使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API Version 12开始废弃，建议使用[systemDateTime.getTime<sup>10+</sup>](#systemdatetimegettime10)替代。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型       | 必填 | 说明                             |
| -------- | -------------- | ---- | ------------------ |
| isNano   | boolean                     | 是   | 返回结果是否为纳秒数。<br>- true：表示返回结果为纳秒数(ns)。 <br>- false：表示返回结果为毫秒数(ms)。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自Unix纪元以来经过的时间戳。         |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                              |
| -------- |-------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## systemDateTime.getCurrentTime<sup>(deprecated)</sup>

getCurrentTime(callback: AsyncCallback&lt;number&gt;): void

获取自Unix纪元以来经过的时间，使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API Version 12开始废弃，建议使用[systemDateTime.getTime<sup>10+</sup>](#systemdatetimegettime10)替代。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型               | 必填 | 说明                            |
| -------- | ----------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自Unix纪元以来经过的时间戳(ms)。         |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                              |
|----------|-------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## systemDateTime.getCurrentTime<sup>(deprecated)</sup>

getCurrentTime(isNano?: boolean): Promise&lt;number&gt;

获取自Unix纪元以来经过的时间，使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API Version 12开始废弃，建议使用[systemDateTime.getTime<sup>10+</sup>](#systemdatetimegettime10)替代。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                     |
| ------ | ------- | ---- | ------------------------- |
| isNano | boolean | 否   | 返回结果是否为纳秒数,默认值为false。<br/>- true：表示返回结果为纳秒数(ns)。 <br/>- false：表示返回结果为毫秒数(ms)。 |

**返回值：**

| 类型        | 说明                               |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise对象，返回自Unix纪元以来经过的时间戳。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                              |
|---------|-------------------------------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## systemDateTime.getRealActiveTime<sup>(deprecated)</sup>

getRealActiveTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，不包括深度睡眠时间，使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API Version 12开始废弃，建议使用[systemDateTime.getUptime<sup>10+</sup>](#systemdatetimegetuptime10)替代。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明   |
| -------- | ---------- | ---- | -------------------------- |
| isNano   | boolean                     | 是   | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数(ns)。 <br/>- false：表示返回结果为毫秒数(ms)。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，但不包括深度睡眠时间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                              |
|---------|-------------------------------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## systemDateTime.getRealActiveTime<sup>(deprecated)</sup>

getRealActiveTime(callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，不包括深度睡眠时间，使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API Version 12开始废弃，建议使用[systemDateTime.getUptime<sup>10+</sup>](#systemdatetimegetuptime10)替代。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明    |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，但不包括度睡眠时间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                              |
|---------|-------------------------------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## systemDateTime.getRealActiveTime<sup>(deprecated)</sup>

getRealActiveTime(isNano?: boolean): Promise&lt;number&gt;

获取自系统启动以来经过的时间，不包括深度睡眠时间，使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API Version 12开始废弃，建议使用[systemDateTime.getUptime<sup>10+</sup>](#systemdatetimegetuptime10)替代。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                              |
| ------ | ------- | ---- | ----------------------------------- |
| isNano | boolean | 否   | 返回结果是否为纳秒数,默认值为false。<br/>- true：表示返回结果为纳秒数(ns)。 <br/>- false：表示返回结果为毫秒数(ms)。 |

**返回值：**

| 类型                  | 说明         |
| -------------- | -------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回自系统启动以来经过的时间，但不包括深度睡眠时间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                              |
|---------|-------------------------------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## systemDateTime.getRealTime<sup>(deprecated)</sup>

getRealTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，包括深度睡眠时间，使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API Version 12开始废弃，建议使用[systemDateTime.getUptime<sup>10+</sup>](#systemdatetimegetuptime10)替代。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明   |
| -------- | --------------- | ---- | ------------------------------- |
| isNano   | boolean                     | 是   | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数(ns)。 <br/>- false：表示返回结果为毫秒数(ms)。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，包括深度睡眠时间。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                              |
|---------|-------------------------------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## systemDateTime.getRealTime<sup>(deprecated)</sup>

getRealTime(callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，包括深度睡眠时间，使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API Version 12开始废弃，建议使用[systemDateTime.getUptime<sup>10+</sup>](#systemdatetimegetuptime10)替代。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明      |
| -------- | --------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，包括深度睡眠时间。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                              |
|---------|-------------------------------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## systemDateTime.getRealTime<sup>(deprecated)</sup>

getRealTime(isNano?: boolean): Promise&lt;number&gt;

获取自系统启动以来经过的时间，包括深度睡眠时间，使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API Version 12开始废弃，建议使用[systemDateTime.getUptime<sup>10+</sup>](#systemdatetimegetuptime10)替代。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ------------------------------- |
| isNano | boolean | 否   | 返回结果是否为纳秒数,默认值为false。<br/>- true：表示返回结果为纳秒数(ns)。 <br/>- false：表示返回结果为毫秒数(ms)。 |

**返回值：**

| 类型                  | 说明       |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回自系统启动以来经过的时间，包括深度睡眠时间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                              |
|---------|-------------------------------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

使用同步方式获取自Unix纪元以来到当前系统时间所经过的时间。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名        | 类型    | 必填 | 说明                                                         |
| ------------- | ------- | ---- | ------------------------------------------------------------ |
| isNanoseconds | boolean | 否   | 返回结果是否为纳秒数。<br>- true：表示返回结果为纳秒数(ns)。 <br>- false：表示返回结果为毫秒数(ms)。<br>默认值为false。 |

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 自Unix纪元以来到当前系统时间所经过的时间。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let time = systemDateTime.getTime(true)
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get time. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getUptime<sup>10+</sup>

getUptime(timeType: TimeType, isNanoseconds?: boolean): number

使用同步方式获取自系统启动以来经过的时间。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名        | 类型                    | 必填 | 说明                                                                                |
| ------------- | ----------------------- | ---- |-----------------------------------------------------------------------------------|
| timeType      | [TimeType](#timetype10) | 是   | 获取时间的类型，仅能为`STARTUP`或者`ACTIVE`。                                                  |
| isNanoseconds | boolean                 | 否   | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数(ns)。 <br/>- false：表示返回结果为毫秒数(ms)。<br>默认值为false。 |

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 自系统启动以来经过的时间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                           |
| -------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification<br> failed.This error code was added due to missing issues. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let time = systemDateTime.getUptime(systemDateTime.TimeType.ACTIVE, false);
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get uptime. message: ${error.message}, code: ${error.code}`);
}
```

## systemDateTime.getDate<sup>(deprecated)</sup>

getDate(callback: AsyncCallback&lt;Date&gt;): void

获取当前系统日期，使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API 10开始废弃，建议使用new Date()替代，new Date()返回Date实例对象。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型           | 必填 | 说明                   |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;Date&gt; | 是   | 回调函数，返回当前系统日期。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                 |
|-------|------------------------------------------------------|
| 401   | Parameter error. Possible causes: 1.System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

获取当前系统日期，使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API 10开始废弃，建议使用new Date()替代，new Date()返回Date实例对象。

**系统能力：** SystemCapability.MiscServices.Time

**返回值：**

| 类型                | 说明                                      |
| ------------------- | ----------------------------------------- |
| Promise&lt;Date&gt; | Promise对象，返回当前系统日期。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                 |
|-------|------------------------------------------------------|
| 401   | Parameter error. Possible causes: 1.System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

获取系统时区，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型              | 必填 | 说明                 |
| -------- | --------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回系统时区。具体可见[支持的系统时区](#支持的系统时区)。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

获取系统时区，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回系统时区。具体可见[支持的系统时区](#支持的系统时区)。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

获取系统时区，使用同步方式。

**系统能力：** SystemCapability.MiscServices.Time

**返回值：**

| 类型   | 说明                                                       |
| ------ | ---------------------------------------------------------- |
| string | 返回系统时区。具体可见[支持的系统时区](#支持的系统时区)。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let timezone = systemDateTime.getTimezoneSync();
} catch(e) {
  let error = e as BusinessError;
  console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);
}
```

## 支持的系统时区

支持的系统时区及各时区与0时区相比的偏移量(单位：h)可见下表。

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