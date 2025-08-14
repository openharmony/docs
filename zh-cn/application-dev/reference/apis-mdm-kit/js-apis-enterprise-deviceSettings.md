# @ohos.enterprise.deviceSettings （设备设置管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima-->
<!--Designer: @liuzuming-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供企业设备设置能力，包括设置、获取设备息屏时间等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。

## 导入模块

```ts
import { deviceSettings } from '@kit.MDMKit';
```

## deviceSettings.setValue

setValue(admin: Want, item: string, value: string): void

设置设备策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| item   | string                                                  | 是   | 设备设置策略类型。<br/>- screenOff：设备息屏策略，对于PC/2in1设备，仅支持设置电池供电下的息屏策略。<br/>- dateTime：设置系统时间。<br/>- powerPolicy：设备电源策略，对于PC/2in1设备，仅支持设置电池供电下的电源策略。 |
| value  | string                                                  | 是   | 策略类型值。<br/>当item为screenOff时，value为设备息屏时间（单位：毫秒）。<br/>当item为dateTime时，value为要设置的系统时间（单位：毫秒）。<br/>当item为powerPolicy时，value为JSON字符串，格式：{"powerScene":xx,"powerPolicy":{"powerPolicyAction":xx,"delayTime":xx}}。powerScene为电源策略场景；delayTime为延迟时间（单位：毫秒），不支持设置为30000毫秒；powerPolicyAction为休眠策略。<br/>电源策略场景：<br/>- 0：超时场景。<br/>休眠策略：<br/>- 0：不执行动作。<br/>- 1：自动进入睡眠。<br/>- 2：强制进入睡眠。<br/>- 3：进入休眠。（当前电源子系统不支持）<br/>- 4：关机。 |

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
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  // 需根据实际情况进行替换
  deviceSettings.setValue(wantTemp, 'screenOff', '3000');
  console.info(`Succeeded in setting screen off time.`);
} catch (err) {
  console.error(`Failed to set screen off time. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getValue

getValue(admin: Want, item: string): string

获取设备设置策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| item   | string                                                  | 是   | 设备设置策略类型。<br/>- screenOff：设备息屏策略，对于PC/2in1设备，仅支持查询电池供电下的息屏策略。<br/>- dateTime：设置系统时间。<br/>- powerPolicy：设备电源策略，对于PC/2in1设备，仅支持查询电池供电下的电源策略。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 策略类型值。<br/>当item为screenOff时，返回设备息屏时间（单位：毫秒），对于PC/2in1设备，返回设备电池供电下的息屏时间（单位：毫秒）。<br/>当item为dateTime时，返回设置的系统时间（单位：毫秒）。<br/>当item为powerPolicy时，返回电源策略，对于PC/2in1设备，返回设备电池供电下的电源策略，格式为JSON字符串:{"powerScene":xx,"powerPolicy":{"powerPolicyAction":xx,"delayTime":xx}}。powerScene为电源策略场景；delayTime为延迟时间（单位：毫秒）；powerPolicyAction为休眠策略。<br/>电源策略场景：<br/>- 0：超时场景。<br/>休眠策略：<br/>- 0：不执行动作。<br/>- 1：自动进入睡眠。<br/>- 2：强制进入睡眠。<br/>- 3：进入休眠。（当前电源子系统暂不支持）<br/>- 4：关机。 |

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
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  // 参数需根据实际情况进行替换
  let result: string = deviceSettings.getValue(wantTemp, 'screenOff');
  console.info(`Succeeded in getting screen off time, result : ${result}`);
} catch (err) {
  console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.setHomeWallpaper<sup>20+</sup>

setHomeWallpaper(admin: Want, fd: number): Promise&lt;void&gt;

设置桌面壁纸，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_WALLPAPER

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                 |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。               |
| fd     | number                                                  | 是   | 需要设置为桌面壁纸图片的文件描述符，可以通过file.fs的[openSync](../apis-core-file-kit/js-apis-file-fs.md#fsopensync)接口获取应用沙箱目录下的图片文件描述符。壁纸图片大小不能超过100MB。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当设置桌面壁纸失败后会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

<!--code_no_check-->
```ts
import { deviceSettings } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs }  from '@kit.CoreFileKit';

let wantTemp: Want = {
  // 请根据实际情况修改
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 参数根据实际情况进行替换
let filename: string = "homewallpaper.jpg";
let filePath: string = context.filesDir + '/' + filename;
let fd: number = fs.openSync(filePath, fs.OpenMode.READ_WRITE).fd;
deviceSettings.setHomeWallpaper(wantTemp, fd).then(() => {
  console.info('Succeeded in setting home wallpaper');
}).catch((err: BusinessError) => {
  console.error(`Failed to set home wallpaper. Code: ${err.code}, message: ${err.message}`);
});
```
## deviceSettings.setUnlockWallpaper<sup>20+</sup>

setUnlockWallpaper(admin: Want, fd: number): Promise&lt;void&gt;

设置锁屏壁纸，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_WALLPAPER

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                 |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。               |
| fd     | number                                                  | 是   | 需要设置为锁屏壁纸图片的文件描述符，可以通过file.fs的[openSync](../apis-core-file-kit/js-apis-file-fs.md#fsopensync)接口获取应用沙箱目录下的图片文件描述符。壁纸图片大小不能超过100MB。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当设置锁屏壁纸失败后会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

<!--code_no_check-->
```ts
import { deviceSettings } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs }  from '@kit.CoreFileKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 参数根据实际情况进行替换
let filename: string = "lockwallpaper.jpg";
let filePath: string = context.filesDir + '/' + filename;
let fd: number = fs.openSync(filePath, fs.OpenMode.READ_WRITE).fd;
deviceSettings.setUnlockWallpaper(wantTemp, fd).then(() => {
  console.info('Succeeded in setting lock wallpaper');
}).catch((err: BusinessError) => {
  console.error(`Failed to set lock wallpaper. Code: ${err.code}, message: ${err.message}`);
});
```
