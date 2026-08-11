# Modal Transition
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->


Modal transition is a type of transition achieved by a modal – a view that appears on top of the current view while the current view remains.


**Table 1** Modal transition APIs
| API                                      | Description               | Usage                                    |
| ---------------------------------------- | ----------------- | ---------------------------------------- |
| [bindContentCover](../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover) | Binds a modal to the component.       | Use this API to display a custom modal. It can work with the transition animation and shared element animation to implement complex transition animation effects, for example, displaying an image in full in the modal upon the click of a thumbnail.|
| [bindSheet](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet) | Binds a sheet to the component.         | Use this API to display a custom sheet, for example, a sharing confirmation dialog box.                         |
| [bindMenu](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu11) | Binds a menu to the component, which is displayed when the component is clicked.    | Use this API where a menu is required, for example, for the plus sign (+), a common menu indicator in applications.                |
| [bindContextMenu](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu12) | Binds a context menu to the component, which is displayed when the user long-presses or right-clicks the component.| Use this API for components that bounce up when long-pressed, for example, home screen icons.            |
| [bindPopup](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#bindpopup) | Binds a popup to the component.       | Use this API to display a popup containing additional information about a component when the component is clicked.              |
| [if](../ui/rendering-control/arkts-rendering-control-ifelse.md)                                       | Adds or deletes the component.     | Use this API to display a temporary page in a certain state. In this mode, the return navigation needs to be implemented with a listener. |


## Creating Modal Transition with bindContentCover

You can bind a full-screen modal to a component through the [bindContentCover](../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover) attribute. Better yet, with the **ModalTransition** parameter, you can apply a transition effect for when the component appears or disappears.

1. Define [bindContentCover](../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover).

2. Define the modal view.

   ```ts
   // Use @Builder to build a modal view.
   @Builder MyBuilder() {
     Column() {
      Text('my modal view')
     }
     // Use the transition API to implement the transition animation for component appearance and disappearance. The transition API must be added to the first component of the builder.
     .transition(TransitionEffect.translate({ y: 1000 }).animation({ curve: curves.springMotion(0.6, 0.8) }))
   }
   ```

3. Call the modal API to display the modal. Implement an animation by using the animation or shared element transition APIs.

   ```ts
   // Define the state variable to control the visibility of the modal.
   @State isPresent: boolean = false;

   Button('Click to present modal view')
     // Bind a modal to the component. ModalTransition.NONE means not to use the default transition animation for the modal. You can use onDisappear to control state variable changes.
     .bindContentCover(this.isPresent, this.MyBuilder(), {
               modalTransition: ModalTransition.NONE,
               onDisappear: () => {
                 if (this.isPresent) {
                   this.isPresent = !this.isPresent;
                 }
               }
             })
     .onClick(() => {
       // Change the state variable to display the modal.
       this.isPresent = !this.isPresent;
     })
   ```


Below is the complete sample code and effect.

<!-- @[bind_content_cover](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/modalTransition/template1/BindContentCoverDemo.ets) -->

``` TypeScript
import { curves } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

interface PersonList {
  name: Resource,
  cardNum: string
}

@Entry
@Component
struct BindContentCoverDemo {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private personList: Array<PersonList> = [
    // Replace $r('app.string.modal_transition_text1') with the actual resource file. In this example, the value in the resource file is "Wang **".
    { name: $r('app.string.modal_transition_text1'), cardNum: '1234***********789' },
    // Replace $r('app.string.modal_transition_text2') with the actual resource file. In this example, the value in the resource file is "Song **".
    { name: $r('app.string.modal_transition_text2'), cardNum: '2345***********789' },
    // Replace $r('app.string.modal_transition_text3') with the actual resource file. In this example, the value in the resource file is "Xu **".
    { name: $r('app.string.modal_transition_text3'), cardNum: '3456***********789' },
    // Replace $r('app.string.modal_transition_text4') with the actual resource file. In this example, the value in the resource file is "Tang **".
    { name: $r('app.string.modal_transition_text4'), cardNum: '4567***********789' }
  ];
  // Step 1: Define bindContentCover.
  // Define the state variable to control the visibility of the modal.
  @State isPresent: boolean = false;

  // Step 2: Define the modal view.
  // Use @Builder to build a modal view.
  @Builder
  MyBuilder() {
    Column() {
      Row() {
        // Replace $r('app.string.modal_transition_text5') with the actual resource file. In this example, the value in the resource file is "Select passenger".
        Text($r('app.string.modal_transition_text5'))
          .fontSize(20)
          .fontColor(Color.White)
          .width('100%')
          .textAlign(TextAlign.Center)
          .padding({ top: 30, bottom: 15 })
      }
      .backgroundColor(0x007dfe)

      Row() {
        // Replace $r('app.string.modal_transition_text6') with the actual resource file. In this example, the value in the resource file is "+Add passenger".
        Text($r('app.string.modal_transition_text6'))
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
              if (index % 2 === 0) {
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
              // Replace $r('app.string.modal_transition_text7') with the actual resource file. In this example, the value in the resource file is "Edit".
              Text($r('app.string.modal_transition_text7'))
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
      //Replace $r('app.string.modal_transition_text8') with the actual resource file. In this example, the value in the resource file is "Confirm".
      Text($r('app.string.modal_transition_text8'))
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
    // Use the transition API to implement the transition animation for component appearance and disappearance.
    .transition(TransitionEffect.translate({ y: 1000 }).animation({ curve: curves.springMotion(0.6, 0.8) }))
  }

  build() {
    Column() {
      Row() {
        // Replace $r('app.string.modal_transition_text9') with the actual resource file. In this example, the value in the resource file is "Confirm order".
        Text($r('app.string.modal_transition_text9'))
          .fontSize(20)
          .fontColor(Color.White)
          .width('100%')
          .textAlign(TextAlign.Center)
          .padding({ top: 30, bottom: 60 })
      }
      .backgroundColor(0x007dfe)

      Column() {
        Row() {
          Column() {
            Text('00:25')
            // Replace $r('app.string.modal_transition_text10') with the actual resource file. In this example, the value in the resource file is "Start station".
            Text($r('app.string.modal_transition_text10'))
          }
          .width('30%')

          Column() {
            Text('G1234')
            // Replace $r('app.string.modal_transition_text11') with the actual resource file. In this example, the value in the resource file is "8:01".
            Text($r('app.string.modal_transition_text11'))
          }
          .width('30%')

          Column() {
            Text('08:26')
            // Replace $r('app.string.modal_transition_text12') with the actual resource file. In this example, the value in the resource file is "Terminal station".
            Text($r('app.string.modal_transition_text12'))
          }
          .width('30%')
        }
      }
      .width('92%')
      .padding(15)
      .margin({ top: -30 })
      .backgroundColor(Color.White)
      .shadow({ radius: 30, color: '#aaaaaa' })
      .borderRadius(10)

      Column() {
        // Replace $r('app.string.modal_transition_text13') with the actual resource file. In this example, the value in the resource file is "+ Select passenger".
        Text($r('app.string.modal_transition_text13'))
          .fontSize(18)
          .fontColor(Color.Orange)
          .fontWeight(FontWeight.Bold)
          .padding({ top: 10, bottom: 10 })
          .width('60%')
          .textAlign(TextAlign.Center)
          .borderRadius(15)
          // Bind a modal using the selected modal API. ModalTransition represents the built-in ContentCover transition animation type.
          // ModalTransition.DEFAULT means to use the slide-up and slide-down animation type. You can use onDisappear to control state variable changes.
          .bindContentCover(this.isPresent, this.MyBuilder(), {
            modalTransition: ModalTransition.DEFAULT,
            onDisappear: () => {
              if (this.isPresent) {
                this.isPresent = !this.isPresent;
              }
            }
          })
          .onClick(() => {
            // Step 3: Call the modal API to display the modal. Implement an animation by using the animation or shared element transition APIs.
            // Change the state variable to display the modal.
            this.isPresent = !this.isPresent;
          })
      }
      .padding({ top: 60 })
    }
  }
}
```



![en-us_image_0000001646921957](figures/Modal-Transition-bindContentCover.gif)



## Creating Sheet Transition with bindSheet

You can bind a sheet to a component through the [bindSheet](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet) attribute. You can also set the sheet to the preset or custom height for when the component appears. The process of creating a sheet transition is basically the same as that of creating a modal transition using [bindContentCover](../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover).

Below is the complete sample code and effect.


<!-- @[bind_sheet_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/modalTransition/template2/BindSheetDemo.ets) -->

``` TypeScript
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct BindSheetDemo {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  // Set visibility of the sheet.
  @State isShowSheet: boolean = false;
  // Replace $r('app.string.modal_transition_text14') with the actual resource file. In this example, the value in the resource file is "No spicy".
  private menuList: Resource[] = [$r('app.string.modal_transition_text14'),
    // Replace $r('app.string.modal_transition_text15') with the actual resource file. In this example, the value in the resource file is "Mildly spicy".
    $r('app.string.modal_transition_text15'),
    // Replace $r('app.string.modal_transition_text16') with the actual resource file. In this example, the value in the resource file is "Extra spicy".
    $r('app.string.modal_transition_text16'),
    // Replace $r('app.string.modal_transition_text17') with the actual resource file. In this example, the value in the resource file is "No cilantro".
    $r('app.string.modal_transition_text17'),
    // Replace $r('app.string.modal_transition_text18') with the actual resource file. In this example, the value in the resource file is "No chives".
    $r('app.string.modal_transition_text18'),
    // Replace $r('app.string.modal_transition_text19') with the actual resource file. In this example, the value in the resource file is "No disposable tableware".
    $r('app.string.modal_transition_text19'),
    // Replace $r('app.string.modal_transition_text20') with the actual resource file. In this example, the value in the resource file is "Need disposable tableware".
    $r('app.string.modal_transition_text20')];

  // Use @Builder to build a sheet view.
  @Builder
  mySheet() {
    Column() {
      Flex({ direction: FlexDirection.Row, wrap: FlexWrap.Wrap }) {
        ForEach(this.menuList, (item: Resource) => {
          Text(item)
            .fontSize(16)
            .fontColor(0x333333)
            .backgroundColor(0xf1f1f1)
            .borderRadius(8)
            .margin(10)
            .padding(15)
        })
      }
      .padding({ top: 18 })
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.White)
  }

  build() {
    Column() {
      // Replace $r('app.string.modal_transition_text21') with the actual resource file. In this example, the value in the resource file is "Flavor and tableware".
      Text($r('app.string.modal_transition_text21'))
        .fontSize(28)
        .padding({ top: 30, bottom: 30 })
      Column() {
        Row() {
          Row()
            .width(10)
            .height(10)
            .backgroundColor('#a8a8a8')
            .margin({ right: 12 })
            .borderRadius(20)

          Column() {
            // Replace $r('app.string.modal_transition_text22') with the actual resource file. In this example, the value in the resource file is "Select flavor and tableware."
            Text($r('app.string.modal_transition_text22'))
              .fontSize(16)
              .fontWeight(FontWeight.Medium)
          }
          .alignItems(HorizontalAlign.Start)

          Blank()

          Row()
            .width(12)
            .height(12)
            .margin({ right: 15 })
            .border({
              width: { top: 2, right: 2 },
              color: 0xcccccc
            })
            .rotate({ angle: 45 })
        }
        .borderRadius(15)
        .shadow({ radius: 100, color: '#ededed' })
        .width('90%')
        .alignItems(VerticalAlign.Center)
        .padding({ left: 15, top: 15, bottom: 15 })
        .backgroundColor(Color.White)
        // Bind a sheet to the component. Set height (sheet height; large by default) and
        // DragBar (whether to display the drag bar; true by default). You can use onDisappear to control state variable changes.
        .bindSheet(this.isShowSheet, this.mySheet(), {
          height: 300,
          dragBar: false,
          onDisappear: () => {
            this.isShowSheet = !this.isShowSheet;
          }
        })
        .onClick(() => {
          this.isShowSheet = !this.isShowSheet;
        })
      }
      .width('100%')
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xf1f1f1)
  }
}
```

![en-us_image_0000001599977924](figures/Sheet-Transition-bindSheet.gif)


## Creating a Menu with bindMenu

You can bind a menu to component through the [bindMenu](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu) attribute. The menu can then be triggered by clicking. Below is the complete sample code and effect.


<!-- @[bind_menu_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/modalTransition/template3/BindMenuDemo.ets) -->

``` TypeScript
import { common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0xF811;
const TAG = '[Sample_Animation]';

class BMD {
  public value: ResourceStr = '';
  public action: () => void = () => {
  };
}

@Entry
@Component
struct BindMenuDemo {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  // Step 1: Define a data array to represent menu items.
  @State items: BMD[] = [
    {
      // Replace $r('app.string.modal_transition_text23') with the actual resource file. In this example, the value in the resource file is "Menu item 1".
      value: $r('app.string.modal_transition_text23'),
      action: () => {
        hilog.info(DOMAIN, TAG, 'handle Menu1 select');
      }
    },
    {
      // Replace $r('app.string.modal_transition_text24') with the actual resource file. In this example, the value in the resource file is "Menu item 2".
      value: $r('app.string.modal_transition_text24'),
      action: () => {
        hilog.info(DOMAIN, TAG, 'handle Menu2 select');
      }
    },
  ]

  build() {
    Column() {
      Button('click')
        .backgroundColor(0x409eff)
        // Step 2: Bind the menu data to the component through bindMenu.
        .bindMenu(this.items)
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height(437)
  }
}
```

<!--Del-->![image_0000001599643478]  (figures/Creating-Menu-bindMenu.gif)<!--DelEnd-->


## Creating a Context Menu with bindContextMenu

You can bind a menu to component through the [bindContextMenu](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu8) attribute. The menu can then be triggered by long-pressing or right-clicking.

Below is the complete sample code and effect.


<!-- @[bind_context_menu_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/modalTransition/template4/BindContextMenuDemo.ets) -->

``` TypeScript
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct BindContextMenuDemo {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  // Replace $r('app.string.modal_transition_text25') with the actual resource file. In this example, the value in the resource file is "Save image".
  private menu: Resource[] = [$r('app.string.modal_transition_text25'),
    // Replace $r('app.string.modal_transition_text26') with the actual resource file. In this example, the value in the resource file is "Favorites".
    $r('app.string.modal_transition_text26'),
    // Replace $r('app.string.modal_transition_text27') with the actual resource file. In this example, the value in the resource file is "Search".
    $r('app.string.modal_transition_text27')];
  // Replace $r('app.media.icon_2') with the actual resource file.
  private pics: Resource[] = [$r('app.media.icon_1'), $r('app.media.icon_2')];

  // Use @Builder to build custom menu items.
  @Builder
  myMenu() {
    Column() {
      ForEach(this.menu, (item: Resource) => {
        Row() {
          Text(item)
            .fontSize(18)
            .width('100%')
            .textAlign(TextAlign.Center)
        }
        .padding(15)
        .border({ width: { bottom: 1 }, color: 0xcccccc })
      })
    }
    .width(140)
    .borderRadius(15)
    .shadow({ radius: 15, color: 0xf1f1f1 })
    .backgroundColor(0xf1f1f1)
  }

  build() {
    Column() {
      Row() {
        // Replace $r('app.string.modal_transition_text28') with the actual resource file. In this example, the value in the resource file is "View image".
        Text($r('app.string.modal_transition_text28'))
          .fontSize(20)
          .fontColor(Color.White)
          .width('100%')
          .textAlign(TextAlign.Center)
          .padding({ top: 20, bottom: 20 })
      }
      .backgroundColor(0x007dfe)

      Column() {
        ForEach(this.pics, (item: Resource) => {
          Row() {
            Image(item)
              .width('100%')
              .draggable(false)
          }
          .padding({
            top: 20,
            bottom: 20,
            left: 10,
            right: 10
          })
          .bindContextMenu(this.myMenu, ResponseType.LongPress)
        })
      }
    }
    .width('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

![en-us_image_0000001600137920](figures/Context-Menu-bindContextMenu.gif)


## Creating a Popup with bindPopup

You can bind a popup to a component through the [bindPopup](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#bindpopup) attribute, specifying its content, interaction logic, and display status.

Below is the complete sample code and effect.


<!-- @[bind_popup_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/modalTransition/template5/BindPopupDemo.ets) -->

``` TypeScript
@Entry
@Component
struct BindPopupDemo {
  // Step 1: Define the state variable to control the visibility of the popup.
  @State customPopup: boolean = false;

  // Step 2: Use @Builder to build a custom popup.
  @Builder
  popupBuilder() {
    Column({ space: 2 }) {
      Row().width(64)
        .height(64)
        .backgroundColor(0x409eff)
      Text('Popup')
        .fontSize(10)
        .fontColor(Color.White)
    }
    .justifyContent(FlexAlign.SpaceAround)
    .width(100)
    .height(100)
    .padding(5)
  }

  build() {
    Column() {

      Button('click')
      // Step 4: Add a click event to control the visibility of the popup.
        .onClick(() => {
          this.customPopup = !this.customPopup;
        })
        .backgroundColor(0xf56c6c)
        // Step 3: Bind the popup to the component through bindPopup.
        .bindPopup(this.customPopup, {
          builder: this.popupBuilder,
          placement: Placement.Top,
          maskColor: 0x33000000,
          popupColor: 0xf56c6c,
          enableArrow: true,
          onStateChange: (e) => {
            if (!e.isVisible) {
              this.customPopup = false;
            }
          }
        })
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height(437)
  }
}
```



![en-us_image_0000001649282285](figures/Creating-Popup-with-bindPopup.gif)


## Creating Modal Transition with if

In addition to the preceding modal transition APIs, you can also use the **if** syntax to create a modal transition, eliminating the need for binding to the component and listening for state variable changes.

Below is the complete sample code and effect.


<!-- @[modal_transition_with_if](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/modalTransition/template6/ModalTransitionWithIf.ets) -->

``` TypeScript
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct ModalTransitionWithIf {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  // In the resources\base\element\string.json file, set name to 'modal_transition_text29' and value to a non-null string.
  private listArr: ResourceStr[] = ['WLAN', this.context.resourceManager.getStringByNameSync('modal_transition_text29'),
    // In the resources\base\element\string.json file, set name to 'modal_transition_text30' and value to a non-null string.
    this.context.resourceManager.getStringByNameSync('modal_transition_text30'),
    // In the resources\base\element\string.json file, set name to 'modal_transition_text31' and value to a non-null string.
    this.context.resourceManager.getStringByNameSync('modal_transition_text31')];
  // In the resources\base\element\string.json file, set name to 'modal_transition_text32' and value to a non-null string.
  private shareArr: ResourceStr[] = [this.context.resourceManager.getStringByNameSync('modal_transition_text32'),
    // In the resources\base\element\string.json file, set name to 'modal_transition_text33' and value to a non-null string.
    this.context.resourceManager.getStringByNameSync('modal_transition_text33'), 'VPN',
    // In the resources\base\element\string.json file, set name to 'modal_transition_text34' and value to a non-null string.
    this.context.resourceManager.getStringByNameSync('modal_transition_text34'), 'NFC'];
  // Step 1: Define a state variable to control page display.
  @State isShowShare: boolean = false;

  private shareFunc(): void {
    this.getUIContext()?.animateTo({ duration: 500 }, () => {
      this.isShowShare = !this.isShowShare;
    })
  }

  build() {
    // Step 2: Define a stack layout to display the current view and modal view.
    Stack() {
      Column() {
        Column() {
          // Replace $r('app.string.modal_transition_text35') with the actual resource file. In this example, the value in the resource file is "Settings."
          Text($r('app.string.modal_transition_text35'))
            .fontSize(28)
            .fontColor(0x333333)
        }
        .width('90%')
        .padding({ top: 30, bottom: 15 })
        .alignItems(HorizontalAlign.Start)
        // Replace $r('app.string.modal_transition_text36') with the actual resource file. In this example, the value in the resource file is "Search by keyword."
        TextInput({ placeholder: $r('app.string.modal_transition_text36') })
          .width('90%')
          .height(40)
          .margin({ bottom: 10 })
          .focusable(false)

        List({ space: 12, initialIndex: 0 }) {
          ForEach(this.listArr, (item: string, index: number) => {
            ListItem() {
              Row() {
                Row() {
                  Text(`${item.slice(0, 1)}`)
                    .fontColor(Color.White)
                    .fontSize(14)
                    .fontWeight(FontWeight.Bold)
                }
                .width(30)
                .height(30)
                .backgroundColor('#a8a8a8')
                .margin({ right: 12 })
                .borderRadius(20)
                .justifyContent(FlexAlign.Center)

                Column() {
                  Text(item)
                    .fontSize(16)
                    .fontWeight(FontWeight.Medium)
                }
                .alignItems(HorizontalAlign.Start)

                Blank()

                Row()
                  .width(12)
                  .height(12)
                  .margin({ right: 15 })
                  .border({
                    width: { top: 2, right: 2 },
                    color: 0xcccccc
                  })
                  .rotate({ angle: 45 })
              }
              .borderRadius(15)
              .shadow({ radius: 100, color: '#ededed' })
              .width('90%')
              .alignItems(VerticalAlign.Center)
              .padding({ left: 15, top: 15, bottom: 15 })
              .backgroundColor(Color.White)
            }
            .width('100%')
            .onClick(() => {
              // Step 5: Change the state variable to display the modal view.
              // Configure the resource whose name is 'modal_transition_text37' and value is a non-empty string in the resources\base\element\string.json file.
              if (item.slice(-2) === this.context.resourceManager.getStringByNameSync('modal_transition_text37')) {
                this.shareFunc();
              }
            })
          }, (item: string): string => item)
        }
        .width('100%')
      }
      .width('100%')
      .height('100%')
      .backgroundColor(0xfefefe)

      // Step 3: Define the modal view in if and display it at the top layer. Use if to control the appearance and disappearance of the modal view.
      if (this.isShowShare) {
        Column() {
          Column() {
            Row() {
              Row() {
                Row()
                  .width(16)
                  .height(16)
                  .border({
                    width: { left: 2, top: 2 },
                    color: 0x333333
                  })
                  .rotate({ angle: -45 })
              }
              .padding({ left: 15, right: 10 })
              .onClick(() => {
                this.shareFunc();
              })
              // Replace $r('app.string.modal_transition_text31') with the actual resource file. In this example, the value in the resource file is "Connect and share."
              Text($r('app.string.modal_transition_text31'))
                .fontSize(28)
                .fontColor(0x333333)
            }
            .padding({ top: 30 })
          }
          .width('90%')
          .padding({ bottom: 15 })
          .alignItems(HorizontalAlign.Start)

          List({ space: 12, initialIndex: 0 }) {
            ForEach(this.shareArr, (item: string) => {
              ListItem() {
                Row() {
                  Row() {
                    Text(`${item.slice(0, 1)}`)
                      .fontColor(Color.White)
                      .fontSize(14)
                      .fontWeight(FontWeight.Bold)
                  }
                  .width(30)
                  .height(30)
                  .backgroundColor('#a8a8a8')
                  .margin({ right: 12 })
                  .borderRadius(20)
                  .justifyContent(FlexAlign.Center)

                  Column() {
                    Text(item)
                      .fontSize(16)
                      .fontWeight(FontWeight.Medium)
                  }
                  .alignItems(HorizontalAlign.Start)

                  Blank()

                  Row()
                    .width(12)
                    .height(12)
                    .margin({ right: 15 })
                    .border({
                      width: { top: 2, right: 2 },
                      color: 0xcccccc
                    })
                    .rotate({ angle: 45 })
                }
                .borderRadius(15)
                .shadow({ radius: 100, color: '#ededed' })
                .width('90%')
                .alignItems(VerticalAlign.Center)
                .padding({ left: 15, top: 15, bottom: 15 })
                .backgroundColor(Color.White)
              }
              .width('100%')
            }, (item: string): string => item)
          }
          .width('100%')
        }
        .width('100%')
        .height('100%')
        .backgroundColor(0xffffff)
        // Step 4: Define the mode in which the modal view disappears.
        .transition(TransitionEffect.OPACITY
          .combine(TransitionEffect.translate({ x: '100%' }))
          .combine(TransitionEffect.scale({ x: 0.95, y: 0.95 })))
      }
    }
  }
}
```

![en-us_image_0000001597792146](figures/Modal-Transition.gif)
