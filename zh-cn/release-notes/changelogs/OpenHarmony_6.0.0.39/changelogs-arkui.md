# ArkUI子系统Changelog

## cl.arkui.1 半模态SIDE侧边样式新增避让软键盘能力

**访问级别**

公开接口

**变更原因**

[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)半模态弹窗侧边样式默认支持避让软键盘，提升易用性。

**变更影响**

此变更涉及应用适配。

- 变更前：当半模态样式指定为[SheetType](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheettype11枚举说明)的SIDE侧边样式时，[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的属性keyboardAvoidMode设置为[SheetKeyboardAvoidMode](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetkeyboardavoidmode13枚举说明)的避让软键盘方式无效，半模态默认不避让软键盘，需要开发者自定义避让软键盘。
  
- 变更后：当半模态样式指定为[SheetType](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheettype11枚举说明)的SIDE侧边样式时，[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的属性keyboardAvoidMode设置为[SheetKeyboardAvoidMode](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetkeyboardavoidmode13枚举说明)的避让软键盘方式将生效，半模态支持避让软键盘，默认值为SheetKeyboardAvoidMode.TRANSLATE_AND_SCROLL。若开发者希望自定义避让软键盘，则需设置属性keyboardAvoidMode = SheetKeyboardAvoidMode.NONE。

**起始API Level**

API 20

**变更发生版本**

从OpenHarmony SDK 6.0.0.39开始。

**变更的接口/组件**

涉及接口：
[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的keyboardAvoidMode属性。

[SheetType](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheettype11枚举说明)的SIDE半模态侧边样式。

**适配指导**

默认行为变更，当半模态样式指定为[SheetType](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheettype11枚举说明)的SIDE侧边样式时，若开发者期望自定义避让软键盘，则需要设置[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的属性keyboardAvoidMode = [SheetKeyboardAvoidMode](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetkeyboardavoidmode13枚举说明).NONE。

若开发者期望采用半模态控件自带的避让软键盘能力，则可以设置[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的属性keyboardAvoidMode = [SheetKeyboardAvoidMode](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetkeyboardavoidmode13枚举说明)的其他枚举值，或者不设置属性keyboardAvoidMode，采用默认值。

## cl.arkui.2 通用属性drawModifier接口行为变更

**访问级别**

公开接口

**变更原因**

（1）当drawModifier接口参数从DrawModifier对象变为undefined时，实际生效的仍是原来的DrawModifier对象。开发者无法重置其值，这与通用属性接口的规范不符。

（2）当前实现中，若组件设置了drawModifier属性，则默认会在生命周期的布局阶段之后触发重绘。对于绘制内容和尺寸均未发生变化的场景，这将导致多余的重绘，造成性能损耗。因此，调整设置drawModifier的节点的重绘规则，默认仅执行过测量过程的节点才进行重绘。

**变更影响**

此变更涉及应用适配。

- 变更前：（1）drawModifier接口参数从DrawModifier对象变为undefined后，生效的仍旧是原来的DrawModifier对象。（2）任何组件，如果设置了drawModifier属性，无论是否跳过测量（尺寸是否发生变化），都会触发重绘。
  
- 变更后：（1）drawModifier接口参数从DrawModifier对象变为undefined后，会将原来设置的值重置为undefined。（2）任何组件，如果设置了drawModifier属性，当其未跳过测量（尺寸可能发生变化）时，就会触发重绘。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 6.0.0.39开始。

**变更的接口/组件**

drawModifier

**适配指导**

（1）变更前，this.modifier = undefined;不会清除组件上生效的DrawModifier对象，而变更后则会完成清除。因此，若想保持行为不变，需要注释或删除这一行代码。

（2）若开发者的自定义绘制内容变化逻辑受到本次变更影响，在受影响属性变化的代码后加入invalidate以主动触发重绘，即可完成适配。

具体适配方案可参考下文示例。

```ts
import { drawing } from '@kit.ArkGraphics2D';

class MyFrontDrawModifier extends DrawModifier {
  public scaleX: number = 1;
  public scaleY: number = 1;
  public uiContext: UIContext;

  constructor(uiContext: UIContext) {
    super();
    this.uiContext = uiContext;
  }

  drawFront(context: DrawContext): void {
    const brush = new drawing.Brush();
    brush.setColor({
      alpha: 255,
      red: 0,
      green: 0,
      blue: 255
    });
    context.canvas.attachBrush(brush);
    const halfWidth = context.size.width / 2;
    const halfHeight = context.size.width / 2;
    const radiusScale = (this.scaleX + this.scaleY) / 2;
    context.canvas.drawCircle(this.uiContext.vp2px(halfWidth), this.uiContext.vp2px(halfHeight), this.uiContext.vp2px(20 * radiusScale));
  }
}

@Entry
@Component
struct DrawModifierExample {
  @State public modifierToBeCleared: DrawModifier | undefined = new MyFrontDrawModifier(this.getUIContext());
  public modifierToBeChanged: MyFrontDrawModifier = new MyFrontDrawModifier(this.getUIContext());
  @State public testWidth: number = 100;

  build() {
    Column() {
      Button("clearModifier").onClick(() => {
        // 变更前：下面代码不生效，Row组件仍旧绑定原本的modifier
        this.modifierToBeCleared = undefined;
        // 规避方法：变更前若想清空Text组件的自定义绘制效果，可将其绑定的变量变为基类对象
        this.modifierToBeCleared = new DrawModifier();
        // 变更后：若开发者期望行为和变更前保持一致，即下面代码不生效的话，只需要注释掉这一行即可
        // this.modifierToBeCleared = undefined;
      })
      Column() {
        Row()
          .width(100)
          .height(100)
          .margin(10)
          .backgroundColor(Color.Gray)
          .drawModifier(this.modifierToBeCleared)
      }
      .margin({ bottom: 50 })
      Button('changeModifier')
        .onClick(() => {
          this.testWidth++;
          this.modifierToBeChanged.scaleX += 0.1;
          this.modifierToBeChanged.scaleY += 0.1;
          // 变更前自动更新，变更后需要手动调用invalidate方法适配
          this.modifierToBeChanged?.invalidate();
        })
      Column() {
        Row()
          .width(100)
          .height(100)
          .margin(10)
          .backgroundColor(Color.Gray)
          .drawModifier(this.modifierToBeChanged)
        Row() {
          Text("hello world")
            .width(this.testWidth)
            .height(100)
        }
      }
      .width(300)
      .height(300)
    }
  }
}
```

## cl.arkui.3 CanvasRenderer的font接口支持自定义字体行为变更

**访问级别**

公开接口

**变更原因**

增强基础能力，CanvasRenderer的font接口支持设置自定义字体。

**变更影响**

此变更涉及应用适配。

变更前，CanvasRenderer的font接口设置自定义字体不生效，绘制字体显示为默认字体。

变更后，CanvasRenderer的font接口设置自定义字体生效，绘制字体显示为自定义字体。

```ts
import { text } from "@kit.ArkGraphics2D"

// xxx.ets
@Entry
@Component
struct FontDemo {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('rgb(213,213,213)')
        .onReady(() => {
          let fontCollection = text.FontCollection.getGlobalInstance();
          fontCollection.loadFontSync('HarmonyOS_Sans_Thin_Italic', $rawfile("HarmonyOS_Sans_Thin_Italic.ttf"))
          this.context.font = "50px HarmonyOS_Sans_Thin_Italic"
          this.context.fillText("Hello World", 20, 60)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

|                   变更前                   |                 变更后                  |
| :----------------------------------------: | :-------------------------------------: |
| ![](figures/canvasFontBefore.jpg) | ![](figures/canvasFontAfter.jpg) |

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony SDK 6.0.0.39开始。

**变更的接口/组件**

CanvasRenderingContext2D和OffscreenCanvasRenderingContext2D的font接口。

**适配指导**

变更后，CanvasRenderer的font接口设置自定义字体生效。若需保持变更前的默认字体行为，可以不设置自定义字体。
