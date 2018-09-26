let component = ReasonReact.statelessComponent("HistoryList");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="box">
      <h1>
        ("HistoryList" |> ReasonReact.string)
      </h1>
    </div>
};
