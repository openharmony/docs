# Pasteboard Subsystem Changelog

## cl.pasteboard.1 Change of the SetAppShareOptions() and RemoveAppShareOptions() APIs from System APIs to Public APIs

**Access Level**

Public API

**Reason for Change**

The ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION permission is now required for third-party applications to set or delete the pasteable range of pasteboard data.

**Change Impact**

This change is a non-compatible change.

Before change:<br>**SetAppShareOptions()** and **RemoveAppShareOptions()** are system APIs and can be called only by system applications. ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION is not verified when an application sets or deletes the pasteable range of pasteboard data.

After change<br>**SetAppShareOptions()** and **RemoveAppShareOptions()** are public APIs and can be called by both third-party applications and system applications that have obtained the required permissions. Without the ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION permission, third-party applications will be intercepted when setting or deleting the pasteable range of pasteboard data.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.2.52

**Key API/Component Changes**

SetAppShareOptions()/pasteboard_service
RemoveAppShareOptions()/pasteboard_service

**Adaptation Guide**

Declare ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION in **module.json** of third-party applications as required. The sample code is as follows:
```ts
"requestPermissions": [
  {
    "name": "ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION"
  }
]
```
