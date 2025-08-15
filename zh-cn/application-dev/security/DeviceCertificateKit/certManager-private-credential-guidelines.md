# 应用证书凭据开发指导

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

> **说明**
>
> 本开发指导需使用API version 11及以上版本SDK。

## 场景说明

1. 典型场景。

   - 安装应用证书凭据。
   - 获取应用证书凭据。
   - 使用应用证书凭据对数据进行签名、验签。
   - 卸载指定的应用证书凭据。

2. 支持安装的应用证书凭据算法类型和签名验签支持的参数组合。

   - 证书管理安装凭据及使用凭据中的密钥进行签名、验签，依赖[密钥管理服务](../UniversalKeystoreKit/huks-overview.md)（HUKS）能力。
   - 证书管理支持的算法为其子集，当前仅支持RSA、ECC及SM2算法类型的私有凭据安装及使用。
   - 签名、验签支持的参数组合，详见HUKS声明的[签名/验签介绍及算法规格](../UniversalKeystoreKit/huks-signing-signature-verification-overview.md)中RSA、ECC及SM2的描述。

## 接口说明

详细接口说明可参考[API参考](../../reference/apis-device-certificate-kit/js-apis-certManager.md)。

以上场景涉及的常用接口如下表所示。

| 实例名          | 接口名                                                       | 描述                                         |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| certificateManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string, callback: AsyncCallback\<CMResult>) : void  | 使用callback方式安装应用证书凭据。        |
| certificateManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string) : Promise\<CMResult> | 使用promise方式安装应用证书凭据。               |
| certificateManager        | installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string, level: AuthStorageLevel) : Promise\<CMResult><sup>18+</sup> | 使用promise方式安装应用证书凭据，并指定凭据的存储级别。 |
| certificateManager        | getPrivateCertificate(keyUri: string, callback: AsyncCallback\<CMResult>) : void    | 使用callback方式获取应用证书凭据。       |
| certificateManager        | getPrivateCertificate(keyUri: string) : Promise\<CMResult>                         | 使用promise方式获取应用证书凭据。        |
| certificateManager        | uninstallPrivateCertificate(keyUri: string, callback: AsyncCallback\<void>) : void  | 使用callback方式卸载应用证书凭据。      |
| certificateManager        | uninstallPrivateCertificate(keyUri: string) : Promise\<void> | 使用promise方式卸载应用证书凭据。 |
| certificateManager | init(authUri: string, spec: CMSignatureSpec, callback: AsyncCallback\<CMHandle>) : void | 使用callback方式进行签名验签的初始化操作。 |
| certificateManager | init(authUri: string, spec: CMSignatureSpec) : Promise\<CMHandle>  | 使用promise方式进行签名验签的初始化操作。 |
| certificateManager        | update(handle: Uint8Array, data: Uint8Array, callback: AsyncCallback\<void>) : void         | 使用callback方式对待签名、验签的数据进行更新操作。        |
| certificateManager        | update(handle: Uint8Array, data: Uint8Array) : Promise\<void> | 使用promise方式对待签名、验签的数据进行更新操作。 |
| certificateManager        | finish(handle: Uint8Array, callback: AsyncCallback\<CMResult>) : void         | 使用callback方式完成数据的签名操作。        |
| certificateManager        | finish(handle: Uint8Array, signature: Uint8Array, callback: AsyncCallback\<CMResult>) : void     | 使用callback方式完成数据的签名操作。        |
| certificateManager        | finish(handle: Uint8Array, signature?: Uint8Array) : Promise\<CMResult> | 使用promise方式完成数据的签名、验签操作。 |
| certificateManager        | abort(handle: Uint8Array, callback: AsyncCallback\<void>) : void         | 使用callback方式中止签名、验证操作。        |
| certificateManager        | abort(handle: Uint8Array) : Promise\<void> | 使用promise方式中止签名、验证操作。 |

## 开发步骤

1. 权限申请和声明。

   需要申请的权限：ohos.permission.ACCESS_CERT_MANAGER

   申请流程请参考：[申请应用权限](../AccessToken/determine-application-mode.md)

   声明权限请参考：[声明权限](../AccessToken/declare-permissions.md)

2. 导入相关模块。

   ```ts
   import { certificateManager } from '@kit.DeviceCertificateKit';
   ```
   
3. 安装应用证书凭据，获取应用证书凭据，并使用应用证书凭据进行签名、验签，最后删除应用证书凭据。

   ```ts
   async function privateCredSample() {
     /* 安装的凭据数据需要业务赋值，本例数据非凭据数据。 */
     let keystore: Uint8Array = new Uint8Array([
       0x30, 0x82, 0x04, 0x6a, 0x02, 0x01, 0x03, 0x30, 0x82, 0x04, 0x30, 0x06, 0x09,
     ]);
   
     /* 安装凭据对应的密码，业务赋值。 */
     let keystorePwd: string = '123456';
     let appKeyUri: string = '';
     try {
       /* 安装应用证书凭据。 */
       const res: certificateManager.CMResult = await certificateManager.installPrivateCertificate(keystore, keystorePwd, "testPriCredential");
       appKeyUri = (res.uri != undefined) ? res.uri : '';
     } catch (err) {
       console.error(`Failed to install private certificate. Code: ${err.code}, message: ${err.message}`);
     }
      
     try {
       /* 获取应用证书凭据。 */
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
       /* srcData为待签名、验签的数据，业务自行赋值。 */
       let srcData: Uint8Array = new Uint8Array([
         0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01,
       ]);
       
       /* 构造签名的属性参数。 */
       const signSpec: certificateManager.CMSignatureSpec = {
         purpose: certificateManager.CmKeyPurpose.CM_KEY_PURPOSE_SIGN,
         padding: certificateManager.CmKeyPadding.CM_PADDING_PSS,
         digest: certificateManager.CmKeyDigest.CM_DIGEST_SHA256
       };
       
       /* 签名。 */
       const signHandle: certificateManager.CMHandle = await certificateManager.init(appKeyUri, signSpec);
       await certificateManager.update(signHandle.handle, srcData);
       const signResult: certificateManager.CMResult = await certificateManager.finish(signHandle.handle);
       
       /* 构造验签的属性参数。 */
       const verifySpec: certificateManager.CMSignatureSpec = {
         purpose: certificateManager.CmKeyPurpose.CM_KEY_PURPOSE_VERIFY,
         padding: certificateManager.CmKeyPadding.CM_PADDING_PSS,
         digest: certificateManager.CmKeyDigest.CM_DIGEST_SHA256
       };
       
       /* 验签。 */
       const verifyHandle: certificateManager.CMHandle = await certificateManager.init(appKeyUri, verifySpec);
       await certificateManager.update(verifyHandle.handle, srcData);
       const verifyResult = await certificateManager.finish(verifyHandle.handle, signResult.outData);
       console.info('Succeeded in signing and verifying.');
     } catch (err) {
       console.error(`Failed to sign or verify. Code: ${err.code}, message: ${err.message}`);
     }
       
     try {
       /* 删除应用证书凭据。 */
       await certificateManager.uninstallPrivateCertificate(appKeyUri);
     } catch (err) {
       console.error(`Failed to uninstall private certificate. Code: ${err.code}, message: ${err.message}`);
     }
   }
   ```