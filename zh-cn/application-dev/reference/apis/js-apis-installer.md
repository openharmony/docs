# @ohos.bundle.installer (installer模块)

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
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

**系统接口：** 此接口为系统接口，三方应用不支持调用

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

**系统接口：** 此接口为系统接口，三方应用不支持调用

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

**系统接口：** 此接口为系统接口，三方应用不支持调用

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP包的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP包，且这些HAP包的签名需要保持一致。 |
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
| 17700101 | The system service is excepted.                              |
| 17700103 | I/O operation is failed.                                     |

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

## BundleInstaller.uninstall

uninstall(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void;

以异步方法卸载应用，使用callback形式返回结果。

**系统接口：** 此接口为系统接口，三方应用不支持调用

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
| 17700004 | The specified user ID is not found.                          |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |
| 17700101 | The system service is excepted.                              |

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

## BundleInstaller.recover

recover(bundleName: string, installParam: InstallParam, callback: AsyncCallback&lt;void&gt;): void;

以异步方法回滚应用，使用callback形式返回结果。

**系统接口：** 此接口为系统接口，三方应用不支持调用

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

## HashParam

应用程序安装卸载哈希参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口，三方应用不支持调用

| 名称     | 类型   | 必填 | 说明             |
| ---------- | ------ | ---------------- | ---------------- |
| moduleName | string | 是 | 应用程序模块名称。 |
| hashValue  | string | 是 | 哈希值。           |

## InstallParam

应用程序安装、卸载或恢复需指定的参数信息。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口，三方应用不支持调用

| 名称                        | 类型                           | 必填                         | 说明               |
| ------------------------------ | ------------------------------ | ------------------ | ------------------ |
| userId                         | number                         | 是                        | 指示用户id，可使用[queryOsAccountLocalIdFromProcess](js-apis-osAccount.md#queryosaccountlocalidfromprocess9)获取当前进程所在用户。 |
| installFlag                    | number                         | 是                        | 指示安装标志，枚举值：0：应用初次安装，1：应用覆盖安装。 |
| isKeepData                     | boolean                        | 是                       | 卸载时是否保留数据目录。 |
| hashParams        | Array<[HashParam](#hashparam)> | 是 | 哈希值参数。         |
| crowdtestDeadline| number                         | 是                        |[众测](https://developer.huawei.com/consumer/cn/agconnect/crowd-test/)截止日期。 |