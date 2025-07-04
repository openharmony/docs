# ArkUI子系统Changelog

## cl.arkui.1 通用属性drawModifier接口行为变更

**访问级别**

公开接口

**变更原因**

（1）当drawModifier接口参数从DrawModifier对象变为undefined时，实际生效的仍是原来的DrawModifier对象。开发者无法重置其值，这与通用属性接口的规范不符。

（2）当前实现中，若组件设置了drawModifier属性，则默认会在生命周期的布局阶段之后触发重绘。对于绘制内容和尺寸均未发生变化的场景，这将导致多余的重绘，造成性能损耗。因此，调整设置drawModifier的节点的重绘规则，默认仅执行过测量过程的节点才进行重绘。

**变更影响**

此变更涉及应用适配。

- 变更前：（1）drawModifier接口参数从DrawModifier对象变为undefined后，生效的仍旧是原来的DrawModifier对象。（2）任何组件，只要设置了drawModifier属性，即使跳过测量，也会触发重绘。
  
- 变更后：（1）drawModifier接口参数从DrawModifier对象变为undefined后，会将原来设置的值重置为undefined。（2）若容器组件设置了drawModifier属性，则当其跳过测量时，不执行重绘。其他组件的重绘触发机制与是否使用drawModifier属性无关。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 6.0.0.37开始。

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
  @State public modifier1: DrawModifier | undefined = new MyFrontDrawModifier(this.getUIContext());
  public modifier2: MyFrontDrawModifier = new MyFrontDrawModifier(this.getUIContext());
  @State public testWidth: number = 100;

  build() {
    Column() {
      Button("clearModifier").onClick(() => {
        // 变更前：下面代码不生效，Row组件仍旧绑定原本的modifier
        this.modifier1 = undefined;
        // 规避方法：变更前若想清空Text组件的自定义绘制效果，可将其绑定的变量变为基类对象
        this.modifier1 = new DrawModifier();
        // 变更后：若开发者期望行为和变更前保持一致，即下面代码不生效的话，只需要注释掉这一行即可
        // this.modifier = undefined;
      })
      Column() {
        Row()
          .width(100)
          .height(100)
          .margin(10)
          .backgroundColor(Color.Gray)
          .drawModifier(this.modifier1)
      }
      .margin({ bottom: 50 })
      Button('changeModifier')
        .onClick(() => {
          this.testWidth++;
          this.modifier2.scaleX += 0.1;
          this.modifier2.scaleY += 0.1;
          // 适配手动调用invalidate方法
          this.modifier2?.invalidate();
        })
      Column() {
        Row()
          .width(100)
          .height(100)
          .margin(10)
          .backgroundColor(Color.Gray)
          .drawModifier(this.modifier2)
        Row() {
          Text("hello word")
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