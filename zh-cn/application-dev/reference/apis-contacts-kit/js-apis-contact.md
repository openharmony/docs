# @ohos.contact (联系人)

本模块提供联系人管理能力，包括添加联系人、删除联系人、更新联系人等。

>**说明：**
>
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import { contact } from '@kit.ContactsKit';
```

## contact.addContact<sup>10+</sup>

addContact(context: Context, contact: Contact, callback: AsyncCallback&lt;number&gt;): void 

添加联系人，使用callback方式作为异步方法。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                     | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| contact  | [Contact](#contact)         | 是   | 联系人信息。                                                 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。成功返回添加的联系人id；失败返回失败的错误码。     |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.addContact(
    context,
    {
	  name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
    }, (err: BusinessError, data) => {
      if (err) {
        console.error(`Failed to add Contact. Code:${err.code}, message: ${err.message}`);
        return;
      }
      console.info(`Succeeded in adding Contact. data: ${JSON.stringify(data)}`);
  });
```

## contact.addContact(deprecated)<sup>7+</sup>

addContact(contact:Contact, callback:AsyncCallback&lt;number&gt;): void

添加联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[addContact](#contactaddcontact10)

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                     |
| -------- | --------------------------- | ---- | -------------------------------------------------------- |
| contact  | [Contact](#contact)         | 是   | 联系人信息。                                             |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。成功返回添加的联系人id；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.addContact({
      name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to add Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in adding Contact. data: ${JSON.stringify(data)}`);
  });
  ```

## contact.addContact<sup>10+</sup>

addContact(context: Context, contact: Contact): Promise<number&gt;

添加联系人，使用Promise方式作为异步方法。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| context | Context             | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| contact | [Contact](#contact) | 是   | 联系人信息。                                                 |

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回添加的联系人id。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified. |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.addContact(
    context,
    {
	  name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
  });
  promise.then((data) => {
    console.info(`Succeeded in adding Contact. data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to add Contact. Code: ${err.code}, message: ${err.message}`);
  });
```

## contact.addContact(deprecated)<sup>7+</sup>

addContact(contact: Contact): Promise&lt;number&gt;

添加联系人，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[addContact](#contactaddcontact10-1)

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                | 必填 | 说明         |
| ------- | ------------------- | ---- | ------------ |
| contact | [Contact](#contact) | 是   | 联系人信息。 |

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回添加的联系人id。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.addContact({
      name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
  });
  promise.then((data) => {
      console.info(`Succeeded in adding Contact. data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to add Contact. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.deleteContact<sup>10+</sup>

deleteContact(context: Context, key: string, callback: AsyncCallback&lt;void&gt;): void

删除联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                   | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| key      | string                    | 是   | 联系人的唯一查询键key值，一个联系人对应一个key。             |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。成功返回删除的联系人id；失败返回失败的错误码。     |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified. |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context; 
  contact.deleteContact(context, 'xxx', (err: BusinessError) => {
      if (err) {
          console.error(`Failed to delete Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info('Succeeded in deleting Contact.');
  });
```

## contact.deleteContact(deprecated)<sup>7+</sup>

deleteContact(key: string, callback: AsyncCallback&lt;void&gt;): void

删除联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[deleteContact](#contactdeletecontact10)

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                 |
| -------- | ------------------------- | ---- | ------------------------------------ |
| key      | string                    | 是   | 联系人的唯一查询键key值，一个联系人对应一个key。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。成功返回删除的联系人id；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.deleteContact('xxx', (err: BusinessError) => {
      if (err) {
          console.error(`Failed to delete Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info('Succeeded in deleting Contact.');
  });
  ```


## contact.deleteContact<sup>10+</sup>

deleteContact(context: Context,  key: string): Promise&lt;void&gt;

删除联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| key     | string  | 是   | 联系人的唯一查询键key值，一个联系人对应一个key。                       |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified. |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.deleteContact(context, 'xxx');
  promise.then(() => {
      console.info(`Succeeded in deleting Contact.`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to delete Contact. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.deleteContact(deprecated)<sup>7+</sup>

deleteContact(key: string): Promise&lt;void&gt;

删除联系人，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[deleteContact](#contactdeletecontact10-1)

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| key    | string | 是   | 联系人的唯一查询键key值，一个联系人对应一个key。 |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.deleteContact('xxx');
  promise.then(() => {
      console.info(`Succeeded in deleting Contact.`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to delete Contact. Code: ${err.code}, message: ${err.message}`);
  });
  ```


## contact.updateContact<sup>10+</sup>

updateContact(context: Context, contact: Contact, callback: AsyncCallback&lt;void&gt;): void

更新联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS和ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                   | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| contact  | [Contact](#contact)       | 是   | 联系人信息。id必填。                                         |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。成功返回更新的联系人id；失败返回失败的错误码。     |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.updateContact(context, {
      id: 1,
      name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
  }, (err: BusinessError) => {
      if (err) {
          console.error(`Failed to update Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info('Succeeded in updating Contact.');
  });
  ```

## contact.updateContact(deprecated)<sup>7+</sup>

updateContact(contact: Contact, callback: AsyncCallback&lt;void&gt;): void

更新联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[updateContact](#contactupdatecontact10)

**需要权限**：ohos.permission.WRITE_CONTACTS和ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                 |
| -------- | ------------------------- | ---- | ------------------------------------ |
| contact  | [Contact](#contact)       | 是   | 联系人信息。id必填。                         |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。成功返回更新的联系人id；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.updateContact({
      id: 1,
      name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
  }, (err: BusinessError) => {
      if (err) {
          console.error(`Failed to update Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info('Succeeded in updating Contact.');
  });
  ```


## contact.updateContact<sup>10+</sup>

updateContact(context: Context,  contact: Contact, attrs: ContactAttributes, callback: AsyncCallback&lt;void&gt;): void

更新联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS和ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                 | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| contact  | [Contact](#contact)                     | 是   | 联系人信息。id必填。                                         |
| attrs    | [ContactAttributes](#contactattributes) | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;void&gt;               | 是   | 回调函数。成功返回更新的联系人id；失败返回失败的错误码。     |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified. |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.updateContact(context, {
      id: 1,
      name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError) => {
      if (err) {
          console.error(`Failed to update Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info('Succeeded in updating Contact.');
  });
  ```

## contact.updateContact(deprecated)<sup>7+</sup>

updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback&lt;void&gt;): void

更新联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[updateContact](#contactupdatecontact10-1)

**需要权限**：ohos.permission.WRITE_CONTACTS和ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                 |
| -------- | --------------------------------------- | ---- | ------------------------------------ |
| contact  | [Contact](#contact)                     | 是   | 联系人信息。id必填。                         |
| attrs    | [ContactAttributes](#contactattributes) | 是   | 联系人的属性列表。                   |
| callback | AsyncCallback&lt;void&gt;               | 是   | 回调函数。成功返回更新的联系人id；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.updateContact({
      id: 1,
      name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError) => {
      if (err) {
          console.error(`Failed to update Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info('Succeeded in updating Contact.');
  });
  ```


## contact.updateContact<sup>10+</sup>

updateContact(context: Context,  contact: Contact, attrs?: ContactAttributes): Promise&lt;void&gt;

更新联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS和ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                                    | 必填 | 说明                                                         |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                                 | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| contact | [Contact](#contact)                     | 是   | 联系人信息。id必填。                                                 |
| attrs   | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。                                           |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified. |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.updateContact(context, {
      id: 1,
      name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then(() => {
      console.info('Succeeded in updating Contact.');
  }).catch((err: BusinessError) => {
      console.error(`Failed to update Contact. Code: ${err.code}, message: ${err.message}`);
  });
```

## contact.updateContact(deprecated)<sup>7+</sup>

updateContact(contact: Contact, attrs?: ContactAttributes): Promise&lt;void&gt;

更新联系人，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[updateContact](#contactupdatecontact10-2)

**需要权限**：ohos.permission.WRITE_CONTACTS和ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                                    | 必填 | 说明               |
| ------- | --------------------------------------- | ---- | ------------------ |
| contact | [Contact](#contact)                     | 是   | 联系人信息。id必填。       |
| attrs   | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。 |

**返回值：**
| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.updateContact({
      id: 1,
      name: {
	    fullName: 'xxx'
	  },
      phoneNumbers: [{
	    phoneNumber: '138xxxxxxxx'
	  }]
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then(() => {
      console.info('Succeeded in updating Contact.');
  }).catch((err: BusinessError) => {
      console.error(`Failed to update Contact. Code: ${err.code}, message: ${err.message}`);
  });
  ```


## contact.isLocalContact<sup>10+</sup>

isLocalContact(context: Context,  id: number, callback: AsyncCallback&lt;boolean&gt;): void

判断当前联系人id是否在电话簿中，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                      | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| id       | number                       | 是   | 联系人对象的id属性，一个联系人对应一个id。                   |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。成功返回布尔值，true代表联系人id在本地电话簿中，false则代表联系人id不在本地电话簿中；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.isLocalContact(context, /*id*/1, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to isLocalContact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in isLocalContact.`);
  });
  ```

## contact.isLocalContact(deprecated)<sup>7+</sup>

isLocalContact(id: number, callback: AsyncCallback&lt;boolean&gt;): void

判断当前联系人id是否在电话簿中，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[isLocalContact](#contactislocalcontact10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| id       | number                       | 是   | 联系人对象的id属性，一个联系人对应一个id。                   |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。成功返回布尔值，true代表联系人id在本地电话簿中，false则代表联系人id不在本地电话簿中；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.isLocalContact(/*id*/1, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to isLocalContact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in isLocalContact.`);
  });
  ```

## contact.isLocalContact<sup>10+</sup>

isLocalContact(context: Context,  id: number): Promise&lt;boolean&gt;

判断当前联系人id是否在电话簿中，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| id      | number  | 是   | 联系人对象的id属性，一个联系人对应一个id。                   |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示联系人id在本地电话簿中，返回false表示联系人id不在本地电话簿中。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.  |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.isLocalContact(context, /*id*/1);
  promise.then((data) => {
      console.info(`Succeeded in isLocalContact. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to isLocalContact. Code: ${err.code}, message: ${err.message}`);
  });
```

## contact.isLocalContact(deprecated)<sup>7+</sup>

isLocalContact(id: number): Promise&lt;boolean&gt;

判断当前联系人id是否在电话簿中，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[isLocalContact](#contactislocalcontact10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                       |
| ------ | ------ | ---- | ------------------------------------------ |
| id     | number | 是   | 联系人对象的id属性，一个联系人对应一个id。 |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示联系人id在本地电话簿中，返回false表示联系人id不在本地电话簿中。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.isLocalContact(/*id*/1);
  promise.then((data) => {
      console.info(`Succeeded in isLocalContact. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to isLocalContact. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.isMyCard<sup>10+</sup>

isMyCard(context: Context,  id: number, callback: AsyncCallback&lt;boolean&gt;): void

判断是否为“我的名片”，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                      | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| id       | number                       | 是   | 名片对象的id属性。                                           |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。成功返回是否为“我的名片”的布尔值。true代表的是“我的名片”，false则代表不是；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.  |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.isMyCard(context, /*id*/1, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to isMyCard. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in isMyCard. data->${JSON.stringify(data)}`);
  });
```

## contact.isMyCard(deprecated)<sup>7+</sup>

isMyCard(id: number, callback: AsyncCallback&lt;boolean&gt;): void

判断是否为“我的名片”，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[isMyCard](#contactismycard10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| id       | number                       | 是   | 名片对象的id属性。                                           |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。成功返回是否为“我的名片”的布尔值。true代表的是“我的名片”，false则代表不是；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.isMyCard(/*id*/1, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to isMyCard. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in isMyCard. data->${JSON.stringify(data)}`);
  });
  ```


## contact.isMyCard<sup>10+</sup>

isMyCard(context: Context,  id: number): Promise&lt;boolean&gt;

判断是否为“我的名片”，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| id      | number  | 是   | 名片对象的id属性。                                         |

**返回值：**

| 类型                   | 说明                                                       |
| ---------------------- | ---------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示是“我的名片”，返回false表示不是。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.  |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.isMyCard(context, /*id*/1);
  promise.then((data) => {
      console.info(`Succeeded in isMyCard. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to isMyCard. Code: ${err.code}, message: ${err.message}`);
  });
```

## contact.isMyCard(deprecated)<sup>7+</sup>

isMyCard(id: number): Promise&lt;boolean&gt;

判断是否为“我的名片”，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[isMyCard](#contactismycard10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| id     | number | 是   | 名片对象的id属性。 |

**返回值：**

| 类型                   | 说明                                                       |
| ---------------------- | ---------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示是“我的名片”，返回false表示不是。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.isMyCard(/*id*/1);
  promise.then((data) => {
      console.info(`Succeeded in isMyCard. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to isMyCard. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryMyCard<sup>10+</sup>

queryMyCard(context: Context,  callback: AsyncCallback&lt;Contact&gt;): void

查询“我的名片”，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                  | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回“我的名片”信息；失败返回失败的错误码。     |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified. |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryMyCard(context, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query My Card. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying My Card. data->${JSON.stringify(data)}`);
  });
```

## contact.queryMyCard(deprecated)<sup>7+</sup>

queryMyCard(callback: AsyncCallback&lt;Contact&gt;): void

查询“我的名片”，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryMyCard](#contactquerymycard10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                     |
| -------- | ---------------------------------------- | ---- | -------------------------------------------------------- |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回“我的名片”信息；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryMyCard((err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query My Card. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying My Card. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryMyCard<sup>10+</sup>

queryMyCard(context: Context,  attrs: ContactAttributes, callback: AsyncCallback&lt;Contact&gt;): void

查询“我的名片”，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                  | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| attrs    | [ContactAttributes](#contactattributes)  | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回“我的名片”信息；失败返回失败的错误码。     |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryMyCard(context, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query My Card. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying My Card. data->${JSON.stringify(data)}`);
  });
```

## contact.queryMyCard(deprecated)<sup>7+</sup>

queryMyCard(attrs: ContactAttributes, callback: AsyncCallback&lt;Contact&gt;): void

查询“我的名片”，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryMyCard](#contactquerymycard10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                     |
| -------- | ---------------------------------------- | ---- | -------------------------------------------------------- |
| attrs    | [ContactAttributes](#contactattributes)  | 是   | 联系人的属性列表。                                       |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回“我的名片”信息；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryMyCard({
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query My Card. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying My Card. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryMyCard<sup>10+</sup>

queryMyCard(context: Context,  attrs?: ContactAttributes): Promise&lt;Contact&gt;

查询“我的名片”，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                                    | 必填 | 说明                                                         |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                                 | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| attrs   | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。                                           |

**返回值：**

| 类型                               | 说明                                    |
| ---------------------------------- | --------------------------------------- |
| Promise&lt;[Contact](#contact)&gt; | Promise对象。返回“我的名片”联系人对象。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.queryMyCard(context, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying My Card. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query My Card. Code: ${err.code}, message: ${err.message}`);
  });
```

## contact.queryMyCard(deprecated)<sup>7+</sup>

queryMyCard(attrs?: ContactAttributes): Promise&lt;Contact&gt;

查询“我的名片”，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryMyCard](#contactquerymycard10-2)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型                                    | 必填 | 说明               |
| ------ | --------------------------------------- | ---- | ------------------ |
| attrs  | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。 |

**返回值：**
| 类型                               | 说明                                    |
| ---------------------------------- | --------------------------------------- |
| Promise&lt;[Contact](#contact)&gt; | Promise对象。返回“我的名片”联系人对象。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.queryMyCard({
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying My Card. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query My Card. Code: ${err.code}, message: ${err.message}`);
  });
  ```


## contact.selectContact(deprecated)<sup>7+</sup>

selectContact(callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[selectContacts](#contactselectcontacts10)

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回选择的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.selectContact((err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to select Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in selecting Contact. data->${JSON.stringify(data)}`);
  });
  ```


## contact.selectContact(deprecated)<sup>7+</sup>

selectContact(): Promise&lt;Array&lt;Contact&gt;&gt;

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[selectContacts](#contactselectcontacts10-1)

**系统能力**：SystemCapability.Applications.Contacts

**返回值：**

| 类型                                            | 说明                                    |
| ----------------------------------------------- | --------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | Promise对象。返回选择的联系人数组对象。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.selectContact();
  promise.then((data) => {
      console.info(`Succeeded in selecting Contact. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to select Contact. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.selectContacts<sup>10+</sup>

selectContacts(callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用callback方式作为异步方法。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回选择的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified. |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.selectContacts((err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to select Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in selecting Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.selectContacts<sup>10+</sup>

selectContacts(): Promise&lt;Array&lt;Contact&gt;&gt;

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用Promise方式作为异步方法。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.Contacts

**返回值：**

| 类型                                            | 说明                                    |
| ----------------------------------------------- | --------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | Promise对象。返回选择的联系人数组对象。 |


**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.selectContacts();
  promise.then((data) => {
      console.info(`Succeeded in selecting Contacts. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to select Contacts. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.selectContacts<sup>10+</sup>

selectContacts(options: ContactSelectionOptions, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用callback方式作为异步方法。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| options | [ContactSelectionOptions](#contactselectionoptions10) | 是   | 选择联系人时的筛选条件 |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回选择的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.selectContacts({
    isMultiSelect:false
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to select Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in selecting Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.selectContacts<sup>10+</sup>

selectContacts(options: ContactSelectionOptions): Promise&lt;Array&lt;Contact&gt;&gt;

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用Promise方式作为异步方法。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| options | [ContactSelectionOptions](#contactselectionoptions10) | 是   | 选择联系人时的筛选条件 |

**返回值：**

| 类型                                            | 说明                                    |
| ----------------------------------------------- | --------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | Promise对象。返回选择的联系人数组对象。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.selectContacts({isMultiSelect:false});
  promise.then((data) => {
      console.info(`Succeeded in selecting Contacts. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to select Contacts. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryContact<sup>10+</sup>

queryContact(context: Context,  key: string,  callback: AsyncCallback&lt;Contact&gt;): void

根据key查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                  | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。                       |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回查询的联系人对象；失败返回失败的错误码。   |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContact(context, 'xxx', (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContact(deprecated)<sup>7+</sup>

queryContact(key: string,  callback: AsyncCallback&lt;Contact&gt;): void

根据key查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContact](#contactquerycontact10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------------------------- |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。                     |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回查询的联系人对象；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContact('xxx', (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContact<sup>10+</sup>

queryContact(context: Context,  key: string, holder: Holder, callback: AsyncCallback&lt;Contact&gt;): void

根据key和holder查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                  | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。                       |
| holder   | [Holder](#holder)                        | 是   | 创建联系人的应用信息。                                       |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回查询的联系人对象；失败返回失败的错误码。   |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContact(context, 'xxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContact(deprecated)<sup>7+</sup>

queryContact(key: string, holder: Holder, callback: AsyncCallback&lt;Contact&gt;): void

根据key和holder查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContact](#contactquerycontact10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------------------------- |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。                     |
| holder   | [Holder](#holder)                        | 是   | 创建联系人的应用信息。                                     |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回查询的联系人对象；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContact('xxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContact<sup>10+</sup>

queryContact(context: Context,  key: string,  attrs: ContactAttributes, callback: AsyncCallback&lt;Contact&gt;): void

根据key和attrs查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                  | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。                       |
| attrs    | [ContactAttributes](#contactattributes)  | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回查询的联系人对象；失败返回失败的错误码。   |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContact(context, 'xxx', {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContact(deprecated)<sup>7+</sup>

queryContact(key: string,  attrs: ContactAttributes, callback: AsyncCallback&lt;Contact&gt;): void

根据key和attrs查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContact](#contactquerycontact10-2)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------------------------- |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。                     |
| attrs    | [ContactAttributes](#contactattributes)  | 是   | 联系人的属性列表。                                         |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回查询的联系人对象；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContact('xxx', {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContact<sup>10+</sup>

queryContact(context: Context,  key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Contact&gt;): void

根据key、holder和attrs查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                  | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。                       |
| holder   | [Holder](#holder)                        | 是   | 创建联系人的应用信息。                                       |
| attrs    | [ContactAttributes](#contactattributes)  | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回查询的联系人对象；失败返回失败的错误码。   |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContact(context, 'xxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  });
```

## contact.queryContact(deprecated)<sup>7+</sup>

queryContact(key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Contact&gt;): void

根据key、holder和attrs查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContact](#contactquerycontact10-3)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------------------------- |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。                     |
| holder   | [Holder](#holder)                        | 是   | 创建联系人的应用信息。                                     |
| attrs    | [ContactAttributes](#contactattributes)  | 是   | 联系人的属性列表。                                         |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数。成功返回查询的联系人对象；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContact('xxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContact<sup>10+</sup>

queryContact(context: Context,  key: string, holder?: Holder, attrs?: ContactAttributes): Promise&lt;Contact&gt;

根据key、holder和attrs查询联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                                    | 必填 | 说明                                                         |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                                 | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| key     | string                                  | 是   | 联系人的key值，一个联系人对应一个key。                       |
| holder  | [Holder](#holder)                       | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。       |
| attrs   | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表，不传默认查询所有联系人属性。           |

**返回值：**
| 类型                               | 说明                                  |
| ---------------------------------- | ------------------------------------- |
| Promise&lt;[Contact](#contact)&gt; | Promise对象。返回查询到的联系人对象。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.queryContact(context, 'xxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryContact(deprecated)<sup>7+</sup>

queryContact(key: string, holder?: Holder, attrs?: ContactAttributes): Promise&lt;Contact&gt;

根据key、holder和attrs查询联系人，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContact](#contactquerycontact10-4)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                                   |
| ------ | --------------------------------------- | ---- | -------------------------------------- |
| key    | string                                  | 是   | 联系人的key值，一个联系人对应一个key。 |
| holder | [Holder](#holder)                       | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。                |
| attrs  | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表，不传默认查询所有联系人属性。                    |

**返回值：**
| 类型                               | 说明                                  |
| ---------------------------------- | ------------------------------------- |
| Promise&lt;[Contact](#contact)&gt; | Promise对象。返回查询到的联系人对象。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.queryContact('xxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Contact. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Contact. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryContacts<sup>10+</sup>

queryContacts(context: Context,  callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

查询所有联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContacts(context, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContacts(deprecated)<sup>7+</sup>

queryContacts(callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

查询所有联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContacts](#contactquerycontacts10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContacts((err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContacts<sup>10+</sup>

queryContacts(context: Context,  holder: Holder, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据holder查询所有联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContacts(context, {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContacts(deprecated)<sup>7+</sup>

queryContacts(holder: Holder, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据holder查询所有联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContacts](#contactquerycontacts10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContacts({
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContacts<sup>10+</sup>

queryContacts(context: Context,  attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据attrs查询所有联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContacts(context, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContacts(deprecated)<sup>7+</sup>

queryContacts(attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据attrs查询所有联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContacts](#contactquerycontacts10-2)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContacts({
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContacts<sup>10+</sup>

queryContacts(context: Context,  holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据holder和attrs查询所有联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContacts(context, {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContacts(deprecated)<sup>7+</sup>

queryContacts(holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据holder和attrs查询所有联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContacts](#contactquerycontacts10-3)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContacts({
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContacts<sup>10+</sup>

queryContacts(context: Context,  holder?: Holder, attrs?: ContactAttributes): Promise&lt;Array&lt;Contact&gt;&gt;

根据holder和attrs查询所有联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                                    | 必填 | 说明                                                         |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                                 | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| holder  | [Holder](#holder)                       | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。       |
| attrs   | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表，不传默认查询所有联系人属性。               |

**返回值：**
| 类型                                            | 说明                                      |
| ----------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | Promise对象。返回查询到的联系人数组对象。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.queryContacts(context, {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Contacts. data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryContacts(deprecated)<sup>7+</sup>

queryContacts(holder?: Holder, attrs?: ContactAttributes): Promise&lt;Array&lt;Contact&gt;&gt;

根据holder和attrs查询所有联系人，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContacts](#contactquerycontacts10-4)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                   |
| ------ | --------------------------------------- | ---- | ---------------------- |
| holder | [Holder](#holder)                       | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。 |
| attrs  | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表，不传默认查询所有联系人属性。     |

**返回值：**

| 类型                                            | 说明                                      |
| ----------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | Promise对象。返回查询到的联系人数组对象。 |

**示例：**

```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.queryContacts({
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Contacts. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Contacts. Code: ${err.code}, message: ${err.message}`);
  });
```

## contact.queryContactsByPhoneNumber<sup>10+</sup>

queryContactsByPhoneNumber(context: Context,  phoneNumber: string, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                                         |
| ----------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context     | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                                           |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContactsByPhoneNumber(context, '138xxxxxxxx', (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByPhoneNumber(deprecated)<sup>7+</sup>

queryContactsByPhoneNumber(phoneNumber: string, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByPhoneNumber](#contactquerycontactsbyphonenumber10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                                         |
| ----------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                                           |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContactsByPhoneNumber('138xxxxxxxx', (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContactsByPhoneNumber<sup>10+</sup>

queryContactsByPhoneNumber(context: Context,  phoneNumber: string, holder: Holder, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码和holder查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                                         |
| ----------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context     | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                                           |
| holder      | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContactsByPhoneNumber(context, '138xxxxxxxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByPhoneNumber(deprecated)<sup>7+</sup>

queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码和holder查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByPhoneNumber](#contactquerycontactsbyphonenumber10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                                         |
| ----------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                                           |
| holder      | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContactsByPhoneNumber('138xxxxxxxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByPhoneNumber<sup>10+</sup>

queryContactsByPhoneNumber(context: Context,  phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码和attrs查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                                         |
| ----------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context     | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                                           |
| attrs       | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContactsByPhoneNumber(context, '138xxxxxxxx', {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByPhoneNumber(deprecated)<sup>7+</sup>

queryContactsByPhoneNumber(phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码和attrs查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByPhoneNumber](#contactquerycontactsbyphonenumber10-2)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                                         |
| ----------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                                           |
| attrs       | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContactsByPhoneNumber('138xxxxxxxx', {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByPhoneNumber<sup>10+</sup>

queryContactsByPhoneNumber(context: Context,  phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码、holder和attrs查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                                         |
| ----------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context     | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                                           |
| holder      | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| attrs       | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContactsByPhoneNumber(context, '138xxxxxxxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByPhoneNumber(deprecated)<sup>7+</sup>

queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码、holder和attrs查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByPhoneNumber](#contactquerycontactsbyphonenumber10-3)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                                         |
| ----------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                                           |
| holder      | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| attrs       | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContactsByPhoneNumber('138xxxxxxxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByPhoneNumber<sup>10+</sup>

queryContactsByPhoneNumber(context: Context,  phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise&lt;Array&lt;Contact&gt;&gt;

根据电话号码、holder和attrs查询联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                    | 必填 | 说明                                                         |
| ----------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context     | Context                                 | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| phoneNumber | string                                  | 是   | 联系人的电话号码。                                           |
| holder      | [Holder](#holder)                       | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。       |
| attrs       | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表，不传默认查询所有联系人属性。               |

**返回值：**

| 类型                                            | 说明                                      |
| ----------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | Promise对象。返回查询到的联系人数组对象。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.queryContactsByPhoneNumber(context, '138xxxxxxxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryContactsByPhoneNumber(deprecated)<sup>7+</sup>

queryContactsByPhoneNumber(phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise&lt;Array&lt;Contact&gt;&gt;

根据电话号码、holder和attrs查询联系人，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByPhoneNumber](#contactquerycontactsbyphonenumber10-4)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                    | 必填 | 说明                   |
| ----------- | --------------------------------------- | ---- | ---------------------- |
| phoneNumber | string                                  | 是   | 联系人的电话号码。     |
| holder      | [Holder](#holder)                       | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。 |
| attrs       | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表，不传默认查询所有联系人属性。     |

**返回值：**

| 类型                                            | 说明                                      |
| ----------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | Promise对象。返回查询到的联系人数组对象。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.queryContactsByPhoneNumber('138xxxxxxxx', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Contacts By PhoneNumber. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Contacts By PhoneNumber. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryContactsByEmail<sup>10+</sup>

queryContactsByEmail(context: Context,  email: string, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| email    | string                                                | 是   | 联系人的邮箱地址。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContactsByEmail(context, 'xxx@email.com', (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByEmail(deprecated)<sup>7+</sup>

queryContactsByEmail(email: string, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByEmail](#contactquerycontactsbyemail10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| email    | string                                                | 是   | 联系人的邮箱地址。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContactsByEmail('xxx@email.com', (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByEmail<sup>10+</sup>

queryContactsByEmail(context: Context,  email: string, holder: Holder, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email和holder查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| email    | string                                                | 是   | 联系人的邮箱地址。                                           |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContactsByEmail(context, 'xxx@email.com', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByEmail(deprecated)<sup>7+</sup>

queryContactsByEmail(email: string, holder: Holder, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email和holder查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByEmail](#contactquerycontactsbyemail10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| email    | string                                                | 是   | 联系人的邮箱地址。                                           |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContactsByEmail('xxx@email.com', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByEmail<sup>10+</sup>

queryContactsByEmail(context: Context,  email: string, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email和attrs查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| email    | string                                                | 是   | 联系人的邮箱地址。                                           |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContactsByEmail(context, 'xxx@email.com', {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByEmail(deprecated)<sup>7+</sup>

queryContactsByEmail(email: string, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email和attrs查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByEmail](#contactquerycontactsbyemail10-2)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| email    | string                                                | 是   | 联系人的邮箱地址。                                           |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContactsByEmail('xxx@email.com', {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByEmail<sup>10+</sup>

queryContactsByEmail(context: Context,  email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email、holder和attrs查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                               | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| email    | string                                                | 是   | 联系人的邮箱地址。                                           |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryContactsByEmail(context, 'xxx@email.com', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByEmail(deprecated)<sup>7+</sup>

queryContactsByEmail(email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email、holder和attrs查询联系人，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByEmail](#contactquerycontactsbyemail10-3)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| email    | string                                                | 是   | 联系人的邮箱地址。                                           |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                                       |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                                           |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数。成功返回查询到的联系人对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryContactsByEmail('xxx@email.com', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryContactsByEmail<sup>10+</sup>

queryContactsByEmail(context: Context,  email: string, holder?: Holder, attrs?: ContactAttributes): Promise&lt;Array&lt;Contact&gt;&gt;

根据email、holder和attrs查询联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                                    | 必填 | 说明                                                         |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                                 | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| email   | string                                  | 是   | 联系人的邮箱地址。                                           |
| holder  | [Holder](#holder)                       | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。                                       |
| attrs   | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表，不传默认查询所有联系人属性。                                           |

**返回值：**

| 类型                                            | 说明                                      |
| ----------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | Promise对象。返回查询到的联系人数组对象。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.queryContactsByEmail(context, 'xxx@email.com', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryContactsByEmail(deprecated)<sup>7+</sup>

queryContactsByEmail(email: string, holder?: Holder, attrs?: ContactAttributes): Promise&lt;Array&lt;Contact&gt;&gt;

根据email、holder和attrs查询联系人，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryContactsByEmail](#contactquerycontactsbyemail10-4)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                   |
| ------ | --------------------------------------- | ---- | ---------------------- |
| email  | string                                  | 是   | 联系人的邮箱地址。     |
| holder | [Holder](#holder)                       | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。 |
| attrs  | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表，不传默认查询所有联系人属性。     |

**返回值：**

| 类型                                            | 说明                                      |
| ----------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | Promise对象。返回查询到的联系人数组对象。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.queryContactsByEmail('xxx@email.com', {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Contacts By Email. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Contacts By Email. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryGroups<sup>10+</sup>

queryGroups(context: Context,  callback: AsyncCallback&lt;Array&lt;Group&gt;&gt;): void

查询联系人的所有群组，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                           | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| callback | AsyncCallback&lt;Array&lt;[Group](#group)&gt;&gt; | 是   | 回调函数。成功返回查询到的群组对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryGroups(context, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Groups. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Groups. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryGroups(deprecated)<sup>7+</sup>

queryGroups(callback: AsyncCallback&lt;Array&lt;Group&gt;&gt;): void

查询联系人的所有群组，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryGroups](#contactquerygroups10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;[Group](#group)&gt;&gt; | 是   | 回调函数。成功返回查询到的群组对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryGroups((err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Groups. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Groups.. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryGroups<sup>10+</sup>

queryGroups(context: Context,  holder: Holder, callback: AsyncCallback&lt;Array&lt;Group&gt;&gt;): void

根据holder查询联系人的所有群组，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                           | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| holder   | [Holder](#holder)                                 | 是   | 创建联系人的应用信息。                                       |
| callback | AsyncCallback&lt;Array&lt;[Group](#group)&gt;&gt; | 是   | 回调函数。成功返回查询到的群组对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryGroups(context, {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Groups. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Groups. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryGroups(deprecated)<sup>7+</sup>

queryGroups(holder: Holder, callback: AsyncCallback&lt;Array&lt;Group&gt;&gt;): void

根据holder查询联系人的所有群组，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryGroups](#contactquerygroups10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| holder   | [Holder](#holder)                                 | 是   | 创建联系人的应用信息。                                       |
| callback | AsyncCallback&lt;Array&lt;[Group](#group)&gt;&gt; | 是   | 回调函数。成功返回查询到的群组对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryGroups({
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Groups. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Groups. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryGroups<sup>10+</sup>

queryGroups(context: Context,  holder?: Holder): Promise&lt;Array&lt;Group&gt;&gt;

根据holder查询联系人的所有群组，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型              | 必填 | 说明                                                         |
| ------- | ----------------- | ---- | ------------------------------------------------------------ |
| context | Context           | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| holder  | [Holder](#holder) | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人群组。                                       |

**返回值：**

| 类型                                        | 说明                                    |
| ------------------------------------------- | --------------------------------------- |
| Promise&lt;Array&lt;[Group](#group)&gt;&gt; | Promise对象。返回查询到的群组对象数组。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.queryGroups(context, {
      holderId: 1,
      bundleName: "",
      displayName: ""
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Groups. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Groups. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryGroups(deprecated)<sup>7+</sup>

queryGroups(holder?: Holder): Promise&lt;Array&lt;Group&gt;&gt;

根据holder查询联系人的所有群组，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryGroups](#contactquerygroups10-2)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型              | 必填 | 说明                   |
| ------ | ----------------- | ---- | ---------------------- |
| holder | [Holder](#holder) | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人群组。 |

**返回值：**

| 类型                                        | 说明                                    |
| ------------------------------------------- | --------------------------------------- |
| Promise&lt;Array&lt;[Group](#group)&gt;&gt; | Promise对象。返回查询到的群组对象数组。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.queryGroups({
      holderId: 1,
      bundleName: "",
      displayName: ""
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Groups. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Groups. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryHolders<sup>10+</sup>

queryHolders(context: Context, callback: AsyncCallback&lt;Array&lt;Holder&gt;&gt;): void

查询所有创建联系人的应用信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                                         |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                             | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| callback | AsyncCallback&lt;Array&lt;[Holder](#holder)&gt;&gt; | 是   | 回调函数。成功返回查询到的创建联系人应用信息的对象数组；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryHolders(context, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Holders. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Holders. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryHolders(deprecated)<sup>7+</sup>

queryHolders(callback: AsyncCallback&lt;Array&lt;Holder&gt;&gt;): void

查询所有创建联系人的应用信息，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryHolders](#contactqueryholders10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                                         |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;[Holder](#holder)&gt;&gt; | 是   | 回调函数。成功返回查询到的创建联系人应用信息的对象数组；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryHolders((err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Holders. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Holders. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryHolders<sup>10+</sup>

queryHolders(context: Context): Promise&lt;Array&lt;Holder&gt;&gt;

查询所有创建联系人的应用信息，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |

**返回值：**

| 类型                                          | 说明                                                    |
| --------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Holder](#holder)&gt;&gt; | Promise对象。返回查询到的创建联系人应用信息的对象数组。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.queryHolders(context);
  promise.then((data) => {
      console.info(`Succeeded in querying Holders. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Holders. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryHolders(deprecated)<sup>7+</sup>

queryHolders(): Promise&lt;Array&lt;Holder&gt;&gt;

查询所有创建联系人的应用信息，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryHolders](#contactqueryholders10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**返回值：**

| 类型                                          | 说明                                                    |
| --------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Holder](#holder)&gt;&gt; | Promise对象。返回查询到的创建联系人应用信息的对象数组。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.queryHolders();
  promise.then((data) => {
      console.info(`Succeeded in querying Holders. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Holders. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryKey<sup>10+</sup>

queryKey(context: Context,  id: number, callback: AsyncCallback&lt;string&gt;): void

根据联系人的id查询联系人的key，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                     | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| id       | number                      | 是   | 联系人对象的id属性。                                         |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。成功返回查询到的联系人对应的key；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryKey(context, /*id*/1, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Key. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Key. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryKey(deprecated)<sup>7+</sup>

queryKey(id: number, callback: AsyncCallback&lt;string&gt;): void

根据联系人的id查询联系人的key，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryKey](#contactquerykey10)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| id       | number                      | 是   | 联系人对象的id属性。                                         |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。成功返回查询到的联系人对应的key；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryKey(/*id*/1, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Key. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Key. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryKey<sup>10+</sup>

queryKey(context: Context,  id: number, holder: Holder, callback: AsyncCallback&lt;string&gt;): void

根据联系人的id和holder查询联系人的key，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                     | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| id       | number                      | 是   | 联系人对象的id属性。                                         |
| holder   | [Holder](#holder)           | 是   | 创建联系人的应用信息。                                       |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。成功返回查询到的联系人对应的key；失败返回失败的错误码。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  contact.queryKey(context, /*id*/1, {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Key. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Key. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryKey(deprecated)<sup>7+</sup>

queryKey(id: number, holder: Holder, callback: AsyncCallback&lt;string&gt;): void

根据联系人的id和holder查询联系人的key，使用callback方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryKey](#contactquerykey10-1)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| id       | number                      | 是   | 联系人对象的id属性。                                         |
| holder   | [Holder](#holder)           | 是   | 创建联系人的应用信息。                                       |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。成功返回查询到的联系人对应的key；失败返回失败的错误码。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  contact.queryKey(/*id*/1, {
      holderId: 1,
      bundleName: "",
      displayName: ""
  }, (err: BusinessError, data) => {
      if (err) {
          console.error(`Failed to query Key. Code: ${err.code}, message: ${err.message}`);
          return;
      }
      console.info(`Succeeded in querying Key. data->${JSON.stringify(data)}`);
  });
  ```

## contact.queryKey<sup>10+</sup>

queryKey(context: Context,  id: number, holder?: Holder): Promise&lt;string&gt;

根据联系人的id和holder查询联系人的key，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型              | 必填 | 说明                                                         |
| ------- | ----------------- | ---- | ------------------------------------------------------------ |
| context | Context           | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| id      | number            | 是   | 联系人对象的id属性。                                         |
| holder  | [Holder](#holder) | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。                                       |

**返回值：**

| 类型                  | 说明                                       |
| --------------------- | ------------------------------------------ |
| Promise&lt;string&gt; | Promise对象。返回查询到的联系人对应的key。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.  |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  // 获取context
  let context = getContext(this) as Context;
  let promise = contact.queryKey(context, /*id*/1, {
      holderId: 1,
      bundleName: "",
      displayName: ""
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Key. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Key. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## contact.queryKey(deprecated)<sup>7+</sup>

queryKey(id: number, holder?: Holder): Promise&lt;string&gt;

根据联系人的id和holder查询联系人的key，使用Promise方式作为异步方法。

> **说明**
>
> 从API version 7 开始支持，从API 10 开始废弃，建议使用[queryKey](#contactquerykey10-2)

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型              | 必填 | 说明                   |
| ------ | ----------------- | ---- | ---------------------- |
| id     | number            | 是   | 联系人对象的id属性。   |
| holder | [Holder](#holder) | 否   | 创建联系人的应用信息，不传默认不使用该条件过滤联系人。 |

**返回值：**

| 类型                  | 说明                                       |
| --------------------- | ------------------------------------------ |
| Promise&lt;string&gt; | Promise对象。返回查询到的联系人对应的key。 |

**示例：**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  let promise = contact.queryKey(/*id*/1, {
      holderId: 1,
      bundleName: "",
      displayName: ""
  });
  promise.then((data) => {
      console.info(`Succeeded in querying Key. data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`Failed to query Key. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## ContactSelectionOptions<sup>10+</sup>

选择联系人条件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.Contacts

|                名称               |                  类型                 | 必填  |        说明      |
| --------------------------------- | ------------------------------------- | ---- | ---------------- |
| isMultiSelect <sup>10+</sup>         | boolean | 否   | 是否为多选     |



## Contact

联系人对象类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

### 常量

| 名称               | 值   | 说明             |
| ------------------ | ---- | ---------------- |
| INVALID_CONTACT_ID | -1   | 默认联系人的id。 |


### 属性

|       名称        |                   类型                  | 可读 | 可写 | 说明                                   |
| ----------------- | --------------------------------------- | ---- | ---- | -------------------------------------- |
| id                | number                                  | 是   | 否   | 联系人的id。                           |
| key               | string                                  | 是   | 否   | 联系人的key。                          |
| contactAttributes | [ContactAttributes](#contactattributes) | 是   | 是   | 联系人的属性列表。                     |
| emails            | [Email](#email)[]                       | 是   | 是   | 联系人的邮箱地址列表。                 |
| events            | [Event](#event)[]                       | 是   | 是   | 联系人的生日、周年纪念等重要日期列表。 |
| groups            | [Group](#group)[]                       | 是   | 是   | 联系人的群组列表。                     |
| imAddresses       | [ImAddress](#imaddress)[]               | 是   | 是   | 联系人的即时消息地址列表。             |
| phoneNumbers      | [PhoneNumber](#phonenumber)[]           | 是   | 是   | 联系人的电话号码列表。                 |
| portrait          | [Portrait](#portrait)                   | 是   | 是   | 联系人的头像。                         |
| postalAddresses   | [PostalAddress](#postaladdress)[]       | 是   | 是   | 联系人的邮政地址列表。                 |
| relations         | [Relation](#relation)[]                 | 是   | 是   | 联系人的关系列表。                     |
| sipAddresses      | [SipAddress](#sipaddress)[]             | 是   | 是   | 联系人的会话发起协议（SIP）地址列表。  |
| websites          | [Website](#website)[]                   | 是   | 是   | 联系人的网站列表。                     |
| name              | [Name](#name)                           | 是   | 是   | 联系人的姓名。                         |
| note              | [Note](#note)                           | 是   | 是   | 联系人的备注。                         |
| organization      | [Organization](#organization)           | 是   | 是   | 联系人的组织信息。                     |


**对象创建示例：**

使用JSON格式创建联系人数据：


```js
let myContact: contact.Contact = {
    phoneNumbers: [{
        phoneNumber: "138xxxxxxxx"
    }],
    name: {
        fullName: "fullName",
        namePrefix: "namePrefix"
    }
};
```



## ContactAttributes

联系人属性列表，一般作为入参用来标识希望查询的联系人属性。
当传入为null时，默认查询全部属性。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称       |            类型           | 可读 | 可写 | 说明             |
| ---------- | ------------------------- | ---- | ---- | ---------------- |
| attributes | [Attribute](#attribute)[] | 是   | 是   | 联系人属性列表。 |


**对象创建示例：**

使用JSON格式创建数据：


```js
let contactAttributes: contact.ContactAttributes = {
    attributes: [
        contact.Attribute.ATTR_EMAIL,
        contact.Attribute.ATTR_NAME,
        contact.Attribute.ATTR_PHONE
    ]
};
```


## Attribute

枚举，联系人属性列表。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称                  | 说明                               |
| --------------------- | ---------------------------------- |
| ATTR_CONTACT_EVENT    | 联系人的生日、周年纪念等重要日期。 |
| ATTR_EMAIL            | 联系人的邮箱地址。                 |
| ATTR_GROUP_MEMBERSHIP | 联系人的群组。                     |
| ATTR_IM               | 联系人的即时消息地址。             |
| ATTR_NAME             | 联系人的姓名。                     |
| ATTR_NOTE             | 联系人的备注。                     |
| ATTR_ORGANIZATION     | 联系人的组织信息。                 |
| ATTR_PHONE            | 联系人的电话号码。                 |
| ATTR_PORTRAIT         | 联系人的头像。                     |
| ATTR_POSTAL_ADDRESS   | 联系人的邮政地址。                 |
| ATTR_RELATION         | 联系人的关系。                     |
| ATTR_SIP_ADDRESS      | 联系人的会话发起协议（SIP）地址。  |
| ATTR_WEBSITE          | 联系人的网站。                     |


**对象创建示例：**

使用JSON格式创建数据：

```js
let attributes = [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME, contact.Attribute.ATTR_PHONE];
```


## Email

联系人的邮箱。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

### 常量

| 名称             | 值   | 说明             |
| ---------------- | ---- | ---------------- |
| CUSTOM_LABEL     | 0    | 自定义邮箱类型。 |
| EMAIL_HOME       | 1    | 家庭邮箱类型。   |
| EMAIL_WORK       | 2    | 工作邮箱类型。   |
| EMAIL_OTHER      | 3    | 其它邮箱类型。   |
| INVALID_LABEL_ID | -1   | 无效邮箱类型。   |


### 属性

| 名称        |   类型   | 可读 | 可写 | 说明             |
| ----------- | -------- | ---- | ---- | ---------------- |
| email       | string   | 是   | 是   | 邮箱地址。       |
| labelName   | string   | 是   | 是   | 邮箱的类型名称。 |
| displayName | string   | 是   | 是   | 邮箱的显示名称。 |
| labelId     | number   | 是   | 是   | 邮箱的类型。     |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let email: contact.Email = {
    email: "xxx@email.com",
    displayName: "displayName"
}
```


  或使用new一个Email对象的方式创建数据：

```js
let email = new contact.Email();
email.email = "xxx@email.com";
```


## Holder

创建联系人的应用信息类。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称        | 类型   | 可读 | 可写 | 说明         |
| ----------- | ------ | ---- | ---- | ------------ |
| bundleName  | string | 是   | 否   | Bundle名称，值为com.ohos.contacts。 |
| displayName | string | 是   | 否   | 应用名称。   |
| holderId    | number | 是   | 是   | 应用ID。     |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let holder: contact.Holder = {
  bundleName: "com.ohos.contacts",
  displayName: "displayName",
  holderId: 1
};
```


## Event

联系人事件类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

### 常量

| 名称              | 值   | 说明               |
| ----------------- | ---- | ------------------ |
| CUSTOM_LABEL      | 0    | 自定义事件类型。   |
| EVENT_ANNIVERSARY | 1    | 周年纪念事件类型。 |
| EVENT_OTHER       | 2    | 其它事件类型。     |
| EVENT_BIRTHDAY    | 3    | 生日事件类型。     |
| INVALID_LABEL_ID  | -1   | 无效事件类型。     |


### 属性

|    名称   |   类型   | 可读 | 可写 | 说明           |
| --------- | -------- | ---- | ---- | -------------- |
| eventDate | string   | 是   | 是   | 事件的日期。   |
| labelName | string   | 是   | 是   | 事件类型名称。 |
| labelId   | number   | 是   | 是   | 事件类型。     |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let event: contact.Event = {
    eventDate: "xxxxxx"
};
```

  或使用new一个Event对象的方式创建数据：

```js
let event = new contact.Event();
event.eventDate = "xxxxxx";
```


## Group

联系人的群组类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称    |   类型   | 可读 | 可写 | 说明               |
| ------- | -------- | ---- | ---- | ------------------ |
| groupId | number   | 是   | 是   | 联系人群组的id。   |
| title   | string   | 是   | 是   | 联系人群组的名称。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let group: contact.Group = {
    groupId: 1,
    title: "title"
};
```


## ImAddress

联系人的即时消息地址。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

### 常量

| 名称             | 值   | 说明                 |
| ---------------- | ---- | -------------------- |
| CUSTOM_LABEL     | -1   | 自定义即时消息类型。 |
| IM_AIM           | 0    | AIM即时消息类型。    |
| IM_MSN           | 1    | MSN即时消息类型。    |
| IM_YAHOO         | 2    | YAHOO即时消息类型。  |
| IM_SKYPE         | 3    | SKYPE即时消息类型。  |
| IM_QQ            | 4    | QQ即时消息类型。     |
| IM_ICQ           | 6    | ICQ即时消息类型。    |
| IM_JABBER        | 7    | JABBER即时消息类型。 |
| INVALID_LABEL_ID | -2   | 无效的即时消息类型。 |


### 属性

| 名称      |   类型   | 可读 | 可写 | 说明               |
| --------- | -------- | ---- | ---- | ------------------ |
| imAddress | string   | 是   | 是   | 即时消息地址。     |
| labelName | string   | 是   | 是   | 即时消息类型名称。 |
| labelId   | number   | 是   | 是   | 即时消息类型。     |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let imAddress: contact.ImAddress = {
    imAddress: "imAddress",
    labelName: "labelName"
};
```


  或使用new一个ImAddress对象的方式创建数据：

```js
let imAddress = new contact.ImAddress();
imAddress.imAddress = "imAddress";
```


## Name

联系人的名字类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称               |   类型   | 可读 | 可写 | 说明                        |
| ------------------ | -------- | ---- | ---- | --------------------------- |
| familyName         | string   | 是   | 是   | 联系人的家庭姓名。          |
| familyNamePhonetic | string   | 是   | 是   | 联系人的家庭姓名拼音。      |
| fullName           | string   | 是   | 是   | 联系人的全名。              |
| givenName          | string   | 是   | 是   | 联系人的名称（firstName）。 |
| givenNamePhonetic  | string   | 是   | 是   | 联系人的名称拼音。          |
| middleName         | string   | 是   | 是   | 联系人的中间名。            |
| middleNamePhonetic | string   | 是   | 是   | 联系人的中间名拼音。        |
| namePrefix         | string   | 是   | 是   | 联系人的姓名前缀。          |
| nameSuffix         | string   | 是   | 是   | 联系人的姓名后缀。          |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let name: contact.Name = {
    familyName: "familyName",
    fullName: "fullName"
};
```


## Note

联系人的备注类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称        |   类型   | 可读 | 可写 | 说明               |
| ----------- | -------- | ---- | ---- | ------------------ |
| noteContent | string   | 是   | 是   | 联系人的备注内容。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let note: contact.Note = {
    noteContent: "noteContent"
};
```


## Organization

联系人的组织类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称  |   类型   | 可读 | 可写 | 说明       |
| ----- | -------- | ---- | ---- | ---------- |
| name  | string   | 是   | 是   | 单位名称。 |
| title | string   | 是   | 是   | 职位名称。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let organization: contact.Organization = {
    name: "name",
    title: "title"
};
```


## PhoneNumber

联系人电话号码类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

### 常量

| 名称             | 值   | 说明                                             |
| ---------------- | ---- | ------------------------------------------------ |
| CUSTOM_LABEL     | 0    | 自定义电话类型。                                 |
| NUM_HOME         | 1    | 家庭电话类型。                                   |
| NUM_MOBILE       | 2    | 移动电话类型。                                   |
| NUM_WORK         | 3    | 工作电话类型。                                   |
| NUM_FAX_WORK     | 4    | 工作传真电话类型。                               |
| NUM_FAX_HOME     | 5    | 家庭传真电话类型。                               |
| NUM_PAGER        | 6    | 寻呼机电话类型。                                 |
| NUM_OTHER        | 7    | 其它电话类型。                                   |
| INVALID_LABEL_ID | -1   | 无效电话类型。                                   |


### 属性

| 名称        |   类型   | 可读 | 可写 | 说明               |
| ----------- | -------- | ---- | ---- | ------------------ |
| labelName   | string   | 是   | 是   | 电话号码类型名称。 |
| phoneNumber | string   | 是   | 是   | 电话号码。         |
| labelId     | number   | 是   | 是   | 电话号码类型。     |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let phoneNumber: contact.PhoneNumber = {
    phoneNumber: "138xxxxxxxx",
    labelId: contact.PhoneNumber.NUM_HOME
};
```

  或使用new一个PhoneNumber对象的方式创建数据：

```js
let phoneNumber = new contact.PhoneNumber();
phoneNumber.phoneNumber = "138xxxxxxxx";
```


## Portrait

联系人的头像类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称 |   类型   | 可读 | 可写 | 说明           |
| ---- | -------- | ---- | ---- | -------------- |
| uri  | string   | 是   | 是   | 联系人的头像。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let portrait: contact.Portrait = {
    uri: "uri"
};
```


## PostalAddress

联系人的邮政地址类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

### 常量

| 名称             | 值   | 说明                 |
| ---------------- | ---- | -------------------- |
| CUSTOM_LABEL     | 0    | 自定义邮政地址类型。 |
| ADDR_HOME        | 1    | 家庭地址类型。       |
| ADDR_WORK        | 2    | 工作地址类型。       |
| ADDR_OTHER       | 3    | 其它地址类型。       |
| INVALID_LABEL_ID | -1   | 无效地址类型。       |


### 属性

| 名称          |   类型   | 可读 | 可写 | 说明                       |
| ------------- | -------- | ---- | ---- | -------------------------- |
| ------------- | -------- | ---- | ---- | -------------------------- |
| city          | string   | 是   | 是   | 联系人所在的城市。         |
| country       | string   | 是   | 是   | 联系人所在的国家。         |
| labelName     | string   | 是   | 是   | 邮政地址类型名称。         |
| neighborhood  | string   | 是   | 是   | 联系人的邻居。             |
| pobox         | string   | 是   | 是   | 联系人的邮箱。             |
| postalAddress | string   | 是   | 是   | 联系人的邮政地址。         |
| postcode      | string   | 是   | 是   | 联系人所在区域的邮政编码。 |
| region        | string   | 是   | 是   | 联系人所在的区域。         |
| street        | string   | 是   | 是   | 联系人所在的街道。         |
| labelId       | number   | 是   | 是   | 邮政地址类型。             |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let postalAddress: contact.PostalAddress = {
    city: "city",
    postalAddress: "postalAddress"
};
```

  或使用new一个PostalAddress对象的方式创建数据：

```js
let postalAddress = new contact.PostalAddress();
postalAddress.city = "city";
postalAddress.postalAddress = "postalAddress";
```


## Relation

联系人的关系类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

### 常量

| 名称                      | 值   | 说明               |
| ------------------------- | ---- | ------------------ |
| CUSTOM_LABEL              | 0    | 自定义关系类型。   |
| RELATION_ASSISTANT        | 1    | 助手关系类型。     |
| RELATION_BROTHER          | 2    | 兄弟关系类型。     |
| RELATION_CHILD            | 3    | 子女关系类型。     |
| RELATION_DOMESTIC_PARTNER | 4    | 同居同伴关系类型。 |
| RELATION_FATHER           | 5    | 父亲关系类型。     |
| RELATION_FRIEND           | 6    | 朋友关系类型。     |
| RELATION_MANAGER          | 7    | 管理者关系类型。   |
| RELATION_MOTHER           | 8    | 母亲关系类型。     |
| RELATION_PARENT           | 9    | 父母关系类型。     |
| RELATION_PARTNER          | 10   | 合作伙伴关系类型。 |
| RELATION_REFERRED_BY      | 11   | 推荐人关系类型。   |
| RELATION_RELATIVE         | 12   | 亲属关系类型。     |
| RELATION_SISTER           | 13   | 姐妹关系类型。     |
| RELATION_SPOUSE           | 14   | 配偶关系类型。     |
| INVALID_LABEL_ID          | -1   | 无效的关系类型。   |


### 属性

| 名称         |   类型   | 可读 | 可写 | 说明           |
| ------------ | -------- | ---- | ---- | -------------- |
| labelName    | string   | 是   | 是   | 关系类型名称。 |
| relationName | string   | 是   | 是   | 关系名称。     |
| labelId      | number   | 是   | 是   | 关系类型。     |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let relation: contact.Relation = {
    relationName: "relationName",
    labelId: contact.Relation.RELATION_ASSISTANT
};
```

  或使用new一个Relation对象的方式创建数据：

```js
let relation = new contact.Relation();
relation.relationName = "relationName";
relation.labelId = contact.Relation.RELATION_ASSISTANT;
```


## SipAddress

联系人的会话发起协议（SIP）地址类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

### 常量

| 名称             | 值   | 说明                                |
| ---------------- | ---- | ----------------------------------- |
| CUSTOM_LABEL     | 0    | 自定义会话发起协议（SIP）地址类型。 |
| SIP_HOME         | 1    | 家庭会话发起协议（SIP）地址类型。   |
| SIP_WORK         | 2    | 工作会话发起协议（SIP）地址类型。   |
| SIP_OTHER        | 3    | 其它会话发起协议（SIP）地址类型。   |
| INVALID_LABEL_ID | -1   | 无效会话发起协议（SIP）地址类型。   |


### 属性

| 名称       |   类型   | 可读 | 可写 | 说明                              |
| ---------- | -------- | ---- | ---- | --------------------------------- |
| labelName  | string   | 是   | 是   | 会话发起协议（SIP）地址类型名称。 |
| sipAddress | string   | 是   | 是   | 会话发起协议（SIP）地址。         |
| labelId    | number   | 是   | 是   | 会话发起协议（SIP）地址类型。     |

**对象创建示例：**

  使用JSON格式创建数据：

```js
let sipAddress: contact.SipAddress = {
    sipAddress: "sipAddress"
};
```

  或使用new一个SipAddress对象的方式创建数据：

```js
let sipAddress = new contact.SipAddress();
sipAddress.sipAddress = "sipAddress";
```


## Website

联系人的网站信息类。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称    |   类型   | 可读 | 可写 | 说明               |
| ------- | -------- | ---- | ---- | ------------------ |
| website | string   | 是   | 是   | 联系人的网站信息。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let website: contact.Website = {
    website: "website"
};
```

