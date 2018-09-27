type state = {taskText: string};
type action =
  | Change(string)
  | KeyDown(int);

let component = ReasonReact.reducerComponent("TaskInput");

let make = (~handleSubmit, _children) => {
  ...component,
  initialState: () => {taskText: ""},
  reducer: (action, state) =>
    switch (action) {
    | Change(text) => ReasonReact.Update({taskText: text})
    | KeyDown(13) =>
      ReasonReact.SideEffects((_self => handleSubmit(state.taskText)))
    | KeyDown(_) => ReasonReact.NoUpdate
    },
  render: ({send}) =>
    <div className="margin-top-down control has-icons-left">
      <input
        className="input is-medium"
        type_="text"
        placeholder="Input Task"
        onChange=(
          event => send(Change(ReactEvent.Form.target(event)##value))
        )
        onKeyDown=(event => send(KeyDown(ReactEvent.Keyboard.which(event))))
      />
      <span className="icon is-small is-left">
        <i className="fas fa-tasks" />
      </span>
    </div>,
};