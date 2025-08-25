# Device Certificate Kit（设备证书服务）

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3--; @chaceli-->
<!--Designer: @lanming--; @chande-->
<!--Tester: @PAFT--; @zhangzhi1995-->
<!--Adviser: @zengyawen-->

- [Device Certificate Kit简介](device-certificate-kit-intro.md)
- 证书算法库框架<!--certificate-framework-->
  - [证书算法库框架概述](certificate-framework-overview.md)
  - [证书对象的创建、解析和校验](create-parse-verify-cert-object.md)
  - [证书扩展信息对象的创建、解析和校验](create-parse-verify-certextension-object.md)
  - [证书吊销列表对象的创建、解析和校验](create-parse-verify-crl-object.md)
  - [证书链校验时从p12文件构造TrustAnchor对象数组](create-trustanchor-from-p12.md)
  - [证书链校验器对象的创建和校验](create-verify-cerchainvalidator-object.md)
  - [证书集合及证书吊销列表集合对象的创建和获取](create-get-cert-crl-object.md)
  - [证书链对象的创建和校验](create-verify-certchain-object.md)
  - [使用系统预置CA证书校验证书链](verify-certchain-by-systemca.md)
  - [证书PKCS7签名](create-pkcs7-sign-object.md)
  - [证书PKCS12的创建和解析](create-parse-pkcs12.md)
- 证书管理<!--certmanager-->
  - [证书管理概述](certManager-overview.md)
  - [应用证书凭据开发指导](certManager-private-credential-guidelines.md)
  - [CA证书开发指导](certManager-ca-certs-guidelines.md)
  - [证书管理对话框开发指导](certManagerDialog-guidelines.md)
