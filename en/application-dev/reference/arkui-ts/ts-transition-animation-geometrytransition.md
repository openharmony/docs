# Implicit Shared Element Transition (geometryTransition)

**GeometryTransition** is used for implicit shared element transitions during component switching. By specifying the in and out components through **id**, you can create a spatial linkage between the transition effects. In this way, you can guide the visual focus from the out component to the in component.

> **NOTE**
>
> This feature is supported since API version 7 but does not take effect. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes

| Name              |   Parameter  | Description                                                    |
| ------------------ | -------- | ------------------------------------------------------------ |
| geometryTransition | id: string | ID of **geometryTransition**, which is used to set up a binding relationship. If this attribute is set to an empty string **""**, the binding relationship is cleared, and the components will not participate in the shared element transition. The value can be dynamically changed to refresh the binding relationship. One ID can be bound to only two components, which function as in and out components.|
