let component = ReasonReact.statelessComponent("Actions");

let make = (_children) => {
  ...component,
  render: _self =>
    <a className="button is-medium is-fullwidth">
      <span className="icon">
        <i className="fas fa-play" />
      </span>
      <span>
        ("Start" |> ReasonReact.string)
      </span>
    </a>
};
