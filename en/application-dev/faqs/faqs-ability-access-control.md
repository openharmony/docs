# Application Access Control Development

## Can the app listen for the permission change after its permission is modified in Settings?

Applicable to: OpenHarmony 3.1 Beta 5 (API version 9)

Third-party apps cannot listen for the permission change.

## Why is there no pop-up window displayed when an app applies for the **ohos.permission.LOCATION** permission?

Applicable to: OpenHarmony 3.2 Release (API version 9)

Applications developed using SDKs earlier than API version 9 can directly apply for the **ohos.permission.LOCATION** permission.
For the applications developed using the SDK of API version 9 or later, you need to apply for **ohos.permission.APPROXIMATELY_LOCATION** and then **ohos.permission.LOCATION**.

**References**

[Application Permission List](../security/permission-list.md#ohospermissionlocation)

## What can I do to prevent the application from crashing when the application is started again after the user denies the permission requested?

Applicable to: OpenHarmony SDK 3.2 Beta5

**Possible Causes**

-   If the permission required by a service is rejected by the user, the system directly returns the result and will no longer display a dialog box to request the permission.
-   If related judgment is not performed after the permission is requested, the application will be rejected due to lack of the corresponding permission when accessing the target object under permission control, and terminated unexpectedly.

**Solution**

1. Before allowing an application to call an API protected by certain permission, verify whether the application has the permission. If the application has the permission, the application can call the API. Otherwise, a dialog box is dipslayed to ask user authorization.

2. If the user rejects to grant the permission, ensure that other functions irrelevant to this permission are not affected.

3. When this service is triggered again by the user or to implement a service function, on-screen message shall be provided to guide the user to grant the permission in **Settings**.

**References**

[Access Control (Permission) Overview](../security/accesstoken-overview.md)

## What are the differences between **extensionAbilities** and **requestPermissions** in the **module.json5** file?

Applicable to: OpenHarmony SDK 3.2 Beta5

-   **requestPermissions**: specifies all the permissions required by an application for running. The permissions take effect only after being configured (declared) in the **module.json5** file.
-   **extensionAbilitie.permissions**: specifies the permissions customized by the ExtensionAbility component. These permissions are required when an application needs to access the ExtensionAbility component. **extensionAbilitie.permissions** is used for permission verification only. 

**References**

[module.json5 Configuration File](../quick-start/module-configuration-file.md)
