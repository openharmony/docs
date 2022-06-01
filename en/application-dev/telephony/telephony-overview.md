# Telephony Service Overview

The Telephony subsystem provides a series of APIs for [making calls](../reference/apis/js-apis-call.md), [obtaining current cellular network signal information](../reference/apis/js-apis-telephony-data.md) and [managing SIM cards](../reference/apis/js-apis-sim.md).

Your application can call related APIs to obtain the name of the currently registered network, network service status, signal strength, and SIM card information. For details, see [Obtaining Current Cellular Network Signal Information](cellular-network-signal-info.md).

To make calls, your application needs to declare the **ohos.permission.PLACE_CALL** permission. It is recommended that the application use **makeCall()** to redirect users to the dial screen and display the dialed number. For details, see [Redirecting to the Dial Screen](jumping-to-the-dial-screen.md).


## Constraints

The accommodating device must be equipped with a modem and a SIM card capable of independent cellular communication.
