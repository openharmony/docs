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

2、在需要适配的地方通过[AppStorage能力](../../../application-dev/quick-start/arkts-appstorage.md)进行适配。

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


