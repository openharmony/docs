# Packing Tool
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @jsjzju-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->

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

## Constraints

- The packing tool must run in Java 8 or later.
- The parameters and parameter values in the packing command must appear in pairs. For example, in the HAP packing command --resources-path \<path>, --resources-path indicates the command parameter, and path indicates the parameter value. The two parameters must be used at the same time.

## HAP Packing Command

You can use the JAR package of the packing tool to generate an HAP file for a module by passing in packing options and file paths.

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
| debug                            | The debug field values of all HAPs/HSPs must be the same.   |
| minAPIVersion                    | The values of the minAPIVersion field of all HAPs/HSPs must be the same.   |
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
java -jar app_packing_tool.jar --mode app [--hap-path <path>] [--hsp-path <path>] --out-path <path> [--signature-path <path>] [--certificate-path <path>] --pack-info-path <path> [--pack-res-path <path>] [--force true] [--encrypt-path <path>]
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



## Multi-project Packing Command

If multiple teams develop the same application but it is inconvenient to share code, you can use multi-project packing, which packs the packed HAP, HSP, and APP files into a final APP file and releases it to the application market.

**Table 6** Validity verification rules for multi-project packaging

| Verified field in the module.json file of the HAP/HSP. | Verification Rules                          |
| --------------------------------- | --------------------------------- |
| name field under module               | The name field values of all HAPs/HSPs must be different.     |
| bundleName                       | The bundleName field values of all HAPs/HSPs must be the same. |
| bundleType                       | The bundleType field values of all HAPs/HSPs must be the same. |
| versionCode                      | The version codes of all HAPs/HSPs must be the same.|
| debug                            | The debug field values of all HAPs/HSPs must be the same.   |
| minAPIVersion                    | The values of the minAPIVersion field of all HAPs/HSPs must be the same.   |
| minCompatibleVersionCode         | From API version 16, the values of minCompatibleVersionCode of all HAPs must be the same and greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 15 and earlier versions, the values of minCompatibleVersionCode of all HAPs/HSPs must be the same.   |
| targetAPIVersion                 | From API version 16, the targetAPIVersion values of all HAPs must be the same and must be greater than or equal to the maximum value of the corresponding field of all HSPs.<br>For API version 15 and earlier versions, the values of the targetAPIVersion field of all HAPs/HSPs must be the same.   |
| versionName                | Since API version 12, versionName is not verified.     |

> **NOTE**
>
> - The module.json file is the compilation and building product of DevEco Studio. For details about the mapping between fields and configuration files, see [Table 1 Mapping between module.json and configuration file attributes](packing-tool.md).

Packing command example:

```
java -jar app_packing_tool.jar --mode multiApp [--hap-list <path>] [--hsp-list <path>] [--app-list <path>] --out-path <option> [--force true] [--encrypt-path <path>]
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

## Packing Commands for RES Files

This command is used to generate an HAP file for the **pack.res** file.

Packing command example:

```
java -jar app_packing_tool.jar --mode res --entrycard-path <path> --pack-info-path <path> --out-path <path> [--force true]
```

**Table 12** Parameters of the FastApp packing command

| Name              | Mandatory| Option           | Description                                |
|------------------|-------|---------------|------------------------------------|
| --mode           | Yes    | res           | Command type.                             |
| --entrycard-path | Yes    | NA            | Path of the **pack.res** file.                          |
| --pack-info-path | Yes    | NA            | Path of the **pack.info** file.             |
| --out-path       | Yes    | NA            | Path of the target file. The file name extension must be .res.             |
| --force          | No    | true or false  | The default value is **false**. If the value is true, the target file is forcibly deleted when it exists.|

## Packing Commands for FastApp Files

You can use the JAR package of the packing tool to generate an APP file for a fast application by passing in packing options and path of the HAP or HSP files. The APP file is used to release the application to the application market.

**Table 13** FastApp packaging validity verification rules

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
java -jar app_packing_tool.jar --mode fastApp [--hap-path <path>] [--hsp-path <path>] --out-path <path> [--signature-path <path>] [--certificate-path <path>] --pack-info-path <path> [--pack-res-path <path>] [--force true] [--encrypt-path <path>]
```

**Table 14** Parameters of the FastApp packing command

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
