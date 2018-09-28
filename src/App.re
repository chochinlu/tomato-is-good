type state = {task: string};
type action =
  | Submit(string);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {task: ""},
  reducer:
    fun
    | Submit(taskText) => (_state => ReasonReact.Update({task: taskText})),
  render: ({state, send}) =>
    <div
      className="container is-fluid"
      style=(ReactDOMRe.Style.make(~marginTop="1em", ()))>
      <TaskInput handleSubmit=(text => send(Submit(text))) />
      <Timer />
      <Info task=state.task />
      <HistoryList />
      <About />
    </div>,
};