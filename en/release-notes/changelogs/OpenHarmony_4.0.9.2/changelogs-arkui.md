# ArkUI Subsystem Changelog

## cl.arkui.1 Change of the ScrollState Enum Rules

The table lists the rules for the **ScrollState** enums in API version 9 and earlier versions:

| Name    | Description                            |
| ------ | ------------------------------ |
| Idle   | Idle. The list enters this state when an API in the controller is used to scroll the list or when the scrollbar is dragged. |
| Scroll | Scrolling. The list enters this state when the user drags the list to scroll.       |
| Fling  | Inertial scrolling. The list enters this state when inertial scrolling occurs or when the list bounces back after being released from a fling.|

The table lists the rules for the **ScrollState** enums in API version 10 and later versions:

| Name    | Description                            |
| ------ | ------------------------------ |
| Idle   | Idle. The list enters this state when it is not scrolling or an API in the controller that does not apply an animation is called. |
| Scroll | Scrolling. The list enters this state when the user drags the list, scrollbar, or mouse wheel to scroll the list.       |
| Fling  | Inertial scrolling. The list enters this state when: inertial scrolling occurs after a fling; the list bounces back after being released from a fling; inertial scrolling occurs after quick dragging of the built-in scrollbar; scrolling occurs after an API in the controller that applies an animation is called.|

The table below lists the changes in the **ScrollState** enums.

| Scenario    | API Version 9 and Earlier                        |API Version 10 and Later                          |
| ------ | ------------------------------ |------------------------------ |
| Finger dragging  | Scroll | Scroll |
| Inertial scrolling  | Fling | Fling |
| Cross-boundary bouncing  | Fling | Fling |
| Scrolling by mouse wheel  | Idle | Scroll |
| Scrollbar dragging  | Idle | Scroll |
| Scrolling by the scrolling controller (with animation)  | Idle | Fling |
| Scrolling by the scrolling controller (without animation)  | Idle | Idle |

**Change Impact**

1. **ScrollState** is available since API version 7. The change is introduced in API version 10 and does not affect the use in API version 9 and earlier versions.
2. Since API version 10, the use of **ScrollState** is affected in the **onScroll** event of the **\<List>** component.

**Key API/Component Changes**


- [List Events](../../../application-dev/reference/arkui-ts/ts-container-list.md#events)
- [ScrollState](../../../application-dev/reference/arkui-ts/ts-container-list.md#scrollstate)

**Adaptation Guide**

When the **\<List>** component is bound to the **onScroll** event and reports the scrolling status through the event, it must comply with the new rules since API version 10.

The code snippet is as follows:
```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }
        }, item => item)
      }
      .listDirection(Axis.Vertical) // Arrangement direction
      .edgeEffect(EdgeEffect.Spring) // Set the edge scrolling effect to Spring.
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {
        console.log(`onScroll scrollState = ${ScrollState[scrollState]}, scrollOffset = ${[scrollOffset]}`)
      })
      .width('90%')
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xDCDCDC)
    .padding({ top: 5 })
  }
}
```

## cl.arkui.2 Change of Use Case Restrictions of ArkUI Built-in Components

Restricted the use of ArkUI built-in components to the build methods of structs, **pageTransition** method, or @Builder decorated functions.

**Example**

```
@Entry
@Component
struct Index {
  build() {
    Row() {
    }

  }
}
// ERROR:UI component 'Text' cannot be used in this place.
Text('Hello World')
```

**Change Impact**

 A build error will occur if a built-in component is not used in a build method of a struct, **pageTransition** method, or any @Builder decorated function.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Use ArkUI built-in components only in build methods of structs, **pageTransition** methods, and @Builder decorated functions.

## cl.arkui.3 \<RowSplit> and \<ColumnSplit> Component Layout and Behavior Changes

1. Changed the default size of the **\<RowSplit>** or **\<ColumnSplit>** component on the cross axis from adapting to the parent component size to adapting to the child component size. 

2. Changed how the child components behave when the**\<RowSplit>** or **\<ColumnSplit>** component's divider is dragged:

  - Before the change, the child components are translated without being compressed or stretched.

  - After the change, the child components are compressed and stretched. 

3. Changed the clipping area of child components for when the **clip** attribute is used to clip the child component content that exceeds the component area: 
    
    - For **\<RowSplit>**, the clipping area is changed from the right side to both the left and right sides of the child component area.
    
    - For **\<ColumnSplit>**, the clipping area is changed from the bottom to both the top and bottom of the child component area.

**Change Impact** 
The preceding changes affect the **\<RowSplit>** and **\<ColumnSplit>** components in API version 10 and later versions.

**Key API/Component Changes**

N/A

## cl.arkui.4 Changes in Layout and Behavior of \<Search>, \<TextInput>, and \<TextArea> Components

1. Changed the position of the edited text area in the **\<Search>**, **\<TextInput>**, and \**<TextArea>** components from moving by the distance specified by **padding** to moving by the distance specified by **padding** and **border**. 
2. Changed the width of the text field in the **\<Search>** component from the component width minus the width and the left and right margins of the search icon, to the component width minus the width of the paddings and borders as well as the width and the left and right margins of the search icon.

**Change Impact**

The change affects only applications of API version 10 and later versions.

**Key API/Component Changes**

N/A

**Adaptation Guide**

N/A
