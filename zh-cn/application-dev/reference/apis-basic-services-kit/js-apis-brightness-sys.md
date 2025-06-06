# @ohos.brightness (屏幕亮度)(系统接口)

该模块提供屏幕亮度的设置接口。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```js
import brightness from '@ohos.brightness';
```

## brightness.setValue

setValue(value: number): void

设置系统的屏幕亮度。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| value  | number | 是   | 亮度的值。范围：0~255；该参数必须为数字类型。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕亮度错误码](errorcode-brightness.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4700101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
try {
    brightness.setValue(128);
} catch(err) {
    console.error('set brightness failed, err: ' + err);
}
```

## brightness.setValue<sup>11+</sup>

setValue(value: number, continuous: boolean): void

设置系统的屏幕亮度。用于连续调节亮度的场景，在连续调节亮度过程中，设置continuous为true，结束时设置continuous为false，会有更好的性能。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| value  | number | 是   | 亮度的值。范围：0~255。 |
| continuous  | boolean | 是   | 亮度调节是否连续。true表示亮度调节连续，false表示亮度调节不连续，默认为false。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕亮度错误码](errorcode-brightness.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4700101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
try {
    brightness.setValue(128, true);
} catch(err) {
    console.error('set brightness failed, err: ' + err);
}
```