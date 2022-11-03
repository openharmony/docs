# BundleInstaller



> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



本模块提供在设备上安装、升级和删除应用的能力。

## BundleInstaller.install

install(bundleFilePaths: Array&lt;string&gt;, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

以异步方法为应用安装hap，支持多hap安装。使用callback形式返回结果。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：** 此接口为系统接口，三方应用不支持调用

**参数：**

| 名称            | 类型                                                 | 必填 | 描述                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFilePaths | Array&lt;string&gt;                                  | 是   | 指示存储hap包的沙箱路径，应用的沙箱路径可以通过[Context](js-apis-Context.md#contextgetfilesdir)获取|
| param           | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                                     |
| callback        | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | 是   | 程序启动作为入参的回调函数，返回安装状态信息。               |

**示例：**

```ts
import bundle from '@ohos.bundle';
let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];
let installParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

bundle.getBundleInstaller().then(installer=>{
    installer.install(hapFilePaths, installParam, err => {
        if (err) {
            console.error('install failed:' + JSON.stringify(err));
        } else {
            console.info('install successfully.');
        }
    });
}).catch(error => {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
});
```

## BundleInstaller.uninstall

uninstall(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

以异步方法卸载应用程序，使用callback形式返回结果。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：** 此接口为系统接口，三方应用不支持调用

**参数：**

| 名称       | 类型                                                 | 必填 | 描述                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 包名                                           |
| param      | [InstallParam](#installparam)                        | 是   | 指定卸载所需的其他参数。                       |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | 是   | 程序启动作为入参的回调函数，返回安装状态信息。 |

**示例：**

```ts
import bundle from '@ohos.bundle';
let bundleName = 'com.ohos.demo';
let installParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

bundle.getBundleInstaller().then(installer=>{
    installer.uninstall(bundleName, installParam, err => {
        if (err) {
            console.error('uninstall failed:' + JSON.stringify(err));
        } else {
            console.info('uninstall successfully.');
        }
    });
}).catch(error => {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
});
```
## BundleInstaller.recover<sup>8+</sup>

recover(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

以异步方法恢复一个应用程序，使用callback形式返回结果。当预置应用被卸载后，可以通过此接口进行恢复。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：** 此接口为系统接口，三方应用不支持调用

**参数：**

| 名称       | 类型                                                 | 必填 | 描述                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 包名                                           |
| param      | [InstallParam](#installparam)                        | 是   | 指定应用恢复所需的其他参数。                       |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | 是   | 程序启动作为入参的回调函数，返回应用恢复状态信息。 |

**示例：**

```ts
import bundle from '@ohos.bundle';

let bundleName = 'com.ohos.demo';
let installParam = {
    userId: 100,
    isKeepData: false,
    installFlag: 1,
};

bundle.getBundleInstaller().then(installer=>{
    installer.recover(bundleName, installParam, err => {
        if (err) {
            console.error('recover failed:' + JSON.stringify(err));
        } else {
            console.info('recover successfully.');
        }
    });
}).catch(error => {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
});
```

## HashParam<sup>9+</sup>

hap的哈希值参数。应用市场升级检测时，校验各版本哈希值是否一致。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

 **系统API：**  此接口为系统接口，三方应用不支持调用

| 名称       | 类型   | 可读|可写|说明             |
| ---------- | ------ | ---|---|---------------- |
| moduleName | string | 是|是 | 应用程序模块名称 |
| hashValue  | string | 是|是 |hap包的sha256哈希值           |

## InstallParam

应用程序安装卸载信息

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

 **系统API：**  此接口为系统接口，三方应用不支持调用

| 名称                           | 类型                           |可读|可写| 说明               |
| ------------------------------ | ------------------------------ | ---- |----|--------------- |
| userId                         | number                         | 是|是 |指示用户id         |
| installFlag                    | number                         | 是|是 |指示安装标志       |
| isKeepData                     | boolean                        | 是|是 |指示应用删除后是否保留数据 |
| hashParams<sup>9+</sup>        | Array<[HashParam](#hashparam)> | 是|是 |哈希值参数         |
| crowdtestDeadline<sup>9+</sup> | number                         | 是|是 |[众测](https://deveco.huawei.com/crowdtest)截止时间 |

## InstallStatus

应用程序安装卸载状态

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

 **系统API：**  此接口为系统接口，三方应用不支持调用

| 名称          | 类型                                                         | 可读 | 可写 | 说明                           |
| ------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------ |
| status        | bundle.[InstallErrorCode](js-apis-Bundle.md#installerrorcode) | 是   | 否   | 表示安装或卸载错误状态码       |
| statusMessage | string                                                       | 是   | 否   | 表示安装或卸载的字符串结果信息 |
