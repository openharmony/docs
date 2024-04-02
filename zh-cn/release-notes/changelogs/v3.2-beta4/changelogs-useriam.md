# 用户IAM子系统Changelog

## cl.useriam.1 API异常处理方式变更

用户IAM部分接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。从API9开始作以下变更：

接口通过抛出异常的方式返回错误信息。

**变更影响**

基于此版本以前开发的应用不受影响，以后的需适配变更接口的错误信息返回方式，否则会影响业务逻辑。

**关键接口/组件变更**

为适配统一的API异常处理方式，对用户IAM相关接口进行废弃（下表中 原接口 列内容），并新增对应接口（下表中 新接口 列内容）。新增接口支持统一的错误码异常处理规范，功能上与原接口保持一致。

|   模块名      |     类名     |     方法/属性/枚举/常量      |    变更类型     |
| ---------------------- | ------------------- | ------------------------- | ------------------------ |
| ohos.userIAM.userAuth | UserAuth | constructor() | 废弃 |
| ohos.userIAM.userAuth | UserAuth | getVersion() : number | 废弃 |
| ohos.userIAM.userAuth | UserAuth | getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number | 废弃 |
| ohos.userIAM.userAuth | UserAuth | auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array | 废弃 |
| ohos.userIAM.userAuth | UserAuth | cancelAuth(contextID : Uint8Array) : number | 废弃 |
| ohos.userIAM.userAuth | IUserAuthCallback | onResult: (result : number, extraInfo : AuthResult) => void | 废弃 |
| ohos.userIAM.userAuth | IUserAuthCallback | onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void | 废弃 |
| ohos.userIAM.userAuth | AuthResult | AuthResult {</br>token ?: Uint8Array; </br>remainTimes ?: number; </br>freezingTime ?: number;} | 废弃 |
| ohos.userIAM.userAuth | 枚举 | ResultCode {</br>SUCCESS = 0, </br>FAIL = 1, </br>GENERAL_ERROR = 2, </br>CANCELED = 3, </br>TIMEOUT = 4, </br>TYPE_NOT_SUPPORT = 5, </br>TRUST_LEVEL_NOT_SUPPORT = 6, </br>BUSY = 7, </br>INVALID_PARAMETERS = 8, </br>LOCKED = 9, </br>NOT_ENROLLED = 10,} | 废弃 |
| ohos.userIAM.userAuth | type | AuthEventKey = "result" | 新增 |
| ohos.userIAM.userAuth | type | EventInfo = AuthResultInfo | 新增 |
| ohos.userIAM.userAuth | AuthResultInfo | AuthResultInfo {</br>result : number; </br>token ?: Uint8Array; </br>remainAttempts ?: number; </br>lockoutDuration ?: number;} | 新增 |
| ohos.userIAM.userAuth | TipInfo | TipInfo {</br>module : number; </br>tip : number;} | 新增 |
| ohos.userIAM.userAuth | AuthInstance | AuthInstance {</br>on: (name: AuthEventKey, callback: AuthEvent) => void; </br>off: (name: AuthEventKey) => void; </br>start: () => void; </br>cancel: () => void;} | 新增 |
| ohos.userIAM.userAuth | 枚举 | ResultCodeV9 {</br>SUCCESS = 12500000, </br>FAIL = 12500001, </br>GENERAL_ERROR = 12500002, </br>CANCELED = 12500003, </br>TIMEOUT = 12500004, </br>TYPE_NOT_SUPPORT = 12500005, </br>TRUST_LEVEL_NOT_SUPPORT = 12500006, </br>BUSY = 12500007, </br>LOCKED = 12500009, </br>NOT_ENROLLED = 12500010,} | 新增 |
| ohos.userIAM.userAuth | function | getAuthInstance(challenge : Uint8Array, authType : UserAuthType, authTrustLevel : AuthTrustLevel) : AuthInstance | 新增 |
| ohos.userIAM.userAuth | function | getVersion() : number | 新增 |
| ohos.userIAM.userAuth | function | getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : void | 新增 |
| ohos.userIAM.faceAuth | FaceAuthManager | setSurfaceId(surfaceId : string) : ResultCode | 删除 |
| ohos.userIAM.faceAuth | 枚举 | ResultCode {</br>SUCCESS = 0, </br>FAIL = 1,} | 删除 |
| ohos.userIAM.faceAuth | FaceAuthManager | setSurfaceId(surfaceId: string) : void | 新增 |

**适配指导**

以getVersion接口为例，示例代码如下：

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

try {
    let version = userIAM_userAuth.getVersion();
    console.info("auth version = " + version);
} catch (error) {
    console.info("get version failed, error = " + error);
}
```

更多接口的示例代码可参考[用户认证API文档](../../../application-dev/reference/apis/js-apis-useriam-userauth.md)和[人脸认证API文档](../../../application-dev/reference/apis/js-apis-useriam-faceauth.md)。

## cl.useriam.2 接口调用权限变更

用户IAM部分接口只允许被系统应用调起，需要做系统应用运行时鉴权。从API9开始作以下变更：

人脸认证模块的setSurfaceId接口增加判别是否为系统应用的逻辑，非系统应用无法调用该接口。

**变更影响**

基于此版本以前开发的应用不受影响，以后的需要持有相应权限，否则无法正常调用接口。

**关键接口/组件变更**

setSurfaceId接口的实现中增加系统应用鉴权处理，非系统应用调用将返回202错误码。

**适配指导**

需要修改[应用签名](https://gitee.com/openharmony/developtools_hapsigner/tree/master/dist)相关文件UnsgnedReleasedProfileTemplate.json，其中的app-feature字段要改为"hos_system_app"，才可保证签名所得到的应用是系统应用。
