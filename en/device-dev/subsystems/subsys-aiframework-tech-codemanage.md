# Code Management<a name="EN-US_TOPIC_0000001096216399"></a>

Code of the AI engine framework consists of three parts:  **client**,  **server**, and  **common**. The client module provides the server connection management function. The northbound SDK needs to encapsulate and call the public APIs provided by the client in the algorithm's external APIs. The server module provides functions such as plug-in loading and task management. Plug-ins are integrated using the plug-in APIs provided by the server. The common module provides platform-related operation methods, engine protocols, and tool classes for other modules.

[Figure 1](#fig171811112818)  shows the code dependency between modules of the AI engine framework.

**Figure  1**  Code dependency<a name="fig171811112818"></a>  


![](figure/code-dependency-(2).jpg)

## Recommendation: Develop plug-ins and northbound SDKs in the directories specified by the AI engine.<a name="section17176374131"></a>

In the overall planning of the AI engine framework, northbound SDKs are a part of the client, and plug-ins are called by the server and are considered a part of the server. Therefore, the following directories have been planned for plug-in and northbound SDK development in the AI engine framework:

-   SDK code directory: //foundation/ai/engine/services/client/algorithm\_sdk

    e.g. //foundation/ai/engine/services/client/algorithm\_sdk/cv

    e.g. //foundation/ai/engine/services/client/algorithm\_sdk/nlu

-   Plug-in code directory: //foundation/ai/engine/services/server/plugin

    e.g. //foundation/ai/engine/services/server/plugin/cv

    e.g. //foundation/ai/engine/services/server/plugin/nlu


## Rule: Store all external APIs provided by plug-ins in the  **interfaces/kits**  directory of the AI subsystem.<a name="section2551029111312"></a>

The AI subsystem exposes its capabilities through external APIs of northbound SDKs. According to API management requirements of OpenHarmony, store all external APIs of northbound SDKs in the  **interfaces/kits**  directory of the subsystem. Currently, the external APIs of plug-ins of the AI subsystem are stored in the following directory:  **//foundation/ai/engine/interface/kits**. You can add a sub-directory for each newly added plug-in in this directory. For example, if you add a CV plug-in, then store its external APIs in the  **//foundation/ai/engine/interfaces/kits/cv**  directory.

## Rule: Make sure that plug-in compilation results are stored in the  **/usr/lib**  directory.<a name="section97021558121310"></a>

Plug-in loading on the server uses the dlopen mode and can only be performed in the  **/usr/lib**  directory. Therefore, when compiling the  **.so**  file of a plug-in, set the output directory as  **/usr/lib**  in the compilation configuration file.

