# @ohos.contact (联系人)

本模块提供联系人管理能力，包括添加联系人、删除联系人、更新联系人等

>**说明：**
>
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import contact from '@ohos.contact';
```

## contact.addContact

addContact(contact:Contact, callback:AsyncCallback&lt;number&gt;): void

添加联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                        | 必填 | 说明                           |
| -------- | --------------------------- | ---- | ------------------------------ |
| contact  | [Contact](#contact)         | 是   | 联系人信息。                   |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回添加的联系人id。 |

**示例：**

  ```js
  contact.addContact({
      name: {fullName: 'xxx'},
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]
  }, (err, data) => {
      if (err) {
          console.log(`addContact callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`addContact callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.addContact

addContact(contact: Contact): Promise&lt;number&gt;

添加联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                | 必填 | 说明         |
| ------- | ------------------- | ---- | ------------ |
| contact | [Contact](#contact) | 是   | 联系人信息。 |

**返回值：**

| 类型                  | 说明                                        |
| --------------------- | ------------------------------------------- |
| Promise&lt;number&gt; | 以Promise形式返回结果，返回添加的联系人id。 |

**示例：**

  ```js
  let promise = contact.addContact({
      name: {fullName: 'xxx'},
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]
  });
  promise.then((data) => {
      console.log(`addContact success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`addContact fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.deleteContact

deleteContact(key: string, callback: AsyncCallback&lt;void&gt;): void

删除联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                 |
| -------- | ------------------------- | ---- | ------------------------------------ |
| key      | string                    | 是   | 联系人key值，一个联系人对应一个key。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，返回删除联系人的结果。     |

**示例：**

  ```js
  contact.deleteContact('xxx', (err) => {
      if (err) {
          console.log(`deleteContact callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log('deleteContact success');
  });
  ```


## contact.deleteContact

deleteContact(key: string): Promise&lt;void&gt;

删除联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| key    | string | 是   | 联系人的key值，一个联系人对应一个key。 |

**返回值：**

| 类型                | 说明                                          |
| ------------------- | --------------------------------------------- |
| Promise&lt;void&gt; | 以Promise形式返回结果，返回删除联系人的结果。 |

**示例：**

  ```js
  let promise = contact.deleteContact('xxx');
  promise.then(() => {
      console.log(`deleteContact success`);
  }).catch((err) => {
      console.error(`deleteContact fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.updateContact

updateContact(contact: Contact, callback: AsyncCallback&lt;void&gt;): void

更新联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                 |
| -------- | ------------------------- | ---- | ------------------------------------ |
| contact  | [Contact](#contact)       | 是   | 联系人信息。                         |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，返回更新联系人的更新结果。 |

**示例：**

  ```js
  contact.updateContact({
      name: {fullName: 'xxx'},
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]
  }, (err) => {
      if (err) {
          console.log('updateContact callback: err->${JSON.stringify(err)}');
          return;
      }
      console.log('updateContact success');
  });
  ```


## contact.updateContact

updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback&lt;void&gt;): void

更新联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                 |
| -------- | --------------------------------------- | ---- | ------------------------------------ |
| contact  | [Contact](#contact)                     | 是   | 联系人信息。                         |
| attrs    | [ContactAttributes](#contactattributes) | 是   | 联系人的属性列表。                   |
| callback | AsyncCallback&lt;void&gt;               | 是   | 回调函数，返回更新联系人的更新结果。 |

**示例：**

  ```js
  contact.updateContact({
      name: {fullName: 'xxx'},
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err) => {
      if (err) {
          console.log('updateContact callback: err->${JSON.stringify(err)}');
          return;
      }
      console.log('updateContact success');
  });
  ```


## contact.updateContact

updateContact(contact: Contact, attrs?: ContactAttributes): Promise&lt;void&gt;

更新联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名  | 类型                                    | 必填 | 说明               |
| ------- | --------------------------------------- | ---- | ------------------ |
| contact | [Contact](#contact)                     | 是   | 联系人信息。       |
| attrs   | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。 |

**返回值：**
| 类型                | 说明                                              |
| ------------------- | ------------------------------------------------- |
| Promise&lt;void&gt; | 以Promise形式返回结果，返回更新联系人的更新结果。 |

**示例：**

  ```js
  let promise = contact.updateContact({
      name: {fullName: 'xxx'},
      phoneNumbers: [{phoneNumber: '138xxxxxxxx'}]
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  });
  promise.then(() => {
      console.log('updateContact success');
  }).catch((err) => {
      console.error(`updateContact fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.isLocalContact

isLocalContact(id: number, callback: AsyncCallback&lt;boolean&gt;): void

判断当前联系人id是否在电话簿中，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| id       | number                       | 是   | 联系人对象的id属性，一个联系人对应一个id。                   |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回布尔值。true代表联系人id在本地电话簿中，false则代表联系人id不在本地电话簿中。 |

**示例：**

  ```js
  contact.isLocalContact(/*id*/1, (err, data) => {
      if (err) {
          console.log(`isLocalContact callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`isLocalContact callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.isLocalContact

isLocalContact(id: number): Promise&lt;boolean&gt;

判断当前联系人id是否在电话簿中，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                       |
| ------ | ------ | ---- | ------------------------------------------ |
| id     | number | 是   | 联系人对象的id属性，一个联系人对应一个id。 |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | 以Promise形式返回结果，返回布尔值。true代表联系人id在本地电话簿中，false则代表联系人id不在本地电话簿中。 |

**示例：**

  ```js
  let promise = contact.isLocalContact(/*id*/1);
  promise.then((data) => {
      console.log(`isLocalContact success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`isLocalContact fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.isMyCard

isMyCard(id: number, callback: AsyncCallback&lt;boolean&gt;): void

判断是否为“我的名片”，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| id       | number                       | 是   | 联系人对象的id属性。                                         |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回是否为“我的名片”的布尔值。true代表此联系人是“我的名片”，false则代表不是。 |

**示例：**

  ```js
  contact.isMyCard(/*id*/1, (err, data) => {
      if (err) {
          console.log(`isMyCard callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`isMyCard callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.isMyCard

isMyCard(id: number): Promise&lt;boolean&gt;

判断是否为“我的名片”，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| id     | number | 是   | 联系人对象的id属性。 |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | 以Promise形式返回结果，返回是否为“我的名片”的布尔值。true代表此联系人是“我的名片”，false则代表不是。 |

**示例：**

  ```js
  let promise = contact.isMyCard(/*id*/1);
  promise.then((data) => {
      console.log(`isMyCard success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`isMyCard fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.queryMyCard

queryMyCard(callback: AsyncCallback&lt;Contact&gt;): void

查询“我的名片”，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                           |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数，返回“我的名片”信息。 |

**示例：**

  ```js
  contact.queryMyCard((err, data) => {
      if (err) {
          console.log(`queryMyCard callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryMyCard callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryMyCard

queryMyCard(attrs: ContactAttributes, callback: AsyncCallback&lt;Contact&gt;): void

查询“我的名片”，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                           |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| attrs    | [ContactAttributes](#contactattributes)  | 是   | 联系人的属性列表。             |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数，返回“我的名片”信息。 |

**示例：**

  ```js
  contact.queryMyCard({
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err, data) => {
      if (err) {
          console.log(`queryMyCard callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryMyCard callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryMyCard

queryMyCard(attrs?: ContactAttributes): Promise&lt;Contact&gt;

查询“我的名片”，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型                                    | 必填 | 说明               |
| ------ | --------------------------------------- | ---- | ------------------ |
| attrs  | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。 |

**返回值：**
| 类型                               | 说明                                        |
| ---------------------------------- | ------------------------------------------- |
| Promise&lt;[Contact](#contact)&gt; | 以Promise形式返回结果，返回“我的名片”信息。 |

**示例：**

  ```js
  let promise = contact.queryMyCard({
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  });
  promise.then((data) => {
      console.log(`queryMyCard success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`queryMyCard fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.selectContact

selectContact(callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

选择联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回选择的联系人对象数组。 |

**示例：**

  ```js
  contact.selectContact((err, data) => {
      if (err) {
          console.log(`selectContact callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`selectContact callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.selectContact

selectContact(): Promise&lt;Array&lt;Contact&gt;&gt;

选择联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.Contacts

**返回值：**

| 类型                                            | 说明                                              |
| ----------------------------------------------- | ------------------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | 以Promise形式返回结果，返回选择的联系人对象数组。 |

**示例：**

  ```js
  let promise = contact.selectContact();
  promise.then((data) => {
      console.log(`selectContact success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`selectContact fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.queryContact

queryContact(key: string,  callback: AsyncCallback&lt;Contact&gt;): void

根据key查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                   |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。 |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数，返回查询的联系人对象。       |

**示例：**

  ```js
  contact.queryContact('xxx', (err, data) => {
      if (err) {
          console.log(`queryContact callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContact callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContact

queryContact(key: string, holder: Holder, callback: AsyncCallback&lt;Contact&gt;): void

根据key查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                   |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。 |
| holder   | [Holder](#holder)                        | 是   | 创建联系人的应用信息。                 |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数，返回查询的联系人对象。       |

**示例：**

  ```js
  contact.queryContact('xxx', {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, (err, data) => {
      if (err) {
          console.log(`queryContact callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContact callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContact

queryContact(key: string,  attrs: ContactAttributes, callback: AsyncCallback&lt;Contact&gt;): void

根据key查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                   |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。 |
| attrs    | [ContactAttributes](#contactattributes)  | 是   | 联系人的属性列表。                     |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数，返回查询的联系人对象。       |

**示例：**

  ```js
  contact.queryContact('xxx', {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err, data) => {
      if (err) {
          console.log(`queryContact callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContact callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContact

queryContact(key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Contact&gt;): void

根据key查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                   |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| key      | string                                   | 是   | 联系人的key值，一个联系人对应一个key。 |
| holder   | [Holder](#holder)                        | 是   | 创建联系人的应用信息。                 |
| attrs    | [ContactAttributes](#contactattributes)  | 是   | 联系人的属性列表。                     |
| callback | AsyncCallback&lt;[Contact](#contact)&gt; | 是   | 回调函数，返回查询的联系人对象。       |

**示例：**

  ```js
  contact.queryContact('xxx', {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err, data) => {
      if (err) {
          console.log(`queryContact callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContact callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContact

queryContact(key: string, holder?: Holder, attrs?: ContactAttributes): Promise&lt;Contact&gt;

根据key查询联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                                   |
| ------ | --------------------------------------- | ---- | -------------------------------------- |
| key    | string                                  | 是   | 联系人的key值，一个联系人对应一个key。 |
| holder | [Holder](#holder)                       | 否   | 创建联系人的应用信息。                 |
| attrs  | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。                     |

**返回值：**
| 类型                               | 说明                                            |
| ---------------------------------- | ----------------------------------------------- |
| Promise&lt;[Contact](#contact)&gt; | 以Promise形式返回结果，返回查询到的联系人对象。 |

**示例：**

  ```js
  let promise = contact.queryContact('xxx', {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  });
  promise.then((data) => {
      console.log(`queryContact success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`queryContact fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.queryContacts

queryContacts(callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

查询所有联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                   |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContacts((err, data) => {
      if (err) {
          console.log(`queryContacts callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContacts callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContacts

queryContacts(holder: Holder, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

查询所有联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                   |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                 |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContacts({
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, (err, data) => {
      if (err) {
          console.log(`queryContacts callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContacts callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContacts

queryContacts(attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

查询所有联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                   |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                     |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContacts({
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err, data) => {
      if (err) {
          console.log(`queryContacts callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContacts callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContacts

queryContacts(holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

查询所有联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                   |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                 |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                     |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContacts({
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err, data) => {
      if (err) {
          console.log(`queryContacts callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContacts callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContacts

queryContacts(holder?: Holder, attrs?: ContactAttributes): Promise&lt;Array&lt;Contact&gt;&gt;

查询所有联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                   |
| ------ | --------------------------------------- | ---- | ---------------------- |
| holder | [Holder](#holder)                       | 否   | 创建联系人的应用信息。 |
| attrs  | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。     |

**返回值：**
| 类型                                            | 说明                                                |
| ----------------------------------------------- | --------------------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | 以Promise形式返回结果，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  let promise = contact.queryContacts({
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  });
  promise.then((data) => {
      console.log(`queryContacts success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`queryContacts fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.queryContactsByPhoneNumber

queryContactsByPhoneNumber(phoneNumber: string, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                   |
| ----------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                     |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContactsByPhoneNumber('138xxxxxxxx', (err, data) => {
      if (err) {
          console.log(`queryContactsByPhoneNumber callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContactsByPhoneNumber callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContactsByPhoneNumber

queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                   |
| ----------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                     |
| holder      | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                 |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContactsByPhoneNumber('138xxxxxxxx', {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, (err, data) => {
      if (err) {
          console.log(`queryContactsByPhoneNumber callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContactsByPhoneNumber callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContactsByPhoneNumber

queryContactsByPhoneNumber(phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                   |
| ----------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                     |
| attrs       | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                     |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContactsByPhoneNumber('138xxxxxxxx', {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err, data) => {
      if (err) {
          console.log(`queryContactsByPhoneNumber callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContactsByPhoneNumber callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContactsByPhoneNumber

queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据电话号码查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                   |
| ----------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                                                | 是   | 联系人的电话号码。                     |
| holder      | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                 |
| attrs       | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                     |
| callback    | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContactsByPhoneNumber('138xxxxxxxx', {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err, data) => {
      if (err) {
          console.log(`queryContactsByPhoneNumber callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContactsByPhoneNumber callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContactsByPhoneNumber

queryContactsByPhoneNumber(phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise&lt;Array&lt;Contact&gt;&gt;

根据电话号码查询联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名      | 类型                                    | 必填 | 说明                   |
| ----------- | --------------------------------------- | ---- | ---------------------- |
| phoneNumber | string                                  | 是   | 联系人的电话号码。     |
| holder      | [Holder](#holder)                       | 否   | 创建联系人的应用信息。 |
| attrs       | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。     |

**返回值：**

| 类型                                            | 说明                                                |
| ----------------------------------------------- | --------------------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | 以Promise形式返回结果，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  let promise = contact.queryContactsByPhoneNumber('138xxxxxxxx', {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  });
  promise.then((data) => {
      console.log(`queryContactsByPhoneNumber success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`queryContactsByPhoneNumber fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.queryContactsByEmail

queryContactsByEmail(email: string, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                   |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| email    | string                                                | 是   | 联系人的邮箱地址。                     |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContactsByEmail('xxx@email.com', (err, data) => {
      if (err) {
          console.log(`queryContactsByEmail callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContactsByEmail callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContactsByEmail

queryContactsByEmail(email: string, holder: Holder, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                   |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| email    | string                                                | 是   | 联系人的邮箱地址。                     |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。                 |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  contact.queryContactsByEmail('xxx@email.com', {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, (err, data) => {
      if (err) {
          console.log(`queryContactsByEmail callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContactsByEmail callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContactsByEmail

queryContactsByEmail(email: string, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| email    | string                                                | 是   | 联系人的邮箱地址。                   |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                   |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到联系人对象数组。 |

**示例：**

  ```js
  contact.queryContactsByEmail('xxx@email.com', {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err, data) => {
      if (err) {
          console.log(`queryContactsByEmail callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContactsByEmail callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContactsByEmail

queryContactsByEmail(email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

根据email查询联系人，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| email    | string                                                | 是   | 联系人的邮箱地址。                   |
| holder   | [Holder](#holder)                                     | 是   | 创建联系人的应用信息。               |
| attrs    | [ContactAttributes](#contactattributes)               | 是   | 联系人的属性列表。                   |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回查询到联系人对象数组。 |

**示例：**

  ```js
  contact.queryContactsByEmail('xxx@email.com', {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  }, (err, data) => {
      if (err) {
          console.log(`queryContactsByEmail callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryContactsByEmail callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryContactsByEmail

queryContactsByEmail(email: string, holder?: Holder, attrs?: ContactAttributes): Promise&lt;Array&lt;Contact&gt;&gt;

根据email查询联系人，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                   |
| ------ | --------------------------------------- | ---- | ---------------------- |
| email  | string                                  | 是   | 联系人的邮箱地址。     |
| holder | [Holder](#holder)                       | 否   | 创建联系人的应用信息。 |
| attrs  | [ContactAttributes](#contactattributes) | 否   | 联系人的属性列表。     |

**返回值：**

| 类型                                            | 说明                                                |
| ----------------------------------------------- | --------------------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | 以Promise形式返回结果，返回查询到的联系人对象数组。 |

**示例：**

  ```js
  let promise = contact.queryContactsByEmail('xxx@email.com', {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, {
      attributes: [contact.Attribute.ATTR_EMAIL, contact.Attribute.ATTR_NAME]
  });
  promise.then((data) => {
      console.log(`queryContactsByEmail success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`queryContactsByEmail fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.queryGroups

queryGroups(callback: AsyncCallback&lt;Array&lt;Group&gt;&gt;): void

查询联系人的所有群组，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                 |
| -------- | ------------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;[Group](#group)&gt;&gt; | 是   | 回调函数，返回查询到的群组对象数组。 |

**示例：**

  ```js
  contact.queryGroups((err, data) => {
      if (err) {
          console.log(`queryGroups callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryGroups callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryGroups

queryGroups(holder: Holder, callback: AsyncCallback&lt;Array&lt;Group&gt;&gt;): void

查询联系人的所有群组，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                 |
| -------- | ------------------------------------------------- | ---- | ------------------------------------ |
| holder   | Holder                                            | 是   | 创建联系人的应用信息。               |
| callback | AsyncCallback&lt;Array&lt;[Group](#group)&gt;&gt; | 是   | 回调函数，返回查询到的群组对象数组。 |

**示例：**

  ```js
  contact.queryGroups({
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, (err, data) => {
      if (err) {
          console.log(`queryGroups callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryGroups callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryGroups

queryGroups(holder?: Holder): Promise&lt;Array&lt;Group&gt;&gt;

查询联系人的所有群组，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型              | 必填 | 说明                   |
| ------ | ----------------- | ---- | ---------------------- |
| holder | [Holder](#holder) | 否   | 创建联系人的应用信息。 |

**返回值：**

| 类型                                        | 说明                                              |
| ------------------------------------------- | ------------------------------------------------- |
| Promise&lt;Array&lt;[Group](#group)&gt;&gt; | 以Promise形式返回结果，返回查询到的群组对象数组。 |

**示例：**

  ```js
  let promise = contact.queryGroups({
      holderId: 0,
      bundleName: "",
      displayName: ""
  });
  promise.then((data) => {
      console.log(`queryGroups success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`queryGroups fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.queryHolders

queryHolders(callback: AsyncCallback&lt;Array&lt;Holder&gt;&gt;): void

查询所有创建联系人的应用信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                                 |
| -------- | --------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Holder](#holder)&gt;&gt; | 是   | 回调函数，返回查询到的创建联系人应用信息的对象数组。 |

**示例：**

  ```js
  contact.queryHolders((err, data) => {
      if (err) {
          console.log(`queryHolders callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryHolders callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryHolders

queryHolders(): Promise&lt;Array&lt;Holder&gt;&gt;

查询所有创建联系人的应用信息，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**返回值：**

| 类型                                          | 说明                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[Holder](#holder)&gt;&gt; | 以Promise形式返回结果，返回查询到的创建联系人应用信息的对象数组。 |

**示例：**

  ```js
  let promise = contact.queryHolders();
  promise.then((data) => {
      console.log(`queryHolders success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`queryHolders fail: err->${JSON.stringify(err)}`);
  });
  ```


## contact.queryKey

queryKey(id: number, callback: AsyncCallback&lt;string&gt;): void

根据联系人的id查询联系人的key，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                    |
| -------- | --------------------------- | ---- | --------------------------------------- |
| id       | number                      | 是   | 联系人对象的id属性。                    |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回查询到的联系人对应的key。 |

**示例：**

  ```js
  contact.queryKey(/*id*/1, (err, data) => {
      if (err) {
          console.log(`queryKey callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryKey callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryKey

queryKey(id: number, holder: Holder, callback: AsyncCallback&lt;string&gt;): void

根据联系人的id查询联系人的key，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                    |
| -------- | --------------------------- | ---- | --------------------------------------- |
| id       | number                      | 是   | 联系人对象的id属性。                    |
| holder   | [Holder](#holder)           | 是   | 创建联系人的应用信息。                  |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回查询到的联系人对应的key。 |

**示例：**

  ```js
  contact.queryKey(/*id*/1, {
      holderId: 0,
      bundleName: "",
      displayName: ""
  }, (err, data) => {
      if (err) {
          console.log(`queryKey callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`queryKey callback: success data->${JSON.stringify(data)}`);
  });
  ```


## contact.queryKey

queryKey(id: number, holder?: Holder): Promise&lt;string&gt;

根据联系人的id查询联系人的key，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Applications.ContactsData

**参数：**

| 参数名 | 类型              | 必填 | 说明                   |
| ------ | ----------------- | ---- | ---------------------- |
| id     | number            | 是   | 联系人对象的id属性。   |
| holder | [Holder](#holder) | 否   | 创建联系人的应用信息。 |

**返回值：**

| 类型                  | 说明                                                 |
| --------------------- | ---------------------------------------------------- |
| Promise&lt;string&gt; | 以Promise形式返回结果，返回查询到的联系人对应的key。 |

**示例：**

  ```js
  let promise = contact.queryKey(/*id*/1, {
      holderId: 0,
      bundleName: "",
      displayName: ""
  });
  promise.then((data) => {
      console.log(`queryKey success: data->${JSON.stringify(data)}`);
  }).catch((err) => {
      console.error(`queryKey fail: err->${JSON.stringify(err)}`);
  });
  ```


## Contact

联系人对象类。

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
| nickName          | [NickName](#nickname)                   | 是   | 是   | 联系人的昵称。                         |
| note              | [Note](#note)                           | 是   | 是   | 联系人的备注。                         |
| organization      | [Organization](#organization)           | 是   | 是   | 联系人的组织信息。                     |


**对象创建示例：**

使用JSON格式创建联系人数据：


```js
let myContact = {
    phoneNumbers: [{
        phoneNumber: "138xxxxxxxx"
    }],
    name: {
        fullName: "fullName",
        namePrefix: "namePrefix"
    },
    nickName: {
        nickName: "nickName"
    }
};
```


  或使用new一个Contact对象的方式创建数据：

```js
let myContact = new contact.Contact();
let name = new contact.Name();
name.fullName = "fullName";
let phoneNumber = new contact.PhoneNumber();
phoneNumber.phoneNumber = "138xxxxxxxx";
myContact.name = name;
myContact.phoneNumbers = [phoneNumber];
```


## ContactAttributes

联系人属性列表，一般作为入参用来标识希望查询的联系人属性。
当传入为null时，默认查询全部属性。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称       |            类型           | 可读 | 可写 | 说明             |
| ---------- | ------------------------- | ---- | ---- | ---------------- |
| attributes | [Attribute](#attribute)[] | 是   | 是   | 联系人属性列表。 |


**对象创建示例：**

使用JSON格式创建数据：


```js
let contactAttributes = {
    attributes: [
        contact.Attribute.ATTR_EMAIL,
        contact.Attribute.ATTR_NAME,
        contact.Attribute.ATTR_PHONE
    ]
};
```

或使用new一个ContactAttributes对象的方式创建数据：


```js
let contactAttributes = new contact.ContactAttributes();
contactAttributes.attributes = [contact.Attribute.ATTR_EMAIL];
```


## Attribute

枚举，联系人属性列表。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称                  | 说明                               |
| --------------------- | ---------------------------------- |
| ATTR_CONTACT_EVENT    | 联系人的生日、周年纪念等重要日期。 |
| ATTR_EMAIL            | 联系人的邮箱地址。                 |
| ATTR_GROUP_MEMBERSHIP | 联系人的群组。                     |
| ATTR_IM               | 联系人的即时消息地址。             |
| ATTR_NAME             | 联系人的姓名。                     |
| ATTR_NICKNAME         | 联系人的昵称。                     |
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
let email = {
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
| bundleName  | string | 是   | 否   | Bundle名称。 |
| displayName | string | 是   | 否   | 应用名称。   |
| holderId    | number | 是   | 是   | 应用ID。     |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let holder = {
  holderId: 0
};
```

  或使用new一个Holder对象的方式创建数据：

```js
let holder = new contact.Holder();
holder.holderId = 0;
```


## Event

联系人事件类。

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
let event = {
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

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称    |   类型   | 可读 | 可写 | 说明               |
| ------- | -------- | ---- | ---- | ------------------ |
| groupId | number   | 是   | 是   | 联系人群组的id。   |
| title   | string   | 是   | 是   | 联系人群组的名称。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let group = {
    groupId: 1,
    title: "title"
};
```

  或使用new一个Group对象的方式创建数据：

```js
let group = new contact.Group();
group.title = "title";
```


## ImAddress

联系人的即时消息地址。

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
let imAddress = {
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
let name = {
    familyName: "familyName",
    fullName: "fullName"
};
```

  或使用new一个name对象的方式创建数据：

```js
let name = new contact.Name();
name.familyName = "familyName";
name.fullName = "fullName";
```


## NickName

联系人的昵称类。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称     |   类型   | 可读 | 可写 | 说明           |
| -------- | -------- | ---- | ---- | -------------- |
| nickName | string   | 是   | 是   | 联系人的昵称。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let nickName = {
    nickName: "nickName"
};
```

  或使用new一个NickName对象的方式创建数据：

```js
let nickName = new contact.NickName();
nickName.nickName = "nickName";
```


## Note

联系人的备注类。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称        |   类型   | 可读 | 可写 | 说明               |
| ----------- | -------- | ---- | ---- | ------------------ |
| noteContent | string   | 是   | 是   | 联系人的备注内容。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let note = {
    noteContent: "noteContent"
};
```

  或使用new一个Note对象的方式创建数据：

```js
let note = new contact.Note();
note.noteContent = "noteContent";
```


## Organization

联系人的组织类。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称  |   类型   | 可读 | 可写 | 说明       |
| ----- | -------- | ---- | ---- | ---------- |
| name  | string   | 是   | 是   | 组织名称。 |
| title | string   | 是   | 是   | 组织标题。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let organization = {
    name: "name",
    title: "title"
};
```

  或使用new一个Organization对象的方式创建数据：

```js
let organization = new contact.Organization();
organization.name = "name";
organization.title = "title";
```


## PhoneNumber

联系人电话号码类。

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
| NUM_CALLBACK     | 8    | 回呼电话类型。                                   |
| NUM_CAR          | 9    | 车机电话类型。                                   |
| NUM_COMPANY_MAIN | 10   | 公司电话类型。                                   |
| NUM_ISDN         | 11   | 综合业务数字网（ISDN）电话类型。                 |
| NUM_MAIN         | 12   | 主电话类型。                                     |
| NUM_OTHER_FAX    | 13   | 其它传真类型。                                   |
| NUM_RADIO        | 14   | 无线电话类型。                                   |
| NUM_TELEX        | 15   | 电传电话类型。                                   |
| NUM_TTY_TDD      | 16   | 电传打字机（TTY）或测试驱动开发（TDD）电话类型。 |
| NUM_WORK_MOBILE  | 17   | 工作移动电话类型。                               |
| NUM_WORK_PAGER   | 18   | 工作寻呼机电话类型。                             |
| NUM_ASSISTANT    | 19   | 助理电话类型。                                   |
| NUM_MMS          | 20   | 彩信电话类型。                                   |
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
let phoneNumber = {
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

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称 |   类型   | 可读 | 可写 | 说明           |
| ---- | -------- | ---- | ---- | -------------- |
| uri  | string   | 是   | 是   | 联系人的头像。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let portrait = {
    uri: "uri"
};
```

  或使用new一个Portrait对象的方式创建数据：

```js
let portrait = new contact.Portrait();
portrait.uri = "uri";
```


## PostalAddress

联系人的邮政地址类。

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
| city          | string   | 是   | 是   | 联系人所在的城市。         |
| country       | string   | 是   | 是   | 联系人所在的国家。         |
| labelName     | string   | 是   | 是   | 邮政地址类型名称。         |
| neighborhood  | string   | 是   | 是   | 联系人的邻居。             |
| pobox         | string   | 是   | 是   | 联系人的邮箱。             |
| postalAddress | string   | 是   | 是   | 联系人的邮政地址。         |
| postcode      | string   | 是   | 是   | 联系人所在区域的邮政编码。 |
| region        | string   | 是   | 是   | 联系人所在的区域。         |
| street        | string   | 是   | 是   | 联系人所在的街道。         |
| labelId       | number   | 是   | 是   | 邮政地址名称。             |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let postalAddress = {
    city: "city"
};
```

  或使用new一个PostalAddress对象的方式创建数据：

```js
let postalAddress = new contact.PostalAddress();
postalAddress.city = "city";
```


## Relation

联系人的关系类。

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
let relation = {
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
var sipAddress = {
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

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称    |   类型   | 可读 | 可写 | 说明               |
| ------- | -------- | ---- | ---- | ------------------ |
| website | string   | 是   | 是   | 联系人的网站信息。 |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let website = {
    website: "website"
};
```

  或使用new一个Website对象的方式创建数据：

```js
let website = new contact.Website();
website.website = "website";
```
