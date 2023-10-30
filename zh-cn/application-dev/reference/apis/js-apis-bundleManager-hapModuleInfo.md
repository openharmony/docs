# HapModuleInfo

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

HAP信息，系统应用可以通过[bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)获取自身或其他应用的HAP信息，三方应用可以通过[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的HAP信息，其中入参[bundleFlags](js-apis-bundleManager.md#bundleflag)需要使用GET_BUNDLE_INFO_WITH_HAP_MODULE。

## HapModuleInfo

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core

| 名称                              | 类型                                                         | 可读 | 可写 | 说明                 |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | -------------------- |
| name                              | string                                                       | 是   | 否   | 模块名称。             |
| icon                              | string                                                       | 是   | 否   | 模块图标。             |
| iconId                            | number                                                       | 是   | 否   | 模块图标的资源id值。       |
| label                             | string                                                       | 是   | 否   | 模块标签。             |
| labelId                           | number                                                       | 是   | 否   | 模块标签的资源id值。       |
| description                       | string                                                       | 是   | 否   | 模块描述信息。         |
| descriptionId                     | number                                                       | 是   | 否   | 描述信息的资源id值。       |
| mainElementName                   | string                                                       | 是   | 否   | 入口ability信息。      |
| abilitiesInfo                     | Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>         | 是   | 否   | Ability信息。          |
| extensionAbilitiesInfo            | Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | 是   | 否   | ExtensionAbility信息。 |
| metadata                          | Array\<[Metadata](js-apis-bundleManager-metadata.md)>               | 是   | 否   | Ability的元信息。      |
| deviceTypes                       | Array\<string>                                               | 是   | 否   | 可以运行模块的设备类型。   |
| installationFree                  | boolean                                                      | 是   | 否   | 模块是否支持免安装。       |
| hashValue                         | string                                                       | 是   | 否   | 模块的Hash值。              |
| moduleType                        | [ModuleType](js-apis-bundleManager.md#moduletype)            | 是   | 否   | 标识当前模块的类型。      |
| preloads                          | Array\<[PreloadItem](#preloaditem)>                          | 是   | 否   | 原子化服务中模块的预加载列表。|
| dependencies                      | Array\<[Dependency](#dependency)>                            | 是   | 否   | 模块运行依赖的动态共享库列表。  |
| fileContextMenu                   | string                                                       | 是   | 否   | 模块的右键菜单配置。      |

## PreloadItem

描述原子化服务中模块的预加载模块信息。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称      | 类型           | 可读 | 可写 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
|moduleName | string         | 是   | 否   | 模块运行时，由系统自动执行预加载的模块名称。|

## Dependency

描述模块所依赖的动态共享库信息。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称        | 类型   | 可读 | 可写 | 说明                   |
| ----------- | ------ | ---- | ---- | ---------------------- |
| bundleName  | string | 是   | 否   | 标识当前模块依赖的共享包包名。       |
| moduleName  | string | 是   | 否   | 标识当前模块依赖的共享包模块名。 |
| versionCode | number | 是   | 否   | 标识当前共享包的版本号。   |