# @ohos.enterprise.deviceSettings (设备设置管理)

本模块提供企业设备设置能力，包括获取设备息屏时间等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后调用，实现相应功能。

## 导入模块

```ts
import deviceSettings from '@ohos.enterprise.deviceSettings';
```

## deviceSettings.getScreenOffTime

getScreenOffTime(admin: Want, callback: AsyncCallback&lt;number&gt;): void

指定设备管理应用获取设备息屏时间，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| callback | AsyncCallback&lt;number&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为设备息屏时间（单位：毫秒），否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
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

指定设备管理应用获取设备息屏时间，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_SETTINGS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise对象，返回设备息屏时间（单位：毫秒）。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

deviceSettings.getScreenOffTime(wantTemp).then((result) => {
  console.info(`Succeeded in getting screen off time, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
});
```

## deviceSettings.installUserCertificate

installUserCertificate(admin: Want, certificate: CertBlob, callback: AsyncCallback&lt;string&gt;): void

指定设备管理应用安装用户证书，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| certificate    | [CertBlob](#certblob)     | 是    | 证书信息。                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。      |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |
| 9201001 | manage certificate failed |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let certFileArray: Uint8Array = new Uint8Array();
// The variable context needs to be initialized in MainAbility's onCreate callback function
// test.cer needs to be placed in the rawfile directory
getContext().resourceManager.getRawFileContent("test.cer").then((value) => {
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
  return
});
```

## deviceSettings.installUserCertificate

installUserCertificate(admin: Want, certificate: CertBlob): Promise&lt;string&gt;

指定设备管理应用安装用户证书，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| certificate    | [CertBlob](#certblob)     | 是    | 证书信息。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise对象，返回当前证书安装后的uri，用于卸载证书。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |
| 9201001 | manage certificate failed |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let certFileArray: Uint8Array = new Uint8Array();
// The variable context needs to be initialized in MainAbility's onCreate callback function
// test.cer needs to be placed in the rawfile directory
getContext().resourceManager.getRawFileContent("test.cer").then((value) => {
  certFileArray = value
  deviceSettings.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" })
    .then((result) => {
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);
    }).catch((err: BusinessError) => {
    console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to get row file content. message: ${error.message}`);
  return
});
```

## CertBlob

证书信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称         | 类型     | 必填 | 说明                            |
| ----------- | --------| ----- | ------------------------------- |
| inData | Uint8Array | 是 | 证书的二进制内容。 |
| alias | string | 是 | 证书别名。 |

## deviceSettings.uninstallUserCertificate

uninstallUserCertificate(admin: Want, certUri: string, callback: AsyncCallback&lt;void&gt;): void

指定设备管理应用卸载用户证书，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| certUri    | string    | 是    | 证书uri，由安装用户证书接口返回。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。      |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |
| 9201001 | manage certificate failed |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let aliasStr = "certName"
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

指定设备管理应用卸载用户证书，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| certUri    | string     | 是    | 证书uri，由安装用户证书接口返回。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理应用卸载用户证书失败时会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |
| 9201001 | manage certificate failed |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let aliasStr = "certName"
deviceSettings.uninstallUserCertificate(wantTemp, aliasStr).then(() => {
  console.info(`Succeeded in uninstalling user certificate`);
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall user certificate. Code is ${err.code}, message is ${err.message}`);
});
```