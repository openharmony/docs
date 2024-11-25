# Event Distribution

## Overview

ArkUI touch events are primarily categorized into touch and mouse types based on the input source.

The touch input sources include: finger, pen

The mouse input sources include: mouse, touchpad, joystick

Events triggered by these two types of input sources are as follows.

| Touch | Mouse |
|:-----:| ----- |
| Touch event | Touch event |
| Click event | Mouse event |
| Drag event | Click event |
| Gesture event | Drag event |
|       | Gesture event |

Both touch and mouse events in ArkUI are initiated by touch testing, which directly determines the generation of the ArkUI event response chain and the distribution of events.

## Touch Testing

Several factors significantly affect the results of touch testing:

- **TouchTest**: The entry method for touch testing, without external APIs

- **hitTestBehavior**: control on touch testing

- **interceptTouch**: custom interception of events

- **responseRegion**: touch target settings

- **enabled**: enable/disable control, which means control on the component's interactivity

- Security components

- Other attribute settings: such as opacity and component availability

### TouchTest

- Touch testing is initiated by each press action, with the root node's **TouchTest** API as the default entry point.

- **hitTestBehavior** can be modified by the **InterceptTouch** event.

- If touch targets, enable/disable control, opacity, or other settings do not meet the component's interaction requirements, the event will immediately bubble up to the parent node.

  ![TouchTest](figures/TouchTest.png)

### Touch Test Control

For details, see [Hit Test Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-hit-test-behavior.md).

- Hit: The touch test successfully captures events for the current component or its child components.

- The impact of child components on the parent component's touch test depends on the last child component that does not block the touch test.

- **HitTestMode.Default**: the default mode when the **hitTestBehavior** attribute is not specified. If the component itself is hit, it will block other siblings but not children.

  ![hitTestModeDefault](figures/hitTestModeDefault.png)

- **HitTestMode.None**: The component does not receive events and does not prevent siblings or children from continuing the touch test.

  ![hitTestModeNone](figures/hitTestModeNone.png)

- **HitTestMode.Block**: This mode blocks touch tests of the children. If the component itself is hit, it will block the touch test for siblings and the parent.

  ![hitTestModeBlock](figures/hitTestModeBlock.png)

- **HitTestMode.Transparent**: The component participates in the touch test without blocking siblings or the parent.

  ![hitTestModeTransparent](figures/hitTestModeTransparent.png)

### Custom Event Interception

[Custom event interception](../reference/apis-arkui/arkui-ts/ts-universal-attributes-on-touch-intercept.md) allows you to dynamically change a component's **hitTestBehavior** attribute based on service needs when a touch is initiated.

### Enable/Disable Control

[Disabled](../reference/apis-arkui/arkui-ts/ts-universal-attributes-enable.md) components, including their children, do not initiate the touch testing process; instead, they pass the event back to the parent for handling.

### Touch Target Settings

[Touch target settings](../reference/apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md) affect touch testing for touch and mouse inputs. If the component area is set to zero or designated as a non-touchable area, the event will directly propagate to the parent node for continued touch testing.

### Security Components

ArkUI provides a range of security components, including [LocationButton](../security/AccessToken/locationbutton.md), [PasteButton](../security/AccessToken/pastebutton.md), and [SaveButton](../security/AccessToken/savebutton.md).

If a component has a higher [z-order](../reference/apis-arkui/arkui-ts/ts-universal-attributes-z-order.md) than a security component and covers it, the security component's touch events are sent directly to the parent node for further touch testing.

## Event Response Chain Collection

In ArkUI, the event response chain is collected based on a right subtree priority, which follows a post-order traversal process according to the layout hierarchy of components. The process is as follows:

```
foreach(item=>(node.rbegin(),node.rend(){
    item.TouchTest()
}
node.collectEvent()
```

In the example of response chain collection below, with all **hitTestBehavior** attributes set to **Default** in the component tree, if a user touches component 5, the response chain that is ultimately collected, in order, is 5, 3, 1.

This is because component 3 has **hitTestBehavior** set to **Default**, which, upon capturing the event, blocks the collection from its sibling nodes, thereby preventing the collection of component 1's left subtree.

  ![EventResponseChain](figures/EventResponseChain.png)
