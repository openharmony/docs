# PrintExtensionAbility开发指导

## 场景介绍
PrintExtensionAbility类定义了打印扩展生命周期方法，开发者可以自定义类继承PrintExtensionAbility，通过重写基类中相关生命周期方法，来实现打印机发现、连接，打印任务启动、取消，打印机能力和打印预览的查询等相关业务逻辑操作。

> **说明：**
>  
> PrintExtensionAbility仅可在Stage模型下使用。

## 接口说明

**表1** PrintExtensionAbility中相关生命周期API功能介绍

|接口名|描述|
|:------|:------|
|onCreated(want:&nbsp;Want):&nbsp;void| PrintExtension生命周期回调，在创建时回调，执行初始化业务逻辑操作。| 
|onStartDiscoverPrinter():&nbsp;void | PrintExtension生命周期回调，执行发现打印机业务逻辑操作。|
|onStopDiscoverPrinter():&nbsp;void| PrintExtension生命周期回调，执行停止发现打印机业务逻辑操作。|
|onConnectPrinter(printerId:&nbsp;number):&nbsp;void| PrintExtension生命周期回调，执行连接打印机业务逻辑操作。
|onDisconnectPrinter(printerId:&nbsp;number):&nbsp;void|PrintExtension生命周期回调，执行连接打印机业务逻辑操作。|
|onStartPrintJob(jobInfo:&nbsp;print.PrintJob):&nbsp;void|PrintExtension生命周期回调，执行启动打印任务业务逻辑操作。|
|onCancelPrintJob(jobInfo:&nbsp;print.PrintJob):&nbsp;void| PrintExtension生命周期回调，执行取消打印任务业务逻辑操作。|
|onRequestPrinterCapability(printerId:&nbsp;number):&nbsp;print.PrinterCapability| PrintExtension生命周期回调，在print.queryPrinterCapability调用时回调，执行查询打印机能力业务逻辑操作。|
|onRequestPreview(jobInfo:&nbsp;print.PrintJob):&nbsp;string| PrintExtension生命周期回调，执行查询打印预览业务逻辑操作。|
|onDestroy():&nbsp;void| PrintExtension生命周期回调，在销毁时回调，执行资源清理等操作。|


## 约束与限制

OpenHarmony当前不支持三方应用创建PrintExtensionAbility。


## 开发步骤

1. 需要在应用配置文件module.json5中进行注册，注册类型type需要设置为service。module.json5配置样例如下所示：

```json
    "extensionAbilities":[{
        "name": "CustomPrintExtensionAbility",
        "srcEntrance": "./ets/PrintExtensionAbility/CustomPrintExtensionAbility.ts",
        "label": "$string:form_FormAbility_label",
        "description": "$string:form_FormAbility_desc",
        "type": "service",
        "metadata": [
          {
            "name": "ohos.extension.form",
            "resource": "$profile:form_config"
          }
    }]
```

2. 请求权限。

   需要在`config.json`文件里进行配置请求权限，用于使用打印相关API[打印管理API](../reference/apis/js-apis-print.md#print)，示例代码如下：

    ```json
     {
       "module": {
           "reqPermissions": [
               {
                  "name": "ohos.permission.MANAGE_PRINT_JOB"
               }
           ]
       }
     }
    ```


3. 开发者在定义Service的目录下创建TS文件，自定义类继承PrintExtensionAbility，重写基类回调函数，接口生成的默认相对路径：entry\src\main\ets\PrintExtensionAbility\CustomPrintExtensionAbility.ts，示例如下：

```js
import PrintExtensionAbility from '@ohos.PrintExtension';
import print from "@ohos.print";
import Want from '@ohos.application.Want';

export default class CustomPrintExtensionAbility extends PrintExtensionAbility {
    MODULE_TAG: string = "customPrintExtensionAbility"

    onCreated(want: Want): void {
        console.info(this.MODULE_TAG + 'ability on created start');
    }

    onStartDiscoverPrinter() {
        console.info(this.MODULE_TAG + "ability start to discover printer");
        let printer1 = {
            printerId: 1, // printer id
            printerName: 'string', // printer name
            printerIcon: 1, // resource id of printer icon
            printerState: 1, // current printer state
            description: 'string', // printer description
            capability: PrinterCapability,
        }
        let printer2 = {
            printerId: 2, // printer id
            printerName: 'char', // printer name
            printerIcon: 2, // resource id of printer icon
            printerState: 2, // current printer state
            description: 'char', // printer description
            capability: PrinterCapability,
        }

      let printers = [printer1, printer2]

      print.addPrinters(printers, (err, data) => {
      if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
       }
       console.info('Operation successful. Data:' + JSON.stringify(data));
     });
    }
    onStopDiscoverPrinter() {
        console.info(this.MODULE_TAG + 'ability stop discovering printer');

    }
    onConnectPrinter(printerId) {
        console.info(this.MODULE_TAG + 'ability connect the speci1 printer');
        console.info(this.MODULE_TAG + 'onConnectPrinter printerId: ' + JSON.stringify(printerId));

    }
    onDisconnectPrinter(printerId) {
        console.info(this.MODULE_TAG + 'ability disconnect the speci1 printer');
        console.info(this.MODULE_TAG + 'onDisconnectPrinter printerId: ' + JSON.stringify(printerId));
    }
    onStartPrintJob(jobInfo) {
        console.info(this.MODULE_TAG + 'ability start Print Job');
        console.info(this.MODULE_TAG + 'onStartPrintJob jobInfo: ' + JSON.stringify(jobInfo));
    }
    onCancelPrintJob(jobInfo) {
        console.info(this.MODULE_TAG + 'ability cancel Print Job');
        console.info(this.MODULE_TAG + 'onCancelPrintJob jobInfo: ' + JSON.stringify(jobInfo));

    }
    onRequestPrinterCapability(printerId) {
        console.info(this.MODULE_TAG + 'ability request printer capability');
        console.info(this.MODULE_TAG + 'onRequestPrinterCapability printerId: ' + JSON.stringify(printerId));

        let PrinterPageSizeArr = [
            {
                id: '1',
                name: 'string',
                width: 200,
                height: 200,
            }
        ]
        let PrintMargin = {
            top: 1,
            bottom: 2,
            left: 1,
            right: 1,
        }
        let PrinterResolutionArr = [
            {
                id: 2,
                horizontalDpi: 2,
                verticalDpi: 1,
            }
        ]
        let cap = {
            minMargin: PrintMargin,
            pageSize: PrinterPageSizeArr,
            resolution: PrinterResolutionArr,
            colorMode: 1,
            duplexMode: 2,
        }
        return cap;
    }

    onRequestPreview(jobInfo) {
        console.info(this.MODULE_TAG + 'ability request printer preview');
        console.info(this.MODULE_TAG + 'onRequestPreview jobInfo: ' + JSON.stringify(jobInfo));

    }
    onDestroy() {
        console.info(this.MODULE_TAG + 'ability on destroy');
    }
};
    ```
## 相关实例

针对PrintExtensionAbility开发，有以下相关实例可供参考：

- [`Print_Extension_demo`：打印扩展（eTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/Print/project-printExtension)
