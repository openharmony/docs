# Graph Drawing

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyujie43-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=2fe06c91e0a27d15dbfdba21fc4a3873ff6d81b0 translatedAt=2026-08-05T10:14:14.974Z pushedAt=2026-08-06T07:17:25.988Z -->

The **svg** component can be used to draw common shapes and line segments, such as rectangles (&lt;rect&gt;), circles (&lt;circle&gt;), and lines (&lt;line&gt;). For details about supported shape styles, refer to [svg](../reference/apis-arkui/arkui-js/js-components-svg.md).

The following example demonstrates how to draw different shapes and stitch them to form a house graph.

```html
<!-- xxx.hml -->
<div class="container">
  <svg width="1000" height="1000">
    <polygon points="100,400 300,200 500,400" fill="red"></polygon>     // Roof
    <polygon points="375,275 375,225 425,225 425,325" fill="orange"></polygon>   // Chimney
    <rect width="300" height="300" x="150" y="400" fill="orange">      // House
    </rect>
    <rect width="100" height="100" x="180" y="450" fill="white">    //Window
    </rect>
    <line x1="180" x2="280" y1="500" y2="500" stroke-width="4" fill="white" stroke="black"></line>     // Window frame
    <line x1="230" x2="230" y1="450" y2="550" stroke-width="4" fill="white" stroke="black"></line>     // Window frame
    <polygon points="325,700 325,550 400,550 400,700" fill="red"></polygon>     // Door
    <circle cx="380" cy="625" r="20" fill="black"></circle>      // Doorknob
  </svg>
</div>
```


```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
}
```

![Graph-Drawing](figures/Graph-Drawing.png)