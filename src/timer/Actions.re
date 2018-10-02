module PlayIcon = {
  let component = ReasonReact.statelessComponent("PlayIcon");
  let make = _children => {
    ...component,
    render: _self =>
      <span className="icon"> <i className="fas fa-play" /> </span>,
  };
};

module StopIcon = {
  let component = ReasonReact.statelessComponent("StopIcon");
  let make = _children => {
    ...component,
    render: _self =>
      <span className="icon"> <i className="fas fa-stop" /> </span>,
  };
};

let component = ReasonReact.statelessComponent("Actions");

let make = (~play, ~togglePlay, _children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <a className="button is-fullwidth is-medium" onClick=togglePlay>
        {play ? <StopIcon /> : <PlayIcon />}
        <span> {(play ? "Stop" : "Play") |> ReasonReact.string} </span>
      </a>
    </div>,
};