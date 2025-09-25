# 感知和调整认证过程

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--Designer: @lichangting518-->
<!--Tester: @jane_lz-->
<!--Adviser: @zengyawen-->

从API version 20开始，在应用发起身份认证时，可通过接口调整认证过程，以及感知认证过程。

调整认证过程：应用发起认证时通过[AuthParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authparam10)参数的skipLockedBiometricAuth属性控制是否跳过已禁用的生物认证。

感知认证过程：通过[on](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#on20)接口注册回调来获取认证过程中控件的拉起和退出提示，以及认证过程中用户的每一次认证失败结果。正确的顺序为先通过on注册回调，再通过[start](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#start10)发起认证，start成功发起认证后on注册的回调才会收到信息。

## 接口说明

具体参数、返回值、错误码等描述，请参考对应的[API文档](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md)。

| 接口名称 | 功能描述 | 
| ------- | ------- |
| AuthParam | 用户认证相关参数，包括挑战值、认证类型列表、认证等级等。<br/>可通过skipLockedBiometricAuth参数控制是否跳过禁用的生物认证。<br/>true表示生物认证冻结时自动跳过倒计时界面直接切换到其他方式的认证。<br/>false表示不跳过；默认为false。 |
| on(type: 'authTip', callback: AuthTipCallback): void | 订阅身份认证过程中的提示信息。 | 
| off(type: 'authTip', callback?: AuthTipCallback): void | 取消订阅认证过程中的提示信息。 | 

## 开发步骤

1. [申请权限](prerequisites.md#申请权限)：ohos.permission.ACCESS_BIOMETRIC。

2. 指定用户认证相关参数[AuthParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authparam10)（包括挑战值、认证类型[UserAuthType](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthtype8)列表和认证等级[AuthTrustLevel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtrustlevel8)）、配置认证控件界面[WidgetParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#widgetparam10)，调用[getUserAuthInstance](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetuserauthinstance10)获取认证对象。

3. 调用[UserAuthInstance.on](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#on20)接口订阅身份认证过程中的提示信息。

4. 调用[UserAuthInstance.start](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#start10)接口发起认证，通过[AuthTipCallback](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtipcallback20)回调返回认证中间状态[AuthTipInfo](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtipinfo20)。

5. 认证成功后，调用[UserAuthInstance.off](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#off20)接口取消订阅认证过程中的提示信息。

以跳过禁用的生物认证，订阅认证信息为例：

```ts
import { BusinessError } from  '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
  // 设置认证参数。
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN, userAuth.UserAuthType.FACE],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
    skipLockedBiometricAuth: true
  };
  // 配置认证界面。
  const widgetParam: userAuth.WidgetParam = {
    title: '请进行身份认证'
  };
  // 获取认证对象。
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // 订阅认证过程中的提示信息。
  userAuthInstance.on('authTip', (authTipInfo: userAuth.AuthTipInfo) => {
    console.info(`userAuthInstance callback authTipInfo = ${JSON.stringify(authTipInfo)}`);
  });
  // 开始认证。
  userAuthInstance.start();
  console.info('auth start success');
  // 取消订阅认证过程中的提示信息。
  userAuthInstance.off('authTip');
  userAuthInstance.cancel();
  console.info('auth cancel success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```
<!-- [perceive-adjust-authentication-process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/UserAuthentication/entry/src/main/ets/pages/Index.ets) -->
