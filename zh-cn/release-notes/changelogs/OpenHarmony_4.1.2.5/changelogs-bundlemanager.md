# 包管理子系统ChangeLog

## cl.bundlemanager.1 系统应用判断逻辑调整。

系统应用判断逻辑修改为只根据[签名证书](../../../application-dev/security/app-provision-structure.md)中的app-feature字段来判断是否为系统应用，规则如下：
* app-feature为hos_system_app，则为系统应用。
* app-feature为hos_normal_app，则为三方应用。

**变更影响**<br>
如果应用位于"/system/app"下面，并且路径配置在"/****/etc/app/install_list.json”文件中，但是app-feature为hos_normal_app，该应用将无法使用systemApi。

**关键的接口/组件变更**<br>
不涉及接口及组件变更。

**适配指导**<br>
业务需要确认自身是否为系统应用，如果是，则需要修改app-feature为hos_system_app，并对HAP重新签名。


## c2.bundlemanager.2 包管理ApplicationInfo结构体中新增dataUnclearable字段。

包管理[ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)结构体中新增dataUnclearable字段，参考：[API文档链接](../../../application-dev/reference/apis/js-apis-bundle-ApplicationInfo.md)。

**变更影响**<br>
对之前接口使用无影响。

**关键的接口/组件变更**<br>
包管理[ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)结构体中新增dataUnclearable字段，参考：[API文档链接](../../../application-dev/reference/apis/js-apis-bundle-ApplicationInfo.md)。

**适配指导**<br>
无
