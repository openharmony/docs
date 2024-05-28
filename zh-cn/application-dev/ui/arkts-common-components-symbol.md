# 图标小符号 (SymbolGlyph/SymbolSpan)

SymbolGlyph是图标小符号组件，便于使用精美的图标，如渲染多色图标。具体用法请参考[SymbolGlyph](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolGlyph.md)。


## 创建图标

SymbolGlyph通过引用Resource资源来创建，资源引用类型可以通过$r创建Resource类型对象。

  ```ts
  SymbolGlyph($r('sys.symbol.ohos_folder_badge_plus'))
      .fontSize(96)
      .renderingStrategy(SymbolRenderingStrategy.SINGLE)
      .fontColor([Color.Black, Color.Green, Color.White])
  ```
  ![symbol_folder_badge_plus](figures/symbol_ohos_folder_badge_plus.png)


## 添加到文本中

[SymbolSpan](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolSpan.md)能作为[Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md)的子组件显示图标小符号。可以在一个Text内添加多个SymbolSpan来显示一串图标。

- 创建SymbolSpan。

  SymbolSpan组件需要写到Text组件内，单独的SymbolSpan组件不会显示。


  ```ts
  Text() {
    SymbolSpan($r('sys.symbol.ohos_trash'))
      .fontWeight(FontWeight.Normal)
      .fontSize(96)
  }
  ```
  ![symbol_trash](figures/symbolspan_trash.png)


- 通过fontSize属性设置SymbolSpan的大小。


  ```ts
  Row() {
    Column() {
      Text("48")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_folder_badge_plus'))
          .fontSize(48)
          .renderingStrategy(SymbolRenderingStrategy.SINGLE)
          .fontColor([Color.Black, Color.Green, Color.White])
      }
    }

    Column() {
      Text("72")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_folder_badge_plus'))
          .fontSize(72)
          .renderingStrategy(SymbolRenderingStrategy.SINGLE)
          .fontColor([Color.Black, Color.Green, Color.White])
      }
    }

    Column() {
      Text("96")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_folder_badge_plus'))
          .fontSize(96)
          .renderingStrategy(SymbolRenderingStrategy.SINGLE)
          .fontColor([Color.Black, Color.Green, Color.White])
      }
    }
  }
  ```
  ![symbolSpan_multi_fontSize](figures/symbolspan_multi_fontsize.png)

- 通过fontWeight属性设置SymbolSpan组件的粗细。

  ```ts
  Row() {
    Column() {
      Text("Light")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_trash'))
        .fontWeight(FontWeight.Lighter)
        .fontSize(96)
      }
    }

    Column() {
      Text("Normal")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_trash'))
          .fontWeight(FontWeight.Normal)
          .fontSize(96)
      }
    }

    Column() {
      Text("Bold")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_trash'))
          .fontWeight(FontWeight.Bold)
          .fontSize(96)
      }
    }
  }
  ```
  ![symbolSpan_multi_fontWeight_trash](figures/symbol_multi_fontweight_trash.png)

- 通过fontColor属性设置SymbolSpan的颜色。

  ```ts
  Row() {
    Column() {
      Text("Black")
      Text() {
          SymbolSpan($r('sys.symbol.ohos_folder_badge_plus'))
            .fontSize(96)
            .fontColor([Color.Black])
      }
    }

    Column() {
      Text("Green")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_folder_badge_plus'))
          .fontSize(96)
          .fontColor([Color.Green])
      }
    }

    Column() {
      Text("Pink")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_folder_badge_plus'))
          .fontSize(96)
          .fontColor([Color.Pink])
      }
    }
  }
  ```
  ![symbolSpan_multi_fontColor](figures/symbolspan_multi_fontcolor.PNG)

- 通过renderingStrategy属性设置SymbolSpan的渲染策略。

  ```ts
  Row() {
    Column() {
      Text("单色")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_folder_badge_plus'))
          .fontSize(96)
          .renderingStrategy(SymbolRenderingStrategy.SINGLE)
          .fontColor([Color.Black, Color.Green, Color.White])
      }
    }

    Column() {
      Text("多色")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_folder_badge_plus'))
          .fontSize(96)
          .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_COLOR)
          .fontColor([Color.Black, Color.Green, Color.White])
      }
    }

    Column() {
      Text("分层")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_folder_badge_plus'))
          .fontSize(96)
          .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_OPACITY)
          .fontColor([Color.Black, Color.Green, Color.White])
      }
    }
  }
  ```
  ![symbolSpan_multi_renderingStrategy](figures/symbolspan_multi_renderingStrategy.png)

- 通过effectStrategy属性设置SymbolSpan的动效策略。

  ```ts
  Row() {
    Column() {
      Text("无动效")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_wifi'))
          .fontSize(96)
          .effectStrategy(SymbolEffectStrategy.NONE)
      }
    }

    Column() {
      Text("整体缩放动效")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_wifi'))
          .fontSize(96)
          .effectStrategy(SymbolEffectStrategy.SCALE)
      }
    }

    Column() {
      Text("层级动效")
      Text() {
        SymbolSpan($r('sys.symbol.ohos_wifi'))
          .fontSize(96)
          .effectStrategy(SymbolEffectStrategy.HIERARCHICAL)
      }
    }
  }
  ```
  ![symbolSpan_multi_effectStrategy](figures/symbolspan_multi_effectStrategy.gif)

- SymbolSpan不支持通用事件。

## 自定义图标动效

相较于effectStrategy属性启动即触发动效，可以通过以下两种方式控制动效的播放状态以及更多样的动效策略选择。

关于effectStrategy属性与symbolEffect属性多种动态属性使用生效原则，详见[SymbolGlyph.symbolEffect属性说明](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolGlyph.md#symboleffect12-1)。

- 通过symbolEffect属性同时设置SymbolGlyph的动效策略及动效播放状态。

  ```ts
  @State isActive: boolean = true;
  Column() {
    Text("可变颜色动效")
    SymbolGlyph($r('sys.symbol.ohos_wifi'))
      .fontSize(96)
      .symbolEffect(new HierarchicalSymbolEffect(EffectFillStyle.ITERATIVE), this.isActive)
    Button(this.isActive ? '关闭' : '播放').onClick(() => {
      this.isActive = !this.isActive;
    })
  }
  ```
  ![symbolGlyph_symbolEffect_isActive](figures/symbolGlyph_symbolEffect_isActive.gif)

- 通过symbolEffect属性同时设置SymbolGlyph的动效策略及播放触发器。

  ```ts
  @State triggerValueReplace: number = 0;
  Column() {
    Text("弹跳动效")
    SymbolGlyph($r('sys.symbol.ellipsis_message_1'))
      .fontSize(96)
      .fontColor([Color.Gray])
      .symbolEffect(new BounceSymbolEffect(EffectScope.WHOLE, EffectDirection.UP), this.triggerValueReplace)
    Button('trigger').onClick(() => {
      this.triggerValueReplace = this.triggerValueReplace + 1;
    })
  }
  ```
  ![BounceSymbolEffect](figures/symbolGlyph_bounceSymbolEffect_trigger.gif)


## 添加事件

SymbolGlyph组件可以添加通用事件，例如绑定onClick、onTouch等事件来响应操作。

```ts
@State wifiColor: ResourceColor = Color.Black;
SymbolGlyph($r('sys.symbol.ohos_wifi'))
.fontSize(96)
.fontColor([this.wifiColor])
.onClick(()=>{
  this.wifiColor = Color.Gray
})
```
![symbolGlyph_onClick](figures/symbolGlyph_onClick.gif)

## 场景示例


```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State triggerValueReplace: number = 0;
  @State symbolSources: Resource[] = [$r('sys.symbol.repeat'), $r('sys.symbol.repeat_1'), $r('sys.symbol.arrow_left_arrow_right')]
  @State symbolSourcesIndex: number = 0;
  @State symbolText: string[] = ['顺序播放', '单曲循环', '随机播放']
  @State symbolTextIndex: number = 0;
  @State fontColorValue:ResourceColor = Color.Grey;
  @State fontColorValue1:ResourceColor = '#E8E8E8';

  build() {
    Column( { space: 10 }) {
      Row() {
        Text(){
          Span('当前播放列表')
            .fontSize(20)
            .fontWeight(FontWeight.Bolder)
          Span('（101）')
        }
      }
      Row() {
        Row({ space: 5 }) {
          SymbolGlyph(this.symbolSources[this.symbolSourcesIndex])
            .symbolEffect(new ReplaceSymbolEffect(EffectScope.WHOLE), this.triggerValueReplace)
            .fontSize(20)
            .fontColor([this.fontColorValue])
          Text(this.symbolText[this.symbolTextIndex])
            .fontColor(this.fontColorValue)
        }
        .onClick(()=>{
          this.symbolTextIndex++;
          this.symbolSourcesIndex++;
          this.triggerValueReplace++;
          if (this.symbolSourcesIndex > (this.symbolSources.length - 1)) {
            this.symbolSourcesIndex = 0;
            this.triggerValueReplace = 0;
          }
          if (this.symbolTextIndex > (this.symbolText.length - 1)) {
            this.symbolTextIndex = 0;
          }
        })
        .width('75%')

        Row({ space: 5 }) {
          Text(){
            SymbolSpan($r('sys.symbol.arrow_down_circle_badge_vip_circle_filled'))
              .fontColor([this.fontColorValue])
              .fontSize(20)
          }
          Text(){
            SymbolSpan($r('sys.symbol.heart_badge_plus'))
              .fontColor([this.fontColorValue])
              .fontSize(20)
          }
          Text(){
            SymbolSpan($r('sys.symbol.ohos_trash'))
              .fontColor([this.fontColorValue])
              .fontSize(20)
          }
        }
        .width('25%')
      }
      Divider().width(5).color(this.fontColorValue1).width('98%')
      Row(){
        Row(){
          Text("歌曲一")
        }.width('82%')
        Row({ space: 5}) {
          SymbolGlyph($r('sys.symbol.play_arrow_triangle_2_circlepath'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
          SymbolGlyph($r('sys.symbol.trash'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
        }
      }
      Divider().width(5).color(this.fontColorValue1).width('98%')
      Row(){
        Row(){
          Text("歌曲二")
        }.width('82%')
        Row({ space: 5}) {
          SymbolGlyph($r('sys.symbol.play_arrow_triangle_2_circlepath'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
          SymbolGlyph($r('sys.symbol.trash'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
        }
      }
      Divider().width(5).color(this.fontColorValue1).width('98%')
      Row(){
        Row(){
          Text("歌曲三")
        }.width('82%')
        Row({ space: 5}) {
          SymbolGlyph($r('sys.symbol.play_arrow_triangle_2_circlepath'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
          SymbolGlyph($r('sys.symbol.trash'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
        }
      }
      Divider().width(5).color(this.fontColorValue1).width('98%')
      Row(){
        Row(){
          Text("歌曲四")
        }.width('82%')
        Row({ space: 5}) {
          SymbolGlyph($r('sys.symbol.play_arrow_triangle_2_circlepath'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
          SymbolGlyph($r('sys.symbol.trash'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
        }
      }
      Divider().width(5).color(this.fontColorValue1).width('98%')
      Row(){
        Row(){
          Text("歌曲五")
        }.width('82%')
        Row({ space: 5}) {
          SymbolGlyph($r('sys.symbol.play_arrow_triangle_2_circlepath'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
          SymbolGlyph($r('sys.symbol.trash'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
        }
      }
      Divider().width(5).color(this.fontColorValue1).width('98%')
      Row(){
        Row(){
          Text("歌曲六")
        }.width('82%')
        Row({ space: 5}) {
          SymbolGlyph($r('sys.symbol.play_arrow_triangle_2_circlepath'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
          SymbolGlyph($r('sys.symbol.trash'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
        }
      }
      Divider().width(5).color(this.fontColorValue1).width('98%')
      Row(){
        Row(){
          Text("歌曲七")
        }.width('82%')
        Row({ space: 5}) {
          SymbolGlyph($r('sys.symbol.play_arrow_triangle_2_circlepath'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
          SymbolGlyph($r('sys.symbol.trash'))
            .fontColor([this.fontColorValue])
            .fontSize(20)
        }
      }
      Divider().width(5).color(this.fontColorValue1).width('98%')
      Column(){
        Text("关闭")
      }
      .alignItems(HorizontalAlign.Center)
      .width('98%')
    }
    .alignItems(HorizontalAlign.Start)
    .width('100%')
    .height(400)
    .padding({
      left:10,
      top:10
    })
  }
}
```
![symbol_scene_demo](figures/symbol_music_demo.gif)
