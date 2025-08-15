# ShortcutInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

应用[module.json5配置文件](../../quick-start/module-configuration-file.md#shortcuts标签)中定义的快捷方式信息，可以通过[getAllShortcutInfoForSelf接口](js-apis-shortcutManager.md#shortcutmanagergetallshortcutinfoforself)<!--Del-->或[getShortcutInfo接口](js-apis-launcherBundleManager-sys.md#launcherbundlemanagergetshortcutinfo9)<!--DelEnd-->获取。

> **说明：**
>
> 本模块首批接口从API version 20 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { shortcutManager } from '@kit.AbilityKit';
```

## ShortcutWant

快捷方式内定义的目标[wants](../../quick-start/module-configuration-file.md#wants标签)信息集合。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

| 名称               | 类型                                    | 只读 | 可选 | 说明                 |
| ------------------| --------------------------------------- | --- | --- | -------------------- |
| targetBundle      | string                                  | 否   | 否  | 快捷方式的目标包名。 |
| targetModule      | string                                  | 否   | 是  | 快捷方式的目标模块名。 |
| targetAbility     | string                                  | 否   | 否  | 快捷方式的目标组件名。 |
| parameters        | Array\<[ParameterItem](#parameteritem)> | 否   | 是  | 拉起快捷方式时的自定义数据，仅支持配置字符串类型的数据。其中键值均最大支持1024长度的字符串。 |

## ShortcutInfo

快捷方式的配置信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

| 名称                | 类型                                       | 只读 | 可选 | 说明                         |
| ------------------- | ----------------------------------------- | --- | --- | ---------------------------- |
| id                  | string                                    | 否  | 否  | 快捷方式的ID。 |
| bundleName          | string                                    | 否  | 否  | 快捷方式所属应用的包名。 |
| moduleName          | string                                    | 否  | 是  | 快捷方式的模块名。 |
| hostAbility         | string                                    | 否  | 是  | 快捷方式的宿主组件名, 即承载此快捷方式的组件名。 |
| icon                | string                                    | 否  | 是  | 快捷方式的图标，取值为资源文件的索引。 |
| iconId              | number                                    | 否  | 是  | 快捷方式图标的资源ID。 |
| label               | string                                    | 否  | 是  | 快捷方式的标签信息，即快捷方式对外显示的文字描述信息。可以是描述性内容，也可以是标识label的资源索引。 |
| labelId             | number                                    | 否  | 是  | 快捷方式标签信息为资源索引时的资源ID。 |
| wants               | Array\<[ShortcutWant](#shortcutwant)>     | 否  | 是  | 快捷方式内定义的目标wants信息集合。 |
| appIndex            | number                                    | 否  | 否  | 快捷方式所属应用的分身索引。 |
| sourceType          | number                                    | 否  | 否  | 快捷方式来源类型，0：自定义快捷方式；1：静态快捷方式。 |
| visible             | boolean                                   | 否  | 是  | 快捷方式是否显示。true：快捷方式显示；false：快捷方式不显示。默认值为true。 |

## ParameterItem

快捷方式配置信息中的自定义数据。由开发者自行决定传入的键值对，可以通过key值获取对应的value值。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

| 名称          | 类型    | 只读 | 可选 | 说明                            |
| ------------- | ------ | ---- | ---- | ----------------------------- |
| key           | string | 否   | 否   | 快捷方式配置信息中的自定义数据的键。 |
| value         | string | 否   | 否   | 快捷方式配置信息中的自定义数据的值。 |