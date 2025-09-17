# Module Description

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

During application development, you often need to draw different elements. Typically, you can use ArkUI components to draw the desired elements or effects. However, sometimes these components cannot meet the needs for custom graphics or effects. In such cases, you can turn to the Drawing module for flexible custom drawing. This module provides basic drawing capabilities, such as drawing rectangles, circles, points, straight lines, custom paths, and fonts.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This module uses the physical pixel unit, px.
>
> - The module operates under a single-threaded model. The caller needs to manage thread safety and context state transitions.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```
