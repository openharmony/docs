# @ohos.inputMethodList (Input Method List)

The **inputMethodList** module is oriented to system applications and input method applications. It provides APIs for implementing an input method list. This list displays the default input method subtypes and third-party input methods. Users can use this list to switch from the default input method to another input method.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { inputMethod } from '@kit.IMEKit';
```

## Child Components

Not supported

## Attributes
The [universal attributes](../apis-arkui/arkui-ts/ts-component-general-attributes.md) are not supported.

## InputMethodListDialog

InputMethodListDialog({controller: CustomDialogController, patternOptions?: PatternOptions})

Implements a dialog box showing the input method list.

**Decorator type**: @CustomDialog

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| controller | [CustomDialogController](../apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md#customdialogcontroller) | Yes| - | Controller for the dialog box showing the input method list.|
| patternOptions | [PatternOptions](#patternoptions) | No| - | Input method pattern options (for the default input method only).|

## PatternOptions

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| defaultSelected<sup>11+</sup>  | number | No| Yes| Optional. Default selected pattern.|
| patterns<sup>11+</sup>    | Array<[Pattern](#pattern)> | No| No| Mandatory. Resource of the pattern option.|
| action<sup>9+</sup> | function | No| No| Mandatory. Callback invoked when the pattern option changes.|

## Pattern

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| icon<sup>11+</sup>  | [Resource](../apis-arkui/arkui-ts/ts-types.md#resource) | No| No| Mandatory. Default icon.|
| selectedIcon<sup>11+</sup>    | [Resource](../apis-arkui/arkui-ts/ts-types.md#resource) | No| No| Mandatory. Icon for the selected option.|

##  Events

The [universal events](../apis-arkui/arkui-ts/ts-component-general-events.md) are not supported.

##  Example

```ts
import { InputMethodListDialog, Pattern, PatternOptions } from '@kit.IMEKit';

@Entry
// Configure the component.
@Component
export struct settingsItem {
  @State defaultPattern: number = 1;
  private oneHandAction: PatternOptions = {
    defaultSelected: this.defaultPattern,
    patterns: [
      {
        icon: $r('app.media.hand_icon'),
        selectedIcon: $r('app.media.hand_icon_selected')
      },
      {
        icon: $r('app.media.hand_icon1'),
        selectedIcon: $r('app.media.hand_icon_selected1')
      },
      {
        icon: $r('app.media.hand_icon2'),
        selectedIcon: $r('app.media.hand_icon_selected2'),
      }],
    action:(index: number)=>{
      console.info(`pattern is changed, current is ${index}`);
      this.defaultPattern = index;
    }
  };
  private listController: CustomDialogController = new CustomDialogController({
    builder: InputMethodListDialog({ patternOptions: this.oneHandAction }),
    customStyle: true,
    maskColor: '#00000000'
  });

  build() {
    Column() {
      Flex({ direction: FlexDirection.Column,
        alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Text("Input Method List").fontSize(20)
      }
    }
    .width("13%")
    .id('bindInputMethod')
    .onClick((event?: ClickEvent) => {
      this.listController.open();
    })
  }
}
```

 <!--no_check--> 