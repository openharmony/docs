# 耗时任务并发场景简介


耗时任务是指需要较长时间执行的任务，如果在UI主线程执行，可能导致应用卡顿、掉帧或响应延迟。典型的耗时任务包括CPU密集型任务、I/O密集型任务和同步任务。


常见的业务场景分类如下：


| 常见业务场景 | 具体业务描述 | 是否为CPU密集型任务 | 是否为I/O密集型任务 | 是否为同步任务 |
| -------- | -------- | -------- | -------- | -------- |
| 图片/视频编解码 | 将图片或视频进行编解码再展示。 | 是 | 是 | 否 |
| 压缩/解压缩 | 解压本地压缩包或压缩本地文件。 | 是 | 是 | 否 |
| JSON解析 | 序列化和反序列化JSON字符串。 | 是 | 否 | 否 |
| 模型运算 | 对数据进行模型运算分析等。 | 是 | 否 | 否 |
| 网络下载 | 密集网络请求下载资源、图片、文件等。 | 否 | 是 | 否 |
| 数据库操作 | 将聊天记录、页面布局信息、音乐列表信息等保存到数据库，或者应用二次启动时，读取数据库展示相关信息。 | 否 | 是 | 否 |
