let component = ReasonReact.statelessComponent("Info");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="notification">
      <i className="fas fa-info-circle" />
      <span style=(ReactDOMRe.Style.make(~paddingLeft="0.5em", ()))>
        ("Let's do something amazing!" |> ReasonReact.string)
      </span>
    </div>
};
