

# Application Package Structure Configuration File

When developing an application in the Feature Ability (FA) model, you must declare the package structure of the application in the **config.json** file.

## Internal Structure of the config.json File

The **config.json** file consists of three mandatory tags, namely, **app**, **deviceConfig**, and **module**. For details, see Table 1.

Table 1 Internal structure of the config.json file

| Tag    | Description                                                        | Data Type| Initial Value Allowed|
| ------------ | ------------------------------------------------------------ | -------- | ---------- |
| app          | Global configuration of the application. Different HAP files of the same application must use the same **app** configuration. For details, see [Internal Structure of the app Tag](#internal-structure-of-the-app-tag).| Object    | No  |
| deviceConfig | Application configuration applied to a specific type of device. For details, see [Internal Structure of the deviceconfig Tag](#internal-structure-of-the-deviceconfig-tag).| Object    | No  |
| module       | Configuration of a HAP file. It is valid only for the current HAP file. For details, see [Internal Structure of the module Tag](#internal-structure-of-the-module-tag).| Object    | No  |

Example of the **config.json** file:

```json
{
  "app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "version": {
      "code": 1,
      "name": "1.0"
    },
    "apiVersion": {
      "compatible": 4,
      "target": 5,
      "releaseType": "Beta1"
    }
  },
  "deviceConfig": {},
  "module": {
    "package": "com.example.myapplication.entrymodule",
    "name": ".MyApplication",
    "deviceType": [
      "default"
    ],
    "distro": {
      "moduleName": "entry",
      "moduleType": "entry"
    },
    "abilities": [
      {
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ],
        "name": "com.example.myapplication.entrymodule.MainAbility",
        "icon": "$media:icon",
        "description": "$string:mainability_description",
        "label": "$string:app_name",
        "type": "page",
        "launchType": "standard"
      }
    ],
    "js": [
      {
        "pages": [
          "pages/index/index"
        ],
        "name": "default",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": false
        }
      }
    ]
  }
}
```

### Internal Structure of the app Tag

The **app** tag contains the global configuration information of the application. For details about the internal structure, see Table 2.

Table 2 Internal structure of the app tag

| Attribute         | Description                                                        | Data Type| Initial Value Allowed                 |
| ----------------- | ------------------------------------------------------------ | -------- | --------------------------- |
| bundleName        | Bundle name, which uniquely identifies an application. The bundle name can contain only letters, digits, underscores (_), and periods (.). It must start with a letter. The value is a string with 7 to 127 bytes of a reverse domain name, for example, **com.example.myapplication**. It is recommended that the first level be the domain suffix "com" and the second level be the vendor/individual name. More levels are also accepted.| String  | No                   |
| vendor            | Description of the application vendor. The value is a string with a maximum of 255 bytes.         | String  | Yes (initial value: left empty)         |
| version           | Version of the application. For details, see Table 3.                               | Object    | No                         |
| apiVersion        | OpenHarmony API version on which the application depends. For details, see Table 4.          | Object    | Yes (initial value: left empty)         |
| singleton         | Whether to enable singleton mode for the application. This attribute applies only to system applications and does not take effect for third-party applications. If this attribute is set to **true**, the application always runs in singleton mode, even in multi-user scenarios. This attribute is supported since API version 8.| Boolean  | Yes (initial value: **false**)|
| removable         | Whether the application can be uninstalled. This attribute applies only to system applications and does not take effect for third-party applications. It is supported since API version 8.    | Boolean  | Yes (initial value: **true**)       |
| userDataClearable | Whether user data of the application can be cleared. This attribute applies only to system applications and does not take effect for third-party applications. It is supported since API version 8.| Boolean  | Yes (initial value: **true**)       |

Table 3 Internal structure of version

| Attribute                | Description                                                        | Data Type| Initial Value Allowed                |
| ------------------------ | ------------------------------------------------------------ | -------- | -------------------------- |
| name                     | Application version number visible to users. The value can be customized and cannot exceed 127 bytes. The customization rules are as follows:<br>API 5 and earlier versions: A three-segment version number is recommended, for example, A.B.C (also compatible with A.B). In the version number, A, B, and C are integers ranging from 0 to 999. Other formats are not supported.<br>     A indicates the major version number. <br>     B indicates the minor version number.<br>     C indicates the patch version number.<br>API 6 and later versions: A four-segment version number is recommended, for example, A.B.C.D. In the version number, A, B, and C are integers ranging from 0 to 99, and D is an integer ranging from 0 to 999.<br>     A indicates the major version number. <br>     B indicates the minor version number.<br>     C indicates the feature version number.<br>     D indicates the patch version number.| Number    | No                  |
| code                     | Application version number used only for application management by OpenHarmony. This version number is not visible to users of the application. The value rules are as follows:<br>API 5 and earlier versions: It is a non-negative integer less than 32 bits in binary mode, converted from the value of version.name as follows: The conversion rules are as follows:<br> Value of **code** = A * 1,000,000 + B * 1,000 + C. For example, if the value of **version.name** is 2.2.1, the value of **code** is 2002001.<br> API 6 and later versions: The value of **code** is not associated with the value of **version.name** and can be customized. The value is a non-negative integer ranging from 2 to 31. Note that the value must be updated each time the application version is updated. The value for a later version must be greater than that for an earlier version.| Number    | No                  |
| minCompatibleVersionCode | Earliest version compatible with the application. It is used in the cross-device scenario to check whether the application is compatible with a specific version on other devices.<br> The value rules are the same as those of **version.code**.| Number    | No (initial value: **code** attribute value)|

Table 4 Internal structure of apiVersion

| Attribute   | Description                                                       | Data Type| Initial Value Allowed|
| ----------- | ----------------------------------------------------------- | -------- | ---------- |
| compatible  | Minimum API version required for running the application. The value ranges from 0 to 2147483647.      | Integer    | Yes    |
| target      | Target API version required for running the application. The value ranges from 0 to 2147483647.| Integer    | Yes    |
| releaseType | Type of the target API version required for running the application.                  | String  | Yes    |

Example of the app tag structure:

```json
"app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "version": {
        "code": 1,
        "name": "1.0"
    },
    "apiVersion": {
        "compatible": 4,
        "target": 5,
        "releaseType": "Beta1"
    }
}
```

### Internal Structure of the deviceConfig Tag

The **deviceConfig** tag contains the application configuration information on the device, including attributes such as **default**, **tv**, **car**, and **wearable**. The **default** configuration applies to all types of devices. You need to declare the peculiar configuration of a specific device type in the associated sub-tag of this type. For details about the internal structure, see Table 5.

Table 5 Internal structure of the deviceConfig tag

| Attribute| Description                                     | Data Type| Initial Value Allowed        |
| -------- | ----------------------------------------- | -------- | ------------------ |
| default  | Application configuration applied to all types of devices. For details, see Table 6.| Object    | No                |
| tablet   | Application configuration specific to tablets. For details, see Table 6.        | Object    | Yes (initial value: left empty)|
| tv       | Application configuration specific to smart TVs. For details, see Table 6.  | Object    | Yes (initial value: left empty)|
| car      | Application configuration specific to head units. For details, see Table 6.    | Object    | Yes (initial value: left empty)|
| wearable | Application configuration specific to wearables. For details, see Table 6.| Object    | Yes (initial value: left empty)|

For details about the internal structures of device attributes, see Table 6.

Table 6 Internal structure of device attributes

| Attribute          | Description                                                        | Data Type| Initial Value Allowed             |
| ------------------ | ------------------------------------------------------------ | -------- | ----------------------- |
| process            | Process running the application or ability. If the **process** attribute is configured in the **deviceConfig** tag, all abilities of the application run in this process. You can set the **process** attribute for a specific ability in the **abilities** attribute, so that the ability can run in the particular process. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types. The value can contain a maximum of 31 characters.| String  | Yes                     |
| keepAlive          | Whether the application is always kept alive. This attribute applies only to system applications and does not take effect for third-party applications. The value **true** means that the application is always kept alive: The system automatically launches the application at startup and restarts it after it exits.| Boolean  | Yes (initial value: **false**)  |
| supportBackup      | Whether the application supports backup and restoration. The value **false** means that the application does not support backup or restoration.<br> This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| Boolean  | Yes (initial value: **false**)|
| compressNativeLibs | Whether the **libs** libraries are packaged in the HAP file after being compressed. The value **false** means that the **libs** libraries are stored without being compressed and will be directly loaded during the installation of the HAP file.<br> This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| Boolean  | Yes (initial value: **true**) |
| directLaunch       | Whether the application can be started when the device is locked. The value **true** means that the application can be started when the device is locked. Devices running OpenHarmony do not support this attribute.| Boolean  | Yes (initial value: **false**)|
| ark                | Maple configuration. For details, see Table 7.                                | Object    | Yes (initial value: left empty)             |
| network            | Network security configuration. You can customize the network security settings of the application in the security statement of the configuration file without modifying the application code. For details, see Table 9.| Object    | Yes (initial value: left empty)     |

Table 7 Internal structure of the ark attribute

| Attribute  | Description                            | Data Type| Initial Value Allowed                    |
| ---------- | -------------------------------- | -------- | ------------------------------ |
| reqVersion | Maple version required for the application. For details, see Table 8.| Object    | No                      |
| flag       | Type of the Maple application.       | String  | No (available options: **m**, **mo**, **z**).|

Table 8 Internal structure of the reqVersion attribute

| Attribute  | Description                                                     | Data Type| Initial Value Allowed|
| ---------- | --------------------------------------------------------- | -------- | ---------- |
| compatible | Minimum Maple version required for the application. The value is a 32-bit unsigned integer.| Integer    | No  |
| target     | Type of the Maple application. The value is a 32-bit unsigned integer.        | Integer    | No  |

Table 9 Internal structure of the network attribute

| Attribute        | Description                                                        | Data Type| Initial Value Allowed             |
| ---------------- | ------------------------------------------------------------ | -------- | ----------------------- |
| cleartextTraffic | Whether to allow the application to use plaintext traffic, for example, plaintext HTTP traffic.<br> **true**: The application is allowed to use plaintext traffic.<br> **false**: The application is not allowed to use plaintext traffic.| Boolean  | Yes (initial value: **false**)|
| securityConfig   | Network security configuration of the application. For details, see Table 10.                      | Object    | Yes (initial value: left empty)       |

Table 10 Internal structure of the securityConfig attribute

| Attribute      | Sub-attribute        | Description                                                        | Data Type| Initial Value Allowed      |
| -------------- | ------------------ | ------------------------------------------------------------ | -------- | ---------------- |
| domainSettings | -                  | Security settings of the custom network domain. This attribute allows nested domains. That is, the **domainSettings** object of a network domain can be nested with the **domainSettings** objects of smaller network domains.| Object| Yes (initial value: left empty)|
|                | cleartextPermitted | Whether plaintext traffic can be transmitted in the custom network domain. If both **cleartextTraffic** and **security** are declared, whether plaintext traffic can be transmitted in the custom network domain is determined by the **cleartextPermitted** attribute.<br>**true**: Plaintext traffic can be transmitted.<br>**false**: Plaintext traffic cannot be transmitted.| Boolean| No        |
|                | domains            | Domain name. This attribute consists of two sub-attributes: **subdomains** and **name**.<br> **subdomains** (boolean): specifies whether the domain name contains subdomains. If this sub-attribute is set to **true**, the domain naming convention applies to all related domains and subdomains (including the lower-level domains of the subdomains). Otherwise, the convention applies only to exact matches.<br> **name** (string): indicates the domain name.| Object array| No        |

Example of the deviceConfig tag structure:

```json
"deviceConfig": {
    "default": {
        "process": "com.example.test.example",
        "supportBackup": false,
        "network": {
            "cleartextTraffic": true,
            "securityConfig": {
                "domainSettings": {
                    "cleartextPermitted": true,
                    "domains": [
                        {
                            "subdomains": true,
                            "name": "example.ohos.com"
                        }
                    ]
                }
            }
        }
    }
}
```

### Internal Structure of the module Tag

The **module** tag contains the configuration information of the HAP file. For details about the internal structure, see Table 11.

Table 11 Internal structure of the module tag

| Attribute         | Description                                                        | Data Type  | Initial Value Allowed                                                  |
| ----------------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| mainAbility       | Ability displayed on the Service Center icon. When the resident process is started, the **mainAbility** is started.| String    | No if any ability using the Page template exists               |
| package           | Package name of the HAP file, which must be unique in the application. The value is a string with a maximum of 127 bytes, in the reverse domain name notation. It is recommended that the value be the same as the project directory of the HAP file. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types. | String    | No                                                    |
| name              | Class name of the HAP file. The value is in the reverse domain name notation, with the prefix same as the package name specified by **package** at the same level. It can also start with a period (.). The value is a string with a maximum of 255 bytes.<br> This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| String    | No                                                    |
| description       | Description of the HAP file. The value is a string with a maximum of 255 bytes. If the value exceeds the limit or needs to support multiple languages, you can use a resource index to the description. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| String    | Yes (initial value: left empty)                                          |
| supportedModes    | Mode supported by the application. Currently, only the **drive** mode is defined. This attribute applies only to head units.| String array| Yes (initial value: left empty)                                          |
| deviceType        | Type of device on which the ability can run. The device types predefined in the system include **tablet**, **tv**, **car**, and **wearable**.| String array| No                                                    |
| distro            | Distribution description of the HAP file. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types. For details, see Table 12.| Object      | No                                                    |
| metaData          | Metadata of the HAP file. For details, see Table 13.                                 | Object      | Yes (initial value: left empty)                                          |
| abilities         | All abilities in the current module. The value is an array of objects, each of which represents a shortcut object. For details, see Table 17.| Object array  | Yes (initial value: left empty)                                          |
| js                | A set of JS modules developed using ArkUI. Each element in the set represents the information about a JS module. For details, see Table 22.| Object array  | Yes (initial value: left empty)                                          |
| shortcuts         | Shortcuts of the application. The value is an array of objects, each of which represents a shortcut object. For details, see Table 25.| Object array  | Yes (initial value: left empty)                                          |
| reqPermissions    | Permissions that the application requests from the system when it is running. For details, see Table 21.                  | Object array  | Yes (initial value: left empty)                                          |
| colorMode         | Color mode of the application. Available values are as follows:<br>**"dark"**: Resources applicable for the dark mode are selected.<br>**"light"**: Resources applicable for the light mode are selected.<br>**"auto"**: Resources are selected based on the color mode of the system.<br> This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types. | String    | Yes (initial value: **auto**)                                      |
| distroFilter      | Distribution rules of the application.<br> AppGallery uses these rules to distribute HAP files to the matching devices. Distribution rules cover three factors: API version, screen shape, and screen resolution. AppGallery distributes a HAP file to the device whose on the mapping between **deviceType** and these three factors. For details, see Table 29.| Object      | Yes (initial value: left empty) Set this attribute when an application has multiple entry modules.|
| reqCapabilities   | Device capabilities required for running the application.                              | String array| Yes (initial value: left empty)                                            |
| commonEvents      | Static broadcast. For details, see Table 35.                                        | Object array  | Yes (initial value: left empty)                                            |
| entryTheme        | Keyword of an OpenHarmony internal theme. Set it to the resource index of the name.| String    | Yes (initial value: left empty)                                          |
| testRunner        | Test runner configuration. For details, see Table 36.                  | Object      | Yes (initial value: left empty)                                          |
| definePermissions | Permissions defined for the HAP file. This attribute applies only to system applications and does not take effect for third-party applications. The caller of the application must have these permissions to properly call the app. For details, see Table 37.| Object      | Yes (initial value: left empty)                                          |

Example of the **module** tag structure:

```json
"module": {
    "mainAbility": "MainAbility",
    "package": "com.example.myapplication.entry",
    "name": ".MyOHOSAbilityPackage",
    "description": "$string:description_application",
    "supportModes": [
        "drive"
    ],
    "deviceType": [
        "car"
    ],
    "distro": {
        "moduleName": "ohos_entry",
        "moduleType": "entry"
    },
    "abilities": [
      ...
    ],
    "shortcuts": [
      ...
    ],
    "js": [
      ...
    ],
    "reqPermissions": [
      ...
    ],
    "colorMode": "light"
}
```

Table 12 Internal structure of the distro attribute

| Attribute        | Description                                                        | Data Type| Initial Value Allowed|
| ---------------- | ------------------------------------------------------------ | -------- | ---------- |
| moduleName       | Name of the HAP file. The maximum length is 31 characters.                           | String  | No  |
| moduleType       | Type of the HAP file. The value can be **entry** or **feature**. For the HAR type, set this attribute to **har**.| String  | No  |
| installationFree | Whether the HAP file supports the installation-free feature.<br> **true**: The HAP file supports the installation-free feature and meets installation-free constraints.<br> **false**: The HAP file does not support the installation-free feature.<br>Pay attention to the following:<br>- When **entry.hap** is set to **true**, all **feature.hap** fields related to **entry.hap **must be **true**.<br>- When **entry.hap** is set to **false**, **feature.hap** related to **entry.hap** can be set to **true** or **false** based on service requirements. | Boolean  | No    |
| deliveryWithInstall | Whether the HAP file is installed with application.<br> **true**: The HAP file is installed together with the application.<br> **false**: The HAP file is not installed together with the application.| Boolean| No|

Example of the **distro** attribute structure:

```json
"distro": {
    "moduleName": "ohos_entry",
    "moduleType": "entry",
    "installationFree": true,
    "deliveryWithInstall": true
}
```

Table 13 Internal structure of the metaData attribute

| Attribute     | Description                                                        | Data Type| Initial Value Allowed          |
| ------------- | ------------------------------------------------------------ | -------- | -------------------- |
| parameters    | Metadata of the parameters to be passed for calling the ability. The metadata of each parameter consists of the **description**, **name**, and **type** sub-attributes. For details, see Table 14.| Object array| Yes (initial value: left empty)  |
| results       | Metadata of the ability return value. The metadata of each return value consists of the **description**, **name**, and **type** sub-attributes. For details, see Table 15.| Object array| Yes (initial value: left empty)|
| customizeData | Custom metadata of the parent component. **parameters** and **results** cannot be configured in **application**. For details, see Table 16.| Object array| Yes (initial value: left empty)|

Table 14 Internal structure of the parameters attribute

| Attribute   | Description                                                        | Data Type| Initial Value Allowed        |
| ----------- | ------------------------------------------------------------ | -------- | ------------------ |
| description | Description of the parameter passed for calling the ability. The value can be a string or a resource index to descriptions in multiple languages. The value can contain a maximum of 255 characters.| String  | Yes (initial value: left empty)|
| name        | Name of the parameter passed for calling the ability. The value can contain a maximum of 255 characters.                   | String  | Yes (initial value: left empty)|
| type        | Type of the parameter passed for calling the ability, for example, **Integer**.                             | String  | No          |

Table 15 Internal structure of the results attribute

| Attribute   | Description                                                        | Data Type| Initial Value Allowed          |
| ----------- | ------------------------------------------------------------ | -------- | -------------------- |
| description | Description of the return value. The value can be a string or a resource index to descriptions in multiple languages. The value can contain a maximum of 255 characters.| String  | Yes (initial value: left empty)|
| name        | Name of the return value. The value can contain a maximum of 255 characters.                     | String  | Yes (initial value: left empty)|
| type        | Type of the return value, for example, **Integer**.                               | String  | No            |

Table 16 Internal structure of the customizeData attribute

| Attribute| Description                                                      | Data Type| Initial Value Allowed          |
| -------- | ---------------------------------------------------------- | -------- | -------------------- |
| name     | Key of the data item. The value is a string with a maximum of 255 bytes.  | String  | Yes (initial value: left empty)|
| value    | Value of the data item. The value is a string with a maximum of 255 bytes.   | String  | Yes (initial value: left empty)|
| extra    | Custom format of the data item. The value is an index to the resource that identifies the data.| String  | Yes (initial value: left empty)|

Example of the **metaData** attribute structure:

```json
"metaData": {
    "parameters" : [{
        "name" : "string",
        "type" : "Float",
        "description" : "$string:parameters_description"
    }],
    "results" : [{
        "name" : "string",
        "type" : "Float",
        "description" : "$string:results_description"
    }],
    "customizeData" : [{
        "name" : "string",
        "value" : "string",
        "extra" : "$string:customizeData_description"
    }]
}
```

Table 17 Internal structure of the abilities attribute

| Attribute        | Description                                                        | Data Type  | Initial Value Allowed                                              |
| ---------------- | ------------------------------------------------------------ | ---------- | -------------------------------------------------------- |
| process          | Name of the process running the application or ability. If the **process** attribute is configured in the **deviceConfig** tag, all abilities of the application run in this process. You can set the **process** attribute for a specific ability in the **abilities** attribute, so that the ability can run in the particular process. If this attribute is set to the name of the process running other applications, all these applications can run in the same process, provided they have the same unified user ID and the same signature. Devices running OpenHarmony do not support this attribute.| String    | Yes (initial value: left empty)                                    |
| name             | Ability name. The value can be a reverse domain name, in the format of "*Bundle name*.*Class name*", for example, **"com.example.myapplication.MainAbility"**. Alternatively, the value can start with a period (.) followed by the class name, for example, **".MainAbility"**.<br> The ability name must be unique in an application. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.<br>Note: If you use DevEco Studio to create the project, an ability named **MainAbility** will be created together with the default configuration in the **config.json** file. The value of this attribute can be customized if you use other IDEs. The value can contain a maximum of 127 characters. | String    | No                                                  |
| description      | Description of the ability. The value can be a string or a resource index to descriptions in multiple languages. The value can contain a maximum of 255 characters.| String    | Yes (initial value: left empty)                                    |
| icon             | Index to the ability icon file. Example value: **$media:ability_icon**. In the **skills** attribute of the ability, if the **actions** value contains **action.system.home** and the **entities** value contains **entity.system.home**, the icon of the ability is also used as the icon of the application. If multiple abilities address this condition, the icon of the first candidate ability is used as the application icon.<br>Note: The **icon** and **label** values of an application are visible to users. Ensure that at least one of them is different from any existing icons or labels. | String    | Yes (initial value: left empty)                                    |
| label            | Ability name visible to users. The value can be a name string or a resource index to names in multiple languages. In the **skills** attribute of the ability, if the **actions** value contains **action.system.home** and the **entities** value contains **entity.system.home**, the label of the ability is also used as the label of the application. If multiple abilities address this condition, the label of the first candidate ability is used as the application label.<br>Note: The **icon** and **label** values of an application are visible to users. Ensure that at least one of them is different from any existing icons or labels. The value can be a reference to a string defined in a resource file or a string enclosed in brackets ({}). The value can contain a maximum of 255 characters. | String    | Yes (initial value: left empty)                                    |
| uri              | Uniform Resource Identifier (URI) of the ability. The value can contain a maximum of 255 characters.          | String    | Yes (No for abilities using the Data template)                 |
| launchType       | Launch type of the ability. Available values are as follows:<br>**"standard"**: Multiple **Ability** instances can be created during startup. Most abilities can use this type.<br>**"singleton"**: Only a single **Ability** instance can be created across all task stacks during startup. For example, a globally unique incoming call screen uses the singleton startup type. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types. | String    | Yes (initial value: **"singleton"**)                           |
| visible          | Whether the ability can be called by other applications.<br>**true**: The ability can be called by other applications.<br>**false**: The ability cannot be called by other applications.| Boolean  | Yes (initial value: **false**)                               |
| permissions      | Permissions required for abilities of another application to call the current ability. The value is an array of permission names predefined by the system, generally in the format of a reverse domain name the reverse domain name format (a maximum of 255 bytes).| String array| Yes (initial value: left empty)                                    |
| skills           | Types of the **want** that can be accepted by the ability.                           | Object array  | Yes (initial value: left empty)                                    |
| deviceCapability | Device capabilities required to run the ability.| String array| Yes (initial value: left empty)                                    |
| metaData         | Metadata. For details, see Table 13.                                          | Object      | Yes (initial value: left empty)                                    |
| type             | Ability type. Available values are as follows:<br>**"page"**: FA developed using the Page template to provide the capability of interacting with users.<br>**"service"**: PA developed using the Service template to provide the capability of running tasks in the background.<br>**"data"**: PA developed using the Data template to provide unified data access for external systems.<br>**"CA"**: ability that can be started by other applications as a window. | String    | No                                                  |
| orientation      | Display orientation of the ability. This attribute applies only to the ability using the Page template. Available values are as follows:<br>**"unspecified"**: indicates that the system automatically determines the display orientation of the ability.<br>**"landscape"**: indicates the landscape orientation.<br>**"portrait"**: indicates the portrait orientation.<br>**"followRecent"**: indicates that the orientation follows the most recent application in the stack. | String    | Yes (initial value: **"unspecified"**)                         |
| backgroundModes  | Background service type of the ability. You can assign multiple background service types to a specific ability. This attribute applies only to the ability using the Service template. Available values are as follows:<br>**dataTransfer**: service for downloading, backing up, sharing, or transferring data from the network or peer devices<br>**audioPlayback**: audio playback service<br>**audioRecording**: audio recording service<br>**pictureInPicture**: picture in picture (PiP) and small-window video playback services<br>**voip**: voice/video call and VoIP services<br>**location**: location and navigation services<br>**bluetoothInteraction**: Bluetooth scanning, connection, and transmission services<br>**wifiInteraction**: WLAN scanning, connection, and transmission services<br>**screenFetch**: screen recording and screenshot services<br>**multiDeviceConnection**: multi-device interconnection service| String array| Yes (initial value: left empty)                                    |
| grantPermission  | Whether permissions can be granted for any data in the ability.                   | Boolean    | Yes (initial value: left empty)                                    |
| readPermission   | Permission required for reading data in the ability. This attribute applies only to the ability using the Data template. The value is a string with a maximum of 255 bytes. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| String    | Yes (initial value: left empty)                                      |
| writePermission  | Permission required for writing data to the ability. This attribute applies only to the ability using the Data template. The value is a string with a maximum of 255 bytes. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| String    | Yes (initial value: left empty)                                      |
| configChanges    | System configurations that the ability concerns. Upon any changes on the concerned configurations, the **onConfigurationUpdated** callback will be invoked to notify the ability. Available values are as follows:<br>**mcc**: indicates that the mobile country code (MCC) of the IMSI is changed. Typical scenario: A SIM card is detected, and the MCC is updated.<br>**mnc**: indicates that the mobile network code (MNC) of the IMSI is changed. Typical scenario: A SIM card is detected, and the MNC is updated.<br>**locale**: indicates that the locale is changed. Typical scenario: The user has selected a new language for the text display of the device.<br>**layout**: indicates that the screen layout is changed. Typical scenario: Currently, different display forms are all in the active state.<br>**fontSize**: indicates that font size is changed. Typical scenario: A new global font size is set.<br>**orientation**: indicates that the screen orientation is changed. Typical scenario: The user rotates the device.<br>**density**: indicates that the display density is changed. Typical scenario: The user may specify different display ratios, or different display forms are active at the same time.<br>**size**: indicates that the size of the display window is changed.<br>**smallestSize**: indicates that the length of the shorter side of the display window is changed.<br>**colorMode**: indicates that the color mode is changed.| String array| Yes (initial value: left empty)                                      |
| mission          | Task stack of the ability. This attribute applies only to the ability using the Page template. By default, all abilities in an application belong to the same task stack. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| String    | Yes (initial value: bundle name of the application)                              |
| targetAbility    | Target ability that this ability alias points to. This attribute applies only to the ability using the Page template. If the **targetAbility** attribute is set, only **name**, **icon**, **label**, **visible**, **permissions**, and **skills** take effect in the current ability (ability alias). Other attributes use the values of the **targetAbility** attribute. The target ability must belong to the same application as the alias and must be declared in **config.json** ahead of the alias. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| String    | Yes (initial value: left empty, indicating that the current ability is not an alias)|
| multiUserShared  | Whether the ability supports data sharing among multiple users. This attribute applies only to the ability using the Data template. If this attribute is set to **true**, only one copy of data is stored for multiple users. Note that this attribute will invalidate the **visible** attribute. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| Boolean| Yes (initial value: **false**)                               |
| supportPipMode   | Whether the ability allows the user to enter the Picture in Picture (PiP) mode. The PiP mode enables the user to watch a video in a small window that hovers on top of a full screen window (main window). This attribute applies only to the ability using the Page template. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types.| Boolean| Yes (initial value: **false**)                               |
| formsEnabled     | Whether the ability can provide forms. This attribute applies only to the ability using the Page template.<br>**true**: This ability can provide forms.<br>**false**: This ability cannot provide forms.| Boolean| Yes (initial value: **false**)                               |
| forms            | Information about the forms used by the ability. This attribute is valid only when **formsEnabled** is set to **true**. For details, see Table 27.| Object array  | Yes (initial value: left empty)                                    |
| srcLanguage      | Programming language used to develop the ability. The value can be **"js"** or **"ets"**.                                 | String    | Yes                                     |
| srcPath          | Path of the JS component code corresponding to the ability.                       | String    | Yes (initial value: left empty)                                    |
| uriPermission    | Application data that the ability can access. This attribute consists of the **mode** and **path** sub-attributes. This attribute is valid only for the capability of the type provider. Devices running OpenHarmony do not support this attribute. For details, see Table 18.| Object      | Yes (initial value: left empty)                                    |
| startWindowIcon    | Index to the icon file of the ability startup page. This attribute applies only to the ability using the Page template. Example: **$media:icon**.| String      | Yes (initial value: left empty)|
| startWindowBackground    | Index to the background color resource file of the ability startup page. This attribute applies only to the ability using the Page template. Example: **$color:red**.| String      | Yes (initial value: left empty)|
| removeMissionAfterTerminate    | Whether to remove the relevant task from the task list after the ability is destroyed. This attribute applies only to the ability using the Page template. The value **true** means to remove the relevant task from the task list after the ability is destroyed, and **false** means the opposite.| Boolean      | Yes (initial value: **false**)|

Table 18 Internal structure of the uriPermission attribute

| Attribute| Description                   | Data Type| Initial Value Allowed               |
| -------- | ----------------------- | -------- | ------------------------- |
| path     | Path identified by **uriPermission**.| String  | No                 |
| mode     | Mode matching the **uriPermission**.| String  | Yes (initial value: *default***)|

Example of the **abilities** attribute structure:

```json
"abilities": [
    {
        "name": ".MainAbility",
        "description": "test main ability",
        "icon": "$media:ic_launcher",
        "label": "$media:example",
        "launchType": "standard",
        "orientation": "unspecified",
        "permissions": [], 
        "visible": true,
        "skills": [
            {
                "actions": [
                    "action.system.home"
                ],
                "entities": [
                    "entity.system.home"
                ]
            }
        ],
        "configChanges": [
            "locale", 
            "layout", 
            "fontSize", 
            "orientation"
        ], 
        "type": "page",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:red",
        "removeMissionAfterTerminate": true
    },
    {
        "name": ".PlayService",
        "description": "example play ability",
        "icon": "$media:ic_launcher",
        "label": "$media:example",
        "launchType": "standard",
        "orientation": "unspecified",
        "visible": false,
        "skills": [
            {
                "actions": [
                    "action.play.music",
                    "action.stop.music"
                ],
                "entities": [
                    "entity.audio"
                ]
            }
        ],
        "type": "service",
        "backgroundModes": [
            "audioPlayback"
        ]
    },
    {
        "name": ".UserADataAbility",
        "type": "data",
        "uri": "dataability://com.example.world.test.UserADataAbility",
        "visible": true
    }
]
```

Table 19 Internal structure of the skills attribute

| Attribute| Description                                                        | Data Type  | Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | ---------- | -------------------- |
| actions  | Actions of the **want** that can be accepted by the ability. Generally, the value is an **action** value predefined in the system.| String array| Yes (initial value: left empty)|
| entities | Entities of the **want** that can be accepted by the ability, such as video and home applications.| String array| Yes (initial value: left empty)|
| uris     | URIs of the **want** that can be accepted by the ability. For details, see Table 20.| Object array  | Yes (initial value: left empty)|

Table 20 Internal structure of the uris attribute

| Attribute     | Description                      | Data Type| Initial Value Allowed          |
| ------------- | -------------------------- | -------- | -------------------- |
| scheme        | Scheme of the URI.       | String  | No          |
| host          | Host value of the URI.         | String  | Yes (initial value: left empty)|
| port          | Port number of the URI.         | String  | Yes (initial value: left empty)|
| pathStartWith | **pathStartWith** value of the URI.| String  | Yes (initial value: left empty)|
| path          | **path** value of the URI.         | String  | Yes (initial value: left empty)|
| pathRegx      | **pathRegx** value of the URI.     | String  | Yes (initial value: left empty)|
| type          | **type** value of the URI.         | String  | Yes (initial value: left empty)|

Example of the **skills** attribute structure:

```json
"skills": [
    {
        "actions": [
            "action.system.home"
        ], 
        "entities": [
            "entity.system.home"
        ],
        "uris": [
            {
                "scheme": "http",
                "host": "www.example.com",
                "port": "8080",
                "path": "query/student/name",
                "type": "text/*"
            }
        ]
    }
]
```

Table 21 reqPermissions

| Attribute  | Description                                                        | Data Type| Initial Value Allowed        |
| ---------- | ------------------------------------------------------------ | -------- | ------------------ |
| name      | Name of the permission to request.| String| No|
| reason    | Reason for requesting the permission. The value cannot exceed 256 bytes. Multi-language adaptation is required.| String| No if the requested permission is **user_grant** (if it is left empty, application release will be rejected)|
| usedScene | Application scenario and timing for using the permission. This attribute consists of the **ability** and **when** sub-attributes. **ability**: ability name. Multiple ability names can be configured. **when**: time for using the permission. The options are **inuse** and **always**.| Object| **ability**: mandatory for the **user_grant** permission and can be left empty in other cases<br> **when**: initial value allowed (initial value: **inuse**)|
For details, see [Access Control (Permission) Development](../security/accesstoken-guidelines.md#fa-model).

Table 22 Internal structure of the js attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed              |
| -------- | ------------------------------------------------------------ | -------- | ------------------------ |
| name     | Name of the JS component. The default value is **default**.   | String  | No                |
| pages    | Route information about all pages in the JS component, including the page path and page name. The value is an array, in which each element represents a page. The first element in the array represents the home page of the JavaScript FA.| Array    | No                |
| window   | Window-related configurations. This attribute applies only to the default, tablet, smart TV, head unit, and wearable device types. For details, see Table 23.| Object    | Yes                  |
| type     | Type of the JS component. Available values are as follows:<br>**"normal"**: indicates that the JavaScript component is an application instance.<br>**"form"**: indicates that the JavaScript component is a widget instance. | String  | Yes (initial value: **"normal"**) |
| mode     | Development mode of the JS component. For details, see Table 24.                            | Object    | Yes (initial value: left empty)      |

Table 23 Internal structure of the window attribute

| Attribute       | Description                                                        | Data Type| Initial Value Allowed             |
| --------------- | ------------------------------------------------------------ | -------- | ----------------------- |
| designWidth     | Baseline width for page design. The size of an element is scaled by the actual device width.| Number    | Yes (initial value: 720px)  |
| autoDesignWidth | Whether to automatically calculate the baseline width for page design. If it is set to **true**, the **designWidth** attribute becomes invalid. The baseline width is calculated based on the device width and screen density.| Boolean  | Yes (initial value: **false**)|

Table 24 Internal structure of the mode attribute

| Attribute| Description                | Data Type                           | Initial Value Allowed                 |
| -------- | -------------------- | ----------------------------------- | --------------------------- |
| type     | Type of the JS component. The value can be **"pageAbility"** or **"form"**. | String | Yes (initial value: **"pageAbility"**) |
| syntax   | Syntax type of the JS component. The value can be **"hml"** or **"ets"**. | String         | Yes (initial value: **"hml"**)      |

Example of the **js** attribute structure:

```json
"js": [
    {
        "name": "default", 
        "pages": [            
            "pages/index/index",
            "pages/detail/detail"
        ],         
        "window": {
            "designWidth": 720,
            "autoDesignWidth": false
        },
        "type": "form"
    }
]
```

Table 25 Internal structure of the shortcuts attribute

| Attribute  | Description                                                        | Data Type| Initial Value Allowed        |
| ---------- | ------------------------------------------------------------ | -------- | ------------------ |
| shortcutId | ID of the shortcut. The value is a string with a maximum of 63 bytes.                | String  | No          |
| label      | Label of the shortcut, that is, the text description displayed for the shortcut. The value can be a string or a resource index to the description. The value is a string with a maximum of 63 bytes.| String  | Yes (initial value: left empty)|
| icon       | Icon of the shortcut. The value is a resource index to the description.          | String  | Yes (initial value: left empty)|
| intents    | Intents to which the shortcut points. The attribute consists of the **targetClass** and **targetBundle** sub-attributes. For details, see Table 26.| Object array| Yes (initial value: left empty)|

Table 26 Internal structure of the intents attribute

| Attribute    | Description                                   | Data Type| Initial Value Allowed          |
| ------------ | --------------------------------------- | -------- | -------------------- |
| targetClass  | Target class of the shortcut.                 | String  | Yes (initial value: left empty)|
| targetBundle | Application bundle name for the target ability of the shortcut.| String  | Yes (initial value: left empty)|

Example of the **shortcuts** attribute structure:

```json
"shortcuts": [
    {
        "shortcutId": "id",
        "label": "$string:shortcut",
        "intents": [
            {
                "targetBundle": "com.example.world.test",
                "targetClass": "com.example.world.test.entry.MainAbility"
            }
        ]
    }
]
```

Table 27 Internal structure of the forms attribute

| Attribute           | Description                                                        | Data Type  | Initial Value Allowed              |
| ------------------- | ------------------------------------------------------------ | ---------- | ------------------------ |
| name                | Class name of the widget. The value is a string with a maximum of 127 bytes.                   | String    | No                |
| description         | Description of the widget. The value can be a string or a resource index to descriptions in multiple languages. The value is a string with a maximum of 255 bytes.| String    | Yes (initial value: left empty)      |
| isDefault           | Whether the widget is a default one. Each ability has only one default widget.<br>**true**: The widget is the default one.<br>**false**: The widget is not the default one.| Boolean    | No                |
| type                | Type of the widget. Available values are as follows:<br>**JS**: indicates a JavaScript-programmed widget.            | String    | No                |
| colorMode           | Color mode of the widget. Available values are as follows:<br>**auto**: The widget adopts the auto-adaptive color mode.<br>**dark**: The widget adopts the dark color mode.<br>**light**: The widget adopts the light color mode.| String    | Yes (initial value: **auto**)|
| supportDimensions   | Grid styles supported by the widget. Available values are as follows:<br>1 * 2: indicates a grid with one row and two columns.<br>2 * 1: indicates a grid with two rows and one column.<br>2 * 2: indicates a grid with two rows and two columns.<br>2 * 4: indicates a grid with two rows and four columns.<br>4 * 4: indicates a grid with four rows and four columns.| String array| No                |
| defaultDimension    | Default grid style of the widget. The value must be from the **supportDimensions** array of the widget.| String    | No                |
| updateEnabled       | Whether the widget can be updated periodically. Available values are as follows:<br>**true**: The widget can be updated periodically, depending on the update way you select, either at a specified interval (**updateDuration**) or at the scheduled time (**scheduledUpdateTime**). **updateDuration** is preferentially recommended.<br>**false**: The widget cannot be updated periodically.| Boolean  | No                |
| scheduledUpdateTime | Scheduled time to update the widget. The value is in 24-hour format and accurate to minute.        | String    | Yes (initial value: **0:0**) |
| updateDuration      | Interval to update the widget. The value is a natural number, in the unit of 30 minutes.<br>If the value is **0**, this field does not take effect.<br>If the value is a positive integer ***N***, the interval is calculated by multiplying ***N*** and 30 minutes.| Number      | Yes (initial value: **0**)   |
| formConfigAbility   | Name of the facility or activity used to adjust the ability.                        | String    | Yes (initial value: left empty)    |
| formVisibleNotify   | Whether the widget is allowed to use the widget visibility notification.                          | String    | Yes (initial value: left empty)    |
| jsComponentName     | Component name of the widget. The value is a string with a maximum of 127 bytes. This attribute is required only by JavaScript-programmed widgets.| String    | No                |
| metaData            | Metadata of the widget. The value contains value of the **customizeData** attribute. For details, see Table 13. | Object      | Yes (initial value: left empty)    |
| customizeData       | Custom information of the widget. For details, see Table 28.                            | Object array  | Yes (initial value: left empty)    |

Table 28 Internal structure of the customizeData attribute

| Attribute| Description                                               | Data Type| Initial Value Allowed          |
| -------- | --------------------------------------------------- | -------- | -------------------- |
| name     | Key name that identifies a data item. The value is a string with a maximum of 255 bytes.      | String  | Yes (initial value: left empty)|
| value    | Value of the data item. The value is a string with a maximum of 255 bytes.          | String  | Yes (initial value: left empty)|
| extra    | Current format of the custom data. The value indicates the resource.| String  | Yes (initial value: left empty)|

Example of the **forms** attribute structure:

```json
"forms": [
    {
        "name": "Form_Js",
        "description": "It's Js Form",
        "type": "JS",
        "jsComponentName": "card",
        "colorMode": "auto",
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "11:00",
        "updateDuration": 1,
        "defaultDimension": "2*2",
        "supportDimensions": [
            "2*2",
            "2*4",
            "4*4"
        ]
    },
    {
        "name": "Form_Js",
        "description": "It's JS Form",
        "type": "Js",
        "colorMode": "auto",
        "isDefault": false,
        "updateEnabled": true,
        "scheduledUpdateTime": "21:05",
        "updateDuration": 1,
        "defaultDimension": "1*2",
        "supportDimensions": [
            "1*2"
        ],
        "landscapeLayouts": [
            "$layout:ability_form"
        ],
        "portraitLayouts": [
            "$layout:ability_form"
        ],
        "formConfigAbility": "ability://com.example.myapplication.fa/.MainAbility",
        "metaData": {
            "customizeData": [
                {
                    "name": "originWidgetName",
                    "value": "com.example.weather.testWidget"
                }
            ]
        }
    }
]
```

Table 29 Internal structure of the distroFilter attribute

| Attribute     | Description                                                        | Data Type| Initial Value Allowed          |
| ------------- | ------------------------------------------------------------ | -------- | -------------------- |
| apiVersion    | Supported API versions. For details, see Table 30.                        | Object    | Yes (initial value: left empty)|
| screenShape   | Supported screen shapes. For details, see Table 31.                          | Object array| Yes (initial value: left empty)|
| screenWindow  | Supported window resolutions for when the application is running. This attribute applies only to the lite wearables. For details, see Table 32.| Object array| Yes (initial value: left empty)|
| screenDensity | Pixel density of the screen, in dots per inch (dpi). For details, see Table 33.       | Object array| Yes (initial value: left empty)|
| countryCode   | Country code used for distributing the application. For details, see the ISO-3166-1 standard. Multiple enumerated values of countries and regions are supported. For details, see Table 34.| Object array| Yes (initial value: left empty)|

Table 30 Internal structure of the apiVersion attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | An integer of the existing API version, for example, 4, 5, or 6. Example: If an application uses two software versions developed using API 5 and API 6 for the same device model, two installation packages of the entry type can be released.| Array    | Yes (initial value: left empty)|

Table 31 Internal structure of the screenShape attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | The value can be **circle** or **rect**. Example: Different HAPs can be provided for a smart watch with a circular face and that with a rectangular face.| Array    | Yes (initial value: left empty)|

Table 32 Internal structure of the screenWindow attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | Width and height of the screen. The value of a single string is in the format of Width x Height in pixels, for example, **454*454**.| Array    | Yes (initial value: left empty)|

Table 33 Internal structure of the screenDensity attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | Available values are as follows:<br>**sdpi**: screen density with small-scale dots per inch (SDPI). This value is applicable for devices with a DPI range of (0, 120].<br>**mdpi**: screen density with medium-scale dots per inch (MDPI). This value is applicable for devices with a DPI range of (120, 160].<br>**ldpi**: screen density with large-scale dots per inch (LDPI). This value is applicable for devices with a DPI range of (160, 240].<br>**xldpi**: screen density with extra-large-scale dots per inch (XLDPI). This value is applicable for devices with a DPI range of (240, 320].<br>**xxldpi**: screen density with extra-extra-large-scale dots per inch (XXLDPI). This value is applicable for devices with a DPI range of (320, 480].<br>**xxxldpi**: screen density with extra-extra-extra-large-scale dots per inch (XXXLDPI). This value is applicable for devices with a DPI range of (480, 640].| Array    | Yes (initial value: left empty)|

Table 34 Internal structure of the countryCode attribute

| Attribute| Description                                                        | Data Type  | Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | ---------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String    | Yes (initial value: left empty)|
| value    | Country code of the area to which the application is to be distributed. The value is a string array, of which each substring indicates a country or region. The substring consists of two uppercase letters.| String array| Yes (initial value: left empty)|

Example of the **distroFilter** attribute structure:

```json
"distroFilter":  {
    "apiVersion": {
        "policy": "include",
        "value": [4,5]
    },
    "screenShape": {
        "policy": "include",
        "value": ["circle","rect"]
    },
    "screenWindow": {
        "policy": "include",
        "value": ["454*454","466*466"]
    },
    "screenDensity":{
    	"policy": "exclude",
    	"value": ["ldpi","xldpi"]
	},
	"countryCode": {
        "policy":"include",
        "value":["CN","HK"]
    }
}
```

Table 35 Internal structure of the commonEvents attribute

| Attribute  | Description                                                        | Data Type  | Initial Value Allowed        |
| ---------- | ------------------------------------------------------------ | ---------- | ------------------ |
| name       | Name of a static broadcast.                                            | String    | No          |
| permission | Permission needed to implement the static common event.                  | String array| Yes (initial value: left empty)|
| data       | Additional data array to be carried by the current static common event.                | String array| Yes (initial value: left empty)|
| type       | Type array of the current static common event.                    | String array| Yes (initial value: left empty)|
| events     | A set of events for the wants that can be received. The value can be system predefined or custom.| String array| No          |

Example of the **commonEvents** attribute structure:

```json
"commonEvents": [
    {
        "name":"MainAbility",
        "permission": "string",
        "data":[
            "string",
            "string"
        ],
        "events": [
            "string",
            "string"
        ]
    }
]
```

Table 36 Internal structure of the testRunner attribute

| Attribute| Description                | Data Type| Initial Value Allowed|
| -------- | -------------------- | -------- | ---------- |
| name     | Name of the test runner object.| String  | No  |
| srcPath  | Path of the test runner code.| String  | No  |

```json
"testRunner": {
    "name": "myTestRUnnerName",
    "srcPath": "etc/test/TestRunner.ts"
}
```

Table 37 Internal structure of the definePermissions attribute
**definePermission** applies only to system applications and does not take effect for third-party applications.

| Attribute               | Description                                                        | Data Type| Initial Value Allowed|
| ----------------------- | ------------------------------------------------------------ | -------- | ---------- |
| name                    | Permission name.                                              | String  | No  |
| grantMode               | Permission grant mode.<br>Available values are as follows:<br>**"system_grant"**: The permission is automatically granted by the system after the application is installed.<br>**"user_grant"**: The permission must be dynamically requested and can be used only after being granted by the user. | String  | Yes (initial value: **"system_grant"**) |
| availableLevel          | Permission level. Available values are as follows:<br>**"system_core"**: core system permission.<br>**"system_basic"**: basic system permission.<br>**"normal"**: normal permission, which is open to all applications. | String  | Yes (initial value: **"normal"**) |
| provisionEnable         | Whether the permission can be requested in provision mode. | Boolean  | Yes (initial value: **true**) |
| distributedSceneEnabled | Whether the permission can be used in distributed scenarios. | Boolean  | Yes (initial value: **false**) |
| label                   | Brief description of the permission. The value is a resource index.            | String  | Yes    |
| description             | Detailed description of the permission, which can be a string or a resource index.| String  | Yes    |
