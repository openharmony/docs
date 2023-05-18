# 原子化服务

## 原子化服务分包预加载

### 使用分包

为了加快首次启动原子化服务时的速度，可以采用分包策略，原子化服务的代码包可以被划分为几个：一个是类型为entry的模块，包含原子化服务启动时会打开的页面代码和相关资源；其余是“分包”，包含其余的代码和资源。这样，启动原子化服务时，只需下载和安装entry模块，即可立刻启动原子化服务，大大降低原子化服务下载的时间。

#### 配置方法

原子化服务分包可以在`DevEco Studio`中创建，我们以创建一个原子化服务为例。基本的工程目录结构大致如下：

```
├── AppScope
|    ├── resources
|    └── app.json5
├── entry
|    └── src/main
|       ├── ets
|       ├── resources
|       └── module.json5
├── feature
|    └── src/main
|       ├── ets
|       ├── resources
|       └── module.json5
├── library
|    └── src/main
|       ├── ets
|       ├── resources
|       └── module.json5
├── node_modules
```

注意，开发者需要在[app.json5](app-configuration-file.md)中`bundleType`字段指定为`atomicService`，标识当前应用是原子化服务。`app.json5`（路径为：`AppScope/app.json5`）的内容为：

```json
{
  "app": {
    "bundleName": "com.example.hmservice",
    "bundleType":"atomicService",
    "vendor": "example",
    "versionCode": 1000000,
    "versionName": "1.0.0",
    "icon": "$media:app_icon",
    "label": "$string:app_name",
    "targetAPIVersion": 9
  }
}
```

具体分包攻略，详细可参考[多hap开发](multi-hap-objective.md)。

#### 限制

1. 原子化服务中每个模块对应的配置文件[module.json5](module-configuration-file.md)中`installationFree`字段必须为`true`。

2. 打包原子化服务时，需遵循以下大小校验规则：

- 原子化服务中，所有包的大小总和不能超过10M。

- 单个包加上其依赖的所有[共享包](in-app-hsp.md)，大小不能超过2M。


### 使用预加载

开发者可以通过配置，在原子化服务进入某个模块时，由系统自动预下载可能需要的模块，从而提升进入后续模块的速度。

原子化服务预加载目前只支持通过配置方式使用，暂不支持通过调用API使用。

#### 配置方法

原子化服务预加载行为在点击进入某个模块时，第一帧绘制结束之后触发，可以通过在相应模块的[module.json5](module-configuration-file.md)文件中配置`atomicService`标签下的`preloads`字段来控制，以下为entry模块的`module.json5`（路径为：`entry/src/main/module.json5`）文件内容：

```json
{
  "module": {
    "name": "entry",
    "type": "entry",
    "srcEnty": "./ets/Application/MyAbilityStage.ts",
    "description": "$string:entry_desc",
    "mainElement": "MainAbility",
    "deviceTypes": [
      "default",
      "tablet"
    ],
    "deliveryWithInstall": true,
    "installationFree": true,
    "pages": "$profile:main_pages",
    "atomicService": {
      "preloads": [
        {
          "moduleName": "feature"
        }
      ]
    },
    "abilities": [
      {
        "name": "MainAbility",
        "srcEnty": "./ets/MainAbility/MainAbility.ts",
        "description": "$string:MainAbility_desc",
        "icon": "$media:icon",
        "label": "$string:MainAbility_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:white",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ]
      }
    ]
  }
}
```

在完成entry模块的第一帧绘制结束后，会自动执行预加载去下载和安装模块名为feature的模块。

#### 限制

preloads列表配置的moduleName对应的[moduleType(模块类型)](../reference/apis/js-apis-bundleManager.md#moduletype)不能为entry。

## 原子化服务中使用动态共享包

[Harmony动态共享包](shared-guide.md)（Harmony Shared Package），简称HSP，其可以包含其他模块公用的代码、C++库、资源和配置文件等。
在原子化服务中使用HSP，可以参考[应用内HSP开发指导](in-app-hsp.md)。

#### 配置方法

假设工程目录结构如下：
```
├── AppScope
|    ├── resources
|    └── app.json5
├── entry
|    └── src/main
|       ├── ets
|           ├── entryAbility
|           └── pages
|               └── Index.ets
|       ├── resources
|       └── module.json5
├── feature
|    └── src/main
|       ├── ets
|       ├── resources
|       └── module.json5
├── library
|    └── src/main
|       ├── ets
|           └── pages
|               └── menu.ets
|       ├── resources
|       └── module.json5
├── node_modules
```

若开发者想在entry模块中，添加一个按钮跳转至library模块中的menu页面（路径为：`library/src/main/ets/pages/menu.ets`），那么可以在使用方的代码（entry模块下的Index.ets，路径为：`entry/src/main/ets/MainAbility/Index.ets`）里这样使用：

```ts
import router from '@ohos.router';

@Entry
@Component
struct Index {
    @State message: string = 'Hello World'

    build() {
    Row() {
        Column() {
        Text(this.message)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        // 添加按钮，以响应用户点击
        Button() {
            Text('click to menu')
            .fontSize(30)
            .fontWeight(FontWeight.Bold)
        }
        .type(ButtonType.Capsule)
        .margin({
            top: 20
        })
        .backgroundColor('#0D9FFB')
        .width('40%')
        .height('5%')
        // 绑定点击事件
        .onClick(() => {
            router.pushUrl({
              url: '@bundle:com.example.hmservice/library/ets/pages/menu'
            }).then(() => {
              console.log("push page success");
            }).catch(err => {
              console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);
            })
        })
      .width('100%')
    }
    .height('100%')
    }
  }
}
```

其中`router.pushUrl`方法的入参中`url`的内容为：
```ets
'@bundle:com.example.hmservice/library/ets/pages/menu'
```
`url`内容的模板为：
```ets
'@bundle:包名（bundleName）/模块名（moduleName）/路径/页面所在的文件名(不加.ets后缀)'
```