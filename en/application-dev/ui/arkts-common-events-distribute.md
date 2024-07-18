# Event Dispatch

## Overview

ArkUI touch events are primarily divided into touch and mouse categories based on the input source.

The touch category includes input sources such as: finger, pen

The mouse category includes input sources such as: mouse, touchpad, joystick

The following events can be triggered by these two types of input sources:

|     touch      | mouse          |
| :------------: | :------------- |
|  Touch Events  | Touch Events   |
|  Click Events  | Mouse Events   |
|  Drag Events   | Click Events   |
| Gesture Events | Drag Events    |
|                | Gesture Events |

Whether it is a touch event or a mouse event, in the ArkUI framework, they are all initiated by touch testing, which directly determines the generation of the ArkUI event response chain and the distribution of events.

## Touch Testing

The following are several factors that have a significant impact on the results of touch testing:

- TouchTest: The entry method for touch testing, this method has no external interface

- hitTestBehavior: Control of touch testing

- interceptTouch: Custom event interception

- responseRegion: Setting of touch hotspots

- enable: Disable control

- Safe components

- Other attribute settings: Transparency/Component deactivation

### TouchTest

- The trigger time for TouchTest is initiated by the press action of each tap, and the default entry is the TouchTest method of the root node of the component tree.

- hitTestBehavior can be changed by the InterceptTouch event.

- Touch hotspots/disabling control/transparency, etc., that do not meet the component event interaction requirements will cause an immediate return to the parent node.

  ![TouchTest](figures/TouchTest.png)

### Control of Touch Testing

For specific usage, refer to [Control of Touch Testing](../reference/apis-arkui/arkui-ts/ts-universal-attributes-hit-test-behavior.md)

- Hit: The touch test successfully collects events for the current component/sub-component.

- The impact of sub-components on the parent component's touch test depends on the last sub-component that has not blocked the touch test.

- hitTestMode.default: The effect of not setting the hitTestBehavior property by default, if it hits, it will block siblings but not children.

  ![hitTestModeDefault](figures/hitTestModeDefault.png)

- hitTestMode.none: It does not receive events itself but will not block siblings/children from continuing touch testing.

  ![hitTestModeNone](figures/hitTestModeNone.png)

- hitTestMode.block: Blocks the touch test of children, if it hits, it will block the touch test of siblings and parents.

  ![hitTestModeBlock](figures/hitTestModeBlock.png)

- hitTestMode.transparent: It performs touch testing itself and does not block siblings or parents.

  ![hitTestModeTransparent](figures/hitTestModeTransparent.png)

### Custom Event Interception

[Custom Event Interception](../reference/apis-arkui/arkui-ts/ts-universal-attributes-on-touch-intercept.md) can dynamically change the component's hitTestBehavior property based on business status when triggered by a press.

### Disable Control

Components set with [Disable Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-enable.md), including their sub-components, will not initiate the touch test process and will directly return to the parent node to continue touch testing.

### Touch Hotspot Settings

[Touch Hotspot Settings](../reference/apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md) will affect the touch test of touch screen/mouse classes, if set to 0, or an area that is not touchable, then the event will directly return to the parent node to continue touch testing.

### Safe Components

Safe components included in ArkUI are: [Using Position Components](../security/AccessToken/locationbutton.md), [Using Paste Components](../security/AccessToken/pastebutton.md), [Using Save Components](../security/AccessToken/savebutton.md), etc.

The current impact of safe components on touch testing: If there is a component that is in front of the safe component in the z-order and covers the safe component, then the safe component event will directly return to the parent node to continue touch testing.

## Collection of Event Response Chain

The collection of the ArkUI event response chain is based on the subsequent traversal process of the right subtree (according to the layout order of the components), and the process is:

```
foreach(item=>(node.rbegin(),node.rend(){
    item.TouchTest()
}
node.collectEvent()
```

An example of the collection of the response chain, if the hitTestBehavior properties of the component tree in the following figure are all default, and the user's tapping action occurs on component 5, then the final collected response chain and the order of relationship are 5, 3, 1.

Because the hitTestBehavior property of component 3 is default, after collecting the event, it will block the sibling nodes, so the left subtree of component 1 is not collected.

  ![EventResponseChain](figures/EventResponseChain.png)
