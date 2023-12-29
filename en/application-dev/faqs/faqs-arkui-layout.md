# ArkUI Layout Development (ArkTS)

## What should I do if the height settings in position do not take effect? (API version 9)

**Solution**

When **position** is set for a container component, it is taken out of normal flow and works independently from the outer container. In this case, the height does not take effect. You can replace the outer container with a stack to solve this issue.

## How do I implement horizontal scrolling on a \<Grid> component? (API version 9)

Set **rowsTemplate** (the number of rows) for the **\<Grid>** component and do not set **columnsTemplate** (the number of columns). In this way, the **\<Grid>** component scrolls horizontally when its content does not fit within its width.

## What should I do if the \<List> component cannot be dragged to the bottom when it is used with another component and does not have the size specified? (API version 9)

Add the **layoutWeight** attribute for the **\<List>** component so that it takes up the remaining height (or width, depending on the scrolling direction) adapatively.

By default, the **\<List>** component, as a scrollable container, takes up the entire screen height. When it is used with any component whose height is fixed, you need to explicitly add the **layoutWeight** attribute for the **\<List>** component so that it takes up the remaining height instead of the entire screen height.

## Can tab switching be disabled for the \<Tabs> component? (API version 9)

No. This feature is not supported.

## How do I intercept the onBackPress event so that it does not trigger page return? (API version 9)

If **true** is returned in **onBackPress**, the page executes its own return logic instead of the default return logic.

**Reference**

[onBackPress](../reference/arkui-ts/ts-custom-component-lifecycle.md#onbackpress).

## How do I implement a sticky header for a list item group in the \<List> component? (API version 9)

You can use the **sticky** attribute of the **\<List>** component together with the **\<ListItemGroup>** component. Specifically, set the **sticky** attribute of the **\<List>** component to **StickyStyle.Header** and set the **header** parameter of the corresponding **\<ListItemGroup>** component.

**Reference**

[Adding a Sticky Header](../ui/arkts-layout-development-create-list.md#adding-a-sticky-header)