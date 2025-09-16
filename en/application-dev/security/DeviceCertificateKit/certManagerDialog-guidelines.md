# Certificate Management Dialog Box Development

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> This guide applies to the SDK of API version 13 or later.

You can use the **certificateManagerDialog** APIs to open the certificate management dialog box and perform certificate management, such as installing, storing, using, and destroying a certificate.

## Available APIs

For details about the APIs, see [Certificate Management Dialog Box](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md).

The following table describes the commonly used APIs.

| Instance         | API                                                      | Description                                        |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| certificateManagerDialog        | openCertificateManagerDialog(context: common.Context, pageType: CertificateDialogPageType): Promise\<void> | Opens the certificate management dialog box and displays the page of the specified type. This API uses a promise to return the result.|
| certificateManagerDialog | openInstallCertificateDialog(context: common.Context, certType: CertificateType, certScope: CertificateScope, cert: Uint8Array): Promise\<string><sup>14+</sup> | Opens the certificate installation dialog box to install a certificate. This API uses a promise to return the unique identifier of the installed certificate.<br>This API is available only to 2-in-1 devices.|
| certificateManagerDialog | openUninstallCertificateDialog(context: common.Context, certType: CertificateType, certUri: string): Promise\<void><sup>18+</sup> | Opens the certificate uninstallation dialog box to uninstall a certificate. This API uses a promise to return the result.<br>This API is available only to 2-in-1 devices.|
| certificateManagerDialog | openCertificateDetailDialog(context: common.Context, cert: Uint8Array, property: CertificateDialogProperty): Promise\<void><sup>18+</sup> | Opens the certificate details dialog box to display the certificate details. This API uses a promise to return the result.<br>This API is available only to 2-in-1 devices.|

## How to Develop

1. Request and declare permissions.

   Required permission: **ohos.permission.ACCESS_CERT_MANAGER**

   For details about how to request permissions, see [Workflow for Requesting Permissions](../AccessToken/determine-application-mode.md).

   For details about how to declare permissions, see [Declaring Permissions](../AccessToken/declare-permissions.md).

2. Import the required module.

   ```ts
   import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { UIContext } from '@kit.ArkUI';
   ```

3. Open the certificate management dialog box.

   ```ts
   /* context is application context information, which is obtained by the caller. The context here is only an example. */
   let context: common.Context = new UIContext().getHostContext() as common.Context;
   async function certificateManagerDialogSample() {
     /* pageType specifies the type of the page to display. In this example, pageType is PAGE_MAIN, which indicates the main page of the Certificate Manager application. */
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
   }
   ```
4. Call the APIs for installing a certificate, uninstalling a certificate, and viewing certificate details, respectively. These APIs are available only to 2-in-1 devices.

   ```ts
   /* context is application context information, which is obtained by the caller. The context here is only an example. */
   let context: common.Context = new UIContext().getHostContext() as common.Context;
   async function userCADialogSample() {
     let certUri: string = '';
     let certType = certificateManagerDialog.CertificateType.CA_CERT;
     /* The user CA certificate data must be assigned based on the service. */
     let cert = new Uint8Array([
       0x30, 0x82, 0x01, 0x2E, 0x30, 0x81, 0xD5, 0x02, 0x14, 0x28, 0x75, 0x71, 0x22, 0xDF, 0xDC, 0xCB,
     ]);

     try {
       /* Install the certificate. */
       let certScope = certificateManagerDialog.CertificateScope.CURRENT_USER; /* Install the certificate under the current user. */
       certificateManagerDialog.openInstallCertificateDialog(context, certType, certScope, cert).then((result) => {
         console.info('Succeeded in opening install ca dialog.');
         certUri = result;
       }).catch((err: BusinessError) => {
         console.error(`Failed to open install ca dialog. Code: ${err.code}, message: ${err.message}`);
       })
     } catch (error) {
       console.error(`Failed to open install ca dialog. Code: ${error.code}, message: ${error.message}`);
     }

     try {
       /* Uninstall the certificate. */
       certificateManagerDialog.openUninstallCertificateDialog(context, certType, certUri).then(() => {
         console.info('Succeeded in opening uninstall ca dialog.');
       }).catch((err: BusinessError) => {
         console.error(`Failed to open uninstall ca dialog. Code: ${err.code}, message: ${err.message}`);
       })
     } catch (error) {
       console.error(`Failed to open uninstall ca dialog. Code: ${error.code}, message: ${error.message}`);
     }

     try {
       let property: certificateManagerDialog.CertificateDialogProperty = {
         showInstallButton: false    /* Do not display the button for installing the certificate. */
       };
       /* Display certificate details. */
       certificateManagerDialog.openCertificateDetailDialog(context, cert, property).then(() => {
         console.info('Succeeded in opening show ca detail dialog.');
       }).catch((err: BusinessError) => {
         console.error(`Failed to open show ca detail dialog. Code: ${err.code}, message: ${err.message}`);
       })
     } catch (error) {
       console.error(`Failed to open show ca detail dialog. Code: ${error.code}, message: ${error.message}`);
     }
   }
   ```
