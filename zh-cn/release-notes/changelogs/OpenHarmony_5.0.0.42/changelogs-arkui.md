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
const myIcon: NavigationMenuItem = { value: "图标", icon: "https://example.png"}
const myString: string = myIcon.value

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

## cl.arkui.2 优化状态变量场景下ForEach的冗余刷新行为

**访问级别**

公开接口

**变更原因**

开发者使用ForEach，在旧节点下树的时候会被刷新一次，属于规格外的行为，当刷新调用方法中存在对全局变量的修改时会发生异常。

**变更影响**

该变更为不兼容变更。

变更前：开发者在使用ForEach时，节点下树的时候会被刷新一次。

变更后：开发者在使用ForEach时，节点下树的时候不会被刷新。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.42开始。

**变更的接口/组件**

ForEach

**适配指导**

之前使用ForEach涉及节点刷新时调用的方法存在对全局变量值修改的，需要根据具体情况对代码进行相应的修改，使当前修改等效于原来的两次修改叠加，以保证效果不变。

示例：

变更前：
```ts
let g_data = 0;

@Entry
@Component
struct MyComponent {
  @State simpleList: number[] = [0, 1, 2]

  fn(item: number, index: number) {
    g_data++;
    return 80;
  }

  build() {
    Row() {
      Column() {
        Button('click button []')
          .onClick(() => {
            this.simpleList = [4, 5, 6]
          })
        ForEach(this.simpleList, (item: number, index: number) => {
          Text(item.toString())
            .fontSize(this.fn(item, index))
            .onAppear(()=>{
              console.log('g_data: ' + g_data);
            })
        }, (item: string) => item)
      }
      .width('100%')
      .height('100%')
    }
  }
}
```

变更后：
```ts
let g_data = 0;

@Entry
@Component
struct MyComponent {
  @State simpleList: number[] = [0, 1, 2]

  fn(item: number, index: number) {
    // 变更前总会调用两次，变更后只会调用一次，保证变更前后效果一致
    g_data+=2;
    return 80;
  }

  build() {
    Row() {
      Column() {
        Button('click button []')
          .onClick(() => {
            this.simpleList = [4, 5, 6]
          })
        ForEach(this.simpleList, (item: number, index: number) => {
          Text(item.toString())
            .fontSize(this.fn(item, index))
            .onAppear(()=>{
              console.log('g_data: ' + g_data);
            })
        }, (item: string) => item)
      }
      .width('100%')
      .height('100%')
    }
  }
}
```

## cl.arkui.3 Navdestination的Dialog模式默认支持系统动画

**访问级别**

公开接口

**变更原因**

Navdestination的Dialog模式支持系统动画

**变更影响**
该变更为不兼容变更。

变更前：Navdestination的Dialog模式，无系统默认动画。

变更后：Navdestination的Dialog模式，默认带有系统转场动画。

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/dialog_before.gif) | ![](figures/dialog_after.gif) |

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.42开始。

**变更的接口/组件**

Navdestination

**适配指导**

开发者可以通过在pop与push接口中设置false关闭Navdestination的系统默认动画。

示例：

其中，NavDestination的内容区需自行构造，可参考[开发指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/ui/arkts-navigation-navigation.md)。

```ts
@Entry
@Component

struct NavigationDemo {
	@State pageInfos: NavPathStack = new NavPathStack();

	@Builder
	pageOneTmp() {
		NavDestination() {
          // ...
          // 需自行构造NavDestination
		}
		.title("PageOne")
		.mode(NavDestinationMode.DIALOG)
	}

	@Builder
	PageMap(name: string, param: object) {
		if (name === 'pageOne') {
			this.pageOneTmp()
		}
	}

	build() {
		Column({ space: 10 }) {
			Button('Pop Dialog')
			.onClick(() => {
				// set false to close system pop animation
				this.pageInfos.pop(false)
			})
			Button('Push Dialog')
			.onClick(() => {
				// set false to close system push animation
				this.pageInfos.pushPath({ name: 'pageOne' }, false)
			})
			Navigation(this.pageInfos) {
				Column({ space: 10 }) {
					Text("This is navigation").fontSize(60).align(Alignment.Center)
				}
			}
			.height(500)
			.backgroundColor(Color.Grey)
			.navDestination(this.PageMap)
		}.height(50)
	}
}
```