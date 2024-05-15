# @ohos.power (系统电源管理)(系统接口)

该模块主要提供重启、关机、查询屏幕状态等接口。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.power (系统电源管理)](js-apis-power.md)。

## 导入模块

```js
import power from '@ohos.power';
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
| reason | string | 是    | 关机原因。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | If connecting to the service failed. |

**示例：**

```js
try {
    power.shutdown('shutdown_test');
} catch(err) {
    console.error('shutdown failed, err: ' + err);
}
```
## power.rebootDevice<sup>(deprecated)</sup>

rebootDevice(reason: string): void

> **说明：**<br>从API version 7开始支持，从API version 9开始不再维护。建议使用power.reboot (js-apis-power-sys.md#powerreboot9)替代，替代接口能力仅对系统应用开放。

重启设备。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REBOOT，仅对系统应用开放。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| reason | string | 是    | 重启原因。 |

**示例：**

```js
power.rebootDevice('reboot_test');
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
| reason | string | 是   | 重启原因。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | If connecting to the service failed. |

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

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| detail | string | 是   | 唤醒原因。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | If connecting to the service failed. |

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

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| isImmediate<sup>10+</sup> | boolean |  否  | 是否直接休眠设备。不填该参数则默认为false由系统自动检测何时进入休眠。<br>**说明：** 从API version 10开始，支持该参数。|


**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | If connecting to the service failed. |

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
| mode     | DevicePowerMode | 是   | 电源模式。                                                   |
| callback | AsyncCallback&lt;void&gt;            | 是   | 回调函数。当设置电源模式成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | If connecting to the service failed. |

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
| mode   | DevicePowerMode | 是   | 电源模式。 |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[系统电源管理错误码](errorcode-power.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4900101 | If connecting to the service failed. |

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
