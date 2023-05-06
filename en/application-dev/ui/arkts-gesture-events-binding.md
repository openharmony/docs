# Gesture Binding


Different gesture events are bound to each component and the event response mode is designed. When gesture recognition is successful, the ArkUI framework notifies the component of the gesture recognition result through event callback.


## gesture (Common Gesture Binding Method)


```ts
.gesture(gesture: GestureType, mask?: GestureMask)
```

Binds a gesture to the specified component. **gesture** is a general gesture binding method.

For example, the tap gesture TapGesture can be bound to the **\<Text>** component by using the **gesture** method.


```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      Text('Gesture').fontSize(28)
        // Use the gesture method to bind the TapGesture.
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

Binds gestures that are preferentially recognized to a component.

By default, when a parent component and a child component use gesture to bind gestures of the same type, the child component preferentially identifies gestures bound by using gesture. When the parent component uses priorityGesture to bind gestures of the same type as the child component, the parent component preferentially identifies gestures bound through priorityGesture.

For example, when the parent component Column and child component Text are bound to the TapGesture gesture at the same time, and the parent component is bound in the form of a priority gesture priorityGesture, the TapGesture bound to the parent component is preferentially responded.



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
    // When this parameter is set to priorityGesture, the TapGesture gesture event of the Text component is ignored when the text area is tapped, and the TapGesture gesture event of the parent component Column is preferentially responded.
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

Binds the same gesture that can be responded to at the same time to the parent and child components.

By default, the gesture event does not bubble up. When a parent component and a child component are bound to a same gesture, the gesture events bound to the parent component and the child component compete with each other, and a gesture event of at most one component can be responded to. When the parent component is bound to parallel gesture parallelGesture, the same gesture events of the parent and child components can be triggered to implement a bubbling effect.



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
    // If this parameter is set to parallelGesture, the TapGesture gesture events of the parent component Column and child component Text are responded when the text area is clicked.
    .parallelGesture(
      TapGesture()
        .onAction(() => {
          console.info('Column TapGesture is onAction');
        }), GestureMask.IgnoreInternal)
  }
}
```


>**NOTE**
>
>When the parent component and the child component are bound to both the click gesture event and the double-click gesture event, both the parent component and the child component respond only to the click gesture event.
