# Class (OverlayManager)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @houguobiao-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

提供绘制浮层的能力。OverlayManager支持通过配置浮层层级、显示顺序、显示模式等方式管理浮层节点，适用于需要在Page页面之上但Dialog、Popup、Menu等之下的长时间显示的浮层场景，为开发者提供灵活的浮层管理能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 以下API需先使用UIContext中的[getOverlayManager()](arkts-apis-uicontext-uicontext.md#getoverlaymanager12)方法获取到OverlayManager对象，再通过该对象调用对应方法。
>
> - OverlayManager上节点的层级在Page页面层级之上，在Dialog、Popup、Menu、BindSheet、BindContentCover和Toast等之下。
>
> - OverlayManager上节点安全区域内外的绘制方式与Page一致，键盘避让方式与Page一致。
>
> - 与OverlayManager相关的属性推荐采用AppStorage来进行应用全局存储，以免切换页面后属性值发生变化从而导致业务错误。

## openOrderOverlay

openOrderOverlay(content: ComponentContent, options?: OrderOverlayOptions): Promise&lt;void&gt;

在OverlayManager上打开一个支持层级配置的浮层，浮层内容由content参数决定。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填    | 说明          |
| ------- | ---------------------------------------- | ------ | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md#componentcontent-1) | 是    | 浮层的显示内容，在OverlayManager的新节点上添加此内容节点。 <br>**说明：** <br> 新增的节点默认处于页面居中位置，按层级堆叠。|
| options | [OrderOverlayOptions](#orderoverlayoptions) | 否    | 浮层的层级配置选项。不传入时使用默认配置。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。成功时无返回结果；失败时抛出错误，错误码参见错误码部分。 |

**错误码：**

以下错误码的详细介绍请参见[弹窗错误码](errorcode-promptAction.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 103307 | The overlay cannot be opened due to the system pop-up window. |

**示例：**

```ts
import { ComponentContent, OverlayManager, LevelOrder, LevelMode } from '@kit.ArkUI';

class Params {
  text: string = '';
  offset: Position;

  constructor(text: string, offset: Position) {
    this.text = text;
    this.offset = offset;
  }
}

@Builder
function builderText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }.offset(params.offset)
}

@Entry
@Component
struct OverlayExample {
  @State message: string = 'ComponentContent';
  private uiContext: UIContext = this.getUIContext();
  private overlayNode: OverlayManager = this.uiContext.getOverlayManager();

  build() {
    Column({ space: 5 }) {
      Button('打开浮层').onClick(() => {
        let componentContent = new ComponentContent(
          this.uiContext, wrapBuilder<[Params]>(builderText),
          new Params(this.message, { x: 0, y: 110 })
        );
        this.overlayNode.openOrderOverlay(componentContent, {
          levelOrder: LevelOrder.clamp(100),
          levelMode: LevelMode.OVERLAY
        });
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

## OrderOverlayOptions

浮层的层级配置选项。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- |--------| -------- |
| levelOrder | [LevelOrder](js-apis-promptAction.md#levelorder18) | 否 | 是 | 浮层的显示顺序。<br>**说明：**<br>- 默认值：LevelOrder.clamp(0) |
| levelMode | [LevelMode](js-apis-promptAction.md#levelmode15) | 否 | 是 | 浮层的显示模式。<br>**说明：**<br>- 默认值：LevelMode.OVERLAY |
| levelUniqueId | number | 否 | 是 | 浮层需要显示的层级下的节点uniqueId，uniqueId可通过[getUniqueId](js-apis-arkui-frameNode.md#getuniqueid12)接口获取。取值范围为大于等于0的数字，当且仅当levelMode设置为LevelMode.EMBEDDED时生效。 |

## addComponentContent<sup>12+</sup>

addComponentContent(content: ComponentContent, index?: number): void

在OverlayManager上新增指定节点，可通过index参数控制新增节点的层级位置。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | 是    | 在OverlayManager上新增此content节点。 <br>**说明：** <br> 新增的节点默认处于页面居中，按层级堆叠。|
| index | number | 否    | 新增节点在OverlayManager上的层级位置。<br>**说明：** <br> 当index ≥ 0时，index值越大，ComponentContent的层级越高；若多个ComponentContent的index相同，ComponentContent添加的时间越晚层级越高。<br> 当index < 0、index = null或index = undefined时，ComponentContent默认添加至最高层。<br>当同一个ComponentContent被添加多次时，只保留最后一次添加的ComponentContent。|

**示例：**

```ts
import { ComponentContent, OverlayManager } from '@kit.ArkUI';

class Params {
  text: string = '';
  offset: Position;

  constructor(text: string, offset: Position) {
    this.text = text;
    this.offset = offset;
  }
}

@Builder
function builderText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }.offset(params.offset)
}

@Entry
@Component
struct OverlayExample {
  @State message: string = 'ComponentContent';
  private uiContext: UIContext = this.getUIContext();
  private overlayNode: OverlayManager = this.uiContext.getOverlayManager();
  @StorageLink('contentArray') contentArray: ComponentContent<Params>[] = [];
  @StorageLink('componentContentIndex') componentContentIndex: number = 0;
  @StorageLink('arrayIndex') arrayIndex: number = 0;
  @StorageLink('componentOffset') componentOffset: Position = { x: 0, y: 110 };

  build() {
    Column({ space: 5 }) {
      Button('++componentContentIndex: ' + this.componentContentIndex).onClick(() => {
        ++this.componentContentIndex;
      })
      Button('--componentContentIndex: ' + this.componentContentIndex).onClick(() => {
        --this.componentContentIndex;
      })
      Button('增加ComponentContent' + this.contentArray.length).onClick(() => {
        let componentContent = new ComponentContent(
          this.uiContext, wrapBuilder<[Params]>(builderText),
          new Params(this.message + (this.contentArray.length), this.componentOffset)
        );
        this.contentArray.push(componentContent);
        this.overlayNode.addComponentContent(componentContent, this.componentContentIndex);
      })
      Button('++arrayIndex: ' + this.arrayIndex).onClick(() => {
        ++this.arrayIndex;
      })
      Button('--arrayIndex: ' + this.arrayIndex).onClick(() => {
        --this.arrayIndex;
      })
      Button('删除ComponentContent' + this.arrayIndex).onClick(() => {
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray.splice(this.arrayIndex, 1);
          this.overlayNode.removeComponentContent(componentContent.pop());
        } else {
          console.info('arrayIndex有误');
        }
      })
      Button('显示ComponentContent' + this.arrayIndex).onClick(() => {
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray[this.arrayIndex];
          this.overlayNode.showComponentContent(componentContent);
        } else {
          console.info('arrayIndex有误');
        }
      })
      Button('隐藏ComponentContent' + this.arrayIndex).onClick(() => {
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray[this.arrayIndex];
          this.overlayNode.hideComponentContent(componentContent);
        } else {
          console.info('arrayIndex有误');
        }
      })
      Button('显示所有ComponentContent').onClick(() => {
        this.overlayNode.showAllComponentContents();
      })
      Button('隐藏所有ComponentContent').onClick(() => {
        this.overlayNode.hideAllComponentContents();
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![overlayManager01](figures/overlayManager01.gif)

## addComponentContentWithOrder<sup>18+</sup>

addComponentContentWithOrder(content: ComponentContent, levelOrder?: LevelOrder): void

创建浮层节点时，指定显示顺序。支持在浮层节点创建时指定显示的顺序。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | 是    | 在OverlayManager上新增此content节点。 <br>**说明：** <br> 新增的节点默认处于页面居中，按层级堆叠。|
| levelOrder | [LevelOrder](js-apis-promptAction.md#levelorder18) | 否    | 新增浮层节点的显示顺序。<br>**说明：**<br>- 默认值：LevelOrder.clamp(0)|

**示例：**

本示例展示如何调用addComponentContentWithOrder接口创建浮层节点并指定显示顺序。

```ts
import { ComponentContent, PromptAction, LevelOrder, UIContext, OverlayManager } from '@kit.ArkUI';

class Params {
  text: string = '';
  offset: Position;
  constructor(text: string, offset: Position) {
    this.text = text;
    this.offset = offset;
  }
}
@Builder
function builderText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }.offset(params.offset)
}

@Entry
@Component
struct Index {
  @State message: string = '弹窗';
  private ctx: UIContext = this.getUIContext();
  private promptAction: PromptAction = this.ctx.getPromptAction();
  private overlayNode: OverlayManager = this.ctx.getOverlayManager();
  @StorageLink('contentArray') contentArray: ComponentContent<Params>[] = [];
  @StorageLink('componentContentIndex') componentContentIndex: number = 0;
  @StorageLink('arrayIndex') arrayIndex: number = 0;
  @StorageLink('componentOffset') componentOffset: Position = { x: 0, y: 80 };

  build() {
    Row() {
      Column({ space: 10 }) {
        Button('OverlayManager下面弹窗')
          .fontSize(20)
          .onClick(() => {
            let componentContent = new ComponentContent(
              this.ctx, wrapBuilder<[Params]>(builderText),
              new Params(this.message + (this.contentArray.length), this.componentOffset)
            );
            this.contentArray.push(componentContent);
            this.overlayNode.addComponentContentWithOrder(componentContent, LevelOrder.clamp(100.1));
            let topOrder: LevelOrder = this.promptAction.getTopOrder();
            if (topOrder !== undefined) {
              console.info('topOrder: ' + topOrder.getOrder());
            }
            let bottomOrder: LevelOrder = this.promptAction.getBottomOrder();
            if (bottomOrder !== undefined) {
              console.info('bottomOrder: ' + bottomOrder.getOrder());
            }
          })
        Button('OverlayManager上面弹窗')
          .fontSize(20)
          .onClick(() => {
            let componentContent = new ComponentContent(
              this.ctx, wrapBuilder<[Params]>(builderText),
              new Params(this.message + (this.contentArray.length), this.componentOffset)
            );
            this.contentArray.push(componentContent);
            this.overlayNode.addComponentContentWithOrder(componentContent, LevelOrder.clamp(100.2));
            let topOrder: LevelOrder = this.promptAction.getTopOrder();
            if (topOrder !== undefined) {
              console.info('topOrder: ' + topOrder.getOrder());
            }
            let bottomOrder: LevelOrder = this.promptAction.getBottomOrder();
            if (bottomOrder !== undefined) {
              console.info('bottomOrder: ' + bottomOrder.getOrder());
            }
          })
      }.width('100%')
    }.height('100%')
  }
}
```

![](figures/overlayManager02.gif)

## removeComponentContent<sup>12+</sup>

removeComponentContent(content: ComponentContent): void

删除OverlayManager上的指定节点。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | 是    | 在OverlayManager上删除此content。 |

**示例：**

请参考[addComponentContent](#addcomponentcontent12)示例。

## showComponentContent<sup>12+</sup>

showComponentContent(content: ComponentContent): void

在OverlayManager上显示指定节点。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | 是    | 在OverlayManager上显示此content。|

**示例：**

请参考[addComponentContent](#addcomponentcontent12)示例。

## hideComponentContent<sup>12+</sup>

hideComponentContent(content: ComponentContent): void

隐藏OverlayManager上的指定节点。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | 是    | 在OverlayManager上隐藏此content。 |

**示例：**

请参考[addComponentContent](#addcomponentcontent12)示例。

## showAllComponentContents<sup>12+</sup>

showAllComponentContents(): void

显示OverlayManager上所有的ComponentContent。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

请参考[addComponentContent](#addcomponentcontent12)示例。

## hideAllComponentContents<sup>12+</sup>

hideAllComponentContents(): void

隐藏OverlayManager上的所有ComponentContent。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

请参考[addComponentContent](#addcomponentcontent12)示例。
