# @ohos.security.certManagerDialog (Certificate Management Dialog Box)

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
| NOT_SPECIFIED<sup>16+</sup>  | 0      | No user is specified.|
| CURRENT_USER | 1      | The installed certificate is accessible only to the current user.|
| GLOBAL_USER<sup>16+</sup> | 2      | The installed certificate is accessible to all users.|


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
| 29700001 | Internal error.     |

**Example**
```ts
import certificateManagerDialog from '@ohos.security.certManagerDialog';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

/* context is application context information, which is obtained by the caller. The context here is only an example. */
let context: common.Context = getContext(this);
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

This API is available only to 2-in-1 devices.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md)                   | Yes  | Context of the application.|
| certType | [CertificateType](#certificatetype14)                   | Yes  | Type of the certificate to install.|
| certScope | [CertificateScope](#certificatescope14)                   | Yes  | Usage scope of the certificate.|
| cert | Uint8Array                  | Yes  | Data of the certificate to install.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<string> | Promise used to return the certificate URI.|

**Error codes**

For details about the error codes, see [Certificate Management Dialog Box Error Codes](errorcode-certManagerDialog.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 29700001 | Internal error.     |
| 29700002 | The user cancels the installation operation.     |
| 29700003 | The user install certificate failed in the certificate manager dialog, such as the certificate is in an invalid format.     |
| 29700004 | The API is not supported on this device.     |
| 29700005<sup>16+</sup> | The operation does not comply with the device security policy, such as the device does not allow users to manage the ca certificate of the global user.     |

**Example**
```ts
import certificateManagerDialog from '@ohos.security.certManagerDialog';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

/* context is application context information, which is obtained by the caller. The context here is only an example. */
let context: common.Context = getContext(this);
/* certificateType specifies the certificate type. The value CA_CERT here indicates a CA certificate. */
let certificateType: certificateManagerDialog.CertificateType = certificateManagerDialog.CertificateType.CA_CERT;
/* certificateScope specifies the usage scope of the certificate. The value CURRENT_USER here means the certificate can be used by the the current user. */
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

## certificateManagerDialog.openUninstallCertificateDialog<sup>16+</sup>

openUninstallCertificateDialog(context: common.Context, certType: CertificateType, certUri: string): Promise\<void>

Opens a dialog box for uninstalling a certificate. This API uses a promise to return the result.

This API is available only to 2-in-1 devices.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: SystemCapability.Security.CertificateManagerDialog

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| context | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md)                   | Yes  | Context of the application.|
| certType | [CertificateType](#certificatetype14)                   | Yes  | Type of the certificate to uninstall.|
| certUri | string                  | Yes  | Unique identifier of the certificate to uninstall.|

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
| 29700001 | Internal error.     |
| 29700002 | The user cancels the uninstallation operation.     |
| 29700003 | The user uninstall certificate failed in the certificate manager dialog, such as the certificate uri is not exist.     |
| 29700004 | The API is not supported on this device.     |
| 29700005 | The operation does not comply with the device security policy, such as the device does not allow users to manage the ca certificate of the global user.     |

**Example**
```ts
import certificateManagerDialog from '@ohos.security.certManagerDialog';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

/* context is application context information, which is obtained by the caller. The context here is only an example. */
let context: common.Context = getContext(this);
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
