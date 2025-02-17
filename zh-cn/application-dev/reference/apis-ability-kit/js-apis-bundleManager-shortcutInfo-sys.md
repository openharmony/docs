# ShortcutInfo (系统接口)

应用配置文件中定义的快捷方式信息，可以通过[getShortcutInfo](js-apis-launcherBundleManager-sys.md#launcherbundlemanagergetshortcutinfo9)获取。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> FA模型配置在[config.json文件中进行配置](../../quick-start/module-structure.md#shortcuts对象的内部结构)，Stage模型配置参考[shortcuts对象内部结构](../../quick-start/module-configuration-file.md#shortcuts标签)。
>
> 本模块为系统接口。

## ShortcutWant

**系统能力:** SystemCapability.BundleManager.BundleFramework.Launcher

**系统接口：**  此接口为系统接口。

| 名称                      | 类型   | 只读 | 可选 | 说明                 |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| targetBundle              | string | 是   | 否   | 快捷方式的目标bundleName。 |
| targetModule              | string | 是   | 是  | 快捷方式的目标moduleName。  |
| targetAbility             | string | 是   | 否  | 快捷方式所需的目标abilityName。 |
| parameters<sup>12+</sup>  | Array\<[ParameterItem](#parameteritem12)> | 否   | 是  | 快捷方式配置信息中的自定义数据。 |

## ShortcutInfo

**系统能力:**  SystemCapability.BundleManager.BundleFramework.Launcher

**系统接口：**  此接口为系统接口。

| 名称                    | 类型                                       | 只读 | 可选 | 说明                         |
| ----------------------- | ------------------------------------------ | ---- | ---- | ---------------------------- |
| id                      | string                                     | 是   | 否 | 快捷方式所属应用程序的ID。  |
| bundleName              | string                                     | 是   | 否  | 包含快捷方式的Bundle名称。 |
| moduleName | string                                     | 是   | 是  | 快捷方式的模块名。            |
| hostAbility             | string                                     | 是   | 是  | 快捷方式的本地Ability名称。   |
| icon                    | string                                     | 是   | 是  | 快捷方式的图标。             |
| iconId     | number                                     | 是   | 是  | 快捷方式的图标ID。           |
| label                   | string                                     | 是   | 是  | 快捷方式的标签。              |
| labelId    | number                                     | 是   | 是  | 快捷方式的标签ID。           |
| wants                   | Array\<[ShortcutWant](#shortcutwant)> | 是   | 是  | 快捷方式所需要的信息。        |
| appIndex<sup>12+</sup> | number | 否 | 否 | 应用程序分身的索引。 |
| sourceType<sup>12+</sup> | number | 否 | 否 | 快捷方式来源类型，0：自定义快捷方式；1：静态快捷方式。 |

## ParameterItem<sup>12+</sup>

描述快捷方式配置信息中的自定义数据。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Launcher

| 名称          | 类型    | 只读 | 可选 | 说明                   |
| ------------- | ------ | ---- | ---------------------- | ---------------------- |
| key           | string | 否   | 否   | 描述快捷方式配置信息中的自定义数据的键。       |
| value         | string | 否   | 否   | 描述快捷方式配置信息中的自定义数据的值。 |

<!--no_check-->