# SymbolGlyph

显示一个图标小符号的组件。

>  **说明：**
>
>  该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

不支持子组件


## 接口

SymbolGlyph(value: Resource)


**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
 value | [Resource](../arkui-ts/ts-types.md#resource)| 是 | SymbolGlyph组件的资源名,如 $r('sys.symbol.ohos_wifi')
 >  **说明：**
>  $r('sys.symbol.ohos_wifi')中引用的资源为系统预置，SymbolGlyph仅支持系统预置的symbol资源名，引用非symbol资源将不显示内容

## 属性

支持[通用属性](ts-universal-attributes-size.md)，不支持文本通用属性，仅支持以下特有属性：

| 名称                       | 参数类型                            | 描述                                               |
| ----------------------- | ----------------------------------- | ------------------------------------------- |
| fontSize               | [number](../apis/js-apis-image.md#pixelmap7)&nbsp;\|&nbsp;[string](ts-types.md#resourcestr)\|&nbsp;[Resource](../apis/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | 设置symbol图标的显示大小
| fontColor               | Array\<[ResourceColor](ts-types.md#resourcecolor)\>| 设置symbol图标颜色| 
| fontWeight | number&nbsp;\|&nbsp;[FontWeight](ts-appendix-enums.md#fontweight)&nbsp;\|&nbsp;string | 设置symbol图标的粗细，number类型取值[100,&nbsp;900]，取值间隔为100，默认为400，取值越大，字体越粗。string类型仅支持number类型取值的字符串形式，例如"400"，以及"bold"、"bolder"、"lighter"、"regular"、"medium"，分别对应FontWeight中相应的枚举值。<br/>默认值：FontWeight.Normal<br/>|
| effectStrategy               | [SymbolEffectStrategy](#symboleffectstrategy)| 设置symbol图标的动效类型| 
| renderingStrategy               | [SymbolRenderingStrategy](#symbolrenderingstrategy)| 设置symbol图标的渲染模式|

## SymbolEffectStrategy
动效类型的枚举值
| 名称     | 描述                            |
| ------ | ----------------------------- |
| NONE | 无动效（默认值） |
| SCALE | 整体缩放动效                 |
|  HIERARCHICAL  | 层级动效  

## SymbolRenderingStrategy
渲染模式的枚举值
| 名称     | 描述                            |
| ------ | ----------------------------- |
| SINGLE  | 统一作为一层，设置一种颜色（默认值） |
| MULTIPLE_COLOR  |    每层都可设置颜色             |
|  MULTIPLE_OPACITY   | 设置一种颜色，然后每层有不同的透明度  

## 事件

支持[通用事件](ts-universal-events-click.md)



## 示例

### 示例1

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
      Column() {
        Row() {
          Column(){
            Text("字重 细")
            SymbolGlyph($r('sys.media.ohos_lungs'))
              .fontWeight(FontWeight.Lighter)
              .fontSize(100)
          }
          Column(){
            Text("字重 标准")
            SymbolGlyph($r('sys.media.ohos_lungs'))
              .fontWeight(FontWeight.Normal)
              .fontSize(100)
          }
          Column(){
            Text("字重 粗")
            SymbolGlyph($r('sys.media.ohos_lungs'))
              .fontWeight(FontWeight.Bold)
              .fontSize(100)
          }
        }

        Row() {
          Column(){
            Text("渲染模式：统一")
            SymbolGlyph($r('sys.media.ohos_lungs'))
              .fontSize(100)
              .renderingStrategy(SymbolRenderingStrategy.SINGLE)
              .fontColor([Color.Blue,Color.Grey,Color.Green])
          }
          Column(){
            Text("渲染模式：多色")
            SymbolGlyph($r('sys.media.ohos_lungs'))
              .fontSize(100)
              .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_COLOR)
              .fontColor([Color.Blue,Color.Grey,Color.Green])
          }
          Column(){
            Text("渲染模式：不同透明度")
            SymbolGlyph($r('sys.media.ohos_lungs'))
              .fontSize(100)
              .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_OPACITY)
              .fontColor([Color.Blue,Color.Grey,Color.Green])
          }
        }
        Row() {
          Column(){
            Text("无动效")
            SymbolGlyph($r('sys.media.ohos_lungs'))
              .fontSize(100)
              .effectStrategy(SymbolEffectStrategy.NONE)
          }
          Column(){
            Text("整体缩放动效")
            SymbolGlyph($r('sys.media.ohos_lungs'))
              .fontSize(100)
              .effectStrategy(SymbolEffectStrategy.SCALE)
          }
          Column(){
            Text("层级动效")
            SymbolGlyph($r('sys.media.ohos_lungs'))
              .fontSize(100)
              .effectStrategy(SymbolEffectStrategy.HIERARCHICAL)
          }
        }
      }
    }
}
```
![textExp1](figures/textExp1.png)

