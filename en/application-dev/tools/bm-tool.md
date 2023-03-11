# Bundle Manager


The Bundle Manager enables you to install, uninstall, update, and query a bundle (application). It provides the bundle debugging capabilities, for example, installing and uninstalling a bundle and querying bundle information.

> **NOTE**
>
> Before using this tool, you must obtain the [hdc tool](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md) and run the hdc shell command.


**Table 1** bm commands

| Name| Description|
| -------- | -------- |
| help | Displays the commands supported by the Bundle Manager tool.|
| install | Installs a bundle.|
| uninstall | Uninstalls a bundle.|
| dump | Queries bundle information.|
| clean | Clears the cache and data of a bundle.|
| enable | Enables a bundle. A bundle can be used after being enabled.|
| disable | Disables a bundle. A bundle cannot be used after being disabled.|
| get | Obtains the UDID of a device.|
| quickfix | Performs patch-related operations, such as installing or querying a patch.|


## Help Command

**Table 2** Help command

| Name| Description|
| -------- | -------- |
| bm help | Displays the commands supported by the bm tool.|

Example


```bash
# Display the help information.
bm help
```


## Installation Command

```bash
bm install [-h] [-p path] [-u userId] [-r] [-w waitting-time]
```


**Table 3** Installation command parameters

| Name| Mandatory| Description|
| -------- | -------- | -------- |
| -h | No| Used to display the parameters supported by the **install** command. By default, the help information is displayed.|
| -p | Yes| Path of the HAP to install. You can specify a path to install one or more HAPs at the same time.|
| -u | No| User whose HAP is to be installed. By default, the current user's HAP is installed.|
| -r | No| Whether to install the HAP in overwrite mode. By default, the HAP is installed in overwrite mode.|
| -w | No| Time that the Bundle Manager tool waits before installing the HAP. The minimum waiting time is 5s, and the maximum waiting time is 600s. The default waiting time is 5s.|


Example

```bash
bm install -p /data/app/ohosapp.hap -u 100 -w 5s -r
// The execution result is as follows:
install bundle successfully.
```


## Uninstall Command

```bash
bm uninstall [-h help] [-n bundleName] [-m moduleName] [-u userId] [-k]
```


**Table 4** Uninstall command parameters

| Name| Mandatory| Description|
| -------- | -------- | -------- |
| -h | No| Used to display the parameters supported by the **uninstall** command. By default, the help information is displayed.|
| -n | Yes| Name of the bundle to uninstall.|
| -m | No| Module of the bundle to uninstall. By default, all modules are uninstalled.|
| -u | No| User whose bundle is to be uninstalled. By default, the current user's bundle is uninstalled.|
| -k | No| Whether the application data is retained when the bundle is uninstalled. By default, the application data is deleted along the uninstall.|


Example

```bash
bm uninstall -n com.ohos.app -m com.ohos.app.MainAbility -u 100 -k
// The execution result is as follows:
uninstall bundle successfully.
```


## Dump Command

```bash
bm dump [-h help] [-a] [-n bundleName] [-s shortcutInfo] [-u userId] [-d deviceId]
```


If **-u** is not specified, the command applies to all users.


**Table 5** Dump command parameters

| Name| Mandatory| Description|
| -------- | -------- | -------- |
| -h | No| Used to display the parameters supported by the **dump** command. By default, the help information is displayed.|
| -a | Yes| Used to display all bundles installed in the system.|
| -n | Yes| Used to display the details of a bundle.|
| -s | Yes| Used to display the shortcut information of a bundle.|
| -d | No| Used to display the bundle information on a given device. By default, the bundle information on the current device is queried.|
| -u | No| Used to display the bundle information for a given user. By default, the bundle information of the current user is queried.|


Example

```bash
# Display the names of all bundles installed in the system.
bm dump -a
# Display the details of a bundle.
bm dump -n com.ohos.app -u 100
# Display the shortcut information of a bundle.
bm dump -s com.ohos.app -u 100
# Display cross-device bundle information.
bm dump -n com.ohos.app -d xxxxx
```


## Clean Command

```bash
bm clean [-h] [-c] [-n  bundleName] [-d] [-u userId]
```


If **-u** is not specified, the command applies to all active users.


**Table 6** Clean command parameters

| Name| Description|
| -------- | -------- |
| -h | Used to display the parameters supported by the **clean** command.|
| -c -n | Used to clear the cache data of a bundle.|
| -d -n | Used to clear the data directory of a bundle.|
| -u | Used to clear the cache data of a bundle for a given user.|


Example

```bash
# Clear the cache data of a bundle.
bm clean -c -n com.ohos.app -u 100
// The execution result is as follows:
clean bundle cache files successfully.
# Clear the user data of a bundle.
bm clean -d -n com.ohos.app -u 100
// The execution result is as follows:
clean bundle data files successfully.
```


## Enable Command

```bash
bm enable [-h] [-n bundleName] [-a abilityName] [-u userId]
```


If **-u** is not specified, the command applies to all active users.


**Table 7** Enable command parameters

| Name| Description|
| -------- | -------- |
| -h | Used to display the parameters supported by the **enable** command.|
| -n | Used to enable a bundle.|
| -a | Used to enable an ability with a specified bundle name.|
| -u | Used to enable a bundle for a given user.|


Example

```bash
# Enable a bundle.
bm enable -n com.ohos.app -a com.ohos.app.MainAbility -u 100
// The execution result is as follows:
enable bundle successfully.
```


## Disable Command

```bash
bm disable [-h] [-n bundleName] [-a abilityName] [-u userId]
```


If **-u** is not specified, the command applies to all active users.


**Table 8** Disabled command parameters

| Name| Description|
| -------- | -------- |
| -h | Used to display the parameters supported by the **disable** command.|
| -n | Used to disable a bundle.|
| -a | Used to disable an ability with a specified bundle name.|
| -u | Used to disable a bundle for a given user.|

Example

```bash
# Disable a bundle.
bm disable -n com.ohos.app -a com.ohos.app.MainAbility -u 100
// The execution result is as follows:
disable bundle successfully.
```


## Obtaining UDID

```bash
bm get [-h] [-u]
```


**Table 9** Parameters used in the command for obtaining the UDID

| Name| Description|
| -------- | -------- |
| -h | Used to display the parameters supported by the **get** command.|
| -u | Used to obtain the UDID of a device.|


Example

```bash
# Obtain the UDID of a device.
bm get -u
// The execution result is as follows:
udid of current device is :
23CADE0C
```


## Quick Fix

```bash
bm quickfix [-h] [-a -f filePath] [-q -b bundleName]
```


**Table 10** Parameters used in the command for quick fix

| Name| Description|
| -------- | -------- |
| -h | Used to display the commands supported by **quickfix**.|
| -a -f | Used to run the quick fix patch installation command. **file-path** corresponds to the hqf file. You can pass in one or more hqf files or the directory where the hqf file is located.|
| -q -b | Used to display the patch information based on the bundle name. **bundle-name** indicates the bundle name.|


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
# Patch installation in the quick fix:
bm quickfix -a -f /data/app/
// The execution result is as follows:
apply quickfix succeed.
```
