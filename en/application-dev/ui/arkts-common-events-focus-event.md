# Focus Events

## Basic Concepts and Standards

### Basic Concepts

**Focus, Focus Chain, and Focusing**

- Focus: Refers to the unique interactive element in the current window. When users interact indirectly with the application using non-pointing input devices such as keyboards, TV remote controls, or in-car knobs/dials, focus-based navigation and interaction are essential means of input.
- Focus chain: In the application's component tree structure, when a component gains focus, all nodes on the entire path from the root node to that component node are considered to be in focus, forming a continuous focus chain.
- Focusing: Refers to the behavior of the focus transferring between components within the application. This process is transparent to the user, but developers can capture these changes by listening to the onFocus (focus acquisition) and onBlur (focus loss) events. For specific methods and rules of focusing, see [Rules of Focus Navigation](#rules of focus navigation).

**Focus State**

Used to indicate the style of the currently focused component.

- Display Rules: By default, the focus state does not display. It only appears after the application enters the active state. Therefore, although a component that has gained focus may not necessarily display the focus state (depending on whether it is in the active state), a component that displays the focus state must have gained focus. Most components come with built-in focus state styles, and developers can also customize them using style interfaces. Once customized, the component will no longer display the built-in focus state styles. In the focus chain, if multiple components have the focus state at the same time, the system will adopt a strategy that prioritizes the child component, displaying the focus state of the child component and only one focus state.
- Entering the Active State: The focus's active state is only entered when the TAB key is pressed using an external keyboard. After entering the active state, you can use the keyboard TAB key/arrow keys to defocus. The first TAB key used to activate the focus state does not trigger focusing.
- Exiting the Active State: When the application receives a click event (including finger touch press events and mouse left button press events), the focus's active state will exit.

**Hierarchical Pages**

Hierarchical pages are general terms for specific container components in the focus framework, including Page, Dialog, SheetPage, ModalPage, Menu, Popup, NavBar, NavDestination, etc. These components usually have the following key characteristics:

- Visual Hierarchy Independence: From a visual presentation perspective, these components are independent of other page content and are usually positioned above it, creating a visual hierarchy difference.
- Focus Acquisition: After these components are created and displayed for the first time, they immediately seize the focus within the application.
- Focusing Range Limitation: When the focus is inside these components, users cannot transfer the focus to other elements outside the component using keyboard keys, and the focus movement is limited within the component.

In an application, there is always at least one hierarchical page component at any time, and this component holds the current focus. When this hierarchical page is closed or no longer visible, the focus will automatically transfer to the next available hierarchical page component, ensuring the coherence and consistency of user interaction.

> **NOTE**
>
> The Popup component does not have the second characteristic when the focusable attribute (component attribute, not a universal attribute) is false.
>
> NavBar and NavDestination do not have the third characteristic; for their focusing range, it is the same as their first parent hierarchical page.

**Root Container**

The root container is a concept within hierarchical pages. When a hierarchical page is created and displayed for the first time, according to the characteristics of the hierarchical page, the focus is immediately seized by the page. At this time, the end node of the focus chain where the hierarchical page is located will become the default focus, and this default focus is usually located on the root container of the hierarchical page.

By default, the default focus of the hierarchical page is on its root container, but developers can customize this behavior through the defaultFocus attribute.

When the focus is on the root container, the first press of the TAB key not only activates the focus state but also triggers the transfer of focus to the child components. If the child component itself is also a container, the focus will continue to be passed down until it reaches the leaf node. The transfer rules are: first, pass to the child node that last gained focus; if there is no such node, it is passed by default to the first child node.

### Rules of Focus Navigation

Based on the trigger method of focusing, it can be divided into active focusing and passive focusing.

**Active Focusing**

Refers to the focus movement caused by the subjective actions of developers/users, including: using keyboard key focusing (TAB key/Shift+TAB key/arrow keys), using requestFocus to apply for focus, clearFocus to clear focus, focusOnTouch click to apply for focus, and other interfaces that cause focus transfer.

- Key Focusing
1. Prerequisite: The current application needs to be in the focus activation state.
2. Range Limitation: Key focusing only occurs within the current focused hierarchical page, see the "Focusing Range Limitation" section in "Hierarchical Pages."
3. Key Types:
   TAB key: Follows a Z-shaped traversal logic to complete the traversal of all leaf nodes within the current range. After reaching the last component within the current range, continue pressing the TAB key, and the focus will cycle back to the first focusable component within the range, achieving circular focusing.
    Shift+TAB key: Has the opposite focus transfer effect of the TAB key.
    Direction keys (up, down, left, right): Follow a cross-shaped movement strategy. In a single-layer container, the focus transfer is determined by the specific focusing algorithm of the container. If the algorithm determines that the next focus should fall on a certain container component, the system will further determine the target child node inside the container using the center point distance priority algorithm.
4. Focusing Algorithm: Each focusable container component has its specific focusing algorithm, which defines the rules for focus transfer.
5. Child Component Priority: When the child component handles key focusing events, the parent component will no longer be involved.

- requestFocus
See [requestFocus](#active-focus-acquisitionloss-of-focus), which can actively transfer focus to a specified component.
Cannot cross windows, cannot apply for focus across ArkUI instances, can apply for focus across hierarchical pages.

- clearFocus
See [clearFocus](#active-focus-acquisitionloss-of-focus), which clears the focus in the current hierarchical page, and the final focus rests on the root container.

- focusOnTouch
See [focusOnTouch](#setting-whether-a-component-is-focusable), which gives the bound component the ability to gain focus after a click. If the component itself cannot gain focus, this function is ineffective. If the bound is a container component, after clicking, the focus is first transferred to the last focused child component, otherwise, it is transferred to the first focusable child component.

**Passive Focusing**

Passive focusing refers to the automatic transfer of component focus due to the system or other operations, without the need for direct intervention by developers. This is the default behavior of the focus system.

Currently, there are mechanisms that will passively defocus:

- Component Deletion: When a component in focus is deleted, the focus framework first tries to transfer the focus to adjacent sibling components, following a back-to-front order. If all sibling components are not focusable, the focus will be released and notify its parent component for focus processing.
- Attribute Change: If the focusable or enabled attribute of a component in focus is set to false, or the visibility attribute is set to invisible, the system will automatically transfer the focus to other focusable components, with the same transfer method as in 1.
- Hierarchical Page Switching: When a hierarchical page switch occurs, such as jumping from one page to another, the focus of the current page will be automatically released, and the new page may automatically gain focus according to preset logic.
- Web Component Initialization: For Web components, when they are created, if they are designed to immediately gain focus (such as some pop-ups or input boxes), it may trigger the focus transfer to that Web component. Its behavior belongs to the component's own behavior logic and is not within the scope of the focus framework specifications.

### Focusing Algorithms

In the focus management system, each focusable container is equipped with a specific focusing algorithm, which defines how the focus is transferred from the currently focused child component to the next focusable child component when using the TAB key, Shift+TAB key, or arrow keys.

The focusing algorithm used by the container depends on its UX (user experience) specifications and is adapted by the container component. Currently, the focus framework supports three focusing algorithms: linear focusing, projection focusing, and custom focusing.

**Linear Focusing Algorithm**

The linear focusing algorithm is the default focusing strategy. It is based on the mounting order of child nodes in the node tree for focusing and is commonly used for containers with single-direction layouts, such as Row, Column, and Flex containers. The operating rules are as follows:

- Order dependency: The focusing order is entirely based on the mounting order of child nodes in the node tree, regardless of their actual layout positions on the interface.
- TAB Key focusing: Traverses all leaf nodes in the current range based on the Z-shaped traversal logic. After the last component in the current range is reached, press the TAB key. The focus loops to the first component that can be focused in the range.
- Arrow key focus: When you use an arrow key that is perpendicular to the direction defined by the container, the container does not accept the focus request in this direction. For example, in a horizontal Row container, you cannot use arrow keys to move up and down.
- Boundary processing: When the focus is on the first and last subnodes of the container, the container rejects the focus request of the arrow keys that are opposite to the current focus direction. For example, when the focus is on the first child node of a horizontal Row container, the container cannot process the focus request of the left arrow key.

**Projection Focusing Algorithm**

The projection focusing algorithm is based on the projection of the currently focused component in the focusing direction, combined with the overlapping area of the subcomponents with the projection and the distance from the center point for the winning determination. This algorithm is particularly suitable for containers with subcomponents of varying sizes and is currently only available for Flex components configured with the wrap attribute. The operating rules are as follows:

- When focusing with the direction keys, determine the overlapping area between the projection and the subcomponent area. Among all subcomponents with a non-zero area, calculate their straight-line distance from the center point of the currently focused component. The one with the shortest distance wins; if there are multiple candidates, the one further up in the node tree wins. If no subcomponents overlap with the projection, it indicates that the container cannot handle the focusing request for that direction key.

- When focusing with the TAB key, first use Specification 1 and determine according to the direction key to the right. If found, exit successfully. If not found, simulate moving the position of the currently focused subcomponent down by the height of the subcomponent, and then determine according to the direction key to the left. The subcomponent with the projection overlap and the farthest straight-line distance from the center point wins. If there is no subcomponent with overlapping projection, it means that the container cannot handle this TAB key focusing request.

- When focusing with the Shift+TAB key, first use Specification 1 and determine according to the direction key to the left. If found, exit successfully. If not found, simulate moving the position of the currently focused subcomponent up by the height of the subcomponent, and then determine according to the direction key to the right. The subcomponent with the projection overlap and the farthest straight-line distance from the center point wins. If there is no subcomponent with overlapping projection, it means that the container cannot handle this Shift+TAB key focusing request.

**Custom Focusing Algorithm**

The custom focusing algorithm is defined by the component itself, with specifications determined by the component.

## Focus Interface Usage

### Focus Event

```ts
onFocus(event: () => void)
```


Triggered when the bound component obtains focus.

```ts
onBlur(event:() => void)
```

Triggered when the bound component loses focus.

The **onFocus** and **onBlur** APIs are usually used in pairs to listen for the focus changes of the component.

```ts
// xxx.ets
@Entry
@Component
struct FocusEventExample {
  @State oneButtonColor: Color = Color.Gray;
  @State twoButtonColor: Color = Color.Gray;
  @State threeButtonColor: Color = Color.Gray;

  build() {
    Column({ space: 20 }) {
      // You can use the up and down arrow keys on an external keyboard to move the focus between the three buttons. When a button gains focus, its color changes. When it loses focus, its color changes back.
      Button('First Button')
        .width(260)
        .height(70)
        .backgroundColor(this.oneButtonColor)
        .fontColor(Color.Black)
          // Listen for the focus obtaining event of the first component and change its color when it obtains focus.
        .onFocus(() => {
          this.oneButtonColor = Color.Green;
        })
          // Listen for the focus loss event of the first component and change its color when it loses focus.
        .onBlur(() => {
          this.oneButtonColor = Color.Gray;
        })

      Button('Second Button')
        .width(260)
        .height(70)
        .backgroundColor(this.twoButtonColor)
        .fontColor(Color.Black)
          // Listen for the focus obtaining event of the second component and change its color when it obtains focus.
        .onFocus(() => {
          this.twoButtonColor = Color.Green;
        })
          // Listen for the focus loss event of the second component and change its color when it loses focus.
        .onBlur(() => {
          this.twoButtonColor = Color.Grey;
        })

      Button('Third Button')
        .width(260)
        .height(70)
        .backgroundColor(this.threeButtonColor)
        .fontColor(Color.Black)
          // Listen for the focus obtaining event of the third component and change its color when it obtains focus.
        .onFocus(() => {
          this.threeButtonColor = Color.Green;
        })
          // Listen for the focus loss event of the third component and change its color when it loses focus.
        .onBlur(() => {
          this.threeButtonColor = Color.Gray ;
        })
    }.width('100%').margin({ top: 20 })
  }
}
```


![en-us_image_0000001511740584](figures/en-us_image_0000001511740584.gif)


The preceding example includes four steps:

- Open the app and press the Tab key to activate the focus. The first button is displayed in the focus state. There is a blue closed box outside the component. The onFocus callback responds, and the background color turns green.
- When the Tab key (or the down arrow key) is pressed, the **Second Button** component is focused, its **onFocus** callback is triggered, and its background color turns green. **First Button** loses focus, its **onBlur** callback is triggered, and its background color turns gray.
- When the Tab key (or the down arrow key) is pressed, the **Third Button** component is focused, its **onFocus** callback is triggered, and its background color turns green. **Second Button** loses focus, its **onBlur** callback is triggered, and its background color turns gray.

### Setting Whether a Component Is Focusable

```ts
focusable(value: boolean)
```

Setting Whether a Component Is Focusable

Components can be classified into the following types based on their focusability:

- Components that are focusable by default: These components are usually interactive components, such as **\<Button>**, **\<Checkbox>**, and **\<TextInput>**.

- Components that can be focused but are unfocusable by default: Typical examples are **\<Text>** and **\<Image>**. To enable them to be focusable, use the **focusable(true)** attribute.

- Components that cannot be focused: These components usually do not allow for interactions and cannot be focused even if they use the **focusable** attribute. Examples are **\<Blank>** and **\<Circle>**.




```ts
enabled(value: boolean)
```

Sets whether the component responds to user interactions. If this parameter is set to false, the component does not have the interaction capability and cannot be focused.


```ts
focusOnTouch(value: boolean)
```

Whether the component is focusable on touch.




>**NOTE**
>
>- When a component is in the focused state, if its **focusable** or **enabled** attribute is set to **false**, the component automatically loses focus. Then, the focus moves to other components based on the [rules of focus navigation](#rules-of-focus-navigation).


```ts
// xxx.ets
@Entry
@Component
struct FocusableExample {
  @State textFocusable: boolean = true;
  @State textEnabled: boolean = true;
  @State color1: Color = Color.Yellow;
  @State color2: Color = Color.Yellow;
  @State color3: Color = Color.Yellow;

  build() {
    Column({ space: 5 }) {
      Text('Default Text')    // The focusable attribute is not set for the first <Text> component. By default, the component is unfocusable.
        .borderColor(this.color1)
        .borderWidth(2)
        .width(300)
        .height(70)
        .onFocus(() => {
          this.color1 = Color.Blue;
        })
        .onBlur(() => {
          this.color1 = Color.Yellow;
        })
      Divider()

      Text('focusable: '+ this.textFocusable) //The initial value of focusable is true for the second text, and the value of focusableOnTouch is true.
        .borderColor(this.color2)
        .borderWidth(2)
        .width(300)
        .height(70)
        .focusable(this.textFocusable)
        .focusOnTouch(true)
        .onFocus(() => {
          this.color2 = Color.Blue;
        })
        .onBlur(() => {
          this.color2 = Color.Yellow;
        })

      Text('enabled:'+ this.textEnabled) //The focusable parameter is set to true for the third text. The initial value of enabled is true.
        .borderColor(this.color3)
        .borderWidth(2)
        .width(300)
        .height(70)
        .focusable(true)
        .enabled(this.textEnabled)
        .focusOnTouch(true)
        .onFocus(() => {
          this.color3 = Color.Blue;
        })
        .onBlur(() => {
          this.color3 = Color.Yellow;
        })

      Divider()

      Row() {
        Button('Button1')
          .width(140).height(70)
        Button('Button2')
          .width(160).height(70)
      }

      Divider()
      Button('Button3')
        .width(300).height(70)

      Divider()
    }.width('100%').justifyContent(FlexAlign.Center)
    .onKeyEvent((e) => {
      //Bind onKeyEvent. When the Column component is focused, press F to reverse the focusable of the second Text.
      if (e.keyCode === 2022 && e.type === KeyType.Down) {
        this.textFocusable = !this.textFocusable;
      }
      //Bind onKeyEvent. When the Column component is focused, press G to reverse the enabled state of the third Text component.
      if (e.keyCode === 2023 && e.type === KeyType.Down) {
        this.textEnabled = !this.textEnabled;
      }
    })
  }
}
```


Operation result:


![focus-1.gif](figures/focus-1.gif)

The preceding example includes four steps:


- As the **focusable** attribute is not set for the first **\<Text>** component, it cannot be focused.
- Click the second Text component. Because focusOnTouch(true) is set, the second component is focused. Press the Tab key to trigger the focus. The second Text component is still focused. Press F on the keyboard to trigger onKeyEvent. Set focusable to false. The second Text component cannot be focused and the focus automatically shifts. The system automatically searches for the next Text component that can be focused and moves the focus to the third Text component.
- Press G on the keyboard to trigger onKeyEvent. Set enabled to false. The third Text component becomes unfocused and the focus is automatically transferred to the Row container. The default configuration is used in the container, and the focus is transferred to Button1.

### Default focus

```ts
defaultFocus(value: boolean)
```

Specifies whether to set the component as the default focus of the page.


```ts
// xxx.ets
@Entry
@Component
struct morenjiaodian {
  @State oneButtonColor: Color = Color.Gray;
  @State twoButtonColor: Color = Color.Gray;
  @State threeButtonColor: Color = Color.Gray;

  build() {
    Column({ space: 20 }) {
      // You can use the up and down arrow keys on an external keyboard to move the focus between the three buttons. When a button gains focus, its color changes. When it loses focus, its color changes back.
      Button('First Button')
        .width(260)
        .height(70)
        .backgroundColor(this.oneButtonColor)
        .fontColor(Color.Black)
          // Listen for the focus obtaining event of the first component and change its color when it obtains focus.
        .onFocus(() => {
          this.oneButtonColor = Color.Green;
        })
          // Listen for the focus loss event of the first component and change its color when it loses focus.
        .onBlur(() => {
          this.oneButtonColor = Color.Gray;
        })

      Button('Second Button')
        .width(260)
        .height(70)
        .backgroundColor(this.twoButtonColor)
        .fontColor(Color.Black)
          // Listen for the focus obtaining event of the second component and change its color when it obtains focus.
        .onFocus(() => {
          this.twoButtonColor = Color.Green;
        })
          // Listen for the focus loss event of the second component and change its color when it loses focus.
        .onBlur(() => {
          this.twoButtonColor = Color.Grey;
        })

      Button('Third Button')
        .width(260)
        .height(70)
        .backgroundColor(this.threeButtonColor)
        .fontColor(Color.Black)
                   // Set the default focus.
        .defaultFocus(true)
          // Listen for the focus obtaining event of the third component and change its color when it obtains focus.
        .onFocus(() => {
          this.threeButtonColor = Color.Green;
        })
          // Listen for the focus loss event of the third component and change its color when it loses focus.
        .onBlur(() => {
          this.threeButtonColor = Color.Gray ;
        })
    }.width('100%').margin({ top: 20 })
  }
}
```

![defaultFocus.gif](figures/defaultFocus.gif)

The preceding example includes four steps:

- defaultFocus(true) is set for the third Button component. After the page is displayed, the third Button component is focused by default and displayed in green.
- Press the Tab key to trigger the focus. The third button is in the focus state, and the focus frame is displayed.

### Focus Styles


```ts
focusBox(style: FocusBoxStyle)
```

Sets the style of the system focus frame of the current widget.

```ts
import { ColorMetrics, LengthMetrics } from '@ohos.arkui.node'

@Entry
@Component
struct RequestFocusExample {
  build() {
    Column({ space: 30 }) {
      Button("small black focus box")
        .focusBox({
          margin: new LengthMetrics(0),
          strokeColor: ColorMetrics.rgba(0, 0, 0),
        })
      Button("large red focus box")
        .focusBox({
          margin: LengthMetrics.px(20),
          strokeColor: ColorMetrics.rgba(255, 0, 0),
          strokeWidth: LengthMetrics.px(10)
        })
    }
    .alignItems(HorizontalAlign.Center)
    .width('100%')
  }
}
```

![focusBox](figures/focusBox.gif)


The preceding example includes four steps:

- Go to the page and press the tab to trigger the focus. The first button is focused. The focus frame is a blue thin frame close to the edge.
- Press the Tab key and move the focus to the second button. The focus frame is a red thick frame far away from the edge.

### Active Focus Acquisition/Loss of Focus

- Using Methods in focusControl
  ```ts
  requestFocus(value: string): boolean
  ```

  This API is used to actively move the focus to the component specified by the parameter. The focus transfer takes effect when the next frame signal is received.


- Using Methods in FocusController

  You need to use the [getFocusController()](../reference/apis-arkui/js-apis-arkui-UIContext.md#getfocuscontroller12) method in UIContext to obtain the instance, and then use the instance to call the corresponding method.

  ```ts
  requestFocus(key: string): void
  ```
  Moves the focus to the entity node corresponding to the component tree based on the component ID. The focus takes effect when the frame takes effect.

  ```ts
  clearFocus(): void
  ```
  Clears the focus and forcibly moves the focus to the root container node of the page, causing other nodes in the focus chain to lose focus.


```ts
// focusTest.ets
@Entry
@Component
struct RequestExample {
  @State btColor: Color = Color.Blue
  @State btColor2: Color = Color.Blue

  build() {
    Column({ space: 20 }) {
      Column({ space: 5 }) {
        Button('Button')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(this.btColor)
          .onFocus(() => {
            this.btColor = Color.Red
          })
          .onBlur(() => {
            this.btColor = Color.Blue
          })
          .id("testButton")

        Button('Button')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(this.btColor2)
          .onFocus(() => {
            this.btColor2 = Color.Red
          })
          .onBlur(() => {
            this.btColor2 = Color.Blue
          })
          .id("testButton2")

        Divider()
          .vertical(false)
          .width("80%")
          .backgroundColor(Color.Black)
          .height(10)

        Button('FocusController.requestFocus')
          .width(200).height(70).fontColor(Color.White)
          .onClick(() => {
            this.getUIContext().getFocusController().requestFocus("testButton")
          })

        Button("focusControl.requestFocus")
          .width(200).height(70).fontColor(Color.White)
          .onClick(() => {
            focusControl.requestFocus("testButton2")
          })

        Button("clearFocus")
          .width(200).height(70).fontColor(Color.White)
          .onClick(() => {
            this.getUIContext().getFocusController().clearFocus()
          })
      }
    }
    .width('100%')
    .height('100%')
  }
}
```
The preceding example includes four steps:

- Click FocusController.requestFocus. The first button is focused.
- Click focusControl.requestFocus. The second button is focused.
- When the clearFocus button is clicked, the second button is out of focus.


## Component Focus Capability Description


  **Table 1** Focusability of basic components

| Basic Component                                    | Can Be Focused | Default Value of focusable |
| ---------------------------------------- | ------- | ------------ |
| [AlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md) | Yes      | true         |
| [Blank](../reference/apis-arkui/arkui-ts/ts-basic-components-blank.md) | No      | false        |
| [Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md) | Yes      | true         |
| [CalendarPicker](../reference/apis-arkui/arkui-ts/ts-basic-components-calendarpicker.md) | Yes      | true         |
| [Checkbox](../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md) | Yes      | true         |
| [CheckboxGroup](../reference/apis-arkui/arkui-ts/ts-basic-components-checkboxgroup.md) | Yes      | true         |
| [ContainerSpan](../reference/apis-arkui/arkui-ts/ts-basic-components-containerspan.md) | No      | false         |
| [DataPanel](../reference/apis-arkui/arkui-ts/ts-basic-components-datapanel.md) | Yes      | false        |
| [DatePicker](../reference/apis-arkui/arkui-ts/ts-basic-components-datepicker.md) | Yes      | true         |
| [Divider](../reference/apis-arkui/arkui-ts/ts-basic-components-divider.md) | Yes      | false        |
| [Gauge](../reference/apis-arkui/arkui-ts/ts-basic-components-gauge.md) | Yes      | false        |
| [Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md) | Yes      | false        |
| [ImageAnimator](../reference/apis-arkui/arkui-ts/ts-basic-components-imageanimator.md) | No      | false        |
| [ImageSpan](../reference/apis-arkui/arkui-ts/ts-basic-components-imagespan.md)                 | No      | false        |
| [LoadingProgress](../reference/apis-arkui/arkui-ts/ts-basic-components-loadingprogress.md) | Yes      | true        |
| [Marquee](../reference/apis-arkui/arkui-ts/ts-basic-components-marquee.md) | No      | false        |
| [Menu](../reference/apis-arkui/arkui-ts/ts-basic-components-menu.md) | Yes      | true         |
| [MenuItem](../reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md) | Yes      | true         |
| [MenuItemGroup](../reference/apis-arkui/arkui-ts/ts-basic-components-menuitemgroup.md) | No      | false         |
| [Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md) | Yes      | true       |
| [NavRouter](../reference/apis-arkui/arkui-ts/ts-basic-components-navrouter.md) | No      | false        |
| [NavDestination](../reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md) | Yes      | true        |
| [PatternLock](../reference/apis-arkui/arkui-ts/ts-basic-components-patternlock.md) | Yes      | true        |
| [Progress](../reference/apis-arkui/arkui-ts/ts-basic-components-progress.md) | Yes      | true        |
| [QRCode](../reference/apis-arkui/arkui-ts/ts-basic-components-qrcode.md) | Yes      | true        |
| [Radio](../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md) | Yes      | true         |
| [Rating](../reference/apis-arkui/arkui-ts/ts-basic-components-rating.md) | Yes      | true         |
| [RichEditor](../reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md) | Yes      | true         |
| [RichText](../reference/apis-arkui/arkui-ts/ts-basic-components-richtext.md) | No      | false        |
| [ScrollBar](../reference/apis-arkui/arkui-ts/ts-basic-components-scrollbar.md) | No      | false        |
| [Search](../reference/apis-arkui/arkui-ts/ts-basic-components-search.md) | Yes      | true         |
| [Select](../reference/apis-arkui/arkui-ts/ts-basic-components-select.md) | Yes      | true         |
| [Slider](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md) | Yes      | true         |
| [Span](../reference/apis-arkui/arkui-ts/ts-basic-components-span.md) | No      | false        |
| [Stepper](../reference/apis-arkui/arkui-ts/ts-basic-components-stepper.md) | Yes      | true         |
| [StepperItem](../reference/apis-arkui/arkui-ts/ts-basic-components-stepperitem.md) | Yes      | true         |
| [SymbolSpan](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolSpan.md) | No      | false         |
| [SymbolGlyph](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolGlyph.md) | No      | false         |
| [Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md) | Yes      | false        |
| [TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md) | No      | false         |
| [TextClock](../reference/apis-arkui/arkui-ts/ts-basic-components-textclock.md) | No      | false        |
| [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md) | Yes      | true         |
| [TextPicker](../reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md) | Yes      | true         |
| [TextTimer](../reference/apis-arkui/arkui-ts/ts-basic-components-texttimer.md) | No      | false        |
| [TimePicker](../reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md) | No      | false         |
| [Toggle](../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md) | Yes      | true         |
| [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md) | Yes      | false        |

  **Table 2** Focusability of container components

| Container Component                                    | Focusable | Default Value of focusable |
| ---------------------------------------- | ----- | ------------ |
| [Badge](../reference/apis-arkui/arkui-ts/ts-container-badge.md) | No    | false        |
| [Column](../reference/apis-arkui/arkui-ts/ts-container-column.md) | Yes    | true         |
| [ColumnSplit](../reference/apis-arkui/arkui-ts/ts-container-columnsplit.md) | Yes    | true         |
| [Counter](../reference/apis-arkui/arkui-ts/ts-container-counter.md) | Yes    | false         |
| [EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md)    | No    | false         |
| [Flex](../reference/apis-arkui/arkui-ts/ts-container-flex.md) | Yes    | true         |
| [FlowItem](../reference/apis-arkui/arkui-ts/ts-container-flowitem.md)             | Yes    | true         |
| [FolderStack](../reference/apis-arkui/arkui-ts/ts-container-folderstack.md)             | Yes    | true         |
| [FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md)               | No    | false         |
| [GridCol](../reference/apis-arkui/arkui-ts/ts-container-gridcol.md) | Yes    | true         |
| [GridRow](../reference/apis-arkui/arkui-ts/ts-container-gridrow.md) | Yes    | true         |
| [Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md) | Yes    | true         |
| [GridItem](../reference/apis-arkui/arkui-ts/ts-container-griditem.md) | Yes    | true         |
| [Hyperlink](../reference/apis-arkui/arkui-ts/ts-container-hyperlink.md)         | Yes    | true         |
| [List](../reference/apis-arkui/arkui-ts/ts-container-list.md) | Yes    | true         |
| [ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md) | Yes    | true         |
| [ListItemGroup](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md) | Yes    | true         |
| [Navigator](../reference/apis-arkui/arkui-ts/ts-container-navigator.md) | Yes    | true         |
| [Refresh](../reference/apis-arkui/arkui-ts/ts-container-refresh.md) | Yes    | true        |
| [RelativeContainer](../reference/apis-arkui/arkui-ts/ts-container-relativecontainer.md) | No    | false         |
| [Row](../reference/apis-arkui/arkui-ts/ts-container-row.md) | Yes   | true         |
| [RowSplit](../reference/apis-arkui/arkui-ts/ts-container-rowsplit.md) | Yes    | true         |
| [Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md) | Yes    | true         |
| [SideBarContainer](../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md) | Yes    | true         |
| [Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md) | Yes    | true         |
| [Swiper](../reference/apis-arkui/arkui-ts/ts-container-swiper.md) | Yes    | true         |
| [Tabs](../reference/apis-arkui/arkui-ts/ts-container-tabs.md) | Yes    | true         |
| [TabContent](../reference/apis-arkui/arkui-ts/ts-container-tabcontent.md) | Yes    | true         |
| [WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md)         | No    | false         |
| [WithTheme](../reference/apis-arkui/arkui-ts/ts-container-with-theme.md)         | Yes    | true         |

  **Table 3** Focusability of media components

| Media Component                                    | Focusable | Default Value of focusable |
| ---------------------------------------- | ----- | ------------ |
| [Video](../reference/apis-arkui/arkui-ts/ts-media-components-video.md) | Yes    | true         |
