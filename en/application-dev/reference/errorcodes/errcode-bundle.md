#  Bundle Error Codes

## 17700001 Nonexistent Bundle Name

**Error Message**
The specified bundle name is not found.

**Description**
This error code is reported when the bundle name passed in the API does not exist.

**Possible Causes**
1. The bundle name is misspelled.
2. The corresponding application is not installed.

**Solution**
1. Check whether the spelling of the bundle name is correct.
2. Check whether the corresponding application is installed.

## 17700002 Nonexistent Module Name

**Error Message**
The specified module name is not found.

**Description**
This error code is reported when the module name passed in the API does not exist.

**Possible Causes**
1. The module name is misspelled.
2. The module is not installed for the application.

**Solution**
1. Check whether the spelling of the module name is correct.
2. Check whether the module is installed for the application.

## 17700003 Nonexistent Ability Name

**Error Message**
The specified ability name is not found.

**Description**
This error code is reported when the ability name passed in the API does not exist.

**Possible Causes**
1. The ability name is misspelled.
2. The corresponding application is not installed.

**Solution**
1. Check whether the spelling of the ability name is correct.
2. Check whether the ability is installed for the application.

## 17700004 Nonexistent User ID

**Error Message**
The specified user id is not found.

**Description**
This error code is reported when the user ID passed in the API does not exist.

**Possible Causes**
The user ID is incorrect. The user does not exist.

**Solution**
1. Check whether the user ID is correct.
2. Check whether the user exists.

## 17700005 Nonexistent Application ID

**Error Message**
The specified appId is not found.

**Description**
This error code is reported when the value of **appId** passed in the API is an empty string.

**Possible Causes**
**appId** is an empty string.

**Solution**
Check whether **appId** is an empty string.

## 17700006 Nonexistent Permission

**Error Message**
The specified permission is not found.

**Description**
This error code is reported when the permission passed in the API does not exist.

**Possible Causes**
1. The permission name is misspelled.
2. The permission does not exist.

**Solution**
1. Check whether the spelling of the permission name is correct.
2. Check whether the permission exists.

## 17700007 Incorrect Device ID

**Error Message**
The specified deviceId is not found.

**Description**
This error code is reported when the device ID passed in the API is incorrect.

**Possible Causes**
1. The device ID is incorrect.
2. The device ID does not exist.

**Solution**
1. Check whether the device ID is correct.
2. Check whether the device ID exists.

## 17700010 Application Installation Failure Due to File Parsing Failure

**Error Message**
Failed to install the hap since the hap fails to be parsed.

**Description**
This error code is reported when the application fails to be installed because the HAP fails to be parsed.

**Possible Causes**
1. The HAP is not in ZIP format.
2. The configuration file in the HAP is not in JSON format.
3. Necessary fields are missing in the configuration file.

**Solution**
1. Check whether the HAP is in ZIP format.
2. Check whether the configuration file is in [JSON format](../../quick-start/stage-structure.md).
3. Check whether an error message is displayed when DevEco Studio compiles the HAP. If necessary fields are missing, an error message will be displayed.

## 17700011 Application Installation Failure Due to Signature Verification Failure

**Error Message**
Failed to install the hap since the hap signature fails to be verified.

**Description**
This error code is reported when the application fails to be installed due to signature verification failure.

**Possible Causes**

1. The HAP is not signed.
2. The source of the HAP signature information is unreliable.
3. The signature information of the HAP used for an upgrade is different from that of the installed HAP.
4. The signature information of multiple HAPs is inconsistent.

**Solution**
1. Check whether the HAP is signed.
2. Check whether the same certificate is used for signing multiple HAPs.
3. Check whether the certificate used for signing the upgrade HAP is the same as the certificate used for signing the installed HAP.

## 17700012 Application Installation Failure Due to Invalid File Path or Too Large File

**Error Message**
Failed to install the hap since the path of the hap is invalid or too large size.

**Description**
This error code is reported when the application fails to be installed because the HAP path is invalid or the HAP is too large.

**Possible Causes**
1. The path of the HAP does not exist.
2. The path of the HAP is inaccessible.
3. The size of the HAP exceeds the upper limit 4 GB.

**Solution**
1. Check whether the HAP path exists.
2. Check whether the HAP is read only or executable.
3. Check whether the size of the HAP exceeds 4 GB.

## 17700015 Application Installation Failure Due to Different Configuration Information of Multiple HAP Packages

**Error Message**
Failed to install haps since the configuration information of multi haps is inconsistent.

**Description**
This error code is reported when the application fails to be installed because the HAPs have different configuration information.

**Possible Causes**
The fields under **app** in the configuration files of these HAPs are inconsistent.

**Solution**
Check whether the fields under **app** are the same.

## 17700016 Application Installation Failure Due to Insufficient System Disk Space

**Error Message**
Failed to install the hap since the system disk space is insufficient.

**Description**
This error code is reported when the application fails to be installed due to insufficient system disk space.

**Possible Causes**
The system disk space is insufficient.

**Solution**
Check whether the system has sufficient disk space.

## 17700017 Application Installation Failure Because the Version to Install is Too Earlier

**Error Message**
Failed to install the hap since the version of the newly installed hap is too early.

**Description**
This error code is reported when the version number of the application to install is earlier than the version in use.

**Possible Causes**
The version number is earlier than the version in use.

**Solution**
Ensure that the version of the application to install is later than the version in use.

## 17700020 Failure to Uninstall Preinstalled Applications

**Error Message**
The preinstalled app cannot be uninstalled.

**Description**
This error code is reported when you attempt to uninstall a preinstalled application.

**Possible Causes**
1. You might want to uninstall a non-preinstalled application but passed the bundle name of a preinstalled app.
2. The preinstalled application cannot be uninstalled.

**Solution**
1. Check whether the bundle name is correct.
1. Check whether the preinstalled application can be uninstalled.

## 17700021 Invalid UID

**Error Message**
The specified uid is invalid.

**Description**
This error code is reported when the UID passed in the API is invalid.

**Possible Causes**
1. The UID is misspelled.
2. The UID does not exist.

**Solution**
1. Check whether the UID is correct.
2. Check whether the UID exists.

## 17700022 Invalid Source File

**Error Message**
The input source file is invalid.

**Description**
This error code is reported when the source file to be parsed is invalid.

**Possible Causes**
1. The source file to be parsed does not exist.
2. The source file to be parsed is not in ZIP format.

**Solution**
1. Check whether the source file to be parsed exists.
2. Check whether the source file to be parsed is in ZIP format.

## 17700023 Nonexistent Default Application

**Error Message**
The specified default app does not exist.

**Description**
This error code is reported when the specified default application does not exist.

**Possible Causes**
No default application is set for the device.

**Solution**
Check whether the default application is set on the device.

## 17700024 Nonexistent Configuration File

**Error Message**
Failed to get profile since no profile in the hap.

**Description**
This error code is reported when you attempt to obtain the configuration file that does not exist.

**Possible Causes**
1. The metadata name passed in the API does not exist in the configuration file.
2. The content of the configuration file is not in JSON format.

**Solution**
1. Check whether the metadata name in the **ability** or **extensionAbility** to be queried exists.
2. Check whether the content of the profile to be queried is in JSON format.

## 17700025 Invalid Type

**Error Message**
The specified type is invalid.

**Description**
The type is invalid.

**Possible Causes**
1. The type passed in the API is misspelled.
2. The type passed in the API does not exist.

**Solution**
Check whether the spelling of type is correct.

## 17700026 Application Disabled

**Error Message**
The specified bundle is disabled.

**Description**
This error code is reported when the specified application is disabled.

**Possible Causes**
The application on the device has been disabled and cannot be queried.

**Solution**
Check whether the application on the device is disabled.

## 17700027 Distributed Service Not Started

**Error Message**
The distributed service is not running.

**Description**
This error code is reported when the distributed service is not started.

**Possible Causes**
The device is not networked.

**Solution**
Check whether the device is networked.
## 17700028 Mismatch Between Ability and Type

**Error Message**
The ability does not match the type.

**Description**
This error code is reported when the ability and type passed in the API do not match.

**Possible Causes**
The ability and type are misspelled.

**Solution**
Check whether the spellings of ability and type are correct.

## 17700029 Disabled Ability

**Error Message**
The specified ability is disabled.

**Description**
This error code is reported when the specified ability is disabled.

**Possible Causes**
The specified ability is disabled.

**Solution**
Check whether the ability is disabled. You can run the [bm commands](../../../readme/bundle-management.md#bm-commands) to query the application information.

## 17700030 Failure in Clearing Cache Files

**Error Message**
The specified bundle does not support clearing cache files.

**Description**
This error code is reported when the application does not support cache file clearing.

**Possible Causes**
The application is a system application and the **AllowAppDataNotCleared** field is configured in the signing certificate.

**Solution**
1. Check whether the application is a system application. You can run the [bm commands](../../../readme/bundle-management.md#bm-commands) to query the application information and check whether the value of **isSystemApp** is **true**.
2. Check whether the **AllowAppDataNotCleared** field is configured for the application. You can run the [bm commands](../../../readme/bundle-management.md#bm-commands) to query the application information and check whether the value of **userDataClearable** is **true**.
