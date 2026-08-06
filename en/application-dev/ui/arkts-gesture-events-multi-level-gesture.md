# Multi-level Gesture Events

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=4c2e225aac32899cadee59d9bf9342ca46a9c9ff translatedAt=2026-08-01T00:26:57.024Z pushedAt=2026-08-01T03:42:07.205Z -->

Multi-level gesture events refer to scenarios where both parent and child components in a nested structure are bound to gestures or events. In such scenarios, the response to gestures or events is affected by multiple factors, with mutual transmission and competition between them, which is likely to cause unexpected responses.

This topic describes the default response sequence of multi-level gesture events and how to set related attributes to affect the response sequence of multi-level gesture events.

## Default Multi-level Gesture Events

### Touch Event

The [touch event](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md) (**onTouch**) is the foundation of all gestures, comprising four types: Down, Move, Up, and Cancel. Gestures are built from touch events. For example, a tap consists of Down and Up, and a swipe consists of Down, a series of Move events, and Up. Touch events have the following characteristics:

1. Components that have registered for **onTouch** events receive callbacks for these events when touched, influenced by touch hotspots and touch control settings.

2. The **onTouch** event callbacks follow a closed-loop pattern. If a component receives a Down event with finger ID **0**, it will also receive subsequent Move and Up events for the same finger ID.

3. The **onTouch** event callbacks maintain consistency. If a component receives a Down event for finger ID **0** but not for finger ID **1**, it will only receive touch events for finger ID **0** and will not receive subsequent touch events for finger ID **1**.

4. The **onTouch** event triggers a Cancel event in the following scenarios:

   - When a finger is pressing the screen and the Home button is pressed to return to the home screen, a Cancel event is triggered.

   <!--RP1--><!--RP1End-->

   - When a stylus operation occurs during a finger touch, the finger touch operation receives a Cancel event.

For common container components (such as **Column**), **onTouch** events can be received by parent and child components at the same time, and how they are received by sibling components is subject to the layout.

<!-- @[column_touch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/TouchEvent.ets) -->

``` TypeScript
Column() {
  Column().id('ComponentB').onTouch(() => {})
  Column().id('ComponentC').onTouch(() => {})
}.id('ComponentA').onTouch(() => {})
```

Components B and C are child components of component A. When component B or C is touched, component A is also touched. The **onTouch** event allows multiple components to be triggered simultaneously. Therefore, touching component B triggers the **onTouch** callbacks of both component A and component B, but not the **onTouch** callback of component C.

Touching component C triggers the **onTouch** callbacks of both component A and component C, but not the callback of component B.

Special container components, such as **Stack**, have child components arranged in a stacking order, meaning that their layouts may overlap and cover one another.

Therefore, **onTouch** events can be triggered simultaneously between parent and child components, while sibling components are subject to occlusion in **onTouch** event delivery.

<!-- @[stack_touch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/TouchEvent.ets) -->

``` TypeScript
Stack() {
  Column().id('ComponentB').onTouch(() => {})
  Column().id('ComponentC').onTouch(() => {})
}.id('Stack A').onTouch(() => {})
```

Assume that components B and C are children of Stack A, and component C covers component B. Then touching component B or component C also touches Stack A. The **onTouch** callback can be invoked by multiple components at the same time. Therefore, when the overlapping area of components B and C is touched, the **onTouch** callback is invoked by both Stack A and component C, but not by component B (which is covered by component C).

### Gestures and Events

All gestures and events except the touch event (**onTouch**) are implemented using basic or combined gestures. For example, the drag event is a sequence of a long press gesture and a swipe gesture.

If no explicit declaration is made, only one gesture in a gesture group can be recognized for a single finger at the same time, which means that only one set callback can be invoked.

Therefore, unless it is explicitly declared that multiple gestures can be recognized at the same time, only one gesture will respond at any given time.

The response to gestures complies with the following rules:

1. When the parent and child components are bound to the same type of gesture, the child component responds prior to the parent component.

2. When a component is bound to multiple gestures, the gesture that first meets triggering conditions is preferentially triggered.

<!-- @[priorityfirst_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/GesturesEvents.ets) -->

``` TypeScript
Column() {
  Column().id('ComponentB').gesture(TapGesture({ count: 1 }))
}.id('ComponentA').gesture(TapGesture({ count: 1 }))
```

When both a parent component and a child component have a tap gesture bound, the child component takes priority over the parent component.

Therefore, when the user touches component B, the callback of **TapGesture** bound to component B is invoked, but the callback bound to component A is not.

<!-- @[prioritysecond_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/GesturesEvents.ets) -->

``` TypeScript
Column()
  .id('ComponentA')
  .gesture(
    GestureGroup(
      GestureMode.Exclusive,
      TapGesture({count: 1}),
      PanGesture({distance: 5})
    )
  )
```

If the tap gesture and the swipe gesture are bound to a component in exclusive recognition mode, the gesture that first meets triggering conditions is preferentially triggered.

If the user performs a tap operation, the callback corresponding to the tap is invoked. If the user performs a swipe operation and the swipe distance reaches the threshold, the callback corresponding to the swipe is invoked.

## Handling Multi-level Gesture Events with Custom Logic

You can set attributes to control the multi-level gesture event competition process.

Currently, touch event distribution can be controlled by setting the [touch hotspot](../reference/apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md) and [hit testing](../reference/apis-arkui/arkui-ts/ts-universal-attributes-hit-test-behavior.md) attributes, which in turn affects the response of **onTouch** events and gestures. The bound gesture method attributes can control gesture competition and thus affect gesture response, but they do not affect **onTouch** events.

### Controlling Gestures and Events via Touch Hotspot

The touch hotspot of a component can be set through the [responseRegion](../reference/apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md#responseregion) and [mouseResponseRegion](../reference/apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md#mouseresponseregion10) attributes. Starting from API version 22, the touch hotspot can also be set through [responseRegionList](../reference/apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md#responseregionlist22). The touch hotspot area can extend beyond or be smaller than the component's layout area.

<!-- @[response_region](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/CustomEvent.ets) -->

``` TypeScript
Column() {
  Column()
    .id('ComponentB')
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))
    .responseRegion([rect1, rect2, rect3])
}
.id('ComponentA')
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
.responseRegion([rect4])
```

When component A has the **.responseRegion([rect4])** attribute set, all touch events and gestures that fall within the rect4 region can be responded to by the corresponding callback of component A.

When component B has the **.responseRegion([rect1, rect2, rect3])** attribute set, all touch events and gestures that fall within the rect1, rect2, and rect3 regions can be responded to by the corresponding callback of component B.

When **responseRegion** is set for a component, the component responds to all gestures and events that occur within the designated regions, instead of those in the layout area. This may lead to no response to gestures and events in the layout-related area.

The **responseRegion** attribute accepts an array consisting of multiple **Rect** values.

### Controlling Gestures and Events via Hit Testing

The [hitTestBehavior](../reference/apis-arkui/arkui-ts/ts-universal-attributes-hit-test-behavior.md#hittestbehavior) attribute sets which components can respond to specific gestures and events. It is especially useful under complex multi-layer event scenarios.

<!-- @[hittestbehavior_first](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/CustomEvent.ets) -->

``` TypeScript
Column() {
  Column()
    .id('ComponentB')
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))

  Column() {
    Column()
      .id('ComponentD')
      .onTouch(() => {})
      .gesture(TapGesture({count: 1}))
  }
  .id('ComponentC')
  .onTouch(() => {})
  .gesture(TapGesture({count: 1}))
  .hitTestBehavior(HitTestMode.Block)
}
.id('ComponentA')
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
```

With **HitTestMode.Block**, the node responds to the hit test of a touch event, but its child node and sibling node are blocked from the hit test; as a result, neither the child node nor sibling node can receive the **onTouch** events and gestures.

When **hitTestBehavior** is not set for component C, tapping on the area of component D triggers the **onTouch** events of components A, C, and D, and also triggers the tap gesture of component D.

When **hitTestBehavior** is set to **HitTestMode.Block** for component C, tapping on the area of component D triggers the **onTouch** events of components A and C, but not the **onTouch** event of component D. In addition, because component D is blocked and its tap gesture cannot be triggered, the tap gesture of component C is triggered.

<!-- @[responseregion_second](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/CustomEvent.ets) -->

``` TypeScript
Stack() {
  Column()
    .id('ComponentB')
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))

  Column()
    .id('ComponentC')
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))
    .hitTestBehavior(HitTestMode.Transparent)
}
.id('Stack A')
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
```

With **HitTestMode.Transparent**, both the node and its child node respond to the hit test of a touch event, and its sibling node is also considered during the hit test.

If **hitTestBehavior** is not set for component C, when the overlapping area of component B and component C is touched, the **onTouch** events of Stack A and component C are triggered, the touch event of component C is triggered, and neither the **onTouch** event nor tap gesture of component B is triggered.

If **hitTestBehavior** is set to **HitTestMode.Transparent** for component C, when the overlapping area of components B and C is touched, the **onTouch** events of Stack A and component C are still triggered, and the touch event of component C is also triggered; yet, because component B can receive the touch event in this case, its **onTouch** event is triggered.

<!-- @[responseregion_thirdly](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/CustomEvent.ets) -->

``` TypeScript
Column() {
  Column()
    .id('ComponentB')
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))
}
.id('ComponentA')
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
.hitTestBehavior(HitTestMode.None)
```

**HitTestMode.None** does not respond to hit testing itself and does not block hit testing for child nodes or sibling nodes.

If **hitTestBehavior** is not set for component A, a touch in the target touch of component B triggers the **onTouch** events of components A and B, as well as the tap gesture of component B.

When **hitTestBehavior** is set to **HitTestMode.None** for component A, a touch in the target touch of component B triggers the **onTouch** event and tap gesture of component B, but not the **onTouch** event of component A.

<!-- @[responseregion_fourth](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/CustomEvent.ets) -->

``` TypeScript
Stack() {
  Column()
    .id('ComponentB')
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))
  Column() {
    Column()
      .id('ComponentD')
      .onTouch(() => {})
      .gesture(TapGesture({count: 1}))
  }
  .id('ComponentC')
  .onTouch(() => {})
  .gesture(TapGesture({count: 1}))
  .hitTestBehavior(HitTestMode.BLOCK_HIERARCHY)
}
.id('Stack A')
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
```

**HitTestMode.BLOCK_HIERARCHY** is available since API version 20. In this mode, the node itself and its child nodes respond to the hit test, while all parent nodes and sibling nodes with lower priority are blocked from participating in the hit test.

When component C does not have **hitTestBehavior** set, clicking the overlapping area of components B and D triggers the **onTouch** events of components A, C, and D, and also triggers the click gesture of component D.

When component C has **hitTestBehavior** set to **HitTestMode.BLOCK_HIERARCHY**, clicking the overlapping area of components B and D triggers the **onTouch** events of components C and D, while the **onTouch** events of components A and B are not triggered; the click gesture of component D is still triggered.

<!-- @[responseregion_fifth](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/CustomEvent.ets) -->

``` TypeScript
Stack() {
  Column()
    .id('ComponentB')
    .onTouch(() => {})
    .gesture(TapGesture({count: 1}))
  Column() {
    Column()
      .id('ComponentD')
      .onTouch(() => {})
      .gesture(TapGesture({count: 1}))
  }
  .id('ComponentC')
  .onTouch(() => {})
  .gesture(TapGesture({count: 1}))
  .hitTestBehavior(HitTestMode.BLOCK_DESCENDANTS)
}
.id('Stack A')
.onTouch(() => {})
.gesture(TapGesture({count: 1}))
```

[HitTestMode](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#hittestmode9).BLOCK_DESCENDANTS is available since API version 20. In this mode, the node itself does not respond to the hit test, and all its descendants (children, grandchildren, and more) also do not respond to the hit test. It does not affect the hit test of ancestor nodes.

If component C does not have [hitTestBehavior](../reference/apis-arkui/arkui-ts/ts-universal-attributes-hit-test-behavior.md#hittestbehavior) set, clicking the overlapping area of components B and D triggers the [onTouch](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md#ontouch) events of components A, C, and D, and also triggers the click gesture of component D.

When component C has [hitTestBehavior](../reference/apis-arkui/arkui-ts/ts-universal-attributes-hit-test-behavior.md#hittestbehavior) set to **HitTestMode.BLOCK_DESCENDANTS**, clicking the overlapping area of components B and D triggers the [onTouch](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md#ontouch) events of components A and B, while the **onTouch** events of components C and D are not triggered; the click gesture of component B is triggered instead.

Under simple scenarios, you are advised to set **hitTestBehavior** for each single component.

Under complex scenarios, you are advised to set different **hitTestBehavior** values to multiple components to control the dispatching of touch events.

### Calling Gesture Binding Methods

When binding a parent component and a child component to a same gesture, you can assign different response priorities to them by using different gesture binding methods.

When .[gesture](../reference/apis-arkui/arkui-ts/ts-gesture-settings.md#gesture) is used for gesture binding, the child component responds prior to the parent component.

<!-- @[bindingfirst_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/CustomEvent.ets) -->

``` TypeScript
Column() {
  Column()
    .id('ComponentB')
    .gesture(TapGesture({count: 1}))
}
.id('ComponentA')
.gesture(TapGesture({count: 1}))
```

When both a parent component and a child component have a tap gesture bound normally, the child component responds prior to the parent component.

In this case, when component B is touched, the tap gesture of component B is triggered, but that of component A is not.

To enable the parent component to respond prior to the child component, use the **.priorityGesture** method.

<!-- @[bindingsecond_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/CustomEvent.ets) -->

``` TypeScript
Column() {
  Column()
    .id('ComponentB')
    .gesture(TapGesture({count: 1}))
}
.id('ComponentA')
.priorityGesture(TapGesture({count: 1}))
```

When a parent component binds a gesture .[priorityGesture](../reference/apis-arkui/arkui-ts/ts-gesture-settings.md#prioritygesture), the gesture on the parent component takes precedence over gestures on its child components.

In this case, tapping within the area of component B triggers the tap gesture of component A, but not the tap gesture of component B.

To enable both the parent and child components to respond to a same gesture, use the **.parallelGesture** method in the parent component.

<!-- @[bindingthirdly_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/CustomEvent.ets) -->

``` TypeScript
Column() {
  Column()
    .id('ComponentB')
    .gesture(TapGesture({count: 1}))
}
.id('ComponentA')
.parallelGesture(TapGesture({count: 1}))
```

When a parent component binds a gesture using .[parallelGesture](../reference/apis-arkui/arkui-ts/ts-gesture-settings.md#parallelgesture), both the parent's and the child's gestures can be triggered.

In this case, tapping within the area of component B triggers the tap gestures of both component A and component B.

### Implementing Event Passthrough in OverlayManager

In the event mechanism of [OverlayManager](../reference/apis-arkui/arkts-apis-uicontext-overlaymanager.md), events are first delivered to components inside the [WrappedBuilder](../reference/apis-arkui/arkui-ts/ts-universal-wrapBuilder.md#wrappedbuilder) and are not propagated downward by default.

To enable the underlying page below the **OverlayManager** to detect events, you can use **hitTestBehavior(HitTestMode.Transparent)** to pass through events. Refer to the following pseudocode:

<!-- @[overlay_manager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/MultilevelGestureEvents/entry/src/main/ets/pages/OverlayManager.ets) -->

``` TypeScript
@Builder
function builderOverlay(params: Params) {
  Component1().hitTestBehavior(HitTestMode.Transparent)
}

// ···

  aboutToAppear(): void {
    // ···
    let componentContent = new ComponentContent(
      this.context, wrapBuilder<[Params]>(builderOverlay),
      new Params(uiContext, {x:0, y: 100})
    );
    this.overlayManager.addComponentContent(componentContent, 0);
  }
```