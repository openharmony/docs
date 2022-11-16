# AbilityInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



Ability信息，未做特殊说明的属性，均通过GET_BUNDLE_DEFAULT获取

## AbilityInfo<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[AbilityInfo](js-apis-bundleManager-abilityInfo.md)替代。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                  | 类型                                                     | 可读 | 可写 | 说明                                      |
| --------------------- | -------------------------------------------------------- | ---- | ---- | ----------------------------------------- |
| bundleName            | string                                                   | 是   | 否   | 应用包名                                  |
| name                  | string                                                   | 是   | 否   | Ability名称                               |
| label                 | string                                                   | 是   | 否   | Ability对用户显示的名称                   |
| description           | string                                                   | 是   | 否   | Ability的描述                             |
| icon                  | string                                                   | 是   | 否   | Ability的图标资源文件索引                 |
| descriptionId         | number                                                   | 是   | 否   | Ability的描述id                           |
| iconId                | number                                                   | 是   | 否   | Ability的图标id                           |
| moduleName            | string                                                   | 是   | 否   | Ability所属的HAP包的名称                  |
| process               | string                                                   | 是   | 否   | Ability的进程，如果不设置，默认为包的名称 |
| targetAbility         | string                                                   | 是   | 否   | 当前Ability重用的目标Ability<br />此属性仅可在FA模型下使用 |
| backgroundModes       | number                                                   | 是   | 否   | 表示后台服务的类型<br />此属性仅可在FA模型下使用     |
| isVisible             | boolean                                                  | 是   | 否   | 判断Ability是否可以被其他应用调用         |
| formEnabled           | boolean                                                  | 是   | 否   | 判断Ability是否提供卡片能力<br />此属性仅可在FA模型下使用 |
| type                  | AbilityType                                              | 是   | 否   | Ability类型<br />此属性仅可在FA模型下使用  |
| orientation           | [DisplayOrientation](js-apis-Bundle.md#deprecatedisplayorientation)                                       | 是   | 否   | Ability的显示模式                         |
| launchMode            | [LaunchMode](js-apis-Bundle.md#launchmode)                                               | 是   | 否   | Ability的启动模式                         |
| permissions           | Array\<string>                                           | 是   | 否   | 被其他应用Ability调用时需要申请的权限集合<br />通过传入GET_ABILITY_INFO_WITH_PERMISSION获取 |
| deviceTypes           | Array\<string>                                           | 是   | 否   | Ability支持的设备类型                     |
| deviceCapabilities    | Array\<string>                                           | 是   | 否   | Ability需要的设备能力                     |
| readPermission        | string                                                   | 是   | 否   | 读取Ability数据所需的权限<br />此属性仅可在FA模型下使用 |
| writePermission       | string                                                   | 是   | 否   | 向Ability写数据所需的权限<br />此属性仅可在FA模型下使用 |
| applicationInfo       | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md)     | 是   | 否   | 应用程序的配置信息<br />通过传入GET_ABILITY_INFO_WITH_APPLICATION获取 |
| uri                   | string                                                   | 是   | 否   | 获取Ability的统一资源标识符（URI）<br />此属性仅可在FA模型下使用 |
| labelId               | number                                                   | 是   | 否   | Ability的标签id                           |
| subType               | AbilitySubType                                           | 是   | 否   | Ability中枚举使用的模板的子类型<br />此属性仅可在FA模型下使用 |
| metadata<sup>8+</sup> | Array\<[CustomizeData](js-apis-bundle-CustomizeData.md)>           | 是   | 否   | ability的元信息<br />通过传入GET_ABILITY_INFO_WITH_METADATA获取 |
| enabled<sup>8+</sup>  | boolean                                                  | 是   | 否   | ability是否可用                           |