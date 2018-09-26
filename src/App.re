let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="container is-fluid" style=(ReactDOMRe.Style.make(~marginTop="1em", ()))>
      <TaskInput />
      <Info />
      <Timer />
      <HistoryList />
      <About />
    </div>
};
