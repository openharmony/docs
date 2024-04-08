# HapModuleInfo

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

HAP信息，三方应用可以通过[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的HAP信息，其中入参[bundleFlags](js-apis-bundleManager.md#bundleflag)至少包含GET_BUNDLE_INFO_WITH_HAP_MODULE。

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
| abilitiesInfo                     | Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>         | 是   | 否   | Ability信息。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_ABILITY获取。 |
| extensionAbilitiesInfo            | Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | 是   | 否   | ExtensionAbility信息。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY获取。 |
| metadata                          | Array\<[Metadata](js-apis-bundleManager-metadata.md)>               | 是   | 否   | Ability的元信息。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_METADATA获取。 |
| deviceTypes                       | Array\<string>                                               | 是   | 否   | 可以运行模块的设备类型。   |
| installationFree                  | boolean                                                      | 是   | 否   | 模块是否支持免安装。       |
| hashValue                         | string                                                       | 是   | 否   | 模块的Hash值。              |
| type                              | [ModuleType](js-apis-bundleManager.md#moduletype)            | 是   | 否   | 标识当前模块的类型。      |
| preloads                          | Array\<[PreloadItem](#preloaditem)>                          | 是   | 否   | 元服务中模块的预加载列表。|
| dependencies                      | Array\<[Dependency](#dependency)>                            | 是   | 否   | 模块运行依赖的动态共享库列表。  |
| fileContextMenuConfig<sup>11+</sup>     | string                                                       | 是   | 否   | 模块的文件菜单配置。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_MENU获取。 |
| routerMap<sup>12+</sup>           | Array\<[RouterItem](#routeritem)>                            | 是   | 否   | [模块的路由表配置](../../quick-start/module-configuration-file.md#routermap标签)。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_ROUTER_MAP获取。 |
| codePath<sup>12+</sup>            | string                                                       | 是   | 否   | 模块的安装路径。              |
| nativeLibraryPath<sup>12+</sup> | string                                                                     | 是   | 否   | 应用程序内某个hapModule的本地库文件路径。                                                                                                   |

## PreloadItem

描述元服务中模块的预加载模块信息。

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

## RouterItem<sup>12+</sup>

描述模块配置的路由表信息。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称           | 类型   | 只读 | 必填 | 说明                   |
| ------------- | ------ | ---- | ---- | ---------------------- |
| name          | string | 是   | 是   | 标识跳转页面的名称。       |
| pageModule    | string | 是   | 是   | 标识页面所在的模块名称。 |
| pageSourceFile| string | 是   | 是   | 标识页面在模块内的路径。   |
| buildFunction | string | 是   | 是   | 标识被@Builder修饰的函数，该函数描述页面的UI。   |
| data          | Array\<[DataItem](#dataitem12)> | 是   | 是   | 标识自定义数据。   |

## DataItem<sup>12+</sup> 

描述模块配置的路由表中的自定义数据。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称          | 类型    | 只读 | 必填 | 说明                   |
| ------------- | ------ | ---- | ---- | ---------------------- |
| key           | string | 是   | 是   | 标识路由表自定义数据的键。       |
| value         | string | 是   | 是   | 标识路由表自定义数据的值。 |