# Drawing Modifier

If the drawn content of some components does not meet the requirements, you can use the custom drawing features to draw part or all of the components to achieve the expected effect. For example, you can create buttons in special shapes or icons that mix text and imagery. The drawing modifier offers higher flexibility in your custom drawing.

>  **NOTE**
>
>  This feature is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## drawModifier

drawModifier(modifier: DrawModifier | undefined)

Creates a drawing modifier.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Supported components:**

AlphabetIndexer, Badge, Blank, Button, CalendarPicker, Checkbox, CheckboxGroup, Circle, Column, ColumnSplit, Counter, DataPanel, DatePicker, Ellipse, Flex, FlowItem, FolderStack, FormLink, Gauge, Grid, GridCol, GridItem, GridRow, Hyperlink, Image, ImageAnimator, ImageSpan, Line, List, ListItem, ListItemGroup, LoadingProgress, Marquee, Menu, MenuItem, MenuItemGroup, NavDestination, Navigation, Navigator, NavRouter, NodeContainer, Path, PatternLock, Polygon, Polyline, Progress, QRCode, Radio, Rating, Rect, Refresh, RelativeContainer, RichEditor, Row, RowSplit, Scroll, ScrollBar, Search, Select, Shape, SideBarContainer, Slider, Stack, Stepper, StepperItem, Swiper, SymbolGlyph, TabContent, Tabs, Text, TextArea, TextClock, TextInput, TextPicker, TextTimer, TimePicker, Toggle, WaterFlow, XComponent

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| modifier  |  DrawModifier \| undefined | Yes  | Custom drawing modifier, which defines the logic of custom drawing.<br> Default value: **undefined**<br>**NOTE**<br> A custom modifier applies only to the FrameNode of the currently bound component, not to its subnodes.|

## DrawModifier

Implements a **DrawModifier** instance for using the **drawFront**, **drawContent**, and **drawBehind** methods for custom drawing as well as the **invalidate** method for redrawing. Each **DrawModifier** instance can be set for only one component. Repeated setting is not allowed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### drawFront

drawFront?(drawContext: DrawContext): void

Draws the foreground. This method can be overloaded for custom foreground drawing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| drawContext | [DrawContext](../js-apis-arkui-graphics.md#drawcontext) | Yes  | Graphics drawing context.|

### drawContent

drawContent?(drawContext: DrawContext): void

Draws the content. This method can be overloaded for custom content drawing. The overloaded method will replace the original content drawing function of the component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| drawContext | [DrawContext](../js-apis-arkui-graphics.md#drawcontext) | Yes  | Graphics drawing context.|

### drawBehind

drawBehind?(drawContext: DrawContext): void

Draws the background. This method can be overloaded for custom background drawing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| drawContext | [DrawContext](../js-apis-arkui-graphics.md#drawcontext) | Yes  | Graphics drawing context.|


### invalidate

invalidate(): void

Triggers redrawing of the bound component. No overloading is allowed or needed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## Example
```ts
// xxx.ets
import { drawing } from '@kit.ArkGraphics2D';
import { Animator, AnimatorResult } from '@kit.ArkUI';

class MyFullDrawModifier extends DrawModifier {
  public scaleX: number = 1;
  public scaleY: number = 1;

  drawBehind(context: DrawContext): void
  {
    const brush = new drawing.Brush();
    brush.setColor({
      alpha: 255,
      red: 255,
      green: 0,
      blue: 0
    });
    context.canvas.attachBrush(brush);
    const halfWidth = context.size.width / 2;
    const halfHeight = context.size.width / 2;
    context.canvas.drawRect({
      left: vp2px(halfWidth - 50 * this.scaleX),
      top: vp2px(halfHeight - 50 * this.scaleY),
      right: vp2px(halfWidth + 50 * this.scaleX),
      bottom: vp2px(halfHeight + 50 * this.scaleY)
    });
  }

  drawContent(context: DrawContext): void
  {
    const brush = new drawing.Brush();
    brush.setColor({
      alpha: 255,
      red: 0,
      green: 255,
      blue: 0
    });
    context.canvas.attachBrush(brush);
    const halfWidth = context.size.width / 2;
    const halfHeight = context.size.width / 2;
    context.canvas.drawRect({
      left: vp2px(halfWidth - 30 * this.scaleX),
      top: vp2px(halfHeight - 30 * this.scaleY),
      right: vp2px(halfWidth + 30 * this.scaleX),
      bottom: vp2px(halfHeight + 30 * this.scaleY)
    });
  }

  drawFront(context: DrawContext): void
  {
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
    context.canvas.drawCircle(vp2px(halfWidth), vp2px(halfHeight), vp2px(20 * radiusScale));
  }
}

class MyFrontDrawModifier extends DrawModifier {
  public scaleX: number = 1;
  public scaleY: number = 1;

  drawFront(context: DrawContext): void
  {
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
    context.canvas.drawCircle(vp2px(halfWidth), vp2px(halfHeight), vp2px(20 * radiusScale));
  }
}

@Entry
@Component
struct DrawModifierExample {
  private fullModifier: MyFullDrawModifier = new MyFullDrawModifier();
  private frontModifier: MyFrontDrawModifier = new MyFrontDrawModifier();
  private drawAnimator: AnimatorResult | undefined = undefined;
  @State modifier: DrawModifier = new MyFrontDrawModifier();
  private count = 0;

  create() {
    let self = this;
    this.drawAnimator = Animator.create({
      duration: 1000,
      easing: 'ease',
      delay: 0,
      fill: 'forwards',
      direction: 'normal',
      iterations: 1,
      begin: 0,
      end: 2
    });
    this.drawAnimator.onFrame = (value: number) => {
      console.log('frame value =', value);
      const tempModifier = self.modifier as MyFullDrawModifier | MyFrontDrawModifier;
      tempModifier.scaleX = Math.abs(value - 1);
      tempModifier.scaleY = Math.abs(value - 1);
      self.modifier.invalidate();
    };
  }

  build() {
    Column() {
      Row() {
        Text('test text')
        .width(100)
        .height(100)
        .margin(10)
        .backgroundColor(Color.Gray)
        .onClick(() => {
          const tempModifier = this.modifier as MyFullDrawModifier | MyFrontDrawModifier;
          tempModifier.scaleX -= 0.1;
          tempModifier.scaleY -= 0.1;
        })
        .drawModifier(this.modifier)
      }
      Row() {
        Button('create')
        .width(100)
        .height(100)
        .margin(10)
        .onClick(() => {
          this.create();
        })
        Button('play')
        .width(100)
        .height(100)
        .margin(10)
        .onClick(() => {
          if (this.drawAnimator) {
            this.drawAnimator.play();
          }
        })
        Button('changeModifier')
        .width(100)
        .height(100)
        .margin(10)
        .onClick(() => {
          this.count += 1;
          if (this.count % 2 === 1) {
            console.log('change to full modifier');
            this.modifier = this.fullModifier;
          } else {
            console.log('change to front modifier');
            this.modifier = this.frontModifier;
          }
        })
      }
    }
    .width('100%')
    .height('100%')
  }
}
```

![drawModifier.gif](figures/drawModifier.gif)
