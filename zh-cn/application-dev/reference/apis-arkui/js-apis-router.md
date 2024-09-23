# @ohos.router (页面路由)(不推荐)

本模块提供通过不同的url访问不同的页面，包括跳转到应用内的指定页面、同应用内的某个页面替换当前页面、返回上一页面或指定的页面等。

推荐使用[Navigation组件](../../ui/arkts-navigation-navigation.md)作为应用路由框架。

> **说明**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 页面路由需要在页面渲染完成之后才能调用，在onInit和onReady生命周期中页面还处于渲染阶段，禁止调用页面路由方法。
>
> - 本模块功能依赖UI的执行上下文，不可在UI上下文不明确的地方使用，参见[UIContext](./js-apis-arkui-UIContext.md#uicontext)说明。
>
> - 从API version 10开始，可以通过使用[UIContext](./js-apis-arkui-UIContext.md#uicontext)中的[getRouter](./js-apis-arkui-UIContext.md#getrouter)方法获取当前UI上下文关联的[Router](./js-apis-arkui-UIContext.md#router)对象。
>
> - 如果使用传入callback形式的pushUrl，pushNamedRoute接口，则在callback中使用getLength等接口获取的栈信息是中间态的栈信息，可能和最终状态不一致。

## 导入模块

```
import { router } from '@kit.ArkUI';
```

## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions): Promise&lt;void&gt;

跳转到应用内的指定页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100002    | Uri error. The URI of the page to redirect is incorrect or does not exist. |
| 100003    | Page stack error. Too many pages are pushed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class innerParams {
  data3:number[]

  constructor(tuple:number[]) {
    this.data3 = tuple
  }
}

class routerParams {
  data1:string
  data2:innerParams

  constructor(str:string, tuple:number[]) {
    this.data1 = str
    this.data2 = new innerParams(tuple)
  }
}

try {
  router.pushUrl({
    url: 'pages/routerpage2',
    params: new routerParams('message' ,[123,456,789])
  })
} catch (err) {
  console.error(`pushUrl failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
}
```

## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions, callback: AsyncCallback&lt;void&gt;): void

跳转到应用内的指定页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100002    | Uri error. The URI of the page to redirect is incorrect or does not exist. |
| 100003    | Page stack error. Too many pages are pushed. |

**示例：**

```ts
class innerParams {
  data3:number[]

  constructor(tuple:number[]) {
    this.data3 = tuple
  }
}

class routerParams {
  data1:string
  data2:innerParams

  constructor(str:string, tuple:number[]) {
    this.data1 = str
    this.data2 = new innerParams(tuple)
  }
}

router.pushUrl({
  url: 'pages/routerpage2',
  params: new routerParams('message' ,[123,456,789])
}, (err) => {
  if (err) {
    console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('pushUrl success');
})
```
## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions, mode: RouterMode): Promise&lt;void&gt;

跳转到应用内的指定页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100002    | Uri error. The URI of the page to redirect is incorrect or does not exist. |
| 100003    | Page stack error. Too many pages are pushed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class innerParams {
  data3:number[]

  constructor(tuple:number[]) {
    this.data3 = tuple
  }
}

class routerParams {
  data1:string
  data2:innerParams

  constructor(str:string, tuple:number[]) {
    this.data1 = str
    this.data2 = new innerParams(tuple)
  }
}

try {
  router.pushUrl({
    url: 'pages/routerpage2',
    params: new routerParams('message' ,[123,456,789])
  }, router.RouterMode.Standard)
} catch (err) {
  console.error(`pushUrl failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
}
```

## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback&lt;void&gt;): void

跳转到应用内的指定页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 跳转页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100002    | Uri error. The URI of the page to redirect is incorrect or does not exist. |
| 100003    | Page stack error. Too many pages are pushed. |

**示例：**

```ts
class innerParams {
  data3:number[]

  constructor(tuple:number[]) {
    this.data3 = tuple
  }
}

class routerParams {
  data1:string
  data2:innerParams

  constructor(str:string, tuple:number[]) {
    this.data1 = str
    this.data2 = new innerParams(tuple)
  }
}

router.pushUrl({
  url: 'pages/routerpage2',
  params: new routerParams('message' ,[123,456,789])
}, router.RouterMode.Standard, (err) => {
  if (err) {
    console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('pushUrl success');
})
```

## router.replaceUrl<sup>9+</sup>

replaceUrl(options: RouterOptions): Promise&lt;void&gt;

用应用内的某个页面替换当前页面，并销毁被替换的页面。不支持设置页面转场动效，如需设置，推荐使用[Navigation组件](../../ui/arkts-navigation-navigation.md)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名  | 类型                            | 必填 | 说明               |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | 是   | 替换页面描述信息。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 200002    | Uri error. The URI of the page to be used for replacement is incorrect or does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class routerParams {
  data1:string

  constructor(str:string) {
    this.data1 = str
  }
}

try {
  router.replaceUrl({
    url: 'pages/detail',
    params: new routerParams('message')
  })
} catch (err) {
  console.error(`replaceUrl failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
}
```

## router.replaceUrl<sup>9+</sup>

replaceUrl(options: RouterOptions, callback: AsyncCallback&lt;void&gt;): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名  | 类型                            | 必填 | 说明               |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | 是   | 替换页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 200002    | Uri error. The URI of the page to be used for replacement is incorrect or does not exist. |

**示例：**

```ts
class routerParams {
  data1:string

  constructor(str:string) {
    this.data1 = str
  }
}

router.replaceUrl({
  url: 'pages/detail',
  params: new routerParams('message')
}, (err) => {
  if (err) {
    console.error(`replaceUrl failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('replaceUrl success');
})
```

## router.replaceUrl<sup>9+</sup>

replaceUrl(options: RouterOptions, mode: RouterMode): Promise&lt;void&gt;

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 替换页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |


**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Failed to get the delegate. This error code is thrown only in the standard system. |
| 200002    | Uri error. The URI of the page to be used for replacement is incorrect or does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class routerParams {
  data1:string

  constructor(str:string) {
    this.data1 = str
  }
}

try {
  router.replaceUrl({
    url: 'pages/detail',
    params: new routerParams('message')
  }, router.RouterMode.Standard)
} catch (err) {
  console.error(`replaceUrl failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
}
```

## router.replaceUrl<sup>9+</sup>

replaceUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback&lt;void&gt;): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | 是    | 替换页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 200002    | Uri error. The URI of the page to be used for replacement is incorrect or does not exist. |

**示例：**

```ts
class routerParams {
  data1:string

  constructor(str:string) {
    this.data1 = str
  }
}

router.replaceUrl({
  url: 'pages/detail',
  params: new routerParams('message')
}, router.RouterMode.Standard, (err) => {
  if (err) {
    console.error(`replaceUrl failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('replaceUrl success');
});

```

## router.pushNamedRoute<sup>10+</sup>

pushNamedRoute(options: NamedRouterOptions): Promise&lt;void&gt;

跳转到指定的命名路由页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | 是    | 跳转页面描述信息。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100003    | Page stack error. Too many pages are pushed. |
| 100004    | Named route error. The named route does not exist. |

**示例：** 

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class innerParams {
  data3:number[]

  constructor(tuple:number[]) {
    this.data3 = tuple
  }
}

class routerParams {
  data1:string
  data2:innerParams

  constructor(str:string, tuple:number[]) {
    this.data1 = str
    this.data2 = new innerParams(tuple)
  }
}

try {
  router.pushNamedRoute({
    name: 'myPage',
    params: new routerParams('message' ,[123,456,789])
  })
} catch (err) {
  console.error(`pushNamedRoute failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
}
```

详细示例请参考：[UI开发-页面路由](../../ui/arkts-routing.md#命名路由)

## router.pushNamedRoute<sup>10+</sup>

pushNamedRoute(options: NamedRouterOptions, callback: AsyncCallback&lt;void&gt;): void

跳转到指定的命名路由页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | 是    | 跳转页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100003    | Page stack error. Too many pages are pushed. |
| 100004    | Named route error. The named route does not exist. |

**示例：**

```ts
class innerParams {
  data3:number[]

  constructor(tuple:number[]) {
    this.data3 = tuple
  }
}

class routerParams {
  data1:string
  data2:innerParams

  constructor(str:string, tuple:number[]) {
    this.data1 = str
    this.data2 = new innerParams(tuple)
  }
}

router.pushNamedRoute({
  name: 'myPage',
  params: new routerParams('message' ,[123,456,789])
}, (err) => {
  if (err) {
    console.error(`pushNamedRoute failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('pushNamedRoute success');
})
```
## router.pushNamedRoute<sup>10+</sup>

pushNamedRoute(options: NamedRouterOptions, mode: RouterMode): Promise&lt;void&gt;

跳转到指定的命名路由页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | 是    | 跳转页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100003    | Page stack error. Too many pages are pushed. |
| 100004    | Named route error. The named route does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class innerParams {
  data3:number[]

  constructor(tuple:number[]) {
    this.data3 = tuple
  }
}

class routerParams {
  data1:string
  data2:innerParams

  constructor(str:string, tuple:number[]) {
    this.data1 = str
    this.data2 = new innerParams(tuple)
  }
}

try {
  router.pushNamedRoute({
    name: 'myPage',
    params: new routerParams('message' ,[123,456,789])
  }, router.RouterMode.Standard)
} catch (err) {
  console.error(`pushNamedRoute failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
}
```

## router.pushNamedRoute<sup>10+</sup>

pushNamedRoute(options: NamedRouterOptions, mode: RouterMode, callback: AsyncCallback&lt;void&gt;): void

跳转到指定的命名路由页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | 是    | 跳转页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100003    | Page stack error. Too many pages are pushed. |
| 100004    | Named route error. The named route does not exist. |

**示例：**

```ts
class innerParams {
  data3:number[]

  constructor(tuple:number[]) {
    this.data3 = tuple
  }
}

class routerParams {
  data1:string
  data2:innerParams

  constructor(str:string, tuple:number[]) {
    this.data1 = str
    this.data2 = new innerParams(tuple)
  }
}

router.pushNamedRoute({
  name: 'myPage',
  params: new routerParams('message' ,[123,456,789])
}, router.RouterMode.Standard, (err) => {
  if (err) {
    console.error(`pushNamedRoute failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('pushNamedRoute success');
})
```

## router.replaceNamedRoute<sup>10+</sup>

replaceNamedRoute(options: NamedRouterOptions): Promise&lt;void&gt;

用指定的命名路由页面替换当前页面，并销毁被替换的页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                            | 必填 | 说明               |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [NamedRouterOptions](#namedrouteroptions10) | 是   | 替换页面描述信息。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 100004    | Named route error. The named route does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class routerParams {
  data1:string

  constructor(str:string) {
    this.data1 = str
  }
}

try {
  router.replaceNamedRoute({
    name: 'myPage',
    params: new routerParams('message')
  })
} catch (err) {
  console.error(`replaceNamedRoute failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
}
```

## router.replaceNamedRoute<sup>10+</sup>

replaceNamedRoute(options: NamedRouterOptions, callback: AsyncCallback&lt;void&gt;): void

用指定的命名路由页面替换当前页面，并销毁被替换的页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                            | 必填 | 说明               |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [NamedRouterOptions](#namedrouteroptions10) | 是   | 替换页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 100004    | Named route error. The named route does not exist. |

**示例：**

```ts
class routerParams {
  data1:string

  constructor(str:string) {
    this.data1 = str
  }
}

router.replaceNamedRoute({
  name: 'myPage',
  params: new routerParams('message')
}, (err) => {
  if (err) {
    console.error(`replaceNamedRoute failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('replaceNamedRoute success');
})
```

## router.replaceNamedRoute<sup>10+</sup>

replaceNamedRoute(options: NamedRouterOptions, mode: RouterMode): Promise&lt;void&gt;

用指定的命名路由页面替换当前页面，并销毁被替换的页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | 是    | 替换页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |


**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Failed to get the delegate. This error code is thrown only in the standard system. |
| 100004    | Named route error. The named route does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class routerParams {
  data1:string

  constructor(str:string) {
    this.data1 = str
  }
}

try {
  router.replaceNamedRoute({
    name: 'myPage',
    params: new routerParams('message')
  }, router.RouterMode.Standard)
} catch (err) {
  console.error(`replaceNamedRoute failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
}
```

## router.replaceNamedRoute<sup>10+</sup>

replaceNamedRoute(options: NamedRouterOptions, mode: RouterMode, callback: AsyncCallback&lt;void&gt;): void

用指定的命名路由页面替换当前页面，并销毁被替换的页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | 是    | 替换页面描述信息。  |
| mode    | [RouterMode](#routermode9)      | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 100004    | Named route error. The named route does not exist. |

**示例：**

```ts
class routerParams {
  data1:string

  constructor(str:string) {
    this.data1 = str
  }
}

router.replaceNamedRoute({
  name: 'myPage',
  params: new routerParams('message')
}, router.RouterMode.Standard, (err) => {
  if (err) {
    console.error(`replaceNamedRoute failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('replaceNamedRoute success');
});

```

## router.back

back(options?: RouterOptions ): void

返回上一页面或指定的页面，会删除当前页面与指定页面之间的所有页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                            | 必填 | 说明                                                         |
| ------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| options | [RouterOptions](#routeroptions) | 否   | 返回页面描述信息，其中参数url指路由跳转时会返回到指定url的界面，如果页面栈上没有url页面，则不响应该情况。如果url未设置，则返回上一页，页面不会重新构建，页面栈里面的page不会回收，出栈后会被回收。back是返回接口，url设置为特殊值"/"不生效。 |

**示例：**

```ts
router.back({url:'pages/detail'});    
```

## router.back<sup>12+</sup>

back(index: number, params?: Object): void;

返回指定的页面，会删除当前页面与指定页面之间的所有页面。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| index | number | 是    | 跳转目标页面的索引值。  |
| params    | Object      | 否    | 页面返回时携带的参数。 |

**示例：**

```ts
router.back(1);    
```
```ts
router.back(1, {info: '来自Home页'}); //携带参数返回
```

## router.clear

clear(): void

清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
router.clear();    
```

## router.getLength

getLength(): string

获取当前在页面栈内的页面数量。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| string | 页面数量，页面栈支持最大数值是32。 |

**示例：**

```ts
let size = router.getLength();        
console.log('pages stack size = ' + size);    
```

## router.getState

getState(): RouterState

获取栈顶页面的状态信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                          | 说明      |
| --------------------------- | ------- |
| [RouterState](#routerstate) | 页面状态信息。 |

**示例：** 

```ts
let page = router.getState();
console.log('current index = ' + page.index);
console.log('current name = ' + page.name);
console.log('current path = ' + page.path);
```

## router.getStateByIndex<sup>12+</sup>

getStateByIndex(index: number): RouterState | undefined

通过索引值获取对应页面的状态信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| index    | number | 是   | 表示要获取的页面索引。  |

**返回值：**

| 类型                          | 说明      |
| --------------------------- | ------- |
| [RouterState](#routerstate) \| undefined | 返回页面状态信息。索引不存在时返回undefined。 |

**示例：** 

```ts
let options:router.RouterState | undefined = router.getStateByIndex(1);
if (options != undefined) {
  console.log('index = ' + options.index);
  console.log('name = ' + options.name);
  console.log('path = ' + options.path);
  console.log('params = ' + options.params);
}
```
## router.getStateByUrl<sup>12+</sup>

getStateByUrl(url: string): Array&lt;RouterState&gt;

通过url获取对应页面的状态信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| url    | string | 是   | 表示要获取对应页面信息的url。  |

**返回值：**

| 类型                          | 说明      |
| --------------------------- | ------- |
| Array<[RouterState](#routerstate)> | 页面状态信息。 |

**示例：** 

```ts
let options:Array<router.RouterState> = router.getStateByUrl('pages/index');
for (let i: number = 0; i < options.length; i++) {
  console.log('index = ' + options[i].index);
  console.log('name = ' + options[i].name);
  console.log('path = ' + options[i].path);
  console.log('params = ' + options[i].params);
}
```

## RouterState

页面状态信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full。

| 名称  | 类型   | 必填 | 说明                                                         |
| ----- | ------ | ---- | ------------------------------------------------------------ |
| index | number | 是   | 表示当前页面在页面栈中的索引。从栈底到栈顶，index从1开始递增。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| name  | string | 是  | 表示当前页面的名称，即对应文件名。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| path  | string | 是   | 表示当前页面的路径。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| params<sup>12+</sup>  | Object |  是  | 表示当前页面携带的参数。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                         |

## router.showAlertBeforeBackPage<sup>9+</sup>

showAlertBeforeBackPage(options: EnableAlertOptions): void

开启页面返回询问对话框。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [EnableAlertOptions](#enablealertoptions) | 是    | 文本弹窗信息描述。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  router.showAlertBeforeBackPage({
    message: 'Message Info'
  });
} catch(err) {
  console.error(`showAlertBeforeBackPage failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
}
```
## EnableAlertOptions

页面返回询问对话框选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

| 名称      | 类型     | 必填   | 说明       |
| ------- | ------ | ---- | -------- |
| message | string | 是    | 询问对话框内容。 |

## router.hideAlertBeforeBackPage<sup>9+</sup>

hideAlertBeforeBackPage(): void

禁用页面返回询问对话框。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
router.hideAlertBeforeBackPage();    
```

##  router.getParams

getParams(): Object

获取发起跳转的页面往当前页传入的参数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型   | 说明                               |
| ------ | ---------------------------------- |
| object | 发起跳转的页面往当前页传入的参数。 |

**示例：**

```ts
router.getParams();
```

## RouterOptions

路由跳转选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite。

| 名称   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| url    | string | 是   | 表示目标页面的url，可以用以下两种格式：<br/>-&nbsp;页面绝对路径，由配置文件中pages列表提供，例如：<br/>&nbsp;&nbsp;-&nbsp;pages/index/index<br/>&nbsp;&nbsp;-&nbsp;pages/detail/detail<br/>-&nbsp;特殊值，如果url的值是"/"，则跳转到首页，首页默认为页面跳转配置项src数组的第一个数据项。 |
| params | Object | 否   | 表示路由跳转时要同时传递到目标页面的数据，切换到其他页面时，当前接收的数据失效。跳转到目标页面后，使用router.getParams()获取传递的参数，此外，在类web范式中，参数也可以在页面中直接使用，如this.keyValue(keyValue为跳转时params参数中的key值)，如果目标页面中已有该字段，则其值会被传入的字段值覆盖。<br/>**说明：** <br/>params参数不能传递方法和系统接口返回的对象（例如，媒体接口定义和返回的PixelMap对象）。建议开发者提取系统接口返回的对象中需要被传递的基础类型属性，自行构造object类型对象进行传递。 |


  > **说明：**
  > 页面路由栈支持的最大Page数量为32。

## RouterMode<sup>9+</sup>

路由跳转模式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full。

| 名称     | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| Standard | 多实例模式，也是默认情况下的跳转模式。 <br/>目标页面会被添加到页面栈顶，无论栈中是否存在相同url的页面。<br/>**说明：**  <br/>不使用路由跳转模式时，则按照默认的多实例模式进行跳转。 |
| Single   | 单实例模式。<br/>如果目标页面的url已经存在于页面栈中，则该url页面移动到栈顶。<br />如果目标页面的url在页面栈中不存在同url页面，则按照默认的多实例模式进行跳转。 |

## NamedRouterOptions<sup>10+</sup>

命名路由跳转选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | 是   | 表示目标命名路由页面的name。                                 |
| params | Object | 否   | 表示路由跳转时要同时传递到目标页面的数据。跳转到目标页面后，使用router.getParams()获取传递的参数，此外，在类web范式中，参数也可以在页面中直接使用，如this.keyValue(keyValue为跳转时params参数中的key值)，如果目标页面中已有该字段，则其值会被传入的字段值覆盖。 |

## 完整示例

### 基于JS扩展的类Web开发范式

以下代码仅适用于javascript文件，不适用于ArkTS文件

<!--code_no_check-->

```js
// 在当前页面中
export default {
  pushPage() {
    router.pushUrl({
      url: 'pages/detail/detail',
      params: {
        data1: 'message'
      }
    });
  }
}
```
<!--code_no_check-->

```js
// 在detail页面中
export default {
  onInit() {
    console.info('showData1:' + router.getParams()['data1']);
  }
}
```

### 基于TS扩展的声明式开发范式

> **说明：**
> 
> 直接使用router可能导致实例不明确的问题，建议使用[getUIContext](js-apis-arkui-UIContext.md#uicontext)获取UIContext实例，并使用[getRouter](js-apis-arkui-UIContext.md#getrouter)获取绑定实例的router。

```ts
// 通过router.pushUrl跳转至目标页携带params参数
import { router } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit'

// 定义传递参数的类
class innerParams {
  array:number[]

  constructor(tuple:number[]) {
    this.array = tuple
  }
}

class routerParams {
  text:string
  data:innerParams

  constructor(str:string, tuple:number[]) {
    this.text = str
    this.data = new innerParams(tuple)
  }
}

@Entry
@Component
struct Index {
  async routePage() {
    let options:router.RouterOptions = {
      url: 'pages/second',
      params: new routerParams('这是第一页的值' ,[12, 45, 78])
    }
    try {
      // 建议使用this.getUIContext().getRouter().pushUrl()
      await router.pushUrl(options)
    } catch (err) {
      console.info(` fail callback, code: ${(err as BusinessError).code}, msg: ${(err as BusinessError).message}`)
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
// 在second页面中接收传递过来的参数
import { router } from '@kit.ArkUI';

class innerParams {
  array:number[]

  constructor(tuple:number[]) {
    this.array = tuple
  }
}

class routerParams {
  text:string
  data:innerParams

  constructor(str:string, tuple:number[]) {
    this.text = str
    this.data = new innerParams(tuple)
  }
}

@Entry
@Component
struct Second {
  private content: string = "这是第二页"
  // 建议使用this.getUIContext().getRouter().getParams()
  @State text: string = (router.getParams() as routerParams).text
  @State data: object = (router.getParams() as routerParams).data
  @State secondData: string = ''

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text(`${this.content}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Text(this.text)
        .fontSize(30)
        .onClick(() => {
          this.secondData = (this.data['array'][1]).toString()
        })
        .margin({ top: 20 })
      Text(`第一页传来的数值:${this.secondData}`)
        .fontSize(20)
        .margin({ top: 20 })
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

```ts
class innerParams {
  data3:number[]

  constructor(tuple:number[]) {
    this.data3 = tuple
  }
}

class routerParams {
  data1:string
  data2:innerParams

  constructor(str:string, tuple:number[]) {
    this.data1 = str
    this.data2 = new innerParams(tuple)
  }
}

router.push({
  url: 'pages/routerpage2',
  params: new routerParams('message' ,[123,456,789])
});
```

## router.replace<sup>(deprecated)</sup>

replace(options: RouterOptions): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

从API version9开始不再维护，建议使用[replaceUrl<sup>9+</sup>](#routerreplaceurl9)

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名  | 类型                            | 必填 | 说明               |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | 是   | 替换页面描述信息。 |

**示例：**

```ts
class routerParams {
  data1:string

  constructor(str:string) {
    this.data1 = str
  }
}

router.replace({
  url: 'pages/detail',
  params: new routerParams('message')
});
```

## router.enableAlertBeforeBackPage<sup>(deprecated)</sup>

enableAlertBeforeBackPage(options: EnableAlertOptions): void

开启页面返回询问对话框。

从API version9开始不再维护，建议使用[showAlertBeforeBackPage<sup>9+</sup>](#routershowalertbeforebackpage9)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [EnableAlertOptions](#enablealertoptions) | 是    | 文本弹窗信息描述。 |

**示例：**

```ts
router.enableAlertBeforeBackPage({
  message: 'Message Info'
});
```

## router.disableAlertBeforeBackPage<sup>(deprecated)</sup>

disableAlertBeforeBackPage(): void

禁用页面返回询问对话框。

从API version9开始不再维护，建议使用[hideAlertBeforeBackPage<sup>9+</sup>](#routerhidealertbeforebackpage9)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
router.disableAlertBeforeBackPage();
```