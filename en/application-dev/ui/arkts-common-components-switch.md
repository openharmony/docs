# Toggle

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @houguobiao-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=6448b6b0bfc045f8772649c8e0d84d7c698cb3d1 translatedAt=2026-07-29T12:45:58.636Z pushedAt=2026-07-30T03:04:23.280Z -->

The **Toggle** component provides a clickable element in the check box, button, or switch type, typically used to switch between two states. For details, see [Toggle](../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md).

## Creating a Toggle

A toggle is created using [ToggleOptions](../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md#toggleoptions18). The syntax is as follows:

```ts
Toggle(options: { type: ToggleType, isOn?: boolean })
```

In the preceding syntax, `ToggleType` indicates the toggle type, which can be `Button`, `Checkbox`, or `Switch`, and `isOn` indicates the state of the toggle.

Since API version 11, the default style of the **Checkbox** component is changed from rounded square to circle.

The API can be called in either of the following ways:

- Create a toggle that does not contain child components.

  This can be achieved by calling the API with **ToggleType** set to **Checkbox** or **Switch**.

  <!-- @[create_toggle_with_checkbox](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/toggle/CreateToggle.ets) -->

  ``` TypeScript
  Toggle({ type: ToggleType.Checkbox, isOn: false }).id('toggle1') // Replace the value of id with the actual ID.
  Toggle({ type: ToggleType.Checkbox, isOn: true }).id('toggle2') // Replace the value of id with the actual ID.
  ```

  ![switch-checkbox-default](figures/switch-checkbox-default.png)

  <!-- @[create_toggle_with_switch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/toggle/CreateToggle.ets) -->

  ``` TypeScript
  Toggle({ type: ToggleType.Switch, isOn: false }).id('toggle3') // Replace the value of id with the actual ID.
  Toggle({ type: ToggleType.Switch, isOn: true }).id('toggle4') // Replace the value of id with the actual ID.
  ```

    ![switch-create](figures/switch-create.png)

- Create a toggle that contains a child component.

  When **ToggleType** is set to **Button**, only one child component is allowed. If the child component has text set, the text content is displayed on the button.

  <!-- @[create_a_toggle_that_contains_subcomponents](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/toggle/CreateToggle.ets) -->

  ``` TypeScript
  Toggle({ type: ToggleType.Button, isOn: false }) {
    Text('status button')
      .fontColor('#182431')
      .fontSize(12)
  }.width(100).id('toggle5') // Replace the value of id with the actual ID.
  
  Toggle({ type: ToggleType.Button, isOn: true }) {
    Text('status button')
      .fontColor('#182431')
      .fontSize(12)
  }.width(100).id('toggle6') // Replace the value of id with the actual ID.
  ```

    ![switch-checkbox](figures/switch-checkbox.png)

## Setting Styles

- Use the **selectedColor** attribute to set the background color of the toggle for when it is turned on.

  <!-- @[custom_toggle](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/toggle/ToggleCustomStyle.ets) -->

  ``` TypeScript
    Toggle({ type: ToggleType.Button, isOn: true }) {
      Text('status button')
        .fontColor('#182431')
        .fontSize(12)
    }.width(100)
    .selectedColor(Color.Pink)
  // ···
  
    Toggle({ type: ToggleType.Checkbox, isOn: true })
      .selectedColor(Color.Pink)
      // ···
    Toggle({ type: ToggleType.Switch, isOn: true })
      .selectedColor(Color.Pink)
      // ···
  ```

  ![switch-style](figures/switch-style.png)

- Use the **switchPointColor** attribute to set the color of the circular slider. This attribute is valid only when **type** of the toggle is set to **ToggleType.Switch**.

  <!-- @[custom_switch_point_color](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/toggle/ToggleCustomStyle.ets) -->  

  ``` TypeScript
  Toggle({ type: ToggleType.Switch, isOn: false })
    .switchPointColor(Color.Pink)
    // ···
  Toggle({ type: ToggleType.Switch, isOn: true })
    .switchPointColor(Color.Pink)
    // ···
  ```

  ![switch-custom](figures/switch-custom.png)

## Adding Events

The **Toggle** component supports the [universal events](../reference/apis-arkui/arkui-ts/ts-component-general-events.md). In addition, it can be bound to the **onChange** event so that it responds with custom behavior after being turned on or off.

<!-- @[create_toggle_with_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/toggle/CreateToggle.ets) -->  

``` TypeScript
Toggle({ type: ToggleType.Switch, isOn: false })
  .onChange((isOn: boolean) => {
    if(isOn) {
      // Operation
      // ···
    }
  })
```

## Example Scenario

In this example, the **Toggle** component is used to enable or disable Bluetooth.

<!-- @[the_example_of_bluetooth](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/toggle/ToggleCaseExample.ets) --> 

``` TypeScript
// xxx.ets
import { promptAction } from '@kit.ArkUI';

@Entry
@Component
export struct ToggleSample {
  @State message: string = 'off';
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column({ space: 8 }) {
        Column({ space: 8 }) {
          Text('Bluetooth Mode: ' + this.message)
            .id('message')
          Row() {
            Text('Bluetooth')
            Blank()
            Toggle({ type: ToggleType.Switch })
              .id('toggle') // Replace the value of id with the actual ID.
              .onChange((isOn: boolean) => {
                if (isOn) {
                  this.message = 'on';
                  promptAction.openToast({ 'message': 'Bluetooth is on.' });
                } else {
                  this.message = 'off';
                  promptAction.openToast({ 'message': 'Bluetooth is off.' });
                }
              })
          }.width('100%')
        }
        .alignItems(HorizontalAlign.Start)
        .backgroundColor('#fff')
        .borderRadius(12)
        .padding(12)
        .width('100%')
      }
      .width('100%')
      .height('100%')
      .padding({ left: 12, right: 12 })
    }
    .backgroundColor('#f1f2f3')
    // Replace $r('app.string.ToggleCaseExample_title') with the actual resource file. In this example, the value in the resource file is "Bluetooth."
    .title($r('app.string.ToggleCaseExample_title'))
  }
}
```

![switch-example](figures/switch-example.gif)