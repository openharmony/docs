# 包管理子系统ChangeLog

## cl.bundlemanager.1 非MDM应用不能申请MDM权限，否则安装失败。

MDM应用判断逻辑只根据[签名证书](../../../application-dev/security/app-provision-structure.md)中的app-distribution-type字段来判断是否为MDM应用，规则如下：
* app-distribution-type为enterprise_mdm，则为MDM应用。
* app-distribution-type不为enterprise_mdm，则为非MDM应用。
  
MDM权限判断逻辑是根据[权限定义](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)中definePermissions字段中availableType属性来判断是否为MDM权限，规则如下：
* availableType为MDM，则为MDM权限。
* availableType不为MDM，则为非MDM权限。

**变更影响**<br>
如果应用是非MDM应用，但是申请了MDM权限的权限，会导致无法安装。

**关键的接口/组件变更**<br>
不涉及接口及组件变更。

**适配指导**<br>
业务需要确认自身是否为MDM应用，如果不是，则不能继续申请MDM权限。