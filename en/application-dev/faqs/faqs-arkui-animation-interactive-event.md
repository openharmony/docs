# ArkUI Animation/Interaction Event Development (ArkTS)

## What should I do if the onBlur and onFocus callbacks cannot be triggered?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

The **onBlur** and **onFocus** callbacks of the focus event cannot be triggered.

**Solution**

Check the trigger device. By default, the focus event (and the **onBlur** and **onFocus** callbacks) can be triggered only by the Tab button and arrow buttons on the connected keyboard. To enable the focus event to be triggered by a touch, add the **focusOnTouch** attribute for the target component.

**Reference**

[Focus Control](../reference/arkui-ts/ts-universal-attributes-focus.md)

## How do I disable the scroll event of a \<Grid> nested in the \<Scroll>?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

Implement nested scrolling of the containers, by using the **onScrollFrameBegin** event and the **scrollBy** method.

**Reference**

[Scroll](../reference/arkui-ts/ts-container-scroll.md#example-2)

## How do I enable a component to rotate continuously?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

You can use [attribute animation](../reference/arkui-ts/ts-animatorproperty.md) to that effect.

## How do I scroll a list with the keyboard?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution** 

- Add **focusable\(true\)** to the list item to enable it to obtain focus.

- Nest a focusable component, for example, **\<Button>**, at the outer layer of each item.

## Why is the click event not triggered for the focused component upon the press of the Enter key after keyboard navigation?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

By default, the built-in click event of the component and the custom **onClick** click event are bound to the space bar instead of the Enter key.

## How do I block event bubbling when a button is nested in multi-layer components?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

You can bind the button to the **stopPropagation** parameter.

## How do I disable the transition effect between pages when the router or navigator is used to switch between pages?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

1.  Define the **pageTransition** method for the current and target pages, by following instructions in [Example](../reference/arkui-ts/ts-page-transition-animation.md#example).
2.  Set the **duration** parameter of both **PageTransitionEnter** and **PageTransitionExit** to **0**.

## How do I fix misidentification of the pan gesture where container nesting is involved?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

The pan gesture requires a minimum 5 vp movement distance of a finger on the screen. You can set the **distance** parameter in **PanGesture** to **1** so that the pan gesture can be more easily recognized.

**Reference**

[PanGesture](../reference/arkui-ts/ts-basic-gestures-pangesture.md)

## Can I use the fontFamily attribute to set different fonts for OpenHarmony applications?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

No. For applications developed based on OpenHarmony, only the default font, HarmonyOS Sans, is supported.

## How do I implement a text input box that shows a soft keyboard when touched and hides the soft keyboard when a button is touched?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

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

## How do I implement a button that only responds to the bound onClick event, but not the onTouch event bound to the button's parent component?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

Bind **onTouch** to the **\<Button>** component and use **stopPropagation\(\)** in **onTouch** to prevent **onTouch** from bubbling up to the parent component.

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

## Why is the menu bound to a component not displayed by a right-click on the component?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Solution**

Currently, the menu is displayed when the bound component is clicked or long pressed.

## How do I shield the default keyboard popup behavior of the \<TextInput> component?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

Set the **focusable** attribute of the **\<TextInput>** component to **false**. In this way, the component is not focusable and therefore will not bring up the keyboard.

## How do I implement the slide up and slide down effect for page transition?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

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

[Page Transition Animation](../ui/arkts-page-transition-animation.md)

## How do I configure custom components to slide in and out from the bottom?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Symptom**

Custom components A and B need to deliver the following effects: When custom component A, displayed at the bottom of the screen by default, is touched, it is hidden, and custom component B slides in from the bottom. When custom component B is touched, it is hidden, and custom component A slides in from the bottom.

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

[Transition Animation Within the Component](../ui/arkts-transition-animation-within-component.md)
