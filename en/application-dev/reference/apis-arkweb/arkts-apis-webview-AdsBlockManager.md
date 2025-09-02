# Class (AdsBlockManager)

Implements an **AdsBlockManager** instance to set custom ad blocking configurations in the **Web** components and disable the ad blocking feature for specific websites. Each application's **Web** components share an **AdsBlockManager** instance.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.
>
> - Static methods must be used on the user interface (UI) thread.

## Modules to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## setAdsBlockRules<sup>12+</sup>

static setAdsBlockRules(rulesFile: string, replace: boolean): void

Sets a custom ad blocking rule file that conforms to the universal EasyList syntax in the **Web** components.

> **NOTE**
>
> The ad blocking rules set by this API will be persistently stored after successful internal parsing; you do not need to set them again after the application is restarted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| rulesFile | string | Yes  | Path to the rule file that conforms to the universal EasyList syntax. The application needs to have read permission for this file.|
| replace   | boolean | Yes  | Whether to replace the built-in default rules. The value **true** indicates that the built-in default rules will be forcibly replaced; **false** indicates that the custom rules will work alongside the built-in default rules.|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { picker, fileUri } from '@kit.CoreFileKit';

// This example demonstrates how to click a button to open an EasyList-compliant rule file through filepicker and set the file in the Web component.
@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Row() {
      Flex() {
        Button({ type: ButtonType.Capsule }) {
          Text("setAdsBlockRules")
        }
        .onClick(() => {
          try {
            let documentSelectionOptions: ESObject = new picker.DocumentSelectOptions();
            let documentPicker: ESObject = new picker.DocumentViewPicker();
            documentPicker.select(documentSelectionOptions).then((documentSelectResult: ESObject) => {
              if (documentSelectResult && documentSelectResult.length > 0) {
                let fileRealPath = new fileUri.FileUri(documentSelectResult[0]);
                console.info('DocumentViewPicker.select successfully, uri: ' + fileRealPath);
                webview.AdsBlockManager.setAdsBlockRules(fileRealPath.path, true);
              }
            })
          } catch (err) {
            console.error('DocumentViewPicker.select failed with err:' + err);
          }
        })
      }
    }
  }
}
```

## addAdsBlockDisallowedList<sup>12+</sup>

static addAdsBlockDisallowedList(domainSuffixes: Array\<string\>): void

Adds an array of domain names to the disallowed list of this **AdsBlockManager** object. When the ad blocking feature is enabled, ad blocking for these websites will be disabled.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted.
>
> The ad blocking feature matches website URLs based on the suffix. For example, if the disallowed list contains **'example.com'** or **'www.example.com'**, then ad blocking will be disabled for sites **https://www.example.com** and **https://m.example.com**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to add an array of domain names to the disallowed list.
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("addAdsBlockDisallowedList") }
          .onClick(() => {
            let arrDomainSuffixes = new Array<string>();
            arrDomainSuffixes.push('example.com');
            arrDomainSuffixes.push('abcdefg.cn');
            webview.AdsBlockManager.addAdsBlockDisallowedList(arrDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

## removeAdsBlockDisallowedList<sup>12+</sup>

static removeAdsBlockDisallowedList(domainSuffixes: Array\<string\>): void

Removes an array of domain names from the disallowed list of this **AdsBlockManager** object.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted. Removing an entry that does not exist does not trigger an exception.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to remove an array of domain names from the disallowed list.
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("removeAdsBlockDisallowedList") }
          .onClick(() => {
            let arrDomainSuffixes = new Array<string>();
            arrDomainSuffixes.push('example.com');
            arrDomainSuffixes.push('abcdefg.cn');
            webview.AdsBlockManager.removeAdsBlockDisallowedList(arrDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

## clearAdsBlockDisallowedList<sup>12+</sup>

static clearAdsBlockDisallowedList(): void

Clears the disallowed list of this **AdsBlockManager** object.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("clearAdsBlockDisallowedList") }
          .onClick(() => {
            webview.AdsBlockManager.clearAdsBlockDisallowedList();
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

## addAdsBlockAllowedList<sup>12+</sup>

static addAdsBlockAllowedList(domainSuffixes: Array\<string\>): void

Adds an array of domain names to the allowed list of this **AdsBlockManager** object. This API is typically used to re-enable ad blocking for certain websites that were previously added to the disallowed list.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted.
>
> The priority of the allowed list is higher than that of the disallowed list. For example, if the disallowed list includes **['example.com']**, all pages under the **example.com** domain will have their ad blocking disabled; to re-enable ad blocking for the subdomain **news.example.com**, you can use the **addAdsBlockAllowedList(['news.example.com'])** API.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to add an array of domain names to the disallowed list.
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("addAdsBlockAllowedList") }
          .onClick(() => {
            let arrDisallowDomainSuffixes = new Array<string>();
            arrDisallowDomainSuffixes.push('example.com');
            webview.AdsBlockManager.addAdsBlockDisallowedList(arrDisallowDomainSuffixes);

            let arrAllowedDomainSuffixes = new Array<string>();
            arrAllowedDomainSuffixes.push('news.example.com');
            webview.AdsBlockManager.addAdsBlockAllowedList(arrAllowedDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true)
        })
    }
  }
}
```

## removeAdsBlockAllowedList<sup>12+</sup>

static removeAdsBlockAllowedList(domainSuffixes: Array\<string\>): void

Removes an array of domain names from the allowed list of this **AdsBlockManager** object.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted. Removing an entry that does not exist does not trigger an exception.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to remove an array of domain names from the disallowed list.
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("removeAdsBlockAllowedList") }
          .onClick(() => {
            let arrDomainSuffixes = new Array<string>();
            arrDomainSuffixes.push('example.com');
            arrDomainSuffixes.push('abcdefg.cn');
            webview.AdsBlockManager.removeAdsBlockAllowedList(arrDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

## clearAdsBlockAllowedList<sup>12+</sup>

static clearAdsBlockAllowedList(): void

Clears the allowed list of this **AdsBlockManager** object.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';


  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("clearAdsBlockAllowedList") }
          .onClick(() => {
            webview.AdsBlockManager.clearAdsBlockAllowedList();
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
      .onControllerAttached(()=>{
        this.controller.enableAdsBlock(true);
      })
    }
  }
}
```
