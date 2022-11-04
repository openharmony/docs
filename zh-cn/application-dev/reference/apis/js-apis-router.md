# 页面路由

本模块提供通过不同的url访问不同的页面，包括跳转到应用内的指定页面、用应用内的某个页面替换当前页面、返回上一页面或指定的页面等。

> **说明**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 页面路由需要在页面渲染完成之后才能调用，在onInit和onReady生命周期中页面还处于渲染阶段，禁止调用页面路由方法。

## 导入模块

```
import router from '@ohos.router'
```

## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions): Promise&lt;void&gt;

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID   | 错误码信息 |
| --------- | ------- |
| 100001    | Internal error. |
| 100002    | Uri error. The uri of router is not exist. |
| 100003    | Page stack error. The pages are pushed too much. |

**示例：**

```js
try {
  router.pushUrl({
    url: 'pages/routerpage2',
    params: {
      data1: 'message',
      data2: {
        data3: [123, 456, 789]
      },
    },
  })
    .then(() => {
      // success
    })
    .catch(err => {
      console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);
    })
} catch (error) {
  console.error(`pushUrl args error code is ${error.code}, message is ${error.message}`);
};
```

## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions, callback: AsyncCallback&lt;void&gt;): void

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调    |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID   | 错误码信息 |
| --------- | ------- |
| 100001    | Internal error. |
| 100002    | Uri error. The uri of router is not exist. |
| 100003    | Page stack error. The pages are pushed too much. |

**示例：**

```js
try {
  router.pushUrl({
    url: 'pages/routerpage2',
    params: {
      data1: 'message',
      data2: {
        data3: [123, 456, 789]
      },
    },
  }, (err) => {
    if (err) {
      console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('pushUrl success');
  });
} catch (error) {
  console.error(`pushUrl args error code is ${error.code}, message is ${error.message}`);
};
```
## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions, mode: RouterMode): Promise&lt;void&gt;

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID   | 错误码信息 |
| --------- | ------- |
| 100001    | Internal error. |
| 100002    | Uri error. The uri of router is not exist. |
| 100003    | Page stack error. The pages are pushed too much. |

**示例：**

```js
try {
  router.pushUrl({
    url: 'pages/routerpage2',
    params: {
      data1: 'message',
      data2: {
        data3: [123, 456, 789]
      },
    },
  }, router.RouterMode.Standard)
    .then(() => {
      // success
    })
    .catch(err => {
      console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);
    })
} catch (error) {
  console.error(`pushUrl args error code is ${error.code}, message is ${error.message}`);
};
```

## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback&lt;void&gt;): void

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调    |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID   | 错误码信息 |
| --------- | ------- |
| 100001    | Internal error. |
| 100002    | Uri error. The uri of router is not exist. |
| 100003    | Page stack error. The pages are pushed too much. |

**示例：**

```js
try {
  router.pushUrl({
    url: 'pages/routerpage2',
    params: {
      data1: 'message',
      data2: {
        data3: [123, 456, 789]
      },
    },
  }, router.RouterMode.Standard, (err) => {
    if (err) {
      console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('pushUrl success');
  });
} catch (error) {
  console.error(`pushUrl args error code is ${error.code}, message is ${error.message}`);
};
```

## router.replaceUrl<sup>9+</sup>

replaceUrl(options: RouterOptions): Promise&lt;void&gt;

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名  | 类型                            | 必填 | 说明               |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | 是   | 替换页面描述信息。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID   | 错误码信息 |
| --------- | ------- |
| 100001    | Internal error. |
| 200002    | Uri error. The uri of router is not exist. |

**示例：**

```js
try {
  router.replaceUrl({
    url: 'pages/detail',
    params: {
      data1: 'message',
    },
  })
    .then(() => {
      // success
    })
    .catch(err => {
      console.error(`replaceUrl failed, code is ${err.code}, message is ${err.message}`);
    })
} catch (error) {
  console.error(`replaceUrl args error code is ${error.code}, message is ${error.message}`);
};
```

## router.replaceUrl<sup>9+</sup>

replaceUrl(options: RouterOptions, callback: AsyncCallback&lt;void&gt;): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名  | 类型                            | 必填 | 说明               |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | 是   | 替换页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调    |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID   | 错误码信息 |
| --------- | ------- |
| 100001    | Internal error. |
| 200002    | Uri error. The uri of router is not exist. |

**示例：**

```js
try {
  router.replaceUrl({
    url: 'pages/detail',
    params: {
      data1: 'message',
    },
  }, (err) => {
    if (err) {
      console.error(`replaceUrl failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('replaceUrl success');
  });
} catch (error) {
  console.error(`replaceUrl args error code is ${error.code}, message is ${error.message}`);
};
```

## router.replaceUrl<sup>9+</sup>

replaceUrl(options: RouterOptions, mode: RouterMode): Promise&lt;void&gt;

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 替换页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |


**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID   | 错误码信息 |
| --------- | ------- |
| 100001    | Internal error. |
| 200002    | Uri error. The uri of router is not exist. |

**示例：**

```js
try {
  router.replaceUrl({
    url: 'pages/detail',
    params: {
      data1: 'message',
    },
  }, router.RouterMode.Standard)
    .then(() => {
      // success
    })
    .catch(err => {
      console.error(`replaceUrl failed, code is ${err.code}, message is ${err.message}`);
    })
} catch (error) {
  console.error(`replaceUrl args error code is ${error.code}, message is ${error.message}`);
};
```

## router.replaceUrl<sup>9+</sup>

replaceUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback&lt;void&gt;): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 替换页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调    |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID   | 错误码信息 |
| --------- | ------- |
| 100001    | Internal error. |
| 200002    | Uri error. The uri of router is not exist. |

**示例：**

```js
try {
  router.replaceUrl({
    url: 'pages/detail',
    params: {
      data1: 'message',
    },
  }, router.RouterMode.Standard, (err) => {
    if (err) {
      console.error(`replaceUrl failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('replaceUrl success');
  });
} catch (error) {
  console.error(`replaceUrl args error code is ${error.code}, message is ${error.message}`);
};
```

## router.back

back(options?: RouterOptions ): void

返回上一页面或指定的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                            | 必填 | 说明                                                         |
| ------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| options | [RouterOptions](#routeroptions) | 否   | 返回页面描述信息，其中参数url指路由跳转时会返回到指定url的界面，如果页面栈上没有url页面，则不响应该情况。如果url未设置，则返回上一页，页面栈里面的page不会回收，出栈后会被回收。 |

**示例：**

```js
router.back({url:'pages/detail'});    
```

## router.clear

clear(): void

清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```js
router.clear();    
```

## router.getLength

getLength(): string

获取当前在页面栈内的页面数量。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| string | 页面数量，页面栈支持最大数值是32。 |

**示例：**

```js
var size = router.getLength();        
console.log('pages stack size = ' + size);    
```

## router.getState

getState(): RouterState

获取当前页面的状态信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                          | 说明      |
| --------------------------- | ------- |
| [RouterState](#routerstate) | 页面状态信息。 |

**示例：** 

```js
var page = router.getState();
console.log('current index = ' + page.index);
console.log('current name = ' + page.name);
console.log('current path = ' + page.path);
```

## RouterState

页面状态信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full。

| 名称    | 类型     | 说明                                 |
| ----- | ------ | ---------------------------------- |
| index | number | 表示当前页面在页面栈中的索引。从栈底到栈顶，index从1开始递增。 |
| name  | string | 表示当前页面的名称，即对应文件名。                  |
| path  | string | 表示当前页面的路径。                         |

## router.enableBackPageAlert<sup>9+</sup>

enableBackPageAlert(options: EnableAlertOptions): void

开启页面返回询问对话框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [EnableAlertOptions](#enablealertoptions) | 是    | 文本弹窗信息描述。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID   | 错误码信息 |
| --------- | ------- |
| 100001    | Internal error. |

**示例：**

  ```js    
try {
  router.enableBackPageAlert({            
    message: 'Message Info'        
  });
} catch(error) {
  console.error(`enableBackPageAlert failed, code is ${error.code}, message is ${error.message}`);
}
  ```
## EnableAlertOptions

页面返回询问对话框选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

| 名称      | 类型     | 必填   | 说明       |
| ------- | ------ | ---- | -------- |
| message | string | 是    | 询问对话框内容。 |

## router.disableAlertBeforeBackPage

disableAlertBeforeBackPage(): void

禁用页面返回询问对话框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```js
router.disableAlertBeforeBackPage();    
```

##  router.getParams

getParams(): Object

获取发起跳转的页面往当前页传入的参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                |
| ------ | ----------------- |
| Object | 发起跳转的页面往当前页传入的参数。 |

**示例：**

```
router.getParams();
```

## RouterOptions

路由跳转选项。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite。

| 名称   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| url    | string | 是   | 表示目标页面的url，可以用以下两种格式：<br/>-&nbsp;页面绝对路径，由配置文件中pages列表提供，例如：<br/>&nbsp;&nbsp;-&nbsp;pages/index/index<br/>&nbsp;&nbsp;-&nbsp;pages/detail/detail<br/>-&nbsp;特殊值，如果url的值是"/"，则跳转到首页。 |
| params | Object | 否   | 表示路由跳转时要同时传递到目标页面的数据。跳转到目标页面后，使用router.getParams()获取传递的参数，此外，在类web范式中，参数也可以在页面中直接使用，如this.keyValue(keyValue为跳转时params参数中的key值)，如果目标页面中已有该字段，则其值会被传入的字段值覆盖。 |


  > **说明：**
  > 页面路由栈支持的最大Page数量为32。

## RouterMode<sup>9+</sup>

路由跳转模式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full。

| 名称       | 描述                                       |
| -------- | ---------------------------------------- |
| Standard | 标准模式。 <br/>目标页面会被添加到页面路由栈顶，无论栈中是否存在相同url的页面。                            |
| Single   | 单实例模式。<br/>如果目标页面的url在页面栈中已经存在同url页面，离栈顶最近的页面会被移动到栈顶，移动后的页面为新建页。<br/>如目标页面的url在页面栈中不存在同url页面，按标准模式跳转。 |

## 完整示例

### 基于JS扩展的类Web开发范式

```js
// 在当前页面中
export default {
  pushPage() {
    router.push({
      url: 'pages/detail/detail',
      params: {
        data1: 'message',
      },
    });
  }
}
```
```js
// 在detail页面中
export default {
  onInit() {
    console.info('showData1:' + router.getParams()[data1]);
  }
}
```

### 基于TS扩展的声明式开发范式

```ts
//通过router.push跳转至目标页携带params参数
import router from '@ohos.router'

@Entry
@Component
struct Index {
  async  routePage() {
    let options = {
      url: 'pages/second',
      params: {
        text: '这是第一页的值',
        data: {
          array: [12, 45, 78]
        },
      }
    }
    try {
      await router.push(options)
    } catch (err) {
      console.info(` fail callback, code: ${err.code}, msg: ${err.msg}`)
    }
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Text('这是第一页')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      Button() {
        Text('next page')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
          .margin({ top: 20 })
          .backgroundColor('#ccc')
          .onClick(() => {
            this.routePage()
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

```ts
//在second页面中接收传递过来的参数
import router from '@ohos.router'

@Entry
@Component
struct Second {
  private content: string = "这是第二页"
  @State text: string = router.getParams()['text']
  @State data: any = router.getParams()['data']
  @State secondData : string = ''
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text(`${this.content}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Text(this.text)
        .fontSize(30)
        .onClick(()=>{
          this.secondData = (this.data.array[1]).toString()
        })
      .margin({top:20})
      Text('第一页传来的数值' + '  ' + this.secondData)
        .fontSize(20)
        .margin({top:20})
        .backgroundColor('red')      
    }
    .width('100%')
    .height('100%')
  }
}
```

## router.push<sup>(deprecated)</sup>

push(options: RouterOptions): void

跳转到应用内的指定页面。

从API version9开始不再维护，建议使用[pushUrl<sup>9+</sup>](#routerpushurl9)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。 |


**示例：**

```js
router.push({
  url: 'pages/routerpage2',
  params: {
    data1: 'message',
    data2: {
      data3: [123, 456, 789]
    },
  },
});
```
## router.push<sup>(deprecated)</sup>

push(options: RouterOptions, mode: RouterMode): void

跳转到应用内的指定页面。

从API version9开始不再维护，建议使用[pushUrl<sup>9+</sup>](#routerpushurl9)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |


**示例：**

```js
router.push({
  url: 'pages/routerpage2/routerpage2',
  params: {
    data1: 'message',
    data2: {
      data3: [123, 456, 789]
    },
  },
},router.RouterMode.Standard);
```

## router.replace<sup>(deprecated)</sup>

replace(options: RouterOptions): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

从API version9开始不再维护，建议使用[replaceUrl<sup>9+</sup>](#routerreplaceurl9)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                            | 必填 | 说明               |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | 是   | 替换页面描述信息。 |

**示例：**

```js
router.replace({
  url: 'pages/detail',
  params: {
    data1: 'message',
  },
});
```

  ## router.replace<sup>(deprecated)</sup>

replace(options: RouterOptions, mode: RouterMode): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

从API version9开始不再维护，建议使用[replaceUrl<sup>9+</sup>](#routerreplaceurl9)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 替换页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |

**示例：**

```js
router.replace({
  url: 'pages/detail/detail',
  params: {
    data1: 'message',
  },
}, router.RouterMode.Standard);
```

## router.enableAlertBeforeBackPage<sup>(deprecated)</sup>

enableAlertBeforeBackPage(options: EnableAlertOptions): void

开启页面返回询问对话框。

从API version9开始不再维护，建议使用[enableBackPageAlert<sup>9+</sup>](#routerenablebackpagealert9)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [EnableAlertOptions](#enablealertoptions) | 是    | 文本弹窗信息描述。 |

**示例：**

  ```js        
  router.enableAlertBeforeBackPage({            
    message: 'Message Info'        
  });    
  ```