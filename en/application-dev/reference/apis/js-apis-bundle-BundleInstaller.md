# BundleInstaller

The **BundleInstaller** module provides APIs for installing, updating, and deleting bundles on devices.

> **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## BundleInstaller.install

install(bundleFilePaths: Array&lt;string&gt;, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

Installs bundles. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name           | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the bundles are stored. Each path should point to a relative directory of the current application's data directory.|
| param           | [InstallParam](#installparam)                        | Yes  | Parameters required for the installation or uninstall.                                    |
| callback        | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | Yes  | Callback used to return the installation status.              |

## BundleInstaller.uninstall

uninstall(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

Uninstalls a bundle. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Bundle name.                                          |
| param      | [InstallParam](#installparam)                        | Yes  | Parameters required for the installation or uninstall.                      |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | Yes  | Callback used to return the installation status.|

## BundleInstaller.recover<sup>8+</sup>

recover(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

Recovers a bundle. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Bundle name.                                          |
| param      | [InstallParam](#installparam)                        | Yes  | Parameters required for the installation or uninstall.                      |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | Yes  | Callback used to return the installation status.|

## HashParam<sup>9+</sup>

Describes the parameters required for bundle installation or uninstall.

 **System capability**: SystemCapability.BundleManager.BundleFramework

 **System API**: This is a system API and cannot be called by third-party applications.

| Name      | Type  | Description            |
| ---------- | ------ | ---------------- |
| moduleName | string | Module name of the application.|
| hashValue  | string | Hash value.          |

## InstallParam

Describes the parameters required for bundle installation or uninstall.

 **System capability**: SystemCapability.BundleManager.BundleFramework

 **System API**: This is a system API and cannot be called by third-party applications.

| Name                          | Type                          | Description              |
| ------------------------------ | ------------------------------ | ------------------ |
| userId                         | number                         | User ID.        |
| installFlag                    | number                         | Installation flag.      |
| isKeepData                     | boolean                        | Whether data is kept.|
| hashParams<sup>9+</sup>        | Array<[HashParam](#hashparam)> | Hash parameters.        |
| crowdtestDeadline<sup>9+</sup> | number                         | Time when the test package is killed.|

## InstallStatus

Describes the bundle installation status.

 **System capability**: SystemCapability.BundleManager.BundleFramework

 **System API**: This is a system API and cannot be called by third-party applications.

| Name         | Type                                                        | Readable| Writable| Description                          |
| ------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------ |
| status        | bundle.[InstallErrorCode](js-apis-Bundle.md#installerrorcode) | Yes  | No  | Installation or uninstall error code.      |
| statusMessage | string                                                       | Yes  | No  | Installation or uninstall status message.|
