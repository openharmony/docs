# 文本测量（ArkTS）


## 场景介绍

文本测量指的是在图形绘制中，对文本的尺寸和布局进行评估，计算文本在给定字体和样式下占用的空间（例如宽度、高度和其他相关信息）的过程。文本测量用于文本排版、布局、渲染以及调整文本显示的位置和大小等场景，便于对界面的布局和呈现更好地把控和调整，以达到设计预期。

当前主要支持以下方面的文本测量能力：


- **文本宽度**：测量给定文本在特定字体、大小和样式下的水平长度。

- **文本高度**：测量给定文本的垂直高度，通常涉及文本的上升线、下降线等。

- **行间距**：测量多行文本之间的垂直距离，通常与文本的行距相关。

- **字符间距**：测量单个字符之间的水平距离，通常与字形和字体设计有关。


## 接口说明

文本测量中常用接口如下表所示，详细接口说明参考[@ohos.graphics.text (文本模块)](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#paragraph)。

| 接口名 | 描述 | 
| -------- | -------- |
| getLongestLine(): number | 获取当前段落最长行的宽度，建议实际使用时将返回值向上取整。 | 
| getLongestLineWithIndent(): number | 获取当前段落最长行的宽度（该宽度包含当前行缩进的宽度），建议实际使用时将返回值向上取整。 | 
| getTextLines(): Array&lt;TextLine&gt; | 获取当前段落文本行对象数组。 | 
| getLineMetrics(): Array&lt;LineMetrics&gt; | 获取段落所有行的度量信息。包含行的高度、宽度、起始坐标等信息。 | 
| getLineMetrics(lineNumber: number): LineMetrics \| undefined | 获取段落指定行的度量信息。包含行的高度、宽度、起始坐标等信息。超出当前段落排版后最大行数后返回 undefined | 


## 开发步骤

1. 导入依赖的相关模块。

   ```ts
   import { text } from '@kit.ArkGraphics2D';
   ```

2. 创建段落样式，并使用构造段落生成器PargraphBuilder生成段落实例。

   ```ts
   // 设置文本样式
   let myTextStyle: text.TextStyle = {
       color: { alpha: 255, red: 255, green: 0, blue: 0 },
       fontSize: 100
   };
   // 创建一个段落样式对象，以设置排版风格
   let myParagraphStyle: text.ParagraphStyle = {
       textStyle: myTextStyle,
       wordBreak:text.WordBreak.NORMAL
   }
   // 创建一个段落生成器
   let paragraphBuilder: text.ParagraphBuilder = new text.ParagraphBuilder(myParagraphStyle, new text.FontCollection());
   ```

3. 设置文本样式，添加文本内容，并生成段落文本用于后续文本的绘制显示。

   ```ts
   // 在段落生成器中设置文本样式
   paragraphBuilder.pushStyle(myTextStyle);
   // 在段落生成器中设置文本内容
   paragraphBuilder.addText("文本测量测试");
   // 通过段落生成器生成段落
   let paragraph = paragraphBuilder.build();
   ```

4. 调用测量相关接口，获取指定的测量信息。

   ```ts
   // case1: 获取排版后最长行行宽
   let longestLineWidth = paragraph.getLongestLine();
   // case2: 获取排版后最长行行宽(包含缩进)
   let longestLineWithIndentWidth = paragraph.getLongestLineWithIndent()
   // case3: 获取排版后所有行对象
   let textLines = paragraph.getTextLines();
   // case4: 获取排版后指定行对应的度量信息
   let lineCnt = paragraph.getLineCount();
   for (let index = 0; index < lineCnt; index++) {
       let lineMetrics = paragraph.getLineMetrics(index);
   }
   // case5: 获取排版后所有行度量信息数组
   let allLineMetrics = paragraph.getLineMetrics();
   ```

## 完整示例

完整的文本测量示例如下。

```ts
// Index.ets
import { NodeController, FrameNode, RenderNode, DrawContext } from '@kit.ArkUI'
import { UIContext } from '@kit.ArkUI'
import { text } from '@kit.ArkGraphics2D'

class MyRenderNode extends RenderNode {
  async draw(context: DrawContext) {
    // 获取画布canvas对象
    const canvas = context.canvas
    // 设置文本样式
    let myTextStyle: text.TextStyle = {
      color: {
        alpha: 255,
        red: 255,
        green: 0,
        blue: 0
      },
      fontSize: 100
    };
    // 创建一个段落样式对象，以设置排版风格
    let myParagraphStyle: text.ParagraphStyle = {
      textStyle: myTextStyle,
      wordBreak: text.WordBreak.NORMAL
    }
    // 创建一个段落生成器
    let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, new text.FontCollection())
    // 在段落生成器中设置文本样式
    paragraphBuilder.pushStyle(myTextStyle);
    // 在段落生成器中设置文本内容
    paragraphBuilder.addText("文本测量测试");
    // 通过段落生成器生成段落
    let paragraph = paragraphBuilder.build();
    // 布局
    paragraph.layoutSync(1000);
    // case1: 获取排版后最长行行宽
    let longestLineWidth = paragraph.getLongestLine();
    console.info("longestLineWidth = " + longestLineWidth);

    // case2: 获取排版后最长行行宽(包含缩进)
    let longestLineWithIndentWidth = paragraph.getLongestLineWithIndent();
    console.info("longestLineWithIndentWidth = " + longestLineWithIndentWidth);

    // case3: 获取排版后所有行对象
    let textLines = paragraph.getTextLines();
    for (let index = 0; index < textLines.length; index++) {
      const textline = textLines[index];
      let curLineRange = textline.getTextRange();
      let curLineGlyCnt = textline.getGlyphCount();
      console.info("第" + index + "行 TextRange start: " + curLineRange.start + " TextRange end: " + curLineRange.end);
      console.info("第" + index + "行字形数量为: " + curLineGlyCnt);
    }

    // case4: 获取排版后指定行对应的度量信息
    let lineCnt = paragraph.getLineCount();
    for (let index = 0; index < lineCnt; index++) {
      let lineMetrics = paragraph.getLineMetrics(index);
      if (lineMetrics) {
        console.info("第" + index + "行 lineMetrics width: " + lineMetrics.width);
        console.info("第" + index + "行 lineMetrics start index: " + lineMetrics.startIndex + ", end index: " +
        lineMetrics.endIndex);
      }
    }

    // case5: 获取排版后所有行度量信息数组
    let allLineMetrics = paragraph.getLineMetrics();
    paragraph.paint(canvas, 200, 800);
  }
}

// 创建一个MyRenderNode对象
function getNewRenderNode() {
  const textNodeTest = new MyRenderNode();
  textNodeTest.frame = {
    x: 0,
    y: 0,
    width: 500,
    height: 500
  }
  textNodeTest.pivot = { x: 0.5, y: 0.5 }
  textNodeTest.scale = { x: 1, y: 1 }
  return textNodeTest;
}

const textNode = new MyRenderNode();
// 定义newNode的像素格式
textNode.frame = {
  x: 0,
  y: 0,
  width: 500,
  height: 500
}
textNode.pivot = { x: 0.5, y: 0.5 }
textNode.scale = { x: 1, y: 1 }

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode {
    this.rootNode = new FrameNode(uiContext)
    if (this.rootNode == null) {
      return this.rootNode
    }
    const renderNode = this.rootNode.getRenderNode()
    if (renderNode != null) {
      renderNode.frame = {
        x: 0,
        y: 0,
        width: 300,
        height: 50
      }
      renderNode.pivot = { x: 0, y: 0 }
    }
    return this.rootNode
  }

  addNode(node: RenderNode): void {
    if (this.rootNode == null) {
      return
    }
    const renderNode = this.rootNode.getRenderNode()
    if (renderNode != null) {
      renderNode.appendChild(node)
    }
  }

  clearNodes(): void {
    if (this.rootNode == null) {
      return
    }
    const renderNode = this.rootNode.getRenderNode()
    if (renderNode != null) {
      renderNode.clearChildren()
    }
  }
}

@Entry
@Component
struct RenderTest {
  private myNodeController: MyNodeController = new MyNodeController()

  build() {
    Column() {
      Row() {
        NodeContainer(this.myNodeController)
          .height('100%')
      }
      .height('90%')
      .backgroundColor(Color.White)

      Row() {
        Button("Draw Text")
          .fontSize('16fp')
          .fontWeight(500)
          .margin({ bottom: 24, right: 12 })
          .onClick(() => {
            this.myNodeController.clearNodes()
            this.myNodeController.addNode(getNewRenderNode())
          })
          .width('50%')
          .height(40)
      }
      .width('100%')
      .justifyContent(FlexAlign.Center)
      .alignItems(VerticalAlign.Bottom)
      .layoutWeight(1)
    }
  }
}
```
