# 插件的开发过程


AI引擎框架规定了一套算法插件接入规范，各插件需实现规定接口以实现获取插件版本信息、算法推理类型、同步执行算法、异步执行算法、加载算法插件、卸载算法插件、设置算法配置信息、获取指定算法配置信息等功能。（同步算法实现SyncProcess接口，异步算法实现AsyncProcess接口）。


算法插件类IPlugin接口设计如下表所示。


  **表1** 算法插件类IPlugin接口设计

| 接口名 | 接口说明 | 参数要求 | 
| -------- | -------- | -------- |
| const&nbsp;long&nbsp;long&nbsp;GetVersion()&nbsp;const; | **作用**：获取插件版本信息。<br/>**返回值**：版本号（long&nbsp;long） | - | 
| const&nbsp;char&nbsp;\*GetInferMode()&nbsp;const; | **作用**：获取算法推理类型。<br/>**返回值**："SYNC"&nbsp;or&nbsp;"ASYNC"; | - | 
| int&nbsp;SyncProcess(IRequest&nbsp;\*request,<br/>IResponse&nbsp;\*&amp;response); | **作用**：执行插件同步算法。<br/>**返回值**：0为成功，其他返回值失败。 | **request**(NOT&nbsp;NULL)：用于向算法插件传递请求内容；引擎服务端与插件的数据通道；<br/>**response**(NOT&nbsp;NULL)：作为出参用于接收算法插件发回的同步算法执行结果，引擎服务端与插件的数据通道； | 
| int&nbsp;AsyncProcess(IRequest&nbsp;\*request,<br/>IPluginAlgorithmCallback&nbsp;\*callback); | **作用**：执行异步算法。<br/>**返回值**：0为成功，其他返回值失败。 | **request**(NOT&nbsp;NULL)：用于向算法插件传递请求内容；引擎服务端与插件的数据通道。<br/>**callback**(NOT&nbsp;NULL)：算法插件异步执行结果通过此回调返回引擎服务端； | 
| int&nbsp;Prepare(long&nbsp;long&nbsp;transactionId,<br/>const&nbsp;DataInfo&nbsp;&amp;inputInfo,&nbsp;DataInfo<br/>&amp;outputInfo); | **作用**：加载算法插件。<br/>**返回值**：0为成功，其他返回值失败。 | **transactionId**(NOT&nbsp;NULL)：事务ID，用于标记客户端+会话信息；<br/>**inputInfo**(可为NULL)：加载算法插件传入的一些信息；<br/>**outputInfo**(可为NULL)：调用加载接口时的出参，返回相关执行结果； | 
| int&nbsp;Release(bool&nbsp;isFullUnload,&nbsp;long&nbsp;long<br/>transactionId,&nbsp;const&nbsp;DataInfo&nbsp;&amp;inputInfo); | **作用**：卸载相关算法插件。<br/>**返回值**：0为成功，其他返回值失败。 | **isFullUnload**(NOT&nbsp;NULL)：表示此插件是否只剩一个client调用，否则不能直接卸载插件，需等最后一个client来进行卸载；<br/>**transactionId**(NOT&nbsp;NULL)：事务ID，用于标记客户端+会话信息；<br/>**inputInfo**(可为NULL)：卸载算法插件传入的一些信息； | 
| int&nbsp;SetOption(int&nbsp;optionType,&nbsp;const<br/>DataInfo&nbsp;&amp;inputInfo); | **作用**：设置配置项，可将一些算法的拓展信息通过此接口传入插件。<br/>**返回值**：0为成功，其他返回值失败。 | **optionType**&nbsp;(NOT&nbsp;NULL)：算法配置项，算法插件可根据需要利用此状态位；<br/>**inputInfo**(可为NULL)：插件可根据需要通过此入参设置算法参数信息； | 
| int&nbsp;GetOption(int&nbsp;optionType,&nbsp;const<br/>DataInfo&nbsp;&amp;inputInfo,&nbsp;DataInfo<br/>&amp;outputInfo); | **作用**：给定特定的optionType和inputInfo，获取其对应的配置项信息。<br/>**返回值**：0为成功，其他返回值失败。 | **optionType**(NOT&nbsp;NULL)：所获取配置项信息的对应算法状态位；<br/>**inputInfo**(可为NULL)：所获取配置项信息的对应算法参数信息；<br/>**outputInfo**(可为NULL)：所要获取的配置项信息返回结果； | 


算法插件类接口：Prepare、SyncProcess、AsyncProcess、Release、SetOption、GetOption分别于客户端接口AieClientPrepare、AieClientSyncProcess、AieClientAsyncProcess、AieClientRelease、AieClientSetOption、AieClientGetOption一一对应；GetInferMode接口用于返回算法执行类型——同步或异步。


算法插件回调类IPluginCallback 接口设计如下表所示。


  **表2** 算法插件回调类IPluginCallback 接口设计

| 接口名 | 接口说明 | 参数要求 | 
| -------- | -------- | -------- |
| void&nbsp;OnEvent(PluginEvent&nbsp;event,<br/>IResponse&nbsp;\*response); | 作用：插件通过此回调返回异步算法执行结果。 | **event**：算法执行结果枚举,‘ON_PLUGIN_SUCCEED’或&nbsp;‘ON_PLUGIN_FAIL’（成功或者失败）；<br/>**response**：算法执行结果封装； | 


Request、Response是ai引擎服务端与算法插件进行通信的对象。Request封装了调用方的请求、输入数据等，而插件主要通过Response将运算之后的结果返回给AI引擎服务端。


Request类的属性如下表所示。


  **表3** Request类的属性

| 属性名称 | 属性说明 | 默认值 | 
| -------- | -------- | -------- |
| innerSequenceId_ | 类型：long&nbsp;long<br/>作用：暂未启用。 | 0 | 
| requestId_ | 类型：int<br/>作用：标识请求序列，用于绑定返回运算结果。 | 0 | 
| operationId_ | 类型：int<br/>作用：目前暂未启用。 | 0 | 
| transactionId_ | 类型：long&nbsp;long<br/>作用：事务ID，唯一标识clientId+sessionId。 | 0 | 
| algoPluginType_ | 类型：int<br/>作用：引擎框架根据插件加载顺序分配的算法类型的ID。 | 0 | 
| msg_ | 类型：DataInfo<br/>作用：存放调用算法接口的输入数据。 | .data&nbsp;=&nbsp;nullptr<br/>.length&nbsp;=&nbsp;0 | 


Response类的属性如下表所示。


  **表4** Response类的属性

| 属性名称 | 属性说明 | 默认值 | 
| -------- | -------- | -------- |
| innerSequenceId_ | 类型：long&nbsp;long<br/>作用：暂未启用。 | 0 | 
| requestId_ | 类型：int<br/>作用：标识请求序列，用于绑定返回运算结果。 | 0 | 
| retCode__ | 类型：int<br/>作用：异步执行算法推理结果码。 | 0 | 
| retDesc_ | 类型：string<br/>作用：暂未启用。 | - | 
| transactionId_ | 类型：long&nbsp;long<br/>作用：事务ID，唯一标识clientId+sessionId。 | 0 | 
| algoPluginType_ | 类型：int<br/>作用：引擎框架根据插件加载顺序分配的算法类型的ID。 | INVALID_ALGO_PLUGIN_TYPE(-1) | 
| result_ | 类型：DataInfo<br/>作用：存放异步算法推理结果。 | .data&nbsp;=&nbsp;nullptr<br/>.length&nbsp;=&nbsp;0 | 


具体开发过程可参考[唤醒词识别插件开发示例](../subsystems/subsys-aiframework-demo-plugin.md)。
