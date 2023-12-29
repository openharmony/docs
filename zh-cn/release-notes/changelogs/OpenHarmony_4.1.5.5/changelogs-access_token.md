# 程序访问子系统变更说明
## cl.access_token.1 grantUserGrantedPermission、revokeUserGrantedPermission接口入参：permissionFlags变更

**访问级别**

公开接口

**变更原因**

原可选授权选项中，0表示未经用户设置、4表示系统设置；正常使用情况下应用不存在使用这两种授权选项值的授权情况；
去除不符合使用场景规范的选项值0、4，并在底层进行管控返回错误码；新增仅本次允许选项值：64。

**变更影响**

该变更为非兼容性变更。
原使用grantUserGrantedPermission、revokeUserGrantedPermission接口授予或取消授予权限的应用，错误传入了0、4授权选项值，会被拦截并返回错误码，需要应用整改不合理场景，根据实际使用场景传入正确permissionFlags值：

**API level**

8

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

@ohos.abilityAccessCtrl.d.ts中 grantUserGrantedPermission、revokeUserGrantedPermission接口。

**适配指导**

接口使用的示例代码可参考[requestPermissionsFromUser接口指导](../../../application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)
