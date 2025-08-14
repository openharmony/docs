# 应用配置文件概述（FA模型）
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->


每个应用项目必须在项目的代码目录下加入配置文件，这些配置文件会向编译工具、操作系统和应用市场提供描述应用的基本信息。


应用配置文件需要声明以下内容：


- 应用的软件Bundle名称，应用的开发厂商，版本号等应用的基本配置信息，这些信息被要求设置在app这个字段下。

- 应用的组件的基本信息，包括所有的Ability，设备类型，组件的类型以及当前组件所使用的语法类型。

- 应用在具体设备上的配置信息，这些信息会影响应用在设备上的具体功能。


在FA模型的应用开发过程中，需要在config.json配置文件中对应用的包结构进行声明。


## 配置文件的内部结构

config.json由app、deviceConfig和module三个部分组成，缺一不可。

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| [app](app-structure.md) | 标识应用的全局配置信息。同一个应用的不同HAP的app配置必须保持一致。 | 对象 | 不可缺省。 |
| [deviceConfig](deviceconfig-structure.md) | 标识应用在具体设备上的配置信息。 | 对象 | 不可缺省。 |
| [module](module-structure.md) | 标识HAP的配置信息。该标签下的配置只对当前HAP生效。 | 对象 | 不可缺省。 |

config.json示例：


```json
{
  "app": {
    "vendor": "example",
    "bundleName": "com.example.demo",
    "version": {
      "code": 1000000,
      "name": "1.0.0"
    }
  },
  "deviceConfig": {
  },
  "module": {
    "mainAbility": ".MainAbility_entry",
    "deviceType": [
      "tablet"
    ],
    "commonEvents": [
      {
        "name": ".EntryAbility",
        "permission": "ohos.permission.GET_BUNDLE_INFO",
        "data": [
          "com.example.demo",
          "100"
        ],
        "events": [
          "install",
          "update"
        ]
      }
    ],
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
        "visible": true,
        "srcPath": "MainAbility_entry",
        "name": ".MainAbility_entry",
        "srcLanguage": "ets",
        "icon": "$media:icon",
        // $string:MainAbility_entry_desc为资源索引
        "description": "$string:MainAbility_entry_desc",
        "formsEnabled": false,
        // $string:MainAbility_entry_label为资源索引
        "label": "$string:MainAbility_entry_label",
        "type": "page",
        "launchType": "multiton"
      }
    ],
    "distro": {
      "moduleType": "entry",
      "installationFree": false,
      "deliveryWithInstall": true,
      "moduleName": "myapplication"
    },
    "package": "com.example.myapplication",
    "srcPath": "",
    "name": ".myapplication",
    "js": [
      {
        "mode": {
          "syntax": "ets",
          "type": "pageAbility"
        },
        "pages": [
          "pages/index"
        ],
        "name": ".MainAbility_entry",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": false
        }
      }
    ]
  }
}
```
