# Image Analysis Types

>**NOTE**
>
>The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## ImageAnalyzerConfig

Provides AI image analyzer configuration.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name    | Type               | Mandatory  | Description                  |
| ------ | ----------------- | ---- | -------------------- |
| types | [ImageAnalyzerType[]](#imageanalyzertype) | Yes | AI image analysis types.

## ImageAnalyzerType

Enumerates the AI image analysis types.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Description          |
| -------- | -------------- |
| SUBJECT | Subject recognition. |
| TEXT | Text recognition. |
