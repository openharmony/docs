

# 应用包结构配置文件的说明

在FA模型的应用开发的工程中，需要在config.json配置文件中对应用的包结构进行声明。

## 配置文件的内部结构

“config.json”由app，deviceConfig和module三个部分组成，缺一不可。配置文件的内部结构说明参见表1。

表1 配置文件的内部结构说明

| 属性名称     | 含义                                                         | 数据类型 | 是否可缺省 |
| ------------ | ------------------------------------------------------------ | -------- | ---------- |
| app          | 标识应用的全局配置信息。同一个应用的不同HAP包的app配置必须保持一致。参考[app对象内部结构](#app对象内部结构)。 | 对象     | 不可缺省。   |
| deviceConfig | 标识应用在具体设备上的配置信息。参考[deviceconfig对象内部结构](#deviceconfig对象的内部结构)。 | 对象     | 不可缺省。   |
| module       | 标识HAP包的配置信息。该标签下的配置只对当前HAP包生效。参考[module对象的内部结构](#module对象的内部结构)。 | 对象     | 不可缺省。   |

config.json示例：

```json
{
  "app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "version": {
      "code": 1,
      "name": "1.0"
    },
    "apiVersion": {
      "compatible": 4,
      "target": 5,
      "releaseType": "Beta1"
    }
  },
  "deviceConfig": {},
  "module": {
    "package": "com.example.myapplication.entrymodule",
    "name": ".MyApplication",
    "deviceType": [
      "default"
    ],
    "distro": {
      "moduleName": "entry",
      "moduleType": "entry"
    },
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
        "name": "com.example.myapplication.entrymodule.MainAbility",
        "icon": "$media:icon",
        "description": "$string:mainability_description",
        "label": "$string:app_name",
        "type": "page",
        "launchType": "standard"
      }
    ],
    "js": [
      {
        "pages": [
          "pages/index/index"
        ],
        "name": "default",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": false
        }
      }
    ]
  }
}
```

### app对象内部结构

app对象包含应用全局配置信息，内部结构说明参见表2。

表2 app对象的内部结构说明

| 属性名称          | 含义                                                         | 数据类型 | 是否可缺省                  |
| ----------------- | ------------------------------------------------------------ | -------- | --------------------------- |
| bundleName        | 标识应用的包名，用于标识应用的唯一性。包名是由字母、数字、下划线（_）和点号（.）组成的字符串，必须以字母开头。支持的字符串长度为7~127字节。包名通常采用反向域名形式表示（例如，"com.example.myapplication"）。建议第一级为域名后缀"com"，第二级为厂商/个人名，也可以采用多级。 | 字符串   | 不可缺省。                    |
| vendor            | 标识对应用开发厂商的描述。字符串长度不超过255字节。          | 字符串   | 可缺省，缺省值为空。         |
| version           | 标识应用的版本信息。参考表3。                                | 对象     | 否                          |
| apiVersion        | 标识应用程序所依赖的OpenHarmony API版本。参考表4。           | 对象     | 可缺省，缺省值为空。          |
| smartWindowSize        | 标识应用在模拟器中运行时使用的屏幕尺寸。           | 字符串     | 可缺省，缺省值为空。          |
| smartWindowDeviceType        | 标识应用在模拟器中运行时可以模拟的设备。           | 字符串数组     | 可缺省，缺省值为空。          |

表3 version内部结构说明

| 属性名称                 | 含义                                                         | 数据类型 | 是否可缺省                 |
| ------------------------ | ------------------------------------------------------------ | -------- | -------------------------- |
| name                     | 标识应用的版本号，用于向应用的终端用户呈现。取值可以自定义，长度不超过127字节。自定义规则如下：<br />API5及更早的版本：推荐使用三段数字版本号（也兼容两段式版本号），如A.B.C(也兼容A.B)，其中A、B、C取值为0-999范围内的整数。除此之外不支持其他格式。<br />     A段，一般表示主版本号（Major）。<br />     B段，一般表示次版本号（Minor）。<br />     C段，一般表示修订版本号（Patch）。<br />API6版本起：推荐采用四段式数字版本号，如A.B.C.D，其中A、B、C取值为0-99范围内的整数，D的取值为0-999范围内的整数。<br />     A段，一般表示主版本号（Major）。<br />     B段，一般表示次版本号（Minor）。<br />     C段，一般表示特性版本号（Feature）。<br />     D段，一般表示修订版本号（Patch）。 | 数值     | 不可缺省。                   |
| code                     | 标识应用的版本号，仅用于OpenHarmony管理该应用，不对应用的终端用户呈现。取值规则如下：<br />API5及更早版本：二进制32位以内的非负整数，需要从version.name的值转换得到。转换规则为：<br /> code值=A * 1,000,000 + B * 1,000 + C 例如，version.name字段取值为2.2.1，则code值为2002001。<br /> API6版本起：code的取值不与version.name字段的取值关联，开发者可自定义code取值，取值范围为2^31以内的非负整数，但是每次应用版本的更新，均需要更新code字段的值，新版本code取值必须大于旧版本code的值。 | 数值     | 不可缺省。                   |
| minCompatibleVersionCode | 标识应用可兼容的最低版本号，用于跨设备场景下，判断其他设备上该应用的版本是否兼容。<br /> 格式与version.code字段的格式要求相同。 | 数值     | 可缺省，缺省值为code标签值。 |

表4 apiVersion内部结构

| 属性名称    | 含义                                                        | 数据类型 | 是否可缺省 |
| ----------- | ----------------------------------------------------------- | -------- | ---------- |
| compatible  | 运行应用所需要的最低API版本，取值范围为0~2147483647。       | 数值     | 配置在build.profile中，打包时由IDE填充到config.json中。     |
| target      | 用于标识应用运行所需的目标API版本，取值范围为0~2147483647。 | 数值     | 配置在build.profile中，打包时由IDE填充到config.json中。     |
| releaseType | 用于标识应用运行所需的目标API版本的类型。                   | 字符串   | 配置在build.profile中，打包时由IDE填充到config.json中。     |

app实例：

```json
"app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "version": {
        "code": 8,
        "name": "8.0.1"
    },
    "apiVersion": {
        "compatible": 8,
        "target": 9,
        "releaseType": "Beta1"
    }
}
```

### deviceConfig对象的内部结构

deviceConfig包含设备上的应用配置信息，可以包含default，tv，car，wearable等属性。default标签内的配置适用于所有通用设备，其他设备类型如果有特殊的需求，则需要在该设备类型的标签下进行配置。内部结构说明参见表5。

表5 deviceConfig对象的内部结构说明

| 属性名称 | 含义                                      | 数据类型 | 是否可缺省         |
| -------- | ----------------------------------------- | -------- | ------------------ |
| default  | 能够使用全部系统能力的OpenHarmony设备。 | 对象     | 可缺省，缺省值为空。  |
| tablet   | 标识平板的应用配置信息。     | 对象     | 可缺省，缺省值为空。 |
| tv       | 标识智慧屏特有的应用配置信息。   | 对象     | 可缺省，缺省值为空。 |
| car      | 标识车机特有的应用配置信息。    | 对象     | 可缺省，缺省值为空。 |
| wearable | 标识智能穿戴特有的应用配置信息。| 对象     | 可缺省，缺省值为空。 |

default、tablet、tv、car、wearable等对象的内部结构说明如下：。

表6 deviceConfig设备对象的内部结构说明

| 属性名称           | 含义                                                         | 数据类型 | 是否可缺省              |
| ------------------ | ------------------------------------------------------------ | -------- | ----------------------- |
| process            | 标识应用或者Ability的进程名。如果在deviceConfig标签下配置了process标签，则该应用的所有Ability都运行在这个进程中。如果在abilities标签下也为某个Ability配置了process标签，则该Ability就运行在这个进程中。该标签仅适用于默认设备、平板、智慧屏、车机、智慧穿戴。该标签最大长度为31。 | 字符串   | 可缺省，缺省值为空。                      |
| keepAlive          | 标识应用是否始终保持运行状态，仅支持系统应用配置，三方应用配置不生效。该标签为布尔类型，可缺省，缺省值为false，如果配置为true，应用将始终保持为运行状态，并在系统启动的时候被系统驱动起来，应用进程退出后，系统也会重新启动应用进程。 | 布尔值   | 可缺省，缺省值为false。   |
| supportBackup      | 标识应用是否支持备份和恢复。如果配置为"false"，则不支持为该应用执行备份或恢复操作。<br /> 该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 布尔值   | 可缺省，缺省值为false。 |
| compressNativeLibs | 标识libs库是否以压缩存储的方式打包到HAP包。如果配置为"false"，则libs库以不压缩的方式存储，HAP包在安装时无需解压libs，运行时会直接从HAP内加载libs库。<br /> 该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 布尔值   | 可缺省，缺省值为false。  |
| network            | 标识网络安全性配置。该标签允许应用通过配置文件的安全声明来自定义其网络安全，无需修改应用代码。参考表9。 | 对象     | 可缺省，缺省值为空。      |

表9 network对象的内部结构说明

| 属性名称         | 含义                                                         | 数据类型 | 是否可缺省              |
| ---------------- | ------------------------------------------------------------ | -------- | ----------------------- |
| cleartextTraffic | 标识是否允许应用使用明文网络流量（例如，明文HTTP）。<br /> true：允许应用使用明文流量请求。<br /> false：拒绝应用使用明文流量的请求。 | 布尔值   | 可缺省，缺省值为false。 |
| securityConfig   | 标识应用的网络安全配置信息。参考表10。                       | 对象     | 可缺省，缺省值为空。        |

表10 securityConfig对象的内部结构说明

| 属性名称       | 子属性名称         | 含义                                                         | 数据类型 | 是否可缺省       |
| -------------- | ------------------ | ------------------------------------------------------------ | -------- | ---------------- |
| domainSettings | -                  | 标识自定义的网域范围的安全配置，支持多层嵌套，即一个domainSettings对象中允许嵌套更小网域范围的domainSettings对象。 | 对象 | 可缺省，缺省值为空。 |
|                | cleartextPermitted | 标识自定义的网域范围内是否允许明文流量传输。当cleartextTraffic和security同时存在时，自定义网域是否允许明文流量传输以cleartextPermitted的取值为准。<br />true：允许明文流量传输。<br />false：拒绝明文流量传输。 | 布尔值 | 可缺省，缺省值为空。         |
|                | domains            | 标识域名配置信息，包含两个参数：subdomains和name。<br /> subdomains(布尔类型)：表示是否包含子域名。如果为"true"，此网域规则将与相应网域及所有子网域（包括子网域的子网域）匹配。否则，该规则仅适用于精确匹配项。<br /> name(字符串)：表示域名名称。 | 对象数组 | 可缺省，缺省值为空。         |

deviceConfig示例：

```json
"deviceConfig": {
    "default": {
        "process": "com.example.test.example",
        "supportBackup": false,
        "network": {
            "cleartextTraffic": true,
            "securityConfig": {
                "domainSettings": {
                    "cleartextPermitted": true,
                    "domains": [
                        {
                            "subdomains": true,
                            "name": "example.ohos.com"
                        }
                    ]
                }
            }
        }
    }
}
```

### module对象的内部结构

module对象包含HAP包的配置信息，内部结构说明参见表11。

表11 module对象的内部结构说明

| 属性名称          | 含义                                                         | 数据类型   | 是否可缺省                                                   |
| ----------------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| mainAbility       | 服务中心图标露出的ability，常驻进程拉起时会启动mainAbility。 | 字符串     | 可缺省，缺省值为空。                |
| package           | 标识HAP的包结构名称，在应用内保证唯一性。采用反向域名格式（建议与HAP的工程目录保持一致）。字符串长度为1-127个字节。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串     | 不可缺省。                                                     |
| name              | 标识HAP的类名。采用反向域名方式标识，前缀要与同级的package标签指定的包名一致，也可采用"."开头的命名方式。字符串长度不超过255字节。<br /> 该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串     | 可缺省，缺省值为空。                                                     |
| description       | 标识HAP的描述信息。字符串长度不超过255字节。如果字符串超出长度或者需要支持多语言，可以采用资源索引的方式添加描述内容。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串     | 可缺省，缺省值为空。                                           |
| supportedModes    | 标识应用支持的运行模式，当前只定义了驾驶模式（drive）。该标签只适用于车机。 | 字符串数组 | 可缺省，缺省值为空。                                           |
| deviceType        | 标识允许Ability运行的设备类型。系统预定义的设备类型包括：tablet(平板)、tv（智慧屏）、car(车机)、wearable(智能穿戴)等。 | 字符串数组 | 不可缺省。                                                     |
| distro            | 标识HAP发布的具体描述。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。参考表12。 | 对象       | 不可缺省。                                                     |
| metaData          | 标识HAP的元信息。参考表13。                                  | 对象       | 可缺省，缺省值为空。                                           |
| abilities         | 标识当前模块内的所有Ability。采用对象数据格式。参考表17。 | 对象数组   | 可缺省，缺省值为空。                                           |
| js                | 标识基于ArkUI框架开发的JS模块集合，其中的每个元素代表一个JS模块的信息。参考表22。 | 对象数组   | 可缺省，缺省值为空。                                           |
| shortcuts         | 标识应用的快捷方式信息。采用对象数组格式，其中的每个元素表示一个快捷方式对象。参考表25。 | 对象数组   | 可缺省，缺省值为空。                                           |
| reqPermissions    | 标识应用运行时向系统申请的权限。参考表21。                   | 对象数组   | 可缺省，缺省值为空。                                           |
| colorMode         | 标识应用自身的颜色模式。<br /> dark：表示按照深色模式选取资源。<br /> light：表示按照浅色模式选取资源。<br /> auto：表示跟随系统的颜色模式值选取资源。<br /> 该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串     | 可缺省，缺省值为"auto"。                                       |
| distroFilter      | 标识应用的分发规则。<br /> 该标签用于定义HAP包对应的细分设备规格的分发策略，以便在应用市场进行云端分发应用包时做精准匹配。该标签可配置的分发策略维度包括API Version、屏幕形状、屏幕分辨率。在进行分发时，通过deviceType与这三个属性的匹配关系，唯一确定一个用于分发到设备的HAP。参考表29。 | 对象       | 可缺省，缺省值为空。但当应用中包含多个entry模块时，必须配置该标签。 |
| commonEvents      | 定义了公共事件静态订阅者的信息，该字段中需要声明静态订阅者的名称、权限要求及订阅事件列表信息，当订阅的公共事件发送时，该公共事件静态订阅者将被拉起。这里的静态订阅者区分于常用的动态订阅者，前者无需在业务代码中主动调用订阅事件的接口，在公共事件发布时可能未被拉起，而动态订阅者则在业务代码中主动调用公共事件订阅的相关API，因此需要应用处于活动状态。参考表35。                                         | 对象数组   | 可缺省，缺省值为空。                                             |
| entryTheme        | 此标签标识OpenHarmony内部主题的关键字。将标记值设置为名称的资源索引。 | 字符串     | 可缺省，缺省值为空。                                           |
| testRunner        | 此标签用于支持对测试框架的配置，参考表36。                   | 对象       | 可缺省，缺省值为空。                                           |

module示例：

```json
"module": {
    "mainAbility": "MainAbility",
    "package": "com.example.myapplication.entry",
    "name": ".MyOHOSAbilityPackage",
    "description": "$string:description_application",
    "supportModes": [
        "drive"
    ],
    "deviceType": [
        "car"
    ],
    "distro": {
        "moduleName": "ohos_entry",
        "moduleType": "entry"
    },
    "abilities": [
      ...
    ],
    "shortcuts": [
      ...
    ],
    "js": [
      ...
    ],
    "reqPermissions": [
      ...
    ],
    "colorMode": "light"
}
```

表12 distro对象的内部结构说明

| 属性名称         | 含义                                                         | 数据类型 | 是否可缺省 |
| ---------------- | ------------------------------------------------------------ | -------- | ---------- |
| moduleName       | 标识当前HAP的名称，最大长度为31个字节。                            | 字符串   | 不可缺省。   |
| moduleType       | 标识当前HAP的类型，包括三种类型：entry、feature和har。 | 字符串   | 不可缺省。   |
| installationFree | 标识当前HAP是否支持免安装特性。<br /> true：表示支持免安装特性，且符合免安装约束。<br /> false：表示不支持免安装特性。<br /> 另外还需注意：<br /> 当entry.hap该字段配置为true时，与该entry.hap相关的所有feature.hap该字段也需要配置为true。<br /> 当entry.hap该字段配置为false时，与该entry.hap相关的各feature.hap该字段可按业务 需求配置true或false。 | 布尔值   | 不可缺省。     |
| deliveryWithInstall | 标识当前HAP是否在用户主动安装HAP所在应用的时候一起安装。<br /> true：安装应用时当前HAP随应用一起下载安装。<br /> false：安装应用时当前HAP并不下载安装，后续使用时按需下载。| 布尔值 | 不可缺省。 |

distro示例：

```json
"distro": {
    "moduleName": "ohos_entry",
    "moduleType": "entry",
    "installationFree": true,
    "deliveryWithInstall": true
}
```

表13 metaData对象的内部结构说明

| 属性名称      | 含义                                                         | 数据类型 | 是否可缺省           |
| ------------- | ------------------------------------------------------------ | -------- | -------------------- |
| parameters    | 标识调用Ability时所有调用参数的元信息。每个调用参数的元信息由以下三个标签组成：description、name、type。参考表14。 | 对象数组 | 可缺省，缺省值为空。   |
| results       | 标识Ability返回值的元信息。每个返回值的元信息由以下三个标签组成：description、name、type。参考表15。 | 对象数组 | 可缺省，缺省值为空。 |
| customizeData | 该标签标识父级组件的自定义元信息，Parameters和results在application不可配。参考表16 | 对象数组 | 可缺省，缺省值为空。 |

表14 parameters对象的内部结构说明

| 属性名称    | 含义                                                         | 数据类型 | 是否可缺省         |
| ----------- | ------------------------------------------------------------ | -------- | ------------------ |
| description | 标识对调用参数的描述，可以是表示描述内容的字符串，也可以是对描述内容的资源索引以支持多语言。该标签最大长度为255个字节。 | 字符串   | 可缺省，缺省值为空。 |
| name        | 标识调用参数的名称。该标签最大长度为255个字节。                    | 字符串   | 可缺省，缺省值为空。 |
| type        | 标识调用参数的类型，如Integer。                              | 字符串   | 不可缺省。           |

表15 results对象的内部结构说明

| 属性名称    | 含义                                                         | 数据类型 | 是否可缺省           |
| ----------- | ------------------------------------------------------------ | -------- | -------------------- |
| description | 标识对返回值的描述，可以是表示描述内容的字符串，也可以是对描述内容的资源索引以支持多语言。该标签最大长度为255个字节。 | 字符串   | 可缺省，缺省值为空。 |
| name        | 标识返回值的名字。该标签最大长度为255个字节。                      | 字符串   | 可缺省，缺省值为空。 |
| type        | 标识返回值的类型，如Integer。                                | 字符串   | 不可缺省。             |

表16 customizeData对象的内部结构说明

| 属性名称 | 含义                                                       | 数据类型 | 是否可缺省           |
| -------- | ---------------------------------------------------------- | -------- | -------------------- |
| name     | 标识数据项的键名称，字符串类型（最大长度255字节）。        | 字符串   | 可缺省，缺省值为空。 |
| value    | 标识数据项的值名称，字符串类型（最大长度255字节）。        | 字符串   | 可缺省，缺省值为空。 |
| extra    | 标识用户自定义数据格式，标签值为标识该数据的资源的索引值。 | 字符串   | 可缺省，缺省值为空。 |

metaData示例：

```json
"metaData": {
    "parameters" : [{
        "name" : "string",
        "type" : "Float",
        "description" : "$string:parameters_description"
    }],
    "results" : [{
        "name" : "string",
        "type" : "Float",
        "description" : "$string:results_description"
    }],
    "customizeData" : [{
        "name" : "string",
        "value" : "string",
        "extra" : "$string:customizeData_description"
    }]
}
```

表17 abilities对象的内部结构说明

| 属性名称         | 含义                                                         | 数据类型   | 是否可缺省                                               |
| ---------------- | ------------------------------------------------------------ | ---------- | -------------------------------------------------------- |
| process          | 运行应用程序或Ability的进程名称。如果在deviceConfig标记中配置了进程，则应用程序的所有能力都在此进程中运行。您还可以为特定能力设置流程属性，以便该能力可以在此流程中运行。如果此属性设置为与其他应用程序相同的进程名称，则所有这些应用程序可以在同一进程中运行，前提是他们具有相同的联合用户ID和相同的签名。运行OHOS的设备不支持此属性。该标签最大字节数为31个字节。 | 字符串     | 可缺省，缺省值为空。                                     |
| name             | 标识Ability名称。取值可采用反向域名方式表示，由包名和类名组成，如“com.example.myapplication.MainAbility”；也可采用“.”开头的类名方式表示，如“.MainAbility”。<br /> Ability的名称，需在一个应用的范围内保证唯一。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。<br /> 说明：在使用DevEco Studio新建项目时，默认生成首个Ability的配置，即“config.json”中“MainAbility”的配置。如使用其他IDE工具，可自定义名称。该标签最大长度为127。 | 字符串     | 不可缺省。                                                   |
| description      | 标识对Ability的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。该标签最大长度为255个字节。 | 字符串     | 可缺省，缺省值为空。                                     |
| icon             | 标识Ability图标资源文件的索引。取值示例：$media:ability_icon。如果在该Ability的skills属性中，actions的取值包含 “action.system.home”，entities取值中包含“entity.system.home”，则该Ability的icon将同时作为应用的icon。如果存在多个符合条件的Ability，则取位置靠前的Ability的icon作为应用的icon。<br /> 说明：应用的“icon”和“label”是用户可感知配置项，需要区别于当前所有已有的应用“icon”或“label”（至少有一个不同）。 | 字符串     | 可缺省，缺省值为空。                                     |
| label            | 标识Ability对用户显示的名称。取值可以是Ability名称，也可以是对该名称的资源索引，以支持多语言。如果在该Ability的skills属性中，actions的取值包含 “action.system.home”，entities取值中包含“entity.system.home”，则该Ability的label将同时作为应用的label。如果存在多个符合条件的Ability，则取位置靠前的Ability的label作为应用的label。<br /> 说明： 应用的“icon”和“label”是用户可感知配置项，需要区别于当前所有已有的应用“icon”或“label”（至少有一个不同）。该标签为资源文件中定义的字符串的引用，或以"{}"包括的字符串。该标签最大长度为255。 | 字符串     | 可缺省，缺省值为空。                                     |
| uri              | 标识Ability的统一资源标识符。该标签最大长度为255。           | 字符串     | 可缺省，对于data类型的Ability不可缺省。                  |
| launchType       | 标识Ability的启动模式，支持“standard”和“singleton”两种模式：<br />standard：表示该Ability可以有多实例。该模式适用于大多数应用场景。<br />singleton：表示该Ability在所有任务栈中仅可以有一个实例。例如，具有全局唯一性的呼叫来电界面即采用“singleton”模式。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串     | 可缺省，缺省值为“singleton”。                            |
| visible          | 标识Ability是否可以被其他应用调用。<br />true：可以被其他应用调用。<br />false：不能被其他应用调用。 | 布尔类型   | 可缺省，缺省值为“false”。                                |
| permissions      | 标识其他应用的Ability调用此Ability时需要申请的权限集合，一个数组元素为一个权限名称。通常采用反向域名格式（最大255字节），取值为系统预定义的权限。 | 字符串数组 | 可缺省，缺省值为空。                                     |
| skills           | 标识Ability能够接收的want的特征。                            | 对象数组   | 可缺省，缺省值为空。                                     |
| deviceCapability | 标识Ability运行时要求设备具有的能力，采用字符串数组的格式表示。该标签为数组，支持最多配置512个元素，单个元素最大字节长度为64. | 字符串数组 | 可缺省，缺省值为空。                                     |
| metaData         | 元数据，参考表13。                                           | 对象       | 可缺省，缺省值为空。                                     |
| type             | 标识Ability的类型。取值范围如下：<br />page：表示基于Page模板开发的FA，用于提供与用户交互的能力。<br />service：表示基于Service模板开发的PA，用于提供后台运行任务的能力。<br />data：表示基于Data模板开发的PA，用于对外部提供统一的数据访问抽象。<br />CA：表示支持其他应用以窗口方式调起该Ability。 | 字符串     | 不可缺省。                                                   |
| orientation      | 标识该Ability的显示模式。该标签仅适用于page类型的Ability。取值范围如下：<br />unspecified：由系统自动判断显示方向。<br />landscape：横屏模式。<br />portrait：竖屏模式。<br />followRecent：跟随栈中最近的应用。 | 字符串     | 可缺省，缺省值为“unspecified”。                          |
| backgroundModes  | 标识后台服务的类型，可以为一个服务配置多个后台服务类型。该标签仅适用于service类型的Ability。取值范围如下：<br />dataTransfer：通过网络/对端设备进行数据下载、备份、分享、传输等业务。<br />audioPlayback：音频输出业务。<br />audioRecording：音频输入业务。<br />pictureInPicture：画中画、小窗口播放视频业务。<br />voip：音视频电话、VOIP业务。<br />location：定位、导航业务。<br />bluetoothInteraction：蓝牙扫描、连接、传输业务。<br />wifiInteraction：WLAN扫描、连接、传输业务。<br />screenFetch：录屏、截屏业务。<br />multiDeviceConnection：多设备互联业务 | 字符串数组 | 可缺省，缺省值为空。                                     |
| grantPermission  | 指定是否可以向Ability内任何数据授予权限。                    | 布尔值     | 可缺省，缺省值为空。                                     |
| readPermission   | 标识读取Ability的数据所需的权限。该标签仅适用于data类型的Ability。取值为长度不超过255字节的字符串。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串     | 可缺省，缺省值为空。                                       |
| writePermission  | 标识向Ability写数据所需的权限。该标签仅适用于data类型的Ability。取值为长度不超过255字节的字符串。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串     | 可缺省，缺省值为空。                                       |
| configChanges    | 标识Ability关注的系统配置集合。当已关注的配置发生变更后，Ability会收到onConfigurationUpdated回调。取值范围：<br />mcc：表示IMSI移动设备国家/地区代码（MCC）发生变更。典型场景：检测到SIM并更新MCC。<br />mnc：IMSI移动设备网络代码（MNC）发生变更。典型场景：检测到SIM并更新MNC。<br />locale：表示语言区域发生变更。典型场景：用户已为设备文本的文本显示选择新的语言类型。<br />layout：表示屏幕布局发生变更。典型场景：当前有不同的显示形态都处于活跃状态。<br />fontSize：表示字号发生变更。典型场景：用户已设置新的全局字号。<br />orientation：表示屏幕方向发生变更。典型场景：用户旋转设备。<br />density：表示显示密度发生变更。典型场景：用户可能指定不同的显示比例，或当前有不同的显示形态同时处于活跃状态。<br />size：显示窗口大小发生变更。<br />smallestSize：显示窗口较短边的边长发生变更。<br />colorMode：颜色模式发生变更。 | 字符串数组 | 可缺省，缺省值为空。                                       |
| mission          | 标识Ability指定的任务栈。该标签仅适用于page类型的Ability。默认情况下应用中所有Ability同属一个任务栈。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串     | 可缺省，缺省为应用的包名。                               |
| targetAbility    | 标识当前Ability重用的目标Ability。该标签仅适用于page类型的Ability。如果配置了targetAbility属性，则当前Ability（即别名Ability）的属性中仅name、icon、label、visible、permissions、skills生效，其它属性均沿用targetAbility中的属性值。目标Ability必须与别名Ability在同一应用中，且在配置文件中目标Ability必须在别名之前进行声明。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。 | 字符串     | 可缺省，缺省值为空。表示当前Ability不是一个别名Ability。 |
| formsEnabled     | 标识Ability是否支持卡片（forms）功能。该标签仅适用于page类型的Ability。<br />true：支持卡片能力。<br />false：不支持卡片能力。 | 布尔值 | 可缺省，缺省值为“false”。                                |
| forms            | 标识服务卡片的属性。该标签仅当formsEnabled为“true”时，才能生效。参考表27。 | 对象数组   | 可缺省，缺省值为空。                                     |
| srcLanguage      | Ability开发语言的类型，开发者创建工程时由开发者手动选择开发语言。                                      | 字符串     | 可缺省，取值为js或ets                                      |
| srcPath          | 该标签标识Ability对应的JS组件代码路径，该标签最大长度为127字节。                        | 字符串     | 可缺省，缺省值为空。                                     |
| uriPermission    | 标识该Ability有权访问的应用程序数据。此属性由模式和路径子属性组成。此属性仅对类型提供者的能力有效。运行OHOS的设备不支持此属性。参考表18。 | 对象       | 可缺省，缺省值为空。                                     |
| startWindowIcon    | 标识该Ability启动页面图标资源文件的索引。该标签仅适用于page类型的ability。取值示例：$media:icon。 | 字符串       | 可缺省，缺省值为空。|
| startWindowBackground    | 标识该Ability启动页面背景颜色资源文件的索引。该标签仅适用于page类型的ability。取值示例：$color:red。 | 字符串       | 可缺省，缺省值为空。|
| removeMissionAfterTerminate    | 该标签标识ability销毁后是否从任务列表中移除任务。该标签仅适用于page类型的ability。true表示销毁后移除任务， false表示销毁后不移除任务。 | 布尔值       | 可缺省，缺省值为false。 |

表18 uriPermission对象的内部结构说明

| 属性名称 | 含义                    | 数据类型 | 是否可缺省                |
| -------- | ----------------------- | -------- | ------------------------- |
| path     | uriPermission标识的路径，该标签最大字节长度为255个字节。 | 字符串   | 不可缺省。                  |
| mode     | uriPermission的匹配模式 | 字符串   | 可缺省，缺省值为default。 |

abilities示例：

```json
"abilities": [
    {
        "name": ".MainAbility",
        "description": "test main ability",
        "icon": "$media:ic_launcher",
        "label": "$media:example",
        "launchType": "standard",
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
        "label": "$media:example",
        "launchType": "standard",
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

表19 skills对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型   | 是否可缺省           |
| -------- | ------------------------------------------------------------ | ---------- | -------------------- |
| actions  | 标识能够接收的want的action值，可以包含一个或多个action。取值通常为系统预定义的action值。 | 字符串数组 | 可缺省，缺省值为空。 |
| entities | 标识能够接收的want的Ability的类别（如视频、桌面应用等），可以包含一个或多个entity。 | 字符串数组 | 可缺省，缺省值为空。 |
| uris     | 该标签标识向want过滤器添加数据规范集合。该规范可以是只有数据类型（mimeType属性），可以是只有URI，也可以是既有数据类型又有URI。URI由其各个部分的单独属性指定：\<scheme>://\<host>:\<port>/[\<path>\|\<pathStartWith>\|\<pathRegx>]。其中，scheme字段配置为uri时必配；当只设置数据类型（mimeType）时，则scheme字段为非必配项。参考表20。 | 对象数组   | 可缺省，缺省值为空。 |

表20 uris对象的内部结构说明

| 属性名称      | 含义                       | 数据类型 | 是否可缺省           |
| ------------- | -------------------------- | -------- | -------------------- |
| scheme        | 标识uri的scheme值。        | 字符串   | 不可缺省。           |
| host          | 标识uri的host值。          | 字符串   | 可缺省，缺省值为空。 |
| port          | 标识uri的port值。          | 字符串   | 可缺省，缺省值为空。 |
| pathStartWith | 标识uri的pathStartWith值。 | 字符串   | 可缺省，缺省值为空。 |
| path          | 标识uri的path值。          | 字符串   | 可缺省，缺省值为空。 |
| pathRegx      | 标识uri的pathRegx值。      | 字符串   | 可缺省，缺省值为空。 |
| type          | 标识uri的type值。          | 字符串   | 可缺省，缺省值为空。 |

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

表21  reqPermissions权限申请字段说明

| 属性名称   | 含义                                                         | 数据类型 | 是否可缺省         |
| ---------- | ------------------------------------------------------------ | -------- | ------------------ |
| name      | 需要使用的权限名称。 | 字符串 | 不可缺省。 |
| reason    | 描述申请权限的原因。需要做多语种适配。 | 字符串 | 分情况：当申请的权限为user_grant时，必须填写此字段，否则不允许在应用市场上架；其它权限可缺省，缺省值为空。 |
| usedScene | 描述权限使用的场景和时机。场景类型如下两种：</br>ability：ability的名称，可配置多个。</br>when：调用时机，可填的值有inuse（使用时）、always（始终） | 对象 | 可缺省，缺省值为空。when可缺省，缺省值为“inuse” |
具体示例可参考[访问控制开发指导](../security/accesstoken-guidelines.md#fa模型)。

表21 usedScene对象内部结构说明

| 属性名称 | 含义   | 数据类型 | 是否可缺省 |
| ------- | --------------------| -------- | ------ |
| ability  | 标识哪些Ability需要此权限，里面配置Ability的名称。| 字符串数组   | 可缺省，缺省表示所有Ability都需要此权限。 |
| when | 标识使用此权限的使用时间：</br>inuse：使用时需要此权限。</br>always：所有时间都需要此权限。 | 枚举值   | 可缺省，缺省值为空。 |

表22  js对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省               |
| -------- | ------------------------------------------------------------ | -------- | ------------------------ |
| name     | 标识JS Component的名字。该标签不可缺省，默认值为default。    | 字符串   | 不可缺省。                 |
| pages    | 标识JS Component的页面用于列举JS Component中每个页面的路由信息[页面路径+页面名称]。该标签不可缺省，取值为数组，数组第一个元素代表JS FA首页。 | 字符串数组     | 不可缺省。                 |
| window   | 用于定义与显示窗口相关的配置。该标签仅适用于默认设备、平板、智慧屏、车机、智能穿戴。参考表23。 | 对象     | 可缺省。                   |
| type     | 标识JS应用的类型。取值范围如下：<br />normal：标识该JS Component为应用实例。<br />form：标识该JS Component为卡片实例。 | 字符串   | 可缺省，缺省值为“normal” |
| mode     | 定义JS组件的开发模式。参考表24。                             | 对象     | 可缺省，缺省值为空。       |

表23 window对象的内部结构说明

| 属性名称        | 含义                                                         | 数据类型 | 是否可缺省              |
| --------------- | ------------------------------------------------------------ | -------- | ----------------------- |
| designWidth     | 标识页面设计基准宽度。以此为基准，根据实际设备宽度来缩放元素大小。 | 数值     | 可缺省，缺省值为720px。   |
| autoDesignWidth | 标识页面设计基准宽度是否自动计算。当配置为true时，designWidth将会被忽略，设计基准宽度由设备宽度与屏幕密度计算得出。 | 布尔值   | 可缺省，缺省值为“false”。 |

表24 mode对象的内部结构说明

| 属性名称 | 含义                 | 数据类型                            | 是否可缺省                  |
| -------- | -------------------- | ----------------------------------- | --------------------------- |
| type     | 定义JS组件的功能类型 | 字符串，取值为"pageAbility"、"form" | 可缺省，缺省值为pageAbility。 |
| syntax   | 定义JS组件的语法类型 | 字符串，取值为"hml"，"ets"          | 可缺省，缺省值为"hml"。       |

js示例：

```json
"js": [
    {
        "name": "default", 
        "pages": [            
            "pages/index/index",
            "pages/detail/detail"
        ],         
        "window": {
            "designWidth": 720,
            "autoDesignWidth": false
        },
        "type": "form"
    }
]
```

表25 shortcuts对象的内部结构说明

| 属性名称   | 含义                                                         | 数据类型 | 是否可缺省         |
| ---------- | ------------------------------------------------------------ | -------- | ------------------ |
| shortcutId | 标识快捷方式的ID。字符串的最大长度为63字节。                 | 字符串   | 不可缺省。           |
| label      | 标识快捷方式的标签信息，即快捷方式对外显示的文字描述信息。取值可以是描述性内容，也可以是标识label的资源索引。字符串最大长度为63字节。 | 字符串   | 可缺省，缺省值为空。 |
| icon       | 标识快捷方式的图标信息。取值为表示icon的资源索引。           | 字符串   | 可缺省，缺省值为空。 |
| intents    | 标识快捷方式内定义的目标intent信息集合，每个intent可配置两个子标签，targetClass, targetBundle。参考表26。 | 对象数组 | 可缺省，缺省值为空。 |

表26 intents对象的内部结构说明

| 属性名称     | 含义                                    | 数据类型 | 是否可缺省           |
| ------------ | --------------------------------------- | -------- | -------------------- |
| targetClass  | 标识快捷方式目标类名。                  | 字符串   | 可缺省，缺省值为空。 |
| targetBundle | 标识快捷方式目标Ability所在应用的包名。 | 字符串   | 可缺省，缺省值为空。 |

shortcuts示例：

```json
"shortcuts": [
    {
        "shortcutId": "id",
        "label": "$string:shortcut",
        "intents": [
            {
                "targetBundle": "com.example.world.test",
                "targetClass": "com.example.world.test.entry.MainAbility"
            }
        ]
    }
]
```

表27 forms对象的内部结构说明

| 属性名称            | 含义                                                         | 数据类型   | 是否可缺省               |
| ------------------- | ------------------------------------------------------------ | ---------- | ------------------------ |
| name                | 标识卡片的类名。字符串最大长度为127字节。                    | 字符串     | 不可缺省。                 |
| description         | 标识卡片的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。字符串最大长度为255字节。 | 字符串     | 可缺省，缺省值为空。       |
| isDefault           | 标识该卡片是否为默认卡片，每个Ability有且只有一个默认卡片。<br />true：默认卡片。<br />false：非默认卡片。 | 布尔值     | 不可缺省。                 |
| type                | 标识卡片的类型。取值范围如下：<br />JS：JS卡片。             | 字符串     | 不可缺省。                 |
| colorMode           | 标识卡片的主题样式，取值范围如下：<br />auto：自适应。<br />dark：深色主题。<br />light：浅色主题。 | 字符串     | 可缺省，缺省值为“auto”。 |
| supportDimensions   | 标识卡片支持的外观规格，取值范围：<br />1 * 2：表示1行2列的二宫格。<br />2 * 1：表示2行1列的二宫格。<br />2 * 2：表示2行2列的四宫格。<br />2 * 4：表示2行4列的八宫格。<br />4 * 4：表示4行4列的十六宫格。 | 字符串数组 | 不可缺省。                 |
| defaultDimension    | 标识卡片的默认外观规格，取值必须在该卡片supportDimensions配置的列表中。 | 字符串     | 不可缺省。                 |
| updateEnabled       | 标识卡片是否支持周期性刷新，取值范围：<br />true：表示支持周期性刷新，可以在定时刷新（updateDuration）和定点刷新（scheduledUpdateTime）两种方式任选其一，优先选择定时刷新。<br />false：表示不支持周期性刷新。 | 布尔类型   | 不可缺省。                 |
| scheduledUpdateTime | 标识卡片的定点刷新的时刻，采用24小时制，精确到分钟。         | 字符串     | 可缺省，缺省值为“0:0”。  |
| updateDuration      | 标识卡片定时刷新的更新周期，单位为30分钟，取值为自然数。<br />当取值为0时，表示该参数不生效。<br />当取值为正整数N时，表示刷新周期为30*N分钟。 | 数值       | 可缺省，缺省值为“0”。    |
| formConfigAbility   | 标识用于调整卡片的设施或活动的名称。                         | 字符串     | 可缺省，缺省值为空。     |
| formVisibleNotify   | 标识是否允许卡片使用卡片可见性通知                           | 字符串     | 可缺省，缺省值为空。     |
| jsComponentName     | 标识JS卡片的Component名称。字符串最大长度为127字节。仅当卡片类型为JS卡片时，需要配置该标签。 | 字符串     | 不可缺省。                 |
| metaData            | 标识卡片的自定义信息，包含customizeData数组标签。参考表13。  | 对象       | 可缺省，缺省值为空。     |
| customizeData       | 标识自定义的卡片信息。参考表28。                             | 对象数组   | 可缺省，缺省值为空。     |

表28 customizeData对象内部结构说明

| 属性名称 | 含义                                                | 数据类型 | 是否可缺省           |
| -------- | --------------------------------------------------- | -------- | -------------------- |
| name     | 标识数据项的键名称。字符串最大长度为255字节。       | 字符串   | 可缺省，缺省值为空。 |
| value    | 标识数据项的值。字符串最大长度为255字节。           | 字符串   | 可缺省，缺省值为空。 |
| extra    | 标识当前custom数据的格式，取值为表示extra的资源值。 | 字符串   | 可缺省，缺省值为空。 |

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
        "formConfigAbility": "ability://com.example.myapplication.fa/.MainAbility",
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

表29  distroFilter对象的内部结构说明

| 属性名称      | 含义                                                         | 数据类型 | 是否可缺省           |
| ------------- | ------------------------------------------------------------ | -------- | -------------------- |
| apiVersion    | 标识支持的apiVersion范围。参考表30。                         | 对象     | 可缺省，缺省值为空。 |
| screenShape   | 标识屏幕形状的支持策略。参考表31。                           | 对象数组 | 可缺省，缺省值为空。 |
| screenWindow  | 标识应用运行时窗口的分辨率支持策略。该字段仅支持对轻量级智能穿戴设备进行配置。参考表32。 | 对象数组 | 可缺省，缺省值为空。 |
| screenDensity | 标识屏幕的像素密度（dpi：Dots Per  Inch）。参考表33。        | 对象数组 | 可缺省，缺省值为空。 |
| countryCode   | 标识分发应用时的国家码。具体值参考ISO-3166-1的标准，支持多个国家和地区的枚举定义。参考表34。 | 对象数组 | 可缺省，缺省值为空。 |

表30 apiVersion对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 支持的取值为API Version存在的整数值，例如4、5、6。场景示例：某应用，针对相同设备型号，同时在网的为使用API 5和API 6开发的两个软件版本，则允许上架2个entry类型的安装包，分别支持到对应设备侧软件版本的分发。 | 数组     | 可缺省，缺省值为空。 |

表31 screenShape对象的内部结构说明	

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 支持的取值为circle（圆形）、rect（矩形）。场景示例：针对智能穿戴设备，可为圆形表盘和矩形表盘分别提供不同的HAP。 | 数组     | 可缺省，缺省值为空。 |

表32 screenWindow对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 单个字符串的取值格式为：“宽 * 高”，取值为整数像素值，例如“454 * 454”。 | 数组     | 可缺省，缺省值为空。 |

表33 screenDensity对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型 | 是否可缺省           |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串   | 可缺省，缺省值为空。 |
| value    | 取值范围如下：<br />sdpi：表示小规模的屏幕密度（Small-scale Dots Per Inch），适用于dpi取值为（0,120]的设备。<br />mdpi：表示中规模的屏幕密度(Medium-scale Dots Per Inch)，适用于dpi取值为（120,160]的设备。<br />ldpi：表示大规模的屏幕密度(Large-scale Dots Per Inch)，适用于dpi取值为（160,240]的设备。<br />xldpi：表示特大规模的屏幕密度(Extra Large-scale Dots Per Inch)，适用于dpi取值为（240,320]的设备。<br />xxldpi：表示超大规模的屏幕密度(Extra Extra Large-scale Dots Per Inch)，适用于dpi取值为（320,480]的设备。<br />xxxldpi：表示超特大规模的屏幕密度(Extra Extra Extra Large-scale Dots Per Inch)，适用于dpi取值为（480,640]的设备。 | 数组     | 可缺省，缺省值为空。 |

表34 countryCode对象的内部结构说明

| 属性名称 | 含义                                                         | 数据类型   | 是否可缺省           |
| -------- | ------------------------------------------------------------ | ---------- | -------------------- |
| policy   | 标识该子属性取值的黑白名单规则。配置为“exclude”或“include”。“include”表示该字段取值为白名单，满足value枚举值匹配规则的表示匹配该属性。 | 字符串     | 可缺省，缺省值为空。 |
| value    | 该标签标识应用需要分发的国家码，标签为字符串数组，子串表示支持的国家或地区，由两个大写字母表示。 | 字符串数组 | 可缺省，缺省值为空。 |

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

表35 commonEvents对象的内部结构说明

| 属性名称   | 含义                                                         | 数据类型   | 是否可缺省         |
| ---------- | ------------------------------------------------------------ | ---------- | ------------------ |
| name       | 标识静态公共事件名称，该标签最大长度为127字节。                                             | 字符串     | 不可缺省。           |
| permission | 此标签标识实现静态公共事件所需要申请的权限，该标签最大长度为127字节。                   | 字符串 | 可缺省，缺省值为空。 |
| data       | 标识配置当前静态公共事件要携带的附加数据数组。                 | 字符串数组 | 可缺省，缺省值为空。 |
| type       | 该标签用于配置当前静态公共事件的分类数组。                     | 字符串数组 | 可缺省，缺省值为空。 |
| events     | 此标签标识可接收的意图的一组事件值。一般由系统预定义，也可以自定义。 | 字符串数组 | 不可缺省。           |

commonEvents示例：

```json
"commonEvents": [
    {
        "name":"MainAbility",
        "permission": "string",
        "data":[
            "string",
            "string"
        ],
        "events": [
            "string",
            "string"
        ]
    }
]
```

表36 testRunner对象的内部结构说明

| 属性名称 | 含义                 | 数据类型 | 是否可缺省 |
| -------- | -------------------- | -------- | ---------- |
| name     | 标识测试框架对象名称，该标签最大长度为255字节。 | 字符串   | 不可缺省。   |
| srcPath  | 标识测试框架代码路径，该标签最大长度为255字节。 | 字符串   | 不可缺省。   |

```json
"testRunner": {
    "name": "myTestRunnerName",
    "srcPath": "etc/test/TestRunner.ts"
}
```

表37 definePermissions对象内部结构说明

definePermission仅支持系统应用配置，三方应用配置不生效。

| 属性名称                | 含义                                                         | 数据类型 | 是否可缺省 |
| ----------------------- | ------------------------------------------------------------ | -------- | ---------- |
| name                    | 标识权限的名称，该标签最大长度为255字节。                                               | 字符串   | 不可缺省。   |
| grantMode               | 标识权限的授予方式，支持如下两种授予模式：<br />system_grant:安装后系统自动授予该权限。<br />user_grant:使用时动态申请，用户授权后才可使用。 | 字符串   | 可缺省，缺省值为system_grant。   |
| availableLevel          | 标识权限限制类别。可选值如下：<br />system_core：系统核心权限。<br />system_basic：系统基础权限。<br />normal：普通权限。所有应用允许申请的权限。 | 字符串   | 可缺省，缺省值为normal。     |
| provisionEnable         | 标识权限是否支持证书方式申请权限，包括高级别的权限。配置为true标识需要开发者可以通过provision方式申请权限。 | 布尔值   | 可缺省，缺省值为true。     |
| distributedSceneEnabled | 标识权限是否支持分布式场景下使用该权限。 | 布尔值   | 可缺省，缺省值为false。     |
| label                   | 标识权限的简短描述，配置为对描述内容的资源索引。             | 字符串   | 可缺省，缺省值为空。     |
| description             | 标识权限的详细描述，可以是字符串（最大长度255字节），或者为对描述内容的资源索引。 | 字符串   | 可缺省，缺省值为空。     |
