# AbilityInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 
> API9 当前为Canary版本，仅供试用，不保证接口可稳定调用。

Ability信息

## AbilityInfo

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
| targetAbility         | string                                                   | 是   | 否   | 当前Ability重用的目标Ability              |
| backgroundModes       | number                                                   | 是   | 否   | 表示后台服务的类型                        |
| isVisible             | boolean                                                  | 是   | 否   | 判断Ability是否可以被其他应用调用         |
| formEnabled           | boolean                                                  | 是   | 否   | 判断Ability是否提供卡片能力               |
| type                  | AbilityType                                              | 是   | 否   | Ability类型                               |
| orientation           | DisplayOrientation                                       | 是   | 否   | Ability的显示模式                         |
| launchMode            | LaunchMode                                               | 是   | 否   | Ability的启动模式                         |
| permissions           | Array\<string>                                           | 是   | 否   | 被其他应用Ability调用时需要申请的权限集合 |
| deviceTypes           | Array\<string>                                           | 是   | 否   | Ability支持的设备类型                     |
| deviceCapabilities    | Array\<string>                                           | 是   | 否   | Ability需要的设备能力                     |
| readPermission        | string                                                   | 是   | 否   | 读取Ability数据所需的权限                 |
| writePermission       | string                                                   | 是   | 否   | 向Ability写数据所需的权限                 |
| applicationInfo       | ApplicationInfo                                          | 是   | 否   | 应用程序的配置信息                        |
| uri                   | string                                                   | 是   | 否   | 获取Ability的统一资源标识符（URI）        |
| labelId               | number                                                   | 是   | 否   | Ability的标签id                           |
| subType               | AbilitySubType                                           | 是   | 否   | Ability中枚举使用的模板的子类型           |
| metaData<sup>8+</sup> | Array\<[CustomizeData](js-apis-bundle-CustomizeData.md)> | 是   | 否   | ability的自定义信息                       |
| metadata<sup>9+</sup> | Array\<[Metadata](js-apis-bundle-Metadata.md)>           | 是   | 否   | ability的元信息                           |
| enabled<sup>8+</sup>  | boolean                                                  | 是   | 否   | ability是否可用                           |