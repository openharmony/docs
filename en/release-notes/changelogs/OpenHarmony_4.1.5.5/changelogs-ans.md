# Event Notification Subsystem ChangeLog

## cl.ans.1 Permission Change of isRemoveAllowed

**Access Level**

System API

**Reason for Change**

Permission control is required for the **isRemoveAllowed** attribute of notifications.

**Change Impact**

This change is a non-compatible change.
To use the **isRemoveAllowed** attribute, you must first apply for **ohos.permission.SET_UNREMOVABLE_NOTIFICATION** permission.

**API Level**

11

**Change Since**

Openharmony SDK 4.1.5.5

**Key API/Component Changes**

isRemoveAllowed (ohos.permission.SET_UNREMOVABLE_NOTIFICATION)

**Adaptation Guide**


Apply for the **ohos.permission.SET_UNREMOVABLE_NOTIFICATION** permission before using the **isRemoveAllowed** attribute.
