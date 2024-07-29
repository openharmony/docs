# Setting the Theme and Skin

## Overview

For applications, build ArkUI application-level and page-level theme setting capabilities, and provide functions such as partial light and dark mode settings, dynamic skin changing, etc.
This article provides the following scenarios:
- [Custom Brand Colors](#customizing-brand-colors)
- [Application-Level Custom Brand Colors](#setting-application-level-custom-brand-colors)
- [Partial Page Custom Theme Style](#setting-custom-theme-style-for-app-partial-pages)
- [Partial Light and Dark Colors](#setting-local-light-and-dark-modes-for-application-pages)


## Customizing Brand Colors
[CustomTheme](../reference/apis-arkui/js-apis-arkui-theme.md#customtheme) is used to customize themes. The properties are optional; only the parts that need to be modified need to be overwritten. Unmodified content inherits from the system, refer to [System Default Token Color Values](#System-Default-Token-Color-Values). Please refer to:

  ```ts
    import { CustomColors, CustomTheme } from '@kit.ArkUI'

    export class AppColors implements CustomColors {
      // Custom brand color
      brand: ResourceColor = '#FF75D9';
    }

    export class AppTheme implements CustomTheme {
      public colors: AppColors = new AppColors()
    }
    
    export let gAppTheme: CustomTheme = new AppTheme()
  ```

## Setting Application-Level Custom Brand Colors
- It can be uniformly set at the page entry point, and it needs to be executed before the page build [ThemeControl](../reference/apis-arkui/js-apis-arkui-theme.md#themecontrol).
  Among them, the [onWillApplyTheme](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#onwillapplytheme12) callback function is used for custom components to obtain the currently effective Theme object.

  ```ts
    import { Theme, ThemeControl } from '@kit.ArkUI'
    import { gAppTheme } from './AppTheme'
    
    // Execute ThemeControl before page build.
    ThemeControl.setDefaultTheme(gAppTheme)

    @Entry
    @Component
    struct DisplayPage {
      @State menuItemColor: ResourceColor = $r('sys.color.background_primary')
      
      onWillApplyTheme(theme: Theme) {
        this.menuItemColor = theme.colors.backgroundPrimary;
      }
    
      build() {
        Column() {
          List({ space: 10 }) {
            ListItem() {
              Column({ space: '5vp' }) {
                Text('Color mode')
                  .margin({ top: '5vp', left: '14fp' })
                  .width('100%')
                Row() {
                  Column() {
                    Text('Light')
                      .fontSize('16fp')
                      .textAlign(TextAlign.Start)
                      .alignSelf(ItemAlign.Center)
                    Radio({ group: 'light or dark', value: 'light' })
                      .checked(true)
                  }
                  .width('50%')

                  Column() {
                    Text('Dark')
                      .fontSize('16fp')
                      .textAlign(TextAlign.Start)
                      .alignSelf(ItemAlign.Center)
                    Radio({ group: 'light or dark', value: 'dark' })
                  }
                  .width('50%')
                }
              }
              .width('100%')
              .height('90vp')
              .borderRadius('10vp')
              .backgroundColor(this.menuItemColor)
            }

            ListItem() {
              Column() {
                Text('Brightness')
                  .width('100%')
                  .margin({ top: '5vp', left: '14fp' })
                Slider({ value: 40, max: 100 })
              }
              .width('100%')
              .height('70vp')
              .borderRadius('10vp')
              .backgroundColor(this.menuItemColor)
            }

            ListItem() {
              Column() {
                Row() {
                  Column({ space: '5vp' }) {
                    Text('Touch sensitivity')
                      .fontSize('16fp')
                      .textAlign(TextAlign.Start)
                      .width('100%')
                    Text('Increase the touch sensitivity of your screen' +
                      ' for use with screen protectors')
                      .fontSize('12fp')
                      .fontColor(Color.Blue)
                      .textAlign(TextAlign.Start)
                      .width('100%')
                  }
                  .alignSelf(ItemAlign.Center)
                  .margin({ left: '14fp' })
                  .width('75%')
    
                  Toggle({ type: ToggleType.Switch, isOn: true })
                    .margin({ right: '14fp' })
                    .alignSelf(ItemAlign.Center)
                    .width('25%')
                }
                .width('100%')
                .height('80vp')
              }
              .width('100%')
              .borderRadius('10vp')
              .backgroundColor(this.menuItemColor)
            }
          }
        }
        .padding('10vp')
        .backgroundColor('#dcdcdc')
        .width('100%')
        .height('100%')
      }
    }
  ```

- To set the [ThemeControl](../reference/apis-arkui/js-apis-arkui-theme.md#themecontrol) in Ability, you need to call [setDefaultTheme](../reference/apis-arkui/js-apis-arkui-theme.md#setdefaulttheme) within the onWindowStageCreate() method.

  ```ts
    import AbilityConstant from '@ohos.app.ability.AbilityConstant';
    import hilog from '@ohos.hilog';
    import UIAbility from '@ohos.app.ability.UIAbility';
    import Want from '@ohos.app.ability.Want';
    import window from '@ohos.window';
    import { CustomColors, ThemeControl } from '@kit.ArkUI';

    class AppColors implements CustomColors {
      fontPrimary = 0xFFD53032
      iconOnPrimary = 0xFFD53032
      iconFourth = 0xFFD53032
    }
    
    const abilityThemeColors = new AppColors();
    
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
          // Set default theme in the onWindowStageCreate() method
          ThemeControl.setDefaultTheme({ colors: abilityThemeColors })
          hilog.info(0x0000, 'testTag', '%{public}s', 'ThemeControl.setDefaultTheme done');
        });
      }
    
    }
  ```

![systemTheme](figures/systemTheme.png)

Note: If the parameter of setDefaultTheme is undefined, the default color values corresponding to the token value refer to [System Default Token Color Values](#system-default-token-color-values).

## Setting Custom Theme Style for App Partial Pages
Apply custom theme colors to the default styles of internal components by setting [WithTheme](../reference/apis-arkui/arkui-ts/ts-container-with-theme.md#withtheme). The colors of components within the scope of WithTheme follow the theme's color scheme.

In the following example, the color scheme of the components within the scope is set to a custom theme style by WithTheme({ theme: this.myTheme }). Subsequently, the theme style can be changed by modifying this.myTheme.

The [onWillApplyTheme](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#onwillapplytheme12) callback function is used for custom components to obtain the currently effective Theme object.


  ```ts
    import { CustomColors, CustomTheme, Theme } from '@kit.ArkUI'

    class AppColors implements CustomColors {
      fontPrimary: ResourceColor = $r('app.color.brand_purple')
      backgroundEmphasize: ResourceColor = $r('app.color.brand_purple')
    }
    
    class AppColorsSec implements CustomColors {
      fontPrimary: ResourceColor = $r('app.color.brand')
      backgroundEmphasize: ResourceColor = $r('app.color.brand')
    }
    
    class AppTheme implements CustomTheme {
      public colors: AppColors = new AppColors()
    }
    
    class AppThemeSec implements CustomTheme {
      public colors: AppColors = new AppColorsSec()
    }
    
    @Entry
    @Component
    struct DisplayPage {
      @State customTheme: CustomTheme = new AppTheme()
      @State message: string = 'Set custom theme style for partial pages'
      count = 0;
    
      build() {
        WithTheme({ theme: this.customTheme }) {
          Row(){
            Column() {
              Text('WithTheme')
                .fontSize(30)
                .margin({bottom: 10})
              Text(this.message)
                .margin({bottom: 10})
              Button('Change Theme').onClick(() => {
                this.count++;
                if (this.count > 1) {
                  this.count = 0;
                }
                switch (this.count) {
                  case 0:
                    this.customTheme = new AppTheme();
                    break;
                  case 1:
                    this.customTheme = new AppThemeSec();
                    break;
                }
              })
            }
            .width('100%')
          }
          .height('100%')
          .width('100%')
        }
      }
    }
  ```

![customTheme](figures/customTheme.gif)

## Setting Local Light and Dark Modes for Application Pages

The [WithTheme](../reference/apis-arkui/arkui-ts/ts-container-with-theme.md#withtheme) utility can be used to set light and dark color modes. The [ThemeColorMode](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#themecolormode10) has three modes: ThemeColorMode.SYSTEM, which follows the system's color scheme; ThemeColorMode.LIGHT, which indicates a light color scheme; and ThemeColorMode.DARK, which indicates a dark color scheme.</br>
Within the scope of WithTheme, the style resource values of components follow the specified mode to read the corresponding light or dark color system and application resource values. The color scheme of components within the WithTheme scope takes effect according to the specified light or dark mode.</br>
In the following example, components within the scope are set to dark mode using WithTheme({ colorMode: ThemeColorMode.DARK }).

When setting local light and dark modes, you need to add a "dark" directory under the resources folder and include a dark.json resource file in the dark directory for the color scheme to take effect.


  ```ts
    @Entry
    @Component
    struct DisplayPage {
      @State message: string = 'Hello World';
      @State colorMode: ThemeColorMode = ThemeColorMode.DARK;

      build() {
        WithTheme({ colorMode: this.colorMode }) {
          Row() {
            Column() {
              Text(this.message)
                .fontSize(50)
                .fontWeight(FontWeight.Bold)
              Button('Switch ColorMode').onClick(() => {
                if (this.colorMode === ThemeColorMode.LIGHT) {
                  this.colorMode = ThemeColorMode.DARK;
                } else if (this.colorMode === ThemeColorMode.DARK) {
                  this.colorMode = ThemeColorMode.LIGHT;
                }
              })
            }
            .width('100%')
          }
          .backgroundColor($r('sys.color.background_primary'))
          .height('100%')
          .expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.END, SafeAreaEdge.BOTTOM, SafeAreaEdge.START])
        }
      }
    }
  ```

![lightDarkMode](figures/lightDarkMode.png)

## System Default Token Color Values

| Token                                      | Category       | Light        |                                 | Dark          |                                              |
|--------------------------------------------|----------------|--------------|-----------------------------|---------------|---------------------------------------------|
| theme.colors.brand                         | Brand Color    | #ff0a59f7     | ![](figures/ff0a59f7.png "#ff0a59f7") | #ff317af7     | ![](figures/ff317af7.png "#ff317af7")    |
| theme.colors.warning                       | Primary Warning | #ffe84026    | ![](figures/ffe84026.png "#ffe84026") | #ffd94838     | ![](figures/ffd94838.png "#ffd94838")    |
| theme.colors.alert                         | Secondary Alert | #ffed6f21    | ![](figures/ffed6f21.png "#ffed6f21") | #ffdb6b42     | ![](figures/ffdb6b42.png "#ffdb6b42")    |
| theme.colors.confirm                       | Confirmation   | #ff64bb5c    | ![](figures/ff64bb5c.png "#ff64bb5c") | #ff5ba854     | ![](figures/ff5ba854.png "#ff5ba854")    |
| theme.colors.fontPrimary                   | Primary Text   | #e5000000    | ![](figures/e5000000.png "#e5000000") | #e5ffffff     | ![](figures/e5ffffff.png "#e5ffffff")   |
| theme.colors.fontSecondary                 | Secondary Text | #99000000    | ![](figures/99000000.png "#99000000") | #99ffffff     | ![](figures/99ffffff.png "#99ffffff")   |
| theme.colors.fontTertiary                  | Tertiary Text  | #66000000    | ![](figures/66000000.png "#66000000") | #66ffffff     | ![](figures/66ffffff.png "#66ffffff")   |
| theme.colors.fontFourth                    | Quaternary Text| #33000000    | ![](figures/33000000.png "#33000000") | #33ffffff     | ![](figures/33ffffff.png "#33ffffff")   |
| theme.colors.fontEmphasize                 | Highlight Text | #ff0a59f7    | ![](figures/ff0a59f7.png "#ff0a59f7") | #ff317af7     | ![](figures/ff317af7.png "#ff317af7")    |
| theme.colors.fontOnPrimary                 | Primary Inverse Text | #ffffffff | ![](figures/ffffffff.png "#ffffffff") | #ff000000     | ![](figures/ff000000.png "#ff000000")   |
| theme.colors.fontOnSecondary               | Secondary Inverse Text | #99ffffff | ![](figures/99ffffff.png "#99ffffff") | #99000000     | ![](figures/99000000.png "#99000000")   |
| theme.colors.fontOnTertiary                | Tertiary Inverse Text | #66ffffff | ![](figures/66ffffff.png "#66ffffff") | #66000000     | ![](figures/66000000.png "#66000000")   |
| theme.colors.fontOnFourth                  | Quaternary Inverse Text | #33ffffff | ![](figures/33ffffff.png "#33ffffff") | #33000000     | ![](figures/33000000.png "#33000000")   |
| theme.colors.iconPrimary                   | Primary Icon   | #e5000000    | ![](figures/e5000000.png "#e5000000") | #e5ffffff     | ![](figures/e5ffffff.png "#e5ffffff")   |
| theme.colors.iconSecondary                 | Secondary Icon | #99000000    | ![](figures/99000000.png "#99000000") | #99ffffff     | ![](figures/99ffffff.png "#99ffffff")   |
| theme.colors.iconTertiary                  | Tertiary Icon  | #66000000    | ![](figures/66000000.png "#66000000") | #66ffffff     | ![](figures/66ffffff.png "#66ffffff")   |
| theme.colors.iconFourth                    | Quaternary Icon| #33000000    | ![](figures/33000000.png "#33000000") | #33ffffff     | ![](figures/33ffffff.png "#33ffffff")   |
| theme.colors.iconEmphasize                 | Highlight Icon | #ff0a59f7    | ![](figures/ff0a59f7.png "#ff0a59f7") | #ff317af7     | ![](figures/ff317af7.png "#ff317af7")    |
| theme.colors.iconSubEmphasize              | Subtle Highlight Icon | #660a59f7 | ![](figures/660a59f7.png "#660a59f7") | #66317af7     | ![](figures/66317af7.png "#66317af7")    |
| theme.colors.iconOnPrimary                 | Primary Inverse Icon | #ffffffff | ![](figures/ffffffff.png "#ffffffff") | #ff000000     | ![](figures/ff000000.png "#ff000000")   |
| theme.colors.iconOnSecondary               | Secondary Inverse Icon | #99ffffff | ![](figures/99ffffff.png "#99ffffff") | #99000000     | ![](figures/99000000.png "#99000000")   |
| theme.colors.iconOnTertiary                | Tertiary Inverse Icon | #66ffffff | ![](figures/66ffffff.png "#66ffffff") | #66000000     | ![](figures/66000000.png "#66000000")   |
| theme.colors.iconOnFourth                  | Quaternary Inverse Icon | #33ffffff | ![](figures/33ffffff.png "#33ffffff") | #33000000     | ![](figures/33000000.png "#33000000")   |
| theme.colors.backgroundPrimary             | Primary Background (Solid/Opaque) | #ffffffff | ![](figures/ffffffff.png "#ffffffff") | #ffe5e5e5     | ![](figures/ffe5e5e5.png "#ffe5e5e5")    |
| theme.colors.backgroundSecondary           | Secondary Background (Solid/Opaque) | #fff1f3f5 | ![](figures/fff1f3f5.png "#fff1f3f5") | #ff191a1c     | ![](figures/ff191a1c.png "#ff191a1c")    |
| theme.colors.backgroundTertiary            | Tertiary Background (Solid/Opaque) | #ffe5e5ea    | ![](figures/ffe5e5ea.png "#ffe5e5ea") | #ff202224     | ![](figures/ff202224.png "#ff202224")   |
| theme.colors.backgroundFourth              | Quaternary Background (Solid/Opaque) | #ffd1d1d6    | ![](figures/ffd1d1d6.png "#ffd1d1d6") | #ff2e3033     | ![](figures/ff2e3033.png "#ff2e3033")   |
| theme.colors.backgroundEmphasize           | Highlight Background (Solid/Opaque) | #ff0a59f7    | ![](figures/ff0a59f7.png "#ff0a59f7") | #ff317af7     | ![](figures/ff317af7.png "#ff317af7")    |
| theme.colors.compForegroundPrimary         | Foreground | #ff000000    | ![](figures/ff000000.png "#ff000000") | #ffe5e5e5     | ![](figures/ffe5e5e5.png "#ffe5e5e5")   |
| theme.colors.compBackgroundPrimary         | White Background | #ffffffff    |![](figures/ffffffff.png "#ffffffff")| #ffffffff     |![](figures/ffffffff.png "#ffffffff")  |
| theme.colors.compBackgroundPrimaryTran     | White Transparent Background | #ffffffff    |![](figures/ffffffff.png "#ffffffff")| #33ffffff     |![](figures/33ffffff.png "#33ffffff")   |
| theme.colors.compBackgroundPrimaryContrary | Contrary Background | #ffffffff    |![](figures/ffffffff.png "#ffffffff")| #ffe5e5e5     |
| theme.colors.compBackgroundGray            | Gray Background | #fff1f3f5 |![](figures/fff1f3f5.png "#fff1f3f5")| #ffe5e5ea |![](figures/ffe5e5ea.png "#ffe5e5ea")|
| theme.colors.compBackgroundSecondary       | Secondary Background | #19000000 |![](figures/19000000.png "#19000000")| #19ffffff |![](figures/19ffffff.png "#19ffffff")|
| theme.colors.compBackgroundTertiary        | Tertiary Background | #0c000000 |![](figures/0c000000.png "#0c000000")| #0cffffff |![](figures/0cffffff.png "#0cffffff")|
| theme.colors.compBackgroundEmphasize       | Emphasized Background | #ff0a59f7 |![](figures/ff0a59f7.png "#ff0a59f7")| #ff317af7 |![](figures/ff317af7.png "#ff317af7")|
| theme.colors.compBackgroundNeutral         | Black Neutral Emphasized Background | #ff000000 |![](figures/ff000000.png "#ff000000")| #ffffffff |![](figures/ffffffff.png "#ffffffff")|
| theme.colors.compEmphasizeSecondary        | 20% Emphasized Background | #330a59f7 |![](figures/330a59f7.png "#330a59f7")| #33317af7 |![](figures/33317af7.png "#33317af7")|
| theme.colors.compEmphasizeTertiary         | 10% Emphasized Background | #190a59f7 |![](figures/190a59f7.png "#190a59f7")| #19317af7 |![](figures/19317af7.png "#19317af7")|
| theme.colors.compDivider                   | Divider Color | #33000000 |![](figures/33000000.png "#33000000")| #33ffffff |![](figures/33ffffff.png "#33ffffff")|
| theme.colors.compCommonContrary            | Common Contrast | #ffffffff |![](figures/ffffffff.png "#ffffffff")| #ff000000 |![](figures/ff000000.png "#ff000000")|
| theme.colors.compBackgroundFocus           | Focused State Background Color | #fff1f3f5 |![](figures/fff1f3f5.png "#fff1f3f5")| #ff000000 |![](figures/fff1f3f5.png "#fff1f3f5")|
| theme.colors.compFocusedPrimary            | Focused State Primary Contrast | #e5000000 |![](figures/e5000000.png "#e5000000")| #e5ffffff |![](figures/e5ffffff.png "#e5ffffff")|
| theme.colors.compFocusedSecondary          | Focused State Secondary Contrast | #99000000 |![](figures/99000000.png "#99000000")| #99ffffff |![](figures/99ffffff.png "#99ffffff")|
| theme.colors.compFocusedTertiary           | Focused State Tertiary Contrast | #66000000 |![](figures/66000000.png "#66000000")| #66ffffff |![](figures/66ffffff.png "#66ffffff")|
| theme.colors.interactiveHover              | General Hover Interactive Color | #0c000000 |![](figures/0c000000.png "#0c000000")| #0cffffff |![](figures/0cffffff.png "#0cffffff")|
| theme.colors.interactivePressed            | General Pressed Interactive Color | #19000000 |![](figures/19000000.png "#19000000")| #19ffffff |![](figures/19ffffff.png "#19ffffff")|
| theme.colors.interactiveFocus              | General Focus Interactive Color | #ff0a59f7 |![](figures/ff0a59f7.png "#ff0a59f7")| #ff317af7 |![](figures/ff317af7.png "#ff317af7")|
| theme.colors.interactiveActive             | General Active Interactive Color | #ff0a59f7 |![](figures/ff0a59f7.png "#ff0a59f7")| #ff317af7 |![](figures/ff317af7.png "#ff317af7")|
| theme.colors.interactiveSelect             | General Selection Interactive Color | #33000000 |![](figures/33000000.png "#33000000")| #33ffffff |![](figures/33ffffff.png "#33ffffff")|
| theme.colors.interactiveClick              | General Click Interactive Color | #19000000 |![](figures/19000000.png "#19000000")| #19ffffff |![](figures/19ffffff.png "#19ffffff")|
