# Advanced Security Mode

The advanced security mode is designed for specific high-risk users. By restricting basic functions of the device, the advanced security mode provides higher security and prevents targeted network attacks. When the advanced security mode is enabled, ArkWeb reduces the attack surface by disabling some HTML5 features.


The disabled features are as follows:

1. The WebAssembly capability.

2. The WebGL and WebGL2 capability.

3. The preview function of PDF viewer.

4. The MathML capability.

5. The speech recognition capability of Web speech API .

6. The RTCDataChannel API.

7. The MediaDevices.getUserMedia API.

8. The Service Worker capability.

9. Non-proxy UDP traffic. (To prevent WebRTC from disclosing real source IP addresses.)

10. The JIT capability.
