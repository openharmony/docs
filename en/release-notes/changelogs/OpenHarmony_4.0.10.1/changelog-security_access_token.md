# Application Access Control Subsystem Changelog

## cl.sucurity_access_token.1 Changes in the Event Subscription and Cancellation APIs

**Change Impact**

The applications developed based on earlier versions are not affected.

**Key API/Component Changes**

Involved APIs:
interface/sdk-js/api/@ohos.abilityAccessCtrl.d.ts:

atManager.on

atManager.off

From this version:

Multiple callbacks can be registered if **tokenIDList** and **permissionList** are the same.

The same callback cannot be registered if **tokenIDList** or **permissionList** are overlapped.

If callback is not passed in **atManager.off**, all callbacks under **tokenIDList** and **permissionList** will be unregistered.
