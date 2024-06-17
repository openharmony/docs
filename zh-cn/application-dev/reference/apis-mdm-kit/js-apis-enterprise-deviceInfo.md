# @ohos.enterprise.deviceInfo（设备信息管理）

本模块提供企业设备信息管理能力，包括获取设备序列号等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，需将设备管理应用激活后调用，实现相应功能。

## 导入模块

```ts
import { deviceInfo } from '@kit.MDMKit';
```

## deviceInfo.getDeviceInfo

getDeviceInfo(admin: Want, label: string): string

获取设备信息。

**需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。                                               |
| label  | string                                                  | 是   | 管理员的能力信息。<br/>- deviceName：设备名称。<br/>- deviceSerial：设备序列号。<br/>- simInfo：SIM卡信息。 <!--RP1--><!--RP1End-->|

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 返回label对应的参数值。<br/>当label为simInfo时，返回值为表示SIM卡信息的JSON字符串。例如：[{"slotId": 0, "MEID": "", "IMSI": "", "ICCID": "", "IMEI": ""}, {"slotId": 1, "MEID": "", "IMSI": "", "ICCID": "", "IMEI": ""}]，其中：slotId:0表示卡槽1，slotId:1表示卡槽2。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: string = deviceInfo.getDeviceInfo(wantTemp, 'deviceName');
  console.info(`Succeeded in getting device name, result : ${result}`);
} catch (err) {
  console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);
}
```
