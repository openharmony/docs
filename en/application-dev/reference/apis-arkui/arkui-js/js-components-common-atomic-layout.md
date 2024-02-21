# Atomic Layout

>  **NOTE**
>
>  This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.

The atomic layout implements adaptive layout for screens of different sizes and types. Designers can use the atomic layout to define adaptive rules for elements on UIs of different forms. Developers can use the atomic layout to implement the adaptive UI features matching the design effect for a variety of screens.

## Hiding Components

You can set priority flags for a flex layout that does not support cross-row display to define the display priorities for elements in the horizontal or vertical direction. The elements are hidden based on available space of the container.

| Name | Type| Description|
| -------- | -------- | -------- |
| display-index | number | Display index of a child component. Child components are hidden according to the ascending order of their **display-index** values when the space on the flex main axis of the container is insufficient to display all content. Child components with the same display-index value are hidden at the same time.<br>Default value: **0** (means not to hide the child component)|


## Proportion

In a flex layout that does not support cross-row display, child components with the proportion style configured are always arranged with the set proportions in the container.

| Name | Type| Description|
| -------- | -------- | -------- |
| flex-weight | number | Size weight of a child component on the flex main axis. If this style is set for all child components in the container: Child component size = Container main axis size x flex-weight / Sum of size weights of all child components. If this style is set for only some child components in the container, the container first lays out the child components for which this style is not set and then allocates the remaining space to the set child components. Size of the set child component = Remaining space x flex-weight / Sum of size weights of all child components.|


## Fixed Ratio

A component with fixed ratio can be scaled up and down while retaining its aspect ratio.

| Name | Type| Description|
| -------- | -------- | -------- |
| aspect-ratio | number | Aspect ratio of the component. The value is a floating-point value greater than 0.<br>The value is subjective to the upper and lower limits of the component size.<br>In a flex layout, the main axis size is adjusted first, based on which the cross axis size is adjusted.|
