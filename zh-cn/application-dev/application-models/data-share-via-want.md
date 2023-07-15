# 应用间使用Want分享数据

在应用使用场景中，用户经常需要将应用内的数据（如文字、图片等）分享至其他应用以供进一步处理。以分享PDF文件为例，本文将介绍如何使用Want来实现应用间的数据分享。

数据分享需要使用两个UIAbility组件（分享方和被分享方）以及一个系统组件（应用分享框）。当分享方使用`startAbility()`方法发起数据分享时，系统会隐式匹配所有支持接收分享数据类型的应用，并将其展示给用户以供选择。用户选择应用后，系统将启动该应用来完成数据分享操作。

在本文中，我们将使用按钮的形式触发分享操作，但实际开发中并不限于此。本文主要介绍如何配置Want以实现数据分享的功能。

本文中涉及的两个Action为：

- `ohos.want.action.select`：用于启动应用分享框。
- `ohos.want.action.sendData`：用于发送单个数据记录。此Action用于将数据传递给分享方应用。

## 分享方

为了实现数据分享功能，分享方需要先拉起应用分享框并将要分享的数据传递给被分享方应用。因此，在分享方的代码中需要嵌套使用两层Want。在第一层中，使用隐式Want和`ohos.want.action.select`的action来启动应用分享框。在第二层Want中，声明要传递给被分享方应用的数据。

具体来说，可以将要分享的数据放在自定义字段`parameters`中，然后将包含`ohos.want.action.sendData`的action和`parameters`字段的Want作为第二层Want传递给应用分享框。被分享方应用可以通过获取参数`parameters`来获取分享的数据。

```ts
import common from '@ohos.app.ability.common';

let fileType = 'application/pdf';
let fileName = 'TestFile.pdf';
let fileFd = -1; // 需要获取被分享文件的FD
let fileSize; // 需要获取被分享文件的大小

function implicitStartAbility() {
  let context = getContext(this) as common.UIAbilityContext;
  let wantInfo = {
    // This action is used to implicitly match the application selctor.
    action: 'ohos.want.action.select',
    // This is the custom parameter in the first layer of want
    // which is intended to add info to application selector.
    parameters: {
      // The MIME type of pdf
      'ability.picker.type': fileType,
      'ability.picker.fileNames': [fileName],
      'ability.picker.fileSizes': [fileSize],
      // This a nested want which will be directly send to the user selected application.
      'ability.want.params.INTENT': {
        'action': 'ohos.want.action.sendData',
        'type': 'application/pdf',
        'parameters': {
          'keyFd': { 'type': 'FD', 'value': fileFd }
        }
      }
    }
  }
  context.startAbility(wantInfo).then(() => {
    ...
  }).catch((err) => {
    ...
  })
}
```

> **说明：**
>
> 目前仅支持使用文件描述符（FD）格式分享数据。获取被分享文件的文件描述符和文件名，请参考[文件管理](../reference/apis/js-apis-file-fs.md)相关接口。

在以上代码中，使用了自定义字段`parameters`。其中，一级参数`parameters`中的字段`ability.picker.*`用于向应用选择器传递展示信息，具体字段如下：

- `ability.picker.type`：用于渲染相应的文件类型图标。
- `ability.picker.fileNames`：用于展示文件名。
- `ability.picker.fileSizes`：用于展示文件大小，单位为字节。
- `ability.picker.fileNames`和`ability.picker.fileSizes`是数组，两者一一对应。

效果示意如下图所示。   
![](figures/ability-startup-with-implicit-want2.png)

## 被分享方

为了使分享的内容能够在被分享方识别，需要在被分享方UIAbility的[module.json5配置文件](../quick-start/module-configuration-file.md)中的skills标签进行相应的配置。其中，`actions`字段和`uris`内的`type`字段分别与分享方Want参数中`ability.want.params.INTENT`内的`action`和`type`字段进行匹配。

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
              "action.system.home",
              "ohos.want.action.sendData"
              ...
            ],
            "uris": [
              {
                "type": "application/pdf"
              },
            ]
          }
        ]
      }
    ]
  }
}
```

当用户选择分享的应用后，嵌套在`ability.want.params.INTENT`字段中的Want参数将会传递给所选应用。被分享方的UIAbility被启动后，可以在其[`onCreate()`](../reference/apis/js-apis-app-ability-uiAbility.md#uiabilityoncreate)或者[`onNewWant()`](../reference/apis/js-apis-app-ability-uiAbility.md#uiabilityonnewwant)回调中获取传入的Want参数信息。

获取到的Want参数信息示例如下，可以使用被分享文件的文件描述符（FD）进行相应操作。

```json
{
    "deviceId": "",
    "bundleName": "com.example.myapplication",
    "abilityName": "EntryAbility",
    "moduleName": "entry",
    "uri": "",
    "type": "application/pdf",
    "flags": 0,
    "action": "ohos.want.action.sendData",
    "parameters": {
        "component.startup.newRules": true,
        "keyFd": {
            "type": "FD",
            "value": 36
        },
        "mime-type": "application/pdf",
        "moduleName": "entry",
        "ohos.aafwk.param.callerPid": 3488,
        "ohos.aafwk.param.callerToken": 537379209,
        "ohos.aafwk.param.callerUid": 20010014
    },
    "entities": []
}
```
