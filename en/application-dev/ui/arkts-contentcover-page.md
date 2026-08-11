# Binding a Full-Modal Page (bindContentCover)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=fd87a3fabd6b3d582616cc6b10933b62b2152e9f translatedAt=2026-07-30T11:30:14.860Z pushedAt=2026-07-30T11:42:43.416Z -->

A full-modal page, implemented using [bindContentCover](../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover), is a full-screen modal interaction page that completely covers the underlying parent view. It is ideal for scenarios such as viewing large images or full-screen documents.

## Constraints

A full-modal page functions as a popup component and is, by default, at the topmost layer in the application.

When [Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md) is used, any new page pushed will not be able to exceed the full-modal in terms of layering; it will remain beneath the modal page. In such cases, consider integrating the content of the modal page into the transition page. For example, you can use **NavDestination** to replace the modal page being launched, ensuring that the new page is at a lower layer than the full-modal.

## Lifecycle

The full-modal page provides lifecycle callbacks to notify the application of the lifecycle status of the popup. These callbacks are triggered in the following order: onWillAppear -> onAppear -> onWillDisappear -> onDisappear.

| Name           |Type| Description                      |
| ----------------- | ------ | ---------------------------- |
| onWillAppear    | () => void | Callback for when the full-modal page is about to be displayed (before the animation starts).|
| onAppear    | () => void  | Callback for when the full-modal page is displayed (after the animation ends). |
| onWillDisappear | () => void | Callback for when the full-modal page is about to disappear (before the animation starts).|
| onDisappear |() => void  | Callback for when the full-modal page disappears (after the animation ends).    |

## Using bindContentCover to Build Full-Screen Modal Content over Semi-Modal

There is a popup-style layered interaction between full-modal and semi-modal pages. A modal page launched later can cover the previous modal page. If you want to implement a full-screen transition to cover the semi-modal and ensure that the semi-modal page remains visible after the full-screen page is swiped out, use **bindSheet** in combination with **bindContentCover**.

For details about how to use **bindContentCover** to create a full-screen modal transition effect, see [Modal Transition](arkts-modal-transition.md#creating-modal-transition-with-bindcontentcover)

<!-- @[bindContentCover_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/BindSheet/entry/src/main/ets/pages/bindContentCover/template6/BindContentCoverDemo.ets) -->

``` TypeScript
import { curves } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

interface PersonList {
  name: string,
  cardNum: string
}

@Entry
@Component
struct BindContentCoverDemo {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private manager = this.context.resourceManager;
  private personList: Array<PersonList> = [
    // The value in the 'Person_example1' resource file is 'Wang **.'
    { name: this.manager.getStringByNameSync('Person_example1'), cardNum: '1234***********789' },
    // The value in the 'Person_example2' resource file is 'Song *.'
    { name: this.manager.getStringByNameSync('Person_example2'), cardNum: '2345***********789' },
    // The value in the 'Person_example3' resource file is 'Xu **.'
    { name: this.manager.getStringByNameSync('Person_example3'), cardNum: '3456***********789' },
    // The value in the 'Person_example4' resource file is 'Tang *.'
    { name: this.manager.getStringByNameSync('Person_example4'), cardNum: '4567***********789' }
  ];
  // Define the state variable to control the semi-modal visibility.
  @State isSheetShow: boolean = false;
  // Define the state variable to control the full-modal visibility.
  @State isPresent: boolean = false;

  @Builder
  MyContentCoverBuilder() {
    Column() {
      Row() {
        // Replace $r('app.string.Text_choose_person') with the actual resource file. In this example, the value in the resource file is "Select passengers."
        Text($r('app.string.Text_choose_person'))
          .fontSize(20)
          .fontColor(Color.White)
          .width('100%')
          .textAlign(TextAlign.Center)
          .padding({ top: 30, bottom: 15 })
      }
      .backgroundColor(0x007dfe)

      Row() {
        // Replace $r('app.string.Text_add_person') with the actual resource file. In this example, the value in the resource file is "+ Add."
        Text($r('app.string.Text_add_person'))
          .fontSize(16)
          .fontColor(0x333333)
          .margin({ top: 10 })
          .padding({ top: 20, bottom: 20 })
          .width('92%')
          .borderRadius(10)
          .textAlign(TextAlign.Center)
          .backgroundColor(Color.White)
      }

      Column() {
        ForEach(this.personList, (item: PersonList, index: number) => {
          Row() {
            Column() {
              if (index % 2 == 0) {
                Column()
                  .width(20)
                  .height(20)
                  .border({ width: 1, color: 0x007dfe })
                  .backgroundColor(0x007dfe)
              } else {
                Column()
                  .width(20)
                  .height(20)
                  .border({ width: 1, color: 0x007dfe })
              }
            }
            .width('20%')

            Column() {
              Text(item.name)
                .fontColor(0x333333)
                .fontSize(18)
              Text(item.cardNum)
                .fontColor(0x666666)
                .fontSize(14)
            }
            .width('60%')
            .alignItems(HorizontalAlign.Start)

            Column() {
              // Replace $r('app.string.Text_edit') with the actual resource file. In this example, the value in the resource file is "Edit."
              Text($r('app.string.Text_edit'))
                .fontColor(0x007dfe)
                .fontSize(16)
            }
            .width('20%')
          }
          .padding({ top: 10, bottom: 10 })
          .border({ width: { bottom: 1 }, color: 0xf1f1f1 })
          .width('92%')
          .backgroundColor(Color.White)
        })
      }
      .padding({ top: 20, bottom: 20 })

      // Replace r('app.string.Text_confirm') with the actual resource file. In this example, the value in the resource file is "OK."
      Text($r('app.string.Text_confirm'))
        .width('90%')
        .height(40)
        .textAlign(TextAlign.Center)
        .borderRadius(10)
        .fontColor(Color.White)
        .backgroundColor(0x007dfe)
        .onClick(() => {
          this.isPresent = !this.isPresent;
        })
    }
    .size({ width: '100%', height: '100%' })
    .backgroundColor(0xf5f5f5)
  }

  @Builder
  TripInfo() {
    Row() {
      Column() {
        Text('00:25')
        // Replace $r('app.string.Label_origin_station') with the actual resource file. In this example, the value in the resource file is "Departure."
        Text($r('app.string.Label_origin_station'))
      }
      .width('25%')

      Column() {
        Text('G1234')
        // Replace $r('app.string.Label_start_time') with the actual resource file. In this example, the value in the resource file is "8 h 1 min."
        Text($r('app.string.Label_start_time'))
      }
      .width('25%')

      Column() {
        Text('08:26')
        // Replace $r('app.string.Label_destination_station') with the actual resource file. In this example, the value in the resource file is "Arrival."
        Text($r('app.string.Label_destination_station'))
      }
      .width('25%')
    }
  }

  // Step 2: Define the semi-modal view.
  // Use @Builder to build a modal view.
  @Builder
  MySheetBuilder() {
    Column() {
      Column() {
        this.TripInfo()
      }
      .width('92%')
      .margin(15)
      .backgroundColor(Color.White)
      .shadow({ radius: 30, color: '#aaaaaa' })
      .borderRadius(10)

      Column() {
        // Replace $r('app.string.Sheet_choose_person') with the actual resource file. In this example, the value in the resource file is "+ Select passengers."
        Text($r('app.string.Sheet_choose_person'))
          .fontSize(18)
          .fontColor(Color.Orange)
          .fontWeight(FontWeight.Bold)
          .padding({ top: 10, bottom: 10 })
          .width('60%')
          .textAlign(TextAlign.Center)
          .borderRadius(15)
          .onClick(() => {
            // Step 3: Launch the full-modal view using the full-modal API. The newly launched modal panel is displayed on the top by default.
            this.isPresent = !this.isPresent;
          })
          // Bind the modal view MyContentCoverBuilder using the full-modal API. The transition property supports custom transition effects. Here a horizontal entry along the x-axis is defined.
          .bindContentCover($$this.isPresent, this.MyContentCoverBuilder(), {
            transition: TransitionEffect.translate({ x: 500 }).animation({ curve: curves.springMotion(0.6, 0.8) })
          })
      }
      .padding({ top: 60 })
    }
  }

  build() {
    Column() {
      Row() {
        this.TripInfo()
        // Replace $r('app.string.Sheet_tickets_available') with the actual resource file. In this example, the value in the resource file is "Tickets available."
        Text($r('app.string.Sheet_tickets_available'))
          .fontColor(Color.Blue)
          .width('25%')
      }
      .width('100%')
      .margin({top: 200, bottom: 30})
      .borderRadius(10)
      .backgroundColor(Color.White)
      .onClick(()=>{
        this.isSheetShow = !this.isSheetShow;
      })
      // Step 1: Define the semi-modal transition effect.
      .bindSheet($$this.isSheetShow, this.MySheetBuilder(), {
        height: SheetSize.MEDIUM,
        // Replace $r('app.string.Text_confirm_order') with the actual resource file. In this example, the value in the resource file is "Confirm Order."
        title: {title: $r('app.string.Text_confirm_order')},
      })
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#30aaaaaa')
  }
}
```

![modalTransition](figures/modalTransition.gif)