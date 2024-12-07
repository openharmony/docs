# Multi-level Gesture Events

Multi-level gesture events occur when both parent and child components receive a gesture or event bound to them. Handling such events can be tricky: The gesture and event detection is affected by a plurality of factors, with much transmission and competition involved, and an unexpected response easily occurs.

This topic describes the default response sequence of multi-level gesture events and how to set related attributes to affect the response sequence of multi-level gesture events.

## Default Multi-level Gesture Events

### Touch Event

The touch event (**onTouch**) is the foundation of all gestures. It comes in four types: Down, Move, Up, and Cancel. A gesture is a sequence of touch events. For example, tap gestures include Down and Up events, and swipe gestures include Down, Move, and Up events. Touch events have the most particularity:

1. If a component that has the **onTouch** listener added is touched, it receives the callback of the **onTouch** event. Detection of a touch is subject to the touch target and touch control.

2. The callback of the **onTouch** event is in a closed-loop manner. If a component receives a Down event whose finger ID is 0, it will also receive a Move event and an Up event whose finger ID is 0.

3. The callback of the **onTouch** event follows consistency. If a component receives the Down event whose finger ID is 0 but does not receive the Down event whose finger ID is 1, it will receive other touch events whose finger ID is 0, but not touch events whose finger ID is 1.

For common container components (such as **Column**), **onTouch** events can be received by parent and child components at the same time, and how they are received by sibling components is subject to the layout.

```ts
ComponentA() {
    ComponentB().onTouch(() => {})
    ComponentC().onTouch(() => {})
}.onTouch(() => {})
```
If components B and C are children of component A, then touching component B or component C also touches component A. The **onTouch** callback can be invoked by multiple components at the same time.
Therefore, when component B is touched, the **onTouch** callback is invoked by both component A and component B, but not by component C; when component C is touched, the **onTouch** callback is invoked by both component A and component C, but not by component B.

For special container components, such as **Stack**, **onTouch** events can be received by parent and child components at the same time, but how they are received by child components depends on the stacking relationship.


```ts
Stack A() {
    ComponentB().onTouch(() => {})
    ComponentC().onTouch(() => {})
}.onTouch(() => {})
```
Assume that components B and C are children of Stack A, and component C is stacked on component B. Then touching component B or component C also touches Stack A. The **onTouch** callback can be invoked by multiple components at the same time. Therefore, when the overlapping area of components B and C is touched, the **onTouch** callback is invoked by both Stack A and component C, but not by component B (which is stacked by component C).

### Gestures and Events

All gestures and events except the touch event (**onTouch**) are implemented using basic or combined gestures. For example, the drag event is a sequence of a long press gesture and a swipe gesture.

If no explicit declaration is made, only one gesture in a gesture group can be recognized for a single finger at the same time, which means that only one set callback can be invoked.

Therefore, unless it is explicitly declared that multiple gestures can be recognized at the same time, only one gesture is handled at once.

The response to gestures complies with the following rules:

1. When the parent and child components are bound to the same type of gesture, the child component responds prior to the parent component.

2. When a component is bound to multiple gestures, the gesture that first meets triggering conditions is preferentially triggered.

```ts
ComponentA() {
    ComponentB().gesture(TapGesture({count: 1}))
}.gesture(TapGesture({count: 1}))    
```
When both the parent and child components are bound to a tap gesture, the child component responds prior to the parent component.
Therefore, when the user touches component B, the callback of **TapGesture** bound to component B is invoked, but the callback bound to component A is not.

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
If the tap gesture and the swipe gesture are bound to a component in exclusive recognition mode, the gesture that first meets triggering conditions is preferentially triggered.
If the user performs a tap operation, the callback corresponding to the tap is invoked. If the user performs a swipe operation and the swipe distance reaches the threshold, the callback corresponding to the swipe is invoked.

## Handling Multi-level Gesture Events with Custom Logic

You can set attributes to control the multi-level gesture event competition process.

Specifically, use the **responseRegion** and **hitTestBehavior** attributes to control dispatching of touch events, thereby affecting the response to the **onTouch** events and gestures. You can also call gesture binding methods to control gesture competition and affect gesture response, but this approach does not affect triggering of **onTouch** events.

### Using responseRegion

The **responseRegion** attribute sets the touch target of a component, which can be larger or smaller than the layout scope of the component.

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
In the preceding example, **.responseRegion({Rect4})** is set for component A, and as such, all touch events and gestures that fall within the Rect4 region can be received by the callback corresponding to component A.

Similarly, with **.responseRegion({Rect1, Rect2, Rect3})** set for component B, all touch events and gestures that fall within the Rect1, Rect2, and Rect3 regions can be received by the callback corresponding to component B.

When **responseRegion** is set for a component, the component responds to all gestures and events that occur within the designated regions, instead of those in the layout area. This may lead to no response to gestures and events in the layout-related area.

The **responseRegion** attribute accepts an array consisting of multiple **Rect** values.

### Using hitTestBehavior

The **hitTestBehavior** attribute sets which components can respond to specific gestures and events. It is especially useful under complex multi-level event scenarios.

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
With **HitTestMode.Block**, the node responds to the hit test of a touch event, but its child node and sibling node are blocked from the hit test; as a result, neither the child node nor sibling node can receive the **onTouch** events and gestures.
    
When **hitTestBehavior** is not set for component C, a touch in the target touch of component D triggers the **onTouch** events of components A, C, and D, as well as the tap gesture of component D.

When **hitTestBehavior** is set to **HitTestMode.Block** for component C, a touch in the target touch of component D triggers the **onTouch** events of components A and C, but not the **onTouch** event of component D. In addition, because component D is blocked and its tap gesture of the component D cannot be triggered, the tap gesture of component C is triggered.

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
With **HitTestMode.Transparent**, both the node and its child node respond to the hit test of a touch event, and its sibling node is also considered during the hit test.

If **hitTestBehavior** is not set for component C, when the overlapping area of component B and component C is touched, the **onTouch** events of Stack A and component C are triggered, the touch event of component C is triggered, and neither the **onTouch** event nor tap gesture of component B is triggered.

If **hitTestBehavior** is set to **HitTestMode.Transparent** for component C, when the overlapping area of components B and C is touched, the **onTouch** events of Stack A and component C are still triggered, and the touch event of component C is also triggered; yet, because component B can receive the touch event in this case, its **onTouch** event and tap gesture are triggered.

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
With **HitTestMode.None**, the node does not respond to the hit test of a touch event, but its child node and sibling node are considered during the hit test.

If **hitTestBehavior** is not set for component A, a touch in the target touch of component B triggers the **onTouch** events of components A and B, as well as the tap gesture of component B.

When **hitTestBehavior** is set to **HitTestMode.None** for component A, a touch in the target touch of component B triggers the **onTouch** event and tap gesture of component B, but not the **onTouch** event of component A.

Under simple scenarios, you are advised to set **hitTestBehavior** for each single component.
Under complex scenarios, you are advised to set different **hitTestBehavior** values to multiple components to control the dispatching of touch events.

### Calling Gesture Binding Methods
When binding a parent component and a child component to a same gesture, you can assign different response priorities to them by using different gesture binding methods.

When **.gesture** is used for gesture binding, the child component responds prior to the parent component.

```ts
ComponentA() {
    ComponentB()
    .gesture(TapGesture({count: 1}))
}
.gesture(TapGesture({count: 1}))
```
In the preceding example, both the parent and child components are bound to the tap gesture, and the child component responds prior to the parent component.
In this case, when component B is touched, the tap gesture of component B is triggered, but that of component A is not.

To enable the parent component to respond prior to the child component, use the **.priorityGesture** method.

```ts
ComponentA() {
    ComponentB()
    .gesture(TapGesture({count: 1}))
}
.priorityGesture(TapGesture({count: 1}))
```
In the preceding example, the **.priorityGesture** method is used to bind the parent component to the tap gesture, and the parent component responds prior to the child component.
In this case, when component B is touched, the tap gesture of component A is triggered, but that of component B is not.

To enable both the parent and child components to respond to a same gesture, use the **.parallelGesture** method in the parent component.

```ts
ComponentA() {
    ComponentB()
    .gesture(TapGesture({count: 1}))
}
.parallelGesture(TapGesture({count: 1}))
```
In the preceding example, the **.parallelGesture** method is used to bind the parent component to the tap gesture, and both the parent and child components can respond to the bound gesture.
In this case, when component B is touched, both the tap gestures of components A and B are triggered.
