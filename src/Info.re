let addZeroStr = dateStr =>
  String.length(dateStr) === 1 ? "0" ++ dateStr : dateStr;

let floatDateToString = floatDate =>
  floatDate |> int_of_float |> string_of_int |> addZeroStr;

let formatedTime = someTime => {
  let year = someTime |> Js.Date.getFullYear |> floatDateToString;
  let month =
    someTime |> Js.Date.getMonth |> (e => e +. 1. |> floatDateToString);
  let day = someTime |> Js.Date.getDate |> floatDateToString;
  let hour = someTime |> Js.Date.getHours |> floatDateToString;
  let min = someTime |> Js.Date.getMinutes |> floatDateToString;
  let sec = someTime |> Js.Date.getSeconds |> floatDateToString;
  year ++ "/" ++ month ++ "/" ++ day ++ " " ++ hour ++ ":" ++ min ++ ":" ++ sec;
};

let timeStr = startAt =>
  switch (startAt) {
  | None => ""
  | Some(time) => formatedTime(time)
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