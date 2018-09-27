let component = ReasonReact.statelessComponent("Actions");

let make = (~setStart, ~setShortBreak, ~setLongBreak, ~setStop, _children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <div className="tile">
        <a className="button is-fullwidth is-medium" onClick=setStart>
          ("Start" |> ReasonReact.string)
        </a>
      </div>
      <div className="tile">
        <a className="button is-fullwidth is-medium" onClick=setShortBreak>
          ("Short Break" |> ReasonReact.string)
        </a>
      </div>
      <div className="tile">
        <a className="button is-fullwidth is-medium" onClick=setLongBreak>
          ("Long Break" |> ReasonReact.string)
        </a>
      </div>
      <div className="tile">
        <a className="button is-fullwidth is-medium" onClick=setStop>
          ("Stop" |> ReasonReact.string)
        </a>
      </div>
    </div>,
};