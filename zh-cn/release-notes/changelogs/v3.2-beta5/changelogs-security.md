# security子系统ChangeLog

## cl.security.1 Random的setSeed功能变更，由异步接口改为同步接口

**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
修改前的接口原型：
setSeed(seed : DataBlob, callback : AsyncCallback\<void>) : void;
setSeed(seed : DataBlob) : Promise\<void>;
修改后的接口原型：
setSeed(seed : DataBlob) : void;

**适配指导**
查看API参考中setSeed对应的接口适配指南：
[加解密算法库框架-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cryptoFramework.md)


## cl.security.2 interface DataArray 从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface DataArray从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.3 interface EncodingFormat从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface EncodingFormat从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.4 interface EncodingBlob 从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface EncodingBlob 从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.5 interface CertChainData从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface CertChainData从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.6 interface X509Cert从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface X509Cert从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.7 function createX509Cert从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
function createX509Cert从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.8 interface X509CrlEntry从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface X509CrlEntry从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.9 interface X509Crl从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface X509Crl从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.10 function createX509Crl从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
function createX509Crl从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.11 interface CertChainValidator从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface CertChainValidator从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.12 function createCertChainValidator从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
function createCertChainValidator从@ohos.security.cryptoFramework.d.ts 迁移至@ohos.security.cert.d.ts

**适配指导**
重新import并使用对应的.d.ts文件：
import cryptoCert from '@ohos.security.cert';
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.13 X509Cert 的getPublicKey功能变更，由异步接口改为同步接口
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
修改前的接口原型：
getPublicKey(callback : AsyncCallback\<PubKey>) : void;
getPublicKey() : Promise\<PubKey>;
修改后的接口原型：
getPublicKey() : cryptoFramework.PubKey;

**适配指导**
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.14 X509Cert 的checkValidityWithDate功能变更，由异步接口改为同步接口
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
修改前的接口原型：
checkValidityWithDate(date: string, callback : AsyncCallback\<void>) : void;
checkValidityWithDate(date: string) : Promise\<void>;
修改后的接口原型：
checkValidityWithDate(date: string) : void;

**适配指导**
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.15 X509CrlEntry 的getCertIssuer功能变更，由异步接口改为同步接口
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
修改前的接口原型：
getCertIssuer(callback : AsyncCallback\<DataBlob>) : void;
getCertIssuer() : Promise\<DataBlob>;

修改后的接口原型：
getCertIssuer() : DataBlob;

**适配指导**
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.16 X509CrlEntry 的getRevocationDate功能变更，由异步接口改为同步接口
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
修改前的接口原型：
getRevocationDate(callback : AsyncCallback\<string>) : void;
getRevocationDate() : Promise\<string>;

修改后的接口原型：
getRevocationDate() : string;

**适配指导**
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.17 X509Crl 的isRevoked功能变更，由异步接口改为同步接口
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
修改前的接口原型：
isRevoked(cert : X509Cert, callback : AsyncCallback\<boolean>) : void;
isRevoked(cert : X509Cert) : Promise\<boolean>;

修改后的接口原型：
isRevoked(cert : X509Cert) : boolean;

**适配指导**
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.18 X509Crl 的getRevokedCert功能变更，由异步接口改为同步接口
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
修改前的接口原型：
getRevokedCert(serialNumber : number, callback : AsyncCallback\<X509CrlEntry>) : void;
getRevokedCert(serialNumber : number) : Promise\<X509CrlEntry>;

修改后的接口原型：
getRevokedCert(serialNumber : number) : X509CrlEntry;

**适配指导**
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.19 X509Crl 的getRevokedCertWithCert功能变更，由异步接口改为同步接口
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
修改前的接口原型：
getRevokedCertWithCert(cert : X509Cert, callback : AsyncCallback\<X509CrlEntry>) : void;
getRevokedCertWithCert(cert : X509Cert) : Promise\<X509CrlEntry>;

修改后的接口原型：
getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry;

**适配指导**
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)


## cl.security.20 X509Crl 的getTbsInfo功能变更，由异步接口改为同步接口
**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
修改前的接口原型：
getTbsInfo(callback : AsyncCallback\<DataBlob>) : void;
getTbsInfo() : Promise\<DataBlob>;

修改后的接口原型：
getTbsInfo() : DataBlob;

**适配指导**
查看API参考中对应的接口适配指南：
[证书-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cert.md)

## cl.security.21 HUKS支持No-Hash的签名模式

变更之前，应用传递huks.HuksTag.HUKS_TAG_DIGEST = huks.HuksKeyDigest.HUKS_DIGEST_NONE，HUKS默认使用huks.HuksKeyDigest.HUKS_DIGEST_SHA256进行处理；变更之后，应用传递huks.HuksTag.HUKS_TAG_DIGEST = huks.HuksKeyDigest.HUKS_DIGEST_NONE时，HUKS默认不进行摘要处理，需要业务先对原始数据进行hash操作，再将hash后的摘要传入huks进行签名/验签处理。

**变更影响**

影响已发布的JS接口，接口行为发生变更。
应用需要进行适配，才可以使得变更前后的签名/验签结果通过。

**关键的接口/组件变更**

发布的JS接口不变， 传入接口的参数集合发生变更。

业务使用No-Hash的签名模式，需要先对原始数据进行hash处理，再将hash后的摘要传入huks签名/验签接口。同时huks.HuksTag.HUKS_TAG_DIGEST参数设置为huks.HuksKeyDigest.HUKS_DIGEST_NONE。

**适配指导**

以签名为例，示例代码如下：

```js
import huks from '@ohos.security.huks';

let keyAlias = 'rsa_Key';
/* sha256之后的摘要值 */
let inDataAfterSha256 = new Uint8Array(
    0x4B, 0x1E, 0x22, 0x64, 0xA9, 0x89, 0x60, 0x1D, 0xEC, 0x78, 0xC0, 0x5D, 0xBE, 0x46, 0xAD, 0xCF,
    0x1C, 0x35, 0x16, 0x11, 0x34, 0x01, 0x4E, 0x9B, 0x7C, 0x00, 0x66, 0x0E, 0xCA, 0x09, 0xC0, 0xF3,
);
/* 签名参数 */
let signProperties = new Array();
signProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA,
}
signProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
}
signProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048,
}
signProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE, // 设置 digest-none
}
let signOptions = {
    properties: signProperties,
    inData: inDataAfterSha256 // 设置HASH后的值
}

huks.initSession(keyAlias, signOptions);
```

更多接口的示例代码可参考[HUKS-guidelines](../../../application-dev/security/huks-guidelines.md)和[HUKS API](../../../application-dev/reference/apis/js-apis-huks.md)。

## cl.security.22 HUKS支持在密钥使用时指定密钥运算参数

变更之前，业务在生成密钥的时候，必须指定密钥运算的全部参数；变更之后，在生成密钥时，只需要包含必选参数即可，在密钥使用阶段再传入其他参数。业务使用会更加灵活。

**变更影响**

影响已发布的JS接口，接口行为发生变更。

允许应用在生成密钥阶段传入的参数中包含必选参数即可，在密钥使用阶段再传入其他可选参数。

**关键的接口/组件变更**

发布的JS接口不变， 传入接口的参数集合发生变更，将参数分为必选参数和可选参数，具体可参考[HUKS-guidelines](../../../application-dev/security/huks-guidelines.md)，涉及的接口有：

huks.generateKeyItem

huks.importKeyItem

huks.importWrappedKeyItem

huks.initSession

huks.updateSession

huks.finishSession

**适配指导**

以生成密钥为例，示例代码如下：

```js
let keyAlias = 'keyAlias';
let properties = new Array();
//必选参数
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
};
//必选参数
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
};
//必选参数
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
};
//可选参数，如果在生成密钥阶段没有传入，则在使用密钥阶段必须传入。
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
};
let options = {
    properties: properties
};
try {
    huks.generateKeyItem(keyAlias, options, function (error, data) {
        if (error) {
            console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
        } else {
            console.info(`callback: generateKeyItem key success`);
        }
    });
} catch (error) {
    console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
}
```

更多接口的示例代码可参考[HUKS-guidelines](../../../application-dev/security/huks-guidelines.md)和[HUKS API](../../../application-dev/reference/apis/js-apis-huks.md)。
