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

