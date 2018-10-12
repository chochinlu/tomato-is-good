[@bs.val] external userPermission: string = "Notification.permission";

[@bs.val]
external requestPermission: unit => unit = "Notification.requestPermission";

type permission;

[@bs.deriving abstract]
type options = {body: string};
[@bs.new] external make: (string, options) => unit = "Notification";