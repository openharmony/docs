# @ohos.bluetooth.wearDetection(蓝牙佩戴检测模块)

佩戴检测模块提供了获取蓝牙音频设备（如蓝牙耳机）是否支持佩戴检测、是否开启佩戴检测的方法。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import wearDetection from '@ohos.bluetooth.wearDetection';
```


## wearDetection.enableWearDetection<sup>11+</sup><a name="enableWearDetection"></a>

enableWearDetection(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

开启、使能佩戴检测。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH和ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 通过注册回调函数获取使能佩戴检测的结果。如果成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
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

## wearDetection.enableWearDetection<sup>11+</sup><a name="enableWearDetection"></a>

enableWearDetection(deviceId: string): Promise&lt;void&gt;

开启、使能佩戴检测。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH和ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | 以Promise的形式返回结果。如果成功，err为undefine的，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.enableWearDetection('XX:XX:XX:XX:XX:XX').then(() => {
            console.info("enableWearDetection");
        }
    );
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.disableWearDetection<sup>11+</sup><a name="disableWearDetection"></a>

disableWearDetection(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

关闭、禁用佩戴检测。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH和ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 通过注册回调函数获取禁用佩戴检测的结果。。如果成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
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

## wearDetection.disableWearDetection<sup>11+</sup><a name="disableWearDetection"></a>

disableWearDetection(deviceId: string): Promise&lt;void&gt;

关闭、禁用佩戴检测。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH和ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | 以Promise的形式返回结果。如果成功，err为undefine的，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**示例：**

```js
try {
    wearDetection.disableWearDetection('XX:XX:XX:XX:XX:XX').then(() => {
            console.info("disableWearDetection");
        }
    );
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.isWearDetectionSupported<sup>11+</sup><a name="isWearDetectionSupported"></a>

isWearDetectionSupported(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

获取设备是否支持佩戴检测。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 通过注册回调函数获取设备是否支持佩戴检测。如果成功，值在supported中返回。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
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

## wearDetection.isWearDetectionSupported<sup>11+</sup><a name="isWearDetectionSupported"></a>

isWearDetectionSupported(deviceId: string): Promise&lt;boolean&gt;

获取设备是否支持佩戴检测。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | 以Promise的形式获取设备是否支持佩戴检测。如果成功，值在supported中返回。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
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

## wearDetection.isWearDetectionEnabled<sup>11+</sup><a name="isWearDetectionEnabled"></a>

isWearDetectionEnabled(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

获取设备佩戴检测是否开启。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 通过注册回调函数获取设备佩戴检测是否开启。如果成功，值在enabled中返回。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
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

## wearDetection.isWearDetectionEnabled<sup>11+</sup><a name="isWearDetectionEnabled"></a>

isWearDetectionEnabled(deviceId: string): Promise&lt;boolean&gt;

获取设备佩戴检测是否开启。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | 以Promise的形式获取设备佩戴检测是否开启。如果成功，值在enabled中返回。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
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