# 窗口元数据配置
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## metadata标签

该标签标识HAP的自定义元信息，标签值为数组类型，包含name、value、resource三个子标签。

**表1** metadata标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| name | 标识数据项的名称，取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| value | 标识数据项的值，取值为长度不超过255字节的字符串。 | 字符串 | 该标签可缺省，缺省值为空。 |
| resource | 标识了用户自定义数据，取值为长度不超过255字节的字符串，内容为该数据的资源索引，例如配置成$profile:shortcuts_config，表示指向了/resources/base/profile/shortcuts_config.json配置文件。| 字符串 | 该标签可缺省，缺省值为空。 |

下面给出几种metadata标签的使用场景及示例，开发者也可以根据实际需求自定义设置。

1. 使用metadata标签配置主窗口的默认大小和位置（单位为vp）。其中name取值及对应含义如下：

    * name取值为ohos.ability.window.height表示主窗口的默认高度，value表示高度大小。
    * name取值为ohos.ability.window.width表示主窗口的默认宽度，value表示宽度大小。
    * name取值为ohos.ability.window.left表示主窗口默认左边的位置。value表示配置格式，取值：对齐方式 +/- 偏移量。对齐方式包括center、left和right，默认值为left；当偏移量为0时可以省略。
    * name取值为ohos.ability.window.top表示主窗口顶部的位置。value表示配置格式，取值：对齐方式 +/- 偏移量。对齐方式包括center、top和bottom，默认值为top。如果对齐方式和偏移量同时省略，则按照系统默认的层叠规格处理。

2. 使用metadata标签配置是否移除启动页。配置项为：name取值为enable.remove.starting.window，value取值为true或false，取值为true表示移除启动页、取值为false表示不移除启动页，未配置时默认为false。

3. 使用metadata标签配置主窗启动时是否以最大化状态显示。配置项为：name为ohos.ability.window.isMaximize，value取值为true或false，取值为true表示最大化启动、取值为false表示不以最大化状态启动，未配置时默认为false。主窗最大化显示配置存在如下约束与限制：

    * 该配置项仅在PC/2in1设备上生效。
    * 若使用[startOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)的supportWindowModes属性，需要配置FULL_SCREEN选项，此时使用metadata标签配置主窗最大化启动生效，否则不生效。
    * 若使用[module.json5](../quick-start/module-configuration-file.md#abilities标签)的supportWindowMode属性，需要配置fullscreen选项，此时使用metadata标签配置主窗最大化启动生效，否则不生效。
    * 主窗显示设置优先级排序为：全屏显示 > 使用[startOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)接口指定大小和位置 > 使用[setWindowRectAutoSave()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#setwindowrectautosave14)方法开启窗口尺寸记忆 > 使用metadata标签配置最大化 > 使用metadata标签配置大小和位置。全屏显示配置方法包括如下三种：
        1. 使用[startOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)的windowMode属性并将其配置为WINDOW_MODE_FULLSCREEN。
        2. 使用[startOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)的supportWindowModes属性，且只配置FULL_SCREEN选项。
        3. 使用[module.json5](../quick-start/module-configuration-file.md#abilities标签)的supportWindowMode属性，且只配置fullscreen选项。

4. 使用metadata配置[自由多窗](https://developer.huawei.com/consumer/cn/doc/design-guides/pad-0000001823654157#section1768267204717)下的可支持窗口模式。配置项为：name为ohos.ability.window.SupportWindowModeInFreeWindow，value取值为：fullscreen（表示全屏模式）、split（表示分屏模式）、floating（表示悬浮窗模式）。value取值为字符串，可以配置多种模式，每个模式之间用逗号分隔开，不区分顺序，不添加空格，例如：fullscreen,split。仅在平板、PC/2in1设备上生效。

   自由多窗下的可支持窗口模式可以采用多种方法进行配置，配置优先级为：通过[SetSupportedWindowModes](../reference/apis-arkui/arkts-apis-window-WindowStage.md#setsupportedwindowmodes15)接口配置 > 通过StartAbility配置[StartOption](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions)中的SupportWindowMode > 使用metadata配置 > 配置module.json5中[abilities](../quick-start/module-configuration-file.md#abilities标签)标签下的SupportWindowMode属性。

   非自由多窗模式下只能通过配置module.json5中abilities标签下的SupportWindowMode属性配置窗口支持模式，其他配置方式均不生效。

<!--Del-->
5. 使用metadata标签配置主窗边角以直角显示。配置项为：name为ohos.ability.window.isRightAngle，value取值为true或false，取值为true表示窗口边角以直角显示、取值为false则使用系统默认圆角，未配置时默认为false。主窗直角配置仅在PC/2in1设备上生效，且仅支持系统应用。<!--DelEnd-->


```json
{
  "module": {
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
        "name": "ohos.ability.window.isMaximize",
        "value": "true"
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
      },
      {
        "name": "ohos.ability.window.SupportWindowModeInFreeWindow",
        "value": "fullscreen,split,floating",
      }],
    }]
  }
}
```