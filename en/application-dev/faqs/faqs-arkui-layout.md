# ArkUI Layout Development (ArkTS)


## What should I do if the height settings in position do not take effect? (API version 9)

**Solution**

When **position** is set for a container component, it is taken out of normal flow and works independently from the outer container. In this case, the height does not take effect. You can replace the outer container with a stack to solve this issue.


## How do I implement horizontal scrolling on a Grid component? (API version 9)

Set **rowsTemplate** (the number of rows) for the **Grid** component and do not set **columnsTemplate** (the number of columns). In this way, the **Grid** component scrolls horizontally when its content does not fit within its width.


## What should I do if the List component cannot be dragged to the bottom when it is used with another component and does not have the size specified? (API version 9)

Add the **layoutWeight** attribute for the **List** component so that it takes up the remaining height (or width, depending on the scrolling direction). By default, the **List** component, as a scrollable container, takes up the entire screen height. When it is used with any component whose height is fixed, you need to explicitly add the **layoutWeight** attribute for the **List** component so that it takes up the remaining height instead of the entire screen height.


## Can tab switching be disabled for the Tabs component? (API version 9)

No. This feature is not supported.


## How do I intercept the onBackPress event so that it does not trigger page return? (API version 9)

If **true** is returned in **onBackPress**, the page executes its own return logic instead of the default return logic.

**Reference**

[Custom Component Lifecycle-onBackPress](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#onbackpress)


## How do I implement a sticky header for a list item group in the List component? (API version 9)

You can use the **sticky** attribute of the **List** component together with the **ListItemGroup** component. Specifically, set the **sticky** attribute of the **List** component to **StickyStyle.Header** and set the **header** parameter of the corresponding **ListItemGroup** component.

**Reference**

[Adding a Sticky Header](../ui/arkts-layout-development-create-list.md#adding-a-sticky-header)

## How do I configure only specified UI components to move up to avoid the open keyboard? (API version 10)

**Solution**

 To configure the UI logic for keyboard avoidance, use **expandSafeArea**.

**Reference**

[Safe Area](../reference/apis-arkui/arkui-ts/ts-universal-attributes-expand-safe-area.md)

## What methods are available for combining text and images? (API version 10)

**Solution**

1. To display text with images, you can nest an **ImageSpan** component in a **Text** component; alternatively, nest **Text** and **Image** components in a container component (such as **Row** and **Column**). The former is recommended.

2. If editing is needed, use the **RichEditor** component.

**Reference**

[RichEditor](../reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md)

## How do I implement a coordinated layout? (API version 10)

**Solution**

You can implement nested scrolling in a scrollable component with the **nestedScroll** attribute.

**Reference**

[Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md)

## What should I do if the navigation bar is blocked when the sidebar is displayed? (API version 10)

**Solution**

Configure the navigation bar as the second child component, that is, the content area, of the **SideBarContainer** component. In this way, the sidebar takes up only its own width and does not block other part of the navigation bar.

**Reference**

[SideBarContainer](../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md)

## What should I if the UI is not re-rendered with ForEach and LazyForEach when the data source is changed? (API version 10)

**Solution**

If the default key generator is used, the framework automatically generates a key based on **item** and **index**, that is, **(item: T, index: number) => { return index + '__' + JSON.stringify(item); }**. When the data source of a state variable is changed, **ForEach** or **LazyForEach** detects the key change, and triggers a component reconstruction to update the UI.

**Reference**

[ForEach: Rendering of Repeated Content](../quick-start/arkts-rendering-control-foreach.md)

## How do I decouple a dialog box from pages? What are the best practices? (API 10)

**Solution**

A dialog box must be bound a component and triggered by events. Its content can be defined with a global builder. It only needs to be defined once.

Global builder:

Syntax:

@Builder function MyGlobalBuilderFunction(){ ... }

Usage:

MyGlobalBuilderFunction()

A custom global build function is accessible throughout the application. As such, it is recommended if no own state is involved.

**Reference**

1. [Custom Dialog Box (CustomDialog)](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)
2. [Popup Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md)
3. [@Builder Decorator: Custom Builder Function](../quick-start/arkts-builder.md)

## What should I do if there are white and dark lines between two adjacent components of the same color? (API version 11)

**Solution**

If the boundaries of adjacent components with the same color fall on floating-point coordinates, a seemingly white or dark line appears after anti-aliasing processing is performed at the graphics layer. To fix this issue, set the universal attribute **pixelRound**
so that the component boundaries on both sides of the white and dark lines are aligned with the integer pixel coordinates.

Usage:
```ts
Flex(){
    Column().height('30%').width('30%').backgroundColor(Color.Blue)
        .pixelRound({end: PixelRoundCalcPolicy.FORCE_CEIL})
    Column().height('30%').width('30%').backgroundColor(Color.Blue)
    Column().height('30%').width('30%').backgroundColor(Color.Blue)
}
```

**Reference**
[Layout Constraints](../reference/apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md)
