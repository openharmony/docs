# Navigation

The **\<Navigation>** component typically functions as the root container of a page and displays the title bar, toolbar, and navigation bar based on the attribute settings.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported

Since API version 9, it is recommended that this component be used together with the **[\<NavRouter>](ts-basic-components-navrouter.md)** component.


## APIs

**API 1**: Navigation()

**API 2**: Navigation(pathInfos: NavPathStack)<sup>10+</sup>

Binds a navigation stack to the **\<Navigation>** component.

**Parameters**

| Name    | Type                               | Mandatory  | Description         |
| ------- | ----------------------------------- | ---- | ------------- |
| pathInfos   | [NavPathStack](#navpathstack10) | No   | Information about the navigation stack.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                           | Type                                    | Description                                      |
| ----------------------------- | ---------------------------------------- | ---------------------------------------- |
| title                         | [ResourceStr](ts-types.md#resourcestr)<sup>10+</sup> \| [CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup> \| [NavigationCommonTitle](#navigationcommontitle)<sup>9+</sup> \| [NavigationCustomTitle](#navigationcustomtitle)<sup>9+</sup> | Page title.<br>**NOTE**<br>When the NavigationCustomTitle type is used to set the height, the **titleMode** attribute does not take effect.<br>When the title string is too long: (1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...); (2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).|
| subTitle<sup>deprecated</sup> | string                                   | Subtitle of the page. If this attribute is not set, no subtitle is displayed. This attribute is deprecated since API version 9. You are advised to use **title** instead.|
| menus                         | Array<[NavigationMenuItem](#navigationmenuitem)&gt; \| [CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup> | Menu items in the upper right corner of the page. If this parameter is not set, no menu item is displayed. When the value type is Array\<[NavigationMenuItem](#navigationmenuitem)>, the menu shows a maximum of three icons in portrait mode and a maximum of five icons in landscape mode, plus excess icons (if any) under the automatically generated **More** icon.|
| titleMode                     | [NavigationTitleMode](#navigationtitlemode) | Display mode of the page title bar.<br>Default value: **NavigationTitleMode.Free**|
| toolBar                       | [object](#object) \| [CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup> | Content of the toolbar. If this attribute is not set, no toolbar is displayed.<br>**items**: items on the toolbar.<br>**NOTE**<br>Items are evenly distributed on the toolbar at the bottom. Text and icons are evenly distributed in each content area. If the text is too long, it is scaled down level by level, wrapped in two lines, and then clipped with an ellipsis (...).|
| hideToolBar                   | boolean                                  | Whether to hide the toolbar.<br>Default value: **false**<br>**true**: Hide the toolbar.<br>**false**: Display the toolbar.|
| hideTitleBar                  | boolean                                  | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Display the title bar.|
| hideBackButton                | boolean                                  | Whether to hide the back button.<br>Default value: **false**<br>**true**: Hide the back button.<br>**false**: Display the back button.<br>The back button in the title bar of the **\<NavDestination>** component cannot be hidden.<br>**NOTE**<br>The back button is available only when **titleMode** is set to **NavigationTitleMode.Mini**.|
| navBarWidth<sup>9+</sup>      | [Length](ts-types.md#length)             | Width of the navigation bar.<br>Default value: **200**<br>Unit: vp<br>**NOTE**<br>This attribute is valid only when the **\<Navigation>** component is split.|
| navBarPosition<sup>9+</sup>   | [NavBarPosition](#navbarposition)        | Position of the navigation bar.<br>Default value: **NavBarPosition.Start**<br>**NOTE**<br>This attribute is valid only when the **\<Navigation>** component is split.|
| mode<sup>9+</sup>             | [NavigationMode](#navigationmode)        | Display mode of the navigation bar.<br>Default value: **NavigationMode.Auto**<br>At the default settings, the component adapts to a single column or two columns based on the component width.|
| backButtonIcon<sup>9+</sup>   | string \| [PixelMap](../apis/js-apis-image.md#pixelmap7) \| [Resource](ts-types.md#resource) | Back button icon on the navigation bar. The back button in the title bar of the **\<NavDestination>** component cannot be hidden.|
| hideNavBar<sup>9+</sup>       | boolean                                  | Whether to hide the navigation bar. This attribute is valid only when **mode** is set to **NavigationMode.Split**.|
| navDestination<sup>10+</sup>  | builder: (name: string, param: unknown) => void | Creates a **\<NavDestination>** component.<br>**NOTE**<br>The **builder** function is used, with the **name** and **param** parameters passsed in. In the builder, a layer of custom components can be included outside the **\<NavDestination>** component. However, no attributes or events can be set for the custom components. Otherwise, only blank components are displayed.|

## NavPathStack<sup>10+</sup>

Implements a navigation stack.

### push<sup>10+</sup>

push(info: NavPathInfo): void

Pushes the NavDestination page information specified by **info** to the stack.

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| info  | [NavPathInfo](#navpathinfo10)                  | Yes   | Information about the navigation destination page.  |

### pushName<sup>10+</sup>

pushName(name: string, param: unknown): void

Pushes the navigation destination page specified by **name** to the navigation stack.

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| name   | string                   | Yes   | Name of the navigation destination page.  |
| param  | unknown                  | Yes   | Parameter information of the navigation destination page.  |

### pop<sup>10+</sup>

pop(): NavPathInfo | undefined

Pops the top element out of the navigation stack.

**Return value**

| Type    | Description      |
| ------ | -------- |
| NavPathInfo | Returns the information about the navigation destination page at the top of the stack.|
| undefined   | Returns **undefined** if the navigation stack is empty.|

### popTo<sup>10+</sup>

popTo(name: string): number

Returns the navigation stack to the first navigation destination page that matches the value of **name**.

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| name   | string                  | Yes  | Name of the navigation destination page.  |

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Returns the index of the first navigation destination page that matches the value of **name** if it exists in the navigation stack; returns **-1** otherwise.|

### popToIndex<sup>10+</sup>

popToIndex(index: number): void

Returns the navigation stack to the navigation destination page that matches the value of **index**.

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| index  | number                  | Yes  | Index of the navigation destination page.  |

### moveToTop<sup>10+</sup>

moveToTop(name: string): number

Moves to the top of the navigation stack the first navigation destination page that matches the value of **name**.

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| name  | string                  | Yes   | Name of the navigation destination page.  |

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Returns the index of the first navigation destination page that matches the value of **name** if it exists in the navigation stack; returns **-1** otherwise.|

### moveIndexToTop<sup>10+</sup>

moveIndexToTop(index: number): void

Moves to the top of the navigation stack the navigation destination page that matches the value of **index**.

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| index  | number                  | Yes  | Index of the navigation destination page.  |

### clear<sup>10+</sup>

clear(): void

Clears the navigation stack.

### getAllPathName<sup>10+</sup>

getAllPathName(): Array<string\>

Obtains the names of all navigation destination pages in the navigation stack.

**Return value**

| Type    | Description      |
| ------ | -------- |
| Array<string\> | Names of all navigation destination pages in the navigation stack.|

### getParamByIndex<sup>10+</sup>

getParamByIndex(index: number): unknown | undefined

Obtains the parameter information of the navigation destination page that matches the value of **index**.

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| index  | number                  | Yes  | Index of the navigation destination page.  |

**Return value**

| Type    | Description      |
| ------ | -------- |
| unknown   | Returns the parameter information of the matching navigation destination page.|
| undefined | Returns **undefined** if the passed index is invalid.|

### getParamByName<sup>10+</sup>

getParamByName(name: string): Array<unknown\>

Obtains the parameter information of all the navigation destination pages that match the value of **name**.

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| name  | string                  | Yes   | Name of the navigation destination page.  |

**Return value**

| Type    | Description      |
| ------ | -------- |
| Array<unknown\>  | Parameter information of all the matching navigation destination pages.|

### getIndexByName<sup>10+</sup>

getIndexByName(name: string): Array<number\>

Obtains the indexes information of all the navigation destination pages that match the value of **name**.

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| name   | string                  | Yes  | Name of the navigation destination page.  |

**Return value**

| Type    | Description      |
| ------ | -------- |
| Array<number\>  | Indexes of all the matching navigation destination pages.|

### size<sup>10+</sup>

size(): number

Obtains the stack size.

**Return value**

| Type    | Description      |
| ------ | -------- |
| number  | Stack size.|

## NavPathInfo<sup>10+</sup>

Describes the navigation page information.

### constructor

constructor(name: string, param: unknown)

**Parameters**

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| name  | string                  | Yes   | Name of the navigation destination page.  |
| param  | unknown                  | No   | Parameter information of the navigation destination page.  |

## NavigationMenuItem

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| value  | string                  | Yes   | Text of a menu item.  |
| icon   | string                  | No   | Icon path of a menu item.|
| action | () =&gt; void | No   | Callback invoked when a menu item is selected.  |

## object

| Name    | Type                     | Mandatory  | Description             |
| ------ | ----------------------- | ---- | --------------- |
| value  | string                  | Yes   | Text of an option on the toolbar.  |
| icon   | string                  | No   | Icon path of an option on the toolbar.|
| action | () =&gt; void | No   | Callback invoked when an option is selected.  |

## NavigationTitleMode

| Name  | Description                                      |
| ---- | ---------------------------------------- |
| Free | When the content is a scrollable component, the main title shrinks as the content scrolls down (the subtitle fades out with its size remaining unchanged) and restores when the content scrolls up to the top.|
| Mini | The title is fixed at mini mode.                               |
| Full | The title is fixed at full mode.                               |

## NavigationCommonTitle

| Name  | Type    | Mandatory  | Description    |
| ---- | ------ | ---- | ------ |
| main | string | Yes   | Main title.|
| sub  | string | Yes   | Subtitle.|

## NavigationCustomTitle

| Name     | Type                                      | Mandatory  | Description      |
| ------- | ---------------------------------------- | ---- | -------- |
| builder | [CustomBuilder](ts-types.md#custombuilder8) | Yes   | Content of the title bar.|
| height  | [TitleHeight](#titleheight) \| [Length](ts-types.md#length) | Yes   | Height of the title bar.|

## NavBarPosition

| Name   | Description              |
| ----- | ---------------- |
| Start | When two columns are displayed, the main column is at the start of the main axis.|
| End   | When two columns are displayed, the main column is at the end of the main axis.|

## NavigationMode

| Name   | Description                                      |
| ----- | ---------------------------------------- |
| Stack | The navigation bar and content area are displayed independently of each other, which are equivalent to two pages.                    |
| Split | The navigation bar and content area are displayed in different columns.                           |
| Auto  | When the window width is greater than or equal to 520 vp, Split mode is used. Otherwise, the Stack mode is used.|

## TitleHeight

| Name         | Description                        |
| ----------- | -------------------------- |
| MainOnly    | Recommended height (56 vp) of the title bar when only the main title is available.     |
| MainWithSub | Recommended height (82 vp) of the title bar when both the main title and subtitle exist.|


>  **NOTE**
>
>  Among the scrollable components, only **\<List>** is supported.


## Events

| Name                                      | Description                                    |
| ---------------------------------------- | ---------------------------------------- |
| onTitleModeChange(callback: (titleMode: NavigationTitleMode) =&gt; void) | Called when **titleMode** is set to **NavigationTitleMode.Free** and the title bar mode changes as content scrolls.|
| onNavBarStateChange(callback: (isVisible: boolean) =&gt; void) | Called when the navigation bar visibility status changes. The value **true** means that the navigation bar is displayed, and **false** means the opposite.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct NavigationExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State currentIndex: number = 0
  @State Build: Array<Object> = [
    {
      text: 'add',
      num: 0
    },
    {
      text: 'app',
      num: 1
    },
    {
      text: 'collect',
      num: 2
    }
  ]

  @Builder NavigationTitle() {
    Column() {
      Text('Title')
        .fontColor('#182431')
        .fontSize(30)
        .lineHeight(41)
        .fontWeight(700)
      Text('subtitle')
        .fontColor('#182431')
        .fontSize(14)
        .lineHeight(19)
        .opacity(0.4)
        .margin({ top: 2, bottom: 20 })
    }.alignItems(HorizontalAlign.Start)
  }

  @Builder NavigationMenus() {
    Row() {
      Image('common/navigation_icon1.svg')
        .width(24)
        .height(24)
      Image('common/navigation_icon1.svg')
        .width(24)
        .height(24)
        .margin({ left: 24 })
      Image('common/navigation_icon2.svg')
        .width(24)
        .height(24)
        .margin({ left: 24 })
    }
  }

  @Builder NavigationToolbar() {
    Row() {
      ForEach(this.Build, item => {
        Column() {
          Image(this.currentIndex == item.num ? 'common/public_icon_selected.svg' : 'common/public_icon.svg')
            .width(24)
            .height(24)
          Text(item.text)
            .fontColor(this.currentIndex == item.num ? '#007DFF' : '#182431')
            .fontSize(10)
            .lineHeight(14)
            .fontWeight(500)
            .margin({ top: 3 })
        }.width(104).height(56)
        .onClick(() => {
          this.currentIndex = item.num
        })
      })
    }.margin({ left: 24 })
  }

  build() {
    Column() {
      Navigation() {
        TextInput({ placeholder: 'search...' })
          .width('90%')
          .height(40)
          .backgroundColor('#FFFFFF')
          .margin({ top: 8 })

        List({ space: 12, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('90%')
                .height(72)
                .backgroundColor('#FFFFFF')
                .borderRadius(24)
                .fontSize(16)
                .fontWeight(500)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)
        }
        .height(324)
        .width('100%')
        .margin({ top: 12, left: '10%' })
      }
      .title(this.NavigationTitle)
      .menus(this.NavigationMenus)
      .titleMode(NavigationTitleMode.Full)
      .toolBar(this.NavigationToolbar)
      .hideTitleBar(false)
      .hideToolBar(false)
      .onTitleModeChange((titleModel: NavigationTitleMode) => {
        console.info('titleMode' + titleModel)
      })
    }.width('100%').height('100%').backgroundColor('#F1F3F5')
  }
}
```

![en-us_image_0000001192655288](figures/en-us_image_0000001192655288.gif)
