# Application- or Component-Level Configuration (FA Model)

During application development, you must configure tags to identify an application, such as the bundle name and application icon. This topic describes some key tags.

## Configuring the Bundle Name

The bundle name is specified by the **bundleName** field under **app** in the **config.json** file. This field identifies an application and must be globally unique. The bundle name can contain only letters, digits, underscores (_), and periods (.). It must start with a letter. It is a string with 7 to 127 bytes of a reverse domain name, for example, **com.example.myapplication**. It is recommended that the first part is the top-level domain **"com"**, and the second part is the vendor or individual name, which can be of multiple levels. For details about the configuration, see [app](../quick-start/app-structure.md).

## Configuring Icons and Labels

Icons and labels are usually configured together. There are four types: application icon, application label, entry icon, and entry label.

The application icon and application label are used to identify an application, and they are usually displayed on a screen for identifying the application. Example scenarios are as follows:
* Application list in Settings
* Applications with permissions granted in the privacy management screen
* Notification messages displayed in the status bar


The entry icon and entry label are displayed on the device's home screen after an application is installed. The entry icon is specific to a PageAbility. Only one entry icon and entry label can be configured for an application. If there are multiple entry abilities, only the entry icon and entry label configured for the mainAbility in the entry HAP take effect. After you touch the entry icon, the corresponding PageAbility page is displayed. Example scenarios are as follows:
* Applications displayed on the device's home screen
* Applications displayed in Recents

### Configuring the Application Icon and Application Label
The FA model does not support direct configuration of application icons and application labels. Instead, the icon and label of a PageAbility that meet the rules are used as the application icon and application label. If multiple PageAbilities address this condition, the icon and label of the first candidate PageAbility is used as the application icon and application label.

### Configuring the Entry Icon and Entry Label
#### Configuration Methods
In the FA model, the entry icon and entry label are the values of **icon** and **label** configured for a PageAbility.

For details about the configuration rules, see [PageAbility Component](pageability-configuration.md). Configure the following fields under **abilities** in the **config.json** file:
* **icon**: index of the resource file. The icon must be configured in the resource file on DevEco Studio, and the path of the icon must be **/resource/base/media**. An example value is **$media:ability_icon**.
* **label**: index of the resource file. It identifies the name of the ability presented to users. The label value can be an ability name or a resource index to the ability name in multiple languages.

In the **skills** attribute of the PageAbility, if the **actions** value contains **action.system.home** and the **entities** value contains **entity.system.home**, the icon and label of this PageAbility is used as the application icon and label. If multiple PageAbilities address this condition, the icon and label of the first candidate PageAbility is used as the application icon and label. For details about the configuration, see [abilities](../quick-start/module-structure.md).

```json
{
  ...
  "module": {
    ...
    "abilities": [
      {
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ],
        "orientation": "unspecified",
        "formsEnabled": false,
        "name": ".MainAbility",
        "srcLanguage": "ets",
        "srcPath": "MainAbility",
        "icon": "$media:icon",
        "description": "$string:MainAbility_desc",
        "label": "$string:MainAbility_label",
        "type": "page",
        "visible": true,
        "launchType": "singleton"
      },
      ...
    ]
    ...
  }
}
```
#### Control Rules
The system strictly controls applications without icons to prevent malicious applications from deliberately configuring no icon to block uninstall attempts.

To hide an entry icon on the home screen, you must configure the **AllowAppDesktopIconHide** privilege.<!--Del--> For details, see [Application Privilege Configuration Guide](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).<!--DelEnd--> The rules for displaying the entry icon and entry label are as follows:

* The HAP file contains PageAbility configuration.
  * An entry icon is set in the **abilities** field of the **config.json** file.
    * The application does not have the privilege to hide its icon on the home screen.
      * The system uses the icon configured for the PageAbility as the entry icon and displays it on the home screen. Touching this icon will direct the user to the home page of the PageAbility.
      * The system uses the label configured for the PageAbility as the entry label and displays it on the home screen. If no label is configured, the system uses the bundle name of the application as the entry label and displays it on the home screen.
    * The application has the privilege to hide its icon on the home screen.
      * The application information is not returned when the home screen queries the information, and the entry icon and entry label of the application are not displayed on the home screen.
  * No entry icon is set in the **abilities** field of the **config.json** file.
    * The application does not have the privilege to hide its icon on the home screen.
      * The system uses the icon specified in the system resource as the entry icon and displays it on the home screen. Touching this icon will direct the user to the application details page.
      * The system uses the label configured for the PageAbility as the entry label and displays it on the home screen. If no label is configured, the system uses the bundle name of the application as the entry label and displays it on the home screen.
    * The application has the privilege to hide its icon on the home screen.
        * The application information is not returned when the home screen queries the information, and the entry icon and entry label of the application are not displayed on the home screen.

* The HAP file does not contain PageAbility configuration.
  * The application does not have the privilege to hide its icon on the home screen.
    * The system uses the icon specified in the system resource as the entry icon and displays it on the home screen. Touching this icon will direct the user to the application details page.
    * The system uses the bundle name of the application as the entry label and displays it on the home screen.
  * The application has the privilege to hide its icon on the home screen.
    * The application information is not returned when the home screen queries the information, and the entry icon and entry label of the application are not displayed on the home screen.

## Configuring Application Version Declaration

To declare the application version, set the **version** field under **app** in the **config.json** file to specify the version number, version name, and earliest compatible version number. For details, see [Internal Structure of the version Attribute](../quick-start/app-structure.md#internal-structure-of-the-version-attribute).

## Configuring Device Types Supported by the Module

To configure the device types supported by the module, set the **deviceType** field in the **config.json** file. If a certain device type is added to **deviceTypes**, the module can run on that device. For details, see [deviceType Attribute](../quick-start/module-structure.md#devicetype-attribute).

## Configuring the Component Permission

To request component permissions, set the **reqPermissions** field under **module** in the **config.json** file. This field declares the name of the permission to request, the reason for requesting the permission, and the scenario where the permission is used. For details, see [Internal Structure of the reqPermissions Attribute](../quick-start/module-structure.md#internal-structure-of-the-reqpermissions-attribute).
