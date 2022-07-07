# 应用事件打点开发指导

## 场景介绍

应用事件打点的主要用于帮助应用记录在运行过程中发生的各种信息。

## 接口说明

应用事件JS打点接口由hiAppEvent模块提供。

以下仅提供简单的API接口介绍，具体使用说明（参数使用限制、具体取值范围等），请参考[应用事件打点API参考](../reference/apis/js-apis-hiappevent.md)。

**表1** 打点接口功能介绍

| 接口名                                                       | 返回值         | 描述                                                 |
| ------------------------------------------------------------ | -------------- | ---------------------------------------------------- |
| write(string eventName, EventType type, object keyValues, AsyncCallback\<void> callback): void | void           | 应用事件异步打点方法，使用callback方式作为异步回调。 |
| write(string eventName, EventType type, object keyValues): Promise\<void> | Promise\<void> | 应用事件异步打点方法，使用Promise方式作为异步回调。  |

当采用callback作为异步回调时，可以在callback中进行下一步处理。当采用Promise对象返回时，可以在Promise对象中类似地处理接口返回值。具体结果码说明见[事件校验结果码](#事件校验结果码)。

**表2** 打点配置接口功能介绍

| 接口名                         | 返回值  | 描述                                                         |
| ------------------------------ | ------- | ------------------------------------------------------------ |
| configure(ConfigOption config) | boolean | 应用事件打点配置方法，可以对打点功能进行自定义配置。返回true表示配置成功，false表示配置失败。 |

### 事件校验结果码

| 错误码 | 原因                        | 校验规则                                                     | 处理结果                                       |
| ------ | --------------------------- | ------------------------------------------------------------ | ------------------------------------------- |
| 0      | 无                          | 事件校验成功。                                                 | 事件正常打点。                                        |
| -1     | 无效的事件名称              | 非空且长度在48个字符以内（含）。<br>只由以下字符组成：0-9、a-z、_。<br/>非数字以及下划线开头。 | 忽略该事件，不执行打点。                              |
| -2     | 无效的事件基本参数类型      | 事件名称参数必须为string。<br/>事件类型参数必须为number类型。<br/>keyValues参数必须为object类型。 | 忽略该事件，不执行打点。                              |
| -99    | 应用打点功能被关闭          | 应用打点功能被关闭。                                         | 忽略该事件，不执行打点。                              |
| -100   | 未知错误                    | 无。                                                         | 忽略该事件，不执行打点。                              |
| 1      | 无效的key参数名称           | 非空且长度在16个字符以内（含）。<br/>只由以下字符组成：0-9、a-z、_。<br/>非数字以及下划线开头。<br/>非下划线结尾。 | 忽略该键值对参数后，继续执行打点。 |
| 2      | 无效的key参数类型           | Key参数必须为字符串类型。                                    | 忽略该键值对参数后，继续执行打点。                  |
| 3      | 无效的value参数类型         | value参数只支持以下类型：<br/>boolean、number、string、Array[基本类型]。 | 忽略该键值对参数后，继续执行打点。  |
| 4      | value参数值过长             | 参数值长度必须在8*1024个字符以内（含）。                     | 忽略该键值对参数后，继续执行打点。                   |
| 5      | key-value参数对数过多       | key-value参数对数必须在32对以内（含）。                      | 忽略后面多余的键值对参数后，继续执行打点。           |
| 6      | List类型的value参数容量过大 | List类型的value参数容量必须在100个以内（含）。               | 对List进行截断（只保留前100个元素）后，继续执行打点。 |
| 7      | 无效的List类型value参数     | List的泛型类型只能为基本类型。<br/>List内的参数必须为同一类型。 | 忽略该键值对参数后，继续执行打点。                    |

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

2. 点击应用界面上的运行按钮运行项目。

## 相关实例

针对应用事件打点开发，有以下相关实例可供参考：

- [`JsDotTest`：测试打点（JS）（API8）](https://gitee.com/openharmony/app_samples/tree/master/DFX/JsDotTest)