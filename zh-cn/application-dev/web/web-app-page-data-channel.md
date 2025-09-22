# 建立应用侧与前端页面数据通道
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->


前端页面和应用侧之间可以用[createWebMessagePorts()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createwebmessageports)接口创建消息端口来实现两端的通信。


在下面的示例中，应用侧页面中通过createWebMessagePorts方法创建两个消息端口，再把其中一个端口通过[postMessage()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#postmessage)接口发送到前端页面，便可以在前端页面和应用侧之间互相发送消息。端口使用完毕后或Webview对象销毁前通过[close](../reference/apis-arkweb/arkts-apis-webview-WebMessagePort.md#close)接口关闭端口。


- 应用侧代码。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    ports: webview.WebMessagePort[] = [];
    @State sendFromEts: string = 'Send this message from ets to HTML';
    @State receivedFromHtml: string = 'Display received message send from HTML';

    build() {
      Column() {
        // 展示接收到的来自HTML的内容
        Text(this.receivedFromHtml);
        // 输入框的内容发送到HTML
        TextInput({ placeholder: 'Send this message from ets to HTML' })
          .onChange((value: string) => {
            this.sendFromEts = value;
          })

        // 该内容可以放在onPageEnd生命周期中调用。
        Button('postMessage')
          .onClick(() => {
            try {
              // 1、创建两个消息端口。
              this.ports = this.controller.createWebMessagePorts();
              if (this.ports && this.ports[0] && this.ports[1]) {
                // 2、在应用侧的消息端口(如端口1)上注册回调事件。
                this.ports[1].onMessageEvent((result: webview.WebMessage) => {
                  let msg = 'Got msg from HTML:';
                  if (typeof (result) === 'string') {
                    console.info(`received string message from html5, string is: ${result}`);
                    msg = msg + result;
                  } else if (typeof (result) === 'object') {
                    if (result instanceof ArrayBuffer) {
                      console.info(`received arraybuffer from html5, length is: ${result.byteLength}`);
                      msg = msg + 'length is ' + result.byteLength;
                    } else {
                      console.info('not support');
                    }
                  } else {
                    console.info('not support');
                  }
                  this.receivedFromHtml = msg;
                })
                // 3、将另一个消息端口(如端口0)发送到HTML侧，由HTML侧保存并使用。
                this.controller.postMessage('__init_port__', [this.ports[0]], '*');
              } else {
                console.error(`ports is null, Please initialize first`);
              }
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })

        // 4、使用应用侧的端口给另一个已经发送到html的端口发送消息。
        Button('SendDataToHTML')
          .onClick(() => {
            try {
              if (this.ports && this.ports[1]) {
                this.ports[1].postMessageEvent(this.sendFromEts);
              } else {
                console.error(`ports is null, Please initialize first`);
              }
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })

        // 5、关闭端口。  
        Button('closePort')
        .onClick(() => {
          try {
            if (this.ports && this.ports.length == 2) {
              this.ports[0].close();
              this.ports = [];
            } else {
              console.error("ports is null, not need close");
            }
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        Web({ src: $rawfile('index.html'), controller: this.controller })
      }
    }
  }
  ```

- 前端页面代码。

  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>WebView Message Port Demo</title>
  </head>
  <body>
      <h1>WebView Message Port Demo</h1>
      <div>
          <input type="button" value="SendToEts" onclick="PostMsgToEts(msgFromJS.value);"/><br/>
          <input id="msgFromJS" type="text" value="send this message from HTML to ets"/><br/>
      </div>
      <p class="output">display received message send from ets</p>
  </body>
  <script>
  var h5Port;
  var output = document.querySelector('.output');
  window.addEventListener('message', function (event) {
      if (event.data === '__init_port__') {
          if (event.ports[0] !== null) {
              h5Port = event.ports[0]; // 1. 保存从应用侧发送过来的端口。
              h5Port.onmessage = function (event) {
                // 2. 接收ets侧发送过来的消息。
                var msg = 'Got message from ets:';
                var result = event.data;
                if (typeof(result) === 'string') {
                  console.info(`received string message from ets, string is: ${result}`);
                  msg = msg + result;
                } else if (typeof(result) === 'object') {
                  if (result instanceof ArrayBuffer) {
                    console.info(`received arraybuffer from ets, length is: ${result.byteLength}`);
                    msg = msg + 'length is ' + result.byteLength;
                  } else {
                    console.info('not support');
                  }
                } else {
                  console.info('not support');
                }
                output.innerHTML = msg;
              }
          }
      }
  })

  // 3. 使用h5Port向应用侧发送消息。
  function PostMsgToEts(data) {
      if (h5Port) {
        h5Port.postMessage(data);
      } else {
        console.error('h5Port is null, Please initialize first');
      }
  }
  </script>
  </html>
  ```

## 常见问题

### 为什么H5向应用侧发送消息接收不到？
检查传递的数据类型是否正确，WebMessage支持的数据类型有string和ArrayBuffer。  
如果想要传递对象类型则需要将对象类型通过JSON.stringify方法转换为string类型再进行传递。示例如下：

```ts
  function PostMsgToEts(data) {
      if (h5Port) {
        let obj = {name:'exampleName',id:10}
        h5Port.postMessage(JSON.stringify(obj));
      } else {
        console.error('h5Port is null. Please initialize it first.');
      }
  }
```

### onControllerAttached与javaScriptOnDocumentStart的执行顺序是什么？
[javaScriptOnDocumentStart](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#javascriptondocumentstart11)在[onControllerAttached](../reference/apis-arkweb/arkts-basic-components-web-events.md#oncontrollerattached10)之后执行。 