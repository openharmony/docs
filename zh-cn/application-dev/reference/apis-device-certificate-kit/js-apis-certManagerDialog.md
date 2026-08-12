# @ohos.security.certManagerDialog (证书管理对话框模块)

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

证书管理对话框主要提供打开证书管理界面的能力，用户在打开的证书管理对话框可对证书进行查看和管理（安装、卸载、授权）。

> **说明：**
>
> 本模块首批接口从API version 13开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
```

## CertificateDialogPageType

表示证书管理对话框的页面类型。

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| PAGE_MAIN | 1      | 证书管理应用主页面。 |
| PAGE_CA_CERTIFICATE | 2      | CA证书列表页面。 |
| PAGE_CREDENTIAL | 3      | 凭据列表页面。 |
| PAGE_INSTALL_CERTIFICATE | 4      | 安装证书页面。 |

## CertificateType<sup>14+</sup>

表示安装证书的类型。

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| CA_CERT | 1      | CA证书。 |
| CREDENTIAL_USER<sup>22+</sup> | 2      | 用户公共凭据。 |
| CREDENTIAL_APP<sup>22+</sup> | 3      | 应用私有凭据。 |
| CREDENTIAL_UKEY<sup>22+</sup> | 4      | USB Key证书凭据。 |
| CREDENTIAL_SYSTEM<sup>23+</sup> | 5      | 系统凭据。 |

## CertificateScope<sup>14+</sup>

表示安装证书的使用范围。

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| NOT_SPECIFIED<sup>18+</sup>  | 0      | 不指定使用范围。 |
| CURRENT_USER | 1      | 当前用户。表示证书仅对当前登录用户可用。 |
| GLOBAL_USER<sup>18+</sup> | 2      | 所有用户。表示证书对设备的所有用户可见。 |


## CertificateDialogErrorCode

表示调用证书管理对话框相关API的错误码。

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| ERROR_GENERIC  | 29700001      | 表示调用接口时发生内部错误。<br>例如IPC通信失败、内存操作失败、文件操作失败。 |
| ERROR_OPERATION_CANCELED<sup>14+</sup>  | 29700002      | 表示用户在证书管理对话框中取消操作。 |  
| ERROR_OPERATION_FAILED<sup>14+</sup>  | 29700003      | 表示用户在证书管理对话框中操作失败。<br>例如安装证书失败。 |
| ERROR_DEVICE_NOT_SUPPORTED<sup>14+</sup>  | 29700004      | 表示接口不支持该设备。 |
| ERROR_NOT_COMPLY_SECURITY_POLICY<sup>18+</sup>  | 29700005      | 表示该操作不符合设备安全策略。<br>例如设备不允许用户管理GLOBAL_USER的CA证书。 |
| ERROR_PARAMETER_VALIDATION_FAILED<sup>22+</sup>  | 29700006      | 表示输入参数校验失败。<br>例如参数格式不正确或取值范围无效。 |
| ERROR_NO_AVAILABLE_CERTIFICATE<sup>22+</sup>  | 29700007      | 表示没有可用证书。 |

## CertificateDialogProperty<sup>18+</sup>

表示证书管理对话框的属性。

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称              | 类型    | 只读 | 可选 | 说明                         |
| ----------------- | ------- | ---- | ---- | ---------------------------- |
| showInstallButton | boolean | 否   | 否   | 表示是否显示安装证书的按钮，true为显示，false为不显示。 |

## CertReference<sup>22+</sup>

表示证书凭据的引用信息。

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称              | 类型    | 只读 | 可选 | 说明                         |
| ----------------- | ------- | ---- | ---- | ---------------------------- |
| certType | [CertificateType](#certificatetype14)   | 否   | 否   | 表示证书类型。 |
| keyUri | string   | 否   | 否   | 表示证书凭据的唯一标识符，长度限制256字节以内。 |

## UkeyAuthRequest<sup>22+</sup>

USB Key PIN码认证请求。

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称              | 类型    | 只读 | 可选 | 说明                         |
| ----------------- | ------- | ---- | ---- | ---------------------------- |
| keyUri | string   | 否   | 否   | 表示USB Key证书凭据的唯一标识符，长度限制256字节以内。该参数值可通过调用[openAuthorizeDialog](#certificatemanagerdialogopenauthorizedialog22)接口返回的CertReference中获取。 |

## AuthorizeRequest<sup>22+</sup>

证书凭据授权请求信息。

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称              | 类型    | 只读 | 可选 | 说明                         |
| ----------------- | ------- | ---- | ---- | ---------------------------- |
| certTypes | Array<[CertificateType](#certificatetype14)>   | 否   | 否   | 表示证书类型的列表。 |
| certPurpose | [certificateManager.CertificatePurpose](js-apis-certManager.md#certificatepurpose22)    | 否   | 是   | 表示证书用途。<br>若certTypes参数中存在CertificateType.CREDENTIAL_UKEY类型，则certPurpose参数生效，表示根据指定的证书用途筛选USB Key的证书凭据。 |
| keyAlgIDs |  Array\<string>  | 否   | 是   | 表示证书公钥的算法类型，用于筛选凭据授权对话框中的证书列表，仅显示匹配的证书。支持的取值为RSA、EC或ECDSA（区分大小写）。若不传此参数，则不按算法类型筛选证书。<br>若 keyAlgIDs包含不支持的算法，则该筛选器无效。<br>数组最大长度为20。<br>**起始版本：** 26.0.0 |
| issuers |  Array\<Uint8Array>  | 否   | 是   | 表示以DER格式编码的证书颁发者，用于筛选凭据授权对话框中的证书列表，仅显示匹配的证书。<br>如果issuers数组中存在长度为0的元素，则issuers筛选器不会生效。<br>数组最大长度为20。<br>**起始版本：** 26.0.0 |
| uri | string  | 否   | 是   | 该URI在授权对话框中进行显示，用于为用户提供更多有关申请授权使用证书凭据的上下文。<br>**起始版本：** 26.0.0 |

## certificateManagerDialog.openCertificateManagerDialog

openCertificateManagerDialog(context: common.Context, pageType: CertificateDialogPageType): Promise\<void>

打开证书管理对话框，显示相应的页面。调用成功后，用户可以在弹出的对话框中对证书进行查看、安装、卸载等操作。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context)                   | 是   | 表示应用的上下文信息。 |
| pageType | [CertificateDialogPageType](#certificatedialogpagetype)                   | 是   | 表示页面类型。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理对话框错误码](errorcode-certManagerDialog.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again.    |

**示例**：
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context为应用的上下文信息，调用方自行获取，此处仅为示例 */
let context: common.Context = new UIContext().getHostContext() as common.Context;
/* pageType为页面类型，此处赋值PAGE_MAIN，即拉起证书管理主界面 */
let pageType: certificateManagerDialog.CertificateDialogPageType = certificateManagerDialog.CertificateDialogPageType.PAGE_MAIN;
try {
  certificateManagerDialog.openCertificateManagerDialog(context, pageType).then(() => {
    console.info('Succeeded in opening certificate manager dialog.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to open certificate manager dialog. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  console.error(`Failed to open certificate manager dialog. Code: ${error.code}, message: ${error.message}`);
}
```
## certificateManagerDialog.openInstallCertificateDialog<sup>14+</sup>

openInstallCertificateDialog(context: common.Context, certType: CertificateType, certScope: CertificateScope, cert: Uint8Array): Promise\<string>

打开证书管理安装证书向导，显示相应的页面。证书安装成功后，返回证书的唯一标识符，应用可通过该标识符对证书进行使用。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**设备行为差异：**
1. 入参certType为CA_CERT时，该接口在PC/2in1设备中可以正常调用，在其他设备中会返回29700004错误码。从API版本26.0.0开始，可以通过[supportsCACertDialog](#certificatemanagerdialogsupportscacertdialog)来判断本设备是否支持打开CA证书安装对话框。
2. 入参certType为CREDENTIAL_USER或CREDENTIAL_SYSTEM时，在PC/2in1、phone和tablet设备中可以正常调用。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context)                   | 是   | 表示应用的上下文信息。 |
| certType | [CertificateType](#certificatetype14)                   | 是   | 表示安装证书类型，目前仅支持CA_CERT、CREDENTIAL_USER、CREDENTIAL_SYSTEM。 |
| certScope | [CertificateScope](#certificatescope14)                   | 是   | 表示安装证书的使用范围，目前仅支持CURRENT_USER、NOT_SPECIFIED。 |
| cert | Uint8Array                  | 是   | 表示证书数据，大小不超过8KB。<br>当certType为CA_CERT，应为PEM或DER编码格式的证书数据。<br>当certType为CREDENTIAL_USER或CREDENTIAL_SYSTEM，应为P12编码格式的证书凭据数据。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<string> | Promise对象。表示返回证书uri的结果，最大长度为256字节。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理对话框错误码](errorcode-certManagerDialog.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | The certificate management application Hap is not preinstalled in the system, and the capability is not supported.<br>适用版本：26.0.0+ |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again.     |
| 29700002 | The user cancels the installation operation.     |
| 29700003 | The user install certificate failed in the certificate manager dialog, such as the certificate is in an invalid format.     |
| 29700004 | For security purposes, the current device does not support this API. You can use the [supportsCACertDialog](#certificatemanagerdialogsupportscacertdialog) to determine whether the device supports opening the dialog box for installing a CA certificate with certType set to CA. |
| 29700005 | The operation does not comply with the device security policy, such as the device does not allow users to manage the CA certificate of the global user.<br>适用版本：18+ |

**示例**：
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context为应用的上下文信息，调用方自行获取，此处仅为示例 */
let context: common.Context = new UIContext().getHostContext() as common.Context;
/* certificateType为证书类型，此处赋值CA_CERT，即安装CA证书 */
let certificateType: certificateManagerDialog.CertificateType = certificateManagerDialog.CertificateType.CA_CERT;
/* certificateScope为证书使用范围，此处赋值CURRENT_USER，即当前用户下可用 */
let certificateScope: certificateManagerDialog.CertificateScope = certificateManagerDialog.CertificateScope.CURRENT_USER;
/* 安装的CA证书数据需要业务赋值，本例数据非CA证书数据 */
let caCert: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01
]);
try {
  certificateManagerDialog.openInstallCertificateDialog(context, certificateType, certificateScope, caCert).then((uri: string) => {
    console.info('Succeeded in opening install certificate');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to open install certificate dialog. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  console.error(`Failed to open install certificate dialog. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManagerDialog.openUninstallCertificateDialog<sup>18+</sup>

openUninstallCertificateDialog(context: common.Context, certType: CertificateType, certUri: string): Promise\<void>

打开证书管理卸载证书向导，显示相应的页面。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**设备行为差异：** 该接口在PC/2in1设备可正常调用，在其他设备中返回29700004错误码。从API版本26.0.0开始，可以通过[supportsCACertDialog](#certificatemanagerdialogsupportscacertdialog)来判断是否支持打开CA证书卸载对话框。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context)                   | 是   | 表示应用的上下文信息。 |
| certType | [CertificateType](#certificatetype14)                   | 是   | 表示待卸载证书类型，目前仅支持CA_CERT。 |
| certUri | string                  | 是   | 表示待卸载证书的唯一标识符，可通过安装CA证书接口或查询CA证书列表接口获取。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理对话框错误码](errorcode-certManagerDialog.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again.     |
| 29700002 | The user cancels the uninstallation operation.     |
| 29700003 | The user uninstall certificate failed in the certificate manager dialog, such as the certificate uri is not exist.     |
| 29700004 | For security purposes, the current device does not support this API. You can use the [supportsCACertDialog](#certificatemanagerdialogsupportscacertdialog) to determine whether the device can open the dialog box for deleting a CA certificate with certType set to CA.     |
| 29700005 | The operation does not comply with the device security policy, such as the device does not allow users to manage the CA certificate of the global user.     |

**示例**：
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context为应用的上下文信息，调用方自行获取，此处仅为示例 */
let context: common.Context = new UIContext().getHostContext() as common.Context;
/* certificateType为证书类型，此处赋值CA_CERT，即删除CA证书 */
let certificateType: certificateManagerDialog.CertificateType = certificateManagerDialog.CertificateType.CA_CERT;
/* certUri为业务安装证书返回的唯一标识符，此处仅为示例 */
let certUri: string = "test";
try {
  certificateManagerDialog.openUninstallCertificateDialog(context, certificateType, certUri).then(() => {
    console.info('Succeeded in opening uninstall certificate');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to open uninstall certificate dialog. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  console.error(`Failed to open uninstall certificate dialog. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManagerDialog.openCertificateDetailDialog<sup>18+</sup>

openCertificateDetailDialog(context: common.Context, cert: Uint8Array, property: CertificateDialogProperty): Promise\<void>

打开证书管理对话框显示证书的详情。调用成功后，将显示证书的基本信息、有效期、颁发者、使用者等详细信息。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**设备行为差异：** 该接口在PC/2in1设备可正常调用，在其他设备中返回29700004错误码。从API版本26.0.0开始，可以通过[supportsCACertDialog](#certificatemanagerdialogsupportscacertdialog)来判断是否支持打开CA证书详情对话框。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context)                   | 是   | 表示应用的上下文信息。 |
| cert     | Uint8Array                                                   | 是   | 表示证书数据。             |
| property | [CertificateDialogProperty](#certificatedialogproperty18) | 是   | 表示打开证书管理对话框的属性。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理对话框错误码](errorcode-certManagerDialog.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again.                |
| 29700003 | Show the certificate detail dialog failed, such as the certificate is in an invalid format. |
| 29700004 | The API is not supported on this device.                     |

**示例**：
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context为应用的上下文信息，调用方自行获取，此处仅为示例 */
let context: common.Context = new UIContext().getHostContext() as common.Context;
/* 安装的CA证书数据需要业务赋值，本例数据非CA证书数据 */
let caCert: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01
]);
let property: certificateManagerDialog.CertificateDialogProperty = {
  showInstallButton: false /* 不显示安装按钮 */
};
try {
  certificateManagerDialog.openCertificateDetailDialog(context, caCert, property).then(() => {
    console.info('Succeeded opening certificate detail dialog.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to open certificate detail dialog. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  console.error(`Failed to open certificate detail dialog. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManagerDialog.openAuthorizeDialog<sup>20+</sup>

openAuthorizeDialog(context: common.Context): Promise\<string>

打开证书管理对话框的证书凭据授权页面。在弹出的页面中，用户可以为应用授权使用证书凭据。调用成功后，应用可通过接口返回的授权证书凭据uri进行签名、验签和查询详情操作。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名     | 类型                                                                 | 必填 | 说明          |
|---------|--------------------------------------------------------------------|----|-------------|
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context) | 是  | 表示应用的上下文信息。 |

**返回值**：

| 类型               | 说明                                   |
|------------------|--------------------------------------|
| Promise\<string> | Promise对象。表示返回授权证书uri的结果，最大长度为256字节。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理对话框错误码](errorcode-certManagerDialog.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201      | Permission verification failed. The application does not have the permission required to call the API.                                          |
| 401      | Parameter error. Possible causes: 1. A mandatory parameter is left unspecified. 2. Incorrect parameter type. 3. Parameter verification failed. |
| 801      | The certificate management application Hap is not preinstalled in the system, and the capability is not supported.<br>适用版本：26.0.0+ |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again.        |
| 29700002 | The user cancels the authorization.                                                                                                             |

**示例**：
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context为应用的上下文信息，调用方自行获取，此处仅为示例 */
let context: common.Context = new UIContext().getHostContext() as common.Context;
try {
  /* 打开证书管理对话框的证书凭据授权页面。 */
  certificateManagerDialog.openAuthorizeDialog(context).then((uri: string) => {
    console.info(`Succeeded in authorizing certificate, uri: ${uri}`);
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to authorize certificate. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to authorize certificate. Code: ${error.code}, message: ${error.message}`);
}
```
## certificateManagerDialog.openAuthorizeDialog<sup>22+</sup>

openAuthorizeDialog(context: common.Context, authorizeRequest: AuthorizeRequest): Promise\<CertReference>

打开证书管理对话框的证书凭据授权页面。在弹出的页面中，用户可以为应用授权使用证书凭据。调用成功后，应用可通过接口返回的授权证书凭据uri进行签名、验签和查询详情操作。可授权的证书类型包括应用证书凭据、用户证书凭据和USB Key证书凭据。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**设备行为差异：**
- 从API版本26.0.0开始，该接口在所有设备上无行为差异。
- 在API版本22-24，当authorizeRequest.certTypes数组只包含CREDENTIAL_UKEY取值时，在PC/2in1设备可正常调用，在其他设备返回801错误码。当authorizeRequest.certTypes数组包含CREDENTIAL_UKEY和其他凭据类型时，在PC/2in1设备可正常调用，在其他设备上会忽略CREDENTIAL_UKEY类型的凭据。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名     | 类型                                                                 | 必填 | 说明          |
|---------|--------------------------------------------------------------------|----|-------------|
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context) | 是  | 表示应用的上下文信息。 |
| authorizeRequest | [AuthorizeRequest](#authorizerequest22) | 是  | 表示授权请求信息。 |

**返回值**：

| 类型               | 说明                                   |
|------------------|--------------------------------------|
| Promise\<[CertReference](#certreference22)> | Promise对象，返回授权证书引用的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理对话框错误码](errorcode-certManagerDialog.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201      | Permission verification failed. The application does not have the permission required to call the API.                                          |
| 801      | Capability not supported.  |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error; 4. Call other service failed. Please try again.                 |
| 29700002 | The user cancels the authorization.                                                                                                             |
| 29700006 | Indicates that the input parameters validation failed. for example, the parameter format is incorrect or the value range is invalid.            |
| 29700007 | No available certificate for authorization. Possible causes: 1. No certificate matches the filter criteria; 2. All certificates have been deleted.            |

**示例**：
```ts
import { certificateManagerDialog, certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context为应用的上下文信息，调用方自行获取，此处仅为示例 */
let context: common.Context = new UIContext().getHostContext() as common.Context;
let certTypes: Array<certificateManagerDialog.CertificateType> = [
  certificateManagerDialog.CertificateType.CREDENTIAL_USER,
  certificateManagerDialog.CertificateType.CREDENTIAL_APP,
  certificateManagerDialog.CertificateType.CREDENTIAL_UKEY
];
let certPurpose: certificateManager.CertificatePurpose = certificateManager.CertificatePurpose.PURPOSE_DEFAULT;
let authorizeRequest: certificateManagerDialog.AuthorizeRequest = { certTypes: certTypes, certPurpose: certPurpose };
try {
  certificateManagerDialog.openAuthorizeDialog(context, authorizeRequest).then((certReference: certificateManagerDialog.CertReference) => {
    let reference = certReference;
    console.info(`Succeeded in opening authorize dialog.`);
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to open authorize dialog. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to open authorize dialog. Code: ${error.code}, message: ${error.message}`);
}
```
## certificateManagerDialog.openUkeyAuthDialog<sup>22+</sup>

openUkeyAuthDialog(context: common.Context, ukeyAuthRequest: UkeyAuthRequest): Promise\<void>

打开证书管理对话框的USB Key证书凭据PIN码认证页面。在弹出的页面中，用户可以输入PIN码授权USB Key证书凭据。调用成功后，USB Key证书凭据将被解锁，应用可使用该凭据进行签名、加密等操作。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**设备行为差异：**
- 从API版本26.0.0开始，该接口在所有设备上无行为差异。
- 在API版本22-24，该接口在PC/2in1设备可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名     | 类型                                                                 | 必填 | 说明          |
|---------|--------------------------------------------------------------------|----|-------------|
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context) | 是  | 表示应用的上下文信息。 |
| ukeyAuthRequest | [UkeyAuthRequest](#ukeyauthrequest22) | 是  | 表示USB Key证书凭据授权请求信息。 |

**返回值**：

| 类型               | 说明                                   |
|------------------|--------------------------------------|
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理对话框错误码](errorcode-certManagerDialog.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201      | Permission verification failed. The application does not have the permission required to call the API.                                          |
| 801      | Capability not supported.  |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again.           |
| 29700002 | The user cancels the authentication operation.                                                                                                             |
| 29700003 | The authentication operation failed, such as the USB key certificate does not exist, the USB key status is abnormal.                              |
| 29700006 | Indicates that the input parameters validation failed. For example, the parameter format is incorrect or the value range is invalid.            |

**示例**：
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context为应用的上下文信息，调用方自行获取，此处仅为示例 */
let context: common.Context = new UIContext().getHostContext() as common.Context;
/* keyUri为证书凭据的唯一标识符，调用方自行获取，此处仅为示例 */
let keyUri: string = "test";
let ukeyAuthRequest: certificateManagerDialog.UkeyAuthRequest = { keyUri: keyUri };
try {
  certificateManagerDialog.openUkeyAuthDialog(context, ukeyAuthRequest).then(() => {
    console.info(`Succeeded in opening ukey authorization dialog`);
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to open ukey authorization dialog. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to open ukey authorization dialog. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManagerDialog.supportsCACertDialog

supportsCACertDialog(): boolean

判断设备是否支持打开CA证书管理对话框的特性，包括[openInstallCertificateDialog](#certificatemanagerdialogopeninstallcertificatedialog14)、[openUninstallCertificateDialog](#certificatemanagerdialogopenuninstallcertificatedialog18)、[openCertificateDetailDialog](#certificatemanagerdialogopencertificatedetaildialog18)方法。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Security.CertificateManagerDialog

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值**：

| 类型               | 说明                                   |
|------------------|--------------------------------------|
| boolean | 设备是否支持打开CA证书管理对话框。true：支持，false：不支持。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理对话框错误码](errorcode-certManagerDialog.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again.           |

**示例**：
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  /* 判断设备是否支持打开CA证书管理对话框。 */
  let isSupport: boolean = certificateManagerDialog.supportsCACertDialog();
  console.info(`Succeeded in checking whether the device supports CA dialog.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to check whether the device supports CA dialog. Code: ${error.code}, message: ${error.message}`);
}
```