# 包管理子系统ChangeLog

## cl.bundlemanager.1 app.json配置文件删除atomicService标签
删除配置文件app.json中atomicService标签

**变更影响**<br>
删除配置文件app.json中atomicService标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除atomicService标签

## cl.bundlemanager.2 app.json配置文件新增bundleType标签
配置文件app.json中新增bundleType标签

**变更影响**<br>
现存的元服务（[installationFree](../../../application-dev/quick-start/module-configuration-file.md)为true），必须在app.json中指定bundleType为atomicService，否则打包失败。

**适配指导**<br>
新增[bundleType](../../../application-dev/quick-start/app-configuration-file.md)标签。该标签为可缺省（缺省值为app）。该标签需要和module.json中[installationFree](../../../application-dev/quick-start/module-configuration-file.md)字段保持一一对应，其相应规则为：
- 当bundleType为app时，installationFree必须为false。
- 当bundleType为atomicService时，installationFree必须为true。

## cl.bundlemanager.3 包管理ApplicationInfo结构体中删除split字段。

包管理[ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)结构体中删除split字段。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了split的，会编译失败。

**关键的接口/组件变更**<br>
包管理[ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)结构体中删除split字段。

**适配指导**<br>
删除ApplicationInfo结构体中的split字段。目前元服务中stage模型强制分包，不支持不分包。

## cl.bundlemanager.4 包管理HapModuleInfo结构体中删除atomicServiceModuleType字段。

包管理[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中删除atomicServiceModuleType字段。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了atomicServiceModuleType的，会编译失败。

**关键的接口/组件变更**<br>
包管理[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中删除atomicServiceModuleType字段。

**适配指导**<br>
删除[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中的atomicServiceModuleType字段。判断atomicServiceModuleType字段的部分，用[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中的moduleType代替。

## cl.bundlemanager.5 包管理删除AtomicServiceModuleType枚举值。

包管理[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中删除atomicServiceModuleType字段。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了atomicServiceModuleType的，会编译失败。

**关键的接口/组件变更**<br>
包管理[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中删除atomicServiceModuleType字段。

**适配指导**<br>
删除[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中的atomicServiceModuleType字段。判断atomicServiceModuleType字段的部分，用[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中的moduleType代替。