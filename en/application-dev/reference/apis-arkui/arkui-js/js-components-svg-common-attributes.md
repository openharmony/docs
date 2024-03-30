# Universal Attributes

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| fill | &lt;color&gt; | black | No| Fill color of an element using the shorthand attribute. Attribute animations are supported.|
| fill-opacity | number | 1 | No| Opacity of a fill color. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent. Attribute animations are supported.|
| fill-rule | nonzero&nbsp;\|&nbsp;evenodd | nonzero | No| Fill rule.<br>**nonzero**: non-zero rule.<br>**evenodd**: parity rule.|
| opacity | number | 1 | No| Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent. Attribute animations are supported.|
| stroke | &lt;color&gt; | - | No| Color of the stroke. Attribute animations are supported.|
| stroke-dasharray | &lt;string&gt; | - | No| Length of the dashes and notches. The format is [length length length length]. The length values of dashes and notches are separated by a space and appear in pairs.|
| stroke-dashoffset | &lt;length&gt; | 0 | No| Offset for rendering the associated dash line array. Attribute animations are supported.|
| stroke-linejoin | [bevel&nbsp;\|&nbsp;miter&nbsp;\|&nbsp;round] | miter | No| The shape used at the corner of a path when stroked.<br>**bevel**: connects paths with bevel corners.<br>**miter**: connects paths with mitered corners.<br>**round**: connects paths with rounded corners.|
| stroke-linecap | [butt&nbsp;\|&nbsp;round&nbsp;\|&nbsp;square] | butt | No| The shape used at the end of paths when stroked.<br>**butt**: The stroke for each path does not extend beyond its two endpoints.<br>**round**: At the end of each path the stroke is extended by a half circle with a diameter equal to the stroke width.<br>**square**: At the end of each path the stroke is extended by a half circle, with the width being equal to half of the stroke width, and the height being equal to the stroke width.|
| stroke-miterlimit | number | 4 | No| Limit value when the sharp angle is drawn as a miter. Attribute animations are supported.|
| stroke-opacity | number | 1 | No| Opacity of the stroke. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent. Attribute animations are supported.|
| stroke-width | &lt;length&gt; | 1px | No| Stroke width. Attribute animations are supported.|
| transform | &lt;string&gt; | - | No| Coordinate transformation parameters of the component and its child components.<br>The following formats are supported:<br>**translate(\<x> [\<y>])**: translates along the x[y]-axis.<br>**scale(\<x> [\<y>])**: scales along the x[y]-axis.<br>**rotate(\<a> [\<x> \<y>])**: rotates at an angle of **a** with point (x,y) as the center.<br>**skewX(\<a>)**: skews at an angle of **a** along the x-axis.<br>**skewY(\<a>)**: skews at an angle of **a** along the y-axis. |
