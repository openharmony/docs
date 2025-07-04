# Using Canvas in ArkTS Widgets


You can apply custom drawing in your ArkTS widget to create a more vibrant experience. Use the [\<Canvas>](../reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md) component to create a canvas on the widget, and then use the [CanvasRenderingContext2D](../reference/apis-arkui/arkui-ts/ts-canvasrenderingcontext2d.md) object to draw custom graphics on the canvas. The following code snippet draws a smiling face in the center of a canvas.

```ts
@Entry
@Component
struct CustomCanvasDrawingCard {
  private canvasWidth: number = 0;
  private canvasHeight: number = 0;
  // Initialize CanvasRenderingContext2D and RenderingContextSettings.
  private settings: RenderingContextSettings = new RenderingContextSettings(true);
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);

  build() {
    Column() {
      Row() {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .onReady(() => {
            // Obtain the actual width and height of the canvas in the onReady callback.
            this.canvasWidth = this.context.width;
            this.canvasHeight = this.context.height;
            // Draw the background of the canvas.
            this.context.fillStyle = '#EEF0FF';
            this.context.fillRect(0, 0, this.canvasWidth, this.canvasHeight);
            // Draw a circle in the center of the canvas.
            this.context.beginPath();
            let radius = this.context.width / 3;
            let circleX = this.context.width / 2;
            let circleY = this.context.height / 2;
            this.context.moveTo(circleX - radius, circleY);
            this.context.arc(circleX, circleY, radius, 2 * Math.PI, 0, true);
            this.context.closePath();
            this.context.fillStyle = '#5A5FFF';
            this.context.fill();
            // Draw the left eye of the smiling face.
            let leftR = radius / 13;
            let leftX = circleX - (radius / 2.3);
            let leftY = circleY - (radius / 4.5);
            this.context.beginPath();
            this.context.arc(leftX, leftY, leftR, 0, 2 * Math.PI, true);
            this.context.closePath();
            this.context.strokeStyle = '#FFFFFF';
            this.context.lineWidth = 15;
            this.context.stroke();
            // Draw the right eye of the smiling face.
            let rightR = radius / 13;
            let rightX = circleX + (radius / 2.3);
            let rightY = circleY - (radius / 4.5);
            this.context.beginPath();
            this.context.arc(rightX, rightY, rightR, 0, 2 * Math.PI, true);
            this.context.closePath();
            this.context.strokeStyle = '#FFFFFF';
            this.context.lineWidth = 15;
            this.context.stroke();
            // Draw the nose of the smiling face.
            let startX = circleX;
            let startY = circleY - 20;
            this.context.beginPath();
            this.context.moveTo(startX, startY);
            this.context.lineTo(startX - 8, startY + 40);
            this.context.lineTo(startX + 8, startY + 40);
            this.context.strokeStyle = '#FFFFFF';
            this.context.lineWidth = 15;
            this.context.lineCap = 'round';
            this.context.lineJoin = 'round';
            this.context.stroke();
            // Draw the mouth of the smiling face.
            let mouthR = radius / 2;
            let mouthX = circleX;
            let mouthY = circleY + 10;
            this.context.beginPath();
            this.context.arc(mouthX, mouthY, mouthR, Math.PI / 1.4, Math.PI / 3.4, true);
            this.context.strokeStyle = '#FFFFFF';
            this.context.lineWidth = 15;
            this.context.stroke();
            this.context.closePath();
          })
      }
    }.height('100%').width('100%')
  }
}
```

The figure below shows the effect. 
![WidgetCanvasDemo](figures/WidgetCanvasDemo.jpeg)
