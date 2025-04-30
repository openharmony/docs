# shortcutInfo (系统接口)

应用配置文件中定义的快捷方式信息，FA模型配置在[config.json](../../quick-start/application-configuration-file-overview-fa.md)文件中进行配置，Stage模型在开发视图的resources/base/profile下面定义配置文件即可。

> **说明：**
>
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 从API Version 9开始，该模块不再维护，建议使用[bundleManager-ShortcutWant](js-apis-bundleManager-shortcutInfo-sys.md)替代。
> 
> 本模块为系统接口。

## ShortcutWant<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[bundleManager-ShortcutWant](js-apis-bundleManager-shortcutInfo-sys.md#shortcutwant)替代。

 **系统能力:** SystemCapability.BundleManager.BundleFramework

 **系统接口：** 此接口为系统接口，三方应用不支持调用。

| 名称                      | 类型   | 只读 | 可选 | 说明                 |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| targetBundle              | string | 是   | 否   | 快捷方式的目标捆绑包。 |
| targetClass               | string | 是   | 否   | 快捷方式所需的目标类。 |
