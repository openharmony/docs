# 应用/组件级配置

在开发应用时，需要配置应用的一些标签，例如应用的包名、图标等标识特征的属性。本文描述了在开发应用需要配置的一些关键标签。

## 应用包名配置

应用需要在工程的AppScope目录下的[app.json5配置文件](../quick-start/app-configuration-file.md)中配置bundleName标签，该标签用于标识应用的唯一性。推荐采用反域名形式命名（如com.example.demo，建议第一级为域名后缀com，第二级为厂商/个人名，第三级为应用名，也可以多级）。

## 图标和标签配置
图标和标签通常一起配置，对应[app.json5配置文件](../quick-start/app-configuration-file.md)和[module.json5配置文件](../quick-start/module-configuration-file.md)中的icon和label。在DevEco Studio 5.0.3.800版本及之后，[module.json5配置文件](../quick-start/module-configuration-file.md)中的icon和label不再强制要求配置，而[app.json5配置文件](../quick-start/app-configuration-file.md)中的icon和label仍然是必选参数。因此，[module.json5配置文件](../quick-start/module-configuration-file.md)中的icon和label可以省略。

### 生成机制
* HAP中包含UIAbility

  * 如果在module.json5配置文件的abilities标签中配置了icon和label，且该对应的ability中skills标签下面的entities中包含"entity.system.home"、actions中包含"ohos.want.action.home"或者"action.system.home"，则系统将优先返回module.json5中的icon与label。如果存在多个满足条件的ability，优先返回module.json5中mainElement对应的ability配置的icon和label。

  * 如果在module.json5配置文件的abilities标签中未设置icon和label，系统将返回app.json5中的icon和label。

* HAP中不包含UIAbility，系统将返回app.json5中的icon和label。


### 应用场景
<!--RP1-->
- 用于在应用界面内展示当前应用。例如：在设置应用中展示应用列表，在设置的隐私管理中展示应用申请的权限。
- 用于在设备桌面上展示当前应用。例如：桌面或者最近任务列表中显示应用。
<!--RP1End-->

效果图如下：
<!--RP2-->
![application-component-configuration-stage-app-module](figures/application-component-configuration-stage-app-module.png)
<!--RP2End-->

### 配置示例

- **方式一：配置app.json5（推荐）**

  ```json
  {
    "app": {
      "icon": "$media:app_icon",
      "label": "$string:app_name"
      // ...
    }
  }
  ```

- **方式二：配置module.json5**

  如果需要在桌面显示UIAbility图标，除了需要配置icon与label字段，还需要在skills标签下面的entities中添加"entity.system.home"、actions中添加"ohos.want.action.home"。

  ```json
  {
    "module": {
      // ...
      "abilities": [
        {
          "icon": "$media:icon",
          "label": "$string:EntryAbility_label",
          "skills": [
            {
              "entities": [
                "entity.system.home"
              ],
              "actions": [
                "ohos.want.action.home"
              ]
            }
          ],
        }
      ]
    }
  }
  ```
### 管控规则
系统对无图标应用实施严格管控，防止一些恶意应用故意配置无桌面应用图标，导致用户找不到软件所在的位置，无法操作卸载应用，在一定程度上保证用户终端设备的安全。

如果预置应用确需隐藏桌面应用图标，需要配置AllowAppDesktopIconHide应用特权<!--Del-->，具体配置方式参考[应用特权配置指南](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)<!--DelEnd-->。申请该特权后，应用不会在桌面上显示。除预置应用外，其他应用不支持隐藏桌面图标。


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
