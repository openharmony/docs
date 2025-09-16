# Using App Linking for Application Redirection

## Overview

In App Linking, the system directs users to specific content in the target application based on the passed-in URI (HTTPS link). Unlike [Deep Linking](deep-linking-startup.md), users can directly access the content regardless of whether the target application is installed.


## When to Use

* App Linking applies to scenarios with high security requirements. It helps prevent spoofing of the target application.

* App Linking applies to scenarios with high requirements on user experience. Users can directly access the content regardless of whether the target application is installed.

## Working Principles

* App Linking adopts domain name verification, which is unavailable in Deep Linking. Domain name verification helps identify valid applications, making links more secure and reliable.

* App Linking requires that an HTTPS website be displayed in two modes: application and web page. When the application is installed, the application is preferentially opened to present the content. When the application is not installed, the web page is opened to present the content.


## Procedure for the Target Application

To use App Linking in the target application, perform the following operations:

1. Declare a domain name.
2. Associate the application on the developer website.
3. Add code to the ability of the application to handle the passed-in link.


### Declaring a Domain Name

Configure the [module.json5 file](../quick-start/module-configuration-file.md) of the application to declare the domain name associated with the application, and enable domain name verification:

* The **actions** field must contain **ohos.want.action.viewData**.
* The **entities** field must contain **entity.system.browsable**.
* The **uris** field must contain an element whose **scheme** is **https** and **host** is a domain name address.
* **domainVerify** must be set to **true**.

> **NOTE**
>
> By default, the **skills** field contains a skill object, which is used to identify the application entry. Application redirection links should not be configured in this object. Instead, separate skill objects should be used. If there are multiple redirection scenarios, create different skill objects under **skills**. Otherwise, the configuration does not take effect.


For example, the configuration below declares that the application is associated with the domain name www.example.com.

```json
{
  "module": {
    // ...
    "abilities": [
      {
        // ...
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "ohos.want.action.home"
            ]
          },
          {
            "entities": [
              // entities must contain "entity.system.browsable".
              "entity.system.browsable"
            ],
            "actions": [
              // actions must contain "ohos.want.action.viewData".
              "ohos.want.action.viewData"
            ],
            "uris": [
              {
                // scheme must be set to https.
                "scheme": "https",
                // host must be set to the associated domain name.
                "host": "www.example.com",
                // path is optional. To distinguish between applications that are associated with the same domain name, you are advised to configure this field.
                "path": "path1"
              }
            ],
            // domainVerify must be set to true.
           "domainVerify": true
          } // Add a skill object for redirection. If there are multiple redirection scenarios, create multiple skill objects.
        ]
      }
    ]
  }
}
```


### Associating the Application on the Developer Website

Perform the following operations on the developer website to associate the application:

1. Create the domain name configuration file **applinking.json**.

   The content is as follows:

   ```json
   {
    "applinking": {
      "apps": [
        {
          "appIdentifier": "1234"
        }
      ]
    }
   }
   ```

   **app-identifer** is the unique identifier allocated to an application during application signing. It is also the value of the **app-identifer** field declared in the [HarmonyAppProvision configuration file](../security/app-provision-structure.md).

1. Place the domain name configuration file in a fixed directory on the DNS.
   
   The fixed directory is as follows:

   > https://*your.domain.name*/.well-known/applinking.json

   For example, if the domain name is www.example.com, place the **applinking.json** file in the following directory:
   `https://www.example.com/.well-known/applinking.json`


### Adding Code to the Ability of the Application to Handle the Passed-in Link

Add code to the **onCreate()** or **onNewWant()** lifecycle callback of the ability (such as EntryAbility) of the application to handle the passed-in link.

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { url } from '@kit.ArkTS';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // Obtain the input link information from want.
    // For example, the input URL is https://www.example.com/programs?action=showall.
    let uri = want?.uri 
    if (uri) {
      // Parse the query parameter from the link. You can perform subsequent processing based on service requirements.
      let urlObject = url.URL.parseURL(want?.uri);
      let action = urlObject.params.get('action')
      // For example, if action is set to showall, all programs are displayed.
      if (action === "showall") {
         // ...
      }
    }
  }
}
```

## Implementing Application Redirection (Required for the Caller Application)

The caller application passes in the link of the target application through the **UIAbilityContext.openLink** API to start the target application.

The **openLink** API provides two methods for starting the target application.

  - Method 1: Open the application only in App Linking mode.
    
    In this mode, **appLinkingOnly** is set to **true**. If a matching application is found, that application is directly opened. If no application matches, an exception is thrown.

  - Method 2: Open the application preferentially in App Linking mode.

    In this mode, **appLinkingOnly** is set to **false** or uses the default value. App Linking is preferentially used to start the target application. If a matching application is found, that application is directly opened. If no application matches, the system attempts to open the application in Deep Linking mode.

This section describes method 1, in order to check whether the App Linking configuration is correct. The following is an example.

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Index {
  build() {
    Button('start link', { type: ButtonType.Capsule, stateEffect: true })
      .width('87%')
      .height('5%')
      .margin({ bottom: '12vp' })
      .onClick(() => {
        let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
        let link: string = "https://www.example.com/programs?action=showall";
        // Open the application only in App Linking mode.
        context.openLink(link, { appLinkingOnly: true })
          .then(() => {
            console.info('openlink success.');
          })
          .catch((error: BusinessError) => {
            console.error(`openlink failed. error:${JSON.stringify(error)}`);
          });
      })
  }
}
```

If the target application is started, the App Linking configuration of the target application is correct.

## FAQs


1. What should I do when the value of **skills** in the **Modules.json5** file of the application is incorrect?

   Ensure that the value of **host** is the domain name of the application.

2. What should I do when the developer website server is incorrectly configured?

   * Check the JSON configuration of the server and ensure that the value of **appIdentifier** is correct.
   * Check whether the **applinking.json** file is stored in the correct directory (**.well-known**). Use a browser to access the JSON file address https://*your.domain.name*/.well-known/applinking.json and ensure that the file is accessible.

3. What should I do when the system has not verified the domain name?

   After installing the application on the device, wait for at least 20 seconds to ensure that asynchronous verification is complete.

4. What is the mapping between applications and domain names?

   They are in a many-to-many relationship. An application can be associated with multiple domain names, and a domain name can be associated with multiple applications.

5. If a domain name is associated with multiple applications, which application will be started by domain name?

   You can configure the **applinking.json** file to associate a domain name with multiple applications. If the **uris** field in the **module.json5** file of each application is set to the same value, the system displays a dialog box for users to select the application to start.
   
   You can also use the **path** field to distinguish the applications to start. For example, use **https://www.example.com/path1** to start target application 1 and use **https://www.example.com/path2** to start target application 2.
  
