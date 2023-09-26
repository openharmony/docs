# ArkUI Subsystem Changelog

## cl.arkui.1 Visibility Change of the menus Attribute in \<Navigation>

**Change Impact**

The **value** sub-attribute of the **menus** attribute is not displayed. To display the value, you can use a custom builder.

**Example**
```ts
@Entry
@Component
struct Index {
  build() {
    Column() {
      Navigation() {
        Text('Navigation')
      }.title("Navigation Menu")
      .menus([
        {icon: 'common/image/icon.png', value: 'menu1'},
        {icon: 'common/image/icon.png', value: 'menu2'},
        {icon: 'common/image/icon.png', value: 'menu3'}
      ])
    }
  }
}
```
In API version 9, the **value** sub-attribute of the **menus** attribute is displayed.

![Navigation](figures/navigation_menu_api9.png)

In API version 10, the **value** sub-attribute of the **menus** attribute is not displayed.

![Navigation](figures/navigation_menu_api10.png)

## cl.arkui.2 Change of the Default Display Position for Free Mode of the titleMode Attribute in \<Navigation>

**Change Impact**
1. In the **\<Navigation>** component, the display position of a custom title with **titleMode** set to **Full** is the same as that with **titleMode** set to **Free**.
2. If a custom title is used with a label in Free mode, the label is deviated rightwards.

**Example**
```ts
@Entry
@Component
struct Index {
  @Builder NavigationTile() {
    Column() {
      Text('title').fontColor('#182431').fontSize(30).lineHeight(41)
      Text('subTitle').fontColor('#182431').fontSize(14).lineHeight(19).margin(top:2, bottom: 20)
    }
  }

  build() {
    Column() {
      Navigation() {
        Text('Navigation')
      }.title(this.NavigationTitle)
       .titleMode(NavigationTitleMode.Free)
       .menus([
        {icon: 'common/image/icon.png', value: 'menu1'}
       ])
    }
  }
}
```

Display position in Free mode in API version 9

![Navigation](figures/navigation_title_mode_free_sdk9.png)

Display position in Free mode in API version 10, which is the same as that in Full mode

![Navigation](figures/navigation_title_mode_free_sdk10.png)

## cl.arkui.3 Change of Advanced Animation APIs to System APIs

**Change Impact**
The **sphericalEffect**, **lightUpEffect**, and **pixelStretchEffect** APIs are changed from public APIs to system APIs, which are not exposed to external developers.

## cl.arkui.4 Specification Change of the onClick Event

**Change Impact**
1. If a component is bound to both onClick/TapGesture and PanGesture, it responds to PanGesture, but not onClick/TapGesture, when the finger slides beyond the allowed distance.
2. If a component is bound to only onClick/TapGesture, it responds to onClick/TapGesture when the finger is lifted up after having moved within the component area.
3. If a component is bound to only onClick/TapGesture, it does not respond to onClick/TapGesture when the finger is lifted up after having moved beyond the component area.
