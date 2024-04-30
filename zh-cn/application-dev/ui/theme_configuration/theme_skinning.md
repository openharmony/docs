# 设置主题换肤

### 概述

为了给用户更好的体验，系统应用和生态应用会定义几套主题，支持应用及自定义换肤，包含应用级换肤、局部强制深浅色和局部换肤，支持动态换肤。当主题切换的时候同步更换样式，资源文件等。

### 主题色主要场景

- 应用：应用品牌色、应用级深浅色和局部换肤，支持动态换肤。
- 主题：官方预置主题色、个性化和在线主题色。
- 产品组件预置：产品品牌色。

### 示例代码

- 自定义Theme：CustomTheme接口用于自定义Theme。CustomTheme的属性是可选的，只需要复写需要的修改的部分，其余部分会继承自系统。

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

- 应用级换肤: 通过上面自定义Theme示例代码设置应用级自定义Theme的配色风格，通过ThemeControl将自定义Theme的配色作用于应用内组件缺省样式，APP应用内组件配色跟随Theme的配色生效。
在下面的示例中，willApplyTheme回调函数用于自定义组件获取当前生效的Theme对象。

    ```ts
    // xxx.ets
    import { Theme, ThemeControl, CustomTheme } from '@ohos.arkui.theme';
    import { gAppTheme } from '../Theme/AppTheme'
      
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
  
- WithTheme局部换肤：将自定义Theme的配色通过设置WithTheme作用于内组件缺省样式，WithTheme作用域内组件配色跟随Theme的配色生效。
在下面示例中，通过WithTheme({ theme: this.redCustomTheme })将作用域内的组件配色设置为自定义redCustomTheme的配色。

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
  
- WithTheme深浅色模式:通过WithTheme可以设置深浅色模式，ThemeColorMode.SYSTEM模式表示跟随系统模式，ThemeColorMode.LIGHT模式表示浅色模式，ThemeColorMode.DARK模式表示深色模式。
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
  

