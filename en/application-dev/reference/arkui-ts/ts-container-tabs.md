# Tabs


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Tabs&gt;** component is a container component that allows users to switch between content views through tabs. Each tab page corresponds to a content view.


## Required Permissions

None


## Child Component

The **&lt;Tabs&gt;** component can contain [TabContent](ts-container-tabcontent.md) child components.


## APIs

Tabs(value: {barPosition?: BarPosition, index?: number, controller?: [TabsController](#tabscontroller)})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | barPosition | BarPosition | No | BarPosition.Start | Tab&nbsp;bar&nbsp;position&nbsp;for&nbsp;creating&nbsp;the&nbsp;**&lt;Tabs&gt;**&nbsp;container&nbsp;component. | 
  | index | number | No | 0 | Initial&nbsp;tab&nbsp;index. | 
  | controller | [TabsController](#tabscontroller) | No | - | Tab&nbsp;controller. | 

- BarPosition enums
    | Name | Description | 
  | -------- | -------- |
  | Start | If&nbsp;the&nbsp;**vertical**&nbsp;attribute&nbsp;is&nbsp;set&nbsp;to&nbsp;**true**,&nbsp;the&nbsp;tab&nbsp;is&nbsp;on&nbsp;the&nbsp;left&nbsp;of&nbsp;the&nbsp;container.&nbsp;If&nbsp;the&nbsp;**vertical**&nbsp;attribute&nbsp;is&nbsp;set&nbsp;to&nbsp;**false**,&nbsp;the&nbsp;tab&nbsp;is&nbsp;on&nbsp;the&nbsp;top&nbsp;of&nbsp;the&nbsp;container. | 
  | End | If&nbsp;the&nbsp;**vertical**&nbsp;attribute&nbsp;is&nbsp;set&nbsp;to&nbsp;**true**,&nbsp;the&nbsp;tab&nbsp;is&nbsp;on&nbsp;the&nbsp;right&nbsp;of&nbsp;the&nbsp;container.&nbsp;If&nbsp;the&nbsp;**vertical**&nbsp;attribute&nbsp;is&nbsp;set&nbsp;to&nbsp;**false**,&nbsp;the&nbsp;tab&nbsp;is&nbsp;at&nbsp;the&nbsp;bottom&nbsp;of&nbsp;the&nbsp;container. | 


### TabsController

Defines a tab controller, which is used to control switching of tabs.

  | API | Description | 
| -------- | -------- |
| changeIndex(value:&nbsp;number):&nbsp;void | Changes&nbsp;the&nbsp;index&nbsp;of&nbsp;a&nbsp;tab.&nbsp;The&nbsp;value&nbsp;starts&nbsp;from&nbsp;**0**. | 


## Attributes

Touch target configuration is not supported.

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| vertical | boolean | false | Whether&nbsp;a&nbsp;tab&nbsp;is&nbsp;a&nbsp;vertical&nbsp;tab. | 
| scrollable | boolean | true | Whether&nbsp;page&nbsp;switching&nbsp;can&nbsp;be&nbsp;performed&nbsp;by&nbsp;swiping&nbsp;left&nbsp;or&nbsp;right. | 
| barMode | BarMode | - | Tab&nbsp;bar&nbsp;layout&nbsp;mode. | 
| barWidth | number | - | Width&nbsp;of&nbsp;the&nbsp;tab&nbsp;bar.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;the&nbsp;default&nbsp;value&nbsp;in&nbsp;the&nbsp;system&nbsp;theme&nbsp;is&nbsp;used. | 
| barHeight | number | - | Height&nbsp;of&nbsp;the&nbsp;tab&nbsp;bar.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;the&nbsp;default&nbsp;value&nbsp;in&nbsp;the&nbsp;system&nbsp;theme&nbsp;is&nbsp;used. | 
| animationDuration | number | 200 | Animation&nbsp;duration&nbsp;of&nbsp;the&nbsp;tab&nbsp;content. | 

- BarMode enums
    | Name | Description | 
  | -------- | -------- |
  | Scrollable | The&nbsp;actual&nbsp;layout&nbsp;width&nbsp;of&nbsp;the&nbsp;tab&nbsp;bar&nbsp;is&nbsp;used.&nbsp;If&nbsp;the&nbsp;actual&nbsp;width&nbsp;exceeds&nbsp;the&nbsp;total&nbsp;length,&nbsp;the&nbsp;tab&nbsp;bar&nbsp;is&nbsp;scrollable. | 
  | Fixed | The&nbsp;widths&nbsp;of&nbsp;all&nbsp;tab&nbsp;bars&nbsp;are&nbsp;evenly&nbsp;allocated. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onChange(callback:&nbsp;(index:&nbsp;number)&nbsp;=&gt;&nbsp;void) | Event&nbsp;triggered&nbsp;when&nbsp;a&nbsp;tab&nbsp;is&nbsp;switched. | 


## Example


```
@Entry
@Component
struct TabsExample {
  private controller: TabsController = new TabsController()

  build() {
    Column() {
      Tabs({ barPosition: BarPosition.Start, controller: this.controller }) {
        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Pink)
        }.tabBar('pink')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Yellow)
        }.tabBar('yellow')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Blue)
        }.tabBar('blue')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Green)
        }.tabBar('green')
      }
      .vertical(true).scrollable(true).barMode(BarMode.Fixed)
      .barWidth(70).barHeight(150).animationDuration(400)
      .onChange((index: number) => {
        console.info(index.toString())
      })
      .width('90%').backgroundColor(0xF5F5F5)
    }.width('100%').height(150).margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218430](figures/en-us_image_0000001212218430.gif)
