let timeStr = startAt =>
  switch (startAt) {
  | None => ""
  | Some(time) => " Start At: " ++ Js.Date.toTimeString(time)
  };

let titleEle = ((title, startAt)) =>
  <span>
    <strong> {"  [ " ++ title ++ " ] " |> ReasonReact.string} </strong>
    {startAt |> timeStr |> ReasonReact.string}
  </span>;

let status = isPaused =>
  isPaused ?
    <strong> {" [ PAUSED ] " |> ReasonReact.string} </strong> :
    ReasonReact.null;

let component = ReasonReact.statelessComponent("Info");

let make = (~title, ~startAt, ~isPaused, _children) => {
  ...component,
  render: _self =>
    <div className="notification">
      <i className="fas fa-info-circle" />
      {(title, startAt) |> titleEle}
      {isPaused |> status}
    </div>,
};