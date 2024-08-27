# 静态快捷方式

静态快捷方式是一种在系统中创建的可以快速访问应用程序或特定功能的链接。它通常可以在长按应用图标，以图标和相应的文字出现在应用图标的上方，用户可以迅速启动对应应用程序的组件。使用快捷方式，一来可以提高效率，节省了查找和打开对应的组件时间；二来可以实现个性化定制的需求，创建多个快捷方式，以满足个性话的工作流程和操作偏好。应用配置静态快捷方式，在桌面上展示的效果如下图：

图1 效果示意图<br>
<img src="figures/shortcut_display.jpeg" width="200" />

如图1所示，安装该应用后，在桌面上长按该应用图标，在应用的图标上方会出现开发者配置的快捷方式（“添加收藏”和“分享好友”），点击对应的标签，即可拉起对应的组件。

## 配置方法

下面分别介绍在Stage模型和FA模型中静态快捷方式的配置方法。

### Stage模型配置步骤

1. 配置快捷方式的配置文件

  开发者若要配置静态快捷方式，开发者可以在某个模块的/resources/base/profile/目录下配置[快捷方式的配置文件](module-configuration-file.md#shortcuts标签)，如shortcuts_config.json。

```json
  {
    "shortcuts": [
      {
        "shortcutId": "id_test1",  // 标识快捷方式，在应用有多个快捷方式时，该字段可作为快捷方式的唯一标识符
        "label": "$string:share",  // 标识该快捷方式对外显示的文字
        "icon": "$media:share_icon",  // 标识该快捷方式对外显示的图片
        "wants": [
          {
            "bundleName": "com.ohos.hello",   // 对应该快捷方式对应拉起组件的包名
            "moduleName": "entry",    // 对应该快捷方式对应拉起组件的模块名
            "abilityName": "EntryAbility",   // 对应该快捷方式对应拉起组件的组件名
            "parameters": {
              "testKey": "testValue"   // 表示拉起快捷方式时的自定义数据
            }
          }
        ]
      }
    ]
  }
  ```

2. 在应用module.json5文件中配置metadata指向快捷方式的配置文件

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
                        "name": "ohos.ability.shortcuts",  // 配置快捷方式，该值固定为ohos.ability.shortcuts
                        "resource": "$profile:shortcuts_config"  // 指定shortcuts信息的资源位置
                    }
                ]
            }
        ]
    }
}
```

### FA模型配置步骤

  FA模型中配置静态快捷方式，只需在模块的[config.json](module-structure.md)中module标签下配置[shortcuts信息](module-structure.md#shortcuts对象的内部结构)。

```json
{
  "app": {
    "bundleName": "com.example.fademo",
    // ...
  },
  "deviceConfig": {},
  "module": {
    // ...
    "shortcuts": [
      {
        "shortcutId": "id_test1",  // 标识快捷方式，在应用有多个快捷方式时，该字段可作为快捷方式的唯一标识符
        "label": "$string:module_desc",  // 标识该快捷方式对外显示的文字
        "icon": "$media:icon",  // 标识该快捷方式对外显示的图片
        "intents": [
          {
            "targetBundle": "com.example.fademo",  // 对应该快捷方式对应拉起组件的包名
            "targetClass": "EntryAbility"  // 对应该快捷方式对应拉起组件的组件名
          }
        ]
      }
    ],
    "abilities": [
      {
        // ...
      }
    ],
    "js": [
      {
        // ...
      }
    ]
  }
}
```

  与Stage模型不一样的是，在FA模型中快捷方式对应拉起的组件元素，用intents字段标识。而且在FA模型中没有拉起快捷方式时的自定义数据，也就是Stage模型中的parameters信息。