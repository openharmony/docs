# CheckboxGroup

> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The **\<CheckboxGroup>** component is used to select or deselect all check boxes in a group.

## Required Permissions

None

## Child Components

None

## APIs

CheckboxGroup( group?: string )

Creates a check box group so that you can select or deselect all check boxes in the group at the same time. Check boxes and the check box group that share the group name belong to the same group.

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | group | string | No| - | Group name.|


## Attributes

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| selectAll | bool | false | Whether to select all.|
| selectedColor | Color | - | Color of the selected check box.|

## Events

| Name| Description|
| -------- | -------- |
| onChange (callback: (names: Array&lt;string&gt;, status: SelectStatus) => void ) |Triggered when the selection status of the check box group or any check box wherein changes.<br>- **names**: names of all selected check boxes in the group.<br>- **status**: selection status.|

- SelectStatus enums
  | Name | Description|
  | ----- | -------------------- |
  | All   | All check boxes in the group are selected.|
  | Part  | Some check boxes in the group are selected.|
  | None  | None of the check boxes in the group are selected.|


## Example

```
@Entry
@Component
struct CheckboxExample {

  build() {
    Scroll() {
      Column() {
        CheckboxGroup({group : 'checkboxGroup'})
          .selectedColor(0xed6f21)
          .onChange((itemName:CheckboxGroupResult) => {
            console.info("TextPicker::dialogResult is" + JSON.stringify(itemName))
          })
        Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
          .select(true)
          .selectedColor(0x39a2db)
          .onChange((value: boolean) => {
            console.info('Checkbox1 change is' + value)
          })
        Checkbox({ name: 'checkbox2', group: 'checkboxGroup' })
          .select(false)
          .selectedColor(0x39a2db)
          .onChange((value: boolean) => {
            console.info('Checkbox2 change is' + value)
          })
        Checkbox({ name: 'checkbox3', group: 'checkboxGroup' })
          .select(true)
          .selectedColor(0x39a2db)
          .onChange((value: boolean) => {
            console.info('Checkbox3 change is' + value)
          })
      }
    }
  }
}
```
![](figures/checkboxgroup.gif)
