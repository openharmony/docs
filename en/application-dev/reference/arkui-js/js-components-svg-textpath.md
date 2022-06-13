# textPath

The  **<textPath\>**  component is used to draw text along the path.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>-   Draws text based on the specified path. The  **tspan**  child component can be nested for segmenting.
>-   **<textPath\>**  can be nested only by the parent element label  **svg**.

## Required Permissions

None

## Child Components

**tspan**  is supported.

## Attributes

The attributes in the following table are supported.

| Name           | Type                     | Default Value | Mandatory | Description                                                  |
| -------------- | ------------------------ | ------------- | --------- | ------------------------------------------------------------ |
| id             | string                   | -             | No        | Unique ID of the component.                                  |
| path           | string                   | 0             | Yes       | Shape of the path.<br/>The meanings of the letters are as follows:<br/>- M = moveto<br/>- L = lineto<br/>- H = horizontal lineto<br/>- V = vertical lineto<br/>- C = curveto<br/>- S = smooth curveto<br/>- Q = quadratic Belzier curve<br/>- T = smooth quadratic Belzier curveto<br/>- A = elliptical Arc<br/>- Z = closepath |
| startOffset    | \<length>\|\<percentage> | 0             | No        | Start offset of the text drawing along the path.             |
| font-size      | \<length>                | 30px          | No        | Font size.                                                   |
| fill           | \<color>                 | black         | No        | Font fill color.                                             |
| by             | number                   | -             | No        | Attribute offset relative to the specified animation. The default value of **from** is the original attribute value. |
| opacity        | number                   | 1             | No        | Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent. Attribute animations are supported. |
| fill-opacity   | number                   | 1.0           | No        | Font fill opacity.                                           |
| stroke         | \<color>                 | black         | No        | Stroke and stroke color.                                     |
| stroke-width   | number                   | 1px           | No        | Stroke width.                                                |
| stroke-opacity | number                   | 1.0           | No        | Stroke opacity.                                              |


## Example

The following is an example of the  **textspan**  attribute. The  **textpath**  text is drawn along the path specified by the  **path**  attribute, and the start point is offset by 20% of the  **path**  length. \(The drawn element  **<path\>**  curve is for reference only.\)

```
/* xxx.css */
.container {
    flex-direction: row;
    justify-content: flex-start;
    align-items: flex-start;
    height: 1200px;
    width: 600px;
}
```

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="#00FF00" x="50">
    <path d="M40,360 Q360,360 360,180 Q360,40 200,40 Q40,40 40,160 Q40,280 180,280 Q280,280 300,200" stroke="red" fill="none"></path>
    <text>
      <textpath fill="blue" startOffset="20%" path="M40,360 Q360,360 360,180 Q360,40 200,40 Q40,40 40,160 Q40,280 180,280 Q280,280 300,200" font-size="30px">
        This is textpath test.
      </textpath>
    </text>
  </svg>
</div>
```

![](figures/textpath-part1.png)

Combination of  **textpath**  and  **tspan**

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="#00FF00" x="50">
    <path d="M40,360 Q360,360 360,180 Q360,40 200,40 Q40,40 40,160 Q40,280 180,280 Q280,280 300,200" stroke="red" fill="none"></path>
      <text>
        <textpath fill="blue" startOffset="20%" path="M40,360 Q360,360 360,180 Q360,40 200,40 Q40,40 40,160 Q40,280 180,280 Q280,280 300,200" font-size="15px">
          <tspan dx="-50px" fill="red">This is tspan onTextPath.</tspan>
          <tspan font-size="25px">Let's play.</tspan>
          <tspan font-size="30px" fill="#00FF00">12345678912354567891234567891234567891234567891234567890</tspan>
        </textpath>
      </text>
  </svg>
</div>
```

![](figures/textpath-part2.png)

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="#00FF00" x="50">
    <path d="M40,760 Q360,760 360,580 Q360,440 200,440 Q40,440 40,560 Q40,680 180,680 Q280,680 300,600" stroke="red" fill="none"></path>
    <text>
      <textpath fill="#D2691E" path="M40,760 Q360,760 360,580 Q360,440 200,440 Q40,440 40,560 Q40,680 180,680 Q280,680 300,600"font-size="30px" stroke="black" stroke-width="1" >
        This is TextPath.
        <tspan font-size="20px" fill="red">This is tspan onTextPath.</tspan>
        <tspan font-size="30px">Let's play.</tspan>
        <tspan font-size="40px" fill="#00FF00"  stroke="blue" stroke-width="2">12345678912354567891234567891234567891234567891234567890
        </tspan>
      </textpath>
    </text>
  </svg>
</div>
```

![](figures/textpath-part3.png)

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="#00FF00" x="50">
    <path d="M40,1160 Q360,1160 360,980 Q360,840 200,840 Q40,840 40,960 Q40,1080 180,1080 Q280,1080 300,1000" stroke="red" fill="none">
    </path>
    <!--      Value percentage    -->
    <text>
      <textpath fill="#D2691E" path="M40,1160 Q360,1160 360,980 Q360,840 200,840 Q40,840 40,960 Q40,1080 180,1080 Q280,1080 300,1000" font-size="30px">
        This is TextPath.
        <tspan x="50" fill="blue">This is first tspan.</tspan>
        <tspan x="50%">This is second tspan.</tspan>
        <tspan dx="10%">12345678912354567891234567891234567891234567891234567890</tspan>
      </textpath>
    </text>
  </svg>
</div>
```

![](figures/textpath-part4.png)

The following is an example of the  **startOffset**  animation. When the text is drawn, the start offset is moved from 10% to 40%, and the text whose length exceeds the path length range is not drawn.

```
/* xxx.css */
.container {
    flex-direction: row;
    justify-content: flex-start;
    align-items: flex-start;
    height: 3000px;
    width: 1080px;
}
```

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="#00FF00">
    <path d="M40,360 Q360,360 360,180 Q360,40 200,40 Q40,40 40,160 Q40,280 180,280 Q280,280 300,200" stroke="red" fill="none"></path>
    <text>
      <textpath fill="blue" startOffset="10%" path="M40,360 Q360,360 360,180 Q360,40 200,40 Q40,40 40,160 Q40,280 180,280 Q280,280 300,200" font-size="15px">
        <tspan dx="-50px" fill="red">This is tspan onTextPath.</tspan>
        <tspan font-size="25px">Let's play.</tspan>
        <tspan font-size="30px" fill="#00FF00">12345678912354567891234567891234567891234567891234567890</tspan>
        <animate attributeName="startOffset" from="10%" to="40%" dur="3s" repeatCount="indefinite"></animate>
      </textpath>
    </text>
  </svg>
</div>
```

![](figures/textpath-animate1.gif)

Animation and effect of the combination of  **textpath**  and  **tspan**

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="#00FF00">
    <path d="M40,1160 Q360,1160 360,980 Q360,840 200,840 Q40,840 40,960 Q40,1080 180,1080 Q280,1080 300,1000" stroke="red" fill="none">
    </path>
    <text>
      <textpath fill="#D2691E" path="M40,1160 Q360,1160 360,980 Q360,840 200,840 Q40,840 40,960 Q40,1080 180,1080 Q280,1080 300,1000" font-size="30px">
        This is TextPath.
        <tspan x="50" fill="blue">
          tspan attribute x|rotate
          <animate attributeName="x" from="50" to="100" dur="5s" repeatCount="indefinite"></animate>
          <animate attributeName="rotate" from="0" to="360" dur="5s" repeatCount="indefinite"></animate>
        </tspan>
        <tspan x="30%">tspan static.</tspan>
        <tspan>
          tspan attribute dx|opacity
          <animate attributeName="dx" from="0%" to="30%" dur="3s" repeatCount="indefinite"></animate>
          <animate attributeName="opacity" from="0.01" to="0.99" dur="3s" repeatCount="indefinite"></animate>
        </tspan>
        <tspan dx="5%">tspan move</tspan>
      </textpath>
    </text>
  </svg>
</div>
```

![](figures/textpath-animate2.gif)

\(1\) "tspan attribute x|rotate" indicates that the text drawing start point moves from 50 px to 100 px and rotates clockwise by 0 degrees to 360 degrees.

\(2\) "tspan attribute dx|opacity" is drawn after the "tspan static." drawing is complete. The offset moves from 0% to 30%, and the opacity changes from shallow to deep.

\(3\)  **tspan move**: After the previous  **tspan**  is drawn, the next tspan is drawn with an offset of 5% to show the effect of following the previous  **tspan**.

Animation and effect of the combination of  **textpath**  and  **tspan**

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="#00FF00">
    <path d="M40,1560 Q360,1560 360,1380 Q360,1240 200,1240 Q40,1240 40,1360 Q40,1480 180,1480 Q280,1480 300,1400" stroke="red" 
      fill="none">
    </path>
    <text>
      <textpath fill="#D2691E" path="M40,1560 Q360,1560 360,1380 Q360,1240 200,1240 Q40,1240 40,1360 Q40,1480 180,1480 Q280,1480 300,1400" font-size="30px">
        This is TextPath.
        <tspan dx="20" fill="blue">
          tspan attribute fill|fill-opacity
          <animate attributeName="fill" from="blue" to="red" dur="3s" repeatCount="indefinite"></animate>
          <animate attributeName="fill-opacity" from="0.01" to="0.99" dur="3s" repeatCount="indefinite"></animate>
        </tspan>
        <tspan dx="20" fill="blue">
          tspan attribute font-size
          <animate attributeName="font-size" from="10" to="50" dur="3s" repeatCount="indefinite"></animate>
        </tspan>
      </textpath>
        <tspan font-size="30">Single tspan</tspan>
    </text>
  </svg>
</div>
```

![](figures/textpath-animate3.gif)

\(1\)  **This is TextPath**.: Draw the first paragraph of text on the path without offset. The size is 30px, and the color is "\#D2691E".

\(2\) The value of  **tspan attribute fill|fill-opacity**  is 20px offset from the end of the previous text segment. The color is from blue to red, and the opacity is from light to deep.

\(3\)  **tspan attribute font-size**: The drawing start point is 20px offset from the end of the previous segment. The start point is static, and the font size ranges from 10px to 50px. The overall length is continuously prolonged.

\(4\)  **Single tspan**: Draw a horizontal line at the end of the previous segment to follow the previous segment.

Animation and effect of the combination of  **textpath**  and  **tspan**

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="#00FF00">
    <path d="M40,1960 Q360,1960 360,1780 Q360,1640 200,1640 Q40,1640 40,1760 Q40,1880 180,1880 Q280,1880 300,1800" stroke="red" 
      fill="none">
    </path>
    <text>
      <textpath fill="#D2691E" path="M40,1960 Q360,1960 360,1780 Q360,1640 200,1640 Q40,1640 40,1760 Q40,1880 180,1880 Q280,1880 300,1800" font-size="30px">
          This is TextPath.
          <tspan dx="20" fill="blue">
            tspan attribute stroke
            <animate attributeName="stroke" from="red" to="#00FF00" dur="3s" repeatCount="indefinite"></animate>
          </tspan>
          <tspan dx="20" fill="white" stroke="red">
            tspan attribute stroke-width-opacity
            <animate attributeName="stroke-width" from="1" to="5" dur="3s" repeatCount="indefinite"></animate>
            <animate attributeName="stroke-opacity" from="0.01" to="0.99" dur="3s" repeatCount="indefinite"></animate>
          </tspan>
      </textpath>
    </text>
  </svg>
</div>
```

![](figures/textpath-animate4.gif)

\(1\)  **tspan attribute stroke**: The stroke color gradually changes from red to green.

\(2\)  **tspan attribute stroke-width-opacity**: The contour width is changed from 1px to 5px, and the opacity is changed from shallow to deep.

