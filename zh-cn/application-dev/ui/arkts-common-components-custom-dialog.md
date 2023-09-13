# 自定义弹窗（CustomDialog）


自定义弹窗CustomDialog可用于广告、中奖、警告、软件更新等与用户交互响应操作。开发者可以通过CustomDialogController类显示自定义弹窗。具体用法请参考[自定义弹窗](../reference/arkui-ts/ts-methods-custom-dialog-box.md)。


## 创建自定义弹窗

1. 使用\@CustomDialog装饰器装饰自定义弹窗。

2. \@CustomDialog装饰器用于装饰自定义弹框，此装饰器内进行自定义内容（也就是弹框内容）。

   ```ts
   @CustomDialog
   struct CustomDialogExample1 {
     controller: CustomDialogController | undefined
     build() {
       Column() {
         Text('我是内容')
         .fontSize(20)
         .margin({ top: 10, bottom: 10 })
       }
     }
   }
   ```

3. 创建构造器，与装饰器呼应相连。

   ```ts
   let bud:Record<string,string> = {}
   let obj:object|undefined = undefined
   dialogController: obj = new CustomDialogController({
       builder: CustomDialogExample(bud),
   })
   ```

4. 点击与onClick事件绑定的组件使弹窗弹出

  ```ts
  class dialogc{
    dialogController:CustomDialogController|undefined = undefined
    open(){
      if(this.dialogController){
        this.dialogController.open()
      }
    }
  }
  Flex({justifyContent:FlexAlign.Center}){
    Button('click me')
      .onClick(() => {
        let dia = new dialogc();
        dia.open()
      })
  }.width('100%')
  ```

   ![zh-cn_image_0000001562700493](figures/zh-cn_image_0000001562700493.png)


## 弹窗的交互

弹窗可用于数据交互，完成用户一系列响应操作。


1. 在\@CustomDialog装饰器内添加按钮操作，同时添加数据函数的创建。

  ```ts
  class cancelconfirmF{
    cancel():void{}
    confirm():void{}
  }
  @CustomDialog
  struct CustomDialogExample {
    controller: CustomDialogController | undefined
    build() {
      Column() {
        Text('我是内容').fontSize(20).margin({ top: 10, bottom: 10 })
        Flex({ justifyContent: FlexAlign.SpaceAround }) {
          Button('cancel')
            .onClick(() => {
              if(this.controller){
              this.controller.close()
              }
              let canf = new cancelconfirmF()
              canf.cancel()
            }).backgroundColor(0xffffff).fontColor(Color.Black)
          Button('confirm')
            .onClick(() => {
                if(this.controller){
                  this.controller.close()
                }
                let conf = new cancelconfirmF()
                conf.confirm()
            }).backgroundColor(0xffffff).fontColor(Color.Red)
        }.margin({ bottom: 10 })
      }
    }
  }
  ```

2. 页面内需要在构造器内进行接收，同时创建相应的函数操作。

    ```ts
    dialogController: object = new CustomDialogController({
      builder: CustomDialogExample({
        cancel: this.onCancel,
        confirm: this.onAccept,
      }),
      alignment: DialogAlignment.Default,  // 可设置dialog的对齐方式，设定显示在底部或中间等，默认为底部显示
    })
    onCancel() {
      console.info('Callback when the first button is clicked')
    }
    onAccept() {
      console.info('Callback when the second button is clicked')
    }
    ```

   ![zh-cn_image_0000001511421320](figures/zh-cn_image_0000001511421320.png)

## 相关实例

针对自定义弹窗开发，有以下相关实例可供参考：

- [`CustomDialog`：自定义弹窗（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/CustomDialog)

- [构建多种样式弹窗（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/MultipleDialog)

- [目标管理（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/TargetManagement)