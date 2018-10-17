let timeStr = startAt =>
  switch (startAt) {
  | None => ""
  | Some(time) => Js.Date.toString(time)
  };

let titleEle = ((title, startAt)) =>
  <span>
    <strong> {"  [ " ++ title ++ " ] " |> ReasonReact.string} </strong>
    {startAt |> timeStr |> ReasonReact.string}
  </span>;

let status = isPaused =>
  isPaused ?
    <strong style={ReactDOMRe.Style.make(~color="#209CEE", ())}>
      {" [ PAUSED ] " |> ReasonReact.string}
    </strong> :
    ReasonReact.null;

let component = ReasonReact.statelessComponent("Info");

let make = (~title, ~startAt, ~isPaused, _children) => {
  ...component,
  render: _self =>
    <div className="notification">
      <div className="tile is-ancestor">
        <div className="tile">
          <span className="icon has-text-info">
            <i className="fas fa-info-circle" />
          </span>
          {(title, startAt) |> titleEle}
        </div>
        <div className="tile is-1"> {isPaused |> status} </div>
      </div>
    </div>,
};