# 用户认证开发指导

> **说明：**
> 该开发指导需配合API Version 8或以上版本的SDK使用。

## 场景介绍

当前用户认证支持人脸识别和指纹识别，可应用于设备解锁、应用登录、支付等身份认证场景。

## 接口说明

userIAM_userAuth模块提供了用户认证的相关方法，包括查询认证能力、发起认证和取消认证等，用户可以使用人脸、指纹等生物特征信息进行认证操作。具体接口说明可以查阅[API参考](../reference/apis/js-apis-useriam-userauth.md)。

在执行认证前，需要指认证类型和认证等级，查询设备是否支持该认证能力。如果不支持，需要考虑使用其他认证能力。

**表1** 用户认证开放能力列表

| 接口名称                                                       | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getVersion() : number                                        | 获取认证对象的版本信息。                                     |
| getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number | 根据指定的认证类型、认证等级，检测当前设备是否支持相应的认证能力。 |
| auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array | 执行用户认证，使用callback方式作为异步方法返回结果。                 |
| cancelAuth(contextID : Uint8Array) : number                  | 通过contextID取消本次认证操作。                              |

## 获取认证对象的版本信息

### 开发步骤

1. 申请权限。调用getVersion接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[应用包结构配置文件的说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/stage-structure.md)。

2. 获取认证对象。

3. 调用getVersion接口获取版本信息。

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth'

let auth = new userIAM_userAuth.UserAuth();
let version = auth.getVersion();
console.info("auth version = " + version);
```

## 查询当前设备是否支持相应的认证能力

### 开发步骤

1. 申请权限。调用getAvailableStatus接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[应用包结构配置文件的说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/stage-structure.md)。

2. 获取认证对象。

3. 指定认证类型和认证等级，调用getAvailableStatus接口查询当前的设备是否支持相应的认证能力。

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth'

let auth = new userIAM_userAuth.UserAuth();
let checkCode = auth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
if (checkCode == userIAM_userAuth.ResultCode.SUCCESS) {
    console.info("check auth support success");
    // 此处添加支持相应认证能力的逻辑
} else {
    console.error("check auth support fail, code = " + checkCode);
    // 此处添加不支持相应认证能力的逻辑
}
```

## 执行认证操作

### 开发步骤

1. 申请权限。调用auth接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[应用包结构配置文件的说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/stage-structure.md)。

2. 获取认证对象。

3. 指定认证类型和认证等级，调用auth接口发起认证，通过onResult回调返回认证结果，通过onAcquireInfo回调返回认证过程中的提示信息。

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth'

let auth = new userIAM_userAuth.UserAuth();
auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
    onResult: (result, extraInfo) => {
        try {
            console.info("auth onResult result = " + result);
            console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
            if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                // 此处添加认证成功逻辑
            }  else {
                // 此处添加认证失败逻辑
            }
        } catch (e) {
            console.info("auth onResult error = " + e);
        }
    },

    onAcquireInfo: (module, acquire, extraInfo) => {
        try {
            console.info("auth onAcquireInfo module = " + module);
            console.info("auth onAcquireInfo acquire = " + acquire);
            console.info("auth onAcquireInfo extraInfo = " + JSON.stringify(extraInfo));
        } catch (e) {
            console.info("auth onAcquireInfo error = " + e);
        }
    }
});
```

## 认证过程中取消认证

### 开发步骤

1. 申请权限。调用cancelAuth接口，需要在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[应用包结构配置文件的说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/stage-structure.md)。

2. 获取认证对象。

3. 指定认证类型和认证等级，调用auth接口发起认证，通过onResult回调返回认证结果，通过onAcquireInfo回调返回认证过程中的提示信息。

4. 通过调用cancelAuth接口取消本次认证。

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth'

let auth = new userIAM_userAuth.UserAuth();
// contextId通过auth接口获取
let contextId = auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
    onResult: (result, extraInfo) => {
        console.info("auth onResult result = " + result);
    },

    onAcquireInfo: (module, acquire, extraInfo) => {
        console.info("auth onAcquireInfo module = " + module);
    }
});
let cancelCode = auth.cancelAuth(contextId);
if (cancelCode == userIAM_userAuth.ResultCode.SUCCESS) {
    console.info("cancel auth success");
} else {
    console.error("cancel auth fail");
}
```
