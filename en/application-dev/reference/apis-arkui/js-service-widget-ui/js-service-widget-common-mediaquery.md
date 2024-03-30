# Media Query


Media queries are widely used on mobile devices. You can use them to modify the application style based on the device type or specific features and device parameters (such as the screen resolution). Specifically, media queries allow you to:

1. Design a layout style based on the device and app attributes.

2. Update the page layout to adapt to dynamic screen changes (for example, screen splitting or switching between landscape and portrait modes).


> **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> The **media** attribute uses the actual size, physical pixel, and screen resolution of the device by default. Do not confuse them with the configuration based on basic screen width 720 px.


## CSS Syntax Rules

Use **\@media** to import query statements. The rule is as follows:


```css
@media [media-type] [and|not|only] [(media-feature)] {
  CSS-Code;
}
```

Example:

\@media screen and (round-screen: true) { … } // The condition is met when the device screen is round.

\@media (max-height: 800) { … } // Range query. CSS level 3 is used.

\@media (height &lt;= 800) { ... } // Range query. CSS level 4 is used, and the statement is equivalent to that of CSS level 3.

\@media screen and (device-type: tv) or (resolution &lt; 2) { … } // Multi-condition query that contains the media type and multiple media features.


## Referencing Resources on a Page

Use **@import** to import a media query. The rule is as follows:


```
@import url [media-type] [and|not|only] [(media-feature)];
```

Example:


```
@import '../common/style.css' screen and (min-width: 600) and (max-width: 1200);
```


## Media Type

| Type| Description|
| -------- | -------- |
| screen | Media query based on screen-related parameters.|


## Media Logical Operation

Media logical operators (and, or, not, and only) are used to implement complex media query. They can also be combined using comma (,). The following table describes the operators.

  **Table 1** Media logical operators

| Type| Description|
| -------- | -------- |
| and | The **and** operator is used to combine multiple media features into one media query, in a logical AND operation. The query is valid only when all media features are true. It can also combine media types and media functions.<br>For example, **screen and (device-type: wearable) and (max-height: 600)** indicates that the query is valid when the device type is wearable and the maximum height of the application is 600 pixel units.|
| not | The **not** operator is used to perform a logical negation for a media query. **true** is returned if the query condition is not met. Otherwise, **false** is returned. In a media query list, logical negation is performed only for the media query using the **not** operator.<br>For example, **not screen and (min-height: 50) and (max-height: 600)** indicates that the query is valid when the height of the application is less than 50 pixel units or greater than 600 pixel units.<br>You must specify the media type when using the **not** operator.|
| only | The **only** operator applies the selected style only when the entire expression is matched. It can be used to prevent ambiguity on browsers of earlier versions. The statements that contain both media types and media features produce ambiguity when they are received by some browsers of earlier versions. For example:<br>screen and (min-height: 50)<br>The browsers of earlier versions would mislead this sentence into screen, causing the fact that the specified style is applied when only the media type is matched. In this case, the **only** operator can be used to avoid this problem.<br>You must specify the media type when using the **only** operator.|
| ,(comma) | The **or** operator is used to combine multiple media features into one media query, in a logical OR operation. The query is valid if a media feature is true. The effect of a comma operator is equivalent to that of the **or** operator.<br>For example, **screen and (min-height: 1000),  (round-screen: true)** indicates that the query is valid when the minimum height of the application is 1000 pixel units or the device screen is round.|
| or | The **or** operator is used to combine multiple media features into one media query, in a logical OR operation. The query is valid if a media feature is true.<br>For example, **screen and (max-height: 1000) or  (round-screen: true)** indicates that the query is valid when the maximum height of the application is 1000 pixel units or the device screen is round.|

At MediaQuery Level 4, range query is imported so that you can use the operators including &lt;=, &gt;=, &lt;, and &gt; besides the max- and min-operators.

  **Table 2** Logical operators for range query

| Type| Description|
| -------- | -------- |
| &lt;= | Less than or equal to, for example, **screen and (height &lt;= 50)**.|
| &gt;= | Greater than or equal to, for example, **screen and (height &gt;= 600)**.|
| &lt; | Less than, for example, **screen and (height &lt; 50)**.|
| &gt; | Greater than, for example, **screen and (height &gt; 600)**.|


## Media Features

| Type| Description|
| -------- | -------- |
| height | Height of the display area on the application page.|
| min-height | Minimum height of the display area on the application page.|
| max-height | Maximum height of the display area on the application page.|
| width | Width of the display area on the application page.|
| min-width | Minimum width of the display area on the application page.|
| max-width | Maximum width of the display area on the application page.|
| resolution | Resolution of the device. The unit can be dpi, dppx, or dpcm. Where:<br>- **dpi** indicates the number of physical pixels per inch. 1 dpi ≈ 0.39 dpcm.<br>- **dpcm** indicates the number of physical pixels per centimeter. 1 dpcm ≈ 2.54 dpi.<br>- **dppx** indicates the number of physical pixels in each pixel. (This unit is calculated based on this formula: 96 px = 1 inch, which is different from the calculation method of the px unit on the page.) 1 dppx = 96 dpi.|
| min-resolution | Minimum device resolution.|
| max-resolution | Maximum device resolution.|
| orientation | Screen orientation.<br>Options are as follows:<br>- orientation: portrait<br>- orientation: landscape|
| aspect-ratio | Ratio of the width to the height of the display area on the application page.<br>Example: **aspect-ratio:1/2**|
| min-aspect-ratio | Minimum ratio of the width to the height of the display area on the application page.|
| max-aspect-ratio | Maximum ratio of the width to the height of the display area on the application page.|
| device-height | Height of the device.|
| min-device-height | Minimum height of the device.|
| max-device-height | Maximum height of the device.|
| device-width | Width of the device.|
| min-device-width | Minimum width of the device.|
| max-device-width | Maximum width of the device.|
| round-screen | Screen type. The value **true** means that the screen is round, and **false** means the opposite.|
| dark-mode<sup>6+</sup> | Whether the device is in dark mode. The value **true** means that the device is in dark mode, and **false** means the opposite.|


## Sample Code


```html
<!-- xxx.hml -->
<div>
  <div class="container">
    <text class="title">Hello World</text>
  </div>
</div>
```


```css
/* xxx.css */
.container {
  width: 300px;
  height: 600px;
  background-color: #008000;
}

@media (device-type: wearable) {
    .container-inner {
        justify-content: center;
        align-items: center;
        padding: 40px 26px;
    }

    .title {
        text-align: center;
    }

    .detail_text {
        max-lines: 2;
        text-align: center;
    }
}

@media (device-type: tv) {
    .title {
        font-size: 16px;
    }

    .detail_text {
        font-size: 12px;
    }
}

@media (device-type: car) {
    .title {
        font-size: 12px;
        color: #FFFFFF;
        font-family: @id_text_font_family_medium;
    }

    .detail_text {
        font-size: 12px;
        margin-top: 2px;
        font-family: @id_text_font_family_regular;
        color: #FFFFFF;
    }
}
```
