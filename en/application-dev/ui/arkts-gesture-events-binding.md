# Gesture Binding


You can bind to each component different gesture events and design the logic for responding to these events. When a gesture is successfully recognized, the ArkUI framework notifies the component of the gesture recognition result through event callback.


## gesture (Common Gesture Binding Method)


```ts
.gesture(gesture: GestureType, mask?: GestureMask)
```

**gesture** is a frequently used API for binding a gesture to a component.

For example, you can use it to bind the tap gesture to the **Text** component.


```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      Text('Gesture').fontSize(28)
        // Use the gesture API to bind the tap gesture.
        .gesture(
          TapGesture()
            .onAction(() => {
              console.info('TapGesture is onAction');
            }))
    }
    .height(200)
    .width(250)
  }
}
```


## priorityGesture (Gesture Binding Method with Priority)


```ts
.priorityGesture(gesture: GestureType, mask?: GestureMask)
```

The **priorityGesture** API binds gestures that are preferentially recognized to a component.

By default, the child component preferentially recognizes the gesture specified by **gesture**, and the parent component preferentially recognizes the gesture specified by **priorityGesture** (if set).

With regard to long press gestures, the component with the shortest minimum hold-down time responds first, ignoring the **priorityGesture** settings.

In the following example, the parent component **Column** and child component **Text** are both bound to the tap gesture. As the **Column** is bound to the gesture through **priorityGesture**, the tap gesture recognized by the parent component is preferentially responded to.



```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      Text('Gesture').fontSize(28)
        .gesture(
          TapGesture()
            .onAction(() => {
              console.info('Text TapGesture is onAction');
            }))
    }
    .height(200)
    .width(250)
    // When the tap gesture is bound to the parent Column component with priorityGesture, any tap gesture events from the Text component are ignored. This means that when the text area is tapped, the Column component's tap gesture event is given priority and responded to first.
    .priorityGesture(
      TapGesture()
        .onAction(() => {
          console.info('Column TapGesture is onAction');
        }), GestureMask.IgnoreInternal)
  }
}
```


## parallelGesture (Parallel Gesture Binding Method)


```ts
.parallelGesture(gesture: GestureType, mask?: GestureMask)
```

The **parallelGesture** API binds to a component the gesture that can be triggered together with the child component gesture.

By default, the gesture event does not bubble up. When a parent component and a child component are bound to a same gesture, the gesture events bound to the parent component and the child component compete with each other, and a gesture event of at most one component can be responded to. When **parallelGesture** is set, the same gesture events can be triggered for the parent and child components, thereby implementing a bubbling effect.



```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      Text('Gesture').fontSize(28)
        .gesture(
          TapGesture()
            .onAction(() => {
              console.info('Text TapGesture is onAction');
            }))
    }
    .height(200)
    .width(250)
    // When parallelGesture is set, the tap gestures on the Column component and on the child Text component are both recognized.
    .parallelGesture(
      TapGesture()
        .onAction(() => {
          console.info('Column TapGesture is onAction');
        }), GestureMask.Normal)
  }
}
```
