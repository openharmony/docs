# 应用/组件级配置
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->


开发者在开发应用时，需要配置应用的一些标签，例如应用的Bundle名称、图标等标识特征的属性。这一章节描述了开发者在开发应用时需要配置的一些关键标签。


## 应用包名配置

应用包名需在config.json文件中app标签下配置bundleName字段，该字段用于指定应用的包名，需保证唯一性。包名是由字母、数字、下划线（_）和点号（.）组成的字符串，必须以字母开头。支持的字符串长度为7~127字节。包名通常采用反向域名形式表示（例如，"com.example.myapplication"）。建议第一级为域名后缀"com"，第二级为厂商/个人名，也可以采用多级。应用名称配置可以参考[app标签说明](../quick-start/app-structure.md)。

## 图标和标签配置

图标和标签通常一起配置，可以分为应用图标、应用标签和入口图标、入口标签。

应用图标和标签通常用于标识整个应用，可以在标识应用的界面使用该类型图标和标签。比如：
* 设置应用中，需要展示应用列表时
* 在隐私管理中，需要展示应用申请的权限时
* 在状态栏显示通知消息时


入口图标和标签是应用安装完成后可以在设备桌面上显示出来的。入口图标是以Page类型的Ability为粒度，支持同一个应用存在一个入口图标和入口标签（存在多个入口Ability时，仅entry类型HAP中的mainAbility会生效），点击后进入对应的Ability界面。比如：
* 桌面上需要显示图标时
* 最近任务列表中显示时

### 应用图标和标签配置
FA模型不支持直接配置应用图标和标签，会以符合规则的PageAbility的图标和标签作为应用图标和标签。存在多个时，则取位置靠前的Ability的icon和label作为应用的icon和label。

### 入口图标和标签配置
#### 入口图标和标签配置方法
FA模型的入口图标和标签是Page类型的Ability配置的icon和label。

PageAbility的图标和标签配置请参见[PageAbility组件配置](pageability-configuration.md)。需在config.json文件的abilities标签下做如下配置：
* 配置icon字段，标签值为资源文件的索引。图标需要在配置DevEco Studio的资源文件中，路径为/resource/base/media。取值示例：$media:ability_icon。
* 配置label字段，标签值为资源文件的索引，标识Ability对用户显示的名称。取值可以是Ability名称，也可以是对该名称的资源索引，以支持多语言。

如果在该PageAbility的skills属性中，actions的取值包含 "action.system.home"，entities取值中包含"entity.system.home"，则该Ability的icon和label将同时作为应用的icon和label。如果存在多个符合条件的Ability，则取位置靠前的Ability的icon和label作为应用的icon和label。图标和标签配置可以参考[abilities标签说明](../quick-start/module-structure.md)。

```json
{
  ...
  "module": {
    ...
    "abilities": [
      {
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ],
        "orientation": "unspecified",
        "formsEnabled": false,
        "name": ".MainAbility",
        "srcLanguage": "ets",
        "srcPath": "MainAbility",
        "icon": "$media:icon",
        "description": "$string:MainAbility_desc",
        "label": "$string:MainAbility_label",
        "type": "page",
        "visible": true,
        "launchType": "singleton"
      },
      ...
    ]
    ...
  }
}
```
#### 入口图标和标签管控规则
系统对无图标应用实施严格管控，防止一些恶意应用故意配置无入口图标，导致用户找不到软件所在的位置，无法操作卸载应用，在一定程度上保证用户终端设备的安全。

如果应用确需隐藏入口图标，需要配置AllowAppDesktopIconHide应用特权<!--Del-->，具体配置方式参考[应用特权配置指南](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)<!--DelEnd-->。详细的入口图标及入口标签的显示规则如下。

* HAP中包含PageAbility
  * 在config.json配置文件的abilities标签中设置了入口图标
    * 该应用没有隐藏图标的特权
      * 系统将使用该PageAbility配置的icon作为入口图标，并显示在桌面上。用户点击该图标，页面跳转到该PageAbility首页。
      * 系统将使用该PageAbility配置的label作为入口标签，并显示在桌面上，如果没有配置label，系统将使用应用的bundleName作为入口标签，并显示在桌面上。
    * 该应用具有隐藏图标的特权
      * 桌面应用查询时不返回应用信息，不会在桌面上显示对应的入口图标和标签。
  * 在config.json配置文件的abilities标签中未设置入口图标
    * 该应用没有隐藏图标的特权
      * 系统将使用系统资源中的icon作为入口图标，并显示在桌面上。用户点击该图标，页面跳转到应用管理中对应的应用详情页面。
      * 系统将使用该PageAbility配置的label作为入口标签，并显示在桌面上，如果没有配置label，系统将使用应用的bundleName作为入口标签，并显示在桌面上。
    * 该应用具有隐藏图标的特权
        * 桌面应用查询时不返回应用信息，不会在桌面上显示对应的入口图标和标签。

* HAP中不包含PageAbility
  * 该应用没有隐藏图标的特权
    * 系统将使用系统资源中的icon作为入口图标，并显示在桌面上。用户点击该图标，页面跳转到应用管理中对应的应用详情页面。
    * 系统将使用应用的bundleName作为入口标签，并显示在桌面上。
  * 该应用具有隐藏图标的特权
    * 桌面应用查询时不返回应用信息，不会在桌面上显示对应的入口图标和标签。

## 应用版本声明配置

应用版本声明配置需在config.json中的app标签下配置version字段，以说明应用当前的版本号和版本名称以及应用能够兼容的最低历史版本号。应用版本配置说明可以参考[version对象内部结构](../quick-start/app-structure.md#version对象内部结构)。

## Module支持的设备类型配置

Module支持的设备类型需要在config.json文件中配置deviceType字段，如果deviceType标签中添加了某种设备，则表明当前的module支持在该设备上运行。具体的deviceType配置规则可以参考[deviceType标签](../quick-start/module-structure.md#devicetype标签)。

## 组件权限申请配置

组件权限申请配置需在config.json中的module标签下配置reqPermissions字段。来声明需要申请权限的名称，申请权限的原因以及权限使用的场景。组件权限申请可以参考[reqPermissions权限申请](../quick-start/module-structure.md#reqpermissions权限申请)。