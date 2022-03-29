# 用户认证开发指导

> **说明：**
> 该开发指导匹配@ohos.userIAM.userAuth API Version 6开始支持的接口。对应接口已在API Version 8废弃，建议使用[新接口](userauth-guidelines-api8.md)。

## 场景介绍

当前用户认证支持2D人脸识别、3D人脸识别，可应用于设备解锁、应用登录、支付等身份认证场景。

## 接口说明

userIAM_userAuth模块提供了用户认证的相关方法，包括获取认证对象、认证，用户可以使用人脸等生物特征信息进行认证操作。具体接口说明可以查阅[API参考](../reference/apis/js-apis-useriam-userauth.md)。

**表1** 用户认证开放能力列表

| 接口名                                                       | 功能描述                                      |
| ------------------------------------------------------------ | --------------------------------------------- |
| getAuthenticator(): Authenticator                            | 获取Authenticator对象，用于执行用户身份认证。 |
| execute(type: AuthType, level: SecureLevel, callback: AsyncCallback\<number>): void | 执行用户认证，使用callback方式作为异步方法。  |
| execute(type: AuthType, level: SecureLevel): Promise\<number> | 执行用户认证，使用Promise方式作为异步方法。   |

## 开发步骤

开发前请完成以下准备工作：

1. 在应用配置权限文件中，增加ohos.permission.ACCESS_BIOMETRIC的权限声明。
2. 在使用用户认证能力的代码文件中增加import userIAM_userAuth from '@ohos.userIAM.userAuth'。

开发过程：

1. 获取Authenticator的单例对象，代码示例如下：

   ```js
   let auth = userIAM_userAuth.getAuthenticator();
   ```

2. 执行认证操作，代码示例如下：

   ```js
   let authenticator = userIAM_userAuth.getAuthenticator();
   authenticator.execute("FACE_ONLY", "S2").then((code) => {
       console.info("auth success");
   }).catch((code) => {
       console.error("auth fail, code = " + code);
   });
   ```
