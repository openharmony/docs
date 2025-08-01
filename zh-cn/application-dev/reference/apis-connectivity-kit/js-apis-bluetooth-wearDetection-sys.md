# @ohos.bluetooth.wearDetection(蓝牙佩戴检测模块)(系统接口)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--SE: @chengguohong; @tangjia15-->
<!--TSE: @wangfeng517-->

佩戴检测模块提供了获取蓝牙音频设备(如蓝牙耳机)是否支持佩戴检测、是否开启佩戴检测的方法。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块为系统接口。



## 导入模块

```js
import { wearDetection } from '@kit.ConnectivityKit';
```


## wearDetection.enableWearDetection<sup>11+</sup>

enableWearDetection(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

使能佩戴检测。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH和ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数。当使能佩戴检测成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900003 | Bluetooth disabled.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.enableWearDetection('XX:XX:XX:XX:XX:XX', (err) => {
        if (err) {
            console.error("enableWearDetection error");
        }
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.enableWearDetection<sup>11+</sup>

enableWearDetection(deviceId: string): Promise&lt;void&gt;

使能佩戴检测。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH和ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900003 | Bluetooth disabled.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.enableWearDetection('XX:XX:XX:XX:XX:XX').then(() => {
        console.info("enableWearDetection");
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.disableWearDetection<sup>11+</sup>

disableWearDetection(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

禁用佩戴检测。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH和ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数。当禁用佩戴检测成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900003 | Bluetooth disabled.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.disableWearDetection('XX:XX:XX:XX:XX:XX', (err) => {
        if (err) {
            console.error("disableWearDetection error");
        }
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.disableWearDetection<sup>11+</sup>

disableWearDetection(deviceId: string): Promise&lt;void&gt;

禁用佩戴检测。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH和ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900003 | Bluetooth disabled.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.disableWearDetection('XX:XX:XX:XX:XX:XX').then(() => {
        console.info("disableWearDetection");
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.isWearDetectionSupported<sup>11+</sup>

isWearDetectionSupported(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

判断设备是否支持佩戴检测能力。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 回调函数。当接口调用成功，err为undefined，data为佩戴检测能力支持结果；否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900003 | Bluetooth disabled.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.isWearDetectionSupported('XX:XX:XX:XX:XX:XX', (err, supported) => {
        console.info('device support wear detection ' + supported);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.isWearDetectionSupported<sup>11+</sup>

isWearDetectionSupported(deviceId: string): Promise&lt;boolean&gt;

判断设备是否支持佩戴检测能力。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示支持佩戴检测能力；返回false表示不支持佩戴检测能力。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900003 | Bluetooth disabled.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.isWearDetectionSupported('XX:XX:XX:XX:XX:XX').then((supported) => {
        console.info('device support wear detection ' + supported);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.isWearDetectionEnabled<sup>11+</sup>

isWearDetectionEnabled(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

判断设备佩戴检测能力是否开启。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 回调函数。当接口调用成功，err为undefined，data为佩戴检测能力开启结果；否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900003 | Bluetooth disabled.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.isWearDetectionEnabled('XX:XX:XX:XX:XX:XX', (err, enabled) => {
        console.info('device enable wear detection ' + enabled);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.isWearDetectionEnabled<sup>11+</sup>

isWearDetectionEnabled(deviceId: string): Promise&lt;boolean&gt;

判断设备佩戴检测能力是否开启。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示佩戴检测能力开启；返回false表示佩戴检测能力未开启。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900003 | Bluetooth disabled.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.isWearDetectionEnabled('XX:XX:XX:XX:XX:XX').then((enabled) => {
        console.info('device enable wear detection ' + enabled);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```