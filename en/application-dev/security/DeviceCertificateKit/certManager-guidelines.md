# Certificate Management Development

> **NOTE**
>
> The SDK of API version 11 or later must be used.

## Scenarios

**Typical scenarios**

   - Install an application certificate and its private credential.

   - Obtain the application certificate and private credential.

   - Perform signing and signature verification using an application certificate and its private credential.

   - Uninstall an application certificate and its private credential.

Before you get started, you need to know the combinations of the algorithm and the signing/signature verification parameters supported by certificate management.

   The credential installation, signing, and signature verification in certificate management depends on [HUKS](../UniversalKeystoreKit/huks-overview.md). The algorithms supported by certificate management are a subset of HUKS. Currently, only private credentials using the RSA or ECC algorithm can be installed and used. For details about the parameter combinations supported by signing and signature verification, see the description of RSA and ECC in [Signing and Signature Verification Overview and Algorithm Specifications](../UniversalKeystoreKit/huks-signing-signature-verification-overview.md).


## Available APIs

For details about the APIs, see [Certificate Management](../../reference/apis-device-certificate-kit/js-apis-certManager.md).

The following table describes the APIs used in the typical scenarios mentioned above.

| Instance         | API                                                      | Description                                        |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| certificateManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string, callback: AsyncCallback\<CMResult>) : void  | Installs a private credential. This API uses an asynchronous callback to return the result.                |
| certificateManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string) : Promise\<CMResult> | Installs a private credential. This API uses a promise to return the result.                 |
| certificateManager        | getPrivateCertificate(keyUri: string, callback: AsyncCallback\<CMResult>) : void    | Obtains a private credential. This API uses an asynchronous callback to return the result.         |
| certificateManager        | getPrivateCertificate(keyUri: string) : Promise\<CMResult>                         | Obtains a private credential. This API uses a promise to return the result.          |
| certificateManager        | uninstallPrivateCertificate(keyUri: string, callback: AsyncCallback\<void>) : void  | Uninstalls a private credential. This API uses an asynchronous callback to return the result.        |
| certificateManager        | uninstallPrivateCertificate(keyUri: string) : Promise\<void> | Uninstalls a private credential. This API uses a promise to return the result. |
| certificateManager | init(authUri: string, spec: CMSignatureSpec, callback: AsyncCallback\<CMHandle>) : void | Initializes the signing or signature verification operation. This API uses an asynchronous callback to return the result. |
| certificateManager | init(authUri: string, spec: CMSignatureSpec) : Promise\<CMHandle>  | Initializes the signing or signature verification operation. This API uses a promise to return the result. |
| certificateManager        | update(handle: Uint8Array, data: Uint8Array, callback: AsyncCallback\<void>) : void         | Updates the data to be signed or verified. This API uses an asynchronous callback to return the result.        |
| certificateManager        | update(handle: Uint8Array, data: Uint8Array) : Promise\<void> | Updates the data to be signed or verified. This API uses a promise to return the result. |
| certificateManager        | finish(handle: Uint8Array, callback: AsyncCallback\<CMResult>) : void         | Finishes the signing operation. This API uses an asynchronous callback to return the result.        |
| certificateManager        | finish(handle: Uint8Array, signature: Uint8Array, callback: AsyncCallback\<CMResult>) : void     | Finishes the signing operation. This API uses an asynchronous callback to return the result.        |
| certificateManager        | finish(handle: Uint8Array, signature?: Uint8Array) : Promise\<CMResult> | Finishes the signing or signature verification operation. This API uses a promise to return the result. |
| certificateManager        | abort(handle: Uint8Array, callback: AsyncCallback\<void>) : void         | Aborts the signing or signature verification operation. This API uses an asynchronous callback to return the result.        |
| certificateManager        | abort(handle: Uint8Array) : Promise\<void> | Aborts the signing or signature verification operation. This API uses a promise to return the result. |

## How to Develop

1. Request permissions.<br> To call **certManager** APIs, declare the ohos.permission.ACCESS_CERT_MANAGER permission in the **requestPermissions** field in the **module.json5** file. For more information, see [module.json5](../../quick-start/module-configuration-file.md).

2. Import modules.

   ```ts
   import { certificateManager } from '@kit.DeviceCertificateKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```
3. Install a private credential, obtain the private credential, use it to sign and verify data. Then, uninstall the private credential.

   ```ts
   async function certificateManagerSample() {
     /* The data of the credential to be installed must be assigned based on the service. The data in this example is not the real credential data. */
     let keystore: Uint8Array = new Uint8Array([
       0x30, 0x82, 0x04, 0x6a, 0x02, 0x01,
     ]);

     /* Keystore password of the credential to be installed. */
     let keystorePwd: string = '123456';
     let appKeyUri: string = '';
     try {
       /* Install a private credential. */
       const res = await certificateManager.installPrivateCertificate(keystore, keystorePwd, "testPriCredential");
       appKeyUri = (res.uri != undefined) ? res.uri : '';
     } catch (err) {
       let e: BusinessError = err as BusinessError;
       console.error(`Failed to install private certificate. Code: ${e.code}, message: ${e.message}`);
     }

     try {
       /* srcData is the data to be signed and verified. */
       let srcData: Uint8Array = new Uint8Array([
         0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01,
     ]);

       /* Construct the parameters used for signing. */
       const signSpec: certificateManager.CMSignatureSpec = {
         purpose: certificateManager.CmKeyPurpose.CM_KEY_PURPOSE_SIGN,
         padding: certificateManager.CmKeyPadding.CM_PADDING_PSS,
         digest: certificateManager.CmKeyDigest.CM_DIGEST_SHA256
       };

       /* Generate a signature. */
       const signHandle: certificateManager.CMHandle = await certificateManager.init(appKeyUri, signSpec);
       await certificateManager.update(signHandle.handle, srcData);
       const signResult: certificateManager.CMResult = await certificateManager.finish(signHandle.handle);

       /* Construct the parameters for signature verification. */
       const verifySpec: certificateManager.CMSignatureSpec = {
         purpose: certificateManager.CmKeyPurpose.CM_KEY_PURPOSE_VERIFY,
         padding: certificateManager.CmKeyPadding.CM_PADDING_PSS,
         digest: certificateManager.CmKeyDigest.CM_DIGEST_SHA256
       };

       /** Verify the signature. */
       const verifyHandle: certificateManager.CMHandle = await certificateManager.init(appKeyUri, verifySpec);
       await certificateManager.update(verifyHandle.handle, srcData);
       const verifyResult = await certificateManager.finish(verifyHandle.handle, signResult.outData);
       console.info('Succeeded in signing and verifying.');
     } catch (err) {
       let e: BusinessError = err as BusinessError;
       console.error(`Failed to sign or verify. Code: ${e.code}, message: ${e.message}`);
     }

     try {
       /* Uninstall a private credential. */
       await certificateManager.uninstallPrivateCertificate(appKeyUri);
     } catch (err) {
       let e: BusinessError = err as BusinessError;
       console.error(`Failed to uninstall private certificate. Code: ${e.code}, message: ${e.message}`);
     }
   }
   ```
