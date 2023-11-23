# @ohos.contact    
本模块提供联系人管理能力，包括添加联系人、删除联系人、更新联系人等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import contact from '@ohos.contact'    
```  
    
## addContact<sup>(deprecated)</sup>    
添加联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- addContact(contact: Contact, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.addContact#addContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| contact<sup>(deprecated)</sup> | Contact | true | 联系人信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回添加的联系人id。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.addContact(  
    context,  
    {name: {fullName: 'xxx'},  
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]  
    }, (err: BusinessError, data) => {  
      if (err) {  
        console.log(`addContact callback: err->${JSON.stringify(err)}`);  
        return;  
      }  
      console.log(`addContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## addContact<sup>(10+)</sup>    
添加联系人  
 **调用形式：**     
    
- addContact(context: Context, contact: Contact, callback: AsyncCallback\<number>): void    
起始版本： 10    
- addContact(context: Context, contact: Contact): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |  
| contact | Contact | true | 联系人信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回添加的联系人id。 |  
| Promise<number> | 返回结果，返回添加的联系人id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.addContact({  
      name: {fullName: 'xxx'},  
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`addContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`addContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.addContact(  
    context,  
    {name: {fullName: 'xxx'},  
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]  
  });  
  promise.then((data) => {  
    console.log(`addContact success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
    console.error(`addContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## addContact<sup>(deprecated)</sup>    
添加联系人，使用Promise方式作为异步方法。  
 **调用形式：**     
- addContact(contact: Contact): Promise\<number>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.addContact#addContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| contact<sup>(deprecated)</sup> | Contact | true | 联系人信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 返回结果，返回添加的联系人id。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  let promise = contact.addContact({  
      name: {fullName: 'xxx'},  
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]  
  });  
  promise.then((data) => {  
      console.log(`addContact success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`addContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## selectContact<sup>(deprecated)</sup>    
调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用callback方式作为异步方法。  
 **调用形式：**     
- selectContact(callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.selectContact#selectContacts。  
 **系统能力:**  SystemCapability.Applications.Contacts  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回选择的联系人对象数组。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.selectContact((err: BusinessError, data) => {  
      if (err) {  
          console.log(`selectContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`selectContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## selectContacts<sup>(10+)</sup>    
调用选择联系人接口，打开选择联系人UI界面  
 **调用形式：**     
    
- selectContacts(callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- selectContacts(): Promise\<Array\<Contact>>    
起始版本： 10    
- selectContacts(options: ContactSelectionOptions, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- selectContacts(options: ContactSelectionOptions): Promise\<Array\<Contact>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.Contacts    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ContactSelectionOptions | true | 选择联系人时的筛选条件 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回选择的联系人对象数组。 |  
| Promise<Array<Contact>> | 返回结果，返回选择的联系人对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.selectContacts({  
    isMultiSelect:false  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`selectContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`selectContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  let promise = contact.selectContacts({isMultiSelect:false});  
  promise.then((data) => {  
      console.log(`selectContact success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`selectContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## selectContact<sup>(deprecated)</sup>    
调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用Promise方式作为异步方法。  
 **调用形式：**     
- selectContact(): Promise\<Array\<Contact>>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.selectContact#selectContacts。  
 **系统能力:**  SystemCapability.Applications.Contacts  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<Contact>> | 以Promise形式返回结果，返回选择的联系人对象数组。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  let promise = contact.selectContact();  
  promise.then((data) => {  
      console.log(`selectContact success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`selectContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## deleteContact<sup>(deprecated)</sup>    
删除联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- deleteContact(key: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.deleteContact#deleteContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 联系人key值，一个联系人对应一个key。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步删除联系人之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.deleteContact('xxx', (err: BusinessError) => {  
      if (err) {  
          console.log(`deleteContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log('deleteContact success');  
  });  
    
```    
  
    
## deleteContact<sup>(10+)</sup>    
删除联系人，使用callback方式作为异步方法。  
 **调用形式：**     
    
- deleteContact(context: Context, key: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- deleteContact(context: Context, key: string): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |  
| key | string | true | 联系人key值，一个联系人对应一个key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步删除联系人之后的回调。 |  
| Promise<void> | 返回一个Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
    contact.deleteContact('xxx', (err: BusinessError) => {  
        if (err) {  
            console.log(`deleteContact callback: err->${JSON.stringify(err)}`);  
            return;  
        }  
        console.log('deleteContact success');  
    });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.deleteContact(context, 'xxx');  
  promise.then(() => {  
      console.log(`deleteContact success`);  
  }).catch((err: BusinessError) => {  
      console.error(`deleteContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## deleteContact<sup>(deprecated)</sup>    
删除联系人，使用Promise方式作为异步方法。  
 **调用形式：**     
- deleteContact(key: string): Promise\<void>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.deleteContact#deleteContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 联系人的key值，一个联系人对应一个key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 返回一个Promise对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  let promise = contact.deleteContact('xxx');  
  promise.then(() => {  
      console.log(`deleteContact success`);  
  }).catch((err: BusinessError) => {  
      console.error(`deleteContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryContact<sup>(deprecated)</sup>    
根据key查询联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContact(key: string, callback: AsyncCallback\<Contact>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContact#queryContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 联系人的key值，一个联系人对应一个key。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Contact> | true | 回调函数，返回查询的联系人对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContact('xxx', (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContact<sup>(10+)</sup>    
根据key查询联系人，使用callback方式作为异步方法。  
 **调用形式：**     
    
- queryContact(context: Context, key: string, callback: AsyncCallback\<Contact>): void    
起始版本： 10    
- queryContact(context: Context, key: string, holder: Holder, callback: AsyncCallback\<Contact>): void    
起始版本： 10    
- queryContact(context: Context, key: string, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void    
起始版本： 10    
- queryContact(context: Context, key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void    
起始版本： 10    
- queryContact(context: Context, key: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Contact>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |  
| key | string | true | 联系人的key值，一个联系人对应一个key。 |  
| holder | Holder | true | 创建联系人的应用信息。 |  
| attrs | ContactAttributes | true | 联系人的属性列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询的联系人对象。 |  
| Promise<Contact> | 以Promise形式返回结果，返回查询到的联系人对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Parameter error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.queryContact(context, 'xxx', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.queryContact(context, 'xxx', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then((data) => {  
      console.log(`queryContact success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryContact<sup>(deprecated)</sup>    
根据key查询联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContact(key: string, holder: Holder, callback: AsyncCallback\<Contact>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContact#queryContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 联系人的key值，一个联系人对应一个key。 |  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Contact> | true | 回调函数，返回查询的联系人对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContact('xxx', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContact<sup>(deprecated)</sup>    
根据key查询联系人  
 **调用形式：**     
- queryContact(key: string, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContact#queryContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 联系人的key值，一个联系人对应一个key。 |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 联系人的属性列表。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Contact> | true | 回调函数，返回查询的联系人对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContact('xxx', {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContact<sup>(deprecated)</sup>    
根据key查询联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContact(key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContact#queryContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 联系人的key值，一个联系人对应一个key。<br/> |  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。 |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 联系人的属性列表。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Contact> | true | 回调函数，返回查询的联系人对象。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContact('xxx', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContact<sup>(deprecated)</sup>    
根据key查询联系人，使用promise方式作为异步方法。  
 **调用形式：**     
- queryContact(key: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Contact>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContact#queryContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 联系人的key值，一个联系人对应一个key。 |  
| holder<sup>(deprecated)</sup> | Holder | false | 创建联系人的应用信息。 |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | false | 联系人的属性列表。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Contact> | 以Promise形式返回结果，返回查询到的联系人对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  let promise = contact.queryContact('xxx', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then((data) => {  
      console.log(`queryContact success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryContacts<sup>(deprecated)</sup>    
根据key查询联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContacts(callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContacts#queryContacts。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询的联系人对象。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContacts((err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContacts callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContacts callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContacts<sup>(10+)</sup>    
根据key查询联系人  
 **调用形式：**     
    
- queryContacts(context: Context, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContacts(context: Context, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContacts(context: Context, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContacts(context: Context, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContacts(context: Context, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。<br/> |  
| holder | Holder | true | 创建联系人的应用信息。<br/> |  
| attrs | ContactAttributes | true | 联系人的属性列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询的联系人对象。 |  
| Promise<Array<Contact>> | 以Promise形式返回结果，返回查询到的联系人对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.queryContacts(context, {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContacts callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContacts callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.queryContacts(context, {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then((data) => {  
      console.log(`queryContacts success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryContacts fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryContacts<sup>(deprecated)</sup>    
查询所有联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContacts(holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContacts#queryContacts。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询的联系人对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContacts({  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContacts callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContacts callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContacts<sup>(deprecated)</sup>    
查询所有联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContacts(attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContacts#queryContacts。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 回调函数，返回查询的联系人对象。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询的联系人对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContacts({  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContacts callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContacts callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContacts<sup>(deprecated)</sup>    
查询所有联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContacts(holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContacts#queryContacts。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。<br/> |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 联系人的属性列表。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询的联系人对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContacts({  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContacts callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContacts callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContacts<sup>(deprecated)</sup>    
查询所有联系人。  
 **调用形式：**     
- queryContacts(holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContacts#queryContacts。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| holder<sup>(deprecated)</sup> | Holder | false | 创建联系人的应用信息。<br/> |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | false | 联系人的属性列表。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<Contact>> | 以Promise形式返回结果，返回查询到的联系人对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  let promise = contact.queryContacts({  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then((data) => {  
      console.log(`queryContacts success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryContacts fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryContactsByEmail<sup>(deprecated)</sup>    
根据电话号码查询联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContactsByEmail(email: string, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByEmail#queryContactsByEmail。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| email<sup>(deprecated)</sup> | string | true | 联系人的邮箱地址。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询到的联系人对象数组。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContactsByEmail('xxx@email.com', (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByEmail callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByEmail callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContactsByEmail<sup>(10+)</sup>    
根据email查询联系人  
 **调用形式：**     
    
- queryContactsByEmail(context: Context, email: string, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContactsByEmail(context: Context, email: string, holder: Holder,     callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContactsByEmail(context: Context, email: string, attrs: ContactAttributes,     callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContactsByEmail(context: Context, email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContactsByEmail(context: Context, email: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |  
| email | string | true | 联系人的邮箱地址。 |  
| holder | Holder | true | 创建联系人的应用信息。 |  
| attrs | ContactAttributes | true | 联系人的属性列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询到联系人对象数组。 |  
| Promise<Array<Contact>> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.queryContactsByEmail(context, 'xxx@email.com', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByEmail callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByEmail callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.queryContactsByEmail(context, 'xxx@email.com', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]  
  });  
  promise.then((data) => {  
      console.log(`queryContactsByEmail success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryContactsByEmail fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryContactsByEmail<sup>(deprecated)</sup>    
查询联系人的所有群组，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContactsByEmail(email: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByEmail#queryContactsByEmail。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| email<sup>(deprecated)</sup> | string | true | 联系人的邮箱地址。<br/> |  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询到联系人对象数组。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContactsByEmail('xxx@email.com', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByEmail callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByEmail callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContactsByEmail<sup>(deprecated)</sup>    
查询联系人的所有群组，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContactsByEmail(email: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByEmail#queryContactsByEmail。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| email<sup>(deprecated)</sup> | string | true | 联系人的邮箱地址。<br/> |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 联系人的属性列表。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询到的群组对象数组。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.queryContactsByEmail(context, 'xxx@email.com', (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByEmail callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByEmail callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContactsByEmail<sup>(deprecated)</sup>    
查询联系人的所有群组，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContactsByEmail(email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByEmail#queryContactsByEmail。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| email<sup>(deprecated)</sup> | string | true | 联系人的邮箱地址。<br/> |  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。<br/> |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 联系人的属性列表。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询到联系人对象数组。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  contact.queryContactsByEmail('xxx@email.com', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByEmail callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByEmail callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContactsByEmail<sup>(deprecated)</sup>    
根据email查询联系人，使用Promise方式作为异步方法。  
 **调用形式：**     
- queryContactsByEmail(email: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByEmail#queryContactsByEmail。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| email<sup>(deprecated)</sup> | string | true | 联系人的邮箱地址。 |  
| holder<sup>(deprecated)</sup> | Holder | false | 创建联系人的应用信息。 |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | false | 联系人的属性列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<Contact>> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
  
  import { BusinessError } from '@ohos.base';  
  let promise = contact.queryContactsByEmail('xxx@email.com', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]  
  });  
  promise.then((data) => {  
      console.log(`queryContactsByEmail success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryContactsByEmail fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryContactsByPhoneNumber<sup>(deprecated)</sup>    
根据电话号码查询联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContactsByPhoneNumber(phoneNumber: string, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber<sup>(deprecated)</sup> | string | true | 联系人的电话号码。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询到的联系人对象数组。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.queryContactsByPhoneNumber(context, '138xxxxxxxx', (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByPhoneNumber callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByPhoneNumber callback: success data->${JSON.stringify(data)}`);  
  });    
```    
  
    
## queryContactsByPhoneNumber<sup>(10+)</sup>    
根据电话号码查询联系人  
 **调用形式：**     
    
- queryContactsByPhoneNumber(context: Context, phoneNumber: string, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContactsByPhoneNumber(context: Context, phoneNumber: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContactsByPhoneNumber(context: Context, phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContactsByPhoneNumber(context: Context, phoneNumber: string, holder: Holder, attrs: ContactAttributes,     callback: AsyncCallback\<Array\<Contact>>): void    
起始版本： 10    
- queryContactsByPhoneNumber(context: Context, phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |  
| phoneNumber | string | true | 联系人的电话号码。 |  
| holder | Holder | true | 创建联系人的应用信息。 |  
| attrs | ContactAttributes | true | 联系人的属性列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询到的联系人对象数组。 |  
| Promise<Array<Contact>> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.queryContactsByPhoneNumber(context, '138xxxxxxxx', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByPhoneNumber callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByPhoneNumber callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.queryContactsByPhoneNumber(context, '138xxxxxxxx', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then((data) => {  
      console.log(`queryContactsByPhoneNumber success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryContactsByPhoneNumber fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryContactsByPhoneNumber<sup>(deprecated)</sup>    
查询所有联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber<sup>(deprecated)</sup> | string | true | 联系人的电话号码。<br/> |  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询到的联系人对象数组。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryContactsByPhoneNumber('138xxxxxxxx', {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByPhoneNumber callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByPhoneNumber callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContactsByPhoneNumber<sup>(deprecated)</sup>    
查询所有联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContactsByPhoneNumber(phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber<sup>(deprecated)</sup> | string | true | 联系人的电话号码。<br/> |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 联系人的属性列表。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询到的联系人对象数组。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryContactsByPhoneNumber('138xxxxxxxx', {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByPhoneNumber callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByPhoneNumber callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContactsByPhoneNumber<sup>(deprecated)</sup>    
查询所有联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber<sup>(deprecated)</sup> | string | true | 联系人的电话号码。<br/> |  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。<br/> |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 联系人的属性列表。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Contact>> | true | 回调函数，返回查询到的联系人对象数组。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryContactsByPhoneNumber('138xxxxxxxx', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryContactsByPhoneNumber callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryContactsByPhoneNumber callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryContactsByPhoneNumber<sup>(deprecated)</sup>    
查询所有联系人，使用Promise方式作为异步方法。  
 **调用形式：**     
- queryContactsByPhoneNumber(phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber<sup>(deprecated)</sup> | string | true | 联系人的电话号码。<br/> |  
| holder<sup>(deprecated)</sup> | Holder | false | 创建联系人的应用信息。<br/> |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | false | 联系人的属性列表。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<Contact>> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.queryContactsByPhoneNumber(context, '138xxxxxxxx', {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then((data) => {  
      console.log(`queryContactsByPhoneNumber success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryContactsByPhoneNumber fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryGroups<sup>(deprecated)</sup>    
查询联系人的所有群组，使用callback方式作为异步方法。  
 **调用形式：**     
- queryGroups(callback: AsyncCallback\<Array\<Group>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryGroups#queryGroups。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Group>> | true | 回调函数，返回查询到的群组对象数组。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryGroups((err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryGroups callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryGroups callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryGroups<sup>(10+)</sup>    
查询联系人的所有群组  
 **调用形式：**     
    
- queryGroups(context: Context, callback: AsyncCallback\<Array\<Group>>): void    
起始版本： 10    
- queryGroups(context: Context, holder: Holder, callback: AsyncCallback\<Array\<Group>>): void    
起始版本： 10    
- queryGroups(context: Context, holder?: Holder): Promise\<Array\<Group>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |  
| holder | Holder | true | 创建联系人的应用信息。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询到的联系人对象数组。 |  
| Promise<Array<Group>> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.queryGroups(context, {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryGroups callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryGroups callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.queryGroups(context, {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  });  
  promise.then((data) => {  
      console.log(`queryGroups success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryGroups fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryGroups<sup>(deprecated)</sup>    
查询联系人的所有群组，使用callback方式作为异步方法。  
 **调用形式：**     
- queryGroups(holder: Holder, callback: AsyncCallback\<Array\<Group>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryGroups#queryGroups。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Group>> | true | 回调函数，返回查询到的联系人对象数组。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryGroups({  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryGroups callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryGroups callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryGroups<sup>(deprecated)</sup>    
查询联系人的所有群组，使用Promise方式作为异步方法。  
 **调用形式：**     
- queryGroups(holder?: Holder): Promise\<Array\<Group>>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryGroups#queryGroups。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| holder<sup>(deprecated)</sup> | Holder | false | 创建联系人的应用信息。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<Group>> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  let promise = contact.queryGroups({  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  });  
  promise.then((data) => {  
      console.log(`queryGroups success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryGroups fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryHolders<sup>(deprecated)</sup>    
查询所有创建联系人的应用信息，使用callback方式作为异步方法。  
 **调用形式：**     
- queryHolders(callback: AsyncCallback\<Array\<Holder>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryHolders#queryHolders。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Holder>> | true | 回调函数，返回查询到的创建联系人应用信息的对象数组。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryHolders((err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryHolders callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryHolders callback: success data->${JSON.stringify(data)}`);  
  });  
  ```  
    
```    
  
    
## queryHolders<sup>(10+)</sup>    
查询所有创建联系人的应用信息  
 **调用形式：**     
    
- queryHolders(context: Context, callback: AsyncCallback\<Array\<Holder>>): void    
起始版本： 10    
- queryHolders(context: Context): Promise\<Array\<Holder>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context] (js-apis-inner-application-context.md)。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询到的联系人对象数组。 |  
| Promise<Array<Holder>> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
    // 获取context  
    let context = getContext(this) as Context;  
    contact.queryHolders(context, (err: BusinessError, data) => {  
        if (err) {  
            console.log(`queryHolders callback: err->${JSON.stringify(err)}`);  
            return;  
        }  
        console.log(`queryHolders callback: success data->${JSON.stringify(data)}`);  
    });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.queryHolders(context);  
  promise.then((data) => {  
      console.log(`queryHolders success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryHolders fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryHolders<sup>(deprecated)</sup>    
查询所有创建联系人的应用信息。  
 **调用形式：**     
- queryHolders(): Promise\<Array\<Holder>>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryHolders#queryHolders。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<Holder>> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  let promise = contact.queryHolders();  
  promise.then((data) => {  
      console.log(`queryHolders success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryHolders fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryKey<sup>(deprecated)</sup>    
根据联系人的id查询联系人的key，使用callback方式作为异步方法。  
 **调用形式：**     
- queryKey(id: number, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryKey#queryKey。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 联系人对象的id属性。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数，返回查询到的联系人对应的key。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryKey(/*id*/1, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryKey callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryKey callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryKey<sup>(10+)</sup>    
根据联系人的id查询联系人的key  
 **调用形式：**     
    
- queryKey(context: Context, id: number, callback: AsyncCallback\<string>): void    
起始版本： 10    
- queryKey(context: Context, id: number, holder: Holder, callback: AsyncCallback\<string>): void    
起始版本： 10    
- queryKey(context: Context, id: number, holder?: Holder): Promise\<string>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true |  |  
| id | number | true | 联系人对象的id属性。 |  
| holder | Holder | true | 创建联系人的应用信息。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询到的联系人对象数组。 |  
| Promise<string> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
    // 获取context  
    let context = getContext(this) as Context;  
    contact.queryKey(context, /*id*/1, {  
        holderId: 0,  
        bundleName: "",  
        displayName: ""  
    }, (err: BusinessError, data) => {  
        if (err) {  
            console.log(`queryKey callback: err->${JSON.stringify(err)}`);  
            return;  
        }  
        console.log(`queryKey callback: success data->${JSON.stringify(data)}`);  
    });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.queryKey(context, /*id*/1, {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  });  
  promise.then((data) => {  
      console.log(`queryKey success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryKey fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryKey<sup>(deprecated)</sup>    
根据联系人的id查询联系人的key，使用callback方式作为异步方法。  
 **调用形式：**     
- queryKey(id: number, holder: Holder, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryKey#queryKey。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 联系人对象的id属性。<br/> |  
| holder<sup>(deprecated)</sup> | Holder | true | 创建联系人的应用信息。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数，返回查询到的联系人对象数组。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryKey(/*id*/1, {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryKey callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryKey callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryKey<sup>(deprecated)</sup>    
根据联系人的id查询联系人的key，使用Promise方式作为异步方法。  
 **调用形式：**     
- queryKey(id: number, holder?: Holder): Promise\<string>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryKey#queryKey。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 联系人对象的id属性。 |  
| holder<sup>(deprecated)</sup> | Holder | false | 创建联系人的应用信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  let promise = contact.queryKey(/*id*/1, {  
      holderId: 0,  
      bundleName: "",  
      displayName: ""  
  });  
  promise.then((data) => {  
      console.log(`queryKey success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryKey fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryMyCard<sup>(deprecated)</sup>    
查询“我的名片”，使用callback方式作为异步方法。  
 **调用形式：**     
- queryMyCard(callback: AsyncCallback\<Contact>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryMyCard#queryMyCard。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Contact> | true | 回调函数，返回“我的名片”信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryMyCard((err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryMyCard callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryMyCard callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryMyCard<sup>(10+)</sup>    
查询“我的名片”  
 **调用形式：**     
    
- queryMyCard(context: Context, callback: AsyncCallback\<Contact>): void    
起始版本： 10    
- queryMyCard(context: Context, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void    
起始版本： 10    
- queryMyCard(context: Context, attrs?: ContactAttributes): Promise\<Contact>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context] (js-apis-inner-application-context.md)。<br/> |  
| attrs | ContactAttributes | true | 联系人的属性列表。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询到的联系人对象数组。 |  
| Promise<Contact> | 以Promise形式返回结果，返回查询到的联系人对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.queryMyCard(context, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryMyCard callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryMyCard callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.queryMyCard(context, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then((data) => {  
      console.log(`queryMyCard success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryMyCard fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## queryMyCard<sup>(deprecated)</sup>    
查询“我的名片”，使用callback方式作为异步方法。  
 **调用形式：**     
- queryMyCard(attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryMyCard#queryMyCard。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 联系人的属性列表。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Contact> | true | 回调函数，返回“我的名片”信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.queryMyCard({  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`queryMyCard callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`queryMyCard callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## queryMyCard<sup>(deprecated)</sup>    
查询“我的名片”，使用Promise方式作为异步方法。  
 **调用形式：**     
- queryMyCard(attrs?: ContactAttributes): Promise\<Contact>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.queryMyCard#queryMyCard。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| attrs<sup>(deprecated)</sup> | ContactAttributes | false | 联系人的属性列表。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Contact> | 以Promise形式返回结果，返回“我的名片”信息。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  let promise = contact.queryMyCard({  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then((data) => {  
      console.log(`queryMyCard success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`queryMyCard fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## updateContact<sup>(deprecated)</sup>    
更新联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- updateContact(contact: Contact, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.updateContact#updateContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| contact<sup>(deprecated)</sup> | Contact | true | 联系人信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步更新联系人之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.updateContact({  
      id: 1,  
      name: {fullName: 'xxx'},  
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]  
  }, (err: BusinessError) => {  
      if (err) {  
          console.log(`updateContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log('updateContact success');  
  });  
    
```    
  
    
## updateContact<sup>(10+)</sup>    
更新联系人  
 **调用形式：**     
    
- updateContact(context: Context, contact: Contact, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updateContact(context: Context, contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updateContact(context: Context, contact: Contact, attrs?: ContactAttributes): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context] (js-apis-inner-application-context.md)。<br/> |  
| contact | Contact | true | 联系人信息。 |  
| attrs | ContactAttributes | true | 联系人的属性列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步更新联系人之后的回调。 |  
| Promise<void> | 返回一个Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.updateContact(context, {  
      id: 1,  
      name: {fullName: 'xxx'},  
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError) => {  
      if (err) {  
          console.log(`updateContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log('updateContact success');  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.updateContact(context, {  
      id: 1,  
      name: {fullName: 'xxx'},  
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then(() => {  
      console.log('updateContact success');  
  }).catch((err: BusinessError) => {  
      console.error(`updateContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## updateContact<sup>(deprecated)</sup>    
更新联系人，使用callback方式作为异步方法。  
 **调用形式：**     
- updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.updateContact#updateContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| contact<sup>(deprecated)</sup> | Contact | true | 联系人信息。 |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | true | 联系人的属性列表。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步更新联系人之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.updateContact({  
      id: 1,  
      name: {fullName: 'xxx'},  
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  }, (err: BusinessError) => {  
      if (err) {  
          console.log(`updateContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log('updateContact success');  
  });  
    
```    
  
    
## updateContact<sup>(deprecated)</sup>    
更新联系人，使用Promise方式作为异步方法。  
 **调用形式：**     
- updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.updateContact#updateContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| contact<sup>(deprecated)</sup> | Contact | true | 联系人信息。 |  
| attrs<sup>(deprecated)</sup> | ContactAttributes | false | 联系人的属性列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 返回一个Promise对象。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  let promise = contact.updateContact({  
      id: 1,  
      name: {fullName: 'xxx'},  
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]  
  }, {  
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]  
  });  
  promise.then(() => {  
      console.log('updateContact success');  
  }).catch((err: BusinessError) => {  
      console.error(`updateContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## isLocalContact<sup>(deprecated)</sup>    
判断当前联系人id是否在电话簿中，使用callback方式作为异步方法。  
 **调用形式：**     
- isLocalContact(id: number, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.isLocalContact#isLocalContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 联系人对象的id属性，一个联系人对应一个id。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数，返回布尔值。true代表联系人id在本地电话簿中，false则代表联系人id不在本地电话簿中。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
    contact.isLocalContact(/*id*/1, (err: BusinessError, data) => {  
        if (err) {  
            console.log(`isLocalContact callback: err->${JSON.stringify(err)}`);  
            return;  
        }  
        console.log(`isLocalContact callback: success data->${JSON.stringify(data)}`);  
    });  
    
```    
  
    
## isLocalContact<sup>(10+)</sup>    
判断当前联系人id是否在电话簿中  
 **调用形式：**     
    
- isLocalContact(context: Context, id: number, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isLocalContact(context: Context, id: number): Promise\<boolean>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context] (js-apis-inner-application-context.md)。<br/> |  
| id | number | true | 联系人对象的id属性，一个联系人对应一个id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回布尔值。true代表联系人id在本地电话簿中，false则代表联系人id不在本地电话簿中。 |  
| Promise<boolean> | 以Promise形式返回结果，返回布尔值。true代表联系人id在本地电话簿中，false则代表联系人id不在本地电话簿中。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.isLocalContact(context, /*id*/1, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`isLocalContact callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`isLocalContact callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.isLocalContact(context, /*id*/1);  
  promise.then((data) => {  
      console.log(`isLocalContact success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`isLocalContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## isLocalContact<sup>(deprecated)</sup>    
判断当前联系人id是否在电话簿中，使用Promise方式作为异步方法。  
 **调用形式：**     
- isLocalContact(id: number): Promise\<boolean>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.isLocalContact#isLocalContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 联系人对象的id属性，一个联系人对应一个id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回结果，返回布尔值。true代表联系人id在本地电话簿中，false则代表联系人id不在本地电话簿中。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  let promise = contact.isLocalContact(/*id*/1);  
  promise.then((data) => {  
      console.log(`isLocalContact success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`isLocalContact fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## isMyCard<sup>(deprecated)</sup>    
判断是否为“我的名片”，使用callback方式作为异步方法。  
 **调用形式：**     
- isMyCard(id: number, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.deleteContact#deleteContact。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 联系人对象的id属性。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数，返回是否为“我的名片”的布尔值。true代表此联系人是“我的名片”，false则代表不是。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  contact.isMyCard(/*id*/1, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`isMyCard callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`isMyCard callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## isMyCard<sup>(10+)</sup>    
判断是否为“我的名片”  
 **调用形式：**     
    
- isMyCard(context: Context, id: number, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isMyCard(context: Context, id: number): Promise\<boolean>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context] (js-apis-inner-application-context.md)。<br/> |  
| id | number | true | 联系人对象的id属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回是否为“我的名片”的布尔值。true代表此联系人是“我的名片”，false则代表不是。 |  
| Promise<boolean> | 以Promise形式返回结果，返回是否为“我的名片”的布尔值。true代表此联系人是“我的名片”，false则代表不是。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  contact.isMyCard(context, /*id*/1, (err: BusinessError, data) => {  
      if (err) {  
          console.log(`isMyCard callback: err->${JSON.stringify(err)}`);  
          return;  
      }  
      console.log(`isMyCard callback: success data->${JSON.stringify(data)}`);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  // 获取context  
  let context = getContext(this) as Context;  
  let promise = contact.isMyCard(context, /*id*/1);  
  promise.then((data) => {  
      console.log(`isMyCard success: data->${JSON.stringify(data)}`);  
  }).catch((err: BusinessError) => {  
      console.error(`isMyCard fail: err->${JSON.stringify(err)}`);  
  });  
    
```    
  
    
## isMyCard<sup>(deprecated)</sup>    
<span style="letter-spacing: 0px;">判断是否为“我的名片”，使用Promise方式作为异步方法。</span>。  
 **调用形式：**     
- isMyCard(id: number): Promise\<boolean>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: contact.isMyCard#isMyCard。  
 **系统能力:**  SystemCapability.Applications.ContactsData  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 联系人对象的id属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回结果，返回是否为“我的名片”的布尔值。true代表此联系人是“我的名片”，false则代表不是。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
    let promise = contact.isMyCard(/*id*/1);  
    promise.then((data) => {  
        console.log(`isMyCard success: data->${JSON.stringify(data)}`);  
    }).catch((err: BusinessError) => {  
        console.error(`isMyCard fail: err->${JSON.stringify(err)}`);  
    });  
    
```    
  
    
## ContactSelectionOptions<sup>(10+)</sup>    
选择联系人条件。  
 **系统能力:**  SystemCapability.Applications.Contacts    
### 属性    
 **系统能力:**  SystemCapability.Applications.Contacts    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isMultiSelect<sup>(10+)</sup> | boolean | false | false | 是否为多选 |  
    
## Contact    
联系人对象类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| INVALID_CONTACT_ID | -1 | true | true | 默认联系人的id。 |  
| id | number | true | false | 联系人的id。 |  
| key | string | true | false | 联系人的key。 |  
| contactAttributes | ContactAttributes | false | false | 联系人的属性列表。 |  
| emails | Email[] | false | false | 联系人的邮箱地址列表。 |  
| events | Event[] | false | false | 联系人的生日、周年纪念等重要日期列表。 |  
| groups | Group[] | false | false | 联系人的群组列表。 |  
| imAddresses | ImAddress[] | false | false | 联系人的即时消息地址列表。 |  
| phoneNumbers | PhoneNumber[] | false | false | 联系人的电话号码列表。 |  
| portrait | Portrait | false | false | 联系人的头像。 |  
| postalAddresses | PostalAddress[] | false | false | 联系人的邮政地址列表。 |  
| relations | Relation[] | false | false | 联系人的关系列表。 |  
| sipAddresses | SipAddress[] | false | false | 联系人的会话发起协议（SIP）地址列表。 |  
| websites | Website[] | false | false | 联系人的网站列表。 |  
| name | Name | false | false | 联系人的姓名。 |  
| nickName | NickName | false | false | 联系人的昵称。 |  
| note | Note | false | false | 联系人的备注。 |  
| organization | Organization | false | false | 联系人的备注。 |  
    
## ContactAttributes    
联系人属性列表，一般作为入参用来标识希望查询的联系人属性。当传入为null时，默认查询全部属性。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| attributes | Attribute[] | false | true | 联系人属性列表。 |  
    
## Attribute    
枚举，联系人属性列表。    
    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ATTR_CONTACT_EVENT | 0 | 联系人的生日、周年纪念等重要日期。 |  
| ATTR_EMAIL | 1 | 联系人的邮箱地址。 |  
| ATTR_GROUP_MEMBERSHIP | 2 | 联系人的群组。 |  
| ATTR_IM | 3 | 联系人的即时消息地址。 |  
| ATTR_NAME | 4 | 联系人的姓名。 |  
| ATTR_NICKNAME | 5 | 联系人的昵称。 |  
| ATTR_NOTE | 6 | 联系人的备注。 |  
| ATTR_ORGANIZATION | 7 | 联系人的组织信息。 |  
| ATTR_PHONE | 8 | 联系人的电话号码。 |  
| ATTR_PORTRAIT | 9 | 联系人的头像。 |  
| ATTR_POSTAL_ADDRESS | 10 | 联系人的邮政地址。 |  
| ATTR_RELATION | 11 | 联系人的关系。 |  
| ATTR_SIP_ADDRESS | 12 | 联系人的会话发起协议（SIP）地址。 |  
| ATTR_WEBSITE | 13 | 联系人的网站。 |  
    
## Email  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| CUSTOM_LABEL | 0 | true | true | 自定义事件类型。 |  
| EMAIL_HOME | 1 | true | true | 周年纪念事件类型。 |  
| EMAIL_WORK | 2 | true | true |  |  
| EMAIL_OTHER | 3 | true | true | 其它事件类型。 |  
| INVALID_LABEL_ID | -1 | true | true | 无效事件类型。 |  
| email | string | false | true |  |  
| labelName | string | false | false | 事件类型名称。 |  
| displayName | string | false | false |  |  
| labelId | number | false | false | 事件类型。 |  
    
## Event    
联系人事件类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| CUSTOM_LABEL | 0 | true | true | 自定义事件类型。 |  
| EVENT_ANNIVERSARY | 1 | true | true | 周年纪念事件类型。 |  
| EVENT_OTHER | 2 | true | true | 其它事件类型。 |  
| EVENT_BIRTHDAY | 3 | true | true | 生日事件类型。 |  
| INVALID_LABEL_ID | -1 | true | true | 无效事件类型。 |  
| eventDate | string | false | true | 事件的日期。 |  
| labelName | string | false | false | 事件类型名称。 |  
| labelId | number | false | false | 事件类型。 |  
    
## Group    
联系人的群组类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| groupId | number | false | false | 联系人群组的id。 |  
| title | string | false | true | 联系人群组的名称。 |  
    
## Holder    
创建联系人的应用信息类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | true | true | Bundle名称。 |  
| displayName | string | true | false | 应用名称。 |  
| holderId | number | false | false | 应用ID。 |  
    
## ImAddress    
联系人的即时消息地址。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| CUSTOM_LABEL | -1 | true | true | 自定义即时消息类型。 |  
| IM_AIM | 0 | true | true | AIM即时消息类型。 |  
| IM_MSN | 1 | true | true | MSN即时消息类型。 |  
| IM_YAHOO | 2 | true | true | YAHOO即时消息类型。 |  
| IM_SKYPE | 3 | true | true | SKYPE即时消息类型。 |  
| IM_QQ | 4 | true | true | QQ即时消息类型。 |  
| IM_ICQ | 6 | true | true | ICQ即时消息类型。 |  
| IM_JABBER | 7 | true | true | JABBER即时消息类型。 |  
| INVALID_LABEL_ID | -2 | true | true | 无效的即时消息类型。 |  
| imAddress | string | false | true | 即时消息地址。 |  
| labelName | string | false | false | 即时消息类型名称。 |  
| labelId | number | false | false | 即时消息类型。 |  
    
## Name    
联系人的名字类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| familyName | string | false | false | 联系人的家庭姓名。 |  
| familyNamePhonetic | string | false | false | 联系人的家庭姓名拼音。 |  
| fullName | string | false | true | 联系人的全名。 |  
| givenName | string | false | false | 联系人的名称（firstName）。 |  
| givenNamePhonetic | string | false | false | 联系人的名称拼音。 |  
| middleName | string | false | false | 联系人的中间名。 |  
| middleNamePhonetic | string | false | false | 联系人的中间名拼音。 |  
| namePrefix | string | false | false | 联系人的姓名前缀。 |  
| nameSuffix | string | false | false | 联系人的姓名后缀。 |  
    
## NickName    
联系人的昵称类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| nickName | string | false | true | 联系人的昵称。 |  
    
## Note    
联系人的备注类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| noteContent | string | false | true | 联系人的备注内容。 |  
    
## Organization    
联系人的组织类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 组织名称。 |  
| title | string | false | false | 组织标题。 |  
    
## PhoneNumber    
联系人电话号码类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| CUSTOM_LABEL | 0 | true | true | 自定义电话类型。 |  
| NUM_HOME | 1 | true | true | 家庭电话类型。 |  
| NUM_MOBILE | 2 | true | true | 移动电话类型。 |  
| NUM_WORK | 3 | true | true | 工作电话类型。 |  
| NUM_FAX_WORK | 4 | true | true | 工作传真电话类型。 |  
| NUM_FAX_HOME | 5 | true | true | 家庭传真电话类型。 |  
| NUM_PAGER | 6 | true | true | 寻呼机电话类型。 |  
| NUM_OTHER | 7 | true | true | 其它电话类型。 |  
| NUM_CALLBACK | 8 | true | true | 回呼电话类型。 |  
| NUM_CAR | 9 | true | true | 车机电话类型。 |  
| NUM_COMPANY_MAIN | 10 | true | true | 公司电话类型。 |  
| NUM_ISDN | 11 | true | true | 综合业务数字网（ISDN）电话类型。 |  
| NUM_MAIN | 12 | true | true | 主电话类型。 |  
| NUM_OTHER_FAX | 13 | true | true | 其它传真类型。 |  
| NUM_RADIO | 14 | true | true | 无线电话类型。 |  
| NUM_TELEX | 15 | true | true | 电传电话类型。 |  
| NUM_TTY_TDD | 16 | true | true | 电传打字机（TTY）或测试驱动开发（TDD）电话类型。 |  
| NUM_WORK_MOBILE | 17 | true | true | 工作移动电话类型。 |  
| NUM_WORK_PAGER | 18 | true | true | 工作寻呼机电话类型。 |  
| NUM_ASSISTANT | 19 | true | true | 助理电话类型。 |  
| NUM_MMS | 20 | true | true | 彩信电话类型。 |  
| INVALID_LABEL_ID | -1 | true | true | 无效电话类型。 |  
| labelName | string | false | false | 电话号码类型名称。 |  
| phoneNumber | string | false | true | 电话号码。 |  
| labelId | number | false | false | 电话号码类型。 |  
    
## Portrait    
联系人的头像类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri | string | false | true | 联系人的头像。 |  
    
## PostalAddress    
联系人的邮政地址类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| CUSTOM_LABEL | 0 | true | true | 自定义邮政地址类型。 |  
| ADDR_HOME | 1 | true | true | 家庭地址类型。 |  
| ADDR_WORK | 2 | true | true | 工作地址类型。 |  
| ADDR_OTHER | 3 | true | true | 其它地址类型。 |  
| INVALID_LABEL_ID | -1 | true | true | 无效地址类型。 |  
| city | string | false | false | 联系人所在的城市。 |  
| country | string | false | false | 联系人所在的国家。 |  
| labelName | string | false | false | 邮政地址类型名称。 |  
| neighborhood | string | false | false | 联系人的邻居。 |  
| pobox | string | false | false | 联系人的邮箱。 |  
| postalAddress | string | false | true | 联系人的邮政地址。 |  
| postcode | string | false | false | 联系人所在区域的邮政编码。 |  
| region | string | false | false | 联系人所在的区域。 |  
| street | string | false | false | 联系人所在的街道。 |  
| labelId | number | false | false | 邮政地址类型。 |  
    
## Relation    
联系人的关系类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| CUSTOM_LABEL | 0 | true | true | 自定义关系类型。 |  
| RELATION_ASSISTANT | 1 | true | true | 助手关系类型。 |  
| RELATION_BROTHER | 2 | true | true | 兄弟关系类型。 |  
| RELATION_CHILD | 3 | true | true | 子女关系类型。 |  
| RELATION_DOMESTIC_PARTNER | 4 | true | true | 同居同伴关系类型。 |  
| RELATION_FATHER | 5 | true | true | 父亲关系类型。 |  
| RELATION_FRIEND | 6 | true | true | 朋友关系类型。 |  
| RELATION_MANAGER | 7 | true | true | 管理者关系类型。 |  
| RELATION_MOTHER | 8 | true | true | 母亲关系类型。 |  
| RELATION_PARENT | 9 | true | true | 父母关系类型。 |  
| RELATION_PARTNER | 10 | true | true | 合作伙伴关系类型。 |  
| RELATION_REFERRED_BY | 11 | true | true | 推荐人关系类型。 |  
| RELATION_RELATIVE | 12 | true | true | 亲属关系类型。 |  
| RELATION_SISTER | 13 | true | true | 姐妹关系类型。 |  
| RELATION_SPOUSE | 14 | true | true | 配偶关系类型。 |  
| INVALID_LABEL_ID | -1 | true | true | 无效的关系类型。 |  
| labelName | string | false | false | 关系类型名称。 |  
| relationName | string | false | true | 关系名称。 |  
| labelId | number | false | false | 关系类型。 |  
    
## SipAddress    
联系人的会话发起协议（SIP）地址类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| CUSTOM_LABEL | 0 | true | true | 自定义会话发起协议（SIP）地址类型。 |  
| SIP_HOME | 1 | true | true | 家庭会话发起协议（SIP）地址类型。 |  
| SIP_WORK | 2 | true | true | 工作会话发起协议（SIP）地址类型。 |  
| SIP_OTHER | 3 | true | true | 其它会话发起协议（SIP）地址类型。 |  
| INVALID_LABEL_ID | -1 | true | true | 无效会话发起协议（SIP）地址类型。 |  
| labelName | string | false | false | 会话发起协议（SIP）地址类型名称。 |  
| sipAddress | string | false | true | 会话发起协议（SIP）地址。 |  
| labelId | number | false | false | 会话发起协议（SIP）地址类型。 |  
    
## Website    
联系人的网站信息类。  
 **系统能力:**  SystemCapability.Applications.ContactsData    
### 属性    
 **系统能力:**  SystemCapability.Applications.ContactsData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| website | string | false | true | 联系人的网站信息。 |  
