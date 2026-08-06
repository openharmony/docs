# @ohos.selectionInput.SelectionPanel (Word Selection Panel)

<!--Kit: Basic Services Kit-->
<!--Subsystem: SelectionInput-->
<!--Owner: @no86-->
<!--Designer: @no86-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=1210a92867c5c546bcdf34b618914a517e85d135 translatedAt=2026-08-04T10:29:02.274Z pushedAt=2026-08-05T11:50:08.558Z -->

The text selection panel is an operation panel that pops up after a user selects text. This module is applicable when quick operations such as translation and search need to be provided for the selected text. This helps developers quickly integrate the text selection capability and improve user interaction experience. The panel adopts a two-level architecture design. The menu panel (**MENU_PANEL**) is the level-1 panel, which displays the function entries (such as translation and search) provided by the current app. The main panel (**MAIN_PANEL**) is the level-2 panel, which pops up after a user taps a function button on the menu panel and displays the specific function result. This module provides the attributes and types of the word selection panel. You can use [PanelInfo](#panelinfo) to set the position and size of the panel and use [PanelType](#paneltype) to specify the panel type. [createPanel](js-apis-selectionInput-selectionManager.md#createpanel) and [show](js-apis-selectionInput-selectionManager.md#show) are used to create and display the word selection panel.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This module is supported only on PCs/2-in-1 devices. You can use **canIUse('SystemCapability.SelectionInput.Selection')** to check whether the current device supports this function.

## Modules to Import

```ts
import { PanelInfo, PanelType } from '@kit.BasicServicesKit';
```

## PanelInfo

Defines attributes of the word selection panel, including its type, position, and size. You can specify the panel type (menu panel or main panel) using **panelType**, set the coordinates of the upper left corner of the panel using **x** and **y**, and set the panel size using **width** and **height**. These attributes collectively define the display form of the panel.

**System capability**: SystemCapability.SelectionInput.Selection

**Model constraint**: This API can be used only in the stage model.

| Name| Type| Read-Only| Optional| Description|
| --------- | -------- | -------- | -------- | -------- |
| panelType | [PanelType](#paneltype) | No | No | Word selection panel types, which include two options. For details, see [PanelType](#paneltype). |
| x | number | No | No | X-coordinate of the upper left corner of the word selection panel, in px. The upper left corner of the main screen is the origin, and the positive direction of the X axis is rightward. The value range is [0, +∞). If a negative value is passed, the panel cannot be created. |
| y | number | No | No | Y-coordinate of the upper left corner of the word selection panel, in px. The upper left corner of the main screen is the origin, and the positive direction of the Y axis is downward. The value range is [0, +∞). If a negative value is passed, the panel cannot be created. |
| width | number | No | No | Width of the word selection panel, in px. The value range is (0, +∞). If **0** or a negative value is passed, the panel cannot be created. |
| height | number | No | No | Height of the word selection panel, in px. The value range is (0, +∞). If **0** or a negative value is passed, the panel cannot be created. |

## PanelType

Enumerates the word selection panel types, which defines the two-level architecture of the panel: menu panel (level 1) and main panel (level 2).

**System capability**: SystemCapability.SelectionInput.Selection

**Model constraint**: This API can be used only in the stage model.

| Name         | Value  | Description        |
| ------------- | ---- | ------------ |
| MENU_PANEL | 1    | Menu panel, which serves as the level-1 panel to display the functions that the current app can provide, such as translation and search. |
| MAIN_PANEL | 2    | Main panel, which serves as the level-2 panel and is displayed when a user taps a function button on the menu panel. It displays specific content such as translation or search results. |