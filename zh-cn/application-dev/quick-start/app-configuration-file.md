# app.json5配置文件

## 配置文件示例


先通过一个示例，整体认识一下app.json5配置文件。

```json
{
  "app": {
    "bundleName": "com.application.myapplication",
    "vendor": "example",
    "versionCode": 1000000,
    "versionName": "1.0.0",
    "icon": "$media:layered_image",
    "label": "$string:app_name",
    "description": "$string:description_application",
    "minAPIVersion": 9,
    "targetAPIVersion": 9,
    "apiReleaseType": "Release",
    "debug": false,
    "car": {
      "minAPIVersion": 8
    },
    "targetBundleName": "com.application.test",
    "targetPriority": 50,
    "appEnvironments": [
      {
        "name":"name1",
        "value": "value1"
      }
    ],
    "maxChildProcess": 5,
    "multiAppMode": {
      "multiAppModeType": "multiInstance",
      "maxCount": 5
    },
    "hwasanEnabled": false,
    "ubsanEnabled": false,
    "cloudFileSyncEnabled": false,
    "configuration": "$profile:configuration",
    "assetAccessGroups": [
      "com.ohos.photos",
      "com.ohos.screenshot",
      "com.ohos.note"
    ]
  },
}
```
## 配置文件标签

app.json5配置文件包含以下标签。


  **表1** app.json5配置文件标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| bundleName | 标识应用的Bundle名称，用于标识应用的唯一性。命名规则如下&nbsp;：<br/>-&nbsp;必须为以点号（.）分隔的字符串，且至少包含三段，每段中仅允许使用英文字母、数字、下划线（_）。<br/>-&nbsp;首段以英文字母开头，非首段以数字或英文字母开头，每一段以数字或者英文字母结尾。<br/>-&nbsp;不允许多个点号（.）连续出现。<br/>-&nbsp;字符串最小长度为7字节，最大长度128字节。<br/>-&nbsp;推荐采用反域名形式命名（如“com.example.demo”，建议第一级为域名后缀com，第二级为厂商/个人名，第三级为应用名，也可以多级）。<br/>对于随系统源码编译的应用，建议命名为“com.ohos.demo”形式，其中的ohos标识系统应用。 | 字符串 | 该标签不可缺省。 |
| bundleType| 标识应用的Bundle类型，用于区分应用或者原子化服务。支持的取值如下：<br/>-&nbsp;app：当前Bundle为应用。<br/>-&nbsp;atomicService：当前Bundle为原子化服务。<br/>-&nbsp;shared：当前Bundle为共享库应用，预留字段。<!--Del--><br/>-&nbsp;appService：当前Bundle为系统级共享库应用，仅供系统应用使用。<!--DelEnd--><br/>-&nbsp;appPlugin：当前Bundle为应用的插件包。从API version 19开始，支持该字段。 | 字符串| 该标签可缺省，缺省值为app。 |
| debug | 标识应用是否可调试。<br/>-&nbsp;true：可调试，一般用于开发阶段。<br/>-&nbsp;false：不可调试，一般用于发布阶段。 | 布尔值 | 由DevEco Studio编译构建时生成。该标签可缺省，缺省值为false。 |
| [icon](#icon标签) | 标识[应用的图标](../application-models/application-component-configuration-stage.md)，取值为图标资源文件的索引。 | 字符串 | 该标签不可缺省。 |
| label | 标识[应用的名称](../application-models/application-component-configuration-stage.md)，取值为字符串资源的索引，字符串长度不超过63字节。 | 字符串 | 该标签不可缺省。 |
| description | 标识应用的描述信息，取值为长度不超过255字节的字符串，内容为描述信息的字符串资源索引。该字段可用于应用信息展示，如在应用的关于页面，取该字段展示应用描述信息。 | 字符串 | 该标签可缺省，缺省值为空。 |
| vendor | 标识对应用开发厂商的描述，取值为长度不超过255字节的字符串。该字段可用于展示开发厂商信息，如在应用的关于页面，取该字段展示开发厂商信息。 | 字符串 | 该标签可缺省，缺省值为空。 |
| versionCode | 标识应用的版本号，取值为小于2^31次方的正整数。此数字仅用于确定某个版本是否比另一个版本更新，数值越大表示版本越高。<br/>开发者可以将该值设置为任何正整数，但是必须确保应用的新版本都使用比旧版本更大的值。 | 数值 | 该标签不可缺省。 |
| versionName | 标识向用户展示的应用版本号。<br/>取值为长度不超过127字节的字符串，仅由数字和点构成，推荐采用“A.B.C.D”四段式的形式。四段式推荐的含义如下所示。<br/>第一段：主版本号/Major，范围0\~99，重大修改的版本，如实现新的大功能或重大变化。<br/>第二段：次版本号/Minor，范围0\~99，表示实现较突出的特点，如新功能添加或大问题修复。<br/>第三段：特性版本号/Feature，范围0\~99，标识规划的新版本特性。<br/>第四段：修订版本号/Patch，范围0\~999，表示维护版本，如修复bug。 | 字符串 | 该标签不可缺省。 |
| minCompatibleVersionCode | 标识应用能够兼容的最低历史版本号，用于应用多设备之间协同、数据迁移、跨设备兼容性判断，该字段为预留字段，暂未使用。取值范围为0~2147483647。 | 数值 | 该标签可缺省，缺省值等于versionCode标签值。 |
| minAPIVersion | 标识应用运行需要的SDK的API最小版本。取值范围为0~2147483647。 | 数值 | 应用编译构建时由build-profile.json5中的compatibleSdkVersion自动生成。 |
| targetAPIVersion | 标识应用运行需要的API目标版本。取值范围为0~2147483647。 | 数值 | 应用编译构建时由build-profile.json5中的compileSdkVersion自动生成。 |
| apiReleaseType | 标识应用运行需要的API目标版本的类型，采用字符串类型表示。取值为“CanaryN”、“BetaN”或者“Release”，其中，N代表大于零的整数。<br/>-&nbsp;Canary：受限发布的版本。<br/>-&nbsp;Beta：公开发布的Beta版本。<br/>-&nbsp;Release：公开发布的正式版本。 | 字符串 | 应用编译构建时根据当前使用的SDK的Stage自动生成。即便手动配置了取值，编译构建时也会被覆盖。 |
| accessible | 标识应用是否能访问应用的安装目录，仅针对Stage模型的系统应用和预置应用生效。<br/>-&nbsp;true：当前应用可以访问应用的安装目录。<br/>-&nbsp;false：当前应用不可以访问应用的安装目录。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| multiProjects | 标识当前工程是否支持多个工程的联合开发。<br/>-&nbsp;true：当前工程支持多个工程的联合开发。多工程开发可参考[多工程构建](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-multi-projects)。<br/>-&nbsp;false：当前工程不支持多个工程的联合开发。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| asanEnabled | 标识应用程序是否开启[asan检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-asan)，用于辅助定位buffer越界造成的crash问题。<br/>-&nbsp;true：当前工程开启asan检测。<br/>-&nbsp;false：当前工程不开启asan检测。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| tablet | 标识对tablet设备做的特殊配置，可以配置的属性字段有上文提到的：minAPIVersion。<br/>如果使用该属性对tablet设备做了特殊配置，则应用在tablet设备中会采用此处配置的属性值，并忽略在app.json5公共区域配置的属性值。 | 对象 | 该标签可缺省，缺省时tablet设备使用app.json5公共区域配置的属性值。 |
| tv | 标识对tv设备做的特殊配置，可以配置的属性字段有上文提到的：minAPIVersion。<br/>如果使用该属性对tv设备做了特殊配置，则应用在tv设备中会采用此处配置的属性值，并忽略在app.json5公共区域配置的属性值。 | 对象 | 该标签可缺省，缺省时tv设备使用app.json5公共区域配置的属性值。 |
| wearable | 标识对wearable设备做的特殊配置，可以配置的属性字段有上文提到的：minAPIVersion。<br/>如果使用该属性对wearable设备做了特殊配置，则应用在wearable设备中会采用此处配置的属性值，并忽略在app.json5公共区域配置的属性值。 | 对象 | 该标签可缺省，缺省时wearable设备使用app.json5公共区域配置的属性值。 |
| car | 标识对car设备做的特殊配置，可以配置的属性字段有上文提到的：minAPIVersion。<br/>如果使用该属性对car设备做了特殊配置，则应用在car设备中会采用此处配置的属性值，并忽略在app.json5公共区域配置的属性值。 | 对象 | 该标签可缺省，缺省时car设备使用app.json5公共区域配置的属性值。 |
| default | 标识对default设备做的特殊配置，可以配置的属性字段有上文提到的：minAPIVersion。<br/>如果使用该属性对default设备做了特殊配置，则应用在default设备中会采用此处配置的属性值，并忽略在app.json5公共区域配置的属性值。 | 对象 | 该标签可缺省，缺省时default设备使用app.json5公共区域配置的属性值。 |
|targetBundleName|标识当前包所指定的目标应用, 标签值的取值规则和范围与bundleName标签一致。配置该字段的应用为具有overlay特征的应用。|字符串|该标签可缺省，缺省值为空。|
|targetPriority|标识当前应用的优先级，取值范围为1~100。配置targetBundleName字段之后，才支持配置该字段。|数值|该标签可缺省，缺省值为1。|
|generateBuildHash |标识当前应用的所有HAP和HSP是否由打包工具生成哈希值。<br/>该字段配置为true时，该应用下的所有HAP和HSP都会由打包工具生成对应的哈希值。系统OTA升级时，若应用的versionCode保持不变，可根据哈希值判断应用是否需要升级。<br/>-&nbsp;true：当前应用下所有HAP和HSP都会由打包工具生成对应的哈希值。<br/>-&nbsp;false：当前应用下所有HAP和HSP都不会由打包工具生成对应的哈希值。<br/>**说明：**<br/>该字段仅对预置应用生效。|布尔值|该标签可缺省，缺省值为false。|
| GWPAsanEnabled | 标识应用程序是否开启[GWP-asan](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-gwpasan-detection#section2735718353)堆内存检测工具，用于对内存越界、内存释放后使用等内存破坏问题进行分析。<br/>-&nbsp;true：应用程序开启GWP-asan检测。<br/>-&nbsp;false：应用程序不开启GWP-asan检测。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| [appEnvironments](#appenvironments标签) | 标识当前模块配置的应用环境变量。 | 对象数组 | 该标签可缺省，缺省值为空。 |
| maxChildProcess | 标识当前应用自身可创建的子进程的最大个数，取值范围为0到512，0表示不限制，当应用有多个模块时，以entry模块的配置为准。 | 数值 | 该标签可缺省，缺省时使用系统配置的默认值。 |
| [multiAppMode](#multiappmode标签) | 标识当前应用配置的多开模式。仅bundleType为app的应用的entry或feature模块配置有效，存在多个模块时，以entry模块的配置为准。 | 对象 | 该标签可缺省，缺省值为空。 |
| hwasanEnabled | 标识应用程序是否开启[HWAsan检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hwasan)。HWAsan(HardWare-assisted AddressSanitizer)是利用Top-Byte-Ignore特性实现的增强版Asan，与Asan相比HWAsan的内存开销更低，检测到的内存错误范围更大。<br/>-&nbsp;true：当前工程开启HWAsan检测。<br/>-&nbsp;false：当前工程不开启HWAsan检测。<br/>**说明：** <br/>从API version 14开始，支持该字段。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| ubsanEnabled | 标识应用程序是否开启UBsan检测。<br/>UBsan(Undefined Behavior Sanitizer)是一个用于运行时检测程序中未定义行为的工具，旨在帮助开发人员发现代码中潜在的错误和漏洞。<br/>-&nbsp;true：当前工程开启UBsan检测。<br/>-&nbsp;false：当前工程不开启UBsan检测。<br/>**说明：** <br/>从API version 14开始，支持该字段。 | 布尔值 | 该标签可缺省，缺省值为false。 |
| cloudFileSyncEnabled | 标识当前应用是否启用端云文件同步能力。 <br/>-&nbsp;true：当前应用启用端云文件同步能力。<br/>-&nbsp;false：当前应用不启用端云文件同步能力。 | 布尔值 | 该标签可缺省，缺省值为false。  |
| [configuration](#configuration标签) | 标识当前应用字体大小跟随系统配置的能力。<br/>该标签是一个profile文件资源，用于指定描述应用字体大小跟随系统变更的配置文件。| 字符串 | 该标签可缺省，缺省时configuration使用不跟随系统默认设定。 |
| assetAccessGroups | 配置应用的Group ID，它和Developer ID一起组成群组信息。<br/>打包HAP时，DevEco使用开发者证书对群组信息签名，其中群组信息由Developer ID（由应用市场分配）+ Group ID（开发者配置）组成。<br/>**说明：** <br/>从API version 18开始，支持该字段。| 字符串数组 | 该标签可缺省，缺省值为空。 |
| appPreloadPhase | 配置应用预加载到不同阶段。支持的取值如下：<br/>-processCreated：预加载到进程创建完成阶段。<br/>-abilityStageCreated：预加载到[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)创建完成阶段。<br/>-windowStageCreated：预加载到[WindowStage](../reference/apis-arkui/arkts-apis-window-WindowStage.md#windowstage9)创建完成阶段。<br/>**说明：** <br/>从API version 20开始，支持该字段。<br>仅在[应用](../reference/apis-ability-kit/js-apis-bundleManager.md#bundletype)的entry模块配置有效。| 字符串| 该标签可缺省，缺省时不进行预加载。 |

## icon标签

此标签标识[应用的图标](../application-models/application-component-configuration-stage.md)和对分层图标配置文件的索引。

分层图标的配置方式如下：

1. 将图标的前景资源和背景资源放在AppScope/resources/base/media目录下，或使用目录下默认存放的前景资源和背景资源。

2. 上述media目录下存在一个分层图标配置文件（layered_image.json），在文件中引用前景资源和背景资源，详见[图标资源规范](https://developer.huawei.com/consumer/cn/doc/design-guides/application-icon-0000001953444009#section634668113212)。

分层图标配置文件示例：

```json
{
  "layered-image"：
    {
      "background":"$media:background", //背景资源
      "foreground":"$media:foreground" //前景资源 
    }    
}
```

icon标签示例：

```json
{
  "app":{
    "icon":"$media:layered_image"
  }
}
```

## appEnvironments标签

此标签标识应用配置的环境变量。应用运行时有时会依赖一些三方库，这些三方库会使用到一些自定义的环境变量，为了不修改三方库的实现逻辑，可以在工程的配置文件中设置自定义的环境变量，以供运行时使用。

**表2** appEnvironments标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name          | 标识环境变量的变量名称。取值为长度不超过4096字节的字符串。 | 字符串  | 该标签可缺省，缺省值为空。 |
| value         | 标识环境变量的值。取值为长度不超过4096字节的字符串。       | 字符串  | 该标签可缺省，缺省值为空。 |

appEnvironments标签示例：

```json
{
  "app": {
    "appEnvironments": [
      {
        "name":"name1",
        "value": "value1"
      }
    ]
  }
}
```

## multiAppMode标签

应用多开模式。

**表3** multiAppMode标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| multiAppModeType          | 标识应用多开模式类型，支持的取值如下：<br/>-&nbsp;multiInstance：多实例模式。该字段仅支持2in1设备，常驻进程不支持该字段。<br/>-&nbsp;appClone：应用分身模式。 | 字符串  | 该标签不可缺省。 |
| maxCount         | 标识最大允许的应用多开个数，支持的取值如下：<br/>-&nbsp;multiInstance模式：取值范围1\~10。<br/>-&nbsp;appClone模式：取值范围1\~5。      | 数值  | 该标签不可缺省。 |

multiAppMode标签示例：

```json
{
  "app": {
    "multiAppMode": {
      "multiAppModeType": "appClone",
      "maxCount": 5
    }
  }
}
```

## configuration标签

该标签是一个profile文件资源，用于指定描述应用字体大小跟随系统变更的配置文件。

configuration标签示例：

```json
{
  "app": {
    "configuration": "$profile:configuration"  
  }
}
```

在开发视图的AppScope/resources/base/profile下面定义配置文件configuration.json，其中文件名"configuration"可自定义，需要和configuration标签指定的信息对应。配置文件中列举了当前应用字体大小跟随系统变化的属性。

   **表4** configuration标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| fontSizeScale | 应用字体大小是否跟随系统，支持的取值如下：<br/>-&nbsp;followSystem：跟随系统。<br/>-&nbsp;nonFollowSystem：不跟随系统。| 字符串 | 该标签可缺省，缺省值为nonFollowSystem。 |
| fontSizeMaxScale | 应用字体大小选择跟随系统后，配置的最大比例，支持的取值：1、1.15、1.3、1.45、1.75、2、3.2。	 <br/> fontSizeScale为nonFollowSystem时，该项不生效。 | 字符串 | 该标签可缺省，缺省值为3.2。 |

configuration标签示例：

```json
{
  "configuration": {
    "fontSizeScale": "followSystem",
    "fontSizeMaxScale": "3.2"
  }
}
```
