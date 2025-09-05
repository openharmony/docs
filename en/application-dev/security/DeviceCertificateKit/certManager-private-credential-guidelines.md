# Application Certificate Development

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The SDK of API version 11 or later must be used.

## Scenarios

1. Typical scenarios:

   - Install an application certificate.
   - Obtain an application certificate.
   - Use an application certificate to sign or verify data.
   - Uninstall an application certificate.

2. Before installation, you need to know the algorithm types and the combinations of the signing and signature verification parameters supported by certificate management.

   - Certificate management depends on the [Universal Keystore Kit](../UniversalKeystoreKit/huks-overview.md) (HUKS) to install certificates and use the keys in the certificates for signing and signature verification.
   - The algorithms supported by certificate management are a subset of HUKS cipher algorithm specifications. Currently, only the private certificates using the RSA, ECC, and SM2 algorithms can be installed and used.
   - For details about the parameter combinations supported by signing and signature verification, see the description of RSA, ECC, and SM2 in [Signing and Signature Verification Overview and Algorithm Specifications](../UniversalKeystoreKit/huks-signing-signature-verification-overview.md).

## Available APIs

For details about the APIs, see [Certificate Management](../../reference/apis-device-certificate-kit/js-apis-certManager.md).

The following table describes the commonly used APIs.

| Instance         | API                                                      | Description                                        |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| certificateManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string, callback: AsyncCallback\<CMResult>) : void  | Installs an application certificate. This API uses an asynchronous callback to return the result.       |
| certificateManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string) : Promise\<CMResult> | Installs an application certificate. This API uses a promise to return the result.              |
| certificateManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string, level: AuthStorageLevel) : Promise\<CMResult><sup>18+</sup> | Installs an application certificate and specifies the certificate storage level. This API uses a promise to return the result.|
| certificateManager        | getPrivateCertificate(keyUri: string, callback: AsyncCallback\<CMResult>) : void    | Obtains an application certificate. This API uses an asynchronous callback to return the result.      |
| certificateManager        | getPrivateCertificate(keyUri: string) : Promise\<CMResult>                         | Obtains an application certificate. This API uses a promise to return the result.       |
| certificateManager        | uninstallPrivateCertificate(keyUri: string, callback: AsyncCallback\<void>) : void  | Uninstalls an application certificate. This API uses an asynchronous callback to return the result.     |
| certificateManager        | uninstallPrivateCertificate(keyUri: string) : Promise\<void> | Uninstalls an application certificate. This API uses a promise to return the result.|
| certificateManager | init(authUri: string, spec: CMSignatureSpec, callback: AsyncCallback\<CMHandle>) : void | Initializes the signing or signature verification operation. This API uses an asynchronous callback to return the result.|
| certificateManager | init(authUri: string, spec: CMSignatureSpec) : Promise\<CMHandle>  | Initializes the signing or signature verification operation. This API uses a promise to return the result.|
| certificateManager        | update(handle: Uint8Array, data: Uint8Array, callback: AsyncCallback\<void>) : void         | Updates the data to be signed or verified. This API uses an asynchronous callback to return the result.       |
| certificateManager        | update(handle: Uint8Array, data: Uint8Array) : Promise\<void> | Updates the data to be signed or verified. This API uses a promise to return the result.|
| certificateManager        | finish(handle: Uint8Array, callback: AsyncCallback\<CMResult>) : void         | Finishes the signing operation. This API uses an asynchronous callback to return the result.       |
| certificateManager        | finish(handle: Uint8Array, signature: Uint8Array, callback: AsyncCallback\<CMResult>) : void     | Finishes the signing operation. This API uses an asynchronous callback to return the result.       |
| certificateManager        | finish(handle: Uint8Array, signature?: Uint8Array) : Promise\<CMResult> | Finishes the signing or signature verification operation. This API uses a promise to return the result.|
| certificateManager        | abort(handle: Uint8Array, callback: AsyncCallback\<void>) : void         | Aborts the signing or signature verification operation. This API uses an asynchronous callback to return the result.       |
| certificateManager        | abort(handle: Uint8Array) : Promise\<void> | Aborts the signing or signature verification operation. This API uses a promise to return the result.|

## How to Develop

1. Request and declare permissions.

   Required permission: **ohos.permission.ACCESS_CERT_MANAGER**

   For details about how to request permissions, see [Workflow for Requesting Permissions](../AccessToken/determine-application-mode.md).

   For details about how to declare permissions, see [Declaring Permissions](../AccessToken/declare-permissions.md).

2. Import the required module.

   ```ts
   import { certificateManager } from '@kit.DeviceCertificateKit';
   ```
   
3. Install an application certificate, obtain the certificate, use it to sign and verify data. Then, uninstall the certificate.

   ```ts
   async function privateCredSample() {
     /* The data of the certificate to be installed must be assigned based on the service. The data in this example is not the real certificate data. */
     let keystore: Uint8Array = new Uint8Array([
       0x30, 0x82, 0x04, 0x6a, 0x02, 0x01, 0x03, 0x30, 0x82, 0x04, 0x30, 0x06, 0x09,
     ]);
   
     /* Keystore password of the certificate to be installed. */
     let keystorePwd: string = '123456';
     let appKeyUri: string = '';
     try {
       /* Install an application certificate. */
       const res: certificateManager.CMResult = await certificateManager.installPrivateCertificate(keystore, keystorePwd, "testPriCredential");
       appKeyUri = (res.uri != undefined) ? res.uri : '';
     } catch (err) {
       console.error(`Failed to install private certificate. Code: ${err.code}, message: ${err.message}`);
     }
      
     try {
       /* Obtain the application certificate. */
       let res: certificateManager.CMResult = await certificateManager.getPrivateCertificate(appKeyUri);
       if (res === undefined || res.credential == undefined) {
         console.error('The result of getting private certificate is undefined.');
       } else {
         let credential = res.credential;
         console.info('Succeeded in getting private certificate.');
       }
     } catch (err) {
       console.error(`Failed to get private certificate. Code: ${err.code}, message: ${err.message}`);
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
       console.error(`Failed to sign or verify. Code: ${err.code}, message: ${err.message}`);
     }
       
     try {
       /* Uninstall the application certificate. */
       await certificateManager.uninstallPrivateCertificate(appKeyUri);
     } catch (err) {
       console.error(`Failed to uninstall private certificate. Code: ${err.code}, message: ${err.message}`);
     }
   }
   ```
