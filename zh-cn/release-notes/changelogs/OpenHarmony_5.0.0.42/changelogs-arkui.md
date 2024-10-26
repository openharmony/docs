# ArkUI子系统ChangeLog
## cl.arkui.1 Navigation、NavDestination的title和menus接口支持Resource类型资源
**访问级别**

公开接口

**变更原因**

基础能力增强，Navigation、navdestination的title和menus接口支持Resource类型

**变更影响**

该变更为不兼容变更。

由于NavigationMenuItem变量类型变更为 string | Resource，不再与单一变量类型string相匹配，因此将NavigationMenuItem赋值给一个string类型变量，程序会编译报错。

```
@State myString: string = '';
@State myIcon: NavigationMenuItem["value"] = $r("app.string.MyTestMenuValue1")

this.myString = this.myIcon
```

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.42 版本开始。

**变更的接口/组件**

Navigation/NavDestination

**适配指导**

```
// navigation.ets
// 使用resource类型资源赋值给Navigation/NavDestination的title及menu接口
Navigation() {
    // xxx
}
.title($r('app.string.MyTestNavigationTitle'))  // 可直接将resource类型资源传递给title接口
// menus内的item设置可直接支持resource类型资源
.menus([
  {
    value: $r("app.string.MyTestMenuValue1"),
    icon: $r("app.media.1")
  },
  {
    value: $r("app.string.MyTestMenuValue2"),
    icon: $r("app.media.2")
  },
  {
    value: $r("app.string.MyTestMenuValue3"),
    icon: $r("app.media.3")
  }
])
```


```
// navDestination.ets
// Navigation及NavDestination的CommonTitle类型，支持设置resource资源
@State commonTitle: NavDestinationCommonTitle = { main: $r('app.string.MyTestNavigationTitle'), sub: $r('app.string.MyTestNavigationTitle')}
NavDestination() {
    // xxx
}
.menus([
  {
    value: $r("app.string.MyTestMenuValue1"),
    icon: $r("app.media.4")
  },
  {
    value: $r("app.string.MyTestMenuValue2"),
    icon: $r("app.media.5")
  },
  {
    value: $r("app.string.MyTestMenuValue3"),
    icon: $r("app.media.6")
  }
])
.title(this.commonTitle)
```