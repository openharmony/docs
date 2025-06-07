# 包管理子系统Changelog

## cl.bundlemanager.1 安装的应用是已卸载的预置应用时校验签名是否一致

**访问级别**

公开接口

**变更原因**

预置应用被卸载后可以安装一个bundleName相同、签名信息不同的应用仿冒，有安全风险。

**变更影响**

该变更为不兼容变更。

变更前：预置应用被卸载后安装一个bundleName相同、签名信息中密钥和APP ID都不同的应用会安装成功。

变更后：预置应用被卸载后安装一个bundleName相同、签名信息中密钥和APP ID都不同的应用会安装失败。

**起始API Level**

API 7

**变更发生版本**

从OpenHarmony 5.0.0.54 版本开始。

**变更的接口/组件**

[bm工具](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/tools/bm-tool.md#%E5%AE%89%E8%A3%85%E5%91%BD%E4%BB%A4)安装命令。

**适配指导**

1. 重新签名，保证应用签名信息中的[密钥](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-signing#section462703710326)和[APP ID](https://developer.huawei.com/consumer/cn/doc/app/agc-help-createharmonyapp-0000001945392297)任意一个与预置应用的一致。
2. 修改安装应用的[bundleName](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/app-configuration-file.md)，确保与预置应用的不一致。

## cl.bundlemanager.2 bm uninstall命令无法直接卸载已设置应用锁的应用

**访问级别**

系统接口

**变更原因**

基于安全管控考虑，新增应用锁。bm uninstall命令卸载已设置应用锁的应用时，需要解锁或取消应用锁后才可卸载。

**变更影响**

此变更不涉及应用适配。

变更前：
bm uninstall命令可直接卸载应用，无需额外处理。

变更后：
bm uninstall命令卸载应用，若应用设置了应用锁会卸载失败。

**起始API Level**

API 6

**变更发生版本**

从OpenHarmony 5.0.0.54 版本开始。

**变更的接口/组件**

bm工具的uninstall命令

**适配指导**

bm uninstall命令卸载已设置应用锁的应用前，通过[deleteUninstallDisposedRule](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-ability-kit/js-apis-appControl-sys.md#appcontroldeleteuninstalldisposedrule15)接口关闭应用锁。若为终端设备，也可在设备的"设置"->"隐私和安全"->"应用锁"界面关闭应用锁，或在运行卸载命令后设备会弹出解锁页面，输入密码解锁即可。