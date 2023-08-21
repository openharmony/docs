# 程序访问控制子系统ChangeLog

## cl.sucurity_access_token.1 事件订阅与事件取消接口变更

**变更影响**

基于此前版本开发的应用，向上兼容

**关键接口/组件变更**

涉及接口：
interface/sdk-js/api/@ohos.privacyManager.d.ts:

privacyManager.on

privacyManager.off

变更后：

允许相同permissionList订阅多个callback。

不允许存在交集的permissionList订阅相同callback。

取消订阅不传callback时，批量删除permissionList下面的所有callback。
