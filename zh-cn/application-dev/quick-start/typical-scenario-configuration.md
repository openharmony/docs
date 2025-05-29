# 创建应用静态快捷方式

静态快捷方式是一种在系统中创建的可以快速访问应用程序或特定功能的链接。长按应用图标后，快捷方式会以图标和相应的文字出现在应用图标的上方，详情请参考[桌面快捷方式开发实践](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-desktop-shortcuts)，用户可以迅速启动对应应用程序的组件。使用快捷方式可以提高效率，节省查找和打开对应组件的时间。还可以实现个性化定制，如创建多个快捷方式，以满足个性化的工作流程和操作偏好。应用配置静态快捷方式，在桌面上展示的效果如下图：


安装应用后，长按桌面上的应用图标，图标上方会出现开发者配置的快捷方式：“添加收藏”和“分享好友”。点击相应标签，即可启动对应的组件。

<img src="figures/shortcut_display.jpg"/>



## 配置方法

下面介绍在工程中配置静态快捷方式的方法。

1. 配置快捷方式文件。
    开发者若要配置静态快捷方式，可以在某个模块的/resources/base/profile/目录下配置[快捷方式的配置文件](module-configuration-file.md#shortcuts标签)，如shortcuts_config.json。

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

2. 在应用的module.json5文件中配置metadata，指向快捷方式的配置文件。

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