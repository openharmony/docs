# Packaging Tool


The packaging tool is a commissioning tool provided by OpenHarmony. It can generate HAP files in command line mode, pack multiple HAP files into an App Pack, or pack multiple HAP files and App Packs into an App Pack. App Pack is the application package format required for releasing an application on AppGallery.


The **app_packing_tool.jar** package can be found in the OpenHarmony SDK downloaded locally.


- Packing folders into an HAP file
  
The command in the stage model is as follows:
  
  
  ```bash
  java -jar app_packing_tool.jar --mode <option> --json-path <option> --resources-path <option> --ets-path <option> --index-path <option> --pack-info-path <option> --out-path <option> --force <option>
```
  
The command in the FA model is as follows:
  
  
  ```bash
  java -jar app_packing_tool.jar --mode <option> --json-path <option> --maple-so-path <option>  --profile-path <option> --maple-so-dir <option> --dex-path <option> --lib-path <option> --resources-path <option> --index-path <option> --out-path <option> --force <option>
```
  
The table below describes the command parameters.
  
  | Name| Mandatory| Description|
  | -------- | -------- | -------- |
  | --mode | Yes| Packing mode. In this scenario, set this parameter to **hap**.|
  | --json-path | Yes| Path of the .json file. The file name must be **config.json** in the FA model and **module.json5** in the stage model.|
  | --profile-path | No| Path of the **CAPABILITY.profile** file.|
  | --maple-so-path | No| Path of the maple .so file. The file name extension must be .so. If there are multiple .so files, separate them with commas (,).|
  | --maple-so-dir | No| Path of the maple .so directory.|
  | --dex-path | No| Path of the .dex file. The file name extension must be .dex. If there are multiple .dex files, separate them with commas (,).<br>The value can also be the directory (folder) where the .dex file is stored.|
  | --lib-path | No| Path of the library file.|
  | --resources-path | No| Path of the resource file.|
  | --index-path | No| Path of the .index file. The file name must be **resources.index**.|
  | --pack-info-path | No| Path of the **pack.info** file. The file name must be **pack.info**.|
  | --rpcid-path | No| Path of the **rpcid.sc** file. The file name must be **rpcid.sc**.|
  | --js-path | No| Path of the .js file. This parameter is valid only for the stage model.|
  | --ets-path | No| Path of the .ets file. This parameter is valid only for the stage model.|
  | --out-path | Yes| Path of the target file. The file name extension must be .hap.|
| --force | No| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.|
  
- Packing multiple HAP files into an App Pack
  
The command is as follows:
  
  
  ```bash
  java -jar app_packing_tool.jar --mode <option> --hap-path <option>  --out-path <option> --signature-path <option> --certificate-path <option>  --pack-info-path <option> --force <option>
```
  
The table below describes the command parameters.
  
  | Name| Mandatory| Description|
  | -------- | -------- | -------- |
  | --mode | Yes| Packing mode. In this scenario, set this parameter to **app**. Each HAP file to pack must have the same settings for **versionCode** and **versionName**.|
  | --hap-path | Yes| Path of the HAP file. The file name extension must be .hap. If there are multiple HAP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HAP file is stored.|
  | --pack-info-path | Yes| The file name must be **pack.info**.|
  | --out-path | Yes| Path of the target file. The file name extension must be .app.|
  | --signature-path | No| Signature path.|
  | --certificate-path | No| Certificate path. For details, see [Signature Guide](../security/hapsigntool-guidelines.md).|
| --force | No| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.|
  
- Packing multiple HAP files and App Packs into an App Pack
  
The command is as follows:
  
  
  ```bash
  java -jar app_packing_tool.jar --mode <option> --hap-list <option> --app-list <option> --out-path <option>
```
  
The table below describes the command parameters.
  
  | Name| Mandatory| Description|
  | -------- | -------- | -------- |
  | --mode | Yes| Packing mode. In this scenario, set this parameter to **multiApp**. Each HAP file to pack must meet the validity check rules.|
  | --hap-list | No| Path of the HAP file. The file name extension must be .hap. If there are multiple HAP files, separate them with commas (,).<br>The value can also be the directory (folder) where the HAP file is stored.|
  | --app-list | No| Path of the App Pack. The file name extension must be .app. If there are multiple App Packs, separate them with commas (,).<br>The value can also be the directory (folder) where the App Pack is stored.<br>You must specify either **--hap-list** or **--app-list**, or both.|
  | --out-path | Yes| Path of the target file. The file name extension must be .app.|
| --force | No| The default value is **false**. If the value is **true**, an existing target file will be forcibly deleted during packing.|
  
Rules for checking the validity of HAP files to be packed into an App Pack:
  
  - Each HAP file must have the same settings for the **bundleName**, **versionCode**, **versionName**, **minCompatibleVersionCode**, **minAPIVersion**, **targetAPIVersion**, and **apiReleaseType** fields in the configuration file. For details, see [Application- or Component-Level Configuration (FA Model)](../application-models/application-component-configuration-fa.md) or [Application- or Component-Level Configuration (Stage Model)](../application-models/application-component-configuration-stage.md).
  - Each HAP file must have a unique **moduleName** and a unique HAP of the Entry type for the same device.
  - For the FA model, the **package** field configured in the JSON file must be unique.
