# Modem业务请求及响应开发指导<a name="ZH-CN_TOPIC_0000001149293857"></a>

-   [场景介绍](#section273mcpsimp)
-   [接口说明](#section276mcpsimp)
-   [开发步骤](#section532835815524)
-   [调测验证（可选）](#section332mcpsimp)

## 场景介绍<a name="section273mcpsimp"></a>

Modem业务请求及响应是指RIL Adapter收到电话服务具体业务请求后，调用Modem厂商库初始化获得的函数指针，把具体业务请求发送给厂商库，厂商库根据业务请求ID做相应的业务处理。

## 接口说明<a name="section276mcpsimp"></a>

Modem业务请求及响应接口。

**表 1**  Modem业务请求及响应接口功能介绍

<a name="table279mcpsimp"></a>
<table><thead align="left"><tr id="row285mcpsimp"><th class="cellrowborder" valign="top" width="56.99999999999999%" id="mcps1.2.3.1.1"><p id="p287mcpsimp"><a name="p287mcpsimp"></a><a name="p287mcpsimp"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="43%" id="mcps1.2.3.1.2"><p id="p289mcpsimp"><a name="p289mcpsimp"></a><a name="p289mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row291mcpsimp"><td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.3.1.1 "><p id="p293mcpsimp"><a name="p293mcpsimp"></a><a name="p293mcpsimp"></a>static void</p>
<p id="p294mcpsimp"><a name="p294mcpsimp"></a><a name="p294mcpsimp"></a>OnRequest(int request, void *data, size_t datalen, RIL_Token t)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.3.1.2 "><p id="p296mcpsimp"><a name="p296mcpsimp"></a><a name="p296mcpsimp"></a>该接口对具体业务请求进行分发处理</p>
</td>
</tr>
<tr id="row297mcpsimp"><td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.3.1.1 "><p id="p299mcpsimp"><a name="p299mcpsimp"></a><a name="p299mcpsimp"></a>void OnRequestResponse(RIL_Token t, RIL_Errno e, void *response, size_t responselen);</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.3.1.2 "><p id="p301mcpsimp"><a name="p301mcpsimp"></a><a name="p301mcpsimp"></a>该接口对业务执行结果进行响应，即当请求业务执行完成后，Modem根据该请求执行的结果上报给RIL Adapter</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section532835815524"></a>

1.  在OnRequest\(\)接口里根据业务请求ID进行分发。

    ```
    switch (request) {
        case HREQ_CALL_DIAL:
            SendDialRequest(data, datalen, t);
            break;
        case HREQ_CALL_HANGUP:
            SendHangupRequest(data, datalen, t);
            break;
            ……
        default：
            break;
    }
    ```

2.  在Modem执行业务请求完成后，调用OnRequestResponse\(\)回调函数，把事件上报给RIL Adapter。

    ```
    asprintf(&cmd, "ATD%s%s;", dial->address, clir);
    ret = send_at_request(cmd, NULL);
    free(cmd);
    OnRequestResponse(t, RIL_RESULT_SUCCESS, NULL, 0);
    ```


## 调测验证（可选）<a name="section332mcpsimp"></a>

1.  用hdc工具连接调试设备，把编译生成的libvendor.z.so库文件通过hdc file send推到/system/lib/目录下。
2.  执行hdc shell sync, hdc shell reboot重启设备。
3.  hdc shell后输入hilog命令，查看OnRequest\(\)是否正确执行完成，根据日志信息判断是否成功。

