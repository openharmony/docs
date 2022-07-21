# BundleInstaller



> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



在设备上安装、升级和删除捆绑包



## 系统能力

SystemCapability.BundleManager.BundleFramework

## BundleInstaller.install

install(bundleFilePaths: Array&lt;string&gt;, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

以异步方法在HAP中安装应用程序，使用callback形式返回结果。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称            | 类型                                                 | 必填 | 描述                                                         |
| --------------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFilePaths | Array&lt;string&gt;                                  | 是   | 指示存储应用程序包的路径。路径应该是当前应用程序的数据目录的相对路径。 |
| param           | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                                     |
| callback        | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | 是   | 程序启动作为入参的回调函数，返回安装状态信息。               |

## BundleInstaller.uninstall

uninstall(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

以异步方法卸载应用程序，使用callback形式返回结果。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称       | 类型                                                 | 必填 | 描述                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 包名                                           |
| param      | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                       |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | 是   | 程序启动作为入参的回调函数，返回安装状态信息。 |

## BundleInstaller.recover

recover(bundleName: string, param: InstallParam, callback: AsyncCallback&lt;InstallStatus&gt;): void;

以异步方法恢复一个应用程序，使用callback形式返回结果。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称       | 类型                                                 | 必填 | 描述                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| bundleName | string                                               | 是   | 包名                                           |
| param      | [InstallParam](#installparam)                        | 是   | 指定安装所需的其他参数。                       |
| callback   | AsyncCallback&lt;[InstallStatus](#installstatus)&gt; | 是   | 程序启动作为入参的回调函数，返回安装状态信息。 |

## InstallParam

应用程序安装卸载信息

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称        | 类型    | 说明               |
| ----------- | ------- | ------------------ |
| userId      | number  | 指示用户id         |
| installFlag | number  | 指示安装标志       |
| isKeepData  | boolean | 指示参数是否有数据 |

## InstallStatus

应用程序安装状态

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称          | 类型                                                         | 可读 | 可写 | 说明                           |
| ------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------ |
| status        | bundle.[InstallErrorCode](js-apis-Bundle.md#installerrorcode) | 是   | 否   | 表示安装或卸载错误状态码       |
| statusMessage | string                                                       | 是   | 否   | 表示安装或卸载的字符串结果信息 |