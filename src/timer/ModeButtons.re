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
        label="Short Break"
        onClick=setShortBreak
        selected={modeName == "ShortBreak"}
      />
      <ModeButton
        label="Long Break"
        onClick=setLongBreak
        selected={modeName == "LongBreak"}
      />
    </div>,
};