# CheckboxGroup

The **\<CheckboxGroup>** component is used to select or deselect all check boxes in a group.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

CheckboxGroup(options?: { group?: string })

Creates a check box group so that you can select or deselect all check boxes in the group at the same time. Check boxes and the check box group that share the group name belong to the same group.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| group | string | No| Group name.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| selectAll | boolean | Whether to select all.<br>Default value: **false**|
| selectedColor | [ResourceColor](ts-types.md#resourcecolor) | Color of the selected check box.|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name| Description|
| -------- | -------- |
| onChange (callback: (event: CheckboxGroupResult) => void ) |Triggered when the selection status of the check box group or any check box wherein changes.|

## CheckboxGroupResult
| Name    | Type  | Description     |
| ------ | ------ | ------- |
| name   | Array&lt;string&gt; | Names of all the selected check boxes in the group.|
| status | SelectStatus | Selected status.|

## SelectStatus

| Name | Description|
| ----- | -------------------- |
| All   | All check boxes in the group are selected.|
| Part  | Some check boxes in the group are selected.|
| None  | None of the check boxes in the group are selected.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct CheckboxExample {
  build() {
    Scroll() {
      Column() {
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          CheckboxGroup({ group: 'checkboxGroup' })
            .selectedColor(0xed6f21)
            .onChange((itemName: CheckboxGroupResult) => {
              console.info("TextPicker::dialogResult is" + JSON.stringify(itemName))
            })
          Text('select all').fontSize(20)
        }

        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
            .select(true)
            .selectedColor(0x39a2db)
            .onChange((value: boolean) => {
              console.info('Checkbox1 change is' + value)
            })
          Text('Checkbox1').fontSize(20)
        }

        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          Checkbox({ name: 'checkbox2', group: 'checkboxGroup' })
            .select(false)
            .selectedColor(0x39a2db)
            .onChange((value: boolean) => {
              console.info('Checkbox2 change is' + value)
            })
          Text('Checkbox2').fontSize(20)
        }

        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          Checkbox({ name: 'checkbox3', group: 'checkboxGroup' })
            .select(true)
            .selectedColor(0x39a2db)
            .onChange((value: boolean) => {
              console.info('Checkbox3 change is' + value)
            })
          Text('Checkbox3').fontSize(20)
        }
      }
    }
  }
}
```
![](figures/checkboxgroup.gif)
