# Application Access Control Subsystem Changelog

## cl.sucurity_access_token.1 Changes in the Event Subscription and Cancellation APIs

**Change Impact**

The applications developed based on earlier versions are not affected.

**Key API/Component Changes**

Involved APIs:
interface/sdk-js/api/@ohos.privacyManager.d.ts:

privacyManager.on

privacyManager.off

From this version:

Multiple callbacks can be registered if **permissionList** is the same.

The same callback cannot be registered if **tokenIDList** is overlapped.

If callback is not passed in **privacyManager.off**, all callbacks under **permissionList** will be unregistered.
