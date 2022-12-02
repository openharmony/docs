# 应用/组件级配置


开发者在开发应用时，需要配置应用的一些标签，例如应用的包名、图标等标识特征的属性。这一章节描述了开发者在开发应用时需要配置的一些关键标签。


- **应用包名配置**
  应用包名需在config.json文件中app标签下配置bundleName字段，该字段用于指定应用的包名，需保证唯一性。包名是由字母、数字、下划线（_）和点号（.）组成的字符串，必须以字母开头。支持的字符串长度为7~127字节。包名通常采用反向域名形式表示（例如，"com.example.myapplication"）。建议第一级为域名后缀"com"，第二级为厂商/个人名，也可以采用多级。应用名称配置可以参考[app标签说明](../quick-start/app-structure.md)。

- **应用图标和标签配置**
  FA模型不支持直接配置应用图标和标签，会以符合规则的PageAbility的图标和标签作为应用图标和标签。PageAbility的图标和标签配置请参见[PageAbility组件配置](pageability-configuration.md)。需在config.json文件的abilities标签下配置icon字段，标签值为资源文件的索引。图标需要在配置IDE的资源文件中，路径为/resource/base/media。取值示例：$media:ability_icon。标签值为资源文件的索引，标识Ability对用户显示的名称。取值可以是Ability名称，也可以是对该名称的资源索引，以支持多语言。如果在该Ability的skills属性中，actions的取值包含 "action.system.home"，entities取值中包含"entity.system.home"，则该Ability的icon和label将同时作为应用的icon和label。如果存在多个符合条件的Ability，则取位置靠前的Ability的icon和label作为应用的icon和label。应用图标和标签配置可以参考[ablities标签说明](../quick-start/module-structure.md)。

  
  ```json
  "abilities": [
    "icon": "$media:icon",
    "label": "$string:MainAbility_label",
    "skills": [  
      {
        "entities": ["entity.system.home"],
        "actions": ["action.system.home"]
      }
    ]
    // ...
  }
  ```

- **应用版本声明配置**
  应用版本声明配置需在config.json中的app标签下配置version字段，以说明应用当前的版本号和版本名称以及应用能够兼容的最低历史版本号。应用版本配置说明可以参考[version标签说明](../quick-start/module-structure.md)。

- **Module支持的设备类型配置**
  Module支持的设备类型需要在config.json文件中配置deviceType字段，如果deviceType标签中添加了某种设备，则表明当前的module支持在改设备上运行。具体的deviceType配置规则可以参考[deviceType标签说明](../quick-start/module-structure.md)。

- **组件权限申请配置**
  组件权限申请配置需在confog.json中的module标签下配置reqPermission字段。来声明需要申请权限的名称，申请权限的原因以及权限使用的场景。组件权限申请可以参考[reqPermission标签说明](../quick-start/module-structure.md)。
