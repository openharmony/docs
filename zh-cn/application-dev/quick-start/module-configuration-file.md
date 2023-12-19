# module.json5配置文件

## 配置文件示例

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
        "resource": "$profile:distributionFilter_config"
      }
    ],
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ts",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
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
    ],
    "targetModuleName": "feature",
    "targetPriority": 50
  }
}
```

## 配置文件标签

module.json5配置文件包含以下标签。


  **表1** module.json5配置文件标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识当前Module的名称，确保该名称在整个应用中唯一。取值为长度不超过31字节的字符串，不支持中文。<br/>应用升级时允许修改该名称，但需要应用适配Module相关数据目录的迁移，详见[文件管理接口](../reference/apis/js-apis-file-fs.md#fscopydir10)。 | 字符串 | 该标签不可缺省。 |
| type | 标识当前Module的类型。支持的取值如下：<br/>-&nbsp;entry：应用的主模块。<br/>-&nbsp;feature：应用的动态特性模块。<br/>-&nbsp;har：静态共享包模块。<br/>-&nbsp;shared：动态共享包模块。 | 字符串 | 该标签不可缺省。 |
| srcEntry | 标识当前Module所对应的代码路径，取值为长度不超过127字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| description | 标识当前Module的描述信息，取值为长度不超过255字节的字符串，可以采用字符串资源索引格式。 | 字符串 | 该标签可缺省，缺省值为空。 |
| process | 标识当前Module的进程名，取值为长度不超过31字节的字符串。如果在HAP标签下配置了process，则该应用的所有UIAbility、DataShareExtensionAbility、ServiceExtensionAbility都运行在该进程中。<br/>**说明：**<br/>仅支持系统应用配置，三方应用配置不生效。 | 字符串 | 该标签可缺省，缺省为app.json5文件下app标签下的bundleName。 |
| mainElement | 标识当前Module的入口UIAbility名称或者ExtensionAbility名称，取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| [deviceTypes](#devicetypes标签) | 标识当前Module可以运行在哪类设备上。 | 字符串数组 | 该标签不可缺省。 |
| deliveryWithInstall | 标识当前Module是否在用户主动安装的时候安装，即该Module对应的HAP是否跟随应用一起安装。仅支持原子化服务。<br/>-&nbsp;true：主动安装时安装。<br/>-&nbsp;false：主动安装时不安装。 | 布尔值 | 该标签不可缺省。 |
| installationFree | 标识当前Module是否支持免安装特性。<br/>-&nbsp;true：表示支持免安装特性，且符合免安装约束。<br/>-&nbsp;false：表示不支持免安装特性。<br/>**说明：**<br/>-&nbsp;当应用的entry类型Module的该字段配置为true时，该应用的feature类型的该字段也需要配置为true。<br/>-&nbsp;当应用的entry类型Module的该字段配置为false时，该应用的feature类型的该字段可根据业务需求配置true或false。 | 布尔值 | 该标签不可缺省。 |
| virtualMachine | 标识当前Module运行的目标虚拟机类型，供云端分发使用，如应用市场和分发中心。如果目标虚拟机类型为ArkTS引擎，则其值为“ark+版本号”。 | 字符串 | 该标签由IDE构建HAP的时候自动插入。 |
| [pages](#pages标签) | 标识当前Module的profile资源，用于列举每个页面信息，取值为长度不超过255字节的字符串。 | 字符串 | 在有UIAbility的场景下，该标签不可缺省。 |
| [metadata](#metadata标签) | 标识当前Module的自定义元信息，可通过资源引用的方式配置[distributionFilter](#distributionfilter标签)、[shortcuts](#shortcuts标签)等信息。只对当前Module、UIAbility、ExtensionAbility生效。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [abilities](#abilities标签) | 标识当前Module中UIAbility的配置信息，只对当前UIAbility生效。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [extensionAbilities](#extensionabilities标签) | 标识当前Module中ExtensionAbility的配置信息，只对当前ExtensionAbility生效。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| [requestPermissions](#requestpermissions标签) | 标识当前应用运行时需向系统申请的权限集合。 | 对象 | 该标签可缺省，缺省值为空。 |
| [testRunner](#testrunner标签) | 标识用于测试当前Module的测试框架的配置。 | 对象 | 该标签可缺省，缺省值为空。 |
| [atomicService](#atomicservice标签)| 标识当前应用是原子化服务时，有关原子化服务的相关配置。| 对象 | 该标签可缺省，缺省值为空。  |
| [dependencies](#dependencies标签)| 标识当前模块运行时依赖的共享库列表。| 对象数组 | 该标签可缺省，缺省值为空。  |
| targetModuleName | 标识当前包所指定的目标module，确保该名称在整个应用中唯一。取值为长度不超过31字节的字符串，不支持中文。配置该字段的Module具有overlay特性。 |字符串|该标签可缺省，缺省值为空。|
| targetPriority | 标识当前Module的优先级，取值范围为1~100。配置targetModuleName字段之后，才需要配置该字段。 |整型数值|该标签可缺省，缺省值为1。|
| [proxyData](#proxydata标签) | 标识当前Module提供的数据代理列表。| 对象数组 | 该标签可缺省，缺省值为空。|
| isolationMode | 标识当前Module的多进程配置项。支持的取值如下：<br/>-&nbsp;nonisolationFirst：优先在非独立进程中运行。<br/>-&nbsp;isolationFirst：优先在独立进程中运行。<br/>-&nbsp;isolationOnly：只在独立进程中运行。<br/>-&nbsp;nonisolationOnly：只在非独立进程中运行。 |字符串|该标签可缺省，缺省值为nonisolationFirst。|
| generateBuildHash |标识当前HAP/HSP是否由打包工具生成哈希值。当配置为true时，如果系统OTA升级时应用versionCode保持不变，可根据哈希值判断应用是否需要升级。<br/>该字段仅在[app.json5文件](./app-configuration-file.md)中的generateBuildHash字段为false时使能。**<br/>说明：**<br/>该字段仅对预置应用生效。|布尔值|该标签可缺省，缺省值为false。|
| compressNativeLibs | 标识libs库是否以压缩存储的方式打包到HAP。<br/>-&nbsp;true：libs库以压缩方式存储。<br/>-&nbsp;false：libs库以不压缩方式存储。 | 布尔值 | 该标签可缺省，缺省值为true。 |
| libIsolation | 用于区分同应用不同HAP下的.so文件，以防止.so冲突。<br/>-&nbsp;true：当前HAP的.so文件会储存在libs目录中以Module名命名的路径下。<br/>-&nbsp;false：当前HAP的.so文件会直接储存在libs目录中。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| fileContextMenu | 标识当前HAP的右键菜单配置项。 | 字符串 | 该标签可缺省，缺省值为空。 |

## deviceTypes标签

  **表2** deviceTypes标签说明

| 设备类型 | 枚举值 | 说明 |
| -------- | -------- | -------- |
| 平板 | tablet | - |
| 智慧屏 | tv | - |
| 智能手表 | wearable | 系统能力较丰富的手表，具备电话功能。 |
| 车机 | car | - |
| 默认设备 | default | 能够使用全部系统能力的设备。 |

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
| src | 标识关于JavaScript模块中所有页面的路由信息，包括页面路径和页面名称。取值为一个字符串数组，其中每个元素表示一个页面。 | 字符串数组 | 该标签不可缺省。 |
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
| [launchType](../application-models/uiability-launch-type.md) | 标识当前UIAbility组件的启动模式，支持的取值如下：<br/>-&nbsp;multiton：多实例模式，每次启动创建一个新实例。<br/>-&nbsp;singleton：单实例模式，仅第一次启动创建新实例。<br/>-&nbsp;specified：指定实例模式，运行时由开发者决定是否创建新实例。 | 字符串 | 改标签可缺省，该标签缺省为“singleton”。 |
| description | 标识当前UIAbility组件的描述信息，取值为长度不超过31字节的字符串。要求采用描述信息的资源索引，以支持多语言。 | 字符串 | 该标签可缺省，缺省值为空。 |
| icon | 标识当前UIAbility组件的图标，取值为图标资源文件的索引。 | 字符串 | 该标签可缺省，缺省值为空。<br/>如果UIAbility被配置为MainElement，该标签必须配置。 |
| label | 标识当前UIAbility组件对用户显示的名称，要求采用该名称的资源索引，以支持多语言。 | 字符串 | 该标签可缺省，缺省值为空。<br/>如果UIAbility被配置为MainElement，该标签必须配置。 |
| permissions | 标识当前UIAbility组件自定义的权限信息。当其他应用访问该UIAbility时，需要申请相应的权限信息。<br/>一个数组元素为一个权限名称。通常采用反向域名格式（不超过255字节），取值为系统预定义的权限。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| [metadata](#metadata标签) | 标识当前UIAbility组件的元信息。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| exported | 标识当前UIAbility组件是否可以被其他应用调用。<br/>-&nbsp;true：表示可以被其他应用调用。<br/>-&nbsp;false：表示不可以被其他应用调用，包括无法被aa工具命令拉起应用。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| continuable | 标识当前UIAbility组件是否支持跨端迁移。<br/>-&nbsp;true：表示支持迁移。<br/>-&nbsp;false：表示不支持迁移。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| [skills](#skills标签) | 标识当前UIAbility组件或ExtensionAbility组件能够接收的[Want](../application-models/want-overview.md)特征集，为数组格式。<br/>配置规则：<br/>-&nbsp;对于Entry类型的HAP，应用可以配置多个具有入口能力的skills标签（即配置了ohos.want.action.home和entity.system.home）。<br/>-&nbsp;对于Feature类型的HAP，只有应用可以配置具有入口能力的skills标签，服务不允许配置。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| backgroundModes | 标识当前UIAbility组件的长时任务集合，指定用于满足特定类型的长时任务。<br/>长时任务类型有如下：<br/>-&nbsp;dataTransfer：通过网络/对端设备进行数据下载、备份、分享、传输等。<br/>-&nbsp;audioPlayback：音频播放。<br/>-&nbsp;audioRecording：录音。<br/>-&nbsp;location：定位、导航。<br/>-&nbsp;bluetoothInteraction：蓝牙扫描、连接、传输（穿戴）。<br/>-&nbsp;multiDeviceConnection：多设备互联。<br/>-&nbsp;wifiInteraction：Wi-Fi扫描、连接、传输（克隆多屏）。<br/>-&nbsp;voip：音视频电话、VoIP。<br/>-&nbsp;taskKeeping：计算。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| startWindowIcon | 标识当前UIAbility组件启动页面图标资源文件的索引，取值为长度不超过255字节的字符串。 | 字符串 | 该标签不可缺省。 |
| startWindowBackground | 标识当前UIAbility组件启动页面背景颜色资源文件的索引，取值为长度不超过255字节的字符串。<br/>取值示例：$color:red。| 字符串 | 该标签不可缺省。 |
| removeMissionAfterTerminate | 标识当前UIAbility组件销毁后，是否从任务列表中移除任务。<br/>-&nbsp;true表示销毁后移除任务。<br/>-&nbsp;false表示销毁后不移除任务。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| orientation | 标识当前UIAbility组件启动时的方向。支持的取值如下：<br/>-&nbsp;unspecified：未指定方向，由系统自动判断显示方向。<br/>-&nbsp;landscape：横屏。<br/>-&nbsp;portrait：竖屏。<br/>-&nbsp;landscape_inverted：反向横屏。<br/>-&nbsp;portrait_inverted：反向竖屏。<br/>-&nbsp;auto_rotation：随传感器旋转。<br/>-&nbsp;auto_rotation_landscape：传感器横屏旋转，包括横屏和反向横屏。<br/>-&nbsp;auto_rotation_portrait：传感器竖屏旋转，包括竖屏和反向竖屏。<br/>-&nbsp;auto_rotation_restricted：传感器开关打开，方向可随传感器旋转。<br/>-&nbsp;auto_rotation_landscape_restricted：传感器开关打开，方向可随传感器旋转为横屏，&nbsp;包括横屏和反向横屏。<br/>-&nbsp;auto_rotation_portrait_restricted：传感器开关打开，方向随可传感器旋转为竖屏，&nbsp;包括竖屏和反向竖屏。<br/>-&nbsp;locked：传感器开关关闭，方向锁定。 | 字符串 | 该标签可缺省，缺省值为unspecified。 |
| supportWindowMode | 标识当前UIAbility组件所支持的窗口模式。支持的取值如下：<br/>-&nbsp;fullscreen：全屏模式。<br/>-&nbsp;split：分屏模式。<br/>-&nbsp;floating：悬浮窗模式。 | 字符串数组 | 该标签可缺省，缺省值为<br/>["fullscreen",&nbsp;"split",&nbsp;"floating"]。 |
| priority | 标识当前UIAbility组件的优先级。[隐式查询](../application-models/explicit-implicit-want-mappings.md)时，优先级越高，UIAbility在返回列表越靠前。取值范围0~10，数值越大，优先级越高。<br/>**说明：**<br/>仅支持系统应用配置，三方应用配置不生效。 | 整型数值 | 该标签可缺省，缺省值为0。 |
| maxWindowRatio | 标识当前UIAbility组件支持的最大的宽高比。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最大的宽高比。 |
| minWindowRatio | 标识当前UIAbility组件支持的最小的宽高比。该标签最小取值为0。 | 数值 | 该标签可缺省，缺省值为平台支持的最小的宽高比。 |
| maxWindowWidth | 标识当前UIAbility组件支持的最大的窗口宽度，宽度单位为vp。<br/>最小取值为minWindowWidth，最大取值为平台支持的最大窗口宽度。窗口尺寸可以参考[窗口大小限制](../windowmanager/window-overview.md#约束与限制)。 | 数值 | 该标签可缺省，缺省值为平台支持的最大的窗口宽度。 |
| minWindowWidth | 标识当前UIAbility组件支持的最小的窗口宽度，&nbsp;宽度单位为vp。<br/>最小取值为平台支持的最小窗口宽度，最大取值为maxWindowWidth。窗口尺寸可以参考[窗口大小限制](../windowmanager/window-overview.md#约束与限制)。 | 数值 | 该标签可缺省，缺省值为平台支持的最小的窗口宽度。 |
| maxWindowHeight | 标识当前UIAbility组件支持的最大的窗口高度，&nbsp;高度单位为vp。<br/>最小取值为minWindowHeight，最大取值为平台支持的最大窗口高度。 窗口尺寸可以参考[窗口大小限制](../windowmanager/window-overview.md#约束与限制)。| 数值 | 该标签可缺省，缺省值为平台支持的最大的窗口高度。 |
| minWindowHeight | 标识当前UIAbility组件支持的最小的窗口高度，&nbsp;高度单位为vp。<br/>最小取值为平台支持的最小窗口高度，最大取值为maxWindowHeight。窗口尺寸可以参考[窗口大小限制](../windowmanager/window-overview.md#约束与限制)。| 数值 | 该标签可缺省，缺省值为平台支持的最小的窗口高度。 |
| excludeFromMissions | 标识当前UIAbility组件是否在最近任务列表中显示。<br/>-&nbsp;true：表示不在任务列表中显示。<br/>-&nbsp;false：表示在任务列表中显示。<br/>**说明：**<br/>仅支持系统应用配置，且需申请应用特权AllowAbilityExcludeFromMissions，三方应用配置不生效，详见[应用特权配置指导](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)。| 布尔值 | 该标签可缺省，缺省值为false。 |
| recoverable | 标识当前UIAbility组件是否支持在检测到应用故障后，恢复到应用原界面。<br/>-&nbsp;true：支持检测到出现故障后，恢复到原界面。<br/>-&nbsp;false：不支持检测到出现故障后，恢复到原界面。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| unclearableMission | 标识当前UIAbility组件是否支持从最近任务列表中移除。<br/>-&nbsp;true：表示在任务列表中不可移除。<br/>-&nbsp;false：表示在任务列表中可以移除。<br/>**说明：**<br/>单独配置该字段不可生效，需要申请对应的[AllowMissionNotCleared](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)特权之后，该字段才能生效。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| isolationProcess | 标识组件能否运行在独立的进程中。<br/>-&nbsp;true：表示能运行在独立的进程中。<br/>-&nbsp;false：表示不能运行在独立的进程中。 | 布尔值 | 该标签可缺省，缺省值为false。 |

abilities示例：


```json
{
  "abilities": [{
    "name": "EntryAbility",
    "srcEntry": "./ets/entryability/EntryAbility.ts",
    "launchType":"singleton",
    "description": "$string:description_main_ability",
    "icon": "$media:icon",
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
    "orientation": " ",
    "supportWindowMode": ["fullscreen", "split", "floating"],
    "maxWindowRatio": 3.5,
    "minWindowRatio": 0.5,
    "maxWindowWidth": 2560,
    "minWindowWidth": 1400,
    "maxWindowHeight": 300,
    "minWindowHeight": 200,
    "excludeFromMissions": false,
    "unclearableMission": false
  }]
}
```


## skills标签

该标签标识UIAbility组件或者ExtensionAbility组件能够接收的[Want](../application-models/want-overview.md)的特征。

  **表7** skills标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| actions | 标识能够接收的[Action值集合](../application-models/actions-entities.md)，取值通常为系统预定义的action值，也允许自定义。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| entities | 标识能够接收的[Entity值的集合](../application-models/actions-entities.md)。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| uris | 标识与Want中URI（Uniform&nbsp;Resource&nbsp;Identifier）相匹配的集合。 | 对象数组 | 该标签可缺省，缺省值为空。 |


  **表8** uris标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| scheme | 标识URI的协议名部分，常见的有http、https、file、ftp等。 | 字符串 | uris中仅配置type时可以缺省，缺省值为空，否则不可缺省。 |
| host | 标识URI的主机地址部分，该字段在schema存在时才有意义。常见的方式：<br/>-&nbsp;域名方式，如example.com。<br/>-&nbsp;IP地址方式，如10.10.10.1。 | 字符串 | 该标签可缺省，缺省值为空。 |
| port | 标识URI的端口部分。如http默认端口为80，https默认端口是443，ftp默认端口是21。该字段在schema和host都存在时才有意义。 | 字符串 | 该标签可缺省，缺省值为空。 |
| path&nbsp;\|&nbsp;pathStartWith&nbsp;\|&nbsp;pathRegex | 标识URI的路径部分，path、pathStartWith和pathRegex配置时三选一。path标识URI与want中的路径部分全匹配，pathStartWith标识URI与want中的路径部分允许前缀匹配，pathRegex标识URI与want中的路径部分允许正则匹配。该字段在schema和host都存在时才有意义。 | 字符串 | 该标签可缺省，缺省值为空。 |
| type | 标识与Want相匹配的数据类型，使用MIME（Multipurpose&nbsp;Internet&nbsp;Mail&nbsp;Extensions）类型规范。可与schema同时配置，也可以单独配置。 | 字符串 | 该标签可缺省，缺省值为空。 |

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

  **表9** extensionAbilities标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识当前ExtensionAbility组件的名称，确保该名称在整个应用中唯一，取值为长度不超过127字节的字符串。 | 字符串 | 该标签不可缺省。 |
| srcEntry | 标识当前ExtensionAbility组件所对应的代码路径，取值为长度不超过127字节的字符串。 | 字符串 | 该标签不可缺省。 |
| description | 标识当前ExtensionAbility组件的描述，取值为长度不超过255字节的字符串，可以是对描述内容的资源索引，用于支持多语言。 | 字符串 | 该标签可缺省，缺省值为空。 |
| icon | 标识当前ExtensionAbility组件的图标，取值为资源文件的索引。如果ExtensionAbility组件被配置为MainElement，该标签必须配置。 | 字符串 | 该标签可缺省，缺省值为空。 |
| label | 标识当前ExtensionAbility组件对用户显示的名称，取值为该名称的资源索引，以支持多语言。如果ExtensionAbility被配置当前Module的mainElement时，该标签必须配置，且要确保应用内唯一。 | 字符串 | 该标签可缺省，缺省值为空。 |
| type | 标识当前ExtensionAbility组件的类型，支持的取值如下：<br/>-&nbsp;form：卡片的ExtensionAbility。<br/>-&nbsp;workScheduler：延时任务的ExtensionAbility。<br/>-&nbsp;inputMethod：输入法的ExtensionAbility。<br/>-&nbsp;service：后台运行的service组件。<br/>-&nbsp;accessibility：辅助能力的ExtensionAbility。<br/>-&nbsp;dataShare：数据共享的ExtensionAbility。<br/>-&nbsp;fileShare：文件共享的ExtensionAbility。<br/>-&nbsp;staticSubscriber：静态广播的ExtensionAbility。<br/>-&nbsp;wallpaper：壁纸的ExtensionAbility。<br/>-&nbsp;backup：数据备份的ExtensionAbility。<br/>-&nbsp;window：该ExtensionAbility会在启动过程中创建一个window，为开发者提供界面开发。开发者开发出来的界面将通过UIExtensionComponent控件组合到其他应用的窗口中。<br/>-&nbsp;thumbnail：获取文件缩略图的ExtensionAbility，开发者可以对自定义文件类型的文件提供缩略。<br/>-&nbsp;preview：该ExtensionAbility会将文件解析后在一个窗口中显示，开发者可以通过将此窗口组合到其他应用窗口中。<br/>-&nbsp;print：打印框架的ExtensionAbility。<br/>-&nbsp;push：推送的ExtensionAbility。<br/>-&nbsp;driver：驱动框架的ExtensionAbility。<br/>-&nbsp;remoteNotification：远程通知的ExtensionAbility。<br/>-&nbsp;remoteLocation：远程定位的ExtensionAbility。<br/>-&nbsp;voip：网络音视频通话的ExtensionAbility。<br/>**说明：**<br/>其中service和dataShare类型，仅支持系统应用配置，三方应用配置不生效。 | 字符串 | 该标签不可缺省。 |
| permissions | 标识当前ExtensionAbility组件自定义的权限信息。当其他应用访问该ExtensionAbility时，需要申请相应的权限信息。<br/>一个数组元素为一个权限名称。通常采用反向域名格式（最大255字节），取值为[系统预定义的权限](../security/permission-list.md)。 | 字符串数组 | 该标签可缺省，缺省值为空。 |
| uri | 标识当前ExtensionAbility组件提供的数据URI，取值为长度不超过255字节的字符数组，用反向域名的格式表示。<br/>**说明：**<br/>该标签在type为dataShare类型的ExtensionAbility时，不可缺省。 | 字符串 | 该标签可缺省，缺省值为空。 |
|skills | 标识当前ExtensionAbility组件能够接收的[Want](../application-models/want-overview.md)的特征集。<br/>配置规则：entry包可以配置多个具有入口能力的skills标签（配置了ohos.want.action.home和entity.system.home）的ExtensionAbility，其中第一个配置了skills标签的ExtensionAbility中的label和icon作为服务或应用的label和icon。<br/>**说明：**<br/>服务的Feature包不能配置具有入口能力的skills标签。<br/>应用的Feature包可以配置具有入口能力的skills标签。 | 数组 | 该标签可缺省，缺省值为空。 |
| [metadata](#metadata标签) | 标识当前ExtensionAbility组件的元信息。 | 对象 | 该标签可缺省，缺省值为空。 |
| exported | 标识当前ExtensionAbility组件是否可以被其他应用调用。<br/>-&nbsp;true：表示可以被其他应用调用。<br/>-&nbsp;false：表示不可以被其他应用调用，包括无法被aa工具命令拉起应用。 | 布尔值 | 该标签可缺省，缺省值为false。 |

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

该标签标识应用运行时需向系统申请的权限集合，权限设置方式参见[指导](../security/accesstoken-guidelines.md)。

> **说明：**
>
> - 在requestPermissions标签中配置的权限项将在应用级别生效，即该权限适用于整个应用程序。
> - 如果应用需要订阅自己发布的事件，而且应用在extensionAbilities标签中的permissions字段中设置了访问该应用所需要的权限，那么应用也需要在requestPermissions标签中注册相关权限才能收到该事件。

**表10** requestPermissions标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识需要使用的权限名称。 | 字符串 | 该标签不可缺省。 |
| reason | 标识申请权限的原因，取值需要采用资源引用格式，以适配多语种。  | 字符串 | 该标签可缺省，缺省值为空。 <br/>**说明：**<br/>当申请的权限为user_grant权限时，该字段必填，否则不允许在应用市场上架。|
| usedScene | 标识权限使用的场景，包含abilities和when两个子标签。<br/>-&nbsp;abilities：可以配置为多个UIAbility或者ExtensionAbility名称的字符串数组。<br/>-&nbsp;when：表示调用时机，支持的取值包括inuse（使用时）和always（始终）。 | 对象 | 该标签可缺省，缺省值为空。 <br/>**说明：**<br/>当申请的权限为user_grant权限时，abilities标签必填，when标签可选。|

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

shortcuts标识应用的快捷方式信息。标签值为数组，包含四个子标签shortcutId、label、icon、wants。

metadata中指定shortcut信息，其中：

- name：指定shortcuts的名称，使用ohos.ability.shortcuts作为shortcuts信息的标识。

- resource：指定shortcuts信息的资源位置。

**表11** shortcuts标签说明

| 属性名称 | 含义 | 类型  | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| shortcutId | 标识快捷方式的ID，取值为长度不超过63字节的字符串。 | 字符串 | 该标签不可缺省。 |
| label | 标识快捷方式的标签信息，即快捷方式对外显示的文字描述信息。取值为长度不超过255字节的字符串，可以是描述性内容，也可以是标识label的资源索引。 | 字符串 | 该标签可缺省，缺省值为空。 |
| icon | 标识快捷方式的图标，取值为资源文件的索引。 | 字符串 | 该标签可缺省，缺省值为空。 |
| [wants](../application-models/want-overview.md) | 标识快捷方式内定义的目标wants信息集合，每个wants可配置bundleName、moduleName和abilityName三个子标签，并且支持配置其中的一个或多个标签。<br/>- bundleName：表示快捷方式的目标Bundle名称，字符串类型。<br/>- moduleName：表示快捷方式的目标Module名，字符串类型。<br/>- abilityName：表示快捷方式的目标组件名，字符串类型。 | 对象 | 该标签可缺省，缺省为空。 |


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
             "moduleName": "entry",
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
           "srcEntry": "./ets/entryability/EntryAbility.ts",
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
  
  * 如果需要配置该标签，则至应当包含一个属性。
  * 如果一个Entry中配置了任意一个或多个属性，则其他Entry也必须包含相同的属性。
  * screenShape和screenWindow属性仅用于轻量级智能穿戴设备。

- **配置方式：** 该标签需要配置在/resource/profile资源目录下，并在metadata的resource字段中引用。


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
| moduleName | 标识原子化服务中当前模块被加载时，需预加载的模块名。 | 字符串 | 该标签不可缺省。 |


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
| bundleName  | 标识当前模块依赖的共享包包名。  | 字符串   | 该标签可缺省，缺省值为空。 |
| moduleName  | 标识当前模块依赖的共享包模块名。| 字符串   | 该标签不可缺省。 |
| versionCode | 标识当前共享包的版本号。       | 数值     | 该标签可缺省，缺省值为空。 |

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
| uri | 标识用于访问该数据代理的URI，不同的数据代理配置的URI不可重复，且需要满足`datashareproxy://当前应用包名/xxx`的格式。  | 字符串   | 该标签不可缺省。 |
| requiredReadPermission  | 标识从该数据代理中读取数据所需要的权限，若不配置，则其他应用无法使用该代理。非系统应用配置的权限的等级需为system_basic或system_core，系统应用配置的权限的等级没有限制。权限等级可以参考[权限列表](../security/permission-list.md)。 | 字符串   | 该标签可缺省，缺省值为空。 |
| requiredWritePermission | 标识向该数据代理中写入数据所需要的权限，若不配置，则其他应用无法使用该代理。非系统应用配置的权限的等级需为system_basic或system_core，系统应用配置的权限的等级没有限制。权限等级可以参考[权限列表](../security/permission-list.md)。 | 字符串   | 该标签可缺省，缺省值为空。 |
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