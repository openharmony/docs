# @system.router (Page Routing)

The **Router** module provides APIs to access pages through URIs.

> **NOTE**
>
> - The APIs of this module are no longer maintained since API version 8. You are advised to use [@ohos.router](js-apis-router.md) instead.
>
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```ts
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

```ts
// Current page
import router from '@system.router';
class A{
  pushPage() {
    router.push({
      uri: 'pages/routerpage2/routerpage2',
      params: {
        data1: 'message',
        data2: {
          data3: [123, 456, 789]
        }
      }
    });
  }
}
export default new A()
```


```ts
// routerpage2 page
class B{
  data:Record<string,string> = {'data1': 'default'}
  data2:Record<string,number[]> = {'data3': [1, 2, 3]}
  onInit() {
    console.info('showData1:' + this.data.data1);
    console.info('showData3:' + this.data2.data3);
  }
}
export default new B()
```

> **NOTE**
>
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

```ts
// Current page
import router from '@system.router';
class C{
  replacePage() {
    router.replace({
      uri: 'pages/detail/detail',
      params: {
        data1: 'message'
      }
    });
  }
}
export default new C()
```


```ts
// detail page
class Area {
  data:Record<string,string> = {'data1': 'default'}
  onInit() {
    console.info('showData1:' + this.data)
  }
}
export default new Area()
```

## router.back

back(options?: BackRouterOptions): void

Returns to the previous page or a specified page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                     | Mandatory  | Description                     |
| ------- | --------------------------------------- | ---- | ----------------------- |
| options | [BackRouterOptions](#backrouteroptions) | No   | For details, see **BackRouterOptions**.|

**Example**

```ts
// index page
import router from '@system.router';
class D{
  indexPushPage() {
    router.push({
      uri: 'pages/detail/detail'
    });
  }
}
export default new D()
```


```ts
// detail page
import router from '@system.router';
class E{
  detailPushPage() {
    router.push({
      uri: 'pages/mall/mall'
    });
  }
}
export default new E()
```


```ts
// Navigate from the mall page to the detail page through router.back().
import router from '@system.router';
class F{
  mallBackPage() {
    router.back();
  }
}
export default new F()
```


```ts
// Navigate from the detail page to the index page through router.back().
import router from '@system.router';
class G{
  defaultBack() {
    router.back();
  }
}
export default new G()
```


```ts
// Return to the detail page through router.back().
import router from '@system.router';
class H{
  backToDetail() {
    router.back({uri:'pages/detail/detail'});
  }
}
export default new H()
```

> **NOTE**
>
> In the example, the **uri** field indicates the page route, which is specified by the **pages** list in the **config.json** file.

## router.getParams<sup>7+</sup>

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

```ts
import router from '@system.router';
class I{
  clearPage() {
    router.clear();
  }
}
export default new I()
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

```ts
import router from '@system.router';
class J{
  getLength() {
    let size = router.getLength();
    console.log('pages stack size = ' + size);
  }
}
export default new J()
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

```ts
import router from '@system.router';
class K{
  getState() {
    let page = router.getState();
    console.log('current index = ' + page.index);
    console.log('current name = ' + page.name);
    console.log('current path = ' + page.path);
  }
}
export default new K()
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

```ts
import router from '@system.router';
class L{
  enableAlertBeforeBackPage() {
    router.enableAlertBeforeBackPage({
      message: 'Message Info',
      success: ()=> {
        console.log('success');
      },
      cancel: ()=> {
        console.log('cancel');
      }
    });
  }
}
export default new L()
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

```ts
import router from '@system.router';
class Z{
  disableAlertBeforeBackPage() {
    router.disableAlertBeforeBackPage({
      success: ()=> {
        console.log('success');
      },
      cancel: ()=> {
        console.log('cancel');
      }
    });
  }
}
export default new Z()
```

## RouterOptions

Defines the page routing parameters.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

| Name  | Type| Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| uri | string   | Yes  | URI of the target page, in either of the following formats:<br>1. Absolute path, which is provided by the **pages** list in the **config.json** file. Example:<br>- pages/index/index<br> - pages/detail/detail<br>2. Specific path. If the URI is a slash (/), the home page is displayed.|
| params | object   | No  | Data that needs to be passed to the target page during redirection. The target page can use **router.getParams()** to obtain the passed parameters, for example, **this.keyValue** (**keyValue** is the value of a key in **params**). In the web-like paradigm, these parameters can be directly used on the target page. If the field specified by **key** already exists on the target page, the passed value of the key will be displayed.|


## BackRouterOptions

Defines the parameters for routing back.

**System capability**: The items in the table below require different system capabilities. For details, see the table.

| Name  | Type| Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| uri<sup>7+</sup> | string   | No  | URI of the page to return to. If the specified page does not exist in the page stack, the application does not respond. If this parameter is not set, the application returns to the previous page.<br>**System capability**: SystemCapability.ArkUI.ArkUI.Full|
| params<sup>7+</sup> | object   | No  | Data that needs to be passed to the target page during redirection.<br>**System capability**: SystemCapability.ArkUI.ArkUI.Lite|

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

| Name         | Type| Description          |
| ------------- | -------- | -------------- |
| [key: string] | object   | List of routing parameters.|
