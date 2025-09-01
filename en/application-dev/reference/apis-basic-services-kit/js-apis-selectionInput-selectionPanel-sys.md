# @ohos.selectionInput.SelectionPanel (Word Selection Panel) (System API)

This module provides the properties and types of the word selection panel.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { PanelInfo, PanelType } from '@kit.BasicServicesKit';
```

## PanelInfo

Describes the properties of the word selection panel.

**System capability**: SystemCapability.SelectionInput.Selection

| Name| Type| Read-Only| Optional| Description|
| --------- | -------- | -------- | -------- | -------- |
| panelType | [PanelType](#paneltype) | No| No| Type of the word selection panel.|
| x | number | No| No| X-coordinate of the upper left corner of the word selection panel, in px.|
| y | number | No| No| Y-coordinate of the upper left corner of the word selection panel, in px.|
| width | number | No| No| Width of the word selection panel, in px.|
| height | number | No| No| Height of the word selection panel, in px.|

## PanelType

Enumerates the word selection panel types.

**System capability**: SystemCapability.SelectionInput.Selection

| Name         | Value  | Description        |
| ------------- | ---- | ------------ |
| MENU_PANEL | 1    | Menu panel.|
| MAIN_PANEL | 2    | Main panel.|
