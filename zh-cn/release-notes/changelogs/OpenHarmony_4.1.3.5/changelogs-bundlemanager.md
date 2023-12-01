# 包管理子系统ChangeLog
## cl.bundlemanager.1 打包工具默认以不压缩方式打包libs库

打包工具打包libs库时，默认方式由压缩打包变更为不压缩打包。若用户需要打包时对libs库进行压缩存储，可以设置compressNativeLibs参数为true，若不设置此参数，默认为false。

**变更影响**<br>
变更前，打包工具默认以压缩方式打包libs库。

变更后，打包工具默认以不压缩方式打包libs库。

**关键的接口/组件变更**<br>
无关联接口/组件

**适配指导**<br>
升级SDK即可。升级后，如果开发者需要以压缩方式打包libs库，可以设置[module.json5配置文件](../../../application-dev/quick-start/module-configuration-file.md)中的compressNativeLibs参数为true。
