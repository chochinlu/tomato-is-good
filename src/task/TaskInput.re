let component = ReasonReact.statelessComponent("TaskInput");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="margin-top-down control has-icons-left">
      <input className="input is-medium" type_="text" placeholder="Input Task" />
      <span className="icon is-small is-left">
        <i className="fas fa-tasks" />
      </span>
    </div>
};
