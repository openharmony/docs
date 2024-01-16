# 包管理子系统变更说明

## cl.bundlemanager.1 打包工具打包libs库压缩等级变更

**访问级别**

其他

**变更原因**

在设置[module.json5配置文件](../../../application-dev/quick-start/module-configuration-file.md)中的compressNativeLibs参数为true的情况下，打包工具会以压缩方式打包libs库，可以通过适当调低压缩等级的方式，用较小的空间代价（包大小）换取较大的时间收益（打包耗时）。

**变更影响**

该变更为兼容性变更。在设置[module.json5配置文件](../../../application-dev/quick-start/module-configuration-file.md)中的compressNativeLibs参数为true的情况下，打包输出的未签名的包会略微变大。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.2版本开始。

**变更的接口/组件**

在设置[module.json5配置文件](../../../application-dev/quick-start/module-configuration-file.md)中的compressNativeLibs参数为true的情况下，修改前，打包工具以默认压缩等级（5）打包libs库，修改后，打包工具以极速压缩等级（1）打包libs库。

**适配指导**

无需适配。
