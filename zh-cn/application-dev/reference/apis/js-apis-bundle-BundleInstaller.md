# BundleInstaller

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

在设备上安装、升级和卸载应用

## BundleInstaller.install<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[install](js-apis-installer.md)替代。

install(bundleFilePaths: Array&lt;string&gt;, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

以异步方法在应用中安装hap，支持多hap安装。使用callback形式返回结果。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：** 此接口为系统接口，三方应用不支持调用

**参数：**

| 名称            | 类型                                                 | 必填 | 描述                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFilePaths | Array&lt;string&gt;                                  | 是   | 指示存储hap包的沙箱路径。沙箱路径的获取方法参见[获取应用的沙箱路径](#获取应用的沙箱路径)|
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

## BundleInstaller.uninstall<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[uninstall](js-apis-installer.md)替代。

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
## BundleInstaller.recover<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[recover](js-apis-installer.md)替代。

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

## InstallParam<sup>(deprecated)<sup>

应用程序安装卸载信息

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

 **系统API：**  此接口为系统接口，三方应用不支持调用

| 名称                           | 类型                           |可读|可写| 说明               |
| ------------------------------ | ------------------------------ | ---- |----|--------------- |
| userId                         | number                         | 是|是 |指示用户id，可以通过[账户子系统](js-apis-)         |
| installFlag                    | number                         | 是|是 |指示安装标志 <br> 0表示正常安装 <br>1表示替代原有应用       |
| isKeepData                     | boolean                        | 是|是 |指示应用删除后是否保留数据 |


## InstallStatus<sup>(deprecated)<sup>

应用程序安装卸载状态

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

 **系统API：**  此接口为系统接口，三方应用不支持调用

| 名称          | 类型                                                         | 可读 | 可写 | 说明                           |
| ------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------ |
| status        | bundle.[InstallErrorCode](js-apis-Bundle.md#installerrorcode) | 是   | 否   | 表示安装或卸载错误状态码       |
| statusMessage | string                                                       | 是   | 否   | 表示安装或卸载的字符串结果信息 |

## 获取应用的沙箱路径
对于FA模型，应用的沙箱路径可以通过[Context](js-apis-Context.md)中的方法获取；对于Stage模型，应用的沙箱路径可以通过[Context](js-apis-ability-context.md#abilitycontext)中的属性获取。

**示例：**
``` ts
// Stage模型
import Ability from '@ohos.application.Ability';
class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let context = this.context;
        let pathDir = context.filesDir;
    }
}

// FA模型
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();
context.getFilesDir().then((data) => {
    let pathDir = data;
});
```