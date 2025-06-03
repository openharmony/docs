# Toggle

组件提供勾选框样式、状态按钮样式和开关样式。

>  **说明：**
>
> 该组件从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

仅当ToggleType设置为Button时，可包含子组件。

## 接口

Toggle(options: ToggleOptions)

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型 | 必填   | 说明           |
| ---- | ---------- | -----| -------------- |
| options | [ToggleOptions](#toggleoptions18对象说明) | 是   | Toggle的信息。 |

## ToggleOptions<sup>18+</sup>对象说明

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型                              | 必填 | 说明                                                         |
| ----------------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| type<sup>8+</sup> | [ToggleType](#toggletype枚举说明) | 是   | 开关的样式。<br/>默认值：ToggleType.Switch<br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| isOn<sup>8+</sup> | boolean                           | 否   | 开关是否打开，值为true表示打开，值为false表示关闭。<br/>默认值：false<br />该参数支持[$$](../../../ui/state-management/arkts-two-way-sync.md)双向绑定变量。<br />该属性支持[!!](../../../ui/state-management/arkts-new-binding.md#系统组件参数双向绑定)双向绑定变量。<br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |

## ToggleType枚举说明

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| Checkbox | 提供单选框样式。<br>**说明：**<br/>API version 11开始，Checkbox默认样式由圆角方形变为圆形。<br/>[通用属性margin](ts-universal-attributes-size.md#margin)的默认值为：<br>{<br>&nbsp;top: '14px',<br>&nbsp;right: '14px',<br>&nbsp;bottom: '14px',<br>&nbsp;left: '14px'<br> }。<br/>默认尺寸为：<br>{width:'20vp', height:'20vp'}。 |
| Button   | 提供状态按钮样式。如子组件设置文本，文本内容将显示在按钮内。默认高度为28vp，宽度无默认值。 |
| Switch   | 提供开关样式。<br>**说明：**<br/>[通用属性margin](ts-universal-attributes-size.md#margin)默认值为：<br>{<br/>&nbsp;top: '6px',<br/>&nbsp;right: '14px',<br/>&nbsp;bottom: '6px',<br/>&nbsp;left: '14px'<br/> }。<br/>默认尺寸为：<br>{width:'36vp', height:'20vp'}。 |

## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

### selectedColor

selectedColor(value: ResourceColor)

设置组件在打开状态下的背景颜色。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                                         |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 组件打开状态的背景颜色。<br/>默认值：<br/>当ToggleType为Switch时，默认值为`$r('sys.color.ohos_id_color_component_activated')`<br/>当ToggleType为Checkbox时，默认值为`$r('sys.color.ohos_id_color_component_activated')`<br/>当ToggleType为Button时，默认值为`$r('sys.color.ohos_id_color_component_activated')`混合`$r('sys.color.ohos_id_color_text_highlight_bg')`的透明度。 |

### switchPointColor

switchPointColor(color: ResourceColor)

设置Switch类型的圆形滑块颜色。仅对type为ToggleType.Switch生效。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                       |
| ------ | ------------------------------------------ | ---- | -------------------------- |
| color  | [ResourceColor](ts-types.md#resourcecolor) | 是   | Switch类型的圆形滑块颜色。<br/>默认值：$r('sys.color.ohos_id_color_foreground_contrary') |

### switchStyle<sup>12+</sup>

switchStyle(value: SwitchStyle)

设置Switch类型的样式。仅对type为ToggleType.Switch生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                  | 必填 | 说明             |
| ------ | ------------------------------------- | ---- | ---------------- |
| value  | [SwitchStyle](#switchstyle12对象说明) | 是   | Switch样式风格。 |

### contentModifier<sup>12+</sup>

contentModifier(modifier: ContentModifier\<ToggleConfiguration>)

定制Toggle内容区的方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                          | 必填 | 说明                                             |
| ------ | --------------------------------------------- | ---- | ------------------------------------------------ |
| modifier  | [ContentModifier\<ToggleConfiguration>](#toggleconfiguration12对象说明) | 是   | 在Toggle组件上，定制内容区的方法。<br/>modifier：内容修改器，开发者需要自定义class实现ContentModifier接口。 |

## SwitchStyle<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型                                        | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| pointRadius       | number \|  [Resource](ts-types.md#resource) | 否   | 设置Switch类型的圆形滑块半径，单位为vp。<br />**说明：**<br/>不支持百分比，设定值小于0时按照默认算法设置，设定值大于等于0时按照设定值设置。<br/>未设定此属性时，圆形滑块半径根据默认算法设置。<br/>默认算法：（组件高度（单位：vp） / 2） - （2vp * 组件高度（单位：vp） / 20vp）。 |
| unselectedColor   | [ResourceColor](ts-types.md#resourcecolor)  | 否   | 设置Switch类型关闭状态的背景颜色。<br />默认值：0x337F7F7F |
| pointColor        | [ResourceColor](ts-types.md#resourcecolor)  | 否   | 设置Switch类型的圆形滑块颜色。<br />默认值：$r('sys.color.ohos_id_color_foreground_contrary') |
| trackBorderRadius | number \|  [Resource](ts-types.md#resource) | 否   | 设置Switch类型的滑轨的圆角，单位为vp。<br />**说明：**<br/>不支持百分比，设定值小于0时按照默认算法设置，设定值大于组件高度一半时按照组件高度一半设置，其他场合按照设定值设置。<br/>未设定此属性时，滑轨圆角根据默认算法设置。<br/>默认算法：组件高度（单位：vp） / 2。 |

## 事件

除支持[通用事件](ts-component-general-events.md)外，还支持以下事件：

### onChange

onChange(callback:&nbsp;(isOn:&nbsp;boolean)&nbsp;=&gt;&nbsp;void)

开关状态切换时触发该事件。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| isOn   | boolean | 是   | 为true时，代表状态从关切换为开。false时，代表状态从开切换为关。 |

## ToggleConfiguration<sup>12+</sup>对象说明

开发者需要自定义class实现ContentModifier接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型    |    只读    |    可选    |  说明              |
| ------ | ------ | ------ |-------------------------------- |-------------------------------- |
| isOn   | boolean| 否  | 否 | 开关是否打开。<br/>默认值：false<br/>值为true时，开关打开。值为false时，开关关闭。 |
| enabled | boolean | 否 | 否 | 是否可以切换状态。<br/>默认值：true<br/>值为true时，可以切换状态。值为false时，不可以切换状态。 |
| triggerChange |Callback\<boolean>| 否 | 否 |触发switch选中状态变化。<br/>为true时，代表状态从关切换为开。false时，代表状态从开切换为关。 |


## 示例

### 示例1（设置开关的样式）

该示例通过配置ToggleType设置Toggle的勾选框样式、状态按钮样式及开关样式。

```ts
// xxx.ets
@Entry
@Component
struct ToggleExample {
  build() {
    Column({ space: 10 }) {
      Text('type: Switch').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Switch, isOn: false })
          .selectedColor('#007DFF')
          .switchPointColor('#FFFFFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn);
          })

        Toggle({ type: ToggleType.Switch, isOn: true })
          .selectedColor('#007DFF')
          .switchPointColor('#FFFFFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn);
          })
      }

      Text('type: Checkbox').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Checkbox, isOn: false })
          .size({ width: 20, height: 20 })
          .selectedColor('#007DFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn);
          })

        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .size({ width: 20, height: 20 })
          .selectedColor('#007DFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn);
          })
      }

      Text('type: Button').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Button, isOn: false }) {
          Text('status button').fontColor('#182431').fontSize(12)
        }.width(106)
        .selectedColor('rgba(0,125,255,0.20)')
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn);
        })

        Toggle({ type: ToggleType.Button, isOn: true }) {
          Text('status button').fontColor('#182431').fontSize(12)
        }.width(106)
        .selectedColor('rgba(0,125,255,0.20)')
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn);
        })
      }
    }.width('100%').padding(24)
  }
}
```

![toggle](figures/toggle.gif)

### 示例2（自定义开关类型的样式）

该示例实现了自定义设置Toggle组件Switch样式，包括圆形滑块半径、关闭状态的背景颜色、圆形滑块颜色、滑轨的圆角。

```ts
// xxx.ets
@Entry
@Component
struct ToggleExample {
  build() {
    Column({ space: 10 }) {
      Text('type: Switch').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Switch, isOn: false })
          .selectedColor('#007DFF')
          .switchStyle({
            pointRadius: 15,
            trackBorderRadius: 10,
            pointColor: '#D2B48C',
            unselectedColor: Color.Pink })
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn);
          })

        Toggle({ type: ToggleType.Switch, isOn: true })
          .selectedColor('#007DFF')
          .switchStyle({
            pointRadius: 15,
            trackBorderRadius: 10,
            pointColor: '#D2B48C',
            unselectedColor: Color.Pink })
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn);
          })
      }
    }.width('100%').padding(24)
  }
}
```

![toggle](figures/toggleSwitchStyle.gif)

### 示例3（自定义Toggle样式）

该示例实现自定义Toggle样式，通过按钮切换圆形背景颜色：点击蓝圆按钮，背景变蓝色；点击黄圆按钮，背景变黄色。

```ts
// xxx.ets
class MySwitchStyle implements ContentModifier<ToggleConfiguration> {
  selectedColor: Color = Color.White;
  lamp: string = 'string';

  constructor(selectedColor: Color, lamp: string) {
    this.selectedColor = selectedColor;
    this.lamp = lamp;
  }

  applyContent(): WrappedBuilder<[ToggleConfiguration]> {
    return wrapBuilder(buildSwitch);
  }
}

@Builder
function buildSwitch(config: ToggleConfiguration) {
  Column({ space: 50 }) {
    Circle({ width: 150, height: 150 })
      .fill(config.isOn ? (config.contentModifier as MySwitchStyle).selectedColor : Color.Blue)
    Row() {
      Button('蓝' + JSON.stringify((config.contentModifier as MySwitchStyle).lamp))
        .onClick(() => {
          config.triggerChange(false);
        })
      Button('黄' + JSON.stringify((config.contentModifier as MySwitchStyle).lamp))
        .onClick(() => {
          config.triggerChange(true);
        })
    }
  }
}

@Entry
@Component
struct Index {
  build() {
    Column({ space: 50 }) {
      Toggle({ type: ToggleType.Switch })
        .enabled(true)
        .contentModifier(new MySwitchStyle(Color.Yellow, '灯'))
        .onChange((isOn: boolean) => {
          console.info('Switch Log:' + isOn);
        })
    }.height('100%').width('100%')
  }
}
```

![toggle](figures/Toggle_builder.gif)
