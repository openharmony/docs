# BundleInstaller

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

在设备上安装、升级和卸载应用

## 导入模块

```js
import installer from '@ohos.bundle.installer';
```

## 权限列表

| 权限                                       | 权限等级     | 描述               |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.INSTALL_BUNDLE             | system_core  | 可安装、卸载应用   |

权限等级参考[权限等级说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/accesstoken-overview.md#%E6%9D%83%E9%99%90%E7%AD%89%E7%BA%A7%E8%AF%B4%E6%98%8E)

## BundleInstaller.getBundleInstaller

getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void;

获取BundleInstaller对象，使用callback形式返回结果。

**系统接口：** 此接口为系统接口，三方应用不支持调用

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 名称     | 类型                                                         | 必填 | 描述                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[BundleInstaller](js-apis-installer.md#BundleInstaller)> | 是   | 回调函数，获取BundleInstaller对象，err为undefined，data为获取到的BundleInstaller对象；否则为错误对象 |

**错误码：**

错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

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
| Promise\<[BundleInstaller](js-apis-installer.md#BundleInstaller)> | Promise对象，返回BundleInstaller对象 |

**错误码：**

错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

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

| 名称            | 类型                                                 | 必填 | 描述                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePaths | Array&lt;string&gt;                                  | 是   | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP包的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP包，且这些HAP包的签名需要保持一致 |
| installParam           | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数                                     |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，安装应用成功，err为undefined，否则为错误对象 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误码信息                                                      |
| -------- | ---------------------------------------------------------------|
| 17700004 | The specified userId is not existed                            |
| 17700010 | To parse file of config.json or module.json failed             |
| 17700011 | To verify signature failed                                     |
| 17700012 | Invalid hap file path or too large file size                   |
| 17700015 | Multiple haps have inconsistent configured information         |
| 17700016 | No disk space left for installation                            |
| 17700017 | Downgrade installation is prohibited                           |
| 17700101 | The system service is excepted                                 |
| 17700103 | I/O operation is failed                                        |

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

| 名称       | 类型                                                 | 必填 | 描述                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 包名                                           |
| installParam      | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数                       |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，卸载应用成功，err为undefined，否则为错误对象 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误码信息                                                                  |
| -------- | ---------------------------------------------------------------------------|
| 17700004 | The specified userId is not existed                                        |
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled   |
| 17700101 | The system service is excepted                                             |

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

| 名称       | 类型                                                 | 必填 | 描述                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 包名                                           |
| installParam      | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数                       |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，回滚应用成功，err为undefined，否则为错误对象 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误码信息                                                                 |
| -------- | ---------------------------------------------------------------------------|
| 17700004 | The specified userId is not existed                                        |

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

应用程序安装卸载信息

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口，三方应用不支持调用

| 名称       | 类型   | 说明             |
| ---------- | ------ | ---------------- |
| moduleName | string | 应用程序模块名称 |
| hashValue  | string | 哈希值           |

## InstallParam

应用程序安装卸载信息

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口，三方应用不支持调用

| 名称                           | 类型                           | 说明               |
| ------------------------------ | ------------------------------ | ------------------ |
| userId                         | number                         | 指示用户id，可使用[queryOsAccountLocalIdFromProcess](js-apis-osAccount.md#queryosaccountlocalidfromprocess9)获取当前进程所在用户 |
| installFlag                    | number                         | 指示安装标志，枚举值：0：应用初次安装，1：应用覆盖安装 |
| isKeepData                     | boolean                        | 卸载时是否保留数据目录 |
| hashParams        | Array<[HashParam](#hashparam)> | 哈希值参数         |
| crowdtestDeadline| number                         | 测试包的被杀死时间 |