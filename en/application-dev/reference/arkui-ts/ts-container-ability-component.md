# AbilityComponent

>  **NOTE**
>
>  This component is supported since API version 9.
>
>  The APIs of this module are system APIs and cannot be called by third-party applications.


**\<AbilityComponent>** is a container for independently displaying an ability.

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

AbilityComponent(value: {want : Want, controller? : AbilityController})

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | want | [Want](../../reference/apis/js-apis-application-Want.md) | Yes| - | Description of the default ability to load.|
  | controller | [AbilityController](#abilityController) | No| - | Ability controller.|


## Events

| Name| Description|
| -------- | -------- |
| onReady()&nbsp;=&gt;&nbsp;void | Called when this **\<AbilityComponent>** is started. You can then use APIs in the **\<AbilityComponent>**.|
| onDestroy()&nbsp;=&gt;&nbsp;void | Called when this **\<AbilityComponent>** is destroyed.|
| onAbilityCreated(name:&nbsp;string)&nbsp;=&gt;&nbsp;void | Called when the specified ability is loaded.|
| onAbilityMoveToFont()&nbsp;=&gt;&nbsp;void               | Called when this ability is moved to the foreground.|
| onAbilityWillRemove()&nbsp;=&gt;&nbsp;void | Called when this ability is about to be removed.|

## AbilityController

Implements an ability controller, which provides the control APIs for **\<AbilityComponent>**.

| Name                                   | Description                                                    |
| --------------------------------------- | ------------------------------------------------------------ |
| startAbility()&nbsp;=&gt;&nbsp;want     | Loads an ability inside the **\<AbilityComponent>**.<br>**want**: description of the ability to be loaded.|
| preformBackPress()&nbsp;=&gt;&nbsp;void | Performs a return operation inside the **\<AbilityComponent>**.                        |
| getStackCount()&nbsp;=&gt;&nbsp;void    | Obtains the number of tasks in the internal task stack of the **\<AbilityComponent>**.                |


## Example

```ts
// xxx.ets
@Entry
@Component
struct MyComponent {
 @State controller: AbilityController = new AbilityController()

  build() {
      Column() {
          AbilityComponent({
              want: {
                  bundleName: '',
                  abilityName: ''
              },
              controller: this.controller
          })
          .onReady(() => {
              console.log('AbilityComponent ready');
          })
          .onDestory(() => {
              console.log('AbilityComponent destory');
          })
          Button("Start New")
          .onClick(() => {
              this.controller.startAbility({
                  bundleName: '',
                  abilityName: ''
              });
          })
          Button("Back")
          .onClick(() => {
              if (this.controller.getStacjCount() > 1) {
                  this.controller.preformBackPress();
              }
          })
      }
  }
}
```
