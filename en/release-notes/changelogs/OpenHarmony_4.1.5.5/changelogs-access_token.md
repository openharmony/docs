# Access Token Changelog
## cl.access_token.1 Change of permissionFlags in grantUserGrantedPermission and revokeUserGrantedPermission

**Access Level**

Public

**Reason for Change**

The values **0** and **4** of **permissionFlags** are deleted because they are not used in actual applications. 
In addition, error codes are returned, and the value **64** is added.

**Change Impact**

This change is a non-compatible change.
If the value **0** or **4** is passed in for **permissionFlags** in **grantUserGrantedPermission** or **revokeUserGrantedPermission**, an error code will be returned. You need to check for such cases, and pass in the correct value for **permissionFlags**.

**API level**

8

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

**grantUserGrantedPermission** and **revokeUserGrantedPermission** in @ohos.abilityAccessCtrl.d.ts.

**Adaptation Guide**

For details about the sample code, see [grantUserGrantedPermission](../../../application-dev/reference/apis-ability-kit/js-apis-abilityAccessCtrl-sys.md#grantusergrantedpermission) and [revokeUserGrantedPermission](../../../application-dev/reference/apis-ability-kit/js-apis-abilityAccessCtrl-sys.md#revokeusergrantedpermission).
