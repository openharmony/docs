# Enabling Ads Blocking of the Web Component

The **Web** component provides features for blocking advertisement, including the common capabilities such as URL interception and element hiding. You can use [setAdsBlockRules()](../reference/apis-arkweb/js-apis-webview.md#setadsblockrules12) provided by **AdsBlockManager** to set blocking rules in EasyList and use [enableAdsBlock()](../reference/apis-arkweb/js-apis-webview.md#enableadsblock12) of the **Web** component to enable the ads blocking.

## Enabling Ads Blocking
The following example shows how to select the EasyList rule file using the file picker and how to enable the ads blocking in an application.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { picker, fileUri } from '@kit.CoreFileKit';

// This example demonstrates how to click a button to open the EasyList using file picker and set the file in the Web component.
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  controller: webview.WebviewController = new webview.WebviewController();

  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          Button({type: ButtonType.Capsule}) {
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
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

When the component has a built-in EasyList, the **replace** parameter of [setAdsBlockRules()](../reference/apis-arkweb/js-apis-webview.md#setadsblockrules12) can be used to set the options of the built-in rule. If **replace** is set to **true**, the built-in EasyList is not used. Otherwise, the custom rule and built-in rule work at the same time. If the built-in rule conflicts with the custom rule, you can use set **replace** to **true** to disable the built-in rule.

The custom rule is a global configuration rule for the application that it takes effect for all **Web** components in the application processes. In addition, the rule is persistent that it continues to work when the application is restarted.

## Disabling Ads Blocking on Pages with Specific Domain Names
When the ads blocking of a **Web** component is enabled, you may want to disable it for some specific pages. In addition to the custom EasyList, you can also use [addAdsBlockDisallowedList()](../reference/apis-arkweb/js-apis-webview.md#addadsblockdisallowedlist12) provided by **AdsBlockManager** to disable the blocking.

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

The domain names are set to **DisallowedList** of **AdsBlockManager** through **addAdsBlockDisallowedList()**. When the page is loaded, the system matches the suffix of the web page URL with the domain names in **DisallowedList**. If the matching is successful, ads blocking will be disabled on the page. In addition, [addAdsBlockAllowedList()](../reference/apis-arkweb/js-apis-webview.md#addadsblockallowedlist12) is provided to be used with **DisallowedList()** to set domain names and determine whether to enable ads blocking.

**AdsBlockManager** caches two lists of domain names, including **DisallowedList** and **AllowList**. **DisallowedList** is used to disable ads blocking on web pages, and **AllowList** is used to enable ads blocking disabled by **DisallowedList**. **AllowList** has a higher priority. When a web page is loaded, the system matches the web page URL with **AllowList**. If the matching is successful, the ad blocking is enabled. Otherwise, the system continues to match the web page URL with **DisallowedList**. If the matching is successful, the ads blocking is disabled. If the accessed web page is neither list in **AllowList** nor in **DisallowedList**, the ads blocking for this web page is enabled by default.

For example, if you want to enable ads blocking for the **news.example.com** and **sport.example.com** domain in an application, but need to disable ads blocking for other web pages under the **example.com** domain, you can use **addAdsBlockDisallowedList()** to add the **example.com** domain to **DisallowedList**, and then use **addAdsBlockAllowedList()** to add the **news.example.com** and **sport.example.com** domain to **AllowedList**.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// In the following example, **addAdsBlockAllowedList()** and **addAdsBlockDisallowedList()** are used together to set the ads blocking for web pages.
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
            arrAllowedDomainSuffixes.push('sport.example.com');
            webview.AdsBlockManager.addAdsBlockAllowedList(arrAllowedDomainSuffixes);
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

Note that the **DisallowedList** and **AllowedList** of the **AdsBlockManager** are not persisted. Therefore, the lists are reset to empty when the application is restarted.
If the ads blocking is not enabled through **enableAdsBlock()**, the preceding APIs do not take effect in the **Web** component.

## Collecting Ads Blocking Information
When ads blocking is enabled on the **Web** component, if any ad is blocked on the accessed web page, the [onAdsBlocked()](../reference/apis-arkweb/ts-basic-components-web.md#onadsblocked12) callback of the **Web** component notifies the application. You can collect blocking information and statistics as needed.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';


@Entry
@Component
struct WebComponent {
  @State totalAdsBlockCounts: number = 0;
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'https://www.example.com', controller: this.controller })
        .onAdsBlocked((details: AdsBlockedDetails) => {
          if (details) {
            console.log(' Blocked ' + details.adsBlocked.length + ' in ' + details.url);
            let adList: Array<string> = Array.from(new Set(details.adsBlocked));
            this.totalAdsBlockCounts += adList.length;
            console.log('Total blocked counts :' + this.totalAdsBlockCounts);
          }
        })
    }
  }
}
```

To reduce the frequency of notifications and minimize the impact on the page loading process, only the first notification is made when the page is fully loaded. Subsequent blocking events are reported at intervals of 1 second, and no notifications are sent if there is no ad blocked.
