# web

>**NOTE**
>
>This component is supported since API version 6. Updates will be marked with a superscript to indicate their earliest API version.

The **\<web>** component displays web page content.

## Required Permissions
ohos.permission.INTERNET, required only for accessing online web pages.

## Constraints
The **\<web>** component does not follow the transition animation. A page allows only one **\<web>** component.

## Child Components
Not supported

## Attributes

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| src      | string |   -    |   No    |Address of the web page to be displayed. The domain name of the website must compile with the HTTPS protocol and have received an ICP license.|
| id  | string | -  | No |  Unique ID of the component. |


## Styles
Universal style settings are not supported.

## Events
The following events are supported.

| Name| Parameter| Description|
| -------- |  -------- | -------- |
| pagestart      | {url: string} | Triggered when web page loading starts.|
| pagefinish  | {url: string} |  Triggered when web page loading is completed. |
| error  | {url: string, errorCode: number, description: string} |  Triggered when an error occurs during web page loading or opening. |

## Methods
The following methods are supported.

| Name| Parameter| Description|
| -------- |  -------- | -------- |
| reload      | - | Reloads a page.|

## Example
```html
<!-- xxx.hml -->
<div style="height: 500px; width: 500px; flex-direction: column;">
    <button onclick="reloadWeb">click to reload</button>
    <web src="www.example.com" id="web" onpagestart="pageStart" onpagefinish="pageFinish" on:error="pageError"></web>
</div>
```

```js
// xxx.js
export default {
    reloadWeb() {
        this.$element('web').reload()
    },

    pageStart: function(e) {
        console.info('web pageStart: ' + e.url)
    },

    pageFinish: function(e) {
        console.info('web pageFinish: ' + e.url)
    },

    pageError: function(e) {
        console.info('web pageError url: ' + e.url)
        console.info('web pageError errorCode: ' + e.errorCode)
        console.info('web pageError description: ' + e.description)
    }
}
```
