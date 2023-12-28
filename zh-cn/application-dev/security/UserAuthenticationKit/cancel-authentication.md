# 认证过程中取消认证


统一用户认证框架提供了cancel接口，当应用在认证过程中，需要取消认证时可调用该接口。


## 接口说明

具体参数、返回值、错误码等描述，请参考对应的[API文档](../../reference/apis/js-apis-useriam-userauth.md#cancel10)。

此处仅展示了取消认证操作的接口，在取消认证前，需要先发起认证，发起认证的接口列表、详细说明可参考[发起认证](start-authentication.md)章节和API文档。

| 接口名称 | 功能描述 | 
| -------- | -------- |
| cancel(): void | 取消本次认证操作。 | 


## 开发步骤

1. [申请权限](prerequisites.md#申请权限)：ohos.permission.ACCESS_BIOMETRIC。

2. 指定用户认证相关参数[AuthParam](../../reference/apis/js-apis-useriam-userauth.md#authparam10)（包括挑战值、认证类型[UserAuthType](../../reference/apis/js-apis-useriam-userauth.md#userauthtype8)列表和认证等级[AuthTrustLevel](../../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)），获取认证对象[UserAuthInstance](../../reference/apis/js-apis-useriam-userauth.md#userauthinstance10)，并调用[UserAuthInstance.start](../../reference/apis/js-apis-useriam-userauth.md#start10)发起认证。
   此步骤详细说明可参考[发起认证](start-authentication.md)。

3. 通过使用已经成功发起认证的UserAuthInstance对象调用[UserAuthInstance.cancel](../../reference/apis/js-apis-useriam-userauth.md#cancel10)接口取消本次认证。

示例代码为发起认证可信等级≥ATL3的人脸+锁屏密码认证后，取消认证请求：

```ts
import userIAM_userAuth from '@ohos.userIAM.userAuth'; 

const authParam: userIAM_userAuth.AuthParam = {
  challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
  authType: [userIAM_userAuth.UserAuthType.PIN, userIAM_userAuth.UserAuthType.FACE],
  authTrustLevel: userIAM_userAuth.AuthTrustLevel.ATL3,
};
const widgetParam: userIAM_userAuth.WidgetParam = {
  title: '请进行身份认证',
};
try {
  // 获取认证对象
  let userAuthInstance = userIAM_userAuth.getUserAuthInstance(authParam, widgetParam);
  console.log('get userAuth instance success');
  // 开始认证
  userAuthInstance.start();
  console.log('auth start success');
  // 取消认证
  userAuthInstance.cancel();
  console.log('auth cancel success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.log('auth catch error. Code is ${err.code}, message is ${err.message}`);
}
```
