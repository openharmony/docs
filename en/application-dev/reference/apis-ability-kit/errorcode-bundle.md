# Bundle Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 17700001 Bundle Name Does Not Exist

**Error Message**

The specified bundle name is not found.

**Description**

When a query API is called, the bundle name passed in does not exist.

**Possible Causes**

1. The bundle name is misspelled.
2. The corresponding bundle is not installed.

**Solution**
1. Check whether the spelling of the bundle name is correct.
2. Check whether the corresponding bundle is installed.

## 17700002 Module Name Does Not Exist

**Error Message**

The specified module name is not found.

**Description**

When a query API or an installation-free API is called, the module name passed in does not exist.

**Possible Causes**
1. The module name is misspelled.
2. The module is not installed.

**Solution**
1. Check whether the spelling of the module name is correct.
2. Check whether the module is installed.

## 17700003 Ability Name Does Not Exist

**Error Message**

The specified ability name is not found.

**Description**

When a query API is called, the ability name passed in does not exist.

**Possible Causes**
1. The ability name is misspelled.
2. The application does not have the ability specified by **abilityName**.

**Solution**
1. Check whether the spelling of the ability name is correct.
2. Check whether the application has the ability specified by **abilityName**.

## 17700004 User ID Does Not Exist

**Error Message**

The specified user ID is not found.

**Description**

When a user-related API is called, the user ID passed in does not exist.

**Possible Causes**
1. Incorrect username.
2. The user does not exist in the system.

**Solution**
1. Check whether the user ID is correct.
2. Check whether the user exists.

## 17700005 appId Is an Empty String

**Error Message**

The specified app ID is an empty string.

**Description**

When an API of the **appControl** module is called, the application ID passed in does not exist.

**Possible Causes**

**appId** is an empty string.

**Solution**

Check whether **appId** is an empty string.

## 17700006 Permission Does Not Exist

**Error Message**

The specified permission is not found.

**Description**

When the **getPermissionDef** API of the **bundleManager** module is called, the permission passed in does not exist.

**Possible Causes**
1. The permission name is misspelled.
2. The permission does not exist.

**Solution**
1. Check whether the spelling of the permission name is correct.
2. Check whether the permission exists.

## 17700007 Incorrect Device ID

**Error Message**

The specified device ID is not found.

**Description**

When an API of the **distributedBundle** module is called, the device ID passed in does not exist.

**Possible Causes**
1. The device ID is incorrect.
2. The device ID does not exist.

**Solution**
1. Check whether the device ID is correct.
2. Check whether the device ID exists.

## 17700010 Bundle Installation Failure Due to File Parsing Failure

**Error Message**

Failed to install the HAP because the HAP fails to be parsed.

**Description**

When the **install** API of the **installer** module is called, the HAP passed in fails to be parsed.

**Possible Causes**
1. The HAP is not in ZIP format.
2. The profile in the HAP is not in JSON format.
3. Necessary fields are missing in the profile.

**Solution**
1. Check whether the HAP is in ZIP format.
2. Check whether the profile is in [JSON format](../../quick-start/application-configuration-file-overview-stage.md).
3. Check whether an error message is displayed when DevEco Studio compiles the HAP. If necessary fields are missing, an error message will be displayed.

## 17700011 Bundle Installation Failure Due to Signature Verification Failure

**Error Message**

Failed to install the HAP because the HAP signature fails to be verified.

**Description**

Calling the **install** API of the **installer** module to install the bundle fails due to signature verification failure.

**Possible Causes**

1. The HAP is not signed.
2. The source of the HAP signature information is unreliable.
3. The signature information of the HAP to update is different from that of the installed HAP.
4. The signature information of multiple HAPs is inconsistent.

**Solution**
1. Check whether the HAP is signed.
2. Ensure that the signing certificate of the HAP is applied for from the application market.
3. Check whether the same certificate is used for signing multiple HAPs.
4. Check whether the certificate used for signing the HAP to update is the same as the certificate used for signing the installed HAP.

## 17700012 Bundle Installation Failure Due to Invalid File Path or Too Large File

**Error Message**

Failed to install the HAP because the HAP path is invalid or the HAP is too large.

**Description**

Calling the **install** API of the **installer** module to install the bundle fails because the HAP path is invalid or the HAP is too large.

**Possible Causes**
1. The path of the HAP does not exist.
2. The path of the HAP is inaccessible.
3. The size of the HAP exceeds the upper limit 4 GB.

**Solution**
1. Check whether the HAP path exists.
2. Check whether the HAP is read only or executable.
3. Check whether the size of the HAP exceeds 4 GB.

## 17700015 Bundle Installation Failure Due to Different Configuration Information of Multiple HAPs

**Error Message**

Failed to install the HAPs because they have different configuration information.

**Description**

Calling the **install** API of the **installer** module to install the bundle fails because the HAPs have different configuration information.

**Possible Causes**

The fields under **app** in the profiles of these HAPs are inconsistent.

**Solution**

Check whether the fields under **app** are the same.

## 17700016 Bundle Installation Failure Due to Insufficient System Disk Space

**Error Message**

Failed to install the HAP because of insufficient system disk space.

**Description**

Calling the **install** API of the **installer** module to install the bundle fails due to insufficient system disk space.

**Possible Causes**

The system disk space is insufficient.

**Solution**

Check whether the system has sufficient disk space.

## 17700017 Bundle Installation Failure Because the Version to Install is Too Earlier

**Error Message**

Failed to install the HAP since the version of the HAP to install is too early.

**Description**

Calling the **install** API of the **installer** module to install the bundle fails because the version to install is earlier than the version in use.

**Possible Causes**

The version number is earlier than the version in use.

**Solution**

Ensure that the version of the bundle to install is not earlier than the version in use.

## 17700018 Bundle Installation Failure Because the Dependent Module Does Not Exist

**Error Message**

Failed to install the HAP or HSP because the dependent module does not exist.

**Description**

The dependent module does not exist during the HAP or HPS installation.

**Possible Causes**

The dependent module is not installed.

**Solution**

Install the dependent modules first.

## 17700020 Failure to Uninstall Preinstalled Applications

**Error Message**

The preinstalled app cannot be uninstalled.

**Description**

Calling the **uninstall** API of the **installer** module to uninstall a preinstalled application fails.

**Possible Causes**

1. You might want to uninstall a non-preinstalled application but passed the bundle name of a preinstalled app.
2. The preinstalled application cannot be uninstalled.

**Solution**
1. Check whether the bundle name is correct.
2. Check whether the preinstalled application can be uninstalled.

## 17700021 Invalid UID

**Error Message**

The specified uid is invalid.

**Description**

When the **getBundleNameByUid** API of the **bundleManager** module is called, the UID passed in is invalid.

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

When the **getBundleArchiveInfo** API of the **bundleManager** module is called, the HAP path passed in is invalid.

**Possible Causes**
1. The source file to be parsed does not exist.
2. The source file to be parsed is not in ZIP format.

**Solution**
1. Check whether the source file to be parsed exists.
2. Check whether the source file to be parsed is in ZIP format.

## 17700023 Default Application Does Not Exist

**Error Message**

The specified default app does not exist.

**Description**

When the **getDefaultApplication** API of the **defaultAppManager** module is called, the specified default application does not exist.

**Possible Causes**

No default application is set for the device.

**Solution**

Check whether the default application is set on the device.

## 17700024 Profile Does Not Exist

**Error Message**

Failed to get the profile because the specified profile is not found in the HAP.

**Description**

When an API for querying the profile is called, the profile does not exist.

**Possible Causes**

1. The metadata name passed in the API does not exist in the profile.
2. The content of the profile is not in JSON format.
3. The type of the profile to query does not exist.

**Solution**
1. Check whether the metadata name in the **ability** or **extensionAbility** to be queried exists.
2. Check whether the content of the profile to be queried is in JSON format.
3. Check whether the application contains a profile that matches the value of **profileType** passed in.

## 17700025 Invalid Type

**Error Message**

The specified type is invalid.

**Description**

When an API of the **defaultAppManager** module is called, the type passed in is invalid.

**Possible Causes**
1. The type passed in the API is misspelled.
2. The type passed in the API does not exist.

**Solution**
1. Check whether the spelling of type is correct.
2. Enter a type that exists.

## 17700026 Bundle Disabled

**Error Message**

The specified bundle is disabled.

**Description**

When an API for querying bundle information is called, the specified bundle is disabled.

**Possible Causes**

The bundle on the device has been disabled and cannot be queried.

**Solution**

Check whether the bundle on the device is disabled.

## 17700027 Distributed Service Is Not Started

**Error Message**

The distributed service is not running.

**Description**

When an API of the **distributedBundle** module is called, the distributed service is not started.

**Possible Causes**

The device is not networked.

**Solution**

Check whether the device is networked.

## 17700028 Mismatch Between Ability and Type

**Error Message**

The ability does not match the type.

**Description**

When the **setDefaultApplication** API of the **defaultAppManager** module is called, the **ability** and **type** passed in do not match.

**Possible Causes**

The ability and type are misspelled.

**Solution**

Check whether the spellings of ability and type are correct.

## 17700029 Disabled Ability

**Error Message**

The specified ability is disabled.

**Description**

When an API for querying ability information is called, the specified ability is disabled.

**Possible Causes**

The specified ability is disabled.

**Solution**

Check whether the ability is disabled. You can use [Bundle Manager](../../tools/bm-tool.md) to query the information.

## 17700030 Failure in Clearing Cache Files

**Error Message**

The specified bundle does not support clearing of cache files.

**Description**

When the **cleanBundleCacheFiles** API of the **bundleManager** module is called, the specified bundle does not support cache file clearing.

**Possible Causes**

The application is a system application and the **AllowAppDataNotCleared** field is configured in the signing certificate.

**Solution**
1. Check whether the application is a system application. You can use [Bundle Manager](../../tools/bm-tool.md) to query the application information and check whether the value of **isSystemApp** is **true**.
2. Check whether the **AllowAppDataNotCleared** field is configured for the application. You can use [Bundle Manager](../../tools/bm-tool.md) to query the application information and check whether the value of **userDataClearable** is **true**.

## 17700031 HAP Installation Fails Due to Overlay Feature Verification Failure

**Error Message**

Failed to install the HAP because the overlay check of the HAP failed.

**Description**

The target application and the to-be-installed application with the overlay feature are not preset applications, or the target application or target module is one with the overlay feature.

**Possible Causes**
1. To use the overlay feature between applications, the following conditions must be met:<br>The application with the overlay feature must be a preset application.
2. The target application must be a preset application.
3. The target application cannot be an application with the overlay feature.
4. The target module cannot be a module with the overlay feature.

**Solution**
1. Ensure that the application with the overlay feature is a preset application.
2. Ensure that the target application is a preset application.
3. Ensure that the target application is not an application with the overlay feature.
4. Ensure that the target module is not a module with the overlay feature.

## 17700032 Application Does Not Contain a Module with the Overlay Feature

**Error Message**

The specified bundle does not contain any overlay module.

**Description**

An API is called to obtain the **overlayModuleInfo** object of another application, but that application does not contain a module with the overlay feature.

**Possible Causes**

The specified application does not contain a module with the overlay feature.

**Solution**

Check whether the application contains a module with the overlay feature.

## 17700033 Module Is Not Configured with the Overlay Feature

**Error Message**

The specified module is not an overlay module.

**Description**

An API is called to obtain the **overlayModuleInfo** object of a module, but the module is not configured with the overlay feature.

**Possible Causes**

The specified module is not a module with the overlay feature.

**Solution**

Check whether the module is configured with the overlay feature.

## 17700034 Module Is Configured with the Overlay Feature

**Error Message**

The specified module is an overlay module.

**Description**

An API is called to obtain the **overlayModuleInfo** object based on the target module name, but that module is configured with the overlay feature.

**Possible Causes**

The specified module is configured with the overlay feature.

**Solution**

Check whether the specified module is configured with the overlay feature.

## 17700035 Application Contains Only Modules with the Overlay Feature

**Error Message**

The specified bundle is an overlay bundle.

**Description**

An API is called to obtain the **overlayModuleInfo** object based on the target module name of another application, but that application contains only modules with the overlay feature.

**Possible Causes**

The specified application contains only modules with the overlay feature.

**Solution**

Check whether the application contains only modules with the overlay feature.

## 17700036 Failure in Installing the Shared Library Because of No AllowAppShareLibrary Privilege

**Error Message**

Failed to install the HSP due to the lack of required permission.

**Description**

The shared library is not configured with the **AllowAppShareLibrary** privilege, resulting in security and privacy risks. As a result, the installation fails.

**Possible Causes**

The shared library does not request the **AllowAppShareLibrary** privilege before being released.

**Solution**

Configure the **AllowAppShareLibrary** privilege for the shared library, re-sign the library, and release it.

## 17700037 Failure in Uninstalling the Shared Library Due to Dependency

**Error Message**

The version of the shared bundle is dependent on other applications.

**Description**

Other applications depend on the shared library, causing the uninstall to fail.

**Possible Causes**
1. The version specified during the uninstall is the latest version of the shared library, and the shared library is depended on by other applications.
2. No version is not specified during the uninstall, meaning that all versions of the shared library will be uninstalled, and the shared library is depended on by other applications.

**Solution**
1. Check whether the shared library to uninstall is depended on by other applications.
2. Check whether the version of the shared library to uninstall is the latest version of the shared library.

## 17700038 Shared Library to Uninstall Does Not Exist

**Error Message**

The specified shared bundle does not exist.

**Description**

The shared library to uninstall does not exist.

**Possible Causes**
1. The version specified during the uninstall is different from the version of the shared library installed.
2. The shared library to uninstall is not installed.

**Solution**
1. Check whether the shared library exists.
2. Check whether the version of the shared library is the same as that installed.

## 17700039 Failure in Installing an Inter-Application Shared Library

**Error Message**

Failed to install the HSP because installing a shared bundle specified by hapFilePaths is not allowed.

**Description**

During application installation, the installation package passed in is of the inter-application shared library type.

**Possible Causes**
1. When [Bundle Manager](../../tools/bm-tool.md) is used to install an application, the **-p** parameter is set to the installation package path of an inter-application shared library.
2. When the **install** API is called to install an application, the **hapFilePaths** parameter is set to the installation package path of an inter-application shared library.

**Solution**
1. Use the **-p** parameter to specify the installation package path of an inter-application shared library.
2. Use the **sharedBundleDirPaths** parameter in **installParam** to specify the installation package path of an inter-application shared library.

## 17700040 Failure in Uninstalling an Inter-Application Shared Library

**Error Message**

The specified bundle is a shared bundle which cannot be uninstalled.

**Description**

During application uninstall, the bundle name of an inter-application shared library is passed in.

**Possible Causes**
1. When [Bundle Manager](../../tools/bm-tool.md) is used to uninstall an application, the **-n** parameter is set to the bundle name of an inter-application shared library.
2. When the **install** API is called to uninstall an application, the **bundleName** parameter is set to the bundle name of an inter-application shared library.

**Solution**
1. Use the **-n** parameter to specify the application to be uninstalled as a shared library application.
2. Use the **bundleName** and **versionCode** parameters in **UninstallParam** to specify the bundle name and version of the shared library to be uninstalled.

## 17700041 Application Installation Is Not Allowed by Enterprise Device Management

**Error Message**

Failed to install the HAP because the installation is forbidden by enterprise device management.

**Description**

The installation of this application is prohibited by enterprise device management.

**Possible Causes**

The enterprise device management does not allow the installation of this application.

**Solution**

Check whether the application installation is prohibited by the enterprise device management.

## 17700042 Incorrect URI in the Data Proxy

**Error Message**

Failed to install the HAP because of incorrect URI in the data proxy.

**Description**

During application installation, the URI of the data proxy is incorrectly configured.

**Possible Causes**

1. The bundle name in the URI is different from that of the current application.
2. The URI is duplicate.

**Solution**

1. Change the bundle name in the URI to that of the current application.
2. Change duplicate URIs. Ensure that the URI of each data proxy is unique.

## 17700043 Incorrect Permission Configuration in the Data Proxy

**Error Message**

Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core).

**Description**

During application installation, the permission level of the data proxy of a non-system application is too low. The permission level should be **system_basic** or **system_core**.

**Possible Causes**

1. No permission is configured for the data proxy of a non-system application.
2. The permission level of the data proxy of a non-system application is too low.

**Solution**

1. Configure the read and write permissions in the data proxy.
2. Change the read and write permissions in the data proxy and ensure that the permission level is **system_basic** or **system_core**.

## 17700044 Field isolationMode in the HAP Conflicts with the Device Isolation Mode

**Error Message**

Failed to install the HAP because the isolationMode configured is not supported.

**Description**

During application installation, the value of **isolationMode** in the HAP conflicts with the isolation mode of the device.

**Possible Causes**
1. The device supports the isolation mode (the value of **persist.bms.supportIsolationMode** is **true**), whereas the value of **isolationMode** in the HAP is **nonisolationOnly**.
2. The device does not support the isolation mode (the value of **persist.bms.supportIsolationMode** is **false**), whereas the value of **isolationMode** in the HAP is **isolationOnly**.

**Solution**

Set the **isolationMode** field in the HAP based on the isolation mode of the device.

## 17700045 Application Uninstall Is Not Allowed by Enterprise Device Management

**Error Message**

Failed to uninstall the HAP because the uninstall is forbidden by enterprise device management.

**Description**

The uninstall of this application is prohibited by enterprise device management.

**Possible Causes**

The enterprise device management does not allow the installation of this application.

**Solution**

Check whether the application uninstall is prohibited by the enterprise device management.

## 17700047 Application Version To Be Updated Is Not Later Than the Current Version

**Error Message**

Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode.

**Description**

The version of the application to be updated is not later than the current version.

**Possible Causes**

1. The version number of the application to be updated is earlier than or equal to that of the current version number.
2. When **installFlag** is set to **NORMAL**, the version number of the application to be updated must be later than the installed version number.

**Solution**

1. Set the version number of the application to be later than the current version number.
2. If you want to update the application without changing the version number, set **installFlag** to **REPLACE_EXISTING**.

## 17700048 Code Signature Verification Failure
**Error Message**

Failed to install the HAP because the code signature verification failed.

**Description**

During application installation, the code signature file of the installation package fails to be verified.

**Possible Causes**

1. The module corresponding to the code signature file does not exist in the installation package.
2. The path of the code signature file is invalid.
3. The code signature file does not match the installation package.

**Solution**

1. Ensure that the module corresponding to the code signature file is contained in the installation package.
2. Provide a valid path of the code signature file.
3. Use the code signature file that matches the installation package.

## 17700049 Update Failure Because of Incorrect Bundle Name

**Error Message**

Failed to install the HAP because the bundleName is different from the bundleName of the caller application.

**Description**

During the update of an enterprise MDM application, the bundleName passed in is different from that of the caller.

**Possible Causes**

The HAP or HSP to be installed does not belong to the current application.

**Solution**

Ensure that the HAP or HSP to be installed belongs to the current application.

## 17700050 Enterprise Device Verification Failure

**Error Message**

Failed to install the HAP because an enterprise normal/MDM bundle cannot be installed on non-enterprise devices.

**Description**

Users try to install an enterprise Normal or MDM application on a non-enterprise device.

**Possible Causes**

The device is not an enterprise device.

**Solution**

1. Use an enterprise device.

2. Ensure that **const.bms.allowenterprisebundle** is set to **true**.

## 17700051 Update Failure Because the Distribution Type of the Caller Is Not Enterprise MDM

**Error Message**

Failed to install the HAP because the distribution type of the caller application is not enterprise_mdm.

**Description**

During the update of an enterprise MDM application, the distribution type of the caller is not enterprise MDM.

**Possible Causes**

The distribution type of the caller is not enterprise MDM.

**Solution**

Ensure that the signature file of the application is correctly configured.

## 17700052 Installation of Debugging Applications Allowed Only in Developer Mode

**Error Message**

Failed to install the HAP because a debug bundle can be installed only in developer mode.

**Description**

A debugging application can be installed only in the developer mode.

**Possible Causes**

The application is a debugging application, but the device is not in developer mode.

**Solution**

Run the **hdc shell param get const.security.developermode.state** command. If **false** is returned, a debugging application cannot be installed on the device.

## 17700053 Not Invoked by AppGallery

**Error Message**

The caller is not AppGallery.

**Description**

This API is called by AppGallery.

**Possible Causes**

The caller is not AppGallery.

**Solution**

Use AppGallery to call the API.

## 17700054 Bundle Installation Failure Due to Permission Verification Failure

**Error Message**

Failed to install the HAP because the HAP requests wrong permissions.

**Description**

The application has applied for an incorrect permission, causing the installation to fail.

**Possible Causes**

1. The application is not an MDM application and has applied for the MDM permission.
2. The ability privilege level (APL) of the application is lower than the level of the permission that the application has applied for.

**Solution**

1. Check whether the application has applied for the <!--Del-->[<!--DelEnd-->MDM permission<!--Del-->](../../security/AccessToken/permissions-for-mdm-apps.md)<!--DelEnd-->, which is available only for MDM applications.
2. Check whether the requested permission is open. For details, see [Permission List](../../security/AccessToken/app-permissions.md).

## 17700055 Invalid Link

**Error Message**

The specified link is invalid.

**Description**

When the **canOpenLink** API of the **bundleManager** module is called, the link passed in is invalid.

**Possible Causes**

The format of the link is incorrect.

**Solution**

Check whether the link format is correct.

## 17700056 Scheme of the Link Not Configured in querySchemes

**Error Message**

The scheme of the specified link is not in the querySchemes.

**Description**

When the **canOpenLink** API of the **bundleManager** module is called, the scheme of the link is not configured in the **querySchemes** field.

**Possible Causes**

The scheme of the link is not configured in the **querySchemes** field.

**Solution**

Check whether the URL scheme is configured in the **querySchemes** field.

## 17700057 Specified Application Is Not a Preset Application

**Error Message**

Failed to uninstall updates because the HAP is not pre-installed.

**Description**

When the **uninstallUpdates** API of the **installer** module is called, the specified application is not a preset application.

**Possible Causes**

The **uninstallUpdates** API can only be used to uninstall the updates of a preset application.

**Solution**

Check whether the specified application is a preset application.

## 17700058 Specified Application Cannot Be Installed on this Device or by this User

**Error Message**

Failed to install the HAP because this application is prohibited from being installed on this device or by specified users.

**Description**

The specified application cannot be installed on this device or by this user.

**Possible Causes**
1. The device in use has undergone a whitewashing process.
2. The specified application is prohibited from being installed by the specified user.

**Solution**
1. Check whether the device has undergone a whitewashing process.
2. Install the application as another user.

## 17700059 Specified Developer ID Does Not Exist

**Error Message**

The specified developerId is invalid.

**Description**

When the **getAllBundleInfoByDeveloperId** API of the **bundleManager** module is called, the developer ID passed in is invalid.

**Possible Causes**

Applications with the specified developer ID are not installed on the device.

**Solution**

Check the validity of the developer ID.

## 17700060 Specified Application Cannot Be Uninstalled

**Error Message**

The specified application cannot be uninstalled.

**Description**

When the **uninstall** API of the **BundleInstaller** module or the **switchUninstallState** API of the **bundleManager** module is called, the specified application cannot be uninstalled.

**Possible Causes**
1. When the **uninstall** API is called, the specified application rejects the uninstallation attempt due to the ongoing operation of its own services.
2. When the **switchUninstallState** API is called, the specified application has a privilege that prevents it from being uninstalled.

**Solution**
1. Check the reason why the application cannot be uninstalled and perform related operations.
2. Check whether the specified application is uninstallable.

## 17700061 appIndex for a Clone Is Invalid

**Error Message**

The appIndex is invalid.

**Description**

When an API related to the app clone feature is called, the specified **appIndex** is invalid.

**Possible Causes**
1. The index is out of range.
2. The application does not have a clone of the specified index.
3. The index already exists when you create the clone.

**Solution**
1. Check whether the index is within the allowed range.
2. Check whether the application has a clone of the specified index.
3. Check whether **createAppClone** is called with an existing index.

## 17700062 Failed to Uninstall an Application Configured with an Uninstallation Disposed Rule

**Error Message**

Failed to uninstall the app because the app has uninstall rule.

**Description**

The application cannot be directly uninstalled because it is configured with an uninstallation disposed rule.

**Possible Causes**

The application to uninstall is configured with an uninstallation disposed rule.

**Solution**

Check whether the application is configured with an uninstallation disposed rule. The entity that set the rule is responsible for handling.

## 17700065 Ability Specified by want in the ShortcutInfo Struct Cannot Be Started

**Error Message**

The ability specified by want in the ShortcutInfo struct cannot be started.

**Description**

When the **startShortcut** API of the **launcherBundleManager** module is called, the ability specified by **want** in the **ShortcutInfo** struct fails to start.

**Possible Causes**

The ability specified by **want** in the **ShortcutInfo** struct does not exist, or the ability specified by **want** in the **ShortcutInfo** struct cannot be started.

**Solution**

Check the validity of **want** in the **ShortcutInfo** struct.

## 17700066 Failed to Install the Native Software Package

**Error Message**

Failed to install the HAP because installing the native package failed.

**Description**

The native software package fails to be installed during HAP installation.

**Possible Causes**

The configuration of the native software package is incorrect.

**Solution**

Check the configuration of the native software package.

## 17700067 Failed to Uninstall the Native Software Package

**Error Message**

Failed to uninstall the HAP because uninstalling the native package failed.

**Description**

The native software package fails to be uninstalled during application uninstall.

**Possible Causes**

The native software package to be uninstalled is occupied.

**Solution**

Check whether any process occupies the native software package.

## 17700069 AppClone Instance Cannot Be Created For an Application in Multi-app Mode Not Set To appClone

**Error Message**

The app does not support the creation of an appClone instance.

**Description**

An AppClone instance cannot be created for an application that is not in appClone mode.

**Possible Causes**

The multi-app mode is set to another mode other than appClone.

**Solution**

Check whether the application to update supports clones.

## 17700070 Invalid Shortcut ID

**Error Message**

The specified shortcut id is illegal.

**Description**

The specified shortcut ID is invalid.

**Possible Causes**

When the API for adding a shortcut is called, a shortcut with the same bundle name, clone index, user ID, and shortcut ID already exists, or the passed-in shortcut ID is empty.

**Solution**

Check whether the bundle name and shortcut ID are correct.

## 17700071 Enterprise Applications Cannot Be Installed

**Error Message**

It is not allowed to install the enterprise bundle.

**Description**

It is not allowed to install enterprise applications through a specific installation API.

**Possible Causes**

Due to policy control, enterprise applications cannot be installed through the specific API.

## 17700072 Launch Want Does Not Exist

**Error Message**

The launch want is not found.

**Description**

The launch want does not exist.

**Possible Causes**

The application does not have an ability, or does not have an ability for which **entities** is set to **entity.system.home** and **actions** is set to **action.system.home**.

**Solution**

Configure an ability with **entities** set to **entity.system.home** and **actions** set to **action.system.home** for the application.

## 17700073 Installation Failure Caused by an Application with the Same Bundle Name but Different Signature Information

**Error Message**

Failed to install the HAP because an application with the same bundle name but different signature information exists on the device.

**Description**

The installation fails because an application with the same bundle name but different signature information exists on the device.

**Possible Causes**
1. An application with the same bundle name but different signature information exists on the device.
2. An application with the same bundle name but different signature information has been uninstalled with data retained.

**Solution**
1. Uninstall the application with the same bundle name.
2. Install the application that has been uninstalled with data retained, and then uninstall the application without data retained.

## 17700074 Invalid appIdentifier

**Error Message**

The specified appIdentifier is invalid.

**Description**

When an API of the appControl module is called, the appIdentifier passed in is invalid.

**Possible Causes**

**appIdentifier** is an empty string.

**Solution**

Check whether **appIdentifier** is an empty string.

## 17700075 Bundle Name Specified in want Is Inconsistent with That of the Caller

**Error Message**

The specified bundleName of want is not the same with caller.

**Description**

When setting an uninstallation disposed rule, the bundle name specified in **want** is different from that of the caller.

**Possible Causes**

When setting an uninstallation disposed rule, the bundle name specified in **want** is different from that of the caller.

**Solution**

Change the value of **bundleName** in **want** to be the same as that of the caller.

## 17700076 Failed to Install the HAP or HSP Because the Distribution Type in the Signature File Restricts Installation
**Error Message**

Failed to install the HAP or HSP because the app distribution type is not allowed.

**Description**

The distribution type in the signature file restricts installation, leading to a failure in installing the HAP or HSP.

**Possible Causes**

The distribution type specified in the signature file restricts installation on the current device.

**Solution**

Change the distribution type of the signature file.

<!--Del-->
## 17700077 Application Installation Fails but Preinstallation Is Successful

**Error Message**

Failed to install the HAP and restore to preinstalled bundle.

**Description**

If the preinstalled application corresponding to the specified application has been uninstalled, the system first attempts to reinstall the preinstalled application. If the preinstalled application is successfully reinstalled but the specified application fails to install afterward, this error code is reported.

**Possible Causes**

The version number of the application to be installed is earlier than or the same as the version number of the preinstalled application.

**Solution**
1. Ensure that the version number of the specified application is later than that of the preinstalled application.
2. Reinstall the specified application.
<!--DelEnd-->

<!--Del-->
## 17700080 Invalid Source Paths

**Error Message**

The source paths are invalid.

**Description**

The source paths are invalid.

**Possible Causes**
1. The source path array is empty.
2. A source path includes the special sequence **../**.
3. None of the paths can be resolved to the intended location.

**Solution**

Pass in a valid path that does not include the special sequence **../**.

## 17700081 Invalid Destination Path

**Error Message**

The destination path is invalid.

**Description**

The destination path is invalid.

**Possible Causes**
1. The destination path is empty.
2. The destination path includes the special sequence **../**.
3. The destination path cannot be resolved to the intended location.

**Solution**

Pass in a valid path that does not include the special sequence **../**.

## 17700082 User Authentication Failed

**Error Message**

User authentication failed.

**Description**

User authentication fails.

**Possible Causes**
1. The current system does not support user authentication.
2. The current user has not enabled user authentication.
3. User authentication information is incorrect or the user cancels authentication.

**Solution**
1. Check whether the current system supports user authentication. If not, the API cannot be used.
2. Ensure that user authentication is enabled for the current user.
3. Have the user re-enter accurate authentication details to ensure successful authentication.

## 17700083 User Authentication Times Out

**Error Message**

Waiting for user authentication timeout.

**Description**

Waiting for user authentication times out.

**Possible Causes**

The user authentication process exceeds the 5-minute waiting period.

**Solution**

Ensure that the user completes the authentication process within the allowed time.

## 17700084 No Read Permissions for Source Paths

**Error Message**

There are inaccessible path in the source paths.

**Description**

Some paths in the source path array lack read permissions.

**Possible Causes**

Read permissions are not enabled for some source paths.

**Solution**

Provide a valid path with read permissions enabled.

## 17700085 No Write Permissions for the Destination Path

**Error Message**

The destination path cannot be accessed.

**Description**

The destination path cannot be accessed.

**Possible Causes**

Write permissions are not enabled for the destination path.

**Solution**

Provide a valid path with write permissions enabled.

## 17700086 System Error

**Error Message**

System error occurred during copy execution.

**Description**

A system error occurred during the copy operation.

**Possible Causes**

Errors related to file operations occurs, such as insufficient space at the destination or the removal of files from the source path.

**Solution**
1. Ensure that the destination path has sufficient space.
2. Ensure the files in the source path are still present.
<!--DelEnd-->

## 17700101 Bundle Manager Service Abnormal
**Error Message**

Bundle manager service is excepted.

**Description**

The Bundle Manager service is abnormal.

**Possible Causes**

An unknown system exception occurs.

**Solution**
1. Restart the phone and try again.

2. If the request still fails after the preceding steps are performed for three to five times, check whether a crash file containing **foundation** exists in the **/data/log/faultlog/faultlogger/** directory of the device.
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

## 17700201 .abc File Verification Failure

**Error Message**

Failed to verify the abc file.

**Description**

Failed to verify the .abc file.

**Possible Causes**

The .abc file is untrusted.

**Solution**

Pass in the path of a trusted .abc file.

## 17700202 .abc File Deletion Failure

**Error Message**

Failed to delete the abc file.

**Description**

Failed to delete the .abc file.

**Possible Causes**

The .abc file does not exist.

**Solution**

Pass in a valid path of the .abc file.

## 17700301 Failed to Add Extended Resources
**Error Message**

Failed to add extended resources.

**Description**

Failed to add the extended resources.

**Possible Causes**

The .hsp file does not exist or is untrusted.

**Solution**

Pass in a correct and trusted .hsp file path.

## 17700302 Failed to Delete Extended Resources
**Error Message**

Failed to remove extended resources.

**Description**

Failed to delete the extended resources.

**Possible Causes**

The HSP corresponding to the module name does not exist.

**Solution**

Pass in a valid module name.

## 17700303 Failed to Obtain Extended Resources
**Error Message**

Failed to obtain extended resources.

**Description**

Failed to obtain the extended resources.

**Possible Causes**

The HSP corresponding to the bundle name does not exist.

**Solution**

Pass in a valid bundle name.

## 17700304 Failed to Enable the Dynamic Icon
**Error Message**

Failed to enable the dynamic icon.

**Description**

Failed to enable the dynamic icon.

**Possible Causes**

The HSP does not contain the correct icon resource.

**Solution**

Before enabling the dynamic icon, ensure that the HSP corresponding to the module name is valid and contains the icon resource.

## 17700305 Failed to Disable the Dynamic Icon
**Error Message**

Failed to disable the dynamic icon.

**Description**

Failed to disable the dynamic icon.

**Possible Causes**

The HSP does not contain the correct icon resource.

**Solution**

Before disabling the dynamic icon, ensure that the HSP corresponding to the bundle name contains the icon resource.

## 17700306 Failed to Obtain the Dynamic Icon
**Error Message**

Failed to obtain the dynamic icon.

**Description**

Failed to obtain the dynamic icon.

**Possible Causes**

The HSP does not contain the correct icon resource.

**Solution**

Before querying the dynamic icon, ensure that the HSP corresponding to the bundle name contains the icon resource.
