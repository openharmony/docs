# 创建应用静态快捷方式

## 概述

随着应用的功能越来越复杂，用户在使用应用时，找到某个功能的操作步骤也变得更加繁琐。为提升用户体验，可以对应用中常用的功能创建对应的桌面快捷方式，以达到快速启动应用、一键直达特定功能等目的。例如相机应用的 “快速拍照”、便签应用的 “新建便签” 和地图应用的常用地点导航等功能的快捷方式，用户通过快捷方式可以快速进入特定功能页面，既能大大提高操作效率，同时也增加了用户对应用的依赖性。使用快捷方式，还可以实现个性化定制的需求，创建多个快捷方式，以满足个性化的工作流程和操作偏好。

## 场景介绍

以导航场景为例，当用户使用地图应用导航时，通常是先搜索目的地，然后开始导航。为了提升导航效率和提高操作便捷性，可以给该地图应用添加常去地点的导航快捷方式，如去公司、回家等。添加常去地点（例如公司、家等）的快捷方式后，用户即可通过长按应用图标，打开快捷方式入口，快速开启导航。

快捷方式创建成功后，可以通过以下两种方式快速启动相应的导航功能：

* 点击快捷方式入口列表中的“回家”列，即可快速打开地图应用，开启从当前位置到家的导航路线选择。

  <img src="figures/shortcuts01.gif"/>

* 长按快捷方式入口列表中的“回家”列，可将其拖动至桌面，点击桌面对应图标，即可开启从当前位置到家的导航路线选择。

  <img src="figures/shortcuts02.gif"/>

> **说明：**<br>
> 本文以单[HAP](hap-package.md)包为场景，讲述了快捷方式的实现步骤。多HAP包的场景下，步骤与单HAP包一致，都是在entry文件夹下进行shortcuts_config.json的创建和module.json5的配置。
>

## 实现原理

### 关键技术
使用[shortcuts](module-configuration-file.md#shortcuts标签)来配置应用的快捷方式，其标签值为数组，包含四个子标签shortcutId、label、icon、wants。

* shortcutId：标识快捷方式的ID，取值为长度不超过63字节的字符串。
* label：标识快捷方式的标签信息，即快捷方式对外显示的文字描述信息。取值为长度不超过255字节的字符串，可以是描述性内容，也可以是标识label的资源索引。
* icon：标识快捷方式的图标，取值为资源文件的索引。
* [wants](module-configuration-file.md#wants标签)：标识快捷方式内定义的目标wants信息集合，wants中可配置如下参数：

| 属性名称 | 含义 | 
| -------- | -------- | 
| bundleName | 表示快捷方式的目标包名。 | 
| moduleName | 表示快捷方式的目标模块名。 | 
| abilityName| 表示快捷方式的目标组件名。 | 
| parameters | 表示拉起快捷方式时的自定义数据，仅支持配置字符串类型的数据。其中键值均最大支持1024长度的字符串。 | 


[shortcuts](module-configuration-file.md#shortcuts标签)配置完成后，还需要在[module.json5](module-configuration-file.md)配置文件中配置[metadata字段](module-configuration-file.md#metadata标签)来指定应用的快捷方式配置文件，从而完成快捷方式配置。

>
> **说明：**
> 通过在[module.json5](module-configuration-file.md)配置文件中配置[metadata字段](module-configuration-file.md#metadata标签)的快捷方式是一种在系统中创建的可以快速访问应用程序或特定功能的链接，与[卡片](../form/formkit-overview.md)的区别在于：快捷方式只允许跳转至某个具体的UIAbility，无法直接跳转至非入口页面，且最多可以配置四个快捷方式。
>

### 实现流程

给地图应用添加常用地点的导航快捷方式需要进行如下步骤：

1. 创建页面并配置页面的路由信息。首先需要创建对应的快捷方式页面，且页面组件需要用@Entry装饰。然后在resources/base/profile下的main_pages.json文件中添加对应快捷方式页面的路由信息。

    ```json
    {
      "src": [
        "pages/Index",
        "pages/GoHouse",
        "pages/GoCompany"
      ]
    }
    ```

2. 在/resources/base/profile/目录下创建名为shortcuts_config.json的文件，并在文件中定义应用快捷方式的相关配置。

    ```json
    {
      "shortcuts": [
        {
          "shortcutId": "id_company",
          "label": "$string:Go_to_the_Company",
          "icon": "$media:company",
          "wants": [
            {
              "bundleName": "com.example.desktopshortcuts",
              "moduleName": "entry",
              "abilityName": "EntryAbility",
              "parameters": {
                "shortCutKey": "CompanyPage"
              }
            }
          ]
        },
        {
          "shortcutId": "id_house",
          "label": "$string:Go_to_House",
          "icon": "$media:house",
          "wants": [
            {
              "bundleName": "com.example.desktopshortcuts",
              "moduleName": "entry",
              "abilityName": "EntryAbility",
              "parameters": {
                "shortCutKey": "HousePage"
              }
            }
          ]
        }
      ]
    }
    ```

3. 在[module.json5配置文件](module-configuration-file.md)中的[abilities标签](module-configuration-file.md#abilities标签)下的[metadata](module-configuration-file.md#metadata标签)中设置resource属性值为$profile:shortcuts_config，指定应用的快捷方式配置文件，即使用shortcuts_config.json文件中的shortcuts配置。

    ```json
    {
      "module": {
        // ...
        "abilities": [
          {
            "name": "EntryAbility",
            "srcEntry": "./ets/entryability/EntryAbility.ets",
            // ...
            "skills": [
              {
                "entities": [
                  "entity.system.home"
                ],
                "actions": [
                  "ohos.want.action.home"
                ]
              }
            ],
            "metadata": [
              {
                "name": "ohos.ability.shortcuts", // 配置快捷方式，该值固定为ohos.ability.shortcuts
                "resource": "$profile:shortcuts_config" // 指定shortcuts信息的资源位置
              }
            ]
          }
        ]
      }
    }
    ```

4. 在EntryAbility.ets文件中定义跳转到指定页面的方法。在步骤2中，通过parameters参数来指定了拉起快捷方式时的自定义数据 ，如"shortCutKey": "HousePage"。此时，可以通过获取want中的parameters里的shortCutKey来判断用户使用了哪种快捷方式，从而进行对应的页面跳转。如用户使用了“回家”的快捷方式进行导航，则获取到的shortCutKey的值为HousePage。

    ```ts
    goToSpecifyPage(want: Want) {
      let shortCutKey = want.parameters?.shortCutKey;

      if (this.uiContext && shortCutKey && shortCutKey === 'CompanyPage') {
        let router: Router = this.uiContext.getRouter();
        router.pushUrl({
          url: 'pages/GoCompany'
        }).catch((err: BusinessError) => {
          hilog.error(0x0000, 'testTag', `Failed to push url. Code is ${err.code},message is ${err.message}`);
        });
      }
      if (this.uiContext && shortCutKey && shortCutKey === 'HousePage') {
        let router: Router = this.uiContext.getRouter();
        router.pushUrl({
          url: 'pages/GoHouse'
        }).catch((err: BusinessError) => {
          hilog.error(0x0000, 'testTag', `Failed to push url. Code is ${err.code},message is ${err.message}`);
        });
      }
    }
    ```

5. 最后，需要在EntryAbility.ets文件中的[onNewWant()函数](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onnewwant)中调用步骤4的goToSpecifyPage()方法，并将want作为参数传入。

    ```ts
    onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      // Receive the parameters passed by UIAbility from the caller
      this.goToSpecifyPage(want);

      hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onNewWant');
    }
    ```

## 示例代码

* [桌面快捷方式开发实践](https://gitee.com/harmonyos_samples/DesktopShortcut)