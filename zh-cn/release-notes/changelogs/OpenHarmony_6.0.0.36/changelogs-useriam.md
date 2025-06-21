# 用户IAM子系统Changelog

## cl.useriam.1 @ohos.useriam.userAuth限制应用从后台发起带交互界面的身份认证变更

**访问级别**

公开接口

**变更原因**

需要限制应用从后台发起带交互界面的身份认证。

**变更影响**

此变更涉及应用适配。

变更前：应用申请了权限ohos.permission.ACCESS_BIOMETRIC，可以从前台和后台调用start()发起身份认证。

变更后：如果需要从后台调用start()发起认证，需要申请系统权限ohos.permission.USER_AUTH_FROM_BACKGROUND。

**起始 API Level**

10

**变更发生版本**

从OpenHarmony SDK 6.0.1.2开始。

**变更的接口/组件**

start(): void;

变更前：
```ts
 * @permission ohos.permission.ACCESS_BIOMETRIC
     * @throws { BusinessError } 201 - Permission verification failed.
    start(): void;
```
变更后：
```ts
 * @permission ohos.permission.ACCESS_BIOMETRIC or ohos.permission.USER_AUTH_FROM_BACKGROUND
     * @throws { BusinessError } 201 - Permission verification failed. Possible causes:
     * <br>1. No permission to access biometric.
     * <br>2. No permission to start authentication from background.
    start(): void;
```

**适配指导**

不涉及从后台调用start()发起身份认证场景，无需适配。

如果涉及从后台调用start()发起身份认证，系统应用需要申请系统权限ohos.permission.USER_AUTH_FROM_BACKGROUND；三方应用不能从后台发起身份认证。
