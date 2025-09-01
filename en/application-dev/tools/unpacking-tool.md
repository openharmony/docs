# Unpacking Tool
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @jsjzju-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @Brilliantry_Rui-->

The unpacking tool is a commissioning tool used to unpack HAP (an application package), HSP (dynamically shared library), and APP (application set to launch to the application market) files. It also provides Java APIs to parse the HAP, HSP, and APP files.


The **app_unpacking_tool.jar** package can be found in the OpenHarmony SDK downloaded locally.


## Constraints

The unpacking tool must run in Java 8 or later.


## Commands

### Unpacking Commands for HAP Files

You can use the JAR package of the unpacking tool to unpack an HAP file by importing unpacking options and file paths.

**Example**

```
java -jar app_unpacking_tool.jar --mode hap --hap-path <path> --out-path <path> [--force true]
```

Parameters

| Name      | Mandatory| Option         | Description                                                        |
| ---------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode     | Yes        | hap           | Unpacking mode.                                                  |
| --hap-path | Yes        | NA            | Path of the HAP file.                                                 |
| --rpcid    | No        | true or false| Indicates whether to extract the rpcid file from the HAP package to a specified directory. If the value is true, only the rpcid file is extracted and the HAP package is not split.|
| --out-path | Yes        | NA            | Path of the target files.                                          |
| --force    | No        | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists. |

### Unpacking Commands for APP Files

You can use the JAR package of the unpacking tool to unpack an APP file by importing unpacking options and file paths.

**Example**

```
java -jar app_unpacking_tool.jar --mode app --app-path <path> --out-path <path> [--force true]
```

Parameters

| Name      | Mandatory| Option         | Description                                                       |
| ---------- | ---------- |-------------| ----------------------------------------------------------- |
| --mode     | Yes        | app         | Unpacking mode.                                                 |
| --app-path | Yes        | NA          | Path of the APP file.                                                |
| --out-path | Yes        | NA          | Path of the target files.                                         |
| --force    | No        | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.|

### Obtaining the rpcid File from the HAP File

You can use the JAR package of the unpacking tool to unpack an HAP file to obtain the rpcid file by importing unpacking options and file paths.

**Example**

```
java -jar app_unpacking_tool.jar --mode hap --rpcid true --hap-path <path> --out-path <path> [--force true]
```

Parameters

| Name      | Mandatory| Option         | Description                                                        |
| ---------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode     | Yes        | hap           | Unpacking mode.                                                    |
| --rpcid    | No        | true or false| Indicates whether to extract the rpcid file from the HAP package to a specified directory. If the value is true, only the rpcid file is extracted and the HAP package is not split.|
| --hap-path | Yes        | NA            | Path of the HAP file.                                                   |
| --out-path | Yes        | NA            | Path of the target rpcid file.                                       |
| --force    | No        | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists. |

### Unpacking HAP Files Based on the Architecture Type

You can use the unpacking tool to unpack HAP files based on the architecture type of **libs** and then pack multiple HAP files that contain only single-architecture type libraries.

**Example**

```
java -jar app_unpacking_tool.jar --mode hap --hap-path <path> --out-path <path> [--force true] [--libs true] [--cpu-abis option]
```

Parameters

| Name      | Mandatory| Option         | Description                                                        |
| ---------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode     | Yes        | hap    | Unpacking mode.                                                  |
| --hap-path | Yes        | NA            | Path of the HAP file.                                            |
| --out-path | Yes        | NA            | Path of the target files.                                          |
| --force    | No        | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists. |
| --libs     | No        | true or false| Whether to perform exponential splitting based on the architectures in the libs directory of the package. If the value is true, the split is performed based on the architecture.|
| --cpu-abis | No        | NA            | Specifies the architecture type of the **libs** to be unpacked. You can specify multiple architecture types and use commas (,) to separate them. This parameter does not take effect when **--libs** is set to **false**.|

### Unpacking Commands for HSP Files

You can use the JAR package of the unpacking tool to unpack an HSP file by importing unpacking options and file paths.

**Example**

```
java -jar app_unpacking_tool.jar --mode hsp --hsp-path <path> --out-path <path> [--force true]
```

Parameters

| Name        | Mandatory| Option         | Description                                |
|------------| ---------- | ------------- |------------------------------------|
| --mode     | Yes        | hsp           | Unpacking mode.                             |
| --hsp-path | Yes        | NA            | Path of the HSP file.                           |
| --out-path | Yes        | NA            | Path of the target files.                         |
| --force    | No        | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.|

### Unpacking HSP Files Based on the Architecture Type

You can use the unpacking tool to unpack HSP files based on the architecture type of **libs** and then pack multiple HSP files that contain only single-architecture type libraries.

**Example**

```
java -jar app_unpacking_tool.jar --mode hsp --hsp-path <path> --out-path <path> [--force true] [--libs true] [--cpu-abis option]
```

Parameters

| Name      | Mandatory| Option         | Description                                                        |
| ---------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode     | Yes        | hsp    | Unpacking mode.                                                  |
| --hsp-path | Yes        | NA            | Path of the HSP file.                                            |
| --out-path | Yes        | NA            | Path of the target files.                                          |
| --force    | No        | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists. |
| --libs     | No        | true or false| Whether to perform exponential splitting based on the architectures in the libs directory of the package. If the value is true, the split is performed based on the architecture.|
| --cpu-abis | No        | NA            | Specifies the architecture type of the **libs** to be unpacked. You can specify multiple architecture types and use commas (,) to separate them. This parameter does not take effect when **--libs** is set to **false**.|

### Unpacking Commands for APPQF Files

You can use the JAR package of the unpacking tool to unpack an APPQF file by importing unpacking options and file paths.

**Example**

```
java -jar app_unpacking_tool.jar --mode appqf --appqf-path <path> --out-path <path> [--force true]
```

Parameters

| Name          | Mandatory| Option         | Description                                |
|--------------| ---------- |-------------|------------------------------------|
| --mode       | Yes        | appqf       | Unpacking mode.                             |
| --appqf-path | Yes        | NA          | Path of the APPQF package.                         |
| --out-path   | Yes        | NA          | Path of the target files.                         |
| --force      | No        | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.|

## Package Parsing APIs

The package parsing APIs are used by the application market to parse an HAP, HSP, or APP file and obtain information such as the configuration file.

### Available APIs

| Class              | Prototype                                                    | Type    | Description                                                           |
| ------------------ | ------------------------------------------------------------ | -------- |-------------------------------------------------------------------|
| UncompressEntrance | UncompressResult parseApp(String appPath, ParseAppMode parseMode, String hapName) | Java| API function: Parses the pack.info information of an app package based on parameters.<br>Input parameters: appPath, parseMode (ALL/HAP_LIST/HAP_INFO), and hapName (required when parseMode is set to HAP_INFO)<br>Return value: UncompressResult.|
| UncompressEntrance | UncompressResult parseApp(InputStream input, ParseAppMode parseMode, String hapName) | Java| API function: Parses the pack.info information of an app package based on parameters.<br>Input parameters: input app file stream, parseMode (ALL/HAP_LIST/HAP_INFO), hapName (required when parseMode is set to HAP_INFO)<br>Return value: UncompressResult.|
| UncompressEntrance | UncompressResult parseHap(String hapPath)                    | Java| API function: Parses the JSON configuration file of the app package based on parameters.<br>Input parameter: hapPath HAP package path.<br>Return value: UncompressResult.   |
| UncompressEntrance | UncompressResult parseHap(InputStream input)                 | Java| API function: Parses the JSON configuration file of the app package based on parameters.<br>Input parameter: input HAP package file stream.<br>Return value: UncompressResult.  |

## Fields of the Unpacking Tool

### UncompressResult (Bundle Information) Struct

| Field           | Type              | Description                                    | Remarks|
| ----------------| ------------------ |----------------------------------------| ---- |
| result          | boolean            | Indicates whether the parsing is successful. The value **true** means that the operation is successful, and **false** means the opposite.                            | NA   |
| message         | String             | If the parsing fails, the failure cause is returned.                           | NA   |
| packInfos       | List\<PackInfo>    | Packages information in the pack.info file of the bundle.         | NA   |
| profileInfos    | List\<profileInfo> | Application configuration information.                               | NA   |
| profileInfosStr | List\<String>      | Application configuration information.| NA   |
| icon            | String             | Icon path of the entry component. If there is no entry component, the icon information of the first component is returned.| NA   |
| label           | String             | Label of the entry component. If there is no entry component, the label of the first component is returned.| NA   |
| packageSize     | long               | Size of an app package, in bytes.| NA   |

### PackInfo Struct

| Field               | Type         | Description                                   | Remarks|
| ------------------- | ------------- | --------------------------------------- | ---- |
| name                | String        | Bundle name.                                   | NA   |
| moduleName          | String        | HAP name.                                | NA   |
| moduleType          | String        | Type of a module.                           | NA   |
| deviceType          | List\<String> | Device type supported by the current HAP package.          | NA   |
| deliveryWithInstall | boolean       | Indicates whether the current HAP is installed during user-initiated installation. The value true indicates yes and the value false indicates no.| NA   |

### ProfileInfo Struct

| Field        | Type                          | Description                                       | Remarks           |
| ------------ | ------------------------------ | ------------------------------------------ | --------------- |
| hapName      | String                         | Name of the HAP package that is being parsed.                   | NA                                                           |
| appInfo      | AppInfo struct (see **AppInfo Struct** below)  | App information structure. For details, see the following AppInfo information.  | NA                                                           |
| deviceConfig | Map\<String,DeviceConfig>      | Device information.                              | The storage type is Map\<String,String>. This column stores the device type name and device type information. In the stage model, this column is stored in the app structure.|
| hapInfo      | HapInfo struct (see **HapInfo Struct** below)  | Indicates the module information in the HAP package. For details, see the following HapInfo information.| NA                                                           |

### AppInfo Struct

| Field                          | Type    | Description                     | Remarks        |
|--------------------------------|---------|---------------------------|-------------|
| bundleName                     | String  | Package name of an app.         | NA          |
| vendor                         | String  | Supplier information of an app.      | NA          |
| relatedBundleName              | String  | Name of the bundle related to the app.  | NA          |
| versionName                    | String  | Version name in the app.      | NA          |
| versionCode                    | String  | Version code of the app. | NA          |
| targetApiVersion               | int     | Target API version required for running the application.   | NA          |
| compatibleApiVersion           | int     | API version compatible with the application.   | NA          |
| appName                        | String  | Label of the ability displayed on the home screen.     | NA          |
| appNameEN                      | String  | Label of the ability displayed on the home screen.   | NA          |
| releaseType                    | String  | Type of the target API version required for running the application.| NA          |
| shellVersionCode               | String  | API version number of the application.| NA          |
| shellVersionName               | String  | API version name of the application. | NA          |
| multiFrameworkBundle           | boolean | Identifies an application framework. The value true indicates mixed packaging, and the value false indicates non-mixed packaging.  | NA          |
| debug                          | boolean | Whether the application can be debugged. The value true indicates that debugging is supported, and the value false indicates that debugging is not supported.    | NA          |
| iconId                         | int     | Icon resource of the application.| NA          |
| labelId                        | int     | Label resource ID of an application. | NA          |
| icon                           | String  | Icon of an application.| NA          |
| label                          | String  | Label of an application. | NA          |
| description                    | String  | Application description.   | The stage model is added.  |
| minCompatibleVersionCode       | int     | Earliest compatible version of the application. | NA          |
| distributedNotificationEnabled | boolean | Whether distributed notification is enabled for the application. The value **true** means to enable privacy protection for screenshots, and **false** means the opposite.  | The stage model is added.  |
| bundleType                     | String  | Bundle type.<br>- app: application.<br>- atomicService: atomic service.<br>- shared: shared library between applications.| NA   |
| compileSdkVersion              | String  | SDK version used for compiling the application.  | Only for applications using API version 10 or later.  |
| compileSdkType                 | String  | SDK type used for compiling the application.  | Only for applications using API version 10 or later.  |
| labels                         | HashMap\<String, String> | Labels of the application in multiple languages.| NA          |
| descriptions                   | HashMap\<String, String> | Descriptions of the application in multiple languages.| NA          |

### HapInfo Struct

| Field                | Type                       | Description                              | Remarks      |
| ---------------------|----------------------------|------------------------------------| -----------|
| appModel             | AppModel enumerated value             | Framework model of an application.<br>- FA: FA model.<br>- STAGE: stage model.| NA |
| packageStr           | String                      | Package information about the application.    | This feature is specific to the FA model.            |
| name                 | String                      | Name of the current module.               | NA                 |
| description          | String                      | Indicates the description of the HAP package.                | This feature is specific to the FA model.                 |
| supportedModes       | List\<String>               | Mode supported by the HAP package.              | NA                           |
| abilities            | List\<AbilityInfo>          | Indicates the ability information of the HAP package.               | NA                             |
| defPermissions       | List\<DefPermission>        | DefPermission information of the HAP package.         | NA                             |
| definePermissions    | List\<DefinePermission>     | Indicates the DefinePermission information of the HAP package.      | NA                             |
| defPermissionsGroups | List\<DefPermissionsGroups> | Indicates the DefPermissionsGroups information of the HAP package. | NA                             |
| distro               | Distro struct                | Distro information about the HAP package.              | NA                      |
| reqCapabilities      | List\<String>               | Indicates the reqCapabilities information of the HAP package.       | NA                           |
| deviceType           | List\<String>               | Type of the device on which HAP can run.   Corresponds to deviceTypes in the stage model.      |
| metaData             | metaData struct (see **metaData Struct** below)| User-defined meta information of HAP.               | NA           |
| dependencies         | List\<DependencyItem>       | DependencyItem information of the HAP package.        | NA                   |
| isJs                 | boolean                     | Whether the application is a JS application. The value true indicates that the application is a JS application, and the value false indicates that the application is not a JS application.             | This feature is specific to the FA model.           |
| reqPermissions       | list\<ReqPermission>        | A set of permissions requested by an application.     | Corresponds to requestPermissions of the stage model.|
| commonEvents         | CommonEvent struct (see **CommonEvent Struct** below)      | Identifies a static event.                        | NA     |
| shortcuts            | list\<Shortcut>             | Shortcuts information of an application.             | NA                  |
| distroFilter         | DistroFilter struct          | Information distributed by device form in AppGallery.    | NA               |
| srcEntrance          | String                      | Entry code path of the application.          | The stage model is added.         |
| process              | String                      | Process name of the HAP.                     | The stage model is added.      |
| mainElement          | String                      | Entry ability name or extension name of HAP.| Added in the stage model. The FA model assigns the value of mainAbility to mainElement.|
| uiSyntax             | String                      | Defines the syntax type of a JavaScript component.        | The stage model is added.      |
| pages                | List\<String>               | Lists information about each page in a JS component.      | The stage model is added.      |
| extensionAbilityInfos| List\<ExtensionAbilityInfo> | Describes the configuration information of the ExtensionAbility.      | The stage model is added.       |
| moduleAtomicService  | ModuleAtomicService struct (see **ModuleAtomicService Struct** below)| Atomic service information of HAP.| NA              |
| formInfos            | List\<AbilityFormInfo>      | Description of a card.                      | NA              |
| descriptions         | HashMap\<String, String>    | Description of HAP.                   | NA             |
| compressedSize       | long                        | Size of the compressed HAP package, in bytes.        | NA              |
| originalSize         | long                        | Original size of the HAP packet, in bytes.        | NA             |

### AbilityInfo Struct

| Field             | Type                      | Description                        | Remarks                       |
|-------------------|---------------------------| ---------------------------- | -------------------------- |
| name              | String                    | Logical name of the current ability.       | NA                              |
| description       | String                    | Description of the ability.            | NA                              |
| descriptionRes    | String                    | Indicates the description of the ability resource.           | NA                              |
| iconId            | int                       | ID of the ability icon resource.           | NA                              |
| icon              | String                    | Icon of ability.           | NA                              |
| iconPath          | String                    | Path of the ability icon.     | NA                              |
| labelId           | int                       | Identifies the name resource that ability displays to the user.      | NA                              |
| label             | String                    | Name of ability displayed to users.      | NA                              |
| labelRes          | String                    | Identifies the name resource that ability displays to the user.     | NA                    |
| type              | String                    | Indicates the ability type.     | In the stage model, the value is directly assigned to the page type.|
| formsEnabled      | boolean                   | Whether the ability card is enabled. **true** to enable, **false** otherwise.     | NA                              |
| formInfo          | FormInfo struct            | Description of a card.      | NA                              |
| uri               | String                    | URI of the ability.     | The FA model is supported.                     |
| launchType        | String                    | Launcher type in ability.        | NA                      |
| orientation       | String                    | Indicates the orientation information in ability.     | NA                              |
| visible           | boolean                   | Indicates the visible information in ability. The value **true** indicates that the same-layer tag is visible, and **false** indicates the opposite.     | NA                              |
| grantPermission   | boolean                   | Indicates the grantPermission information in ability. The value true indicates that permissions can be granted to any data in ability, and the value false indicates that permissions cannot be granted to any data in ability.  | NA                              |
| readPermission    | String                    | Indicates the readPermission information in ability. | NA                              |
| writePermission   | String                    | Indicates the writePermission information in ability.   | NA                              |
| uriPermissionMode | String                    | Indicates the uriPermissionMode information in ability.  | NA                              |
| uriPermissionPath | String                    | Indicates the uriPermissionPath information in ability.| NA                              |
| directLaunch      | boolean                   | Indicates the directLaunch information in ability. The value true indicates that applications can be started when the device is not unlocked, and the value false indicates that applications cannot be started when the device is not unlocked.  | NA                              |
| mission           | String                    | Mission information in ability.   | NA                              |
| targetAbility     | String                    | Indicates the targetAbility information in ability.  | NA                              |
| multiUserShared   | boolean                   | Identifies the multiUserShared information in ability. The value true indicates that multi-user status sharing is supported, and the value false indicates that multi-user status sharing is not supported.  | NA                              |
| supportPipMode    | boolean                   | Indicates the supportPipMode information in ability. The value true indicates that a subscriber is allowed to enter the PIP mode, and the value false indicates that a subscriber is not allowed to enter the PIP mode. | NA                              |
| srcLanguage       | String                    | Indicates the srcLanguage information in ability.    | NA                              |
| srcPath           | String                    | srcPath information in ability. | NA                              |
| srcEntrance       | String                    | Indicates the srcEntrance information in ability.     | NA                              |
| continuable       | boolean                   | Indicates the continuable information in ability. true indicates that ability can be migrated, and false indicates that ability cannot be migrated.| NA                              |
| metaData          | MetaData struct (see **MetaData Struct** below)| User-defined meta information of ability.    | NA                             |
| configChanges     | List\<String>             | Indicates the configChanges information in ability.   | NA                              |
| formInfos         | List\<AbilityFormInfo>    | Indicates the forms information in ability.             | NA                              |
| permissions       | List\<String>             | Indicates the permissions information in ability.          | NA                              |
| skills            | List\<SkillInfo>          | Skills information in ability.              | NA                              |
| backgroundModes   | List\<String>             | Indicates the backgroundModes information in ability.      | NA                              |
| labels            | HashMap\<String, String>  | Name of ability displayed to users in multiple languages.    | NA                             |
| descriptions      | HashMap\<String, String>  | Description of ability in multiple languages.             | NA                              |

### Distro Struct

| Field               | Type   | Description                      | Remarks                                                        |
| ------------------- |---------| ------------------------- | ------------------------------------------------------------ |
| moduleName          | String  | Name of the current module.   | Corresponds to the moduleName column in the module structure in the stage model.                |
| moduleType          | String  | Type of the current HAP.      | Corresponds to the moduleType column in the module structure of the stage model.                |
| deliveryWithInstall | boolean | Indicates whether the current HAP is installed during user-initiated installation. The value true indicates yes and the value false indicates no.| Corresponds to the deliveryWithInstall column in the module structure in the stage model.        |
| installationFree    | int     | Whether the HAP file supports the installation-free feature.          | Corresponds to the installationFree column in the module structure in the stage model. If the column is set to true in the JSON file, 1 is returned. If the column is set to false, 0 is returned. If the column is not set, 2 is returned.|
| virtualMachine      | String  | Type of the target VM where the HAP is running, which is used for cloud distribution, such as the application market and distribution center.| It corresponds to the virtualMachine column in the module structure in the stage model.|

### MetaData Struct

| Field          | Type                | Description                            | Remarks                     |
| -------------- |----------------------| -------------------------------- | ------------------------- |
| parameters     | List\<MetaDataInfo>  | Metadata parameter information.          | This field is specific to the FA model and is deprecated for the stage model. |
| results        | List\<MetaDataInfo>  | Indicates the results of the metadata.       | This field is specific to the FA model and is deprecated for the stage model. |
| customizeDatas | List\<CustomizeData> | Indicates the customizeDatas information of the metadata.| NA                         |

### MetaDataInfo Struct

| Field       | Type  | Description                             | Remarks                     |
| ----------- | ------ | --------------------------------- | ------------------------- |
| name        | String | Indicates the name of MetaDataInfo.       | This field is specific to the FA model and is deprecated for the stage model. |
| description | String | Indicates the description of MetaDataInfo.| This field is specific to the FA model and is deprecated for the stage model. |
| type        | String | Indicates the type of MetaDataInfo.       | This field is specific to the FA model and is deprecated for the stage model. |

### CustomizeData Struct

| Field | Type  | Description                        | Remarks                   |
| ----- | ------ | ---------------------------- | ----------------------- |
| name  | String | Specifies the name of CustomizeData. | Metadata of the stage model.|
| value | String | Indicates the value of CustomizeData.| Metadata of the stage model.|
| extra | String | Indicates the extra information about CustomizeData.| Metadata of the stage model.|

### ReqPermission Struct

| Field     | Type                              | Description                                                      | Remarks|
| --------- | ---------------------------------- |------------------------------------------------------------| ---- |
| name      | String                             | Name of a request permission.                                | NA   |
| reason    | String                             | This column is mandatory when the permission to be applied for is user_grant. It describes the reason for applying for the permission.| NA   |
| usedScene | UsedScene struct (see **UsedScene Struct** below)| Application scenario of the permission. The value can be **ability** or **when**. Multiple abilities can be configured.| NA   |
| reasons   | HashMap\<String, String>           | This column is mandatory when the permission to be applied for is user_grant. It describes the reason for applying for the permission.| NA    |

### UsedScene Struct

| Field   | Type         | Description                                                        | Remarks|
| ------- | ------------- | ------------------------------------------------------------ | ---- |
| ability | List\<String> | Meta capability (ability) that needs to use the permission. The value is an array.  | NA   |
| when    | String        | Time when the permission is used. The value is inuse/always, indicating that the permission can be used only on the foreground and both the foreground and background.| NA   |

### Shortcut Struct

| Field      | Type                  | Description                                                        | Remarks|
| ---------- | ---------------------- | :----------------------------------------------------------- | ---- |
| shortcutId | String                 | ShortCut ID.                                            | NA   |
| label      | String                 | Label of the **ShortCut** struct.                                      | NA   |
| icon       | String                 | Icon of the ShortCut.                                      | NA   |
| intents    | List\<IntentInfo>      | Target intent information set defined in the shortcut. Each intent can be configured with two sublabels: targetClass and targetBundle.| NA   |
| labels     | HashMap\<String, String> | ShortCut name displayed to users in multiple languages.                       | NA   |

### IntentInfo Struct

| Field        | Type  | Description            | Remarks|
| ------------ | ------ | ---------------- | ---- |
| targetClass  | String | Shortcut target type.| NA   |
| targetBundle | String | Name of the target shortcut package.| NA   |

### DistroFilter Struct

| Field         | Type               | Description                                 | Remarks|
| ------------- | ------------------- | ------------------------------------- | ---- |
| apiVersion    | ApiVersion struct   | Indicates the apiVersion information in DistroFilter.   | NA   |
| screenShape   | ScreenShape struct  | Indicates the screenShape information in DistroFilter.  | NA   |
| screenDensity | ScreenDensity struct| Indicates the screenDensity information in DistroFilter.| NA   |
| screenWindow  | ScreenWindow struct | Indicates the screenWindow information in DistroFilter. | NA   |
| countryCode   | CountryCode struct  | Country code in DistroFilter.  | NA   |

### ApiVersion Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Indicates the policy information in the structure.| NA   |
| value  | List\<String> | Value information in the structure. | NA   |

### ScreenShape Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Indicates the policy information in the structure.| NA   |
| value  | List\<String> | Value information in the structure. | NA   |

### ScreenDensity Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Indicates the policy information in the structure.| NA   |
| value  | List\<String> | Value information in the structure. | NA   |

### ScreenWindow Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Indicates the policy information in the structure.| NA   |
| value  | List\<String> | Value information in the structure. | NA   |

### CountryCode Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Indicates the policy information in the structure.| NA   |
| value  | List\<String> | Value information in the structure. | NA   |

### ExtensionAbilityInfo Struct

| Field           | Type                    | Description                                                 | Remarks               |
| --------------- | ------------------------ | ----------------------------------------------------- | ------------------ |
| name            | String                   | Logical name of the current ExtensionAbility.      | Supported the stage model.                     |
| srcEntrance     | String                   | JS code path of the ExtensionAbility. | Supported the stage model.                  |
| icon            | String                   | ExtensionAbility icon.      | Supported the stage model.                     |
| label           | String                   | Name of the ExtensionAbility displayed to users.   | Supported the stage model.          |
| description     | String                   | Description of the ExtensionAbility.           | Supported the stage model.                |
| type            | String                   | ExtensionAbility type, which can be form, workScheduler, inputMethod, service, accessibility, dataShare, fileShare, wallpaper or backup.| Supported by the stage model. Currently, only form and staticSubscriber information is parsed. Other types (such as workScheduler, inputMethod, service, accessibility, dataShare, fileShare, wallpaper and backup) are not parsed.       |
| permissions     | List\<String>            | Indicates the set of permissions that need to be applied for when the ability of another application is called.| Supported the stage model.     |
| readPermission  | String                   | Permission required for reading data in ability.                        | Supported the stage model. |
| writePermission | String                   | Permission required for writing data to the ability.                          | Supported the stage model.   |
| visible         | boolean                  | Whether the ExtensionAbility can be called by other applications. **true** if it can be invoked by other applications, **false** otherwise.             | Supported the stage model. |
| skills          | List\<SkillInfo>         | Feature set of intents that can be received by the ExtensionAbility.             | Supported the stage model.  |
| metadataInfos   | List\<ModuleMetadataInfo>| Metadata that can be received by the ExtensionAbility.               | Supported the stage model. |
| metadata        | MetaData Struct          | Metadata of the ExtensionAbility. | Assign the information in metadata to CustomizeData.|
| uri             | String                   | URI of the data provided by the ExtensionAbility.                      | Supported the stage model.     |
| descriptions    | HashMap\<String, String> | ExtensionAbility description in multiple languages.   | NA                 |
| labels          | HashMap\<String, String> | Name of the ExtensionAbility displayed to users in multiple languages. | NA                   |

### SkillInfo Struct

| Field    | Type               | Description                  | Remarks|
| -------- | ------------------- |----------------------| ---- |
| actions  | List\<String>       | A set of action values that identify intents that can be received.| NA   |
| entities | List\<String>       | Category set of meta-capabilities that identify intents that can be received.  | NA   |
| domainVerify | boolean       | Specifies whether ability supports domain verification. **true** if supported, **false** otherwise.  | NA   |

### UriInfo Struct

| Field         | Type  | Description                    | Remarks|
| ------------- | ------ |------------------------| ---- |
| schema        | String | Indicates the normal form of ModuleUriInfo.  | NA   |
| host          | String | Host information of the ModuleUriInfo.  | NA   |
| port          | String | Port information of the ModuleUriInfo.  | NA   |
| pathStartWith | String | Path prefix of the ModuleUriInfo.  | NA   |
| pathRegex     | String | Indicates the path regular expression of ModuleUriInfo.| NA   |
| path          | String | Path information of the ModuleUriInfo.  | NA   |
| type          | String | Type of the ModuleUriInfo.    | NA   |

### AbilityFormInfo Struct

| Field               | Type                    | Description                                                        | Remarks       |
| ------------------- | -------------------------| ------------------------------------------------------------ |-----------|
| name                | String                   | Name of the forms.                                             | NA        |
| type                | String                   | The tag identifies the type of the card.                                          | NA        |
| updateEnabled       | boolean                  | Indicates whether the card supports scheduled refresh. **true** if supported, **false** otherwise.                                  | NA        |
| scheduledUpdateTime | String                   | Time when the vertex of a tag is refreshed. The value is accurate to minute and is counted in 24 hours.      | NA        |
| updateDuration      | int                      | Update frequency of a card. The unit is 30 minutes. The value is a multiple of 30.  | NA        |
| supportDimensions   | List\<String>            | Card appearance specifications. The value can be "1 * 2," "2 * 2," "2 * 4," or "4 * 4."  | NA        |
| defaultDimension    | String                   | Default appearance of a widget. The value must be in the list specified by supportDimensions.| NA        |
| MetaData            | MetaData                 | Custom information about a card.                                        | NA        |
| description         | String                   | Description of forms.                            | The stage model is added.|
| src                 | String                   | UI code of the tag JS widget.                                      | NA        |
| windowInfo          | ModuleWindowInfo struct  | Window information of the ability.                                      | NA        |
| isDefault           | boolean                  | Indicates whether a widget is the default widget. Each HAP can have only one default widget. The value true indicates the default card, and the value false indicates a non-default card.     | NA        |
| colorMode           | String                   | Hue of a card. The value can be auto, dark, or light.             | NA        |
| formConfigAbility   | String                   | Name of the ability to adjust the widget.                                   | NA        |
| formVisibleNotify   | String                   | Indicates whether a card is allowed to use the card visibility notification.                        | NA        |
| providerAbility     | String                   | Name of the ability or extension to which the widget provider belongs.<br>1. FA model: If the widget is configured in the ability of the service type, set providerAbility to mainAbility.<br>2. FA model: If the widget is configured in a Page ability, set providerAbility to the current ability.<br>3. FA model: If mainAbility is not configured, providerAbility is set to system.home in the current HAP package. Otherwise, the ability of the first page is used.<br>4. In the stage model (following the preceding rules), set providerAbility to mainElement.| NA |
| descriptions        | HashMap\<String, String> | Description of ability in multiple languages.                                    | NA     |


### CommonEvent Struct

| Field      | Type         | Description                                  | Remarks                                            |
| ---------- | ------------- | -------------------------------------- | ------------------------------------------------ |
| name       | String        | Name of the class corresponding to the current static common event.            | The stage model is obtained from the extension of the staticSubscriber type.|
| permission | String        | Permission to be applied for to implement the static common event.  | The stage model is obtained from the extension of the staticSubscriber type.|
| data       | List\<String> | Additional data array to be carried in the current static public time.| The stage model is obtained from the extension of the staticSubscriber type.|
| type       | List\<String> | Class array for configuring the current static public time.        | The stage model is obtained from the extension of the staticSubscriber type.|
| events     | List\<String> | A set of event values that identify intents that can be received.     | The stage model is obtained from the extension of the staticSubscriber type.|

### DependencyItem Struct

| Field          | Type  | Description          | Remarks|
|--------------| ------ |--------------| ---- |
| bundleName   | String | Name of a shared bundle.| NA   |
| moduleName   | String | Module name of the shared package.| NA   |
| versionCode  | String | Version number of the shared bundle.     | NA   |

### ModuleAtomicService Struct

| Field        | Type                  | Description          | Remarks|
|--------------|------------------------|----------------| ---- |
| preloadItems | list\<PreloadItem>     | Preloads an object.    | NA   |

### PreloadItem Struct

| Field        | Type  | Description          | Remarks|
|--------------|--------|----------------| ---- |
| moduleName   | String | Name of the preloaded module.| NA   |

### DeviceConfig Struct

| Field                          | Type   | Description                                    | Remarks|
|--------------------------------|-------- |------------------------------------------| ---- |
| targetReqSdk                   | String  | Target SDK version of DeviceConfig. | NA   |
| compatibleReqSdk               | String  | Specifies the SDK version compatible with DeviceConfig. | NA   |
| jointUserid                    | String  | jointUserid of the DeviceConfig application.     | NA   |
| process                        | String  | Identifies the process of the DeviceConfig application.            | NA   |
| arkFlag                        | String  | arkFlag of the application DeviceConfig.         | NA   |
| targetArkVersion               | String  | Indicates the targetArkVersion of the DeviceConfig application.| NA   |
| compatibleArkVersion           | String  | Compatible ArkVersion of the application DeviceConfig.  | NA   |
| directLaunch                   | boolean | Indicates the direct startup of the DeviceConfig application. The value true indicates that applications can be started when the device is not unlocked, and the value false indicates that applications cannot be started when the device is not unlocked.        | NA   |
| distributedNotificationEnabled | boolean | Indicates the distributedNotificationEnabled of the application AppJson. The value true indicates that the distributed notification function is enabled, and the value false indicates that the distributed notification function is disabled.| NA   |

### DefPermission Struct

| Field          | Type                    | Description                                     | Remarks|
|----------------|--------------------------|-------------------------------------------| ---- |
| name           | String                   | Indicates the name of the DefPermission.              | NA   |
| grantMode      | String                   | Indicates the grantMode of DefPermission.             | NA   |
| group          | String                   | Identifies the DefPermission group.                    | NA   |
| label          | String                   | Label of DefPermission.                  | NA   |
| description    | String                   | Description of the DefPermission.                  | NA   |
| availableScope | List\<String>            | Indicates the available scope of DefPermission.              | NA   |
| labels         | HashMap\<String, String> | Label identifying the multi-language application DefPermission.    | NA   |
| descriptions   | HashMap\<String, String> | Identifies the description of the multilingual application DefPermission.    | NA   |

### DefinePermission Struct

| Field                  | Type                    | Description                                              | Remarks|
|------------------------|--------------------------|----------------------------------------------------| ---- |
| name                   | String                   | Name of a DefinePermission.                        | NA   |
| grantMode              | String                   | Indicates the grantMode of DefinePermission.                       | NA   |
| availableLevel         | String                   | Group that identifies a DefinePermission.                              | NA   |
| provisionEnable        | boolean                  | Indicates whether to enable the provision of the module definition permission. The value true indicates that certificate-based permission application is supported, and the value false indicates that certificate-based permission application is not supported.                          | NA   |
| distributedSceneEnable | boolean                  | Identifies the distributedSceneEnable of ModuleDefinePermissions. The value true indicates that the permission can be used in distributed scenarios, and the value false indicates that the permission cannot be used in distributed scenarios.| NA   |
| label                  | String                   | Label of DefinePermission.                             | NA   |
| description            | String                   | Description of the DefinePermission.                             | NA   |
| descriptions           | HashMap\<String, String> | Identifies the description of the multilingual application DefinePermission.               | NA   |
| labels                 | HashMap\<String, String> | Label identifying the multi-language application DefinePermission.               | NA   |

### DefPermissionsGroups Struct

| Field       | Type   | Description                        | Remarks|
|-------------|---------|------------------------------| ---- |
| name        | String  | Indicates the name of the DefPermissionGroup.| NA   |
| order       | String  | Sequence of DefPermissionGrou. | NA   |
| icon        | String  | Icon that identifies a DefPermissionGroup.| NA   |
| label       | String  | Label of the DefPermissionGroup.| NA   |
| description | String  | Description of the DefPermissionGroup.| NA   |
| request     | String  | Identifies the DefPermissionGroup request.| NA   |

### FormInfo Struct

| Field         | Type         | Description                    | Remarks|
|---------------|---------------|--------------------------| ---- |
| formEntity    | List\<String> | Widget entity.| NA   |
| minHeight     | String        | Minimum height of the widget.  | NA   |
| defaultHeight | String        | Default height of the widget.  | NA   |
| minWidth      | String        | Minimum width of the widget  | NA   |
| defaultWidth  | String        | Default width of the widget.  | NA   |

### ModuleMetadataInfo Struct

| Field    | Type   | Description                        | Remarks|
|----------|---------|------------------------------| ---- |
| name     | String  | Name of the ModuleMetadataInfo.| NA   |
| value    | String  | Value of ModuleMetadataInfo.  | NA   |
| resource | String  | Identifies the ModuleMetadataInfo resource.| NA   |

### ModuleWindowInfo Struct

| Field           | Type   | Description                               | Remarks|
|-----------------|---------|-------------------------------------| ---- |
| designWidth     | int     | Design width of the used scenario of the module.          | NA   |
| autoDesignWidth | boolean | autoDesignWidth of ModuleUsedScene. The value true indicates that designWidth is ignored and the design reference width is calculated based on the device width and screen density. The value false indicates that the design reference width is designWidth.| NA   |
