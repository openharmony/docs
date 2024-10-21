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