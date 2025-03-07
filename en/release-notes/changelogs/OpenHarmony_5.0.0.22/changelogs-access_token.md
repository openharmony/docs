# Access Token Changelog

## cl.access_token.1 Change of requestPermissionsFromUser

**Access Level**

Public

**Reason for Change**

If **requestPermissionsFromUser()** is called multiple times to request user authorization for the same permission, the authorization dialog box will be displayed multiple times and the user needs to grant or deny the permission each time.

**Change Impact**

This change is a non-compatible change.

Before the change:

Each time **requestPermissionsFromUser()** is called, the authorization dialog box will be displayed for the user to operate.

After the change:

Ehen **requestPermissionsFromUser()** is called to request the same permission for multiple times, the authorization dialog box will be displayed only once.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.22

**Key API/Component Changes**

**requestPermissionsFromUser** in @ohos.abilityAccessCtrl.d.ts

**Adaptation Guide**

See [requestPermissionsFromUser](../../../application-dev/reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9).
