# 用户认证开发指导

> **说明：**
> 该开发指导需配合API version 10版本的SDK使用。

## 场景介绍

当前用户认证支持Pin码认证、人脸识别和指纹识别，可应用于设备解锁、应用登录、支付等身份认证场景。

## 接口说明

userIAM_userAuth模块提供了用户认证的相关方法，包括查询认证能力、发起认证和取消认证等，用户可以使用人脸、指纹等生物特征信息进行认证操作。具体接口说明可以查阅[API参考文档](../reference/apis/js-apis-useriam-userauth.md)。

在执行认证前，需要指定[认证类型](../reference/apis/js-apis-useriam-userauth.md#userauthtype8)和[认证等级](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)，查询设备是否支持该认证能力。

**表1** 用户认证开放能力列表

| 接口名称    | 功能描述                |
| ---------- | ----------------------- |
| getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void | 根据指定的认证类型、认证等级，检测当前设备是否支持相应的认证能力。 |
| getUserAuthInstance(authParam: AuthParam, widgetParam: WidgetParam): UserAuthInstance | 获取UserAuthInstance对象，用于执行用户身份认证，并支持使用统一用户身份认证组件。 |
| on(type: 'result', callback: IAuthCallback): void | 订阅用户身份认证结果。 |
| off(type: 'result', callback?: IAuthCallback): void | 取消订阅用户身份认证结果。 |
| start(): void | 执行用户认证。        |
| cancel(): void | 取消本次认证操作。    |

**表2** 用户身份认证可信等级划分原则

| 确认用户身份的认证可信等级 | 认证能力指标                      | 说明&举例                                                    | 可支撑的典型业务场景                                 |
| -------------------------- | --------------------------------- | ------------------------------------------------------------ | ---------------------------------------------------- |
| ATL4                       | FRR=10%时，FAR≤0.0003%，SAR≤3%    | 能高精度地识别用户个体，有很强的活体检测能力，如采用了安全键盘的PIN码认证和有特殊安全增强的指纹与3D人脸认证。 | 小额支付                                             |
| ATL3                       | FRR=10%时，FAR≤0.002%，SAR≤7%     | 能精确识别用户个体，有较强的活体检测能力，如有特殊安全增强的2D人脸认证。 | 设备解锁                                             |
| ATL2                       | FRR=10%时，FAR≤0.002%，7%<SAR≤20% | 能精确识别用户个体，有一定的活体检测能力，如基于普通测距和佩戴检测的手表作为可信持有物的认证。 | 维持设备解锁状态、应用登录                           |
| ATL1                       | FRR=10%时，FAR≤1%，7%<SAR≤20%     | 能识别用户个体，有一定的活体检测能力，如声纹认证。           | 业务风控、一般个人数据查询、精准业务推荐、个性化服务 |


## 查询当前设备是否支持相应的认证能力

### 开发步骤

1. 申请权限。调用[getAvailableStatus](../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetavailablestatus9)接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息请参考[Stage模型应用程序包结构](../quick-start/module-configuration-file.md)。

2. 查询认证能力之前需要录入口令/指纹/人脸相关特征。指定[认证类型](../reference/apis/js-apis-useriam-userauth.md#userauthtype8)和[认证等级](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)，调用[getAvailableStatus](../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetavailablestatus9)接口查询当前的设备是否支持相应的认证能力。

    ```ts
    import userIAM_userAuth from '@ohos.userIAM.userAuth';
    
    // 查询认证能力是否支持
    try {
        userIAM_userAuth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
        console.info('current auth trust level is supported');
    } catch (error) {
        console.info('current auth trust level is not supported, error = ' + error);
    }
    ```

## 执行认证操作并订阅认证结果

### 开发步骤

1. 申请权限。调用[start](../reference/apis/js-apis-useriam-userauth.md#start10)接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息请参考[Stage模型应用程序包结构](../quick-start/module-configuration-file.md)。

2. 指定challenge、[认证类型](../reference/apis/js-apis-useriam-userauth.md#userauthtype8)和[认证等级](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)，获取认证对象。

3. 调用[on](../reference/apis/js-apis-useriam-userauth.md#on10)接口订阅认证结果。

4. 调用[start](../reference/apis/js-apis-useriam-userauth.md#start10)接口发起认证，通过[onResult](../reference/apis/js-apis-useriam-userauth.md#onresult10)回调返回认证结果。

    ```ts
    import userIAM_userAuth from '@ohos.userIAM.userAuth';
    
    const authParam : userIAM_userAuth.AuthParam = {
      challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
      authType: [userIAM_userAuth.UserAuthType.PIN],
      authTrustLevel: userIAM_userAuth.AuthTrustLevel.ATL1,
    };
    const widgetParam : userIAM_userAuth.WidgetParam = {
      title: '请输入密码',
    };
    try {
      //获取认证对象
      let userAuthInstance = userIAM_userAuth.getUserAuthInstance(authParam, widgetParam);
      console.log('get userAuth instance success');
      //订阅认证结果
      userAuthInstance.on('result', {
        onResult (result) {
          console.log('userAuthInstance callback result = ' + JSON.stringify(result));
        }
      });
      console.log('auth on success');
      userAuthInstance.start();
      console.log('auth start success');
    } catch (error) {
      console.log('auth catch error: ' + JSON.stringify(error));
    }
    ```

5. 如果业务需要取消订阅认证结果，可以使用已经成功订阅事件的[UserAuthInstance](../reference/apis/js-apis-useriam-userauth.md#userauthinstance10)对象调用[off](../reference/apis/js-apis-useriam-userauth.md#off10)接口进行取消订阅。

   ```ts
   import userIAM_userAuth from '@ohos.userIAM.userAuth';
   
   const authParam : userIAM_userAuth.AuthParam = {
     challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
     authType: [userIAM_userAuth.UserAuthType.PIN],
     authTrustLevel: userIAM_userAuth.AuthTrustLevel.ATL1,
   };
   const widgetParam : userIAM_userAuth.WidgetParam = {
     title: '请输入密码',
   };
   try {
     //获取认证对象
     let userAuthInstance = userIAM_userAuth.getUserAuthInstance(authParam, widgetParam);
     console.log('get userAuth instance success');
     //取消订阅认证结果
     userAuthInstance.off('result', {
       onResult (result) {
         console.log('auth off result: ' + JSON.stringify(result));
       }
     });
     console.log('auth off success');
   } catch (error) {
     console.log('auth catch error: ' + JSON.stringify(error));
   }
   ```

## 认证过程中取消认证

### 开发步骤

1. 申请权限。调用[cancel](../reference/apis/js-apis-useriam-userauth.md#cancel10)接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息请参考[Stage模型应用程序包结构](../quick-start/module-configuration-file.md)。

2. 指定challenge、[认证类型](../reference/apis/js-apis-useriam-userauth.md#userauthtype8)和[认证等级](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)，获取认证对象。

3. 调用[start](../reference/apis/js-apis-useriam-userauth.md#start10)接口发起认证。

4. 通过使用已经成功发起认证的调用[UserAuthInstance](../reference/apis/js-apis-useriam-userauth.md#userauthinstance10)对象调用[cancel](../reference/apis/js-apis-useriam-userauth.md#cancel10)接口取消本次认证。

    ```ts
    import userIAM_userAuth from '@ohos.userIAM.userAuth';
    
    const authParam : userIAM_userAuth.AuthParam = {
      challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
      authType: [userIAM_userAuth.UserAuthType.PIN],
      authTrustLevel: userIAM_userAuth.AuthTrustLevel.ATL1,
    };
    const widgetParam : userIAM_userAuth.WidgetParam = {
      title: '请输入密码',
    };
    try {
      //获取认证对象
      let userAuthInstance = userIAM_userAuth.getUserAuthInstance(authParam, widgetParam);
      console.log('get userAuth instance success');
      //开始认证
      userAuthInstance.start();
      console.log('auth start success');
      // 取消认证
      userAuthInstance.cancel();
      console.log('auth cancel success');
    } catch (error) {
      console.log('auth catch error: ' + JSON.stringify(error));
    }
    ```
