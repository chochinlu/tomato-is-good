type mode =
  | Pomodoro
  | ShortBreak
  | LongBreak;

type action =
  | Submit(string)
  | Set(mode);

type state = {
  task: string,
  timeLeft: int,
  mode,
};

let secondsForMode = mode =>
  switch (mode) {
  | Pomodoro => 25 * 60
  | ShortBreak => 5 * 60
  | LongBreak => 10 * 60
  };

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    task: "",
    timeLeft: secondsForMode(Pomodoro),
    mode: Pomodoro,
  },
  reducer: (action, state) =>
    switch (action) {
    | Submit(taskText) => ReasonReact.Update({...state, task: taskText})
    | Set(mode) =>
      ReasonReact.Update({...state, mode, timeLeft: secondsForMode(mode)})
    },
  render: ({state, send}) =>
    <div
      className="container is-fluid"
      style={ReactDOMRe.Style.make(~marginTop="1em", ())}>
      <TaskInput handleSubmit={text => send(Submit(text))} />
      <Timer
        timeLeft={state.timeLeft}
        setPomodoro={_event => send(Set(Pomodoro))}
        setShortBreak={_event => send(Set(ShortBreak))}
        setLongBreak={_event => send(Set(LongBreak))}
      />
      <Info task={state.task} />
      <HistoryList />
      <About />
    </div>,
};