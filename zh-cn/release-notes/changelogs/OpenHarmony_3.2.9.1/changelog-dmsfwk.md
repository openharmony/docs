# 分布式调度子系统ChangeLog

## cl.DistributedManagerService.1 continuationManager接口新增DATASYNC权限校验

此前版本continuationManager接口未对调用方进行校验，不符合OpenHarmony的API接口规范。
已做出以下变更：调用方使用continuationManager前需提前申请"ohos.permission.DISTRIBUTED_DATASYNC"权限。

**变更影响**

基于此前版本开发的应用，需提前申请"ohos.permission.DISTRIBUTED_DATASYNC"权限，否则会影响原有业务逻辑。

**关键的接口/组件变更**

涉及接口

  - continuationManager.registerContinuation;
  - continuationManager.on;
  - continuationManager.off;
  - continuationManager.unregisterContinuation;
  - continuationManager.updateContinuationState;
  - continuationManager.startContinuationDeviceManager;
