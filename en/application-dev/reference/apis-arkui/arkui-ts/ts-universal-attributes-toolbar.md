# Toolbar

You can configure the toolbar for a component.

>  **NOTE**
>
>  The feature is supported since API version 20. Updates will be marked with a superscript to indicate their earliest API version.
>
>  This toolbar is a universal attribute for components. Note the distinction from the toolbar attribute of the [Navigation](ts-basic-components-navigation.md#navigation) component.

## toolbar

toolbar(value: CustomBuilder)

Creates a toolbar bound to the component in the window's title bar section. The toolbar position corresponds to the component's position in the layout. The [CustomBuilder](ts-types.md#custombuilder8) must consist of [ToolBarItem](ts-basic-components-toolbaritem.md#toolbaritem) components to take effect.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                       | Mandatory| Description                                           |
| ------ | ------------------------------------------- | ---- | ----------------------------------------------- |
| value  | [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Custom toolbar of the CustomBuilder type for the current component.|

>  **NOTE**
>  1. Only fixed title bars are supported; floating title bars in three-button navigation mode are not supported.
>
>  2. You can customize the toolbar layout and place it on the left or right side. However, if the number of elements exceeds the available space, layout truncation or focus frame overlap may occur, rendering some actions invisible or causing interaction conflicts. There is no automatic shrinking, so keep the number of elements reasonable.
>
>  3. The toolbar only supports single-line layouts, so avoid putting multi-line elements in it.
>
>  4. The toolbar only works when [NavigationMode](ts-basic-components-navigation.md#navigationmode9) is set to **Split**. It does not work with **Stack** or **Auto** modes.
>
>  5. The title bar height dynamically adjusts based on the [ToolBarItem](ts-basic-components-toolbaritem.md#toolbaritem) components in the toolbar:
>     * There is a default 4 vp margin between the [ToolBarItem](ts-basic-components-toolbaritem.md#toolbaritem) components and the title bar.
>     * If the tallest [ToolBarItem](ts-basic-components-toolbaritem.md#toolbaritem) component is less than or equal to 48 vp, the title bar height will adjust to 56 vp. This setting is suitable for universal components such as title bars, toolbars, and search bars.
>     * If the tallest [ToolBarItem](ts-basic-components-toolbaritem.md#toolbaritem) component is between 48 vp and 56 vp, the title bar height will adjust to 64 vp. This setting is suitable for toolbars that display both icons and text.
>     * If the tallest [ToolBarItem](ts-basic-components-toolbaritem.md#toolbaritem) component exceeds 56 vp, the title bar height will adjust to 72 vp. If it exceeds 64 vp, the title bar height will remain at 72 vp, and any excess area will be clipped.

## Example

This example demonstrates how to:

1. Bind the universal **toolbar** attribute to a [Button](ts-basic-components-button.md#button) component under [Navigation](ts-basic-components-navigation.md#navigation), adding two button toolbar items at the start of the **Navbar** section in the title bar.
2. Bind the **toolbar** attribute to a [Text](ts-basic-components-text.md#text) component under [NavDestination](ts-basic-components-navdestination.md#navdestination) to add a slider and a search bar component as toolbar items at the end of the **NavDestination** section in the title bar.

```ts
// xxx.ets
@Entry
@Component
struct SideBarContainerExample {
  normalIcon: Resource = $r("app.media.startIcon")
  selectedIcon: Resource = $r("app.media.startIcon")
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1
  @Provide('navPathStack') navPathStack: NavPathStack = new NavPathStack()

  @Builder
  MyToolBar() {
    ToolBarItem({ placement: ToolBarItemPlacement.TOP_BAR_LEADING }) {
      Button("left").height("30vp")
    }

    ToolBarItem({ placement: ToolBarItemPlacement.TOP_BAR_LEADING }) {
      Button("right").height("30vp")
    }
  }

  @Builder
  MyToolbarNavDest() {
    ToolBarItem({ placement: ToolBarItemPlacement.TOP_BAR_TRAILING }) {
      Slider().width("120vp")
    }

    ToolBarItem({ placement: ToolBarItemPlacement.TOP_BAR_TRAILING }) {
      Search().width("120vp")
    }
  }

  @Builder
  PageNavDest(name: string) {
    if (name = "1")
    NavDestination() {
      Column() {
        Text("add toolbar")
          .fontSize(30)
          .toolbar(this.MyToolbarNavDest())
      }
      .backgroundColor(Color.Grey)
    }
  }

  build() {
    SideBarContainer(SideBarContainerType.Embed) {
      Column() {
        ForEach(this.arr, (item: number) => {
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
        }, (item: string) => item)
      }.width('100%')
      .justifyContent(FlexAlign.SpaceEvenly)
      .backgroundColor('#19000000')

      Navigation(this.navPathStack) {
        Column() {
          Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })
            .width('20%')
            .height(40)
            .margin(20)
            .toolbar(this.MyToolBar)
          Button('showNavDest', { stateEffect: true, type: ButtonType.Capsule })
            .width('20%')
            .height(40)
            .margin(20)
            .onClick(() => {
              this.navPathStack.pushPath({ name: "1" })
            })
        }
        .width('100%')
        .height('100%')
      }
      .navBarPosition(NavBarPosition.Start)
      .navBarWidth("50%")
      .navBarWidthRange(["25%", "70%"])
      .hideBackButton(true)
      .navDestination(this.PageNavDest)
      .height('100%')
      .title('Navigation')
    }
    .sideBarWidth(150)
    .minSideBarWidth(50)
    .maxSideBarWidth(300)
    .minContentWidth(0)
    .onChange((value: boolean) => {
      console.info('status:' + value)
    })
    .divider({
      strokeWidth: '1vp',
      color: Color.Gray,
      startMargin: '4vp',
      endMargin: '4vp'
    })
  }
}
```
<!--no_check-->