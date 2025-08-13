# 应用/组件级配置

在开发应用时，需要配置应用的一些标签，例如应用的包名、图标等标识特征的属性。本文描述了在开发应用需要配置的一些关键标签。

## 应用包名配置

应用需要在工程的AppScope目录下的[app.json5配置文件](../quick-start/app-configuration-file.md)中配置bundleName标签，该标签用于标识应用的唯一性。推荐采用反域名形式命名（如com.example.demo，建议第一级为域名后缀com，第二级为厂商/个人名，第三级为应用名，也可以多级）。

## 应用图标和名称配置

应用图标和名称配置通常一起配置，对应[app.json5配置文件](../quick-start/app-configuration-file.md)和[module.json5配置文件](../quick-start/module-configuration-file.md)中的icon和label。在DevEco Studio 5.0.3.800版本及之后，module.json5配置文件中的icon和label不再强制要求配置，而app.json5配置文件中的icon和label仍然是必选参数。因此，module.json5配置文件中的icon和label可以省略。app.json5配置文件和module.json5配置文件中的icon和label存在优先级和生效策略，详情参考[配置优先级和生成策略](../quick-start/layered-image.md#配置优先级和生成策略)。

## 应用版本声明配置

应用版本声明需要在工程的AppScope目录下的[app.json5配置文件](../quick-start/app-configuration-file.md)中配置versionCode标签和versionName标签。versionCode用于标识应用的版本号，该标签值为32位非负整数。此数字仅用于确定某个版本是否比另一个版本更新，数值越大表示版本越高。versionName标签标识版本号的文字描述。

## Module支持的设备类型配置

Module支持的设备类型需要在[module.json5配置文件](../quick-start/module-configuration-file.md)中配置[deviceTypes标签](../quick-start/module-configuration-file.md#devicetypes标签)，如果deviceTypes标签中添加了某种设备，则表明当前的Module支持在该设备上运行。

## Module权限配置

Module访问系统或其他应用受保护部分所需的权限信息需要在[module.json5配置文件](../quick-start/module-configuration-file.md)中配置[requestPermissions标签](../security/AccessToken/declare-permissions.md)。该标签用于声明需要申请权限的名称、申请权限的原因以及权限使用的场景。

## 应用启动模式配置

从API version 20开始，支持应用配置startMode字段以自定义点击图标启动的模式，且仅在launchType为[单实例模式](./uiability-launch-type.md#singleton启动模式)时生效，用于一个应用存在多个UIAbility的场景。需要在[app.json5配置文件](../quick-start/app-configuration-file.md#配置文件标签)中配置startMode标签。

- 默认值为"mainTask"，表现为点击图标总是启动应用主UIAbility。
- 可选值"recentTask"，表现为点击图标打开最近使用的UIAbility。

```json
{
  ...
  "app": {
    "startMode": "mainTask"
    ...
  }
}
```
