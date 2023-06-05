# Packing and Unpacking Tools
## Overview

The packing tool packs compiled files for installation and release. The packing tool supports the generation of application packages (HAP), application sets (APP) to launch to the application market, quick fix packages (HQF), quick fix packages (APPQF) to launch to the application market, static shared libraries (HAR), and dynamic shared libraries (HSP). The unpacking tool is used to unpack the HAP, APP, HQF, APPQF, HAR, and HSP files and parse the HAP, HSP, APP, and APPQF files. Generally, the packing process is automatically carried out in DevEco Studio. However, you can also use the JAR package of the packing tool to pack files. The JAR package is stored in the **toolchains** directory in the SDK path.

## Packing Commands

### Packing Commands for HAP Files

You can use the JAR package of the packing tool to generate an HAP file by importing packing options and file paths.

#### Example

- A packing command example in the stage model:


  ```
  java -jar app_packing_tool.jar --mode hap --json-path <option> --resources-path <option> --ets-path <option> --index-path <option> --pack-info-path <option> --out-path path\out\srcEntrance.hap --force true
  ```

- A packing command example in the FA model:


  ```
  java -jar app_packing_tool.jar --mode hap --json-path <option> --maple-so-path [option] --profile-path [option] --maple-so-dir [option] --dex-path [option] --lib-path [option] --resources-path [option] --index-path [option] --out-path <option> --force [option]
  ```

#### Parameters

| Name              | Mandatory| Option                  | Description                                                       | Remarks        |
|------------------|-------|----------------------|-----------------------------------------------------------|------------|
| --mode           | Yes    | hap                  | Packing mode.                                                    | NA         |
| --json-path      | Yes    | NA                   | Path of the JSON file. The file name must be **config.json** in the FA model and **module.json** in the stage model.| NA         |
| --profile-path   | No    | NA                   | Path of the **CAPABILITY.profile** file.                                  | NA         |
| --maple-so-path  | No    | NA                   | Path of the Maple SO file. The file name extension must be .so. If there are multiple SO files, separate them with commas (,).      | NA         |
| --maple-so-dir   | No    | NA                   | Path of the maple SO directory.                                          | NA         |
| --dex-path       | No    | NA                   | Path of the DEX file. The file name extension must be .dex. If there are multiple DEX files, separate them with commas (,).<br>The value can also be the directory (folder) where the DEX file is stored.| NA         |
| --lib-path       | No    | NA                   | Path of the library file.                                                | NA         |
| --resources-path | No    | NA                   | Path of the resource file.                                          | NA         |
| --index-path     | No    | NA                   | Path of the INDEX file. The file name must be **resources.index**.                        | NA         |
| --pack-info-path | No    | NA                   | Path of the **pack.info** file. The file name must be **pack.info**.                           | NA         |
| --rpcid-path     | No    | NA                   | Path of the **rpcid.sc** file. The file name must be **rpcid.sc**.                             | NA         |
| --js-path        | No    | NA                   | Path of the JS file.                                              | This parameter is valid only in the stage model.|
| --ets-path       | No    | NA                   | Path of the ETS file.                                             | This parameter is valid only in the stage model.|
| --out-path       | Yes    | NA                   | Path of the target file. The file name extension must be .hap.                                    | NA         |
| --force          | No    | true or false         | The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.                       | NA         |
| --an-path        | No    | NA                   | Path of the AN file.                                               | This parameter is valid only in the stage model.|
| --ap-path        | No    | NA                   | Path of the AP file.                                               | This parameter is valid only in the stage model.|
| --dir-list       | No    | NA                   | List of directories (folders) to be packed into the HAP file.                             | NA         |

### Packing Commands for HAR Files

You can use the JAR package of the packing tool to generate an HAR file by importing packing options and file paths.

#### Example

```
java -jar app_packing_tool.jar --mode har --json-path [option] --jar-path [option]--lib-path [option] --resources-path [option] --out-path [option] --force [option]
```

#### Parameters

| Name             | Mandatory| Option         | Description                                                       |
|-----------------|-------|-------------|-----------------------------------------------------------|
| --mode          | Yes    | har         | Packing mode.                                                    |
| --json-path     | Yes    | NA          | Path of the JSON file. The file name must be **config.json** in the FA model and **module.json** in the stage model.|
| --jar-path      | No    | NA          | Path of the JAR file. The file name extension must be .jar. If there are multiple JAR files, separate them with commas (,).<br>The value can also be the directory (folder) where the JAR file is stored.|
| --lib-path      | No    | NA          | Path of the library file.                                                |
| --resource-path | Yes    | NA          | Path of the resource file.                                          |
| --out-path      | Yes    | NA          | Path of the target file. The file name extension must be .har.                                    |
| --force         | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.                       |

### Packing Commands for APP Files

You can use the JAR package of the packing tool to generate an APP file by importing packing options and file paths. The APP file is used to release the application to the application market.  


#### Example

```
java -jar app_packing_tool.jar --mode app --hap-path <option> --hsp-path <option> --out-path [option] --signature-path [option] --certificate-path [option] --pack-info [option]--force [option]
```

#### Parameters

| Name                | Mandatory| Option         | Description                                                          |
|--------------------|-------|-------------|--------------------------------------------------------------|
| --mode             | Yes    | app         | Packing mode. Each HAP file to pack into the APP file must pass the validity check.                                          |
| --hap-path         | Yes    | NA          | Path of the HAP file. The file name extension must be .hap. If there are multiple HAP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HAP file is stored.|
| --hsp-path         | No    | NA          | Path of the HSP file. The file name extension must be .hsp. If there are multiple HSP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HSP file is stored.|
| --pack-info-path   | Yes    | NA          | Path of the **pack.info** file. The file name must be **pack.info**.                                            |
| --out-path         | No    | NA          | Path of the target file. The file name extension must be .app.                                       |
| --signature-path   | No    | NA          | Path of the signature file.                                                       |
| --certificate-path | No    | NA          | Path of the certificate file.                                                       |
| --force            | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.                          |

#### HAP Validity Check During APP Packing

When packing the HAP files in a project to generate an APP file, ensure that the values of **bundleName**, **versionCode**, **versionName**, **minCompatibleVersionCode**, **minAPIVersion**, **targetAPIVersion**, and **apiReleaseType** configured in each JSON file of the HAP are the same, and the value of **moduleName** is unique in all the JSON files. For the FA model, you must also ensure that the value of **package** is unique in all the JSON files.

### Multi-project Packing

If multiple teams develop the same application but it is inconvenient to share code, you can use multi-project packing, which packs the packed HAP, HSP, and APP files into a final APP file and releases it to the application market.

#### Example

```
java -jar app_packing_tool.jar --mode multiApp --hap-list 1.hap,2.hap --app-list 1.app,2.app --out-path final.app
```

#### Parameters

| Name        | Mandatory| Option       | Description                                                                                                 |
|------------|-------|-----------|-----------------------------------------------------------------------------------------------------|
| --mode     | Yes    | multiApp  | Packing mode. Each HAP file to pack into the APP file must pass the validity check.                                                           |
| --hap-list | No    | Path of the HAP files   | Path of the HAP files. The file name extension must be .hap. If there are multiple HAP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HAP file is stored.                                         |
| --hsp-list | No    | Path of the HSP files   | Path of the HSP files. The file name extension must be .hsp. If there are multiple HSP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HSP file is stored.                                         |
| --app-list | No    | Path of the APP files   | Path of the APP files. The file name extension must be .app. If there are multiple APP files, separate them with commas (,).<br>The value can also be the directory (folder) where the APP file is stored.<br>You must specify **--hap-list**, **--hsp-list**, or **--app-list**, or any of their combinations.|
| --force    | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.                                                                 |

#### HAP Validity Check During Multi-project Packing

Ensure that the values of **bundleName**, **versionCode**, **versionName**, **minCompatibleVersionCode**, **minAPIVersion**, **targetAPIVersion**, and **apiReleaseType** configured in each JSON file of the HAP are the same, the value of **moduleName** is unique in all the JSON files, and the value of **entry** is unique for the same device. For the FA model, you must also ensure that the value of **package** is unique in all the JSON files.

### Packing Commands for HQF Files

If you find detects in the application and want to rectify the defects quickly, you can use HQF files. You can use the JAR package of the packing tool to generate an HQF file by importing packing options and file paths.

#### Example

```
java -jar app_packing_tool.jar --mode hqf --json-path <option> ---lib-path <option> --ets-path <option> --out-path <option>
```

#### Parameters

| Name         | Mandatory| Option         | Description                                |
|-------------|-------|-------------|------------------------------------|
| --mode      | Yes    | hqf         | Packing mode.                             |
| --json-path | Yes    | NA          | Path of the JSON file. The file name must be **patch.json**.       |
| --lib-path  | No    | NA          | Path of the library file.                        |
| --ets-path  | No    | NA          | Path of the ETS file.                      |
| --out-path  | Yes    | NA          | Path of the target file. The file name extension must be .hqf.             |
| --force     | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.|

### Packing Commands for APPQF Files

An APPQF file consists of one or more HQF files. These HQF files are split from an APPQF file in the application market and then distributed to specific devices. You can use the JAR package of the packing tool to generate an APPQF file by importing packing options and file paths.

#### Example

```
java -jar app_packing_tool.jar --mode appqf --hqf-list <option> --out-path <option>
```

#### Parameters

| Name        | Mandatory| Option         | Description                                |
|------------|-------|-------------|------------------------------------|
| --mode     | Yes    | appqf       | Packing mode.                             |
| --hqf-list | Yes    | NA          | Path of the HQF files. If there are multiple HQF files, separate them with commas (,).             |
| --out-path | Yes    | NA          | Path of the target file. The file name extension must be .appqf.           |
| --force    | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.|


### Packing Commands for HSP Files

HSP files enable multiple HAPs to share files. You can use the JAR package of the packing tool to generate an HSP file by importing packing options and file paths.

#### Example
```
java -jar path\app_packing_tool.jar --mode hsp --json-path <option> --resources-path <option> --ets-path <option> --index-path <option> --pack-info-path <option> --out-path path\out\library.hsp --force true
```

#### Parameters

| Name              | Mandatory| Option         | Description                                                       |
|------------------|-------|-------------|-----------------------------------------------------------|
| --mode           | Yes    | hsp         | Packing mode.                                                    |
| --json-path      | Yes    | NA          | Path of the JSON file. The file name must be **module.json**.                             |
| --profile-path   | No    | NA          | Path of the **CAPABILITY.profile** file.                                  |
| --dex-path       | No    | NA          | Path of the DEX file. The file name extension must be .dex. If there are multiple DEX files, separate them with commas (,).<br>The value can also be the directory (folder) where the DEX file is stored.|
| --lib-path       | No    | NA          | Path of the library file.                                                |
| --resources-path | No    | NA          | Path of the resource file.                                          |
| --index-path     | No    | NA          | Path of the INDEX file. The file name must be **resources.index**.                        |
| --pack-info-path | No    | NA          | Path of the **pack.info** file. The file name must be **pack.info**.                           |
| --js-path        | No    | NA          | Path of the JS file.                                              |
| --ets-path       | No    | NA          | Path of the ETS file.                                             |
| --out-path       | Yes    | NA          | Path of the target file. The file name extension must be .hsp.                                    |
| --force          | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.                       |

## Unpacking Commands

### Unpacking Commands for HAP Files

You can use the JAR package of the unpacking tool to unpack an HAP file by importing unpacking options and file paths.

#### Example

```
java -jar app_unpacking_tool.jar --mode <option> --hap-path <options> --out-path [option] --force [option]
```

#### Parameters

| Name      | Mandatory| Option         | Description                                                        |
| ---------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode     | Yes        | hap           | Unpacking mode.                                                  |
| --hap-path | Yes        | NA            | Path of the HAP file.                                                 |
| --rpcid    | No        | true or false| Whether to extract the rpcid file from the HAP file to a specified directory. If the value is **true**, only the rpcid file is extracted and the HAP file is not unpacked.|
| --out-path | Yes        | NA            | Path of the target files.                                          |
| --force    | No        | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking. |

### Unpacking Commands for HAR Files

You can use the JAR package of the unpacking tool to unpack an HAR file by importing unpacking options and file paths.

#### Example

```
java -jar app_unpacking_tool.jar --mode <options> --har-path <option> --out-path [option] --force [option]
```

#### Parameters

| Name      | Mandatory| Option         | Description                                                       |
| ---------- | ---------- |-------------| ----------------------------------------------------------- |
| --mode     | Yes        | har         | Unpacking mode.                                                 |
| --har-path | Yes        | NA          | Path of the HAR file.                                                |
| --out-path | Yes        | NA          | Path of the target files.                                         |
| --force    | No        | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking.|

### Unpacking Commands for APP Files

You can use the JAR package of the unpacking tool to unpack an APP file by importing unpacking options and file paths.

#### Example

```
java -jar app_unpacking_tool.jar --mode <options> --app-path <option> --out-path [option] --force [option]
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
java -jar app_unpacking_tool.jar --mode hap --rpcid true --hap-path <option> --out-path <option> --force true
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
java -jar app_unpacking_tool.jar --mode <option> --hsp-path <options> --out-path [option] --force [option]
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
java -jar app_unpacking_tool.jar --mode <option> --appqf-path <options> --out-path [option] --force [option]
```

#### Parameters

| Name          | Mandatory| Option         | Description                                |
|--------------| ---------- |-------------|------------------------------------|
| --mode       | Yes        | appqf       | Unpacking mode.                             |
| --appqf-path | Yes        | NA          | Path of the APPQF file.                         |
| --out-path   | Yes        | NA          | Path of the target files.                         |
| --force      | No        | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during unpacking.|

## Package Parsing APIs

The package parsing APIs are used to parse an HAP file and obtain information such as the configuration file.

### Available APIs

| Class              | Prototype                                                    | Type    | Description                                                           |
| ------------------ | ------------------------------------------------------------ | -------- |-------------------------------------------------------------------|
| UncompressEntrance | UncomperssResult parseApp(String appPath,String parseMode,String deviceType,String hapName) | Java| Function: Parses **pack.info** in the APP file.<br>Input parameters: **appPath**, which specifies the path of the APP file.<br>Return value: **UncomperssResult**.|
| UncompressEntrance | UncomperssResult parseApp(InputStream input,String parseMode,String deviceType,String hapName,String outPath) | Java| Function: Parses **pack.info** in the APP file.<br>Input parameters: **input**, which specifies the stream of the APP file.<br>Return value: **UncomperssResult**.|
| UncompressEntrance | UncomperssResult parseHap(String hapPath)                    | Java| Function: Parses the JSON file in the APP file.<br>Input parameters: **hapPath**, which specifies the path of the HAP file.<br>Return value: **UncomperssResult**.   |
| UncompressEntrance | UncomperssResult parseHap(InputStream input)                 | Java| Function: Parses the JSON file in the APP file.<br>Input parameters: **input**, which specifies the stream of the HAP file.<br>Return value: **UncomperssResult**.  |

## Fields of the Unpacking Tool

### UncomperssResult (Bundle Information) Struct

| Field        | Type              | Description                                    | Remarks|
| ------------ | ------------------ |----------------------------------------| ---- |
| result       | boolean            | Whether the parsing is successful.                            | NA   |
| message      | String             | Failure cause returned if the parsing fails.                           | NA   |
| packInfos    | List\<PackInfo>    | Information about **packages** in the **pack.info** file of the bundle.         | NA   |
| profileInfos | List\<profileInfo> | Configuration information of the application.                               | NA   |
| icon         | String             | Path of the icon of the entry component. If there is no entry component, the icon path of the first component is returned.| NA   |
| label        | String             | Label of the entry component. If there is no entry component, the label of the first component is returned.| NA   |

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

| Field                            | Type     | Description                                                                         | Remarks       |
|--------------------------------|---------|-----------------------------------------------------------------------------|-----------|
| bundleName                     | String  | Bundle name of the application.                                                                  | NA        |
| bundleType                     | String  | Bundle type.<br>- **app**: The bundle is used for a common application.<br>- **atomicService**: The bundle is used for an atomic service.<br>- **shared**: The bundle is used for a shared library.| NA        |
| vendor                         | String  | Vendor of the application.                                                                | NA        |
| releatedBundleName             | String  | Related bundle name of the application.                                                           | NA        |
| versionName                    | String  | Version name of the application.                                                       | NA        |
| versionCode                    | String  | Version code of the application.                                                       | NA        |
| targetApiVersion               | int     | Target API version required for running the application.                                                           | NA        |
| compatibleApiVersion           | int     | API version compatible with the application.                                                               | NA        |
| appName                        | String  | Label of the ability displayed on the home screen.                                                     | NA        |
| releaseType                    | String  | Release type of the target API version required for running the application.                                                        | NA        |
| shellVersionCode               | String  | API version in HarmonyOS.                                                         | NA        |
| shellVersionName               | String  | API version name in HarmonyOS.                                                       | NA        |
| multiFrameworkBundle           | String  | Bundle name of the application in the dual-framework scenario.                                                       | NA        |
| debug                          | boolean | Whether the application can be debugged.                                                                  | NA        |
| icon                           | String  | Path of the application icon.                                                                  | NA        |
| label                          | String  | Label of the application.                                                                 | NA        |
| description                    | String  | Description of the application.                                                                  | This field is newly added to the stage model.|
| minCompatibleVersionCode       | int     | Earliest compatible version of the application.                                                             | NA        |
| distributedNotificationEnabled | boolean | Whether the distributed notification feature is enabled for the application.                                                             | This field is newly added to the stage model.|
| jointUserid                    | String  | Shared user ID.                                                           | This field is unique to the FA model.   |
| process                        | String  | Process name of the application.                                                                   | This field is unique to the FA model.   |
| directLaunch                   | String  | Whether the application can be started when the screen is locked.                                                          | NA        |
| distributedNotificationEnabled | boolean | Whether the distributed notification feature is enabled for the application.                                                             | This field is unique to the stage model.|

### HapInfo Struct

| Field              | Type                                            | Description                            | Remarks                                                   |
| ------------------ |------------------------------------------------|--------------------------------| ------------------------------------------------------- |
| packageStr         | String                                         | Package information about the application.                      | This field is unique to the FA model.                                             |
| name               | String                                         | Name of the module.                 | NA                                                      |
| description        | String                                         | Description of the HAP file.                   | This field is unique to the FA model.                                             |
| supporteModes      | List\<String>                                  | Mode supported by the HAP file.                  | NA                                                      |
| abilities          | Array of AbilityInfo                                | Ability information of the HAP file.               | NA                                                      |
| distro             | Distro Struct                                     | Distro description of the HAP file.               | NA                                                      |
| deviceType         | List\<String>                                  | Type of devices on which the HAP can run.               | This field corresponds to **deviceTypes** in the stage model.                           |
| metadata           | metaData struct (see **metaData Struct** below)                      | Custom metadata of the HAP.                  | NA                                                      |
| isJs               | boolean                                        | Whether the application is a JS application.                  | This field is unique to the FA model.                                             |
| reqPermissions     | ReqPermission struct array (see **ReqPermission** below)          | Permissions requested by the application.                  | This field corresponds to **requestPermissions** in the stage model.                      |
| commonEvents       | CommonEvent struct (see **CommonEvent Struct** below)               | Static event.                        | NA                                                      |
| shortcuts          | Shortcut struct array (see **Shortcut** below)                    | Shortcuts information of the application.              | NA                                                      |
| distrofilter       | DistroFilter struct                               | Information distributed by the application market by device form.              | NA                                                      |
| srcEntrance        | String                                         | Entry code path of the application.                 | This field is newly added to the stage model.                                          |
| process            | String                                         | Process name of the HAP.                     | This field is newly added to the stage model.                                          |
| mainElement        | String                                         | Entry ability name or ExtensionAbility name of the HAP file.| This field is newly added to the stage model. In the FA model , the value of **mainAbility** is automatically assigned to **mainElement**.|
| unSyntax           | String                                         | Syntax type of a JS component.          | This field is newly added to the stage model.                                          |
| pages              | List\<String>                                  | Information about each page in a JS component.         | This field is newly added to the stage model.                                          |
| extensionAbilities | List\<ExtensionAbilityInfo>                    | ExtensionAbility information.       | This field is newly added to the stage model.                                          |
| abilityFormInfos   | List\<AbilityFormInfo>                         | Widget information.                       | NA                                                      |
| moduleAtomicService| ModuleAtomicService struct (see **ModuleAtomicService Struct** below)| Atomic service information of the HAP.                  | NA                                                     |

### AbilityInfo Struct

| Field               | Type                      | Description                                             | Remarks                           |
|-------------------|--------------------------| ------------------------------------------------- | ------------------------------- |
| name              | String                   | Logical name of the ability.                          | NA                              |
| description       | String                   | Description of the ability.                                | NA                              |
| icon              | String                   | Icon of the ability.                                  | NA                              |
| label             | String                   | Ability name visible to users.                      | NA                              |
| type              | String                   | Ability type.                                  | In the stage model, the value is directly assigned to the **page** field.|
| uri               | String                   | URI of the ability.                             | This field is supported only in the FA model.                     |
| launchType        | String                   | Launcher type of the ability.                  | NA                              |

### Distro Struct

| Field               | Type     | Description                                                        | Remarks                                                        |
| ------------------- |---------| ------------------------------------------------------------ | ------------------------------------------------------------ |
| moduleName          | String  | Name of the module.                                        | This field corresponds to the **moduleName** field under the **module** struct in the stage model.               |
| moduleType          | String  | Type of the module.                                           | This field corresponds to the **moduleType** field under the **module** struct in the stage model.               |
| deliveryWithInstall | boolean | Whether the HAP is installed when the user installs the application.                     | This field corresponds to the **deliveryWithInstall** field under the **module** struct in the stage model.      |
| installationFree    | int     | Whether the HAP supports the installation-free feature.                               | This parameter corresponds to the **installationFree** field under the **module** struct in the stage model. In the JSON file, if this parameter is set to **true**, **1** is returned; if this parameter is set to **false**, **0** is returned; if this parameter is not set, **2** is returned.|
| virtualMachine      | String  | Type of the target virtual machine (VM) where the HAP is running. It is used for cloud distribution, such as the application market and distribution center.| This field corresponds to the **virtualMachine** field under the **module** struct in the stage model.           |

### Metadata Struct

| Field          | Type                 | Description                            | Remarks                     |
| -------------- |---------------------| -------------------------------- | ------------------------- |
| parameters     | List\<MetadataInfo> | Metadata information.          | This field is unique to the FA model. It is deprecated in the stage model.|
| results        | List\<MetadataInfo> | Result information of the metadata.       | This field is unique to the FA model. It is deprecated in the stage model.|
| customizeDatas | List\<CustomizeData> | Custom data of the metadata.| NA                        |

### MetadataInfo Struct

| Field       | Type  | Description                             | Remarks                     |
| ----------- | ------ | --------------------------------- | ------------------------- |
| name        | String | Name of the **MetadataInfo** struct.       | This field is unique to the FA model. It is deprecated in the stage model.|
| description | String | Description of the **MetadataInfo** struct.| This field is unique to the FA model. It is deprecated in the stage model.|
| type        | String | Type of the **MetadataInfo** struct.       | This field is unique to the FA model. It is deprecated in the stage model.|

### CustomizeData Struct

| Field | Type  | Description                        | Remarks                   |
| ----- | ------ | ---------------------------- | ----------------------- |
| name  | String | Name of the **CustomizeData** struct. | This field corresponds to **metadata** in the stage model.|
| value | String | Value of the **CustomizeData** struct.| This field corresponds to **metadata** in the stage model.|
| extra | String | Extra information of the **CustomizeData** struct.| This field corresponds to **metadata** in the stage model.|

### ReqPermission Struct

| Field     | Type                              | Description                                                | Remarks|
| --------- | ---------------------------------- |----------------------------------------------------| ---- |
| name      | String                             | Name of the **ReqPermission** struct.                              | NA   |
| reason    | String                             | Reason for requesting the permission. This field is mandatory for a user_grant permission.               | NA   |
| usedScene | UsedScene struct (see **UsedScene Struct** below)| Application scenario of the permission. The value can be **ability** or **when**. Multiple abilities can be configured.| NA   |

### UsedScene Struct

| Field   | Type         | Description                                                        | Remarks|
| ------- | ------------- | ------------------------------------------------------------ | ---- |
| ability | List\<String> | Abilities that use the permission. The value is an array. | NA   |
| when    | String        | Time when the permission is used. The value can be **inuse** (the permission can be used only in the foreground) or **always** (the permission can be used in foreground and background).| NA   |

### ShortCut Struct

| Field      | Type                  | Description                                                        | Remarks|
| ---------- | ---------------------- | :----------------------------------------------------------- | ---- |
| shortcutId | String                 | ID of the **ShortCut** struct.                                            | NA   |
| label      | String                 | Label of the **ShortCut** struct.                                      | NA   |
| icon       | String                 | Icon of the **ShortCut** struct.                                      | NA   |
| intents    | List of IntentInfo structs| Intents to which the shortcut points. The attribute consists of the **targetClass** and **targetBundle** sub-attributes.| NA   |

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

| Field           | Type             | Description                                                        | Remarks                                                        |
| --------------- | ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| name            | String            | Logical name of the ExtensionAbility.                            | This field is supported only in the stage model.                                               |
| srcEntrance     | String            | JS code path of the ExtensionAbility.                      | This field is supported only in the stage model.                                               |
| icon            | String            | Icon ID of the ExtensionAbility.                                | This field is supported only in the stage model.                                               |
| label           | String            | ExtensionAbility name visible to users.                        | This field is supported only in the stage model.                                               |
| description     | String            | Description of the ExtensionAbility.                                  | This field is supported only in the stage model.                                               |
| type            | String            | Type of the ExtensionAbility, which can be **form**, **workScheduler**, **inputMethod**, **service**, **accessibility**, **dataShare**, **fileShare**, **wallpaper**, or **backup**.| This field is supported only in the stage model. Currently, only **form** and **staticSubscriber** information is parsed. The information of other types is not parsed.|
| permissions     | List\<String>     | Permissions required when the ExtensionAbility is called by the ability of another application.           | This field is supported only in the stage model.                                               |
| readPermission  | String            | Permission required for reading data in the ExtensionAbility.                             | This field is supported only in the stage model.                                               |
| writePermission | String            | Permission required for writing data to the ExtensionAbility.                               | This field is supported only in the stage model.                                               |
| visible         | boolean           | Whether the ExtensionAbility can be called by other applications.                  | This field is supported only in the stage model.                                               |
| skills          | SkillInfo array    | Skills of the Want that the extensionAbility can receive.                  | This field is supported only in the stage model.                                               |
| metadata        | CustomizeData information| Metadata of the ExtensionAbility.                                | The information in **metadata** is assigned to **CustomizeData**.                     |
| uri             | String            | URI of the data provided by the ExtensionAbility.                           | This field is supported only in the stage model.                                               |

### SkillInfo Struct

| Field    | Type               | Description                  | Remarks|
| -------- | ------------------- |----------------------| ---- |
| actions  | List\<String>       | Actions of the Want that the ExtensionAbility can receive.| NA   |
| entities | List\<String>       | Entities of the Want that the ExtensionAbility can receive.  | NA   |
| uriInfos | List\<String> | URIs of the Want.          | NA   |

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

| Field               | Type         | Description                                                        | Remarks       |
| ------------------- | ------------- | ------------------------------------------------------------ |-----------|
| name                | String        | Name of the widget.                                             | NA        |
| description         | String        | Description of the widget.                                             | This field is newly added to the stage model.|
| type                | String        | Type of the widget.                                          | NA        |
| src                 | String        | JS code of the widget.                                      | NA        |
| isDefault           | boolean       | Whether the widget is a default one. Each HAP has only one default widget.     | NA        |
| colorMode           | String        | Color mode of the widget, which can be **auto**, **dark**, or **light**.             | NA        |
| updateEnabled       | boolean       | Whether the widget supports scheduled refresh.                                  | NA        |
| scheduledUpdateTime | String        | Scheduled time to update the widget. The value is in 24-hour format and accurate to the minute.      | NA        |
| updateDuration      | int           | Interval to update the widget. The unit is 30 minutes. The value is a multiple of 30.  | NA        |
| supportDimensions   | List\<String> | Dimensions supported by the widget, which can be **1 * 2**, **2 * 2**, **2 * 4**, or **4 * 4**.  | NA        |
| defaultDimension    | String        | Default dimensions of the widget. The value must be available in the **supportDimensions** array of the widget.| NA        |
| formConfigAbility   | String        | Ability name for widget adjustment.                                   | NA        |
| formVisibleNotify   | String        | Whether the widget is allowed to use the visibility notification.                        | NA        |
| MetaData            | MetaData      | Custom data of the widget.                                        | NA        |
| providerAbility     | String        | Ability or ExtensionAbility name of the widget.<br>1. FA model: If the widget is configured in an ability of the Service type, set **providerAbility** to **mainAbility**.<br>2. FA model: If the widget is configured in an ability of the Page type, set **providerAbility** to the current ability.<br>3. FA model: If **mainAbility** is not configured, set **providerAbility** to the ability that preferentially uses **system.home** in the current HAP. Otherwise, set **providerAbility** to the ability of the first page.<br>4. Stage model: Set **providerAbility** to **mainElement**.| NA        |

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

| Field          | Type                                    | Description            | Remarks|
|--------------|----------------------------------------|----------------| ---- |
| preloadItems | PreloadItem object array| Preloaded objects.         | NA   |

### PreloadItem Struct

| Field          | Type | Description     | Remarks|
|--------------|-----|---------| ---- |
| moduleName | String| Name of the preloaded module.| NA   |
