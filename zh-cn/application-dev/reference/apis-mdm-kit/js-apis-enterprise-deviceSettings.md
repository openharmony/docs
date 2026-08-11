# @ohos.enterprise.deviceSettings（设备设置管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供企业设备设置能力，支持设置和获取设备息屏时间、系统时间、电源策略、护眼模式、默认输入法、壁纸、隐藏设置项等。

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

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

<!--Table: 10%; 10%; 10%; 70%-->
| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| item   | string                                                  | 是   | 设备设置策略类型。<br/>- screenOff：设备息屏策略。对于PC/2in1设备，支持设置电池和电源供电下的设备息屏策略。<br/>- dateTime：设置系统时间。<br/>- powerPolicy：设备电源策略。该能力仅支持PC/2in1设备，策略设置之后不刷新设置—电源和电池页面，在手机平板设备设置后不生效。<br/>对于PC/2in1设备，仅支持设置电池供电下的设备电源策略。设置设备超时灭屏时睡眠延迟策略，睡眠动作需要在设置—电源和电池页面显示的睡眠时间之后等待设置的delayTime才会生效。<br/>- eyeComfort：从API version 23开始支持，设置护眼模式开关状态，仅支持全天开启和关闭护眼模式。<br/>- defaultInputMethod：从API version 23开始支持，设置默认输入法。 |
| value  | string                                                  | 是   | 策略类型值。<br/>当item为screenOff时，value为设备息屏时间（单位：毫秒）。建议value值和设置页面手动操作下拉框中的可选项保持一致。仅在PC/2in1设备上支持传-1设置永不息屏，其他设备无效。<br/>当item为dateTime时，value为要设置的系统时间（单位：毫秒）。<br/>当item为powerPolicy时，value为JSON字符串，格式：{"powerScene":xx,"powerPolicy":{"powerPolicyAction":xx,"delayTime":xx}}。<br/>powerScene为电源策略场景，可设置参数如下：<br/>- 0：超时灭屏场景。<br/>powerPolicyAction为休眠动作策略场景，可设置参数如下：<br/>- 0：不执行动作。<br/>- 1：自动进入睡眠。<br/>- 2：强制进入睡眠。<br/>- 3：进入休眠，该策略暂不生效。<br/>- 4：关机。<br/>delayTime为延迟时间（单位：毫秒），不支持设置为30000毫秒，其余数值均在允许范围内。<br/>当item为eyeComfort时，value为护眼模式开关状态的字符串。<br/>- on：全天开启护眼模式。<br/>- off：关闭护眼模式。<br/>当item为defaultInputMethod时，value为输入法应用包名字符串。<br/>- 可以通过[getCurrentInputMethod](../apis-ime-kit/js-apis-inputmethod.md#inputmethodgetcurrentinputmethod9)获取当前输入法应用包名。 |

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
  abilityName: 'EnterpriseAdminAbility'
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
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| item   | string                                                  | 是   | 设备设置策略类型。<br/>- screenOff：设备息屏策略，对于PC/2in1设备，支持查询电池供电下的设备息屏策略。<br/>- powerPolicy：设备电源策略，仅对PC/2in1设备生效，仅支持查询电池供电下的设备电源策略。<br/>- eyeComfort：从API version 23开始支持，护眼模式开关状态。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 策略类型值。<br/>当item为screenOff时，返回设备息屏时间（单位：毫秒），对于PC/2in1设备，返回设备电池供电下的息屏时间（单位：毫秒）。<br/>当item为powerPolicy时，返回电源策略，对于PC/2in1设备，返回设备电池供电下的电源策略，格式为JSON字符串:{"powerScene":xx,"powerPolicy":{"powerPolicyAction":xx,"delayTime":xx}}。powerScene为电源策略场景；delayTime为延迟时间（单位：毫秒）；powerPolicyAction为休眠策略。<br/>电源策略场景：<br/>- 0：超时场景。<br/>休眠策略：<br/>- 0：不执行动作。<br/>- 1：自动进入睡眠。<br/>- 2：强制进入睡眠。<br/>- 3：进入休眠，该策略暂不生效。<br/>- 4：关机。<br/>当item为eyeComfort时，返回的value为护眼模式开关状态的字符串。<br/>- on：全天开启护眼模式。<br/>- off：关闭护眼模式。<br/>- unknown：其他模式。 |

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
  abilityName: 'EnterpriseAdminAbility'
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

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| fd     | number                                                  | 是   | 需要设置为桌面壁纸图片的文件描述符，可以通过file.fs的[openSync](../apis-core-file-kit/js-apis-file-fs.md#fileioopensync)接口获取应用沙箱目录下的图片文件描述符。壁纸图片大小不能超过100MB。 |

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
  abilityName: 'EnterpriseAdminAbility'
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
}).finally(() => {
  fs.closeSync(fd);
});
```
## deviceSettings.setUnlockWallpaper<sup>20+</sup>

setUnlockWallpaper(admin: Want, fd: number): Promise&lt;void&gt;

设置锁屏壁纸，使用Promise异步回调。企业设备管理应用可通过此接口统一设置企业设备的锁屏壁纸，用于企业形象展示或安全管控等场景。

**需要权限：** ohos.permission.ENTERPRISE_SET_WALLPAPER

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| fd     | number                                                  | 是   | 需要设置为锁屏壁纸图片的文件描述符，可以通过file.fs的[openSync](../apis-core-file-kit/js-apis-file-fs.md#fileioopensync)接口获取应用沙箱目录下的图片文件描述符。壁纸图片大小不能超过100MB。 |

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
  abilityName: 'EnterpriseAdminAbility'
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
}).finally(() => {
  fs.closeSync(fd);
});
```

## deviceSettings.setValueForAccount<sup>24+</sup>

setValueForAccount(admin: Want, item: SettingsItem, accountId: number, value: string): void

设置指定用户的设备设置策略。该接口可以设置指定用户在设置应用中的某个参数，比如设置用户100的设备名称等。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| item   | [SettingsItem](#settingsitem24)                                                  | 是   | 设备设置策略类型。|
| accountId | number                                                 | 是   | 用户ID，取值范围：大于等于0。<br/>accountId可以通过[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。                       |
| value  | string                                                  | 是   | 策略类型值。<br/>当item为[SettingsItem.DEVICE_NAME](#settingsitem24)时，value为设备名称的字符串。 字符串长度范围：大于等于1，小于等于100。只允许设置当前用户的设备名称，设置其他用户的设备名称返回9200012错误码。<br/>当item为[SettingsItem.FLOATING_NAVIGATION](#settingsitem24)时，在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。只允许设置当前用户的三键导航，设置其他用户的三键导航不会生效，value为三键导航的开关状态。<br/>- '0'：表示开启三键导航（通过接口[enterKioskMode](../apis-ability-kit/js-apis-app-ability-kioskManager.md#kioskmanagerenterkioskmode)进入Kiosk模式下，三键导航显示依赖底部手势开启；即三键导航开关和底部手势开关同时开启时，三键导航才会显示。底部手势可通过接口[applicationManager.setKioskFeatures](./js-apis-enterprise-applicationManager.md#applicationmanagersetkioskfeatures20)设置开启或关闭）。<br/>- '1'：表示关闭三键导航。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.  |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 需根据实际情况进行替换
  let accountId = 100;
  let deviceName: string = "deviceName"
  deviceSettings.setValueForAccount(wantTemp, deviceSettings.SettingsItem.DEVICE_NAME, accountId, deviceName);
  console.info('Succeeded in setting device name.');
} catch (err) {
  console.error(`Failed to set device name. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getValueForAccount<sup>24+</sup>

getValueForAccount(admin: Want, item: SettingsItem, accountId: number): string

获取指定用户的设备设置策略。该接口可以获取指定用户在设置应用中的某个参数，比如获取用户100的设备名称等。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| item   | [SettingsItem](#settingsitem24)                         | 是   | 设备设置策略类型。支持的策略类型包括：DEVICE_NAME（设备名称）、FLOATING_NAVIGATION（三键导航）。|
| accountId | number                                                 | 是   | 用户ID，取值范围：大于等于0。<br/>accountId可以通过[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。  |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 策略类型值。<br/>当item为[SettingsItem.DEVICE_NAME](#settingsitem24)时，返回当前用户的设备名称，查询非当前用户的设备名称返回9200012错误码。 <br/>当item为[SettingsItem.FLOATING_NAVIGATION](#settingsitem24)时，返回指定用户的三键导航的开关状态。<br/>当item为[SettingsItem.FLOATING_NAVIGATION](#settingsitem24)时，该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.  |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 需根据实际情况进行替换
  let accountId = 100;
  let result: string = deviceSettings.getValueForAccount(wantTemp, deviceSettings.SettingsItem.DEVICE_NAME, accountId);
  console.info(`Succeeded in getting device name, result : ${result}`);
} catch (err) {
  console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.addHiddenSettingsMenu<sup>24+</sup>

addHiddenSettingsMenu(admin: Want, menusToHidden: Array\<SettingsMenu>): void

添加设置项至当前用户下的隐藏设置项列表。添加至隐藏设置项列表的设置项在当前用户的设置菜单中会被隐藏，隐藏后不可以在设置的搜索中搜索到。如果通过某种方式搜索到该设置项，点击后也无法打开。调用接口后即刻生效，无需重启设置应用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| menusToHidden | Array\<[SettingsMenu](#settingsmenu24)>          | 是   | 隐藏的设置项列表。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.  |
| 9200016  | Service timeout. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let menusToHidden: Array<deviceSettings.SettingsMenu> = [
  // 需根据实际情况进行替换或增加
  deviceSettings.SettingsMenu.ACCOUNT_ID,
  deviceSettings.SettingsMenu.WIFI,
]

try {
  deviceSettings.addHiddenSettingsMenu(wantTemp, menusToHidden);
  console.info('Succeeded in adding hidden settings menu.');
} catch (err) {
  console.error(`Failed to add hidden settings menu. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.removeHiddenSettingsMenu<sup>24+</sup>

removeHiddenSettingsMenu(admin: Want, menusToHidden: Array\<SettingsMenu>): void

将设置项从当前用户下的隐藏设置项列表中移除。隐藏设置项列表中的设置项在当前用户的设置菜单中会被隐藏，隐藏后不可以在设置的搜索中搜索到，如果通过某种方式搜索到该设置项，点击后也无法打开。若移除后剩余的隐藏设置项列表为空，则设置项会全部显示。调用接口后即刻生效，无需重启设置应用。

从API版本26.0.0开始，调用[setDisallowedPolicyForAccount](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount)接口禁用[SUPER_HUB](./js-apis-enterprise-restrictions.md#featureforaccount)后，再调用该接口将中转站从隐藏设置项列表中移除时，会发生策略冲突，抛出9200010错误码。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| menusToHidden | Array\<[SettingsMenu](#settingsmenu24)>          | 是   | 隐藏的设置项列表。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. <br>适用版本：26.0.0+ |
| 9200012  | Parameter verification failed.  |
| 9200016  | Service timeout. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let menusToHidden: Array<deviceSettings.SettingsMenu> = [
  // 需根据实际情况进行替换或增加
  deviceSettings.SettingsMenu.ACCOUNT_ID,
  deviceSettings.SettingsMenu.WIFI,
]

try {
  deviceSettings.removeHiddenSettingsMenu(wantTemp, menusToHidden);
  console.info('Succeeded in removing hidden settings menu.');
} catch (err) {
  console.error(`Failed to remove hidden settings menu. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getHiddenSettingsMenu<sup>24+</sup>

getHiddenSettingsMenu(admin: Want): Array\<SettingsMenu>

获取配置在当前用户下被隐藏的设置项列表。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**返回值：**

| 类型                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| Array\<[SettingsMenu](#settingsmenu24)> | 隐藏的设置项列表。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  const rawList: Array<number> = deviceSettings.getHiddenSettingsMenu(wantTemp) as Array<number>;
  for (const item of rawList) {
    const menu: deviceSettings.SettingsMenu = item as deviceSettings.SettingsMenu;
    console.info(`Valid SettingsMenu item: ${item} -> ${menu}`);
  }
  console.info('Succeeded in getting hidden settings menu.');
} catch (err) {
  console.error(`Failed to get hidden settings menu. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.setSwitchStatus

setSwitchStatus(admin: Want, key: SwitchKey, status: SwitchStatus): void

设置开关的状态。支持设置星闪、蓝牙、Wi-Fi、NFC的状态为开启或关闭，设置完毕后，用户可以手动开关。支持设置蓝牙、NFC的状态为强制开启，设置完毕后，用户不可以手动开关。若已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) 接口禁用了某个开关，则通过本接口设置这个开关的状态会抛出错误码203，需通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) 接口解除该开关禁用策略。当设备有多个MDM应用时，各MDM应用设置开关状态不存在冲突，最后设置的策略生效。开启(用户可手动开启、关闭)、关闭(用户可手动开启、关闭)、强制开启(用户不可手动关闭)三个状态可以随意切换，也不存在冲突。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS 或 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名   | 类型                                           | 必填   | 说明                                  |
| ------- | ---------------------------------------------- | ---- |------------------------------------------------------------|
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。   |
| key     | [SwitchKey](#switchkey)                        | 是      | 开关的名称，应用申请权限 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS 并通过接口[startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15)激活为自带设备管理应用，可以使用此接口设置以下开关：星闪、蓝牙、Wi-Fi。设置NFC开关时会报错误码9200002。 |
| status  | [SwitchStatus](#switchstatus)                  | 是      | 开关的状态，应用申请权限 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS 并通过接口[startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15)激活为自带设备管理应用，可以使用此接口设置以下状态：ON、OFF。设置为FORCE_ON状态时会报错误码9200002。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.  |
| 9201042  | Failed to toggle the switch state.  |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 需根据实际情况进行替换
  let key: deviceSettings.SwitchKey = deviceSettings.SwitchKey.BLUETOOTH;
  let status: deviceSettings.SwitchStatus  = deviceSettings.SwitchStatus.ON;
  deviceSettings.setSwitchStatus(wantTemp, key, status);
  console.info(`Succeeded in setting switch status.`);
} catch (err) {
  console.error(`Failed to set switch status. Code: ${err.code}, message: ${err.message}`);
}
```

## SettingsItem<sup>24+</sup>

设置的策略类型。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称 | 值   | 说明           |
| ---- | ---- | -------------- |
| DEVICE_NAME   | 0    | 设备名称。 |
| FLOATING_NAVIGATION<sup>24+</sup>   | 1   | 三键导航。 |

## SettingsMenu<sup>24+</sup>

设置项列表。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称   | 值 | 说明         |
| ------ | ------ | ----------- |
| ACCOUNT_ID                  | 0      | 账号。 |
| WIFI                        | 1      | WLAN。 |
| WIFI_PROXY_SETTINGS         | 2      | WLAN 代理。 |
| WIFI_IP_SETTINGS            | 3      | WLAN IP 。 |
| BLUETOOTH                   | 4      | 星闪和蓝牙/蓝牙。 |
| NETWORK                     | 5      | 网络。 |
| MOBILE_NETWORK              | 6      | 移动网络。 |
| SUPER_DEVICE                | 7      | 多设备协同-超级终端。 |
| MORE_CONNECTIVITY_OPTIONS   | 8      | 多设备协同。 |
| HOME_SCREEN_STYLE           | 9      | 桌面和个性化。 |
| DISPLAY_BRIGHTNESS          | 10     | 显示和亮度。 |
| SOUND_VIBRATION             | 11     | 声音和振动。 |
| NOTIFICATIONS               | 12     | 通知和状态栏。 |
| BIOMETRICS_PASSWORD         | 13     | 生物识别和密码。 |
| APPS_AND_SERVICES           | 14     | 应用和元服务。 |
| BATTERY                     | 15     | 电池。 |
| STORAGE                     | 16     | 存储。 |
| PRIVACY_AND_SECURITY        | 17     | 隐私和安全。 |
| DIGITAL_BALANCE             | 18     | 健康使用设备。 |
| SMART_ASSISTANT             | 19     | 智能助手。 |
| ACCESSIBILITY               | 20     | 关怀和无障碍。 |
| SYSTEM                      | 21     | 系统。 |
| ABOUT_DEVICE                | 22     | 关于本机。 |
| SYSTEM_NAVIGATION           | 23     | 系统-系统导航。 |
| LANGUAGE_REGION             | 24     | 系统-语言和地区。 |
| INPUT_METHODS               | 25     | 系统-输入法。 |
| DATE_TIME                   | 26     | 系统-日期和时间。 |
| DATA_CLONE                  | 27     | 系统-数据克隆。 |
| BACKUP_SETTINGS             | 28     | 系统-备份和恢复。 |
| RESET                       | 29     | 系统-重置。 |
| SUPERHUB                    | 30     | 系统-中转站。 |
| USER_EXPERIENCE             | 31     | 系统-用户体验改进计划。 |
| SCREEN_CAST                 | 32     | 多设备协同-无线投屏。 |
| PRINTERS_SCANNERS           | 33     | 打印机和扫描仪。 |
| MOBILE_DATA                 | 34     | 移动网络-移动数据。 |
| PERSONAL_HOTSPOT            | 35     | 移动网络-个人热点。 |
| SIM_MANAGEMENT              | 36     | 移动网络-SIM卡管理。 |
| AIRPLANE_MODE               | 37     | 移动网络-飞行模式。 |
| MANAGE_DATA_USAGE           | 38     | 移动网络-流量管理。 |
| VPN_SETTINGS                | 39     | 移动网络-VPN。 |
| TEXT_DISPLAY_SIZE           | 40     | 显示和亮度-字体大小和界面缩放。 |
| APP_DUPLICATOR              | 41     | 系统-应用分身。 |
| SEARCH                      | 42     | 搜索。 |

## SwitchKey

开关名称的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称       | 值   | 说明       | 需要权限 |
| ---------- | --- | -----------|----------|
| NEARLINK  | 0    | 星闪开关。 | ohos.permission.ENTERPRISE_MANAGE_SETTINGS 或 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS |
| BLUETOOTH | 1    | 蓝牙开关。 | ohos.permission.ENTERPRISE_MANAGE_SETTINGS 或 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS |
| WIFI      | 2    | Wi-Fi开关。 | ohos.permission.ENTERPRISE_MANAGE_SETTINGS 或 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS |
| NFC       | 3    | NFC开关。  | ohos.permission.ENTERPRISE_MANAGE_SETTINGS |

## SwitchStatus

开关状态的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称 | 值   | 说明      | 需要权限 |
| ----| ---- | ----------|----------|
| ON  | 0    | 开启状态。 | ohos.permission.ENTERPRISE_MANAGE_SETTINGS 或 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS |
| OFF | 1    | 关闭状态。 | ohos.permission.ENTERPRISE_MANAGE_SETTINGS 或 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS |
| FORCE_ON  | 2    | 强制开启状态。 | ohos.permission.ENTERPRISE_MANAGE_SETTINGS |