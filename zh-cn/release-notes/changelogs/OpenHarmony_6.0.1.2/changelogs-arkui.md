# ArkUI子系统Changelog

## cl.arkui.1 通用属性drawModifier接口变更

**访问级别**

公开接口

**变更原因**

当drawModifier接口参数从DrawModifier对象变为undefined时，实际生效的仍是原来的DrawModifier对象。开发者无法重置其值，这与通用属性接口的规范不符。

**变更影响**

此变更涉及应用适配。

- 变更前： drawModifier接口参数从DrawModifier对象变为undefined后，生效的仍旧是原来的DrawModifier对象。
  
- 变更后：drawModifier接口参数从DrawModifier对象变为undefined后，会将原来设置的值重置为undefined。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 6.0.1.2开始。

**适配指导**

变更前，this.modifier = undefined;不会清除组件上生效的DrawModifier对象，而变更后则会完成清除。因此，若想保持行为不变，需要注释或删除这一行代码。

```ts
import { drawing } from '@kit.ArkGraphics2D';

class MyFrontDrawModifier extends DrawModifier {
  public scaleX: number = 1;
  public scaleY: number = 1;

  drawFront(context: DrawContext): void {
    const brush = new drawing.Brush();
    brush.setColor({
      alpha: 255,
      red: 0,
      green: 0,
      blue: 255
    });
    context.canvas.attachBrush(brush);
    const halfWidth = context.size.width / 2;
    const halfHeight = context.size.width / 2;
    const radiusScale = (this.scaleX + this.scaleY) / 2;
    context.canvas.drawCircle(vp2px(halfWidth), vp2px(halfHeight), vp2px(20 * radiusScale));
  }
}

@Entry
@Component
struct DrawModifierExample {
  @State modifier: DrawModifier | undefined = new MyFrontDrawModifier();

  build() {
    Column() {
      Button("清除modifier").onClick(() => {
        // 变更前：下面代码不生效，Text组件仍旧绑定原本的modifier
        this.modifier = undefined;
        // 规避方法：变更前若想清空Text组件的自定义绘制效果，可将其绑定的变量变为基类对象
        this.modifier = new DrawModifier();
        // 变更后：若开发者期望行为和变更前保持一致，即下面代码不生效的话，只需要注释掉这一行即可
        // this.modifier = undefined;
      })
      Row() {
        Text()
          .width(100)
          .height(100)
          .margin(10)
          .backgroundColor(Color.Gray)
          .drawModifier(this.modifier)
      }
    }
  }
}
```

## cl.arkui.2 默认深浅色切换流程变更

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

## cl.arkui.3 drawModifier接口通过取消多余重绘达实现性能优化

**访问级别**

公开

**变更原因**

当前实现中，若组件设置了drawModifier属性，则默认会在生命周期的布局阶段之后触发重绘。对于绘制内容和尺寸均未发生变化的场景，这将导致多余的重绘，造成性能损耗。因此，调整设置drawModifier的节点的重绘规则，默认仅执行过测量过程的节点才进行重绘。

**变更影响**

此变更涉及应用适配

- 变更前：任何组件，只要设置了drawModifier属性，即使跳过测量，也会触发重绘
  
- 变更后：若容器组件设置了drawModifier属性，则当其跳过测量时，不执行重绘。其他组件的重绘触发机制与是否使用drawModifier属性无关。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 6.0.1.2开始。

**变更的接口/组件**

 drawModifier

**适配指导**

若开发者的自定义绘制内容变化逻辑受到本次变更影响，在受影响属性变化的代码后加入invalidate以主动触发重绘，即可完成适配。具体适配方案可参考下文示例。

```ts
// index.ets
import { drawing } from '@kit.ArkGraphics2D';

class MyFontDrawModifier extends DrawModifier {
  public scaleX: number = 1;
  public scaleY: number = 1;

  drawFront(context: DrawContext): void {
    const brush = new drawing.Brush();
    brush.setColor({
      alpha: 255,
      red: 0,
      green: 0,
      blue: 255
    });
    context.canvas.attachBrush(brush);
    const halfWidth = context.size.width / 2;
    const halfHeight = context.size.width / 2;
    const radiusScale = (this.scaleX + this.scaleY) / 2;
    context.canvas.drawCircle(vp2px(halfWidth), vp2px(halfHeight), vp2px(20 * radiusScale));
  }
}

@Entry
@Component
struct DrawModifierExample {
  private fontModifier: MyFontDrawModifier = new MyFontDrawModifier();
  @State testWidth: number = 100;

  build() {
    Column() {
      Button('changeModifier')
        .onClick(() => {
          this.testWidth++;
          this.fontModifier.scaleX += 0.1;
          this.fontModifier.scaleY += 0.1;
          // 适配手动调用invalidate方法
          this.fontModifier.invalidate();
        })
      Column() {
        Row()
          .width(50)
          .height(50)
          .drawModifier(this.fontModifier)
        Row() {
          Text("hello word")
            .width(this.testWidth)
            .height(100)
        }
      }
      .width(100)
      .height(100)
    }
  }
}
```

## cl.arkui.4 WithTheme组件设置colorMode后效果异常问题修复

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

## cl.arkui.5 ListItem组件创建行为变更
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
