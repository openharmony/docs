# 系统电源管理

该模块主要提供重启、关机、查询屏幕状态等接口。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import power from '@ohos.power';
```


## power.shutdownDevice

shutdownDevice(reason: string): void

系统关机。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.REBOOT

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| reason | string | 是    | 关机原因。 |

**示例：**

```js
power.shutdownDevice("shutdown_test");
console.info('power_shutdown_device_test success')
```


## power.rebootDevice

rebootDevice(reason: string): void

重启设备。

**需要权限：** ohos.permission.REBOOT

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明    |
| ------ | ------ | ---- | ----- |
| reason | string | 是    | 重启原因。 |

**示例：**

```js
power.rebootDevice("reboot_test");
console.info('power_reboot_device_test success')
```


## power.isScreenOn

isScreenOn(callback: AsyncCallback&lt;boolean&gt;): void

检测当前设备的亮灭屏状态。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名      | 类型                           | 必填   | 说明                                       |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 指定的callback回调方法，用于获取返回值。<br/>callback返回值：亮屏返回true，灭屏返回false。 |

**示例：**

```js
power.isScreenOn((error, screenOn) => {
    if (typeof error === "undefined") {
        console.info('screenOn status is ' + screenOn);
    } else {
        console.log('error: ' + error);
    }
})
```


## power.isScreenOn

isScreenOn(): Promise&lt;boolean&gt;

检测当前设备的亮灭屏状态。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**返回值：**
| 类型                     | 说明                                      |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于异步获取返回值，亮屏返回true，灭屏返回false。 |

**示例：**

```js
power.isScreenOn()
.then(screenOn => {
    console.info('screenOn status is ' + screenOn);
})
.catch(error => {
    console.log('error: ' + error);
})
```

## power.wakeupDevice<sup>9+</sup>

wakeupDevice(detail: string): void

唤醒设备。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| detail | string | 是   | 唤醒原因。 |

**示例：**

```js
power.wakeupDevice("application");
console.info('power_wakeup_device_test success')
```

## power.suspendDevice<sup>9+</sup>

suspendDevice(): void

休眠设备。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**示例：**

```js
power.suspendDevice();
console.info('power_suspend_device_test success')
```

## power.getPowerMode<sup>9+</sup>

getPowerMode(callback: AsyncCallback&lt;DevicePowerMode&gt;): void

获取当前设备的电源模式。

**需要权限：** ohos.permission.POWER_OPTIMIZATION

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;DevicePowerMode&gt; | 是   | 指定的callback回调方法，用于获取返回值。<br/>callback返回值：[DevicePowerMode](#devicepowermode9)。 |

**示例：**

```js
power.getPowerMode((error, mode) => {
    if (typeof error === "undefined") {
        console.info('power mode is ' + mode);
    } else {
        console.log('error: ' + error);
    }
})
```


## power.getPowerMode<sup>9+</sup>

getPowerMode(): Promise&lt;DevicePowerMode&gt;

获取当前设备的电源模式。

**需要权限：** ohos.permission.POWER_OPTIMIZATION

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**返回值：**

| 类型                           | 说明                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| Promise&lt;DevicePowerMode&gt; | Promise实例，用于异步获取返回值，[DevicePowerMode](#devicepowermode9)。 |

**示例：**

```js
power.getPowerMode()
.then(mode => {
    console.info('power mode is ' + mode);
})
.catch(error => {
    console.log('error: ' + error);
})
```

## power.setPowerMode<sup>9+</sup>

setPowerMode(mode: DevicePowerMode, callback: AsyncCallback&lt;void&gt;): void

设置当前设备的电源模式。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.POWER_OPTIMIZATION

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                     |
| -------- | ------------------------------------ | ---- | ------------------------ |
| mode     | [DevicePowerMode](#devicepowermode9) | 是   | 电源模式。               |
| callback | AsyncCallback&lt;void&gt;            | 是   | 指定的callback回调方法。 |

**示例：**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE, error => {
    if (typeof error === "undefined") {
        console.info('set power mode to MODE_PERFORMANCE');
    } else {
        console.log('error: ' + error);
    }
})
```


## power.setPowerMode<sup>9+</sup>

setPowerMode(mode: DevicePowerMode): Promise&lt;void&gt;

设置当前设备的电源模式。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.POWER_OPTIMIZATION

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型                                 | 必填 | 说明       |
| ------ | ------------------------------------ | ---- | ---------- |
| mode   | [DevicePowerMode](#devicepowermode9) | 是   | 电源模式。 |

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise实例。 |

**示例：**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE)
.then(() => {
    console.info('set power mode to MODE_PERFORMANCE');
})
.catch(error => {
    console.log('error: ' + error);
})
```

## DevicePowerMode<sup>9+</sup>

表示电源模式的枚举值。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core


| 名称                    | 默认值 | 描述                   |
| ----------------------- | ------ | ---------------------- |
| MODE_NORMAL             | 600    | 表示标准模式，默认值。 |
| MODE_POWER_SAVE         | 601    | 表示省电模式。         |
| MODE_PERFORMANCE        | 602    | 表示性能模式。         |
| MODE_EXTREME_POWER_SAVE | 603    | 表示超级省电模式。     |
