# Spherical Effect

You can apply a spherical effect to a component to make it appear spherized.

>  **NOTE**
>
>  This attribute is supported since API Version 10. Updates will be marked with a superscript to indicate their earliest API version. This is a system API.

## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| sphericalEffect | [number] | Spherical degree of the component.<br>The value ranges from 0 to 1.<br>**NOTE**<br>1. If the value is 0, the component remains unchanged. If the value is 1, the component is completely spherical. Between 0 and 1, a greater value indicates a higher spherical degree.<br>A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**.<br> 2. If a component image is loaded asynchronously, the spherical effect is not supported. For example, the **\<Image>** component uses asynchronous loading by default, which means that **syncLoad** must be set to **true** to apply the spherical effect. However, this setting is not recommended. Asynchronous loading is also used for **backgroundImage**. Therefore, if **backgroundImage** is set, the spherical effect is not supported.<br>3. If the shadow effect is set for a component, the spherical effect is not supported.|

## Example

### Example 1
```ts
// xxx.ets
@Entry
@Component
struct SphericalEffectExample {
  build() {
    Stack() {
      TextInput({placeholder: "Enter a percentage."})
        .width('50%')
        .height(35)
        .type(InputType.Number)
        .enterKeyType(EnterKeyType.Done)
        .caretColor(Color.Red)
        .placeholderColor(Color.Blue)
        .placeholderFont({
          size: 20,
          style: FontStyle.Italic,
          weight: FontWeight.Bold
        })
        .sphericalEffect(0.5)
    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}

```
Below is how the component looks with the spherical effect applied:

![textInputSpherical1](figures/textInputSpherical1.png)

Below is how the component looks without the spherical effect applied:

![textInputSpherical2](figures/textInputSpherical2.png)
