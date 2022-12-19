# ShortcutInfo

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

本应用配置文件中定义的快捷方式信息，可以通过[getShortcutInfo](js-apis-launcherBundleManager.md#launcherbundlemanagergetshortcutinfo9)获取，FA模型配置在[config.json文件中进行配置](../../quick-start/module-structure.md#%E8%A1%A817-shortcuts%E5%AF%B9%E8%B1%A1%E7%9A%84%E5%86%85%E9%83%A8%E7%BB%93%E6%9E%84%E8%AF%B4%E6%98%8E)，Stage模型配置参考[shortcuts对象内部结构](../../quick-start/module-configuration-file.md#shortcuts标签)。

## ShortcutWant

**系统能力:** SystemCapability.BundleManager.BundleFramework.Launcher

**系统接口：**  此接口为系统接口。

| 名称                      | 类型   | 可读 | 可写 | 说明                 |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| targetBundle              | string | 是   | 否   | 快捷方式的目标bundleName |
| targetModule              | string | 是   | 否   | 快捷方式的目标moduleName   |
| targetAbility             | string | 是   | 否   | 快捷方式所需的目标abilityName |

## ShortcutInfo

**系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher

 **系统接口：**  此接口为系统接口。

| 名称                    | 类型                                       | 可读 | 可写 | 说明                         |
| ----------------------- | ------------------------------------------ | ---- | ---- | ---------------------------- |
| id                      | string                                     | 是   | 否   | 快捷方式所属应用程序的Id     |
| bundleName              | string                                     | 是   | 否   | 包含快捷方式的包名称         |
| moduleName | string                                     | 是   | 否   | 快捷方式的模块名             |
| hostAbility             | string                                     | 是   | 否   | 快捷方式的本地Ability名称    |
| icon                    | string                                     | 是   | 否   | 快捷方式的图标               |
| iconId     | number                                     | 是   | 否   | 快捷方式的图标Id             |
| label                   | string                                     | 是   | 否   | 快捷方式的标签               |
| labelId    | number                                     | 是   | 否   | 快捷方式的标签Id             |
| wants                   | Array\<[ShortcutWant](#shortcutwant)> | 是   | 否   | 快捷方式所需要的信息         |

<!--no_check-->