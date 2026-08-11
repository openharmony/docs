# 感知和调整认证过程

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--Designer: @lichangting518-->
<!--Tester: @jane_lz-->
<!--Adviser: @zengyawen-->

从API version 20开始，在应用发起身份认证时，可通过接口调整认证过程，以及感知认证过程。

调整认证过程：应用发起认证时通过[AuthParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authparam10)参数的skipLockedBiometricAuth属性控制是否跳过已禁用的生物认证。

感知认证过程：通过[on('authTip')](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#onauthtip20)接口注册回调来获取认证过程中控件的拉起和退出提示，以及认证过程中用户的每一次认证失败结果。正确的顺序为先通过on注册回调，再通过[start](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#start10)发起认证，start成功发起认证后on注册的回调才会收到信息。

## 接口说明

具体参数、返回值、错误码等描述，请参考对应的[@ohos.userIAM.userAuth (用户认证)](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md)。

| 接口名称 | 功能描述 | 
| ------- | ------- |
| AuthParam | 用户认证相关参数，包括挑战值、认证类型列表、认证等级等。<br/>可通过skipLockedBiometricAuth参数控制是否跳过禁用的生物认证。<br/>true表示生物认证冻结时自动跳过倒计时界面直接切换到其他方式的认证。<br/>false表示不跳过；默认为false。 |
| on(type: 'authTip', callback: AuthTipCallback): void | 订阅身份认证过程中的提示信息。 | 
| off(type: 'authTip', callback?: AuthTipCallback): void | 取消订阅认证过程中的提示信息。 | 

## 开发步骤

1. [申请权限](prerequisites.md#申请权限)：ohos.permission.ACCESS_BIOMETRIC。

2. 指定用户认证相关参数[AuthParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authparam10)（包括挑战值、认证类型[UserAuthType](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthtype8)列表和认证等级[AuthTrustLevel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtrustlevel8)）、配置认证控件界面[WidgetParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#widgetparam10)，调用[getUserAuthInstance](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetuserauthinstance10)获取认证对象。

3. 调用[UserAuthInstance.on('authTip')](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#onauthtip20)接口订阅身份认证过程中的提示信息。

4. 调用[UserAuthInstance.start](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#start10)接口发起认证，通过[AuthTipCallback](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtipcallback20)回调返回认证中间状态[AuthTipInfo](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtipinfo20)。

5. 认证成功后，调用[UserAuthInstance.off('authTip')](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#offauthtip20)接口取消订阅认证过程中的提示信息。

以跳过禁用的生物认证，订阅认证信息为例：

<!-- @[perceive-adjust-authentication-process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/UserAuthentication/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
perceiveAndAdjustAuthentication() {
  try {
    const randData = getRandData();
    if (!randData) {
      return;
    }
    // 设置认证参数
    const authParam: userAuth.AuthParam = {
      challenge: randData,
      authType: [userAuth.UserAuthType.PIN, userAuth.UserAuthType.FACE, userAuth.UserAuthType.FINGERPRINT],
      authTrustLevel: userAuth.AuthTrustLevel.ATL3,
      skipLockedBiometricAuth: true
    };
    // 配置认证界面
    const widgetParam: userAuth.WidgetParam = {
      title: resourceToString($r('app.string.title')),
    };
    // 获取认证对象
    const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
    Logger.info('get userAuth instance successfully.');
    // 订阅认证过程中的提示信息。
    userAuthInstance.on('authTip', (authTipInfo: userAuth.AuthTipInfo) => {
      try {
        Logger.info('userAuthInstance callback.');
        this.result[ResultIndex.PERCEIVE_ADJUST] = (`${authTipInfo.tipType}`);
        // 认证完成后取消订阅
        userAuthInstance.off('result');
      } catch (error) {
        const err: BusinessError = error as BusinessError;
        Logger.error(`onResult failed, code: ${err?.code}, Message: ${err?.message}`);
      }
    });
    // 开始认证
    userAuthInstance.start();
    // ...
      // 取消订阅认证过程中的提示信息。
      userAuthInstance.off('authTip');
      Logger.info('off authTip successfully.');
      // 取消认证
      userAuthInstance.cancel();
      Logger.info('auth cancel successfully.');
      // ...
  } catch (error) {
    const err: BusinessError = error as BusinessError;
    Logger.error(`auth failed, code is ${err?.code as number}, message is ${err?.message}`);
  }
}
```


## 示例代码

  - [感知和调整认证过程](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/UserAuthentication)
