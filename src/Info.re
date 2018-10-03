let taskName = task => {
  let taskName =
    switch (task) {
    | None => "Unnamed"
    | Some(name) => name
    };
  <span>
    <strong> {"  [ " ++ taskName ++ " ]" |> ReasonReact.string} </strong>
  </span>;
};

let component = ReasonReact.statelessComponent("Info");

let make = (~task=?, _children) => {
  ...component,
  render: _self =>
    <div className="notification">
      <i className="fas fa-info-circle" />
      {task |> taskName}
    </div>,
};