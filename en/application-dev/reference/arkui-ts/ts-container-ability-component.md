# AbilityComponent

**\<AbilityComponent>** is a container for independently displaying an ability.

>  **NOTE**
>
>  This component is supported since API version 9.
>
>  The APIs of this module are system APIs and cannot be called by third-party applications.


## Constraints

Using **\<AbilityComponent>** requires a signature and related permissions.

**\<AbilityComponent>** is rendered independently and cannot be overlaid with other display content.

**\<AbilityComponent>** cannot process input events. Events are directly distributed to the internal ability for processing without passing through the current ability.

Only width and height can be set for **\<AbilityComponent>**. These attributes are mandatory and cannot be dynamically updated.

The ability to be started must be resizeable.

The ability to start must be set not to display on the recent tasks screen.

## Required Permissions

ohos.permission.INFUSE_EVENTS

ohos.permission.CONTROL_ABILITY_STACKS

ohos.permission.INTEGRATED_ABILITY

ohos.permission.INTEGRATED_INTERIOR_WINDOW


## Child Components

Not supported


## APIs

AbilityComponent(value: {want : Want})

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | want | [Want](../../reference/apis/js-apis-application-Want.md) | Yes| - | Description of the default ability to load.|


## Events

| Name| Description|
| -------- | -------- |
| onConnect()&nbsp;=&gt;&nbsp;void | Called when this **\<AbilityComponent>** is started. You can then use APIs in the **\<AbilityComponent>**.|
| onDisconnect()&nbsp;=&gt;&nbsp;void | Called when this **\<AbilityComponent>** is destroyed.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct MyComponent {

  build() {
      Column() {
          AbilityComponent({
              want: {
                  bundleName: '',
                  abilityName: ''
              },
          })
          .onConnect(() => {
              console.log('AbilityComponent connect');
          })
          .onDisconnect(() => {
              console.log('AbilityComponent disconnect');
          })
      }
  }
}
```
