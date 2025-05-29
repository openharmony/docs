# Contacts Kit开发概述

Contacts Kit可以帮助开发者轻松实现联系人的增删改查等功能。该Kit提供了一系列API，可以让开发者在应用中快速集成联系人管理功能。

详情请参考[@ohos.contact API](../reference/apis-contacts-kit/js-apis-contact.md)。


## 能力范围

通过Contacts Kit，开发者可以对联系人进行管理，包括增加、删除、修改、查询联系人信息。开发者还可以通过Picker的方式，拉起联系人列表。

面向所有应用开放如下能力：

- [使用Picker选择联系人](#使用picker选择联系人)

面向三方应用受限开放如下能力：

<!--RP1-->
> **注意：**
> 
> 读取联系人需要声明接口调用的权限：ohos.permission.READ_CONTACTS，此权限级别为system_basic。添加联系人、删除联系人、更新联系人需要声明接口调用的权限：ohos.permission.WRITE_CONTACTS，此权限级别为system_basic。
<!--RP1End-->

- [联系人管理](#联系人管理受限开放)

- [选择联系人](#选择联系人受限开放)


## 使用Picker选择联系人

当用户选择联系人的时候，通过Picker的方式，拉起联系人列表，引导用户完成界面操作，接口本身无需申请权限。

1. 导入相关的联系人模块。

   ```ts
   import { contact } from '@kit.ContactsKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 调用联系人接口，拉起联系人列表，用户点击对应的联系人后返回。

   ```ts
   contact.selectContacts({
     isMultiSelect:false
   },(err: BusinessError, data) => {
       if (err) {
         console.error('selectContact callback, errCode:' + err.code + ', errMessage:' + err.message);
           return;
       }
       console.info(`selectContact callback: success data->${JSON.stringify(data)}`);
   });

   ```

3. 完成操作，返回想要的data数据。


## 选择联系人（受限开放）

1. 声明接口调用所需要的权限。
   <!--RP2-->
   选择联系人，调用selectContacts接口，需要配置ohos.permission.WRITE_CONTACTS权限，权限级别为system_basic。在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)声明对应权限。
   <!--RP2End-->
2. 设置一个需要的Permissions数组变量。

3. 执行对应联系人的权限操作。

  ```ts
  import { common, abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
  import { contact } from '@kit.ContactsKit';

  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  const permissions: Array<Permissions> = ['ohos.permission.WRITE_CONTACTS'];

  abilityAccessCtrl.createAtManager().requestPermissionsFromUser(context, permissions).then(() => {
      try {
          contact.selectContacts();
      } catch(err) {
          console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
      }
  })

  ```


## 联系人管理（受限开放）

若需要在应用内实现管理联系人的功能，可以使用permissions接口获取应用对联系人的编辑权限。

1. 声明接口调用所需要的权限。
   <!--RP2-->
   - 删除联系人，调用deleteContact接口，需要配置ohos.permission.WRITE_CONTACTS权限，权限级别为system_basic。
   - 更新联系人，调用updateContact接口，需要配置ohos.permission.WRITE_CONTACTS权限，权限级别为system_basic。
   - 查询联系人，调用queryContact接口，需要配置ohos.permission.READ_CONTACTS权限，权限级别为system_basic。
   在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)声明对应权限。
   <!--RP2End-->

2. 设置一个需要的Permissions数组变量。

3. 执行对应联系人的权限操作。

  ```ts
  // 示例代码
  import { common, abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
  import { contact } from '@kit.ContactsKit';

  @Entry
  @Component
  struct Contact {
    addContactByPermissions() {
      let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
      const permissions: Array<Permissions> = ['ohos.permission.WRITE_CONTACTS'];
      const contactInfo: contact.Contact = {
        name: { fullName: '王小明' },
        phoneNumbers: [{ phoneNumber: '13912345678' }]
      }
      abilityAccessCtrl.createAtManager().requestPermissionsFromUser(context, permissions).then(() => {
        try {
          contact.addContact(context, contactInfo, (err, data) => {
            if (err) {
              console.error('addContact callback, errCode:' + err.code + ', errMessage:' + err.message);
              return;
            }
            console.info('addContact callback: data->' + JSON.stringify(data));
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
