# Using Secure Shield Mode

The Secure Shield mode is <!--RP1--><!--RP1End-->a system-level security mode provided for users with high security requirements. This mode restricts basic device capabilities to enhance security and effectively defend against targeted attacks through the remote attack surface.

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

To evaluate the impact and compatibility of applications in Secure Shield mode, go to **Settings** > **Privacy & security** > **Secure Shield mode** to enable this mode.

<!--RP2--><!--RP2End-->

> **NOTE**
>
> To evaluate the compatibility of a debug version (not released on AppGallery), you need to enable the developer option and then enable the Secure Shield mode.

When an application is running, you can check whether the corresponding functions are affected in the following ways:

- Check whether WebAssembly APIs are called in the frontend code. WebAssembly provides the capability of running low-level languages such as C and C++ on the web, which is usually used in high-performance scenarios such as games and encoding and decoding. In Secure Shield mode, WebAssembly cannot be called.

- Check whether WebGL APIs are called in the frontend code. WebGL provides the 3D graphics drawing capability, which cannot be called in shield daemon mode.

- Check whether the PDF file can be displayed online. If the Secure Shield mode is enabled, the PDF file cannot be displayed online. For example, the loadUrl API cannot be used to load the PDF link.

- Check whether the HTML page contains the MathML syntax embedded in the \**<\math>** tag. In the Secure Shield mode, the MathML syntax cannot be properly parsed and displayed.

- Check whether APIs such as **SpeechRecognition** and **SpeechSynthesis** are called in the frontend code. In the Shield Guard mode, they cannot be called.

- Check whether WebRTC APIs such as **RTCDataChannel** and **createDataChannel** are called in the frontend code. These APIs can be used to establish a bidirectional data channel to implement real-time data exchange between peers in WebRTC and cannot be called in the Secure Shield mode.

- Check whether the **MediaDevices.getUserMedia** API is called in the frontend code. This API is used to request users to access streaming media devices (such as cameras and microphones). In the Secure Shield mode, the exception information "can't use getUserMedia on advancedSecurityMode!" is displayed when this API is called.

- Check whether ServiceWorker APIs are called in the frontend code. This mechanism is used to implement capabilities such as offline cache, network request interception, and notification push, which cannot be created in Secure Shield mode.

- Check whether non-proxy UDP transmission is used in WebRTC. In Secure Shield mode, non-proxy UDP transmission is not allowed. When network connectivity is involved, network functions and performance in WebRTC scenarios need to be verified and evaluated.

- Check whether JIT is used. In the Secure Shield mode, the JS performance needs to be evaluated for applications because JIT involves performance optimization.
