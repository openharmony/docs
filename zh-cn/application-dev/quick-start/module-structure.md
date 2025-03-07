# module对象内部结构


module对象包含HAP的配置信息。

 **表1** **module对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| mainAbility | 服务中心图标露出的Ability，常驻进程拉起时会启动mainAbility。 | 字符串 | 可缺省，缺省值为空。 |
| package | 标识HAP的包结构名称，在应用内保证唯一性。采用反向域名格式（建议与HAP的工程目录保持一致）。字符串长度为1-127个字节。 | 字符串 | 不可缺省。 |
| name | 标识HAP的类名。采用反向域名方式标识，前缀要与同级的package标签指定的包名一致，也可采用"."开头的命名方式。字符串长度不超过255字节。 | 字符串 | 可缺省，缺省值为空。 |
| description | 标识HAP的描述信息。字符串长度不超过255字节。如果字符串超出长度或者需要支持多语言，可以采用资源索引的方式添加描述内容。 | 字符串 | 可缺省，缺省值为空。 |
| supportedModes | 标识应用支持的运行模式，当前只定义了驾驶模式（drive）。该标签只适用于车机。 | 字符串数组 | 可缺省，缺省值为空。 |
|deviceType | <!--RP1-->标识允许Ability运行的设备类型。系统预定义的设备类型包括：tablet(平板)、tv（智慧屏）、car(车机)、wearable(智能穿戴)等。<!--RP1End--> | 字符串数组 | 不可缺省。 |
|distro | 标识HAP发布的具体描述。 | 对象 | 不可缺省。 |
|metaData | 标识HAP的元信息。 | 对象 | 可缺省，缺省值为空。 |
| abilities | 标识当前模块内的所有Ability。采用对象数据格式。 | 对象数组 | 可缺省，缺省值为空。 |
| js | 标识基于ArkUI框架开发的JS模块集合，其中的每个元素代表一个JS模块的信息。 | 对象数组 | 可缺省，缺省值为空。 |
| shortcuts | 标识应用的快捷方式信息。采用对象数组格式，其中的每个元素表示一个快捷方式对象。 | 对象数组 | 可缺省，缺省值为空。 |
| reqPermissions | 标识应用运行时向系统申请的权限。 | 对象数组 | 可缺省，缺省值为空。 |
| colorMode | 标识应用自身的颜色模式，目前支持如下三种模式：<br/>-&nbsp;dark：表示按照深色模式选取资源。<br/>-&nbsp;light：表示按照浅色模式选取资源。<br/>-&nbsp;auto：表示跟随系统的颜色模式值选取资源。 | 字符串 | 可缺省，缺省值为"auto"。 |
| distroFilter | 该标签下的子标签均为可选字段，用于定义HAP对应的细分设备规格的分发策略，以便应用市场在云端分发HAP时做精准匹配。该标签需要配置在/resource/profile资源目录下；在进行分发时，通过deviceType与下表属性的匹配关系，唯一确定一个用于分发到设备的HAP。 | 对象 | 可缺省，缺省值为空。但当应用中包含多个entry模块时，必须配置该标签。 |
|commonEvents | 定义了公共事件静态订阅者的信息，该字段中需要声明静态订阅者的名称、权限要求及订阅事件列表信息，当订阅的公共事件发送时，该公共事件静态订阅者将被拉起。这里的静态订阅者区分于常用的动态订阅者，前者无需在业务代码中主动调用订阅事件的接口，在公共事件发布时可能未被拉起，而动态订阅者则在业务代码中主动调用公共事件订阅的相关API，因此需要应用处于活动状态。 | 对象数组 | 可缺省，缺省为空。 |
| entryTheme | 此标签标识系统内部主题的关键字。将标记值设置为名称的资源索引。 | 字符串 | 可缺省，缺省值为空。 |
|testRunner | 此标签用于支持对测试框架的配置。 | 对象 | 可缺省，缺省值为空。 |
|generateBuildHash |标识当前HAP/HSP是否由打包工具生成哈希值。如果存在，则在系统OTA升级但应用的[version下的code](./app-structure.md#version对象内部结构)保持不变时，可根据哈希值判断应用是否需要升级。**<br/>注：该字段仅对预置应用生效。**|布尔值|该标签可缺省, 缺省值为false。|
|libIsolation |用于区分同应用不同hap下的so文件，以防止so冲突。<br/>-&nbsp;true：当前hap的so会储存在libs目录中以Module名命名的路径下。<br/>-&nbsp;false：当前hap的so会直接储存在libs目录中。|布尔值|该标签可缺省, 缺省值为false。|

module示例：

```json
{
  "module": {
    "mainAbility": ".EntryAbility",
    "deviceType": [
      "default",
      "tablet"
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
        "srcPath": "EntryAbility",
        "name": ".EntryAbility",
        "srcLanguage": "ets",
        "icon": "$media:icon",
        "description": "$string:MainAbility_desc",
        "formsEnabled": false,
        "label": "$string:MainAbility_label",
        "type": "page",
        "launchType": "multiton"
      }
    ],
    "distro": {
      "moduleType": "entry",
      "installationFree": false,
      "deliveryWithInstall": true,
      "moduleName": "entry"
    },
    "package": "com.example.entry",
    "srcPath": "",
    "name": ".entry",
    "js": [
      {
        "mode": {
          "syntax": "ets",
          "type": "pageAbility"
        },
        "pages": [
          "pages/Index"
        ],
        "name": ".EntryAbility",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": false
        }
      }
    ]
  }
}
```

## distro对象内部结构

**表2** **distro对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| moduleName | 标识当前HAP的名称，最大长度为31个字节。 在应用升级时，该名称允许修改，但需要应用适配Module相关数据目录的迁移，可使用[文件操作接口](../reference/apis-core-file-kit/js-apis-file-fs.md#fscopydir10)。| 字符串 | 不可缺省。 |
| moduleType | 标识当前HAP的类型，包括三种类型：entry、feature和har。 | 字符串 | 不可缺省。 |
| installationFree | 标识当前HAP是否支持免安装特性。true：表示支持免安装特性，且符合免安装约束。false：表示不支持免安装特性。另外还需注意：当entry.hap该字段配置为true时，与该entry.hap相关的所有feature.hap该字段也需要配置为true。当entry.hap该字段配置为false时，与该entry.hap相关的各feature.hap该字段可按业务需求配置true或false。 | 布尔值 | 不可缺省。 |
| deliveryWithInstall | 标识当前HAP是否在用户主动安装HAP所在应用的时候一起安装。true：&nbsp;安装应用时当前HAP随应用一起下载安装。false：安装应用时当前HAP并不下载安装，后续使用是按需下载。 | 布尔值 | 不可缺省。 |


distro示例：

```json
"distro": {
  "moduleName": "ohos_entry",
  "moduleType": "entry",
  "installationFree": true,
  "deliveryWithInstall": true
}
```

## metadata对象内部结构

**表3** **metadata对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| parameters | 标识调用Ability时所有调用参数的元信息。每个调用参数的元信息由以下三个标签组成：description、name、type。 | 对象数组 | 可缺省，缺省值为空。 |
| results | 标识Ability返回值的元信息。每个返回值的元信息由以下三个标签组成：description、name、type。 | 对象数组 | 可缺省，缺省值为空。 |
| customizeData | 该标签标识父级组件的自定义元信息，Parameters和results在application不可配。 | 对象数组 | 可缺省，缺省值为空。 |

## parameters对象内部结构

**表4** **parameters对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| description | 标识对调用参数的描述，可以是表示描述内容的字符串，也可以是对描述内容的资源索引以支持多语言。该标签最大长度为255个字节。 | 字符串 | 可缺省，缺省值为空。 |
| name | 标识调用参数的名称。该标签最大长度为255个字节。 | 字符串 | 不可缺省。 |
| type | 标识调用参数的类型，如Integer。 | 字符串 | 不可缺省。 |

## results对象内部结构

**表5** **results对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| description | 标识对返回值的描述，可以是表示描述内容的字符串，也可以是对描述内容的资源索引以支持多语言。该标签最大长度为255个字节。 | 字符串 | 可缺省，缺省值为空。 |
| name | 标识返回值的名字。该标签最大长度为255个字节。 | 字符串 | 可缺省，缺省值为空。 |
| type | 标识返回值的类型，如Integer。 | 字符串 | 不可缺省。 |

## customizeData对象的内部结构

**表6** **customizeData对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识数据项的键名称，字符串类型（最大长度255字节）。 | 字符串 | 可缺省，缺省值为空。 |
| value | 标识数据项的值名称，字符串类型（最大长度255字节）。 | 字符串 | 可缺省，缺省值为空。 |
| extra | 标识用户自定义数据格式，标签值为标识该数据的资源的索引值。 | 字符串 | 可缺省，缺省值为空。 |


metadata对象示例：

```json
"metaData": {
  "parameters" : [{
    "name" : "a test for metadata parameter",
    "type" : "Float",
    // "$string:parameters_description"为文件资源索引值
    "description" : "$string:parameters_description"
  }],
  "results" : [{
    "name" : "a test for metadata result",
    "type" : "Float",
    "description" : "$string:results_description"
  }],
  "customizeData" : [{
    "name" : "a customizeData",
    "value" : "string",
    "extra" : "$string:customizeData_description"
  }]
}
```

## deviceType标签

**表7** **deviceType标签配置说明**

<!--RP2-->
| 设备类型 | 枚举值 | 说明 |
| -------- | -------- | -------- |
| 平板 | tablet | - |
| 智慧屏 | tv | - |
| 智能手表 | wearable | 系统能力较丰富的手表，具备电话功能。 |
| 运动表 | litewearable | - |
| 车机 | car | - |
| 默认设备 | default | 能够使用全部系统能力的设备。 |
<!--RP2End-->

## abilities对象的内部结构

**表8** **abilities对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| process | 运行应用程序或Ability的进程名称。如果在deviceConfig标记中配置了进程，则应用程序的所有能力都在此进程中运行。您还可以为特定能力设置流程属性，以便该能力可以在此流程中运行。如果此属性设置为与其他应用程序相同的进程名称，则所有这些应用程序可以在同一进程中运行，前提是他们具有相同的联合用户ID和相同的签名。该标签最大字节数为31个字节。 | 字符串 | 可缺省，缺省值为空。 |
| name | 标识Ability名称。取值可采用反向域名方式表示，由包名和类名组成，如"com.example.myapplication.EntryAbility"；也可采用"."开头的类名方式表示，如".EntryAbility"。<br/>Ability的名称，需在一个应用的范围内保证唯一。说明：在使用DevEco&nbsp;Studio新建项目时，默认生成首个Ability的配置，即"config.json"中"EntryAbility"的配置。如使用其他IDE工具，可自定义名称。该标签最大长度为127个字节。 | 字符串 | 不可缺省。 |
| description | 标识对Ability的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。该标签最大长度为255个字节。 | 字符串 | 可缺省，缺省值为空。 |
| icon | 标识Ability图标资源文件的索引。取值示例：$media:ability_icon。如果在该Ability的skills属性中，actions的取值包含&nbsp;"action.system.home"，entities取值中包含"entity.system.home"，则该Ability的icon将同时作为应用的icon。如果存在多个符合条件的Ability，则取位置靠前的Ability的icon作为应用的icon。<br/>说明：应用的"icon"和"label"是用户可感知配置项，需要区别于当前所有已有的应用"icon"或"label"（至少有一个不同）。 | 字符串 | 可缺省，缺省值为空。 |
| label | 标识Ability对用户显示的名称。取值是对该名称的资源索引，支持多语言，例：$string:ability_label。如果在该Ability的skills属性中，actions的取值包含&nbsp;"action.system.home"，entities取值中包含"entity.system.home"，则该Ability的label将同时作为应用的label。如果存在多个符合条件的Ability，则取位置靠前的Ability的label作为应用的label。<br/>说明：&nbsp;应用的"icon"和"label"是用户可感知配置项，需要区别于当前所有已有的应用"icon"或"label"（至少有一个不同）。该标签为资源文件中定义的字符串的引用，或以"{}"包括的字符串。该标签最大长度为255个字节。 | 字符串 | 可缺省，缺省值为空。 |
| uri | 标识Ability的统一资源标识符。该标签最大长度为255个字节。 | 字符串 | 可缺省，对于data类型的Ability不可缺省。 |
| launchType | 标识Ability的启动模式，支持"multiton"和"singleton"两种模式：<br/>multiton：表示该Ability可以有多实例。该模式适用于大多数应用场景。<br/>singleton：表示该Ability在所有任务栈中仅可以有一个实例。例如，具有全局唯一性的呼叫来电界面即采用"singleton"模式。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串 | 可缺省，缺省值为"singleton"。 |
| visible | 标识Ability是否可以被其他应用调用。<br/>true：可以被其他应用调用。<br/>false：不能被其他应用调用，包括无法被aa工具命令拉起应用。 | 布尔类型 | 可缺省，缺省值为"false"。 |
| permissions | 标识其他应用的Ability调用此Ability时需要申请的权限集合，一个数组元素为一个权限名称。通常采用反向域名格式（最大255字节），取值为系统预定义的权限。 | 字符串数组 | 可缺省，缺省值为空。 |
|skills | 标识Ability能够接收的want的特征。 | 对象数组 | 可缺省，缺省值为空。 |
| deviceCapability | 标识Ability运行时要求设备具有的能力，采用字符串数组的格式表示。该标签为数组，支持最多配置512个元素，单个元素最大字节长度为64。 | 字符串数组 | 可缺省，缺省值为空。 |
| metaData | 元数据。 | 对象 | 可缺省，缺省值为空。 |
| type | 标识Ability的类型。取值范围如下：<br/>page：表示基于Page模板开发的FA，用于提供与用户交互的能力。<br/>service：表示基于Service模板开发的PA，用于提供后台运行任务的能力。<br/>data：表示基于Data模板开发的PA，用于对外部提供统一的数据访问对象。<br/>CA：表示支持其他应用以窗口方式调起该Ability。 | 字符串 | 不可缺省。 |
| orientation | 标识该Ability的显示模式。该标签仅适用于page类型的Ability。取值范围如下：<br/>unspecified：由系统自动判断显示方向。<br/>landscape：横屏模式。<br/>portrait：竖屏模式。<br/>followRecent：跟随栈中最近的应用。 | 字符串 | 可缺省，缺省值为"unspecified"。 |
| backgroundModes | 标识后台服务的类型，可以为一个服务配置多个后台服务类型。该标签仅适用于service类型的Ability。取值范围如下：<br/>dataTransfer：通过网络/对端设备进行数据下载、备份、分享、传输等。<br/>audioPlayback：音频播放。<br/>audioRecording：录音。<br/>pictureInPicture：画中画、小窗口播放视频。<br/>voip：音视频电话、VOIP。<br/>location：定位、导航。<br/>bluetoothInteraction：蓝牙扫描、连接、传输。<br/>wifiInteraction：Wi-Fi扫描、连接、传输。<br/>screenFetch：录屏、截屏。<br/>multiDeviceConnection：多设备互联。 | 字符串数组 | 可缺省，缺省值为空。 |
| grantPermission | 指定是否可以向Ability内任何数据授予权限。 | 布尔值 | 可缺省，缺省值为空。 |
| readPermission | 标识读取Ability的数据所需的权限。该标签仅适用于data类型的Ability。取值为长度不超过255字节的字符串。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串 | 可缺省，缺省为空。 |
| writePermission | 标识向Ability写数据所需的权限。该标签仅适用于data类型的Ability。取值为长度不超过255字节的字符串。 | 字符串 | 可缺省，缺省为空。 |
| configChanges | 标识Ability关注的系统配置集合。当已关注的配置发生变更后，Ability会收到onConfigurationUpdated回调。取值范围：<br/>mcc：表示IMSI移动设备国家/地区代码（MCC）发生变更。典型场景：检测到SIM并更新MCC。<br/>mnc：IMSI移动设备网络代码（MNC）发生变更。典型场景：检测到SIM并更新MNC。<br/>locale：表示语言区域发生变更。典型场景：用户已为设备文本的文本显示选择新的语言类型。<br/>layout：表示屏幕布局发生变更。典型场景：当前有不同的显示形态都处于活跃状态。<br/>fontSize：表示字号发生变更。典型场景：用户已设置新的全局字号。<br/>orientation：表示屏幕方向发生变更。典型场景：用户旋转设备。<br/>density：表示显示密度发生变更。典型场景：用户可能指定不同的显示比例，或当前有不同的显示形态同时处于活跃状态。<br/>size：显示窗口大小发生变更。<br/>smallestSize：显示窗口较短边的边长发生变更。<br/>colorMode：颜色模式发生变更。 | 字符串数组 | 可缺省，缺省为空。 |
| mission | 标识Ability指定的任务栈。该标签仅适用于page类型的Ability。默认情况下应用中所有Ability同属一个任务栈。 | 字符串 | 可缺省，缺省为应用的包名。 |
| targetAbility | 标识当前Ability重用的目标Ability。该标签仅适用于page类型的Ability。如果配置了targetAbility属性，则当前Ability（即别名Ability）的属性中仅name、icon、label、visible、permissions、skills生效，其他属性均沿用targetAbility中的属性值。目标Ability必须与别名Ability在同一应用中，且在配置文件中目标Ability必须在别名之前进行声明。 | 字符串 | 可缺省，缺省值为空。表示当前Ability不是一个别名Ability。 |
| formsEnabled | 标识Ability是否支持卡片（forms）功能。该标签仅适用于page类型的Ability。<br/>true：支持卡片能力。<br/>false：不支持卡片能力。 | 布尔值 | 可缺省，缺省值为false。 |
| forms | 标识服务卡片的属性。该标签仅当formsEnabled为"true"时，才能生效。 | 对象数组 | 可缺省，缺省值为空。 |
| srcLanguage | Ability开发语言的类型，开发者创建工程时由开发者手动选择开发语言。取值如下："js"、"ets"、"java"。 | 字符串 | 可缺省，缺省值为"js"。 |
| srcPath | 该标签标识Ability对应的JS组件代码路径，该标签最大长度为127字节。 | 字符串 | 不可缺省。 |
| uriPermission | 标识该Ability有权访问的应用程序数据。此属性由模式和路径子属性组成。此属性仅对类型提供者的能力有效。 | 对象 | 可缺省，缺省值为空。 |
| startWindowIcon | 标识该Ability启动页面图标资源文件的索引。该标签仅适用于page类型的Ability。取值示例：$media:icon。 | 字符串 | 可缺省，缺省值为空。 |
| startWindowBackground | 标识该Ability启动页面背景颜色资源文件的索引。该标签仅适用于page类型的Ability。取值示例：$color:red。 | 字符串 | 可缺省，缺省值为空。 |
| removeMissionAfterTerminate | 该标签标识Ability销毁后是否从任务列表中移除任务。该标签仅适用于page类型的Ability。true表示销毁后移除任务，&nbsp;false表示销毁后不移除任务。 | 布尔值 | 可缺省，缺省值为false。 |


**不允许应用隐藏入口图标**

系统对无图标应用实施严格管控，防止一些恶意应用故意配置无入口图标，导致用户找不到软件所在的位置，无法操作卸载应用，在一定程度上保证用户终端设备的安全。

**入口图标的设置:** 需要在配置文件（config.json）中abilities配置下设置icon，label以及skills，而且skills的配置下必须同时包含“ohos.want.action.home” 和 “entity.system.home”。
```
{
  "module":{

    // ...

    "abilities": [{
      "icon": "$media:icon",
      "label": "Login",
      "skills": [{
        "actions": ["ohos.want.action.home"],
        "entities": ["entity.system.home"],
        "uris": []
      }]
    }],

    // ...

  }
}
```

如果应用确需隐藏入口图标，需要配置AllowAppDesktopIconHide应用特权<!--Del-->，具体配置方式参考[应用特权配置指南](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)<!--DelEnd-->。详细的入口图标及入口标签的显示规则如下。
* HAP中包含Page类型的PageAbility
  * 配置文件（config.json）中abilities配置中设置了入口图标
    * 该应用没有隐藏图标的特权
      * 系统将使用该PageAbility配置的icon作为入口图标，并显示在桌面上。用户点击该图标，页面跳转到该PageAbility首页。
      * 系统将使用该PageAbility配置的label作为入口标签，并显示在桌面上（如果没有配置label，返回包名）。
    * 该应用具有隐藏图标的特权
      * 桌面查询时不返回应用信息，不会在桌面上显示对应的入口图标和标签。
  * 配置文件（config.json）中abilities配置中未设置入口图标
    * 该应用没有隐藏图标的特权
      * 系统将使用系统默认图标作为入口图标，并显示在桌面上。用户点击该图标，页面跳转到应用管理中对应的应用详情页面（参考下图）。
      * 系统将使用应用的包名作为入口标签，并显示在桌面上。
    * 该应用具有隐藏图标的特权
      * 桌面查询时不返回应用信息，不会在桌面上显示对应的入口图标和标签。
* HAP中不包含Page类型的PageAbility
  * 该应用没有隐藏图标的特权
    * 系统将使用系统默认图标作为入口图标，并显示在桌面上。用户点击该图标，页面跳转到应用管理中对应的应用详情页面（参考下图）。
    * 系统将使用应用的包名作为入口标签，并显示在桌面上。
  * 该应用具有隐藏图标的特权
    * 桌面查询时不返回应用信息，不会在桌面上显示对应的入口图标和标签。

**图1** 应用的详情页示意图

![应用的详情页例图](figures/application_details.jpg)

注：应用详情页面中显示的label可能与桌面上显示的不同。如果非Page类型的PageAbility配置了入口图标和label，那么详情页中显示的即为配置的。<br>
## uriPermission对象的内部结构

**表9** **uriPermission对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| path | uriPermission标识的路径，该标签最大字节长度为255个字节。 | 字符串 | 不可缺省。 |
| mode | uriPermission的匹配模式。 | 字符串 | 可缺省，缺省值为default。 |


abilities示例：

```json
"abilities": [
  {
    "name": ".EntryAbility",
    "description": "test main ability",
    // $media:ic_launcher 为媒体类资源
    "icon": "$media:ic_launcher",
    // $string:example 为字符串类资源
    "label": "$string:example",
    "launchType": "multiton",
    "orientation": "unspecified",
    "permissions": [],
    "visible": true,
    "skills": [
      {
        "actions": [
          "action.system.home"
        ],
        "entities": [
          "entity.system.home"
        ]
      }
    ],
    "configChanges": [
      "locale",
      "layout",
      "fontSize",
      "orientation"
    ],
    "type": "page",
    "startWindowIcon": "$media:icon",
    "startWindowBackground": "$color:red",
    "removeMissionAfterTerminate": true
  },
  {
    "name": ".PlayService",
    "description": "example play ability",
    "icon": "$media:ic_launcher",
    "label": "$string:example",
    "launchType": "multiton",
    "orientation": "unspecified",
    "visible": false,
    "skills": [
      {
        "actions": [
          "action.play.music",
          "action.stop.music"
        ],
        "entities": [
          "entity.audio"
        ]
      }
    ],
    "type": "service",
    "backgroundModes": [
      "audioPlayback"
    ]
  },
  {
    "name": ".UserADataAbility",
    "type": "data",
    "uri": "dataability://com.example.world.test.UserADataAbility",
    "visible": true
  }
]
```
## skills对象的内部结构

**表10** **skills对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| actions | 标识能够接收的want的action值，可以包含一个或多个action。取值通常为系统预定义的action值。 | 字符串数组 | 可缺省，缺省值为空。 |
| entities | 标识能够接收的want的Ability的类别（如视频、桌面应用等），可以包含一个或多个entity。 | 字符串数组 | 可缺省，缺省值为空。 |
| uris | 该标签标识向want过滤器添加数据规范集合。该规范可以是只有数据类型（mimeType属性），可以是只有URI，也可以是既有数据类型又有URI。<br/>URI由其各个部分的单独属性指定：&lt;scheme&gt;://&lt;host&gt;:&lt;port&gt;[&lt;path&gt;\|&lt;pathStartWith&gt;\|&lt;pathRegex&gt;]。该标签可缺省，缺省值为空。<br/>其中，scheme字段配置为uri时必配；当只设置数据类型（mimeType）时，则scheme字段为非必配项。 | 对象数组 | 可缺省，缺省值为空。 |

## uris对象的内部结构

**表11** **uris对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| scheme | 标识uri的scheme值。 | 字符串 | 不可缺省。 |
| host | 标识uri的host值。 | 字符串 | 可缺省，缺省值为空。 |
| port | 标识uri的port值。 | 字符串 | 可缺省，缺省值为空。 |
| pathStartWith | 标识uri的pathStartWith值。 | 字符串 | 可缺省，缺省值为空。 |
| path | 标识uri的path值。 | 字符串 | 可缺省，缺省值为空。 |
| pathRegx | 标识uri的pathRegx值。 | 字符串 | 可缺省，缺省值为空。 |
| type | 标识uri的type值。type为MIME-TYPE属性，为资源的媒体类型，常见的类型有"audio/aac"，"text/css"等。<br/>注意：只支持*/*、mainType/*的通配符格式，不支持mainType/subType.*的通配符格式，mainType为标准媒体类型。| 字符串 | 可缺省，缺省值为空。 |


skills示例：

```json
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
        "scheme": "http",
        "host": "www.example.com",
        "port": "8080",
        "path": "query/student/name",
        "type": "text/*"
      }
    ]
  }
]
```

## reqPermissions权限申请

**表12** **reqPermissions权限申请字段说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 需要使用的权限名称。 | 字符串 | 否 |
| reason | 描述申请权限的原因。需要做多语种适配。 | 字符串 | 分情况：当申请的权限为user_grant时，必须填写此字段，否则不允许在应用市场上架；其他权限可缺省，缺省为空。 |
| usedScene | 描述权限使用的场景和时机。场景类型如下两种：<br/>-&nbsp;ability：ability的名称，可配置多个。<br/>-&nbsp;when：调用时机，可填的值有inuse（使用时）、always（始终）。 | 对象 | 可缺省，缺省值为空。<br/>when可缺省，缺省值为"inuse"。 |

## usedScene对象内部结构

**表13** **usedScene对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| ability | 标识哪些Ability需要此权限，里面配置Ability的名称。 | 字符串数组 | 可以缺省，缺省表示所有Ability都需要此权限。 |
| when | 标识此权限的使用时间：<br/>inuse:&nbsp;使用时需要此权限。<br/>always:&nbsp;所有时间都需要此权限。 | 枚举值 | 可缺省，缺省值为空。 |

## js对象的内部结构

**表14** **js对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识JS&nbsp;Component的名字。 | 字符串 | 不可缺省。 |
| pages | 标识JS&nbsp;Component的页面用于列举JS&nbsp;Component中每个页面的路由信息，格式为“页面路径+页面名称”。其中，页面路径是以当前Ability的srcPath字段取值为基准，例如srcPath取值为EntryAbility，则JS Component页面路径需要从EntryAbility的下一层开始描述。该标签取值为数组，数组第一个元素代表JS&nbsp;FA首页。 | 字符串数组 | 不可缺省。 |
| window | 用于定义与显示窗口相关的配置。 | 对象 | 可缺省，缺省值见表15。 |
| type | 标识JS应用的类型。取值范围如下：<br/>normal：标识该JS&nbsp;Component为应用实例。<br/>form：标识该JS&nbsp;Component为卡片实例。 | 字符串 | 可缺省，缺省值为"normal"。 |
|mode | 定义JS组件的开发模式。 | 对象 | 可缺省，缺省值为空。 |

## window对象的内部结构

**表15** **window对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| designWidth | 标识页面设计基准宽度。以此为基准，根据实际设备宽度来缩放元素大小。 | 数值 | 可缺省，缺省值为720px。 |
| autoDesignWidth | 标识页面设计基准宽度是否自动计算。当配置为true时，designWidth将会被忽略，设计基准宽度由设备宽度与屏幕密度计算得出。 | 布尔值 | 可缺省，缺省值为false。 |

## mode对象的内部结构

**表16** **mode对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| type | 定义JS组件的功能类型。 | 字符串，取值为"pageAbility"、"form" | 可缺省，缺省值为pageAbility。 |
| syntax | 定义JS组件的语法类型。 | 字符串，取值为"hml"，"ets" | 可缺省，默认值为"hml"。 |


js示例：

```json
"js": [
  {
    "name": ".EntryAbility",
    "pages": [
      "pages/index",
      "pages/detail/detail"
    ],
    "window": {
      "designWidth": 720,
      "autoDesignWidth": false
    },
    "type": "form",
    "mode": {
      "syntax": "ets",
      "type": "pageAbility"
    }
  }
]
```

## shortcuts对象的内部结构

**表17** **shortcuts对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| shortcutId | 标识快捷方式的ID。字符串的最大长度为63字节。 | 字符串 | 不可缺省。 |
| label | 标识快捷方式的标签信息，即快捷方式对外显示的文字描述信息。取值可以是描述性内容，也可以是标识label的资源索引。字符串最大长度为63字节。 | 字符串 | 可缺省，缺省为空。 |
| icon | 标识快捷方式的图标信息。取值为表示icon的资源索引。 | 字符串 | 可缺省，缺省为空。 |
| intents | 标识快捷方式内定义的目标intent信息集合，每个intent可配置两个子标签，targetClass,&nbsp;targetBundle。 | 对象数组 | 可缺省，缺省为空。 |

## intents对象的内部结构

**表18** **intents对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| targetClass | 标识快捷方式目标类名。 | 字符串 | 可缺省，缺省值为空。 |
| targetBundle | 标识快捷方式目标Ability所在应用的包名。 | 字符串 | 可缺省，缺省值为空。 |


shortcuts示例：

```json
"shortcuts": [
  {
    "shortcutId": "id",
    // $string:shortcut 为配置的字符串资源值
    "label": "$string:shortcut",
    "intents": [
      {
        "targetBundle": "com.example.world.test",
        "targetClass": "com.example.world.test.entry.EntryAbility"
      }
    ]
  }
]
```

## forms对象的内部结构

**表19** **forms对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识卡片的类名。字符串最大长度为127字节。 | 字符串 | 不可缺省。 |
| description | 标识卡片的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。字符串最大长度为255字节。 | 字符串 | 可缺省，缺省为空。 |
| isDefault | 标识该卡片是否为默认卡片，每个Ability有且只有一个默认卡片。<br/>true：默认卡片。<br/>false：非默认卡片。 | 布尔值 | 不可缺省。 |
| type | 标识卡片的类型。取值范围如下：<br/>JS：JS卡片。<br/>Java：Java卡片。 | 字符串 | 不可缺省。 |
| colorMode | 标识卡片的主题样式，取值范围如下：<br/>auto：自适应。<br/>dark：深色主题。<br/>light：浅色主题。 | 字符串 | 可缺省，缺省值为"auto"。 |
| supportDimensions | 标识卡片支持的外观规格，取值范围：<br/>1&nbsp;\*&nbsp;2：表示1行2列的二宫格。<br/>2&nbsp;\*&nbsp;1：表示2行1列的二宫格。<br/>2&nbsp;\*&nbsp;2：表示2行2列的四宫格。<br/>2&nbsp;\*&nbsp;4：表示2行4列的八宫格。<br/>4&nbsp;\*&nbsp;4：表示4行4列的十六宫格。 | 字符串数组 | 不可缺省。 |
| defaultDimension | 标识卡片的默认外观规格，取值必须在该卡片supportDimensions配置的列表中。 | 字符串 | 不可缺省。 |
| updateEnabled | 标识卡片是否支持周期性刷新，取值范围：<br/>true：表示支持周期性刷新，可以在定时刷新（updateDuration）和定点刷新（scheduledUpdateTime）两种方式任选其一，优先选择定时刷新。<br/>false：表示不支持周期性刷新。 | 布尔类型 | 不可缺省。 |
| scheduledUpdateTime | 标识卡片的定点刷新的时刻，采用24小时制，精确到分钟。 | 字符串 | 可缺省，缺省值为"0:0"。 |
| updateDuration | 标识卡片定时刷新的更新周期，单位为30分钟，取值为自然数。<br/>当取值为0时，表示该参数不生效。<br/>当取值为正整数N时，表示刷新周期为30\*N分钟。 | 数值 | 可缺省，缺省值为"0"。 |
| formConfigAbility | 标识用于调整卡片的设施或活动的名称。 | 字符串 | 可缺省，缺省值为空。 |
| jsComponentName | 标识JS卡片的Component名称。字符串最大长度为127字节。仅当卡片类型为JS卡片时，需要配置该标签。 | 字符串 | 可缺省，缺省值为空。 |
| metaData | 标识卡片的自定义信息，包含customizeData数组标签。 | 对象 | 可缺省，缺省值为空。 |
| formVisibleNotify | 标识是否允许卡片使用卡片可见性通知。<br/>true：允许。<br/>false：不允许。 | 布尔值 | 可缺省，缺省值为false。 |

## customizeData对象内部结构

**表20** **customizeData对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识数据项的键名称。字符串最大长度为255字节。 | 字符串 | 可缺省，缺省值为空。 |
| value | 标识数据项的值。字符串最大长度为255字节。 | 字符串 | 可缺省，缺省值为空。 |
| extra | 标识当前custom数据的格式，取值为表示extra的资源值。 | 字符串 | 可缺省，缺省值为空。 |


forms示例：

```json
"forms": [
  {
    "name": "Form_Js",
    "description": "It's Js Form",
    "type": "JS",
    "jsComponentName": "card",
    "colorMode": "auto",
    "isDefault": true,
    "updateEnabled": true,
    "scheduledUpdateTime": "11:00",
    "updateDuration": 1,
    "defaultDimension": "2*2",
    "supportDimensions": [
      "2*2",
      "2*4",
      "4*4"
    ]
  },
  {
    "name": "Form_Js",
    "description": "It's JS Form",
    "type": "Js",
    "colorMode": "auto",
    "isDefault": false,
    "updateEnabled": true,
    "scheduledUpdateTime": "21:05",
    "updateDuration": 1,
    "defaultDimension": "1*2",
    "supportDimensions": [
      "1*2"
    ],
    "landscapeLayouts": [
      "$layout:ability_form"
    ],
    "portraitLayouts": [
      "$layout:ability_form"
    ],
    "formConfigAbility": "ability://com.example.myapplication.fa/.EntryAbility",
    "metaData": {
      "customizeData": [
        {
          "name": "originWidgetName",
          "value": "com.example.weather.testWidget"
        }
      ]
    }
  }
]
```

## distroFilter对象的内部结构

**表21** **distroFilter对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| apiVersion | 标识支持的apiVersion范围。 | 对象数组 | 可缺省，缺省值为空。 |
|screenShape | 标识屏幕形状的支持策略。 | 对象数组 | 可缺省，缺省值为空。 |
| screenWindow | 标识应用运行时窗口的分辨率支持策略。该字段仅支持对轻量级智能穿戴设备进行配置。 | 对象数组 | 可缺省，缺省值为空。 |
|screenDensity | 标识屏幕的像素密度（dpi：Dots&nbsp;Per&nbsp;Inch）。 | 对象数组 | 可缺省，缺省值为空。 |
| countryCode | 标识分发应用时的国家码。具体值参考ISO-3166-1的标准，支持多个国家和地区的枚举定义。 | 对象数组 | 可缺省，缺省值为空。 |

## apiVersion对象的内部结构

**表22** **apiVersion对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 不可缺省。 |
| value | 支持的取值为API&nbsp;Version存在的整数值，例如4、5、6。场景示例：某应用，针对相同设备型号，同时在网的为使用API&nbsp;5和API&nbsp;6开发的两个软件版本，则允许上架2个entry类型的安装包，分别支持到对应设备侧软件版本的分发。 | 数组 | 不可缺省。 |

## screenShape对象的内部结构

**表23** **screenShape对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 不可缺省。 |
| value | 支持的取值为API&nbsp;Version存在的整数值，例如4、5、6。场景示例：某应用，针对相同设备型号，同时在网的为使用API&nbsp;5和API&nbsp;6开发的两个软件版本，则允许上架2个entry类型的安装包，分别支持到对应设备侧软件版本的分发。 | 数组 | 不可缺省。 |

## screenWindow对象的内部结构

**表24** **screenWindow对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 不可缺省。 |
| value | 支持的取值为API&nbsp;Version存在的整数值，例如4、5、6。场景示例：某应用，针对相同设备型号，同时在网的为使用API&nbsp;5和API&nbsp;6开发的两个软件版本，则允许上架2个entry类型的安装包，分别支持到对应设备侧软件版本的分发。 | 数组 | 不可缺省。 |

## screenDensity对象的内部结构

**表25** **screenDensity对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 不可缺省。 |
| value | 取值范围如下：<br/>sdpi：表示小规模的屏幕密度（Small-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为（0,120]的设备。<br/>mdpi：表示中规模的屏幕密度(Medium-scale&nbsp;Dots&nbsp;Per&nbsp;Inch)，适用于dpi取值为（120,160]的设备。<br/>ldpi：表示大规模的屏幕密度(Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch)，适用于dpi取值为（160,240]的设备。<br/>xldpi：表示特大规模的屏幕密度(Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch)，适用于dpi取值为（240,320]的设备。<br/>xxldpi：表示超大规模的屏幕密度(Extra&nbsp;Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch)，适用于dpi取值为（320,480]的设备。<br/>xxxldpi：表示超特大规模的屏幕密度(Extra&nbsp;Extra&nbsp;Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch)，适用于dpi取值为（480,640]的设备。 | 数组 | 不可缺省。 |

## countryCode对象的内部结构

**表26** **countryCode对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| policy | 标识该子属性取值规则。配置为“exclude”或“include”。<br/>-&nbsp;exclude：表示需要排除的value属性。<br/>-&nbsp;include：表示需要包含的value属性。 | 字符串 | 不可缺省。 |
| value | 该标签标识应用需要分发的国家码，标签为字符串数组，子串表示支持的国家或地区，由两个大写字母表示。 | 字符串数组 | 不可缺省。 |


distroFilter示例：

```json
"distroFilter":  {
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
  },
  "screenDensity":{
    "policy": "exclude",
    "value": ["ldpi","xldpi"]
  },
  "countryCode": {
    "policy":"include",
    "value":["CN","HK"]
  }
}
```

## commonEvents对象的内部结构

**表27** **commonEvents对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识静态公共事件名称，该标签最大长度为127字节。 | 字符串 | 不可缺省。 |
| permission | 此标签标识实现静态公共事件所需要申请的权限，该标签最大长度为255字节。 | 字符串 | 可缺省，缺省值为空。 |
| data | 标识配置当前静态公共事件要携带的附加数据数组。 | 字符串数组 | 可缺省，缺省值为空。 |
| type | 该标签用于配置当前静态公共事件的分类数组。 | 字符串数组 | 可缺省，缺省值为空。 |
| events | 此标签标识可接收的意图的一组事件值。一般由系统预定义，也可以自定义。 | 字符串数组 | 不可缺省。 |


commonEvents示例：

```json
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
]
```

## testRunner对象的内部结构

**表28** **testRunner对象的内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识测试框架对象名称，该标签最大长度为255字节。 | 字符串 | 不可缺省。 |
| srcPath | 标识测试框架代码路径，该标签最大长度为255字节。 | 字符串 | 不可缺省。 |

```json
"testRunner": {
  "name": "myTestRunnerName",
  "srcPath": "etc/test/TestRunner.ts"
}
```


definePermission仅支持系统应用配置，三方应用配置不生效。

## definePermissions对象内部结构
**表29** **definePermissions对象内部结构说明**

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识权限的名称，该标签最大长度为255字节。 | 字符串 | 不可缺省。 |
| grantMode | 标识权限的授予方式，支持如下两种授予模式如下：<br/>-&nbsp;system_grant：安装后系统自动授予该权限。<br/>-&nbsp;user_grant：使用时动态申请，用户授权后才可使用。 | 字符串 | 可缺省，缺省值为system_grant。 |
| availableLevel | 标识权限限制类别，可选值如下：<br/>-&nbsp;system_core：系统核心权限。<br/>-&nbsp;system_basic：系统基础权限。<br/>-&nbsp;normal：普通权限。所有应用允许申请的权限。 | 字符串 | 可缺省，缺省值为normal。 |
| provisionEnable | 标识权限是否支持证书方式申请权限，包括高级别的权限。配置为true标识开发者可以通过provision方式申请权限。 | 布尔值 | 可缺省，缺省值为true。 |
| distributedSceneEnabled | 标识权限是否支持分布式场景下使用该权限。 | 布尔值 | 可缺省，缺省值为false。 |
| label | 标识权限的简短描述，配置为对描述内容的资源索引。 | 字符串 | 可缺省，缺省值为空。 |
| description | 标识权限的详细描述，可以是字符串（最大长度为255字节），或者为对描述内容的资源索引。 | 字符串 | 可缺省，缺省值为空。 |
