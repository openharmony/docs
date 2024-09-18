# Certificate Management Dialog Box Development

> **NOTE**
>
> This guide applies to the SDK of API version 13 or later.

You can use the **certificateManagerDialog** APIs to open the certificate management dialog box and perform certificate management, such as installing, storing, using, and destroying a certificate.


## Available APIs

For details about the APIs, see [Certificate Management Dialog Box](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md).

The following table describes the commonly used APIs.

| Instance         | API                                                      | Description                                        |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| certificateManagerDialog        | openCertificateManagerDialog(context: common.Context, pageType: CertificateDialogPageType): Promise\<void> | Opens the certificate management dialog box and displays the page of the specified type. This API uses a promise to return the result. |

## How to Develop

1. Apply for the ohos.permission.ACCESS_CERT_MANAGER permission. For details, see [Declaring Permissions](../AccessToken/declare-permissions.md).

2. Import modules.

   ```ts
   import certificateManagerDialog from '@ohos.security.certManagerDialog';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```
3. Open the certificate management dialog box.

   ```ts
   async function certificateManagerDialogSample() {
	/* context is application context information, which is obtained by the caller. The context here is only an example. */
	let context: common.Context = getContext(this);
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
