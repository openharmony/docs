# HapModuleInfo

HAP信息，可以通过[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的HAP信息，其中参数[bundleFlags](js-apis-bundleManager.md#bundleflag)至少包含GET_BUNDLE_INFO_WITH_HAP_MODULE。

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## HapModuleInfo

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称                              | 类型                                                         | 只读 | 可选 | 说明                 |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | -------------------- |
| name                              | string                                                       | 是   | 否   | 模块名称。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| icon                              | string                                                       | 是   | 否   | 模块图标。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| iconId                            | number                                                       | 是   | 否   | 模块图标的资源id值。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| label                             | string                                                       | 是   | 否   | 模块标签。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| labelId                           | number                                                       | 是   | 否   | 模块标签的资源id值。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| description                       | string                                                       | 是   | 否   | 模块描述信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| descriptionId                     | number                                                       | 是   | 否   | 描述信息的资源id值。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| mainElementName                   | string                                                       | 是   | 否   | 当前模块的入口UIAbility名称或者ExtensionAbility名称。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| abilitiesInfo                     | Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>         | 是   | 否   | Ability信息。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_ABILITY获取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| extensionAbilitiesInfo            | Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | 是   | 否   | ExtensionAbility信息。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY获取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| metadata                          | Array\<[Metadata](js-apis-bundleManager-metadata.md)>               | 是   | 否   | Ability的元信息。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_METADATA获取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| deviceTypes                       | Array\<string>                                               | 是   | 否   | 模块支持安装的运行设备类型的集合。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| installationFree                  | boolean                                                      | 是   | 否   | 模块是否支免安装（无需用户通过应用市场显式安装），取值为true表示支持免安装，取值为false表示不支持免安装。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| hashValue                         | string                                                       | 是   | 否   | 模块的Hash值。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| type                              | [bundleManager.ModuleType](js-apis-bundleManager.md#moduletype)            | 是   | 否   | 标识当前模块的类型。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| preloads                          | Array\<[PreloadItem](#preloaditem)>                          | 是   | 否   | 原子化服务中模块的预加载列表。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| dependencies                      | Array\<[Dependency](#dependency)>                            | 是   | 否   | 模块运行依赖的动态共享库列表。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| fileContextMenuConfig<sup>11+</sup>     | string                                                       | 是   | 否   | 模块的文件菜单配置。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_MENU获取。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| routerMap<sup>12+</sup>           | Array\<[RouterItem](#routeritem12)>                            | 是   | 否   | [模块的路由表配置](../../quick-start/module-configuration-file.md#routermap标签)。通过调用[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，bundleFlags参数传入GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_ROUTER_MAP获取。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| codePath<sup>12+</sup>            | string                                                       | 是   | 否   | 模块的安装路径。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| nativeLibraryPath<sup>12+</sup>     | string                                                       | 是   | 否   | 应用程序内模块本地库文件路径。                    |

## PreloadItem

描述原子化服务中模块的预加载模块信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力:** SystemCapability.BundleManager.BundleFramework.Core

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
|moduleName | string         | 是   | 否   | 模块名称。|

## Dependency

描述模块所依赖的动态共享库信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称        | 类型   | 只读 | 可选 | 说明                   |
| ----------- | ------ | ---- | ---- | ---------------------- |
| bundleName<sup>10+</sup>  | string | 是   | 否   | 标识当前模块依赖的共享包包名。       |
| moduleName  | string | 是   | 否   | 标识当前模块依赖的共享包模块名。 |
| versionCode<sup>10+</sup> | number | 是   | 否   | 标识当前共享包的版本号。   |

## RouterItem<sup>12+</sup>

描述模块配置的路由表信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称           | 类型   | 只读 | 可选 | 说明                   |
| ------------- | ------ | ---- | ---- | ---------------------- |
| name          | string | 是   | 否   | 标识跳转页面的名称。       |
| pageSourceFile| string | 是   | 否   | 标识页面在模块内的路径。   |
| buildFunction | string | 是   | 否   | 标识被@Builder修饰的函数，该函数描述页面的UI。   |
| data          | Array\<[DataItem](#dataitem12)> | 是   | 否   | 标识[路由表配置文件](../../quick-start/module-configuration-file.md#routermap标签)中的字符串自定义数据，即data字段的信息，该字段已由系统解析，无需开发者自行解析。   |
| customData    | string | 是   | 否   | 标识[路由表配置文件](../../quick-start/module-configuration-file.md#routermap标签)中的任意类型的自定义数据，即customData字段的JSON字符串，开发者需要调用JSON.parse函数解析出具体内容。   |

## DataItem<sup>12+</sup>

描述模块配置的路由表中的自定义数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称          | 类型    | 只读 | 可选 | 说明                   |
| ------------- | ------ | ---- | ---- | ---------------------- |
| key           | string | 是   | 否   | 标识路由表自定义数据的键。       |
| value         | string | 是   | 否   | 标识路由表自定义数据的值。 |
