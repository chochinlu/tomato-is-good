let timerText = ((min: int, sec: int)) : string => {
  let secText = sec == 0 ? "00" : sec |> string_of_int;
  string_of_int(min) ++ ":" ++ secText;
};
type state = {
  min: int,
  sec: int,
};

type timer =
  | Work
  | ShortBreak
  | LongBreak;

let startMin = (timer: timer) =>
  switch (timer) {
  | Work => 25
  | ShortBreak => 5
  | LongBreak => 20
  };

type action =
  | Start
  | Stop
  | Set(timer);

let component = ReasonReact.reducerComponent("Timer");

let make = _children => {
  ...component,
  initialState: () => {min: 25, sec: 0},
  reducer: (action, state) =>
    switch (action) {
    | Start => ReasonReact.NoUpdate
    | Stop => ReasonReact.NoUpdate
    | Set(timer) => ReasonReact.Update({...state, min: startMin(timer)})
    },
  render: ({state, send}) =>
    <div className="box">
      <h1
        style=(
          ReactDOMRe.Style.make(
            ~color="#444444",
            ~fontSize="7em",
            ~textAlign="center",
            /* ~border="1px solid grey", */
            (),
          )
        )>
        ((state.min, state.sec) |> timerText |> ReasonReact.string)
      </h1>
      <Actions 
        setWork=(_evt => send(Set(Work))) 
        setShortBreak=(_evt => send(Set(ShortBreak))) 
        setLongBreak=(_evt => send(Set(LongBreak))) />
    </div>,
};