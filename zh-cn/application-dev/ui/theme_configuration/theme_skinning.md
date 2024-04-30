# 设置主题换肤

### 概述

针对应用需要设置自己的品牌色和主题风格，需要在局部页面使用自己的主题风格，并且在局部设置深浅色的三种场景需求，设计了Theme主题换肤方案，开发指导如下：


### 自定义品牌色
CustomTheme接口用于自定义Theme。CustomTheme的属性是可选的，只需要复写需要的修改的部分，其余部分会继承自系统。详情参考：
>UX鸿蒙色彩设计原色介绍

  ```ts
    // xxx.ets
    import { CustomTheme, CustomColors } from '@ohos.arkui.theme'

    class AppColors implements CustomColors {
      //Button字体
      fontOnPrimary: ResourceColor = '#ff0c0b0b';
      //Button背景颜色
      backgroundEmphasize: ResourceColor = '#ffebecee';
    }

    export class AppTheme implements CustomTheme {
      colors = new AppColors()
    }

    export let gAppTheme: CustomTheme = new AppTheme()
  ```

### 设置应用级全局风格
- 方法一：在ability中设置ThemeControl
- 约束：如果在ability中设置，需要在onWindowStageCreate()方法中setDefaultTheme。


| 接口名          | 方法/属性名                                    | 是否必填 | 描述（说明默认值）                                                       | 所属文件                   |
|--------------|-------------------------------------------|------|-----------------------------------------------------------------|------------------------|
| ThemeControl | setDefaultTheme(theme: CustomTheme): void | 是    | 将自定义Theme应用于APP组件，实现APP组件风格跟随Theme切换。Theme后续可扩展shape, typograph | @ohos.arkui.theme.d.ts |

参考示例：

  ```ts
    xxx.ts
    import AbilityConstant from '@ohos.app.ability.AbilityConstant';
    import hilog from '@ohos.hilog';
    import UIAbility from '@ohos.app.ability.UIAbility';
    import Want from '@ohos.app.ability.Want';
    import window from '@ohos.window';
    import { CustomColors, ThemeControl } from '@ohos.arkui.theme'
    
    class RedColors implements CustomColors {
      fontEmphasize = 0xFFD53032
      iconEmphasize = 0xFFD53032
      backgroundEmphasize = 0xFFD53032
    }
    const abilityThemeColors = new RedColors();
    // the invoking here does not have effect
    // ThemeControl.setDefaultTheme({ colors: abilityThemeColors })
    
    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
      }
    
      onDestroy() {
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
      }
    
      onWindowStageCreate(windowStage: window.WindowStage) {
        // Main window is created, set main page for this ability
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
      
        windowStage.loadContent('pages/Index', (err, data) => {
          if (err.code) {
            hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
            return;
          }
          hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
          // invoking here works good
          ThemeControl.setDefaultTheme({ colors: abilityThemeColors })
          hilog.info(0x0000, 'testTag', '%{public}s', 'ThemeControl.setDefaultTheme done');
        });
      }
    
      onWindowStageDestroy() {
        // Main window is destroyed, release UI related resources
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
      }
    
      onForeground() {
        // Ability has brought to foreground
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
      }
    
      onBackground() {
        // Ability has back to background
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
      }
    }
  ```
- 方法二：在页面入口处统一设置
- 约束：要在页面build前执行ThemeControl。

在下面的示例中，willApplyTheme回调函数用于自定义组件获取当前生效的Theme对象。

| 组件名             | 方法/属性名                              | 是否必填 | 描述（说明默认值） | 所属文件        |
|-----------------|-------------------------------------|------|-----------|-------------|
| CustomComponent | willApplyTheme?(theme: Theme): void | 是    | 回调函数用于自定义组件获取当前生效的Theme对象      | common.d.ts |


参考示例：

  ```ts
    // xxx.ets
    import { Theme, ThemeControl, CustomTheme } from '@ohos.arkui.theme';
    import { gAppTheme } from '../Theme/AppTheme'
    
    //在页面build前执行ThemeControl
    ThemeControl.setDefaultTheme(gAppTheme)
      
    @Entry
    @Component
    struct WillApplyThemePage {
      @State textSize: Length = 0
      @State textWeight: FontWeight | number | string = 0
      @State textPadding: Length = 0
      @State textCorners: Length = 0
      @State textColor: ResourceColor = Color.Transparent
      @State textBackgroundColor: ResourceColor = Color.Transparent
      @State textPressBackgroundColor: ResourceColor = Color.Transparent
        
      @Styles
      normalStyles() {
        .backgroundColor(this.textBackgroundColor)
      }
        
      @Styles
      pressedStyles() {
        .backgroundColor(this.textPressBackgroundColor)
      }
        
      willApplyTheme(theme: Theme) {
        this.textColor = theme.colors.fontOnPrimary
        this.textBackgroundColor = theme.colors.backgroundEmphasize
        this.textPressBackgroundColor = theme.colors.interactivePressed
      }
        
      build() {
        Column() {
          Row() {
            Text('Hello World')
              .fontSize(this.textSize)
              .fontWeight(this.textWeight)
              .padding(this.textPadding)
              .borderRadius(this.textCorners)
              .fontColor(this.textColor)
              .stateStyles({
                normal: this.normalStyles,
                pressed: this.pressedStyles,
              })
          }
          .alignItems(VerticalAlign.Center)
          .justifyContent(FlexAlign.Center)
          .width('100%')
          .flexGrow(1)
        }
        .height('100%')
      }
    }
  ```

### 设置应用页面局部换肤  
- 将自定义Theme的配色通过设置WithTheme作用于内组件缺省样式，WithTheme作用域内组件配色跟随Theme的配色生效。
在下面示例中，通过WithTheme({ theme: this.redCustomTheme })将作用域内的组件配色设置为自定义redCustomTheme的配色。


| 组件名                                  | 方法/属性名                                                                                      | 是否必填 | 描述（说明默认值）                          | 所属文件            |
|--------------------------------------|---------------------------------------------------------------------------------------------|------|------------------------------------|-----------------|
| WithTheme(options: WithThemeOptions) | WithThemeOptions? {<br/>theme?: CustomTheme // 自定义Theme<br/>colorMode?: ColorMode // 深浅色模式<br/>} | 是    | WithThemeOptions为自定义Theme或指定的深浅色模式 | with_theme.d.ts |


  ```ts
    // xxx.ets
    import { CustomTheme } from '@ohos.arkui.theme'
    import { BrownThemeColors, GreenThemeColors, RedThemeColors } from '../theme/CustomColorsImlp'
    import { CustomThemeImpl } from '../theme/CustomThemeImpl'
    
    @Entry
    @Component
    struct CustomThemePage {
      redCustomTheme: CustomTheme = new CustomThemeImpl(RedThemeColors)
      greenCustomTheme: CustomTheme = new CustomThemeImpl(GreenThemeColors)
      brownCustomTheme: CustomTheme = new CustomThemeImpl(BrownThemeColors)
      
      build() {
        Row() {
          Scroll() {
            Column({ space: '8vp' }) {
              Button('System Theme')
  
              WithTheme({ theme: this.redCustomTheme }) {
                Column({ space: '8vp' }) {
                  Button('Red Theme')
                  WithTheme({ theme: this.greenCustomTheme }) {
                    Column({ space: '8vp' }) {
                      Button('Green Theme')
                    }
                  }
                  Button('Red Theme')
                }
              }
              Button('System Theme')
              WithTheme({ theme: this.brownCustomTheme }) {
                Button('Brown Theme')
              }
              Button('System Theme')
            }
            .padding('10vp')
            .width('100%')
          }.height('100%')
        }
        .height('100%')
      }
    }
  ```

### 设置应用页面局部深浅色
- 通过WithTheme可以设置深浅色模式，ThemeColorMode.SYSTEM模式表示跟随系统模式，ThemeColorMode.LIGHT模式表示浅色模式，ThemeColorMode.DARK模式表示深色模式。
在WithTheme作用域内，组件的样式资源取值跟随指定的模式读取对应的深浅色模式系统和应用资源值，WithTheme作用域内的组件配色跟随指定的深浅模式生效。
在下面的示例中，通过WithTheme({ colorMode: ThemeColorMode.LIGHT })将组件设置为浅色模式。

  ```ts
    // xxx.ets
    @Entry
    @Component
    struct DarkLightTheme {
      @State message: string = 'Hello World';

      build() {
        Row() {
          Column() {
            WithTheme({ colorMode: ThemeColorMode.LIGHT }) {
              Text(this.message)
                .fontSize(50)
                .fontWeight(FontWeight.Bold)
            }
          }
          .width('100%')
        }
        .height('100%')
      }
    }
  ```
  

