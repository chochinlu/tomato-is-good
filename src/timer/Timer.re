let formatTime = (time: int) =>
  time < 10 ? "0" ++ string_of_int(time) : string_of_int(time);

let convertedTime = seconds => {
  let minutes = seconds / 60;
  let secondsRemaining = seconds mod 60;
  let minutesRemaining = minutes mod 60;

  formatTime(minutesRemaining) ++ ":" ++ formatTime(secondsRemaining);
};

let timeLevelStyle = modeName => {
  let basic = "timer-label ";
  switch (modeName) {
  | "Pomodoro" => basic ++ "gray"
  | "ShortBreak"
  | "LongBreak" => basic ++ "lighter-gray"
  | _ => basic
  };
};

let component = ReasonReact.statelessComponent("Timer");

let make =
    (
      ~timeLeft,
      ~modeName,
      ~setPomodoro,
      ~setShortBreak,
      ~setLongBreak,
      ~togglePlay,
      ~play,
      _children,
    ) => {
  ...component,
  render: _self =>
    <div className="box">
      <ModeButtons setPomodoro setShortBreak setLongBreak modeName />
      <h1 className={modeName |> timeLevelStyle}>
        {timeLeft |> convertedTime |> ReasonReact.string}
      </h1>
      <Actions play togglePlay />
    </div>,
};