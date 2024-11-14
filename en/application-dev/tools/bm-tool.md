# Bundle Manager

Bundle Manager (bm) is a tool for installing, uninstalling, updating, and querying bundles. It provides basic capabilities for debugging application installation packages.

## Environment Setup

Before using this tool, you must obtain <!--Del-->[<!--DelEnd-->hdc<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> and run the hdc shell command.


## bm Commands

| Name| Description|
| -------- | -------- |
| help | Displays the commands supported by the bm tool.|
| install | Installs a bundle.|
| uninstall | Uninstalls a bundle.|
| dump | Displays bundle information.|
| clean | Clears the cache and data of a bundle. This command is available in the root version. It is also available in the user version with developer mode enabled. It is unavailable in other cases.|
| <!--DelRow-->enable | Enables a bundle. A bundle can be used after being enabled. This command is available in the root version but not in the user version.|
| <!--DelRow-->disable | Disables a bundle. A bundle cannot be used after being disabled. This command is available in the root version but not in the user version.|
| get | Obtains the UDID of a device.|
| quickfix | Performs patch-related operations, such as installing or querying a patch.|
| compile | Executes the AOT compilation on a bundle.|
| copy-ap | Copies the .ap file of a bundle to the **/data/local/pgo** directory for the shell user to read the file.|
| dump-dependencies | Displays the information about the modules on which the bundle depends.|
| dump-shared | Displays the HSP information of a bundle.|
| dump-overlay | Displays **overlayModuleInfo** of an overlay bundle.|
| dump-target-overlay | Displays **overlayModuleInfo** of all overlay bundles associated with a target bundle.|


## help Command

```bash
# Display the help information.
bm help
```


## Installation Command

```bash
bm install [-h] [-p filePath] [-u userId] [-r] [-w waitingTime] [-s hspDirPath]
```

  **Parameters of the install command**


| Parameter| Description| 
| -------- | -------- | 
| -h | Displays help information.| 
| -p | Installs a HAP with other HAPs in the specified path. This parameter is mandatory.| 
| -u | Installs a HAP for a given user, which is the currently active user by default. This parameter is optional.  | 
| -r | Installs a HAP in overwrite mode. This parameter is optional. By default, the HAP is installed in overwrite mode.| 
| -s |  Installs an HSP. Each directory can have only one HSP with the same bundle name. This parameter is mandatory only for HSP installation.|
| -w | Waits for a specified time before installing a HAP. The minimum waiting time is 5s, and the maximum waiting time is 600s. The default waiting time is 5s. This parameter is optional.| 


Example
```bash
# Install a HAP.
bm install -p /data/app/ohos.app.hap
# Install a HAP in overwrite mode.
bm install -p /data/app/ohos.app.hap -r
# Install an HSP.
bm install -s xxx.hsp
# Install a HAP and its dependent HSP.
bm install -p aaa.hap -s xxx.hsp yyy.hsp
# Install a HAP for a specified user. The waiting time is 10s.
bm install -p /data/app/ohos.app.hap -u 100 -w 10
```

## uninstall

```bash
bm uninstall [-h] [-n bundleName] [-m moduleName] [-u userId] [-k] [-s] [-v versionCode]
```

  **Parameters of the uninstall command**

| Parameter| Description| 
| -------- | -------- | 
| -h | Displays help information.| 
| -n | Uninstalls a bundle. This parameter is mandatory.| 
| -m | Uninstalls a module. This parameter is optional. By default, all modules are uninstalled.| 
| -u | Uninstalls a bundle for a given user, which is the currently active user by default. This parameter is optional.  | 
| -k | Uninstalls a bundle with or without retaining the bundle data. This parameter is optional. By default, the bundle data is deleted along the uninstall.| 
| -s | Uninstalls an HSP. This parameter is mandatory only for the HSP installation.| 
| -v | Uninstalls an HSP of a given version number. This parameter is optional. By default, all shared bundles with the specified bundle name are uninstalled.|


Example

```bash
# Uninstall a bundle.
bm uninstall -n com.ohos.app
# Uninstall a module of a bundle.
bm uninstall -n com.ohos.app -m com.ohos.app.EntryAbility
# Uninstall a shared bundle.
bm uninstall -n com.ohos.example -s
# Uninstall a shared bundle of the specified version.
bm uninstall -n com.ohos.example -s -v 100001
# Uninstall a bundle and retain user data.
bm uninstall -n com.ohos.app -k
# Uninstall a module of a bundle for a specified user.
bm uninstall -n com.ohos.app -m com.ohos.app.EntryAbility -u 100 
```


## dump

```bash
bm dump [-h] [-a] [-n bundleName] [-s shortcutInfo] [-u userId] [-d deviceId]
```

  **Parameters of the dump command**

| Parameter| Description|
| -------- | -------- | 
| -h | Displays help information.| 
| -a | Displays all bundles installed in the system. This parameter is optional.| 
| -n | Displays the details of a bundle. This parameter is optional.|
| -s | Displays the shortcut information of a bundle. This parameter is optional.|
| -d | Displays the bundle information on a given device, which is the current device by default. This parameter is optional.  | 
| -u | Displays the bundle information for a given user. By default, the bundle information of all users is displayed. This parameter is optional.  | 


Example

```bash
# Display the names of all bundles installed in the system.
bm dump -a
# Display the details of a bundle.
bm dump -n com.ohos.app -u 100
# Display the shortcut information of a bundle.
bm dump -s -n com.ohos.app -u 100
# Display cross-device bundle information.
bm dump -n com.ohos.app -d xxxxx
```

## clean

```bash
bm clean [-h] [-c] [-n bundleName] [-d] [-u userId] [-i appIndex]
```
**Parameters of the clean command**

| Parameter| Description| 
| -------- | --------- | 
| -h | Displays help information.|
| -c -n | **-n** is mandatory, and **-c** is optional. Clears the cache data of a specified bundle.|
| -d -n | **-n** is mandatory, and **-d** is optional. Clears the data directory of a specified bundle.|
| -i | Clears the data directory of an application clone. This parameter is optional. The default value is 0.| 
| -u | Clears the cache data of a bundle for a specified user, which is the currently active user by default. This parameter is optional.  | 


Example

```bash
# Clear the cache data of a bundle.
bm clean -c -n com.ohos.app -u 100
# Clear the user data of a bundle.
bm clean -d -n com.ohos.app -u 100
// The execution result is as follows:
clean bundle data files successfully.
```

<!--Del-->
## enable

```bash
bm enable [-h] [-n bundleName] [-a abilityName] [-u userId]
```


  **Parameters of the enable command**

| Parameter| Description|
| -------- | -------- | 
| -h | Displays help information.|
| -n | Enables a specified bundle. This parameter is mandatory.|
| -a | Enables an ability with a specified bundle name. This parameter is optional.|
| -u | Enables a bundle for a specified user, which is the currently active user by default. This parameter is optional.  |


Example

```bash
# Enable a bundle.
bm enable -n com.ohos.app -a com.ohos.app.EntryAbility -u 100
// The execution result is as follows:
enable bundle successfully.
```


## disable

```bash
bm disable [-h] [-n bundleName] [-a abilityName] [-u userId]
```


  **Parameters of the disable command**

| Parameter| Description|
| -------- | -------- | 
| -h | Displays help information.| 
| -n | Disables a specified bundle. This parameter is mandatory.|
| -a | Disables an ability with a specified bundle name. This parameter is optional.|
| -u | Disables a bundle for a specified user, which is the currently active user by default. This parameter is optional.  | 


Example

```bash
# Disable a bundle.
bm disable -n com.ohos.app -a com.ohos.app.EntryAbility -u 100
// The execution result is as follows:
disable bundle successfully.
```
<!--DelEnd-->


## get

```bash
bm get [-h] [-u]
```

  **Parameters of the get command**

| Parameter| Description|
| -------- | -------- | 
| -h |Displays help information.| 
| -u |Obtains the UDID of a device. This parameter is mandatory.|


Example

```bash
# Obtain the UDID of a device.
bm get -u
// The execution result is as follows:
udid of current device is:
23CADE0C
```


## quickfix

```bash
bm quickfix [-h] [-a -f filePath [-t targetPath] [-d]] [-q -b bundleName] [-r -b bundleName] 
```

Note: For details about how to create an .hqf file, see [HQF Packing Command](packing-tool.md#hqf-packing-command).

  **Parameters of the quickfix command**
|   Parameter | Description|
| -------- | -------- | 
| -h | Displays help information.| 
| -a -f | **-a** is optional, and **-f** is mandatory when **-a** is specified. Executes the quick fix patch installation command. **file-path** corresponds to an .hqf file. You can pass in one or more .hqf files or the directory where the .hqf file is located.|
| -q -b | **-q** is optional, and **-b** is mandatory when **-q** is specified. Displays the patch information based on the bundle name.|
| -r&nbsp;-b | **-r** is optional, and **-b** is mandatory when **-r** is specified. Uninstalls a disabled patch based on the bundle name.|
| -t | Restores a bundle to a specified path.|
| -d | Selects the debug mode for quick fix. This parameter is optional.|



Example

```bash
# Display patch package information by the bundle name.
bm quickfix -q -b com.ohos.app
// The execution result is as follows:
// Information as follows:            
// ApplicationQuickFixInfo:           
//  bundle name: com.ohos.app 
//  bundle version code: xxx     
//  bundle version name: xxx       
//  patch version code: x            
//  patch version name:              
//  cpu abi:                          
//  native library path:             
//  type:                            
# Install a quick fix patch.
bm quickfix -a -f /data/app/
// The execution result is as follows:
apply quickfix succeed.
# Uninstall a quick fix patch.
bm quickfix -r -b com.ohos.app
// The execution result is as follows:
delete quick fix successfully
```

## dump-shared

```bash
bm dump-shared [-h] [-a] [-n bundleName] [-m moduleName]
```

  **Parameters of the dump-shared command**

| Parameter| Description|
| -------- | -------- | 
| -h | Displays help information.| 
| -a | Displays all shared libraries installed in the system. This parameter is optional.|
| -n | Displays details about a shared library. This parameter is optional.|
| -m | Displays details about the bundle name and module name of a specified shared library. This parameter is optional.|


Example

```bash
# Display the bundle names of all shared libraries installed in the system.
bm dump-shared -a
# Display the details about the specified shared library.
bm dump-shared -n com.ohos.lib
# Display information about the shared library on which a specified module of a bundle depends.
bm dump-dependencies -n com.ohos.app -m entry
```

## dump-dependencies

Displays information about the shared library on which a specified module of a bundle depends.
```bash
bm dump-dependencies [-h] [-n bundleName] [-m moduleName]
```

  **Parameters of the dump-dependencies command**
| Parameter| Description|
| -------- | -------- | 
| -h | Displays help information.| 
| -n | Displays details about a shared library. This parameter is mandatory.|
| -m | Displays information about the shared library on which a specified module of a bundle depends. This parameter is optional.|

Example
```Bash
# Display information about the shared library on which a specified module of a bundle depends.
bm dump-dependencies -n com.ohos.app -m entry
```


## compile

Executes the AOT compilation on a bundle.
```bash
bm compile [-h] [-m mode] [-r bundleName]
```
  **Parameters of the compile command**

| Parameter| Description|
| -------- | -------- | 
| -h | Displays help information.| 
| -a | Compiles all bundles. This parameter is optional.|
| -m | Compiles a bundle based on the bundle name. The value can be **partial** or **full**. This parameter is optional.|
| -r | Checks whether a bundle is removed. This parameter is optional.|

Example

```bash
# Compile a bundle based on the bundle name.
bm compile -m partial com.example.myapplication
```

## copy-ap

Copies an .ap file to the **/data/local/pgo** directory of a specified bundle.

```bash
bm copy-ap [-h] [-a] [-n bundleName]
```

**Parameters of the copy-ap command**

| Parameter| Description|
| -------- | -------- | 
| -h | Displays help information.| 
| -a | Copies the .ap files related to all bundles. By default, .ap files related to all bundles are copied. This parameter is optional.|
| -n | Copies the .ap file related to a specified bundle, which is the current bundle by default. This parameter is optional.|

Example

```bash
# Copy the .ap file related to a specified bundle.
bm copy-ap -n com.example.myapplication
```

## dump-overlay

Displays **overlayModuleInfo** of an overlay bundle.
```bash
bm dump-overlay [-h] [-b bundleName] [-m moduleName] [-u userId] [-t targetModuleName]
```

**Parameters of the dump-overlay command**
| Parameter| Description|
| -------- | -------- | 
| -h | Displays help information.| 
| -b | Displays all **OverlayModuleInfo** about a specified bundle. This parameter is mandatory.|
| -m | Displays **OverlayModuleInfo** based on a specified bundle name and module name. By default, **OverlayModuleInfo** of the main module of the current bundle is displayed. This parameter is optional.|
| -t | Displays **OverlayModuleInfo** based on a specified bundle name and target module name. This parameter is optional.|
| -u | Displays **OverlayModuleInfo** based on a specified bundle name, target module name, and user name, which is the currently active user by default. This parameter is optional.|

Example

```bash
# Display OverlayModuleInfo of an overlay bundle named com.ohos.app.
bm dump-overlay -b com.ohos.app

# Display OverlayModuleInfo of the overlay module named entry in an overlay bundle named com.ohos.app.
bm dump-overlay -b com.ohos.app -m entry

# Display OverlayModuleInfo of the overlay module named feature in an overlay bundle named com.ohos.app.
bm dump-overlay -b com.ohos.app -m feature
```

## dump-target-overlay

Displays **overlayModuleInfo** of all overlay bundles associated with a target bundle.

```bash
bm dump-target-overlay [-h] [-b bundleName] [-m moduleName] [-u userId]
```

**Parameters of the dump-target-overlay command**
| Parameter| Description|
| -------- | -------- | 
| -h | Displays help information.| 
| -b | Displays all **OverlayBundleInfo** about a specified bundle. This parameter is mandatory.|
| -m | Displays **OverlayBundleInfo** based on a specified bundle name and module name. By default, **OverlayBundleInfo** of the main module of the current bundle is displayed. This parameter is optional.|
| -u | Displays **OverlayBundleInfo** based on a specified bundle name, target module name, and user name, which is the currently active user by default. This parameter is optional.|

Example

```bash
# Display OverlayBundleInfo of an overlay bundle named com.ohos.app.
bm dump-target-overlay-b com.ohos.app

# Display OverlayModuleInfo of the overlay module named entry in an overlay bundle named com.ohos.app.
bm dump-target-overlay -b com.ohos.app -m entry
```

## Error Codes

### 9568320 The signature file does not exist
**Error Message**

Failed to install bundle, no signature file.
![Example](figures/en-us_image_0000001389116960.png)

**Symptom**

A user attempts to install an unsigned HAP file.

**Possible Causes**

The HAP file is not signed.

**Solution**

1. Use [automatic signing](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-signing-V5#section18815157237) to sign the HAP file after the device is connected.
2. Manually sign the HAP file. For details, see <!--RP1-->[Signing Your App/Service Manually](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-signing-V5#section297715173233)<!--RP1End-->.
<br></br>

### 9568347 The local .so file fails to be parsed
**Error Message**

Error: install parse native so failed.

**Symptom**

When you start debugging or running a C++ app/service, the error message "error: install parse native so failed" is displayed during HAP installation.

**Possible Causes**

The Application Binary Interface (ABI) supported by the device does not match that configured in the C++ project.

**Solution**

1. Connect the device to DevEco Studio.
2. Open the command line tool and go to the **toolchains\{*Version*}** directory in the OpenHarmony SDK installation directory.
    ```
    To check the OpenHarmony SDK installation directory, choose **File** > **Settings** > **SDK**.
    ```
3. Run the following command to obtain the list of ABI types supported by the device, which include one or more of the following: default, armeabi-v7a, armeabi, arm64-v8a, x86, and x86_64.
    ```
    hdc shell
    param get const.product.cpu.abilist
    ```
4. Based on the obtained list, modify the **abiFilters** settings in the [module-level build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-hvigor-compilation-options-customizing-sample-V5#section4322212200) file. The rules are as follows:
    * If the list includes only **default**, run the following command to check whether the **lib64** folder exists:
      ```
      cd /system/
      ls
      ```
      ![Example](figures/en-us_image_0000001609001262.png)
      * If the **lib64** folder exists, add the arm64-v8a type to **abiFilters**.
      * If the **lib64** folder does not exist, add armeabi, armeabi-v7a, or both types to **abiFilters**.
    * If the list includes one or more of the following, add at least one of them to **abiFilters**: armeabi-v7a, armeabi, arm64-v8a, x86, and x86_64.
<br></br>


### 9568344 The configuration file fails to be parsed
**Error Message**

Error: install parse profile prop check error.
![Example](figures/en-us_image_0000001585361412.png)

**Symptom**

When you start debugging or run an application, the error message "error: install parse profile prop check error" is displayed during the installation of the HAP.

**Possible Causes**

The application uses the privileges, but the new signature fingerprint is not added to the **install_list_capability.json** file of the device after the signature file of the application is changed.

**Solution**

1. Obtain the new signature fingerprint.

    a. Obtain the storage path of the signature file, which is the value of **profile** in the **signingConfigs** field in the [project-level build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-hvigor-compilation-options-customizing-sample-V5#section1448071082016) file.

    b. Open the signature file (with the file name extension .p7b), search for **development-certificate** in the file, copy **-----BEGIN CERTIFICATE-----**, **-----END CERTIFICATE-----**, and the information between them to a new text file, delete the newline characters, and save the file as a new .cer file.

    The format of the new .cer file is shown below. (The file content is an example.)

    ![Example](figures/en-us_image_0000001585521364.png)



    c. Use the keytool (available in the **jbr/bin** folder of the DevEco Studio installation directory) to obtain the SHA-256 value of the certificate fingerprint from the .cer file:
      ```
      keytool -printcert -file xxx.cer
      ```
    d. Remove the colon (:) from the SHA-256 content in the certificate fingerprint. What you get is the signature fingerprint.
    
    An example SHA-256 value is shown below.
    ![Example](figures/en-us_image_0000001635921233.png)

    The signature fingerprint obtained by removing the colon is 5753DDBC1A8EF88A62058A9FC4B6AFAFC1C5D8D1A1B86FB3532739B625F8F3DB.

2. Obtain the **install_list_capability.json** file of the device.

    a. Connect the device.

    b. Run the following command to view the **install_list_capability.json** file of the device:
    ```
    find /system -name install_list_capability.json
    ```
    The **install_list_capability.json** file of the device is stored in the following directory. Find the corresponding configuration file based on the bundle name.
    ```
    /system/etc/app/install_list_capability.json
    ```
    c. Run the following command to obtain the **install_list_capability.json** file:
    ```
    hdc shell mount -o rw,remount /
    hdc file recv /system/etc/app/install_list_capability.json
    ```

3. Add the signature fingerprint obtained to **app_signature** in the **install_list_capability.json** file. Note that the signature fingerprint must be configured under the corresponding bundle name.
![Example](figures/en-us_image_0000001635641893.png)
4. Push the modified **install_list_capability.json** file to the device and restart the device.

    ```
    hdc shell mount -o rw,remount / 
    hdc file send install_list_capability.json /system/etc/app/install_list_capability.json 
    hdc shell chmod 644 /system/etc/app/install_list_capability.json 
    hdc shell reboot
    ```
5. Reinstall the application.


### 9568305 The dependent module does not exist
**Error Message**

Error: dependent module does not exist.
![Example](figures/en-us_image_0000001560338986.png)

**Symptom**

When you start debugging or run an application, the error message "error: dependent module does not exist" is displayed during the installation of the HAP.

**Possible Causes**

The SharedLibrary module on which the application depends is not installed.

**Solution**

1. Install the dependent SharedLibrary module. On the **Run/Debug Configurations** page of DevEco Studio, select **Keep Application Data** on the **General** tab page, and click **OK** to save the configuration. Then run or debug the application again.
![Example](figures/en-us_image_0000001560201786.png)
2. On the **Run/Debug Configurations** page of DevEco Studio, click the **Deploy Multi Hap** tab, select **Deploy Multi Hap Packages**, select the dependent module SharedLibrary, and click **OK** to save the configuration. Then run or debug the application again.
![Example](figures/en-us_image_0000001610761941.png)


### 9568259 Some fields are missing in the configuration file
**Error Message**

Error: install parse profile missing prop.<br>
![Example](figures/en-us_image_0000001559130596.png)

**Symptom**

When you start debugging or run an application, the error message "error: install parse profile missing prop" is displayed during the installation of the HAP.

**Possible Causes**

Mandatory fields are missing in the **app.json5** and **module.json5** files.

**Solution**

* 1. Check and add mandatory fields by referring to the [app.json5 file](../quick-start/app-configuration-file.md) and [module.json5 file](../quick-start/module-configuration-file.md).
* 2. Determine the missing fields based on the HiLog.

    Run the following command to enable disk flushing:
    ```
    hilog -w start
    ```

    Disk location: /data/log/hilog

    Open the log file and find **profile prop %{public}s is mission**. For example, **profile prop icon is mission** indicates that the **icon** field is missing.


### 9568258 The release types of the new application and existing application are different
**Error Message**

Error: install releaseType target not same.<br>
![Example](figures/en-us_image_0000001609976041.png)

**Symptom**

When you start debugging or run an application, the error message "error: install releaseType target not same" is displayed during the installation of the HAP.

**Possible Causes**

The value of **releaseType** in the SDK used by the existing HAP is different from that used by the new HAP.

**Solution**

1. Uninstall the existing HAP on the device, and then install the new HAP.


### 9568322 The signature verification fails because the application source is untrusted
**Error Message**

Error: signature verification failed due to not trusted app source.
![Example](figures/en-us_image_0000001585042216.png)

**Symptom**

When you start debugging or run an application, the error message "error: signature verification failed due to not trusted app source" is displayed during the installation of the HAP.

**Possible Causes**

* Scenario 1: The signature does not contain the UDID of the debugging device.

* Scenario 2: The [release certificate and release profile](https://developer.huawei.com/consumer/en/doc/app/agc-help-releaseharmony-0000001933963166) is used during signature. However, an application signed by a release certificate cannot be debugged or run.

**Solution**

* Scenario 1:
	1. Use [automatic signing](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-signing-V5#section18815157237) to sign the HAP file after the device is connected.
	2. If manual signature is used, add the UDID of the device to the **UnsgnedDebugProfileTemplate.json** file. For details, see <!--RP2-->[hapsigner Guide](https://gitee.com/openharmony/docs/blob/master/en/application-dev/security/hapsigntool-guidelines.md)<!--RP2End-->.
		```
		// Command for obtaining the UDID
		hdc shell bm get -u
		```
* Scenario 2: Use the [debug certificate and debug profile](https://developer.huawei.com/consumer/en/doc/app/agc-help-debug-app-0000001914423098) to re-sign the application.


### 9568289 The installation fails because the permission request fails
**Error Message**

Error: install failed due to grant request permissions failed.
![Example](figures/en-us_image_0000001585201996.png)

**Symptom**

When you start debugging or run an application, the error message "error: install failed due to grant request permissions failed" is displayed during the installation of the HAP.

**Possible Causes**

The application uses the default Ability Privilege Level (APL), which is normal, and requires the system_basic or system_core permission.

**Solution**

1. Change the APL in the **UnsgnedDebugProfileTemplate.json** file to **system_basic** or **system_core**, and sign and pack the application again.


### 9568297 The installation fails because the SDK version of the device is too early
**Error Message**

Error: install failed due to older sdk version in the device.
![Example](figures/en-us_image_0000001635521909.png)

**Symptom**

When you start debugging or run an application, the error message "error: install failed due to older sdk version in the device" is displayed during the installation of the HAP.

**Possible Causes**

The SDK version used for build and packing does not match the device image version.

**Solution**

* Scenario 1: The device image version is earlier than the SDK version for build and packing. Update the device image version. Run the following command to query the device image version:
  ```
  hdc shell param get const.ohos.apiversion
  ```
  If the API version provided by the image is 10 and the SDK version used for application build is also 10, the possible cause is that the image version is too early to be compatible with the SDK verification rules of the new version. In this case, update the image version to the latest version.

* Scenario 2: For applications that need to run on OpenHarmony devices, ensure that runtimeOS has been changed to OpenHarmony.


### 9568332 The installation fails due to inconsistent signatures
**Error Message**

Error: install sign info inconsistent.
![Example](figures/en-us_image_0000001635761329.png)

**Symptom**

When you start debugging or run an application, the error message "error: install sign info inconsistent" is displayed during the installation of the HAP.

**Possible Causes**

The signatures of the existing application and new application are different, or the signatures of HAPs and HSPs are different. **Keep Application Data** is selected in **Edit Configurations** (the application installation is overwritten) and the application is re-signed.


**Solution**
zh-cn\application-dev\quick-start\integrated-hsp.md
1. Uninstall the application, or deselect **Keep Application Data**. Then install the new application.
2. If the signature inconsistency is caused by HSPs provided by different teams, use [integrated HSP](../quick-start/integrated-hsp.md). If there are multiple HAPs, ensure that their signatures are the same.

### 9568329 The signature information fails to be verified
**Error Message**

Error: verify signature failed.

![Example](figures/en_image_155401.png)

**Symptom**

The **bundleName** in the signature information is different from that of the application.

**Possible Causes**

* Scenario 1: An HSP module provided by a third party is imported, and the HSP is neither an [integrated HSP](../quick-start/integrated-hsp.md) nor an HSP with the same bundle name, causing the bundle name inconsistency.

* Scenario 2: An incorrect signature file (with the file name extension .p7b) is used for signature, causing the bundle name inconsistency.


**Solution**

* Scenario 1: Use an HSP only for the application with the same bundle name; use an integrated HSP for applications with different bundle names. Ask the third party to provide an integrated HSP or an HSP with the same bundle name.

* Scenario 2: Check the signing process and signing certificate. For details, see [Signing Your App/Service](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-signing-V5).


### 9568266 The installation permission is denied
**Error Message**

Error: install permission denied.
![Example](figures/en_image_9568266.png)

**Symptom**

When you run the **hdc install** command to install the HAP file, the error message "code:9568266 error: install permission denied" is displayed.

**Possible Causes**

The **hdc install** command cannot be used to install the enterprise application with a release signature.

**Solution**

1. Run the **hdc install** command to install and debug the enterprise application with a debug signature.


### 9568337 The installation parsing fails
**Error Message**

Error: install parse unexpected.

**Symptom**

When an application is pushed to a device, an error message is displayed, indicating that the HAP file fails to be opened.

**Possible Causes**

* Scenario 1: The storage space of the system partition is full. As a result, when you run the **hdc file send** command, files on the device are damaged due to insufficient storage space.

* Scenario 2: The HAP file is damaged when it is pushed to the device.

**Solution**

* 1. Check the storage space allocated to the system partition. If the storage space is full, clear the storage space to install the HAP file.
  ```bash
  hdc shell df -h /system
  ```

* 2. Check the MD5 values of the local HAP file and the HAP file pushed to the device. If they are different, the HAP is damaged during the push. In this case, push the file again.


### 9568316 The permission of APL in proxyData is low
**Error Message**

Error: apl of required permission in proxy data is too low.

**Symptom**

**requiredReadPermission** and **requiredWritePermission** of the **proxyData** tag in the **module.json** file fail to be verified.

**Possible Causes**

**requiredReadPermission** and **requiredWritePermission** can be configured only when the application has the permission level of **system_basic** or **system_core**.

**Solution**

1. Check whether the **proxyData** content defined by the application meets the requirements. For details, see [proxyData](../quick-start/module-configuration-file.md#proxydata).


### 9568315 The URI in proxy data is incorrect
**Error Message**

Error: uri in proxy data is wrong.

**Symptom**

**uri** of the **proxyData** tag in the **module.json** file fails to be verified.

**Possible Causes**

The format of **uri** does not meet the requirement.

**Solution**

1. Check whether the **proxyData** content defined by the application meets the requirements. For details, see [proxyData](../quick-start/module-configuration-file.md#proxydata).


### 9568336 The debugging type of the application is different from that of the installed application
**Error Message**

Error: install debug type not same.

**Symptom**

The debugging type (the **debug** field in the **app.json** file) of the application is different from that of the installed application.

**Possible Causes**

You have installed the application using the **Debug** button of DevEco Studio, and then you install the HAP file of the application by running the **hdc install** command.

**Solution**

1. Uninstall the existing application and install the new application.
   

### 9568296 The bundle type is incorrect
**Error Message**

Error: install failed due to error bundle type.

**Symptom**   

The installation fails because the **bundleType** tag is incorrect.

**Possible Causes**

The **bundleType** of the application to be installed is different from that of an existing application with the same **bundleName**.
       
**Solution**

* Method 1. Uninstall the existing application and install the application again.

* Method 2: Set the **bundleType** of the application to the same as that of the existing application.


### 9568292 The user with UserID 0 can install only the singleton application
**Error Message**

Error: install failed due to zero user can only install singleton app.

**Symptom**

The user with **UserID 0** is only allowed to install the application with the **singleton** permission, and the application with the **singleton** permission is only allowed to be installed by the user with **UserID 0**.

**Possible Causes**

**UserID** is not set to **0** for the application with the **singleton** permission.

**Solution**

1. If the application has the **singleton** permission, set **UserID** to **0** during installation.
	```
	// Set the user ID to 0.
	hdc install -p <HAP file name>.hap -u 0
	```


### 9568263 The installation version cannot be downgraded
**Error Message**

Error: install version downgrade.

**Symptom**

The installation fails because **versionCode** of the application to be installed is earlier than that of the existing application.

**Possible Causes**

The **versionCode** of the application to be installed is earlier than that of the existing application.

**Solution**

1. Uninstall the existing application and install the new application.


### 9568304 The application does not support the current device type
**Error Message**

Error: device type is not supported.

**Symptom**

The installation fails because the application does not support the current device type.

**Possible Causes**

The application does not support the current device type.

**Solution**

1. To adapt to the current device, add the current device type to the value of **deviceTypes** of the application. The value of **deviceTypes** can be any of the following: phone, tablet, 2in1, tv, wearable, and car.


### 9568317 The multi-process configuration of the application does not match the system configuration
**Error Message**

Error: isolationMode does not match the system.

**Symptom**

The installation fails because **isolationMode** of the application is not supported by the system.

**Possible Causes**

* 1. The device supports the isolation mode (the value of **persist.bms.supportIsolationMode** is **true**), whereas the value of **isolationMode** in the HAP is **nonisolationOnly**.

* 2. The device does not support the isolation mode (the value of **persist.bms.supportIsolationMode** is **false**), whereas the value of **isolationMode** in the HAP is **isolationOnly**.

**Solution**

1. Set the value of **isolationMode** in the HAP configuration file based on the isolation mode of the device. 
	```
	// Query the value of persist.bms.supportIsolationMode. If errNum is:106 is returned, persist.bms.supportIsolationMode is not configured.
	hdc shell
	param get persist.bms.supportIsolationMode
	// Set persist.bms.supportIsolationMode.
	hdc shell
	param set persist.bms.supportIsolationMode [true|false]
	```


### 9568315 The URI attribute of the proxy data is incorrect
**Error Message**

Error: uri in proxy data is wrong.

**Symptom**

**uri** of the **proxyData** tag in the **module.json** file fails to be verified.

**Possible Causes**

The format of **uri** does not meet the requirements.

**Solution**

1. Ensure that the URI meets the format requirements.
	```
	// URI format specifications:
	The URI of a data proxy must be unique and must be in the format of datashareproxy://bundleName/xxx.
	```


### 9568310 The compatibility policies are different     
**Error Message**

Error: compatible policy not same.

**Symptom**

The compatibility policy of the new bundle is different from that of the existing bundle.

**Possible Causes**

A HAP with the same name has been installed on the device.

**Solution**

1. Uninstall the HAP with the same name and install the new HAP.


### 9568391 The bundle manager service is stopped     
**Error Message**

Error: bundle manager service is died.

**Symptom**

The bundle manager service is stopped.

**Possible Causes**

When you run the **bm install -p ***.hap** command to install a pre-installed application, the running application is killed, causing an exception (for example, the foundation process restarts).

**Solution**

1. Install the pre-installed applications by referring to the OTA upgrade guide.


### 9568393 The code signature fails to be verified     
**Error Message**

Error: verify code signature failed.

**Symptom**

The code signature fails to be verified.

**Possible Causes**

* 1. The package does not contain code signature information.

* 2. The signing certificate is incorrect.


**Solution**

* 1. Use the signing tool SDK to check whether the package is signed.
	```
	// Verify the signature.
	java -jar SDK installation path (SDK in the DevEco Studio installation directory) \toolchains\lib\hap-sign-tool.jar verify-app -outCertChain out.cer -outProfile out.p7b -inFile package path\**.hap
	// 1. If "is can not find codesign block" is returned, the package is not signed.
	// 2. If "verify codesign success," is returned, the package is signed.
	```

* Scenario 2: Check the signing process and signing certificate. For details, see [Signing Your App/Service](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-signing-V5).


### 9568257 A PKCS7 file failed to be verified     
**Error Message**

Error: fail to verify pkcs7 file.

**Symptom**

A PKCS7 file failed to be verified.

**Possible Causes**

The signature used by the application does not meet the signature requirements for the HarmonyOS application. Generally, the signature for OpenHarmony applications is used and should be replaced with the signature for HarmonyOS applications.

**Solution**

1. Select **Support HarmonyOS** during the process of signing your application/service. After the HarmonyOS application is signed, debug or run the application again.
![Example](figures/en_image_9868257_1.png)

### 9568401 The bundle to debug can run only on devices in developer mode     
**Error Message**

Error: debug bundle can only be installed in developer mode.

**Symptom**

The bundle to debug can run only on devices in developer mode.

**Possible Causes**

Developer mode is not enabled on the device.

**Solution**

1. Choose **Settings** > **System** and check whether **Developer options** is available. If not, go to **Settings** > **About** and touch the version number for seven consecutive times until the message "Enable developer mode?" is displayed. Touch **OK** and enter the PIN (if set). Then the device will automatically restart.
2. Connect the device to the PC using a USB cable. Choose **Settings** > **System** > **Developer options** and enable USB debugging. In the displayed dialog box, touch **Allow**.
3. Start debugging or run the application.

### 9568386 The bundle cannot be found for uninstallation     
**Error Message**

Error: uninstall missing installed bundle.

**Symptom**

The bundle cannot be found for uninstallation.

**Possible Causes**

The application is not completely uninstalled, and residual resources exist.

**Solution**

1. Delete all resources that are not uninstalled in **el1** and **el2**.
2. Install the application again.


### 9568284 The installation version is not compatible     
**Error Message**

Error: install version not compatible.

**Symptom**

The installation version is not compatible.

**Possible Causes**

The version of the installed HSP does not match that of the installed HAP.
When an HSP is installed, the following information is verified:
1. bundleName
2. Version
3. Signature

**Solution**

1. Uninstall the HAP whose version does not match and then install the HSP.
2. Change the HSP version to be the same as that of the HAP and install the HSP again.

### 9568287 The number of entry modules in the installation package is invalid     
**Error Message**

Error: install invalid number of entry hap.

**Symptom**

The number of entry modules in the installation package is invalid.

**Possible Causes**

There are multiple entry modules in the installation package. An application can have only one entry module but multiple feature modules.

**Solution**

1. Retain one entry module and change the other entry modules to feature modules (by modifying the **type** field in **module.json5**).


### 9568281 The **vendor** field of the installation package is inconsistent     
**Error Message**

Error: install vendor not same.

**Symptom**

The **vendor** field of the installation package is inconsistent.

**Possible Causes**

The **vendor** field of the application in the **app.json5** file is inconsistent.

**Solution**

1. If only a HAP is involved, the **vendor** field of the HAP must be the same as that of the installed application. In this case, uninstall and reinstall the HAP.
2. If an integrated HSP is included, the **vendor** field of the integrated HSP must be the same as that of the HAP.


### 9568279 The version name used for installation is inconsistent     
**Error Message**

Error: install version name not same.

**Symptom**

The version name used for installation is inconsistent.

**Possible Causes**

* Scenario 1: If only a HAP file is involved, the version of the application to install is inconsistent with the application for which the data is saved.

* Scenario 2: If an HSP and a HAP are involved, the bundle name, version number, SDK version number, and release type of the HSP are different from those of the HAP.

**Solution**

* Scenario 1: Deselect **Keep Application Data** on the entry configuration page of DevEco Studio.
![Example](figures/en_image_9568279.png)

* Scenario 2: Ensure that the bundle name, version number, SDK version number, and release type of the HSP are the same as those of the HAP.


### 9568274 An error occurs during service installation     
**Error Message**

Error: install installd service error.

**Symptom**

An error occurs during service installation.

**Possible Causes**

An exception occurs during service installation.

**Solution**

1. Clear the cache and restart the device.


### 9568314 An HSP fails to be installed     
**Error Message**

Error: Failed to install the HSP because installing a shared bundle specified by hapFilePaths is not allowed.

**Symptom**

An HSP fails to be installed.

**Possible Causes**

The HSP is installed by running the **hdc app install ***** command.

**Solution**

1. Run the **hdc install -s ***** command to install the HSP.


### 9568359 The SELinux fails to be installed and set     
**Error Message**

Error: installd set selinux label failed.

**Symptom**

The SELinux fails to be installed and set.

**Possible Causes**

The **apl** field in the signature configuration file is incorrect. It can be **normal**, **system_basic**, and **system_core**.

**Solution**

1. Check whether the **apl** field in the .p7b file is correct.                                  
![Example](figures/en_image_9568359.png)
2. If the **apl** field is incorrect, modify the **apl** field in the **UnsgnedReleasedProfileTemplate.json** file and sign the file again.
![Example](figures/en_image_9568359_2.png)


### 9568403 The encryption check fails during the installation     
**Error Message**

Error: check encryption failed.

**Symptom**

The encryption check fails during the installation.

**Possible Causes**

The image version is too early or the **lib** directory of the HAP contain non-so files.

**Solution**

1. Install a new image version.
2. Delete non-so files in the **lib** directory of the HAP project and re-sign and package the files.
