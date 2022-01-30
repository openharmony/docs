# 应用事件开发指导

## 场景介绍

应用事件打点的主要工作是在应用运行过程中，帮助应用记录在运行过程中发生的各种信息。

## 接口说明

应用事件JS打点接口由hiAppEvent模块提供。

**打点接口功能介绍：**

| 接口名                                                       | 返回值         | 描述                                                 |
| ------------------------------------------------------------ | -------------- | ---------------------------------------------------- |
| write(string eventName, EventType type, object keyValues, AsyncCallback\<void> callback): void | void           | 应用事件异步打点方法，使用callback方式作为异步回调。 |
| write(string eventName, EventType type, object keyValues): Promise\<void> | Promise\<void> | 应用事件异步打点方法，使用promise方式作为异步回调。  |

- 参数eventName：开发者自定义事件名称。事件名称在48个字符以内，有效的字符是0-9、a-z、下划线，只能以字母开头。

- 参数type：事件所属的类型，取值为枚举EventType，具体值如下表。

  | 类型      | 描述           |
  | --------- | -------------- |
  | FAULT     | 故障类型事件。 |
  | STATISTIC | 统计类型事件。 |
  | SECURITY  | 安全类型事件。 |
  | BEHAVIOR  | 行为类型事件。 |

- 参数keyValues：事件参数键值对，如果是变长参数类型，则依次输入事件的参数名与参数值。如果是Json对象类型，则Json对象的key是事件的参数名，value是事件的参数值。
  - 参数名只支持string类型，参数值只支持boolean、number、string、Array（数组参数值为基本类型）。
  - 事件的参数个数必须小于等于32。
  - 参数名在16个字符以内，有效的字符是0-9、a-z、下划线，只能以字母开头，不能以下划线结尾。
  - string类型参数值在8*1024个字符内。
  - Array类型参数值的元素个数必须在100个以内，超出时会进行截断处理。
- 参数callback：回调函数，可以在回调函数中处理接口返回值。返回值为0表示事件参数校验成功，事件正常异步写入事件文件；大于0表示事件存在异常参数，事件在忽略异常参数后再异步写入事件文件；小于0表示事件校验失败，不执行事件异步打点操作。

当采用callback作为异步回调时，可以在callback中进行下一步处理。当采用Promise对象返回时，可以在Promise对象中类似地处理接口返回值。具体结果码说明见[事件校验结果码](hiappevent-overview.md#事件校验结果码)。

**打点配置接口功能介绍：**

| 接口名                         | 返回值  | 描述                                                         |
| ------------------------------ | ------- | ------------------------------------------------------------ |
| configure(ConfigOption config) | boolean | 应用事件打点配置方法，可以对打点功能进行自定义配置。返回true表示配置成功，false表示配置失败。 |

- 参数config：应用事件打点配置项对象。应用打点配置选项ConfigOption如下表。

  | 参数名     | 类型    | 必填 | 说明                                                         |
  | ---------- | ------- | ---- | ------------------------------------------------------------ |
  | disable    | boolean | 否   | 应用打点功能开关，例如配置值为true表示关闭打点功能。         |
  | maxStorage | string  | 否   | 打点落盘文件存放目录的配额大小，默认限额为“10M”，超出限额后会对存放目录进行清理。 |


**预定义事件名称常量接口Event：**
| 常量名                    | 类型   | 描述                     |
| ------------------------- | ------ | ------------------------ |
| USER_LOGIN                | string | 用户登录事件名称。       |
| USER_LOGOUT               | string | 用户登出事件名称。       |
| DISTRIBUTED_SERVICE_START | string | 分布式服务启动事件名称。 |


**预定义参数名称常量接口Param：**
| 常量名                          | 类型   | 描述               |
| ------------------------------- | ------ | ------------------ |
| USER_ID                         | string | 用户自定义ID。     |
| DISTRIBUTED_SERVICE_NAME        | string | 分布式服务名称。   |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | 分布式服务示例ID。 |

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


