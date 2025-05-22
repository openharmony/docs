# ArkData Changelog

## cl.arkdata.1 Change of setAppShareOptions, removeAppShareOptions, and DRAG in UDMF @ohos.data.unifiedDataChannel.d.ts to Public APIs

**Access Level**

System API -> Public API

**Reason for the Change**

The APIs for setting or removing the drag scope of the application data should be open to third-party applications.

**Change Impact**

This change is a non-compatible change.

Before the change:<br>**SetAppShareOptions()**, **RemoveAppShareOptions()**, and **DRAG** are system APIs and can be called only by system applications. The ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION is not verified when an application sets or deletes the drag scope of the application data.

After the change:<br>**SetAppShareOptions()**, **RemoveAppShareOptions()**, and **DRAG** are public APIs, which can be called by normal applications with the ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION permission. If the application does not have this permission, access to these APIs will be rejected.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.2.58

**Key API/Component Changes**

1. function setAppShareOptions(intention: Intention, shareOptions: ShareOptions): void;

2. function removeAppShareOptions(intention: Intention): void;

3. DRAG = 'Drag'

**Adaptation Guide**

The application must have the ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION permission. For details, see [Requesting Restricted Permissions](../../../application-dev/security/AccessToken/declare-permissions-in-acl.md).

