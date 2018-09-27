let component = ReasonReact.statelessComponent("Info");

let make = (~task, _children) => {
  let text = task =>
    task == "" ?
      "Let's do something amazing!" : "Task: " ++ task ++ " Let's rock!!";

  {
    ...component,
    render: _self =>
      <div className="notification">
        <i className="fas fa-info-circle" />
        <span style=(ReactDOMRe.Style.make(~paddingLeft="0.5em", ()))>
          (task |> text |> ReasonReact.string)
        </span>
      </div>,
  };
};