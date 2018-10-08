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

let logEle = (log: Utils.log) => {
  let logStr =
    "  [ "
    ++ log.title
    ++ " ] "
    ++ Info.timeStr(log.startAt)
    ++ " ,End At: "
    ++ Js.Date.toTimeString(log.endAt);

  let tag =
    <span className={resultStyle(log.result)}>
      {log.result |> resultStr |> ReasonReact.string}
    </span>;

  <p className="m-t-b"> {logStr |> ReasonReact.string} tag </p>;
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
          logs |> List.map(logEle) |> Array.of_list |> ReasonReact.array
      }
    </div>,
};