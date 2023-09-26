# Custom Dialog Box (CustomDialog)


A custom dialog box is a dialog box you customize by using APIs of the **CustomDialogController** class. It can be used for user interactions, showing an ad, prize, alert, software update message, and more. For details, see [Custom Dialog Box](../reference/arkui-ts/ts-methods-custom-dialog-box.md).


## Creating a Custom Dialog Box

1. Use the \@CustomDialog decorator to create a custom dialog box.

2. Set the content for the \@CustomDialog decorated dialog box.

   ```ts
   @CustomDialog
   struct CustomDialogExample1 {
     controller: CustomDialogController | undefined
     build() {
       Column() {
         Text ('I am content')
         .fontSize(20)
         .margin({ top: 10, bottom: 10 })
       }
     }
   }
   ```

3. Create a builder that is bound to the decorator.

   ```ts
   let bud:Record<string,string> = {}
   let obj:object|undefined = undefined
   dialogController: obj = new CustomDialogController({
       builder: CustomDialogExample(bud),
   })
   ```

4. Click the component bound to the **onClick** event to display the dialog box.

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

   ![en-us_image_0000001562700493](figures/en-us_image_0000001562700493.png)


## Interaction with Custom Dialog Box

Custom dialog boxes can be used for data interactions to complete a series of response operations.


1. Add button operations to the \@CustomDialog decorator and add the creation of data functions.

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
        Text('I am content') .fontSize(20).margin({ top: 10, bottom: 10 })
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

2. Receive the page in the builder and create corresponding function operations.

    ```ts
    dialogController: object = new CustomDialogController({
      builder: CustomDialogExample({
        cancel: this.onCancel,
        confirm: this.onAccept,
      }),
      alignment: DialogAlignment.Default,  // Set the alignment mode of the dialog box. By default, the dialog box is displayed at the bottom.
    })
    onCancel() {
      console.info('Callback when the first button is clicked')
    }
    onAccept() {
      console.info('Callback when the second button is clicked')
    }
    ```

   ![en-us_image_0000001511421320](figures/en-us_image_0000001511421320.png)
