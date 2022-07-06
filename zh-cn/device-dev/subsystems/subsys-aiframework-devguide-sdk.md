# SDK开发过程


SDK头文件的功能实现是基于对SDK的调用映射到对客户端的调用。客户端端提供的接口如下表所示。


  **表1** Client端提供的接口

| 接口名 | 接口说明 | 参数要求 |
| -------- | -------- | -------- |
| int&nbsp;**AieClientInit**(const&nbsp;ConfigInfo&nbsp;&amp;configInfo,<br/>&nbsp;ClientInfo&nbsp;&amp;clientInfo,&nbsp;const&nbsp;AlgorithmInfo<br/>&nbsp;&amp;algorithmInfo,&nbsp;IServiceDeadCb&nbsp;\*cb) | **作用**：链接并初始化引擎服务，激活跨进程调用。<br/>**返回值**：0为成功，其他返回值失败。 | **configInfo**(NOT&nbsp;NULL)：引擎相关初始化配置数据；<br/>**clientInfo**(NOT&nbsp;NULL)：引擎客户端信息；<br/>**algorithmInfo**(NOT&nbsp;NULL)：调用算法信息；<br/>**cb**(可为NULL)：死亡回调&nbsp;对象； |
| int&nbsp;**AieClientPrepare**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo<br/>,&nbsp;const&nbsp;AlgorithmInfo&nbsp;&amp;algorithmInfo,&nbsp;const&nbsp;DataInfo<br/>&nbsp;&amp;inputInfo,&nbsp;DataInfo&nbsp;&amp;outputInfo,&nbsp;IClientCb&nbsp;\*cb) | **作用**：加载算法插件。<br/>**返回值**：&nbsp;0为成功，其他返回值失败。 | **clientInfo**(NOT&nbsp;NULL)：引擎客户端信息；<br/>**algorithmInfo**(NOT&nbsp;NULL)：调用算法信息；<br/>**inputInfo**(可为NULL)：加载算法插件时输入所需信息；<br/>**outputInfo**(可为NULL)：加载算法插件之后如需返回信息则通过此出参返回；<br/>**cb**：异步算法通过此回调返回运算结果，因此**异步算法此结构体不能为空**；若为同步算法，传入空值即可； |
| int&nbsp;**AieClientAsyncProcess**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;const&nbsp;AlgorithmInfo&nbsp;&amp;algorithmInfo,&nbsp;const&nbsp;DataInfo<br/>&nbsp;&amp;inputInfo) | **作用**：执行异步算法。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**(NOT&nbsp;NULL)：引擎客户端信息；<br/>**algorithmInfo**(NOT&nbsp;NULL)：调用算法信息；<br/>**inputInfo**(可为NULL)：算法运算入参； |
| int&nbsp;**AieClientSyncProcess**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;const&nbsp;AlgorithmInfo&nbsp;&amp;algorithmInfo,&nbsp;const<br/>&nbsp;DataInfo&nbsp;&amp;inputInfo,&nbsp;DataInfo&nbsp;&amp;outputInfo) | **作用**：执行同步算法。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**(NOT&nbsp;NULL)：引擎客户端信息；<br/>**algorithmInfo**(NOT&nbsp;NULL)：调用算法信息；<br/>**inputInfo**(可为NULL)：算法运算入参；<br/>**outputInfo**(可为NULL)：同步算法运算结果出参； |
| int&nbsp;**AieClientRelease**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;const&nbsp;AlgorithmInfo&nbsp;&amp;algorithmInfo,&nbsp;const<br/>&nbsp;DataInfo&nbsp;&amp;inputInfo) | **作用**：卸载算法插件。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**(NOT&nbsp;NULL)：引擎客户端信息；<br/>**algorithmInfo**(NOT&nbsp;NULL)：卸载算法插件的相关信息；<br/>**inputInfo**(可为NULL)：调用卸载接口时的输入信息； |
| int&nbsp;**AieClientDestroy**(ClientInfo&nbsp;&amp;clientInfo) | **作用**：断开与服务端的链接，释放相关缓存。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**(NOT&nbsp;NULL)：所要销毁的引擎客户端信息； |
| int&nbsp;**AieClientSetOption**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;int&nbsp;optionType,&nbsp;const&nbsp;DataInfo&nbsp;&amp;inputInfo) | **作用**：设置配置项，可将一些算法的拓展信息通过此接口传入插件。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**(NOT&nbsp;NULL)：引擎客户端信息；<br/>**optionType**&nbsp;(NOT&nbsp;NULL)：算法配置项，算法插件可根据需要利用此状态位；<br/>**inputInfo**(可为NULL)：插件可根据需要通过此入参设置算法参数信息； |
| int&nbsp;**AieClientGetOption**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;int&nbsp;optionType,&nbsp;const&nbsp;DataInfo&nbsp;&amp;inputInfo,<br/>&nbsp;DataInfo&nbsp;&amp;outputInfo) | **作用**：给定特定的optionType和inputInfo，获取其对应的配置项信息。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**(NOT&nbsp;NULL)：引擎客户端信息；<br/>**optionType**(NOT&nbsp;NULL)：所获取配置项信息的对应算法状态位；<br/>**inputInfo**(可为NULL)：所获取配置项信息的对应算法参数信息；<br/>**outputInfo**(可为NULL)：所要获取的配置项信息返回结果； |


其中，ConfigInfo，ClientInfo，AlgorithmInfo，DataInfo的数据结构如下表所示。


  **表2** ConfigInfo，ClientInfo，AlgorithmInfo，DataInfo的数据结构

| 结构体名称 | 说明 | 属性 |
| -------- | -------- | -------- |
| ConfigInfo | 算法配置项信息。 | **const&nbsp;char&nbsp;\*description**：配置项信息主体； |
| ClientInfo | 客户端信息。 | **long&nbsp;long&nbsp;clientVersion**：客户端设备版本号（当前还未启用）；<br/>**int&nbsp;clientId**：客户端ID；<br/>**int&nbsp;sessionId：**会话ID；<br/>**uid_t&nbsp;serverUid**：server端UID；<br/>**uid_t&nbsp;clientUid：**client端UID；<br/>**int&nbsp;extendLen**：拓展信息（extendMsg）长度；<br/>**unsigned&nbsp;char&nbsp;\*extendMsg**：拓展信息主体； |
| AlgorithmInfo | 算法信息。 | **long&nbsp;long&nbsp;clientVersion**：客户端设备版本号（当前还未启用）；<br/>**bool&nbsp;isAsync**：是否为异步执行；<br/>**int&nbsp;algorithmType：**引擎框架根据插件加载顺序分配的算法类型ID；<br/>**long&nbsp;long&nbsp;algorithmVersion**：算法版本号；<br/>**bool&nbsp;isCloud**：是否上云（当前还未启用）；<br/>**int&nbsp;operateId**：执行ID（当前还未启用）；<br/>**int&nbsp;requestId**：请求ID，标识每次request，以对应执行结果；<br/>**int&nbsp;extendLen**：拓展信息（extendMsg）长度；<br/>**unsigned&nbsp;char&nbsp;\*extendMsg**：拓展信息主体； |
| DataInfo | 算法数据入参(inputInfo)、<br/>接口调用结果出参(outputInfo)。 | **unsigned&nbsp;char&nbsp;\*data：**数据主体；<br/>**int&nbsp;length**：数据(data)长度； |


具体开发过程可参考[唤醒词识别SDK开发示例](../subsystems/subsys-aiframework-demo-sdk.md)。
