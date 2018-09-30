type mode =
  | Pomodoro
  | ShorBreak
  | LongBreak;

type action =
  | Submit(string);

type state = {
  task: string,
  timeLeft: int,
  mode,
};

let secondsForMode = mode =>
  switch (mode) {
  | Pomodoro => 25 * 60
  | ShorBreak => 5 * 60
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
    },
  render: ({state, send}) =>
    <div
      className="container is-fluid"
      style={ReactDOMRe.Style.make(~marginTop="1em", ())}>
      <TaskInput handleSubmit={text => send(Submit(text))} />
      <Timer timeLeft={state.timeLeft} />
      <Info task={state.task} />
      <HistoryList />
      <About />
    </div>,
};