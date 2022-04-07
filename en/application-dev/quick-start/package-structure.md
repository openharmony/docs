# Directory Structure<a name="EN-US_TOPIC_0000001117322842"></a>

In an application development project, you need to declare the package structure of the application in the  **config.json**  file.

The following is an example of the configuration file:

```
{
  "app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "version": {
      "code": 1,
      "name": "1.0"
    },
    "apiVersion": {
      "compatible": 4,
      "target": 5,
      "releaseType": "Beta1"
    }
  },
  "deviceConfig": {},
  "module": {
    "package": "com.example.myapplication.entrymodule",
    "name": ".MyApplication",
    "deviceType": [
      "default"
    ],
    "distro": {
      "deliveryWithInstall": true,
      "moduleName": "entry",
      "moduleType": "entry"
    },
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
        "name": "com.example.myapplication.entrymodule.MainAbility",
        "icon": "$media:icon",
        "description": "$string:mainability_description",
        "label": "$string:app_name",
        "type": "page",
        "launchType": "standard"
      }
    ],
    "js": [
      {
        "pages": [
          "pages/index/index"
        ],
        "name": "default",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": false
        }
      }
    ]
  }
}
```

Note the following when declaring the package structure:

-   The value of  **package**  must be unique for the applications with the same  **bundleName**.
-   Only one ability can be declared in the  **abilities**  field.
-   The  **name**  field under  **abilities**  must be unique for the applications with the same  **bundleName**.

