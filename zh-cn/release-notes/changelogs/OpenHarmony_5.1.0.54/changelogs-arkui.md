# ArkUI子系统Changelog


## cl.arkui.1 通用属性backgroundEffect在modifier中radius参数单位修改

**访问级别**

公开接口

**变更原因**

 直接使用backgroundEffect时对应的模糊参数radius单位为vp。通过modifier或者CAPI使用时，单位为px。现将单位同一为vp。

**变更影响**

此变更涉及应用适配。

变更前：backgroundEffect通过modifier使用时单位为px。<br/>
![addComponentContent_before](figures/backgroundEffect_before.png)

变更后：backgroundEffect通过modifier使用时单位为vp。<br/>
![addComponentContent_after](figures//backgroundEffect_after.png)



**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.1.0.45 版本开始。

**变更的接口/组件**

backgroundEffect

**适配指导**

在modifier中使用px2vp方法把radius参数转换为vp。

```ts

import { CommonModifier } from '@kit.ArkUI';

class ColumnModifier extends CommonModifier {
  public radius: number = 0;
  applyNormalAttribute(instance: CommonAttribute): void {
    instance.backgroundEffect({ radius: this.radius })
  }
}

@Entry
@Component
struct Index {
  @State testSize: number = 200;
  @State modifier:ColumnModifier = new ColumnModifier();
  onPageShow(): void {
    // 变更前
    // this.modifier.radius = 10;
    // 变更后适配
    this.modifier.radius = px2vp(10);
  }
  build() {
    Column() {
      Stack() {
        Image($r('app.media.test')).width(this.testSize).height(this.testSize)
        Column().width(this.testSize).height(this.testSize).attributeModifier(this.modifier)
      }.width('100%')
    }
  }
}
```

## cl.arkui.2 DrawModifier的invalidate接口行为变更

**变更原因**

实现bug，之前实现中未在节点标脏后请求下一帧vsync信号，导致部分场景下invalidate无法刷新绘制内容。

**变更影响**

此变更不涉及应用适配。

| 变更前                                        | 变更后                                        |
|-----------------------------------------------|-----------------------------------------------|
|invalidate接口仅对节点标脏，不请求下一帧。导致节点标脏但不会刷新重绘。等到其他操作，例如点击触发下一帧信号的时候才会重绘。 |invalidate接口对节点标脏后主动请求下一帧，使节点及时刷新重绘。|

使用如下示例代码对影响补充说明。

```ts
import { drawing } from '@kit.ArkGraphics2D';

class MyFrontDrawModifier extends DrawModifier {
  public scaleX: number = 1;
  public scaleY: number = 1;

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
    context.canvas.drawCircle(vp2px(halfWidth), vp2px(halfHeight), vp2px(20 * radiusScale));
  }
}

@Entry
@Component
struct DrawModifierExample {
  @State modifier: MyFrontDrawModifier = new MyFrontDrawModifier();
  @State changeScale: boolean = false;

  build() {
    Column() {
      Row() {
        Text()
          .width(100)
          .height(100)
          .margin(10)
          .backgroundColor(Color.Gray)
          .drawModifier(this.modifier)
      }

      Button('invalidate immediately')
        .onClick(() => {
          this.changeScale = !this.changeScale
          // 变更前后不影响，节点在invalidate的下一帧刷新
          this.changeScale ? this.modifier.scaleX = 2 : this.modifier.scaleX = 1
          this.changeScale ? this.modifier.scaleY = 2 : this.modifier.scaleY = 1
          this.modifier.invalidate()
        }
        )
      Button('invalidate in setTimeout ')
        .onClick(() => {
          setTimeout(() => {
            // 变更前：invalidate对节点标脏，但不请求下一帧，等到其他事件触发下一帧，进行刷新绘制
            // 变更后：节点在invalidate的下一帧刷新
            this.changeScale = !this.changeScale
            this.changeScale ? this.modifier.scaleX = 2 : this.modifier.scaleX = 1
            this.changeScale ? this.modifier.scaleY = 2 : this.modifier.scaleY = 1
            this.modifier.invalidate()
          }, 1000)
        }
        )
    }
  }
}
```

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.54开始。

**变更的接口/组件**

common.d.ts#DrawModifier.invalidate

**适配指导**

默认行为变更，无需适配。但需要注意invalidate调用后没有其他操作产生请求下一帧的场景下的影响。

## cl.arkui.3 节点默认生命周期回调策略变更

**访问级别**

公开接口

**变更原因**

节点复用情况下，造成冗余的性能损耗。

**变更影响**

此变更不涉及应用适配。

| 变更前                           |           变更后 |
|---------------------------------|------------------|
|节点复用情况下,如果存在父布局约束。节点通过addChild重新上树默认触发测量，布局以及绘制。| 节点复用情况下节点通过addChild重新上树，只有布局约束发生变化才会触发测量布局以及绘制。|

变更前后示例代码对比如下，调用rebuildTree变更前会触发customEventReceiver变更后不会。<br/>

示例代码如下，完整实例可参考使用ndk接口构建接入UI中的接入ArkTS页面。

```ts

static std::vector<ArkUI_NodeHandle> childList;

void registerCustomEvent(ArkUI_NodeHandle node) {
    nodeApi->registerNodeCustomEvent(node, ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE, 0, nullptr);
    nodeApi->registerNodeCustomEvent(node, ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT, 0, nullptr);
    nodeApi->registerNodeCustomEvent(node, ARKUI_NODE_CUSTOM_EVENT_ON_DRAW, 0, nullptr);
}

void customEventReceiver(ArkUI_NodeCustomEvent *event) {
   auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
  // 变更前会触发自定义测量，布局，绘制事件
  // 变更后不会触发自定义测量，布局，绘制事件
} 

void init() {

auto rootNode = nodeApi->CreateNode(ARKUI_NODE_CUSTOM);
auto child1 = nodeApi->CreateNode(ARKUI_NODE_CUSTOM);
auto child2 = nodeApi->CreateNode(ARKUI_NODE_CUSTOM);
nodeApi->addChild(rootNode, child1);
nodeApi->addChild(rootNode, child2);
childList.push_back(child1);
childList.push_back(child2);
ArkUI_NumberValue value[] = {{.f32 = 100}};
ArkUI_AttributeItem item = {value, 1};
nodeApi->setAttribute(rootNode, NODE_WIDTH, item);
nodeApi->setAttribute(child1, NODE_WIDTH, item);
nodeApi->setAttribute(child2, NODE_WIDTH, item);
nodeApi->setAttribute(rootNode, NODE_HEIGHT, item);
nodeApi->setAttribute(child1, NODE_HEIGHT, item);
nodeApi->setAttribute(child2, NODE_HEIGHT, item);

// 注册订阅自定义事件
registerCustomEvent(rootNode);
registerCustomEvent(child1);
registerCustomEvent(child2);
nodeApi->registerNodeCustomEventReceiver(customEventReceiver);
}

void rebuildTree(ArkUI_NodeHandle root) {
  // 触发组件上下树
  auto front = childList.front();
  nodeApi->removeChild(root, front);
  childList.erase(childList.begin());
  nodeApi->addChild(root, front);
  childList.push_back(front);
} 

```

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.54开始。

**变更的接口/组件**

frameNode 生命周期。

**适配指导**

默认行为变更无需适配。

## cl.arkui.4 禁用键盘Ctrl按键和触控板轴事件触发缩放手势变更

**访问级别**

公开接口

**变更原因**

UX规格变化。

**变更影响**

此变更不涉及应用适配。

变更前：键盘Ctrl按键和触控板双指水平滑动或者垂直滑动时，可以触发缩放手势。

变更前：键盘Ctrl按键和触控板双指水平滑动或者垂直滑动时，不可以触发缩放手势。

**起始API Level**

接口起始版本为API version 7。

**变更发生版本**

从OpenHarmony SDK 5.1.0.54开始。

**变更的接口/组件**

ArkTS：PinchGestureInterface、PinchGestureHandler

C API：createPinchGesture

**适配指导**

默认UX变更无需适配。

## cl.arkui.5  半模态底部样式最大高度默认避让状态栏安全区

**访问级别**

公开接口

**变更原因**

UX规格变更。

半模态底部样式最大高度默认避让状态栏安全区。

**变更影响**

此变更不涉及应用适配。
 
场景1：竖屏下，状态栏隐藏时，半模态底部样式最大高度也需要避让状态栏安全区。

- 变更前：状态栏隐藏时，半模态底部样式最大高度距离屏幕上边界8vp，未避让状态栏安全区。
- 变更后：API version 18及以后，状态栏隐藏时，半模态底部样式最大高度距离状态栏下边界8vp，避让状态栏安全区。该样式的最大高度为屏幕高度 - (窗口状态栏安全区高度 + 安全间距8vp)。

| 变更前 | 变更后 |
|------ |--------|
|![verticalSheet1](figures/verticalSheet1.png)|![verticalSheet2](figures/verticalSheet2.png)|
 
场景2：横屏下，状态栏不隐藏时，半模态底部样式最大高度也需要避让状态栏安全区。

- 变更前：状态栏不隐藏时，半模态底部样式最大高度距离屏幕上边界8vp，未避让状态栏安全区，且与状态栏区域重合。
- 变更后：API version 18及以后，状态栏不隐藏时，半模态底部样式最大高度距离状态栏下边界8vp，避让状态栏安全区。该样式的最大高度为屏幕高度 - (窗口状态栏安全区高度 + 安全间距8vp)。

| 变更前 | 变更后 |
|------ |--------|
|![horizontalSheet1](figures/horizontalSheet1.jpg)|![horizontalSheet2](figures/horizontalSheet2.jpg)|

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.1.0.54 版本开始。

**变更的接口/组件**

bindSheet的LARGE属性

**适配指导**

若开发者自定义的builder面板内容是固定高度，建议使用100%布局，变更后自定义的内容也可以自动撑满半模态面板。

若按变更前的最大高度规格限制的builder内容，需要变更为新规格计算。

## cl.arkui.6 sharedTransition在id入参为undefined或空字符串时的行为变更

**访问级别**

公开接口

**变更原因**

sharedTransition的id从非空字符串变为空字符串或undefined时，无法实现清空共享元素转场id的效果。

**变更影响**

此变更涉及应用适配，API18之前不变，API18及以后，发生变更。

变更前：sharedTransition的id从非空字符串变为空字符串或undefined时，会维持之前的有效id值。

变更后：sharedTransition的id从非空字符串变为空字符串或undefined时，会将共享元素转场id置为空字符串，达到取消sharedTransition匹配的效果。

**起始API Level**

API 7

**变更发生版本**

从OpenHarmony SDK 5.1.0.54版本开始。

**变更的接口/组件**

common.d.ts文件的sharedTransition接口

**适配指导**

开发者如果希望同一组件的sharedTransition的id维持有效值不变，且开发者已经主动设置id为空字符串或undefined时，需要适配。适配方式为不更改sharedTransition的id，维持之前的有效值不变。其余情况无需适配。

## cl.arkui.8  bindSheet在2in1设备中默认避让窗口安全区

**访问级别**

公开接口

**变更原因**

UX规格变更。

半模态内容需默认避让窗口安全区，否则会有重叠区域。

**变更影响**

此变更涉及应用适配，API18之前不变，API18及以后，发生变更。

当自由窗口标题栏类型为悬浮标题栏时，需要半模态面板默认避让标题安全区。

场景1：半模态居中弹窗样式

- 变更前：半模态居中弹窗样式的面板最大高度为窗口高度的90%。
- 变更后：API version 18及以后，该样式的最大高度为窗口高度 - (窗口安全区高度 + 安全间距8vp) * 2。

| 变更前 | 变更后 |
|------ |--------|
|![sheetCenter1](figures/sheetCenter1.png)|![sheetCenter2](figures/sheetCenter2.png)|

场景2：半模态底部弹窗样式

- 变更前：半模态底部弹窗样式的面板最大高度为窗口高度 - 8vp。
- 变更后：API version 18及以后，该样式的最大高度为窗口高度 - (窗口安全区高度 + 安全间距8vp)。

| 变更前 | 变更后 |
|------ |--------|
|![sheetBottom1](figures/sheetBottom1.png)|![sheetBottom2](figures/sheetBottom2.png)|

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.1.0.54版本开始。

**变更的接口/组件**

bindSheet的preferType属性

**适配指导**

若开发者自定义的builder面板内容是固定高度，建议使用100%布局，变更后自定义的内容也可以自动撑满半模态面板。

若按变更前的最大高度规格限制的builder内容，需要变更为新规格计算。