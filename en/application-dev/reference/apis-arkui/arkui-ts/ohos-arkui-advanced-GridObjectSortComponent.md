# GridObjectSortComponent


**GridObjectSortComponent** is a grid object organizer that you can use to edit, drag to sort, add, and delete grid objects.


>  **NOTE**
>
>  This component is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { GridObjectSortComponent, GridObjectSortComponentItem, GridObjectSortComponentOptions, GridObjectSortComponentType } from '@kit.ArkUI'
```

##  Child Components

Not supported

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are supported.

## GridObjectSortComponent

GridObjectSortComponent({options: GridObjectSortComponentOptions, dataList: Array\<GridObjectSortComponentItem>, onSave: (select: Array\<GridObjectSortComponentItem>, unselect: Array\<GridObjectSortComponentItem>) => void, onCancel: () => void })

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**


| Name    | Type                            | Decorator| Mandatory| Description        |
| -------- | -------------------------------- | ---------- | ---- | ------------ |
| options  | [GridObjectSortComponentOptions](#gridobjectsortcomponentoptions) | @Prop      | Yes  | Component configuration.|
| dataList | Array<[GridObjectSortComponentItem](#gridobjectsortcomponentitem)> | -     | Yes  | Data to pass. The maximum data length is 50 characters. If it is exceeded, only the first 50 characters are used.|
| onSave | (select: Array<[GridObjectSortComponentItem](#gridobjectsortcomponentitem)>, unselect: Array<[GridObjectSortComponentItem](#gridobjectsortcomponentitem)>)  => void | - | Yes| Callback invoked when changes are saved. The data after the changes is returned.|
| onCancel | () => void | - | Yes| Callback invoked when changes are canceled.|

##  GridObjectSortComponentOptions

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name          | Type                     | Mandatory| Description                                                  |
| -------------- | ------------------------- | ---- | ------------------------------------------------------ |
| type           | [GridObjectSortComponentType](#gridobjectsortcomponenttype) | No  | Component display form: text only or\|text and imagery.<br>Default value: **GridObjectSortComponentType.text**|
| imageSize      | number \| [Resource](ts-types.md#resource) | No  | Image size.<br>Default value: **56**                         |
| normalTitle | [ResourceStr](ts-types.md#resourcestr)     | No  | Title displayed in the non-editing state.<br>Default value: **Channel**           |
| showAreaTitle | [ResourceStr](ts-types.md#resourcestr)     | No  | First subtitle of the display area.<br>Default value: **Drag to sort**|
| addAreaTitle | [ResourceStr](ts-types.md#resourcestr)     | No  | Second subtitle of the display area.<br>Default value: **Touch to add**           |
| editTitle      | [ResourceStr](ts-types.md#resourcestr)     | No  | Title displayed in the editing state.<br>Default value: **Edit**            |

## GridObjectSortComponentType 

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name    | Value   | Description          |
| -------- | ----- | -------------- |
| IMAGE_TEXT | 'image_text' | Text and imagery.|
| TEXT     | 'text'       | Text only.    |

## GridObjectSortComponentItem

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name    | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| id       | string \| number                       | Yes  | Data ID, which must be unique.                                      |
| text     | [ResourceStr](ts-types.md#resourcestr) | Yes  | Text information.                                              |
| selected | boolean                                | Yes  | Whether the grid object has been added. The value **true** means that grid object has been added, and **false** means the opposite.                 |
| url      | [ResourceStr](ts-types.md#resourcestr) | No  | URL of the image. This parameter is required when **GridObjectSortComponentType** is set to **IMAGE_TEXT**.|
| order    | number                                 | Yes  | Sequence number.                                                  |

##  Events

The [universal events](ts-universal-events-click.md) are not supported.

## Example

```ts
import { GridObjectSortComponent, GridObjectSortComponentItem, GridObjectSortComponentOptions, GridObjectSortComponentType } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State dataList: GridObjectSortComponentItem[] = [
    {
      id: 0,
      url: $r('app.media.ic_controlcenter_location_filled'),
      text: 'Location',
      selected: true,
      order: 3
    },
    {
      id: 1,
      url: $r('app.media.ic_controlcenter_mobiledata_filled'),
      text: 'Mobile data',
      selected: true,
      order: 9
    },
    {
      id: 2,
      url: $r('app.media.ic_controlcenter_nfc_filled'),
      text: 'NFC',
      selected: false,
      order: 1
    },
    {
      id: 3,
      url: $r('app.media.ic_controlcenter_ring_off_filled'),
      text: 'Silent',
      selected: true,
      order: 4
    },
    {
      id: 4,
      url: $r('app.media.ic_controlcenter_ring_on_filled'),
      text: 'Ring',
      selected: false,
      order: 5
    },
    {
      id: 5,
      url: $r('app.media.ic_controlcenter_ultra_power_saver_filled'),
      text: 'Low power',
      selected: true,
      order: 6
    },
    {
      id: 6,
      url: $r('app.media.ic_controlcenter_screenshot_filled'),
      text: 'Screenshot',
      selected: true,
      order: 7
    },
    {
      id: 7,
      url: $r('app.media.ic_controlcenter_screen_recording_filled'),
      text: 'Screen recording',
      selected: true,
      order: 8
    },
    {
      id: 8,
      url: $r('app.media.ic_controlcenter_super_power_saver_filled'),
      text: 'Ultra power saving',
      selected: false,
      order: 9
    },
  ]

  @State option: GridObjectSortComponentOptions = {
    type: GridObjectSortComponentType.IMAGE_TEXT,
    imageSize: 45,
    normalTitle: 'Menu',
    editTitle: 'Edit',
    showAreaTitle: 'Drag to sort',
    addAreaTitle: 'Touch to add'
  }

  build() {
    Column() {
      GridObjectSortComponent({
        options: this.option,
        dataList: this.dataList,
        onSave: (
          select: Array<GridObjectSortComponentItem>,
          unselect: Array<GridObjectSortComponentItem>
        ) => {
          // save ToDo
        },
        onCancel: () =>{
          // cancel ToDo
        }
      })
    }
  }
}
```

![GridObjectSortComponent](figures/GridObjectSortComponent.gif)
