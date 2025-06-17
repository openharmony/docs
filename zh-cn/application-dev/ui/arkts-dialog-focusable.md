# 弹出框焦点策略
ArkUI的弹出框焦点策略可以设定是否中断用户当前操作，并聚焦到新弹出的弹出框。若设定弹出框不获取焦点，则新弹出时不会中断用户当前操作，例如，当用户正在文本框中输入内容时，新弹出的弹出框不会关闭软键盘，焦点仍保留在文本框中。

从API version 19开始，可以通过设置[focusable](../reference/apis-arkui/js-apis-promptAction.md#basedialogoptions11)参数来管理弹出框是否获取焦点。

## 使用约束

[openCustomDialog](arkts-uicontext-custom-dialog.md)和[CustomDialog](arkts-common-components-custom-dialog.md)支持通过focusable参数来管理弹出框是否获取焦点。

> **说明：**
> 
> 只有弹出覆盖在当前窗口之上的弹出框才可以获取焦点。

## 创建不获取焦点的弹出框

> **说明：**
> 
> 详细变量定义请参考[完整示例](#完整示例)。

1. 初始化一个弹出框内容区域，内含一个Text组件。

  ```ts
  private message = '弹窗'
  @State dialogIdIndex: number = 0
  @Builder customDialogComponent() {
    Column({ space: 5 }) {
      Text(this.message + this.dialogIdIndex)
        .fontSize(30)
    }
    .height(200)
    .padding(5)
    .justifyContent(FlexAlign.SpaceBetween)
  }
  ```

2. 创建一个TextInput组件，在onChange事件函数中通过调用[UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext)中的[getPromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#getpromptaction)方法获取[PromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#promptaction)对象，再通过该对象调用[openCustomDialog](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialog12)接口，并设置[focusable](../reference/apis-arkui/js-apis-promptAction.md#basedialogoptions11)参数为false，以创建弹出框。

  ```ts
  TextInput()
    .onChange(() => {
      this.dialogIdIndex++
      this.getUIContext().getPromptAction().openCustomDialog({
        builder: () => {
          this.customDialogComponent()
        },
        focusable: false
      }).then((dialogId: number) => {
        setTimeout(() => {
          this.getUIContext().getPromptAction().closeCustomDialog(dialogId);
        }, 3000)
      })
    })
  ```

## 完整示例
当用户正在文本框中输入内容时，新弹出的弹出框不会关闭软键盘，焦点仍保留在文本框中。
  ```ts
  @Entry
  @Component
  export struct Index {
    private message = '弹窗'
    @State dialogIdIndex: number = 0
    @Builder customDialogComponent() {
      Column({ space: 5 }) {
        Text(this.message + this.dialogIdIndex)
          .fontSize(30)
      }
      .height(200)
      .padding(5)
      .justifyContent(FlexAlign.SpaceBetween)
    }

    build() {
      Column({ space: 5 }) {
        TextInput()
          .onChange(() => {
            this.dialogIdIndex++
            this.getUIContext().getPromptAction().openCustomDialog({
              builder: () => {
                this.customDialogComponent()
              },
              focusable: false
            }).then((dialogId: number) => {
              setTimeout(() => {
                this.getUIContext().getPromptAction().closeCustomDialog(dialogId);
              }, 3000)
            })
          })
      }.width('100%')
    }
  }
  ```
![dialog-focusable-demo1](figures/dialog-focusable-demo1.gif)
