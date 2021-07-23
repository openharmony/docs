# Naming<a name="EN-US_TOPIC_0000001095816835"></a>

-   [Rule: Name an SDK in the format of domain\_keyword<\_other information 1\_other information 2\_...\>\_sdk.so.](#section62071110121516)
-   [Rule: Name a plug-in in the format of domain\_keyword<\_other information 1\_other information 2\_...\>.so.](#section1665562841519)

## Rule: Name an SDK in the format of  **domain\_keyword<\_other information 1\_other information 2\_...\>\_sdk.so**.<a name="section62071110121516"></a>

You are advised to use the commonly known abbreviations for domains. For example, use  **cv**  for image and video,  **asr**  for voice recognition, and  **translation**  for text translation. Add one if there is no available abbreviation for a domain. Use keywords that accurately describe the algorithm capability of the plug-in. For example, use  **keyword\_spotting**  for wakeup keyword spotting \(KWS\). Add other information, such as the supported chip type and applicable region, between  **keyword**  and  **sdk**, with each of them separated by an underscore \(\_\). Note that the name of a northbound SDK must end with  **sdk**.

For example, if the SDK for the KWS plug-in supports only the Kirin 9000 chipset and is applicable only in China, then name the SDK as follows:  **asr\_keyword\_spotting\_kirin9000\_china\_sdk.so**.

## Rule: Name a plug-in in the format of  **domain\_keyword<\_other information 1\_other information 2\_...\>.so**.<a name="section1665562841519"></a>

Use the same naming rules as the SDK.

A plug-in maps to an SDK. Therefore, they have the same requirements for the domain, keyword, and other information in their names. The only difference is that the name of the SDK ends with  **\_sdk**  additionally. For example, if the plug-in is named  **asr\_keyword\_spotting.so**, the corresponding northbound SDK is named  **asr\_keyword\_spotting\_sdk.so**.

For example, if the SDK for the KWS plug-in supports only the Kirin 9000 chipset and is applicable only in China, then name the plug-in as follows:  **asr\_keyword\_spotting\_kirin9000\_china.so**.

