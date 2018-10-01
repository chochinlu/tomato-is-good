type mode =
  | Pomodoro
  | ShortBreak
  | LongBreak;

type action =
  | Submit(string)
  | Set(mode)
  | Tick;

type state = {
  task: string,
  timeLeft: int,
  mode,
  completeCount: int,
};

let secondsForMode = mode =>
  switch (mode) {
  | Pomodoro => 25 * 60
  | ShortBreak => 5 * 60
  | LongBreak => 10 * 60
  };

let timeIsUp = state => state.timeLeft == 1;

let updateTimeLeft = state =>
  ReasonReact.Update({
    ...state,
    timeLeft: state.timeLeft == 0 ? 0 : state.timeLeft - 1,
  });

let updateMode = state => {
  let completeCount =
    state.mode == Pomodoro ? state.completeCount + 1 : state.completeCount;
  let shouldUpdateToLongBreak = completeCount mod 4 == 0;
  let mode =
    switch (state.mode) {
    | Pomodoro => shouldUpdateToLongBreak ? LongBreak : ShortBreak
    | ShortBreak => Pomodoro
    | LongBreak => LongBreak
    };
  ReasonReact.Update({
    ...state,
    timeLeft: secondsForMode(mode),
    mode,
    completeCount,
  });
};

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    task: "",
    timeLeft: secondsForMode(Pomodoro),
    mode: Pomodoro,
    completeCount: 0,
  },
  reducer: (action, state) =>
    switch (action) {
    | Submit(taskText) => ReasonReact.Update({...state, task: taskText})
    | Set(mode) =>
      ReasonReact.Update({...state, mode, timeLeft: secondsForMode(mode)})
    | Tick => timeIsUp(state) ? updateMode(state) : updateTimeLeft(state)
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