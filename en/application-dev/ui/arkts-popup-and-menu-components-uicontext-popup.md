# Global Popups Independent of UI Components (openPopup)

The [Popup](arkts-popup-and-menu-components-popup.md) API is a great option for creating popups, but it relies on a bound UI component to work. Since API version 18, however, the global API [openPopup](../reference/apis-arkui/js-apis-arkui-UIContext.md#openpopup18) offers a more flexible solution. This API can be used directly or encapsulated in scenarios where no bound UI components are available, making it ideal for use cases such as event callbacks or when integrating with external systems.

## Displaying a Popup

To display a popup, call the [openPopup](../reference/apis-arkui/js-apis-arkui-UIContext.md#openpopup18) API. Here's a basic example:
   
   ```ts
   promptAction.openPopup(contentNode, { id: targetId }, {
     enableArrow: true
   })
     .then(() => {
       console.info('openPopup success');
     })
     .catch((err: BusinessError) => {
       console.info('openPopup error: ' + err.code + ' ' + err.message);
     })
   ```

### Creating a ComponentContent Instance
   
   When using **openPopup**, you need to provide a [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md) instance to define the popup content. **wrapBuilder(buildText)** encapsulates the custom component, and **new Params(this.message)** is the input parameter for the custom component. This parameter is optional and can be a basic data type.
   
   ```ts
   private contentNode: ComponentContent<Object> = new ComponentContent(uiContext, wrapBuilder(buildText), this.message);
   ```
   
   If your **wrapBuilder** includes other components (such as [Popup](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Popup.md#popup) or [Chip](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Chip.md#chip)), the [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md#componentcontent-1) constructor must include four parameters, and the **options** parameter must be **{ nestingBuilderSupported: true }**.
   
   ```ts
   @Builder
   export function buildText(params: Params) {
     Popup({
       // Set the icon for the menu.
       icon: {
         image: $r('app.media.app_icon'),
         width: 32,
         height: 32,
         fillColor: Color.White,
         borderRadius: 10
       } as PopupIconOptions,
       // Set the text content.
       title: {
         text: `This is a Popup title 1`,
         fontSize: 20,
         fontColor: Color.Black,
         fontWeight: FontWeight.Normal
       } as PopupTextOptions,
       // Set the text content.
       message: {
         text: `This is a Popup message 1`,
         fontSize: 15,
         fontColor: Color.Black
       } as PopupTextOptions,
       // Set the buttons.
       buttons: [{
         text: 'confirm',
         action: () => {
           console.info('confirm button click')
         },
         fontSize: 15,
         fontColor: Color.Black,
       },
         {
           text: 'cancel',
           action: () => {
             console.info('cancel button click')
           },
           fontSize: 15,
           fontColor: Color.Black
         },] as [PopupButtonOptions?, PopupButtonOptions?]
     })
   }
   
   let contentNode: ComponentContent<Object> = new ComponentContent(uiContext, wrapBuilder(buildText), this.message, { nestingBuilderSupported: true });
   ```


### Providing Bound Component Information
   
   When calling **openMenu**, you must provide the [TargetInfo](../reference/apis-arkui/js-apis-arkui-UIContext.md#targetinfo18) of the bound component. Without a valid target, the popup won't display.
   
   ```ts
   let frameNode: FrameNode | null = this.ctx.getFrameNodeByUniqueId(this.getUniqueId());
   let targetId = frameNode?.getChild(0)?.getUniqueId();
   ```

### Customizing the Popup Style
   
   When calling **openPopup**, you can customize the menu style using [PopupCommonOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#popupcommonoptions18).
   
   ```ts
   private options: PopupCommonOptions = { enableArrow: true };
   ```

## Updating the Popup Style

To update the popup style, use the [updatePopup](../reference/apis-arkui/js-apis-arkui-UIContext.md#updatepopup18) API. You can update the style fully or incrementally. However, certain properties, including **showInSubWindow**, **focusable**, **onStateChange**, **onWillDismiss**, and **transition**, cannot be updated.
   
   ```ts
   promptAction.updatePopup(contentNode, {
     enableArrow: false
   }, true)
     .then(() => {
       console.info('updatePopup success');
     })
     .catch((err: BusinessError) => {
       console.info('updatePopup error: ' + err.code + ' ' + err.message);
     })
   ```

## Closing the Popup

To close the popup, call the [closePopup](../reference/apis-arkui/js-apis-arkui-UIContext.md#closepopup18) API.
   
   ```ts
   promptAction.closePopup(contentNode)
     .then(() => {
       console.info('closePopup success');
     })
     .catch((err: BusinessError) => {
       console.info('closePopup error: ' + err.code + ' ' + err.message);
     })
   ```

> **NOTE**
>
> The [updatePopup](../reference/apis-arkui/js-apis-arkui-UIContext.md#updatepopup18) and [closePopup](../reference/apis-arkui/js-apis-arkui-UIContext.md#closepopup18) APIs rely on the content to identify the menu. Therefore, you must maintain the content instance throughout the popup's lifecycle.


## Using the Global Popup in HAR Packages

You can encapsulate a popup using the [HAR](../quick-start/har-package.md) package to provide display, update, and close capabilities.

```ts
// library/src/main/ets/components/MainPage.ets

import { BusinessError } from '@kit.BasicServicesKit';
import { ComponentContent, TargetInfo, PromptAction } from '@kit.ArkUI';

export class PromptActionClass {
  private promptAction: PromptAction | null = null;
  private contentNode: ComponentContent<Object> | null = null;
  private options: PopupCommonOptions | null = null;
  private target: TargetInfo | null = null;
  private isPartialUpdate: boolean = false

  public setPromptAction(promptAction: PromptAction) {
    this.promptAction = promptAction;
  }

  public setContentNode(node: ComponentContent<Object>) {
    this.contentNode = node;
  }

  public setTarget(target: TargetInfo) {
    this.target = target;
  }

  public setOptions(options: PopupCommonOptions) {
    this.options = options;
  }

  public setIsPartialUpdate(isPartialUpdate: boolean) {
    this.isPartialUpdate = isPartialUpdate;
  }

  public openPopup() {
    if (this.promptAction != null) {
      this.promptAction.openPopup(this.contentNode, this.target, this.options)
        .then(() => {
          console.info('openPopup success');
        })
        .catch((err: BusinessError) => {
          console.info('openPopup error: ' + err.code + ' ' + err.message);
        })
    }
  }

  public closePopup() {
    if (this.promptAction != null) {
      this.promptAction.closePopup(this.contentNode)
        .then(() => {
          console.info('closePopup success');
        })
        .catch((err: BusinessError) => {
          console.info('closePopup error: ' + err.code + ' ' + err.message);
        })
    }
  }

  public updatePopup(options: PopupCommonOptions) {
    if (this.promptAction != null) {
      this.promptAction.updatePopup(this.contentNode, options, this.isPartialUpdate)
        .then(() => {
          console.info('updatePopup success');
        })
        .catch((err: BusinessError) => {
          console.info('updatePopup error: ' + err.code + ' ' + err.message);
        })
    }
  }
}
```

```ts
// entry/src/main/ets/pages/Index.ets

import { PromptActionClass } from "library";
import { ComponentContent, PromptAction } from '@kit.ArkUI';

class Params {
  text: string = ""
  promptActionClass: PromptActionClass = new PromptActionClass();

  constructor(text: string, promptActionClass: PromptActionClass) {
    this.text = text;
    this.promptActionClass = promptActionClass;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(20)
      .margin({ top: 10 })
    Button('Update')
      .margin({ top: 10 })
      .width(100)
      .onClick(() => {
        params.promptActionClass.updatePopup({
          enableArrow: false,
        })
      })
    Button('Close')
      .margin({ top: 10 })
      .width(100)
      .onClick(() => {
        params.promptActionClass.closePopup()
      })
  }.width(130).height(150)
}

@Entry
@Component
struct Index {
  @State message: string = "hello"
  private uiContext: UIContext = this.getUIContext();
  private promptAction: PromptAction = this.uiContext.getPromptAction();
  private promptActionClass: PromptActionClass = new PromptActionClass();
  private targetId: number = 0;
  private contentNode: ComponentContent<Object> =
    new ComponentContent(this.uiContext, wrapBuilder(buildText), new Params(this.message, this.promptActionClass));
  private options: PopupCommonOptions = { enableArrow: true };

  build() {
    Column() {
      Button("openPopup")
        .margin({ top: 50, left: 100 })
        .onClick(() => {
          let frameNode: FrameNode | null = this.uiContext.getFrameNodeByUniqueId(this.getUniqueId());
          let targetId = frameNode?.getChild(0)?.getUniqueId();
          if (targetId == undefined) {
            this.targetId = 0;
          } else {
            this.targetId = targetId;
          }
          this.promptActionClass.setPromptAction(this.promptAction);
          this.promptActionClass.setContentNode(this.contentNode);
          this.promptActionClass.setOptions(this.options);
          this.promptActionClass.setIsPartialUpdate(false);
          this.promptActionClass.setTarget({ id: this.targetId });
          this.promptActionClass.openPopup();
        })
    }
  }
}
```

![image](figures/UIopenPopup.gif)
