# 使用Web组件的广告过滤功能
<!--Kit: ArkWeb-->
<!--Subsystem: ArkWeb-->
<!--Owner: @aohui-->
<!--SE: @yaomingliu-->
<!--TSE: @ghiker-->

ArkWeb为应用提供广告过滤功能，支持通过云端推送默认的easylist规则，或允许应用通过接口设定自定义规则文件。它在网络层拦截广告资源的下载，或在网页中注入CSS规则以隐藏特定的广告元素。

当前配置文件格式为[easylist规则](https://easylist-downloads.adblockplus.org/easylist.txt)。

## 常用easylist语法规则

| 规则类别     | 说明   | 示例 |
| ---------- | ------ | ---- |
| URL拦截规则 | 拦截所有网站中url能匹配"example.com/js/*_tv.js"的子资源请求。用于定义域名过滤规则，匹配特定的域名及其所有子域名。 | \|\|example.com/js/*_tv.js   |
| URL拦截规则 | 拦截非alimama.com、非taobao.com域名网站中的url匹配"alimama.cn"的第三方资源。\$third\_party是一种options语法，表示匹配第三方资源；域名前使用'~'表示不包括该域名。 | \|\|alimama.cn^$third-party,domain\=~alimama.com\|\~taobao.com   |
| 例外规则 | 关闭example.com网页内的广告过滤。@@是例外规则的语法关键字，表示不过滤。 | \@\@\|\|example.com^$document   |
| 例外规则 | 在域名为litv.tv的网页中，不过滤能匹配上".adserver."的子资源。 | \@\@.adserver.$domain=litv.tv   |
| 元素隐藏规则 | 隐藏myabandonware.com和myware.com域名中所有class="i528"的元素。##用于表示元素隐藏。 | myabandonware.com, myware.com##.i528   |
| 元素隐藏例外规则 | 不隐藏sdf-event.sakura.ne.jp网站中id="ad_1"的元素。 | sdf-event.sakura.ne.jp#@##ad_1   |

例外规则，通常是与普通规则配合使用的，在某些特定场景下使普通规则不适用，单独应用例外规则是没有意义的。
例如先配置了一条过滤所有网站的拦截规则：||abc.com/js/123.js，如果某些网站出现误拦截或不能拦截的情况，可以针对这些网站配置新的例外规则。

## 约束与限制

- 在[WebviewController](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md)类中，增加开启/关闭广告过滤特性的接口[enableAdsBlock()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#enableadsblock12)，支持Web实例级的特性开关。

- 新增[AdsBlockManager](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md)全局单例类，提供自定义广告过滤配置、控制网站级特性开关的能力。

- Web实例上提供了[onAdsBlocked()](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#onadsblocked12)回调通知方法，支持将拦截信息通知到上层应用。

- [AdsBlockManager](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md)接口[setAdsBlockRules()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#setadsblockrules12)接口仅能设置一份自定义配置，此配置会持久化，应用冷启动无需重新配置，可避免每次冷启动配置规则都触发广告过滤配置的编译解析。

- [AdsBlockManager](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md)接口[addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12)、[removeAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#removeadsblockdisallowedlist12)、[clearAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#clearadsblockdisallowedlist12)、[addAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockallowedlist12)、[removeAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#removeadsblockallowedlist12)、[clearAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#clearadsblockallowedlist12)操作的数据不会持久化，应用冷启动需要重新设置。

- 如果1个Web实例启用了广告过滤特性，但未调用[AdsBlockManager](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md)接口[addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12)、[removeAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#removeadsblockdisallowedlist12)、[clearAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#clearadsblockdisallowedlist12)、[addAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockallowedlist12)、[removeAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#removeadsblockallowedlist12)、[clearAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#clearadsblockallowedlist12)配置disallowlist和allowlist数据，则默认所有网站均启用广告过滤。

- allowlist和disallowlist数据共同使用时，allowlist的优先级高于disallowlist，即先使用allowlist匹配，如果匹配成功就不再使用disallowlist匹配，该网站会启用广告过滤特性。

- 如果应用未启用广告过滤特性，那么Web组件不会向服务器请求默认的内置easylist规则。

- disallowlist和allowlist数据采用后缀匹配，例如应用的设置的域名"xxyy.com"，可以匹配上url为"wwsstt.xxyy.com"的网站。

## 使用场景

### 开启广告过滤
应用可以通过AdsBlockManager提供的[setAdsBlockRules()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#setadsblockrules12)接口设置自定义的easylist过滤规则，并通过Web组件的[enableAdsBlock()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#enableadsblock12)接口使能广告过滤特性。

在下面的示例中，演示了一个应用通过文件选择器选择easylist规则文件，并开启广告过滤功能。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { picker, fileUri } from '@kit.CoreFileKit';

// 演示点击按钮，通过filepicker打开一个easylist规则文件并设置到Web组件中
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

如果存在内置的easylist规则文件，[setAdsBlockRules()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#setadsblockrules12)接口的replace参数可用于设置规则文件的使用策略，replace为true表示不使用内置的easylist规则文件，replace为false表示自定义规则和内置的规则将会同时工作，如果发现内置规则与自定义规则冲突，可使用replace=true禁用内置规则效果。

设置的自定义规则文件在应用进程内对所有的Web组件生效，是一个应用级全局配置文件，并将持久化，应用重启后可继续工作。

### 关闭特定域名页面的广告过滤
在Web组件的广告过滤开关开启后，应用有时候会期望关闭一些特定页面的广告过滤功能，除了可以使用自定义的easylist规则，AdsBlockManager还提供了[addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12)接口完成此功能。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// 演示通过一个按钮的点击向Web组件设置广告过滤的域名策略
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

[addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12)接口将域名设置到AdsBlockManager的DisallowedList中，下次页面加载时会使用网页url和DisallowedList中的域名进行后缀匹配，匹配成功则不会对此页面进行广告过滤。此外，还提供了[addAdsBlockAllowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockallowedlist12)接口配合DisallowedList进行域名设置，控制是否开启广告过滤。

AdsBlockManager中缓存有2组域名列表，分别为DisallowedList和AllowList，其中DisallowedList用于禁用网页的广告过滤，而AllowList用于重新开启被DisallowedList关闭的广告过滤开关，其中AllowList优先级更高。页面加载时会先使用网页url和AllowList进行匹配，匹配成功的网页广告过滤将保持开启，否则将会继续使用DisallowedList进行匹配，匹配成功将关闭网页的广告过滤。如果访问的网页不在AllowList和DisallowedList中，那么默认网页的广告过滤会保持开启状态。

例如，应用想要开启域名为'news.example.com'和'sport.example.com'的广告过滤，但需要关闭'example.com'的其他域名下网页的广告过滤，就可以先使用addAdsBlockDisallowedList()接口添加'example.com'域名到DisallowedList，再使用[addAdsBlockDisallowedList()](../reference/apis-arkweb/arkts-apis-webview-AdsBlockManager.md#addadsblockdisallowedlist12)接口添加'news.example.com'和'sport.example.com'域名。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// 演示addAdsBlockAllowedList和addAdsBlockAllowedList配套使用，设置网页级的广告过滤开关。
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

需要注意的是，AdsBlockManager的DisallowedList和AllowedList列表不会持久化，因此重启应用后会重置为空。
如果Web组件未通过[enableAdsBlock()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#enableadsblock12)接口开启广告过滤功能，上述接口设置在此Web组件中将不起作用。

### 收集广告过滤的信息
在Web组件的广告过滤开关开启后，访问的网页如果发生了广告过滤，会通过Web组件的[onAdsBlocked()](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#onadsblocked12)回调接口通知到应用，应用可根据需要进行过滤信息的收集和统计。

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

由于页面可能随时发生变化并不断产生网络请求，为了减少通知频次、降低对页面加载过程的影响，仅在页面加载完成时进行首次通知，此后发生的过滤将间隔1秒钟上报，无广告过滤则无通知。
