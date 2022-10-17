# ArkUI (eTS) Development



## What are the restrictions on using generator functions in TypeScript?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Below are the restrictions on using generator functions in TypeScript:

- Expressions can be used only in character strings (in the ${expression} format), **if** conditions, **ForEach** parameters, and component parameters.

- No expressions should cause any application state variables (including **\@State**, **\@Link**, and **\@Prop**) to change. Otherwise, undefined and potentially unstable framework behavior may occur.

- The generator function cannot contain local variables.

None of the above restrictions apply to anonymous function implementations of event handlers (such as **onClick**).

Negative example:


```
build() {
  let a: number = 1 // invalid: variable declaration not allowed
  Column() {
    Text('Hello ${this.myName.toUpperCase()}') // ok.
    ForEach(this.arr.reverse(), ..., ...) // invalid: Array.reverse modifies the @State array varible in place
  }
  buildSpecial()  // invalid: no function calls
  Text(this.calcTextValue()) // this function call is ok.
}
```

## How do I use router to implement page redirection in the stage model?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

To implement page redirection through **router**, add all redirected-to pages to the pages list in the **main_pages.json** file.

Page routing APIs in **router** can be invoked only after page rendering is complete. Do not call these APIs in **onInit** or **onReady** when the page is still in the rendering phase.

## Will a page pushed into the stack through router.push be reclaimed?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

After being pushed to the stack through **router.push**, a page can be reclaimed only when it is popped from the stack through **router.back**.

## How do I dynamically replace the %s placeholder in a resource file?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

In an application, you can replace the %s placeholder by using the second parameter in `$r('app.string.xx')`, which is used to reference application resources.

Example:

```
build() {
  //do something
  // The second parameter indicates the referenced string resource, which can be used to replace the %s placeholder.
  Text($r('app.string.entry_desc','aaa')) 
    .fontSize(100)
    .fontColor(Color.Black)
  //do something
}
```

## How do I read an XML file in Resource and convert data in it to the string type?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

1. Obtain data in Uint8Array format by calling the **RawFile** API of **resourceManager**.

2. Convert data in Uint8Array format to the string type by calling the **String.fromCharCode** API.

Reference: [Resource Management](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-resource-manager.md)

Example:


```
resourceManager.getRawFile(path, (error, value) => {
  if (error != null) {
    console.log("error is " + error);
  } else {
    let rawFile = value;
    let xml = String.fromCharCode.apply(null, rawFile)
  }
});
```

## How do I convert a Resource object to the string type?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Use the **resourceManager.getString()** API of the **\@ohos.resourceManager** module.

Reference: [Resource Management](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-resource-manager.md#getstring)

## What should I do if the global static variables of a class do not work?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Objects imported to abilities and pages are packaged into two different closures, that is, two global objects. In this case, a static variable referenced by the abilities is not the same object as that referenced by the pages. Therefore, global variables cannot be defined by defining static variables in the class. You are advised to use AppStorage to manage global variables.

Reference: [AppStorage](https://docs.openharmony.cn/pages/v3.2Beta/en/application-dev/ui/ts-application-states-appstorage.md/)

## How do I obtain resources in the stage model?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

The stage model allows an application to obtain a **ResourceManager** object based on **context** and call its resource management APIs without first importing the required bundle. This method, however, is not applicable to the FA model.

Example:


```
const context = getContext(this) as any
context 
  .resourceManager
  .getString($r('app.string.entry_desc').id)
  .then(value => {
    this.message = value.toString()
})
```

## How do I position a container component to the bottom of the screen?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Create a **<Stack\>** component, and set the target container at the bottom of the **<Stack\>** component.

Example:

```
build() {
  Stack({alignContent : Alignment.Bottom}) {
    // The container is at the bottom.
    Stack() {
      Column()
      .width('100%')
      .height('100%')
      .backgroundColor(Color.Yellow)
    }
    .width('100%')
    .height('10%')
  }
  .width('100%')
  .height('100%')
  .backgroundColor('rgba(255,255,255, 0)')
}
```

## Can CustomDialog be used in TypeScript files?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

No. Currently, **CustomDialog** can be used only on eTS pages.

Reference: [Custom Dialog Box](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/arkui-ts/ts-methods-custom-dialog-box.md)

## How do I transfer variables in CustomDialog to variables on pages?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

Use a custom callback so that when the confirm button in the custom dialog box is clicked, the value of **data** is transferred from the dialog box to the current page.

Example:


```
// CustomDialog component
@CustomDialog
struct MyDialog {
  controller: CustomDialogController
  title: string
  data: string
  cancel: () => void
  confirm: (data: string) => void
  Button('confirm')
    .onClick(() => {
      this.controller.close()
      this.data = 'test'
      this.confirm(this.data)
    }).backgroundColor(0xffffff).fontColor(Color.Red)
// Page
@Entry
@Component
struct DialogTest {
  dialogController: CustomDialogController = new CustomDialogController({
    builder: MyDialog({ title:'Custom Title',cancel: this.onCancel,
    confirm: this.onAccept.bind(this)}), // Bind the custom callback to the button.
    cancel: this.existApp,
    autoCancel: true
  })
  onAccept(data:string) {
    console.info('Callback when the second button is clicked ' + data)
  }
}
```

## What should I do if the \<List> component cannot be dragged to the bottom after it has a \<Text> component added?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

The **\<List>** component is a scrollable container. By default, it takes up the entire screen height. When any component with a fixed height takes up part of the screen height, you need to explicitly specify **layoutWeight(1)** for the parent container of the **\<List>** component to take up the remaining height instead of the entire screen height.

## How do I center child components in a grid container?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

By default, child components in a **\<GridContainer>** are horizontally aligned to the left. To center them, perform the following steps:

Nest a **\<Row>** component and set it to **justifyContent(FlexAlign.Center)**. For details, see [Grid Layout](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/ui/ui-ts-layout-grid-container.md).

  Example:

```
GridContainer({ sizeType: SizeType.SM, columns: 12 }) {
  Row() {
    Text('1')
    .useSizeType({
      sm: { span: 4, offset: 0 },
    })
    .backgroundColor(0x46F2B4)
  }.justifyContent(FlexAlign.Center) // Center child components.
}
```

## How do I obtain the height of the status bar and navigation bar?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Before the window content is loaded, enable listening for the **systemAvoidAreaChange** event.

Example:

```
// MainAbility.ts
import window from '@ohos.window';

/**
 * Set the immersive window and obtain the height of the status bar and navigation bar.
 * @param mainWindow Indicates the main window.
 */
async function enterImmersion(mainWindow: window.Window) {
  mainWindow.on("systemAvoidAreaChange", (area: window.AvoidArea) => {
    AppStorage.SetOrCreate<number>("topHeight", area.topRect.height);
    AppStorage.SetOrCreate<number>("bottomHeight", area.bottomRect.height);
  })
  await mainWindow.setFullScreen(true)
  await mainWindow.setSystemBarEnable(["status", "navigation"])
  await mainWindow.setSystemBarProperties({
    navigationBarColor: "#00000000",
    statusBarColor: "#00000000",
    navigationBarContentColor: "#FF0000",
    statusBarContentColor: "#FF0000"
  })
}
export default class MainAbility extends Ability {
  // do something
  async onWindowStageCreate(windowStage: window.WindowStage) {
    let mainWindow = await windowStage.getMainWindow()
    await enterImmersion(mainWindow)
    windowStage.loadContent('pages/index')
  }
  // do something
}
```

## How do I execute JavaScript functions in the \<Web> component in eTS code?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Call the **runJavaScript** API in the **WebController** to asynchronously execute JavaScript scripts. This API uses a callback to return the execution result. Note: **runJavaScript** can only be called after **loadUrl** has been completed. For example, it can be called in **onPageEnd**.

Reference: [Web](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/arkui-ts/ts-basic-components-web.md)

## How do I fix misidentification of the pan gesture where container nesting is involved?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Set the **distance** attribute to **1** for the gesture. By default, this attribute is set to **5**.
