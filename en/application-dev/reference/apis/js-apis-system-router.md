# Page Routing

The **Router** module provides APIs to access pages through URIs.

> **NOTE**
>
> - The APIs of this module are no longer maintained since API version 8. You are advised to use [`@ohos.router`](js-apis-router.md) instead.
>
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import router from '@system.router';
```

## router.push

push(options: RouterOptions): void

Navigates to a specified page in the application.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description                        |
| ------- | ------------------------------- | ---- | -------------------------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters. For details, see **RouterOptions**.|

**Example**

```js
// Current page
export default {
  pushPage() {
    router.push({
      uri: 'pages/routerpage2/routerpage2',
      params: {
        data1: 'message',
        data2: {
          data3: [123, 456, 789]
	},
      },
    });
  }
}
```


```js
// routerpage2 page
export default {
  data: {
    data1: 'default',
    data2: {
      data3: [1, 2, 3]
    }
  },
  onInit() {
    console.info('showData1:' + this.data1);
    console.info('showData3:' + this.data2.data3);
  }
}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The page routing stack supports a maximum of 32 pages.


## router.replace

replace(options: RouterOptions): void

Replaces the current page with another one in the application and destroys the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Parameters**

| Name    | Type                             | Mandatory  | Description                        |
| ------- | ------------------------------- | ---- | -------------------------- |
| options | [RouterOptions](#routeroptions) | Yes   | Page routing parameters. For details, see **RouterOptions**.|

**Example**

```js
// Current page
export default {
  replacePage() {
    router.replace({
      uri: 'pages/detail/detail',
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
  data: {
    data1: 'default'
  },
  onInit() {
    console.info('showData1:' + this.data1)
  }
}
```

## router.back

back(options?: BackRouterOptions): void

Returns to the previous page or a specified page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                     | Mandatory  | Description                     |
| ------- | --------------------------------------- | ---- | ----------------------- |
| options | [BackRouterOptions](#backrouteroptions) | Yes   | For details, see **BackRouterOptions**.|

**Example**

```js
// index page
export default {    
  indexPushPage() {        
    router.push({            
      uri: 'pages/detail/detail',        
    });        
  }
}
```


```js
// detail page
export default {    
  detailPushPage() {        
    router.push({            
      uri: 'pages/mall/mall',        
    });    
  }
}
```


```js
// Navigate from the mall page to the detail page through router.back().
export default {    
  mallBackPage() {        
    router.back();    
  }
}
```


```js
// Navigate from the detail page to the index page through router.back().
export default {    
  defaultBack() {        
    router.back();    
  }
}
```


```js
// Return to the detail page through router.back().
export default {    
  backToDetail() {        
    router.back({uri:'pages/detail/detail'});    
  }
}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> In the example, the **uri** field indicates the page route, which is specified by the **pages** list in the **config.json** file.

## router.getParams

getParams(): ParamsInterface

Obtains parameter information about the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                 | Description                   |
| ----------------------------------- | --------------------- |
| [ParamsInterface](#paramsinterface) | For details, see **ParamsInterface**.|

## router.clear

clear(): void

Clears all historical pages in the stack and retains only the current page at the top of the stack.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
export default {    
  clearPage() {        
    router.clear();    
  }
}
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
export default {     
  getLength() {        
    var size = router.getLength();        
    console.log('pages stack size = ' + size);    
  }
}
```

## router.getState

getState(): RouterState

Obtains state information about the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                       | Description               |
| --------------------------- | ----------------- |
| [RouterState](#routerstate) | For details, see **RouterState**.|

**Example**

```js
export default {     
  getState() {        
    var page = router.getState();
    console.log('current index = ' + page.index);
    console.log('current name = ' + page.name);
    console.log('current path = ' + page.path);
  }
}
```

## router.enableAlertBeforeBackPage<sup>6+</sup>

enableAlertBeforeBackPage(options: EnableAlertBeforeBackPageOptions): void

Enables the display of a confirm dialog box before returning to the previous page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description                                    |
| ------- | ---------------------------------------- | ---- | -------------------------------------- |
| options | [EnableAlertBeforeBackPageOptions](#enablealertbeforebackpageoptions6) | Yes   | For details, see **EnableAlertBeforeBackPageOptions**.|

**Example**

```js
export default {    
  enableAlertBeforeBackPage() {        
    router.enableAlertBeforeBackPage({            
      message: 'Message Info',            
      success: function() {                
        console.log('success');            
      },            
      cancel: function() {                
        console.log('cancel');            
      },        
    });    
  }
}
```

## router.disableAlertBeforeBackPage<sup>6+</sup>

disableAlertBeforeBackPage(options?: DisableAlertBeforeBackPageOptions): void

Disables the display of a confirm dialog box before returning to the previous page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description                                     |
| ------- | ---------------------------------------- | ---- | --------------------------------------- |
| options | [DisableAlertBeforeBackPageOptions](#disablealertbeforebackpageoptions6) | No   | For details, see **DisableAlertBeforeBackPageOptions**.|

**Example**

```js
export default {    
  disableAlertBeforeBackPage() {        
    router.disableAlertBeforeBackPage({            
      success: function() {                
        console.log('success');            
      },            
      cancel: function() {                
        console.log('cancel');            
      },        
    });    
  }
}
```

## RouterOptions

Defines the page routing parameters.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

| Name    | Type  | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| uri    | string | Yes   | URI of the target page, in either of the following formats:<br>1. Absolute path, which is provided by the **pages** list in the **config.json** file. Example:<br>- pages/index/index<br> - pages/detail/detail<br>2. Specific path. If the URI is a slash (/), the home page is displayed.|
| params | Object | No   | Data that needs to be passed to the target page during redirection. The target page can use **router.getParams()** to obtain the passed parameters, for example, **this.keyValue** (**keyValue** is the value of a key in **params**). In the web-like paradigm, these parameters can be directly used on the target page. If the field specified by **key** already exists on the target page, the passed value of the key will be displayed.|


## BackRouterOptions

Defines the parameters for routing back.

**System capability**: The items in the table below require different system capabilities. For details, see the table.

| Name    | Type  | Mandatory  | Description                                      |
| ------ | ------ | ---- | ---------------------------------------- |
| uri    | string | No   | URI of the page to return to. If the specified page does not exist in the page stack, the application does not respond. If this parameter is not set, the application returns to the previous page.<br>**System capability**: SystemCapability.ArkUI.ArkUI.Full|
| params | Object | No   | Data that needs to be passed to the target page during redirection.<br>**System capability**: SystemCapability.ArkUI.ArkUI.Lite|

## RouterState

Defines the page state.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type  | Mandatory  | Description                                |
| ----- | ------ | ---- | ---------------------------------- |
| index | number | Yes   | Index of the current page in the stack. The index starts from 1 from the bottom to the top of the stack.|
| name  | string | Yes   | Name of the current page, that is, the file name.                 |
| path  | string | Yes   | Path of the current page.                        |

## EnableAlertBeforeBackPageOptions<sup>6+</sup>

Defines the **EnableAlertBeforeBackPage** parameters.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                | Mandatory| Description                                              |
| -------- | ------------------------ | ---- | -------------------------------------------------- |
| message  | string                   | Yes  | Content displayed in the confirm dialog box.                                  |
| success  | (errMsg: string) => void | No  | Called when the **OK** button in the confirm dialog box is clicked. **errMsg** indicates the returned information.|
| cancel   | (errMsg: string) => void | No  | Called when the **Cancel** button in the confirm dialog box is clicked. **errMsg** indicates the returned information.|
| complete | () => void               | No  | Called when the dialog box is closed.                          |

## DisableAlertBeforeBackPageOptions<sup>6+</sup>

Defines the **DisableAlertBeforeBackPage** parameters.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                | Mandatory| Description                                              |
| -------- | ------------------------ | ---- | -------------------------------------------------- |
| success  | (errMsg: string) => void | No  | Called when the dialog box is closed. **errMsg** indicates the returned information.|
| cancel   | (errMsg: string) => void | No  | Called when the dialog box fails to be closed. **errMsg** indicates the returned information.|
| complete | () => void               | No  | Called when the dialog box is closed.                          |

## ParamsInterface

| Name           | Type  | Description     |
| ------------- | ------ | ------- |
| [key: string] | Object | List of routing parameters.|
