# chart

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

The **\<chart>** component displays line charts, gauge charts, and bar charts.

## Required Permissions

None


## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name                            | Type                                      | Default Value | Mandatory  | Description                                      |
| ------------------------------ | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| type                           | string                                   | line | No   | Chart type. Dynamic modification is not supported. Available values include:<br>- **bar**: bar chart<br>- **line**: line chart<br>- **gauge**: gauge chart<br>- **progress**<sup>5+</sup>: circle chart of progresses<br>- **loading**<sup>5+</sup>: circle chart of loading processes<br>- **rainbow**<sup>5+</sup>: circle chart of proportions|
| options                        | ChartOptions                             | -    | No   | Chart parameters. You must set parameters for bar charts and line charts. Parameter settings for gauge charts do not take effect. You can set the minimum value, maximum value, scale, and line width of the x-axis or y-axis, whether to display the x-axis and y-axis, and whether the line is smooth. Dynamic modification is not supported.|
| datasets                       | Array&lt;ChartDataset&gt;                | -    | No   | Data sets. You must set data sets for bar charts and line charts. Data sets for a gauge chart do not take effect. You can set multiple datasets and their background colors.|
| segments<sup>5+</sup>          | DataSegment \| Array&lt;DataSegment&gt; | -    | No   | Data structures used by **progress**, **loading**, and **rainbow** charts.<br>**DataSegment** is available for **progress** and **loading** charts.<br>**Array&lt;DataSegment&gt;** is available for **rainbow** charts. A maximum of nine **DataSegment**s are supported in the array.|
| effects<sup>5+</sup>           | boolean                                  | true | No   | Whether to enable the effects for **progress** and **rainbow** charts.                      |
| animationduration<sup>6+</sup> | number                                   | 3000 | No   | Animation duration for expanding a **rainbow** chart, in milliseconds.                  |

**Table 1** ChartOptions

| Name    | Type         | Default Value | Mandatory  | Description                                      |
| ------ | ----------- | ---- | ---- | ---------------------------------------- |
| xAxis  | ChartAxis   | -    | Yes   | X-axis parameters. You can set the minimum value, maximum value, and scale of the x-axis, and whether to display the x-axis.         |
| yAxis  | ChartAxis   | -    | Yes   | Y-axis parameters. You can set the minimum value, maximum value, and scale of the y-axis, and whether to display the y-axis.         |
| series | ChartSeries | -    | No   | Data sequence parameters. Only line charts support this attribute.<br>- Line style, such as the line width and whether the line is smooth.<br>- Style and size of the white point at the start of the line.|

**Table 2** ChartDataset

| Name         | Type                                      | Default Value     | Mandatory  | Description                    |
| ----------- | ---------------------------------------- | -------- | ---- | ---------------------- |
| strokeColor | &lt;color&gt;                            | \#ff6384 | No   | Stroke color. Only line charts support this attribute.         |
| fillColor   | &lt;color&gt;                            | \#ff6384 | No   | Fill color.<br>For line charts, the value indicates the gradient color to fill.|
| data        | Array&lt;number&gt; \| Array&lt;Point&gt;<sup>5+</sup> | -        | Yes   | Data of the drawn line or bar.          |
| gradient    | boolean                                  | false    | No   | Whether to display the gradient color. Only line charts support this attribute.   |

**Table 3** ChartAxis

| Name      | Type           | Default Value     | Mandatory  | Description                                      |
| -------- | ------------- | -------- | ---- | ---------------------------------------- |
| min      | number        | 0        | No   | Minimum value of the axis. Only line charts support negative numbers.                         |
| max      | number        | 100      | No   | Maximum value of the axis. Only line charts support negative numbers.                         |
| axisTick | number        | 10       | No   | Number of scales displayed on the axis. The value ranges from 1 to 20. The display effect depends on the calculation result of Number of pixels occupied by the image width/(**max** – **min**).<br>In the bar chart, the number of bars in each group of data is the same as the number of scales, and the bars are displayed at the scales.|
| display  | boolean       | false    | No   | Whether to display the axis.                                  |
| color    | &lt;color&gt; | \#c0c0c0 | No   | Axis color.                                    |

**Table 4** ChartSeries

| Name         | Type            | Default Value | Mandatory  | Description                  |
| ----------- | -------------- | ---- | ---- | -------------------- |
| lineStyle   | ChartLineStyle | -    | No   | Line style, such as the line width and whether the line is smooth.     |
| headPoint   | PointStyle     | -    | No   | Style and size of the white point at the start of the line.     |
| topPoint    | PointStyle     | -    | No   | Style and size of the top point.          |
| bottomPoint | PointStyle     | -    | No   | Style and size of the bottom point.          |
| loop        | ChartLoop      | -    | No   | Whether to start drawing again when the screen is looped.|

**Table 5** ChartLineStyle

| Name    | Type            | Default Value  | Mandatory  | Description   |
| ------ | -------------- | ----- | ---- | ----- |
| width  | &lt;length&gt; | 1px   | No   | Line width.|
| smooth | boolean        | false | No   | Whether the line is smooth.|

**Table 6** PointStyle

| Name         | Type            | Default Value     | Mandatory  | Description                                      |
| ----------- | -------------- | -------- | ---- | ---------------------------------------- |
| shape       | string         | circle   | No   | Shape of the highlight point. Available values are as follows:<br>- circle<br>- square<br>- triangle|
| size        | &lt;length&gt; | 5px      | No   | Size of the highlight point.                                 |
| strokeWidth | &lt;length&gt; | 1px      | No   | Stroke width.                                    |
| strokeColor | &lt;color&gt;  | \#ff0000 | No   | Stroke color.                                   |
| fillColor   | &lt;color&gt;  | \#ff0000 | No   | Fill color.                                   |

**Table 7** ChartLoop

| Name      | Type            | Default Value  | Mandatory  | Description                                      |
| -------- | -------------- | ----- | ---- | ---------------------------------------- |
| margin   | &lt;length&gt; | 1     | No   | Number of erased points (horizontal distance between the latest drawn point and the earliest point). You are not advised to use **margin** together with **topPoint**, **bottomPoint**, or **headPoint** for mini-, small- and standard-system devices. If you do so, there is a possibility that the point is in the erase area and invisible.|
| gradient | boolean        | false | No   | Whether to perform gradient erase.                               |

**Table 8** Point<sup>5+</sup>

| Name          | Type           | Default Value     | Mandatory  | Description                                      |
| ------------ | ------------- | -------- | ---- | ---------------------------------------- |
| value        | number        | 0        | Yes   | Y coordinate of the point to draw.                             |
| pointStyle   | PointStyle    | -        | No   | Style of the point.                           |
| description  | string        | -        | No   | Description text of the point.                             |
| textLocation | string        | -        | No   | Position of the description text relative to the point. Available values are as follows: **top**: above the point<br>**bottom**: below the point<br>**none**: not displayed|
| textColor    | &lt;color&gt; | \#000000 | No   | Color of the description text.                              |
| lineDash     | string        | solid    | No   | Dashed line pattern. You can set the dash length and space length between the dashes. - **"dashed, 5, 5"**: dashed line with each dash in 5 px and a 5 px space between each two dashes. Default value **"solid"** indicates a solid line.|
| lineColor    | &lt;color&gt; | \#000000 | No   | Line color. If this attribute is not set, the value of **strokeColor** is used.  |

**Table 9** DataSegment<sup>5+</sup>

| Name        | Type    | Default Value | Mandatory  | Description                                      |
| ---------- | ------ | ---- | ---- | ---------------------------------------- |
| startColor | Color  | -    | No   | Color of the start position. If this attribute is set, **endColor** must be set. If this attribute is not set, the default color array preset in the system is used. For details about the color values, see the next table.|
| endColor   | Color  | -    | No   | Color of the end position. If this attribute is set, **startColor** must be set.<br>If this attribute is not set, the default color array preset in the system is used.|
| value      | number | 0    | Yes   | Percentage for the data segment. The maximum value is **100**.                        |
| name       | string | -    | No   | Name of the data segment.                                |

| Data Segment | Light Mode                       | Dark Mode                       |
| ---- | --------------------------- | --------------------------- |
| 0    | Start color: \#f7ce00; end color: \#f99b11| Start color: \#d1a738; end color: \#eb933d|
| 1    | Start color: \#f76223; end color: \#f2400a| Start color: \#e67d50; end color: \#d9542b|
| 2    | Start color: \#f772ac; end color: \#e65392| Start color: \#d5749e; end color: \#d6568d|
| 3    | Start color: \#a575eb; end color: \#a12df7| Start color: \#9973d1; end color: \#5552d9|
| 4    | Start color: \#7b79f7; end color: \#4b48f7| Start color: \#7977d9; end color: \#f99b11|
| 5    | Start color: \#4b8af3; end color: \#007dff| Start color: \#4c81d9; end color: \#217bd9|
| 6    | Start color: \#73c1e6; end color: \#4fb4e3| Start color: \#5ea6d1; end color: \#4895c2|
| 7    | Start color: \#a5d61d; end color: \#69d14f| Start color: \#91c23a; end color: \#70ba5d|
| 8    | Start color: \#a2a2b0; end color: \#8e8e93| Start color: \#8c8c99; end color: \#6b6b76|

For the **gauge** charts, the following attributes are also supported.

| Name     | Type    | Default Value | Mandatory  | Description                    |
| ------- | ------ | ---- | ---- | ---------------------- |
| percent | number | 0    | No   | Percentage of the current value to the total value. The value ranges from 0 to 100.|


## Styles



In addition to the [universal styles](js-components-common-styles.md), the following styles are supported.

| Name                      | Type            | Default Value                       | Mandatory  | Description                                      |
| ------------------------ | -------------- | -------------------------- | ---- | ---------------------------------------- |
| stroke-width             | &lt;length&gt; | 32px (**gauge** charts)<br>24px (**rainbow** charts)| No   | Width of the scale bar for **gauge** and **rainbow** charts.                     |
| start-angle              | &lt;deg&gt;    | 240 (**gauge** charts)<br>0 (**rainbow** charts)    | No   | Start angle of the scale bar for **gauge** and **rainbow** charts, which starts from zero o'clock. The value ranges from 0 to 360.  |
| total-angle              | &lt;deg&gt;    | 240 (**gauge** charts)<br>360 (**rainbow** charts)  | No   | Total length of the scale bar for **gauge** and **rainbow** charts. The value ranges from –360 to 360. A negative number indicates the anticlockwise direction.|
| center-x                 | &lt;length&gt; | -                          | No   | Center of the scale bar of the gauge component. This style is supported by the gauge chart only. This style takes precedence over the **position** style in the common styles, and must be used together with **center-y** and **radius**. This style is supported by the gauge chart only.|
| center-y                 | &lt;length&gt; | -                          | No   | Center of the scale bar of the gauge component. This style is supported by the gauge chart only. This style takes precedence over the **position** style in the common styles, and must be used together with **center-x** and **radius**. This style is supported by the gauge chart only.|
| radius                   | &lt;length&gt; | -                          | No   | Radius of the scale bar of the gauge component. This style is supported by the gauge chart only. This style takes precedence over the **width** and **height** in the common styles, and must be used together with **center-x** and **center-y**. This style is supported by the gauge chart only.|
| colors                   | Array          | -                          | No   | Color of each section for the scale bar of the gauge component.<br>For example, **colors: \#ff0000, \#00ff00**. This style is supported by the gauge chart only.|
| weights                  | Array          | -                          | No   | Weight of each section for the scale bar of the gauge component.<br>For example, **weights: 2, 2**. This style is supported by the gauge chart only.|
| font-family<sup>5+</sup> | Array          | -                          | No   | Font style of the description text. You can use a [custom font](js-components-common-customizing-font.md).|
| font-size<sup>5+</sup>   | &lt;length&gt; | -                          | No   | Font size of the description text.                           |


## Events

The [universal events](js-components-common-events.md) are supported.


## Methods

In addition to the [universal methods](js-components-common-methods.md), the following methods are supported.

| Name    | Parameter                                      | Description                                      |
| ------ | ---------------------------------------- | ---------------------------------------- |
| append | {<br>serial: number, <br>data: Array&lt;number&gt;, <br>} | Data is dynamically added to an existing data sequence. The target sequence is specified based on **serial**, which is the subscript of the datasets array and starts from 0. For example, if the value of **serial** is **index**, use **data** to update **datasets[index].data**. Only line charts support this attribute. The value is incremented by 1 based on the horizontal coordinate and is related to the **xAxis min/max** setting.|

## Example

1. Line chart
   ```html
   <!-- xxx.hml -->
   <div class="container">
     <stack class="chart-region">
       <image class="chart-background" src="common/background.png"></image>
       <chart class="chart-data" type="line" ref="linechart" options="{{lineOps}}" datasets="{{lineData}}"></chart>
     </stack>
     <button value="Add data" onclick="addData"></button>
   </div>
   ```

   ```css
   /* xxx.css */
   .container {
     flex-direction: column;
     justify-content: center;
     align-items: center;
   }
   .chart-region {
     height: 400px;
     width: 700px;
   }
   .chart-background {
     object-fit: fill;
   }
   .chart-data {
     width: 700px;
     height: 600px;
   }
   button {
     width: 100%;
     height: 50px;
     background-color: #F4F2F1;
     text-color: #0C81F3;
   }
   ```

   ```js
   // xxx.js
   export default {
     data: {
       lineData: [
         {
           strokeColor: '#0081ff',
           fillColor: '#cce5ff',
           data: [763, 550, 551, 554, 731, 654, 525, 696, 595, 628, 791, 505, 613, 575, 475, 553, 491, 680, 657, 716],
           gradient: true
         }
       ],
       lineOps: {
         xAxis: {
           min: 0,
           max: 20,
           display: false
         },
         yAxis: {
           min: 0,
           max: 1000,
           display: false
         },
         series: {
           lineStyle: {
             width: "5px",
             smooth: true
           },
           headPoint: {
             shape: "circle",
             size: 20,
             strokeWidth: 5,
             fillColor: '#ffffff',
             strokeColor: '#007aff',
             display: true
           },
           loop: {
             margin: 2,
             gradient: true
           }
         }
       }
     },
     addData() {
       this.$refs.linechart.append({
         serial: 0,
         data: [Math.floor(Math.random() * 400) + 400]
       })
     }
   }
   ```

   ![en-us_image_0000001173324843](figures/en-us_image_0000001173324843.png)

2. Bar chart
   ```html
   <!-- xxx.hml -->
   <div class="container">
     <stack class="data-region">
       <image class="data-background" src="common/background.png"></image>
       <chart class="data-bar" type="bar" id="bar-chart" options="{{barOps}}" datasets="{{barData}}"></chart>
     </stack>
   </div>
   ```

   ```css
   /* xxx.css */
   .container {
     flex-direction: column;
     justify-content: center;
     align-items: center;
   }
   .data-region {
     height: 400px;
     width: 700px;
   }
   .data-background {
     object-fit: fill;
   }
   .data-bar {
     width: 700px;
     height: 400px;
   }
   ```

   ```js
   // xxx.js
   export default {
     data: {
       barData: [
         {
           fillColor: '#f07826',
           data: [763, 550, 551, 554, 731, 654, 525, 696, 595, 628]
         },
         {
           fillColor: '#cce5ff',
           data: [535, 776, 615, 444, 694, 785, 677, 609, 562, 410]
         },
         {
           fillColor: '#ff88bb',
           data: [673, 500, 574, 483, 702, 583, 437, 506, 693, 657]
         },
       ],
       barOps: {
         xAxis: {
           min: 0,
           max: 20,
           display: false,
           axisTick: 10
         },
         yAxis: {
           min: 0,
           max: 1000,
           display: false
         }
       }
     }
   }
   ```

   ![en-us_image_0000001173164929](figures/en-us_image_0000001173164929.png)

3. Gauge chart
   ```html
   <!-- xxx.hml -->
   <div class="container">
     <div class="gauge-region">
       <chart class="data-gauge" type="gauge" percent = "50"></chart>
     </div>
   </div>
   ```

   ```css
   /* xxx.css */
   .container {
     flex-direction: column;
     justify-content: center;
     align-items: center;
   }
   .gauge-region {
     height: 400px;
     width: 400px;
   }
   .data-gauge {
     colors: #83f115, #fd3636, #3bf8ff;
     weights: 4, 2, 1;
   }
   ```

   ![en-us_image_0000001127125264](figures/en-us_image_0000001127125264.png)

4. Circle chart of progresses, loading progresses, or proportions
   ```html
   <!-- xxx.hml -->
   <div class="container">
       <text class="text">progress Example</text>
       <stack class="chart-region">
           <chart class="" type="progress" segments="{{ progressdata }}"></chart>
       </stack>
       <text class="text">loading Example</text>
       <stack class="chart-region">
           <chart class="" type="loading" segments="{{ loadingdata }}"></chart>
       </stack>
       <text class="text">rainbow Example</text>
       <stack class="chart-region">
           <chart class="" type="rainbow" segments="{{ rainbowdata }}" effects="true" animationduration="5000"></chart>
       </stack>
   </div>
   ```
   ```css
   /* xxx.css */
   .container {
       flex-direction: column;
       justify-content: center;
       align-items: center;
   }
   .chart-region {
       height: 400px;
       width: 700px;
       margin-top: 10px;
   }
   .text {
       margin-top: 30px;
   }
   ```
   ```js
   // xxx.js
   export default {
      data: {
         progressdata: {
            value: 50,
            name: 'progress'
         },
         loadingdata: {
            startColor: "#ffc0cb",
            endColor: "#00bfff",
         },
         rainbowdata: [
            {
               value: 50,
               name: 'item1'
            },
            {
               value: 10,
               name: 'item2'
            },
            {
               value: 20,
               name: 'item3'
            },
            {
               value: 10,
               name: 'item4'
            },
            {
               value: 10,
               name: 'item5'
            }
         ]
      }
   }
   ```
   ![rainbow](figures/rainbow.gif)
