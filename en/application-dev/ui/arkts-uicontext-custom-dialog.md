# Global Custom Dialog Box Independent of UI Components (Recommended)


Due to the restrictions of [CustomDialogController](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md#customdialogcontroller), which does not support dynamic creation or refresh, for more complex use cases, you are advised to use the [openCustomDialog](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialog12) API provided by the **PromptAction** object obtained from **UIContext** to implement a custom dialog box.


## Opening and Closing a Custom Dialog Box

1. Create a **ComponentContent** instance.

   **ComponentContent** is used to define the content of the custom dialog box. **wrapBuilder(buildText)** encapsulates the custom component, and **new Params(this.message)** is the input parameter for the custom component, which can be omitted or passed in with basic data types.

   ```ts
   private contentNode: ComponentContent<Object> = new ComponentContent(this.ctx, wrapBuilder(buildText), new Params(this.message));
   ```

2. Open the custom dialog box.

   Call **openCustomDialog** to open the custom dialog box, whose **customStyle** is set to **true** by default, meaning that the dialog box is styled entirely based on the **contentNode** settings you provide.

   ```ts
   this.ctx.getPromptAction().openCustomDialog(this.contentNode, this.options)
     .then(() => {
       console.info('OpenCustomDialog complete.')
     })
     .catch((error: BusinessError) => {
       let message = (error as BusinessError).message;
       let code = (error as BusinessError).code;
       console.error(`OpenCustomDialog args error code is ${code}, message is ${message}`);
     })
   ```

3. Close the custom dialog box.

   Call **closeCustomDialog**, which requires the ComponentContent corresponding to the dialog box to be closed. To set a close method within the dialog box, follow the complete sample to encapsulate this functionality into a static method.

   To release the corresponding ComponentContent after the dialog box is closed, call the **dispose** API of the ComponentContent.

   ```ts
   this.ctx.getPromptAction().closeCustomDialog(this.contentNode)
     .then(() => {
       console.info('CloseCustomDialog complete.')
     })
     .catch((error: BusinessError) => {
       let message = (error as BusinessError).message;
       let code = (error as BusinessError).code;
       console.error(`CloseCustomDialog args error code is ${code}, message is ${message}`);
     })
   ```

## Updating the Content of a Custom Dialog Box

ComponentContent has the same usage constraints as [BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md) and does not support custom components using decorators such as [@Reusable](../quick-start/arkts-create-custom-components.md#basic-structure-of-a-custom-component), [@Link](../quick-start/arkts-link.md), [@Provide](../quick-start/arkts-provide-and-consume.md), and [@Consume](../quick-start/arkts-provide-and-consume.md) to synchronize the state between the page where the dialog box pops up and the custom component in ComponentContent. Therefore, if you need to update the content of the custom component in the dialog box, use the **update** API provided by ComponentContent.
```ts
this.contentNode.update(new Params('update'))
```

## Updating the Attributes of a Custom Dialog Box

You can dynamically update the attributes of the dialog box through **updateCustomDialog**. Currently, the following attributes are supported: **alignment**, **offset**, **autoCancel**, and **maskColor**.
Note that when attributes are updated, those unset will be restored to their default values. For example, if you initially set **{ alignment: DialogAlignment.Top, offset: { dx: 0, dy: 50 } }** and then update it to **{ alignment: DialogAlignment.Bottom }**, the initially set **offset: { dx: 0, dy: 50 }** will not be retained; the offset will be restored to the default value.
```ts
this.ctx.getPromptAction().updateCustomDialog(this.contentNode, options)
  .then(() => {
    console.info('UpdateCustomDialog complete.')
  })
  .catch((error: BusinessError) => {
    let message = (error as BusinessError).message;
    let code = (error as BusinessError).code;
    console.error(`UpdateCustomDialog args error code is ${code}, message is ${message}`);
  })
```

## Sample

```ts
// PromptActionClass.ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ComponentContent, window } from '@kit.ArkUI';
import { UIContext } from '@ohos.arkui.UIContext';

export class PromptActionClass {
  static ctx: UIContext;
  static contentNode: ComponentContent<Object>;
  static options: Object;

  static setContext(context: UIContext) {
    this.ctx = context;
  }

  static setContentNode(node: ComponentContent<Object>) {
    this.contentNode = node;
  }

  static setOptions(options: Object) {
    this.options = options;
  }

  static openDialog() {
    if (this.contentNode !== null) {
      this.ctx.getPromptAction().openCustomDialog(this.contentNode, this.options)
        .then(() => {
          console.info('OpenCustomDialog complete.')
        })
        .catch((error: BusinessError) => {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`OpenCustomDialog args error code is ${code}, message is ${message}`);
        })
    }
  }

  static closeDialog() {
    if (this.contentNode !== null) {
      this.ctx.getPromptAction().closeCustomDialog(this.contentNode)
        .then(() => {
          console.info('CloseCustomDialog complete.')
        })
        .catch((error: BusinessError) => {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`CloseCustomDialog args error code is ${code}, message is ${message}`);
        })
    }
  }

  static updateDialog(options: Object) {
    if (this.contentNode !== null) {
      this.ctx.getPromptAction().updateCustomDialog(this.contentNode, options)
        .then(() => {
          console.info('UpdateCustomDialog complete.')
        })
        .catch((error: BusinessError) => {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`UpdateCustomDialog args error code is ${code}, message is ${message}`);
        })
    }
  }
}
```

```ts
// Index.ets
import { ComponentContent } from '@kit.ArkUI';
import { PromptActionClass } from './PromptActionClass';

class Params {
  text: string = ""

  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
    Button('Close')
      .onClick(() => {
        PromptActionClass.closeDialog()
      })
  }.backgroundColor('#FFF0F0F0')
}

@Entry
@Component
struct Index {
  @State message: string = "hello"
  private ctx: UIContext = this.getUIContext();
  private contentNode: ComponentContent<Object> =
    new ComponentContent(this.ctx, wrapBuilder(buildText), new Params(this.message));

  aboutToAppear(): void {
    PromptActionClass.setContext(this.ctx);
    PromptActionClass.setContentNode(this.contentNode);
    PromptActionClass.setOptions({ alignment: DialogAlignment.Top, offset: { dx: 0, dy: 50 } });
  }

  build() {
    Row() {
      Column() {
        Button("open dialog and update options")
          .margin({ top: 50 })
          .onClick(() => {
            PromptActionClass.openDialog()

            setTimeout(() => {
              PromptActionClass.updateDialog({
                alignment: DialogAlignment.Bottom,
                offset: { dx: 0, dy: -50 }
              })
            }, 1500)
          })
        Button("open dialog and update content")
          .margin({ top: 50 })
          .onClick(() => {
            PromptActionClass.openDialog()

            setTimeout(() => {
              this.contentNode.update(new Params('update'))
            }, 1500)
          })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```
