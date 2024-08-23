# AbilityComponent (System API)

**AbilityComponent** is a container for independently displaying an ability.

>  **NOTE**
>
>  This component is deprecated since API version 10. You are advised to use [\<UIExtensionComponent>](ts-container-ui-extension-component-sys.md) instead.
>
>  This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The APIs provided by this component are system APIs.

## Constraints

**AbilityComponent** is rendered independently and cannot be overlaid with other display content.

**AbilityComponent** cannot process input events. Events are directly distributed to the internal ability for processing without passing through the current ability.

Only width and height can be set for **AbilityComponent**. These attributes are mandatory and cannot be dynamically updated.

The ability to be started must inherit from [WindowExtension](../js-apis-application-windowExtensionAbility-sys.md).

## Child Components

Not supported


## APIs

AbilityComponent(want: Want)

**Parameters**

| Name| Type                                                  | Mandatory| Description               |
| ------ | ---------------------------------------------------------- | ---- | ----------------------- |
| want   | [Want](../../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Description of the default ability to load.|


## Events

### onConnect

onConnect(callback:() =&gt; void)

Called when this **AbilityComponent** is started. You can then use APIs in the **AbilityComponent**.

### onDisconnect

onDisconnect(callback:() =&gt; void)

Called when this **AbilityComponent** is destroyed.

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
