# Common Event Subscription Overview

The common event service provides two subscription modes: dynamic and static. The biggest difference between these two modes is that dynamic subscription requires the application to be running, while static subscription does not.

- In dynamic subscription mode, a subscriber subscribes to common events by calling an API during the running period. For details, see [Subscribing to Common Events in Dynamic Mode](common-event-subscription.md).

- In static subscription mode, a subscriber subscribes to common events by configuring a declaration file and implementing a class that inherits from **StaticSubscriberExtensionAbility**. For details, see [Subscribing to Common Events in Static Mode](common-event-static-subscription.md).
