# AI Engine Framework<a name="EN-US_TOPIC_0000001077309802"></a>

The AI subsystem of OpenHarmony provides native distributed AI capabilities. At the heart of the subsystem is a unified AI engine framework, which implements quick integration of AI algorithm plug-ins. The framework consists of the plug-in management, module management, and communication management modules, fulfilling lifecycle management and on-demand deployment of AI algorithms. Plug-in management implements lifecycle management, on-demand deployment, and quick integration of AI algorithm plug-ins. Module management implements task scheduling and client instance management. Communication management implements inter-process communication \(IPC\) between the client and server and data transmission between the AI engine and plug-ins. Under this framework, AI algorithm APIs will be standardized to facilitate distributed calling of AI capabilities. In addition, unified inference APIs will be provided to adapt to different inference framework hierarchies.  [Figure 1](#fig143186187187)  shows the AI engine framework.

**Figure  1**  AI engine framework<a name="fig143186187187"></a>  


![](figures/en-us_image_0000001077727032.png)

