# 包管理子系统ChangeLog
## cl.bundlemanager.1 打包工具modulecheck、configcheck校验schema变更

schema校验文件app.json、module.json、configSchema_lite.json和configSchema_rich.json中，对bundleName的长度限定由最大127改为最大128。

**变更影响**<br>
变更前，项目允许的bundleName最大长度为127，设置项目bundleName的长度大于等于128时，DevEco Studio IDE无法编译、打包该项目，IDE报错：Schema validate failed。

变更后，项目允许的bundleName最大长度为128，设置项目bundleName的长度等于128时，DevEco Studio IDE可以成功编译、打包该项目；设置项目bundleName的长度大于128时，DevEco Studio IDE无法编译、打包该项目，IDE报错：Schema validate failed。

**关键的接口/组件变更**<br>
无关联接口/组件

**适配指导**<br>
升级SDK即可，开发者无需适配。
