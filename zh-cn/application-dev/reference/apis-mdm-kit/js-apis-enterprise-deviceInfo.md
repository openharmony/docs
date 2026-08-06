# @ohos.enterprise.deviceInfo（设备信息管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供企业设备信息管理能力，支持获取设备序列号、设备名称、SIM卡信息等。企业管理员可通过此模块查询设备详细信息，实现设备资产的统一管理和追踪。

**使用场景：**
- 设备资产管理与追踪
- 企业设备合规性检查
- 设备信息采集与统计
- 故障诊断与设备识别

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。

## 导入模块

```ts
import { deviceInfo } from '@kit.MDMKit';
```

## deviceInfo.getDeviceInfo

getDeviceInfo(admin: Want, label: string): string

获取设备信息。

**需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件，用于指定具有设备管理能力的目标应用。Want对象中必须包含abilityName（扩展能力名称）和bundleName（应用包名）两个必填字段。                                               |
| label  | string                                                  | 是   | 支持获取的设备信息标签。<br/>- deviceName：设备名称。<br/>- deviceSerial：设备序列号。<br/>- simInfo：SIM卡信息。 <!--RP1--><!--RP1End-->|

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 返回label对应的参数值。<br/>当label为simInfo时，返回值为表示SIM卡信息的JSON字符串。例如：[{"slotId": 0, "MEID": "", "IMSI": "", "ICCID": "", "IMEI": "", "NUMBER": ""}, {"slotId": 1, "MEID": "", "IMSI": "", "ICCID": "", "IMEI": "", "NUMBER": ""}]，其中：slotId:0表示卡槽1，slotId:1表示卡槽2。 NUMBER：从API version 23开始支持，表示手机号码，格式为包含国家码的E.164国际标准格式（如 +8612345678901）。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200007 | The system ability works abnormally. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceInfo } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 需根据实际情况进行替换
  let result: string = deviceInfo.getDeviceInfo(wantTemp, 'deviceName');
  console.info(`Succeeded in getting device name, result : ${result}`);
} catch (err) {
  console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);
}
```
