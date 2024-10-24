# 支持适老化

## 基本概念

适老化提供了一种通过鼠标或手指长按的方法来放大所选区域或组件，即如果系统字体大小大于1倍，当用户使用鼠标或手指长按装配了适老化方法的组件，需要从所选区域的组件中提取数据，并放入另一个弹窗组件中展示。该方法的目的在于使组件和组件内部数据（子组件）放大，同时将整体组件在屏幕中央显示，让用户能够更好的观察该组件。

## 使用约束

* 适老化规则

  由于在系统字体大于1倍时，组件并没有默认放大，需要通过配置[configuration标签](../quick-start/app-configuration-file.md#configuration标签)，实现组件放大的适老化功能。

<!--RP1--><!--RP1End-->

* 适老化操作

  在已经支持适老化能力的组件上长按组件，能够触发弹窗，当用户释放时，适老化操作结束。当设置系统字体大于1倍时，组件自动放大，当系统字体恢复至1倍时组件恢复正常状态。

* 适老化对象

  触发适老化操作并提供数据的组件。

* 适老化弹窗目标

  可接收并处理适老化数据的组件。

* 弹窗限制

  当用户将系统字体设置为2倍以上时，弹窗内容包括icon和文字的放大倍数固定为2倍。

* 联合其他能力

  适老化能力可以适配其他能力（如：滑动拖拽）。底部页签（tabBar）组件在触发适老化时，如果用户滑动手指或鼠标可以触发底部页签其他子组件的适老化功能。

## 适配适老化的组件及触发方式

| 触发方式             | 组件名称                                                     |
| -------------------- | ------------------------------------------------------------ |
| 长按组件触发         | [SideBarContainer](../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md)， [底部页签（tabBar）](../reference/apis-arkui/arkui-ts/ts-container-tabcontent.md#tabbar9)，[Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md)，[NavDestination](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10)， [Tabs](../reference/apis-arkui/arkui-ts/ts-container-tabs.md) |
| 设置系统字体默认放大 | [PickerDialog](../reference/apis-arkui/arkui-ts/ts-methods-calendarpicker-dialog.md)， [Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md)， [Menu](../reference/apis-arkui/arkui-ts/ts-basic-components-menu.md)， [Stepper](../reference/apis-arkui/arkui-ts/ts-basic-components-stepper.md)， [BindSheet](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)，[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)/[TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md)/[Search](../reference/apis-arkui/arkui-ts/ts-basic-components-search.md)/[SelectionMenu](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-SelectionMenu.md)，[Chip](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Chip.md#chip)，[Dialog](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Dialog.md)，[Slider](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md)， [Progress](../reference/apis-arkui/arkui-ts/ts-basic-components-progress.md)， [Badge](../reference/apis-arkui/arkui-ts/ts-container-badge.md) |

## 示例

<!--RP2-->
SideBarContainer组件通过长按控制按钮触发适老化弹窗。在系统字体为1倍的情况下，长按控制按钮不能弹窗。在系统字体大于1倍的情况下，长按控制按钮可以弹窗。

```ts
import { abilityManager, Configuration } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct SideBarContainerExample {
  @State currentFontSizeScale: number = 1
  normalIcon: Resource = $r("app.media.icon")
  selectedIcon: Resource = $r("app.media.icon")
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1
  @State title: string = 'Index01';
  // 设置字体大小
  async setFontScale(scale: number): Promise<void> {
    let configInit: Configuration = {
      language: 'zh-Ch',
      fontSizeScale: scale,
    };
    // 更新配置-字体大小
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
        Button('1倍').onClick(() => {
          this.setFontScale(1)
        }).margin(10)
        Button('1.75倍').onClick(() => {
          this.setFontScale(1.75)
        }).margin(10)
        Button('2倍').onClick(() => {
          this.setFontScale(2)
        }).margin(10)
        Button('3.2倍').onClick(() => {
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

切换系统字体前后长按已经支持适老化能力的组件，有如下效果：

| 系统字体为一倍（适老化能力开启前） | 系统字体为1.75倍（适老化能力开启后） |
| ---------------------------------- | ------------------------------------ |
| ![](figures/aging_01.png)          | ![](figures/aging_02.png)            |

[TextPickerDialog](../reference/apis-arkui/arkui-ts/ts-methods-textpicker-dialog.md)组件通过设置系统字体大小触发适老化弹窗。在系统字体为1倍的情况下，适老化不触发；在系统字体大于1倍的情况下，适老化触发。

```ts
import { abilityManager, Configuration } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct TextPickerExample {
  private select: number | number[] = 0;
  private cascade: TextCascadePickerRangeContent[] = [
    {
      text: '辽宁省',
      children: [{ text: '沈阳市', children: [{ text: '沈河区' }, { text: '和平区' }, { text: '浑南区' }] },
        { text: '大连市', children: [{ text: '中山区' }, { text: '金州区' }, { text: '长海县' }] }]
    },
    {
      text: '吉林省',
      children: [{ text: '长春市', children: [{ text: '南关区' }, { text: '宽城区' }, { text: '朝阳区' }] },
        { text: '四平市', children: [{ text: '铁西区' }, { text: '铁东区' }, { text: '梨树县' }] }]
    },
    {
      text: '黑龙江省',
      children: [{ text: '哈尔滨市', children: [{ text: '道里区' }, { text: '道外区' }, { text: '南岗区' }] },
        { text: '牡丹江市', children: [{ text: '东安区' }, { text: '西安区' }, { text: '爱民区' }] }]
    }
  ]
  @State v: string = '';
  @State showTriggered: string = '';
  private triggered: string = '';
  private maxLines: number = 3;
  // 设置字体大小
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
        Button('1倍').onClick(() => {
          this.setFontScale(1)
        }).margin(10)
        Button('1.75倍').onClick(() => {
          this.setFontScale(1.75)
        }).margin(10)

        Button('2倍').onClick(() => {
          this.setFontScale(2)
        }).margin(10)
        Button('3.2倍').onClick(() => {
          this.setFontScale(3.2)
        }).margin(10)
      }.margin({ top: 50 })
    }

  }
}
```

| 系统字体为一倍（适老化能力开启前） | 系统字体为1.75倍（适老化能力开启后） |
| ---------------------------------- | ------------------------------------ |
| ![](figures/aging_03.png)          | ![](figures/aging_04.png)            |
<!--RP2End-->