# Packing Tool

The packing tool packs compiled files for installation and release. You can use DevEco Studio or the JAR package of the packaging tool to pack files. The JAR package is usually stored in the **toolchains** directory of the SDK.

The packing tool supports the generation of HAP (module package of the ability type), HAR (statically shared package), HSP (dynamically shared package), APP (application program package), HQF (quick fix module package), and APPQF (quick fix package) files.


## HAP Packing Command

You can use the JAR package of the packing tool to generate an HAP file for a module by passing in packing options and file paths.

- Packing command example in the stage model:

      ```
      java -jar app_packing_tool.jar --mode hap --json-path <option> --resources-path <option>   --ets-path <option> --index-path <option> --pack-info-path <option> --out-path <option> --force true
      ```

- Packing command example in the FA model:

      ```
      java -jar app_packing_tool.jar --mode hap --json-path <option> --maple-so-path [option] --profile-path [option] --maple-so-dir [option] --dex-path [option] --lib-path [option] --resources-path [option] --index-path [option] --out-path <option> --force [option]
      ```

**Table 1** Parameters of the HAP packing command

| Name              | Mandatory| Option                  | Description                                                       | Remarks        |
|------------------|-------|----------------------|-----------------------------------------------------------|------------|
| --mode           | Yes    | hap                  | Packing mode.                                                    | NA         |
| --json-path      | Yes    | NA                   | Path of the JSON file. The file name must be **config.json** in the FA model and **module.json** in the stage model.| NA         |
| --profile-path   | No    | NA                   | Path of the **CAPABILITY.profile** file.                                  | NA         |
| --maple-so-path  | No    | NA                   | Path of the Maple SO file. The file name extension must be .so. If there are multiple SO files, separate them with commas (,).      | NA         |
| --maple-so-dir   | No    | NA                   | Path of the maple SO directory (folder).                                          | NA         |
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

## HAR Packing Command

You can use the JAR package of the packing tool to generate an HAR file for an application by passing in packing options and file paths.

Packing command example:

```
java -jar app_packing_tool.jar --mode har --json-path [option] --jar-path [option]--lib-path [option] --resources-path [option] --out-path [option] --force [option]
```

**Table 2** Parameters of the HAR packing command

| Name             | Mandatory| Option         | Description                                                       |
|-----------------|-------|-------------|-----------------------------------------------------------|
| --mode          | Yes    | har         | Packing mode.                                                    |
| --json-path     | Yes    | NA          | Path of the JSON file. The file name must be **config.json** in the FA model and **module.json** in the stage model.|
| --jar-path      | No    | NA          | Path of the JAR file. The file name extension must be .jar. If there are multiple JAR files, separate them with commas (,).<br>The value can also be the directory (folder) where the JAR file is stored.|
| --lib-path      | No    | NA          | Path of the library file.                                                |
| --resource-path | Yes    | NA          | Path of the resource file.                                          |
| --out-path      | Yes    | NA          | Path of the target file. The file name extension must be .har.                                    |
| --force         | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.                       |


## APP Packing Command

You can use the JAR package of the packing tool to generate an APP file for an application by passing in packing options and file paths. The APP file is used to release the application to the application market.

**HAP validity check**: When packing the HAP files in a project to generate an APP file, ensure that the values of **bundleName**, **versionCode**, **versionName**, **minCompatibleVersionCode**, **debug**, **minAPIVersion**, **targetAPIVersion**, and **apiReleaseType** configured in each JSON file of the HAP are the same, and the value of **moduleName** is unique in all the JSON files. For the FA model, you must also ensure that the value of **package** is unique in all the JSON files.


Packing command example:

```
java -jar app_packing_tool.jar --mode app --hap-path <option> --hsp-path <option> --out-path <option> --signature-path [option] --certificate-path [option] --pack-info [option]--force [option]
```

**Table 3** Parameters of the APP packing command

| Name                | Mandatory| Option         | Description                                                          |
|--------------------|-------|-------------|--------------------------------------------------------------|
| --mode             | Yes    | app         | Packing mode. Each HAP file to pack into the APP file must pass the validity check.                                          |
| --hap-path         | Yes    | NA          | Path of the HAP file. The file name extension must be .hap. If there are multiple HAP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HAP file is stored.|
| --hsp-path         | No    | NA          | Path of the HSP file. The file name extension must be .hsp. If there are multiple HSP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HSP file is stored.|
| --pack-info-path   | Yes    | NA          | Path of the **pack.info** file. The file name must be **pack.info**.                                            |
| --out-path         | Yes    | NA          | Path of the target file. The file name extension must be .app.                                       |
| --signature-path   | No    | NA          | Path of the signature file.                                                       |
| --certificate-path | No    | NA          | Path of the certificate file.                                                       |
| --force            | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.                          |



## Multi-project Packing Command

If multiple teams develop the same application but it is inconvenient to share code, you can use multi-project packing, which packs the packed HAP, HSP, and APP files into a final APP file and releases it to the application market.

**HAP validity check**: Ensure that the values of **bundleName**, **versionCode**, **versionName**, **minCompatibleVersionCode**, **debug**, **minAPIVersion**, **targetAPIVersion**, **apiReleaseType**, **compileSdkVersion**, and **compileSdkType** configured in each JSON file of the HAP are the same, the value of **moduleName** is unique in all the JSON files, and the value of **entry** is unique for the same device. For the FA model, you must also ensure that the value of **package** is unique in all the JSON files.

Packing command example:

```
java -jar app_packing_tool.jar --mode multiApp --hap-list [option] --hsp-list [option] --app-list [option] --out-path <option>
```

**Table 4** Parameters of the multi-project packing command

| Name        | Mandatory| Option       | Description                                                                                                 |
|------------|-------|-----------|-----------------------------------------------------------------------------------------------------|
| --mode     | Yes    | multiApp  | Packing mode. Each HAP file to pack into the APP file must pass the validity check.                                                           |
| --hap-list | No    | Path of the HAP files   | Path of the HAP files. The file name extension must be .hap. If there are multiple HAP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HAP files are stored.                                         |
| --hsp-list | No    | Path of the HSP files   | Path of the HSP files. The file name extension must be .hsp. If there are multiple HSP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HSP files are stored.                                         |
| --app-list | No    | Path of the APP files   | Path of the APP files. The file name extension must be .app. If there are multiple APP files, separate them with commas (,).<br>The value can also be the directory (folder) where the APP files are stored.<br>You must specify **--hap-list**, **--hsp-list**, or **--app-list**, or any of their combinations.|
| --out-path | Yes    | NA | Path of the target file. The file name extension must be .hqf.|
| --force    | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.                                                                 |



## HQF Packing Command

If you find detects in the application and want to rectify the defects quickly, you can use HQF files. You can use the JAR package of the packing tool to generate an HQF file for an application by passing in packing options and file paths.

Packing command example:

```
java -jar app_packing_tool.jar --mode hqf --json-path <option> --lib-path <option> --ets-path <option> --out-path <option>
```

**Table 5** Parameters of the HQF packing command

| Name         | Mandatory| Option         | Description                                |
|-------------|-------|-------------|------------------------------------|
| --mode      | Yes    | hqf         | Packing mode.                             |
| --json-path | Yes    | NA          | Path of the JSON file. The file name must be **patch.json**.       |
| --lib-path  | No    | NA          | Path of the library file.                        |
| --ets-path  | Yes    | NA          | Path of the ETS file.                      |
| --out-path  | Yes    | NA          | Path of the target file. The file name extension must be .hqf.             |
| --force     | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.|

## APPQF Packing Command

An APPQF file consists of one or more HQF files. These HQF files are split from an APPQF file in the application market and then distributed to specific devices. You can use the JAR package of the packing tool to generate an APPQF file for an application by passing in packing options and file paths.

Packing command example:

```
java -jar app_packing_tool.jar --mode appqf --hqf-list <option> --out-path <option>
```

**Table 6** Parameters of the APPQF packing command

| Name        | Mandatory| Option         | Description                                |
|------------|-------|-------------|------------------------------------|
| --mode     | Yes    | appqf       | Packing mode.                             |
| --hqf-list | Yes    | NA          | Path of the HQF file. If there are multiple HQF files, separate them with commas (,).             |
| --out-path | Yes    | NA          | Path of the target file. The file name extension must be .appqf.           |
| --force    | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.|

## HSP Packing Command

HSP files enable file sharing among multiple HAPs. You can use the JAR package of the packing tool to generate an HSP file for an application by passing in packing options and file paths.

Packing command example:
```
java -jar path\app_packing_tool.jar --mode hsp --json-path <option> --resources-path <option> --ets-path <option> --index-path <option> --pack-info-path <option> --out-path path\out\library.hsp --force true
```

**Table 7** Parameters of the HSP packing command

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
| --force          | No    | true or false| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.           |

## versionNormalize Command

For the same APP, the values of **versionName** and **versionCode** of all the HAP and HSP files must be the same. When only one HAP or HSP needs to be updated, you can run the **versionNormalize** command to unify the versions of these HAP or HSP files. This command changes the version numbers and names of the HAP and HSP files passed in, and generates in the specified directory new HAP and HSP files with the same names and a **version_record.json** file to record their original version numbers and names.

Packing command example:
```
java -jar path\app_packing_tool.jar --mode versionNormalize --input-list 1.hap,2.hsp --version-code 1000001 --version-name 1.0.1 --out-path path\out\
```

**Table 8** Parameters of the versionNormalize command

| Name            | Mandatory| Option              | Description                                                               |
|----------------|-------|------------------|-------------------------------------------------------------------|
| --mode         | Yes    | versionNormalize | Command type.                                                            |
| --input-list   | Yes    | Path of the HAP or HSP files      | Path of the HAP or HSP files. The file name extension must be .hap or .hsp. If there are multiple HAP or HSP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HAP and HSP files are stored. If this is the case, all HAP and HSP files in the directory (folder) are read.|
| --version-code | Yes    | Internal version number             | New internal version number of the HAP and HSP files. The value must be an integer and cannot be earlier than the version numbers of all the HAP and HSP files passed in.           |
| --version-name | Yes    | Version name            | New version name of the HAP and HSP files.                                   |
| --out-path     | Yes    | NA               | Target file path, which must be a directory (folder).                                                  |
