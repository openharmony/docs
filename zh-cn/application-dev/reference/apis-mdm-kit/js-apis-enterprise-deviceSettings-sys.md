# @ohos.enterprise.deviceSettings （设备设置管理）(系统接口)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima-->
<!--Designer: @liuzuming-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供企业设备设置能力，包括获取设备息屏时间等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-term.md#mdm应用设备管理应用)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2)后调用。
> 
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.enterprise.deviceSettings](js-apis-enterprise-deviceSettings.md)。

## 导入模块

```ts
import { deviceSettings } from '@kit.MDMKit';
```

## deviceSettings.setScreenOffTime<sup>11+</sup>

setScreenOffTime(admin: Want, time: number): void

设置设备息屏时间。

**需要权限：** ohos.permission.ENTERPRISE_SET_SCREENOFF_TIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。     |
| time | number            | 是    | 设备息屏时间（单位：毫秒，建议参数与设备可选息屏时间保持一致）。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
  deviceSettings.setScreenOffTime(wantTemp, 30000);
  console.info(`Succeeded in setting screen off time`);
} catch(err) {
  console.error(`Failed to set screen off time. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getScreenOffTime

getScreenOffTime(admin: Want, callback: AsyncCallback&lt;number&gt;): void

获取设备息屏时间，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| callback | AsyncCallback&lt;number&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为设备息屏时间（单位：毫秒），否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

deviceSettings.getScreenOffTime(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting screen off time, result : ${result}`);
});
```

## deviceSettings.getScreenOffTime

getScreenOffTime(admin: Want): Promise&lt;number&gt;

获取设备息屏时间，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise对象，返回设备息屏时间（单位：毫秒）。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

deviceSettings.getScreenOffTime(wantTemp).then((result) => {
  console.info(`Succeeded in getting screen off time, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
});
```

## deviceSettings.installUserCertificate

installUserCertificate(admin: Want, certificate: CertBlob, callback: AsyncCallback&lt;string&gt;): void

安装用户证书，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| certificate    | [CertBlob](#certblob)     | 是    | 证书信息。证书文件应放在应用沙箱路径等应用有权限访问的路径下。 |
| callback | AsyncCallback&lt;string&gt;            | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。      |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9201001 | Failed to manage the certificate. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

<!--code_no_check-->
```ts
import { deviceSettings } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let certFileArray: Uint8Array = new Uint8Array();
// 变量context需要在MainAbility的onCreate回调函数中进行初始化
// test.cer需要放置在rawfile目录下
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
context.resourceManager.getRawFileContent("test.cer").then((value) => {
  certFileArray = value;
  deviceSettings.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" }, (err, result) => {
    if (err) {
      console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);
    }
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to get row file content. message: ${error.message}`);
  return;
});
```

## deviceSettings.installUserCertificate

installUserCertificate(admin: Want, certificate: CertBlob): Promise&lt;string&gt;

安装用户证书，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| certificate    | [CertBlob](#certblob)     | 是    | 证书信息。证书文件应放在应用沙箱路径等应用有权限访问的路径下。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise对象，返回当前证书安装后的uri，用于卸载证书。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9201001 | Failed to manage the certificate. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

<!--code_no_check-->
```ts
import { deviceSettings } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let certFileArray: Uint8Array = new Uint8Array();
// 变量context需要在MainAbility的onCreate回调函数中进行初始化
// test.cer需要放置在rawfile目录下
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
context.resourceManager.getRawFileContent("test.cer").then((value) => {
  certFileArray = value
  deviceSettings.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" })
    .then((result) => {
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);
    }).catch((err: BusinessError) => {
    console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to get row file content. message: ${error.message}`);
  return;
});
```

## CertBlob

证书信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称         | 类型     | 只读 | 可选 | 说明                            |
| ----------- | --------| ----- | ---- | ------------------------------- |
| inData | Uint8Array | 否 | 否 |证书的二进制内容。 |
| alias | string | 否 | 否 |证书别名。 |

## deviceSettings.uninstallUserCertificate

uninstallUserCertificate(admin: Want, certUri: string, callback: AsyncCallback&lt;void&gt;): void

卸载用户证书，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| certUri    | string    | 是    | 证书uri，由安装用户证书接口[installUserCertificate](#devicesettingsinstallusercertificate)设置返回。 |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。      |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9201001 | Failed to manage the certificate. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// 需根据实际情况进行替换
let aliasStr = "certName";
deviceSettings.uninstallUserCertificate(wantTemp, aliasStr, (err) => {
  if (err) {
    console.error(`Failed to uninstall user certificate. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in uninstalling user certificate`);
});
```

## deviceSettings.uninstallUserCertificate

uninstallUserCertificate(admin: Want, certUri: string): Promise&lt;void&gt;

卸载用户证书，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| certUri    | string     | 是    | 证书uri，由安装用户证书接口[installUserCertificate](#devicesettingsinstallusercertificate-1)设置返回。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当卸载用户证书失败时会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9201001 | Failed to manage the certificate. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// 需根据实际情况进行替换
let aliasStr = "certName"
deviceSettings.uninstallUserCertificate(wantTemp, aliasStr).then(() => {
  console.info(`Succeeded in uninstalling user certificate`);
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall user certificate. Code is ${err.code}, message is ${err.message}`);
});
```

## deviceSettings.setPowerPolicy<sup>11+</sup>

setPowerPolicy(admin: Want, powerScene: PowerScene, powerPolicy: PowerPolicy): void

设置电源策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| powerScene | [PowerScene](#powerscene11) | 是    | 电源策略场景，当前只支持超时场景。       |
| powerPolicy | [PowerPolicy](#powerpolicy11) | 是    | 电源策略。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
  let delayTime = 0;
  let powerScene: deviceSettings.PowerScene = deviceSettings.PowerScene.TIME_OUT;
  let powerPolicyAction: deviceSettings.PowerPolicyAction = deviceSettings.PowerPolicyAction.AUTO_SUSPEND;
  let powerPolicy: deviceSettings.PowerPolicy = {powerPolicyAction, delayTime};
  deviceSettings.setPowerPolicy(wantTemp, powerScene, powerPolicy);
  console.info(`Succeeded in setting power polilcy`);
} catch (err) {
  console.error(`Failed to set power policy. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getPowerPolicy<sup>11+</sup>

getPowerPolicy(admin: Want, powerScene: PowerScene): PowerPolicy

获取电源策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| powerScene | [PowerScene](#powerscene11) | 是    | 电源策略场景，当前只支持超时场景。       |

**返回值：**

| 类型   | 说明        |
| ----- | --------------------------------- |
| [PowerPolicy](#powerpolicy11) | 电源策略。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
  let powerScene: deviceSettings.PowerScene = deviceSettings.PowerScene.TIME_OUT;
  let powerPolicy: deviceSettings.PowerPolicy = deviceSettings.getPowerPolicy(wantTemp, powerScene);
  console.info(`Succeeded in getting power policy ${JSON.stringify(powerPolicy)}`);
} catch (err) {
  console.error(`Failed to get power policy. Code: ${err.code}, message: ${err.message}`);
}
```

## PowerPolicy<sup>11+</sup>

电源策略。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统接口：** 此接口为系统接口。

| 名称         | 类型     | 只读 | 可选 | 说明                            |
| ----------- | --------| ----- | ---- | ------------------------------- |
| powerPolicyAction | [PowerPolicyAction](#powerpolicyaction11) | 否 | 否 | 执行电源策略的动作。 |
| delayTime | number | 否 | 否 | 延迟时间（单位：毫秒）。|

## PowerScene<sup>11+</sup>

执行电源策略的场景。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统接口：** 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| TIME_OUT | 0 | 超时场景。 |

## PowerPolicyAction<sup>11+</sup>

执行电源策略的动作。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统接口：** 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NONE | 0 | 不执行动作。 |
| AUTO_SUSPEND | 1 | 自动进入睡眠。 |
| FORCE_SUSPEND | 2 | 强制进入睡眠。 |
| HIBERNATE | 3 | 进入休眠。（当前电源子系统暂不支持） |
| SHUTDOWN | 4 | 关机。 |
