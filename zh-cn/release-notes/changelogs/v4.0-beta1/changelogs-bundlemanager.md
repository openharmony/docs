# 包管理子系统ChangeLog

## cl.bundlemanager.1 底层能力变更，安装hap时，hap中的文件不再解压到安装目录。

安装hap后，安装目录下只会存在hap文件，应用不能再使用拼接路径访问解压后的资源文件，应用想要访问资源文件，需要使用标准的资源管理接口。

**变更影响**<br>
如果应用使用拼接路径的形式访问资源文件，会访问失败。需要修改成使用资源管理接口访问资源文件。

**关键的接口/组件变更**<br>
不涉及接口及组件变更

**适配指导**<br>
资源管理子系统提供Js接口访问资源文件。参考[访问资源文件](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md#getrawfilecontent9)


## cl.bundlemanager.2 包管理删除@ohos.bundle.bundleManager.d.ts中的getAbilityIcon接口，可以使用@ohos.resourceManager.d.ts中的getMediaContent替换。

包管理删除[@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)中的getAbilityIcon接口，可以使用[@ohos.resourceManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.resourceManager.d.ts)中的getMediaContent替换。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了getAbilityIcon接口的，需要改为使用getMediaContent接口。

**关键的接口/组件变更**<br>
删除@ohos.bundle.bundleManager.d.ts中的getAbilityIcon接口。

**适配指导**<br>
使用@ohos.bundle.bundleManager.d.ts下面的getAbilityIcon，需要修改为@ohos.resourceManager.d.ts中的getMediaContent。需要提前获取到图标的资源ID值，可参考该接口的[使用指导](../../../application-dev/reference/apis/js-apis-resource-manager.md#getmediacontent9)。

## cl.bundlemanager.3 包管理新增202错误码

包管理系统新增202错误码，非系统应用调用api9及之后包管理提供的系统api，将返回错误202。

**变更影响**<br>
非系统应用调用api9及之后包管理提供的系统api，将返回错误202。

**关键的接口/组件变更**<br>
所有包管理提供的api9及之后的系统api，非系统应用调用将返回错误202。

**适配指导**<br>
不影响已开发的程序，无需适配。


## cl.bundlemanager.4 包管理底层能力变更，仅支持系统资源HAP自定义权限，其它HAP均不支持自定义权限。

仅支持系统资源HAP自定义权限，其它HAP均不支持自定义权限。包管理在解析HAP时，仅支持解析资源HAP(包名为：ohos.global.systemres)的配置文件中的definePermissions字段，该字段用来定义权限。其它HAP中配置的definePermissions字段将不会解析。
如果有应用需要自定义权限，可以在资源HAP的[配置文件](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)中definePermissions字段下面新增定义权限。格式可参考[定义权限](../../../application-dev/quick-start/module-structure.md#definepermissions对象内部结构)。


**变更影响**<br>
升级新版本镜像后，应用自定义的权限将不会生效，使用方在申请该权限时，会授权失败。

**关键的接口/组件变更**<br>
包管理底层能力变更，仅支持系统资源HAP自定义权限，其它HAP均不支持自定义权限。

**适配指导**<br>
如果有应用需要自定义权限，可以在资源HAP的[配置文件](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)中definePermissions字段下面新增定义权限。格式可参考[定义权限](../../../application-dev/quick-start/module-structure.md#definepermissions对象内部结构)。

## cl.bundlemanager.5 包管理二级模块文件名称变更，修改为文件内对应的接口名称

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

## cl.bundlemanager.6 包管理LaunchType枚举类型名称变更，由STANDARD修改为MULTITON，枚举值不变。

包管理[LaunchType](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)枚举类型变更，由STANDARD修改为MULTITON，枚举值不变，表示多实例类型。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了LaunchType.STANDARD的，需要改为使用LaunchType.MULTITON接口。

**关键的接口/组件变更**<br>
LaunchType枚举类型名称变更，由LaunchType.STANDARD修改为LaunchType.MULTITON。

**适配指导**<br>
由LaunchType.STANDARD修改为LaunchType.MULTITON。

## cl.bundlemanager.7 包管理AbilityInfo结构体中isVisible字段修改为exported，类型不变。

包管理[AbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts)结构体中isVisible字段修改为exported，类型不变，表示当前ability是否支持导出，被其他的ability使用。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了isVisible的，需要改为使用exported。

**关键的接口/组件变更**<br>
包管理[AbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts)结构体中isVisible字段修改为exported，类型不变。

**适配指导**<br>
由isVisible修改为exported。

## cl.bundlemanager.8 包管理ExtensionAbilityInfo结构体中isVisible字段修改为exported，类型不变。

包管理[ExtensionAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts)结构体中isVisible字段修改为exported，类型不变，表示当前ability是否支持导出，被其他的ability使用。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了isVisible的，需要改为使用exported。

**关键的接口/组件变更**<br>
包管理[ExtensionAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts)结构体中isVisible字段修改为exported，类型不变。

**适配指导**<br>
由isVisible修改为exported。

## cl.bundlemanager.9 包管理ModuleAbilityInfo结构体中visible字段修改为exported，类型不变。

包管理[ModuleAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundlePackInfo.d.ts)结构体中visible字段修改为exported，类型不变，表示当前ability是否支持导出，被其他的ability使用。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了visible的，需要改为使用exported。

**关键的接口/组件变更**<br>
包管理[ModuleAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundlePackInfo.d.ts)结构体中visible字段修改为exported，类型不变。

**适配指导**<br>
由visible修改为exported。
