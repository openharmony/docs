# CanvasRenderingContext2D

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=dfb15c325281e5e789ea7ade45dfdd45876606ad translatedAt=2026-07-27T02:26:31.277Z pushedAt=2026-07-27T09:23:36.721Z -->

**CanvasRenderingContext2D** allows you to draw rectangles and text on a canvas.

> **NOTE**
>
> Starting from API version 23, the previewer is no longer subject to the restriction that JS files cannot exceed 48 KB.

**Example**

```html
<!-- xxx.hml -->
<div>
    <canvas ref="canvas1" style="width: 200px; height: 150px; background-color: #ffff00;"></canvas>
    <input type="button" style="width: 180px; height: 60px;" value="fillStyle" onclick="handleClick" />
</div>
```

```javascript
// xxx.js
export default {
  handleClick() {
    const el = this.$refs.canvas1;
    const ctx = el.getContext('2d');
    ctx.beginPath();
    ctx.arc(100, 75, 50, 0, 6.28);
    ctx.stroke();
  },
}
```

  ![CanvasRenderingContext2D](figures/CanvasRenderingContext2D.png)

## fillRect()

Fills a rectangle on the canvas.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| x | number | X-coordinate of the upper left corner of the rectangle.|
| y | number | Y-coordinate of the upper left corner of the rectangle.|
| width | number | Width of the rectangle.|
| height | number | Height of the rectangle.|

**Example**

 ![fillRect](figures/fillRect.png)

  ```javascript
  ctx.fillRect(20, 20, 200, 150);
  ```

## fillStyle

Sets the style to fill an area.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| color | &lt;color&gt; | Color used to fill the area|

**Example**

  ![fillStyle](figures/fillStyle.png)

  ```javascript
  ctx.fillStyle = '#0000ff';
  ctx.fillRect(20, 20, 150, 100);
  ```

## strokeRect()

Draws a rectangle stroke on the canvas.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| x | number | X-coordinate of the upper left corner of the rectangle.|
| y | number | Y-coordinate of the upper left corner of the rectangle.|
| width | number | Width of the rectangle.|
| height | number | Height of the rectangle.|

**Example**

  ![strokeRect](figures/strokeRect.png)

  ```javascript
  ctx.strokeRect(30, 30, 200, 150);
  ```

## fillText()

Draws filled text on the canvas.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| text | string | Text to draw.|
| x | number | X coordinate of the lower left corner of the text to be drawn.|
| y | number | Y coordinate of the lower left corner of the text to be drawn.|

**Example**

  ![fillText](figures/fillText.png)

  ```javascript
  ctx.font = '35px sans-serif';
  ctx.fillText("Hello World!", 20, 60);
  ```

## lineWidth

Sets the width of a line.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| lineWidth | number | Line width.|

**Example**

  ![lineWidth](figures/lineWidth.png)

  ```javascript
  ctx.lineWidth = 5;
  ctx.strokeRect(25, 25, 85, 105);
  ```

## strokeStyle

Sets the stroke style.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| color | &lt;color&gt; | Color of the stroke.|

**Example**

  ![strokeStyle](figures/strokeStyle.png)

  ```javascript
  ctx.lineWidth = 10;
  ctx.strokeStyle = '#0000ff';
  ctx.strokeRect(25, 25, 155, 105);
  ```

### stroke()<sup>5+</sup>

Draws a stroke.

**Example**

![stroke](figures/stroke.png)

  ```javascript
  ctx.moveTo(25, 25);
  ctx.lineTo(25, 105);
  ctx.strokeStyle = 'rgb(0,0,255)';
  ctx.stroke();
  ```

### beginPath()<sup>5+</sup>

Creates a drawing path.

**Example**

  ![beginPath](figures/beginPath.png)

  ```javascript
  ctx.beginPath();              
  ctx.lineWidth = 6;
  ctx.strokeStyle = '#0000ff';
  ctx.moveTo(15, 80); 
  ctx.lineTo(280, 80);
  ctx.stroke();
  ```

### moveTo()<sup>5+</sup>

Moves a drawing path from the current position to a target position on the canvas.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| x | number | X-coordinate of the target position.|
| y | number | Y-coordinate of the target position.|

**Example**

  ![moveTo](figures/moveTo.png)

  ```javascript
  ctx.beginPath();
  ctx.moveTo(10, 10);
  ctx.lineTo(280, 160);
  ctx.stroke();
  ```

### lineTo()<sup>5+</sup>

Connects the current point to a target position using a straight line.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| x | number | X-coordinate of the target position.|
| y | number | Y-coordinate of the target position.|

**Example**

![lineTo](figures/lineTo.png)

  ```javascript
  ctx.beginPath();
  ctx.moveTo(10, 10);
  ctx.lineTo(280, 160);
  ctx.stroke();
  ```

### closePath()<sup>5+</sup>

Draws a closed path.

**Example**

  ![closePath](figures/closePath.png)

  ```javascript
  ctx.beginPath();
  ctx.moveTo(30, 30);
  ctx.lineTo(110, 30);
  ctx.lineTo(70, 90);
  ctx.closePath();
  ctx.stroke();
  ```

## font

Font style.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| value | string | Font style. **sans-serif**, **serif**, and **monospace** are supported. The default value is **30px HYQiHei-65S**.|

**Example**

  ![font](figures/font.png)

  ```javascript
  ctx.font = '30px sans-serif';
  ctx.fillText("Hello World", 20, 60);
  ```

## textAlign

Sets the text alignment mode.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| align | string | Available values are as follows:<br>- **left** (default): The text is left-aligned.<br>- **right**: The text is right-aligned.<br>- **center**: The text is center-aligned.|

**Example**

  ![textAlign](figures/textAlign.png)

  ```javascript
  ctx.strokeStyle = '#0000ff';
  ctx.moveTo(140, 10);
  ctx.lineTo(140, 160);
  ctx.stroke();
  
  ctx.font = '18px sans-serif';    
  
  // Show the different textAlign values
  ctx.textAlign = 'left';      
  ctx.fillText('textAlign=left', 140, 100);
  ctx.textAlign = 'center';     
  ctx.fillText('textAlign=center',140, 120);              
  ctx.textAlign = 'right';      
  ctx.fillText('textAlign=right',140, 140);
  ```

## arc()<sup>5+</sup>

Draws an arc on the canvas.

**Parameters**

| Name| Type| Mandatory   | Description|
| -------- | -------- | -------- | -------- |
| x | number | Yes| X coordinate of the center point of the arc, in vp.|
| y | number | Yes| Y coordinate of the center point of the arc, in vp.|
| radius | number | Yes| Radius of the arc, in vp.|
| startAngle | number | Yes| Start radian of the arc, in radians|
| endAngle | number | Yes| End radian of the arc, in radians.|
| anticlockwise | boolean | No| Whether to draw the arc counterclockwise.<br>**true**: Draw the arc counterclockwise.<br>**false**: Draw the arc clockwise.<br>The default value is **false**. |

**Example**

![arc](figures/arc.png)

  ```javascript
  ctx.beginPath();
  ctx.arc(100, 75, 50, 0, 6.28);
  ctx.stroke();
  ```

### rect()<sup>5+</sup>

Creates a rectangle on the canvas.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| x | number | Yes| X coordinate of the upper left corner of the rectangle, in vp.|
| y | number | Yes| Y coordinate of the upper left corner of the rectangle, in vp.|
| width | number | Yes| Width of the rectangle, in vp.|
| height | number | Yes| Height of the rectangle, in vp.|

**Example**

![rect](figures/rect.png)

  ```javascript
  ctx.rect(20, 20, 100, 100); // Create a 100*100 rectangle at (20, 20)
  ctx.stroke(); // Draw it
  ```