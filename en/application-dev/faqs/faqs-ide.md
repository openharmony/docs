# IDE Usage


## What should do if the error message "npm ERR! code SELF_SIGNED_CERT_IN_CHAIN" is displayed?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. Run **npm config set strict-ssl=false** on the DevEco Studio terminal.

2. Run the **npm install** on the DevEco Studio terminal.

## After manual updating of the DevEco Studio SDK, the error message "Cannot find module 'xxx\ets\x.x.x.x\build-tools\ets-loader\node_modules\webpack\bin\webpack.js'" is displayed during HAP building. What should I do?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. Run **npm install** in the **ets\x.x.x.x\build-tools\ets-loader** directory of the SDK.

2. Run **npm install** in the **js\x.x.x.x\build-tools\ace-loader** directory of the SDK. 

3. Perform HAP building again.
