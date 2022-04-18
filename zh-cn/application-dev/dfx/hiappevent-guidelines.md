# 应用事件开发指导

## 场景介绍

应用事件打点的主要工作是在应用运行过程中，帮助应用记录在运行过程中发生的各种信息。

## 接口说明

应用事件JS打点接口由hiAppEvent模块提供。

以下仅提供简单的接口介绍，API接口的具体使用说明（参数使用限制、具体取值范围等），请参考[应用事件打点API文档](../reference/apis/js-apis-hiappevent.md)。

**打点接口功能介绍：**

| 接口名                                                       | 返回值         | 描述                                                 |
| ------------------------------------------------------------ | -------------- | ---------------------------------------------------- |
| write(string eventName, EventType type, object keyValues, AsyncCallback\<void> callback): void | void           | 应用事件异步打点方法，使用callback方式作为异步回调。 |
| write(string eventName, EventType type, object keyValues): Promise\<void> | Promise\<void> | 应用事件异步打点方法，使用promise方式作为异步回调。  |

当采用callback作为异步回调时，可以在callback中进行下一步处理。当采用Promise对象返回时，可以在Promise对象中类似地处理接口返回值。具体结果码说明见[事件校验结果码](hiappevent-overview.md#事件校验结果码)。

**打点配置接口功能介绍：**

| 接口名                         | 返回值  | 描述                                                         |
| ------------------------------ | ------- | ------------------------------------------------------------ |
| configure(ConfigOption config) | boolean | 应用事件打点配置方法，可以对打点功能进行自定义配置。返回true表示配置成功，false表示配置失败。 |

## 开发步骤

在应用启动执行页面加载后，执行一个应用事件打点，用于记录应用的初始页面加载事件。

1. 新建一个JS应用工程，在“Project”窗口点击“entry > src > main > js > default > pages > index”，打开工程中的“index.js”文件，在页面执行加载后，执行一个应用事件打点，用于记录应用的初始页面加载事件，示例代码如下：

   ```js
   import hiAppEvent from '@ohos.hiAppEvent'
   
   export default {
       data: {
           title: ""
       },
       onInit() {
           this.title = this.$t('strings.world');
   
           // 1.callback方式
           hiAppEvent.write("start_event", hiAppEvent.EventType.BEHAVIOR, {"int_data":100, "str_data":"strValue"}, (err, value) => {
               if (err) {
                   console.error(`failed to write event because ${err.code}`);
                   return;
               }
               console.log(`success to write event: ${value}`);
           });
   
           // 2.Promise方式
           hiAppEvent.write("start_event", hiAppEvent.EventType.BEHAVIOR, {"int_data":100, "str_data":"strValue"})
               .then((value) => {
                   console.log(`success to write event: ${value}`);
               }).catch((err) => {
                   console.error(`failed to write event because ${err.code}`);
               });
   
           // 3.配置应用打点开关
           hiAppEvent.configure({
               disable: true
           });
   
           // 4.配置事件文件目录限额（默认为10M）
           hiAppEvent.configure({
               maxStorage: '100M'
           });
       }
   }
   ```

2. 运行项目，点击应用界面上的运行按钮。

## 相关实例

针对应用事件开发，有以下相关实例可供参考：

- [`JsDotTest:`测试打点（JS）（API7）](https://gitee.com/openharmony/app_samples/tree/master/DFX/JsDotTest)