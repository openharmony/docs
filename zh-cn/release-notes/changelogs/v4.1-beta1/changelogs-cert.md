# cert子系统ChangeLog

##  cl.cert.1 X509Crl接口变更

**访问级别**

公开接口

**变更原因**

1.为满足规范规定的证书吊销列表（CRL）描述，需要将原有X509Crl相关的接口，重新定义为X509CRL。

2.getRevokedCert接口，规范规定的证书序列号范围较大，需要将serialNumber参数类型从number变更为bigint。

**变更影响**

该变更为非兼容性变更。从API11开始，X509Crl接口不再提供支持，应用需要自行适配为X509CRL接口函数。函数功能不变。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

修改前的接口原型：

 ```js
interface X509Crl {
    ...
    getRevokedCert(serialNumber: number): X509CrlEntry;
    getRevokedCertWithCert(cert: X509Cert): X509CrlEntry;
    getRevokedCerts(callback: AsyncCallback<Array<X509CrlEntry>>): void;
    getRevokedCerts(): Promise<Array<X509CrlEntry>>;
    getTbsInfo(): DataBlob;    
    ...
};
function createX509Crl(inStream: EncodingBlob, callback: AsyncCallback<X509Crl>): void;
function createX509Crl(inStream: EncodingBlob): Promise<X509Crl>;
 ```

修改后的接口原型：

 ```js
interface X509CRL {
    ...
    getRevokedCert(serialNumber: bigint): X509CRLEntry;
    getRevokedCertWithCert(cert: X509Cert): X509CRLEntry;
    getRevokedCerts(callback: AsyncCallback<Array<X509CRLEntry>>): void;
    getRevokedCerts(): Promise<Array<X509CRLEntry>>;
    getTBSInfo(): DataBlob;    
    ...
};
function createX509CRL(inStream: EncodingBlob, callback: AsyncCallback<X509CRL>): void;
function createX509CRL(inStream: EncodingBlob): Promise<X509CRL>;
 ```

**适配指导**

接口使用的示例代码可参考[证书开发指导](../../../application-dev/security/cert-guidelines.md)和[API参考](../../../application-dev/reference/apis/js-apis-cert.md)。

##  cl.cert.2 X509CrlEntry接口变更

**访问级别**

公开接口

**变更原因**

1.为满足规范规定的证书吊销列表（CRL）描述，需要将原有X509CrlEntry相关的接口，重新定义为X509CRLEntry。

2.获取序列号的接口getSerialNumber，由于规范规定的证书序列号范围较大，返回值类型需要从number变更为bigint。

**变更影响**

该变更为非兼容性变更。从API11开始，X509CrlEntry接口不再提供支持，应用需要自行适配为X509CRLEntry。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

修改前的接口原型：

 ```js
interface X509CrlEntry {
  ...
  getSerialNumber(): number;
  ...
}
 ```

修改后的接口原型：

 ```js
interface X509CRLEntry {
  ...
  getSerialNumber(): bigint;
  ...
}
 ```

**适配指导**

接口使用的示例代码可参考[证书开发指导](../../../application-dev/security/cert-guidelines.md)和[API参考](../../../application-dev/reference/apis/js-apis-cert.md)。
