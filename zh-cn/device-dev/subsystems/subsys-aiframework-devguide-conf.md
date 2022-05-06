# 配置文件的开发过程


开发者开发的SDK通过AlgorithmInfo结构体中algorithmVersion以及algorithmType识别出具体的插件类型，实现插件能力的调用。因此开发者需完成以下步骤：


1. 代码路径//foundation/ai/engine/services/common/protocol/plugin_config/plugin_config_ini/中添加插件的配置文件。

2. 代码路径//foundation/ai/engine/services/common/protocol/plugin_config/中的aie_algorithm_type.h文件添加算法类型。

3. 代码路径//foundation/ai/engine/services/server/plugin_manager/include/中的aie_plugin_info.h文件添加唤醒词识别的算法名称及其在ALGORITHM_TYPE_ID_LIST中的序号。


具体开发过程可参考[唤醒词识别配置文件开发示例](../subsystems/subsys-aiframework-demo-conf.md)。
