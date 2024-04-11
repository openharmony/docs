# 接入安全隐私框架

安全隐私接入框架允许两种接入方式：ExtensionAbility和UIAbility方式接入。

应用接入后，将按照bundleName的字母顺序在隐私中心展示。

业务接入方需在本应用模块下的module.json5配置文件中配置相应的action和metadata，供安全隐私中心菜单接入框架扫描、解析。

开发者可参考以下步骤，完成对安全隐私框架的接入。

## 新增元数据资源配置文件

业务接入方需要新增一个元数据资源配置json文件，用于承载接入安全隐私框架的方式、跳转的Ability等内容，具体字段说明如表所示：

| key值（属性名称） | value值                                                      | 是否必填 | 说明                                              |
| ----------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------- |
| displayedMode     | - list：代表列表方式接入。<br />- card：代表卡片方式接入，当前版本暂不支持。 | 是       | 目前仅支持列表展示，输入card/list均按照列表展示。 |
| mainTitleResource | 入口菜单显示的主标题字串的资源名                             | 是       | -                                                 |
| dstAbilityMode    | - 0： 表示被拉起的ability为UIAbility。<br />- 1： 表示被拉起的ability为UIExtensionAbility。 | 是       | -                                                 |
| dstAbilityName    | 跳转的目标Ability。<br />- 当dstAbilityMode为0时，该ability为UIAbility。<br />- 当dstAbilityMode为1时，该ability需继承自UIExtensionAbility，接入方在此ability中加载自身页面。 | 是       | -                                                 |
| dstBundleName     | 跳转的目的bundle名称。                                         | 是       | -                                                 |
| displayUserConfig | - ONLY_PRIMARY_USER：仅主用户展示。<br />- ONLY_SUB_USER：仅子用户展示。 | 否       | 如果不填，默认为向所有用户展示。                  |

本文档中以新建一个security_privacy.json文件为例，来指导业务接入方完成配置，实际的json文件的名称可由开发者自定义。

此文件需放置在对应模块的`"resource/rawfile/xxx.json"`中。

```json
{
  "displayedMode": "list",
  "mainTitleResource": "$string:main_title",
  "dstAbilityMode": 0,
  "dstAbilityName": "EntryAbility",
  "dstBundleName": "com.example.test"
}
```

## 修改应用配置文件

各模块的module.json5配置文件中，承载了该模块UIAbility组件和ExtensionAbility组件的描述信息、应用运行过程中所需的权限等信息。接入安全隐私框架需将一下相关字段配置到module.json5中。

### 配置action

在module.json5文件的“ skill ”标签中，配置隐私中心的action值`"action.access.privacy.center"`。

```typescript
"skills": [
  {
    "actions": [
      "action.access.privacy.center"
    ]
  }
]
```

### 配置metadata

在module.json5文件的“ metadata ”标签中，新增“ name ”为“ metadata.access.privacy.center ”、“ value ”为元数据json文件名称的条目。

元数据json文件即为上一步新增的`"resource/rawfile/xxx.json"`。

> **说明：**
>
> 开发者需要根据dstAbilityMode来选择action、metadata的配置。
>
> - 如果被拉起的页面是UIAbility，则需配置到“ abilities ”中，
>
> - 如果是UIExtensionAbility，则需配置到“ extensionAbilities ” 中。
>
>   **在配置extensionAbilities时，其中type类型需配置成"sys/commonUI"。**

当前示例仅提供接入安全隐私框架涉及的标签用法，module.json5中的其余标签字段，需要开发者根据实际情况填写。

```typescript
// UIAbility方式接入
"abilities": [
  {
    "skills": [
      {
        "actions": [
          "action.access.privacy.center"
        ]
      }
    ],
    "metadata": [
      {
        "name": 'metadata.access.privacy.center',
        "value": 'security_privacy.json'
      }
    ]
  }
]
```

```typescript
// ExtensionAbility方式接入
"extensionAbilities": [
      {
        "type": "sys/commonUI",
        "skills": [
          {
            "actions": [
              "action.access.privacy.center"
            ]
          }
        ],
        "metadata": [
          {
            "name": 'metadata.access.privacy.center',
            "value": 'security_privacy.json'
          }
        ]
      }
    ]
```

### 配置权限

业务接入方需申请权限[ohos.permission.ACCESS_SECURITY_PRIVACY_CENTER](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/AccessToken/permissions-for-system-apps.md#ohospermissionaccess_security_privacy_center)，来确保应用可以接入框架菜单。

申请方式请参考[访问控制开发指导](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/AccessToken/determine-application-mode.md)。

## 配置Ability页面（以UIAbility方式接入）

如果为UIAbility方式接入，则不需要单独做相关的配置，直接使用默认生成的方式。

示例：

```typescript
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
}
```

## 配置Ability页面（以ExtensionAbility方式接入）

如果为ExtensionAbility方式接入，Ability页面需继承自ExtensionAbility，并且需修改相应配置，使用session的方式来拉起接入应用的主页面。

示例：

```typescript
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
import ExtensionAbility from '@ohos.app.ability.ExtensionAbility';
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';

export default class EntryAbility extends ExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onSessionCreate');
    let param: Record<string, Object> = {
      'session': session
    }
    let storage: LocalStorage = new LocalStorage(param)
    session.loadContent('pages/Index', storage)
  }
}
```

## 接入页面退出（以UIAbility方式接入）

如果是UIAbility的方式接入，接入方需主动退出时，例如页面有返回按钮，想要销毁应用的页面时，可以直接调用router.back()或者terminateSelf()来销毁当前页面。

示例：

```typescript
import router from '@ohos.router';

@Entry()
@Component
struct Index {
 
  build() {
    Row() {
      Column() {
        Button("click to back")
          .onClick(() => {
            router.back()
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 接入页面退出（以ExtensionAbility方式接入）

如果是UIExtensionAbility的方式接入，接入方需主动退出时，例如页面有返回按钮，想要销毁应用的页面时，可以通过UIExtensionContentSession的sendData向使用方发送数据 `{“action”: "exit"}`，使用方接收到消息之后将退出拉起的页面。

示例：

```typescript
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession'

let storage = LocalStorage.getShared()

@Entry(storage)
@Component
struct Index {
  private session: UIExtensionContentSession = storage.get<UIExtensionContentSession>('session') as UIExtensionContentSession
  build() {
    Row() {
      Column() {
        Button("click to back")
          .onClick(() => {
            this.session.sendData({ 'action': "exit" })
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
