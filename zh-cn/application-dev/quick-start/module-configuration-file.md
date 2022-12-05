# module.json5配置文件


先通过一个示例，整体认识一下module.json5配置文件。

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
    "virtualMachine": "ark",
    "metadata": [
      {
        "name": "string",
        "value": "string",
        "resource": "$profile:distrofilter_config"
      }
    ],
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntrance": "./ets/entryability/EntryAbility.ts",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "visible": true,
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


module.json5配置文件包含以下标签。


  **表1** **module.json5配置文件配置标签说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识当前Module的名称，标签值采用字符串表示（最大长度31个字节），该名称在整个应用要唯一。 | 字符串 | 该标签不可缺省。 |
| type | 标识当前Module的类型。类型有两种，分别：<br/>-&nbsp;entry：应用的主模块。<br/>-&nbsp;feature：应用的动态特性模块。 | 字符串 | 该标签不可缺省。 |
| srcEntrance | 标识当前Module所对应的代码路径，标签值为字符串（最长为127字节）。 | 字符串 | 该标签可缺省，缺省值为空。 |
| description | 标识当前Module的描述信息，标签值是字符串类型（最长255字节）或对描述内容的字符串资源索引。 | 字符串 | 该标签可缺省，缺省值为空。 |
| process | 标识当前Module的进程名，标签值为字符串类型（最长为31个字节）。如果在HAP标签下配置了process，该应用的所有UIAbility、DataShareExtensionAbility、ServiceExtensionAbility都运行在该进程中。<br/>**说明：**<br/>- 仅支持系统应用配置，三方应用配置不生效。 | 字符串 | 可缺省，缺省为app.json5文件下app标签下的bundleName。 |
| mainElement | 标识当前Module的入口UIAbility名称或者ExtensionAbility名称。标签最大字节长度为255。 | 字符串 | 该标签可缺省，缺省值为空。 |
| [deviceTypes](#devicetypes标签) | 标识当前Module可以运行在哪类设备上，标签值采用字符串数组的表示。 | 字符串数组 | 该标签不可缺省，可以为空值。 |
| deliveryWithInstall | 标识当前Module是否在用户主动安装的时候安装，表示该Module对应的HAP是否跟随应用一起安装。<br/>-&nbsp;true：主动安装时安装。<br/>-&nbsp;false：主动安装时不安装。 | 布尔值 | 该标签不可缺省。 |
| installationFree | 标识当前Module是否支持免安装特性。<br/>-&nbsp;true：表示支持免安装特性，且符合免安装约束。<br/>-&nbsp;false：表示不支持免安装特性。<br/>**说明：**<br/>- 当应用的entry类型Module的该字段配置为true时，该应用的feature类型的该字段也需要配置为true。<br/>- 当应用的entry类型Module的该字段配置为false时，该应用的feature类型的该字段根据业务需求配置true或false。 | 布尔值 | 该标签不可缺省。 |
| virtualMachine | 标识当前Module运行的目标虚拟机类型，供云端分发使用，如应用市场和分发中心。<br/>该标签值为字符串。如果目标虚拟机类型为ArkTS引擎，则其值为“ark+版本号”。 | 字符串 | 该标签由IDE构建HAP的时候自动插入。 |
| uiSyntax（deprecated） | 标识当前Module&nbsp;syntax定义该JS&nbsp;Component的语法类型。<br/>-&nbsp;hml：标识该JS&nbsp;Component使用hml/css/js进行开发。<br/>-&nbsp;ets：标识该JS&nbsp;Component使用ArkTS声明式语法进行开发。 | 字符串 | 该标签可缺省，默认值为hml，该标签从API9开始废弃。 |
| [pages](#pages标签) | 标识当前Module的profile资源，用于列举JS&nbsp;Component中每个页面信息。该标签最大长度为255个字节。 | 字符串 | 在有UIAbility的场景下，该标签不可缺省。 |
| [metadata](#metadata标签) | 标识当前Module的自定义元信息，标签值为数组类型，只对当前Module、UIAbility、ExtensionAbility生效。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [abilities](#abilities标签) | 标识当前Module中UIAbility的配置信息，标签值为数组类型，只对当前UIAbility生效。 | 对象 | 该标签可缺省，缺省值为空。 |
| [extensionAbilities](#extensionabilities标签) | 标识当前Module中ExtensionAbility的配置信息，标签值为数组类型，只对当前ExtensionAbility生效。 | 对象 | 该标签可缺省，缺省值为空。 |
| [requestPermissions](#requestpermissions标签) | 标识当前应用运行时需向系统申请的权限集合。 | 对象 | 该标签可缺省，缺省值为空。 |
| [testRunner](#testrunner标签) | 标识当前Module用于支持对测试框架的配置。 | 对象 | 该标签可缺省，缺省值为空。 |


## deviceTypes标签

  **表2** deviceType标签配置说明

| 设备类型 | 枚举值 | 说明 |
| -------- | -------- | -------- |
| 平板 | tablet | - |
| 智慧屏 | tv | - |
| 智能手表 | wearable | 系统能力较丰富的手表，具备电话功能。 |
| 车机 | car | - |
| 默认设备 | default | 能够使用全部系统能力的OpenHarmony设备。 |

deviceTypes示例：


```json
{
  "module": {
    "name": "myHapName",
    "type": "feature",
    "deviceTypes" : [
       "tablet"
    ]
  }
}
```


## pages标签

该标签是一个profile文件资源，用于指定描述页面信息的配置文件。


```json
{
  "module": {
    // ...
    "pages": "$profile:main_pages", // 通过profile下的资源文件配置
  }
}
```

在开发视图的resources/base/profile下面定义配置文件**main_pages**.json，其中文件名(**main_pages**)可自定义，需要和前文中pages标签指定的信息对应，配置文件中列举了当前应用组件中的页面信息。


```json
{
  "src": [
    "pages/index/mainPage",
    "pages/second/payment",
    "pages/third/shopping_cart",
    "pages/four/owner"
  ]
}
```


## metadata标签

该标签标识HAP的自定义元信息，标签值为数组类型，包含name，value，resource三个子标签。

  **表3** **metadata标签说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 该标签标识数据项的键名称，字符串类型（最大长度255字节）。 | 字符串 | 该标签可缺省，缺省值为空。 |
| value | 该标签标识数据项的值，标签值为字符串（最大长度255字节）。 | 字符串 | 该标签可缺省，缺省值为空。 |
| resource | 该标签标识定义用户自定义数据格式，标签值为标识该数据的资源的索引值。该标签最大字节长度为255字节。 | 字符串 | 该标签可缺省，缺省值为空。 |


```json
{
  "module": {
    "metadata": [{
      "name": "module_metadata",
      "value": "a test demo for module metadata",
      "resource": "$profile:shortcuts_config",
    }],

    "abilities": [{
      "metadata": [{
        "name": "ability_metadata",
        "value": "a test demo for ability",
        "resource": "$profile:config_file"
      },
      {
        "name": "ability_metadata_2",
        "value": "a string test",
        "resource": "$profile:config_file"
      }],
    }],

    "extensionAbilities": [{
      "metadata": [{
        "name": "extensionAbility_metadata",
        "value": "a test for extensionAbility",
        "resource": "$profile:config_file"
      },
      {
        "name": "extensionAbility_metadata_2",
        "value": "a string test",
        "resource": "$profile:config_file"
      }],
    }]
  }
}
```


## abilities标签

ablities标签描述UIAbility组件的配置信息，标签值为数组类型，该标签下的配置只对当前UIAbility生效。

  **表4** **abilities标签说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识当前UIAbility组件的名称，该名称在整个应用要唯一，标签值采用字符串表示（最大长度127个字节）。 | 字符串 | 该标签不可缺省。 |
| srcEntrance | 该标签标识入口UIAbility的代码路径，标签值为字符串（最长为127字节）。 | 字符串 | 该标签不可缺省。 |
| [launchType](../application-models/uiability-launch-type.md) | 标识当前UIAbility组件的启动模式，可选标签值：<br/>-&nbsp;standard：标准实例模式，每次启动创建一个新的实例。<br/>-&nbsp;singleton：单实例模式，仅第一次启动创建新实例。<br/>-&nbsp;specified：指定实例模式，运行时由开发者决定是否创建新实例。 | 字符串 | 可缺省，该标签缺省为“singleton”。 |
| description | 标识当前UIAbility组件的描述信息，标签值是字符串类型（最长255字节）或对描述内容的资源索引，要求采用资源索引方式，以支持多语言。 | 字符串 | 该标签可缺省，缺省值为空。 |
| icon | 标识当前UIAbility组件的图标，标签值为图标资源文件的索引。 | 字符串 | 该标签可缺省，缺省值为空。<br/>如果UIAbility被配置为MainElement，该标签必须配置。 |
| label | 标识当前UIAbility组件对用户显示的名称，标签值配置为该名称的资源索引以支持多语言。<br/>如果UIAbility被配置当前Module的mainElement时，该标签必须配置，且应用内唯一。 | 字符串 | 该标签不可缺省。 |
| permissions | 标识当前UIAbility组件自定义的权限信息。当其他应用访问该UIAbility时，需要申请相应的权限信息。<br/>一个数组元素为一个权限名称。通常采用反向域名格式（最大255字节），取值为系统预定义的权限。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| [metadata](#metadata标签) | 标识当前UIAbility组件的元信息。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| visible | 标识当前UIAbility组件是否可以被其他应用调用。<br/>-&nbsp;true：表示可以被其他应用调用。<br/>-&nbsp;false：表示不可以被其他应用调用。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| continuable | 标识当前UIAbility组件是否可以[迁移](../application-models/hop-cross-device-migration.md)。<br/>-&nbsp;true：表示可以被迁移。<br/>-&nbsp;false：表示不可以被迁移。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| [skills](#skills标签) | 标识当前UIAbility组件或ExtensionAbility组件能够接收的[Want](../application-models/want-overview.md)的特征集，为数组格式。<br/>配置规则：<br/>-&nbsp;对于Entry类型的HAP，OpenHarmony应用可以配置多个具有入口能力的skills标签（即配置了action.system.home和entity.system.home）。<br/>-&nbsp;对于Feature类型的HAP，只有OpenHarmony应用可以配置具有入口能力的skills标签，OpenHarmony服务不允许配置。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| backgroundModes | 标识当前UIAbility组件的长时任务集合。指定用于满足特定类型的长时任务。<br/>长时任务类型有如下：<br/>-&nbsp;dataTransfer：通过网络/对端设备进行数据下载、备份、分享、传输等业务。<br/>-&nbsp;audioPlayback：音频输出业务。<br/>-&nbsp;audioRecording：音频输入业务。<br/>-&nbsp;location：定位、导航业务。<br/>-&nbsp;bluetoothInteraction：蓝牙扫描、连接、传输业务（穿戴）。<br/>-&nbsp;multiDeviceConnection：多设备互联业务。<br/>-&nbsp;wifiInteraction：Wi-Fi扫描、连接、传输业务（克隆多屏）。<br/>-&nbsp;voip：音视频电话，VoIP业务。<br/>-&nbsp;taskKeeping：计算业务。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| startWindowIcon | 标识当前UIAbility组件启动页面图标资源文件的索引。取值示例：$media:icon。<br/>该标签最大字节长度为255。 | 字符串 | 不可缺省。 |
| startWindowBackground | 标识当前UIAbility组件启动页面背景颜色资源文件的索引。取值示例：$color:red。<br/>改标签最大字节长度为255。 | 字符串 | 不可缺省。 |
| removeMissionAfterTerminate | 标识当前UIAbility组件销毁后是否从任务列表中移除任务，为布尔类型：<br/>-&nbsp;true表示销毁后移除任务。<br/>-&nbsp;false表示销毁后不移除任务。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| orientation | 标识当前UIAbility组件启动时的方向。该方向的取值范围包括：<br/>-&nbsp;unspecified：未指定方向，由系统自动判断显示方向。<br/>-&nbsp;landscape：横屏。<br/>-&nbsp;portrait：竖屏。<br/>-&nbsp;landscape_inverted：反向横屏。<br/>-&nbsp;portrait_inverted：反向竖屏。<br/>-&nbsp;auto_rotation：随传感器旋转。<br/>-&nbsp;auto_rotation_landscape：传感器横屏旋转，包括了横屏和反向横屏。<br/>-&nbsp;auto_rotation_portrait：传感器竖屏旋转，包括了竖屏和反向竖屏。<br/>-&nbsp;auto_rotation_restricted：传感器开关打开，方向可随传感器旋转。<br/>-&nbsp;auto_rotation_landscape_restricted：传感器开关打开，方向可随传感器旋转为横屏，&nbsp;包括了横屏和反向横屏。<br/>-&nbsp;auto_rotation_portrait_restricted：传感器开关打开，方向随可传感器旋转为竖屏，&nbsp;包括了横屏和反向横屏。<br/>-&nbsp;locked：传感器开关关闭，方向锁定。 | 字符串 | 该标签可缺省，缺省值为unspecified。 |
| supportWindowMode | 标识当前UIAbility组件所支持的窗口模式，包含：<br/>-&nbsp;fullscreen：全屏模式。<br/>-&nbsp;split：分屏模式。<br/>-&nbsp;floating：悬浮窗模式。 | 字符串数组 | 该标签可缺省，缺省值为<br/>["fullscreen",&nbsp;"split",&nbsp;"floating"]。 |
| priority | 标识当前UIAbility组件的优先级，仅支持系统应用配置，三方应用配置不生效。[隐式查询](../application-models/explicit-implicit-want-mappings.md)时，优先级越高，UIAbility在返回列表越靠前。该标签取值为integer类型，取值范围0-10。数值越大，优先级越高。 | 数值 | 该标签可缺省，缺省值为0。 |
| maxWindowRatio | 标识当前UIAbility组件支持的最大的宽高比。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最大的宽高比。 |
| minWindowRatio | 标识当前UIAbility组件支持的最小的宽高比。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最小的宽高比。 |
| maxWindowWidth | 标识当前UIAbility组件支持的最大的窗口宽度，宽度单位为vp。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最大的窗口宽度。 |
| minWindowWidth | 标识当前UIAbility组件支持的最小的窗口宽度,&nbsp;宽度单位为vp。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最小的窗口宽度。 |
| maxWindowHeight | 标识当前UIAbility组件支持的最大的窗口高度,&nbsp;高度单位为vp。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最大的窗口高度。 |
| minWindowHeight | 标识当前UIAbility组件支持的最小的窗口高度,&nbsp;高度单位为vp。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最小的窗口高度。 |
| excludeFromMissions | 标识当前UIAbility组件是否在最近任务列表中显示。<br/>-&nbsp;true：表示不在任务列表中显示。<br/>-&nbsp;false：表示在任务列表中显示。<br/>**说明：**<br/>- 仅支持系统应用配置，三方应用配置不生效。 | 布尔值 | 该标签可缺省，缺省值为false。 |

abilities示例：


```json
{
  "abilities": [{
    "name": "EntryAbility",
    "srcEntrance": "./ets/entryability/EntryAbility.ts",
    "launchType":"standard",
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
    "startWindowIcon": "$media:icon",
    "startWindowBackground": "$color:red",
    "removeMissionAfterTerminate": true,
    "orientation": " ",
    "supportWindowMode": ["fullscreen", "split", "floating"],
    "maxWindowRatio": 3.5,
    "minWindowRatio": 0.5,
    "maxWindowWidth": 2560,
    "minWindowWidth": 1400,
    "maxWindowHeight": 300,
    "minWindowHeight": 200,
    "excludeFromMissions": false
  }]
}
```


## skills标签

该标签标识UIAbility组件或者ExtensionAbility组件能够接收的[Want](../application-models/want-overview.md)的特征。

  **表5** **skills标签说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| actions | 标识能够接收的Want的[Action值的集合](../application-models/actions-entities.md)，取值通常为系统预定义的action值，也允许自定义。 | 字符串数组 | 可缺省，缺省值为空。 |
| entities | 标识能够接收Want的[Entity值的集合](../application-models/actions-entities.md)。 | 字符串数组 | 可缺省，缺省值为空。 |
|uris | 标识与Want中URI（Uniform&nbsp;Resource&nbsp;Identifier）相匹配的集合。 | 对象数组 | 可缺省，缺省值为空。 |

  **表6** **uris对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| scheme | 标识URI的协议名部分，常见的有http、https、file、ftp等。 | 字符串 | uris中仅配置type时可以缺省，缺省值为空，否则不可缺省。 |
| host | 标识URI的主机地址部分，该字段要在schema存在时才有意义。常见的方式：<br/>-&nbsp;域名方式，如example.com。<br/>-&nbsp;IP地址方式，如10.10.10.1。 | 字符串 | 可缺省，缺省值为空。 |
| port | 标识URI的端口部分。如http默认端口为80，https默认端口是443，ftp默认端口是21。该字段要在schema和host都存在时才有意义。 | 字符串 | 可缺省，缺省值为空。 |
| path&nbsp;\|&nbsp;pathStartWith&nbsp;\|&nbsp;pathRegex | 标识URI的路径部分，path、pathStartWith和pathRegex配置时三选一。path标识URI与want中的路径部分全匹配，pathStartWith标识URI与want中的路径部分允许前缀匹配，pathRegex标识URI与want中的路径部分允许正则匹配。该字段要在schema和host都存在时才有意义。 | 字符串 | 可缺省，缺省值为空。 |
| type | 标识与Want相匹配的数据类型，使用[MIME](https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com%E3%80%82)（Multipurpose&nbsp;Internet&nbsp;Mail&nbsp;Extensions）类型规范。可与schema同时配置，也可以单独配置。 | 字符串 | 可缺省，缺省值为空。 |

skills示例：


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
              "scheme":"http",
              "host":"example.com",
              "port":"80",
              "path":"path",
              "type": "text/*"
            }
          ]
        }
      ]
    }
  ]
}
```


## extensionAbilities标签

描述extensionAbilities的配置信息，标签值为数组类型，该标签下的配置只对当前extensionAbilities生效。

  **表7** **extensionAbilities标签说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识当前ExtensionAbility组件的名称，标签值最大长度为127个字节，该名称在整个应用要唯一。 | 字符串 | 该标签不可缺省。 |
| srcEntrance | 标识当前ExtensionAbility组件所对应的代码路径，标签值最大长度为127字节。 | 字符串 | 该标签不可缺省。 |
| description | 标识当前ExtensionAbility组件的描述，标签值最大长度为255字节，标签也可以是描述内容的资源索引，用于支持多语言。 | 字符串 | 该标签可缺省，缺省值为空。 |
| icon | 标识当前ExtensionAbility组件的图标，标签值为资源文件的索引。如果ExtensionAbility组件被配置为MainElement，该标签必须配置。 | 字符串 | 该标签可缺省，缺省值为空。 |
| label | 标识当前ExtensionAbility组件对用户显示的名称，标签值配置为该名称的资源索引以支持多语言。<br/>**说明：**<br/>- 如果ExtensionAbility被配置当前Module的mainElement时，该标签必须配置，且应用内唯一。 | 字符串 | 该标签不可缺省。 |
| type | 标识当前ExtensionAbility组件的类型，取值为：<br/>-&nbsp;form：卡片的ExtensionAbility。<br/>-&nbsp;workScheduler：延时任务的ExtensionAbility。<br/>-&nbsp;inputMethod：输入法的ExtensionAbility。<br/>-&nbsp;service：后台运行的service组件。<br/>-&nbsp;accessibility：辅助能力的ExtensionAbility。<br/>-&nbsp;dataShare：数据共享的ExtensionAbility。<br/>-&nbsp;fileShare：文件共享的ExtensionAbility。<br/>-&nbsp;staticSubscriber：静态广播的ExtensionAbility。<br/>-&nbsp;wallpaper：壁纸的ExtensionAbility。<br/>-&nbsp;backup：数据备份的ExtensionAbility。<br/>-&nbsp;window：该ExtensionAbility会在启动过程中创建一个window，为开发者提供界面开发。开发者开发出来的界面将通过abilityComponent控件组合到其他应用的窗口中。<br/>-&nbsp;thumbnail：获取文件缩略图的ExtensionAbility，开发者可以对自定义文件类型的文件提供缩略。<br/>-&nbsp;preview：该ExtensionAbility会将文件解析后在一个窗口中显示，开发者可以通过将此窗口组合到其他应用窗口中。<br/>**说明：**<br/>- 其中service和dataShare类型，仅支持系统应用配置，三方应用配置不生效。 | 字符串 | 该标签不可缺省。 |
| permissions | 标识当前ExtensionAbility组件自定义的权限信息。当其他应用访问该ExtensionAbility时，需要申请相应的权限信息。<br/>一个数组元素为一个权限名称。通常采用反向域名格式（最大255字节），可以是系统预定义的权限，也可以是该应用自定义的权限。如果是后者，需与defPermissions标签中定义的某个权限的name标签值一致。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| uri | 标识当前ExtensionAbility组件提供的数据URI，为字符数组类型（最大长度255），用反向域名的格式表示。<br/>**说明：**<br/>- 该标签在type为dataShare类型的ExtensionAbility时，不可缺省。 | 字符串 | 该标签可缺省，缺省值为空。 |
|skills | 标识当前ExtensionAbility组件能够接收的[Want](../application-models/want-overview.md)的特征集，为数组格式。<br/>配置规则：entry包可以配置多个具有入口能力的skills标签（配置了action.system.home和entity.system.home）的ExtensionAbility，其中第一个配置了skills标签的ExtensionAbility中的label和icon作为OpenHarmony服务或应用的label和icon。<br/>**说明：**<br/>- OpenHarmony服务的Feature包不能配置具有入口能力的skills标签。<br/>- OpenHarmony应用的Feature包可以配置具有入口能力的skills标签。 | 数组 | 该标签可缺省，缺省值为空。 |
| [metadata](#metadata标签) | 标识当前ExtensionAbility组件的元信息。 | 对象 | 该标签可缺省，缺省值为空。 |
| visible | 标识当前ExtensionAbility组件是否可以被其他应用调用，为布尔类型。<br/>-&nbsp;true：表示可以被其他应用调用。<br/>-&nbsp;false：表示不可以被其他应用调用。 | 布尔值 | 该标签可缺省，缺省值为false。 |

extensionAbilities示例：


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
      "uri":"scheme://authority/path/query",
      "skills": [{
        "actions": [],
        "entities": [],
        "uris": []
      }],
      "metadata": [
        {
          "name": "ohos.extension.form",
          "resource": "$profile:form_config", 
        }
      ]
    }
  ]
}
```


## requestPermissions标签

该标签标识应用运行时需向系统申请的权限集合。

  **表8** **requestPermissions标签说明**

| 属性 | 含义 | 类型 | 取值范围 | 默认值 |
| -------- | -------- | -------- | -------- | -------- |
| name | 必须，填写需要使用的权限名称。 | 字符串 | 自定义。 | 无。 |
| reason | 可选，当申请的权限为user_grant权限时此字段必填，用于描述申请权限的原因。<br/>**说明：**<br/>- 当申请的权限为user_grant权限时，如果未填写该字段则不允许在应用市场上架，并且需要进行多语种适配。 | 字符串 | 使用string类资源引用。格式为$string:&nbsp;\*\*\*。 | 空。 |
| usedScene | 可选，当申请的权限为user_grant权限时此字段必填。描述权限使用的场景由abilities和when组成。其中abilities可以配置为多个UIAbility组件，when表示调用时机。<br/>**说明：**<br/>- 默认为可选，当申请的权限为user_grant权限时，abilities标签必填，when标签可选。 | abilities：UIAbility或者ExtensionAbility名称的字符串数组<br/>when：字符串 | abilities：UIAbility或者ExtensionAbility组件的名称。<br/>when：inuse（使用时）、always（始终）。 | abilities：空。<br/>when：空。 |

requestPermissions示例：


```json
{
  "module" : {
    "requestPermissions": [
      {
        "name": "ohos.abilitydemo.permission.PROVIDER",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "EntryFormAbility"
          ],
          "when": "inuse"
        }
      }
    ]
  }
}
```


## shortcuts标签

shortcuts标识应用的快捷方式信息。标签值为数组，最多可以配置四个快捷方式。其包含四个子标签shortcutId、label、icon、wants。

metadata中指定shortcut信息，其中：

- name：指定shortcuts的名称。使用ohos.ability.shortcuts作为shortcuts信息的标识。

- resource：指定shortcuts信息的资源位置。
  
| 属性 | 含义 | 类型  | 默认值 |
| -------- | -------- | -------- | -------- |
| shortcutId | 标识快捷方式的ID。字符串的最大长度为63字节。 | 字符串 | 该标签不可缺省。 |
| label | 标识快捷方式的标签信息，即快捷方式对外显示的文字描述信息。取值可以是描述性内容，也可以是标识label的资源索引。字符串最大长度为255字节。 | 字符串 | 该标签可缺省，缺省值为空。 |
| icon | 标识快捷方式的图标，标签值为资源文件的索引。 | 字符串 | 该标签可缺省，缺省值为空。 |
| [wants](../application-models/want-overview.md) | 标识快捷方式内定义的目标wants信息集合，每个wants可配置bundleName和abilityName两个子标签。<br/>bundleName：表示快捷方式的目标包名，字符串类型。<br/>abilityName：表示快捷方式的目标组件名，字符串类型。 | 对象 | 该标签可缺省，缺省为空。 |


1. 在/resource/base/profile/目录下配置shortcuts_config.json配置文件。
   
   ```json
   {
     "shortcuts": [
       {
         "shortcutId": "id_test1",
         "label": "$string:shortcut",
         "icon": "$media:aa_icon",
         "wants": [
           {
             "bundleName": "com.ohos.hello",
             "abilityName": "EntryAbility"
           }
         ]
       }
     ]
   }
   ```

2. 在module.json5配置文件的abilities标签中，针对需要添加快捷方式的UIAbility进行配置metadata标签，使shortcut配置文件对该UIAbility生效。
   
   ```json
   {
     "module": {
       // ...
       "abilities": [
         {
           "name": "EntryAbility",
           "srcEntrance": "./ets/entryability/EntryAbility.ts",
           // ...
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


## distroFilter标签

该标签下的子标签均为可选字段，在应用市场云端分发时做精准匹配使用，distroFilter用于定义HAP对应的细分设备规格的分发策略，以便在应用市场进行云端分发应用包时做精准匹配。该标签可配置的分发策略维度包括API Version、屏幕形状、屏幕尺寸、屏幕分辨率，设备的国家与地区码。在进行分发时，通过deviceType与这五个属性的匹配关系，唯一确定一个用于分发到设备的HAP。该标签需要配置在/resource/profile资源目录下。

  **表9** **distroFilter标签配置说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| apiVersion | 标识支持的apiVersion范围。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| screenShape | 标识屏幕形状的支持策略。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| screenWindow | 标识应用运行时窗口的分辨率支持策略。该字段仅支持对轻量级智能穿戴设备进行配置。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| screenDensity | 标识屏幕的像素密度（dpi：Dot&nbsp;Per&nbsp;Inch）。该字段可选，如果配置了该字段，取值必须合法。该标签为字符串数组，字符串范围如下。<br/>-&nbsp;sdpi：表示小规模的屏幕密度（Small-scale&nbsp;Dots&nbsp;per&nbsp;Inch），适用于dpi取值为(0,120]的设备。<br/>-&nbsp;mdpi：表示中规模的屏幕密度（Medium-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(120,160]的设备。<br/>-&nbsp;ldpi：表示大规模的屏幕密度（Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(160,240]的设备。<br/>-&nbsp;xldpi：表示大规模的屏幕密度（Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(240,320]的设备。<br/>-&nbsp;xxldpi：表示大规模的屏幕密度（Extra&nbsp;Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(320，480]的设备。<br/>-&nbsp;xxxldpi：表示大规模的屏幕密度（Extra&nbsp;Extra&nbsp;Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(480,&nbsp;640]的设备。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| countryCode | 表示应用需要分发的国家地区码，具体值以[ISO-3166-1](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/basic-resource-file-categories-0000001052066099)标准为准。支持多个国家和地区枚举定义。 | 对象数组 | 该标签可缺省，缺省值为空。 |

  **表10** **apiVersion标签说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 该标签不可缺省。 |
| value | 支持的取值为API&nbsp;Version存在的整数值，例如4、5、6。场景示例：某应用，针对相同设备型号，同时在网的为使用API&nbsp;5和API&nbsp;6开发的两个软件版本，则允许上架2个entry类型的安装包，分别支持到对应设备侧软件版本的分发。 | 数组 | 该标签不可缺省。 |

  **表11** **screenShape对象的内部结构**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 该标签不可缺省。 |
| value | 支持的取值为circle（圆形）、rect（矩形）。场景示例：针对智能穿戴设备，可为圆形表盘和矩形表盘分别提供不同的HAP。 | 字符串数组 | 该标签不可缺省。 |

  **表12** **screenWindow对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示该字段取值不包含value枚举值匹配规则的匹配该属性。<br/>-&nbsp;include：表示该字段取值满足value枚举值匹配规则的匹配该属性。 | 字符串 | 该标签不可缺省。 |
| value | 单个字符串的取值格式为“宽&nbsp;\*&nbsp;高”，取值为整数像素值，例如“454&nbsp;\*&nbsp;454”。 | 字符串数组 | 该标签不可缺省。 |

  **表13** **screenDensity对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 该标签不可缺省。 |
| value | 该标签标识屏幕的像素密度（dpi&nbsp;:Dot&nbsp;Per&nbsp;Inch）。 | 字符串数组 | 该标签不可缺省。 |

  **表14** **countryCode对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 该标签不可缺省。 |
| value | 标识应用需要分发的国家地区码。 | 字符串数组 | 该标签不可缺省。 |

在开发视图的resources/base/profile下面定义配置文件distro_filter_config.json，文件名可以自定义。


```json
{
  "distroFilter": {
    "apiVersion": {
      "policy": "include",
      "value": [
        3,
        4
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
    "countryCode": { // 支持中国和香港地区分发
      "policy": "include",
      "value": [
        "CN",
        "HK"
      ]
    }
  }
}
```

在module.json5配置文件的module标签中定义metadata信息。


```json
{
  "module": {
    // ...
    "metadata": [
      {
        "name": "ohos.module.distro",
        "resource": "$profile:distro_filter_config",
      }
    ]
  }
}
```


## testRunner标签

此标签用于支持对测试框架的配置。

  **表15** **testRunner标签说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识测试框架对象名称。该标签最大字节长度为255个字节。 | 字符串 | 不可缺省。 |
| srcPath | 标识测试框架代码路径。该标签最大字节长度为255个字节。 | 字符串 | 不可缺省。 |

testRunner标签示例：


```json
{
  "module": {
    // ...
    "testRunner": {
      "name": "myTestRunnerName",
      "srcPath": "etc/test/TestRunner.ts"
    }
  }
}
```
