# ArkUI子系统Changelog

## cl.arkui.1 默认深浅色切换流程变更

**访问级别**

其他

**变更原因**

针对深浅色模式切换等系统配置的热更新场景，当前的实现方式会导致整个组件树重新构建，进而使得TS层的UI代码重新执行。在页面结构较为复杂时，这种处理方式会显著降低时间性能。我们需要对此进行优化。

**变更影响**

此变更涉及应用适配

- 变更前：系统配置热更新场景下，组件树重新构建，相关属性设置的代码重新执行，存在大量不涉及深浅色变更的冗余开销。
  
- 变更后：开发者在属性中调用的方法不会再被触发。因此，如果有开发者在属性设置中使用了函数的方式去适配深浅色变化，那么变更后将会失效。

**起始API Level**

不涉及API

**变更发生版本**

从OpenHarmony SDK 6.0.1.2开始。

**变更的接口/组件**

不涉及具体接口/组件

**适配指导**

上面的适配方式虽然在旧版本能够生效，但并不是合理的适配方式，变更后将不再支持。
开发者可以根据自己的业务场景，按照如下正确方式进行深浅色模式适配：
方法一：对于仅仅是深浅色模式下显示类资源的自定义配置场景，比如上面代码中的背景色切换，推荐开发者采用资源目录配置的方式适配深浅色。
参考开发指南：[应用深浅色适配](../../../application-dev/ui/ui-dark-light-color-adaptation.md)
方法二：对于在不同颜色模式下有比较复杂的定制业务逻辑的场景，开发者需要在Ability类提供的系统配置变更回调中监听配置变更，当深浅等配置变化时通过绑定状态变量等方式进行适配，[参考API文档](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)
下面是一个简单的例子：

```ts
@Entry
@Component
struct Index {
  // 深浅色适配函数
  getBackgroundColor(): ResourceColor {
    // let isDark = getSystemColorMode(); 通过媒体查询等方式获取当前系统颜色模式
    // some other codes  其他的定制逻辑
    return isDark ? Color.Blue : Color.Black; // 返回自定义颜色值
  }
  build() {
    RelativeContainer() {
      Column()
        .width(100)
        .height(100)
        // 依赖backgroundColor()属性设置接口重新执行，才会重新执行getBackgroundColor()完成正确切换
        .backgroundColor(this.getBackgroundColor())
    }
    .height('100%')
    .width('100%')
  }
}
```

1、通过程序启动时，在UIAbility中重写onConfigurationUpdate监听配置变化。
```ts
// EntryAbility.ts
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    AppStorage.setOrCreate('currentColorMode', this.context.config.colorMode);

  }

  onConfigurationUpdate(newConfig: Configuration): void {
    AppStorage.setOrCreate('currentColorMode', newConfig.colorMode);
  }
```

2、在需要适配的地方通过[AppStorage能力](../../../application-dev/ui/state-management/arkts-appstorage.md)进行适配。

```ts
import { ConfigurationConstant } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @State isDark: boolean = false;
  @StorageProp('currentColorMode') @Watch('onColorModeChange') currentMode: number =
    ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT;

  onColorModeChange(): void {
    // 也可以实现更加复杂的应用自定义的适配逻辑，这里用一个颜色变量的设置作为简单例子
    this.isDark = (this.currentMode === ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT) ? false : true;
    this.columColor = this.isDark ? Color.Blue : Color.Black;
  }

  getBackgroundColor(): ResourceColor {
    return this.isDark ? Color.Blue : Color.Black;
  }

  // 通过状态变量触发页面更新逻辑
  @State columColor: ResourceColor = Color.Black;

  build() {
    RelativeContainer() {
      Column()
        .width(100)
        .height(100)
        .backgroundColor(this.getBackgroundColor())// 变更前 
        .backgroundColor(this.columColor)
    }
    .height('100%')
    .width('100%')
  }
}
```

## cl.arkui.2 WithTheme组件设置colorMode后效果异常问题修复

**访问级别**

公开

**变更原因**

WithTheme组件指定局部主题的能力对某些组件不生效。例如：通过WithTheme设置主题深浅色为DARK或LIGHT后，Button子组件使用的资源仍会依循系统深浅色变化。

**变更影响**

此变更涉及应用适配

- 变更前：WithTheme组件设置了主题后，其子组件的主题仍旧跟随系统切换。
  
- 变更后：WithTheme组件设置了主题后，其中的子组件使用指定的主题，不跟随系统切换。

 **变更涉及组件范围**
 
  变更前部分组件未适配WithTheme，因此其作为WithTheme子组件不受指定的主题影响，因此变更后这部分组件的行为会受到影响。变更前后会受到影响的具体组件类型列表如下：

  TextArea、Search、Button、DatePicker、TextPicker、TimePicker、AlphabetIndexer、Swiper、Scroll、Tabs、TabContent、RichEditor、Menu、MenuItem、Counter、Progress、TextClock、LoadingProgress。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 6.0.1.2开始。

**变更的接口/组件**

 WithTheme

**适配指导**

变更后，WithTheme组件指定的主题对子组件生效。若需适配，应针对发生变化的组件增加WithTheme，并指定其主题跟随系统，例如设置colorMode属性为SYSTEM。

```ts
// index.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      // 设置组件为深色模式
      WithTheme({ colorMode: ThemeColorMode.DARK }) {
      // 适配:设置colorMode为ThemeColorMode.SYSTEM
        Column() {
          Text('WithTheme')
            .fontSize(40)
            .fontWeight(FontWeight.Bold)
          Text('DARK')
            .fontSize(40)
            .fontWeight(FontWeight.Bold)
        }
        .justifyContent(FlexAlign.Center)
        .width('100%')
        .height('33%')
        .backgroundColor($r('sys.color.background_primary'))
      }
    }
    .height('100%')
    .expandSafeArea([SafeAreaType.SYSTEM],
      [SafeAreaEdge.TOP, SafeAreaEdge.END, SafeAreaEdge.BOTTOM, SafeAreaEdge.START])
  }
}
```

## cl.arkui.3 ListItem组件创建行为变更
**访问级别**

公开接口

**变更原因**

如果ListItem组件不是通过LazyForEach和Repeat动态生成，创建ListItem时会执行两次ListItem的属性方法，需要优化为只执行一次属性方法以提升性能。

**变更影响**

此变更涉及应用适配，只涉及ListItem组件。

变更前：如果ListItem组件不是通过LazyForEach和Repeat动态生成，创建ListItem时会执行两次ListItem的属性方法。

变更后：ListItem在创建时只执行一次属性方法。

如下代码运行后，变更前会打印两次“GetWidth”，变更后只会打印一次“GetWidth”。

```ts
@Entry
@Component
struct ListItemExample {
  getWidth(): string {
    console.log("GetWidth");
    return "100%"
  }
  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ListItem() {
          Text('Item')
        }
        .width(this.getWidth())
      }.width('90%')
    }.width('100%').height('100%')
  }
}
```

**起始API Level**

API 7

**变更发生版本**
从OpenHarmony SDK 6.0.1.2开始。

**变更的接口/组件**

ListItem组件。

**适配指导**

需要排查ListItem属性方法中是否有调用函数获取属性值，排查函数调用次数是否对业务有影响，如果有影响需要根据实际业务场景适配。

## cl.arkui.4 FullScreenLaunchComponent嵌入式运行元服务内容区避让系统安全区行为变更
**访问级别**

公开接口

**变更原因**

通过FullScreenLaunchComponent拉起嵌入式运行元服务时，元服务的windowMode为undefined, 元服务的页面内容在任何场景下都不会避让系统安全区，嵌入式运行元服务和跳出式运行元服务页面默认避让行为不一致，需要元服务的开发者针对嵌入式场景主动做避让适配。

**变更影响**

此变更涉及应用适配。

说明：宿主是拉起方，即FullScreenLaunchComponent组件使用方，提供方是被嵌入式运行的元服务。

- 变更前：提供方的windowMode不跟随宿主，默认值为undefined，所有场景下，元服务的页面内容都不会默认避让系统安全区，需要提供方开发者主动避让。

- 变更后：提供方的windowMode跟随宿主保持一致，在宿主windowMode为全屏显示的场景下，并且提供方未主动设置页面为沉浸式，提供方页面会默认避让系统安全区，无需提供方开发者主动避让

|                   变更前                   |                 变更后                  |
| :----------------------------------------: | :-------------------------------------: |
| ![](figures/fullScreenLainchComponent/earlier_than_20.jpg) | ![](figures/fullScreenLainchComponent/api20.jpg) |

**起始API Level**

API 12

**变更发生版本**
从OpenHarmony SDK 6.0.1.2开始。

**变更的接口/组件**

FullScreenLaunchComponent组件及嵌入式拉起的元服务。

**适配指导**

- 宿主的targetsdkversion >= 20。
  - 建议宿主应用在6.0及以上版本使用嵌入式运行元服务，5.x版本建议使用跳出式运行元服务，提供方元服务无需在嵌入式场景主动避让适配。
  - 如果宿主应用需要在5.x使用嵌入式运行元服务，需要提供方元服务针对嵌入式场景做适配，需要判断提供方元服务的ohos.extra.atomicservice.param.key.isFollowHostWindowMode，如果ohos.extra.atomicservice.param.key.isFollowHostWindowMode为true,无需主动避让适配；否则需要主动避让适配。

- 宿主的targetsdkversion < 20。
  - 不建议宿主应用使用嵌入式运行元服务，建议使用跳出式运行元服务。
  - 如果宿主应用需要使用嵌入式运行元服务，提供方元服务需要判断ohos.extra.atomicservice.param.key.isFollowHostWindowMode，若ohos.extra.atomicservice.param.key.isFollowHostWindowMode为true,无需主动避让适配；否则需要主动避让适配。
```ts
export default class AtomicServiceAbility extends EmbeddableUIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    if (want.parameters) {
      hilog.info(0x0000, 'testTag', '%{public}s', 'followed host window mode' + want.parameters['ohos.extra.atomicservice.param.key.isFollowHostWindowMode']);
    }
  }
}
```