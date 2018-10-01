let component = ReasonReact.statelessComponent("ModeButtons");

let make = (~setPomodoro, ~setShortBreak, ~setLongBreak, _children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <ModeButton label="Pomodoro" onClick=setPomodoro />
      <ModeButton label="ShorBreak" onClick=setShortBreak />
      <ModeButton label="LongBreak" onClick=setLongBreak />
    </div>,
};