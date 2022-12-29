# ArkUI (ArkTS) Development

## How do I use router to implement page redirection in the stage model?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. To implement page redirection through **router**, add all redirected-to pages to the pages list in the **main_pages.json** file.

2. Page routing APIs in **router** can be invoked only after page rendering is complete. Do not call these APIs in **onInit** or **onReady** when the page is still in the rendering phase.

Reference: [Page Routing](../reference/apis/js-apis-router.md)

## Will a page pushed into the stack through router.push be reclaimed?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

After being pushed to the stack through **router.push**, a page can be reclaimed only when it is popped from the stack through **router.back**.

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

No. **CustomDialog** can be used only on ArkTS pages.

Reference: [Custom Dialog Box](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## How do I transfer variables in CustomDialog to variables on pages?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

Use a custom callback so that when the confirm button in the custom dialog box is clicked, the value of **data** is transferred from the dialog box to the current page.

Example:


```
// Dialog box component
@CustomDialog
struct MyDialog {
  controller: CustomDialogController
  title: string
  confirm: (data: string) => void
  data: string = ''

  build() {
    Row() {
      Column({ space: 10 }) {
        Text(this.title)
          .fontSize(30)
          .fontColor(Color.Blue)
        TextInput({ placeholder: "Enter content", text: this.data })
          .onChange((data) => {
            this.data = data // Obtain the data in the text box.
          })
        Button('confirm')
          .onClick(() => {
            this.confirm(this.data) // Transfer the data in the text box to the main page through the callback.
            this.controller.close()
          }).backgroundColor(0xffffff).fontColor(Color.Red)
      }.width("50%")
    }.height("50%")
  }
}

// Main page
@Entry
@Component
struct DialogTest {
  @State dialogTitle: string = ''
  @State dialogData: string = ''
  dialogController: CustomDialogController = new CustomDialogController({
    builder: MyDialog({
      title: this.dialogTitle, // Bind data.
      data: this.dialogData,
      confirm: this.confirm.bind(this) // Bind the custom callback. Change the direction of this here.
    })
  })

  confirm(data: string) {
    this.dialogData = data
    console.info(`recv dialog data: ${data}`) // Obtain the information entered in the dialog box.
  }

  build() {
    Row() {
      Column({ space: 10 }) {
        Button ('Open Dialog Box')
          .onClick(() => {
            this.dialogTitle ='Dialog Box'
            this.dialogController.open()
          })
        Text(`Accept pop-up window data:`)
          .fontSize(20)
        TextInput ({ placeholder: "Input", text: this.dialogData })
          .width("50%")
          .onChange((data) => {
            this.dialogData = data //Obtain the data in the text box.
          })
      }.width("100%")
    }.height("100%")
  }
}
```

## What should I do if the \<List> component cannot be dragged to the bottom after it has a \<Text> component added?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

The **\<List>** component is a scrollable container. By default, it takes up the entire screen height. When any component with a fixed height takes up part of the screen height, you need to explicitly specify **layoutWeight(1)** for the parent container of the **\<List>** component to take up the remaining height instead of the entire screen height.

## How do I center child components in a grid container?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

By default, child components in a **\<GridContainer>** are horizontally aligned to the left. To center them, perform the following steps:

Nest a **\<Row>** component and set it to **justifyContent(FlexAlign.Center)**. For details, see [Grid Layout](../reference/arkui-ts/ts-container-gridcontainer.md).

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
  await mainWindow.sArkTSystemBarProperties({
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

## How do I fix misidentification of the pan gesture where container nesting is involved?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Set the **distance** attribute to **1** for the gesture. By default, this attribute is set to **5**.

## How do I obtain the height of a component?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

You can obtain the changes in the width and height of a component through **onAreaChange**.

Example:


```
Column() {
  Text(this.value)
    .backgroundColor(Color.Green).margin(30).fontSize(20)
    .onClick(() => {
      this.value = this.value + 'Text'
    })
    .onAreaChange((oldValue: Area, newValue: Area) => {
      console.info(`Ace: on area change, oldValue is ${JSON.stringify(oldValue)} value is ${JSON.stringify(newValue)}`)
      this.size = JSON.stringify(newValue)
    })
```

## How do I obtain the offset of the \<List> component?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Bind the **\<List>** component to a **Scoller** object and obtain the offset through **currentOffset**.

Example:


```
Column() {
  List({ space: 20, initialIndex: 0,scroller: this.scroller}) {
    ForEach(this.arr, (item) => {
      ListItem() {
        Text('' + item)
          .width('100%').height(100).fontSize(16)
          .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
      }.editable(true)
    }, item => item)
  }
  .listDirection(Axis.Vertical) // Arrangement direction
  .editMode(this.editFlag)
  .onScroll((xOffset: number, yOffset: number) => {        
      console.info("yOffset======="+this.scroller.currentOffset().yOffset)
  })
}.width('100%')
```

## How do I obtain the value of param for the target page of redirection implemented using router?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9


```
// In versions earlier than 3.1.5.5, obtain the value through router.getParams().key.
private value: string = router.getParams().value;  
// In 3.1.6.5 and later versions, obtain the value through router.getParams()['key'].
private value: string = router.getParams()['value'];
```

## Does the \<RichText> component support redirection to a local page?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

No. This feature is not supported.

## How do I disable the transition effect for pages switched using router or navigator?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

1. Define the **pageTransition** method for the current and target pages, by following instructions in [Example](../reference/arkui-ts/ts-page-transition-animation.md#example).

2. Set the **duration** parameter of both **PageTransitionEnter** and **PageTransitionExit** to **0**.

## How do I select the pixel unit during UI development?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

It depends.

The vp unit ensures consistency of visual effects across resolutions. For example, it ensures that an icon is displayed consistently under different resolutions.

The lpx unit produces a visual effect where items are zoomed in or out proportionally.

If you are concerned about visual effect consistency of items, for example, buttons, texts, and lists, use the vp unit. If your focus is on the layout, for example, 1/2 grid, the lpx is a better choice.

## What color formats are used in ArkTS?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

The color can be represented in two formats, for example, 0x7F000000 or '\#7F000000'. The first two digits indicate opacity, and the last six digits indicate RGB.


```
fontColor(0x7F000000)
fontColor( '#7F000000' )
```

## How do I listen for the return operation on a page?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

When a return operation is performed on a page, the system calls the **onBackPress()** callback of the **@Entry** decorated custom component. You can implement related service logic in the callback.

Reference: [Custom Component Lifecycle Callbacks](../ui/ui-ts-custom-component-lifecycle-callbacks.md)

## Can I customize the eye icon for the \<TextInput> component in password mode?

Applicable to: OpenHarmony SDK 3.0, stage model of API version 9

No. The eye icon can be shown or hidden through **showPasswordIcon** when **type** of the **\<TextInput>** component is set to **InputType.Password**. It cannot be customized.

Reference: [TextInput](../reference/arkui-ts/ts-basic-components-textinput.md)

## Why can't images be loaded over HTTP?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

HTTP is insecure and HTTP sources will be filtered out by the trustlist. For security purposes, use HTTPS.

## What should I do if the spacing set for the TextView layout does not fit the UI?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

By default, the **align** attribute of **TextView** is set to **Center**. To display the text from left to right, set the **align** attribute to **Start**.

## Why do the constraintSize settings fail to take effect?

Applicable to: OpenHarmony SDK 3.0, stage model of API version 9

If **constraintSize** is set for a component and the width of its child component is set to a percentage, for example, **width('100%')**, **constraintSize** takes effect by multiplying the maximum width by the percentage. As a result, the child component may overflow, in which case it looks like the **constraintSize** settings fail to take effect.

## How do I set the background color to transparent?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Set **backgroundColor** to **'\#00000000'**.

## What should I do if the \<Scroll> component cannot scroll to the bottom?

Applicable to: OpenHarmony SDK 3.0, stage model of API version 9

Unless otherwise specified, the height of the **\<Scroll>** component is equal to the window height. In this case, the component's bottom area will be blocked by components (if any) outside of it. To fix this issue, set the height of the **\<Scroll>** component or use the flex layout to limit this height.

## How do I use the onSubmit event of the \<TextInput> component?

Applicable to: OpenHarmony SDK 3.0, stage model of API version 9

The **onSubmit** event is triggered when the Enter key is pressed and accepts the current Enter key type as its input parameter. You can set the Enter key type for the **\<TextInput>** component through the **enterKeyType** attribute. The Enter key style of the soft keyboard requires the support of the input method.

Reference: [TextInput](../reference/arkui-ts/ts-basic-components-textinput.md)

## What is the maximum number of pages allowed during page routing?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

The maximum number of pages supported by the page stack is 32. When this limit is reached, the **router.push** API cannot be used for page redirection.

## Does ArkUI allow components to be dynamically created in code?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

Yes. You can dynamically creaete components using [conditional rendering](../quick-start/arkts-rendering-control.md#conditional-rendering) and [loop rendering](../quick-start/arkts-rendering-control.md#loop-rendering).

## What should I do if the PixelMap object carried in page routing cannot be obtained from the target page?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

Page routing supports only the common object type and common JSON data structure. To pass a **PixelMap** object to the target page, store it in the **localStorage**.

## How do I use .caretPosition(0) to move the caret to the start of the text area when onEditChange is triggered for the \<TextInput> component?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

The **onEditChange** event is triggered when the input box gains focus. Under this scenario, the caret position is related to the position where the gesture is when the event is triggered, and **caretPosition** cannot be used to change the caret position. Call **setTimeout** for asynchronous processing first.

## Is there any method for selecting all items in the \<TextInput> component?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

No. This feature is not supported yet.

## Why can't I select a date when the type attribute of the input text box is set to date?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

Setting the **type** attribute of the input component to **date** means that the component accepts dates as input and the user will be notified of the valid input format. It does not display a date picker. To display a date picker, use the **\<DatePicker>** component.

## What should I do if the displayed input keyboard gets squeezed when using the **\<TextInput>** component?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

This issue may occur when the flex layout is used. To fix it, switch to the column layout.

## How does the parent component pass values to a @Link decorated member variable in its child component?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

To pass a value from the parent component to the **@Link** decorated member variable in a child component, add **"$"** in front of the value.

Example:


```
@Component
struct FoodImageDisplay {
  @Link imageSrc: Resource

  build() {
    Stack({ alignContent: Alignment.BottomStart }) {
      Image(this.imageSrc)
        .objectFit(ImageFit.Contain)
      Text('Tomato')
        .fontSize(26)
        .fontWeight(500)
        .margin({ left: 26, bottom: 17.4 })
    }
    .backgroundColor('#FFedf2f5')
    .height(357)
  }
}

@Entry
@Component
struct FoodDetail {

  @State imageSrc: Resource = $r('app.media.Tomato')

  build() {
    Column() {
      FoodImageDisplay({imageSrc:$imageSrc})
    }
    .alignItems(HorizontalAlign.Center)
  }
}
```

## How do I share variables between Page abilities?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

1. Use a lightweight database.

2. Use persistent data management.

3. Use the emitter event communication mechanism.


## How do I customize the control bar style of the \<Video> component?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

1. Set **controls** to **false** to disable the default control bar.

2. Set **controller** for the **\<Video>** component.

3. Implement a custom control bar in ArkTS and use **VideoController** to control video playback.

## How do I optimize the performance when an ArkTS component is to be updated for multiple times?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Extract the ArkTS component to be updated into a custom component and update the **@State** decorated variables in the custom component to implement partial refresh.

## How do I optimize the \<Tab> component performance?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

When the **\<Tab>** component is on a tab page, other tab pages are not unloaded by the system and still occupy some memory. To improve performance, you can use **if** to check whether the current tab page is being displayed and unload it if it is not. In this way, the tab pages not being displayed can be unloaded and the memory occupied by them can be released.

## How do I set state-specific styles for a component?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

You can use the polymorphic style attribute to set styles of the component for different states (being stateless, in pressed state, in disabled state, in focused state, or in clicked state).

Reference: [Polymorphic Style](../reference/arkui-ts/ts-universal-attributes-polymorphic-style.md)

## Why can't the onBlur or onFocus callback be triggered?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

Only the Tab button and arrow buttons on the connected keyboard can be used to trigger the focus event. In addition, to trigger a focus event by a touch, the **focusOnTouch** attribute must be added for the component.

Reference: [Focus Control](../reference/arkui-ts/ts-universal-attributes-focus.md)

## What should I do if the flex width and height in the \<Scroll> component conflicts with the scrolling?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

The **\<Scroll>** component supports a single child component, whose height is subject to the content height. If the scrolling layout is abnormal due to asynchronous loading of an image within the content, you can set the minimum height for the child component through **constraintSize({ minHeight: '100%' })**.

## How do I block the page router from returning to the previous page?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Call **router.clear()** to remove all historical pages in the page stack and retain the current page at the top of the stack.

Reference: [Page Routing](../reference/apis/js-apis-router.md)

## How do I clear the content of the \<TextInput> component at once?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

Refer to the following:


```
struct Index {
@State text: string = 'Hello World'
controller: TextInputController = new TextInputController()
  build() {
    Row() {
      Column() {
        TextInput({ placeholder: 'Please input your words.', text: this.text,
          controller:this.controller}).onChange((value) => {
            this.text = value
          })
        Button("Clear TextInput").onClick(() => {
          this.text = "";
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Can tab switching be disabled for the \<Tabs> component?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

No. This feature is not supported.

## An error is reported when @state is used to decorate the id member variable: "TypeError: cannot read property 'get' of undefined." Why?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

The ID has been added as a unique value and becomes a keyword.

## Can I use the fontFamily attribute to set different fonts for OpenHarmony applications?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

No. For applications developed based on OpenHarmony, the default font and also the only supported font is HarmonyOS Sans.

## What is the recommended data interaction mode between an ability and UI page?

Applicable to: OpenHarmony SDK 3.2.7.5, stage model of API version 9

[LocalStorage](../quick-start/arkts-state-mgmt-application-level.md#localstorage) is recommended.

## How does a parent component synchronize status with its grandchild components?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

- Method 1 (recommended): Use the **@Provide** and **@Consume** decorators. Specifically, use **@Provide** in the parent component and **@Consume** in the grandchild component to implement two-way data binding between the components.

- Method 2: Use the **@State** and **@Link** decorators. Specifically, use **@State** in the parent component, and **@Link** in all involved child and grandchild components.

## How do I display an ellipsis in cases when the string is too long to display in full?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

Example:


```
beautySub(str,len) {
	var reg = /[\u4e00-\u9fa5]/g;
	// Reduce characters whenever possible.
	var slice = str.substring(0,len)
	var charNum = (~~(slice.match(reg) && slice.match(reg).length))
	// The purpose of charNum-1 is to process the string that exceeds the maximum value. If the string exceeds the maximum value, the character that is not in current language is not displayed.
	var realen = slice.length*2 - charNum-1
	return str.substr(0,realen) + (realen < str.length ? "..." : "") +str.substr(str.length-realen,str.length)
}
```

## How do I add a scrollbar to the \<richText> component?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

The **\<RichText>** component is underpinned by web. To add a scrollbar, you can refer to the HTML syntax and add the **overflow: auto** style to **div**.

## How do I disable the scroll event of a grid in the \<Scroll> component?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

You can use the **onScrollBegin** event and the **scrollBy** method to implement nested scrolling of the containers.

Reference: [Scroll](../reference/arkui-ts/ts-container-scroll.md#example-2)

## Can the white background of the custom dialog box be removed?

Applicable to: OpenHarmony SDK 3.2.7.5, stage model of API version 9

No. This feature is not supported. The UI style is hardcoded in the framework and cannot be changed.

## Does the **backgroundImage** API support the SVG image format?

Applicable to: OpenHarmony SDK 3.2.7.5, stage model of API version 9

No. This image format is not supported.

## How do I set the position for a custom dialog box?

Applicable to: OpenHarmony SDK 3.2.7.5, stage model of API version 9

You can set the position for a custom dialog box through the **alignment** parameter. For example, to set the custom dialog box to show at the bottom, set **alignment** to **DialogAlignment.Bottom**.

Reference: [Custom Dialog Box](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## How does the scroller determine the end error of the rebound animation?

Applicable to: OpenHarmony SDK 3.2.5.3, FA model of API version 8

After the touch ends, a change in the same direction may be calculated. If the change is in the opposite direction, it indicates that a rebound occurs, and no processing is performed.


## How do I implement persistent storage of application data?

Use the **PersistentStorage** class to manage persistent application data. Persistent data with specific tags can be linked to the **AppStorage** and accessed through the **AppStorage** APIs.

Reference: [PersistentStorage](../quick-start/arkts-state-mgmt-application-level.md#persistentstorage)

Example:


```
AppStorage.Link('varA')
PersistentStorage.PersistProp("varA", "111");
@Entry
@Componentstruct Index {
  @StorageLink('varA') varA: string = ''
  build() {
    Column() {
      Text('varA: ' + this.varA).fontSize(20)
      Button('Set').width(100).height(100).onClick(() => {
        this.varA += '333'
      })
    }
    .width('100%')
    .height('100%')
  }
}
```
