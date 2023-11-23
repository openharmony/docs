# @system.fetch    
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import fetch from '@system.fetch';  
    
```  
    
## FetchResponse    
通过网络获取数据。  
 **系统能力:**  SystemCapability.Communication.NetStack    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetStack    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| code | number | false | true | 表示服务器的状态code。 |  
| data | string \| object | false | true | 返回数据类型由responseType确定，详见表 responseType与success中data关系。 |  
| headers | Object | false | true | 表示服务器response的所有header。 |  
    
 **示例代码：**   
```ts    
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
  
    
## Fetch    
通过网络获取数据。  
 **系统能力:**  SystemCapability.Communication.NetStack    
### fetch  
 **调用形式：**     
- static fetch(options: {     /**      * Resource URL.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     url: string;        /**      * Request parameter, which can be of the string type or a JSON object.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     data?: string | object;        /**      * Request header, which accommodates all attributes of the request.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     header?: Object;        /**      * Request methods available: OPTIONS, GET, HEAD, POST, PUT, DELETE and TRACE. The default value is GET.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     method?: string;        /**      * The return type can be text, or JSON. By default, the return type is determined based on Content-Type in the header returned by the server.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     responseType?: string;        /**      * Called when the network data is obtained successfully.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     success?: (data: FetchResponse) => void;        /**      * Called when the network data fails to be obtained.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     fail?: (data: any, code: number) => void;        /**      * Called when the execution is completed.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     complete?: () => void;   }): void  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | {     /**      * Resource URL.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     url: string;        /**      * Request parameter, which can be of the string type or a JSON object.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     data?: string \| object;        /**      * Request header, which accommodates all attributes of the request.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     header?: Object;        /**      * Request methods available: OPTIONS, GET, HEAD, POST, PUT, DELETE and TRACE. The default value is GET.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     method?: string;        /**      * The return type can be text, or JSON. By default, the return type is determined based on Content-Type in the header returned by the server.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     responseType?: string;        /**      * Called when the network data is obtained successfully.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     success?: (data: FetchResponse) => void;        /**      * Called when the network data fails to be obtained.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     fail?: (data: any, code: number) => void;        /**      * Called when the execution is completed.      * @syscap SystemCapability.Communication.NetStack      * @since 3      */     complete?: () => void;   } | true |  |  
