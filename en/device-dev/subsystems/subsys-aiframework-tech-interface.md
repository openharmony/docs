# API Development<a name="EN-US_TOPIC_0000001096100171"></a>

-   [Rule: Encapsulate the external APIs provided by the client based on the algorithm call sequence. For the SDK of an asynchronous plug-in, implement the IClientCb callback API provided by the client.](#section15872017171616)
-   [Rule: Save all common data related to client interaction in the SDK during API implementation.](#section011283741612)
-   [Recommendation: Enable the SDK to implement the IServiceDeadCb API defined by the client.](#section1199125331613)
-   [Rule: Convert dedicated algorithm data into common data of the AI engine if the SDK and plug-ins need to use the codec module.](#section93139389171)
-   [Rule: Release the memory used by the encoded or decoded parameters in the SDK. Otherwise, a memory leakage occurs.](#section1698441814183)
-   [Rule: Enable plug-ins to implement the IPlugin API defined by the server and use the PLUGIN\_INTERFACE\_IMPL statement to provide the function pointer for external systems.](#section20850717196)
-   [Rule: Use the unified data channel provided by the AI engine for plug-ins.](#section1493821732019)

## Rule: Encapsulate the external APIs provided by the client based on the algorithm call sequence. For the SDK of an asynchronous plug-in, implement the  **IClientCb**  callback API provided by the client.<a name="section15872017171616"></a>

The external APIs provided by the client of the AI engine include  **AieClientInit**,  **AieClientPrepare**,  **AieClientSyncProcess**,  **AieClientAsyncProcess**,  **AieClientRelease**,  **AieClientDestroy**,  **AieClientSetOption**, and  **AieClientGetOption**. The SDK needs to encapsulate at least the following five APIs in sequence:  **AieClientInit**,  **AieClientPrepare**,  **AieClientSyncProcess**  \(or  **AieClientAsyncProcess**\),  **AieClientRelease**, and  **AieClientDestroy**. Otherwise, a call failure or memory leakage may occur. For example, if the  **AieClientprepare**  API is omitted during encapsulation, the server cannot load the plug-in. As a result, APIs that follow it cannot be called.

For an asynchronous plug-in, the SDK needs to implement the  **IClientCb**  API to receive the algorithm inference result from the client and return the result to the third-party caller.

## Rule: Save all common data related to client interaction in the SDK during API implementation.<a name="section011283741612"></a>

The client of the AI engine uses the singleton pattern for API implementation. If the client is connecting to multiple SDKs, each SDK needs to store all common data exchanged with the client so that they can connect to the server to perform operations such as task inference and return the result. Common data usually includes  **clientInfo**,  **algorithmInfo**, and  **configInfo**, which are defined in the SDK's member variables.

## Recommendation: Enable the SDK to implement the  **IServiceDeadCb**  API defined by the client.<a name="section1199125331613"></a>

The processes running on the server are system resident processes. The server provides services for clients by way of system capabilities. The  **IServiceDeadCb**  API is called if a server process is abnormally killed. The SDK can implement related operations in this API, for example, stopping process call or restarting the server.

The following is an example of  **IServiceDeadCb**  API implementation:

```
class ServiceDeadCb : public IServiceDeadCb {
public:
ServiceDeadCb() = default;
~ServiceDeadCb() override = default;
void OnServiceDead() override
{
printf("[ServiceDeadCb]OnServiceDead Callback happens");
}
};
```

As shown above, the SDK can implement its own operations in the  **OnServiceDead\(\)**  function, for example, stopping API call.

## Rule: Convert dedicated algorithm data into common data of the AI engine if the SDK and plug-ins need to use the codec module.<a name="section93139389171"></a>

For plug-ins, inference data is transmitted by the third-party caller to them through the client and server. The required data type varies according to algorithms. For example, the CV algorithm requires image data, and the ASR algorithm requires audio data. To address this issue, the AI engine provides the codec capabilities to convert different types of data into common data that can be used by it.

The encoded data is as follows:

```
struct DataInfo {
unsigned char *data;
int length;
} DataInfo;

```

As shown above,  **DataInfo**  consists of two variables: a pointer to the data memory, and the data length.

To use the APIs of the AI engine framework, you need to:

1. Add the dependency header file  **utils/encdec/include/encdec.h**.

2. Add the dependency items in the  **build.gn**  file.

Add  **"//foundation/ai/engine/services/common"**  to  **include\_dirs**.

Add  **"//foundation/ai/engine/services/common/utils/encdec:encdec"**  to  **deps**.

3. Convert different types of data through codec. The following is an example:

```
// Example function for encoding: arg1, arg2, and arg3 are variables to be encoded, and dataInfo is the encoding result.
retCode = ProcessEncode(dataInfo, arg1, arg2, arg3) // The number of parameters can be flexible.
// Example function for decoding: dataInfo is the data to be decoded, and arg1, arg2, and arg3 are the decoding result.
retCode = ProcessDecode(dataInfo, arg1, arg2, arg3) // The number of parameters can be flexible.
```

Note:

-   The sequence of parameters must be the same during encoding and decoding.
-   After encoding, the memory used by  **dataInfo**  needs to be manually released by the caller.
-   The memory is managed and released separately on the server and the client.
-   If a pointer contains the shared memory, no extra processing is required.
-   If other types of pointers are used, you need to dereference them before using  **ProcessEncode**  or  **ProcessDecode**.
-   The codec module has not been adapted to the  **class**  data type and therefore it is not recommended.

## Rule: Release the memory used by the encoded or decoded parameters in the SDK. Otherwise, a memory leakage occurs.<a name="section1698441814183"></a>

Encoding is essentially a process of encapsulating different types of data in the same memory space and then encapsulating the start address and length of the memory into the body. The plug-in is unable to release the memory that has been allocated to output parameter data returned to the SDK through encoding. To obtain the data, the SDK first needs to release the memory.

The following is an example of releasing the memory:

```
DataInfo outputInfo = {
.data = nullptr,
.length = 0,
};
AieClientPrepare(clientInfo_, algorithmInfo_, inputInfo, outputInfo, nullptr);
if (outputInfo.data != nullptr) {
free(outputInfo.data);
outputInfo.data = nullptr;
outputInfo.length = 0;
}
```

## Rule: Enable plug-ins to implement the  **IPlugin**  API defined by the server and use the  **PLUGIN\_INTERFACE\_IMPL**  statement to provide the function pointer for external systems.<a name="section20850717196"></a>

The server manages a variety of plug-ins, and the API implementation logic varies according to plug-ins. To unify the plug-in loading process, the AI engine provides the  **IPlugin**  API. In the runtime environment, a plug-in is loaded as a dynamic link library \(DLL\) by the AI engine framework in dlopen mode. Therefore, the plug-in needs to use the  **PLUGIN\_INTERFACE\_IMPL**  statement to expose the function pointer. Otherwise, the plug-in cannot be properly loaded. 

## Rule: Use the unified data channel provided by the AI engine for plug-ins.<a name="section1493821732019"></a>

The AI engine provides a unified data channel between the server and plug-ins to send inference requests from the SDK and returned results from plug-ins. Plug-ins need to obtain the request data and encapsulate the inference result over the data channel when calling the inference API.

The following is an example of using the data channel:

```
int SyncProcess(IRequest *request, IResponse *&response)
{
HILOGI("[IvpPlugin]Begin SyncProcess");
if (request == nullptr) {
HILOGE("[IvpPlugin]SyncProcess request is nullptr");
return RETCODE_NULL_PARAM;
}
DataInfo inputInfo = request->GetMsg();
if (inputInfo.data == nullptr) {
HILOGE("[IvpPlugin]InputInfo data is nullptr");
return RETCODE_NULL_PARAM;
}

...

response = IResponse::Create(request);
response->SetResult(outputInfo);
return RETCODE_SUCCESS;
}
```

In the example, the request and response are the data body sent over the data channel. The server encapsulates data in the request and sends it to the plug-in. After completing algorithm processing, the plug-in encapsulates the result into the response and returns it to the server over the data channel.

