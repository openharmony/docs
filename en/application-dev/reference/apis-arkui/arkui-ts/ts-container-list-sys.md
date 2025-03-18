# List (System API)

The **List** component provides a list container that presents a series of list items arranged in a column with the same width. It supports presentations of the same type of data in a multiple and coherent row style, for example, images or text.

> **NOTE**
>
> - This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [List](ts-container-list.md).

## Attributes

### chainAnimationOptions<sup>10+</sup>

chainAnimationOptions(value: ChainAnimationOptions)

Sets chained animation options.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                    | Description                          |
| ------ | ---------------------------------------- | ---------------------------------- |
| value  | [ChainAnimationOptions](#chainanimationoptions10) | Chained animation options.|

## ChainEdgeEffect<sup>10+</sup>

Describes the chained animation edge scrolling effect.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     |  Value | Description                                      |
| ------- | ------ | ---------------------------------------- |
| DEFAULT | 0 | Default effect. After the list is scrolled to the edge, a continued drag of the list will result in reduced spacing between the list items in the drag direction and<br>increased spacing between the list items in the direction opposite to the drag direction.|
| STRETCH | 1 | After the list is scrolled to the edge, a continued drag of the list result in increased spacing between all the list items.                |

## chainAnimationOptions<sup>10+</sup>

Provides the chained animation settings, which cover the maximum spacing, minimum spacing, intensity, conductivity, and edge scrolling effect.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name          | Type                                      | Mandatory  | Description                                      |
| ------------ | ---------------------------------------- | ---- | ---------------------------------------- |
| minSpace     | [Length](ts-types.md#length)             | Yes   | Minimum spacing between the chained animations.                           |
| maxSpace     | [Length](ts-types.md#length)             | Yes   | Maximum spacing between the chained animations.                           |
| conductivity | number                                   | No   | Conductivity of the chained animations. The value range is [0,1]. A larger value indicates higher conductivity.<br>Default value: **0.7**|
| intensity    | number                                   | No   | Intensity of the chained animations. The value range is [0,1]. A larger value indicates more obvious animations.<br>Default value: **0.3**|
| edgeEffect   | [ChainEdgeEffect](#chainedgeeffect10)| No   | Chained animation edge scrolling effect.<br>Default value: **ChainEdgeEffect.DEFAULT**|
| stiffness    | number                                   | No   | Stiffness of the chained animations.<br>Default value: **228**|
| damping      | number                                   | No   | Damping of the chained animations.<br>Default value: **30**|
