# Checkbox

The **\<Checkbox>** component is used to enable or disable an option.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

Checkbox(options?: {name?: string,  group?: string })

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name | Type| Mandatory | Description|
| --------| --------| ------ | -------- |
| name    | string | No| Name of the check box.|
| group   | string | No| Group name of the check box.<br>**NOTE**<br>If not used with the **\<CheckboxGroup>** component, this parameter is invalid.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.


| Name         | Type| Description|
| ------------- | ------- | -------- |
| select        | boolean | Whether the check box is selected.<br>Default value: **false**<br>Since API version 9, this API is supported in ArkTS widgets.|
| selectedColor | [ResourceColor](ts-types.md#resourcecolor) | Color of the check box when it is selected.<br>Since API version 9, this API is supported in ArkTS widgets.|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following attributes are supported.

| Name                                        | Description                                                    |
| -------------------------------------------- | ------------------------------------------------------------ |
| onChange(callback: (value: boolean) => void) | Triggered when the selected status of the check box changes.<br>- The value **true** means that the check box is selected.<br>- The value **false** means that the check box is not selected.<br>Since API version 9, this API is supported in ArkTS widgets. |

## Example

```ts
// xxx.ets
@Entry
@Component
struct CheckboxExample {

  build() {
    Row() {
      Checkbox({name: 'checkbox1',  group: 'checkboxGroup'})
        .select(true)
        .selectedColor(0xed6f21)
        .onChange((value: boolean) => {
          console.info('Checkbox1 change is'+ value)
        })
      Checkbox({name: 'checkbox2',  group: 'checkboxGroup'})
        .select(false)
        .selectedColor(0x39a2db)
        .onChange((value: boolean) => {
          console.info('Checkbox2 change is'+ value)
        })
    }
  }
}
```


![](figures/checkbox.gif)
