# @ohos.security.certManagerDialog (Certificate Management Dialog Box)

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

The **certificateManagerDialog** module provides APIs for opening the certificate management pages, on which the certificates are installed, stored, used, and destroyed.

> **NOTE**
>
> The initial APIs of this module are supported since API version 13. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import certificateManagerDialog from '@ohos.security.certManagerDialog';
```

## CertificateDialogPageType

Enumerates the page types of the certificate management dialog box.

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Model restriction**: This API can be used only in the stage model.

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| PAGE_MAIN | 1      | Main page of the Certificate Manager application.|
| PAGE_CA_CERTIFICATE | 2      | CA certificate list page.|
| PAGE_CREDENTIAL | 3      | Credential list page.|
| PAGE_INSTALL_CERTIFICATE | 4      | Certificate installation page.|

## CertificateType<sup>14+</sup>

Enumerates the types of the certificate to be installed.

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Model restriction**: This API can be used only in the stage model.

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| CA_CERT | 1      | CA certificate.|

## CertificateScope<sup>14+</sup>

Defines the usage scope of the certificate to be installed.

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Model restriction**: This API can be used only in the stage model.

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| NOT_SPECIFIED<sup>18+</sup>  | 0      | No user is specified.|
| CURRENT_USER | 1      | The installed certificate is accessible only to the current user.|
| GLOBAL_USER<sup>18+</sup> | 2      | The installed certificate is accessible to all users.|


## CertificateDialogErrorCode

Enumerates the error codes reported when the certificate management dialog box APIs are called.

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Model restriction**: This API can be used only in the stage model.

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| ERROR_GENERIC  | 29700001      | Internal error.|
| ERROR_OPERATION_CANCELED<sup>14+</sup>  | 29700002      | The user canceled the operation when the API is called.|
| ERROR_OPERATION_FAILED<sup>14+</sup>  | 29700003      | The certificate installation fails.|
| ERROR_DEVICE_NOT_SUPPORTED<sup>14+</sup>  | 29700004      | The device does not support the API called.|
| ERROR_NOT_COMPLY_SECURITY_POLICY<sup>18+</sup>  | 29700005      | The device security policy is not met when the API is called.|

## CertificateDialogProperty<sup>18+</sup>

Defines the property of the certificate management dialog box.

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Model restriction**: This API can be used only in the stage model.

| Name             | Type   | Read-Only| Optional| Description                        |
| ----------------- | ------- | ---- | ---- | ---------------------------- |
| showInstallButton | boolean | No  | No  | Whether to display the button for installing the certificate. The value **true** means to display the button; the value **false** means the opposite.|

## certificateManagerDialog.openCertificateManagerDialog

openCertificateManagerDialog(context: common.Context, pageType: CertificateDialogPageType): Promise\<void>

Opens the certificate management dialog box and displays the page of the specified type. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md)                   | Yes  | Context of the application.|
| pageType | [CertificateDialogPageType](#certificatedialogpagetype)                   | Yes  | Type of the page to display.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Certificate Management Dialog Box Error Codes](errorcode-certManagerDialog.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error.     |

**Example**
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context is application context information, which is obtained by the caller. The context here is only an example. */
let context: common.Context = new UIContext().getHostContext() as common.Context;
/* pageType specifies the type of the page to display. In this example, pageType is PAGE_MAIN, which indicates the main page of the Certificate Management application. */
let pageType: certificateManagerDialog.CertificateDialogPageType = certificateManagerDialog.CertificateDialogPageType.PAGE_MAIN;
try {
  certificateManagerDialog.openCertificateManagerDialog(context, pageType).then(() => {
    console.info('Succeeded in opening certificate manager dialog.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to open certificate manager dialog. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to open certificate manager dialog. Code: ${error.code}, message: ${error.message}`);
}
```
## certificateManagerDialog.openInstallCertificateDialog<sup>14+</sup>

openInstallCertificateDialog(context: common.Context, certType: CertificateType, certScope: CertificateScope, cert: Uint8Array): Promise\<string>

Opens a dialog box for installing a certificate. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Device support**: This API is available on PCs/2-in-1 devices. For other devices, error code 29700004 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md)                   | Yes  | Context of the application.|
| certType | [CertificateType](#certificatetype14)                   | Yes  | Type of the certificate to install.|
| certScope | [CertificateScope](#certificatescope14)                   | Yes  | Defines the usage scope of the certificate to be installed.|
| cert | Uint8Array                  | Yes  | Data of the certificate to install.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<string> | Promise used to return the certificate URI. The value contains up to 256 bytes.|

**Error codes**

For details about the error codes, see [Certificate Management Dialog Box Error Codes](errorcode-certManagerDialog.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error.     |
| 29700002 | The user cancels the installation operation.     |
| 29700003 | The user install certificate failed in the certificate manager dialog, such as the certificate is in an invalid format.     |
| 29700004 | The API is not supported on this device.     |
| 29700005<sup>18+</sup> | The operation does not comply with the device security policy, such as the device does not allow users to manage the ca certificate of the global user.     |

**Example**
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context is application context information, which is obtained by the caller. The context here is only an example. */
let context: common.Context = new UIContext().getHostContext() as common.Context;
/* certificateType specifies the certificate type. The value CA_CERT here indicates a CA certificate. */
let certificateType: certificateManagerDialog.CertificateType = certificateManagerDialog.CertificateType.CA_CERT;
/* certificateScope specifies the usage scope of the certificate. The value CURRENT_USER here means the certificate can be used by the current user. */
let certificateScope: certificateManagerDialog.CertificateScope = certificateManagerDialog.CertificateScope.CURRENT_USER;
/* The CA certificate data must be assigned by the service. In this example, the data is not CA certificate data. */
let caCert: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
try {
  certificateManagerDialog.openInstallCertificateDialog(context, certificateType, certificateScope, caCert).then((uri: string) => {
    console.info('Succeeded opening install certificate');
  }).catch((err: BusinessError) => {
    console.error(`Failed to open install certificate dialog. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to open install certificate dialog. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManagerDialog.openUninstallCertificateDialog<sup>18+</sup>

openUninstallCertificateDialog(context: common.Context, certType: CertificateType, certUri: string): Promise\<void>

Opens a dialog box for deleting a certificate. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Device support**: This API is available on PCs/2-in-1 devices. For other devices, error code 29700004 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md)                   | Yes  | Context of the application.|
| certType | [CertificateType](#certificatetype14)                   | Yes  | Type of the certificate to delete.|
| certUri | string                  | Yes  | Unique identifier of the certificate to delete. The value contains up to 256 bytes.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Certificate Management Dialog Box Error Codes](errorcode-certManagerDialog.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error.     |
| 29700002 | The user cancels the uninstallation operation.     |
| 29700003 | The user uninstall certificate failed in the certificate manager dialog, such as the certificate uri is not exist.     |
| 29700004 | The API is not supported on this device.     |
| 29700005 | The operation does not comply with the device security policy, such as the device does not allow users to manage the ca certificate of the global user.     |

**Example**
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context is application context information, which is obtained by the caller. The context here is only an example. */
let context: common.Context = new UIContext().getHostContext() as common.Context;
/* certificateType specifies the certificate type. The value CA_CERT here indicates a CA certificate. */
let certificateType: certificateManagerDialog.CertificateType = certificateManagerDialog.CertificateType.CA_CERT;
/* certUri is the unique identifier of the certificate installed. The value here is only an example. */
let certUri: string = "test";
try {
  certificateManagerDialog.openUninstallCertificateDialog(context, certificateType, certUri).then(() => {
    console.info('Succeeded opening uninstall certificate');
  }).catch((err: BusinessError) => {
    console.error(`Failed to open uninstall certificate dialog. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to open uninstall certificate dialog. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManagerDialog.openCertificateDetailDialog<sup>18+</sup>

openCertificateDetailDialog(context: common.Context, cert: Uint8Array, property: CertificateDialogProperty): Promise\<void>

Opens the certificate management dialog box and displays the certificate details. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Device support**: This API is available on PCs/2-in-1 devices. For other devices, error code 29700004 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md)                   | Yes  | Context of the application.|
| cert     | Uint8Array                                                   | Yes  | Data of the certificate to install.            |
| property | [CertificateDialogProperty](#certificatedialogproperty18) | Yes  | Property of the certificate management dialog box.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Certificate Management Dialog Box Error Codes](errorcode-certManagerDialog.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error.                                              |
| 29700003 | Show the certificate detail dialog fail, such as the certificate is in an invalid format. |
| 29700004 | The API is not supported on this device.                     |

**Example**
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context is application context information, which is obtained by the caller. The context here is only an example. */
let context: common.Context = new UIContext().getHostContext() as common.Context;
/* The CA certificate data must be assigned by the service. In this example, the data is not CA certificate data. */
let caCert: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
let property: certificateManagerDialog.CertificateDialogProperty = {
  showInstallButton: false /* Do not display the button for installing the certificate.*/
};
try {
  certificateManagerDialog.openCertificateDetailDialog(context, caCert, property).then(() => {
    console.info('Succeeded opening certificate detail dialog.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to open certificate detail dialog. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to open certificate detail dialog. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManagerDialog.openAuthorizeDialog<sup>20+</sup>

openAuthorizeDialog(context: common.Context): Promise\<string>

Opens the authorization page of the certificate management dialog box to grant a certificate to the application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Model restriction**: This API can be used only in the stage model.

| Name    | Type                                                                | Mandatory| Description         |
|---------|--------------------------------------------------------------------|----|-------------|
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md) | Yes | Context of the application.|

**Return value**

| Type              | Description                                  |
|------------------|--------------------------------------|
| Promise\<string> | Promise used to return the URI of the certificate authorized. The value contains up to 256 bytes.|

**Error codes**

For details about the error codes, see [Certificate Management Dialog Box Error Codes](errorcode-certManagerDialog.md).

| ID   | Error Message                                                                                                                                           |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201      | Permission verification failed. The application does not have the permission required to call the API.                                          |
| 401      | Invalid parameter. Possible causes: 1. A mandatory parameter is left unspecified. 2. Incorrect parameter type. 3. Parameter verification failed. |
| 29700001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error.                                                                                                                                 |
| 29700002 | The user cancels the authorization.                                                                                                             |

**Example**
```ts
import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

/* context is application context information, which is obtained by the caller. The context here is only an example. */
let context: common.Context = new UIContext().getHostContext() as common.Context;
try {
    certificateManagerDialog.openAuthorizeDialog(context).then((uri: string) => {
        console.info(`Success to authorize certificate, uri: ${uri}`)
    }).catch((err: BusinessError) => {
        console.error(`Failed to authorize certificate. Code: ${err.code}, message: ${err.message}`);
    });
} catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to authorize certificate. Code: ${error.code}, message: ${error.message}`);
}
```
