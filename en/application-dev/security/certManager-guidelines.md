# Certificate Management Development

> **NOTE**
>
> The SDK of API version 11 or later must be used.

## Scenarios

You can use the certificate management APIs to:

- Install a private credential of the application.

- Obtain the private credential of an application.

- Use a private credential to sign or verify data.

- Uninstall a private credential of an application.

Before you get started, you need to know the combinations of the algorithm and the signing/signature verification parameters supported by certificate management.

The certificate management operations (such as installing a private credential and using the key of a private credential to sign or verify data) depend on [HUKS](huks-overview.md) capabilities. For details about the algorithm specifications for HUKS, see [HUKS Cipher Algorithm Specifications](huks-appendix.md). The algorithms supported by certificate management are a subset of HUKS cipher algorithm specifications. Currently, only the private credentials using the RSA and ECC algorithms can be installed and used. For details about the parameter combinations supported by signing and signature verification, see those of the RSA and ECC in [Combinations of the Signing or Signature Verification Algorithm, Digest Algorithm, and Padding Mode](huks-appendix.md#combinations-of-the-signing-or-signature-verification-algorithm-digest-algorithm-and-padding-mode).


## Available APIs

The following table describes the APIs used in the scenarios mentioned above. For details about the APIs, see [Certificate Management](../reference/apis/js-apis-certManager.md).

| Instance         | API                                                      | Description                                        |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| certManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string, callback: AsyncCallback\<CMResult>) : void  | Installs a private credential. This API uses an asynchronous callback to return the result.                |
| certManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string) : Promise\<CMResult> | Installs a private credential. This API uses a promise to return the result.                 |
| certManager        | getPrivateCertificate(keyUri: string, callback: AsyncCallback\<CMResult>) : void    | Obtains a private credential. This API uses an asynchronous callback to return the result.         |
| certManager        | getPrivateCertificate(keyUri: string) : Promise\<CMResult>                         | Obtains a private credential. This API uses a promise to return the result.          |
| certManager        | uninstallPrivateCertificate(keyUri: string, callback: AsyncCallback\<void>) : void  | Uninstalls a private credential. This API uses an asynchronous callback to return the result.        |
| certManager        | uninstallPrivateCertificate(keyUri: string) : Promise\<void> | Uninstalls a private credential. This API uses a promise to return the result.|
| certManager | init(authUri: string, spec: CMSignatureSpec, callback: AsyncCallback\<CMHandle>) : void | Initializes the signing or signature verification operation. This API uses an asynchronous callback to return the result.|
| certManager | init(authUri: string, spec: CMSignatureSpec) : Promise\<CMHandle>  | Initializes the signing or signature verification operation. This API uses a promise to return the result. |
| certManager        | update(handle: Uint8Array, data: Uint8Array, callback: AsyncCallback\<void>) : void         | Updates the data to be signed or verified. This API uses an asynchronous callback to return the result.        |
| certManager        | update(handle: Uint8Array, data: Uint8Array) : Promise\<void> | Updates the data to be signed or verified. This API uses a promise to return the result.|
| certManager        | finish(handle: Uint8Array, callback: AsyncCallback\<CMResult>) : void         | Finishes the signing operation. This API uses an asynchronous callback to return the result.        |
| certManager        | finish(handle: Uint8Array, signature: Uint8Array, callback: AsyncCallback\<CMResult>) : void     | Finishes the signature verification operation. This API uses an asynchronous callback to return the result. |
| certManager        | finish(handle: Uint8Array, signature?: Uint8Array) : Promise\<CMResult> | Finishes the signing or signature verification operation. This API uses a promise to return the result.|
| certManager        | abort(handle: Uint8Array, callback: AsyncCallback\<void>) : void         | Aborts the signing or signature verification operation. This API uses an asynchronous callback to return the result.        |
| certManager        | abort(handle: Uint8Array) : Promise\<void> | Aborts the signing or signature verification operation. This API uses a promise to return the result.|

## How to Develop

1. Apply for the required permission.<br>To call certificate management APIs, add the ohos.permission.ACCESS_CERT_MANAGER permission in **requestPermissions** in the **module.json5** file. For more information, see [module.json5](../quick-start/module-configuration-file.md).

2. Import modules.

   ```ts
   import certManager from '@ohos.security.certManager';
   import { BusinessError } from '@ohos.base';
   ```
3. Install a private credential, obtain the private credential, use it to sign and verify data. Then, uninstall the private credential.

   ```ts
   /* The credential data to be installed must be assigned by the service. The data in this example is not the real credential data. */
   let keystore: Uint8Array = new Uint8Array([
     0x30, 0x82, 0x04, 0x6a, 0x02, 0x01,
   ]);
   
   /* Password of the credential to be installed. The value is assigned by the service. */
   let keystorePwd: string = '123456';
   let appKeyUri: string = '';
   try {
     /* Install a private credential. */
     const res = await certManager.installPrivateCertificate(keystore, keystorePwd, "testPriCredential");
     appKeyUri = (res.uri != undefined) ? res.uri : '';
   } catch (err) {
     let e: BusinessError = err as BusinessError;
     console.error("installPrivateCertificates error, errcode:" + e.code);
   }
   
   try {
     /* srcData is the data to be signed and verified. The value is assigned by the service. */
     let srcData: Uint8Array = new Uint8Array([
       0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01,
     ]);
   
     /* Construct the parameters used for signing. */
     const signSpec: certManager.CMSignatureSpec = {
       purpose: certManager.CmKeyPurpose.CM_KEY_PURPOSE_SIGN,
       padding: certManager.CmKeyPadding.CM_PADDING_PSS,
       digest: certManager.CmKeyDigest.CM_DIGEST_SHA256
     };
   
     /* Generate a signature. */
     const signHandle: certManager.CMHandle = await certManager.init(appKeyUri, signSpec);
     await certManager.update(signHandle.handle, srcData);
     const signResult: certManager.CMResult = await certManager.finish(signHandle.handle);
   
     /* Construct the parameters used for signature verification. */
     const verifySpec: certManager.CMSignatureSpec = {
       purpose: certManager.CmKeyPurpose.CM_KEY_PURPOSE_VERIFY,
       padding: certManager.CmKeyPadding.CM_PADDING_PSS,
       digest: certManager.CmKeyDigest.CM_DIGEST_SHA256
     };
   
     /** Verify the signature. */
     const verifyHandle: certManager.CMHandle = await certManager.init(appKeyUri, verifySpec);
     await certManager.update(verifyHandle.handle, srcData);
     const verifyResult = await certManager.finish(verifyHandle.handle, signResult.outData);
     console.log("sign and verify success");
   } catch (err) {
     let e: BusinessError = err as BusinessError;
     console.error("sign or verify failed, errcode:" + e.code);
   }
   
   try {
     /* Uninstall the private credential. */
     await certManager.uninstallPrivateCertificate(appKeyUri);
   } catch (err) {
     let e: BusinessError = err as BusinessError;
     console.error("uninstallPrivateCertificate failed, errcode:" + e.code);
   }
   ```
<!--no_check-->