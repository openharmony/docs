# @ohos.router (Page Routing) (Not Recommended)

The **Router** module provides APIs to access pages through URLs. You can use the APIs to navigate to a specified page in an application, replace the current page with another one in the same application, and return to the previous page or a specified page.

For routing management, it is recommended that you use the [Navigation](../../ui/arkts-navigation-navigation.md) component instead as your application routing framework.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - Page routing APIs can be invoked only after page rendering is complete. Do not call these APIs in **onInit** and **onReady** when the page is still in the rendering phase.
>
> - The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](./js-apis-arkui-UIContext.md#uicontext).
>
> - Since API version 10, you can use the [getRouter](./js-apis-arkui-UIContext.md#getrouter) API in [UIContext](./js-apis-arkui-UIContext.md#uicontext) to obtain the [Router](./js-apis-arkui-UIContext.md#router) object associated with the current UI context.
>
> - When the **pushUrl** or **pushNamedRoute** API uses a callback to return the result, the information obtained from the callback using APIs such as **getLength** may represent an intermediate state of the stack and might not be consistent with the final state.

## Modules to Import

```
import { router } from '@kit.ArkUI';
```

## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions): Promise&lt;void&gt;

Navigates to a specified page in the application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters.|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100002    | Uri error. The URI of the page to redirect is incorrect or does not exist. |
| 100003    | Page stack error. Too many pages are pushed. |

**Example**

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

Navigates to a specified page in the application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100002    | Uri error. The URI of the page to redirect is incorrect or does not exist. |
| 100003    | Page stack error. Too many pages are pushed. |

**Example**

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

Navigates to a specified page in the application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100002    | Uri error. The URI of the page to redirect is incorrect or does not exist. |
| 100003    | Page stack error. Too many pages are pushed. |

**Example**

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

Navigates to a specified page in the application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100002    | Uri error. The URI of the page to redirect is incorrect or does not exist. |
| 100003    | Page stack error. Too many pages are pushed. |

**Example**

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

Replaces the current page with another one in the application and destroys the current page. This API cannot be used to configure page transition effects. To configure page transition effects, use the [Navigation](../../ui/arkts-navigation-navigation.md) component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Parameters**

| Name | Type                           | Mandatory| Description              |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | Yes  | Description of the new page.|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 200002    | Uri error. The URI of the page to be used for replacement is incorrect or does not exist. |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Parameters**

| Name | Type                           | Mandatory| Description              |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | Yes  | Description of the new page.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 200002    | Uri error. The URI of the page to be used for replacement is incorrect or does not exist. |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | Yes   | Description of the new page. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|


**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Failed to get the delegate. This error code is thrown only in the standard system. |
| 200002    | Uri error. The URI of the page to be used for replacement is incorrect or does not exist. |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | Yes   | Description of the new page. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 200002    | Uri error. The URI of the page to be used for replacement is incorrect or does not exist. |

**Example**

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

Navigates to a page using the named route. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | Yes   | Page routing parameters.|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100003    | Page stack error. Too many pages are pushed. |
| 100004    | Named route error. The named route does not exist. |

**Example**

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

For details, see [UI Development-Named Route](../../ui/arkts-routing.md#named-route).

## router.pushNamedRoute<sup>10+</sup>

pushNamedRoute(options: NamedRouterOptions, callback: AsyncCallback&lt;void&gt;): void

Navigates to a page using the named route. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | Yes   | Page routing parameters.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100003    | Page stack error. Too many pages are pushed. |
| 100004    | Named route error. The named route does not exist. |

**Example**

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

Navigates to a page using the named route. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | Yes   | Page routing parameters. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100003    | Page stack error. Too many pages are pushed. |
| 100004    | Named route error. The named route does not exist. |

**Example**

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

Navigates to a page using the named route. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | Yes   | Page routing parameters. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |
| 100003    | Page stack error. Too many pages are pushed. |
| 100004    | Named route error. The named route does not exist. |

**Example**

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

Replaces the current page with another one using the named route and destroys the current page. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                           | Mandatory| Description              |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [NamedRouterOptions](#namedrouteroptions10) | Yes  | Description of the new page.|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 100004    | Named route error. The named route does not exist. |

**Example**

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

Replaces the current page with another one using the named route and destroys the current page. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                           | Mandatory| Description              |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [NamedRouterOptions](#namedrouteroptions10) | Yes  | Description of the new page.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 100004    | Named route error. The named route does not exist. |

**Example**

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

Replaces the current page with another one using the named route and destroys the current page. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | Yes   | Description of the new page. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|


**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Failed to get the delegate. This error code is thrown only in the standard system. |
| 100004    | Named route error. The named route does not exist. |

**Example**

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

Replaces the current page with another one using the named route and destroys the current page. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [NamedRouterOptions](#namedrouteroptions10) | Yes   | Description of the new page. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | The UI execution context is not found. This error code is thrown only in the standard system. |
| 100004    | Named route error. The named route does not exist. |

**Example**

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

Returns to the previous page or a specified page, which deletes all pages between the current page and the target page.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                           | Mandatory| Description                                                        |
| ------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| options | [RouterOptions](#routeroptions) | No  | Description of the page. The **url** parameter indicates the URL of the page to return to. If the specified page does not exist in the page stack, the application does not respond. If no URL is set, the application returns to the previous page, and the page is not rebuilt. The page in the page stack is not reclaimed. It will be reclaimed after being popped up. The **back** API does not work if **url** is set to a slash (/).|

**Example**

```ts
router.back({url:'pages/detail'});    
```

## router.back<sup>12+</sup>

back(index: number, params?: Object): void;

Returns to the specified page, which deletes all pages between the current page and the target page.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| index | number | Yes   | Index of the target page to navigate to. |
| params    | Object      | No   | Parameters carried when returning to the page.|

**Example**

```ts
router.back(1);    
```
```ts
router.back(1, {info: 'From Home'}); // Returning with parameters.
```

## router.clear

clear(): void

Clears all historical pages in the stack and retains only the current page at the top of the stack.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
router.clear();    
```

## router.getLength

getLength(): string

Obtains the number of pages in the current stack.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | Number of pages in the stack. The maximum value is **32**.|

**Example**

```ts
let size = router.getLength();        
console.log('pages stack size = ' + size);    
```

## router.getState

getState(): RouterState

Obtains state information about the page at the top of the navigation stack.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                         | Description     |
| --------------------------- | ------- |
| [RouterState](#routerstate) | Page routing state.|

**Example**

```ts
let page = router.getState();
console.log('current index = ' + page.index);
console.log('current name = ' + page.name);
console.log('current path = ' + page.path);
```

## router.getStateByIndex<sup>12+</sup>

getStateByIndex(index: number): RouterState | undefined

Obtains the status information about a page by its index.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| index    | number | Yes  | Index of the target page. |

**Return value**

| Type                         | Description     |
| --------------------------- | ------- |
| [RouterState](#routerstate) \| undefined | State information about the target page; **undefined** if the specified index does not exist.|

**Example**

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

Obtains the status information about a page by its URL.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| url    | string | Yes  | URL of the target page. |

**Return value**

| Type                         | Description     |
| --------------------------- | ------- |
| Array<[RouterState](#routerstate)> | Page routing state.|

**Example**

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

Describes the page routing state.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type  | Mandatory| Description                                                        |
| ----- | ------ | ---- | ------------------------------------------------------------ |
| index | number | Yes  | Index of the current page in the stack. The index starts from 1 from the bottom to the top of the stack.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| name  | string | Yes | Name of the current page, that is, the file name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| path  | string | Yes  | Path of the current page.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| params<sup>12+</sup>  | Object |  Yes | Parameters carried on the current page.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                        |

## router.showAlertBeforeBackPage<sup>9+</sup>

showAlertBeforeBackPage(options: EnableAlertOptions): void

Enables the display of a confirm dialog box before returning to the previous page.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description       |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [EnableAlertOptions](#enablealertoptions) | Yes   | Description of the dialog box.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Router Error Codes](errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |

**Example**

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

Describes the confirm dialog box.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type    | Mandatory  | Description      |
| ------- | ------ | ---- | -------- |
| message | string | Yes   | Content displayed in the confirm dialog box.|

## router.hideAlertBeforeBackPage<sup>9+</sup>

hideAlertBeforeBackPage(): void

Disables the display of a confirm dialog box before returning to the previous page.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
router.hideAlertBeforeBackPage();    
```

##  router.getParams

getParams(): Object

Obtains the parameters passed from the page that initiates redirection to the current page.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type  | Description                              |
| ------ | ---------------------------------- |
| object | Parameters passed from the page that initiates redirection to the current page.|

**Example**

```ts
router.getParams();
```

## RouterOptions

Describes the page routing options.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| url    | string | Yes  | URL of the target page, in either of the following formats:<br>- Absolute path of the page. The value is available in the pages list in the **config.json** file, for example:<br>- pages/index/index<br>- pages/detail/detail<br>- special value. If the value of url is **"/"**, the application navigates to the home page. By default, the home page is set to the first item in the **src** value array.|
| params | Object | No  | Data that needs to be passed to the target page during redirection. The received data becomes invalid when the page is switched to another page. The target page can use **router.getParams()** to obtain the passed parameters, for example, **this.keyValue** (**keyValue** is the value of a key in **params**). In the web-like paradigm, these parameters can be directly used on the target page. If the field specified by **key** already exists on the target page, the passed value of the key will be displayed.<br>**NOTE**<br>The **params** parameter cannot pass objects returned by methods and system APIs, for example, **PixelMap** objects defined and returned by media APIs. To pass such objects, extract from them the basic type attributes to be passed, and then construct objects of the object type.|


  > **NOTE**
  > The page routing stack supports a maximum of 32 pages.

## RouterMode<sup>9+</sup>

Enumerates the routing modes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Description                                                        |
| -------- | ------------------------------------------------------------ |
| Standard | Multi-instance mode. It is the default routing mode.<br>The target page is added to the top of the page stack, regardless of whether a page with the same URL exists in the stack.<br>**NOTE**<br>If no routing mode is used, the navigation will be carried out according to the default multi-instance mode.|
| Single   | Singleton mode.<br>If the URL of the target page already exists in the page stack, the page is moved to the top of the stack.<br>If the URL of the target page does not exist in the page stack, the page is redirected to in multi-instance mode.|

## NamedRouterOptions<sup>10+</sup>

Describes the named route options.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | Yes  | Name of the target named route.                                |
| params | Object | No  | Data that needs to be passed to the target page during redirection. The target page can use **router.getParams()** to obtain the passed parameters, for example, **this.keyValue** (**keyValue** is the value of a key in **params**). In the web-like paradigm, these parameters can be directly used on the target page. If the field specified by **key** already exists on the target page, the passed value of the key will be displayed.|

## Examples

### JavaScript-based Web-like Development Paradigm

The following sample code applies only to JavaScript files, not ArkTS files.

<!--code_no_check-->

```js
// Current page
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
// detail page
export default {
  onInit() {
    console.info('showData1:' + router.getParams()['data1']);
  }
}
```

### TypeScript-based Declarative Development Paradigm

> **NOTE**
> 
> To avoid confusion with **router** instances, it is recommended that you obtain a **UIContext** instance using the [getUIContext](js-apis-arkui-UIContext.md#uicontext) API, and then obtain the **router** instance bound to the context through the [getRouter](js-apis-arkui-UIContext.md#getrouter) API.

```ts
// Navigate to the target page through router.pushUrl with the params parameter carried.
import { router } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit'

// Define the class for passing parameters.
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
      params: new routerParams ('This is the value on the first page', [12, 45, 78])
    }
    try {
      // You are advised to use this.getUIContext().getRouter().pushUrl().
      await router.pushUrl(options)
    } catch (err) {
      console.info(` fail callback, code: ${(err as BusinessError).code}, msg: ${(err as BusinessError).message}`)
    }
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text('This is the first page.')
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
// Receive the transferred parameters on the second page.
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
  private content: string = "This is the second page."
  // You are advised to use this.getUIContext().getRouter().getParams().
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
      Text(`This is the data passed from the first page: ${this.secondData}`)
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

Navigates to a specified page in the application.

This API is deprecated since API version 9. You are advised to use [pushUrl<sup>9+</sup>](#routerpushurl9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters.|


**Example**

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

Replaces the current page with another one in the application and destroys the current page.

This API is deprecated since API version 9. You are advised to use [replaceUrl<sup>9+</sup>](#routerreplaceurl9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Parameters**

| Name | Type                           | Mandatory| Description              |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | Yes  | Description of the new page.|

**Example**

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

Enables the display of a confirm dialog box before returning to the previous page.

This API is deprecated since API version 9. You are advised to use [showAlertBeforeBackPage<sup>9+</sup>](#routershowalertbeforebackpage9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description       |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [EnableAlertOptions](#enablealertoptions) | Yes   | Description of the dialog box.|

**Example**

```ts
router.enableAlertBeforeBackPage({
  message: 'Message Info'
});
```

## router.disableAlertBeforeBackPage<sup>(deprecated)</sup>

disableAlertBeforeBackPage(): void

Disables the display of a confirm dialog box before returning to the previous page.

This API is deprecated since API version 9. You are advised to use [hideAlertBeforeBackPage<sup>9+</sup>](#routerhidealertbeforebackpage9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
router.disableAlertBeforeBackPage();
```
