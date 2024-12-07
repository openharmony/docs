# ShortcutInfo

应用配置文件中定义的快捷方式信息，FA模型配置在[config.json](../../quick-start/application-configuration-file-overview-fa.md)文件中进行配置，Stage模型在开发视图的resources/base/profile下面定义配置文件即可。

> **说明：**
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ShortcutInfo<sup>(deprecated)<sup>

**系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                    | 类型                                       | 只读 | 可选 | 说明                         |
| ----------------------- | ------------------------------------------ | ---- | ---- | ---------------------------- |
| id                      | string                                     | 是   | 否   | 快捷方式所属应用程序的Id。     |
| bundleName              | string                                     | 是   | 否   | 包含该快捷方式的Bundle名称。 |
| hostAbility             | string                                     | 是   | 否   | 快捷方式的本地Ability信息。    |
| icon                    | string                                     | 是   | 否   | 快捷方式的图标。               |
| iconId<sup>8+</sup>     | number                                     | 是   | 否   | 快捷方式的图标Id。             |
| label                   | string                                     | 是   | 否   | 快捷方式的名称。               |
| labelId<sup>8+</sup>    | number                                     | 是   | 否   | 快捷方式的名称Id。             |
| disableMessage          | string                                     | 是   | 否   | 快捷方式的禁用消息。           |
| wants                   | Array&lt;<!--Del-->[<!--DelEnd-->ShortcutWant<!--Del-->](js-apis-bundle-ShortcutInfo-sys.md#shortcutwantdeprecated)<!--DelEnd-->&gt; | 是   | 否   | 快捷方式意图列表。         |
| isStatic                | boolean                                    | 是   | 是   | 快捷方式是否为静态。           |
| isHomeShortcut          | boolean                                    | 是   | 是   | 快捷方式是否为主页面快捷方式。 |
| isEnabled               | boolean                                    | 是   | 是   | 是否启用快捷方式。             |