# 发起认证

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--Designer: @lichangting518-->
<!--Tester: @jane_lz-->
<!--Adviser: @zengyawen-->

应用发起身份认证请求，获取身份认证结果，以访问受保护的系统、服务或应用的功能和数据，包括用户个人数据。

## 接口说明

具体参数、返回值、错误码等描述，请参考对应的[userAuth.getUserAuthInstance](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetuserauthinstance10)。

| 接口名称 | 功能描述 | 
| -------- | -------- |
| getUserAuthInstance(authParam: AuthParam, widgetParam: WidgetParam): UserAuthInstance | 获取UserAuthInstance对象，用于执行用户身份认证，并支持使用[统一用户认证控件](#统一用户认证控件介绍)。 | 
| on(type: 'result', callback: IAuthCallback): void | 订阅用户身份认证结果。 | 
| off(type: 'result', callback?: IAuthCallback): void | 取消订阅用户身份认证结果。 | 
| start(): void | 执行用户认证。 | 

## 统一用户认证控件介绍

系统提供了统一用户认证控件供应用调用，使用统一用户认证控件的优势：

- 统一用户认证服务将通过该控件完成信息的识别和认证，再将认证结果返回给应用，整体过程安全可控，可以更好地保护用户的生物特征信息。

- 统一固定的UI组件样式，便于用户识别。

认证控件的样式如图所示，通过[WidgetParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#widgetparam10)配置对应参数。

<!--RP1-->
![unified-UI-component-authentication](figures/unified-UI-component-authentication.png)
<!--RP1End-->

- 标注1：用户认证界面的标题（WidgetParam.title），不支持传空字串，最大长度为500字符。应用可在此配置符合场景的字符串，建议传入认证目的，例如用于支付、登录应用等。
<!--RP2-->
- 标注2：导航按键上显示的文本（WidgetParam.navigationButtonText），最大长度为60字符。API 10-17仅在单指纹、单人脸场景下支持配置。从API 18开始，增加支持人脸+指纹场景。

  当生物认证失败后，将显示一个按钮。点击该按钮，可以从生物认证切换到应用自定义认证。<!--RP2End-->

<!--Del-->
- 如图所示，认证控件的显示形式（WidgetParam.windowMode）为弹窗。
  
  认证控件分为弹窗、全屏两种显示形式，如下图所示，左侧为默认的弹窗样式，右侧为全屏样式。

  当前仅系统应用可以选择和使用全屏类型的认证界面。

  ![popup-authentication](figures/popup-authentication.png)
<!--DelEnd-->

当前支持使用认证控件的认证类型包括：

- 锁屏口令认证。

- 人脸认证。

- 指纹认证。

- 人脸+锁屏口令认证。

- 指纹+锁屏口令认证。

- 人脸+指纹+锁屏口令认证。

- 人脸+自定义导航按键。

- 指纹+自定义导航按键。

- 从API版本18开始，支持人脸+指纹+自定义导航按键的认证类型。

<!--RP3--><!--RP3End-->

## 开发步骤

1. [申请权限](prerequisites.md#申请权限)：ohos.permission.ACCESS_BIOMETRIC。

2. 指定用户认证相关参数[AuthParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authparam10)（包括挑战值、认证类型[UserAuthType](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthtype8)列表和认证等级[AuthTrustLevel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtrustlevel8)）、配置认证控件界面[WidgetParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#widgetparam10)，调用[getUserAuthInstance](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetuserauthinstance10)获取认证对象。

3. 调用[UserAuthInstance.on('result')](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#onresult10-1)接口订阅认证结果。

4. 调用[UserAuthInstance.start](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#start10)接口发起认证，通过[IAuthCallback](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#iauthcallback10)回调返回认证结果[UserAuthResult](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthresult10)。当认证成功时返回认证通过类型（[UserAuthType](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthtype8)）和令牌信息（AuthToken）。

**示例1：**

 发起用户认证，采用认证可信等级≥ATL3的人脸+指纹+锁屏口令认证，获取认证结果。

<!-- @[authentication_example1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/UserAuthentication/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
initiatingUserAuthentication1() {
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
    };
    // 配置认证界面
    const widgetParam: userAuth.WidgetParam = {
      title: resourceToString($r('app.string.title')),
    };
    // 获取认证对象
    const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
    Logger.info('get userAuth instance successfully.');
    // 订阅认证结果
    userAuthInstance.on('result', {
      onResult: (result: userAuth.UserAuthResult) => {
        try {
          Logger.info('userAuthInstance callback.');
          this.result[ResultIndex.EXAMPLE_1] = (`${result.result}`);
          // 可在认证结束或其他业务需要场景，取消订阅认证结果。
          userAuthInstance.off('result');
        } catch (error) {
          const err: BusinessError = error as BusinessError;
          Logger.error(`onResult failed, code: ${err?.code}, Message: ${err?.message}`);
        }
      }
    });
    // 启动认证
    userAuthInstance.start();
    Logger.info('auth start successfully.');
  } catch (error) {
    const err: BusinessError = error as BusinessError;
    Logger.error(`auth failed, code is ${err?.code}, message is ${err?.message}`);
  }
}
```


**示例2：**

发起用户认证，采用认证可信等级≥ATL3的人脸+认证类型相关+复用设备解锁最大有效时长认证，获取认证结果。

<!-- @[authentication_example2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/UserAuthentication/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
initiatingUserAuthentication2() {
  // 设置认证参数
  let reuseUnlockResult: userAuth.ReuseUnlockResult = {
    reuseMode: userAuth.ReuseMode.AUTH_TYPE_RELEVANT,
    reuseDuration: userAuth.MAX_ALLOWABLE_REUSE_DURATION,
  };
  try {
    const randData = getRandData();
    if (!randData) {
      return;
    }
    const authParam: userAuth.AuthParam = {
      challenge: randData,
      authType: [userAuth.UserAuthType.PIN, userAuth.UserAuthType.FACE, userAuth.UserAuthType.FINGERPRINT],
      authTrustLevel: userAuth.AuthTrustLevel.ATL3,
      reuseUnlockResult: reuseUnlockResult,
    };
    // 配置认证界面
    const widgetParam: userAuth.WidgetParam = {
      title: resourceToString($r('app.string.title')),
    };
    // 获取认证对象
    const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
    Logger.info('get userAuth instance successfully.');
    // 订阅认证结果
    userAuthInstance.on('result', {
      onResult: (result: userAuth.UserAuthResult) => {
        try {
          Logger.info('userAuthInstance callback.');
          this.result[ResultIndex.EXAMPLE_2] = (`${result.result}`);
          // 可在认证结束或其他业务需要场景，取消订阅认证结果。
          userAuthInstance.off('result');
        } catch (error) {
          const err: BusinessError = error as BusinessError;
          Logger.error(`onResult failed, code: ${err?.code}, Message: ${err?.message}`);
        }
      }
    });
    // 启动认证
    userAuthInstance.start();
    Logger.info('auth start successfully.');
  } catch (error) {
    const err: BusinessError = error as BusinessError;
    Logger.error(`auth failed, code is ${err?.code}, message is ${err?.message}`);
  }
}
```


**示例3：**

发起用户认证，采用认证可信等级≥ATL3的人脸+任意应用认证类型相关+复用任意应用最大有效时长认证，获取认证结果。

<!-- @[authentication_example3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/UserAuthentication/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
initiatingUserAuthentication3() {
  // 设置认证参数
  let reuseUnlockResult: userAuth.ReuseUnlockResult = {
    reuseMode: userAuth.ReuseMode.CALLER_IRRELEVANT_AUTH_TYPE_RELEVANT,
    reuseDuration: userAuth.MAX_ALLOWABLE_REUSE_DURATION,
  };
  try {
    const randData = getRandData();
    if (!randData) {
      return;
    }
    const authParam: userAuth.AuthParam = {
      challenge: randData,
      authType: [userAuth.UserAuthType.PIN, userAuth.UserAuthType.FACE, userAuth.UserAuthType.FINGERPRINT],
      authTrustLevel: userAuth.AuthTrustLevel.ATL3,
      reuseUnlockResult: reuseUnlockResult,
    };
    // 配置认证界面
    const widgetParam: userAuth.WidgetParam = {
      title: resourceToString($r('app.string.title')),
    };
    // 获取认证对象
    const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
    Logger.info('get userAuth instance successfully.');
    // 订阅认证结果
    userAuthInstance.on('result', {
      onResult: (result: userAuth.UserAuthResult) => {
        try {
          Logger.info('userAuthInstance callback.');
          this.result[ResultIndex.EXAMPLE_3] = (`${result.result}`);
          // 可在认证结束或其他业务需要场景，取消订阅认证结果。
          userAuthInstance.off('result');
        } catch (error) {
          const err: BusinessError = error as BusinessError;
          Logger.error(`onResult failed, code: ${err?.code}, Message: ${err?.message}`);
        }
      }
    });
    // 启动认证
    userAuthInstance.start();
    Logger.info('auth start successfully.');
  } catch (error) {
    const err: BusinessError = error as BusinessError;
    Logger.error(`auth failed, code is ${err?.code}, message is ${err?.message}`);
  }
}
```


**示例4：**

以模应用弹窗方式拉起身份认证控件对用户进行身份认证：

> **说明：**
> 在PC/2in1设备上，应用如果使用模应用弹窗方式发起认证（即配置用户界面参数[widgetParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#widgetparam10)时传入了有效的uiContext），收到认证结果后，若需弹出其他窗口，应先获取控件弹窗释放的标志消息，通过[on('authTip')](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#onauthtip20)接口订阅控件释放消息（authTipInfo.tipCode = UserAuthTipCode.WIDGET_RELEASED）。

<!-- @[authentication_example4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/UserAuthentication/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
initiatingUserAuthentication4() {
  // 设置认证参数
  try {
    const randData = getRandData();
    if (!randData) {
      return;
    }
    const authParam: userAuth.AuthParam = {
      challenge: randData,
      authType: [userAuth.UserAuthType.PIN, userAuth.UserAuthType.FACE, userAuth.UserAuthType.FINGERPRINT],
      authTrustLevel: userAuth.AuthTrustLevel.ATL3,
    };
    // 配置认证界面
    const widgetParam: userAuth.WidgetParam = {
      title: resourceToString($r('app.string.title')),
      uiContext: this.getUIContext().getHostContext()
    };
    // 获取认证对象
    const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
    Logger.info('get userAuth instance successfully.');
    // 订阅认证结果
    userAuthInstance.on('result', {
      onResult: (result: userAuth.UserAuthResult) => {
        try {
          Logger.info('userAuthInstance callback.');
          this.result[ResultIndex.EXAMPLE_4] = (`${result.result}`);
          // 可在认证结束或其他业务需要场景，取消订阅认证结果。
          userAuthInstance.off('result');
        } catch (error) {
          const err: BusinessError = error as BusinessError;
          Logger.error(`onResult failed, code: ${err?.code}, Message: ${err?.message}`);
        }
      }
    });
    // 启动认证
    userAuthInstance.start();
    Logger.info('auth start successfully.');
  } catch (error) {
    const err: BusinessError = error as BusinessError;
    Logger.error(`auth failed, code is ${err?.code}, message is ${err?.message}`);
  }
}
```


## 示例代码

  - [发起认证](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/UserAuthentication)
