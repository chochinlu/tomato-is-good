let timerText = ((min: int, sec: int)) : string => {
  let secText = sec == 0 ? "00" : sec |> string_of_int;
  string_of_int(min) ++ ":" ++ secText;
};

type state = {
  min: int,
  sec: int,
};
type action =
  | Start
  | ShortBreak
  | LongBreak
  | Stop;

let component = ReasonReact.reducerComponent("Timer");

let make = _children => {
  ...component,
  initialState: () => {min: 25, sec: 0},
  reducer: (action, state) =>
    switch (action) {
    | Start
    | Stop => ReasonReact.Update({...state, min: 25})
    | ShortBreak => ReasonReact.Update({...state, min: 5})
    | LongBreak => ReasonReact.Update({...state, min: 20})
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
        setStart=(_evt => send(Start))
        setShortBreak=(_evt => send(ShortBreak))
        setLongBreak=(_evt => send(LongBreak))
        setStop=(_evt => send(Stop))
      />
    </div>,
};