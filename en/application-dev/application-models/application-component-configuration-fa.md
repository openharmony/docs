# Application- or Component-Level Configuration (FA Model)

During application development, you must configure tags to identify an application, such as the bundle name and application icon. This topic describes some key tags.


- **Configuring the bundle name**
  
  The bundle name is specified by the **bundleName** field under **app** in the **config.json** file. This field identifies an application and must be globally unique. The bundle name can contain only letters, digits, underscores (_), and periods (.). It must start with a letter. It is a string with 7 to 127 bytes of a reverse domain name, for example, **com.example.myapplication**. It is recommended that the first part is the top-level domain **"com"**, and the second part is the vendor or individual name, which can be of multiple levels. For details about the configuration, see [app](../quick-start/app-structure.md).
  
- **Configuring the application icon and label**

  The FA model does not support direct configuration of application icons and application labels. Instead, the icon and label of a PageAbility that meet the rules are used as the application icon and application label. For details about the configuration rules, see [PageAbility Component](pageability-configuration.md). The icon is specified by the **icon** field under **abilities** in the **config.json** file. The icon must be configured in the resource file on DevEco Studio, and the path of the icon must be **/resource/base/media**. An example value is **$media:ability_icon**. The label is the index of the resource file. It identifies the name of the ability presented to users. The label value can be an ability name or a resource index to the ability name in multiple languages. In the **skills** attribute of the ability, if the **actions** value contains **action.system.home** and the **entities** value contains **entity.system.home**, the icon and label of the ability is used as the application icon and label. If multiple PageAbilities address this condition, the icon and label of the first candidate PageAbility is used as the application icon and label. For details about the configuration, see [abilities](../quick-start/module-structure.md).

  ```json
    "abilities": [
      "icon": "$media:icon",
      "label": "$string:MainAbility_label",
      "skills": [  
        {
          "entities": ["entity.system.home"],
          "actions": ["action.system.home"]
        }
      ]
      ...
    }
  ```

- **Configuring application version declaration**
  
  To declare the application version, set the **version** field under **app** in the **config.json** file to specify the version number, version name, and earliest compatible version number. For details, see [Internal Structure of the version Attribute](../quick-start/app-structure.md#internal-structure-of-the-version-attribute).
  
- **Configuring device types supported by the module**

  To configure the device types supported by the module, set the **deviceType** field in the **config.json** file. If a certain device type is added to **deviceTypes**, the module can run on that device. For details, see [deviceType Attribute](../quick-start/module-structure.md#devicetype-attribute).

- **Configuring the component permission**

  To request component permissions, set the **reqPermission** field under **module** in the **config.json** file. This field declares the name of the permission to request, the reason for requesting the permission, and the scenario where the permission is used. For details, see [deviceType Attribute](../quick-start/module-structure.md#devicetype-attribute).

 <!--no_check--> 