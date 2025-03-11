# CA证书开发指导

> **说明**
>
> 本开发指导需使用API version 12及以上版本SDK。

## 场景说明

典型场景。

- 安装用户CA证书。调用者可以将用户CA证书安装在当前用户或者设备公共位置下。
  - 安装在当前用户时，仅当前用户的业务可以访问该证书。
  - 安装在设备公共位置下，所有用户下的业务都可以访问。
- 获取用户CA证书列表。可以选择获取当前用户或者设备公共位置下的用户CA证书列表。
- 获取用户CA证书详情。
- 删除指定的用户CA证书。
- 获取CA证书的存储路径。

## 接口说明

详细接口说明可参考[API参考](../../reference/apis-device-certificate-kit/js-apis-certManager.md)。

以上场景涉及的常用接口如下表所示。

| 实例名          | 接口名                                                       | 描述                                         |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| certificateManager        | installUserTrustedCertificateSync(cert: Uint8Array, certScope: CertScope) : CMResult<sup>18+</sup> | 安装用户CA证书。        |
| certificateManager        | uninstallUserTrustedCertificateSync(certUri: string) : void<sup>18+</sup> | 删除用户CA证书。       |
| certificateManager        | getAllUserTrustedCertificates(): Promise\<CMResult> | 获取当前用户和设备公共位置的所有用户根CA证书列表。 |
| certificateManager        | getAllUserTrustedCertificates(scope: CertScope): Promise\<CMResult><sup>18+</sup> | 根据证书的位置获取用户根CA证书列表。 |
| certificateManager        | getUserTrustedCertificate(certUri: string): Promise\<CMResult> | 获取用户根CA证书的详细信息。 |
| certificateManager | getCertificateStorePath(property: CertStoreProperty): string<sup>18+</sup> | 获取证书的存储路径。 |


## 开发步骤

1. 权限申请和声明。

    使用安装和删除接口需要申请权限：ohos.permission.ACCESS_ENTERPRISE_USER_TRUSTED_CERT或ohos.permission.ACCESS_USER_TRUSTED_CERT
    
    使用获取列表和获取详情接口需要申请权限：ohos.permission.ACCESS_CERT_MANAGER
    
    申请流程请参考：[申请应用权限](../AccessToken/determine-application-mode.md)
    
    声明权限请参考：[声明权限](../AccessToken/declare-permissions.md)

2. 导入相关模块。

   ```ts
   import { certificateManager } from '@kit.DeviceCertificateKit';
   ```

3. 安装用户CA证书、获取用户CA证书列表、获取用户证书详情、删除用户CA证书。

   ```ts
   async function userCASample() {
     /* 安装的用户CA证书数据需要业务赋值。 */
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
       /* 在当前用户下，安装用户CA证书。 */
       let result = certificateManager.installUserTrustedCertificateSync(userCAData, certScope);
       certUri = (result.uri != undefined) ? result.uri : '';
       console.info(`Succeeded in install user ca cert, certUri is ${certUri}`);
     } catch (err) {
       console.error(`Failed to install user ca cert. Code: ${err.code}, message: ${err.message}`);
     }
   
     try {
       /* 获取用户CA证书详情。 */
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
       /* 获取当前用户下的用户CA证书列表。 */
       let result = await certificateManager.getAllUserTrustedCertificates(certScope);
       if (result == undefined) { /* 用户根CA证书个数为0时，返回result为undefined。 */
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
       /* 删除安装的用户CA证书。 */
       certificateManager.uninstallUserTrustedCertificateSync(certUri);
     } catch (err) {
       console.error(`Failed to uninstall user ca certificate. Code: ${err.code}, message: ${err.message}`);
     }
   }
   ```

4. 获取系统CA证书路径、用户CA证书路径。应用可以直接通过该路径访问CA证书。

   ```ts
   function getUserCAPath() {
     try {
       /* 获取系统CA的存储位置。 */
       let property1: certificateManager.CertStoreProperty = {
         certType: certificateManager.CertType.CA_CERT_SYSTEM,
       }
       let systemCAPath = certificateManager.getCertificateStorePath(property1);
       console.info(`Success to get system ca path: ${systemCAPath}`);
   
       /* 获取当前用户的用户CA存储位置。 */
       let property2: certificateManager.CertStoreProperty = {
         certType: certificateManager.CertType.CA_CERT_USER,
         certScope: certificateManager.CertScope.CURRENT_USER,
       }
       let userCACurrentPath = certificateManager.getCertificateStorePath(property2);
       console.info(`Success to get current user's user ca path: ${userCACurrentPath}`);
   
       /* 获取设备公共的用户CA存储位置。 */
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