# 用户认证开发指导

## 场景介绍

当前用户认证支持2D人脸识别、3D人脸识别，可应用于设备解锁、应用登录、支付等身份认证场景。

## 接口说明

userIAM_userAuth模块提供了用户认证的相关方法，包括检测认证能力、认证和取消认证等，用户可以通过人脸等生物特征信息进行认证操作。具体接口说明可以查阅[API参考](../reference/apis/js-apis-useriam-userauth.md)。

在执行认证前，需要检查设备是否支持该认证能力，具体指认证类型、安全级别和是否本地认证。如果不支持，需要考虑使用其他认证能力。

**表1** 用户认证开放能力列表

| 接口名                                                       | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getAuthenticator(): Authenticator                            | 获取Authenticator对象，用于执行用户身份认证。<sup>6+</sup><br>获取Authenticator对象，用于检测设备身份认证能力、执行和取消用户身份认证，获取认证过程中的提示信息。<sup>7+</sup> |
| checkAvailability(type: AuthType, level: SecureLevel): number | 根据指定的认证类型、安全等级，检测当前设备是否支持相应的认证能力。 |
| execute(type: AuthType, level: SecureLevel, callback: AsyncCallback\<number>): void | 执行用户认证，使用callback方式作为异步方法。                 |
| execute(type: AuthType, level: SecureLevel): Promise\<number> | 执行用户认证，使用Promise方式作为异步方法。                  |
| cancel(): void                                               | 取消当前的认证流程。                                         |
| on(type: "tip", callback: Callback\<Tip>): void              | 订阅指定类型的事件。                                         |
| off(type: "tip", callback?: Callback\<Tip>): void            | 取消订阅指定类型的事件。                                     |

## 开发步骤

开发前请完成以下准备工作：

1. 在应用配置权限文件中，增加ohos.permission.ACCESS_BIOMETRIC的权限声明。
2. 在使用用户认证能力的代码文件中增加import userIAM_userAuth from '@ohos.userIAM.userAuth'。

开发过程：

1. 获取Authenticator的单例对象，代码示例如下：

   ```js
   let auth = userIAM_userAuth.getAuthenticator();
   ```

2. 检测设备是否具有指定级别的认证能力：

   2D人脸识别支持低于S2级别的认证，3D人脸识别支持低于S3级别的认证。代码示例如下：

   ```js
   let authenticator = userIAM_userAuth.getAuthenticator();
   let checkCode = authenticator.checkAvailability("FACE_ONLY", "S2");
   if (checkCode == userIAM_userAuth.CheckAvailabilityResult.SUPPORTED) {
       console.info("check auth support success");
   } else {
       console.error("check auth support fail, code = " + checkCode);
   }
   ```

3. （可选）订阅人脸tip信息，代码示例如下：

   ```js
   let authenticator = userIAM_userAuth.getAuthenticator();
   let tipCallback = (tip)=>{
       console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode +") event(" +
           tip.tipEvent + ") info(" + tip.tipInfo + ")");
   };
   authenticator.on("tip", tipCallback);
   ```

4. 执行认证操作，代码示例如下：

   ```js
   let authenticator = userIAM_userAuth.getAuthenticator();
   authenticator.execute("FACE_ONLY", "S2").then((code)=>{
       authenticator.off("tip", tipCallback);
       console.info("auth success");
   }).catch((code)=>{
       authenticator.off("tip", tipCallback);
       console.error("auth fail, code = " + code);
   });
   ```

5. （仅执行订阅信息后需要）取消订阅人脸tip信息：

   ```js
   let authenticator = userIAM_userAuth.getAuthenticator();
   let tipCallback = (tip)=>{
       console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode + ") event(" +
           tip.tipEvent + ") info(" + tip.tipInfo + ")");
   };
   // 取消订阅指定回调
   authenticator.off("tip", tipCallback);
   // 取消订阅所有回调authenticator.off("tip");
   ```

6. 认证过程中取消认证，代码示例如下：

   ```js
   let authenticator = userIAM_userAuth.getAuthenticator();
   let cancelCode = authenticator.cancel();
   if (cancelCode == userIAM_userAuth.Result.SUCCESS) {
       console.info("cancel auth success");
   } else {
       console.error("cancel auth fail");
   }
   ```