# Using Secure Shield Mode

The Secure Shield mode is a system-level security mode provided for users with high security requirements. This mode restricts basic device capabilities to enhance security and effectively defend against targeted attacks through the remote attack surface.

## HTML5 Features Restricted by ArkWeb

When the Secure Shield mode is enabled, ArkWeb reduces the attack surface by restricting the following HTML5 features:

- The WebAssembly capability.

- The WebGL and WebGL2 capability.

- The preview function of PDF Viewer.

- The MathML capability.

- The speech recognition capability of the Web Speech API.

- The **RTCDataChannel** API.

- The **MediaDevices.getUserMedia** API, which is used to prompt users to allow access to the media input device.

- The Service Worker capability.

- Non-proxy UDP traffic. This prevents WebRTC from disclosing the real source IP address.

- The JIT capability.

## Evaluating Impacts On Applications

To evaluate the impact and compatibility of applications in Secure Shield mode, go to **Settings** > **Privacy & security** > **Secure Shield** to enable this mode.

<!--RP2--><!--RP2End-->

> **NOTE**
>
> - To evaluate the compatibility of a debug version (not released on AppGallery), you need to enable **Developer options** and the Secure Shield mode.
> - To check whether the Secure Shield mode is enabled, use <!--RP1-->the capability of querying the device security mode (C/C++) provided by <!--RP1End-->Device Security Kit.

When an application is running, you can check whether the corresponding functionalities are affected in the following ways:

- Check whether the frontend code calls the WebAssembly APIs, which are used to run code compiled using low-level languages such as C and C++ on web pages and cannot be called in the Secure Shield mode.

- Check whether the frontend code calls the WebGL APIs, which provide the 3D graphics drawing capability and cannot be called in the Secure Shield mode.

- Check whether there is the functionality of displaying PDF files online. PDF files cannot be displayed online in the Secure Shield mode. For example, loadUrl cannot be used to load PDF links.

- Check whether the HTML page contains the MathML syntax embedded in the **\<math>** tag. In the Secure Shield mode, the MathML syntax cannot be parsed and displayed.

- Check whether APIs such as **SpeechRecognition** and **SpeechSynthesis** are called in the frontend code. In the Secure Shield mode, they cannot be called.

- Check whether the frontend code calls the WebRTC APIs such as **RTCDataChannel** and **createDataChannel**, which are used to establish bidirectional data channels for real-time data exchange between peers and cannot be called in the Secure Shield mode.

- Check whether the frontend code calls the **MediaDevices.getUserMedia** API, which is used to access streaming media devices, such as cameras and microphones. When the Secure Shield mode is used, the exception "can't use getUserMedia on advancedSecurityMode!" is thrown when related APIs are called.

- Check whether the frontend code calls the ServiceWorker APIs, which are used to implement functionalities such as offline cache, network request interception, and notification push and cannot be created in the Secure Shield mode.

- Check whether WebRTC uses non-proxy UDP transmission, which is prohibited in the Secure Shield mode. The application needs to verify the network functionalities and performance in the WebRTC scenario.

- The application needs to evaluate the JS performance in the Secure Shield mode.
