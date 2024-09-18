# Establishing a Data Channel Between the Application and the Frontend Page


The [createWebMessagePorts()](../reference/apis-arkweb/js-apis-webview.md#createwebmessageports) API allows you to create message ports to implement communication between the application and frontend page.


In the following example, **createWebMessagePorts** is used to create message ports on the application and [postMessage()](../reference/apis-arkweb/js-apis-webview.md#postmessage) is used to forward one of the message ports to the frontend page so that the application and frontend page can exchange messages with each other over the port.


- Application code:

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
        // Display the content received from the HTML side.
        Text(this.receivedFromHtml)
        // Send the content in the text box to the HTML side.
        TextInput({ placeholder: 'Send this message from ets to HTML' })
          .onChange((value: string) => {
            this.sendFromEts = value;
          })

        // The following can be called in the onPageEnd lifecycle callback.
        Button('postMessage')
          .onClick(() => {
            try {
              // 1. Create two message ports.
              this.ports = this.controller.createWebMessagePorts();
              // 2. Register a callback for the message port (for example, port 1) on the application.
              this.ports[1].onMessageEvent((result: webview.WebMessage) => {
                let msg = 'Got msg from HTML:';
                if (typeof (result) === 'string') {
                  console.info(`received string message from html5, string is: ${result}`);
                  msg = msg + result;
                } else if (typeof (result) === 'object') {
                  if (result instanceof ArrayBuffer) {
                    console.info(`received arraybuffer from html5, length is: ${result.byteLength}`);
                    msg = msg + 'lenght is ' + result.byteLength;
                  } else {
                    console.info('not support');
                  }
                } else {
                  console.info('not support');
                }
                this.receivedFromHtml = msg;
              })
              // 3. Send the other message port (for example, port 0) to the HTML side, which then saves the message port.
              this.controller.postMessage('__init_port__', [this.ports[0]], '*');
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })

        // 4. Use the message port on the application to send messages to the message port that has been sent to the HTML side.
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
        Web({ src: $rawfile('index.html'), controller: this.controller })
      }
    }
  }
  ```

- Frontend page code:

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
              h5Port = event.ports[0]; // 1. Save the port number sent from the application side.
              h5Port.onmessage = function (event) {
                // 2. Receive messages sent from the eTS side.
                var msg = 'Got message from ets:';
                var result = event.data;
                if (typeof(result) === 'string') {
                  console.info(`received string message from html5, string is: ${result}`);
                  msg = msg + result;
                } else if (typeof(result) === 'object') {
                  if (result instanceof ArrayBuffer) {
                    console.info(`received arraybuffer from html5, length is: ${result.byteLength}`);
                    msg = msg + 'lenght is ' + result.byteLength;
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

  // 3. Use h5Port to send messages to the application side.
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
