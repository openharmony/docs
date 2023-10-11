# Navigation Transition


Navigation transition is a transition animation that runs during the navigation from one view to another. The animation settings of the navigation transition are pre-defined and cannot be modified.


To implement the navigation transition, you are advised to use the [\<Navigation>](../reference/arkui-ts/ts-basic-components-navigation.md) component, complete with the [\<NavRouter>](../reference/arkui-ts/ts-basic-components-navrouter.md) and [\<NavDestination>](../reference/arkui-ts/ts-basic-components-navdestination.md) components.


Below is the complete sample code and effect.



```ts
@Entry
@Component
struct NavigationDemo {
  private listArray: Array<number> = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  // Set the title bar menu, if a title bar is involved.
  @Builder NavigationMenus() {
    Column() {
      Text('menu')
        .fontColor('#182431')
        .fontSize(14)
        .lineHeight(19)
        .opacity(0.4)
        .margin({ top: 70 })
    }
    .alignItems(HorizontalAlign.Start)
  }

  build() {
    Stack() {
      Column() {
        // Define the <Navigation> component, setting the display mode and title.
        Navigation() {
          // An <Input> component is defined here.
          TextInput({ placeholder: 'Search...' })
            .width('90%')
            .height(40)
            .backgroundColor('#ededed')
            .margin({ bottom: 10 })

          // Define the level-1 navigation view through <List>.
          List({ space: 12, initialIndex: 0 }) {
            ForEach(this.listArray, (item:number) => {
              ListItem() {
                // Define the navigation transition through <NavRouter> and define the navigation destination through <NavDestination>. Parameters are transferred between views through state variables or regular variables between components.
                // <NavRouter> must contain two child components. The first child component is the level-1 navigation view, and the second child component must be <NavDestination>, which specifies the navigation destination.
                NavRouter() {
                  // First component: Level-1 navigation view.
                  Row() {
                    Row()
                      .width(40)
                      .height(40)
                      .backgroundColor('#a8a8a8')
                      .margin({ right: 12 })
                      .borderRadius(20)

                    Column() {
                      Text('Level-1 item')
                        .fontSize(16)
                        .lineHeight(21)
                        .fontWeight(FontWeight.Medium)
                      Text('Click to go to subitems')
                        .fontSize(13)
                        .lineHeight(21)
                        .fontColor('#a8a8a8')
                    }
                    .alignItems(HorizontalAlign.Start)

                    Blank()

                    Row()
                      .width(15)
                      .height(15)
                      .margin({ right: 12 })
                      .border({
                        width: { top: 2, right: 2 },
                        color: 0xcccccc
                      })
                      .rotate({ angle: 45 })
                  }
                  .borderRadius(15)
                  .shadow({ radius: 100, color: '#ededed' })
                  .width('90%')
                  .alignItems(VerticalAlign.Center)
                  .padding({ left: 16, top: 12, bottom: 12 })
                  .height(80)

                  // Second component: navigation destination
                  NavDestination() {
                    // Content of the destination view, which is generally a custom component.
                    Column() {
                      Text("Destination"+ item +" content ")
                        .fontSize(20)
                        .fontColor(Color.Black)
                        .textAlign(TextAlign.Center)
                        .width('100%')
                        .height('100%')
                    }
                    .width('100%')
                    .height('100%')
                    .backgroundColor(0xf5f5f5)
                  }
                  .title('Destination page') // Title of the level-2 page.
                }
              }
              .width('100%')
            }, (item:string):string => item)
          }
          .listDirection(Axis.Vertical)
          .edgeEffect(EdgeEffect.Spring)
          .sticky(StickyStyle.Header)
          .chainAnimation(false)
          .borderRadius(15)
          .width('100%')
          .height('100%')
        }
        .width('100%')
        .mode(NavigationMode.Auto) // Set the display mode of the navigation bar to Auto.
        .title('Navigation transition') // Set the title text.
        .titleMode(NavigationTitleMode.Full) // Set the display mode of the page title bar.
        .menus(this.NavigationMenus) // Set the title bar menu.
      }
      .width('100%')
    }
  }
}
```



![en-us_image_0000001588458252](figures/en-us_image_0000001588458252.gif)
