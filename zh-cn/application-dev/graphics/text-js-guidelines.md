# 使用Text模块实现文本显示

## 场景介绍

@ohos.graphics.text模块提供了接口创建复杂的文本段落，包括多样的文本样式、段落样式、换行规则等，并最终将这些信息转换为能在屏幕上高效渲染的布局数据。

## 接口说明

@ohos.graphics.text常用接口如下表所示，详细的接口说明请参考[@ohos.graphics.text](../reference/apis-arkgraphics2d/js-apis-graphics-text.md)。

| 接口名 | 描述 |
| -------- | -------- |
| pushStyle(textStyle: TextStyle): void | 设置成最新的文本样式。 |
| addText(text: string): void | 用于向正在构建的文本段落中插入具体的文本字符串。 |
| addPlaceholder(placeholderSpan: PlaceholderSpan): void | 用于在构建文本段落时插入占位符。 |
| build(): Paragraph | 用于完成段落的构建过程，生成一个可用于后续排版渲染的段落对象。 |
| paint(canvas: drawing.Canvas, x: number, y: number): void | 在画布上以坐标点 (x, y) 为左上角位置绘制文本。 |

## 开发步骤

使用TextEngine进行文字绘制与显示时，需要使用@ohos.graphics.text模块的字体管理器和段落样式、段落生成器创建文本段落，最终在应用上显示文本。

本文以实现段落文字的创建与显示为例，给出具体的开发指导。
### 添加开发依赖

**依赖文件**
```js
import { NodeController, FrameNode, RenderNode, DrawContext } from '@kit.ArkUI'
import { UIContext } from '@kit.ArkUI'
import { drawing } from '@kit.ArkGraphics2D'
import { text } from '@kit.ArkGraphics2D'
import { image } from '@kit.ImageKit'
import { common2D } from '@kit.ArkGraphics2D'
```

接下来介绍如何使用text接口进行文本绘制。

### 绘制文本

以下步骤描述了如何使用@ohos.graphics.text模块的接口创建段落对象以及显示段落文本。

1. **创建RenderNode子类**。创建`RenderNode`子类`MyRenderNode`，并在其中定义绘图函数draw，下方第2步及第3步为draw函数的具体实现。`RenderNode`中包含树结构的操作，以及对绘制属性的操作。

    ```js
    // 创建一个MyRenderNode类，并绘制文本。
    class MyRenderNode extends RenderNode {

        async draw(context: DrawContext) {
            // ...
        }
    }
    ```

2. **创建canvas并设置画笔和画刷样式**。使用`Pen`接口创建一个画笔实例pen，并设置抗锯齿、颜色、线宽等属性，画笔用于形状边框线的绘制。使用`Brush`接口创建一个画刷实例brush，并设置填充颜色，画刷用于形状内部的填充。使用canvas中的`attachPen`和`attachBrush`接口将画笔画刷的实例设置到画布实例中。

    ```js
    // 创建画布canvas对象
    const canvas = context.canvas
    // 创建一个画笔Pen对象，Pen对象用于形状的边框线绘制
    let pen = new drawing.Pen()
    let pen_color : common2D.Color = { alpha: 0xFF, red: 0xFF, green: 0x00, blue: 0x00 }
    pen.setColor(pen_color)

    // 将Pen画笔设置到canvas中
    canvas.attachPen(pen)

    // 创建一个画刷Brush对象，Brush对象用于形状的填充
    let brush = new drawing.Brush()
    let brush_color : common2D.Color = { alpha: 0xFF, red: 0x00, green: 0xFF, blue: 0x00 }
    brush.setColor(brush_color)

    // 将Brush画刷设置到canvas中
    canvas.attachBrush(brush)
    ```

3. **绘制文本**。使用`TextStyle`接口创建一个文本样式实例myTextStyle，示例只设置了文本颜色，使用`ParagraphStyle`接口创建一个段落样式实例myParagraphStyle，并设置文本样式等属性，使用`FontCollection`接口创建一个字体管理器实例fontCollection，使用`ParagraphBuilder`的接口，以myParagraphStyle和fontCollection为参数创建一个段落生成器实例paragraphBuilder，并调用其接口使文本样式更新以及添加段落文本，在调用build()接口生成段落实例paragraph，最后调用paint接口在屏幕上显示。

    ```js
    //字体颜色，字重，字体大小等属性由此设置
    let myTextStyle: text.TextStyle = {
        color: { alpha: 255, red: 255, green: 0, blue: 0 },
    };
    //断词类型，换行策略，文本方向以及对齐方式由此设置
    let myParagraphStyle: text.ParagraphStyle = {
        textStyle: myTextStyle,
        align: 3,
        //wordBreak:text.WordBreak.NORMAL 文本断词类型
    };
    let fontCollection = new text.FontCollection();
    let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
    //更新文本样式
    paragraphBuilder.pushStyle(myTextStyle);
    //添加文本
    paragraphBuilder.addText("0123456789");
    //生成段落
    let paragraph = paragraphBuilder.build();
    // 布局
    paragraph.layoutSync(600);
    //绘制文本
    paragraph.paint(canvas, 0, 0);
    ```

4. **创建MyRenderNode对象**。以上1到3步构建出了MyRenderNode类并在其中定义了绘图的主要函数，接下来创建一个MyRenderNode对象，并设置它的像素格式。

    ```js
    // 创建一个MyRenderNode对象
    const textNode = new MyRenderNode()
    // 定义newNode的像素格式
    textNode.frame = { x: 100, y: 100, width: 200, height: 800 }
    textNode.pivot = { x: 0.2, y: 0.8 }
    textNode.scale = { x: 1, y: 1 }
    ```

5. **创建NodeController子类**。创建`NodeController`的子类`MyNodeController`，并在其中定义创建`FrameNode`的函数。`NodeController`定义了节点容器的控制器，控制着容器里在生命周期中的节点。`FrameNode`定义了节点的基本类型，并包含一个`RenderNode`。

    ```js
    class MyNodeController extends NodeController {
        private rootNode: FrameNode | null = null;

        makeNode(uiContext: UIContext): FrameNode {
            this.rootNode = new FrameNode(uiContext)
            if (this.rootNode == null) {
                return this.rootNode
            }
            const renderNode = this.rootNode.getRenderNode()
            if (renderNode != null) {
                renderNode.frame = { x: 0, y: 0, width: 10, height: 500 }
                renderNode.pivot = { x: 50, y: 50 }
            }
            return this.rootNode
        }
    }
    ```

6. **创建添加节点的接口**。在第5步中创建的`MyNodeController`类中创建添加`RenderNode`的接口。

    ```js
    addNode(node: RenderNode): void {
        if (this.rootNode == null) {
            return
        }
        const renderNode = this.rootNode.getRenderNode()
        if (renderNode != null) {
            renderNode.appendChild(node)
        }
    }
    ```

7. **创建删除节点的接口**。在第5步中创建的`MyNodeController`类中创建删除`RenderNode`的接口。

    ```js
    clearNodes(): void {
        if (this.rootNode == null) {
            return
        }
        const renderNode = this.rootNode.getRenderNode()
        if (renderNode != null) {
            renderNode.clearChildren()
        }
    }
    ```

8. **绘制图形和文字**。创建`MyNodeController`实例并将其存入`NodeContainer`，添加button控件供用户点击，并调用已定义的接口。

    ```js
    @Entry
    @Component
    struct RenderTest {
        private myNodeController: MyNodeController = new MyNodeController()
        build() {
            Column() {
                Row() {
                    NodeContainer(this.myNodeController)
                        .height('100%')
                    Button("Draw Text")
                        .margin({ bottom: 200, right: 12 })
                        .onClick(() => {
                            this.myNodeController.clearNodes()
                            this.myNodeController.addNode(textNode)
                        })
                }
                .width('100%')
                .justifyContent(FlexAlign.Center)
                .shadow(ShadowStyle.OUTER_DEFAULT_SM)
                .alignItems(VerticalAlign.Bottom)
                .layoutWeight(1)
            }
        }
    }
    ```

9. 绘制与显示的效果图如下：

    | 主页                                 | 绘制文字(不设置wordBreak)                  | 绘制文字(设置wordBreak)               |
    | ------------------------------------ | ---------------------------------------- | ------------------------------------ |
    | ![main](./figures/JStextMainPage.jpg) | ![Draw Path](figures/JStextText.jpg)    | ![Draw Path](figures/JStextText2.jpg) |
