let component = ReasonReact.statelessComponent("Timer");

let make = _children => {
  ...component,
  render: _self =>
    <div className="box">
      <SettingActions />
      <h1
        style={
          ReactDOMRe.Style.make(
            ~color="#444444",
            ~fontSize="7em",
            ~textAlign="center",
            /* ~border="1px solid grey", */
            (),
          )
        }>
        {"00:00" |> ReasonReact.string}
      </h1>
      <Actions />
    </div>,
};