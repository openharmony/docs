# Using mailto to Start an Email Application

## When to Use

You can create hyperlinks that link to email addresses through mailto, so that users can easily access email clients by touching the hyperlinks present within websites or applications. You can also preset the recipient, subject, and body of the email in the mailto: fields to save the time when composing emails.

Typical development scenarios are as follows:

- On websites:
    - When browsing product pages on a shopping website, users can touch a **Contact Us** button, which triggers the default email client with the customer service email pre-filled as the recipient and the subject line set to inquire about the product.
    - On job posting pages, touching an **Apply for Job** button opens an email client with the recruitment email address pre-filled, the subject line set to "Request for a Specific Position," and the body possibly pre-populated with a request template.
- Within applications:
    - In a mobile application, touching a **Feedback** button may cause the application to activate the system's default email client, with the feedback email address and issue details preset.
    - In a mobile application, when users touch a **Share via email** button, the application can use the mailto protocol to initiate the email client, pre-populating the subject and body of the email.
> **NOTE**
> - To start an email application through mailto, the initiating application must first format the string according to the mailto protocol and then use this method to launch the email application. The email application parses the mailto string to populate fields like the sender, recipient, and email body.
> - If the initiating application already has details such as the sender, recipient, and email body, you are advised to [use startAbilityByType to start an email application](start-email-apps.md).

## Format of mailto

The standard mailto format is as follows:

```
mailto:someone@example.com?key1=value1&key2=value2
```

+ **mailto:**: mailto scheme, which is mandatory.
+ **someone@example.com**: recipient address, which is optional. If there are multiple addresses, separate them with commas (,).
+ **?**: start character of the email header declaration. If email header parameters are contained, this parameter is mandatory.
+ **key-value**: email header parameters. For details, see the following table.

  | Email Header Parameter| Description| Data Type| Mandatory|
  | --- | --- | --- | --- |
  | subject | Email subject.| string | No|
  | body | Email body.| string | No|
  | cc| Copy-to person. Use commas (,) to separate multiple recipients.| string | No|
  | bcc| Bcc recipient. Use commas (,) to separate multiple recipients.| string | No|

## Developing a Caller Application

### On Websites

Hyperlinks on web pages must comply with the mailto protocol. Example:


```
<a href="mailto:support@example.com?subject=Product Inquiry&body=I am interested in...">Contact Us</a>
```
Replace the email address with the actual one, and configure the email content as required.

### Within Applications

Pass the mailto string to the **uri** parameter. In the application, the context can be obtained through **getContext (this)** for a page and through **this.context** for an ability.

```ts
@Entry
@Component
struct Index {

  build() {
    Column() {
      Button('Feedback')
        .onClick(() => {
          let ctx = getContext(this) as common.UIAbilityContext;
          ctx.startAbility({
            action: 'ohos.want.action.sendToData',
            uri: 'mailto:feedback@example.com?subject=App Feedback&body=Please describe your feedback here...'
          })
        
        })
    }
  }
}
```



## Developing a Target Application

1. To be started by other applications in mailto mode, an application must declare its mailto configuration in the [module.json5 file](../quick-start/module-configuration-file.md).

    ```json
    {
      "module": {
        // ...
        "abilities": [
          {
            // ...
            "skills": [
              {
              "actions": [
                  'ohos.want.action.sendToData'
                ],
                "uris": [
                  {
                    "scheme": "mailto",
                    // linkFeature is used to start a vertical domain panel.
                    "linkFeature": 'ComposeMail'
                  }
                ]
              }
            ]
          }
        ]
      }
    }
    ```

2. The target application obtains the **uri** parameter from the code for parsing.

    ```ts
    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void { 
        // Callback of the application cold start lifecycle, where other services are processed.
        parseMailto(want);
      }

      onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        // Callback of the application hot start lifecycle, where other services are processed.
        parseMailto(want);
      }

      public parseMailto(want: Want) {
        const uri = want?.uri;
        if (!uri || uri.length <= 0) {
          return;
        }
        // Start to parse mailto...
      }
    }

    ```
