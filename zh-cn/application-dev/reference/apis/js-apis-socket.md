# Socket连接<a name="ZH-CN_TOPIC_0000001181612734"></a>

-   [支持设备](#section11223131205610)
-   [导入模块](#s56d19203690d4782bfc74069abb6bd71)
-   [权限列表](#section11257113618419)
-   [socket.constructUDPSocketInstance](#section375081875219)
-   [UDPSocket](#section1957294511568)
    -   [bind](#section7382103811272)
    -   [bind](#section12433131831219)
    -   [send](#section1859172655111)
    -   [send](#section61591275527)
    -   [close](#section068563155214)
    -   [close](#section1788163335319)
    -   [getState](#section1028719549533)
    -   [getState](#section1333814412551)
    -   [setExtraOptions](#section16890953175514)
    -   [setExtraOptions](#section5493159165611)
    -   [on\('message'\)](#section1632573015551)
    -   [off\('message'\)](#section789519374558)
    -   [on\('listening' | 'close'\)](#section20461174410557)
    -   [off\('listening' | 'close'\)](#section649105218559)
    -   [on\('error'\)](#section16745135855515)
    -   [off\('error'\)](#section49111157568)

-   [NetAddress](#section159132241295)
-   [UDPSendOptions](#section13297558184010)
-   [UDPExtraOptions](#section1650575184117)
-   [SocketStateBase](#section164609984111)
-   [SocketRemoteInfo](#section46021613174115)
-   [socket.constructTCPSocketInstance](#section283119484161)
-   [TCPSocket](#section1180211014548)
    -   [bind](#section8465924145710)
    -   [bind](#section27150134582)
    -   [connect](#section82761299586)
    -   [connect](#section374992304)
    -   [send](#section74991317709)
    -   [send](#section2841321507)
    -   [close](#section71701043701)
    -   [close](#section13523755306)
    -   [getRemoteAddress](#section1268431414115)
    -   [getRemoteAddress](#section89019337116)
    -   [getState](#section830554511115)
    -   [getState](#section3460522026)
    -   [setExtraOptions](#section738911419219)
    -   [setExtraOptions](#section1847278215)
    -   [on\('message'\)](#section642292019182)
    -   [off\('message'\)](#section8426920151811)
    -   [on\('connect' | 'close'\)](#section6429202001812)
    -   [off\('connect' | 'close'\)](#section54325209187)
    -   [on\('error'\)](#section19436172061817)
    -   [off\('error'\)](#section6438202013182)

-   [TCPConnectOptions](#section13821005712)
-   [TCPSendOptions](#section1689232415715)
-   [TCPExtraOptions](#section13892555115718)

>![](public_sys-resources/icon-note.gif) **说明：** 
>
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>本模块所有接口需要设备具有系统能力：SystemCapability.Communication.NetStack

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import socket from '@ohos.net.socket';
```

## 权限列表<a name="section11257113618419"></a>

ohos.permission.INTERNET

## socket.constructUDPSocketInstance<a name="section375081875219"></a>

constructUDPSocketInstance\(\): UDPSocket

创建一个UDPSocket对象。

- 返回值

  | 类型                               | 说明                    |
  | :--------------------------------- | :---------------------- |
  | [UDPSocket](#section1957294511568) | 返回一个UDPSocket对象。 |


-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    ```


## UDPSocket<a name="section1957294511568"></a>

UDPSocket连接。在调用UDPSocket的方法前，需要先通过[socket.constructUDPSocketInstance](#section375081875219)创建UDPSocket对象。

### bind<a name="section7382103811272"></a>

bind\(address: NetAddress, callback: AsyncCallback<void\>\): void

绑定IP地址和端口，端口可以指定或由系统随机分配。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                               | 必填 | 说明                                                   |
  | -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
  | address  | [NetAddress](#section159132241295) | 是   | 目标地址信息，参考[NetAddress](#section159132241295)。 |
  | callback | AsyncCallback\<void\>              | 是   | 回调函数。                                             |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    udp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1}, err => {
      if (err) {
        console.log('bind fail');
        return;
      }
      console.log('bind success');
    })
    ```


### bind<a name="section12433131831219"></a>

bind\(address: NetAddress\): Promise<void\>

绑定IP地址和端口，端口可以指定或由系统随机分配。使用Promise方式作为异步方法。

-   参数

      | 参数名   | 类型                               | 必填 | 说明                                                   |
  | -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
  | address  | [NetAddress](#section159132241295) | 是   | 目标地址信息，参考[NetAddress](#section159132241295)。 |
  | callback | AsyncCallback\<void\>              | 是   | 回调函数。                                             |


- 返回值

  | 类型            | 说明                                       |
  | :-------------- | :----------------------------------------- |
  | Promise\<void\> | 以Promise形式异步返回UDPSocket绑定的结果。 |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    let promise = udp.bind({address: '192.168.xx.xxx', port: 8080, family: 1});
    promise .then(() => {
      console.log('bind success');
    }).catch(err => {
      console.log('bind fail');
    });
    ```


### send<a name="section1859172655111"></a>

send\(options: UDPSendOptions, callback: AsyncCallback<void\>\): void

通过UDPSocket连接发送数据。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                                     | 必填 | 说明                                                         |
  | -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
  | options  | [UDPSendOptions](#section13297558184010) | 是   | UDPSocket发送参数，参考[UDPSendOptions](#section13297558184010)。 |
  | callback | AsyncCallback\<void\>                    | 是   | 回调函数。                                                   |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    udp.send({
      data:'Hello, server!',
      address: {
        address:'192.168.xx.xxx',
        port:xxxx,
        family:1
      }
    }, err=> {
        if (err) {
          console.log('send fail');
          return;
        }
        console.log('send success');
    })
    ```


### send<a name="section61591275527"></a>

send\(options: UDPSendOptions\): Promise<void\>

通过UDPSocket连接发送数据。使用Promise方式作为异步方法。

-   参数

  | 参数名  | 类型                                     | 必填 | 说明                                                         |
  | ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
  | options | [UDPSendOptions](#section13297558184010) | 是   | UDPSocket发送参数，参考[UDPSendOptions](#section13297558184010)。 |
  
- 返回值

  | 类型            | 说明                                           |
  | :-------------- | :--------------------------------------------- |
  | Promise\<void\> | 以Promise形式返回UDPSocket连接发送数据的结果。 |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    let promise = udp.send({
      data:'Hello, server!',
      address: {
        address:'192.168.xx.xxx',
        port:xxxx,
        family:1
      }
    });
    promise.then(() => {
      console.log('send success');
    }).catch(err => {
      console.log('send fail');
    });
    ```


### close<a name="section068563155214"></a>

close\(callback: AsyncCallback<void\>\): void

关闭UDPSocket连接。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                  | 必填 | 说明       |
  | -------- | --------------------- | ---- | ---------- |
  | callback | AsyncCallback\<void\> | 是   | 回调函数。 |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    udp.close(err => {
      if (err) {
        console.log('close fail');
        return;
      }
      console.log('close success');
    })
    ```


### close<a name="section1788163335319"></a>

close\(\): Promise<void\>

关闭UDPSocket连接。使用Promise方式作为异步方法。

- 返回值

  | 类型            | 说明                                       |
  | :-------------- | :----------------------------------------- |
  | Promise\<void\> | 以Promise形式返回关闭UDPSocket连接的结果。 |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    let promise = udp.close();
    promise.then(() => {
      console.log('close success');
    }).catch(err => {
      console.log('close fail');
    });
    ```


### getState<a name="section1028719549533"></a>

getState\(callback: AsyncCallback<SocketStateBase\>\): void

获取UDPSocket状态。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#section7382103811272)方法调用成功后，才可调用此方法。

- 参数

  | 参数名   | 类型                                                   | 必填 | 说明       |
  | -------- | ------------------------------------------------------ | ---- | ---------- |
  | callback | AsyncCallback<[SocketStateBase](#section164609984111)> | 是   | 回调函数。 |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    udp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1}, err => {
      if (err) {
        console.log('bind fail');
        return;
      }
      console.log('bind success');
      udp.getState((err, data) => {
        if (err) {
          console.log('getState fail');
          return;
        }
        console.log('getState success:' + JSON.stringify(data));
      })
    })
    ```


### getState<a name="section1333814412551"></a>

getState\(\): Promise<SocketStateBase\>

获取UDPSocket状态。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#section7382103811272)方法调用成功后，才可调用此方法。

- 返回值

  | 类型                                             | 说明                                       |
  | :----------------------------------------------- | :----------------------------------------- |
  | Promise<[SocketStateBase](#section164609984111)> | 以Promise形式返回获取UDPSocket状态的结果。 |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    udp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1}, err => {
      if (err) {
        console.log('bind fail');
        return;
      }
      console.log('bind success');
      let promise = udp.getState({});
      promise.then(data => {
        console.log('getState success:' + JSON.stringify(data));
      }).catch(err => {
        console.log('getState fail');
      });
    })
    ```


### setExtraOptions<a name="section16890953175514"></a>

setExtraOptions\(options: UDPExtraOptions, callback: AsyncCallback<void\>\): void

设置UDPSocket连接的其他属性。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#section7382103811272)方法调用成功后，才可调用此方法。

- 参数

  | 参数名   | 类型                                     | 必填 | 说明                                                         |
  | -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
  | options  | [UDPExtraOptions](#section1650575184117) | 是   | UDPSocket连接的其他属性，参考[UDPExtraOptions](#section1650575184117)。 |
  | callback | AsyncCallback\<void\>                    | 是   | 回调函数。                                                   |


-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    udp.bind({address:'192.168.xx.xxx', port:xxxx, family:1}, err=> {
      if (err) {
        console.log('bind fail');
        return;
      }
      console.log('bind success');
      udp.setExtraOptions({
        receiveBufferSize:1000,
        sendBufferSize:1000,
        reuseAddress:false,
        socketTimeout:6000,
        broadcast:true
      }, err=> {
        if (err) {
          console.log('setExtraOptions fail');
          return;
        }
        console.log('setExtraOptions success');
      })
    })
    ```


### setExtraOptions<a name="section5493159165611"></a>

setExtraOptions\(options: UDPExtraOptions\): Promise<void\>

设置UDPSocket连接的其他属性。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#section7382103811272)方法调用成功后，才可调用此方法。

- 参数

  | 参数名  | 类型                                     | 必填 | 说明                                                         |
  | ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
  | options | [UDPExtraOptions](#section1650575184117) | 是   | UDPSocket连接的其他属性，参考[UDPExtraOptions](#section1650575184117)。 |

- 返回值

  | 类型            | 说明                                                 |
  | :-------------- | :--------------------------------------------------- |
  | Promise\<void\> | 以Promise形式返回设置UDPSocket连接的其他属性的结果。 |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    let promise = udp.bind({address:'192.168.xx.xxx', port:xxxx, family:1});
    promise.then(() => {
      console.log('bind success');
      let promise1 = udp.setExtraOptions({
        receiveBufferSize:1000,
        sendBufferSize:1000,
        reuseAddress:false,
        socketTimeout:6000,
        broadcast:true
      });
      promise1.then(() => {
        console.log('setExtraOptions success');
      }).catch(err => {
        console.log('setExtraOptions fail');
      });
    }).catch(err => {
      console.log('bind fail');
    });
    ```


### on\('message'\)<a name="section1632573015551"></a>

on\(type: 'message', callback: Callback<\{message: ArrayBuffer, remoteInfo: SocketRemoteInfo\}\>\): void

订阅UDPSocket连接的接收消息事件。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                                                         | 必填 | 说明                                      |
  | -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
  | type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
  | callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#section46021613174115)}> | 是   | 回调函数。                                |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    udp.on('message', value => {
        console.log("on message, message:" + value.message) + ", remoteInfo:" + value.remoteInfo);
    });
    ```


### off\('message'\)<a name="section789519374558"></a>

off\(type: 'message', callback?: Callback<\{message: ArrayBuffer, remoteInfo: SocketRemoteInfo\}\>\): void

取消订阅UDPSocket连接的接收消息事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

-   参数

  | 参数名   | 类型                                                         | 必填 | 说明                                      |
  | -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
  | type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
  | callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#section46021613174115)}> | 否   | 回调函数。                                |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    let callback = value =>{
        console.log("on message, message:" + value.message) + ", remoteInfo:" + value.remoteInfo);
    }
    udp.on('message', callback);
    // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
    udp.off('message', callback);
    udp.off('message');
    ```


### on\('listening' | 'close'\)<a name="section20461174410557"></a>

on\(type: 'listening' | 'close', callback: Callback<void\>\): void

订阅UDPSocket连接的数据包消息事件或关闭事件。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型             | 必填 | 说明                                                         |
  | -------- | ---------------- | ---- | ------------------------------------------------------------ |
  | type     | string           | 是   | 订阅的事件类型。<br />- 'listening'：数据包消息事件。<br />- 'close'：关闭事件。 |
  | callback | Callback\<void\> | 是   | 回调函数。                                                   |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    udp.on('listening', () => {
        console.log("on listening success"));
    });
    udp.on('close', () => {
        console.log("on close success" );
    });
    ```


### off\('listening' | 'close'\)<a name="section649105218559"></a>

off\(type: 'listening' | 'close', callback?: Callback<void\>\): void

取消订阅UDPSocket连接的数据包消息事件或关闭事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

- 参数

  | 参数名   | 类型             | 必填 | 说明                                                         |
  | -------- | ---------------- | ---- | ------------------------------------------------------------ |
  | type     | string           | 是   | 订阅事件类型。<br />- 'listening'：数据包消息事件。<br />- 'close'：关闭事件。 |
  | callback | Callback\<void\> | 否   | 回调函数。                                                   |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance();
    let callback1 = () =>{
        console.log("on listening, success");
    }
    udp.on('listening', callback1);
    // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
    udp.off('listening', callback1);
    udp.off('listening');
    let callback2 = () =>{
        console.log("on close, success");
    }
    udp.on('close', callback2);
    // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
    udp.off('close', callback2);
    udp.off('close');
    ```


### on\('error'\)<a name="section16745135855515"></a>

on\(type: 'error', callback: ErrorCallback\): void

订阅UDPSocket连接的error事件。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型          | 必填 | 说明                                 |
  | -------- | ------------- | ---- | ------------------------------------ |
  | type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
  | callback | ErrorCallback | 是   | 回调函数。                           |


-   示例

    ```
    let udp = socket.constructUDPSocketInstance()
    udp.on('error', err => {
        console.log("on error, err:" + JSON.stringify(err))
    });
    ```


### off\('error'\)<a name="section49111157568"></a>

off\(type: 'error', callback?: ErrorCallback\): void

取消订阅UDPSocket连接的error事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

- 参数

  | 参数名   | 类型          | 必填 | 说明                                 |
  | -------- | ------------- | ---- | ------------------------------------ |
  | type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
  | callback | ErrorCallback | 否   | 回调函数。                           |

-   示例

    ```
    let udp = socket.constructUDPSocketInstance()
    let callback = err =>{
        console.log("on error, err:" + JSON.stringify(err));
    }
    udp.on('error', callback);
    // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
    udp.off('error', callback);
    udp.off('error');
    ```


## NetAddress<a name="section159132241295"></a>

目标地址信息。

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | 是   | 本地绑定的ip地址。                                           |
| port    | number | 否   | 端口号 ，范围0~65535。如果不指定系统随机分配端口。           |
| family  | number | 否   | 网络协议类型，可选类型：<br />- 1：IPv4<br />- 2：IPv6<br />默认为1。 |

## UDPSendOptions<a name="section13297558184010"></a>

UDPSocket发送参数。

| 参数名  | 类型                               | 必填 | 说明           |
| ------- | ---------------------------------- | ---- | -------------- |
| data    | string                             | 是   | 发送的数据。   |
| address | [NetAddress](#section159132241295) | 是   | 目标地址信息。 |

## UDPExtraOptions<a name="section1650575184117"></a>

UDPSocket连接的其他属性。

| 参数名            | 类型    | 必填 | 说明                             |
| ----------------- | ------- | ---- | -------------------------------- |
| broadcast         | boolean | 否   | 是否可以发送广播。默认为false。  |
| receiveBufferSize | number  | 否   | 接收缓冲区大小（单位：Byte）。   |
| sendBufferSize    | number  | 否   | 发送缓冲区大小（单位：Byte）。   |
| reuseAddress      | boolean | 否   | 是否重用地址。默认为false。      |
| socketTimeout     | number  | 否   | 套接字超时时间，单位毫秒（ms）。 |

## SocketStateBase<a name="section164609984111"></a>

Socket的状态信息。

| 参数名      | 类型    | 必填 | 说明       |
| ----------- | ------- | ---- | ---------- |
| isBound     | boolean | 是   | 是否绑定。 |
| isClose     | boolean | 是   | 是否关闭。 |
| isConnected | boolean | 是   | 是否连接。 |

## SocketRemoteInfo<a name="section46021613174115"></a>

Socket的连接信息。

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | 是   | 本地绑定的ip地址。                                           |
| family  | string | 是   | 网络协议类型，可选类型：<br />- IPv4<br />- IPv6<br />默认为IPv4。 |
| port    | number | 是   | 端口号，范围0~65535。                                        |
| size    | number | 是   | 服务器响应信息的字节长度。                                   |

## socket.constructTCPSocketInstance<a name="section283119484161"></a>

constructTCPSocketInstance\(\): TCPSocket

创建一个TCPSocket对象。

- 返回值

  | 类型                               | 说明                    |
  | :--------------------------------- | :---------------------- |
  | [TCPSocket](#section1180211014548) | 返回一个TCPSocket对象。 |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    ```


## TCPSocket<a name="section1180211014548"></a>

TCPSocket连接。在调用TCPSocket的方法前，需要先通过[socket.constructTCPSocketInstance](#section283119484161)创建TCPSocket对象。

### bind<a name="section8465924145710"></a>

bind\(address: NetAddress, callback: AsyncCallback<void\>\): void

绑定IP地址和端口，端口可以指定或由系统随机分配。使用callback方法作为异步方法。

- 参数

  | 参数名   | 类型                               | 必填 | 说明                                                   |
  | -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
  | address  | [NetAddress](#section159132241295) | 是   | 目标地址信息，参考[NetAddress](#section159132241295)。 |
  | callback | AsyncCallback\<void\>              | 是   | 回调函数。                                             |


-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    tcp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1}, err => {
      if (err) {
        console.log('bind fail');
        return;
      }
      console.log('bind success');
    })
    ```


### bind<a name="section27150134582"></a>

bind\(address NetAddress\): Promise<void\>

绑定IP地址和端口，端口可以指定或由系统随机分配。使用Promise方法作为异步方法。

-   参数

  | 参数名  | 类型                               | 必填 | 说明                                                   |
  | ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
  | address | [NetAddress](#section159132241295) | 是   | 目标地址信息，参考[NetAddress](#section159132241295)。 |


- 返回值

  | 类型            | 说明                                                     |
  | :-------------- | :------------------------------------------------------- |
  | Promise\<void\> | 以Promise形式返回TCPSocket绑定本机的IP地址和端口的结果。 |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise = tcp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1});
    promise.then(() => {
      console.log('bind success');
    }).catch(err => {
      console.log('bind fail');
    });
    ```


### connect<a name="section82761299586"></a>

connect\(options: TCPConnectOptions, callback: AsyncCallback<void\>\): void

连接到指定的IP地址和端口。使用callback方法作为异步方法。

- 参数

  | 参数名   | 类型                                     | 必填 | 说明                                                         |
  | -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
  | options  | [TCPConnectOptions](#section13821005712) | 是   | TCPSocket连接的参数，参考[TCPConnectOptions](#section13821005712)。 |
  | callback | AsyncCallback\<void\>                    | 是   | 回调函数。                                                   |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000}, err => {
      if (err) {
        console.log('connect fail');
        return;
      }
      console.log('connect success');
    })
    ```


### connect<a name="section374992304"></a>

connect\(options: TCPConnectOptions\): Promise<void\>

连接到指定的IP地址和端口。使用promise方法作为异步方法。

-   参数

  | 参数名  | 类型                                     | 必填 | 说明                                                         |
  | ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
  | options | [TCPConnectOptions](#section13821005712) | 是   | TCPSocket连接的参数，参考[TCPConnectOptions](#section13821005712)。 |


- 返回值

  | 类型            | 说明                                                       |
  | :-------------- | :--------------------------------------------------------- |
  | Promise\<void\> | 以Promise形式返回TCPSocket连接到指定的IP地址和端口的结果。 |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
    promise.then(() => {
      console.log('connect success')
    }).catch(err => {
      console.log('connect fail');
    });
    ```


### send<a name="section74991317709"></a>

send\(options: TCPSendOptions, callback: AsyncCallback<void\>\): void

通过TCPSocket连接发送数据。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[connect](#section82761299586)方法调用成功后，才可调用此方法。

- 参数

  | 参数名   | 类型                                    | 必填 | 说明                                                         |
  | -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
  | options  | [TCPSendOptions](#section1689232415715) | 是   | TCPSocket发送请求的参数，参考[TCPSendOptions](#section1689232415715)。 |
  | callback | AsyncCallback\<void\>                   | 是   | 回调函数。                                                   |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
    promise.then(() => {
      console.log('connect success');
      tcp.send({
        data:'Hello, server!'
      },err => {
        if (err) {
          console.log('send fail');
          return;
        }
        console.log('send success');
      })
    }).catch(err => {
      console.log('connect fail');
    });
    ```


### send<a name="section2841321507"></a>

send\(options: TCPSendOptions\): Promise<void\>

通过TCPSocket连接发送数据。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[connect](#section82761299586)方法调用成功后，才可调用此方法。

-   参数

  | 参数名  | 类型                                    | 必填 | 说明                                                         |
  | ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
  | options | [TCPSendOptions](#section1689232415715) | 是   | TCPSocket发送请求的参数，参考[TCPSendOptions](#section1689232415715)。 |
  
- 返回值

  | 类型            | 说明                                               |
  | :-------------- | :------------------------------------------------- |
  | Promise\<void\> | 以Promise形式返回通过TCPSocket连接发送数据的结果。 |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise1 = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
    promise1.then(() => {
      console.log('connect success');
      let promise2 = tcp.send({
        data:'Hello, server!'
      });
      promise2.then(() => {
        console.log('send success');
      }).catch(err => {
        console.log('send fail');
      });
    }).catch(err => {
      console.log('connect fail');
    });
    ```


### close<a name="section71701043701"></a>

close\(callback: AsyncCallback<void\>\): void

关闭TCPSocket连接。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                  | 必填 | 说明       |
  | -------- | --------------------- | ---- | ---------- |
  | callback | AsyncCallback\<void\> | 是   | 回调函数。 |


-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    tcp.close(err => {
      if (err) {
        console.log('close fail');
        return;
      }
      console.log('close success');
    })
    ```


### close<a name="section13523755306"></a>

close\(\): Promise<void\>

关闭TCPSocket连接。使用Promise方式作为异步方法。

- 返回值

  | 类型            | 说明                                       |
  | :-------------- | :----------------------------------------- |
  | Promise\<void\> | 以Promise形式返回关闭TCPSocket连接的结果。 |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise = tcp.close();
    promise.then(() => {
      console.log('close success');
    }).catch(err => {
      console.log('close fail');
    });
    ```


### getRemoteAddress<a name="section1268431414115"></a>

getRemoteAddress\(callback: AsyncCallback<NetAddress\>\): void

获取对端Socket地址。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[connect](#section82761299586)方法调用成功后，才可调用此方法。

- 参数

  | 参数名   | 类型                                              | 必填 | 说明       |
  | -------- | ------------------------------------------------- | ---- | ---------- |
  | callback | AsyncCallback<[NetAddress](#section159132241295)> | 是   | 回调函数。 |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
    promise.then(() => {
      console.log('connect success');
      tcp.getRemoteAddress((err, data) => {
        if (err) {
          console.log('getRemoteAddressfail');
          return;
        }
        console.log('getRemoteAddresssuccess:' + JSON.stringify(data));
      })
    }).catch(err => {
      console.log('connect fail');
    });
    ```


### getRemoteAddress<a name="section89019337116"></a>

getRemoteAddress\(\): Promise<NetAddress\>

获取对端Socket地址。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[connect](#section82761299586)方法调用成功后，才可调用此方法。

- 返回值

  | 类型                                        | 说明                                        |
  | :------------------------------------------ | :------------------------------------------ |
  | Promise<[NetAddress](#section159132241295)> | 以Promise形式返回获取对端socket地址的结果。 |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise1 = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
    promise1.then(() => {
      console.log('connect success');
      let promise2 = tcp.getRemoteAddress();
      promise2.then(() => {
        console.log('getRemoteAddress success:' + JSON.stringify(data));
      }).catch(err => {
        console.log('getRemoteAddressfail');
      });
    }).catch(err => {
      console.log('connect fail');
    });
    ```


### getState<a name="section830554511115"></a>

getState\(callback: AsyncCallback<SocketStateBase\>\): void

获取TCPSocket状态。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#section8465924145710)或[connect](#section82761299586)方法调用成功后，才可调用此方法。

- 参数

  | 参数名   | 类型                                                   | 必填 | 说明       |
  | -------- | ------------------------------------------------------ | ---- | ---------- |
  | callback | AsyncCallback<[SocketStateBase](#section164609984111)> | 是   | 回调函数。 |


-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
    promise.then(() => {
      console.log('connect success');
      tcp.getState((err, data) => {
        if (err) {
          console.log('getState fail');
          return;
        }
        console.log('getState success:' + JSON.stringify(data));
      });
    }).catch(err => {
      console.log('connect fail');
    });
    ```


### getState<a name="section3460522026"></a>

getState\(\): Promise<SocketStateBase\>

获取TCPSocket状态。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#section8465924145710)或[connect](#section82761299586)方法调用成功后，才可调用此方法。

- 返回值

  | 类型                                             | 说明                                       |
  | :----------------------------------------------- | :----------------------------------------- |
  | Promise<[SocketStateBase](#section164609984111)> | 以Promise形式返回获取TCPSocket状态的结果。 |


-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
    promise.then(() => {
      console.log('connect success');
      let promise1 = tcp.getState();
      promise1.then(() => {
        console.log('getState success:' + JSON.stringify(data));
      }).catch(err => {
        console.log('getState fail');
      });
    }).catch(err => {
      console.log('connect fail');
    });
    ```


### setExtraOptions<a name="section738911419219"></a>

setExtraOptions\(options: TCPExtraOptions, callback: AsyncCallback<void\>\): void

设置TCPSocket连接的其他属性。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#section8465924145710)或[connect](#section82761299586)方法调用成功后，才可调用此方法。

- 参数

  | 参数名   | 类型                                      | 必填 | 说明                                                         |
  | -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
  | options  | [TCPExtraOptions](#section13892555115718) | 是   | TCPSocket连接的其他属性，参考[TCPExtraOptions](#section13892555115718)。 |
  | callback | AsyncCallback\<void\>                     | 是   | 回调函数。                                                   |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
    promise.then(() => {
      console.log('connect success');
      tcp.setExtraOptions({
        keepAlive: true,
        OOBInline: true,
        TCPNoDelay: true,
        socketLinger: { on:true, linger:10 }
        receiveBufferSize: 1000,
        sendBufferSize: 1000,
        reuseAddress: true,
        socketTimeout: 3000,
      },err => {
        if (err) {
          console.log('setExtraOptions fail');
          return;
        }
        console.log('setExtraOptions success');
      });
    }).catch(err => {
      console.log('connect fail');
    });
    ```


### setExtraOptions<a name="section1847278215"></a>

setExtraOptions\(options: TCPExtraOptions\): Promise<void\>

设置TCPSocket连接的其他属性，使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#section8465924145710)或[connect](#section82761299586)方法调用成功后，才可调用此方法。

-   参数

  | 参数名  | 类型                                      | 必填 | 说明                                                         |
  | ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
  | options | [TCPExtraOptions](#section13892555115718) | 是   | TCPSocket连接的其他属性，参考[TCPExtraOptions](#section13892555115718)。 |


- 返回值

  | 类型            | 说明                                                 |
  | :-------------- | :--------------------------------------------------- |
  | Promise\<void\> | 以Promise形式返回设置TCPSocket连接的其他属性的结果。 |


-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
    promise.then(() => {
      console.log('connect success');
      let promise1 = tcp.setExtraOptions({
        keepAlive: true,
        OOBInline: true,
        TCPNoDelay: true,
        socketLinger: { on:true, linger:10 }
        receiveBufferSize: 1000,
        sendBufferSize: 1000,
        reuseAddress: true,
        socketTimeout: 3000,
      });
      promise1.then(() => {
        console.log('setExtraOptions success');
      }).catch(err => {
        console.log('setExtraOptions fail');
      });
    }).catch(err => {
      console.log('connect fail');
    });
    ```


### on\('message'\)<a name="section642292019182"></a>

on\(type: 'message', callback: Callback<\{message: ArrayBuffer, remoteInfo: SocketRemoteInfo\}\>\): void

订阅TCPSocket连接的接收消息事件。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                                                         | 必填 | 说明                                      |
  | -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
  | type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
  | callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#section46021613174115)}> | 是   | 回调函数。                                |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    tcp.on('message', value => {
        console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo)
    });
    ```


### off\('message'\)<a name="section8426920151811"></a>

off\(type: 'message', callback?: Callback<\{message: ArrayBuffer, remoteInfo: SocketRemoteInfo\}\>\): void

取消订阅TCPSocket连接的接收消息事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

-   参数

  | 参数名   | 类型                                                         | 必填 | 说明                                      |
  | -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
  | type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
  | callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#section46021613174115)}> | 否   | 回调函数。                                |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let callback = value =>{
        console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
    }
    tcp.on('message', callback);
    // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
    tcp.off('message', callback);
    tcp.off('message');
    ```


### on\('connect' | 'close'\)<a name="section6429202001812"></a>

on\(type: 'connect' | 'close', callback: Callback<void\>\): void

订阅TCPSocket的连接事件或关闭事件。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型             | 必填 | 说明                                                         |
  | -------- | ---------------- | ---- | ------------------------------------------------------------ |
  | type     | string           | 是   | 订阅的事件类型。<br />- 'connect'：连接事件。<br />- 'close'：关闭事件。 |
  | callback | Callback\<void\> | 是   | 回调函数。                                                   |


-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    tcp.on('connect', () => {
        console.log("on connect success")
    });
    tcp.on('close', data => {
        console.log("on close success")
    });
    ```


### off\('connect' | 'close'\)<a name="section54325209187"></a>

off\(type: 'connect' | 'close', callback: Callback<void\>\): void

取消订阅TCPSocket的连接事件或关闭事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

- 参数

  | 参数名   | 类型             | 必填 | 说明                                                         |
  | -------- | ---------------- | ---- | ------------------------------------------------------------ |
  | type     | string           | 是   | 订阅的事件类型。<br />- 'connect'：连接事件。<br />- 'close'：关闭事件。 |
  | callback | Callback\<void\> | 否   | 回调函数。                                                   |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let callback1 = () =>{
        console.log("on connect success");
    }
    tcp.on('connect', callback1);
    // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
    tcp.off('connect', callback1);
    tcp.off('connect');
    let callback2 = () =>{
        console.log("on close success");
    }
    tcp.on('close', callback2);
    // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
    tcp.off('close', callback2);
    tcp.off('close');
    ```


### on\('error'\)<a name="section19436172061817"></a>

on\(type: 'error', callback: ErrorCallback\): void

订阅TCPSocket连接的error事件。使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型          | 必填 | 说明                                 |
  | -------- | ------------- | ---- | ------------------------------------ |
  | type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
  | callback | ErrorCallback | 是   | 回调函数。                           |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    tcp.on('error', err => {
        console.log("on error, err:" + JSON.stringify(err))
    });
    ```


### off\('error'\)<a name="section6438202013182"></a>

off\(type: 'error', callback?: ErrorCallback\): void

取消订阅TCPSocket连接的error事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

-   参数

  | 参数名   | 类型          | 必填 | 说明                                 |
  | -------- | ------------- | ---- | ------------------------------------ |
  | type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
  | callback | ErrorCallback | 否   | 回调函数。                           |

-   示例

    ```
    let tcp = socket.constructTCPSocketInstance();
    let callback = err =>{
        console.log("on error, err:" + JSON.stringify(err));
    }
    tcp.on('error', callback);
    // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
    tcp.off('error', callback);
    tcp.off('error');
    ```


## TCPConnectOptions<a name="section13821005712"></a>

TCPSocket连接的参数。

| 参数名  | 类型                               | 必填 | 说明                       |
| ------- | ---------------------------------- | ---- | -------------------------- |
| address | [NetAddress](#section159132241295) | 是   | 绑定的地址以及端口。       |
| timeout | number                             | 否   | 超时时间，单位毫秒（ms）。 |

## TCPSendOptions<a name="section1689232415715"></a>

TCPSocket发送请求的参数。

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| data     | string | 是   | 发送的数据。                                                 |
| encoding | string | 否   | 字符编码(UTF-8，UTF-16BE，UTF-16LE，UTF-16，US-AECII，ISO-8859-1)，默认为UTF-8。 |

## TCPExtraOptions<a name="section13892555115718"></a>

TCPSocket连接的其他属性。

| 参数名            | 类型    | 必填 | 说明                                                         |
| ----------------- | ------- | ---- | ------------------------------------------------------------ |
| keepAlive         | boolean | 否   | 是否保持连接。默认为false。                                  |
| OOBInline         | boolean | 否   | 是否为OOB内联。默认为false。                                 |
| TCPNoDelay        | boolean | 否   | TCPSocket连接是否无时延。默认为false。                       |
| socketLinger      | Object  | 是   | socket是否继续逗留。<br />- on：是否逗留（true：逗留；false：不逗留）。<br />- linger：逗留时长，单位毫秒（ms），取值范围为0~65535。<br />当入参on设置为true时，才需要设置。 |
| receiveBufferSize | number  | 否   | 接收缓冲区大小（单位：Byte）。                               |
| sendBufferSize    | number  | 否   | 发送缓冲区大小（单位：Byte）。                               |
| reuseAddress      | boolean | 否   | 是否重用地址。默认为false。                                  |
| socketTimeout     | number  | 否   | 套接字超时时间，单位毫秒（ms）。                             |
