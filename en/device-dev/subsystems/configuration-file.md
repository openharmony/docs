# Configuration File<a name="EN-US_TOPIC_0000001120666799"></a>

The SDK identifies the plug-in type based on  **algorithmVersion**  and  **algorithmType**  in the  **AlgorithmInfo**  structure so it can call the plug-in capabilities. Therefore, you need to develop the plug-in configuration file as follows:

1.  Add the plug-in configuration file to the  **//foundation/ai/engine/services/common/protocol/plugin\_config/plugin\_config\_ini/**  directory.
2.  Add the algorithm type to the  **aie\_algorithm\_type.h**  file in the  **//foundation/ai/engine/services/common/protocol/plugin\_config/**  directory.
3.  Add the name of the KWS algorithm and its sequence number in  **ALGORITHM\_TYPE\_ID\_LITS**  to the  **aie\_plugin\_info.h**  file in the  **//foundation/ai/engine/services/server/plugin\_manager/include/**  directory.

For details about the development process, see the development example for the KWS configuration file.

