# Attribute Animation Overview


An attribute API (attribute for short) defines a multitude of attributes, such as size, layout, and location, for controlling behavior of the owning component. Changes to some attributes (such as location) on the UI will cause UI re-render. You can animate the value change of an attribute from the start point to the end point. Attributes can be classified as animatable or non-animatable, depending on whether an animation can be applied to their value changes. Specifically, an animatable attribute meets the following requirements:


1. Its value changes can cause UI re-render. For example, the [enabled](../reference/arkui-ts/ts-universal-attributes-enable.md) attribute is used to control whether a component can respond to events such as clicks and touches. However, as its value change does not cause UI re-render, it does not qualify as an animatable attribute.

2. An animation can be applied to the transition between value changes. For example, the [focusable](../reference/arkui-ts/ts-universal-attributes-focus.md) attribute determines whether the current component can obtain focus. If the value of this attribute changes, the component should immediately switch to the end state to respond to user behavior, and no animation is appropriate here. Therefore, the attribute does not qualify as an animatable attribute.

**Attribute classification:**

- Animatable attributes:

  - Built-in animatable attributes
  
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

  - Custom animatable attributes: animatable attributes abstracted through the custom attribute animation mechanism.

- Non-animatable attributes: **zIndex** and **focusable**, among others.


Generally, an animatable attribute accepts only continuous parameters, which allows for using interpolation to fill in gaps between data points, so as to create a visual illusion of continuity. That said, whether the parameter type of an attribute can be interpolated is not a key factor that determines whether an animation can be applied to the attribute. For example, with regard to the [direction](../reference/arkui-ts/ts-universal-attributes-location.md) attribute, which sets the horizontal layout of an element, as it is animatable, ArkUI allows you to apply an animation to the transition between its value changes, though its parameter type is enum.


Animatable attributes include both built-in and custom attributes.


- Built-in animatable attributes: system-provided component attributes for changing the UI, for example, position, zoom, and blur attributes.

- [Custom animatable attributes](../quick-start/arkts-animatable-extend.md): attributes made animatable with the use of the [@AnimatableExtend](../quick-start/arkts-animatable-extend.md) decorator. You can abstract animatable attributes from the custom drawing content to control the drawing content of each frame, for example, customizing the volume icon. By defining custom animatable attributes, you can apply animations to some attributes that otherwise do not support animations in ArkUI.
