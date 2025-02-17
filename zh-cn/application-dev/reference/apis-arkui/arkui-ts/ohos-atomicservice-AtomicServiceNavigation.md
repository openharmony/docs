# AtomicServiceNavigation

作为Page页面的根容器使用，其内部默认包含了标题栏、内容区，其中内容区默认首页显示导航内容或非首页显示（[NavDestination](ts-basic-components-navdestination.md)的子组件），首页和非首页通过路由进行切换。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```
import { AtomicServiceNavigation } from '@kit.ArkUI';
```

## 子组件

可以包含子组件。
从API Version 10开始，推荐使用[NavPathStack](ts-basic-components-navigation.md#navpathstack10)进行页面路由。
## AtomicServiceNavigation

```
AtomicServiceNavigation({
    navPathStack?: NavPathStack,
    navigationContent: Callback<void>,
    title?: ResourceStr,
    titleOptions?: TitleOptions,
    gradientBackground?: GradientBackground,
    hideTitleBar?: boolean,
    navBarWidth?: Length,
    mode?: NavigationMode,
    navDestinationBuilder?: NavDestinationBuilder,
    navBarWidthRange?: [Dimension, Dimension],
    minContentWidth?: Dimension,
    stateChangeCallback?: Callback<boolean>,
    modeChangeCallback?: Callback<NavigationMode>
})
```

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**装饰器类型：** @Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 名称 | 类型 | 必填 | 装饰器类型|说明 |
| --------------- | ------ | ---- | ----|----------|
| navPathStack | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | 否 | @State | 路由栈信息。 |
| navigationContent | Callback\<void\> | 否 | @BuilderParam | Navigation容器内容。 |
| title | [ResourceStr](ts-types.md#resourcestr) | 否 |@Prop | 设置页面标题。|
| titleOptions | [TitleOptions](#titleoptions) | 否 | @Prop | 标题栏选项。|
| gradientBackground<sup>16+</sup> | [GradientBackground](#gradientbackground16) | 否 | @Prop | 背景色选项。|
| hideTitleBar | boolean | 否 | @Prop | 设置是否隐藏标题栏。|
| navBarWidth | [Length](ts-types.md#length)| 否 | @Prop | 设置导航栏宽度。<br>仅在Navigation组件分栏时生效。|
| mode| [NavigationMode](ts-basic-components-navigation.md#navigationmode9枚举说明) | 否 | @Prop |设置导航栏的显示模式。<br>支持Stack、Split与Auto模式。|
| navDestinationBuilder | [NavDestinationBuilder](#navdestinationbuilder) | 否 | @BuilderParam | 创建[NavDestination](ts-basic-components-navdestination.md)组件所需要的Builder数据。 |
| navBarWidthRange | [[Dimension](ts-types.md#dimension10), [Dimension](ts-types.md#dimension10)] | 否 | @Prop |设置导航栏最小和最大宽度（双栏模式下生效）。|
| minContentWidth | [Dimension](ts-types.md#dimension10) | 否 | @Prop | 设置导航栏内容区最小宽度（双栏模式下生效）。|
| stateChangeCallback | Callback\<boolean\> | 否 | - | 导航栏显示状态切换时触发该回调。|
| modeChangeCallback | Callback\<[NavigationMode](ts-basic-components-navigation.md#navigationmode9枚举说明)\> | 否 | - | 当Navigation首次显示或者单双栏状态发生变化时触发该回调。|

## TitleOptions
标题栏选项。
**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明 |
| --------------- | ------ | ---- | ---------- |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 标题栏背景颜色。 |
| isBlurEnabled | boolean | 否 | 标题栏是否模糊，默认为true。 |
| barStyle | [BarStyle](ts-basic-components-navigation.md#barstyle12枚举说明)  | 否 | 标题栏样式属性设置。 |

## GradientBackground<sup>16+</sup>
供开发者设置品牌渐变色。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明 |
| --------------- | ------ | ---- | ---------- |
| primaryColor | [ResourceColor](ts-types.md#resourcecolor)  | 是 | 单色渐变色彩值和双色渐变第一色彩值。无默认值。|
| secondaryColor |[ResourceColor](ts-types.md#resourcecolor)  | 否 |双色渐变色第二色彩值。无默认值。|
| backgroundTheme |[BackgroundTheme<sup>16+</sup>](#backgroundtheme16)  | 否 |导航栏背景底色。默认值为DEFAULT。|
| mixMode | [MixMode<sup>16+</sup>](#mixmode16)  | 否 |同时设置primaryColor和secondaryColor时此参数生效。代表双色渐变下两种颜色的融合方式。默认值为TOWARDS。|
| alpha | [GradientAlpha<sup>16+</sup>](#gradientalpha16)  | 否 |设置渐变色显示区域的透明度。默认值为OPACITY_20。|

## NavDestinationBuilder

type NavDestinationBuilder = (name: string, param?: Object) => void

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full
    
| 参数名 | 类型 | 必填 | 描述 |
| --------------- | ------ | ---- | ---------- |
| name | string | 是 | [NavDestination](ts-basic-components-navdestination.md)页面名称。 |
| param | Object | 是 | [NavDestination](ts-basic-components-navdestination.md)页面详细参数。 |

## MixMode<sup>16+</sup>
背景色颜色混合模式的可选项。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| --------------- | ------ |-----|
| AVERAGE  | 1 | 两种颜色各占一半。  |
| CROSS  | 2 | 一种颜色从另一种颜色中穿过。 |
| TOWARDS  | 3 | 一种颜色渐变为另一种颜色。 |


## GradientAlpha<sup>16+</sup>
导航栏背景底色的可选项。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| --------------- | ------ |-----|
| OPACITY_20| 1 | 不透明度为0.2。 |
| OPACITY_60| 2 | 不透明度为0.6。|
| OPACITY_80| 3 | 不透明度为0.8。 |
| OPACITY_100| 4 | 不透明度为1.0。 |

## BackgroundTheme<sup>16+</sup>
导航栏背景色底色的可选项。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| --------------- | ------ |-----|
| DARK  | 1 | 背景底色为黑色。 |
| LIGHT  | 2 | 背景底色为白色。|
| DEFAULT  | 3 | 背景底色为灰白色。颜色值`#F1F3F5` 。|


## 示例

```ts
import { AtomicServiceNavigation, NavDestinationBuilder, AtomicServiceTabs, TabBarOptions, TabBarPosition } from '@kit.ArkUI';
import { MixMode, GradientAlpha, BackgroundTheme} from '@ohos.atomicservice.AtomicServiceNavigation'
@Entry
@Component
struct Index {
  @State message: string = '主题';
  childNavStack: NavPathStack = new NavPathStack();
  @Builder
  tabContent1() {
    Text('first page')
      .onClick(() => {
        this.childNavStack.pushPath({ name: 'page one' })
      })
  }

  @Builder
  tabContent2() {
    Text('second page')
  }

  @Builder
  tabContent3() {
    Text('third page')
  }

  @Builder
  navigationContent() {
    AtomicServiceTabs({
      tabContents: [
        () => {
          this.tabContent1()
        },
        () => {
          this.tabContent2()
        },
        () => {
          this.tabContent3()
        }
      ],
      tabBarOptionsArray: [
        new TabBarOptions($r('sys.media.ohos_ic_public_phone'), '功能1'),
        new TabBarOptions($r('sys.media.ohos_ic_public_location'), '功能2', Color.Green, Color.Red),
        new TabBarOptions($r('sys.media.ohos_ic_public_more'), '功能3')
      ],
      tabBarPosition: TabBarPosition.BOTTOM,
      barBackgroundColor: $r('sys.color.ohos_id_color_bottom_tab_bg'),
      onTabBarClick: (index: Number) => {
        if (index == 0) {
          this.message = '功能1';
        } else if (index == 1) {
          this.message = '功能2';
        } else {
          this.message = '功能3';
        }
      }
    })
  }

  @Builder
  pageMap(name: string) {
    if (name === 'page one') {
      PageOne()
    } else if (name === 'page two') {
      PageTwo()
    }
  }

  build() {
    Row() {
      Column() {
        AtomicServiceNavigation({
          navigationContent: () => {
            this.navigationContent()
          },
          title: this.message,
          titleOptions: {
            isBlurEnabled: false
          },
          gradientBackground: {
            primaryColor: 'red',
            secondaryColor: 'green',
            backgroundTheme: BackgroundTheme.LIGHT,
            mixMode: MixMode.AVERAGE,
            alpha: GradientAlpha.OPACITY_100
          },
          navDestinationBuilder: this.pageMap,
          navPathStack: this.childNavStack,
          mode: NavigationMode.Stack
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Component
export struct PageOne {
  pageInfo: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Button('Next')
        .onClick(() => {
          this.pageInfo.pushPath({ name: 'page two'})
        })
    }
    .title('PageOne')
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@Component
export struct PageTwo {
  pageInfo: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Button('End')
    }
    .title('PageTwo')
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}
```

![](figures/AtomicServiceNavigationDemo02.jpg)