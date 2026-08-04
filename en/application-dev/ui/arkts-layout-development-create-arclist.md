# Creating an Arc List (ArcList) (Recommended for Circular Screens)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @wind_-->
<!--Designer: @yangcan18-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=89088668461d692ecc85a9b5fcd1dff18d08f4fe translatedAt=2026-08-01T00:30:35.750Z pushedAt=2026-08-03T03:06:38.641Z -->

This component is supported since API version 18. An arc list is a specialized list designed for circular screens. It can efficiently display information in a structured and scrollable form. For details, see [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md).

You can linearly arrange child components, [ArcListItem](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md), vertically within the [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md) component. This allows each item in the **ArcList** to have its own view. To build a complex **ArcList**, you can use [ForEach](../ui/rendering-control/arkts-rendering-control-foreach.md) to iterate over a set of list items or combine any number of individual views with the **ForEach** structure. The [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md) component supports various [rendering control](../ui/rendering-control/arkts-rendering-control-overview.md) methods, including conditional rendering, loop rendering, and lazy loading, to generate child components.

## Creating an ArcList Component

To create an [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md) component, use the following:

<!-- @[arcList_create_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListCreate.ets) -->

``` TypeScript
ArcList({
  initialIndex: 2
}) {
  ArcListItem() {
    // ···
  }
  ArcListItem() {
    // ···
  }
// ···
}
```

>**NOTE**
>
>The child components of the [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md) must be [ArcListItem](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md). [ArcListItem](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md) must be used in conjunction with [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md).

## Displaying Data in the ArcList Component

The **ArcList** component displays a collection of items vertically and provides scrolling functionality when items exceed the screen boundaries. This makes it ideal for displaying large datasets. In the simplest form of an **ArcList**, the list items, **ArcListItem**, are statically created within the **ArcList**.

<!-- @[arcListShow_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListShow.ets) -->

``` TypeScript
import { ArcList, ArcListItem, ArcListAttribute, ArcListItemAttribute, LengthMetrics } from '@kit.ArkUI';

@Entry
@Component
export struct ArcListShow {
  build() {
    NavDestination() {
      Column({ space: 12 }) {
        // ...
          ArcList({ initialIndex: 2 }) {
            ArcListItem() {
              Row() {
                Image($r('app.media.wlan')).width('99px').height('99px')
                  .borderRadius('50px').margin({ left: 7 })
                Column() {
                  Text($r('app.string.ArcListStyles_wlan')).fontSize('38px').fontColor('#FFFFFFFF')
                  Text($r('app.string.ArcListStyles_open')).fontSize('20px').fontColor('#FFFFFFFF')
                }.width('190px')

                Image($r('app.media.ic_settings_arrow')).width('92px').height('92px')
                  .borderRadius('50px')
              }
            }
            .borderRadius('65px')
            .width('414px')
            .height('129px')
            .backgroundColor('#26FFFFFF')

            ArcListItem() {
              Row() {
                Image($r('app.media.blueTooth')).width('99px').height('99px')
                  .borderRadius('50px').margin({ left: 7 })
                Column() {
                  Text($r('app.string.ArcListStyles_blue')).fontSize('38px').fontColor('#FFFFFFFF')
                  Text($r('app.string.ArcListStyles_open')).fontSize('20px').fontColor('#FFFFFFFF')
                }.width('190px')

                Image($r('app.media.ic_settings_arrow')).width('92px').height('92px')
                  .borderRadius('50px')
              }
            }
            .borderRadius('65px')
            .width('414px')
            .height('129px')
            .backgroundColor('#26FFFFFF')

            ArcListItem() {
              Row() {
                Image($r('app.media.mobileData')).width('99px').height('99px')
                  .borderRadius('50px').margin({ left: 7 })
                Column() {
                  Text($r('app.string.ArcListStyles_net')).fontSize('38px').fontColor('#FFFFFFFF')
                }.width('190px')

                Image($r('app.media.ic_settings_arrow')).width('92px').height('92px')
                  .borderRadius('50px')
              }
            }
            .borderRadius('65px')
            .width('414px')
            .height('129px')
            .backgroundColor('#26FFFFFF')

            ArcListItem() {
              Row() {
                Image($r('app.media.ic_settings_more_connections')).width('99px').height('99px')
                  .borderRadius('50px').margin({ left: 7 })
                Column() {
                  Text($r('app.string.ArcListStyles_connect')).fontSize('38px').fontColor('#FFFFFFFF')
                }.width('190px')

                Image($r('app.media.ic_settings_arrow')).width('92px').height('92px')
                  .borderRadius('50px')
              }
            }
            .borderRadius('65px')
            .width('414px')
            .height('129px')
            .backgroundColor('#26FFFFFF')

            ArcListItem() {
              Row() {
                Image($r('app.media.displayAndBrightness')).width('99px').height('99px')
                  .borderRadius('50px').margin({ left: 7 })
                Column() {
                  Text($r('app.string.ArcListStyles_light')).fontSize('38px').fontColor('#FFFFFFFF')
                }.width('190px')

                Image($r('app.media.ic_settings_arrow')).width('92px').height('92px')
                  .borderRadius('50px')
              }
            }
            .borderRadius('65px')
            .width('414px')
            .height('129px')
            .backgroundColor('#26FFFFFF')
          }
          .width('466px')
          .height('466px')
          .space(LengthMetrics.px(10))
          .borderRadius('233px')
          .backgroundColor(Color.Black)
        }
      // ...
    }
    .backgroundColor('#f1f2f3')
    // Replace $r('app.string.ArcListShow_title') with the actual resource file. In this example, the value in the resource file is "Displaying Data in ArcList."
    .title($r('app.string.ArcListShow_title'))
  }
}
```

  **Figure 1** Displaying data in the ArcList component

![arcList_item](figures/arcList_item.png)

## Iterating ArcList Content

Typically, applications dynamically create lists from data collections. Using [loop rendering](../ui/rendering-control/arkts-rendering-control-foreach.md), you can iterate over the data source to create corresponding components during each iteration, thereby reducing code complexity.

ArkTS provides component loop rendering capabilities using [ForEach](../ui/rendering-control/arkts-rendering-control-foreach.md). For example, in a simple contacts list, contact names and profile picture data are stored in a **contacts** array using a **Contact** class structure. By using [ForEach](../ui/rendering-control/arkts-rendering-control-foreach.md) with nested [ArcListItem](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md), you can replace multiple similar, flat-laid-out **ArcListItem** components, reducing redundant code and making your code more concise and efficient.

<!-- @[arcListContentsTitle_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListContents.ets) -->

``` TypeScript
import { ArcList, ArcListAttribute, ArcListItemAttribute, ArcListItem, LengthMetrics } from '@kit.ArkUI';
import { util } from '@kit.ArkTS';
import { common } from '@kit.AbilityKit';

class Contact {
  key: string = util.generateRandomUUID(true);
  name: ResourceStr;
  icon: Resource;

  constructor(name: ResourceStr, icon: Resource) {
    this.name = name;
    this.icon = icon;
  }
}

@Entry
@Component
export struct ArcListContents {
  @State private contacts: Array<object> = [
    // Replace $r('app.string.xxx') with the actual resource file.
    new Contact($r('app.string.name_xiaohong'), $r('app.media.ic_contact')),
    new Contact($r('app.string.name_xiaolan'), $r('app.media.ic_contact')),
    new Contact($r('app.string.name_xiaowang'), $r('app.media.ic_contact')),
    new Contact($r('app.string.name_xiaoli'), $r('app.media.ic_contact')),
    new Contact($r('app.string.name_xiaoming'), $r('app.media.ic_contact'))
  ];

  build() {
    NavDestination() {
      Column({ space: 12 }) {
        // ...
          ArcList({ initialIndex: 2 }) {
            ForEach(this.contacts, (item: Contact) => {
              ArcListItem() {
                Row() {
                  Image(item.icon)
                    .width(40)
                    .height(40)
                    .margin(10)
                    .backgroundColor('#FF9CC998')
                    .borderRadius(20)
                  Text(item.name).fontSize('38px').fontColor('#FFFFFFFF')
                }
                .width('100%')
                .justifyContent(FlexAlign.Start)
              }
              .borderRadius('65px')
              .width('410px')
              .height('130px')
              .backgroundColor('#26FFFFFF')
            }, (item: Contact) => JSON.stringify(item))
          }
          .space(LengthMetrics.px(10))
          .width('466px')
          .height('466px')
          .borderRadius('233px')
          .backgroundColor(Color.Black)
        }
        // ...
    }
    .backgroundColor('#f1f2f3')
    // Replace $r('app.string.ArcListContents_title') with the actual resource file. In this example, the value in the resource file is "Iterating ArcList Content."
    .title($r('app.string.ArcListContents_title'))
  }
}
```

  **Figure 2** Iterating ArcList content

![arcList_foreach](figures/arcList_foreach.png)

## Customizing the ArcList Style

### Setting a Custom Header

You can add a custom header to an ArcList using the [header](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#arklistoptions) parameter.

1. Construct the custom header component, **customHeader**.

   <!-- @[create_customHeader_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListStyles.ets) -->

   ``` TypeScript
   @Builder
   function customHeader() {
     Column() {
       Text($r('app.string.ArcListCrown_set'))
         .fontColor('#FFFFFFFF')
         .fontSize('19fp')
     }
   }
   ```

2. Wrap the custom header component. This step is required because the [header](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#arklistoptions) parameter expects a [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md) type.

   <!-- @[componentContent_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListStyles.ets) -->

   ``` TypeScript
   context: UIContext = this.getUIContext();
   arcListHeader: ComponentContent<Object> = new ComponentContent(this.context, wrapBuilder(customHeader));
   ```

3. Set the **arcListHeader** to the **ArcList** component using the [header](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#arklistoptions) parameter.

   <!-- @[arcListHeader_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListStyles.ets) -->

   ``` TypeScript
   ArcList({ header: this.arcListHeader }) {
     ArcListItem() {
       // ...
     }
     // ...
   
     ArcListItem() {
       // ...
     }
     // ...
   }
   ```

  **Figure 3** Setting a custom header

![arcList_header](figures/arcList_header.png)

### Setting the List Item Spacing

When initializing the **ArcList** component, you can use the [space](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#space) attribute to add spacing between list items. For example, to add a vertical spacing of 30 px between list items:

<!-- @[arcListSpace_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListStyles.ets) -->

``` TypeScript
ArcList({ initialIndex: 2 }) {
  // ...
}
.space(LengthMetrics.px(30))
```

  **Figure 4** Setting the list item spacing

![arcList_space](figures/arcList_space.png)

### Disabling Auto-Scaling for List Items

By default, items in an **ArcList** component automatically scale when they are near the top or bottom edges. However, in some cases, you might not want this scaling effect. To disable it, set the [autoScale](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md#autoscale) attribute of [ArcListItem](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md) to **false**. For example, as shown in Figure 5, the **Network** and **Display** list items do not scale regardless of their position after the **autoScale** attribute is disabled.

<!-- @[arcListScale_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListStyles.ets) -->

``` TypeScript
ArcListItem() {
  // ...
}
.autoScale(false)
```

  **Figure 5** Disabling auto-scaling for list items

![arcListItem_autoScale](figures/arcListItem_autoScale.png)

### Adding a Built-in Scrollbar

When the height of the list items exceeds the screen height, the **ArcList** component can scroll vertically. To help users quickly navigate, a scrollbar can be provided to allow rapid scrolling through the list, as shown in Figure 6.

When using the [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md) component, you can control the display of the scrollbar using the [scrollBar](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#scrollbar) attribute. The value of **scrollBar** is of type [BarState](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#barstate). When set to **BarState.Auto**, the scrollbar is displayed as needed. In this mode, the scrollbar appears when the user touches the scrollbar area, allowing for up and down dragging to quickly scroll through the content. The scrollbar also thickens during dragging for better visibility. If the user takes no action, the scrollbar automatically disappears after 2 seconds. You can customize the scrollbar style, using the [scrollBarWidth](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#scrollbarwidth) attribute to set its width in the pressed state and the [scrollBarColor](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#scrollbarcolor) attribute to set its color.

<!-- @[arcListBuiltInScrollBar_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/arcListBuiltInScrollerBar.ets) -->

``` TypeScript
ArcList({ header: this.arcListHeader }) {
  // ...
}
.scrollBar(BarState.Auto)
.scrollBarWidth(LengthMetrics.px(10))
.scrollBarColor(ColorMetrics.numeric(Color.White))
```

  **Figure 6** Built-in scrollbar of the ArcList component

![arcList_scrollBar](figures/arcList_scrollBar.gif)

## Adding an External Scrollbar: ArcScrollBar

To add an external scrollbar to an [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md), you can use the [ArcScrollBar](../reference/apis-arkui/arkui-ts/ts-basic-components-arcscrollbar.md) component. By binding both the **List** and **ScrollBar** components to the same [Scroller](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scroller) object, you can ensure they stay synchronized.

1. Create a [Scroller](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scroller) object named **arcListScroller**.

   <!-- @[create_arcListScroller_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListAcrScrollBar.ets) -->

   ``` TypeScript
   private arcListScroller: Scroller = new Scroller();
   ```

2. Bind the **arcListScroller** object to the **ArcList** component using the [scroller](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#arklistoptions) parameter.

   <!-- @[bind_arcList_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListAcrScrollBar.ets) -->

   ``` TypeScript
   // Use arcListScroller to initialize the scroller parameter to bind it with the ArcList component.
   ArcList({ scroller: this.arcListScroller, header: this.arcListHeader }) {
     // ...
   }
   ```

3. Bind the **arcListScroller** object to the **ArcScrollBar** component using the [scroller](../reference/apis-arkui/arkui-ts/ts-basic-components-arcscrollbar.md#arcscrollbaroptions) parameter.

   <!-- @[bind_arcScrollBar_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListAcrScrollBar.ets) -->

   ``` TypeScript
   // Use arcListScroller to initialize the scroller parameter to bind it with the ArcScrollBar component.
   ArcScrollBar({ scroller: this.arcListScroller })
   ```

  **Figure 7** External scrollbar of the ArcList component

![arcScrollBar](figures/arcScrollBar.gif)

>**NOTE**
>
>The [ArcScrollBar](../reference/apis-arkui/arkui-ts/ts-basic-components-arcscrollbar.md) component can also be used with other scrollable components such as [List](../reference/apis-arkui/arkui-ts/ts-container-list.md), [Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md), [Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md), and [WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md).

## Interacting with ArcAlphabetIndexer

Applications often need to monitor changes in the scroll position of a list and respond accordingly, or quickly navigate to specific sections by adjusting the scroll position. For example, in a contacts list, as the list scrolls through different sections (for example, from "A" to "B"), the external index bar should update to reflect the current letter. When a user selects an index item (for example, "C"), the list should jump to the corresponding section. To achieve this functionality, you can use the [ArcAlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-arc-alphabet-indexer.md) component.

As shown in Figure 8, when the list scrolls from contacts starting with "A" to those starting with "B," the external index bar should also update from the selected "A" state to the selected "B" state. This can be achieved by listening for the [onScrollIndex](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#onscrollindex) event of the [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md) component. When an index item "C" is clicked, the list should jump to the contacts starting with "C." This can be achieved by listening for the [onSelect](../reference/apis-arkui/arkui-ts/ts-container-arc-alphabet-indexer.md#onselect) event of the [ArcAlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-arc-alphabet-indexer.md) component.

During list scrolling, the corresponding letter position **indexerIndex** in the alphabet index bar is recalculated based on the current index position **centerIndex** of the list. Since the [ArcAlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-arc-alphabet-indexer.md) component sets the selected item index through the [selected](../reference/apis-arkui/arkui-ts/ts-container-arc-alphabet-indexer.md#selected) attribute, a change in **indexerIndex** triggers the [ArcAlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-arc-alphabet-indexer.md) component to re-render, thereby displaying the corresponding letter in the selected state.

When an index item is selected, the selected item index (**index**) is used to recalculate the corresponding position in the list. The list is then scrolled to that position using the [scrollToIndex](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scrolltoindex) API of the bound scroll controller (**arcListScroller**). The [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md) component can be bound to a [Scroller](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scroller) (scroll controller) object using the [scroller](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#arklistoptions) parameter.

<!-- @[arcAlphabetIndexer_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListArcIndexerBar.ets) -->

``` TypeScript
import { ArcList, ArcListAttribute, ArcListItemAttribute, ArcListItem, LengthMetrics } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

// ...
const alphabets: string[] = [
  '#', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
];

@Entry
@Component
export struct ArcListArcIndexerBar {

  // ...
  // Index of the selected item in the index bar
  @State indexerIndex: number = 0;
  // Scroll controller bound to the list
  private arcListScroller: Scroller = new Scroller();

  // ...

  build() {
    // ...
          Stack({alignContent: Alignment.End}) {
            ArcList({ initialIndex: 0, header:this.tabBar1, scroller:this.arcListScroller }) {
              // ...
            }
            // ...
            .onScrollIndex((firstIndex: number, lastIndex: number, centerIndex: number) => {
              // Recalculate the position of the corresponding index bar this.indexerIndex based on the index value to which the list scrolls.
              let contact = this.contacts[centerIndex] as Contact;
              let firstChar = contact.firstChar;
              this.indexerIndex = alphabets.indexOf(firstChar);
            })
            // ...
            // ArcAlphabetIndexer component
            ArcAlphabetIndexer({ arrayValue: alphabets, selected: this.indexerIndex})
              .selected(this.indexerIndex!!)
              .onSelect((index: number) => {
                // Scroll the list to the corresponding position when an index item is selected.
                this.indexerIndex = index;
                const selectedLetter = alphabets[index];
                let targetIndex = -1;
                for (let i = 0; i < this.contacts.length; i++) {
                  const contact = this.contacts[i] as Contact;
                  if (contact.firstChar === selectedLetter) {
                    targetIndex = i;
                    break;
                  }
                }
                if (targetIndex >= 0) {
                  this.arcListScroller.scrollToIndex(targetIndex);
                }
              })
              // ...
          }
          // ...
  }
}
```

  **Figure 8** Interaction between the ArcList and ArcAlphabetIndexer

![arcAlphabetIndexer](figures/arcAlphabetIndexer.gif)

## Responding to Swipe on List Items

To enable swipe gestures on list items in the [ArcListItem](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md) component, you can use the [swipeAction](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md#swipeaction) attribute of **ArcListItem**. This attribute requires a [SwipeActionOptions](../reference/apis-arkui/arkui-ts/ts-container-listitem.md#swipeactionoptions9) object with **start** and **end** parameters. Here, **start** defines the swipe action item displayed on the start edge of the list item when the item is swiped right, while **end** defines the swipe action item displayed on the end edge of the list item when the item is swiped left.

In the contact list, the **end** parameter specifies the custom component that slides out from the end edge when an [ArcListItem](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md) is swiped left, that is, the delete button. When initializing the **end** method, the index of the swiped list item is passed to the delete button component. When the user taps the delete button, the data corresponding to the list item can be removed based on the data index, thereby implementing the swipe-to-delete feature.

1. Build the component that appears from the end edge when the list item is swiped left.

   <!-- @[create_SideSlip_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListSideSlip.ets) -->

   ``` TypeScript
   @Builder
   itemEnd(item: Contact) {
     // Build the component that appears from the end edge when the list item is swiped left.
     Button({ type: ButtonType.Circle }) {
       Image($r('app.media.ic_public_delete_filled'))
         .width(20)
         .height(20)
     }
     .width(20)
     .height(20)
     .backgroundColor(Color.Black)
     .onClick(() => {
       this.getUIContext()?.animateTo({
         duration: 1000,
         curve: Curve.Smooth,
         iterations: 1,
         playMode: PlayMode.Normal,
       }, () => {
         // this.contacts is the data source. The indexOf API obtains the index of the item to be deleted.
         let index = this.contacts.indexOf(item);
         // Remove the specified data item from the data source.
         this.contacts.splice(index, 1);
       })
     })
   }
   ```

2. Bind the [swipeAction](../reference/apis-arkui/arkui-ts/ts-container-arclistitem.md#swipeaction) attribute to the **ArcListItem** that can be swiped left.

   <!-- @[bind_swipeAction_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListSideSlip.ets) -->

   ``` TypeScript
   // When constructing an ArcList component, use ForEach to render list items based on the data source this.contacts.
   ArcListItem() {
   // ···
   }
   .swipeAction({
     end: {
       // index is the index of the arc list item.
       builder: () => {
         this.itemEnd(item);
       },
     }
   }) // Set the swipe action.
   ```

  **Figure 9** Swipe-to-delete feature

![arcListItem_swipeAction](figures/arcListItem_swipeAction.gif)

## Handling Long Lists

While [ForEach](../ui/rendering-control/arkts-rendering-control-foreach.md) is suitable for short lists, using it for long lists with a large number of items can significantly slow down page loading, as it loads all items at once. Therefore, for better list performance, use [LazyForEach](../ui/rendering-control/arkts-rendering-control-lazyforeach.md) instead to implement on-demand iterative data loading. For details about the implementation, see the example in [LazyForEach: Lazy Data Loading](../ui/rendering-control/arkts-rendering-control-lazyforeach.md).

When the list is rendered in lazy loading mode, to improve the list scrolling experience and minimize white blocks during list scrolling, you can use the [cachedCount](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#cachedcount) attribute of the [ArcList](../reference/apis-arkui/arkui-ts/ts-container-arclist.md) component. This attribute sets the number of cached list items and is valid only in [LazyForEach](../ui/rendering-control/arkts-rendering-control-lazyforeach.md).

<!-- @[arcLongList_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcLongList.ets) -->

``` TypeScript
ArcList() {
  // ···
}.cachedCount(3)
```

>**NOTE**
>
>- A greater **cachedCount** value may result in higher CPU and memory overhead of the UI. Adjust it based on actual scenarios, balancing performance and user experience.
>
>- When data lazy loading is used in the list, list items other than those in the display area and the cached items before and after will be destroyed.

## Responding to Digital Crown Rotations

On wearable devices, the **ArcList** component can respond to digital crown rotations when it is in focus. Users can scroll through the list items by rotating the crown. To make the **ArcList** the default focus on the page and enable it to respond to crown rotations, you can use the following [focus control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md) attributes:

<!-- @[arcListCrown_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListCrown.ets) -->

``` TypeScript
ArcList({
  initialIndex: 2,
}) {
// ···
}
// Enable focus for the ArcList component.
.focusable(true)
// Allow the ArcList component to gain focus on touch.
.focusOnTouch(true)
// Set the ArcList component as the default focus on the page.
.defaultFocus(true)
```

You can also adjust the sensitivity of the digital crown response using the [digitalCrownSensitivity](../reference/apis-arkui/arkui-ts/ts-container-arclist.md#digitalcrownsensitivity) attribute. This allows you to fine-tune the responsiveness based on the amount of data in the list. For lists with more items, you might want to increase the sensitivity, while for lists with fewer items, you can decrease it.

<!-- @[arcListCrownDigitalCrownSensitivity_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ScrollableComponent/entry/src/main/ets/pages/arcList/ArcListCrown.ets) -->

``` TypeScript
ArcList({
  initialIndex: 2,
}) {
// ···
}
// ···
.digitalCrownSensitivity(CrownSensitivity.MEDIUM)
```