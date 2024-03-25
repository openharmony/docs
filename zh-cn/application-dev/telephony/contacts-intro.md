# Contacts Kit开发概述

提供联系人管理能力，包括添加联系人、删除联系人、更新联系人等功能。

详情请参考[@ohos.contact API](../reference/apis/js-apis-contact.md)。


## 约束与限制

读取联系人需要声明接口调用的权限：ohos.permission.READ_CONTACTS，此权限级别为system_basic。

添加联系人、删除联系人、更新联系人需要声明接口调用的权限：ohos.permission.WRITE_CONTACTS，此权限级别为system_basic。

## 开发步骤

1.在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[访问控制-声明权限](../security/AccessToken/declare-permissions.md)声明对应权限。

2.在通常情况下，第三方应用无法使用此权限，若需要在应用内实现管理联系人的功能，可以使用permissions接口获取应用对联系人的编辑权限。

3.设置一个需要的Permissions数组变量。

4.执行对应联系人的权限操作。

```ts
// 示例代码一：
let context = getContext(this) as common.UIAbilityContext;
const permissions: Array<Permissions> = ['ohos.permission.WRITE_CONTACTS'];

abilityAccessCtrl.createAtManager().requestPermissionsFromUser(context, permissions).then(() => {
    try {
        contact.selectContacts();
    } catch(err) {
        console.error('errCode: ' + err.code + ', errMessage: ' + err.message)
    }
})

// 示例代码二：
import common from '@ohos.app.ability.common';
import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';
import contact from '@ohos.contact';

@Entry
@Component
struct Contact {
  addContactByPermissions() {
    let context = getContext(this) as common.UIAbilityContext;
    const permissions: Array<Permissions> = ['ohos.permission.WRITE_CONTACTS'];
    const contactInfo: contact.Contact = {
      name: { fullName: '王小明' },
      phoneNumbers: [{ phoneNumber: '13912345678' }]
    }
    abilityAccessCtrl.createAtManager().requestPermissionsFromUser(context, permissions).then(() => {
      try {
        contact.addContact(context, contactInfo, (err, data) => {
          if (err) {
            console.log('addContact callback: err->' + JSON.stringify(err));
            return;
          }
          console.log('addContact callback: data->' + JSON.stringify(data));
        })
      } catch (err) {
        console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
      }
    })
  }

  build() {
    Row() {
      Column() {
        Button('添加联系人')
          .onClick(() => {
            this.addContactByPermissions();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```