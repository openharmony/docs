# BundleInstaller

The **BundleInstaller** module provides APIs for you to install, uninstall, and recover bundles on devices.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## BundleInstaller.install<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [install](js-apis-installer.md) instead.

install(bundleFilePaths: Array&lt;string&gt;, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

Installs a bundle. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name         | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored. Each path should point to a relative directory of the current bundle's data directory.|
| param           | [InstallParam](#installparam)                        | Yes  | Parameters required for bundle installation.                                    |
| callback        | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | Yes  | Callback used to return the installation status.              |

## BundleInstaller.uninstall<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [uninstall](js-apis-installer.md) instead.

uninstall(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

Uninstalls a bundle. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Bundle name.                                          |
| param      | [InstallParam](#installparam)                        | Yes  | Parameters required for bundle uninstall.                      |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | Yes  | Callback used to return the installation status.|

## BundleInstaller.recover<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [recover](js-apis-installer.md) instead.

recover(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

Recovers a bundle. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Bundle name.                                          |
| param      | [InstallParam](#installparam)                        | Yes  | Parameters required for bundle recovering.                      |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | Yes  | Callback used to return the installation status.|

## InstallParam<sup>(deprecated)<sup>

Describes the parameters required for bundle installation or uninstall.

 **System capability**: SystemCapability.BundleManager.BundleFramework

 **System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type   | Readable| Writable| Description              |
| ----------- | ------- | ---- | ---- | ------------------ |
| userId      | number  | Yes  | No  | User ID.        |
| installFlag | number  | Yes  | No  | Installation flag.      |
| isKeepData  | boolean | Yes  | No  | Whether data is kept.|

## InstallStatus<sup>(deprecated)<sup>

Describes the bundle installation status.

 **System capability**: SystemCapability.BundleManager.BundleFramework

 **System API**: This is a system API and cannot be called by third-party applications.

| Name         | Type                                                        | Readable| Writable| Description                          |
| ------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------ |
| status        | bundle.[InstallErrorCode](js-apis-Bundle.md#installerrorcode) | Yes  | No  | Installation or uninstall error code.      |
| statusMessage | string                                                       | Yes  | No  | Installation or uninstall status message.|
