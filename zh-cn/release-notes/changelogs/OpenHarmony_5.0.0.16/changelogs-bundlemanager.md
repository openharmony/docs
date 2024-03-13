# 包管理子系统变更说明

## cl.bundlemanager.1 删除const.product.developmentmode系统参数的解析

**访问级别**

其他

**变更原因**

在API9时，包管理使用系统参数const.product.developmentmode，用于对debug签名证书应用的安装豁免校验设备udid。在API11时，系统开始支持开发者模式，通过开发者模式加强对debug签名证书应用安装的管控，此时依然可以通过原有的系统参数跳过设备udid的校验。在API12时，包管理删除对const.product.developmentmode的解析，安装debug签名应用时无法再跳过设备udid的校验。

**变更影响**

该变更为非兼容性变更。该系统参数没有相应的文档描述，且本身不保证兼容性。

对于debug签名证书应用安装产生影响，无法再通过设置const.product.developmentmode的方式来跳过udid校验。对系统镜像中的应用无影响，该系统参数默认不存在，且重启后会失效。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.16开始。

**适配指导**

当前对于debug签名应用安装校验udid的管控已加强，无法再通过配置系统参数来跳过设备udid的校验。如需安装debug签名证书的应用，需要确保将安装设备的udid添加到应用签名profile中。
