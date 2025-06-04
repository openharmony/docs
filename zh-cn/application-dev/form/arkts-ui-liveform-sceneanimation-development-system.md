# 场景动效类型互动卡片开发指导（系统应用）

场景动效类型互动卡片基础开发指导，可以参考文档[场景动效类型互动卡片开发指导](arkts-ui-liveform-sceneanimation-development.md)。针对系统应用，场景动效类型互动卡片提供了**禁用手势配置**和**卡片长时激活**两个扩展能力。

## 接口说明

**表1** 主要接口

| 接口名                                                                      | 描述                                                                                                                  |
|--------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------|
| formProvider.activateSceneAnimation(formId: string): Promise&lt;void&gt; | 互动卡片请求状态切换到激活态，只针对[场景动效类型互动卡片](../../form/arkts-ui-widget-configuration.md#sceneanimationparams标签)生效，使用Promise异步回调。 |
| formProvider.deactivateSceneAnimation(formId: string): Promise&lt;void&gt; | 互动卡片请求切换到非激活态，只针对[场景动效类型互动卡片](../../form/arkts-ui-widget-configuration.md#sceneanimationparams标签)生效，使用Promise异步回调。 |

## 禁用手势配置

在form_config.json中，配置项sceneAnimationParams新增针对系统应用的可选字段disabledDesktopBehaviors，应用可以控制在激活态下卡片不响应特定用户在桌面的有效手势操作。例如：
1. 长按：LONG_CLICK。
2. 拖拽卡片：DRAG。
3. 下拉进入全搜：PULL_DOWN_SEARCH。
4. 滑动翻页：SWIPE_PAGE。

不配置时，默认不禁用任何用户在桌面的有效手势操作。

```ts
// entry/src/main/resources/base/profile/form_config.json
{
  "forms": [
    {
      "name": "systemWidget",
      "displayName": "$string:systemWidget_display_name",
      "description": "$string:systemWidget_desc",
      "src": "./ets/systemwidget/pages/SystemWidgetCard.ets",
      "uiSyntax": "arkts",
      "window": {
        "designWidth": 720,
        "autoDesignWidth": true
      },
      "colorMode": "auto",
      "isDynamic": true,
      "isDefault": false,
      "updateEnabled": false,
      "scheduledUpdateTime": "10:30",
      "updateDuration": 1,
      "defaultDimension": "2*2",
      "supportDimensions": [
        "2*2"
      ],
      "sceneAnimationParams": {
        "abilityName": "MySystemLiveFormExtensionAbility",
        "disabledDesktopBehaviors": "LONG_CLICK|DRAG|SWIPE_DESKTOP|PULL_DOWN_SEARCH"
      }
    }
  ]
}
```

## 卡片长时激活

针对系统应用，支持通过接口控制卡片状态切换，不对激活态保持时间做强限制，即卡片可以长时间保持激活态。卡片进入/退出激活态操作由[formProvider.activateSceneAnimation](../reference/apis-form-kit/js-apis-app-form-formProvider-sys.md#activatesceneanimation20)和[formProvider.deactivateSceneAnimation](../reference/apis-form-kit/js-apis-app-form-formProvider-sys.md#deactivatesceneanimation20)接口控制。
特别地，卡片处于长时激活状态时候，卡片动效渲染区域和卡片自身渲染区域等大，不支持在激活态下调用[formProvider.requestOverflow](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderrequestoverflow20)。

### 开发流程

1. 导入模块

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

2. 调用formProvider.activateSceneAnimation，触发卡片长时激活

```ts

let formId: string = '12400633174999288';

try {
  formProvider.activateSceneAnimation(formId).then(() => {
    console.info('activateSceneAnimation succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

3. 调用formProvider.deactivateSceneAnimation，取消长时激活，卡片切换为非激活态

```ts
let formId: string = '12400633174999288';

try {
  formProvider.deactivateSceneAnimation(formId).then(() => {
    console.info('deactivateSceneAnimation succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

4. LiveFormExtensionAbility适配

为了卡片提供方更加精细控制卡片状态切换，卡片提供方需在激活态页面准备就绪时，通过session发送信息告知卡片使用方，卡片使用方在收到信息后开始加载卡片激活态UI。

```ts
// entry/src/main/ets/mysystemliveformextensionability/MySystemLiveFormExtensionAbility.ets
import { LiveFormInfo } from '@kit.FormKit';
import { LiveFormExtensionAbility } from '@kit.FormKit';
import { UIExtensionContentSession } from '@kit.AbilityKit';

export default class MySystemLiveFormExtensionAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession) {
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('session', session);

    // 获取参卡片 ID 与激活态渲染区域
    let formId: string = liveFormInfo.formId as string;
    storage.setOrCreate('formId', formId);
    console.log(`MySystemLiveFormExtensionAbility onSessionCreate formId: ${formId}`);

    // 加载提供方页面
    session.loadContent('mysystemliveformextensionability/pages/MySystemLiveFormPage', storage);

    // 卡片提供方需在激活态页面准备就绪时，通过 session 发送信息告知卡片使用方
    session.sendData({['isFormReady']: true});
    this.context.setBackgroundImage($r('app.media.background'));
  }

  onLiveFormDestroy(liveFormInfo: LiveFormInfo) {
    console.log(`MySystemLiveFormExtensionAbility onDestroy`);
  }
}
```