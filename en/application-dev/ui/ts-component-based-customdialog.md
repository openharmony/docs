# @CustomDialog


The @CustomDialog decorator is used to decorate custom pop-up dialog boxes.


  
```
// custom-dialog-demo.ets
@CustomDialog
struct DialogExample {
    controller: CustomDialogController;
    action: () => void;

    build() {
        Row() {
            Button ("Close CustomDialog")
                .onClick(() => {
                    this.controller.close();
                    this.action();
                })
        }.padding(20)
    }
}

@Entry
@Component
struct CustomDialogUser {
    dialogController : CustomDialogController = new CustomDialogController({
        builder: DialogExample({action: this.onAccept}),
        cancel: this.existApp,
        autoCancel: true
    });

    onAccept() {
        console.log("onAccept");
    }
    existApp() {
        console.log("Cancel dialog!");
    }

    build() {
        Column() {
            Button("Click to open Dialog")
                .onClick(() => {
                    this.dialogController.open()
                })
        }
    }
}
```
