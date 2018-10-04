Utils.requireCSS("./common.css");

type mode =
  | Pomodoro
  | ShortBreak
  | LongBreak;

type action =
  | Submit(string)
  | Set(mode)
  | Tick
  | TogglePlay;

type state = {
  task: option(string),
  timeLeft: int,
  mode,
  completeCount: int,
  play: bool,
};

let modeName = mode =>
  switch (mode) {
  | Pomodoro => "Pomodoro"
  | ShortBreak => "ShortBreak"
  | LongBreak => "LongBreak"
  };

let isPormodoro =
  fun
  | Pomodoro => true
  | ShortBreak
  | LongBreak => false;

let taskName = task =>
  switch (task) {
  | None => "Unnamed Task"
  | Some(name) => name
  };

let title = state =>
  isPormodoro(state.mode) ? taskName(state.task) : modeName(state.mode);

let secondsForMode = mode =>
  switch (mode) {
  | Pomodoro => 25 * 60
  | ShortBreak => 5 * 60
  | LongBreak => 10 * 60
  };

let timeIsUp = state => state.timeLeft == 1;

let updateTimeLeft = state => {
  let timeLeft =
    state.play ? state.timeLeft == 0 ? 0 : state.timeLeft - 1 : state.timeLeft;
  ReasonReact.Update({...state, timeLeft});
};

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
    play: false,
  });
};

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    task: None,
    timeLeft: secondsForMode(Pomodoro),
    mode: Pomodoro,
    completeCount: 0,
    play: false,
  },
  didMount: self => {
    let intervalId = Js.Global.setInterval(() => self.send(Tick), 1000);
    self.onUnmount(() => Js.Global.clearInterval(intervalId));
  },
  reducer: (action, state) =>
    switch (action) {
    | Submit(taskText) =>
      ReasonReact.Update({...state, task: Some(taskText)})
    | Set(mode) =>
      ReasonReact.Update({
        ...state,
        mode,
        timeLeft: secondsForMode(mode),
        play: false,
      })
    | Tick => timeIsUp(state) ? updateMode(state) : updateTimeLeft(state)
    | TogglePlay => ReasonReact.Update({...state, play: !state.play})
    },
  render: ({state, send}) =>
    <div
      className="container is-fluid"
      style={ReactDOMRe.Style.make(~marginTop="1em", ())}>
      <TaskInput handleSubmit={text => send(Submit(text))} />
      <Timer
        timeLeft={state.timeLeft}
        play={state.play}
        modeName={state.mode |> modeName}
        setPomodoro={_event => send(Set(Pomodoro))}
        setShortBreak={_event => send(Set(ShortBreak))}
        setLongBreak={_event => send(Set(LongBreak))}
        togglePlay={_event => send(TogglePlay)}
      />
      <Info title={title(state)} />
      <HistoryList />
      <About />
    </div>,
};