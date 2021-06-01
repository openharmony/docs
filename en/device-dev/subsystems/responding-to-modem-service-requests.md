# Responding to Modem Service Requests<a name="EN-US_TOPIC_0000001149293857"></a>

-   [When to Use](#section273mcpsimp)
-   [Available APIs](#section276mcpsimp)
-   [How to Develop](#section532835815524)
-   [\(Optional\) Commissioning and Verification](#section332mcpsimp)

## When to Use<a name="section273mcpsimp"></a>

After receiving a specific telephony service request, the RIL Adapter calls the target function pointer obtained in modem vendor library initialization to send a specific service request to the vendor library. Then the vendor library processes the request based on the request ID.

## Available APIs<a name="section276mcpsimp"></a>

The following table describes the APIs for responding to modem service requests.

**Table  1**  APIs for responding to modem service requests

<a name="table279mcpsimp"></a>
<table><thead align="left"><tr id="row285mcpsimp"><th class="cellrowborder" valign="top" width="56.99999999999999%" id="mcps1.2.3.1.1"><p id="p287mcpsimp"><a name="p287mcpsimp"></a><a name="p287mcpsimp"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="43%" id="mcps1.2.3.1.2"><p id="p289mcpsimp"><a name="p289mcpsimp"></a><a name="p289mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row291mcpsimp"><td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.3.1.1 "><p id="p293mcpsimp"><a name="p293mcpsimp"></a><a name="p293mcpsimp"></a>static void</p>
<p id="p294mcpsimp"><a name="p294mcpsimp"></a><a name="p294mcpsimp"></a>OnRequest(int request, void *data, size_t datalen, RIL_Token t)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.3.1.2 "><p id="p296mcpsimp"><a name="p296mcpsimp"></a><a name="p296mcpsimp"></a>Distributes service requests.</p>
</td>
</tr>
<tr id="row297mcpsimp"><td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.3.1.1 "><p id="p299mcpsimp"><a name="p299mcpsimp"></a><a name="p299mcpsimp"></a>void OnRequestResponse(RIL_Token t, RIL_Errno e, void *response, size_t responselen);</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.3.1.2 "><p id="p301mcpsimp"><a name="p301mcpsimp"></a><a name="p301mcpsimp"></a>Reports the execution result of a service request to RIL Adapter.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section532835815524"></a>

1.  Distribute service requests based on request IDs through  **OnRequest\(\)**.

    ```
    switch (request) {
        case HREQ_CALL_DIAL:
            SendDialRequest(data, datalen, t);
            break;
        case HREQ_CALL_HANGUP:
            SendHangupRequest(data, datalen, t);
            break;
            ...
        default:
            break;
    }
    ```

2.  After a modem executes a service request, call  **OnRequestResponse\(\)**  to report the target event to RIL Adapter.

    ```
    asprintf(&cmd, "ATD%s%s;", dial->address, clir);
    ret = send_at_request(cmd, NULL);
    free(cmd);
    OnRequestResponse(t, RIL_RESULT_SUCCESS, NULL, 0);
    ```


## \(Optional\) Commissioning and Verification<a name="section332mcpsimp"></a>

1.  Use the  **HDC**  tool to connect to a commissioning device, and run the  **hdc file send**  command to send the generated  **libvendor.z.so**  library file to the  **/system/lib/**  directory.
2.  Run the  **hdc shell sync**  and  **hdc shell reboot**  commands to restart the device.
3.  Run the  **hdc shell hilog**  command to check whether  **OnRequest\(\)**  is successfully executed based on the log information.

