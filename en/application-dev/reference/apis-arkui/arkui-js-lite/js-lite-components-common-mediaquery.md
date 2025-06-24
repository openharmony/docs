# Media Query

>  **NOTE**
>
>  - This API is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
>  - The **media** attribute uses the actual size, physical pixel, and screen resolution of the device by default.


Media queries are widely used. You can use them to modify the application style based on the device type or specific features and device parameters (such as the screen resolution). Specifically, media queries allow you to design a layout style based on the device and application attributes.


## CSS Syntax Rules

Use **@media** to import query statements. The rule is as follows:

```
@media [media-type] [and|or] [(media-feature)] {
  CSS-Code;
}
```

**@media screen and (round-screen: true) { … }**: The condition is met when the device screen is round.

**@media (max-height: 454) { … }**: Range query. CSS level 3 is used.

>  **NOTE**
>
>  - The following operators are not supported: &lt;=, &gt;=, &lt;, and &gt;.
>  - Nested parentheses are supported since API version 9.
>  - A media query statement can contain a maximum of 512 characters.
>  - A media query condition can contain a maximum of 32 characters.


## Media Type

| Type    | Description            |
| ------ | -------------- |
| screen | Media query based on screen-related parameters.|


## Media Logical Operation

You can use media logical operators to implement complex media query. The following table describes the available operators.

**Table 1** Media logical operators

| Type             | Description                                      |
| --------------- | ---------------------------------------- |
| and             | The **and** operator is used to combine multiple media features into one media query, in a logical AND operation. The query is valid only when all media features are true. It can also combine media types and media functions.<br>For example, **screen and (device-type: liteWearable) and (max-height: 454)** evaluates to **true** when the device type is wearable and the maximum height of the application is 454 pixel units.|
| or<sup>9+</sup> | The **or** operator is used to combine multiple media features into one media query, in a logical OR operation. The query is valid if a media feature is true.<br>For example, **screen and (max-height: 454) or (round-screen: true)** evaluates to **true** when the maximum height of the application is 454 pixel units or the device screen is round.|




## Media Features

| Type              | Description                                      |
| ---------------- | ---------------------------------------- |
| height           | Height of the display area on the application page.                            |
| min-height       | Minimum height of the display area on the application page.                          |
| max-height       | Maximum height of the display area on the application page.                          |
| width            | Width of the display area on the application page.                            |
| min-width        | Minimum width of the display area on the application page.                          |
| max-width        | Maximum width of the display area on the application page.                          |
| aspect-ratio     | Ratio of the width to the height of the display area on the application page.<br>Example: **aspect-ratio: 1/2**|
| min-aspect-ratio | Minimum ratio of the width to the height of the display area on the application page.                    |
| max-aspect-ratio | Maximum ratio of the width to the height of the display area on the application page.                    |
| round-screen     | Screen type. The value **true** means that the screen is round, and **false** means the opposite.|


## Sample Code for the Common Media Feature

The number and type of attributes must be the same among **.container** blocks. Otherwise, display errors will occur.

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
.title {
    font-size: 30px;
    text-align: center;
}
@media (device-type: smartVision) {
  .container {
    width: 500px;
    height: 500px;
    background-color: #fa8072;
  }
} 
@media (device-type: liteWearable) {
  .container {
    width: 300px;
    height: 300px;
    background-color: #008b8b;
  }
} 
```
