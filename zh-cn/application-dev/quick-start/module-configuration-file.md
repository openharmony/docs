# module.json5配置文件

## 配置文件示例

先通过一个示例，整体认识一下module.json5配置文件。
<!--RP1-->
```json
{
  "module": {
    "name": "entry",
    "type": "entry",
    "description": "$string:module_desc",
    "srcEntry": "./ets/entryability/EntryAbility.ets",
    "mainElement": "EntryAbility",
    "deviceTypes": [
      "default",
      "tablet"
    ],
    "deliveryWithInstall": true,
    "installationFree": false,
    "pages": "$profile:main_pages",
    "virtualMachine": "ark",
    "appStartup": "$profile:app_startup_config",
    "metadata": [
      {
        "name": "string",
        "value": "string",
        "resource": "$profile:distributionFilter_config"
      }
    ],
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ets",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:layered_image",
        "label": "$string:EntryAbility_label",
        "startWindow": "$profile:start_window",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "exported": true,
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
        "continueType": [
          "continueType1"
        ],
        "continueBundleName": [
          "com.example.myapplication1",
          "com.example.myapplication2"
        ]
      }
    ],
    "definePermissions": [
      {
        "name": "ohos.abilitydemo.permission.PROVIDER",
        "grantMode": "system_grant",
        "availableLevel": "system_core",
        "provisionEnable": true,
        "distributedSceneEnable": false,
        "label": "$string:EntryAbility_label"
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
    ],
    "targetModuleName": "feature",
    "targetPriority": 50,
    "querySchemes": [
      "app1Scheme",
      "app2Scheme"
    ],
    "routerMap": "$profile:router_map",
    "appEnvironments": [
      {
        "name": "name1",
        "value": "value1"
      }
    ],
    "hnpPackages": [
      {
        "package": "hnpsample.hnp",
        "type": "public"
      }
    ],
    "fileContextMenu": "$profile:menu"
  }
}
```
<!--RP1End-->

## 配置文件标签

module.json5配置文件包含以下标签。


  **表1** module.json5配置文件标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识当前Module的名称，确保该名称在整个应用中唯一。命名规则如下&nbsp;：<br/>-&nbsp;由字母、数字和下划线组成，且必须以字母开头。<br/>-&nbsp;最大长度31字节。<br/>应用升级时允许修改该名称，但需要应用适配Module相关数据目录的迁移，详见[文件管理接口](../reference/apis-core-file-kit/js-apis-file-fs.md#fscopydir10)。 | 字符串 | 该标签不可缺省。 |
| type | 标识当前Module的类型。支持的取值如下：<br/>-&nbsp;entry：应用的主模块。<br/>-&nbsp;feature：应用的动态特性模块。<br/>-&nbsp;har：静态共享包模块。<br/>-&nbsp;shared：动态共享包模块。 | 字符串 | 该标签不可缺省。 |
| srcEntry | 标识当前Module所对应的代码路径，取值为长度不超过127字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| description | 标识当前Module的描述信息，取值为长度不超过255字节的字符串，可以采用字符串资源索引格式。 | 字符串 | 该标签可缺省，缺省值为空。 |
| <!--DelRow-->process | 标识当前Module的进程名，取值为长度不超过31字节的字符串。如果在HAP标签下配置了process，则该Module的所有UIAbility、DataShareExtensionAbility、ServiceExtensionAbility都运行在该进程中。<br/>**说明：**<br/>开启[多实例特权](../../device-dev/subsystems/subsys-app-privilege-config-guide.md#可由设备厂商配置的特权)生效，三方应用配置不生效。 | 字符串 | 该标签可缺省，缺省为app.json5文件下app标签下的bundleName。 |
| mainElement | 标识当前Module的入口UIAbility名称或者ExtensionAbility名称，取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| [deviceTypes](#devicetypes标签) | 标识当前Module可以运行在哪类设备上。<br/>**说明：**<br/>当存在多个模块时，各模块中的配置可以不一致，但必须包含所需的设备类型以确保正常运行。 | 字符串数组 | 该标签不可缺省。 |
| deliveryWithInstall | 标识当前Module是否在用户主动安装的时候安装，即该Module对应的HAP是否跟随应用一起安装。<br/>-&nbsp;true：主动安装时安装。<br/>-&nbsp;false：主动安装时不安装。 | 布尔值 | 该标签不可缺省。 |
| installationFree | 标识当前Module是否支持免安装特性。<br/>-&nbsp;true：表示支持免安装特性，且符合免安装约束。<br/>-&nbsp;false：表示不支持免安装特性。<br/>**说明：**<br/>当[bundleType](./app-configuration-file.md#配置文件标签)为原子化服务时，该字段需要配置为true。反之，该字段需要配置为false。 | 布尔值 | 该标签不可缺省。 |
| virtualMachine | 标识当前Module运行的目标虚拟机类型，供云端分发使用，如应用市场和分发中心。如果目标虚拟机类型为ArkTS引擎，则其值为“ark+版本号”。 | 字符串 | 该标签由IDE构建HAP的时候自动插入。 |
| [pages](#pages标签) | 标识当前Module的profile资源，用于列举每个页面信息，取值为长度不超过255字节的字符串。 | 字符串 | 在有UIAbility的场景下，该标签不可缺省。 |
| [metadata](#metadata标签) | 标识当前Module的自定义元信息，可通过资源引用的方式配置[distributionFilter](#distributionfilter标签)、[shortcuts](#shortcuts标签)等信息。只对当前Module、UIAbility、ExtensionAbility生效。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [abilities](#abilities标签) | 标识当前Module中UIAbility的配置信息，只对当前UIAbility生效。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [extensionAbilities](#extensionabilities标签) | 标识当前Module中ExtensionAbility的配置信息，只对当前ExtensionAbility生效。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [definePermissions](#definepermissions标签) | 标识系统资源hap定义的权限，不支持应用自定义权限。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [requestPermissions](../security/AccessToken/declare-permissions.md#在配置文件中声明权限)| 标识当前应用运行时需向系统申请的权限集合。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [testRunner](#testrunner标签) | 标识用于测试当前Module的测试框架的配置。 | 对象 | 该标签可缺省，缺省值为空。 |
| [atomicService](#atomicservice标签)| 标识当前应用是原子化服务时，有关原子化服务的相关配置。| 对象 | 该标签可缺省，缺省值为空。  |
| [dependencies](#dependencies标签)| 标识当前模块运行时依赖的共享库列表。| 对象数组 | 该标签可缺省，缺省值为空。  |
| targetModuleName | 标识当前包所指定的目标module，确保该名称在整个应用中唯一。取值为长度不超过31字节的字符串，不支持中文。配置该字段的Module具有overlay特性。仅在动态共享包（HSP）中适用。 |字符串|该标签可缺省，缺省值为空。|
| targetPriority | 标识当前Module的优先级，取值范围为1~100。配置targetModuleName字段之后，才需要配置该字段。仅在动态共享包（HSP）中适用。 |整型数值|该标签可缺省，缺省值为1。|
| [proxyData](#proxydata标签) | 标识当前Module提供的数据代理列表。| 对象数组 | 该标签可缺省，缺省值为空。|
| isolationMode | 标识当前Module的多进程配置项。支持的取值如下：<br/>-&nbsp;nonisolationFirst：优先在非独立进程中运行。<br/>-&nbsp;isolationFirst：优先在独立进程中运行。<br/>-&nbsp;isolationOnly：只在独立进程中运行。<br/>-&nbsp;nonisolationOnly：只在非独立进程中运行。 |字符串|该标签可缺省，缺省值为nonisolationFirst。|
| generateBuildHash |标识当前HAP/HSP是否由打包工具生成哈希值。当配置为true时，如果系统OTA升级时应用versionCode保持不变，可根据哈希值判断应用是否需要升级。<br/>该字段仅在[app.json5文件](./app-configuration-file.md)中的generateBuildHash字段为false时使能。<br/>**说明：**<br/>该字段仅对预置应用生效。|布尔值|该标签可缺省，缺省值为false。|
| compressNativeLibs | 在打包hap时，该字段标识libs库是否以压缩存储的方式打包到HAP。<br/>-&nbsp;true：libs库以压缩方式存储。<br/>-&nbsp;false：libs库以不压缩方式存储。<br>在应用安装时，该字段用于标识libs库是否需要解压出来（API16及之后版本支持，之前的版本均默认解压libs库）。<br/>-&nbsp;true：libs库会解压出来。<br/>-&nbsp;false：libs库不会解压出来。 | 布尔值 | 该标签可缺省，在打包hap时缺省值为false。在安装应用时，该字段未配置时默认为true。 |
| libIsolation | 用于区分同应用不同HAP下的.so文件，以防止.so冲突。<br/>-&nbsp;true：当前HAP的.so文件会储存在libs目录中以Module名命名的路径下。<br/>-&nbsp;false：当前HAP的.so文件会直接储存在libs目录中。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| fileContextMenu | 标识当前HAP的右键菜单配置项。取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| querySchemes | 标识允许当前应用进行跳转查询的URL schemes，只允许entry类型模块配置，最多50个，每个字符串取值不超过128字节。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| [routerMap](#routermap标签) | 标识当前模块配置的路由表路径。取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| [appEnvironments](#appenvironments标签) | 标识当前模块配置的应用环境变量，只允许entry和feature模块配置。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| appStartup | 标识当前Module启动框架配置路径，在Entry类型的HAP、HSP、HAR中生效。 | 字符串 | 该标签可缺省，缺省值为空。 |
| [hnpPackages](#hnppackages标签) | 标识当前应用包含的Native软件包信息。只允许entry类型模块配置。 | 对象数组 | 该标签可缺省，缺省值为空。 |

## deviceTypes标签

  **表2** deviceTypes标签说明
<!--RP2-->
| 设备类型 | 枚举值 | 说明 |
| -------- | -------- | -------- |
| 平板 | tablet | - |
| 智慧屏 | tv | - |
| 智能手表 | wearable | 系统能力较丰富的手表，具备电话功能。 |
| 车机 | car | - |
| 2in1 | 2in1 | 融合了屏幕触控和键鼠操作的二合一设备。 |
| 默认设备 | default | 能够使用全部系统能力的设备。 |
<!--RP2End-->

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

在开发视图的resources/base/profile下面定义配置文件main_pages.json，其中文件名"main_pages"可自定义，需要和pages标签指定的信息对应。配置文件中列举了当前应用组件中的页面信息，包含页面的路由信息和显示窗口相关的配置。

  **表3** pages标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| src | 标识当前Module中所有页面的路由信息，包括页面路径和页面名称。其中，页面路径是以当前Module的src/main/ets为基准。该标签取值为一个字符串数组，其中每个元素表示一个页面。 | 字符串数组 | 该标签不可缺省。 |
| window | 标识用于定义与显示窗口相关的配置。	 | 对象 | 该标签可缺省，缺省值为空。 |


  **表4** window标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| designWidth | 标识页面设计基准宽度。以此为基准，根据实际设备宽度来缩放元素大小。 | 数值 | 可缺省，缺省值为720px。 |
| autoDesignWidth | 标识页面设计基准宽度是否自动计算。当配置为true时，designWidth将会被忽略，设计基准宽度由设备宽度与屏幕密度计算得出。 | 布尔值 | 可缺省，缺省值为false。 |

```json
{
  "src": [
    "pages/index/mainPage",
    "pages/second/payment",
    "pages/third/shopping_cart",
    "pages/four/owner"
  ],
  "window": {
    "designWidth": 720,
    "autoDesignWidth": false
  }
}
```


## metadata标签

该标签标识HAP的自定义元信息，标签值为数组类型，包含name、value、resource三个子标签。

**表5** metadata标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识数据项的名称，取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| value | 标识数据项的值，取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| resource | 标识定义用户自定义数据格式，取值为长度不超过255字节的字符串，内容为标识该数据的资源索引。| 字符串 | 该标签可缺省，缺省值为空。 |

metadata标签可配置主窗的默认大小和位置（单位为vp），name为ohos.ability.window.height表示主窗默认高度，name为ohos.ability.window.width表示主窗默认宽度，name为ohos.ability.window.left表示主窗默认左边的位置，其配置格式为(对齐方式)(+|-偏移量)，对齐方式包括center、left和right，默认值为left，偏移量为0时可以省略，name为ohos.ability.window.top表示主窗顶部的位置，对齐方式包括center、top和bottom，默认值为top，两者同时省略按照系统默认层叠规格。

metadata标签可配置使能移除启动页功能，name为enable.remove.starting.window，value可配置为true/false，未配置则默认为false。

resource属性值使用“\$profile:文件名”的方式指定文件所在位置，\$profile表示资源的路径为工程中的/resources/base/profile目录下。例如\$profile:shortcuts_config指定了/resources/base/profile/shortcuts_config.json配置文件。

```json
{
  "module": {
    "metadata": [{
      "name": "module_metadata",
      "value": "a test demo for module metadata",
      "resource": "$profile:shortcuts_config"
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
      },
      {
        "name": "ohos.ability.window.height",
        "value": "987"
      },
      {
        "name": "ohos.ability.window.width",
        "value": "1300"
      },
      {
        "name": "ohos.ability.window.left",
        "value": "right-50"
      },
      {
        "name": "ohos.ability.window.top",
        "value": "center+50"
      },
      {
        "name": "enable.remove.starting.window",
        "value": "true"
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

abilities标签描述UIAbility组件的配置信息，标签值为数组类型，该标签下的配置只对当前UIAbility生效。

  **表6** abilities标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识当前UIAbility组件的名称，确保该名称在整个应用中唯一。取值为长度不超过127字节的字符串，不支持中文。 | 字符串 | 该标签不可缺省。 |
| srcEntry | 标识入口UIAbility的代码路径，取值为长度不超过127字节的字符串。 | 字符串 | 该标签不可缺省。 |
| [launchType](../application-models/uiability-launch-type.md) | 标识当前UIAbility组件的启动模式，支持的取值如下：<br/>-&nbsp;multiton：多实例模式，每次启动创建一个新实例。<br/>-&nbsp;singleton：单实例模式，仅第一次启动创建新实例。<br/>-&nbsp;specified：指定实例模式，运行时由开发者决定是否创建新实例。<br/>-&nbsp;standard：multiton的曾用名，效果与多实例模式一致。 | 字符串 | 该标签可缺省，该标签缺省为“singleton”。 |
| description | 标识当前UIAbility组件的描述信息，取值为长度不超过255字节的字符串。要求采用描述信息的资源索引，以支持多语言。 | 字符串 | 该标签可缺省，缺省值为空。 |
| icon | 标识当前UIAbility组件的[图标](../application-models/application-component-configuration-stage.md#生成机制)，取值为图标资源文件的索引。 | 字符串 | 该标签可缺省，缺省值为空。 |
| label | 标识当前UIAbility组件对用户显示的[名称](../application-models/application-component-configuration-stage.md#生成机制)，要求采用该名称的资源索引，以支持多语言。取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| permissions | 标识当前UIAbility组件自定义的权限信息。当其他应用访问该UIAbility时，需要申请相应的权限信息。<br/>一个数组元素为一个权限名称。通常采用反向域名格式（不超过255字节），取值为系统预定义的权限。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| [metadata](#metadata标签) | 标识当前UIAbility组件的元信息。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| exported | 标识当前UIAbility组件是否可以被其他应用调用。<br/>-&nbsp;true：表示可以被其他应用调用。<br/>-&nbsp;false：表示不可以被其他应用调用，包括无法被aa工具命令拉起应用。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| continuable | 标识当前UIAbility组件是否支持跨端迁移。<br/>-&nbsp;true：表示支持迁移。<br/>-&nbsp;false：表示不支持迁移。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| [skills](#skills标签) | 标识当前UIAbility组件或ExtensionAbility组件能够接收的[Want](../application-models/want-overview.md)特征集，为数组格式。<br/>配置规则：<br/>-&nbsp;对于Entry类型的HAP，应用可以配置多个具有入口能力的skills标签（即配置了ohos.want.action.home和entity.system.home）。<br/>-&nbsp;对于Feature类型的HAP，只有应用可以配置具有入口能力的skills标签，服务不允许配置。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| backgroundModes | 标识当前UIAbility组件的长时任务集合，指定用于满足特定类型的长时任务。<br/>长时任务类型有如下：<br/>-&nbsp;dataTransfer：通过网络/对端设备进行数据下载、备份、分享、传输等。<br/>-&nbsp;audioPlayback：音频播放。<br/>-&nbsp;audioRecording：录音。<br/>-&nbsp;location：定位、导航。<br/>-&nbsp;bluetoothInteraction：蓝牙扫描、连接、传输（穿戴）。<br/>-&nbsp;multiDeviceConnection：多设备互联。<br/>-&nbsp;taskKeeping：计算。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| [startWindow](#startwindow标签) | 标识当前UIAbility组件启动页面profile资源，取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| startWindowIcon | 标识当前UIAbility组件启动页面图标资源文件的索引，取值为长度不超过255字节的字符串。 | 字符串 | 该标签不可缺省。 |
| startWindowBackground | 标识当前UIAbility组件启动页面背景颜色资源文件的索引，取值为长度不超过255字节的字符串。<br/>取值示例：$color:red。| 字符串 | 该标签不可缺省。 |
| removeMissionAfterTerminate | 标识当前UIAbility组件销毁后，是否从任务列表中移除任务。<br/>-&nbsp;true表示销毁后移除任务。<br/>-&nbsp;false表示销毁后不移除任务。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| orientation | 标识当前UIAbility组件启动时的方向，支持配置枚举和启动方向资源索引。枚举支持的取值如下：<br/>-&nbsp;unspecified：未指定方向，由系统自动判断显示方向。<br/>-&nbsp;landscape：横屏。<br/>-&nbsp;portrait：竖屏。<br/>-&nbsp;follow_recent：跟随背景窗口的旋转模式。<br/>-&nbsp;landscape_inverted：反向横屏。<br/>-&nbsp;portrait_inverted：反向竖屏。<br/>-&nbsp;auto_rotation：随传感器旋转。<br/>-&nbsp;auto_rotation_landscape：传感器横屏旋转，包括横屏和反向横屏。<br/>-&nbsp;auto_rotation_portrait：传感器竖屏旋转，包括竖屏和反向竖屏。<br/>-&nbsp;auto_rotation_restricted：传感器开关打开，方向可随传感器旋转。<br/>-&nbsp;auto_rotation_landscape_restricted：传感器开关打开，方向可随传感器旋转为横屏，&nbsp;包括横屏和反向横屏。<br/>-&nbsp;auto_rotation_portrait_restricted：传感器开关打开，方向随可传感器旋转为竖屏，&nbsp;包括竖屏和反向竖屏。<br/>-&nbsp;locked：传感器开关关闭，方向锁定。<br/>-&nbsp;auto_rotation_unspecified：受开关控制和由系统判定的自动旋转模式。<br/>-&nbsp;follow_desktop：跟随桌面的旋转模式。<br/>&nbsp;配置启动方向的资源索引时，取值为长度不超过255字节的字符串。<br/>&nbsp;启动方向资源索引配置示例：$string:orientation。 | 字符串 | 该标签可缺省，缺省值为unspecified。 |
| supportWindowMode | 标识当前UIAbility组件所支持的窗口模式。支持的取值如下：<br/>-&nbsp;fullscreen：全屏模式。<br/>-&nbsp;split：分屏模式。<br/>-&nbsp;floating：悬浮窗模式。 | 字符串数组 | 该标签可缺省，缺省值为<br/>["fullscreen",&nbsp;"split",&nbsp;"floating"]。 |
| <!--DelRow-->priority | 标识当前UIAbility组件的优先级。[隐式查询](../application-models/explicit-implicit-want-mappings.md)时，优先级越高，UIAbility在返回列表越靠前。取值范围0~10，数值越大，优先级越高。<br/>**说明：**<br/>三方应用的配置不生效，当前配置仅在系统应用中有效。 | 整型数值 | 该标签可缺省，缺省值为0。 |
| maxWindowRatio | 标识当前UIAbility组件支持的最大的宽高比。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最大的宽高比。 |
| minWindowRatio | 标识当前UIAbility组件支持的最小的宽高比。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最小的宽高比。 |
| maxWindowWidth | 标识当前UIAbility组件支持的最大的窗口宽度，宽度单位为vp。<br/>最小取值为minWindowWidth，最大取值为平台支持的最大窗口宽度。窗口尺寸可以参考[窗口大小限制](../windowmanager/window-overview.md#约束与限制)。 | 数值 | 该标签可缺省，缺省值为平台支持的最大的窗口宽度。 |
| minWindowWidth | 标识当前UIAbility组件支持的最小的窗口宽度，&nbsp;宽度单位为vp。<br/>最小取值为平台支持的最小窗口宽度，最大取值为maxWindowWidth。窗口尺寸可以参考[窗口大小限制](../windowmanager/window-overview.md#约束与限制)。 | 数值 | 该标签可缺省，缺省值为平台支持的最小的窗口宽度。 |
| maxWindowHeight | 标识当前UIAbility组件支持的最大的窗口高度，&nbsp;高度单位为vp。<br/>最小取值为minWindowHeight，最大取值为平台支持的最大窗口高度。 窗口尺寸可以参考[窗口大小限制](../windowmanager/window-overview.md#约束与限制)。| 数值 | 该标签可缺省，缺省值为平台支持的最大的窗口高度。 |
| minWindowHeight | 标识当前UIAbility组件支持的最小的窗口高度，&nbsp;高度单位为vp。<br/>最小取值为平台支持的最小窗口高度，最大取值为maxWindowHeight。窗口尺寸可以参考[窗口大小限制](../windowmanager/window-overview.md#约束与限制)。| 数值 | 该标签可缺省，缺省值为平台支持的最小的窗口高度。 |
| <!--DelRow-->excludeFromMissions | 标识当前UIAbility组件是否在最近任务列表中显示。<br/>-&nbsp;true：表示不在任务列表中显示。<br/>-&nbsp;false：表示在任务列表中显示。<br/>**说明：**<br/>三方应用的配置不生效，当前配置仅在系统应用中有效，若要使系统应用配置生效，需申请应用特权AllowAbilityExcludeFromMissions，详见[应用特权配置指导](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)。| 布尔值 | 该标签可缺省，缺省值为false。 |
| recoverable | 标识当前UIAbility组件是否支持在检测到应用故障后，恢复到应用原界面。<br/>-&nbsp;true：支持检测到出现故障后，恢复到原界面。<br/>-&nbsp;false：不支持检测到出现故障后，恢复到原界面。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| <!--DelRow-->unclearableMission | 标识当前UIAbility组件是否支持从最近任务列表中移除。<br/>-&nbsp;true：表示在任务列表中不可移除。<br/>-&nbsp;false：表示在任务列表中可以移除。<br/>**说明：**<br/>三方应用的配置不生效，当前配置仅在系统应用中有效，若要使系统应用配置生效，需申请应用特权AllowMissionNotCleared，详见[应用特权配置指导](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| isolationProcess | 标识组件能否运行在独立的进程中。<br/>-&nbsp;true：表示能运行在独立的进程中。<br/>-&nbsp;false：表示不能运行在独立的进程中。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| excludeFromDock | 标识当前UIAbility组件是否支持从dock区域隐藏图标。<br/>-&nbsp;true：表示在dock区域隐藏。<br/>-&nbsp;false：表示不能在dock区域隐藏。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| preferMultiWindowOrientation | 标识当前UIAbility组件多窗布局方向：<br/>-&nbsp;default：缺省值，参数不配置默认值，建议其他应用类配置。<br/>-&nbsp;portrait：多窗布局方向为竖向，建议竖向游戏类应用配置。<br/>-&nbsp;landscape：多窗布局方向为横向，配置后支持横屏悬浮窗和上下分屏，建议横向游戏类应用配置。<br/>-&nbsp;landscape_auto：多窗布局动态可变为横向，需要配合API enableLandScapeMultiWindow/disableLandScapeMultiWindow使用，建议视频类应用配置。 | 字符串 | 该标签可缺省，缺省值为default。 |
| continueType | 标识当前UIAbility组件的跨端迁移类型。 | 字符串数组 | 该标签可缺省，缺省值为当前组件的名称。 |
| continueBundleName | 标识当前应用支持跨端迁移的其它应用名称列表。<br/>**说明：**<br/>不能配置为本应用包名，仅为了做异包名迁移使用。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| process | 标识组件的进程标签。<br/>**说明：**<br/>仅在[2in1](./module-configuration-file.md#devicetypes标签)设备上生效，UIAbility组件和type为embeddedUI的ExtensionAbility组件标签一致时运行在同一个进程中。 | 字符串 | 该标签可缺省，缺省值为空。 |

abilities示例：

<!--RP3-->
```json
{
  "abilities": [{
    "name": "EntryAbility",
    "srcEntry": "./ets/entryability/EntryAbility.ets",
    "launchType":"singleton",
    "description": "$string:description_main_ability",
    "icon": "$media:layered_image",
    "label": "Login",
    "permissions": [],
    "metadata": [],
    "exported": true,
    "continuable": true,
    "skills": [{
      "actions": ["ohos.want.action.home"],
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
    "orientation": "$string:orientation",
    "supportWindowMode": ["fullscreen", "split", "floating"],
    "maxWindowRatio": 3.5,
    "minWindowRatio": 0.5,
    "maxWindowWidth": 2560,
    "minWindowWidth": 1400,
    "maxWindowHeight": 300,
    "minWindowHeight": 200,
    "excludeFromMissions": false,
    "unclearableMission": false,
    "excludeFromDock": false,
    "preferMultiWindowOrientation": "default",
    "isolationProcess": false,
    "continueType": [
      "continueType1",
      "continueType2"
    ],
    "continueBundleName": [
      "com.example.myapplication1",
      "com.example.myapplication2"
    ],
    "process": ":processTag"
  }]
}
```
<!--RP3End-->

## skills标签

该标签标识UIAbility组件或者ExtensionAbility组件能够接收的[Want](../application-models/want-overview.md)的特征。

  **表7** skills标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| actions | 标识能够接收的Action值集合，取值通常为系统预定义的action值，也允许自定义。<br>一个skill中不建议配置多个action，否则可能导致无法匹配预期场景。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| entities | 标识能够接收的Entity值的集合。<br>一个skill中不建议配置多个entity，否则可能导致无法匹配预期场景。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| uris | 标识与Want中URI（Uniform&nbsp;Resource&nbsp;Identifier）相匹配的集合。数组允许的最大数量为512。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| permissions | 标识当前UIAbility组件自定义的权限信息。当其他应用访问该UIAbility时，需要申请相应的权限信息。<br/>一个数组元素为一个权限名称。通常采用反向域名格式（不超过255字节），取值为系统预定义的权限。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| domainVerify | 标识是否开启域名校验。 | 布尔值 | 该标签可缺省，缺省值为false。 |


  **表8** uris标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| scheme | 标识URI的协议名部分，常见的有http、https、file、ftp等。<br/>**说明：**<br/>从API 16开始参与隐式Want匹配时该字段不区分大小写。 | 字符串 | uris中仅配置type时可以缺省，缺省值为空，否则不可缺省。 |
| host | 标识URI的主机地址部分，该字段在scheme存在时才有意义。常见的方式：<br/>-&nbsp;域名方式，如example.com。<br/>-&nbsp;IP地址方式，如10.10.10.1。<br/>**说明：**<br/>从API 16开始参与隐式Want匹配时该字段不区分大小写。 | 字符串 | 该标签可缺省，缺省值为空。 |
| port | 标识URI的端口部分。如http默认端口为80，https默认端口是443，ftp默认端口是21。该字段在scheme和host都存在时才有意义。 | 字符串 | 该标签可缺省，缺省值为空。 |
| path&nbsp;\|&nbsp;pathStartWith&nbsp;\|&nbsp;pathRegex | 标识URI的路径部分，path、pathStartWith和pathRegex配置时三选一。path标识URI与want中的路径部分全匹配，pathStartWith标识URI与want中的路径部分允许前缀匹配，pathRegex标识URI与want中的路径部分允许正则匹配。该字段在scheme和host都存在时才有意义。 | 字符串 | 该标签可缺省，缺省值为空。 |
| type | 标识与Want相匹配的数据类型，使用MIME（Multipurpose&nbsp;Internet&nbsp;Mail&nbsp;Extensions）类型规范和[UniformDataType](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md)类型规范。可与scheme同时配置，也可以单独配置。 | 字符串 | 该标签可缺省，缺省值为空。 |
| utd | 标识与Want相匹配的[标准化数据类型](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md)，适用于分享等场景。 | 字符串 | 该标签可缺省，缺省值为空。 |
| maxFileSupported | 对于指定类型的文件，标识一次能接收或打开的最大数量，适用于分享等场景，需要与utd配合使用。| 整数 | 该标签可缺省，缺省值为0。|
| linkFeature | 标识URI提供的功能类型（如文件打开、分享、导航等），用于实现应用间跳转。取值为长度不超过127字节的字符串，不支持中文。详情见[linkFeature标签说明](../application-models/app-uri-config.md#linkfeature标签说明)。 | 字符串 | 该标签可缺省，缺省值为空。|

skills示例：


```json
{
  "abilities": [
    {
      "skills": [
        {
          "actions": [
            "ohos.want.action.home"
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
              "type": "text/*",
              "linkFeature": "Login"
            }
          ],
          "permissions": [],
          "domainVerify": false
        }
      ]
    }
  ]
}
```

## extensionAbilities标签

描述extensionAbilities的配置信息，标签值为数组类型，该标签下的配置只对当前extensionAbilities生效。

  **表9** extensionAbilities标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识当前ExtensionAbility组件的名称，确保该名称在整个应用中唯一，取值为长度不超过127字节的字符串。 | 字符串 | 该标签不可缺省。 |
| srcEntry | 标识当前ExtensionAbility组件所对应的代码路径，取值为长度不超过127字节的字符串。 | 字符串 | 该标签不可缺省。 |
| description | 标识当前ExtensionAbility组件的描述，取值为长度不超过255字节的字符串，可以是对描述内容的资源索引，用于支持多语言。 | 字符串 | 该标签可缺省，缺省值为空。 |
| icon | 标识当前ExtensionAbility组件的图标，取值为资源文件的索引。如果ExtensionAbility组件被配置为MainElement，该标签必须配置。 | 字符串 | 该标签可缺省，缺省值为空。 |
| label | 标识当前ExtensionAbility组件对用户显示的名称，取值为该名称的资源索引，以支持多语言，字符串长度不超过255字节。如果ExtensionAbility被配置当前Module的mainElement时，该标签必须配置，且要确保应用内唯一。 | 字符串 | 该标签可缺省，缺省值为空。 |
| type | 标识当前ExtensionAbility组件的类型，支持的取值如下：<br/>-&nbsp;form：卡片的ExtensionAbility。<br/>-&nbsp;workScheduler：延时任务的ExtensionAbility。<br/>-&nbsp;inputMethod：输入法的ExtensionAbility。<!--Del--><br/>-&nbsp;service：后台运行的service组件。<!--DelEnd--><br/>-&nbsp;accessibility：辅助能力的ExtensionAbility。<!--Del--><br/>-&nbsp;fileAccess：公共数据访问的ExtensionAbility，允许应用程序提供文件和文件夹给文件管理类应用展示。<br/>-&nbsp;dataShare：数据共享的ExtensionAbility。<!--DelEnd--><br/>-&nbsp;staticSubscriber：静态广播的ExtensionAbility。<br/>-&nbsp;wallpaper：壁纸的ExtensionAbility。<br/>-&nbsp;backup：数据备份的ExtensionAbility。<br/>-&nbsp;window：该ExtensionAbility会在启动过程中创建一个window，为开发者提供界面开发。开发者开发出来的界面将通过UIExtensionComponent控件组合到其他应用的窗口中。<br/>-&nbsp;thumbnail：获取文件缩略图的ExtensionAbility，开发者可以对自定义文件类型的文件提供缩略。<br/>-&nbsp;preview：该ExtensionAbility会将文件解析后在一个窗口中显示，开发者可以通过将此窗口组合到其他应用窗口中。<br/>-&nbsp;print：打印框架的ExtensionAbility。<br/>-&nbsp;push：推送的ExtensionAbility。<br/>-&nbsp;driver：驱动框架的ExtensionAbility。<br/>-&nbsp;remoteNotification：远程通知的ExtensionAbility。<br/>-&nbsp;remoteLocation：远程定位的ExtensionAbility。<br/>-&nbsp;voip：网络音视频通话的ExtensionAbility。<br/>-&nbsp;action：自定义操作业务模板的ExtensionAbility，为开发者提供基于UIExtension的自定义操作业务模板。<!--Del--><br/>-&nbsp;adsService：广告业务的ExtensionAbility，提供广告业务框架。<!--DelEnd--><br/>-&nbsp;embeddedUI：嵌入式UI扩展能力，提供跨进程界面嵌入的能力。<br/>-&nbsp;insightIntentUI：为开发者提供能被小艺意图调用，以窗口形态呈现内容的扩展能力。<br/>-&nbsp;ads：广告业务的ExtensionAbility，与AdComponent控件组合使用，将广告页面展示到其他应用中。仅支持设备厂商使用。<br/>-&nbsp;photoEditor：图片编辑业务的ExtensionAbility，为开发者提供基于UIExtension的图片编辑业务模版。<br/>-&nbsp;appAccountAuthorization：应用账号授权扩展能力的ExtensionAbility，用于处理账号授权请求，比如账号登录授权。<br/>-&nbsp;autoFill/password：用于账号和密码自动填充业务的ExtensionAbility，支持数据的保存、填充能力。<br/>-&nbsp;hms/account：应用账号管理能力的ExtensionAbility。<!--Del--><br/>-&nbsp;sysDialog/atomicServicePanel：提供构建原子化服务服务面板的基础能力的ExtensionAbility，使用时基于UIExtensionAbility实现。<br/>-&nbsp;sysDialog/userAuth：本地用户鉴权的ExtensionAbility。<br/>-&nbsp;sysDialog/common：通用弹窗的ExtensionAbility。<br/>-&nbsp;sysDialog/power：关机重启弹窗的ExtensionAbility。<br/>-&nbsp;sysDialog/print：打印模态弹窗的ExtensionAbility。<br/>-&nbsp;sysDialog/meetimeCall：畅连通话的ExtensionAbility。<br/>-&nbsp;sysDialog/meetimeContact：畅连联系人的ExtensionAbility。<br/>-&nbsp;sysPicker/meetimeMessage：畅连消息的ExtensionAbility。<br/>-&nbsp;sysPicker/meetimeContact：畅连联系人列表的ExtensionAbility。<br/>-&nbsp;sysPicker/meetimeCallLog：畅连通话记录列表的ExtensionAbility。<br/>-&nbsp;sysPicker/share：系统分享的ExtensionAbility。<br/>-&nbsp;sysPicker/mediaControl：投播组件的ExtensionAbility。<br/>-&nbsp;sysPicker/photoPicker：三方应用通过对应的UIExtensionType拉起图库picker界面。<br/>-&nbsp;sysPicker/filePicker：文件下载弹窗的ExtensionAbility。<br/>-&nbsp;sysPicker/audioPicker：音频管理弹窗的ExtensionAbility。<br/>-&nbsp;sysPicker/photoEditor：图片编辑弹窗的ExtensionAbility。<br/>-&nbsp;sys/commonUI：非通用的ExtensionAbility，提供业务属性强相关的嵌入式显示或弹框。<!--DelEnd--><br/>-&nbsp;autoFill/smart：用于情景化场景自动填充业务的ExtensionAbility，支持数据的保存、填充能力。<br/>-&nbsp;uiService：弹窗服务组件，在启动过程中会创建window，并支持双向通信。<br/>-&nbsp;statusBarView：一步直达的ExtensionAbility。<br/>-&nbsp;recentPhoto：最近照片推荐的ExtensionAbility。<!--Del--><br/>-&nbsp;fence：地理围栏的ExtensionAbility。<br/>-&nbsp;callerInfoQuery：企业联系人查询的ExtensionAbility。<br/>-&nbsp;assetAcceleration：资源预下载的ExtensionAbility。<br/>-&nbsp;formEdit：卡片编辑的ExtensionAbility。<br/>**说明：**<br/>其中service、adsService、sys/commonUI、fileAccess、sysDialog类型、sysPicker类型、dataShare类型和uiService类型，三方应用的配置不生效，当前配置仅在系统应用中有效。<!--DelEnd--> | 字符串 | 该标签不可缺省。 |
| permissions | 标识当前ExtensionAbility组件自定义的权限信息。当其他应用访问该ExtensionAbility时，需要申请相应的权限信息。<br/>一个数组元素为一个权限名称。通常采用反向域名格式（最大255字节），取值为[系统预定义的权限](../security/AccessToken/app-permissions.md)。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| readPermission | 标识读取当前ExtensionAbility组件数据所需的权限，取值为长度不超过255字节的字符串。仅当ExtensionAbility组件的type为dataShare时支持配置该标签。 | 字符串 | 该标签可缺省，缺省值为空。 |
| writePermission | 标识向当前ExtensionAbility组件写数据所需的权限，取值为长度不超过255字节的字符串。仅当ExtensionAbility组件的type为dataShare时支持配置该标签。 | 字符串 | 该标签可缺省，缺省值为空。 |
| uri | 标识当前ExtensionAbility组件提供的数据URI，取值为长度不超过255字节的字符数组，用反向域名的格式表示。<br/>**说明：**<br/>该标签在type为dataShare类型的ExtensionAbility时，不可缺省。 | 字符串 | 该标签可缺省，缺省值为空。 |
|skills | 标识当前ExtensionAbility组件能够接收的[Want](../application-models/want-overview.md)的特征集。<br/>配置规则：entry包可以配置多个具有入口能力的skills标签（配置了ohos.want.action.home和entity.system.home）的ExtensionAbility，其中第一个配置了skills标签的ExtensionAbility中的label和icon作为服务或应用的label和icon。<br/>**说明：**<br/>服务的Feature包不能配置具有入口能力的skills标签。<br/>应用的Feature包可以配置具有入口能力的skills标签。 | 数组 | 该标签可缺省，缺省值为空。 |
| [metadata](#metadata标签) | 标识当前ExtensionAbility组件的元信息。<br/>**说明：**<br/>该标签在type为form时，不可缺省，且必须存在一个name为ohos.extension.form的对象值，其对应的resource值不能缺省，为卡片的二级资源引用。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| exported | 标识当前ExtensionAbility组件是否可以被其他应用调用。<br/>-&nbsp;true：表示可以被其他应用调用。<br/>-&nbsp;false：表示不可以被其他应用调用，包括无法被aa工具命令拉起应用。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| extensionProcessMode | 标识当前ExtensionAbility组件的多进程实例模型,当前只对UIExtensionAbility以及从UIExtensionAbility扩展的ExtensionAbility生效。<br/>-&nbsp;instance：表示该ExtensionAbility每个实例一个进程。<br/>-&nbsp;type：表示该ExtensionAbility实例都运行在同一个进程里，与其他ExtensionAbility分离进程。<br/>-&nbsp;bundle：表示该ExtensionAbility实例都运行在应用统一进程里，与其他配置了bundle模型的ExtensionAbility共进程。<br>-&nbsp;runWithMainProcess：表示该ExtensionAbility和应用主进程共进程，只有一步直达的ExtensionAbility可以配置runWithMainProcess。 | 字符串 | 该标签可缺省，缺省值为空。 |
| dataGroupIds | 标识当前ExtensionAbility组件的dataGroupId集合。如果当前ExtensionAbility组件所在的应用在应用市场申请的证书里groupIds也申请了某个dataGroupId，那么当前ExtensionAbility组件可以和应用共享这一个dataGroupId生成的目录，所以ExtensionAbility组件的dataGroupId需要是应用的证书中groupIds字段里配置的才能生效。 且该字段仅在当前ExtensionAbility组件存在独立的沙箱目录时生效。详见[dataGroupId申请流程](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ime-kit-security-V5#section4219152220459)。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| process | 标识组件的进程标签，只有type为embeddedUI时可以配置该字段。<br/>**说明：**<br/>仅在[2in1](./module-configuration-file.md#devicetypes标签)设备上生效，UIAbility组件和ExtensionAbility组件标签一致时运行在同一个进程中。 | 字符串 | 该标签可缺省，缺省值为空。 |

extensionAbilities示例：


```json
{
  "extensionAbilities": [
    {
      "name": "FormName",
      "srcEntry": "./form/MyForm.ts",
      "icon": "$media:icon",
      "label" : "$string:extension_name",
      "description": "$string:form_description",
      "type": "form",
      "permissions": ["ohos.abilitydemo.permission.PROVIDER"],
      "readPermission": "",
      "writePermission": "",
      "exported": true,
      "uri":"scheme://authority/path/query",
      "skills": [{
        "actions": [],
        "entities": [],
        "uris": [],
        "permissions": []
      }],
      "metadata": [
        {
          "name": "ohos.extension.form",
          "resource": "$profile:form_config",
        }
      ],
      "extensionProcessMode": "instance",
      "dataGroupIds": [
        "testGroupId1"
      ]
    }
  ]
}
```

## shortcuts标签

shortcuts标识应用的快捷方式信息。标签值为数组，包含四个子标签shortcutId、label、icon、wants。

metadata中指定shortcut信息，其中：

- name：指定shortcuts的名称，使用ohos.ability.shortcuts作为shortcuts信息的标识。

- resource：指定shortcuts信息的资源位置。

**表11** shortcuts标签说明

| 属性名称 | 含义 | 类型  | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| shortcutId | 标识快捷方式的ID，取值为长度不超过63字节的字符串。**不支持通过资源索引的方式（$string）配置该字段。** | 字符串 | 该标签不可缺省。 |
| label | 标识快捷方式的标签信息，即快捷方式对外显示的文字描述信息。取值为长度不超过255字节的字符串，可以是描述性内容，也可以是标识label的资源索引。 | 字符串 | 该标签可缺省，缺省值为空。 |
| icon | 标识快捷方式的图标，取值为资源文件的索引。 | 字符串 | 该标签可缺省，缺省值为空。 |
| [wants](#wants标签) | 标识快捷方式内定义的目标wants信息集合，在调用launcherBundleManager的startShortcut接口时，会拉起wants标签里的第一个目标组件，推荐只配置一个wants元素。 | 对象 | 该标签可缺省，缺省为空。 |


1. 在/resources/base/profile/目录下配置shortcuts_config.json配置文件。

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
             "moduleName": "entry",
             "abilityName": "EntryAbility",
             "parameters": {
               "testKey": "testValue"
             }
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
           "srcEntry": "./ets/entryability/EntryAbility.ets",
           // ...
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
### wants标签

此标签用于标识快捷方式内定义的目标wants信息集合。

**表11-1** wants标签说明

| 属性名称 | 含义 | 类型  | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| bundleName | 表示快捷方式的目标包名。 | 字符串 | 该标签不可缺省。 |
| moduleName | 表示快捷方式的目标模块名。 | 字符串 | 该标签可缺省。 |
| abilityName| 表示快捷方式的目标组件名。 | 字符串 | 该标签不可缺省。 |
| parameters | 表示拉起快捷方式时的自定义数据，仅支持配置字符串类型的数据。其中键值均最大支持1024长度的字符串。 | 对象 | 该标签可缺省。 |

data标签示例：

```json
{
  "wants": [
    {
      "bundleName": "com.ohos.hello",
      "moduleName": "entry",
      "abilityName": "EntryAbility",
      "parameters": {
        "testKey": "testValue"
      }
    }
  ]
}
```

## distributionFilter标签

该标签用于定义HAP对应的细分设备规格的分发策略，以便在应用市场进行云端分发应用包时做精准匹配。

> **说明：**
> 该标签从API10及以后版本开始生效，API9及以前版本使用distroFilter标签。

- **适用场景：** 当一个工程中存在多个Entry，且多个Entry配置的deviceTypes存在交集时，则需要通过该标签进行区分。比如下面的两个Entry都支持tablet类型，就需要通过该标签进行区分。
  ```json
  // entry1支持的设备类型
  {
    "module": {
      "name": "entry1",
      "type": "entry",
      "deviceTypes" : [
        "tv",
        "tablet"
      ]
    }
  }
  ```
  ```json
  // entry2支持的设备类型
  {
    "module": {
      "name": "entry2",
      "type": "entry",
      "deviceTypes" : [
        "car",
        "tablet"
      ]
    }
  }
  ```

- **配置规则：**  该标签支持配置四个属性，包括屏幕形状([screenShape](#screenshape标签))、窗口分辨率([screenWindow](#screenwindow标签))、屏幕像素密度([screenDensity](#screendensity标签) )、设备所在国家与地区([countryCode](#countrycode标签))，详见下表。

  在分发应用包时，通过deviceTypes与这四个属性的匹配关系，唯一确定一个用于分发到设备的HAP。

  * 如果需要配置该标签，则至少包含一个属性。
  * 如果一个Entry中配置了任意一个或多个属性，则其他Entry也必须包含相同的属性。
  * screenShape和screenWindow属性仅用于轻量级智能穿戴设备。

- **配置方式：** 该标签需要配置在/resources/base/profile资源目录下，并在metadata的resource字段中引用。


**表12** distributionFilter标签配置说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| [screenShape](#screenshape标签) | 标识屏幕形状的支持策略。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [screenWindow](#screenwindow标签) | 标识应用运行时的窗口分辨率的支持策略。| 对象数组 | 该标签可缺省，缺省值为空。 |
| [screenDensity](#screendensity标签) | 标识屏幕的像素密度（dpi：Dot&nbsp;Per&nbsp;Inch）的支持策略。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [countryCode](#countrycode标签) | 标识国家与地区的支持策略，取值参考ISO-3166-1标准。支持多个国家和地区枚举定义。 | 对象数组 | 该标签可缺省，缺省值为空。 |

### screenShape标签

**表13** screenShape标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识条件属性的过滤规则。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 该标签不可缺省。 |
| value | 支持的取值为circle（圆形）、rect（矩形）。例如，针对智能穿戴设备，可为圆形表盘和矩形表盘分别提供不同的HAP。 | 字符串数组 | 该标签不可缺省。 |

### screenWindow标签

**表14** screenWindow标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识条件属性的过滤规则。当前取值仅支持“include”。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 该标签不可缺省。 |
| value | 单个字符串的取值格式为“宽&nbsp;\*&nbsp;高”，取值为整数像素值，例如“454&nbsp;\*&nbsp;454”。 | 字符串数组 | 该标签不可缺省。 |

### screenDensity标签

**表15** screenDensity标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识条件属性的过滤规则。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 该标签不可缺省。 |
| value | 标识屏幕的像素密度（dpi&nbsp;:Dot&nbsp;Per&nbsp;Inch）。支持的取值如下：<br/>-&nbsp;sdpi：表示小规模的屏幕密度（Small-scale&nbsp;Dots&nbsp;per&nbsp;Inch），适用于dpi取值为(0,120]的设备。<br/>-&nbsp;mdpi：表示中规模的屏幕密度（Medium-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(120,160]的设备。<br/>-&nbsp;ldpi：表示大规模的屏幕密度（Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(160,240]的设备。<br/>-&nbsp;xldpi：表示大规模的屏幕密度（Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(240,320]的设备。<br/>-&nbsp;xxldpi：表示大规模的屏幕密度（Extra&nbsp;Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(320，480]的设备。<br/>-&nbsp;xxxldpi：表示大规模的屏幕密度（Extra&nbsp;Extra&nbsp;Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(480,&nbsp;640]的设备。 | 字符串数组 | 该标签不可缺省。 |

### countryCode标签

**表16** countryCode标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识条件属性的过滤规则。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 该标签不可缺省。 |
| value | 标识应用需要分发的国家地区码。 | 字符串数组 | 该标签不可缺省。 |


示例如下：

1. 在开发视图的resources/base/profile下面定义配置文件distributionFilter_config.json，文件名可以自定义。
   ```json
   {
     "distributionFilter": {
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
       "countryCode": { // 支持在中国分发
         "policy": "include",
         "value": [
           "CN"
         ]
       }
     }
   }
   ```


2. 在module.json5配置文件的module标签中定义metadata信息。


    ```json
    {
      "module": {
        // ...
        "metadata": [
          {
            "name": "ohos.module.distribution",
            "resource": "$profile:distributionFilter_config",
          }
        ]
      }
    }
    ```


## testRunner标签

此标签用于支持对测试框架的配置。

**表17** testRunner标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识测试框架对象名称，取值为长度不超过255字节的字符串。 | 字符串 | 不可缺省。 |
| srcPath | 标识测试框架代码路径，取值为长度不超过255字节的字符串。 | 字符串 | 不可缺省。 |

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

## atomicService标签

此标签用于支持对原子化服务的配置。此标签仅在app.json中bundleType指定为atomicService时使能。

**表18** atomicService标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| preloads | 标识原子化服务中预加载列表。 | 对象数组 | 该标签可缺省，缺省值为空。 |


**表19** preloads标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| moduleName | 标识原子化服务中当前模块被加载时，需预加载的模块名。不能配置自身modulename，且必须有对应的模块，取值为长度不超过31字节的字符串。 | 字符串 | 该标签不可缺省。 |


atomicService标签示例：

```json
{
  "module": {
    "atomicService": {
      "preloads":[
        {
          "moduleName":"feature"
        }
      ]
    }
  }
}
```

## dependencies标签

此标签标识模块运行时依赖的共享库列表。

**表20** dependencies标签说明

| 属性名称    | 含义                           | 数据类型 | 是否可缺省 |
| ----------- | ------------------------------ | -------- | ---------- |
| bundleName  | 标识当前模块依赖的共享包包名。取值为长度7~128字节的字符串。 | 字符串   | 该标签可缺省，缺省值为空。 |
| moduleName  | 标识当前模块依赖的共享包模块名。取值为长度不超过31字节的字符串。 | 字符串   | 该标签不可缺省。 |
| versionCode | 标识当前共享包的版本号。取值范围为0~2147483647。 | 数值     | 该标签可缺省，缺省值为空。 |

dependencies标签示例：

```json
{
  "module": {
    "dependencies": [
      {
        "bundleName":"com.share.library",
        "moduleName": "library",
        "versionCode": 10001
      }
    ]
  }
}
```

## proxyData标签

此标签标识模块提供的数据代理列表，仅限entry和feature配置。

**表21** proxyData标签说明
| 属性名称    | 含义                           | 数据类型 | 是否可缺省 |
| ----------- | ------------------------------ | -------- | ---------- |
| uri | 标识用于访问该数据代理的URI，不同的数据代理配置的URI不可重复，且需要满足`datashareproxy://当前应用包名/xxx`的格式。取值为长度不超过255字节的字符串。 | 字符串   | 该标签不可缺省。 |
| requiredReadPermission  | 标识从该数据代理中读取数据所需要的权限，若不配置，则其他应用无法使用该代理。非系统应用配置的权限的等级需为system_basic或system_core，系统应用配置的权限的等级没有限制。权限等级可以参考[权限列表](../security/AccessToken/app-permissions.md)。取值为长度不超过255字节的字符串。 | 字符串   | 该标签可缺省，缺省值为空。 |
| requiredWritePermission | 标识向该数据代理中写入数据所需要的权限，若不配置，则其他应用无法使用该代理。非系统应用配置的权限的等级需为system_basic或system_core，系统应用配置的权限的等级没有限制。权限等级可以参考[权限列表](../security/AccessToken/app-permissions.md)。取值为长度不超过255字节的字符串。 | 字符串   | 该标签可缺省，缺省值为空。 |
| [metadata](#metadata标签) | 标识该数据代理的元信息，只支持配置name和resource字段。 | 对象 | 该标签可缺省，缺省值为空。 |

proxyData标签示例：

```json
{
  "module": {
    "proxyData": [
      {
        "uri":"datashareproxy://com.ohos.datashare/event/Meeting",
        "requiredReadPermission": "ohos.permission.GET_BUNDLE_INFO",
        "requiredWritePermission": "ohos.permission.GET_BUNDLE_INFO",
        "metadata": {
          "name": "datashare_metadata",
          "resource": "$profile:datashare"
        }
      }
    ]
  }
}
```

## routerMap标签

此标签标识模块配置的路由表的路径。

routerMap配置文件描述模块的路由表信息，routerMap标签值为数组类型。

**表22** routerMap标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name          | 标识跳转页面的名称。取值为长度不超过1023字节的字符串。 | 字符串  | 该标签不可缺省。       |
| pageSourceFile| 标识页面在模块内的路径。取值为长度不超过255字节的字符串。 | 字符串 | 该标签不可缺省。  |
| buildFunction | 标识被@Builder修饰的函数，该函数描述页面的UI。取值为长度不超过1023字节的字符串。 | 字符串  | 该标签不可缺省。   |
| [data](#data标签)  | 标识字符串类型的自定义数据。 每个自定义数据字符串取值不超过128字节。 | 对象   | 该标签可缺省，缺省值为空。   |
| [customData](#customdata标签)  | 标识任意类型的自定义数据，总长度不超过4096字节。  | 对象   | 该标签可缺省，缺省值为空。   |

示例如下：

1. 在开发视图的resources/base/profile下面定义配置文件，文件名可以自定义，例如：router_map.json。

    ```json
    {
      "routerMap": [
        {
          "name": "DynamicPage1",
          "pageSourceFile": "src/main/ets/pages/pageOne.ets",
          "buildFunction": "myFunction",
          "customData": {
            "stringKey": "data1",
            "numberKey": 123,
            "booleanKey": true,
            "objectKey": {
              "name": "test"
            },
            "arrayKey": [
              {
                "id": 123
              }
            ]
          }
        },
        {
          "name": "DynamicPage2",
          "pageSourceFile": "src/main/ets/pages/pageTwo.ets",
          "buildFunction": "myBuilder",
          "data": {
            "key1": "data1",
            "key2": "data2"
          }
        }
      ]
    }
    ```

2. 在module.json5配置文件的module标签中定义`routerMap`字段，指向定义的路由表配置文件，例如：`"routerMap": "$profile:router_map"`。

### data标签

此标签用于支持在路由表中配置自定义的字符串数据。

data标签示例：

```json
{
  "routerMap": [
    {
      "name": "DynamicPage",
      "pageSourceFile": "src/main/ets/pages/pageOne.ets",
      "buildFunction": "myBuilder",
      "data": {
        "key1": "data1",
        "key2": "data2"
      }
    }
  ]
}
```

### customData标签

此标签用于支持在路由表中配置自定义数据。
customData对象内部，可以填入任意类型的自定义数据。

customData标签示例：

```json
{
  "routerMap": [
    {
      "name": "DynamicPage",
      "pageSourceFile": "src/main/ets/pages/pageOne.ets",
      "buildFunction": "myBuilder",
      "customData": {
        "stringKey": "data1",
        "numberKey": 123,
        "booleanKey": true,
        "objectKey": {
          "name": "test"
        },
        "arrayKey": [
          {
            "id": 123
          }
        ]
      }
    }
  ]
}
```

## appEnvironments标签

此标签标识模块配置的应用环境变量。

**表23** appEnvironments标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name          | 标识环境变量的变量名称。取值为长度不超过4096字节的字符串。 | 字符串  | 该标签可缺省，缺省值为空。 |
| value         | 标识环境变量的值。取值为长度不超过4096字节的字符串。       | 字符串  | 该标签可缺省，缺省值为空。 |

appEnvironments标签示例：

```json
{
  "module": {
    "appEnvironments": [
      {
        "name":"name1",
        "value": "value1"
      }
    ]
  }
}
```

## definePermissions标签

该标签仅支持系统资源hap定义权限，不支持应用自定义权限。权限定义方式参见[系统资源权限定义](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)。

**表24** definePermissions标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识权限的名称，该标签最大长度为255字节。 | 字符串 | 不可缺省。 |
| grantMode | 标识权限的授予方式，支持如下两种授予模式如下：<br/>-&nbsp;system_grant：安装后系统自动授予该权限。<br/>-&nbsp;user_grant：使用时动态申请，用户授权后才可使用。 | 字符串 | 可缺省，缺省值为system_grant。 |
| availableLevel | 标识权限限制类别，可选值如下：<br/>-&nbsp;system_core：系统核心权限。<br/>-&nbsp;system_basic：系统基础权限。<br/>-&nbsp;normal：普通权限。所有应用允许申请的权限。 | 字符串 | 可缺省，缺省值为normal。 |
| provisionEnable | 标识权限是否支持证书方式申请权限，包括高级别的权限。配置为true标识开发者可以通过provision方式申请权限。 | 布尔值 | 可缺省，缺省值为true。 |
| distributedSceneEnabled | 标识权限是否支持分布式场景下使用该权限。 | 布尔值 | 可缺省，缺省值为false。 |
| label | 标识权限的简短描述，配置为对描述内容的资源索引。 | 字符串 | 可缺省，缺省值为空。 |
| description | 标识权限的详细描述，可以是字符串，或者是对描述内容的资源索引。 | 字符串 | 可缺省，缺省值为空。 |

definePermissions标签示例：

```json
{
  "module" : {
    "definePermissions": [
      {
        "name": "ohos.abilitydemo.permission.PROVIDER",
        "grantMode": "system_grant",
        "availableLevel": "system_core",
        "provisionEnable": true,
        "distributedSceneEnable": false,
        "label": "$string:EntryAbility_label"
      }
    ]
  }
}
```

## hnpPackages标签

该标签标识应用包含的Native软件包信息。

**表25** hnpPackages标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| package | 标识Native软件包名称。 | 字符串 | 该标签不可缺省。 |
| type | 标识Native软件包类型。支持的取值如下：<br/>-&nbsp;public：公有类型。<br/>-&nbsp;private：私有类型。  | 字符串 | 该标签不可缺省。 |

hnpPackages示例：


```json
{
  "module" : {
    "hnpPackages": [
      {
        "package": "hnpsample.hnp",
        "type": "public"
      }
    ]
  }
}
```

## fileContextMenu标签

该标签用来标识当前HAP的右键菜单配置项，是一个profile文件资源，用于指定描述应用注册右键菜单配置文件。

fileContextMenu标签示例

```json
{
  "module": {
    // ...
    "fileContextMenu": "$profile:menu" // 通过profile下的资源文件配置
  }
}
```

在开发视图的resources/base/profile下面定义配置文件menu.json，其中文件名“menu.json”可自定义，需要和fileContextMenu标签指定的信息对应。配置文件中描述了当前应用注册的右键菜单的项目和响应行为。
配置文件根节点名称为fileContextMenu，为对象数组，标识当前module注册右键菜单的数量。（单模块和单应用注册数量不能超过5个，配置超过数量当前只解析随机5个）

**表26** fileContextMenu标签配置说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| abilityName | 表示当前右键菜单对应的需要拉起的ability名称。 | 字符串 | 不可缺省 |
| menuItem | 右键菜单显示的信息。 | 资源id | 不可缺省 |
| menuHandler | 一个ability可以创建多个右键菜单， 用该字段来区分用户拉起的不同右键菜单项。该字段在用户点击右键菜单执行时，会作为参数传递给右键菜单应用。 | 字符串 | 不可缺省 |
| menuContext | 定义展示该菜单项需要的上下文，可以支持多种情况，类型为数组。 | 对象数组 | 不可缺省 |

**表27** menuContext标签配置说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| menuKind | 表示单击如下类型时会触发右键菜单。取值范围如下：<br/>-&nbsp;0：空白处<br/>-&nbsp;1：文件<br/>-&nbsp;2：文件夹<br/>-&nbsp;3：文件和文件夹 | 数值 | 不可缺省 |
| menuRule | 表示采用什么方式选择文件或文件夹时，会触发右键菜单。取值范围如下：<br/>-&nbsp;single：单选<br/>-&nbsp;multi：多选<br/>-&nbsp;both：单选或多选 | 字符串 | 仅当menuKind为1或2时，才会读取该字段，此时不可缺省。 |
| fileSupportType | 表示当选中的文件列表里包含指定的文件类型时，显示右键菜单。<br/>当该字段取值为["*"]时，将会读取fileNotSupportType字段。<br/>当该字段取值为[]时，将不做任何处理。 | 字符串数组 | 仅当menuKind为1时，才会读取该字段，此时不可缺省。 |
| fileNotSupportType | 	表示当选中的文件列表里包含这些文件类型时，不显示该右键菜单。<br/>仅当menuKind为1、且fileSupportType为["*"]时，才会读取该字段。 | 字符串数组 | 可缺省，缺省值为空。 |

resources/base/profile路径下的menu.json资源文件示例如下：
```json
{
  "fileContextMenu": [
    {
      "abilityName": "EntryAbility",
      "menuItem": "$string:module_desc",
      "menuHandler": "openCompress",
      "menuContext": [
        {
          "menuKind": 0
        },
        {
          "menuKind": 1,
          "menuRule": "both",
          "fileSupportType": [
            ".rar",
            ".zip"
          ],
          "fileNotSupportType": [
            ""
          ]
        },
        {
          "menuKind": 2,
          "menuRule": "single"
        },
        {
          "menuKind": 3
        }
      ]
    }
  ]
}
```

**响应行为**

应用进行右键扩展菜单注册后，在文件管理器通过右键操作拉起菜单，该菜单中会有“更多”选项。点击“更多”选项后，会出现注册后的menuItem列表，点击任意一个选项后，文件管理器默认通过startAbility的方式拉起三方应用，除了指定三方应用的包名和ability名之外，want中的parameter中，也会传入如下字段：

**表28** want中parameter字段说明

| 参数名 | 值 | 类型 |
| -------- | -------- | -------- |
| menuHandler | 对应注册配置文件中menuHandler的值。 | 字符串 |
| uriList | 用户在具体文件上触发右键的uri值，如果空白处响应，此值为空，单个文件响应，数组长度1，多个文件响应则传入对应所有文件的uri值。 | 字符串数组 |

## startWindow标签

该标签指向一个profile文件资源，用于指定UIAbility组件启动页面的配置文件，在开发视图的resources/base/profile下面定义配置文件start_window.json。

**表29** startWindow标签配置说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| startWindowAppIcon | 标识当前UIAbility组件启动页面图标资源文件的索引，取值为长度不超过255字节的字符串。| 字符串 | 可缺省，缺省值为空。 |
| startWindowIllustration | 标识当前UIAbility组件启动页面插画资源文件的索引，取值为长度不超过255字节的字符串。 | 字符串 | 可缺省，缺省值为空。 |
| startWindowBrandingImage | 标识当前UIAbility组件启动页面品牌标识资源文件的索引，取值为长度不超过255字节的字符串。 | 字符串 | 可缺省，缺省值为空。 |
| startWindowBackgroundColor | 标识当前UIAbility组件启动页面背景颜色资源文件的索引，取值为长度不超过255字节的字符串。 | 字符串 | 不可缺省。 |
| startWindowBackgroundImage | 标识当前UIAbility组件启动页面背景图片资源文件的索引，取值为长度不超过255字节的字符串。 | 字符串 | 可缺省，缺省值为空。 |
| startWindowBackgroundImageFit | 标识当前UIAbility组件启动页面背景图像适应方式的索引，取值为长度不超过255字节的字符串。 | 字符串 | 可缺省，缺省值为空。 |

resources/base/profile路径下的start_window.json资源文件示例如下：
```json
{
  "startWindowAppIcon": "$media:start_window_app_icon",
  "startWindowIllustration": "$media:start_window_illustration",
  "startWindowBrandingImage": "$media:start_window_branding_image",
  "startWindowBackgroundColor": "$color:start_window_back_ground_color",
  "startWindowBackgroundImage": "$media:start_window_back_ground_image",
  "startWindowBackgroundImageFit": "$string:start_window_back_ground_image_fit"
}
```