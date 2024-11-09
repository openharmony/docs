# ArkUI Subsystem Changelog
## cl.arkui.1 Resource Type Support Added for Navigation and NavDestination Components' title and menus APIs
**Access Level**

Public API

**Reason for Change**

This change is made for enhancement of basic capabilities.

**Change Impact**

This change is a non-compatible change.

After the type of **NavigationMenuItem** changes to string | Resource, it no longer matches a single variable type of string. Therefore, assigning **NavigationMenuItem** to a string type variable will result in a compilation error.

```
@State myString: string = '';
@State myIcon: NavigationMenuItem["value"] = $r("app.string.MyTestMenuValue1")

this.myString = this.myIcon
```

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.42

**Key API/Component Changes**

Navigation/NavDestination

**Adaptation Guide**

```
// navigation.ets
// Assign Resource type values to the title and menu APIs of Navigation or NavDestination.
Navigation() {
    // xxx
}
.title($r('app.string.MyTestNavigationTitle'))  // Resource type values can be directly passed to the title API.
// The item settings within menus directly support Resource type values.
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
// The CommonTitle type of Navigation and NavDestination supports Resource type settings.
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
