# @ohos.systemTimer (系统定时器)(系统接口)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Time-->
<!--Owner: @huaxin05-->
<!--Designer: @hu-kai45-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @fang-jinxu-->

本模块主要由系统定时器功能组成，提供定时器的创建、启动、停止和销毁能力，支持创建系统启动时间定时器、唤醒定时器、精准定时器和IDLE模式定时器等多种类型。开发者可以使用定时功能实现定时服务，如闹钟等。定时器的典型使用流程为：先通过createTimer创建定时器，再通过startTimer启动定时器，可根据需要通过stopTimer停止定时器，最后通过destroyTimer销毁定时器以释放资源。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块


```ts
import { systemTimer } from '@kit.BasicServicesKit';
```

## 常量

支持创建的定时器类型。

**系统能力：** SystemCapability.MiscServices.Time

| 名称                | 类型   | 值   | 说明                                          |
| ------------------- | ------ | ---- |---------------------------------------------|
| TIMER_TYPE_REALTIME | number | 1    | 系统启动时间定时器（定时器启动时间不能晚于当前设置的系统时间）。|
| TIMER_TYPE_WAKEUP   | number | 2    | 唤醒定时器（如果未配置为唤醒定时器，则系统处于休眠状态下不会触发，直到退出休眠状态）。|
| TIMER_TYPE_EXACT    | number | 4    | 精准定时器（系统时间修改的情况下，可能会出现最多1s的前后偏移误差）。|
| TIMER_TYPE_IDLE     | number | 8    | IDLE模式定时器（仅支持系统服务配置，不支持应用配置）。|

## TimerOptions

创建系统定时器的初始化选项。

**系统能力：** SystemCapability.MiscServices.Time

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------|------|------|------|-------------------------------|
| type | number | 否 | 否 | 定时器类型，可以使用 '\|' 多选。<br>取值为1，表示为系统启动时间定时器（定时器启动时间不能晚于当前设置的系统时间）；<br>取值为2，表示为唤醒定时器（如果未配置为唤醒定时器，则系统处于休眠状态下不会触发，直到退出休眠状态）；<br>取值为4，表示为精准定时器（APP被冻结时，定时器也会被冻结，并且定时器受统一心跳管控，因此即使是精准定时器也不能确保在指定时间点触发；系统时间修改的情况下，可能会出现最多1s的前后偏移误差）；<br>取值为8，表示为IDLE模式定时器（仅支持系统服务配置，不支持应用配置）。 |
| repeat | boolean | 否 | 否 | 是否为循环定时器。true表示循环定时器，false表示单次定时器。 |
| autoRestore<sup>15+</sup> | boolean | 否 | 是 | 是否在设备重启后恢复。<br>true为重启后恢复，false为重启后不恢复。<br>仅支持非`TIMER_TYPE_REALTIME`类型且配置了wantAgent的定时器配置为true，不满足该条件时该参数不生效。<br>默认值为false。 |
| name<sup>15+</sup> | string | 否 | 是 | 定时器名称，长度不超过64字节，超出长度限制时创建定时器失败并返回错误。<br>同一个UID中不可以同时存在两个同名定时器。如果创建了一个和之前已创建的定时器名字相同的定时器，先创建的定时器会被销毁。<br>默认值为空字符串。 |
| interval | number | 否 | 是 | 定时器时间间隔，单位：毫秒。<br>如果是循环定时器，interval值最小为1s，最大为365天，建议interval值不小于5000毫秒，超出该范围时定时器创建失败并返回错误；<br>单次定时器interval值为0。<br>默认值为0。 |
| wantAgent | WantAgent | 否 | 是 | 设置通知的WantAgent，定时器到期后通知（支持拉起应用MainAbility，不支持拉起ServiceAbility）。<br>默认值为空。 |
| callback | function | 否 | 是  | 用户需要执行的回调函数，在定时器触发时被调用。当需要在定时器触发时执行自定义逻辑时传入此参数；不传入时默认为空，定时器触发后不执行用户自定义逻辑。 |


## systemTimer.createTimer

createTimer(options: TimerOptions, callback: AsyncCallback&lt;number&gt;): void

创建定时器，使用callback异步回调。

> **注意：**
> 
> 需与[systemTimer.destroyTimer](#systemtimerdestroytimer)结合使用，否则会造成内存泄漏。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                         |
| -------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TimerOptions](#timeroptions) | 是   | 创建系统定时器的初始化选项，包括定时器类型、是否循环触发、间隔时间、WantAgent通知机制等。 |
| callback | AsyncCallback&lt;number>      | 是   | 回调函数，返回定时器的ID。                                   |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                                                         |
|-------|----------------------------------------------------------------------------------------------------------------------------------------------|
| 202   | Permission verification failed. A non-system application calls a system API.                                                                 |
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: systemTimer.TimerOptions = {
  type: systemTimer.TIMER_TYPE_REALTIME,
  repeat: false
};
try {
  systemTimer.createTimer(options, (error: BusinessError, timerId: number) => {
    if (error) {
      console.error(`Failed to create timer. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to create timer. Code: ${error.code}, message: ${error.message}`);
}
```

## systemTimer.createTimer

createTimer(options: TimerOptions): Promise&lt;number&gt;

创建定时器，使用Promise异步回调返回定时器的ID。

> **注意：**
> 
> 需与[systemTimer.destroyTimer](#systemtimerdestroytimer)结合使用，否则会造成内存泄漏。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名  | 类型                          | 必填 | 说明                                                         |
| ------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| options | [TimerOptions](#timeroptions) | 是   | 创建系统定时器的初始化选项，包括定时器类型、是否循环触发、间隔时间、WantAgent通知机制等。 |

**返回值：**

| 类型                  | 说明                          |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise对象，返回定时器的ID。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 202   | Permission verification failed. A non-system application calls a system API.                                |
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: systemTimer.TimerOptions = {
  type: systemTimer.TIMER_TYPE_REALTIME,
  repeat:false
};
try {
  systemTimer.createTimer(options).then((timerId: number) => {
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to create timer. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to create timer. Code: ${error.code}, message: ${error.message}`);
}
```

## systemTimer.startTimer

startTimer(timer: number, triggerTime: number, callback: AsyncCallback&lt;void&gt;): void

开启定时器，使用callback异步回调。

> **注意：**
>
> 需与[systemTimer.stopTimer](#systemtimerstoptimer)配合使用，停止已开启的定时器。典型调用顺序：createTimer → startTimer → stopTimer → destroyTimer。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名      | 类型                   | 必填 | 说明                                                                                                                                                                                                                                                           |
| ----------- | ---------------------- | ---- |--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| timer       | number                 | 是   | 定时器的ID。                                                                                                                                                                                                                                                      |
| triggerTime | number                 | 是   | 定时器的触发时间，单位：毫秒。<br>若定时器类型包含了TIMER_TYPE_REALTIME，该triggerTime应为系统启动时间，建议通过[systemDateTime.getUptime()](js-apis-date-time.md#systemdatetimegetuptime10)获取，否则定时器无法在预期时间触发；<br>若定时器类型不包含TIMER_TYPE_REALTIME，该triggerTime应为墙上时间，建议通过[systemDateTime.getTime()](js-apis-date-time.md#systemdatetimegettime10)获取，否则定时器无法在预期时间触发。 |
| callback    | AsyncCallback&lt;void> | 是   | 回调函数，用于接收定时器启动结果。回调参数为err（错误对象，启动成功时为undefined）。                                                                                                                                 |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 202   | Permission verification failed. A non-system application calls a system API.                                |
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: systemTimer.TimerOptions = {
  type: systemTimer.TIMER_TYPE_REALTIME,
  repeat:false
};
let triggerTime: number = new Date().getTime();
triggerTime += 3000;

try {
  systemTimer.createTimer(options).then((timerId: number) => {
    systemTimer.startTimer(timerId, triggerTime, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to start timer. Code: ${error.code}, message: ${error.message}`);
        return;
      }
      console.info(`Succeeded in starting timer.`);
    });
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to create timer. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to start timer. Code: ${error.code}, message: ${error.message}`);
}
```

## systemTimer.startTimer

startTimer(timer: number, triggerTime: number): Promise&lt;void&gt;

开启定时器，使用Promise进行异步回调。

> **注意：**
>
> 需与[systemTimer.stopTimer](#systemtimerstoptimer)配合使用，停止已开启的定时器。典型调用顺序：createTimer → startTimer → stopTimer → destroyTimer。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                                                                                                                                                                                                                           |
| ----------- | ------ | ---- |--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| timer       | number | 是   | 定时器的ID。                                                                                                                                                                                                                                                      |
| triggerTime | number | 是   | 定时器的触发时间，单位：毫秒。<br>若定时器类型包含了TIMER_TYPE_REALTIME，该triggerTime应为系统启动时间，建议通过[systemDateTime.getUptime()](js-apis-date-time.md#systemdatetimegetuptime10)获取，否则定时器无法在预期时间触发；<br>若定时器类型不包含TIMER_TYPE_REALTIME，该triggerTime应为墙上时间，建议通过[systemDateTime.getTime()](js-apis-date-time.md#systemdatetimegettime10)获取，否则定时器无法在预期时间触发。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。resolve表示定时器开启成功，reject表示开启失败。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 202   | Permission verification failed. A non-system application calls a system API.                                |
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: systemTimer.TimerOptions = {
  type: systemTimer.TIMER_TYPE_REALTIME,
  repeat:false
};
let triggerTime: number = new Date().getTime();
triggerTime += 3000;

try {
  systemTimer.createTimer(options).then((timerId: number) => {
    systemTimer.startTimer(timerId, triggerTime).then(() => {
      console.info(`Succeeded in starting timer.`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to start timer. Code: ${error.code}, message: ${error.message}`);
    });
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to create timer. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to create timer. Code: ${error.code}, message: ${error.message}`);
}
```

## systemTimer.stopTimer

stopTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

该方法停止定时器，使用callback进行异步回调。需与[systemTimer.startTimer](#systemtimerstarttimer)配合使用，用于停止已开启的定时器。停止定时器后可调用[systemTimer.destroyTimer](#systemtimerdestroytimer)销毁定时器释放资源。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                   | 必填 | 说明         |
| -------- | ---------------------- | ---- | ------------ |
| timer    | number                 | 是   | 定时器的ID。 |
| callback | AsyncCallback&lt;void> | 是   | 回调函数，用于接收定时器停止结果。回调参数为err（错误对象，停止成功时为undefined）。   |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 202   | Permission verification failed. A non-system application calls a system API.                                |
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: systemTimer.TimerOptions = {
  type: systemTimer.TIMER_TYPE_REALTIME,
  repeat:false
};
let triggerTime: number = new Date().getTime();
triggerTime += 3000;

try {
  systemTimer.createTimer(options).then((timerId: number) => {
    systemTimer.startTimer(timerId, triggerTime);
    systemTimer.stopTimer(timerId, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to stop timer. Code: ${error.code}, message: ${error.message}`);
        return;
      }
      console.info(`Succeeded in stopping timer.`);
    });
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to create timer. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to stop timer. Code: ${error.code}, message: ${error.message}`);
}
```

## systemTimer.stopTimer

stopTimer(timer: number): Promise&lt;void&gt;

此方法用于停止定时器，使用Promise异步回调。需与[systemTimer.startTimer](#systemtimerstarttimer)配合使用，用于停止已开启的定时器。停止定时器后可调用[systemTimer.destroyTimer](#systemtimerdestroytimer)销毁定时器释放资源。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| timer  | number | 是   | 定时器的ID。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。resolve表示定时器停止成功，reject表示停止失败。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 202   | Permission verification failed. A non-system application calls a system API.                                |
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: systemTimer.TimerOptions = {
  type: systemTimer.TIMER_TYPE_REALTIME,
  repeat:false
};
let triggerTime: number = new Date().getTime();
triggerTime += 3000;

try {
  systemTimer.createTimer(options).then((timerId: number) => {
    systemTimer.startTimer(timerId, triggerTime);
    systemTimer.stopTimer(timerId).then(() => {
      console.info(`Succeeded in stopping timer.`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to stop timer. Code: ${error.code}, message: ${error.message}`);
    });
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to operate timer. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to stop timer. Code: ${error.code}, message: ${error.message}`);
}
```

## systemTimer.destroyTimer

destroyTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

销毁定时器，使用callback异步回调。

> **注意：**
>
> 需与[systemTimer.createTimer](#systemtimercreatetimer)配合使用，用于销毁通过createTimer创建的定时器，避免内存泄漏。建议先调用[systemTimer.stopTimer](#systemtimerstoptimer)停止定时器后再销毁。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                   | 必填 | 说明         |
| -------- | ---------------------- | ---- | ------------ |
| timer    | number                 | 是   | 定时器的ID。 |
| callback | AsyncCallback&lt;void> | 是   | 回调函数，用于接收定时器销毁结果。回调参数为err（错误对象，销毁成功时为undefined）。   |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 202   | Permission verification failed. A non-system application calls a system API.                                |
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: systemTimer.TimerOptions = {
  type: systemTimer.TIMER_TYPE_REALTIME,
  repeat:false
};
let triggerTime: number = new Date().getTime();
triggerTime += 3000;

try {
  systemTimer.createTimer(options).then((timerId: number) => {
    systemTimer.startTimer(timerId, triggerTime);
    systemTimer.stopTimer(timerId);
    systemTimer.destroyTimer(timerId, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to destroy timer. Code: ${error.code}, message: ${error.message}`);
        return;
      }
      console.info(`Succeeded in destroying timer.`);
    });
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to operate timer. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to destroy timer. Code: ${error.code}, message: ${error.message}`);
}
```

## systemTimer.destroyTimer

destroyTimer(timer: number): Promise&lt;void&gt;

销毁定时器，使用Promise进行异步回调。需与[systemTimer.createTimer](#systemtimercreatetimer)配合使用，用于销毁通过createTimer创建的定时器，避免内存泄漏。建议先调用[systemTimer.stopTimer](#systemtimerstoptimer)停止定时器后再销毁。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| timer  | number | 是   | 定时器的ID。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。resolve表示定时器销毁成功，reject表示销毁失败。 |

**错误码：**

以下错误码的详细介绍请参见[时间时区服务错误码](./errorcode-time.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 202   | Permission verification failed. A non-system application calls a system API.                                |
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: systemTimer.TimerOptions = {
  type: systemTimer.TIMER_TYPE_REALTIME,
  repeat:false
};
let triggerTime: number = new Date().getTime();
triggerTime += 3000;

try {
  systemTimer.createTimer(options).then((timerId: number) => {
    systemTimer.startTimer(timerId, triggerTime);
    systemTimer.stopTimer(timerId);
    systemTimer.destroyTimer(timerId).then(() => {
      console.info(`Succeeded in destroying timer.`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to destroy timer. Code: ${error.code}, message: ${error.message}`);
    });
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to operate timer. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to destroy timer. Code: ${error.code}, message: ${error.message}`);
}
```