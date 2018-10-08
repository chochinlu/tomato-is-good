type log = {
  title: string,
  startAt: option(Js.Date.t),
  endAt: Js.Date.t,
};

[@bs.val] external requireCSS: string => unit = "require";