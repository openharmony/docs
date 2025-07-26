# ArcSlider

The **ArcSlider** component is designed for circular screens on wearables to quickly adjust settings, such as the volume and brightness.

>  **NOTE**
>
>  This component is supported since API version 18. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import {
  ArcSlider,
  ArcSliderPosition,
  ArcSliderOptions,
  ArcSliderValueOptions,
  ArcSliderLayoutOptions,
  ArcSliderStyleOptions,
  ArcSliderValueOptionsConstructorOptions,
  ArcSliderLayoutOptionsConstructorOptions,
  ArcSliderStyleOptionsConstructorOptions,
  ArcSliderOptionsConstructorOptions
} from '@kit.ArkUI';
```

## Child Components

Not supported

## Attributes

The [universal attributes](ts-component-general-attributes.md) are not supported.

## Events

The [universal events](ts-component-general-events.md) are not supported.

## ArcSlider

ArcSlider({ options: ArcSliderOptions })

Creates an **ArcSlider** instance. The input parameter is the configuration for the arc slider.

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name   | Type                                 | Mandatory| Description                                                        |
| ------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [ArcSliderOptions](#arcslideroptions) | Yes  | Parameters of the arc slider.<br>Default value: default values of all properties of [ArcSliderOptions](#arcslideroptions)|

## ArcSliderOptions

Defines the properties of the arc slider.

**Decorator type**: @ObservedV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| valueOptions | [ArcSliderValueOptions](#arcslidervalueoptions) | No| @Trace | Value of the arc slider.<br>Default value: default values of all properties of [ArcSliderValueOptions](#arcslidervalueoptions)|
| layoutOptions | [ArcSliderLayoutOptions](#arcsliderlayoutoptions) | No| @Trace | Layout of the arc slider.<br>Default value: default values of all properties of [ArcSliderLayoutOptions](#arcsliderlayoutoptions)|
| styleOptions | [ArcSliderStyleOptions](#arcsliderstyleoptions) | No| @Trace | Style of the arc slider.<br>Default value: default values of all properties of [ArcSliderStyleOptions](#arcsliderstyleoptions)|
| digitalCrownSensitivity | [CrownSensitivity](ts-appendix-enums.md#crownsensitivity18) | No| @Trace | Sensitivity to the digital crown rotation.<br>Default value: **CrownSensitivity.MEDIUM**|
| onTouch | [ArcSliderTouchHandler](#arcslidertouchhandler) | No| @Trace | Callback invoked to notify the application when the arc slider is touched.<br>If no value is provided, no callback is performed.|
| onChange | [ArcSliderChangeHandler](#arcsliderchangehandler) | No| @Trace | Callback invoked to notify the application when the progress value of the arc slider changes.<br>If no value is provided, no callback is performed.|
| onEnlarge | [ArcSliderEnlargeHandler](#arcsliderenlargehandler) | No| @Trace | Callback invoked to notify the application when the arc slider is enlarged or reduced.<br>If no value is provided, no callback is performed.|

### constructor

constructor(options?: ArcSliderOptionsConstructorOptions)

A constructor used to create an **ArcSliderOptions** instance.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name | Type                                                        | Mandatory| Description                        |
| ------- | ------------------------------------------------------------ | ---- | ---------------------------- |
| options | [ArcSliderOptionsConstructorOptions](#arcslideroptionsconstructoroptions) | No  | Construction information for **ArcSliderOptions**.|

## ArcSliderValueOptions

Defines the value of the arc slider.

**Decorator type**: @ObservedV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name | Type  | Mandatory| Decorator| Description                                                        |
| ----- | ------ | ---- | ---------- | ------------------------------------------------------------ |
| progress | number | No  | @Trace     | Current progress.<br>Default value: same as the value of **min**.           |
| min   | number | No  | @Trace     | Minimum value.<br>Default value: **0**.                                 |
| max   | number | No  | @Trace     | Maximum value.<br>Default value: **100**<br>**NOTE**<br>If the value of **min** is greater than or equal to that of **max**, **min** is set to **0** and **max** **100**.<br>If the value is not within the [min, max] range, the value of **min** or **max** is used, whichever is closer.|

### constructor

constructor(options?: ArcSliderValueOptionsConstructorOptions)

A constructor used to create an **ArcSliderValueOptions** instance.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name | Type                                                        | Mandatory| Description                             |
| ------- | ------------------------------------------------------------ | ---- | --------------------------------- |
| options | [ArcSliderValueOptionsConstructorOptions](#arcslidervalueoptionsconstructoroptions) | No  | Construction information for **ArcSliderValueOptions**.|

## ArcSliderLayoutOptions

Defines the layout of the arc slider.

**Decorator type**: @ObservedV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name    | Type                                   | Mandatory| Decorator| Description                                                        |
| -------- | --------------------------------------- | ---- | ---------- | ------------------------------------------------------------ |
| reverse  | boolean                                 | No  | @Trace     | Whether the value range of the arc slider is reversed. **false**: top-to-bottom sliding.<br>**true** (default): bottom-to-top sliding.|
| position | [ArcSliderPosition](#arcsliderposition) | No  | @Trace     | Position of the arc slider on the screen.<br>Default value: **ArcSliderPosition.RIGHT**|

### constructor

constructor(options?: ArcSliderLayoutOptionsConstructorOptions)

A constructor used to create an **ArcSliderLayoutOptions** instance.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name | Type                                                        | Mandatory| Description                              |
| ------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| options | [ArcSliderLayoutOptionsConstructorOptions](#arcsliderlayoutoptionsconstructoroptions) | No  | Construction information for **ArcSliderLayoutOptions**.|

## ArcSliderStyleOptions

Defines the style of the arc slider.

**Decorator type**: @ObservedV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name                | Type  | Mandatory| Decorator| Description                                                        |
| -------------------- | ------ | ---- | ---------- | ------------------------------------------------------------ |
| trackThickness       | number | No  | @Trace     | Stroke width of the arc slider in the normal state, in vp.<br>Default value: **5**<br>The value ranges from 5 to 16. If an invalid value is set, the default value is used.|
| activeTrackThickness | number | No  | @Trace     | Stroke width of the arc slider when it is in an enlarged state, in vp.<br>Default value: **24**<br>The value ranges from 24 to 36. If an invalid value is set, the default value is used.|
| trackColor           | string | No  | @Trace     | Background color of the stroke.<br>Default value: **#33FFFFFF**                     |
| selectedColor        | string | No  | @Trace     | Highlight color of the stroke.<br>Default value: **#FF5EA1FF**                     |
| trackBlur            | number | No  | @Trace     | Blur effect applied to the stroke background, in vp.<br>Default value: **20**<br>If a value less than 0 is set, the default is used.|

### constructor

constructor(options?: ArcSliderStyleOptionsConstructorOptions)

A constructor used to create an **ArcSliderStyleOptions** instance.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name | Type                                                        | Mandatory| Description                             |
| ------- | ------------------------------------------------------------ | ---- | --------------------------------- |
| options | [ArcSliderStyleOptionsConstructorOptions](#arcsliderstyleoptionsconstructoroptions) | No  | Construction information for **ArcSliderStyleOptions**.|

## ArcSliderPosition

Defines the position of the arc slider on the screen.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name | Value  | Description                            |
| ----- | ---- | -------------------------------- |
| LEFT  | 0    | The arc slider is displayed on the left.|
| RIGHT | 1    | The arc slider is displayed on the right.|

## ArcSliderTouchHandler

type ArcSliderTouchHandler = (event: TouchEvent) => void

Defines the callback invoked to notify the application when the arc slider is touched.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name| Type                                                        | Mandatory| Description                |
| ------ | ------------------------------------------------------------ | ---- | -------------------- |
| event  | [TouchEvent](ts-universal-events-touch.md#touchevent) | Yes  | **TouchEvent** object.|

## ArcSliderChangeHandler

type ArcSliderChangeHandler = (progress: number) => void

Defines the callback invoked to notify the application when the progress value of the arc slider changes.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name  | Type  | Mandatory| Description                |
| -------- | ------ | ---- | -------------------- |
| progress | number | Yes  | Current progress of the slider.|

## ArcSliderEnlargeHandler

type ArcSliderEnlargeHandler = (isEnlarged: boolean) => void

Defines the callback invoked to notify the application when the arc slider is enlarged or reduced.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name    | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| isEnlarged | boolean | Yes  | Whether the arc slider is enlarged.<br>**false**: The arc slider is in a reduced state.<br>**true**: The arc slider is in an enlarged state.|

## ArcSliderOptionsConstructorOptions

Defines the construction information for **ArcSliderOptions**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name                   | Type                                                       | Mandatory| Description                                                        |
| ----------------------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| valueOptions            | [ArcSliderValueOptions](#arcslidervalueoptions)             | No  | Value of the arc slider.<br>Default value: default values of all properties of [ArcSliderValueOptions](#arcslidervalueoptions)|
| layoutOptions           | [ArcSliderLayoutOptions](#arcsliderlayoutoptions)           | No  | Layout of the arc slider.<br>Default value: default values of all properties of [ArcSliderLayoutOptions](#arcsliderlayoutoptions)|
| styleOptions            | [ArcSliderStyleOptions](#arcsliderstyleoptions)             | No  | Style of the arc slider.<br>Default value: default values of all properties of [ArcSliderStyleOptions](#arcsliderstyleoptions)|
| digitalCrownSensitivity | [CrownSensitivity](ts-appendix-enums.md#crownsensitivity18) | No  | Sensitivity to the digital crown rotation.<br>Default value: **CrownSensitivity.MEDIUM**  |
| onTouch                 | [ArcSliderTouchHandler](#arcslidertouchhandler)             | No  | Callback invoked to notify the application when the arc slider is touched.<br>If no value is provided, no callback is performed.|
| onChange                | [ArcSliderChangeHandler](#arcsliderchangehandler)           | No  | Callback invoked to notify the application when the progress value of the arc slider changes.<br>If no value is provided, no callback is performed.|
| onEnlarge               | [ArcSliderEnlargeHandler](#arcsliderenlargehandler)         | No  | Callback invoked to notify the application when the arc slider is enlarged or reduced.<br>If no value is provided, no callback is performed.|

## ArcSliderValueOptionsConstructorOptions

Defines the construction information for **ArcSliderValueOptions**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name | Type  | Mandatory| Description                                                        |
| ----- | ------ | ---- | ------------------------------------------------------------ |
| progress | number | No  | Current progress.<br>Default value: same as the value of **min**.          |
| min   | number | No  | Minimum value.<br>Default value: **0**.                                 |
| max   | number | No  | Maximum value.<br>Default value: **100**<br>**NOTE**<br>If the value of **min** is greater than or equal to that of **max**, **min** is set to **0** and **max** **100**.<br>If the value is not within the [min, max] range, the value of **min** or **max** is used, whichever is closer.|

## ArcSliderLayoutOptionsConstructorOptions

Defines the construction information for **ArcSliderLayoutValueOptions**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name    | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| reverse  | boolean                                 | No  | Whether the value range of the arc slider is reversed.<br>Default value: **true** (swipe from bottom to top)|
| position | [ArcSliderPosition](#arcsliderposition) | No  | Position of the arc slider on the screen.<br>Default value: **ArcSliderPosition.RIGHT**|

## ArcSliderStyleOptionsConstructorOptions

Defines the construction information for **ArcSliderStyleOptions**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name                | Type  | Mandatory| Description                                                        |
| -------------------- | ------ | ---- | ------------------------------------------------------------ |
| trackThickness       | number | No  | Stroke width of the arc slider in the normal state, in vp.<br>Default value: **5**<br>The value ranges from 5 to 16. If an invalid value is set, the default value is used.|
| activeTrackThickness | number | No  | Stroke width of the arc slider when it is in an enlarged state, in vp.<br>Default value: **24**<br>The value ranges from 24 to 36. If an invalid value is set, the default value is used.|
| trackColor           | string | No  | Background color of the stroke.<br>Default value: **#33FFFFFF**                     |
| selectedColor        | string | No  | Highlight color of the stroke.<br>Default value: **#FF5EA1FF**                     |
| trackBlur            | number | No  | Blur effect applied to the stroke background, in vp.<br>Default value: **20**<br>If a value less than 0 is set, the default is used.|

## Example

```ts
// xxx.ets
import {
  ArcSlider,
  ArcSliderPosition,
  ArcSliderOptions,
  ArcSliderValueOptions,
  ArcSliderLayoutOptions,
  ArcSliderStyleOptions,
  ArcSliderValueOptionsConstructorOptions,
  ArcSliderLayoutOptionsConstructorOptions,
  ArcSliderStyleOptionsConstructorOptions,
  ArcSliderOptionsConstructorOptions
} from '@kit.ArkUI';

@Entry
@ComponentV2
struct ArcSliderExample {
  valueOptionsConstructorOptions: ArcSliderValueOptionsConstructorOptions = {
    progress: 60,
    min: 10,
    max: 110
  };

  layoutOptionsConstructorOptions: ArcSliderLayoutOptionsConstructorOptions = {
    reverse: true,
    position: ArcSliderPosition.RIGHT
  };
  styleOptionsConstructorOptions: ArcSliderStyleOptionsConstructorOptions = {
    trackThickness: 8,
    activeTrackThickness: 30,
    trackColor: '#ffd5d5d5',
    selectedColor: '#ff2787d9',
    trackBlur: 20
  };
  valueOptions: ArcSliderValueOptions = new ArcSliderValueOptions(this.valueOptionsConstructorOptions);
  layoutOptions: ArcSliderLayoutOptions = new ArcSliderLayoutOptions(this.layoutOptionsConstructorOptions);
  styleOptions: ArcSliderStyleOptions = new ArcSliderStyleOptions(this.styleOptionsConstructorOptions);
  arcSliderOptionsConstructorOptions: ArcSliderOptionsConstructorOptions = {
    valueOptions: this.valueOptions,
    layoutOptions: this.layoutOptions,
    styleOptions: this.styleOptions,
    digitalCrownSensitivity:CrownSensitivity.LOW,
    onTouch: (event: TouchEvent) => {
    },
    onChange: (progress: number) => {
    },
    onEnlarge: (isEnlarged: boolean) => {
    }
  };
  arcSliderOptions: ArcSliderOptions = new ArcSliderOptions(this.arcSliderOptionsConstructorOptions);

  build() {
    Column() {
      ArcSlider({ options: this.arcSliderOptions })}
      .width('100%')
  }
}
```

![arcslider](figures/arcslider.gif)
