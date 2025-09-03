# Bundle Manager
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

Bundle Manager (bm) is a tool for installing, uninstalling, updating, and querying bundles. It provides basic capabilities for debugging application installation packages.

## Environment Requirements (hdc)

Before using this tool, you need to obtain the [hdc tool](../dfx/hdc.md) and run the hdc shell.

## bm Commands

| Name| Description|
| -------- | -------- |
| help | Displays the commands supported by the bm tool.|
| install | Installs a bundle.|
| uninstall | Uninstalls a bundle.|
| dump | Displays bundle information.|
| clean | Clears the cache and data of a bundle. <!--Del--> This command is available in the root version and <!--DelEnd--&gt. This command is available in the user version when the developer mode is enabled.|
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
| install-plugin | Installs a plug-in.|
| uninstall-plugin | This command is used to uninstall a plug-in.|


## help

```bash
# Display the help information.
bm help
```


## install

```bash
bm install [-h] [-p filePath] [-r] [-w waitingTime] [-s hspDirPath] [-u userId]
```

  **Parameters**


| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -p | Installs a HAP in a specified path or multiple HAPs in a specified directory. This parameter is mandatory.|
| -r | Installs a HAP in overwrite mode. This parameter is optional. By default, the HAP is installed in overwrite mode.|
| -s |  Installs an HSP. Each directory can have only one HSP with the same bundle name. This parameter is mandatory only for the HSP installation.|
| -w | Waits for a specified time before installing a HAP. The minimum waiting time is 5s, and the maximum waiting time is 600s. The default waiting time is 5s. This parameter is optional.|
| -u | (Optional) Specified user. By default, the app is installed under the current active user. The installation can be performed only by the current active user or user 0.<br>**NOTE**<br> If the number of current active users is 100, the application is installed only under the current active user 100 when the `bm install -p /data/local/tmp/ohos.app.hap -u 102` command is used for installation.|


Example
```bash
# Install a HAP.
bm install -p /data/local/tmp/ohos.app.hap
# Install a HAP for 100 users.
bm install -p /data/local/tmp/ohos.app.hap -u 100
# Install a HAP in overwrite mode.
bm install -p /data/local/tmp/ohos.app.hap -r
# Install an HSP.
bm install -s xxx.hsp
# Install a HAP and its dependent HSP.
bm install -p aaa.hap -s xxx.hsp yyy.hsp
# Install both the HAP and in-app shared library.
bm install -p /data/local/tmp/hapPath/
# Install a HAP. The waiting time is 10s.
bm install -p /data/local/tmp/ohos.app.hap -w 180
```

## uninstall

```bash
bm uninstall [-h] [-n bundleName] [-m moduleName] [-k] [-s] [-v versionCode] [-u userId]
```

  **Parameters**

| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -n | Uninstalls a bundle. This parameter is mandatory.|
| -m | Specifies the name of an application module to be uninstalled. This parameter is optional. By default, all modules are uninstalled.|
| -k | Uninstalls a bundle with or without retaining the bundle data. This parameter is optional. By default, the bundle data is deleted along the uninstall.|
| -s |  Uninstalls an HSP. This parameter is mandatory only for the HSP installation.|
| -v | Uninstalls an HSP of a given version number. This parameter is optional. By default, all shared bundles with the specified bundle name are uninstalled.|
| -u | (Optional) Specified user. By default, the app is uninstalled under the current active user. The app can be uninstalled only by the current active user or 0 user.<br>**NOTE**<br> If the number of current active users is 100, the `bm uninstall -n com.ohos.app -u 102` command uninstalls applications only under the current active user 100.|


Example

```bash
# Uninstall a bundle.
bm uninstall -n com.ohos.app
# Uninstall an application under the user 100
bm uninstall -n com.ohos.app -u 100
# Uninstall a module of a bundle.
bm uninstall -n com.ohos.app -m entry
# Uninstall a shared bundle.
bm uninstall -n com.ohos.example -s
# Uninstall a shared bundle of the specified version.
bm uninstall -n com.ohos.example -s -v 100001
# Uninstall a bundle and retain user data.
bm uninstall -n com.ohos.app -k
```


## dump

```bash
bm dump [-h] [-a] [-g] [-n bundleName] [-s shortcutInfo] [-d deviceId] [-l label] [-u userId]
```

  **Parameters**

| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -a | Displays all bundles installed in the system. This parameter is optional.|
| -g | Displays the names of bundles whose signatures are of the debug type. This parameter is optional.|
| -n | Displays the details of a bundle. This parameter is optional.|
| -s | Displays the shortcut information of a bundle. This parameter is optional.|
| -d | Displays the bundle information on a given device, which is the current device by default. This parameter is optional.  |
| -l | (Optional) Queries the label value (application name) of a specified bundle name. This parameter must be used together with `-n` or `-a`.<br>**Note:**<br>This command is supported since API version 20. If the command output in the Windows environment contains special characters or garbled Chinese characters, run the `chcp 65001` command on the CLI to change the CLI code to UTF-8.|
| -u | (Optional) Queries application information of a specified user. By default, application information of the current active user is queried. The query can be performed only by the current active user or user 0.<br>**NOTE**<br> If the number of current active users is 100, applications are queried only under the current active user 100 when the `bm dump -n com.ohos.app -u 102` command is used for uninstallation.|


Example

```bash
# Display the names of all bundles installed in the system.
bm dump -a
# Display the names of bundles whose signatures are of the debug type in the system.
bm dump -g
# Display the details of a bundle.
bm dump -n com.ohos.app
# Query detailed information about the application under the user 100.
bm dump -n com.ohos.app -u 100
# Display the shortcut information of a bundle.
bm dump -s -n com.ohos.app
# Display cross-device bundle information.
bm dump -n com.ohos.app -d xxxxx
# Query the label value (application name) of the application.
bm dump -n com.ohos.app -l
# Displays the bundle names and label values (application names) of all installed applications.
bm dump -a -l
```

## clean

```bash
bm clean [-h] [-c] [-n bundleName] [-d] [-i appIndex] [-u userId]
```
**Parameters**

| Parameter| Description|
| -------- | --------- |
| -h | Displays help information.|
| -c -n | **-n** is mandatory, and **-c** is optional. Clears the cache data of a specified bundle.|
| -d -n | **-n** is mandatory, and **-d** is optional. Clears the data directory of a specified bundle.|
| -i | Clears the data directory of an application clone. This parameter is optional. The default value is 0.|
| -u | (Optional) Clears data of a specified user. By default, data of the current active user is cleared. Data can be deleted only for the current active user or user 0.<br>**NOTE**<br> If the number of current active users is 100, the `bm clean -c -n com.ohos.app -u 102` command deletes data only of the current active user 100.|


Example

```bash
# Clear the cache data of a bundle.
bm clean -c -n com.ohos.app
# Clear the cache data of the application under the user 100
bm clean -c -n com.ohos.app -u 100
# Clear the user data of a bundle.
bm clean -d -n com.ohos.app
# Execution result
clean bundle data files successfully.
```

<!--Del-->
## enable

```bash
bm enable [-h] [-n bundleName] [-a abilityName] [-u userId]
```


  **Parameters**

| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -n | Enables a specified bundle. This parameter is mandatory.|
| -a | Enables an ability with a specified bundle name. This parameter is optional.|
| -u | (Optional) Enables the application of a specified user. By default, the application is enabled for the current active user. Applications can be enabled only for active users or 0 users.<br>**NOTE**<br> If the number of current active users is 100 and the `bm enable -n com.ohos.app -u 102` command is run to enable an application, the application is enabled only for the current active user 100.|


Example

```bash
# Enable a bundle.
bm enable -n com.ohos.app -a com.ohos.app.EntryAbility
# Enable the application under the user 100.
bm enable -n com.ohos.app -u 100
# Execution result
enable bundle successfully.
```


## disable

```bash
bm disable [-h] [-n bundleName] [-a abilityName] [-u userId]
```


  **Parameters**

| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -n | Disables a specified bundle. This parameter is mandatory.|
| -a | Disables an ability with a specified bundle name. This parameter is optional.|
| -u | (Optional) Disables applications of a specified user. By default, applications of the current active user are disabled. Applications can be disabled only by the current active user or user 0.<br>**NOTE**<br> If the current active user is 100 and the `bm disable -n com.ohos.app -u 102` command is used to disable an application, the application is disabled only under the current active user 100.|


Example

```bash
# Disable a bundle.
bm disable -n com.ohos.app -a com.ohos.app.EntryAbility
# Disable the application under the user 100.
bm disable -n com.ohos.app -u 100
# Execution result
disable bundle successfully.
```
<!--DelEnd-->


## get

```bash
bm get [-h] [-u]
```

  **Parameters**

| Parameter| Description|
| -------- | -------- |
| -h |Displays help information.|
| -u | Obtains the UDID of a device. This parameter is mandatory.|


Example

```bash
# Obtain the UDID of a device.
bm get -u
# Execution result
udid of current device is:
23CADE0C
```


## quickfix

```bash
bm quickfix [-h] [-a -f filePath [-t targetPath] [-d] [-o]] [-q -b bundleName] [-r -b bundleName]
```

Note: For details about how to create an .hqf file, see [HQF Packing Command](packing-tool.md#hqf-packing-command).

  **Parameters**
|   Parameter | Description|
| -------- | -------- |
| -h | Displays help information.|
| -a -f | **-a** is optional, and **-f** is mandatory when **-a** is specified. Executes the quick fix patch installation command. **file-path** corresponds to an .hqf file. You can pass in one or more .hqf files or the directory where the .hqf file is located.|
| -q -b | **-q** is optional, and **-b** is mandatory when **-q** is specified. Displays the patch information based on the bundle name.|
| -r&nbsp;-b | **-r** is optional, and **-b** is mandatory when **-r** is specified. Uninstalls a disabled patch based on the bundle name.|
| -t | Fixes a bundle to a specified path. This parameter is optional.|
| -d | Selects the debug mode for quick fix. This parameter is optional.|
| -o | Selects the overwrite mode for quick fix. In this mode, the .so file is decompressed and overwritten in the .so directory of the bundle. This parameter is optional.|



Example

```bash
# Display patch package information by the bundle name.
bm quickfix -q -b com.ohos.app
# Execution result
# Information as follows:
# ApplicationQuickFixInfo:
#  bundle name: com.ohos.app
#  bundle version code: xxx
#  bundle version name: xxx
#  patch version code: x
#  patch version name:
#  cpu abi:
#  native library path:
#  type:

# Install a quick fix patch.
bm quickfix -a -f /data/app/
# Execution result
apply quickfix succeed.
# Uninstall a quick fix patch.
bm quickfix -r -b com.ohos.app
# Execution result
delete quick fix successfully
```

## dump-shared

```bash
bm dump-shared [-h] [-a] [-n bundleName] [-m moduleName]
```

  **Parameters**

| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -a | Displays all HSPs in the system. This parameter is optional.|
| -n | Displays detailed information about the shared library with a specified bundle name. This parameter is optional.|
| -m | Displays detailed information about the shared library with a specified bundle name and module name. This parameter is optional.|


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

```bash
bm dump-dependencies [-h] [-n bundleName] [-m moduleName]
```

**Parameters**
| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -n | Displays information about the shared library on which a specified bundle depends. This parameter is mandatory.|
| -m | Displays information about the shared library on which a specified module of a bundle depends. This parameter is optional.|

Example
```Bash
# Display information about the shared library on which a specified module of a bundle depends.
bm dump-dependencies -n com.ohos.app -m entry
```


## compile

```bash
bm compile [-h] [-m mode] [-r bundleName] [-a]
```
**Parameters**

| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -a | Compiles all bundles. This parameter is optional.|
| -m |  Compiles a bundle based on the bundle name. The value can be **partial** or **full**. This parameter is optional.|
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

**Parameters**

| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -a |  Copies the .ap files related to all bundles. By default, .ap files related to all bundles are copied. This parameter is optional.|
| -n |  Copies the .ap file related to a specified bundle, which is the current bundle by default. This parameter is optional.|

Example

```bash
# Copy the .ap file related to a specified bundle.
bm copy-ap -n com.example.myapplication
```

## dump-overlay

```bash
bm dump-overlay [-h] [-b bundleName] [-m moduleName] [-u userId]
```

**Parameters**
| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -b | Displays all **OverlayModuleInfo** about a specified overlay bundle. This parameter is mandatory.|
| -m | By default, the name of the main module of the current overlay bundle is used. This parameter is optional. Displays **OverlayModuleInfo** about a specified overlay bundle based on the bundle name and module name.|
| -u | (Optional) Specifies the user whose OverlayModuleInfo information is to be queried. By default, the information is queried by the current active user. The query can be performed only by the current active user or user 0.<br>**NOTE**<br> If the number of current active users is 100, run the `bm dump-overlay -b com.ohos.app -u 102` command to query the OverlayModuleInfo information. Only the OverlayModuleInfo information of the current active user 100 is returned.|

Example

```bash
# Display OverlayModuleInfo of an overlay bundle named com.ohos.app.
bm dump-overlay -b com.ohos.app

# Under the user 100, obtain all OverlayModuleInfo information in the overlay application com.ohos.app based on the bundle name.
bm dump-overlay -b com.ohos.app -u 100

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

**Parameters**
| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -b | Displays all **OverlayBundleInfo** about a specified bundle. This parameter is mandatory.|
| -m |  Displays **OverlayModuleInfo** based on a specified bundle name and module name. By default, **OverlayModuleInfo** of the main module of the current bundle is displayed. This parameter is optional.|
| -u | (Optional) Specifies the user whose OverlayModuleInfo information is to be queried. By default, the information is queried by the current active user. The query can be performed only by the current active user or user 0.<br>**NOTE**<br> If the number of current active users is 100, run the `bm dump-target-overlay -b com.ohos.app -u 102` command to query all associated OverlayBundleInfo information in the target application com.ohos.app. Only the OverlayModuleInfo information of the current active user 100 is returned.|

Example

```bash
# Display OverlayBundleInfo of an overlay bundle named com.ohos.app.
bm dump-target-overlay -b com.ohos.app

# Under the user 100, obtain all associated OverlayBundleInfo information in the target application com.ohos.app based on the bundle name
bm dump-target-overlay -b com.ohos.app -u 100

# Display OverlayModuleInfo of the overlay module named entry in an overlay bundle named com.ohos.app.
bm dump-target-overlay -b com.ohos.app -m entry
```

## Installing a Plug-in (install-plugin)

```bash
bm install-plugin [-h] [-n hostBundleName] [-p filePath]
```

**Parameters in the install-plugin command**
| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -n | Specifies the app bundle name of the plug-in to be installed. This parameter is mandatory.|
| -p | Specifies the plug-in file path. This parameter is mandatory.|

Example

```bash
# Install a plug-in.
bm install-plugin -n com.ohos.app -p /data/plugin.hsp
```
> **NOTE**
>
> If the same plug-in is installed in the same application, the plug-in version is updated and the plug-in cannot be downgraded. After the plug-in version is updated, you need to restart the application plug-in for the update to take effect.
>
> You are not advised to install a plugin with the same name as the host application module. Currently, this plugin is not supported in the runtime state.


## Uninstalling a Plug-in (uninstall-plugin)

```bash
bm uninstall-plugin [-h] [-n hostBundleName] [-p pluginBundleName]
```

**Parameters in the uninstall-plugin command**
| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -n | Specifies the app bundle name. This parameter is mandatory.|
| -p | Specifies the bundle name of a plug-in. This parameter is mandatory.|

Example

```bash
# Uninstall a plug-in.
bm uninstall-plugin -n com.ohos.app -p com.ohos.plugin
```


## Error Codes

### 301 System Account Does Not Exist
**Error Message**

error: user not exist.

**Symptom**

The system account does not exist.

**Possible Causes**

The system account ID does not exist during application installation.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
hdc file recv /data/log/hilog/
```

### 304 The HAP Package Is Not Installed for the Current System Account
**Error Message**

error: user does not install the hap.

**Symptom**

During the uninstallation, the HAP package is not installed for the current system account.

**Possible Causes**

No HAP package is installed under the current system account.

**Solution**

No HAP package is installed under the current system account. Do not uninstall the app.

### 9568319 Signature File Exception
**Error Message**

error: cannot open signature file.

**Symptom**

During application installation, the signature file fails to be opened. As a result, the installation fails.

**Possible Causes**

The signature file of the HAP package is abnormal.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

### 9568320 The Signature File Does Not Exist
**Error Message**

error: no signature file.

**Symptom**

A user attempts to install an unsigned HAP file.

**Possible Causes**

The HAP file is not signed.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

### 9568321 Failed to Parse the Signature File
**Error Message**

error: fail to parse signature file.

**Symptom**

Failed to parse the signature file during installation.

**Possible Causes**

The signature file of the HAP package is abnormal.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

### 9568323 Signature Digest Verification Failed
**Error Message**

error: signature verification failed due to not bad digest.

**Symptom**

Signature verification failed during installation.

**Possible Causes**

The signature of the HAP package is incorrect.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

### 9568324 Signature Integrity Verification Failed
**Error Message**

error: signature verification failed due to out of integrity.

**Symptom**

Signature verification failed during installation.

**Possible Causes**

The signature of the HAP package is incorrect.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

### 9568326 The Signature Public Key Is Abnormal
**Error Message**

error: signature verification failed due to bad public key.

**Symptom**

Signature verification failed during installation. The signature public key is abnormal.

**Possible Causes**

The signature of the HAP package is incorrect.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

### 9568327 Failed to Obtain the Signature
**Error Message**

error: signature verification failed due to bad bundle signature.

**Symptom**

Failed to verify the signature during installation. The signature cannot be obtained.

**Possible Causes**

The signature of the HAP package is incorrect.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

### 9568328 The Configuration File Block Is Not Found
**Error Message**

error: signature verification failed due to no profile block.

**Symptom**

Failed to verify the signature during installation. The configuration file block is not found.

**Possible Causes**

The signature of the HAP package is incorrect.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

### 9568330 Failed to Initialize the Signature Source
**Error Message**

error: signature verification failed due to init source failed.

**Symptom**

Failed to verify the signature during installation and failed to initialize the signature source.

**Possible Causes**

The signature of the HAP package is incorrect.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

### 9568257 Failed to Verify the Signature File Pkcs7

**Error Message**

error: fail to verify pkcs7 file.

**Symptom**

The signature PKCS7 verification fails when the user installs the app.

**Possible Causes**

1. The certificate chain is incomplete or untrusted.
2. The signature algorithm does not match.
3. The data is tampered with or the signature file is damaged.
4. The signature format does not match.
5. The private key does not match.

**Solution**

1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. Manual signature. For details, see [Manual Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).


### 9568344 The Configuration File Fails to Be Parsed
**Error Message**

error: install parse profile prop check error.

![Example](figures/en-us_image_0000001585361412.png)

**Symptom**

When you start debugging or run an application, the error message "error: install parse profile prop check error" is displayed during the installation of the HAP.

**Possible Causes**

1. The **bundleName** in the [app.json5 configuration file](../quick-start/app-configuration-file.md#tags-in-the-configuration-file) and **name** in the [module.json5 configuration file](../quick-start/module-configuration-file.md#tags-in-the-configuration-file) are invalid.

<!--Del-->
2. The **type** field in [extensionAbilities](../quick-start/module-configuration-file.md#extensionabilities) is set to **service** or **dataShare**.
<!--DelEnd-->


**Solution**
1. Modify the **bundleName** field in the app.json5 configuration file and the **name** field in the module.json5 file based on the naming rule.
<!--Del-->
2. If the **type** field in **extensionAbilities** is set to **service** or **dataShare**, set [allowAppUsePrivilegeExtension](../../device-dev/subsystems/subsys-app-privilege-config-guide.md) for the application as follows:

    1. Obtain the new signature fingerprint.

        a. In the project-level **build-profile.json5** file (in the root directory of the project), obtain the value of **profile** in the **signingConfigs** field, which is the storage path of the signature file.

        b. Open the signature file (with the file name extension .p7b), search for **development-certificate** in the file, copy **-----BEGIN CERTIFICATE-----**, **-----END CERTIFICATE-----**, and the information between them to a new text file, delete the newline characters, and save the file as a new .cer file.

        The format of the new .cer file is shown below. (The file content is an example.)

        ![Example](figures/en-us_image_0000001585521364.png)

        c. Use the keytool (available in the **jbr/bin** folder of the DevEco Studio installation directory) to obtain the SHA-256 value of the certificate fingerprint from the .cer file:
          ```
          keytool -printcert -file xxx.cer
          ```
        d. Remove colons (:\) from the SHA-256 content in the certificate fingerprint. What you get is the signature fingerprint.

        The following figure shows an example.

        ![Example](figures/en-us_image_0000001635921233.png)

        After colons are removed, the obtained signature fingerprint is **5753DDBC1A8EF88A62058A9FC4B6AFAFC1C5D8D1A1B86FB3532739B625F8F3DB**.

    2. Obtain the **install_list_capability.json** file of the device.

        a. Connect to the device and enter the shell.
        ```
        hdc shell
        ```
        b. Run the following command to view the **install_list_capability.json** file of the device:
        ```
        // Locate the file on the device.
        find /system -name install_list_capability.json
        ```
        c. Run the following command to obtain the **install_list_capability.json** file:
        ```
        hdc target mount
        hdc file recv /system/etc/app/install_list_capability.json
        ```

    3. Add the signature fingerprint obtained to **app_signature** in the **install_list_capability.json** file. Note that the signature fingerprint must be configured under the corresponding bundle name.
    ![Example](figures/en-us_image_0000001635641893.png)
    4. Push the modified **install_list_capability.json** file to the device and restart the device.

        ```
        hdc target mount
        hdc file send install_list_capability.json /system/etc/app/install_list_capability.json
        hdc shell chmod 644 /system/etc/app/install_list_capability.json
        hdc shell reboot
        ```
    5. Reinstall the application.<!--DelEnd-->


### 9568305 The Dependent Module Does Not Exist
**Error Message**

error: dependent module does not exist.

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
3. Choose **Run** > **Edit Configurations**. On the **General** tab page, select **Auto Dependencies**. Click **OK** to save the configuration, and then run or debug the project.
![Example](figures/en-us_image_9568305.png)

### 9568259 Some Fields Are Missing in the Configuration File
**Error Message**

error: install parse profile missing prop.

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

    Disk location: **/data/log/hilog**

    Open the log file and find **profile prop %{public}s is mission**. For example, **profile prop icon is mission** indicates that the **icon** field is missing.


### 9568258 The Release Types of the New Application and Existing Application Are Different
**Error Message**

error: install releaseType target not same.

![Example](figures/en-us_image_0000001609976041.png)

**Symptom**

When you start debugging or run an application, the error message "error: install releaseType target not same" is displayed during the installation of the HAP.

**Possible Causes**

* Scenario 1: The value of **releaseType** in the SDK used by the existing HAP is different from that used by the new HAP.
* Scenario 2: When the application has multiple HAPs, the **releaseType** values in the SDK used by each HAP are different.

**Solution**

* Scenario 1: Uninstall the existing HAP on the device and then install a new HAP.
* Scenario 2: Use the same SDK to repackage the HAPs to ensure that the **releaseType** values of multiple HAPs are the same.


### 9568260 Internal Installation Error
**Error Message**

error: install internal error.

**Symptom**

An internal error occurs during the installation.

**Possible Causes**

An internal service exception occurs during the installation.

**Solution**

Restart the device and try again.


### 9568267 The entry Module Already Exists
**Error Message**

error: install entry already exist.

**Symptom**

The entry module of the application to be installed already exists.

**Possible Causes**

The entry module must be unique for multi-module application installation. The name of the module package to be installed is different from that of the installed module package, but both are of the entry type, which violates the entry uniqueness. As a result, the installation fails.

**Solution**

1. Uninstall the existing HAP on the device, and then install the new HAP.
2. Ensure that the name of the entry module in the installation package is the same as that of the installed entry module, or change the type of the module to be installed to feature and try again.


### 9568268 Incorrect Installation Status
**Error Message**

error: install state error.

**Symptom**

Failed to update the application installation status.

**Possible Causes**

The previous app installation package is too large and takes a long time. During app installation, the previous app installation task is not complete. As a result, the installation status fails to be updated.

**Solution**

Wait until the previous app is installed and try again.


### 9568269 Invalid File Path
**Error Message**

error: install file path invalid.

**Symptom**

The installation package path input during installation is invalid.

**Possible Causes**

1. The installation package path does not exist. For example, the spelling is incorrect.
2. The length of the installation package path exceeds 256 bytes.

**Solution**

1. Check whether the path of the installation package exists and whether you have the permission to access the path.
2. Verify that the length of the installation package path does not exceed 256 bytes.

### 9568322 The Signature Verification Fails Because the Application Source Is Untrusted
**Error Message**

error: signature verification failed due to not trusted app source.

![Example](figures/en-us_image_0000001585042216.png)

**Symptom**

When you start debugging or run an application, the error message "error: signature verification failed due to not trusted app source" is displayed during the installation of the HAP.

**Possible Causes**

<!--RP8-->
<!--RP8End-->The signature does not contain the UDID of the debugging device.



**Solution**

<!--RP9-->
<!--RP9End-->
1. Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237). after the device is connected.
2. If manual signature is used, add the UDID of the device to the **UnsgnedDebugProfileTemplate.json** file. For details, see <!--RP2-->[hapsigner Guide](https://gitee.com/openharmony/docs/blob/master/en/application-dev/security/hapsigntool-guidelines.md)<!--RP2End-->.

    1. Obtain the UDID of the device.

    ```
      // Command for obtaining the UDID
      hdc shell bm get -u
    ```

    2. Go to the DevEco Studio installation path and open the **UnsgnedDebugProfileTemplate.json** configuration file in the SDK directory.

    ```
      DevEco Studio installation path\sdk\version number or default\openharmony\toolchains\lib\

      Example: xxxx\Huawei\DevEco Studio\sdk\HarmonyOS-NEXT-DB1\openharmony\toolchains\lib\
      Example: xxxx\Huawei\DevEco Studio\sdk\default\openharmony\toolchains\lib\
    ```

    3. Add the UDID of the device to the **device-ids** field in the **UnsgnedDebugProfileTemplate.json** file.

3. Use the text editor to open the signed HAP and search for device-ids to check whether the signature contains the UDID of the debugging device.

### 9568286 The Type of the Signing Certificate Profile of the New Application Is Different from That of the Existing Application
**Error Message**

error: install provision type not same.

**Symptom**

When you start debugging or run an app/service, the type in the <!--RP5--> [profile signature file](../security/app-provision-structure.md)<!--RP5End--> of the installed app is different from that of the installed app. As a result, an error occurs during HAP installation.

**Possible Causes**

The type in the signing certificate profile of the new application is different from that of the existing application.

**Solution**

1. Ensure that the type of the signing certificate profile of the new application is the same as that of the existing application, and install the new HAP.
2. Uninstall the existing application and install the new HAP.


### 9568288 Installation Failure Due to Insufficient Disk Space
**Error Message**

error: install failed due to insufficient disk memory.

**Symptom**

During app installation, a file or directory is created. However, the file or directory fails to be created due to insufficient storage space. As a result, the app fails to be installed.

**Possible Causes**

Failed to create the file or directory due to insufficient storage space.

**Solution**

Check the storage space on your device and clear it to ensure that the space is sufficient for installing the app. Then install the app again.
<!--RP4-->
```bash
# Check the disk space usage.
hdc shell df -h /system
hdc shell df -h /data
```
<!--RP4End-->


### 9568289 The Installation Fails Because the Permission Request Fails
**Error Message**

error: install failed due to grant request permissions failed.

![Example](figures/en-us_image_0000001585201996.png)

**Symptom**

When you start debugging or run an application, the error message "error: install failed due to grant request permissions failed" is displayed during the installation of the HAP.

**Possible Causes**

The application uses the default Ability Privilege Level (APL), which is normal, and requires the system_basic or system_core permission.

**Solution**

Apply for restricted ACL permissions for the application by referring to [ACL Signature Guide](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section157591551175916).


### 9568290 Installation Failed Because the HAP Token Fails to Be Updated
**Error Message**

error: install failed due to update hap token failed.

**Symptom**

During application installation, the application token fails to be authorized when HAP is updated.

**Possible Causes**

During application installation or update, the token update API of the ability is called, but the API returns a failure message.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
hdc file recv /data/log/hilog/
```


<!--Del-->
### 9568291 Installation Failure Due to Singleton Inconsistency
**Error Message**

error: install failed due to singleton not same.

**Symptom**

During application update, the singleton configuration (discarded since API version 9) in the HAP package installed for the application is inconsistent with that in the app.json5 configuration file of the update package.

**Possible Causes**

The singleton configuration (discarded since API version 9) in the app.json5 configuration file of the installed HAP package is inconsistent with that in the app.json5 configuration file of the update package.

**Solution**

Solution 1: Uninstall the existing application package and install a new one.

Solution 2: Adjust the singleton configuration in the update package to be the same as that in the existing installation package. Package the app again and then update the app package.<!--DelEnd-->

<!--Del-->
### 9568294 Installation Failure Due to Inconsistent Application Types
**Error Message**

error: install failed due to apptype not same.

**Symptom**

During application installation, the [app-feature](../security/app-provision-structure.md) configuration in the signature file of the installed HAP package is inconsistent with that in the signature file of the HAP package to be installed. As a result, the installation fails.

**Possible Causes**

The name of the installed HAP package is the same as that of the to-be-installed HAP package, but the app-feature configuration in the signature file is different.

**Solution**

* Solution 1: Uninstall the existing HAP package and install the new HAP package.
* Solution 2: Modify the app-feature column in the signature file of the HAP package to be installed to ensure that the configuration of the app-feature column is the same as that of the existing installation package. Then, package and sign the [app/service signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing) again, and install the package again.<!--DelEnd-->

### 9568297 The Installation Fails Because the SDK Version of the Device Is Too Early
**Error Message**

error: install failed due to older sdk version in the device.

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


### 9568300 Installation Failed Because the Application Module Name Is Not Unique
**Error Message**

error: moduleName is not unique.

**Symptom**

During the installation of a multi-module application, the module name conflict occurs, and the module uniqueness verification fails. As a result, the installation fails.

**Possible Causes**

During the installation of a multi-module application, a module name conflict occurs.

**Solution**

Check the names of all modules of the current app and compare them with the names in the module.json5 file of each module. If they are inconsistent, package the app again and install it.



### 9568332 The Installation Fails Due to Inconsistent Signatures
**Error Message**

error: install sign info inconsistent.

![Example](figures/en-us_image_0000001635761329.png)

**Symptom**

When you start debugging or run an application, the error message "error: install sign info inconsistent" is displayed during the installation of the HAP.

**Possible Causes**

1. The signatures of the existing application and new application are different, or the signatures of HAPs and HSPs are different. If at least one of the signature [key](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section462703710326) or <!--RP7--&gt of two applications and the app-identifier<!--RP7End--&gt in the [profile signature file](../security/app-provision-structure.md) of the two applications is the same, the signatures of the two applications are considered to be the same. **Keep Application Data** is selected in **Edit Configurations** (the application installation is overwritten) and the application is re-signed.
2. If an application is uninstalled but its data is kept, and a new application with the same bundle name is later installed, it is necessary to check whether the identity details match. This error is reported if the values of [key](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section462703710326) and <!--RP7--&gt in the signature information and the value of app-identifier<!--RP7End--&gt in the [profile signature file](../security/app-provision-structure.md) are different.


**Solution**

1. Uninstall the application, or deselect **Keep Application Data**. Then install the new application.
2. If the signature inconsistency is caused by HSPs provided by different teams, use [integrated HSP](../quick-start/integrated-hsp.md). If there are multiple HAPs, ensure that their signatures are the same.
3. If an application is uninstalled but its data is kept, a new application with the same bundle name but different signature information fails to be installed. To install the new application, you must first reinstall the uninstalled application and uninstall it without retaining the data.

### 9568329 The Signature Information Fails to Be Verified
**Error Message**

error: verify signature failed.

![Example](figures/en_image_155401.png)

**Symptom**

The **bundleName** in the signature information is different from that of the application.

**Possible Causes**

* Scenario 1: An HSP module provided by a third party is imported, and the HSP is neither an [integrated HSP](../quick-start/integrated-hsp.md) nor an HSP with the same bundle name, causing the bundle name inconsistency.

* Scenario 2: An incorrect signature file (with the file name extension .p7b) is used for signature, causing the bundle name inconsistency.


**Solution**

* Scenario 1: Use an HSP only for the application with the same bundle name; use an integrated HSP for applications with different bundle names. Ask the third party to provide an integrated HSP or an HSP with the same bundle name.

* Scenario 2: Check the signing process and signing certificate. For details, see [App/FA Signing](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing).


### 9568266 The Installation Permission Is Denied
**Error Message**

error: install permission denied.

![Example](figures/en_image_9568266.png)

**Symptom**

When you run the **hdc install** command to install the HAP file, the error message "code:9568266 error: install permission denied" is displayed.

**Possible Causes**

The **hdc install** command cannot be used to install the enterprise application with a release signature.

**Solution**

1. Run the **hdc install** command to install and debug the enterprise application with a debug signature.


### 9568337 The Installation Parsing Fails
**Error Message**

error: install parse unexpected.

**Symptom**

When an application is pushed to a device, an error message is displayed, indicating that the HAP file fails to be opened.

**Possible Causes**

* Scenario 1: The storage space of the system partition is full. As a result, when you run the **hdc file send** command, files on the device are damaged due to insufficient storage space.

* Scenario 2: The HAP file is damaged when it is pushed to the device.

**Solution**

* 1. Check the storage space allocated to the system partition. If the storage space is full, clear the storage space to install the HAP file.
<!--RP4-->
  ```bash
  hdc shell df -h /system
  ```
<!--RP4End-->

* 2. Check the MD5 values of the local HAP file and the HAP file pushed to the device. If they are different, the HAP is damaged during the push. In this case, push the file again.


### 9568316 The Permission of APL in ProxyData Is Low
**Error Message**

error: apl of required permission in proxy data is too low.

**Symptom**

**requiredReadPermission** and **requiredWritePermission** of the **proxyData** tag in the **module.json** file fail to be verified.

**Possible Causes**

**requiredReadPermission** and **requiredWritePermission** can be configured only when the application has the permission level of **system_basic** or **system_core**.

**Solution**

1. Check whether the **proxyData** content defined by the application meets the requirements. For details, see [proxyData](../quick-start/module-configuration-file.md#proxydata).


### 9568315 The URI in Proxy Data Is Incorrect
**Error Message**

error: uri in proxy data is wrong.

**Symptom**

**uri** of the **proxyData** tag in the **module.json** file fails to be verified.

**Possible Causes**

The format of **uri** does not meet the requirement.

**Solution**

1. Check whether the **proxyData** content defined by the application meets the requirements. For details, see [proxyData](../quick-start/module-configuration-file.md#proxydata).


### 9568336 The Debugging Type of the Application Is Different From That of the Installed Application
**Error Message**

error: install debug type not same.

**Symptom**

The debugging type (the **debug** field in the **app.json** file) of the application is different from that of the installed application.

**Possible Causes**

You have installed the application using the **Debug** button of DevEco Studio, and then you install the HAP file of the application by running the **hdc install** command.

**Solution**

1. Uninstall the existing application and install the new application.


### 9568296 The Bundle Type Is Incorrect
**Error Message**

error: install failed due to error bundle type.

**Symptom**

The installation fails because the **bundleType** tag is incorrect.

**Possible Causes**

The **bundleType** of the application to be installed is different from that of an existing application with the same **bundleName**.

**Solution**

* Method 1. Uninstall the existing application and install the application again.

* Method 2: Set the **bundleType** of the application to the same as that of the existing application.


### 9568292 The User With UserID 0 Can Install Only the Singleton Application
**Error Message**

error: install failed due to zero user can only install singleton app.

**Symptom**

The UserID 0 user can install only the singleton permission application.

**Possible Causes**

The UserID 0 user has installed an application that does not have the singleton permission.

**Solution**

1. If the application does not have the singleton permission, you do not need to specify a user and can directly install the application.
	```bash
	hdc shell bm install -p /data/hap name.hap
	```


### 9568263 The Installation Version Cannot Be Downgraded
**Error Message**

error: install version downgrade.

**Symptom**

The installation fails because **versionCode** of the application to be installed is earlier than that of the existing application.

**Possible Causes**

The **versionCode** of the application to be installed is earlier than that of the existing application.

**Solution**

1. Uninstall the existing application and install the new application.


### 9568301 Module Type Inconsistent
**Error Message**

error: moduleName is inconsistent.

**Symptom**

The name of the module that is being installed already exists in the system, but the module name is inconsistent. As a result, the installation fails.

**Possible Causes**

The name of the application module to be installed already exists in the system, but the module type is inconsistent. As a result, the installation fails.

**Solution**

Check whether the module name of the installed application is the same as the name of the module to be installed. If the module names are the same but the types are different, modify the type attribute in the module.json5 file of the corresponding module.


<!--Del-->
### 9568302 Installation Failure Due to Inconsistent singletons of Multiple Modules of the Application
**Error Message**

error: install failed due to singleton not same.

**Symptom**

The singleton configurations (API 9 is marked as discarded) of multiple modules of the application are inconsistent. As a result, the installation fails.

**Possible Causes**

When multiple application modules are installed, the singleton configurations are different. As a result, the singleton consistency check fails, and the installation fails.

**Solution**

Adjust the singleton configuration of all modules to ensure that the configuration is consistent before the installation.<!--DelEnd-->


### 9568303 Enterprise Device Management Forbidden
**Error Message**

error: Failed to install the HAP because the installation is forbidden by enterprise device management.

**Symptom**

Installation failed because an application control policy exists.

**Possible Causes**

An application control policy exists.

**Solution**

Due to enterprise management and control, no solution is available. Submit an online [service ticket](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.


### 9568304 The Application Does Not Support the Current Device Type
**Error Message**

error: device type is not supported.

**Symptom**

The installation fails because the application does not support the current device type.

**Possible Causes**

The application does not support the current device type.

**Solution**

1. To adapt to the current device, add the current device type to the value of **deviceTypes** of the application. The value of **deviceTypes** can be any of the following: phone, tablet, 2in1, tv, wearable, and car.


### 9568308 Inconsistent App Package Type
**Error Message**

error: install bundleType not same.

**Symptom**

The application package types are inconsistent. As a result, the installation fails.

**Possible Causes**

When a multi-HAP application is installed, the bundleType attributes of two modules are inconsistent.

**Solution**

Check and ensure that the bundleType attributes in the app.json5 file of each module in the multi-HAP application are the same.


<!--Del-->
### 9568309 Unable to Install Inter-App HSP
**Error Message**

error: Failed to install the HSP due to the lack of required permission.

**Symptom**

The inter-application HSP installation fails due to lack of privileges.

**Possible Causes**

Lack of privileges when installing the inter-application HSP.

**Solution**

Check whether the application in the install_list_capability.json file on the device has the AllowAppShareLibrary permission. For details about how to configure the permission, see [Application Privilege Configuration Guide](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).


### 9568311 The Inter-Application HSP to Be Uninstalled Does Not Exist
**Error Message**

error: shared bundle is not exist.

**Symptom**

Failed to uninstall the inter-application HSP because the specified package does not exist.

**Possible Causes**

When the inter-application HSP is uninstalled, the specified package does not exist.

**Solution**

Check whether the inter-application HSP to be uninstalled exists.
```
hdc shell bm dump-shared -n com.xxx.xxx.demo
```


### 9568312 The Uninstalled Application HSP Is Dependent
**Error Message**

error: The version of the shared bundle is dependent on other applications.

**Symptom**

When the inter-application HSP is uninstalled, the specified package is depended on by another application. As a result, the uninstallation fails.

**Possible Causes**

When the inter-application HSP is uninstalled, the specified package is depended on by other applications.

**Solution**

Check whether other applications depend on the HSP of the application to be uninstalled. If yes, uninstall the applications that depend on the HSP first.<!--DelEnd-->


### 9568317 The Multi-Process Configuration of the Application Does Not Match the System Configuration
**Error Message**

error: isolationMode does not match the system.

**Symptom**

The installation fails because **isolationMode** of the application is not supported by the system.

**Possible Causes**

* 1. The device supports the isolation mode (the value of **persist.bms.supportIsolationMode** is **true**), whereas the value of **isolationMode** in the HAP is **nonisolationOnly**.

* 2. The device does not support the isolation mode (the value of **persist.bms.supportIsolationMode** is **false**), whereas the value of **isolationMode** in the HAP is **isolationOnly**.

**Solution**

1. Set the value of **isolationMode** in the HAP configuration file based on the isolation mode of the device.
	```bash
	# Query the value of persist.bms.supportIsolationMode. If errNum is:106 is returned, persist.bms.supportIsolationMode is not configured.
	hdc shell
	param get persist.bms.supportIsolationMode
	# Set persist.bms.supportIsolationMode.
	hdc shell
	param set persist.bms.supportIsolationMode [true|false]
	```


### 9568310 The Compatibility Policies Are Different
**Error Message**

error: compatible policy not same.

**Symptom**

The compatibility policy of the new bundle is different from that of the existing bundle.

**Possible Causes**

1. The shared library to be installed has the same bundle name as the existing bundle.
2. The bundle to be installed has the same bundle name as the existing shared library.

**Solution**

1. Uninstall the installed bundle or shared library, and install the new bundle.


### 9568391 The Bundle Manager Service Is Stopped
**Error Message**

error: bundle manager service is died.

**Symptom**

The bundle manager service is stopped.

**Possible Causes**

An unknown system exception occurs.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after the preceding steps are performed for three to five times, check whether a crash file containing **foundation** exists in the **/data/log/faultlog/faultlogger/** directory of the device.

  ```
  hdc shell
  cd /data/log/faultlog/faultlogger/
  ls -ls
  ```

3. Export the crash file and log file and submit them to [online tickets](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

  ```
  hdc file recv /data/log/faultlog/faultlogger/
  hdc file recv /data/log/hilog/
  ```

### 9568393 The Code Signature Fails to Be Verified
**Error Message**

error: verify code signature failed.

**Symptom**

The code signature fails to be verified.

**Possible Causes**

The bundle does not contain code signature information.

**Solution**

1. Install the latest version of DevEco Studio and sign the code again.

<!--RP3--><!--RP3End-->

### 9568399 Failed to Copy Files

**Error Message**

error: copy file failed.

**Symptom**

Files fail to be copied during application installation.

**Possible Causes**

1. The source file path or destination path to be copied is invalid.
2. Failed to open the source file.
3. Failed to obtain the source file status.
4. The size of the source file is invalid.
6. Failed to copy the source file.
7. You do not have the permission to access the source file.
8. Failed to change the file permission.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
hdc file recv /data/log/hilog/
```

### 9568401 The Bundle to Debug Can Run Only on Devices in Developer Mode
**Error Message**

error: debug bundle can only be installed in developer mode.

**Symptom**

The bundle to debug can run only on devices in developer mode.

**Possible Causes**

Developer mode is not enabled on the device.

**Solution**

1. Choose **Settings** > **System** and check whether **Developer options** is available. If not, go to **Settings** > **About** and touch the version number for seven consecutive times until the message "Enable developer mode?" is displayed. Touch **OK** and enter the PIN (if set). Then the device will automatically restart.
2. Connect the device to the PC using a USB cable. Choose **Settings** > **System** > **Developer options** and enable USB debugging. In the displayed dialog box, touch **Allow**.
3. Start debugging or run the application.

### 9568404 Failed to Transfer the Signature Configuration File

**Error Message**

error: delivery sign profile failed.

**Symptom**

During the installation, an exception occurs when the code signature configuration file is transferred. As a result, the installation fails.

**Possible Causes**

1. The file path does not exist.
2. Failed to create the file path.
3. Failed to change the file directory mode.
4. Failed to write the configuration file data.
5. Failed to change the configuration file mode.
6. Failed to add the configuration file data.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
hdc file recv /data/log/hilog/
```

### 9568405 Failed to Delete the Signature Configuration File

**Error Message**

error: remove sign profile failed.

**Symptom**

An exception occurs when the signature configuration file is deleted during app uninstallation. As a result, the app fails to be uninstalled.

**Possible Causes**

1. The file path does not exist.
2. Failed to load the configuration file data.
3. The file permission is not writable.

**Solution**

1. Restart your phone and uninstall the app again.

2. If the uninstallation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online service ticket](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
hdc file recv /data/log/hilog/
```

### 9568386 The Bundle Cannot Be Found for Uninstallation
**Error Message**

error: uninstall missing installed bundle.

**Symptom**

The bundle cannot be found for uninstallation.

**Possible Causes**

The bundle to be uninstalled is not installed.

**Solution**

1. Check whether the bundle to be uninstalled has been installed.

### 9568388 Bundle Uninstall Is Not Allowed by Enterprise Device Management
**Error Message**

error: Failed to uninstall the HAP because the uninstall is forbidden by enterprise device management.

**Symptom**

The enterprise device management does not allow the uninstall of this bundle.

**Possible Causes**

The bundle is set not to be uninstalled.

**Solution**

1. The enterprise device management cancels the uninstallation control of the bundle.

### 9568389 Installation Failure Due to an Unknown Error
**Error Message**

error: unknown.

**Symptom**

This error code is reported if an unknown error occurs.

**Possible Causes**

The installation fails due to an unknown system error.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

### 9568284 The Installation Version Is Not Compatible
**Error Message**

error: install version not compatible.

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

### 9568287 The Number of Entry Modules in the Installation Package Is Invalid
**Error Message**

error: install invalid number of entry hap.

**Symptom**

The number of entry modules in the installation package is invalid.

**Possible Causes**

There are multiple entry modules in the installation package. An application can have only one entry module but multiple feature modules.

**Solution**

1. Retain one entry module and change the other entry modules to feature modules (by modifying the **type** field in **module.json5**).


### 9568281 The vendor Field of the Installation Package Is Inconsistent
**Error Message**

error: install vendor not same.

**Symptom**

The **vendor** field of the installation package is inconsistent.

**Possible Causes**

The **vendor** field of the application in the **app.json5** file is inconsistent.

**Solution**

1. If only a HAP is involved, the **vendor** field of the HAP must be the same as that of the installed application. In this case, uninstall and reinstall the HAP.
2. If an integrated HSP is included, the **vendor** field of the integrated HSP must be the same as that of the HAP.

### 9568272 Invalid Installation Package Size
**Error Message**

error: install invalid hap size.

**Symptom**

The size of the installation package exceeds the upper limit.

**Possible Causes**

The size of the installation package exceeds 4 GB.

**Solution**

Split the package and ensure that the size of each installation package does not exceed 4 GB.

### 9568273 Failed to Install the Application Because the UID Fails to Be Generated
**Error Message**

error: install generate uid error.

**Symptom**

The application fails to generate the UID. As a result, the installation fails.

**Possible Causes**

The number of applications installed on the device exceeds 65,535. As a result, the UID fails to be allocated during application installation.

**Solution**

Uninstall unnecessary apps and try again.

### 9568274 An Error Occurs During Service Installation
**Error Message**

error: install installd service error.

**Symptom**

An error occurs during service installation.

**Possible Causes**

An exception occurs during service installation.

**Solution**

1. Clear the cache and restart the device.


### 9568275 Package Management Service Error

**Error Message**

error: install bundle mgr service error.

**Symptom**

Package management service error.

**Possible Causes**

The package management service is abnormal. For example, a null pointer occurs.

**Solution**

Restart the device or try again later.

### 9568277 Installation Failure Due to Inconsistent Package Names

**Error Message**

error: install bundle name not same.

**Symptom**

The package names are inconsistent. As a result, the installation fails.

**Possible Causes**

The names of multiple installation packages in the installation path are different.

**Solution**

Check the names of the installation packages in the installation path and ensure that the values of bundleName in the app.json5 configuration files of all installation packages are the same.


### 9568279 Installation Failure Due to Version Inconsistency

**Error Message**

error: install version name not same.

**Symptom**

The versions (versionName column) are inconsistent. As a result, the installation fails.

**Possible Causes**

The version names of multiple installation packages in the installation path are different.

**Solution**

Check the versions of the installation packages in the installation path and ensure that the values of versionName in the app.json5 configuration files of all installation packages are the same.

### 9568280 Installation Failure Due to Inconsistent minCompatibleVersionCode

**Error Message**

error: install min compatible version code not same.

**Symptom**

The minCompatibleVersionCode column is inconsistent. As a result, the installation fails.

**Possible Causes**

The minCompatibleVersionCode values of multiple installation packages in the installation path are different.

**Solution**

Check the installation packages in the installation path and ensure that the minCompatibleVersionCode values in the app.json5 configuration files of all installation packages are the same.

### 9568282 Installation Failed Due to Inconsistent targetAPIVersions

**Error Message**

error: install releaseType target not same.

**Symptom**

The targetAPIVersion column is inconsistent. As a result, the installation fails.

**Possible Causes**

The targetAPIVersion values of multiple installation packages in the installation path are different.

**Solution**

Check the installation packages in the installation path and ensure that the targetAPIVersion values in the app.json5 configuration files of all installation packages are the same.

### 9568314 The HSP Fails to Be Installed
**Error Message**

error: Failed to install the HSP because installing a shared bundle specified by hapFilePaths is not allowed.

**Symptom**

The HSP fails to be installed.

**Possible Causes**

The HSP is installed by running the **hdc app install ***** command.

**Solution**

1. Run the **hdc install -s ***** command to install the HSP.


### 9568349 Input Parameter Error During File Operation
**Error Message**

error: installd param error.

**Symptom**

The input parameter is abnormal during file operation. As a result, the installation fails.

**Possible Causes**

During the installation, the input parameter is invalid or the input directory is empty.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
# Export the log file.
hdc file recv /data/log/hilog/
```


### 9568351 Installation Failure Due to an Exception in Creating a File Directory
**Error Message**

error: installd create dir failed.

**Symptom**

An exception occurs during file directory creation. As a result, the installation fails.

**Possible Causes**

You do not have the write permission when creating a file directory.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
# Export the log file.
hdc file recv /data/log/hilog/
```


### 9568354 Installation Failed Due to an Exception in Deleting a File Directory
**Error Message**

error: installd remove dir failed.

**Symptom**

The installation fails because the file directory fails to be deleted.

**Possible Causes**

The directory to be deleted does not exist, or the current directory does not have the write permission.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
# Export the log file.
hdc file recv /data/log/hilog/
```


### 9568355 Failed to Extract Files from the Installation Package
**Error Message**

error: installd extract files failed.

**Symptom**

Files fail to be extracted from the installation package. As a result, the installation fails.

**Possible Causes**

During the installation, the directory for decompressing the .so file fails to be created. As a result, the .so file fails to be extracted from the HAP package.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
# Export the log file.
hdc file recv /data/log/hilog/
```


### 9568356 Failed to Rename a Directory During Installation
**Error Message**

error: installd rename dir failed.

**Symptom**

The installation fails because the directory name fails to be renamed.

**Possible Causes**

During the installation, the directory name contains more than 260 characters, or the current directory does not have the write permission.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
# Export the log file.
hdc file recv /data/log/hilog/
```

### 9568357 Failed to Delete Files
**Error Message**

error: installd clean dir failed.

**Symptom**

The installation fails because files fail to be deleted.

**Possible Causes**

During the installation, the files to be deleted do not have the write permission. As a result, the files fail to be deleted.

**Solution**

1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
# Export the log file.
hdc file recv /data/log/hilog/
```


### 9568359 The SELinux Fails to be Installed and Set
**Error Message**

error: installd set selinux label failed.

**Symptom**

The SELinux fails to be installed and set.

**Possible Causes**

The **apl** field in the signature configuration file is incorrect. It can be **normal**, **system_basic**, and **system_core**.

**Solution**

1. Check whether the **apl** field in the .p7b file is correct.

    ![Example](figures/en_image_9568359.png)

2. If the **apl** field is incorrect, modify the **apl** field in the **UnsgnedReleasedProfileTemplate.json** file and sign the file again.

    ![Example](figures/en_image_9568359_2.png)

### 9568398 The Enterprise Bundle Is Not Allowed to Be Installed on Non-Enterprise Devices
**Error Message**

error: Failed to install the HAP because an enterprise normal/MDM bundle cannot be installed on non-enterprise device.

**Symptom**

Do not install applications of the enterprise_mdm or enterprise_normal type in <!--RP5--> [Profile signature file](../security/app-provision-structure.md)<!--RP5End--> on non-enterprise devices.

**Possible Causes**

The device is not an enterprise device.

**Solution**

1. Install the enterprise bundle on the enterprise device.

### 9568402 The release Bundle of the app_gallery Type Cannot Be Installed
**Error Message**

error: Release bundle can not be installed.

**Symptom**

Do not run the bm command to install apps whose type is app_gallery and signature certificate type is release in <!--RP5--> [Profile signature file](../security/app-provision-structure.md)<!--RP5End-->.

**Possible Causes**

Install the app. The type in <!--RP5--> [Profile signature file](../security/app-provision-structure.md)<!--RP5End--> is app_gallery and the signature certificate type is release.

**Solution**

1. Use a file whose type is not app_gallery in <!--RP5--> [profile signature file](../security/app-provision-structure.md)<!--RP5End--> to re-sign the app.
2. Use the **debug** certificate to re-sign the bundle.

### 9568403 The Encryption Check Fails During the Installation
**Error Message**

error: check encryption failed.

**Symptom**

The encryption check fails during the installation.

**Possible Causes**

The image version is too early or the **lib** directory of the HAP contain non-so files.

**Solution**

1. Install a new image version.
2. Delete non-so files in the **lib** directory of the HAP project and re-sign and package the files.

### 9568407 Failed to Install the Native Software Package
**Error Message**

error: Failed to install the HAP because installing the native package failed.

**Symptom**

The native software package fails to be installed during HAP installation.

**Possible Causes**

The native software package to be installed in the HAP is damaged.

**Solution**

1. Check the native software package in the HAP, replace the native software package with the correct one, and re-sign and package the software package. For details, see [Native Software Package Development Guide](https://gitee.com/openharmony/startup_appspawn/tree/master/service/hnp).

### 9568408 Failed to Uninstall the Native Software Package
**Error Message**

error: Failed to uninstall the HAP because uninstalling the native package failed.

**Symptom**

The native software package fails to be uninstalled during HAP uninstall.

**Possible Causes**

The native software package to be uninstalled is occupied.

**Solution**

1. Check whether any process occupies the native software package. If yes, stop the process and uninstall the native software package again. For details, see [Native Software Package Development Guide](https://gitee.com/openharmony/startup_appspawn/tree/master/service/hnp).

### 9568409 Failed to Extract the Native Software Package
**Error Message**

error: Failed to install the HAP because the extract of the native package failed.

**Symptom**

The native software package fails to be extracted during the HAP installation.

**Possible Causes**

The native software package configured in **module.json5** does not exist in the HAP.

**Solution**

1. Check the native software package directory in the HAP, input the native software package to be installed again and sign the package, or delete the missing native software package configuration from the **module.json5** file. For details, see [Native Software Package Development Guide](https://gitee.com/openharmony/startup_appspawn/tree/master/service/hnp).

### 9568410 Failed To Install the HAP Because the Device Is Under Control
**Error Message**

error: failed to install because the device be controlled.

**Symptom**

The HAP fails to be installed because the device is under control.

**Possible Causes**

The device is activated through an unauthorized channel.

**Solution**

1. Check whether the device is obtained from unauthorized channels.
2. Activate the device through the normal process.

### 9568413 The Application Device Type Does Not Support the Current Device

**Error Message**

error: check syscap filed and device type is not supported.

**Symptom**

The [device type](../quick-start/module-configuration-file.md) configured for the application does not support installation.

**Possible Causes**

The [device type](../quick-start/module-configuration-file.md) configured for the application is different from that of the device where the application is installed.

**Solution**

Correct the [device type](../quick-start/module-configuration-file.md).

### 9568415 The Encrypted Bundle Whose Signing Certificate Is Debug or Debug Is True in Configuration File Cannot Be Installed
**Error Message**

error: debug encrypted bundle is not allowed to install.

**Symptom**

The encrypted application whose signing certificate is of the **debug** type or whose **debug** attribute of the configuration file is **true** cannot be installed.

**Possible Causes**

1. An encrypted bundle whose signing certificate is of the **debug** type has been installed.
2. An encrypted bundle whose **debug** attribute value is **true** in the configuration file has been installed.

**Solution**

1. Decrypt the encrypted bundle for installation and debugging.

### 9568416 The Encrypted Bundle Cannot Be Installed
**Error Message**

error: Encrypted bundle cannot be installed.

**Symptom**

The encrypted bundle cannot be installed using the bm command.

**Possible Causes**

The installed bundle is encrypted.

**Solution**

1. Use [automatic signing](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V13/ide-signing-V13#section18815157237) or [manual signing](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V13/ide-signing-V13#section297715173233) to re-sign the bundle for installation and debugging.

### 9568417 Failed to Verify the Signature
**Error Message**

error: bundle cannot be installed because the appId is not same with preinstalled bundle.

**Symptom**

If a pre-installed app is uninstalled and then an app with the same bundle name is installed, the app cannot be installed due to inconsistent signature information.

**Possible Causes**

The [key](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section462703710326) and <!--RP7--&gt in the app signature information and the app-identifier<!--RP7End--&gt in the app [profile signature file](../security/app-provision-structure.md) are different from those of the uninstalled pre-installed app.

**Solution**

1. Re-sign the app to ensure that the [key](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section462703710326) and <!--RP7--&gt in the app signature information and the app-identifier<!--RP7End--&gt in the [app profile signature file](../security/app-provision-structure.md) are the same as those of the pre-installed app.
2. Modify [bundleName](../quick-start/app-configuration-file.md) of the installed application to ensure that it is different from that of the preset application.

### 9568418 Failed to Uninstall an Application Configured with an Uninstallation Disposed Rule
**Error Message**

error: Failed to uninstall the app because the app is locked.

**Symptom**

The application cannot be directly uninstalled because it is configured with an uninstallation disposed rule.

**Possible Causes**

The application to uninstall is configured with an uninstallation disposed rule.

**Solution**

1. Check whether the application is configured with an uninstallation disposed rule. The entity that set the rule is responsible for canceling the rule.

### 9568420 Do Not Use the bm Tool to Install Pre-installed Bundles of the Release Version
**Error Message**

error: os_integration Bundle is not allowed to install for shell.

**Symptom**

The pre-installed bundles of the release version cannot be installed.

**Possible Causes**

The bundles are installed using the bm tool.

**Solution**

1. Check whether the bundle is a pre-installed bundle of the release version.

### 9568278 Version Codes of Bundles Are Inconsistent
**Error Message**

error: install version code not same.

**Possible Causes**
1. The version code of the new bundle is different from that of the existing bundle.
2. The version codes of multiple bundles to be installed are inconsistent.

**Solution**
1. Change the version code of the new bundle to be the same as that of the existing bundle, or uninstall the existing bundle and install the new bundle.
2. Ensure that the version codes of all new bundles are the same.

### 9568421 The Application Fails to Be Installed on the Device Because the Type of the Signing Certificate Profile Is Not Supported 
**Error Message**

error: Failed to install the HAP or HSP because the app distribution type is not allowed.

**Symptom**

The application fails to be installed on the device because the distribution type in the signing certificate profile is not supported.

**Possible Causes**

The type in the <!--RP5--> [signature profile file](../security/app-provision-structure.md)<!--RP5End--> is restricted and cannot be installed on the current device.

**Solution**

Change the type of the signing certificate profile.

### 9568423 The Signature Certificate Profile File Does Not Contain the UDID Configuration of the Current Device and Cannot Be Installed on the Current Device
**Error Message**

error: Failed to install the HAP because the device is unauthorized, make sure the UDID of your device is configured in the signing profile.

**Symptom**

The profile file of the signature certificate does not contain the UDID configuration of the current device and cannot be installed on the current device.

**Possible Causes**

The <!--RP5--> [profile signature file](../security/app-provision-structure.md)<!--RP5End--&gt of the application is of the debugging type, and the UDID of the current device is not configured.

**Solution**

<!--RP6-->
<!--RP6End-->Use [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237).


### 9568380 Failed to Uninstall System Applications
**Error Message**

error: uninstall system app error.

**Symptom**

Failed to uninstall the system application.

**Possible Causes**

Some system apps cannot be uninstalled.

**Solution**

Apps that cannot be uninstalled cannot be uninstalled.

### 9568387 Failed to Uninstall a Module That Is Not Installed
**Error Message**

error: uninstall missing installed module.

**Symptom**

Uninstall the modules that are not installed.

**Possible Causes**

Uninstall the modules that are not installed.

**Solution**

Run the bm dump -n command to check the application configuration and ensure that the module to be uninstalled has been installed.
### 9568432 Installation Fails Because the pluginDistributionIDs Verification Between the Plug-in and Application Fails
**Error Message**

error: Check pluginDistributionID between plugin and host application failed.

**Symptom**

Failed to verify pluginDistributionIDs between the application and plug-in.

**Possible Causes**

The pluginDistributionIDs of the application and plug-in do not have the same value. As a result, the verification fails.

**Solution**

Reconfigure pluginDistributionIDs in <!--RP5--> [signature certificate profile file](../security/app-provision-structure.md)<!--RP5End--> of the application or plug-in. as follows:
```
"app-services-capabilities":{
    "ohos.permission.kernel.SUPPORT_PLUGIN":{
        "pluginDistributionIDs":"value-1,value-2,···"
    }
}
``` 

### 9568433 The Application Does Not Have the ohos.permission.SUPPORT_PLUGIN Permission
**Error Message**

error: Failed to install the plugin because host application check permission failed.

**Symptom**

Failed to verify the application permission when installing the plug-in.

**Possible Causes**

The app does not have the ohos.permission.SUPPORT_PLUGIN permission.

**Solution**

1. Request the [ohos.permission.kernel.SUPPORT_PLUGIN permission](../security/AccessToken/restricted-permissions.md#ohospermissionkernelsupport_plugin) by referring to [Declaring Permissions](../security/AccessToken/declare-permissions.md).
<!--Del-->
2. The permission APL is system_basic. If the [application APL](../security/AccessToken/app-permission-mgmt-overview.md) is lower than system_basic, request the permission by referring to [Requesting Restricted Permissions](../security/AccessToken/declare-permissions-in-acl.md).
<!--DelEnd-->


### 9568333 The Module Name Is Empty
**Error Message**

error: Install failed due to hap moduleName is empty.

**Symptom**

The module name is empty. As a result, the installation fails.

**Possible Causes**

The module name is empty.

**Solution**

Check whether the name field of [module.json5](../quick-start/module-configuration-file.md) is empty.

### 9568331 The Signature Information Is Inconsistent
**Error Message**

error: Install incompatible signature info.

**Symptom**

The signature information is inconsistent. As a result, the installation fails.

**Possible Causes**

When an application with multiple HAP packages is installed, the signature information of the HAP packages is inconsistent.

**Solution**

Re-sign the HAP package to ensure that the signature information of multiple HAP packages is the same. For details, see [App/Service Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing).

### 9568334 Duplicate Module Name
**Error Message**

error: Install failed due to hap moduleName duplicate.

**Symptom**

The module name is duplicate. As a result, the installation fails.

**Possible Causes**

When multiple modules are installed for an application at the same time, the module names are duplicate.

**Solution**

The names of multiple modules of the same application must be unique.


<!--Del-->
### 9568335 Failed to Verify the Installation Parameter hashParams
**Error Message**

error: Install failed due to check hap hash param failed.

**Symptom**

During installation, the InstallParam.hashParams parameter fails to be verified.

**Possible Causes**

The [InstallParam.hashParams](../reference/apis-ability-kit/js-apis-installer-sys.md#installparam) parameter contains redundant module names.

**Solution**

Verify that the value of InstallParam.hashParams does not contain redundant module names.<!--DelEnd-->


### 9568340 Configuration File Missing
**Error Message**

error: Install parse no profile.

**Symptom**

The HAP package does not contain a configuration file. As a result, the installation fails.

**Possible Causes**

Configuration files such as [module.json](../quick-start/module-configuration-file.md) and [pack.info](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-compile-build#section43931054115513) are missing.

**Solution**

Use DevEco Studio to rebuild, package, and install the app.

### 9568341 Failed to Parse the Configuration File During Installation
**Error Message**

error: Install parse bad profile.

**Symptom**

Failed to parse the configuration file during installation.

**Possible Causes**

The formats of configuration files such as [module.json](../quick-start/module-configuration-file.md) and [pack.info](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-compile-build#section43931054115513) are incorrect.

**Solution**
Use DevEco Studio to rebuild, package, and install the app.


### 9568342 Incorrect Data Type in the Configuration File
**Error Message**

error: Install parse profile prop type error.

**Symptom**

The data type is incorrect when the configuration file is parsed during installation. As a result, the installation fails.


**Possible Causes**

The configuration files such as [module.json](../quick-start/module-configuration-file.md) and [pack.info](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-compile-build#section43931054115513) contain fields with incorrect data types.

**Solution**

Use DevEco Studio to rebuild, package, and install the app.

### 9568345 Too Long String or Array Size in the Configuration File
**Error Message**

error: too large size of string or array type element in the profile.

**Symptom**

When the configuration file is parsed during installation, the string length or array size is too large. As a result, the installation fails.

**Possible Causes**

The configuration files such as [module.json](../quick-start/module-configuration-file.md) and [pack.info](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-compile-build#section43931054115513) contain fields whose string length or array size is too large.

**Solution**

Use DevEco Studio to rebuild, package, and install the app.


### 9568347 The Local .so File Fails to Be Parsed
**Error Message**

error: install parse native so failed.

**Symptom**

When you start debugging or running a C++ app/service, the error message "error: install parse native so failed" is displayed during HAP installation.

**Possible Causes**

The Application Binary Interface (ABI) supported by the device does not match that configured in the C++ project.

> **NOTE**
>
> - If the project has a dependent HSP or HAR module, make sure that one of the ABI types configured for all modules that contain C++ code is supported by the device.
> - If the project depends on a third-party library that includes .so files, make sure the appropriate ABI directory for your device, such as **arm64-v8a** or **x86_64**, is present in the **oh_modules/*third-party-library*/libs** directory.
<!--RP1--><!--RP1End-->

**Solution**

1. Connect the device or simulator to DevEco Studio. For details, please refer to [Running an App/FA](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-run-device).

2. Run the hdc command on the CLI to query the list of Abis supported by the device.

    ```
    hdc shell
    param get const.product.cpu.abilist
    ```
3. Based on the query result, check the configuration in the ["abiFilters"](../napi/ohos-abi.md) in the [module-level build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile) file. The rules are as follows:

    <!--Del-->
    * If the list includes only **default**, run the following command to check whether the **lib64** folder exists:
      ```
      cd /system/
      ls
      ```
      ![Example](figures/en-us_image_0000001609001262.png)
      * If the **lib64** folder exists, add the arm64-v8a type to **abiFilters**.
      * If the **lib64** folder does not exist, add armeabi, armeabi-v7a, or both types to **abiFilters**.<!--DelEnd-->



    * If the list includes one or more of the following, add at least one of them to **abiFilters**: armeabi-v7a, armeabi, arm64-v8a, x86, and x86_64.

### 9568348 Failed to Parse the ark Native SO File

**Error Message**

error: Install parse ark native file failed.

**Symptom**

Failed to parse the ark native SO file during installation.

**Possible Causes**

When multiple HAPs are installed, the ABIs are inconsistent and do not match the ABIs supported by the current device.

**Solution**

Check whether the Abi of multiple HAPs is consistent. For details, see Error Code 9568347.


### 9568350 Failed to Obtain the Proxy Object During Installation
**Error Message**

error: Installd get proxy error.

**Symptom**

Failed to obtain the proxy object during installation.

**Possible Causes**

The package management service or other services are abnormal. As a result, the proxy fails to be obtained.

**Solution**
1. Restart the phone and try again.

2. If the installation still fails after you repeat the preceding steps for three to five times, export the log file and submit an [online work order](https://developer.huawei.com/consumer/en/support/feedback/#/) for help.

```
# Export the log file.
hdc file recv /data/log/hilog/
```

### 9568434 The Device Does Not Have the Plug-in Capability
**Error Message**

error: Failed to install the plugin because current device does not support plugin.

**Symptom**

Failed to install the plug-in because the device does not have the plug-in capability.

**Possible Causes**

The device does not have the plug-in capability.

**Solution**

Use [param tool](./param-tool.md) to set const.bms.support_plugin to true, that is, run hdc shell param set const.bms.support_plugin true.


### 9568435 The Application Bundle Name Does Not Exist
**Error Message**

error: Host application is not found.

**Symptom**

The app bundle name does not exist.

**Possible Causes**

The app is not installed.

**Solution**

Check whether the input app exists.


### 9568436 Information of Multiple HSP Packages Is Inconsistent
**Error Message**

error: Failed to install the plugin because they have different configuration information.

**Symptom**

The bundle information is inconsistent among multiple HSPs. As a result, the installation fails.

**Possible Causes**

When multiple HSPs are installed, the bundle information of multiple HSP files is inconsistent.

**Solution**

Check whether the bundle information of multiple HSPs is consistent, including the bundleName, bundleType, versionCode, and apiReleaseType fields in the [app.json5 configuration file](../quick-start/app-configuration-file.md).

### 9568437 Plugin Installation Failure Because of Plugin ID Parsing Failure
**Error Message**

error: Failed to install the plugin because the plugin id failed to be parsed.

**Symptom**

The pluginDistributionIDs of the plug-in fails to be parsed. As a result, the installation fails.

**Possible Causes**

The pluginDistributionIDs configuration in the plug-in signature information does not comply with the specifications. As a result, the parsing fails.

**Solution**

Reconfigure the app-services-capabilities field in <!--RP5--> [signature certificate profile file](../security/app-provision-structure.md)<!--RP5End--> by referring to the following format:
```
"app-services-capabilities":{
    "ohos.permission.kernel.SUPPORT_PLUGIN":{
        "pluginDistributionIDs":"value-1,value-2,···"
    }
}
```

### 9568438 Plugin Uninstall Failure Because of Nonexistent Plugin Bundle Name
**Error Message**

error: The plugin is not found.

**Symptom**

The plug-in does not exist.

**Possible Causes**

The plug-in is not installed in the current application.

**Solution**

Run the bm dump -n command to query application information and check whether the input plug-in is installed.

### 9568439 The Plug-in Name Is the Same as the Application Package Name
**Error Message**

error: The plugin name is same as host bundle name.

**Symptom**

The plug-in bundle name is the same as the app bundle name.

**Possible Causes**

The plug-in bundle name is the same as the application bundle name. As a result, the plug-in fails to be installed.

**Solution**

Reconfigure the plugin bundle name.

### 9568441 U1Enabled Cannot Be Changed for Applications
**Error Message**

error: install failed due to U1Enabled can not change.

**Symptom**

The installation fails because the value of U1Enabled in the signature information is changed.

**Possible Causes**

The U1Enabled configuration of the allowed-acls field in <!--RP5--> [profile signature file](../security/app-provision-structure.md)<!--RP5End--> is changed. For example:
1. The installed application is configured with U1Enabled in allowed-acls, but the application to be installed is not configured with U1Enabled in allowed-acls.
2. U1Enabled is not configured in allowed-acls for the installed application, but is configured in allowed-acls for the to-be-installed application.

**Solution**

Solution 1: Re-sign the signature. During the signing, configure the ACL permission by referring to [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section9786111152213) or [Manual signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section157591551175916) to ensure that the configuration of the app to be installed is the same as that of the installed app.<br>
Solution 2: Uninstall the app that has been installed on the device, and then install the app to be installed.

### 9568442 Inconsistent U1Enable Configurations
**Error Message**

error: Install failed due to the U1Enabled is not same in all haps.

**Symptom**

The U1Enabled configuration in the signature information is inconsistent. As a result, the installation fails.

**Possible Causes**

The <!--RP5--> [Profile signature file](../security/app-provision-structure.md)<!--RP5End--&gt used for signing the multi-HAP package is inconsistent. As a result, the U1Enabled configurations of allowed-acls in the signature information are inconsistent.

**Solution**

Re-sign the signature. During the signature, configure the ACL permission by referring to [Automatic signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section9786111152213) or [Manual signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section157591551175916) to ensure that the U1Enabled information of allowed-acls in the signature information of multiple HAP packages is the same.

<!--Del-->
## FAQs

### 1. The pre-installed system app has been uninstalled. When the app is reinstalled, an error message is displayed, indicating that the app is downgraded or the signature information is inconsistent.

**Issue Details**

When I reinstall an application that has been uninstalled, an error message is displayed indicating that the application is downgraded or the signature information is inconsistent. However, the corresponding application icon is displayed on the home screen and can be started properly. What should I do?

**Possible Causes**

The security control capability is enhanced for pre-installed apps that have been uninstalled. When an app with the same bundle name is installed, the system restores the app in the pre-installed image version and then installs the app.

**Solution**

Rectify the fault based on the error information and error code.
<!--DelEnd-->
