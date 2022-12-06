# AbilityComponent

**\<AbilityComponent>** is a container for independently displaying an ability.

>  **NOTE**
>
>  This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The APIs of this module are system APIs and cannot be called by third-party applications.

## Constraints

**\<AbilityComponent>** is rendered independently and cannot be overlaid with other display content.

**\<AbilityComponent>** cannot process input events. Events are directly distributed to the internal ability for processing without passing through the current ability.

Only width and height can be set for **\<AbilityComponent>**. These attributes are mandatory and cannot be dynamically updated.

The ability to be started must inherit from [WindowExtension](../apis/js-apis-application-WindowExtensionAbility.md).

## Child Components

Not supported


## APIs

AbilityComponent(want: Want)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis/js-apis-application-Want.md) | Yes| Description of the default ability to load.|


## Events

### onConnect

onConnect(callback:() =&gt; void)

Called when this **\<AbilityComponent>** is started. You can then use APIs in the **\<AbilityComponent>**.

### onDisconnect

onDisconnect(callback:() =&gt; void)

Called when this **\<AbilityComponent>** is destroyed.

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
              console.log('AbilityComponent connect')
          })
          .onDisconnect(() => {
              console.log('AbilityComponent disconnect')
          })
      }
  }
}
```
