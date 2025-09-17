# Interfaces (Others)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This module uses the physical pixel unit, px.
>
> - The module operates under a single-threaded model. The caller needs to manage thread safety and context state transitions.

## TextBlobRunBuffer

Describes a series of consecutive glyphs with the same attributes in a text blob.

**System capability**: SystemCapability.Graphics.Drawing

| Name     | Type  | Read-Only| Optional| Description                     |
| --------- | ------ | ---- | ---- | ------------------------- |
| glyph     | number | No  | No  | Index of the glyph. The value is an integer. If a floating point number is passed in, the value is rounded down.|
| positionX | number | No  | No  | X coordinate of the start point of the text blob. The value is a floating point number.|
| positionY | number | No  | No  | Y coordinate of the start point of the text blob. The value is a floating point number.|

## FontMetrics

Describes the attributes that describe the font size and layout. A typeface has similar font metrics.

**System capability**: SystemCapability.Graphics.Drawing

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| flags<sup>12+</sup>   | [FontMetricsFlags](arkts-apis-graphics-drawing-e.md#fontmetricsflags12) | No  | Yes  | Font measurement flags that are valid.       |
| top     | number | No  | No  | Maximum distance from the baseline to the highest coordinate of the text. The value is a floating point number.                        |
| ascent  | number | No  | No  | Distance from the baseline to the highest coordinate of the text. The value is a floating point number.                            |
| descent | number | No  | No  | Distance from the baseline to the lowest coordinate of the text. The value is a floating point number.                            |
| bottom  | number | No  | No  | Maximum distance from the baseline to the lowest coordinate of the text. The value is a floating point number.                        |
| leading | number | No  | No  | Interline spacing, that is, the distance from the descent of one line of text to the ascent of the next line. The value is a floating point number.|
| avgCharWidth<sup>12+</sup> | number | No  | Yes  | Average character width.                            |
| maxCharWidth<sup>12+</sup> | number | No  | Yes  | Maximum character width.                            |
| xMin<sup>12+</sup> | number | No   | Yes  | Horizontal distance from the leftmost edge of any glyph bounding box to the origin. This value is usually less than 0, indicating the minimum horizontal coordinate across all glyph bounding boxes.               |
| xMax<sup>12+</sup> | number | No  | Yes  | Horizontal distance from the rightmost edge of any glyph bounding box to the origin. The value is a positive number, indicating the maximum horizontal coordinate across all glyph bounding boxes.       |
| xHeight<sup>12+</sup> | number | No  | Yes  | Height of the lowercase letter x. The value is usually a negative value.                    |
| capHeight<sup>12+</sup> | number | No  | Yes  | Height of a capital letter. The value is usually a negative value.                     |
| underlineThickness<sup>12+</sup> | number | No  | Yes  | Thickness of the underline.                                         |
| underlinePosition<sup>12+</sup>  | number | No  | Yes  | Vertical distance from the baseline to the top of the underline. The value is usually a positive number.            |
| strikethroughThickness<sup>12+</sup>  | number | No  | Yes  | Thickness of the strikethrough.   |
| strikethroughPosition<sup>12+</sup>  | number | No  | Yes  | Vertical distance from the baseline to the bottom of the strikethrough. The value is usually a negative value.        |

## FontFeature<sup>20+</sup>

Defines font features, which are typesetting rules within a font that determine how glyphs look, such as ligatures, alternates, and superscripts/subscripts.

**System capability**: SystemCapability.Graphics.Drawing

| Name   | Type  | Read-Only| Optional| Description  |
| ------- | ------ | ---- | ---- | ------------------ |
| name   | string | No  | No  | Name of a font feature. Common font feature names include **liga**, **frac**, and **case**. A font feature needs a TTF file to work.|
| value | number | No| No| Value of a font feature, which is a floating point number. You are advised to determine the valid value range by using a font viewing tool or referring to the font document.|
