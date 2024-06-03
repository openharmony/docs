# FormComponent (System API)

The **FormComponent** is used to display widgets.

>  **NOTE**
>
> - This component is supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This component is intended for the widget host. For details about the widget provider, see [JS Service Widget UI Components](../js-service-widget-ui/js-service-widget-file.md).
>
> - To use this component, you must have the system signature.
>
> - The APIs provided by this module are system APIs.

## Required Permissions

ohos.permission.REQUIRE_FORM, ohos.permission.GET_BUNDLE_INFO_PRIVILEGED


## Child Components

Not supported


## APIs

FormComponent(value: {
    id: number;
    name: string;
    bundle: string;
    ability: string;
    module: string;
    dimension?: FormDimension;
    temporary?: boolean;
    renderingMode?: FormRenderingMode;
  })

Creates a **FormComponent** instance to display the provided widget.

**Parameters**

| Name   | Type                       | Mandatory| Description                                                               |
| --------- | ------------------------------- | ---- | ----------------------------------------------------------------------- |
| id        | number                          | Yes  | Widget ID. Set this parameter to **0** for a new widget.<br>**NOTE**<br>Different widget hosts cannot use the same ID.<br>If a widget host uses the same ID for two widgets, the one added later is displayed.                                       |
| name      | string                          | Yes  | Widget name.                                                             |
| bundle    | string                          | Yes  | Bundle name of the widget.                                                         |
| ability   | string                          | Yes  | Ability name of the widget.                                                  |
| module    | string                          | Yes  | Module name of the widget.                                                         |
| dimension | [FormDimension](#formdimension) | No  | Dimensions of the widget. The widgets in the 2 x 2, 4 x 4, and 4 x 2 dimensions are supported.<br>Default value: **Dimension_2_2**|
| temporary | boolean                         | No  | Whether the widget is a temporary one.                                                   |
| renderingMode<sup>11+</sup> | [FormRenderingMode](#formrenderingmode11) | No  | Widget rendering mode. The options are as follows:<br>- **FULL_COLOR** (default): full color mode, where the widget framework does not change the widget effect, which means that the widget is displayed in the effect as you set it.<br>- **SINGLE_COLOR**: single color mode, where the widget framework sets the widget background to transparent. In this mode you need to set the widget style based on the best practices.<br>**NOTE**<br>If the system does not support unified rendering, the widget framework does not set the widget background to transparent in single color mode.|

## FormDimension

| Name                      | Description    |
| -------------------------- | -------- |
| Dimension_1_2              | 1 x 2 widget.|
| Dimension_2_2              | 2 x 2 widget.|
| Dimension_2_4              | 2 x 4 widget.|
| Dimension_4_4              | 4 x 4 widget.|
| Dimension_2_1<sup>9+</sup> | 2 x 1 widget.|
| Dimension_1_1<sup>11+</sup> | 1 x 1 widget.|
| Dimension_6_4<sup>12+</sup> | 6 x 4 widget.|

## FormRenderingMode<sup>11+</sup>
| Name                      | Description    |
| -------------------------- | -------- |
| FULL_COLOR                 | Full color mode.|
| SINGLE_COLOR               | Single color mode.|

## Attributes

### size

size(value: { width: number; height: number })

Sets the size for the widget.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                     | Mandatory| Description      |
| ------ | --------------------------------------------------------- | ---- | ---------- |
| value  | {<br>width?: number,<br>height?: number<br>} | Yes  | Width and height.|

### moduleName

moduleName(value: string)

Sets the module name for the widget.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| value  | string | Yes  | Module name of the widget.|

### dimension

dimension(value: FormDimension)

Sets the dimensions for the widget. The 2 x 2, 4 x 4, and 4 x 2 options are available.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                           | Mandatory| Description                                |
| ------ | ------------------------------- | ---- | ------------------------------------ |
| value  | [FormDimension](#formdimension) | Yes  | Dimensions of the widget.<br>Default value: **Dimension_2_2**|

### allowUpdate

allowUpdate(value: boolean)

Sets whether to allow the widget to update.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                               |
| ------ | ------- | ---- | ----------------------------------- |
| value  | boolean | Yes  | Whether to allow the widget to update.<br>Default value: **true**|

### visibility

visibility(value: Visibility)

Sets whether the widget is visible.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                         | Mandatory| Description                                  |
| ------ | --------------------------------------------- | ---- | -------------------------------------- |
| value  | [Visibility](ts-appendix-enums.md#visibility) | Yes  | Whether the widget is visible.<br>Default value: **Visible**|

## Events

### onAcquired

onAcquired(callback: (info: { id: number }) =&gt; void)

Called when the widget is obtained.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                               | Mandatory| Description      |
| ------ | ----------------------------------- | ---- | ---------- |
| info   |  { id: number } | Yes  | Widget ID.|

### onError

onError(callback: (info: { errcode: number; msg: string }) => void)

Called when an error occurs during component loading.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                           |
| ------ | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| info   |  { errcode: number, msg: string } | Yes  | **errcode**: error code.<br>**msg**: error information.|

### onRouter

onRouter(callback: (info: any) =&gt; void)

Called when routing occurs for the widget. This API returns information in [routerEvent](../js-service-widget-ui/js-service-widget-syntax-hml.md#event-binding).

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description                                                        |
| ------ | ---- | ---- | ------------------------------------------------------------ |
| info   | any  | Yes  | Information in [routerEvent](../js-service-widget-ui/js-service-widget-syntax-hml.md#event-binding).|

### onUninstall

onUninstall(callback: (info: { id: number }) =&gt; void)

Called when the widget is uninstalled. This API returns the ID of the uninstalled widget.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                               | Mandatory| Description      |
| ------ | ----------------------------------- | ---- | ---------- |
| info   |  { id: number } | Yes  | Widget ID.|


## Example

```ts
//card.ets
@Entry
@Component
struct CardExample {
   @State formId:number = 0;
  build() {
    Column() {
      Text('this is a card')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      FormComponent({
        id:this.formId,
        name:"Form1",
        bundle:"com.example.cardexample",
        ability:"FormAbility",
        module:"entry",
        dimension:FormDimension.Dimension_2_2,
        temporary:false
      })
        .allowUpdate(true)
        .size({width:360,height:360})
        .visibility(Visibility.Visible)
        .onAcquired((form)=>{
          console.log(`form info : ${JSON.stringify(form)}`);
          this.formId = form.id;
        })
        .onError((err)=>{
          console.log(`fail to add form, err: ${JSON.stringify(err)}`);
        })

    }
    .width('100%')
    .height('100%')
  }
}
```

![Form](figures/form.png)
