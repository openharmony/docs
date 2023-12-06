# $$ Syntax: Two-Way Synchronization of Built-in Components


The $$ operator provides a TS variable by-reference to a built-in component so that the variable value and the internal state of that component are kept in sync.


What the internal state is depends on the component. For example, for the [\<Refresh>](../reference/arkui-ts/ts-container-refresh.md) component, it is the **refreshing** parameter.


## Rules of Use

- $$ supports variables of simple types and variables decorated by **\@State**, **\@Link**, or **\@Prop**.

- Currently, $$ supports only the **refreshing** parameter of the [\<Refresh>](../reference/arkui-ts/ts-container-refresh.md) component.

- When the variable bound to $$ changes, the UI is re-rendered synchronously.


## Example

This example uses the **refreshing** parameter of the [\<Refresh>](../reference/arkui-ts/ts-container-refresh.md) component.

When the **isRefreshing** variable is bound to $$, it changes to **true** when the page is pulled down,

and the change is synced to **Text**. If the variable is not bound to $$, the change will not be synced.


```ts
// xxx.ets
@Entry
@Component
struct RefreshExample {
  @State isRefreshing: boolean = false
  @State counter: number = 0

  build() {
    Column() {
      Text('Pull Down and isRefreshing: ' + this.isRefreshing)
        .fontSize(30)
        .margin(10)

      Refresh({ refreshing: $$this.isRefreshing, offset: 120, friction: 100 }) {
        Text('Pull Down and refresh: ' + this.counter)
          .fontSize(30)
          .margin(10)
      }
      .onStateChange((refreshStatus: RefreshStatus) => {
        console.info('Refresh onStatueChange state is ' + refreshStatus)
      })
    }
  }
}
```


![](figures/refersh.gif)
