let component = ReasonReact.statelessComponent("ModeButtons");

let make = (~modeName, ~setPomodoro, ~setShortBreak, ~setLongBreak, _children) => {
  ...component,
  render: _self =>
    <div className="tile">
      <ModeButton
        label="Pomodoro"
        onClick=setPomodoro
        selected={modeName == "Pomodoro"}
      />
      <ModeButton
        label="ShortBreak"
        onClick=setShortBreak
        selected={modeName == "ShortBreak"}
      />
      <ModeButton
        label="LongBreak"
        onClick=setLongBreak
        selected={modeName == "LongBreak"}
      />
    </div>,
};