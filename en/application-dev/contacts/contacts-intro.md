# Contacts Kit Development

The Contacts Kit allows users to add, delete, modify, and query contacts easily. It provides a series of APIs for you to quickly integrate contact management functions into your applications.

For details, see [@ohos.contact](../reference/apis-contacts-kit/js-apis-contact.md).


## Available Capabilities

Using the Contacts Kit, you can manage contacts, including adding, deleting, modifying, and querying contact information. You can also use the Picker function to open the contact list.

The following capabilities are opened to all applications:

- [Contact Selection with Picker](#contact-selection-with-picker)

The following capabilities are restrictedly opened to third-party applications:

<!--RP1-->
> **NOTE**
> 
> To read contacts, you need to declare the **ohos.permission.READ_CONTACTS** permission. This permission is of the **system_basic** level. To add, delete, or update contacts, you need to declare the **ohos.permission.WRITE_CONTACTS** permission. This permission is of the **system_basic** level.
<!--RP1End-->

- [Contact Management](#contact-management-restricted-permission)


## Contact Selection with Picker

When you select a contact, the contact list is displayed in Picker mode to facilitate selection. You do not need to apply for permissions for using the API.

1. Import the related modules.

   ```ts
   import { contact } from '@kit.ContactsKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Call the contact API to display the contact list, and click the desired contact.

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

3. View the returned contact data.


## Contact Management (Restricted Permission)

To implement contact management for an application, use the **permissions** API to request for the contact editing permission.

1. Declare the required permission:
   <!--RP2-->
   - To delete a contact, you need to declare the **ohos.permission.WRITE_CONTACTS** permission to call the **deleteContact** API. This permission is of the **system_basic** level.
   - To update a contact, you need to declare the **ohos.permission.WRITE_CONTACTS** permission to call the **updateContact** API. This permission is of the **system_basic** level.
   - To query a contact, you need to declare the **ohos.permission.READ_CONTACTS** permission to call the **queryContact** API. This permission is of the **system_basic** level.
   Before declaring the required permission, ensure that the [basic principles for using permissions](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Then, declare the requried permission by referring to [Requesting Application Permissions](../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).
   <!--RP2End-->

2. Include an array of required permissions in **Permissions**.

3. Perform the corresponding operation on the contact.

  ```ts
  // Sample code
  import { common, abilityAccessCtrl, Permissions, PermissionRequestResult } from '@kit.AbilityKit';
  import { contact } from '@kit.ContactsKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct Contact {
    addContactByPermissions() {
      // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
      let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
      const permissions: Array<Permissions> = ['ohos.permission.WRITE_CONTACTS'];
      const contactInfo: contact.Contact = {
        name: { fullName: 'Wang Xiaoming' },
        phoneNumbers: [{ phoneNumber: '13912345678' }]
      }
      abilityAccessCtrl.createAtManager().requestPermissionsFromUser(context, permissions).then((result: PermissionRequestResult) => {
        if (result.authResults[0] !== 0) { // 0 if the permission request is successful; a non-0 value otherwise.
          console.error('request contact permissions failed');
          return;
        }
        contact.addContact(context, contactInfo).then((data) => {
          console.info(`Succeeded in adding Contact. data: ${JSON.stringify(data)}`);
        }).catch((err: BusinessError) => {
          console.error(`Failed to add Contact. Code: ${err.code}, message: ${err.message}`);
        });
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
