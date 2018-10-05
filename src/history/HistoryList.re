let component = ReasonReact.statelessComponent("HistoryList");

let logEle = (log: Utils.log) => {
  let logStr = "  [ " ++ log.title ++ " ] " ++ Info.timeStr(log.startAt);
  <p> {logStr |> ReasonReact.string} </p>;
};

let make = (~logs, _children) => {
  ...component,
  render: _self =>
    <div className="box">
      <h1> {"HistoryList" |> ReasonReact.string} </h1>
      {logs |> List.map(logEle) |> Array.of_list |> ReasonReact.array}
    </div>,
};