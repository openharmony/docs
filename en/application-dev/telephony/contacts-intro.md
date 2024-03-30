# Contacts Kit Development

The **contacts** module provide contact management capabilities, including adding, deleting, and updating contacts.

For details, see [@ohos.contact](../reference/apis-contacts-kit/js-apis-contact.md).


## Constraints

To read contacts, you need to declare the **ohos.permission.READ_CONTACTS** permission. This permission is of the **system_basic** level.

To add, delete, or update contacts, you need to declare the **ohos.permission.WRITE_CONTACTS** permission. This permission is of the **system_basic** level.

## How to Develop

1. Before requesting permissions, ensure that the [basic principles for using permissions](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](accesstoken-guidelines.md#declaring-permissions-in-the configuration-file).

2. Generally, third-party applications is not accessible to the permissions. To manage contacts in an application, call the **permissions** API to obtain the contact editing permission.

3. Set a **Permissions** array containing required variables.

4. Perform the permission operation of the corresponding contact.

```ts
// Sample code 1
let context = getContext(this) as common.UIAbilityContext;
const permissions: Array<Permissions> = ['ohos.permission.WRITE_CONTACTS'];

abilityAccessCtrl.createAtManager().requestPermissionsFromUser(context, permissions).then(() => {
    try {
        contact.selectContacts();
    } catch(err) {
        console.error('errCode: ' + err.code + ', errMessage: ' + err.message)
    }
})

// Sample code 2
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
      name: { fullName: 'Wang Xiaoming' },
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
        Button ('Add Contact')
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
