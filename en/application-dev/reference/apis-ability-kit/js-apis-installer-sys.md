# @ohos.bundle.installer (installer) (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

The module provides APIs for you to install, uninstall, and recover bundles on devices.

## Modules to Import

```js
import { installer } from '@kit.AbilityKit';
```

## BundleInstaller.getBundleInstaller

getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void

Obtains a BundleInstaller object. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<BundleInstaller> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the BundleInstaller object obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types.   |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

try {
    installer.getBundleInstaller((err: BusinessError, data: installer.BundleInstaller) => {
        if (err) {
            console.error('getBundleInstaller failed:' + err.message);
        } else {
            console.info('getBundleInstaller successfully');
        }
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed:' + message);
}
```

## BundleInstaller.getBundleInstaller

getBundleInstaller(): Promise\<BundleInstaller>

Obtains a BundleInstaller object. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**
| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise\<BundleInstaller> | Promise used to return the BundleInstaller object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        console.info('getBundleInstaller successfully.');
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.getBundleInstallerSync<sup>10+</sup>

getBundleInstallerSync(): BundleInstaller

Obtains a BundleInstaller object. This API is a synchronous API.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**
| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| BundleInstaller | BundleInstaller object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

try {
    installer.getBundleInstallerSync();
    console.info('getBundleInstallerSync successfully.');
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstallerSync failed. Cause: ' + message);
}
```

## BundleInstaller.install
install(hapFilePaths: Array&lt;string&gt;, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void

Installs a bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE, ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup>, ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE<sup>10+</sup>, or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE<sup>10+</sup>
> **NOTE**
>
> Starting from API version 10, this API can be called with the permission ohos.permission.INSTALL_ENTERPRISE_BUNDLE, ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE, or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE.
>
> To install an enterprise application, you must have the ohos.permission.INSTALL_ENTERPRISE_BUNDLE permission.
>
> To install an enterprise Normal application, you must have the ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE permission.
>
> To install an enterprise MDM application, you must have the ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE permission.
>
> To install a common application, you must have the ohos.permission.INSTALL_BUNDLE permission.
>
> To install a beta application, you must have the ohos.permission.INSTALL_INTERNALTESTING_BUNDLE permission.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| installParam           | [InstallParam](#installparam)                        | Yes  | Parameters required for the installation.                                    |
| callback | AsyncCallback&lt;void&gt; | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.INSTALL_ENTERPRISE_BUNDLE' or 'ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE' or 'ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE'.   |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter hapFiles is needed for code signature; 4. The size of specifiedDistributionType is greater than 128; 5. The size of additionalInfo is greater than 3000.   |
| 17700004 | The specified user ID is not found.                          |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install the HAP or HSP because the dependent module does not exist. |
| 17700031 | Failed to install the HAP because the overlay check of the HAP failed. |
| 17700036 | Failed to install the HSP due to the lack of required permission. |
| 17700039 | Failed to install the HSP because installing a shared bundle specified by hapFilePaths is not allowed. |
| 17700041 | Failed to install the HAP because the installation is forbidden by enterprise device management. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification failed. |
| 17700050 | Failed to install the HAP because an enterprise normal/MDM bundle cannot be installed on non-enterprise devices. |
| 17700052 | Failed to install the HAP because a debug bundle can be installed only in developer mode. |
| 17700054 | Failed to install the HAP because the HAP requests wrong permissions.|
| 17700058 | Failed to install the HAP because the device has been controlled. |
| 17700066 | Failed to install the HAP because installing the native package failed. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |
| 17700076 | Failed to install the HAP or HSP because the app distribution type is not allowed. |
| 17700077 | Failed to install the HAP and restore to preinstalled bundle. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];
let installParam: installer.InstallParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.install(hapFilePaths, installParam, (err: BusinessError) => {
            if (err) {
                console.error('install failed:' + err.message);
            } else {
                console.info('install successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```
## BundleInstaller.install
install(hapFilePaths: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Installs a bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE, ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup>, ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE<sup>10+</sup>, or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE<sup>10+</sup>
> **NOTE**
>
> Starting from API version 10, this API can be called with the permission ohos.permission.INSTALL_ENTERPRISE_BUNDLE, ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE, or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE.
>
> To install an enterprise application, you must have the ohos.permission.INSTALL_ENTERPRISE_BUNDLE permission.
>
> To install an enterprise Normal application, you must have the ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE permission.
>
> To install an enterprise MDM application, you must have the ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE permission.
>
> To install a common application, you must have the ohos.permission.INSTALL_BUNDLE permission.
>
> To install a beta application, you must have the ohos.permission.INSTALL_INTERNALTESTING_BUNDLE permission.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| callback | AsyncCallback&lt;void&gt; | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.INSTALL_ENTERPRISE_BUNDLE' or 'ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE' or 'ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE'.   |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install the HAP or HSP because the dependent module does not exist. |
| 17700031 | Failed to install the HAP because the overlay check of the HAP failed. |
| 17700036 | Failed to install the HSP due to the lack of required permission. |
| 17700039 | Failed to install the HSP because installing a shared bundle specified by hapFilePaths is not allowed. |
| 17700041 | Failed to install the HAP because the installation is forbidden by enterprise device management. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification failed. |
| 17700050 | Failed to install the HAP because an enterprise normal/MDM bundle cannot be installed on non-enterprise devices. |
| 17700052 | Failed to install the HAP because a debug bundle can be installed only in developer mode. |
| 17700054 | Failed to install the HAP because the HAP requests wrong permissions.|
| 17700058 | Failed to install the HAP because the device has been controlled. |
| 17700066 | Failed to install the HAP because installing the native package failed. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |
| 17700076 | Failed to install the HAP or HSP because the app distribution type is not allowed. |
| 17700077 | Failed to install the HAP and restore to preinstalled bundle. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.install(hapFilePaths, (err: BusinessError) => {
            if (err) {
                console.error('install failed:' + err.message);
            } else {
                console.info('install successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.install

install(hapFilePaths: Array\<string\>, installParam?: InstallParam) : Promise\<void\>

Installs a bundle. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE, ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup>, ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE<sup>10+</sup>, or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE<sup>10+</sup>
> **NOTE**
>
> Starting from API version 10, this API can be called with the permission ohos.permission.INSTALL_ENTERPRISE_BUNDLE, ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE, or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE.
>
> To install an enterprise application, you must have the ohos.permission.INSTALL_ENTERPRISE_BUNDLE permission.
>
> To install an enterprise Normal application, you must have the ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE permission.
>
> To install an enterprise MDM application, you must have the ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE permission.
>
> To install a common application, you must have the ohos.permission.INSTALL_BUNDLE permission.
>
> To install a beta application, you must have the ohos.permission.INSTALL_INTERNALTESTING_BUNDLE permission.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array\<string\>               | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| installParam | [InstallParam](#installparam) | No  | Parameters required for the installation. For details about their default values, see [InstallParam](#installparam).                                    |

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.INSTALL_ENTERPRISE_BUNDLE' or 'ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE' or 'ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE'.   |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter hapFiles is needed for code signature; 4. The size of specifiedDistributionType is greater than 128; 5. The size of additionalInfo is greater than 3000.   |
| 17700004 | The specified user ID is not found.                          |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install the HAP or HSP because the dependent module does not exist. |
| 17700031 | Failed to install the HAP because the overlay check of the HAP failed. |
| 17700036 | Failed to install the HSP due to the lack of required permission. |
| 17700039 | Failed to install the HSP because installing a shared bundle specified by hapFilePaths is not allowed. |
| 17700041 | Failed to install the HAP because the installation is forbidden by enterprise device management. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification failed. |
| 17700050 | Failed to install the HAP because an enterprise normal/MDM bundle cannot be installed on non-enterprise devices. |
| 17700052 | Failed to install the HAP because a debug bundle can be installed only in developer mode. |
| 17700054 | Failed to install the HAP because the HAP requests wrong permissions.|
| 17700058 | Failed to install the HAP because the device has been controlled. |
| 17700066 | Failed to install the HAP because installing the native package failed. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |
| 17700076 | Failed to install the HAP or HSP because the app distribution type is not allowed. |
| 17700077 | Failed to install the HAP and restore to preinstalled bundle. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];
let installParam: installer.InstallParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.install(hapFilePaths, installParam)
            .then((data: void) => {
                console.info('install successfully: ' + JSON.stringify(data));
        }).catch((error: BusinessError) => {
            console.error('install failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.uninstall

uninstall(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void

Uninstalls a bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Name of the target bundle.                                          |
| installParam      | [InstallParam](#installparam)                        | Yes  | Parameters required for the installation.                      |
| callback | AsyncCallback&lt;void&gt; | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.UNINSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |
| 17700045 | Failed to uninstall the HAP because the uninstall is forbidden by enterprise device management. |
| 17700060 | The specified application cannot be uninstalled. |
| 17700062 | Failed to uninstall the app because the app is locked. |
| 17700067 | Failed to uninstall the HAP because uninstalling the native package failed. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.demo';
let installParam: installer.InstallParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.uninstall(bundleName, installParam, (err: BusinessError) => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.uninstall

uninstall(bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Uninstalls a bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Name of the target bundle.                                          |
| callback | AsyncCallback&lt;void&gt; | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.UNINSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |
| 17700045 | Failed to uninstall the HAP because the uninstall is forbidden by enterprise device management. |
| 17700060 | The specified application cannot be uninstalled. |
| 17700067 | Failed to uninstall the HAP because uninstalling the native package failed. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.demo';

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.uninstall(bundleName, (err: BusinessError) => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```
## BundleInstaller.uninstall

uninstall(bundleName: string, installParam?: InstallParam) : Promise\<void\>

Uninstalls a bundle. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                          | Yes  | Name of the target bundle.                                          |
| installParam | [InstallParam](#installparam) | No  | Parameters required for the installation. For details about their default values, see [InstallParam](#installparam).                                    |

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.UNINSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |
| 17700045 | Failed to uninstall the HAP because the uninstall is forbidden by enterprise device management. |
| 17700060 | The specified application cannot be uninstalled. |
| 17700062 | Failed to uninstall the app because the app is locked. |
| 17700067 | Failed to uninstall the HAP because uninstalling the native package failed. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.demo';
let installParam: installer.InstallParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.uninstall(bundleName, installParam)
            .then((data: void) => {
                console.info('uninstall successfully: ' + JSON.stringify(data));
        }).catch((error: BusinessError) => {
            console.error('uninstall failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.recover

recover(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void

Rolls back a bundle to the initial installation state. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.RECOVER_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Name of the target bundle.                                          |
| installParam      | [InstallParam](#installparam)                        | Yes  | Parameters required for the installation.                      |
| callback | AsyncCallback&lt;void&gt; | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.RECOVER_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700058 | Failed to install the HAP because this application is prohibited from being installed on this device or by specified users. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.demo';
let installParam: installer.InstallParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.recover(bundleName, installParam, (err: BusinessError) => {
            if (err) {
                console.error('recover failed:' + err.message);
            } else {
                console.info('recover successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```


## BundleInstaller.recover

recover(bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Rolls back a bundle to the initial installation state. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.RECOVER_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Name of the target bundle.                              |
| callback | AsyncCallback&lt;void&gt; | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.RECOVER_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700058 | Failed to install the HAP because this application is prohibited from being installed on this device or by specified users. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.demo';

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.recover(bundleName, (err: BusinessError) => {
            if (err) {
                console.error('recover failed:' + err.message);
            } else {
                console.info('recover successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.recover

recover(bundleName: string, installParam?: InstallParam) : Promise\<void\>

Rolls back a bundle to the initial installation state. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.RECOVER_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                          | Yes  | Name of the target bundle.                                          |
| installParam | [InstallParam](#installparam) | No  | Parameters required for the installation. For details about their default values, see [InstallParam](#installparam).                                    |

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.RECOVER_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700058 | Failed to install the HAP because this application is prohibited from being installed on this device or by specified users. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**Example**
```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.demo';
let installParam: installer.InstallParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.recover(bundleName, installParam)
            .then((data: void) => {
                console.info('recover successfully: ' + JSON.stringify(data));
        }).catch((error: BusinessError) => {
            console.error('recover failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.uninstall<sup>10+</sup>

uninstall(uninstallParam: UninstallParam, callback : AsyncCallback\<void\>) : void

Uninstalls a shared package. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name        | Type                               | Mandatory| Description                                                    |
| -------------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| uninstallParam | [UninstallParam](#uninstallparam10) | Yes  | Parameters required for the uninstall.                            |
| callback       | AsyncCallback&lt;void&gt;           | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.UNINSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700037 | The version of the shared bundle is dependent on other applications. |
| 17700038 | The specified shared bundle does not exist.                  |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let uninstallParam: installer.UninstallParam = {
    bundleName: "com.ohos.demo",
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.uninstall(uninstallParam, (err: BusinessError) => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.uninstall<sup>10+</sup>

uninstall(uninstallParam: UninstallParam) : Promise\<void>

Uninstalls a shared package. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name        | Type                               | Mandatory| Description                        |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| uninstallParam | [UninstallParam](#uninstallparam10) | Yes  | Parameters required for the uninstall.|

**Return value**

| Type         | Description                                  |
| ------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.UNINSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700037 | The version of the shared bundle is dependent on other applications. |
| 17700038 | The specified shared bundle does not exist.                  |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let uninstallParam: installer.UninstallParam = {
    bundleName: "com.ohos.demo",
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.uninstall(uninstallParam, (err: BusinessError) => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.addExtResource<sup>12+</sup>

addExtResource(bundleName: string, filePaths: Array\<string>): Promise\<void>;

Adds extended resources based on the specified bundle name and HSP file path. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name        | Type                               | Mandatory| Description                        |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name of the application to which extended resources are to be added.|
| filePaths | Array\<string> | Yes  | Path of the extended resources to be added.|

**Return value**

| Type         | Description                                  |
| ------------- | -------------------------------------- |
| Promise\<void> | that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700301 | Failed to add extended resources.                 |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import hilog from '@ohos.hilog';
import { BusinessError } from '@ohos.base';

let bundleName : string = 'com.ohos.demo';
let filePaths : Array<string> = ['/data/storage/el2/base/a.hsp'];
try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.addExtResource(bundleName, filePaths).then((data) => {
            hilog.info(0x0000, 'testTag', 'addExtResource successfully');
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'addExtResource failed. Cause: %{public}s', err.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.removeExtResource<sup>12+</sup>

removeExtResource(bundleName: string, moduleNames: Array\<string>): Promise\<void>;

Removes extended resources based on the specified bundle name and HSP file path. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name        | Type                               | Mandatory| Description                        |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name of the application for which extended resources are to be removed.|
| moduleNames | Array\<string> | Yes  | Names of the modules whose extended resources are to be removed.|

**Return value**

| Type         | Description                                  |
| ------------- | -------------------------------------- |
| Promise\<void> | that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700302 | Failed to remove extended resources.                  |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import hilog from '@ohos.hilog';
import { BusinessError } from '@ohos.base';

let bundleName : string = 'com.ohos.demo';
let moduleNames : Array<string> = ['moduleTest'];
try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.removeExtResource(bundleName, moduleNames).then((data) => {
            hilog.info(0x0000, 'testTag', 'removeExtResource successfully');
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'removeExtResource failed. Cause: %{public}s', err.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.updateBundleForSelf<sup>10+</sup>

updateBundleForSelf(hapFilePaths: Array\<string\>, installParam: InstallParam, callback: AsyncCallback\<void\>): void

Updates the current bundle. This API uses an asynchronous callback to return the result. It can be called only by enterprise MDM applications on enterprise devices, and the HAPs in **hapFilePaths** must belong to the current application.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_SELF_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| installParam           | [InstallParam](#installparam)                        | Yes  | Parameters required for the installation.                                    |
| callback | AsyncCallback&lt;void&gt; | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_SELF_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter hapFiles is needed for code signature; 4. The size of specifiedDistributionType is greater than 128; 5. The size of additionalInfo is greater than 3000. |
| 17700004 | The specified user ID is not found.                          |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install the HAP or HSP because the dependent module does not exist. |
| 17700039 | Failed to install the HSP because installing a shared bundle specified by hapFilePaths is not allowed. |
| 17700041 | Failed to install the HAP because the installation is forbidden by enterprise device management. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification failed. |
| 17700049 | Failed to install the HAP because the bundleName is different from the bundleName of the caller application. |
| 17700050 | Failed to install the HAP because an enterprise normal/MDM bundle cannot be installed on non-enterprise devices. |
| 17700051 | Failed to install the HAP because the distribution type of the caller application is not enterprise_mdm. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];
let installParam: installer.InstallParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.updateBundleForSelf(hapFilePaths, installParam, (err: BusinessError) => {
            if (err) {
                console.error('updateBundleForSelf failed:' + err.message);
            } else {
                console.info('updateBundleForSelf successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.updateBundleForSelf<sup>10+</sup>

updateBundleForSelf(hapFilePaths: Array\<string\>, callback: AsyncCallback\<void\>): void

Updates the current bundle. This API uses an asynchronous callback to return the result. It can be called only by enterprise MDM applications on enterprise devices, and the HAPs in **hapFilePaths** must belong to the current application.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_SELF_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| callback | AsyncCallback&lt;void&gt; | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_SELF_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install the HAP or HSP because the dependent module does not exist. |
| 17700039 | Failed to install the HSP because installing a shared bundle specified by hapFilePaths is not allowed. |
| 17700041 | Failed to install the HAP because the installation is forbidden by enterprise device management. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification failed. |
| 17700049 | Failed to install the HAP because the bundleName is different from the bundleName of the caller application. |
| 17700050 | Failed to install the HAP because an enterprise normal/MDM bundle cannot be installed on non-enterprise devices. |
| 17700051 | Failed to install the HAP because the distribution type of the caller application is not enterprise_mdm. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.updateBundleForSelf(hapFilePaths, (err: BusinessError) => {
            if (err) {
                console.error('updateBundleForSelf failed:' + err.message);
            } else {
                console.info('updateBundleForSelf successfully.');
            }
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.updateBundleForSelf<sup>10+</sup>

updateBundleForSelf(hapFilePaths: Array\<string\>, installParam?: InstallParam): Promise\<void\>

Updates the current bundle. This API uses a promise to return the result. It can be called only by enterprise MDM applications on enterprise devices, and the HAPs in **hapFilePaths** must belong to the current application.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_SELF_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| installParam | [InstallParam](#installparam) | No  | Parameters required for the installation. For details about their default values, see [InstallParam](#installparam).                                    |

**Return value**

| Type         | Description                                  |
| ------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_SELF_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter hapFiles is needed for code signature; 4. The size of specifiedDistributionType is greater than 128; 5. The size of additionalInfo is greater than 3000. |
| 17700004 | The specified user ID is not found.                          |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install the HAP or HSP because the dependent module does not exist. |
| 17700039 | Failed to install the HSP because installing a shared bundle specified by hapFilePaths is not allowed. |
| 17700041 | Failed to install the HAP because the installation is forbidden by enterprise device management. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification failed. |
| 17700049 | Failed to install the HAP because the bundleName is different from the bundleName of the caller application. |
| 17700050 | Failed to install the HAP because an enterprise normal/MDM bundle cannot be installed on non-enterprise devices. |
| 17700051 | Failed to install the HAP because the distribution type of the caller application is not enterprise_mdm. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];
let installParam: installer.InstallParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.updateBundleForSelf(hapFilePaths, installParam)
            .then((data: void) => {
                console.info('updateBundleForSelf successfully: ' + JSON.stringify(data));
        }).catch((error: BusinessError) => {
            console.error('updateBundleForSelf failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.uninstallUpdates<sup>12+</sup>

uninstallUpdates(bundleName: string, installParam?: InstallParam): Promise\<void\>;

Uninstalls and updates a preinstalled application and restores it to the initial installation status. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.RECOVER_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | Yes  | Name of the target bundle.                                                 |
| installParam | [InstallParam](#installparam) | No  | Parameters required for the uninstall and update. For details about their default values, see [InstallParam](#installparam). The **userId** parameter cannot be specified. Calling this API will uninstall and update the application for all users.|

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.UNINSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700045 | Failed to uninstall the HAP because the uninstall is forbidden by enterprise device management. |
| 17700057 | Failed to uninstall updates because the HAP is not pre-installed. |
| 17700060 | The specified application cannot be uninstalled. |
| 17700067 | Failed to uninstall the HAP because uninstalling the native package failed. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**Example**

```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.camera';
let installParam: installer.InstallParam = {
    isKeepData: true,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.uninstallUpdates(bundleName, installParam)
            .then(() => {
                console.info('uninstallUpdates successfully.');
        }).catch((error: BusinessError) => {
            console.error('uninstallUpdates failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.createAppClone<sup>12+</sup>

createAppClone(bundleName: string, createAppCloneParam?: CreateAppCloneParam): Promise\<number\>;

Creates an application clone. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_CLONE_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | Yes  | Bundle name of the application for which a clone is to be created.                                        |
| createAppCloneParam  | [createAppCloneParam](#createappcloneparam12)   | No  | Other parameters required for creating the clone. For details about the default values of these parameters, see [createAppCloneParam](#createappcloneparam12).  |

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<number\> | Promise used to return the index of the application clone.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_CLONE_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName cannot be found or the bundle is not installed by the specified user. |
| 17700004 | The userId is invalid. |
| 17700061 | The appIndex is not in valid range or already exists. |
| 17700069 | The app does not support the creation of an appClone instance. |

**Example**
```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.camera';
let createAppCloneParam: installer.CreateAppCloneParam = {
    userId: 100,
    appIndex: 1,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.createAppClone(bundleName, createAppCloneParam)
            .then(() => {
                console.info('createAppClone successfully.');
        }).catch((error: BusinessError) => {
            console.error('createAppClone failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.destroyAppClone<sup>12+</sup>

destroyAppClone(bundleName: string, appIndex: number, userId?: number): Promise\<void\>;

Destroys an application clone. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.UNINSTALL_CLONE_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | Yes  | Bundle name of the application for which a clone is to be destroyed.                                        |
| appIndex     | number                        | Yes  | Index of the clone to destroy.                                        |
| userId       | number                        | No  | ID of the user for whom the clone is to be destroyed. You can obtain the user ID by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.                |

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.UNINSTALL_CLONE_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName cannot be found or the bundle is not installed by the specified user. |
| 17700004 | The userId is invalid. |
| 17700061 | The appIndex is invalid. |

**Example**
```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.camera';
let index = 1;
let userId = 100;

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.destroyAppClone(bundleName, index, userId)
            .then(() => {
                console.info('destroyAppClone successfully.');
        }).catch((error: BusinessError) => {
            console.error('destroyAppClone failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.destroyAppClone<sup>15+</sup>

destroyAppClone(bundleName: string, appIndex: number, destroyAppCloneParam?: DestroyAppCloneParam): Promise\<void\>;

Destroys an application clone. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.UNINSTALL_CLONE_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | Yes  | Bundle name of the application for which a clone is to be destroyed.                                        |
| appIndex     | number                        | Yes  | Index of the clone to destroy.                                        |
| destroyAppCloneParam       | [DestroyAppCloneParam](#destroyappcloneparam15)   | No  | Other parameters required for destroying the clone. For details about the default values of these parameters, see [DestroyAppCloneParam](#destroyappcloneparam15).  |

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.UNINSTALL_CLONE_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 17700001 | The specified bundleName cannot be found or the bundle is not installed by the specified user. |
| 17700004 | The userId is invalid. |
| 17700061 | The appIndex is invalid. |
| 17700062 | Failed to uninstall the app because the app is locked. |

**Example**
```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.camera';
let index = 1;
let userId = 100;
let key = 'ohos.bms.param.verifyUninstallRule';
let value = 'false';
let item: installer.Parameters = {key, value};
let destroyAppCloneOpt: installer.DestroyAppCloneParam = {
    userId: userId,
    parameters: [item]
};


try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.destroyAppClone(bundleName, index, destroyAppCloneOpt)
            .then(() => {
                console.info('destroyAppClone successfully.');
        }).catch((error: BusinessError) => {
            console.error('destroyAppClone failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.installPreexistingApp<sup>12+</sup>

installPreexistingApp(bundleName: string, userId?: number): Promise\<void\>;

Installs a bundle. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | Yes  | Bundle name of the application to install.                                          |
| userId       | number                        | No  | ID of the user for whom the bundle is to be installed. You can obtain the user ID by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The value must be greater than 0. The default value is the user ID of the caller.   |

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName cannot be found. |
| 17700004 | The userId is invalid. |
| 17700071 | It is not allowed to install the enterprise bundle. |
| 17700058 | Failed to install the HAP because this application is prohibited from being installed on this device or by specified users. |

**Example**
```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.ohos.camera';
let userId = 100;

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.installPreexistingApp(bundleName, userId)
            .then(() => {
                console.info('installPreexistingApp successfully.');
        }).catch((error: BusinessError) => {
            console.error('installPreexistingApp failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.installPlugin<sup>19+</sup>

installPlugin(hostBundleName: string, pluginFilePaths: Array\<string\>, pluginParam?: PluginParam): Promise\<void\> 

Installs a plugin for an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_PLUGIN_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| hostBundleName   | string                        | Yes  | Bundle name of the application for which the plugin is to be installed.                                          |
| pluginFilePaths  | Array\<string\>                  | Yes  | Paths where the plugin package files are stored. If multiple file paths or a directory is provided, ensure that these files are HSPs of the same plugin program and their signatures are consistent. |
| pluginParam  | [PluginParam](#pluginparam19)      | No  | Parameters required for installing the plugin. For details about the default value, see [PluginParam](#pluginparam19).|

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_PLUGIN_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17700001 | The specified hostBundleName cannot be found or the bundle is not installed by the specified user. |
| 17700004 | The userId is invalid. |
| 17700010 | Failed to install the plugin because the plugin fails to be parsed. |
| 17700011 | Failed to install the plugin because the plugin signature fails to be verified. |
| 17700012 | Failed to install the plugin because the HSP path is invalid or the HSP is too large. |
| 17700015 | Failed to install the plugin because they have different configuration information. |
| 17700016 | Failed to install the plugin because of insufficient system disk space. |
| 17700017 | Failed to install the plugin since the version of the plugin to install is too early. |
| 17700048 | Failed to install the plugin because the code signature verification is failed. |
| 17700052 | Failed to install the plugin because debug bundle cannot be installed under non-developer mode. |
| 17700073 | Failed to install the plugin because a plugin with the same bundle name but different signature information exists on the device. |
| 17700087 | Failed to install the plugin because the current device does not support plugin. |
| 17700088 | Failed to install the plugin because the host application lacks ohos.permission.kernel.SUPPORT_PLUGIN. |
| 17700089 | Failed to install the plugin because the plugin id fails to be parsed. |
| 17700090 | Failed to install the plugin because the plugin id fails to be verified. |
| 17700091 | Failed to install the plugin because the plugin name is same as host bundle name. |

**Example**
```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let hostBundleName = 'com.example.application';
let pluginFilePaths = ['/data/bms_app_install/test.hsp'];
let pluginParam : installer.PluginParam = {
    userId : 100,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.installPlugin(hostBundleName, pluginFilePaths, pluginParam)
            .then(() => {
                console.info('installPlugin successfully.');
        }).catch((error: BusinessError) => {
            console.error('installPlugin failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('installPlugin failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## BundleInstaller.uninstallPlugin<sup>19+</sup>

uninstallPlugin(hostBundleName: string, pluginBundleName: string, pluginParam?: PluginParam): Promise\<void\>

Uninstalls a plugin for an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.UNINSTALL_PLUGIN_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| hostBundleName   | string                        | Yes  | Bundle name of the application for which the plugin is to be uninstalled.                      |
| pluginBundleName  | string                  | Yes  |   Bundle name of the plugin.|
| pluginParam  | [PluginParam](#pluginparam19)      | No  | Parameters required for uninstalling the plugin. For details about the default value, see [PluginParam](#pluginparam19).|

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.UNINSTALL_PLUGIN_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17700001 | The specified bundle name is not found. |
| 17700004 | The user id is invalid. |
| 17700092 | Failed to uninstall the plugin because the specified plugin is not found. |

**Example**
```ts
import { installer } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let hostBundleName = 'com.example.application';
let pluginBundleName = 'com.ohos.pluginDemo';
let pluginParam : installer.PluginParam = {
    userId : 100,
};

try {
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {
        data.uninstallPlugin(hostBundleName, pluginBundleName, pluginParam)
            .then(() => {
                console.info('uninstallPlugin successfully.');
        }).catch((error: BusinessError) => {
            console.error('uninstallPlugin failed:' + error.message);
        });
    }).catch((error: BusinessError) => {
        console.error('uninstallPlugin failed. Cause: ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getBundleInstaller failed. Cause: ' + message);
}
```

## HashParam

Defines the hash parameters for bundle installation and uninstall.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name    | Type  | Read-Only| Optional| Description            |
| ---------- | ------ | ---------------- |------- | ---------------- |
| moduleName | string | No| No| Module name of the bundle.|
| hashValue  | string | No| No| Hash value.          |

## InstallParam

Defines the parameters that need to be specified for bundle installation, uninstall, or recovering.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name                       | Type                          |  Read-Only |  Optional | Description              |
| ------------------------------ | ------------------------------ | ------------------| ------------------ | ------------------ |
| userId                         | number                         | No                      | Yes | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0. You can call [queryOsAccountLocalIdFromProcess](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) to obtain the user ID of the current process. When a driver application is installed, uninstalled, or restored, this parameter is ignored and the operation is executed for all users.|
| installFlag                    | number                         | No                      | Yes| Installation flag. The value **0x00** means initial installation, **0x01** means overwrite installation, and **0x10** means installation-free. The default value is **0x00**.|
| isKeepData                     | boolean                        | No                      | Yes| Whether to retain the data directory during bundle uninstall. The default value is **false**. **true** to retain, **false** otherwise.|
| hashParams        | Array<[HashParam](#hashparam)> | No| Yes| Hash parameters. By default, no value is passed.        |
| crowdtestDeadline| number                         | No                      | Yes| End date of crowdtesting. The default value is **-1**, indicating that no end date is specified for crowdtesting.|
| sharedBundleDirPaths<sup>10+</sup> | Array\<string> | No| Yes|Paths of the shared bundle files. By default, no value is passed.|
| specifiedDistributionType<sup>10+</sup> | string | No| Yes|[Distribution type](../../security/app-provision-structure.md) specified during application installation. By default, no value is passed. The maximum length is 128 bytes. This field is usually specified by the application market of the operating system operator.|
| additionalInfo<sup>10+</sup> | string | No| Yes|Additional information during application installation (usually an enterprise application). By default, no value is passed. The maximum length is 3,000 bytes. This field is usually specified by the application market of the operating system operator.|
| verifyCodeParams<sup>deprecated<sup> | Array<[VerifyCodeParam](#verifycodeparamdeprecated)> | No| Yes| Information about the code signature file. The default value is null.        |
| pgoParams<sup>11+</sup> | Array<[PGOParam](#pgoparam11)> | No| Yes| Parameters of the Profile-guided Optimization (PGO) configuration file. The default value is null.        |
| parameters<sup>15+</sup> | Array<[Parameters](#parameters15)> | No| Yes| Extended parameters, represented as an array of the Parameters type. The default value is empty. The options of **Parameters.key** are as follows:<br> - **ohos.bms.param.renameInstall**: If the value is **true**, the installation package is moved from the application sandbox to the installation directory using a shared directory. Otherwise, it is copied from the application sandbox to the installation directory using a regular directory.<br> - **ohos.bms.param.enterpriseForAllUser**: If the value is **true**, the enterprise application is installed for all users.<br> - **ohos.bms.param.verifyUninstallRule**: If the value is **true**, an uninstallation handling rule is set to block application uninstallation.<br> - **ohos.bms.param.enterpriseManifest**: The value is the sandbox path of the JSON file used to store the application's manifest, including the bundle name. It is used in the scenario of cloning enterprise applications. If this JSON file exists during cloning, the application package from the old device is copied to the new device for installation.|
## UninstallParam<sup>10+</sup>

Defines the parameters required for the uninstall of a shared bundle.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name       | Type   |  Read-Only |  Optional | Description                                                        |
| ----------- | ------ | ---- |---- | ------------------------------------------------------------ |
| bundleName  | string | No| No | Name of the shared bundle.                                                |
| versionCode | number | No| Yes | Version number of the shared bundle. By default, no value is passed, and all shared bundles of the specified name are uninstalled.|

## VerifyCodeParam<sup>deprecated<sup>

> Starting from API version 11, the code signature file of an application is integrated into the installation package, rather than being specified by using this field.

Defines the information about the code signature file.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name    | Type  |  Read-Only |  Optional | Description            |
| ---------- | ------ |------ | ---------------- | ---------------- |
| moduleName | string |  No| No| Module name of the bundle.|
| signatureFilePath  | string |  No| No| Path of the code signature file.          |

## PGOParam<sup>11+</sup>

Defines the parameters of the PGO configuration file.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name    | Type  | Read-Only |  Optional  | Description            |
| ---------- | ------ | ------ | ---------------- | ---------------- |
| moduleName | string |  No| No| Module name of the bundle.|
| pgoFilePath  | string |  No| No| Path of the PGO configuration file.          |

## Parameters<sup>15+</sup>

Describes the extended parameter information.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name    | Type  | Read-Only |  Optional | Description            |
| ---------- | ------ |------ | ---------------- | ---------------- |
| key | string | No| No| Key of an extended parameter.|
| value  | string | No| No| Value of the extended parameter. |

## CreateAppCloneParam<sup>12+</sup>

Describes the parameters used for creating an application clone.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name       | Type  | Read-Only |  Optional| Description                                                         |
| ----------- | ------ | ---- |---- | ------------------------------------------------------------ |
| userId      | number | No| Yes | ID of the user for whom the clone is to be created. You can obtain the user ID by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.            |
| appIndex    | number |  No| Yes  | Index of the clone. The default value is the currently available minimum index.          |

## DestroyAppCloneParam<sup>15+</sup>

Describes the parameters used for destroying an application clone.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name       | Type  | Read-Only |  Optional| Description                                                         |
| ----------- | ------ | ----| ---- | ------------------------------------------------------------ |
| userId      | number | No| Yes | ID of the user for whom the clone is to be destroyed. You can obtain the user ID by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.            |
| parameters  | Array<[Parameters](#parameters15)> | No| Yes  | Extended parameters for destroying the clone. The default value is null.           |

## PluginParam<sup>19+</sup>

Defines the parameters for installing or uninstalling a plugin.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name       | Type  | Read-Only |  Optional| Description                                                         |
| ----------- | ------ | ---- |---- | ------------------------------------------------------------ |
| userId      | number | No| Yes  | ID of the user for whom the plugin is to be installed or uninstalled. You can obtain the user ID by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.            |
| parameters  | Array<[Parameters](#parameters15)> | No| Yes  | Extension parameters for installing or uninstalling the plugin. The default value is empty.           |
