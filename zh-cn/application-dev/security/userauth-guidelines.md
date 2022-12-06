# 用户认证开发指导

> **说明：**
> 该开发指导需配合API version 9版本的SDK使用。

## 场景介绍

当前用户认证支持人脸识别和指纹识别，可应用于设备解锁、应用登录、支付等身份认证场景。

## 接口说明

userIAM_userAuth模块提供了用户认证的相关方法，包括查询认证能力、发起认证和取消认证等，用户可以使用人脸、指纹等生物特征信息进行认证操作。具体接口说明可以查阅[API参考文档](../reference/apis/js-apis-useriam-userauth.md)。

在执行认证前，需要指定[认证类型](../reference/apis/js-apis-useriam-userauth.md#userauthtype8)和[认证等级](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)，查询设备是否支持该认证能力。

**表1** 用户认证开放能力列表

| 接口名称    | 功能描述                |
| ---------- | ----------------------- |
| getVersion() : number      | 获取认证对象的版本信息。            |
| getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void | 根据指定的认证类型、认证等级，检测当前设备是否支持相应的认证能力。 |
| getAuthInstance(challenge : Uint8Array, authType : UserAuthType, authTrustLevel : AuthTrustLevel): AuthInstance | 获取AuthInstance对象，用于执行用户身份认证。 |
| on(name : AuthEventKey, callback : AuthEvent) : void | 订阅指定类型的用户认证事件。 |
| off(name : AuthEventKey) : void | 取消订阅特定类型的认证事件。 |
| start: void  | 执行用户认证。        |
| cancel: void | 取消本次认证操作。    |

## 获取认证对象的版本信息

### 开发步骤

1. 申请权限。调用[getVersion](../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetversion9)接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[Stage模型应用程序包结构](../quick-start/application-package-structure-stage.md)。

2. 调用[getVersion](../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetversion9)接口获取版本信息。

    ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    // 获取版本信息
    try {
        let version = userIAM_userAuth.getVersion();
        console.info("auth version = " + version);
    } catch (error) {
        console.info("get version failed, error = " + error);
    }
    ```

## 查询当前设备是否支持相应的认证能力

### 开发步骤

1. 申请权限。调用[getAvailableStatus](../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetavailablestatus9)接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[Stage模型应用程序包结构](../quick-start/application-package-structure-stage.md)。

2. 指定[认证类型](../reference/apis/js-apis-useriam-userauth.md#userauthtype8)和[认证等级](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)，调用[getAvailableStatus](../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetavailablestatus9)接口查询当前的设备是否支持相应的认证能力。

    ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    // 查询认证能力是否支持
    try {
        userIAM_userAuth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
        console.info("current auth trust level is supported");
    } catch (error) {
        console.info("current auth trust level is not supported, error = " + error);
    }
    ```

## 执行认证操作并请阅认证结果

### 开发步骤

1. 申请权限。调用[start](../reference/apis/js-apis-useriam-userauth.md#start9)接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[Stage模型应用程序包结构](../quick-start/application-package-structure-stage.md)。

2. 指定challenge、[认证类型](../reference/apis/js-apis-useriam-userauth.md#userauthtype8)和[认证等级](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)，获取认证对象。

3. 调用[on](../reference/apis/js-apis-useriam-userauth.md#on9)接口订阅认证结果。

4. 调用[start](../reference/apis/js-apis-useriam-userauth.md#start9)接口发起认证，通过[callback](../reference/apis/js-apis-useriam-userauth.md#callback9)回调返回认证结果。

5. 调用[off](../reference/apis/js-apis-useriam-userauth.md#off9)接口取消订阅认证结果。

    ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

    // 获取认证对象
    let auth;
    try {
        auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
        console.log("get auth instance success");
    } catch (error) {
        console.log("get auth instance failed" + error);
    }

    // 订阅认证结果
    try {
        auth.on("result", {
            callback: (result: userIAM_userAuth.AuthResultInfo) => {
                console.log("authV9 result " + result.result);
                console.log("authV9 token " + result.token);
                console.log("authV9 remainAttempts " + result.remainAttempts);
                console.log("authV9 lockoutDuration " + result.lockoutDuration);
            }
        });
        console.log("subscribe authentication event success");
    } catch (error) {
        console.log("subscribe authentication event failed " + error);
    }

    // 开始认证
    try {
        auth.start();
        console.info("authV9 start auth success");
    } catch (error) {
        console.info("authV9 start auth failed, error = " + error);
    }

    // 取消订阅认证结果
    try {
        auth.off("result");
        console.info("cancel subscribe authentication event success");
    } catch (error) {
        console.info("cancel subscribe authentication event failed, error = " + error);
    }
    ```

## 执行认证操作并订阅认证过程中的提示信息

### 开发步骤

1. 申请权限。调用[start](../reference/apis/js-apis-useriam-userauth.md#start9)接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[Stage模型应用程序包结构](../quick-start/application-package-structure-stage.md)。

2. 指定challenge、[认证类型](../reference/apis/js-apis-useriam-userauth.md#userauthtype8)和[认证等级](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)，获取认证对象。

3. 调用[on](../reference/apis/js-apis-useriam-userauth.md#on9)接口订阅认证过程中的提示信息。

4. 调用[start](../reference/apis/js-apis-useriam-userauth.md#start9)接口发起认证，通过[callback](../reference/apis/js-apis-useriam-userauth.md#callback9)回调返回认证过程中的提示信息。

5. 调用[off](../reference/apis/js-apis-useriam-userauth.md#off9)接口取消订阅认证过程中的提示信息。

    ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

    // 获取认证对象
    let auth;
    try {
        auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
        console.log("get auth instance success");
    } catch (error) {
        console.log("get auth instance failed" + error);
    }

    // 订阅认证过程中的提示信息
    try {
        auth.on("tip", {
            callback : (result : userIAM_userAuth.TipInfo) => {
                switch (result.tip) {
                    case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
                    // do something;
                    case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
                    // do something;
                    default:
                    // do others
                }
            }
        });
        console.log("subscribe authentication event success");
    } catch (error) {
        console.log("subscribe authentication event failed " + error);
    }

    // 开始认证
    try {
        auth.start();
        console.info("authV9 start auth success");
    } catch (error) {
        console.info("authV9 start auth failed, error = " + error);
    }

    // 取消订阅认证过程中的提示信息
    try {
        auth.off("tip");
        console.info("cancel subscribe tip information success");
    } catch (error) {
        console.info("cancel subscribe tip information failed, error = " + error);
    }
    ```

## 认证过程中取消认证

### 开发步骤

1. 申请权限。调用[cancel](../reference/apis/js-apis-useriam-userauth.md#cancel9)接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[Stage模型应用程序包结构](../quick-start/application-package-structure-stage.md)。

2. 指定challenge、[认证类型](../reference/apis/js-apis-useriam-userauth.md#userauthtype8)和[认证等级](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)，获取认证对象。

3. 调用[start](../reference/apis/js-apis-useriam-userauth.md#start9)接口发起认证。

4. 通过调用[cancel](../reference/apis/js-apis-useriam-userauth.md#cancel9)接口取消本次认证。

    ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

    // 获取认证对象
    let auth;
    try {
        auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
        console.log("get auth instance success");
    } catch (error) {
        console.log("get auth instance failed" + error);
    }

    // 开始认证
    try {
        auth.start();
        console.info("authV9 start auth success");
    } catch (error) {
        console.info("authV9 start auth failed, error = " + error);
    }

    // 取消认证
    try {
        auth.cancel();
        console.info("cancel auth success");
    } catch (error) {
        console.info("cancel auth failed, error = " + error);
    }
    ```
