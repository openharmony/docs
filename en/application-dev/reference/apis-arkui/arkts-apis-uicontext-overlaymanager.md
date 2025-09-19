# Class (OverlayManager)

Provides the capability to draw overlays.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - In the following API examples, you must first use [getOverlayManager()](arkts-apis-uicontext-uicontext.md#getoverlaymanager12) in **UIContext** to obtain an **OverlayManager** instance, and then call the APIs using the obtained instance.
>
> - The nodes on **OverlayManager** are above the page level, but below such components as created through **Dialog**, **Popup**, **Menu**, **BindSheet**, **BindContentCover**, and **Toast**.
>
> - The drawing method inside and outside the safe area of nodes on **OverlayManager** is consistent with that of the page, and the keyboard avoidance method is also the same as that of the page.
>
> - For properties related to **OverlayManager**, you are advised to use AppStorage for global storage across the application to prevent changes in property values when switching pages, which could lead to service errors.

## addComponentContent<sup>12+</sup>

addComponentContent(content: ComponentContent, index?: number): void

Adds a specified **ComponentContent** node to the **OverlayManager**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description         |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | Yes   | Content to add to the new node on the **OverlayManager**.<br>**NOTE**<br> By default, the new node is centered on the page and stacked according to its stacking level.|
| index | number | No   | Stacking level of the new node on the **OverlayManager**.<br>**NOTE**<br> If the value is greater than or equal to 0, a larger value means a higher layer for the **ComponentContent** node. If multiple **ComponentContent** nodes have the same index, the later-added ones appear above earlier ones.<br> If the value is less than 0, **null**, or **undefined**, the **ComponentContent** node is added at the highest level by default.<br>If the same **ComponentContent** node is added multiple times, only the last added one is retained.

**Example**

```ts
import { ComponentContent, OverlayManager } from '@kit.ArkUI';

class Params {
  text: string = "";
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
  @StorageLink("componentOffset") componentOffset: Position = { x: 0, y: 80 };

  build() {
    Column() {
      Button("++componentContentIndex: " + this.componentContentIndex).onClick(() => {
        ++this.componentContentIndex;
      })
      Button("--componentContentIndex: " + this.componentContentIndex).onClick(() => {
        --this.componentContentIndex;
      })
      Button("Add ComponentContent" + this.contentArray.length).onClick(() => {
        let componentContent = new ComponentContent(
          this.uiContext, wrapBuilder<[Params]>(builderText),
          new Params(this.message + (this.contentArray.length), this.componentOffset)
        );
        this.contentArray.push(componentContent);
        this.overlayNode.addComponentContent(componentContent, this.componentContentIndex);
      })
      Button("++arrayIndex: " + this.arrayIndex).onClick(() => {
        ++this.arrayIndex;
      })
      Button("--arrayIndex: " + this.arrayIndex).onClick(() => {
        --this.arrayIndex;
      })
      Button("Delete ComponentContent" + this.arrayIndex).onClick(() => {
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray.splice(this.arrayIndex, 1);
          this.overlayNode.removeComponentContent(componentContent.pop());
        } else {
          console.info("Invalid arrayIndex.");
        }
      })
      Button("Show ComponentContent" + this.arrayIndex).onClick(() => {
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray[this.arrayIndex];
          this.overlayNode.showComponentContent(componentContent);
        } else {
          console.info("Invalid arrayIndex.");
        }
      })
      Button("Hide ComponentContent" + this.arrayIndex).onClick(() => {
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray[this.arrayIndex];
          this.overlayNode.hideComponentContent(componentContent);
        } else {
          console.info("Invalid arrayIndex.");
        }
      })
      Button("Show All ComponentContent").onClick(() => {
        this.overlayNode.showAllComponentContents();
      })
      Button("Hide All ComponentContent").onClick(() => {
        this.overlayNode.hideAllComponentContents();
      })

      Button("Go").onClick(() => {
        this.getUIContext().getRouter().pushUrl({
          url: 'pages/Second'
        });
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

## addComponentContentWithOrder<sup>18+</sup>

addComponentContentWithOrder(content: ComponentContent, levelOrder?: LevelOrder): void

Creates an overlay node with the specified display order.

This API allows you to define the stacking order of the nodes when they are created.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description         |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | Yes   | Content to add to the new node on the **OverlayManager**.<br>**NOTE**<br> By default, the new node is centered on the page and stacked according to its stacking level.|
| levelOrder | [LevelOrder](js-apis-promptAction.md#levelorder18) | No   | Display order of the new floating layer node.<br>**NOTE**<br>- Default value: **LevelOrder.clamp(0)**|

**Example**

This example demonstrates how to use **addComponentContentWithOrder** to create an overlay node with the specified display order.

```ts
import { ComponentContent, PromptAction, LevelOrder, UIContext, OverlayManager } from '@kit.ArkUI';

class Params {
  text: string = "";
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
  @State message: string = 'Dialog box';
  private ctx: UIContext = this.getUIContext();
  private promptAction: PromptAction = this.ctx.getPromptAction();
  private overlayNode: OverlayManager = this.ctx.getOverlayManager();
  @StorageLink('contentArray') contentArray: ComponentContent<Params>[] = [];
  @StorageLink('componentContentIndex') componentContentIndex: number = 0;
  @StorageLink('arrayIndex') arrayIndex: number = 0;
  @StorageLink("componentOffset") componentOffset: Position = { x: 0, y: 80 };

  build() {
    Row() {
      Column({ space: 10 }) {
        Button('OverlayManager Bottom Overlay')
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
              console.error('topOrder: ' + topOrder.getOrder());
            }
            let bottomOrder: LevelOrder = this.promptAction.getBottomOrder();
            if (bottomOrder !== undefined) {
              console.error('bottomOrder: ' + bottomOrder.getOrder());
            }
          })
        Button('OverlayManager Top Overlay')
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
              console.error('topOrder: ' + topOrder.getOrder());
            }
            let bottomOrder: LevelOrder = this.promptAction.getBottomOrder();
            if (bottomOrder !== undefined) {
              console.error('bottomOrder: ' + bottomOrder.getOrder());
            }
          })
      }.width('100%')
    }.height('100%')
  }
}
```

## removeComponentContent<sup>12+</sup>

removeComponentContent(content: ComponentContent): void

Removes a specified **ComponentContent** node from the **OverlayManager**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description         |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | Yes   | Content to remove from the **OverlayManager**.|

**Example**

See the example for [addComponentContent](#addcomponentcontent12).

## showComponentContent<sup>12+</sup>

showComponentContent(content: ComponentContent): void

Shows a specified **ComponentContent** node on the **OverlayManager**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description         |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | Yes   | Content to show on the **OverlayManager**.|

**Example**

See the example for [addComponentContent](#addcomponentcontent12).

## hideComponentContent<sup>12+</sup>

hideComponentContent(content: ComponentContent): void

Hides a specified **ComponentContent** node on the **OverlayManager**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description         |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | Yes   | Content to hide on the **OverlayManager**.|

**Example**

See the example for [addComponentContent](#addcomponentcontent12).

## showAllComponentContents<sup>12+</sup>

showAllComponentContents(): void

Shows all **ComponentContent** nodes on the **OverlayManager**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

See the example for [addComponentContent](#addcomponentcontent12).

## hideAllComponentContents<sup>12+</sup>

hideAllComponentContents(): void

Hides all **ComponentContent** nodes on the **OverlayManager**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

See the example for [addComponentContent](#addcomponentcontent12).
