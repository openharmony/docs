# Supporting Aging-Friendly Design
<!--RP1-->

## Basic Concepts

Aging-friendly design offers a method to enlarge selected areas or components through a long-press action with a mouse or finger. Specifically, when the system font is larger than 1x, this action on a component with aging-friendly features extracts data from the component within the selected area and presents it in a dialog box. This way, both the component and its internal data (child components) are enlarged, and the entire component is centered on the screen for better visibility.

## Constraints

* Aging-friendly rules

  To ensure that components enlarge appropriately when the system font size is greater than 1x, you need to configure the [configuration tag](../quick-start/app-configuration-file.md#configuration) for implementing an aging-friendly feature.

* Aging-friendly operations

  Long-pressing a component that supports aging-friendly capabilities triggers a dialog box. The aging-friendly operation ends when the user releases the press. When the system font size is set to be greater than 1x, the component automatically enlarges, and when the system font size returns to 1x, the component returns to its normal state.

* Aging-friendly objects

  The components that trigger the aging-friendly operation and provide the data.

* Aging-friendly dialog box targets

  The components capable of receiving and processing the aging-friendly data.

* Dialog box restrictions

  When users set the system font to more than 2x, the dialog box content, including icons and text, is magnified at a fixed 2x scale.

* Combination with other capabilities

  Aging-friendly capabilities can be integrated with other features (such as swipe and drag). When the bottom tab bar (**tabBar**) component is activated for aging-friendly features, users can swipe their fingers or use a mouse to trigger aging-friendly features for other child components within the tab bar.

## Aging-Friendly Component Adaptation and Activation Methods

| Activation Method            | Component                                                    |
| -------------------- | ------------------------------------------------------------ |
| Long press on the component        | [SideBarContainer](../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md), [Bottom Tab Bar (tabBar)](../reference/apis-arkui/arkui-ts/ts-container-tabcontent.md#tabbar9), [Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md), [NavDestination](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10), [Tabs](../reference/apis-arkui/arkui-ts/ts-container-tabs.md)|
| Default system font enlargement| [PickerDialog](../reference/apis-arkui/arkui-ts/ts-methods-calendarpicker-dialog.md), [Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md), [Menu](../reference/apis-arkui/arkui-ts/ts-basic-components-menu.md), [Stepper](../reference/apis-arkui/arkui-ts/ts-basic-components-stepper.md), [BindSheet](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet), [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md), [TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md), [Search](../reference/apis-arkui/arkui-ts/ts-basic-components-search.md), [SelectionMenu](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-SelectionMenu.md), [Chip](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Chip.md#chip), [Dialog](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Dialog.md), [Slider](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md), [Progress](../reference/apis-arkui/arkui-ts/ts-basic-components-progress.md), [Badge](../reference/apis-arkui/arkui-ts/ts-container-badge.md)|

## Example

This example uses the **SideBarContainer** component to trigger an aging-friendly dialog box through a long press of the control button. Note that the dialog box does not appear if the system font size is at the 1x setting. Instead, it appears only when the system font size is set to greater than 1x.

```ts
import { abilityManager, Configuration } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct SideBarContainerExample {
  @State currentFontSizeScale: number = 1
  normalIcon: Resource = $r("app.media.icon") // Example icon. Replace it with the actual image.
  selectedIcon: Resource = $r("app.media.icon") // Example icon. Replace it with the actual image.
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1
  @State title: string = 'Index01';
  // Set the font scale.
  async setFontScale(scale: number): Promise<void> {
    let configInit: Configuration = {
      language: 'zh-Ch',
      fontSizeScale: scale,
    };
    // Update the font size.
    abilityManager.updateConfiguration(configInit, (err: BusinessError) => {
      if (err) {
        console.error(`updateConfiguration fail, err: ${JSON.stringify(err)}`);
      } else {
        this.currentFontSizeScale = scale;
        console.log('updateConfiguration success.');
      }
    });
  }

  build() {
    SideBarContainer(SideBarContainerType.Embed) {
      Column() {
        ForEach(this.arr, (item: number) => {
          Column({ space: 5 }) {
            Image(this.current === item ? this.selectedIcon : this.normalIcon).width(64).height(64)
            Text("0" + item)
              .fontSize(25)
              .fontColor(this.current === item ? '#0A59F7' : '#999')
              .fontFamily('source-sans-pro,cursive,sans-serif')
          }
          .onClick(() => {
            this.current = item;
            this.title = "Index0" + item;
          })
        }, (item: string) => item)
      }.width('100%')
      .justifyContent(FlexAlign.SpaceEvenly)
      .backgroundColor($r('sys.color.mask_fifth'))

      Column() {
        Text(this.title)
        Button('1x').onClick(() => {
          this.setFontScale(1)
        }).margin(10)
        Button('1.75x').onClick(() => {
          this.setFontScale(1.75)
        }).margin(10)
        Button('2x').onClick(() => {
          this.setFontScale(2)
        }).margin(10)
        Button('3.2x').onClick(() => {
          this.setFontScale(3.2)
        }).margin(10)
      }
      .margin({ top: 50, left: 20, right: 30 })
    }
    .controlButton({
      icons: {
        hidden: $r('sys.media.ohos_ic_public_drawer_open_filled'),
        shown: $r('sys.media.ohos_ic_public_drawer_close')
      }
    })
    .sideBarWidth(150)
    .minSideBarWidth(50)
    .maxSideBarWidth(300)
    .minContentWidth(0)
    .onChange((value: boolean) => {
      console.info('status:' + value)
    })
    .divider({ strokeWidth: '1vp', color: Color.Gray, startMargin: '4vp', endMargin: '4vp' })
  }
}
```

Switching system font sizes and long-pressing components with aging-friendly capabilities yields the effects as follows.

| System Font at 1x (Before Aging-Friendly Features Are Enabled)| System Font at 1.75x (After Aging-Friendly Features Are Enabled)|
| ---------------------------------- | ------------------------------------ |
| ![](figures/aging_01.png)          | ![](figures/aging_02.png)            |

The [TextPickerDialog](../reference/apis-arkui/arkui-ts/ts-methods-textpicker-dialog.md) component triggers an aging-friendly dialog box when the system font is set to greater than 1x, which does not occur at the default 1x setting.

```ts
import { abilityManager, Configuration } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct TextPickerExample {
  private select: number | number[] = 0;
  private cascade: TextCascadePickerRangeContent[] = [
    {
      text: 'Category 1',
      children: [{ text: 'Subcategory 1', children: [{ text: 'Subcategory 2' }, { text: 'Subcategory 3' }, { text: 'Subcategory 4' }] },
        { text: 'Item 1', children: [{ text: 'Item 2' }, { text: 'Item 3' }, { text: 'Item 4' }] }]
    },
    {
      text: 'Category 2',
      children: [{ text: 'Subcategory 1', children: [{ text: 'Subcategory 2' }, { text: 'Subcategory 3' }, { text: 'Subcategory 4' }] },
        { text: 'Item 1', children: [{ text: 'Item 2' }, { text: 'Item 3' }, { text: 'Item 4' }] }]
    },
    {
      text: 'Category 3',
      children: [{ text: 'Subcategory 1', children: [{ text: 'Subcategory 2' }, { text: 'Subcategory 3' }, { text: 'Subcategory 4' }] },
        { text: 'Item 1', children: [{ text: 'Item 2' }, { text: 'Item 3' }, { text: 'Item 4' }] }]
    }
  ]
  @State v: string = '';
  @State showTriggered: string = '';
  private triggered: string = '';
  private maxLines: number = 3;
  // Set the font scale.
  async setFontScale(scale: number): Promise<void> {
    let configInit: Configuration = {
      fontSizeScale: scale,
    };

    abilityManager.updateConfiguration(configInit, (err: BusinessError) => {
      if (err) {
        console.error(`updateConfiguration fail, err: ${JSON.stringify(err)}`);
      } else {
        console.log('updateConfiguration success.');
      }
    });
  }

  linesNum(max: number): void {
    let items: string[] = this.triggered.split('\n').filter(item => item != '');
    if (items.length > max) {
      this.showTriggered = items.slice(-this.maxLines).join('\n');
    } else {
      this.showTriggered = this.triggered;
    }
  }

  build() {
    Column() {
      Button("TextPickerDialog.show:" + this.v)
        .onClick(() => {
          this.getUIContext().showTextPickerDialog({
            range: this.cascade,
            selected: this.select,
            onAccept: (value: TextPickerResult) => {
              this.select = value.index
              console.log(this.select + '')
              this.v = value.value as string
              console.info("TextPickerDialog:onAccept()" + JSON.stringify(value))
              if (this.triggered != '') {
                this.triggered += `\nonAccept(${JSON.stringify(value)})`;
              } else {
                this.triggered = `onAccept(${JSON.stringify(value)})`;
              }
              this.linesNum(this.maxLines);
            },
            onCancel: () => {
              console.info("TextPickerDialog:onCancel()")
              if (this.triggered != '') {
                this.triggered += `\nonCancel()`;
              } else {
                this.triggered = `onCancel()`;
              }
              this.linesNum(this.maxLines);
            },
            onChange: (value: TextPickerResult) => {
              console.info("TextPickerDialog:onChange()" + JSON.stringify(value))
              if (this.triggered != '') {
                this.triggered += `\nonChange(${JSON.stringify(value)})`;
              } else {
                this.triggered = `onChange(${JSON.stringify(value)})`;
              }
              this.linesNum(this.maxLines);
            },
          })
        })
        .margin({ top: 60 })

      Row() {
        Button('1x').onClick(() => {
          this.setFontScale(1)
        }).margin(10)
        Button('1.75x').onClick(() => {
          this.setFontScale(1.75)
        }).margin(10)

        Button('2x').onClick(() => {
          this.setFontScale(2)
        }).margin(10)
        Button('3.2x').onClick(() => {
          this.setFontScale(3.2)
        }).margin(10)
      }.margin({ top: 50 })
    }

  }
}
```

| System Font at 1x (Before Aging-Friendly Features Are Enabled)| System Font at 1.75x (After Aging-Friendly Features Are Enabled)|
| ---------------------------------- | ------------------------------------ |
| ![](figures/aging_03.png)          | ![](figures/aging_04.png)            |
<!--RP1End-->
