# Navigation

The **\<Navigation>** component is the root view container for navigation. It typically functions as the root container of a page and includes a title bar, content area, and toolbar. The content area switches between the home page content (child components of **\<Navigation>**) and non-home page content (child components of [\<NavDestination>](ts-basic-components-navdestination.md)) through routing.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported

Since API version 9, it is recommended that this component be used together with the **[\<NavRouter>](ts-basic-components-navrouter.md)** component.

Since API version 10, it is recommended that this component be used together with the **[\<NavPathStack>](#navpathstack10)** component and **navDestination** attribute.

## APIs

### Navigation

Navigation()

### Navigation<sup>10+</sup>

Navigation(pathInfos: NavPathStack)

Binds a navigation stack to the **\<Navigation>** component.

**Parameters**

| Name      | Type                           | Mandatory  | Description  |
| --------- | ------------------------------- | ---- | ------ |
| pathInfos | [NavPathStack](#navpathstack10) | No   | Information about the navigation stack.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                                | Type                                    | Description                                      |
| ---------------------------------- | ---------------------------------------- | ---------------------------------------- |
| title                              | [ResourceStr](ts-types.md#resourcestr)<sup>10+</sup> \| [CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup> \| [NavigationCommonTitle](#navigationcommontitle)<sup>9+</sup> \| [NavigationCustomTitle](#navigationcustomtitle)<sup>9+</sup> | Page title.<br>**NOTE**<br>When the NavigationCustomTitle type is used to set the height, the **titleMode** attribute does not take effect.<br>When the title string is too long: (1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...); (2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).|
| subTitle<sup>(deprecated)</sup>    | string                                   | Subtitle of the page. If this attribute is not set, no subtitle is displayed. This attribute is deprecated since API version 9. You are advised to use **title** instead.|
| menus                              | Array<[NavigationMenuItem](#navigationmenuitem)&gt; \| [CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup> | Menu items in the upper right corner of the page. If this attribute is not set, no menu item is displayed. When the value type is Array<[NavigationMenuItem](#navigationmenuitem)&gt;, the menu shows a maximum of three icons in portrait mode and a maximum of five icons in landscape mode, with excess icons (if any) placed under the automatically generated **More** icon.|
| titleMode                          | [NavigationTitleMode](#navigationtitlemode) | Display mode of the page title bar.<br>Default value: **NavigationTitleMode.Free**|
| toolBar<sup>(deprecated)</sup>     | [object](#object) \| [CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup> | Content of the toolbar. If this attribute is not set, no toolbar is displayed.<br>**items**: all items on the toolbar.<br>**NOTE**<br>Items are evenly distributed on the toolbar at the bottom. Text and icons are evenly distributed in each content area. If the text is too long, it is scaled down level by level, wrapped in two lines, and then clipped with an ellipsis (...).<br>This API is deprecated since API version 10. You are advised to use **toolbarConfiguration** instead.|
| toolbarConfiguration<sup>10+</sup> | Array<[ToolbarItem](#toolbaritem10)<sup>10+</sup>&gt; \| [CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup> | Content of the toolbar. If this attribute is not set, no toolbar is displayed.<br>**NOTE**<br>When the value type is Array<[ToolbarItem](#ToolbarItem>, the toolbar exhibits the following features:<br>Items are evenly distributed on the toolbar at the bottom. Text and icons are evenly distributed in each content area.<br>If any item contains overlong text and there are fewer than five items, the following measures are taken: 1. Increase the item's width to accommodate the text until it is as large as the screen width; 2. Scale down the text level by level; 3. Wrap the text in two lines; 4. Clip the text with an ellipsis (...).<br>The toolbar shows a maximum of five icons in portrait mode, with excess icons (if any) placed under the automatically generated **More** icon. In landscape mode, this attribute must be used together with Array<[NavigationMenuItem](#navigationmenuitem)> of the **menus** attribute; the toolbar at the bottom is automatically hidden, and all items on the toolbar are moved to the menu in the upper right corner of the screen.<br>When the value type is [CustomBuilder](ts-types.md#custombuilder8), and the toolbar does not exhibit the preceding features except that items are evenly distributed on the toolbar at the bottom.|
| hideToolBar                        | boolean                                  | Whether to hide the toolbar.<br>Default value: **false**<br>**true**: Hide the toolbar.<br>**false**: Show the toolbar.|
| hideTitleBar                       | boolean                                  | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Show the title bar.|
| hideBackButton                     | boolean                                  | Whether to hide the back button.<br>Default value: **false**<br>**true**: Hide the back button.<br>**false**: Show the back button.<br>The back button in the title bar of the **\<NavDestination>** component cannot be hidden.<br>**NOTE**<br>The back button works only when **titleMode** is set to **NavigationTitleMode.Mini**.|
| navBarWidth<sup>9+</sup>           | [Length](ts-types.md#length)             | Width of the navigation bar.<br>Default value: **240**<br>Unit: vp<br>**NOTE**<br>This attribute is valid only when the **\<Navigation>** component is split.|
| navBarPosition<sup>9+</sup>        | [NavBarPosition](#navbarposition)    | Position of the navigation bar.<br>Default value: **NavBarPosition.Start**<br>**NOTE**<br>This attribute is valid only when the **\<Navigation>** component is split.|
| mode<sup>9+</sup>                  | [NavigationMode](#navigationmode)    | Display mode of the navigation bar.<br>Default value: **NavigationMode.Auto**<br>At the default settings, the component adapts to a single column or two columns based on the component width.<br>**NOTE**<br>Available options are **Stack**, **Split**, and **Auto**.|
| backButtonIcon<sup>9+</sup>        | string \| [PixelMap](../apis/js-apis-image.md#pixelmap7) \| [Resource](ts-types.md#resource) | Back button icon on the navigation bar. The back button in the title bar of the **\<NavDestination>** component cannot be hidden.|
| hideNavBar<sup>9+</sup>            | boolean                                  | Whether to hide the navigation bar.<br>Default value: **false**|
| navDestination<sup>10+</sup>       | builder: (name: string, param: unknown) => void | Creates a **\<NavDestination>** component.<br>**NOTE**<br>The **builder** function is used, with the **name** and **param** parameters passed in. In the builder, a layer of custom components can be included outside the **\<NavDestination>** component. However, no attributes or events can be set for the custom components. Otherwise, only blank components are displayed.|
| navBarWidthRange<sup>10+</sup>     | [[Dimension](ts-types.md#dimension10), [Dimension](ts-types.md#dimension10)] | Minimum and maximum widths of the navigation bar (valid in dual-column mode).<br>Default value: **240** for the minimum value; 40% of the component width (not greater than 432) for the maximum value<br>Unit: vp<br>Priority rules:<br>Custom value > Default value<br>Minimum value > Maximum value<br>navBar > content<br>If values conflict, the global value takes precedence, and the local minimum value depends on the container size.|
| minContentWidth<sup>10+</sup>      | [Dimension](ts-types.md#dimension10)     | Minimum width of the navigation bar content area (valid in dual-column mode).<br>Default value: **360**<br>Unit: vp<br>Priority rules:<br>Custom value > Default value<br>Minimum value > Maximum value<br>navBar > content<br>If values conflict, the global value takes precedence, and the local minimum value depends on the container size.<br>Breakpoint calculation in Auto mode: default 600 vp = minNavBarWidth (240 vp) + minContentWidth (360 vp)|

## Events

| Name                                      | Description                                    |
| ---------------------------------------- | ---------------------------------------- |
| onTitleModeChange(callback: (titleMode: NavigationTitleMode) =&gt; void) | Called when **titleMode** is set to **NavigationTitleMode.Free** and the title bar mode changes as content scrolls.|
| onNavBarStateChange(callback: (isVisible: boolean) =&gt; void) | Called when the navigation bar visibility status changes. The value **true** means that the navigation bar is displayed, and **false** means the opposite.|
| onNavigationModeChange(callback: (mode: NavigationMode) =&gt; void) <sup>11+</sup>| Called when the **\<Navigation>** component is displayed for the first time or its display mode switches between single-column and dual-column.<br>**NavigationMode.Split**: The component is displayed in two columns.<br>**NavigationMode.Stack**: The component is displayed in a single column.|

## NavPathStack<sup>10+</sup>

Implements a navigation stack.

### pushPath<sup>10+</sup>

pushPath(info: NavPathInfo): void

Pushes the navigation destination page specified by **info** to the navigation stack.

**Parameters**

| Name  | Type                           | Mandatory  | Description                  |
| ---- | ----------------------------- | ---- | -------------------- |
| info | [NavPathInfo](#navpathinfo10) | Yes   | Information about the navigation destination page.|

### pushPathByName<sup>10+</sup>

pushPathByName(name: string, param: unknown): void

Pushes the navigation destination page specified by **name**, with the data specified by **param**, to the navigation stack.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| name  | string  | Yes   | Name of the navigation destination page.  |
| param | unknown | Yes   | Detailed parameters of the navigation destination page.|

### replacePath<sup>11+</sup>

replacePath(info: NavPathInfo): void

Replaces the top of the navigation stack with the page specified by **info**.

**Parameters**

| Name  | Type                           | Mandatory  | Description                  |
| ---- | ----------------------------- | ---- | -------------------- |
| info | [NavPathInfo](#navpathinfo10) | Yes   | Parameters of the page to replace the top of the navigation stack.|

### replacePathByName <sup>11+</sup>

replacePathByName(name: string, param: Object): void

Replaces the top of the navigation stack with the page specified by **name**.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| name  | string  | Yes   | Name of the navigation destination page.  |
| param | Object | Yes   | Detailed parameters of the navigation destination page.|

### pop<sup>10+</sup>

pop(): NavPathInfo | undefined

Pops the top element out of the navigation stack.

**Return value**

| Type         | Description                      |
| ----------- | ------------------------ |
| NavPathInfo | Returns the information about the navigation destination page at the top of the stack.|
| undefined   | Returns **undefined** if the navigation stack is empty.     |

### popToName<sup>10+</sup>

popToName(name: string): number

Returns the navigation stack to the first navigation destination page that matches the value of **name**.

**Parameters**

| Name  | Type    | Mandatory  | Description                 |
| ---- | ------ | ---- | ------------------- |
| name | string | Yes   | Name of the navigation destination page.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Returns the index of the first navigation destination page that matches the value of **name** if it exists in the navigation stack; returns **-1** otherwise.|

### popToIndex<sup>10+</sup>

popToIndex(index: number): void

Returns the navigation stack to the page specified by **index**.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ----- | ------ | ---- | ---------------------- |
| index | number | Yes   | Index of the navigation destination page.|

### moveToTop<sup>10+</sup>

moveToTop(name: string): number

Moves to the top of the navigation stack the first navigation destination page that matches the value of **name**.

**Parameters**

| Name  | Type    | Mandatory  | Description                 |
| ---- | ------ | ---- | ------------------- |
| name | string | Yes   | Name of the navigation destination page.|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Returns the index of the first navigation destination page that matches the value of **name** if it exists in the navigation stack; returns **-1** otherwise.|

### moveIndexToTop<sup>10+</sup>

moveIndexToTop(index: number): void

Moves to the top of the navigation stack the navigation destination page that matches the value of **index**.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ----- | ------ | ---- | ---------------------- |
| index | number | Yes   | Index of the navigation destination page.|

### clear<sup>10+</sup>

clear(): void

Clears the navigation stack.

### getAllPathName<sup>10+</sup>

getAllPathName(): Array<string\>

Obtains the names of all navigation destination pages in the navigation stack.

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Array<string\> | Names of all navigation destination pages in the navigation stack.|

### getParamByIndex<sup>10+</sup>

getParamByIndex(index: number): unknown | undefined

Obtains the parameter information of the navigation destination page that matches the value of **index**.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ----- | ------ | ---- | ---------------------- |
| index | number | Yes   | Index of the navigation destination page.|

**Return value**

| Type       | Description                        |
| --------- | -------------------------- |
| unknown   | Returns the parameter information of the matching navigation destination page.|
| undefined | Returns **undefined** if the passed index is invalid.    |

### getParamByName<sup>10+</sup>

getParamByName(name: string): Array<unknown\>

Obtains the parameter information of all the navigation destination pages that match the value of **name**.

**Parameters**

| Name  | Type    | Mandatory  | Description                 |
| ---- | ------ | ---- | ------------------- |
| name | string | Yes   | Name of the navigation destination page.|

**Return value**

| Type             | Description                               |
| --------------- | --------------------------------- |
| Array<unknown\> | Parameter information of all the matching navigation destination pages.|

### getIndexByName<sup>10+</sup>

getIndexByName(name: string): Array<number\>

Obtains the indexes of all the navigation destination pages that match the value of **name**.

**Parameters**

| Name  | Type    | Mandatory  | Description                 |
| ---- | ------ | ---- | ------------------- |
| name | string | Yes   | Name of the navigation destination page.|

**Return value**

| Type            | Description                               |
| -------------- | --------------------------------- |
| Array<number\> | Indexes of all the matching navigation destination pages.|

### size<sup>10+</sup>

size(): number

Obtains the stack size.

**Return value**

| Type    | Description    |
| ------ | ------ |
| number | Stack size.|

## NavPathInfo<sup>10+</sup>

Describes the navigation page information.

### constructor

constructor(name: string, param: unknown)

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| name  | string  | Yes   | Name of the navigation destination page.  |
| param | unknown | No   | Detailed parameters of the navigation destination page.|

## NavigationMenuItem

| Name    | Type           | Mandatory  | Description             |
| ------ | ------------- | ---- | --------------- |
| value  | string        | Yes   | Text of the menu item. Its visibility varies by the API version.<br>API version 9: visible.<br>API version 10: invisible. |
| icon   | string        | No   | Icon path of the menu item.|
| action | () =&gt; void | No   | Callback invoked when the menu item is selected.  |

## object

| Name    | Type           | Mandatory  | Description             |
| ------ | ------------- | ---- | --------------- |
| value  | string        | Yes   | Text of a toolbar item.  |
| icon   | string        | No   | Icon path of a toolbar item.|
| action | () =&gt; void | No   | Callback invoked when a toolbar item is selected.  |

## ToolbarItem<sup>10+</sup>

| Name        | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| value      | ResourceStr                              | Yes   | Text of a toolbar item.                           |
| icon       | ResourceStr                              | No   | Icon path of a toolbar item.                         |
| action     | () =&gt; void                            | No   | Callback invoked when a toolbar item is selected.                           |
| status     | [ToolbarItemStatus](#toolbaritemstatus10) | No   | Status of a toolbar item.<br>Default value: **ToolbarItemStatus.NORMAL**|
| activeIcon | ResourceStr                              | No   | Icon path of the toolbar item in the active state.               |

## ToolbarItemStatus<sup>10+</sup>

| Name      | Description                                      |
| -------- | ---------------------------------------- |
| NORMAL   | Normal state. In this state, the toolbar item takes on the default style and can switch to another state-specific style by responding to the hover, press, and focus events.|
| DISABLED | Disabled state. In this state, the toolbar item is disabled and does not allow for user interactions.|
| ACTIVE   | Active state. In this state, the toolbar item can update its icon to the one specified by **activeIcon** by responding to a click event.|

## NavigationTitleMode

| Name  | Description                                      |
| ---- | ---------------------------------------- |
| Free | When the content is a scrollable component, the main title shrinks as the content scrolls down (the subtitle fades out with its size remaining unchanged) and restores as the content scrolls up to the top.<br>**NOTE**<br>The size linkage effect works only when **title** is set to **ResourceStr** or **NavigationCommonTitle**. If **title** is set to any other value type, the main title changes in mere location when pulled down.|
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

| Name | Description                                                        |
| ----- | ------------------------------------------------------------ |
| Stack | The navigation bar and content area are displayed independently of each other, which are equivalent to two pages.                    |
| Split | The navigation bar and content area are displayed in different columns.<br>The values of **navBarWidthRange** are represented by [minNavBarWidth,maxNavBarWidth].<br>1. When the value of **navBarWidth** is beyond the value range specified by **navBarWidthRange**, **navBarWidth** is set according to the following rules:<br>Value of **navBarWidth** < Value of **minNavBarWidth**: The value of **navBarWidth** is changed to that of **minNavBarWidth**.<br>Value of **navBarWidth** > Value of **maxNavBarWidth** and Component width - Value of **minContentWidth** - Divider width (1 vp) > Value of **maxNavBarWidth**: The value of **navBarWidth** is changed to that of **maxNavBarWidth**.<br>Value of **navBarWidth** > Value of **maxNavBarWidth** and Component width - Value of **minContentWidth** - Divider width (1 vp) < Value of **minNavBarWidth**: The value of **navBarWidth** is changed to that of **minNavBarWidth**.<br>Value of **navBarWidth** > Value of **maxNavBarWidth** and Component width - Value of **minContentWidth** - Divider width (1 vp) is within the value range specified by **navBarWidthRange**: The value of **navBarWidth** is changed to Component width - Value of **minContentWidth** - Divider width (1 vp).<br>2. When the value of **navBarWidth** is within the value range specified by **navBarWidthRange**, **navBarWidth** is set according to the following rules:<br>Value of **minNavBarWidth** + Value of **minContentWidth** + Divider width (1 vp) > = Component width: The value of **navBarWidth** is changed to that of **minNavBarWidth**.<br>Value of **minNavBarWidth** + Value of **minContentWidth** + Divider width (1 vp) < Component width and Value of **navBarWidth** + Value of **minContentWidth** + Divider width (1 vp) > = Component width: The value of **navBarWidth** is changed to Component width - Value of **minContentWidth** - Divider width (1 vp).<br>Value of **minNavBarWidth** + Value of **minContentWidth** + Divider width (1 vp) < Component width and Value of **navBarWidth** + Value of **minContentWidth** + Divider width (1 vp) < Component width: The value of **navBarWidth** is the set value. <br>3. When the component size is decreased, the content area is shrunk until its width reaches the value defined by **minContentWidth**, and then the navigation bar is shrunk until its width reaches the value defined by **minNavBarWidth**; if the component size is further decreased, the content area is further shrunk until it disappears, and then navigation bar is shrunk.<br>4. When the navigation bar is set to a fixed size and the component size is continuously decreased, the navigation bar is shrunk.<br>5. If only **navBarWidth** is set, the width of the navigation bar is fixed at the value of **navBarWidth**, and the divider cannot be dragged.|
| Auto  | In API version 9 and earlier versions: When the window width is greater than or equal to 520 vp, the Split mode is used. In other cases, the Stack mode is used.<br>In API version 10 and later versions: When the window width is greater than or equal to 600 vp, the Split mode is used. In other cases, the Stack mode is used. 600 vp = minNavBarWidth (240 vp) + minContentWidth (360 vp).|

## TitleHeight

| Name         | Description                        |
| ----------- | -------------------------- |
| MainOnly    | Recommended height (56 vp) of the title bar when only the main title is available.     |
| MainWithSub | Recommended height (82 vp) of the title bar when both the main title and subtitle exist.|


>  **NOTE**
>
>  Among the scrollable components, only **\<List>** is supported.


## Example

### Example 1

```ts
// xxx.ets
class A {
  text: string = ''
  num: number = 0
}

@Entry
@Component
struct NavigationExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State currentIndex: number = 0

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
      Image('common/ic_public_add.svg')
        .width(24)
        .height(24)
      Image('common/ic_public_add.svg')
        .width(24)
        .height(24)
        .margin({ left: 24 })
      Image('common/ic_public_more.svg')
        .width(24)
        .height(24)
        .margin({ left: 24 })
    }
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
          ForEach(this.arr, (item: number) => {
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
          }, (item: number) => item.toString())
        }
        .height(324)
        .width('100%')
        .margin({ top: 12, left: '10%' })
      }
      .title(this.NavigationTitle)
      .menus(this.NavigationMenus)
      .titleMode(NavigationTitleMode.Full)
      .toolbarConfiguration([
        {
          value: $r("app.string.navigation_toolbar_add"),
          icon: $r("app.media.ic_public_highlightsed")
        },
        {
          value: $r("app.string.navigation_toolbar_app"),
          icon: $r("app.media.ic_public_highlights")
        },
        {
          value: $r("app.string.navigation_toolbar_collect"),
          icon: $r("app.media.ic_public_highlights")
        }
      ])
      .hideTitleBar(false)
      .hideToolBar(false)
      .onTitleModeChange((titleModel: NavigationTitleMode) => {
        console.info('titleMode' + titleModel)
      })
    }.width('100%').height('100%').backgroundColor('#F1F3F5')
  }
}
```

![en-us_image_navigation](figures/en-us_image_navigation.png)



### Example 2
```ts
// Index.ets
import { pageOneTmp } from './pageOne'
import { pageTwoTmp } from './pageTwo'
import { pages }  from './pageTwo'

@Entry
@Component
struct NavigationExample {
  @Provide('pageInfos') pageInfos: NavPathStack = new NavPathStack()

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      pageOneTmp()
    } else if (name === 'pageTwo') {
      pageTwoTmp({ names: name, values: this.pageInfos } as pages)
    }
  }

  build() {
    Navigation(this.pageInfos) {
      Column() {
        Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.pushPath({ name:'pageOne'}) // Push the navigation destination page specified by name to the navigation stack.
          })
      }
    }.title('NavIndex').navDestination(this.PageMap)
  }
}
```
```ts
// pageOne.ets
class tmpClass{
  count:number=10
}
@Component
export struct pageOneTmp {
  @Consume('pageInfos') pageInfos: NavPathStack;

  build() {
    NavDestination() {
      Column() {
        Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            let tmp = new tmpClass()
            this.pageInfos.pushPathByName('pageTwo', tmp) // Push the navigation destination page specified by name to the navigation stack, with the data specified by param passed in.
          })
        Button('popToname', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.popToName('pageTwo') // Return the navigation stack to the first navigation destination page that matches the value of name.
            console.log('popToName' + JSON.stringify(this.pageInfos), 'Return value' + JSON.stringify(this.pageInfos.popToName('pageTwo')))
          })
        Button('popToIndex', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.popToIndex(1) // Return the navigation stack to the navigation destination page that matches the value of index.
            console.log('popToIndex' + JSON.stringify(this.pageInfos))
          })
        Button('moveToTop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.moveToTop('pageTwo') // Move to the top of the navigation stack the first navigation destination page that matches the value of name.
            console.log('moveToTop' + JSON.stringify(this.pageInfos), 'Return value' + JSON.stringify(this.pageInfos.moveToTop('pageTwo')))
          })
        Button('moveIndexToTop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.moveIndexToTop(1) // Move to the top of the navigation stack the navigation destination page that matches the value of index.
            console.log('moveIndexToTop' + JSON.stringify(this.pageInfos))
          })
        Button('clear', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.clear() // Clear the navigation stack.
          })
        Button('get', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            console.log('-------------------')
            console.log('Obtained the names of all pages in the navigation stack', JSON.stringify(this.pageInfos.getAllPathName()))
            console.log('Obtained parameter information of the navigation destination page specified by index', JSON.stringify(this.pageInfos.getParamByIndex(1)))
            console.log('Obtained parameter information of all the navigation destination pages specified by name', JSON.stringify(this.pageInfos.getParamByName('pageTwo')))
            console.log('Obtained the index information of all the navigation destination pages specified by name', JSON.stringify(this.pageInfos.getIndexByName('pageOne'))))
            console.log ('Obtained the stack size', JSON.stringify (this.pageInfos.size ()))
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfos.pop() // Pop the top element out of the navigation stack.
      console.log ('pop' + 'Return value' + JSON.stringify (this.pageInfos.pop ()))
      return true
    })
  }
}
```
```ts
// pageTwo.ets

export class pages {
  names: string = ""
  values: NavPathStack | null = null
}

@Builder
export function pageTwoTmp(info: pages) {
  NavDestination() {
    Column() {
      Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })
        .width('80%')
        .height(40)
        .margin(20)
        .onClick(() => {
          (info.values as NavPathStack).pushPathByName('pageOne', null)
        })
    }.width('100%').height('100%')
  }.title('pageTwo')
  .onBackPressed(() => {
    (info.values as NavPathStack).pop()
    return true
  })
}
```
![navigation.gif](figures/navigation.gif)
