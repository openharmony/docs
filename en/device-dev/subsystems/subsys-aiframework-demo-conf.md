# KWS Configuration File<a name="EN-US_TOPIC_0000001121062971"></a>

1.  Add the KWS configuration file to the  **//foundation/ai/engine/services/common/protocol/plugin\_config/plugin\_config\_ini/**  directory.

    ```
    [base]
    supported_boards = hi3516dv300
    related_sessions = asr_keyword_spotting+20001002
    
    // Naming rule: [algorithm name+algorithm version], for example, [asr_keyword_spotting+20001002]
    [asr_keyword_spotting+20001002]
    AID         = asr_keyword_spotting
    VersionCode = 20001002
    VersionName = 2.00.01.002
    XPU         = NNIE
    District    = China
    // Location of the complied .so file of the plug-in
    FullPath    = /usr/lib/libasr_keyword_spotting.so
    Chipset     = ALL
    ChkSum      = ''
    Key         = ''
    ```

2.  Add the type ID of the KWS algorithm to the  **aie\_algorithm\_type.h**  file in the  **//foundation/ai/engine/services/common/protocol/plugin\_config/**  directory.

    ```
    // Make sure that the type ID maps to the sequence number in ALGORITHM_TYPE_ID_LITS.
    const int ALGORITHM_TYPE_KWS = 3;
    ```

3.  Add the name of the KWS algorithm and its sequence number in  **ALGORITHM\_TYPE\_ID\_LITS**  to the  **aie\_plugin\_info.h**  file in the  **//foundation/ai/engine/services/server/plugin\_manager/include/**  directory.

    ```
    const std::string ALGORITHM_ID_SAMPLE_1 = "sample_plugin_1";
    const std::string ALGORITHM_ID_SAMPLE_2 = "sample_plugin_2";
    const std::string ALGORITHM_ID_IVP = "cv_human_detect";
    // Add the name of the KWS algorithm: asr_keyword_spotting.
    // Name the algorithm variable in the same way as the algorithm type ID in ALGORITHM_TYPE_ID_LIST, for example, ALGORITHM_ID_KWS.
    const std::string ALGORITHM_ID_KWS = "asr_keyword_spotting";
    const std::string ALGORITHM_ID_IC = "cv_image_classification";
    const std::string ALGORITHM_ID_INVALID = "invalid algorithm id";
    
    const std::vector<std::string> ALGORITHM_TYPE_ID_LIST = {
        ALGORITHM_ID_SAMPLE_1,
        ALGORITHM_ID_SAMPLE_2,
        ALGORITHM_ID_IVP,
        // Add the sequence number of the KWS algorithm to ALGORITHM_TYPE_ID_LITS, so that the name of the KWS algorithm can be obtained based on the sequence number.
        // Make sure that the algorithm name maps to the sequence number in ALGORITHM_TYPE_ID_LITS.
        ALGORITHM_ID_KWS,
        ALGORITHM_ID_IC,
    };
    ```


