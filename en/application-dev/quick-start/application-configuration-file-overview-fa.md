# Application Configuration Files (FA Model)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->


Each application project must have configuration files in its code directory. These configuration files provide basic application information for build tools, the operating system, and application markets.


The application configuration file contains the following information:


- Basic information of the application, including the bundle name, vendor, and version number. Such information must be set under the **app** tag.

- Component information of the application, including all abilities, device types, component types, and syntax types in use.

- Device-specific information of the application. Such information affects the functioning of the application on the device.


When developing an application in the Feature Ability (FA) model, you must declare the package structure of the application in the **config.json** file.


## Configuration File Internal Structure

The **config.json** file consists of three mandatory tags, namely, **app**, **deviceConfig**, and **module**.

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| [app](app-structure.md) | Application-wide configuration. Different HAP files of an application must use the same **app** configuration.| Object| No|
| [deviceConfig](deviceconfig-structure.md) | Device-specific configuration.| Object| No|
| [module](module-structure.md) | HAP configuration. It is valid only for the current HAP file.| Object| No|

Example of the **config.json** file:


```json
{
  "app": {
    "vendor": "example",
    "bundleName": "com.example.demo",
    "version": {
      "code": 1000000,
      "name": "1.0.0"
    }
  },
  "deviceConfig": {
  },
  "module": {
    "mainAbility": ".MainAbility_entry",
    "deviceType": [
      "tablet"
    ],
    "commonEvents": [
      {
        "name": ".EntryAbility",
        "permission": "ohos.permission.GET_BUNDLE_INFO",
        "data": [
          "com.example.demo",
          "100"
        ],
        "events": [
          "install",
          "update"
        ]
      }
    ],
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
        "visible": true,
        "srcPath": "MainAbility_entry",
        "name": ".MainAbility_entry",
        "srcLanguage": "ets",
        "icon": "$media:icon",
        // $string:MainAbility_entry_desc is a resource index.
        "description": "$string:MainAbility_entry_desc",
        "formsEnabled": false,
        // $string:MainAbility_entry_label is a resource index.
        "label": "$string:MainAbility_entry_label",
        "type": "page",
        "launchType": "multiton"
      }
    ],
    "distro": {
      "moduleType": "entry",
      "installationFree": false,
      "deliveryWithInstall": true,
      "moduleName": "myapplication"
    },
    "package": "com.example.myapplication",
    "srcPath": "",
    "name": ".myapplication",
    "js": [
      {
        "mode": {
          "syntax": "ets",
          "type": "pageAbility"
        },
        "pages": [
          "pages/index"
        ],
        "name": ".MainAbility_entry",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": false
        }
      }
    ]
  }
}
```
