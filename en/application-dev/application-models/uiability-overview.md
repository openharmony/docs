# UIAbility Component Overview


## Overview

UIAbility is a type of application component that provides the UI for user interaction.

UIAbility is the basic unit scheduled by the system and provides a window for applications to draw UIs. A UIAbility component can implement a functional module through multiple pages. Each UIAbility component instance corresponds to a mission in **Recents**.


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
