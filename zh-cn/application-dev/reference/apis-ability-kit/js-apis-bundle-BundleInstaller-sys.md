# BundleInstaller (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供设备上安装、升级和卸载应用的能力。

> **说明：**
>
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 从API Version 9开始，该模块不再维护，建议使用[@ohos.bundle.installer.install](js-apis-installer-sys.md)替代。
>
> 本模块为系统接口。

## BundleInstaller.install<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[@ohos.bundle.installer.install](js-apis-installer-sys.md#bundleinstallerinstall)替代。

install(bundleFilePaths: Array&lt;string&gt;, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

在应用中安装hap，支持多hap安装。使用callback异步回调。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名          | 类型                                                         | 必填 | 说明                                                         |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleFilePaths | Array&lt;string&gt;                                          | 是   | 指示存储HAP的沙箱路径。沙箱路径的获取方法参见[获取应用的沙箱路径](#获取应用的沙箱路径)。 |
| param           | [InstallParam](#installparamdeprecated)                      | 是   | 指定安装所需的其他参数。                                     |
| callback        | AsyncCallback&lt;[InstallStatus](#installstatusdeprecated)&gt; | 是   | 程序启动作为入参的回调函数，返回安装状态信息。               |

**示例：**

```ts
import bundleInstall from '@ohos.bundle.installer';
import { BusinessError } from '@ohos.base';

let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/files/'];
let installParam: bundleInstall.InstallParam = {
  userId: 100,
  isKeepData: false,
  installFlag: 1,
};

bundleInstall.getBundleInstaller().then(installer => {
  installer.install(hapFilePaths, installParam, err => {
    if (err) {
      console.error('install failed:' + JSON.stringify(err));
    } else {
      console.info('install successfully.');
    }
  });
}).catch((error: BusinessError)=> {
  let message = (error as BusinessError).message;
  console.error('getBundleInstaller failed. Cause: ' + message);
});
```

## BundleInstaller.uninstall<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[uninstall](js-apis-installer-sys.md#bundleinstalleruninstall)替代。

uninstall(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

卸载应用程序，使用callback异步回调，返回安装状态信息。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                           |
| ---------- | ------------------------------------------------------------ | ---- | ---------------------------------------------- |
| bundleName | string                                                       | 是   | 应用Bundle名称。                               |
| param      | [InstallParam](#installparamdeprecated)                      | 是   | 指定卸载所需的其他参数。                       |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatusdeprecated)&gt; | 是   | 程序启动作为入参的回调函数，返回安装状态信息。 |

**示例：**

```ts
import bundleInstall from '@ohos.bundle.installer';
import { BusinessError } from '@ohos.base';

let bundleName: string = 'com.example.myapplication';
let installParam: bundleInstall.InstallParam = {
  userId: 100,
  isKeepData: false,
  installFlag: 1,
};

bundleInstall.getBundleInstaller().then(installer => {
  installer.uninstall(bundleName, installParam, err => {
    if (err) {
      console.error('uninstall failed:' + JSON.stringify(err));
    } else {
      console.info('uninstall successfully.');
    }
  });
}).catch((error: BusinessError) => {
  let message = (error as BusinessError).message;
  console.error('getBundleInstaller failed. Cause: ' + message);
});
```
## BundleInstaller.recover<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[recover](js-apis-installer-sys.md#bundleinstallerrecover)替代。

recover(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

恢复一个应用程序，使用callback异步回调。当预置应用被卸载后，可以通过此接口进行恢复。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                               |
| ---------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| bundleName | string                                                       | 是   | 应用Bundle名称。                                   |
| param      | [InstallParam](#installparamdeprecated)                      | 是   | 指定应用恢复所需的其他参数。                       |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatusdeprecated)&gt; | 是   | 程序启动作为入参的回调函数，返回应用恢复状态信息。 |

**示例：**

```ts
import bundleInstall from '@ohos.bundle.installer';
import { BusinessError } from '@ohos.base';

let bundleName: string = 'com.example.myapplication';
let installParam: bundleInstall.InstallParam = {
  userId: 100,
  isKeepData: false,
  installFlag: 1,
};

bundleInstall.getBundleInstaller().then(installer => {
  installer.uninstall(bundleName, installParam, err => {
    if (err) {
      console.error('uninstall failed:' + JSON.stringify(err));
    } else {
      console.info('uninstall successfully.');
    }
  });
}).catch((error: BusinessError) => {
  let message = (error as BusinessError).message;
  console.error('getBundleInstaller failed. Cause: ' + message);
});
```

## InstallParam<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[InstallParam](js-apis-installer-sys.md#installparam)替代。

安装、恢复或卸载时需要指定的参数。

 **系统能力：** SystemCapability.BundleManager.BundleFramework

 **系统接口：** 此接口为系统接口。

| 名称        | 类型    | 只读 | 可选 | 说明               |
| ----------- | ------- | ---- | ---- | ------------------ |
| userId      | number  | 否  | 否  | 指示用户id, 默认值：调用方的userId。 |
| installFlag | number  | 否  | 否  | 指示安装标志, 默认值：1。 </br>取值范围：</br>1: 覆盖安装。</br>16: 免安装。|
| isKeepData  | boolean | 否  | 否  | 指示应用卸载时是否保留包数据，默认值：false，true表示保留，false表示不保留。 |

## InstallStatus<sup>(deprecated)<sup>

应用程序安装卸载的结果。

 **系统能力：** SystemCapability.BundleManager.BundleFramework

 **系统接口：**  此接口为系统接口。

| 名称          | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| status        | bundle.[InstallErrorCode](js-apis-Bundle.md#installerrorcodedeprecated) | 否   | 否   | 表示安装或卸载错误状态码。取值范围：枚举值[InstallErrorCode](js-apis-Bundle.md#installerrorcodedeprecated)。 |
| statusMessage | string                                                       | 否   | 否   | 表示安装或卸载的字符串结果信息。取值范围包括：<br/> "SUCCESS" : 安装成功。</br> "STATUS_INSTALL_FAILURE": 安装失败（不存在安装文件）。</br> "STATUS_INSTALL_FAILURE_ABORTED": 安装中止。 </br> "STATUS_INSTALL_FAILURE_INVALID": 安装参数无效。 </br> "STATUS_INSTALL_FAILURE_CONFLICT":  安装冲突（常见于升级和已有应用基本信息不一致）。 </br> "STATUS_INSTALL_FAILURE_STORAGE": 存储包信息失败。 </br> "STATUS_INSTALL_FAILURE_INCOMPATIBLE": 安装不兼容（常见于版本降级安装或者签名信息错误）。 </br> "STATUS_UNINSTALL_FAILURE": 卸载失败（不存在卸载的应用）。 </br> "STATUS_UNINSTALL_FAILURE_ABORTED": 卸载中止（没有使用）。 </br> "STATUS_UNINSTALL_FAILURE_ABORTED": 卸载冲突（卸载系统应用失败， 结束应用进程失败）。 </br> "STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT": 安装失败（下载超时）。</br> "STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED": 安装失败（下载失败）。 </br> "STATUS_RECOVER_FAILURE_INVALID": 恢复预置应用失败。 </br> "STATUS_ABILITY_NOT_FOUND": Ability未找到。</br> "STATUS_BMS_SERVICE_ERROR": BMS服务错误。 </br> "STATUS_FAILED_NO_SPACE_LEFT": 设备空间不足。</br> "STATUS_GRANT_REQUEST_PERMISSIONS_FAILED": 应用授权失败。 </br> "STATUS_INSTALL_PERMISSION_DENIED": 缺少安装权限。 </br> "STATUS_UNINSTALL_PERMISSION_DENIED": 缺少卸载权限。 |

## 获取应用的沙箱路径
对于FA模型，应用的沙箱路径可以通过[Context](js-apis-inner-app-context.md)中的方法获取；对于Stage模型，应用的沙箱路径可以通过[Context](js-apis-inner-application-uiAbilityContext-sys.md#uiabilitycontext)中的属性获取。下面以获取沙箱文件路径为例。

**示例：**
``` ts
// Stage模型
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        let context = this.context;
        let pathDir = context.filesDir;
        console.info('sandbox path is ' + pathDir);
    }
}
```

<!--code_no_check_fa-->
``` ts
// FA模型
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();
context.getFilesDir().then((data: string) => {
    let pathDir = data;
    console.info('sandbox path is ' + pathDir);
});
```