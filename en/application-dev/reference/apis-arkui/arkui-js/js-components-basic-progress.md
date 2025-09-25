# progress

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

The **\<Progress>** component is used to provide a progress bar that displays the progress of content loading or an operation.

## Required Permissions

None


## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name  | Type    | Default Value       | Mandatory  | Description                                      |
| ---- | ------ | ---------- | ---- | ---------------------------------------- |
| type | string | horizontal | No   | Type of the progress bar, which cannot be changed dynamically. Available values are as follows:<br>- **horizontal**: linear progress bar.<br>- **circular**: loading progress bar.<br>- **ring**: ring progress bar.<br>- **scale-ring**: ring progress bar with a scale.<br>- **arc**: arc progress bar.<br>- **eclipse**<sup>5+</sup>: eclipse progress bar.|

Different types of progress bars support different attributes.

- When the type is **horizontal**, **ring**, or **scale-ring**, the following attributes are supported.
  | Name              | Type    | Default Value | Mandatory  | Description              |
  | ---------------- | ------ | ---- | ---- | ---------------- |
  | percent          | number | 0    | No   | Current progress. The value ranges from 0 to 100.|
  | secondarypercent | number | 0    | No   | Secondary progress. The value ranges from 0 to 100.|

- When the type is **ring** or **scale-ring**, the following attributes are supported.
  | Name       | Type     | Default Value | Mandatory  | Description            |
  | --------- | ------- | ---- | ---- | -------------- |
  | clockwise | boolean | true | No   | Whether the ring progress bar uses clockwise.|

- When the type is **arc** or **eclipse**<sup>5+</sup>, the following attributes are supported.
  | Name     | Type    | Default Value | Mandatory  | Description              |
  | ------- | ------ | ---- | ---- | ---------------- |
  | percent | number | 0    | No   | Current progress. The value ranges from 0 to 100.|


## Styles

In addition to the [universal styles](js-components-common-styles.md), the following styles are supported.

Horizontal progress bar, of which **type** is **horizontal**

| Name              | Type            | Default Value       | Mandatory  | Description         |
| ---------------- | -------------- | ---------- | ---- | ----------- |
| color            | &lt;color&gt;  | \#ff007dff | No   | Color of the progress bar.  |
| stroke-width     | &lt;length&gt; | 4px        | No   | Stroke width of the progress bar.  |
| background-color | &lt;color&gt;  | -          | No   | Background color of the progress bar. |
| secondary-color  | &lt;color&gt;  | -          | No   | Color of the secondary progress bar.|

Circular progress bar, of which **type** is **circular**

| Name   | Type           | Default Value | Mandatory  | Description               |
| ----- | ------------- | ---- | ---- | ----------------- |
| color | &lt;color&gt; | -    | No   | Color of the dot on the loading progress bar.|

Ring or scale-ring progress bar, of which **type** is **scale-ring**

| Name              | Type                                      | Default Value | Mandatory  | Description                                      |
| ---------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| color            | &lt;color&gt; \| &lt;linear-gradient&gt; | -    | No   | Color of the ring progress bar. The **ring** type supports the linear gradient color.<br>The linear gradient color supports only two color attribute formats, for example, **color = linear-gradient(\#ff0000, \#00ff00)**.|
| background-color | &lt;color&gt;                            | -    | No   | Background color of the ring progress bar.                              |
| secondary-color  | &lt;color&gt;                            | -    | No   | Color of the secondary ring progress bar.                             |
| stroke-width     | &lt;length&gt;                           | 10px | No   | Width of the ring progress bar.                               |
| scale-width      | &lt;length&gt;                           | -    | No   | Scale thickness of the ring progress bar with a scale. This style takes effect only when the type is **scale-ring**.         |
| scale-number     | number                                   | 120  | No   | Number of scales of the ring progress bar with a scale. This style takes effect only when the type is **scale-ring**.         |

Arc progress bar, of which **type** is **arc**

| Name              | Type            | Default Value          | Mandatory  | Description                                      |
| ---------------- | -------------- | ------------- | ---- | ---------------------------------------- |
| color            | &lt;color&gt;  | -             | No   | Color of the arc progress bar.                               |
| background-color | &lt;color&gt;  | -             | No   | Background color of the arc progress bar.                              |
| stroke-width     | &lt;length&gt; | 4px           | No   | Width of the arc progress bar, which is always within the radius area.<br>The wider the progress bar is, the closer the progress bar is to the center of the circle. The progress bar is always within the radius.|
| start-angle      | &lt;deg&gt;    | 240           | No   | Start angle of the arc progress bar, which starts from zero o'clock clockwise. The value ranges from 0 to 360 degrees.     |
| total-angle      | &lt;deg&gt;    | 240           | No   | Total length of the arc progress bar. The value ranges from –360 to 360. A negative number indicates anticlockwise.     |
| center-x         | &lt;length&gt; | Half of the width of the arc progress bar   | No   | Center of the arc progress bar (with the upper left corner of the component as the coordinate origin). This style must be used together with **center-y** and **radius**.|
| center-y         | &lt;length&gt; | Half of the height of the arc progress bar   | No   | Center of the arc progress bar (with the upper left corner of the component as the coordinate origin). This style must be used together with **center-x** and **radius**.|
| radius           | &lt;length&gt; | Half of the minimum width and height of the arc progress bar| No   | Radius of the arc progress bar. This style must be used together with **center-x** and **center-y**.    |

Eclipse progress bar, of which **type** is **eclipse**<sup>5+</sup>

| Name              | Type           | Default Value | Mandatory  | Description        |
| ---------------- | ------------- | ---- | ---- | ---------- |
| color            | &lt;color&gt; | -    | No   | Color of the eclipse progress bar. |
| background-color | &lt;color&gt; | -    | No   | Background color of the eclipse progress bar.|


## Events

The [universal events](js-components-common-events.md) are supported.

## Methods

The [universal methods](js-components-common-methods.md) are supported.


## Example

```html
<!--xxx.hml -->
<div class="container">
  <progress class="min-progress" type="scale-ring"  percent= "10" secondarypercent="50"></progress>
  <progress class="min-progress" type="horizontal" percent= "10" secondarypercent="50"></progress>
  <progress class="min-progress" type="arc" percent= "10"></progress>
  <progress class="min-progress" type="ring" percent= "10" secondarypercent="50"></progress>
</div>
```

```css
/* xxx.css */
.container {
  flex-direction: column;
  height: 100%;
  width: 100%;
  align-items: center;
}
.min-progress {
  width: 300px;
  height: 300px;
}
```

![progress](figures/progress.png)
