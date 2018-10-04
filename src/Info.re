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

let component = ReasonReact.statelessComponent("Info");

let make = (~title, ~startAt, _children) => {
  ...component,
  render: _self =>
    <div className="notification">
      <i className="fas fa-info-circle" />
      {(title, startAt) |> titleEle}
    </div>,
};