# 安全子系统ChangeLog

##  cl.cert.1 X509Cert.getSerialNumber接口废弃变更

X509Cert.getSerialNumber接口作废弃处理，变更为X509Cert.getCertSerialNumber接口。

**变更影响**

从API version 10开始，X509Cert.getSerialNumber接口废弃。应用需要自行适配为X509Cert.getCertSerialNumber。接口功能不变。

**关键的接口/组件变更**

修改前的接口原型：

 ```js
interface X509Cert {
  ...
  getSerialNumber(): number;
  ...
}
 ```

修改后的接口原型：

 ```js
interface X509Cert {
  ...
  getCertSerialNumber(): bigint;
  ...
}
 ```

**适配指导**

接口使用的示例代码可参考[证书开发指导](../../../application-dev/security/cert-guidelines.md)和[API参考](../../../application-dev/reference/apis/js-apis-cert.md)。
