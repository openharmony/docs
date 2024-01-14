# Application Access Control Development


## Can the app listen for the permission change made in Settings? (API version 9)

Third-party apps cannot listen for the permission change.


## Why is there no window displayed when an app applies for the ohos.permission.LOCATION permission? (API version 9)

The apps developed using SDKs earlier than API version 9 can apply for the **ohos.permission.LOCATION** permission without user authorization.

The apps developed using the SDK of API version 9 or later must have the **ohos.permission.APPROXIMATELY_LOCATION** permission before applying for **ohos.permission.LOCATION**.

**References**

[ohos.permission.LOCATION](../security/AccessToken/permissions-for-all.md#ohospermissionlocation)


## What can I do to prevent the app from crashing when it is started again after the user denies the permission requested? (API version 9)

**Possible Causes**

- If the permission required by a service is rejected by the user, the system directly returns the result and will no longer display a dialog box to request the permission.

- If related judgment is not performed after the permission is requested, the application will be rejected due to lack of the corresponding permission when accessing the target object under permission control, and terminated unexpectedly.

**Solution**

1. Before allowing an application to call an API protected by certain permission, verify whether the application has the permission. If the application has the permission, the application can call the API. Otherwise, a dialog box is displayed to ask user authorization.

2. If the user rejects to grant the permission, ensure that other functions irrelevant to this permission are not affected.

3. When this service is triggered again by the user or to implement a service function, on-screen message shall be provided to guide the user to grant the permission in **Settings**.

**References**

[Application Permission Management Overview](../security/AccessToken/access-token-overview.md)

## What are the differences between extensionabilities and requestpermissions in the module.json5 file? (API version 9)

- **requestPermissions**: specifies all the permissions required by an application for running. The permissions take effect only after being configured (declared) in the **module.json5** file.

- **extensionAbilitie.permissions**: specifies the permissions customized by the ExtensionAbility component. These permissions are required when an application needs to access the ExtensionAbility component. **extensionAbilitie.permissions** is used for permission verification only. 

**References**

[module.json5 Configuration File](../quick-start/module-configuration-file.md)
