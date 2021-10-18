# 包结构说明

在应用开发的工程中，需要在config.json配置文件中对应用的包结构进行声明。


配置文件示例如下：


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
      "phone"
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


**包结构声明需要注意以下约束：**


- "package"字段命名要保证在相同bundleName的应用内唯一。

- "abilities"字段下只能声明一个ability。

- "abilities"字段中ability的"name"字段命名要保证在相同bundleName的应用内唯一。
