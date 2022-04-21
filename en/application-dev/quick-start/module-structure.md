

# Application Package Structure Configuration File

When developing an application in the FA model, you need to declare the package structure of the application in the **config.json** file. Similarly, when developing an application in the stage model, you need to declare the package structure of the application in the **module.json** file.

## Internal Structure of the config.json File

The **module.json** file consists of two parts: **app** and **module**. See Table 1 for details.

Table 1 Internal structure of the module.json file

| Attribute| Description                                                        | Data Type| Default|
| -------- | ------------------------------------------------------------ | -------- | ---------- |
| app      | Global configuration of an application. Different HAP files of the same application must use the same **app** configuration. For details, see [Internal Structure of the app Tag](#internal-structure-of-the-app-tag).| Object    | No        |
| module   | Configuration of a HAP file. The ***module*** configuration is valid only for the current HAP file. For details, see [Internal Structure of the module Tag](#internal-structure-of-the-module-tag).| Object    | No        |

Example of the module.json file:

```json
{
    "app": {
        "bundleName": "com.application.music",
        "vendor": "application",
        "versionCode": 1,
        "versionName": "1.0",
        "minCompatibleVersionCode": 1,
        "apiCompatibleVersion": 7,
        "apiTargetVersion": 8,
        "apiReleaseType": "Release",
        "debug": false,
        "icon" : "$media:app_icon",
        "label": "$string:app_name",
        "description": "$string:description_application",
        "distributedNotificationEnabled": true,
        "entityType": "game",
        "car": {
            "apiCompatibleVersion": 8
         }
    },
    "module": {
        "name": "myHapName",
        "type": "entry|feature|har",
        "srcEntrance" : "./MyAbilityStage.js",
        "description" : "$string:description_application",
        "process": "string", 
        "mainElement": "MainAbility",
        "deviceTypes": [
            "tablet", 
            "tv", 
            "wearable", 
            "liteWearable", 
            "ar", 
            "vr", 
            "car", 
            "earphones", 
            "speaker", 
            "smartVision", 
            "linkIoT", 
            "router",
        ],
        "deliveryWithInstall": true,
        "installationFree": false,
        "virtualMachine": "ark | default",
        "metadata": [
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file1"
            },
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file2"
            }
        ],
        "metadata": [
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file1"
            },
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file2"
            }
        ],
        "abilities": [
            {
                "name": "MainAbility",
                "srcEntrance" : "./login/MyMainAbility.ts",
                "description": "$string:description_main_ability",
                "icon": "$media:icon",
                "label": "HiMusic",
                "visible": true,
                "skills": [
                    {
                        "actions": [
                            "action.system.home"
                        ],
                        "entities": [
                            "entity.system.home"
                        ],
                        "uris": [ ]
                    }
                ],
                "backgroundModes": [
                    "dataTransfer",
                    "audioPlayback",
                    "audioRecording",
                    "location",
                    "bluetoothInteraction",
                    "multiDeviceConnection",
                    "wifiInteraction",
                    "voip",
                    "taskKeeping"
                ],
            }
        ],
        "abilities": [
            {
                "name": "MainAbility",
                "srcEntrance" : "./login/MyMainAbility.ts",
                "description": "$string:description_main_ability",
                "icon": "$media:icon",
                "label": "HiMusic",
                "visible": true,
                "skills": [
                    {
                        "actions": [
                            "action.system.home"
                        ],
                        "entities": [
                            "entity.system.home"
                        ],
                        "uris": [ ]
                    }
                ],
                "backgroundModes": [
                    "dataTransfer",
                    "audioPlayback",
                    "audioRecording",
                    "location",
                    "bluetoothInteraction",
                    "multiDeviceConnection",
                    "wifiInteraction",
                    "voip",
                    "taskKeeping"
                ],
            }
        ],
        "requestPermissions": [
            {
                "name": "ohos.abilitydemo.permission.PROVIDER",
                "reason": "$string:reason",
                "usedScene": {
                    "abilities": [
                        "FormAbility"
                    ],
                    "when": "inuse"
                }
            }
        ]
    }
}
```

### Internal Structure of the app Tag

This tag is an attribute of the entire application. It affects the left and right hap and components in the application and will not be replaced by hap or components. For an internal structure of the label, refer to Table 2.

Table 2 Internal structure of the app tag

| Attribute                      | Description                                                        | Data Type| Default                                 |
| ------------------------------ | ------------------------------------------------------------ | -------- | ------------------------------------------- |
| bundleName                     | Bundle name of the application. It uniquely identifies the application. This attribute cannot be left empty. The value must meet the following rules:<br> 1) Consists of letters, digits, underscores (_), and periods (.).<br> (2) Starts with a letter.<br> (3) Contains 7 to 127 bytes.<br> You are advised to use the reverse domain name format, for example, com.example.xxx. The first level is the domain name suffix com, the second level is the vendor/individual name, and the third level is the application name. Multiple levels are supported.<br> The application compiled with the system source code must be named in the format of com.ohos.xxx, where ohos indicates the OpenHarmony system application.| String  | No                                         |
| debug                          | Indicates whether an application can be debugged.                                  | Boolean  | No (initial value: **false**)              |
| icon                           | Icon of the application. The value is the index to the resource file.              | String  | No                           |
| label                          | Name of the application. The value is a resource index to descriptions in multiple languages.| String  | No                           |
| description                    | Description of the application. The value can be a string or a resource index to descriptions in multiple languages.| String  | Yes (initial value: left empty)                 |
| vendor                         | Application vendor. The value is a string of a maximum of 255 bytes.| String  | Yes (initial value: left empty)                 |
| versionCode                    | Version number of the application. The value is a 32-bit non-negative integer. The value is used only to determine whether a version is later than another version. A larger value indicates a later version. You can set the value to any positive integer. However, you must ensure that the new version of the application uses a value greater than any earlier version. The value must be less than 2 to the power of 31.| Number    |                                             |
| versionName                    | Text description of the version number, which is displayed to users.<br>The value consists of only digits and dots. The A.B.C.D four-segment format is recommended. The meaning of the four-segment format is as follows:<br>Segment 1: major version number. The value ranges from 0 to 99. This segment indicates the version that is modified greatly, for example, the version that implements a new major function or has a major change.<br>Segment 2: minor version number. The value ranges from 0 to 99. This segment indicates outstanding features, such as new function addition and major issue rectification.<br>Segment 3: feature version number. The value ranges from 0 to 99. This segment indicates the planned new version features.<br>Segment 4: revision version number or patch. The value ranges from 0 to 999. This segment indicates a maintenance version for fixing bugs.| String  | No                             |
| minCompatibleVersionCode       | Minimum API version required for running the application.                       | Number    | Yes (initial value: value of **versionCode**)|
| minAPIVersion                  | Target API version required for running the application.                       | Number    | No                           |
| targetAPIVersion               | Target API version required for running the application.                       | Integer    | No                           |
| apiReleaseType                 | Type of the target API version required for running the application. The value is a string. The value can be **CanaryN**, **BetaN**, or **Release**, where **N** represents a positive integer.<br>Canary: indicates a restricted release.<br>Beta: indicates a publicly released beta version.<br>Release: indicates a publicly released official version.| String  | Yes (initial value: **Release**)            |
| distributedNotificationEnabled | Whether the distributed notification feature is enabled for the application.                        | Boolean  | Yes (initial value: **true**)               |
| entityType                     | Category of the application, which can be: game, media, communication, news, travel, utility, shopping, education, kids, business, and photography.| String  | Yes (initial value: unspecified)        |

### Internal Structure of the module Tag

This tag specifies the HAP configuration, which only applies to the current HAP file.

Table 3 Internal structure of the module tag

| Attribute           | Description                                                        | Data Type  | Default                           |
| ------------------- | ------------------------------------------------------------ | ---------- | ------------------------------------- |
| name                | Name of the current module. After the module is packed into the HAP, this attribute indicates the name of the HAP. The value is a string containing a maximum of 31 bytes and must be unique in the entire application.| String    | No                     |
| type                | Type of the current HAP file. There are three types: entry, feature, and har.| String    | No                     |
| srcEntrance         | Path of the entry JS code corresponding to the HAP. The value is a string containing a maximum of 127 bytes.| String    | Yes                       |
| description         | Description of the HAP file. The value can be a string or a resource index to descriptions in multiple languages.| String    | Yes (initial value: left empty)           |
| process             | Process of the HAP file. The value is a string with a maximum of 31 bytes. If a process is configured in the **hap** tag, all abilities of the application run in this process.| String    | Yes (initial value: name of the HAP)            |
| mainElement         | Entrance ability name or extension name of the HAP. Only the ability or extension whose value is **mainElement** can be displayed in the Service Center. This attribute cannot be left empty for an OpenHarmony atomic service.| String    | Yes for an OpenHarmony application    |
| deviceTypes         | Types of the devices on which the HAP can run. The value is a string array. Table 4 lists the device types predefined by the system.<br>Different from **syscap**, which is based on the device capability (such as Bluetooth and Wi-Fi), **deviceTypes** is based on the device type.| String array| No (can be left empty)         |
| deliveryWithInstall | Whether this HAP will be installed when the user installs the application. The value **true** indicates that the HAP file will be automatically installed when the user installs the application. Value "false" indicates the opposite.| Boolean    | No                     |
| installationFree    | Whether the HAP file supports the installation-free feature. No default value is allowed for the HAP file.<br>**true**: The HAP file supports the installation-free feature and meets installation-free constraints.<br>**false**: The HAP file does not support the installation-free feature.<br><br>When **entry.hap** is set to **true**, all **feature.hap** fields related to **entry.hap** must be **true**.<br>When **entry.hap** is set to **false**, **feature.hap** related to **entry.hap** can be set to **true** or **false** based on service requirements.| Boolean    | No                     |
| virtualMachine      | Type of the target VM where the current HAP is running. It is used for cloud distribution, such as the application market and distribution center.<br>The value is a string. If the target VM type is Ark, the value is **ark**. Otherwise, the value is **default**. This attribute is automatically inserted when the IDE builds the HAP. When the decompression tool parses the HAP file, if the HAP file does not contain this attribute, the value is set to **default**.| String    | Yes (initial value: **default**)    |
| uiSyntax            | **syntax**: defines the syntax type of the JS component.<br>**hml**: indicates that the JS component is developed using HML, CSS, or JS.<br>**ets**: indicates that the JS component is developed using the eTS declarative syntax.| String    | Yes (initial value: **hml**)            |
| pages               | Profile resource used to list information about each page in the JS component. For details about how to use pages, see the pages example.| Object      | No in the ability scenario|
| metadata            | Custom metadata of the HAP. The configuration is valid only for the current module, ability, or extensionAbility. For details about metadata, see [Internal Structure of the metadata Attribute](#internal-structure-of-the-metadata-attribute).| Array      | Yes (initial value: left empty)           |
| abilities           | Metadata capability configuration. The configuration under this tag is valid only for the current ability. For details about the capabilities, see [Internal Structure of the abilities Attribute](#internal-structure-of-the-abilities-attribute).| Object      | Yes (initial value: left empty)           |
| extensionAbilities  | Configuration information of extensionAbilities. The configuration under this tag is valid only for the current extensionAbility. For details about extensionAbilities, see [Internal structure of the extensionAbility attribute](#internal-structure-of-the-extensionAbility-attribute).| Object      | Yes (initial value: left empty)           |
| requestPermissions  | A set of permissions that the application needs to apply for from the system when the application is running. For details about requestPermissions, see [Internal structure of the requestPermissions attribute](#internal-structure-of-the-requestPermissions-attribute).| Object      | Yes (initial value: left empty)           |

Table 4 System-defined deviceTypes values

| Value      | Device Type                                                |
| ------------ | -------------------------------------------------------- |
| tablet       | Tablet, speaker with a screen                            |
| tv           |                                                          |
| wearable     | Smart watch, kids watch, especially a watch that packs a wide array of resources |
| liteWearable | Basic functions watch, sports watch                                  |
| ar           |                                                          |
| vr           |                                                          |
| car          |                                                          |
| earphones    |                                                          |
| speaker      | Speaker without a screen, speaker with a screen                     |
| smartVision  | Devices with cameras                |
| linkIoT      | Wi-Fi module, Bluetooth module                                    |
| router       | Router                                                  |

Example of deviceTypes:

```json
{
	"module": {
		"name": "myHapName",
        "type": "har",
        "deviceTypes" : [
            "wearable"
        ]
	}
}
```

Example of pages:

```json
{
    "module": {
       "name": "myHapName",
        "type": "har",
        "deviceTypes" : [
            "wearable"
        ],
        "pages": "$profile:pages_config"
    }
}
```

pages_config configuration file

```json
{
    "src": [
        "pages/index/index",
        "pages/second/second",
        "pages/third/third",
        "pages/four/four"
    ]
}
```



#### Internal Structure of the metadata Attribute

Configuration information about the module, ability, and extensionAbility. The value is of the array type. The configuration is valid only for the current module, ability, or extensionAbility.

Table 5 Internal structure of the metadata attribute

| Attribute| Description                                                        | Data Type| Default                |
| -------- | ------------------------------------------------------------ | -------- | -------------------------- |
| name     | Key of a data element. The value is a string with a maximum of 255 bytes.   | String  | Yes (initial value: left empty) |
| value    | This tag indicates the value of a data item. The tag value is a character string containing a maximum of 255 bytes.   | String  | Yes (initial value: left empty)        |
| resource | Custom data format. The value is an index to the resource that identifies the data.| String  | Yes (initial value: left empty)        |

Example of metadata:

```json
{ 
    "module": {
        "metadata": [
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file"
            },
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file"
            }
        ]
    }
}
```

#### Internal Structure of the abilities Attribute

The **abilities** attribute describes the ability configuration information. The value is of the array type.

Table 6 Internal structure of the abilities attribute

| Attribute           | Description                                                        | Data Type  | Default                                                  |
| --------------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| name            | Logical name of the ability, which must be unique in the entire application. The value is a string containing a maximum of 127 bytes.| String    | No                                            |
| srcEntrance     | JS code path corresponding to the ability. The tag value is a string containing a maximum of 127 bytes.| String    | No                                            |
| launchType      | Ability startup mode. The value can be **standard**, **singleton**, or **specified**. The default value is **standard**. The value **standard** indicates common multi-instance, the value **specified** indicates that multiple instances are configured for the ability based on the service, and the value **singleton** indicates a singleton.| String    | Yes (initial value: **standard**)                              |
| description     | Ability description. The value can be a string or a resource index to descriptions in multiple languages.| String    | Yes (initial value: left empty)                                  |
| icon            | Icon of the ability. The value is the index to the resource file. This attribute can be left empty, and the default value is an empty array.<br>If **ability** is set to **MainElement**, this attribute is mandatory.| String    | Yes (initial value: left empty)<br>If **ability** is set to **MainElement**, this attribute is mandatory.|
| permissions     | A set of permissions that need to be applied for when the capability of another application is invoked. The value is a character string array. Each array element is a permission name, which is usually represented by a reverse domain name (a maximum of 255 bytes). The permission can be predefined by the system or customized by the application. For the latter, the value must be the same as the **name** value of a permission defined in the **defPermissions** attribute. This attribute can be left empty, and the default value is an empty array.| String array| Yes (initial value: left empty)                                  |
| metadata        | Metadata about the ability. For details about metadata, see [Internal Structure of the metadata Attribute](#internal-structure-of-the-metadata-attribute).| Array      | Yes (initial value: left empty)   |
| visible         | Indicates whether the Ability can be invoked by other applications. The value is a boolean value. Value "true" means that the Ability can be invoked by other applications, and "false" means the opposite.| Boolean    | Yes (initial value: **false**)                               |
| continuable     | Indicates whether the ability can be migrated. The value is a Boolean value. The value true indicates that the ability can be migrated, and the value false indicates that the ability cannot be migrated.| Boolean    | Yes (initial value: **false**)                               |
| skills          | Feature set of wants that can be received by the ability. The tag is in array format.<br>Configuration rule: In an entry package, you can configure the ability of multiple **skill** attributes (**action.system.home** and **entity.system.home** are configured) that have the entry capability. The label and icon in the first **skill** attribute that is configured are used as the label and icon of the OpenHarmony service or application.<br>The skills tag with the entry capability cannot be configured for the feature package of the OpenHarmony service.<br>The **skill** attribute with the entry capability can be configured for the feature package of the OpenHarmony application.<br>For details about the internal structure of **skills**, see [Internal Structure of the skills Attribute](#internal-structure-of-the-skills-attribute).| Array      | Yes (initial value: left empty)   |
| backgroundModes | Continuous task modes of the ability.<br>Continuous tasks are classified into the following types:<br>**dataTransfer**: service for downloading, backing up, sharing, or transferring data from the network or peer devices<br>**audioPlayback**: audio playback service<br>**audioRecording**: audio recording service<br>**location**: location and navigation services<br>**bluetoothInteraction**: Bluetooth scanning, connection, and transmission services (wearables)<br>**multiDeviceConnection**: multi-device interconnection service<br>**wifiInteraction**: Wi-Fi scanning, connection, and transmission services (multi-screen cloning)<br>**voip**: voice/video call and VoIP services<br>**taskKeeping**: computing service.<br> | String    | Yes (initial value: left empty)                                          |

Example of the abilities attribute structure:

```json
{
    "abilities": [{
        "name": "MainAbility",
        "srcEntrance": "./ets/login/MyLoginAbility.ts",
        "launchType":"standard"
        "description": "$string:description_main_ability",
        "icon": "$media:icon",
        "label": "Login",
        "permissions": [],
        "metadata": [],
        "visible": true,
        "continuable": true,
        "skills": [{
            "actions": ["action.system.home"],
            "entities": ["entity.system.home"],
            "uris": []
        }],
        "backgroundModes": [
            "dataTransfer",
            "audioPlayback",
            "audioRecording",
            "location",
            "bluetoothInteraction",
            "multiDeviceConnection",
            "wifiInteraction",
            "voip",
            "taskKeeping"
        ],
    }],
}
```

#### Internal Structure of the skills Attribute

This attribute identifies a want feature that can be received by the ability or extension.

Table 7 Internal structure of skills

| Attribute| Description                                                        | Data Type  | Default          |
| -------- | ------------------------------------------------------------ | ---------- | -------------------- |
| actions  | A set of want action values that can be received. The value can be a value predefined by the system or a custom value.| String array| Yes (initial value: left empty)|
| entities | Categories of abilities that can receive the want. The value can be a value predefined by the system or a custom value.| String array| Yes (initial value: left empty)|
| uris     | Data specifications to be added to the want filter. The specification can be of data type only (**mimeType** attribute), URI only, or both. For details about the internal structure of **uris**, see Table 8.| Object array  | Yes (initial value: left empty)|

Table 8 Internal structure of the uris attribute

| Attribute| Description               | Data Type| Default          |
| -------- | ------------------- | -------- | -------------------- |
| scheme   | Scheme in the URI.| String  | No          |
| host     | Host in the URI.  | String  | Yes (initial value: left empty)|
| port     | Port number in the URI.  | String  | Yes (initial value: left empty)|
| path     | Path in the URI.  | String  | Yes (initial value: left empty)|
| type     | Type of the URI.  | String  | Yes (initial value: left empty)|

Example of the skills attribute structure:

```json
{
    "abilities": [
        {
            "skills": [
                {
                    "actions": [
                        "action.system.home"
                    ],
                    "entities": [
                        "entity.system.home"
                    ],
                    "uris": [
                        {
                            "scheme":"uri2",
                            "host":"host2",
                            "port":"port2",
                            "pathStartWith":"path2",
                            "pathRegex":"/query/.*",
                            "path":"path",
                            "type": "text/*"
                        },
                    ]
                }
            ],
        }
    ],
    "extensionAbilities": [
        {
            "skills": [
                {
                    "actions": [
                    ],
                    "entities": [
                    ],
                    "uris": [
                        {
                            "scheme":"uri2",
                            "host":"host2",
                            "port":"port2",
                            "pathStartWith":"path2",
                            "pathRegex":"/query/.*",
                            "path":"path",
                            "type": "text/*"
                        },
                    ]
                }
            ],
        }
    ],
}
```

#### Internal Structure of the extensionAbility Attribute

The **extensionAbility** attribute describes the configuration information of **extensionAbility**. The configuration is valid only for the current extensionAbility.

Table 9 Internal structure of the extensionAbility attribute

| Attribute   | Description                                                        | Data Type  | Default                   |
| ----------- | ------------------------------------------------------------ | ---------- | ----------------------------- |
| name        | Logical name of the current extensionAbility. The value is a string containing a maximum of 127 bytes. The name must be unique in the entire application.| String    | No             |
| srcEntrance | JS code path corresponding to extensionAbility. The value is a character string containing a maximum of 127 bytes.| String    | No             |
| description | Description of the extensionAbility. The value can be a string or a resource index to descriptions in multiple languages.| String    | Yes (initial value: left empty)   |
| icon        | Icon of the extensionAbility. The value is the index to the resource file. If **extensionAbility** is set to **MainElement**, this attribute is mandatory.| String    | Yes (initial value: left empty)   |
| label       | Name of the extensionAbility displayed to users. The value is a resource index to names in multiple languages.<br>If **extensionAbility** is set to **MainElement**, this attribute is mandatory and the value must be unique in the application.| String    | No             |
| type        | Type of the extension capability. The value can be form, workScheduler, inputMethod, service, accessibility, dataShare, fileShare, staticSubscriber or wallpaper.| String    | No             |
| permissions | A set of permissions that need to be applied for when the capability of another application is invoked. The value is a character string array. Each array element is a permission name, which is usually represented by a reverse domain name (a maximum of 255 bytes). The permission can be predefined by the system or customized by the application. For the latter, the value must be the same as the **name** value of a permission defined in the **defPermissions** attribute.| String array| Yes (initial value: left empty)   |
| uri         | Data URI provided by the ability. The value is an array containing a maximum of 255 characters and is in the format of a reverse domain name. This attribute is mandatory when **type** is set to **extensionAbility** of the dataShare type.| String    | Yes (initial value: left empty)   |
| skills      | Feature set of wants that can be received by the ability.<br>Configuration rule: In an entry package, you can configure the ability of multiple **skill** attributes (**action.system.home** and **entity.system.home** are configured) that have the entry capability. The **label** and **icon** in the first ability that has **skills** configured are used as the **label** and **icon** of the OpenHarmony service or application.<br>The **skills** attribute with the entry capability cannot be configured for the feature package of the OpenHarmony service.<br>The **skills** attribute with the entry capability can be configured for the feature package of the OpenHarmony application.<br>For details about the internal structure of **skills**, see [Internal Structure of the skills Attribute](#internal-structure-of-the-skills-attribute).| Array      | Yes (initial value: left empty)   |
| metadata    | Metadata of extensionAbility. For details about metadata, see [Internal Structure of the metadata Attribute](#internal-structure-of-the-metadata-attribute).| Object      | Yes (initial value: left empty)   |
| visible     | Whether extensionAbility can be invoked by other applications. The value is of the Boolean type. The value **true** means that it can be invoked by other applications, and the value **false** means the opposite.|            | Yes (initial value: **false**)|

Example of extensionAbility:

```json
{
    "extensionAbilities": [
        {
            "name": "FormName",
            "srcEntrance": "./form/MyForm.ts",
            "icon": "$media:icon",
            "label" : "$string:extension_name",
            "description": "$string:form_description",
            "type": "form", 
            "permissions": ["ohos.abilitydemo.permission.PROVIDER"],
            "readPermission": "",
            "writePermission": "",
            "visible": true,
            "uri":"scheme://authority/path/query"
            "skills": [{
                "actions": [],
                "entities": [],
                "uris": []
            }],
            "metadata": [
                {
                    "name": "ohos.extability.form",
                    "resource": "$profile:form_config", 
                }
            ],
        }
    ]
}

```

#### Internal Structure of the requestPermissions Attribute

This attribute identifies a set of permissions that the application needs to apply for from the system when the application is running.

Table 10 requestPermissions fields

| Attribute | Description                                                        | Type                       | **Value Range**                                               | **Default Value**            | **Restrictions**                                                |
| --------- | ------------------------------------------------------------ | ------------------------------- | ----------------------------------------------------------- | ---------------------- | ------------------------------------------------------------ |
| name      | Permission name, which is mandatory.                              | String                         | Custom                                                     | None                    | Parsing will fail if this field is not set.                                        |
| reason    | Optional. This field is mandatory when the requested permission is **user_grant**. Reason for requesting the permission.| String                         | The displayed text cannot exceed 256 bytes.                            | Empty                    | This attribute is mandatory for the **user_grant** permission. If it is left empty, application release will be rejected. Multi-language adaptation is required. |
| usedScene | Optional. This field is mandatory when the requested permission is **user_grant**. Describes the application scenario and timing for using the permission. This attribute consists of the **ability** and **when** sub-attributes. Multiple abilities can be configured.| **ability**: string array; **when**: string| **ability**: ability name; **when**: **inuse** or **always**| **ability**: left empty; **when**: **inuse**| The **ability** sub-attribute is mandatory for the **user_grant** permission, and the **when** field is optional.                     |

Example of requestPermissions:

```json
{
    "usedScene": {
        "abilities": [
            "AudioAbility",
            "VedioAbility",
        ],
        "when": "inuse"
    }
}
```

#### Internal Structure of the form Attribute

The **forms** attribute indicates the service widget configuration. The service widget is a brief application view that can be embedded on the home screen and periodically updated. The **form** attribute can be contained in the following scenarios:

1. Set **type** to **form** in **extensions**.

2. Specify the **form** information in metadata,
   	  where **name** indicates the name of the service widget,**ohos.extability.form** indicates the identifier of the service widget,
      	  and **resource** indicates the resource location of the service widget.

Table 11 Internal structure of the forms attribute

| Attribute         | Description                                                        | Data Type  | Default                   |
| ----------------- | ------------------------------------------------------------ | ---------- | ----------------------------- |
| name              | Class name of the widget. The value is a string with a maximum of 127 bytes.                   | String    | No                           |
| description       | Description of the widget. The value can be a string or a resource index to descriptions in multiple languages. The value is a string with a maximum of 255 bytes.| String    | Yes (initial value: left empty)           |
| src               | UI code of a JS service widget. It is recommended that you use the adaptive layout to display a service widget of different specifications. If the layout of a service widget of different specifications differs greatly, you are advised to use different service widgets.| String    | Yes (initial value: left empty)           |
| window            | Adaptive capability of a JS service widget. For details about the window structure, see Table 12.          | Object      | Yes (initial value: left empty)           |
| isDefault         | Whether the widget is a default one. Each ability has only one default widget. **true**: The widget is the default one. **false**: The widget is not the default one.| Boolean    | No                           |
| colorMode         | Theme style of a service widget. The options are as follows: **auto**; **dark**: The widget adopts the dark color mode; **light**: The widget adopts the light color mode.| String    | Yes (initial value: **auto**)     |
| supportDimensions | Appearance specifications supported by the widget. The options are as follows: 1 * 2: indicates a grid with one row and two columns. 2 * 2: indicates a grid with two rows and two columns. 2 * 4: indicates a grid with two rows and four columns. 4 * 4: indicates a grid with four rows and four columns.| String array| No                           |
| defaultDimension  | Default grid style of the widget. The value must be available in the **supportDimensions** array of the widget.| String    | No                           |
| updateDuration    | Update frequency of a widget. The unit is 30 minutes. The value is a multiple of 30. The highest frequency of refreshing a widget is once every 30 minutes. You can also use scheduled refresh to refresh a widget at a fixed time or once every 30 minutes. If both of them are configured, the scheduled refresh takes precedence.| Number      | Yes (initial value: left empty)           |
| metadata          | Custom information about a widget. For details about the internal structure of metadata, see Table 5.       | Object      | Yes (initial value: left empty)           |
| formConfigAbility | Ability name for widget adjustment. The value is a string of up to 127 characters. The value must be in the following format:<br>ability:// Name of an ability.<br>The name must be the same as that of the current application.| String    | Yes (initial value: left empty)           |
| formVisibleNotify | Whether the widget is allowed to use the visibility notification. The value is **true** or **false**.| Boolean    | Yes (initial value: **false**)|

Table 12 Internal structure of window

| Attribute       | Description                                                        | Data Type| Default          |
| --------------- | ------------------------------------------------------------ | -------- | -------------------- |
| designWidth     | Baseline width of the page design, in pixels. The element size is scaled by the actual device width. The value is an integer.| Number    | Yes (initial value: left empty)|
| autoDesignWidth | Whether to automatically calculate the baseline width of the page design. If this parameter is set to **true**, the **designWidth** attribute is invalid. The baseline width is calculated based on the device width and screen density.| Boolean  | Yes (initial value: left empty)|

Example of the form attribute structure:

Define the **form_config.json** file in **resources/base/profile** of the development view. (The file name can be defined by developers.)

```json
{
    "forms": [
        {
            "name": "Form_Js",
            "description": "$string:form_description",
            "src": "./js/pages/card/index",
            "window": {
                "designWidth": 720,
                "autoDesignWidth": true
            },
            "colorMode": "auto",
            "formConfigAbility": "ability://xxxxx",
            "formVisibleNotify": false,
            "isDefault": true,
            "updateEnabled": true,
            "scheduledUpdateTime": "10:30",
            "updateDuration": 1,
            "defaultDimension": "2*2",
            "supportDimensions": [
                "2*2"
            ],
           "metadata": [
             {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file"
             }
           ] 
        }
    ]
}
```

Define metadata information in the **extension** component of the **module.json** file.

```json
{
	"extensionAbilities": [
        {
            "name": "MyForm",
            "type": "form", 
            "metadata": [
                {
                    "name": "ohos.extability.form",
                    "resource": "$profile:form_config",
                }
            ],
        }
	]
}
```

#### Internal Structure of the shortcuts Attribute

This attribute identifies the shortcut information of an application. The value is an array. A maximum of four shortcuts can be configured. It contains four sub-attributes: **shortcutId**, **label**, **icon**, and **intents**.

The shortcut information is identified in metadata, where:
(1) **name**: name of a shortcut.**ohos.ability.shortcut** is used as the identifier of the shortcut.
(2) **resource**: resource location of the shortcut.

Table 13 Internal structure of the shortcuts attribute

| Attribute  | Description                                                        | Data Type| Default                |
| ---------- | ------------------------------------------------------------ | -------- | -------------------------- |
| shortcutId | Shortcut ID. The value is a string with a maximum of 63 bytes.                | String  | No                        |
| label      | Label of the shortcut, that is, the text description displayed by the shortcut. The value can be a string or a resource index to the description. The value is a string with a maximum of 63 bytes.| String  | Yes (initial value: left empty)        |
| icon       | Icon of the shortcut. The value is the index to the resource file.          | String  | Yes (initial value: left empty)|
| wants      | Wants to which the shortcut points. The attribute consists of the **bundleName** and **abilityName** sub-attributes.<br>**bundleName**: target bundle name of the shortcut, which is a string.<br>**abilityName**: target component name of the shortcut, which is a string.| Object    | Yes (initial value: left empty)  |

Define the **shortcut_config.json** file in **resources/base/profile** of the development view. (The file name can be defined by developers.)

```json
{
        "shortcuts": [
            {
                "shortcutId": "id_test1",
                "label": "$string:shortcut",
                "icon": "$media:aa_icon",
                "wants": [
                    {
                       "bundleName": "com.ohos.hello"
                       "abilityName": "MainAbility"
                    }
                ]
            }
        ]
}
```

Define the metadata information under **module** in the **config.json** file as follows:

```json
{
    "module": {
        "name": "MyAbilityStage",
        "abilities" : [
            {
                "name" : "MyAbility",
                "srcEntrance": "./abilities/MyAbility.ts",
                "skills": [{
                            "actions": ["action.system.home"],
                            "entities": ["entity.system.home"],
                            "uris": []
                }],
                "metadata": [
                    {
                        "name": "ohos.ability.shortcut",
                        "resource": "$profile:shortcuts_config", 
                    }
                ],
            }
        ]
    }
}
```

#### Internal Structure of the commonEvents Attribute

The **commonEvents** attribute identifies the registered static common event information. The value is an array.
The **commonEvent** information is defined in the metadata, where:

1. **name**: name of a common event.**ohos.extability.staticSubscriber** is used as the common event ID.

2. **resource**: resource location of the **commonEvent** information.

Table 14 Internal structure of the commonEvents attribute

| Attribute  | Description                                                        | Data Type  | Default                |
| ---------- | ------------------------------------------------------------ | ---------- | -------------------------- |
| name       | Ability name corresponding to the current static common event. The class must be marked in the ability.| String    | No          |
| permission | Permission required for implementing the static common event. The value is a string with a maximum of 255 bytes, in the reverse domain name notation.| String    | Yes (initial value: left empty)      |
| types      | Types of the current static common event. The value is an array of strings, each of which represents a type.| String array| Yes (initial value: left empty)|
| events     | Events of the intents that can be accepted by the ability. The value can be customized or be the events predefined in the system.| String array| No          |

Define the **common_event_config.json** file in **resources/base/profile** in the development view. (The file name can be defined by developers.)

```json
{
    "commonEvents": [
            {
                "name": "abilityName",
                "permission": "string",
                "types": [
                    "string",
                    "string"
                ],
                "events": [
                    "string",
                    "string"
                ]
            }
    ]
}
```

Define metadata information in the **extension** component of the **module.json** file as follows:

```json
"extensionAbilities": [
    {
        "name": "mySubscriber",
        "srcEntrance": "./extension/my_subscriber.js",
        "type": "staticSubscriber",
        "metadata": [
            {
                "name": "ohos.extability.staticSubscriber",
                "resource": "$profile:common_event_config", 
            }
        ],
    }
]
```

#### Internal Structure of the distroFilter Attribute

Application distribution rules.

This attribute defines the rules for distributing HAP files based on different device specifications, so that precise matching can be performed when AppGallery distributes applications. Applications can be distributed by API version, screen shape, or screen resolution. During distribution, a unique HAP is determined based on the mapping between **deviceType** and these three factors.

Table 15 Internal structure of the distroFilter attribute

| Attribute     | Description                                                        | Data Type| Default                |
| ------------- | ------------------------------------------------------------ | -------- | -------------------------- |
| apiVersion    | Supported API versions. For details, see Table 16.                        | Object array| Yes (initial value: left empty)|
| screenShape   | Supported screen shapes.                                    | Object array| Yes (initial value: left empty)|
| screenWindow  | Supported window resolutions when the application is running. This attribute applies only to the lite wearables.| Object array| Yes (initial value: left empty)|
| screenDensity | It indicates the dot per inch (DPI) of the screen. This attribute is optional. If this attribute is set, the value must be valid. The value is a string array. The range is as follows:<br>**sdpi**: screen density with small-scale dots per inch (SDPI). This value is applicable for devices with a DPI range of (0, 120].<br>**mdpi**: screen density with medium-scale dots per inch (MDPI). This value is applicable for devices with a DPI range of (120, 160].<br>**ldpi**: screen density with large-scale dots per inch (LDPI). This value is applicable for devices with a DPI range of (160, 240].<br> **xldpi**: screen density with extra-large-scale dots per inch (XLDPI). This value is applicable for devices with a DPI range of (240, 320].<br>**xxldpi**: screen density with extra-extra-large-scale dots per inch (XXLDPI). This value is applicable for devices with a DPI range of (320, 480].<br>**xxxldpi**: screen density with extra-extra-extra-large-scale dots per inch (XXXLDPI). This value is applicable for devices with a DPI range of (480, 640].| Object array| Yes (initial value: left empty)|
| countryCode   | Code of the country or region to which an application is distributed. For details, see ISO-3166-1. Enumerated definitions of multiple countries and regions are supported. This attribute is optional. If this attribute is set, the value must be valid. The substring of the value indicates the supported countries or regions and consists of two uppercase letters.| Object array| Yes (initial value: left empty)|

Table 16 Internal structure of the apiVersion attribute

| Attribute| Description                                                        | Data Type| Default          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**.**include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | An integer of the existing API version, for example, 4, 5, or 6. Example: If an application uses two software versions developed using API 5 and API 6 for the same device model, two installation packages of the entry type can be released.| Array    | Yes (initial value: left empty)|

Table 17 Internal structure of the screenShape attribute

| Attribute| Description                                                        | Data Type| Default          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**.**include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | The value can be **circle** or **rect**. Example: Different HAPs can be provided for a smart watch with a circular face and that with a rectangular face.| Array    | Yes (initial value: left empty)|

Table 18 Internal structure of the screenWindow attribute

| Attribute| Description                                                        | Data Type| Default          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**.**include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | Width and height of the screen. The value of a single string is in the format of Width x Height in pixels, for example, **454*454**.| Array    | Yes (initial value: left empty)|

Table 19 Internal structure of the screenDensity attribute

| Attribute| Description                                                        | Data Type| Default          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**.**include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | It indicates the dot per inch (DPI) of the screen.             | Array    | Yes (initial value: left empty)|

Table 20 Internal structure of the countryCode attribute

| Attribute| Description                                                        | Data Type| Default          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**.**include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | Code of the country or region to which an application is to be distributed.                        | Array    | Yes (initial value: left empty)|

Example of the distroFilter attribute structure:

Define the **distroFilter_config.json** file in **resources/base/profile** of the development view. (The file name can be defined by developers.)

```json
"distroFilter": [
    {
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
        }
    }
]
```

Define metadata information in the **extensionAbilities** component of the **module.json** file as follows:

```json
"extensionAbilities": [
    {
        "name": "mySubscriber",
        "srcEntrance": "./extension/my_subscriber.js",
        "type": "staticSubscriber", 
        "metadata": [
            {
                "name": "ohos.extability.staticSubscriber",
                "resource": "$profile:distroFilter_config", 
            }
        ],
    }
]

```
