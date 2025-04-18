# HapModuleInfo

Hap模块信息，未做特殊说明的属性，均通过[bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated)获取。

> **说明：**
> 
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 从API Version 9开始，该模块不再维护，建议使用[bundleManager-HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)替代。

## HapModuleInfo<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[bundleManager-HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md#hapmoduleinfo-1)替代。

**系统能力：** SystemCapability.BundleManager.BundleFramework

| 名称                              | 类型                                                         | 只读 | 可选 | 说明                 |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | -------------------- |
| name                              | string                                                       | 是   | 否   | 模块名称。             |
| description                       | string                                                       | 是   | 否   | 模块描述信息。         |
| descriptionId                     | number                                                       | 是   | 否   | 描述信息ID。           |
| icon                              | string                                                       | 是   | 否   | 模块图标。             |
| label                             | string                                                       | 是   | 否   | 模块标签。             |
| labelId                           | number                                                       | 是   | 否   | 模块标签ID。           |
| iconId                            | number                                                       | 是   | 否   | 模块图标ID。           |
| backgroundImg                     | string                                                       | 是   | 否   | 模块背景图片。         |
| supportedModes                    | number                                                       | 是   | 否   | 模块支持的模式。       |
| reqCapabilities                   | Array\<string>                                               | 是   | 否   | 模块运行需要的能力。   |
| deviceTypes                       | Array\<string>                                               | 是   | 否   | 支持运行的设备类型。   |
| abilityInfo                       | Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>         | 是   | 否   | Ability信息。          |
| moduleName                        | string                                                       | 是   | 否   | 模块名。               |
| mainAbilityName                   | string                                                       | 是   | 否   | 入口Ability名称。      |
| installationFree                  | boolean                                                      | 是   | 否   | 是否支持免安装，取值为true表示支持免安装，取值为false表示不支持免安装。       |

