# Access Control (Permission) Overview

AccessTokenManager (ATM) implements unified app permission management based on access tokens on OpenHarmony.

By default, apps can access limited system resources. However, in some cases, an app needs to access excess data (including personal data) and functions of the system or another app to implement extended functions. The system or apps must also share their data or functions through interfaces in an explicit manner. OpenHarmony uses app permissions to perform access control and prevent improper or malicious use of these data or functions.

App permissions are used to protect the following objects:

- Data: personal data (such as photos, contacts, calendar, and location), device data (such as device ID, camera, and microphone), and app data.
- Functions: device functions (such as making calls, sending SMS messages, and connecting to the Internet) and app functions (such as displaying windows and creating shortcuts).

Without the required permissions, an app cannot access or perform operations on the target object. Permissions must be clearly defined for apps. With well-defined app permissions, the system can standardize the behavior of apps and protect user privacy. Before an app accesses the target object, the target object verifies the app's permissions and denies the access if the app does not have required permissions.

Currently, ATM verifies app permissions based on the token identity (Token ID). A token ID identifies an app. The ATM manages app permissions based on the app's token ID.

## Basic Principles for Permission Management

Observe the following principles for permission management:

- Provide clear description about the app functions and scenarios for each permission required by the app so that users can clearly know why and when these permissions are required. Do not induce or mislead users' authorization. The permissions on an app must comply with the description provided in the app.
- Use the principle of least authority for user permissions. Allow only necessary permissions for service functions.
- When an app is started for the first time, avoid frequently displaying dialog boxes to request permissions. Allow the app to apply for permissions only when it needs to use the corresponding service functions.
- If a user rejects to authorize a permission, the user can still use functions irrelevant to this permission and can register and access the app.
- Provide no more message if a user rejects the authorization required by a function. Provide onscreen instructions to direct the user to grant the permission in **Settings** if the user triggers this function again or needs to use this function.

- All the permissions granted to apps must come from the [Application Permission List](permission-list.md). Custom permissions are not allowed for apps currently.

## Permission Workflow

Determine the permissions required for an app to access data or perform an operation. Declare the required permissions in the app installation package.

Determine whether the required permissions need to be authorized by users. If yes, provide a dialog box dynamically to request user authorization.

After the user grants permissions to the app, the app can access the data or perform the operation.

The figure below shows the permission workflow.

![](figures/figure1.png)

1. You can refer to the following figure to determine whether an app can apply for a permission.

![](figures/permission-application-process.png)

1. See [Permission Levels](#permission-levels) for details about the mapping between the application Ability Privilege Level (APL) and permission level.

2. The permission authorization modes include user_grant (permission granted by the user) and system_grant (permission granted by the system). For details, see [Permission Authorization Modes](#permission-authorization-mode).

3. A low-level app can have a high-level permission by using the Access Control List (ACL). For details, see [ACL](#acl).

## Permission Levels

To protect user privacy, ATM defines different permission levels based on the sensitivity of the data involved or the security threat of the ability.

### App APLs

The APL defines the priority of the app permission requested. Apps of different APLs can apply for permissions of different levels.

The table below describes the APLs.

| APL         | Description                                  |
| ---------------- | -------------------------------------- |
| system_core | The apps of this level provide core abilities of the operating system.|
| system_basic| The apps of this level provide basic system services.    |
| Normal      | The apps of this level are normal apps.                            |

By default, apps are of the normal APL.

For the app of the system_basic or system_core APL, declare the APL in the **apl** field of **bundle-info** in the app's profile when developing the application installation package.

Then, use the [hapsigner](hapsigntool-guidelines.md) tool to generate a certificate or use DevEco Studio to [have your app automatically signed](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465#section161281722111).

> **CAUTION**<br>The method of declaring the app's APL in its profile applies only to the application or service in debug phase. For a commercial app, apply for a release certificate and profile in the corresponding app market.

Example:

This example shows only the modification of the **apl** field. Set other fields based on service requirements.

```json
{
	"bundle-info" : {
		"developer-id": "OpenHarmony",
		"development-certificate": "Base64 string",
		"distribution-certificate": "Base64 string",
		"bundle-name": "com.OpenHarmony.app.test",
		"apl": "system_basic",
        "app-feature": "hos_normal_app"
	},
}
```

### Levels of Permissions

The permissions open to apps vary with the permission level. The permission levels include the following in ascending order of seniority.

- **normal**

    The normal permission allows access to common system resources beyond the default rules. Access to these system resources (including data and functions) has minor risks on user privacy and other apps.

    The permissions of this level are available only to apps of the normal or higher APL.

- **system_basic**

    The system_basic permission allows access to resources related to basic operating system services. The basic services are basic functions provided or preconfigured by the system, such as system setting and identity authentication. Access to these resources may have considerable risks to user privacy and other apps.

    The permissions of this level are available only to apps of the system_basic or system_core APL.

- **system_core**

    The system_core permission allows access to core resources of the operating system. These resources are the underlying core services of the system. If these resources are corrupted, the OS cannot run properly.
    
    The permissions of this type are not open to any app currently.

## Permission Authorization Modes

Permissions can be classified into the following types based on the authorization mode:

- **system_grant**

   The app permissions are authorized by the system. This type of apps cannot access user or device sensitive information. The allowed operations have minor impact on the system or other apps.

    For a system_grant app, the system automatically grants the required permissions to the app when the app is installed. The system_grant permission list must be presented to users on the details page of the app in the app store.

- **user_grant**

    The app permissions must be authorized by users. This type of apps may access user or device sensitive information. The allowed operations may have a critical impact on the system or other apps.

    This type of permissions must be declared in the app installation package and authorized by users dynamically during the running of the app. The app has the permission only after user authorization.

    For example, in the [Application Permission List](permission-list.md), the permissions for the microphone and camera are user_grant. The list provides reasons for using the permissions.

    The user_grant permission list must also be presented on the details page of the app in the app store.

### Authorization Processes

The process for an app obtaining the required permissions varies depending on the permission authorization mode.

- For a system_grant permission, you need to [declare the permission](accesstoken-guidelines.md#declaring-permissions) in the configuration file. The permission will be pre-granted when the app is installed.

- For a user_grant permission, you need to [declare the permission](accesstoken-guidelines.md#declaring-permissions) in the configuration file and trigger user authorization through a dialog box during the running of the app.

### Permission Authorization Process (user_grant)

The procedure is as follows:

1. In the configuration file, declare the permissions required by the app. For details, see [Access Control Development](accesstoken-guidelines.md).

2. Associate the object that requires the permissions in the app with the target permissions. In this way, the user knows the operations to be granted with the specified permissions.

3. Check whether the user has granted the required permissions to the app when the app is running. If yes, the app can access the data or perform the operation. If the user has not granted the permissions to the app, display a dialog box requesting the user authorization when the app attempts to access the data.

4. Check the user authorization result. Allow the next step only after the user has granted the permissions to the app.

**Precautions**

- Check the app's permission each time before the operation requiring the permission is performed.
- To check whether a user has granted specific permissions to your app, use the [verifyAccessToken](../reference/apis/js-apis-abilityAccessCtrl.md) method. This method returns [PERMISSION_GRANTED](../reference/apis/js-apis-abilityAccessCtrl.md) or [PERMISSION_DENIED](../reference/apis/js-apis-abilityAccessCtrl.md). For details about the sample code, see [Access Control Development](accesstoken-guidelines.md).
- Users must be able to understand and control the authorization of user_grant permissions. During the running process, the app requiring user authorization must proactively call the API to dynamically request the authorization. Then, the system displays a dialog box asking the user to grant the requested permission. The user will determine whether to grant the permission based on the running context of the app.
- The permission authorized is not permanent, because the user may revoke the authorization at any time. Therefore, even if the user has granted the requested permission to the app, the app must check for the permission before calling the API controlled by this permission.

## ACL

As described above, permission levels and app APLs are in one-to-one correspondence. In principle, **an app with a lower APL cannot apply for higher permissions by default**.

The ACL makes low-level apps have high-level permissions.

**Example**

The APL of app A is normal. App A needs to have permission B (system_basic level) and permission C (normal level).

In this case, you can use the ACL to grant permission B to app A.

For details, see [Using the ACL](#using-the-acl).
For details about whether a permission can be enabled through the ACL, see the [Application Permission List](permission-list.md).

### Using the ACL

If the permission required by an app has higher level than the app's APL, you can use the ACL to grant the permissions required.

In addition to the preceding [authorization processes](#authorization-processes), you must declare the ACL.

In other words, in addition to declaring the required permissions in the app's configuration file, you must declare the permissions higher than the app's APL [using the ACL](accesstoken-guidelines.md#declaring-the-acl) in the app's profile. The subsequent steps of authorization are the same.

**NOTICE**

When developing an app installation package, you must declare the allowed ACLs in the **acls** field in the app's profile. Then, use the [hapsigner](hapsigntool-guidelines.md) tool to generate a certificate.

> **CAUTION**<br>The method of declaring the app's APL in its profile applies only to the application or service in debug phase. For a commercial app, apply for a release certificate and profile in the corresponding app market.

```json
{
    "acls": {
        "allowed-acls": [
            "ohos.permission.PERMISSION"
        ]
    },
}
```
