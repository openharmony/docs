# 包管理子系统ChangeLog

## cl.bundlemanager.1 包管理分布式查询模块名称变更，由ohos.bundle.distributedBundle变更为ohos.bundle.distributedBundleManager，接口未发生变更。

API9的包管理分布式查询模块名称变更，由ohos.bundle.distributedBundle变更为[ohos.bundle.distributedBundleManager](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.distributedBundleManager.d.ts)，接口未发生变更。

**变更影响**<br>
对原有使用API version 9之前的应用无影响，使用API version 9的应用需要适配新模块。

**关键的接口/组件变更**<br>
包管理分布式查询模块名称由ohos.bundle.distributedBundle修改为ohos.bundle.distributedBundleManager，接口未发生变更。

**适配指导**<br>
原有导入模块@ohos.bundle.distributedBundle代码需要修改为@ohos.bundle.distributedBundleManager。
```ts
import distributedBundle form '@ohos.bundle.distributedBundleManager';
```
