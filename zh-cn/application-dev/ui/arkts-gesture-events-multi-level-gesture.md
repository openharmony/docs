# 多层级手势事件

多层级手势事件指父子组件嵌套时，父子组件均绑定了手势或事件。在该场景下，手势或者事件的响应受到多个因素的影响，相互之间发生传递和竞争，容易出现预期外的响应。

本章主要介绍了多层级手势事件的默认响应顺序，以及如何通过设置相关属性影响多层级手势事件的响应顺序。

## 默认多层级手势事件

### 触摸事件

[触摸事件](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md)（onTouch事件）是所有手势组成的基础，有Down，Move，Up，Cancel四种。手势均由触摸事件组成，例如，点击为Down+Up，滑动为Down+一系列Move+Up。触摸事件具有最特殊性：

1.监听了onTouch事件的组件。若在手指落下时被触摸则均会收到onTouch事件的回调，被触摸受到触摸热区和触摸控制影响。

2.onTouch事件的回调是闭环的。若一个组件收到了手指Id为0的Down事件，后续也会收到手指Id为0的Move事件和Up事件。

3.onTouch事件的回调是一致的。若一个组件收到了手指Id为0的Down事件未收到手指Id为1的Down事件，则后续只会收到手指Id为0的touch事件，不会收到手指Id为1的后续touch事件。

对于一般的容器组件（例如：Column），父子组件之间onTouch事件能够同时触发，兄弟组件之间onTouch事件根据布局进行触发。

```ts
ComponentA() {
    ComponentB().onTouch(() => {})
    ComponentC().onTouch(() => {})
}.onTouch(() => {})
```
组件B和组件C作为组件A的子组件，当触摸到组件B或者组件C时，组件A也会被触摸到。onTouch事件允许多个组件同时触发，
因此，当触摸组件B时，会触发组件A和组件B的onTouch回调，不会触发组件C的onTouch回调。
当触摸组件C时，会触发组件A和组件C的onTouch回调，不触发组件B的回调。

特殊的容器组件，如Stack等组件，由于子组件之间存在着堆叠关系，子组件的布局也互相存在遮盖关系。
所以，父子组件之间onTouch事件能够同时触发，兄弟组件之间onTouch事件会存在遮盖关系。

```ts
Stack A() {
    ComponentB().onTouch(() => {})
    ComponentC().onTouch(() => {})
}.onTouch(() => {})
```
组件B和组件C作为Stack A的子组件，组件C覆盖在组件B上。当触摸到组件B或者组件C时，Stack A也会被触摸到。onTouch事件允许多个组件同时触发，因此，当触摸组件B和组件C的重叠区域时，会触发Stack A和组件C的onTouch回调，不会触发组件B的onTouch回调（组件B被组件C遮盖）。

### 手势与事件

除了触摸事件（onTouch事件）外的所有手势与事件，均是通过基础手势或者组合手势实现的。例如，拖拽事件是由长按手势和滑动手势组成的一个顺序手势。

在未显式声明的情况下，同一时间，一根手指对应的手势组中只会有一个手势获得成功从而触发所设置的回调。

因此，除非显式声明允许多个手势同时成功，同一时间只会有一个手势响应。

响应优先级遵循以下条件：

1.当父子组件均绑定同一类手势时，子组件优先于父组件触发。

2.当一个组件绑定多个手势时，先达到手势触发条件的手势优先触发。

```ts
ComponentA() {
    ComponentB().gesture(TapGesture({count: 1}))
}.gesture(TapGesture({count: 1}))    
```
当父组件和子组件均绑定点击手势时，子组件的优先级高于父组件。
因此，当在B组件上进行点击时，组件B所绑定的TapGesture的回调会被触发，而组件A所绑定的TapGesture的回调不会被触发。

```ts
ComponentA()
.gesture(
    GestureGroup(
        GestureMode.Exclusive,
        TapGesture({count: 1}),
        PanGesture({distance: 5})
    )
)
```
当组件A上绑定了由点击和滑动手势组成的互斥手势组时，先达到手势触发条件的手势触发对应的回调。
若使用者做了一次点击操作，则响应点击对应的回调。若使用者进行了一次滑动操作并且滑动距离达到了阈值，则响应滑动对应的回调。

## 自定义控制的多层级手势事件

可以通过设置属性，控制默认的多层级手势事件竞争流程，更好的实现手势事件。

目前，responseRegion属性和hitTestBehavior属性可以控制Touch事件的分发，从而可以影响到onTouch事件和手势的响应。而绑定手势方法属性可以控制手势的竞争从而影响手势的响应，但不能影响到onTouch事件。

### responseRegion对手势和事件的控制

responseRegion属性可以实现组件的响应区域范围的变化。响应区域范围可以超出或者小于组件的布局范围。

```ts
ComponentA() {
    ComponentB()
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))
    .responseRegion({Rect1, Rect2, Rect3})
}
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
.responseRegion({Rect4})
```
当组件A绑定了.responseRegion({Rect4})的属性后，所有落在Rect4区域范围的触摸事件和手势可被组件A对应的回调响应。

当组件B绑定了.responseRegion({Rect1, Rect2, Rect3})的属性后，所有落在Rect1,Rect2和Rect3区域范围的触摸事件和手势可被组件B对应的回调响应。

当绑定了responseRegion后，手势与事件的响应区域范围将以所绑定的区域范围为准，而不是以布局区域为准，可能出现布局相关区域不响应手势与事件的情况。

此外，responseRegion属性支持由多个Rect组成的数组作为入参，以支持更多开发需求。

### hitTestBehavior对手势和事件的控制

hitTestBehavior属性可以实现在复杂的多层级场景下，一些组件能够响应手势和事件，而一些组件不能响应手势和事件。

```ts
ComponentA() {
    ComponentB()
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))

    ComponentC() {
        ComponentD()
        .onTouch(() => {})
        .gesture(TapGesture({count: 1}))
    }
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))
    .hitTestBehavior(HitTestMode.Block)
}
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
```
HitTestMode.Block自身会响应触摸测试，阻塞子节点和兄弟节点的触摸测试，从而导致子节点和兄弟节点的onTouch事件和手势均无法触发。
    
当组件C未设置hitTestBehavior时，点击组件D区域，组件A、组件C和组件D的onTouch事件会触发，组件D的点击手势会触发。

当组件C设置了hitTestBehavior为HitTestMode.Block时，点击组件D区域，组件A和组件C的onTouch事件会触发，组件D的onTouch事件未触发。同时，由于组件D的点击手势因为被阻塞而无法触发，组件C的点击手势会触发。

```ts
Stack A() {
    ComponentB()
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))

    ComponentC()
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))
    .hitTestBehavior(HitTestMode.Transparent)
}
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
```
HitTestMode.Transparent自身响应触摸测试，不会阻塞兄弟节点的触摸测试。

当组件C未设置hitTestBehavior时，点击组件B和组件C的重叠区域时，Stack A和组件C的onTouch事件会触发，组件C的点击事件会触发，组件B的onTouch事件和点击手势均不触发。

而当组件C设置hitTestBehavior为HitTestMode.Transparent时，点击组件B和组件C的重叠区域，组件A和组件C不受到影响与之前一致，组件A和组件C的onTouch事件会触发，组件C的点击手势会触发。而组件B因为组件C设置了HitTestMode.Transparent，组件B也收到了Touch事件，从而组件B的onTouch事件和点击手势触发。

```ts
ComponentA() {
    ComponentB()
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))
}
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
.hitTestBehavior(HitTestMode.None)
```
HitTestMode.None自身不响应触摸测试，不会阻塞子节点和兄弟节点的触摸控制。

当组件A未设置hitTestBehavior时，点击组件B区域时，组件A和组件B的onTouch事件均会触发，组件B的点击手势会触发。

当组件A设置hitTestBehavior为HitTestMode.None时，点击组件B区域时，组件B的onTouch事件触发，而组件A的onTouch事件无法触发，组件B的点击手势触发。

针对简单的场景，建议在单个组件上绑定hitTestBehavior。
针对复杂场景，建议在多个组件上绑定不同的hitTestBehavior来控制Touch事件的分发。

### 绑定手势方法对手势的控制
设置绑定手势的方法可以实现在多层级场景下，当父组件与子组件绑定了相同的手势时，设置不同的绑定手势方法有不同的响应优先级。

当父组件使用.gesture绑定手势，父子组件所绑定手势类型相同时，子组件优先于父组件响应。

```ts
ComponentA() {
    ComponentB()
    .gesture(TapGesture({count: 1}))
}
.gesture(TapGesture({count: 1}))
```
当父子组件均正常绑定点击手势时，子组件优先于父组件响应。
此时，单击组件B区域范围，组件B的点击手势会触发，组件A的点击手势不会触发。

如果以带优先级的方式绑定手势，则可使得父组件所绑定手势的响应优先级高于子组件。

```ts
ComponentA() {
    ComponentB()
    .gesture(TapGesture({count: 1}))
}
.priorityGesture(TapGesture({count: 1}))
```
当父组件以.priorityGesture的形式绑定手势时，父组件所绑定的手势优先级高于子组件。
此时，单击组件B区域范围，组件A的点击手势会触发，组件B的点击手势不会触发。

如果需要父子组件所绑定的手势不发生冲突，均可响应，则可以使用并行的方式在父组件绑定手势。

```ts
ComponentA() {
    ComponentB()
    .gesture(TapGesture({count: 1}))
}
.parallelGesture(TapGesture({count: 1}))
```
当父组件以.parallelGesture的形式绑定手势时，父组件和子组件所绑定的手势均可触发。
此时，单击组件B区域范围，组件A和组件B的点击手势均会触发。

### OverlayManager的事件透传
OverlayManager事件机制，默认优先被WrappedBuilder内组件先接收，不会向下传递。

若希望OverlayManager下方的页面也能感应到事件，可采用hitTestBehavior(HitTestMode.Transparent)来传递事件，参考以下伪代码。

```ts
@Builder
function builderOverlay(params: Params) {
    Component().hitTestBehavior(HitTestMode.Transparent)
}

aboutToAppear(): void {
    let componentContent = new ComponentContent(
        this.context, wrapBuilder<[Params]>(builderOverlay),
        new Params(uiContext, {x:0, y: 100})
    );
    this.overlayManager.addComponentContent(componentContent, 0);
}
```