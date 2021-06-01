# Initializing a Modem Vendor Library<a name="EN-US_TOPIC_0000001149333801"></a>

-   [When to Use](#section219mcpsimp)
-   [Available APIs](#section225mcpsimp)
-   [How to Develop](#section1432655815216)
-   [\(Optional\) Commissioning and Verification](#section268mcpsimp)

## When to Use<a name="section219mcpsimp"></a>

Initializing a modem vendor library refers to implementing of the  **const VendorCallbacks \*RilInit\(const struct RIL\_Init\_Env \*env\)**  function in the vendor library. This function is mainly used to:

-   Receive pointers to callbacks for modem events. When there is a modem event that needs to be reported, the target pointer will be called to report the event to the RIL Adapter.
-   Create a thread for reading modem nodes. In this thread, the data reported by the modem is read cyclically and parsed as a specific event.
-   Return pointers to functions used for service requests, execution results of service requests, and modem event reporting to the RIL Adapter.

## Available APIs<a name="section225mcpsimp"></a>

The following table describes the API for initializing a modem vendor library.

**Table  1**  API for initializing a modem vendor library

<a name="table228mcpsimp"></a>
<table><thead align="left"><tr id="row234mcpsimp"><th class="cellrowborder" valign="top" width="56.99999999999999%" id="mcps1.2.3.1.1"><p id="p236mcpsimp"><a name="p236mcpsimp"></a><a name="p236mcpsimp"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="43%" id="mcps1.2.3.1.2"><p id="p238mcpsimp"><a name="p238mcpsimp"></a><a name="p238mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row240mcpsimp"><td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.3.1.1 "><p id="p242mcpsimp"><a name="p242mcpsimp"></a><a name="p242mcpsimp"></a>const VendorCallbacks *RilInit(const struct RIL_Init_Env *env)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.3.1.2 "><p id="p244mcpsimp"><a name="p244mcpsimp"></a><a name="p244mcpsimp"></a>Entry for running a modem vendor library</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section1432655815216"></a>

1.  Set the pointers to callbacks passed by RIL Adapter through  **RilInit**.

    ```
    static struct RIL_Init_Env g_rilEnv = {
        OnRequestResponse,
        OnRadioEventNotify,
        OnReqTimerExpiredCallback,
        OnAsyncReqAck
    };
    s_rilenv = env;
    ```

2.  Create the  **s\_tid\_main**  thread to enable message loop.

    ```
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); 
    ret = pthread_create(&s_tid_main, &attr, MainRunner, NULL);
    ```

3.  In the  **s\_tid\_main**  thread, use  **open\(\)**  to open a modem node and then create the  **s\_tid\_read**  thread to read and process the messages reported by the modem.

    ```
    open(s_device_path, O_RDWR); // s_device_path indicates a modem node.
    pthread_attr_init(&attr); 
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); 
    ret = pthread_create(&s_tid_read, &attr, ReadRunner, &attr);
    ```

4.  Return pointers to functions used for service requests, execution results of service requests, and modem event reporting.

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


## \(Optional\) Commissioning and Verification<a name="section268mcpsimp"></a>

1.  Use the  **HDC**  tool to connect to a commissioning device, and run the  **hdc file send**  command to send the generated  **libvendor.z.so**  library file to the  **/system/lib/**  directory.
2.  Run the  **hdc shell sync**  and  **hdc shell reboot**  commands to restart the device.
3.  Run the  **hdc shell hilog**  command to check whether  **RilInit\(\)**  is successfully executed based on the log information.

