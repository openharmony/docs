# Radio Button (Radio)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @houguobiao-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=233780541406c33f29af8bce3784afa16dc6ae50 translatedAt=2026-07-29T12:44:17.710Z pushedAt=2026-07-30T02:30:34.319Z -->

The **Radio** component allows users to select from a set of mutually exclusive options. Only one radio button in a given group can be selected at the same time. For details, see [Radio](../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md).

## Creating a Radio Button

A radio button is created using the **Radio** component with [RadioOptions](../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md#radiooptions). The following example demonstrates how to use the **value** and **group** properties in **RadioOptions**:

```ts
Radio(options: {value: string, group: string})
```

In this API, **value** indicates the name of the radio button, and **group** indicates the name of the group to which the radio button belongs. You can use the **checked** attribute to specify whether the radio button is selected. Setting it to **true** means that the radio button is selected. **false** means the opposite.

In addition, you can customize the style of the radio button for both the selected and unselected states.

<!-- @[click_radio_to_show_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/radio/RadioButton.ets) -->

``` TypeScript
Radio({ value: 'Radio1', group: 'radioGroup' })
  .checked(false)
Radio({ value: 'Radio2', group: 'radioGroup' })
  .checked(true)
```

![radio-create](figures/radio-create.png)

## Adding Events

The **Radio** component supports the [universal events](../reference/apis-arkui/arkui-ts/ts-component-general-events.md). In addition, it can be bound to the **onChange** event to execute custom logic when the selection changes.

<!-- @[click_radio_event_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/radio/RadioButton.ets) -->

``` TypeScript
Radio({ value: 'Radio1', group: 'radioGroup' })
  .onChange((isChecked: boolean) => {
    if(isChecked) {
      // Action to perform.
      // ...
    }
  })
Radio({ value: 'Radio2', group: 'radioGroup' })
  .onChange((isChecked: boolean) => {
    if(isChecked) {
      // Action to perform.
      // ...
    }
  })
```

## Example Scenario

In this example, the **Radio** components are used to switch between sound modes.

<!-- @[click_radio_to_change_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ChooseComponent/entry/src/main/ets/pages/radio/RadioSample.ets) -->

``` TypeScript
// xxx.ets
import { promptAction } from '@kit.ArkUI';

@Entry
@Component
export struct RadioExample {
  @State rst: promptAction.ShowToastOptions = { 'message': 'Ringing mode.' };
  @State vst: promptAction.ShowToastOptions = { 'message': 'Vibration mode.' };
  @State sst: promptAction.ShowToastOptions = { 'message': 'Silent mode.' };

  build() {
    // ...
      Row() {
        Column() {
          Radio({ value: 'Ringing', group: 'radioGroup' }).checked(true)
            .height(50)
            .width(50)
            .onChange(async (isChecked: boolean) => {
              if (isChecked) {
                try {
                  // Switch to ringing mode.
                  await this.getUIContext().getPromptAction().openToast(this.rst);
                } catch (err) {
                  console.error('Failed to show toast: ${err.code}');
                }
              }
            })
          Text('Ringing')
        }

        Column() {
          Radio({ value: 'Vibration', group: 'radioGroup' })
            .height(50)
            .width(50)
            .onChange(async (isChecked: boolean) => {
              if (isChecked) {
                try {
                  // Switch to vibration mode.
                  await this.getUIContext().getPromptAction().openToast(this.vst);
                } catch (err) {
                  console.error('Failed to show toast: ${err.code}');
                }
              }
            })
          Text('Vibration')
        }

        Column() {
          Radio({ value: 'Silent', group: 'radioGroup' })
            .height(50)
            .width(50)
            .onChange(async (isChecked: boolean) => {
              if (isChecked) {
                try {
                  // Switch to silent mode.
                  await this.getUIContext().getPromptAction().openToast(this.sst);
                } catch (err) {
                  console.error('Failed to show toast: ${err.code}');
                }
              }
            })
          Text('Silent')
        }
      }.height('100%').width('100%').justifyContent(FlexAlign.Center)
      // ...
  }
}
```

![radio-scenario](figures/radio-scenario.gif)