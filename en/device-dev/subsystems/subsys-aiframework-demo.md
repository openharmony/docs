# Development Examples<a name="EN-US_TOPIC_0000001077767514"></a>

For your better understanding, a KWS application is used as an example to walk you through the development process. You can develop the KWS SDK and plug-in based on the AI engine framework on the Hi3516D V300 development board, compile an image for the new version, and burn the image into the version. Then, develop an application with the KWS function. The application can receive external audio and pass the audio to the SDK API. If the audio contains specified keywords, the application will be able to recognize these keywords and print them in the command line.

This example uses a fixed keyword  **Hi, xiaowen**  for illustration. If the input audio contains  **Hi, xiaowen**, the application prints  **\[Hi, xiaowen\]**; otherwise, the application prints  **\[UNKNOWN\]**.

-   **[KWS SDK](subsys-aiframework-demo-sdk.md)**  

-   **[KWS Plug-in](subsys-aiframework-demo-plugin.md)**  

-   **[KWS Configuration File](subsys-aiframework-demo-conf.md)**  


