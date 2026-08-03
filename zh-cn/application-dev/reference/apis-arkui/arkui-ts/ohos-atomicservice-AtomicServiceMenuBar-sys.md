# AtomicServiceMenuBar (系统接口)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @qq_36417014-->
<!--Designer: @autojuan-->
<!--Tester: @tinygreyy-->
<!--Adviser: @zengyawen-->

依赖当前原子化服务的上下文，创建AtomicServiceMenuBar对象，用于操控右上角菜单功能胶囊的显示与隐藏。

> **说明：**
>
> 该组件从API version 23开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { AtomicServiceMenuBar } from '@kit.ArkUI';
```

## 子组件

无

## 属性

不支持[通用属性](ts-component-general-attributes.md)。

## AtomicServiceMenuBar

使用当前原子化服务的UI上下文信息创建的对象，通过定义的接口操控当前原子化服务菜单功能胶囊的显隐状态。示例参见[示例](#示例)。

### constructor

constructor(uiContext: UIContext)

AtomicServiceMenuBar的构造函数。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                            | 必填   |  说明         |
| ---- | ----------------------------- | ---- | -------------------- |
| uiContext | [UIContext](../arkts-apis-uicontext-uicontext.md) | 是    | 当前原子化服务的上下文信息。 |

### setVisible

setVisible(visible: boolean): void

设置当前原子化服务菜单功能胶囊的显隐状态。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                            | 必填   |  说明         |
| ---- | ----------------------------- | ---- | -------------------- |
| visible | boolean | 是 | 菜单功能胶囊预期的状态。true表示显示菜单功能胶囊，false表示隐藏菜单功能胶囊。 |


## 示例

```ts
import { AtomicServiceMenuBar } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private menuBar: AtomicServiceMenuBar = new AtomicServiceMenuBar(this.getUIContext());

  @Builder
  private MenuCapsuleShow(title: string, text: string, event?: () => void) {
    Column() {
      if (typeof event === 'function') {
        Button(title)
          .width(300)
          .height(50)
          .fontSize(16)
          .borderRadius(25)
          .onClick(() => {
            event();
          })
      }
      Text(`预期现象：${text}`)
        .width(300)
        .textAlign(TextAlign.Start)
        .fontSize(12)
        .margin({ top: 5, bottom: 15})
    }
  }

  build() {
    Column() {
      this.MenuCapsuleShow('显示菜单功能胶囊', '点击后菜单功能胶囊显示', () => {
        this.menuBar.setVisible(true);
      });
      this.MenuCapsuleShow('隐藏菜单功能胶囊', '点击后菜单功能胶囊消失', () => {
        this.menuBar.setVisible(false);
      });
    }
    .width('100%')
    .height('100%')
    .padding({ top: 100 })
  }
}
```
点击“隐藏菜单功能胶囊”按钮后，菜单功能胶囊隐藏。

![AtomicServiceMenuBarDemo01](figures/AtomicServiceMenuBarDemo01.png)

点击“显示菜单功能胶囊”按钮后，菜单功能胶囊显示。

![AtomicServiceMenuBarDemo02](figures/AtomicServiceMenuBarDemo02.png)
