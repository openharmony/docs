# Distributed Scheduler Subsystem ChangeLog

## cl.DistributedManagerService.1 Adding DATASYNC Permission Verification on the continuationManager API

In earlier versions, the **continuationManager** API does not verify the caller, which does not comply with the OpenHarmony API specifications.
Now, before using **continuationManager**, the caller must apply for the **ohos.permission.DISTRIBUTED_DATASYNC** permission.

**Change Impacts**

The application developed based on earlier versions needs to apply for the **ohos.permission.DISTRIBUTED_DATASYNC** permission in advance. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

Involved APIs:

  - continuationManager.registerContinuation;
  - continuationManager.on;
  - continuationManager.off;
  - continuationManager.unregisterContinuation;
  - continuationManager.updateContinuationState;
  - continuationManager.startContinuationDeviceManager;
