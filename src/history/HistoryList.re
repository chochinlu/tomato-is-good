let resultStr = (result: Utils.taskResult) =>
  switch (result) {
  | Finished => "Finished"
  | Terminated => "Terminated"
  };

let resultStyle = (result: Utils.taskResult) => {
  let tagStyle =
    switch (result) {
    | Finished => "is-primary"
    | Terminated => "is-light"
    };
  "m-l tag " ++ tagStyle;
};

let convertTimeStr = ((startAt, endAt)): string => {
  let startAtTime =
    switch (startAt) {
    | None => endAt
    | Some(time) => time
    };

  let duration =
    (Js.Date.getTime(endAt) -. Js.Date.getTime(startAtTime)) /. 1000. +. 1.0;

  duration |> int_of_float |> Timer.convertedTime;
};

let logStyle = title =>
  switch (title) {
  | "ShortBreak"
  | "LongBreak" => "m-t-b smaller lighter"
  | _ => "m-t-b smaller"
  };

let logTitleStyle = title =>
  switch (title) {
  | "ShortBreak"
  | "LongBreak" => "lighter"
  | _ => ""
  };

let logEle = (index: int, log: Utils.log) => {
  let titleStr = "  [ " ++ log.title ++ " ] ";
  let logStr =
    Info.timeStr(log.startAt)
    ++ " ,End at "
    ++ Info.formatedTime(log.endAt)
    ++ ", Duration: "
    ++ ((log.startAt, log.endAt) |> convertTimeStr);

  let tag =
    <span className={resultStyle(log.result)}>
      {log.result |> resultStr |> ReasonReact.string}
    </span>;

  <p className={logStyle(log.title)} key={"logEle-" ++ string_of_int(index)}>
    <strong className={logTitleStyle(log.title)}>
      {titleStr |> ReasonReact.string}
    </strong>
    {logStr |> ReasonReact.string}
    tag
  </p>;
};

let completeCountEle = completeCount =>
  <p>
    {"Complete Count: " |> ReasonReact.string}
    <strong> {completeCount |> string_of_int |> ReasonReact.string} </strong>
  </p>;

let component = ReasonReact.statelessComponent("HistoryList");

let make = (~logs, ~completeCount, _children) => {
  ...component,
  render: _self =>
    <div className="box">
      {completeCount |> completeCountEle}
      {
        List.length(logs) == 0 ?
          ReasonReact.null :
          logs |> List.mapi(logEle) |> Array.of_list |> ReasonReact.array
      }
    </div>,
};