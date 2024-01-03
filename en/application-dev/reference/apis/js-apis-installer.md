# @ohos.bundle.installer (installer)

The **bundle.installer** module provides APIs for you to install, uninstall, and recover bundles on devices.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import installer from '@ohos.bundle.installer';
```

## Required Permissions

| Permission                          | Permission Level   | Description            |
| ------------------------------ | ----------- | ---------------- |
| ohos.permission.INSTALL_BUNDLE | system_core | Permission to install or uninstall other applications except enterprise applications, including enterprise InHouse, mobile device management (MDM), and Normal applications.|
| ohos.permission.INSTALL_ENTERPRISE_BUNDLE | system_core | Permission to install enterprise InHouse applications.|
| ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE | system_core | Permission to install enterprise MDM applications.|
| ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE | system_core | Permission to install enterprise Normal applications.|
| ohos.permission.UNINSTALL_BUNDLE | system_core | Allows an application to uninstall applications.|
| ohos.permission.RECOVER_BUNDLE | system_core | Allows an application to restore pre-installed applications.|
| ohos.permission.INSTALL_SELF_BUNDLE | system_core | Allows automatic updates of the enterprise MDM applications on enterprise devices.|


For details, see [Permission Levels](../../security/accesstoken-overview.md#permission-levels).

## BundleInstaller.getBundleInstaller

getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void;

Obtains a **BundleInstaller** object. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[BundleInstaller](js-apis-installer.md#BundleInstaller)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the **BundleInstaller** object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

getBundleInstaller(): Promise\<BundleInstaller>;

Obtains a **BundleInstaller** object. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**
| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise\<[BundleInstaller](js-apis-installer.md#BundleInstaller)> | Promise used to return the **BundleInstaller** object obtained.|

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

getBundleInstallerSync(): BundleInstaller;

Obtains a **BundleInstaller** object. This API is a synchronous API.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**
| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| [BundleInstaller](js-apis-installer.md#BundleInstaller) | **BundleInstaller** object.|

**Example**

```ts
import installer from '@ohos.bundle.installer';
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
install(hapFilePaths: Array&lt;string&gt;, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void;

Installs a bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE, ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup>, ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE<sup>10+</sup>, or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE<sup>10+</sup>
> **NOTE**
>
> From API version 10, this API can be called with the permission **ohos.permission.INSTALL_ENTERPRISE_BUNDLE**, **ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE**, or **ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE**.
>
> To install an enterprise application, you must have the **ohos.permission.INSTALL_ENTERPRISE_BUNDLE** permission.
>
> To install an enterprise Normal application, you must have the **ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE** or **ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE** permission.
>
> To install an enterprise MDM application, you must have the **ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE** permission.
>
> To install a common application, you must have the **ohos.permission.INSTALL_BUNDLE** permission.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| installParam           | [InstallParam](#installparam)                        | Yes  | Parameters required for the installation.                                    |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700004 | The specified user ID is not found.                          |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install because the dependent module does not exist. |
| 17700031 | Failed to install the HAP because the overlay check of the HAP is failed. |
| 17700036 | Failed to install the HSP because lacks appropriate permissions. |
| 17700039 | Failed to install because disallow install a shared bundle by hapFilePaths. |
| 17700041 | Failed to install because enterprise device management disallow install. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification is failed. |
| 17700050 | Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device. |
| 17700052 | Failed to install the HAP because debug bundle cannot be installed under non-developer mode. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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
install(hapFilePaths: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void;

Installs a bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE, ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup>, ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE<sup>10+</sup>, or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE<sup>10+</sup>
> **NOTE**
>
> From API version 10, this API can be called with the permission **ohos.permission.INSTALL_ENTERPRISE_BUNDLE**, **ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE**, or **ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE**.
>
> To install an enterprise application, you must have the **ohos.permission.INSTALL_ENTERPRISE_BUNDLE** permission.
>
> To install an enterprise Normal application, you must have the **ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE** or **ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE** permission.
>
> To install an enterprise MDM application, you must have the **ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE** permission.
>
> To install a common application, you must have the **ohos.permission.INSTALL_BUNDLE** permission.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install because the dependent module does not exist. |
| 17700031 | Failed to install the HAP because the overlay check of the HAP is failed. |
| 17700036 | Failed to install the HSP because lacks appropriate permissions. |
| 17700039 | Failed to install because disallow install a shared bundle by hapFilePaths. |
| 17700041 | Failed to install because enterprise device management disallow install. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification is failed. |
| 17700050 | Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device. |
| 17700052 | Failed to install the HAP because debug bundle cannot be installed under non-developer mode. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

install(hapFilePaths: Array\<string\>, installParam?: InstallParam) : Promise\<void\>;

Installs a bundle. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE, ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup>, ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE<sup>10+</sup>, or ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE<sup>10+</sup>
> **NOTE**
>
> From API version 10, this API can be called with the permission **ohos.permission.INSTALL_ENTERPRISE_BUNDLE**, **ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE**, or **ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE**.
>
> To install an enterprise application, you must have the **ohos.permission.INSTALL_ENTERPRISE_BUNDLE** permission.
>
> To install an enterprise Normal application, you must have the **ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE** or **ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE** permission.
>
> To install an enterprise MDM application, you must have the **ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE** permission.
>
> To install a common application, you must have the **ohos.permission.INSTALL_BUNDLE** permission.

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

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700004 | The specified user ID is not found.                          |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install because the dependent module does not exist. |
| 17700031 | Failed to install the HAP because the overlay check of the HAP is failed. |
| 17700036 | Failed to install the HSP because lacks appropriate permissions. |
| 17700039 | Failed to install because disallow install a shared bundle by hapFilePaths. |
| 17700041 | Failed to install because enterprise device management disallow install. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification is failed. |
| 17700050 | Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device. |
| 17700052 | Failed to install the HAP because debug bundle cannot be installed under non-developer mode. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

uninstall(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void;

Uninstalls a bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Name of the target bundle.                                          |
| installParam      | [InstallParam](#installparam)                        | Yes  | Parameters required for the uninstall.                      |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |
| 17700045 | Failed to uninstall because enterprise device management disallow uninstall. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

uninstall(bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

Uninstalls a bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Name of the target bundle.                                          |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700001 | The specified bundle name is not found. |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |
| 17700045 | Failed to uninstall because enterprise device management disallow uninstall. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

uninstall(bundleName: string, installParam?: InstallParam) : Promise\<void\>;

Uninstalls a bundle. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                          | Yes  | Name of the target bundle.                                          |
| installParam | [InstallParam](#installparam) | No  | Parameters required for the uninstall. For details about their default values, see [InstallParam](#installparam).                                    |

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |
| 17700045 | Failed to uninstall because enterprise device management disallow uninstall. |

**Example**
```ts
import installer from '@ohos.bundle.installer';
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

recover(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void;

Rolls back a bundle to the initial installation state. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.RECOVER_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Name of the target bundle.                                          |
| installParam      | [InstallParam](#installparam)                        | Yes  | Parameters required for the recovery.                      |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

recover(bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

Rolls back a bundle to the initial installation state. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.RECOVER_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | Yes  | Name of the target bundle.                              |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 17700001 | The specified bundle name is not found. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

recover(bundleName: string, installParam?: InstallParam) : Promise\<void\>;

Rolls back a bundle to the initial installation state. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.RECOVER_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                          | Yes  | Name of the target bundle.                                          |
| installParam | [InstallParam](#installparam) | No  | Parameters required for the recovery. For details about their default values, see [InstallParam](#installparam).                                    |

**Return value**

| Type           | Description                                  |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |

**Example**
```ts
import installer from '@ohos.bundle.installer';
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

uninstall(uninstallParam: UninstallParam, callback : AsyncCallback\<void>) : void ;

Uninstalls a shared bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name        | Type                               | Mandatory| Description                                                    |
| -------------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| uninstallParam | [UninstallParam](#uninstallparam10) | Yes  | Parameters required for the uninstall.                            |
| callback       | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700037 | The version of shared bundle is dependent on other applications. |
| 17700038 | The specified shared bundle does not exist.                  |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

uninstall(uninstallParam: UninstallParam) : Promise\<void>;

Uninstalls a shared bundle. This API uses a promise to return the result.

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

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700037 | The version of shared bundle is dependent on other applications. |
| 17700038 | The specified shared bundle does not exist.                  |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

## BundleInstaller.updateBundleForSelf<sup>10+</sup>

updateBundleForSelf(hapFilePaths: Array\<string\>, installParam: InstallParam, callback: AsyncCallback\<void\>): void;

Updates the current bundle. This API uses an asynchronous callback to return the result. It can be called only by enterprise MDM applications on enterprise devices, and the HAPs in **hapFilePaths** must belong to the current application.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_SELF_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| installParam           | [InstallParam](#installparam)                        | Yes  | Parameters required for the installation.                                    |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700004 | The specified user ID is not found.                          |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install because the dependent module does not exist. |
| 17700039 | Failed to install because disallow install a shared bundle by hapFilePaths. |
| 17700041 | Failed to install because enterprise device management disallow install. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification is failed. |
| 17700049 | Failed to install the HAP because the bundleName is different from the bundleName of the caller application. |
| 17700050 | Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device. |
| 17700051 | Failed to install the HAP because the distribution type of caller application is not enterprise_mdm. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

updateBundleForSelf(hapFilePaths: Array\<string\>, callback: AsyncCallback\<void\>): void;

Updates the current bundle. This API uses an asynchronous callback to return the result. It can be called only by enterprise MDM applications on enterprise devices, and the HAPs in **hapFilePaths** must belong to the current application.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_SELF_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install because the dependent module does not exist. |
| 17700039 | Failed to install because disallow install a shared bundle by hapFilePaths. |
| 17700041 | Failed to install because enterprise device management disallow install. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification is failed. |
| 17700049 | Failed to install the HAP because the bundleName is different from the bundleName of the caller application. |
| 17700050 | Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device. |
| 17700051 | Failed to install the HAP because the distribution type of caller application is not enterprise_mdm. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

updateBundleForSelf(hapFilePaths: Array\<string\>, installParam?: InstallParam): Promise\<void\>;

Updates the current bundle. This API uses a promise to return the result. It can be called only by enterprise MDM applications on enterprise devices, and the HAPs in **hapFilePaths** must belong to the current application.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_SELF_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | Yes  | Paths where the HAP files of the bundle are stored, which are the data directories. If only one directory is passed, the HAP files in the directory must belong to the same bundle and have the same signature.|
| installParam | [InstallParam](#installparam) | No  | Parameters required for the installation. For details about their default values, see [InstallParam](#installparam).                                    |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700004 | The specified user ID is not found.                          |
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 17700015 | Failed to install the HAPs because they have different configuration information. |
| 17700016 | Failed to install the HAP because of insufficient system disk space. |
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |
| 17700018 | Failed to install because the dependent module does not exist. |
| 17700039 | Failed to install because disallow install a shared bundle by hapFilePaths. |
| 17700041 | Failed to install because enterprise device management disallow install. |
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 17700048 | Failed to install the HAP because the code signature verification is failed. |
| 17700049 | Failed to install the HAP because the bundleName is different from the bundleName of the caller application. |
| 17700050 | Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device. |
| 17700051 | Failed to install the HAP because the distribution type of caller application is not enterprise_mdm. |

**Example**

```ts
import installer from '@ohos.bundle.installer';
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

## HashParam

Defines the hash parameters for bundle installation and uninstall.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API.

| Name    | Type  | Mandatory| Description            |
| ---------- | ------ | ---------------- | ---------------- |
| moduleName | string | Yes| Module name of the bundle.|
| hashValue  | string | Yes| Hash value.          |

## InstallParam

Defines the parameters that need to be specified for bundle installation, uninstall, or recovering.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API.

| Name                       | Type                          | Mandatory                        | Description              |
| ------------------------------ | ------------------------------ | ------------------ | ------------------ |
| userId                         | number                         | No                       | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0. You can call [queryOsAccountLocalIdFromProcess](js-apis-osAccount.md#getOsAccountLocalId) to obtain the user ID of the current process.|
| installFlag                    | number                         | No                       | Installation flag. The value **0x00** means initial installation, **0x01** means overwrite installation, and **0x10** means installation-free. The default value is **0x00**.|
| isKeepData                     | boolean                        | No                      | Whether to retain the data directory during bundle uninstall. The default value is **false**.|
| hashParams        | Array<[HashParam](#hashparam)> | No| Hash parameters. By default, no value is passed.        |
| crowdtestDeadline| number                         | No                       | End date of crowdtesting. The default value is **-1**, indicating that no end date is specified for crowdtesting.|
| sharedBundleDirPaths<sup>10+</sup> | Array\<String> | No|Paths of the shared bundle files. By default, no value is passed.|
| specifiedDistributionType<sup>10+</sup> | string | No|Distribution type specified during application installation. By default, no value is passed. The maximum length is 128 bytes. This field is usually specified by the application market of the operating system operator.|
| additionalInfo<sup>10+</sup> | string | No|Additional information during application installation (usually an enterprise application). By default, no value is passed. The maximum length is 3,000 bytes. This field is usually specified by the application market of the operating system operator.|
| verifyCodeParams<sup>deprecated<sup> | Array<[VerifyCodeParam](#verifycodeparamdeprecated)> | No| Information about the code signature file. The default value is null.        |
| pgoParams<sup>11+</sup> | Array<[PGOParam](#pgoparam11)> | No| Parameters of the Profile-guided Optimization (PGO) configuration file. The default value is null.        |

## UninstallParam<sup>10+</sup>

Defines the parameters required for the uninstall of a shared bundle.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API.

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | Yes  | Name of the shared bundle.                                                |
| versionCode | number | No  | Version number of the shared bundle. By default, no value is passed, and all shared bundles of the specified name are uninstalled.|

## VerifyCodeParam<sup>deprecated<sup>

> Since API version 11, the code signature file of an application is integrated into the installation package, rather than being specified by using this field.

Defines the information about the code signature file.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API.

| Name    | Type  | Mandatory| Description            |
| ---------- | ------ | ---------------- | ---------------- |
| moduleName | string | Yes| Module name of the bundle.|
| signatureFilePath  | string | Yes| Path of the code signature file.          |

## PGOParam<sup>11+</sup>

Defines the parameters of the PGO configuration file.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API.

| Name    | Type  | Mandatory| Description            |
| ---------- | ------ | ---------------- | ---------------- |
| moduleName | string | Yes| Module name of the bundle.|
| pgoFilePath  | string | Yes| Path of the PGO configuration file.          |
