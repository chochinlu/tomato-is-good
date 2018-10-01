let component = ReasonReact.statelessComponent("Actions");

let make = (~play, ~togglePlay, _children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <a className="button is-fullwidth is-medium" onClick=togglePlay>
        <span className="icon"> <i className="fab fa-pagelines" /> </span>
        <span> {(play ? "Stop" : "Play") |> ReasonReact.string} </span>
      </a>
    </div>,
};