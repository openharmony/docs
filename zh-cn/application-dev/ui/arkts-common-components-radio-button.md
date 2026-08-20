# 单选框 (Radio)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @houguobiao-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->


Radio是单选框组件，通常用于提供相应的用户交互选择项，同一组的Radio中只有一个可以被选中。具体用法请参考[Radio](../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md)。


## 创建单选框

Radio通过调用[RadioOptions](../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md#radiooptions对象说明)来创建，以RadioOptions中的value和group为例：

```ts
Radio(options: {value: string, group: string})
```

其中，value是单选框的名称，group是单选框的所属群组名称。checked属性可以设置单选框的状态，状态分别为false和true，设置为true时表示单选框被选中。

Radio支持设置选中状态和非选中状态的样式。

<!-- @[click_radio_to_show_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/radio/RadioButton.ets) -->

``` TypeScript
Radio({ value: 'Radio1', group: 'radioGroup' })
  .checked(false)
Radio({ value: 'Radio2', group: 'radioGroup' })
  .checked(true)
```


![zh-cn_image_0000001562820821](figures/zh-cn_image_0000001562820821.png)

## 添加事件

除支持[通用事件](../reference/apis-arkui/arkui-ts/ts-component-general-events.md)外，Radio还用于选中后触发某些操作，可以绑定onChange事件来响应选中操作后的自定义行为。

<!-- @[click_radio_event_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/radio/RadioButton.ets) -->

``` TypeScript
Radio({ value: 'Radio1', group: 'radioGroup' })
  .onChange((isChecked: boolean) => {
    if(isChecked) {
      // 需要执行的操作
      // ...
    }
  })
Radio({ value: 'Radio2', group: 'radioGroup' })
  .onChange((isChecked: boolean) => {
    if(isChecked) {
      // 需要执行的操作
      // ...
    }
  })
```


## 场景示例

通过点击Radio切换声音模式。

<!-- @[click_radio_to_change_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/radio/RadioSample.ets) -->

``` TypeScript
// xxx.ets
import { promptAction } from '@kit.ArkUI';

@Entry
@Component
export struct RadioExample {
  @State rst: promptAction.ShowToastOptions = { 'message': 'Ringing mode.' };
  @State vst: promptAction.ShowToastOptions = { 'message': 'Vibration mode.' };
  @State sst: promptAction.ShowToastOptions = { 'message': 'Silent mode.' };

  build() {
    // ...
      Row() {
        Column() {
          Radio({ value: 'Ringing', group: 'radioGroup' }).checked(true)
            .height(50)
            .width(50)
            .onChange(async (isChecked: boolean) => {
              if (isChecked) {
                try {
                  // 切换为响铃模式
                  await this.getUIContext().getPromptAction().openToast(this.rst);
                } catch (err) {
                  console.error(`Failed to show toast: ${err.code}`);
                }
              }
            })
          Text('Ringing')
        }

        Column() {
          Radio({ value: 'Vibration', group: 'radioGroup' })
            .height(50)
            .width(50)
            .onChange(async (isChecked: boolean) => {
              if (isChecked) {
                try {
                  // 切换为振动模式
                  await this.getUIContext().getPromptAction().openToast(this.vst);
                } catch (err) {
                  console.error(`Failed to show toast: ${err.code}`);
                }
              }
            })
          Text('Vibration')
        }

        Column() {
          Radio({ value: 'Silent', group: 'radioGroup' })
            .height(50)
            .width(50)
            .onChange(async (isChecked: boolean) => {
              if (isChecked) {
                try {
                  // 切换为静音模式
                  await this.getUIContext().getPromptAction().openToast(this.sst);
                } catch (err) {
                  console.error(`Failed to show toast: ${err.code}`);
                }
              }
            })
          Text('Silent')
        }
      }.height('100%').width('100%').justifyContent(FlexAlign.Center)
      // ...
  }
}
```


![zh-cn_image_0000001562700457](figures/zh-cn_image_0000001562700457.gif)

为不同Swiper页中的Radio设置独立的group值，实现各季节活动选项的隔离与独立选择。


<!-- @[radio_control_swiper_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/radio/RadioSwiper.ets) -->

``` TypeScript
// xxx.ets
@Entry
@Component
export struct RadioSwiperSample {
  // 当前展示的页面索引
  @State currentIndex: number = 0;
  // 各页面的主题色
  private colors: string[] = ['#699eec', '#699eec', '#699eec'];
  // 各页面的标题文字
  private titles: string[] = ['Spring', 'Summer', 'Autumn'];
  // 各页面对应的独立Radio分组名称，不同页面的分组互不影响
  private groups: string[] = ['springGroup', 'summerGroup', 'autumnGroup'];
  // 各页面独立的可选项
  private options: string[][] = [
    ['Bloom', 'Spring outing', 'Kite'],
    ['Swim', 'Cool off', 'Watermelon'],
    ['Moon', 'Climb', 'Autumn outing']
  ];

  build() {
    // ...
      Column({ space: 16 }) {
        Text(`Current page: ${this.titles[this.currentIndex]}`)
          .fontSize(18)
          .fontWeight(FontWeight.Medium)

        // Swiper每页内包含一组独立的Radio，滑动切页后各页选中状态互不影响
        Swiper() {
          ForEach(this.titles, (title: string, index: number) => {
            Column({ space: 16 }) {
              Text(title)
                .fontSize(48)
                .fontColor('#fff')
              // 当前页的Radio分组，group名称随页面变化，与其他页相互独立
              Row({ space: 24 }) {
                ForEach(this.options[index], (option: string) => {
                  Column() {
                    Radio({ value: option, group: this.groups[index] })
                    Text(option)
                      .fontSize(14)
                      .fontColor('#fff')
                      .margin({ top: 4 })
                  }
                })
              }
              .justifyContent(FlexAlign.Center)
            }
            .width('100%')
            .height(240)
            .justifyContent(FlexAlign.Center)
            .backgroundColor(this.colors[index])
            .borderRadius(16)
          })
        }
        .index(this.currentIndex)
        .indicator(true)
        .loop(false)
        .onChange((index: number) => {
          // 滑动切换页面时，更新当前页索引
          this.currentIndex = index;
        })
      }
      .width('100%')
      .height('100%')
      .padding({ left: 16, right: 16 })
      .alignItems(HorizontalAlign.Center)
      // ...
  }
}
```


![radio-swiper](figures/radio-swiper.gif)
