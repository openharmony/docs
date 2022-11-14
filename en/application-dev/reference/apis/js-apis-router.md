# Page Routing

The **Router** module provides APIs to access pages through URLs. You can use the APIs to navigate to a specified page in an application, replace the current page with another one in an application, and return to the previous page or a specified page.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - Page routing APIs can be invoked only after page rendering is complete. Do not call these APIs in **onInit** and **onReady** when the page is still in the rendering phase.

## Modules to Import

```
import router from '@ohos.router'
```

## router.pushUrl<sup>9+</sup>

pushUrl(options: RouterOptions): Promise&lt;void&gt;

Navigates to a specified page in the application.

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

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | Internal error. |
| 100002    | Uri error. The uri of router is not exist. |
| 100003    | Page stack error. The pages are pushed too much. |

**Example**

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

Navigates to a specified page in the application.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | Internal error. |
| 100002    | Uri error. The uri of router is not exist. |
| 100003    | Page stack error. The pages are pushed too much. |

**Example**

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

Navigates to a specified page in the application.

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

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | Internal error. |
| 100002    | Uri error. The uri of router is not exist. |
| 100003    | Page stack error. The pages are pushed too much. |

**Example**

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

Navigates to a specified page in the application.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | Internal error. |
| 100002    | Uri error. The uri of router is not exist. |
| 100003    | Page stack error. The pages are pushed too much. |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

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

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | Internal error. |
| 200002    | Uri error. The uri of router is not exist. |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Parameters**

| Name | Type                           | Mandatory| Description              |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | Yes  | Description of the new page.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | Internal error. |
| 200002    | Uri error. The uri of router is not exist. |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

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

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | Internal error. |
| 200002    | Uri error. The uri of router is not exist. |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | Yes   | Description of the new page. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | Internal error. |
| 200002    | Uri error. The uri of router is not exist. |

**Example**

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

Returns to the previous page or a specified page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                           | Mandatory| Description                                                        |
| ------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| options | [RouterOptions](#routeroptions) | No  | Description of the page. The **url** parameter indicates the URL of the page to return to. If the specified page does not exist in the page stack, the application does not respond. If no URL is set, the previous page is returned, and the page in the page stack is not reclaimed. It will be reclaimed after being popped up.|

**Example**

```js
router.back({url:'pages/detail'});    
```

## router.clear

clear(): void

Clears all historical pages in the stack and retains only the current page at the top of the stack.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
router.clear();    
```

## router.getLength

getLength(): string

Obtains the number of pages in the current stack.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | Number of pages in the stack. The maximum value is **32**.|

**Example**

```js
var size = router.getLength();        
console.log('pages stack size = ' + size);    
```

## router.getState

getState(): RouterState

Obtains state information about the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                         | Description     |
| --------------------------- | ------- |
| [RouterState](#routerstate) | Page routing state.|

**Example**

```js
var page = router.getState();
console.log('current index = ' + page.index);
console.log('current name = ' + page.name);
console.log('current path = ' + page.path);
```

## RouterState

Describes the page routing state.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type    | Description                                |
| ----- | ------ | ---------------------------------- |
| index | number | Index of the current page in the stack. The index starts from 1 from the bottom to the top of the stack.|
| name  | string | Name of the current page, that is, the file name.                 |
| path  | string | Path of the current page.                        |

## router.enableBackPageAlert<sup>9+</sup>

enableBackPageAlert(options: EnableAlertOptions): void

Enables the display of a confirm dialog box before returning to the previous page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description       |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [EnableAlertOptions](#enablealertoptions) | Yes   | Description of the dialog box.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | Internal error. |

**Example**

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

Describes the confirm dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type    | Mandatory  | Description      |
| ------- | ------ | ---- | -------- |
| message | string | Yes   | Content displayed in the confirm dialog box.|

## router.disableAlertBeforeBackPage

disableAlertBeforeBackPage(): void

Disables the display of a confirm dialog box before returning to the previous page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
router.disableAlertBeforeBackPage();    
```

##  router.getParams

getParams(): Object

Obtains the parameters passed from the page that initiates redirection to the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description               |
| ------ | ----------------- |
| Object | Parameters passed from the page that initiates redirection to the current page.|

**Example**

```
router.getParams();
```

## RouterOptions

Describes the page routing options.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| url    | string | Yes  | URL of the target page, in either of the following formats:<br>- Absolute path of the page. The value is available in the pages list in the **config.json** file, for example:<br>- pages/index/index<br>- pages/detail/detail<br>- Particular path. If the URL is a slash (/), the home page is displayed.|
| params | Object | No  | Data that needs to be passed to the target page during redirection. The target page can use **router.getParams()** to obtain the passed parameters, for example, **this.keyValue** (**keyValue** is a key in **params**). In the web-like paradigm, these parameters can be directly used on the target page. If the field specified by **key** already exists on the target page, the passed value of the key will be displayed.|


  > **NOTE**
  > The page routing stack supports a maximum of 32 pages.

## RouterMode<sup>9+</sup>

Enumerates the routing modes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Description                                      |
| -------- | ---------------------------------------- |
| Standard | Standard mode.<br>The target page is added to the top of the page stack, regardless of whether a page with the same URL exists in the stack.                           |
| Single   | Singleton mode.<br>If the URL of the target page already exists in the page stack, the page closest to the top of the stack is moved as a new page to the top of the stack.<br>If the URL of the target page does not exist in the page stack, the page is redirected to in standard mode.|

## Examples

### JavaScript-based Web-like Development Paradigm

```js
// Current page
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
// detail page
export default {
  onInit() {
    console.info('showData1:' + router.getParams()[data1]);
  }
}
```

### TypeScript-based Declarative Development Paradigm

```ts
// Navigate to the target page through router.push with the params parameter carried.
import router from '@ohos.router'

@Entry
@Component
struct Index {
  async  routePage() {
    let options = {
      url: 'pages/second',
      params: {
        text: 'This is the value on the first page.',
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
import router from '@ohos.router'

@Entry
@Component
struct Second {
  private content: string = "This is the second page."
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
      Text('Value from the first page '+'' + this.secondData)
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

Navigates to a specified page in the application.

This API is deprecated since API version 9. You are advised to use [pushUrl<sup>9+</sup>](#routerpushurl9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters.|


**Example**

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

Navigates to a specified page in the application.

This API is deprecated since API version 9. You are advised to use [pushUrl<sup>9+</sup>](#routerpushurl9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|


**Example**

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

Replaces the current page with another one in the application and destroys the current page.

This API is deprecated since API version 9. You are advised to use [replaceUrl<sup>9+</sup>](#routerreplaceurl9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                           | Mandatory| Description              |
| ------- | ------------------------------- | ---- | ------------------ |
| options | [RouterOptions](#routeroptions) | Yes  | Description of the new page.|

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

This API is deprecated since API version 9. You are advised to use [replaceUrl<sup>9+</sup>](#routerreplaceurl9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description        |
| ------- | ------------------------------- | ---- | ---------- |
| options | [RouterOptions](#routeroptions) | Yes   | Description of the new page. |
| mode    | [RouterMode](#routermode9)      | Yes   | Routing mode.|

**Example**

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

Enables the display of a confirm dialog box before returning to the previous page.

This API is deprecated since API version 9. You are advised to use [enableBackPageAlert<sup>9+</sup>](#routerenablebackpagealert9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description       |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [EnableAlertOptions](#enablealertoptions) | Yes   | Description of the dialog box.|

**Example**

  ```js        
  router.enableAlertBeforeBackPage({            
    message: 'Message Info'        
  });    
  ```
