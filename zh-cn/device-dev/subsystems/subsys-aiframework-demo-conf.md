# 唤醒词识别配置文件的开发示例


1. 在代码路径//foundation/ai/engine/services/common/protocol/plugin_config/plugin_config_ini/中添加唤醒词识别的配置文件。
     
   ```
   [base]
   supported_boards = hi3516dv300
   related_sessions = asr_keyword_spotting+20001002
   
   //[asr_keyword_spotting+20001002]的命名规则为[算法名称+算法version]
   [asr_keyword_spotting+20001002]
   AID         = asr_keyword_spotting
   VersionCode = 20001002
   VersionName = 2.00.01.002
   XPU         = NNIE
   District    = China
   // 编译出的插件so文件所在的位置
   FullPath    = /usr/lib/libasr_keyword_spotting.so
   Chipset     = ALL
   ChkSum      = ''
   Key         = ''
   ```

2. 在代码路径//foundation/ai/engine/services/common/protocol/plugin_config/中的aie_algorithm_type.h文件添加唤醒词识别算法类型id。
     
   ```
   // 唤醒词识别的算法类型id与唤醒词识别在ALGORITHM_TYPE_ID_LIST中的序号一一对应
   const int ALGORITHM_TYPE_KWS = 3;
   ```

3. 在代码路径//foundation/ai/engine/services/server/plugin_manager/include/中的aie_plugin_info.h文件添加唤醒词识别算法名称及在ALGORITHM_TYPE_ID_LIST中的序号。
     
   ```
   const std::string ALGORITHM_ID_SAMPLE_1 = "sample_plugin_1";
   const std::string ALGORITHM_ID_SAMPLE_2 = "sample_plugin_2";
   const std::string ALGORITHM_ID_IVP = "cv_human_detect";
   // 添加唤醒词识别的算法名称asr_keyword_spotting
   // 算法的变量名称与ALGORITHM_TYPE_ID_LIST中算法typeId命名相同，例如：ALGORITHM_ID_KWS 
   const std::string ALGORITHM_ID_KWS = "asr_keyword_spotting";
   const std::string ALGORITHM_ID_IC = "cv_image_classification";
   const std::string ALGORITHM_ID_INVALID = "invalid algorithm id";
   
   const std::vector<std::string> ALGORITHM_TYPE_ID_LIST = {
       ALGORITHM_ID_SAMPLE_1,
       ALGORITHM_ID_SAMPLE_2,
       ALGORITHM_ID_IVP,
       // 添加唤醒词识别在ALGORITHM_TYPE_ID_LIST中的序号，通过该序号可获得唤醒词识别的算法名称
       // 唤醒词识别的算法名称和唤醒词识别在ALGORITHM_TYPE_ID_LIST中的序号顺序需保持一致
       ALGORITHM_ID_KWS,
       ALGORITHM_ID_IC,
   };
   ```
