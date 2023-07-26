# arkui子系统ChangeLog

## cl.arkui.1 Navigation menus属性显示变更

**变更影响**

menus的value属性值不做显示，如果需要显示，可以使用自定义Builder显示。

**示例：**
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
API Version 9：menus的value属性会显示

![Navigation](figures/navigation_menu_api9.png)

API Version 10: menus中的value属性不显示
![Navigation](figures/navigation_menu_api10.png)

## cl.arkui.2 Navigation的titleMode属性Free模式默认显示位置变更

**变更影响**
1. Navigation组件自定义标题并titleMode设置为Full模式或Free模式显示位置相同
2. 使用自定义title结合Free模式的标签会出现标签位置向右偏移

**示例：**
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

API Version 9: Free模式显示位置

![Navigation](figures/navigation_title_mode_free_sdk9.png)

API Version 10: Free模式显示位置与Full模式显示位置相同

![Navigation](figures/navigation_title_mode_free_sdk10.png)