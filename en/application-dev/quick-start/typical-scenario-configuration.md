# Creating a Static Shortcut of the Application

A static shortcut is a link created in the system to quickly access an application or a specific feature. Generally, the shortcut icon and text will appear above the application icon by long touching the application icon, so that a user can quickly start a specific component of the application. Using shortcuts can improve efficiency and save the time for searching and starting specific components. In addition, you can create multiple shortcuts to meet personalized workflow and operation preferences. The following figure shows a static shortcut of an application displayed on the home screen.

**Figure 1** Example<br>

After installing the application, long touch the icon on the home screen. The shortcuts (Add to Favorites and Share) configured by you are displayed above the application icon. Touch a label to start the corresponding component.

<img src="figures/shortcut_display.jpg"/>



## Configuration

The following describes how to configure a static shortcut in a project.

1.  
    Configure the [shortcut configuration file](module-configuration-file.md#shortcuts) in the **resources/base/profile** directory of a specific module, for example, **shortcuts_config.json** file.

    ```json
    {
      "shortcuts": [
        {
          "shortcutId": "id_test1",  // Shortcut ID. If an app has multiple shortcuts, this field can be used as the unique identifier of the shortcut.
          label": "$string:share",  // Text displayed on the shortcut.
          "icon": "$media:share_icon",  // Image displayed on the shortcut.
          "wants": [
            {
              "bundleName": "com.ohos.hello",   // Bundle name of the started component.
              "moduleName": "entry," // Module name of the started component.
              "abilityName": "EntryAbility",   // Component name of the started component.
              "parameters": {
                "testKey": "testValue"   // Custom data of the started shortcut.
              }
            }
          ]
        }
      ]
    }
    ```

2. Configure the configuration file in which the **metadata** points to the shortcut in the **module.json5** file of the application.

    ```json
    {
      "module": {
      // ...
        "abilities": [
          {
            "name": "EntryAbility",
            "srcEntry": "./ets/entryability/EntryAbility.ets",
            // ...
            "metadata": [
              {
                "name": "ohos.ability.shortcuts",  // Configure a shortcut. The value is fixed at ohos.ability.shortcuts.
                "resource": "$profile:shortcuts_config"  // Specify the resource of the shortcuts configuration.
              }
            ]
          }
        ]
      }
    }
    ```
