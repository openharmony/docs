# Modem厂商库初始化开发指导<a name="ZH-CN_TOPIC_0000001149333801"></a>

-   [场景介绍](#section219mcpsimp)
-   [接口说明](#section225mcpsimp)
-   [开发步骤](#section1432655815216)
-   [调测验证（可选）](#section268mcpsimp)

## 场景介绍<a name="section219mcpsimp"></a>

Modem厂商库初始化是指在厂商库里实现const VendorCallbacks \*RilInit\(const struct RIL\_Init\_Env \*env\)函数，在该函数里处理三个重要的功能：

-   接收RIL Adapter事件回调的函数指针，当Modem有事件上报时，调用对应的函数指针，把事件上报给RIL Adapter。
-   创建读取Modem设备节点的线程，在该线程里会循环地读取Modem上报的事件，并把接收的Modem信息解析为具体事件上报。
-   返回业务请求接口、业务请求执行结果的接口和Modem事件上报接口的函数指针给RIL Adapter。

## 接口说明<a name="section225mcpsimp"></a>

Modem厂商库初始化接口。

**表 1**  Modem厂商库初始化接口功能介绍

<a name="table228mcpsimp"></a>
<table><thead align="left"><tr id="row234mcpsimp"><th class="cellrowborder" valign="top" width="56.99999999999999%" id="mcps1.2.3.1.1"><p id="p236mcpsimp"><a name="p236mcpsimp"></a><a name="p236mcpsimp"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="43%" id="mcps1.2.3.1.2"><p id="p238mcpsimp"><a name="p238mcpsimp"></a><a name="p238mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row240mcpsimp"><td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.3.1.1 "><p id="p242mcpsimp"><a name="p242mcpsimp"></a><a name="p242mcpsimp"></a>const  VendorCallbacks *RilInit(const struct RIL_Init_Env *env)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.3.1.2 "><p id="p244mcpsimp"><a name="p244mcpsimp"></a><a name="p244mcpsimp"></a>该接口为Modem厂商库运行的入口</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section1432655815216"></a>

1.  RilInit接口中设置RIL Adapter传入的事件回调函数指针。

    ```
    static struct RIL_Init_Env g_rilEnv = {
        OnRequestResponse,
        OnRadioEventNotify,
        OnReqTimerExpiredCallback,
        OnAsyncReqAck
    };
    s_rilenv = env;
    ```

2.  创建主线程s\_tid\_main，开启消息循环。

    ```
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); 
    ret = pthread_create(&s_tid_main, &attr, MainRunner, NULL);
    ```

3.  在s\_tid\_main线程用open\(\)打开Modem设备节点，并创建s\_tid\_read线程循环读取处理Modem上报的消息。

    ```
    open(s_device_path, O_RDWR); // s_device_path为Modem设备节点        
    pthread_attr_init(&attr); 
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); 
    ret = pthread_create(&s_tid_read, &attr, ReadRunner, &attr);
    ```

4.  返回业务请求接口、业务请求执行结果的接口和Modem事件上报接口的函数指针。

    ```
    static const RIL_RadioFunctions g_callbacks = {
        RIL_VERSION,
        OnRequest,
        CurrentState,
        OnSupports,
        OnCancel,
        GetVersion
    };
    return &g_callbacks;
    ```


## 调测验证（可选）<a name="section268mcpsimp"></a>

1.  用hdc工具连接调试设备，把编译生成的libvendor.z.so库文件通过hdc file send推到/system/lib/目录下。
2.  执行hdc shell sync, hdc shell reboot重启设备。
3.  hdc shell后输入hilog命令，查看RilInit\(\)是否正确执行完成，根据日志信息判断是否成功。

