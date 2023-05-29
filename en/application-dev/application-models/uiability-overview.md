# UIAbility Component Overview


## Overview

UIAbility is a type of application component that provides the UI for user interaction.

The following design philosophy is behind UIAbility:

1. Native support for [cross-device migration](hop-cross-device-migration.md) and [multi-device collaboration](hop-multi-device-collaboration.md) at the application component level

2. Support for multiple device types and window forms

> **NOTE**
>
> For details, see [Interpretation of the Application Model](application-model-description.md).

The UIAbility division principles and suggestions are as follows:

UIAbility is the basic unit scheduled by the system and provides a window for applications to draw UIs. An application can contain one or more UIAbility components. For example, for a payment application, you can use two UIAbility components to carry the entry and payment functionalities.

Each UIAbility component instance is displayed as a mission in Recents.

You can develop a single UIAbility or multiple UIAbilities for your application based on service requirements.

- If you want only one mission to be displayed in Recents, use one UIAbility and multiple pages.

- If you want multiple missions to be displayed in Recents or multiple windows to be opened simultaneously, use multiple UIAbilities.

## Privacy Statement Configuration

To enable an application to properly use a UIAbility component, declare the UIAbility name, entry, and tags under [abilities](../quick-start/module-configuration-file.md#abilities) in the [module.json5 configuration file](../quick-start/module-configuration-file.md).


```json
{
  "module": {
    ...
    "abilities": [
      {
        "name": "EntryAbility", // Name of the UIAbility component.
        "srcEntry": "./ets/entryability/EntryAbility.ts", // Code path of the UIAbility component.
        "description": "$string:EntryAbility_desc", // Description of the UIAbility component.
        "icon": "$media:icon", // Icon of the UIAbility component.
        "label": "$string:EntryAbility_label", // Label of the UIAbility component.
        "startWindowIcon": "$media:icon", // Index of the icon resource file.
        "startWindowBackground": "$color:start_window_background", // Index of the background color resource file.
        ...
      }
    ]
  }
}
```
