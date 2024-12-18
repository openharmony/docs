# ListItemGroup

The **\<ListItemGroup>** component is used to display list item groups. It must be used with the **[\<List>](ts-container-list.md)** component and, if not otherwise specified, takes up the entire width of the **\<List>**.

> **NOTE**
>
> - This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
> - This component can be used only as a child of [List](ts-container-list.md).
> - The **\<ListItemGroup>** component does not support the universal attribute [aspectRatio](ts-universal-attributes-layout-constraints.md).
> - If the parent **List** component of **\<ListItemGroup>** has its **listDirection** attribute set to **Axis.Vertical**, setting the [universal attribute height](ts-universal-attributes-size.md) has no effect. In this case, the height of the **\<ListItemGroup>** component is fixed at the sum of the component's header height, footer height, and total height of the list items.
> - If the parent **List** component of **\<ListItemGroup>** has its **listDirection** attribute set to **Axis.Horizontal**, setting the [universal attribute width](ts-universal-attributes-size.md) has no effect. In this case, the width of the **\<ListItemGroup>** component is fixed at the sum of the component's header width, footer width, and total width of the list items.
> - The list items in the **\<ListItemGroup>** component cannot be edited or dragged. This means that their **editable** attribute does not take effect.

## Child Components

This component supports the **[\<ListItem>](ts-container-listitem.md)** child component.


## APIs

ListItemGroup(options?: ListItemGroupOptions)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options |  [ListItemGroupOptions](#listitemgroupoptions)| No| Parameters of the list item group.|

## ListItemGroupOptions

| Name             | Type                                           | Mandatory| Description                                                    |
| ------------------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| header              | [CustomBuilder](ts-types.md#custombuilder8)         | No  | Header of the list item group.<br>**NOTE**<br>Only one child component can be placed.                                 |
| footer              | [CustomBuilder](ts-types.md#custombuilder8)         | No  | Footer of the list item group.<br>**NOTE**<br>Only one child component can be placed.                                 |
| space               | number \| string                          | No  | Spacing between list items. This parameter is valid only between list items, but not between the header and list item or between the footer and list item.|
| style<sup>10+</sup> | [ListItemGroupStyle](#listitemgroupstyle10) | No  | Style of the list item group.<br>Default value: **ListItemGroupStyle.NONE**<br>If this parameter is set to **ListItemGroupStyle.NONE**, no style is applied.<br>When **ListItemGroupStyle.CARD** is used, you are advised to pair it with **ListItemStyle.CARD** from [ListItem](ts-container-listitem.md) to apply the default card style.<br>In the card style, the default specifications for the **\<ListItemGroup>** are as follows: horizontal margin of 12 vp on both left and right sides, and vertical as well as horizontal padding of 4 vp.<br>In the default card style, list items can be in focus, hover, press, selected, or disable style depending on their state.<br>**NOTE**<br>In the card style, by default, the list runs along the vertical axis, that is, **listDirection** is at **Axis.Vertical**. If **listDirection** is set to **Axis.Horizontal**, a disordered display may result. The **alignListItem** attribute of the list is set to **ListItemAlign.Center** by default, which aligns the list items in the center.|

## Attributes

| Name| Type|  Description|
| -------- | -------- | -------- |
| divider | {<br>strokeWidth: [Length](ts-types.md#length),<br>color?: [ResourceColor](ts-types.md#resourcecolor),<br>startMargin?: [Length](ts-types.md#length),<br>endMargin?: [Length](ts-types.md#length)<br>} \| null | Style of the divider for the list items. By default, there is no divider.<br>- **strokeWidth**: stroke width of the divider.<br>- **color**: color of the divider.<br>- **startMargin**: distance between the divider and the start of the list.<br>- **endMargin**: distance between the divider and the end of the list.<br>**strokeWidth**, **startMargin**, and **endMargin** cannot be set in percentage.|

## ListItemGroupStyle<sup>10+</sup>

| Name| Value | Description              |
| ---- | ---- | ------------------ |
| NONE | 0 | No style.          |
| CARD | 1 | Default card style.|



## Example

### Example 1

```ts
// xxx.ets
@Entry
@Component
struct ListItemGroupExample {
  private timeTable: TimeTable[] = [
    {
      title: 'Monday',
      projects: ['Language', 'Math', 'English']
    },
    {
      title: 'Tuesday',
      projects: ['Physics', 'Chemistry', 'Biologics']
    },
    {
      title: 'Wednesday',
      projects: ['History', 'Geography', 'Politics']
    },
    {
      title: 'Thursday',
      projects: ['Art', 'Music', 'Sports']
    }
  ]

  @Builder
  itemHead(text: string) {
    Text(text)
      .fontSize(20)
      .backgroundColor(0xAABBCC)
      .width("100%")
      .padding(10)
  }

  @Builder
  itemFoot(num: number) {
    Text('Total lessons: ' + num)
      .fontSize(16)
      .backgroundColor(0xAABBCC)
      .width("100%")
      .padding(5)
  }

  build() {
    Column() {
      List({ space: 20 }) {
        ForEach(this.timeTable, (item: TimeTable) => {
          ListItemGroup({ header: this.itemHead(item.title), footer: this.itemFoot(item.projects.length) }) {
            ForEach(item.projects, (project: string) => {
              ListItem() {
                Text(project)
                  .width("100%")
                  .height(100)
                  .fontSize(20)
                  .textAlign(TextAlign.Center)
                  .backgroundColor(0xFFFFFF)
              }
            }, (item: string) => item)
          }
          .divider({ strokeWidth: 1, color: Color.Blue }) // Divider between lines
        })
      }
      .width('90%')
      .sticky(StickyStyle.Header | StickyStyle.Footer)
      .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}

interface TimeTable {
  title: string;
  projects: string[];
}
```

![en-us_image_0000001219864159](figures/en-us_image_listitemgroup.gif)

### Example 2

```ts
// xxx.ets
@Entry
@Component
struct ListItemGroupExample2 {
  private arr: ArrObject[] = [
    {
      style: ListItemGroupStyle.CARD,
      itemStyles: [ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.CARD]
    },
    {
      style: ListItemGroupStyle.CARD,
      itemStyles: [ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.NONE]
    },
    {
      style: ListItemGroupStyle.CARD,
      itemStyles: [ListItemStyle.CARD, ListItemStyle.NONE, ListItemStyle.CARD]
    },
    {
      style: ListItemGroupStyle.NONE,
      itemStyles: [ListItemStyle.CARD, ListItemStyle.CARD, ListItemStyle.NONE]
    }
  ]

  build() {
    Column() {
      List({ space: "4vp", initialIndex: 0 }) {
        ForEach(this.arr, (item: ArrObject, index?: number) => {
          ListItemGroup({ style: item.style }) {
            ForEach(item.itemStyles, (itemStyle: number, itemIndex?: number) => {
              ListItem({ style: itemStyle }) {
                if (index != undefined && itemIndex != undefined) {
                  Text("Item" + (itemIndex + 1) +" in group" + (index + 1) +" ")
                    .width("100%")
                    .textAlign(TextAlign.Center)
                }
              }
            }, (item: string) => item)
          }
        })
      }
      .width('100%')
      .multiSelectable(true)
      .backgroundColor(0xDCDCDC)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}

interface ArrObject {
  style: number;
  itemStyles: number[];
}
```
![ListItemGroupStyle](figures/listItemGroup2.jpeg)
