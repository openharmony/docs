# 基础绘制效果（ArkTS）


## 场景介绍

在进行绘制时，可以进行一些基础效果的设置，比如设置填充颜色、设置抗锯齿、设置图形描边、设置图形线条连接样式等。

主要通过画刷（Brush）设置填充基础效果，通过画笔（Pen）设置描边基础效果。


## 填充效果

可以通过画刷设置基础的填充颜色，还可以通过画刷使用混合模式、着色器效果、滤波器效果等实现更多复杂绘制效果，具体可见[复杂绘制效果](complex-drawing-effect-arkts.md)。


### 接口说明

使用画刷（Brush）设置绘制效果的常用接口如下表所示，详细的使用和参数请见[drawing.Brush](../reference/apis-arkgraphics2d/arkts-apis-graphics-drawing-Brush.md)。

| 接口 | 描述 |
| -------- | -------- |
| attachBrush(brush: Brush): void | 用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。 |
| setColor(alpha: number, red: number, green: number, blue: number): void | 用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色。 |
| setAntiAlias(aa: boolean) : void | 用于设置画刷的抗锯齿属性，设置为true则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理，以使图形边缘更加平滑。 |
| detachBrush(): void | 用于去除画布中的画刷，执行后画布将不使用此前设置的画刷，恢复到默认填充效果。 |


### 开发步骤

1. 创建画刷Brush对象。

   ```ts
   const brush = new drawing.Brush();
   ```

2. 使用画刷设置基础绘制效果，例如设置填充颜色、开启抗锯齿效果等。
   可使用setColor()接口设置填充颜色。

   ```ts
   brush.setColor(0xFF, 0xFF, 0x00, 0x00);
   ```

   可使用setAntiAlias()接口开启抗锯齿效果，以使图形边缘更加平滑。

   ```ts
   brush.setAntiAlias(true);
   ```

3. 使用attachBrush()接口给Canvas画布设置画刷。

   ```ts
   canvas.attachBrush(brush);
   ```

4. 按需绘制图元，具体可见[图元绘制](primitive-drawing-overview.md)一节。

5. 当不需要填充效果时，可以使用detachBrush()接口去除画布中的画刷。

   ```ts
   canvas.detachBrush();
   ```


## 描边效果

可以通过画笔设置基础的描边颜色，还可以通过画笔使用混合模式、路径效果、着色器效果、滤波器效果等实现更多复杂绘制效果，具体可见[复杂绘制效果](complex-drawing-effect-arkts.md)。


### 接口说明

使用画笔（Pen）设置绘制效果的常用接口如下表所示，详细的使用和参数请见[drawing.Pen](../reference/apis-arkgraphics2d/arkts-apis-graphics-drawing-Pen.md)。


| 接口 | 描述 |
| -------- | -------- |
| attachPen(pen: Pen): void | 用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。 |
| setColor(alpha: number, red: number, green: number, blue: number): void | 用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色。 |
| setStrokeWidth(width: number) : void | 用于设置画笔的线宽。0线宽被视作特殊的极细线宽，在绘制时始终会被绘制为1像素，不随画布的缩放而改变；负数线宽在实际绘制时会被视作0线宽。 |
| setAntiAlias(aa: boolean) : void | 用于设置画笔的抗锯齿属性，设置为true则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 |
| setCapStyle(style: CapStyle): void | 用于设置画笔线帽样式。 |
| setJoinStyle(style: JoinStyle): void | 用于设置画笔绘制转角的样式。 |
| detachPen(): void | 用于去除画布中的画笔，执行后画布将不去绘制图形形状的轮廓，恢复到默认的填充效果。 |


### 开发步骤

1. 创建画笔Pen对象。

   ```ts
   let pen = new drawing.Pen();
   ```

2. 使用attachPen()接口给Canvas画布设置画笔。画布将会使用设置的画笔样式和颜色等绘制图形轮廓。

   ```ts
   canvas.attachPen(pen);
   ```

3. 使用画笔设置具体的描边效果（可选以下的一个或者多个效果）。

   - 可使用setColor()接口设置画笔颜色，对应为绘制图形轮廓时使用的颜色。

      ```ts
      // 设置颜色为红色
      pen.setColor(0xFF, 0xFF, 0x00, 0x00);
      ```

   - 可使用setStrokeWidth()接口设置画笔的线宽。

      ```ts
      pen.setStrokeWidth(15);
      ```

   - 可使用setAntiAlias()接口设置画笔抗锯齿，以使图形绘制边缘更平滑。

      ```ts
      pen.setAntiAlias(true);
      ```

   - 可使用setCapStyle()接口设置画笔线帽样式。

      ```ts
      pen.setCapStyle(drawing.CapStyle.SQUARE_CAP);
      ```

      CapStyle线帽样式可选分类对应如下：

      | 线帽样式 | 说明 | 示意图 |
      | -------- | -------- | -------- |
      | FLAT_CAP | 没有线帽样式，线条头尾端点处横切。 | ![Screenshot_20241130143725824](figures/Screenshot_20241130143725824.jpg) |
      | SQUARE_CAP | 线帽的样式为方框，线条的头尾端点处多出一个方框，方框宽度和线段一样宽，高度是线段宽度的一半。 | ![Screenshot_20241130143837975](figures/Screenshot_20241130143837975.jpg) |
      | ROUND_CAP | 线帽的样式为圆弧，线条的头尾端点处多出一个半圆弧，半圆的直径与线段宽度一致。 | ![Screenshot_20241130143949934](figures/Screenshot_20241130143949934.jpg) |

   - 可使用setJoinStyle()接口设置画笔转角样式。

      ```ts
      pen.setJoinStyle(drawing.JoinStyle.ROUND_JOIN);
      ```

      JoinStyle转角样式可选分类对应如下：

      | 转角样式 | 说明 | 示意图 |
      | -------- | -------- | -------- |
      | MITER_JOIN | 转角类型为尖角 | ![zh-cn_image_0000002158744154](figures/zh-cn_image_0000002158744154.png) |
      | ROUND_JOIN | 转角类型为圆头 | ![zh-cn_image_0000002158744146](figures/zh-cn_image_0000002158744146.png) |
      | BEVEL_JOIN | 转角类型为平头 | ![zh-cn_image_0000002194025257](figures/zh-cn_image_0000002194025257.png) |

4. 按需绘制图元，具体可见[图元绘制](primitive-drawing-overview.md)一节。

5. 当不需要描边效果时，可以使用detachPen()接口去除画布中的画笔。

   ```ts
   canvas.detachPen();
   ```

<!--RP1-->
## 相关实例

针对Drawing(ArkTS)的开发，有以下相关实例可供参考：

- [ArkTSGraphicsDraw (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/ArkTSGraphicsDraw)
<!--RP1End-->