# 应用程序包安装卸载与更新

本章节介绍应用程序包的安装卸载流程和两种更新方式。

## 应用程序包的安装卸载
开发者可以通过调试命令安装和卸载应用，详情参考[编译发布与上架部署流程图](./application-package-structure-stage.md#发布态包结构)。

**图1** 应用程序包安装和卸载流程（开发者）

![hap-intall-uninstall](figures/hap-install-uninstall-developer.png)


应用上架应用市场后，终端设备用户可在设备上通过应用市场安装和卸载应用。

**图2** 应用程序包安装和卸载流程（终端设备用户）

![hap-intall-uninstall](figures/hap-install-uninstall-user.png)

## 应用程序包的更新


对于开发者，应用程序包的更新，首先需要更新[app.json5配置文件](./app-configuration-file.md#appjson5配置文件)中的versionCode版本号字段，通过IDE打包后在应用市场发布，发布流程与首次发布一致。对于终端设备用户，新版本发布后，可以通过以下两种方式更新应用程序包。

- 应用市场内更新：应用市场通知用户该应用有新版本，用户根据通知到应用市场（客户端）进行升级。
- 应用内检测升级：开发者根据[更新指导](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/store-update#section316371715233)实现版本更新提醒功能，应用启动完成或用户在应用中主动检查新版本时，会弹出升级对话框，用户根据对话框提示升级。
