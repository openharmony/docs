# Data Request

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> - The APIs of this module are no longer maintained since API version 6. It is recommended that you use [`@ohos.net.http`](js-apis-http.md) instead.
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import fetch from '@system.fetch';
```


## fetch.fetch

fetch(Object): void

Obtains data through a network.

**Required permissions:** ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| url | string | Yes | Resource&nbsp;URL. |
| data | string \| Object | No | Request&nbsp;parameter,&nbsp;which&nbsp;can&nbsp;be&nbsp;a&nbsp;string&nbsp;or&nbsp;a&nbsp;JSON&nbsp;object. For details, see Relationship between data and Content-Type. |
| header | Object | No | Request&nbsp;header. |
| method | string | No | Request&nbsp;method.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**GET**.&nbsp;The&nbsp;value&nbsp;can&nbsp;be&nbsp;**OPTIONS**,&nbsp;**GET**,&nbsp;**HEAD**,&nbsp;**POST**,&nbsp;**PUT**,&nbsp;**DELETE&nbsp;**or&nbsp;**TRACE**. |
| responseType | string | No | Response&nbsp;type.&nbsp;The&nbsp;return&nbsp;type&nbsp;can&nbsp;be&nbsp;text&nbsp;or&nbsp;JSON.&nbsp;By&nbsp;default,&nbsp;the&nbsp;return&nbsp;type&nbsp;is&nbsp;determined&nbsp;based&nbsp;on&nbsp;**Content-Type**&nbsp;in&nbsp;the&nbsp;header&nbsp;returned&nbsp;by&nbsp;the&nbsp;server.&nbsp;For&nbsp;details,&nbsp;see return values of the success callback. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;network&nbsp;data&nbsp;is&nbsp;obtained&nbsp;successfully. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;network&nbsp;data&nbsp;fails&nbsp;to&nbsp;be&nbsp;obtained. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

  **Table1** Relationship between data and Content-Type

| data | Content-Type | Description |
| -------- | -------- | -------- |
| string | Not&nbsp;set | The&nbsp;default&nbsp;value&nbsp;of&nbsp;Content-Type&nbsp;is&nbsp;text/plain,&nbsp;and&nbsp;the&nbsp;value&nbsp;of&nbsp;data&nbsp;is&nbsp;used&nbsp;as&nbsp;the&nbsp;request&nbsp;body. |
| string | Any&nbsp;type | The&nbsp;value&nbsp;of&nbsp;data&nbsp;is&nbsp;used&nbsp;as&nbsp;the&nbsp;request&nbsp;body. |
| Object | Not&nbsp;set | The&nbsp;default&nbsp;value&nbsp;of&nbsp;**Content-Type**&nbsp;is&nbsp;**application/x-www-form-urlencoded**.&nbsp;The&nbsp;**data**&nbsp;value&nbsp;is&nbsp;encoded&nbsp;based&nbsp;on&nbsp;the&nbsp;URL&nbsp;rule&nbsp;and&nbsp;appended&nbsp;in&nbsp;the&nbsp;request&nbsp;body. |
| Object | application/x-www-form-urlencoded | The&nbsp;value&nbsp;of&nbsp;data&nbsp;is&nbsp;encoded&nbsp;based&nbsp;on&nbsp;the&nbsp;URL&nbsp;rule&nbsp;and&nbsp;is&nbsp;used&nbsp;as&nbsp;the&nbsp;request&nbsp;body. |

The following values will be returned when data is successfully obtained.

| Parameter | Type | Description |
| -------- | -------- | -------- |
| code | number | Server&nbsp;status&nbsp;code. |
| data | string \| Object | The&nbsp;type&nbsp;of&nbsp;the&nbsp;returned&nbsp;data&nbsp;is&nbsp;determined&nbsp;by&nbsp;**responseType**.&nbsp;For&nbsp;details,&nbsp;see&nbsp;Relationship between responseType and data returned by the success function. |
| headers | Object | All&nbsp;headers&nbsp;in&nbsp;the&nbsp;response&nbsp;from&nbsp;the&nbsp;server. |

  **Table2** Relationship between responseType and data returned by the success function

| responseType | data | Description |
| -------- | -------- | -------- |
| N/A | string | When&nbsp;the&nbsp;type&nbsp;in&nbsp;the&nbsp;header&nbsp;returned&nbsp;by&nbsp;the&nbsp;server&nbsp;is&nbsp;**text/\***,&nbsp;**application/json**,&nbsp;**application/javascript**,&nbsp;or&nbsp;**application/xml**,&nbsp;the&nbsp;value&nbsp;is&nbsp;the&nbsp;text&nbsp;content. |
| text | string | Text&nbsp;content. |
| json | Object | A&nbsp;JSON&nbsp;object. |

**Example**

```
export default {
  data: {
    responseData: 'NA',
    url: "test_url",
  },
  fetch: function () {
    var that = this;
    fetch.fetch({
      url: that.url,
      success: function(response) {
        console.info("fetch success");
        that.responseData = JSON.stringify(response);
      },
      fail: function() {
        console.info("fetch fail");
      }
    });
  }
}
```


> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
>   HTTPS is supported by default. To support HTTP, you need to add **"network"** to the **config.json** file, and set the attribute **"cleartextTraffic"** to **true**. 
>   
> ```
> {
>   "deviceConfig": {
>     "default": {
>       "network": {
>         "cleartextTraffic": true
>       }
>       ...
>     }
>   }
>   ...
> }
> ```