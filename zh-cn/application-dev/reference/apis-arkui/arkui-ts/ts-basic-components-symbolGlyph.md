# SymbolGlyph

显示图标小符号的组件。

>  **说明：**
>
>  该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

不支持子组件。

## 接口

SymbolGlyph(value: Resource)

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| value | [Resource](ts-types.md#resource)| 是 | SymbolGlyph组件的资源名,如 $r('sys.symbol.ohos_wifi')。 |

>  **说明：**
>
>  $r('sys.symbol.ohos_wifi')中引用的资源为系统预置，SymbolGlyph仅支持系统预置的symbol资源名，引用非symbol资源将显示异常。

## 属性

支持[通用属性](ts-universal-attributes-size.md)，不支持文本通用属性，仅支持以下特有属性：

### fontColor

fontColor(value: Array&lt;ResourceColor&gt;)

设置SymbolGlyph组件颜色。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                | 必填 | 说明                                                         |
| ------ | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | Array\<[ResourceColor](ts-types.md#resourcecolor)\> | 是   | SymbolGlyph组件颜色。<br/> 默认值：不同渲染策略下默认值不同。 |

### fontSize

fontSize(value: number | string | Resource)

设置SymbolGlyph组件大小。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                           |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------- |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | SymbolGlyph组件大小。<br/>默认值：系统默认值。 |

### fontWeight

fontWeight(value: number | FontWeight | string)

设置SymbolGlyph组件粗细。number类型取值[100,900]，取值间隔为100，默认为400，取值越大，字体越粗。string类型仅支持number类型取值的字符串形式，例如“400”，以及“bold”、“bolder”、“lighter”、“regular” 、“medium”分别对应FontWeight中相应的枚举值。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                |
| ------ | ------------------------------------------------------------ | ---- | --------------------------------------------------- |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[FontWeight](ts-appendix-enums.md#fontweight) | 是   | SymbolGlyph组件粗细。<br/>默认值：FontWeight.Normal |

### renderingStrategy

renderingStrategy(value: SymbolRenderingStrategy)

设置SymbolGlyph组件渲染策略。$r('sys.symbol.ohos_*')中引用的资源仅ohos_folder_badge_plus支持分层与多色模式。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [SymbolRenderingStrategy](ts-appendix-enums.md#symbolrenderingstrategy11) | 是   | SymbolGlyph组件渲染策略。<br/>默认值：SymbolRenderingStrategy.SINGLE |

不同渲染策略效果可参考以下示意图。

![renderingStrategy](figures/renderingStrategy.png)

### effectStrategy

effectStrategy(value: SymbolEffectStrategy)

设置SymbolGlyph组件动效策略。$r('sys.symbol.ohos_*')中引用的资源仅ohos_wifi支持层级动效模式。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [SymbolEffectStrategy](ts-appendix-enums.md#symboleffectstrategy11) | 是   | SymbolGlyph组件动效策略。<br/>默认值：SymbolEffectStrategy.NONE |

### symbolEffect<sup>12+</sup>

symbolEffect(symbolEffect: SymbolEffect, isActive?: boolean)

设置SymbolGlyph组件动效策略及播放状态。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| symbolEffect  | [SymbolEffect](#symboleffect12-2)\|[ScaleSymbolEffect](#scalesymboleffect12)\|[HierarchicalSymbolEffect](#hierarchicalsymboleffect12)\|<br>[AppearSymbolEffect](#appearsymboleffect12)\|[DisappearSymbolEffect](#disappearsymboleffect12)\|[BounceSymbolEffect](#bouncesymboleffect12)\|<br>[ReplaceSymbolEffect](#replacesymboleffect12)\|[PulseSymbolEffect](#pulsesymboleffect12) | 是   | SymbolGlyph组件动效策略。<br/>默认值：[SymbolEffect](#symboleffect12-2) |
| isActive  |boolean | 否   | SymbolGlyph组件动效播放状态。<br/>默认值：false |
### symbolEffect<sup>12+</sup>

symbolEffect(symbolEffect: SymbolEffect, triggerValue?: number)

设置SymbolGlyph组件动效策略及播放触发器。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| symbolEffect | [SymbolEffect](#symboleffect12-2)\|[ScaleSymbolEffect](#scalesymboleffect12)\|[HierarchicalSymbolEffect](#hierarchicalsymboleffect12)\|<br>[AppearSymbolEffect](#appearsymboleffect12)\|[DisappearSymbolEffect](#disappearsymboleffect12)\|[BounceSymbolEffect](#bouncesymboleffect12)\|<br>[ReplaceSymbolEffect](#replacesymboleffect12)\|[PulseSymbolEffect](#pulsesymboleffect12) | 是   | SymbolGlyph组件动效策略。<br/>默认值：[SymbolEffect](#symboleffect12-2) |
| triggerValue | number | 否   | SymbolGlyph组件动效播放触发器，在数值变更时触发动效。<br/>如果首次不希望触发动效，设置-1。 |

>  **说明：**
>
>  动效属性，仅支持使用effectStrategy属性或单个symbolEffect属性，不支持多种动效属性混合使用。

## SymbolEffect<sup>12+</sup>

### constructor<sup>12+</sup>

constructor()

SymbolEffect的构造函数，无动效。

## ScaleSymbolEffect<sup>12+</sup>

### constructor<sup>12+</sup>

constructor(scope?: EffectScope, direction?: EffectDirection)

ScaleSymbolEffect的构造函数，缩放动效。

**参数：**

| 参数名    | 参数类型                              | 必填 | 参数描述                                    |
| --------- | ------------------------------------- | ---- | ------------------------------------------- |
| scope     | [EffectScope](#effectscope12)         | 否   | 动效范围。<br/>默认值：EffectScope.LAYER    |
| direction | [EffectDirection](#effectdirection12) | 否   | 动效方向。<br/>默认值：EffectDirection.DOWN |

### 属性

| 名称      | 参数类型                              | 描述                                        |
| --------- | ------------------------------------- | ------------------------------------------- |
| scope     | [EffectScope](#effectscope12)         | 动效范围。<br/>默认值：EffectScope.LAYER    |
| direction | [EffectDirection](#effectdirection12) | 动效方向。<br/>默认值：EffectDirection.DOWN |

## HierarchicalSymbolEffect<sup>12+</sup>

### constructor<sup>12+</sup>

constructor(fillStyle?: EffectFillStyle)

HierarchicalSymbolEffect的构造函数，层级动效。

**参数：**

| 参数名    | 参数类型                              | 必填 | 参数描述                                          |
| --------- | ------------------------------------- | ---- | ------------------------------------------------- |
| fillStyle | [EffectFillStyle](#effectfillstyle12) | 否   | 动效模式。<br/>默认值：EffectFillStyle.CUMULATIVE |

### 属性

| 名称      | 类型                                  | 必填 | 说明                                              |
| --------- | ------------------------------------- | ---- | ------------------------------------------------- |
| fillStyle | [EffectFillStyle](#effectfillstyle12) | 否   | 动效模式。<br/>默认值：EffectFillStyle.CUMULATIVE |

## AppearSymbolEffect<sup>12+</sup>

### constructor<sup>12+</sup>

constructor(scope?: EffectScope)

AppearSymbolEffect的构造函数，出现动效。

**参数：**

| 参数名 | 参数类型                      | 必填 | 参数描述                                 |
| ------ | ----------------------------- | ---- | ---------------------------------------- |
| scope  | [EffectScope](#effectscope12) | 否   | 动效范围。<br/>默认值：EffectScope.LAYER |

### 属性

| 名称  | 类型                          | 必填 | 说明                                     |
| ----- | ----------------------------- | ---- | ---------------------------------------- |
| scope | [EffectScope](#effectscope12) | 否   | 动效范围。<br/>默认值：EffectScope.LAYER |

## DisappearSymbolEffect<sup>12+</sup>

### constructor<sup>12+</sup>

constructor(scope?: EffectScope)

DisappearSymbolEffect的构造函数，消失动效。

**参数：**

| 参数名 | 参数类型                      | 必填 | 参数描述                                 |
| ------ | ----------------------------- | ---- | ---------------------------------------- |
| scope  | [EffectScope](#effectscope12) | 否   | 动效范围。<br/>默认值：EffectScope.LAYER |

### 属性

| 名称  | 类型                          | 必填 | 说明                                     |
| ----- | ----------------------------- | ---- | ---------------------------------------- |
| scope | [EffectScope](#effectscope12) | 否   | 动效范围。<br/>默认值：EffectScope.LAYER |

## BounceSymbolEffect<sup>12+</sup>

### constructor<sup>12+</sup>

constructor(scope?: EffectScope, direction?: EffectDirection)

BounceSymbolEffect的构造函数，弹跳动效。

**参数：**

| 参数名    | 参数类型                              | 必填 | 参数描述                                    |
| --------- | ------------------------------------- | ---- | ------------------------------------------- |
| scope     | [EffectScope](#effectscope12)         | 否   | 动效范围。<br/>默认值：EffectScope.LAYER    |
| direction | [EffectDirection](#effectdirection12) | 否   | 动效方向。<br/>默认值：EffectDirection.DOWN |

### 属性

| 名称      | 类型                                  | 必填 | 说明                                        |
| --------- | ------------------------------------- | ---- | ------------------------------------------- |
| scope     | [EffectScope](#effectscope12)         | 否   | 动效范围。<br/>默认值：EffectScope.LAYER    |
| direction | [EffectDirection](#effectdirection12) | 否   | 动效方向。<br/>默认值：EffectDirection.DOWN |

## ReplaceSymbolEffect<sup>12+</sup>

### constructor<sup>12+</sup>

constructor(scope?: EffectScope)

ReplaceSymbolEffect的构造函数，替换动效。

**参数：**

| 参数名 | 参数类型                      | 必填 | 参数描述                                 |
| ------ | ----------------------------- | ---- | ---------------------------------------- |
| scope  | [EffectScope](#effectscope12) | 否   | 动效范围。<br/>默认值：EffectScope.LAYER |

### 属性

| 名称  | 类型                          | 必填 | 说明                                     |
| ----- | ----------------------------- | ---- | ---------------------------------------- |
| scope | [EffectScope](#effectscope12) | 否   | 动效范围。<br/>默认值：EffectScope.LAYER |

## PulseSymbolEffect<sup>12+</sup>

### constructor<sup>12+</sup>

constructor()

PulseSymbolEffect的构造函数，脉冲动效。

## EffectDirection<sup>12+</sup>

| 名称 | 值   | 说明             |
| ---- | ---- | ---------------- |
| DOWN | 0    | 图标缩小再复原。 |
| UP   | 1    | 图标放大再复原。 |

## EffectScope<sup>12+</sup>

| 名称  | 值   | 说明       |
| ----- | ---- | ---------- |
| LAYER | 0    | 分层模式。 |
| WHOLE | 1    | 整体模式。 |

## EffectFillStyle<sup>12+</sup>

| 名称       | 值   | 说明       |
| ---------- | ---- | ---------- |
| CUMULATIVE | 0    | 累加模式。 |
| ITERATIVE  | 1    | 迭代模式。 |

## 事件

支持[通用事件](ts-universal-events-click.md)。

## 示例

###  示例1

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      Row() {
        Column() {
          Text("Light")
          SymbolGlyph($r('sys.symbol.ohos_trash'))
            .fontWeight(FontWeight.Lighter)
            .fontSize(96)
        }

        Column() {
          Text("Normal")
          SymbolGlyph($r('sys.symbol.ohos_trash'))
            .fontWeight(FontWeight.Normal)
            .fontSize(96)
        }

        Column() {
          Text("Bold")
          SymbolGlyph($r('sys.symbol.ohos_trash'))
            .fontWeight(FontWeight.Bold)
            .fontSize(96)
        }
      }

      Row() {
        Column() {
          Text("单色")
          SymbolGlyph($r('sys.symbol.ohos_folder_badge_plus'))
            .fontSize(96)
            .renderingStrategy(SymbolRenderingStrategy.SINGLE)
            .fontColor([Color.Black, Color.Green, Color.White])
        }

        Column() {
          Text("多色")
          SymbolGlyph($r('sys.symbol.ohos_folder_badge_plus'))
            .fontSize(96)
            .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_COLOR)
            .fontColor([Color.Black, Color.Green, Color.White])
        }

        Column() {
          Text("分层")
          SymbolGlyph($r('sys.symbol.ohos_folder_badge_plus'))
            .fontSize(96)
            .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_OPACITY)
            .fontColor([Color.Black, Color.Green, Color.White])
        }
      }

      Row() {
        Column() {
          Text("无动效")
          SymbolGlyph($r('sys.symbol.ohos_wifi'))
            .fontSize(96)
            .effectStrategy(SymbolEffectStrategy.NONE)
        }

        Column() {
          Text("整体缩放动效")
          SymbolGlyph($r('sys.symbol.ohos_wifi'))
            .fontSize(96)
            .effectStrategy(1)
        }

        Column() {
          Text("层级动效")
          SymbolGlyph($r('sys.symbol.ohos_wifi'))
            .fontSize(96)
            .effectStrategy(2)
        }
      }
    }
  }
}
```
![symbol](figures/symbolGlyph.gif)

###  示例2

SymbolGlyph使用symbolEffect属性实现可变颜色动效和替换动效。

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State isActive: boolean = true;
  @State triggerValueReplace: number = 0;
  replaceFlag: boolean = true;

  build() {
    Column() {
      Row() {
        Column() {
          Text("可变颜色动效")
          SymbolGlyph($r('sys.symbol.ohos_wifi'))
            .fontSize(96)
            .symbolEffect(new HierarchicalSymbolEffect(EffectFillStyle.ITERATIVE), this.isActive)
          Button(this.isActive ? '关闭' : '播放').onClick(() => {
            this.isActive = !this.isActive;
          })
        }.margin({right:20})

        Column() {
          Text("替换动效")
          SymbolGlyph(this.replaceFlag ? $r('sys.symbol.checkmark_circle') : $r('sys.symbol.repeat_1'))
            .fontSize(96)
            .symbolEffect(new ReplaceSymbolEffect(EffectScope.WHOLE), this.triggerValueReplace)
          Button('trigger').onClick(() => {
            this.replaceFlag = !this.replaceFlag;
            this.triggerValueReplace = this.triggerValueReplace + 1;
          })
        }
      }
    }.margin({
      left:30,
      top:50
    })
  }
}
```
![symbol](figures/symbolGlyph_symbolEffect.gif)