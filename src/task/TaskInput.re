type state = {
  taskText: string
};
type action = 
  | Change(string);

let component = ReasonReact.reducerComponent("TaskInput");

let make = (_children) => {
  ...component,
  initialState: () => {
    taskText: "",
  },
  reducer: fun
  | Change(text) => (_ => ReasonReact.Update({taskText: text})),
  render: ({state, send}) =>
    <div>
    <div className="margin-top-down control has-icons-left">
      <input className="input is-medium" type_="text" placeholder="Input Task" onChange=(
        event => send(Change(ReactEvent.Form.target(event)##value))
      )/>
      <span className="icon is-small is-left">
        <i className="fas fa-tasks" />
      </span>
    </div>
    <p>(state.taskText |> ReasonReact.string)</p>
    </div>
};
