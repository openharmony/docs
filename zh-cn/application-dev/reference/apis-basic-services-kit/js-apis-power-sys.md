# @ohos.power (系统电源管理)(系统接口)

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @w_Machine_cc-->

该模块主要提供重启、关机、查询屏幕状态等接口。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.power (系统电源管理)](js-apis-power.md)。

## 导入模块

```js
import {power} from '@kit.BasicServicesKit';
```

## power.shutdown

shutdown(reason: string): void

系统关机。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REBOOT

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| reason | string | 是    | 关机原因；该参数必须为字符串类型。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |


**示例：**

```js
try {
    power.shutdown('shutdown_test');
} catch(err) {
    console.error('shutdown failed, err: ' + err);
}
```

## power.reboot<sup>9+</sup>

reboot(reason: string): void

重启设备。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REBOOT

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| reason | string | 是   | 重启原因；该参数必须为字符串类型。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
try {
    power.reboot('reboot_test');
} catch(err) {
    console.error('reboot failed, err: ' + err);
}
```

## power.wakeup<sup>9+</sup>

wakeup(detail: string): void

唤醒设备。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.POWER_MANAGER

API version 9-18，使用该接口无需权限；从API version 19开始，需要申请“ohos.permission.POWER_MANAGER”权限。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| detail | string | 是   | 唤醒原因；该参数必须为字符串类型。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
try {
    power.wakeup('wakeup_test');
} catch(err) {
    console.error('wakeup failed, err: ' + err);
}
```

## power.suspend<sup>9+</sup>

suspend(isImmediate?: boolean): void

休眠设备。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.POWER_MANAGER

API version 9-18，使用该接口无需权限；从API version 19开始，需要申请“ohos.permission.POWER_MANAGER”权限。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| isImmediate<sup>10+</sup> | boolean |  否  | 是否直接休眠设备。true表示灭屏后立即进入休眠，不填该参数则默认为false，表示灭屏后由系统自动检测何时进入休眠。如果只想做灭屏操作，建议不填参数。<br>**说明：** 从API version 10开始，支持该参数。|


**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```js
try {
    power.suspend();
} catch(err) {
    console.error('suspend failed, err: ' + err);
}
```

## power.setPowerMode<sup>9+</sup>

setPowerMode(mode: DevicePowerMode, callback: AsyncCallback&lt;void&gt;): void

设置当前设备的电源模式。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.POWER_OPTIMIZATION

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| mode     | DevicePowerMode | 是   | 电源模式；该参数类型是一个枚举类。                                                   |
| callback | AsyncCallback&lt;void&gt;            | 是   | 回调函数。当设置电源模式成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE, (err: Error) => {
    if (typeof err === 'undefined') {
        console.info('set power mode to MODE_PERFORMANCE');
    } else {
        console.error('set power mode failed, err: ' + err);
    }
});
```

## power.setPowerMode<sup>9+</sup>

setPowerMode(mode: DevicePowerMode): Promise&lt;void&gt;

设置当前设备的电源模式。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.POWER_OPTIMIZATION

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型                                 | 必填 | 说明       |
| ------ | ------------------------------------ | ---- | ---------- |
| mode   | DevicePowerMode | 是   | 电源模式；该参数类型是一个枚举类。 |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE)
.then(() => {
    console.info('set power mode to MODE_PERFORMANCE');
})
.catch((err : Error)=> {
    console.error('set power mode failed, err: ' + err);
});
```

## power.setScreenOffTime<sup>12+</sup>

setScreenOffTime(timeout: number): void

设置熄屏超时时间。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.POWER_MANAGER

API version 12-18，使用该接口无需权限；从API version 19开始，需要申请“ohos.permission.POWER_MANAGER”权限。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| timeout | number | 是    | 熄屏超时时间，单位是毫秒，大于0代表熄屏超时时间，-1代表恢复默认超时时间，其它是无效值。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1. Parameter verification failed. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
try {
    power.setScreenOffTime(30000);
} catch(err) {
    console.error('set screen off time failed, err: ' + err);
}
```

## power.hibernate<sup>12+</sup>

hibernate(clearMemory: boolean): void

休眠设备。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.POWER_MANAGER

API version 12-18，使用该接口无需权限；从API version 19开始，需要申请“ohos.permission.POWER_MANAGER”权限。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| clearMemory | boolean | 是    | true 代表在进入休眠之前清理内存，否则为false。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**示例：**

```js
try {
    power.hibernate(true);
} catch(err) {
    console.error('hibernate failed, err: ' + err);
}
```

## power.refreshActivity<sup>20+</sup>

refreshActivity(reason: string): void

刷新设备活动状态（如：重设屏幕超时息屏时间等）。
只有设备在活动状态下生效，设备活动状态见[power.isActive](js-apis-power.md#powerisactive9)接口。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REFRESH_USER_ACTION

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| reason | string | 是    | 刷新设备活动状态的原因。该参数必须为字符串类型。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 4900201 |The device activity is being refreshed too frequently; the minimum time interval is 100 ms. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
try {
    power.refreshActivity('refreshActivity_test');
} catch(err) {
    console.error('refreshActivity failed, err: ' + err);
}
```

## power.setPowerKeyFilteringStrategy<sup>21+</sup>

setPowerKeyFilteringStrategy(strategy: PowerKeyFilteringStrategy): void;

设置电源键过滤策略，在电源服务订阅电源键事件后，用于配置电源键事件的处理方式。
电源键过滤策略见[power.PowerKeyFilteringStrategy](js-apis-power.md#powerkeyfilteringstrategy21)接口。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.POWER_MANAGER

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| strategy | PowerKeyFilteringStrategy | 是    | 电源键过滤策略。该参数必须为枚举类型。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
try {
    power.setPowerKeyFilteringStrategy(power.PowerKeyFilteringStrategy.LONG_PRESS_FILTERING_ONCE);
} catch(err) {
    console.error('setPowerKeyFilteringStrategy failed, err: ' + err);
}
```