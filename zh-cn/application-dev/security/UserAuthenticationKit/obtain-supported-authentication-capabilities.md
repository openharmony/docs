# 查询支持的认证能力


不同的设备对于认证能力（人脸、指纹、口令）的支持性各有差异，开发者在发起认证前应当先查询当前设备支持的用户认证能力。


## 接口说明

具体参数、返回值、错误码等描述，请参考对应的[API文档](../../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetavailablestatus9)。

| 接口名称 | 功能描述 | 
| -------- | -------- |
| getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void | 根据指定的认证类型、认证等级，检测当前设备是否支持相应的认证能力。 | 


## 开发步骤

1. [申请权限](prerequisites.md#申请权限)：ohos.permission.ACCESS_BIOMETRIC。

2. 指定认证类型（UserAuthType）和认证等级（AuthTrustLevel），调用[getAvailableStatus](../../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetavailablestatus9)接口查询当前的设备是否支持相应的认证能力。

以查询设备是否支持认证可信等级≥ATL1的人脸认证功能为例：

```ts
import userIAM_userAuth from '@ohos.userIAM.userAuth'; 

// 查询认证能力是否支持
try {    
    userIAM_userAuth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);    
    console.info('current auth trust level is supported');
} catch (error) {
    const err: BusinessError = error as BusinessError;
    console.info('current auth trust level is not supported. Code is ${err.code}, message is ${err.message}');
}
```
