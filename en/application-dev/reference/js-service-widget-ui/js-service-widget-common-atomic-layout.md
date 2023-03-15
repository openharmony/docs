# Atomic Layout

The atomic layout implements adaptive layout for screens of different sizes and types. Designers can use the atomic layout to define adaptive rules for components on UIs of different widgets. Developers can use the atomic layout to implement the adaptive UI features matching the design effect for a variety of screens.


>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Hiding Components

You can set priority flags for a flex layout that does not support cross-row display to define the display priorities for components in the horizontal or vertical direction. The components are hidden based on available space of the container.

| Style           | Type    | Default Value | Description                                      |
| ------------- | ------ | ---- | ---------------------------------------- |
| display-index | number | 0    | When the space of a container on the flex main axis is insufficient to display all content, the child components are hidden in ascending order of their **display-index** values. Child components with the same **display-index** value are hidden at the same time. The default value of this style is **0**, indicating that the child component is hidden. This style is applicable to child components in a container that supports flex layout, such as **\<div>**. |


## Proportion

In a flex layout that does not support cross-row display, components with the proportion style configured are always arranged with the set proportions in the container.

| Style         | Type    | Default Value | Description                                      |
| ----------- | ------ | ---- | ---------------------------------------- |
| flex-weight | number | -    | Size weight of the component on the flex main axis. Component size = Container main axis size x flex-weight / Sum of all component size weights. This style takes effect only when it is set for all components in the container.|


## Fixed Ratio

A component with fixed ratio can be scaled up and down while retaining its aspect ratio.

| Style          | Type    | Default Value | Description                                      |
| ------------ | ------ | ---- | ---------------------------------------- |
| aspect-ratio | number | -    | Aspect ratio of the component. The value is a floating-point value greater than 0.<br>The value is subjective to the upper and lower limits of the component size.<br>In a flex layout, the main axis size is adjusted first, based on which the cross axis size is adjusted.|
