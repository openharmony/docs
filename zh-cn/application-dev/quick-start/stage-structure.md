

# 应用包结构配置文件的说明

在开发FA模型下的应用程序时，需要在config.json文件中对应用的包结构进行申明；同样的，在开发stage模型下的应用程序时，需要在module.json和app.json配置文件中对应用的包结构进行声明。

## 配置文件内部结构

配置文件由app和module这两个部分组成，缺一不可。配置文件的内部结构参见表1。

表1 配置文件的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省 |
| -------- | ------------------------------------------------------------ | -------- | ---------- |
| app      | 表示应用的全局配置信息。同一个应用的不同HAP包的app配置必须保持一致。参考[app对象内部结构](#app对象内部结构)。 | 对象     | 否         |
| module   | 表示HAP包的配置信息。该标签下的配置只对当前HAP包生效。参考[module对象内部结构](#module对象内部结构)。 | 对象     | 否         |

### app对象内部结构

app.json示例：

```json
{
	"app": {
        "bundleName": "com.application.music",
        "vendor": "application",
        "versionCode": 1,
        "versionName": "1.0",
        "minCompatibleVersionCode": 1,
        "apiCompatibleVersion": 7,
        "apiTargetVersion": 8,
        "apiReleaseType": "Release",
        "debug": false,
        "icon": "$media:app_icon",
        "label": "$string:app_name",
        "description": "$string:description_application",
        "distributedNotificationEnabled": true,
        "entityType": "game",
        "car": {
            "apiCompatibleVersion": 8
        }
    }
}
```

该标签为整个应用的属性，影响应用中所有hap及组件。该标签的内部结构参见表2。

表2 app对象的内部结构说明

| 属性名称                       | 含义                                                         | 数据类型 | 是否可缺省                                  |
| ------------------------------ | ------------------------------------------------------------ | -------- | ------------------------------------------- |
| bundleName                     | 该标签表示应用的包名，用于标识应用的唯一性。该标签不可缺省。标签的值命名规则 :<br /> 1）字符串以字母、数字、下划线和符号”.”组成；<br /> 2）以字母开头；<br /> 3）最小长度7个字节，最大长度127个字节。<br /> 推荐采用反域名形式命名（如 :com.example.xxx，建议第一级为域名后缀com，第二级为厂商/个人名，第三级为应用名，也可以多级）。<br /> 其中，随系统源码编译的应用需命名为”com.ohos.xxx”形式， ohos标识OpenHarmony系统应用。 | 字符串   | 否                                          |
| debug                          | 该标签标识应用是否可调试。                                   | 布尔值   | 该标签可以缺省，缺省为false。               |
| icon                           | 该标签标识应用的图标，标签值为资源文件的索引。               | 字符串   | 该标签不可缺省。                            |
| label                          | 该标签标识应用的的名称，标签值为资源文件的索引，以支持多语言。 | 字符串   | 该标签不可缺省。                            |
| description                    | 该标签标识App的描述信息，标签值是是字符串类型或对描述内容的资源索引，以支持多语言。 | 字符串   | 该标签可缺省，缺省值为空。                  |
| vendor                         | 该标签是对应用开发厂商的描述。该标签的值是字符串类型（最大255个字节）。 | 字符串   | 该标签可以缺省，缺省为空。                  |
| versionCode                    | 该标签标识应用的版本号，该标签值为32位非负整数。此数字仅用于确定某个版本是否比另一个版本更新，数值越大表示版本越高。开发者可以将该值设置为任何正整数，但是必须确保应用的新版本都使用比旧版本更大的值。该标签不可缺省，versionCode 值应小于2的31方。 | 数值     | 该标签不可缺省                              |
| versionName                    | 该标签标识版本号的文字描述，用于向用户展示。<br />该标签仅由数字和点构成，推荐采用“A.B.C.D”四段式的形式。四段式推荐的含义如下所示。<br/>第一段 :主版本号/Major，范围0-99，重大修改的版本，如实现新的大功能或重大变化。<br/>第二段 :次版本号/Minor，范围0-99，表示实现较突出的特点，如新功能添加和大问题修复。<br/>第三段 :特性版本号/Feature，范围0-99，标识规划的新版本特性。<br/>第四段 :修订版本号/Patch，范围0-999，表示维护版本，修复bug。 | 字符串   | 该标签不可缺省                              |
| minCompatibleVersionCode       | 该标签标识该app pack能够兼容的最低历史版本号。               | 数值     | 该标签可缺省。缺省值等于versionCode标签值。 |
| minAPIVersion                  | 该标签标识应用运行需要的API最小版本。                        | 数值     | 该标签不可缺省。                            |
| targetAPIVersion               | 该标签标识应用运行需要的API目标版本。                        | 整形     | 该标签不可缺省。                            |
| apiReleaseType                 | 该标签标识应用运行需要的API目标版本的类型，采用字符串类型表示。取值为“CanaryN”、“BetaN”或者“Release”，其中，N代表大于零的整数。<br />Canary :受限发布的版本。<br/>Beta :公开发布的Beta版本。<br/>Release :公开发布的正式版本。 | 字符串   | 该标签可缺省，缺省为“Release”。             |
| distributedNotificationEnabled | 该标签标记该应用是否开启分布式通知。                         | 布尔值   | 该标签可缺省，缺省值为true。                |
| entityType                     | 该标签标记该应用的类别，具体有 :游戏类(game)，影音类（media）、社交通信类（communication）、新闻类（news）、出行类（travel）、工具类（utility）、购物类（shopping）、教育类（education）、少儿类（kids）、商务类（business）、拍摄类（photography）。 | 字符串   | 该标签可以缺省，缺省为unspecified。         |

### module对象内部结构

module.json示例:

```json
{
    "module": {
        "name": "myHapName",
        "type": "entry|feature|har",
        "srcEntrance" : "./MyAbilityStage.js",
        "description" : "$string:description_application",
        "process": "string", 
        "mainElement": "MainAbility",
        "deviceTypes": [
            "tablet", 
            "tv", 
            "wearable",
            "car",
            "router",
        ],
        "deliveryWithInstall": true,
        "installationFree": false,
        "virtualMachine": "ark | default",
        "metadata": [
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file1"
            },
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file2"
            }
        ],
        "metadata": [
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file1"
            },
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file2"
            }
        ],
        "abilities": [
            {
                "name": "MainAbility",
                "srcEntrance" : "./login/MyMainAbility.ts",
                "description": "$string:description_main_ability",
                "icon": "$media:icon",
                "label": "HiMusic",
                "visible": true,
                "skills": [
                    {
                        "actions": [
                            "action.system.home"
                        ],
                        "entities": [
                            "entity.system.home"
                        ],
                        "uris": [ ]
                    }
                ],
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
            }
        ],
        "abilities": [
            {
                "name": "MainAbility",
                "srcEntrance" : "./login/MyMainAbility.ts",
                "description": "$string:description_main_ability",
                "icon": "$media:icon",
                "label": "HiMusic",
                "visible": true,
                "skills": [
                    {
                        "actions": [
                            "action.system.home"
                        ],
                        "entities": [
                            "entity.system.home"
                        ],
                        "uris": [ ]
                    }
                ],
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
            }
        ],
        "requestPermissions": [
            {
                "name": "ohos.abilitydemo.permission.PROVIDER",
                "reason": "$string:reason",
                "usedScene": {
                    "abilities": [
                        "FormAbility"
                    ],
                    "when": "inuse"
                }
            }
        ]
    }
}
```

hap包的配置信息，该标签下的配置只对当前hap包生效。

表3 module对象内部结构

| 属性名称            | 含义                                                         | 数据类型   | 是否可缺省                            |
| ------------------- | ------------------------------------------------------------ | ---------- | ------------------------------------- |
| name                | 该标签标识当前module的名字，module打包成hap后，表示hap的名称，标签值采用字符串表示（最大长度31个字节），该名称在整个应用要唯一。 | 字符串     | 该标签不可缺省。                      |
| type                | 该标签表示当前hap的类型。类型有三种，分别是entry、feature和har。 | 字符串     | 该标签不可缺省。                      |
| srcEntrance         | 该标签表示hap所对应的入口js代码路径，标签值为字符串（最长为127字节）。 | 字符串     | 该标签可缺省。                        |
| description         | 该标签标识hap包的描述信息，标签值是是字符串类型或对描述内容的资源索引，以支持多语言。 | 字符串     | 该标签可缺省，缺省值为空。            |
| process             | 该标签标识hap的进程名，标签值为字符串类型（最长为31个字节）。如果在hap标签下配置了process，该应用的所有ability都运行在该进程中。 | 字符串     | 可缺省，缺省为hap的名称。             |
| mainElement         | 该标签标识hap的入口ability名称或者extension名称。只有配置为mainElement的ability或者extension才允许在服务中心露出。创建OpenHarmony原子化服务时，该标签不可缺省。 | 字符串     | OpenHarmony应用下，该标签可缺省。     |
| deviceTypes         | 该标签标识hap可以运行在哪类设备上，标签值采用字符串数组的表示，系统预定义的设备类型见表4。<br />与syscap不同的是，deviceTypes是以设备类型为粒度，而syscap是以设备能力(例如蓝牙、wifi)为粒度。 | 字符串数组 | 该标签不可缺省，可以为空值。          |
| deliveryWithInstall | 该标签标识当前hap是否在用户主动安装的时候安装，true表示主动安装时安装，false表示主动安装时不安装。 | 布尔值     | 该标签不可缺省。                      |
| installationFree    | 表示当前HAP是否支持免安装特性。所有Hap包都需要配置不可缺省。<br/>true :表示支持免安装特性，且符合免安装约束。<br/>false :表示不支持免安装特性。<br/><br/>当entry.hap该字段配置为true时，与该entry.hap相关的所有feature.hap该字段也需要配置为true。<br/>当entry.hap该字段配置为false时，与该entry.hap相关的各feature.hap该字段可按业务需求配置true或false。 | 布尔值     | 该标签不可缺省。                      |
| virtualMachine      | 该标签用于标识当前hap运行的目标虚拟机类型，供云端分发使用，如应用市场和分发中心。<br/>该标签值为字符串。如果目标虚拟机类型为方舟虚拟机，则其值为”ark”； 如果目标虚拟机类型不是方舟虚拟机，则其值为”default”。该标签由IDE构建hap的时候自动插入。解包工具解析时，如果hap包没有该标签，设置该标签值为”default”。 | 字符串     | 该标签可缺省，缺省值为“default”。     |
| uiSyntax            | syntax定义该JS Component的语法类型。<br />hml标识该JS Component使用hml/css/js进行开发；<br/>ets标识该JS Component使用ets声明式语法进行开发。 | 字符串     | 该标签可缺省，默认值为hml             |
| pages               | 该标签是一个profile资源，用于列举JS Component中每个页面信息。pages使用参考pages示例。 | 对象       | 在有ability的场景下，该标签不可缺省。 |
| metadata            | 该标签标识Hap的自定义元信息，标签值为数组类型，该标签下的配置只对当前module、或者ability、或者extensionAbility生效。metadata参考[metadata对象内部结构](#metadata对象内部结构)。 | 数组       | 该标签可缺省，缺省值为空。            |
| abilities           | 描述元能力的配置信息，标签值为数组类型，该标签下的配置只对当前ability生效。abilities参考[abilities对象内部结构](#abilities对象内部结构)。 | 对象       | 该标签可缺省，缺省值为空。            |
| extensionAbilities  | 描述extensionAbilities的配置信息，标签值为数组类型，该标签下的配置只对当前extensionAbility生效。extensionAbilities参考[extensionAbility对象的内部结构说明](#extensionAbility对象的内部结构说明)。 | 对象       | 该标签可缺省，缺省值为空。            |
| requestPermissions  | 该标签标识应用运行时需向系统申请的权限集合，标签值为数组类型。requestPermissions参考[requestPermissions对象内部结构](#requestPermissions对象内部结构)。 | 对象       | 该标签可缺省，缺省值为空。            |

表4 deviceTypes对象的系统预定义设备

| 中文     | 英文        | 枚举值   | 设备类型                                                 |
| -------- | ----------- | -------- | -------------------------------------------------------- |
| 平板     | tablet      | tablet   | 平板，带屏音箱                                           |
| 智慧屏   | smart TV    | tv       | 智慧屏                                                   |
| 智能手表 | smart watch | wearable | 智能手表，儿童手表，特指资源较丰富的的手表，具备电话功能 |
| 车机     | head unit   | car      | 车机                                                     |
| 路由器   | router      | router   | 路由器                                                   |

deviceTypes示例 :

```json
{
	"module": {
		"name": "myHapName",
        "type": "har",
        "deviceTypes" : [
            "wearable"
        ]
	}
}
```

pages示例 :

```json
{
    "module": {
       "name": "myHapName",
        "type": "har",
        "deviceTypes" : [
            "wearable"
        ],
        "pages": "$profile:pages_config"
    }
}
```

pages_config配置文件

```json
{
    "src": [
        "pages/index/index",
        "pages/second/second",
        "pages/third/third",
        "pages/four/four"
    ]
}
```



#### metadata对象内部结构

描述的module、ability、extensionAbility配置信息，标签值为数组类型，该标签下的配置只对当前module、或者ability、或者extensionAbility生效。

表5 metadata对象内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省                 |
| -------- | ------------------------------------------------------------ | -------- | -------------------------- |
| name     | 该标签表示数据项的键名称，字符串类型（最大长度255字节）。    | 字符串   | 该标签可缺省，缺省值为空。 |
| value    | 该标签表示数据项的值，标签值为字符串（最大长度255字节）。    | 字符串   | 可缺省，缺省为空。         |
| resource | 该标签标识定义用户自定义数据格式，标签值为标识该数据的资源的索引值。 | 字符串   | 可缺省，缺省为空。         |

metadata示例 :

```json
{ 
    "module": {
        "metadata": [
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file"
            },
            {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file"
            }
        ]
    }
}
```

#### abilities对象内部结构

abilities描述ability的配置信息，标签值为数组类型。

表6 abilities对象内部结构说明

| 属性            | 含义                                                         | 数据类型   | 是否可缺省                                                   |
| --------------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| name            | 该标签标识当前ability的逻辑名，该名称在整个应用要唯一，标签值采用字符串表示（最大长度127个字节）。 | 字符串     | 该标签不可缺省。                                             |
| srcEntrance     | 该标签表示ability所对应的js代码路径，标签值为字符串（最长为127字节）。。 | 字符串     | 该标签不可缺省。                                             |
| launchType      | 该标签标示ability的启动模式，标签值可选“standard”、“singleton”、“specified”。该标签缺省为"singleton"。standard表示普通多实例，spcified表示指定实例，运行时由ability内部业务决定是否创建多实例，singleton表示单实例。 | 字符串     | 可缺省，该标签缺省为"singleton"                               |
| description     | 该标签标识ability的描述，标签值是是字符串类型或对描述内容的资源索引，要求采用用资源索引方式，以支持多语言。 | 字符串     | 该标签可缺省，缺省值为空。                                   |
| icon            | 该标签标识ability图标，标签值为资源文件的索引。该标签可缺省，缺省值为空。<br/>如果ability被配置为MainElement，该标签必须配置。 | 字符串     | 该标签可缺省，缺省值为空。<br/>如果ability被配置为MainElement，该标签必须配置。 |
| permissions     | 该标签标识被其它应用的ability调用时需要申请的权限的集合，字符串数组类型，每个数组元素为一个权限名称，通常采用反向域名方式表示（最大255字节），可以是系统预定义的权限，也可以是该应用自定义的权限。如果是后者，需与defPermissions标签中定义的某个权限的name标签值一致。该标签可缺省，缺省值为空。 | 字符串数组 | 该标签可缺省，缺省值为空。                                   |
| metadata        | 该标签表示ability的元信息。metadata参考[metadata对象内部结构](#metadata对象内部结构)。 | 数组       | 该标签可缺省，缺省值为空。                                   |
| visible         | 该标签标识ability是否可以被其它应用调用，为布尔类型，true表示可以被其它应用调用， false表示不可以被其它应用调用。 | 布尔值     | 该标签可缺省，缺省值为false。                                |
| continuable     | 该标签标识ability是否可以迁移，为布尔类型，true表示可以被迁移， false表示不可以被迁移。 | 布尔值     | 该标签可缺省，缺省值为false。                                |
| skills          | 该标签标识ability能够接收的意图的特征集，为数组格式。<br />配置规则 : entry包可以配置多个具有入口能力的skills标签（配置了action.system.home和entity.system.home）的ability，其中第一个配置了skills标签的ability中的label和icon作为OpenHarmony服务或应用的label和icon。<br/>OpenHarmony服务的Feature包不能配置具有入口能力的skills标签。<br/>OpenHarmony应用的Feature包可以配置具有入口能力的skills标签。 <br />skills内部结构参考[skills对象内部结构](#skills对象内部结构)。 | 数组       | 该标签可缺省，缺省值为空。                                   |
| backgroundModes | 该标签标识ability长时任务集合。指定用于满足特定类型的长时任务。<br />长时任务类型有如下 :<br/>dataTransfer :通过网络/对端设备进行数据下载、备份、分享、传输等业务。<br/>audioPlayback :音频输出业务。<br/>audioRecording :音频输入业务。<br/>location :定位、导航业务。<br/>bluetoothInteraction :蓝牙扫描、连接、传输业务（穿戴）。<br/>multiDeviceConnection :多设备互联业务。<br/>wifiInteraction :Wifi扫描、连接、传输业务（克隆 多屏）。<br/>voip :音视频电话，VOIP业务。<br/>taskKeeping :计算业务。 <br/> | 字符串     | 可缺省，缺省为空。                                           |

abilities示例

```json
{
    "abilities": [{
        "name": "MainAbility",
        "srcEntrance": "./ets/login/MyLoginAbility.ts",
        "launchType":"standard"
        "description": "$string:description_main_ability",
        "icon": "$media:icon",
        "label": "Login",
        "permissions": [],
        "metadata": [],
        "visible": true,
        "continuable": true,
        "skills": [{
            "actions": ["action.system.home"],
            "entities": ["entity.system.home"],
            "uris": []
        }],
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
    }],
}
```

#### skills对象内部结构

该标签标识ability或者extension能够接收的意图的特征。

表7 skills内部结构示例

| 属性名称 | 含义                                                         | 数据类型   | 是否可缺省           |
| -------- | ------------------------------------------------------------ | ---------- | -------------------- |
| actions  | 该标签标识能够接收的意图的action值的集合，取值通常为系统预定义的action值，也允许自定义。 | 字符串数组 | 可缺省，缺省值为空。 |
| entities | 该标签标识能够接收Want的元能力的类别集合，取值通常为系统预定义的类别，也允许自定义。 | 字符串数组 | 可缺省，缺省值为空。 |
| uris     | 该标签标识向 want过滤器添加数据规范集合。该规范可以是只有数据类型（mimeType 属性），可以是只有 URI，也可以是既有数据类型又有 URI。uris内部结构参考表8。 | 对象数组   | 可缺省，缺省值为空。 |

表8 uris对象的内部结构说明

| 属性名称 | 含义                | 数据类型 | 是否可缺省           |
| -------- | ------------------- | -------- | -------------------- |
| scheme   | 表示uri的scheme值。 | 字符串   | 不可缺省。           |
| host     | 表示uri的host值。   | 字符串   | 可缺省，缺省值为空。 |
| port     | 表示uri的port值。   | 字符串   | 可缺省，缺省值为空。 |
| path     | 表示uri的path值。   | 字符串   | 可缺省，缺省值为空。 |
| type     | 表示uri的type值。   | 字符串   | 可缺省，缺省值为空。 |

skills示例

```json
{
    "abilities": [
        {
            "skills": [
                {
                    "actions": [
                        "action.system.home"
                    ],
                    "entities": [
                        "entity.system.home"
                    ],
                    "uris": [
                        {
                            "scheme":"uri2",
                            "host":"host2",
                            "port":"port2",
                            "pathStartWith":"path2",
                            "pathRegex":"/query/.*",
                            "path":"path",
                            "type": "text/*"
                        },
                    ]
                }
            ],
        }
    ],
    "extensionAbilities": [
        {
            "skills": [
                {
                    "actions": [
                    ],
                    "entities": [
                    ],
                    "uris": [
                        {
                            "scheme":"uri2",
                            "host":"host2",
                            "port":"port2",
                            "pathStartWith":"path2",
                            "pathRegex":"/query/.*",
                            "path":"path",
                            "type": "text/*"
                        },
                    ]
                }
            ],
        }
    ],
}
```

#### extensionAbility对象的内部结构说明

描述extensionAbility的配置信息，标签值为数组类型，该标签下的配置只对当前extensionAbility生效。

表9 extensionAbility对象内部结构说明

| 属性名称    | 含义                                                         | 数据类型   | 是否可缺省                    |
| ----------- | ------------------------------------------------------------ | ---------- | ----------------------------- |
| name        | 该标签标识当前extensionAbility的逻辑名，标签值采用字符串表示（最大长度127个字节），该名称在整个应用要唯一。 | 字符串     | 该标签不可缺省。              |
| srcEntrance | 该标签表示extensionAbility所对应的js代码路径，标签值为字符串（最长为127字节）。 | 字符串     | 该标签不可缺省。              |
| description | 该标签标识extensionAbility的描述，标签值是是字符串类型或对描述内容的资源索引，以支持多语言。 | 字符串     | 该标签可缺省，缺省值为空。    |
| icon        | 该标签标识extensionAbility图标，标签值为资源文件的索引。如果extensionAbility被配置为MainElement，该标签必须配置。 | 字符串     | 该标签可缺省，缺省值为空。    |
| label       | 该标签标识extensionAbility对用户显示的名称，标签值配置为该名称的资源索引以支持多语言。<br/>如果extensionAbility被配置为MainElement，该标签必须配置，且应用内唯一。 | 字符串     | 该标签不可缺省。              |
| type        | 该标签标识extensionAbility的类型，取值为form、workScheduler、inputMethod、service、accessibility、dataShare、fileShare、staticSubscriber、wallpaper其中之一。 | 字符串     | 该标签不可缺省。              |
| permissions | 该标签标识被其它应用的ability调用时需要申请的权限的集合，字符串数组类型，每个数组元素为一个权限名称，通常采用反向域名方式表示（最大255字节），可以是系统预定义的权限，也可以是该应用自定义的权限。如果是后者，需与defPermissions标签中定义的某个权限的name标签值一致。 | 字符串数组 | 该标签可缺省，缺省值为空。    |
| uri         | 该标签标识ability提供的数据uri，为字符数组类型（最大长度255），用反向域名的格式表示。该标签在type为dataShare类型的extensionAbility时，不可缺省。 | 字符串     | 该标签可缺省，缺省值为空。    |
| skills      | 该标签标识ability能够接收的意图的特征集，为数组格式。<br />配置规则 : entry包可以配置多个具有入口能力的skills标签（配置了action.system.home和entity.system.home）的ability，其中第一个配置了skills标签的ability中的label和icon作为OpenHarmony服务或应用的label和icon。<br/>OpenHarmony服务的Feature包不能配置具有入口能力的skills标签。<br/>OpenHarmony应用的Feature包可以配置具有入口能力的skills标签。 <br />skills内部结构参考[skills对象内部结构](#skills对象内部结构)。 | 数组       | 该标签可缺省，缺省值为空。    |
| metadata    | 该标签表示extensionAbility的元信息。metadata内部结构参考[metadata对象内部结构](#metadata对象内部结构)。 | 对象       | 该标签可缺省，缺省值为空。    |
| visible     | 该标签标识extensionAbility是否可以被其它应用调用，为布尔类型。true表示可以被其它应用调用， false表示不可以被其它应用调用。 |            | 该标签可缺省，缺省值为false。 |

extensionAbility示例 :

```json
{
    "extensionAbilities": [
        {
            "name": "FormName",
            "srcEntrance": "./form/MyForm.ts",
            "icon": "$media:icon",
            "label" : "$string:extension_name",
            "description": "$string:form_description",
            "type": "form", 
            "permissions": ["ohos.abilitydemo.permission.PROVIDER"],
            "readPermission": "",
            "writePermission": "",
            "visible": true,
            "uri":"scheme://authority/path/query"
            "skills": [{
                "actions": [],
                "entities": [],
                "uris": []
            }],
            "metadata": [
                {
                    "name": "ohos.extability.form",
                    "resource": "$profile:form_config", 
                }
            ],
        }
    ]
}

```

#### requestPermissions对象内部结构

该标签标识应用运行时需向系统申请的权限集合。

表10 requestPermissions权限申请字段说明

| 属性名称  | 含义                                                         | **类型**                        | **取值范围**                                                | **默认值**             | **规则约束**                                                 |
| --------- | ------------------------------------------------------------ | ------------------------------- | ----------------------------------------------------------- | ---------------------- | ------------------------------------------------------------ |
| name      | 必须，填写需要使用的权限名称。                               | 字符串                          | 自定义                                                      | 无                     | 未填写时，解析失败。                                         |
| reason    | 可选，当申请的权限为user_grant权限时此字段必填。描述申请权限的原因。 | 字符串                          | 显示文字长度不能超过256个字节。                             | 空                     | user_grant权限必填，否则不允许在应用市场上架。需做多语种适配。 |
| usedScene | 可选，当申请的权限为user_grant权限时此字段必填。描述权限使用的场景和时机。场景类型有 :ability、when（调用时机）。可配置多个ability。 | ability :字符串数组when :字符串 | ability :ability的名称when :inuse（使用时）、always（始终） | ability :空when :inuse | user_grant权限必填ability，可选填when。                      |

requestPermissions示例 :

```json
{
    "name": "ohos.abilitydemo.permission.PROVIDER",
    "reason": "$string:reason",
    "usedScene": {
        "abilities": [
            "AudioAbility",
            "VedioAbility",
        ],
        "when": "inuse"
    }
}
```

#### form对象内部结构

forms标签表示卡片的配置，form卡片是可以嵌入桌面上并接收定期更新的应用简要视图。在以下场景中可以包含form标签。

1. extensions中指定type为form。

2. metadata中指定form信息，其中 :
   	  name :指定form的名称。使用ohos.extability.form作为form信息的标识。
      	  resource :指定form信息的资源位置。

表11 forms对象的内部结构说明

| 属性名称          | 含义                                                         | 数据类型   | 是否可缺省                    |
| ----------------- | ------------------------------------------------------------ | ---------- | ----------------------------- |
| name              | 表示卡片的类名。字符串最大长度为127字节。                    | 字符串     | 否                            |
| description       | 表示卡片的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。字符串最大长度为255字节。 | 字符串     | 可缺省，缺省为空。            |
| src               | 该标签标识JS卡片对应的UI代码。建议开发者通过自适应布局显示不同规格卡片，如果不同规格卡片布局相差较大，建议通过不同卡片来区分。 | 字符串     | 可缺省，缺省为空。            |
| window            | 该标签标识JS卡片的自适应能力。window结构参考表12。           | 对象       | 可缺省，缺省为空。            |
| isDefault         | 表示该卡片是否为默认卡片，每个Ability有且只有一个默认卡片。 true :默认卡片。 false :非默认卡片。 | 布尔值     | 否                            |
| colorMode         | 表示卡片的主题样式，取值范围如下 : auto :自适应。 dark :深色主题。 light :浅色主题。 | 字符串     | 可缺省，缺省值为“auto”。      |
| supportDimensions | 表示卡片支持的外观规格，取值范围 : 1 * 2 :表示1行2列的二宫格。 2 * 2 :表示2行2列的四宫格。 2 * 4 :表示2行4列的八宫格。 4 * 4 :表示4行4列的十六宫格。 | 字符串数组 | 否                            |
| defaultDimension  | 表示卡片的默认外观规格，取值必须在该卡片supportDimensions配置的列表中。 | 字符串     | 否                            |
| updateDuration    | 该标签标识卡片定时刷新的更新频率，单位为30分钟，取值为30的倍数值。卡片的最高频率为每30分钟刷新一次，和定点刷新二选一，二者都配置的情况下，定时优先。 | 数值       | 可缺省，缺省为空。            |
| metadata          | 该标签表示卡片的自定义信息。metadata内部结构参考表5。        | 对象       | 可缺省，缺省为空。            |
| formConfigAbility | 该标签标识卡片调整的Ability名称。标签值为字符串类型（最长127字符）。该标签值必须满足下面的格式 :<br/>ability://单个ability名字<br/>单个ability名字必须为本应用的ability。 | 字符串     | 可缺省，缺省为空。            |
| formVisibleNotify | 该标签标识卡片是否被允许使用卡片可见性通知。标签值为true或false | 布尔值     | 该标签可缺省，默认值为false。 |

表12 window内部结构说明

| 属性名称        | 含义                                                         | 数据类型 | 是否可缺省           |
| --------------- | ------------------------------------------------------------ | -------- | -------------------- |
| designWidth     | 指示页面设计的基线宽度，以像素为单位。 元素的大小由实际设备宽度缩放。 这个标签是一个整数。 | 数值     | 可缺省，缺省值为空。 |
| autoDesignWidth | 指定是否自动计算页面设计的基线宽度。 如果设置为true，则designWidth属性无效。基线宽度根据设备宽度和屏幕密度计算。 | 布尔值   | 可缺省，缺省值为空。 |

form示例 :

在开发视图的resources/base/profile下面定义配置文件form_config.json（文件名称可由开发者定义）

```json
{
    "forms": [
        {
            "name": "Form_Js",
            "description": "$string:form_description",
            "src": "./js/pages/card/index",
            "window": {
                "designWidth": 720,
                "autoDesignWidth": true
            },
            "colorMode": "auto",
            "formConfigAbility": "ability://xxxxx",
            "formVisibleNotify": false,
            "isDefault": true,
            "updateEnabled": true,
            "scheduledUpdateTime": "10:30",
            "updateDuration": 1,
            "defaultDimension": "2*2",
            "supportDimensions": [
                "2*2"
            ],
           "metadata": [
             {
                "name": "string",
                "value": "string",
                "resource": "$profile:config_file"
             }
           ] 
        }
    ]
}
```

在module.json的extension组件下面定义metadata信息

```json
{
	"extensionAbilities": [
        {
            "name": "MyForm",
            "type": "form", 
            "metadata": [
                {
                    "name": "ohos.extability.form",
                    "resource": "$profile:form_config",
                }
            ],
        }
	]
}
```

#### shortcuts对象内部结构

标识应用的快捷方式信息。标签值为数组，最多可以配置四个快捷方式。其包含四个子标签shortcutId、label、icon、intents。

metadata中指定shortcut信息，其中 :
1）name :指定shortcuts的名称。使用ohos.ability.shortcut作为shortcuts信息的标识。
2）resource :指定shortcuts信息的资源位置。

表13 shortcuts对象的内部结构说明

| 属性名称   | 含义                                                         | 数据类型 | 是否可缺省                 |
| ---------- | ------------------------------------------------------------ | -------- | -------------------------- |
| shortcutId | 表示快捷方式的ID。字符串的最大长度为63字节。                 | 字符串   | 否                         |
| label      | 表示快捷方式的标签信息，即快捷方式对外显示的文字描述信息。取值可以是描述性内容，也可以是标识label的资源索引。字符串最大长度为63字节。 | 字符串   | 可缺省，缺省为空。         |
| icon       | 该标签标识shortcut的图标，标签值为资源文件的索引。           | 字符串   | 该标签可缺省，缺省值为空。 |
| wants      | 该标签标识快捷方式内定义的目标wants信息集合，每个want可配置两个子标签，bundleName，abilityName。<br />bundleName :快捷方式目标包名，字符串类型。<br />abilityName :快捷方式的目标组件名，字符串类型。 | 对象     | 该标签可缺省，缺省为空。   |

在开发视图的resources/base/profile下面定义配置文件shortcut_config.json（文件名称可由开发者定义）。

```json
{
        "shortcuts": [
            {
                "shortcutId": "id_test1",
                "label": "$string:shortcut",
                "icon": "$media:aa_icon",
                "wants": [
                    {
                       "bundleName": "com.ohos.hello"
                       "abilityName": "MainAbility"
                    }
                ]
            }
        ]
}
```

在config.json的module下面定义metadata信息，如下 :

```json
{
    "module": {
        "name": "MyAbilityStage",
        "abilities" : [
            {
                "name" : "MyAbility",
                "srcEntrance": "./abilities/MyAbility.ts",
                "skills": [{
                            "actions": ["action.system.home"],
                            "entities": ["entity.system.home"],
                            "uris": []
                }],
                "metadata": [
                    {
                        "name": "ohos.ability.shortcut",
                        "resource": "$profile:shortcuts_config", 
                    }
                ],
            }
        ]
    }
}
```

#### commonEvents对象内部结构

commonEvents标签标识注册静态公共事件信息。标签值为数组。
metadata中指定commonEvent信息，其中 :

1. name :指定commonEvent的名称。使用ohos.extability.staticSubscriber作为commonEvent信息的标识。

2. resource :指定commonEvent信息的资源位置。

表14 commonEvents对象内部结构

| 属性名称   | 含义                                                         | 数据类型   | 是否可缺省                 |
| ---------- | ------------------------------------------------------------ | ---------- | -------------------------- |
| name       | 该标签指明当前静态公共事件对应的ability名，该类需要在ability中标明。 | 字符串     | 该标签不可缺省。           |
| permission | 该标签标识实现该静态公共事件需要申请的权限，以字符串类型表示一个权限名称，通常采用反向域名方式表示（最大255字节）。 | 字符串     | 可缺省，缺省值为空。       |
| types      | 该标签配置当前静态公共事件的类别数组，字符串数组类型，每个数组元素为一个类别名称。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| events     | 该标签标识能够接收的意图的event值的集合，取值通常为系统预定义的event值，也允许自定义。 | 字符串数组 | 该标签不可缺省。           |

在开发视图的resources/base/profile下面定义配置文件common_event_config.json（文件名称可由开发者定义）。

```json
{
    "commonEvents": [
            {
                "name": "abilityName",
                "permission": "string",
                "types": [
                    "string",
                    "string"
                ],
                "events": [
                    "string",
                    "string"
                ]
            }
    ]
}
```

在module.json的extension组件下面定义metadata信息，如下 :

```json
"extensionAbilities": [
    {
        "name": "mySubscriber",
        "srcEntrance": "./extension/my_subscriber.js",
        "type": "staticSubscriber",
        "metadata": [
            {
                "name": "ohos.extability.staticSubscriber",
                "resource": "$profile:common_event_config", 
            }
        ],
    }
]
```

#### distroFilter对象内部结构

表示应用的分发规则。

该标签用于定义HAP包对应的细分设备规格的分发策略，以便在应用市场进行云端分发应用包时做精准匹配。该标签可配置的分发策略维度包括API Verion、屏幕形状、屏幕分辨率。在进行分发时，通过deviceType与这三个属性的匹配关系，唯一确定一个用于分发到设备的HAP。

表15  distroFilter对象内部结构

| 属性名称      | 含义                                                         | 数据类型 | 是否可缺省                 |
| ------------- | ------------------------------------------------------------ | -------- | -------------------------- |
| apiVersion    | 表示支持的apiVersion范围。参考表16。                         | 对象数组 | 该标签可缺省，缺省值为空。 |
| screenShape   | 表示屏幕形状的支持策略。                                     | 对象数组 | 该标签可缺省，缺省值为空。 |
| screenWindow  | 表示应用运行时窗口的分辨率支持策略。该字段仅支持对轻量级智能穿戴设备进行配置。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| screenDensity | 该标签表示屏幕的像素密度（dpi :Dot Per Inch）。该字段可选，如果配置了该字段，取值必须合法。该标签为字符串数组，字符串范围如下。<br />sdpi :表示小规模的屏幕密度（Small-scale Dots per Inch），适用于dpi取值为（0,120]的设备。<br />mdpi :表示中规模的屏幕密度(Medium-scale Dots Per Inch)，适用于dpi取值为(120,160]的设备。<br />ldpi :表示大规模的屏幕密度(Large-scale Dots Per Inch)，适用于dpi取值为(160,240]的设备。<br /> xldpi :表示大规模的屏幕密度(Extra Large-scale Dots Per Inch)，适用于dpi取值为(240,320]的设备。<br />xxldpi :表示大规模的屏幕密度(Extra Extra  Large-scale Dots Per Inch)，适用于dpi取值为(320，480]的设备。<br />xxxldpi :表示大规模的屏幕密度(Extra Extra Extra   Large-scale Dots Per Inch)，适用于dpi取值为(480, 640]的设备。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| countryCode   | 该标签表示应用需要分发的国家地区码，具体值以ISO-3166-1标准为准。支持多个国家和地区枚举定义。该字段可选，如果配置了该字段，取值必须合法。标签值字符串数组，子串表示所支持的国家或地区，由两个大写字母组成。 | 对象数组 | 该标签可缺省，缺省值为空。 |

表16  apiVersion对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 表示该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 支持的取值为API Version存在的整数值，例如4、5、6。场景示例 :某应用，针对相同设备型号，同时在网的为使用API 5和API 6开发的两个软件版本，则允许上架2个entry类型的安装包，分别支持到对应设备侧软件版本的分发。 | 数组     | 可缺省，缺省值为空。 |

表17 screenShape对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 表示该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 支持的取值为circle（圆形）、rect（矩形）。场景示例 :针对智能穿戴设备，可为圆形表盘和矩形表盘分别提供不同的HAP。 | 数组     | 可缺省，缺省值为空。 |

表18 screenWindow对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 表示该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 单个字符串的取值格式为 :“宽 * 高”，取值为整数像素值，例如“454 * 454”。 | 数组     | 可缺省，缺省值为空。 |

表19  screenDensity对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 表示该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 该标签表示屏幕的像素密度（dpi :Dot Per Inch）。              | 数组     | 可缺省，缺省值为空。 |

表20 countryCode对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 表示该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 该标签表示应用需要分发的国家地区码。                         | 数组     | 可缺省，缺省值为空。 |

distroFilter示例 :

在开发视图的resources/base/profile下面定义配置文件distroFilter_config.json（文件名称可由开发者定义）。

```json
"distroFilter": [
    {
       "apiVersion": {
            "policy": "include",
            "value": [4,5]
        },
        "screenShape": {
            "policy": "include",
            "value": ["circle","rect"]
        },
        "screenWindow": {
            "policy": "include",
            "value": ["454*454","466*466"]
        }
    }
]
```

在module.json的extensionAbilities组件下面定义metadata信息，如下 :

```json
"extensionAbilities": [
    {
        "name": "mySubscriber",
        "srcEntrance": "./extension/my_subscriber.js",
        "type": "staticSubscriber", 
        "metadata": [
            {
                "name": "ohos.extability.staticSubscriber",
                "resource": "$profile:distroFilter_config", 
            }
        ],
    }
]

```

