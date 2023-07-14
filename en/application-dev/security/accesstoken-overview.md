# Access Control (Permission) Overview

OpenHarmony AccessTokenManager (ATM) implements unified management of application permissions based on access tokens.

By default, applications can access limited system resources. However, to provide extended features, an application may need to access excess data (including personal data) and functions of the system or another application. The system or applications must also explicitly share their data or functions through APIs. OpenHarmony uses application permissions to prevent unauthorized access to and improper or malicious use of these data or functions.

Application permissions are used to protect the following objects:

- Data: includes personal data (such as photos, contacts, calendar, and location), device data (such as device ID, camera, and microphone), and application data.
- Functions: includes device functions (such as making calls, sending SMS messages, and connecting to the Internet) and application functions (such as displaying windows and creating shortcuts).

Without the required permissions, an application cannot access or perform operations on the target object. Permissions must be clearly defined for applications. With well-defined application permissions, the system can standardize application behavior and protect user privacy. Before an application accesses an object, the object verifies the application's permissions and denies the access if the application does not have required permissions.

Currently, ATM verifies application permissions based on the token identity (token ID). A token ID identifies an application. ATM manages application permissions based on the application's token ID.

## Basic Principles for Permission Management

Observe the following permission management principles:

- Provide clear description about the usage and scenario for each permission required by the application so that user can clearly know why and when these permissions are needed. Do not induce or mislead users' authorization. The permissions on an application must comply with the description provided in the application.
- Use the principle of least authority for application permissions. Allow only necessary permissions for service functions.
- When an application is started for the first time, avoid frequently displaying dialog boxes to request multiple permissions. Allow the application to apply for the permission only when it needs to use the corresponding service function.
- If a user rejects to grant a permission, the user can still use functions irrelevant to this permission and can register and access the application.
- Provide no more message if a user rejects the authorization required by a function. Provide onscreen instructions to direct the user to grant the permission in **Settings** if the user triggers this function again or needs to use this function.

- All the permissions for applications must come from the [Application Permission List](permission-list.md). Custom permissions are not allowed currently.

## Permission Workflows

### Applying for and Using a Permission

Determine the permissions required by an application, and declare the required permissions in the application installation package.

Determine whether the required permissions need user authorization. If yes, display a dialog box dynamically to request user authorization.

After the user grants the permissions, the application can access the data or perform the operation.

The figure below illustrates the process.

![](figures/permission-workflow.png)

**NOTE**

1. Refer to the figure below to determine whether an application can apply for a permission.

![](figures/permission-application-process.png)

**NOTE**

1. See [Permission Levels](#permission-levels) for details about the mapping between the application Ability Privilege Level (APL) and the permission level.

2. The permission authorization modes include user_grant (permission granted by the user) and system_grant (permission granted by the system). For details, see [Permission Types](#permission-types).

3. A low-APL application can have a high-level permission by using the Access Control List (ACL). For details, see [ACL](#acl).

### Verifying a Permission
To protect sensitive data and eliminate security threats on core abilities, you can use the permissions in the [Application Permission List](permission-list.md) to protect an API from unauthorized calling. Each time before the API is called, a verification is performed to check whether the caller has the required permission.

The API can be called only after the permission verification is successful.

The figure below shows the permission verification process.

![](figures/permission-verify-process.png)

**NOTE**

1: An application permission can be used to control the access to an API that has sensitive data involved or security threats on core abilities.

2: The API can be protected by a permission in the [ACL](#acl). For example, if contact information is involved in an API provided by an application, you can use a contact-related permission to protect the API.

3: Use **checkAccessToken()** to check whether the caller has the required permission. For details, see [API Access Permission Verification](permission-verify-guidelines.md).

## Permission Levels

ATM defines different permission levels based on the sensitivity of the data involved or the security threat of the ability to protect user privacy.

### Application APLs

The APL defines the priority for an application to apply for permissions. Applications of different APLs can apply for permissions of different levels.

The following table describes the APLs.

| APL         | Description                                  |
| ---------------- | -------------------------------------- |
| system_core | Application that provides core abilities of the operating system (OS). |
| system_basic| Application that provides basic system services.    |
| normal      | Normal application.                            |

The default APL of applications is **normal**.

To set an application's APL to **system_basic** or **system_core**, set the **apl** field under **bundle-info** in the application's profile when developing the application's installation package.

Then, use the [hapsigner](hapsigntool-overview.md) tool to generate a certificate or use DevEco Studio to [have your application automatically signed](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465#section161281722111).

> **CAUTION**<br>The method of changing the application's APL in its profile applies only to the application or service in debug mode. For a commercial application, apply for a release certificate and profile in the corresponding application market.

Example:

This example shows only the modification of the **apl** field. Set other fields based on your requirements. For details about the fields in the profile, see [HarmonyAppProvision Configuration File](app-provision-structure.md).

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

The permissions available to applications vary with the APL. The permission levels include the following in ascending order of seniority.

- **normal**

    The **normal** permission allows access to common system resources beyond the default rules. Access to these resources (including data and functions) has minor risks on user privacy and other applications.

    The permissions of this level are available to applications of the **normal** or higher APL.

- **system_basic**

    The **system_basic** permission allows access to resources related to basic OS services. The basic services are basic functions provided or preconfigured by the system, such as system settings and identity authentication. Access to these resources may have considerable risks to user privacy and other applications.

    The permissions of this level are available only to applications of the **system_basic** or **system_core** APL.

- **system_core**

    The **system_core** permission allows access to core resources of the OS. These resources are underlying core services of the system. If these resources are corrupted, the OS cannot run properly.
    
    The **system_core** permissions are not available to third-party applications.

## Permission Types

Permissions can be classified into the following types based on the authorization mode:

- **system_grant**

   A system_grant permission is authorized by the system. The application with this type of permission cannot access user or device sensitive information, and the operations allowed have minor impact on the system or other applications.

    For an application with a system_grant permission, the system automatically grants the permission to the application when the application is installed. The system_grant permission list must be presented to users on the details page of the application in the application market.

- **user_grant**

    A user_grant permission must be authorized by the user. An application with this type of permission may access user or device sensitive information, and the operations allowed may have a critical impact on the system or other applications.

    This type of permissions must be declared in the application installation package and authorized by users dynamically during the running of the application. The application has the permission only after user authorization.

    For example, the permissions for microphones and cameras in the [Application Permission List](permission-list.md) are user_grant. The list provides information about when to use the permissions.

    The user_grant permission list must also be presented on the details page of each application in the application market.

### Authorization Processes

As described in [Permission Workflows](permission-workflows), you need to first apply for the required permissions for your application.

- Applying for a permission

   You need to [declare the required permissions](accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file) in the configuration file.

- Authorizing a permission

   - The system_grant permission is pre-granted when the application is installed.
   - For a user_grant permission, you need to trigger user authorization through a dialog box during the running of the application. For details, see [Requesting User Authorization](#requesting-user-authorization).

### Requesting User Authorization

The procedure is as follows:

1. In the configuration file, declare the permissions required by your application. For details, see [Permission Application Guide](accesstoken-guidelines.md).

2. Associate the target object in the application with the required permission. This allows the users to know the operations that need user authorization.

3. Use an API to dynamically trigger a dialog box for requesting user authorization when the target object is accessed. This API first checks whether the user has granted the permission required. If no, a dialog box will be displayed to request authorization from the user.

4. Check the user authorization result. Allow the subsequent operations only after the user has granted the permission to the application successfully.

**Caution**

- Each time before the operation that requires the target permission is performed, the application must check whether the permission is available.
- To check whether a user has granted a permission to your application, use [checkAccessToken()](../reference/apis/js-apis-abilityAccessCtrl.md#checkaccesstoken9). This API returns [PERMISSION_GRANTED](../reference/apis/js-apis-abilityAccessCtrl.md) or [PERMISSION_DENIED](../reference/apis/js-apis-abilityAccessCtrl.md). For details about the sample code, see [Permission Application Guide](accesstoken-guidelines.md).
- Users must be able to understand and control the authorization of user_grant permissions. For a user_grant permission, the application must proactively call an API to dynamically request user authorization. Then, the system displays a dialog box asking the user to grant the permission. The user then determines whether to grant the permission.
- The user may revoke the permission authorization at any time. Therefore, each time before an API associated with a user_grant permission is called, the application must check whether the permission is available.

## ACL

Permission levels and application APLs are in one-to-one correspondence. In principle, an application with a lower APL cannot apply for higher-level permissions by default.

The ACL makes low-APL applications have high-level permissions.

**Example:**

The APL of application A is **normal**. Application A needs to have permission B (system_basic level) and permission C (normal level).

In this case, you can use the ACL to grant permission B to application A.

For details, see [Using the ACL](#using-the-acl).
For details about whether a permission can be enabled via the ACL, see [Application Permission List](permission-list.md).

### Using the ACL

If the permission required by an application has a higher level than the application's APL, you can use the ACL to grant the permission required.

In addition to the preceding [authorization processes](#authorization-processes), you must declare the ACL.

That is, you need to declare the required permissions in the application's configuration file, and [declare the ACL](accesstoken-guidelines.md#declaring-the-acl) in the application's profile. The subsequent authorization steps are the same.

**NOTICE**

When developing an application installation package, you must declare the ACL in the **acls** field in the application's profile. Then, use the [hapsigner](hapsigntool-overview.md) tool to generate a certificate.

> **CAUTION**<br>The method of changing the application's APL in its profile applies only to the application or service in debug mode. For a commercial application, apply for a release certificate and profile in the corresponding application market.

```json
{
    "acls": {
        "allowed-acls": [
            "ohos.permission.PERMISSION"
        ]
    },
}
```

For details about the fields in the profile, see [HarmonyAppProvision Configuration File](app-provision-structure.md).
