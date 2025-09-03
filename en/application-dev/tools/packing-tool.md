# Packing Tool
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @jsjzju-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @Brilliantry_Rui-->

The packing tool packs compiled files for installation and release. You can use DevEco Studio or the JAR package of the packaging tool to pack files. The JAR package is usually stored in the **toolchains** directory of the SDK.

The packing tool supports the generation of HAP (module package of the ability type), HSP (dynamically shared package), APP (application program package), HQF (quick fix module package), and APPQF (quick fix package) files.

The file in the packaging command comes from the [DevEco Studio compilation and building products](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-compile-build). To view the file path, perform the following steps:<br>
1. In the /hvigor/hvigor-config.json5 file in the root directory of the DevEco Studio project, change the value of level under logging to debug.<br>
2. On the DevEco Studio menu bar, choose Build > Clean Up Projects.<br>
3. On the DevEco Studio menu bar, choose Build > Build App (s).<br>
4. In the Build window at the bottom of DevEco Studio, search for app_packing_tool.jar and check the file path in the packaging parameters.<br>

The packaging tool verifies the validity of the attributes of the module.json file. The module.json file is a compilation and building product. Its attribute values are automatically generated during compilation and building. The mapping between the attribute values and configuration items in the configuration file is as follows:

**Table 1** Mapping between module.json and configuration file attributes

| Attributes of module.json         | [module.json5](../quick-start/module-configuration-file.md)        | [app.json5](../quick-start/app-configuration-file.md)           | [Project-level build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile-app) Configuration Item |
| ------------------------ | ------------------------ | -------------------------- | --------------------------       |
| bundleName               | -                        | bundleName                 | -                                |
| bundleType               | -                        | bundleType                 | -                                |
| versionCode              | -                        | versionCode                | -                                |
| debug                    | -                        | debug                      | -                                |
| module/name              | module/name              | -                          | -                                |
| minCompatibleVersionCode | -                        | minCompatibleVersionCode   | -                                |
| minAPIVersion            | -                        | minAPIVersion              | compatibleSdkVersion             |
| targetAPIVersion         | -                        | targetAPIVersion           | targetSdkVersion/compileSdkVersion  <br>Note: If targetSdkVersion exists, targetAPIVersion is determined by targetSdkVersion.<br>Otherwise, targetAPIVersion is determined by compileSdkVersion.              |
| querySchemes             | querySchemes              | -                          | -                                |

## Constraints

- The packing tool must run in Java 8 or later.
- The parameters and parameter values in the packing command must appear in pairs. For example, in the HAP packing command --resources-path \<path>, --resources-path indicates the command parameter, and path indicates the parameter value. The two parameters must be used at the same time.

## HAP Packing Command

You can use the JAR package of the packing tool to generate an HAP file for a module by passing in packing options and file paths.

**Verify the validity of HAP during packaging.**
- Since API version 21, if more than 50 URL schemes are configured for querySchemes in the module.json file when the HAP of the entry type is packaged, the value of minAPIVersion must be greater than or equal to 21.

**The compression rules for HAP packaging are as follows:**
- If compressNativeLibs is set to true, files in the directory specified by --lib-path are compressed based on the compression level specified by --compress-level.
- To ensure running performance, files that are not in the directory specified by --lib-path are not compressed.

Packing command example:
- [Stage model](../../application-dev/application-models/application-models.md) Example:


    ```
    java -jar app_packing_tool.jar --mode hap --json-path <path> [--resources-path <path>] [--ets-path <path>] [--index-path <path>] [--pack-info-path <path>] [--lib-path <path>] --out-path <path> [--force true] [--compress-level 5] [--pkg-context-path <path>] [--hnp-path <path>]
    ```

- [FA model](../../application-dev/application-models/application-models.md) Example:


    ```
    java -jar app_packing_tool.jar --mode hap --json-path <path> [--maple-so-path <path>] [--profile-path <path>] [--maple-so-dir <path>] [--dex-path <path>] [--lib-path <path>] [--resources-path <path>] [--index-path <path>] --out-path <path> [--force true] [--compress-level 5]
    ```

**Table 1** Parameters of the HAP packing command

| Name            | Mandatory| Option         | Description                                                        | Remarks           |
| ---------------- | ---------- | ------------- | ------------------------------------------------------------ | --------------- |
| --mode           | Yes        | hap           | Packing mode.                                                  | NA              |
| --json-path      | Yes        | NA            | Path of the .json file. The FA model file name must be config.json, and the stage model file name must be module.json.| NA              |
| --profile-path   | No        | NA            | Path of the **CAPABILITY.profile** file.                                | NA              |
| --maple-so-path  | No        | NA            | Path of the Maple SO file. The file name extension must be .so. If there are multiple SO files, separate them with commas (,).| NA              |
| --maple-so-dir   | No        | NA            | Path of the maple SO directory (folder).                                      | NA              |
| --dex-path       | No        | NA            | Path of the DEX file. The file name extension must be .dex. If there are multiple DEX files, separate them with commas (,).<br>The value can also be the directory (folder) where the DEX file is stored.| NA              |
| --lib-path       | No        | NA            | Path of the library file.                                             | NA              |
| --resources-path | No        | NA            | Path of the resources file.                                       | NA              |
| --index-path     | No        | NA            | Path of the INDEX file. The file name must be **resources.index**.               | NA              |
| --pack-info-path | No        | NA            | Path of the **pack.info** file. The file name must be **pack.info**.                  | NA              |
| --rpcid-path     | No        | NA            | Path of the **rpcid.sc** file. The file name must be **rpcid.sc**.                    | NA              |
| --js-path        | No        | NA            | Path of the JS file.                                        | This parameter takes effect only for the stage model.|
| --ets-path       | No        | NA            | Path of the ETS file.                                       | This parameter takes effect only for the stage model.|
| --out-path       | Yes        | NA            | Path of the target file. The file name extension must be .hap.                      | NA              |
| --force          | No        | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists. | NA              |
| --an-path        | No        | NA            | Path for storing the [an file](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs-V5/faqs-arkts-52-V5).| This attribute takes effect only for the stage model.|
| --ap-path        | No        | NA            | Path for storing the [ap file](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs-V5/faqs-arkts-52-V5).| This attribute takes effect only for the stage model.|
| --dir-list       | No        | NA            | List of directories (folders) to be packed into the HAP file.                     | NA              |
| --compress-level | No        | number        | Compression level of files in the library. The default value is 1. The value ranges from 1 to 9. This parameter is valid only when **compressNativeLibs** is set to **true**. A larger value indicates a higher compression rate and a slower compression speed.| NA  |
| --pkg-context-path      | No        | NA            | Path of the **pkgContextInfo.json** file, which contains the context information.| This parameter takes effect only for the stage model.             |
| --hnp-path | No| NA | Path of the native software package to be packed into the HAP file.| NA |

## HSP Packing Command

HSP files enable file sharing among multiple HAPs. You can use the JAR package of the packing tool to generate an HSP file for an application by passing in packing options and file paths.

**The compression rules for HSP packaging are as follows:**
- If compressNativeLibs is set to true, files in the directory specified by --lib-path are compressed based on the compression level specified by --compress-level.
- To ensure running performance, files that are not in the directory specified by --lib-path are not compressed.

Packing command example:
```
java -jar app_packing_tool.jar --mode hsp --json-path <path> [--resources-path <path>] [--ets-path <path>] [--index-path <path>] [--pack-info-path <path>] [--lib-path <path>] --out-path <path> [--force true] [--compress-level 5] [--pkg-context-path <path>]
```

**Table 3** Parameters of the HSP packing command

| Name            | Mandatory| Option         | Description                                                        |
| ---------------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode           | Yes        | hsp           | Packing mode.                                                  |
| --json-path      | Yes        | NA            | Path of the JSON file. The file name must be **module.json**.                    |
| --profile-path   | No        | NA            | Path of the **CAPABILITY.profile** file.                                |
| --dex-path       | No        | NA            | 1. Path of the DEX file. The file name extension must be .dex. If there are multiple DEX files, separate them with commas (,).<br>2. The value can also be the directory (folder) where the DEX file is stored.|
| --lib-path       | No        | NA            | Path of the library file.                                             |
| --resources-path | No        | NA            | Path of the resources file.                                       |
| --index-path     | No        | NA            | Path of the INDEX file. The file name must be **resources.index**.               |
| --pack-info-path | No        | NA            | Path of the **pack.info** file. The file name must be **pack.info**.                  |
| --js-path        | No        | NA            | Path of the JS file.                                        |
| --ets-path       | No        | NA            | Path of the ETS file.                                       |
| --out-path       | Yes        | NA            | Path of the target file. The file name extension must be .hsp.                      |
| --force          | No        | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists. |
| --compress-level | No        | number        | Compression level of files in the library. The value ranges from 1 to 9. The default value is 1. This parameter is valid only when **compressNativeLibs** is set to **true**. A larger value indicates a higher compression rate and a slower compression speed.|
| --pkg-context-path      | No        | NA            | Path of the **pkgContextInfo.json** file, which contains the context information.|

## APP Packing Command

You can use the JAR package of the packing tool to generate an APP file for an application by passing in packing options and file paths. The APP file is used to release the application to the application market.

**Table 4** App packaging validity verification rules

| Verified field in the module.json file of the HAP/HSP. | Verification Rules                          |
| --------------------------------- | --------------------------------- |
| name field under module               | The name field values of all HAPs/HSPs must be different.     |
| bundleName                       | The bundleName field values of all HAPs/HSPs must be the same. |
| bundleType                       | The bundleType field values of all HAPs/HSPs must be the same. |
| versionCode                      | The version codes of all HAPs/HSPs must be the same.|
| debug                            | Since API version 20, the debug field values of all HAPs must be the same. If the debug field value of HAP is false, the debug field value of HSP must also be false. If the value of debug in HAP is true, there is no requirement on the value of debug in HSP.<br>For API version 19 and earlier versions, the debug field values of all HAPs/HSPs must be the same.   |
| minAPIVersion                    | From API version 20, the values of minAPIVersion of all HAPs must be the same and must be greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 19 and earlier versions, the values of the minAPIVersion field of all HAPs/HSPs must be the same.   |
| minCompatibleVersionCode         | From API version 16, the values of minCompatibleVersionCode of all HAPs must be the same and greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 15 and earlier versions, the values of minCompatibleVersionCode of all HAPs/HSPs must be the same.   |
| targetAPIVersion                 | From API version 16, the targetAPIVersion values of all HAPs must be the same and must be greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 15 and earlier versions, the values of the targetAPIVersion field of all HAPs/HSPs must be the same.   |
| versionName                | Since API version 12, versionName is not verified.     |

> **NOTE**
>
> - The module.json file is the compilation and building product of DevEco Studio. For details about the mapping between fields and configuration files, see [Table 1 Mapping between module.json and configuration file attributes](packing-tool.md).

**Compression rules**: When packaging the APP files, the HAP and HSP files in release mode are compressed, but the HAP and HSP files in debug mode are not compressed.

> **NOTE**
> 
> If the .so file has been compressed in the HAP/HSP and is compressed again during app packaging, the size of the .so file will not be significantly reduced.

Packing command example:

```
java -jar app_packing_tool.jar --mode app [--hap-path <path>] [--hsp-path <path>] --out-path <path> [--signature-path <path>] [--certificate-path <path>] --pack-info-path <path> [--pack-res-path <path>] [--force true] [--encrypt-path <path>] [--pac-json-path <path>] [--atomic-service-entry-size-limit <size>] [--atomic-service-non-entry-size-limit <size>]
```

**Table 3** Parameters of the APP packing command

| Name                | Mandatory| Option         | Description                                                          |
|--------------------|-------|-------------|--------------------------------------------------------------|
| --mode             | Yes    | app         | Packing mode. Each HAP file to pack into the APP file must pass the validity check.                                          |
| --hap-path         | No    | NA          | Path of the HAP files. The file name extension must be .hap. If there are multiple HAP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HAP files are stored.|
| --hsp-path         | No    | NA          | Path of the HSP files. The file name extension must be .hsp. If there are multiple HSP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HSP files are stored.|
| --pack-info-path   | Yes    | NA          | Path of the **pack.info** file. The file name must be **pack.info**.                                            |
| --out-path         | Yes    | NA          | Path of the target file. The file name extension must be .app.                                       |
| --signature-path   | No    | NA          | Path of the signature file.                                                       |
| --certificate-path | No    | NA          | Path of the certificate file.                                                       |
| --pack-res-path    | No    | NA          | Path of the **pack.res** file.                                |
| --force            | No    | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.                          |
| --encrypt-path     | No    | NA          | The file name must be **encrypt.json**.                          |
| --pac-json-path     | No    | NA          | Path of the pac.json file. The file name must be pac.json.<br>This parameter is supported since API version 20.|
| --atomic-service-entry-size-limit      | No        | NA            | Maximum size of the entry package (including the size of the dependency package) of an FA. This parameter is valid only when the stage model is used and bundleType is set to atomicService. The value is an integer of [0,4194304]. The value 0 indicates that the size is not limited. The unit is KB. If this parameter is not set, the default value 2048 KB is used.                      |
| --atomic-service-non-entry-size-limit  | No        | NA            | Maximum size of a non-entry package (including the size of its dependency package) of an FA. This parameter is valid only when the stage model is used and bundleType is set to atomicService. The value is an integer of [0,4194304]. The value 0 indicates that the size is not limited. The unit is KB. If this parameter is not set, the default value 2048 KB is used.                    |



## Multi-project Packing Command

If multiple teams develop the same application but it is inconvenient to share code, you can use multi-project packing, which packs the packed HAP, HSP, and APP files into a final APP file and releases it to the application market.

**Table 6** Validity verification rules for multi-project packaging

| Verified field in the module.json file of the HAP/HSP. | Verification Rules                          |
| --------------------------------- | --------------------------------- |
| name field under module               | The name field values of all HAPs/HSPs must be different.     |
| bundleName                       | The bundleName field values of all HAPs/HSPs must be the same. |
| bundleType                       | The bundleType field values of all HAPs/HSPs must be the same. |
| versionCode                      | The version codes of all HAPs/HSPs must be the same.|
| debug                            | Since API version 20, the debug field values of all HAPs must be the same. If the debug field value of HAP is false, the debug field value of HSP must also be false. If the value of debug in HAP is true, there is no requirement on the value of debug in HSP.<br>For API version 19 and earlier versions, the debug field values of all HAPs/HSPs must be the same.   |
| minAPIVersion                    | From API version 20, the values of minAPIVersion of all HAPs must be the same and must be greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 19 and earlier versions, the values of the minAPIVersion field of all HAPs/HSPs must be the same.   |
| minCompatibleVersionCode         | From API version 16, the values of minCompatibleVersionCode of all HAPs must be the same and greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 15 and earlier versions, the values of minCompatibleVersionCode of all HAPs/HSPs must be the same.   |
| targetAPIVersion                 | From API version 16, the targetAPIVersion values of all HAPs must be the same and must be greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 15 and earlier versions, the values of the targetAPIVersion field of all HAPs/HSPs must be the same.   |
| versionName                | Since API version 12, versionName is not verified.     |

> **NOTE**
>
> - The module.json file is the compilation and building product of DevEco Studio. For details about the mapping between fields and configuration files, see [Table 1 Mapping between module.json and configuration file attributes](packing-tool.md).

Packing command example:

```
java -jar app_packing_tool.jar --mode multiApp [--hap-list <path>] [--hsp-list <path>] [--app-list <path>] --out-path <option> [--force true] [--encrypt-path <path>] [--pac-json-path <path>] [--atomic-service-entry-size-limit <size>] [--atomic-service-non-entry-size-limit <size>]
```

**Table 4** Parameters of the multi-project packing command

| Name        | Mandatory| Option       | Description                                                       |
|------------|-------|-----------|----------------------------------------------------------------|
| --mode     | Yes    | multiApp  | Packing mode. Each HAP file to pack into the APP file must pass the validity check.                                                           |
| --hap-list | No    | Path of the HAP files   | Path of the HAP files. The file name extension must be .hap. If there are multiple HAP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HAP files are stored.                                         |
| --hsp-list | No    | Path of the HSP files   | Path of the HSP files. The file name extension must be .hsp. If there are multiple HSP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HSP files are stored.                                         |
| --app-list | No    | Path of the APP files   | Path of the APP files. The file name extension must be .app. If there are multiple APP files, separate them with commas (,).<br>The value can also be the directory (folder) where the APP files are stored.<br>You must specify **--hap-list**, **--hsp-list**, or **--app-list**, or any of their combinations.|
| --out-path | Yes    | NA | Path of the target file. The file name extension must be .app.|
| --force    | No    | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.                                                                 |
| --encrypt-path | No    | Path of **encrypt.json**| The file name must be **encrypt.json**.                                                                 |
| --pac-json-path | No    | NA          | Path of the pac.json file. The file name must be pac.json.<br>The pac.json file in the final app product comes only from this parameter. If this parameter is not set, the final app product does not contain this file.<br>The pac.json file in the app package specified by the --app-list parameter is not packed into the final app.<br>This parameter is supported since API version 20.|
| --atomic-service-entry-size-limit      | No        | NA            | Maximum size of the entry package (including the size of the dependency package) of an FA. This parameter is valid only when the stage model is used and bundleType is set to atomicService. The value is an integer of [0,4194304]. The value 0 indicates that the size is not limited. The unit is KB. If this parameter is not set, the default value 2048 KB is used.                      |
| --atomic-service-non-entry-size-limit  | No        | NA            | Maximum size of a non-entry package (including the size of its dependency package) of an FA. This parameter is valid only when the stage model is used and bundleType is set to atomicService. The value is an integer of [0,4194304]. The value 0 indicates that the size is not limited. The unit is KB. If this parameter is not set, the default value 2048 KB is used.                    |



## HQF Packing Command

If you find detects in the application and want to rectify the defects quickly, you can use HQF files. You can use the JAR package of the packing tool to generate an HQF file for an application by passing in packing options and file paths.

Packing command example:

```
java -jar app_packing_tool.jar --mode hqf --json-path <path> [--lib-path <path>] [--ets-path <path>] [--resources-path <path>] --out-path <path> [--force true]
```

**Table 5** Parameters of the HQF packing command

| Name         | Mandatory| Option         | Description                                |
|-------------|-------|-------------|------------------------------------|
| --mode      | Yes    | hqf         | Packing mode.                             |
| --json-path | Yes    | NA          | Path of the .json file. The file name must be [patch.json](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-incremental-debugging#section28031446182019).       |
| --lib-path  | No    | NA          | Path of the library file.                        |
| --ets-path  | No    | NA          | Path of the ETS file.                      |
| --resources-path  | No    | NA          | Path of the resources file.                      |
| --out-path  | Yes    | NA          | Path of the target file. The file name extension must be .hqf.             |
| --force     | No    | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.|

## APPQF Packing Command

An APPQF file consists of one or more HQF files. These HQF files are split from an APPQF file in the application market and then distributed to specific devices. You can use the JAR package of the packing tool to generate an APPQF file for an application by passing in packing options and file paths.

**APPQF package validity check**
- When generating an APPQF package, ensure that the values of versionName, versionCode, patchVersionName, and patchVersionCode in the [patch.json file](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-incremental-debugging#section28031446182019) of each HQF are the same.
- All HQFs must be unique. HQF repetition indicates that both of the following conditions are met:
	1. The values of the name fields under module in the patch.json files of the two HQFs are the same.
	2. The deviceTypes attributes of modules in the patch.json files of two HQFs overlap (at least one device type is the same).

Packing command example:

```
java -jar app_packing_tool.jar --mode appqf --hqf-list <path> --out-path <path> [--force true]
```

**Table 6** Parameters of the APPQF packing command

| Name        | Mandatory| Option         | Description                                |
|------------|-------|-------------|------------------------------------|
| --mode     | Yes    | appqf       | Packing mode.                             |
| --hqf-list | Yes    | NA          | HQF file Path. Use commas (,) to separate multiple HQF files.             |
| --out-path | Yes    | NA          | Path of the target file. The file name extension must be .appqf.           |
| --force    | No    | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.|

## versionNormalize Command

For the same APP, the values of **versionName** and **versionCode** of all the HAP and HSP files must be the same. When only one HAP or HSP needs to be updated, you can run the **versionNormalize** command to unify the versions of these HAP or HSP files. This command changes the version numbers and names of the HAP and HSP files passed in, and generates in the specified directory new HAP and HSP files with the same names and a **version_record.json** file to record their original version numbers and names.

Packing command example:
```
java -jar app_packing_tool.jar --mode versionNormalize --input-list 1.hap,2.hsp --version-code 1000001 --version-name 1.0.1 --out-path out
```

**Table 7** Parameters of the versionNormalize command

| Name            | Mandatory| Option              | Description                                                               |
|----------------|-------|------------------|-------------------------------------------------------------------|
| --mode         | Yes    | versionNormalize | Command type.                                                            |
| --input-list   | Yes    | Path of the HAP or HSP files      | 1. Path of the HAP or HSP package file. The file name extension must be .HAP or .HSP. If there are multiple HAP or HSP files, separate them with commas (,).<br>2. When a directory is imported, all HAP and HSP files in the directory are read.|
| --version-code | Yes    | Internal version number             | New internal version number of the HAP and HSP files. The value must be an integer and cannot be earlier than the version numbers of all the HAP and HSP files passed in.           |
| --version-name | Yes    | Version name            | New version name of the HAP and HSP files.                                   |
| --out-path     | Yes    | NA               | Target file path, which must be a directory (folder).                                                  |

## packageNormalize Command

The **packageNormalize** command is used to change the passed-in HSP bundle name and version number and generate an HSP with the same name in the specified directory.

Packing command example:
```
java -jar app_packing_tool.jar --mode packageNormalize --hsp-list 1.hsp,2.hsp --bundle-name com.example.myapplication --version-code 1000001 --out-path out
```

**Table 8** Parameters of the packageNormalize command

| Name            | Mandatory| Option           | Description                                                 |
|----------------|-------|---------------|-----------------------------------------------------|
| --mode         | Yes    | packageNormalize | Command type.                                              |
| --hsp-list     | Yes    | Path of the HSP files     | 1. Path of the HSP files. The file name extension must be .hsp. If there are multiple HSP files, separate them with commas (,).<br>2. HSP package directory. Only .hsp files in the directory are processed.|
| --bundle-name  | Yes    | Bundle name           | New bundle name, to which the passed-in bundle name will be changed.                            |
| --version-code | Yes    | Internal version number          | New version number, to which the passed-in version number will be changed. The value must be an integer greater than 0.                |
| --out-path     | Yes    | NA            | Target file path, which must be a directory (folder).                                    |

## General Normalization Instruction (generalNormalize)

This command is used to modify the deviceType/bundleName/versionName/versionCode/minCompatibleVersionCode/minAPIVersion/targetAPIVersion/ of the input HAP/HSP.<br>
apiReleaseType/bundleTypes/installationFree/deliveryWithInstall parameter. A new HAP/HSP with the same name and a general_record.json file are generated in the specified directory to record the original parameter names and module names of HAP and HSP. The preceding parameters must comply with the correct packaging specifications. Otherwise, the HAP/HSP file fails to be generated in the specified directory, and no file is generated in the specified directory.

> **NOTE**
>
> - General normalization instructions are supported since API version 20.

Packing command example:

```
java -jar app_packing_tool.jar --mode generalNormalize --input-list 1.hsp,2.hsp --bundle-name com.example.myapplication --version-code 1000001 --version-name 1.0.1 --min-compatible-version-code 14 --min-api-version 14 --target-api-version 14 --api-release-type Release1 --bundle-type app --installation-free false --delivery-with-install true --device-types default,tablet --out-path out
```

**Table 8** Parameters of the packageNormalize command

| Name                         | Mandatory| Option                                              | Description                                                        |
| ----------------------------- | ---------- | -------------------------------------------------- | ------------------------------------------------------------ |
| --mode                        | Yes        | generalNormalize                                   | Instruction type, indicating a general normalization instruction.                              |
| --input-list                  | Yes        | Path of the HAP or HSP files                                    | 1. Path of the HAP or HSP package file. The file name extension must be .HAP or .HSP. Use commas (,) to separate multiple HAP or HSP package file paths.<br>2. When a directory is imported, all HAP and HSP files in the directory are read.|
| --bundle-name                 | No        | Bundle name                                              | Bundle name. The bundle name of the input package will be changed to the bundle name. The specified value cannot be empty. For details about the definition and specifications of this field, see the bundleName field in [app.json5](../quick-start/app-configuration-file.md).|
| --version-code                | No        | Internal version number                                            | Version number. The version number of the input package will be changed to this version number. The value is an integer ranging from 0 to 2147483647. The specified value cannot be empty. For details about the definition and specifications of this field, see the versionCode field in [app.json5](../quick-start/app-configuration-file.md).|
| --version-name                | No        | Version name                                          | Version name. The version name of the input package will be changed to this version name. The specified value cannot be empty. For details about the definition and specifications of this field, see the versionName field in [app.json5](../quick-start/app-configuration-file.md).|
| --min-compatible-version-code | No        | Earliest Compatible Version                          | Specifies the earliest historical version number. The earliest historical version number of the input package will be changed to this version number. The value is an integer ranging from 0 to 2147483647. The specified value cannot be empty. For details about the definition and specifications of this field, see the minCompatibleVersionCode field in [app.json5](../quick-start/app-configuration-file.md).|
| --min-api-version             | No        | Minimum API version of the SDK.                                  | Minimum API version of the specified SDK. The minimum API version of the SDK in the transferred package will be changed to this version. The value is an integer ranging from 0 to 2147483647. The specified value cannot be empty. For details about the definition and specifications of this field, see the minAPIVersion field in [app.json5](../quick-start/app-configuration-file.md).|
| --target-api-version          | No        | Target API Version                                       | Target API version. The target API version of the transferred package will be changed to this version. The value is an integer ranging from 0 to 2147483647. The specified value cannot be empty. For details about the definition and specifications of this field, see the targetAPIVersion field in [app.json5](../quick-start/app-configuration-file.md).|
| --api-release-type            | No        | Type of the target API version.                                 | Type of the target API version. The type of the target API version of the transferred package will be changed to this type. The specified value cannot be empty. For details about the definition and specifications of this field, see the apiReleaseType field in [app.json5](../quick-start/app-configuration-file.md).|
| --bundle-type                 | No        | Bundle Type                                        | Specified bundle type. The bundle type of the input package will be changed to this type. The specified value cannot be empty. For details about the definition and specifications of this field, see the bundleType field in [app.json5](../quick-start/app-configuration-file.md).|
| --installation-free           | No        | Whether the installation-free feature is supported                                | Specified installation-free feature. The installation-free feature of the input package will be changed to this type. The value cannot be empty. For details about the definition and specifications of this field, see the installationFree field in [module.json5](../quick-start/module-configuration-file.md) in the stage model or [config.json](../quick-start/application-configuration-file-overview-fa.md) in the FA model.|
| --delivery-with-install       | No        | Whether the HAP file will be installed when the user installs the application.| Whether the specified HAP needs to be installed together. The deliveryWithInstall of the input package will be changed to this type. The value cannot be empty. For details about the definition and specifications of this field, see the deliveryWithInstall field in [module.json5](../quick-start/module-configuration-file.md) in the stage model or [config.json](../quick-start/application-configuration-file-overview-fa.md) in the FA model.|
| --device-types                | No        | Type of device on which the ability can run.                         | Device type. The device type of the transferred package will be changed to this type. The value cannot be empty. For details about the definition and specifications of this field, see the deviceTypes field in [module.json5](../quick-start/module-configuration-file.md) in the stage model or [config.json](../quick-start/application-configuration-file-overview-fa.md) in the FA model. The input value is a string. Multiple device types are separated by commas (,).|
| --out-path                    | Yes        | NA                                                 | Path of the target file. The path must be a directory with the read and write permissions.                  |

## Packing Commands for RES Files

This command is used to generate an HAP file for the **pack.res** file.

Packing command example:

```
java -jar app_packing_tool.jar --mode res --entrycard-path <path> --pack-info-path <path> --out-path <path> [--force true]
```

**Table 10** Parameters of the FastApp packing command

| Name              | Mandatory| Option           | Description                                |
|------------------|-------|---------------|------------------------------------|
| --mode           | Yes    | res           | Command type.                             |
| --entrycard-path | Yes    | NA            | Path of the **pack.res** file.                          |
| --pack-info-path | Yes    | NA            | Path of the **pack.info** file.             |
| --out-path       | Yes    | NA            | Path of the target file. The file name extension must be .res.             |
| --force          | No    | true or false  | The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.|

## Packing Commands for FastApp Files

You can use the JAR package of the packing tool to generate an APP file for a fast application by passing in packing options and path of the HAP or HSP files. The APP file is used to release the application to the application market.

**Table 14** FastApp packaging validity verification rules

| Verified field in the module.json file of the HAP/HSP. | Verification Rules                          |
| --------------------------------- | --------------------------------- |
| name field under module               | The name field values of all HAPs/HSPs must be different.     |
| bundleName                       | The bundleName field values of all HAPs/HSPs must be the same. |
| bundleType                       | The bundleType field values of all HAPs/HSPs must be the same. |
| versionCode                      | The version codes of all HAPs/HSPs must be the same.|
| debug                            | Since API version 20, the debug field values of all HAPs must be the same. If the debug field value of HAP is false, the debug field value of HSP must also be false. If the value of debug in HAP is true, there is no requirement on the value of debug in HSP.<br>For API version 19 and earlier versions, the debug field values of all HAPs/HSPs must be the same.   |
| minAPIVersion                    | From API version 20, the values of minAPIVersion of all HAPs must be the same and must be greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 19 and earlier versions, the values of the minAPIVersion field of all HAPs/HSPs must be the same.   |
| minCompatibleVersionCode         | From API version 16, the values of minCompatibleVersionCode of all HAPs must be the same and greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 15 and earlier versions, the values of minCompatibleVersionCode of all HAPs/HSPs must be the same.   |
| targetAPIVersion                 | From API version 16, the targetAPIVersion values of all HAPs must be the same and must be greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 15 and earlier versions, the values of the targetAPIVersion field of all HAPs/HSPs must be the same.   |

> **NOTE**
>
> - The module.json file is the compilation and building product of DevEco Studio. For details about the mapping between fields and configuration files, see [Table 1 Mapping between module.json and configuration file attributes](packing-tool.md).

**Compression rules**: When packaging the APP files, the HAP and HSP files in release mode are compressed, but the HAP and HSP files in debug mode are not compressed.

> **NOTE**
> 
> If the .so file has been compressed in the HAP/HSP and is compressed again during app packaging, the size of the .so file will not be significantly reduced.

Packing command example:

```
java -jar app_packing_tool.jar --mode fastApp [--hap-path <path>] [--hsp-path <path>] --out-path <path> [--signature-path <path>] [--certificate-path <path>] --pack-info-path <path> [--pack-res-path <path>] [--force true] [--encrypt-path <path>] [--pac-json-path <path>] [--atomic-service-entry-size-limit <size>] [--atomic-service-non-entry-size-limit <size>]
```

**Table 10** Parameters of the FastApp packing command

| Name                | Mandatory| Option        | Description                                                    |
|--------------------|-------|------------|----------------------------------------------------|
| --mode             | Yes    | fastApp    | Packing mode. Each HAP file to pack into the APP file must pass the validity check.                                     |
| --hap-path         | No    | NA         | Path of the HAP file directory, which contains all files of the HAP. If there are multiple HAP file directories, separate them with commas (,).                                             |
| --hsp-path         | No    | NA         | 1. Path of the HSP files. The file name extension must be .hsp. If there are multiple HSP files, separate them with commas (,).<br>2. Directory for storing the HSP package. The directory must contain all files of the HSP package. If there are multiple HSP file directories, separate them with commas (,).|
| --pack-info-path   | Yes    | NA         | Path of the **pack.info** file. The file name must be **pack.info**.                                              |
| --out-path         | Yes    | NA         | Path of the target file. The file name extension must be .app.                                            |
| --signature-path   | No    | NA         | Path of the signature file.                                                           |
| --certificate-path | No    | NA         | Path of the certificate file.                                               |
| --pack-res-path    | No    | NA         | Path of the **pack.res** file.                  |
| --force            | No    | true or false| The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.          |
| --encrypt-path     | No    | NA         | The file name must be **encrypt.json**.          |
| --pac-json-path     | No    | NA          | Path of the pac.json file. The file name must be pac.json.<br>This parameter is supported since API version 20.|
| --atomic-service-entry-size-limit      | No        | NA            | Maximum size of the entry package (including the size of the dependency package) of an FA. This parameter is valid only when the stage model is used and bundleType is set to atomicService. The value is an integer of [0,4194304]. The value 0 indicates that the size is not limited. The unit is KB. If this parameter is not set, the default value 2048 KB is used.                     |
| --atomic-service-non-entry-size-limit  | No        | NA            | Maximum size of a non-entry package (including the size of its dependency package) of an FA. This parameter is valid only when the stage model is used and bundleType is set to atomicService. The value is an integer of [0,4194304]. The value 0 indicates that the size is not limited. The unit is KB. If this parameter is not set, the default value 2048 KB is used.                    |

## Packaging Tool Error Codes

### 10010001 Failed to Run the Packing Tool
**Error Message**

Execute packing tool failed.

**Description**

Failed to run the packaging tool.

**Possible Causes**

1. Failed to verify the validity of the package file.
2. The file to be packaged is being used by another program, such as the compression software or file manager.

**Solution**

1. Check whether the configuration items in [app.json5](../quick-start/app-configuration-file.md) and [module.json5](../quick-start/module-configuration-file.md) are correct based on the error information. If there are multiple error messages, rectify the fault based on the first error message.
2. Check whether any program (such as the compression software or file manager) occupies the package file. If yes, stop the related process and try again.

### 10012001 Failed to Perform Compression
**Error Message**

Execute compress process failed.

**Description**

During packaging, for example, HAP or app packaging, the compression operation fails. As a result, the packaging is interrupted.

**Possible Causes**

1. Failed to verify the validity of the package file.
2. The file to be packaged is being used by another program, such as the compression software or file manager.

**Solution**

1. Check whether the configuration items in [app.json5](../quick-start/app-configuration-file.md) and [module.json5](../quick-start/module-configuration-file.md) are correct based on the error information. If there are multiple error messages, rectify the fault based on the first error message.
2. Check whether any program (such as the compression software or file manager) occupies the package file. If yes, stop the related process and try again.

### 10012002 Failed to Compress the HAP
**Error Message**

Compress Stage Hap failed.

**Description**

Failed to compress the HAP package of the stage model during HAP packaging.

**Possible Causes**

1. Failed to verify the validity of the HAP package of the stage model.
2. The file to be packaged is being used by another program, such as the compression software or file manager.

**Solution**

1. Check whether the configuration items in [app.json5](../quick-start/app-configuration-file.md) and [module.json5](../quick-start/module-configuration-file.md) are correct based on the error information. If there are multiple error messages, rectify the fault based on the first error message.
2. Check whether any program (such as the compression software or file manager) occupies the package file. If yes, stop the related process and try again.

### 10012003 Failed to Verify HAP Information
**Error Message**

Verify stage hap info failed.

**Description**

Failed to verify the configuration information when packaging the HAP package of the stage model.

**Possible Causes**

`atomicService` or `continueBundleName` in `module.json5` is incorrectly configured, or `asanEnabled` or `hwasanEnabled` in `app.json5` is incorrectly configured.

**Solution**

 

### 10012004 Failed to Check the asanEnabled Parameter
**Error Message**

Check asanEnabled failed.

**Description**

During HAP/HSP packaging, `asanEnabled` in `app.json5` is incorrectly configured.

**Possible Causes**

Both `asanEnabled` and `tsanEnabled` are set to true.

**Solution**

Check [app.json5](../quick-start/app-configuration-file.md) and change the values of `asanEnabled` and `tsanEnabled` to ensure that the values of `asanEnabled` and `tsanEnabled` are not true at the same time.

### 10012005 Failed to Check the hwasanEnabled Parameter
**Error Message**

Check hwasanEnabled failed.

**Description**

During HAP/HSP packaging, `hwasanEnabled` in `app.json5` is incorrectly configured.

**Possible Causes**

1. Both `hwasanEnabled` and `asanEnabled` are set to true.
2. Both `hwasanEnabled` and `tsanEnabled` are set to true.
3. Both `hwasanEnabled` and `GWPAsanEnabled` are set to true.

**Solution**

Check [app.json5](../quick-start/app-configuration-file.md). Ensure that any of `asanEnabled`, `tsanEnabled`, and `GWPAsanEnabled` and `hwasanEnabled` are not set to true at the same time.

### 10012006 Failed to Check atomicService
**Error Message**

Check atomicService failed.

**Description**

Failed to check the `atomicService` configuration during HAP/HSP packaging.

**Possible Causes**

1. ability is not configured in the `entry` module of `module.json5`. As a result, the `atomicService` configuration check fails.
2. `bundleType` in `app.json5` is set to `atomicService`, but `installationFree` in `module.json5` is set to false.

**Solution**

1. Check [module.json5](../quick-start/module-configuration-file.md). Ensure that the `abilities` tag is correctly configured in the `module.json5` file and at least one ability is contained. For details, see [abilities tag](../quick-start/module-configuration-file.md).
2. Check `module.json5` and [app.json5](../quick-start/app-configuration-file.md). If `bundleType` is set to `atomicService`, ensure that `installationFree` is set to true. Otherwise, set `installationFree` to false.

### 10012007 Invalid continueBundleName
**Error Message**

Check continueBundleName invalid.

**Description**

Failed to check the `continueBundleName` configuration during HAP/HSP packaging.

**Possible Causes**

`continueBundleName` in `module.json5` is the same as `bundleName` in `app.json5`.

**Solution**

Modify `continueBundleName` to ensure that it is different from `bundleName` in [app.json5](../quick-start/app-configuration-file.md).

### 10012008 Failed to Check the Overlay HSP
**Error Message**

Check whether is an overlay hsp failed.

**Description**

Check whether the HSP package of the overlay feature fails.

**Possible Causes**

1. Both `targetModuleName` and `requestPermissions` are configured in `module.json5`.

2. The value of `targetModuleName` in `module.json5` is the same as that of `name` in `module.json5`.

3. When `targetPriority` is configured in `module.json5`, `targetModuleName` is not configured.

4. When `targetBundleName` is configured in `app.json5`, `targetModuleName` is not configured in `module.json5`.

5. In `app.json5`, the value of `targetBundleName` is the same as that of `bundleName`.

**Solution**

1. Check [module.json5](../quick-start/module-configuration-file.md) and ensure that `targetModuleName` and `requestPermissions` do not appear at the same time.
2. Ensure that the value of `targetModuleName` is different from that of `name`.
3. Check `module.json5` and ensure that `targetModuleName` is configured when `targetPriority` is configured.
4. Check [app.json5](../quick-start/app-configuration-file.md) and `module.json5` and ensure that `targetModuleName` is configured when `targetBundleName` is configured.
5. Check `app.json5` and ensure that `targetBundleName` is different from `bundleName`.

### 10012009 Compression Error
**Error Message**

Process compress exception.

**Description**

An exception occurs when the HAP, HSP, or app is compressed.

**Possible Causes**

1. Failed to verify the validity of the package file.
2. The file to be packaged is being used by another program, such as the compression software or file manager.

**Solution**

1. Check whether the configuration items in [app.json5](../quick-start/app-configuration-file.md) and [module.json5](../quick-start/module-configuration-file.md) are correct based on the error information. If there are multiple error messages, rectify the fault based on the first error message.
2. Check whether any program (such as the compression software or file manager) occupies the package file. If yes, stop the related process and try again.

### 10012015 Failed to Build an App Package
**Error Message**

Compress app file failed.

**Description**

Failed to build the app package.

**Possible Causes**

1. Failed to verify the validity of the app package file.
2. The file to be packaged is being used by another program, such as the compression software or file manager.

**Solution**

1. Check whether the configuration items in [app.json5](../quick-start/app-configuration-file.md) and [module.json5](../quick-start/module-configuration-file.md) are correct based on the error information. If there are multiple error messages, rectify the fault based on the first error message.
2. Check whether any program (such as the compression software or file manager) occupies the package file. If yes, stop the related process and try again.

### 10012017 Invalid SharedAPP
**Error Message**

Check shared App mode invalid.

**Description**

When an app package whose [bundleType](../quick-start/app-configuration-file.md) is shared is built, the HSP package is invalid.

**Possible Causes**

1. More than two [HSP packages](../quick-start/in-app-hsp.md) exist. As shown in the following figure, when you use DevEco Studio to build an app, the project contains two HSP packages: library and library1. In this case, the app package fails to be packaged.

![alt text](figures/zh_cn_packing_tool_image_10012017_01.png)

2. `dependencies` is configured in `module.json5` of the HSP package.

**Solution**

1. Check the package file and ensure that there is no more than one HSP package in the app package whose `bundleType` is shared.
2. Check the package file and delete `dependencies` from [module.json5](../quick-start/module-configuration-file.md) in the HSP package.

### 10012022 Failed to Verify the Stage HSP
**Error Message**

Verify stage hsp info failed.

**Description**

Failed to verify the HSP package of the stage model during HSP packaging.

**Possible Causes**

1. `atomicService` and `continueBundleName` in `module.json5` are incorrectly configured, or `asanEnabled` and `hwasanEnabled` in `app.json5` are incorrectly configured.
2. The overlay configuration is incorrect.

**Solution**

1.  
1. Modify the configuration items.

### 10012024 Failed to Verify the Metadata Service Size
**Error Message**

Check atomicService size failed.

**Description**

During app packaging, the size of the FA package exceeds 2 MB.

**Possible Causes**

The size of the FA package and its dependent shared library or resource file exceeds 2 MB.

**Solution**

Optimize and reduce the package size, for example, delete unnecessary resources, simplify code, or reduce dependencies.

### 10013005 Failed to Check the Bundle Type of a Module
**Error Message**

Failed to parse module.json and bundleType.

**Description**

Failed to check the bundle type of the module.

**Possible Causes**

The configuration does not meet the requirements. For example:
1. In the [app.json5](../quick-start/app-configuration-file.md) configuration file of the module, the value of `bundleType` is app, but the value of `installationFree` in [module.json5](../quick-start/module-configuration-file.md) is true.
2. In the app.json5 configuration file of the module, the value of `bundleType` is atomicService, but the value of `installationFree` in the module.json5 configuration file is false.
3. In the app.json5 configuration file of the module, the value of `bundleType` is shared, but the value of `type` in the module.json5 configuration file is not shared.

**Solution**

1. Ensure that the value of `installationFree` in the module.json5 file is false when `bundleType` in the app.json5 file is set to app.
2. Ensure that the value of `installationFree` in the module.json5 file is true when `bundleType` in the app.json5 file is atomicService.
3. Ensure that the value of `type` in the module.json5 file is shared when the value of `bundleType` in the app.json5 file is shared.
4. If there are multiple error messages, rectify the fault based on the first error message.

### 10013006 Failed to Check ability in the Entry Module
**Error Message**

check entry module at least one ability failed.

**Description**

The entry package does not contain ability.

**Possible Causes**

The entry package does not contain ability. The possible cause is that `module.json5` is not set to `abilities` or `abilities` is left empty.

**Solution**

Check [module.json5](../quick-start/module-configuration-file.md) and ensure that ability is correctly configured for `abilities` of the entry package.

### 10013007 Checking for the installationFree Error
**Error Message**

Check module atomicService installationFree invalid.

**Description**

An error occurred when checking the `atomicService` and `installationFree` settings during HAP/HSP packaging.

**Possible Causes**

1. The value of `bundleType` in `app.json5` is invalid.
2. When `bundleType` is set to shared, `installationFree` in `module.json5` is not set to false.
3. When `installationFree` is set to true, `bundleType` is not set to atomicService.

**Solution**

1. Check [app.json5](../quick-start/app-configuration-file.md) and ensure that `bundleType` is set to app, atomicService, shared<!--Del-->, or appService<!--DelEnd-->.
2. If `bundleType` is set to shared, ensure that `installationFree` in [module.json5](../quick-start/module-configuration-file.md) is set to false.
3. If `installationFree` is true, ensure that `bundleType` is set to atomicService.

### 10014001 No Available File
**Error Message**

File available not found exception.

**Description**

When you use the packaging tool to package files, the files to be packaged cannot be used.

**Possible Causes**

1. The specified file path is incorrect or the file does not exist.
2. The file is being used by another program, such as the compression software or file manager.
3. The current user does not have the permission to access the file.

**Solution**

1. Check whether the file path is correct and whether the file exists.
2. Check whether any program (such as the compression software or file manager) occupies the file. If yes, stop the process and try again.
3. Check and adjust the file access permission. For example, the current user can read, modify, and delete files.

### 10016003 Failed to Verify Distribution Policy Intersection
**Error Message**

Check two distroFilter policy disjoint invalid.

**Description**

[The logic for checking HAP uniqueness](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-verification-rule) checks whether the distribution policies intersect. However, the distribution policies are incorrectly configured. As a result, the system cannot determine whether the distribution policies intersect.

**Possible Causes**

The `policy` and `value` tags of the distribution policy are empty or invalid.

**Solution**

Check the distribution policy configuration and ensure that the value of `policy` is `include` or `exclude`. For details about the value of `value`, see [distributionFilter](../quick-start/module-configuration-file.md#distributionfilter).

### 10016006 Invalid HAP Package
**Error Message**

Verify hap info is invalid.

**Description**

Failed to verify the HAP/HSP used for packaging during app package building.

**Possible Causes**

The configurations of multiple HAPs/HSPs conflict with each other.

**Solution**

Check whether the configuration items in [app.json5](../quick-start/app-configuration-file.md) and [module.json5](../quick-start/module-configuration-file.md) are correct based on the error information. If there are multiple error messages, rectify the fault based on the first error message.

### 10016007 Invalid Entry Module
**Error Message**

Check entry module invalid.

**Description**

When a project contains multiple HAP packages of the entry type during app package building, the configuration information fails to be checked.

**Possible Causes**

The HAP uniqueness verification rule is not met.

**Solution**

Adjust the HAP configuration of the entry type in the project by referring to [Understanding the Logic for Checking HAP Uniqueness](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-verification-rule).

### 10016009 Check Dependency Error
**Error Message**

Check dependency list is invalid.

**Description**

The module dependency fails to be checked during app package building.

**Possible Causes**

1. Cyclic dependency exists between modules. For example, if `dependencies` in `module.json5` of module library1 is set to library2 and `dependencies` in module library2 is set to library1, cyclic dependency exists between the two modules.
2. The `type` in `module.json5` corresponding to the dependent module in the `module.json5` configuration is entry or feature.

**Solution**

1. Check `dependencies` in [module.json5](../quick-start/module-configuration-file.md) and delete cyclic dependency to ensure that no cyclic dependency exists in the app.
2. Check the configuration of `dependencies` in `module.json5` and delete the dependency on the entry or feature module.

### 10016010 Invalid Meta Service
**Error Message**

Check atomicservice is invalid.

**Description**

When an app package is built, the FA check result is invalid.

**Possible Causes**

The value of `moduleName` in `preloads` of `module.json5` is incorrect.

**Solution**

Check the `moduleName` under [preloads](../quick-start/module-configuration-file.md#atomicservice) in [module.json5](../quick-start/module-configuration-file.md). The `moduleName` cannot be set to the `name` in the `module.json5` of the module, and the module corresponding to the `moduleName` must exist.

### 10016011 Checking Whether Meta Service Preloading Is Invalid
**Error Message**

Atomicservice preloads is invalid.

**Description**

When an app package whose bundleType is atomicService is constructed, the module pre-loaded in the FA package is invalid.

**Possible Causes**

1. Duplicate `moduleName`s are configured for `preloads` in `module.json5` of the meta service package.
2. The value of `moduleName` in the meta service package does not match the value of `name` in `module.json5` in other meta service packages.
3. The value of `moduleName` in the meta service package is the same as the value of `name` in `module.json5`.

**Solution**

Check the preloads attribute (../quick-start/module-configuration-file.md#atomicservice tag) of the metadata service in [module.json5](../quick-start/module-configuration-file.md). Ensure that no duplicate module is configured, all modules exist, and the module name cannot be configured.

### 10016012 Target Module Does Not Exist
**Error Message**

TargetModuleName is not exist.

**Description**

During app building, the target module is configured in the module, but the module is not found.

**Possible Causes**

`targetModuleName` is configured in `module.json5`, but the value is different from `name` in `module.json5` of other modules.

**Solution**

Check the `targetModuleName` configuration item and ensure that it is correctly configured. For details, see [module.json5 configuration file label](../quick-start/module-configuration-file.md) and the targetModuleName attribute. If necessary, create a target module.

### 10016014 The proxy data is not unique.
**Error Message**

Proxy data uri is not unique.

**Description**

The URI of the data proxy is not unique.

**Possible Causes**

Duplicate URIs are configured for `proxyData` in `module.json5`.

**Solution**

Check [module.json5](../quick-start/module-configuration-file.md) and delete duplicate URIs from `proxyData` to ensure that each URI is unique. For details, see [proxyData](../quick-start/module-configuration-file.md#proxydata).

### 10016015 Invalid ContinueType Configuration
**Error Message**

Check continueType is invalid.

**Description**

The continueType configuration is incorrect during app building.

**Possible Causes**

1. Different abilities of `module.json5` have duplicate `continueType` configuration items.
2. Duplicate `deviceType` and `continueType` configuration items exist in different `module.json5`s.

**Solution**

Check [module.json5](../quick-start/module-configuration-file.md) and delete the duplicate configuration items of `continueType` or `deviceType`.

### 10016016 File Size Check Error
**Error Message**

Check file size failed.

**Description**

When building an app of the meta service type, check whether the size of a single package exceeds 2 MB.

**Possible Causes**

The size of a single package exceeds 2 MB.

**Solution**

Optimize and reduce the size of a single package file, for example, delete unnecessary resources, simplify code, or compress files.

### 10016018 Failed to Check the Size of the Metadata Service Module
**Error Message**

Check the atomicService module size failed.

**Description**

When building an app of the meta service type, check whether the size of a single package and the shared library on which the package depends exceeds 2 MB.

**Possible Causes**

The total size of a package and its dependent shared libraries exceeds 2 MB.

**Solution**

Optimize and reduce the size of the corresponding package, for example, delete unnecessary resources, simplify code, or reduce dependencies.

### 10016019 Invalid Distribution Policy
**Error Message**

Check the entry module distributionFilter is invalid.

**Description**

The distribution policy of the entry-type module is incorrect.

**Possible Causes**

The distribution policy of the entry-type module is incorrectly configured.

**Solution**

Check whether the distribution policy of the Entry module is correctly configured. For example, the value of `policy` should be `exclude` or `include`. For details, see [distributionFilter](../quick-start/module-configuration-file.md#distributionfilter).

### 10011021 Failed to Run the General Normalization Command

**Error Message**

Parse and check args invalid in generalNormalize mode.

**Description**

Failed to execute the general normalization command.

**Possible Causes**

1. The input parameter type is incorrect.
2. The input parameter range is incorrect.
3. The input HAP/HSP package is incomplete. The JSON file is missing. For details about how to configure the JSON file, see the stage model [module.json5](../quick-start/module-configuration-file.md) /FA model [config.json](../quick-start/application-configuration-file-overview-fa.md).

**Solution**

Check and input the correct command parameters and valid package file.
