# LauncherAbilityInfo (系统接口)

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
桌面应用的Ability信息，可以通过[bundleManager.getLauncherAbilityInfo](js-apis-launcherBundleManager-sys.md#launcherbundlemanagergetlauncherabilityinfo9)获取。
>
> 本模块为系统接口。

## LauncherAbilityInfo

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher。

 **系统接口：** 此接口为系统接口。

| 名称            | 类型                                                        | 只读 | 可选 | 说明                                 |
| --------------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------ |
| applicationInfo | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | 是   | 否   | launcher ability的应用程序的配置信息。 |
| elementName     | [ElementName](js-apis-bundleManager-elementName.md)         | 是   | 否   | launcher ability的ElementName信息。    |
| labelId         | number                                                      | 是   | 否   | launcher ability的标签ID。             |
| iconId          | number                                                      | 是   | 否   | launcher ability的图标ID。             |
| userId          | number                                                      | 是   | 否   | launcher ability的用户ID。             |
| installTime     | number                                                      | 是   | 否   | launcher ability的安装时间。           |