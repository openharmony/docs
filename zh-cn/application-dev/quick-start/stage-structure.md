

# 应用包结构配置文件的说明

在开发stage模型的应用程序时，需要在app.json5和module.json5配置文件中对应用的包结构进行声明。

## 配置文件内部结构

配置文件由app.json5和module.json5两部分组成。配置文件的内部结构参见表1。

表1 配置文件的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省 |
| -------- | ------------------------------------------------------------ | -------- | ---------- |
| app      | 标识应用的全局配置信息。参考[app对象内部结构](#app对象内部结构)。 | 对象     | 不可缺省。         |
| module   | 标识HAP包的配置信息。该标签下的配置只对当前HAP包生效。参考[module对象内部结构](#module对象内部结构)。 | 对象     | 不可缺省。         |

### app对象内部结构

该标签为整个应用的属性，影响应用中所有HAP及组件。该标签的内部结构参见表2。

表2 app对象的内部结构说明

| 属性名称                       | 含义                                                         | 数据类型<div style="width:20px"> | 是否可缺省                                  |
| ------------------------------ | ------------------------------------------------------------ | -------- | ------------------------------------------- |
| bundleName                     | 该标签标识应用的包名，用于标识应用的唯一性。标签的值命名规则 :<br /> 1）字符串以字母、数字、下划线和符号”.”组成；<br /> 2）以字母开头；<br /> 3）最小长度7字节，最大长度127个字节。<br /> 推荐采用反域名形式命名（如 :com.example.xxx，建议第一级为域名后缀com，第二级为厂商/个人名，第三级为应用名，也可以多级）。 | 字符串   | 不可缺省。                                          |
| debug                          | 该标签标识应用是否可调试。该标签由IDE编译构建时产生。                                   | 布尔值   | 可缺省，缺省值为false。               |
| icon                           | 该标签标识应用的图标，标签值为图标资源文件的索引。               | 字符串   | 不可缺省。                            |
| label                          | 该标签标识应用的名称，标签值为字符串资源的索引。 | 字符串   | 不可缺省。                            |
| description                    | 该标签标识App的描述信息，标签值是是字符串类型或对描述内容的字符串资源索引。 | 字符串   | 可缺省，缺省值为空。                  |
| vendor                         | 该标签是对应用开发厂商的描述。最大长度255字节。 | 字符串   | 可缺省，缺省值为空。                  |
| versionCode                    | 该标签标识应用的版本号，该标签值为32位非负整数。此数字仅用于确定某个版本是否比另一个版本更新，数值越大表示版本越高。<br />开发者可以将该值设置为任何正整数，但是必须确保应用的新版本都使用比旧版本更大的值。versionCode 值应小于2的31次方。 | 数值     | 不可缺省。                              |
| versionName                    | 该标签标识版本号的文字描述，用于向用户展示。<br />该标签仅由数字和点构成，推荐采用“A.B.C.D”四段式的形式。四段式推荐的含义如下所示。<br/>第一段 :主版本号/Major，范围0-99，重大修改的版本，如实现新的大功能或重大变化。<br/>第二段 :次版本号/Minor，范围0-99，表示实现较突出的特点，如新功能添加和大问题修复。<br/>第三段 :特性版本号/Feature，范围0-99，标识规划的新版本特性。<br/>第四段 :修订版本号/Patch，范围0-999，表示维护版本，修复bug。 | 字符串   | 不可缺省。                              |
| minCompatibleVersionCode       | 该标签标识该app能够兼容的最低历史版本号，用于跨设备兼容性判断。    | 数值     | 可缺省。缺省值等于versionCode标签值。|
| minAPIVersion                  | 该标签标识应用运行需要的SDK的API最小版本。   | 数值     | 可缺省，缺省值为bundle-profile.json5中的compatibleSdkVersion。|
| targetAPIVersion               | 该标签标识应用运行需要的API目标版本。   | 数值     | 可缺省，缺省值为bundle-profile.json5中的compileSdkVersion。|
| apiReleaseType                 | 该标签标识应用运行需要的API目标版本的类型，采用字符串类型表示。取值为“CanaryN”、“BetaN”或者“Release”，其中，N代表大于零的整数。<br />Canary :受限发布的版本。<br/>Beta :公开发布的Beta版本。<br/>Release :公开发布的正式版本。<br/>该字段由IDE读取当前使用的SDK的stage来生成。 | 字符串   | 可缺省，由IDE生成并覆盖。             |
| distributedNotificationEnabled | 该标签标记该应用是否开启分布式通知。                         | 布尔值   | 可缺省，缺省值为true。                |
| entityType                     | 该标签标记该应用的类别，具体有 :游戏类(game)，影音类（media）、社交通信类（communication）、新闻类（news）、<br />出行类（travel）、工具类（utility）、购物类（shopping）、教育类（education）、少儿类（kids）、商务类（business）、拍摄类（photography）。 | 字符串   | 可缺省，缺省值为"unspecified"。         |
| multiProjects | 标识当前工程是否支持多工程。 | 布尔值 | 可缺省，缺省值为false。 |
| 设备类型                       | 该标签可以配置多个，表示具体设备上的特殊配置信息，具体的设备类型有："tablet"、"tv"、"wearable"、"car"、"default"，可包含的字段有：minAPIVersion、distributedNotificationEnabled。 | 对象     | 可缺省，缺省值使用app下面相关的字段。 |

app.json示例 ：

```json
{
  "app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "versionCode": 1000000,
    "versionName": "1.0.0",
    "icon": "$media:app_icon",
    "label": "$string:app_name",
    "distributedNotificationEnabled": true,
    "minCompatibleVersionCode": 9,
    "minAPIVersion": 9,
    "targetAPIVersion": 9,
    "apiReleaseType": "Canary1",
    "debug": false,
    "description": "$string:app_description",
    "entityType": "game",
    "car": {
      "minAPIVersion": 9
    }
  }
}

```

### module对象内部结构

HAP包的配置信息，该标签下的配置只对当前HAP包生效。

表3 module对象内部结构说明

| 属性名称             | 含义                                                         | 数据类型<div style="width:20px">  | 是否可缺省                                                   |
| -------------------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| name                 | 该标签标识当前module的名字。module打包成HAP后，表示HAP的名称，标签值采用字符串表示（最大长度31字节），该名称在整个应用要唯一。 | 字符串     | 不可缺省。                                             |
| type                 | 该标签标识当前module的类型。类型有两种，分别是entry、feature。 | 字符串     | 不可缺省。                                             |
| srcEntrance          | 该标签标识HAP所对应的入口js代码路径，标签值为字符串（最大长度127字节）。 | 字符串     | 可缺省，缺省值为空。                                               |
| description          | 该标签标识HAP包的描述信息，标签值是是字符串类型或对描述内容的字符串资源索引。 | 字符串     | 可缺省，缺省值为空。                                   |
| process              | 该标签标识HAP的进程名，标签值为字符串类型（最大长度31字节）。如果在HAP标签下配置了process，该应用的所有ability都运行在该进程中。该标签只支持系统应用配置。 | 字符串     | 可缺省，缺省值为app标签下的bundleName。                        |
| mainElement          | 该标签标识HAP的入口Ability名称或者Extension名称。只有配置为mainElement的Ability或者Extension才允许在服务中心露出。 | 字符串     | 创建OpenHarmony原子化服务时，不可缺省。OpenHarmony应用下，可缺省，缺省值为空。                            |
| deviceTypes          | 该标签标识HAP可以运行在哪类设备上，标签值采用字符串数组的表示，系统预定义的设备类型见表4。 | 字符串数组 | 不可缺省。                                 |
| deliveryWithInstall  | 该标签标识当前HAP是否在用户主动安装的时候安装，true表示主动安装时安装，false表示主动安装时不安装。 | 布尔值     | 不可缺省。                                             |
| installationFree     | 标识当前HAP是否支持免安装特性。所有Hap包都需要配置不可缺省。<br/>true :表示支持免安装特性，且符合免安装约束。<br/>false :表示不支持免安装特性。<br/><br/>当entry.hap该字段配置为true时，与该entry.hap相关的所有feature.hap该字段也需要配置为true。<br/>当entry.hap该字段配置为false时，与该entry.hap相关的各feature.hap该字段可按业务需求配置true或false。 | 布尔值     | 不可缺省。                                             |
| virtualMachine       | 该标签用于标识当前HAP运行的目标虚拟机类型，供云端分发使用，如应用市场和分发中心。<br/>该标签值为字符串。如果目标虚拟机类型为方舟虚拟机，则其值为"ark + 版本号"。 该标签由IDE构建HAP的时候自动插入。 | 字符串     | 该标签由IDE构建HAP的时候自动插入。                            |
| uiSyntax(deprecated) | syntax定义该JS Component的语法类型。<br />hml标识该JS Component使用hml/css/js进行开发；<br/>ets标识该JS Component使用ets声明式语法进行开发。 | 字符串     | 可缺省，缺省值为"hml"，该字段从API9开始废弃。            |
| pages                | 标识当前Module的profile资源，用于列举JS Component中每个页面信息。该标签最大长度为255个字节。 | 字符串       | 在有ability的场景下，不可缺省。                        |
| metadata             | 该标签标识Hap的自定义元信息。参考[metadata对象内部结构](#metadata对象内部结构)。 | 对象数组       | 可缺省，缺省值为空。                                   |
| abilities            | 描述元能力的配置信息，该标签下的配置只对当前ability生效。参考[abilities对象内部结构](#abilities对象内部结构)。 | 对象数组       | 可缺省，缺省值为空。                                   |
| extensionAbilities   | 描述extensionAbilities的配置信息，该标签下的配置只对当前extensionAbility生效。参考[extensionAbilities对象内部结构](#extensionabilities对象内部结构)。 | 对象数组       | 可缺省，缺省值为空。                                   |
| definePermissions    | 标识HAP定义的权限，仅支持系统应用配置，三方应用配置不生效。参考[definePermissions对象内部结构](#definepermissions对象内部结构)。 | 对象数组       | 可缺省，缺省值为空。 |
| requestPermissions   | 该标签标识应用运行时需向系统申请的权限集合。参考[requestPermissions对象内部结构](#requestpermissions对象内部结构)。 | 对象数组       | 可缺省，缺省值为空。                                   |
| testRunner           | 该标签用于支持对测试框架的配置，参考[testRunner对象内部结构说明](#testrunner对象内部结构)。 | 对象       | 可缺省，缺省值为空。                                           |


module.json5示例:

```json
{
  "module": {
    "name": "entry",
    "type": "entry",
    "description": "$string:module_desc",
    "mainElement": "EntryAbility",
    "deviceTypes": [
      "default",
      "tablet"
    ],
    "deliveryWithInstall": true,
    "installationFree": false,
    "pages": "$profile:main_pages",
    "metadata": [
      {
        "name": "name1",
        "value": "value1",
        "resource": "$profile:config_file1"
      },
      {
        "name": "name2",
        "value": "value2",
        "resource": "$profile:config_file2"
      }
    ],
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntrance": "./ets/entryability/EntryAbility.ts",
        "description": "$string:ability_desc",
        "icon": "$media:icon",
        "label": "$string:ability_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "visible": true,
        "backgroundModes": [
          "dataTransfer",
          "audioPlayback",
          "audioRecording",
          "location",
          "bluetoothInteraction",
          "multiDeviceConnection",
          "wifiInteraction",
          "voip",
          "taskKeeping"
        ],
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        "name": "permissionName",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "EntryFormAbility"
          ],
          "when": "inuse"
        }
      }
    ],
    "extensionAbilities": [
      {
        "name": "EntryFormAbility",
        "srcEntrance": "./ets/entryformability/EntryFormAbility.ts",
        "label": "$string:EntryFormAbility_label",
        "description": "$string:EntryFormAbility_desc",
        "type": "form",
        "metadata": [
          {
            "name": "ohos.extension.form",
            "resource": "$profile:form_config"
          }
        ]
      }
    ]
  }
}
```

pages示例 ：

1.在开发视图的resources/base/profile下面定义配置文件main_pages.json（文件名称可由开发者定义）：

```json
{
  "src": [
    "pages/LoginPage",
    "pages/MinePage",
    "pages/RegistrationSuccessPage",
    "pages/PrivacyPage",
    "pages/CustomerServicePage"
  ]
}
```

2.在module.json5的module标签下定义pages信息 ：

```json
{
  "module": {
    "pages": "$profile:main_pages"
  }
}
```

表4 deviceTypes对象的系统预定义设备

| 设备类型 | 枚举值   | 说明   |
| -------- | ----------- | -------- |
| 平板     | tablet   | -                                        |
| 智慧屏   | tv       | -                                        |
| 智能手表 | wearable | 系统能力较丰富的手表，具备电话功能。       |
| 车机     | car      | -                                        |
| 默认设备 | default  | 能够使用全部系统能力的OpenHarmony设备。   |

deviceTypes示例 ：

```json
{
  "module": {
    "deviceTypes": [
      "default",
      "tablet"
    ]
  }
}
```

#### metadata对象内部结构

描述的module、ability、extensionAbility配置信息，标签值为数组类型，该标签下的配置只对当前module、或者ability、或者extensionAbility生效。

表5 metadata对象内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省                 |
| -------- | ------------------------------------------------------------ | -------- | -------------------------- |
| name     | 该标签标识数据项的键名称，最大长度255字节。    | 字符串   | 可缺省，缺省值为空。 |
| value    | 该标签标识数据项的值，最大长度255字节。    | 字符串   | 可缺省，缺省值为空。         |
| resource | 该标签标识定义用户自定义数据格式，标签值为标识该数据的资源的索引值。 | 字符串   | 可缺省，缺省值为空。         |

metadata示例：

```json
{
  "module": {
    "metadata": [
      {
        "name": "name1",
        "value": "value1",
        "resource": "$profile:config_file1"
      },
      {
        "name": "name2",
        "value": "value2",
        "resource": "$profile:config_file2"
      }
    ]
  }
}
```

#### distroFilter对象内部结构

标识应用的分发规则。

该标签用于定义HAP包对应的细分设备规格的分发策略，以便在应用市场进行云端分发应用包时做精准匹配。该标签可配置的分发策略维度包括API Version、屏幕形状、窗口分辨率、屏幕分辨率、国家码。在进行分发时，通过deviceType与这五个属性的匹配关系，唯一确定一个用于分发到设备的HAP。<br/>
配置方式如下：<br/>
module标签配置metadata信息。name :"ohos.module.distro"。resource :指定distroFilter信息的资源位置。

表6  distroFilter对象内部结构

| 属性名称      | 含义                                                         | 数据类型 | 是否可缺省                 |
| ------------- | ------------------------------------------------------------ | -------- | -------------------------- |
| apiVersion    | 标识支持的apiVersion。                        | 对象 | 可缺省，缺省值为空。 |
| screenShape   | 标识屏幕形状的支持策略。仅支持liteWearable设备配置。                                    | 对象 | 可缺省，缺省值为空。 |
| screenWindow  | 标识应用运行时窗口的分辨率支持策略。仅支持liteWearable设备配置。 | 对象 | 可缺省，缺省值为空。 |
| screenDensity | 标识屏幕的像素密度（dpi : Dot Per Inch）。 | 对象 | 可缺省，缺省值为空。 |
| countryCode   | 标识应用需要分发的国家地区码。具体值以ISO-3166-1标准为准。 | 对象 | 可缺省，缺省值为空。 |

表7  apiVersion对象内部结构

| 属性名称 | 含义                                                         | 数据类型<div style="width:20px"> | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为"exclude"或"include"。"include"表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 支持的取值为API Version存在的整数值，例如4、5、6，最小取值为3。场景示例 :某应用，针对相同设备型号，同时在网的为使用API 5和API 6开发的两个软件版本，<br />则允许上架2个entry类型的安装包，分别支持到对应设备侧软件版本的分发。 | 数值数组     | 可缺省，缺省值为空。 |

表8 screenShape对象内部结构

| 属性名称 | 含义                                                         | 数据类型<div style="width:20px"> | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为"exclude"或"include"。"include"表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 支持的取值为circle（圆形屏幕）、rect（矩形屏幕）。场景示例:针对智能穿戴设备，可为圆形表盘和矩形表盘分别提供不同的HAP。 | 字符串数组     | 可缺省，缺省值为空。 |

表9 screenWindow对象内部结构

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为"include"。"include"表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 单个字符串的取值格式为 :“宽 * 高”，取值为整数像素值，例如“454 * 454”。 | 字符串数组     | 可缺省，缺省值为空。 |

表10  screenDensity对象内部结构

| 属性名称 | 含义                                                         | 数据类型<div style="width:20px"> | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为"exclude"或"include"。"include"表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 字符串范围如下：<br />sdpi :表示小规模的屏幕密度（Small-scale Dots per Inch），适用于dpi取值为（0,120]的设备。<br />mdpi :表示中规模的屏幕密度(Medium-scale Dots Per Inch)，适用于dpi取值为(120,160]的设备。<br />ldpi :表示大规模的屏幕密度(Large-scale Dots Per Inch)，适用于dpi取值为(160,240]的设备。<br /> xldpi :表示大规模的屏幕密度(Extra Large-scale Dots Per Inch)，适用于dpi取值为(240,320]的设备。<br />xxldpi :表示大规模的屏幕密度(Extra Extra  Large-scale Dots Per Inch)，适用于dpi取值为(320，480]的设备。<br />xxxldpi :表示大规模的屏幕密度(Extra Extra Extra   Large-scale Dots Per Inch)，适用于dpi取值为(480, 640]的设备。              | 字符串数组     | 可缺省，缺省值为空。 |

表11 countryCode对象内部结构

| 属性名称 | 含义                                                         | 数据类型<div style="width:20px"> | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为"exclude"或"include"。"include"表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 支持多个国家和地区枚举定义。字符串表示所支持的国家或地区，由两个大写字母组成。                         | 字符串数组     | 可缺省，缺省值为空。 |

distroFilter示例 :

1.在开发视图的resources/base/profile下面定义配置文件distro_filter_config.json（文件名称可由开发者定义）：

```json
{
  "distroFilter": {
    "apiVersion": {
      "policy": "include",
      "value": [
        4,
        5
      ]
    },
    "screenShape": {
      "policy": "include",
      "value": [
        "circle",
        "rect"
      ]
    },
    "screenWindow": {
      "policy": "include",
      "value": [
        "454*454",
        "466*466"
      ]
    },
    "screenDensity": {
      "policy": "exclude",
      "value": [
        "ldpi",
        "xldpi"
      ]
    },
    "countryCode": {
      "policy": "include",
      "value": [
        "CN",
        "HK"
      ]
    }
  }
}
```

2.在module.json5的module标签下配置metadata信息：

```json
{
  "module": {
    "metadata": [
      {
        "name": "ohos.module.distro",
        "resource": "$profile:distro_filter_config"
      }
    ]
  }
}
```

#### skills对象内部结构

该标签标识ability或者extension能够接收的意图的特征。

表12 skill对象内部结构说明

| 属性名称 | 含义                                                         | 数据类型<div style="width:20px">   | 是否可缺省           |
| -------- | ------------------------------------------------------------ | ---------- | -------------------- |
| actions  | 该标签标识能够接收的意图的action值的集合，取值通常为系统预定义的action值，也允许自定义。 | 字符串数组 | 可缺省，缺省值为空。 |
| entities | 该标签标识能够接收Want的元能力的类别集合，取值通常为系统预定义的类别，也允许自定义。 | 字符串数组 | 可缺省，缺省值为空。 |
| uris     | 该标签标识与意图中URI（Uniform Resource Identifier）相匹配的集合。uris内部结构参考表13。 | 对象数组   | 可缺省，缺省值为空。 |

表13 uris对象内部结构说明

| 属性名称 | 含义                | 数据类型<div style="width:20px"> | 是否可缺省           |
| -------- | ------------------- | -------- | -------------------- |
| scheme   | 标识URI的协议名部分，常见的有http、https、file、ftp等。 | 字符串   | 当配置type时可缺省，缺省值为空。没有配置type时不可缺省。           |
| host     | 标识URI的主机地址部分，常见的有域名的方式，如example.com，ip地址的方式，如192.0.0.1。该字段要在scheme存在时才有意义。   | 字符串   | 可缺省，缺省值为空。 |
| port     | 标识URI的端口部分。如http默认端口为80，https默认端口是443，ftp默认端口是21。该字段要在scheme和host都存在时才有意义。| 字符串   | 可缺省，缺省值为空。 |
| path \| pathStartWith \| <br />pathRegex   | 标识URI的路径部分，path、pathStartWith和pathRegex配置时三选一。path标识URI与want中的路径部分全匹配，<br />pathStartWith标识URI与want中的路径部分允许前缀匹配，pathRegex标识URI与want中的路径部分允许正则匹配。<br />该字段要在scheme和host都存在时才有意义。| 字符串   | 可缺省，缺省值为空。 |
| type     | 标识数据类型，使用MIME（Multipurpose Internet Mail Extensions）类型规范。可与scheme同时配置，也可以单独配置。| 字符串   | 可缺省，缺省值为空。 |

skills示例 ：

```json
{
  "module": {
    "abilities": [
      {
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ],
            "uris": [
              {
                "scheme": "https",
                "host": "www.example.com",
                "port": "8080",
                "path": "query/student/name",
                "pathStartWith": "query/student",
                "pathRegex": "query/.*/name",
                "type": "text/*"
              }
            ]
          }
        ]
      }
    ],
    "extensionAbilities": [
      {
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ],
            "uris": [
              {
                "scheme": "https",
                "host": "www.example.com",
                "port": "8080",
                "path": "query/student/name",
                "pathStartWith": "query/student",
                "pathRegex": "query/.*/name",
                "type": "text/*"
              }
            ]
          }
        ]
      }
    ]
  }
}
```

#### abilities对象内部结构

abilities描述Ability组件的配置信息，标签值为数组类型。

表14 ability对象内部结构说明

| 属性            | 含义                                                         | 数据类型<div style="width:20px">   | 是否可缺省                                                   |
| --------------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| name            | 该标签标识当前Ability组件的逻辑名，该名称在整个应用要唯一，标签值采用字符串表示（最大长度127字节）。 | 字符串     | 不可缺省。                                             |
| srcEntrance     | 该标签标识Ability组件所对应的js代码路径，标签值为字符串（最大长度127字节）。 | 字符串     | 不可缺省。                                             |
| launchType      | 该标签标识Ability组件的启动模式，可选标签值：<br/>"standard"：多实例，每次启动创建一个新的实例。<br/>"singleton"：单实例，仅第一次启动创建新实例。<br/>"specified"：运行时由开发者决定是否创建新实例。 | 字符串     | 可缺省，缺省值为"singleton"。                               |
| description     | 该标签标识Ability组件的描述信息，标签值是是字符串类型或对描述内容的资源索引，要求采用资源索引方式，以支持多语言。 | 字符串     | 可缺省，缺省值为空。                                   |
| icon            | 该标签标识Ability组件的图标，标签值为图标资源文件的索引。 | 字符串     | 可缺省，缺省值为空。<br/>如果Ability组件被配置为MainElement，该标签必须配置。 |
| permissions     | 该标签标识被其它应用的Ability组件调用时需要申请的权限的集合，一个数组元素为一个权限名称。通常采用反向域名格式（最大长度255字节），<br />取值为系统预定义的权限。 | 字符串数组 | 可缺省，缺省值为空。                                   |
| metadata        | 该标签标识Ability组件的元信息。参考[metadata对象内部结构](#metadata对象内部结构)。 | 对象数组       | 可缺省，缺省值为空。                                   |
| visible         | 该标签标识Ability组件是否可以被其它应用调用，true表示可以被其它应用调用， false表示不可以被其它应用调用。 | 布尔值     | 可缺省，缺省值为false。                                |
| continuable     | 该标签标识Ability组件是否可以迁移，true表示可以被迁移， false表示不可以被迁移。 | 布尔值     | 可缺省，缺省值为false。                                |
| skills          | 该标签标识Ability组件能够接收的意图的特征集。<br />配置规则 : entry包可以配置多个具有入口能力的skills标签（配置了action.system.home和entity.system.home）的Ability组件，<br />其中第一个配置了skills标签的Ability组件中的label和icon作为OpenHarmony服务或应用的label和icon。<br/>OpenHarmony服务的Feature包不能配置具有入口能力的skills标签。<br/>OpenHarmony应用的Feature包可以配置具有入口能力的skills标签。 <br />参考[skills对象内部结构](#skills对象内部结构)。 | 对象数组       | 可缺省，缺省值为空。                                   |
| backgroundModes | 该标签标识Ability组件的长时任务集合。指定用于满足特定类型的长时任务。<br />长时任务类型有如下 :<br/>dataTransfer :通过网络/对端设备进行数据下载、备份、分享、传输等业务。<br/>audioPlayback :音频输出业务。<br/>audioRecording :音频输入业务。<br/>location :定位、导航业务。<br/>bluetoothInteraction :蓝牙扫描、连接、传输业务（穿戴）。<br/>multiDeviceConnection :多设备互联业务。<br/>wifiInteraction :Wifi扫描、连接、传输业务（克隆 多屏）。<br/>voip :音视频电话，VOIP业务。<br/>taskKeeping :计算业务。 <br/> | 字符串数组     | 可缺省，缺省值为空。                                           |
| startWindowIcon    | 标识该Ability组件启动页面图标资源文件的索引。取值示例：$media:icon。 | 字符串       | 不可缺省。|
| startWindowBackground    | 标识该Ability组件启动页面背景颜色资源文件的索引。取值示例：$color:red。 | 字符串       | 不可缺省。|
| removeMissionAfterTerminate    | 该标签标识Ability组件销毁后是否从任务列表中移除任务。true表示销毁后移除任务， false表示销毁后不移除任务。 | 布尔值       | 可缺省，缺省值为false。|
| orientation              | 标识该Ability组件启动时的方向。取值范围包括：<br/>unspecified: 未指定方向，由系统自动判断显示方向，<br/>landscape：横屏，<br/> portrait：竖屏，<br/>landscape_inverted: 反向横屏， <br/>portrait_inverted: 反向竖屏， <br/>auto_rotation: 随传感器旋转， <br/>auto_rotation_landscape: 传感器横屏旋转，包括了横屏和反向横屏，<br/>auto_rotation_portrait: 传感器竖屏旋转，包括了竖屏和反向竖屏，<br/>auto_rotation_restricted: 传感器开关打开，方向可随传感器旋转，<br/>auto_rotation_landscape_restricted: 传感器开关打开，方向可随传感器旋转为横屏， 包括了横屏和反向横屏， <br/>auto_rotation_portrait_restricted: 传感器开关打开，方向随可传感器旋转为竖屏， 包括了横屏和反向横屏， <br/>locked: 传感器开关关闭，方向锁定。 | 字符串   | 可缺省，缺省值为"unspecified"。|
|supportWindowMode|标识该Ability组件所支持的窗口模式，取值范围包括：<br/> fullscreen: 全屏模式， <br /> split: 分屏模式， <br />floating: 悬浮窗模式。 |字符串数组       | 可缺省，缺省值为<br/>["fullscreen", "split", "floating"]。|
|maxWindowRatio|标识该Ability组件支持的最大的宽高比。| 数值    |可缺省，缺省值为平台支持的最大的宽高比。|
|minWindowRatio|标识该Ability组件支持的最小的宽高比。| 数值    |可缺省，缺省值为平台支持的最小的宽高比。|
|maxWindowWidth|标识该Ability组件支持的最大的窗口宽度，宽度单位为vp。| 数值    |可缺省，缺省值为平台支持的最大的窗口宽度。|
|minWindowWidth|标识该Ability组件支持的最小的窗口宽度, 宽度单位为vp。| 数值    |可缺省，缺省值为平台支持的最小的窗口宽度。|
|maxWindowHeight|标识该Ability组件支持的最大的窗口高度, 高度单位为vp。| 数值    |可缺省，缺省值为平台支持的最大的窗口高度。|
|minWindowHeight|标识该Ability组件支持的最小的窗口高度, 高度单位为vp。| 数值    |可缺省，缺省值为平台支持的最小的窗口高度。|

abilities示例 ：

```json
{
  "module": {
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntrance": "./ets/entryability/EntryAbility.ts",
        "description": "$string:ability_desc",
        "icon": "$media:icon",
        "label": "$string:ability_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "visible": true,
        "backgroundModes": [
          "dataTransfer",
          "audioPlayback",
          "audioRecording",
          "location",
          "bluetoothInteraction",
          "multiDeviceConnection",
          "wifiInteraction",
          "voip",
          "taskKeeping"
        ],
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
        "orientation": "landscape",
        "supportWindowMode": [
          "fullscreen",
          "split",
          "floating"
        ],
        "maxWindowRatio": 3.5,
        "minWindowRatio": 0.5,
        "maxWindowWidth": 2560,
        "minWindowWidth": 1400,
        "maxWindowHeight": 300,
        "minWindowHeight": 200
      }
    ]
  }
}
```

#### shortcuts对象内部结构

标识应用的快捷方式信息。最多可以配置四个快捷方式。<br/>
配置方式如下：<br/>
ability标签配置metadata信息。name :"ohos.ability.shortcuts"。resource :指定shortcuts信息的资源位置。

表15 shortcut对象内部结构说明

| 属性名称   | 含义                                                         | 数据类型<div style="width:20px"> | 是否可缺省                 |
| ---------- | ------------------------------------------------------------ | -------- | -------------------------- |
| shortcutId | 标识快捷方式的ID。最大长度为63字节。                 | 字符串   | 不可缺省。                         |
| label      | 标识快捷方式的标签信息，即快捷方式对外显示的文字描述信息。取值可以是描述性内容，也可以是标识label的资源索引。字符串最大长度为63字节。 | 字符串   | 可缺省，缺省值为空。         |
| icon       | 该标签标识shortcut的图标，标签值为资源文件的索引。           | 字符串   | 可缺省，缺省值为空。 |
| wants      | 该标签标识快捷方式内定义的目标wants信息集合，每个want可配置两个子标签，bundleName，abilityName。<br />bundleName :快捷方式目标包名，字符串类型。<br />abilityName :快捷方式的目标组件名，字符串类型。 | 对象数组     | 可缺省，缺省值为空。   |

shortcuts示例 :

1.在开发视图的resources/base/profile下面定义配置文件shortcuts_config.json（文件名称可由开发者定义）：

```json
{
  "shortcuts": [
    {
      "shortcutId": "shortcut_id",
      "label": "$string:label",
      "icon": "$media:icon",
      "wants": [
        {
          "bundleName": "com.example.myapplication",
          "abilityName": "abilityName"
        }
      ]
    }
  ]
}
```

2.在module.json5的abilities标签下配置metadata信息：

```json
{
  "module": {
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntrance": "./ets/entryability/EntryAbility.ts",
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
        "metadata": [
          {
            "name": "ohos.ability.shortcuts",
            "resource": "$profile:shortcuts_config"
          }
        ]
      }
    ]
  }
}
```

#### extensionAbilities对象内部结构

extensionAbilities描述extensionAbility的配置信息，标签值为数组类型。

表16 extensionAbility对象内部结构说明

| 属性名称    | 含义                                                         | 数据类型<div style="width:20px">   | 是否可缺省                    |
| ----------- | ------------------------------------------------------------ | ---------- | ----------------------------- |
| name        | 该标签标识当前ExtensionAbility组件的逻辑名，标签值采用字符串表示（最大长度127字节），该名称在整个应用要唯一。 | 字符串     | 不可缺省。              |
| srcEntrance | 该标签标识ExtensionAbility组件所对应的js代码路径，标签值为字符串（最大长度127字节）。 | 字符串     | 不可缺省。              |
| description | 该标签标识ExtensionAbility组件的描述，标签值是是字符串类型或对描述内容的资源索引，以支持多语言。 | 字符串     | 可缺省，缺省值为空。    |
| icon        | 该标签标识ExtensionAbility组件图标，标签值为资源文件的索引。 | 字符串     | 可缺省，缺省值为空。如果ExtensionAbility组件被配置为MainElement，不可缺省。    |
| label       | 该标签标识ExtensionAbility组件对用户显示的名称，标签值配置为该名称的资源索引以支持多语言。 | 字符串     | 可缺省，缺省值为空。如果ExtensionAbility组件被配置为MainElement，该标签必须配置，且应用内唯一。             |
| type        | 该标签标识ExtensionAbility组件的类型，取值为form、workScheduler、inputMethod、service、accessibility、dataShare、fileShare、staticSubscriber、wallpaper、backup、window、enterpriseAdmin、thumbnail、preview其中之一。 | 字符串     | 不可缺省。              |
| permissions | 该标签标识被其它应用的ability调用时需要申请的权限的集合，字符串数组类型，每个数组元素为一个权限名称，通常采用反向域名方式表示（最大长度255字节），取值为系统预定义权限或者应用自定义权限，如果是后者，需与defPermissions标签中定义的某个权限的name标签值一致。 | 字符串数组 | 可缺省，缺省值为空。    |
| uri         | 该标签标识ability提供的数据URI，为字符数组类型（最大长度255字节），用反向域名的格式表示。 | 字符串     | 可缺省，缺省值为空。该标签在type为dataShare类型的ExtensionAbility组件时，不可缺省。    |
| skills      | 该标签标识ability能够接收的意图的特征集，为数组格式。<br />配置规则 : entry包可以配置多个具有入口能力的skills标签（配置了action.system.home和entity.system.home）的ability，其中第一个配置了skills标签的ability中的label和icon作为OpenHarmony服务或应用的label和icon。<br/>OpenHarmony服务的Feature包不能配置具有入口能力的skills标签。<br/>OpenHarmony应用的Feature包可以配置具有入口能力的skills标签。 <br />参考[skills对象内部结构](#skills对象内部结构)。 | 对象数组       | 可缺省，缺省值为空。    |
| metadata    | 该标签标识ExtensionAbility组件的元信息。参考[metadata对象内部结构](#metadata对象内部结构)。 | 对象数组       | 可缺省，缺省值为空。    |
| visible     | 该标签标识ExtensionAbility组件是否可以被其它应用调用。true表示可以被其它应用调用， false表示不可以被其它应用调用。 | 布尔值     | 可缺省，缺省值为false。 |
| readPermission     | 该标签标识读取ExtensionAbility组件的数据所需的权限。最大长度255字节。type为dataShare类型的ExtensionAbility组件支持该配置。该标签只对系统应用生效。 | 字符串     | 可缺省，缺省值为空。 |
| writePermission     | 该标签标识向ExtensionAbility组件写数据所需的权限。最大长度255字节。type为dataShare类型的ExtensionAbility组件支持该配置。该标签只对系统应用生效。 | 字符串     | 可缺省，缺省值为空。 |

extensionAbilities示例 ：

```json
{
  "module": {
    "extensionAbilities": [
      {
        "name": "EntryFormAbility",
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
        "srcEntrance": "./ets/entryformability/EntryFormAbility.ts",
        "label": "$string:EntryFormAbility_label",
        "description": "$string:EntryFormAbility_desc",
        "type": "form",
        "metadata": [
          {
            "name": "ohos.extension.form",
            "resource": "$profile:form_config"
          }
        ]
      }
    ]
  }
}
```

#### forms对象内部结构

forms标签标识卡片的配置，form卡片是可以嵌入桌面上并接收定期更新的应用简要视图。<br/>
配置方式如下：<br/>
extensionAbility标签配置type为form，并配置metadata信息：name :"ohos.extension.form"。resource :指定form信息的资源位置。

表17 form对象内部结构说明

| 属性名称            | 含义                                                         | 数据类型<div style="width:20px">   | 是否可缺省                    |
| ------------------- | ------------------------------------------------------------ | ---------- | ----------------------------- |
| name                | 标识卡片的名称。最大长度为127字节。                    | 字符串     | 不可缺省。                             |
| description         | 标识卡片的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。最大长度为255字节。 | 字符串     | 可缺省，缺省值为空。            |
| src                 | 该标签标识JS卡片对应的UI代码。建议开发者通过自适应布局显示不同规格卡片，如果不同规格卡片布局相差较大，建议通过不同卡片来区分。 | 字符串     | 可缺省，缺省值为空。            |
| window              | 该标签标识JS卡片的自适应能力。参考[window对象内部结构](#window对象内部结构)。           | 对象       | 可缺省，缺省值为空。            |
| isDefault           | 标识该卡片是否为默认卡片，每个Ability有且只有一个默认卡片。 true :默认卡片。 false :非默认卡片。 | 布尔值     | 不可缺省。                             |
| colorMode           | 标识卡片的主题样式，取值范围如下 : <br/>auto :自适应。<br/> dark :深色主题。<br/> light :浅色主题。<br/>| 字符串     | 可缺省，缺省值为“auto”。      |
| supportDimensions   | 标识卡片支持的外观规格，取值范围 :<br/>1 * 2 :表示1行2列的二宫格。<br/> 2 * 1 :表示2行1列的二宫格。<br/> 2 * 2 :表示2行2列的四宫格。<br/> 2 * 4 :表示2行4列的八宫格。<br/> 4 * 4 :表示4行4列的十六宫格。 | 字符串数组 | 不可缺省。                             |
| defaultDimension    | 标识卡片的默认外观规格，取值必须在该卡片supportDimensions配置的列表中。 | 字符串     | 不可缺省。                            |
| updateEnabled       | 该标签标识该卡片是否支持实时刷新，true标识卡片支持实时刷新，false表示不支持。 | 布尔值     | 不可缺省。                             |
| scheduledUpdateTime | 该标签标识卡片定点刷新的时间，采用24小时计数，精确到分钟。   | 字符串     | 可缺省，缺省值为空。                            |
| updateDuration      | 该标签标识卡片定时刷新的更新频率，单位为30分钟，取值为30的倍数。卡片的最高频率为每30分钟刷新一次，和定点刷新二选一，二者都配置的情况下，定时优先。 | 数值       | 可缺省，缺省值为空。            |
| metadata            | 该标签标识卡片的元信息。参考[metadata对象内部结构](#metadata对象内部结构)。        | 对象数组       | 可缺省，缺省值为空。            |
| formConfigAbility   | 该标签标识卡片调整的Ability名称。最大长度127字节。该标签值必须满足下面的格式 :<br/>ability://单个ability名字。<br/>单个ability名字必须为本应用的ability。 | 字符串     | 可缺省，缺省值为空。            |
| formVisibleNotify   | 该标签标识卡片是否被允许使用卡片可见性通知。 | 布尔值     | 可缺省，缺省值为false。 |

form示例 :

1.在开发视图的resources/base/profile下面定义配置文件form_config.json（文件名称可由开发者定义）：

```json
{
  "forms": [
    {
      "name": "widget",
      "description": "This is a service widget.",
      "src": "./js/widget/pages/index/index",
      "window": {
        "designWidth": 720,
        "autoDesignWidth": true
      },
      "colorMode": "auto",
      "isDefault": true,
      "updateEnabled": true,
      "scheduledUpdateTime": "10:30",
      "updateDuration": 1,
      "defaultDimension": "2*2",
      "supportDimensions": [
        "2*2"
      ]
    }
  ]
}
```

2.在module.json5的extensionAbilities标签下配置metadata信息：

```json
{
  "module": {
    "extensionAbilities": [
      {
        "type": "form",
        "metadata": [
          {
            "name": "ohos.extension.form",
            "resource": "$profile:form_config"
          }
        ]
      }
    ]
  }
}
```

#### window对象内部结构

定义与显示窗口相关的配置。

表18 window对象内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省                 |
| -------- | ------------------------------------------------------------ | -------- | -------------------------- |
| designWidth     | 定义页面设计基准宽度，根据实际设备宽度来缩放元素大小。    | 数值   | 可缺省，缺省值为750。 |
| autoDesignWidth    | 定义页面设计基准宽度是否自动计算，当设置为true时，designWidth将被忽略，设计基准宽度由设备宽度与屏幕密度计算得出。    | 布尔值   | 可缺省，缺省值为false。         |

window示例 :

```json
{
  "forms": [
    {
      "window": {
        "designWidth": 720,
        "autoDesignWidth": true
      }
    }
  ]
}
```

#### commonEvents对象内部结构

commonEvents标签标识注册静态公共事件信息。<br/>
配置方式如下：<br/>
extensionAbility标签配置type为staticSubscriber，并配置metadata信息：name :"ohos.extability.staticSubscriber"。resource :指定commonEvents信息的资源位置。

表19 commonEvent对象内部结构

| 属性名称   | 含义                                                         | 数据类型   | 是否可缺省                 |
| ---------- | ------------------------------------------------------------ | ---------- | -------------------------- |
| name       | 该标签指明当前静态公共事件对应的ability名，该类需要在ability中标明。 | 字符串     | 不可缺省。           |
| permission | 该标签标识实现该静态公共事件需要申请的权限，以字符串类型表示一个权限名称，通常采用反向域名方式表示（最大长度255字节）。 | 字符串     | 可缺省，缺省值为空。       |
| types      | 该标签配置当前静态公共事件的类别数组，字符串数组类型，每个数组元素为一个类别名称。 | 字符串数组 | 可缺省，缺省值为空。 |
| events     | 该标签标识能够接收的意图的event值的集合，取值通常为系统预定义的event值，也允许自定义。 | 字符串数组 | 不可缺省。           |

commonEvents示例 :

1.在开发视图的resources/base/profile下面定义配置文件common_event_config.json（文件名称可由开发者定义）：

```json
{
    "commonEvents": [
        {
            "name": "abilityName",
            "permission": "permissionName",
            "types": [
                "type1",
                "type2"
            ],
            "events": [
                "event1",
                "event2"
            ]
        }
    ]
}
```

2.在module.json5的extensionAbilities标签下配置metadata信息：

```json
{
  "module": {
    "extensionAbilities": [
      {
        "name": "subscriber",
        "srcEntrance": "./ets/subscriber/Subscriber.ts",
        "type": "staticSubscriber",
        "metadata": [
          {
            "name": "ohos.extability.staticSubscriber",
            "resource": "$profile:common_event_config"
          }
        ]
      }
    ]
  }
}
```

#### definePermissions对象内部结构

该标签标识HAP定义的权限。该标签只支持系统应用配置。

表20 definePermission对象内部结构说明

| 属性名称               | 含义                                                         | 数据类型<div style="width:20px"> | 是否可缺省                     |
| ---------------------- | ------------------------------------------------------------ | -------- | ------------------------------ |
| name                   | 标识权限的名称。                                             | 字符串   | 不可缺省。                       |
| grantMode              | 标识权限的授予方式，授予模式如下：<br />system_grant：安装后系统自动授予该权限。<br />user_grant：应用动态申请，用户授权后才可使用。 | 字符串   | 可缺省，缺省值为"system_grant"。 |
| availableLevel         | 标识权限限制门限，可选值为system_core、system_basic、normal。<br />system_core：系统核心权限。<br />system_basic：系统基础权限。<br />normal：普通权限。所有应用允许申请的权限。 | 字符串   | 可缺省，缺省值为"normal"。       |
| provisionEnable        | 标识权限是否支持证书方式申请权限，包括高级别的权限，true标识需要开发者可以通过provision证书acls方式申请权限。 | 布尔值   | 可缺省，缺省值为true。           |
| distributedSceneEnable | 标识权限是否支持分布式场景下使用该权限。                     | 布尔值   | 可缺省，缺省值为false。          |
| label                  | 标识权限的简短描述，配置为对描述内容的资源索引。             | 字符串   | 可缺省，缺省值为空。             |
| description            | 标识权限的详细描述，可以是表示描述内容的字符串，也可以是对描述内容的资源索引。 | 字符串   | 可缺省，缺省值为空。             |

definePermissions示例 ：

```json
{
  "module": {
    "definePermissions": [
      {
        "name": "permissionName",
        "grantMode": "user_grant",
        "availableLevel": "system_basic",
        "provisionEnable": false,
        "distributedSceneEnable": true,
        "label": "$string:label",
        "description": "$string:description"
      }
    ]
  }
}
```

#### requestPermissions对象内部结构

该标签标识应用运行时需向系统申请的权限集合。

表21 requestPermission对象内部结构说明

| 属性名称   | 含义            | 数据类型<div style="width:20px"> | 是否可缺省                     |
| ------| ------| -------- | ------------------------------ |
| name      | 需要申请的权限名称。| 字符串   | 不可缺省。 |
| reason  | 申请权限的原因。配置为描述内容的资源索引，以支持多语言。   | 字符串   | 可缺省，缺省值为空。当申请权限的grantMode为user_grant时不可缺省。                       |
| usedScene | 权限使用的场景和时机。参考[usedScene对象内部结构](#usedscene对象内部结构)。| 对象   | 可缺省，缺省值为空。当申请权限的grantMode为user_grant时不可缺省。 |

requestPermissions示例 ：

```json
{
  "module": {
    "requestPermissions": [
      {
        "name": "permissionName",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "EntryAbility"
          ],
          "when": "inuse"
        }
      }
    ]
  }
}
```

权限访问的更多说明，可参考[访问控制开发指导](../security/accesstoken-guidelines.md)

#### usedScene对象内部结构

该标签标识权限使用的场景和时机。

表22 usedScene对象内部结构说明

| 属性名称 | 含义   | 数据类型 | 是否可缺省 |
| ------- | --------------------| -------- | ------ |
| abilities  | 标识需要使用到该权限的ability。| 字符串数组   | 不可缺省。 |
| when | 标识使用该权限的时机，可选值为inuse和always。inuse表示仅前台使用，always表示前后台都可使用。 | 字符串   | 可缺省，缺省值为空。 |


usedScene示例 ：

```json
{
  "module": {
    "requestPermissions": [
      {
        "usedScene": {
          "abilities": [
            "EntryAbility"
          ],
          "when": "inuse"
        }
      }
    ]
  }
}
```

#### testRunner对象内部结构

该标签用于支持对测试框架的配置

表23 testRunner对象内部结构

| 属性名称 | 含义                   | 数据类型 | 是否可缺省 |
| -------- | ---------------------- | -------- | ---------- |
| name     | 标识测试框架对象名称。 | 字符串   | 不可缺省。 |
| srcPath  | 标识测试框架代码路径。 | 字符串   | 不可缺省。 |

testRunner示例 :

```json
{
  "module": {
    "testRunner": {
      "name": "testRunnerName",
      "srcPath": "ets/test/TestRunner.ts"
    }
  }
}
```

