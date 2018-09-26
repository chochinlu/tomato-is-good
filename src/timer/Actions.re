let component = ReasonReact.statelessComponent("Actions");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <div className="tile">
        <a className="button is-fullwidth is-medium">("Start" |> ReasonReact.string)</a>
      </div>
      <div className="tile">
        <a className="button is-fullwidth is-medium">("Short Break" |> ReasonReact.string)</a>
      </div>
      <div className="tile">
        <a className="button is-fullwidth is-medium">("Long Break" |> ReasonReact.string)</a>
      </div>
      <div className="tile">
        <a className="button is-fullwidth is-medium">("Stop" |> ReasonReact.string)</a>
      </div>
    </div>
};
