let formatTime = (time: int) =>
  time < 10 ? "0" ++ string_of_int(time) : string_of_int(time);

let convertedTime = seconds => {
  let minutes = seconds / 60;
  let secondsRemaining = seconds mod 60;
  let minutesRemaining = minutes mod 60;

  formatTime(minutesRemaining) ++ ":" ++ formatTime(secondsRemaining);
};

let component = ReasonReact.statelessComponent("Timer");

let make =
    (
      ~timeLeft,
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
      <ModeButtons setPomodoro setShortBreak setLongBreak />
      <h1
        style={
          ReactDOMRe.Style.make(
            ~color="#444444",
            ~fontSize="7em",
            ~textAlign="center",
            /* ~border="1px solid grey", */
            (),
          )
        }>
        {timeLeft |> convertedTime |> ReasonReact.string}
      </h1>
      <Actions play togglePlay />
    </div>,
};