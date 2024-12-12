# ArkUI子系统Changelog

## cl.arkui.1 ChipGroup选项后缀图标属性变更

**访问级别**

公开接口

**变更原因**

 ChipGroup 选项后缀图标需要支持配置无障碍信息以实现屏幕朗读功能，而前缀图标不需要实现屏幕朗读功能，同时后缀图标配置参数（suffixIcon）与前缀图标配置参数（prefixIcon）共用了同一个数据类型（IconOptions），不可以直接扩展IconOptions参数。因此决定废弃suffixIcon配置参数，并提供suffixImageIcon替代。

**变更影响**

该变更为不兼容性变更。

变更前：使用suffixIcon配置ChipGroup选项的后缀图标信息；

变更后：使用suffixImageIcon配置ChipGroup选项的后缀图标信息。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.51开始

**变更的接口/组件**

废弃suffixIcon配置参数，并新增suffixImageIcon替代。

**适配指导**

使用suffixImageIcon配置ChipGroup选项的后缀图标信息。示例如下:

```ts
import { ChipGroup, IconGroupSuffix, SymbolGlyphModifier } from '@kit.ArkUI';

@Builder function DefaultFunction(): void {}

@Component
struct SectionGroup {
  @Prop
  @Require
  title: ResourceStr;
  @BuilderParam
  @Require
  content: () => void = DefaultFunction;

  build() {
    Column({ space: 4 }) {
      Text(this.title)
        .fontColor('#FF666666')
        .fontSize(12)
      Column({ space: 8 }) {
        this.content()
      }
    }
    .alignItems(HorizontalAlign.Start)
    .width('100%')
  }
}
@Component
struct SectionItem {
  @Prop
  @Require
  title: ResourceStr;
  @BuilderParam
  @Require
  content: () => void = DefaultFunction;

  build() {
    Column({ space: 12 }) {
      Text(this.title)
      this.content()
    }
    .backgroundColor('#FFFFFFFF')
    .borderRadius(12)
    .padding(12)
    .width('100%')
  }
}

@Entry
@Component
export struct ChipGroupExample2 {
  @LocalBuilder
  Suffix() {
    IconGroupSuffix({
      items: [
        {
          icon: { src: $r('sys.media.ohos_ic_public_more'), },
          accessibilityText: '更多',
          accessibilityDescription: '新手提醒',
          action: () => {
            this.getUIContext().getPromptAction().showToast({
              message: '更多按钮被点击！'
            });
          }
        },
        {
          symbol: new SymbolGlyphModifier($r('sys.symbol.more'))
            .accessibilityText('更多')
            .accessibilityDescription('新手提醒'),
          action: () => {
            this.getUIContext().getPromptAction().showToast({
              message: '更多按钮被点击！'
            });
          }
        },
        {
          icon: { src: $r('sys.media.ohos_ic_public_more'), },
          accessibilityText: '更多',
          accessibilityDescription: '新手提醒',
          accessibilityLevel: 'no',
          action: () => {
            this.getUIContext().getPromptAction().showToast({
              message: '更多按钮被点击！'
            });
          }
        }
      ]
    })
  }

  build() {
    NavDestination() {
      Scroll() {
        Column({ space: 12 }) {
          SectionGroup({ title: '可用的' }) {
            SectionItem({ title: '单选 无后缀区域' }) {
              ChipGroup({
                items: [
                  {
                    prefixIcon: {
                      src: $r('app.media.startIcon')
                    },
                    label: { text: "选项1" },
                    suffixImageIcon: {
                      src: $r('sys.media.save_button_picture'),
                      accessibilityText: '保存',
                      action: () => {
                        this.getUIContext().getPromptAction().showToast({
                          message: '后缀图标被点击！'
                        });
                      },
                    }
                  },
                  {
                    label: { text: "选项2" },
                    suffixSymbol: {
                      normal: new SymbolGlyphModifier($r('sys.symbol.save')),
                      activated: new SymbolGlyphModifier($r('sys.symbol.save'))
                    },
                    suffixSymbolOptions: {
                      normalAccessibility: {
                        accessibilityText: '保存'
                      },
                      action: () => {
                        this.getUIContext().getPromptAction().showToast({
                          message: '后缀图标被点击！'
                        });
                      }
                    }
                  },
                  {
                    label: { text: "选项3" },
                    suffixIcon: { src: $r('sys.media.save_button_picture'), }
                  },
                  { label: { text: "选项4" } },
                  { label: { text: "选项5" } },
                  { label: { text: "选项6" } },
                  { label: { text: "选项7" } },
                  { label: { text: "选项8" } },
                  { label: { text: "选项9" } },
                ]
              })
            }
          }
        }
      }
    }
    .title('基础用法')
    .backgroundColor('#F1F3F5')
  }
}
```

## cl.arkui.2 ImageAttributeModifier支持new方式创建ColorFilter对象传入colorFilter接口变更

**访问级别**

公开接口

**变更原因**

ImageAttributeModifier不支持new方式创建ColorFilter对象传入colorFilter接口，修复后即可增加colorFilter接口的支持范围，并且ColorFilter在业务代码中传递更加便捷。

**变更影响**

该变更为不兼容变更。

变更前：ImageAttributeModifier不支持new方式创建ColorFilter对象传入colorFilter接口。

变更后：ImageAttributeModifier支持new方式创建ColorFilter对象传入colorFilter接口。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.51开始。

**变更的接口/组件**

ImageAttributeModifier的colorFilter接口。

**适配指导**

使用ImageAttributeModifier的colorFilter接口时，已经支持new方式创建ColorFilter对象传入接口中。示例如下:

```ts
class ColorFilterModifier implements AttributeModifier<ImageAttribute> {
  private colorFilter: ColorFilter | undefined = undefined

  constructor(colorFilter: ColorFilter) {
    this.colorFilter = colorFilter
  }

  applyNormalAttribute(instance: ImageAttribute): void {
    instance.colorFilter(this.colorFilter)
  }
}


@Entry
@Component
struct ColorFilters {
  @State modifier: ColorFilterModifier = new ColorFilterModifier(new ColorFilter([0.1, 0.1, 0.1, 0.1, 0.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.8, 0,]))

  build() {
    Column() {
      Image($r('app.media.startIcon'))
        .width(100)
        .height(100)
        .attributeModifier(this.modifier)
    }
    .height('100%')
    .width('100%')
  }
}
```

## cl.arkui.3  CanvasRenderingContext2D的drawImage接口默认单位变更

**访问级别**

公开接口

**变更原因**

当drawImage传入9个参数时，若首个参数（image）为PixelMap类型，则第2至第5个参数（sx、sy、sw和sh）以px为单位进行解析。与文档描述不一致，且绘制得到的图片大小存在问题。

**变更影响**

该变更为不兼容变更。

当drawImage传入9个参数时，且首个参数为PixelMap类型时：

- 变更前：第2至第5个参数都会以px为单位进行解析。
- 变更后：
  - API version 13及以前，第2至第5个参数会以px为单位进行解析；
  - API version 14及以后，第2至第5个参数会以vp为单位进行解析。

|               变更前                |              变更后               |
| :---------------------------------: | :-------------------------------: |
| ![](figures/before_drawimage_change.jpeg) | ![](figures/after_drawimage_change.jpeg) |

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.51 版本开始。

**变更的接口/组件**

CanvasRenderingContext2D的drawImage接口

**适配指导**

API version 14及以后，使用drawImage接口时，若传入9个参数，且首个参数为PixelMap类型时，要注意第2至第5个参数会以vp为单位进行解析。

**示例**

```ts
import { image } from '@kit.ImageKit'

@Entry
@Component
struct Demo {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .onReady(() => {
          let context = getContext(this)
          let imageSourceApi = image.createImageSource(context.filesDir + "/view.jpg")
          let pixelmap = imageSourceApi.createPixelMapSync();
          let imageInfo = pixelmap.getImageInfoSync()
          let width = px2vp(imageInfo.size.width)
          let height = px2vp(imageInfo.size.height)
          this.context.drawImage(pixelmap, 0, 0, width, height, 50, 50, 250, 200)
          this.context.drawImage(pixelmap, 0, 0, imageInfo.size.width, imageInfo.size.height, 50, 300, 250, 200)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## cl.arkui.4  空格/回车响应按键事件行为变更

**访问级别**

公开接口

**变更原因**

空格键和回车键能够默认触发获焦组件的点击事件。即便当前界面未进入焦点激活状态（即未显示焦点框），这些按键依然会触发相应的事件。

**变更影响**

该变更为不兼容变更。

影响范围：依赖空格键/回车键响应点击事件的应用；

- 变更前：组件获焦，无需进入焦点激活态，空格/回车可以触发点击事件。
- 变更后：组件获焦且界面进入焦点激活态，空格/回车才可以触发点击事件。


**起始API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.0.0.51 版本开始。

**变更的接口/组件**

不涉及

**适配指导**

适配的场景仅限于在非走焦态响应点击事件。适配方案是在原本绑定点击事件的组件上新绑定按键事件，而按键事件的触发不依赖于走焦状态。示例如下：

**示例**

```ts
import { KeyCode } from '@kit.InputKit';

@Entry
@Component
struct KeyEventExample {
  @State text1: string = "can not respond event"
  @State text2: string = "can not respond event"

  build() {
    Column() {
      Text(this.text1)
      // Button中仅包含onClick事件，在非走焦态的时，即使Button获焦，空格键和回车键依然不响应onClick事件。
      Button('KeyEvent')
        .onClick(() => {
          this.text1 = 'respond click event'
        })
      Text(this.text2)
      // 若需要在非走焦态下，Button获焦且空格键或回车键能够响应，需要通过增加onKeyEvent事件来触发。
      Button('KeyEvent')
        .onClick(() => {
          this.text2 = 'respond click event'
        })
        .onKeyEvent((event?: KeyEvent) => {
          if (event && event.type == KeyType.Down &&
            (event.keyCode == KeyCode.KEYCODE_ENTER || event.keyCode == KeyCode.KEYCODE_NUMPAD_ENTER ||
              event.keyCode == KeyCode.KEYCODE_SPACE)) {
            this.text2 = 'respond onKeyEvent event'
            return true
          }
          return false
        })
    }
  }
}
```