# UIAbility Overview


## Overview

UIAbility is a type of application component that provides the UI for user interactions.

The following design philosophy is behind UIAbility:

1. Native support for cross-device migration and multi-device collaboration at the application component level

2. Support for multiple device types and window modes


 

UIAbility is the basic unit of scheduling in OpenHarmony and provides a window for applications to draw the UI. An application can contain one or more UIAbility components. For example, for a payment application, you can use separate UIAbility components to carry the entry and payment functionalities.

Each UIAbility component instance is displayed as a mission in the system application Recents.

You can develop a single UIAbility or multiple UIAbilities for your application based on service requirements.

- If you want your application to be displayed as one mission in Recents, use one UIAbility and multiple pages.

- If you want your application to be displayed as multiple missions in Recents or multiple windows to be opened simultaneously, use multiple UIAbilities.

## Declaration Configuration

To enable an application to properly use a UIAbility component, declare the UIAbility name, entry, and label under [abilities](../quick-start/module-configuration-file.md#abilities) in the [module.json5 file](../quick-start/module-configuration-file.md).


```json
{
  "module": {
    // ...
    "abilities": [
      {
        "name": "EntryAbility", // Name of the UIAbility component.
        "srcEntry": "./ets/entryability/EntryAbility.ets", // Code path of the UIAbility component.
        "description": "$string:EntryAbility_desc", // Description of the UIAbility component.
        "icon": "$media:icon", // Icon of the UIAbility component.
        "label": "$string:EntryAbility_label", // Label of the UIAbility component.
        "startWindowIcon": "$media:icon", // Index of the icon resource file.
        "startWindowBackground": "$color:start_window_background", // Index of the background color resource file.
        // ...
      }
    ]
  }
}
```
