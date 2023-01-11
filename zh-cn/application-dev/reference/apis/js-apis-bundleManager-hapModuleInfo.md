# HapModuleInfo

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

HAP信息，系统应用可以通过[bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)获取自身或其他应用的HAP信息，三方应用可以通过[getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的HAP信息，其中入参[bundleFlags](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-bundleManager.md#bundleflag)需要使用GET_BUNDLE_INFO_WITH_HAP_MODULE。

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
| moduleSourceDir                   | string                                                       | 是   | 否   | 模块的路径。|

