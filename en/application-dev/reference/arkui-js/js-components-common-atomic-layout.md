# Atomic Layout

The atomic layout implements adaptive layout for screens of different sizes and types. Designers can use the atomic layout to define adaptive rules for elements on UIs of different forms. Developers can use the atomic layout to implement the adaptive UI features matching the design effect for a variety of screens.

## Hiding Components

You can set priority flags for a flex layout that does not support cross-row display to define the display priorities for elements in the horizontal or vertical direction. The elements are hidden based on available space of the container.



| Style         | Type   | Default Value | Description                                                  |
| ------------- | ------ | ------------- | ------------------------------------------------------------ |
| display-index | number | 0             | Hide child components according to the ascending order of their **display-index** values when the space on the flex main axis of the container is insufficient to display all content.<br>Child components with the same **display-index** value are hidden at the same time.<br>You can use the default value (**0**) for a child component, which means that it will be hidden.<br>This style is applicable only to child components in a container that supports the flex layout, such as **\<div>**. |

## Proportion

In a flex layout that does not support cross-row display, elements with the proportion style configured are always arranged with the set proportions in the container.



| Style       | Type   | Default Value | Description                                                  |
| ----------- | ------ | ------------- | ------------------------------------------------------------ |
| flex-weight | number | -             | Size weight of an element on the flex main axis.<br>Element size = Container main axis size x **flex-weight** / Sum of all element size weights.<br>This style takes effect only when it is set for all elements in the container. |

## Fixed Ratio

A component with fixed ratio can be scaled up and down while retaining its aspect ratio.



| Style        | Type   | Default Value | Description                                                  |
| ------------ | ------ | ------------- | ------------------------------------------------------------ |
| aspect-ratio | number | -             | Aspect ratio of the component. The value is a floating-point value greater than 0.<br>The value is subjective to the upper and lower limits of the component size.<br>In a flex layout, the main axis size is adjusted first, based on which the cross axis size is adjusted. |