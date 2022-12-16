# HapModuleInfo

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## HapModuleInfo

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core

| 名称                              | 类型                                                         | 可读 | 可写 | 说明                 |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | -------------------- |
| name                              | string                                                       | 是   | 否   | 模块名称             |
| icon                              | string                                                       | 是   | 否   | 模块图标             |
| iconId                            | number                                                       | 是   | 否   | 模块图标资源id       |
| label                             | string                                                       | 是   | 否   | 模块标签             |
| labelId                           | number                                                       | 是   | 否   | 模块标签资源id       |
| description                       | string                                                       | 是   | 否   | 模块描述信息         |
| descriptionId                     | number                                                       | 是   | 否   | 描述信息资源id       |
| mainElementName                   | string                                                       | 是   | 否   | 入口ability信息      |
| abilitiesInfo                     | Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>         | 是   | 否   | Ability信息          |
| extensionAbilitiesInfo            | Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | 是   | 否   | extensionAbility信息 |
| metadata                          | Array\<[Metadata](js-apis-bundleManager-metadata.md)>               | 是   | 否   | Ability的元信息      |
| deviceTypes                       | Array\<string>                                               | 是   | 否   | 支持运行的设备类型   |
| installationFree                  | boolean                                                      | 是   | 否   | 是否支持免安装       |
| hashValue                         | string                                                       | 是   | 否   | Module的Hash值              |
| moduleSourceDir | string   | 是   | 否   | Module的路径|

