# ArkUI Animation/Interaction Event Development (ArkTS)


## What should I do if the onBlur and onFocus callbacks cannot be triggered? (API version 9)

**Symptom**

The **onBlur** and **onFocus** callbacks of the focus event cannot be triggered.

**Solution**

Check the trigger device. By default, the focus event (and the **onBlur** and **onFocus** callbacks) can be triggered only by the Tab button and arrow buttons on the connected keyboard. To enable the focus event to be triggered by a touch, add the **focusOnTouch** attribute for the target component.

**Reference**

[Focus Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md)


## How do I disable the scroll event of a \<Grid> nested in the \<Scroll>? (API version 9)

Implement nested scrolling of the containers, by using the **onScrollFrameBegin** event and the **scrollBy** method.

**Reference**

[Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#example-2).


## How do I enable a component to rotate continuously? (API version 9)

You can use [property animation](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md) to that effect.


## How do I scroll a list with the keyboard? (API version 9)

**Solution**

Use either of the following:

- Add **focusable(true)** to the list item to enable it to obtain focus.

- Nest a focusable component, for example, **\<Button>**, at the outer layer of each item.


## Why is the click event not triggered for the focused component upon the press of the Enter key after keyboard navigation? (API version 9)

By default, the built-in click event of the component and the custom **onClick** click event are bound to the space bar instead of the Enter key.


## How do I block event bubbling when a button is nested in multi-layer components? (API version 9)

You can bind the button to the **stopPropagation** parameter.


## How do I disable the page transition effect when the router or navigator is used for page transition? (API version 9)

1. Define the **pageTransition** method for the current and target pages, by following instructions in [Example](../reference/apis-arkui/arkui-ts/ts-page-transition-animation.md#example).

2. Set the **duration** parameter of both **PageTransitionEnter** and **PageTransitionExit** to **0**.


## How do I fix misidentification of the pan gesture where container nesting is involved? (API version 9)

The pan gesture requires a minimum 5 vp movement distance of a finger on the screen. You can set the **distance** parameter in **PanGesture** to **1** so that the pan gesture can be more easily recognized.

**Reference**

[PanGesture](../reference/apis-arkui/arkui-ts/ts-basic-gestures-pangesture.md)


## Can I use the fontFamily attribute to set different fonts? (API version 9)

No. Currently, only the default font, HarmonyOS Sans, is supported.


## How do I implement a text input box that shows a soft keyboard when touched and hides the soft keyboard when a button is touched? (API version 9)

Use **focusControl** for the **\<TextInput>** component to control its focus. The **\<TextInput>** component shows a soft keyboard when it gains focus and hides the soft keyboard when it loses focus.

**Example**

```
build() {
  Column() {
    TextInput()
    Button(`hide`)
      .key('button')
      .onClick(()=>{
        focusControl.requestFocus('button')
      })
  }
}
```


## How do I implement a button that only responds to the bound onClick event, but not the onTouch event bound to the button's parent component? (API version 9)

Bind the **onTouch** event to the **\<Button>** component and use **stopPropagation()** in the event to prevent the event from bubbling up to the parent component.

**Example**

```
build() {
  Row() {
    Button ("Click Me")
      .width(100)
      .width(100)
      .backgroundColor('#f00')
      .onClick(()=>{
        console.log("Button onClick")
      })
      .onTouch((e) => {
        console.log("Button onTouch")
        e.stopPropagation()
      })
  }
  .onTouch(() => {
    console.log("Row onTouch")
  })
}
```


## Why is the menu bound to a component not displayed when the component is right-clicked? (API version 9)

**Solution**

Currently, the menu is displayed when the bound component is clicked or long pressed.


## How do I prevent the \<TextInput> component from bringing up the default keyboard? (API version 9)

Set the **focusable** attribute of the **\<TextInput>** component to **false**. In this way, the component is not focusable and therefore will not bring up the keyboard.


## How do I implement the slide up and slide down effect for page transition? (API version 9)

 

 

**Solution**

You can use the **pageTransition** API to implement the page transition effect. Specifically, set the **slide** attribute in **PageTransitionEnter** and **PageTransitionExit** to **SlideEffect.Bottom**. In this way, the page slides in and out from the bottom.

**Example**

```
// Index.ets
@Entry
@Component
struct PageTransition1 {
  build() {
    Stack({alignContent: Alignment.Bottom}) {
      Navigator({ target: 'pages/Page1'}) {
        Image($r('app.media.ic_banner01')).width('100%').height(200) // Save the image in the media folder.
      }
    }.height('100%').width('100%')
  }
  pageTransition() {
    PageTransitionEnter({ duration: 500, curve: Curve.Linear }).slide(SlideEffect.Bottom)
    PageTransitionExit({ duration: 500, curve: Curve.Ease }).slide(SlideEffect.Bottom)
  }
}
```

```
// Page1.ets
@Entry
@Component
struct PageTransition2 {
  build() {
    Stack({alignContent: Alignment.Bottom}) {
      Navigator({ target: 'pages/Index'}) {
        Image($r('app.media.ic_banner02')).width('100%').height(200) // Save the image in the media folder.
      }
    }.height('100%').width('100%')
  }
  pageTransition() {
    PageTransitionEnter({ duration: 500, curve: Curve.Linear }).slide(SlideEffect.Bottom)
    PageTransitionExit({ duration: 500, curve: Curve.Ease }).slide(SlideEffect.Bottom)
  }
}
```

**Reference**

[Page Transition](../reference/apis-arkui/arkui-ts/ts-page-transition-animation.md)

## How do I configure custom components to slide in and out from the bottom? (API version 9)

**Symptom**

Custom components A and B need to deliver the following effects: When custom component A, displayed at the bottom of the screen by default, is touched, it is hidden, and custom component B slides in from the bottom; when custom component B is touched, it is hidden, and custom component A slides in from the bottom.  

**Solution**

You can use the **transition** attribute to create component transition animations. Set the **type** parameter to specify the component transition type, which can be component addition, component deletion, or both. Set the **translate** parameter to specify the translation of the component during transition. **NOTE**<br>The **transition** attribute must work with **animateTo**. The animation duration, curve, and delay follow the settings in **animateTo**.

**Example**

```
@Entry
@Component
struct ComponentTransition {
  @State flag: boolean = true;

  build() {
    Stack({alignContent: Alignment.Bottom}) {
        if (this.flag) {
          ComponentChild1({ flag: $flag })
            .transition({ type: TransitionType.Insert,translate: { x: 0, y: 200 } })
        }
        if (!this.flag) {
          ComponentChild2({ flag: $flag })
            .transition({ type: TransitionType.Insert, translate: { x: 0, y: 200 } })
        }
    }.height('100%').width('100%')
  }
}

@Component
struct ComponentChild1 {
  @Link flag: boolean

  build() {
    Column() {
      Image($r('app.media.ic_banner01'))
        .width('100%')
        .height(200)
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            this.flag = !this.flag;
          })
        })
    }
  }
}

@Component
struct ComponentChild2 {
  @Link flag: boolean

  build() {
    Column() {
      Image($r('app.media.ic_banner02'))
        .width('100%')
        .height(200)
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            this.flag = !this.flag;
          })
        })
    }
  }
}
```

**Reference**

[Enter/Exit Transition](../ui/arkts-enter-exit-transition.md)


## What should I do if the Files application does not respond to touches? (API version 10)

**Symptom**

When the Files application icon is touched and held for 200 ms to 500 ms, the application does not respond.

**Cause Analysis**

An error occurs with the drag gesture recognition logic. As a result, when the application icon is touched and held for a specific period of time, the gesture recognizer enters the pending state and stops responding.

**Solution**

Long press the Files application icon or a blank area.

## How do I customize event transfer between parent and child components? (API version 10)

**Solution**

1. When processing a touch event, the system conducts hit testing - from the parent component to its children - to determine the component that needs to respond to the event. Subsequent gesture recognition and competition are performed based on the test result.

2. You can set the **hitTestBehavior** attribute to specify how a component behaves during hit testing.

3. Intervention on gesture recognition and competition results may be refined with custom events and custom gesture judgment.

**Reference**

1. [Hit Test Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-hit-test-behavior.md)

2. [Custom Event Dispatch](../reference/apis-arkui/arkui-ts/ts-universal-attributes-on-child-touch-test.md)

3.[Custom Gesture Judgment](../reference/apis-arkui/arkui-ts/ts-gesture-customize-judge.md)

## How do I enable a list to automatically rearrange the layout after one of the list items is dragged? (API version 10)
 
**Solution**

1. Configure the list or list items to be draggable, and register the **onDragStart** callback.

2. Set **visibility** of the dragged item to **HIDDEN** in the **onDragStart** callback.

2. Register the **onDragMove** callback on the list or list item to listen for the movement during dragging.

3. During the dragging, use the **event** parameter of **onDragMove** to obtain the coordinates of the drag points.

4. Calculate the distance between the drag point coordinates and the item middle line. When the drag point and middle line overlap, enable the space filling animation.

5. Use the **componentUtils** API to obtain the item layout information.

6. The space filling animation uses **animateTo** to change the index in the data source and trigger the list sorting animation.

7. The drop animation can be customized.

 **Example**

```ts
// Record the dragged item when the dragging is started.
  .onDragStart((event?: DragEvent, extraParams?: string) => {
    this.dragIndex = Number(item.data)
    this.dragItem = item
  })
  // Execute the space filling animation when the dragged item enters a valid drop target.
  .onDragEnter((event?: DragEvent, extraParams?: string) => {
    if (Number(item.data) != this.dragIndex) {
      let current = this.dataSource.findIndex((element) => element.data === this.dragItem.data)
      let index = this.dataSource.findIndex((element) => element.data === item.data)
      animateTo({
        curve: curves.interpolatingSpring(0, 1, 400, 38)
      }, () => {
        this.dataSource.splice(current, 1)
        this.dataSource.splice(index, 0, this.dragItem)
      })
    }
  })
   // Implement a custom drop animation on the dragged item when it is dropped on a valid drop target.
  .onDrop((dragEvent: DragEvent) => {
    dragEvent.useCustomDropAnimation = true;
    // Obtain the drop target.
    let downLocation = getInspectorByKey(item.data)
    let currentLocation = dragEvent.getPreviewRect()
    this.dragItem.scale = 1.05
    animateTo({
      curve: curves.interpolatingSpring(14, 1, 170, 17)
    }, () => {
      this.dragItem.scale = 1
    })
  })
```
