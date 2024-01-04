# SymbolSpan

**\<SymbolSpan>** is a child component of the **\<Text>** and **\<RichEditor>** components and is used to display small icons.

>  **NOTE**
>
>  This component is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

SymbolSpan(value: Resource)


**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | [Resource](../arkui-ts/ts-types.md#resource)| Yes| Resource of the **\<SymbolSpan>** component, for example, **$r('sys.symbol.ohos_wifi')**.|
>  **NOTE**
>
>  The **\<SymbolSpan>** component supports only the preset symbol resources. If unsupported resources are referenced, they are not displayed.

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are not supported. Only the following attributes are supported.

| Name| Type| Mandatory| Description                              |
| ------ | -------- | ---- | -------------------------------------- |
| fontColor | Array\<[ResourceColor](ts-types.md#resourcecolor)\> | No| Color of the symbol span.<br> Default value: **Color.Black**|
| fontSize | number \| string \| [Resource](../arkui-ts/ts-types.md#resource) | No| Size of the symbol span.<br>Default value: system default value|
| fontWeight | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | No| Font weight.<br>For the number type, the value ranges from 100 to 900, at an interval of 100. A larger value indicates a heavier font weight. The default value is **400**.<br>For the string type, only strings of the number type are supported, for example, **"400"**, **"bold"**, **"bolder"**, **"lighter"**, **"regular"**, and **"medium"**, which correspond to the enumerated values in **FontWeight**.<br>Default value: **FontWeight.Normal**|
| renderingStrategy | [SymbolRenderingStrategy](ts-appendix-enums.md#symbolrenderingstrategy11)	| No| Rendering strategy.<br>Default value: **SymbolRenderingStrategy.SINGLE**|
| effectStrategy | [SymbolEffectStrategy](ts-appendix-enums.md#symboleffectstrategy11)	| No| Symbol effect strategy.<br>Default value: **SymbolEffectStrategy.NONE**|

## Events

The [universal events](ts-universal-events-click.md) are not supported.

## Example

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      Row() {
        Column(){
          Text ("Lighter")
          Text(){
            SymbolSpan($r('sys.symbol.ohos_lungs'))
              .fontWeight(FontWeight.Lighter)
              .fontSize(100)
          }
        }
        Column(){
          Text ("Normal")
          Text(){
            SymbolSpan($r('sys.symbol.ohos_lungs'))
              .fontWeight(FontWeight.Normal)
              .fontSize(100)
          }
        }
        Column(){
          Text ("Bold")
          Text(){
            SymbolSpan($r('sys.symbol.ohos_lungs'))
              .fontWeight(FontWeight.Bold)
              .fontSize(100)
          }
        }
      }

      Row() {
        Column(){
          Text ("Monochrome")
          Text(){
            SymbolSpan($r('sys.symbol.ohos_lungs'))
              .fontSize(100)
              .renderingStrategy(SymbolRenderingStrategy.SINGLE)
              .fontColor([Color.Blue,Color.Grey,Color.Green])
          }
        }
        Column(){
          Text ("Multicolor")
          Text(){
            SymbolSpan($r('sys.symbol.ohos_lungs'))
              .fontSize(100)
              .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_COLOR)
              .fontColor([Color.Blue,Color.Grey,Color.Green])
          }
        }
        Column(){
          Text ("Multi-opacity")
          Text(){
            SymbolSpan($r('sys.symbol.ohos_lungs'))
              .fontSize(100)
              .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_OPACITY)
              .fontColor([Color.Blue,Color.Grey,Color.Green])
          }
        }
      }
      Row() {
        Column(){
          Text ("No effect")
          Text() {
            SymbolSpan($r('sys.symbol.ohos_lungs'))
              .fontSize(100)
              .effectStrategy(SymbolEffectStrategy.NONE)
          }
        }
        Column(){
          Text ("Overall scale effect")
          Text(){
            SymbolSpan($r('sys.symbol.ohos_lungs'))
              .fontSize(100)
              .effectStrategy(SymbolEffectStrategy.SCALE)
          }
        }
        Column(){
          Text ("Hierarchical effect")
          Text(){
            SymbolSpan($r('sys.symbol.ohos_lungs'))
              .fontSize(100)
              .effectStrategy(SymbolEffectStrategy.HIERARCHICAL)
          }
        }
      }
    }
  }
}
```
![SymbolSpan](figures/symbolSpan.png)
