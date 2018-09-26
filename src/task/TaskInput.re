let component = ReasonReact.statelessComponent("TaskInput");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="box">
      <h1>
        ("Input Task" |> ReasonReact.string)
      </h1>
    </div>
};
