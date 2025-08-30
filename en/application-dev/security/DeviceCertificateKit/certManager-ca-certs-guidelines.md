# CA Certificate Development

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> This guide applies to the SDK of API version 12 or later.

## Scenarios

Typical scenarios:

- Install a user CA certificate. The caller can install the user CA certificate in the current user or device public directory.
  - If the certificate is installed in the current user directory, only the services of the current user can access the certificate.
  - If the certificate is installed in the device public directory, services of all users can access the certificate.
- Obtain the list of user CA certificates from the current user or device public directory.
- Obtain the details of a user CA certificate.
- Delete a user CA certificate.
- Obtain the storage path of a CA certificate.

## Available APIs

For details about the APIs, see [Certificate Management](../../reference/apis-device-certificate-kit/js-apis-certManager.md).

The following table describes the commonly used APIs.

| Instance         | API                                                      | Description                                        |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| certificateManager        | installUserTrustedCertificateSync(cert: Uint8Array, certScope: CertScope) : CMResult<sup>18+</sup> | Installs a user CA certificate.       |
| certificateManager        | uninstallUserTrustedCertificateSync(certUri: string) : void<sup>18+</sup> | Deletes a user CA certificate.      |
| certificateManager        | getAllUserTrustedCertificates(): Promise\<CMResult> | Obtains the list of all user root CA certificates in the current user and device public directories.|
| certificateManager        | getAllUserTrustedCertificates(scope: CertScope): Promise\<CMResult><sup>18+</sup> | Obtains the list of user root CA certificates based on the certificate storage path.|
| certificateManager        | getUserTrustedCertificate(certUri: string): Promise\<CMResult> | Obtains the details about a user root CA certificate.|
| certificateManager | getCertificateStorePath(property: CertStoreProperty): string<sup>18+</sup> | Obtains the storage path of a certificate.|

## How to Develop

1. Request and declare permissions.

    To use the API for installing or deleting a certificate, request the **ohos.permission.ACCESS_ENTERPRISE_USER_TRUSTED_CERT** or **ohos.permission.ACCESS_USER_TRUSTED_CERT** permission.
    
    To use the API for obtaining the certificate list or details, request the **ohos.permission.ACCESS_CERT_MANAGER** permission.
    
    For details about how to request permissions, see [Workflow for Requesting Permissions](../AccessToken/determine-application-mode.md).
    
    For details about how to declare permissions, see [Declaring Permissions](../AccessToken/declare-permissions.md).

2. Import the required module.

   ```ts
   import { certificateManager } from '@kit.DeviceCertificateKit';
   ```

3. Install a user CA certificate, obtain the list of user CA certificates, obtain the details of the user certificate, and delete the user CA certificate.

   ```ts
   async function userCASample() {
     /* The user CA certificate data to be installed must be assigned based on the service. */
     let userCAData: Uint8Array = new Uint8Array([
       0x30, 0x82, 0x01, 0x2E, 0x30, 0x81, 0xD5, 0x02, 0x14, 0x28, 0x75, 0x71, 0x22, 0xDF, 0xDC, 0xCB,
       0xD4, 0xE5, 0x6B, 0x6B, 0x89, 0xEB, 0x77, 0x97, 0xF6, 0x1D, 0xF4, 0x62, 0x81, 0x30, 0x0A, 0x06,
       0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x30, 0x1A, 0x31, 0x18, 0x30, 0x16, 0x06,
       0x03, 0x55, 0x04, 0x03, 0x0C, 0x0F, 0x45, 0x78, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x20, 0x52, 0x6F,
       0x6F, 0x74, 0x20, 0x43, 0x41, 0x30, 0x1E, 0x17, 0x0D, 0x32, 0x35, 0x30, 0x32, 0x32, 0x37, 0x31,
       0x31, 0x35, 0x38, 0x30, 0x34, 0x5A, 0x17, 0x0D, 0x32, 0x37, 0x31, 0x31, 0x32, 0x33, 0x31, 0x31,
       0x35, 0x38, 0x30, 0x34, 0x5A, 0x30, 0x1A, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03,
       0x0C, 0x0F, 0x45, 0x78, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43,
       0x41, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08,
       0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0x39, 0xCC, 0xE1, 0x3F,
       0x36, 0x57, 0x73, 0x82, 0x28, 0x56, 0xBB, 0xE7, 0x97, 0x6C, 0xA9, 0x66, 0x3E, 0xD7, 0x2C, 0xF2,
       0x7B, 0x05, 0x81, 0xE8, 0xA4, 0x57, 0x90, 0x5D, 0x64, 0x6A, 0xAD, 0x30, 0x2F, 0x1D, 0x6F, 0x31,
       0x31, 0xCB, 0x35, 0x84, 0x7F, 0xF6, 0xE4, 0xD5, 0x7B, 0x66, 0xDD, 0x93, 0x2B, 0x0C, 0x1B, 0x42,
       0xA4, 0x68, 0xE3, 0xC6, 0x9C, 0xF5, 0xFE, 0x66, 0x78, 0xF7, 0xBD, 0x9C, 0x30, 0x0A, 0x06, 0x08,
       0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x03, 0x48, 0x00, 0x30, 0x45, 0x02, 0x21, 0x00,
       0xCC, 0xA7, 0x34, 0xC5, 0xC0, 0x31, 0x36, 0x19, 0x3F, 0xA4, 0x34, 0x48, 0xC3, 0x2C, 0x7D, 0x33,
       0x1F, 0x0A, 0xCF, 0xB0, 0x73, 0x58, 0x6B, 0xB7, 0xC9, 0xAE, 0x16, 0x34, 0xF1, 0x8F, 0xAF, 0xC8,
       0x02, 0x20, 0x70, 0x9C, 0x64, 0xC2, 0xE2, 0x60, 0x26, 0x01, 0x5F, 0xF2, 0x0B, 0x8C, 0x9F, 0x7D,
       0x18, 0x6E, 0x91, 0xA6, 0xB3, 0x5E, 0x2C, 0xF0, 0x68, 0x45, 0x11, 0x1D, 0xA0, 0xCB, 0x83, 0xEB,
       0xE6, 0x25,
     ]);
   
     let certUri: string = '';
     let certScope = certificateManager.CertScope.CURRENT_USER;
     try {
       /* Install the user CA certificate in the current user directory. */
       let result = certificateManager.installUserTrustedCertificateSync(userCAData, certScope);
       certUri = (result.uri != undefined) ? result.uri : '';
       console.info(`Succeeded in install user ca cert, certUri is ${certUri}`);
     } catch (err) {
       console.error(`Failed to install user ca cert. Code: ${err.code}, message: ${err.message}`);
     }
   
     try {
       /* Obtain the details of the user CA certificate. */
       let result = await certificateManager.getUserTrustedCertificate(certUri);
       if (result === undefined || result.certInfo == undefined) {
         console.error('The result of getting user ca cert is undefined.');
       } else {
         let certInfo = result.certInfo;
         console.info('Succeeded in getting user ca cert.');
       }
     } catch (err) {
       console.error(`Failed to get user ca certificate. Code: ${err.code}, message: ${err.message}`);
     }
   
     try {
       /* Obtain the list of user CA certificates in the current user directory. */
       let result = await certificateManager.getAllUserTrustedCertificates(certScope);
       if (result == undefined) { /* If the number of root CA certificates is 0, the returned result is undefined. */
         console.info('the count of the user trusted certificates is 0');
       } else if (result.certList == undefined) {
         console.error('The result of getting current user trusted certificates is undefined.');
       } else {
         let list = result.certList;
         console.info('Succeeded in getting user ca cert list.');
       }
     } catch (err) {
       console.error(`Failed to get user ca certificate. Code: ${err.code}, message: ${err.message}`);
     }
   
     try {
       /* Delete the installed user CA certificate. */
       certificateManager.uninstallUserTrustedCertificateSync(certUri);
     } catch (err) {
       console.error(`Failed to uninstall user ca certificate. Code: ${err.code}, message: ${err.message}`);
     }
   }
   ```

4. Obtain the paths of system CA certificates and user CA certificates so applications can access them.

   ```ts
   function getUserCAPath() {
     try {
       /* Obtain the storage path of the system CA certificates. */
       let property1: certificateManager.CertStoreProperty = {
         certType: certificateManager.CertType.CA_CERT_SYSTEM,
       }
       let systemCAPath = certificateManager.getCertificateStorePath(property1);
       console.info(`Success to get system ca path: ${systemCAPath}`);
   
       /* Obtain the storage path of the CA certificates for the current user. */
       let property2: certificateManager.CertStoreProperty = {
         certType: certificateManager.CertType.CA_CERT_USER,
         certScope: certificateManager.CertScope.CURRENT_USER,
       }
       let userCACurrentPath = certificateManager.getCertificateStorePath(property2);
       console.info(`Success to get current user's user ca path: ${userCACurrentPath}`);
   
       /* Obtain the storage path of the CA certificates for all users. */
       let property3: certificateManager.CertStoreProperty = {
         certType: certificateManager.CertType.CA_CERT_USER,
         certScope: certificateManager.CertScope.GLOBAL_USER,
       }
       let globalCACurrentPath = certificateManager.getCertificateStorePath(property3);
       console.info(`Success to get global user's user ca path: ${globalCACurrentPath}`);
     } catch (error) {
       console.error(`Failed to get store path. Code: ${error.code}, message: ${error.message}`);
     }
   }
   ```
