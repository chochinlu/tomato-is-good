let resultStr = (result: Utils.taskResult) =>
  switch (result) {
  | Finished => "Finished"
  | Terminated => "Terminated"
  };

let resultStyle = (result: Utils.taskResult) => {
  let tagStyle =
    switch (result) {
    | Finished => "is-primary"
    | Terminated => "is-dark"
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

let logRow = (index: int, log: Utils.log) =>
  <tr key={"logEle-" ++ string_of_int(index)}>
    <td> {log.title |> ReasonReact.string} </td>
    <td> {Info.timeStr(log.startAt) |> ReasonReact.string} </td>
    <td> {Info.formatedTime(log.endAt) |> ReasonReact.string} </td>
    <td>
      {(log.startAt, log.endAt) |> convertTimeStr |> ReasonReact.string}
    </td>
    <td>
      <span className={resultStyle(log.result)}>
        {log.result |> resultStr |> ReasonReact.string}
      </span>
    </td>
  </tr>;

let logTable = logs =>
  <div className="box">
    <table className="table is-striped is-hoverable is-fullwidth">
      <thead>
        <tr>
          {
            [|"Task", "Start At", "End At", "Duration", "Result"|]
            |> Array.mapi((index, e) =>
                 <th key={"logTitle-" ++ string_of_int(index)}>
                   <abbr title=e />
                   {e |> ReasonReact.string}
                 </th>
               )
            |> ReasonReact.array
          }
        </tr>
      </thead>
      <tbody>
        {logs |> List.mapi(logRow) |> Array.of_list |> ReasonReact.array}
      </tbody>
    </table>
  </div>;

let completeCountEle = completeCount =>
  <div className="box">
    <p>
      {"Complete Count: " |> ReasonReact.string}
      <strong> {completeCount |> string_of_int |> ReasonReact.string} </strong>
    </p>
  </div>;

let component = ReasonReact.statelessComponent("HistoryList");

let make = (~logs, ~completeCount, _children) => {
  ...component,
  render: _self =>
    <>
      {completeCount |> completeCountEle}
      {List.length(logs) == 0 ? ReasonReact.null : logs |> logTable}
    </>,
};