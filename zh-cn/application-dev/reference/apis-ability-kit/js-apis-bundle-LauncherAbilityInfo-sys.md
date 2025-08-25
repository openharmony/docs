# LauncherAbilityInfo (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

LauncherAbilityInfo信息，通过接口[innerBundleManager.getLauncherAbilityInfos](js-apis-Bundle-InnerBundleManager-sys.md#innerbundlemanagergetlauncherabilityinfosdeprecated)获取。

> **说明：**
>
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
>从API Version 9开始，该模块不再维护，建议使用[bundleManager-LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)替代。
>
> 本模块为系统接口。

## LauncherAbilityInfo<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[bundleManager-LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)替代。

**系统能力：** SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

| 名称            | 类型                                                 | 只读 | 可选 | 说明                                   |
| --------------- | ---------------------------------------------------- | ---- | ---- | -------------------------------------- |
| applicationInfo | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md) | 是   | 否   | launcher ability的应用程序的配置信息。 |
| elementName     | [ElementName](js-apis-bundle-ElementName.md)         | 是   | 否   | launcher ability的ElementName信息。    |
| labelId         | number                                               | 是   | 否   | launcher ability的标签的资源ID值。             |
| iconId          | number                                               | 是   | 否   | launcher ability的图标的资源ID值。             |
| userId          | number                                               | 是   | 否   | launcher ability的用户ID。             |
| installTime     | number                                               | 是   | 否   | launcher ability的安装时间戳，单位毫秒。        |