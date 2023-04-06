# UIAbility Component Overview


## Overview

UIAbility is a type of application component that provides the UI for user interaction.

UIAbility is the basic unit scheduled by the system and provides a window for applications to draw UIs. An application can contain one or more UIAbility components. For example, for a payment application, you can use two UIAbility components to carry the entry and payment functionalities. You are advised to use one UIAbility component to carry the same functional module, with multiple pages (if necessary).

Each UIAbility component instance is displayed as a mission in Recents.


## Privacy Statement Configuration

To enable an application to properly use a UIAbility component, declare the UIAbility name, entry, and tags under [abilities](../quick-start/module-configuration-file.md#abilities) in the [module.json5 configuration file](../quick-start/module-configuration-file.md).


```json
{
  "module": {
    // ...
    "abilities": [
      {
        "name": "EntryAbility", // Name of the UIAbility component.
        "srcEntrance": "./ets/entryability/EntryAbility.ts", // Code path of the UIAbility component.
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
