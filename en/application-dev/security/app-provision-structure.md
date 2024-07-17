#  HarmonyAppProvision Configuration File
The **HarmonyAppProvision** configuration file (also called profile) is a file where you declare permission and signature information for your application.

## Configuration File Structure
The **HarmonyAppProvision** file consists of several parts, which are described in the table below.

| Name    | Description                                                                                    | Data Type| Mandatory| Initial Value Allowed|
| ----------- | ---------------------------------------------------------------------------------------- | -------- | -------- | -------- |
| version-code | Version number of the **HarmonyAppProvision** file format. The value is a positive integer containing 32 or less digits.| Number  | Yes| No                |
| version-name     | Description of the version number. It is recommended that the value consist of three segments, for example, **A.B.C**.       | String  | Yes| No|
| uuid    | Unique ID of the **HarmonyAppProvision** file.                      | String    | Yes| No|
| type | Type of the **HarmonyAppProvision** file. The value can be **debug** (for application debugging) or **release** (for application release). The recommended value is **debug**.| String    | Yes| No|
| app-distribution-type | Distribution type of the application. The value can be any of the following:<br>- **app_gallery**: application distributed by AppGallery.<br>- **enterprise**: enterprise application that can be installed on personal devices.<br>- **enterprise_mdm**: enterprise mobile device management (MDM) application, which can be installed only on enterprise devices. The applications of this type must have device management privileges, such as remote locking devices and installing common enterprise applications on devices.<br>- **enterprise_normal**: common enterprise application, which can be installed on enterprise devices only through an enterprise MDM application. The applications of this type do not require device management privileges.<br>- **os_integration**: preset application in the system.<br>- **crowdtesting**: crowdtesting application.<br>- **none**: other applications. | String| Yes| No|
| issuer | Issuer of the **HarmonyAppProvision** file.       | String    | Yes| No|
| validity    | Validity period of the **HarmonyAppProvision** file. For details, see [validity](#validity). | Object    | Yes| No |
| bundle-info | Information about the application bundle and developer. For details, see [bundle-info](#bundle-info).        | Object    | Yes| No |
| acls        | Information about the permissions authorized via the Access Control List (ACL). For details, see [acls](#acls). | Object    | No| Yes   |
| permissions | Permissions required for your application. For details, see [permissions](#permissions).     | Object    | No| Yes   |
| debug-info  | Additional information for application debugging. For details, see [debug-info](#debug-info).         | Object    | No| Yes        |
| app-privilege-capabilities | Privilege information required by the application bundle. For details, see the [Application Privilege Configuration Guide](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).  | String array| No| Yes        |

An example of the **HarmonyAppProvision** file is as follows:
```json
{
    "version-code": 1,
    "version-name": "1.0.0",
	"uuid": "string",
	"type": "debug",
	"app-distribution-type": "os_integration",
	"validity": {
		"not-before": 1586422743,
		"not-after": 1617958743
	},
	"bundle-info" : {
		"developer-id": "OpenHarmony",
		"development-certificate": "Base64 string",
		"distribution-certificate": "Base64 string",
		"bundle-name": "com.OpenHarmony.app.test",
		"apl": "normal",
		"app-feature": "hos_normal_app",
		"data-group-ids": [
			"testGroupId1",
			"testGroupId2"
		]
	},
	"acls": {
		"allowed-acls": ["string"]
    },
	"permissions": {
		"restricted-permissions": ["string"]
    },
    "debug-info" : {
	    "device-id-type": "udid",
	    "device-ids": ["string"]
    },
    "app-privilege-capabilities":["AllowAppUsePrivilegeExtension"],
    "issuer": "OpenHarmony"
}

```

### validity

| Name   | Description                           | Data Type| Mandatory| Initial Value Allowed|
| ---------- | ------------------------------- | ------- | ------- | --------- |
| not-before | Start time of the file validity period. The value is a Unix timestamp, which is a non-negative integer.| Number   | Yes| No  |
| not-after  | End time of the file validity period. The value is a Unix timestamp, which is a non-negative integer.| Number   | Yes| No  |

### bundle-info

> **NOTE**<br>The value of **bundle-name** in the **bundle-info** object in the HarmonyAppProvision file must be the same as the value of **bundleName** (in **config.json** or **module.json5**) of the signed application. To prevent a HarmonyAppProvision file from being used for signatures of different applications, the system checks whether the value of **bundleName** in the HAP signature is the same as that in the HAP configuration file during application installation. If they are different, the HAP cannot be installed.

| Name                 | Description                           | Data Type| Mandatory| Initial Value Allowed|
| ------------------------ | ------------------------------- | ------- | -------- | --------- |
| developer-id | Unique ID of the developer.| String   | Yes| No  |
| development-certificate  | Information about the [debug certificate](hapsigntool-guidelines.md).| Number   | Yes if **type** is set to **debug** and no otherwise  | No  |
| distribution-certificate  | Information about the [release certificate](hapsigntool-guidelines.md).| Number   | Yes if **type** is set to **release** and no otherwise| No  |
| bundle-name  | Bundle name of the application.| String   | Yes| No  |
| apl  | [Ability Privilege Level (APL)](AccessToken/access-token-overview.md) of the application. The predefined APLs includes normal, system_basic, and system_core.| String   | Yes| No  |
| app-feature  | Type of your application. The value can be **hos_system_app** (system application) or **hos_normal_app** (normal application). Only system applications are allowed to call system APIs. If a normal application calls a system API, the call cannot be successful or the application may run abnormally.| String   | Yes| No  |
| data-group-ids  | IDs of application data groups. When an application is installed, a directory is generated for each data group ID. If two applications or an ExtensionAbility and its application have the same data group ID in **data-group-ids**, they can share the data in the directory corresponding to the data group ID. An ExtensionAbility declares the data group IDs in the **dataGroupIds** field in the [module.json5](../quick-start/module-configuration-file.md#extensionabilities) file.| String array   | No| Yes (initial value: left empty)  |
| app-identifier | Unique ID of the application, which is allocated by the cloud. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers.| String array   | No| Yes (initial value: left empty)  |


### acls
The **acls** object contains the [permissions authorized via the ACL](AccessToken/permissions-for-system-apps.md). It should be noted that you still need to add the ACL information to the [**requestPermissions**](../quick-start/module-configuration-file.md#requestpermissions) attribute in the application configuration file.

| Name                 | Description                           | Data Type| Mandatory| Initial Value Allowed|
| ------------------------ | ------------------------------- | ------- | ------- | --------- |
| allowed-acls | [Permissions authorized via the ACL](AccessToken/permissions-for-system-apps.md).| String array   | No| No  |

### permissions
The **permissions** object contains restricted permissions required for your application. Different from the ACLs set in the **acls** object, these permissions need user authorization during the running of your application. It should be noted that you still need to add the ACL information to the [**requestPermissions**](../quick-start/module-configuration-file.md#requestpermissions) attribute in the application configuration file.

| Name                 | Description                           | Data Type| Mandatory| Initial Value Allowed|
| ------------------------ | ------------------------------- | ------- | ------- | --------- |
| restricted-permissions | [user_grant permissions](AccessToken/permissions-for-all.md#user_grant-permissions) that can be used.| String array   | No| No  |

### debug-info
The **debug-info** object contains debugging information of your application, mainly device management and control information.

| Name                 | Description                           | Data Type| Mandatory| Initial Value Allowed|
| ------------------------ | ------------------------------- | ------- | ------- | --------- |
| device-id-type | Type of the device ID. Currently, only the udid type is supported.| String   | No| No  |
| device-ids | IDs of devices on which your application can be debugged.| String array   | No| No  |

## Modifying the HarmonyAppProvision Configuration File

When a development project is created, the default application type is **hos_normal_app** and the default APL level is **normal**.

To enable the application to use system APIs, you need to change the **app-feature** field to **hos_system_app** (system application). To request high-level permissions, you need to modify fields such as **apl** and **acl**. For details, see [Access Control Overview](AccessToken/access-token-overview.md).


To modify the HarmonyAppProvision configuration file, perform the following steps:

1. Open the directory where the OpenHarmony SDK is located. (You can choose **File** > **Settings** > **OpenHarmony SDK** on the menu bar of DevEco Studio to query the directory.)
2. In the SDK directory, go to the **Toolchains** > {Version} > **lib** directory and open the **UnsignedReleasedProfileTemplate.json** file.
3. Modify the related fields as required.

After modifying the configuration file, [sign the application](hapsigntool-guidelines.md).

<!--no_check-->
