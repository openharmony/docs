# $$ Syntax: Two-Way Synchronization of Built-in Components


The $$ operator provides a TS variable by-reference to a built-in component so that the variable value and the internal state of that component are kept in sync.


What the internal state is depends on the component. For example, for the [bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md) attribute method, it is the **show** parameter.


## Rules of Use

- $$ supports variables of simple types and variables decorated by **\@State**, **\@Link**, or **\@Prop**.

- Currently, $$ supports only the **show** parameter of the [bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md) attribute method, the **checked** attribute of the [\<Radio>](../reference/arkui-ts/ts-basic-components-radio.md) component, and the **refreshing** parameter of the [\<Refresh>](../reference/arkui-ts/ts-container-refresh.md) component.

- When the variable bound to $$ changes, the UI is re-rendered synchronously.


## Example

This example uses the **show** parameter of the [bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md) attribute method.


```ts
// xxx.ets
@Entry
@Component
struct bindPopupPage {
  @State customPopup: boolean = false;

  build() {
    Column() {
      Button('Popup')
        .margin(20)
        .onClick(() => {
          this.customPopup = !this.customPopup
        })
        .bindPopup($$this.customPopup, {
          message: 'showPopup'
        })
    }
  }
}
```


![popup](figures/popup.gif)
