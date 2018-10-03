module PlayIcon = {
  let component = ReasonReact.statelessComponent("PlayIcon");
  let make = _children => {
    ...component,
    render: _self =>
      <span className="icon"> <i className="fas fa-play" /> </span>,
  };
};

module PauseIcon = {
  let component = ReasonReact.statelessComponent("PauseIcon
");
  let make = _children => {
    ...component,
    render: _self =>
      <span className="icon"> <i className="fas fa-pause" /> </span>,
  };
};

let component = ReasonReact.statelessComponent("Actions");

let make = (~play, ~togglePlay, _children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <a className="button is-fullwidth is-medium" onClick=togglePlay>
        {play ? <PauseIcon /> : <PlayIcon />}
        <span> {(play ? "Pause" : "Play") |> ReasonReact.string} </span>
      </a>
    </div>,
};