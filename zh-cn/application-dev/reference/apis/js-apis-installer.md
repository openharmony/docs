# @ohos.bundle.installer (installer模块)

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

在设备上安装、升级和卸载应用

## 导入模块

```js
import installer from '@ohos.bundle.installer';
```

## 权限列表

| 权限                           | 权限等级    | 描述             |
| ------------------------------ | ----------- | ---------------- |
| ohos.permission.INSTALL_BUNDLE | system_core | 可安装、卸载应用。 |

权限等级参考[权限等级说明](../../security/accesstoken-overview.md#权限等级说明)

## BundleInstaller.getBundleInstaller

getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void;

获取BundleInstaller对象，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[BundleInstaller](js-apis-installer.md#BundleInstaller)> | 是   | 回调函数，获取BundleInstaller对象，err为undefined，data为获取到的BundleInstaller对象；否则为错误对象。 |

**示例：**

```ts
import installer from '@ohos.bundle.installer';

try {
    installer.getBundleInstaller((err, data) => {
        if (err) {
            console.error('getBundleInstaller failed:' + err.message);
        } else {
            console.info('getBundleInstaller successfully');
        }
    });
} catch (error) {
    console.error('getBundleInstaller failed:' + error.message);
}
```

## BundleInstaller.getBundleInstaller

getBundleInstaller(): Promise\<BundleInstaller>;

获取BundleInstaller对象，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**返回值：**
| 类型                                                         | 说明                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise\<[BundleInstaller](js-apis-installer.md#BundleInstaller)> | Promise对象，返回BundleInstaller对象。 |

**示例：**

```ts
import installer from '@ohos.bundle.installer';

try {
    installer.getBundleInstaller().then((data) => {
        console.info('getBundleInstaller successfully.');
    }).catch((error) => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## BundleInstaller.install
install(hapFilePaths: Array&lt;string&gt;, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void;

以异步方法安装应用，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup>
> **说明：** 从API version 10起，可通过ohos.permission.INSTALL_ENTERPRISE_BUNDLE权限调用此接口。
>
> 安装企业应用需要ohos.permission.INSTALL_ENTERPRISE_BUNDLE权限
>
> 安装普通应用需要ohos.permission.INSTALL_BUNDLE权限

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。 |
| installParam           | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                                     |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，安装应用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];
let installParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then(data => {
        data.install(hapFilePaths, installParam, err => {
            if (err) {
                console.error('install failed:' + err.message);
            } else {
                console.info('install successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```
## BundleInstaller.install
install(hapFilePaths: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void;

以异步方法安装应用，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup>
> **说明：** 从API version 10起，可通过ohos.permission.INSTALL_ENTERPRISE_BUNDLE权限调用此接口。
>
> 安装企业应用需要ohos.permission.INSTALL_ENTERPRISE_BUNDLE权限
>
> 安装普通应用需要ohos.permission.INSTALL_BUNDLE权限

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，安装应用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];

try {
    installer.getBundleInstaller().then(data => {
        data.install(hapFilePaths, err => {
            if (err) {
                console.error('install failed:' + err.message);
            } else {
                console.info('install successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## BundleInstaller.install

install(hapFilePaths: Array\<string\>, installParam?: InstallParam) : Promise\<void\>;

以异步方法安装应用，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE 或 ohos.permission.INSTALL_ENTERPRISE_BUNDLE<sup>10+</sup>
> **说明：** 从API version 10起，可通过ohos.permission.INSTALL_ENTERPRISE_BUNDLE权限调用此接口。
>
> 安装企业应用需要ohos.permission.INSTALL_ENTERPRISE_BUNDLE权限
>
> 安装普通应用需要ohos.permission.INSTALL_BUNDLE权限

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

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
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

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];
let installParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then(data => {
        data.install(hapFilePaths, installParam)
            .then((data) => {
                console.info('install successfully: ' + JSON.stringify(data));
        }).catch((error) => {
            console.error('install failed:' + error.message);
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## BundleInstaller.uninstall

uninstall(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void;

以异步方法卸载应用，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型                                                 | 必填 | 说明                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 待卸载应用的包名。                                           |
| installParam      | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                       |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，卸载应用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |
| 17700045 | Failed to uninstall because enterprise device management disallow uninstall. |

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let bundleName = 'com.ohos.demo';
let installParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1
};

try {
    installer.getBundleInstaller().then(data => {
        data.uninstall(bundleName, installParam, err => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## BundleInstaller.uninstall

uninstall(bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

以异步方法卸载应用，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型                                                 | 必填 | 说明                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 待卸载应用的包名。                                           |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，卸载应用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700001 | The specified bundle name is not found. |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |
| 17700045 | Failed to uninstall because enterprise device management disallow uninstall. |

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let bundleName = 'com.ohos.demo';

try {
    installer.getBundleInstaller().then(data => {
        data.uninstall(bundleName, err => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```
## BundleInstaller.uninstall

uninstall(bundleName: string, installParam?: InstallParam) : Promise\<void\>;

以异步方法卸载应用，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

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

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |
| 17700045 | Failed to uninstall because enterprise device management disallow uninstall. |

**示例：**
```ts
import installer from '@ohos.bundle.installer';
let bundleName = 'com.ohos.demo';
let installParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then(data => {
        data.uninstall(bundleName, installParam)
            .then((data) => {
                console.info('uninstall successfully: ' + JSON.stringify(data));
        }).catch((error) => {
            console.error('uninstall failed:' + error.message);
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## BundleInstaller.recover

recover(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void;

以异步方法回滚应用到初次安装时的状态，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型                                                 | 必填 | 说明                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 待恢复应用的包名。                                           |
| installParam      | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                       |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，回滚应用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let bundleName = 'com.ohos.demo';
let installParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1
};

try {
    installer.getBundleInstaller().then(data => {
        data.recover(bundleName, installParam, err => {
            if (err) {
                console.error('recover failed:' + err.message);
            } else {
                console.info('recover successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```


## BundleInstaller.recover

recover(bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

以异步方法回滚应用到初次安装时的状态，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型                                                 | 必填 | 说明                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 待恢复应用的包名。                               |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，回滚应用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 17700001 | The specified bundle name is not found. |

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let bundleName = 'com.ohos.demo';

try {
    installer.getBundleInstaller().then(data => {
        data.recover(bundleName, err => {
            if (err) {
                console.error('recover failed:' + err.message);
            } else {
                console.info('recover successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## BundleInstaller.recover

recover(bundleName: string, installParam?: InstallParam) : Promise\<void\>;

以异步方法回滚应用到初次安装时的状态，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

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

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 17700001 | The specified bundle name is not found. |
| 17700004 | The specified user ID is not found. |

**示例：**
```ts
import installer from '@ohos.bundle.installer';
let bundleName = 'com.ohos.demo';
let installParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

try {
    installer.getBundleInstaller().then(data => {
        data.recover(bundleName, installParam)
            .then((data) => {
                console.info('recover successfully: ' + JSON.stringify(data));
        }).catch((error) => {
            console.error('recover failed:' + error.message);
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## BundleInstaller.uninstall<sup>10+</sup>

uninstall(uninstallParam: UninstallParam, callback : AsyncCallback\<void>) : void ;

以异步方法卸载一个共享包，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名         | 类型                                | 必填 | 说明                                                     |
| -------------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| uninstallParam | [UninstallParam](#uninstallparam10) | 是   | 共享包卸载需指定的参数信息。                             |
| callback       | AsyncCallback&lt;void&gt;           | 是   | 回调函数，卸载应用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700037 | The version of shared bundle is dependent on other applications. |
| 17700038 | The specified shared bundle does not exist.                  |

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let uninstallParam = {
    bundleName : "com.ohos.demo",
};

try {
    installer.getBundleInstaller().then(data => {
        data.uninstall(uninstallParam, err => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## BundleInstaller.uninstall<sup>10+</sup>

uninstall(uninstallParam: UninstallParam) : Promise\<void>;

以异步方法卸载一个共享包，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

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

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700037 | The version of shared bundle is dependent on other applications. |
| 17700038 | The specified shared bundle does not exist.                  |

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let uninstallParam = {
    bundleName : "com.ohos.demo",
};

try {
    installer.getBundleInstaller().then(data => {
        data.uninstall(uninstallParam, err => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
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
| userId                         | number                         | 否                        | 指示用户id，默认值：调用方所在用户，取值范围：大于等于0，可使用[queryOsAccountLocalIdFromProcess](js-apis-osAccount.md#getOsAccountLocalId)获取当前进程所在用户。 |
| installFlag                    | number                         | 否                        | 指示安装标志，枚举值：0x00：应用初次安装，0x01：应用覆盖安装，0x10：应用免安装，默认值为应用初次安装。 |
| isKeepData                     | boolean                        | 否                       | 卸载时是否保留数据目录，默认值为false。 |
| hashParams        | Array<[HashParam](#hashparam)> | 否 | 哈希值参数，默认值为空。         |
| crowdtestDeadline| number                         | 否                        | 众测活动的截止日期，默认值为-1，表示无截止日期约束。 |
| sharedBundleDirPaths<sup>10+</sup> | Array\<String> | 否 |共享包文件所在路径，默认值为空。 |
| specifiedDistributionType<sup>10+</sup> | string | 否 |应用安装时指定的分发类型，默认值为空，最大长度为128字节。该字段通常由操作系统运营方的应用市场指定。 |
| additionalInfo<sup>10+</sup> | string | 否 |应用安装时的额外信息，默认值为空，最大长度为3000字节。该字段通常由操作系统运营方的应用市场在安装企业应用时指定，用于保存应用的额外信息。 |
| verifyCodeParams<sup>10+</sup> | Array<[VerifyCodeParam](#verifycodeparam10)> | 否 | 代码签名文件参数，默认值为空。         |

## UninstallParam<sup>10+</sup>

共享包卸载需指定的参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称        | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | 是   | 共享包包名。                                                 |
| versionCode | number | 否   | 指示共享包的版本号。默认值：如果不填写versionCode，则卸载该包名的所有共享包。 |

## VerifyCodeParam<sup>10+</sup>

应用程序代码签名文件信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称     | 类型   | 必填 | 说明             |
| ---------- | ------ | ---------------- | ---------------- |
| moduleName | string | 是 | 应用程序模块名称。 |
| signatureFilePath  | string | 是 | 代码签名文件路径。           |