# Navigation


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Navigation&gt;** component typically functions as the root container of a page and displays the page title, toolbar, and menu based on the attribute settings.


## Required Permissions

None


## Child Component

It can contain subcomponents.


## APIs

Navigation()

Creates a component that can automatically display the navigation bar, title, and toolbar based on the attribute settings.


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| title | string&nbsp;\|&nbsp;[Custom Builder](../../ui/ts-types.md) | - | Page&nbsp;title. |
| subtitle | string | - | Subtitle&nbsp;of&nbsp;the&nbsp;page. |
| menus | Array&lt;NavigationMenuItem&gt;&nbsp;\|&nbsp;[Custom Builder](../../ui/ts-types.md) | - | Menu&nbsp;in&nbsp;the&nbsp;upper&nbsp;right&nbsp;corner&nbsp;of&nbsp;the&nbsp;page. |
| titleMode | NavigationTitleMode | NavigationTitleMode.Free | Display&nbsp;mode&nbsp;of&nbsp;the&nbsp;page&nbsp;title&nbsp;bar. |
| toolBar | {<br/>items:[<br/>Object<br/>]&nbsp;}<br/>\|&nbsp;[Custom Builder](../../ui/ts-types.md) | - | Content&nbsp;of&nbsp;the&nbsp;toolbar.<br/>**items**:&nbsp;all&nbsp;items&nbsp;on&nbsp;the&nbsp;toolbar. |
| hideToolBar | boolean | false | Whether&nbsp;to&nbsp;hide&nbsp;the&nbsp;toolbar.<br/>**true**:&nbsp;Hide&nbsp;the&nbsp;toolbar.<br/>**false**:&nbsp;Show&nbsp;the&nbsp;toolbar. |
| hideTitleBar | boolean | false | Whether&nbsp;to&nbsp;hide&nbsp;the&nbsp;title&nbsp;bar. |
| hideBackButton | boolean | false | Whether&nbsp;to&nbsp;hide&nbsp;the&nbsp;back&nbsp;button. |

- NavigationMenuItem attributes
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | value | string | Yes | - | Text&nbsp;of&nbsp;an&nbsp;option&nbsp;on&nbsp;the&nbsp;menu&nbsp;bar. | 
  | icon | string | No | - | Icon&nbsp;path&nbsp;of&nbsp;an&nbsp;option&nbsp;on&nbsp;the&nbsp;menu&nbsp;bar. | 
  | action | ()&nbsp;=&gt;&nbsp;void | No | - | Callback&nbsp;invoked&nbsp;when&nbsp;an&nbsp;option&nbsp;is&nbsp;selected. | 

- Object attributes
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | value | string | Yes | - | Text&nbsp;of&nbsp;an&nbsp;option&nbsp;on&nbsp;the&nbsp;toolbar. | 
  | icon | string | No | - | Icon&nbsp;path&nbsp;of&nbsp;an&nbsp;option&nbsp;on&nbsp;the&nbsp;toolbar. | 
  | action | ()&nbsp;=&gt;&nbsp;void | No | - | Callback&nbsp;invoked&nbsp;when&nbsp;an&nbsp;option&nbsp;is&nbsp;selected. | 

- NavigationTitleMode enums
    | Name | Description | 
  | -------- | -------- |
  | Free | When&nbsp;the&nbsp;content&nbsp;is&nbsp;a&nbsp;scrollable&nbsp;component,&nbsp;the&nbsp;title&nbsp;shrinks&nbsp;as&nbsp;the&nbsp;content&nbsp;scrolls&nbsp;up&nbsp;(the&nbsp;subtitle&nbsp;fades&nbsp;out&nbsp;with&nbsp;its&nbsp;size&nbsp;remaining&nbsp;unchanged)&nbsp;and&nbsp;restores&nbsp;as&nbsp;the&nbsp;content&nbsp;scrolls&nbsp;down. | 
  | Mini | The&nbsp;mode&nbsp;is&nbsp;fixed&nbsp;at&nbsp;mini&nbsp;mode&nbsp;(icon&nbsp;+&nbsp;main&nbsp;title&nbsp;and&nbsp;subtitle). | 
  | Full | The&nbsp;mode&nbsp;is&nbsp;fixed&nbsp;at&nbsp;full&nbsp;mode&nbsp;(main&nbsp;title&nbsp;and&nbsp;subtitle). | 

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
  > Currently, only the scrollable component **&lt;List&gt;** is supported.


## Events

  | Name | Description | 
| -------- | -------- |
| onTitleModeChanged(callback:&nbsp;(titleMode:&nbsp;NavigationTitleMode)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;**titleMode**&nbsp;is&nbsp;set&nbsp;to&nbsp;**NavigationTitleMode.Free**&nbsp;and&nbsp;the&nbsp;title&nbsp;bar&nbsp;mode&nbsp;changes&nbsp;as&nbsp;content&nbsp;scrolls. | 


## Example


```
// Example 01
@Entry
@Component
struct NavigationExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State hideBar: boolean = true

  @Builder NavigationTitle() {
    Column() {
      Text('title')
        .width(80)
        .height(60)
        .fontColor(Color.Blue)
        .fontSize(30)
    }
    .onClick(() => {
      console.log("title")
    })
  }

  @Builder NavigationMenus() {
    Row() {
      Image('images/add.png')
        .width(25)
        .height(25)
      Image('comment/more.png')
        .width(25)
        .height(25)
        .margin({ left: 30 })
    }.width(100)
  }

  build() {
    Column() {
      Navigation() {
        Search({ value: '', placeholder: "" }).width('85%').margin(26)
        List({ space: 5, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('90%')
                .height(80)
                .backgroundColor('#3366CC')
                .borderRadius(15)
                .fontSize(16)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical)
        .height(300)
        .margin({ top: 10, left: 18 })
        .width('100%')

        Button(this.hideBar ? "tool bar" : "hide bar")
          .onClick(() => {
            this.hideBar = !this.hideBar
          })
          .margin({ left: 135, top: 60 })
      }
      .title(this.NavigationTitle)
      .subTitle('subtitle')
      .menus(this.NavigationMenus)
      .titleMode(NavigationTitleMode.Free)
      .hideTitleBar(false)
      .hideBackButton(false)
      .onTitleModeChanged((titleModel: NavigationTitleMode) => {
        console.log('titleMode')
      })
      .toolBar({ items: [
        { value: 'app', icon: 'images/grid.svg', action: () => {
          console.log("app")
        } },
        { value: 'add', icon: 'images/add.svg', action: () => {
          console.log("add")
        } },
        { value: 'collect', icon: 'images/collect.svg', action: () => {
          console.log("collect")
        } }] })
      .hideToolBar(this.hideBar)
    }
  }
}
```

![en-us_image_0000001256978359](figures/en-us_image_0000001256978359.gif)


```
// Example 02
@Entry
@Component
struct ToolbarBuilderExample {
  @State currentIndex: number = 0
  @State Build: Array<Object> = [
    {
      icon: $r('app.media.ic_public_add'),
      icon_after: $r('app.media.ic_public_addcolor'),
      text: 'add',
      num: 0
    },
    {
      icon: $r('app.media.ic_public_app'),
      icon_after: $r('app.media.ic_public_appcolor'),
      text: 'app',
      num: 1
    },
    {
      icon: $r('app.media.ic_public_collect'),
      icon_after: $r('app.media.ic_public_collectcolor'),
      text: 'collect',
      num: 2
    }
  ]

  @Builder NavigationToolbar() {
    Row() {
      ForEach(this.Build, item => {
        Column() {
          Image(this.currentIndex == item.num ? item.icon_after : item.icon)
            .width(25)
            .height(25)
          Text(item.text)
            .fontColor(this.currentIndex == item.num ? "#ff7500" : "#000000")
        }
        .onClick(() => {
          this.currentIndex = item.num
        })
        .margin({ left: 70 })
      })
    }
  }

  build() {
    Column() {
      Navigation() {
        Flex() {
        }
      }
      .toolBar(this.NavigationToolbar)
    }
  }
}
```

![en-us_image_0000001212058484](figures/en-us_image_0000001212058484.gif)
