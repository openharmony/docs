# HapModuleInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 
> API9 当前为Canary版本，仅供试用，不保证接口可稳定调用。

Hap模块信息

## HapModuleInfo

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                                | 类型                           | 可读   | 可写   | 说明                 |
| --------------------------------- | ---------------------------- | ---- | ---- | ------------------ |
| name                              | string                       | 是    | 否    | 模块名称               |
| description                       | string                       | 是    | 否    | 模块描述信息             |
| descriptionId                     | number                       | 是    | 否    | 描述信息ID             |
| icon                              | string                       | 是    | 否    | 模块图标               |
| label                             | string                       | 是    | 否    | 模块标签               |
| labelId                           | number                       | 是    | 否    | 模块标签ID             |
| iconId                            | number                       | 是    | 否    | 模块图标ID             |
| backgroundImg                     | string                       | 是    | 否    | 模块背景图片             |
| supportedModes                    | number                       | 是    | 否    | 模块支持的模式            |
| reqCapabilities                   | Array\<string>               | 是    | 否    | 模块运行需要的能力          |
| deviceTypes                       | Array\<string>               | 是    | 否    | 支持运行的设备类型          |
| abilityInfo                       | Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>          | 是    | 否    | Ability信息          |
| moduleName                        | string                       | 是    | 否    | 模块名                |
| mainAbilityName                   | string                       | 是    | 否    | 入口Ability名称        |
| installationFree                  | boolean                      | 是    | 否    | 是否支持免安装            |
| mainElementName<sup>9+</sup>      | string                       | 是    | 否    | 入口ability信息        |
| extensionAbilityInfo<sup>9+</sup> | Array\<[ExtensionAbilityInfo](js-apis-bundle-ExtensionAbilityInfo.md)> | 是    | 否    | extensionAbility信息 |
| metadata<sup>9+</sup>             | Array\<[Metadata](js-apis-bundle-Metadata.md)>             | 是    | 否    | Ability的元信息        |
