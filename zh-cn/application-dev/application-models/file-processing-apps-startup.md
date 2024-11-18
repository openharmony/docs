# 拉起文件处理类应用（startAbility）

## 使用场景

开发者可以通过调用[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口，由系统从已安装的应用中寻找符合要求的应用，打开特定文件。

例如，浏览器下应用下载PDF文件，可以调用此接口选择文件处理应用打开此PDF文件。开发者需要在请求中设置待打开文件的URI路径（[uri](#接口关键参数说明)）、文件格式（[type](#接口关键参数说明)）等字段，以便系统能够识别，直接拉起文件打开应用或弹出一个选择框，让用户选择合适的应用来打开文件，效果示意如下图所示。

图1 效果示意图<br>
![](figures/file-open.jpeg)

## 接口关键参数说明

开发者通过调用[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口即可实现由已安装的垂域应用来打开文件。

表1 startAbility请求中[want](../reference/apis-ability-kit/js-apis-app-ability-want.md)相关参数说明

| 参数名称 | 类型   | 是否必填 | 说明                  |
|----------|--------|----------|---------------------|
| uri      | string | 是       | 表示待打开文件的URI路径，一般配合type使用。<br />uri格式为：file:\/\/bundleName\/path<br />- file：文件URI的标志。<br />- bundleName：该文件资源的属主。<br />- path：文件资源在应用沙箱中的路径。 |
| type     | string | 否       | 表示MIME type类型描述，打开文件的类型。比如：'text/xml' 、 'image/*'等，MIME定义请参见https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com。<br>**说明：** <br>1. type为可选字段，如果不传type，系统会尝试根据uri后缀名判断文件类型进行匹配；如果传入type，必须确保与uri的文件类型一致，否则会导致无法匹配到合适的应用。文件后缀与文件类型的映射关系参见[Uniform Type Descriptor(UTD)预置列表](../database/uniform-data-type-list.md)。<br>2. 不支持传\*/\*。                  |
| parameters | Record<string, Object>       | 否         | 表示由系统定义，由开发者按需赋值的自定义参数，文件打开场景请参考表2。         |
| flags | number | 否 | 表示处理方式，文件打开场景请参考表3。                                                                                                                                                                                       |

**表2** [parameters](../reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#params)相关参数说明


| 参数名称                              | 类型    | 说明                                                                                                                                                                |
|---------------------------------------|---------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ability.params.stream                 | string  | 指示携带的文件URI要授权给目标方，用于待打开的文件存在其他文件依赖的场景。例如打开本地html文件依赖本地其余资源文件的场景等。对应的value必须是string类型的文件URI数组。文件URI的获取参考表1中uri参数。 |
| ohos.ability.params.showDefaultPicker | boolean | 表示是否强制展示文件打开方式的选择弹框，缺省为false。<br>- false：表示由系统策略或默认应用设置决定直接拉起文件打开应用还是展示弹框。<br>- true：表示始终展示弹框。                                                                            |
| showCaller                            | boolean | 表示调用方本身是否作为目标方应用之一参与匹配，缺省为false。<br>- false：不参与匹配。<br>- true：参与匹配。                                                                            |

**表3** [flags](../reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags)相关参数说明

| 参数名称                       | 值         | 说明                       |
|--------------------------------|------------|----------------------------|
| FLAG_AUTH_READ_URI_PERMISSION  | 0x00000001 | 指对URI执行读取操作的授权。 |
| FLAG_AUTH_WRITE_URI_PERMISSION | 0x00000002 | 指对URI执行写入操作的授权。 |

## 接入步骤

### 调用方接入步骤

1. 导入相关模块。

    ```ts
    // xxx.ets
    import { fileUri } from '@kit.CoreFileKit';
    import { UIAbility, Want, common, wantConstant } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 获取[应用文件路径](application-context-stage.md#获取应用文件路径)。

    ```ts
    // xxx.ets
    // 假设应用bundleName值为com.example.demo
    export default class EntryAbility extends UIAbility {
        onWindowStageCreate(windowStage: window.WindowStage) {
            // 获取文件沙箱路径
            let filePath = this.context.filesDir + '/test1.txt';
            // 将沙箱路径转换为uri
            let uri = fileUri.getUriFromPath(filePath);
            // 获取的uri为"file://com.example.demo/data/storage/el2/base/files/test.txt"
        }
        // ...
    }
    ```

3. 构造请求数据。

    ```ts
    // xxx.ets
    export default class EntryAbility extends UIAbility {
        onWindowStageCreate(windowStage: window.WindowStage) {
            // 获取文件沙箱路径
            let filePath = this.context.filesDir + '/test.txt';
            // 将沙箱路径转换为uri
            let uri = fileUri.getUriFromPath(filePath);
            // 构造请求数据
            let want: Want = {
            uri: uri,
            type: 'text/plain', // 表示待打开文件的类型
            // 配置被分享文件的读写权限，例如对文件打开应用进行读写授权
            flags: wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION | wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION
            };
        }
        // ...
    }
    ```

4. 调用接口启动。
    
    ```ts
    // xxx.ets
    export default class EntryAbility extends UIAbility {
        onWindowStageCreate(windowStage: window.WindowStage) {
            // 获取文件沙箱路径
            let filePath = this.context.filesDir + '/test.txt';
            // 将沙箱路径转换为uri
            let uri = fileUri.getUriFromPath(filePath);
            // 构造请求数据
            let want: Want = {
            uri: uri,
            type: 'text/plain', // 表示待打开文件的类型
            // 配置被分享文件的读写权限，例如对文件打开应用进行读写授权
            flags: wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION | wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION
            };
            // 调用接口启动
            this.context.startAbility(want)
            .then(() => {
                console.info('Succeed to invoke startAbility.');
            })
            .catch((err: BusinessError) => {
                console.error(`Failed to invoke startAbility, code: ${err.code}, message: ${err.message}`);
            });
        }
        // ...
    }
    ```

### 目标方接入步骤

1. 声明文件打开能力。

    支持打开文件的应用需要在[module.json5](../quick-start/module-configuration-file.md)配置文件中声明文件打开能力。其中uris字段表示接收URI的类型，其中scheme固定为file。type字段表示支持打开的文件类型（请参见[MIME定义](https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com)），如下举例中类型为txt文件。

    ```ts
    {
    "module": {
        // ...
        "abilities": [
        {
            // ...
            "skills": [
            {
                "actions": [
                "ohos.want.action.viewData" // 必填，声明数据处理能力
                ],
                "uris": [
                {
                    // 允许打开uri中以file://协议开头标识的本地文件
                    "scheme": "file", // 必填，声明协议类型为文件
                    "type": "text/plain", // 必填，表示支持打开的文件类型
                    "linkFeature": "FileOpen" // 必填且大小写敏感，表示此URI的功能为文件打开
                }
                // ...
                ]
                // ...
            }
            ]
        }
        ]
    }
    }
    ```


2. 应用处理待打开文件。

    声明了文件打开的应用在被拉起后，获取传入的[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md)参数信息，从中获取待打开文件的URI，在打开文件并获取对应的file对象后，可对文件进行读写操作。

    ```ts
    // xxx.ets
    import fs from '@ohos.file.fs';
    import { Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class EntryAbility extends UIAbility {
        onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
            // 从want信息中获取uri字段
            let uri = want.uri;
            if (uri == null || uri == undefined) {
                console.info('uri is invalid');
                return;
            }
            try {
                // 根据待打开文件的URI进行相应操作。例如同步读写的方式打开URI获取file对象
                let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
                console.info('Succeed to open file.');
            } catch (err) {
                let error: BusinessError = err as BusinessError;
                console.error(`Failed to open file openSync, code: ${error.code}, message: ${error.message}`);
            }
        }
    }
    ```


