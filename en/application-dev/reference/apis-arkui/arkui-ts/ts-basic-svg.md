# SVG Tags

Scalable Vector Graphics (SVG) is an XML-based graphics format for describing two-dimensional graphics and images. The **Image** component supports a subset of the SVG 1.1 specification. The supported tags and attributes are as follows.

## Basic Shapes

The basic shape tags include the following: \<rect\>, \<circle\>, \<ellipse\>, \<line\>, \<polyline\>, \<polygon\>, \<path\>

>  **NOTE**
>
>  Basic tags support the following universal attributes:
>  id, fill, fill-rule, fill-opacity, stroke, stroke-dasharray, stroke-dashoffset, stroke-opacity, stroke-width, stroke-linecap, stroke-linejoin, stroke-miterlimit, opacity, transform, clip-path, clip-rule

| Element| Description| Unique Attribute|
| :-------- | :-------- | :-------- |
| \<rect\> | Rectangle| **x**: x-axis offset.<br>**y**: y-axis offset.<br>**width**: width.<br>**height**: height.<br>**rx**: corner radius on the x-axis.<br>**ry**: corner radius on the y-axis.|
| \<circle\> | Circle| **cx**: X coordinate of the circle center.<br> **cy**: Y coordinate of the circle center.<br> **r**: radius of the circle.|  |
| \<ellipse\> | Ellipse| **cx**: X coordinate.<br> **cy**: Y coordinate.<br> **rx**: x-axis radius.<br> **ry**: y-axis radius.|  |
| \<line\> | Line| **x1**: X coordinate of the start point.<br> **y1**: Y coordinate of the start point.<br> **x2**: X coordinate of the end point.<br> **y2**: Y coordinate of the end point.|  |
| \<polyline\> | Polyline| **points**: vertex coordinates.|  |
| \<polygon\> | Polygon| **points**: vertex coordinates.|  |
| \<path\> | Path| **d**: path.|  |

## Graphic Effects

### Filters

The filter tags include the following: \<filter\>, \<feOffset\>, \<feGaussianBlur\>, \<feBlend\>, and \<. The tags are feComposite\>, \<feColorMatrix\>, \<feFlood\>, where \<filter\> defines the filter area, and other tags define filter effects.

| Element| Description| Unique Attribute|
| :-------- | :-------- | :-------- |
| \<filter\> | Defines the filter area.| **x**: x-axis offset of the filter area, with the default value of **0**.<br>**y**: y-axis offset of the filter area, with the default value of **0**.<br>**width**: width of the filter area.<br>**height**: height of the filter area.|
| \<feOffset\> | Defines the offset distance along x-axis and y-axis.| **in**: filter input, which can be SourceGraphic, SourceAlpha, or result from other filter effects.<br> **result**: output after filter processing, which can be used as input for the next filter. The value can include dx and dy.|
| \<feGaussianBlur\> | Defines the Gaussian blur effect.| **in**: filter input, which can be SourceGraphic, SourceAlpha, or result from other filter effects.<br> **result**: output after filter processing, which can be used as input for the next filter. The value can include edgemode and stddeviation.|
| \<feBlend\> | Defines the blending mode for two input images.| **in**: filter input, which can be SourceGraphic, SourceAlpha, or result from other filter effects.<br> **result**: output after filter processing, which can be used as input for the next filter.<br>**in2**: second image source, which can be SourceGraphic, SourceAlpha, or result from other filter effects; mode|
| \<feComposite\> | Defines composition of two input images.<br>Algorithm: result = k1 * in * in2 + k2 * in + k3 * in2 + k4| **in**: filter input, which can be SourceGraphic, SourceAlpha, or result from other filter effects.<br>**in2**: second image source, which can be SourceGraphic, SourceAlpha, or result from other filter effects; operator( over \| in \| out \| atop \| xor \| lighter \| arithmetic ), k1, k2, k3, k4.|
| \<feColorMatrix\> | Transforms colors based on a transformation matrix.| **in**: filter input, which can be SourceGraphic, SourceAlpha, or result from other filter effects.<br> **result**: output after filter processing, which can be used as input for the next filter.<br>type ( matrix \| saturate \| hueRotate ), values.|
| \<feFlood\> | Defines the fill color and opacity.| **in**: filter input, which can be SourceGraphic, SourceAlpha, or result from other filter effects.<br> **result**: output after filter processing, which can be used as input for the next filter; flood-color and flood-opacity.|

### Masks

The mask tags include the following: \<mask\>
| Element| Description| Unique Attribute|
| :-------- | :-------- | :-------- |
| \<mask\> | Defines the mask area.| **x**: x-axis offset of the mask area.<br>**y**: y-axis offset of the mask area.<br>**width**: width of the mask area<br>**height**: height of the mask area.|

### Clipping

The clipping tags include the following: \<clippath\>
| Element| Description| Unique Attribute|
| :-------- | :-------- | :-------- |
| \<clippath\> | Defines a clipping path.| **x**: x-axis offset of the clipping area.<br>**y**: y-axis offset of the clipping area.<br>**width**: width of the clipping area.<br>**height**: height of the clipping area.|

### Patterns

The pattern tags include the following: \<pattern\>
| Element| Description| Unique Attribute|
| :-------- | :-------- | :-------- |
| \<pattern\> | Defines a fill pattern.| **x**: x-axis offset of the fill area.<br>**y**: y-axis offset of the fill area.<br>**width**: width of the fill area.<br>**height**: height of the fill area.|

### Gradients

The gradient tags include the following: \<linearGradient\>, \<radialGradient\>, \<stop\>.

| Element| Description| Unique Attribute|
| :-------- | :-------- | :-------- |
| \<linearGradient\> | Linear gradient.| x1, y1, x2, y2|
| \<radialGradient\> | Radial gradient.| fx, fy, cx, cy, r|
| \<stop\> | Color stop.| offset, stop-color|

## Static Images

The image tags include the following: \<image\>
| Element| Description| Unique Attribute|
| :-------- | :-------- | :-------- |
| \<image\> | Displays an image.| **x**: x-axis offset of the image.<br> **y**: y-axis offset of the image.<br> **width**: width of the image.<br> **height**: height of the image.<br> **href**: target image, which can be in JPG, JPEG, PNG, BMP, WEBP, HEIC, or base64 format (SVG is not supported).|

## Animation

The animation tags include the following: \<animate\>, \<animateTransform\>
| Element| Description| Unique Attribute|
| :-------- | :-------- | :-------- |
| \<animate\> | Defines a property animation.| **attributeName**: animatable attribute; values: (cx\| cy \| r \| fill \| stroke \| fill-opacity \| stroke-opacity \| stroke-miterlimit)<br>**begin**: animation start time.<br> **dur**: animation duration.<br>**from**: start value.<br>**to**: end value.<br>**fill**: end state of the animation.<br> **calcMode**: interpolation.<br> keyTimes, values, keySplines |
| \<animateTransform\> | Defines a transformation animation.| **attributeName**: animatable attribute; value: transform<br>**type**: transformation type; values: (translate \| scale \| rotate \| skewX \| skewY);<br>**begin**: animation start time.<br> **dur**: animation duration.<br>**from**: start value.<br>**to**: end value.<br>**fill**: end state of the animation.<br> **calcMode**: interpolation.<br> keyTimes, values, keySplines|

> **NOTE**
>
> Currently, only single element attribute or transformation animations are supported, not nested animations between elements.

## Other

In addition to tags that identify graphic and image effects, there are also grouping and other tags, including the following:
\<svg\>, \<g\>, \<use\>, \<defs\>

| Element| Description| Unique Attribute| Universal Attribute|
| :-------- | :-------- | :-------- | :-------- |
| \<svg\> | Defines an SVG segment.| **x**: x-axis offset.<br> **y**: y-axis offset.<br> **width**: width.<br>**height**: height.<br> **viewBox**: viewport.| fill, fill-rule, fill-opacity, stroke, stroke-dasharray, stroke-dashoffset, stroke-opacity, stroke-width, stroke-linecap, stroke-linejoin, stroke-miterlimit, transform|
| \<g\> | Groups other SVG elements.| **x**: x-axis offset.<br> **y**: y-axis offset.<br> **width**: width.<br> **height**: height.| fill, fill-rule, fill-opacity, stroke, stroke-dasharray, stroke-dashoffset, stroke-opacity, stroke-width, stroke-linecap, stroke-linejoin, stroke-miterlimit, transform|
| \<use\> | Reuses existing elements.| **x**: x-axis offset.<br> **y**: y-axis offset.<br>**href**: target element.| fill, fill-rule, fill-opacity, stroke, stroke-dasharray, stroke-dashoffset, stroke-opacity, stroke-width, stroke-linecap, stroke-linejoin, stroke-miterlimit, transform|
| \<defs\> | Defines reusable objects.| | |

> **NOTE**
>
> Currently supported color value formats include #rgb, #rrggbb, rgb(), rgba(), and common color keywords (such as red, black, blue, and more).