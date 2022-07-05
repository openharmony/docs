#  HarmonyAppProvision Configuration File
The **HarmonyAppProvision** configuration file (also called profile) is the file where you declare permission and signature information for your application.

## Configuration File Internal Structure
The **HarmonyAppProvision** file consists of several parts, which are described in the table below.

**Table 1** Configuration file internal structure
| Name    | Description                                                                                    | Data Type| Mandatory | Initial Value Allowed|
| ----------- | ---------------------------------------------------------------------------------------- | -------- | -------- | -------- |
| version-code | Version number of the **HarmonyAppProvision** file format. The value is a positive integer containing 32 or less digits.| Number  | Yes | No                |
| version-name     | Description of the version number. It is recommended that the value consist of three segments, for example, **A.B.C**.       | String  | Yes | No|
| uuid    | Unique ID of the **HarmonyAppProvision** file.                      | String    | Yes | No|
| type | Type of the **HarmonyAppProvision** file. The value can be **debug** (for application debugging) and **release** (for application release). The recommended value is **debug**.| String    | Yes | No|
| issuer | Issuer of the **HarmonyAppProvision** file.       | String    | Yes | No|
| validity    | Validity period of the **HarmonyAppProvision** file. For details, see [Internal Structure of the validity Object](#internal-structure-of-the-validity-object). | Object    | Yes | No |
| bundle-info | Information about the application bundle and developer. For details, see [Internal Structure of the bundle-info Object](#internal-structure-of-the-bundle-info-object).        | Object    | Yes | No |
| acls        | Information about the Access Control Lists (ACLs). For details, see [Internal Structure of the acls Object](#internal-structure-of-the-acls-object).                          | Object    | No | No   |
| permissions | Permissions required for your application. For details, see [Internal Structure of the permissions Object](#internal-structure-of-the-permissions-object).     | Object    | No | No   |
| debug-info  | Additional debug information. For details, see [Internal Structure of the debug-info Object](#internal-structure-of-the-debug-info-object).         | Object    | No | No        |

An example of the **HarmonyAppProvision** file is as follows:
```json
{
    "version-code": 1,
    "version-name": "1.0.0",
	"uuid": "string",
	"type": "debug",
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
        "app-feature": "hos_normal_app"
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
    "issuer": "OpenHarmony"
}

```


### Internal Structure of the validity Object
| Name   | Description                           | Data Type| Mandatory | Initial Value Allowed|
| ---------- | ------------------------------- | ------- | ------- | --------- |
| not-before | Start time of the file validity period. The value is a Unix timestamp, which is a non-negative integer.| Number   | Yes | No  |
| not-after  | End time of the file validity period. The value is a Unix timestamp, which is a non-negative integer.| Number   | Yes | No  |

### Internal Structure of the bundle-info Object
| Name                 | Description                           | Data Type| Mandatory | Initial Value Allowed|
| ------------------------ | ------------------------------- | ------- | -------- | --------- |
| developer-id | Unique ID of the developer.| String   | Yes | No  |
| development-certificate  | Information about the [debug certificate](../security/hapsigntool-guidelines.md).| Number   | Yes if **type** is set to **debug** and no otherwise | No  |
| distribution-certificate  | Information about the [release certificate](../security/hapsigntool-guidelines.md).| Number   | Yes if **type** is set to **release** and no otherwise | No  |
| bundle-name  | Bundle name of the application.| String   | Yes | No  |
| apl  | [Ability privilege level (APL)](../security/accesstoken-overview.md) of your application. The value can be **normal**, **system_basic**, or **system_core**.| String   | Yes | No  |
| app-feature  | Type of your application. The value can be **hos_system_app** (system application) or **hos_normal_app** (non-system application).| String   | Yes | No  |


### Internal structure of the acls Object
The **acls** object contains the [ACLs](../security/accesstoken-overview.md) configured for your application. It should be noted that you still need to fill the ACL information in the **reqPermissions** attribute in the [config.json](package-structure.md) file.

**Table 4** Internal structure of the acls object

| Name                 | Description                           | Data Type| Mandatory | Initial Value Allowed|
| ------------------------ | ------------------------------- | ------- | ------- | --------- |
| allowed-acls | [ACLs](../security/accesstoken-overview.md) configured for your application.| String array   | No | No  |

### Internal Structure of the permissions Object
The **permissions** object contains restricted permissions required for your application. Different from the ACLs set in the **acls** object, these permissions need user authorization during the running of your application. It should be noted that you still need to fill the permission information in the **reqPermissions** attribute in the [config.json](package-structure.md) file.

**Table 5** Internal structure of the permissions object

| Name                 | Description                           | Data Type| Mandatory | Initial Value Allowed|
| ------------------------ | ------------------------------- | ------- | ------- | --------- |
| restricted-permissions | [Restricted permissions](../security/accesstoken-overview.md) required for your application.| String array   | No | No  |

### Internal Structure of the debug-info Object
The **debug-info** object contains debug information of your application, mainly device management and control information.

**Table 6** Internal structure of the debug-info object

| Name                 | Description                           | Data Type| Mandatory | Initial Value Allowed|
| ------------------------ | ------------------------------- | ------- | ------- | --------- |
| device-id-type | Type of the device ID. Currently, only the udid type is supported.| String   | No | No  |
| device-ids | IDs of devices on which your application can be debugged.| String array   | No | No  |
