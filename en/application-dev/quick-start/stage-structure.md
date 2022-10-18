

# Application Package Structure Configuration File

When developing an application in the Feature Ability (FA) model, you need to declare the package structure of the application in the **config.json** file. Similarly, when developing an application in the stage model, you need to declare the package structure of the application in the **module.json5** and **app.json** files.

## Configuration File Internal Structure

The configuration files each consist of two mandatory tags, namely, **app** and **module**. For details, see Table 1.

Table 1 Configuration file internal structure

| Tag| Description                                                        | Data Type| Initial Value Allowed|
| -------- | ------------------------------------------------------------ | -------- | ---------- |
| app      | Global configuration of the application. For details, see [Internal Structure of the app Tag](#internal-structure-of-the-app-tag).| Object    | No        |
| module   | Configuration of the HAP file. It is valid only for the current HAP file. For details, see [Internal Structure of the module Tag](#internal-structure-of-the-module-tag).| Object    | No        |

### Internal Structure of the app Tag

Code snippet in the **app.json** file:

```json
{
    "app": {
        "bundleName": "com.application.music",
        "vendor": "application",
        "versionCode": 1,
        "versionName": "1.0",
        "minCompatibleVersionCode": 1,
        "minAPIVersion": 7,
        "targetAPIVersion": 8,
        "apiReleaseType": "Release",
        "debug": false,
        "icon": "$media:app_icon",
        "label": "$string:app_name",
        "description": "$string:description_application",
        "distributedNotificationEnabled": true,
        "entityType": "game",
        "car": {
            "apiCompatibleVersion": 8
        }
    }
}
```

This tag is an application-level attribute that applies to all the HAP files and components in the application. For the internal structure of the tag, see Table 2.

Table 2 Internal structure of the app tag

| Attribute                      | Description                                                        | Data Type| Initial Value Allowed                                 |
| ------------------------------ | ------------------------------------------------------------ | -------- | ------------------------------------------- |
| bundleName                     | Bundle name that uniquely identifies the application. The value must comply with the following rules:<br> (1) Consists of letters, digits, underscores (_), and periods (.).<br> (2) Starts with a letter.<br> (3) Contains 7 to 127 bytes.<br> You are advised to use the reverse domain name notion, for example, *com.example.xxx*, where the first part is the domain suffix **com**, the second part is the vendor/individual name, and the third part is the application name, which can be of multiple levels.<br> For an application compiled with the system source code, its bundle name must be in the format of **com.ohos.*xxx***, where **ohos** signifies OpenHarmony. | String  | No                                         |
| debug                          | Whether the application can be debugged.                                  | Boolean  | Yes (initial value: **false**)              |
| icon                           | Icon of the application. The value is the index to the resource file.              | String  | No                           |
| label                          | Name of the application. The value is a resource index to descriptions in multiple languages.| String  | No                           |
| description                    | Description of the application. The value can be a string or a resource index to descriptions in multiple languages.| String  | Yes (initial value: left empty)                 |
| vendor                         | Application vendor. The value is a string with a maximum of 255 bytes.| String  | Yes (initial value: left empty)                 |
| versionCode                    | Version number of the application. The value is a 32-bit non-negative integer and less than 2 to the power of 31. It is used only to determine whether a version is later than another version. A larger value indicates a later version. Ensure that a new version of the application uses a value greater than any of its predecessors. | Number    | No                             |
| versionName                    | Text description of the version number, which is displayed to users.<br>The value consists of only digits and dots. The four-segment format *A.B.C.D* is recommended, wherein:<br>Segment 1: major version number, which ranges from 0 to 99. A major version consists of major new features or large changes.<br>Segment 2: minor version number, which ranges from 0 to 99. A minor version consists of some new features and large bug fixes.<br>Segment 3: feature version number, which ranges from 0 to 99. A feature version consists of scheduled new features.<br>Segment 4: maintenance release number or patch number, which ranges from 0 to 999. A maintenance release or patch consists of resolution to security flaws or minor bugs.| String  | No                             |
| minCompatibleVersionCode       | Earliest version that the application is compatible with. It is used to determine cross-device compatibility.   | Number    | Yes (initial value: value of **versionCode**)|
| minAPIVersion                  | Minimum API version required for running the application.  | Integer    | Yes (initial value: value of **compatibleSdkVersion** in **bundle-profile.json5**)|
| targetAPIVersion               | Target API version required for running the application.  | Integer    | Yes (initial value: value of **compileSdkVersion** in **bundle-profile.json5**)|
| apiReleaseType                 | Type of the target API version required for running the application. The value can be **CanaryN**, **BetaN**, or **Release**, where **N** represents a positive integer.<br>**Canary**: indicates a restricted release.<br>**Beta**: indicates a publicly released beta version.<br>**Release**: indicates a publicly released official version.| String  | Yes (initial value: **"Release"**)            |
| distributedNotificationEnabled | Whether the distributed notification feature is enabled for the application.                        | Boolean  | Yes (initial value: **true**)               |
| entityType                     | Category of the application, which can be **game**, **media**, **communication**, **news**, **travel**, **utility**, **shopping**, **education**, **kids**, **business**, and **photography**.| String  | Yes (initial value: **"unspecified"**)        |
| singleton                      | Whether to enable singleton mode for the application. This attribute applies only to system applications and does not take effect for third-party applications. If this attribute is set to **true**, the application always runs in singleton mode, even in multi-user scenarios. This attribute is supported since API version 8. | Boolean  | Yes (initial value: **false**)                    |
| removable                      | Whether the application can be uninstalled. This attribute applies only to system applications and does not take effect for third-party applications. It is supported since API version 8.| Boolean  | Yes (initial value: **true**)                     |
| keepAlive                      | Whether the application is always running. This attribute applies only to system applications and does not take effect for third-party applications. The value **true** means that the application is always kept alive: The system automatically launches the application at startup and restarts it after it exits.| Boolean  | Yes (initial value: **false**)                    |
| userDataClearable              | Whether user data of the application can be cleared. This attribute applies only to system applications and does not take effect for third-party applications. It is supported since API version 8.| Boolean  | Yes (initial value: **true**)                     |
| accessible                     | Whether the installation directory of the application is accessible. This attribute applies only to system applications and does not take effect for third-party applications. The value **true** means that the installation directory can be accessed by third-party applications, and **false** means the opposite.| Boolean  | Yes (initial value: **false**)                    |
| multiProjects | Whether multiple projects are supported.| Boolean| Yes (initial value: **false**)|
| deviceType                      | Supported device types, such as **tablet**, **tv**, **wearable**, and **car**. The following attributes may be included: **minAPIVersion**, **distributedNotificationEnabled**, **keepAlive**, and **removable**.| Object    | Yes (initial value: settings under **"app"**)|

### Internal Structure of the module Tag

Code snippet in the **module.json5** file:

```json
{
    "module": {
        "name": "myHapName",
        "type": "entry|feature|har",
        "srcEntrance" : "./MyAbilityStage.js",
        "description" : "$string:description_application",
        "mainElement": "MainAbility",
        "deviceTypes": [
            "tablet", 
            "tv", 
            "wearable",
            "car",
            "router"
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
                "startWindowIcon": "$media:icon",
                "startWindowBackground": "$color:red"
            },
            {
                "name": "sampleAbility",
                "srcEntrance" : "./login/sampleAbility.ts",
                "description": "$string:description_sample_ability",
                "icon": "$media:icon",
                "label": "HiMusic",
                "visible": true,
                "startWindowIcon": "$media:icon",
                "startWindowBackground": "$color:red"
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

This tag stores the HAP configuration, which only applies to the current HAP file.

Table 3 Internal structure of the module tag

| Attribute            | Description                                                        | Data Type  | Initial Value Allowed                                                  |
| -------------------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| name                 | Name of the current module. After the module is packed into a HAP file, this attribute indicates the name of the HAP file. The value is a string with a maximum of 31 bytes and must be unique in the entire application.| String    | No                                            |
| type                 | Type of the HAP file. There are three types: **entry**, **feature**, and **har**.| String    | No                                            |
| srcEntrance          | Path of the entry JS code corresponding to the HAP file. The value is a string with a maximum of 127 bytes.| String    | Yes                                              |
| description          | Description of the HAP file. The value can be a string or a resource index to descriptions in multiple languages.| String    | Yes (initial value: left empty)                                  |
| process              | Process of the HAP file. The value is a string with a maximum of 31 bytes. If a process is configured under **hap**, all abilities of the application run in this process. This attribute applies only to system applications.| String    | Yes (initial value: value of **bundleName** under the **app** tag)                       |
| mainElement          | Entrance ability name or extension name of the HAP file. Only the ability or extension whose value is **mainElement** can be displayed in the Service Center. This attribute cannot be left at the initial value for an OpenHarmony atomic service.| String    | Yes for an OpenHarmony application                           |
| deviceTypes          | Types of the devices on which the HAP file can run. Table 4 lists the device types predefined by the system.<br>Unlike **syscap**, which is based on the device capability (such as Bluetooth and Wi-Fi), **deviceTypes** is based on the device type.| String array| No (can be left empty)                                |
| deliveryWithInstall  | Whether the current HAP file will be installed when the user installs the application. The value **true** means that the HAP file will be automatically installed when the user installs the application, and **false** means the opposite.| Boolean    | No                                            |
| installationFree     | Whether the HAP file supports the installation-free feature.<br>**true**: The HAP file supports the installation-free feature and meets installation-free constraints.<br>**false**: The HAP file does not support the installation-free feature.<br><br>When **entry.hap** is set to **true**, all **feature.hap** fields related to **entry.hap** must be **true**.<br>When **entry.hap** is set to **false**, **feature.hap** fields related to **entry.hap** can be set to **true** or **false** based on service requirements. | Boolean    | No                                            |
| virtualMachine       | Type of the target virtual machine (VM) where the current HAP file is running. It is used for cloud distribution, such as the application market and distribution center.<br>If the target VM type is Ark, the value is **ark**. Otherwise, the value is **default**. This attribute is automatically inserted when the IDE builds the HAP file. When the decompression tool parses the HAP file, if the HAP file does not contain this attribute, the value is set to **default**. | String    | Yes (initial value: **default**)                           |
| uiSyntax(deprecated) | Syntax type of the JS component. This attribute is deprecated since API version 9.<br>**"hml"**: indicates that the JS component is developed using HML, CSS, or JS.<br>**"ets"**: indicates that the JS component is developed using the eTS declarative syntax.| String    | Yes (initial value: **"hml"**)           |
| pages                | Profile resource used to list information about each page in the JS component. For details about how to use **pages**, see the **pages** example.| Object      | No in the ability scenario                       |
| metadata             | Custom metadata of the HAP file. The configuration is valid only for the current module, ability, or extensionAbility. For details, see [Internal Structure of the metadata Attribute](#internal-structure-of-the-metadata-attribute).| Array      | Yes (initial value: left empty)                                  |
| abilities            | Ability configuration, which is valid only for the current ability. For details, see [Internal Structure of the abilities Attribute](#internal-structure-of-the-abilities-attribute).| Object      | Yes (initial value: left empty)                                  |
| extensionAbilities   | Extension ability configuration, which is valid only for the current Extension ability. For details, see [Internal structure of the extensionAbility attribute](#internal-structure-of-the-extensionability-attribute).| Object      | Yes (initial value: left empty)                                  |
| definePermissions    | Permissions defined for the HAP file. This attribute applies only to system applications and does not take effect for third-party applications. The callers must acquire these permissions before calling the application. For details, see [Internal structure of the definePermissions attribute](#internal-structure-of-the-definepermissions-attribute).| Object      | Yes (initial value: left empty)|
| requestPermissions   | A set of permissions that the application needs to request from the system when the application is running. For details, see [Internal structure of the requestPermissions attribute](#internal-structure-of-the-requestpermissions-attribute). | Object      | Yes (initial value: left empty)                                  |
| testRunner           | Test runner configuration. For details, see [Internal structure of the testRunner attribute](#internal-structure-of-the-testrunner-attribute).| Object      | Yes (initial value: left empty)                                          |

Table 4 System-defined deviceTypes values

| Value  | Device Type                                                |
| -------- | -------------------------------------------------------- |
| tablet   | Tablet, speaker with a screen                                          |
| tv       | Smart TV                                                  |
| wearable | Smart watch, kids' watch, especially a watch that provides call features|
| car      | Head unit                                                    |
| router   | Router                                                  |

Example of the **deviceTypes** attribute structure:

```json
{
    "module": {
        "name": "myHapName",
        "type": "har",
        "deviceTypes" : [
            "wearable"
        ]
    }
}
```

Example of the **pages** attribute structure:

```json
{
    "module": {
       "name": "myHapName",
        "type": "har",
        "deviceTypes" : [
            "wearable"
        ],
        "pages": "$profile:pages_config"
    }
}
```

Example of the **pages_config** configuration file:

```json
{
    "src": [
        "pages/index/index",
        "pages/second/second",
        "pages/third/third",
        "pages/four/four"
    ]
}
```



#### Internal Structure of the metadata Attribute

The **metadata** attribute provides the configuration about the module, ability, and extensionAbility. The value is of the array type. The configuration is valid only for the current module, ability, or extensionAbility.

Table 5 Internal structure of the metadata attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed                |
| -------- | ------------------------------------------------------------ | -------- | -------------------------- |
| name     | Name of the data item. The value is a string with a maximum of 255 bytes.   | String  | Yes (initial value: left empty)|
| value    | Value of the data item. The value is a string with a maximum of 255 bytes.   | String  | Yes (initial value: left empty)        |
| resource | Custom data format. The value is an index to the resource that identifies the data.| String  | Yes (initial value: left empty)        |

Example of the **metadata** attribute structure:

```json
{ 
    "module": {
        "metadata": [
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file"
            },
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file"
            }
        ]
    }
}
```

#### Internal Structure of the abilities Attribute

The **abilities** attribute describes the ability configuration information. The value is of the array type.

Table 6 Internal structure of the abilities attribute

| Attribute           | Description                                                        | Data Type  | Initial Value Allowed                                                  |
| --------------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| name            | Logical name of the ability, which must be unique in the entire application. The value is a string with a maximum of 127 bytes.| String    | No                                            |
| srcEntrance     | JS code path corresponding to the ability. The value is a string with a maximum of 127 bytes.| String    | No                                            |
| launchType      | Ability startup mode. Available values are as follows:<br>**"standard"**: indicates common multi-instance.<br>**"singleton"**: indicates a singleton.<br>**"specified"**: indicates one or more specified instances, depending on the internal service of the ability. | String    | Yes (initial value: **singleton**)                              |
| description     | Ability description. The value can be a string or a resource index to descriptions in multiple languages.| String    | Yes (initial value: left empty)                                  |
| icon            | Icon of the ability. The value is the index to the resource file. | String    | Yes (initial value: left empty)<br>If **ability** is set to **MainElement**, this attribute is mandatory.|
| permissions     | Permissions required for abilities of another application to call the current ability. The value is an array of permission names predefined by the system, generally in the format of a reverse domain name the reverse domain name format (a maximum of 255 bytes).| String array| Yes (initial value: left empty)                                  |
| metadata        | Metadata of the ability. For details, see [Internal Structure of the metadata Attribute](#internal-structure-of-the-metadata-attribute).| Array      | Yes (initial value: left empty)                                  |
| visible         | Whether the ability can be invoked by other applications. The value **true** means that the ability can be invoked by other applications, and **false** means the opposite.| Boolean    | Yes (initial value: **false**)                               |
| continuable     | Whether the ability can be migrated. The value **true** means that the ability can be migrated, and **false** means the opposite.| Boolean    | Yes (initial value: **false**)                               |
| skills          | Feature set of wants that can be received by the ability.<br>Configuration rule: In an entry package, you can configure multiple abilities with the **skills** attribute (where **action.system.home** and **entity.system.home** are configured) that has the entry capability. The **label** and **icon** in the first ability that has **skills** configured are used as the **label** and **icon** of the entire service/application.<br>The **skills** attribute with the entry capability can be configured for the feature package of an OpenHarmony application, but not for an OpenHarmony service.<br>For details, see [Internal Structure of the skills Attribute](#internal-structure-of-the-skills-attribute). | Array      | Yes (initial value: left empty)                                  |
| backgroundModes | Continuous task modes of the ability.<br>Continuous tasks are classified into the following types:<br>**dataTransfer**: service for downloading, backing up, sharing, or transferring data from the network or peer devices<br>**audioPlayback**: audio playback service<br>**audioRecording**: audio recording service<br>**location**: location and navigation services<br>**bluetoothInteraction**: Bluetooth scanning, connection, and transmission services (wearables)<br>**multiDeviceConnection**: multi-device interconnection service<br>**wifiInteraction**: Wi-Fi scanning, connection, and transmission services (multi-screen cloning)<br>**voip**: voice/video call and VoIP services<br>**taskKeeping**: computing service<br>| String    | Yes (initial value: left empty)                                          |
| startWindowIcon    | Index to the icon file of the ability startup page. Example: **$media:icon**.| String      | No|
| startWindowBackground    | Index to the background color resource file of the ability startup page. Example: **$color:red**.| String      | No|
| removeMissionAfterTerminate    | Whether to remove the relevant task from the task list after the ability is destroyed. The value **true** means to remove the relevant task from the task list after the ability is destroyed, and **false** means the opposite.| Boolean      | Yes (initial value: **false**)|
| orientation              | Display orientation of the ability when it is started. Available values are as follows:<br>**"unspecified"**: The device orientation is auto-set by the system.<br>**"landscape"**: The device is in landscape orientation.<br> **"portrait"**: The device is in portrait orientation.<br>**"landscape_inverted"**: The device is in inverted landscape orientation.<br>**"portrait_inverted"**: The device is in inverted portrait orientation.<br>**"auto_rotation"**: The device orientation is determined by the sensor.<br>**auto_rotation_landscape**: The device orientation is determined by the sensor in the horizontal direction, including landscape and reverse landscape.<br>**auto_rotation_portrait**: The device orientation is determined by the sensor in the vertical direction, including portrait and reverse portrait.<br>**auto_rotation_restricted**: The device orientation is determined by the sensor when the sensor switch is enabled.<br>**auto_rotation_landscape_restricted**: The device orientation is determined by the sensor in the horizontal direction, including landscape and reverse landscape, when the sensor switch is enabled.<br>**auto_rotation_portrait_restricted**: The device orientation is determined by the sensor in the vertical direction, including portrait and reverse portrait, when the sensor switch is enabled.<br>**locked**: Auto rotate is disabled.| String  | Yes (initial value: **"unspecified"**)|
|supportWindowMode|Window display mode of the ability. Available values are as follows:<br> **fullscreen**: full-screen mode.<br> **split**: split-screen mode.<br>**floating**: floating window mode.|Array      | Yes (initial value:<br>["fullscreen", "split", "floating"])|
|priority|Priority of the ability. This attribute applies only to system applications and does not take effect for third-party applications. During implicit query, an ability with a higher the priority is closer to the top of the returned list. The value is an integer ranging from 0 to 10. A larger value indicates a higher priority.|Number| Yes (initial value: **0**)|
|maxWindowRatio|Maximum aspect ratio of the ability.| Number   |Yes (initial value: maximum aspect ratio of the platform)|
|minWindowRatio|Minimum aspect ratio of the ability.| Number   |Yes (initial value: minimum aspect ratio supported by the platform)|
|maxWindowWidth|Maximum window width of the ability, in vp.| Number   |Yes (initial value: maximum window width supported by the platform)|
|minWindowWidth|Minimum window width of the ability, in vp.| Number   |Yes (initial value: minimum window width supported by the platform)|
|maxWindowHeight|Maximum window height of the ability, in vp.| Number   |Yes (initial value: maximum window height supported by the platform)|
|minWindowHeight|Minimum window height of the ability, in vp.| Number   |Yes (initial value: minimum window height supported by the platform)|
| excludeFromMissions    | Whether the ability is excluded from the recent tasks list. This attribute applies only to system applications and does not take effect for third-party applications. The value **true** indicates that the task is excluded from the recent tasks list, and **false** indicates that the task is displayed in the recent tasks list.| Boolean      | Yes (initial value: **false**)|

Example of the **abilities** attribute structure:

```json
{
    "abilities": [{
        "name": "MainAbility",
        "srcEntrance": "./ets/login/MyLoginAbility.ts",
        "launchType":"standard",
        "description": "$string:description_main_ability",
        "icon": "$media:icon",
        "label": "Login",
        "permissions": [],
        "metadata": [],
        "visible": true,
        "continuable": true,
        "skills": [{
            "actions": ["action.system.home"],
            "entities": ["entity.system.home"],
            "uris": []
        }],
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
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:red",
        "removeMissionAfterTerminate": true,
        "orientation": " ",
        "supportWindowMode": ["fullscreen", "split", "floating"],
        "maxWindowRatio": 3.5,
        "minWindowRatio": 0.5,
        "maxWindowWidth": 2560,
        "minWindowWidth": 1400,
        "maxWindowHeight": 300,
        "minWindowHeight": 200,
        "excludeFromMissions": false
    }]
}
```

#### Internal Structure of the skills Attribute

This attribute identifies a want feature that can be received by the ability or extension.

Table 7 Internal structure of the skills attribute

| Attribute| Description                                                        | Data Type  | Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | ---------- | -------------------- |
| actions  | A set of want action values that can be received. The value can be a value predefined by the system or a custom value.| String array| Yes (initial value: left empty)|
| entities | Categories of abilities that can receive the want. The value can be a value predefined by the system or a custom value.| String array| Yes (initial value: left empty)|
| uris     | Data specifications to be added to the want filter. The specification can be of data type only (**mimeType** attribute), URI only, or both. For details, see Table 8.| Object array  | Yes (initial value: left empty)|

Table 8 Internal structure of the uris attribute

| Attribute| Description               | Data Type| Initial Value Allowed          |
| -------- | ------------------- | -------- | -------------------- |
| scheme   | Scheme of the URI.| String  | No          |
| host     | Host value of the URI.  | String  | Yes (initial value: left empty)|
| port     | Port number of the URI.  | String  | Yes (initial value: left empty)|
| path     | **path** value of the URI.  | String  | Yes (initial value: left empty)|
| type     | **type** value of the URI.  | String  | Yes (initial value: left empty)|

Example of the **skills** attribute structure:

```json
{
    "abilities": [
        {
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
                            "scheme":"uri2",
                            "host":"host2",
                            "port":"port2",
                            "pathStartWith":"path2",
                            "pathRegex":"/query/.*",
                            "path":"path",
                            "type": "text/*"
                        }
                    ]
                }
            ]
        }
    ],
    "extensionAbilities": [
        {
            "skills": [
                {
                    "actions": [
                    ],
                    "entities": [
                    ],
                    "uris": [
                        {
                            "scheme":"uri2",
                            "host":"host2",
                            "port":"port2",
                            "pathStartWith":"path2",
                            "pathRegex":"/query/.*",
                            "path":"path",
                            "type": "text/*"
                        }
                    ]
                }
            ]
        }
    ]
}
```

#### Internal Structure of the extensionAbility Attribute

The **extensionAbility** attribute describes the configuration information of the current Extension ability.

Table 9 Internal structure of the extensionAbility attribute

| Attribute   | Description                                                        | Data Type  | Initial Value Allowed                   |
| ----------- | ------------------------------------------------------------ | ---------- | ----------------------------- |
| name        | Logical name of the current Extension ability. The value is a string with a maximum of 127 bytes. The name must be unique in the entire application.| String    | No             |
| srcEntrance | JS code path corresponding to the Extension ability. The value is a string with a maximum of 127 bytes.| String    | No             |
| description | Description of the Extension ability. The value can be a string or a resource index to descriptions in multiple languages.| String    | Yes (initial value: left empty)   |
| icon        | Icon of the Extension ability. The value is the index to the resource file. If **extensionAbility** is set to **MainElement**, this attribute is mandatory.| String    | Yes (initial value: left empty)   |
| label       | Name of the Extension ability displayed to users. The value is a resource index to names in multiple languages.<br>If **extensionAbility** is set to **MainElement**, this attribute is mandatory and the value must be unique in the application.| String    | No             |
| type        | Type of the Extension ability. The value can be **"form"**, **"workScheduler"**, **"inputMethod"**, **"service"**, **"accessibility"**, **"dataShare"**, **"fileShare"**, **"staticSubscriber"**, **"wallpaper"**, **"backup"**, **"window"**, **"enterpriseAdmin"**, **"thumbnail"**, or **"preview"**.| String    | No             |
| permissions | A set of permissions that need to be applied for when the capability of another application is invoked. The value is a string array. Each array element is a permission name, which is usually represented by a reverse domain name (a maximum of 255 bytes). The permission can be predefined by the system or customized by the application. For the latter, the value must be the same as the **name** value of a permission defined in the **defPermissions** attribute.| String array| Yes (initial value: left empty)   |
| uri         | Data URI provided by the ability. The value is an array containing a maximum of 255 characters and is in the format of a reverse domain name. This attribute is mandatory when **type** is set to **extensionAbility** of the dataShare type.| String    | Yes (initial value: left empty)   |
| skills      | Feature set of wants that can be received by the ability.<br>Configuration rule: In an entry package, you can configure multiple abilities with the **skills** attribute (where **action.system.home** and **entity.system.home** are configured) that has the entry capability. The **label** and **icon** in the first ability that has **skills** configured are used as the **label** and **icon** of the entire service/application.<br>The **skills** attribute with the entry capability can be configured for the feature package of an OpenHarmony application, but not for an OpenHarmony service.<br>For details, see [Internal Structure of the skills Attribute](#internal-structure-of-the-skills-attribute). | Array      | Yes (initial value: left empty)   |
| metadata    | Metadata of the Extension ability. For details, see [Internal Structure of the metadata Attribute](#internal-structure-of-the-metadata-attribute).| Object      | Yes (initial value: left empty)   |
| visible     | Whether extensionAbility can be invoked by other applications. The value is of the Boolean type. The value **true** means that it can be invoked by other applications, and the value **false** means the opposite.| Boolean    | Yes (initial value: **false**)|

Example of the **extensionAbility** attribute structure:

```json
{
    "extensionAbilities": [
        {
            "name": "FormName",
            "srcEntrance": "./form/MyForm.ts",
            "icon": "$media:icon",
            "label" : "$string:extension_name",
            "description": "$string:form_description",
            "type": "form", 
            "permissions": ["ohos.abilitydemo.permission.PROVIDER"],
            "readPermission": "",
            "writePermission": "",
            "visible": true,
            "uri":"scheme://authority/path/query"
            "skills": [{
                "actions": [],
                "entities": [],
                "uris": []
            }],
            "metadata": [
                {
                    "name": "ohos.extability.form",
                    "resource": "$profile:form_config", 
                }
            ]
        }
    ]
}

```

#### Internal Structure of the definePermissions Attribute

The **definePermissions** attribute indicates the permissions defined for the HAP file.

Table 10 Internal structure of the definePermissions attribute

| Attribute              | Description                                                        | Data Type| Initial Value Allowed                    |
| ---------------------- | ------------------------------------------------------------ | -------- | ------------------------------ |
| name                   | Permission name.                                            | String  | No                      |
| grantMode              | Permission grant mode. Available values are as follows:<br>**"system_grant"**: The permission is automatically granted by the system after the application is installed.<br>**"user_grant"**: The permission must be dynamically requested and can be used only after being granted by the user.| String  | Yes (initial value: **"system_grant"**)|
| availableLevel         | Permission level. Available values are as follows:<br>**"system_core"**: core system permission.<br>**"system_basic"**: basic system permission.<br>**"normal"**: normal permission, which is open to all applications. | String  | Yes (initial value: **"normal"**)      |
| provisionEnable        | Whether to enable provision mode for requesting permissions, including higher-level permissions. The value **true** indicates that provision mode is enabled.| Boolean  | Yes (initial value: **true**)          |
| distributedSceneEnable | Whether the permission can be used in distributed scenarios.                    | Boolean  | Yes (initial value: **false**)         |
| label                  | Brief description of the permission. The value is a resource index.            | String  | Yes (initial value: left empty)            |
| description            | Detailed description of the permission, which can be a string or a resource index.| String  | Yes (initial value: left empty)            |

#### Internal Structure of the requestPermissions Attribute

This attribute identifies a set of permissions that the application needs to request from the system when the application is running.

Table 11 Internal structure of the requestPermissions attribute

| Attribute | Description                                                        | Type                                | Value Range                                                | Default Value          | Restrictions                                                |
| --------- | ------------------------------------------------------------ | ---------------------------------------- | ------------------------------------------------------------ | -------------------- | ------------------------------------------------------------ |
| name      | Permission name. This attribute is mandatory.                              | String                                  | Custom                                                      | N/A                  | Parsing will fail if this attribute is not set.                                        |
| reason    | Reason for requesting the permission. This attribute is mandatory when the permission to request is **user_grant**. | String                                  | Resource reference of the string type in `$string: ***` format                | Empty                  | If the permission to request is **user_grant**, this attribute is required for the application to be released to AppGallery. Multi-language adaptation is required.|
| usedScene | Application scenario and timing for using the permission. This attribute is mandatory when the permission to request is **user_grant**. It consists of the **abilities** and **when** sub-attributes. Multiple abilities can be configured.| **abilities**: string array; **when**: string| **abilities**: array of ability names; **when**: **inuse** and **always**| **abilities**: left empty; **when**: left empty| If the permission to request is **user_grant**, the **abilities** sub-attribute is mandatory and **when** is optional.                   |

Example of the **requestPermissions** attribute structure:

```json
{
    "name": "ohos.abilitydemo.permission.PROVIDER",
    "reason": "$string:reason",
    "usedScene": {
        "abilities": [
            "AudioAbility",
            "VideoAbility",
        ],
        "when": "inuse"
    }
}
```
For details, see [Access Control (Permission) Development](../security/accesstoken-guidelines.md#fa-model).

#### Internal Structure of the form Attribute

The **forms** attribute indicates the service widget configuration. The service widget is an application brief view that can be displayed on the home screen and periodically updated. You can include the **forms** attribute in any of the following modes:

1. Set **type** to **form** in **extensions**.

2. Specify the **form** information in **metadata**, where:	  
   - **name** indicates the name of the service widget, for example, **ohos.extability.form**.
   - **resource** indicates where the resources of the service widget are stored.

Table 12 Internal structure of the forms attribute

| Attribute           | Description                                                        | Data Type  | Initial Value Allowed                   |
| ------------------- | ------------------------------------------------------------ | ---------- | ----------------------------- |
| name                | Class name of the widget. The value is a string with a maximum of 127 bytes.                   | String    | No                           |
| description         | Description of the widget. The value can be a string or a resource index to descriptions in multiple languages. The value is a string with a maximum of 255 bytes.| String    | Yes (initial value: left empty)           |
| src                 | UI code of a JS service widget. It is recommended that you use the adaptive layout to display a service widget of different specifications. If the layout of a service widget of different specifications differs greatly, you are advised to use different service widgets.| String    | Yes (initial value: left empty)           |
| window              | Adaptive capability of a JS service widget. For details, see Table 12.          | Object      | Yes (initial value: left empty)           |
| isDefault           | Whether the widget is a default one. Each ability has only one default widget. **true**: The service widget is the default one. **false**: The service widget is not the default one.| Boolean    | No                           |
| colorMode           | Color mode of the widget. The value can be **auto**, **dark**, or **light**.| String    | Yes (initial value: **auto**)     |
| supportDimensions   | Dimensions supported by the service widget. The value can be **1 * 2**, **2 * 1**, **2 * 2**, **2 * 4**, or **4 * 4**, where the number before the asterisk (*) indicates the number of rows, and the number after the asterisk (*) indicates the number of columns.| String array| No                           |
| defaultDimension    | Default grid style of the widget. The value must be from the **supportDimensions** array of the widget.| String    | No                           |
| updateEnabled       | Whether the widget can be updated periodically. The value **true** indicates that the widget can be updated periodically, and **false** indicates that the widget cannot be updated periodically.| Boolean    | No                           |
| scheduledUpdateTime | Scheduled time to update the widget. The value is in 24-hour format and accurate to minute.  | String    | Yes                           |
| updateDuration      | Update frequency of a widget. The unit is 30 minutes. The value is a multiple of 30. The highest frequency of refreshing a widget is once every 30 minutes. You can also use scheduled refresh to refresh a widget at a fixed time or once every 30 minutes. If both of them are configured, the scheduled refresh takes precedence.| Number      | Yes (initial value: left empty)           |
| metadata            | Metadata of the widget. For details, see Table 5.       | Object      | Yes (initial value: left empty)           |
| formConfigAbility   | Ability name for widget adjustment. The value is a string of up to 127 characters. The value must be in the following format:<br>ability:// Name of an ability.<br>The name must be the same as that of the current application.| String    | Yes (initial value: left empty)           |
| formVisibleNotify   | Whether the widget is allowed to use the visibility notification. The value is **true** or **false**.| Boolean    | Yes (initial value: **false**)|

Table 13 Internal structure of the window attribute

| Attribute       | Description                                                        | Data Type| Initial Value Allowed          |
| --------------- | ------------------------------------------------------------ | -------- | -------------------- |
| designWidth     | Baseline width of the page design, in pixels. The element size is scaled by the actual device width. The value is an integer.| Number    | Yes (initial value: left empty)|
| autoDesignWidth | Whether to automatically calculate the baseline width of the page design. If this parameter is set to **true**, the **designWidth** attribute is invalid. The baseline width is calculated based on the device width and screen density.| Boolean  | Yes (initial value: left empty)|

Example of the **forms** attribute structure:

Define the **form_config.json** file (this file name is customizable) in **resources/base/profile** of the development view.

```json
{
    "forms": [
        {
            "name": "Form_Js",
            "description": "$string:form_description",
            "src": "./js/pages/card/index",
            "window": {
                "designWidth": 720,
                "autoDesignWidth": true
            },
            "colorMode": "auto",
            "formConfigAbility": "ability://xxxxx",
            "formVisibleNotify": false,
            "isDefault": true,
            "updateEnabled": true,
            "scheduledUpdateTime": "10:30",
            "updateDuration": 1,
            "defaultDimension": "2*2",
            "updateEnabled": true,
            "scheduledUpdateTime": "21:33",
            "supportDimensions": [
                "2*2"
            ],
            "metadata": [
             {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file"
             }
           ] 
        }
    ]
}
```

Define metadata information in the **extension** component of the **module.json5** file.

```json
{
    "extensionAbilities": [{
        "name": "MyForm",
        "type": "form",
        "metadata": [{
            "name": "ohos.extability.form",
            "resource": "$profile:form_config"
        }]
    }]
}
```

#### Internal Structure of the shortcuts Attribute

This attribute identifies the shortcut information of an application. The value is an array. A maximum of four shortcuts can be configured. It contains four sub-attributes: **shortcutId**, **label**, **icon**, and **wants**.

Specify the **shortcut** information in **metadata**, where:

- **name** indicates the name of the shortcut, for example, **ohos.ability.shortcuts**.

- **resource** indicates where the resources of the shortcut are stored.

Table 14 Internal structure of the shortcuts attribute

| Attribute  | Description                                                        | Data Type| Initial Value Allowed                |
| ---------- | ------------------------------------------------------------ | -------- | -------------------------- |
| shortcutId | ID of the shortcut. The value is a string with a maximum of 63 bytes.                | String  | No                        |
| label      | Label of the shortcut, that is, the text description displayed for the shortcut. The value can be a string or a resource index to the description. The value is a string with a maximum of 63 bytes.| String  | Yes (initial value: left empty)        |
| icon       | Icon of the shortcut. The value is the index to the resource file.          | String  | Yes (initial value: left empty)|
| wants      | Wants to which the shortcut points. The attribute consists of the **bundleName** and **abilityName** sub-attributes.<br>**bundleName**: target bundle name of the shortcut; string type.<br>**abilityName**: target component name of the shortcut; string type.| Object    | Yes (initial value: left empty)  |

Define the **shortcut_config.json** file (this file name is customizable) in **resources/base/profile** of the development view.

```json
{
    "shortcuts": [{
        "shortcutId": "id_test1",
        "label": "$string:shortcut",
        "icon": "$media:aa_icon",
        "wants": [{
            "bundleName": "com.ohos.hello",
            "abilityName": "MainAbility"
        }]
    }]
}
```

Define the **metadata** information under **module** in the **module.json5** file as follows:

```json
{
    "module": {
        "name": "MyAbilityStage",
        "abilities": [{
            "name": "MyAbility",
            "srcEntrance": "./abilities/MyAbility.ts",
            "skills": [{
                "actions": ["action.system.home"],
                "entities": ["entity.system.home"],
                "uris": []
            }],
            "metadata": [{
                "name": "ohos.ability.shortcuts",
                "resource": "$profile:shortcuts_config"
            }]
        }]
    }
}
```

#### Internal Structure of the commonEvents Attribute

The **commonEvents** attribute identifies the registered static common event information. The value is an array.

Specify the **commonEvent** information in the **metadata**, where:

- **name** indicates the name of the common event, for example, **ohos.extability.staticSubscriber**.

- **resource** indicates where the resources of the common event are stored.

Table 15 Internal structure of the commonEvents attribute

| Attribute  | Description                                                        | Data Type  | Initial Value Allowed                |
| ---------- | ------------------------------------------------------------ | ---------- | -------------------------- |
| name       | Ability name corresponding to the current static common event. The class must be marked in the ability.| String    | No          |
| permission | Permission required for implementing the static common event. The value is a string with a maximum of 255 bytes, in the reverse domain name notation.| String    | Yes (initial value: left empty)      |
| types      | Types of the current static common event. The value is an array of strings, each of which represents a type.| String array| Yes (initial value: left empty)|
| events     | Events of the intents that can be accepted by the ability. The value can be customized or be the events predefined in the system.| String array| No          |

Define the **common_event_config.json** file in **resources/base/profile** in the development view. (The file name can be defined by developers.)

```json
{
    "commonEvents": [{
        "name": "abilityName",
        "permission": "string",
        "types": [
            "string",
            "string"
        ],
        "events": [
            "string",
            "string"
        ]
    }]
}
```

Define the **metadata** information under **extension** in the **module.json5** file as follows:

```json
"extensionAbilities": [
    {
        "name": "mySubscriber",
        "srcEntrance": "./extension/my_subscriber.js",
        "type": "staticSubscriber",
        "metadata": [{
            "name": "ohos.extability.staticSubscriber",
            "resource": "$profile:common_event_config",
        }],
    }
]
```

#### Internal Structure of the distroFilter Attribute

Distribution rules of the application.

This attribute defines the rules for distributing HAP files based on different device specifications, so that precise matching can be performed when AppGallery distributes applications. Distribution rules cover three factors: API version, screen shape, and screen resolution. During distribution, a unique HAP is determined based on the mapping between **deviceType** and these three factors.

Table 16 Internal structure of the distroFilter attribute

| Attribute     | Description                                                        | Data Type| Initial Value Allowed                |
| ------------- | ------------------------------------------------------------ | -------- | -------------------------- |
| apiVersion    | Supported API versions. For details, see Table 16.                        | Object array| Yes (initial value: left empty)|
| screenShape   | Supported screen shapes.                                    | Object array| Yes (initial value: left empty)|
| screenWindow  | Supported window resolutions for when the application is running. This attribute applies only to the lite wearables.| Object array| Yes (initial value: left empty)|
| screenDensity | Pixel density of the screen, in dots per inch (dpi). This attribute is optional. The value options are as follows:<br>**sdpi**: small-scale dots per inch. This value is applicable for devices with a DPI range of (0, 120].<br>**mdpi**: medium-scale dots per inch. This value is applicable for devices with a DPI range of (120, 160].<br>**ldpi**: large-scale dots per inch. This value is applicable for devices with a DPI in the (160, 240] range.<br> **xldpi**: extra-large-scale dots per inch. This value is applicable for devices with a DPI in the (240, 320] range.<br>**xxldpi**: extra-extra-large-scale dots per inch (XXLDPI). This value is applicable for devices with a DPI in the (320, 480] range.<br>**xxxldpi**: extra-extra-extra-large-scale dots per inch. This value is applicable for devices with a DPI in the (480, 640] range.| Object array| Yes (initial value: left empty)|
| countryCode   | Code of the country or region to which the application is to be distributed. For details, see ISO-3166-1. Enumerated definitions of multiple countries and regions are supported. This attribute is optional. The substring of the value consists of two uppercase letters and indicates the supported countries or regions.| Object array| Yes (initial value: left empty)|

Table 17 Internal structure of the apiVersion attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | An integer of the existing API version, for example, 4, 5, or 6. If an application uses two software versions developed using API 5 and API 6 for the same device model, two installation packages of the entry type can be released.| Array    | Yes (initial value: left empty)|

Table 18 Internal structure of the screenShape attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | The value can be **circle** or **rect**. Example: Different HAP files can be provided for a smart watch with a circular face and a smart watch with a rectangular face.| Array    | Yes (initial value: left empty)|

Table 19 Internal structure of the screenWindow attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | Width and height of the screen. The value is in the "width * height" format, in pixels, for example, **454*454**.| Array    | Yes (initial value: left empty)|

Table 20 Internal structure of the screenDensity attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | Pixel density of the screen, in dots per inch (dpi).             | Array    | Yes (initial value: left empty)|

Table 21 Internal structure of the countryCode attribute

| Attribute| Description                                                        | Data Type| Initial Value Allowed          |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | Blocklist and trustlist rule of the sub-attribute value. Set this attribute to **exclude** or **include**. **include** indicates that the sub-attribute value is in the trustlist. If the value matches any of the **value** enums, it matches this attribute.| String  | Yes (initial value: left empty)|
| value    | Code of the country or region to which the application is to be distributed.                        | Array    | Yes (initial value: left empty)|

Example of the **distroFilter** attribute structure:

Define the **distroFilter_config.json** file in **resources/base/profile** of the development view. (The file name can be defined by developers.)

```json
"distroFilter": [
    {
        "apiVersion": {
            "policy": "include",
            "value": [4, 5]
        },
        "screenShape": {
            "policy": "include",
            "value": ["circle", "rect"]
        },
        "screenWindow": {
            "policy": "include",
            "value": ["454*454", "466*466"]
        }
    }
]
```

Define the **metadata** information under **extensionAbilities** in the **module.json5** file as follows:

```json
"extensionAbilities": [
    {
        "name": "mySubscriber",
        "srcEntrance": "./extension/my_subscriber.js",
        "type": "staticSubscriber",
        "metadata": [{
            "name": "ohos.extability.staticSubscriber",
            "resource": "$profile:distroFilter_config",
        }],
    }
]
```

#### Internal Structure of the testRunner Attribute

Table 22 Internal structure of the testRunner attribute

| Attribute| Description                  | Data Type| Initial Value Allowed|
| -------- | ---------------------- | -------- | ---------- |
| name     | Name of the test runner object.| String  | No|
| srcPath  | Path of the test runner code.| String  | No|

```
"testRunner": {
    "name": "myTestRUnnerName",
    "srcPath": "etc/test/TestRunner.ts"
}
```
