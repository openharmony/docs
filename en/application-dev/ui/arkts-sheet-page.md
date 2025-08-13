# Binding a Semi-Modal Page (bindSheet)

A semi-modal page, implemented using [bindSheet](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet), is a modal, non-full-screen popup interaction page by default, allowing parts of the underlying parent view to be visible. This helps users retain the context of their parent view while interacting with the semi-modal.

Semi-modal pages are suitable for displaying simple tasks or information panels, such as personal information, text introductions, sharing panels, creating schedules, and adding content. If a semi-modal page needs to be displayed in a way that could potentially affect the parent view, it can be configured to use a non-modal interaction form.

Semi-modal pages have different form capabilities on devices of different widths. For details about the form requirements on devices with different widths, see the [preferType](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions) property. You can use **bindSheet** to build semi-modal transition effects. For details, see [Modal Transition](arkts-modal-transition.md#creating-sheet-transition-with-bindsheet). For complex or lengthy user processes, consider other transition methods instead of semi-modals, such as [full-modal transition](arkts-contentcover-page.md) and [navigation transition](arkts-navigation-navigation.md).

## Constraints

 - When a [UIExtension](../reference/apis-arkui/js-apis-arkui-uiExtension.md) is embedded in a semi-modal, launching another semi-modal or popup window within the UIExtension is not allowed.

 - In scenarios without secondary confirmation or custom close behavior, avoid using the [shouldDismiss/onWillDismiss](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions) API.

## Lifecycle

The semi-modal page provides lifecycle callbacks to notify the application of the lifecycle status of the popup. These callbacks are triggered in the following order: onWillAppear -> onAppear -> onWillDisappear -> onDisappear.

| Name           |Type| Description                      |
| ----------------- | ------ | ---------------------------- |
| onWillAppear    | () => void | Callback for when the semi-modal page is about to appear (before the animation starts).|
| onAppear    | () => void  | Callback for when the semi-modal page appears (after the animation ends). |
| onWillDisappear | () => void | Callback for when the semi-modal page is about to disappear (before the animation starts).|
| onDisappear |() => void  | Callback for when the semi-modal page disappears (after the animation ends).    |

## Using Nested Scrolling

The priority of operations during scrolling in the content area of a semi-modal panel is as follows:

1. 1. Content at the top and content that cannot be scrolled

   Swiping up: The sheet will attempt to expand upwards. If no expansion is possible, the content will scroll.

   Swiping down: The panel will attempt to contract downwards. If no contraction is possible, the panel will close.
2. 2. Content in the middle (scrollable both up and down)

   Swiping up or down: The content will scroll until it reaches the top or bottom of the panel.

3. 3. Content at the bottom (scrollable)

   Swiping up: The content area will display a rebound effect without changing the panel position.

   Swiping down: The content will scroll until it reaches the top.

By default, the nested scrolling mode for the half-modal panel is as follows: {Forward: PARENT\_FIRST, Backward: SELF\_FIRST}

If you want to define a scrollable container, such as **List** or **Scroll**, in the panel content builder, and combine it with the semi-modal's interaction capabilities, you must set the nested scrolling attributes for the scrollable container in the vertical direction.

```ts
.nestedScroll({
    // Nested scrolling options for the scrollable component when it scrolls towards the end, with the gesture upwards.
    scrollForward: NestedScrollMode.PARENT_FIRST,
    // Nested scrolling options for the scrollable component when it scrolls towards the start, with the gesture downwards.
    scrollBackward: NestedScrollMode.SELF_FIRST,
})
```

The sample code is as follows:

```ts
@Entry
@Component
struct SheetDemo {
  @State isShowSheet: boolean = false;
  private items: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  @Builder
  SheetBuilder() {
    Column() {
      // Step 1: Customize a scrollable container.
      List({ space: '10vp' }) {
        ForEach(this.items, (item: number) => {
          ListItem() {
            Text(String(item)).fontSize(16).fontWeight(FontWeight.Bold)
          }.width('90%').height('80vp').backgroundColor('#ff53ecd9').borderRadius(10)
        })
      }
      .alignListItem(ListItemAlign.Center)
      .margin({ top: '10vp' })
      .width('100%')
      .height('900px')
      // Step 2: Set the nested scrolling attributes of the scrollable component.
      .nestedScroll({
        scrollForward: NestedScrollMode.PARENT_FIRST,
        scrollBackward: NestedScrollMode.SELF_FIRST,
      })

      Text("Non-scrollable area")
        .width('100%')
        .backgroundColor(Color.Gray)
        .layoutWeight(1)
        .textAlign(TextAlign.Center)
        .align(Alignment.Top)
    }.width('100%').height('100%')
  }

  build() {
    Column() {
      Button('Open Sheet').width('90%').height('80vp')
        .onClick(() => {
          this.isShowSheet = !this.isShowSheet;
        })
        .bindSheet($$this.isShowSheet, this.SheetBuilder(), {
          detents: [SheetSize.MEDIUM, SheetSize.LARGE, 600],
          preferType: SheetType.BOTTOM,
          title: { title: 'Nested Scrolling Scenario' },
        })
    }.width('100%').height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

## Secondary Confirmation Capability

To implement the secondary confirmation capability, you are advised to use the **onWillDismiss** API, with which you can handle secondary confirmation or custom close behavior in the callback.

> **NOTE**
>
> After the **onWillDismiss** API is declared, all close operations of the semi-modal page, including side swiping, touching the close button, touching the mask, and pulling down, must be implemented by calling the **dismiss** API. If this logic is not implemented, the semi-modal page will not respond to the above close operations.

```ts
// Step 1: Declare the onWillDismiss callback.
onWillDismiss: ((DismissSheetAction: DismissSheetAction) => {
// Step 2: Implement the secondary confirmation interaction, using an AlertDialog component to prompt the user for confirmation.
  this.getUIContext().showAlertDialog(
    {
      message: 'Do you want to close the semi-modal?',
      autoCancel: true,
      alignment: DialogAlignment.Bottom,
      gridCount: 4,
      offset: { dx: 0, dy: -20 },
      primaryButton: {
        value: 'cancel',
        action: () => {
          console.info('Callback when the cancel button is clicked');
        }
      },
      secondaryButton: {
        enabled: true,
        defaultFocus: true,
        style: DialogButtonStyle.HIGHLIGHT,
        value: 'ok',
        // Step 3: Define the logic for closing the semi-modal within the AlertDialog button callback.
        action: () => {
          // Step 4: Call dismiss() to close the semi-modal when the logic in step 3 is triggered.
          DismissSheetAction.dismiss();
          console.info('Callback when the ok button is clicked');
        }
      },
      cancel: () => {
        console.info('AlertDialog Closed callbacks');
      }
    }
  )
})
```

## Blocking Specific Dismiss Behavior

After the **onWillDismiss** API is declared, it takes control over all dismiss behaviors of the semi-modal. This means that the semi-modal can be dismissed only when you explicitly call the **dismiss** API. You can customize the dismissal logic using **if** statements or other logic.
For example, you might want the semi-modal to be dismissed only when the user swipes down. Here's how you can implement this:

```ts
onWillDismiss: ((DismissSheetAction: DismissSheetAction) => {
  if (DismissSheetAction.reason === DismissReason.SLIDE_DOWN) {
    DismissSheetAction.dismiss(); // Register the dismiss behavior.
  }
}),
```

To enhance the user experience during the swiping down action, you can use the **onWillSpringBackWhenDismiss** API.
Just like with **onWillDismiss**, after **onWillSpringBackWhenDismiss** is declared, the rebound operation during a swipe-down of the half-modal requires handling with **SpringBackAction.springBack()**; without this logic, no rebound will occur.

Here is the specific code to prevent the rebound effect when the semi-modal is swiped down:

```ts
onWillDismiss: ((DismissSheetAction: DismissSheetAction) => {
  if (DismissSheetAction.reason === DismissReason.SLIDE_DOWN) {
    DismissSheetAction.dismiss(); // Register the dismiss behavior.
  }
}),

onWillSpringBackWhenDismiss: ((SpringBackAction: SpringBackAction) => {
 // No springBack is registered, so the half-modal will not bounce back when swiped down.
}),
```
