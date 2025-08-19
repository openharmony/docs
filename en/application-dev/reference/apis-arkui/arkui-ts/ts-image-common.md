# Image Analysis Types

>**NOTE**
>
>The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## ImageAnalyzerConfig

Provides AI image analyzer configuration.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| types | [ImageAnalyzerType[]](#imageanalyzertype) | Yes| AI image analysis types.

## ImageAnalyzerType

Defines the AI image analysis type. If it is not set, subject recognition and text recognition are enabled by default.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Value   | Description          |
| -------- | ----- | -------- |
| SUBJECT | 0  | Subject recognition.|
| TEXT | 1  | Text recognition.|
| OBJECT_LOOKUP | 2  | Object lookup.|

## ImageAIOptions

Provides the AI image analysis options.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| types | [ImageAnalyzerType[]](#imageanalyzertype) | No| AI image analysis types.|
| aiController | [ImageAnalyzerController](#imageanalyzercontroller) | No| AI image analysis controller.|

> **NOTE**
>
> The **types** parameter of this API has a higher priority than that of [ImageAnalyzerConfig](#imageanalyzerconfig). This means that, if both parameters are set, the value set by this API takes precedence.
>
> This API depends on device capabilities and must be used together with the **enableAnalyzer** API of the corresponding component (for example, the [\<Image>](ts-basic-components-image.md#enableanalyzer11) component).

## ImageAnalyzerController

Implements an AI image analysis controller, which provides control for image analysis features when bound to supported components.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor()

A constructor used to create an **ImageAnalyzerController** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### getImageAnalyzerSupportTypes

getImageAnalyzerSupportTypes(): ImageAnalyzerType[]

Obtains the analysis types supported by the corresponding component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| ImageAnalyzerType[] | Analysis type supported by the corresponding component.|
