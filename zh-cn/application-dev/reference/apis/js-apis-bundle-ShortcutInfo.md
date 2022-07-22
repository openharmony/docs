# ShortcutInfo



> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



配置文件中定义的权限详细信息



## ShortcutWant

获取有关快捷方式将启动的功能和目标的信息

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                      | 类型   | 可读 | 可写 | 说明                 |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| targetBundle              | string | 是   | 否   | 快捷方式的目标捆绑包 |
| targetModule<sup>9+</sup> | string | 是   | 否   | 快捷方式的目标模块   |
| targetClass               | string | 是   | 否   | 快捷方式所需的目标类 |

## ShortcutInfo

获取有关快捷方式将启动的功能和目标的信息

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                    | 类型                                       | 可读 | 可写 | 说明                         |
| ----------------------- | ------------------------------------------ | ---- | ---- | ---------------------------- |
| id                      | string                                     | 是   | 否   | 快捷方式所属应用程序的Id     |
| bundleName              | string                                     | 是   | 否   | 包含快捷方式的包名称         |
| hostAbility             | string                                     | 是   | 否   | 快捷方式的本地Ability信息    |
| icon                    | string                                     | 是   | 否   | 快捷方式的图标               |
| iconId<sup>8+</sup>     | number                                     | 是   | 否   | 快捷方式的图标Id             |
| label                   | string                                     | 是   | 否   | 快捷方式的标签               |
| labelId<sup>8+</sup>    | number                                     | 是   | 否   | 快捷方式的标签Id             |
| disableMessage          | string                                     | 是   | 否   | 快捷方式的禁用消息           |
| wants                   | Array&lt;[ShortcutWant](#shortcutwant)&gt; | 是   | 否   | 快捷方式所需要的信息         |
| isStatic                | boolean                                    | 是   | 否   | 快捷方式是否为静态           |
| isHomeShortcut          | boolean                                    | 是   | 否   | 快捷方式是否为主页面快捷方式 |
| isEnabled               | boolean                                    | 是   | 否   | 是否启用快捷方式             |
| moduleName<sup>9+</sup> | string                                     | 是   | 否   | 快捷方式的模块名             |