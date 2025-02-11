# @ohos.bundle.installer (installer模块)(系统接口)

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

在设备上安装、升级和卸载应用。

## 导入模块

```js
import installer from '@ohos.bundle.installer';
```

## 权限列表

| 权限                           | 权限等级    | 描述             |
| ------------------------------ | ----------- | ---------------- |
| ohos.permission.INSTALL_BUNDLE | system_core | 允许应用安装、卸载其他应用（除了企业相关应用，目前有企业InHouse应用，企业MDM应用和企业normal应用）。 |
| ohos.permission.INSTALL_ENTERPRISE_BUNDLE | system_core | 允许应用安装企业InHouse应用。 |
| ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE | system_core | 允许在企业设备上安装企业MDM应用包。 |
| ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE | system_core | 允许在企业设备上安装企业NORMAL应用包。 |
| ohos.permission.UNINSTALL_BUNDLE | system_core | 允许应用卸载应用。 |
| ohos.permission.RECOVER_BUNDLE | system_core | 允许应用恢复预置应用。 |
| ohos.permission.INSTALL_SELF_BUNDLE | system_core | 允许企业MDM应用在企业设备上自升级。|
| ohos.permission.INSTALL_INTERNALTESTING_BUNDLE | system_core | 允许应用安装开发者内测构建应用。|

权限等级参考[权限APL等级说明](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)。

## BundleInstaller.getBundleInstaller

getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void

获取BundleInstaller对象，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<BundleInstaller> | 是   | 回调函数，获取BundleInstaller对象，err为null，data为获取到的BundleInstaller对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types.   |

**示例：**

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

getBundleInstaller(): Promise\<BundleInstaller>

获取BundleInstaller对象，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**返回值：**
| 类型                                                         | 说明                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise\<BundleInstaller> | Promise对象，返回BundleInstaller对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

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

getBundleInstallerSync(): BundleInstaller

获取并返回BundleInstaller对象。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**返回值：**
| 类型                                                         | 说明                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| BundleInstaller | 返回BundleInstaller对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

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
install(hapFilePaths: Array&lt;string&gt;, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void

安装应用，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup> 或 ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE<sup>10+</sup> 或 ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE<sup>10+</sup>
> **说明：** 从API version 10起，可通过ohos.permission.INSTALL_ENTERPRISE_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE权限调用此接口。
>
> 安装企业应用需要ohos.permission.INSTALL_ENTERPRISE_BUNDLE权限。
>
> 安装企业NORMAL应用需要ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE或ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE权限。
>
> 安装企业MDM应用需要ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE权限。
>
> 安装普通应用需要ohos.permission.INSTALL_BUNDLE权限。
>
> 安装开发者内测构建应用需要ohos.permission.INSTALL_INTERNALTESTING_BUNDLE权限。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。 |
| installParam           | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                                     |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，安装应用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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
| 17700066 | Failed to install the HAP because installing the native package failed. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**示例：**

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
install(hapFilePaths: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

安装应用，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup> 或 ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE<sup>10+</sup> 或 ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE<sup>10+</sup>
> **说明：** 从API version 10起，可通过ohos.permission.INSTALL_ENTERPRISE_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE权限调用此接口。
>
> 安装企业应用需要ohos.permission.INSTALL_ENTERPRISE_BUNDLE权限。
>
> 安装企业NORMAL应用需要ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE或ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE权限。
>
> 安装企业MDM应用需要ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE权限。
>
> 安装普通应用需要ohos.permission.INSTALL_BUNDLE权限。
>
> 安装开发者内测构建应用需要ohos.permission.INSTALL_INTERNALTESTING_BUNDLE权限。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，安装应用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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
| 17700066 | Failed to install the HAP because installing the native package failed. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**示例：**

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

install(hapFilePaths: Array\<string\>, installParam?: InstallParam) : Promise\<void\>

安装应用，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup> 或 ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE<sup>10+</sup> 或 ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE<sup>10+</sup>
> **说明：** 从API version 10起，可通过ohos.permission.INSTALL_ENTERPRISE_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE权限调用此接口。
>
> 安装企业应用需要ohos.permission.INSTALL_ENTERPRISE_BUNDLE权限。
>
> 安装企业NORMAL应用需要ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE或ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE权限。
>
> 安装企业MDM应用需要ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE权限。
>
> 安装普通应用需要ohos.permission.INSTALL_BUNDLE权限。
>
> 安装开发者内测构建应用需要ohos.permission.INSTALL_INTERNALTESTING_BUNDLE权限。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array\<string\>               | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。 |
| installParam | [InstallParam](#installparam) | 否   | 指定安装所需的其他参数，默认值：参照[InstallParam](#installparam)的默认值。                                     |

**返回值：**

| 类型            | 说明                                   |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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
| 17700066 | Failed to install the HAP because installing the native package failed. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**示例：**

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

uninstall(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void

卸载应用，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.UNINSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型                                                 | 必填 | 说明                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 待卸载应用的包名。                                           |
| installParam      | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                       |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，卸载应用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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

**示例：**

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

uninstall(bundleName: string, callback: AsyncCallback&lt;void&gt;): void

卸载应用，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.UNINSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型                                                 | 必填 | 说明                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 待卸载应用的包名。                                           |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，卸载应用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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

**示例：**

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

uninstall(bundleName: string, installParam?: InstallParam) : Promise\<void\>

卸载应用，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.UNINSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                          | 是   | 待卸载应用的包名。                                           |
| installParam | [InstallParam](#installparam) | 否   | 指定安装所需的其他参数，默认值：参照[InstallParam](#installparam)的默认值。                                     |

**返回值：**

| 类型            | 说明                                   |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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

**示例：**

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

recover(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void

回滚应用到初次安装时的状态，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.RECOVER_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型                                                 | 必填 | 说明                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 待恢复应用的包名。                                           |
| installParam      | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                       |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，回滚应用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.RECOVER_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700058 | Failed to install the HAP because this application is prohibited from being installed on this device or by specified users. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**示例：**

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

recover(bundleName: string, callback: AsyncCallback&lt;void&gt;): void

回滚应用到初次安装时的状态，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.RECOVER_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型                                                 | 必填 | 说明                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 待恢复应用的包名。                               |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，回滚应用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.RECOVER_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700058 | Failed to install the HAP because this application is prohibited from being installed on this device or by specified users. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**示例：**

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

recover(bundleName: string, installParam?: InstallParam) : Promise\<void\>

回滚应用到初次安装时的状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.RECOVER_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                          | 是   | 待卸载应用的包名。                                           |
| installParam | [InstallParam](#installparam) | 否   | 指定安装所需的其他参数，默认值：参照[InstallParam](#installparam)的默认值。                                     |

**返回值：**

| 类型            | 说明                                   |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.RECOVER_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700058 | Failed to install the HAP because this application is prohibited from being installed on this device or by specified users. |
| 17700073 | Failed to install the HAP because an application with the same bundle name but different signature information exists on the device. |

**示例：**
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

uninstall(uninstallParam: UninstallParam, callback : AsyncCallback\<void\>) : void

卸载一个共享包，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.UNINSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名         | 类型                                | 必填 | 说明                                                     |
| -------------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| uninstallParam | [UninstallParam](#uninstallparam10) | 是   | 共享包卸载需指定的参数信息。                             |
| callback       | AsyncCallback&lt;void&gt;           | 是   | 回调函数，卸载应用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.UNINSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700037 | The version of the shared bundle is dependent on other applications. |
| 17700038 | The specified shared bundle does not exist.                  |

**示例：**

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

uninstall(uninstallParam: UninstallParam) : Promise\<void>

卸载一个共享包，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.UNINSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名         | 类型                                | 必填 | 说明                         |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| uninstallParam | [UninstallParam](#uninstallparam10) | 是   | 共享包卸载需指定的参数信息。 |

**返回值：**

| 类型          | 说明                                   |
| ------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE' or 'ohos.permission.UNINSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700037 | The version of the shared bundle is dependent on other applications. |
| 17700038 | The specified shared bundle does not exist.                  |

**示例：**

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

## BundleInstaller.addExtResource<sup>12+</sup>

addExtResource(bundleName: string, filePaths: Array\<string>): Promise\<void>;

根据给定的bundleName和hsp文件路径添加扩展资源，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名         | 类型                                | 必填 | 说明                         |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| bundleName | string | 是   | 要添加扩展资源的应用名称。 |
| filePaths | Array\<string> | 是   | 要添加扩展资源的资源路径。 |

**返回值：**

| 类型          | 说明                                   |
| ------------- | -------------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700301 | Failed to add extended resources.                 |

**示例：**

```ts
import installer from '@ohos.bundle.installer';
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

根据给定的bundleName和moduleNames删除扩展资源，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名         | 类型                                | 必填 | 说明                         |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| bundleName | string | 是   | 要删除扩展资源的应用名称。 |
| moduleNames | Array\<string> | 是   | 要删除扩展资源的moduleNames。 |

**返回值：**

| 类型          | 说明                                   |
| ------------- | -------------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700302 | Failed to remove extended resources.                  |

**示例：**

```ts
import installer from '@ohos.bundle.installer';
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

更新当前应用，仅限企业设备上的企业MDM应用调用，且传入的hapFilePaths中的hap必须都属于当前应用，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_SELF_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。 |
| installParam           | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                                     |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，安装应用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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

**示例：**

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

updateBundleForSelf(hapFilePaths: Array\<string\>, callback: AsyncCallback\<void\>): void

更新当前应用，仅限企业设备上的企业MDM应用调用，且传入的hapFilePaths中的hap必须都属于当前应用，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_SELF_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，安装应用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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

**示例：**

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

updateBundleForSelf(hapFilePaths: Array\<string\>, installParam?: InstallParam): Promise\<void\>

更新当前应用，仅限企业设备上的企业MDM应用调用，且传入的hapFilePaths中的hap必须都属于当前应用，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_SELF_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。 |
| installParam | [InstallParam](#installparam) | 否   | 指定安装所需的其他参数，默认值：参照[InstallParam](#installparam)的默认值。                                     |

**返回值：**

| 类型          | 说明                                   |
| ------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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

**示例：**

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

## BundleInstaller.uninstallUpdates<sup>12+</sup>

uninstallUpdates(bundleName: string, installParam?: InstallParam): Promise\<void\>;

对预置应用进行卸载更新，恢复到初次安装时的状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.RECOVER_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | 是   | 待卸载更新应用的包名。                                                  |
| installParam | [InstallParam](#installparam) | 否   | 指定卸载更新所需的其他参数，默认值：参照[InstallParam](#installparam)的默认值。其中userId无法指定，调用本接口将对所有已安装相应应用的用户进行卸载更新操作。 |

**返回值：**

| 类型            | 说明                                   |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
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

**示例：**

```ts
import installer from '@ohos.bundle.installer';
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

创建应用分身，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_CLONE_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                                                          |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | 是   | 待创建应用分身的包名。                                         |
| createAppCloneParam  | [createAppCloneParam](#createappcloneparam12)   | 否   | 指定创建应用分身所需的其他参数，默认值：参照[createAppCloneParam](#createappcloneparam12)的默认值。   |

**返回值：**

| 类型            | 说明                                   |
| --------------- | -------------------------------------- |
| Promise\<number\> | Promise对象。返回创建的分身应用索引值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_CLONE_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName cannot be found or the bundle is not installed by the specified user. |
| 17700004 | The userId is invalid. |
| 17700061 | The appIndex is not in valid range or already exists. |
| 17700069 | The app does not support the creation of an appClone instance. |

**示例：**
```ts
import installer from '@ohos.bundle.installer';
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

删除应用分身，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.UNINSTALL_CLONE_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                                                          |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | 是   | 待删除应用分身的包名。                                         |
| appIndex     | number                        | 是   | 待删除应用分身的索引。                                         |
| userId       | number                        | 否   | 待删除应用分身所属用户id。默认值：调用方所在用户。                |

**返回值：**

| 类型            | 说明                                   |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.UNINSTALL_CLONE_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName cannot be found or the bundle is not installed by the specified user. |
| 17700004 | The userId is invalid. |
| 17700061 | The appIndex is invalid. |

**示例：**
```ts
import installer from '@ohos.bundle.installer';
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

删除应用分身，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.UNINSTALL_CLONE_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                                                          |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | 是   | 待删除应用分身的包名。                                         |
| appIndex     | number                        | 是   | 待删除应用分身的索引。                                         |
| destroyAppCloneParam       | [DestroyAppCloneParam](#destroyappcloneparam15)   | 否   | 指定删除应用分身所需的其他参数，默认值：参照[DestroyAppCloneParam](#destroyappcloneparam15)的默认值。   |

**返回值：**

| 类型            | 说明                                   |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.UNINSTALL_CLONE_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 17700001 | The specified bundleName cannot be found or the bundle is not installed by the specified user. |
| 17700004 | The userId is invalid. |
| 17700061 | The appIndex is invalid. |
| 17700062 | Failed to uninstall the app because the app is locked. |

**示例：**
```ts
import installer from '@ohos.bundle.installer';
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

安装应用，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                                                          |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| bundleName   | string                        | 是   | 需要安装应用的包名。                                           |
| userId       | number                        | 否   | 需要安装应用的用户id，userId需要大于0。默认值：调用方所在用户。   |

**返回值：**

| 类型            | 说明                                   |
| --------------- | -------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.INSTALL_BUNDLE'. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName cannot be found. |
| 17700004 | The userId is invalid. |
| 17700071 | It is not allowed to install the enterprise bundle. |
| 17700058 | Failed to install the HAP because this application is prohibited from being installed on this device or by specified users. |

**示例：**
```ts
import installer from '@ohos.bundle.installer';
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

## HashParam

应用程序安装卸载哈希参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称     | 类型   | 必填 | 说明             |
| ---------- | ------ | ---------------- | ---------------- |
| moduleName | string | 是 | 应用程序模块名称。 |
| hashValue  | string | 是 | 哈希值。           |

## InstallParam

应用程序安装、卸载或恢复需指定的参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称                        | 类型                           | 必填                         | 说明               |
| ------------------------------ | ------------------------------ | ------------------ | ------------------ |
| userId                         | number                         | 否                        | 指示用户id，默认值：调用方所在用户，取值范围：大于等于0，可使用[queryOsAccountLocalIdFromProcess](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取当前进程所在用户。当安装、卸载或恢复一个驱动应用时，该参数会被忽略，会在所有用户下执行。 |
| installFlag                    | number                         | 否                        | 指示安装标志，枚举值：0x00：应用初次安装，0x01：应用覆盖安装，0x10：应用免安装，默认值为应用初次安装。 |
| isKeepData                     | boolean                        | 否                       | 卸载时是否保留数据目录，默认值为false。 |
| hashParams        | Array<[HashParam](#hashparam)> | 否 | 哈希值参数，默认值为空。         |
| crowdtestDeadline| number                         | 否                        | 众测活动的截止日期，默认值为-1，表示无截止日期约束。 |
| sharedBundleDirPaths<sup>10+</sup> | Array\<String> | 否 |共享包文件所在路径，默认值为空。 |
| specifiedDistributionType<sup>10+</sup> | string | 否 |应用安装时指定的分发类型，默认值为空，最大长度为128字节。该字段通常由操作系统运营方的应用市场指定。 |
| additionalInfo<sup>10+</sup> | string | 否 |应用安装时的额外信息，默认值为空，最大长度为3000字节。该字段通常由操作系统运营方的应用市场在安装企业应用时指定，用于保存应用的额外信息。 |
| verifyCodeParams<sup>deprecated<sup> | Array<[VerifyCodeParam](#verifycodeparamdeprecated)> | 否 | 代码签名文件参数，默认值为空。         |
| pgoParams<sup>11+</sup> | Array<[PGOParam](#pgoparam11)> | 否 | PGO配置文件参数，默认值为空。         |
| parameters<sup>15+</sup> | Array<[Parameters](#parameters15)> | 否 | 扩展参数，默认值为空。         |

## UninstallParam<sup>10+</sup>

共享包卸载需指定的参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称        | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | 是   | 共享包包名。                                                 |
| versionCode | number | 否   | 指示共享包的版本号。默认值：如果不填写versionCode，则卸载该包名的所有共享包。 |

## VerifyCodeParam<sup>deprecated<sup>

> 从API version 11开始不再维护，应用的代码签名文件将集成到安装包中，不再需要该接口来指定安装包的代码签名文件。

应用程序代码签名文件信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称     | 类型   | 必填 | 说明             |
| ---------- | ------ | ---------------- | ---------------- |
| moduleName | string | 是 | 应用程序模块名称。 |
| signatureFilePath  | string | 是 | 代码签名文件路径。           |

## PGOParam<sup>11+</sup>

PGO（Profile-guided Optimization）配置文件参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称     | 类型   | 必填 | 说明             |
| ---------- | ------ | ---------------- | ---------------- |
| moduleName | string | 是 | 应用程序模块名称。 |
| pgoFilePath  | string | 是 | PGO配置文件路径。           |

## Parameters<sup>15+</sup>

扩展参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称     | 类型   | 必填 | 说明             |
| ---------- | ------ | ---------------- | ---------------- |
| key | string | 是 | 扩展参数键。 |
| value  | string | 是 | 扩展参数值。  |

## CreateAppCloneParam<sup>12+</sup>

创建分身应用可指定的参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称        | 类型   | 必填 | 说明                                                          |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| userId      | number | 否   | 指定创建分身应用所在的用户id。默认值：调用方所在用户。            |
| appIndex    | number | 否   | 指定创建分身应用的索引值。默认值：当前可用的最小索引值。           |

## DestroyAppCloneParam<sup>15+</sup>

删除分身应用可指定的参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称        | 类型   | 必填 | 说明                                                          |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| userId      | number | 否   | 指定删除分身应用所在的用户id。默认值：调用方所在用户。            |
| parameters  | Array<[Parameters](#parameters15)> | 否   | 指定删除分身应用扩展参数，默认值为空。            |
