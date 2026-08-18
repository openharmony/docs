# Using the Ad Blocking Feature

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=28ca9f6fbe76ba1de91dad58d9ee3079cdad3c1a translatedAt=2026-08-14T03:42:20.952Z pushedAt=2026-08-14T07:16:16.415Z -->

ArkWeb provides the ad blocking feature for applications, supporting default EasyList rules pushed by the cloud and custom rule files set by applications through APIs. It can intercept the advertisement resource download at the network layer or inject CSS rules into the web page to hide specific advertisement elements.

The current configuration file format uses [EasyList](https://easylist-downloads.adblockplus.org/easylist.txt).

## Common EasyList Rules

| Type    | Description  | Example|
| ---------- | ------ | ---- |
| URL blocking rule| Blocks all sub-resource requests whose URLs match **example.com/js/*_tv.js**. This rule is used to block a specified domain name and all its subdomain names.| \|\|example.com/js/*_tv.js   |
| URL blocking rule| Blocks third-party resources whose URLs match **alimama.cn** on websites whose domain names are neither **alimama.com** nor **taobao.com**. **\$third\_party** is an options syntax used to match third-party resources. A tilde (~) before a domain name indicates that the domain name is not included.| \|\|alimama.cn^$third-party,domain\=~alimama.com\|\~taobao.com   |
| Exception rule| Disables ad blocking on **example.com**. **@@** is the syntax keyword that indicates no blocking.| \@\@\|\|example.com^$document   |
| Exception rule| Disables the blocking of subresources that match **.adserver** in the web page whose domain name is **litv.tv**.| \@\@.adserver.$domain=litv.tv   |
| Element hiding rule| Hides all elements whose class is **i528** in the web page whose domain name is **myabandonware.com** or **myware.com**. **##** is used to hide an element.| myabandonware.com, myware.com##.i528   |
| Element hiding exception rule| Disables the hiding of elements whose IDs are **ad_1** in **sdf-event.sakura.ne.jp**.| sdf-event.sakura.ne.jp#@##ad_1   |

Exception rules are usually used together with common rules. In some specific scenarios, common rules are not applicable, and exception rules do not have effects.

For example, if you configure a blocking rule **||abc.com/js/123.js** to block websites, but some websites are blocked by mistake or cannot be blocked, you can configure exception rules for these websites.

## Constraints

- In the [WebviewController](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md) class, the [enableAdsBlock()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#enableadsblock12) API is added for enabling or disabling the ad blocking feature at the web instance level.

- The [AdsBlockManager](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md) global singleton class is added to provide the capabilities of customizing ad blocking configurations and controlling website-level features.

- The web instance provides [onAdsBlocked()](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#onadsblocked12) callback to notify the upper-layer application of the interception information.

- Only one custom configuration can be set by the [setAdsBlockRules()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#setadsblockrules12) API of [AdsBlockManager](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md). The configuration is persistent and does not need to be reconfigured during cold start of the application. This prevents the compilation and parsing of the ad blocking rule from being triggered again.

- The data operated by the [addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12), [removeAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#removeadsblockdisallowedlist12), [clearAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#clearadsblockdisallowedlist12), [addAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockallowedlist12), [removeAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#removeadsblockallowedlist12) and [clearAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#clearadsblockallowedlist12) APIs of the [AdsBlockManager](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md) API is not persistent. The data needs to be reset during cold start of the application.

- If the ad filtering feature is enabled for a web instance but the [AdsBlockManager](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md) APIs [addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12), [removeAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#removeadsblockdisallowedlist12), [clearAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#clearadsblockdisallowedlist12), [addAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockallowedlist12), [removeAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#removeadsblockallowedlist12), and [clearAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#clearadsblockallowedlist12) are not called to configure the disallowedlist and allowedlist data, ad filtering is enabled for all websites by default.

- When the allowedlist and disallowedlist data are used together, the allowedlist has a higher priority than the disallowedlist. That is, the allowedlist is used for matching first. If the matching is successful, the disallowedlist is no longer used for matching, and the ad filtering feature is enabled for the website.

- If the ad blocking feature is not enabled for the application, the **Web** component does not request the default built-in EasyList file from the server.

- The disallowedlist and allowedlist data use suffix matching. For example, if the app sets the domain name "xxyy.com", it can match the website whose URL is "wwsstt.xxyy.com".

## Application Scenarios

### Enabling Ad Blocking

You can use [setAdsBlockRules()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#setadsblockrules12) provided by **AdsBlockManager** to set blocking rules in EasyList and use [enableAdsBlock()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#enableadsblock12) of the **Web** component to enable the ad blocking feature.

The following example shows how to select the EasyList file using the file picker and how to enable the ad blocking feature in an application.

<!-- @[app_select_list_rule_file_for_ad_filter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebCompSecPriv/entry/src/main/ets/pages/EnablingAdsBlocking.ets) -->

``` TypeScript
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
            Text('setAdsBlockRules')
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

When the component has a built-in EasyList, you can set the **replace** parameter of the [setAdsBlockRules()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#setadsblockrules12) API to disable the built-in EasyList. When the **replace** parameter is set to **false**, the built-in and custom rules work at the same time. If the built-in rules conflict with the custom rules, set the **replace** parameter to **true**.

The custom rule file is a global configuration file for the application that it takes effect for all **Web** components in the application processes. In addition, the file is persistent that it continues to work when the application is restarted.

### Disabling Ad Blocking on Pages with Specific Domain Names

When the ad blocking feature of a **Web** component is enabled, in addition to the custom EasyList, you can also use [addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12) provided by **AdsBlockManager** to disable the ad blocking feature.

<!-- @[turn_off_ad_filtering_for_specific_domain_pages](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebCompSecPriv/entry/src/main/ets/pages/DisAdsBlockSpecDomPages_one.ets) -->

``` TypeScript
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
            .id('input_url')    
            .height(40)    
            .margin(5)    
            .borderColor(Color.Blue)    
            .onChange((value: string) => {    
              this.input_text = value;    
            })    

          Button({type: ButtonType.Capsule}) { Text('Go') }    
          .onClick(() => {    
            this.controller.loadUrl(this.input_text);    
          })    

          Button({type: ButtonType.Capsule}) { Text('addAdsBlockDisallowedList') }    
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

Add the domain name to **DisallowedList** of **AdsBlockManager** through [addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12). When the page is loaded, the system matches the suffix of the web page URL with the domain name in **DisallowedList**. If the matching is successful, the system does not block ads on the page. In addition, [addAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockallowedlist12) is provided to be used with **DisallowedList()** to set domain names and determine whether to enable ad blocking.

**AdsBlockManager** caches two lists of domain names, namely **DisallowedList** and **AllowedList**. **DisallowedList** is used to disable ad filtering on web pages, while **AllowedList** is used to re-enable the ad filtering switch that has been turned off by **DisallowedList**. **AllowedList** has a higher priority. When a page is loaded, the page URL is first matched against **AllowedList**. If the matching is successful, ad filtering remains enabled for the web page. Otherwise, the URL is matched against **DisallowedList**. If the matching is successful, ad filtering is disabled for the web page. If the visited web page is in neither **AllowedList** nor **DisallowedList**, ad filtering remains enabled for the web page by default.

For example, if you want to enable ad filtering for the domains 'news.example.com' and 'sport.example.com' in an app, but disable ad filtering for web pages under other domains of 'example.com', you can first call [addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12) to add the 'example.com' domain to **DisallowedList**, and then call [addAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockallowedlist12) to add the 'news.example.com' and 'sport.example.com' domains.

<!-- @[set_up_page_level_ad_filtering_switch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebCompSecPriv/entry/src/main/ets/pages/DisAdsBlockSpecDomPages_two.ets) -->

``` TypeScript
import { webview } from '@kit.ArkWeb';    

// Demonstrate the combined use of addAdsBlockAllowedList and addAdsBlockDisallowedList to set the web-page-level ad filtering switch.
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
            .id('urlInput')    
            .height(40)    
            .margin(5)    
            .borderColor(Color.Blue)    
            .onChange((value: string) => {    
              this.input_text = value;    
            })    

          Button({type: ButtonType.Capsule}) { Text('Go') }    
          .onClick(() => {    
            this.controller.loadUrl(this.input_text);    
          })    

          Button({type: ButtonType.Capsule}) { Text('addAdsBlockAllowedList') }    
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

If the ad blocking feature of the **Web** component is not enabled through [enableAdsBlock()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#enableadsblock12), the preceding APIs do not take effect in the **Web** component.

### Collecting Ad Blocking Information

When ad blocking is enabled on the **Web** component, if any ad is blocked on the accessed web page, the [onAdsBlocked()](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#onadsblocked12) callback of the **Web** component notifies the application. You can collect blocking information and statistics as needed.

<!-- @[collect_information_about_ad_filtering](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebCompSecPriv/entry/src/main/ets/pages/CollectingAdsBlockingInformation.ets) -->

``` TypeScript
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
            console.info(' Blocked ' + details.adsBlocked.length + ' in ' + details.url);    
            let adList: Array<string> = Array.from(new Set(details.adsBlocked));    
            this.totalAdsBlockCounts += adList.length;    
            console.info('Total blocked counts :' + this.totalAdsBlockCounts);    
          }    
        })    
    }    
  }    
}
```

To reduce the frequency of notifications and minimize the impact on the page loading process, only the first notification is made when the page is fully loaded. Subsequent blocking events are reported at intervals of 1 second, and no notifications are sent if there is no ads blocked.