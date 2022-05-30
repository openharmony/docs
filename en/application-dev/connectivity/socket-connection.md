# Socket Connection


## Use Cases

Your application can transmit data through Socket connections. Currently, the TCP and UDP protocols are supported.


## Available APIs

The Socket connection function is mainly implemented by the Socket module. The following table describes the related APIs.

| API| Description |
| -------- | -------- |
| constructUDPSocketInstance() | Creates a **UDPSocket** object. |
| constructTCPSocketInstance() | Creates a **TCPSocket** object. |
| bind() | Binds the IP address and port number. |
| send() | Sends data.|
| close() | Closes a Socket connection. |
| getState() | Obtains the Socket connection status. |
| connect() | Connects to the specified IP address and port. This function is supported only for TCP. |
| getRemoteAddress() | Obtains the peer address of the Socket connection. This function is supported only for TCP. The **connect** API must have been called before you use this API. |
| on(type:&nbsp;'message') | Enables listening for **message** events of the Socket connection. |
| off(type:&nbsp;'message') | Disables listening for **message** events of the Socket connection. |
| on(type:&nbsp;'close') | Enables listening for **close** events of the Socket connection. |
| off(type:&nbsp;'close') | Disables listening for **close** events of the Socket connection. |
| on(type:&nbsp;'error') | Enables listening for **error** events of the Socket connection. |
| off(type:&nbsp;'error') | Disables listening for **error** events of the Socket connection. |
| on(type:&nbsp;'listening') | Enables listening for **listening** events of the UDPSocket connection. |
| off(type:&nbsp;'listening') | Disables listening for **listening** events of the UDPSocket connection. |
| on(type:&nbsp;'connect') | Enables listening for **connect** events of the TCPSocket connection. |
| off(type:&nbsp;'connect') | Disables listening for **connect** events of the TCPSocket connection. |


## How to Develop

The implementation is similar for UDPSocket and TCPSocket. The following uses the TCPSocket as an example.

1. Import the required Socket module.

2. Create a **TCPSocket** object.

3. (Optional) Enable listening for TCPSocket events.

4. Bind the IP address and port number. The port number can be specified or randomly allocated by the system.

5. Set up a connection to the specified IP address and port number.

6. Send data.

7. Enable the TCPSocket connection to be automatically closed after use.
   
   ```js
   import socket from '@ohos.net.socket'
   
   // Create a TCPSocket object.
   let tcp = socket.constructTCPSocketInstance();
   
   // Enable listening for TCPSocket events.
   tcp.on('message', value => {
       console.log("on message")
       let buffer = value.message
       let dataView = new DataView(buffer)
       let str = ""
       for (let i = 0;i < dataView.byteLength; ++i) {
           str += String.fromCharCode(dataView.getUint8(i))
       }
       console.log("on connect received:" + str)
   });
   tcp.on('connect', () => {
       console.log("on connect")
   });
   tcp.on('close', () => {
       console.log("on close")
   });
   
   // Bind the IP address and port number.
   let bindAddress = {
       address: '192.168.xx.xx',
       port: 1234, // Bound port, for example, 1234.
       family: 1
   };
   tcp.bind(bindAddress, err => {
       if (err) {
           console.log('bind fail');
           return;
       }
       console.log('bind success');
       // Set up a connection to the specified IP address and port number.
       let connectAddress = {
           address: '192.168.xx.xx',
           port: 5678, // Connection port, for example, 5678.
           family: 1
       };
       tcp.connect({
           address: connectAddress, timeout: 6000
       }, err => {
           if (err) {
               console.log('connect fail');
               return;
           }
           console.log('connect success');
           // Send data.
           tcp.send({
               data: 'Hello, server!'
           }, err => {
               if (err) {
                   console.log('send fail');
                   return;
               }
               console.log('send success');
           })
       });
   });
   // Enable the TCPSocket connection to be automatically closed after use. Then, disable listening for TCPSocket events.
   setTimeout(() => {
       tcp.close((err) => {
           console.log('close socket.')
       });
       tcp.off('message');
       tcp.off('connect');
       tcp.off('close');
   }, 30 * 1000);
   ```

## Samples
The following sample is provided to help you better understand how to develop the socket connection feature:
- [`Socket`: Socket Connection (eTS) (API 8)](https://gitee.com/openharmony/app_samples/tree/master/Network/Socket)
