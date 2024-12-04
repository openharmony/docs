# Unpacking Tool


The unpacking tool is a commissioning tool used to unpack HAP (an application package), HSP (dynamically shared library), and APP (application set to launch to the application market) files. It also provides Java APIs to parse the HAP, HSP, and APP files.


The **app_unpacking_tool.jar** package can be found in the OpenHarmony SDK downloaded locally.


## Constraints

The unpacking tool must run in Java 8 or later.


## Unpacking Commands

### Unpacking Commands for HAP Files

You can use the JAR package of the unpacking tool to unpack an HAP file by importing unpacking options and file paths.

#### Example

```
java -jar app_unpacking_tool.jar --mode hap --hap-path <path> --out-path <path> [--force true]
```

#### Parameters

| Name      | Mandatory| Option         | Description                                                        |
| ---------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode     | Yes        | hap           | Unpacking mode.                                                  |
| --hap-path | Yes        | NA            | Path of the HAP file.                                                 |
| --rpcid    | No        | true or false| Whether to extract the rpcid file from the HAP file to a specified directory. If the value is **true**, only the rpcid file is extracted and the HAP file is not unpacked.|
| --out-path | Yes        | NA            | Path of the target files.                                          |
| --force    | No        | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking. |

### Unpacking Commands for APP Files

You can use the JAR package of the unpacking tool to unpack an APP file by importing unpacking options and file paths.

#### Example

```
java -jar app_unpacking_tool.jar --mode app --app-path <path> --out-path <path> [--force true]
```

#### Parameters

| Name      | Mandatory| Option         | Description                                                       |
| ---------- | ---------- |-------------| ----------------------------------------------------------- |
| --mode     | Yes        | app         | Unpacking mode.                                                 |
| --app-path | Yes        | NA          | Path of the APP file.                                                |
| --out-path | Yes        | NA          | Path of the target files.                                         |
| --force    | No        | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking.|

### Obtaining the rpcid File from the HAP File

You can use the JAR package of the unpacking tool to unpack an HAP file to obtain the rpcid file by importing unpacking options and file paths.

#### Example

```
java -jar app_unpacking_tool.jar --mode hap --rpcid true --hap-path <path> --out-path <path> [--force true]
```

#### Parameters

| Name      | Mandatory| Option         | Description                                                        |
| ---------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode     | Yes        | hap           | Unpacking mode.                                                    |
| --rpcid    | No        | true or false| Whether to extract the rpcid file from the HAP file to a specified directory. If the value is **true**, only the rpcid file is extracted and the HAP file is not unpacked.|
| --hap-path | Yes        | NA            | Path of the HAP file.                                                   |
| --out-path | Yes        | NA            | Path of the target rpcid file.                                       |
| --force    | No        | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking. |

### Unpacking Commands for HSP Files

You can use the JAR package of the unpacking tool to unpack an HSP file by importing unpacking options and file paths.

#### Example

```
java -jar app_unpacking_tool.jar --mode hsp --hsp-path <path> --out-path <path> [--force true]
```

#### Parameters

| Name        | Mandatory| Option         | Description                                |
|------------| ---------- | ------------- |------------------------------------|
| --mode     | Yes        | hsp           | Unpacking mode.                             |
| --hsp-path | Yes        | NA            | Path of the HSP file.                           |
| --out-path | Yes        | NA            | Path of the target files.                         |
| --force    | No        | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking.|

### Unpacking Commands for APPQF Files

You can use the JAR package of the unpacking tool to unpack an APPQF file by importing unpacking options and file paths.

#### Example

```
java -jar app_unpacking_tool.jar --mode appqf --appqf-path <path> --out-path <path> [--force true]
```

#### Parameters

| Name          | Mandatory| Option         | Description                                |
|--------------| ---------- |-------------|------------------------------------|
| --mode       | Yes        | appqf       | Unpacking mode.                             |
| --appqf-path | Yes        | NA          | Path of the APPQF file.                         |
| --out-path   | Yes        | NA          | Path of the target files.                         |
| --force      | No        | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking.|

## Package Parsing APIs

The package parsing APIs are used by the application market to parse an HAP, HSP, or APP file and obtain information such as the configuration file.

### Available APIs

| Class              | Prototype                                                    | Type    | Description                                                           |
| ------------------ | ------------------------------------------------------------ | -------- |-------------------------------------------------------------------|
| UncompressEntrance | UncompressResult parseApp(String appPath,String parseMode,String deviceType,String hapName) | Java| Function: Parses **pack.info** in the APP file.<br>Input parameters: **appPath**, which specifies the path of the APP file.<br>Return value: **UncompressResult**.|
| UncompressEntrance | UncompressResult parseApp(InputStream input,String parseMode,String deviceType,String hapName,String outPath) | Java| Function: Parses **pack.info** in the APP file.<br>Input parameters: **input**, which specifies the stream of the APP file.<br>Return value: **UncompressResult**.|
| UncompressEntrance | UncompressResult parseHap(String hapPath)                    | Java| Function: Parses the JSON file in the APP file.<br>Input parameters: **hapPath**, which specifies the path of the HAP file.<br>Return value: **UncompressResult**.   |
| UncompressEntrance | UncompressResult parseHap(InputStream input)                 | Java| Function: Parses the JSON file in the APP file.<br>Input parameters: **input**, which specifies the stream of the HAP file.<br>Return value: **UncompressResult**.  |

## Fields of the Unpacking Tool

### UncompressResult (Bundle Information) Struct

| Field           | Type              | Description                                    | Remarks|
| ----------------| ------------------ |----------------------------------------| ---- |
| result          | boolean            | Whether the parsing is successful.                            | NA   |
| message         | String             | Failure cause returned if the parsing fails.                           | NA   |
| packInfos       | List\<PackInfo>    | Information about **packages** in the **pack.info** file of the bundle.         | NA   |
| profileInfos    | List\<profileInfo> | Configuration information of the application.                               | NA   |
| profileInfosStr | List\<String>      | Configuration information of the application.| NA   |
| icon            | String             | Path of the icon of the entry component. If there is no entry component, the icon path of the first component is returned.| NA   |
| label           | String             | Label of the entry component. If there is no entry component, the label of the first component is returned.| NA   |
| packageSize     | long               | Size of the APP file, in bytes.| NA   |

### PackInfo Struct

| Field               | Type         | Description                                   | Remarks|
| ------------------- | ------------- | --------------------------------------- | ---- |
| name                | String        | Bundle name.                                   | NA   |
| moduleName          | String        | HAP (module) name.                                | NA   |
| moduleType          | String        | Module type.                           | NA   |
| deviceType          | List\<String> | Device type supported by the current HAP.          | NA   |
| deliveryWithInstall | boolean       | Whether the HAP is installed when the user installs the application.| NA   |

### ProfileInfo Struct

| Field        | Type                          | Description                                      | Remarks                                                        |
| ------------ | ------------------------------ | ------------------------------------------ | ------------------------------------------------------------ |
| hapName      | String                         | Name of the HAP file that is being parsed.                   | NA                                                           |
| appInfo      | AppInfo struct (see **AppInfo Struct** below)| Struct of the application information. For details, see **AppInfo Struct** below.  | NA                                                           |
| deviceConfig | Map\<String,DeviceConfig>      | Device information.                              | The storage type is Map\<String,String>, which indicates the device type name and device type value, respectively. In the stage model, this field is stored in the **app** struct.|
| hapInfo      | HapInfo struct (see **HapInfo Struct** below)| Module information in the HAP file. For details, see **HapInfo Struct** below.| NA                                                           |

### AppInfo Struct

| Field                            | Type     | Description                                                                           | Remarks         |
|--------------------------------|---------|-------------------------------------------------------------------------------|-------------|
| bundleName                     | String  | Bundle name of the application.                                                                    | NA          |
| vendor                         | String  | Vendor of the application.                                                                  | NA          |
| relatedBundleName              | String  | Related bundle name of the application.                                                             | NA          |
| versionName                    | String  | Version name of the application.                                                         | NA          |
| versionCode                    | String  | Version code of the application.                                                         | NA          |
| targetApiVersion               | int     | Target API version required for running the application.                                                             | NA          |
| compatibleApiVersion           | int     | API version compatible with the application.                                                                 | NA          |
| appName                        | String  | Label of the ability displayed on the home screen.                                                       | NA          |
| appNameEN                      | String  | Label of the ability displayed on the home screen.                                                       | NA          |
| releaseType                    | String  | Release type of the target API version required for running the application.                                                          | NA          |
| shellVersionCode               | String  | API version number of the application.                                                         | NA          |
| shellVersionName               | String  | API version name of the application.                                                         | NA          |
| multiFrameworkBundle           | boolean | Application framework.                                                        | NA          |
| debug                          | boolean | Whether the application can be debugged.                                                                    | NA          |
| icon                           | String  | Path of the application icon.                                                                    | NA          |
| label                          | String  | Label of the application.                                                                   | NA          |
| description                    | String  | Description of the application.                                                                    | This field is newly added to the stage model.  |
| minCompatibleVersionCode       | int     | Earliest compatible version of the application.                                                               | NA          |
| distributedNotificationEnabled | boolean | Whether the distributed notification feature is enabled for the application.                                                             | This field is newly added to the stage model.  |
| bundleType                     | String  | Bundle type.<br>- **app**: The bundle is used for an application.<br>- **atomicService**: The bundle is used for an atomic service.<br>- **shared**: The bundle is used for a shared library.| NA   |
| compileSdkVersion              | String  | SDK version used for compiling the application.                                                             | This field is valid only for API version 10 and later.  |
| compileSdkType                 | String  | SDK type used for compiling the application.                                                             | This field is valid only for API version 10 and later.  |
| labels                         | HashMap\<String, String> | Labels of the application in multiple languages.| NA          |
| descriptions                   | HashMap\<String, String> | Descriptions of the application in multiple languages.| NA          |

### HapInfo Struct

| Field                | Type                                         | Description                              | Remarks                                  |
| ---------------------|-----------------------------------------------|------------------------------------| ---------------------------------------|
| appModel             | AppModel enumerated value                               | Application framework model.<br>- FA: FA model<br>- STAGE: stage model| NA |
| packageStr           | String                                        | Package information about the application.                   | This field is unique to the FA model.            |
| name                 | String                                        | Name of the module.               | NA                 |
| description          | String                                        | Description of the HAP.                | This field is unique to the FA model.                      |
| supportedModes       | List\<String>                                 | Modes supported by the HAP.              | NA                           |
| abilities            | List\<AbilityInfo>                            | Ability information of the HAP file.               | NA                             |
| defPermissions       | List\<DefPermission>                          | Default permissions of the HAP.         | NA                             |
| definePermissions    | List\<DefinePermission>                       | Defined permissions of the HAP.      | NA                             |
| defPermissionsGroups | List\<DefPermissionsGroups>                   | Default permission groups of the HAP. | NA                             |
| distro               | Distro struct                                 | Distro description of the HAP file.              | NA                             |
| reqCapabilities      | List\<String>                                 | Required capabilities of the HAP.       | NA                           |
| deviceType           | List\<String>                                 | Type of devices on which the HAP can run.        | This field corresponds to **deviceTypes** in the stage model.      |
| metaData             | metaData struct (see **metaData Struct** below)             | Custom metadata of the HAP.               | NA           |
| dependencies         | List\<DependencyItem>                         | Dependencies of the HAP.        | NA                             |
| isJs                 | boolean                                       | Whether the application is a JS application.             | This field is unique to the FA model.           |
| reqPermissions       | list\<ReqPermission>                          | Permissions requested by the application.            | This field corresponds to **requestPermissions** in the stage model.|
| commonEvents         | CommonEvent struct (see **CommonEvent Struct** below)      | Static event.                        | NA     |
| shortcuts            | list\<Shortcut>                               | Shortcuts used by the application.             | NA                  |
| distroFilter         | DistroFilter struct                           | Information distributed by the application market by device form.    | NA               |
| srcEntrance          | String                                        | Entry code path of the application.          | This field is newly added to the stage model.         |
| process              | String                                        | Process name of the HAP.                     | This field is newly added to the stage model.      |
| mainElement          | String                  | Entry ability name or ExtensionAbility name of the HAP file.| This field is newly added to the stage model. In the FA model, the value of **mainAbility** is automatically assigned to **mainElement**.|
| uiSyntax             | String                                        | Syntax type of a JS component.        | This field is newly added to the stage model.      |
| pages                | List\<String>                                 | Information about each page in a JS component.      | This field is newly added to the stage model.      |
| extensionAbilityInfos| List\<ExtensionAbilityInfo>                   | Information about the ExtensionAbility.      | This field is newly added to the stage model.       |
| moduleAtomicService  | ModuleAtomicService struct (see **ModuleAtomicService Struct** below)| Information about the atomic service in the HAP.         | NA              |
| formInfos            | List\<AbilityFormInfo>                        | Widget information.                      | NA              |
| descriptions         | HashMap\<String, String>                      | Description of the HAP.                   | NA             |
| compressedSize       | long                                          | Size of the compressed HAP file, in bytes.        | NA              |
| originalSize         | long                                          | Original size of the HAP file, in bytes.        | NA             |

### AbilityInfo Struct

| Field               | Type                      | Description                                             | Remarks                       |
|-------------------|--------------------------| ------------------------------------------------- | ------------------------------- |
| name              | String                   | Logical name of the ability.                          | NA                              |
| description       | String                   | Description of the ability.                                | NA                              |
| descriptionRes    | String                   | Description of the ability.                            | NA                              |
| icon              | String                   | Icon of the ability.                                  | NA                              |
| iconPath          | String                   | Path of the ability icon.                              | NA                              |
| label             | String                   | Ability name visible to users.                      | NA                              |
| labelRes          | String                   | Ability name visible to users.                  | NA                              |
| type              | String                   | Ability type.                                  | In the stage model, the value is directly assigned to the **page** field.|
| formsEnabled      | boolean                  | Whether the widget is enabled for the ability.                          | NA                              |
| formInfo          | FormInfo struct          | Widget information.                                   | NA                              |
| uri               | String                   | URI of the ability.                             | This field is supported only in the FA model.                     |
| launchType        | String                   | Launcher type of the ability.                  | NA                              |
| orientation       | String                   | Orientation of the ability.                   | NA                              |
| visible           | boolean                  | Whether the ability is visible.                       | NA                              |
| grantPermission   | boolean                  | Granted permissions of the ability.               | NA                              |
| readPermission    | String                   | Read permissions of the ability.                | NA                              |
| writePermission   | String                   | Write permissions of the ability.               | NA                              |
| uriPermissionMode | String                   | URI permission mode of the ability.             | NA                              |
| uriPermissionPath | String                   | URI permission path of the ability.             | NA                              |
| directLaunch      | boolean                  | Whether the ability can be directly launched.                  | NA                              |
| mission           | String                   | Mission of the ability.                       | NA                              |
| targetAbility     | String                   | Target ability of the ability.                 | NA                              |
| multiUserShared   | boolean                  | Whether the ability can be shared by multiple users.               | NA                              |
| supportPipMode    | boolean                  | Whether the ability supports the PIP mode.                | NA                              |
| srcLanguage       | String                   | Source language of the ability.                   | NA                              |
| srcPath           | String                   | Source path of the ability.                       | NA                              |
| srcEntrance       | String                   | Source entrance of the ability.                   | NA                              |
| continuable       | boolean                  | Whether the ability can be continued on another device.                   | NA                              |
| metaData          | MetaData struct (see **MetaData Struct** below)| Custom metadata of the ability.                 | NA                             |
| configChanges     | List\<String>            | Configuration changes of the ability.                 | NA                              |
| formInfos         | List\<AbilityFormInfo>   | Widgets of the ability.                         | NA                              |
| permissions       | List\<String>            | Permissions of the ability.                   | NA                              |
| skills            | List\<SkillInfo>         | Skills of the ability.                        | NA                              |
| backgroundModes   | List\<String>            | Background modes of the ability.               | NA                              |
| labels            | HashMap\<String, String> | Names of the ability displayed to users in multiple languages.               | NA                             |
| descriptions      | HashMap\<String, String> | Descriptions of the ability in multiple languages.                        | NA                              |

### Distro Struct

| Field               | Type   | Description                                   | Remarks                                                        |
| ------------------- |---------| --------------------------------------- | ------------------------------------------------------------ |
| moduleName          | String  | Name of the module.                   | This field corresponds to the **moduleName** field under the **module** struct in the stage model.                |
| moduleType          | String  | Type of the HAP.                      | This field corresponds to the **moduleType** field under the **module** struct in the stage model.                |
| deliveryWithInstall | boolean | Whether the HAP is installed when the user installs the application.| This field corresponds to the **deliveryWithInstall** field under the **module** struct in the stage model.        |
| installationFree    | int     | Whether the HAP file supports the installation-free feature.          | This parameter corresponds to the **installationFree** field under the **module** struct in the stage model. In the JSON file, if this parameter is set to **true**, **1** is returned; if this parameter is set to **false**, **0** is returned; if this parameter is not set, **2** is returned.|
| virtualMachine      | String  | Type of the target virtual machine (VM) where the HAP is running. It is used for cloud distribution, such as the application market and distribution center.| This field corresponds to the **virtualMachine** field under the **module** struct in the stage model.|

### MetaData Struct

| Field          | Type                | Description                            | Remarks                     |
| -------------- |----------------------| -------------------------------- | ------------------------- |
| parameters     | List\<MetaDataInfo>  | Metadata information.          | This field is unique to the FA model. It is deprecated in the stage model. |
| results        | List\<MetaDataInfo>  | Result information of the metadata.       | This field is unique to the FA model. It is deprecated in the stage model. |
| customizeDatas | List\<CustomizeData> | Custom data of the metadata.| NA                         |

### MetaDataInfo Struct

| Field       | Type  | Description                             | Remarks                     |
| ----------- | ------ | --------------------------------- | ------------------------- |
| name        | String | Name of the **MetaDataInfo** struct.       | This field is unique to the FA model. It is deprecated in the stage model. |
| description | String | Description of the **MetaDataInfo** struct.| This field is unique to the FA model. It is deprecated in the stage model. |
| type        | String | Type of the **MetaDataInfo** struct.       | This field is unique to the FA model. It is deprecated in the stage model. |

### CustomizeData Struct

| Field | Type  | Description                        | Remarks                   |
| ----- | ------ | ---------------------------- | ----------------------- |
| name  | String | Name of the **CustomizeData** struct. | This field corresponds to **metadata** in the stage model.|
| value | String | Value of the **CustomizeData** struct.| This field corresponds to **metadata** in the stage model.|
| extra | String | Extra information of the **CustomizeData** struct.| This field corresponds to **metadata** in the stage model.|

### ReqPermission Struct

| Field     | Type                              | Description                                                      | Remarks|
| --------- | ---------------------------------- |------------------------------------------------------------| ---- |
| name      | String                             | Name of the requested permission.                                | NA   |
| reason    | String                             | Reason for requesting the permission. This field is mandatory for a user_grant permission.| NA   |
| usedScene | UsedScene struct (see **UsedScene Struct** below)| Application scenario of the permission. The value can be **ability** or **when**. Multiple abilities can be configured.| NA   |
| reasons   | HashMap\<String, String>           | Reason for requesting the permission. This field is mandatory for a user_grant permission.| NA    |

### UsedScene Struct

| Field   | Type         | Description                                                        | Remarks|
| ------- | ------------- | ------------------------------------------------------------ | ---- |
| ability | List\<String> | Abilities that use the permission. The value is an array.  | NA   |
| when    | String        | Time when the permission is used. The value can be **inuse** (the permission can be used only in the foreground) or **always** (the permission can be used in foreground and background).| NA   |

### Shortcut Struct

| Field      | Type                  | Description                                                        | Remarks|
| ---------- | ---------------------- | :----------------------------------------------------------- | ---- |
| shortcutId | String                 | ID of the **ShortCut** struct.                                            | NA   |
| label      | String                 | Label of the **ShortCut** struct.                                      | NA   |
| icon       | String                 | Icon of the **ShortCut** struct.                                      | NA   |
| intents    | List\<IntentInfo>      | Intents to which the shortcut points. The attribute consists of the **targetClass** and **targetBundle** sub-attributes.| NA   |
| labels     | HashMap\<String, String> | Shortcut names displayed to users in multiple languages.                       | NA   |

### IntentInfo Struct

| Field        | Type  | Description            | Remarks|
| ------------ | ------ | ---------------- | ---- |
| targetClass  | String | Class name for the target ability of the shortcut.| NA   |
| targetBundle | String | Target bundle name of the shortcut.| NA   |

### DistroFilter Struct

| Field         | Type               | Description                                 | Remarks|
| ------------- | ------------------- | ------------------------------------- | ---- |
| apiVersion    | ApiVersion struct   | API version of the **DistroFilter** struct.   | NA   |
| screenShape   | ScreenShape struct  | Screen shape of the **DistroFilter** struct.  | NA   |
| screenDensity | ScreenDensity struct| Screen density of the **DistroFilter** struct.| NA   |
| screenWindow  | ScreenWindow struct | Screen window of the **DistroFilter** struct. | NA   |
| countryCode   | CountryCode struct  | Country code of the **DistroFilter** struct.  | NA   |

### ApiVersion Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Policy information in the struct.| NA   |
| value  | List\<String> | Value information in the struct. | NA   |

### ScreenShape Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Policy information in the struct.| NA   |
| value  | List\<String> | Value information in the struct. | NA   |

### ScreenDensity Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Policy information in the struct.| NA   |
| value  | List\<String> | Value information in the struct. | NA   |

### ScreenWindow Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Policy information in the struct.| NA   |
| value  | List\<String> | Value information in the struct. | NA   |

### CountryCode Struct

| Field  | Type         | Description                    | Remarks|
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | Policy information in the struct.| NA   |
| value  | List\<String> | Value information in the struct. | NA   |

### ExtensionAbilityInfo Struct

| Field           | Type                    | Description                                                 | Remarks                               |
| --------------- | ------------------------ | ----------------------------------------------------- | ----------------------------------- |
| name            | String                   | Logical name of the ExtensionAbility.                     | This field is supported only in the stage model.                     |
| srcEntrance     | String                   | JS code path of the ExtensionAbility.               | This field is supported only in the stage model.                     |
| icon            | String                   | Icon ID of the ExtensionAbility.                         | This field is supported only in the stage model.                     |
| label           | String                   | ExtensionAbility name visible to users.                 | This field is supported only in the stage model.                     |
| description     | String                   | Description of the ExtensionAbility.                           | This field is supported only in the stage model.                     |
| type            | String                   | Type of the ExtensionAbility, which can be **form**, **workScheduler**, **inputMethod**, **service**, **accessibility**, **dataShare**, **fileShare**, **wallpaper**, or **backup**.| This field is supported only in the stage model. Currently, only **form** and **staticSubscriber** information is parsed. The information of other types is not parsed.       |
| permissions     | List\<String>            | Permissions required when the ExtensionAbility is called by the ability of another application.      | This field is supported only in the stage model.                     |
| readPermission  | String                   | Permission required for reading data in the ExtensionAbility.                        | This field is supported only in the stage model.                   |
| writePermission | String                   | Permission required for writing data to the ExtensionAbility.                          | This field is supported only in the stage model.                  |
| visible         | boolean                  | Whether the ExtensionAbility can be called by other applications.             | This field is supported only in the stage model.                  |
| skills          | List\<SkillInfo>         | Skills of the Want that the extensionAbility can receive.             | This field is supported only in the stage model.                   |
| metadataInfos   | List\<ModuleMetadataInfo>| Metadata that the ExtensionAbility can receive.               | This field is supported only in the stage model.                   |
| metadata        | MetaData Struct          | Metadata of the ExtensionAbility.                           | The information in **metadata** is assigned to **CustomizeData**.|
| uri             | String                   | URI of the data provided by the ExtensionAbility.                      | This field is supported only in the stage model.                          |
| descriptions    | HashMap\<String, String> | Descriptions of the ExtensionAbility in multiple languages.                     | NA                              |
| labels          | HashMap\<String, String> | Names of the ExtensionAbility displayed to users in multiple languages.           | NA                             |

### SkillInfo Struct

| Field    | Type               | Description                  | Remarks|
| -------- | ------------------- |----------------------| ---- |
| actions  | List\<String>       | Actions of the Want that the ExtensionAbility can receive.| NA   |
| entities | List\<String>       | Entities of the Want that the ExtensionAbility can receive.  | NA   |

### UriInfo Struct

| Field         | Type  | Description                    | Remarks|
| ------------- | ------ |------------------------| ---- |
| schema        | String | Schema information of the **ModuleUriInfo** struct.  | NA   |
| host          | String | Host of the **ModuleUriInfo** struct.  | NA   |
| port          | String | Port of the **ModuleUriInfo** struct.  | NA   |
| pathStartWith | String | Path prefix of the **ModuleUriInfo** struct.  | NA   |
| pathRegex     | String | Path regular expression of the **ModuleUriInfo** struct.| NA   |
| path          | String | Path information of the **ModuleUriInfo** struct.  | NA   |
| type          | String | Type of the **ModuleUriInfo** struct.    | NA   |

### AbilityFormInfo Struct

| Field               | Type                    | Description                                                        | Remarks       |
| ------------------- | -------------------------| ------------------------------------------------------------ |-----------|
| name                | String                   | Name of the widget.                                             | NA        |
| type                | String                   | Type of the widget.                                          | NA        |
| updateEnabled       | boolean                  | Whether the widget supports scheduled refresh.                                  | NA        |
| scheduledUpdateTime | String                   | Scheduled time to update the widget. The value is in 24-hour format and accurate to the minute.      | NA        |
| updateDuration      | int                      | Interval to update the widget. The unit is 30 minutes. The value is a multiple of 30.  | NA        |
| supportDimensions   | List\<String>            | Dimensions supported by the widget, which can be **1 * 2**, **2 * 2**, **2 * 4**, or **4 * 4**.  | NA        |
| defaultDimension    | String                   | Default dimensions of the widget. The value must be available in the **supportDimensions** array of the widget.| NA        |
| MetaData            | MetaData                 | Custom data of the widget.                                        | NA        |
| description         | String                   | Description of the widget.                                             | This field is newly added to the stage model.|
| src                 | String                   | JS code of the widget.                                      | NA        |
| windowInfo          | ModuleWindowInfo struct  | Window information of the ability.                                      | NA        |
| isDefault           | boolean                  | Whether the widget is a default one. Each HAP has only one default widget.     | NA        |
| colorMode           | String                   | Color mode of the widget, which can be **auto**, **dark**, or **light**.             | NA        |
| formConfigAbility   | String                   | Ability name for widget adjustment.                                   | NA        |
| formVisibleNotify   | String                   | Whether the widget is allowed to use the visibility notification.                        | NA        |
| providerAbility     | String                   | Ability or ExtensionAbility name of the widget provider.<br>- FA model: If the widget is configured in an ability of the Service type, set **providerAbility** to **mainAbility**.<br/>- FA model: If the widget is configured in an ability of the Page type, set **providerAbility** to the current ability.<br/>- FA model: If **mainAbility** is not configured, set **providerAbility** to the ability that preferentially uses **system.home** in the current HAP. Otherwise, set **providerAbility** to the ability of the first page.<br/>- Stage model: Set **providerAbility** to **mainElement**.| NA |
| descriptions        | HashMap\<String, String> | Descriptions of the ability in multiple languages.                                    | NA     |


### CommonEvent Struct

| Field      | Type         | Description                                  | Remarks                                            |
| ---------- | ------------- | -------------------------------------- | ------------------------------------------------ |
| name       | String        | Name of the class corresponding to the current static common event.            | In the stage model, the value is obtained from the StaticSubscriberExtensionAbility.|
| permission | String        | Permissions required to implement the static common event.  | In the stage model, the value is obtained from the StaticSubscriberExtensionAbility.|
| data       | List\<String> | Additional data array to be carried in the static common event.| In the stage model, the value is obtained from the StaticSubscriberExtensionAbility.|
| type       | List\<String> | Type array for configuring the static common event.        | In the stage model, the value is obtained from the StaticSubscriberExtensionAbility.|
| events     | List\<String> | Events of the Want that the ExtensionAbility can receive.     | In the stage model, the value is obtained from the StaticSubscriberExtensionAbility.|

### DependencyItem Struct

| Field          | Type  | Description          | Remarks|
|--------------| ------ |--------------| ---- |
| bundleName   | String | Bundle name of the shared package.| NA   |
| moduleName   | String | Module name of the shared package.| NA   |
| versionCode  | String | Version number of the shared bundle.     | NA   |

### ModuleAtomicService Struct

| Field        | Type                  | Description          | Remarks|
|--------------|------------------------|----------------| ---- |
| preloadItems | list\<PreloadItem>     | Preloaded objects.    | NA   |

### PreloadItem Struct

| Field        | Type  | Description          | Remarks|
|--------------|--------|----------------| ---- |
| moduleName   | String | Name of the preloaded module.| NA   |

### DeviceConfig Struct

| Field                          | Type   | Description                                    | Remarks|
|--------------------------------|-------- |------------------------------------------| ---- |
| targetReqSdk                   | String  | Target SDK version requested. | NA   |
| compatibleReqSdk               | String  | Compatible SDK version requested. | NA   |
| jointUserid                    | String  | Joint user ID.     | NA   |
| process                        | String  | Process.            | NA   |
| arkFlag                        | String  | ArkCompiler flag.         | NA   |
| targetArkVersion               | String  | Target ArkCompiler version.| NA   |
| compatibleArkVersion           | String  | Compatible ArkCompiler version.  | NA   |
| directLaunch                   | boolean | Whether direct launch is supported.        | NA   |
| distributedNotificationEnabled | boolean | Whether distributed notification is enabled.| NA   |

### DefPermission Struct

| Field          | Type                    | Description                                     | Remarks|
|----------------|--------------------------|-------------------------------------------| ---- |
| name           | String                   | Name of the default permission.              | NA   |
| grantMode      | String                   | Grant mode of the default permission.             | NA   |
| group          | String                   | Group of the default permission.                    | NA   |
| label          | String                   | Label of the default permission.                  | NA   |
| description    | String                   | Description of the default permission.                  | NA   |
| availableScope | List\<String>            | Available scope of the default permission.              | NA   |
| labels         | HashMap\<String, String> | Labels of the default permission in multiple languages.    | NA   |
| descriptions   | HashMap\<String, String> | Descriptions of the default permission in multiple languages.    | NA   |

### DefinePermission Struct

| Field                  | Type                    | Description                                              | Remarks|
|------------------------|--------------------------|----------------------------------------------------| ---- |
| name                   | String                   | Name of the defined permission.                        | NA   |
| grantMode              | String                   | Grant mode of the defined permission.                       | NA   |
| availableLevel         | String                   | Group of the defined permission.                              | NA   |
| provisionEnable        | boolean                  | Whether the defined permission is enabled.                          | NA   |
| distributedSceneEnable | boolean                  | Whether the distributed scene is enabled for the defined permission.| NA   |
| label                  | String                   | Label of the defined permission.                             | NA   |
| description            | String                   | Description of the defined permission.                             | NA   |
| descriptions           | HashMap\<String, String> | Descriptions of the defined permission in multiple languages.               | NA   |
| labels                 | HashMap\<String, String> | Labels of the defined permission in multiple languages.               | NA   |

### DefPermissionsGroups Struct

| Field       | Type   | Description                        | Remarks|
|-------------|---------|------------------------------| ---- |
| name        | String  | Name of the default permission group.| NA   |
| order       | String  | Sequence of the default permission group. | NA   |
| icon        | String  | Icon of the default permission group.| NA   |
| label       | String  | Label of the default permission group.| NA   |
| description | String  | Description of the default permission group.| NA   |
| request     | boolean | Request for the default permission group.| NA   |

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
| value    | String  | Value of the ModuleMetadataInfo.  | NA   |
| resource | String  | Resource of the ModuleMetadataInfo.| NA   |

### ModuleWindowInfo Struct

| Field           | Type   | Description                               | Remarks|
|-----------------|---------|-------------------------------------| ---- |
| designWidth     | int     | Designed width of the used scene of the module.          | NA   |
| autoDesignWidth | boolean | Automatically designed width of the used scene of the module.| NA   |
