# 应用文件分享

应用文件分享是应用之间通过分享URI（Uniform Resource Identifier）或文件描述符FD（File Descriptor）的方式，进行文件共享的过程。由于FD分享的文件关闭FD后，无法再打开分享文件，因此不推荐使用，本文重点介绍URI分享方式。

- 基于URI分享方式，应用可分享单个文件，通过[ohos.app.ability.wantConstant](../reference/apis/js-apis-app-ability-wantConstant.md#wantconstantflags)的wantConstant.Flags接口以只读或读写权限授权给其他应用。应用可通过[ohos.file.fs](../reference/apis/js-apis-file-fs.md#fsopen)的open()接口打开URI，并进行读写操作。当前OpenHarmony API 9仅支持临时授权，分享给其他应用的文件在被分享应用退出时权限被收回。

- 基于FD分享方式，应用可分享单个文件，通过ohos.file.fs的open接口以指定权限授权给其他应用。应用从Want中解析拿到FD后可通过ohos.file.fs的读写接口对文件进行读写。

开发者可以使用相关接口，[分享文件给其他应用](#分享文件给其他应用)或[使用其他应用分享的文件](#使用其他应用分享的文件)。

## 文件URI规范

文件URI的格式为：

  格式为file://&lt;bundleName&gt;/&lt;path&gt;

- file：文件URI的标志。

- bundleName：该文件资源的属主。

- path：文件资源在应用沙箱中的路径。

## 分享文件给其他应用

在分享文件给其他应用前，开发者需要先[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)。

1. 获取文件在应用沙箱中的路径，并转换为文件URI。

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   import fileuri from '@ohos.file.fileuri';
   import window from '@ohos.window';
   
   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       // 获取文件的沙箱路径
       let pathInSandbox = this.context.filesDir + "/test.txt";
       // 将沙箱路径转换为uri
       let uri = fileuri.getUriFromPath(pathInSandbox);
       // 获取的uri为"file://com.example.demo/data/storage/el2/base/files/test.txt"
     }
   }
   ```

2. 设置获取文件的权限以及选择要分享的应用。
   分享文件给其他应用需要使用[startAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口，将获取到的URI填充在want的参数uri中，标注URI的文件类型，type字段可参考[Want属性](../reference/apis/js-apis-app-ability-want.md#属性)，并通过设置want的flag来设置对应的读写权限，action字段配置为"ohos.want.action.sendData"表示进行应用文件分享，开发示例如下。

   > **说明：**
   >
   > 写权限分享时，同时授予读权限。

   ```ts
   import fileuri from '@ohos.file.fileuri';
   import window from '@ohos.window';
   import wantConstant from '@ohos.app.ability.wantConstant';
   import UIAbility from '@ohos.app.ability.UIAbility';
   
   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       // 获取文件沙箱路径
       let filePath = this.context.filesDir + '/test.txt';
       // 将沙箱路径转换为uri
       let uri = fileuri.getUriFromPath(filePath);
       let want = {
         // 配置被分享文件的读写权限，例如对被分享应用进行读写授权
         flags: wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION | wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
         // 配置分享应用的隐式拉起规则
         action: 'ohos.want.action.sendData',
         uri: uri,
         type: 'text/plain'
       }
       this.context.startAbility(want)
         .then(() => {
           console.info('Invoke getCurrentBundleStats succeeded.');
         })
         .catch((err) => {
           console.error(`Invoke startAbility failed, code is ${err.code}, message is ${err.message}`);
         });
     }
   
     ...
   }
   ```

## 使用其他应用分享的文件

被分享应用需要在[module.json5配置文件](../quick-start/module-configuration-file.md)的actions标签的值配置为"ohos.want.action.sendData"，表示接收应用分享文件，配置uris字段，表示接收URI的类型，即只接收其他应用分享该类型的URI，如下表示本应用只接收scheme为file，类型为txt的文件，示例如下。
  
```json
{
  "module": {
    ...
    "abilities": [
      {
        ...
        "skills": [
          {
            ...
            "actions": [
              "ohos.want.action.sendData"
            ],
            "uris": [
              {
                "scheme": "file",
                "type": "text/plain"
              }
           ]
          }
        ]
      }
    ]
  }
}
```

被分享方的UIAbility被启动后，可以在其[onCreate()](../reference/apis/js-apis-app-ability-uiAbility.md#uiabilityoncreate)或者[onNewWant()](../reference/apis/js-apis-app-ability-uiAbility.md#uiabilityonnewwant)回调中获取传入的Want参数信息。

通过接口want的参数获取分享文件的URI，获取文件URI后通过fs.open()接口打开文件，获取对应的file对象后，可对文件进行读写操作。

```ts
// xxx.ets
import fs from '@ohos.file.fs';

function getShareFile() {
  try {
    let want = ...; // 获取分享方传递过来的want信息

    // 从want信息中获取uri字段
    let uri = want.uri;
    if (uri == null || uri == undefined) {
      console.info('uri is invalid');
      return;
    }
    try {
      // 根据需要对被分享文件的URI进行相应操作。例如读写的方式打开URI获取file对象
      let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
      console.info('open file successfully!');
    } catch (error) {
      console.error(`Invoke openSync failed, code is ${error.code}, message is ${error.message}`);
    }
  } catch (error) {
    console.error(`Invoke openSync failed, code is ${error.code}, message is ${error.message}`);
  }
}
```
