# Application Access Control Changelog

## cl.sucurity_access_token.1 Changes in atManager.on and atManager.off

**Change Impact**

The applications developed based on earlier versions are not affected.

**Key API/Component Changes**

Involved APIs:

interface/sdk-js/api/@ohos.abilityAccessCtrl.d.ts:

atManager.on

atManager.off

After the change:

- Multiple callbacks can be registered for the same **tokenIDList** and **permissionList**.


- A callback cannot be registered if **tokenIDList** and **permissionList** have common values with those of a callback registered.


- If no callback is passed in **atManager.off**, all callbacks for **tokenIDList** and **permissionList** will be unregistered.


## cl.sucurity_access_token.2 Changes in privacyManager.on and privacyManager.off

**Change Impact**

The applications developed based on earlier versions are not affected.

**Key API/Component Changes**

Involved APIs:

interface/sdk-js/api/@ohos.privacyManager.d.ts:

privacyManager.on

privacyManager.off

After the change:

- Multiple callbacks can be registered for the same **permissionList**.

- A callback cannot be registered if **permissionList** has common values with that of a callback registered.

- If no callback is passed in **privacyManager.off**, all callbacks for **permissionList** will be unregistered.
