# ExceptionPromptV2

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangrunsen-->
<!--Designer: @YanSanzo-->
<!--Tester: @ybhou1993-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=3d1075d2494a6247e95c6fc8e72638db15a80c54 translatedAt=2026-08-10T02:21:51.382Z pushedAt=2026-08-10T03:33:11.041Z -->

The **ExceptionPromptV2** component is used when an exception occurs and the exception content needs to be prompted.

This component is implemented based on [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). Compared with [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), state management V2 delivers enhanced capabilities for deep observation and management of data objects, and is no longer limited to the component level. With state management V2, you can more flexibly control the data and state of the exception prompt through this component, achieving more efficient UI refresh.

> **NOTE**
>
> - This component can only be used in the stage model.
>
> - If [universal attributes](ts-component-general-attributes.md) and [universal events](ts-component-general-events.md) are set for **ExceptionPromptV2**, the compilation toolchain will generate an additional node __Common__ and mount the universal attributes or universal events on __Common__, rather than directly applying them to **ExceptionPromptV2** itself. This may cause the set universal attributes or universal events to not take effect or behave unexpectedly. Therefore, it is not recommended to set universal attributes and universal events on **ExceptionPromptV2**.

**Since:** 26.0.0

## Modules to Import

```ts
import { ExceptionPromptV2, PromptOptionsV2, MarginTypeV2 } from '@kit.ArkUI';
```

## Child Components

Not supported

## ExceptionPromptV2

ExceptionPromptV2({ options: PromptOptionsV2, onTipClick?: OnTipClickCallback, onActionTextClick?: OnActionTextClickCallback })

Defines an exception prompt component, which is used when there is an exception that needs to be prompted.

**Since:** 26.0.0

**Decorator:** @ComponentV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Mandatory | Decorator | Description |
| -------- | -------- | -------- | -------- | -------- |
| options | [PromptOptionsV2](#promptoptionsv2) | Yes | \@Param | Configuration information of the current exception prompt. |
| onTipClick | [OnTipClickCallback](#ontipclickcallback) | No | \@Event | Callback invoked when the left-side tip text is tapped. When not set, no operation is performed. |
| onActionTextClick | [OnActionTextClickCallback](#onactiontextclickcallback) | No | \@Event | Callback invoked when the right-side icon button is tapped. When not set, no operation is performed. |

## PromptOptionsV2Config

Defines the configuration information API for constructing a **PromptOptionsV2** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| marginType | [MarginTypeV2](#margintypev2) | No | No | Margin type of the current exception prompt. |
| marginTop | [Dimension](ts-types.md#dimension10) | No | No | Top margin of the current exception prompt. |
| icon | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Exception icon style of the current exception prompt.<br/>Not set by default or set to **undefined**, the exception icon is not displayed. |
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Exception symbol icon style of the current exception prompt, which takes priority over **icon**.<br/>Not set by default or set to **undefined**, the symbol icon is not displayed. |
| tip | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Text content of the current exception prompt.<br />Supports custom resources or the following four system resource strings for status text.<br />1. No network state: Show network not connected, referencing **\$r('sys.string.ohos_network_not_connected')**.<br />2. Poor network state: Show network connection is unstable, tap to retry, referencing **\$r('sys.string.ohos_network_connected_unstable')**.<br />3. Unable to connect to server state: Show unable to connect to server, tap to retry, referencing **\$r('sys.string.ohos_unstable_connect_server')**.<br />4. Network available but unable to obtain location state: Show unable to obtain location, tap to retry, referencing **\$r('sys.string.ohos_custom_network_tips_left')**.<br/>Not set by default or set to **undefined**, the text content is not displayed. |
| actionText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Text content of the right icon button of the current exception prompt.<br/>Not set by default or set to **undefined**, the text content is not displayed. |
| isShown | boolean | No | Yes | Visibility state of the current exception prompt.<br />**true**: shown.<br />**false**: hidden.<br/>Default value: **false** |

## PromptOptionsV2

Defines the configuration information of the exception prompt component.

**Since:** 26.0.0

**Decorator:** @ObservedV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| icon | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Exception icon style of the current exception prompt.<br/>Not set by default or set to **undefined**, the exception icon is not displayed.<br/>**Decorator:** @Trace |
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Exception symbol icon style of the current exception prompt, with higher priority than **icon**.<br/>Not set by default or set to **undefined**, the symbol icon is not displayed.<br/>**Decorator:** @Trace |
| tip | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Text prompt content of the current exception prompt.<br />Supports custom resources or the following four system resource strings for statuses.<br />1. No network status: displays network not connected, referencing **$r('sys.string.ohos_network_not_connected')**.<br />2. Poor network status: displays network connection unstable, tap to retry, referencing **$r('sys.string.ohos_network_connected_unstable')**.<br />3. Unable to connect to server status: displays unable to connect to server, tap to retry, **referencing $r('sys.string.ohos_unstable_connect_server')**.<br />4. Network available but unable to obtain location status: displays unable to obtain location, tap to retry, referencing **$r('sys.string.ohos_custom_network_tips_left')**.<br/>Not set by default or set to **undefined**, the text prompt content is not displayed.<br/>**Decorator:** @Trace |
| marginType | [MarginTypeV2](#margintypev2) | No | No | Margin type of the current exception prompt.<br/>**Decorator:** @Trace |
| actionText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Text content of the right icon button of the current exception prompt.<br/>Not set by default or set to **undefined**, the text content is not displayed.<br/>**Decorator:** @Trace |
| marginTop | [Dimension](ts-types.md#dimension10) | No | No | Top margin of the current exception prompt.<br/>**Decorator:** @Trace |
| isShown | boolean | No | Yes | Whether to show the current exception prompt.<br />**true**: shown.<br />**false**: hidden.<br/>Default value: **false**<br/>**Decorator:** @Trace |

### constructor

constructor(config?: PromptOptionsV2Config)

Constructor of **PromptOptionsV2**.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| config | [PromptOptionsV2Config](#promptoptionsv2config) | No | Configuration information of **PromptOptionsV2**. If **config** is not passed, the default values are used: **marginType** is **MarginTypeV2.DEFAULT_MARGIN** and **marginTop** is **0**. |

## MarginTypeV2

Defines the margin type of the exception prompt.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Value | Description |
| -------- | -------- | -------- |
| DEFAULT_MARGIN | 0 | Default margin:<br />Left margin: references **$r('sys.float.ohos_id_card_margin_start')**.<br />Right margin: references **$r('sys.float.ohos_id_card_margin_end')**. |
| FIT_MARGIN | 1 | Adaptable margin:<br />Left margin: references **$r('sys.float.ohos_id_max_padding_start')**.<br />Right margin: references **$r('sys.float.ohos_id_max_padding_end')**. |

## OnTipClickCallback

type OnTipClickCallback = () => void

Defines the callback function type for tapping the left-side tip text.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

## OnActionTextClickCallback

type OnActionTextClickCallback = () => void

Defines the callback function type for tapping the icon button on the right.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

## Events

The [universal events](ts-component-general-events.md) are not supported.

## Examples

### Example 1: Setting an Exception Prompt

Starting from API version 26.0.0, this example shows how to set the exception icon, exception prompt text, margin style, and text content of the right icon button for the exception prompt.

```ts
import { ExceptionPromptV2, PromptOptionsV2, MarginTypeV2 } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local options: PromptOptionsV2 = new PromptOptionsV2({
    icon: $r('sys.media.ohos_ic_public_fail'),
    tip: 'Exception prompt',
    marginType: MarginTypeV2.DEFAULT_MARGIN,
    actionText: 'Set network',
    marginTop: 80,
    isShown: true,
  });

  build(): void {
    Column() {
      ExceptionPromptV2({
        options: this.options,
        onTipClick: () => {
          // Tap the text on the left to switch to the connected state.
        },
        onActionTextClick: () => {
          // Open the network configuration dialog box by tapping the "Set network" button.
        },
      })
    }
  }
}
```

![ExceptionPromptV2-01](figures/image-exceptionpromptv2-01.png)

### Example 2 Setting an Exception Prompt of the Dialog Box Type

Since API version 26.0.0, this example uses a custom dialog box to set an exception prompt of the dialog box type.

```ts
import { promptAction } from '@kit.ArkUI';
import { ExceptionPromptV2, MarginTypeV2, PromptOptionsV2 } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index1 {
  @Local ButtonText: string = '';
  @Local MAP_HEIGHT: string = '30%';
  @Local duration: number = 2500;
  @Local tips: string = '';
  @Local actionText: string = '';
  controller: TextInputController = new TextInputController();
  cancel: () => void = () => {
  };
  confirm: () => void = () => {
  };
  @Local options: PromptOptionsV2 = new PromptOptionsV2({
    icon: $r('sys.media.ohos_ic_public_fail'),
    tip: 'Exception prompt!',
    marginType: MarginTypeV2.DEFAULT_MARGIN,
    actionText: 'Settings',
    marginTop: 5,
    isShown: true,
  })
  @Local textValue: string = '';
  @Local inputValue: string = 'click me';

  onCancel(): void {
    console.info('Callback when the first button is clicked');
  }

  onAccept(): void {
    console.info('Callback when the second button is clicked');
  }

  existApp(): void {
    console.info('Click the callback in the blank area');
  }

  private customDialogComponentId: number = 0;

  build(): void {
    Column() {
      Button('Click Me')
        .width('30%')
        .margin({ top: 420 })
        .zIndex(999)
        .onClick(() => {
          promptAction.openCustomDialog({
            builder: () => {
              this.customDialogComponent()
            },
            onWillDismiss: (dismissDialogAction: DismissDialogAction) => {
              console.info('reason' + JSON.stringify(dismissDialogAction.reason));
              console.info('dialog onWillDismiss');
              if (dismissDialogAction.reason == DismissReason.PRESS_BACK) {
                dismissDialogAction.dismiss();
              }
              if (dismissDialogAction.reason == DismissReason.TOUCH_OUTSIDE) {
                dismissDialogAction.dismiss();
              }
            },
            autoCancel: true,
            alignment: DialogAlignment.Bottom,
            offset: { dx: 0, dy: -20 },
          })
            .then((dialogId: number) => {
              this.customDialogComponentId = dialogId;
            })
            .catch((error: BusinessError) => {
              console.error(`openCustomDialog error code is ${error.code}, message is ${error.message}`);
            })

        })
    }
    .height('100%')
    .width('100%')
  }

  @Builder
  customDialogComponent(): void {
    Column() {
      ExceptionPromptV2({
        options: this.options,
      })
      TextInput({ placeholder: '', text: this.textValue }).margin({ top: 70 }).height(60).width('90%')
        .onChange((value: string) => {
          this.textValue = value;
        })
      Text('Whether to change the text?').fontSize(16).margin({ bottom: 10 })
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        Button('cancel')
          .onClick(() => {
            try {
              this.getUIContext().getPromptAction().closeCustomDialog(this.customDialogComponentId)
            } catch (error) {
              let message = (error as BusinessError).message;
              let code = (error as BusinessError).code;
              console.error(`closeCustomDialog error code is ${code}, message is ${message}`);
            }
          }).backgroundColor(0xffffff).fontColor(Color.Black)
        Button('confirm')
          .onClick(() => {
            try {
              this.getUIContext().getPromptAction().closeCustomDialog(this.customDialogComponentId)
            } catch (error) {
              let message = (error as BusinessError).message;
              let code = (error as BusinessError).code;
              console.error(`closeCustomDialog error code is ${code}, message is ${message}`);
            }
          }).backgroundColor(0xffffff).fontColor(Color.Red)
      }.margin({ bottom: 10 })
    }
  }
}
```

![ExceptionPromptV2_02](figures/image-exceptionpromptv2-02.gif)

### Example 3: Setting a Symbol Icon

Since API version 26.0.0, this example demonstrates custom symbol icons by setting the **symbolStyle** property of **PromptOptionsV2**.

```ts
import { ExceptionPromptV2, PromptOptionsV2, MarginTypeV2, SymbolGlyphModifier } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local options1: PromptOptionsV2 = new PromptOptionsV2({
    icon: $r('sys.symbol.house'),
    tip: 'Exception prompt',
    marginType: MarginTypeV2.DEFAULT_MARGIN,
    actionText: 'Set network',
    marginTop: 80,
    isShown: true,
  });

  @Local options2: PromptOptionsV2 = new PromptOptionsV2({
    icon: $r('sys.symbol.house'),
    symbolStyle: new SymbolGlyphModifier($r('sys.symbol.bell')).fontColor([Color.Red]),
    tip: 'Exception prompt',
    marginType: MarginTypeV2.DEFAULT_MARGIN,
    actionText: 'Set network',
    marginTop: 200,
    isShown: true,
  });

  build(): void {
    Column() {
      ExceptionPromptV2({
        options: this.options1,
      })
      ExceptionPromptV2({
        options: this.options2,
      })
    }
  }
}
```

![ExceptionPromptV2_03](figures/image-exceptionpromptv2-03.png)
<!--no_check-->