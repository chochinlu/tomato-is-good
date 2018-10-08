type taskResult =
  | Finished
  | Terminated;

type log = {
  title: string,
  startAt: option(Js.Date.t),
  endAt: Js.Date.t,
  result: taskResult,
};

[@bs.val] external requireCSS: string => unit = "require";