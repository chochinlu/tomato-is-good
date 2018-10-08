let resultStr = (result: Utils.taskResult) =>
  switch (result) {
  | Finished => " [ Finished ]"
  | Terminated => " [ Terminated ]"
  };

let logEle = (log: Utils.log) => {
  let logStr =
    "  [ "
    ++ log.title
    ++ " ] "
    ++ Info.timeStr(log.startAt)
    ++ " ,End At: "
    ++ Js.Date.toTimeString(log.endAt)
    ++ resultStr(log.result);

  <p> {logStr |> ReasonReact.string} </p>;
};

let component = ReasonReact.statelessComponent("HistoryList");

let make = (~logs, _children) => {
  ...component,
  render: _self =>
    <div className="box">
      <h1> {"HistoryList" |> ReasonReact.string} </h1>
      {logs |> List.map(logEle) |> Array.of_list |> ReasonReact.array}
    </div>,
};