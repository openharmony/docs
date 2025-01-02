# 不依赖UI组件的全局自定义弹出框 (openCustomDialog)（推荐）

由于[CustomDialogController](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md#customdialogcontroller)在使用上存在诸多限制，不支持动态创建也不支持动态刷新，在相对较复杂的应用场景中推荐使用UIContext中获取到的PromptAction对象提供的[openCustomDialog](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialog12)接口来实现自定义弹出框。

> **说明：**
> 
> 弹出框（openCustomDialog）存在两种入参方式创建自定义弹出框：
> - openCustomDialog（传参为ComponentContent形式）：通过ComponentContent封装内容可以与UI界面解耦，调用更加灵活，可以满足开发者的封装诉求。拥有更强的灵活性，弹出框样式是完全自定义的，且在弹出框打开之后可以使用updateCustomDialog方法动态更新弹出框的一些参数。
> - openCustomDialog（传builder的形式）：相对于ComponentContent，builder必须要与上下文做绑定，与UI存在一定耦合。此方法有用默认的弹出框样式，适合于开发者想要实现与系统弹窗默认风格一致的效果。
> 
> 本文介绍通过入参形式为ComponentContent创建自定义弹出框，传builder形式的弹出框使用方法可参考[openCustomDialog](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialog12-1)。

弹出框（openCustomDialog）可以通过配置[isModal](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialog12)来实现模态和非模态弹窗。isModal为true时，弹出框为模态弹窗。isModal为false时，弹出框为非模态弹窗。

## 生命周期

弹出框提供了生命周期函数用于通知用户该弹出框的生命周期。生命周期的触发时序依次为：onWillAppear -> onDidAppear -> onWillDisappear -> onDidDisappear。

| 名称            |类型| 说明                       |
| ----------------- | ------ | ---------------------------- |
| onDidAppear    | () => void  | 弹出框弹出时的事件回调。    |
| onDidDisappear |() => void  | 弹出框消失时的事件回调。    |
| onWillAppear    | () => void | 弹出框显示动效前的事件回调。 |
| onWillDisappear | () => void | 弹出框退出动效前的事件回调。 |

## 自定义弹出框的打开与关闭

1. 创建ComponentContent。
   
   ComponentContent用于定义自定义弹出框的内容。其中，wrapBuilder(buildText)封装自定义组件，new Params(this.message)是自定义组件的入参，可以缺省，也可以传入基础数据类型。
   
   ```ts
   private contentNode: ComponentContent<Object> = new ComponentContent(this.ctx, wrapBuilder(buildText), new Params(this.message));
   ```
2. 打开自定义弹出框。
   
   通过调用openCustomDialog接口打开的弹出框默认为customStyle为true的弹出框，即弹出框的内容样式完全按照contentNode自定义样式显示。
   
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
3. 关闭自定义弹出框。
   
   由于closeCustomDialog接口需要传入待关闭弹出框对应的ComponentContent。因此，如果需要在弹出框中设置关闭方法，则可参考完整示例封装静态方法来实现。
   
   关闭弹出框之后若需要释放对应的ComponentContent，则需要调用ComponentContent的dispose方法。
   
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

## 更新自定义弹出框的内容

ComponentContent与[BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md)有相同的使用限制，不支持自定义组件使用[@Reusable](../../application-dev/quick-start/arkts-create-custom-components.md#自定义组件的基本结构)、[@Link](../../application-dev/quick-start/arkts-link.md)、[@Provide](../../application-dev/quick-start/arkts-provide-and-consume.md)、[@Consume](../../application-dev/quick-start/arkts-provide-and-consume.md)等装饰器，来同步弹出框弹出的页面与ComponentContent中自定义组件的状态。因此，若需要更新弹出框中自定义组件的内容可以通过ComponentContent提供的update方法来实现。

```ts
this.contentNode.update(new Params('update'))
```

## 更新自定义弹出框的属性

通过updateCustomDialog可以动态更新弹出框的属性。目前支持的属性包括alignment、offset、autoCancel、maskColor。
需要注意的是，更新属性时，未设置的属性会恢复为默认值。例如，初始设置{ alignment: DialogAlignment.Top, offset: { dx: 0, dy: 50 } }，更新时设置{ alignment: DialogAlignment.Bottom }，则初始设置的offset: { dx: 0, dy: 50 }不会保留，会恢复为默认值。

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

## 完整示例

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


