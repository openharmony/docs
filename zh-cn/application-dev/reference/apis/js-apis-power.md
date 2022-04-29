# 系统电源管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

该模块主要提供重启、关机、查询屏幕状态等接口。


## 导入模块

```js
import power from '@ohos.power';
```

## 系统能力

SystemCapability.PowerManager.PowerManager.Core


## power.shutdownDevice

shutdownDevice(reason: string): void

系统关机。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.REBOOT

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

**需要权限：** ohos.permission.REBOOT（重启权限）、ohos.permission.REBOOT_RECOVERY（重启并进入recovery或者updater模式的权限）

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
