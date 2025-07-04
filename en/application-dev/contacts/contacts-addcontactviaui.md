# Using the Picker for Contact Management

## Available APIs

| API                 | Description                                      |
| --------------------- | ------------------------------------------ |
| addContactViaUI(context: Context, contact: Contact): Promise&lt;number&gt; | Opens the **Add contact** page to add a contact. This API uses a promise to return the result.|
| saveToExistingContactViaUI(context: Context, contact: Contact): Promise&lt;number&gt; | Opens the **Save to existing** page to save a contact to an existing one. This API uses a promise to return the result.|


## Creating a Contact

Call **addContactViaUI** to launch the UI for contact creation. Then, uses can complete contact information on the UI.

```js
import { common } from '@kit.AbilityKit';
import { contact } from '@kit.ContactsKit';
import { BusinessError } from '@kit.BasicServicesKit';


@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
    
  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          let contactInfo: contact.Contact = {
            name: {
              fullName: 'xxx'
            },
            phoneNumbers: [{
              phoneNumber: '138xxxxxx'
            }]
          }
          let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
          let promise = contact.addContactViaUI(context, contactInfo);
          promise.then((data) => {
              console.info(`Succeeded in add Contact via UI.data->${JSON.stringify(data)}`);
            }).catch((err: BusinessError) => {
              console.error(`Failed to add Contact via UI. Code: ${err.code}, message: ${err.message}`);
            });
        })
    }
  }
}
```

## Updating Contact Information

Call **saveToExistingContactViaUI** to launch the UI for contact information updating. Then, users can update information about a specific contact on the UI.

```js
import { common } from '@kit.AbilityKit';
import { contact } from '@kit.ContactsKit';
import { BusinessError } from '@kit.BasicServicesKit';


@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
    
  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          let contactInfo: contact.Contact = {
            id: 1,
            name: {
              fullName: 'xxx'
            },
            phoneNumbers: [{
              phoneNumber: '138xxxxxx'
            }]
          }
          let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
          let promise = contact.saveToExistingContactViaUI(context, contactInfo);
          promise.then((data) => {
              console.info(`Succeeded in save to existing Contact via UI.data->${JSON.stringify(data)}`);
            }).catch((err: BusinessError) => {
              console.error(`Failed to save to existing Contact via UI. Code: ${err.code}, message: ${err.message}`);
            });
        })
    }
  }
}
``` 
