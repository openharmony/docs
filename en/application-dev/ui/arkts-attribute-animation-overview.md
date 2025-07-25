# Property Animation Overview


A property API (property for short) defines a multitude of properties, such as size, layout, and location, for controlling behavior of the owning component. Changes to some properties (such as location) on the UI will cause UI re-render. You can animate the value change of a property from the start point to the end point. Properties can be classified as animatable or non-animatable, depending on whether an animation can be applied to their value changes. Specifically, an animatable property meets the following requirements:


1. Its value changes can cause UI re-render. For example, the [enabled](../reference/apis-arkui/arkui-ts/ts-universal-attributes-enable.md#enabled) property is used to control whether a component can respond to events such as clicks and touches. However, as its value change does not cause UI re-render, it does not qualify as an animatable property.

2. An animation can be applied to the transition between value changes. For example, the [focusable](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md#focusable) property determines whether the current component can obtain focus. If the value of this property changes, the component should immediately switch to the end state to respond to user behavior, and no animation is appropriate here. Therefore, the property does not qualify as an animatable property.

**Property classification:**

- Animatable properties:

  - Built-in animatable properties
  
    | Category    | Example                                          |
    | -------- | ---------------------------------------------- |
    | Layout| Position, size, padding, margin, alignment, and weight.|
    | Affine transformation| Translation, rotation, scaling, and anchor.                    |
    | Background    | Background color and blur.                        |
    | Content    | Font size, font color, image alignment, and blur.    |
    | Foreground    | Foreground color.                                  |
    | Overlay  | Overlay.                               |
    | Appearance    | Opacity, rounded corner, border, and shadow.                  |
    | ...      | ...                                            |

  - Custom animatable properties: animatable properties abstracted through the custom property animation mechanism.

- Non-animatable properties: **zIndex** and **focusable**, among others.


Generally, an animatable property accepts only continuous parameters, which allows for using interpolation to fill in gaps between data points, so as to create a visual illusion of continuity. That said, whether the parameter type of a property can be interpolated is not a key factor that determines whether an animation can be applied to the property. For example, with regard to the [direction](../reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md#direction) property, which sets the horizontal layout of an element, as it is animatable, ArkUI allows you to apply an animation to the transition between its value changes, though its parameter type is enum.


Animatable properties include both built-in and custom properties.


- Built-in animatable properties: system-provided component properties for changing the UI, for example, position, zoom, and blur properties.

- Custom animatable properties: properties made animatable with the use of the [@AnimatableExtend](../ui/state-management/arkts-animatable-extend.md) decorator. You can abstract animatable properties from the custom drawing content to control the drawing content of each frame, for example, customizing the volume icon. By defining custom animatable properties, you can apply animations to some properties that otherwise do not support animations in ArkUI.
