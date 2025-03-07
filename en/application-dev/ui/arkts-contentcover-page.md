# Binding a Full-Modal Page (bindContentCover)

A full-modal page, implemented using [bindContentCover](../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover), is a full-screen modal interaction page that completely covers the underlying parent view. It is ideal for scenarios such as viewing large images or full-screen documents.

## Constraints

A full-modal page functions as a popup component and is, by default, at the topmost layer in the application.

When [Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md) is used, any new page pushed will not be able to exceed the full-modal in terms of layering; it will remain beneath the modal page. In such cases, consider integrating the content of the modal page into the transition page. For example, you can use **NavDestination** to replace the modal page being launched, ensuring that the new page is positioned below the full-modal.

## Lifecycle

The full-modal page provides lifecycle callbacks to notify the application of the lifecycle status of the popup. These callbacks are triggered in the following order: onWillAppear -> onAppear -> onWillDisappear -> onDisappear.

| Name           |Type| Description                      |
| ----------------- | ------ | ---------------------------- |
| onWillAppear    | () => void | Callback for when the full-modal page is about to be displayed (before the animation starts).|
| onAppear    | () => void  | Callback for when the full-modal page is displayed (after the animation ends). |
| onWillDisappear | () => void | Callback for when the full-modal page is about to disappear (before the animation starts).|
| onDisappear |() => void  | Callback for when the full-modal page disappears (after the animation ends).    |

## Using bindContentCover to Build Full-Screen Modal Content over Semi-Modal

There is a popup-style layer interaction between full-modal and semi-modal pages. A modal page launched later can cover the previous modal page. If you want to implement a full-screen transition to cover the semi-modal and ensure that the semi-modal page remains visible after the full-screen page is swiped out, use **bindSheet** in combination with **bindContentCover**.

For details about how to use **bindContentCover** to create a full-screen modal transition effect, see [Modal Transition](arkts-modal-transition.md#creating-modal-transition-with-bindcontentcover)

```ts
import { curves } from '@kit.ArkUI';

interface PersonList {
  name: string,
  cardnum: string
}

@Entry
@Component
struct BindContentCoverDemo {
  private personList: Array<PersonList> = [
    { name: 'Wang **', cardnum: '1234***********789' },
    { name: 'Song *', cardnum: '2345***********789' },
    { name: 'Xu **', cardnum: '3456***********789' },
    { name: 'Tang *', cardnum: '4567***********789' }
  ];
  // Define the state variable to control the semi-modal visibility.
  @State isSheetShow: boolean = false;
  // Define the state variable to control the full-modal visibility.
  @State isPresent: boolean = false;

  @Builder
  MyContentCoverBuilder() {
    Column() {
      Row() {
        Text('Select passengers')
          .fontSize(20)
          .fontColor(Color.White)
          .width('100%')
          .textAlign(TextAlign.Center)
          .padding({ top: 30, bottom: 15 })
      }
      .backgroundColor(0x007dfe)

      Row() {
        Text('+ Add')
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
              Text(item.cardnum)
                .fontColor(0x666666)
                .fontSize(14)
            }
            .width('60%')
            .alignItems(HorizontalAlign.Start)

            Column() {
              Text('Edit')
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

      Text('OK')
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
        Text('From')
      }
      .width('25%')

      Column() {
        Text('G1234')
        Text('8 h 1 min')
      }
      .width('25%')

      Column() {
        Text('08:26')
        Text('To')
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
        Text('+ Select passengers')
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
        Text('Tickets available')
          .fontColor(Color.Blue)
          .width('25%')
      }
      .width('100%')
      .margin({top: 200, bottom: 30})
      .borderRadius(10)
      .backgroundColor(Color.White)
      .onClick(()=>{
        this.isSheetShow = !this.isSheetShow
      })
      // Step 1: Define the semi-modal transition effect.
      .bindSheet($$this.isSheetShow, this.MySheetBuilder(), {
        height: SheetSize.MEDIUM,
        title: {title: "Confirm Order"},
      })
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#30aaaaaa')
  }
}
```
