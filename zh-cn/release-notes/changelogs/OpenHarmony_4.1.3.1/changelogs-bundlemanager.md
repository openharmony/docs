# 包管理子系统ChangeLog

## cl.bundlemanager.1 非MDM应用不能申请MDM权限，否则安装失败。

**访问级别**

系统接口

**变更原因**

MDM类型的权限仅限MDM类型的应用使用。

**变更影响**

非MDM应用不能申请MDM权限，否则安装失败。

MDM应用判断逻辑只根据[签名证书](../../../application-dev/security/app-provision-structure.md)中的app-distribution-type字段来判断是否为MDM应用，规则如下：
* app-distribution-type为enterprise_mdm，则为MDM应用。
* app-distribution-type不为enterprise_mdm，则为非MDM应用。

MDM权限判断逻辑是根据[权限定义](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)中definePermissions字段中availableType属性来判断是否为MDM权限，规则如下：
* availableType为MDM，则为MDM权限。
* availableType不为MDM，则为非MDM权限。

**变更发生版本**

从OpenHarmony SDK 4.1.3.1开始

**变更的接口/组件**

应用在申请权限时，Stage模型对应[module.json5](../../../application-dev/quick-start/module-structure.md#reqpermissions权限申请)，FA模型对应[config.json](../../../application-dev/quick-start/module-configuration-file.md#requestpermissions标签)。非enterprise_mdm类型的应用（app-distribution-type不为enterprise_mdm），不再能申请MDM类型的权限。

**适配指导**

业务需要确认自身是否为MDM应用，如果不是，则不能继续申请MDM权限。