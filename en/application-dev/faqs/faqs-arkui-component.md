# ArkUI Component Development (ArkTS)


## Can custom dialog boxes be defined and used in .ts files? (API version 9)

Unfortunately not. Custom dialog boxes require ArkTS syntax for definition and initialization. Therefore, they can be defined and used only in .ets files.

**Reference**

[Custom Dialog Box](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## How do I pass variables in a custom dialog box to a page? (API version 9)

**Symptom**

The variable defined in a custom dialog box needs to be transferred to the page when the dialog box is closed or the variable changes.

**Solution**

- Method 1: Define the variable as a state variable of the custom dialog box.

- Method 2: During initialization of the custom dialog box, pass to it a method, which is triggered in the custom dialog box and accepts the variable in the custom dialog box as a parameter.

- Method 3: Use AppStorage or LocalStorage to manage page state and implement state sharing between the custom dialog box and page.

**Example**

- Method 1:

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

- Method 2:

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

- Method 3:

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


## How do I obtain the width and height of a component? (API version 9)

**Symptom**

The width and height of a component need to be obtained to calculate the size and offset of the layout area.

**Solution**

- Method 1: Use the **onAreaChange** event of the component, which is triggered when the component is initialized or the component size changes.

- Manner 2: Use the callback in the click or touch event, which provides the area information of the target element.

**Reference**

[Component Area Change Event](../reference/apis-arkui/arkui-ts/ts-universal-component-area-change-event.md), [Click Event](../reference/apis-arkui/arkui-ts/ts-universal-events-click.md), [Touch Event](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md)


## How do I clear the content of the \<TextInput> and \<TextArea> components by one click? (API version 9)

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


## How do I set the position of a custom dialog box? (API version 9)

**Symptom**

By default, a custom dialog box is displayed in the center of the window. In some cases, it needs to be aligned with the window border.

**Solution**

During initialization of the custom dialog box, set the **alignment** and **offset** parameters.

**Reference**

[Custom Dialog Box](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## How do I hide the overflow content of a container component? (API version 9)

**Symptom**

When content overflows in a container component, that is, the child component does not fit in the container component, the overflow content needs to be processed.

**Solution**

To clip and hide overflow content, set the **clip** universal attribute to **true**. By default, this attribute is set to **false**.

**Reference**

[Shape Clipping](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md)


## How do I set a custom dialog box to automatically adapt its size to content? (API version 9)

**Symptom**

When a custom dialog box contains a child component whose area size can be changed, it needs to automatically adjust its size.

**Solution**

- Method 1: Set the custom dialog box to the default style. In this style, the dialog box automatically adapts its width to the grid system and its height to the child components; the maximum height is 90% of the container height.

- Method 2: Set the custom dialog box to a custom style. In this style, the dialog box automatically adapts its width and height to the child components.

**Reference**

[Custom Dialog Box](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## What is the gridCount parameter of the custom dialog box used for? (API version 9)

The **gridCount** parameter indicates the number of grid columns occupied by the dialog box. The system divides the window width into equal regions. The number of equal regions is the number of grid columns, which varies by device. For example, if the screen density of a device is 320 vp &lt;= horizontal width &lt; 600 vp, the number of grid columns is 4, and the valid value of **gridCount** is [1, 4].

Note: This parameter is valid only when the custom dialog box is in the default style.

**Reference**

[Custom Dialog Box](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## How do I remove the white background of a custom dialog box? (API version 9)

**Symptom**

When in the default style a custom dialog box comes with a white background.

**Solution**

To remove the white background, set the custom dialog box to a custom style.

1. During initialization of the custom dialog box, set **customStyle** to **true**.

2. During initialization of the custom dialog box, set **backgroundColor** to the color you prefer.

**Reference**

[Custom Dialog Box](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)


## How do I customize the eye icon for the password input mode of the \<TextInput> component? (API version 9)

**Symptom**

The eye icon for the password input mode (with the **type** attribute of the **\<TextInput>** component set to **InputType.Password**) cannot be customized.

**Solution**

The eye icon itself cannot be customized. You can use set the **showPasswordIcon** attribute of the **\<TextInput>** component to **false** to hide the icon, and use the **\<Image>** component to control the type of the **\<TextInput>** component.

**Reference**

[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)


## How do I use the onSubmit event of the \<TextInput> component? (API version 9)

**Solution**

The **onSubmit** event is triggered when a user presses **Enter** on the (physical or soft) keyboard. The callback parameter in the event is the current Enter key type. The Enter key type can be set through the **enterKeyType** attribute of the **\<TextInput>** component. Setting the key style of the soft keyboard requires support by the input method.

**Reference**

[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)


## How do I set the caret position to the start point for when the \<TextInput> component obtains focus? (API version 9)

**Symptom**

When the **\<TextInput>** component obtains focus, the caret automatically moves to the position of the touch point, instead of the start position.

**Solution**

1. Bind the **\<TextInput>** component to the **onEditChange** event, which is triggered when the component enters the input state.

2. Call the **setTimeout** API for asynchronous processing. Then call the **TextInputController.caretPosition** API in the event callback to set the caret position.

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

[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)


## How do I obtain the current scrolling offset of a scrollable component? (API version 9)

**Solution**

1. During initialization of the scrollable component, such as **\<List>**, **\<Grid>**, and **\<Scroll>**, set the **scroller** parameter to bind the component to a scroll controller.

2. Call the **currentOffset** API of the controller to obtain the horizontal and vertical scrolling offsets.

**Reference**

[Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#currentoffset)


## How do I align text vertically? (API version 9)

**Symptom**

Text cannot be aligned vertically in the **\<Text>** component.

**Solution**

Text is aligned horizontally in the **\<Text>** component. To enable text to align vertically, you can split the file, include it in a **\<Flex>** container, and set the container's main axis direction to vertical.

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


## How do I set the UI of an ability to transparent? (API version 9)

**Solution**

Set the background color of the top container component to transparent, and then set the **opacity** attribute of the XComponent to **0.01**.

**Example**

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


## Why do the constraintSize settings fail to take effect? (API version 9)

Applicable to: stage model

**Symptom**

If **constraintSize** is set for a component and the width of its child component is set to a percentage, for example, **width('100%')**, **constraintSize** takes effect by multiplying the maximum width by the percentage. As a result, the child component may overflow, in which case it looks like the **constraintSize** settings fail to take effect.

**Solution**

You can use the **\<Scroll>** component at the outer layer. In this way, when **constraintSize** is set and the space occupied by a child component exceeds the specified constraint value, a scrollbar will be displayed.


## How do I set the background color to transparent? (API version 9)

**Solution**

Set **backgroundColor** to **'\#00000000'**.


## What should I do if the \<Scroll> component cannot scroll to the bottom? (API version 9)

Applicable to: stage model

**Symptom**

Unless otherwise specified, the height of the **\<Scroll>** component is equal to the window height. In this case, the component's bottom area will be blocked by components (if any) outside of it.

**Solution**

Set the height of the **\<Scroll>** component or use the flex layout to limit this height.


## How do I customize the control bar style of the \<Video> component? (API version 9)

Applicable to: stage model

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

[Video](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#start)

## How do I set state-specific styles for a component? (API version 9)


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

[Polymorphic Style](../reference/apis-arkui/arkui-ts/ts-universal-attributes-polymorphic-style.md)

## What should I do if the flex width and height in the \<Scroll> component conflicts with the scrolling? (API version 9)

Applicable to: stage model

**Symptom**

When a container component with a fixed size is added to the **\<Scroll>** component, a scrolling error occurs.

**Solution**

Do not set a size for any container component in the **\<Scroll>** component. In this way, the **\<Scroll>** component can adapt its size to the content.


## How does a component process click events in its child components? (API version 9)

Applicable to: stage model

When a child component is initialized in the parent component, the method defined in the parent component is transferred to and invoked in the child component. This process is similar to variable transfer.

**Example**

```
class Model {
  value: string
}
@Entry
@Component
struct EntryComponent {
  test() {
    console.log('testTag test in my component');
  }
  build() {
    Column() {
      MyComponent({ title: { value: 'Hello World 2' }, count: 7, onClick: this.test }) // The defined method is transferred during initialization.
    }
  }
}

@Component
struct MyComponent {
  @State title: Model = { value: 'Hello World' }
  @State count: number = 0
  onClick: any;
  private toggle: string = 'Hello World'
  private increaseBy: number = 1

  build() {
    Column() {
      Text(`${this.title.value}`).fontSize(30)
      Button(`Click to increase count=${this.count}`)
        .margin(20)
        .onClick(() => {
          // Change the count value of the internal state variable.
          this.count += this.increaseBy
          this.onClick.call();
        })
    }
  }
}
```


## How do I implement a text input box that automatically brings up the soft keyboard? (API version 9)

**Solution**

You can use **focusControl.requestFocus** to control the focus of the text input box. When the text input box is in focus, it automatically brings up the soft keyboard.

**Reference**

[Focus Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md)


## How do I set the controlButton attribute for the \<SideBarContainer> component? (API version 9)

**Solution**

Refer to the following sample code:

```
@Entry
@Component
struct SideBarContainerExample {
  normalIcon : Resource = $r("app.media.icon")
  selectedIcon: Resource = $r("app.media.icon")
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1

  build() {
    SideBarContainer(SideBarContainerType.Embed)
    {
      Column() {
        ForEach(this.arr, (item, index) => {
          Column({ space: 5 }) {
            Image(this.current === item ? this.selectedIcon : this.normalIcon).width(64).height(64)
            Text("Index0" + item)
              .fontSize(25)
              .fontColor(this.current === item ? '#0A59F7' : '#999')
              .fontFamily('source-sans-pro,cursive,sans-serif')
          }
          .onClick(() => {
            this.current = item
          })
        }, item => item)
      }.width('100%')
      .justifyContent(FlexAlign.SpaceEvenly)
      .backgroundColor('#19000000')


      Column() {
        Text('SideBarContainer content text1').fontSize(25)
        Text('SideBarContainer content text2').fontSize(25)
      }
      .margin({ top: 50, left: 20, right: 30 })
    }
    .sideBarWidth(150)
    .minSideBarWidth(50)
    .controlButton({left:32,
      top:32,
      width:32,
      height:32, 
      icons:{shown: $r("app.media.icon"),
        hidden: $r("app.media.icon"),
        switching: $r("app.media.icon")}})
    .maxSideBarWidth(300)
    .onChange((value: boolean) => {
      console.info('status:' + value)
    })
  }
}
```

## How do I enable proactive component update? (API version 10)

**Solution**

In the **Canvas** component, there are two types of content: 1. content rendered with universal attributes of components, such as the background color and boarder;
2. content drawn by the application through the **CanvasRenderingContext2D** API. The first type of content is updated through state variables. The second type of content is updated in the next frame once the API is called, thanks to the built-in dirty table feature of the API. You do not need to explicitly refresh this type of content.

**Reference**

[CanvasRenderingContext2D](../reference/apis-arkui/arkui-ts/ts-canvasrenderingcontext2d.md)

## What should I do if the \<List> component cannot scroll to the bottom with its height not specified? (API version 10)

**Cause**

If no height is set for a **\<List>** component and the total height of its child components is greater than the height of its parent component, the component is displayed at the height of its parent component. In this case, if the **\<List>** component has sibling nodes, part of it may be pushed outside of the display area of the parent component, making it seemingly unable to be scrolled to the bottom.

**Solution**

Add the **layoutWeight** attribute for the **\<List>** component so that it takes up the remaining space.

**Reference**

[Size](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md)

## How do I implement infinite data loading and display for scrolling with a water flow layout?

**Solution**

1. Use **LazyForEach** as a child node of the **\<WaterFlow>** component.

2. Determine whether the bottom is about to be reached in **onAppear** of the **\<FlowItem>** component, and append new data to the **LazyForEach** data source in advance. Alternatively, determine whether the bottom is about to be reached based on the current index in the **onScrollIndex11+** event.

**Reference**

[High-Performance WaterFlow Development](../performance/waterflow_optimization.md)

## How do I open a new page from a custom dialog box without closing the dialog box? (API version 10)

**Solution**

Obtain the **uiContext** instance of the main window and then call **router.push** to jump to the new page.

**Reference**

[Custom Dialog Box](../reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)

## Is there any update on ArkUI-X availability? Is there a roadmap for ArkUI-X? (API version 10)

**Solution**

1. Progress: ArkUI-X is now an open-source tool, with first version officially released on December 15, 2023. It runs Android and iOS, with support for desktop and web platforms well on the way.

2. [Roadmap](https://gitee.com/arkui-x/docs/blob/master/en/roadmap)

**Reference**

[ArkUI-X](https://gitee.com/arkui-x)

## How does an application track component data or state in the build process of custom components? (API version 10)

**Symptom**

Logs cannot be inserted into the **build** method of the UI. As a result, the application cannot detect the UI drawing process, which is inconvenient for UI debugging and fault locating. 

**Solution**

Use @Watch to listen for state variables. The \@Watch callback is called when any value change has occurred. In this case, the UI of the changed variable is re-rendered when the VSYNC signal is sent next time.

The sample code is as follows:

```ts
@Prop @Watch('onCountUpdated') count: number = 0; 
@State total: number = 0; 
// @Watch callback
onCountUpdated(propName: string): void {
  this.total += this.count; 
}
```

**Reference**

[@Watch Decorator: Getting Notified of State Variable Changes](../quick-start/arkts-watch.md)

## How are inheritance and encapsulation implemented for custom components in ArkUI? (API version 10)

**Solution**

In the declarative UI, custom components do not support inheritance. To extend functionality, you can draw on the combination mechanism and inherit, reuse, and transfer existing component attributes with the attribute modifier.

## What parameter types and unit types do components support? When are they used? (API version 10)

**Solution**

ArkUI provides several pixel units:<br>px: physical pixel unit of the screen. 1 px indicates a pixel on the screen. lpx: logical pixel unit of the window. It is the ratio of the actual screen width to the logical width (configured by **designWidth**, representing the baseline width for page design. The size of an element is scaled at this ratio to the actual screen width. vp: virtual pixel unit. fp: font pixel unit. The formula for calculating vp is as follows: vp = px/(DPI/160). 
A virtual pixel (vp) describes the virtual size of a device for an application. It is different from the unit used by the screen hardware, pixel (px). Its use allows elements to have a consistent visual volume on devices with different densities. By default, the font pixel (fp) size is the same as that of the virtual pixel size. That is, 1 fp = 1 vp. If you select a larger font size in **Settings**, the actual font size is the virtual pixel size multiplied by the scale coefficient. That is, 1 fp = 1 vp \* scale. Percentage: The unit must be %, for example, **'10%'**. 
Resource: Size referenced from system or application resources.
