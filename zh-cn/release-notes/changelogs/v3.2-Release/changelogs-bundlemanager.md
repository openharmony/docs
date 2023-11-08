# 包管理子系统ChangeLog

## cl.bundlemanager.1 包管理删除@ohos.bundle.bundleManager.d.ts中的getAbilityIcon接口，可以使用@ohos.resourceManager.d.ts中的getMediaContent替换。

包管理删除[@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)中的getAbilityIcon接口，可以使用[@ohos.resourceManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.resourceManager.d.ts)中的getMediaContent替换。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了getAbilityIcon接口的，需要改为使用getMediaContent接口。

**关键的接口/组件变更**<br>
删除@ohos.bundle.bundleManager.d.ts中的getAbilityIcon接口。

**适配指导**<br>
使用@ohos.bundle.bundleManager.d.ts下面的getAbilityIcon，需要修改为@ohos.resourceManager.d.ts中的getMediaContent。需要提前获取到图标的资源ID值，可参考该接口的[使用指导](../../../application-dev/reference/apis/js-apis-resource-manager.md#getmediacontent9)。

## cl.bundlemanager.2 包管理底层能力变更，仅支持系统资源HAP自定义权限，其它HAP均不支持自定义权限。

仅支持系统资源HAP自定义权限，其它HAP均不支持自定义权限。包管理在解析HAP时，仅支持解析资源HAP(包名为：ohos.global.systemres)的配置文件中的definePermissions字段，该字段用来定义权限。其它HAP中配置的definePermissions字段将不会解析。
如果有应用需要自定义权限，可以在资源HAP的[配置文件](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)中definePermissions字段下面新增定义权限。格式可参考[定义权限](../../../application-dev/quick-start/module-structure.md#definepermissions对象内部结构)。


**变更影响**<br>
升级新版本镜像后，应用自定义的权限将不会生效，使用方在申请该权限时，会授权失败。

**关键的接口/组件变更**<br>
包管理底层能力变更，仅支持系统资源HAP自定义权限，其它HAP均不支持自定义权限。

**适配指导**<br>
如果有应用需要自定义权限，可以在资源HAP的[配置文件](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)中definePermissions字段下面新增定义权限。格式可参考[定义权限](../../../application-dev/quick-start/module-structure.md#definepermissions对象内部结构)。

## cl.bundlemanager.3 包管理二级模块文件名称变更，修改为文件内对应的接口名称

包管理二级模块文件名称变更，修改为文件内对应的接口名称，变更文件如下：

| 原文件名称 |变更后文件名称 |
|----|----|
| bundleManager/abilityInfo.d.ts |  bundleManager/AbilityInfo.d.ts |
| bundleManager/applicationInfo.d.ts |  bundleManager/ApplicationInfo.d.ts |
| bundleManager/bundleInfo.d.ts |  bundleManager/BundleInfo.d.ts |
| bundleManager/dispatchInfo.d.ts |  bundleManager/DispatchInfo.d.ts |
| bundleManager/elementName.d.ts |  bundleManager/ElementName.d.ts |
| bundleManager/extensionAbilityInfo.d.ts |  bundleManager/ExtensionAbilityInfo.d.ts |
| bundleManager/hapModuleInfo.d.ts |  bundleManager/HapModuleInfo.d.ts |
| bundleManager/launcherAbilityInfo.d.ts |  bundleManager/LauncherAbilityInfo.d.ts |
| bundleManager/metadata.d.ts |  bundleManager/Metadata.d.ts |
| bundleManager/packInfo.d.ts |  bundleManager/BundlePackInfo.d.ts |
| bundleManager/permissionDef.d.ts |  bundleManager/PermissionDef.d.ts |
| bundleManager/remoteAbilityInfo.d.ts |  bundleManager/RemoteAbilityInfo.d.ts |
| bundleManager/shortcutInfo.d.ts |  bundleManager/ShortcutInfo.d.ts |

除了免安装相关的BundlePackInfo文件名称增加了Bundle，其余文件名称均是修改为大写开头。

**变更影响**<br>
仅修改二级模块文件名称，不会影响一级模块的使用。在使用之前已发布的API 9各beta版本时，如果在ts文件中直接导入了bundleManager下面二级模块接口的，IDE中编译报错的话，需要修改导入的文件名称。

**关键的接口/组件变更**<br>
变更bundleManager文件夹下面的d.ts名称，修改为文件中的接口名称。

**适配指导**<br>
使用新的sdk后，正常情况下应用无需适配该变更。如果在应用中直接导入了bundleManager文件夹下面的文件，则需要修改导入的文件名称。可以按照如下的修改方式：

**修改前：**
```ts
import {AbilityInfo} from 'bundleManger/abilityInfo';
import {ExtensionAbilityInfo} from 'bundleManger/extensionAbilityInfo';
import {BundlePackInfo} from 'bundleManger/packInfo';
```
**修改后：**
```ts
import {AbilityInfo} from 'bundleManger/AbilityInfo';
import {ExtensionAbilityInfo} from 'bundleManger/ExtensionAbilityInfo';
import {BundlePackInfo} from 'bundleManger/BundlePackInfo';
```

## cl.bundlemanager.4 包管理LaunchType枚举类型名称变更，由STANDARD修改为MULTITON，枚举值不变。

包管理[LaunchType](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)枚举类型变更，由STANDARD修改为MULTITON，枚举值不变，表示多实例类型。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了LaunchType.STANDARD的，需要改为使用LaunchType.MULTITON接口。

**关键的接口/组件变更**<br>
LaunchType枚举类型名称变更，由LaunchType.STANDARD修改为LaunchType.MULTITON。

**适配指导**<br>
由LaunchType.STANDARD修改为LaunchType.MULTITON。

## cl.bundlemanager.5 包管理AbilityInfo结构体中isVisible字段修改为exported，类型不变。

包管理[AbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts)结构体中isVisible字段修改为exported，类型不变，表示当前ability是否支持导出，被其他的ability使用。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了isVisible的，需要改为使用exported。

**关键的接口/组件变更**<br>
包管理[AbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts)结构体中isVisible字段修改为exported，类型不变。

**适配指导**<br>
由isVisible修改为exported。

## cl.bundlemanager.6 包管理ExtensionAbilityInfo结构体中isVisible字段修改为exported，类型不变。

包管理[ExtensionAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts)结构体中isVisible字段修改为exported，类型不变，表示当前ability是否支持导出，被其他的ability使用。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了isVisible的，需要改为使用exported。

**关键的接口/组件变更**<br>
包管理[ExtensionAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts)结构体中isVisible字段修改为exported，类型不变。

**适配指导**<br>
由isVisible修改为exported。

## cl.bundlemanager.7 包管理ModuleAbilityInfo结构体中visible字段修改为exported，类型不变。

包管理[ModuleAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundlePackInfo.d.ts)结构体中visible字段修改为exported，类型不变，表示当前ability是否支持导出，被其他的ability使用。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了visible的，需要改为使用exported。

**关键的接口/组件变更**<br>
包管理[ModuleAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundlePackInfo.d.ts)结构体中visible字段修改为exported，类型不变。

**适配指导**<br>
由visible修改为exported。

## cl.bundlemanager.8 app.json配置文件删除distributedNotificationEnabled标签
删除配置文件app.json中[distributedNotificationEnabled](../../../application-dev/quick-start/app-configuration-file.md)标签

**变更影响**<br>
删除配置文件app.json中[distributedNotificationEnabled](../../../application-dev/quick-start/app-configuration-file.md)标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除[distributedNotificationEnabled](../../../application-dev/quick-start/app-configuration-file.md)标签

## cl.bundlemanager.9 app.json配置文件删除entityType标签
删除配置文件app.json中[entityType](../../../application-dev/quick-start/app-configuration-file.md)标签

**变更影响**<br>
删除配置文件app.json中[entityType](../../../application-dev/quick-start/app-configuration-file.md)标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除[entityType](../../../application-dev/quick-start/app-configuration-file.md)标签

## cl.bundlemanager.10 app.json配置文件删除keepAlive标签
删除配置文件app.json中[keepAlive](../../../application-dev/quick-start/app-configuration-file.md)标签

**变更影响**<br>
删除配置文件app.json中[keepAlive](../../../application-dev/quick-start/app-configuration-file.md)标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除[keepAlive](../../../application-dev/quick-start/app-configuration-file.md)标签

## cl.bundlemanager.11 app.json配置文件删除removable标签
删除配置文件app.json中[removable](../../../application-dev/quick-start/app-configuration-file.md)标签

**变更影响**<br>
删除配置文件app.json中[removable](../../../application-dev/quick-start/app-configuration-file.md)标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除[removable](../../../application-dev/quick-start/app-configuration-file.md)标签

## cl.bundlemanager.12 app.json配置文件删除singleton标签
删除配置文件app.json中[singleton](../../../application-dev/quick-start/app-configuration-file.md)标签

**变更影响**<br>
删除配置文件app.json中[singleton](../../../application-dev/quick-start/app-configuration-file.md)标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除[singleton](../../../application-dev/quick-start/app-configuration-file.md)标签

## cl.bundlemanager.13 app.json配置文件删除userDataClearable标签
删除配置文件app.json中[userDataClearable](../../../application-dev/quick-start/app-configuration-file.md)标签

**变更影响**<br>
删除配置文件app.json中[userDataClearable](../../../application-dev/quick-start/app-configuration-file.md)标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除[userDataClearable](../../../application-dev/quick-start/app-configuration-file.md)标签

## cl.bundlemanager.14 module.json配置文件中module的name标签不再支持配置中文
module.json配置文件中的module的[name](../../../application-dev/quick-start/module-configuration-file.md)不再支持配置中文

**变更影响**<br>
删除配置文件module.json中module的[name](../../../application-dev/quick-start/module-configuration-file.md)标签不再支持配置中文，IDE中配置该标签为中文，会导致IDE编译报错

**适配指导**<br>
使用英文语言配置module.json中module的[name](../../../application-dev/quick-start/module-configuration-file.md)标签

## cl.bundlemanager.15 module.json配置文件中ability的name标签不再支持配置中文
module.json配置文件中的ability的[name](../../../application-dev/quick-start/module-configuration-file.md)不再支持配置中文

**变更影响**<br>
删除配置文件module.json中ability的[name](../../../application-dev/quick-start/module-configuration-file.md)标签不再支持配置中文，IDE中配置该标签为中文，会导致IDE编译报错

**适配指导**<br>
使用英文语言配置module.json中ability的[name](../../../application-dev/quick-start/module-configuration-file.md)标签

## cl.bundlemanager.16 module.json配置文件删除uiSyntax标签
删除配置文件module.json中[uiSyntax](../../../application-dev/quick-start/module-configuration-file.md)标签

**变更影响**<br>
删除配置文件module.json中[uiSyntax](../../../application-dev/quick-start/module-configuration-file.md)标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除module.json中[uiSyntax](../../../application-dev/quick-start/module-configuration-file.md)标签

## cl.bundlemanager.17 module.json配置文件中module及ability中的srcEntrance标签修改为srcEntry
配置文件module.json中[srcEntrance](../../../application-dev/quick-start/module-configuration-file.md)标签修改为srcEntry

**变更影响**<br>
删除配置文件module.json中[srcEntrance](../../../application-dev/quick-start/module-configuration-file.md)标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除module.json中[srcEntrance](../../../application-dev/quick-start/module-configuration-file.md)标签，使用srcEntry替代

## cl.bundlemanager.18 删除module.json配置文件中distroFilter的apiVersion标签
删除配置文件module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)的apiVersion标签

**变更影响**<br>
删除配置文件module.json[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)的apiVersion标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)的apiVersion标签

## cl.bundlemanager.19 module.json配置文件中launchTypede标签standard模式修改为multiton
删除module.json中[launchType](../../../application-dev/quick-start/module-configuration-file.md)标签的standard模式修改为multiton

**适配指导**<br>
删除module.json中[launchType](../../../application-dev/quick-start/module-configuration-file.md)标签的standard模式，使用multiton替代

## cl.bundlemanager.20 app.json配置文件删除atomicService标签
删除配置文件app.json中atomicService标签

**变更影响**<br>
删除配置文件app.json中atomicService标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除atomicService标签

## cl.bundlemanager.21 app.json配置文件新增bundleType标签
配置文件app.json中新增bundleType标签

**变更影响**<br>
现存的元服务（[installationFree](../../../application-dev/quick-start/module-configuration-file.md)为true），必须在app.json中指定bundleType为atomicService，否则打包失败。

**适配指导**<br>
新增[bundleType](../../../application-dev/quick-start/app-configuration-file.md)标签。该标签为可缺省（缺省值为app）。该标签需要和module.json中[installationFree](../../../application-dev/quick-start/module-configuration-file.md)字段保持一一对应，其相应规则为：
- 当bundleType为app时，installationFree必须为false。
- 当bundleType为atomicService时，installationFree必须为true。

## cl.bundlemanager.22 包管理ApplicationInfo结构体中删除split字段。

包管理[ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)结构体中删除split字段。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了split的，会编译失败。

**关键的接口/组件变更**<br>
包管理[ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)结构体中删除split字段。

**适配指导**<br>
删除ApplicationInfo结构体中的split字段。目前元服务中stage模型强制分包，不支持不分包。

## cl.bundlemanager.23 包管理HapModuleInfo结构体中删除atomicServiceModuleType字段。

包管理[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中删除atomicServiceModuleType字段。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了atomicServiceModuleType的，会编译失败。

**关键的接口/组件变更**<br>
包管理[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中删除atomicServiceModuleType字段。

**适配指导**<br>
删除[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中的atomicServiceModuleType字段。判断atomicServiceModuleType字段的部分，用[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中的moduleType代替。

## cl.bundlemanager.24 包管理删除AtomicServiceModuleType枚举值。

包管理[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中删除atomicServiceModuleType字段。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了atomicServiceModuleType的，会编译失败。

**关键的接口/组件变更**<br>
包管理[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中删除atomicServiceModuleType字段。

**适配指导**<br>
删除[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中的atomicServiceModuleType字段。判断atomicServiceModuleType字段的部分，用[HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)结构体中的moduleType代替。