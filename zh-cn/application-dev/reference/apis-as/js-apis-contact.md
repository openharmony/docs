# @ohos.contact (联系人)

本模块提供选择联系人的功能。

>**说明：**
>
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import contact from '@ohos.contact';
```


## contact.selectContacts<sup>10+</sup>

selectContacts(callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用callback方式作为异步方法。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回选择的联系人对象数组。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401      | Parameter error.   |

**示例：**

  ```js
  import { BusinessError } from '@ohos.base';
  contact.selectContacts((err: BusinessError, data) => {
      if (err) {
          console.log(`selectContact callback: err->${JSON.stringify(err)}`);
          return;
      }
      console.log(`selectContact callback: success data->${JSON.stringify(data)}`);
  });
  ```

## contact.selectContacts<sup>10+</sup>

selectContacts(): Promise&lt;Array&lt;Contact&gt;&gt;

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Applications.Contacts

**返回值：**

| 类型                                            | 说明                                              |
| ----------------------------------------------- | ------------------------------------------------- |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | 以Promise形式返回结果，返回选择的联系人对象数组。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401      | Parameter error.   |

**示例：**

  ```js
  import { BusinessError } from '@ohos.base';
  let promise = contact.selectContacts();
  promise.then((data) => {
      console.log(`selectContact success: data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`selectContact fail: err->${JSON.stringify(err)}`);
  });
  ```

## contact.selectContacts<sup>10+</sup>

selectContacts(options: ContactSelectionOptions, callback: AsyncCallback&lt;Array&lt;Contact&gt;&gt;): void

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用callback方式作为异步方法。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| options | [ContactSelectionOptions](#contactselectionoptions10) | 是   | 选择联系人时的筛选条件 |
| callback | AsyncCallback&lt;Array&lt;[Contact](#contact)&gt;&gt; | 是   | 回调函数，返回选择的联系人对象数组。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401      | Parameter error.   |

**示例：**

  ```js
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

## contact.selectContacts<sup>10+</sup>

selectContacts(options: ContactSelectionOptions): Promise&lt;Array&lt;Contact&gt;&gt;

调用选择联系人接口，打开选择联系人UI界面，选定的联系人使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Applications.Contacts

**返回值：**

| 类型                                            | 说明                                              |
| ----------------------------------------------- | ------------------------------------------------- |
| options | [ContactSelectionOptions](#contactselectionoptions10) | 是   | 选择联系人时的筛选条件 |
| Promise&lt;Array&lt;[Contact](#contact)&gt;&gt; | 以Promise形式返回结果，返回选择的联系人对象数组。 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401      | Parameter error.   |

**示例：**

  ```js
  import { BusinessError } from '@ohos.base';
  let promise = contact.selectContacts({isMultiSelect:false});
  promise.then((data) => {
      console.log(`selectContact success: data->${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
      console.error(`selectContact fail: err->${JSON.stringify(err)}`);
  });
  ```


## ContactSelectionOptions<sup>10+</sup>

选择联系人条件。

**系统能力**：SystemCapability.Applications.Contacts

|                名称               |                  类型                 | 必填  |        说明      |
| --------------------------------- | ------------------------------------- | ---- | ---------------- |
| isMultiSelect <sup>10+</sup>         | boolean | 否   | 是否为多选     |



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
| phoneNumbers      | [PhoneNumber](#phonenumber)[]           | 是   | 是   | 联系人的电话号码列表。                 |
| name              | [Name](#name)                           | 是   | 是   | 联系人的姓名。                         |


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


## Name

联系人的名字类。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。

| 名称               |   类型   | 可读 | 可写 | 说明                        |
| ------------------ | -------- | ---- | ---- | --------------------------- |
| fullName           | string   | 是   | 是   | 联系人的全名。              |



**对象创建示例：**

  使用JSON格式创建数据：

```js
let name: contact.Name = {
    fullName: "fullName"
};
```

  或使用new一个name对象的方式创建数据：

```js
let name = new contact.Name();
name.fullName = "fullName";
```


## PhoneNumber

联系人电话号码类。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Applications.ContactsData。


### 属性

| 名称        |   类型   | 可读 | 可写 | 说明               |
| ----------- | -------- | ---- | ---- | ------------------ |
| phoneNumber | string   | 是   | 是   | 电话号码。         |


**对象创建示例：**

  使用JSON格式创建数据：

```js
let phoneNumber: contact.PhoneNumber = {
    phoneNumber: "138xxxxxxxx",
};
```

  或使用new一个PhoneNumber对象的方式创建数据：

```js
let phoneNumber = new contact.PhoneNumber();
phoneNumber.phoneNumber = "138xxxxxxxx";
```