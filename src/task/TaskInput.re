type state = {taskText: string};
type action =
  | Change(string)
  | KeyDown(int)
  | ClearInput;

let component = ReasonReact.reducerComponent("TaskInput");

let make = (~handleSubmit, _children) => {
  ...component,
  initialState: () => {taskText: ""},
  reducer: (action, state) =>
    switch (action) {
    | Change(text) => ReasonReact.Update({taskText: text})
    | KeyDown(13) =>
      ReasonReact.SideEffects((_self => handleSubmit(state.taskText)))
    | KeyDown(27)
    | ClearInput => ReasonReact.Update({taskText: ""})
    | KeyDown(_) => ReasonReact.NoUpdate
    },
  render: ({state, send}) =>
    <div className="tile margin-top-down">
      <div className="tile control has-icons-left">
        <input
          value={state.taskText}
          className="input is-medium"
          type_="text"
          placeholder="Input Task"
          onChange={
            event => send(Change(ReactEvent.Form.target(event)##value))
          }
          onKeyDown={
            event => send(KeyDown(ReactEvent.Keyboard.which(event)))
          }
        />
        <span className="icon is-small is-left">
          <i className="fas fa-tasks" />
        </span>
      </div>
      <div className="tile is-2">
        <a
          className="button is-medium is-fullwidth"
          disabled={state.taskText == ""}
          onClick={_evt => send(ClearInput)}>
          <span className="icon is-small padding-right-text">
            <i className="fas fa-chevron-left" />
          </span>
          <span> {"Clear" |> ReasonReact.string} </span>
        </a>
      </div>
    </div>,
};