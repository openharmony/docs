# ArkUI Development

## How do I dynamically replace the %s placeholder in a resource file?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

How do I dynamically replace the %s placeholder in a resource file?

**Solution**

In an application, you can replace the **%s** placeholder by using the second parameter in **$r('app.string.xx')**, which is used to reference application resources.

**Example**

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

## Can custom dialog boxes be defined or used in .ts files?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

Unfortunately, no. ArkTS syntax is required for defining and initializing custom dialog boxes. Therefore, they can be defined and used only in .ets files.

**Reference**

[Custom Dialog Box](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## How do I transfer variables in a custom dialog box to a page?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

The variable defined in a custom dialog box needs to be transferred to the page when the dialog box is closed or the variable changes.

**Solution**

-   Method 1: Define the variable as a state variable of the custom dialog box.
-   Method 2: During initialization of the custom dialog box, pass to it a method, which is triggered in the custom dialog box and accepts the variable in the custom dialog box as a parameter.
-   Method 3: Use AppStorage or LocalStorage to manage page state and implement state sharing between the custom dialog box and page.

**Example**

-   Method 1:

    ```
    @CustomDialog
    struct CustomDialog01 {
      @Link inputValue: string
      controller: CustomDialogController
      build() {
        Column() {
          Text('Change text').fontSize(20).margin({ top: 10, bottom: 10 })
          TextInput({ placeholder: '', text: this.inputValue }).height(60).width('90%')
            .onChange((value: string) => {
              this.inputValue = value
            })
        }
      }
    }
    
    @Entry
    @Component
    struct DialogDemo01 {
      @State inputValue: string = 'click me'
      dialogController: CustomDialogController = new CustomDialogController({
        builder: CustomDialog01({
          inputValue: $inputValue
        })
      })
    
      build() {
        Column() {
          Button(this.inputValue)
            .onClick(() => {
              this.dialogController.open()
            }).backgroundColor(0x317aff)
        }.width('100%').margin({ top: 5 })
      }
    }
    
    ```

-   Method 2:

    ```
    @CustomDialog
    struct CustomDialog02 {
      private inputValue: string
      changeInputValue: (val: string) => void
      controller: CustomDialogController
      build() {
        Column() {
          Text('Change text').fontSize(20).margin({ top: 10, bottom: 10 })
          TextInput({ placeholder: '', text: this.inputValue }).height(60).width('90%')
            .onChange((value: string) => {
              this.changeInputValue(value)
            })
        }
      }
    }
    
    @Entry
    @Component
    struct DialogDemo02 {
      @State inputValue: string = 'click me'
      dialogController: CustomDialogController = new CustomDialogController({
        builder: CustomDialog02({
          inputValue: this.inputValue,
          changeInputValue: (val: string) => {
            this.inputValue = val
          }
        })
      })
    
      build() {
        Column() {
          Button(this.inputValue)
            .onClick(() => {
              this.dialogController.open()
            }).backgroundColor(0x317aff)
        }.width('100%').margin({ top: 5 })
      }
    }
    
    ```

-   Method 3:

    ```
    let storage = LocalStorage.GetShared()
    @CustomDialog
    struct CustomDialog03 {
      @LocalStorageLink('inputVal')  inputValue: string = ''
      controller: CustomDialogController
      build() {
        Column() {
          Text('Change text').fontSize(20).margin({ top: 10, bottom: 10 })
          TextInput({ placeholder: '', text: this.inputValue }).height(60).width('90%')
            .onChange((value: string) => {
              this.inputValue = value;
            })
        }
      }
    }
    
    @Entry(storage)
    @Component
    struct DialogDemo03 {
      @LocalStorageLink('inputVal') inputValue: string = ''
      dialogController: CustomDialogController = new CustomDialogController({
        builder: CustomDialog03()
      })
    
      build() {
        Column() {
          Button(this.inputValue)
            .onClick(() => {
              this.dialogController.open()
            }).backgroundColor(0x317aff)
        }.width('100%').margin({ top: 5 })
      }
    }
    
    ```


## How do I obtain the width and height of a component?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

The width and height of a component need to be obtained to calculate the size and offset of the layout area.

**Solution**

-   Method 1: Use the **onAreaChange** event of the component, which is triggered when the component is initialized or the component size changes.
-   Manner 2: Use the callback in the click or touch event, which provides the area information of the target element.

**Reference**

[Component Area Change Event](../reference/arkui-ts/ts-universal-component-area-change-event.md), [Click Event](../reference/arkui-ts/ts-universal-events-click.md), [Touch Event](../reference/arkui-ts/ts-universal-events-touch.md)

## How do I clear the content of the \<TextInput> and \<TextArea> components by one click?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

A click-to-clear feature is required to remove all characters in the **\<TextInput>** and **\<TextArea>** component at once.

**Solution**

Convert the **text** attribute of the **\<TextInput>** and **\<TextArea>** component to a state variable. Assign an empty string to the state variable when the click-to-clear event is performed.

**Example**

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

## How do I set the position of a custom dialog box?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

By default, a custom dialog box is displayed in the center of the window. In some cases, it needs to be aligned with the window border.

**Solution**

During initialization of the custom dialog box, set the **alignment** and **offset** parameters.

**Reference**

[Custom Dialog Box](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## How do I hide the overflow content of a container component?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

When content overflows in a container component, that is, the child component does not fit in the container component, the overflow content needs to be processed.

**Solution**

To clip and hide overflow content, set the **clip** universal attribute to **true**. By default, this attribute is set to **false**.

**Reference**

[Shape Clipping](../reference/arkui-ts/ts-universal-attributes-sharp-clipping.md)


## How do I set a custom dialog box to automatically adapt its size to content?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

When a custom dialog box contains a child component whose area size can be changed, it needs to automatically adjust its size.

**Solution**

-   Method 1: Use the default style of the custom dialog box. In this case, the dialog box automatically adapts its width to the grid system and its height to the child components; the maximum height is 90% of the container height.
-   Method 2: Use a custom style of the custom dialog box. In this case, the dialog box automatically adapts its width and height to the child components.

**Reference**

[Custom Dialog Box](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## What is the function of the gridCount parameter in the custom dialog box?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

The **gridCount** parameter indicates the number of grid columns occupied by the dialog box. The system divides the window width into equal regions. The number of equal regions is the number of grid columns, which varies by device. For example, if the screen density of a phone is 320 vp <= horizontal width < 600 vp, the number of grid columns is 4, and the valid value of **gridCount** is \[1, 4\].

Note: This parameter is valid only when the custom dialog box is in the default style.

**Reference**

[Custom Dialog Box](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## How do I remove the white background of a custom dialog box?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

When in the default style a custom dialog box comes with a white background.

**Solution**

To remove the white background, set the custom dialog box to a custom style.

1.  During initialization of the custom dialog box, set **customStyle** to **true**.
2.  During initialization of the custom dialog box, set **backgroundColor** to the color you prefer.

**Reference**

[Custom Dialog Box](../reference/arkui-ts/ts-methods-custom-dialog-box.md)

## How do I customize the eye icon for the password input mode of the \<TextInput> component?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

The eye icon for the password input mode (with the **type** attribute of the **\<TextInput>** component set to **InputType.Password**) cannot be customized.

**Solution**

The eye icon itself cannot be customized. You can use set the **showPasswordIcon** attribute of the **\<TextInput>** component to **false** to hide the icon, and use the **\<Image>** component to control the type of the **\<TextInput>** component.

**Reference**

[TextInput](../reference/arkui-ts/ts-basic-components-textinput.md)

## How do I use the onSubmit event of the \<TextInput> component?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Solution**

The **onSubmit** event is triggered when a user presses **Enter** on the (physical or soft) keyboard. The callback parameter in the event is the current Enter key type. The Enter key type can be set through the **enterKeyType** attribute of the **\<TextInput>** component. Setting the key style of the soft keyboard requires support by the input method.

**Reference**

[TextInput](../reference/arkui-ts/ts-basic-components-textinput.md)

## How do I set the caret position to the start point for when the \<TextInput> component obtains focus?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

When the **\<TextInput>** component obtains focus, the caret automatically moves to the position of the touch point, instead of the start position.

**Solution**

1.  Bind the **\<TextInput>** component to the **onEditChange** event, which is triggered when the component enters the input state.
2.  Call the **setTimeout** API for asynchronous processing. Then call the **TextInputController.caretPosition** API in the event callback to set the caret position.

**Example**

```
@Entry
@Component
struct TextInputDemo {
  controller: TextInputController = new TextInputController()

  build() {
    Column() {
      TextInput({ controller: this.controller })
        .onEditChange((isEditing: boolean) => {
          if (isEditing) {
            setTimeout(() => {
              this.controller.caretPosition(0)
            }, 100)
          }
        })
    }
  }
}
```

**Reference**

[TextInput](../reference/arkui-ts/ts-basic-components-textinput.md)

## How do I obtain component attribute information?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Solution**

To obtain all attributes of a component, use **getInspectorByKey**.

**Reference**

[Component ID](../reference/arkui-ts/ts-universal-attributes-component-id.md)

## How do I obtain the current scrolling offset of a scrollable component?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Solution**

1.  During initialization of the scrollable component, such as **\<List>**, **\<Grid>**, and **\<Scroll>**, set the **scroller** parameter to bind the component to a scroll controller.
2.  Call the **currentOffset** API of the controller to obtain the horizontal and vertical scrolling offsets.

**Reference**

[Scroll](../reference/arkui-ts/ts-container-scroll.md#currentoffset)

## How do I align text vertically?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

Text cannot be aligned vertically in the **\<Text>** component.

**Solution**

Text is aligned horizontally in the **\<Text>** component. To enable text to align vertically, you can split the file, use the **\<Flex>** container component, and set its main axis direction to vertical.

**Example**

```
@Entry
@Component
struct Index15 {
  private message: string = 'This document is intended for novices in developing applications. It introduces you to the application development process and main files in the project director, by walking you through the building of a simple application with the page redirection/return feature.';
  build() {
    Flex({ direction: FlexDirection.Column, wrap: FlexWrap.Wrap }) {
      ForEach(this.message.split(''), (item, index) => {
        Text(item)
          .fontSize(30)
          .flexShrink(0)
      })
    }
  }
}
```

## How do I create a toast window?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

A toast window is required for delivering a toast message.

**Solution**

To create a toast window, use the **@ohos.promptAction** API.

**Reference**

[@ohos.promptAction (Prompt)](../reference/apis/js-apis-promptAction.md)

## Can I set the background or font color for the toast window?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

This feature is not supported currently.

**Reference**

[@ohos.promptAction (Prompt)](../reference/apis/js-apis-promptAction.md)

## How do I set the UI of an ability to transparent?

Applicable to: OpenHarmony 3.2 (API version 9)

**Solution**

Set the background color of the top container component to transparent, and then set the **opacity** attribute of the XComponent to **0.01**.

Example:

```
build() {
  Stack() {
    XComponent({
    id: 'componentId',
    type: 'surface',
    })
    .width('100%')
    .height('100%')
    .opacity(0.01)
    // Page content
  }
  .width('100%')
  .height('100%')
  .backgroundColor('rgba(255,255,255, 0)')
}
```

## Why do the constraintSize settings fail to take effect?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

If **constraintSize** is set for a component and the width of its child component is set to a percentage, for example, **width\('100%'\)**, **constraintSize** takes effect by multiplying the maximum width by the percentage. As a result, the child component may overflow, in which case it looks like the **constraintSize** settings fail to take effect.

**Solution**

You can use the **\<Scroll>** component at the outer layer. In this way, when **constraintSize** is set and the space occupied by a child component exceeds the specified constraint value, a scrollbar will be displayed.

## How do I set the background color to transparent?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Set **backgroundColor** to **'\#00000000'**.

## What should I do if the \<Scroll> component cannot scroll to the bottom?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

Unless otherwise specified, the height of the **\<Scroll>** component is equal to the window height. In this case, the component's bottom area will be blocked by components (if any) outside of it.

**Solution**

Set the height of the **\<Scroll>** component or use the flex layout to limit this height.

## What is the counterpart of CenterCrop in OpenHarmony for backgroundImage?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Solution**

To achieve the equivalent effect CenterCrop – place the image in the center of the window and scale the image while maintaining its aspect ratio, you can use the universal attributes **backgroundImageSize**\(**ImageSize.cover**\) and **backgroundImagePosition** \(**Alignment.Center**\).

## How do I customize the control bar style of the \<Video> component?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Solution**

1. Set **controls** to **false** to disable the default control bar.

2. Sets **controller** for the **\<Video>** component.

3. Implement a custom control bar in ArkTS and use **VideoController** to control video playback.

**Example**

```
// xxx.ets
@Entry@Componentstruct VideoCreateComponent {
  @State videoSrc: Resource = $rawfile('video1.mp4')
  @State previewUri: Resource = $r('app.media.poster1')
  @State curRate: PlaybackSpeed = PlaybackSpeed.Speed_Forward_1_00_X
  @State isAutoPlay: boolean = false
  @State showControls: boolean = true
  controller: VideoController = new VideoController()
   build() {
    Column() {
      Video({
        src: this.videoSrc,
        previewUri: this.previewUri,
        currentProgressRate: this.curRate,
        controller: this.controller
      }).width('100%').height(600)
        .autoPlay(this.isAutoPlay)
        .controls(this.showControls)
        .onStart(() => {
          console.info('onStart')
        })
        .onPause(() => {
          console.info('onPause')
        })
        .onFinish(() => {
          console.info('onFinish')
        })
        .onError(() => {
          console.info('onError')
        })
        .onPrepared((e) => {
          console.info('onPrepared is ' + e.duration)
        })
        .onSeeking((e) => {
          console.info('onSeeking is ' + e.time)
        })
        .onSeeked((e) => {
          console.info('onSeeked is ' + e.time)
        })
        .onUpdate((e) => {
          console.info('onUpdate is ' + e.time)
        })
             Row() {
        Button('src').onClick(() => {
          this.videoSrc = $rawfile('video2.mp4') // Switch the video source.
        }).margin(5)
        Button('previewUri').onClick(() => {
          this.previewUri = $r('app.media.poster2') // Switch the preview image.
        }).margin(5)

        Button('controls').onClick(() => {
          this.showControls =! this.showControls // Specify whether to show the control bar.
        }).margin(5)
      }
       Row() {
        Button('start').onClick(() => {
          this.controller.start() // Start playback.
        }).margin(5)
        Button('pause').onClick(() => {
          this.controller.pause() // Pause playback.
        }).margin(5)
        Button('stop').onClick(() => {
          this.controller.stop() // Stop playback.
        }).margin(5)
        Button('setTime').onClick(() => {
          this.controller.setCurrentTime(10, SeekMode.Accurate) // Seek to the 10s position of the video.
        }).margin(5)
      }
       Row() {
        Button('rate 0.75').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_0_75_X // Play the video at the 0.75x speed.
        }).margin(5)
        Button('rate 1').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_1_00_X // Play the video at the 1x speed.
        }).margin(5)
        Button('rate 2').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_2_00_X // Play the video at the 2x speed.
        }).margin(5)
      }
    }
  }}
```

**Reference**

[Video](../reference/arkui-ts/ts-media-components-video.md#start)

## How do I set state-specific styles for a component?

**Solution**

You can use the **stateStyles** attribute to set styles of a component for different states (stateless, pressed, disabled, focused, or clicked).

**Example**

```
//xxx.ts
@Entry
@Component
struct StyleExample {
  @State isEnable: boolean = true;

  @Styles pressedStyles() {
    .backgroundColor("#ED6F21")
    .borderRadius(10)
    .borderStyle(BorderStyle.Dashed)
    .borderWidth(2)
    .borderColor('#33000000')
    .width(120)
    .height(30)
    .opacity(1)
  }
  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center}) {
      Text("pressed")
        .backgroundColor('#0A59F7')
        .borderRadius(20)
        .borderStyle(BorderStyle.Dotted)
        .borderWidth(2)
        .borderColor(Color.Red)
        .width(100)
        .height(25)
        .opacity(1)
        .fontSize(14)
        .fontColor(Color.White)
        .stateStyles({
          pressed: this.pressedStyles
        })
        .margin({
          bottom: 20
        })
        .textAlign(TextAlign.Center)
    }
    .width(350)
    .height(300)
  }
}
```

**Reference**

[Polymorphic Style](../reference/arkui-ts/ts-universal-attributes-polymorphic-style.md)

## What should I do if the flex width and height in the \<Scroll> component conflicts with the scrolling?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

**Symptom**

When a container component with a fixed size is added to the **\<Scroll>** component, a scrolling error occurs.

**Solution**

Do not set a size for any container component in the **\<Scroll>** component. In this way, the **\<Scroll>** component can adapt its size to the content.

## What should I do if the height settings in position do not take effect?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

After **position** is set for a container component, the **height** settings do not work.

**Solution**

When **position** is set for a container component, it is taken out of normal flow and works independently from the outer container. In this case, the height does not take effect. You can replace the outer container with a stack to solve this issue.

## Why can't the onBlur or onFocus callback be triggered?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

By default, only the Tab button and arrow buttons on the connected keyboard can be used to trigger the focus event. To trigger a focus event by a touch, add the **focusOnTouch** attribute for the target component.

**Reference**

[Focus Control](../reference/arkui-ts/ts-universal-attributes-focus.md)

## How do I disable the scroll event of a \<Grid> nested in the \<Scroll>?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

You can use the **onScrollFrameBegin** event and **scrollBy** API to implement nested scrolling of the containers.

For details, see [Nested Scrolling Example](../reference/arkui-ts/ts-container-scroll.md#example-2).

## How do I enable a component to rotate continuously?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

You can use [attribute animation](../reference/arkui-ts/ts-animatorproperty.md) to that effect.

## How do I scroll a list with the keyboard?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

- Add **focusable\(true\)** to the list item to enable it to obtain focus.
- Nest a focusable component, for example, **\<Button>**, at the outer layer of each item.

## Why is the click event not triggered for the focused component upon the press of the Enter key after keyboard navigation?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

By default, the built-in click event of the component and the custom **onClick** click event are bound to the space bar instead of the Enter key.

## How do I block event bubbling when a button is nested in multi-layer components?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

You can bind the button to the **stopPropagation** parameter.

## How do I dynamically create components using code in ArkUI?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

ArkUI uses the ArkTS declarative development paradigm. Developers cannot hold component instances. During declaration, you can control component creation by rendering control syntax and dynamically building UI elements.

**Example**

```
// Create a component using the if statement.
if(this.isTrue) {
  Text ("Create Text Component").fontSize (30)
}
// Create a component using the ForEach statement.
ForEach(this.nums,(item) => {
  Text(item + '').fontSize(30)
},item => JSON.stringify(item))
```

**Reference**

[Overview of Rendering Control](../quick-start/arkts-rendering-control-overview.md)

## What is the difference between an @Builder decorated method and a regular method?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

The @Builder decorated method allows for use of a custom component, while regular methods do not. If a custom component is used in an @Builder decorated method, it is re-created each time the method is called.

**Reference**

[@BuilderParam](../quick-start/arkts-builderparam.md)

## How do I define @BuilderParam decorated attributes?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

-   Without parameters

    If no parameter is passed when assigning a value to the **@BuilderParam** decorated attribute (for example, **content: this.specificParam**), define the type of the attribute as a function without a return value (for example, **@BuilderParam content: \(\) =\> void**).

-   With parameters

    If any parameter is passed when assigning a value to the **@BuilderParam** decorated attribute (for example, **callContent: this.specificParam1\("111"\)**), define the type of the attribute as **any** (for example, **@BuilderParam callContent: any**).


**Reference**

[@BuilderParam](../quick-start/arkts-builderparam.md)

## How do I listen for object changes in an array?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

To listen for object changes in an array, use the @Observed and @ObjectLink decorators. **@Observed** applies to classes, and **@ObjectLink** applies to variables.

**Example**

1.  Use @Observed on a class.

    ```
    @Observed
    class ClassA {
      public name: string
      public c: number
      public id: number
    
      constructor(c: number, name: string = 'OK') {
        this.name = name
        this.c = c
      }
    }
    ```

2.  Use @ObjectLink on a component variable.

    ```
    @Component
    struct ViewA {
      label: string = 'ViewA1'
      @ObjectLink a: ClassA
    
      build() {
        Row() {
          Button(`ViewA [${this.label}] this.a.c= ${this.a.c} +1`)
            .onClick(() => {
              this.a.c += 1
            })
        }.margin({ top: 10 })
      }
    }
    ```


**Reference**

[\@Observed and \@ObjectLink: Observing Attribute Changes in Nested Class Objects](../quick-start/arkts-observed-and-objectlink.md)

## How do I transfer values through the parent component to @Link decorated varaibles in a child component?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

To enable a child component to receive the value from the parent component through @Link, '**\$**' must be used to first establish a reference relationship between variables in the child and parent components.  

**Example**

The **@Link** semantics are derived from the '**$**' operator. In other words, **$isPlaying** is the two-way binding of the internal state **this.isPlaying**. When the button in the **PlayButton** child component is touched, the value of the @Link decorated variable is changed, and **PlayButton** together with the **\<Image>** and **\<Text>** components of the parent component is refreshed. Similarly, when the button in the parent component is touched, the value of **this.isPlaying** is changed, and **PlayButton** together with the **\<Text>** and **\<Button>** components of the parent component is refreshed.

1.  Use the @State decorator in the parent component and use the '**\$**' operator to create a reference for transferring data.

    ```
    @Entry
    @Component
    struct Player {
      @State isPlaying: boolean = false
      build() {
        Column() {
          PlayButton({ buttonPlaying: $isPlaying })
          Text(`Player is ${this.isPlaying ? '' : 'not'} playing`).fontSize(18)
          Button('Parent:' + this.isPlaying)
            .margin(15)
            .onClick(() => {
              this.isPlaying = !this.isPlaying
            })
        }
      }
    }
    
    
    ```

2.  Use @Link in the child component to receive data.

    ```
    @Component
    struct PlayButton {
      @Link buttonPlaying: boolean
    
      build() {
        Column() {
          Button(this.buttonPlaying ? 'pause' : 'play')
            .margin(20)
            .onClick(() => {
              this.buttonPlaying = !this.buttonPlaying
            })
        }
      }
    }
    ```


**Reference**

[@Link](../quick-start/arkts-link.md)

## How does a component synchronize state with its grandchild components?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

-   Method 1 (recommended): Use the @Provide and @Consume decorators. Specifically, use @Provide in the component and @Consume in the grandchild component to implement two-way data binding between the components.

-   Method 2: Use the @State and @Link decorators. Specifically, use @State in the parent component and @Link in each layer of child components (child and grandchild components).

**Example 1**

1.  Include a child component in the component. Employ @Provide in the component to provide the **reviewVote** parameter to its grandchild component.

    ```
    @Entry
    @Component
    struct Father{
      @Provide("reviewVote") reviewVotes: number = 0;
    
      build() {
        Column() {
          Son()
          Button(`Father: ${this.reviewVotes}`)
            ...
        }
      }
    }
    ```

2.  Include the grandchild component in the child component.

    ```
    @Component
    struct Son{
      build() {
        Column() {
          GrandSon()
        }
      }
    }
    ```

3.  Employ @Consume in the grandchild component to receive the **reviewVote** parameter.

    ```
    @Component
    struct GrandSon{
      @Consume("reviewVote") reviewVotes: number
    
      build() {
        Column() {
          Button(`GrandSon: ${this.reviewVotes}`)
            ...
        }.width('100%')
      }
    }
    ```


**Example 2**

1.  Employ @State in the component **Father** to decorate **reviewVote**.

    ```
    @Entry
    @Component
    struct Father {
      @State reviewVotes: number = 0;
    
      build() {
        Column() {
          Son({reviewVotes:$reviewVotes})
          Button(`Father: ${this.reviewVotes}`)
            ...
        }
      }
    }
    ```

2.  Employ @Link in the child component **Son** to receive the **reviewVote** parameter passed from **Father**.

    ```
    @Component
    struct Son{
      @Link reviewVotes: number;
      build() {
        Column() {
          Grandson({reviewVotes:$reviewVotes})
        }
      }
    }
    
    
    ```

3.  Employ @Link in the grandchild component **GrandSon** to receive the **reviewVote** parameter passed from **Son**.

    ```
    @Component
    struct Grandson{
      @Link reviewVotes: number;
    
      build() {
        Column() {
          Button(`Grandson: ${this.reviewVotes}`)
            ...
        }.width('100%')
      }
    }
    ```


## How is a callback function defined in JS?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

The following is an example to illustrate how to define a callback function:

1.  Define the callback function.

    ```
    // Define a callback function that contains two parameters and returns void.
    myCallback: (a:number,b:string) => void
    ```

2.  Initialize the callback function by assigning values.

    ```
    aboutToAppear() {
      // Initialize the callback function.
      this.myCallback= (a,b)=>{
        console.info(`handle myCallback a=${a},b=${b}`)
      }}
    ```


## How do I maximize performance in cases when a component needs to be updated for multiple times?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Use the state management module for the purpose. Currently, the minimum update is supported. When the data dependency changes, instead of updating the entire custom component, only the view content that depends on the data is updated.

## How does this of a function in an object point to the outer layer?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

You can use the arrow function for this purpose.

**Example**

```
const obj = {
  start:() => {
    return this.num
  }
}
```

## How do I obtain data through an API before page loading?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

Data needs to be obtained before page rendering so as to be rendered when needed.

**Solution**

In the **aboutToAppear** function, use an asynchronous API to obtain page data and @State to decorate related variables. After the data is obtained, the page is automatically refreshed based on the variables.

**Example**

```
@Entry
@Component
struct Test6Page {
  // After the data is obtained, the page is automatically refreshed.
  @State message: string = 'loading.....'
  aboutToAppear(){
    // Simulate an asynchronous API to obtain data.
    setTimeout(()=>{
      this.message = 'new msg'
    },3000)
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Can placeholders be configured in the string.json file in the stage model?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

The **string.json** file does not support placeholders. As an alternative, you can define variables on the target page and combine these variables and **Resource** objects.

## What are the differences between .ets Files and.ts files?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

ArkTS is a superset of TypeScript. In addition to all TS features, ArkTS offers added declarative UI features, allowing you to develop high-performance applications in a more natural and intuitive manner. It is recommended that you use ArtTS for UI development and TS for service logic development.

**Reference**

[Getting Started with ArkTS](../quick-start/arkts-get-started.md)

## How do I send a verification code through email in ArkTS?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

To send a verification code, you need to request the server, which in turn calls the SMS verification code API. The SMS service can be used to implement related functions.

## How do I display sensor data in the \<Text> component on the UI in real time?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

The type of data returned by the sensor is double. To display it in the \<Text> component, first convert the data from double to string.

## How do I listen for screen rotation events?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

To listen for screen rotation events, use the **mediaquery** API.

```
import mediaquery from '@ohos.mediaquery'
let listener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listen for landscape events.
function onPortrait(mediaQueryResult) {
  if (mediaQueryResult.matches) {
   // do something here
  } else {
   // do something here
  }
}
listener.on('change', onPortrait) // Register a callback.
listener.off('change', onPortrait) // Deregister a callback.
```

**Reference**

[@ohos.mediaquery (Media Query)](../reference/apis/js-apis-mediaquery.md)

## What should I do if ForEach does not traverse all data after DevEco Studio is updated to the latest version?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

In the **forEach\(\)** statement, if the third parameter **keyGenerator** has a value passed in, ensure that the key generated by each element in the data source array is unique. Otherwise, the traversal cannot be performed. If the generated keys are the same, only one key can be generated.

The traversal can also be performed if **keyGenerator** is not specified, in which case the system uses the default generation mode.

## What should I do if a singleton does not take effect after the page is changed?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

A singleton works only in the same page. It becomes **undefined** when the page changes.

**Solution**

A JS file is generated for each page, and a defined singleton is generated in each JS file. Therefore, the singleton in applicable only to the owning page.

To share an instance across pages, it must be created at the UIAbility or application level.

## How do I convert a string in time format to a date object?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

If the string is in the yyyy-MM-dd format, you can convert it to a date object by calling **new Date\("yyyy-MM-dd"\)**.

```
new Date("2021-05-23");
new Date("2020/2/29");
new Date("2020-14-03");
new Date("14-02-2021");
```

If the string is in other formats, you can convert it to a date object by calling **new Date\(year:number,month:number,day?:number,hour?:number,minute?:number,second?:number,ms?:number\)**.

```
Syntax for creating a date based on parameters:
new Date(yearValue, IndexOfMonth, dayValue, hours, minutes, seconds)
```

Pass the date parameters as arguments.

-   **yearValue**: the year in the ISO 8061 YYYY format, for example, **2021**. If we specify a value in YY format, it will be incorrectly accepted. For example, the value **21** would be considered the year 1921 rather than 2021.
-   **IndexOfMonth**: index of the month, which starts from 0. It is obtained by subtracting 1 from the month value. For example, for March, the month value is 3, but the value of **IndexOfMonth** will be 2 (that is, 3 – 1 = 2). The value should typically be within the 0–11 range.
-   **dayValue**: day of the month. It should range from 1 to 31 depending on the number of days in the month. For example, for 21-05-2021, the day value is **21**.
-   **hours**: hour of the day. For example, **10** for 10 o'clock.
-   **minutes**: number of minutes that have elapsed in the hour.
-   **seconds**: number of seconds past a minute.

## How do I convert a string to a byte array in ArkTS?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Refer to the following code:

```
stringToArray(str:string) {
  var arr = [];
  for(var i = 0,j = str.length;i<j;++i) {
 arr.push(str.charCodeAt(i))
  }
  return arr;
}
```

## How do I implement string encoding and decoding in ArkTS?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

You can use **TextEncoder** and **TextDecoder** provided by the **util** module.

**Reference**

[TextEncoder](../reference/apis/js-apis-util.md#textencoder), [TextDecoder](../reference/apis/js-apis-util.md#textdecoder)

## How do I import and export namespaces?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Use **import** and **export** statements.

-   Exporting namespaces from the database:

    ```
    namespace Util{
        export function getTime(){
            return Date.now()
        }
    }
    export default Util
    ```

-   Importing namespaces

    ```
    import Util from './util'
    Util.getTime()
    ```


## Can relational database operations be performed in the Worker thread?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

Currently, the relational database (RDB) object in the UI main thread cannot be sent to the Worker thread for operations. To use the RDB in the Worker thread, you must obtain a new RDB object.

## How do I obtain files in the resource directory of an application?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

-   Method 1: Use **\$r** or **\$rawfile**. This method applies to static access, during which the **resource** directory remains unchanged when the application is running.
-   Method 2: Use **ResourceManager**. This method applies to dynamic access, during which the **resource** directory dynamically changes when the application is running.

**Reference**

[Resource Categories and Access](../quick-start/resource-categories-and-access.md) and [@ohos.resourceManager (Resource Manager)](../reference/apis/js-apis-resource-manager.md)


## How do I convert the XML format to the JSON format?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

The data returned by the server is encoded using Base64 in XML format and needs to be converted to the JSON format for subsequent processing.

**Solution**

Use the Base64-related APIs in the **util** module to decode data, and then use the **convertxml** module to parse data in XML format.

**Example**

```
import convertxml from '@ohos.convertxml';
import util from '@ohos.util';

@Entry
@Component
struct Faq_4_31 {
  @State message: string = 'base64 to JSON'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            / *Original data in GBK encoding
            <?xml version="1.0" encoding="GBK"?>
            <data>
            <asset_no>xxxxx</asset_no>
            <machine_sn>xxxx</machine_sn>
            <bios_id>xxxx</bios_id>
            <responsible_emp_name><![CDATA[xxxx]]></responsible_emp_name>
            <responsible_account><![CDATA[xxxx xxxx]]></responsible_account>
            <responsible_emp_no>xxxx</responsible_emp_no>
            <responsible_dept><![CDATA[xxxx]]></responsible_dept>
            <user_dept><![CDATA[xxxx]]></user_dept>
            <user_name><![CDATA[xxx]]></user_name>
            <cur_domain_account>xxxx</cur_domain_account>
            <asset_loc><![CDATA[--]]></asset_loc>
            <asset_loc_cur><![CDATA[]]></asset_loc_cur>
            <asset_type>1</asset_type>
            <asset_use>For Outsourcing Staff/xxxx</asset_use>
            <overdue_date></overdue_date>
            <asset_status>xxxx</asset_status>
            <asset_period>xxxx</asset_period>
            <license></license>
            </data>
             */
            let src = 'PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iR0JLIj8+CjxkYXRhPgo8YXNzZXRfbm8+eHh4eHg8L2Fzc2V0X25vPgo8bWFjaGluZV9zbj54eHh4PC9tYWNoaW5lX3NuPgo8Ymlvc19pZD54eHh4PC9iaW9zX2lkPgo8cmVzcG9uc2libGVfZW1wX25hbWU+PCFbQ0RBVEFbeHh4eF1dPjwvcmVzcG9uc2libGVfZW1wX25hbWU+CjxyZXNwb25zaWJsZV9hY2NvdW50PjwhW0NEQVRBW3h4eHggeHh4eF1dPjwvcmVzcG9uc2libGVfYWNjb3VudD4KPHJlc3BvbnNpYmxlX2VtcF9ubz54eHh4PC9yZXNwb25zaWJsZV9lbXBfbm8+CjxyZXNwb25zaWJsZV9kZXB0PjwhW0NEQVRBW3h4eHhdXT48L3Jlc3BvbnNpYmxlX2RlcHQ+Cjx1c2VyX2RlcHQ+PCFbQ0RBVEFbeHh4eF1dPjwvdXNlcl9kZXB0Pgo8dXNlcl9uYW1lPjwhW0NEQVRBW3h4eF1dPjwvdXNlcl9uYW1lPgo8Y3VyX2RvbWFpbl9hY2NvdW50Pnh4eHg8L2N1cl9kb21haW5fYWNjb3VudD4KPGFzc2V0X2xvYz48IVtDREFUQVstLV1dPjwvYXNzZXRfbG9jPgo8YXNzZXRfbG9jX2N1cj48IVtDREFUQVtdXT48L2Fzc2V0X2xvY19jdXI+Cjxhc3NldF90eXBlPjE8L2Fzc2V0X3R5cGU+Cjxhc3NldF91c2U+Rm9yIE91dHNvdXJjaW5nIFN0YWZmL3h4eHg8L2Fzc2V0X3VzZT4KPG92ZXJkdWVfZGF0ZT48L292ZXJkdWVfZGF0ZT4KPGFzc2V0X3N0YXR1cz54eHh4PC9hc3NldF9zdGF0dXM+Cjxhc3NldF9wZXJpb2Q+eHh4eDwvYXNzZXRfcGVyaW9kPgo8bGljZW5zZT48L2xpY2Vuc2U+CjwvZGF0YT4='
            let base64 = new util.Base64Helper();
            // base64 decoding
            let src_uint8Array = base64.decodeSync(src);
            // Decode the string into a UTF-8 string.
            let textDecoder = util.TextDecoder.create("utf-8",{ignoreBOM: true})
            let src_str = textDecoder.decodeWithStream(src_uint8Array)
            // Replace the encoding field.
            src_str = src_str.replace("GBK","utf-8")
            console.log('Test src_str: ' + JSON.stringify(src_str));
            //Convert XML format to JSON format.
            let conv = new convertxml.ConvertXML();
            let options = {trim : false, declarationKey:"_declaration",
              instructionKey : "_instruction", attributesKey : "_attributes",
              textKey : "_text", cdataKey:"_cdata", doctypeKey : "_doctype",
              commentKey : "_comment", parentKey : "_parent", typeKey : "_type",
              nameKey : "_name", elementsKey : "_elements"}
            let src_json = JSON.stringify(conv.convertToJSObject(src_str, options));
            console.log('Test json: ' + JSON.stringify(src_json));
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## What is the cause of error code 401 obtained through the try/catch statement?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Cause**

1. Mandatory parameters are not passed in.

2. The parameter type is incorrect.

3. The parameter is **undefined**.

**Reference**

[Universal Error Codes](../reference/errorcodes/errorcode-universal.md)
